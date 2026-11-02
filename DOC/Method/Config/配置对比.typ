#set page(paper: "a4", margin: (x: 12mm, y: 14mm))
#set text(lang: "zh", size: 9.5pt)
#set par(leading: 0.6em)
#set heading(numbering: "1.1")

= 三重对比：修改前 / 当前未提交改动 / 论文

- *未修改之前*：`git` 提交版本。`v1Config` 使用 `WithNLargeBooms`，L2 继承 `AbstractConfig` 默认值，checker ICache 为 64 × 8。
- *目前未提交*：工作区当前改动。`WithNParaMedicBooms` + `WithInclusiveCache(16, 1024, 12)` + checker ICache 32 × 1，并把 `GH_TOTAL_INSTS` 调到 5000。
- *论文*：ParaMedic Table I（同 `Ref/大小核配置.typ`）。

结论标记（每行取最显著一项）：
- *完全匹配*：修改后参数与论文一致。
- *性能等效*：无法逐字一致，但性能行为可基本对齐。
- *无法更改*：受 RTL 结构限制，无法仅靠 Config 达到。

== 顶层与时钟

#table(
  columns: (1.0fr, 1.9fr, 1.9fr, 1.9fr, 1.9fr),
  inset: 4pt,
  stroke: 0.5pt + gray,
  table.header([*项目*], [*未修改之前*], [*目前未提交*], [*论文*], [*结论*]),
  [大核], [1 × BOOM 3-wide 乱序，200 MHz], [同左], [1 × 3-wide 乱序，3.2 GHz], [*性能等效*：3-wide 已一致；绝对频率不可复现，Verilator 下只体现 CDC 周期比],
  [checker], [4 × Rocket 单发射顺序，100 MHz/核], [同左], [12 × in-order 4-stage，1 GHz/核], [*性能等效*：核数可由 `GH_NUM_CORES=13` 加每核 `WithTileFrequency` 扩到 12；4-stage 与 1 GHz 见下表],
  [SBUS / MBUS / PBUS / GBUS], [64-bit SBUS 200 MHz；MBUS/PBUS 200 MHz；GBUS 100 MHz], [同左], [—], [论文未定义总线频率，保持现有实现],
)

== BOOM 大核微结构

#table(
  columns: (1.0fr, 1.9fr, 1.9fr, 1.9fr, 1.9fr),
  inset: 4pt,
  stroke: 0.5pt + gray,
  table.header([*项目*], [*未修改之前*], [*目前未提交*], [*论文*], [*结论*]),
  [宽度], [decodeWidth = 3], [同左], [3-wide], [*完全匹配*],
  [ROB], [96], [42], [40], [*性能等效*：42 是 3-wide 下满足 `numRobEntries % coreWidth == 0` 的最近合法值，40 无法直接填入],
  [IQ], [MEM 16 / INT 32 / FP 24], [同左], [32（总）], [*无法更改*：BOOM 按 MEM/INT/FP 三队列实现，无单一 32-entry IQ；INT 32 与论文总数巧合一致，但总量不等],
  [LQ / SQ], [24 / 24], [16 / 16], [16 / 16], [*完全匹配*],
  [物理寄存器], [INT 100 / FP 96], [INT 128 / FP 128], [128 / 128], [*完全匹配*],
  [执行单元], [由 issue 宽度决定，无独立 ALU 数配置], [同左], [3 INT / 2 FP / 1 Mul-Div], [*无法更改*：需修改执行单元定义与端口/旁路网络，Config 无对应参数],
  [分支预测], [TAGE-L（Loop+TAGE+BTB+uBTB+BIM）], [同左], [Tournament：2048 local / 8192 global / 2048 chooser / 2048 BTB], [*性能等效*：TAGE-L 与 Tournament 均为条件预测器，精度量级相当；精确容量需新建 `WithParaMedicTournamentBPD`],
  [RAS], [32], [16], [16], [*完全匹配*],
  [寄存器 checkpoint], [未实现], [同左], [16 cycles], [*无法更改*：需额外实现寄存器 checkpoint 逻辑，Config 无对应参数],
)

== 缓存（重点）

#table(
  columns: (0.9fr, 1.9fr, 1.9fr, 1.9fr, 1.9fr),
  inset: 4pt,
  stroke: 0.5pt + gray,
  table.header([*项目*], [*未修改之前*], [*目前未提交*], [*论文*], [*结论*]),
  [L1 ICache], [32 KiB（64 × 8）], [同左], [32 KiB，2-way，1-cycle，6 MSHRs], [*性能等效*：容量 32 KiB 已匹配；2-way 需 256 sets，受 `icacheParams.nSets <= 64` 别名限制*无法更改*；1-cycle 需改 BOOM ICache 命中流水，*无法更改*],
  [L1 DCache], [32 KiB（64 × 8），4 MSHRs], [32 KiB（256 × 2），6 MSHRs], [32 KiB，2-way，2-cycle，6 MSHRs], [*完全匹配*：容量/相联度/MSHR 一致，2-cycle 为 BOOM DCache 固有命中延迟],
  [共享 L2], [512 KiB，8-way，outerLatencyCycles=40，1 bank], [1 MiB，16-way，outerLatencyCycles=12，1 bank], [1 MiB，16-way，12-cycle，16 MSHRs，stride prefetcher], [*性能等效*：容量/相联度/12-cycle 外侧延迟参数已匹配；16 MSHRs 与 stride prefetcher 无同名参数，*无法更改*],
  [内存], [SimDRAM / harness 模型], [同左], [DDR3-1600 11-11-11-28，800 MHz], [*无法更改*：harness 无 DRAM 时序模型，需接入 DRAMSim2/Ramulator 才可校准],
)

== checker 与日志

#table(
  columns: (0.9fr, 1.9fr, 1.9fr, 1.9fr, 1.9fr),
  inset: 4pt,
  stroke: 0.5pt + gray,
  table.header([*项目*], [*未修改之前*], [*目前未提交*], [*论文*], [*结论*]),
  [checker 流水], [Rocket 单发射顺序（5 级），mul/div unroll=8], [同左], [12 × in-order 4-stage], [*无法更改*：Rocket 固定 5 级，无 Config 字段可改为 4 级],
  [checker ICache], [32 KiB（64 × 8）], [2 KiB（32 × 1）], [2 KiB L0 ICache/核], [*完全匹配*],
  [checker L1], [私有 DCache 4 KiB（32 × 2，blocking）], [同左], [16 KiB 共享 L1], [*无法更改*：当前每核私有 DCache，Config 无法形成共享 16 KiB L1，需新增 checker cluster 缓存],
  [日志容量], [`GH_TOTAL_INSTS = 3970`（无字节计量）], [`GH_TOTAL_INSTS = 5000`], [36 KiB 总，3 KiB/checker，5000 inst max], [*性能等效*：5000 inst max 已匹配；36 KiB 字节容量无对应参数，*无法更改*],
)

== 小结

- *完全匹配*：宽度、LQ/SQ、物理寄存器、RAS、L1 DCache、checker ICache。
- *性能等效*：大核/checker 频率与核数、ROB（42 vs 40）、分支预测、L1 ICache（容量）、共享 L2（容量/相联度/延迟）、日志 inst max。
- *无法更改*：IQ 三队列结构、执行单元组合、寄存器 checkpoint、checker 4-stage 流水、checker 共享 16 KiB L1、DRAM 时序、16 MSHRs 与 stride prefetcher、ICache 2-way/1-cycle。

下一批贴近论文的改动：新建 `WithParaMedicTournamentBPD`（2048/8192/2048/2048）、checker cluster 共享 16 KiB L1、L2 的 16 MSHRs 与 stride prefetch、DRAM 时序模型；把 checker 数扩到 12 时需同步更新 `Software/Test` 的 `NUM_CHECKERS`。

