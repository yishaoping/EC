# PALIMPSEST 单主核语义差异审查

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


2026-11-21；只读源码/论文审查。**当前不能确认完整单Main rollback语义闭合；SW的有效历史前缀算法、Pending版本选择及错误suffix裁剪方向正确，但baseline顺序、保留集合、CDC、MMIO和有限资源前进仍未闭合。** 不能把旧审计中“没有EVT/Controller”继续当当前事实，也不能用已写RTL维护一种违背论文的解释。

## 1. 证据边界及定位字典

分支 `firesim/fpga-checkpoint-20261104`，HEAD `75f2905693d6eec3b92d733e65bafa7a9c4be6dc`，**包含既有未提交RTL及untracked源码**。00–04描述的是实施前干净代码；05–09描述后续工作区，不同证据版本不可混用。本次读取了00–09、05 JSON的69任务/49功能、论文p3–5、当前相关源文件和diff；本次不重跑旧验证，也不修改其完成证据。

标记：`PAPER`=论文明确行为；`RTL`=当前源码表达；`DESIGN_DECISION`=尚需选择/证明的工程实现；`CONFLICT`=约束冲突。`局部一致`只表示读取的谓词与规则一致；`待证`不表示已发现运行错误。所有场景均为静态推演，没有硬件编译、elaboration、仿真、FI或commit。

全文简写 `DC:行号` 等均指以下**当前工作区**文件。行号不引用generated RTL或旧波形。

| 简写 | 完整文件 / 主要模块 |
|---|---|
| DC | [dcache.scala](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/lsu/dcache.scala)，BoomNonBlockingDCacheModule / BoomWritebackUnit |
| REC | [PalimpsestRecovery.scala](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/exu/PalimpsestRecovery.scala)，ContextMemory / ExecutionHistory / RollbackController |
| CORE | [core.scala](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/exu/core.scala)，BoomCore |
| TILE | [tile.scala](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/common/tile.scala)，BoomTileModuleImp |
| IC | [R_IC.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala)，段/Checker ownership |
| CHK | [RocketCore.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala)，Checker result/cleanup |
| GHM | [GHM.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala)，result CDC |
| LSL | [R_LSL.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/r/R_LSL.scala)，checking FIFO |
| CMP | [R_RSUSL.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/r/R_RSUSL.scala)，寄存器比较 |
| CSR | [CSR.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/rocket/CSR.scala)，CSRFile |
| LSU | [lsu.scala](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/lsu/lsu.scala)，LoadStoreUnit |
| LM | [mshrs.scala](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/lsu/mshrs.scala)，BoomMSHR / BoomMSHRFile / IOMSHR |
| LP | [phase1.scala](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/lsu/phase1.scala)，L1Preservation |
| SVB | [speculative-version-buffer.scala](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/lsu/speculative-version-buffer.scala)，SpeculativeVersionBuffer |
| KEY | [CacheImage.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/tilelink/CacheImage.scala)，CacheImageKey / safe |
| HIST | [PalimpsestHistory.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/tilelink/PalimpsestHistory.scala)，IdentityAllocator / HistoryQuery / VersionHistory |
| INC | [InclusiveCache.scala](/data1/gzh/EC/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/InclusiveCache.scala)，L2 mailbox/CDC |
| SCH | [Scheduler.scala](/data1/gzh/EC/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala)，L2 Scheduler |
| L2P | [L2Preservation.scala](/data1/gzh/EC/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/L2Preservation.scala)，保存/外存Put engine |
| L2M | [MSHR.scala](/data1/gzh/EC/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/MSHR.scala)，L2 MSHR |
| SC | [SourceC.scala](/data1/gzh/EC/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/SourceC.scala)，实际外层C beats |

论文：[PDF](/data1/gzh/EC/AI/Ref/DAC_2027_EC.pdf)，SHA256见10；p3 III/IV-A/Fig.3；p4 IV-B/C/D/Algorithm1；p5 IV-E/F/G。权威不变量见 [10](10_SingleCore_Semantic_Spec.md)，工程待决策见 [12](12_SingleCore_Design_Decision_Log.md)。

## 2. 逐机制对照

| 机制 | PAPER要求 | RTL当前行为 / 证据 | 是否一致 | 风险 | DESIGN_DECISION / 修正建议 |
|---|---|---|---|---|---|
| Seq | p3 III，rollback后不复用 | IC:135,239,279–289,505；counter保留，32bit最大值fatal | 局部一致 | 正常长期执行耗尽；最终段关闭也受counter满门控 | D04，保留不复用，决定运行寿命/全新incarnation |
| 完整验证 | p3 Fig.3，记录段结果 | CHK:1516–1550；GHM:553–577；DC:2822–2846 | 局部一致 | CANCELLED与FAIL共恢复但诊断类别弱；迟到不同payload非可撤销PASS | D02，区分故障类别，保留terminal/release链 |
| SW | p3 III/p4 IV-C，有效连续PASS前缀，跳dead | DC:2890–2943，单步+1、historySync冻结、dead跳洞 | 数值算法方向一致，整链待证 | 假定bitmap/tag、上下文完整；CDC未闭合 | D01/D09，确认frontier编码及原子发布 |
| Safe谓词 | p4 IV-C，Valid且covered | KEY:32/LP:70裸covered；SCH:124、HIST:124补EVT | helper不完整；关键消费者多处补齐 | **CONFLICT**：将裸helper直接解释为VersionSafe | 区分命名/类型，逐效果点说明附加前提 |
| EVT | p3 IV-A/p5 IV-E，跨Epoch有效区间 | REC:109–144，32个dead闭区间；Seq隐式epoch | 编码可等价；容量有限 | DC:655/HIST:43无tail检查；第33个disjoint rollback无回收 | D03/D04，明确来源不变量和回收协议 |
| SCP捕获 | p5 IV-E，SCP n为段首 | CORE:2125–2137,2331–2346，registered alloc + empty/quiet | 结构符合，边界待证 | committed影子/CSR/延迟Store不一定同物理时刻；需语义join | D05/D10，明确CP和cache前缀drain契约 |
| CP退休 | p4 IV-D，安全覆盖后不需该CP历史 | REC:71–79按SW/discard，pin优先；CORE:2099–2102在restart discard | 保守策略可保留 | 乱序PASS保留较多CP，不是错；不能据CP free直接删baseline | D05，确认保守集合和容量信用 |
| Current/G | p3 IV-A/Alg1，lazy逻辑失效 | DC:830–858,1821,3625；G/CurGen32，与内容serial分开 | 局部符合 | surviving resident快速重绑的最大性、late refill/probe仍待证 | D06/D11，候选完整性及owner重验 |
| 跨段Store | p4 IV-B，whole-line predecessor+mask | DC:2066–2074,2140–2175,3294–3300,3385–3397；SVB全行RAM | 普通Store方向一致，其他路径未闭合 | AMO/SC/RPQ/full fallback更保守，会WaitSafe | 保留快路径，修close/headroom，不能省旧字节 |
| NeededForRollback | p4 IV-D，对任一live CP的latest predecessor | LP:73–81按samePackage/safe/receipt；SVB/HIST不读CP集合 | 没有精确谓词；保守实现可能等价 | 缺全层“所有Needed仍有副本”证明；过保留导致满 | D06，可选精确或保守超集，不能只看Seq>SW |
| SVB回收 | p4 IV-D，preserve-before-reuse | SVB:281–365；DC:699–728；dead SPEC删、WB_WAIT exact archive ACK删 | 责任交接局部一致 | archive receipt不等于DRAM ACK；普通exception/RESET现在不删历史 | 保留当前机制；查跨层唯一副本/容量 |
| L2回收 | p4 IV-D，最新有效safe必须可用 | HIST:95–144，dead删，safe等精确外存ACK | 必要条件已写，充分性待证 | obsolete写回/迟到旧capture仍可使baseline倒退 | D07，统一同址次序后才确认全局正确 |
| LatestSurviving | p5 IV-E/Fig4b，允许Pending A7 | SVB:124–147/HIST:102–123/DC:860–884，最大surviving Seq/serial，无SW筛选 | 选择函数一致；域覆盖待证 | L2只查sidecar；ordinary resident/staging/publisher是否全覆盖未证 | 保留无Verified门控的比较器，补候选域闭包 |
| SafeBaseline | p5 IV-E，仅DRAM代表所需值时 | DC:885–897/LM:177–187，not found→普通coherent refill | 未闭合 | noCandidate非DRAM正确证明；旧safe残影也可能遮蔽新baseline | D07，baseline provenance与obsolete suppression |
| 外层WB | p4 IV-C/D，valid-safe且不倒退 | SCH:386–395,490–495；HIST:124；L2P:108,166；SC:175–182 | 局部门控符合；全入口顺序待证 | beat断言非gate；live上下文/已调度事务需共同证明 | D07/D09/D11，不能仅加一条assert称闭合 |
| native peer | p4隔离/p5 IV-F，外部不能见unsafe | L2M:266–285；SCH:371–378,524–533，unaware park/replay | 单Main仍需保留；动态未验证 | image-aware多Main豁免是范围外缺口；pending后续冲突写优先未证 | 单Main保留Rocket/DMA隔离，多Main路由Deferred |
| Rollback/restart | p5 IV-E，SCP n+history+inflight协调 | REC:173–211；CORE:2094–2143；DC:4752–4763 | 控制骨架一致；完成条件未全证 | restored为固定拍数；L2publisher可跨restart，须隔离证明 | D10/D11，逐类terminal与原子restore |
| LSL | p3 III/p4 IV-D，验证后独立释放 | LSL:215,257；CHK:1534–1550；独立CP/history RAM | 局部一致 | FIFO消费、slot release、CP free三个事件不能合并 | 保留，P1-10不是其他历史生命周期已通过 |
| MMIO | p4 IV-C，close+preceding verified后I/O | LM:1119–1164要求当前ioSeq<=SW；CORE:2331要求ROBempty | **CONFLICT：通用前进缺失** | I/O→ROB→ECP→PASS→SW→I/O循环；exactly-once/floor未定 | D12，边界拆分及重放契约先行 |
| 容量/优先权 | p5 IV-G，early close、pending coherence优先 | DC:940–942 SVB14阈值；SCH:398–401 history64压力；CORE:2350仅指令预留 | 待证：完整活性保证缺失 | current段把RAM填满可阻止ECP；关闭命令ACK不是PASS；等待环的整机可达性尚未证明 | D13，按最坏依赖留credit并证明优先权 |
| 身份耗尽 | p4 IV-D身份准确；p5 IV-G前进 | REC:203–207 permanent failed；DC:949；LSU:508–512等 | 安全保护方向合理；不等于前进 | 正常负载也会触发16/32bit终态；无drain/reinit | D04/D11，保留guard但不能视完整恢复已完成 |

## 3. SW 生产、传递与全部消费者清单

搜索覆盖当前BOOM、Rocket-chip、inclusivecache Scala中 `safePacketWatermark/newSafePacketWatermark/rollbackSafe/safeWatermark/watermark/CacheImage.safe/L1Preservation.safe` 及其Boring名称。下表将每个功能性使用点和观测性使用组分开；没有把历史文档命中的旧行号当源码。`PAPER`统一依据p3 III/p4 IV-C/D；额外CP/事务约束按表注明。

### 3.1 功能性生产与跨模块链

| 位置 / 模块 / 行号 | RTL表达式/作用 | PAPER要求及审查 |
|---|---|---|
| IC / R_IC:135,269–289,311–312 → TILE → DC:647–648,2788 | 分配事件完整Seq进入EVT tail及bitmap | 分配不代表PASS；保持完整Seq-tag，slot可环形但执行身份不可alias |
| DC / DCache:2003–2011 bitmap定义、2781–2797 | allocated/completed/passed/seq，窗口256；collision置错 | Valid bitmap项≠HistoryValid；须证明outstanding分配窗口不越界；P1-02未完成 |
| CHK:1535–1550 → GHM:553–577 → TILE → DC:2809–2846 | `{valid,status,Seq}`；accepted要求完整tag、未completed、非stale、known status、非重复 | 乱序PASS只置本段passed；FAIL/CANCELLED completed但passed=false。所有有效前驱仍须PASS |
| DC:2822 | `resultStale = valid && seq!=0 && (seq<=SW || !survives(seq))` | covered结果不再影响前缀，dead结果不能复活；已完成PASS不可再撤销是协议假设 |
| DC:2890–2903 | 连续PASS扫描；`discardedNext=!survives(SW+1)&&SW<tail`；`newSW=historySync?SW:SW+bool` | +1包含dead；没有FAIL→抬高SW。死区跳过必须在history已发布后 |
| DC:2928–2943 | covered或dead bitmap清零；SW提交 | 清bitmap是验证资源回收，不是history data或CP全删除 |
| DC:930 | `RegInit(0.U(32.W))` | 只有模块reset重置；traffic RESET/exception/rollback无重置。旧有效PASS/Pending跨Epoch保留 |
| DC:931–935 | →SVB.safeWatermark；→rollbackSafe；→MSHRFile.safeWatermark/executionTail | 三类消费语义不同；不能把共享输入当统一回收许可 |
| TILE:687 → CORE:2098 → REC:31,71–79 | CP回收 `seq<=SW || discard`，pin/read优先 | 保守合法；还须完整CP capture、pin生命周期以及baseline保留不变量 |
| DC:2920–2922 → INC:291–305 | `gray=newSW^(newSW>>1)`；Boring→sync3→binary→Scheduler | 单步改善逻辑Gray；源为组合next-state表达式，未见Gray源寄存/CDC物理约束证明。不能据逻辑单步证明无毛刺/无撕裂 |
| INC:305 → SCH:86,116–137,242 | →L2Preservation/VersionHistory/SourceC/MSHR；historySafe补EVT | SW滞后可保守阻塞；SW先跨dead而EVT尚旧会错误授权，需发布先后不变量 |
| DC:898–919及INC:220–240/SCH:121–125 | historySync同步查询发布EVT；收齐ACK高再等低后释放freeze | 实际有四相顺序保护；payload sync3/request sync8是工程假设，未做CDC/reset验证；Checker收EVT无专门ACK，依靠原slot release drain |

### 3.2 功能性比较与复用许可

| 位置 / 模块 / 行号 | RTL比较及现有效果 | 需要的附加条件 / 结论 |
|---|---|---|
| KEY:32–40 / CacheImage | `!key.valid || seq==0 || seq<=SW`；samePackageSupersede要求`!safe` | 仅covered/trusted测试；不是VersionValid/Safe。samePackage需Seq唯一、同writer和有效历史来源；不能独立授权外传 |
| LP:70–81 / L1Preservation | 同上safe；allow为不存在/同段/`safe&&(incoming0||lowerPreserved)`；copyAllowed要求同key或safe+receipt | 这是本地覆盖保守许可；Needed由精确下层副本/同段边界间接保护。incomingSeq0绕过下层保存的可信边界须D08；不能据它删除全局唯一baseline |
| DC:1723–1729,1771–1775 | refill/install调用copyAllowed | 还需tag/slotEpoch/MSHR txn/精确installed image/reservation及drain；不要求incoming恢复值safe，因为Pending A7合法 |
| DC:2045–2074 | allow与SVB eligibility使用old.safe/unsafe；suffix取消可绕本地等待但S3不效果 | 正常请求的Current必须先经G/EVT；ordinary跨段unsafe capture；safe仍须精确lower receipt。不是Needed的精确计算 |
| DC:2247–2262 | `!safe`维持WaitSafe读旁路；`safe`才发legacy crossPackage WB | L1→L2内部转移不是DRAM外传；dead数值covered可能走该转移，下层必须过滤；不能把wait解除算完整验证/保存 |
| DC:3392–3397 | S3再检查allow或SVB精确lease，imageSerial/owner/kill等门控实际写 | 保护实际效果的必要条件；仍依赖Current有效和跨层保留。不能单把s3_preservationAllowed称VersionSafe |
| SVB:163–166 | `valid && SPEC && historyValid && (!key.valid || seq0 || seq<=SW)` | 此entrySafe目前用于观测，不门控unsafe archive迁移；实际transferable在:213只要求survives。故Pending A7可迁移/可恢复 |
| HIST:124–140 | `valid && context.survives(seq) && CacheImage.safe`→safe publisher | 外传资格包含EVT；还需全地址obsolete抑制、精确terminal。Safe本身不能直接free |
| SCH:124–125,371–378 / L2M:266–285 | historySafe；native peerUnsafe为dead或未covered；park | 关键隔离gate含EVT。image-aware本Main允许unsafe；扩成多Main豁免不成立 |
| SCH:214–227 | replay条件`q.seq<=SW || !survives(q.seq)`；waitingUnsafe为`q.seq>SW && survives` | dead触发重查，**不是**允许把dead数据直接交peer；directory:740取消dead hit，MSHR重新规划，D:371再gate |
| SCH:250–274 / L2P:20–21 | bare safe影响samePackage覆盖和blocked `!preserved&&(!safe||dirty)` | 只选择是否保存/复用，需精确receipt、后续history过滤。将它解释为完整外写safe是CONFLICT |
| SCH:310–325,394–401 | bare safe可运行候选、drain.safe、unsafeSameLine；pressure触发close | eligibility/诊断/压力，不是唯一外写gate；dead且covered可选中后L2P必须走archive/drop |
| L2P:78–108,156–166 | bare safe决定need；`archiveMode=!safe||!survives`；实际Put fire断言两者 | 已有dead保护；send.valid本身不再检查EVT，需证明捕获safe者在合法后续rollback中不会变dead，以及accepted multibeat责任 |
| SCH:386–395,490–495 | 外C gate完整historySafe或dead；dead强制dirty=false、opcode去data | dead允许释放权限而不能写dead bytes；另有publisher/staging阻塞及锁。需保证本次schedule用对image |
| SC:175–182、SCH:855–872 | request/实际C beat断言EVT+covered；outer A再断言bare safe，L2P内补EVT | assertion不是功能gate；安全由前级准入与状态不变量实现。outerA处裸比较不能独自证明全链 |
| LM:1119–1164 | `!rollbackStop && survives(ioSeq) && (seq0?tail<=SW:ioSeq<=SW)`许可I/O | 带EVT，却错误地依赖当前未闭段自身验证，缺pre-I/O协议；安全阻塞不等于进展 |

### 3.3 观测性比较和非功能输出

以下也属于SW消费者；它们不授权数据、slot、WB、CP或restart，不能用其计数替代语义证明。

| 文件/位置 | RTL用途及表达式 | 审查 |
|---|---|---|
| DC:2083,2320–2401,2557–2643,3651–3657,3812,4040 | printf、hang snapshot、debug taps；含`activeKey.seq<=SW` | 可打印dead为数值covered；标签safe不必然表示完整VersionSafe |
| DC:2954–3040 | DirtyWritebackBucket resolve `bucket.seq<=newSW`；WB.seq `>SW`/`<=newSW`/`<=SW`，窗口baseline一致性 | 延迟统计不含EVT，dead跳洞也可能结算成“safe”；需未来标discard/cancel，否则指标误读；不影响功能SW |
| DC:3548,3707–3718 | overwrittenSeq `>SW`、replacementSeq `>SW`；BarrierLatencyStats输入newSW | 同样仅观察，不能当Needed/外部安全判定 |
| DC:4462–4491,4543–4604 | slowdown/safe-chain所有SW/nextSW/prefix位/裸safe记录 | 记录producer意图与bitmap，可用于后续查证；本次未运行 |
| `lsu/PackageAddressStats.scala`:17,101,194,251,560,584,604,928–930 | event捕获SW、processedSW/queue退休；`packetSeq<eventSW`、队头SW比较、idle一致性 | 模块注释限定统计；不向功能门控反馈安全授权。回滚后有效历史语义需独立解释 |
| `guardiancouncil/BarrierLatencyStats.scala`:35,60,76 | bucket.seq `<=SW`；eventImmediate `<=SW` | 统计safe前缀覆盖时间；无EVT，不是外传许可 |
| INC:360–365,422–433,447–477 | debug Gray/binary，WB.seq `>SW`/`<=SW`、bucket退休、L2DramBarrierStats | 回滚dead区间与验证延迟要分开；观测不能倒灌功能结论 |
| `lsu/DirtyWritebackBitmap.scala`:30,70；`DirtyWritebackBucket.scala`:8 | 类型/规则注释 | 实际功能更新在DC；注释“所有之前均PASS”需按有效历史解释，不把注释当额外硬件gate |
| `GH_GlobalParams.scala`:165 | Boring名称常量 | 单Main SW命名；没有多生产Main路由 |

未见以 `Seq==SW` 单独授权功能效果的比较；源码中的相等多为processed SW、baseline/debug一致性。`seq==0` 是可信编码特例，必须与 `seq==SW` 区分。`VersionValid/VersionSafe/NeededForRollback/CanWriteback/CanReclaim` 并非当前统一RTL接口，见10给出的语义定义，不能从名字搜索未命中直接宣告功能不存在。

### 3.4 dead Seq 反例及实际gate的条件证明

`PAPER`反例：EVT丢弃8–10，旧K9仍物理存在；7已PASS，新11已PASS，数值frontier最终11。`9<=11`为true，但`HistoryValid(9)=false`，因此K9既不可恢复也不可携带数据外写。这**证明裸比较不充分**，不是证明当前已经外写K9。

`RTL`对K9代入当前关键路径：

1. REC:125返回false；DC:655及HIST:43对tombstone9也返回false。bitmap:2822拒收旧PASS9，:2928清其项。
2. SVB:124候选必须historyValid，K9不参加；HIST:102必须query.survives，K9不参加；DC:830–858的Current验证失败，不能通过普通mapped命中。
3. HIST:124的safe=false，不会新选publisher；捕获dead版本在:78–99可以确认接收但不存储，允许旧owner协议终结。
4. SCH:124的historySafe=false；外C如果仍须释放coherence，:490–495变无数据Release；SC实际带数据beat有完整断言。native peer重新查目录、park/重放，不把dead的covered当最终许可。
5. L2P:108即使bare safe=true，`!survives`也使archiveMode=true，不走新的DRAM数据Put。已经接受的safe事务依赖不变量`FAIL target>SW`，故合法rollback不会把其版本变dead；不能在后续设计中撤销这一前提。

**结论 — RTL/待证**：对稳定且一致的EVT/SW、已分配合法key，上述已读gate排除K9，未发现“仅因为9<=SW”直接获恢复/外写授权的这条局部路径。**不能给出现代码全部并发/CDC/reset路径无误的无条件证明**：灰码源为组合逻辑、HistoryQuery不传tail、L2既调度事务及各候选转移覆盖尚缺证明。用静态代入冒充全RTL证明会违反本轮证据标准。D01/D03/D07/D09/D11保留待决策/待证。

## 4. CP / History / Baseline 责任审查

`PAPER`（p4 IV-D）：Needed(v)取决于某个outstandingCP是否把v作为该地址的最新有效值；检查完成、CP退休、数据副本释放是三个不同事件。`RTL`没有精确CP引用表不自动构成错，保守保留超集可合法。

| 位置 | RTL实际释放/覆盖条件 | 审查 |
|---|---|---|
| REC:71–79 / CORE:2099 | CP.seq<=SW或restart丢弃suffix；read/pin优先 | 保守等连续safe覆盖，支持T02/T04；目标pin保持。旧更早CP不因Epoch变化清空 |
| LP:73–81 / DC:2045,3392 | 同段复用，或old covered且lowerPreserved；普通unsafe capture用SVB lease | 不精确算Needed；对safe必要前驱，精确lower copy仍需可检索且不被下层误收。trusted incoming0例外须恢复floor |
| SVB:317–365 | coalesce恒false；SPEC只错误suffix/flush删，当前DC.flush=false；WB_WAIT exact entry/key ACK | 原00–04中“FAIL8按SW6删A7”已不再成立，DC:2884用failedSeq−1。WB_WAIT死版本也保留协议责任直到receipt |
| DC:699–728 / INC:198–210 | 四相archive；L2 capture.fire才ACK；L1收到exactkey后free | 正确区分保存责任与DRAM安全。移动中源必须可查；查response拷贝也可承担稳定数据责任 |
| HIST:78–99,102–123 | dead可确认后drop；活版本入空槽/同key去重；query拷贝held data | 去重须同地址同key的数据相等且现副本未过早free；无same-key字节相等断言/全域证明。query不是CP引用退休事件 |
| HIST:124–144 / L2P:187–204 | safe发布，完整外存AccessAck匹配后删 | 真ACK是必要条件；还须防新baseline被其他旧safe事务覆盖，以及candidate旧残影返回。原P3-10阻塞仍合理 |
| SCH:156–185 | authored incomingC整行staging→RAM；pending/当前C阻止query | 覆盖部分迁移窗口；不能仅凭这两条gate证明所有resident/preservation/read途中的版本都被枚举 |

`DESIGN_DECISION D06/D07`：推荐先保持现有保守保存结构，建立全地址CP predecessor与精确副本owner不变量，再决定是否增加精确Needed索引。不得将所有unsafe永久保留当最终解；也不得将所有safe立即delete当优化。

**baseline反例模板（条件风险，未证明整机可达）**：若A的K7已成功写DRAM且旧K6的精确副本随后从另一路capture进入history，HIST:90只检查当前RAM去重，:128只选当前最老safe，缺“该地址已发布K7”的持久记录，会允许K6随后Put并收到正确ACK。ACK身份全部正确，DRAM仍可能倒退。若已发布K7的sidecar已free而旧K6残留，query还会把K6作为最大可见缓存候选覆盖普通refill的更新值。SCH:386阻SourceC直到publisher清空只约束当时队列，不能独自排除此模板的迟到入口。需证明该模板在现有coherence/迁移下不可达，或实现全入口obsolete suppression；不能直接称已观测数据损坏。

## 5. 七类身份、复用、耗尽及前进

`PAPER`要求不误配版本/事务、Seq永不复用和正常前进；位宽、是否循环复用、reset/fatal策略为`DESIGN_DECISION`。所有“可再初始化”都是待审方案，不是当前RTL已有能力。

| 身份 | RTL宽度/作用域，分配与释放 | 迟到响应 / 允许复用条件 | 正常耗尽及当前保护 | Drain / Reinitialize 评估 |
|---|---|---|---|---|
| Seq | IC:135每Main32位；:279新段counter+1；slot release不释放Seq；0保留 | 完整Seq-tag+bitmap挡旧结果；永不复用是PAPER约束 | 无故障执行也可到2^32−1；:136汇报fatal，:239禁新snapshot；REC failed | 普通drain不允许归零；全新恢复域incarnation需全部旧历史/外部引用隔离，并改变全局身份 |
| Epoch | REC:104每Main32位；rollback.fire递增；无回收 | key不显式带Epoch，Seq/EVT推导；旧epoch仍可有效 | 仅rollback增加；32bit满拒commit并failed；32个disjoint EVT容量可能更早耗尽 | 合并/压缩区间可以，删除tombstone须证明再无旧Seq引用；不是等TL空就安全 |
| CurGen / G | REC:105/143 G32；DC:794 per-slotCurGen32；rollback增G，安装/提升写CurGen | 旧CurGen不能等于新G复活旧mapping；与事务ID不同 | 仅rollback耗尽，guard同Epoch | 需清/重标所有旧mapping或更大incarnation；这可能改变论文无全cache扫描的恢复目标，不能无代价重置 |
| Slot Epoch | DC:767每set/way16位；newowner安装、probe invalidate、recovery/legacy clear推进；:770饱和 | slot/tag+MSHR txn+key共同匹配；不可只slot值匹配。饱和后primary的epoch0候选被LM:982拒绝 | **正常replacement/probe即可耗尽**；任意一个槽andR即DC:949全局failed；命中/空闲不回收计数 | 比执行Seq更适合局部drain后复用，但必须无reservation、install、replay、S1/S2/S3、completion、WB/prober持该槽旧ID，并另有防迟到机制；仅fence_rdy不足 |
| MSHR Transaction ID | LM:143每L1 MSHR32位；:165 next；:389 primary锁存；owner terminal后MSHR复用但serial不退 | DC:1704–1770匹配MSHR编号+txn+slot/tag/key；外TL grant通常只按source，依赖TL终态后source才复用 | 正常primary/upgrade分配到最大；:418禁新primary并报fatal；busy与ready已分离 | 可以研究某MSHR完全drain后新incarnation；当前没有协议，不能只清transactionSerial；任意重复旧TL D需额外fault model |
| Preserve / WB Transaction ID | L2P:62全engine64位，每candidate/history capture递增；L2M:154每MSHR64位，:899每plan递增（不止实际WB）；L1voluntaryWB实际ACK见DC:1893–1898 | L2匹配source/echo/size/fullsent，L2M:807–828精确serial；L1WB用key+source+size+sent，未独立区分同key的两次WB | L2任一serial全1禁capture/allocate/reload并经INC→DC→CORE fatal；64位寿命长但有限。L1WB没有单独per-WB计数器可审 | L2可在所有adapter/ACK/queue排空后研究incarnation；L1同key第二次WB遇任意重复旧ACK可误匹配，需D11决定TL恰好一次模型或增加事务echo，不能声称现逻辑已防任意重复 |
| LSU Token | LSU:402 strict64；:508 functional64但limit2^63−1；maxBatch=coreWidth/coreWidth+1，HIST:18–26整组预留；dispatch/Hella、commit分别consume；terminal释放owner不回收数字 | SDQ/LSQ terminal逐token核对，LM:1090等；rollbackReset/traffic RESET均不重置allocator | 正常请求/Store均增长；不足完整批量即不再分配、CORE failed；尾部有未用空间也停止，属保守策略 | 局部drain后复用需包含LSQ、SDQ/RPQ/MSHR、completion、replay effect去重表、Hella以及所有延迟通知；当前没有该再初始化 |

另有内容身份 `CacheImage.generation/imageSerial32`，不能漏在上述七类之外：DC:942,3396,3635–3662每次实际semantic write增加，非仅新段；一次段内重复Store也耗serial。到全1即gate实际效果并fatal。旧key可能仍在SVB、L2、WB、DRAM基线关联中，普通drain不允许归零。若计入VERSION身份，必须与MSHR/slot/G分开审查。

### 5.1 可达寿命，而非“太大不会发生”

`RTL`只给事件预算；时间取决于实际事件率，以下均为**说明性假设，未测频率/性能**：`T=剩余可分配数 / 该scope事件率`。饱和guard、初值和整批预留使可用数略小于2^w。

| 预算 | 假设事件率 | 数量级 |
|---|---|---|
| 最热点Slot16：至多约65535次slot incarnation变化 | 1000次/s；10^6次/s | 约65.5s；65.5ms（若每替换多次推进，寿命更短） |
| 全L1 imageSerial32：约2^32次实际写 | 10^6次/s；10^8次/s | 约71.6min；42.9s |
| 单MSHR txn32：约2^32次primary | 10^6次/s / 该MSHR | 约71.6min |
| Seq32：约2^32段 | 1000段/s | 约49.7天；不能用指令频率直接代段率 |
| functional低63位；strict/L2 serial64 | 10^9次/s / 各scope | 约292年；约584年（长但非无限） |
| EVT32项 | 每次rollback新增不相交dead区间 | 最多32项，第33次不能合并时停止；与时钟频率无关 |

**RTL/CONFLICT**：REC:203–207的failed没有退出路径，fatal会禁止同拍restart并保留pin；这是fail-stop，不是drain再用、更不是forward progress。`identityUnavailable`来自任一热点资源即全核停止，也会在无错误时触发，未必存在可供恢复的pin。硬reset虽能清寄存器，却可能丢unsafe历史/CP，不能称正确恢复。保护可保留；原“B-IDENTITY解除”只限不回绕源码保护，不应扩张为D04寿命/活性问题已解决。

## 6. 八个场景的实际路径静态推演

每个场景的“第一个潜在错误点”指第一个尚无闭合证明的分叉；没有把它冒充已发生的动态错误。T编号是本轮语义场景，勿与04/08的旧测试编号混同。

### T01：SW6 / Pending7=A7 / FAIL8=A8

**初始**：DRAM[A]=A1；SCP7/SCP8可用；A7整行已在SVB或L2 archive，A8为L1Current，7Pending，SW6。

**PAPER**：恢复SCP8；8及后缀失效，7有效；读A7，即使7未验证；A7/A8均不得在此时数据外写。

**RTL事件链**：DC:2822–2846接FAIL8，:2854–2875选最早并保持error；:2884发cutoff7，SVB:350–356只删SPEC Seq>7。CORE:2094→REC:173–195 lookup/pin SCP8→commit EVT；REC:133–143丢8..tail并增Epoch/G。DC:898–919先同步新EVT到L2/Checker；CHK:1516suffix走原cancel/release；DC:4752–4763及CORE:2105 join后restore/restart。新访问A在DC:830不再mapped；SVB:124或HIST:102选A7，DC:860–884归并。若旧A8resident存在，DC:1030–1062先真Release/ACK/clear，再普通AcquireT/LM:177–187,576安装A7。IC counter不退，新段用旧tail+1。

**局部判定**：FAIL cutoff7和两个查询谓词明确保留Pending A7；L2外写gate的survives+SW使A8不能以dead covered通过，A7>SW不能Put。旧审计的“FAIL8立即删A7”不适用当前源码。

**首个潜在错误点**：前置“A7所有字节已被保留且查询可见”尚无全域证明；若只有断续迁移owner而query漏掉，后续可能fallback A1。ready/restart/CDC及permission交错仍待证，不能宣布T01已通过。**DESIGN_DECISION**：D05/D06/D07/D09/D11。

### T02：乱序PASS8 / Pending7 / SW6

**初始/事件**：7Pending，8已分配、checker完整PASS8经GHM事件到DC，尚无rollback。

**PAPER**：8Verified但unsafe；SW6；8的LSL输入可释放，8产生的历史/Current仍按Needed保留。

**RTL**：DC:2842将slot8 completed/passed；:2893从7检查，7不是PASS则safeAdvance=0，discardedNext=false，newSW6。REC:73不退休SCP8（保守合法）；LSL:215已消费输入及CHK result/release不等SW。HIST:124不会发布K8；SVB迁移却可发生，因为:213不要求safe。

**首个潜在错误点**：没有发现本例局部Verified→Safe的合并；入口必须是完整PASS8而非仅ARF done，CHK:1535来自full_check_complete。LSL物理FIFO可在检查消费时逐项free，比论文允许的验证后释放更早，前提是不再需要该输入；它不是恢复历史。**DESIGN_DECISION**：D01/D02/D05；不能用释放LSL去释放CP/history。

### T03：跳过废弃8–10，新执行11

**初始**：1–7PASS、SW7，8–10被EVT废弃，tail10；物理K9仍可能留在WB/staging；随后allocate11并PASS。

**PAPER**：有效前缀经dead空洞接到11；K9永不成为有效/safe候选。

**RTL**：DC historySync先冻结SW；EVT发布完成后:2900逐拍7→8→9→10，即使11尚Pending；11PASS后→11。这是数值frontier编码，不是说8/9/10已验证。K9裸KEY.safe=true，但HIST/SVB的survives=false；SCH去数据化dead release，L2P archive而非Put，详3.4代入证明。旧PASS9被DC:2822丢弃。

**首个潜在错误点**：消费者若只用裸helper就不充分，当前LP的本地reuse及诊断确实裸用，外写须依赖下一层完整gate。全链首要待证是新SW跨dead时所有外写域已有兼容EVT、无reset撕裂；不能给出无条件全RTL安全证明。**DESIGN_DECISION**：D01/D03/D09；必须保留Valid过滤，不能将helper的valid字段解释成EVT.Valid。

### T04：FAIL8恢复后，更早FAIL7

**初始**：SW6、7Pending；首次tail10；第一次FAIL8后e0有效1–7、dead8–10；e1新11/12执行，SCP7应仍存在。

**事件/PAPER**：晚到有效FAIL7需恢复SCP7，丢弃7以及新11/12；新e2从13或更大Seq继续；A在SCP7之前的前驱必须仍可查。

**RTL**：REC:73因7>SW保留CP7，首次restart discard>=8不删它。FAIL7在DC:2822仍非stale，Controller idle或恢复中earlier=true，REC:179/199 abort/relookup；REC:109与133把原8–10合并进7..tail12（同时作废新epoch后缀）。Epoch/G再增，IC allocator不退。Pending A7若在SVB SPEC被cutoff6删是正确，因为此次7本身失败；需恢复更早的A值。

**首个潜在错误点**：SCP7可定位的局部逻辑成立；全地址SCP7前驱保留及曾safe的DRAM基线顺序未证。若7在第一次恢复期间PASS使SW跨7，则以后FAIL7将被当stale；这是“PASS不可撤销”的故障模型，而不是支持后来撤销PASS。恢复中途更早错误与已发history/query/ACK仍需协调。**DESIGN_DECISION**：D02/D05/D06/D11。

### T05：A7在SVB或L2，A8在L1

**初始**：SW6、7Pending；A7完整data分布在SVB SPEC/WB_WAIT、L2 RAM或archive迁移owner；DRAM A1；A8将被废弃。

**PAPER事件**：query必须收齐相关候选、选A7；保存/查询receipt不是DRAM安全许可；不得因L1 miss使用A1。

**RTL**：DC:699–728锁archive payload/entry；INC:200–210等RAM capture.fire才receipt，SVB:281–344收到exactkey后free。query SVB:124同时含WB_WAIT；INC:220–240送L2 query，SCH:181–185要求staged C完成/无当前C，HIST held response包含publisher wbIdx。DC:863等全部bankACK与SVBresponse再比较。旧A8经过真Release/ACK/clear，LM正常获得T权限，再用recoveredLbResp返回/装A7整行，绑定新G；Promote不删除A7其他副本的保留责任。

**首个潜在错误点**：历史RAM查询不直接读取L2普通resident/正在preservation读取的bank；需要证明这些位置的唯一最新值总已在查询集合或普通coherent fallback可正确补齐，且found旧候选不遮蔽更新的resident/baseline。仅staging barrier不能独自证明。**DESIGN_DECISION**：D06/D07/D09/D11；P3-06/07是局部口准备，不是跨域选择证明。

### T06：rollback与writeback并发

**初始**：SW6，安全K6的outerPut/Release已开始，ACK延迟；另有A7Pending和A8dead候选；可能仍有更旧K5的片上副本。

**PAPER**：K6可完成；旧ACK仅清K6原owner；K5不能随后覆盖更新K6；A8不因新SW跳洞外写。已接受多拍包不能中途截断。

**RTL**：L2P:187–215匹配source/size/64bit echo、全行sent、无denied/corrupt；HIST:141–144等原key成功才free。L2M:807–840匹配releaseGeneration并保持releaseSnapshot。SVB WB_WAIT不因invalidate删；dead包到L2可协议接收后drop。SCH:386阻普通SourceC越过pending publisher/staging；SC:181重检beat。CORE允许已隔离的L2owner在后台保留，并未直接清它。

**首个潜在错误点**：exactACK并不能证明K5/K6全入口顺序；4节的迟到旧safe模板仍开放。另一个具体匹配边界：L1相同immutable key先后两次WB时，任意重复第一笔ACK落在第二笔sent后，可满足DC:1895；当前TL恰好一次模型下不构成合法晚到响应，但如P5-09宣称防任意重复则不足。**DESIGN_DECISION**：D07/D11；区分合法迟到、重复注入、跨reset孤儿响应。

### T07：部分Store及相邻字节

**初始**：64字节line `L0[i]=i (0<=i<64)`，已有前驱K6对应整行L0。Seq7在offset10写16-bit小端值0xBBAA，mask为line bits10/11；得到L7[10]=AA、[11]=BB，其余L7[i]=i。SCP8对应L7；Seq8在offset11写byte CC，得到L8[11]=CC。

**PAPER**：第一次跨段Store保留完整L7；FAIL8后恢复line应为L7，不能只恢复byte11；相邻word offset16..23仍等原图案。Pending Seq7仍可选。

**RTL**：DC:3294–3300用StoreGen字节mask驱动AMOALU将旧word与新数据合成，再:3465用word mask写row；snapshot由DC:1884–1889将完整refillCycles行送SVB，SVB:288–297保存所有row。HIST.data为512位；LM:179/576恢复每row，DC:3611–3628末row提交key/G/receipt。

**首个潜在错误点**：独立SVB保存/恢复full-line方向正确；实际snapshot各row的时间一致性须由freeze/owner保证，真实masked-store的AMOALU输出、row/word选择、fastlease对齐尚未经验证。现fixture相邻字检查不能替代所有byte mask/AMO/SC路径。**DESIGN_DECISION**：D06/D10；保留原StoreGen/整行存储，下一轮验证按明确字节oracle，不要改成只存changed bytes。

### T08：容量或身份耗尽

**初始A**：SVB16近满、L2history64满，当前段还有ROB/LSQ memory操作，最老history属于当前未封段；Checker需ECP才可完成。**初始B**：热点slotEpoch=0xfffe，或imageSerial/MSHR serial接近全1；无故障正常访问持续。

**PAPER**：正确backpressure、earlyclose/dispatch、pendingcoherence优先，资源释放后可继续；不能覆盖Needed数据换取进展。

**RTL链A**：DC:940在14项发close，但仅留2个SVB槽；CORE:2350仅预留指令数，不证明剩余Store/eviction/history需要<=2；SCH:398用最老Seq请求验证。若load miss或preserve等history可用，ROB不能empty；ECP不能形成，PASS/SW不增，history不能发布，形成结构性等待环。不是当前已运行死锁，缺可达配置/credit证明。MMIO循环则见LM:1121与CORE:2331的直接依赖。

**RTL链B**：slot下一次incarnation到ffff即DC:949 fatal；imageSerial每actualStore增加，32bit满也fatal；LSU整批available不足提前阻新分配；REC:207优先于resume让failed永久保持，停止而不wrap。REC:116/206对EVT容量满同样终态。后台owner不被主动清空，但failed不保证全部已接收事务最终能drain。

**首个潜在错误点**：A为资源准入时未预留封口/恢复必需headroom；B为正常运行寿命预算耗尽，没有返回执行的协议。**CONFLICT**：将stop终态当正常forward progress。**DESIGN_DECISION**：D04/D12/D13；不能删guard或只加大RAM来替代契约。

## 7. 原30个 CODE_READY 的逐项语义复核

以下是**附加审查意见，不改05的status、static_checks、verification或旧证据**。30项仍CODE_READY，0项获本轮VERIFIED。文档类任务不需硬件编译来证明“文件存在”，但其语义内容仍可被本轮补充。

| Task ID | 原任务/当前可保留内容（RTL或文档证据） | 本轮语义意见 / DESIGN_DECISION |
|---|---|---|
| P0-01 | 阅读论文/审计，00–04/06 | 保留材料；新规范优先采用论文原文，不能沿用实施前“无EVT”作为当前事实 |
| P0-02 | Git/RTL基线，05/07/09 | 保留历史；同HEAD含不同dirty workspace，需本轮hash边界 |
| P0-03 | 49功能映射，05.features | ID齐全可保留；混合单/多Main语义在8节拆分 |
| P0-04 | 47InScope、2Deferred | 分类太粗；C5/D17的多Main子项Deferred合理，native peer隔离不能整个随之取消 |
| P0-05 | 源码/端口定位，06/07 | 保留定位历史，本报告字典与SW清单为当前行号 |
| P0-06 | 恢复接口契约，06 | **有语义补充**：裸safe、baseline、MMIO、identity终态不能等价于论文要求；以10/12补充待决策 |
| P0-07 | 69任务依赖，05 | 保留结构；D04/07/12/13须在后续实施前确认；不重写原DAG/evidence |
| P1-01 | f0/x0比较，CMP:482–512 | 可保留，f0真实入比较；PC/FCSR/所有状态覆盖不能由该fix推出；未运行 |
| P1-04 | FAIL8 cutoff7，DC:2884/SVB:350 | 局部修复成立，可保留；不等于所有CP的history保留闭合 |
| P1-10 | LSL与CP/history分离，CHK:1534/LSL:215，独立RAM | 局部结构成立，可保留；不要将独立释放视为SCP或版本整体正确 |
| P2-01 | held error `{seq,cancelled}`，REC:6/DC:2865 | 可保留；D02的取消原因/故障模型未决，接口表达较窄 |
| P2-02 | Controller，REC:173–211 | 顺序可保留；**完成范围需收窄**：MMIO/容量、固定拍restore和隔离未证，不是全恢复就绪 |
| P2-03 | SCP RAM16/pin/reclaim，REC:26–79 | 保守SW退休没有直接论文矛盾；D05捕获边界/容量/完整状态及全地址Needed不变量未证 |
| P2-04 | 完整Seq查SCP/error target，REC:46–68/CORE:2097 | 可保留；missing→failed是诊断终态，不算成功rollback |
| P2-11 | 最早有效错误、earlier重选，DC:2853–2875/REC:176–202 | 局部可保留；D02 PASS不可撤销、D11恢复中旧事务/更早FAIL交错待证 |
| P3-01 | 32bit Epoch，REC:104/142 | 递增语义可保留；finite fatal不是连续任意rollback前进 |
| P3-02 | EVT dead intervals，REC:109–144/HIST:43 | 编码可保留；**需补契约**：tail完整性、32项回收、全消费者发布和reset，D03/D09 |
| P3-03 | fresh Seq，IC:279–289/505 | 不复用方向成立，可保留；D04寿命决定未解，不能仅“禁wrap”就称完整运行支持 |
| P3-06 | SVB addressed held query，SVB:124–148 | 查询函数局部符合LatestSurviving且允许Pending；完整跨层域是P3-08/09，不在该CODE_READY内 |
| P3-07 | L2 sidecar query，HIST:102–123/SCH:181 | RAM内最大surviving选择可保留；**范围收窄**：不是全部L2 resident/迁移owner已完整查遍 |
| P3-15 | identity guards，DC:949/LSU:508/REC:207 | **语义问题优先**：安全停机与寿命/forward progress不同；16位slot正常可达耗尽，D04/D11仍未解 |
| P4-06 | identity不复用/terminal匹配，L2P:187/L2M:807/DC:1895 | 保留防alias保护；**不能声称全ACK抗混配**：L1同key重传无独立WB ID，fault model待D11；无安全reinit |
| P5-02 | SW/Preserve/Reclaim组件源码，RecoveryGenerate/recovery_test/svb_test | 已写用例可保留；缺全局baseline/CP oracle与实际SW生产路径覆盖，不能用组件输入SW证明producer |
| P5-03 | SCP save/restore组件源码 | 可保留RAM测试；没有真实BOOM PRF/rename/CSR的全状态恢复证明，D05/D10 |
| P5-05 | Figure4组件+真实cache层次，HierarchyGenerate:67起/hierarchy_test:120起 | 可保留；host注入checker-result，未含BOOM pipeline/真实比较CDC全链；无运行证据 |
| P5-06 | 真实L1+L2+CacheCork层次fixture | 可保留；迁移重叠和accepted miss三个子例不穷尽T05/T06候选域与WB/probe并发 |
| P5-07 | 重复/更早错误组件用例，recovery_test | 可保留；不等于T04真缓存多epoch架构恢复正确 |
| P5-09 | late ACK/identity组件用例，svb/recovery/identity_test | **覆盖解释需收窄**：archive exactkey/identity fatal不同于真实outer adapter迟到重复ACK；D11模型未决 |
| P5-12 | 人工build/run/provenance，08/user_build.sh | 保留命令；本轮不执行，不能由命令存在宣布编译可过 |
| P5-13 | 预期与故障定位，08/09 | 保留证据；本轮10–12补语义边界，未填写Actual Result或改变任务状态 |

## 8. 原49功能的单Main范围复审

保留原A1–E7 ID及47InScope/2Deferred历史记录。以下`.S/.M`只是同一原ID的子要求，**不新增任务ID、不改功能数量或旧分类**。S=本轮单Main系统必须审；M=仅多BOOM Main扩展，Deferred。已有含多核参数/字段不要求删除，禁止将兼容性重构带进本轮。

| 原ID | 原范围 | 单Main保留子要求（PAPER约束，DESIGN_DECISION分解） | 多Main专用子要求 / 审查结论 |
|---|---|---|---|
| A1 | InScope | Main与四RocketChecker通信、CDC、ownership | M：多Main分派/结果归属Deferred；保留原单组接口 |
| A2 | InScope | 单生产者分段、close、dispatch、seal | M：跨Main调度公平/路由Deferred |
| A3 | InScope | 本Main Seq唯一、传播、restart不复用 | M：多个独立Seq命名空间Deferred |
| A4 | InScope | 本Main全部可回滚SCP保存/恢复 | M：每Main CP目录及共享Context仲裁Deferred |
| A5 | InScope | 本组完整结果、乱序/重复/error接收 | M：按producing Main路由Deferred |
| A6 | InScope | 单SW、有效历史连续PASS/跳洞、CDC | M：writer选择对应SW数组Deferred |
| A7 | InScope | Checker LSL检查输入独立释放 | M：多个Main输入stream仲裁Deferred |
| B1 | InScope | 内容身份、单Main EVT/G/slot区分 | M：多个生产Main历史标签选择Deferred；已有writer保留 |
| B2 | InScope | 同址Current/多个历史跨层可检索 | M：多个Main同址历史互隔Deferred |
| B3 | InScope | 唯一Current、历史不普通命中 | M：不同Main独立映射Deferred |
| B4 | InScope | 跨段继承全行及Needed前驱保存 | M：跨生产Main所有权切换建版本Deferred |
| B5 | InScope | 同段重复Store及mask/AMO语义 | 无需新增多Main机制 |
| B6 | InScope | 单恢复域L1/SVB/L2迁移及查询闭包 | M：多Main迁移归属/隔离Deferred |
| B7 | InScope | Needed副本preserve-before-reuse | M：共享way的多Main引用选择Deferred |
| B8 | InScope | 精确ACK/owner/事务与保留责任 | M：跨Main响应路由Deferred；单MainlateACK仍必须 |
| B9 | InScope | CP/EVT保留、latest-safe baseline不丢 | M：各Main独立回收域Deferred |
| B10 | InScope | 单Main容量/替换/recovery headroom | M：多个Main资源quota/公平Deferred |
| C1 | InScope | 本Main Valid且covered判断Safe | M：按producer选择EVT/SW Deferred |
| C2 | InScope | 外写受本Main有效SW约束 | M：多SW arbitration Deferred |
| C3 | InScope | unsafe内部L1→L2允许、历史可达 | M：迁移不能变他Main可见Deferred |
| C4 | InScope | LLC→DRAM所有A/C数据实际gate | M：多个Main各自提交边界Deferred |
| C5 | Deferred | S：外部nativeRocket/DMA不能获unsafe数据/权限，仍由C6/C4任务覆盖 | M：两个BOOM Main之间producing-history可见性Deferred；不能将S连带豁免 |
| C6 | InScope | S：nativeRocket/Checker管理访问/DMA coherence、pending优先、E责任 | M：第二Main image-aware请求者比较writer并转移恢复责任Deferred；原项是混合范围 |
| C7 | InScope | 本Main MMIO/uncacheable/nonrepeatable屏障 | M：多个Main device ordering Deferred；不影响单Main必须修 |
| C8 | InScope | 所有同址safe baseline次序、obsolete suppression | M：多生产Main交错外写顺序Deferred；单Main仍必需 |
| D1 | InScope | 本组检错覆盖/f0/结果类别 | M：多Main错误归属Deferred |
| D2 | InScope | 一个恢复Controller及停止边界 | M：每Main并行独立controller Deferred |
| D3 | InScope | FAIL n定位本Main SCP n | M：Main ID→CP目录Deferred |
| D4 | InScope | 本BOOM PC/int/FP/CSR/priv恢复 | M：多Main恢复状态互不破坏Deferred |
| D5 | InScope | 本Main流水线/LSQ取消与restart | M：不flush别的Main Deferred |
| D6 | InScope | 当前有效历史failed suffix失效 | M：按Main选择suffix Deferred |
| D7 | InScope | 本Main Epoch/EVT跨阶段保留 | M：多套独立EVT Deferred |
| D8 | InScope | fresh Seq/跨epoch有效历史/结果过滤 | M：多个Seq域Deferred |
| D9 | InScope | 本Main G/CurGen、逻辑映射 | M：各Main G独立Deferred |
| D10 | InScope | G推进后所有旧映射lazy失效 | M：只失效目标Main Deferred |
| D11 | InScope | 本域LatestSurviving，允许Pending | M：多生产者候选EVT分派Deferred |
| D12 | InScope | 无合格cache值且DRAM正确才baseline | M：多Main baseline ownership Deferred |
| D13 | InScope | selected内容提升Current及权限 | M：跨Main恢复映射Deferred |
| D14 | InScope | 本Main真实跨层按需恢复 | M：其他Main候选路由Deferred |
| D15 | InScope | 所有本Mainaccepted请求/lateACK结算 | M：保留别的Main在途owner Deferred |
| D16 | InScope | arch/history/transaction共同完成后restart | M：多个Main独立完成条件Deferred |
| D17 | Deferred | S：本Main与nativepeer隔离义务归C6/D15；不新增多Main恢复 | M：多BOOM独立rollback/coherence整体Deferred，分类合理 |
| E1 | InScope | 本Mainpreserve/WB/nativecoherence解除 | M：多Main互等/仲裁Deferred |
| E2 | InScope | 当前段正确earlyclose并dispatch | M：将close路由producing Main Deferred |
| E3 | InScope | 本Main及共享链backpressure责任守恒 | M：跨Main公平Deferred |
| E4 | InScope | boundedhistory/CP/EVT/identity耗尽策略 | M：多Mainquota Deferred |
| E5 | InScope | 单Main与Checker/nativepeer死锁避免、timer行布局边界 | M：多BOOM同步false sharing场景Deferred；单Main所用Rocket timer访问仍在S范围 |
| E6 | InScope | 本Mainrollback与正常WB/probe并发 | M：另一Main持续WB同时恢复Deferred |
| E7 | InScope | 单Mainoracle、身份/恢复/资源属性与证据 | M：双BOOM验证Deferred；已有旧多核材料不能算S验证 |

`DESIGN_DECISION`结论：原表没有遗漏原ID，但仅“47/2”不足以证明排除了全部多Main子要求。本轮按上表分解，C6、C8、B1/B6/B9、A1/A3/A5/A6、D7/D15、E1/E5等只承接S部分。C5/D17继续保留原Deferred历史，不把nativeRocket/DMA隔离漏掉，也不要求删除已有通用writer/owner字段。

## 9. 七个结论与保留/修正边界

1. **现SW是否一致？** `PAPER/RTL`：单步有效前缀、乱序PASS不越Pending、跳dead算法方向一致；数值SW可覆盖dead编码不违背论文。`待证`：全部消费者、发布/复位/CDC与分配窗口未闭合，故不能答“整体已一致”。
2. **Safe/Verified/Valid/Needed是否混用？** `RTL`：bitmap与EVT、query与safe publish已分开；未见给LatestSurviving加Verified门。`CONFLICT`：裸safe helper不是完整Safe，key.valid不是EVT.Valid；preservation使用的保守covered/receipt规则不等于Needed的精确计算。将这些等同的契约解释必须改，不能把所有裸本地gate一律判成外写漏洞。
3. **历史回收足以正确rollback？** `PAPER/RTL`：FAIL8保留A7、WB_WAIT保留到exactreceipt及L2等真ACK是正确基础；`待证`：全CP predecessor、候选闭包和latest-safe baseline不倒退尚不足，不能认定足够。
4. **EVT/LatestSurviving有偏差？** `RTL`：dead区间补集、隐式Epoch和最大surviving Seq/serial可满足论文，Pending A7选择正确；`待证`：tail定义不统一、有限EVT无回收、全层候选域/跨query的上下文协调。sidecar布局差异不是自动语义错误。
5. **永久停止是否只是fail-stop？** 是。`RTL`：failed不可退出，16位slot/32位内容serial等可在正常运行耗尽。`CONFLICT`：把它当正常forward progress或“身份问题全部完成”不成立；保留保护并决定寿命/再初始化。
6. **最急需决定？** `DESIGN_DECISION`：SW编码/CDC；CP lifecycle与history保留证明；baseline全入口次序；身份寿命/故障模型；MMIO pre-I/O/replay/floor；close/drain资源预留。12中未确认项保持pending。
7. **哪些RTL须修、哪些可留？** `RTL`可保留：freshSeq、bitmap独立于EVT、failedSeq−1、SCP完整Seq pin、Pending查询/全行archive、内容身份与G/slot分离、exact终态/不回绕guard及正常coherence责任。`CONFLICT/待补实现`：当前通用MMIO进展、capacity/headroom及身份寿命不能满足完整运行目标；baseline/候选域/CDC/restore/lateowner证明未闭合者必须补完或按证明结果修正，不能把尚未证明的具体数据丢失路径虚构为已确认bug。

## 10. 高优先级修正清单（9项，下一轮须先审决策）

这里是建议和待审验收条件，本轮不实施、不改任务状态。

| 优先项 | 类型 / 必要修正 | 原Task ID | 具体RTL | 必须满足的语义 |
|---|---|---|---|---|
| F01 | DESIGN_DECISION D01/D03/D09：统一Valid/Safe定义与SW/EVT发布；补源端Gray/CDC/reset契约 | P0-06,P1-02,P3-02,P3-05,P4-05 | KEY:32、LP:70、DC:655/2822/2900/2920、INC:220/291、SCH:124 | T03 dead9永不读/外写；合法来源含tail；跨域不提前授权 |
| F02 | DESIGN_DECISION D05/D06：CP起点/退休与Needed副本不变量；精确或保守实现二选一后补闭包 | P1-03,P1-07,P1-09,P2-03,P3-13 | REC:26、CORE:2125、LP:73、SVB:281、HIST:95、SCH:156 | T01/T04每个liveCP每地址都有所需前驱；不得只用safe当删除许可 |
| F03 | DESIGN_DECISION D07：统一全部同址baseline外写次序/obsolete suppression与回退资格 | P1-08,P3-09,P3-10,P4-04,P4-08 | HIST:90/128/144、SCH:130/386、L2P:102/117/187、DC:885 | T06旧safe永不覆盖新baseline；noCandidate不跳过唯一在途值 |
| F04 | DESIGN_DECISION D04/D11：身份运行预算、局部drain/新incarnation与终态策略 | P3-15,P4-06,P4-12,P4-13 | IC:135、DC:767/942/949、LM:143、LSU:402/508、REC:203、L2M:154 | 保留不回绕；正常运行热点耗尽可恢复或有明确用户认可的运行边界；不能称fatal为进展 |
| F05 | CONFLICT / D12：pre-I/O封段及不可重复效果的重放/恢复floor | P4-09,P4-10,P4-11,P5-10 | LM:1119、CORE:2331、IC:239/252、LSU发射路径 | 消除MMIO等待环；验证preceding execution、外部效果恰好一次 |
| F06 | DESIGN_DECISION D13：按最坏资源需求预留close/drain/recovery credit，保障pendingcoherence优先 | P4-11,P4-12,P4-13,P5-10 | DC:940、CORE:2350、SCH:398/579、HIST:78、L2M:266 | T08满history仍可ECP/验证/恢复；不靠timeout成功或无限保留 |
| F07 | DESIGN_DECISION D06/D11：候选域、安装权限与旧请求/ACK逐类协调 | P3-08,P3-11,P3-12,P3-14,P4-01,P4-02,P4-05,P4-07 | DC:830/860/1030/1704/4752、LM:177/576、SCH:181/740、L2M:807 | T05/T06/T04存活Pending可选、无查询空窗，旧response不得复活Current |
| F08 | DESIGN_DECISION D10：共同架构/内存恢复边界、CSR/异步事件集合及真实restore完成证明 | P2-05,P2-06,P2-07,P2-08,P2-10,P4-10 | CORE:2114/2125/2467、CSR:2144；BOOM `exu/rename/rename-stage.scala`、`exu/rename/rename-maptable.scala`、`exu/rename/rename-freelist.scala`、`exu/rename/rename-busytable.scala`、`exu/register-read/regfile.scala`、`exu/fp-pipeline.scala`、`ifu/frontend.scala:874` | SCP段首、所有架构状态一致；固定拍done必须等价于实际写完成 |
| F09 | DESIGN_DECISION：补独立CP/byte/baseline oracle及真实全链覆盖；避免扩大CODE_READY含义 | P5-01,P5-02,P5-03,P5-04,P5-05,P5-06,P5-07,P5-08,P5-09,P5-10,P5-11 | 上述生产路径；配套AI/Debug/scripts/rollback fixtures | T01–T08、real checkerCDC、partialStore、lateWB/probe、连续rollback与容量身份寿命；由用户下一轮授权执行 |

## 11. 本轮材料检查与停止点

只新增10/11/12 Design文档；既有00–09、任务JSON、RTL、测试脚本和debug state保持原样。任务统计保持69：30 CODE_READY / 32 IN_PROGRESS / 7 BLOCKED / 0 VERIFIED；49原功能保留。仅检查文档链接/ID覆盖/文本一致性及受保护文件SHA256；这些是文档检查，不是硬件测试。没有执行构建、RTL生成、仿真、FI、用户build脚本或commit。

文档检查结果：原30个CODE_READY各有独立审查行，原49个功能ID各有范围复审行；T01–T08、F01–F09、D01–D14及C01–C11齐全，29个本地Markdown链接均可解析，任务引用、尾部换行和空白检查通过。61个受保护既有文件的SHA256与本轮审查前一致；其中包括00–09、任务JSON、相关dirty/untracked RTL、测试脚本和debug state。此检查不增加任何硬件完成证据。

本轮先冻结10中的论文约束，12的工程未决项供用户审阅；不自动继续RTL实现。
