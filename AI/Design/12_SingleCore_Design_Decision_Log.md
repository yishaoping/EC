# PALIMPSEST 单主核设计决策记录

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


以下正文是先前架构审查记录；当前冻结与实施状态由上方增量和状态列覆盖。论文明确的要求在下表作为约束固定；后续方案状态不因已有RTL存在而变成CONFIRMED。原05任务及所有完成证据保持不变。

关联：[10 权威语义](10_SingleCore_Semantic_Spec.md)、[11 代码差异/场景/任务复核](11_SingleCore_Semantic_Gap_Review.md)。本文 `REC/DC/CORE/IC/KEY/LP/SVB/HIST/INC/SCH/L2P/L2M/SC/LM/LSU/CHK` 文件简写精确展开见11第1节。

## 1. 状态与约束的含义

| 状态 | 本轮含义 |
|---|---|
| CONFIRMED | 论文原文约束已确认，或会话中明确授权的本轮范围；不表示RTL验证通过 |
| PROPOSED | 有明确推荐，尚未批准冻结为工程契约 |
| NEEDS_USER_DECISION | 会影响布局、运行边界、恢复能力或外部效果；需用户审阅选择，本轮保留pending |
| CONFLICT | 当前行为/解释与约束冲突；约束不可选，解决方案仍待审，不能以维持代码为由豁免 |

### 1.1 已确认的 PAPER 约束（不是可随意选择的方案）

| Constraint ID | PAPER约束 / 来源 | 状态 | 实现自由度 |
|---|---|---|---|
| C01 | p3 III/p5 IV-E：Seq单调，rollback后永不复用；新执行Epoch | CONFIRMED | 位宽、编码和有限寿命处理可选择；不能静默归零复用同一身份 |
| C02 | p3 III/p4 IV-C：SW为有效历史连续已验证前缀，跳过失效区间；有效且Seq<=SW才有外传资格 | CONFIRMED | frontier数值表示、推进节拍、CDC协议可选；不能只看裸数值 |
| C03 | p4 IV-D：Needed指至少一个outstandingCP的最新有效地址值；preserve-before-reuse | CONFIRMED | 精确CP索引或可证明的保守超集可选 |
| C04 | p4 IV-D：保留latest valid safe baseline，抑制obsolete writeback，同址在途传输序列化，ACK只改原owner | CONFIRMED | 不变量证明或显式baseline/owner目录可选；exactACK不替代次序 |
| C05 | p5 IV-E/Fig4b：恢复SCP n，裁剪有效suffix，保留跨Epoch前缀，允许Pending A7成为LatestSurviving | CONFIRMED | 不能将Seq<=SW/Verified加进恢复候选资格来省历史 |
| C06 | p3 IV-A/Algorithm1/p5 IV-E：G逻辑失效Current，按需恢复；无合格cache值且DRAM代表所需值才fallback | CONFIRMED | sidecar/ways/混合存储可选，需完整可检索性，不用整cache清空代替 |
| C07 | p3 III/p4 IV-D：检查输入释放与恢复历史保留解耦 | CONFIRMED | LSL FIFO消费、结果交付、slot release可分别实现，不得据LSLfree删Needed值 |
| C08 | p5 IV-E：恢复架构状态并协调在途事务后才resume | CONFIRMED | 全drain或保留被隔离owner可选；已接受TL责任不能丢 |
| C09 | p4 IV-C：MMIO/nonrepeatable I/O提前close、验证preceding execution后执行 | CONFIRMED | pre-I/O split、日志、floor等细节需决定；普通non-speculative/BASE不等于验证许可 |
| C10 | p5 IV-G：当前段unsafe导致阻塞时earlyclose/dispatch；pendingcoherence优先于后续冲突写 | CONFIRMED | credit数、公平调度、环境假设、进展界限由工程定义；永久failed不是正常进展 |
| C11 | 用户本轮范围：1 BOOM Main+现有RocketChecker，仅审查和新增Design文档，完成后停止 | CONFIRMED | 不实施多Main专用机制；nativeRocket/DMA等外部observer隔离仍在单Main系统内 |

## 2. 工程决策总表

以下选项列保留历史比较；最终状态列已依据用户 U-D01–U-D10 更新。方案已经冻结，剩余差异是实现缺口。优先级首先是SW、CP/Version lifecycle、identity、MMIO；baseline/容量与它们有直接依赖，不能等恢复开放后再补。

| Decision ID | 问题 / 当前RTL | PAPER约束 | 可选方案 | 推荐及理由 | 风险 / 原Task | 状态 |
|---|---|---|---|---|---|---|
| D01 | SW编码、步进及bitmap窗口；DC:2890–2943当前数值frontier每拍+1，含dead区间 | C02；不强制每个SW数值自身都Valid/PASS | A：保留数值frontier；B：显式有效历史位置/压缩区间游标，对外编码再握手 | A；现有代码可解释且单步便于Gray，但将裸covered与Safe分名，定义allocated/同拍result/EVT优先级及256窗口信用 | 误把dead frontier当已验证段；epoch后重置SW丢Pending前驱。P0-06/P1-02/P3-02；11/F01 | FROZEN U-D02：单步数值 SW，寄存 Gray，窗口信用保留 |
| D02 | 结果不可撤销、CANCELLED类别、timeout与fault model；REC事件仅seq/cancelled | C02/C05/C07，不能取消或重发覆盖原PASS后还沿用旧SW | A：完整PASS不可撤销，有效取消可恢复，保留原因；B：只对指定取消恢复，其余显式诊断停机/上报 | A作为起点，细分history取消、传输错误、无进展等原因；后续若要求撤销PASS，需重新设计CP退休/安全传播，不属于小修 | 相同timeout无限重试不进展；诊断消失；未定义已PASS后再FAIL。P2-01/P2-09/P2-11/P4-13 | FROZEN：完整 PASS 不可撤销，合法取消触发恢复 |
| D03 | EVT补集编码、tail完整性、回收；REC有tail上界，DC/HIST helper无上界 | C01/C02/C05，旧有效Epoch仍可选，dead不得复活 | A：保留dead intervals并对所有来源证明已分配；B：接口带tail/explicit Epoch有效interval；均需安全压缩/回收 | 保留当前补集结构，统一“排tombstone”与“属于已分配有效历史”的契约，逐入口证明或检查；定义容量回收需要的最老可引用Seq | 32项可达耗尽；删tombstone后旧cache/queue内容复活；同拍分配结果要纳入AllocatedNow不能机械加tail门。P3-01/P3-02/P3-05/P3-13/P3-14 | FROZEN U-D04/05；EVT32 退休仍是实现缺口 |
| D04 | 身份耗尽、运行寿命和永久failed；DC任一slot16/serial32满即stop；REC无退出 | C01/C04/C08/C10，不alias且支持规定工作范围内前进 | A：保留guard，扩大/分层身份并实现安全局部drain+incarnation；B：明确有限服务寿命，受控系统级重建；C：单纯扩大位宽只作短期过渡 | A优先，先量化热点预算与最低运行寿命；对Seq/内容serial等持久引用不能仅普通drain复用。B仅在用户接受服务中断及恢复边界时成立。guard先保留 | 16bit槽正常执行短时间可耗尽；32bit内容serial每Store增。现保护只是fail-stop，不能标成活性解决；硬reset可能丢CP/unsafe。P3-15/P4-06/P4-12/P4-13；11/F04 | FROZEN U-D07：普通身份已循环，EVT/Seq 寿命尚未解决 |
| D05 | Checkpoint生命周期/捕获边界/16项信用；REC按SW/discard回收，CORE registered allocation捕获 | C03/C05/C08；目标为段首SCP，pin到恢复完成，安全覆盖后可退 | A：保守留所有有效且Seq>SW的SCP及pin；B：依赖图证明后乱序PASS立即退休部分CP；集中/分布式存储可选 | A+现集中RAM；规则简单且支持更早FAIL7，保留目前pin/read优先。明确SCP注册拍与RSU/committed shadow/未完成Store语义join和分配预留 | 过保留会满，但不是语义错误；earlyfree会使更早FAIL无CP；CPfree不能直接删baseline。P2-03/P2-04/P1-09/P3-14；11/F02 | FROZEN U-D03/04：恢复 SCP，pin 到 restart |
| D06 | Needed集合、history布局、候选域和reclaim；当前SVB16+L2sidecar64，无精确CP引用 | C03/C06/C07；保留Needed且全域可检索，Pending可恢复 | A：保留保守superset+精确副本责任+可证明safe回收；B：增加精确CP predecessor索引/refcount；存储可ways/sidecar/混合 | 先A保留当前存储，给出CP/address oracle与迁移owner闭包，再评估B容量收益。没有必要为了函数同名而强加大CP表 | 仅看safe/unsafe不等于Needed；全保留引发容量环；L2RAM查询可能遗漏resident/在读候选；Promote不解除保留责任。P1-03/P1-07/P1-09/P3-06..09/P3-13；11/F02/F07 | FROZEN U-D05：局部被动回收，不扫描全 Cache |
| D07 | 全地址baseline发布、obsolete抑制、SafeBaseline资格；HIST ACK后不记该地址最大发布key | C04/C06；旧safe不得覆盖新safe，DRAM确为所需值才用 | A：统一所有同址owner/版本高水位及更新receipt；B：证明现coherence+迁移全入口严格排序，并增加足够的边界检查/必要最小元数据 | A的语义契约优先，具体目录/分布式证书规模待评估；若B能排除11第4节反例模板，可少加硬件。单RAM升序不足 | late旧capture、新旧publisher/SourceC、旧残影遮蔽正确refill；exactACK成功仍可错误baseline。P3-10/P1-08/P3-09/P4-04/P4-08；11/F03 | FROZEN U-D06：同址最新 safe，receipt/obsolete 已实现，组合入口待齐 |
| D08 | BASE/Seq0/trusted访问者的可信边界及顺序；KEY.safe和LP.allow有特例 | C02/C03/C04/C09；失效内容不得靠改BASE洗白，不可丢必要前驱 | A：受保护执行期间所有semantic write都有合法Seq，trusted仅明确域外；B：trusted事件建立可证明恢复floor/顺序incarnation | A的受保护区间定义优先；平台管理/中断/外部native写需按B或隔离契约处理。列清哪些访问不是Main普通段 | Seq0数值排序早于所有普通Seq，实际trusted写可能更晚；老checkpoint跨外部写恢复语义不明确；KEY.valid不是EVT.Valid。P0-06/P1-05/P4-09/P4-10 | FROZEN：Seq0 为可信初始化/域外，保护写带 Seq |
| D09 | SW/EVT/query/archive跨域原子性及reset；组合Gray、payload sync3/request sync8，Checker无专用EVT ACK | C02/C04/C08；消费者不能收到新covered旧EVT，held事务不能跨reset误认 | A：寄存Gray+物理CDC约束+四相stable bundle/reset协议；B：统一带incarnation版本的CDC mailbox/AsyncQueue发送SW与history | 保留有用四相责任边界，对A给出源端稳定/寄存、skew、reset和所有接收者确认契约；若跨域关系难保证则选B | 单步逻辑Gray不保证组合毛刺无害；reset不同步复用ACK；Checker依赖原result release排空，不可从一拍empty推出同步完成。P1-02/P3-02/P4-05；11/F01 | FROZEN U-D02/03：注册 Gray+四相稳定 bundle；物理 CDC 待用户验证 |
| D10 | 架构状态集合、内存边界、异步事件与restore完成；CSR8192bit、cycle/time不回滚、done固定拍 | C05/C08；SCP一致且恢复完再resume；论文不逐个规定CSR | A：规定受支持特权/CSR/异步事件集合，专用并行restore证明固定拍完成；B：带逐单元ACK的restore事务 | 显式架构状态清单优先；固定拍路径可保留但需写端实际效果证明，后续可按B接done。定义interrupt pending/time/HPM/customCSR、TLB/PTW/fetch及LRSC恢复策略 | 只恢复shadow或PC不能代替PRF/rename；可选配置wideCSR、可重复中断、外部时间输入可能使重执行不同。P2-05..08/P2-10/P4-10；11/F08 | FROZEN U-D03：顺序 PRF/rename/CSR owner done，异步边界测试待齐 |
| D11 | 恢复中在途owner、同key重传、任意重复ACK是否纳故障模型；L1WB无独立每笔echo | C04/C08，acceptedTL责任不丢，旧owner不污染恢复 | A：协议合法TL恰好一次，旧包在原source未复用前终结，逐类drain/隔离；B：额外容忍重复/跨incarnation响应，L1WB等加入独立事务身份/隔离机制 | 先明确A/B；A不是放弃合法迟到响应保护。若继续要求wrong/duplicateACK强防护用例，应选B或明确各用例只触发诊断。给出逐类跨restart owner清单 | 同key第二次WB可能误配重复第一ACK；L2source/echo已有但L1key不等价txn。safe后台publisher可留也须次序证明，Controller fatal不保证全部drain。P1-08/P4-01..08/P5-09；11/F04/F07 | FROZEN U-D03/07/10：合法 TL 恰好一次，保留必要原 owner |
| D12 | MMIO pre-I/O闭段、重放及恢复floor；当前等待当前ioSeq<=SW而ROB等I/O | C09/C08，验证preceding execution后才能产生不可重复效果，且正常前进 | A：pre-I/O split/验证前缀，再建立不跨越该效果的恢复边界；B：跨恢复可重放的输入日志+exactly-once效果记录；C：按设备类别混合 | 推荐A为基础，明确未决前驱CP都已排除跨I/O恢复后才建floor，再决定哪些读结果需记录；B支持更广回滚但成本更大。不能只把<=当前Seq改成<=Seq−1 | **CONFLICT**：现代码通用I/O存在闭段等待环，且未定义重执行恰好一次；永久禁I/O也不满足正常执行。P4-09/P4-10/P4-11/P5-10；11/F05 | FROZEN U-D08：pre/post close+单效果 journal，Core 边界测试/不匹配处理待齐 |
| D13 | bounded资源与Forward Progress：SVB阈值14只留2槽，history64满，指令reserve非数据credit | C03/C10，Needed不丢、earlyclose有路、pendingcoherence不能无限延期 | A：按ROB/LSQ/MSHR/每Store版本需求等最坏条件保留close/drain/recovery credits并给优先级；B：专用escape保存空间/其他可证持久层，仍需许可与信用 | A；先画资源依赖、计算界限，再定阈值/队列/优先级；必要时加B。只加大容量不能证明关段可达 | **待证**：尚无闭环路径保证，current段history阻塞可反过来阻ECP；等待环的整机可达性未证。timeout/CANCEL/fatal不是成功。P4-11/P4-12/P4-13/P5-10；11/F06 | FROZEN U-D09：4 项预留+信用锁+park+保留 way，压力交错测试待齐 |
| D14 | 验收范围和CODE_READY解释；已有4组件/真实cachefixture而无整BOOM链 | C01–C10；论文V正确性比较恢复架构/内存状态 | A：先独立语义oracle，再真实模块→层次→BOOM及CheckerCDC逐级证据；B：仅以package计数/exit/现有harness PASS代替 | A；保持05原历史，下一轮按10约束审测试期望，补T01–T08、byte mask、CP/baseline及资源oracle。B不满足约束，无需作为可批准方案 | 当前均未编译/运行，static_check不验证语义；测试输入人工SW不证明producer；组件PASS不能外推全系统。P5-01..13；11/F09 | FROZEN：CODE_READY 与 VERIFIED 分开，用户运行全部硬件 |

## 3. 五个优先项目的明确边界

### SW：D01/D03/D09

`PAPER`已经确定“有效历史连续PASS前缀”。待确认的是其数值编码、bitmap分配信用、同拍优先级和跨域协议。推荐保留当前数值frontier，不把`SW=10, dead8–10`解释成这些段PASS；所有外传仍要HistoryValid。无法通过删除EVT过滤、清零旧Epoch bitmap或直接把SW设failedSeq来省决策。

`RTL`现有每拍+1、historySync冻结有价值，可保留。`DESIGN_DECISION`要把“裸covered helper”和完整Safe的接口/命名/前提分开；不要求所有本地preservation gate机械添加Verified，因为恢复选择允许Pending。

### Checkpoint Lifecycle：D05/D10

`PAPER`确定FAIL n恢复SCP n，并保存仍可回滚目标；不规定必须在out-of-order PASS时立即退CP。推荐采用现有保守集合，即有效Seq>SW及恢复pin；按更早FAIL7验证跨Epoch保留。

`RTL`捕获点是registered allocation、ROBempty/quiet和committedshadow。`DESIGN_DECISION`必须说明“内存状态”是前驱效果的语义前缀，而非同拍DRAM/所有Store物理完成；通过prefix drain/history保留补齐。具体CSR/中断/time、可选配置和restore实际完成未冻结。

### Version Reclaim / SafeBaseline：D06/D07

`PAPER`不允许`Safe => 可以删除唯一语义值`，也不要求`Unsafe => 必须永久保留每个副本`。可释放某位置的前提可以是精确副本已接手；可删除某语义值还需它不再是Current/Needed且不破坏baseline。

`RTL`archive receipt、DRAM ACK分别完成不同责任，保留这些边界。`DESIGN_DECISION`需选精确Needed或保守超集并证明容量；再决定baseline显式元数据还是全入口次序证明。不能因safe发布已ACK而默许后来旧safe覆盖。

### Identity Exhaustion：D04/D11

`PAPER`不固定16/32/64位，也没有指定永久failed是正确恢复方式。当前guard解决“不静默wrap”的局部安全问题，未解决正常执行寿命与重新前进。推荐先保留guard、量化slot/image/MSHR热点预算，再在无旧引用的范围内设计局部incarnation；Seq和内容身份涉及持久history，重置约束比纯事务ID更强。

待用户确定运行寿命/availability与ACK故障模型后，才能判断扩大位宽、受控重建或复用的工程取舍。复位清掉所有片上状态不能被自动归类为正确rollback。

### MMIO Barrier：D12/D08/D13

`PAPER`确定先验证preceding execution再做外部效果。当前`ioSeq<=SW`对未闭段等待自身验证是过强、且可能无进展的工程实现；论文没有要求这种门。

推荐先pre-I/O拆分并等待所有可跨该效果的前驱回滚风险消除，再建立恢复floor；按设备读写的可重复性决定日志。floor将改变CP允许恢复范围，必须有明确证明“更早FAIL不会在floor后合法到达”，不能执行I/O后强行删较早未验证CP。此方案未确认，本轮不修gate、不建立新floor。

## 4. 下一轮实施依赖与当前停止点

`DESIGN_DECISION`推荐审阅顺序：D01/D03/D05 → D06/D07 → D04/D11 → D08/D12/D13 → D09/D10/D14。依赖表示先明确语义，不要求串行完成所有硬件；SW/EVT CDC与baseline仍须在任何真实restart验收前闭合。

下次若授权实施，以11的9项修正F01–F09关联原任务，不抹去00–09审计历史。没有用户确认的选择保持本表状态；本轮不将任何工程选项标为CONFIRMED。论文约束C01–C10及用户范围C11才是此时冻结内容。

本轮已到审查停止点。没有RTL修改、新硬件、重构、硬件构建、仿真、FI、证据更新或commit；不自动继续实现。
