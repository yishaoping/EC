# 恢复状态机

当前验收（2026-11-24）：69项功能VERIFIED；当前5模型/12完整程序/31负例与严格联合评分全部PASS。来源、范围和独立物理状态见[系统验收](System_Acceptance.md)。

| Controller 状态 | 前进条件及动作 |
|---|---|
| idle | 有有效 Error 当拍拉起 stop，接受最早 Seq。计划重基在 producer 封口后从空 SCP 启动同一流程。 |
| lookup | SCP read.fire 锁定索引。有效读不存在时进入 failed。 |
| history | SCP 响应有效后更新 EVT，发出 `installOnly` 请求以废弃后缀。安装可与已接受的外写并行。 |
| drain | 等 EVT 安装的 ACK 高低两阶段及旧 cache、LSU、RSU、失败后缀 Checker owner 终结，SCP 仍锁定。DCache 在这段期间并行跟踪安装回执和旧事务。 |
| restore | Core 先发一拍 backend reset，随后保持 Restore 到 PRF、rename、CSR、ROB 分别完成。恢复 SFENCE 沿既有翻译路径发出。两个 TLB 保留已接受的旧 walk，直到旧响应完成，再允许发新 walk。SFENCE 作废的响应不能填入翻译表。 |
| resume | 等待 memoryReady，并实时检查 quiesced 和 SCP 响应仍有效。排空确认后新 Probe 可暂时撤回重启许可，期间保持 stop 和 SCP pin。Restart fire 取 SCP PC 发前端 redirect，为下一段拍摄 fresh SCP，释放旧 pin。 |
| failed | 当前实现用于无 SCP 或有限标识/历史空间不可继续的明确边界。 |

更早 FAIL 中止当前恢复并重新定位 SCP。在途安装完成高低两阶段后才能发下一份 EVT。旧 memory owner 保留原始 Seq、事务 key 与终态条件，C 数据归档与地址查询继续遵守基线顺序。EVT 容量维护用原 L2 control flush 和终端收据扫目录，然后复用邮箱安装空表。已废弃内容只还权限。

ROB 在 stop 时抑制异常选中和正常退休。已选异常经一拍传播到 CSR。stop 在投递拍生效时屏蔽投递，恢复后由重执行重新检测。正常时 ROB 保留较老退休优先级，跨无效 lane 仍记住本拍已选中的较老退休。前端从 stop 到实际 restart 仅 flush，restart 当拍才接收恢复 PC。相关实现在 `rob.scala` 的 `will_throw_exception` 和 `core.scala` 的 CSR exception / IFU redirect。整核 CSR、PTW 与 LSU 迟到事件的组合验证见验证矩阵。

SCP 同时保存 `PalimpsestTrapTracker` 的三个已有状态位，由 Core 在恢复 CSR 的同一阶段装入。它们记录是否处于被跟踪的 handler、系统调用边界是否待发以及边界年龄。恢复点位于 trap 之前时撤销废弃后缀的边界，位于 handler 内时恢复该边界的原状态。停核清除 R_IC 的临时 `boundary_priv`，R_RSU 普通快照覆盖旧的 `crt_mode`。`PreciseException` 通过生产 tracker 和 SCP RAM 检查跨 trap 入口和 MRET 的双向恢复，以及 pending 只消费一次。

冷地址查询完成后，DCache 的 `recoveryMiss` 持有选中的整行，直到匹配的 MSHR refill 装入。LSU 重试之间可以没有请求。已经映射的访问可经过这段等待，另一冷地址或下一次 stop 则要等相关 owner 空闲才可接替。停核时，存活前缀的已提交 store 仍可消费同址结果。Hierarchy 用 800 拍请求空窗检查同一地址的重试仅产生一次查询。

不同冷地址接替时，`beginColdLookup()` 在当前 `recoveryMiss` 拍直接锁存新地址、way 和查询上下文，进入 `recoveryQuery`；若该地址有存活驻留行，则刷新它的 CurGen。不得先回 Idle 再重新选择请求：LSU 对尚未接受的 offer 会重新仲裁，这个空拍曾导致同一空查询反复执行而没有请求进入 S0。空 valid 仍保留原结果，stop 仍按原条件终止旧尝试。该修复复用已有寄存器和八态 FSM。长期 `alternatingColdHandoff` 用例及整核证据见冷查询故障记录和验证矩阵。

该整行是候选，尚未取得一致性权限。Acquire 用既有 CacheImage 传候选 key，
SinkA 只对 Acquire 保留这个 hint；目录的实际内容 key 仍来自 final_meta_writeback。
Scheduler 选择 SourceD 请求时对候选 Seq 和 bank SW 做一次共享比较，将一位
CacheRecoverySafe 随 SourceD 现有请求流水冻结。publishPending 继续阻止响应
越过安全历史发布。MSHR 在首个 Grant fire 时按这位证书选择：真则使用真实
一致性数据，假则使用前驱；Main 当前 SW 不参与分类。选择复用 recoveryActive/data
保持，后续 SW 改变不会切换安装中的 payload/key，多拍证书须一致。DCache
refill/install 直接接收这一结果。缺失证书的 recovery Grant 触发 assertion。

计划重基的 resume 还等待空 EVT 和 SW 在所有域完成确认，及三个收据事务返回低。普通容量维护保留旧 Seq 和 SW。详见 Seq32_CDC_Rules.md。

Core 和 R_IC 都以 recoveryStop 禁止恢复期间的新 snapshot，最终 restart 拍仍
保持该禁止。Controller 的 RSU 排空输入复用既有 `snapshot_rsu_prev` 寄存器：
上一拍 busy 为低且停核期间没有新的 snapshot，证明原 capture、merge 请求、
延迟及流传输均已结束。原实时 busy 包括同拍 snapshot offer，不能直接经 restart
和 SCP release 反馈到准入。DCache/LSU 与 Checker owner 条件保持实时检查，新
Probe 仍能撤回 restart。snapshot 的 redirect guard 保留原最终 IFU 检查。

I/O边界的 `closeAfter` 在设备指令退休后保持年轻指令的退休暂停。
后置快照的物理就绪条件复用LSU `ioIssueReady`：已提交STQ前缀排空、
DCache ordered及HellaCache idle。年轻未提交store属于后续段，不能用全STQ空
阻止当前后置封口，否则它们与退休暂停形成等待环。已有ECP快照、RSU传输、
producer seal和safe覆盖effectSeq的顺序继续保持。V6修复的真实整核验收见
[I/O封口记录](../../Debug/bugs/bug-palimpsest-io-seal-cancel.md)。

会话结束也遵守包owner生命周期。原实现只在Checker侧见FINISH且packet_ingress_empty即允许软件退出；正常Sv39实测仍有package_start_pending的包尚未COPY，软件已退出并恢复管理寄存器，最终progress timeout。当前GHM源端以finishPending && forwardDrained约束FINISH入队，复用包释放、END/count与源FIFO空收据。Checker必须完成最后包并交付结果，Main释放槽后才会看到FINISH。它不改变恢复FSM，也不使用新的跨域busy信号。

held Error拉起stop时仍可能有前拍执行单元返回。LSU统一丢弃尚未获得内存owner的exe_req.valid；原已接受响应和已提交prefix仍收尾。stop与执行offer五类定向及正常load控制已在LsuRecovery运行通过；最终固定来源组件/整核验收仍以本批结果为准。

本批四处接口修复的完整C/E功能验收已通过：正常/Fault8异常I/O严格配对、
原Sv39 normal/Fault8精确物理/提交联合、CLINT写Fault18和uncached AMO
Fault18，以及Seq16完整23次物理重基。每项都有raw0与独立完整oracle，
全部五项计分0汇总在reviewed_control_milestone/result.json。原批次driver
因旧Sv39物理次数假设和主动停止的冗余输出运行返回1，失败记录保留。
实际Fault读取18次含2次SCP恢复废弃，存活严格16次，废弃数据也逐项检查。
后续L1 finite-slot三处nextSlotEpoch和GHM源端请求注册已按独立反例/候选
合入，生产组件与组合Seq16已独立验证其新来源：完整23次真实重基、新Seq1逐次PASS，生成/构建/raw/严格oracle全0，见recovery_integration_closure.json。


2026-11-24：设备owner存活期与journal安全共同决定interruptHold及重基准入。ACK前live owner已经承担pending；恢复后journal仍负责原值/ACK重放，禁止第二次外部A。只有live事务终结且journalSafe使pending解除后，MSIP才由现有Rocket CSR/ROB机制进入handler。旧完整程序的重复trap反例与最小修复在bug-palimpsest-io-owner-interrupt-gap.md，最终整核严格验收已通过。
