#set document(
  title: "L1 到 L2 未校验脏写回延迟统计",
  author: "GuardianCouncil 方法说明",
)
#set page(paper: "a4", margin: (x: 18mm, y: 17mm))
#set text(lang: "zh", size: 10.5pt)
#set par(justify: true, leading: 0.72em)
#set heading(numbering: "1.1")
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
  #text(size: 19pt, weight: "bold")[L1 到 L2 未校验脏写回延迟统计]
  #v(0.5em)
  #text(size: 10.5pt, fill: rgb("#455a64"))[基于 Chipyard 的 BOOM 大核与 Rocket checker 协同校验]
]

#v(0.8em)

本文依据当前工作区相对提交 `f8763f74c` 的未提交 changes 整理。文档只做代码检查和信号分析，不包含仿真、Chisel 硬件生成、FPGA 测量或结果解读。当前参数是一个 BOOM 大核和四个 Rocket checker 小核：`GH_NUM_BIG_CORES = 1`、`GH_NUM_CORES = 5`。

本轮目标不是在写回通路上阻塞等待 checker，而是在 BOOM DCache 观察每条 L1 -> L2 行级 C 通道消息：写回发生时，如果该缓存行所属的 checker 包还没有被连续安全水位覆盖，则记录为“未校验”；等该包及其之前的包都以 PASS 结果完成后，再用安全水位推进的周期结算延迟。

本文使用“包”表示一次由 `R_IC` 分配的检查包，使用“包序号”表示 `GH_PACKET_SEQ_BITS = 32` 位的全局序列号。序号 `0` 保留给不属于受检包的操作。

#outline(title: [目录], depth: 3)

= 结论和范围

== 已实现的统计对象

#table(
  columns: (1.55fr, 3.1fr, 2.7fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*对象*], [*实现*], [*统计边界*]),
  [`L1 -> L2` 总写回], [`tl_out.c` 首 beat `fire`，每条行级消息只计一次。], [只在 `trafficCounting` 窗口内计数。],
  [`L1 -> L2` 脏写回], [首 beat opcode 为 `ReleaseData` 或 `ProbeAckData`。], [clean Release/ProbeAck 不进入脏写回分母。],
  [未校验脏写回], [缓存行有有效包归属，且写回包序号大于写回当拍的 `safePacketWatermark`。], [写回时分类永久保留；之后变安全只改变 pending/resolved。],
  [未校验延迟], [写回时刻和安全水位推进时刻均在 BOOM CSR cycle 域取样。], [`safe_cycle_sum - writeback_cycle_sum` 再除以 `resolved`。],
  [L2 -> DRAM], [旧的两个软件向量槽位仍保留。], [本轮没有新增包序号或延迟分类。],
)

“未校验”是事件发生时的分类，不是事后回写的最终状态。一个包失败或取消时，连续 PASS 水位不能越过它；相关 pending 桶因此不能形成可靠的安全时刻，软件会拒绝输出平均延迟。

== 相关未提交文件

- 硬件核心路径：`R_IC.scala`、`RocketCore.scala`、`RocketTile.scala`、`GHM.scala`、`GH_GlobalParams.scala`、`BoomCore`/`BoomTile`、`LSU`、`mshrs.scala` 和 `dcache.scala`。
- 软硬件接口：`GHE.scala` 将性能控制扩为 7 位，`ghe.h` 将统计向量扩为 35 项。
- 软件收尾：`Software/Test/test.c` 增加包统计排空、STOP 快照和未校验脏写回平均延迟打印；`test_config.h` 增加排空超时。
- `test.dump`、`test.riscv` 是测试程序重新编译产生的派生文件，不改变硬件信号语义。

= 总体信号图

```text
R_IC snapshot_accepted
  -> packet_seq_counter + 1
  -> packet_alloc_seq / active_packet_seq
  -> checker_segment_id[checker]
  -> GHM packet/ARF CDC queues
  -> RocketTile sequence high-watermark
  -> RocketCore package_seq_reg
  -> full_check_complete or package_cancelled
  -> {valid, status, seq} result queue
  -> GHM result AsyncQueue
  -> BOOM checker_results[i]
  -> resultAccepted / bitmapCompleted / bitmapPassed
  -> newSafePacketWatermark

BOOM active_packet_seq
  -> STQEntry.packet_seq at commit
  -> BoomDCacheReq.packet_seq
  -> MSHR request/replay (max sequence retained)
  -> dirtyPacketSeq(set)(way), dirtyPacketTracked(set)(way)
  -> WritebackUnit active_packet_seq/tracked
  -> TL-C first beat + opcode
  -> verified / unverified / untracked
  -> 256-entry package bucket
  -> safe_cycle_sum and writeback_cycle_sum
  -> GHE traffic counter index 18..34
  -> test.c average latency
```

这条链有三个不同的时序域：BOOM 的 R_IC、DCache 和 CSR cycle 是同一 BOOM 时钟域；每个 checker 有自己的 Rocket 时钟域；GHM 通过独立的 `AsyncQueue` 在这些域之间传输数据。包序号而非本地周期是跨域关联键。

= 包序号和 checker 结果链路

== 包分配：R_IC

`R_ICIO` 新增以下输出，位宽统一为 32 位：

```scala
val checker_segment_id = Output(Vec(totalnumber_of_cores,
  UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)))
val active_packet_seq = Output(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
val packet_alloc_valid = Output(Bool())
val packet_alloc_seq = Output(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
```

`R_IC` 内部保存 `packet_seq_counter`、`active_packet_seq` 和每个 checker 的 `checker_segment_id_reg`。在 `fsm_snap` 中，`snapshot_accepted = if_dosnap | if_dosnap_priv` 且目标 checker 可用时，偶数控制类型（`!ctrl(0)`）形成 CPS，执行：

```scala
val allocated_packet_seq = packet_seq_counter + 1.U
when (package_allocated) {
  packet_seq_counter := allocated_packet_seq
  active_packet_seq := allocated_packet_seq
  checker_segment_id_reg(crnt_target_ic) := allocated_packet_seq
}
io.packet_alloc_valid := package_allocated
io.packet_alloc_seq := allocated_packet_seq
```

奇数控制类型是同一包的 ECP，不重复分配序号。`checker_segment_id` 对大核而言是每个 checker 最近一次分配到的包号；BOOM tile 将整段 `Vec` 打包，经 BundleBridge 送入 GHM。

需要注意，`packet_alloc_valid` 是一拍事件，而 `active_packet_seq` 是保持值。BOOM DCache 在统计窗口内只用 `packet_alloc_valid && trafficCounting` 登记新包；LSU 在 checker 状态中使用保持的 `active_packet_seq` 给后续 store 归属。

== GHM：包与 ARF/CSR 片段分别过 CDC

`GHMIO` 展宽了包和 ARF 输出，并增加 checker 结果接口：

```text
ghm_packet_outs: {valid, packet_seq, packet_payload}
core_r_arfs_c:   {valid, packet_seq, arf_payload}
checker_result_in:  {valid, status, packet_seq}
checker_results_out: {valid, status, packet_seq}
```

对 checker `i`，GHM 从匹配目标的大核输入中选择 payload，并用 `checker_segment_id_bigcore` 的对应 32 位片段给两个独立队列加序号：

```scala
u_data_cdc(i).io.enq.bits := Cat(selected_packet_seq,
  Mux1H(sel_data, io.ghm_packet_in))
u_arfs_cdc(i).io.enq.bits := Cat(selectedArfSeq, selectedArfPayload)
```

ARF 输入顶部还有 8 位 ECP 路由信息。GHM 先取 `arfPayloadBits - 1, 0`，再拼接序号，避免把路由字段截断时误丢序号高位。

两个队列的头序号在 checker 时钟域比较：

```scala
dataHeadInOrder := !arf_deq.valid || dataHeadSeq <= arfHeadSeq
arfHeadInOrder  := !data_deq.valid || arfHeadSeq <= dataHeadSeq
data_deq.ready  := data_cdc_ready && dataHeadInOrder
arf_deq.ready   := arfHeadInOrder
```

因此旧包会先于新包出队，数据片段和 ARF 片段不会因为两个 CDC 队列的出队速度不同而混包；代码没有丢弃较新的队列项，而是保持它等待较早序号。

GHM 还把 `ghm_status_in(0)(31)` 作为大核 GH_BUF 的“生产端为空”电平，在 checker 时钟域用 `AsyncResetSynchronizerShiftReg` 同步。`packet_ingress_empty = cdc_empty && filterEmptySynced`，其中 `cdc_empty` 要求 data/ARF 两个出队队列都空。该信号同时：

- 送往 `ghm_cdc_empty_out`，再进入 RocketCore；
- 决定 `ghm_status_outs` 是否允许下游看到 GHM 状态；
- 替代旧的“filter empty 控制脉冲与 CDC empty 同拍相交”逻辑。

GH_BUF 的 `ght_filters_empty` 也由单纯 `buf_all_empty` 改为 `buf_all_empty && !new_packet.reduce(_|_)`，避免 FIFO 在当前边沿接收新包时短暂报告空。

== RocketTile：序号高水位过滤

RocketTile 解包 GHM 输出，分别提取 `dataSeqValid/dataSeq` 和 `arfsSeqValid/arfsSeq`。同一 checker 周期选择两类片段中的较大序号 `cycleMaxSeq`，并保存 `packetSeqHighWatermark`：

```scala
val cycleSeqAccepted = cycleSeqValid &&
  cycleMaxSeq >= packetSeqHighWatermark
val dataSeqAccepted = dataSeqUsable && cycleSeqAccepted &&
  dataSeq === cycleMaxSeq
val arfsSeqAccepted = arfsSeqUsable && cycleSeqAccepted &&
  arfsSeq === cycleMaxSeq
when (cycleSeqAccepted && cycleMaxSeq > packetSeqHighWatermark) {
  packetSeqHighWatermark := cycleMaxSeq
}
```

`dataSeqAccepted` 才能使 `packet_en/packet_bj_en` 有效；`arfsSeqAccepted` 才能使 CPS ARF 片段进入 checker。小于已观察高水位的迟到片段被屏蔽，等序号片段仍可继续到达。

== RocketCore：包尾不是单一 ARF 脉冲

RocketCore 用 `package_seq_reg` 记录当前 checker 包号。新包判定为：

```scala
val new_package = io.packet_seq_valid && io.packet_seq > package_seq_reg
```

包开始还要求 `R_ICSL` 接受 COPY、checker 执行单元空闲，并满足包号非零。完整包完成条件为：

```scala
val packet_ingress_drained = io.cdc_empty && packet_ingress_empty_prev
val full_check_complete = package_check_active &&
  packet_ingress_drained && lsl.io.if_empty &&
  arf_check_complete && (!csr_check_required || csr_check_complete)
```

这里有两级防护：GHM 的 `packet_ingress_empty` 已同时考虑 BOOM producer 和两个 CDC 队列，RocketCore 又要求连续两个 checker 周期观察到 `io.cdc_empty`；`lsl.io.if_empty` 防止 LSL 仍有数据时提前报包尾。

为形成这两个错误输入，`R_RSUSL` 把比较不一致的 `channel_enq_valid` 导出为 `check_error`，并在 `arf_check_active` 期间拉高 `core_hang_up`，避免比较仍在读 live ARF/FARF 时 checker 软件改写寄存器。`CSR.scala` 新增 `shadow_check_error` 和 `shadow_check_required`，同时把 `shadow_status` 初始化为 0；不能在 `checker_mode` 一进入时清掉 shadow 状态，否则 `do_cp_check` 永远无法启动。对应的 `package_error` 会在包内保持，故包尾状态是：

```text
status = PASS       无 ARF/LSL/CSR 错误且 full_check_complete
status = FAIL       full_check_complete 但 package_error 为真
status = CANCELLED  新包到达时旧包尚未 full_check_complete
```

包结果以 `{status, seq}` 进入 RocketCore 内部深度 4 的 Queue。若 queue 暂时不能接收，`package_result_waiting` 保存状态和旧包序号；结果交给 GHM 前还要等待 `package_local_clear_seen`，从而避免 R_ICSL 已经复位而完整比较结果尚未被观察。

`R_ICSL` 的 `if_check_completed` 由 `package_completion_pulse` 驱动，不再直接把单一 `if_cp_check_completed` 当作整个包完成。`if_rh_cp_pc` 也被限制为完整包完成后才允许回到 checker 软件上下文。

== 结果回传和 BOOM 释放

Rocket checker tile 输出 `Cat(package_result_valid, package_result_status, package_result_seq)`。GHM 为每个 checker 建立独立 result `AsyncQueue`：

```scala
u_result_cdc(i).io.enq.valid := checker_result_in(i)(34)
u_result_cdc(i).io.enq.bits  := checker_result_in(i)(33, 0)
u_result_cdc(i).io.deq.ready := true.B
io.checker_results_out(i) := Mux(u_result_cdc(i).io.deq.fire,
  Cat(true.B, u_result_cdc(i).io.deq.bits), 0.U)
```

`checker_result_ready` 反向回到 Rocket，使结果 valid 在队列满时保持。结果出队的 BOOM 域脉冲 `checker_result_release` 同时组成 `clear_ic_status_tomain` 的 checker 位，因而 R_IC 的释放与带序号结果在同一个 BOOM 域事件上关联；旧的独立 clear 控制 CDC 不再承担 BOOM 释放。

= BOOM 脏行归因到 TL-C

== 受检 store 的序号传播

BOOM 在 `BoomCore` 中把 R_IC 的三个信号送出，并把当前序号送给 LSU：

```scala
io.lsu.active_packet_seq := Mux(ic_master.io.packet_alloc_valid,
  ic_master.io.packet_alloc_seq,
  Mux(ic_master.io.debug_maincore_status === 2.U,
    ic_master.io.active_packet_seq, 0.U))
```

`STQEntry` 新增 `packet_seq`。进入 STQ、分支 kill、异常、队列回收和 reset 时清零；ROB commit store 时锁存 `io.core.active_packet_seq`。因此只有在受检 `fsm_check` 状态下提交的 store 才带非零包号，同周期新包分配优先使用 `packet_alloc_seq`。

LSU 的 `BoomDCacheReq` 和 DCache 内部请求都带 `packet_seq`。普通 store 在 `stq_commit_e` 到 `dmem_req` 时复制；未使用的 load、prefetch 和初始化路径置零。DCache ingress 的 `traffic_check` 和 `traffic_cacheable` 也在同一请求处锁存，之后跨 miss/refill/replay 保持。

MSHR primary request 复制序号，secondary hit 时执行：

```scala
when (io.req.packet_seq > req.packet_seq) {
  req.packet_seq := io.req.packet_seq
}
```

这使同一 cache line 的在途请求不会因为后来的包而退回旧序号；replay 从 MSHR 再把序号带回 DCache pipeline。

== 每个 cache line 的归因状态

DCache 增加两个 `nSets x nWays` 寄存器阵列：

```scala
dirtyPacketSeq(set)(way)     // 最近受检脏化归属的最大包序号
dirtyPacketTracked(set)(way) // 该归属是否有效
```

状态更新点是 data-array 写入握手，而不是请求发射：

1. `dataWriteArb.io.in(1).fire` 是 refill 安装新 tag/数据，清除被替换 way 的旧归因。
2. `dataWriteArb.io.in(0).fire` 是成功 store/SC/AMO 数据写入。序号为 0 时清除归因；非零时置 `tracked`，并保存旧值与新值的较大者。

保存最大序号是为了抵抗同一 line 上较老请求晚于较新请求完成的情况；未校验判断只应看到该 line 相关受检脏化的最晚包。`s3_way` 改为显式 `Reg(UInt(nWays.W))`，是因为这里随后使用 `OHToUInt`，原来的 widthless `RegNext` 不能稳定提供 way 位宽。

== WritebackUnit 锁存归因

写回仲裁器从 probe 和 MSHR eviction 选择 `WritebackReq`。在请求进入 `BoomWritebackUnit` 时，DCache 用请求的 set/way 查表：

```scala
wb.io.packet_seq := dirtyPacketSeq(wbReqSet)(wbReqWay)
wb.io.packet_tracked := dirtyPacketTracked(wbReqSet)(wbReqWay)
```

`BoomWritebackUnit` 在 `io.req.fire` 锁存这两个字段到 `packet_seq`/`packet_tracked`，再通过 `active_packet_seq`/`active_packet_tracked` 保持到整条 Release/ProbeAckData 发完。这样写回填充 data buffer、等待 grant 或 C 通道反压时，归因不会随 cache array 后续操作改变。

== L1 -> L2 事件点

`TLArbiter.lowest` 合并 `wb.io.release` 与 `prober.io.rep` 后，DCache 用 TileLink C 通道首 beat 计数：

```scala
val (c_first, _, _, _) = edge.count(tl_out.c)
val l1_l2_wb_event = tl_out.c.fire && c_first
val l1_l2_wb_dirty_event = l1_l2_wb_event &&
  tl_out.c.bits.opcode.isOneOf(
    TLMessages.ReleaseData, TLMessages.ProbeAckData)
```

`fire` 排除反压期间的重复观察，`c_first` 将多 beat cache line 合并为一个行级事件；无 data 的 Release/ProbeAck 只增加总写回而不增加脏写回。

= 安全水位、分类和延迟结算

== 统计窗口和包完成位图

DCache 以 `statsWindow = 256` 建立 `bitmapAllocated`、`bitmapCompleted`、`bitmapPassed` 和 32 位 `bitmapSeq`。索引是序号低 8 位，完整序号保存在 `bitmapSeq` 中。

统计窗口内的包分配事件：

```scala
val measuredPacketAlloc = io.packet_alloc_valid && trafficCounting
```

序号为 0 或低 8 位槽位仍被占用时产生 `allocationCollision`，本轮 `statsValid` 置假。该逻辑没有向 R_IC 提供反压，因此窗口溢出不会暂停包分配，只会使统计失效。

每个 checker 结果解析为 `valid/status/seq`。结果只有同时满足“非零、没有低于 reset baseline、状态为 0..2、对应 bitmap 分配且未完成、不是同周期重复结果”才是 `resultAccepted`。PASS 设置 `bitmapPassed`，FAIL/CANCELLED 设置完成但不设置通过；相关计数分别累加 `failedPackages` 和 `cancelledPackages`。

== 连续安全水位

`safePacketWatermark` 表示从 reset baseline 开始已经连续 PASS 的最大序号。每个周期从 `safePacketWatermark + 1` 扫描最多 256 项：每项必须满足 `allocated && seq exact && completed && passed`，遇到缺口就停止。得到：

```scala
val newSafePacketWatermark = safePacketWatermark + safeAdvance
```

只有连续区间越过后，已越过的 bitmap 槽位才清空。于是 checker 结果可以乱序到达，但安全水位不能越过尚未完成、失败或取消的包。

`io.packet_seq_baseline` 接的是 BOOM 当前 `active_packet_seq`。`traffic_reset` 时它同时初始化 `safePacketWatermark` 和 `measurementSeqFloor`，这样 reset 之前的结果不会被当作本窗口结果接受。

== 三类脏写回判定

所有条件都带 `trafficCounting && l1_l2_wb_dirty_event`。写回使用水位推进前的 `safePacketWatermark`：

```scala
unverified = tracked && seq != 0 && seq > safePacketWatermark
verified   = tracked && seq != 0 && seq <= safePacketWatermark
untracked = !tracked || seq == 0
```

分类含义如下：

- `verifiedDirtyWb`：包已经在写回当拍之前安全，增加 counter 28。
- `unverifiedDirtyWb`：增加 `unverifiedDirtyWbSeen` counter 18。它不会因后续结果而改成 verified。
- `untrackedDirtyWb`：没有有效受检归属，增加 counter 29；这不是未校验延迟样本。

clean 写回只影响 counter 13，不进入三类脏写回守恒式。脏写回总数 counter 14 应满足：

```text
L1_L2_WB_DIRTY = VERIFIED_DIRTY_WB
                  + UNVERIFIED_DIRTY_WB_SEEN
                  + UNTRACKED_DIRTY_WB
```

== 延迟桶和同周期处理

对未校验事件，`wbBucketIdx = active_packet_seq(7, 0)`，每个桶保存：

```text
bucketValid
bucketSeq
bucketCount
bucketWritebackCycleSum
```

若桶空、同序号或本周期正要 resolve，则可接受；若桶占用且序号不同、旧桶又没有 resolve，则 `wbBucketDropped`，增加 counter 21 并令 `statsValid = false`。可接受事件增加 `bucketCount`，并把当前 `io.csr_cycle` 加到 `bucketWritebackCycleSum`。

水位推进后，`bucketSeq <= newSafePacketWatermark` 的桶在本周期结算。结算量为：

```text
resolvedThisCycle = resolvedBucketsThisCycle + wbResolvedImmediately
writebackCyclesResolved = bucketWritebackCycleSum + immediate_writeback_cycle
safeCyclesResolved = io.csr_cycle * resolvedThisCycle
```

如果写回和 checker PASS 结果在同一 BOOM 边沿到达，事件先按旧水位判为 unverified，但 `wbResolvedImmediately` 令其当拍结算；该样本的安全时刻和写回时刻相同，延迟贡献为 0 个 BOOM cycle。

普通桶结算时，所有桶内事件共享水位推进当拍的 `io.csr_cycle`，所以硬件保留的是两个总和而不是每一条写回的独立 timestamp：

```text
latency_cycle_sum = safeCycleSum - writebackCycleSum
average_cycles = latency_cycle_sum / resolved
```

计数器 19 是成功结算样本数，计数器 20 是当前仍在桶中的 pending 数。硬件用 73 位中间和和乘法溢出检查，异常累加到 counter 34 并清除 `statsValid`。

== 失败、取消和结果异常

以下任何事件都会使统计无效：

- 包结果为 FAIL 或 CANCELLED；
- 包分配低位槽位碰撞；
- valid 结果无法匹配分配 bitmap、状态值为 3 或重复；
- 桶碰撞丢弃；
- bucket count、周期和、`pending` 账目或乘法溢出。

注意 `resultStale` 只排除 reset baseline 之前或 STOP 后不属于本窗口的结果，不会替代错误诊断。`packageResultDropped` counter 27 记录分配/结果异常，`failedPackages` 和 `cancelledPackages` 分别记录合法接收但不能形成 PASS 水位的包。

= 性能控制、读回和软件公式

== 7 位性能控制

`GH_GlobalParams` 将 `GH_PERF_CTRL_BITS` 从旧宽度扩为 7 位，保留 bits 4:1 的旧 selector，并新增：

#table(
  columns: (1fr, 2fr, 4fr),
  inset: 4.5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*bit*], [*名字*], [*行为*]),
  [`0`], [`RESET`], [清除 BOOM DCache 统计、位图、桶和基础访存计数；建立当前 `active_packet_seq` baseline。],
  [`4:1`], [legacy selector], [保留原有 checker 性能选择器。],
  [`5`], [`START`], [打开 `trafficEnabled`，开始接受计数事件。],
  [`6`], [`STOP`], [关闭新事件并在上升沿冻结 BOOM 35 项快照。],
)

GHE `funct = 0x76` 将 `rs1[6:0]` 锁存到 `debug_perf_ctrl`；`ghe.h` 的 `ghe_fpga_perf_command` 发送控制字后再发送 0，因此 RESET/START/STOP 都是脉冲。DCache 的有效窗口为：

```scala
val trafficCounting = (trafficEnabled || io.traffic_start) &&
  !io.traffic_stop && !io.traffic_reset
val trafficStopPulse = io.traffic_stop && !RegNext(io.traffic_stop, false.B)
```

`traffic_check_state` 仍由 `debug_maincore_status === 2.U` 产生，它用于把新进入 DCache 的请求标为受检流量；窗口控制则独立决定是否更新统计寄存器。

== 35 项统计向量

`GH_TRAFFIC_COUNTERS` 从 18 扩为 35，`funct = 0x7B` 用 `rs1` 索引读取，越界返回 0。0..17 的旧布局保持不变；BOOM hart 0 的新增布局是：

#table(
  columns: (0.7fr, 2.8fr, 3.8fr),
  inset: 4pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*索引*], [*名称*], [*含义*]),
  [18], [`UNVERIFIED_DIRTY_WB_SEEN`], [写回时未超过安全水位的受检脏写回数。],
  [19], [`UNVERIFIED_DIRTY_WB_RESOLVED`], [已从桶结算或同周期立即结算的样本数。],
  [20], [`UNVERIFIED_DIRTY_WB_PENDING`], [仍等待安全水位的桶内样本数。],
  [21], [`UNVERIFIED_DIRTY_WB_DROPPED`], [桶序号冲突导致未接收的样本数。],
  [22], [`FAILED_PACKAGES`], [合法接收的 FAIL 包数。],
  [23], [`SAFE_CYCLE_SUM`], [各结算样本的安全水位周期总和。],
  [24], [`CYCLE_SUM`], [各未校验样本写回周期总和。],
  [25], [`STATS_VALID`], [无异常且可用于平均值的标志，1 为有效。],
  [26], [`SAFE_PACKET_WATERMARK`], [连续 PASS 安全包水位。],
  [27], [`PACKAGE_RESULT_DROPPED`], [包分配/结果异常数。],
  [28], [`VERIFIED_DIRTY_WB`], [写回时已安全的受检脏写回数。],
  [29], [`UNTRACKED_DIRTY_WB`], [没有有效包归属的脏写回数。],
  [30..33], [allocated/completed/passed/cancelled], [包生命周期计数。],
  [34], [`STATS_ARITHMETIC_OVERFLOW`], [桶、周期和、乘法或 pending 账目溢出数。],
)

Rocket checker 的向量 13..16 及新增 18..34 置零；checker 只返回自身访存分类和 `store_uncache` 周期和。L1 -> L2 未校验脏写回延迟只读 BOOM hart 0 的向量。

== 软件排空和 STOP 顺序

`test.c` 的收尾顺序是：

```text
START
  -> 工作负载
  -> 等待 checker hart 写完自己的 traffic snapshot
  -> 循环读取 BOOM allocated/completed/pending/异常计数
  -> completed == allocated 且 pending == 0 时排空
  -> ghe_fpga_perf_stop()
  -> 读取 BOOM 35 项冻结快照
  -> 校验并打印平均延迟
```

`wait_for_package_statistics_to_drain` 在 `PACKAGE_DRAIN_TIMEOUT_CYCLES`（默认 100000）内遇到 result drop、writeback drop 或 arithmetic overflow 会立即返回 hard error；超时则不假设结果已经完整。STOP 放在排空之后，是为了允许已经进入系统的 checker 结果和未校验写回桶继续结算；STOP 上升沿以后 DCache 读回由 snapshot 保证一致。

== 软件平均延迟公式

`print_unverified_dirty_writeback_latency` 只使用 BOOM hart 0：

```text
seen       = counter[18]
resolved   = counter[19]
pending    = counter[20]
safe_sum   = counter[23]
write_sum  = counter[24]

latency_cycle_sum = safe_sum - write_sum
average_cycles    = latency_cycle_sum / resolved
average_ns        = latency_cycle_sum * 1e9
                    / (BOOM_CORE_FREQUENCY_HZ * resolved)
```

输出平均值的前提是 `stats_valid == 1`、`pending/dropped/result_dropped/overflow == 0`、没有 FAIL/CANCELLED、`completed == allocated`、`passed == completed`、`seen == resolved`，并且三类脏写回之和等于 counter 14。`resolved` 而不是 `seen` 作为分母，因为只有结算样本同时拥有写回时刻和安全时刻。

同一批 changes 还保留并扩展了 `store_uncache` 延迟统计，但它不是本文的 L1 -> L2 样本：BOOM 在 IOMSHR 的 TileLink A `mem_access.fire` 且命令为普通 `M_XWR` 时累加 BOOM `csr_cycle`；Rocket 在 checker store 成功到达 WB 时累加包内数量，并在完整包尾用 `csr_cycle * 包内数量` 结算。`test.c` 对各 hart 的周期和按 `BOOM_CORE_FREQUENCY_HZ`/`CHECKER_CORE_FREQUENCY_HZ` 换算后相减。该路径使用包尾时间戳总和，不能用来替代本文按 cache line 归因的 C 通道写回时间。

= 审查得到的边界条件

== 序号回绕没有模块化比较

32 位序号只保留 0 的特殊含义，代码使用普通无符号 `>`、`<=` 和 `seq <= measurementSeqFloor`。当前实现没有 RFC1982 式回绕比较；`packet_seq_counter` 回绕到 0 也会触发 `packet_alloc_seq === 0.U` 异常路径。因此长时间运行超过 2^32-1 个包前必须增加回绕协议或重新复位整个协同组。

== 256 项窗口和桶碰撞

位图和延迟桶都按低 8 位索引，完整序号用于确认槽位身份。只要旧序号未越过安全水位，同低 8 位的新包就会碰撞并令 `statsValid = false`。这不是硬件阻塞机制；软件只能看到诊断计数并放弃平均值。

== 失败包会阻塞安全水位

安全水位只越过连续 PASS。FAIL/CANCELLED 会增加对应诊断计数并使 `statsValid` 变假，即使后续包 PASS，也不会把水位越过失败包。因而软件排空条件的 `completed == allocated` 不能单独代表“所有包安全”。

== reset 边界和缓存行旧归因

`traffic_reset` 清空位图、桶和计数，并把水位设为 `io.packet_seq_baseline`；`resetBoundaryInvalid` 检查 checker 状态、位图和旧水位是否表明 reset 时有在途包。它没有逐项清零 `dirtyPacketSeq/dirtyPacketTracked` cache-line 阵列，因为该阵列不是统计窗口寄存器。旧 dirty line 可能在新窗口内写回：若其序号不高于 baseline 会被视为 verified，若无归因会被视为 untracked。因此新窗口开始前应保证协议边界和缓存状态满足预期，不能把 RESET 理解成 flush DCache。

== 延迟是包级聚合近似

桶内多条写回共享包序号，结算时共享同一水位推进周期；硬件没有记录每条写回的独立安全周期。输出是所有已结算样本的平均周期，不是地址一一匹配后的每事件精确延迟。若需要尾延迟、分位数或逐行配对，还要增加更深的时间戳 FIFO/关联表。

= 文件索引

- `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala`: 序号、结果状态、控制位和 35 项统计索引。
- `chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala`: 包分配序号和 checker 段序号。
- `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala`: data/ARF/result 三组 CDC 和 producer-empty 同步。
- `chipyard/generators/rocket-chip/src/main/scala/tile/RocketTile.scala`: checker 端序号过滤和 result 接口连接。
- `chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala`: 完整包完成、失败/取消、结果队列和 CSR/ARF 检查汇总。
- `chipyard/generators/boom/src/main/scala/common/tile.scala`: BOOM 序号、CSR cycle、性能控制和 DCache 端口连接。
- `chipyard/generators/boom/src/main/scala/lsu/lsu.scala`: STQ/DCache request 的包序号传播。
- `chipyard/generators/boom/src/main/scala/lsu/dcache.scala`: cache-line 归因、TL-C 首 beat 分类、位图、桶和 counter snapshot。
- `Software/Test/ghe.h`、`Software/Test/test.c`: RoCC 控制、counter ABI、排空和平均值公式。

本说明未执行仿真、硬件生成或运行测试程序；它描述的是当前未提交 RTL 与软件代码所表达的实现和边界。
