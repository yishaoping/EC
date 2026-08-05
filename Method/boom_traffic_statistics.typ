#set document(
  title: "Chipyard BOOM 访存流量统计与 RoCC 读回设计",
  author: "Codex",
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
  #text(size: 19pt, weight: "bold")[Chipyard BOOM 访存流量统计与 RoCC 读回设计]
  #v(0.5em)
  #text(size: 10.5pt, fill: rgb("#455a64"))[面向“Rocket 小核校验 BOOM 大核”的协同工作框架]
]

#v(0.8em)

本文按当前仓库的 `chipyard/generators/.../src/main/scala` 编写。当前 `v1Config` 中 hart 0 是 Large BOOM，hart 1--4 是 Rocket checker；配置位置是 `generators/chipyard/src/main/scala/config/RocketConfigs.scala:9-27`。

先记住整条路线：

```text
BOOM LSU
  -> dmem_req_fire
  -> DCache.io.lsu.req.fire
       -> cacheable hit: dataWriteArb / cache response
       -> cacheable miss: mshrs.io.req.fire -> replay
       -> uncacheable: BoomIOMSHR.io.req.fire
            -> BoomIOMSHR.io.mem_access.fire
                 -> TileLink A -> SBUS -> device

L1D replacement/probe
  -> tl_out.c.fire (ReleaseData/ProbeAckData)
       -> Inclusive L2 io.in.c.fire
            -> SourceC
                 -> TLCacheCork.c_a.fire (PutFullData)
                      -> MBUS -> TLToAXI4 -> DRAM
```

Decoupled 接口只有 `valid && ready`（即 `fire`）才计数。TileLink 一条 cache line 有多个 beat，写回次数只在首 beat 计一次。BOOM 的 LDQ/STQ entry 现在带有 `traffic_seen` 去重位；Rocket 在 DCache 的非 nack、非内部 replay 节点统计，因此同一条请求的重发不会重复计数。

#outline(title: [目录], depth: 3)

= 第一章：STORE、LOAD 及是否可缓存

== 1.1 STORE/LOAD 的共同输出节点

LSU 先从 STQ 或 LDQ 选择一条访存指令，把请求放在 `dmem_req` 上。`lsu.scala:767-770` 定义：

```scala
io.dmem.req.valid := dmem_req.map(_.valid).reduce(_ || _)
io.dmem.req.bits  := dmem_req
val dmem_req_fire = widthMap(w => dmem_req(w).valid && io.dmem.req.fire)
```

因此信号顺序是：

```text
STQ/LDQ entry
    │
    ▼
LSU dmem_req.valid
    │ io.dmem.req.fire
    ▼
DCache.io.lsu.req.fire       <- 第一个统计节点：LSU 输出被 DCache 接收
    │
    ├─ cacheable hit
    ├─ cacheable miss -> MSHR
    └─ uncacheable    -> IOMSHR
```

`will_fire_store_commit` 只表示 LSU 想发请求，不能单独统计，因为 DCache 可能没有 ready。STORE 的产生位置在 `lsu.scala:798-809`；LOAD 还可能来自 `will_fire_load_incoming`、`will_fire_load_retry` 和 `will_fire_load_wakeup`，这些请求最终也汇聚到同一个 `dmem_req_fire`。

== 1.2 STORE 和 LOAD 的分类

```text
STORE:
  STQ -> dmem_req_fire -> DCache
       ├─ cacheable hit  -> L1D data array
       ├─ cacheable miss -> MSHR -> refill/replay -> L1D data array
       └─ uncacheable    -> IOMSHR -> PutFullData/PutPartialData

LOAD:
  LDQ -> dmem_req_fire -> DCache
       ├─ cacheable hit  -> L1D data -> LSU response
       ├─ cacheable miss -> MSHR -> GrantData -> replay -> LSU response
       └─ uncacheable    -> IOMSHR -> Get -> LSU response
```

DCache MSHR 文件在 `mshrs.scala:551` 使用物理地址和 manager 能力判断是否可缓存：

```scala
val cacheable = edge.manager.supportsAcquireBFast(
  req.bits.addr, lgCacheBlockBytes.U)
```

这个判据比虚拟地址上的属性更可靠，因为它直接回答“当前 TileLink manager 是否支持 cache block acquire”。请求分流位置如下：

#table(
  columns: (1.65fr, 2.3fr, 2.7fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*节点*], [*信号*], [*含义*]),
  [DCache 接收], [`io.lsu.req.fire`], [LSU 的一条 STORE/LOAD 进入 DCache pipeline。],
  [cacheable hit], [`s2_valid && s2_hit && !s2_nack`], [请求命中 L1D；LOAD 可形成 cache response，STORE/AMO 继续写 data array。],
  [cacheable miss], [`mshrs.io.req.fire && cacheable`], [请求进入普通 cache MSHR；LOAD 等待 refill，STORE 等待 replay。],
  [uncacheable], [`mmio_alloc_arb.io.out.fire` / `BoomIOMSHR.io.req.fire`], [请求进入 IOMSHR，不进入 L1D 和 Inclusive L2。],
)

普通 STORE 的最终 L1D 写入在 `dataWriteArb.io.in(0).fire`；LOAD 的返回在 `io.lsu.resp.valid`，对应代码位于 `dcache.scala:834-868`。因此“指令数”应在 `dmem_req_fire` 统计，“实际修改 L1D 的 STORE 数”才在 data-array write `fire` 统计。

== 1.3 当前统计口径和严格指令数

同一条 LOAD 可能因为 cache miss 或 nack 多次重新发出；同一条 STORE 也可能因为 MSHR 不可用而退回 STQ。BOOM 在 STQ/LDQ entry 分配时清零 `traffic_seen`，第一次 `dmem_req_fire` 时置一，DCache 只统计 `traffic_seen=false` 的请求。Rocket 的统计节点位于 `s2_valid_masked`，并排除 `s2_replay`，所以只在请求最终被 DCache 接受时加一。

```scala
when (dmem_req_fire(w) && uop.uses_stq && !stq(stq_idx).traffic_seen) {
  stq(stq_idx).traffic_seen := true.B
  when (isStore) { store_out := store_out + 1.U }
}
when (dmem_req_fire(w) && uop.uses_ldq && !ldq(ldq_idx).traffic_seen) {
  ldq(ldq_idx).traffic_seen := true.B
  load_out := load_out + 1.U
}
```

建议使用以下 6 个第一章寄存器：

#table(
  columns: (1.5fr, 2.2fr, 2.95fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*寄存器*], [*加一条件*], [*对应路径*]),
  [`store_out`], [DCache 接受 `M_XWR` 请求。], [BOOM LSU -> DCache。],
  [`store_cache`], [该 STORE 后续被判为 cacheable。], [L1D hit 或普通 MSHR。],
  [`store_uncache`], [该 STORE 后续被判为 uncacheable。], [IOMSHR。],
  [`load_out`], [DCache 接受 `M_XRD` 请求。], [BOOM LSU -> DCache。],
  [`load_cache`], [该 LOAD 后续被判为 cacheable。], [L1D hit 或普通 MSHR。],
  [`load_uncache`], [该 LOAD 后续被判为 uncacheable。], [IOMSHR -> Get。],
)

`rob_idx`、`stq_idx`、`ldq_idx` 会回绕。若计数器还要和 checker 的 packet 对齐，应同时保存 `inst_seq` 或 epoch，不能只保存 index。

== 1.4 不可缓存 STORE/LOAD 的 A 通道

IOMSHR 状态机在 `mshrs.scala:413-416` 定义为 `s_idle -> s_mem_access -> s_mem_ack -> s_resp`：

```text
mmio_alloc_arb.io.out.fire
        │
        ▼
BoomIOMSHR.io.req.fire       <- 可加 unc_store_req/unc_load_req
        │ 保存地址、数据和 uop
        ▼
BoomIOMSHR.io.mem_access.fire <- A 通道真正被下游接收
        │
        ├─ STORE: PutFullData / PutPartialData
        └─ LOAD:  Get
        │
        ▼
io.mem_ack.valid              <- D 响应；检查 denied/corrupt
```

A 消息构造在 `mshrs.scala:425-446`，状态转移在 `mshrs.scala:454-465`。不要用 `io.mem_access.valid` 计数，因为 backpressure 时它会保持多拍；必须使用 `io.mem_access.fire`。`io.mem_ack` 是 `Valid`，所以使用 `io.mem_ack.valid`，不能写 `.fire`。

Inclusive L2 的 `TLFilter(skipMMIO)` 会过滤 DCache MMIO client，位置在 `inclusivecache/src/Configs.scala:95-103`。因此不可缓存 STORE/LOAD 在 TileLink A 到达设备或内存 manager，不会经过本文件第四章的 L2 replacement 统计。

= 第二章：AMO 及是否可缓存

== 2.1 AMO 的特殊性

AMO 同时包含“读取旧值、计算、写入新值、返回旧值”四个动作。它不能简单当成普通 LOAD，也不能简单当成普通 STORE。BOOM 允许 AMO 在 ROB 完成前发出，LSU 的 `can_fire_store_commit` 特殊条件在 `lsu.scala:510-513`。

```text
AMO uop
   -> dmem_req_fire                       <- 第一个统计节点：AMO 输出
   -> DCache
       ├─ cacheable hit
       │    └─ AMOALU + dataWriteArb.io.in(0).fire
       ├─ cacheable miss
       │    └─ mshrs.io.req.fire -> refill/replay -> AMOALU + data array
       └─ uncacheable
            └─ BoomIOMSHR.io.req.fire
                 -> mem_access.fire: ArithmeticData/LogicalData
```

AMO 判据建议写成：

```scala
val isSc  = uop.mem_cmd === M_XSC
val isAmo = isAMO(uop.mem_cmd) && !isSc
```

明确排除 `M_XSC`，否则 SC 会被同时记到 AMO 和 SC。

== 2.2 cacheable AMO 的统计点

cacheable AMO 的最终修改仍然是 L1D data-array write。`dcache.scala:870-911` 先判断 `s3_valid`，再把 AMO 写请求送入 `dataWriteArb`；AMO 的运算单元在 `dcache.scala:897-900`。

#table(
  columns: (1.55fr, 2.45fr, 2.65fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*统计内容*], [*信号条件*], [*统计节点*]),
  [`amo_out`], [第一次 AMO `dmem_req_fire`，按 `stq_idx` 去重。], [LSU -> DCache。],
  [`amo_cache_req`], [`s2` 判定为 cacheable，或 `mshrs.io.req.fire && isAmo`。], [DCache -> 普通 MSHR/命中路径。],
  [`amo_cache_write`], [`dataWriteArb.io.in(0).fire && isAmo`。], [AMO 新值真正写入 L1D。],
)

`amo_cache_req` 是请求流量，`amo_cache_write` 是实际 data-array 修改；miss 时二者不会在同一个周期发生。若只需要“AMO 指令数”，使用 `amo_out`；若要分析 L1D 修改次数，使用 `amo_cache_write`。

== 2.3 uncacheable AMO 的统计点

IOMSHR 的 `atomics` 在 `mshrs.scala:427-437` 把 BOOM 的 `M_XA_*` 命令转换为 TileLink `ArithmeticData` 或 `LogicalData`：

```text
BoomIOMSHR.io.req.fire
        │
        ▼  amo_unc_req += 1
io.mem_access.fire
        │
        ├─ ArithmeticData
        └─ LogicalData
             ▼  amo_unc_a += 1
        │
        ▼
io.mem_ack.valid
        ├─ denied=0 && corrupt=0 -> amo_unc_ok
        └─ denied || corrupt     -> amo_unc_err
```

不可缓存 AMO 的计数器建议为 `amo_unc_req`、`amo_unc_a`、`amo_unc_ok`、`amo_unc_err`。A `fire` 表示原子操作已经交给总线，之后 core rollback 不能撤销设备或内存 manager 已经完成的原子修改。

当前 `BoomIOMSHR` 对 SC 有 `assert(state === s_idle || req.uop.mem_cmd =/= M_XSC)`，见 `mshrs.scala:443`。所以 `sc_uncache` 应作为非法路径计数，正常运行必须为 0；不能把不可缓存 SC 当成普通不可缓存 AMO。

= 第三章：SC/LR 及 reservation 统计

== 3.1 SC/LR 的信号路线

```text
LR:
  LDQ -> dmem_req_fire
       -> DCache s2_lr
            -> 命中/重放后设置 lrsc_addr、lrsc_count
                 -> 返回旧数据

SC:
  STQ -> dmem_req_fire
       -> DCache s2_sc
            ├─ lrsc_addr 不匹配 -> s2_sc_fail -> 返回失败码，不写数据
            └─ reservation 有效 -> dataWriteArb.io.in(0).fire
                                  -> L1D line 变 dirty
```

`s2_lr`、`s2_sc`、`s2_sc_fail` 在 `dcache.scala:664-667`，reservation 的建立和清除在 `dcache.scala:668-687`。LR 本身不产生新写数据；成功 SC 才能进入第四章的 dirty-line provenance。

== 3.2 LR 统计

LR 是读指令，使用 LDQ 的 `ldq_idx` 去重：

```scala
when (dmem_req_fire(w) && uop.mem_cmd === M_XLR &&
      !ldq(ldq_idx).traffic_seen) {
  ldq(ldq_idx).traffic_seen := true.B
  lr_out := lr_out + 1.U
}
```

LR 是否可缓存仍然使用 DCache 的 `supportsAcquireBFast` 判据。可缓存 LR 的关键结果是 reservation，不可缓存 LR 则是 IOMSHR 的 `Get` 和 D response；两者都不能当成 dirty writeback。

#table(
  columns: (1.55fr, 2.35fr, 2.75fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*计数器*], [*加一条件*], [*含义*]),
  [`lr_out`], [第一次 LR `dmem_req_fire`，按 LDQ 去重。], [BOOM 发出 LR。],
  [`lr_cache`], [LR 被 DCache 判为 cacheable。], [建立 L1D reservation。],
  [`lr_uncache`], [LR 进入 IOMSHR。], [发送 Get，返回值可能有设备副作用。],
  [`lr_reserve`], [`s2_lr` 且命中/重放成功。], [`lrsc_addr` 和 `lrsc_count` 被更新。],
)

== 3.3 SC 成功、失败和 cacheability

SC 的写数据统计必须排除失败 SC：

```scala
// s3_valid 已经在 dcache.scala:870-873 排除了 s2_sc_fail
val scSuccessWrite = dataWriteArb.io.in(0).fire &&
                     s3_req.uop.mem_cmd === M_XSC
when (scSuccessWrite) {
  sc_success := sc_success + 1.U
  // 设置该 cache line 的 unverifiedMask
}
when (s2_sc_fail) {
  sc_fail := sc_fail + 1.U
}
```

推荐的 SC 计数器如下：

#table(
  columns: (1.55fr, 2.35fr, 2.75fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*计数器*], [*加一条件*], [*含义*]),
  [`sc_out`], [第一次 SC `dmem_req_fire`，按 STQ 去重。], [BOOM 发出 SC。],
  [`sc_cache`], [SC 进入 cacheable L1D/MSHR 路径。], [reservation 判断在 DCache 内完成。],
  [`sc_uncache`], [SC 进入 IOMSHR。], [当前实现非法，应该为 0。],
  [`sc_success`], [成功 SC 的 `dataWriteArb.io.in(0).fire`。], [真正修改 L1D 并可能形成 dirty line。],
  [`sc_fail`], [`s2_sc_fail`。], [不修改数据，但会产生架构成功码 1。],
)

不能通过“校验之后重新执行一次 SC”来修复失败或成功结果：等待期间 reservation 可能因计数器倒计时、同核访问或 coherence Probe 被清除。SC 的原始结果应随校验 packet 保存。

= 第四章：L1 到 L2、L2 到 DRAM 的替换写回

== 4.1 什么事件会触发替换

替换可能由后续 LOAD/STORE/AMO miss、硬件 prefetch、Fence/flush 或其他 hart 的 Probe 触发。触发者不一定是产生 dirty 数据的那条指令；真正向下一级传输的是已有 dirty line：

```text
cacheable STORE / successful SC / cacheable AMO
        -> L1D data array
        -> dirty + unverifiedMask
             ├─ replacement victim -> WritebackUnit
             └─ Probe              -> ProbeUnit
                  -> TileLink C
```

L1 写回和 Probe 在 `dcache.scala:805-820` 仲裁到 `tl_out.c`。无数据的 `Release`/`ProbeAck` 不会传播 line data；只有 `ReleaseData`/`ProbeAckData` 需要统计。

== 4.2 L1 -> L2 的统计节点

```text
BoomWritebackUnit / BoomProbeUnit
        │
        ▼
tl_out.c.valid + tl_out.c.bits.opcode
        │ tl_out.c.fire
        ▼
L2.io.in.c.fire -> SinkC
```

计数器放在 `tl_out.c` 发送端。使用 `edge.count` 得到首 beat，定义见 `rocket-chip/src/main/scala/tilelink/Edges.scala:226-264`：

```scala
val (cFirst, _, _, _) = edge.count(tl_out.c)
val hasData = tl_out.c.bits.opcode.isOneOf(ReleaseData, ProbeAckData)
val l1ToL2 = tl_out.c.fire && cFirst && hasData && c_unverified
when (l1ToL2) {
  l1_l2_unverified := l1_l2_unverified + 1.U
}
```

`c_unverified` 必须在 WritebackReq/Probe 请求进入 `BoomWritebackUnit` 或 `BoomProbeUnit` 时锁存，不能在每个 beat 重新读取 way metadata。否则在 backpressure 或 metadata 被后续请求修改时，可能把一条未校验 line 误判为已校验。

L2 的 `io.in.c.fire` 是接收端镜像，可另设 `l2_sink_c` 检查握手，但不能和 `l1_l2_unverified` 相加。`Scheduler.scala:45-61` 是 `io.in.c` 到 `SinkC` 的连接。

== 4.3 L2 -> DRAM 的统计节点

当前 Inclusive L2 不是直接从 C 通道写 DRAM，而是：

```text
L2 io.in.c -> SinkC -> MSHR/Directory/BankedStore
       -> SourceC.io.req
       -> SourceC.io.c (ReleaseData)
       -> TLCacheCork.in.c
       -> CacheCork.c_a (PutFullData)
       -> MBUS -> TLToAXI4 -> DRAM
```

`Scheduler.scala:38-49` 连接 SourceC，`SourceC.scala:50-119` 生成外部 C beat；`inclusivecache/src/Configs.scala:103-118` 接入 CacheCork；`CacheCork.scala:91-108` 把 ReleaseData 转换为 PutFullData。

L2 目录需要像 L1 一样保存 `unverified` 或 byte mask，并把它从 `SinkC -> MSHR -> DirectoryEntry/BankedStore -> SourceCRequest -> CacheCork` 一路带下去。当前 `SourceCRequest` 有 `dirty` 字段但没有 `unverified`，需要增加。

```scala
val (cFirst, _, _, _) = edge.count(in_c)
val l2ToDram = c_a.fire && cFirst &&
               c_a.bits.opcode === PutFullData && c_unverified
when (l2ToDram) {
  l2_dram_unverified := l2_dram_unverified + 1.U
}
```

这里定义的 `l2_dram_unverified` 是“CacheCork 已接受并送往 MBUS/DRAM 路径”的次数。若要定义为 DRAM controller 真正接受的次数，应在 `TLToAXI4` 后观察 AXI AW/W 的首个握手；AXI 每个 W beat 不能直接当成一次 line 写回。

= 第五章：通过 RoCC 指令读回统计值

== 5.1 六个寄存器的完整传递路径

本版本的流量接口独立于原来的 84 项 32 位 `csr_counter`，使用 6 个 64 位计数器。BOOM 和 Rocket 的路径分别如下：

```text
BOOM DCache traffic_counter[0..5]
        │ BoomTileModuleImp
        ▼
RoccCommandRouterBoom.traffic_counter_in/out
        │
        ▼
GHE.io.traffic_counter_in
        │ funct=0x7B, rs1=index
        ▼
GHE.rd_val -> RoCC response -> BOOM hart 0

Rocket DCache traffic_counter[0..5]
        │ RocketTile/HasLazyRoCCModule
        ▼
RoccCommandRouter.traffic_counter_in/out
        │
        ▼
Rocket tile 的 GHE -> 对应 checker hart 软件
```

BOOM tile 中 `outer.dcache.module.io.traffic_counter` 接到 router；Rocket tile 中同名信号来自 `HellaCacheBundle`，因此 blocking DCache 和 NonBlockingDCache 都能提供这 6 个输出。router 只做直通，不保存副本，GHE 读到的是当前 tile 的实时计数值。

== 5.2 RoCC 指令格式

GHE 已使用 `funct=0x55` 读取旧的 CSR counter，`0x79` 也已有其他性能配置用途。因此流量读回使用 `funct=0x7B`：

```text
custom1 opcode
  rs1 = 0,1,2,3,4,5
  funct = 0x7B, xd = 1
      -> GHE cmd.fire
      -> io.traffic_counter_in(rs1)
      -> rd_val
      -> io.resp.valid
```

软件封装在 `Software/Test/ghe.h`：

```c
static inline uint64_t ghe_traffic_counter_read(int counter_index)
{
    uint64_t value;
    ROCC_INSTRUCTION_DS(1, value, counter_index, 0x7B);
    return value;
}
```

`ROCC_INSTRUCTION_DS` 把 `counter_index` 放到 `rs1`，所以硬件和软件的索引没有额外的 CSR 地址转换。

== 5.3 workload 和 hart 0 打印

`Software/Test/test.c` 的 workload 由 hart 0 执行：

- `0x81000000` 附近的 DRAM 指针执行普通 `sd/ld`、`lr/sc` 和 AMO，进入 cacheable L1D 路径；
- `CLINT_MTIME_ADDRESS` 执行无副作用读取，`CLINT_MTIMECMP_OFFSET(0)` 执行“写入新值后立即恢复”的成对写，进入 uncacheable 路径；
- 循环变量显式初始化为 0，避免 workload 因未定义值被优化或跳过。

每个 hart 都调用 `ghe_traffic_counter_read(0..5)` 并写入共享数组 `hart_traffic[hart][index]`，不访问 UART。hart 0 等待 `hart_traffic_ready[1..4]`，读取 hart 0--4 的全部 30 个值，再通过 `uart_lock` 完成唯一一次统计打印。这样 RoCC 读回可以在各 hart 并行发生，但打印端始终只有大核。

== 5.4 固定索引和计数含义

#table(
  columns: (0.55fr, 1.65fr, 3.8fr),
  inset: 4pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*索引*], [*名称*], [*统计节点*]),
  [0], [`store_out`], [DCache 接收并接受一条 `M_XWR`。],
  [1], [`store_cache`], [同一节点的 manager `supportsAcquireBFast` 返回 true。],
  [2], [`store_uncache`], [同一节点的 manager 判定返回 false。],
  [3], [`load_out`], [DCache 接收并接受一条 `M_XRD`。],
  [4], [`load_cache`], [manager 判定为 cacheable。],
  [5], [`load_uncache`], [manager 判定为 uncacheable。],
)

计数发生在 DCache 的请求/判定节点，而不是 RoCC 读回时；因此读回操作本身不会改变统计值。当前计数定义是“每个访存队列项第一次进入 DCache 的请求次数”，不是提交阶段的退休指令数。BOOM 的 `traffic_seen` 位随 STQ/LDQ entry 生命周期管理；Rocket 以 DCache 的最终接受节点过滤 nack/replay。计数器仍然不包含 AMO、SC/LR 和替换写回统计。
