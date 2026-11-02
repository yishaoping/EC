#set document(
  title: "BOOM DCache 写回追踪与 Chipyard 构建报错修复",
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
  #text(size: 19pt, weight: "bold")[BOOM DCache 写回追踪与 Chipyard 构建报错修复]
  #v(0.5em)
  #text(size: 10.5pt, fill: rgb("#455a64"))[L1→L2、共享 L2→DRAM 统计口径及 FIRRTL/firtool 构建链路修复]
]

#v(0.8em)

本文记录在既有 store/load、LR/SC、AMO 统计协议上增加 DCache 写回统计的软硬件修改，以及该修改引出的 FIRRTL、注解和 Make 增量构建问题。统计范围固定为 BOOM 大核 DCache：L1→L2 只统计 BOOM DCache 的 TileLink C 通道事务；共享 L2→DRAM 只统计具有 DCache 来源的 L2 resident victim。Rocket checker 的四项写回计数始终为零，软件也不打印 checker 的写回行。

本文沿用“完成握手而非请求出现”的口径，但写回计数是缓存行或 TileLink 消息数量，不是架构指令数量。文中的 `total` 和 `dirty` 关系为：

```text
L1→L2 total  = BOOM DCache C 通道的 Release/ProbeAck 行级消息数
L1→L2 dirty  = 其中携带数据的 ReleaseData/ProbeAckData 消息数

L2→DRAM total = DCache 来源的共享 L2 resident victim 数
L2→DRAM dirty = 其中携带脏数据向下游写出的 victim 数
```

需要特别注意：共享 L2 的 `total` 是 DCache 来源淘汰总数。CacheCork 只把 `ReleaseData` 转成 `PutFullData`，clean `Release` 会被即时确认，所以只有 `dirty` 严格对应实际携带数据的 DRAM 写回。保留 `total` 是为了同时观察 clean 和 dirty 淘汰压力。

#outline(title: [目录], depth: 3)

= 第一章：统计范围、术语和固定接口

== 1.1 为什么只关于 DCache

本项目的目标是观察大核数据工作集在缓存层次中的写回行为。Rocket 小核用于重执行和校验 BOOM 指令，不应把自身 DCache 的替换流量计入 BOOM 的 L1→L2；共享 L2 同时服务 ICache 和 DCache，也不能把 ICache-only cache line 的淘汰计入 DCache 的 L2→DRAM 统计。

因此两级计数的所有权不同：

#table(
  columns: (1.25fr, 2.25fr, 3.25fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*层级*], [*计数所有者*], [*排除项*]),
  [L1→L2], [BOOM hart 0 的非阻塞 DCache。], [Rocket checker 的 blocking/non-blocking DCache、ICache、非 C 通道事务。],
  [L2→DRAM], [共享 InclusiveCache 的每个 bank，最终汇总到 BOOM hart 0。], [ICache-only resident line、没有形成 resident victim 的旁路事务、checker 本地重复输出。],
)

“DCache 来源”不表示只看某一时刻发起替换的 client。L2 目录为 resident line 保存 sticky `dcache` 位：只要该行驻留期间曾被 DCache 请求或 DCache Release 标记，后续 L2 淘汰就属于 DCache 来源；只被 ICache 使用的行保持为零。

== 1.2 total、dirty 和 clean 的关系

两个层级均满足：

```text
total = clean + dirty
dirty <= total
```

L1→L2 不单独暴露 `clean`，软件可用 `total - dirty` 得到。这里的 clean 是不带 data 的 `Release` 或 `ProbeAck`，dirty 是带 data 的 `ReleaseData` 或 `ProbeAckData`。名称采用 TileLink 消息的数据携带属性；它与软件指令是否为 store 不是同一概念。

L2 每个 bank 内部实际保存 clean 和 dirty 两个 64 位计数器，以便在跨时钟域后稳定求和。软件只读取它们构造出的 `total` 和 `dirty`。clean victim 不向 DRAM 发送数据，但仍代表 L2 容量替换，因此保留在 `total` 中。

== 1.3 17 项软件可见协议

`GH_GlobalParams.GH_TRAFFIC_COUNTERS` 固定为 17。旧索引 `0..12` 不变，写回项追加在 `13..16`：

#table(
  columns: (0.65fr, 2.15fr, 2.6fr, 1.85fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*索引*], [*名称*], [*BOOM hart 0*], [*Rocket checker*]),
  [`0..2`], [store], [总数、cache、uncache。], [checker 对应值。],
  [`3..6`], [load], [总数、cache、uncache、STQ forward。], [checker 对应值，forward 为 0。],
  [`7..9`], [LR/SC], [LR、SC success、SC fail。], [checker 对应值。],
  [`10..12`], [AMO], [总数、cache、uncache。], [checker 对应值。],
  [13], [`l1_l2_wb_total`], [BOOM DCache C 消息总数。], [`0`。],
  [14], [`l1_l2_wb_dirty`], [其中带 data 的 C 消息数。], [`0`。],
  [15], [`l2_dram_wb_total`], [DCache 来源的共享 L2 victim 总数。], [`0`。],
  [16], [`l2_dram_wb_dirty`], [其中带 data 的 victim 数。], [`0`。],
)

四项写回计数不是 BOOM/Rocket 双路径的指令一致性计数，不能像 store/load/AMO 一样把 BOOM 与 checker 求和比较。它们只通过 hart 0 暴露一次。

= 第二章：BOOM DCache 的 L1→L2 写回统计

== 2.1 TileLink C 通道口径

BOOM 非阻塞 DCache 的 `tl_out.c` 由 writeback unit 的 release 和 prober 的 response 仲裁产生：

```text
BOOM DCache
  ├─ voluntary eviction/flush -> wb.io.release
  └─ coherence probe response -> prober.io.rep
                              -> TLArbiter -> tl_out.c -> L2
```

统计覆盖 C 通道的四种行级消息：

#table(
  columns: (1.75fr, 1.25fr, 3.6fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*opcode*], [*分类*], [*含义*]),
  [`Release`], [clean], [L1 主动释放权限，不携带 cache-line data。],
  [`ReleaseData`], [dirty], [L1 主动释放并携带修改后的 data。],
  [`ProbeAck`], [clean], [响应 L2 probe，不携带 data。],
  [`ProbeAckData`], [dirty], [响应 L2 probe 并携带 data。],
)

因此此处“写回”使用广义缓存层次流量口径，既包括主动 eviction，也包括 coherence probe response。若只想研究主动 victim，应另设只匹配 `Release/ReleaseData` 的事件，不能悄悄改变当前索引 13、14 的含义。

== 2.2 首 beat 的 `fire` 才计一次

带 data 的 C 消息可能包含多个 beat。直接对每个 `tl_out.c.fire` 加一会按 beat 多计，因此通过 TileLink edge 的 beat counter 只选择首 beat：

```scala
val (c_first, _, _, _) = edge.count(tl_out.c)
val l1_l2_wb_event = tl_out.c.fire && c_first
val l1_l2_wb_dirty_event = l1_l2_wb_event &&
  tl_out.c.bits.opcode.isOneOf(
    TLMessages.ReleaseData, TLMessages.ProbeAckData)
```

`fire` 同时要求 `valid && ready`，下游 backpressure 期间不会重复计数；`c_first` 把多 beat data message 压缩为一条 cache-line 事件。clean 单 beat 消息也只计一次。

两个 64 位寄存器只由这两个事件更新：

```text
l1_l2_wb_total_count += l1_l2_wb_event
l1_l2_wb_dirty_count += l1_l2_wb_dirty_event
```

计数器位于 `BoomNonBlockingDCacheModule`，直接写入统一向量的索引 13、14，不在 tile、GHE 或软件中再次累计。

== 2.3 为什么 Rocket 小核必须为零

此前日志中 checker 出现 L1→L2 数据，原因是把写回输出放进了 checker 也会使用的通用 cache 接口或把其本地 cache 流量暴露给统一向量。这不符合“只测 BOOM 大核 DCache”的定义。

修正后的边界如下：

- Rocket `DCacheModule` 和 `NonBlockingDCacheModule` 的 legacy `traffic_counter` 整个向量固定为零；
- Rocket 的 store/load/LR/SC/AMO 仍由 `RocketCore/R_ICSL` 产生，而不是从普通 DCache 入口取得；
- `R_ICSL` 在索引 `13..16` 显式输出零；
- `RocketTile` 只把 core-owned checker counters 连接到 RoCC router，不接入任何写回计数；
- 软件只在 `hart == 0` 时打印 L1→L2，hart 1--4 不打印空行。

这样不会影响 checker 的架构指令统计，因为索引 `0..12` 的所有权原本就在 `RocketCore/R_ICSL`，Rocket DCache 的通用输出置零只是关闭错误的写回来源。

= 第三章：DCache 来源的共享 L2→DRAM 统计

== 3.1 为什么不能直接数 L2 SourceC

InclusiveCache 是共享 L2，SourceC 会看到 ICache 和 DCache 工作集形成的 resident victim。如果仅统计所有 `sourceC.io.req.fire()`，ICache-only clean eviction 也会混入，违背“只关于 DCache”的口径。

同时，L2 淘汰发生时最初的 A/C source 可能已经不在当前请求上，不能只用 eviction 当拍的 source ID 猜来源。实现需要在目录项驻留期间保存 provenance：

```text
DCache A/C request
  -> isDCacheSource(source)
  -> DirectoryEntry.dcache sticky bit
  -> MSHR hit/refill/release/nested-release propagation
  -> SourceCRequest.dcache
  -> line-level eviction counter
```

== 3.2 DCache source range 的识别

`InclusiveCacheParameters` 从 TileLink diplomacy 的 inner clients 中筛选 coherent DCache client，并保存 remapped source range：

```scala
private val dcacheSourceRanges = inner.client.clients
  .filter(c => c.supports.probe &&
    c.nodePath.last.name == "dcache.node")
  .map(_.sourceId)

def isDCacheSource(source: UInt): Bool =
  dcacheSourceRanges.map(_.contains(source))
    .foldLeft(Bool(false))(_ || _)
```

该方法使用 diplomacy 已分配的 source range，不依赖固定 hart 数、固定 source ID 或地址范围。`supports.probe` 排除非 coherent client，node path 末端名称将 DCache 与 ICache 区分开。

== 3.3 sticky `dcache` 目录位的传播

`DirectoryEntry` 新增 `dcache: Bool`。其语义是“该 resident line 自建立以来是否被 DCache 使用过”，与 `dirty` 独立：clean DCache line 可以是 `dcache=1, dirty=0`，dirty line 必然属于需要关注的数据来源，但仍通过两个位分别表达。

传播规则为：

#table(
  columns: (1.55fr, 4.85fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*场景*], [*`dcache` 更新*]),
  [目录无效项], [初始化和失效时置 `false`，并断言 INVALID 项不能保留 `dcache`。],
  [普通 hit/refill], [`(meta.hit && meta.dcache) || isDCacheSource(request.source)`，保留历史来源并吸收当前 DCache A 请求。],
  [C Release], [`meta.dcache || isDCacheSource(request.source)`，DCache release 同样能建立来源。],
  [probe/secondary path], [不改变 resident provenance；继续传递 `meta.dcache`。],
  [nested Release], [`c_set_dcache` 把 nested C transaction 的来源合并回正在处理的 MSHR meta。],
  [control invalidate], [最终无效项置 `false`。],
)

MSHR 把 victim 原目录项的 `meta.dcache` 放入 `SourceCRequest.dcache`。这一步必须取 victim 的 resident metadata，而不是新请求将要安装的来源，否则会把触发替换的新行属性错算到被淘汰的旧行。

== 3.4 SourceC 接受点和脏分类

Scheduler 在 SourceC 接受一条 victim request 时输出行级脉冲：

```scala
io.dcacheWriteback :=
  sourceC.io.req.fire() && sourceC.io.req.bits.dcache
io.dcacheWritebackDirty :=
  io.dcacheWriteback && sourceC.io.req.bits.dirty
```

SourceC front-end 对每条 victim 只接受一次；dirty victim 后续读取 banked store 并产生多个 C beat，clean victim 不读 data。把计数点放在 `req.fire()` 可天然做到一条 cache line 一次，不需要在外侧 C beat 上再次去重。

每个 bank 保存：

```text
cleanCount += dcacheWriteback && !dcacheWritebackDirty
dirtyCount += dcacheWritebackDirty
```

因此软件看到的 `l2_dram_wb_total = sum(cleanCount) + sum(dirtyCount)`，`l2_dram_wb_dirty = sum(dirtyCount)`。

== 3.5 与真实 DRAM 写事务的边界

InclusiveCache 的 SourceC 输出仍是 TileLink C。其下游 CacheCork 对消息的处理决定是否真的产生 A 通道写：

```text
dirty victim: ReleaseData -> CacheCork -> PutFullData -> memory/DRAM path
clean victim: Release     -> CacheCork -> ReleaseAck  -> 不发送 data write
```

所以命名 `l2_dram_wb_total` 表示“以 DRAM 为下一级的 L2 DCache victim 总流量”，而不是“DRAM 已接受的 data write 数”。严格分析内存写带宽时使用索引 16；分析 L2 替换压力时使用索引 15，并用 `total - dirty` 得到 clean victim。

该计数不覆盖绕过 L2 resident replacement 的 MMIO、uncached Put、DMA 或其他 master 请求。若要统计 DRAM controller 接受的所有写事务，应在内存控制器或下游 TileLink A beat 另建计数，不能与本接口混用。

= 第四章：跨 bank、跨时钟域和软件读出

== 4.1 Gray code 传输

InclusiveCache 每个 bank 可能与 BOOM tile 不在同一时钟域。不能把持续变化的 64 位 binary counter 逐位直接同步：多个 bit 同时翻转时，目的域可能短暂采到不存在的组合值。当前实现把每个 bank 的 clean/dirty binary counter 转为 Gray code：

```scala
gray := count ^ (count >> 1)
BoringUtils.addSource(gray, s"..._$bank")
```

BOOM hart 0 为每个 bank 创建同名 sink，先给 sink `WireDefault(0.U)`，再用三级 `AsyncResetSynchronizerShiftReg` 同步，最后将 Gray 转回 binary：

```scala
def grayToBinary(gray: UInt): UInt =
  VecInit((0 until gray.getWidth).map { i =>
    gray(gray.getWidth - 1, i).xorR
  }).asUInt
```

各 bank 的 binary 结果在 BOOM 时钟域求和，clean+dirty 写入索引 15，dirty 写入索引 16。Gray code 保证单次自增只翻转一位；同步读数允许有几拍延迟，但不会因为普通多 bit binary transition 产生巨大伪值。

计数器连续高频自增时，目的域可能跳过中间值，这是观测异步累计计数器的正常行为；在所有工作完成并等待同步延迟后读取最终稳定值即可。该接口统计累计量，不用于逐事件握手。

== 4.2 BoringUtils 连接和 hart 0 汇总

每个 L2 bank 使用带 bank 后缀的唯一 bore name：

```text
gh_l2_dram_wb_clean_gray_0 ... _N
gh_l2_dram_wb_dirty_gray_0 ... _N
```

`InclusiveCache` 是 source，只有 `outer.boomParams.hartId == 0` 的 `BoomTileModuleImp` 建立 sink 和汇总逻辑。BOOM DCache 原始向量的 15、16 先为零，再由 hart 0 tile 的局部 `trafficCounter` 覆盖。RoCC command router 和 GHE 只做统一向量传输，不保存第二份计数器。

传输路径为：

```text
per-bank InclusiveCache clean/dirty counters
  -> binary-to-Gray
  -> BoringUtils source/sink
  -> 3-stage synchronizer in BOOM hart 0
  -> Gray-to-binary and bank sum
  -> trafficCounter[15], trafficCounter[16]
  -> RoccCommandRouterBoom
  -> GHE funct 0x7B indexed read
```

== 4.3 软件枚举、读取和日志

`Software/Test/ghe.h` 在 AMO 后追加四个枚举项。`ghe_traffic_counter_read()` 继续通过 `ROCC_INSTRUCTION_DS` 的 `funct=0x7B` 读取当前 hart 所在 tile 的指定索引。

hart 1--4 仍可按统一循环读取 17 项，但 `13..16` 必须为零；统一数组长度不变可以避免共享内存布局和同步协议分叉。日志只输出有意义的拥有者：

```text
hart0 dcache traffic: l1_l2_wb_total=... l1_l2_wb_dirty=...
shared dcache traffic: l2_dram_wb_total=... l2_dram_wb_dirty=...
```

L1→L2 行放在 `hart == 0` 条件内，checker 不打印。共享 L2 行在所有 hart 的普通指令统计打印完成后只打印一次，数据取自 `hart_traffic[0]`。

= 第五章：构建报错的原因和修复

== 5.1 firtool 无法解析 `validif`

*现象：* 加入 BoringUtils source/sink 后，WiringTransform 参与 Scala FIRRTL 阶段。送入 firtool 的 Low FIRRTL 中仍残留 `validif`，而当前 CIRCT/firtool parser 不接受该表达式，构建在 FIRRTL 输入解析阶段失败。

*根因：* FIRRTL 1.5.5 的 `Forms.LowForm` 依赖集合不会自动执行 `RemoveValidIf`。`ExtraLowTransforms` 虽然声明位于 LowForm 和 emitter 之间，但原来的 `execute` 直接返回 `state`，没有真正消除 `validif`。同时，Make 原来只按 `ENABLE_CUSTOM_FIRRTL_PASS` 或 FIRRTL 中的 `Fixed<` 判断是否需要 `-X low`，没有识别 annotation 中的 WiringTransform。

*修复：* `common.mk` 的 `SFC_NEEDS_LOW` 同时检查 custom pass、`Fixed<` 和 `firrtl.passes.wiring.WiringTransform`，据此稳定选择 `low`。`ExtraLowTransforms.execute` 显式运行：

```scala
passes.RemoveValidIf.runTransform(state)
```

*验证要点：* 不能只确认原始 CHIRRTL 中没有 `validif`；应检查 SFC 最终交给 firtool 的 `.fir`，并确认 WiringTransform 存在时 `SFC_LEVEL_FOR_MFC=low`。

== 5.2 Wiring 注解重复和失效 DontTouch

*现象：* 解决 `validif` 后，firtool 继续报告 wiring source/sink 重复或 annotation target 不存在。中间 `.json` 的条目变化较大，容易误判为功能注解被批量删除。

*根因：* Scala FIRRTL 的 WiringTransform 已经把 `SourceAnnotation` 和 `SinkAnnotation` 实体化为 Low FIRRTL 连线；若把这两类实现注解继续交给 CIRCT，firtool 会尝试二次 wiring。LowForm 的 aggregate 展开、alias 消除和重命名还会让部分旧 `DontTouchAnnotation` 指向已不存在的 declaration。

*修复：* `GenerateModelStageMain.dumpAnnos` 获取最终 Low FIRRTL circuit，并按以下规则导出：

```scala
case _: SourceAnnotation | _: SinkAnnotation => false
case DontTouchAnnotation(target) =>
  moduleNamespaces.get(target.leafModule)
    .exists(_.contains(target.ref))
```

第一条只删除已经消费并实体化的 wiring implementation annotations；第二条用每个最终 module 的 `Namespace` 删除失效 DontTouch，同时保留仍能解析到实际声明的 DontTouch。既有 `DeletedAnnotation`、emitted artifacts、circuit 本体和 stage 私有 out-anno 标记仍按原逻辑过滤。

当时中间数据为：

#table(
  columns: (2.4fr, 3.9fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*检查项*], [*结果*]),
  [输入 Wiring 注解], [`SourceAnnotation=2`、`SinkAnnotation=2`；SFC 输出为 0，因为连线已进入 FIRRTL。],
  [输入 DontTouch], [708 项。],
  [LowForm 后有效 DontTouch], [12055 项；展开后的有效目标被保留。],
  [完整 annotation JSON], [约 1378 项、1.22 MB 变为 12751 项、2.70 MB，并非整体缩水。],
)

因此 `.json` 中删除若干条不能单独说明功能异常。应判断被删类型是否已由 transform 消费、目标是否仍存在，以及最终 FIRRTL/Verilog 是否保留期望连线。这里删除的是重复 wiring 实现注解和无效 DontTouch；BoringUtils 连接已实体化在 Low FIRRTL 中，有效 DontTouch 反而完整保留。

== 5.3 增量构建丢失 sequential-memory replacement 参数

*现象：* 全新构建能经过 SFC，但复用已有 FIRRTL/annotation 的增量构建可能缺少 sequential memory replacement 输出，后续 firtool、memory collateral 或文件依赖失败。同一命令清理后和增量执行时表现不一致。

*根因：* `EXTRA_FIRRTL_OPTIONS` 原来只在 grouped target recipe 实际执行时通过 `$(eval ...)` 追加：

```text
--infer-rw
--repl-seq-mem -c:<MODEL>:-o:<SFC_SMEMS_CONF>
```

当 Make 判断 FIRRTL/annotation 已经最新而跳过该 recipe 时，下游 SFC target 仍会运行，但变量没有获得上述参数。

*修复：* 把下游实际使用的选项定义为可由当前 artifact 状态稳定推导的变量：

```make
EXTRA_FIRRTL_OPTIONS_FOR_SFC = \
  $(strip $(EXTRA_FIRRTL_OPTIONS) \
  $(if $(filter low,$(SFC_LEVEL_FOR_MFC)),$(SFC_REPL_SEQ_MEM)))
```

GenerateModelStageMain 调用改用 `$(EXTRA_FIRRTL_OPTIONS_FOR_SFC)`。同理，`SFC_LEVEL_FOR_MFC` 不再依赖某个可能被跳过的 recipe 才赋值，而是根据 `SFC_NEEDS_LOW` 提供 fallback。这样 clean 和 incremental build 使用同一组 lowering/memory 参数。

== 5.4 black-box filelist 路径重复

*现象：* firtool 生成的 black-box filelist 中已经含有绝对路径或 `gen-collateral` 路径，Make 再无条件添加前缀，最终出现：

```text
.../gen-collateral/.../gen-collateral/ClockDividerN.sv
```

下游编译器据此找不到 black-box SystemVerilog 文件。

*根因：* 原 sed 规则只区分“以 `/` 开头的绝对路径”和相对路径，不能识别已经带有 `$(GEN_COLLATERAL_DIR)` 但不是 `/` 开头的条目。

*修复：* 先去掉 `./`，再把任何已经包含 collateral 目录的前缀归一化，最后只给仍为相对路径的条目增加一次前缀：

```make
$(SED) -e 's;^\./;;' \
  -e 's;^.*$(GEN_COLLATERAL_DIR)/;$(GEN_COLLATERAL_DIR)/;' \
  -e '\|^/|! s;^;$(GEN_COLLATERAL_DIR)/;'
```

同时，GenerateModelStageMain 使用的 TapeoutStage 参数名是 `--out-anno-file`，不是标准 FirrtlStage 风格的 `--output-annotation-file`。`common.mk` 已改为前者，确保过滤后的 SFC annotation 确实写入预期文件并被后续 firtool 消费。

== 5.5 推荐的排错顺序

上述问题会串联出现，前一个错误可能遮蔽后一个。后续遇到相似故障时按 artifact 边界定位：

1. 查看 `SFC_LEVEL_FOR_MFC` 是否为 `low`，以及 SFC 命令是否带 `--infer-rw/--repl-seq-mem`；
2. 检查 SFC 输出 FIRRTL 是否仍含 `validif`，BoringUtils 连线是否已经实体化；
3. 检查输出 annotation 是否还含 Source/Sink，实现后的 DontTouch target 是否确实存在；
4. 检查 firtool black-box filelist 每行路径，只能有一个 collateral 前缀；
5. 最后再进入 Verilator C++ 编译，避免把前端 artifact 错误误判成硬件逻辑错误。

= 第六章：相关文件、结果解释和验证边界

== 6.1 主要硬件和软件文件

#table(
  columns: (3.15fr, 3.85fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*文件*], [*职责*]),
  [`generators/boom/src/main/scala/lsu/dcache.scala`], [BOOM C 通道首 beat 计数，输出 L1→L2 total/dirty。],
  [`generators/rocket-chip/src/main/scala/rocket/DCache.scala`], [Rocket blocking DCache 的统一输出固定为零。],
  [`generators/rocket-chip/src/main/scala/rocket/NBDcache.scala`], [Rocket non-blocking DCache 的统一输出固定为零。],
  [`generators/rocket-chip/src/main/scala/r/R_ICSL.scala`], [checker 指令计数，写回索引 13..16 固定为零。],
  [`generators/rocket-chip/src/main/scala/tile/RocketTile.scala`], [只传输 core-owned checker counters。],
  [`generators/sifive-cache/.../Parameters.scala`], [识别 diplomacy DCache source ranges。],
  [`generators/sifive-cache/.../Directory.scala`], [保存 resident line 的 sticky DCache provenance。],
  [`generators/sifive-cache/.../MSHR.scala`], [命中、填充、Release、nested Release 和 victim metadata 传播。],
  [`generators/sifive-cache/.../SourceC.scala`], [SourceC victim request 携带 dirty/dcache 元数据。],
  [`generators/sifive-cache/.../Scheduler.scala`], [输出每条 DCache 来源 victim 一次的 total/dirty 脉冲。],
  [`generators/sifive-cache/.../InclusiveCache.scala`], [per-bank clean/dirty 累加、Gray code BoringUtils source。],
  [`generators/boom/src/main/scala/common/tile.scala`], [hart 0 CDC、Gray decode、bank sum 和索引 15..16 覆盖。],
  [`generators/rocket-chip/.../GH_GlobalParams.scala`], [17 项协议索引和 bore name 常量。],
  [`Software/Test/ghe.h`, `test.c`, `secondary.c`], [枚举、17 项数组、按 hart 读取以及只打印 hart 0/shared 写回。],
)

构建链路修复位于：

#table(
  columns: (3.15fr, 3.85fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*文件*], [*职责*]),
  [`tools/barstools/.../ExtraTransforms.scala`], [在 Low FIRRTL 流程实际执行 `RemoveValidIf`。],
  [`tools/barstools/.../GenerateModelStageMain.scala`], [过滤已消费 Wiring 注解和无效 DontTouch。],
  [`common.mk`], [稳定选择 LowForm、保留 memory replacement 参数、使用正确 anno CLI、归一化 black-box 路径。],
)

== 6.2 历史日志为什么不能作为最终结果

在早期完整运行中，日志曾出现：

```text
BOOM hart 0 L1→L2 = 101 / 60
Rocket checker L1→L2 = 非零（错误）
shared L2→DRAM = 5 / 3（混入 ICache-only line）
```

这组数据用于暴露统计范围错误，不能作为修正后的性能结果。checker 非零说明 Rocket cache 流量错误接入；共享 L2 的 `5/3` 还没有 DCache provenance 过滤。最终修复已经让 checker 写回索引固定为零，并让 L2 只接受 `dcache=1` 的 resident victim，但按照“不做仿真和硬件生成”的约束，没有用新 RTL 重新运行 workload。因此本文不声称新的动态计数值。

== 6.3 已完成验证和后续检查

此前以下完整目标曾成功退出 0，证明四项 FIRRTL/Make 修复能够使当时的硬件版本通过生成、编译和运行链路：

```bash
make -j48 CONFIG=v1Config run-binary-debug-hex \
  BINARY=../../../Software/Test/test.riscv
```

其后增加“Rocket 写回为零”和“L2 排除 ICache-only line”的最终语义修复时，按约束没有重新执行仿真或硬件生成。对最终代码完成的验证边界是：

- `rocketchip`、`boom`、`sifive_cache` Scala compile 通过；
- `Software/Test/compile.sh` 通过；
- `git diff --check` 通过；
- 软件协议、Vec 长度、索引和日志拥有者完成静态核对。

未来允许动态验证时，至少检查以下不变量：

```text
hart 1..4: counters[13..16] = 0，且日志不打印 checker 写回行
hart 0:    l1_l2_wb_dirty <= l1_l2_wb_total
shared L2: l2_dram_wb_dirty <= l2_dram_wb_total
clean L2 victim = l2_dram_wb_total - l2_dram_wb_dirty
ICache-only workload 不增加 L2 DCache victim counters
多 beat ReleaseData/ProbeAckData 每条 cache line 只增加 1
```

动态验证应在 workload 和所有 checker 完成后再等待若干 BOOM 时钟周期，使 per-bank Gray counter 跨域同步稳定，然后从 hart 0 读取索引 13..16。若目标是 DRAM 总写流量，还需在内存控制器端新增独立计数，与本文件的 DCache resident-victim 口径分开报告。
