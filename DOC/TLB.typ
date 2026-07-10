
= TLB
translation-lookaside buffer，VA 到 PA 翻译的缓冲。定义在 `TLB.scala` 的 `class TLB(instruction: Boolean, lgMaxSize: Int, cfg: TLBConfig)(implicit edge: TLEdgeOut, p: Parameters) extends CoreModule()(p)`

== Translation
存在三种翻译模式。

VA就是PA，VA转为PA，GVA转为GPA转为HPA

= Organization
TLB 在 ICache 和 DCache 中分别实例化，但是统一连接到一个 PTW。
== ITLB
位于 `Frontend.scala`，实例化为 `val tlb = Module(new TLB(true, log2Ceil(fetchBytes), TLBConfig(nTLBSets, nTLBWays, outer.icacheParams.nTLBBasePageSectors, outer.icacheParams.nTLBSuperpages)))`
=== Connection
只罗列了输入和全连接，没有输出。
```scala
tlb.io.req.valid := s1_valid && !s2_replay
tlb.io.req.bits.cmd := M_XRD // Frontend only reads
tlb.io.req.bits.vaddr := s1_pc
tlb.io.req.bits.passthrough := false.B
tlb.io.req.bits.size := log2Ceil(coreInstBytes*fetchWidth).U
tlb.io.req.bits.prv := io.ptw.status.prv
tlb.io.req.bits.v := io.ptw.status.v
tlb.io.sfence := io.cpu.sfence
tlb.io.kill := !s2_valid || s2_kill_speculative_tlb_refill
  // PTW
io.ptw <> tlb.io.ptw
ptwPorts += outer.frontend.module.io.ptw
```
== DTLB
位于 `DCache.scala` 或 `NBDcache.scala`，分别实例化为 `val tlb = Module(new TLB(false, log2Ceil(coreDataBytes), TLBConfig(nTLBSets, nTLBWays, cacheParams.nTLBBasePageSectors, cacheParams.nTLBSuperpages)))` 和 `val dtlb = Module(new TLB(false, log2Ceil(coreDataBytes), TLBConfig(nTLBSets, nTLBWays)))`
=== Connection
只罗列了输入和全连接，没有输出。
```scala
tlb.io.req.valid := s1_tlb_req_valid || s1_valid && !io.cpu.s1_kill && s1_cmd_uses_tlb
tlb.io.req.bits := s1_tlb_req
tlb.io.sfence.valid := s1_valid && !io.cpu.s1_kill && s1_sfence
tlb.io.sfence.bits.rs1 := s1_req.size(0)
tlb.io.sfence.bits.rs2 := s1_req.size(1)
tlb.io.sfence.bits.asid := io.cpu.s1_data.data
tlb.io.sfence.bits.addr := s1_req.addr
tlb.io.sfence.bits.hv := s1_req.cmd === M_HFENCEV
tlb.io.sfence.bits.hg := s1_req.cmd === M_HFENCEG
tlb.io.kill := io.cpu.s2_kill || s2_tlb_req_valid && tlb_port.s2_kill
  // PTW
io.ptw <> tlb.io.ptw
val ptwPorts = ListBuffer(outer.dcache.module.io.ptw)
```
== Core
=== Connection
只罗列了 TLB 的输出，将 ITLB 和 DTLB 统一归类命名为对 Core。
```scala
io.req.ready := state === s_ready
  // paddr = ppn + po
io.resp.paddr := Cat(ppn, io.req.bits.vaddr(pgIdxBits-1, 0))
io.resp.miss := do_refill || vsatp_mode_mismatch || tlb_miss || multipleHits

io.resp.gpa_is_pte := vstage1_en && r_gpa_is_pte // 是否为表项
io.resp.gpa := {
    // 非 VS 阶段，返回仅供报错。
  val page = Mux(!vstage1_en, Cat(bad_gpa, vpn), r_gpa >> pgIdxBits)
    // 表项不使用原偏移
  val offset = Mux(io.resp.gpa_is_pte, r_gpa(pgIdxBits-1, 0), io.req.bits.vaddr(pgIdxBits-1, 0))
  Cat(page, offset)
}

io.resp.pf.ld := (bad_va && cmd_read) || (pf_ld_array & hits).orR
io.resp.pf.st := (bad_va && cmd_write_perms) || (pf_st_array & hits).orR
io.resp.pf.inst := bad_va || (pf_inst_array & hits).orR
io.resp.gf.ld := (bad_gpa && cmd_read) || (gf_ld_array & hits).orR
io.resp.gf.st := (bad_gpa && cmd_write_perms) || (gf_st_array & hits).orR
io.resp.gf.inst := bad_gpa || (gf_inst_array & hits).orR
io.resp.ae.ld := (ae_ld_array & hits).orR
io.resp.ae.st := (ae_st_array & hits).orR
io.resp.ae.inst := (~px_array & hits).orR
io.resp.ma.ld := misaligned && cmd_read
io.resp.ma.st := misaligned && cmd_write
io.resp.ma.inst := false.B // this is up to the pipeline to figure out
io.resp.cacheable := (c_array & hits).orR
io.resp.prefetchable := (prefetchable_array & hits).orR && edge.manager.managers.forall(m => !m.supportsAcquireB || m.supportsHint).B
  // miss 后必须分配
io.resp.must_alloc := (must_alloc_array & hits).orR
```
== PTW
ITLB 和 DTLB 最后统一连接到一个 PTW 上。
=== Connection
```scala
ptw.io.requestor <> ptwPorts.toSeq

io.ptw.req.valid := state === s_request
io.ptw.req.bits.valid := !io.kill
io.ptw.req.bits.bits.addr := r_refill_tag
io.ptw.req.bits.bits.vstage1 := r_vstage1_en
io.ptw.req.bits.bits.stage2 := r_stage2_en
io.ptw.req.bits.bits.need_gpa := r_need_gpa
```

= Process
== Hit
判断命中，三路并行。
```scala
val sector_hits = sectored_entries(memIdx).map(_.sectorHit(vpn, priv_v))
val superpage_hits = superpage_entries.map(_.hit(vpn, priv_v))
val hitsVec = all_entries.map(vm_enabled && _.hit(vpn, priv_v))
val real_hits = hitsVec.asUInt
val hits = Cat(!vm_enabled, real_hits)

val gpa_hits = {
  val need_gpa_mask = if (instruction) gf_inst_array else gf_ld_array | gf_st_array
  val hit_mask = Fill(ordinary_entries.size, r_gpa_valid && r_gpa_vpn === vpn) | Fill(all_entries.size, !vstage1_en)
  hit_mask | ~need_gpa_mask(all_entries.size-1, 0)
}

val tlb_hit_if_not_gpa_miss = real_hits.orR
val tlb_hit = (real_hits & gpa_hits).orR
```

获取数据
```scala
val ppn = Mux1H(hitsVec :+ !vm_enabled, (all_entries zip entries).map{ case (entry, data) => entry.ppn(vpn, data) } :+ vpn(ppnBits-1, 0))

val entries = all_entries.map(_.getData(vpn)) // 全部
val normal_entries = entries.take(ordinary_entries.size) // 无特殊
```

Def：
- sectorHit
返回是否 sector hit。
- sectorTagMatch
返回是否 tag 匹配
- hit
超页是否命中。
- getData
获取数据。
- ppn
PPN 拼接。超页的PPN + 页的VPN
== Miss
- do_refill
重填过程中不能确保正确。
=== TLB Miss
TLB 因为缺页表项而造成的脱靶。
```scala
  // VM 开启，模式匹配，不是非法地址，TLB 未命中。
val tlb_miss = vm_enabled && !vsatp_mode_mismatch && !bad_va && !tlb_hit
```

处理过程：
+ 保存上下文。
  ```scala
    r_refill_tag := vpn
    r_vstage1_en := vstage1_en
    r_stage2_en := stage2_en
    r_sectored_hit.valid := sector_hits.orR
    r_sectored_hit.bits := OHToUInt(sector_hits)
    r_superpage_hit.valid := superpage_hits.orR
    r_superpage_hit.bits := OHToUInt(superpage_hits)
  ```
+ 判断类型，GPA 脱靶？`r_need_gpa := tlb_hit_if_not_gpa_miss`
+ 选择替换。
  ```scala
    r_superpage_repl_addr := replacementEntry(superpage_entries, superpage_plru.way)
    r_sectored_repl_addr := replacementEntry(sectored_entries(memIdx), sectored_plru.way(memIdx))
  ```

- replacementEntry
victim 选择函数。有空闲选空闲，无空闲用算法。
=== multipleHits
```scala
val multipleHits = PopCountAtLeast(real_hits, 2)
```
需要清空 `all_real_entries`。
Eg：超页时可能同时匹配。重填出现问题。ASID 处理出错。
=== vsatp_mode_mismatch
翻译模式不匹配，即协议不同。
```scala
  // guest 环境下，VS 阶段不同，不直通
val vsatp_mode_mismatch  = priv_v && (vstage1_en =/= v_entries_use_stage1) && !io.req.bits.passthrough
```
需要清空 `all_real_entries`，置位 `v_entries_use_stage1 := vstage1_en`。
== Refill
```scala
val do_refill = usingVM.B && io.ptw.resp.valid
  // 是否虚拟化
val refill_v = r_vstage1_en || r_stage2_en
```

构建页表项：
```scala
val pte = io.ptw.resp.bits.pte
val newEntry = Wire(new TLBEntryData) // 一堆赋值省略了
```

在 `special_entry.nonEmpty.B && !io.ptw.resp.bits.homogeneous`，写入 `special_entry`。在 `io.ptw.resp.bits.level < (pgLevels-1).U`，写入 `superpage_entries`。最后，写入 `sectored_entries`。

更新 GPA：
```scala
r_gpa_valid := io.ptw.resp.bits.gpa.valid
r_gpa := io.ptw.resp.bits.gpa.bits
r_gpa_is_pte := io.ptw.resp.bits.gpa_is_pte
```
== Replacement
更新 victim 策略。
```scala
  // per-set LRU 按组
val sectored_plru = new SetAssocLRU(cfg.nSets, sectored_entries.head.size, "plru")
  // tree PLRU 全局
val superpage_plru = new PseudoLRU(superpage_entries.size)
```

在 `io.req.valid && vm_enabled`，命中后更新。
```scala
sectored_plru.access(memIdx, OHToUInt(sector_hits))
superpage_plru.access(OHToUInt(superpage_hits))
```
== Sfence
刷新 tlb，采用 invalidate 的一系列函数。
```scala
  // 用于 VM
val sfence = io.sfence.valid
  // 用于 refill
val invalidate_refill = state.isOneOf(s_request /* don't care */, s_wait_invalidate) || io.sfence.valid
```
== PMA
physical memory attributes
```scala
  // 检查地址是否有设备
val legal_address = edge.manager.findSafe(mpu_physaddr).reduce(_||_)

val cacheable = fastCheck(_.supportsAcquireB) && (instruction || !usingDataScratchpad).B
val prot_r = fastCheck(_.supportsGet) && !deny_access_to_debug && pmp.io.r
val prot_w = fastCheck(_.supportsPutFull) && !deny_access_to_debug && pmp.io.w
val prot_pp = fastCheck(_.supportsPutPartial) // 部分写
val prot_al = fastCheck(_.supportsLogical) // AMO逻辑
val prot_aa = fastCheck(_.supportsArithmetic) // AMO算术
val prot_x = fastCheck(_.executable) && !deny_access_to_debug && pmp.io.x
val prot_eff = fastCheck(Seq(RegionType.PUT_EFFECTS, RegionType.GET_EFFECTS) contains _.regionType) // 有副作用
  // 判断业内属性是否都一致
val homogeneous = TLBPageLookup(edge.manager.managers, xLen, p(CacheBlockBytes), BigInt(1) << pgIdxBits)(mpu_physaddr).homogeneous
  // 禁止访问的保护机制
val deny_access_to_debug = mpu_priv <= PRV.M.U && p(DebugModuleKey).map(dmp => dmp.address.contains(mpu_physaddr)).getOrElse(false.B)
```
- fastCheck
快捷查询。
== PTW
TLB 与 PTW 的交互。

在 `io.ptw.req.fire && io.ptw.req.bits.valid`，即请求成功后，对 GPA 进行操作。
```scala
r_gpa_valid := false.B
r_gpa_vpn := r_refill_tag
```

= FSM
TLB 内部的状态机。
```scala
val s_ready :: s_request :: s_wait :: s_wait_invalidate :: Nil = Enum(4)
```
状态图
```
stateDiagram-v2
  [*] --> s_ready
  s_ready --> s_request : io.req.fire && tlb_miss
  s_request --> s_wait : PTW.req.ready && !sfence && !kill
  s_request --> s_wait_invalidate : PTW.req.ready && sfence
  s_request --> s_ready : sfence || io.kill
  s_wait --> s_wait_invalidate : sfence
  s_wait_invalidate --> s_ready : PTW.resp.valid
  s_wait --> s_ready : PTW.resp.valid
```
== s_ready
就绪状态。

在此状态，`io.req.ready = true.B`，等待 CPU 的请求。命中后当周期输出。
== s_request
请求状态。

在此状态，`io.ptw.req.valid = true.B`，向 PTW 发送请求。同时对 TLB miss 进行处理，见上。
== s_wait
等待状态。
== s_wait_invalidate
等待不接收状态。

= IO
TLB 的输入输出
```scala
  // 地址翻译请求
val req = Flipped(Decoupled(new TLBReq(lgMaxSize)))
  // 翻译结果
val resp = Output(new TLBResp())
  // SFENCE.VMA，即 Supervisor Fence，用于刷新 TLB 以同步页表。
val sfence = Flipped(Valid(new SFenceReq))
  // 取消 speculative TLB refill，仅用于 ptw
val kill = Input(Bool())

  // 与 PTW 的连接
val ptw = new TLBPTWIO
```
== Core
=== TLBReq
```scla
val vaddr = UInt(vaddrBitsExtended.W)
  // 物理地址直通
val passthrough = Bool()
  // 访问大小
val size = UInt(log2Ceil(lgMaxSize + 1).W)

val cmd = Bits(M_SZ.W)
val prv = UInt(PRV.SZ.W)
val v = Bool()
```
=== TLBResp
```scala
val paddr = UInt(paddrBits.W)
val miss = Bool()

val gpa = UInt(vaddrBitsExtended.W)
val gpa_is_pte = Bool()

  // Exception
val pf = new TLBExceptions
val gf = new TLBExceptions
val ae = new TLBExceptions
val ma = new TLBExceptions

  // Others
val cacheable = Bool()
val must_alloc = Bool()
val prefetchable = Bool()
```
==== TLBExceptions
```scala
val ld = Bool()
val st = Bool()
val inst = Bool()
val v = Bool()
```
=== SFenceReq
```scala
  // 刷新 00 所有，01 某个asid，10 某个addr(VPN)，11
val rs1 = Bool()
val rs2 = Bool()

val addr = UInt(vaddrBits.W)
val asid = UInt((asIdBits max 1).W)

  // 10 hfence.vvma 刷新 VS 阶段，11 hfence.gvma 刷新 G 阶段
val hv = Bool()
val hg = Bool()
```

= Hardware
TLB 的内部情况。
== Entry
- ordinary_entries
可能命中的普通项
- all_entries
可能参与的项
- all_real_entries
所有项
=== Sectored Entries
`nSets` 个 set，`nWays/nSectors` 个 entry，`nSectors` 个 sector。不支持超页，不只能超页。
```scala
val sectored_entries = Reg(Vec(cfg.nSets, Vec(cfg.nWays / cfg.nSectors, new TLBEntry(cfg.nSectors, false, false))))
```
=== Superpage Entries
全相联（不分 set），`nSuperpageEntries` 个 entry，1 个 sector。支持超页，只能超页。
用于缓存大页。
```scala
val superpage_entries = Reg(Vec(cfg.nSuperpageEntries, new TLBEntry(1, true, true)))
```
=== Special Entry
支持超页，不只能超页。
```scala
  // 只有 PMP 粒度小于页大小才存在
val pageGranularityPMPs = pmpGranularity >= (1 << pgIdxBits)
val special_entry = (!pageGranularityPMPs).option(Reg(new TLBEntry(1, true, false)))
```
=== TLBEntry
```scala
  // 页表层级
val level = UInt(log2Ceil(pgLevels).W)
  // 将 VPN 作为 tag
val tag_vpn = UInt(vpnBits.W)
  // 虚拟化 tag
val tag_v = Bool()
  // sector 有效位
val valid = Vec(nSectors, Bool())

val data = Vec(nSectors, UInt(new TLBEntryData().getWidth.W))
```
- entry_data
获取项所有数据。
- insert
填入数据。
- invalidate/invalidateVPN/invalidateNonGlobal
清理 sector
=== TLBEntryData
即 PTE
```scala
val ppn = UInt(ppnBits.W)

  // 用户模式可访问和全局
val u = Bool()
val g = Bool()

  // Access Exception from PTW，Final Access Exception
val ae_ptw = Bool()
val ae_final = Bool()
val pf = Bool()
val gf = Bool()

  // Supervisor&Hypervisor
val sw = Bool()
val sx = Bool()
val sr = Bool()

val hw = Bool()
val hx = Bool()
val hr = Bool()

  // Protect
val pw = Bool()
val px = Bool()
val pr = Bool()

  // AMO
val pal = Bool() // logic
val paa = Bool() // arithmetic

val ppp = Bool() // PutPartial
val eff = Bool() // get/put effects
val c = Bool() // cacheable
val fragmented_superpage = Bool() // fragmented_superpage support
```
== PMP
physical memory protection
```scala
val pmp = Module(new PMPChecker(lgMaxSize))
```
```scala
  // 待检查的 ppn
val mpu_ppn = Mux(do_refill, refill_ppn,
                Mux(vm_enabled && special_entry.nonEmpty.B,
                  special_entry.map(e => e.ppn(vpn, e.getData(vpn))).getOrElse(0.U), io.req.bits.vaddr >> pgIdxBits))
val mpu_physaddr = Cat(mpu_ppn, io.req.bits.vaddr(pgIdxBits-1, 0))
val mpu_priv = Mux[UInt](usingVM.B && (do_refill || io.req.bits.passthrough),
                  PRV.S.U, Cat(io.ptw.status.debug, priv)) // 特权级

pmp.io.addr := mpu_physaddr
pmp.io.size := io.req.bits.size
pmp.io.pmp := (io.ptw.pmp: Seq[PMP])
pmp.io.prv := mpu_priv

val refill_ppn = io.ptw.resp.bits.pte.ppn(ppnBits-1, 0)
```
== Reg
```scala
  // 状态机
val state = RegInit(s_ready)
```
=== Hit&Miss
```scala
val r_sectored_hit = Reg(Valid(UInt(log2Ceil(sectored_entries.head.size).W)))
val r_superpage_hit = Reg(Valid(UInt(log2Ceil(superpage_entries.size).W)))

val r_vstage1_en = Reg(Bool())
val r_stage2_en = Reg(Bool())

val r_need_gpa = Reg(Bool())
```
=== Refill
```scala
val r_refill_tag = Reg(UInt(vpnBits.W))
val r_superpage_repl_addr = Reg(UInt(log2Ceil(superpage_entries.size).W))
val r_sectored_repl_addr = Reg(UInt(log2Ceil(sectored_entries.head.size).W))

val r_gpa_valid = Reg(Bool())
val r_gpa = Reg(UInt(vaddrBits.W))
val r_gpa_vpn = Reg(UInt(vpnBits.W))
val r_gpa_is_pte = Reg(Bool())
```

= Signals
== Address
[ Tag\* | memIdx | sectorIdx | page offset ]
[ vpnBits                    | pgIdxBits   ]
[ ppnBits                    | pgIdxBits   ]
```scala
val vpn = io.req.bits.vaddr(vaddrBits-1, pgIdxBits)
  // memIdx 用于 sectored_entries 选择 set
val memIdx = vpn.extract(cfg.nSectors.log2 + cfg.nSets.log2 - 1, cfg.nSectors.log2)
  // sectorIdx 用于 sectored_entries 选择 sector
private def sectorIdx(vpn: UInt) = vpn.extract(nSectors.log2-1, 0)

val bad_gpa = if (!usingHypervisor) false.B
              else vm_enabled && !stage1_en && badVA(true)
val bad_va = if (!usingVM || (minPgLevels == pgLevels 
                                && vaddrBits == vaddrBitsExtended)) false.B
              else vm_enabled && stage1_en && badVA(false)
```
- badVA
虚拟地址合法性检查
== Privilege
```scala
  // 请求者的权限
val priv = io.req.bits.prv
  // 是否在 guest 环境
val priv_v = usingHypervisor.B && io.req.bits.v
  // 是不是 S、M
val priv_s = priv(0)
  // 是不是 U、S
val priv_uses_vm = priv <= PRV.S.U
```
== Stage
```scala
  // stap 和 vstap 寄存器
val satp = Mux(priv_v, io.ptw.vsatp, io.ptw.ptbr)
  // 是否启用分页
val stage1_en = usingVM.B && satp.mode(satp.mode.getWidth-1)
  // 是否启用 guest
val vstage1_en = usingHypervisor.B && priv_v && io.ptw.vsatp.mode(io.ptw.vsatp.mode.getWidth-1) // GVA到GPA
val v_entries_use_stage1 = RegInit(false.B) // 模式是否匹配
val stage2_en  = usingHypervisor.B && priv_v && io.ptw.hgatp.mode(io.ptw.hgatp.mode.getWidth-1) // GPA到HPA
  // 是否使用 VM，即用 TLB
val vm_enabled = (stage1_en || stage2_en) && priv_uses_vm && !io.req.bits.passthrough
```
== Array
```scala
  // 允许 S 访问 U
val sum = Mux(priv_v, io.ptw.gstatus.sum, io.ptw.status.sum)
  // 允许特权级操作 U
val priv_rw_ok = Mux(!priv_s || sum, entries.map(_.u).asUInt, 0.U) 
                | Mux(priv_s, ~entries.map(_.u).asUInt, 0.U)
val priv_x_ok = Mux(priv_s, ~entries.map(_.u).asUInt, entries.map(_.u).asUInt)
  // 允许 x 连带 r
val mxr = io.ptw.status.mxr | Mux(priv_v, io.ptw.gstatus.mxr, false.B)

  // 无需翻译的数量
val nPhysicalEntries = 1 + special_entry.size
```
=== Exception
```scala
val ptw_ae_array = Cat(false.B, entries.map(_.ae_ptw).asUInt)
val final_ae_array = Cat(false.B, entries.map(_.ae_final).asUInt)
val ptw_pf_array = Cat(false.B, entries.map(_.pf).asUInt)
val ptw_gf_array = Cat(false.B, entries.map(_.gf).asUInt)
```
=== AE
```scala
val ae_array =
    Mux(misaligned, eff_array, 0.U) |
    Mux(cmd_lrsc, ~lrscAllowed, 0.U)

val ae_ld_array = Mux(cmd_read, ae_array | ~pr_array, 0.U)
val ae_st_array =
  Mux(cmd_write_perms, ae_array | ~pw_array, 0.U) |
  Mux(cmd_put_partial, ~ppp_array_if_cached, 0.U) |
  Mux(cmd_amo_logical, ~pal_array_if_cached, 0.U) |
  Mux(cmd_amo_arithmetic, ~paa_array_if_cached, 0.U)
val must_alloc_array =
  Mux(cmd_put_partial, ~ppp_array, 0.U) |
  Mux(cmd_amo_logical, ~paa_array, 0.U) |
  Mux(cmd_amo_arithmetic, ~pal_array, 0.U) |
  Mux(cmd_lrsc, ~0.U(pal_array.getWidth.W), 0.U)

  // 未对齐。LR/SC 操作
val misaligned = (io.req.bits.vaddr & (UIntToOH(io.req.bits.size) - 1.U)).orR
val lrscAllowed = Mux((usingDataScratchpad || usingAtomicsOnlyForIO).B, 0.U, c_array)
  // 缓存可支持这三个操作
val ppp_array_if_cached = ppp_array | c_array
val paa_array_if_cached = paa_array | (if(usingAtomicsInCache) c_array else 0.U)
val pal_array_if_cached = pal_array | (if(usingAtomicsInCache) c_array else 0.U)
```
=== PF&GF
```scala
val pf_ld_array = Mux(cmd_read, ((~Mux(cmd_readx, x_array, r_array) & ~ptw_ae_array) | ptw_pf_array) & ~ptw_gf_array, 0.U)
val pf_st_array = Mux(cmd_write_perms, ((~w_array & ~ptw_ae_array) | ptw_pf_array) & ~ptw_gf_array, 0.U)
val pf_inst_array = ((~x_array & ~ptw_ae_array) | ptw_pf_array) & ~ptw_gf_array
val gf_ld_array = Mux(priv_v && cmd_read, ~Mux(cmd_readx, hx_array, hr_array) & ~ptw_ae_array, 0.U)
val gf_st_array = Mux(priv_v && cmd_write_perms, ~hw_array & ~ptw_ae_array, 0.U)
val gf_inst_array = Mux(priv_v, ~hx_array & ~ptw_ae_array, 0.U)
```
=== RWX
```scala
val r_array = Cat(true.B, (priv_rw_ok & (entries.map(_.sr).asUInt | Mux(mxr, entries.map(_.sx).asUInt, 0.U))) | stage1_bypass)
val w_array = Cat(true.B, (priv_rw_ok & entries.map(_.sw).asUInt) | stage1_bypass)
val x_array = Cat(true.B, (priv_x_ok & entries.map(_.sx).asUInt) | stage1_bypass)
  // 跳过 VS 阶段
val stage1_bypass = Fill(entries.size, usingHypervisor.B && !stage1_en)
```
=== HRWX
```scala
val hr_array = Cat(true.B, entries.map(_.hr).asUInt | Mux(io.ptw.status.mxr, entries.map(_.hx).asUInt, 0.U) | stage2_bypass)
val hw_array = Cat(true.B, entries.map(_.hw).asUInt | stage2_bypass)
val hx_array = Cat(true.B, entries.map(_.hx).asUInt | stage2_bypass)
  // 跳过 G 阶段
val stage2_bypass = Fill(entries.size, !stage2_en)
```
=== Protect
```scala
val pr_array = Cat(Fill(nPhysicalEntries, prot_r), normal_entries.map(_.pr).asUInt) & ~(ptw_ae_array | final_ae_array)
val pw_array = Cat(Fill(nPhysicalEntries, prot_w), normal_entries.map(_.pw).asUInt) & ~(ptw_ae_array | final_ae_array)
val px_array = Cat(Fill(nPhysicalEntries, prot_x), normal_entries.map(_.px).asUInt) & ~(ptw_ae_array | final_ae_array)
```
=== AMO
```scala
val paa_array = Cat(Fill(nPhysicalEntries, prot_aa), normal_entries.map(_.paa).asUInt)
val pal_array = Cat(Fill(nPhysicalEntries, prot_al), normal_entries.map(_.pal).asUInt)
```
=== Other 
```scala
val eff_array = Cat(Fill(nPhysicalEntries, prot_eff), normal_entries.map(_.eff).asUInt)
val c_array = Cat(Fill(nPhysicalEntries, cacheable), normal_entries.map(_.c).asUInt)
val ppp_array = Cat(Fill(nPhysicalEntries, prot_pp), normal_entries.map(_.ppp).asUInt)
val prefetchable_array = Cat((cacheable && homogeneous) << (nPhysicalEntries-1), normal_entries.map(_.c).asUInt)
```
== CMD
```scala
val cmd_lrsc = usingAtomics.B && io.req.bits.cmd.isOneOf(M_XLR, M_XSC)
val cmd_amo_logical = usingAtomics.B && isAMOLogical(io.req.bits.cmd)
val cmd_amo_arithmetic = usingAtomics.B && isAMOArithmetic(io.req.bits.cmd)
val cmd_put_partial = io.req.bits.cmd === M_PWR
val cmd_read = isRead(io.req.bits.cmd)
val cmd_readx = usingHypervisor.B && io.req.bits.cmd === M_HLVX
val cmd_write = isWrite(io.req.bits.cmd)
val cmd_write_perms = cmd_write || io.req.bits.cmd.isOneOf(M_FLUSH_ALL, M_WOK)
```

= Parameter
- `usingVM`
是否使用虚拟内存
== TLB config
- `nSets`
组数，遵循 ICacheParams.nSets
- `nWays`
路数，遵循 ICacheParams.nWays
- `nSectors`
块数，默认 4
- `nSuperpageEntries`
超页项数，默认 4

= Terminology
VA/vaddr：物理地址。virtual address
PA/paddr：物理地址。physical address
gva：guest virtual address
gpa：guest physical address
hpa：host physical address

vpn：virtual page number
ppn：physical page number

pf：page fault
gpf：guest page fault
ae：physical access exception
ma：misaligned

c/cacheable 可缓存
prefetchable 在预取
must_alloc 必需分配

VM stage：gva到gpa
G stage：gpa到hpa

v/virtualization mode 是否使用虚拟机
