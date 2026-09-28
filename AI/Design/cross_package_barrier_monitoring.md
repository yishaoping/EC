# 跨包覆盖与 L2–DRAM 屏障：对话结论和实现规格

## 1. 文档用途

本文固定当前讨论已经确认的设计口径，供 BOOM DCache、共享 InclusiveCache、
GuardianCouncil traffic-counter ABI 和测试软件共同使用。本文不是仿真结果；源码中
已经加入的是非侵入式监控、桶统计、CDC 聚合和独立打印，不代表真实屏障已经对主路径
施加等待。

当前阶段的目标是：在不因校验水位主动 stall 主流水线的前提下，尽可能捕获并
排队本来需要等待的安全前驱/dirty writeback，同时独立统计三类屏障事件的次数和
理论等待时间。原有统计必须完整保留，新结果只能追加，不能改变旧计数器的语义。

最终计划采用的真实屏障位置是 **L2–DRAM**。当前先按单 BOOM 核、无其他 coherent
core、忽略 probe 干扰的范围实现和评估；不为多核一致性推广设计通用协议。

## 2. 已确认的总体决策

1. 不实现“等待校验水位”的 stall。Store、L1 replacement 和 L2 replacement 不因
   `safePacketWatermark` 停止；已有的 cache 结构冲突和正常 ready/valid 反压不属于
   本文所说的 stall。
2. 需要大容量、有界的待决结构。统计桶保存包序号、事件数和起始周期和；如果实现
   安全前驱数据捕获，功能缓冲还要保存地址、整条 line 数据、包序号和类型。
3. 任一新增桶/缓冲满时不施加兜底 stall。主功能访问继续，允许安全前驱或监控记录
   丢失；必须增加 dropped/overflow 计数，并锁存该类 `stats_valid = 0`，软件明确报告
   本次统计无效。
4. 缓冲溢出时应优先让原有 cache/writeback 路径旁路继续，以保持工作负载的正常
   数据流；丢失的是屏障要求的安全前驱/延后属性，不能静默丢弃最新的架构 dirty
   victim。若某个实现无法做到这一点，必须在代码和打印中单独标为功能性数据丢失。
5. 原有 L1 dirty-writeback 统计（ABI 18--25 等）和原有 L2–DRAM dirty-writeback
   统计（ABI 46--55）继续表示原来的物理握手口径，不覆盖、不改名、不挪索引。
6. 新增三组独立统计和独立软件打印。旧输出仍保留，不能用新统计替换旧的
   `dirty_wb` 或 `l2_dram_dirty_wb` 行。
7. AMO/SC 沿用现有流量统计的资格和真实完成口径：只有实际修改 L1 line 的成功
   操作才可能产生覆盖事件；失败 SC 不产生 line 写入事件。普通 cacheable Store 仍以
   实际 DCache data-array 写入为唯一事件，不按 issue/replay 重复计数。
8. 本阶段不做仿真和硬件生成。代码完成后只允许源码审查、ABI 对照、
   `git diff --check` 和用户允许范围内的 compile-only 检查。

## 3. 机制语义

### 3.1 L1 Store 跨包覆盖

- 同一包内对同一 cache line 的重复推测写可以直接覆盖。
- 新包要写一条仍归属于旧包、且旧包尚未安全的 dirty line 时，真实机制应等待旧包
  进入连续 PASS 水位，把这个最新安全版本送到 L2，再允许新包覆盖 L1。
- 如果旧版本在新 Store 到达时已经安全，真实机制不需要等待水位，但仍应先把安全
  前驱送到 L2。
- 当前非 stall 评估允许新 Store 立即执行；监控在覆盖前读取旧的 line provenance，
  记录旧包序号和起始周期。若实现数据捕获，应保存覆盖前版本，并在旧包安全后释放。

### 3.2 L1–L2 屏障的理论代价

- 安全 dirty victim 可正常写入 L2。
- 未安全 dirty victim 在真实 L1–L2 屏障中应等待其所属包安全后再进入 L2。
- 当前不阻塞 replacement；在 victim 被写回单元接受时记录理论等待。现有 C-channel
  首 beat 握手统计继续按原口径工作。

这一类用于对比两种屏障位置，但不是最终选择的真实屏障。

### 3.3 最终选择：L2–DRAM 屏障

- L1 replacement 可以把推测 dirty line 带入 L2。
- L2 接收新推测版本前，下一层必须保存最近安全前驱。若 L2 原版本已经安全，可以
  把它送往 DRAM；若 L2 原版本仍推测，则应由 L2–DRAM 屏障等待它安全。
- L2 未安全 dirty victim 要离开 L2 时，真实机制在其所属包安全前禁止进入 DRAM。
- 当前不通过水位反压 SourceC/MSHR；在 L2 victim 写回请求第一次可被接受的位置记录
  理论等待，并用大缓冲捕获待决项。缓冲满时旁路原路径、置无效并计数。

整个机制的目标不变量是：推测版本的下一层保存其最近安全前驱。当前统计运行在
溢出后不再保证该不变量，因此软件不得把溢出后的数值当成有效样本。

## 4. “写回实现”和统计实现的边界

统计桶与 line 数据缓冲必须分开：

- **统计桶**按旧包序号聚合 `{count, requestCycleSum}`。同一个包可以有多次事件，
  不需要为每个事件保存一个独立计时器；水位覆盖该包时统一结算。
- **数据缓冲**按 line/版本保存 `{address, data, packetSeq, tracked, kind}`，用于模拟或
  实际发出安全前驱。不同地址可以独立排队，同一地址的多个版本必须保持顺序。

在单核、忽略 probe 的当前范围内，可以采用面向最终 L2–DRAM 方案的专用 sideband
或本地队列，不要求把它推广成通用 TileLink coherence 消息。普通 `ReleaseData` 会
改变 L1 所有权，不能在不额外处理目录语义的情况下直接等同于“L1 保留新版本、只向
L2 复制旧安全快照”。因此：

1. L1 replacement 可以复用原有 Release/writeback 数据路径；
2. L1 resident line 的跨包覆盖快照需要独立捕获/排队语义；
3. 最终功能重点放在 L2–DRAM 待决 writeback；
4. 若某阶段只完成影子排队而未真正注入下一层，打印必须区分“理论可释放”和“物理
writeback 已握手”，不能把前者冒充后者。

当前源码状态：三类事件检测点、按完整包序号的延迟桶、L2 请求点采样、Gray CDC 导出
以及软件排空/打印已经实现；没有新增 ready/valid 反压，也没有实现保存整条 line 数据
并在水位推进后重新发出的功能缓冲。因此新增周期表示“若启用屏障所需等待”的监控值，
旧的实际 C-channel/DRAM writeback 统计仍是唯一物理握手口径。后续若实现 line-data
shadow buffer，必须另加容量丢失计数，不能复用这些桶的 dropped 含义。

不允许统计旁路修改旧物理计数器的含义。物理 C-channel/DRAM handshake 仍由原统计
记录；新增三组只回答“若启用对应约束，多少事件需要等待、等待多久”。

## 5. 三类新增事件的精确定义

### 5.1 类型 A：跨包 Store 覆盖

推荐检测点是 BOOM DCache 中 `dataWriteArb.io.in(0).fire`，使用更新
`dirtyPacketSeq/dirtyPacketTracked` **之前**的 set/way 元数据。

一次事件需同时满足：

```text
measurement_active
&& actual_cache_line_modify
&& new_packet_seq != 0
&& old_line_tracked
&& old_packet_seq != 0
&& new_packet_seq != old_packet_seq
&& old_packet_seq > pre_edge_safe_watermark
```

说明：

- 普通 Store 以真实 data-array fire 计一次，replay/nack 不重复计数。
- 成功 SC、cacheable AMO 若走同一真实 line 修改点并携带有效包序号，则按现有完成
  口径纳入；失败 SC 排除。
- 同包重复写排除。第一次 P2 覆盖后 line provenance 更新为 P2，所以 P2 后续写不会
  再重复产生“覆盖 P1”事件；P3 覆盖 P2 时是新的事件。
- 事件归属于被覆盖的 `old_packet_seq`，因为等待终点由旧版本何时安全决定。
- 使用拍前水位分类；若同拍 checker 结果令旧包进入 `newSafePacketWatermark`，事件
  可以在同拍以 0 周期结算。

延迟定义：

```text
cross_package_wait = cycle(old_packet_seq becomes safe)
                   - cycle(actual modifying write request accepted)
```

### 5.2 类型 B：L1–L2 replacement 屏障

推荐检测点是 L1 replacement writeback 请求被 `BoomWritebackUnit` 接受的 line-level
握手，即 `wbArb.io.out.fire`/`wb.io.req.fire`，而不是稍后的 TL C-channel 首 beat。
当前范围只统计 MSHR replacement/voluntary victim；probe 路径不纳入新增口径。

条件为 dirty victim 带有效 tracked packet sequence，且该序号大于拍前 L1 安全水位。
事件归属于 victim 的包序号。现有 `unverifiedDirtyWbSeen` 在 C-channel 首 beat 统计，
两者是不同事件点，必须同时保留。

延迟定义：

```text
l1_l2_barrier_wait = cycle(victim packet becomes safe)
                   - cycle(replacement writeback request accepted)
```

### 5.3 类型 C：L2–DRAM replacement 屏障

现有 L2 统计在 `sourceC.io.c.fire && c_first`，这是外层 C-channel 已经接受首 beat 的
物理写回点。新增屏障事件应更早，在 SourceC line-level request 第一次可被接受时产生；
建议 Scheduler 导出 `sourceC.io.req.fire` 对应的 dirty/dcache/packet metadata。

条件为 DCache-originated dirty victim，带有效 tracked nonzero packet sequence，且序号
大于 L2 域同步后水位。事件归属于 victim 包序号。

延迟定义：

```text
l2_dram_barrier_wait = l2_cycle(victim packet observed safe in L2 domain)
                     - l2_cycle(SourceC line request accepted)
```

L2 使用自己的 `l2Cycle` 和同步后的 Gray watermark。禁止用 BOOM `csr_cycle` 减 L2
周期；跨时钟域只同步单调计数/水位，不能直接混合两个时间基准。

## 6. 待决桶与结算算法

每类使用独立桶，不能复用原有 dirty-writeback 桶的寄存器和累计值。推荐与当前包
窗口相同的 full-sequence tagged 环形结构，并把容量参数集中定义；初始至少覆盖现有
256-package window。每个槽保存：

```text
valid
packetSeq             // 完整序号，不能只比较低位
count                 // 此旧包对应的待决事件数
requestCycleSum       // 所有事件起始周期之和
```

新事件：

```text
seen += 1
if bucket available:
    bucket.count += 1
    bucket.requestCycleSum += current_cycle
    pending += 1
else:
    dropped += 1
    stats_valid = 0
```

水位推进时，对全部 `packetSeq <= newSafeWatermark` 的槽结算：

```text
resolved += bucket.count
safeCycleSum += current_cycle * bucket.count
requestCycleSumTotal += bucket.requestCycleSum
pending -= bucket.count
clear bucket
```

最终总等待周期为：

```text
waitCycleSum = safeCycleSum - requestCycleSumTotal
averageWaitCycles = waitCycleSum / resolved
```

所有加法、乘法和 pending 减法必须加宽检查。任一溢出、下溢、槽位序号冲突、数据
缓冲丢失、FAIL 或 CANCELLED 都锁存 `stats_valid = 0`。有效样本应满足：

```text
stats_valid == 1
dropped == 0
pending == 0
seen == resolved
safeCycleSum >= requestCycleSumTotal
```

STOP 当拍仍接收事件，STOP 后不再接收新事件，但水位和待决桶继续结算。若统计已经
无效，软件 drain 应立即返回硬错误，不应为了永远不会跨过 FAIL 包的 pending 无限等候。

## 7. 新增 software-visible ABI

旧 ABI 0--106 保持原样。为三类统计各追加 7 项，共 21 项，使总数从 107 增加到
128。建议固定如下：

| 索引 | 名称 | 含义 |
|---:|---|---|
| 107 | `CROSS_PACKAGE_SEEN` | 类型 A 发生次数 |
| 108 | `CROSS_PACKAGE_RESOLVED` | 类型 A 已等到旧包安全次数 |
| 109 | `CROSS_PACKAGE_PENDING` | 类型 A 当前待决次数 |
| 110 | `CROSS_PACKAGE_DROPPED` | 类型 A 桶/数据缓冲丢失次数 |
| 111 | `CROSS_PACKAGE_REQUEST_CYCLE_SUM` | 类型 A 起始周期和 |
| 112 | `CROSS_PACKAGE_SAFE_CYCLE_SUM` | 类型 A 安全周期和 |
| 113 | `CROSS_PACKAGE_STATS_VALID` | 类型 A 有效位 |
| 114 | `L1_L2_BARRIER_SEEN` | 类型 B 发生次数 |
| 115 | `L1_L2_BARRIER_RESOLVED` | 类型 B 已结算次数 |
| 116 | `L1_L2_BARRIER_PENDING` | 类型 B 当前待决次数 |
| 117 | `L1_L2_BARRIER_DROPPED` | 类型 B 桶/数据缓冲丢失次数 |
| 118 | `L1_L2_BARRIER_REQUEST_CYCLE_SUM` | 类型 B 起始周期和 |
| 119 | `L1_L2_BARRIER_SAFE_CYCLE_SUM` | 类型 B 安全周期和 |
| 120 | `L1_L2_BARRIER_STATS_VALID` | 类型 B 有效位 |
| 121 | `L2_DRAM_BARRIER_SEEN` | 类型 C 发生次数 |
| 122 | `L2_DRAM_BARRIER_RESOLVED` | 类型 C 已结算次数 |
| 123 | `L2_DRAM_BARRIER_PENDING` | 类型 C 当前待决次数 |
| 124 | `L2_DRAM_BARRIER_DROPPED` | 类型 C 桶/数据缓冲丢失次数 |
| 125 | `L2_DRAM_BARRIER_REQUEST_CYCLE_SUM` | 类型 C 的 L2 起始周期和 |
| 126 | `L2_DRAM_BARRIER_SAFE_CYCLE_SUM` | 类型 C 的 L2 安全周期和 |
| 127 | `L2_DRAM_BARRIER_STATS_VALID` | 类型 C 有效位 |

因此 `GH_TRAFFIC_COUNTERS` 和 `GHE_TRAFFIC_COUNTERS` 应为 128。硬件 Scala 常量、
C enum、静态断言和所有 Vec/数组宽度必须同步更新。

L2 每 bank 输出类型 C 的 7 个 Gray-coded 本地统计。BOOM tile 聚合时：count、pending
和周期和对各 bank 求和；valid 必须检查“所有 bank 均为 1”，不能把 valid 位求和后直接
当布尔值。

## 8. 软件排空和打印要求

`Software/Test/stat/report.c` 的 STOP 排空条件要追加三类 pending。任一新 dropped
非零或 valid 不是 1，应返回 hard error 并停止等待，而不是超时后才发现无效。

新增独立打印，建议名称：

```text
[BARRIER] cross_package_store ...
[BARRIER] l1_l2_replacement ...
[BARRIER] l2_dram_replacement ...
```

每行至少打印：

```text
seen resolved pending dropped wait_cycle_sum average_cycles status
```

类型 A/B 使用 `BOOM_CORE_FREQUENCY_HZ` 换算 ns，类型 C 使用
`L2_CORE_FREQUENCY_HZ`。只有第 6 节全部有效条件满足，且全局包统计无 FAIL、
CANCELLED、result drop 或算术错误时，才打印平均延迟。`resolved == 0` 应打印
`no_events`，不是除零，也不是统计失败。

原有 `print_dirty_writeback_latency()`、`print_l2_dram_dirty_writeback_latency()` 和
cache hierarchy traffic 表必须继续输出。新增打印不得改变这些旧函数的校验等式。

## 9. 现有源码基础和建议修改点

- `chipyard/generators/boom/src/main/scala/lsu/dcache.scala`
  - `dirtyPacketSeq/dirtyPacketTracked` 已按 L1 set/way 保存 line provenance；
  - store/AMO 数据修改发生在 `dataWriteArb.io.in(0).fire`；
  - replacement 请求经 `wbArb` 进入 `BoomWritebackUnit`；
  - 连续 PASS 水位、包 bitmap 和旧 L1 dirty-writeback 桶已经存在；
  - 新增类型 A/B 必须使用独立桶和计数器。
- `chipyard/generators/boom/src/main/scala/lsu/DirtyWritebackBucket.scala`
  - 可抽象一个通用 barrier latency bucket，或新增独立 Bundle；不能让三类共享状态。
- `chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala`
  - 同时导出 outer C 首 beat 的旧 writeback pulse，以及 SourceC line request
    acceptance 和随请求携带的 packet metadata；两种口径不能混用。
- `chipyard/generators/sifive-cache/design/craft/inclusivecache/src/InclusiveCache.scala`
  - 当前 L2 old stats 在物理 outer C handshake 采样；新增类型 C 从更早请求点采样；
  - 使用同步后的 Gray watermark 和 L2 本地周期；
  - 新建独立 bore 导出 7 项类型 C 统计，旧 10 项不变。
- `chipyard/generators/boom/src/main/scala/common/tile.scala`
  - 同步并聚合各 L2 bank 的新增 Gray counters，写入 ABI 121--127。
- `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala`
  - 追加 107--127 常量、总数 128 和新的 L2 barrier bore 名称。
- `Software/Test/hw/ghe.h`
  - 追加完全一致的 C enum 和 ABI `_Static_assert`。
- `Software/Test/stat/report.c`
  - drain 读取新 pending/dropped/valid；新增三行打印和一致性检查。

现有 16-entry L1→L2 provenance sideband CAM 是旧 L2 attribution 的实现细节，不应被
当作新统计的无限可靠来源。新实现若继续依赖它，必须给覆盖/未命中增加显式诊断；
更稳妥的是让 packet provenance 随内部 line-level request 保持到事件采样点。

## 10. 静态验收清单

1. `git status --short` 确认只修改计划内文件，并保留用户已有的
   `Doc/Run/Run.typ` 修改。
2. Scala 与 C 的计数器数量、索引和名称逐项一致；旧 0--106 数值不变。
3. 类型 A 使用 provenance 更新前值；类型 B/C 在 line request 点而非旧物理首 beat
   点采样。
4. 每类均有独立 seen/resolved/pending/dropped/cycle sums/valid。
5. 事件只在 fire 或等价一次性接受条件上推进，不能在 held valid 的每拍重复计数。
6. L2 CDC 只同步 Gray counter/watermark；valid 聚合使用 all-banks 语义。
7. START/STOP/reset 和同拍 watermark advance 的边界与旧统计一致。
8. 溢出不产生水位 stall，且软件能立即看到 invalid/dropped。
9. `seen == resolved + pending` 只在 dropped 为零、统计有效时要求成立。
10. 运行 `git diff --check`；本阶段不运行仿真，不生成 RTL/硬件。

## 11. 当前未覆盖范围

- 多个 coherent L1、其他核访问同一 line、probe 并发和完整 TileLink ownership 证明；
- 包序号 32-bit 真正回绕；当前沿用测量窗口内不回绕的比较方式；
- 缓冲容量的面积/时序结果；未做硬件生成前只能报告结构规模，不能宣称综合开销；
- 统计等待与最终 CPI 的一一对应。多个等待可能重叠，非 stall 运行也会改变真实启用
  屏障后的 cache replacement 轨迹，因此新增周期是理论阻塞需求，不是精确 CPI 损失。
