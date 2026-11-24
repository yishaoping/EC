# 单核功能闭环盘点

覆盖全部69项原始任务。实现阶段、主要阻塞及验收条件独立于原任务状态记录；状态提升必须有实际验证证据。

依赖：B事务生命周期→C恢复控制→A版本基线与D缓存owner→E整核协同。A与D共享发布顺序，不单独构成整核证明。

| ID | 当前状态 | 工作流 | 实现阶段 | 主要阻塞或审查结论 | 验收条件 |
|---|---|---|---|---|---|
| P0-01 | VERIFIED | A,B,C,D,E | 既有验证保留 | 已读取论文/原始49项审计和冻结架构边界，原编号不变；对应源文档在69项审查逐项定位，无额外待实现RTL。静态检查验证原49编号集合与单核范围，任务本身是基准读取而非额外硬件。 | static_check 验证编号集合 |
| P0-02 | VERIFIED | A,B,C,D,E | 既有验证保留 | 实际git工作树、V10独立归档、完整源码哈希与当前生成/运行来源均已核对，保留无关DOC删除；本批source_manifest、候选/生产逐字节关系与完整整核运行input哈希均实际核验。 | static_check 验证 DAG、路径和渲染 |
| P0-03 | VERIFIED | A,B,C,D,E | 既有验证保留 | 原49项到69原任务的映射完整且ID集合不变；49 features与原审计编号集合逐项相等，静态检查已执行通过，不再因其他RTL未完保持该映射任务未验收。 | static_check 验证编号集合 |
| P0-04 | VERIFIED | A,B,C,D,E | 既有验证保留 | 单Main+4Checker、C5/D17范围外、I/O输入一致/输出屏障、无永久故障扩展等边界已在长期决策和规范冻结并与实际配置核验；静态检查验证范围集合。 | static_check 验证编号集合 |
| P0-05 | VERIFIED | A,B,C,D,E | 既有验证保留 | 69项每项源码路径和具体信号均在manifest/矩阵，当前源码存在性、source_review和code_review锚点实际核验；新增核心实现亦已纳入来源，实际RTL生成/运行可追溯。 | static_check 验证 DAG、路径和渲染 |
| P0-06 | VERIFIED | A,B,C,D,E | 既有验证保留 | SCP pin/read/restore/discard、Error held Seq、EVT四相及cache/Checker终态责任均已定义并真实接线；当前恢复链组件、完整C/E配对及最终23次重基实际验证接口。 | static_check 验证 DAG、路径和渲染 |
| P0-07 | VERIFIED | A,B,C,D,E | 既有验证保留 | 原69项DAG已实际无环校验，五功能工作流与交叉依赖长期化，剩余缺口按原ID映射；执行顺序遵循Seq32→恢复→版本/owner→整核，不以新增版本代替依赖闭合。 | static_check 验证 DAG、路径和渲染 |
| P1-01 | VERIFIED | C | 既有验证保留 | 当前生产真实RSUSL在F0组件检查x0归零、仅f0差异和f31终拍累积；新双Seq真实注入各只一次、held结果/ACK及Checker→GHM→SCP/EVT组件均重新生成运行PASS，整核真实Fault8严格配对已PASS。原f0比较任务无遗留实现缺口。 | F0 比较结果和 CheckerRecovery FAIL |
| P1-02 | VERIFIED | B | 既有验证保留 | 精确Seq owner/结果bitmap逐项SW推进、普通rollback不复用和四相维护后Seq1复用已由高位SeqTransport/Identity、生产Hierarchy与最终Core23次维护验收；全宽数字生命周期证据单独于小门槛测试，不把Seq16等同32位证明。 | SW 边界和旧 Seq 误配检查 |
| P1-03 | VERIFIED | A,D | 既有验证保留 | 关闭依据：历史生命周期闭环已有真实L1→SVB→L2→外存动态证据：同址Pending7、实际L1 Seq8填满C、BASE外写ACK背压、FAIL8→FAIL7及第二Probe；当前生产Hierarchy再通过。新增同址3/5/7、SW扫描、迟到C/可信Put及EVT5..8与外写owner同持有的四长期用例均通过，精确每beat/ACK/最终无历史槽泄漏。原笼统“其他多owner”不是新功能定义；余下满资源整核压力由P4-12/P4-13跟踪。 | 跨层C迁移+同址History写回+EVT扫描同时持有，逐外写beat及恢复整行核验。 |
| P1-04 | VERIFIED | A,D | 既有验证保留 | 原SW6/FAIL8保留A7问题由真实L1/SVB/L2/DRAM Figure4联合验证，Pending7存活、A8废弃、整行邻字不变；最终生产Hierarchy与多发布入口/EVT四用例均实际PASS。 | Figure 4、保留 Pending7、WB_WAIT 重复 ACK |
| P1-05 | VERIFIED | A,D | 既有验证保留 | 关闭依据：跨Segment创建/保留原任务已完整实现：SW6时真实Seq8 cached AMO覆盖Pending7，前驱先归档，AMO旧值/唯一写效应、回滚整行和邻字全部正确。真实L1/SVB/L2迁移与连续恢复同批Hierarchy通过；实际整核正常/Fault8、CLINT/uncached AMO完整通过。满History整核压力保留P4-12，不能继续作为本项独立缺口。 | 满资源下完成跨段创建、归档、回滚并继续执行。 |
| P1-06 | VERIFIED | A,D | 既有验证保留 | 实际cached store byte mask和cached AMO先捕获整行前驱，只有选中字节被改变，AMO原值和邻字均由真实Hierarchy测试；当前生产Hierarchy再生成PASS，完整normal/Fault8/uncached AMO程序独立通过。 | Hierarchy 检查邻字和 AMO 旧值 |
| P1-07 | VERIFIED | A,D | 既有验证保留 | 关闭依据：Preserve-before-reuse已通过真实L1 dirty victim/满C/外写ACK与两次EVT，以及真实L2满64 History、park、reserved credit与Checker逃生的组合。原owner先保存并得到精确ACK才复用；候选finite slot反例修复后的当前生产Hierarchy再次通过。没有未闭合保存接口，完整资源压力继续P4-12。 | 满History+真实L1 victim+回滚，ACK前不复用，最终可前进。 |
| P1-08 | VERIFIED | A,D | 既有验证保留 | 关闭依据：SVB WB_WAIT与exact key/ACK保持、L2多拍外写事务、实际L1满C/同址BASE ACK/两次EVT和迁移源目标owner均有真实终态测试。新增安全9合并时已接受Seq3的key/txn/bytes不变、匹配ACK后才退休；当前生产finite-slot分配/安装/终态边界已修并验收。原迁移/满C缺口已被实际联合用例覆盖，保留协议终态责任边界。 | 同一完整事务从保存、迁移、ACK到释放重用，含重复/迟到ACK。 |
| P1-09 | VERIFIED | A,D | 既有验证保留 | 关闭依据：原任务三类回收条件均有真实生产证据：既有且来源未变SVB同Seq中间值/EVT dead/WB_WAIT精确ACK；本批真实L1满C+Pending7+BASE外写+FAIL8→FAIL7保持，新增L2安全9合并时held Seq3 owner保持原key/txn/bytes、ACK后仅发布9且查询无泄漏。长期入口实际重编并运行通过。其余跨层迁移压力仍由P1-03/P1-08/P4-08承担，不泛化为本项缺口。 | WB owner不被回收，dead/同段中间值/被安全值替代分别回收。 |
| P1-10 | VERIFIED | A,D | 既有验证保留 | LSL消费仅释放输入日志，不是恢复History终态；旧Pending7在Checker/result/LSL释放后仍按EVT存活供恢复读取，真实L1/SVB/L2和连续EVT/外写owner联合通过，回收仅由存活性、同址合并或精确外写ACK驱动。 | Figure 4、保留 Pending7、WB_WAIT 重复 ACK |
| P2-01 | VERIFIED | C | 既有验证保留 | held Error携带完整Seq/cancelled，GHM result真实跨域、DCache精确owner匹配后送Controller；当前CheckerRecovery重新生成运行及normal/Fault8完整程序证实真实接口，未知旧结果不改变新owner。 | Recovery/CheckerRecovery 的 STOP、优先级和 SCP oracle |
| P2-02 | VERIFIED | C | 既有验证保留 | 生产Controller lookup/history/drain/restore/resume和更早FAIL抢占、SCP pin保持、实时late owner重查已动态验收；当前完整C/E和最终23次重基证实Main集成，无需因另项中断缺陷悬挂已闭合Controller。 | Recovery/CheckerRecovery 的 STOP、优先级和 SCP oracle |
| P2-03 | VERIFIED | C | 既有验证保留 | 持久SCP RAM在SW回收/读取pin/abort/重选/恢复/丢弃全生命周期已有Recovery/Restore和真实完整Core证据；PRF/rename owner收据后才释放，最终23次重基从精确SCP PC重启。 | pinned SCP reclaimed before restore completion；真实 PRF done |
| P2-04 | VERIFIED | C | 既有验证保留 | 按Seq精确查SCP、缺失边界和更早FAIL放弃旧pin后重新定位由生产Recovery组件验证；真实L1 FAIL8→FAIL7/SCP7与整核Fault8/18同PC链均通过，最终组合整核通过。 | Recovery/CheckerRecovery 的 STOP、优先级和 SCP oracle |
| P2-05 | VERIFIED | C | 既有验证保留 | SCP PC→Core redirect→Frontend新取指接口已闭合。正常/Fault8 trap_io和原Sv39、Fault18写/AMO均完整退出并核验同SCP PC恢复；最终owner/CDC增量整核23次重基逐次核验Restore/Restart同PC及新Seq1 PASS。 | 复核PC oracle覆盖冷miss、trap及重基恢复；PC任务不承担所有Sv39失败。 |
| P2-06 | VERIFIED | C | 既有验证保留 | 真实integer/FP PRF逐32项恢复和rename done由实际Restore组件验收，相关PRF/rename源文件与该证据逐字节相同；当前完整Core多次恢复的内存/AMO依赖、f0/FP与所有程序oracle通过，Core实际owner链已闭合。 | pinned SCP reclaimed before restore completion；真实 PRF done |
| P2-07 | VERIFIED | C,E | 既有验证保留 | 无功能未结项；生产scratch shadow W/S/C使用同包CPS旧值、12组件组合通过；最终normal/Fault18完整IRQ均16set/clear/精确trap/匹配MEPC xRET，恢复/CSR/精确异常/Sv39完整配对及14负例通过。 | PASS；AI/TMP/singlecore_function_closure_20261123/final_closure_current_scheduler.json |
| P2-08 | VERIFIED | C,E | 既有验证保留 | stop屏蔽无owner执行offer，已提交prefix及已受理owner有独立终态。真实完整LSU load/STAD/STA/STD/SFENCE五反例和normal load控制通过；PreciseException、真实Hierarchy及最终完整23次重基验证ROB/Rename/LSQ清理与恢复后正确执行。 | 修复stop与在途执行请求交接；旧响应终态保留且新执行无污染。 |
| P2-09 | VERIFIED | B,C | 既有验证保留 | 关闭依据：原始任务是错误后Checker/LSL/Segment清理。生产四域EVT/结果/清标签链已连接；本批真实高位DATA/ARF/END/result、包内trap/xRET/特殊PC保持、慢Checker四相收据通过；相同生产来源的整核23次重基完整退出。其他LSU异常入口缺陷单列P2-08/P4-05，不再泛化为本项缺口。 | 近32位上界标签、延迟结果、停钟、源端空收据、四相复用及正常整核。 |
| P2-10 | VERIFIED | C,E | 既有验证保留 | Restart持续重查当前cache/RSU/SCP owner，已消除snapshot组合反馈及FINISH早于包释放。真实四配置FIRRTL和完整C/E程序通过；最终GHM注册+有限owner组合Seq16整核完整23次恢复均reconciled、新Seq1 PASS，无额外取消。 | 正常/Fault8/Sv39/Seq16完整严格验收及重启单次、SCP释放顺序。 |
| P2-11 | VERIFIED | C | 既有验证保留 | 原任务是重复、乱序和恢复期间Error处理；Recovery实际duplicate不变Epoch、更晚不重选、更早abort/relookup，96次retry和真实层次FAIL8→FAIL7/新Probe均通过；同一Core第二次独立FAIL的额外验收仍由P3-14/P5-07保留。 | Recovery/CheckerRecovery 的 STOP、优先级和 SCP oracle |
| P3-01 | VERIFIED | A,D | 既有验证保留 | Epoch/CurGen随已接受恢复事务更新，普通恢复不复用Seq，物理维护证书后才清标签；真实近32位保留区维护/再次rollback及最终Core23次维护通过。 | EVT maintenance certificate / old ingress after Checker Seq reset |
| P3-02 | VERIFIED | A,D | 既有验证保留 | EVT区间合并、较早FAIL合并释放满表、跨Main/L2/四Checker安装ACK高低阶段、物理维护后空表均有生产组件和真实层次测试；最终Core23次EVT/compact/reset/恢复逐次验收。 | EVT maintenance certificate / old ingress after Checker Seq reset |
| P3-03 | VERIFIED | B | 既有验证保留 | 关闭依据：普通恢复保留递增Seq，只有物理维护、源端FIFO空及各域清标签收据后才清零；真实近上界32位标签清空后Seq1复用正确，整核23次重基无错配。 | SW 边界和旧 Seq 误配检查 |
| P3-04 | VERIFIED | A,D | 既有验证保留 | CurGen与新slot owner reservation共同实现代际失效。当前生产Hierarchy、0xffff真实slot分配/安装终态和32位0xffffffdd→de触发真实物理维护、证书后归零再rollback通过；最终组合整核23次维护后重执行正确。 | 所有reservation进入与终结路径对照真实owner测试。 |
| P3-05 | VERIFIED | A,D | 既有验证保留 | EVT跨Main/Checker/L2保持，dead条目不lookup/不发布，但在途owner保持到物理终态。真实L1 fullC/Pending7/BASE ACK/两EVT、四发布用例及最终完整Seq16组合均通过。 | 废弃数据不成为可读候选或发布字节，已接受协议终态完整。 |
| P3-06 | VERIFIED | A,D | 既有验证保留 | 实际SVB addressed query整行最大存活候选、响应背压、精确WB owner均通过；其生产源码与原通过组件逐字节相同，当前生产Hierarchy真实L1/SVB/L2恢复和整核程序再次通过。 | Hierarchy 真实 load 与 DRAM 字节、SVB 最大存活候选 |
| P3-07 | VERIFIED | A,D | 既有验证保留 | L2单索引scan/共享RAM查询按Seq/serial选择最大存活整行，扫描/外写owner互斥；当前生产Hierarchy及四同址发布/迟到C/可信写/EVT用例逐外写beat和最终query无泄漏均PASS。 | Hierarchy 真实 load 与 DRAM 字节、SVB 最大存活候选 |
| P3-08 | VERIFIED | A,D | 既有验证保留 | 实际L1/SVB/L2跨层查询、空查询交接/重试窗口与冻结Grant证书已验证。真实Hierarchy两EVT和多owner发布逐beat/整行及Sv39完整物理+提交配对通过；有限slot终态修复后的最终组合整核亦通过。 | 不同候选层级、同址迁移时实际读取最大存活整行。 |
| P3-09 | VERIFIED | A,D | 既有验证保留 | LatestSurviving用Seq/serial排序且过滤EVT死版本。SVB/History/真实Hierarchy选择A7而保留前缀、整行邻字及四发布联合用例均通过；最终Core组合恢复与程序oracle正确。 | 多版本与废弃区间共同选择，逐字节oracle。 |
| P3-10 | VERIFIED | A,D | 既有验证保留 | 关闭依据：SafeBaseline原任务已由真实L1/L2/外存闭合：cached AMO/byte mask/前驱恢复，满C与两次EVT、外写ACK，SW边沿/SourceC/迟到C/可信A、冻结Grant证书，新增同址3→5→7实际每beat顺序及安全9合并owner保持全部PASS。当前控制/I/O完整Core另由C/E任务验收，不把无关会话/设备缺陷作为选择算法的永久阻塞。 | Put/C/SourceC/维护/可信写的共同顺序及真实ACK。 |
| P3-11 | VERIFIED | A,D | 既有验证保留 | PromoteCurrent复用首Grant冻结的L2证书和payload/key；SW在背压变化、新可信写和0xffff有限slot分配/安装一致性已动态通过，最终组合整核23次恢复后正常读写并完整退出。 | SW在Grant背压期间变化，payload/key/证书一致且可信后继写保留。 |
| P3-12 | VERIFIED | A,D,C,E | 既有验证保留 | Lazy Recovery实际冷L1/SVB/L2查询与晋升、两EVT/物理维护、当前normal/Fault8/原Sv39/CLINT写/AMO严格完整配对通过；最终owner/CDC组合Seq16整核23次恢复后每次Seq1真实PASS。 | 完成旧owner终态、整行候选与前进性及完整程序。 |
| P3-13 | VERIFIED | A,B,D | 既有验证保留 | 普通rollback跨Epoch保留前缀且不复用Seq，较早FAIL合并和表满维护保留真实owner。真实Hierarchy连续EVT、四发布/回收、32位近界实际维护证书后清零及再次rollback通过；最终完整23次重基无旧历史污染。 | 多个epoch存活版本、表满维护、更早FAIL共同回收正确。 |
| P3-14 | VERIFIED | B,C,E | 既有验证保留 | 原任务是连续Rollback的集成与测试。组件/真实Hierarchy中重复/更早FAIL与满表区间合并已覆盖；本批新增实际生产Main+4Checker+cache同一ELF normal/双注入完整Core，原RSUSL f0 comparator仅在Seq8/24各真实FAIL一次，分别有精确SCP/EVT/同PC Restore/Restart/fresh epoch PASS，最终architecture checksum/128ecall/MMIO/内存/FP/CSR与normal相同，raw0、oracle0、sources前后相同。严格联合计分通过，并拒绝8类第二失败/恢复/取消/结果损坏/缺oracle负例。证据singlecore_function_closure_20261123/concurrency_fullcore及two_fault_oracle_negative/results.json；另行满History/中断/效果重基集合仍按P4-12/P4-10/P4-13验收。 | 同一程序两次真实比较FAIL、两次SCP/EVT/恢复后最终oracle。 |
| P3-15 | VERIFIED | B | 既有验证保留 | Seq32高位DATA/ARF/END/result与四相清空后复用、16位slot 0xffff→1实际完整终态、32位Epoch/CurGen保留区真实外写证书后清零和再次rollback、每段5000条的serial有界性共同闭合；最终组合整核23次维护通过。物理Gray偏斜/布局时序单列硬件签核限制，不冒充数字验证。 | 真实32位近边界DATA/ARF/count/result及四相归零，再Seq1复用；有限generation/serial边界核验。 |
| P4-01 | VERIFIED | C,D,E | 既有验证保留 | Controller drain/reconcile持续跟随真实cache/LSU/Checker/RSU/SCP owner。真实L1 dirty/fullC/Pending7/BASE外写ACK/两EVT及late Probe撤回restart通过；最终组合Core23次恢复均reconciled=1、旧owner收尾后才恢复。 | 修复执行请求stop边界，实测恢复和新Probe重查。 |
| P4-02 | VERIFIED | D,E | 既有验证保留 | MSHR/Probe/Grant/E/Release/ACK、cold miss空查询交接和旧翻译请求均有对应owner到终态。当前生产Hierarchy、真实DTLB/I-TLB/PTW及原Sv39完整配对通过；有限slot修复和最终组合Core23次维护后无遗留阻塞。 | 原owner精确终态、不复用MSHR、旧payload不污染重启。 |
| P4-03 | VERIFIED | D,E | 既有验证保留 | STQ committed prefix/取消终态、uncached AMO授权包归属和唯一ROB响应已实现。真实normal/Fault18写/AMO16轮效果/旧新值/回读/无重复A完整通过；最终LSU/有限owner/CDC组合Seq16完整程序通过，无store/writeback遗留。 | 已提交prefix可完成，年轻请求取消/清理且token无重复或丢失。 |
| P4-04 | VERIFIED | A,D | 既有验证保留 | 关闭依据：回滚期间保存/WB ACK原任务由实际L1满C+Pending7+BASE多拍外写ACK+FAIL8→FAIL7及独立SVB exact ACK共同验收；两个EVT四相先完成但旧物理owner继续保持。第四长期用例在同址3/5/7/迟到C/已发外写时安装EVT5..8并推进SW8，dead字节不出外存、真实ACK后才结束，最终查询无泄漏。 | exact key、ACK高低、旧终态与新版slot隔离。 |
| P4-05 | VERIFIED | B,D,E | 既有验证保留 | 旧请求仍保持物理owner但不能写入新执行。真实DTLB/I-TLB/PTW迟到响应、L1旧miss/外写与两EVT、新执行整行/CSR及原Sv39完整配对均通过；0xffff owner和最终完整23次重基新Seq1逐次PASS。 | 原响应收尾，新地址/数据/CSR恢复与完整程序配对。 |
| P4-06 | VERIFIED | B | 既有验证保留 | 关闭依据：真实0xffff→1 owner错配已按同一反例修复并合入生产：三处install/refill统一既有nextSlotEpoch，无新状态。当前生产实际SBT/Chisel/FIRRTL再生成、SeqTransport与整套Hierarchy回归通过且来源相同，长期空槽边界四次同组miss/完整安装终态/后续读实际PASS。短token按原owner终态循环及exact receipt证据保留，完整有限slot事务接口已闭合。P3-15的持久版本/CurGen边界与FIFO物理约束另验收，不以此任务覆盖。 | identity allocation exceeds reserved group；Identity 小上界 |
| P4-07 | VERIFIED | A,D | 既有验证保留 | 关闭依据：Cache replacement与rollback并发已由真实L1 dirty victim、Probe/C/full staging、已接受多拍外写/ACK背压、较早FAIL重选、实时restart owner重查和相邻字oracle联合验证。修复finite-slot后当前生产Hierarchy再通过；Baseline/Pressure同次固定来源通过，未以主程序checksum替代每个外写beat。 | 替换/compact/新事务共同持有时无不安全外写及死锁。 |
| P4-08 | VERIFIED | A,D | 既有验证保留 | 关闭依据：跨层迁移与rollback接口已闭合：实际L1 Seq8 C填满L2队列、Pending7在L2、同址BASE外写ACK在途时FAIL8→FAIL7，完整四相/第二Probe/恢复实际load与所有外写beat均通过。当前新增同址多版本迁移/SW/EVT扫描/迟到C/精确ACK四用例补齐原另一层owner联合缺口。当前生产Hierarchy重新通过，不再以未指定的任意组合维持IN_PROGRESS。 | 跨层迁移的源/目标owner与恢复扫描同时终结，安全字节保持。 |
| P4-09 | VERIFIED | C,E | 既有验证保留 | 关闭依据：实际uncached AMO两个生产缺口已修：授权时重绑效果包与唯一旧值响应。当前生产normal/Fault18完整联合验收通过，全部16轮真实AMO/回读/旧新值正确，唯一FAIL18按同SCP PC恢复，journal保存旧值重放且原逻辑效果设备A仅1。既有CLINT写16写/16回读在当前RTL完整复验通过；正常/Fault8 trap_io严格配对及组件I/O/边界通过。I/O输入一致/输出屏障既定范围满足，其他重基交叠压力由P5-10/P4-10继续验收。 | 真实uncached AMO返回原值且副作用一次；当前RTL Fault18长期入口通过。 |
| P4-10 | VERIFIED | B,C,E | 既有验证保留 | 无功能未结项；最终生产正常/Fault8精确异常/Sv39、normal/Fault18 IRQ/CLINT写/uncached AMO完整通过；16轮真实效果与回读、每trap返回及恢复门控，已生效效果重放无第二A。 | PASS；AI/TMP/singlecore_function_closure_20261123/final_closure_current_scheduler.json |
| P4-11 | VERIFIED | A,D | 既有验证保留 | I/O pre/post封口、committed-prefix和真实cache容量封口已实现，late closed-package请求不能启动新保持；原Sv39反例同ELF当前normal/Fault8完整配对通过，真实Fault18写/AMO屏障和最终23次重基也通过。 | I/O issued before its committed prefix validated；Io/Ioboundary |
| P4-12 | VERIFIED | D,E | 既有验证保留 | 当前最终来源完整满History及8负例PASS | PASS；AI/TMP/singlecore_function_closure_20261123/grantack_preemption_system_acceptance/pressure/report.json |
| P4-13 | VERIFIED | B,C,D,E | 既有验证保留 | 无功能未结项；原normal IRQ写回死锁由真实638信号链确认同组C→History→外层E循环。最小Scheduler仅含E调度例外解除循环，真实权限组件旧1/新0，Hierarchy/4发布/压力组件及5配置12完整程序全部PASS。 | PASS；AI/TMP/singlecore_function_closure_20261123/final_closure_current_scheduler.json |
| P5-01 | VERIFIED | A,D | 既有验证保留 | 保存测试已长期化并真实执行：SVB独立、多版本整行、byte mask/AMO以及真实L1/SVB/L2迁移和恢复；不只增加测试文件，原生产来源相同证据与当前Hierarchy重复验收俱在。 | 实际退出码、PASS 签名和无 assertion/UNCOVERED |
| P5-02 | VERIFIED | A,D | 既有验证保留 | 原始验证范围保留；已核验对应源文件存在，未重构。 | 保持既有已通过功能及相关回归。 |
| P5-03 | VERIFIED | C | 既有验证保留 | 原始验证范围保留；已核验对应源文件存在，未重构。 | 保持既有已通过功能及相关回归。 |
| P5-04 | VERIFIED | C | 既有验证保留 | 真实RSUSL mismatch→GHM result CDC→Error/SCP/EVT/Restore/Restart测试长期入口实际通过，当前源F0/双注入/CheckerRecovery再执行PASS，真实Core单次Fault8严格完整配对通过。 | 实际退出码、PASS 签名和无 assertion/UNCOVERED |
| P5-05 | VERIFIED | A,D | 既有验证保留 | Figure4 SW6/Pending7/FAIL8真实Hierarchy入口已运行PASS，按真实load和每个accepted外写beat/全部邻字判定；A7未删除且A8不外写，当前生产重编再通过。 | 实际退出码、PASS 签名和无 assertion/UNCOVERED |
| P5-06 | VERIFIED | A,D | 既有验证保留 | 原始验证范围保留；已核验对应源文件存在，未重构。 | 保持既有已通过功能及相关回归。 |
| P5-07 | VERIFIED | A,D | 既有验证保留 | 原任务是连续Rollback的集成与测试。组件/真实Hierarchy中重复/更早FAIL与满表区间合并已覆盖；本批新增实际生产Main+4Checker+cache同一ELF normal/双注入完整Core，原RSUSL f0 comparator仅在Seq8/24各真实FAIL一次，分别有精确SCP/EVT/同PC Restore/Restart/fresh epoch PASS，最终architecture checksum/128ecall/MMIO/内存/FP/CSR与normal相同，raw0、oracle0、sources前后相同。严格联合计分通过，并拒绝8类第二失败/恢复/取消/结果损坏/缺oracle负例。证据singlecore_function_closure_20261123/concurrency_fullcore及two_fault_oracle_negative/results.json；另行满History/中断/效果重基集合仍按P4-12/P4-10/P4-13验收。 | 实际退出码、PASS 签名和无 assertion/UNCOVERED |
| P5-08 | VERIFIED | A,D | 既有验证保留 | Cache miss/Probe/fullC/dirty victim/多拍WB/ACK与FAIL8→更早FAIL7、第二Probe的真实联合测试已长期化并运行；最终生产Hierarchy再PASS且先前restart断言原反例已消失，不以单一checksum代替外写检查。 | 实际退出码、PASS 签名和无 assertion/UNCOVERED；Hierarchy 要求停住外写时第二次 EVT 完成高低回执 |
| P5-09 | VERIFIED | B | 既有验证保留 | 关闭依据：长期测试实际覆盖延迟result/release、旧DATA/ARF/END、高位Seq及四相ACK，并核验Seq1复用；测试由现有user_build入口执行通过。 | 实际退出码、PASS 签名和无 assertion/UNCOVERED |
| P5-10 | VERIFIED | C,E | 既有验证保留 | 无功能未结项；长期MMIO/IRQ/满History/重基完整入口、输入与严格oracle固化；最新12程序raw/oracle0，全部联合评分0，IRQ14/重基9/压力8负例全拒绝，最终源码和输入已独立核验。 | PASS；AI/TMP/singlecore_function_closure_20261123/final_closure_current_scheduler.json |
| P5-11 | VERIFIED | A,D | 既有验证保留 | 原端到端Fault Injection任务已有真实一次f0比较错误经原result链触发恢复，正常/Fault8/原Sv39、Fault18写/AMO严格完整配对与最终23次Seq重基均通过；双独立FAIL扩展不混入原定义，仍待专门验收。 | 实际退出码、PASS 签名和无 assertion/UNCOVERED |
| P5-12 | VERIFIED | A,B,C,D,E | 既有验证保留 | 人工Scala/Chisel/FIRRTL、组件、正常/故障/Seq16完整Core、SV39精确oracle、基线/有限owner和综合入口已长期化并实际执行，命令/来源/退出均追溯；新增concurrency入口已实际构建，不能入口存在即宣称其动态PASS。 | 实际退出码、PASS 签名和无 assertion/UNCOVERED |
| P5-13 | VERIFIED | A,B,C,D,E | 既有验证保留 | 长期预期/失败定位方法和严格计分已由真实成功/失败、四Sv39 payload/restore负例、四CLINT/AMO后续轮次负例验证；raw0但缺完整oracle的停止冗余运行正确被拒绝，原失败不覆盖。 | 实际退出码、PASS 签名和无 assertion/UNCOVERED |
