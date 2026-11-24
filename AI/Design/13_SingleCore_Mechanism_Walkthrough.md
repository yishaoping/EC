# PALIMPSEST 单主核硬件机制讲解

最新续作：Checker安装EVT后的held ACK已接入Main的四相mailbox；维护后重新汇合L1真实owner才compact；SW当拍pending与direct safe Put互锁已补。新增生产RSUSL→完整GHM result CDC→SCP/EVT/Controller组合测试，任务P5-04局部CODE_READY。整体仍未完成，硬件未编译或仿真，细节以05–09为准。

2026-11-21 当前续作补充：Core已直接使用生产PalimpsestIoBoundary，各状态flush同步取消；uncached AMO独立返回旧值与写终态；journal effectPending跨rollback屏蔽异步中断，mismatch转现有SCP retry。capacity park、baselineReady、quiescent仅等待实际发出的owner；Checker Get/Acquire逃生和64项全满Probe/park测试已写。EVT满表后在当前rollback停机/全验证边界复用目录单口和原flush/Probe/Release/ACK低频清除引用，真实ACK后compact并同步；普通rollback仍lazy，Seq/SW保持单调。Seq32跨Rocket/CDC复用和持续I/O不匹配仍未闭合。当前37 CODE_READY/32 IN_PROGRESS/0 NEEDS_FIX/0 VERIFIED，所有硬件NOT_RUN_BY_CODEX；下文旧快照不覆盖05/06/07/09最新状态。


## 2026-11-21 继续实施：用户已冻结的架构基线（优先于下文历史提案）

本轮已授权修改 RTL/配置/测试及任务表；仅一个 BOOM Main 和现有 Rocket Checker。禁止 Codex 执行硬件编译、elaboration、仿真、综合或 FI。以下 U-D 编号对应用户最新附件 D01–D10，避免与历史决策编号重名。

| 用户决策 | 冻结方案与实施约束 |
|---|---|
| U-D01 | 一个 Main；不增加多 Main 恢复框架，保留正常 TileLink 责任。 |
| U-D02 | SW 保存为寄存器，每周期最多 +1；有效 Pending 阻止推进，dead 由 EVT 解释。 |
| U-D03 | Controller 等待各状态所有者明确完成；不以固定拍数代替全局完成。只排空或隔离实际有责任的旧事务。 |
| U-D04 | Lazy Recovery：SCP/EVT/Current 逻辑失效后重启，按地址多周期查询，不扫描全 Cache 恢复。 |
| U-D05 | 被动回收：保留 Needed 的保守超集，复用替换、迁移、精确 ACK；无主动全 Cache history 回收流水线。 |
| U-D06 | 同址最新安全基线不得倒退；可抑制过时写回，不强制所有历史逐项入 DRAM，不要求全地址串行。 |
| U-D07 | 普通 transaction/slot ID 在旧 owner 完成后可循环复用；持久 Seq 仍单调。禁止把常规有限计数器耗尽接成永久停机。 |
| U-D08 | 不可逆 I/O 前提前关段并验证必要前驱；验证等待必须允许完成封口/分派；明确不可重复效果的恢复边界。 |
| U-D09 | 参数化小型 Escape 容量，优先复用现有缓冲；普通准入不能耗尽封口/解锁所需的预留空间。 |
| U-D10 | 简单单 Main FSM，必要握手后重启，错误工作直接失效，不等待无关后台活动。 |

工程假设：使用合法 TileLink 恰好一次终态协议；支持合法迟到/反压，不将网络任意复制旧 ACK 当作正常协议。完整 PASS 不可撤销。受保护 Main 写入带 Seq，Seq0 用于初始化/域外可信访问；平台外部写入不能绕过已有一致性/验证屏障。上述假设不授权丢失任何合法在途 owner。

所有本轮状态仍区分 CODE_READY 与 VERIFIED。没有用户验证证据，不标 VERIFIED。实现进度以 05 JSON/07/09 为准；下文静态行号及待决描述保留为当时记录，不覆盖本节。

## 2026-11-21 当前实施增量（覆盖下文旧源码描述）

用户 U-D01–U-D10 已冻结，不再等待同一设计选择确认。已实际写入：顺序 PRF/逐 owner done、普通 ID 生命周期循环、单步 SW/寄存 Gray、多周期历史 Mem 与局部被动合并、pre/post I/O 关段及单效果 journal、同址基线 receipt/obsolete/replan、四项预留/保存信用锁/未发请求 park/Checker Get 保留 way。当前机制、成本、用户运行入口和具体未完项见 05/07/08/09/15。

整体仍 INCOMPLETE：P3-15 因 EVT32 第33个不相交区间可达停机而 NEEDS_FIX；Core I/O 边界 fixture、满历史/WB/Probe 交错、全部同址发布入口仍未收敛。所有硬件 NOT_RUN_BY_CODEX。下文行号、待定方案、固定拍 restore/饱和停机等属于较早审查快照，不是当前实现；不得用旧 pending 覆盖已冻结用户方案。


2026-11-21。本文解释一个 BOOM Main 与现有四个 Rocket Checker 怎样协作，只讨论当前单 memory lane、64-byte line、单 L2 bank 的恢复配置。源码基线为 `75f2905693d6eec3b92d733e65bafa7a9c4be6dc` 加现有未提交修改；行号均属本轮读取的工作区。00–04 是实施前审计，05–09 是实施记录，10–12 是语义审查，不能把旧报告中的“缺少某模块”继续当作当前源码事实。

`PAPER` 指 [论文](/data1/gzh/EC/AI/Ref/DAC_2027_EC.pdf) 明确规定的行为；`RTL` 指当前确有的状态、连线与判断；`DESIGN_PENDING` 指工程方案、覆盖范围或完成条件仍待讨论，不表示一根现有信号断线；`NOT_CONNECTED` 只用于当前没有实现相应功能路径的地方。下面的执行例子是静态推演，不是运行结果。本文不改变 [10 语义规范](10_SingleCore_Semantic_Spec.md) 和 [12 决策状态](12_SingleCore_Design_Decision_Log.md)；待讨论的问题集中在 [14](14_SingleCore_Mechanism_Questions.md)。

## 1. 先把整个系统讲成一个连续过程

### 1.1 没有错误时：Main 先执行，Checker 跟随，外部效果等验证

PALIMPSEST 让 BOOM 继续做它擅长的乱序执行，同时让多个较简单的 Rocket 分别重执行已经划好的检查段。Main 不必每执行一条指令就等 Checker。它在一个段的起点留下架构状态 SCP，包括下一条指令的 PC、整数和浮点寄存器以及必要控制状态；执行到边界时，再留下终点状态 ECP。一个边界也可以同时是前一段的 ECP 和后一段的 SCP。每次真正开始新的执行段，都分配一个递增的 Seq，用来说明日志、结果和缓存修改属于哪次执行。

段的长度受指令数、日志空间、模式切换和缓存压力等条件影响。要形成可靠边界，Main 先停止加入新的工作，让旧指令走到架构提交边界，再捕获状态。段与 Checker 槽不是同一个东西：Checker 完成后可以检查另一个段，但新段 Seq 必须不同。日志可随 Main 推进持续发送，Checker 可以流式跟随；终点快照和最终指令数到齐，才能确认段尾。Main 继续向前时，较早多个段可以由不同 Checker 并行检查。

Checker 重执行时，不能重新读取正在被 Main 改写的共享内存来猜测当时的输入。因此 Main 把已提交的内存访问及所需数据送入 Load-Store Log。Checker 从 SCP 恢复自己的寄存器和 PC，执行同一段代码，Load 从日志取得 Main 当时读到的值；访问类型、地址和 Store 数据等则进入检查逻辑。必要的 CSR 等输入也有对应日志。这里的日志是重执行的输入流，不是记录每次写入前旧值的内存撤销日志。

Checker 到达该段终点后，将自己的寄存器结果与 ECP 比较，并汇总内存检查等错误。段完整结束且各类检查完成后，才返回带 Seq 的 PASS 或 FAIL。四个 Checker 不必按 Seq 顺序完成：Seq8 可以先于 Seq7 返回。Main 一侧把结果记在带完整 Seq 标签的 verification bitmap 中，区分“尚未结束”和“已经通过”。结果回传、Checker 本地清理和 Checker 槽释放各有握手，不能用某个瞬时完成脉冲代替整次交接。

SW 表示有效执行历史中连续通过检查的前缀。假设 SW=6，Seq8 已 PASS 而 Seq7 仍 Pending，SW 仍停在6；只有7也通过，连续前缀才能延伸到8。由此，PASS8 只证明8自身通过，还没有给8的内存修改外传许可。版本必须属于仍然有效的执行历史，并且其生产 Seq 已被 SW 覆盖，才具备安全传播资格。SW 是验证进度，不能替代历史有效性，也不负责说明某条缓存数据现在存在哪里。

Main 的 Store 同时维护可恢复的缓存内容。例如 Seq7 将 A1 改成 A7，Seq8 又将 A7 改成 A8；若回滚到 SCP8 仍可能需要 A7，覆盖前就必须把完整的 A7 留在某个可找回的位置。正常 Load 只访问 Current 映射，历史版本不作为普通同地址命中。具体历史数据可以留在 L1 旁的 SVB，也可以迁移到 L2 的历史存储；同一段内的连续 Store 则继续更新该段的 Current，而不为每个中间值保留一个回滚点。

尚未安全的数据可以在恢复域内从 L1 移到 L2，也可以从 SVB 归档到 L2；迁移必须保留原版本身份，并由接收方确认接手数据后才能释放源位置。这样，L1 不会仅因某版本还没验证就永远不能腾位置。但是 LLC 向 DRAM 写入数据、或把数据和权限交给恢复域外的观察者时，仍须通过验证屏障。同址外写还必须有序，不能让一个较旧的安全版本在较新的值之后覆盖 DRAM。

最后，检查输入与恢复历史有不同寿命。一个段检查完后，不再需要其 LSL 输入，就可以归还日志和 Checker 资源；但其他仍可回滚的 SCP 可能还需要该段留下的缓存值。SW 推进会减少这种历史需求，却不表示所有安全版本都能直接删除：每个地址最新有效的安全值仍须留在缓存层次或 DRAM 中，作为未来恢复的基线。Main、Checker、日志和缓存由这些不同的完成条件协作，而不是共享一个“完成后全清”的开关。

### 1.2 发现错误时：恢复寄存器起点，按需重建内存

`PAPER` 要求 FAIL8 恢复到 SCP8，也就是执行 Seq8 之前的架构状态。Main 首先停止继续产生可提交的新执行，定位并保住 SCP8；错误段8以及之后的有效执行后缀都作废。Seq7 即使还没验证，也属于 SCP8 之前必须保留的执行历史。恢复不是退到 SW6，也不是把全部旧 Epoch 清空。

寄存器恢复与内存恢复采用不同做法。寄存器数量有限，可以从 SCP 导入 PC、整数、浮点和必要 CSR，并重建 Rename 等内部状态。内存分布在整个层次，不能简单把 DRAM 当作 SCP8 的内存镜像：DRAM 可能还只有 A1，而正确前驱 A7 尚未安全外写。因此硬件更新 EVT，标记哪些 Seq 已被废弃，再推进映射世代 G，使旧 Current 映射逻辑失效；历史字节仍留在原处，不做全 cache 数据回滚扫描。

重启后的第一次 Load A 发现映射失效，就查找仍有效的历史候选。A8 被 EVT 排除，A7 虽然 Pending 却是最新存活值，应当被选中；取得一致性权限并重新绑定 Current 后，Load 返回 A7。之后相同地址的正常命中不必每次重新搜索历史。只有确实没有更合适缓存候选，且下层基线代表所需值时，才允许回退到下层数据。

与此同时，旧事务不能凭一次 reset 消失。已经接受的多拍传输、Probe、Store completion、保存请求和响应要完成原有责任，或被明确隔离；废弃 Checker 工作通过取消和原结果交接释放槽。当前代码采用“pin SCP → 提交 EVT → 排空 → reset/导入架构状态 → restart”的控制顺序。新段使用更大的新 Seq，A7 的生产 Seq 不因恢复变成新段的 Seq。A7 仍大于 SW6，因而可用于内部恢复，却不能直接写往 DRAM。

## 2. 当前模块怎样分工

先分清三类存储。`R_RSU` 的快照寄存器负责把边界状态发送给 Checker；每个 `R_RSUSL` 的 SCP/ECP RAM 供该 Checker 重执行和比较；新增 `PalimpsestContextMemory` 是 BOOM 自己能按 Seq 读取并 pin 住的持久 SCP。前两者不会自动替代第三者。类似地，LSL 存的是检查输入，L1/SVB/L2 history 存的是内存版本。

下表同时定义全文源码缩写；`DC:830` 等指链接文件的实际行号。BOOM、Rocket-chip 和 inclusivecache 都位于 `/data1/gzh/EC/chipyard/generators/`。

| 缩写 / 模块 | 管理的状态及合作对象 | 代表性源码 |
|---|---|---|
| CORE / BoomCore | committed shadow、snapshot 边界、停止提交、PRF/CSR 恢复和 PC redirect | [core.scala](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/exu/core.scala:2091) |
| TILE / BoomTileModuleImp | LSU、DCache、Core 的恢复端口，GH_BUF、producer seal | [tile.scala](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/common/tile.scala:162) |
| IC / R_IC | Seq allocator、producer 归属、Checker 槽、分段状态机 | [R_IC.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala:118) |
| RSU / R_RSU；CMP / R_RSUSL | Main 边界快照和串行发送；Checker SCP/ECP RAM 与比较状态 | [R_RSU.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/r/R_RSU.scala:94)、[R_RSUSL.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/r/R_RSUSL.scala:109) |
| GHM；CHK / RocketCore | DATA/ARF/控制及结果 CDC；Checker 当前段、错误汇总、清理和结果队列 | [GHM.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala:553)、[RocketCore.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala:1301) |
| LSL / R_LSL；ELU / R_ELU | 多路日志 FIFO、head/read/response 状态；访问与 Store 数据比较 | [R_LSL.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/r/R_LSL.scala:135)、[R_ELU.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/r/R_ELU.scala:64) |
| REC | ContextMemory 的16项 SCP；ExecutionHistory 的 tail/Epoch/G/32项 dead 区间；Controller 状态/target | [PalimpsestRecovery.scala](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/exu/PalimpsestRecovery.scala:26) |
| LSU；LM / BoomMSHRFile、BoomMSHR、BoomIOMSHR | LSQ/token/Store terminal；miss、LineBuffer、安装、RPQ、MMIO 准入 | [lsu.scala](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/lsu/lsu.scala:508)、[mshrs.scala](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/lsu/mshrs.scala:143) |
| DC / BoomNonBlockingDCacheModule、BoomWritebackUnit | bitmap/SW、L1 owner/key/CurGen、快照读行、WB 回执、按需恢复 FSM | [dcache.scala](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/lsu/dcache.scala:647) |
| LP / L1Preservation；KEY / CacheImage | 本地覆盖许可；跨层内容 key 与 preserve transaction 字段 | [phase1.scala](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/lsu/phase1.scala:69)、[CacheImage.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/tilelink/CacheImage.scala:12) |
| SVB / SpeculativeVersionBuffer | 16项完整快照、SPEC/WB_WAIT、查询 held response、归档回执 | [speculative-version-buffer.scala](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/lsu/speculative-version-buffer.scala:105) |
| HIST / PalimpsestVersionHistory | 64项按地址检索的整行 history、query/publish owner | [PalimpsestHistory.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/tilelink/PalimpsestHistory.scala:54) |
| INC / InclusiveCache；SCH / Scheduler | archive/query 四相 mailbox、SW CDC、history 仲裁、目录和外传调度 | [InclusiveCache.scala](/data1/gzh/EC/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/InclusiveCache.scala:192)、[Scheduler.scala](/data1/gzh/EC/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala:115) |
| L2P / L2Preservation；L2M / MSHR | 冻结 victim、读行并 archive/Put、精确回执；一致性事务/外层 Release owner | [L2Preservation.scala](/data1/gzh/EC/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/L2Preservation.scala:59)、[MSHR.scala](/data1/gzh/EC/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/MSHR.scala:807) |
| SD / SourceD；SC / SourceC | L1 Release 最后实际 bank write 后回 ACK；LLC 外层 C beats | [SourceD.scala](/data1/gzh/EC/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/SourceD.scala:225)、[SourceC.scala](/data1/gzh/EC/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/SourceC.scala:175) |

正文中的“已接线”只指这些源码连接存在；其合法交错、硬件时序和数据正确性未由本轮编译或运行确认。

## 3. 机制 A：一个 Segment 怎样成为一次完整检查

### 3.1 为什么需要边界和两份架构状态

`PAPER`（III、Fig.3、IV-E）：Checker 要从一个确定起点执行到确定终点。没有 SCP，Checker 不知道起始寄存器；没有 ECP，就无法比较段结束结果；没有 Seq，槽复用后的迟到结果可能被算到另一段。SCP 同时也是错误时的恢复目标，因此它不能随 Checker slot 一起随意复用。

以7、8为例：SCP7是进入7之前的状态，ECP7是7结束的状态；同一个安静边界可以给出ECP7和SCP8。SCP8包含7的架构结果，但“7的 Store 已提交”不等于它已经到 DRAM，甚至不等于该拍所有 Store 已完成缓存效果。恢复时必须让存活的前驱 Store 与这个架构前缀一致地结算。

### 3.2 Main 怎样分段、捕获和发送

`RTL`：IC 以 `producer_open/producer_target/active_packet_seq` 记录当前 Main 正在给谁生产日志；`package_owned` 和每 Checker 的 `checker_segment_id_reg` 记录资源归属。它在指令阈值、LSL 压力、退出/模式切换、缓存 early-close 请求等事件上进入关段过程。CORE 的 `snapshot_dispatch_block` 阻止新 uop 进入；已有 ROB 工作继续排到边界，不能先把退休一起停死再等 ROB empty（IC:239–312,456–487；CORE:2331–2373）。

CORE 等 ROB empty、有效的 committed next-PC、前一拍 commit/CSR/exception/RSU 安静、无 redirect，并且 ContextMemory 有空位，才向 IC 给 snapshot ready。IC 还用 `snapshot_armed` 保证完整拍条件。在 `snapshot_accepted && !capture_ctrl(0)` 时，`packet_seq_counter+1` 成为新 Seq，锁定 Checker 槽；注册后的 `packet_alloc_valid/seq` 同时送入持久 SCP、DCache bitmap 和执行历史 tail。不是每个模式控制快照都分配新 Seq。

RSU 在延迟的 `doSnapshot` 拍把 `arfs/farfs/PC/FCSR` 存入快照寄存器；特权快照还带 CSR shadows。merge 逐项发送整数/浮点配对数据和最后 PC/FCSR，当前目的地是新 Checker 的 SCP，`arfs_ecp_dest` 是旧 Checker 的 ECP。它没有独立逐项 ready 口，而由 GHM 的反压经 TILE 回到 `big_hang`，暂停发送计数及最后一项退休（RSU:94–125,151–165,196–233；TILE:340–357）。Checker 端 CMP 使用各自的 `SyncReadMem` SCP/ECP bank 接收，随后 paste SCP 到执行寄存器（CMP:115–118；CHK:1095–1135）。

BOOM 持久恢复副本走另一条接线：CORE 在注册 allocation 事件采集 `integer/floating/pc/epoch/csr`，送进 REC 的16项 `Mem` 加 `valid/seq` 目录。这里的 CSR 是 CSRFile 打包的8192-bit image，不等于 RSU 发给 Checker 的普通 PC/FCSR 帧（CORE:2125–2137；REC:39–68）。

### 3.3 LSL 怎样喂给 Checker，结果怎样回来

TILE 从提交 uop 对应的 LDQ/STQ header 取地址/数据，连同 PRF 数据等交给 `GH_BUF`，按当前生产 Checker 路由；GHM 的 DATA 与 ARF 使用不同传送路径，不能假定先后到达时间相同（TILE:285–343）。Checker 对 `packet_lsl` 解码出 Load、Store、CSR、RoCC 日志，进入 LSL 各 FIFO（CHK:1233–1266）。LSL 预取并保持队头，Checker 请求到来后给一个 response；类型/地址一致才消费队头，错误则向 ELU 报 mismatch。Load 用记录值继续执行，ELU 比较访问地址等；Store 还比较尺寸截取后的数据，而不是让 Checker 再对外执行 Main 的 Store（LSL:135–169,240–262；ELU:64–102）。

段尾要等一个真正的结束凭据：TILE 只有在 CORE 已到架构边界、RSU 安静、GH_BUF 已排空后，才保持带 Seq 的 producer seal。CHK 再把匹配 seal、连续两拍 ingress empty、LSL 无读/响应在途、架构比较稳定、ECP 比较、必要 CSR 比较、`R_ICSL.package_exec_done` 汇合成 `full_check_complete`。单独 ARF 比较完不够，某一拍 FIFO 空也不够（TILE:216–233；CORE:2375–2387；CHK:1437–1473）。

结果先进入 Checker 深度4的 `package_result_queue`。有错误给 FAIL，无错误给 PASS；废弃历史/超时/传输错误会生成独立 CANCELLED。队列 blocked 时保存 payload；本地 RSUSL/Frontend 清理完成才向 GHM 的结果 AsyncQueue 交接。GHM 在 BOOM 域 `deq.fire` 时送一次结果事件，同时保持 release 电平，直到 R_IC 的槽状态真正变空才撤回。因而8先完成只释放它自己的 Checker，7继续运行；bitmap 如何记账见下一节（CHK:1535–1577；GHM:553–577）。

### 3.4 SCP 何时退休，仍需讨论什么

`RTL`：REC按完整 Seq查 SCP、复制到 `held` 并置 `pinned`；response 持续到 restart 的 `response.fire` 或更早错误使 `abort`。未 pin 的 CP 若 `Seq<=SW`，或 restart 明确 discard 的 suffix，就可清 valid；读命中同拍优先保护。8先 PASS、7未完成时，SW6，因此SCP7/SCP8都保守保留，不跟槽释放一起删（REC:47–79；CORE:2097–2106）。

`DESIGN_PENDING D05/D10`：保守退休集合可以成立，但要把 RSU 的边界、持久 capture 拍、committed shadow、CSR 和延迟 Store 的前缀讲成同一个状态。本文不会把“RAM里有一条SCP8”直接当成它已是完整架构快照。取消类别与 PASS 是否绝不撤销还需 D02；当前没有“撤销一个已被SW覆盖PASS”的恢复协议。

## 4. 机制 B：Verification Bitmap 怎样产生 SW

### 4.1 先区分四件事

`PAPER`（III、IV-A/C/D）：**Valid** 说明版本来自仍保留的执行历史；**Verified** 说明生产段已经完整 PASS；**Safe** 说明它 Valid 且属于有效连续验证前缀；**NeededForRollback** 说明至少一个仍可使用的 CP 需要它作为该地址的最新前驱。这四个事实没有共享一个 valid bit。

例如SW6、7Pending时，A7是Valid而非Safe；8已PASS、7Pending时，A8是Verified而非Safe。等SW8，A8已Safe，但如果它是A的最新安全值，删掉缓存唯一副本后又没有把正确值交给DRAM，恢复基线仍会丢。反过来，dead A8即便后来满足数字`8<=SW`也无效；同段被覆盖的中间A7快照也不一定被任何CP需要。`CacheImageKey.valid`只表示“这是带生产身份的authored内容”，不是上述HistoryValid。

### 4.2 当前状态到底存在哪里

`RTL`：bitmap在BOOM时钟域的DCache，`bitmapState`包含256项 `allocated/completed/passed/seq`；Seq低8位用于定位，完整32位tag防止环形索引误认。R_IC的 `packet_alloc_valid` 设置allocated、写完整seq并清旧结果；占用冲突会报协议问题，而不是覆盖旧段（DC:2003–2011,2781–2797）。

SW本身是一个32位 `RegInit(0)`，不是把所有passed做组合max后直接输出。每拍先把新allocation和多Checker结果合进next-state，再计算下一个SW，最后寄存。结果只有同时满足“已分配/同拍分配、完整tag一致、未completed、非重复、非stale、状态合法”才接受。stale包括 `Seq<=SW` 或EVT已废弃；PASS置completed和passed，FAIL/CANCELLED只置completed而passed=false，并进入error路径（DC:2809–2846）。所以FAIL没有任何“让前缀跳过去”的直接授权。

组合扫描从`SW+1`检查连续slotPass，算出可推进距离；但最终RTL只增加0或1。另一路检查`SW+1`是否在已分配范围内且被EVT废弃，允许越过dead洞。`historySync`期间SW冻结，等历史发布后再逐拍前进。被覆盖或dead的bitmap项清除，清的是验证记录，不是cache line、LSL或SCP总开关（DC:2890–2943）。

### 4.3 按三个事件实际推演

初始SW6，slot7/slot8都allocated、completed=false，且都HistoryValid。

**事件一：PASS8，7Pending。** slot8变为completed=true、passed=true；slot7仍未完成。从7开始的连续扫描立即遇空洞，下一拍SW仍6。Checker8的结果/日志资源可以完成交接，HIST仍不准把A8写DRAM。SCP8在本实现中也继续保留。

**事件二是事件一的成功分支：随后PASS7。** slot7置PASS，扫描看见7/8连续通过。当前拍newSW7；再下一拍从8开始，于是SW8。这里不会一拍从6直接跳到8。7/8的bitmap记录在相应覆盖拍清除，SCP按其生命周期退休；缓存版本只获得安全资格，仍按独立的保存/发布ACK规则释放位置。

**事件三是另一条失败分支，不能接在PASS8之后：** 从SW6、7Pending、8尚未PASS的状态接FAIL8。slot8完成但不通过，SW仍6；Controller恢复SCP8并把8..tail记dead。若旧tail10，新段就是11。7仍Pending时SW还停6；等7PASS，当前数值frontier可逐拍6→7→8→9→10，11未PASS前停10。dead8/9/10没有变成Verified，只有数值被跳过。11PASS后可到11。若7已PASS，FAIL8本身仍不授权跨8，必须先有EVT裁剪及发布。

因此“PASS8后再FAIL8”不属于当前正常结果协议。现代码会把已完成或已covered的重复/变化结果挡在接收门外；若要支持撤销PASS，必须重新设计已经退休的CP和已经对外传播的数据，不能只补一个bitmap clear。

### 4.4 SW 怎样到缓存，谁补足裸 safe helper

本域SW直接给SVB、MSHRFile以及 `rollbackSafe`→CORE→ContextMemory。去L2的路径是 `newSW ^ (newSW>>1)` → Boring名称 `GH_L1_L2_SAFE_WATERMARK_GRAY_BORE` → INC三级同步 → Gray转binary → Scheduler，再供L2P、HIST、SourceC和MSHR使用（DC:930–939,2920–2922；TILE:687；INC:291–305；SCH:115–137）。每拍+1是逻辑编码选择，不能据此断言组合Gray源、物理skew和异步reset已验证安全。

KEY.safe与LP.safe实际都是 `!key.valid || seq==0 || seq<=SW`，没有EVT。因此必须看使用位置：

- L1普通访问先经 `CurGen==G && survives(key.seq)`；本地覆盖还需samePackage或精确lowerPreserved，或SVB已接手的lease，实际S3再核对owner/kill/token。这里的safe不是单独的DRAM许可（DC:830–846,2045–2074,3385–3397；LP:70–81）。
- SVB恢复查询检查 `valid && historyValid`，不要求SW；unsafe迁移也只需survives。SVB中`entrySafe`主要供观察，不能据名字假定它卡住所有迁移（SVB:124–147,163–166,213）。
- HIST发布检查物理valid、context.survives和KEY.safe；SCH的`historySafe`也补survives，外C调度还等publisher/staging/lock；dead release去掉data，只释放一致性责任（HIST:124–144；SCH:124–125,386–395,490–495）。
- L2P捕获时用 `!safe || !survives` 选择archive；实际外Put beat有两条件断言，SourceC实际数据beat也有检查。断言本身不是撤掉非法beat的功能门：前级准入和“已经Safe的版本不会被合法rollback作废”必须共同保证稳定（L2P:108,165–166；SC:175–182）。
- native peer取数据/权限还受L2 MSHR的park/replay隔离，不因系统只有一个BOOM就删除这个屏障（L2M:266–285；SCH:371–378,524–533）。

`DESIGN_PENDING D01/D03/D09`：需确认SW数值frontier、bitmap分配信用、完整HistoryValid及SW/EVT跨域发布和reset契约。裸helper不够这一点已明确；不能从它单独存在就反推已发现dead9写DRAM的实际运行。

## 5. 机制 C：Store 怎样保留前驱并产生新内容

### 5.1 先沿 A1→A7→A8 看为什么要有版本

`PAPER`（IV-A/B、Algorithm1）：SCP8恢复需要看到7结束后的A7。若8直接把唯一A7覆盖成A8，而DRAM还只有A1，即便整数寄存器恢复正确，后续Load也无法返回A7。跨段首次Store因此要在必要时保住前驱整行；同段多次写只改变这个段的Current，因为没有段内SCP要求恢复中间值。

`RTL`正常访问先检查L1驻留tag和Current映射。G=0时沿普通初始cache路径；回滚提高G后，映射失配在入口先进入第8节的冷恢复，不能把dead A8当普通hit。命中后S2的覆盖判断看 `imageValid/imageKey/lowerPreserved` 和请求的 `packet_seq`；同writer同Seq允许段内更新，跨段则需原值safe且已有精确下层副本，或者先拿到SVB保存lease（DC:830–858,2045–2074）。这里没有按CP地址依赖逐项计算Needed，是保守保存策略。

假设A1是可信BASE，并已在下层可取得。Seq7首次写A时，从整个前驱行继承未修改字节，得到A7，实际write fire才写新的内容key。Seq8再写时，若SW6，A7是unsafe前驱；普通cacheable `M_XWR`符合SVB快路径，就冻结这一resident incarnation，调用WritebackUnit的行读取器，把A7完整读出。只有 `snapshot_valid && SVB.capture.fire` 后才授予针对set/way/tag/slotEpoch/key及incomingSeq8的fast-line lease，阻塞的Store重试并产生A8。SVB拥有A7，L1继续拥有A8的一致性权限；没有伪造一次A7的权限Release（DC:2132–2177）。

### 5.2 数据写入与元数据不是同一件事

S2的`StoreGen.mask`送AMOALU，把旧word与新Store数据合成；S3经dataWriteArb写目标row/word。例：64字节line初始`L[i]=i`，7在offset10写小端0xBBAA，只有byte10/11变AA/BB；8再将byte11改CC。给SCP8保留的是整条L7，恢复后byte10/11须为AA/BB，offset16等相邻字仍为原图案。保存两个改动字节不能代替整行L7（DC:3294–3300,3463–3469；SVB:288–297）。

在实际`dataWriteArb.in(0).fire`上，DC分配全L1的32位`imageSerial`，写入`CacheImageKey={valid,writer,generation,contentSeq}`，其中generation是内容serial、contentSeq是请求Seq；同时CurGen绑定当前G，撤销`lowerPreserved`，记录effect token。验证完成或数据迁移不改key。Seq7再写A时key.serial仍会增加，但不会为了每次中间Store建立另一个CP历史版本；真正跨段保留的是之后CP可能需要的最终A7（DC:3380–3402,3632–3663）。

论文显式带Epoch，当前CacheImageKey没有执行Epoch字段：Seq从不复用，历史有效性由独立EVT补集推导。SVB快照里确有16位`epoch`字段，但DC的`svbEpoch`目前只RegInit为0，未见递增赋值；它不是REC的32位执行Epoch。不能拿这个同名字段解释跨Epoch筛选，筛选实际靠`historyValid`输入（KEY:12–16；DC:684–689,1887；SVB:124）。

### 5.3 SVB 实际承担什么，以及快路径的边界

SVB不是普通“被替换的当前行暂放处”。它保存被后继Store覆盖的完整前驱，可以含同地址多个历史key；不参与普通Load tag命中，却接受按地址恢复查询，按最大`(Seq,serial)`返回稳定的held snapshot。它还负责把存活快照向L2归档，持有原entry直到精确回执。`SPEC`表示可选归档的存储责任，`WB_WAIT`表示已经锁定/发送的责任，名字并不意味着数据已写DRAM（SVB:105–148,213–225,281–365）。

`DESIGN_PENDING D06/D13`：普通M_XWR有这条快路径；AMO/SC、RPQ等其他情况及SVB满时仍可能转保守WaitSafe/保存路径，不能把全部Store说成同一FSM。没有精确Needed表不一定错，但必须证明保守保留覆盖所有合法CP前驱，同时不把空间永远占满。快照多row是否在全部交错下来自同一内容，也需由freeze/owner而非示例值证明。

## 6. 机制 D：替换、Preserve 与外写的三种 ACK

### 6.1 一次普通 L1 replacement：unsafe 也可以下移

`PAPER`（IV-C/D）：恢复域内迁移与安全外写分开。设L1 victim为Pending A7，需要腾way给B；A7不能写DRAM，却可以连同原key进入L2。否则将屏障放在L1会重新限制有效cache容量。

`RTL`：L1 MSHR保存victim owner，发`wb_req`到共享BoomWritebackUnit。它逐row读入 `wb_buffer`；最后读行完成的`io.resp`只告诉MSHR“读行副本已在WB buffer”，MSHR可进入install阶段，不代表L2保存成功。WB buffer随后经LSU release交接发送多拍C `ReleaseData`，每beat携原CacheImage key，另有 `ackPending/pendingKey/pendingEpoch/allSent` 保持该source的原责任（LM:539–557；DC:78–125,237–275）。因此L1 way可向buffer交接后复用，但buffer及voluntary source不能在ACK前复用。

L2的SinkC接C数据到put buffer，L2 MSHR调度SourceD把它写入BankedStore。SourceD在最后一个真实bank write能够fire的拍才把ReleaseAck放进专用队列，携同一个image key；ACK回L1后，DC要求source、opcode、size、key、pending_sent一致，WB才产生原owner的done、撤销pending。这是L2接手数据的保存回执，不是DRAM写回完成（SD:225–236,294–335；DC:1893–1903,1942–1956）。SCH另将所有authored C数据整行staging到history RAM；查询屏障要等staging清空，避免已经迁移的历史短暂不可见（SCH:156–185）。

### 6.2 一次 A7 的 SVB archive：只交接历史，不释放 A8 权限

跨段Store产生的SVB A7不是当前A8的coherence owner，因此不能冒充A7 Release来替A8放弃权限。当前另有独立archive mailbox。SVB选一个surviving SPEC项后置WB_WAIT，经`promote.fire`交给DC，锁定整行payload和entry。DC维持 `PALIMPSEST_ARCHIVE_REQUEST/PAYLOAD`；INC同步后送`Scheduler.historyArchive`。只有HIST的`capture.fire`才置archive ACK并返回key；源核收到精确entry/key后，SVB才能free。源再降request，接收端降ACK，源看到ACK低才允许下一笔（DC:699–728；INC:198–210；SVB:281–344）。

这条路径允许Pending A7：它只是把恢复责任从SVB搬到L2。HIST按地址/key去重或接空槽；若内容已被EVT判dead，可以确认接收后丢掉，让旧事务合法结束。WB_WAIT不因FAIL直接free，防止旧回执碰到已复用entry（HIST:73–99；SVB:347–356）。四相握手是当前工程CDC方案；3拍payload与8拍request的稳定/复位约束仍属D09，不是论文指定的延迟。

### 6.3 L2 需要复用旧位置时，谁保存 victim

L2P锁定candidate的set/way/tag/key，按bank读出整行。`archiveMode = !bareSafe || !survives`：unsafe或dead走history archive，live history等RAM接手，dead可接收后drop；safe dirty则可以通过外层Put保存。成功archive或精确外存ACK才回`completed`，SCH/L2M据精确candidate设置`outerPreserved`。此字段在当前路径里表示resident内容已被另一个保存位置接手，不能总解释成“DRAM已经是这个值”（L2P:78–134,187–196；L2M:842–850）。

如果下层没有空间，capture.ready不升，源保留内容与owner。L2P、HIST、SVB各有有界空间，不存在隐藏的无限buffer。L2压力会请求验证相关段；能否在被阻塞的当前段仍未封口时提供足够信用完成关段，是第10节的问题。

### 6.4 何时真正写 DRAM，何时回收

HIST从当前RAM中按Seq/serial升序选safe项，锁住`wbIdx`，向L2P发publish。L2P将512bit整行分成外层PutFullData beats，使用独立source与64位`CachePreserveTxn`；全部beat接受后才接受匹配source/size/serial且无denied/corrupt的AccessAck。它向HIST回 `historyPublished(key)`，HIST才清原entry。普通LLC victim的SourceC Release有另一套L2 MSHR releaseGeneration/ReleaseAck责任，不能拿一个publisher ACK结算它（HIST:124–144；L2P:155–215；L2M:807–840）。

三种“ACK”因此各有边界：L1 ReleaseAck表示L2真实bank接手；SVB archive ACK表示L2 history接手；outer AccessAck/ReleaseAck表示相应外层事务完成。归档ACK不让A7变Safe，PASS也不自动产生任何保存ACK。

`PAPER`还要求obsolete suppression和同址外写序列化。`RTL`已有当前history候选升序、SourceC被pending publisher/staging阻挡、精确owner锁；但HIST entry写DRAM后free，没有持久记录“地址A已经发布到K7”。若稍后另一路又带来旧K6，仅当前RAM升序仍不能排除此旧值外写或遮蔽更新refill的模板；整机是否能走到该模板尚待证明。因此D07需统一所有同址入口的次序，或证明现coherence严格排除它。

历史位置可释放，不等于语义值可删除。论文的Needed按outstandingCP的最新有效前驱定义；当前用精确副本接手、dead过滤和safe发布做保守实现，未直接查询CP集合。最新安全基线必须一直有正确副本。LSL则在检查消费/结束后不再供Main恢复使用，其回收条件与上述三种数据责任不同。

## 7. 机制 E：FAIL8 怎样恢复 BOOM 架构状态

### 7.1 FAIL 从结果队列走到停止信号

`RTL`：Checker汇总错误并完成段尾后，FAIL8经过本地Queue、清理条件、GHM结果AsyncQueue，成为BOOM域checker_results事件。DCache先接受带完整Seq的失败；同拍多Checker失败按最小Seq选恢复目标，不按Checker编号选。`errorPending/errorPayload`保持Decoupled事件直到CORE Controller接受；若更早失败到来可以替换pending较晚事件（DC:2837–2875）。

Controller记录`target=8`，从idle入lookup；`stop`在error.valid时就可拉起，随后在整个恢复期间保持。CORE把它接进ROB的`gh_stall`、dispatch block、rename.kill、Frontend flush，屏蔽正常CSR写和恢复期间的外部interrupt输入；TILE将stop/target传给LSU和DCache。它不是一收到FAIL就reset所有cache/MSHR（REC:173–201；CORE:897,1071,1488,1546,2233,2370；TILE:164–166,678–689）。

### 7.2 Controller 的实际握手顺序

lookup中，`checkpoint.valid/seq8`与ContextMemory.read握手，REC按完整Seq找到CP8，将payload复制到held并pin；不存在则进failed。read.fire后进入history，必须等held response有效。随后`commitHistory`经TILE到DC；DC只在memoryRecoveryIdle且无historySync时允许ExecutionHistory接收。握手更新EVT/G，Controller进入drain，而不是先等一切旧事务无条件空了再发布失效历史（REC:47–79,180–207；DC:649–653,898–928）。

drain等待CORE给`quiesced`：LSU/Cache完成、被废弃Checker槽已走原release、Main RSU也安静。之所以先EVT，是为了让dead suffix解除WaitSafe/取消等待；否则“等待失败段验证才能排空”与“排空后才失效失败段”会互相等。精确等待条件在第9节，不假设Controller自己会让每个下游进展。

### 7.3 真正写回 PRF、Rename、CSR 和 PC

进入restore的第一拍产生`recoveryReset`：CORE用局部pipelineReset复位ROB、issue、decode、rename、执行单元等；TILE单独把rollbackReset给LSU，清理已协调后的LSQ。DCache/SVB/EVT/ContextMemory不是随backend一起reset的存储，否则A7和CP8会一起丢掉（CORE:171–268,2114–2118；TILE:164–166）。

之后`recoveryRestore`有效，SCP integer写真实PRF的专用口：x0保持p0=0，x1→p2至x31→p32；FP f0→p1至f31→p32，并经过recode写浮点PRF。Rename maptable切到同一固定映射，freelist重建可用集合并清branch lists/预分配valid，busytable清空；同时更新committed arfs/farfs影子。只改影子不能让已重命名的源操作数恢复，这些实际写口因此都是必要路径（CORE:247–251,1070,2139–2143；[PRF](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/exu/register-read/regfile.scala:119)、[FP](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/exu/fp-pipeline.scala:78)、[Maptable](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/exu/rename/rename-maptable.scala:112)、[Freelist](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/exu/rename/rename-freelist.scala:79)、[Busytable](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/exu/rename/rename-busytable.scala:57)）。

CSRFile从8192bit image按本模块定义的字段顺序并行导入mstatus、异常/特权/地址翻译/PMP/FP控制等寄存器及instret/HPM；外部pending输入、cycle/time不倒退。CORE送`palimpsestRestore`，不是通过几十条普通CSR指令慢慢写。哪些异步事件可跨边界、所有可选CSR配置是否覆盖，仍需D10（[CSR.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/rocket/CSR.scala:2140)；CORE:2467）。

当前`restored=RegNext(recoveryRestore)`，没有逐PRF/CSR/Frontend完成ACK。Controller随后入resume，等`restart.ready=rollbackMemoryReady`握手，CORE才把SCP8 PC作为新redirect，清FTQ而不读取不存在的旧FTQ entry；IC回调度状态，counter不倒退；同拍释放pin并清已废弃CP suffix（CORE:896–910,2099–2124；[frontend.scala](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/ifu/frontend.scala:874)；IC:505–512）。

`DESIGN_PENDING D10/D11`的具体停止点在这里：代码已经把导入写口连到真实单元，也已经把restart接到PC；但完成判定在CORE固定拍延迟上终结，没有各单元导入回执，也没有完整异步事件/在途隔离证明。不能说恢复信号没有送到PRF；同样不能把这一拍延迟称作已经完成全架构验收。

### 7.4 废弃 Checker 和 LSL 怎样离开

CHK通过同一history request及payload同步到EVT补集，发现自己package_seq不再survive就走`package_cancelled`。它abort比较、下一拍flush本地LSL，完成原清理/结果Queue/CDC release；IC的`recoveryDrained`等所有owned且Seq>=target的槽都释放。7仍有效就继续检查，8之后的CANCELLED不当作PASS（CHK:1305–1313,1516–1577；IC:495–503）。

各Checker没有独立“EVT已安装”的ACK；当前恢复依赖suffix槽真正释放等条件来协调。仍在CDC中的DATA/ARF、尚未成为本地owned的片段及reset边界需逐类证明，不能把一次LSL flush说成整个传输网络都清空。若恢复中更早FAIL7到来，Controller放弃当前pin重新lookup7，EVT再裁剪新旧后缀；不能先删除仍可用的SCP7。

## 8. 机制 F：Epoch / EVT / CurGen 怎样让 Load A 得到 A7

### 8.1 为什么 Seq 和 SW 还不够

Seq回答“哪次段执行产生”；SW回答“有效前缀验证到哪里”。回滚后旧8–10和新11可以同时还有物理字节，单靠`Seq<=SW`无法区分dead9与live7。EVT保存这种历史合法性；Epoch说明重执行阶段。G/CurGen解决另一个问题：不用扫描每一条line，也能让旧Current映射失效。内容serial则区别同段内不同字节快照，与以上状态都不同。

`RTL`：ExecutionHistory把EVT实现为32项dead闭区间的补集。FAIL8、tail10时，记录[8,10]，Epoch/G各+1；新段分配11，live7属于旧Epoch却仍合法。后来FAIL7、tail12则合并并作废[7,12]，包括第一次恢复后产生的11/12。Seq唯一，所以不需要在每个key上再存执行Epoch才能筛历史，但所有来源都必须满足“Seq确已分配”的契约：REC.survives带tail上界，DC与HistoryQuery helper目前只排dead区间（REC:103–143；DC:655–658；HIST:38–44）。

### 8.2 FAIL8 后到第一次 Load 的完整硬件路径

现在固定例子：DRAM[A]=A1，SW6，7Pending，L1 Current=A8，A7已经以完整行保存在SVB或L2；SCP8在持久目录中。这个“前驱已保存”必须由第5/6节建立，不能到恢复时才凭空生成A7。

第一步，FAIL8触发DC的`invalidate.bits=failedSeq-1=7`，SVB只立即删SPEC的Seq>7，保住A7；已发送WB_WAIT仍等原receipt。第二步，Controller pin SCP8，ExecutionHistory裁掉[8,tail]并推进G。DC启动`historySync`，用地址0的同步query带EVT快照发往L2；Query后收齐ACK高，再撤request并等ACK低，才解除historySync。地址0在这里是上下文同步用途，不是要求CPU读取零地址；接收的偶然候选不作为本次Load数据（DC:2882–2884,898–919,860–888）。

第三步，寄存器按第7节恢复并restart。该时刻内存没有被整cache改写成SCP8图像；G变了但A8字节可仍物理存在。新执行第一次请求A，入口计算`resident match && CurGen==G && survives(image.seq)`；A8既旧G又dead，不能作为正常Current命中。DC暂不接受原LSU请求，等局部cache owner安静后，保存地址/way等进入`recoveryQuery`（DC:830–858）。

第四步，DC向SVB发按地址query，随后保持L2 history request。SVB候选包括SPEC和仍有效的WB_WAIT，选择最大`(Seq,serial)`并复制成held response；L2在incoming C/staging完成后查询64项HIST，也按EVT选最大候选。DC等全部bank ACK才消费SVB response，合并两侧赢家。A8在survives筛选时消失，A7虽`7>SW6`仍参与并胜出；选择器没有Verified/SW条件（SVB:124–148；SCH:181–185；HIST:102–123；DC:860–884）。

第五步，收齐结果后降request，等ACK全低。若L1还有旧resident A8，不能不管原权限直接往B-only行写A7：DC走`recoveryWrite→recoveryWaitWB→recoveryClear`，真实Release，等原key/slotEpoch对应WB done，清旧metadata并推进slotEpoch。若L1没有resident可直接进入recoveryMiss。L2收到dead A8会按EVT处理数据与责任，外层若需要释放权限则去data；不会因为后来SW跨8就获得数据外写资格（DC:1030–1062；SCH:490–495）。

第六步，原LSU请求重试，通过正常MSHR的Acquire取得T权限；MSHR以block address锁存选中的A7 `recoveryData/key`，从LineBuffer读回、给Load response及写L1 row时改用A7 bytes，而不是普通Grant携带的A8/A1。install仍检查MSHR txn、slot reservation/tag/key，末row更新image/CurGen/lowerPreserved。获得权限与决定恢复字节是两条合作路径，不能靠history query单独伪造权限（DC:891–897,1704–1775,3611–3628；LM:177–187,474,576）。

第七步，实际Load得到A7，后续命中走已绑定新G的Current。若之后新Seq11 Store A，就按正常跨段规则保留所需前驱并产生新的内容key；被提升的A7仍保持producer Seq7，不“洗成”Seq11或BASE。A7未被SW6覆盖，因此只能留恢复域/内部迁移，不能Put DRAM。A1虽safe，却不是SCP8的最新有效值，所以不能替代A7。

### 8.3 两条不能凭实现存在就补全的前提

第一，存活resident快速重绑G的分支没有扫描下层；它假定该resident是该地址最新存活Current。第二，L2 history query实际读sidecar RAM，没有直接枚举全部普通resident、L2P正在读的candidate和所有在途buffer。当前staging屏障、源owner保留和coherent Acquire承担部分覆盖；但“查到一个旧A6”是否可能遮蔽下层更新A7，必须额外排除。

没有候选时DC确实接回普通coherent miss，不一定直接去DRAM；代码中没有独立SafeBaseline正确性证明器。若较新唯一副本还在未查询的owner、或DRAM已发布A7但旧残影A6赢得局部query，就不能把总线返回成功当作恢复正确。这里标 `DESIGN_PENDING D06/D07/D09/D11`：连线存在，候选全集、迁移原子性和baseline来源契约未完成；不存在一个已经连通的“全域baseline oracle”可替它们兜底。

## 9. 机制 G：旧事务、身份和真正的 quiesce

### 9.1 每种身份保护的对象不同

没有身份区分，rollback后的新请求可能占用了原STQ/MSHR/way，旧响应又把新owner清掉；仅地址相同不能证明响应属于当前请求。当前各计数器多数不循环复用，owner释放后数字仍继续增加。

**LSU Token。** functional allocator是64bit但限低63bit，在dispatch给Load/Store及Hella入口预留完整组预算；token经LSQ、DCache request/effect、SDQ/RPQ、completion/STORE_DONE传播。Store terminal按STQ index和完整request/effect token匹配；DC的appliedEffectToken还防重放重复产生语义写。strict Store token是另一套64bit，在commit给Store终结/计数关联，不可当成同一allocator。取消/完成释放责任，不把数字退回池；traffic RESET/rollback不清allocator（LSU:402,508–512,599–602,2132,2320–2327；DC:3380–3397；HIST:10–27）。

**Slot Epoch。** 每个L1 set/way一个16bit incarnation，安装新owner、失效等推进；S1/S2看到的slotEpoch、MSHR reservation和S3实际write要一致。它防的是“同一物理槽已经换了主人”，不是程序Epoch。slot/tag/MSHR txn/content key一起保护install，Probe和metadata clear不能绕过这些核对（DC:767–787,952–955,1704–1775）。

**Seq / Epoch / CurGen。** Seq32每Main按段分配且永不复用；Epoch32只在rollback增加，EVT区间与Seq建立历史；G32随rollback推进，per-slot CurGen32在install/重绑/新写更新。它们分别识别执行实例、历史阶段、Current映射；不能拿CurGen验证一个Store completion或拿MSHR txn证明Seq有效（IC:135,279–289；REC:103–143；DC:794,830–846）。

**内容serial。** DC的全L1 imageSerial32在每次实际semantic write增加，跨层以CacheImageKey.generation传递，验证/归档不改它。它区分同一Seq中先后字节，供去重、精确receipt和同段快照排序；不是每次网络发送的新事务号。同一个immutable key可能迁移两次（DC:942,3635–3662；KEY:12–16）。

**L1 MSHR txn。** 每个MSHR有32bit transactionSerial，primary分配锁存，携内部请求、reservation、install/retired路径，slot复用要同时匹配txn。外层TL Grant常按source路由，仍依赖原TL事务终态后source才重用；不能假设这32bit已通过所有外存adapter echo（LM:143–187,389,418；DC:1704–1775）。

**L2 Preserve / Release txn 与ACK。** L2P的64bit serial每次capture/history publish增加，经`CachePreserveTxn` echo返回并匹配全部beat已sent、source/size/status；L2 MSHR另有64bit releaseGeneration，规划新事务时增加，SourceC送出后以原serial匹配ReleaseAck。它们各自释放原owner，不负责回收另一模块的版本。L1 voluntary WB则用pending key+source/opcode/size/sent，没有独立per-WB serial（L2P:62–82,164–215；L2M:154,807–840,899；DC:1893–1903）。

因此任意复制出来的旧L1 ACK，若恰在同key第二次WB全sent后返回，单靠key无法区别两笔。协议合法TL下第一笔已经结算后不应再出现这种重复响应；是否额外容忍重复注入/跨reset响应，是D11故障模型选择，不能把它当已实现能力或把所有正常迟到ACK一概视作非法。

### 9.2 Rollback 怎样排空，不能只看 MSHR 数量

`RTL`把未接受与已接受责任分开。LSU stop期间取消尚未inflight的suffix/uncommitted Store；存活的committed prefix Store允许继续发请求，已inflight Store等原STORE_DONE。DC S3在实际效果点检查取消、kill、owner及token；accepted miss仍接Grant和发GrantAck，原RPQ/SDQ/install/completion责任继续终结。否则只清valid会留下未响应的TL owner或遗漏已提交的A7（LSU:1108,2302–2327；DC:833–837,3380–3397；LM:351–353,436–459）。

DCache的实际逻辑可直接读成：

```text
recoveryCacheIdle = MSHR fence_rdy
  && S1/S2/S3无请求 && completionQ空
  && WB读行owner空 && WB等待ACK的pending owner空
  && 无SVB capture && 无legacy跨段保存
  && Prober idle && 无MSHR replay && 无killed-store replay

ordered = MSHR fence_rdy && S1/S2/S3空
  && archive四相回到idle && completionQ/各replayResultQ空
  && WB及pending owner空 && 无legacy跨段保存

DCache.rollbackQuiesced = ordered && recoveryCacheIdle
  && memoryRecoveryState==idle && !historySync

LSU.rollbackDrained = 无inflight Store
  && 无尚未完成的committed且Seq<target Store
  && DCache.ordered && Hella idle

Controller.quiesced = DCache.rollbackQuiesced && LSU.rollbackDrained
  && IC.recoveryDrained && !RSU.busy && !RSU.core_hang_up
```

来源为DC:4752–4763、LSU:607–609、TILE:688、CORE:2105–2106、IC:495–496。这里没有“所有L2 publisher都为空”的条件，也没有逐项等待所有历史RAM空；这些存储正是恢复要保留的东西。

Probe有自己的metadata/C响应owner，可能修改slot或阻止WB；Snapshot/Capture持有行读取和freeze责任；Replay可能尚有一次效果或completion未归属。它们即使不占普通MSHR，也会在backend reset后迟到，因而纳入等待。archive还必须走完ACK高→低，不只是“已发送”。当前predicate没有单独等待`svbFastLineValid`这个lease，而是在rollbackReset路径撤销lease（DC:2770–2773）；不能误写成它等所有SVB有效项free。

这里还有一个具体的取消终态待核对：DC:3673–3682的lease release断言仅列resident身份撤销、实际Store和svbFlush，没有列rollbackReset。如果reset时lease仍有效且没有同时发生已列事件，下一拍清lease可能不被该断言认可。本轮未证明该前态在完整恢复路径可达；它说明“reset清了一个valid”还需与原owner终态及断言一致，不能补写成已经有完整取消握手。

谁保证条件最终成立？每个原FSM负责完成自己的协议：WB等L2 ACK，Prober等C路径，MSHR等下层D/E和本地install/replay，archive等HIST接收，Checker等取消/清理/CDC release。Controller只观察这些条件，没有额外强制完成器。下层最终响应、公平仲裁、足够关段/恢复信用及不会形成资源环，是进展所需假设与设计；当前没有一个模块已经证明全部等待必定终结。

### 9.3 耗尽的实际终态

当任一slotEpoch全1、imageSerial全1、MSHR serial全1、L2 preserve/release serial全1，或LSU剩余预算不足最大同时分配组、R_IC Seq全1时，identityUnavailable沿L2同步/DC/TILE/CORE汇合。Controller优先进入sticky failed，禁止同拍restart；EVT无可用区间或Epoch/G满、SCP缺失也有failed路径（DC:949–950；LSU:511–512；IC:136；REC:203–207）。

这可在正常无故障程序中到达：16bit热点slot反复替换/Probe就会用完；32bit内容serial是每Store增长，不是每段增长。释放owner并不恢复预算，当前也没有drain/reinitialize出口。局部slot/MSHR身份可研究排空后带新incarnation复用，但必须清完所有旧引用；Seq、内容key、G、EVT还关联持久cache/history/CP，普通TL队列空远远不够。保留饱和保护是合理安全措施，把failed当正常Forward Progress则是误解（D04/D11）。

## 10. 机制 H：MMIO 与容量压力为什么可能反过来卡住检查

### 10.1 普通存储可以留历史，设备效果通常不能

即使只有一个BOOM，UART写、读清零寄存器、设备AMO等外部动作也可能不可重复。普通cache Store可把unsafe数据留在恢复域；MMIO一旦发出就可能改变设备，之后恢复SCP不能自动撤销。`PAPER`（IV-C）要求不可缓存/不可重复I/O提前关段，验证preceding execution后再执行；论文未指定具体pre-I/O切分、日志或恢复floor协议。

`RTL`用TL manager的`supportsAcquireBFast(address,blockSize)`区分cacheable，非cacheable进入IOMSHR。当前准入为：不在rollbackStop、ioSeq survive，非零Seq还要求`ioSeq<=SW`；Seq0也要等executionTail<=SW。gate在IOMSHR接受之前，不是先让设备接受再等PASS；未许可时`mmioBlocked/Seq`经DC cacheEarlyClose回CORE和IC（LM:887,1119–1166；DC:940–941；CORE:2160起）。

### 10.2 现有请求走到了哪里，缺哪一步

假设段8中有一个必须完成才能使ROB排空的MMIO Load。IOMSHR等待SW>=8；SW要PASS8；PASS8要ECP/producer seal；当前snapshot要ROB empty；ROB又在等该MMIO。因此当前early-close请求即使被IC ACK，也只表示接受关段命令，不表示MMIO前已建立新边界，更不表示8已经检查。

**NOT_CONNECTED：当前没有通用“停在I/O之前保存/封口 → 验证前驱 → 执行一次设备效果 → 明确重放/恢复边界”的状态机。** 现有信号实际停在`mmioPermit=false`、IOMSHR未接受请求，关段路径可能停在snapshot_quiet的ROB empty。不能把它讲成已经有pre-I/O split，也不能只将门限改成Seq−1就补出exactly-once语义。

`DESIGN_PENDING D12/D08`推荐先定义pre-I/O段边界，等待所有可能跨该设备效果的前驱错误都已排除，再建立明确恢复floor；对仍需跨效果恢复的设备采用结果日志/效果去重。用户需要决定支持哪些I/O/中断类别及恢复能力；工程上不能在I/O执行后强行删除仍合法的更早未验证CP。

### 10.3 SVB/L2 满时，相同问题怎样出现

DC在SVB占用达到14/16时请求early close；HIST64项全满也让SCH发validationBlock及最老相关Seq。IC收到后走现有postcheck/cooling/snapshot，CORE停止新dispatch并让旧ROB工作排完。instruction threshold预留`numRobEntries+coreWidth`，防段内计数超限；它不是给Store快照、L2 history、MSHR或恢复操作预留的数据信用（DC:940；SCH:398–401；IC:252–267,459–487；CORE:2350–2353）。

若当前段的后续Load miss需要腾出history位置，位置释放又等这个段PASS，而该Load使ROB不能排到ECP，就有容量等待环模板。2个SVB余位是否足以完成所有已dispatch Store/eviction，源码没有对应最坏credit证明。模板的整机可达性本轮未动态确认，不能说已经观察到deadlock；但也没有“剩余两槽必定够用”的机制可作为讲解前提。

`DESIGN_PENDING D13`应先列资源依赖，预留close/drain/recovery所需信用，并让pending coherence优先于后续冲突写；必要时才决定escape storage。仅扩大RAM、超时转CANCELLED、身份满后failed都不能代替可继续执行的前进路径。

## 11. 时序一：正常段7执行、验证与安全发布

这是按真实接口排列的事件顺序，不假设每行只占一拍；所有下游响应均假设最终到达。起始SW6、A1为可用基线；A7后来成为需保留的前驱。`DESIGN_PENDING`行是成立条件，不能当成已实现的附加完成器。

| 事件 | 负责模块 | 状态变化 | 数据位置 | 下一步触发条件 |
|---|---|---|---|---|
| 请求开始段7，选择空闲Checker | CORE/IC | 阻新dispatch、drain到snapshot_quiet，snapshot_armed | Main committed架构状态 | ROB empty、安静边界、RSU及CP空间就绪 |
| snapshot接受、分配7 | IC/RSU/REC/DC | counter=7、producer_open、slot owned；注册alloc写SCP7/tagged bitmap/tail | SCP寄存器、ContextMemory；发送Checker SCP7 | allocation事件/merge推进且无big_hang |
| Main执行7的Load/Store | LSU/DC/TILE/GH_BUF | LSQ token/Seq；实际Store fire生成K7、CurGen当前G、清lower receipt | L1 A7；检查日志流向对应Checker LSL | 地址权限、前驱保存许可、数据端口fire |
| 达阈值或压力，形成下一边界 | IC/CORE/RSU | close旧producer、final count；ECP7，同边界可分配SCP8 | ECP7发送旧Checker；持久SCP8 | ROB/RSU/GH_BUF尾部完成、producer seal |
| Seq8将A7覆盖为A8 | DC/WB/SVB | freeze、capture A7→SPEC；lease授予后实际Store写K8 | L1 A8、SVB A7全行 | snapshot与SVB.capture.fire，匹配lease重试 |
| A7可在PASS前归档 | SVB/DC/INC/HIST | SPEC→WB_WAIT→archive ACK→SVB free | L2 sidecar A7 | capture.fire后精确entry/key回执、四相回低 |
| Checker7重执行到末尾 | CHK/LSL/CMP | 消费日志、比较ECP、汇总错误 | Checker寄存器/日志FIFO | seal+ingress drain+LSL quiescent+比较+exec_done |
| PASS7捕获、清理、返回 | CHK/GHM/IC | 本地Queue→AsyncQueue；本地idle后handoff；release槽 | Seq7结果在BOOM域 | deq.fire和held release被IC观察 |
| 更新bitmap并推进SW | DC | completed7/passed7；SW6→7；清covered项 | L1/L2数据仍在原位置 | 已有有效连续PASS；无historySync |
| SW传L2；SCP7可退休 | DC/INC/REC | 本域CP valid清除；L2接收Gray后的SW7 | ContextMemory释放槽；A7尚留history | CDC兼容上下文；pin/read不能被回收 |
| 判断A7可安全发布 | HIST/SCH | survives&&covered，选oldestSafe并锁wbIdx | L2 A7 | `DESIGN_PENDING D07`：同址次序/obsolete条件也成立 |
| 发送完整Put | L2P/外存接口 | 分配serial，逐beat send，最后waitAck | A7由HIST/L2P owner保持；DRAM更新 | 外A fire逐beat、TL责任不丢 |
| 真外存ACK，交接基线 | L2P/HIST | source/size/serial/sent/status匹配，published后free原entry | DRAM为A7；L1可仍为unsafe A8 | 精确terminal；`DESIGN_PENDING D06/D07`保证所需值/基线不丢 |

若8已经先PASS，7PASS后SW再下一拍到8；A8也获得安全资格。这里没有一条“SW推进就将所有历史free”的连线。

## 12. 时序二：Seq8 失败，第一次 Load A 返回 A7

以下走A7已归档L2、A8仍resident的分支；若A7仍在SVB，候选来源改为SVB而选择规则不变。初始SW6、7Pending、tail10。所有标记pending的条件是必须证明的前提。

| 事件 | 负责模块 | 状态变化 | 数据位置 | 下一步触发条件 |
|---|---|---|---|---|
| 7写A7、边界捕获SCP8 | IC/CORE/DC/REC | Seq7写K7；SCP8对应7后架构前缀 | L1 A7、ContextMemory SCP8 | 真实边界capture；`DESIGN_PENDING D05/D10`共同内存前缀 |
| 8写A8，先保存A7 | DC/WB/SVB/HIST | capture lease、K8；A7 archive握手 | L1 A8、L2 history A7、DRAM A1 | A7整行已接手；迁移中源仍持责任 |
| Checker8完成并给FAIL8 | CHK/GHM | package_error；result Queue/cleanup/AsyncQueue | FAIL8的完整Seq/status | 本地清理后handoff、BOOM deq.fire |
| 接受失败、阻新执行 | DC/CORE/REC | completed8且passed=false；held error、target8、stop | 数据暂仍A8/A7/A1 | rollbackError.fire；ROB/dispatch/CSR门响应stop |
| 保住存活前驱 | DC/SVB | invalidate cutoff7，删dead SPEC；WB_WAIT不提前free | A7保留，已发A8事务责任不凭空清除 | 原archive/ACK继续可完成 |
| 查SCP8并pin | REC/CORE | lookup→history，held CP8 valid | CP8 held响应 | read命中；missing则failed不restart |
| 提交错误suffix | REC/DC | EVT[8,10]，Epoch/G+1，historySync；SW保持6 | A8物理可仍在L1但历史dead；A7 live | commitHistory.fire，旧memoryRecovery idle |
| 发布上下文、取消suffix Checker | DC/INC/SCH/CHK | L2安装EVT；query ACK高→低；dead Checker取消后原release | A7始终可保存；旧片段按原owner结算 | history四相完成、IC suffix owned全释放 |
| 排空本地事务 | LSU/DC/CORE | 存活prefix Store完成；MSHR/WB/Probe/capture/replay终态 | cache/history不全清 | 见第9节quiesced；`DESIGN_PENDING D11/D13`终结性与隔离 |
| 局部reset并导入CP8 | CORE/PRF/Rename/CSR/LSU | reset拍→restore拍，固定映射与CSR导入 | CP8寄存器内容进入真实执行状态 | `DESIGN_PENDING D10`固定拍restored须等价实际完成 |
| restart到SCP8 PC | REC/CORE/IC | resume.fire，FTQ fresh；释放pin，counter仍10；后续分配11 | 内存仍A8/A7/A1 | rollbackMemoryReady；未决earlier error不得同时restart |
| 新Load A发现stale映射 | DC | CurGen!=G/!survives；拦入口，query/collect | L1旧A8不当普通hit | recoveryCacheIdle、SVB.query.fire |
| 合并SVB/L2候选 | SVB/INC/HIST/DC | EVT滤A8、选最大Seq/serial=A7；held response | recoveryCandidate携A7全行 | 收齐bank ACK和SVB response；`DESIGN_PENDING D06/D07`候选域完整 |
| 处理旧resident权限 | DC/WB/L2 | recoveryWrite→WaitWB→Clear；原key/epoch done后metadata失效 | WB缓冲承接A8；A7候选稳定 | 真Release/ACK；dead数据不能外写DRAM |
| 原Load重试并安装A7 | LM/DC | Acquire T、锁存recoveryData；行读/response/install用A7；CurGen=G | A7成为L1 Current，原Seq7/key保留 | Grant、slot/MSHR txn/安装及row握手 |
| Load完成，继续新段11 | LSU/CORE | 返回A7，正常执行 | L1 A7；DRAM仍可为A1 | A7>SW6不能外写；之后PASS7才开放安全前缀 |

这条静态时序说明有源码通路如何工作，不声称所有交错已正确：若A7根本没被保存、query漏唯一副本或baseline被旧写倒退，末端取得TL Grant也不能补回丢失数据。当前通用MMIO的pre-I/O分支是`NOT_CONNECTED`，不在这条示例路径中假装已经可用。

## 13. 当前方案与论文目标之间，真正需要讨论的差别

存储布局是明确的工程选择：论文描述常规cache ways中的Current/Historical，当前选择L1 resident + SVB16 + L2 sidecar64。这个选择可以实现相同语义，但必须给出所有候选位置及移动中的owner覆盖；不能用“sidecar里选了最大值”代替“全层最新值”。Seq隐式表达Epoch、SW逐拍数值frontier也可以成立，前提分别是分配来源完整及所有消费方兼容的EVT。

目前最值得保留的是责任边界：实际Store前保存整行、查询允许Pending、原key不因迁移或PASS改变、SCP按完整Seq pin、源owner留到精确receipt/ACK。这些机制确实接了数据路径。需要补设计的是全地址baseline发布/obsolete协议、CP前驱与候选全集不变量、跨域/reset一致性、逐类在途隔离和restore完成契约。它们不能由某条assert或一个固定拍done凭空保证。

另有明确未接的行为：通用pre-I/O split/replay/floor没有状态机，close/drain/recovery没有按最坏需求预留的资源信用，身份耗尽后没有安全重新运行协议。现有gate、early-close请求和saturation guard分别阻止过早外发、提出封口需求、避免alias，但不能被叙述成已完成的正常执行机制。14将这些真正需要选择的问题按正确性风险排序；普通已确定目标的后续接线不另包装成设计歧义。

本轮只新增13/14文档，阅读源码及既有diff，检查文件引用与文档内容；未修改RTL、配置、测试代码、任务状态或既有证据，未执行硬件编译、RTL生成、仿真、FI或commit。机制复述到此停止，工程推荐均等待用户审阅。
