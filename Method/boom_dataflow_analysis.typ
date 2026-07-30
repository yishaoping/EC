#set document(title: "基于 Chipyard 的 BOOM 未经校验数据外扩散路径分析", author: "Codex")
#set page(
  paper: "a4",
  margin: (x: 19mm, y: 18mm),
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

// 三种处理优先级：外部副作用、缓存传播、可重放读取。
#let risk-red(body) = highlight(body, fill: rgb("#ffcdd2"))
#let cache-orange(body) = highlight(body, fill: rgb("#ffe0b2"))
#let replay-yellow(body) = highlight(body, fill: rgb("#fff59d"))

#align(center)[
  #text(size: 20pt, weight: "bold")[基于 Chipyard 的 BOOM 未经校验数据外扩散路径分析]
  #v(0.6em)
  #text(size: 11pt, fill: rgb("#455a64"))[面向“Rocket 小核校验 BOOM 大核”的协同工作框架]
]

#v(1.2em)

#table(
  columns: (1.2fr, 3.8fr),
  inset: 6pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  [*分析对象*], [当前仓库中的 `chipyard.v1Config`，hart 0 为 BOOM 大核，hart 1--4 为 Rocket checker],
  [*仓库版本*], [`1c8a00bc4bc9d6630e1b01ccb331dce9afff63f4`],
  [*分析方法*], [基于 Chisel/Scala 源码的静态数据流与协议分析，不代表某次具体 elaboration 后的全部信号名],
  [*文档日期*], [2026-07-30],
  [*核心结论*], [BOOM 的 ROB commit 不等于 Rocket checker 验证通过。#cache-orange[未经验证的普通 store 可先写脏 L1D，再经 `ReleaseData/ProbeAckData` 扩散到 L2/DRAM；SC/cacheable AMO 甚至可能先访问 DCache]；#risk-red[MMIO Put/Atomic 可绕过 cache 直接作用于外设]。],
)

#outline(title: [目录], depth: 3)

= 阅读结论

本文只关心“BOOM 已产生、但 Rocket checker 尚未确认”的数据如何越过 core、tile 和 SoC 边界。普通 load 的返回值、L1D hit response、取指侧输出和 BOOM 内部投机回滚不属于主分析对象。

需要持续关注的外扩散面只有以下几类：

- *#cache-orange[cacheable store/SC/AMO]*：先由 LSU 送入 L1D，形成 dirty line；之后由替换或 coherence probe 触发 `ReleaseData/ProbeAckData`，数据进入 L2，并可能继续写入 DRAM。
- *#risk-red[MMIO store/AMO]*：由 `BoomIOMSHR` 直接生成 TileLink `PutFullData`、`PutPartialData`、`ArithmeticData` 或 `LogicalData`，经 SBUS/CBUS/PBUS 到外设，不经过 L2。
- *#replay-yellow[有副作用的 MMIO read]*：虽然是 `Get`，设备可能在读取时清状态或弹出 FIFO，因此要把第一次返回值作为不可重复输入记录，回滚时不能再次读取；普通 cacheable load 不属于此类。
- *#cache-orange[LR/SC]*：LR 本身不输出写数据，只建立本核 reservation；成功的 SC 是条件 store，按 cacheable store 路径扩散。
- *GuardianCouncil 校验旁路*：`GH_BUF` 把提交信息送往 checker，用于决定上述 store/MMIO 数据何时允许释放；它不是存储数据扩散路径。

颜色图例：#risk-red[红色] 表示必须先挡住、等 checker 通过后才能发出的不可缓存外部写；#cache-orange[橙色] 表示 L1D 及后续缓存层次中的写入、替换、Probe 和写回；#replay-yellow[黄色] 表示不可重复读取，执行一次后保存返回值，重放时复用该值。颜色是处理类别标记，不改变第 0 层的四种输出分类。

本文中的“未经校验”是指对应指令尚未被 Rocket checker 判定通过。对 #cache-orange[普通 store]，这一窗口通常从 BOOM ROB commit 开始；对 #cache-orange[SC/cacheable AMO]，当前 LSU 允许其在物理地址和数据有效后先访问 DCache，以获得成功码或旧值供 ROB 完成，因此风险窗口可能早于该指令的 ROB commit，甚至早于其 GH packet 产生。BOOM 自己的 branch/exception rollback 不能撤销已经写入 L1D、L2、DRAM 或外设的数据。

取指侧、普通 load response 和 load 写回 PRF 均从正文移除。普通 load 仅在可能触发 #cache-orange[dirty victim 替换] 时作为“替换诱因”出现；被写回的数据仍属于更早的 store，而不是 load 自己产生的数据。

= 当前配置与边界

== `v1Config` 实际组成

#table(
  columns: (1.25fr, 1.4fr, 1.15fr, 2.6fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*对象*], [*当前参数*], [*频率*], [*源码依据*]),
  [hart 0], [1 个 Large BOOM], [200 MHz], [`generators/chipyard/src/main/scala/config/RocketConfigs.scala:9`],
  [hart 1--4], [4 个 Rocket checker], [各 100 MHz], [`RocketConfigs.scala:11`、`GH_GlobalParams.scala:5`],
  [SBUS / Inclusive L2], [共享一致性主路径], [200 MHz], [`RocketConfigs.scala:16`、`BusTopology.scala:106`],
  [CBUS / PBUS / MBUS], [外设与内存侧总线], [200 MHz], [`RocketConfigs.scala:17-19`、`BusTopology.scala:95`],
  [GBUS / GAGG], [GuardianCouncil 聚合路径], [100 MHz], [`RocketConfigs.scala:15`、`System.scala:43`],
)

配置混入顺序使 `v1Config` 中的 200 MHz MBUS/PBUS 参数覆盖 `AbstractConfig` 的默认 100 MHz。本文将“当前配置”限定为上述 `v1Config`；若改用其他 Config，bank 数、总线宽度、端口类型和外设集合都可能变化，应以 elaboration 产物重新核对。

=== 两个 tile crossing 分别是什么

这里的 crossing 是“tile 与 uncore 总线之间的时钟/协议边界”，不是 BOOM 与 Rocket 之间的一条核间连线。它统一作用于 tile 的 TileLink master/slave 端口以及需要同步的中断。

- *Rocket crossing*：`WithAsynchronousRocketTiles` 只匹配 `RocketTileAttachParams`，所以 hart 1--4 的 checker Rocket 使用 `AsynchronousCrossing()`。Rocket tile 在 100 MHz 域，默认 master 端连接 200 MHz SBUS，因此边界中需要异步队列和同步器。当前 mixin 虽然接收 `depth`、`sync` 参数，但实现中重新构造的是默认 `AsynchronousCrossing()`；该默认值为 `depth=8`、`sourceSync=3`、`sinkSync=3`。
- *BOOM crossing*：Large BOOM 的 `BoomTileAttachParams` 保留 `RocketCrossingParams()` 默认值，即 `SynchronousCrossing()`。BOOM tile 和 SBUS 都配置为 200 MHz，因此这里没有 200↔100 MHz 的 CDC；crossing 只是 BOOM tile 接入 SBUS 的同步边界。`WithAsynchronousRocketTiles` 不会修改 BOOM 的 crossing。

大小核与共享存储系统的简化连接如下，竖线表示时钟域边界：

```text
200 MHz 域
  [BOOM tile] <-> [SynchronousCrossing] <-> [SBUS] <-> [Inclusive L2] <-> [MBUS]

100 MHz 域                                      200 MHz 域
  [Rocket checker tile] <-> | AsynchronousCrossing | <-> [SBUS] <-> [Inclusive L2]
```

校验旁路还有一处独立 CDC，它不属于上述两个 tile crossing。`GHM` 本体采用 BOOM/hart 0 的 200 MHz 时钟；其内部 `AsyncQueue` 以 BOOM 时钟写入、以各 Rocket checker 的 100 MHz 时钟读出，反向控制则从 100 MHz 回到 200 MHz。因此应按下面的结构理解：

```text
200 MHz 域                                         100 MHz 域
  [BOOM tile] <-> [GH_BUF] <-> [GHM] <-> | GHM AsyncQueue | <-> [Rocket checker tile]
```

也就是说，Rocket checker 同时面对两种不同边界：访问共享总线时经过 Rocket tile 的异步 crossing；接收 BOOM 校验 packet 时经过 GHM 内部 CDC。GBUS 的 100 MHz 时钟主要供 `GAGG` 聚合模块使用，不是 BOOM store 进入 L1D/L2 的数据通道，也不是上述 GHM packet CDC 的替代品。

源码依据：`generators/rocket-chip/src/main/scala/subsystem/Configs.scala:537` 只改 Rocket tile，`RocketSubsystem.scala:11` 定义 crossing 默认值，`diplomacy/ClockDomain.scala:30` 定义异步参数，`subsystem/HasTiles.scala:339` 连接 tile master 与 SBUS；`guardiancouncil/GHM.scala:107`、`:133-187` 实现大小核之间的双向 CDC。

== BOOM 与缓存参数

#table(
  columns: (1.45fr, 1.5fr, 3.45fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*组件*], [*参数*], [*含义*]),
  [Large BOOM], [`decodeWidth=3`], [提交/校验输出是 3 lane；取指宽度和取指侧输出不纳入本校验数据流。],
  [ROB], [`numRobEntries=96`], [ROB index 会回绕，单独记录 `rob_idx` 不能构成全局唯一指令 ID。],
  [LSU], [STQ=24], [#cache-orange[store/SC/cacheable AMO] 主要由 `stq_idx` 跟踪；index 会回绕，必须结合 epoch/inst_seq。],
  [L1D], [128-bit row，64 sets，8 ways，4 MSHR], [#cache-orange[store 可形成 dirty line；后续并发 miss、替换或 Probe 可能触发其外扩散]。],
  [cache block], [64 B], [来自 `CacheBlockBytes` 默认值，是 A/C/B 通道一致性地址关联的基本粒度。],
  [Inclusive L2], [512 KiB，8 ways，1 bank，约 1024 sets], [默认 `WithInclusiveCache` 与 `BankedL2Key.nBanks=1`；sets=512 KiB/(64 B×8)。],
)

参数来源：`generators/boom/src/main/scala/common/config-mixins.scala:177`、`generators/rocket-chip/src/main/scala/subsystem/BankedL2Params.scala:15` 和 `generators/sifive-cache/design/craft/inclusivecache/src/Configs.scala:47`。

== 未经校验数据的总体扩散图

```text
校验旁路（不计入存储扩散层）：
  [BOOM core] -> [GH_BUF] -> [GHM] -> [Rocket checker]

第 0 层：BOOM core 向外输出
  [BOOM core] -> [BOOM DCache]
  [BOOM core] -> [GH_BUF] -> [GHM] -> [Rocket checker]

第 1 层：进入 BOOM tile 的数据侧存储组件
  [BOOM DCache] -> [L1D]
  [BOOM DCache] -> [BoomIOMSHR]

第 2 层：离开 BOOM tile
  [L1D] -> [tile master xbar] -> [SBUS] -> [Inclusive L2]
  [BoomIOMSHR] -> [tile master xbar] -> [SBUS] -> [CBUS]
  [CBUS] -> [CLINT/PLIC]
  [CBUS] -> [PBUS] -> [UART/外设]

第 3 层：离开共享缓存
  [Inclusive L2]
    -> [L2 outer buffer]
    -> [TLCacheCork]
    -> [MBUS]
    -> [TLToAXI4]
    -> [DRAM controller]
    -> [DRAM]
```

图中每一项都只表示组件，不表示握手信号或 TileLink/AXI 消息。MMIO 分支在第 2 层到达设备后结束，不会进入 Inclusive L2；只有设备随后作为新的 bus master 发起 DMA 时，才会形成另一条独立的数据扩散链。`TLFilter(skipMMIO)` 位于 Inclusive L2 前，用于把 DCache 的 MMIO client 排除在缓存层次之外。相关代码位于 `generators/sifive-cache/design/craft/inclusivecache/src/Configs.scala:95`。

= 第 0 层：BOOM core 的对外输出

== BOOM core 的输出分类

- *无需检验*：只服务于正常执行，例如取指、地址翻译。它们不携带 BOOM 要写出的新数据。
- *待检验*：已经送往 Rocket checker、等待比较的输出，例如 `GH_BUF` 产生的 packet。它们的目的就是被检验，不能称为“未检验数据流出”。
- *未检验*：本来需要检查的写入数据，在 checker 确认前已经进入 L1D、共享 cache 或外设。这是本文的主要数据扩散对象。
- *回滚敏感*：这里专指未列入“未检验”写入、但会让 BOOM 回到 checkpoint 后无法得到与第一次执行相同结果的状态或操作。未检验 store/SC/AMO 数据仍归入“未检验”，不在本类重复展开。

#table(
  columns: (1.05fr, 1.7fr, 2.0fr, 2.25fr, 1.55fr),
  inset: 4pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*输出类型*], [*功能类型*], [*从哪里到哪里*], [*主要内容*], [*判定注释*]),
  [无需检验], [取指相关], [`BoomCore` → frontend/ITLB/L1I], [取指地址、redirect、取指控制], [大小核各自取指，不是待检验写数据。],
  [无需检验], [地址翻译], [LSU/TLB → PTW], [虚拟地址、页表请求和访问权限], [服务地址翻译，不直接改变共享数据。],
  [待检验], [校验输出], [`ROB`/`LDQ`/`STQ`/`PRF` → `GH_BUF` → GHM/CDC → Rocket checker], [提交 uop、地址、数据和分支/CSR 等比较信息], [输出的目的就是校验，不属于未检验数据外流。],
  [未检验], [#cache-orange[普通 store]], [STQ → LSU → `dmem.req` → BOOM L1D], [物理地址、对齐后的写数据、size 和 store uop], [checker 确认前可能先形成 dirty line。],
  [未检验], [#cache-orange[成功 SC]], [STQ → LSU → L1D；之后可能经 C 通道扩散], [条件写地址、写数据和成功结果], [成功时是写入；失败 SC 不写数据，但会产生架构结果。],
  [未检验], [#cache-orange[cacheable AMO] / #risk-red[uncached AMO]], [LSU → L1D 或 `BoomIOMSHR` → TileLink manager], [原子操作地址、源操作数和 opcode], [cacheable AMO 修改 line；uncached AMO 必须等待校验。],
  [未检验], [#cache-orange[cache 替换/一致性写回]], [L1D → C ReleaseData/ProbeAckData → L2], [含 dirty line 的 cache line 数据], [通常是先前 store/SC/AMO 数据的继续扩散。],
  [未检验], [#risk-red[MMIO 写]], [LSU → `BoomIOMSHR` → A Put/Atomic → SBUS → CBUS/PBUS/外设], [写地址、写数据、mask 或原子操作], [可能立即修改设备寄存器、清中断或启动 DMA。],
  [回滚敏感], [检查点已有的架构状态], [BOOM core/CSR/RSU → checkpoint → core/checker], [寄存器、PC、CSR、特权级和异常控制状态], [恢复 checkpoint 即可重建，需保证快照完整。],
  [回滚敏感], [#replay-yellow[不可重复的读取操作]], [BOOM LSU/CSR → MMIO manager、设备或计数器 → BOOM core], [#replay-yellow[read-clear、FIFO pop、状态确认，以及 `cycle`/`time`/`instret` 等动态 CSR 的返回值]], [设备状态或时间会随第一次读取改变；备份返回值或虚拟化后再重放。],
  [回滚敏感], [core 内部可重建状态], [TLB、分支预测、L1I、LDQ/STQ/SDQ → core 内部], [翻译、预测、取指缓存、LSU 队列和 store-to-load forwarding 状态], [刷新、清空或重新填充即可重建；不等同于已经写入 L1D 的数据。],
  [回滚敏感], [顺序和刷新控制], [BOOM core/LSU → DCache、DTLB、IFU], [`FENCE`、`SFENCE.VMA`、`FENCE.I` 及相关 force-order/flush 控制], [不携带写数据，但会改变内存顺序、排空在途请求或刷新结构；重放时必须恢复同样的顺序状态。],
  [回滚敏感], [#cache-orange[core 外部的 L1D 本地状态]], [L1D/一致性单元 ↔ BOOM core], [#cache-orange[LR reservation、在途 cache 事务、line 权限/dirty 状态]], [需按状态性质综合备份、排空、失效或刷新；不能只恢复寄存器。],
)

== 未检验数据分析：从 STQ 到 DCache

本节只追踪“未检验写数据”如何离开 BOOM，不讨论 checker 如何生成、传输或比较校验信息。核心入口是 LSU 的 store queue：

```text
STQ 中的 store/SC/AMO
  → LSU 选择 stq_execute_head
  → io.dmem.req.valid
  → io.dmem.req.fire
  → BOOM DCache
      ├─ cacheable：进入 L1D
      └─ uncached/MMIO：进入 BoomIOMSHR
```

数据的起点是 LSU 内部的 STQ。STQ 保存 store 类指令的地址、写数据和 uop；浮点 store 的数据先经 `fp_stdata` 送入 STQ，cache miss 后的写数据还可能暂存在 DCache MSHR 的 SDQ 中。LSU 选择 `stq_execute_head` 对应的 entry，用 `StoreGen` 对写数据进行对齐，然后放到 `io.dmem.req` 上。终点是 BOOM DCache：此时还没有区分普通 cacheable store 和 MMIO，它们进入 DCache 后才分流。

#table(
  columns: (1.5fr, 1.7fr, 3.1fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*信号/字段*], [*通俗含义*], [*为什么要观察*]),
  [`stq_execute_head`], [下一条准备发给 DCache 的 STQ 项], [确定写地址、写数据和 uop 来自哪一项。不要与 GH 路径使用的 `stq_commit_head` 混为一谈。],
  [`commit.arch_valids` / STQ `committed`], [BOOM 自己认为指令可以退休], [用于关联指令顺序；它本身不是外部写数据。],
  [`will_fire_store_commit`], [LSU 本拍选择发送 store 类请求], [表示 LSU 已准备发送，但还不代表 DCache 一定接收。],
  [`dmem.req.valid`], [LSU 已把请求放到接口上], [若 `ready=0`，请求仍停在接口处。],
  [`dmem.req.ready`], [DCache 当前可以接收], [它和 `valid` 同时为 1，请求才真正越过接口。],
  [`dmem.req.fire`], [`valid && ready`], [这是“数据已经离开 LSU、被 DCache 接收”的准确判据，也是第 0 层最重要的观测点。],
  [`dmem.req.bits.addr`], [物理地址 paddr], [决定请求进入 cacheable L1D 还是 uncached/MMIO 路径。],
  [`dmem.req.bits.data`], [经 `StoreGen` 对齐的写数据], [这是可能向外扩散的实际 store payload。],
  [`dmem.req.bits.uop`], [指令类型和控制信息], [其中包含 `mem_cmd`、`mem_size`、`rob_idx` 和 `stq_idx`，用于判断指令类型及关联后续事件。],
)

不同指令在数据流上的分支如下：

#table(
  columns: (1fr, 2.2fr, 2.7fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*指令*], [*数据从哪里到哪里*], [*主要流动内容*]),
  [#cache-orange[普通 store]], [STQ → LSU → `dmem.req` → cacheable L1D], [paddr、对齐后的写数据、size 和 store uop；命中后形成 dirty line。],
  [#cache-orange[SC]], [STQ → LSU → L1D；成功后进入写回/一致性路径], [候选写数据和地址；reservation 有效才真正改写 cache line。],
  [#cache-orange[cacheable AMO] / #risk-red[MMIO AMO]], [LSU → L1D，或 LSU → `BoomIOMSHR` → TileLink manager], [原子读-改-写；cacheable AMO 修改 line，MMIO AMO 直接修改设备状态。],
  [#cache-orange[LR]], [LSU → L1D reservation logic], [只建立 `lrsc_addr/lrsc_count`，不产生本节所追踪的新写数据。],
  [普通 load], [LSU → L1D], [只读数据；若触发替换，后续写回的是已有 dirty line。],
)

#cache-orange[普通 store 进入 cacheable L1D] 后，先是 BOOM 私有 dirty 状态；后续 #cache-orange[L1D 替换、一致性 Probe、硬件预取引发的 miss，或 Fence/flush 导致的排空、失效和显式释放]，都可能使该 dirty line 通过 `C ReleaseData`/`C ProbeAckData` 送到 L2。若地址属于 MMIO，则由 `BoomIOMSHR` 分流到 #risk-red[`PutFullData`、`PutPartialData` 或原子 A 通道]，经 tile xbar、SBUS 和 CBUS/PBUS 到外设。#cache-orange[成功 SC、cacheable AMO 与普通 store] 一样会形成可继续扩散的写数据；失败 SC、LR 和普通 load 不形成新的写数据。

这里需要记录的先后关系是：`STQ → LSU → dmem.req.fire → L1D/MMIO`，以及随后可能发生的 #cache-orange[`L1D dirty line → C 通道 → L2`]。#cache-orange[cache 替换] 的触发者可以是 load、store、硬件预取或其他 miss；Fence/flush 也可能改变在途事务的排空和释放时机。真正被传播的是先前写入 dirty line 的数据，而不是触发替换的 load 或预取本身。

还要注意，#cache-orange[TileLink 的 writeback 以整条 cache line 为单位]，而原始 store 通常只修改其中一个 word 或 byte。同一条脏 line 可能混合已验证数据、未经验证数据和不同检查片段写入的数据。因此不能只保存一个 line-level dirty 位；至少要结合 byte/word mask、store sequence 或 epoch 判断该 line 中哪些字节仍然不能释放。

本节源码入口：`generators/boom/src/main/scala/lsu/lsu.scala:503` 给出 store/AMO 发送条件，`generators/boom/src/main/scala/lsu/dcache.scala:870` 给出 L1D 的 store/AMO 写入，`generators/boom/src/main/scala/lsu/mshrs.scala:391` 给出 uncached/MMIO 状态机。

== 回滚敏感状态与恢复分类

本节讨论的不是数据从哪里流出，而是 BOOM 回到较早 checkpoint 后，之前已经发生的变化能否被正确重建。四类主要状态的处理方式不同，不能只依靠 ROB flush；异步外部事件另行说明。

=== 检查点已有的架构状态

寄存器、PC、CSR、特权级以及异常控制状态本来就是程序架构状态，也是检查点已有的内容。回滚时如果只清空 ROB，却没有把检查点中的这些值整体写回，后续指令自然会从错误的执行起点继续。恢复完整的架构快照，就能让 core 回到同一个架构起点；这些状态也可以作为 Rocket checker 的比较基准。这里的关键是快照要完整，且不同 checkpoint 使用一致的 `inst_seq/epoch`。

=== 不可重复的读取操作

普通 cacheable load 只读取内存，不会因为重放而消耗设备状态；但 #replay-yellow[read-clear 寄存器、FIFO pop、状态确认等 MMIO read] 会在第一次读取时改变设备。回滚后再次访问时，设备已经不是原来的状态，所以单纯恢复 PC 和寄存器不够。

#replay-yellow[`cycle`、`time`、`instret`、`mcycle` 和 `minstret` 等动态 CSR] 也属于不可重复输入：它们的返回值会随着时间或退休进度变化，回滚后重读不一定得到第一次的值。解决方法同样是保存第一次返回值，或者在 checker/重放环境中对这些计数器进行虚拟化。

解决方法是让设备访问只发生一次，并备份设备返回值或等价的操作结果。重放时使用备份值，就不必再次读取设备；如果设备本身不能提供事务撤销，则不能把这类读当作普通 load 处理。

#risk-red[MMIO AMO 不属于本节的黄色“返回值缓存”类别]。它还必须保持“读取旧值、修改设备、返回旧值”的原子性，不能拆成一次可重放的读和一次延后的写，否则设备状态和返回到寄存器的旧值可能不再匹配。因此应把整个 Atomic 请求挡到 checker 通过以后再发出；只有设备提供完整的事务化撤销时，才可采用其他方案。

=== core 内部可重建状态

TLB、分支预测器、L1I，以及 LDQ、STQ、SDQ、live-store mask、branch mask、replay 队列和 store-to-load forwarding 状态，通常不承载必须永久保留的外部数据。回滚后即使它们与第一次执行不同，重新翻译、重新取指、重新分配 LSU 队列和重新训练也能得到可用状态，最多影响时序和性能。

因此刷新对应结构、清除有效位并重新填充即可解决；LDQ/STQ/SDQ 中尚未真正访问 L1D 的项可以直接丢弃并重新分配。若刷新过程中牵涉 dirty 数据或已经握手的总线事务，就不能只按 TLB/L1I 或 LSU 队列处理，而要转入未检验数据或在途事务的恢复流程。

如果 #cache-orange[未经校验的 store 修改了页表 PTE]，问题不能只靠刷新 TLB 解决：刷新只能丢弃旧的翻译缓存，不能恢复已经写入页表内存的 PTE。此时必须同时撤销或隔离页表内存中的未经校验写入，并在之后重新执行 `SFENCE.VMA` 或重新填充 TLB。

=== core 外部的 L1D 本地状态

#cache-orange[L1D 中的 LR reservation、line 权限和 dirty 状态、MSHR/IOMSHR 等状态] 不属于普通寄存器 checkpoint。不能假设 LR 和 SC 一定在同一个检查片段内：`GH_BUF` 按单条指令记录 LR 和 SC，没有 pair ID，检查点可能落在两者之间。LR 会设置并倒计时 `lrsc_addr/lrsc_count`，SC 访问本身以及 coherence 事件都可能清除 reservation；即使失败 SC 没有写入数据，也可能改变 reservation，使回滚后重放得到不同的成功/失败结果。

#cache-orange[L1D 中已经写入的新数据可能被后续替换或 Probe 送到 L2、内存或其他 hart]，普通 core rollback 无法撤回这些数据。一旦 dirty line 已经进入共享 L2，还需要恢复或隔离 L2 directory、其他 hart 的 cache 副本以及对应的版本状态，不能只刷新 BOOM 的 L1D。

这类状态需要组合处理：保存必要的 reservation/事务信息；回滚时排空或取消在途请求；对不能恢复的 line 进行失效、刷新或重新获取；对已经外发的数据使用版本号、epoch 或 undo 记录判断能否接受。仅恢复寄存器、只刷新 TLB，或者只清空 ROB，都不能解决 L1D 和一致性事务造成的问题。

=== 异步中断和定时器事件

异步中断、CLINT 定时器和外部设备事件不是 BOOM 的数据输出，因此不放入 3.1 的输出分类表。但它们可能在回滚窗口内改变 `mip`、异常入口 PC、特权状态或设备状态。回滚后事件的到达时刻可能已经不同，不能简单地把它们当作普通可重放指令；需要在检查点中记录事件边界，或在恢复期间暂存、屏蔽并重新注入这些事件。

源码定位：`generators/boom/src/main/scala/lsu/dcache.scala:661-687` 实现 LR reservation 的建立、倒计时和失效；`generators/boom/src/main/scala/exu/rob.scala:477` 输出 BOOM 原生 rollback；`generators/boom/src/main/scala/common/tile.scala:328` 连接 ARFS/检查点信息。

= 第 1 层：BOOM 请求进入 L1D 或 BoomIOMSHR
LSU 发出的访存请求进入 DCache 后，DCache 再根据物理地址对应的 manager 是否支持 `AcquireBlock` 进行分流。

== 可缓存路径：写入 BOOM 私有 L1D

输入是 LSU 的 `BoomDCacheReq`，主要包含物理地址 `addr`、写数据 `data`、`mem_cmd`、访问大小和 uop；`io.lsu.req.fire` 表示 DCache 接收这一批请求。输出命中时，DCache 先改本核 L1D 的 data array 和 cache metadata；未命中时，MSHR 先取得 cache line 和写权限，replay 后再完成同样的 L1D 写入。

#table(
  columns: (1.35fr, 2fr, 3.15fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*写入或设置情况*], [*判断成功的关键信号*], [*简要过程和后续影响*]),
  [#cache-orange[cacheable STORE]], [`dataWriteArb.io.in(0).fire`，并确认该请求是普通写], [*未检验。* hit 时选中 way；miss 时先由 MSHR refill/取得权限，replay 后写入。该 line 成为之后可能外扩散的 dirty line。],
  [#cache-orange[成功 SC]], [`!s2_sc_fail` 只是成功前提；真正写入仍以 SC 对应的 `dataWriteArb.io.in(0).fire` 为准], [*未检验。* reservation 有效且 block 地址匹配时写 data array，目的寄存器得到成功码 0。],
  [#cache-orange[失败 SC]], [`s2_sc_fail`，并由 DCache response 返回失败码 1], [*回滚敏感。* 不写 data array，但 SC 访问可能清除已有 reservation；回滚后若 reservation 条件不同，重放结果可能改变。],
  [#cache-orange[cacheable AMO]], [AMO 请求对应的 `dataWriteArb.io.in(0).fire`], [*未检验。* `AMOALU` 读取旧值，用源操作数计算新值，再把新值写回同一 line；旧值返回目的寄存器。之后该 dirty line 与普通 STORE 没有区别。],
  [#cache-orange[LR]], [`s2_lr` 且请求 hit/replay 成功，执行 `lrsc_count := lrscCycles-1` 和 `lrsc_addr := block_addr`], [*回滚敏感。* LR 不写新数据，只建立 reservation。若回滚时不恢复或重建它，后续 SC 的成功/失败可能改变。],
)

实际修改 L1D 的最终判据应看 data-array write 的 `fire`，不能只看 `dmem.req.fire`。后者只说明 DCache 接收了请求；请求仍可能 miss、nack 或等待 replay。相关实现位于 `generators/boom/src/main/scala/lsu/dcache.scala:870`。

=== LR/SC 为什么特殊

#cache-orange[LR/SC 除了读写 cache line，还会改 DCache 内的 `lrsc_addr` 和 `lrsc_count`]。LR 建立 reservation；计数器倒计时、同核后续访问、SC 本身以及 coherence 事件都可能清除它。因而失败 SC 虽然没有未检验写数据，却仍是回滚敏感事件。也不能在 checker 通过后重新执行一次 SC 来代替原 SC：等待期间 reservation 可能已经变化，第二次判断不一定得到原来的成功/失败结果。

=== 现有 Rocket checker 实际检查了什么

*#cache-orange[普通 STORE]：* BOOM 的 STQ 输出“64-bit 写数据 + 40-bit 虚拟地址”，`GH_BUF` 将其作为 store packet 送给 Rocket。Rocket checker 不访问自己的 DCache，而是在 LSL 中取出 BOOM packet；它重新计算本条 STORE 的有效虚拟地址和源写数据。`lsl_req_cmd=2` 时，`R_ELU` 比较地址，并按访问 size 截取后比较有效写数据。因此当前能检查虚拟地址和有效数据，但没有显式比较物理地址、byte mask，也不观察 BOOM 是否真的写入 L1D。

*#cache-orange[SC]：* BOOM 将 SC 标为 `is_amo`，packet 高 64 bit 放 SC 的目的寄存器结果，也就是通常所说的 0/1 成功码；低 64 bit 放地址。SC 的源写数据没有进入 packet。Rocket 的 SC 被编码为 `lsl_req_cmd=3`，而 `R_ELU` 只在 `cmd=2` 时启用 store 数据比较，所以当前只比较 SC 地址，并直接采用 BOOM 给出的 0/1 结果。它不独立重建 reservation、不比较 SC 写数据，也不确认成功 SC 是否真的写入 L1D。

*#cache-orange[cacheable AMO]：* BOOM packet 同样只携带“AMO 返回的旧值 + 地址”，不携带源操作数、AMO opcode 或最终写值。Rocket 对 AMO 的 `lsl_req_cmd` 也是 3，当前路径只检查地址并采用 BOOM 返回的旧值；没有独立检查原子运算类型、源操作数、最终新值和真实 L1D 写入。因此文档后面所说的“AMO 未检验数据”是指现有 checker 尚不能证明这些写入内容正确。#risk-red[uncached/MMIO AMO] 的校验字段限制相同，但属于红色外部副作用类别。

*#cache-orange[LR]：* LR packet 携带地址和 BOOM 返回的数据。Rocket 当前检查地址并使用 BOOM 返回值，但 checker DCache 被关闭，没有用自己的 `lrsc_addr/lrsc_count` 建立一份独立 reservation。LR 的 reservation 变化仍需要额外 sideband 或 shadow state 才能完整验证。

上述 packet 组织见 `generators/boom/src/main/scala/trans/GH_BUF.scala:119`，Rocket 的 DCache 关闭与请求分类见 `generators/rocket-chip/src/main/scala/rocket/RocketCore.scala:1482`、`:1523`，实际比较条件见 `generators/rocket-chip/src/main/scala/r/R_ELU.scala:63`。

== 不可缓存路径：进入 BoomIOMSHR

地址不支持 `AcquireBlock` 时，`BoomMSHRFile` 不分配普通 cache MSHR，而是把请求交给 `BoomIOMSHR`。`BoomIOMSHR.io.req.fire` 表示该本地状态机接收并保存 `BoomDCacheReq`；它的输出是随后生成的 TileLink A 通道 `mem_access`。这里没有 L1D dirty 暂存窗口。

#table(
  columns: (1.4fr, 2fr, 3.1fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*不可缓存操作*], [*判断请求/响应成功的信号*], [*简要过程和后续影响*]),
  [#risk-red[uncacheable STORE]], [`io.mem_access.fire` 表示 A 请求已发出；匹配 source 的 `io.mem_ack.valid` 表示 D 响应返回], [*未检验。* 生成 `PutFullData` 或 `PutPartialData`，携带地址、data、mask 和 size。它不改 L1D，下一层会直接把请求送往目标 manager。],
  [#risk-red[uncacheable AMO]], [`io.mem_access.fire`；随后等待匹配 source 的 `io.mem_ack.valid`], [*未检验。* 生成 `ArithmeticData` 或 `LogicalData`。目标 manager 原子读取旧值并写入新值，旧值经 D 通道返回；已经发生的原子修改不能由 core rollback 撤销。],
  [#replay-yellow[有副作用的 uncacheable 读]], [`Get` 的 `io.mem_access.fire`；D 返回后 `io.resp.fire` 把数据交回 LSU], [*回滚敏感。* read-clear、FIFO pop、PLIC claim 等读取可能在第一次执行时已经改变设备，回滚后不能重新读取出原值。],
  [无副作用的 uncacheable 读], [`io.mem_access.fire`、匹配 D response 和最终 `io.resp.fire`], [*无需检验。* 它不产生 BOOM 新写数据，也通常可重复；返回数据仍通过 GH packet 提供给 checker。],
  [uncacheable SC], [`BoomIOMSHR` 中存在 `req.uop.mem_cmd =/= M_XSC` assertion], [当前实现不支持 SC 走不可缓存路径，不能把它列为合法的 MMIO 写事务。],
)

这里必须区分“请求已经发出”和“操作成功”：`mem_access.fire` 表示请求已被下游 TileLink 网络接受，从 BOOM 角度已不能取消；匹配的 D response 才表示 manager 已响应。严格的成功判断还应检查 D 通道 `denied=0`、`corrupt=0`，但当前 `BoomIOMSHR` 状态机只使用 `mem_ack.valid`，没有显式检查这两个错误位。

不可缓存操作沿用上一节所述 checker packet。#risk-red[普通 MMIO STORE] 可以比较虚拟地址和有效写数据，但不能证明设备只执行一次；#risk-red[uncached AMO] 仍只检查地址并采用 BOOM 返回值；MMIO 读也不会由 Rocket 再访问一次设备，而是使用 BOOM 传来的返回数据。对 #replay-yellow[有副作用的读] 来说，“只执行一次”是正确方向，但还需要保存返回值和事件序号，才能在回滚重放时复用同一次读取结果。

源码依据：`generators/boom/src/main/scala/lsu/mshrs.scala:391` 定义 `BoomIOMSHR`，`:425` 生成 Get/Put/Atomic，`:551` 判断 cacheable，`:732` 分配不可缓存请求。

= 第 2 层：L1D 到 L2，BoomIOMSHR 到外设

这一层的两条路径已经分开：可缓存数据使用一致性 C 通道进入 L2；不可缓存请求使用 A 通道，经 SBUS 按地址到达 CBUS/PBUS 上的 manager。MMIO 不先进入 L2，也不会由 L2 再转发到外设。

== 可缓存路径：dirty line 从 L1D 进入 L2

第 1 层中的 #cache-orange[成功 SC 和 cacheable STORE/AMO] 一旦写入同一 cache line，在这一层就不再需要区分指令类型。L1D 输出的是整条 dirty line；它可能同时包含多条 STORE/SC/AMO 的结果，甚至混合不同检查片段的数据。

输入是 #cache-orange[L1D 中的 dirty victim 或 L2 发来的 `Probe`]。输出是 TileLink C 通道的 #cache-orange[`ReleaseData` 或 `ProbeAckData`]。只有这两种带 data 的消息会传播先前写入的未检验值。

#table(
  columns: (1.4fr, 2.1fr, 3fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*触发情况*], [*判断数据离开/到达的信号*], [*传播路径和后续影响*]),
  [#cache-orange[L1D 替换 dirty victim]], [L1 侧 `tl_out.c.fire` 且 opcode 为 `ReleaseData`；L2 侧 `io.in.c.fire`], [*未检验数据继续扩散。* `WritebackUnit → C ReleaseData → tile xbar → SBUS → L2 SinkC/BankedStore`。输出为 64 B cache line 的多个 beat。],
  [#cache-orange[收到 coherence Probe]], [`tl_out.b.fire` 接收 Probe；随后 `tl_out.c.fire` 且 opcode 为 `ProbeAckData`；L2 `io.in.c.fire` 接收], [*未检验数据继续扩散。* `L2 SourceB → L1D Prober/WritebackUnit → C ProbeAckData → L2 SinkC`。其他 hart 请求同一 block 时可能触发此路径。],
  [#cache-orange[替换 clean line]], [`tl_out.c.fire`，但 opcode 为无数据的 `Release`/`ProbeAck`], [不携带 BOOM 写入的新值，不属于未检验数据外扩散。],
  [#cache-orange[cache miss 获取 line/权限]], [L1 A `AcquireBlock/AcquirePerm.fire`，随后 D `GrantData/Grant.fire`], [A 请求本身不携带当前 STORE 的新数据；它只取得 line/权限。真正的新值要等 replay 写入 L1D，再由前两行的 C data 消息扩散。],
)

#cache-orange[L2 `SinkC` 接收后，数据已经从 BOOM 私有状态变成共享 cache 状态；L2 还可能通过 `SourceD` 的 `GrantData` 把该 line 提供给另一个 L1]。这时即使 DRAM 尚未更新，其他 hart 也可能已经看到未检验值。

#cache-orange[cache 替换] 可能由后续 load、store、硬件预取、Fence/flush 或其他 miss 诱发，但它们只是触发者。真正被 C 通道传播的是 victim line 中更早写入的 dirty data。当前硬件不会用 Rocket 再比较一次 `ReleaseData`；checker 比较的是第 1 层的指令事件，本层需要做的是检查该 line 是否仍含未验证写入，并决定是否允许它离开 L1D。

源码依据：`generators/boom/src/main/scala/lsu/dcache.scala:24` 构造 writeback 数据，`:778` 连接 Probe，`:820` 仲裁 C 通道；`generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala:52` 连接 `SinkC`。

== 不可缓存路径：BoomIOMSHR 经 SBUS 到外设

`BoomIOMSHR` 的 `mem_access` 先和普通 MSHR 的请求仲裁，共用 DCache TileLink A 通道离开 tile。之后 SBUS 根据地址选择 manager：CLINT、PLIC、BootROM 和 debug 等通常在 CBUS；UART 等低速外设在 PBUS，所以要继续经过 `CBUS → PBUS`。如果以后直接在 SBUS 挂 manager，请求会在 SBUS 处直接终止。

本部分的输入是 `BoomIOMSHR` 生成的 A 通道 address/data/mask/opcode，输出是目标设备 manager 接收的 A 请求；反向输入则是设备返回的 D `AccessAck` 或 `AccessAckData`。

#table(
  columns: (1.4fr, 2.1fr, 3fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*操作*], [*关键输出和完成信号*], [*具体路径和影响*]),
  [#risk-red[MMIO STORE]], [A `PutFullData/PutPartialData.fire`；完成看匹配的 D `AccessAck` 且 `denied=0`], [*未检验。* `BoomIOMSHR → DCache tl_out.a → tile xbar → SBUS → CBUS[/PBUS] → device`。A 请求携带 address/data/mask，manager 接收后可能立即改设备寄存器。],
  [#risk-red[uncached AMO]], [A `ArithmeticData/LogicalData.fire`；完成看 D `AccessAckData` 且无 denied/corrupt], [*未检验。* 路径与 MMIO STORE 相同，但 manager 必须把“读旧值、计算、写新值、返回旧值”作为一次原子事务；core rollback 不能撤销已经完成的原子修改。],
  [#replay-yellow[有副作用 cacheable 读]], [A `Get.fire`；D `AccessAckData` 返回旧值；IOMSHR 最终 `io.resp.fire`], [*回滚敏感。* 同一路径到 read-clear/FIFO/claim manager。副作用可能在设备接受读取时发生，D 返回只是把结果送回 BOOM，不能撤销第一次读取。],
  [无副作用 cacheable 读], [A `Get.fire` 和 D `AccessAckData.fire`], [*无需检验。* 沿相同总线路径读取设备；若寄存器可重复读取，则不属于未检验写数据扩散。],
)

被 A 仲裁器选中时，`BoomIOMSHR.io.mem_access.fire` 与 DCache `tl_out.a.fire` 对应同一笔 A 事务。DCache node 之后还有 width widget、tile xbar、crossing 和可能的 buffer，所以不能假定 DCache、SBUS 与目标设备侧在同一周期握手。真正判断设备事务成功，应观察目标 manager 接收请求以及无错误的 D response。InclusiveCache 前的 `TLFilter(skipMMIO)` 会排除 DCache MMIO client，因此这条路径不经过 L2。

#risk-red[MMIO Put/Atomic] 没有 L1D 的私有暂存阶段。请求一旦被 TileLink 网络接受，就可能很快产生发送字符、清中断、改变计时器或启动设备等不可逆结果，所以 validation gate 应放在 IOMSHR 发出 A data-op 之前，而不能等请求到 SBUS 后再阻止。

源码依据：`generators/boom/src/main/scala/lsu/mshrs.scala:734` 仲裁普通 MSHR 与 IOMSHR，`generators/boom/src/main/scala/lsu/dcache.scala:776` 连接 A 通道，`generators/boom/src/main/scala/common/tile.scala:133` 连接 tile xbar；`generators/rocket-chip/src/main/scala/subsystem/BusTopology.scala:96` 给出 `SBUS → CBUS → PBUS`。

= 第 3 层：L2 经 MBUS 到 DRAM

第 3 层只对可缓存分支构成正常的下一层。输入是 #cache-orange[Inclusive L2 中的 dirty line]；输出是 #cache-orange[送往 backing memory 的写事务]。不可缓存/MMIO 分支通常已经在第 2 层的目标设备处结束，不会再经过 L2 和 MBUS。

== 可缓存路径：dirty line 写入 backing memory
数据先保存在 L2 `BankedStore`；只有 L2 自己需要替换或释放这条 dirty line 时，`SourceC` 才向外输出 `ReleaseData`。`TLCacheCork` 将末级一致性消息转换成 backing memory 可处理的请求，再经 MBUS 和 `TLToAXI4` 到达 DRAM controller。

#table(
  columns: (1.45fr, 2.05fr, 3fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*第 3 层事件*], [*判断输出/完成的信号*], [*简要过程和后续影响*]),
  [#cache-orange[L2 替换 dirty line]], [L2 `io.out.c.fire` 且 opcode 为 `ReleaseData`], [若 line 仍含未验证写入，则是*未检验数据继续扩散*。`SourceC` 从 `BankedStore` 逐 beat 读出数据，送往 outer buffer 和 `TLCacheCork`。],
  [#cache-orange[产生 DRAM 写地址]], [AXI `AW.fire`], [`TLToAXI4` 输出写地址、ID 和 burst 属性。此时 controller 已接受地址，但还不能说明全部数据都已到达。],
  [#cache-orange[传输 dirty data]], [每个 AXI `W.fire`；最后一拍同时满足 `last`], [W 携带 data、byte strobe 和 last。所有 W beat 完成后，未经校验数据已经被 DRAM controller/backing-memory interface 接收。],
  [#cache-orange[写事务完成]], [AXI `B.fire` 且 `resp=OKAY`], [表示外部 memory interface 报告写完成；BOOM 的 ROB flush 或 L1D invalidate 已无法撤销该写。],
  [#cache-orange[L2 替换 clean line]], [outer 消息不带 data], [没有 BOOM 新写值，不属于本文的未检验数据扩散。],
)

源码依据：`generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala:38` 连接 `SourceC`，`generators/sifive-cache/design/craft/inclusivecache/src/Configs.scala:103` 连接 outer buffer 和 `TLCacheCork`，`generators/rocket-chip/src/main/scala/subsystem/Ports.scala:86` 连接 MBUS、`TLToAXI4` 和 `memAXI4Node`。

= 必须校验后才能继续的操作

#table(
  columns: (1.6fr, 2.05fr, 3.15fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*必须等待校验的操作*], [*阻断点*], [*原因与处理要求*]),
  [#risk-red[uncacheable STORE]], [`BoomIOMSHR.mem_access.fire` 前], [这两个操作直接控制外设，都涉及无法挽回的问题],
  [#risk-red[uncacheable AMO]], [A `ArithmeticData/LogicalData.fire` 前], [隔离屏障可以与其他区别开来，单独设置],
)


= 缓存层次中的数据传播操作
这类操作发生在 BOOM 私有 L1D、一致性网络、共享 L2 和 backing memory(DRAM) 之间。普通缓存能够暂时容纳数据，但“进入 L1D”不等于安全：替换或 Probe 随时可能把含未校验字节的整条 line 送往 L2、其他 hart 或 DRAM。

#table(
  columns: (1.65fr, 2.1fr, 3.05fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*缓存相关操作*], [*关键观察信号*], [*数据/状态变化及控制要求*]),
  [#cache-orange[SC、cacheable STORE/AMO 写 L1D]], [`!s2_sc_fail`、`dataWriteArb.io.in(0).fire`], [命中或 miss replay 后改 data array 并形成 dirty line。至少关联 `inst_seq/epoch + block address + byte mask`。],
  [#cache-orange[miss/refill/权限获取]], [A `AcquireBlock/AcquirePerm.fire`，D `Grant/GrantData.fire`，replay], [请求本身不带新 store 数据，但可触发 victim 替换，并决定后续写入何时完成。],
  [#cache-orange[L1D dirty 替换]], [L1 `tl_out.c.fire` 且为 `ReleaseData`], [以整条 cache line 多 beat 外发；需在 C 通道前检查该 line 是否仍含未通过校验的 byte/epoch。],
  [#cache-orange[coherence Probe]], [B `Probe.fire`，随后 C `ProbeAck/ProbeAckData.fire`], [`ProbeAckData` 可把未校验 dirty line 送入 L2；无数据的 `ProbeAck` 仍会改变 line 权限和一致性状态。],
  [#cache-orange[L2 接收与对其他 hart 供数]], [L2 `io.in.c.fire`；对外 D `GrantData.fire`], [数据进入共享 L2 后，其他 hart 可能在 DRAM 更新前读到它。必须避免 checker 从同一未校验版本自我取证。],
  [#cache-orange[L2 dirty 替换]], [L2 `io.out.c.fire` 且为 `ReleaseData`], [数据离开 L2，经 `TLCacheCork → MBUS → TLToAXI4` 向 backing memory 扩散。],
  [#cache-orange[DRAM 写事务]], [AXI `AW.fire`、各拍 `W.fire`/`last`、最终 `B.fire` 且 `OKAY`], [W 被接收后 core/L1 rollback 已不能撤销；B 成功表示 backing-memory interface 报告该写完成。],
)

若允许未校验值先写 L1D，单个 line-level dirty 位不够，因为一条 64 B line 可混合多个 epoch 和已/未校验字节。至少需要 byte/word mask、epoch、版本所有者和 undo/old-data；更简单的设计是在 L1D data-array write 前设置 store gate，校验通过后再写入。无论选哪一种，都要同时约束替换与 `ProbeAckData`，否则数据仍可绕过正常 eviction 提前流出。

= 可通过备份解决的操作

#table(
  columns: (1.65fr, 2.1fr, 3.05fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*不可重复输入*], [*执行/记录点*], [*缓存内容与重放方式*]),
  [#replay-yellow[LR/SC reservation]], [`s2_lr`、`s2_sc_fail`、`lrsc_addr/lrsc_count` 的设置、倒计时和清除], [它是 L1D 本地回滚状态，不是 dirty-data 写回。检查点跨越 LR/SC 时，需要保存/重建 reservation 或定义重放规则。],
  [#replay-yellow[uncacheable 读]], [A `Get.fire`，D `AccessAckData.fire`], [见下],
)

针对 uncacheable 读，只读部分可以不必备份；无其他修改部分理论上不需要备份；其余都应该备份。但是工程上不如都备份一遍？

*确认一下CSR作为快照只需要复原到当时那刻就好，没有什么其他隐藏需求。*


