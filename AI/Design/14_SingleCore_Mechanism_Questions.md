# PALIMPSEST 单主核机制设计讨论题

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


2026-11-21。只记录会影响架构契约或实现方案的歧义，按错误数据/外部效果风险及其对恢复的影响排序。本文没有新增已确认决策；所有推荐均为 `DESIGN_PENDING`。论文约束不能被选择性豁免，用户需选择的是满足约束的工程方式与支持边界。普通功能接线、编译和测试准备不作为独立讨论题。

当前机制、代表性代码和两条端到端时序见 [13 机制讲解](13_SingleCore_Mechanism_Walkthrough.md)。`DC/CORE/REC/IC/SVB/HIST/SCH/L2P/L2M/LM/LSU/CHK/INC` 的完整源码路径见该文第2节；下列行号均为当前工作区。沿用 [12 决策记录](12_SingleCore_Design_Decision_Log.md) 的D编号，不修改其状态或原任务证据。

## Q01：恢复查询的候选全集和 DRAM 基线由谁共同负责？

**问题与当前理解。** `LatestSurviving`必须在所有可恢复候选中取最新有效值，SafeBaseline则必须真能代表所需值。两者不能各自只看一小块RAM后互相假定对方正确。需要确定：同址版本的已发布水位、在途保存责任和查询可见性，是一个统一协议，还是由现有coherence顺序作完整保证？

**PAPER约束。** IV-B/E要求跨层选最新有效值，允许Pending A7；仅当没有合格缓存值且DRAM代表所需值时fallback。IV-D要求抑制obsolete writeback、同址在途传输有序并保留最新有效safe baseline。

**当前RTL方案。** SVB与HIST各按最大surviving `(Seq,serial)`返回held response，DC归并；L2查询直接枚举sidecar，并等待incoming C/staging。HIST当前RAM候选升序发布，ACK后删项；SCH阻普通SourceC越过pending publisher/staging。尚无持久per-address“已发布到哪个key”的记录，也没有查询全部resident/读行/网络owner的统一接口（DC:860–897；HIST:102–144；SCH:156–185,386–395）。

**具体风险场景。** A7已写DRAM并从HIST释放，旧A6随后从另一路capture进入；它可能再次发布，或在查询时遮蔽普通coherent refill会取得的A7。另一种情况是A7唯一副本正在保存途中，局部query却报告no candidate。它们是待排除的条件模板，本轮未证明整机可达，也未观测到数据损坏。

**推荐及理由。** 先规定每地址单调的版本顺序、唯一在途发布owner及查询可见责任；所有外写入口、candidate迁移和baseline fallback共用该契约。可以先保留sidecar，实现显式发布高水位/obsolete过滤与owner交接，不能让一个RAM内的排序承担全系统证明。具体目录容量需结合有限实现决定。

**其他方案。** 不增加持久高水位，但给出现有coherence、源副本保留和全部入口的完整次序证明，证明上述模板不可达；或者集中同址传输/查询，牺牲并行度换较简单的证明。不能用“只恢复Safe值”替代候选完整性。

**代码影响与任务。** D06/D07/D11；P1-08、P3-08、P3-09、P3-10、P4-04、P4-08。影响DC冷查询/合并、HIST capture/publish、SCH调度及L2P终态；是否新增元数据取决于采用的全入口协议。**旧问题已由本轮 U-D01–U-D10 冻结；不再等待确认。历史问题涉及：确认责任组织与实现成本；最新值/基线不得倒退是既定约束。**

## Q02：哪些 SCP 始终存活，怎样证明每个 SCP 的内存前驱也始终存在？

**问题与当前理解。** SCP目录和history存储已经分离，但需要一个共同生命周期：CP可被选作目标，就必须既有架构快照，也有全部地址的最新有效前驱。要决定继续保守保存Needed超集，还是建立精确CP依赖，而不是只讨论何时把valid清零。

**PAPER约束。** IV-D定义Needed为某outstanding rollback CP的最新地址值；IV-E要求FAIL n恢复段首SCP n，保留更早跨Epoch历史。论文不强制乱序PASS后立即退休CP，也不要求RTL里必须有同名Needed函数。

**当前RTL方案。** REC16项按完整Seq查找、pin；未pin CP按`Seq<=SW`或restart discarded suffix退休。CORE在registered allocation采committed shadow/PC/CSR。SVB保留前驱到archive receipt；HIST安全发布到真ACK才free，但它们都不查CP引用集合（CORE:2125–2137；REC:47–79；SVB:281–365；HIST:124–144）。

**具体风险场景。** SW6、7Pending，FAIL8后新11/12执行，随后FAIL7仍是合法错误。SCP7应当还在，所有地址在SCP7之前的前驱也必须在；仅CP7目录有效不能证明后一件事。另一个边界是SCP8捕获时7的committed Store尚未完成cache效果，恢复排空必须保留并补完它，不能把“CP内没有Store队列”理解成可取消该Store。

**推荐及理由。** 先确认保守CP集合“有效且Seq>SW的SCP加恢复pin”，保留现集中RAM；将committed prefix Store drain、每CP每地址predecessor和跨层精确副本交接作为同一个不变量。以软件语义oracle描述所需值，硬件可暂用保守超集；然后按容量证据决定是否增加精确依赖索引。

**其他方案。** 对每个地址记录CP前驱/refcount以精确回收，或证明特定已PASS CP可提前退休并同步缩小历史需求。后一方案不能仅根据Checker slot已free推导。

**代码影响与任务。** D05/D06/D10；P1-03、P1-07、P1-09、P2-03、P2-04、P3-13、P3-14。影响SCP capture/信用、SVB/L2 reclaim及prefix Store drain；若选保守方案，不应为了实现函数同名强加全地址CP表。**旧问题已由本轮 U-D01–U-D10 冻结；不再等待确认。历史问题涉及：确认生命周期和保留策略；合法目标不能丢是既定约束。**

## Q03：SW、有效历史和 CDC 的原子发布应采用什么契约？

**问题与当前理解。** SW是有效历史连续PASS的验证frontier，不是VersionValid。当前数值可经过dead洞，因而必须定义所有消费者何时已经知道哪些洞是dead，query held结果属于哪版上下文，以及reset后身份如何一致。

**PAPER约束。** III/IV-C规定前驱有效段全PASS才推进、跳过废弃区间；外传同时要求历史有效及被SW覆盖。论文没有规定数值编码、Gray电路、同步级数或mailbox协议。

**当前RTL方案。** DCache持有tagged bitmap和SW32，每拍+1，historySync期间冻结；query mailbox把EVT同步给L2并等ACK高/低，Checker也接收context但无独立安装ACK。SW以组合next-state Gray经三级同步到L2。REC.survives带allocatedTail，DC/HistoryQuery helper只排tombstone（DC:655,898–919,2890–2943；INC:214–240,291–305；CHK:1305–1313）。

**具体风险场景。** dead8–10后SW到11，旧K9满足裸`9<=11`。稳定兼容EVT下，现有查询/关键外写gate会拒绝K9；若某接收域先看见新SW而还用旧EVT，或reset使旧query/ACK错配，裸比较可能提供错误许可。另需排除未分配Seq被只排dead的helper当live。上述并发风险没有被“每拍只+1”自动解决。

**推荐及理由。** 保留数值frontier作为D01提案，明确`covered`与完整Safe的接口区别；统一Allocated/HistoryValid来源契约。SW源寄存Gray、四相payload稳定/接收/reset契约和所有消费域的历史发布顺序需一起定义。若这些独立CDC难以证明，采用带incarnation的统一SW/history消息，保持单一兼容版本。

**其他方案。** 用显式有效历史游标/区间frontier编码；或所有控制状态通过AsyncQueue/mailbox原子传送。不能通过清旧Epoch bitmap、把SW设failedSeq或删EVT过滤来省协议。

**代码影响与任务。** D01/D03/D09；P0-06、P1-02、P3-02、P3-05、P4-05。影响SW源、query/context payload、reset和consumer前提；bitmap tag/有效前缀结构可以保留。**旧问题已由本轮 U-D01–U-D10 冻结；不再等待确认。历史问题涉及：选择编码/跨域方案；Valid与Covered联合授权不待选择。**

## Q04：哪些旧事务必须等完，哪些可跨 restart；重复 ACK 属于什么故障模型？

**问题与当前理解。** 已接受TL责任不能丢；但不必让所有history/publisher都清空才恢复。需明确一份逐类owner名单：restart前终结，还是以原身份隔离继续运行？此外，合法迟到响应与协议外复制ACK应有不同要求。

**PAPER约束。** IV-D要求异步确认只更新对应版本/reservation；IV-E要求在途协调后resume，不让旧传输修改已恢复状态。论文未定义任意重复网络响应的容错模型，也未要求所有FSM同时idle。

**当前RTL方案。** DC/LSU等待MSHR、S1–S3、WB及pending ACK、Probe、SVB capture、archive、replay/completion和存活prefix Store；CORE再等suffix Checker release与RSU。没有等待全部L2后台publisher。L2P/L2M有64bit事务serial，L1voluntary WB按key/source/size/sent核对但无独立per-WB serial（DC:1893–1903,4752–4763；LSU:607–609；CORE:2105–2106；L2P:187–215）。

**具体风险场景。** 某safe L2 publisher跨restart保留可合理，但必须保证后来旧safe写不会越过新baseline。L1同key两次WB之间若额外复制第一ACK，在第二次全sent后到达，key无法识别是哪笔；合法TL恰好一次模型下它不应出现。另有比“是否重复”更基础的情况：旧Probe或Store completion还持slot/STQ，局部reset却复用了该槽。DC:2770–2773清fast-line lease，而:3673–3682的release断言未列rollbackReset；若带live lease进入reset的前态可达，还需明确取消终态如何被认可，这不是一个已有的完整取消ACK。

**推荐及理由。** 先按合法TL恰好一次模型列全owner和terminal，所有合法迟到仍须正确匹配；只让已经隔离且安全的后台owner跨restart。若产品目标包括抗任意重复/跨incarnation响应，再为L1WB等补独立txn echo或隔离世代，不能以immutable key代替事务号。

**其他方案。** 全层排空后restart，简化隔离但要证明不会因unsafe/history满而互等；或扩大带incarnation的响应隔离域以允许更多后台事务。额外duplicate注入也可限定为诊断终态，但需明确不算成功恢复。

**代码影响与任务。** D11/D07/D09；P1-08、P4-01、P4-02、P4-04、P4-05、P4-06、P4-07、P4-08、P5-09。影响quiesce predicate、TL字段/adapter、WB回执、Checker片段处理及验证模型。**旧问题已由本轮 U-D01–U-D10 冻结；不再等待确认。历史问题涉及：尤其是故障模型和跨restart责任范围。**

## Q05：架构恢复集合和“导入完成”应怎样定义？

**问题与当前理解。** 当前已向真实PRF、Rename、CSR和Frontend接入restore，不应再称“只有shadow”；但仍要决定支持的架构状态和异步事件，以及完成判定是否可以固定拍表达。

**PAPER约束。** III/IV-E要求恢复SCP架构状态、协调在途后重启。论文没有逐个列RISC-V可选CSR、wall-clock、PTW、interrupt或PRF接口延迟。

**当前RTL方案。** SCP保存integer/floating/PC/8192bit CSR；先局部pipelineReset，再专用PRF并行写，重建map/free/busy，CSR本地解包；cycle/time和外部pending输入不回滚。CORE以`RegNext(recoveryRestore)`作为restored，restart PC走fresh FTQ redirect，没有逐单元restore ACK（CORE:2114–2132,247–251,896–910；CSR.scala:2140–2178）。

**具体风险场景。** 某可选CSR未纳入snapshot、旧PTW/Fetch响应在新PC后返回、或interrupt pending在恢复期间改变；寄存器payload看起来正确也不必然保证下一条指令等价重执行。固定拍done若先于某实际写完成，resume就会读到旧值。这些不是已观测错误，需边界清单与数据路径证明。

**推荐及理由。** 明确当前支持配置的完整架构状态/异步事件清单，说明time、pending interrupt、LR/SC和地址翻译的恢复规则。对目前并行写口可保留固定拍实现，但把每个写端的实际生效时刻列成完成契约；有可变延迟或跨域单元则使用真实ACK汇合。

**其他方案。** 所有restore单元提供valid/ready/done事务，减少配置扩展时对固定时序的依赖；或者限定支持特权/CSR集合，其他配置明确不开放恢复。不能默许漏恢复后仍宣称全架构支持。

**代码影响与任务。** D05/D10/D11；P2-05、P2-06、P2-07、P2-08、P2-10、P4-02、P4-10。影响CORE恢复阶段、PRF/Rename/CSR导入口、LSU/TLB/PTW/Frontend边界和restart ready。**旧问题已由本轮 U-D01–U-D10 冻结；不再等待确认。历史问题涉及：确认支持范围及异步语义；实际恢复先于resume是既定约束。**

## Q06：MMIO 的检查边界应放在哪里，恢复是否允许跨设备效果？

**问题与当前理解。** 仅给设备请求加`Seq<=SW`无法定义恰好一次副作用；首先要决定I/O前如何封口，I/O后哪些CP仍是合法目标，以及设备输入是否要被重放。

**PAPER约束。** IV-C要求uncacheable/nonrepeatable I/O触发early close，等preceding execution验证后再执行。论文未指定日志、pre-I/O拆段或recovery floor。

**当前RTL方案。** 非cacheable请求进IOMSHR前检查current ioSeq<=SW，blocked请求发cacheEarlyClose；普通snapshot仍要求ROB empty。当前没有通用pre-I/O边界状态机、effect日志或恢复floor（LM:1119–1166；DC:940；CORE:2331–2345）。

**具体风险场景。** 段8的MMIO Load不完成，ROB不能empty；没有ECP8就没有PASS8，SW不能到8，许可又始终不成立。若简单放宽到SW>=7而允许设备写，之后FAIL8重执行可能把UART等效果做两次；若更早段尚未PASS，强行建立floor又会丢合法恢复。

**推荐及理由。** 以pre-I/O split为基础：在设备动作前形成完整可验证边界，消除前驱回滚风险后才外发并建立明确恢复floor；需要跨效果恢复的设备另用输入日志/效果去重。按设备读写、read-to-clear、AMO、Fence/中断区分策略，不把所有uncacheable请求都假定可重复。

**其他方案。** 全面使用跨恢复可重放的exactly-once效果日志，或限定受保护区间不含某些设备访问并在进入/退出时执行明确协议。永久禁全部I/O、或仅改一个比较符，不满足完整正常执行目标。

**代码影响与任务。** D12/D08/D13；P4-09、P4-10、P4-11、P5-10。影响CORE/IC分段、LSU/IOMSHR准入、SCP允许恢复范围及日志接口。**旧问题已由本轮 U-D01–U-D10 冻结；不再等待确认。历史问题涉及：设备支持类别与跨I/O恢复能力直接影响架构。**

## Q07：Early close 依靠哪些资源信用，才能保证请求最后真的形成 ECP？

**问题与当前理解。** 发出关段请求只表达需求；若现有ROB/LSQ工作还要申请满掉的history才能到边界，close本身也可能被堵住。需选择保证close/drain/recovery可完成的准入与仲裁方式。

**PAPER约束。** IV-G要求当前段unsafe引起preserve/WB/coherence阻塞时提前关段并验证，pending coherence优先于后续冲突写。论文未给槽数或具体credit公式。

**当前RTL方案。** SVB14/16发close，L2history64压力发最老Seq验证请求；IC命令ACK与真正finalization分开。CORE只预留instruction drain计数，没有按Store/eviction/缺页等需求预留完整存储信用；尚未有全链资源依赖证明（DC:940–941；SCH:398–401；IC:252–267；CORE:2350–2353）。

**具体风险场景。** 当前段填满history，后续已dispatch Load miss需保存victim才能完成；victim不能腾空间，ROB不能empty，Checker又等ECP。是否能在实际配置触发尚待证明，不能把缺证明写成已发生死锁；但“仅余两槽”也不能当作充分储备。

**推荐及理由。** 列出每种accepted owner的最坏剩余资源需求，用显式credit在接收新工作前保留close、drain、恢复和pending coherence的逃生能力；确定公平/优先规则。先计算界限再选阈值，不从已写的14这个常数反推正确。

**其他方案。** 独立escape history/封口资源，或更严格地限制每段存储足迹/在途数量；只扩大RAM可作容量选择，不能代替证明。timeout/CANCEL/fatal不是成功完成原程序。

**代码影响与任务。** D13/D06/D12；P4-11、P4-12、P4-13、P5-10。影响dispatch/LSU/cache准入、SVB/HIST容量阈值、L2仲裁和earlyclose完成协议。**旧问题已由本轮 U-D01–U-D10 冻结；不再等待确认。历史问题涉及：需选择性能、容量及支持边界；最终forward progress是既定目标。**

## Q08：正常运行的身份寿命目标是什么，耗尽后怎样继续？

**问题与当前理解。** 不回绕防止alias，不能说明服务可以持续。需确定最短支持运行寿命/恢复次数及可接受的中断范围，才能选择扩位、局部incarnation或受控系统重建。

**PAPER约束。** Seq单调且rollback后不复用；ACK不误配；IV-G支持正常前进。论文没有指定16/32/64位，也没有把永久failed规定为正常恢复方式。

**当前RTL方案。** Slot16、内容serial32、MSHR32、Seq/Epoch/G32、L2serial64及LSUtoken预算都单调，guard汇合到Controller.failed且无退出。EVT32个不相交dead区间也可能耗尽。owner完成释放占用，不返还数字（DC:767–772,942–950；LSU:508–512；IC:135–136；REC:114–143,203–207）。

**具体风险场景。** 无错误程序反复替换同一L1槽即可触发16bit终态；同段大量Store也用内容serial32。即使所有TL消息已排空，历史RAM/CP/cache里还可能留旧key/CurGen/Seq，直接归零会复活旧映射或误认响应。硬reset清掉片上unsafe数据也不能默认视作正确恢复。

**推荐及理由。** 先保留全部guard，量化各scope热点事件预算；slot/MSHR等可局部排空身份研究带incarnation复用，持久内容/Seq/EVT/G按最老可引用对象定义回收或更强重建边界。Seq不能在同一恢复域静默复用。扩位可以争取工程寿命，但不是完整再初始化协议。

**其他方案。** 用户明确接受有限寿命并在安全点受控重建恢复域；或使用更宽/分层身份达到规定寿命。若目标是长期连续运行，单纯永久停止不是可选等价实现。

**代码影响与任务。** D04/D03/D11；P3-15、P4-06、P4-12、P4-13。影响allocator、slot/内容身份、EVT压缩、drain范围及fatal处理；不得先删除保护再补设计。**旧问题已由本轮 U-D01–U-D10 冻结；不再等待确认。历史问题涉及：运行寿命、availability和重建中断边界须先确定。**

## Q09：BASE、Seq0、native peer 和外部写属于哪个可信恢复边界？

**问题与当前理解。** 单Main并不代表系统没有其他观察者或修改者。Seq0/BASE是当前编码的可信特例，需要说清哪些实际事件可以使用它，以及受保护执行期间外部写如何排序。

**PAPER约束。** IV-C/F要求unsafe不能传出恢复域；IV-D/E要求最新有效前驱/安全baseline保持可用。论文没有规定本项目Seq0、DMA管理、Checker运行软件及中断设备的具体信任模型。

**当前RTL方案。** KEY/LP safe把BASE或Seq0当安全，LP对incomingSeq0有覆盖特例；L2 native peer受park/replay，BOOM image-aware可内部接unsafe。内存版本按Seq/serial排序，不另有可信写的全局顺序编号（KEY:32–40；LP:70–81；SCH:371–378,524–533；LM:1121）。

**具体风险场景。** 已有旧SCP、A7历史时，DMA或trusted Seq0在物理时间更晚写A；只按Seq0最小排序可能选旧A7，或者回滚跨过已对外可见的写。把dead数据改成BASE又会绕过survives/covered检查。这里缺的是支持范围契约，不能擅自假设所有DMA都不会发生。

**推荐及理由。** 受保护区间的普通Main semantic write都必须有合法Seq；明确Seq0允许的初始化/管理时段。外部native写要么被隔离，要么在可证明安全的恢复floor/顺序incarnation上纳入；保留native observer验证屏障。内容key与物理cache有效bit继续分开。

**其他方案。** 将所有外部写入也纳入统一版本顺序/日志，或明确受保护内存区域独占、域外区域不参与回滚。两者都需要平台地址/设备契约，不能凭字段存在决定。

**代码影响与任务。** D08/D07/D12；P0-06、P1-05、P4-09、P4-10。影响trusted访问准入、LP例外、baseline排序、内存域和MMIO/中断边界。**旧问题已由本轮 U-D01–U-D10 冻结；不再等待确认。历史问题涉及：属于平台保护范围选择。**

## Q10：PASS 是否不可撤销，CANCELLED 与超时到底应怎样恢复？

**问题与当前理解。** 结果协议必须说明一次完整PASS的信任强度，以及没有结果/日志损坏/历史取消是否都等价于程序错误。否则SW、CP退休和重试策略没有稳定前提。

**PAPER约束。** III/IV-C按完成验证结果推进SW，IV-E按有效错误恢复；论文未定义本实现所有timeout/transport cancellation诊断类别。既有安全外写不能在之后仅靠回滚撤销。

**当前RTL方案。** CHK full_check_complete后产生PASS/FAIL；历史dead、传输错误、ARF/exec/progress timeout可产生CANCELLED。DC对有效FAIL/CANCELLED均发`{seq,cancelled}`恢复事件；completed或covered的后续结果不会再次改变bitmap。不同取消原因没有完整穿透Controller（CHK:1516–1543；DC:2822–2846,2850–2875；REC:6–10）。

**具体风险场景。** 若PASS8后允许另一次FAIL8撤销，SCP8可能已退休、A8可能已写DRAM，现协议不支持。若日志结构故障使同一工作每次timeout，取消→rollback→重试可能永远不能前进；把每次成功进入Controller当“恢复成功”会掩盖该故障。

**推荐及理由。** 在当前模型下规定完整PASS不可撤销；无结果前允许合法错误/取消。保留并传播cancel原因，分别决定history取消的清理、暂态错误重试、持久传输/无进展故障诊断及升级策略。恢复完成必须以重新取得正确执行进度衡量，不能以FAIL脉冲消失衡量。

**其他方案。** 要求对已PASS结果的后验故障也可恢复，则必须扩大信任/保存窗口、延迟不可撤回外部效果并重设计CP退休；或对部分transport故障直接fail-stop并显式超出恢复范围。不能继续沿用旧SW语义同时声称支持PASS撤销。

**代码影响与任务。** D02/D11/D14；P2-01、P2-09、P2-11、P4-13、P5-07、P5-09。影响结果payload、错误分类、Controller策略和oracle，原最早错误/pin机制可保留。**旧问题已由本轮 U-D01–U-D10 冻结；不再等待确认。历史问题涉及：故障模型与重试/停机边界需要共同确定。**

## 建议先讨论的五组问题

先讨论Q01的候选全集和同址baseline责任，再讨论Q02/Q05的SCP共同边界与restore完成；随后确认Q03/Q04的SW/EVT及在途/ACK协议；最后结合Q06/Q07决定I/O封口与资源信用，结合Q08/Q09/Q10明确运行寿命、可信域和故障范围。这是讨论顺序建议，不是已批准的实施计划。

本文到设计讨论准备为止。没有更新任务状态、决策确认状态、RTL、配置、测试或完成证据，也没有执行硬件构建、仿真、FI或commit。
