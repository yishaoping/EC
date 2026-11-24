# PALIMPSEST 单主核语义规范

当前实现以 [硬件不变量](SingleCore_RTL_Baseline/Hardware_Invariants.md)、[Seq32 协议](SingleCore_RTL_Baseline/Seq32_CDC_Rules.md) 和 [验证矩阵](SingleCore_RTL_Baseline/Verification_Matrix.md) 为准。下文的执行权限和验证结论属于早期轮次。

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


审查日期：2026-11-21。范围：一个 BOOM Main、现有四个 Rocket Checker、当前单 bank/64-byte 冷恢复配置。本文冻结论文明确的不变量；工程方案只有标为 `CONFIRMED` 才视为已确认。用户尚未确认的选择保留在 [12 决策记录](12_SingleCore_Design_Decision_Log.md)，不授权继续实现。

`PAPER` 表示论文明确要求；`RTL` 表示当前工作区源码事实；`DESIGN_DECISION` 表示实现选择或推荐；`CONFLICT` 表示与约束冲突的行为/解释。静态证据、条件证明和待证风险分别记录，不把 assertion 存在、CODE_READY 或词法检查当功能正确。逐路径证据及八场景见 [11 审查](11_SingleCore_Semantic_Gap_Review.md)。旧 00–04 属于实施前审计；05–09 属于随后源码实现，不能把相同 HEAD 当作相同工作区。

论文来源：[DAC_2027_EC.pdf](/data1/gzh/EC/AI/Ref/DAC_2027_EC.pdf)，SHA256 `17a81ade91736262b6d9f14f77336c852a1f692ae020fa498c8bddb82bd307e2`。以下页码为 PDF 页码：III/IV-A/Fig.3 在 p3；IV-B/C/D/Algorithm 1 在 p4；IV-E/F/G 在 p5。

## 1. 状态空间及不可混用的谓词

`PAPER`：论文分别描述有效执行历史、验证进度、Current/Historical 和保存确认。`DESIGN_DECISION`：以下谓词将这些概念及实现责任形式化，作为审查用语；名称、类型和具体接口不宣称是论文原文。

| 术语 | 定义 | 不可据此推出 |
|---|---|---|
| Allocated(s) | Seq s 已分配给一个检查段 | 已关闭、已检查、内存效果已完成 |
| HistoryValid(s,EVT) | s 属于尚未废弃的执行历史 | 已 PASS 或可对外传播 |
| Verified(s) | 对同一执行实例收到完整 PASS | 所有有效前驱均 PASS |
| Safe(v) | v 有效且生产段落在有效已验证前缀内 | v 不再是最新 baseline、物理位置可立即复用 |
| NeededForRollback(v,CP,EVT) | v 是至少一个 outstanding CP 所需的该地址最新有效前驱 | v 必须留在某一特定 cache/way |
| Current(a,G) | 正常执行对 a 的唯一逻辑映射在 G 下有效 | 内容必须产生于当前 Epoch 或已经验证 |
| PhysicallyPresent(v) | RAM/队列仍有 v 数据 | 其历史有效，或允许读/写回 |
| SecuredCopy(v) | 某可检索位置已接手精确版本的数据和保留责任 | 已写入 DRAM，或所有 CP 可退休 |
| Terminal(t) | 原事务 t 的完整成功/取消/失败结算事件 | 另一个同址或同 key 事务完成 |

`RTL`：`CacheImageKey.valid` 表示 authored 内容身份（false 为 BASE），SVB/L2 `valid` 表示物理占用；两者都不是 `HistoryValid`。`generation` 在 CacheImage 中是内容 serial，不是 Epoch 或 G。参见 `tilelink/CacheImage.scala:6–16`、`lsu/dcache.scala:767–794`（完整路径见 11 的证据字典）。

`DESIGN_DECISION`：为避免歧义，下文使用 `WatermarkCovered(v)` 表示裸 `Seq<=SW`；只将完整谓词称作 Safe。BASE/Seq0 的信任边界需 D08 决定，不能把失效内容改成 BASE 来通过门控。

## 2. Seq

**定义/依据 — PAPER（p3 III，p5 IV-E）**：Seq 为该 Main 的段执行实例序号，单调递增，回滚后从未使用过的更大序号继续。不是源程序的固定段编号，也不是 Checker slot 编号。单主核只有一个分配序列；多 Main 的独立命名空间不在本轮。

**转换 — PAPER**：allocate 新段 → 分配新 Seq 并保存对应 SCP；FAIL/rollback → 旧后缀失效，但 allocator 不倒退；重新执行同一 PC → 新 Seq。

**不变量 — PAPER**：任意两个已分配执行实例 Seq 不相同；迟到结果不能因重执行同一 PC 归入新段。内容生产 Seq 随迁移保持不变，PromoteCurrent 不重写它。

**RTL**：`R_IC.scala:135–137,239–244,269–289,505–512` 使用 32 位 counter，0 保留；restart 只清 active Seq，不清 counter。`PalimpsestRecovery.scala:128–132` 检查新分配大于 tail。

**未定工程选择 — DESIGN_DECISION D01/D04/D08**：32 位、0 为 trusted 的编码、运行寿命和终态恢复协议。不能用普通 drain 后将 Seq 归零替代论文“不复用”；若做系统级全新 incarnation，必须显式改变恢复域与所有旧引用的身份。

## 3. Verification Result 与 LSL

**定义/依据 — PAPER（p3 III/Fig.3，p4 IV-C/D）**：Checker 对段的完整执行给出 PASS/FAIL。验证 bitmap 记录段结果；乱序 PASS 不等于 Safe。LSL 是检查输入，不是恢复 undo history。

**转换 — PAPER**：Pending → Verified 或 FAIL；回滚废弃段的 PASS 不再构成有效历史证明。一个段完成验证后，其 checking inputs 可独立回收，不能顺便删除 SCP/历史版本。

**不变量 — PAPER**：FAIL 不能当 PASS；结果必须对应原执行实例；回滚不能删除较早仍有效段的未决结果。已 PASS 但未被 SW 覆盖的段可以释放 LSL 输入；其内存版本仍可能需要保留。

**RTL**：`RocketCore.scala:1516–1550` 另有 CANCELLED（timeout/transport/history cancellation）；`GHM.scala:553–577` 经独立结果 AsyncQueue 在 BOOM 域产生事件并释放原 slot；`dcache.scala:2800–2846` 以完整 Seq/tag 接收、排除旧结果，置 completed/passed。`R_LSL.scala:215,257` 的消费/空闲与 SW 无连接。Checkpoint RAM 和 history 独立于 Checker slot。

**未定工程选择 — DESIGN_DECISION D02**：CANCELLED 是实现扩展；当前有效段 CANCELLED 和 FAIL 共用 rollback 入口，事件只有 `seq,cancelled`。应保留诊断类别及可重试/不可恢复策略，不把重复 timeout→rollback 称为活性。PASS 不可逆是当前接收协议假设；若允许之后撤销 PASS，现有 SW/CP 退休规则均须重设计。

## 4. SW

**定义/依据 — PAPER（p3 III，p4 IV-C）**：SW 表示有效执行历史中最大的连续已验证前缀；所有先前有效段必须 PASS，废弃区间不构成验证空洞。

**编码 — DESIGN_DECISION D01（PROPOSED）**：采用数值 frontier：从初值 0，令 `q=SW+1`，仅当 q 已分配且 EVT-dead，或 q 是已分配且 PASS 的有效段时推进。可每拍 +1。因此 frontier 可以停在 dead 区间内部/末尾；`SW=10` 可表示有效前缀仅到 7、8–10 废弃。SW 数值不是“此 Seq 的段一定 PASS”。论文不规定跳洞后标量必须取 dead 区间末端还是下一个有效边界；两种编码应以同一个有效历史前缀解释。

**规则 — PAPER**：乱序 PASS8、Pending7、SW6 → SW 保持6；FAIL8 不产生任何安全授权；若随后 EVT 丢弃8–10，7 未 PASS 前 SW仍6，7 PASS后可跨8–10。有效的新11 未 PASS前不能覆盖11。Epoch 改变不清除仍有效旧段的 PASS/Pending，也不把新 Epoch 起点前的有效 Pending 默认为 Safe。

**不变量 — PAPER**：`HistoryValid(s) && s<=SW => Verified(s)`（保留可信 BASE 的独立例外）；有效 FAIL 的目标必在 SW 之后；safe 版本不能被合法回滚废弃。SW 不负责决定 Current 或 NeededForRollback，不将 Valid/Verified/Safe 合并。`DESIGN_DECISION D01`：当前 frontier 在同一恢复域内数值不减，rollback 不倒退它；这是所选数值编码的性质，论文未单独规定所有 SW 编码的数值形式。

**RTL**：`dcache.scala:930,2781–2797,2814–2846,2890–2943` 保存 256 项完整 Seq bitmap，计算连续 PASS，再将结果节流为单步 +1；EVT dead 下一项可越过，`historySync` 期间冻结；covered/dead bitmap 被清。普通 exception、统计 RESET、rollback 均不重置 SW。`core.scala:2098` 用 SW 保守退休 CP。

**未定工程选择 — DESIGN_DECISION D01/D09**：bitmap 分配信用、同拍 allocation/result/EVT 的优先级证明、SW/EVT CDC 和复位域。单步 Gray 的逻辑转换不能代替寄存后的源端 Gray、物理 skew/同步器及 reset 约束。当前完整一致性未获证明。

## 5. Epoch / EVT

**定义/依据 — PAPER（p3 IV-A，p5 IV-E）**：Epoch 说明执行阶段；EVT 说明各 Epoch 的有效 Seq 区间。一次回滚保留更早有效区间，丢弃错误段起的有效后缀，创建新 Epoch；旧 Epoch 的有效历史仍可被选中。

**转换 — PAPER**：FAIL n → pin SCP n → EVT 失效当前有效历史中 Seq≥n 的部分；随后以新 Epoch、fresh Seq 执行。第二次较早 FAIL m<n 必须连同第一次恢复后生成的新后缀一起作废。

**不变量 — PAPER**：EVT 只回答历史是否有效；bitmap 只回答验证结果；不能互相替代。恢复候选不要求 Epoch 等于当前 Epoch。所有持有旧版本/响应的消费者必须使用兼容的历史上下文。

**RTL**：`PalimpsestExecutionHistory`（`PalimpsestRecovery.scala:88–144`）以最多32个 discarded闭区间表示有效历史的补集；tail 不退，重叠 suffix 合并，Epoch/G 同拍递增。Seq 不复用时，可由 Seq 区间隐式表达 Epoch，无需给每个内容 key 再加一个字段。这是语义等价的可行编码，不因缺少 key.Epoch 就判错。

**限制 — RTL**：模块 `survives` 在 :125 检查 `s<=tail`，但 DCache 本地 helper（:655）及 `PalimpsestHistoryQuery.survives`（:43）只排 tombstone；DCache 连接的 query 输出未用于结果判断。依赖“所有 authored Seq 已分配”的来源不变量。32个 disjoint tombstone 不回收；第33个可进入 failed。

**未定工程选择 — DESIGN_DECISION D03/D04/D09**：补集压缩可以保留；必须决定完整性契约、tail 检查方式、tombstone 回收/容量及发布确认。普通 drain 只能消灭在途事务，不能证明旧 cache key、CP、FIFO 或 history 中再无旧 Seq；不可据此随意删 tombstone。

## 6. Checkpoint

**定义/依据 — PAPER（p3 III/Fig.3，p5 IV-E）**：SCP n 是段 n 开始前的架构状态。内存对应所有有效前驱段的最终内存效果；并不要求这些效果在捕获时已写入 DRAM，甚至不要求 committed Store 已完成 L1 效果。后者必须在恢复/排空时与 SCP 一致地结算。

**Outstanding — PAPER 的语义要求**：某段起点仍可能被选择为合法回滚目标，则其 SCP 及必要内存前驱必须可用。`DESIGN_DECISION D05` 推荐保守集合：已分配且有效、未被 SW 覆盖的全部 SCP，加当前恢复 pin。乱序 PASS 的 SCP 可以保守保留；论文不强制每个 PASS 都立即退 CP。

**转换 — PAPER**：段起点完整捕获 → 可按 Seq 定位 → error 时 pin/read → 架构恢复与事务协调 → restart后释放 pin。安全前缀覆盖后可退休；废弃 suffix 不再作为未来目标，但恢复中的目标 SCP 必须保留到恢复完成。更早错误到达可放弃当前 pin 并重选更早 SCP，不能删除所有旧 Epoch CP。

**不变量 — PAPER**：存活 CP 不可被 Checker slot 复用覆盖；退 CP 只是减少 Needed 集合，不直接证明任何地址最新 baseline 可以删除。SCP n 与 ECP n 必须区分；同一边界可以同时是 ECP n−1 与 SCP n，但执行实例身份不同。

**RTL**：`core.scala:2125–2137,2331–2346` 在 registered packet_alloc 时捕获 committed shadow/next PC/CSR，要求 ROB empty/quiet、16项 RAM有空间；`R_IC.scala:239–289,307–312` 的 allocation 与 RSU capture相邻拍。`PalimpsestContextMemory:47–79` 以完整 Seq查询、read优先于回收、pin持续到response.fire/abort；:73 按 SW 或 discard退休，`core.scala:2099–2102` 在 restart发布discard并释放pin。

**未定工程选择 — DESIGN_DECISION D05/D10**：需确认实际 RSU/CP/committed memory 的共同边界、保守退休集合、16项的分配预留以及所有CSR/异步事件策略。当前未看到“按SW退休CP”本身与论文冲突；缺的是该生命周期与全地址版本保留共同成立的证明。

## 7. Current / Historical Version

**定义/依据 — PAPER（p3 IV-A，p4 IV-B/Algorithm 1）**：Current 是正常访问的逻辑目标；Historical 是为恢复保存的旧值。普通Load只访问有效Current；G不匹配时走按需恢复，不能将 stale mapping 当普通 miss任取DRAM。

**转换 — PAPER**：同一 `(Seq,Epoch)` 内Store修改Current；下一段首次Store继承完整前驱行、应用byte mask，并在前驱Needed时保留历史。回滚提高G，使原Current映射stale；选择存活内容并绑定新G。历史位置可迁移，内容身份不随验证、迁移或提升改变。

**不变量 — PAPER**：每地址正常逻辑Current唯一；Historical不直接参与普通tag/coherence命中。整行旧值必须在覆盖之前已被可靠保存；不得只保存被修改字节而丢失其他字节。

**RTL**：L1 `currentGeneration`、residentTag/imageKey分开；`dcache.scala:830–858` 验证G和历史，存活resident可重绑G，否则查询SVB/L2。SVB+L2 sidecar替代论文常规ways保存组织，是工程布局差异。`dcache.scala:2045–2075,2140–2175,3385–3397` 保存普通跨段unsafe前驱；其他命令走保守保存/WaitSafe。

**未定工程选择 — DESIGN_DECISION D06/D07/D08**：sidecar可保留，须补完候选域闭包与基线次序。存活resident快速重绑G成立的前提是它确为本Main该地址最新副本、没有更晚有效历史被遗漏；这需coherence/迁移不变量。Seq0/trusted外部写的顺序和恢复floor未定。

## 8. NeededForRollback 与 CanReclaim

**定义/依据 — PAPER（p4 IV-D）**：版本在至少一个 outstanding rollback checkpoint 处代表该地址最新有效值时，就仍然 needed。`DESIGN_DECISION D05/D06`：将此规则形式化为下面的 `Pred(a,c,EVT)`；对段首SCP，普通段版本比较 `v.Seq<c.Seq`，工程内容serial用于区分同段多次快照并选最终行。论文没有规定serial编码。

```text
NeededForRollback(v,CP,EVT) = HistoryValid(v)
  AND EXISTS c IN OutstandingCP: v = Pred(v.address,c,EVT)
```

这里比较的是语义版本；多个精确副本是同一个v，不要求每个副本都永久保留。BASE/trusted写由恢复floor契约补充，不能简单以数字0排在所有普通版本之前。

**转换/不变量 — PAPER**：新增CP、新版本、EVT裁剪、CP退休都会改变Needed；任一Needed值始终至少有一个可检索副本，或DRAM确为对应所需值。版本safe不等于可删，unsafe也不等于必需（例如同段中间值、dead suffix、无CP引用且不再Current的版本）。

**DESIGN_DECISION D06**：实现可使用精确CP依赖判定，也可保守保留Needed的超集；论文不要求RTL里必须有名为NeededForRollback的函数。保守方案必须同时证明容量前进，不得靠永久不回收掩盖问题。

```text
CanDropLocalCopy(v) = 无该副本未结算的事务/锁/响应责任
  AND (HistoryDead(v) OR 精确可检索副本已接手 OR 语义值确实不再需要)
CanDropSemanticValue(v) = 非当前需要 AND 非NeededForRollback
  AND 不破坏该地址最新有效safe baseline
```

**RTL**：SVB SPEC只在错误suffix失效、WB_WAIT只在exact archive receipt释放（`SVB:281–365`）；safe-coalescing当前关闭。L2 history dead项可删，safe项到精确DRAM ACK才free（`PalimpsestHistory:95–144`）。L1 `lowerPreserved` 和L2 `outerPreserved` 是保存责任凭证，不是Verified/HistoryValid。当前没有显式CP引用集合，属于保守保存策略；是否覆盖全部Needed仍待全层证明。

## 9. Safe Writeback / 外部可见性

**定义/依据 — PAPER（p4 IV-C/D，p5 IV-F）**：外层传播的最低资格为 `HistoryValid(v) && Seq(v)<=SW`。single-Main内部unsafe迁移允许；面向非恢复域observer的数据/权限必须等待安全。原生Rocket/DMA的隔离仍属单Main系统责任。

**转换/不变量 — PAPER**：先选可安全传播且不obsolete的版本 → 对同址所有外写序列化 → 保持数据/身份 → 完整WB ACK后转交/释放责任。仅Safe不足以授权任意旧值写回；不得覆盖更新baseline。

**协议约束 — DESIGN_DECISION D11**：当前使用TileLink，已接受多拍事务须保持原协议责任，不能在中途任意撤valid或变payload。论文要求在途协调，但没有规定TileLink的beat级实现。

**DESIGN_DECISION D07**：完整 `CanWriteback` 还需要“不会使baseline倒退”、同址互斥/有序、精确owner和事务状态；安全资格与调度资格分开。若旧值已obsolete，抑制其数据写回但正确结束已有coherence责任。

**RTL**：L2 `historySafe`补EVT；SourceC调度gate并将dead release去数据化（`Scheduler:124–125,386–395,490–495`）；history publisher过滤EVT与SW；L2Preservation捕获dead/unsafe为archive模式，发Put时有完整Safe断言。`SourceC:175–182`实际beat断言不是独立硬件gate，需由入队时Safe及“safe永不被合法回滚废弃”保证。

**CONFLICT**：将裸 `CacheImage.safe`/`L1Preservation.safe` 当完整VersionSafe，或把local升序publisher当所有入口的obsolete suppression证明，均不符合论文。当前关键外写路径已有附加过滤，不能据裸helper反推已观测到dead数据外写。

## 10. LatestSurviving

**定义/依据 — PAPER（p4 Algorithm 1/IV-B，p5 IV-E/Fig.4b）**：从地址a的完整可恢复候选域中选最新有效版本。**不要求Verified，不要求Seq<=SW，不要求来自新Epoch。** FAIL8/SW6应选Pending A7。

**转换 — PAPER**：stale Current → 查询全部相关层及迁移责任 → EVT过滤 → 比较执行顺序 → 选择/稳定数据 → PromoteCurrent。只收到上层miss不能证明无缓存候选。

**不变量 — PAPER**：候选集合不能遗漏唯一在途保存副本；同址Seq排序，工程上的同段多快照还须选最终内容。查询期间候选移动或删除不能产生空窗。

**RTL**：`SVB:124–147`、`PalimpsestHistory:102–123` 都按最大 `(Seq,content serial)` 选取并保持response；不使用SW。`dcache.scala:860–884` 等全部L2 ACK后合并SVB与L2结果。L2 query仅枚举sidecar；resident、staging、在途archive/publisher必须由副本/屏障不变量覆盖，不能宣称该RAM就是全部缓存域。

**未定工程选择 — DESIGN_DECISION D06/D07/D09**：候选域闭包、same-key数据相等证明、held snapshot和新EVT之间的协调、可信Seq0排序。不能用“只找safe版本”修复候选/容量问题。

## 11. SafeBaseline

**定义/依据 — PAPER（p4 IV-D，p5 IV-E）**：DRAM在确实代表所需值时才能回退。SafeBaseline不是初始化A1，也不是任意已PASS值。每个地址的最新有效safe值必须在层次/DRAM保持可用；所有仍必需unsafe值必须可检索。

**转换/不变量 — PAPER**：证明不存在更合格缓存版本且没有未协调的相关迁移 → coherent FetchCurrent/DRAM回退。Preserve/WB途中若仍有唯一合格候选，必须等待/访问owner；不能因RAM瞬时无项而用DRAM。

**RTL**：`dcache.scala:885–897,1880–1898` 查询收齐后，没有found则使用普通coherent Acquire；这也可能从L2 resident返回，并非必定读DRAM。found时用恢复line替换普通grant数据（`mshrs.scala:177–187,474,576`）。没有独立持久per-address已发布版本水位；`PalimpsestHistory:128–144`仅对当时RAM候选升序，free后不记录该地址已发布最大key。

**未定工程选择 — DESIGN_DECISION D07（优先）**：统一所有同址外写owner/发布高水位，或给出现有协议全入口顺序证明。未闭合前不能确认Fallback正确，也不能把“整行coherent refill成功”当恢复正确。

## 12. Generation / CurGen

**定义/依据 — PAPER（p3 IV-A，p5 IV-E，Algorithm 1:4–9）**：G是映射世代；CurGen==G验证Current映射；执行Epoch表达历史阶段。`RTL / DESIGN_DECISION D04`：当前另用内容serial标识immutable bytes、slotEpoch标识物理槽incarnation；论文未规定这两个编码。四者语义不同，即便Epoch与G目前一起递增也不能互换。

**转换/不变量 — PAPER**：rollback推进G，历史数据不清空、不全cache扫描；PromoteCurrent仅重建映射；后续新Store分配新内容身份。任何old响应不得借“绑定当前G”复活dead内容。

**RTL**：G/CurGen均32位；`dcache.scala:830–846,1821,3625,3658`读取/写入映射，ingress再查survives。部分refill路径先绑定当时G，需依靠drain及后续历史检查保证旧响应不产生可读错误数据。

**未定工程选择 — DESIGN_DECISION D04/D11**：G复用需要证明所有旧mapping无法误命中；ordinary transaction drain不能清掉cache中所有旧CurGen。位宽/再初始化不可只参考ACK已空。

## 13. Transaction Identity

**定义/依据 — PAPER（p4 IV-D，p5 IV-E）**：version identity指明内容；transaction identity指明一次责任交接；reservation identity指明某物理目的槽的占用实例。每次异步ACK只更新原owner。

**不变量 — PAPER**：异步ACK只更新对应版本和reservation，恢复时协调在途事务。论文没有规定批量分配器、owner状态机或具体ID复用协议。

**转换/规则 — DESIGN_DECISION D04/D11**：当前实现分配前为完整同时分配组预留身份预算；接受请求后owner/payload保持至原terminal，取消也须结算。释放owner不自动证明数字ID可安全重用。合法迟到ACK不得清新owner或创建保存许可；对协议外重复ACK的容错范围仍待D11选择。

**RTL**：LSU functional/strict token各64位（functional限低63位）；L1slotEpoch16、MSHR事务32、内容serial32；L2preserve/release事务64。具体七类身份及耗尽可达性见11。L1voluntary WB ACK以source/opcode/size/key/pending_sent匹配，未携独立per-WB serial；同一immutable key重复传输时，抗任意重复ACK仍依赖TL终态约束，不能用key唯一性代替事务唯一性。

**未定工程选择 — DESIGN_DECISION D04/D11**：正常TL恰好一个响应的故障模型、任意重复ACK是否纳入、全局/局部drain后复用协议。可以保留当前不回绕保护；不能未经证据删除，也不能把permanent failed算forward progress。

## 14. Rollback / Restart

**定义/依据 — PAPER（p3 Fig.3，p5 IV-E）**：恢复目标为FAIL n的SCP n；协调架构状态、EVT/G和在途责任后重新执行。论文不固定所有FSM微步骤顺序。

**RTL**：`PalimpsestRollbackController:173–211` 实际顺序是 lookup/pin → history commit → drain → restore → resume；`core.scala:2094–2143`在restore第一拍reset backend、随后导入状态，再允许restart。先发布EVT可解除失败后缀的WaitSafe，方向可保留。恢复中更早有效错误重选CP；同/较晚错误不重复开新epoch。

**不变量 — PAPER**：restart仅在架构恢复完整、历史已发布、旧事务不能污染新状态且SCP仍可用时；所有acceptedTL责任都终结或已被可证明隔离。FAIL m早于当前target时，新一轮恢复覆盖新旧Epoch全部后缀；CP m及其前驱不能在第一次恢复中丢失。

**未定工程选择 — DESIGN_DECISION D10/D11**：当前restored由固定拍数表示专用并行导入，需证明每个实际PRF/CSR/rename写都在该拍完成；不能单看延时位认定架构恢复成功。memory quiesce未显式等全部L2后台publisher（允许保留安全独立owner也可），必须列出逐类允许跨restart的事务及其隔离证明。

## 15. MMIO Barrier

**定义/依据 — PAPER（p4 IV-C）**：不可缓存/不可重复I/O触发提前关段，等待preceding execution验证后才执行。论文没有定义具体pre-I/O拆段、输入重放、exactly-once日志或recovery floor协议。

**不变量 — PAPER**：错误推测不能产生不可撤回副作用；合法恢复不能重复外部动作；验证屏障必须有前进路径。普通ROB非推测发射、Seq0/BASE标签均不构成检查许可。

**RTL/CONFLICT**：`mshrs.scala:1119–1164`对非零ioSeq要求当前段自身 `ioSeq<=SW`，同时未完成I/O可能阻止ROB empty/ECP；`core.scala:2331–2345`的snapshot门要求ROB empty。当前有拒绝过早外发的gate，却没有通用pre-I/O边界和重放/floor协议。这与完整MMIO前进目标冲突；不能简单改成 `SW>=ioSeq-1` 后宣称解决所有副作用。

**未定工程选择 — DESIGN_DECISION D12（CONFLICT；解决方案待用户确认）**：推荐先定义pre-I/O已验证前缀和不可跨越的恢复边界，再决定读结果日志/写效果去重；另一选项是可回滚的exactly-once effect日志。必须列出中断、Fence、AMO/LRSC、device read-to-clear的区别。不得自行选择永久屏蔽全部I/O。

## 16. Forward Progress

**定义/依据 — PAPER（p5 IV-G）**：当当前段的未验证数据阻塞preserve/WB/coherence时，提前关闭并分发该段；pending coherence优先于后续冲突写，防止无限延期。

**DESIGN_DECISION D13**：在下层最终响应、Checker能前进且仲裁公平的明确环境假设下，设计须给close/ECP/drain/recovery所需资源留足信用。论文未规定具体槽数/延迟上界。

**RTL**：`dcache.scala:940–942`在SVB≥14/16或MMIO blocked请求close；L2在history64满时请求验证最老Seq；但`core.scala:2350`的instruction drain reserve不是history/LSQ/MSHR的存储信用。boundedCP/history/EVT以及身份耗尽都可能阻断正常运行。

**CONFLICT**：permanent failed保守避免身份alias，但不是正常forward progress；无限延长运行、任意容量压力、任意多次回滚均未实现。当前保护可以保留，任务完成标准必须将“有限寿命安全停机”和“规定运行范围内持续执行”分开。

**未定工程选择 — DESIGN_DECISION D04/D13**：决定可支持运行寿命、最大outstandingCP/history需求、提前close阈值与最坏headroom、公平仲裁和耗尽恢复协议。硬reset退出failed会清片上unsafe/CP，不能默认等价于成功rollback或安全resume。

## 17. 本轮冻结边界

`PAPER`约束已明确：fresh Seq、有效历史连续验证SW、Valid与covered共同授权外传、CP所需值不丢、Pending A7可恢复、latest-safe baseline不倒退、exact owner ACK、协调后restart、MMIO验证屏障与压力close/优先权。

`DESIGN_DECISION`尚未冻结：数值SW编码/CDC、CP保守生命周期、history存储与回收证明、全地址baseline次序、身份寿命/安全再初始化、MMIO重放/floor、容量预留、完整架构状态和异步事件边界。见12的逐条状态；不得由已写RTL反推用户已批准这些选择。本轮到语义审查为止，不执行RTL修改、编译、仿真、FI或commit。
