= PTW
== Organization
PTW 作为 Rocket Core 内的独立模块，接收来自多个 TLB 的请求，通过 TileLink 总线访问内存完成页表遍历，并将结果返回给请求方。

== Internal Structure
PTW 内部包含三级缓存结构和一个状态机。
=== L2TLB
缓存叶子 PTE。
+ 组相联结构，可配置组数（`nL2TLBEntries`）和路数（`nL2TLBWays`）。
+ 替换算法：PLRU（伪 LRU）。
+ 三级流水线：
```text
stage 0 : 读出
stage 1 : 解码（含 ECC 校验）
stage 2 : 命中判断
```
+ 写：使用 `DescribedSRAM`，`l2_refill` 时写入；有全局位 `g` 用于 SFence 的 `rs2` 清除。
+ 命中：`s2_hit` 在 `s_req` 或 `s_wait1` 状态下判断。

=== PTE Cache
缓存非叶子 PTE，加速下一级页表遍历。
+ 组相联结构，`nPTECacheEntries` 项。
+ 替换算法：PLRU。
+ 写入条件：`mem_resp_valid && traverse && can_refill && !hits.orR && !invalidated`。
+ 清除：SFence 时清空。
+ 命中即跳过本次内存请求（`pte_hit` 置位）。

=== Stage-2 PTE Cache
两阶段地址翻译专用，缓存 Stage-2 的非叶子 PTE。
+ 结构与 PTE Cache 类似。
+ 仅在 `do_both_stages && !stage2 && !stage2_final` 时写入。
+ 命中时 `aux_count` 递增，推进 Stage-2 遍历。

== State Machine
PTW 使用 8 状态状态机控制页表遍历流程。

```text
s_ready → s_req → s_wait1 → s_wait2 → s_wait3 → (回到 s_req 或 s_ready)
                                  ↑            ↓
                            s_dummy1      s_fragment_superpage → s_ready
                                  ↓
                            s_dummy2
```



== Process
=== Arbitration
多个 TLB（ITLB、DTLB、RoCC）的请求经过 Arbiter 仲裁，选出一路送入状态机：
```scala
val arb = Module(new Arbiter(Valid(new PTWReq), n))
arb.io.in <> io.requestor.map(_.req)
arb.io.out.ready := (state === s_ready) && !l2_refill_wire
```
`r_req_dest` 记录被选中的 TLB 编号，用于响应路由 `resp_valid(r_req_dest)`。

=== Page Table Walk
层次化页表遍历的核心流程。

==== 根 PTE 构造
+ 普通翻译：`makePTE(satp.ppn, r_pte)`，使用 `satp` 的 PPN 作为根 PTE。
+ Stage-2 翻译：`makeHypervisorRootPTE(hgatp, vpn, r_pte)`，组合 `hgatp.ppn` 和 VPN 切片。

==== 下一级地址计算
```scala
val pte_addr = {
  val vpn_idxs = (0 until pgLevels).map { i =>
    (vpn >> (pgLevels - i - 1) * pgLevelBits)(width - 1, 0)
  }
  val vpn_idx = vpn_idxs(count)
  val raw_pte_addr = ((r_pte.ppn << pgLevelBits) | vpn_idx) << log2Ceil(xLen / 8)
  raw_pte_addr(size.min(raw_pte_addr.getWidth) - 1, 0)
}
```
用当前 `r_pte.ppn` 作页表基址，用 `vpn` 对应级数的切片作偏移，构造下级页表项的物理地址。

==== 两阶段翻译切换 (do_switch)
当 Stage-1 遍历到叶子但需继续 Stage-2：
```scala
when (do_switch) {
  aux_count := Mux(traverse, count + 1.U, count)
  count := r_hgatp_initial_count
  aux_pte := ... // 保存 Stage-1 的 PTE
  stage2 := true.B
}
```
`count` 和 `aux_count` 交换角色，`aux_pte` 保存 Stage-1 结果，`stage2` 标记当前为 Stage-2 遍历。

=== L2TLB Hit
L2TLB 命中处理：
```scala
val s2_hit_vec = (0 until nL2TLBWays).map(way =>
  s2_valid_vec(way) && (r_tag === s2_entry_vec(way).tag))
val s2_hit = s2_valid && s2_hit_vec.orR
```
+ 命中时 `l2_plru.access(r_idx, OHToUInt(s2_hit_vec))` 更新 PLRU。
+ 将命中的 `s2_hit_entry` 转化为 `s2_pte`，直接返回给 TLB：
  ```scala
  r_pte := Mux(l2_hit && !l2_error, l2_pte, ...)
  ```
+ 设置 `resp_valid(r_req_dest)`，回到 `s_ready`。

=== L2TLB Refill
当遍历找到最终叶子 PTE 时触发 `l2_refill`：
```scala
l2_refill := success && count === (pgLevels-1).U && !r_req.need_gpa &&
  (!r_req.vstage1 && !r_req.stage2 ||
   do_both_stages && aux_count === (pgLevels-1).U && pte.isFullPerm())
```
条件：
+ 访问成功（`success`）。
+ 到达叶子级数（`count === pgLevels-1`）。
+ 不要求返回 GPA（`!r_req.need_gpa`）。
+ 单阶段翻译，或两阶段均到达叶子且全权限。

写入 L2TLB：
```scala
val wmask = Mux(r_valid_vec_q.andR, UIntToOH(r_l2_plru_way), PriorityEncoderOH(~r_valid_vec_q))
ram.write(r_idx, VecInit(Seq.fill(nL2TLBWays)(code.encode(entry.asUInt))), wmask.asBools)
```
有空闲选空闲，无空闲用 PLRU 替换。

=== PTE 合并 (merged_pte)
两阶段翻译时合并两阶段 PTE：
```scala
val merged_pte = {
  val superpage_mask = superpage_masks(Mux(stage2_final, max_count, (pgLevels-1).U))
  val stage1_ppns = (0 until pgLevels-1).map(i =>
    Cat(pte.ppn(hi, mid), aux_pte.ppn(mid-1, 0))) :+ pte.ppn
  val stage1_ppn = stage1_ppns(count)
  makePTE(stage1_ppn & superpage_mask, aux_pte)
}
```
将 Stage-2 PTE 的 PPN 替换掉 Stage-1 PTE 中对应级数的 PPN 片段，实现 GVA→GPA→HPA 的合并。

=== SFence 处理
```scala
when (io.dpath.sfence.valid) {
  // L2TLB：rs1 按地址清除，rs2 按全局位清除
  for (way <- 0 until nL2TLBWays) {
    valid(way) := Mux(!hg && sfence.bits.rs1, valid(way) & ~UIntToOH(addr),
                   Mux(!hg && sfence.bits.rs2, valid(way) & g(way), 0.U))
  }
}
```
+ SFence 到来时设置 `invalidated`，阻止本次 walk 写入任何缓存。
+ PTE Cache 在 SFence 时完全清空。


