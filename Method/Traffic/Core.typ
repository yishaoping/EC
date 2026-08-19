#set document(
  title: "BOOM BoomCore 的 io 输出信号清单与去向分类",
  author: "GuardianCouncil 工作记录",
)
#set page(
  paper: "a4",
  margin: (x: 18mm, y: 17mm),
  numbering: "1 / 1",
)
#set text(lang: "zh", size: 10.5pt)
#set par(justify: true, leading: 0.72em)
#set heading(numbering: none)
#show heading.where(level: 1): it => block(
  above: 1.2em,
  below: 0.65em,
  stroke: (bottom: 0.7pt + rgb("#455a64")),
  inset: (bottom: 0.25em),
)[#it]
#show heading.where(level: 2): it => block(above: 1em, below: 0.45em)[#it]
#show raw.where(block: true): it => block(
  fill: rgb("#f4f6f7"),
  stroke: 0.5pt + rgb("#c7cdd1"),
  inset: 8pt,
  radius: 3pt,
  width: 100%,
)[#it]

#align(center)[
  #text(size: 19pt, weight: "bold")[BOOM `BoomCore` 的 `io` 输出信号清单与去向分类]
  #v(0.5em)
  #text(size: 10.5pt, fill: rgb("#455a64"))[按输出信号的“去向”整理：SoC 跟踪 / DCache / RoCC / GH_BUF / GHM / Frontend / PTW / LSU]
]

#v(0.8em)

本文整理 BOOM 大核顶层 `BoomCore` 的 `io` 中 *所有输出信号*，逐一注明其在源码中的位置，并按“去向（接到哪里）”进行分类。所有行号均以当前仓库 `chipyard/generators/boom/src/main/scala` 为准。

= 第一章：`io` 定义位置与整体结构

`BoomCore.io` 定义在 `exu/core.scala:58-140`。`io` 的类型是抽象类 `freechips.rocketchip.tile.CoreBundle`（`rocket-chip/src/main/scala/tile/Core.scala:147`，该抽象类本身 *没有任何字段*，只混入 `ParameterizedBundle` 与 `HasCoreParameters`），因此 `BoomCore` 的 `io` 里出现的信号全部都是下面这段代码 *就地声明* 的。




= GH_BUF
`GH_BUF` 接收 BOOM 大核的提交 uop、物理寄存器读出值、JALR 目标与 IC 当前目标核，用于构造发往小核的 GHT packet：

val commit_valids = Output(Vec(coreWidth, UInt(1.W)))
val commit_uops   = Output(Vec(coreWidth, new MicroOp))

val prf_rd = Output(Vec(coreWidth, UInt(xLen.W)))
val jalr_target   = Output(Vec(coreWidth, UInt(xLen.W)))

val ic_crnt_target = Output(UInt(6.W))

```scala
gh_buf.io.commit_valids(w) := RegNext(core.io.commit_valids(w))
gh_buf.io.commit_uops(w)   := RegNext(core.io.commit_uops(w))

gh_buf.io.gh_prfs_rd(w)    := RegNext(core.io.prf_rd(w))
gh_buf.io.jalr_target(w)   := RegNext(core.io.jalr_target(w))
...
gh_buf.io.ic_crnt_target   := RegNext(core.io.ic_crnt_target)
```
= GHM
val ic_status           = Output(UInt(GH_GlobalParams.GH_NUM_CORES.W))
val ic_counter = Output(Vec(GH_GlobalParams.GH_NUM_CORES, (UInt(16.W))))
val checker_segment_id  = Output(Vec(GH_GlobalParams.GH_NUM_CORES, UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)))
val checker_big_owner   = Output(Vec(GH_GlobalParams.GH_NUM_CORES, UInt(4.W)))
outer.core_r_arfs_SRNode.bundle := Cat(core.io.arfs_ecp_dest, core.io.r_arfs_pidx(0), core.io.r_arfs(0))

= LSU
val lsu = Flipped(new boom.lsu.LSUCoreIO)
== Dcache
val csr_cycle = Output(UInt(xLen.W)) 时间戳

val active_packet_seq   = Output(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
val packet_alloc_valid  = Output(Bool())
val packet_alloc_seq    = Output(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
val debug_maincore_status = Output(UInt(4.W))


```scala
outer.dcache.module.io.traffic_check_state := core.io.debug_maincore_status === 2.U
outer.dcache.module.io.csr_cycle          := core.io.csr_cycle
outer.dcache.module.io.packet_alloc_valid := core.io.packet_alloc_valid
outer.dcache.module.io.packet_alloc_seq   := core.io.packet_alloc_seq
outer.dcache.module.io.packet_seq_baseline := core.io.active_packet_seq
```


= RoCC
val ght_prv  = Output(UInt(2.W))
val csr_counter = Output(Vec(84, UInt(32.W)))
val checker_state_data  = Output(UInt(64.W))
val checker_enable_rd   = Output(UInt(GH_GlobalParams.GH_CHECKER_MASK_WIDTH.W))
val debug_perf_val = Output(UInt(64.W))

```scala
cmdRouter.io.ght_satp_ppn := core.io.ptw.ptbr.ppn
cmdRouter.io.ght_sys_mode := core.io.ght_prv
cmdRouter.io.csr_counter_in := core.io.csr_counter
cmdRouter.io.elu_data_in := core.io.debug_perf_val
```
== 无用
控制 FPU 舍入的不用管。
val fcsr_rm = UInt(freechips.rocketchip.tile.FPConstants.RM_SZ.W)

= 双向
val rocc = Flipped(new freechips.rocketchip.tile.RoCCCoreIO())
== 不关心
取址不关心
val ifu = new boom.ifu.BoomFrontendIO

翻译不关心
val ptw = Flipped(new freechips.rocketchip.rocket.DatapathPTWIO())
val ptw_tlb = new freechips.rocketchip.rocket.TLBPTWIO()



= Other
下面的这些信号不用管。
```scala
val r_arfs = Output (Vec(1, (UInt((xLen*2+8+1).W))))
val r_arfs_pidx = Output(Vec(1, UInt(8.W)))


val arfs_ecp_dest = Output(UInt(8.W))
  }
```
== 没用到
val commit_rs1    = Output(Vec(coreWidth, UInt(xLen.W)))
val alu_out = Output(Vec(coreWidth, UInt(xLen.W)))
val csr_addr = Output(Vec(coreWidth, UInt(CSR_ADDR_SZ.W)))
val rsu_merging = Output(UInt(1.W))
val rsu_merging_valid = Output(Bool())
val shared_CP_CFG = Output(UInt(13.W))
== Output
```scala
val trace = Output(Vec(coreParams.retireWidth, new TracedInstruction)) // 调试
```
== Input
```scala
val hartid = Input(UInt(hartIdLen.W))
val interrupts = Input(new freechips.rocketchip.tile.CoreInterrupts())
val big_hang = Input(Bool())
val gh_stall = Input(Bool())
val bigComp  = Input(UInt(3.W))
val num_of_checker = Input(UInt(8.W))
val icctrl = Input(UInt(4.W))
val t_value = Input(UInt(4.W))
val if_correct_process = Input(UInt(1.W))
val clear_ic_status_tomain = Input(UInt(GH_GlobalParams.GH_NUM_CORES.W))
val icsl_na = Input(UInt(GH_GlobalParams.GH_NUM_CORES.W))
val core_trace = Input(UInt(1.W))
val ic_trace = Input(UInt(1.W))
val debug_perf_ctrl = Input(UInt(GH_GlobalParams.GH_PERF_CTRL_BITS.W))
val big_core_id         = Input(UInt(4.W))
val checker_enable_mask = Input(UInt(GH_GlobalParams.GH_CHECKER_MASK_WIDTH.W))
val checker_enable_we   = Input(UInt(1.W))
val checker_state_sel   = Input(UInt(4.W))
val global_ic_status    = Input(UInt(GH_GlobalParams.GH_NUM_CORES.W))
val global_checker_big_owner = Input(UInt((GH_GlobalParams.GH_NUM_CORES * 4).W))
```
