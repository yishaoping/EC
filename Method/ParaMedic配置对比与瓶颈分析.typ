#set page(
  paper: "a4",
  margin: (x: 18mm, y: 17mm),
  numbering: "1 / 1",
)
#set text(lang: "zh", size: 10.5pt)
#set par(justify: true, leading: 0.72em)
#set heading(numbering: "1.1")
#show heading.where(level: 1): it => block(
  above: 1.25em,
  below: 0.7em,
  stroke: (bottom: 0.7pt + rgb("#455a64")),
  inset: (bottom: 0.25em),
)[#it]
#show heading.where(level: 2): it => block(above: 1em, below: 0.5em)[#it]
#show heading.where(level: 3): it => block(above: 0.8em, below: 0.35em)[#it]
#show raw.where(block: true): it => block(
  fill: rgb("#f5f7f8"),
  stroke: 0.5pt + rgb("#c7cdd1"),
  inset: 7pt,
  radius: 3pt,
  width: 100%,
)[#it]
= 现有 Chipyard 项目的配置情况

== 顶层配置、核数与时钟域

当前协同校验系统的直接入口是 `chipyard.v1Config`。它位于
`/home/gzh/EC/chipyard/generators/chipyard/src/main/scala/config/RocketConfigs.scala:9-28`。配置按 hart ID 固定了一个 BOOM 大核和四个 Rocket checker：hart 0 为大核，hart 1--4 为小核。核数不是在 `v1Config` 中写成字面量，而是由 `GH_GlobalParams` 提供；该对象位于
`/home/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala:4-16`。

#table(
  columns: (1.25fr, 1.45fr, 1.35fr, 3.15fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*对象*], [*当前值*], [*时钟*], [*位置与说明*]),
  [BOOM 大核], [1 个，hart 0], [200 MHz], [`RocketConfigs.scala:10,25`；`GH_NUM_BIG_CORES=1`。],
  [Rocket checker], [4 个，hart 1--4], [每核 100 MHz], [`RocketConfigs.scala:11-14,26`；总核数 `GH_NUM_CORES=5`。],
  [GBUS / GuardianCouncil], [校验聚合时钟域], [100 MHz], [`RocketConfigs.scala:15`；GBUS 主要提供 GAGG 时钟，不等同于校验 packet 数据通道。],
  [SBUS], [共享系统总线], [200 MHz], [`RocketConfigs.scala:16`。],
  [MBUS], [内存侧总线], [200 MHz], [`RocketConfigs.scala:17`，覆盖 `AbstractConfig` 的 100 MHz 默认值。],
  [PBUS], [外设总线], [200 MHz], [`RocketConfigs.scala:18`，覆盖 `AbstractConfig` 的 100 MHz 默认值。],
  [未显式指定的时钟], [继承 SBUS], [200 MHz], [`WithSystemBusFrequencyAsDefault`，见 `RocketConfigs.scala:19`。],
)

`v1Config` 还混入 `WithGHE` 和 `WithDisableROBDebug`。前者把 GHE 作为 custom1 RoCC 单元挂入系统，定义在
`generators/rocket-chip/src/main/scala/guardiancouncil/GH_Config.scala:9-15`；后者只关闭 ROB 调试输出，定义在同文件 `:17-19`，不会缩短校验流水本身。

Rocket checker 与 uncore 之间使用异步 crossing。`WithAsynchronousRocketTiles` 位于
`generators/rocket-chip/src/main/scala/subsystem/Configs.scala:536-542`，只匹配 `RocketTileAttachParams`，因此不会把 BOOM tile 改成异步 crossing。值得注意的是，该 mixin 虽然接收 `depth` 和 `sync` 两个形参，函数体却直接构造无参 `AsynchronousCrossing()`；当前调用传入的两个值并未真正作用到 crossing 参数。这是后续调节 CDC 深度时必须先修正的实现问题。

校验 packet 还有另一层独立 CDC。`GHM` 为每个 checker 建立宽度为 `136 bit × 2 packet`、深度 256、同步级数 2 的 `AsyncQueue`，代码位于
`generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala:107`；大核时钟写入、checker 时钟读出，连接位于同文件 `:133-156`。因此当前至少存在两类异步边界：Rocket tile 访问 SBUS 的 TileLink crossing，以及 GHM 在 200 MHz 大核域与 100 MHz checker 域之间的 packet/控制 CDC。

== GuardianCouncil 全局参数与校验粒度

#table(
  columns: (1.55fr, 1.05fr, 3.85fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*参数*], [*当前值*], [*实际含义*]),
  [`GH_NUM_CORES`], [`5`], [1 个 BOOM 加 4 个 checker；许多 `Vec`、路由与状态位宽在 elaboration 时据此展开。],
  [`GH_NUM_BIG_CORES`], [`1`], [大核数量，并决定 checker hart ID 的起始偏移。],
  [`GH_TOTAL_PACKETS`], [`2`], [BOOM 每拍最多从 `GH_BUF` 导出的校验 packet 数；影响 packet 总线宽度及 checker 侧多个日志通道。],
  [`GH_WIDITH_PERF`], [`64`], [基本数据宽度。],
  [`GH_WIDITH_PACKETS`], [`136 bit`], [由 `2 × 64 + 8` 得到，一条 packet 携带两份 64-bit 信息和 8-bit 类型/状态。],
  [`GH_TOTAL_INSTS`], [`3970`], [大核校验阈值；`generators/boom/src/main/scala/exu/core.scala:2050` 把它送给 `ic_master.io.ic_threshold`。],
  [`IF_THERE_IS_CDC`], [`true`], [启用跨时钟域路径。],
  [`GH_CHECKER_MASK_WIDTH`], [`16`], [运行时 checker 使能掩码上限；容纳当前 4 个 checker，也足以容纳论文的 12 个。],
)

这些参数位于 `GH_GlobalParams.scala:5-16`。其中 `GH_TOTAL_PACKETS` 是每周期传输并行度，`GH_TOTAL_INSTS` 是指令阈值，二者都不是以字节计量的日志容量。当前项目中没有一个参数能够直接等价表达论文的“36 KiB 总日志、每个 checker 3 KiB”。

== BOOM 大核微结构

`v1Config` 使用 `WithNLargeBooms(1)`。其定义位于
`/home/gzh/EC/chipyard/generators/boom/src/main/scala/common/config-mixins.scala:177-216`，当前实际参数如下。

#table(
  columns: (1.4fr, 1.6fr, 3.4fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*部件*], [*当前参数*], [*解释*]),
  [前端/宽度], [`fetchWidth=8`，`decodeWidth=3`], [每拍最多解码、派发和提交 3 条；8 是压缩指令取指槽位宽度。],
  [ROB], [`96 entries`], [明显大于论文的 40 entries；较大的在途窗口也可能拉长从执行到校验完成的时间跨度。],
  [Issue Queue], [MEM 16、INT 32、FP 24], [issue width 分别为 1、3、1，dispatch width 均为 3；不是单一的 32-entry IQ。],
  [物理寄存器], [INT 100、FP 96], [小于论文的 INT 128、FP 128。],
  [Load/Store Queue], [LDQ 24、STQ 24], [均大于论文的 16 entries。],
  [分支在途数], [`maxBrCount=16`], [限制同时存在的分支 checkpoint 数。],
  [Fetch Buffer / FTQ], [24 / 32 entries], [控制取指与后端之间的缓冲及预测目标队列。],
  [浮点], [`sfmaLatency=4`，`dfmaLatency=4`，支持 div/sqrt], [配置没有直接声明论文所说的“2 个 FP ALU”。],
)

当前大核默认混入 `WithTAGELBPD`，位置为 `config-mixins.scala:438-465`。该预测器级联 Loop、TAGE、BTB、uBTB 和 BIM，使用 64-bit global history；它不是论文中的 tournament predictor。默认 TAGE 表在
`generators/boom/src/main/scala/ifu/bpd/tage.scala:186-198`，BTB 默认是 128 sets × 2 ways，位于 `ifu/bpd/btb.scala:15-23`；`BoomCoreParams` 默认 RAS 为 32 entries，位于 `common/parameters.scala:66`。因此分支预测器的组织与容量均不能按“名字相近”视为已经匹配论文。

== 大核私有缓存

大核 L1 参数由 `WithNLargeBooms` 直接构造。全局 cache line 是 64 B，定义在
`generators/rocket-chip/src/main/scala/subsystem/BankedL2Params.scala:14-15`。

#table(
  columns: (1.1fr, 1.55fr, 1.15fr, 1.0fr, 1.05fr, 2.2fr),
  inset: 4pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*缓存*], [*sets × ways*], [*容量*], [*row*], [*MSHR*], [*其他参数*]),
  [L1 ICache], [`64 × 8`], [32 KiB], [128 bit], [配置项不适用], [`fetchBytes=16`；未覆盖 `ICacheParams.latency`，故采用默认 2 cycles。],
  [L1 DCache], [`64 × 8`], [32 KiB], [128 bit], [4], [`nTLBWays=16`，随机替换；未显式打开 prefetch。],
)

容量由 `sets × ways × 64 B` 计算。论文要求的 32 KiB 容量已匹配，但当前是 8-way 而论文是 2-way；大核 ICache 默认 2-cycle，而论文是 1-cycle；DCache MSHR 为 4 而论文为 6。代码位置是 `config-mixins.scala:203-208`，ICache 的默认 latency 位于
`generators/rocket-chip/src/main/scala/rocket/ICache.scala:38-53`。

== Rocket checker 微结构与缓存

checker 由 `WithNGCCheckers` 创建，定义在
`/home/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/subsystem/Configs.scala:210-267`。每个 checker 是单发射、顺序执行 Rocket，关闭 debug，但仍继承 `RocketCoreParams` 的其余默认能力；乘除法器设置为 `mulUnroll=8`、`divUnroll=8` 并启用 early-out。Rocket 的源码流水包含取指、译码、执行、访存、写回阶段，当前没有一个 Config 字段可把它精确变成论文的 4-stage checker。

#table(
  columns: (1.15fr, 1.45fr, 1.05fr, 1.1fr, 2.7fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*对象*], [*sets × ways*], [*容量*], [*MSHR*], [*说明*]),
  [checker ICache], [`64 × 8`], [32 KiB/核], [配置项不适用], [64-bit row、64-B line、默认 2-cycle latency；每核私有。],
  [checker DCache], [`32 × 2`], [4 KiB/核], [0], [64-bit row、阻塞式；每核私有。],
)

这里的 row 宽度来自 `site(SystemBusKey).beatBits`。`v1Config` 没有混入 `WithSystemBusWidth(128)`，所以 `BaseSubsystemConfig` 采用 `XLen/8=8 B` 的 SBUS beat，即 64 bit；位置为
`generators/rocket-chip/src/main/scala/subsystem/Configs.scala:20-28`。BOOM L1 的 128-bit row 并不意味着整个 SBUS 已经是 128 bit。

== 共享缓存、内存与外设

`AbstractConfig` 在
`/home/gzh/EC/chipyard/generators/chipyard/src/main/scala/config/AbstractConfig.scala:45-68` 选择 SiFive Inclusive L2、coherent bus topology、模拟串行 TileLink、UART、BootROM 和模拟内存 harness。Inclusive L2 的默认参数定义在
`generators/sifive-cache/design/craft/inclusivecache/src/Configs.scala:47-59`。

#table(
  columns: (1.35fr, 1.75fr, 3.25fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*对象*], [*当前值*], [*说明*]),
  [Inclusive L2], [512 KiB、8-way、1 bank], [64-B line 时为 1024 sets；默认 `outerLatencyCycles=40`、`subBankingFactor=4`。],
  [L2 并发度], [没有“16 MSHRs”同名参数], [Inclusive Cache 的微结构与论文 gem5 缓存模型不同，不能把 `subBankingFactor` 当成 MSHR 数。],
  [预取], [未配置 stride prefetcher], [当前 L1 `prefetch=false`，默认 L2 Config 也没有论文同名的 stride prefetch 选项。],
  [外部内存], [仿真 harness 模型], [`v1Config` 没有设置 DDR3-1600、11-11-11-28 或 800 MHz DRAM timing；200 MHz 只是 MBUS 的外交时钟约束。],
  [MMIO], [片上 UART 等；顶层 MMIO master/slave port 关闭], [`AbstractConfig.scala:61-62` 关闭顶层 MMIO 端口，但片上外设和不可缓存访问仍需要校验提交约束。],
)

因此，当前配置能形成“BOOM 产生校验 packet、GHM 分配给 Rocket、checker 重放并反馈”的检测框架，但没有仅凭这些 Config 就证明实现了 ParaMedic 的完整纠错语义。特别是论文所需的 L1 cacheline timestamp、旧值 undo log、ECC、未提交行禁止 eviction/Probe 外泄、不可重复 I/O 的 check-before-communication，都属于数据通路和一致性控制逻辑，而不是已有的容量或时钟参数。

= ParaMedic 论文配置整理

== 实验平台参数

论文 `ParaMedic: Heterogeneous Parallel Error Correction` 的 Table I（PDF 第 8 页）给出如下实验配置。该论文在 gem5 中使用 ARMv8 64-bit ISA；这与本项目的 RISC-V BOOM/Rocket RTL 在 ISA、流水和缓存模型上均不同，所以这些数字应作为实验条件对齐目标，而不是声称两个实现可做到逐周期等价。

#table(
  columns: (1.35fr, 4.95fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*类别*], [*论文配置*]),
  [主核], [3-wide、out-of-order、3.2 GHz。],
  [主核流水资源], [40-entry ROB；32-entry IQ；16-entry LQ；16-entry SQ；128 个整数物理寄存器；128 个浮点物理寄存器；3 个整数 ALU；2 个浮点 ALU；1 个乘除法 ALU。],
  [分支预测], [Tournament：2048-entry local、8192-entry global、2048-entry chooser；2048-entry BTB；16-entry RAS。],
  [寄存器 checkpoint], [16 cycles latency。],
  [主核 L1 ICache], [32 KiB、2-way、1-cycle hit latency、6 MSHRs。],
  [主核 L1 DCache], [32 KiB、2-way、2-cycle hit latency、6 MSHRs。],
  [共享 L2], [1 MiB、16-way、12-cycle hit latency、16 MSHRs、stride prefetcher。],
  [内存], [DDR3-1600，时序 11-11-11-28，800 MHz。],
  [checker], [12 个 in-order 核、4-stage pipeline、每核 1 GHz。],
  [校验日志], [总计 36 KiB；每个 checker 3 KiB；单个 log segment 最长 5000 条指令。],
  [checker cache], [每核 2 KiB L0 ICache；所有 checker 共享 16 KiB L1。],
)

== 日志与 checkpoint 组织

论文的配置不能只看 Table I，因为其延迟与纠错能力由下列日志语义共同决定。

- Load-store log 按 checker 等分，每个 checker 对应一个 segment；主核按程序顺序记录 load/store 地址、load data、store data，并为纠错额外记录 store 覆盖前的 old value。
- 日志保存 virtual address，以减少 checker 重放时的地址翻译；回滚时才重新经过 TLB。store 的 virtual address 和 old value 必须带 ECC，避免回滚本身使用损坏的地址或旧值。
- segment 填满或达到指令上限时形成 checkpoint，并派给一个 checker。checker 可并行、乱序完成 segment，但释放日志和提交状态必须遵守 timestamp 顺序。
- 论文给出的 36 KiB 日志可根据 load/store 比例容纳约 1500--4500 个日志 entry；“5000 instructions”是 segment 的最大指令长度，不等于 5000 个 load-store entry。
- 动态 checkpoint 使用 AIMD：遇到导致主核暂停或 coherence response 延迟的事件时，把目标 segment 指令数减半；无此事件时每次加 5，最大不超过 5000。该策略直接影响平均检测延迟和日志占用。

以上内容来自论文第 III-A、III-B、IV-B 和 IV-D 节。它们解释了为什么“总日志容量、分区数、最大指令数”必须同时配置，不能只把本项目的 `GH_TOTAL_INSTS` 从 3970 改成 5000。

== 缓存、一致性与 I/O 约束

ParaMedic 允许未经检查的 store 先进入主核私有 L1D，以便后续指令转发和继续执行，但不允许未提交数据离开 L1。每条含未提交写的 cacheline 记录 timestamp；当替换、失效或 coherence downgrade 可能把数据送往 L2 或其他核时，相关响应被延迟到对应 check 完成。若一个 set 内所有候选行都含未提交修改，则暂停主核并提前结束 checkpoint，等待校验释放至少一行。论文明确指出低相联度会放大 conflict eviction，因此建议提高相联度或增加按 timestamp 排序的 eviction buffer。

对于多主核情形，论文采用 check-before-communication：另一个主核不能观察到当前核的未提交数据。对于 uncacheable access、不可重复 read/write 和系统外通信，处理器必须停止、发起检查并等待检查完成后才能发出操作。异常和中断也会形成新的 checkpoint。该规则是系统正确性的组成部分，也会直接形成校验关键路径。

== 论文性能观察中与配置有关的结论

论文报告：单线程无共享内存时，纠错相对无校验的平均 slowdown 为约 2.0%，检测为 1.9%；加入共享内存和 L1 timestamp 阻塞后，纠错约为 4.6%，使用 AIMD 动态 checkpoint 后降至约 3.1%；多线程测试中检测约 1%，纠错约 1.5%。这些结果依赖 Table I 的 12 个 checker、缓存参数、日志容量及 gem5 时序模型，不能直接外推到当前 1+4、200/100 MHz 的 Chipyard RTL。

= 贴近论文的项目配置方法

== 对齐原则与实施层次

这里的“贴近”应首先理解为性能行为接近，而不是参数字符串相同。论文使用的是 ARMv8 gem5 模型，本项目使用 RISC-V BOOM/Rocket RTL；即使把频率、核数、ROB 或 cache 容量改成同样的数值，IPC、cache miss 代价和 checker 服务时间仍可能不同。因此先固定可复现的工作负载和基线，测出性能指标，再把核数、频率、队列和日志容量作为达到目标的手段。

#table(
  columns: (1.25fr, 2.1fr, 3.2fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*层次*], [*目标*], [*实现范围*]),
  [A：功能与拓扑对齐], [BOOM/checker 的 hart ID、分配、CDC 和 packet 路由正确], [先用当前 1+4、200/100 MHz 配置保证 elaboration、boot、checker 使能和错误注入流程通过；12 个 checker 只是扩展实验点。],
  [B：性能等效], [在相同工作负载下控制 IPC、校验吞吐和检测延迟的相对差异], [采集 BOOM commit IPC、checker 有效 IPC、cache miss、packet/日志 occupancy、P50/P95/P99 检查延迟和大核停顿占比，再据此调整核数、频率、队列和 cache。],
  [C：纠错语义对齐], [未提交数据不离开 L1，可按 timestamp 回滚], [实现 undo log、ECC、L1 timestamp、eviction/Probe gate、MMIO barrier、AIMD checkpoint；这是 ParaMedic 正确性的核心。],
)

只完成 A/B 可以做吞吐与检测延迟对比，但不能称为 ParaMedic 式完整纠错系统；只有完成 C 后，才可验证回滚和“错误数据不逃逸”的性质。论文的 slowdown 可以作为参考结果，但不应在未完成 C 或未校准内存模型时直接宣称复现。

== 性能等效指标与校准闭环

每个配置点至少记录以下量，并同时给出无校验 BOOM 基线。大核 IPC 用测量区间内的提交指令数除以大核总周期数；checker IPC 用已验证的原程序指令数除以 checker 执行已分配 segment 的周期数，其中包含日志、CDC 和 cache stall。checker 没有任务时的空闲则由利用率 $eta$ 单独表示，不能把 Rocket 的理论单发射上限当成有效服务率。

#table(
  columns: (1.55fr, 2.25fr, 2.75fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*指标*], [*定义*], [*用于决策*]),
  [BOOM commit IPC], [`committed_insts / core_cycles`], [判断主核是否因校验机制降速；与论文的 3-wide 不能直接等同。],
  [checker 有效 IPC], [`verified_program_insts / assigned_segment_cycles`], [反映 Rocket 流水、分支、访存和长延迟指令的真实服务能力；不使用 checker 辅助代码的 raw retire 数。],
  [checker 利用率 $eta$], [`checker_assigned_cycles / checker_wall_cycles`], [反映 segment 调度、负载不均和前序 timestamp 等待造成的空闲。],
  [校验服务率], [$N_c times "IPC"_c times f_c times eta$], [决定增加 checker 还是提高 checker 频率；必须使用测得的 IPC 和利用率。],
  [积压压力 $rho$], [$("IPC"_b times f_b) / (N_c times "IPC"_c times f_c times eta)$], [$rho < 1$ 才能长期清空队列；建议留出 10--20% 余量，而不是追求论文的频率比。],
  [检查延迟], [BOOM commit/checkpoint 到 checker 完成的 wall-clock 周期，报告 P50/P95/P99], [限制错误暴露时间和未提交状态窗口；平均值不能替代尾延迟。],
  [校验开销], [(校验模式运行时间 / 无校验基线时间) - 1，以及 BOOM 因 backpressure 停顿的周期占比], [与论文 slowdown 做相对比较；区分核 IPC 损失和 CDC/日志等待。],
)

推荐采用“测量--调参--复测”的闭环：先在当前 1+4 配置上测出 $"IPC_b"$、$"IPC_c"$、$eta$ 和 $rho$，再逐步增加 checker 或调整时钟，直到 $rho$ 稳定低于 1 且 P95 检查延迟不再因队列积压增长；最后才比较 cache、预测器和日志容量。所需 checker 数可按
$N_c >= ("IPC_b" times f_b) / ("IPC_c" times f_c times eta times (1 - "margin"))$
估算，其中 `margin` 取 0.1--0.2，并用实测结果验证。这个公式比直接复制论文的 12 个 checker 或 3.2/1 GHz 更适合当前 RTL。

性能实验应至少包含下列配置点，除被扫描变量外，其余微结构和 workload 必须保持不变：

#table(
  columns: (1.1fr, 2.35fr, 3.15fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*配置点*], [*设置*], [*用途与判定*]),
  [B0], [关闭校验框架的 BOOM], [得到 `IPC_base`、MPKI 和基线运行时间。],
  [B1], [当前 1+4、200/100 MHz], [得到 `IPC_checked`、$"IPC_c"$、$eta$、$rho$、队列斜率和检查延迟，定位当前主要瓶颈。],
  [S8 / S12], [保持 BOOM 和 checker 单核参数不变，仅扩展到 8/12 个 checker], [检查总服务率是否近似线性增长；若单 checker IPC 或总线效率下降，说明已经受互连/cache 限制。],
  [F-sweep], [固定 checker 数，只扫描 checker 频率或大核/checker 周期比], [分离“核数不足”和“单核服务率不足”；选取满足 $rho <= 1 - "margin"$ 的最低资源点。],
  [P-ref], [论文 Table I 的可实现参数组合], [只作为参考点；比较相对 slowdown、IPC loss 和尾延迟，不把参数相同视为复现成功。],
)

对固定指令轨迹，`IPC_loss = 1 - IPC_checked / IPC_base` 用于隔离微结构和校验停顿造成的周期损失；若配置点频率不同，还必须用实际运行时间计算论文采用的 slowdown。一个配置只有在 $rho <= 1 - "margin"$、长时间队列 occupancy 无上升趋势、P95/P99 检查延迟稳定，并且 BOOM backpressure 停顿占比可接受时，才算达到性能平衡；不能只看平均 IPC。

== 核数、hart ID 与 GuardianCouncil 参数

不要把全局核数直接改为 13。先把当前 1+4 作为基线，测量不同负载下的 $"IPC_b"$、$"IPC_c"$、$eta$、$rho$ 和 P95 检查延迟；只有当 $rho >= 1$ 或日志长期满时，才按 1+8、1+12 的阶梯扩展。保留 16-bit checker mask，使这些规模都能在同一套 RTL 中切换。用于扩展实验的参数示例如下：

```scala
object GH_GlobalParams {
  val GH_NUM_CORES = 5           // 基线：1 BOOM + 4 Rocket checker
  val GH_NUM_BIG_CORES = 1
  val GH_TOTAL_PACKETS = 2       // 先由 packet lane 利用率决定是否增加
  val GH_TOTAL_INSTS = 3970      // 基线阈值；上限 5000 是待校准变量
  val GH_WIDITH_PACKETS = 136
  val IF_THERE_IS_CDC = true
  val GH_CHECKER_MASK_WIDTH = 16
}
```

修改位置是 `generators/rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala`。顶层继续使用
`WithNLargeBooms(GH_NUM_BIG_CORES, Some(0))` 和
`WithNGCCheckers(GH_NUM_CORES-GH_NUM_BIG_CORES, Some(1))`，核数只作为性能扫描的自变量。由于 GHM、GAGG、BaseTile 和 checker 状态中存在大量按 `GH_NUM_CORES` 展开的 `Vec`、拼接和索引，每个扫描点都必须重新 elaboration，并检查所有硬编码目的编号和位宽。特别是 `GHM.scala:89-98` 的 packet 目的字段只有 4 bit，编号 1--12 可以容纳，但已经接近其结构上限。

== 时钟配置

不要把 3200 MHz、1000 MHz 或 3.2:1 的时钟比当成默认目标。先保持当前 200/100 MHz，使用同一 workload 扫描 checker 数量和频率，令实测 $rho$ 低于 1 并观察 IPC 和 P95 检查延迟是否达到平台稳定区；之后再把周期数归一化，与论文的相对 slowdown 和检查延迟比较。只有在需要研究频率敏感性或物理实现时，才增加下列独立时钟实验：

```scala
new chipyard.config.WithTileFrequency(200, Some(0)) ++
// checker 频率按 rho 扫描结果设置，而不是固定为论文的 1000 MHz
new chipyard.config.WithGCBusFrequency(100) ++
new freechips.rocketchip.subsystem.WithAsynchronousRocketTiles(...) ++
```

绝对 MHz 只对支持独立时钟的仿真/实现流程有意义。Verilator 更应报告每条指令的周期、IPC 和 wall-clock 检查延迟；VCS/FPGA/ASIC 流程再验证真实时钟约束。还应修正 `WithAsynchronousRocketTiles`，让 `depth` 和 `sync` 真正传入 `AsynchronousCrossing(depth=..., sourceSync=..., sinkSync=...)`，否则修改调用参数不会产生硬件变化。

SBUS、MBUS、L2 和外设不应机械地设为 3.2 GHz。论文只明确主核、checker 与 DRAM 频率，没有给出 Chipyard 总线频率。合理做法是先保留当前 64-bit SBUS 与独立 uncore 时钟作为基线；只有当总线利用率、仲裁等待和 checker IPC 显示互连饱和时，再增加 128-bit 对照点。在性能模型中应校准实际 L2 hit 和 DRAM 往返周期；物理实现阶段再以时序收敛为约束选择总线频率。

== BOOM 参数与 IPC 校准

BOOM 参数首先决定无校验基线的 IPC、MPKI 和 memory-level parallelism。下表中的论文数值应作为受控扫描点，而不是必须全部覆盖的默认目标。若需要做微结构敏感性实验，可新增 `WithNParaMedicBooms`，从 `WithNLargeBooms` 复制最小必要结构；不要直接改全局 Large BOOM preset，以免影响仓库其他 Config。

#table(
  columns: (1.4fr, 1.25fr, 1.3fr, 2.4fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*参数*], [*当前*], [*论文参考值*], [*设置方式/限制*]),
  [decode/retire width], [3], [3], [保持 `decodeWidth=3`。],
  [ROB], [96], [40], [设置 `numRobEntries`；但当前 BOOM 要求 `numRobEntries % coreWidth == 0`，40 不能被 3 整除，故不能直接填 40。可选 42 作为最近合法值，或修改 ROB 行组织后精确实现 40。],
  [IQ], [16/32/24], [32 total], [论文只给总 IQ，BOOM 分 MEM/INT/FP。建议先保留 INT 32，并用 12/32/16 做近似；精确对齐需要先明确论文 32 是否全局共享。],
  [LDQ / STQ], [24 / 24], [16 / 16], [设置 `numLdqEntries=16`、`numStqEntries=16`。],
  [INT / FP PRF], [100 / 96], [128 / 128], [设置 `numIntPhysRegisters=128`、`numFpPhysRegisters=128`。],
  [执行单元], [由 BOOM execution-unit 组合决定], [3 INT、2 FP、1 Mul/Div], [issue width 不等于物理 ALU 数；精确对齐需要修改执行单元定义并核对端口/旁路网络。],
  [RAS], [32], [16], [设置 `numRasEntries=16`。],
)

当前 BOOM 的 `require(numRobEntries % coreWidth == 0)` 位于
`generators/boom/src/main/scala/common/parameters.scala:281`。因此敏感性实验可报告“论文 40、实现近似 42”，但应根据 `IPC_base`、分支 MPKI、L1 MPKI 和 $"IPC_b"/"IPC_c"$ 供需关系判断 42 是否比 96 更接近论文的性能行为，不能仅凭 entry 数下结论。

仓库已有 `TourneyBranchPredictorBank`、`BIMBranchPredictorBank`、`BTBBranchPredictorBank` 等组件，但当前 `WithTAGELBPD` 没有按论文的 local/global/chooser 容量组织它们。如果分支 MPKI 差异是影响 $"IPC_b"$ 和 packet 突发性的主因，再实现 `WithParaMedicTournamentBPD`，构造论文的 2048-entry local、8192-entry global、2048-entry chooser、2048-entry BTB，并把 RAS 设为 16。否则可以保留 TAGE-L，但必须标注为“非论文预测器”，并报告实际 MPKI。

== 缓存与内存性能校准

缓存应按 I/D MPKI、命中延迟、miss latency、MSHR occupancy 和由 cache stall 导致的 IPC 损失校准。论文的 32 KiB、2-way 对应 64-B line 下的 256 sets × 2 ways，但 BOOM 当前前端含 `icacheParams.nSets <= 64` 的 alias 限制（`common/parameters.scala:229`），所以 ICache 不能直接设 256 sets。可以先保留 64 sets × 8 ways 作为容量等同点，再用 trace 或小型 cache sweep 判断相联度差异是否显著；只有差异显著时才修复 alias 处理并测试 256 × 2。DCache 的 256 × 2、`nMSHRs=6` 以及 ICache 1-cycle、DCache 2-cycle 也应作为对照点，通过仿真波形和计数器确认实际性能，不能只依据 Scala 字段名。

共享 L2 的论文参数对照点可以写为：

```scala
new freechips.rocketchip.subsystem.WithNBanks(1) ++
new freechips.rocketchip.subsystem.WithInclusiveCache(
  nWays = 16,
  capacityKB = 1024,
  outerLatencyCycles = 12
) ++
new chipyard.config.WithSystemBusWidth(128) ++
```

这能给出 1 MiB、16-way 和外侧延迟常量的参考配置，但不能自动得到“12-cycle L2 hit、16 MSHRs、stride prefetcher”。需要为 Inclusive Cache 建立可测的 hit-latency 基准，记录 L2 MPKI、tracker occupancy 和平均/尾部 miss latency，再判断是否需要增容、增加并发 tracker 或实现 stride prefetch。内存侧只有在 memory-bound workload 的 IPC 对 DRAM 延迟敏感时，才需要接入并校准 DRAMSim2、Ramulator 或等价 DDR3-1600 时序模型；当前 SimDRAM/harness 不能代表论文 DRAM。

== checker 与日志层次对齐

当前 Rocket checker 是单发射顺序核，功能上接近论文的 in-order checker，但阶段划分、FPU/VM 和私有缓存均不匹配。先在 4 个 checker 上测量有效 IPC、每段服务周期和日志等待周期；只有当实测 checker 服务率不足以使 $rho < 1$ 时，才扩展到 8 或 12 个 checker，或提高 checker 时钟。可以新增 `WithNParaMedicCheckers` 保留 GuardianCouncil 接口，并按工作负载决定是否关闭 FPU/VM、设置乘除法 latency；这些选择应以 checker IPC 和 P95 服务时间为验收指标，而不是以“4-stage”名称相同为验收条件。

论文的 checker cache 是“每核 2 KiB L0 ICache + 12 核共享 16 KiB L1”。当前每核 32 KiB ICache + 4 KiB DCache，且所有 L1 私有。仅修改 `ICacheParams` 无法形成共享 checker L1；可把每核 2 KiB ICache（32 sets × 1 way × 64 B）作为性能扫描点。只有当 checker ICache MPKI、SBUS 请求和 $"IPC_c"$ 表明当前私有 cache 明显偏离目标时，再在 checker cluster 与 SBUS 之间新增共享 16 KiB cache/scratchpad。若暂不实现共享 L1，应把私有 cache miss 和 SBUS 流量视为模型偏差。

日志容量也不应先验地固定为 36 KiB。应先按实际 entry 宽度和 load/store 比例测量日志 bytes per instruction、分区 high-watermark、日志 full 次数和提前 checkpoint 次数，再决定总容量及分区数。论文的 36 KiB（12 个 3 KiB 分区）作为对照点保留；`GH_TOTAL_INSTS=5000` 仅是 segment 最大指令数，实际 checkpoint length 由 AIMD 和 P95 检查延迟共同校准。日志 entry 至少包括类型、virtual address、load/store data；用于纠错时还需 old value、地址 ECC、旧值 ECC、timestamp/segment ID。

== 必须补充的正确性机制

为了接近论文而不只是接近 Table I，还必须完成以下 RTL 行为：

- BOOM L1D 在每次 store 时捕获 old value，并写入带 ECC 的 undo log；cacheline tag 增加最新未提交 timestamp。
- 未提交 dirty line 的 eviction、Release、ProbeAckData 和对其他核的降级响应必须等待相应 timestamp 校验通过；全 set 被未提交行占满时触发提前 checkpoint 和大核停顿。
- checker 成功后按 timestamp 顺序释放日志与 cacheline；失败时逆序遍历日志恢复 old value，再恢复寄存器 checkpoint。
- uncacheable/MMIO 读写、外部通信、异常和中断建立 check-before-communication barrier；不可重复 read 的返回值需记录并在重放时复用。
- checkpoint scheduler 实现论文 AIMD 规则，并保证 segment、checker、timestamp、线程/进程 ID 的关联在回滚期间不丢失。

这些机制不能由 `WithInclusiveCache`、`WithTileFrequency` 或 `GH_TOTAL_INSTS` 自动产生。配置对齐完成后，应以“未校验 store 永不离开 BOOM L1D”“任意错误回滚后共享 L2/DRAM 与最近已提交 timestamp 一致”作为形式断言或定向测试的核心性质。

= 配置瓶颈与校验延迟增大因素

== 吞吐供需不平衡

校验是否积压首先取决于大核产生工作的速率与 checker 消化工作的速率。不要用提交宽度代替实际 IPC，应使用测得的提交/验证指令数定义

$ rho = ("IPC"_b times f_b) / (N_c times "IPC"_c times f_c times eta) $

其中 $"IPC"_b$ 是 BOOM 的实际 commit IPC，$"IPC"_c$ 是单个 checker 执行已分配 segment 时的有效验证 IPC，$eta$ 是 checker 平均利用率，$f_b/f_c$ 是各自时钟，$N_c$ 是 checker 数。$rho < 1$ 只表示长期平均服务能力足够；还要通过队列 occupancy 和 P95 检查延迟确认短时突发不会造成持续 backpressure。可以用
$N_c >= ("IPC"_b times f_b) / ("IPC"_c times f_c times eta times (1 - "margin"))$
估算最小核数，`margin` 建议为 0.1--0.2。

例如，假设实测大核 IPC 为 1.8、checker IPC 为 0.65，并暂按理想利用率 $eta=1$ 计算，当前 4 个 checker 和 200/100 MHz 的 $rho$ 约为 1.38；实际 $eta < 1$ 时压力更大。此时直接把频率改成论文数值并不能说明性能已对齐，应该先扩展 checker 或降低大核产生速率，再观察 IPC 和尾延迟是否进入稳定区。论文的 `3 × 3.2 / (12 × 1 × 1.0)` 只能作为无 stall 的粗略上界，不能替代 RTL 实测值。

直接导致 $"IPC"_c$ 降低的因素包括 checker 的 load/use hazard、分支误预测、乘除法和浮点长延迟、日志数据未到齐、共享 cache miss、TLB miss，以及 checker 在 checkpoint 边界保存/比较寄存器状态。仅提高 checker 数量也可能因共享总线和调度争用而收益递减。

== 校验 packet、日志与调度瓶颈

#table(
  columns: (1.55fr, 2.6fr, 2.35fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*因素*], [*如何增加延迟*], [*建议观测/调节*]),
  [`GH_TOTAL_PACKETS=2`], [大核 3-wide 提交而每拍最多输出 2 个 packet，连续三提交会在 `GH_BUF` 内形成排队。], [统计 `numEnq-numDeq`、buffer full、packet lane 利用率；评估 3 packet/cycle，但同时考虑总线宽度和扇出。],
  [136-bit packet × 2], [宽 packet 经过 GHM Mux、CDC 和 12 路目的选择，扩大布线、扇出与综合关键路径。], [记录 GHM enq/deq 等待；必要时分片或流水化路由。],
  [GHM AsyncQueue], [深度 256 可吸收突发，但只能隐藏、不能消除长期吞吐不足；满后向大核传播 backpressure。], [统计每 checker 的 occupancy、full、empty、head wait；按最坏突发调深度。],
  [固定 `GH_TOTAL_INSTS=3970`], [segment 太大时首次错误发现更晚、日志占用更久；太小时 checkpoint/寄存器复制开销占比升高。], [实现 AIMD，画出 segment length 与检测延迟分布，不只看平均值。],
  [36 KiB 日志分区], [某个 checker 对应分区满时，即使其他分区空闲也可能阻塞大核；长 segment 完成乱序时还要等待更早 timestamp。], [统计 per-partition high-watermark、head-of-line blocking、完成到提交的间隔。],
  [日志 entry 变宽], [加入 old value、ECC、timestamp 后，每 3 KiB 能容纳的 store 数下降，store-heavy workload 更易提前 checkpoint。], [按 load/store 比例计算真实 entry 数，分别测试读密集和写密集负载。],
)

== CDC、时钟与互连瓶颈

当前 checker tile 与 SBUS、GHM packet 路径均跨 200/100 MHz 时钟域。同步级数会加入固定延迟，异步 FIFO 的读写指针同步会让 ready/valid 反馈滞后；频率差使大核产生的突发在 checker 域排队。应把 CDC 延迟计入 checker wall-clock 服务时间和 $rho$，通过 occupancy、full、empty 和 head wait 计数判断瓶颈；不能根据论文的 3.2/1.0 GHz 比例直接推断必须使用 12 路 checker。

`WithAsynchronousRocketTiles(depth, sync)` 忽略形参会造成一个隐蔽瓶颈：配置文件看似加深队列，实际 elaborated hardware 仍使用默认值。应把 crossing 参数修正后，从 elaboration 的 `*.dts`、FIRRTL/MLIR 注解或生成 Verilog 中反查队列深度和同步级数。

从 4 个扩到 12 个 checker 会同时增加 SBUS master 数、GHM/GAGG 端口数、状态归并扇入、广播控制扇出和中断/时钟树负载。若所有 checker 同时取指 miss 或访问共享日志，64-bit SBUS 会成为热点。只有当实测 checker IPC 随核数增加明显下降、或 SBUS 利用率接近饱和时，才考虑改为 128 bit、增加 checker cluster 本地共享 L1，或对 GHM 的目的选择和状态归并插入流水级；否则扩核可能换来更长的互连等待。

== 缓存、coherence 与内存瓶颈

当前大核 32 KiB L1 容量与论文一致，但 8-way、4 MSHRs、ICache 2-cycle；L2 则只有 512 KiB、8-way、默认外侧 40 cycles且无 stride prefetch。相较论文，较少的 DCache MSHR、较小且低相联的 L2、更长内存往返时间都会增加 BOOM 和 checker 的 miss stall，并使校验数据到达 checker 更晚。

实现 ParaMedic timestamp 后，校验延迟与缓存压力形成反馈：check 越慢，未提交 dirty line 保留越久；保留越久，可替换 way 越少；冲突/容量 miss 越容易遇到“全 set 未提交”；随后大核被迫提前 checkpoint 并等待 checker，使有效吞吐进一步下降。高 store 密度、低空间局部性、多个地址映射到同一 set、共享数据频繁被其他核 Probe，都会放大这个反馈。

coherence request 是另一类 head-of-line blocking。对带未提交 timestamp 的行，Probe/降级必须延迟；同一行的后续写又必须服从 coherence request 的优先级。共享写密集程序、false sharing 和锁变量会频繁触发该路径，使校验从后台工作变成通信关键路径。需要分别统计 delayed Probe 次数、每次等待的 timestamp、因全 set 未提交导致的 stop 周期，以及 check 完成后到 Release 真正发出的周期。

checker cache 拓扑也会改变结果。当前每核 32 KiB ICache 的命中率可能显著高于论文每核 2 KiB L0，从而低估取指延迟；另一方面，当前没有 16 KiB checker 共享 L1，多个 checker 的相同代码 miss 会重复进入 SBUS，又可能高估互连压力。两种误差方向相反，必须通过命中率和总线请求数分开校准。

== 大核微结构与工作负载因素

当前 96-entry ROB、24-entry LDQ/STQ 比论文 40/16/16 更大。它们可能提高无校验 BOOM IPC，但也可能在 checker 落后时累积更多尚未验证的指令、store 与 checkpoint 状态。应同时报告无校验和有校验 IPC、最大未验证指令数、检查延迟及大核停顿占比；只有当 ROB/LSQ 调整使这些性能指标更接近目标，才有理由修改容量。不能因为论文写成 40/16/16 就忽略 BOOM 的 3-wide 行组织约束。

分支预测器差异同样会干扰对比。TAGE-L 与论文 tournament 的误预测率不同，误预测会清空大核错误路径、改变有效提交速率及 packet 突发；checker 自身的分支、mul/div、FP 和访存组合则决定 segment 服务时间方差。方差越大，分区式调度越容易出现短任务完成但等待长任务前序 timestamp 的情况。

工作负载层面应重点覆盖：高 store 比例、随机访存、低相联冲突、false sharing、锁竞争、频繁 MMIO、异常/中断、长除法/浮点序列和高分支误预测。平均 IPC 不能解释尾部校验延迟，应至少报告 P50/P95/P99 的“BOOM commit 到 checker 验证完成”周期、最大未验证指令数、最大未提交 dirty line 数和大核因校验停顿的周期占比。

== 无法仅靠配置消除的瓶颈

#table(
  columns: (1.4fr, 2.45fr, 2.65fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*瓶颈类别*], [*Config 能做什么*], [*仍需的 RTL/模型工作*]),
  [核数与频率], [增加 checker、调整时钟和 crossing。], [修正 crossing 形参未生效；流水化 GHM/GAGG 大扇入扇出。],
  [BOOM 容量], [调整大部分 ROB/LSQ/PRF 参数。], [40-entry ROB 与 3-wide 行组织冲突；执行单元数量和 16-cycle checkpoint 需结构修改。],
  [缓存容量], [调整 L1/L2 sets、ways、MSHR 和总线宽度的一部分。], [ICache 256-set alias 限制、精确 hit latency、L2 16 MSHR、stride prefetch、checker 共享 L1。],
  [ParaMedic 纠错], [设置 segment 上限和基础拓扑。], [36 KiB undo log、ECC、timestamp、逆序回滚、Probe/eviction gate、MMIO barrier、AIMD。],
  [内存时序], [设置 MBUS 频率和端口。], [接入并校准 DDR3-1600 timing model；区分总线 MHz 与 DRAM 设备 MHz。],
)

配置优化的优先顺序应是：先建立无校验/有校验的 IPC、校验服务率、$rho$、P95/P99 检查延迟和停顿占比基线；再用 checker 数量、频率和 packet 并行度消除长期积压；随后实现日志/AIMD 与 L1 timestamp 正确性；最后校准 checker cache、L2、DRAM、预测器和精确流水周期。较深的队列或更大的日志只有在这些指标证明需要时才增加，否则只会把积压隐藏得更久。
