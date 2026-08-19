#set document(
  title: "BOOM 到 Rocket 的校验包全流程",
  author: "基于当前 Chipyard/GuardianCouncil 硬件代码整理",
)
#set page(
  paper: "a4",
  margin: (x: 22mm, y: 20mm),
  numbering: "1",
)
#set text(
  font: ("Noto Sans CJK SC", "Droid Sans Fallback"),
  size: 10.5pt,
  lang: "zh",
)
#set par(justify: true, leading: 0.72em)
#set heading(numbering: "1.1")
#set table(
  stroke: rgb("d8dee8"),
  inset: 6pt,
  align: (left, top),
)
#show raw: set text(font: "Noto Sans Mono CJK SC", size: 8.2pt)
#show link: set text(fill: rgb("1756a9"))

#align(center)[
  #text(size: 22pt, weight: "bold")[BOOM 到 Rocket 的校验包全流程]

  #v(5pt)
  #text(size: 11pt, fill: rgb("46546a"))[
    从产生、传递到使用：面向初学者的当前硬件代码导读
  ]

  #v(4pt)
  #text(size: 9pt, fill: rgb("68758a"))[
    代码基线：`/data1/gzh/EC/chipyard/generators` 当前工作区，2026-08-17
  ]
]

#v(12pt)

#block(fill: rgb("eef5ff"), stroke: rgb("a9c8ef"), inset: 10pt, radius: 4pt)[
  *阅读范围。* 本文只分析现有 Scala/Chisel 硬件代码，不讨论 Dromajo、Cospike 等仿真参考模型，也不执行仿真、综合或硬件生成。主线配置是 `chipyard.v1Config`：hart 0 为 BOOM 大核，hart 1..4 为 Rocket checker 小核。
]

#outline(indent: auto)

#pagebreak()

= 先建立正确的整体认识

== 这不是逐周期锁步

当前设计是“*检查点 + 分段重放*”，而不是 BOOM 和 Rocket 每周期执行相同指令的 lockstep：

- BOOM 正常乱序执行，在提交端收集一段程序中的关键事件。
- 每个检查窗口开始时，BOOM 把架构上下文快照送给一个 Rocket checker。
- BOOM 继续执行，把 load、store、CSR、RoCC 写回和控制流事件送给该 checker。
- Rocket 从开始快照恢复状态，顺序重放这段程序；不可简单重现的值由包提供。
- 到达窗口末尾后，Rocket 将自己的最终状态和 BOOM 提供的结束快照比较。
- Rocket 生成带窗口序号的 PASS、FAIL 或 CANCELLED 结果，结果返回 BOOM 时才释放对应 checker。

因此，“校验包”不能只理解成一个 136-bit 数据。当前协议至少包含四组彼此配合的信息：

#table(
  columns: (1.2fr, 1fr, 2.8fr),
  table.header(
    [*类别*], [*当前宽度*], [*作用*],
  ),
  [普通事件组], [`272 bit`（BOOM 侧）/ `305 bit`（checker 侧）], [两个 136-bit lane，携带访存、CSR、RoCC 和分支事件；经 GHM 后增加 32-bit 窗口序号和 1-bit 有效位。],
  [上下文片段], [`153 bit`（BOOM 侧）/ `178 bit`（checker 侧）], [携带 ARF、FARF、PC、FCSR 和特权 CSR shadow；同时包含 CPS/ECP 路由信息，经 GHM 后增加序号和有效位。],
  [窗口控制], [`22 bit` 大到小], [携带 16-bit 指令计数、GH_BUF 排空信息和 5-bit 状态，帮助小核判断窗口何时结束。],
  [校验结果], [`35 bit` 小到大], [1-bit valid + 2-bit status + 32-bit sequence；闭合一个窗口的生命周期。],
)

#block(fill: rgb("fff7e8"), stroke: rgb("e5bd68"), inset: 10pt, radius: 4pt)[
  *初学者最重要的区分：* 普通事件组告诉 Rocket “重放过程中遇到特殊指令时用什么信息”；上下文片段告诉 Rocket “从什么状态开始”和“最后应该到达什么状态”；窗口控制告诉 Rocket “重放多少条指令”；结果包告诉 BOOM “这一段是否通过”。
]

== 当前配置和关键常量

主配置位于 `chipyard/generators/chipyard/src/main/scala/config/RocketConfigs.scala:9`：

- `v1Config` 给 hart 0 配置 200 MHz，给 hart 1..4 配置 100 MHz。
- `WithNLargeBooms(GH_NUM_BIG_CORES, overrideIdOffset = Some(0))` 实例化 BOOM。
- `WithNGCCheckers(GH_NUM_CORES - GH_NUM_BIG_CORES, overrideIdOffset = Some(GH_NUM_BIG_CORES))` 实例化 Rocket checker。
- Rocket tile 使用异步 crossing；GuardianCouncil 自己还在 `GHM` 中为各类包建立 `AsyncQueue`。

全局参数位于 `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala:4`：

#table(
  columns: (1.5fr, 0.8fr, 2.7fr),
  table.header([*常量*], [*值*], [*含义*]),
  [`GH_NUM_CORES`], [`5`], [1 个 BOOM + 4 个 Rocket checker。],
  [`GH_NUM_BIG_CORES`], [`1`], [hart 0 是大核；checker hart ID 为 1..4。],
  [`GH_TOTAL_PACKETS`], [`2`], [普通事件通路每拍最多输出两个 lane。],
  [`GH_WIDITH_PACKETS`], [`136`], [每个 lane = 8-bit header + 128-bit payload。],
  [`GH_TOTAL_INSTS`], [`3970`], [大核检查窗口的默认指令阈值。],
  [`GH_PACKET_SEQ_BITS`], [`32`], [窗口序号宽度，0 被保留为“无关联窗口”。],
  [`GH_CHECKER_RESULT_BITS`], [`35`], [1 valid + 2 status + 32 sequence。],
)

== 一张图看完整路径

```text
                         BOOM 时钟域（hart 0）

  R_IC 调度 checker、分配 seq、计数窗口指令
       |                         |
       | CPS/ECP 触发            | crnt_target / checker_segment_id
       v                         v
  R_RSU 保存 ARF/FARF/PC/CSR   ROB commit -> GH_BUF 过滤、打 136-bit 事件包
       | 153-bit 上下文片段       | 272-bit 双 lane 事件组
       +------------+------------+
                    v
              BundleBridge 节点
                    v
  +-------------------------------------------------------------+
  | GHM                                                         |
  | 解析目标 checker；给数据和上下文附加各自的 32-bit seq        |
  | 每个 checker：data AsyncQueue(256) + ARFS AsyncQueue(8)      |
  | 用队头 seq 约束两个独立队列的出队先后                        |
  +-------------------------------------------------------------+
                    |
                    | CDC
                    v
                         Rocket 时钟域（hart 1..4）

  RocketTile：检查 valid/seq/目标/type
       |                    |                    |
       | type 1/2/3/5       | type 4             | type 7 上下文
       v                    v                    v
     R_LSL              Frontend/R_BJLR       R_RSUSL + CSRFile
  load/store/CSR/RoCC      控制流重放          CPS 恢复 / ECP 保存
       |                    |                    |
       +---------- Rocket 顺序重放 -------------+
                            |
             ELU + ARF/FARF compare + CSR compare
                            |
                  35-bit {valid,status,seq}
                            v
                     GHM result AsyncQueue
                            v
                BOOM：释放 checker、记录包结果
```

= 普通事件包的位级格式

== 一个 lane：136 bit

`GH_BUF` 在 `chipyard/generators/boom/src/main/scala/trans/GH_BUF.scala:129` 形成 header，在同文件 `:130` 形成 payload，在 `:227` 拼成最终 lane：

```text
135                     128 127                                  0
+--------------------------+--------------------------------------+
|      header[7:0]         |            payload[127:0]            |
+--------------------------+--------------------------------------+

header[7]   : one / enable，当前目标非 0 时为 1
header[6:3] : 目标 checker 编号，当前 v1Config 中为 1..4
header[2:0] : 事件类型
```

对应 Chisel 逻辑是：

```scala
val one = Mux(io.ic_crnt_target(3,0) === 0.U, 0.U, 1.U)
filter_inst_index(i) := Mux(
  can_fwd(i),
  Cat(one, io.ic_crnt_target(3,0), inst_type_enc(i)),
  0.U)
packet_out(i) := Cat(out_inst_type(i), out_buf(i))
```

事件类型由 `GH_BUF.scala:120` 编码：

#table(
  columns: (0.7fr, 1.1fr, 2.2fr, 2.2fr),
  table.header([*type*], [*事件*], [*BOOM 侧来源*], [*Rocket 侧去向*]),
  [`0`], [无效], [没有需要传输的事件。], [被丢弃。],
  [`1`], [load], [`uses_ldq`；数据来自 LDQ 提交头。], [`R_LSL` 的 load 通道。],
  [`2`], [store], [`uses_stq` 且不是 fence；数据来自 STQ 提交头。], [`R_LSL` 的 store 通道。],
  [`3`], [CSR], [`is_csr`，但排除 `CSRshadows.csrshadow_seq`。], [`R_LSL` 的 CSR 通道。],
  [`4`], [branch/jump], [`is_br || is_jal || is_jalr`。], [`Frontend` 内的 `R_BJLR`。],
  [`5`], [RoCC 写回], [`uopc == uopROCC && ldst_val`。], [`R_LSL` 的 RoCC 通道。],
  [`7`], [上下文类别], [普通 `GH_BUF` 不产生；由 `R_RSU.arfs_pidx` 使用。], [`R_RSUSL` / `CSRFile`。],
)

header 的 bit 7 在当前接收端不是独立握手信号；真正的普通包有效位由 GHM 在跨域输出最上方额外添加。当前路由主要看 `header[6:3]`，类型分发看 `header[2:0]`。

== 两个 lane：272 bit

`GH_TOTAL_PACKETS = 2`。`GH_BUF.scala:246` 使用 `Cat(packet_out.reverse)`：

```text
271                 136 135                   0
+----------------------+-----------------------+
| lane 1：136 bit      | lane 0：136 bit       |
+----------------------+-----------------------+
```

GHM 和 RocketTile 都按相同的 `i * 136` 切片，因此 lane 次序前后一致。某个周期只有一个事件时，另一个 lane 为 0。

== load/store payload

BOOM LSU 在 `chipyard/generators/boom/src/main/scala/lsu/lsu.scala:1806` 和 `:1807` 先形成：

```scala
Cat(load_or_store_data_64, 0.U(24.W), virtual_address_40)
```

`GH_BUF` 再把原 bit 63 替换为 `commit_cacheable`：

```text
127                 64 63 62               40 39                  0
+---------------------+--+-------------------+---------------------+
| data/result[63:0]   | C|      padding      | virtual addr[39:0]  |
+---------------------+--+-------------------+---------------------+
                       C = cacheable
```

- 普通 load：上 64 bit 是 BOOM 的 load 写回数据。
- 普通 store：上 64 bit 是 BOOM 的 store 数据。
- `uses_stq && is_amo` 的分支把 `gh_prfs_rd` 放入上 64 bit，意图携带 AMO 的架构结果。
- `commit_cacheable` 由 `common/tile.scala:304` 调用 TileLink manager 的 `supportsAcquireBFast` 计算。
- checker 真正做地址比较时只取低 40 bit；`R_LSL.scala:148` 明确如此。

当前 BOOM decode 在 `exu/decode.scala:262` 到 `:285` 中对原子访存的标记是：LR 为 `uses_ldq=1, uses_stq=0, is_amo=0`；SC 和普通 AMO 为 `uses_ldq=0, uses_stq=1, is_amo=1`。因此，按当前 decode，LR 形成 type 1，SC/AMO 形成 type 2，且上 64 bit 改为目的寄存器的架构结果。`inst_type_enc` 仍是 `uses_ldq` 优先；以后若修改 micro-op 使两个标志同时为 1，必须重新审查 type 和 payload 的选择。

== CSR 和 RoCC payload

CSR 与 RoCC 写回都把 `gh_prfs_rd` 放入 128-bit payload；因为源只有 64 bit，高 64 bit 被零扩展，真正结果位于 `[63:0]`：

```text
127                               64 63                              0
+-----------------------------------+---------------------------------+
|                 0                 | CSR/RoCC result[63:0]           |
+-----------------------------------+---------------------------------+
```

普通 CSR 包排除了 shadow CSR。特权 CSR shadow 不走 type 3 普通事件包，而是随 `R_RSU` 上下文片段走 type 7 通道。

== branch/jump payload

`GH_BUF.scala:97` 到 `:118` 计算控制流目标：

- branch：taken 时为 `PC + immediate`，否则为顺序 PC。
- JAL：`PC + immediate`。
- JALR：使用 BOOM 已算出的 `jalr_target`。

payload 的逻辑布局是：

```text
+----------------+--------+---------+-------------------+----------------------+
| zero padding   | is_rvc | is_taken| committed PC     | target / next PC     |
+----------------+--------+---------+-------------------+----------------------+
  xLen-coreMaxAddrBits-2      1   1   coreMaxAddrBits          xLen
```

在 Rocket 前端，`R_BJLR` 最终保留低 `pcLen` 位目标、`pcLen` 位当前 PC，以及 taken/rvc 两个标志。高位 padding 不参与控制流消费。

= 普通事件包如何产生

== 来源是 ROB commit，不是取指或执行入口

BOOM core 在 `chipyard/generators/boom/src/main/scala/exu/core.scala:2175` 输出：

```scala
io.commit_valids := rob.io.commit.arch_valids
io.commit_uops   := rob.io.commit.uops
```

这意味着只有已经到达架构提交点的指令才有资格成为事件包。分支预测错误路径、被 squash 的 load/store 不应进入校验流。

`common/tile.scala:294` 到 `:310` 把这些信号接入 `GH_BUF`。这里有一拍寄存：

```scala
gh_buf.io.commit_uops(w)   := RegNext(core.io.commit_uops(w))
gh_buf.io.commit_valids(w) := RegNext(core.io.commit_valids(w))
gh_buf.io.gh_prfs_rd(w)    := RegNext(core.io.prf_rd(w))
gh_buf.io.jalr_target(w)   := RegNext(core.io.jalr_target(w))
```

load/store 的地址和数据不是从通用 ALU 猜出来，而是根据提交 load/store 的数量，从 `lsu.io.ldq_head` / `stq_head` 压紧映射到各 commit lane。LSU 自身的 `ldq_head_delay`、`stq_head_delay` 也已经是寄存输出。

== 哪些提交指令会被过滤出来

`GH_BUF.scala:128` 的 `can_fwd` 同时要求：

- `io.gh_can_fwd === 0`；
- 当前 lane `commit_valid`；
- 指令属于 load、非 fence store、带目的寄存器的 RoCC、非 shadow CSR、branch/JAL/JALR 之一。

大核 tile 将：

```scala
gh_buf.io.gh_can_fwd := ght_bridge.io.out | (!if_correct_process_bridge.io.out)
```

所以只有监控开关允许且当前进程命中时才会产生包。这里的信号名容易反直觉：`can_fwd` 在 `gh_can_fwd == 0` 时才成立，实际是 active-low mask 语义。

== GH_BUF 内部如何排队

`GH_BUF.scala:73` 为每个 BOOM decode/commit lane 实例化一个深度 32 的 `GH_FIFO`。逻辑分两步：

+ 入队：用 `PopCount(new_packet.take(i))` 压紧本周期有效事件，再通过轮转 `buffer_enq_ptr` 分配到各 bank。
+ 出队：从 `buffer_deq_ptr` 开始，每拍最多选择 `GH_TOTAL_PACKETS = 2` 个非空 bank，组成 lane 0 和 lane 1。

当 `io.cdc_not_ready` 为高时，`GH_BUF.scala:207` 禁止出队，因此当前事件留在 GH_BUF，而不是在 GHM 队列满时直接丢掉。

`ght_filters_empty` 只有在所有 bank 都空、且本周期没有新事件时才为高：

```scala
io.ght_filters_empty := buf_all_empty && !new_packet.reduce(_|_)
```

这个稳定排空条件随后参与窗口完成判断，防止“最后一批事件刚入 GH_BUF，但旧的 empty 还没更新”造成过早完成。

= 窗口、序号与上下文包如何产生

== R_IC 先决定“这是谁的第几段”

`R_IC` 位于 `chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala`。它维护：

- `crnt_target`：当前目标 checker。
- `ic_status(i)`：checker 是否被一个窗口占用。
- `ic_counter(i)`：该窗口的大核提交指令数，bit 15 是 done 标志。
- `checker_segment_id_reg(i)`：该 checker 当前窗口的 32-bit sequence。
- `checker_big_owner_reg(i)`：多大核扩展下的 owner；当前 `v1Config` 只有一个大核。

状态机定义于 `R_IC.scala:150`：

```text
reset -> presch -> sch -> cooling -> snap -> trans -> check -> postcheck
```

各状态与校验包的关系：

#table(
  columns: (1fr, 3.8fr),
  table.header([*状态*], [*与包相关的动作*]),
  [`sch`], [从未忙且被 enable mask 允许的 checker 中选择目标。],
  [`cooling`], [等待 RSU 不忙，把 `crnt_target` 切到新目标。],
  [`snap`], [等待 ROB 可安全建立快照，发出 `if_dosnap` 或 `if_dosnap_priv`；新窗口在这里分配 sequence。],
  [`trans`], [等待 `R_RSU` 发送上下文片段。],
  [`check`], [BOOM 继续提交，GH_BUF 产生普通事件包，`ic_counter` 累加。],
  [`postcheck`], [把当前 checker 的 `ic_counter` bit 15 置 1，通知小核窗口事件数已经封口。],
)

序号在 `R_IC.scala:161` 到 `:171` 分配：

```scala
val snapshot_accepted = (if_dosnap | if_dosnap_priv).asBool
val package_allocated = snapshot_accepted && !ctrl(0).asBool
val allocated_packet_seq = packet_seq_counter + 1.U
when (package_allocated) {
  packet_seq_counter := allocated_packet_seq
  active_packet_seq := allocated_packet_seq
  checker_segment_id_reg(crnt_target_ic) := allocated_packet_seq
}
```

sequence 不是 136-bit lane 的一部分。GH_BUF 只写目标和类型；到了 GHM，GHM 根据目标 checker 查询 `checker_segment_id`，再给事件组和上下文片段加上 sequence。

== R_RSU 生成开始和结束检查点

`R_RSU` 位于 `chipyard/generators/rocket-chip/src/main/scala/r/R_RSU.scala`。收到 snapshot 后，它保存：

- 32 个整数 ARF；
- 32 个浮点 FARF；
- 40-bit PC；
- 8-bit FCSR；
- 特权窗口还会保存 `CSRshadows`。

普通上下文按每两拍一个片段发送：

- index 0..31：`payload = {FARF[index], ARF[index]}`。
- index `0x20`：`payload = {56'b0, FCSR[7:0], 24'b0, PC[39:0]}`。
- 特权上下文在 index `0x20` 后继续发送 CSR shadow 对，每片 128 bit；`arfs_index` 的最高类别位标记 CSR。

`R_RSU.scala:227` 和 `:228` 同时生成两个路由 header：

```scala
arfs_pidx    := Cat(ic_crnt_target(4,0), 7.U(3.W))
arfs_ecp_dest:= Cat(ic_old_crnt_target(4,0), 7.U(3.W))
```

这是一处很关键的设计：*同一份边界快照既是新 checker 的 CPS，也是旧 checker 的 ECP*。

- `arfs_pidx` 指向新窗口的 checker，该 checker 把片段当作 CPS（Checkpoint Start）。
- `arfs_ecp_dest` 指向上一窗口的 checker，该 checker 把同一片段当作 ECP（End Checkpoint）。

== BOOM 到 GHM 的 153-bit 上下文格式

大核 tile 在 `chipyard/generators/boom/src/main/scala/common/tile.scala:336` 拼接：

```scala
Cat(core.io.arfs_ecp_dest, core.io.r_arfs_pidx(0), core.io.r_arfs(0))
```

位级格式是：

```text
152       145 144       137 136       128 127                     0
+------------+-------------+-------------+-------------------------+
| ECP route  | CPS pidx    | arfs_index  | context payload[127:0]  |
| 8 bit      | 8 bit       | 9 bit       |                         |
+------------+-------------+-------------+-------------------------+
```

`CPS pidx` 和 `ECP route` 都使用低 3 bit = 7；目标 checker 编号在其目标字段中。`arfs_index` 则描述 payload 是第几个 ARF/FARF、PC/FCSR，还是 CSR shadow。

= GHM 如何路由并跨时钟域

== 顶层连接

`ChipyardSystem` 在 `chipyard/generators/chipyard/src/main/scala/System.scala:42` 将 `GHMCore` 挂到 subsystem。包不是通过普通 TileLink transaction 传递，而是通过 `BundleBridge` 信号网络：

```text
BoomTile.ght_packet_out_SRNode
  -> HasTiles.tile_ght_packet_out_EPNodes
  -> GHMCore.ghm_ght_packet_in_SKNodes
  -> GHM.io.ghm_packet_in

GHM.io.ghm_packet_outs
  -> HasTiles.tile_ghe_packet_in_EPNodes
  -> RocketTile.ghe_packet_in_SKNode
```

上下文路径与此平行：`core_r_arfs_SRNode -> GHM -> core_r_arfs_c_SKNode`。节点宽度集中定义在 `chipyard/generators/rocket-chip/src/main/scala/tile/BaseTile.scala:248` 到 `:310`。

== 普通事件的路由不是看 gh_packet_dest

GHM 在 `GHM.scala:102` 到 `:107` 直接从每个 136-bit lane 的 header 中取 `bits[6:3]`：

```scala
packet_dest(b)(i) := ghm_packet_in(b)(...)(6,3)
```

对每个 checker，任意 lane 的目标命中就将*整个 272-bit 组*送入该 checker 的数据队列。因此：

- 两个 lane 都给 checker 2：只入 checker 2 的队列一次。
- lane 0 给 checker 1、lane 1 给 checker 2：同一 272-bit 组分别入两个 checker 队列。
- 每个 RocketTile 收到整组后，再按 header 目标过滤掉不属于自己的 lane。

`GH_BUF.gh_packet_dest` 是两个数值目标的按位 OR，并不是严格的 one-hot bitmap。当前 GHM 不靠它路由；`GHM.scala:338` 仅用其“是否非零”更新调试计数器。

== 给普通事件组添加 sequence 和 valid

每个 checker 有一个深度 256 的数据 `AsyncQueue`：

```scala
val packetCdcBits = 2 * 136 + 32 // 304
AsyncQueue(UInt(packetCdcBits.W), AsyncQueueParams(256, 2))
```

入队数据是：

```text
303                       272 271                              0
+----------------------------+----------------------------------+
| sequence[31:0]             | original two-lane group[271:0]   |
+----------------------------+----------------------------------+
```

只有真正 `deq.fire` 的 checker 周期，GHM 才输出：

```text
304 303                   272 271                              0
+---+-------------------------+----------------------------------+
| V | sequence[31:0]          | two-lane group[271:0]            |
+---+-------------------------+----------------------------------+
```

所以 Rocket 侧总宽度为 `1 + 32 + 272 = 305 bit`。没有出队时整条输出为 0，`V` 是一个单周期有效标记。

== 给上下文添加 sequence，并移除 ECP 路由元数据

每个 checker 另有深度 8 的 ARFS `AsyncQueue`。GHM 使用 153-bit 输入中的 CPS 和 ECP 目标做路由，但只把低 145 bit 发给 checker：

```text
BOOM 输入 153 bit：{ECP route[7:0], CPS pidx[7:0], index[8:0], data[127:0]}
                                      |<------ checker payload 145 bit ------>|
```

ECP route 已经完成路由使命，不能继续占 checker payload。GHM 显式切出 `selectedArfInput(144, 0)`，再前置 sequence。checker 最终收到：

```text
177 176                  145 144      137 136      128 127       0
+---+------------------------+------------+------------+----------+
| V | sequence[31:0]         | CPS pidx   | index[8:0] | data     |
+---+------------------------+------------+------------+----------+
  1          32                   8             9          128
```

总宽度为 `1 + 32 + 145 = 178 bit`。

同一个 BOOM 上下文片段可能同时入新 checker 的 CPS 队列和旧 checker 的 ECP 队列。GHM 为每个目标 checker 分别读取该 checker 的 `checker_segment_id`，所以两份副本可带不同的窗口 sequence。

== 两个独立队列如何维持窗口次序

普通事件和上下文走不同 `AsyncQueue`，物理上可能先后不一致。GHM 在出队前比较两边队头 sequence：

```scala
dataHeadInOrder = !arf.valid  || dataSeq <= arfSeq
arfHeadInOrder  = !data.valid || arfSeq  <= dataSeq
```

含义是：

- 两个队头 sequence 相同，可以在同一 checker 周期同时出队。
- 数据队头更旧，只让数据先走。
- 上下文队头更旧，只让上下文先走。
- 较新的片段留在原 `AsyncQueue`，不会为了消除冲突而丢弃。

== checker 如何给数据通路反压

Rocket 将 `packet_cdc_ready` 放在 `ghe_event_out[4]`，将本地日志 FIFO near-full 放在 bit 0。GHM 的数据出队条件是：

```scala
data_cdc_ready(i) := ghe_event_in(i)(4) && !ghe_event_in(i)(0)
```

GHM 数据或 ARFS 入队口不 ready 时，`bigcore_hang(i)` 为高。大核 tile 将启用 checker 对应的 hang 位 OR 起来，接到 `GH_BUF.cdc_not_ready`；GH_BUF 停止出队，之后自己的 FIFO 接近满时再阻塞 BOOM commit。

== 什么才叫“所有包已经进完小核”

仅仅 `AsyncQueue` 暂时为空不够，因为 GH_BUF 中可能还有尚未进入 GHM 的尾包。当前实现对每个 checker 使用：

```text
packet_ingress_empty
  = data AsyncQueue empty
  & ARFS AsyncQueue empty
  & synchronized GH_BUF filters_empty level
```

`filters_empty` 通过三级同步器进入 checker 时钟域。这个组合结果同时送到：

- `RocketCore.io.cdc_empty`，参与完整窗口完成条件；
- `GHM.ghm_status_outs`，作为控制状态的一部分。

= RocketTile 如何接收和拆包

== 第一道门：可靠性模式

RocketTile 中的 `s_or_r` 由本 tile 的 GHE RoCC 命令寄存器提供。`GHE.scala:50` 的 funct `0x01` 写 `s_or_r`；只有 `s_or_r == 1` 时，当前 RocketTile 才把普通事件当作可靠性校验包：

```scala
packet_en(i) := dataSeqAccepted && s_or_r.asBool && ...
packet_bj_en(i) := dataSeqAccepted && s_or_r.asBool && type === 4.U && ...
```

如果软件没有把 checker 配成 reliability 模式，包虽然可能到达 tile，但不会进入 LSL/BJL。这是硬件链路成立的前置条件。

== 第二道门：sequence 高水位

`RocketTile.scala:184` 到 `:209` 分别取普通事件和上下文的 valid/sequence：

- `dataSeqValid` / `dataSeq` 来自 305-bit 普通组。
- `arfsSeqValid` / `arfsSeq` 来自 178-bit 上下文。
- sequence 0 不可用。
- 同周期两者都有时，先取较大的 `cycleMaxSeq`。
- 只有 `cycleMaxSeq >= packetSeqHighWatermark` 才接受；严格更大时更新高水位。
- 同周期中 sequence 小于 `cycleMaxSeq` 的那一类片段被拒绝，避免混入新窗口。

GHM 的队头排序是第一道防线，RocketTile 的高水位是第二道防线。

== 第三道门：目标和类型

当前 `v1Config` 只有一个大核，因此：

```scala
checker_num = hartId - GH_NUM_BIG_CORES + 1
```

得到 hart 1 -> checker 1，hart 2 -> checker 2，依此类推。每个 lane 只有 `header[6:3] == checker_num` 才被本 tile 接收。

普通事件随后分两路：

- type 4：`packet_bjvec_in`，送 `Frontend.packet_bj`。
- type 1/2/3/5：`packet_vec_in`，送 `RocketCore.packet_lsl`。

type 0、type 7 不进入普通 LSL；type 7 只走独立上下文端口。

== 上下文如何判断 CPS 还是 ECP

`RocketTile.scala:164` 中名为 `arfs_index` 的变量实际取的是上下文 `CPS pidx[7:0]`，这个名字容易误导。若它的目标等于本 checker，`arfs_if_CPS = 1`；否则，该片段是因为已被移除的 ECP route 命中本 checker 而到达，于是 `arfs_if_CPS = 0`。

之后：

- CPS：`R_RSUSL` 写入 `arfs_ss` / `farfs_ss`，index `0x20` 保存开始 PC/FCSR。
- ECP：`R_RSUSL` 写入 `arfs_ss_ECP` / `farfs_ss_ECP`，供窗口末比较。
- CSR 类上下文：由 `CSRFile` 写入开始 shadow 或 ECP shadow。

= 小核如何真正使用各类包

== CPS：先恢复重放起点

上下文片段到达后，`R_RSUSL` 先缓存在本地。软件对 checker 发 GHE `COPY`（funct `0x60`）后，`arf_copy_in` 经一拍成为 `paste_arfs`，`R_RSUSL` 依次输出 index 0..31：

```scala
rf.write(rsu_slave.io.arfs_idx_out, rsu_slave.io.arfs_out)
io.fpu.r_farf_bits := rsu_slave.io.farfs_out
```

PC 从 index `0x20` 的 payload 恢复，FCSR 也在该 index 更新。`R_ICSL` 接受 COPY 后进入 `fsm_checking`，Rocket 开始从 BOOM 的 CPS 重放。

== load：包数据替代小核真实内存响应

type 1 包进入 `R_LSL` 的 load FIFO。Rocket 执行到 load 时，不再以自己的 DCache 响应作为结果，而是请求 LSL：

```text
Rocket load request {addr, tag, cmd, size}
       -> R_LSL 出队下一条 BOOM load 包
       -> 返回 {BOOM load data, BOOM addr, cacheable}
       -> BOOM load data 写入 Rocket 目的寄存器
```

这种做法的目的，是消除“重放时内存已经被 BOOM 或其他核改变”带来的非确定性。

`R_ELU` 对 load 的显式错误条件只有地址不一致：

```scala
err_ld := ld_valid && (rocket_req_addr =/= boom_packet_addr)
```

load 数据不直接比较，因为 Rocket 正是用包里的 BOOM load 数据继续执行；再拿它和自己比较没有意义。错误数据对后续计算的影响最终可在 ECP 的 ARF/FARF 比较中暴露。

== store：比较地址和写数据

type 2 包进入 store FIFO。Rocket 执行 store 时，LSL 给出 BOOM 的期望地址和数据。`R_ELU.scala:93` 比较：

```text
Rocket store address == BOOM packet address
Rocket store data(size masked) == BOOM packet data(size masked)
```

任一不等就产生 `error_st`。`R_ELU` 还把 PC、双方地址和双方数据写入一个错误日志 FIFO。

在 checker mode 中，访存响应路径被 LSL 替代，代码还屏蔽了正常 DCache 的 load/store page fault、guest fault、access fault 和 misaligned fault。因此这里主要是在重放 BOOM 已观察到的架构行为，不是让 Rocket 独立重新访问同一内存并比较两个真实响应。

== LR/SC/AMO：不能直接套用普通 load/store 结论

原子访存在 BOOM 侧的包类型和 Rocket 侧的请求类型不是同一套编码，需要分两步看：

#table(
  columns: (0.65fr, 1.55fr, 1.05fr, 2.75fr),
  table.header([*指令*], [*BOOM -> 事件包*], [*Rocket `lsl_req_cmd`*], [*R_ELU 的当前处理*]),
  [`LR`], [`uses_ldq=1`，因此是 type 1；包中带回读结果。], [`01`：只读。], [按 load 路径比较地址，并把 BOOM 包数据写入 Rocket 目的寄存器。],
  [`SC`], [`uses_stq=1, is_amo=1`，因此是 type 2；上 64 bit 是 SC 成功/失败结果。], [`11`：同时读写。], [`cmd 11 被归入 load 侧，只比较地址；不走 store 数据比较。包结果用于 Rocket 写回。],
  [`AMO`], [`uses_stq=1, is_amo=1`，因此是 type 2；上 64 bit 是 AMO 架构结果。], [`11`：同时读写。], [与 SC 相同，只走地址校验和结果重放，不比较 Rocket 写操作数与 BOOM 原子写数据。],
)

Rocket 在 `RocketCore.scala:1705` 用下式把 5-bit memory command 压缩成 LSL 的 2-bit command：

```scala
lsl_req_cmd := Cat(isWrite(mem_ctrl.mem_cmd), isRead(mem_ctrl.mem_cmd))
```

`rocket/Consts.scala:85` 和 `:86` 把 `M_XSC` 及所有 AMO 同时定义为 read 和 write，所以它们得到 `11`。`R_LSL.scala:120` 对任何有效访存请求都按时间顺序取出下一个 load/store 包，且 `:150` 因 cmd 最低位为 1 而把包结果标为可写回。但 `R_ELU.scala:63` 到 `:65` 将 `01` 和 `11` 都归为 load，只有精确的 `10` 才归为 store。

#block(fill: rgb("fff0f0"), stroke: rgb("dc8b8b"), inset: 10pt, radius: 4pt)[
  *当前覆盖边界：* LR 与普通 load 一样只显式校验地址。SC/AMO 虽然使用 type 2 包，但在 `R_ELU` 中也只显式校验地址；它们的写操作数、原子内存效果和 SC 保留集语义没有像普通 store 数据那样被独立比较。由于 BOOM 结果本身又被用作 Rocket 写回输入，最终 ECP 寄存器比较不等价于独立验证了这些原子语义。
]

== CSR：把 BOOM 结果送入 Rocket 写回

type 3 包的低 64 bit 进入 `R_LSL` CSR FIFO。Rocket 的相应 CSR 指令到 WB 时：

- FIFO 非空：取出 BOOM CSR 结果，作为 `rf_wdata` 写入 Rocket 目的寄存器。
- FIFO 为空：`lsl_resp_replay_csr` 使该指令 replay，等待包到达。

所以普通 CSR 包主要是*重放输入*，不是直接的 CSR 值比较器。特权 CSR 最终状态的独立比较由 CSR shadow CPS/ECP 通道完成。

== RoCC：处理带寄存器写回的自定义指令

type 5 只为 `uopROCC && ldst_val` 产生，即有整数目的寄存器的 RoCC 指令。小核相应 RoCC response 到达时，从 `R_LSL` RoCC FIFO 取 BOOM 写回值，并用它完成寄存器写回；FIFO 暂无数据时 replay。

没有目的寄存器写回的 RoCC 指令不会形成 type 5 包。

== branch/jump：约束前端，而不是在 ELU 中比较

type 4 不经过 LSL，而是进入 Frontend 内的 `R_BJLR`。每条记录包含：

- BOOM 提交时的控制流指令 PC；
- BOOM 实际 target/next PC；
- taken；
- 是否 RVC。

Rocket 前端将当前取指 PC 与 BJL 队头的 committed PC 匹配；命中后用包里的 taken 和 target 形成 `predicted_npc`。BJL 支持：

- reserve：前端暂时使用一条分支记录；
- commit：对应 Rocket 分支真正提交后永久出队；
- rollback：流水线 redirect/flush 时撤销投机 reserve；
- replay：I-cache 等原因导致前端重放时回退投机指针。

这里没有一个简单的 `rocket_target != boom_target` 错误位。包直接约束重放控制流；若 Rocket 的计算或控制状态仍有偏差，通常由指令计数、最终 PC 或 ECP 架构状态比较暴露。

== ECP：最终架构状态比较

当 `R_ICSL` 根据 done bit 和提交计数判断已执行到窗口末尾后，触发 post-check：

- `R_RSUSL` 逐项比较 Rocket 当前 ARF/FARF 与 ECP 保存值。
- `CSRFile` 在需要时逐项比较特权 CSR shadow 与 ECP shadow。
- 任一 ARF/FARF 不一致产生 `rsu_slave.check_error`。
- 任一 CSR shadow 不一致产生 `csr.shadow_check_error`。

`RocketCore.scala:1254` 汇总当前包的显式错误源：

```scala
package_error_now =
  elu.error_ld || elu.error_st ||
  rsu_slave.check_error ||
  csr.shadow_check_error
```

这正好说明当前校验边界：访存事件做局部比较，普通计算指令通常不单独发包，而是靠最终 ARF/FARF 状态检查覆盖。

= 窗口何时完成，结果如何返回

== 完整完成条件

`RocketCore.scala:1274` 到 `:1277` 的 `full_check_complete` 同时要求：

- 当前确实有 `package_check_active`；
- `io.cdc_empty` 连续两个 checker 周期为高，避免 LSL 入队寄存器造成一个短暂空窗；
- `R_LSL` 的 load/store/CSR/RoCC FIFO 全空；
- ARF/FARF 比较已完成；
- 若本窗口需要 CSR shadow 检查，则 CSR 检查也已完成。

R_ICSL 自己还根据大核传来的 `ic_counter` 控制重放条数：bit 15 表示大核已封口，低 15 bit 是窗口计数。它会在达到目标条数后阻止小核多提交，并进入 postchecking。

== 新窗口提前到达会取消旧窗口

若 `package_check_active` 尚未完整完成，却观察到严格更大的 sequence，当前窗口标记为 CANCELLED：

```scala
package_cancelled = package_check_active && !full_check_complete && new_package
```

这不是 PASS，也不是 FAIL，而是“结果不再完整可信”。R_ICSL 同时回到 reset，避免旧窗口永远等不到完成条件。

== 35-bit 结果格式

结果状态定义于 `GH_GlobalParams.scala:16`：

#table(
  columns: (0.8fr, 1.2fr, 3fr),
  table.header([*status*], [*名称*], [*含义*]),
  [`0`], [`PASS`], [所有完成条件满足，期间未锁存任何显式错误。],
  [`1`], [`FAIL`], [窗口完成，但出现 load/store、ARF/FARF 或 CSR shadow 错误。],
  [`2`], [`CANCELLED`], [旧窗口未完成就被更大 sequence 替代。],
  [`3`], [保留/未知], [BOOM 侧结果统计逻辑将其视为未知状态，不接受为正常结果。],
)

RocketTile 输出：

```text
34 33       32 31                                      0
+--+-----------+----------------------------------------+
|V | status[1:0]| sequence[31:0]                        |
+--+-----------+----------------------------------------+
```

RocketCore 内有深度 4 的结果 `Queue`，并在队列满时用 waiting 寄存器保留事件。只有本地 R_ICSL 已完成 clear/reset，且 GHM 表示 ready，结果才交出。

== 结果穿过 GHM 后释放大核 checker

GHM 为每个 checker 建立深度 256 的 result `AsyncQueue`：

```text
Rocket 域：{valid, status, sequence}
      -> GHM result AsyncQueue（内部存 {status, sequence}）
      -> BOOM 域：{valid, status, sequence}
```

结果在 BOOM 时钟域 `deq.fire` 的同一拍，GHM 产生 `checker_result_release(i)`，并将其送入 `clear_ic_status_tomain`。`R_IC` 收到后清除该 checker 的 `ic_status` 和计数器，调度器才可以再次选择它。

当前实现故意不再用旧的 `R_ICSL.clear_ic_status` 脉冲直接释放大核，因为旧控制脉冲可能先于完整结果跨域到达。现在以带 sequence 的完整结果为释放依据，避免“checker 已被重用，但旧结果还在路上”。

结果还广播回 BOOM DCache。`boom/lsu/dcache.scala:927` 到 `:975` 按 sequence 检查有效性、重复、过期和 PASS 连续水位，用于包生命周期和脏写回统计。这是结果的统计用途，不是普通事件包的生成路径。

= 用一个 load 窗口走一遍

假设 R_IC 给 checker 2 分配 sequence 37，随后 BOOM 提交一条 load：

+ `R_IC` 在 snapshot 接受时把 `checker_segment_id(checker 2)` 写为 37。
+ `R_RSU` 把 CPS 上下文送向 checker 2；GHM 为每片加 `seq=37`。
+ BOOM load 到达 ROB commit，tile 从 LDQ head 得到 `{load_data, addr}`。
+ `GH_BUF` 形成 type 1。目标为 2 时 header 是二进制 `1_0010_001`，即 `0x91`。
+ 若另一 lane 无事件，272-bit 组为 `{lane1=0, lane0={0x91,payload}}`。
+ GHM 从 lane 0 header 解析出目标 2，把整个组放入 checker 2 的 data AsyncQueue，并加 `seq=37`。
+ Rocket hart 2 计算 `checker_num=2`，通过 valid、sequence、reliability mode 和 destination 四层检查。
+ type 1 lane 进入 `R_LSL` load FIFO。
+ Rocket 重放到对应 load 时，以本地请求地址向 LSL 取包；BOOM load data 作为 Rocket 的 load 结果写回。
+ `R_ELU` 比较 Rocket 请求地址和包地址。若不等，锁存窗口错误。
+ Rocket 按窗口计数执行到末尾，并完成 ARF/FARF（以及需要时的 CSR）ECP 比较。
+ 所有入口和本地 FIFO 排空后，输出 `{valid=1, status, seq=37}`。
+ 结果穿过 GHM；到 BOOM 域后释放 checker 2。PASS 时该窗口正式闭合。

= 反压、顺序与不丢包保证

== 当前设计已经具备的保护

#table(
  columns: (1.5fr, 3.8fr),
  table.header([*保护点*], [*当前硬件做法*]),
  [错误路径过滤], [事件源使用 ROB `arch_valids`，而不是执行阶段 speculative 信号。],
  [大核事件缓冲], [GH_BUF 每 bank 深度 32，跨域数据队列忙时停止出队。],
  [跨域保存], [data、ARFS、result 都用 `AsyncQueue`，不是裸多位信号同步。],
  [窗口身份], [data、ARFS、result 都关联 32-bit sequence；0 保留。],
  [独立队列排序], [GHM 比较 data/ARFS 队头 sequence，先送旧窗口。],
  [接收端防混包], [RocketTile 维护 sequence 高水位，同周期只接受最大 sequence 的片段。],
  [完整排空], [完成条件同时观察 GH_BUF、GHM 两类队列和 Rocket 本地 LSL。],
  [结果不丢], [Rocket 结果 Queue + waiting 寄存器 + ready/valid，GHM 再用 result AsyncQueue。],
  [释放有序], [BOOM checker 的释放绑定带 sequence 结果在 BOOM 域的出队事件。],
)

== 需要特别警惕的当前代码事实

#block(fill: rgb("fff0f0"), stroke: rgb("dc8b8b"), inset: 10pt, radius: 4pt)[
  以下不是协议的理想描述，而是当前源码中可直接看到的风险点。阅读和后续修改时，应把它们当成待验证或待修复项，不能默认硬件已经完全保证不丢包。
]

=== ARFS 反压没有真正送回 R_RSU

GHM 的 `bigcore_hang(i)` 同时包含 `cdc_busy(i) | arfs_cdc_busy(i)`。但 BOOM tile 当前在 `common/tile.scala:321` 写的是：

```scala
core.io.big_hang := false.B
```

与此同时，`R_RSU` 只有在 `!io.big_hang` 时才推进片段计数并产生路由 header。也就是说：

- 普通事件路径能通过 `gh_buf.io.cdc_not_ready` 间接看到 GHM busy；
- `R_RSU` 自己却看不到 ARFS queue busy。

若 ARFS AsyncQueue 真正填满，`R_RSU` 仍可能推进，而 GHM 的 `enq.ready` 为低，存在上下文片段未入队却被源端跨过的风险。深度 8 和当前生产/消费速率可以降低发生概率，但不构成握手正确性证明。

=== GH_BUF 只观察最后一个 bank 的 three-slots 状态

`GH_BUF.scala:77`：

```scala
val core_hang_up = u_buffer(params.core_width-1).io.status_threeslots
```

它没有 OR 所有 bank 的 near-full。若其他 bank 先接近满，BOOM commit 未必及时停。`GH_FIFO` 在 full 时对新 `enq_valid` 不写入，也没有 ready 返回源端，因此这可能表现为静默丢事件，而不只是性能下降。

=== sequence 比较没有处理 32-bit 回绕

RocketTile 和 RocketCore 使用普通无符号 `>=`、`>` 判断新旧 sequence。计数到 `0xffff_ffff` 后回绕为 0，而 0 又被保留；现有代码没有模序比较或 epoch reset。短期运行通常不会触发，但协议层面仍是不完整的长期运行边界。

=== 本地完整完成条件没有直接检查 BJL empty

`full_check_complete` 检查 GHM ingress、LSL、ARF 和 CSR，但没有直接把 Frontend 的 BJL empty 纳入表达式。R_ICSL 的提交计数和前端 reserve/commit 机制通常会促使分支包被消费，但若要形式化证明“结果发出前所有 branch 包都已提交消费”，还需要补足显式不变量或完成条件。

=== 其他配置与全局常量必须一起审查

同一个 `RocketConfigs.scala` 还存在写着“2 big BOOM cores”的 `MyRocketConfig` / `MEEKConfig`，但当前 `GH_GlobalParams.GH_NUM_BIG_CORES = 1`、`GH_NUM_CORES = 5`。本文只以一致的 `v1Config` 为主线。切换到多大核配置前，必须同时核对 hart ID、checker 数量、owner、时钟向量和节点宽度，不能直接套用本文的 1..4 映射。

= 按代码追踪时的最短阅读路径

如果以后需要自己重新核对一遍，建议按下面顺序读：

#table(
  columns: (0.45fr, 2.55fr, 2.3fr),
  table.header([*顺序*], [*文件*], [*重点*]),
  [`1`], [`guardiancouncil/GH_GlobalParams.scala`], [先固定核数、lane 数、包宽、sequence 和 result 编码。],
  [`2`], [`chipyard/.../config/RocketConfigs.scala`], [确认实际用哪个 Config、hart ID 和频率。],
  [`3`], [`boom/exu/core.scala` 的 R_IC/R_RSU 段], [窗口状态机输入、snapshot、sequence、ic_counter。],
  [`4`], [`boom/common/tile.scala`], [commit/LDQ/STQ 如何接入 GH_BUF；上下文如何拼接；BundleBridge 输出。],
  [`5`], [`boom/trans/GH_BUF.scala`], [header/type/payload、入队/出队、排空和反压。],
  [`6`], [`guardiancouncil/GHM.scala`], [按 header 路由、附加 sequence、四类 CDC、结果释放。],
  [`7`], [`tile/RocketTile.scala`], [valid/sequence/目标过滤；普通、分支、上下文三路拆分。],
  [`8`], [`rocket/Frontend.scala` + `r/R_BJL.scala`], [branch 包怎样 reserve/commit/rollback。],
  [`9`], [`rocket/RocketCore.scala` + `r/R_LSL.scala`], [load/store/CSR/RoCC 怎样替代正常执行输入。],
  [`10`], [`r/R_ELU.scala` + `r/R_RSUSL.scala` + `rocket/CSR.scala`], [显式错误条件和最终状态比较。],
  [`11`], [`r/R_ICSL.scala`], [小核执行条数、postcheck 和本地 clear。],
  [`12`], [`boom/lsu/dcache.scala`], [带 sequence 结果如何用于包生命周期统计。],
)

= 最后用四句话记住

+ *产生：* BOOM 在 ROB 提交端只挑不可简单重现的关键事件，GH_BUF 将每个事件编码为 `8-bit header + 128-bit payload`；R_IC/R_RSU 另外产生带窗口身份的上下文。
+ *传递：* GHM 从 lane header 解析目标，把整个双 lane 组或上下文片段送入目标 checker 的独立 AsyncQueue，并附加 32-bit sequence 和 1-bit valid。
+ *使用：* RocketTile 按模式、sequence、目标、类型拆包；LSL 提供 load/store/CSR/RoCC 重放输入，BJL约束控制流，RSUSL/CSR 用 CPS 恢复并用 ECP 做最终状态比较。
+ *闭环：* Rocket 汇总显式错误后返回 `{valid,status,sequence}`；结果跨回 BOOM 时释放 checker，PASS 才表示该 sequence 对应窗口完成了端到端校验。

#v(10pt)
#align(center)[
  #text(size: 8.5pt, fill: rgb("68758a"))[
    本文中的行号对应 2026-08-17 当前工作区；代码继续修改后应以信号名和逻辑关系为准。
  ]
]
