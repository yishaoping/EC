# 开屏障后架构 Store 少近二十倍：根因

## 结论

`.typ` 中的开屏障结果（905862 cycles、3713 stores、32 packages）与未开屏障结果（1012405 cycles、60570 stores、279 packages）显示的是 **统计资格被屏障状态切断**，不是 BOOM 执行少了同样数量的 store，也没有证据表明 LDQ/STQ 溢出。

最直接的根因是：LSU 将“是否计入架构访存统计”同时绑定到性能窗口和 R_IC 的 `fsm_check` 状态：

```scala
// boom/src/main/scala/lsu/lsu.scala:1816-1819
arch_store_in_scope = arch_store && stq(idx).valid &&
  io.dmem.traffic_counting && io.dmem.traffic_check_state
arch_load_in_scope = arch_load && ldq(idx).valid &&
  io.dmem.traffic_counting && io.dmem.traffic_check_state
```

而 `traffic_check_state` 在 tile 中定义为：

```scala
// boom/src/main/scala/common/tile.scala:648
outer.dcache.module.io.traffic_check_state :=
  core.io.debug_maincore_status === 2.U
```

`debug_maincore_status==2` 只表示 R_IC 当前处于 `fsm_check`：

```scala
// rocket-chip/src/main/scala/r/R_IC.scala:440-442
debug_maincore_status := ... fsm_state === fsm_check ? 2.U : ...
```

开启真实屏障后，L2 请求 BOOM 关闭当前 package。R_IC 在 `fsm_check` 中遇到 `barrierCloseRequest` 会转入 `fsm_postcheck`：

```scala
// R_IC.scala:331,341
ctrl := Mux(io.ic_exit_isax || barrierCloseRequest, 3.U, ...)
fsm_state := Mux(io.ic_exit_isax || barrierCloseRequest || ..., fsm_postcheck, fsm_check)
```

因此屏障期间存在以下实际路径：

```text
L2 unsafe dirty candidate
  -> barrier request
  -> barrierCloseRequest
  -> R_IC fsm_check -> fsm_postcheck/cooling
  -> debug_maincore_status != 2
  -> traffic_check_state = 0
  -> LSU 仍收到 ROB commit，但 arch_store_in_scope/load_in_scope = 0
  -> 架构 store/load 统计漏计
```

`boom_inst` 使用独立的 CSR 指令计数器，不经过 `traffic_check_state`，所以仍为 649956；这正好解释了“指令数相同，但架构 store/load 少近二十倍”。`boom_arch` 与 `boom_strict` 都使用同一个错误资格门控，因此二者仍然相等，现有一致性检查不会发现漏计。

## 为什么不是 LSU 溢出

- BOOM 指令数相同：649956。
- benchmark 结果相同：512 nodes、8192 edges、checksum 43439728。
- 两次报告均 `status=PASS`，没有 LSU queue overwrite、LDQ/STQ assertion 或 strict pending underflow 报告。
- LSU 对 LDQ/STQ 满的处理是向 rename/dispatch 返回 `ldq_full/stq_full`，阻止新 uop 分派；它不会静默减少已经架构提交的 store。
- 当前生成 RTL 中能看到标准的 `!ldq.valid` / `!stq.valid` 覆写断言，当前日志没有这些断言失败。

所以“少很多”发生在 **统计事件生成条件**，不是 LSU 物理队列丢失。

## 修复原则

性能统计窗口应由 `traffic_counting`（RESET/START/STOP）决定，不能由 R_IC 的瞬时状态决定。建议：

1. 在 LDQ/STQ 分配或第一次真实请求时锁存 `traffic_counting` 作为该内存操作的窗口资格。
2. 普通架构 load/store 在 ROB commit 时使用已锁存的窗口资格；不要再要求当拍 `traffic_check_state==1`。
3. LR/SC/AMO 和包 attribution 仍保留各自的完成点/packet sequence 约束。
4. STOP 后新请求不应进入窗口；STOP 前已锁存的请求允许完成并纳入严格统计。
5. `traffic_check_state` 可以继续作为 checker/package attribution 的控制信号，但不能作为 BOOM 架构访存总量的过滤器。

最小改动方向是把普通访存的统计资格从：

```scala
traffic_counting && traffic_check_state
```

改为在请求/分配时锁存的 `traffic_counting`，并在 commit 使用该锁存位。只直接删除 commit 处的 `traffic_check_state` 不够，因为当前 STQ/LDQ 的 `traffic_check` 在更早阶段也使用同一门控。

## 包数差异的额外根因

屏障新增路径在 `R_IC.scala` 中原来执行：

```scala
ctrl := Mux(io.ic_exit_isax || barrierCloseRequest, 3.U, ...)
```

但 `ctrl=3` 是整个检查会话退出码。`fsm_trans` 对该值进入 `fsm_reset`，同时
`package_allocated = snapshot_accepted && !ctrl(0)` 使该边界不产生新的
`packet_alloc_valid`。因此屏障会关闭当前包，却跳过后续正常包分配，造成开屏障
结果只有 32 个包。现在屏障分支改为 `ctrl=0`，保留真实 `ic_exit_isax` 的
`ctrl=3` 语义，使状态机继续经过调度和快照分配新包。

## 版本边界

`GH_GlobalParams.scala` 在当前工作区是 `false`，当前生成的 `InclusiveCache.sv` 也已将 `barrierRequest` 折叠为常量 0，说明现有 VCD/test.log 是未开屏障版本。`.typ` 第一段来自前一份 `true` 生成版本；两段日志均来自同一提交后的软件测试，但当前未保留开屏障 VCD，因此无法直接统计开屏障时 LDQ/STQ 满信号。不过源代码资格链已经足以解释统计差异。

本分析未重新仿真，也未重新生成 RTL。
