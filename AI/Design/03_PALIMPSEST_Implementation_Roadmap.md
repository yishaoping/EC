# PALIMPSEST 分阶段实现路线（设计建议，未修改 RTL）

## 目标与实施边界

基线为 2026-11-21 的 `75f2905693d6eec3b92d733e65bafa7a9c4be6dc`，当前 1 Main + 4 Checker。事实和代码行号见 [01 功能矩阵](01_PALIMPSEST_Feature_Matrix.md)，失败场景与必要条件见 [02](02_PALIMPSEST_Rollback_Gap.md)。本文件所有“新增接口/模块”均为建议，不是现有 RTL；本轮未实施或仿真。

最小闭环先限定单 Main，但从第一阶段就保留 producing-core/history/transaction 身份。**先修正历史保留和对外提交契约，再开放恢复后的执行。** 不能先接一条 FAIL→PC redirect，稍后再补数据恢复。可以逐阶段做停止状态下的测试；正式 restart 必须同时满足架构状态、有效历史和在途责任条件。

## 设计决策先行

| 问题 | 建议起步方案 | 必须记录的取舍 |
|---|---|---|
| SCP 存储 | 集中 ContextMemory RAM，复用 R_RSU 采集 | 与分布式 Checker RAM pin/read 比较面积与 CDC；不能依赖 result 后立即复用的 slot |
| 历史存储 | 保留 L1 resident+SVB；增加 SVB 恢复查询，L2 独立 history sidecar 或历史 way | 论文使用 cache ways；sidecar 可满足语义，但应明确组织差异、容量与完整搜索范围 |
| 历史有效性 | 每核 Epoch/EVT 区间表，Seq 永不复用 | EVT 满/回收、连续回滚和旧有效区间保留；key 是否显式带 Epoch 必须选定 |
| Current 映射 | 独立 Cur/CurGen/G 或等效 sidecar | 保持普通 hit 路径轻量；区分 stale mapping 与从未缓存的 miss，不能只把 stale 当 BASE miss |
| 在途事务 | 第一个闭环采用保守 quiesce/drain，并阻止新效果进入 | 已弃用后缀的 dirty transfer 不应要求先安全写 DRAM；需可完成片上接收并作废，或拒绝尚未接受的事务 |
| 外部 I/O | 先提供正确 close/wait-safe 许可；不支持的操作明确暂停 | 不能以 conventional non-speculative 或 BASE key 豁免错误隔离 |
| 错误类型 | FAIL 与 transport timeout/CANCELLED 分型，但都不伪造 PASS | 是否所有取消都可恢复、CP 不可用时的停止策略需设计 |

这些是论文未固定的实现细节；有效历史、CP 一致性、safe-only 外传、LatestSurviving 和逻辑 Current 失效则是明确要求。

## 阶段 0：固定恢复不变量与历史保留契约

**目标**：防止新恢复控制建立在会丢历史的规则上；明确正常 exception、会话结束、性能 RESET 与执行 Epoch 的关系。

- 前置依赖：01/02 的证据复核，定义 outstanding CP 的含义和最早可回滚点。
- 可复用：CacheImageKey、SVB 整行 data/key、lowerPreserved/outerPreserved、正常 bitmap 与所有既有 ACK owner。
- 预计修改：`generators/boom/src/main/scala/lsu/dcache.scala`、`generators/boom/src/main/scala/lsu/speculative-version-buffer.scala`、`generators/boom/src/main/scala/lsu/phase1.scala`；需要时 `generators/rocket-chip/src/main/scala/tilelink/CacheImage.scala`。
- 关键接口/状态：区分 measurement reset、ordinary pipeline exception、execution-history invalidation；预留 `HistoryValid`、`NeededForRollback`、`rollbackTarget`，废弃 `FAIL -> invalidate(SW)` 的恢复语义。内容 serial、物理槽 epoch、执行 Epoch、映射 G 分别命名与更新。
- 风险：直接“保留全部 SVB”虽不丢数据，却可能耗尽容量；必须同时定义安全回收或正确阻塞，不能只去掉删除条件。
- 验收：SW6/FAIL8 时 K7 不被删除；正常 exception 和统计 RESET 不丢唯一恢复副本；WB_WAIT 原责任仍保持至匹配 ACK。每种删除必须具有“废弃历史”或“所需值已有等效可用副本/不再为任何 CP 所需”的证明。
- 最小定向测试：[04 的 T03/T06/T16](04_PALIMPSEST_Verification_Plan.md#test-cases)。先能重现当前谓词反例，再验证新历史保留契约；此阶段不声称 CPU 可重启。

## 阶段 1：错误事件、Rollback 主控与稳定停止边界

**目标**：从 Checker 结果启动可观察、可握手的恢复事务，先停在安全边界，不立即 restart。

- 前置依赖：阶段 0 的身份和保留约定。
- 可复用：RocketCore result Queue、GHM result AsyncQueue、DCache 结果校验、R_IC ownership/producer seal；本地 slot/token interlock。
- 检错覆盖配套修改：`generators/rocket-chip/src/main/scala/r/R_RSUSL.scala`、`generators/rocket-chip/src/main/scala/rocket/RocketCore.scala`，必要时 `rocket/CSR.scala`。先补 f0 的结束比较，并通过单状态失配确认 PC/FCSR/CSR 覆盖；不能只注入一个人工 FAIL 来验收真实检错入口。
- 预计新增：`generators/boom/src/main/scala/exu/RollbackController.scala`（建议名）。预计修改：`generators/boom/src/main/scala/lsu/dcache.scala`、`generators/boom/src/main/scala/exu/core.scala`、`generators/boom/src/main/scala/common/tile.scala`、`generators/rocket-chip/src/main/scala/r/R_IC.scala`；需要扩宽事件时修改 `generators/rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala`、`GHM.scala` 和 `generators/rocket-chip/src/main/scala/subsystem/HasTiles.scala`。
- 关键接口/状态：`error(valid,ready,{core,seq,history,errorKind})`、`stopIssue/stopAlloc`、`cpPinReq`、`quiesceReq/done`；建议 FSM `Idle→CaptureError→Stop→WaitCP/WaitDrain→...`，完成门默认关闭。多错误选最早仍有效错误，所有事件 held-valid 到 accepted。
- 风险：过早清 Checker slot 丢 SCP；以清队列代替完成 TL 责任；停住后仍有 committed Store 产生 cache 效果；复用常规 exception 的 SVB flush 反而丢历史。
- 验收：每个被接受 Error 有唯一恢复事务；不能丢失 backpressure 下事件；错误核停止分配新段和产生未授权外部效果；没有 restore 完成前不 restart。CANCELLED 不被当 PASS。
- 最小定向测试：T25（真实检错覆盖）、T05（FAIL、乱序/同周期多错误）、T11（late result）、T14（握手停顿）；观察控制停止即可验收阶段功能，运行恢复仍未完成。

## 阶段 2：持久 SCP 与 Architectural Checkpoint Restore

**目标**：按 failed segment 定位正确 SCP，真实恢复 BOOM 的架构执行状态。

- 前置依赖：阶段 1 能稳定停止并 pin CP，阶段 0 保证相关内存历史仍在。
- 可复用：R_RSU 的 committed snapshot 采集、BOOM arfs/farfs shadow、ROB committed next-PC；Checker 恢复实现可作为协议参考，不能直接当成 BOOM 已有 restore。
- 预计新增：`generators/boom/src/main/scala/exu/ContextMemory.scala`。预计修改：`generators/rocket-chip/src/main/scala/r/R_RSU.scala`、`generators/boom/src/main/scala/exu/core.scala`、`rob.scala`、`register-read/regfile.scala`、`rename/rename-stage.scala`、`rename/rename-maptable.scala`、`rename/rename-freelist.scala`（以上简写文件均相对 BOOM 的 `exu/`）、`generators/rocket-chip/src/main/scala/rocket/CSR.scala`；FPU/IFU 对接文件按实际 restore 方案确定。
- 关键接口/状态：CP directory `{core,seq,epoch,valid,pinned,complete}`；快照捕获/流尾握手；`restoreReq/restoreData/restoreCommit/restoreDone`；PC/int/FP/FCSR/所需 CSR 集合及权限模式。清除 stale busy/issue/ROB/branch/LSQ 状态，重建有效 rename/physical mapping。
- 风险：只恢复提交 shadow，PRF 仍为错误值；普通段未采集 CSR；恢复到段尾而不是段首；SCP 数据尚未完整即标 complete；x0、FP boxing/flags、privilege、interrupt/translation 状态不一致。
- 验收：任意目标段按 Seq 定位其起始 CP，后续快照/slot reuse 不覆盖 pinned CP；单步恢复后的 PC、32 个 int/FP 寄存器和约定 CSR 与保存值逐项相等。所有恢复 beat 完成后才提交恢复点。
- 最小定向测试：T05 的寄存器子集、T17 全架构状态、T18（恢复过程中 trap/privilege 边界）。此时可保持 Main 停止，通过 debug readback 验收，不能以 PC 相同替代架构一致。

## 阶段 3：执行历史、SW 与 Current mapping 逻辑失效

**目标**：实现论文 EVT、新 Epoch、fresh Seq 和 G；废弃历史不再被读取或作为安全版本外传。

- 前置依赖：CP 目录知道所有仍可回滚的起点，阶段 1 恢复事务提供边界。
- 可复用：R_IC 单调 counter、tagged bitmap、CacheImage 内容身份、L1 slotEpoch（继续仅负责物理 owner）。
- 预计新增：`generators/boom/src/main/scala/exu/ExecutionHistory.scala`（含或拆分 EVT/G）。预计修改：`generators/rocket-chip/src/main/scala/r/R_IC.scala`、`generators/boom/src/main/scala/lsu/dcache.scala`、`speculative-version-buffer.scala`、`generators/rocket-chip/src/main/scala/tilelink/CacheImage.scala`、`generators/sifive-cache/design/craft/inclusivecache/src/Directory.scala`、`MSHR.scala`、`Scheduler.scala`、`InclusiveCache.scala`；其他 TL user/echo 传输适配随字段方案审查。
- 关键接口/状态：每核 `Epoch/EVT/G`、`historyQuery/commit`、版本 `(core,Seq,Epoch)`、Current mapping `(Cur,CurGen)`；`HistoryValid(v) && v.Seq<=SW[core]`；bitmap 作废区间/迟到结果过滤，counter 不退回错误段号。
- 风险：只让 SW 跳洞而仍用旧 Seq 比较会把废弃 A8 重新判 safe；把 G 写进内容 generation 会破坏已有 ACK 身份；G 失效但查询把 stale 当普通 miss，错取 A1；EVT 容量/位宽耗尽；异步更新跨域撕裂。
- 验收：错误段及其后 PASS 段均无效，较早 pending 段仍有效；新 Seq 大于所有已分配 Seq；不全 cache 扫描即可识别 stale Current；SW 只覆盖有效已验证前缀，旧结果不改变新历史；两次回滚保留前一 Epoch 中应存活区间。
- 最小定向测试：T05/T08/T09/T11/T19（连续 Epoch 与位宽边界）；加 T14 变时钟测试历史提交和 SW 的 CDC。

## 阶段 4：可查询历史、LatestSurviving 和按需恢复

**目标**：在实际 Load miss/stale 路径从保存的版本恢复正确数据，包括 Figure 4(b) 的未验证 A7。

- 前置依赖：阶段 0 保留保证、阶段 3 历史有效性与映射 G；阶段 1 的停止/恢复屏障。架构接口和内存接口可并行开发，但最终重启须都完成。
- 可复用：SVB associative line/key/data RAM、L1 full-line capture/WB、L2 bank 端口、普通 refill/install、preservation ACK 责任。
- 预计新增：`generators/boom/src/main/scala/lsu/RecoveryCoordinator.scala` 或等效接口模块；L2 需要时新增 `generators/sifive-cache/design/craft/inclusivecache/src/VersionHistory.scala`。预计修改：`generators/boom/src/main/scala/lsu/speculative-version-buffer.scala`、`dcache.scala`、`mshrs.scala`、`phase1.scala`；`generators/sifive-cache/design/craft/inclusivecache/src/Directory.scala`、`Scheduler.scala`、`MSHR.scala`、`L2Preservation.scala`、`SourceD.scala`、`SinkC.scala`、`Parameters.scala`；TileLink 请求/响应字段扩展位置由协议决策确定。
- 关键接口/状态：`recoverQuery{address,core,EVT-context,G,txn}` / `candidate{key,data,valid,survives}` / `noCandidate`；按地址跨层选择最大有效 Seq，必要时同段内容 serial 决胜；baseline qualification；`promoteRecovered` 和新 Current 安装 ACK；NeededForRollback 对所有存活 CP 计算。
- 风险：仅 SVB 命中就提前返回而下层有更新的 surviving 候选；L2 直接多 tag 命中破坏现有 Mux1H；只保数据不保可定位性；回收时 CP 集合更新竞态；部分 Store mask 未继承完整旧 line；缺少恢复储备资源导致查询自身无法前进。
- 验收：A7 pending、A8 discarded、DRAM A1 时返回 A7；不存在合格 cache 版本才按正确条件返回 A1；多个 CP/跨段写链都能恢复；普通非恢复 Load 继续只看 Current；恢复后 Store 新建版本时正确继承数据及生产身份。
- 最小定向测试：T01–T04、T06/T07/T10/T12/T13。先做 L1+SVB，再接真实 L2 history 和 baseline 路径；只完成前者时必须标注配置/容量限制，不能称跨层恢复完成。

## 阶段 5：在途事务/ACK 与恢复提交闭环

**目标**：将已有 quiesce 接口落实为完整责任协议，最终允许正确 restart。

- 前置依赖：阶段 1 已建立停止钩子，阶段 2/3/4 的接口与状态齐备。这里不是首次考虑在途事务，而是完成所有路径并形成最终门控。
- 可复用：L1 key/source/entry 匹配、L2 txn echo、set lock、SourceD 末 bank commit ReleaseAck、MSHR grant/GrantAck 和 local completion。
- 预计修改：`generators/boom/src/main/scala/exu/RollbackController.scala`（前阶段新增）、`core.scala`、`generators/boom/src/main/scala/lsu/lsu.scala`、`dcache.scala`、`mshrs.scala`、`speculative-version-buffer.scala`；`generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala`、`MSHR.scala`、`L2Preservation.scala`、`SinkD.scala`、`SourceD.scala`；若 echo 身份调整，检查 `generators/rocket-chip/src/main/scala/tilelink/CacheCork.scala`、`ToAXI4.scala` 和 `amba/axi4/UserYanker.scala`。
- 关键接口/状态：每类责任的 outstanding/owned 状态、恢复 reservation incarnation、discarded-history mask、`archRestoreDone/historyCommitDone/txnReconciled`，仅其共同满足才 `restartPermit`。已发 safe WB 可完成；片上旧 unsafe 事务可完成协议但不能复活 Current；未接受请求可取消。
- 风险：等 unsafe WB 先变 safe 会因失败段永不 PASS 而死锁；一半多 beat 被丢弃违反 TL；旧 ACK 清新 owner；LineBuffer/RPQ 延迟效果覆盖新 G；取消 load 却漏掉已提交 Store/AMO；E 通道被恢复阻塞拖死。
- 验收：每个已接受 TL transaction 恰好终结一次，source/slot 不早复用；旧响应不修改新 Current/history；恢复完成时未完成事务要么完全 drain，要么已有可证明的隔离责任；开启执行后第一次内存访问与 SCP 一致。
- 最小定向测试：T10/T12/T13/T14/T20，穷举 final beat、ACK、history commit、restore install、restart 同拍/邻拍。该阶段通过后才称“最小单核 Rollback 闭环”。

## 阶段 6：跨层容量、I/O、多主核与 Forward Progress

**目标**：从受限单核闭环扩到论文完整部署范围，保留独立恢复与外部不可见性。

- 前置依赖：阶段 5 的单核闭环；跨层 history 查询和必要容量已经在阶段 4 接通。此阶段扩展压力覆盖与多核，不能把基本跨层正确性推迟到此阶段。
- 可复用：L2 unaware-source park/replay、Seq close command、bank 仲裁、内容/事务身份、safe 外写 gate。
- 预计修改：`generators/rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala`、`GHM.scala`、`generators/rocket-chip/src/main/scala/subsystem/HasTiles.scala`、`generators/boom/src/main/scala/common/tile.scala`、`generators/boom/src/main/scala/exu/core.scala`、`generators/boom/src/main/scala/lsu/mshrs.scala`、`dcache.scala`；`generators/sifive-cache/design/craft/inclusivecache/src/Parameters.scala`、`Scheduler.scala`、`MSHR.scala`、`InclusiveCache.scala`；配置和软件 timer flag 的 cache-line 放置由后续实施任务单独授权。
- 关键接口/状态：SW/EVT/G/CP 按 Main core 索引；writer→core 映射；同核内部访问与跨核外传分别判定；MMIO `close→prior-safe→issue`；pressure-close 的 producing core/Seq、pending coherence 优先权、escape credits 和公平仲裁。
- 风险：两个 image-aware BOOM 互相绕过 safety gate；全局 boring source 多生产者冲突；独立 Seq 数值相同误比较；一个核 Rollback 清另一个核版本；false sharing/中断 handler 等待错误核的 unsafe line；资源满时 CP/恢复流没有 credit。
- 验收：A 回滚不破坏 B；B 从未收到 A 的 discarded/unsafe 数据或权限；新 ownership 下的 Store 记为 B 历史；I/O 恰好一次且错误路径不对外生效；在规定公平/内存响应假设下，小容量压力也有界前进。
- 最小定向测试：T15/T18/T21/T22/T23/T24，双 Main 独立 Seq/Epoch、coherence/ownership、false sharing、资源极限与 I/O device side-effect scoreboard。

## 阶段 7：完整回归与证据交接

**目标**：把“存在控制线”提升为可复现的架构与内存正确性证明。

- 前置依赖：阶段 0–6 全部相关配置功能通过。
- 可复用：Stage2/Stage3 fixture、现有 provenance/trace checker、Opt4 正常 workload 基线。host checker 测试与真实 RTL 测试分别记录。
- 预计修改/新增（后续实施时）：独立的 rollback 单元/集成 fixture、故障注入接口、架构/内存 reference model、scoreboard 与 assertions；目录可沿用 `../AI/Debug/scripts/`，大型运行放 `../AI/TMP/<run-id>/`。不将面积评估模型或归档 candidate 当 production RTL。
- 关键状态：版本/配置/source/generated RTL/simulator/software/hash/seed 的清单，恢复目标与实际 commit trace、每地址 data/key/baseline、所有 CP 和 txn terminal 状态。
- 风险：把 simulator exit0、package PASS 数平衡或日志存在当恢复成功；恢复本身错误而后续 checksum 恰好相同；只验证单次回滚或只验证 safe 前驱。
- 验收：04 的用例逐项关闭，最小必测集全部通过；无未解释断言、丢事务、重复 I/O 或不匹配版本。报告分开记录 Scala compile、elaboration/FIRRTL/组合环、模块、整机、形式/属性检查；未覆盖条件保留 Unverified。
- 最小定向测试：固定 Figure 4(b) 反例作为 smoke test，随后随机 fault/ACK 延迟/替换/多核交错与 fault-free architectural+memory oracle 对照；正常功能和性能回归最后执行。

## 实施门槛与优先顺序

| 门槛 | 可称已完成什么 | 仍不能声称什么 |
|---|---|---|
| 0–1 | 正确保留历史、错误进入稳定停止态 | 能恢复和重启 |
| 2 | SCP 可定位且 BOOM 架构状态能导入 | 读到 checkpoint-consistent 内存 |
| 3–4 | 有效历史/Current 失效与恢复版本选择存在 | 任意在途交错下可重启 |
| 5 | 单核实际 Error→Restore→A7 Load→Restart 闭环 | 完整双主核、全部 I/O、任意资源压力 |
| 6–7 | 论文部署范围的功能与验证证据 | 没有执行过的参数组合或故障模式 |

建议最近一次实施任务聚焦阶段 0–1 的具体闭环，并把 CP/EVT/恢复查询接口契约一起定下来。每次修改只跨已明确的责任边界；保持当前正常保存/ACK 的断言与回归。完整 Rollback 的最早成功标准必须包含 A7 未验证时的恢复及新 Epoch 的继续执行，不能降低成“回到 DRAM baseline 后运行”。
