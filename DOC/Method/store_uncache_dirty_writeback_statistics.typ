#set document(
  title: "大小核协同校验中的延迟与脏写回统计实现",
  author: "GuardianCouncil 方法说明",
)
#set page(
  paper: "a4",
  margin: (x: 18mm, y: 17mm),
  numbering: "1 / 1",
)
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
  #text(size: 19pt, weight: "bold")[大小核协同校验中的延迟与脏写回统计实现]
  #v(0.5em)
  #text(size: 10.5pt, fill: rgb("#455a64"))[store_uncache、包级安全水位与 L1D 脏写回观测]
]

#v(0.8em)

本文根据当前工作区相对提交 `f8763f74c` 的未提交软硬件修改整理。目标系统为一个 BOOM 大核和四个 Rocket checker 小核。本文只描述现有实现，不包含仿真、硬件生成或测量结果。

本轮修改形成了两套相关但不同的延迟统计：

- `store_uncache` 检测延迟：大核和各小核分别在自己的 CSR `cycle` 时钟域内求时间戳总和，软件按各自频率换算后相减。
- L1→L2 未校验脏写回延迟：包序号判断写回时是否已经安全，写回时刻和安全水位推进时刻都取 BOOM CSR `cycle`，硬件先分别求和，软件再相减。

缓存行不再保存持久化的 CSR 时间戳。当前缓存行保存的是“最后一次受检脏化所属包的序号”；CSR 时间只在上述几个实际统计事件发生时采样。早期设想中的包头时间戳、缓存行最后操作时间戳已经由“序号判定、事件时刻采样”的方案取代。

#outline(title: [目录], depth: 3)

= 统计对象、时间基准和测量窗口

== 已实现的统计范围

#table(
  columns: (1.45fr, 2.35fr, 3.2fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*对象*], [*已实现内容*], [*统计边界*]),
  [`store_uncache`], [BOOM 发生时刻、四个 Rocket 所在包的整包校验完成时刻，以及近似平均检测延迟。], [按不可缓存普通 STORE 事件统计，不把 LR、SC、AMO 混入。],
  [L1→L2], [总写回、脏写回、已校验脏写回、未校验脏写回、无包归属脏写回和未校验平均延迟。], [BOOM DCache 的 TileLink C 行级消息；只观测，不阻塞写回。],
  [L2→DRAM], [DCache 来源 victim 的窗口内 total/dirty 数量。], [当前没有包序号分类，也没有未校验延迟统计。],
)

“未校验”是脏写回发生当拍的分类。某次写回当时若所属包还高于安全水位，它会永久计入 `unverified_seen`；以后水位越过该包，只会把该样本从 `pending` 转成 `resolved`，不会回改为 `verified`。

== 关键硬件信号总览

下面先列出贯穿统计路径的关键 RTL 信号。后续章节再说明其组合条件和寄存器更新。表中的“域”指该信号被采样和消费的时钟域。

#table(
  columns: (2.35fr, 1.2fr, 3.45fr),
  inset: 4.5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*信号*], [*时钟域*], [*作用*]),
  [`csr.io.time`], [各 core], [CSR `reg_cycle` 的输出，是所有时间统计的原始时间源。],
  [`core.io.csr_cycle` / `io.csr_cycle`], [BOOM], [把 BOOM CSR 周期送到 DCache，在不可缓存 STORE、C 通道写回和水位推进时采样。],
  [`icsl.io.csr_cycle`], [Rocket], [把 checker 自己的 CSR 周期送到 `R_ICSL`，只在整包完成时形成包尾贡献。],
  [`io.traffic_reset/start/stop`], [各 tile], [由 GHE 7 位 `debug_perf_ctrl` 解码出的测量窗口控制。],
  [`trafficCounting`], [各 tile], [真正允许新事件更新计数器的窗口使能。],
  [`mshrs.io.traffic_store_complete`], [BOOM], [不可缓存普通 STORE 的 TileLink A 接受事件。],
  [`checker_store_uncache_complete`], [Rocket], [checker 重执行的不可缓存普通 STORE 成功进入 WB。],
  [`full_check_complete`], [Rocket], [ARF/FARF 与必要 CSR shadow 均完成的整包尾脉冲。],
  [`package_result_valid/status/seq/ready`], [Rocket], [带反压的整包结果接口。],
  [`io.packet_alloc_valid/seq`], [BOOM], [包分配事件及其 32 位序号，供完成位图登记。],
  [`io.checker_results(i)`], [BOOM], [经 GHM AsyncQueue 跨域返回的 `{valid,status,seq}`。],
  [`newSafePacketWatermark`], [BOOM], [合入当拍分配和完成结果后的连续 pass 水位。],
  [`dirtyPacketSeq(set)(way)`], [BOOM], [缓存行最后相关受检脏化的最大包序号。],
  [`dirtyPacketTracked(set)(way)`], [BOOM], [上述缓存行包序号是否具有有效归属。],
  [`wb.io.active_packet_seq`], [BOOM], [WritebackUnit 接受 victim 时锁存、在 C 通道发送期间保持的包序号。],
  [`wb.io.active_packet_tracked`], [BOOM], [与在途包序号配套的归属有效位。],
  [`l1_l2_wb_event`], [BOOM], [TileLink C 首 beat `fire`，每条行级消息只产生一个脉冲。],
  [`l1_l2_wb_dirty_event`], [BOOM], [首 beat opcode 为 `ReleaseData` 或 `ProbeAckData`。],
  [`unverifiedDirtyWb`], [BOOM], [tracked 脏写回的包序号高于当拍新水位。],
  [`bucketResolve(i)`], [BOOM], [桶中包序号已经被当拍新水位覆盖。],
  [`trafficCounterLive/Snapshot`], [BOOM], [实时 35 项向量及 STOP 上升沿冻结副本。],
)

关键数据与控制关系可以压缩成下图：

```text
BOOM CSR cycle -----------------------------+
                                             | timestamp
IOMSHR mem_access.fire -> traffic_store_complete
                                             `-> store_uncache_cycle_sum

R_IC snapshot_accepted -> packet_alloc_seq -> bitmapAllocated
          |                    |
          |                    `-> STQ.packet_seq -> dirtyPacketSeq(set)(way)
          `-> packet + seq -> GHM -> Rocket -> full_check_complete
                                             -> package_result{status,seq}
                                             -> GHM result AsyncQueue
                                             -> io.checker_results
                                             -> resultAccepted
                                             -> newSafePacketWatermark

dirtyPacketSeq -> WritebackUnit lock
               -> C first-beat fire + opcode
               -> verified / unverified / untracked
               -> bucketWritebackCycleSum
newSafePacketWatermark -> bucketResolve -> safeCycleSum
```

从“事件发生在哪一拍”的角度，四个最重要的采样点如下。所有寄存器均在表中条件为真的时钟沿更新。

#table(
  columns: (1.65fr, 2.55fr, 1.3fr, 2.3fr),
  inset: 4.5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*统计事件*], [*事件脉冲*], [*采样时间*], [*更新状态*]),
  [BOOM `store_uncache`], [`trafficCounting && completed_store_uncache`], [`io.csr_cycle`], [`store_uncache_count`、`store_uncache_cycle_sum`。],
  [Rocket 包内 `store_uncache`], [`measured_st_uncache_deq`], [暂不采样], [`debug_perf_num_st_uncache_in_packet`。],
  [Rocket 整包完成], [`trafficCounting && io.if_check_completed`], [`io.csr_cycle`], [`debug_perf_st_uncache_cycle_sum += cycle × packet_count`。],
  [BOOM 未校验脏写回], [`wbBucketAccepted`], [`io.csr_cycle`], [`bucketCount`、`bucketWritebackCycleSum`、`pending`。],
  [脏写回变安全], [`bucketResolve(i)`], [`io.csr_cycle`], [`resolved`、`safeCycleSum`、`writebackCycleSum`。],
)

== CSR `cycle` 是每个 hart 的本地时间

Rocket Chip 的 CSR 文件把：

```scala
io.time := reg_cycle
```

引到 core。BOOM 通过 `core.io.csr_cycle` 把自己的值送到 DCache，Rocket 把自己的值送到 `R_ICSL`。因此这里使用的是各 hart 的 `cycle/mcycle`，不是共享 CLINT `mtime`。

这带来两个直接结论：

- BOOM 内部的写回时刻与安全时刻处于同一时钟域，可以直接做周期差。
- BOOM 与 Rocket 的 `store_uncache` 时间戳总和不能直接做周期数相减，必须先按各自频率换算到统一时间单位。

当前软件默认 `BOOM_CORE_FREQUENCY_HZ = 200 MHz`、`CHECKER_CORE_FREQUENCY_HZ = 100 MHz`，均可在编译时覆盖。不同 hart 的计数器起点、复位偏移和相位偏差当前按既定方法暂不校正，所以 `store_uncache` 的结果被明确称为近似检测延迟。

== RESET、START、STOP

性能控制从 5 位扩成 7 位，避免新增控制位在 GHE、RoCC router、tile 和 core 之间被截断：

#table(
  columns: (1fr, 1.7fr, 4.3fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*位*], [*名称*], [*作用*]),
  [`0`], [`RESET`], [清空本轮统计并关闭计数；BOOM 位图水位以当时活动包序号建立基线。],
  [`4:1`], [旧 selector], [保留已有性能选择器语义。],
  [`5`], [`START`], [启用测量；L2 计数保存起始基线。],
  [`6`], [`STOP`], [停止接受新测量样本；BOOM DCache 和 L2 在 STOP 上升沿各冻结一次快照。],
)

软件通过 GHE `funct=0x76` 依次写入命令值和零，因而 RESET、START、STOP 都表现为脉冲。统计窗口使用独立 `trafficEnabled`，不再把所有计数仅隐式绑定到校验 FSM 状态。STOP 之后协议内部仍可继续传递校验结果；停止的是新样本采集，不是协同校验本身。

控制信号的硬件连接链为：

```text
GHE: cmd.fire && funct == 0x76
  -> debug_perf_ctrl := rs1_val(6, 0)
  -> RoccCommandRouter(Boom/Rocket).debug_perf_ctrl_out
  -> core.io.debug_perf_ctrl / BOOM tile.debug_perf_sel
  |-- bit 0 -> io.traffic_reset / icsl.io.debug_perf_reset
  |-- bit 5 -> io.traffic_start / icsl.io.debug_perf_start
  `-- bit 6 -> io.traffic_stop  / icsl.io.debug_perf_stop
```

GHE 中只有 `doPerfCtrl = cmd.fire && funct === 0x76.U` 时才更新 7 位控制寄存器；软件随后写零，保证下游看到一个完整高脉冲和下降沿。

DCache 中实际使用的使能与 STOP 边沿信号为：

```scala
val trafficCounting = (trafficEnabled || io.traffic_start) &&
  !io.traffic_stop && !io.traffic_reset
val trafficStopPrev = RegNext(io.traffic_stop, false.B)
val trafficStopPulse = io.traffic_stop && !trafficStopPrev
```

因此 START 拉高的第一个周期就可以计数；STOP 或 RESET 拉高的周期不接受新样本。`trafficStopPulse` 只在 STOP 的 0→1 边沿为真，避免控制寄存器保持为 1 时反复覆盖快照。

= `store_uncache` 检测延迟

== BOOM 的起点

BOOM 不在 STORE 发射、进入 DCache 或 IOMSHR `valid` 时计数，而是在不可缓存请求真正被下游接受时计数：

```text
BOOM STQ
  -> DCache 判定 uncacheable
  -> BoomIOMSHR
  -> TileLink A mem_access.fire
       store_uncache_count += 1
       boom_cycle_sum += BOOM_CSR_cycle
```

事件 `traffic_store_complete` 要求 `mem_access.fire`、处于受检流量、未重复统计、不可缓存、使用 STQ，且命令严格为 `M_XWR`。`fire = valid && ready` 保证总线反压期间不会重复计数；精确命令匹配排除了 SC 和 AMO。计数脉冲与 `io.csr_cycle` 在同一个 BOOM 时钟沿采样，因此“大核求和所用的时钟数”和大核事件点匹配。

对应的关键信号表达式和传播关系为：

```scala
// BoomIOMSHR
io.traffic_store_complete := io.mem_access.fire &&
  req.traffic_check && !req.traffic_seen &&
  !req.traffic_cacheable && req.uop.uses_stq &&
  req.uop.mem_cmd === M_XWR

// BoomDCache MSHRFile 内部汇总所有 IOMSHR
io.traffic_store_complete :=
  mmios.map(_.io.traffic_store_complete).reduce(_ || _)

// BoomNonBlockingDCacheModule
val completed_store_uncache = mshrs.io.traffic_store_complete
when (trafficCounting && completed_store_uncache) {
  store_uncache_count := store_uncache_count + 1.U
  store_uncache_cycle_sum := store_uncache_cycle_sum + io.csr_cycle
}
```

其中 `req.traffic_check` 表明请求属于大核正在检查的执行区间，`req.traffic_seen` 是随请求传播的去重状态，`req.traffic_cacheable` 是 DCache manager 能力判定结果。最终事件以 `io.mem_access.fire` 为准，而不是 `io.mem_access.valid` 或 D 通道 `io.mem_ack.valid`。

若第 $i$ 个 BOOM 不可缓存 STORE 的完成周期为 $B_i$，硬件输出：

$ S_B = sum_i B_i $

以及事件数 $N_B$。

== Rocket 的终点是整个包完成

Rocket 的不可缓存 STORE 事件先在 checker 重执行的成功 WB 点识别：LSL 响应有效、没有 replay/exception、处于 checker 模式、命令为 `M_XWR`，且响应属性为不可缓存。这个事件只增加当前包的暂存数量，不立即写入时间戳总和。

这一事件由以下信号逐级产生：

```scala
val wb_valid = wb_reg_valid && !replay_wb && !wb_xcpt && !check_exception
val checker_mem_complete =
  (checker_mode.asBool || checker_priv_mode.asBool) &&
  wb_valid && wb_ctrl.mem && lsl_resp_valid && !lsl_resp_replay
val checker_store_complete =
  checker_mem_complete && wb_ctrl.mem_cmd === M_XWR
val checker_store_uncache_complete =
  checker_store_complete && !lsl_resp_cacheable

icsl.io.st_uncache_deq := checker_store_uncache_complete
icsl.io.csr_cycle := csr.io.time
```

`wb_valid` 排除了 pipeline replay、WB exception 和 checker exception；`lsl_resp_valid`/`lsl_resp_replay` 说明 LSL 返回是否可提交；`lsl_resp_cacheable` 提供原请求的缓存属性。因此 Rocket 计数点不是包接收点或 LSL 请求点，而是重执行结果成功到达 WB 的周期。

一个包的完成条件由 Rocket core 统一形成：

```text
ARF/FARF 比较已经完成
  AND
若该包需要 CSR shadow 比较，则 CSR shadow 也已经完成
  AND
包仍处于 active
  -> full_check_complete
```

load/store 检查错误、ARF/FARF 错误和 CSR shadow 错误会累计为包错误状态，但整包尾事件必须等待所有必要检查完成。原先直接使用 `RSUSL.if_cp_check_completed` 的做法只覆盖 ARF/FARF，现已改为 `full_check_complete`，这正是 Rocket 侧“整个包都完成”的时间点。

整包尾及结果状态的实际信号组合为：

```scala
val package_error_now = elu.io.error_ld || elu.io.error_st ||
  rsu_slave.io.check_error || csr.io.shadow_check_error
val arf_check_complete =
  arf_check_done_seen || rsu_slave.io.if_cp_check_completed.asBool
val csr_check_required =
  csr_check_required_seen || csr.io.shadow_check_required
val csr_check_complete =
  csr_check_done_seen || csr.io.if_priv_checkcomp

val full_check_complete = package_check_active && arf_check_complete &&
  (!csr_check_required || csr_check_complete)
val package_cancelled = package_check_active &&
  icsl.io.clear_ic_status.asBool && !full_check_complete
val package_result_event = full_check_complete || package_cancelled
val package_result_status = Mux(package_cancelled,
  GH_CHECKER_STATUS_CANCELLED.U,
  Mux(package_error || package_error_now,
    GH_CHECKER_STATUS_FAIL.U,
    GH_CHECKER_STATUS_PASS.U))

icsl.io.if_check_completed := full_check_complete.asUInt
icsl.io.if_check_cancelled := package_cancelled
```

`arf_check_done_seen`、`csr_check_required_seen`、`csr_check_done_seen` 和 `package_error` 是跨周期保持寄存器，防止几个完成/错误脉冲不在同一周期时丢失。`package_check_active` 与 `package_seq_reg` 把这些状态限定在当前包。

设包 $p$ 在某个 Rocket 上包含 $n_p$ 个不可缓存 STORE，整包完成时该 Rocket 的 CSR 周期为 $R_p$。`R_ICSL` 一次执行：

$ S_R := S_R + R_p times n_p $

随后清零本包暂存数。这样等价于给包中每个不可缓存 STORE 分配同一个包尾时间戳，而无需为每条事件存队列。若包被取消，本包暂存被清零，不会产生包尾时间戳贡献。

Rocket 侧求和所用的关键寄存器和更新信号为：

```scala
val measured_st_uncache_deq = io.st_uncache_deq & trafficCounting.asUInt
val st_uncache_count_at_packet_completion =
  debug_perf_num_st_uncache_in_packet + measured_st_uncache_deq
val st_uncache_packet_cycle_contribution =
  io.csr_cycle * st_uncache_count_at_packet_completion

when (trafficCounting && io.if_check_completed.asBool) {
  debug_perf_num_st_uncache_in_packet := 0.U
  debug_perf_st_uncache_cycle_sum :=
    debug_perf_st_uncache_cycle_sum +
      st_uncache_packet_cycle_contribution(63, 0)
}.elsewhen (io.if_check_cancelled) {
  debug_perf_num_st_uncache_in_packet := 0.U
}.elsewhen (measured_st_uncache_deq.asBool) {
  debug_perf_num_st_uncache_in_packet :=
    st_uncache_count_at_packet_completion
}
```

`st_uncache_count_at_packet_completion` 特意加上“当拍新完成”的 `measured_st_uncache_deq`，从而覆盖不可缓存 STORE 完成与整包完成恰好同周期的情况；否则该事件会因寄存器旧值而漏掉。

需注意，Rocket 的 `store_uncache` 总计数在重执行完成时已经增加，而取消只清除本包的时间戳暂存，不回退总计数。因此取消包最终会造成 BOOM/四 Rocket 事件数或有效时间戳语义不一致；软件的数量一致性检查会拒绝给出普通平均值，但当前没有单独为 `store_uncache` 输出“取消导致的时间戳缺项”诊断。

== 五个总和的读出与软件公式

每个 hart 的 GHE/RoCC 都能用 `funct=0x7B`、`rs1=counter_index` 读取本 tile 的 35 项流量向量。索引 17 是该 hart 的 `store_uncache_cycle_sum`。四个 checker 在各自 STOP 后读取本地向量，写入共享的 `hart_traffic[hart]`，再设置独立 ready 标志；hart 0 等待四个 ready 后读取自己的冻结向量并统一打印。

对 hart $h$，软件先用其频率 $f_h$ 换算：

$ T_h = S_h times 10^9 / f_h quad "(ns)" $

然后计算：

$ L_(sum) = sum_(h=1)^4 T_h - T_0 $

$ L_("avg") = L_(sum) / N_B $

软件先验证四个 checker 的 `store_uncache` 数量总和等于 BOOM 数量，并检查数量非零。若换算后的 checker 总和小于 BOOM 总和，打印带负号的结果，以暴露时间基准偏差，而不是让无符号减法下溢。换算和小数部分使用 `unsigned __int128`，避免 `cycle_sum × 10^9` 在软件中溢出。

该方法只保存两个聚合一阶矩，不保存事件的一一对应关系。因此它给出的是整组样本的近似平均值，不能恢复单条 STORE 的延迟分布，也无法检查某条 BOOM 事件是否恰好对应某条 Rocket 事件。

= 包序号与整包结果协议

== 32 位全局包序号

`R_IC` 只在接受新的 CPS 时分配 `packet_seq_counter + 1`。序号宽度为 32 位，值 0 保留给“不属于受检包”的访存。`ctrl=0/2/4` 对应包含新 CPS 的边界，分配新序号；`ctrl=1/3/5` 是当前包的 ECP-only 快照，必须沿用该 checker 已保存的序号。否则 ECP 会被错误标成下一包，正好造成同一 Rocket 周期看到“旧 data + 新 ARF/CSR”。分配脉冲和序号同时送入 BOOM DCache，用于位图登记；同一序号也保存到目标 checker 的 `checker_segment_id_reg`。

分配点的关键状态和输出是：

```scala
val snapshot_accepted = (if_dosnap | if_dosnap_priv).asBool
val package_allocated = snapshot_accepted && !ctrl(0).asBool
val allocated_packet_seq = packet_seq_counter + 1.U
when (package_allocated) {
  packet_seq_counter := allocated_packet_seq
  active_packet_seq := allocated_packet_seq
  checker_segment_id_reg(crnt_target_ic) := allocated_packet_seq
}
io.packet_alloc_valid := package_allocated
io.packet_alloc_seq := allocated_packet_seq
```

BOOM tile 进一步把 `core.io.packet_alloc_valid/seq` 接到 DCache 的同名输入；`core.io.active_packet_seq` 则在 store commit 时写入 `stq(idx).bits.packet_seq`。后者沿 `dmem_req.bits.packet_seq`、`mshrs.io.req.bits.packet_seq` 和 replay request 传播到最终 data-array 写入点。

序号伴随两条既有内容路径发送：

```text
BOOM R_IC 分配 seq
  |-- 数据 packet + seq -> GHM AsyncQueue(256) -> Rocket
  `-- ARF/CSR packet + seq -> GHM AsyncQueue(8) -> Rocket
```

RocketTile 从数据包或 ARF/CSR 包提取 `{seq_valid, seq}`。两类包经过独立 AsyncQueue，不能假设它们天然同拍对齐。GHM 因此先比较两个队头的完整序号：序号较小的一侧先出队，较大的一侧留在原队列；序号相同才允许同拍送达。这样不会通过丢弃旧 payload 来消除冲突。RocketTile 还维护已接收序号高水位，阻止真正迟到的旧片段污染新包。把序号与 payload 放在同一个队列 entry 中，可以避免单条通路内部错配。

GHM 和 RocketTile 的关键握手信号如下：

```text
数据路径:
  u_data_cdc(i).io.enq.valid = if_data_en
  u_data_cdc(i).io.enq.bits  = {selected_packet_seq, packet_payload}
  u_data_cdc(i).io.deq.ready = data_cdc_ready && dataHeadInOrder
  packet_out_wires(i) 仅在 u_data_cdc(i).io.deq.fire 时输出 valid=1

ARF/CSR 路径:
  u_arfs_cdc(i).io.enq.valid = if_arfs_en
  u_arfs_cdc(i).io.enq.bits  = {selectedArfSeq, arf_payload}
  u_arfs_cdc(i).io.deq.ready = arfHeadInOrder
  core_r_arfs_c(i) 仅在 u_arfs_cdc(i).io.deq.fire 时输出 valid=1

RocketTile:
  cycleMaxSeq = max(本拍有效的 dataSeq, arfsSeq)
  仅接受 cycleMaxSeq >= packetSeqHighWatermark 的片段
  data/ARF/CSR payload 均由各自的 SeqAccepted 门控
```

`u_data_cdc.io.enq.ready` 和 `u_arfs_cdc.io.enq.ready` 分别形成 `cdc_busy`、`arfs_cdc_busy` 反压。供 Rocket 判断包尾的 `cdc_empty` 同时要求 data 和 ARF/CSR 两个队列为空；Rocket 又要求该信号连续两拍有效，覆盖 `R_LSL` 的一拍入队寄存器延迟，避免队列刚排空而 payload 尚未写入本地 FIFO 时误报整包完成。

== 包级 pass/fail/cancelled

Rocket 为当前包累计四类错误来源：重执行 load/store、ARF/FARF 比较和 CSR shadow 比较。整包完成或取消时输出：

```text
{ valid, status[1:0], seq[31:0] }

status = 0: pass
status = 1: fail
status = 2: cancelled
status = 3: 非法/保留
```

结果先进入 Rocket 本地深度 4 的 `Queue`，再通过 GHM 中每 checker 独立、深度 256 的 `AsyncQueue` 回到 BOOM 时钟域。Rocket 侧 `valid` 保持到 `ready`，因此 GHM 队列满时会形成反压。当前实现还用断言检查本地结果队列不能溢出；BOOM DCache则对无法接纳或语义非法的结果做计数并使统计无效。

结果通道的关键 valid/ready 信号是：

```scala
// Rocket 本地
package_result_queue.io.enq.valid := package_result_event
package_result_queue.io.enq.bits := Cat(package_result_status, package_seq_reg)
package_result_queue.io.deq.ready := io.package_result_ready
io.package_result_valid := package_result_queue.io.deq.valid

// RocketTile 打包 valid/status/seq
outer.checker_result_SRNode.bundle := Cat(
  core.io.package_result_valid,
  core.io.package_result_status,
  core.io.package_result_seq)

// GHM checker -> BOOM AsyncQueue
u_result_cdc(i).io.enq.valid :=
  io.checker_result_in(i)(GH_GlobalParams.GH_CHECKER_RESULT_BITS - 1)
u_result_cdc(i).io.enq.bits :=
  io.checker_result_in(i)(resultPayloadBits - 1, 0)
io.checker_result_ready(i) := u_result_cdc(i).io.enq.ready
io.checker_results_out(i) := Mux(u_result_cdc(i).io.deq.fire,
  Cat(true.B, u_result_cdc(i).io.deq.bits), 0.U)
```

GHM 的结果队列在 BOOM 侧 `deq.ready := true.B`，所以 `io.checker_results(i)` 是一个仅在 `deq.fire` 当拍携带 `valid=1` 的结果脉冲，而不是需要 DCache 再次拉 ready 的 Decoupled 接口。

= 完成位图与校验安全水位

== 为什么结果到达不等于全局安全

四个 checker 可以乱序完成。假设包 11 已通过，但包 10 仍未完成，那么不能据此宣布 11 及其之前的数据整体安全。BOOM DCache用连续通过水位表达“截至哪个包序号，所有已分配包均已完成且通过”。

位图窗口固定为 256 项，每项保存：

- `bitmapAllocated`：本测量窗口已分配此包。
- `bitmapCompleted`：已经接收合法的整包结果。
- `bitmapPassed`：结果为 pass。
- `bitmapSeq`：完整 32 位序号，用于验证低 8 位索引没有混叠。

包 $s$ 的槽位为 `s[7:0]`，但命中条件同时比较完整序号。若目标槽仍被另一个未退休序号占用，则记为 allocation collision，而不是覆盖旧状态。

位图的写入口信号为：

```scala
val measuredPacketAlloc = io.packet_alloc_valid && trafficCounting
val allocIdx = io.packet_alloc_seq(7, 0)

// checker_results(i) 位域
val valid  = result(GH_CHECKER_RESULT_BITS - 1)
val status = result(GH_PACKET_SEQ_BITS + GH_CHECKER_STATUS_BITS - 1,
                    GH_PACKET_SEQ_BITS)
val seq    = result(GH_PACKET_SEQ_BITS - 1, 0)
val idx    = seq(7, 0)
```

分配时写 `bitmapAllocated/Completed/Passed/Seq`；结果返回时只有 `resultAccepted(i)` 为真才写 completed/pass。关键接纳条件包括：valid、非基线前 stale 结果、状态不是保留值 3、`seq != 0`、位图中确有相同完整序号、尚未完成且同周期没有另一 checker 重复返回同一序号。

```scala
resultAccepted(i) := valid && !resultStale(i) && statusKnown &&
  seq =/= 0.U &&
  ((bitmapAllocated(idx) && bitmapSeq(idx) === seq) ||
    allocatedThisCycle) &&
  !bitmapCompleted(idx) && !duplicateThisCycle
```

== 安全水位推进

每周期先把同周期的新分配和 checker 结果合入临时视图，再从旧水位 $W$ 开始检查：

```text
W+1 allocated && completed && passed ? 继续
W+2 allocated && completed && passed ? 继续
...
遇到第一个空洞、未完成、fail 或 cancelled -> 停止
```

最长可在一周期内前看 256 项，并得到 `newSafePacketWatermark`。已被水位覆盖的位图槽随后释放。写回分类使用 `newSafePacketWatermark`，因此 checker 结果与写回同周期出现时，刚好使水位越过该包的结果会参与当拍分类，不会把已经安全的写回误记为未校验。

推进网络的核心信号是：

```scala
val slotPass = allocatedNext(idx) && seqNext(idx) === seq &&
  completedNext(idx) && passedNext(idx)
contiguous = contiguous && slotPass
safeAdvance = Mux(contiguous, offset.U, safeAdvance)
val newSafePacketWatermark = safePacketWatermark + safeAdvance
```

这里使用 `allocatedNext/completedNext/passedNext/seqNext`，而不是上一周期寄存器值，正是为了让当拍 `resultAccepted` 立即参与 `slotPass`。最后 `safePacketWatermark := newSafePacketWatermark`，并清除所有 `seqNext(i) <= newSafePacketWatermark` 的已退休槽。

例如旧水位为 100，包 102 先完成时水位仍为 100；包 101 后到并通过的同一周期，临时位图显示 101、102 连续通过，水位可直接推进到 102。该周期属于包 102 的脏写回按“已校验”分类。

== 测量边界

RESET 时，安全水位和 `measurementSeqFloor` 设为当时 `active_packet_seq`。小于等于该基线的迟到结果视为 stale，不污染新一轮统计。若 RESET 发生时大核正处于校验状态、位图仍有活动项，或已有安全水位与基线不一致，则新窗口立即标记无效。这要求软件尽量在没有跨窗口在途包的边界启动测量。

= 从 BOOM Core 到 L2 的脏写回数据线路

这一部分按一次 store 从 BOOM 提交到 L1D 脏行离开的顺序说明。实现中始终存在两条并行但用途不同的线路：

- *原有数据线路*传递 store 地址和数据，最终从 L1D data array 读出整条 cache line，经 WritebackUnit 发送到 TileLink C 通道。
- *新增归属线路*传递 32 位 `packet_seq`，在每个 set × way 的旁表中记录当前脏数据需要等待的包。它不进入 cache-line data，也不作为 TileLink 字段发送给 L2。

两条线路在 L1D 真正写入时建立对应关系，在 WritebackUnit 接受 victim 时一同锁存，在 C 通道首 beat 被接受时共同用于统计。校验安全水位是第三条只服务于分类的控制线路，不参与数据传输。

```text
[原有地址/数据主线]
BOOM store addr/data
  -> STQ addr/data
  -> dmem_req.addr/data
  -> DCache s0_req -> s1_req -> s2_req
       |-- hit -------------------------------> s3_req
       `-- miss -> MSHR + refill -> RPQ replay -> s3_req
  -> dataWriteArb.in(0).fire
  -> L1D data array(set, way)
  -> victim: MSHR.wb_req 或 TL B -> prober.wb_req
  -> wbArb -> WritebackUnit io.req.fire
  -> wb.io.data_req -> L1D data array -> wb.io.data_resp
  -> wb_buffer -> ReleaseData/ProbeAckData -> wb.io.release
  -> tl_out.c 首 beat fire -> L2

[新增 32 位包序号旁带]
R_IC allocated_packet_seq
  -> BOOM Core io.lsu.active_packet_seq
  -> STQEntry.packet_seq
  -> BoomDCacheReq.packet_seq
  -> DCache hit 或 MSHR/RPQ replay
  -> s3_req.packet_seq
  -> dataWriteArb.in(0).fire 时写 dirtyPacketSeq/Tracked(set, way)
  -> wbArb 选中 victim 后查旁表
  -> WritebackUnit io.req.fire 时锁存 active_packet_seq/tracked
  -> tl_out.c 首 beat分类（不发送给 L2）

[校验安全控制线]
checker result -> 完成位图 -> newSafePacketWatermark
                                |
tl_out.c 首 beat + active_packet_seq/tracked
                                -> verified/unverified/untracked
                                -> 未校验桶与延迟统计
```

== 第一级：BOOM Core 给提交 store 提供包序号

包序号起源于 BOOM Core 内的 `R_IC`。全局参数 `GH_PACKET_SEQ_BITS = 32` 规定所有包序号字段宽度为 32 位；值 0 保留为“当前操作没有受检包归属”，有效包从非零序号开始。

`R_IC` 接受一份新快照时增加 `packet_seq_counter`，并输出 `packet_alloc_valid` 和 `packet_alloc_seq`。BOOM Core 新增了下面三项输出，其中前两项还送到 DCache 完成位图：

#table(
  columns: (2.3fr, 1.1fr, 3.7fr),
  inset: 4.5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*新增信号*], [*宽度*], [*含义与作用*]),
  [`io.packet_alloc_valid`], [1 bit], [新包分配脉冲，使完成位图在同拍为该序号建立槽位。],
  [`io.packet_alloc_seq`], [32 bit], [本次新分配包的序号；包边界当拍优先使用它，避免 store 被标到上一包。],
  [`io.active_packet_seq`], [32 bit], [`R_IC` 当前活动包序号，供 tile 建立 RESET 基线等用途。],
)

BOOM Core 到 LSU 的新增输入是 `LSUCoreIO.active_packet_seq: UInt(32.W)`。其选择规则为：新包分配当拍使用 `packet_alloc_seq`；其余校验执行期间使用 `active_packet_seq`；不在受检包内时置 0。

```scala
io.lsu.active_packet_seq := Mux(ic_master.io.packet_alloc_valid,
  ic_master.io.packet_alloc_seq,
  Mux(ic_master.io.debug_maincore_status === 2.U,
    ic_master.io.active_packet_seq, 0.U))
```

这里的修改只生成 store 的归属标签，不改变 store 的地址、数据或提交条件。

== 第二级：STQ 在提交时固定 store 的归属

原有 BOOM store 数据先进入 Store Queue。为防止包状态在“ROB 提交”和“DCache 真正写入”之间变化，`STQEntry` 新增 `packet_seq: UInt(32.W)`，并在 `commit_store` 成立时锁存当拍 `io.core.active_packet_seq`：

```scala
when (commit_store) {
  stq(idx).bits.committed := true.B
  stq(idx).bits.packet_seq := io.core.active_packet_seq
}
```

STQ entry 新分配、flush、回收和复用时会把该字段清零，防止旧 entry 的序号泄漏到下一条 store。STQ 向 DCache 发请求的 `will_fire_store_commit` 分支继续传递原有 `addr`、`data` 和 `uop`，同时把新增字段送入 `BoomDCacheReq`：

```scala
dmem_req(w).bits.packet_seq := stq_commit_e.bits.packet_seq
```

#table(
  columns: (2.2fr, 1.15fr, 3.75fr),
  inset: 4.5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*字段*], [*性质*], [*在线路中的作用*]),
  [`STQEntry.addr/data/uop`], [原有], [描述实际 store 地址、数据和操作类型。],
  [`STQEntry.packet_seq`], [新增], [在提交点固定该 store 所属包，之后不再依赖实时 `R_IC` 状态。],
  [`BoomDCacheReq.packet_seq`], [新增], [让序号像请求的旁带标签一样穿过 DCache hit、miss 和 replay 路径。],
)

因此，包归属的定义点是 `commit_store`，而缓存行归属的生效点仍是后面的 data array 写入成功；提交但最终尚未写入 L1D 的请求不会提前改变缓存行状态。

== 第三级：DCache hit、miss 与 replay 都保留序号

`BoomDCacheReq.packet_seq` 随请求从 `s0_req` 寄存到 `s1_req`、`s2_req`。L1 hit store 进入 `s3_req` 后等待 pipeline 数据写端口；若 miss，则序号必须穿过 MSHR 和 replay 队列，不能在 refill 后丢失。

```text
BoomDCacheReq.packet_seq
  |-- L1 hit -> s1_req -> s2_req -> s3_req
  |
  `-- L1 miss -> BoomDCacheReqInternal
                  -> MSHR 的 RPQ entry
                  -> mshrs.io.replay.bits.packet_seq
                  -> replay_req.packet_seq
                  -> s1_req -> s2_req -> s3_req
```

`BoomDCacheReqInternal` 继承新增的 `packet_seq`。`rpq.io.enq.bits := io.req` 使每条 primary/secondary miss 请求都保留自己的完整序号；同一 MSHR 合并 secondary miss 时，MSHR 摘要请求的 `req.packet_seq` 更新为较大值，但每个 RPQ entry 仍保存各自序号。最终 replay 使用：

```scala
replay_req(0).packet_seq := mshrs.io.replay.bits.packet_seq
```

这一修改解决的是 replay store 在很晚才真正写入 L1D 时仍能使用其原始提交包，而不是错误读取当时正在执行的新包。prefetch、tracegen 及不属于受检包的请求把 `packet_seq` 置 0。

== 第四级：data array 写入时建立缓存行归属

DCache 原有 `dataWriteArb` 有两个输入：`in(0)` 是 pipeline store/成功 SC/AMO 的写入，`in(1)` 是 MSHR refill。实现没有扩大 data array 的 cache-line 数据格式，而是新增与物理 set × way 一一对应的两个寄存器旁表：

#table(
  columns: (2.45fr, 1.35fr, 3.25fr),
  inset: 4.5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*新增状态*], [*组织和宽度*], [*含义与作用*]),
  [`dirtyPacketSeq(set)(way)`], [`nSets × nWays × 32 bit`], [当前缓存行需要等待的最大受检包序号。],
  [`dirtyPacketTracked(set)(way)`], [`nSets × nWays × 1 bit`], [上述序号是否有效；为 false 时该行不能按水位判定。],
  [`s3_way`], [`nWays bit`], [显式定宽的一位有效 way 寄存器，既选择 data array way，也安全地供 `OHToUInt` 查询旁表。],
)

`dataWriteArb.io.in(0).fire` 是 store 数据真正被 data array 接受的时刻。只有这一拍才用同一个 `set`、`way` 更新归属旁表，因此实际 cache-line data 与包归属不会在 nack 或尚未完成的 miss 上提前建立关联。

```text
受检写入，s3_req.packet_seq != 0:
  dirtyPacketSeq = max(旧 dirtyPacketSeq, s3_req.packet_seq)
  dirtyPacketTracked = true

未跟踪写入，s3_req.packet_seq == 0:
  dirtyPacketSeq = 0
  dirtyPacketTracked = false

refill 写入，dataWriteArb.io.in(1).fire:
  dirtyPacketSeq = 0
  dirtyPacketTracked = false
```

取最大序号使一行被多个受检包脏化后，必须等最后一个相关包也进入安全水位才算已校验。序号单调分配，因此这里的最大序号就是最晚的受检包依赖。后续未跟踪写入会清除旧归属，因为当前数据已不再能完全归因于旧受检包。refill 则开启新的 set/way 生命周期，必须清除 victim 遗留信息。

同一物理地址被淘汰后再次换入属于新的缓存行生命周期；之后再次变脏并写回时重新计数。统计单位是行级写回事件，不按物理地址去重。

== 第五级：replacement 和 Probe 产生 victim 请求

缓存行离开 L1D 有两个入口，它们都使用原有 `WritebackReq` 描述 victim 的物理位置和 coherence 行为：

#table(
  columns: (1.25fr, 2.3fr, 3.5fr),
  inset: 4.5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*来源*], [*原有数据线路*], [*触发和字段含义*]),
  [replacement], [`mshrs.io.wb_req`], [旧 metadata 使 `req_needs_wb` 成立后，MSHR 进入 `s_wb_req`；`tag/idx/way_en` 定位 victim，`voluntary=true` 表示主动 Release。],
  [coherence Probe], [`tl_out.b -> prober.io.wb_req`], [Probe 要求 dirty victim 返回数据时，prober 给出同样的 `tag/idx/way_en`；`voluntary=false` 表示 ProbeAck 路径。],
)

两路请求在 `wbArb` 汇合，input 0 是 prober，input 1 是 MSHR：

```scala
wbArb.io.in(0) <> prober.io.wb_req
wbArb.io.in(1) <> mshrs.io.wb_req
wb.io.req       <> wbArb.io.out
```

包序号没有塞入原有 `WritebackReq`。DCache 使用仲裁后请求的 `idx` 和一位有效 `way_en` 同步查询归属旁表，并通过新增的 WritebackUnit 输入与 victim 请求并行送入：

```scala
val wbReqSet = wbArb.io.out.bits.idx
val wbReqWay = OHToUInt(wbArb.io.out.bits.way_en)
wb.io.packet_seq := dirtyPacketSeq(wbReqSet)(wbReqWay)
wb.io.packet_tracked := dirtyPacketTracked(wbReqSet)(wbReqWay)
```

新增输入 `wb.io.packet_seq: UInt(32.W)` 携带 victim 的包归属，`wb.io.packet_tracked: Bool` 表示该归属是否有效。查询使用仲裁后的同一个 `WritebackReq`，从而不会把一个来源的 set/way 与另一个来源的序号组合起来。

`WritebackReq` 本身仍然是原有请求格式，字段含义如下：

#table(
  columns: (1.35fr, 2.1fr, 3.6fr),
  inset: 4.5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*字段*], [*来源/用途*], [*含义*]),
  [`tag`], [MSHR 或 prober], [victim 的 tag，和 `idx` 一起重建 cache-line 地址。],
  [`idx`], [MSHR 或 prober], [victim 所在 set；也是旁表查询的 `set` 索引。],
  [`way_en`], [MSHR 或 prober], [victim 所在 way 的 one-hot 选择；转换为 `wbReqWay` 查询旁表和 data array。],
  [`param`], [coherence 状态机], [Release 或 ProbeAck 使用的权限收缩/报告参数，不参与包分类。],
  [`source`], [MSHR/Probe 源编号], [TileLink D/E 握手所需的事务来源编号，不参与包分类。],
  [`voluntary`], [MSHR=true，Probe=false], [选择主动 `Release(Data)` 还是 Probe `ProbeAck(Data)`；dirty 判定最终仍以 C opcode 为准。],
)

== 第六级：WritebackUnit 锁存旁带并读取真正数据

`wb.io.req.fire` 是 WritebackUnit 接受一条 victim 请求的唯一锁存点。模块在该拍同时锁存原有 `WritebackReq` 和新增 `{packet_seq, packet_tracked}`：

```scala
when (io.req.fire) {
  req := io.req.bits
  packet_seq := io.packet_seq
  packet_tracked := io.packet_tracked
}
io.active_packet_seq := packet_seq
io.active_packet_tracked := packet_tracked
```

#table(
  columns: (2.35fr, 1.2fr, 3.45fr),
  inset: 4.5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*新增接口*], [*方向/宽度*], [*作用*]),
  [`io.packet_seq`], [输入 32 bit], [`io.req.fire` 当拍提供被选 victim 的包序号。],
  [`io.packet_tracked`], [输入 1 bit], [说明输入序号是否具有有效行归属。],
  [`io.active_packet_seq`], [输出 32 bit], [输出锁存寄存器，在多 beat C 消息期间保持不变，供 DCache 统计。],
  [`io.active_packet_tracked`], [输出 1 bit], [与活动序号配套的稳定有效位。],
)

真正的 cache-line data 仍走原有线路：WritebackUnit 用锁存的 `req.idx`、`req.way_en` 发出 `io.data_req`；DCache 的 `dataReadArb.io.in(1)` 读取 data array，结果经 `s2_data_muxed(0)` 返回 `io.data_resp`，逐行填入 `wb_buffer`。随后根据 `req.voluntary` 组装 `ReleaseData` 或 `ProbeAckData`，由 `wb.io.release` 送往 TileLink C。

```text
req.idx + req.way_en
  -> wb.io.data_req
  -> dataReadArb.in(1)
  -> L1D data array
  -> s2_data_muxed(0)
  -> wb.io.data_resp
  -> wb_buffer
  -> ReleaseData / ProbeAckData
  -> wb.io.release
```

`packet_seq` 和 `packet_tracked` 只保存在 WritebackUnit 自己的寄存器中，不写入 `wb_buffer`，也不会出现在 TileLink C 的 data、address、source 或 user 字段中。锁存的目的，是防止 WritebackUnit 读取数据和等待 C 通道反压期间，原 set/way 被 refill 或其他 store 改写后改变在途写回的统计归属。

== 第七级：TileLink C 首 beat 是行级统计点

`wb.io.release` 与无需读取脏数据的 `prober.io.rep` 经 `TLArbiter` 汇入 `tl_out.c`。实现利用 TileLink edge beat counter，只在一条 C 消息的首 beat 真正握手时计数：

```scala
TLArbiter.lowest(edge, tl_out.c, wb.io.release, prober.io.rep)
val (c_first, _, _, _) = edge.count(tl_out.c)
val l1_l2_wb_event = tl_out.c.fire && c_first
val l1_l2_wb_dirty_event = l1_l2_wb_event &&
  tl_out.c.bits.opcode.isOneOf(
    TLMessages.ReleaseData, TLMessages.ProbeAckData)
```

`tl_out.c.fire` 等价于 `valid && ready`，表示 L2 方向已接受该 beat；`c_first` 使多 beat data 消息只计一次。各 opcode 的统计含义为：

#table(
  columns: (1.45fr, 2.5fr, 3.05fr),
  inset: 4.5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*计数*], [*包含的 C opcode*], [*含义*]),
  [`total`], [`Release/ReleaseData/ProbeAck/ProbeAckData`], [广义的 L1D 行级 C 消息数。],
  [`dirty`], [`ReleaseData/ProbeAckData`], [携带 cache-line data 的脏写回数。],
)

这里采用 C 首 beat，而不是 `wb.io.req.fire` 计数，是为了把“发生写回”定义为消息已进入 L2 接口；WritebackUnit 内部等待或被 C 通道反压时不会提前统计。

== 第八级：包归属与安全水位完成脏写回分类

C 首 beat 当拍，数据线路给出 `l1_l2_wb_dirty_event`，WritebackUnit 归属线路给出稳定的 `active_packet_seq/tracked`，完成位图线路给出已经合入当拍 checker 结果的 `newSafePacketWatermark`。三者在同一个 BOOM 周期汇合：

```text
l1_l2_wb_dirty_event --------+
active_packet_seq/tracked ---+-> verified / unverified / untracked
newSafePacketWatermark ------+
trafficCounting -------------+
```

#table(
  columns: (1.5fr, 2.8fr, 2.7fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*类别*], [*首 beat 当拍条件*], [*含义*]),
  [`verified`], [`tracked && seq != 0 && seq <= newWatermark`], [产生当前脏数据所依赖的包已经被连续 pass 水位覆盖。],
  [`unverified`], [`tracked && seq != 0 && seq > newWatermark`], [写回时该包尚未安全；同时尝试进入延迟桶。],
  [`untracked`], [`!tracked`], [当前行没有有效受检包归属，不能强行判为已校验或未校验。],
)

对应的关键脉冲是 `verifiedDirtyWb`、`unverifiedDirtyWb` 和 `untrackedDirtyWb`，都还受测量窗口信号 `trafficCounting` 限制。`verified + unverified + untracked` 应覆盖窗口内所有脏写回；`unverifiedDirtyWbSeen` 在事件当拍增加，之后包变安全也不会把历史分类改成 `verified`。

包序号负责“是否已经校验”的正确性判断，CSR cycle 不参与分类。`newSafePacketWatermark` 也不进入 WritebackUnit，不影响写回仲裁、数据读取或 C 通道发送；本实现只观测，不阻塞任何写回。

== 第九级：未校验样本按包序号进入 256 个桶

未校验写回发生时尚不知道未来的安全时刻，所以 DCache 用包序号建立等待桶。局部参数 `statsWindow = 256` 同时规定完成位图和写回桶的槽数，`statsIndexBits = log2Ceil(statsWindow) = 8` 规定用序号低 8 位索引。每个桶仍保存完整 32 位序号以检查低位混叠。

#table(
  columns: (2.55fr, 1.2fr, 3.25fr),
  inset: 4.5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*新增桶状态*], [*宽度*], [*含义*]),
  [`bucketValid(i)`], [1 bit], [槽中是否有尚未解决的包。],
  [`bucketSeq(i)`], [32 bit], [完整包序号，用于确认低 8 位索引没有混叠。],
  [`bucketCount(i)`], [64 bit], [该包已发生的未校验脏写回次数。],
  [`bucketWritebackCycleSum(i)`], [64 bit], [这些写回在 C 首 beat 处采样的 BOOM CSR cycle 之和。],
)

```scala
val wbBucketIdx = wb.io.active_packet_seq(statsIndexBits - 1, 0)
val wbBucketAvailable = !bucketValid(wbBucketIdx) ||
  bucketResolve(wbBucketIdx) ||
  bucketSeq(wbBucketIdx) === wb.io.active_packet_seq
val wbBucketAccepted = unverifiedDirtyWb && wbBucketAvailable
val wbBucketDropped = unverifiedDirtyWb && !wbBucketAvailable
```

同一包的多个写回在一个桶内聚合，每次 `wbBucketAccepted` 都将 `io.csr_cycle` 加入 `bucketWritebackCycleSum`。空槽或同周期正被解决的槽建立新桶；若低 8 位相同但完整序号不同，硬件不能覆盖旧桶，会令 `wbBucketDropped` 成立、增加 dropped 计数并把 `statsValid` 置 false。

`unverifiedDirtyWbSeen` 记录所有事件，`pending` 只记录成功进入桶的样本，`dropped` 单独暴露容量或混叠问题。因此即使桶不足，分类总数仍可核对，但延迟平均值必须判为无效。

== 第十级：安全水位解决桶并形成延迟

当 `newSafePacketWatermark >= bucketSeq(i)` 时，`bucketResolve(i)` 成立。该周期的 `io.csr_cycle` 是 BOOM 侧的校验安全时刻：checker 整包结果已经跨过 CDC、到达 DCache 位图，并实际推进连续通过水位。

```scala
bucketResolve(i) := bucketValid(i) &&
  bucketSeq(i) <= newSafePacketWatermark

resolvedThisCycle = sum_i(Mux(bucketResolve(i), bucketCount(i), 0.U))
writebackCyclesResolvedThisCycle =
  sum_i(Mux(bucketResolve(i), bucketWritebackCycleSum(i), 0.U))
safeCyclesResolvedThisCycle =
  sum_i(Mux(bucketResolve(i), io.csr_cycle * bucketCount(i), 0.U))
```

若一个桶含 $k$ 次写回，写回周期为 $C_1 ... C_k$，安全水位在周期 $C_("safe")$ 覆盖该包，则硬件累加：

$ S_("safe") := S_("safe") + k times C_("safe") $

$ S_("wb") := S_("wb") + sum_(j=1)^k C_j $

$ N_("resolved") := N_("resolved") + k $

软件据此计算：

$ S_("latency") = S_("safe") - S_("wb") $

$ L_("avg","cycles") = S_("latency") / N_("resolved") $

$ L_("avg","ns") = (S_("latency") times 10^9) / (f_("BOOM") times N_("resolved")) $

写回周期和安全周期都来自同一个 BOOM CSR `cycle`，不需要 Rocket/BOOM 跨频率换算。安全时间采用水位实际推进时刻，而不是某个高序号包结果单独到达的时刻；低序号空洞未补齐前，高序号包即使已经完成也还不能被视为全局安全。

缓存行旁表和 WritebackUnit 都不保存 CSR 时间戳。时间只在 C 首 beat 写入桶时采样一次，并在 `bucketResolve` 时再次采样；这使“数据归属”和“延迟测量”职责分离。

== 写回线路新增信号和参数速查

#table(
  columns: (2.55fr, 1.1fr, 3.35fr),
  inset: 4.5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*名称*], [*位置/宽度*], [*作用*]),
  [`GH_PACKET_SEQ_BITS = 32`], [全局参数], [统一 R_IC、STQ、DCache、位图和桶的包序号宽度；0 表示无归属。],
  [`GH_CHECKER_RESULT_BITS = 35`], [全局参数], [checker 返回 `{valid[34], status[33:32], seq[31:0]}`，供完成位图生成安全水位。],
  [`GH_PERF_CTRL_BITS = 7`], [全局参数], [保证 RESET、START、STOP 控制位穿过 GHE、RoCC router、tile 和 core 时不被截断。],
  [`statsWindow = 256`], [DCache 参数], [完成位图与未校验写回桶的槽数；要求未完成包跨度小于该窗口。],
  [`statsIndexBits = 8`], [DCache 参数], [从 32 位序号提取桶/位图索引，完整序号负责防混叠。],
  [`LSUCoreIO.active_packet_seq`], [输入 32 bit], [把 BOOM Core 当前提交包送入 LSU。],
  [`STQEntry.packet_seq`], [字段 32 bit], [在 store 提交时固定包归属。],
  [`BoomDCacheReq.packet_seq`], [字段 32 bit], [使归属穿过 DCache pipeline、MSHR、RPQ 和 replay。],
  [`dirtyPacketSeq/Tracked`], [set × way 旁表], [记录当前 cache line 的受检脏化归属，不改变 data array 格式。],
  [`wb.io.packet_seq/tracked`], [新增输入], [与 `WritebackReq` 同拍送入 WritebackUnit。],
  [`wb.io.active_packet_seq/tracked`], [新增输出], [在途写回期间输出锁存归属，供 C 首 beat 分类。],
  [`newSafePacketWatermark`], [BOOM 32 bit], [合入当拍 checker 结果后的连续 pass 水位。],
  [`trafficCounting`], [BOOM 1 bit], [RESET/START/STOP 解码后的实际窗口使能；只门控统计，不门控写回。],
  [`l1_l2_wb_event/dirty_event`], [BOOM 脉冲], [C 首 beat行级总事件，以及其中携带 data 的脏写回事件。],
  [`verified/unverified/untracked`], [BOOM 脉冲], [用锁存行归属与当拍新水位给脏写回分类。],
  [`bucketValid/Seq/Count/CycleSum`], [256 个桶], [保存尚未变安全的写回次数和 BOOM 写回周期和。],
  [`io.csr_cycle`], [BOOM 64 bit], [在 C 首 beat 和水位解决桶时分别提供写回时刻与安全时刻。],
)

= L2→DRAM 窗口统计

共享 InclusiveCache 的每个 bank 在 `SourceC.req.fire()` 对 DCache 来源 victim 计一次。目录中的 sticky `dcache` provenance 排除 ICache-only resident line，`dirty` 位区分 clean/dirty victim。每 bank 保存 64 位 clean、dirty 二进制计数，再转换成 Gray code，通过 `BoringUtils` 和三级同步器进入 BOOM 时钟域，最后转回二进制并跨 bank 求和。

L2 bank 内的行级事件信号是：

```scala
io.dcacheWriteback := sourceC.io.req.fire() &&
  sourceC.io.req.bits.dcache
io.dcacheWritebackDirty := io.dcacheWriteback &&
  sourceC.io.req.bits.dirty

when (writeback && !dirty) { cleanCount := cleanCount + 1.U }
when (writeback && dirty)  { dirtyCount := dirtyCount + 1.U }
cleanGray := cleanCount ^ (cleanCount >> 1)
dirtyGray := dirtyCount ^ (dirtyCount >> 1)
```

`sourceC.io.req.fire()` 是 Scheduler 向 SourceC 交付一条 victim request 的握手，不是 SourceC 后续的 C 通道 data beat。`sourceC.io.req.bits.dcache` 来自目录 provenance，`sourceC.io.req.bits.dirty` 来自 victim metadata。

START 保存同步后计数的基线，STOP 上升沿保存终点减基线：

```text
l2_dram_wb_total = sum_banks(clean_delta + dirty_delta)
l2_dram_wb_dirty = sum_banks(dirty_delta)
```

clean victim 不携带数据写入 DRAM，dirty victim 才经 CacheCork 转换为向下游的 `PutFullData`。所以 total 更准确地表示“以 DRAM 为下一级的 DCache 来源 L2 victim 总数”，dirty 才对应携带数据的写出。

当前未把 BOOM 包序号继续传播到共享 L2，也没有在 L2 建位图/桶。因此 L2→DRAM 尚不能区分 verified、unverified、untracked，更不能计算未校验脏写回延迟。本轮只为它补齐与 START/STOP 一致的测量窗口。

跨域和快照侧的关键硬件信号是 `cleanGray/dirtyGray`、`AsyncResetSynchronizerShiftReg(..., sync=3)`、`l2DramWbClean/Dirty`、`l2DramWbClean/DirtyBase`、`perfStopPulse` 和 `l2DramWbClean/DirtySnapshot`。STOP 当拍执行：

```scala
l2DramWbCleanSnapshot := l2DramWbClean - l2DramWbCleanBase
l2DramWbDirtySnapshot := l2DramWbDirty - l2DramWbDirtyBase
```

= 35 项 GHE 读出协议

硬件和 `Software/Test/ghe.h` 的向量长度统一为 35。hart 0 返回 BOOM DCache 和共享 L2 指标；Rocket 的 13--16、18--34 固定为 0，索引 17 则由每个 hart 各自返回。

#table(
  columns: (0.7fr, 2.8fr, 3.5fr),
  inset: 4.5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*索引*], [*软件名称*], [*含义*]),
  [`0--12`], [基础 store/load/LR/SC/AMO], [保留原有完成口径的访存分类统计。],
  [`13`], [`L1_L2_WB_TOTAL`], [BOOM DCache C 通道行级总数。],
  [`14`], [`L1_L2_WB_DIRTY`], [其中 `ReleaseData/ProbeAckData` 数量。],
  [`15`], [`L2_DRAM_WB_TOTAL`], [测量窗口内 DCache 来源 L2 victim 总数。],
  [`16`], [`L2_DRAM_WB_DIRTY`], [其中 dirty victim 数量。],
  [`17`], [`STORE_UNCACHE_CYCLE_SUM`], [本 hart 的不可缓存 STORE 时间戳周期和。],
  [`18`], [`UNVERIFIED_DIRTY_WB_SEEN`], [写回当时高于安全水位的脏写回总数。],
  [`19`], [`..._RESOLVED`], [后来已被安全水位解决的样本数。],
  [`20`], [`..._PENDING`], [仍留在桶中等待水位的样本数。],
  [`21`], [`..._DROPPED`], [桶冲突而无法保存的样本数。],
  [`22`], [`FAILED_PACKAGES`], [接收到 fail 的包数。],
  [`23`], [`..._SAFE_CYCLE_SUM`], [每个 resolved 样本对应安全周期之和。],
  [`24`], [`..._WB_CYCLE_SUM`], [这些样本的写回周期之和。],
  [`25`], [`..._STATS_VALID`], [硬件综合有效位。],
  [`26`], [`SAFE_PACKET_WATERMARK`], [连续完成且通过的最大包序号。],
  [`27`], [`PACKAGE_RESULT_DROPPED`], [位图冲突、非法或无法接纳结果等诊断。],
  [`28`], [`VERIFIED_DIRTY_WB`], [写回当拍已不高于水位的 tracked 脏写回。],
  [`29`], [`UNTRACKED_DIRTY_WB`], [没有有效包归属的脏写回。],
  [`30`], [`ALLOCATED_PACKAGES`], [窗口内登记的包分配数。],
  [`31`], [`COMPLETED_PACKAGES`], [位图接受的整包结果数。],
  [`32`], [`PASSED_PACKAGES`], [其中 pass 的包数。],
  [`33`], [`CANCELLED_PACKAGES`], [其中 cancelled 的包数。],
  [`34`], [`STATS_ARITHMETIC_OVERFLOW`], [桶、乘法、求和或 pending 账目异常次数。],
)

GHE 的 `funct=0x7B` 根据 `rs1` 返回对应 64 位元素，越界索引返回 0。STOP 上升沿之后，BOOM DCache 输出冻结向量；L2 用独立但同一控制脉冲的快照寄存器冻结窗口差值。这样 hart 0 后续执行 35 条 RoCC 读取及其内存写入，不会把读数过程本身产生的流量纳入已冻结窗口。

GHE 读出和 DCache 快照选择的关键组合为：

```scala
val doGetTrafficCounter = cmd.fire && funct === 0x7B.U
rd_val := Mux(doGetTrafficCounter,
  Mux(rs1_val < GH_TRAFFIC_COUNTERS.U,
    io.traffic_counter_in(rs1_val), 0.U), ...)

when (trafficStopPulse) {
  trafficCounterSnapshot := trafficCounterLive
  trafficCounterSnapshotValid := true.B
}
io.traffic_counter := Mux(trafficCounterSnapshotValid,
  trafficCounterSnapshot, trafficCounterLive)
```

RoCC 的 `cmd.fire` 保证命令已经被 GHE 接受；`rs1_val` 是软件枚举索引。hart 0 的 `trafficCounter` 先取 DCache 向量，再覆盖索引 15、16 为同步后的 L2 窗口值，最后送入 `cmdRouter.io.traffic_counter_in` 和 GHE。

= 软件收敛、打印与有效性判断

== 软件读取顺序

当前测试程序的流程是：

1. 大核与各 checker 分别执行 RESET、START。
2. 大核运行 workload 并分配校验包；各 checker 重执行和完成整包比较。
3. 每个 checker 退出工作循环后 STOP，读取自己的 35 项向量，写入 `hart_traffic[hart]`，执行内存屏障并置 ready。
4. hart 0 等待四个 ready，再轮询 BOOM 的 `allocated/completed`，直到相等；若 `package_result_dropped != 0` 则提前结束等待以便诊断。
5. hart 0 发 STOP，读取冻结的 BOOM/L2 35 项向量。
6. 软件打印基础流量、五个 `store_uncache` 时间和、脏写回分类、包生命周期诊断和两个平均延迟。

每个 checker 只写自己的二维数组行，避免并发覆盖；`__sync_synchronize()` 保证 ready 置位前计数值对 hart 0 可见。

== 未校验脏写回何时允许输出平均值

软件只有在以下条件全部满足时才计算平均延迟：

```text
stats_valid == 1
seen == resolved
pending == 0
dropped == 0
package_result_dropped == 0
arithmetic_overflow == 0
failed == 0
cancelled == 0
completed == allocated
passed == completed
safe_cycle_sum >= writeback_cycle_sum
resolved != 0
```

这些条件分别排除窗口/位图/桶冲突、仍未解决的样本、丢样本、结果协议异常、64 位硬件算术溢出、失败或取消包、包结果未收敛以及周期和下溢。软件仍使用 128 位中间量计算纳秒分子和分母。

需要区分“没有结果”和“无效结果”：`resolved == 0` 表示没有可报告的已解决未校验脏写回；其他诊断不满足则表示确实观察到测量不完整或协议条件不成立，软件拒绝用残缺样本给出平均数。

= 正确性不变量与实现边界

== 建议检查的不变量

当前实现预期满足：

```text
store_total = store_cache + store_uncache
l1_l2_wb_dirty <= l1_l2_wb_total
l2_dram_wb_dirty <= l2_dram_wb_total

unverified_seen = resolved + pending + dropped
  // 在没有 64 位回绕和同周期账目错误时

completed = passed + failed + cancelled
  // 在结果状态均合法且没有结果丢失时

verified + unverified_seen + untracked = l1_l2_wb_dirty
  // 对同一启停窗口内的 BOOM 脏 C 消息
```

软件实际输出平均值时使用了更严格的 `seen == resolved`、`completed == allocated` 和 `passed == completed`，意味着所有未校验样本都已经安全解决，且所有窗口内包都成功通过。

== 当前必须遵守的边界

- 当前只支持一个 BOOM 大核的统计所有权；四个 Rocket 作为 checker。
- 位图和写回桶均为 256 项。必须保证任一时刻未退休包的序号跨度小于 256，否则低位复用会触发冲突并使统计无效。
- 包序号为 32 位，普通运行不处理回绕附近的模序比较；所有 `<=`、`>` 和 `max` 都按普通无符号顺序解释。
- `store_uncache` 跨 hart 方法暂不校正本地 CSR 计数器起点、复位时刻和时钟相位；它是聚合近似值。
- Rocket 将同一包内所有不可缓存 STORE 统一标记为整包尾时间，因此不提供包内逐条检测延迟。
- 脏写回延迟只统计“写回发生当拍尚未校验”的样本，且安全终点是结果到达 BOOM 并推进水位的时刻，不是 Rocket 本地完成时刻。
- 缓存行保存最大受检脏化序号；任何后续未跟踪写入会清除归属。`untracked` 必须单独解释，不能当作已校验。
- 写回信息只是额外暂存。硬件不会为了等待校验而阻塞或延迟 TileLink C 写回。
- fail/cancelled 包不会推进 pass 水位；软件将本轮未校验延迟判为无效。
- 64 位硬件时间戳和计数器仍可能在超长测量中回绕。已检查显式加法和乘法溢出的位置会设置诊断，但基础计数器的自然回绕没有全面饱和保护。
- RESET/START/STOP 分别由各 hart 本地软件发出，不保证五个核在同一物理时刻打开窗口；跨核窗口边界仍依赖现有启动和退出协议。
- L2→DRAM 当前只有 total/dirty 窗口计数，没有包序号、verified/unverified/untracked 分类或延迟。

= 主要修改文件与职责

#table(
  columns: (2.8fr, 3.7fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*文件或模块*], [*本轮统计职责*]),
  [`GH_GlobalParams.scala`], [定义 32 位包序号、结果状态、7 位性能控制、35 项计数器索引和 L2 Gray counter bore 名称。],
  [`CSR.scala`], [导出 `reg_cycle`；补充 CSR shadow 是否需要检查、是否出错。],
  [`R_IC.scala`], [在 snapshot 接受点分配全局包序号，并记录目标 checker 的 segment id。],
  [`GHM.scala`], [让序号伴随数据/ARF 包跨域；用带反压的 AsyncQueue 把 checker 整包结果送回 BOOM。],
  [`RocketCore.scala`], [识别 checker 访存完成，合并 ARF/FARF 与 CSR 尾条件，生成 pass/fail/cancelled 整包结果。],
  [`R_ICSL.scala`], [按包暂存 Rocket `store_uncache` 数量，并在整包完成时累加 Rocket CSR 周期乘数量。],
  [`BOOM lsu.scala/mshrs.scala`], [在 STQ、DCache request、MSHR/replay 中传播包序号；在不可缓存 STORE 的 TL A 接受点形成完成脉冲。],
  [`BOOM dcache.scala`], [维护缓存行归属、WritebackUnit 锁存、位图、水位、写回桶、分类、时间和、诊断与 STOP 快照。],
  [`BOOM tile.scala`], [连接 BOOM CSR 周期、包分配和 checker 结果；同步并窗口化共享 L2 计数。],
  [`Core/BaseTile/RocketTile/HasTiles/LazyRoCC`], [扩展包序号、结果返回和 7 位性能控制在 tile/subsystem 间的接口。],
  [`Software/Test/ghe.h`], [定义控制命令、35 项枚举和 `funct=0x7B` 读接口。],
  [`Software/Test/test.c`], [等待收敛和冻结快照；频率换算、有效性检查与平均延迟打印。],
  [`Software/Test/checker.c/secondary.c`], [checker 启停本地计数，并把各 hart 的向量与 ready 状态写回共享内存。],
)

综上，当前实现使用包序号解决“是否已经校验”的离散正确性判断，使用完成位图把乱序 checker 结果整理为连续安全水位，使用 BOOM CSR 事件时间求未校验脏写回延迟；只有 `store_uncache` 因起点和终点天然位于不同 hart，才保留五个本地周期总和并在软件中按频率统一到时间。两种方法共享测量窗口和 GHE 读回框架，但不混用时间基准。
