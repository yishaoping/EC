#set document(
  title: "BOOM/Rocket AMO 双路径追踪与 GHE 计数接口",
  author: "Chipyard GuardianCouncil 工作记录",
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
  #text(size: 19pt, weight: "bold")[BOOM/Rocket AMO 双路径追踪与 GHE 计数接口]
  #v(0.5em)
  #text(size: 10.5pt, fill: rgb("#455a64"))[Chipyard 中“BOOM 大核执行、Rocket 小核校验”的协同工作框架]
]

#v(0.8em)

本文记录在既有 store/load、LR/SC 统计协议上增加 AMO 统计的软硬件修改。统计范围是 BOOM 主核在检查窗口内完成的 AMO，以及 Rocket checker 对同一 AMO 的重执行完成。本文不讨论仿真、Chisel elaboration、Verilog 生成或其他硬件生成过程。

当前协议采用与既有 LR/SC 相同的“完成”口径，而不是请求入口、MSHR 分配或总线事务数量。AMO 的 9 种 `M_XA_*` 命令聚合到同一类，再按访问是否可缓存拆成两个子计数器：

```text
BOOM AMO
  -> LSU/DCache response 完成
       ├─ cacheable   -> amo_cache
       └─ uncacheable -> amo_uncache

Rocket checker AMO
  -> LSL response 有效 + WB 完成
       ├─ packet cacheability = 1 -> amo_cache
       └─ packet cacheability = 0 -> amo_uncache
```

#outline(title: [目录], depth: 3)

= 第一章：AMO 语义和统计口径

== 1.1 AMO 与普通访存、LR/SC 的区别

RISC-V AMO 同时读取旧值、执行运算、写入新值，并把旧值返回到目的寄存器。Rocket-Chip 的 `isAMO(cmd)` 覆盖以下 9 个 memory command：

#table(
  columns: (1.45fr, 2.2fr, 2.75fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*类别*], [*命令*], [*含义*]),
  [逻辑交换], [`M_XA_SWAP`], [AMOSWAP，交换旧值和源操作数。],
  [逻辑运算], [`M_XA_XOR`, `M_XA_OR`, `M_XA_AND`], [AMOXOR、AMOOR、AMOAND。],
  [算术加法], [`M_XA_ADD`], [AMOADD。],
  [有符号比较], [`M_XA_MIN`, `M_XA_MAX`], [AMOMIN、AMOMAX。],
  [无符号比较], [`M_XA_MINU`, `M_XA_MAXU`], [AMOMINU、AMOMAXU。],
)

`M_XLR` 和 `M_XSC` 不属于 `isAMO` 的 9 个命令。LR/SC 继续使用原有索引 `7..9`，不会因为它们也使用 LDQ/STQ 或同时具有读写属性而混入 AMO。普通 LOAD/STORE 也必须继续使用精确的 `M_XRD`/`M_XWR` 判定。

当前接口按 AMO 总类统计，不再把 9 个 opcode 分别暴露为 9 组计数器。这样 BOOM 和多个 Rocket checker 能共享与 store/load、LR/SC 一致的固定索引协议；若未来需要 opcode 级分析，应作为独立扩展，不应改变下面 3 个索引的含义。

== 1.2 完成口径

AMO 的统计点是架构结果已经返回、并且该请求没有被 kill 或 replay 隐藏的完成点。下列事件不直接计数：

- LSU 请求 `valid`，但 DCache 尚未接受；
- cacheable miss 的普通 MSHR 分配、refill 或 replay；
- uncacheable AMO 的 IOMSHR 分配；
- TileLink A 通道仅保持 `valid` 而没有 `fire`；
- checker 的 LSL 请求入队或被 replay 的 WB。

BOOM 以 AMO response 到达 LSU 为完成，Rocket 以 checker 模式下 `LSL response valid` 与 `WB` 成功交汇为完成。两条路径发生在不同 hart、不同时间，不能把同一条 AMO 的 BOOM 事件和 checker 事件相加为一个 hart 的统计值。

== 1.3 三项软件可见计数器

原有 store/load/LR/SC 索引 `0..9` 保持不变，AMO 追加到 `10..12`：

#table(
  columns: (0.7fr, 1.7fr, 2.55fr, 2.15fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*索引*], [*名称*], [*BOOM 主核*], [*Rocket checker*]),
  [10], [`amo_out`], [检查窗口内完成的一条 AMO response。], [checker 完成的一条 AMO WB/LSL 事务。],
  [11], [`amo_cache`], [AMO 完成且请求被 TileLink manager 判定为 cacheable。], [AMO 完成且 LSL 返回的 cacheability 位为 1。],
  [12], [`amo_uncache`], [AMO 完成且请求被判定为 uncacheable。], [AMO 完成且 LSL 返回的 cacheability 位为 0。],
)

基本不变量为：

```text
amo_out = amo_cache + amo_uncache
```

`amo_cache` 和 `amo_uncache` 对同一个完成事件互斥；一个 AMO 最多消耗其中一个计数脉冲。该协议不把 AMO 的“旧值返回”和“新值写入”拆成两个指令数。

= 第二章：BOOM 主核的 AMO 路径

== 2.1 请求分流

BOOM LSU 将 AMO 请求送到非阻塞 DCache。AMO 同时满足 `isRead` 和 `isWrite`，因此不能用普通 LOAD/STORE 的宽泛谓词直接统计：

```text
BOOM LSU
  -> io.dmem.req.fire
  -> DCache
       ├─ cacheable hit
       │    └─ AMOALU -> dataWriteArb -> L1D data array
       ├─ cacheable miss
       │    └─ 普通 cache MSHR -> refill/replay -> AMOALU -> L1D
       └─ uncacheable
            └─ BoomIOMSHR -> TileLink ArithmeticData/LogicalData
```

cacheable miss 的第一次请求和最终 replay 属于同一条 AMO。统计不在 MSHR allocate 处增加，而是在 response 完成处增加，从而与 checker 的一条架构 AMO 对齐。uncacheable AMO 经过 `BoomIOMSHR` 的 `s_mem_access`、`s_mem_ack` 和 `s_resp` 状态后，response 才到达 LSU。

== 2.2 命令精确判定和去重

LSU 在 STQ response 分支使用以下条件识别 AMO：

```scala
val count_amo = io.dmem.resp(w).bits.traffic_check &&
  !stq(stq_idx).bits.traffic_seen &&
  rocket.isAMO(io.dmem.resp(w).bits.uop.mem_cmd)

io.dmem.traffic_amo_cache_complete(w) :=
  count_amo && io.dmem.resp(w).bits.traffic_cacheable
io.dmem.traffic_amo_uncache_complete(w) :=
  count_amo && !io.dmem.resp(w).bits.traffic_cacheable
```

`traffic_check` 确认该 response 属于 BOOM 检查窗口，`traffic_seen` 防止同一 STQ entry 的有效 response 重复计数。nack、MSHR allocate 和尚未返回的 replay 不会产生 AMO 完成脉冲。响应完成后，STQ entry 被标记为 `succeeded`，其 `traffic_seen` 也被置位。

这里使用 `rocket.isAMO` 而不是 `uop.is_amo`：后者是 BOOM 微操作属性，可能同时标记 LR/SC；前者只匹配 9 个 `M_XA_*` memory command，能阻止 SC 混入 AMO。

== 2.3 DCache 计数器和总数构造

LSU 为每个 memory lane 输出互斥的 `traffic_amo_cache_complete` 和 `traffic_amo_uncache_complete` 脉冲。`BoomNonBlockingDCacheModule` 用 `PopCount` 累加：

```scala
when (completed_amo_cache.reduce(_|_)) {
  amo_cache_count := amo_cache_count + PopCount(completed_amo_cache)
}
when (completed_amo_uncache.reduce(_|_)) {
  amo_uncache_count := amo_uncache_count + PopCount(completed_amo_uncache)
}

io.traffic_counter := VecInit(Seq(
  // ... existing store/load/LR/SC indices 0..9 ...
  amo_cache_count + amo_uncache_count,
  amo_cache_count,
  amo_uncache_count))
```

计数器实际保存于 BOOM DCache，而不是同时在 LSU、tile 和 GHE 中重复保存。DCache 只输出最终向量；后续 BOOM tile、RoCC command router 和 GHE 负责传输与读回。

== 2.4 cacheability 的判定和传播

BOOM DCache 在入口使用物理地址和 TileLink manager 能力判断是否可缓存：

```scala
edge.manager.supportsAcquireBFast(
  addr, lgCacheBlockBytes.U)
```

判定结果锁存到 `traffic_cacheable`，并随 `BoomDCacheReq` 经过普通 MSHR、replay、IOMSHR 和 response 传播。支持 cache-block acquire 的访问进入 cacheable 路径；不支持的访问进入 IOMSHR。不能在 response 阶段重新采样当前流水线的 cacheability 信号，否则 miss/replay 可能分类错误。

该属性表示 TileLink manager 是否支持 L1 cache block acquire，不是根据虚拟地址范围猜测，也不是根据“AMO 是否写入 data array”反推。cacheable AMO miss 最终仍归入 `amo_cache`；uncacheable AMO 即使总线目标是内存，也归入 `amo_uncache`。

= 第三章：Rocket checker 的重执行路径

== 3.1 AMO packet 的数据布局

BOOM 将提交给 checker 的访存包放入 GH buffer。普通 LOAD/STORE 的 128 位 payload 已使用 bit 63 携带 cacheability；AMO 原本的特殊 payload 只携带架构结果和地址，因此需要补上同一元数据：

```scala
// AMO/SC packet
Cat(io.gh_prfs_rd(i), io.commit_cacheable(i), io.alu_in(i)(62, 0))
```

其布局为：

```text
127                    64 63 62                    0
+------------------------+--+-----------------------+
| architectural result   | C|       address[62:0]   |
+------------------------+--+-----------------------+
```

其中 `C=1` 表示 cacheable，`C=0` 表示 uncacheable。`commit_cacheable` 由 BOOM tile 根据提交访存的物理地址和同一个 TileLink manager 能力函数得到。当前 checker 地址比较只需要物理地址低 40 位，因此 `R_LSL` 显式使用 `out_packet(39, 0)`，并把 `out_packet(63)` 单独输出为 `resp_cacheable`。这样 cacheability 不会污染地址比较。

== 3.2 RocketCore 完成判定

Rocket checker 的共同完成条件是：

```scala
val checker_mem_complete =
  (checker_mode.asBool || checker_priv_mode.asBool) &&
  wb_valid && wb_ctrl.mem && lsl_resp_valid && !lsl_resp_replay
```

随后用精确命令识别 AMO：

```scala
val checker_amo_complete =
  checker_mem_complete && isAMO(wb_ctrl.mem_cmd)
val checker_amo_cache_complete =
  checker_amo_complete && lsl_resp_cacheable
val checker_amo_uncache_complete =
  checker_amo_complete && !lsl_resp_cacheable
```

`wb_valid` 已排除 WB replay、异常和检查异常；`lsl_resp_valid` 确认当前 WB 具有对应 LSL 结果；`!lsl_resp_replay` 排除 LSL 尚未完成而需要重新取包的周期。计数发生在完成条件成立的周期，而不是 LSL 请求入队周期。

== 3.3 R_ICSL 计数和复位

Rocket checker 将两个分类完成脉冲接入 `R_ICSL`：

```scala
icsl.io.amo_cache_deq   := checker_amo_cache_complete
icsl.io.amo_uncache_deq := checker_amo_uncache_complete
```

`R_ICSL` 保存两个 64 位寄存器，并在 `debug_perf_reset` 有效时清零：

```scala
debug_perf_num_amo_cache := Mux(
  io.debug_perf_reset.asBool, 0.U,
  debug_perf_num_amo_cache + io.amo_cache_deq)
debug_perf_num_amo_uncache := Mux(
  io.debug_perf_reset.asBool, 0.U,
  debug_perf_num_amo_uncache + io.amo_uncache_deq)
```

AMO 总数由两个子计数器相加得到，不另设一个可能与分类项漂移的独立累加器。Rocket 的输出向量顺序与 BOOM 完全一致。

= 第四章：GHE、跨 tile 传输和软件接口

== 4.1 固定索引协议

统计向量长度集中定义为 `GH_GlobalParams.GH_TRAFFIC_COUNTERS = 13`。旧索引 `0..9` 保持原含义，新增 AMO 索引位于末尾：

```text
0..2   store_total, store_cache, store_uncache
3..6   load_total, load_cache, load_uncache, load_forward
7..9   lr, sc_success, sc_fail
10..12 amo_out, amo_cache, amo_uncache
```

GHE 使用既有 `funct=0x7B` 指令读回统计，`rs1` 是计数器索引：

```scala
doGetTrafficCounter -> Mux(
  rs1_val < GH_GlobalParams.GH_TRAFFIC_COUNTERS.U,
  io.traffic_counter_in(rs1_val), 0.U)
```

索引越界返回零。公共 `traffic_counter` Vec 接口在 BOOM DCache、Rocket R_ICSL、Core、RoCC command router、GHE 输入之间统一为 13 项，避免不同 tile 的 Bundle 宽度不一致。

== 4.2 BOOM 到 GHE 的传输

```text
BOOM LSU completion pulses
  -> BoomNonBlockingDCacheModule counters
  -> BoomTile traffic_counter
  -> RoccCommandRouterBoom
  -> GHE traffic_counter_in
  -> funct 0x7B / rs1=10,11,12
```

RoCC router 只做向量直通，不复制或再次累加。读回发生在软件发出 RoCC 指令时，不会改变硬件计数器。

== 4.3 Rocket checker 到 GHE 的传输

```text
RocketCore checker_amo_*_complete
  -> R_ICSL AMO counters
  -> RocketCore traffic_counter
  -> RocketTile command router
  -> GHE traffic_counter_in
  -> funct 0x7B / rs1=10,11,12
```

Rocket checker 必须读取自己的 tile 计数器，不能把 BOOM DCache 的计数值直接接到 checker。软件比较时，BOOM hart 0 与所有 checker hart 的 AMO 分类应分别汇总；单个 checker 只覆盖一段检查窗口，不能要求它独立满足完整程序的 AMO 数量。

== 4.4 软件枚举、保存和打印

`Software/Test/ghe.h` 用枚举集中定义 AMO 项：

```c
enum ghe_traffic_counter {
    // ... store/load/LR/SC entries 0..9 ...
    GHE_TRAFFIC_AMO_TOTAL,
    GHE_TRAFFIC_AMO_CACHE,
    GHE_TRAFFIC_AMO_UNCACHE,
    GHE_TRAFFIC_COUNTERS
};
```

`ghe_traffic_counter_read()` 继续调用 `ROCC_INSTRUCTION_DS(1, value, counter_index, 0x7B)`。`test.c` 和 `secondary.c` 使用 `GHE_TRAFFIC_COUNTERS` 作为共享数组和读取循环边界；checker hart 读取本地三项后置 ready，hart 0 等待所有 checker 完成，再统一打印 `amo_out`、`amo_cache` 和 `amo_uncache`。

AMO 输出至少应保持以下关系：

```text
for each hart: amo_out = amo_cache + amo_uncache
BOOM hart 0:   amo_out = amo_cache + amo_uncache
checker sum:   amo_out = amo_cache + amo_uncache
```

跨核比较时，BOOM 的 AMO 总数应与所有有效 checker hart 的 AMO 总数对应；分类项也应分别比较。不要把 BOOM 和 checker 的计数相加后再与程序静态 AMO 数量比较，除非明确要统计“执行路径事件总量”而不是校验一致性。

= 第五章：边界、常见错误和后续扩展

== 5.1 为什么不能用 `uop.is_amo` 或 `isRead/isWrite`

`uop.is_amo` 是 BOOM 解码阶段的微操作属性，LR/SC 在 BOOM 的原子微操作路径中也可能带有相关标志。`isRead`/`isWrite` 更宽，会把 AMO 同时看成 LOAD 和 STORE。正确做法是在完成点比较 `rocket.isAMO(mem_cmd)` 或 Rocket 的 `isAMO(wb_ctrl.mem_cmd)`，并保留原有 LR/SC 的精确命令判断。

== 5.2 为什么不能在 request、MSHR 或 data array 分别加 AMO 数

同一条 cacheable miss AMO 会依次经过请求入口、普通 MSHR、refill/replay、AMOALU 和 data array；在多个节点累计会得到事务数，而不是指令完成数。uncacheable AMO 也会分别出现 IOMSHR allocation、TileLink A、D response 和 LSU response。当前跨核协议只选择最终完成点，因此每条 AMO 在每个 tile 最多产生一个 `amo_out` 脉冲。

如果需要分析微架构事务，应新建独立的 BOOM-only 事件组，例如请求进入 MSHR、L1D data-array write、uncached A、uncached ack/error。它们不能替换本文件定义的 `amo_out/amo_cache/amo_uncache`，也不能要求 Rocket checker 提供同名信号。

== 5.3 不可缓存 AMO 的限制

不可缓存 AMO 需要 TileLink manager 支持对应的 `ArithmeticData` 或 `LogicalData`。某些 MMIO manager 只支持 Get/Put，不支持原子 A channel；对这类目标不能假设 AMO 能正常执行。BOOM `BoomIOMSHR` 已对 SC 采用单独约束，正常路径下不可缓存 SC 不应被当成不可缓存 AMO 统计。

== 5.4 地址和 cacheability 位宽

GH memory packet 的 payload 为 128 位。bit 63 作为 cacheability 元数据后，地址比较使用低 40 位；AMO 的架构结果占据 bit 127:64。修改 packet 布局时必须同时修改 `GH_BUF`、`R_LSL` 和 RocketCore 的响应连接，否则会出现 cacheability 被当成地址高位或架构结果错位的问题。

== 5.5 相关文件和验证边界

#table(
  columns: (2.8fr, 4.2fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*文件*], [*职责*]),
  [`generators/boom/src/main/scala/lsu/lsu.scala`], [AMO response 精确判定、STQ 去重和 cache/uncache 完成脉冲。],
  [`generators/boom/src/main/scala/lsu/dcache.scala`], [两个分类计数器、总数构造和 13 项向量输出。],
  [`generators/boom/src/main/scala/lsu/mshrs.scala`], [uncacheable AMO 的 IOMSHR/TileLink 路径；当前统计仍在 LSU response 完成点。],
  [`generators/boom/src/main/scala/trans/GH_BUF.scala`], [AMO 架构结果、cacheability 和地址的 packet 布局。],
  [`generators/boom/src/main/scala/common/tile.scala`], [BOOM manager cacheability 判定及 packet 元数据输入。],
  [`generators/rocket-chip/src/main/scala/rocket/RocketCore.scala`], [checker AMO WB/LSL 完成判定和 cache 分类。],
  [`generators/rocket-chip/src/main/scala/r/R_LSL.scala`], [从 packet 返回 AMO 数据、低 40 位地址和 cacheability。],
  [`generators/rocket-chip/src/main/scala/r/R_ICSL.scala`], [Rocket AMO 两项分类计数器和 13 项输出。],
  [`generators/rocket-chip/src/main/scala/guardiancouncil/GHE.scala`], [funct 0x7B 的 13 项索引读回。],
  [`Software/Test/ghe.h`, `test.c`, `secondary.c`], [AMO 枚举、按 hart 读取保存、同步和打印。],
)

本次修改的验证边界是静态一致性：`git diff --check`、RISC-V C 语法检查和 Java 17 下 `sbt -batch 'boom/compile'`。不运行仿真，不执行 Chisel elaboration、Verilog 生成或其他硬件生成。实际使用时，应在检查窗口和 checker 同步完成后读取 10..12，并分别检查 BOOM 与 checker 汇总的不变量。
