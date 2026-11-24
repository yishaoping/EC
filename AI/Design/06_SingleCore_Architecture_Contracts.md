# 单主核 Rollback 架构契约

当前实现、握手、冻结边界和运行结果见 [SingleCore_RTL_Baseline](SingleCore_RTL_Baseline/RTL_Architecture.md)。下文保留各阶段的历史记录。最新任务授权执行编译、仿真和可用的综合检查。

## 2026-11-21 续作：上下文安装回执与维护完成边界

P2-09/P4-05：Rocket直接使用PalimpsestHistoryReceiver；payload同步3级、request同步8级，接收时一次安装EVT并置held ACK。Main同时等待所有L2 bank和hart1–4的ACK高，再撤request；所有ACK低后才完成本次mailbox。普通cold lookup也复用该协议；无Checker且不产生rollback的TraceGenerator在构造时显式关闭Checker回执端点，正式Main默认启用；ACK表示上下文安装，不表示Checker package PASS或资源释放。

P3-15：物理维护ACK返回后，重新汇合L1的rollbackQuiesced、SVB空、archive idle、allCheckersDrained，才发compact；增加物理resident为空的assertion。不能用CDC同步级数充当L1 owner完成延迟。compact后的空EVT也必须得到每个Checker安装回执后才restart。

P3-10：history的publishPending包含SW与上拍SW不同的当前拍，关闭寄存maybeSafe晚一拍的窗口。direct safe resident preservation候选等待已有history pending完成，unsafe archive仍可用escape信用；复用既有publisher/lock，不新增地址CAM。可信BASE/迟到C/SourceC全入口的完整次序仍是未完项。

P5-04：新组合夹具直接实例化R_RSUSL和完整GHM（包含生产result AsyncQueue及held release），连接生产SCP/EVT/Controller；不是在host里伪造FAIL。Rocket整包tail/cleanup和BOOM流水线未实例化，不能用此组件测试替代整核验证。所有测试未运行。

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

2026-11-21；依据论文 III、IV、Algorithm 1、Figure 3/4 和 00–04 基线审计。**源码实现未完成、未编译、未仿真。** 任务状态以 05 JSON 为准；以下已经接入的机制不能等同整核可运行。

## 本轮新增/替换的实际契约

- PRF 使用现有第 0 写口写 p0…p32，done 持续到 restore.valid 撤销；普通写回不可重叠。integer x0 映射 p0，x1…31 映射 p2…32；FP f0…31 映射 p1…32。Core 等 int/FP PRF、全部 rename owner、CSR done 与 ROB empty，SCP payload 保持 pin。
- 历史全行在 Mem 中，多周期单索引比较，不在普通 load hit 搜索历史。相同 Seq 的中间值不对应单独 SCP，可以合并；所有已 covered 的旧 safe 地址值只在更晚完整 safe 值可靠接手后合并；WB owner 到 exact ACK 前不复用。
- history 默认 64 项，escape 默认 4 项，来自同一 Mem。普通 SVB ingress 不可占这 4 项；保存读行开始前确认信用，读行/归档期间排他保留，待安装 ingress 也占信用。没有新独立 escape data RAM。
- 无信用的 unsafe victim 若尚未发外部 Release/Acquire，可在已发 inner Probe 全部完成后 park 原 A 到每 source 等待槽，提交已完成 Probe 的目录结果并释放 MSHR/set；不能等待尚未发出 Acquire 的计划 Grant。已接受的外部 owner 仍按协议终结。Checker 非 image-aware Get/Acquire 等读数/取权限 miss 使用已有最后一 way，普通 Main D miss 不分配；仅 v1 开启，前提为 replay 指令文本/页表不被受保护代码改写。
- history safe Put exact ACK 后仍持 set lock；目录 addressed read/write 设置 outerPreserved 收据。严格更旧的字节另置 baselineObsolete，新 A 将其视为待逐出的 victim；C 仍保留物理 owner。等待中的旧 A 在外部 owner 已终结后重新规划。新 refill/真实新字节更新清除 obsolete；不得仅因一笔 ACK 就认为所有地址有全局顺序。
- 同址入口顺序复用 L1 SVB releaseBlocked、按 Seq 迁移、C 完整 staging、history publish owner、SourceC pending barrier 和 set lock。尚缺可信 BASE/迟到 C/多拍写回全部组合定向覆盖，P3-10 不标完整 CODE_READY。
- I/O 用 pre-close 的 committed ARF/next-PC ECP，未退休 device head 不进入该前缀。等前驱 covered、RSU 完成、旧 committed stores/设备 owner 排空后允许一个 device 指令；退休后 post-close/验证效果段，才开放下一次 I/O。非零 Seq 的 I/O 全部进入 IOMSHR0 的单效果日志。日志由真实 D ACK 产生，按 PC/address/cmd/size/write-data 匹配重放，返回原读字或写终态，不重复发 A；有效且 covered 后释放。地址/操作数不匹配时不发第二次 A，由 preview（独立于 ready）报告该 attempt Seq，经 DCache 最早错误选择与 held error 进入现有 SCP retry；持续不匹配不代表成功恢复。journal 的 effectPending 单独保持 Core 中断屏蔽，可跨 rollback；不属于 cache drain busy。uncached AMO 同时拥有旧值 response 和 STQ terminal，前者握手后才允许后者。
- Core 压力关段可在 held 非 unique memory ROB head 前形成 committed-prefix 边界；CSR/unique 仍按原 empty-pipeline 约束。没有普通 rollback 全 Cache scan，也不先恢复全部行再 restart。

Core 直接实例化生产 PalimpsestIoBoundary，新增 io_boundary_test 测同一模块。ROB flush 仅同步取消状态，不能组合反馈到 retirementHold；避免 commit/flush/stall 环。baselineReady 仅等待实际已接受的外部 owner，未发 Acquire 的计划等待不阻止发布。新增满history/Probe/Checker逃生与真实dirty-victim多拍WB+FAIL8测试，均未运行。

上述路径仍需用户编译/仿真；Seq32跨Checker复用、持续I/O不匹配故障语义、整核关段/异常/压力组合为具体未完项。下文是较早契约记录，若提及并行 PRF/固定拍全局 done/普通 serial 饱和或缺 pre-I/O，以本节及 05/09 为准。

## 有限 EVT 容量维护（U-D07，低频服务路径）

普通rollback仍是EVT逻辑失效和按地址lazy恢复。32项EVT全满时，当前rollback继续持有SCP并保持Main停止；更早FAIL仍可用现有重叠merge重选，不能因为满表等待而禁止它。等待SW覆盖allocatedTail、全部R_IC package owner释放、LSU/cache quiescent及SVB/archive空后，L1发held maintenance request。

L2在旧EVT仍有效时完成在途请求和safe history发布，用现有目录单读口逐set/way读元数据；有效行复用原control flush→inner Probe→Release/ReleaseAck→目录invalid。safe脏字节发布DRAM，dead字节只释放权限；每次等待源owner、历史staging、publisher及实际ACK。所有物理行和history为空后才发maintenance ACK。L1收到真实ACK后清EVT并将Epoch/G归零，再经原history/context mailbox发布空表，四相维护返回低电平后才允许restart。

这次物理枚举是有限身份的低频容量服务，不在普通rollback或正常hit路径。它不复位Seq或SW，也不把旧Current直接当新Current。journal已进入replay后不能仅因旧EVT移除而变safe；只有匹配的新attempt重新绑定Seq且PASS才释放。Epoch/G在接近上界前提前进入同一服务窗口，保留超过live SCP窗口的重选余量。

Seq32仍单调；Rocket package_seq_reg也单调拒收旧包。未实现跨Main/Checker/CDC/tagged表的Seq重基维护，因此P3-15仍IN_PROGRESS，不能声称无限运行。Hierarchy新增34次真实不相交rollback/物理ACK/最终safe字节测试；孤立Recovery组件通过显式compact输入只测试局部EVT，不冒充物理维护证据。

## 配置与身份

目标 `chipyard.v1Config`：一个 BOOM、原有四个 Rocket Checker。当前新增冷恢复要求一个 memory lane、64-byte 无 ECC 整行和单个 inclusive-cache bank；代码以 require 拒绝不支持的几何/拓扑。共用 CSR、rename、L2 接口会影响其他配置的编译，尚未验证这些配置。

| 身份 | 当前存储/位宽 | 语义与边界 |
|---|---|---|
| Seq | R_IC，32 bit | 0 保留；恢复不重置 allocator；最大值时禁止新 snapshot |
| execution Epoch / G | ExecutionHistory，各 32 bit | 每次 rollback 提交递增；不能混同 image serial/物理 slotEpoch |
| EVT | 32 个 discarded [lower, upper] | 裁去 failedSeq..allocatedTail；保留旧有效前缀；重叠/相邻 discarded 后缀合并，真实存活 gap 不合并 |
| CacheImageKey | writer16/contentSeq32/generation32/valid | 不可变内容身份；serial 在地址/Seq 内递增，跨 Seq 从 1 开始 |
| Current mapping | L1 每 set/way 的 currentGeneration | tag/permission 命中、CurGen=G、HistoryValid 三者同时满足 |
| transaction/slot | slotEpoch16、request/effect token64、L2 serial64 | 保留到原 owner 终态后循环；组分配跳过不足尾部；Seq 不循环 |

HistoryValid 排除 tombstone；Seq0 为基线。ExecutionHistory 查询额外限制 Seq<=tail。只有 HistoryValid && CacheImage.safe(key,SW) 的数据允许外写。SW 每周期最多 +1，包含废弃区间跳洞，保持 Gray CDC 单步变化；EVT 向 L2 发布完成前不跨 tombstone。

EVT 无无界回收策略。容量不足或 Epoch/G 最大值经 historyUnavailable 将 Controller 置 failed，保持 stop、禁止恢复/重启、保留 pin；只能复位退出。这是显式容量停机，不是任意长执行的前进保证。

P3-15/P4-06 已按 U-D07 简化：普通 ID 由现有 owner 生命周期允许循环；合法迟到必须在 source/slot 复用前结束。LSU batch allocator 跳过不足尾部，L1 terminal receipt 在 completion 出队后清除；MSHR 空闲后再分配 serial，preservation/release 的旧终态完成后才更新 serial。不能把这一结论推广到 Seq、EVT 或有持久引用的 G。

## SCP 与架构状态

packet_alloc_valid/seq 在真实 Starting Checkpoint 边界保存 16 项持久 ContextMemory。capture 必须满足 ROB empty、提交安静、snapshot ready 和 SCP 容量充足。以完整 Seq 定位，与 Checker slot 无关；保存 committed next PC、x0–x31、f0–f31 和 CSRFile 本地打包的 8192-bit opaque 图像。

按 Seq 查询后 response 保持并 pin 到 restart；更早错误 abort/relookup，无 SCP 则 failed。只有连续 SW 回收安全 SCP；restart 回收错误后缀，释放 pin 的同拍也允许回收目标 SCP。read 命中与普通回收同拍时优先 pin。

已写路径：stop commit/dispatch → backend reset pulse → PRF/rename/free/busy restore → CSR/shadow → SCP PC redirect。整数 x0→p0，xi→p(i+1)，FP fi→p(i+1)，f0 必须恢复；FP 通过原 recode helper 写内部格式。PRF 恢复不得同时 normal writeback。

CSR 图像包含实际 privilege/status/debug、delegation/interrupt software state、trap vector/EPC/cause、地址翻译、PMP/breakpoint/custom CSR、FCSR、instret/HPM 等寄存器。cycle/time 不回滚，外部异步输入不作快照。恢复清 WFI，停止期间屏蔽 CSR 命令及 interrupt 输入。DTLB/ITLB/PTW 使用全地址 sfence 和原 s_wait_invalidate 丢弃旧 page-walk refill。可选 CSR 配置、异步事件及不可重复副作用仍属 P2-07/P4-10 未闭合审查。

FTQ 在 backend reset 及 SCP restart 重置；fresh redirect 不读取/修复旧 entry。fetch queues 由 redirect_flush 清空。预测器状态无需等同架构状态，但不能让旧 FTQ/ROB 身份污染新执行；该完整边界仍需整核验收。

## 已接接口

| Producer → Consumer | 接口 | 完成语义 |
|---|---|---|
| DCache → Controller | rollbackError Decoupled | Seq+cancelled，held valid；有效结果中最早错误；CANCELLED 不当 PASS |
| Controller → ContextMemory | checkpoint/read/response | 完整 Seq pin；更早错误可放弃并重选 |
| Controller → DCache EVT | rollbackHistory Decoupled | cold engine 允许时提交后缀失效；rollbackHistoryUnavailable 单独返回容量失败 |
| Cache/LSU/R_IC/RSU → Controller | rollbackQuiesced/Drained、recoveryDrained、idle | accepted 请求保留责任；suffix Checker 通过原 result CDC release |
| LSU/L1/L2/R_IC → Controller | rollbackIdentityUnavailable / identityUnavailable | 整组分配前禁止回绕；L2 sticky level 经同步器进入 L1；fatal 优先于 restart，不释放 pin |
| Controller → backend/frontend | reset/restore/restart | reset 与 restore 分拍；arch restore 完成及 memory ready 才 restart |
| DCache → Core → R_IC | cacheEarlyClose/Seq | MMIO blocked 或 SVB 接近满请求 close；不是完整活性保证 |
| SVB → L2 history | PALIMPSEST_ARCHIVE_* 四相 mailbox | 整行+exact key，RAM capture.fire 才 receipt，L1 收 receipt 才 free |
| DCache → L2/Checker | PALIMPSEST_HISTORY_REQUEST/PAYLOAD | 地址+EVT；payload sync3/request sync8；请求保持 |
| L2 → DCache | PALIMPSEST_HISTORY_ACK_n/RESULT_n | result sync3/ACK sync8；全部 ACK 高取结果，全部低后才复用 |
| L2 history → preservation | publish/published | safe publisher 保留可查询数据到真实外存 AccessAck |

mailbox 要求源 payload 在整个请求周期稳定及相容的时钟/复位约束；未经 CDC 工具验证。Checker 收 EVT 后走原 LSL flush、compare_abort、cleanup、result queue/CDC 释放，不强清 ownership。

## 恢复事务顺序

实际顺序为 **stop → lookup/pin SCP → commit EVT/G → drain/reconcile → reset backend → restore → resume/restart**。早期“先 drain 再 EVT”的草案已撤回：失败事务的 WaitSafe/Checker 等待需要失效通知解除，先 drain 会循环等待。

EVT 提交后先发地址零的同步查询，将 tombstone 发布给 L2/Checker；该查询数据不能作为恢复值。停止期间仍允许 committed prefix store 的 cold recovery，否则新 G 会阻止 prefix store 排空。更早错误重选 CP，正在进行的 cache/history transfer 先完成原责任，再允许下一 EVT 提交。missing SCP 或 unavailable EVT 均 fail closed。

## 保存、选择与安装

SVB 保存完整 immutable predecessor；普通 exception、measurement RESET 不清 recovery history。FAIL8 的 cutoff 是 7，绝不能按 SW6 删除 pending A7。SPEC 错误后缀可删除；WB_WAIT 保留到原 exact archive receipt。LSL 是 checker replay 输入，其释放不释放 SCP/SVB/L2 history。

SVB 已改独立 archive 通道。旧快照不能用普通 ReleaseData 下推，同时让较新 Current 保留 coherence permission。存活版本按 Seq/serial 升序转移，暂不 safe-coalesce；archive receipt 只转移存储责任，不表示 DRAM 安全。旧 Release-only SVB 观测/scoreboard 不再适用。

L2 history 为 64 项 addressed sidecar，保存 preservation unsafe predecessor、SVB archive 和 authored incoming C staging。同址查询排除 tombstone，选择最大 (Seq,serial)，held response；WB_WAIT 仍可查询。tombstone 可回收，safe history 仅在精确外存 ACK 后回收。incoming C staging 未入 RAM 前阻挡下一 C/query，不能在 L1 ReleaseAck 后丢掉唯一副本。

| Algorithm 1 操作 | 已写路径 | 未闭合点 |
|---|---|---|
| LookupCurrent | L1 ingress tag+CurGen+HistoryValid | probe/install/rollback 并发边界 |
| StaleCurrent | cold FSM 暂停普通 ingress | 必须保留原 coherence owner 到终态 |
| LatestSurviving | SVB held query + L2 history，按 Seq/serial 合并 | 缺真实 hierarchy fixture |
| SafeBaseline | 无合格历史才 coherent refill | 普通 WB/archive 入口的完整同址次序论证 |
| PromoteCurrent | stale resident 真 Release/ACK/clear，常规 Acquire T/MSHR 安装，绑定新 G | refill/probe/earlier-error 交错 |

L2 失效命中只撤销 hit 资格，保留原 state/clients/dirty/key，经 victim probe/release 释放义务；不能伪造 INVALID 或 clients0。discarded 外写去数据化，禁止 A8 bytes 写 DRAM。native peer 对 unsafe/invalid history park/replay。本轮无多 Main 所有权转移扩展。

Figure4(b) 目标：DRAM A1、Seq7 A7、Seq8 A8、SW6、FAIL8；pin SCP8，EVT8..tail 失效，A7 仍可查，冷访问选 A7 安装，新 Epoch、新 Seq>旧 tail。新增 HierarchyHarness 实例化真实 BOOM L1、InclusiveCache、CacheCork、Controller/SCP，host 仅驱动架构请求/Checker 结果和终端 DRAM；包含归档完成、迁移重叠和 accepted miss 迟到响应三例。scoreboard 检查真实 load A7、相邻未改字 A1、SCP8/new Epoch/Seq9、禁止 A8 外写。并未实例化 BOOM pipeline；不证明整核重执行。未编译/运行，不能当恢复成功证据。

## 事务结算与尚未满足的契约

LSU 只取消未进入 DCache 的 suffix/uncommitted store；accepted owner 等 STORE_DONE。CANCEL 必须回 LSU 结清责任，但不生成架构数据响应。strict store 统计为 arch=completed+cancelled，不把取消计为内存写，保留断言。rollback reset 清 LSQ/pointers/live_store_mask/局部异常和 busy 通知，不清全局 token。MSHR/WB/reservation 不随 backend reset 丢失。

1. **B-MMIO**：pre-accept gate 等 Seq<=SW，当前 MMIO 又阻止 ROB empty/ECP，形成循环。缺真正 pre-I/O split 或不可重复效果重放日志/recovery floor。当前只有过早外发的拦截，没有前进路径。
2. **B-CAPACITY**：SVB/L2 archive 的 early close 未覆盖 ROB/LSQ/MSHR 后续需求的 reserved credits；当前段满 archive 可阻止 load/evict/ECP。提高容量不能替代闭环。
3. **B-BASELINE**：RAM 内升序 publisher、SourceC pending gate 已写；仍须完成所有入口的同址安全基线次序证明及 directed test。
4. **B-ENDTOEND**：专用整核 workload/scoreboard 尚未写完；真实层次 fixture 只覆盖三个 memory 场景，dirty victim/Probe/accepted WB、TLB/PTW/interrupt 全交错仍未覆盖。B-IDENTITY、B-HIERARCHY-TEST 的源码阻塞已解除，测试均等待用户执行。

CODE_READY 不是 VERIFIED。所有运行结果 NOT_RUN_BY_CODEX；人工验收见 08。
