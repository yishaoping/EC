#set document(
  title: "BOOM/Rocket Store-Load 双路径追踪与 GHE 计数接口",
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
  #text(size: 19pt, weight: "bold")[BOOM/Rocket Store-Load 双路径追踪与 GHE 计数接口]
  #v(0.5em)
  #text(size: 10.5pt, fill: rgb("#455a64"))[Chipyard 中“BOOM 大核执行、Rocket 小核校验”的协同工作框架]
]

#v(0.8em)

本文只讨论 `store` 和 `load` 两类指令，不讨论仿真过程。统计范围固定为：BOOM 主核在检查窗口内实际完成的访存，以及 Rocket checker 对应的重执行完成。LR/SC、AMO、prefetch、探针和 RoCC 自身的访存不应混入这组指令计数。

当前实现的核心思想是把同一条访存拆成两条可对齐的时间路径：

```text
BOOM：指令在 BOOM LSU/DCache 中真实完成
      store -> data array 写入（可缓存）或 TileLink A 接受（不可缓存）
      load  -> DCache/IOMSHR 响应到达 LSU，或 LSU 从 STQ 转发完成

Rocket：checker 在 RocketCore 中重执行
        store/load -> LSL 响应有效且 WB 通过，作为 checker 完成
```

#outline(title: [目录], depth: 3)

= 第一章：BOOM 和 Rocket 的 Store/Load 执行流程

== 1.1 统计窗口与“完成”的含义

BOOM 的检查状态来自 R_IC：`core.io.debug_maincore_status === 2.U` 表示 `fsm_check`。BOOM DCache 在请求进入时锁存该状态到 `traffic_check`，因此请求即使在稍后的 MSHR replay 或响应阶段完成，也仍然属于原来的统计窗口。Rocket 不从普通 DCache 入口统计，而以 checker 重执行的 WB 完成为准；这是为了与“Rocket 校验了哪一条 BOOM 指令”保持一一对应。

计数点不是“请求曾经出现过”，而是指定路径的完成握手。`valid` 但没有 `ready` 的 Decoupled 接口不能计数；nack、内部 replay 和被 kill 的请求也不能直接计数。

== 1.2 BOOM 主核的执行流程

BOOM 的 LSU 从 STQ 或 LDQ 选择微操作，形成 `dmem_req` 并发送到 DCache：

```text
ROB/LSU
  -> STQ（store）或 LDQ（load）
  -> io.dmem.req.fire
  -> DCache pipeline
       ├─ cacheable hit：L1D data array / cache response
       ├─ cacheable miss：普通 cache MSHR，refill 后 replay
       └─ uncacheable：BoomIOMSHR，形成 TileLink Get/Put
```

STORE 的可缓存完成点是 `dataWriteArb.io.in(0).fire`，即 L1D data array 真正接受写入。它覆盖 hit 和 miss replay 后的最终写入，而不是只统计第一次 DCache 请求。不可缓存 STORE 没有 L1D 写入，当前实现把 `mshrs.io.mem_access.fire` 作为外部可见完成点：TileLink A 通道已经接受 `PutFullData` 或 `PutPartialData`。如果研究目标改为“设备确认写入”，可以另设 A 通道后续的 ack 计数，但不能与当前 store 总数混用。

普通 LOAD 的完成点在 LSU 收到 `io.dmem.resp(w).valid` 后，响应中的数据被送入整数或浮点执行结果，并把 LDQ entry 标记为 `succeeded`。可缓存 miss 的 refill、nack 和 replay 都在此之前发生，因此不产生额外 load 计数。不可缓存 LOAD 经 `BoomIOMSHR` 的 TileLink `Get` 和响应状态机后，也沿同一个 LSU response 路径完成。

还有一条不经过 DCache response 的路径：LSU 检测到较老的 STQ 数据已准备好，用 `wb_forward_valid` 选择 STQ entry，经 `LoadGen` 生成字节/半字/字/双字结果，并把该结果直接写回。DCache response 优先；只有没有 response、转发数据有效、未被分支杀死且 `stq_e.bits.data.valid` 时才算转发完成。该路径单独进入 `load_forward`，不能再归入 `load_cache`。

== 1.3 Rocket checker 的重执行流程

Rocket checker 的访存不是 BOOM 的普通 DCache 流量。checker 指令经过 RocketCore 的 EX/MEM/WB 管线，在 MEM 阶段由 `mem_reg_valid && mem_ctrl.mem` 驱动 LSL 请求：

```text
checker 指令
  -> RocketCore MEM/WB
  -> lsl_req_valid
  -> R_LSL 队列/缓存访问
  -> lsl_resp_valid 或 lsl_resp_replay
  -> RocketCore WB
  -> checker_mem_complete
```

`lsl_req_cmd` 使用 `Cat(isWrite(mem_ctrl.mem_cmd), isRead(mem_ctrl.mem_cmd))` 编码：`01` 是 load，`10` 是 store，`11` 可能代表同时具有读写语义的原子操作。计数时不使用宽泛的 `isRead`/`isWrite`，而在 WB 处精确匹配 `M_XRD` 和 `M_XWR`，从源头排除 AMO、LR/SC 等非目标指令。

Rocket checker 的完成条件为：处于 checker 或 checker privilege 模式、`wb_valid` 有效、WB 控制字表明是内存指令、`lsl_resp_valid` 有效且 `lsl_resp_replay` 为假。`wb_valid` 已排除 replay、异常和检查异常，所以一次成功重执行只产生一个完成脉冲。此时再按 `lsl_resp_cacheable` 分到 cacheable 或 uncacheable 子计数器。

Rocket 的 LSL 没有 BOOM 的 STQ-to-LDQ forwarding 语义。Rocket 的第七个输出固定为 `0.U(64.W)`；任何 LSL 读都只能落入 `load_cache` 或 `load_uncache`。

== 1.4 两条路径的对齐关系

对于同一条 BOOM `load`，可能先有 BOOM 的实际读取完成，再有 Rocket checker 的 LSL 重执行完成。两者是不同 hart、不同时间点的事件，不能把 BOOM DCache 请求和 Rocket LSL 请求简单相加。store 也同理：BOOM 统计真实可见写入，Rocket 统计 checker 的重执行 WB 完成。七个寄存器分别由两个 tile 提供，软件按 hart 读取后再比较。

= 第二章：指令类型、完成、缓存属性和 STQ 转发的判定

== 2.1 如何判定是 Store 还是 Load

#table(
  columns: (1.25fr, 2.2fr, 2.75fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*核*], [*严格判定*], [*排除项和注意事项*]),
  [BOOM], [`uop.mem_cmd === M_XWR` 为 STORE；`uop.mem_cmd === M_XRD` 为 LOAD。], [`uses_stq`/`uses_ldq` 只说明队列来源，不能单独当作类型；AMO、LR/SC 和其他 memory command 即使使用队列，也不计入这两类。],
  [Rocket checker], [`wb_ctrl.mem && wb_ctrl.mem_cmd === M_XWR` 为 checker STORE；`wb_ctrl.mem && wb_ctrl.mem_cmd === M_XRD` 为 checker LOAD。], [LSL 请求端的 `Cat(isWrite, isRead)` 只用于发请求；最终计数以 WB 控制字和完成条件联合判定。],
)

精确命令匹配是排除“非 store/load 混入”的关键。若只判断 `isWrite`，原子交换、逻辑原子和带读写语义的操作会被误计为 store；若只判断 `isRead`，同样会把原子读侧误计为 load。

== 2.2 如何判定 Store 完成

BOOM 的两个 store 完成脉冲如下：

```scala
// cacheable STORE: L1D data-array write handshake
dataWriteArb.io.in(0).fire &&
  s3_req.traffic_check && !s3_req.traffic_seen &&
  s3_req.traffic_cacheable && s3_req.uop.uses_stq &&
  s3_req.uop.mem_cmd === M_XWR

// uncacheable STORE: TileLink A request is accepted
mshrs.io.traffic_store_complete
// internally: io.mem_access.fire && traffic_check && !traffic_seen &&
//   !traffic_cacheable && uop.uses_stq && mem_cmd === M_XWR
```

第一条表示真实修改 L1D 的时间点，第二条表示不可缓存写请求已经被下游总线接受。普通 cache miss 在 MSHR 中等待并 replay，直到最终 data-array write 才计数；不能在 MSHR allocate 或第一次 `io.lsu.req.fire` 时加一。

Rocket checker 统一使用 `checker_store_complete`，再由 `lsl_resp_cacheable` 分到两个子计数器：

```scala
checker_mem_complete && wb_ctrl.mem_cmd === M_XWR
```

这里的 `checker_mem_complete` 必须同时包含 checker 模式、`wb_valid`、`wb_ctrl.mem`、`lsl_resp_valid` 和 `!lsl_resp_replay`。

== 2.3 如何判定 Load 完成

BOOM 的 cacheable 和 uncacheable LOAD 都在 LSU response 分支产生脉冲。有效条件的核心是：响应处于统计窗口、当前 LDQ entry 尚未计数，而且 `mem_cmd` 精确等于 `M_XRD`；随后用请求中锁存的 `traffic_cacheable` 选择子计数器。

```scala
val count_load = resp.traffic_check &&
  !ldq(ldq_idx).bits.traffic_seen &&
  resp.uop.mem_cmd === M_XRD

traffic_load_cache_complete   := count_load && resp.traffic_cacheable
traffic_load_uncache_complete := count_load && !resp.traffic_cacheable
```

Rocket checker 的对应条件为：

```scala
val checker_load_complete = checker_mem_complete &&
  wb_ctrl.mem_cmd === M_XRD
load_cache   := checker_load_complete && lsl_resp_cacheable
load_uncache := checker_load_complete && !lsl_resp_cacheable
```

计数点是完成 response 与 WB 的交汇，而不是 `lsl_req_valid`。这样可以把 LSL replay、被 kill 的请求和仅仅进入队列但没有成功重执行的请求排除掉。

== 2.4 如何区分可缓存与不可缓存

BOOM 在 DCache ingress 处按物理地址调用 TileLink manager 能力：

```scala
edge.manager.supportsAcquireBFast(addr, lgCacheBlockBytes.U)
```

结果保存到 `traffic_cacheable`，并随请求复制到普通 MSHR、replay response 和 IOMSHR response。支持 cache-block acquire 的访问归入 cacheable；否则进入 IOMSHR，形成非缓存的 Get/Put。该判据应在入口锁存，不能在 miss 完成时重新读取可能已经变化的流水线信号。

Rocket checker 不使用普通 Rocket DCache 的入口信号来推断 BOOM 访问属性。LSL 返回的 `lsl_resp_cacheable` 是当前 checker 请求的属性元数据，`R_ICSL` 只在完成脉冲到来时读取它。因而：

当前 `R_LSL` 的具体连接是 `io.resp_cacheable := Mux(resp_valid_reg, out_packet(63), false.B)`；也就是说，cacheable 属性随 LSL 中的记录包返回，并在 `resp_valid_reg` 有效时才有意义。

```text
store_cache   = store_complete &&  lsl_resp_cacheable
store_uncache = store_complete && !lsl_resp_cacheable
load_cache    = load_complete  &&  lsl_resp_cacheable
load_uncache  = load_complete  && !lsl_resp_cacheable
```

总数始终由可缓存和不可缓存之和得到；如果以后新增了第三类缓存属性，应先明确其归属，再修改总数公式，不能静默丢弃。

== 2.5 如何判断 LOAD 读取了 STQ

只有 BOOM 需要单独判断 STQ-to-load forwarding。成功转发的流水条件是：

```text
!dmem_resp_fired(w)
&& wb_forward_valid(w)
&& stq_e.bits.data.valid
&& !IsKilledByBranch(brupdate, forward_uop)
```

该条件成立后，LSU 设置 `ldq(...).succeeded`、`forward_std_val` 和 `forward_stq_idx`，并通过 `LoadGen` 产生最终 load 数据。计数脉冲额外要求 `wb_forward_traffic_check`、`!traffic_seen` 和 `forward_uop.mem_cmd === M_XRD`。

`dcache.scala` 中的 `s3_bypass/s4_bypass/s5_bypass` 是 DCache 流水线内部的同地址数据旁路，它不是本协议的第七项；第七项只表示 LSU 明确从较老 STQ entry 完成了 load。Rocket checker 置零 `load_forward`，因为其重执行模型没有这条 BOOM STQ 转发路径。

= 第三章：七个寄存器到 GHE 的连接

== 3.1 软件可见的寄存器协议

#table(
  columns: (0.7fr, 1.55fr, 2.6fr, 2.15fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*索引*], [*名称*], [*BOOM 含义*], [*Rocket checker 含义*]),
  [0], [`store_total`], [`store_cache + store_uncache`], [`store_cache + store_uncache`],
  [1], [`store_cache`], [cacheable STORE 完成], [checker cacheable STORE 完成],
  [2], [`store_uncache`], [uncacheable STORE 的 TileLink A 接受], [checker uncacheable STORE 完成],
  [3], [`load_total`], [`load_cache + load_uncache + load_forward`], [`load_cache + load_uncache`],
  [4], [`load_cache`], [DCache cacheable response 到 LSU], [LSL cacheable response + WB],
  [5], [`load_uncache`], [IOMSHR uncacheable response 到 LSU], [LSL uncacheable response + WB],
  [6], [`load_forward`], [BOOM LSU 从 STQ 成功转发], [`0`，Rocket 没有 BOOM STQ 转发],
)

因此 BOOM 必须满足：

```text
store_total = store_cache + store_uncache
load_total  = load_cache + load_uncache + load_forward
```

Rocket checker 必须满足：

```text
store_total = store_cache + store_uncache
load_total  = load_cache + load_uncache
load_forward = 0
```

== 3.2 BOOM 到 GHE

硬件连接顺序为：

```text
BOOM LSU/DCache completion pulses
  -> BoomNonBlockingDCacheModule 的五个子计数器
  -> io.traffic_counter : Vec(7, UInt(64.W))
  -> BoomTile 的 outer.dcache.module.io.traffic_counter
  -> RoccCommandRouterBoom.io.traffic_counter_in
  -> GHE 所在 RoCC 的 io.traffic_counter_in
  -> GHE funct 0x7B/indexed read
```

`BoomTile.scala` 将 DCache 的 `io.traffic_counter` 连接到 command router；router 再把 `traffic_counter_out` 广播给 tile 中的 GHE/RoCC。GHE 在 `funct === 0x7B.U` 时执行：

```scala
Mux(rs1_val < 7.U, io.traffic_counter_in(rs1_val), 0.U)
```

越界索引返回零，合法索引为 `rs1=0..6`。

== 3.3 Rocket checker 到 GHE

Rocket 的连接顺序为：

```text
RocketCore checker_mem_complete pulses
  -> R_ICSL 的四个 cache/uncache 子计数器
  -> R_ICSL.io.traffic_counter : Vec(7, UInt(64.W))
  -> RocketCore.io.traffic_counter
  -> RocketTile 的 cmdRouter.get.io.traffic_counter_in
  -> GHE io.traffic_counter_in
  -> funct 0x7B, rs1=0..6
```

`RocketCore` 把 `checker_store_*_complete` 和 `checker_load_*_complete` 接到 `icsl.io.st_*_deq`、`icsl.io.ld_*_deq`。`R_ICSL` 保存四个 64 位子计数器，构造七项 `VecInit`，末项显式连接 `0.U(64.W)`。`RocketTile` 只负责把 core 的输出接到 command router，不应在 tile 或普通 DCache 处重新加计数。

六个 Rocket completion 接口均保持连接：

```scala
icsl.io.st_deq         := checker_store_complete
icsl.io.ld_deq         := checker_load_complete
icsl.io.st_cache_deq   := checker_store_cache_complete
icsl.io.st_uncache_deq := checker_store_uncache_complete
icsl.io.ld_cache_deq   := checker_load_cache_complete
icsl.io.ld_uncache_deq := checker_load_uncache_complete
```

其中 `st_deq` 和 `ld_deq` 保留总完成脉冲，cache/uncache 四路负责实际子计数。软件可见的 store/load total 由子计数器求和生成，避免总计数器和分类计数器分别累加后发生漂移。

== 3.4 软件读出和打印

`Software/Test/ghe.h` 的统一入口为：

```c
static inline uint64_t ghe_traffic_counter_read(int counter_index)
{
    uint64_t value;
    ROCC_INSTRUCTION_DS(1, value, counter_index, 0x7B);
    return value;
}
```

`test.c` 保存 hart 0--4 各自的七项数组；hart 1--4 在 checker 完成后由 `secondary.c` 读取并置 `hart_traffic_ready`，hart 0 等待 ready 后统一打印。输出分成两行，分别打印三个 store 项和四个 load 项，避免把 load_forward 从日志中隐藏。

= 第四章：问题原因、改进内容和后续使用约束

== 4.1 旧方案为什么会导致多计和漏计

当前日志 `chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.log` 已体现修正后的结果：

#table(
  columns: (1.4fr, 1.55fr, 1.55fr, 1.55fr, 1.55fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*来源*], [*store total*], [*store cache/uncache*], [*load total*], [*load cache/uncache/forward*]),
  [BOOM hart 0], [2349], [2333 / 16], [2450], [2337 / 96 / 17],
  [Rocket hart 1--4 之和], [2349], [2333 / 16], [2450], [2354 / 96 / 0],
)

两侧总数已经相等。BOOM 的 17 条 load 在 LSU 中从 STQ forwarding 完成，不发生普通 DCache cacheable response；Rocket 重执行同一批指令时通过 LSL 读出，所以 Rocket 的 `load_cache` 比 BOOM 的 `load_cache` 多 17，且 Rocket 的 `load_forward` 固定为零。故正确比较是 BOOM 的 `load_cache + load_forward` 与 Rocket 的 `load_cache`，以及双方各自的 `load_total`；不能要求两个 `load_cache` 子项直接相等。

此前在 DCache 中按请求入口、dcache pipeline 节点或宽泛的 `uses_stq/uses_ldq` 统计，会同时引入以下问题：

- 请求被 nack、MSHR replay 或 refill 重发时，同一条指令被多次看到；入口计数不是完成计数。
- STQ 转发绕过 DCache response。如果只看 DCache response，会漏掉真实完成的 load；如果把转发再当作普通 cache load，可能重复计数。
- `uses_stq`/`uses_ldq` 不是精确的指令类型，AMO、LR/SC 等操作会混入 store 或 load。
- cacheable store 的请求出现不等于 data array 已经写入；uncacheable store 的 MSHR allocate 也不等于 TileLink A 已被接受。
- check 状态与完成状态可能跨多个周期。若在转发延迟路径直接采样当前状态，检查窗口会错位。

store 次数曾经能够对上，并不能证明 load 方案正确。store 的可见写入通常只有一个 data-array/A 通道握手，而 load 还存在 cache response、uncache response、nack/replay 和 STQ forwarding 多条互斥完成路径；少任何一路都会表现为 load 总数偏小。

== 4.2 `traffic_seen` 的正确语义

`traffic_seen` 表示“该 LDQ entry 已经产生过一次有效、在范围内的 load 计数”，不是“该请求曾经进入过 DCache”。当前规则是：

1. LDQ/STQ entry 分配、回收、异常 kill 或分支 kill 时清零相应标志。
2. 只有 `traffic_check` 为真、`traffic_seen` 为假且命令精确为 `M_XRD` 的 DCache/IOMSHR response 才能消耗 LDQ 的标志。
3. STQ 转发只有在同样的范围、去重和命令条件下才能设置 `traffic_seen`。
4. 统计窗口外的推测响应不能设置该标志，否则后续 checker 窗口中的真正完成会被错误抑制。
5. DCache response 优先于 forwarding；同一周期二者同时出现时只保留 response 路径。

forwarding 的检查状态需要跟随流水线延迟：`io.dmem.traffic_check_state -> mem_forward_traffic_check -> wb_forward_traffic_check`。这使转发完成点使用产生该转发请求时捕获的检查窗口，而不是两周期后的当前状态。该改动和 load_forward 独立计数一起用于消除原先遗漏的 load 路径。

== 4.3 计数器实现的约束

计数器应保持以下不变量，便于软件和日志自动检查：

```text
store_total >= store_cache
store_total >= store_uncache
load_total >= load_cache
load_total >= load_uncache
BOOM:   load_total = load_cache + load_uncache + load_forward
Rocket: load_total = load_cache + load_uncache
```

任何一个子计数器都必须由互斥的完成脉冲驱动；不要在 DCache、LSU、R_ICSL 和软件四处重复累加同一事件。缓存属性应随请求携带，命令类型应在完成点精确比较，窗口状态应在请求进入对应执行路径时锁存。

== 4.4 相关文件和验证边界

主要硬件文件如下：

#table(
  columns: (2.8fr, 4.2fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*文件*], [*职责*]),
  [`generators/boom/src/main/scala/lsu/lsu.scala`], [BOOM LSU response 和 STQ forwarding 完成脉冲、LDQ 去重。],
  [`generators/boom/src/main/scala/lsu/dcache.scala`], [cacheable store data-array 计数、五个 BOOM 子计数器及七项输出。],
  [`generators/boom/src/main/scala/lsu/mshrs.scala`], [uncacheable store 的 TileLink A 接受计数。],
  [`generators/boom/src/main/scala/common/tile.scala`], [BOOM DCache counter 到 RoCC command router 的连接。],
  [`generators/rocket-chip/src/main/scala/rocket/RocketCore.scala`], [checker LSL/WB 完成判定和六个输入脉冲。],
  [`generators/rocket-chip/src/main/scala/r/R_LSL.scala`], [LSL 请求命令、响应有效、replay 和 cacheable 元数据。],
  [`generators/rocket-chip/src/main/scala/r/R_ICSL.scala`], [Rocket 四个子计数器及第七项置零。],
  [`generators/rocket-chip/src/main/scala/tile/RocketTile.scala`], [Rocket core counter 到 command router 的连接。],
  [`generators/rocket-chip/src/main/scala/guardiancouncil/GHE.scala`], [funct 0x7B 按索引读回七项计数器。],
  [`Software/Test/ghe.h`, `test.c`, `secondary.c`], [RoCC 读回、按 hart 保存、同步和日志打印。],
)

本记录的编译边界是文档和硬件代码的静态一致性，不运行 Verilator 或其他仿真。此前的软件已完成编译链接，Chipyard `make -j8 CONFIG=v1Config debug` 已完成 Chisel elaboration、FIRRTL 检查和 Verilator 编译/链接；这些步骤只验证生成和编译，不替代对真实运行日志的分析。实际测量时，应在检查窗口开始前清零或记录基线，在所有 checker 完成并同步后读取七项寄存器，再比较 BOOM 与 Rocket 的对应总数及四个子项。
