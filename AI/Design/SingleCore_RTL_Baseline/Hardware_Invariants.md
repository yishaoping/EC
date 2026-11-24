# 硬件不变量

当前验收（2026-11-24）：69项功能VERIFIED；当前5模型/12完整程序/31负例与严格联合评分全部PASS。来源、范围和独立物理状态见[系统验收](System_Acceptance.md)。

| ID | 可检查约束 | 逻辑 / 检查 |
|---|---|---|
| INV-01 | 存活 Seq 的安全前缀逐拍跨过 PASS 或已安装 EVT 的 tombstone。 | DCache `newSafePacketWatermark`、`historySync`；Recovery / Hierarchy。 |
| INV-02 | 安全基线不被错误内容覆盖。同址待发布或已确认的安全行可代替被覆盖的旧行，旧行不得在其后再次发布。 | Scheduler `stage3Allowed / trustedQuery / pendingSafeBaseline / historyCCheckFire`，MSHR `residentHasSafeCopy`，`L2_SPEC_OUTER_WRITE_ERROR checkpoint`。Baseline 等实际 ACK，检查迟到 Probe/ReleaseData、外存字节、旧命中重取和发布次数。 |
| INV-03 | 旧事务 owner 到 matching terminal receipt 后才能释放。C 队列中的 Probe 首拍在 SinkC 准入之前不拥有 staging。 | SVB `WB_WAIT / ack`、MSHR `releaseIssued / baselineOuterReady`，`L2 history publish ACK identity mismatch`。Baseline 检查两拍队列和背压下的终态，Svb、Identity 和 Hierarchy 检查其余 owner。 |
| INV-04 | Main 等 Checker 真正释放，序号新旧过滤与数据、ARF、END 对齐。 | GHM `result_release_pending`、R_IC `package_owned`、RocketCore `package_ready_for_new`；CheckerRecovery。SeqTransport 验证请求、结果释放、跨域空收据和 ACK 高低。 |
| INV-05 | EVT 安装回执独立于 C、外存终态与历史扫描。EVT 生效前 SW 不跨空洞，Main 等各域 ACK 高和低。 | DCache `historySync / historyAllAccepted / historyAllLowered`，InclusiveCache `historyAck`，Scheduler `installOnly`，HistoryReceiver。Hierarchy 停慢 Checker，并在扣住多拍外写时检查 FAIL8 到 FAIL7 的两次安装。 |
| INV-06 | 恢复从 pin 的 SCP 取数据，各实际 owner done 后才重启。 | `restart without reconciled transaction/SCP`、`pinned SCP reclaimed before restore completion`；Restore / Recovery / CheckerRecovery。 |
| INV-07 | 物理 owner 与 compact 互斥，普通恢复保留 Pending 旧前缀。 | DCache `maintenanceLocalDrained`、`EVT maintenance certificate left a physical L1 resident`；Hierarchy 检查 Figure 4、外部 ACK 和复数维护。 |
| INV-08 | I/O 未验证前无外部副作用，已有真实效果重放无第二次发射。 | `PalimpsestIoBoundary`、IOMSHR journal 和 `I/O issued before its committed prefix validated`；Io / IoBoundary。 |
| INV-09 | 精确异常须等较老指令退休。stop 阻止废弃后缀投递。恢复后 handler 和待发边界等于 SCP，重执行到异常指令时只投递一次。 | ROB `block_xcpt / palimpsestRecoveryStop`、Core CSR gate、`PalimpsestTrapTracker`、R_IC `boundary_priv` 和 R_RSU `crt_mode`。PreciseException 覆盖生产 ROB、tracker 和 SCP RAM。对应完整IRQ、Sv39及恢复/外设交叠最终验收见System_Acceptance.json。 |
| INV-10 | 满资源时 Main 停车并释放 MSHR/set。History 压力触发封口请求，已满足发射条件的安全 Checker victim 可在 SW 不变时完成外写。 | Scheduler `clientWait / stage3Allowed / mshr_request`、MSHR `capacityIsolated`、Directory escape way、InclusiveCache `barrierCandidateUnsafe`。Pressure 核对四拍 Probe 后停车，以及 BASE 脏 victim 的真实外存写和 Checker Grant。 |
| INV-11 | 最后一次恢复的有效候选按地址合并，失败段的整行不会恢复。冷查结果跨 LSU 重试空窗保留，并仅供匹配地址的 refill 使用。 | DCache `recoveryFound / recoveryMiss / ingressRecoveryLine；BoomMSHR recoveryLive / responseRecoverySafe`、SVB/L2 查询、MSHR recovered install。Hierarchy 断言 A7、相邻字节及 800 拍后同址重试。 |
| INV-12 | f0 比较必须参与结果，x0 不产生虚假的不一致。 | RSUSL `checker_farfs_snapshot` 及 compare；F0 / CheckerRecovery。 |
| INV-13 | SW 和 Seq 只在缓存无旧 owner、GHM 已清各域标签时归零，空 EVT 和 bank SW 收据完成后才重启。 | DCache sequenceReset / releaseAfterReset，GHM forwardDrained / localCleared，InclusiveCache watermarkStable。SeqTransport 与小上界整核配置。 |
| INV-14 | 待重放的 I/O 效果可继续执行并结算，计划 Seq 重基只能从无未结效果的检查点开始。 | Core `reservedCheckpoint` / `request.valid`，IOMSHR `journalReplay` / `effectPending`。Io 覆盖日志跨两次恢复；完整IoRebaseCompleteProgram已真实通过8次reset/新Seq1 PASS、48设备读及9个负例。当前Core/CSR/连续设备owner来源的完整8次重基也已通过，新增Scheduler来源已完整复验通过。 |
| INV-15 | SVB 有空间且前驱身份匹配时，缓存 AMO 可在前驱仍 Pending 时完成。前驱整行先入 SVB，AMO 恰好写一次并返回旧值。 | DCache `svbEligibleCandidate`、`svbCaptureResidentMatch`、`s3_svbOwnsPredecessor`。Hierarchy 检查 SW=6 时的跨段 AMO 及 FAIL8 后的相邻字。 |
| INV-16 | 失效包的迟到 COPY 不得改写管理寄存器，其 custom JLR 不得进入未校验的 Main 控制流。复制尚在进行时不得释放结果或清序号。 | RocketCore `checker_copy_allowed / checker_replay_owned / checker_local_cleanup_done` 复用存活包、R_ICSL context_idle 和 RSUSL core_hang_up；`Checker COPY modified registers without accepting its live package` assertion。Seq16 原始反例和修复回归见 CheckerCancelBeforeCopy。 |
| INV-17 | 冷查询的旧候选不得覆盖查询后生效的可信写。候选 payload 与 key 必须在取得一致性权限后固定，安装期间不能因 SW 变化切换。 | BoomMSHR `recoveryLive / responseRecoverySafe / grantFirst / recoveryActive`；DCache 使用 MSHR 已选定的 refill/install；Scheduler `stage3Allowed` 持续等待 publishPending。Hierarchy 的独立 host client 检查 fromhost=1、tohost=0，并覆盖查询后 SW 推进。L2 的 CacheRecoverySafe 必须随响应冻结，Grant 已排队后 Main SW 推进不能丢失前驱。新反例 cycle1037 及 V2 证据见可信写故障记录。 |
| INV-18 | 冷查询完成后，不同冷地址的接替必须在 owner 空闲的当前拍锁存。不得因 LSU 对未接受 offer 重新仲裁而无限重发空查询。 | DCache `recoveryMiss / recoveryCacheIdle / beginColdLookup`；Hierarchy `alternatingColdHandoff` 要求接替访问和原地址均完成。V2 原反例 8000 拍内 51 次查询、零接受，修复后验收另存 V3 证据。 |
| INV-19 | 清 Seq 标签须终结所有旧包 owner，但不得依赖维护冻结所阻塞的无包管理异常返回。管理异常、包内 trap 和待 special-PC 返回不得被 Seq reset 擦除；下一包仍等完整 context_idle。 | R_ICSL `package_idle / context_idle / trap_depth / return_pending`，RocketCore `checker_storage_idle / packet_seq_reset_ready`。SeqTransport 纳入管理异常保持与包内 trap→取消→xRET→special-PC 返回场景；修复前组合反例 cycle4455 FAIL；V10异常/I/O完整程序23次reset→Restart→Seq1 PASS；session FINISH的pending包缺陷已修，SeqTransport及23次整核重基通过；新增Scheduler来源已完整复验通过。 |
| INV-20 | 恢复 SFENCE 作废在途页表遍历的数据。其响应只能完成旧 owner，不能填回 DTLB、I-TLB 或 GPA 副数据。恢复后的 miss 必须重新遍历。 | BOOM `core.scala` 和 `lsu.scala` 发全量 SFENCE，DTLB 和 I-TLB 用 `s_wait_invalidate / do_refill / invalidate_refill` 控制三类条目写入。`TranslationRecovery` 复现旧普通页与非同质页错误命中，验收旧 owner 收尾和新物理地址。PtwRecovery 使用真实生产 PTW 核对 fence 后缓存失效，实际页表读取新映射与正常缓存命中。 |
| INV-21 | I/O 后置封口等待已提交前缀及真实物理 owner，年轻未提交 STQ 项不得与 retirementHold 形成循环等待。未完成设备和已提交 store 仍必须阻止快照。 | Core `ioBoundary.io.postReady := io.lsu.ioIssueReady`，LSU `stq_head === stq_commit_head / dmem.ordered / hella_state`，STQ `clear_store`。V6正常/Fault8严格配对、Fault40联合验收和Seq16的23次重基后完整程序通过。IoBoundary组件只覆盖输入协议，不证明Core接线。 |
| INV-22 | Restart 的实际握手同时满足当前 owner 排空和 SCP 有效；先前 drain 确认不能替代最终条件。新 Probe 期间继续保持 stop 和 SCP pin。 | PalimpsestRollbackController `restart.valid` 与原 restart assertion；Recovery `restart_rechecks_late_owner`，Hierarchy `realTrackedC`。V7/V8历史组合环FAIL保留；Core复用原snapshot_rsu_prev后V9真实整核FIRRTL通过，V10正常/Fault8/Seq16异常MMIO完整回归通过。停核禁止新snapshot，缓存/LSU/Checker owner仍实时重查；当前Scheduler修改后五配置组合重验已通过。 |
| INV-23 | 容量封口只有匹配仍开放的实际包 owner 才能保持退休；检查会话关闭后的保留编号不能成为新 owner。迟到已关闭包请求仍须按原协议确认。 | Core `barrierCloseForActivePackage / capacityStart` 汇合 R_IC `traffic_package_open`；R_IC 保留 `barrierAlreadyClosed` ACK。V6 Sv39 Fault8 在 tick559795 的 producer_open=0、protected=0、activeSeq=35 时错误启动保持。V10 owner门控已落地，同一Sv39 Fault8完整通过；正常Sv39后续FINISH缺陷（INV-24）已修并完成原ELF回归；新增Scheduler来源已完整复验通过。 |

本批生产代码实现以下约束；组件和完整Core的最终结论见验证矩阵，不能以代码存在替代动态PASS。

| ID | 可检查约束 | 生产依据及验收 |
|---|---|---|
| INV-24 | 会话FINISH不得越过未COPY/未执行/未释放的Checker包。 | GHM session enq.valid使用finishPending && forwardDrained，R_IC保留checker_segment_id直到result release。SeqTransport扣住ingress/result/Main release；原正常/Fault8 Sv39 ELF已通过；新Scheduler来源完整复验也已通过。 |
| INV-25 | stop当拍在途执行offer未取得owner时不再进入LSU调度；已接受owner继续真实终态。 | LSU SFENCE广播后屏蔽exe_req.valid。LsuRecovery真实LSU覆盖load/STAD/STA/STD/SFENCE及正常load控制；整核正常/Fault8/Seq16。 |
| INV-26 | uncached AMO效果归授权时的新包，旧值响应恰好一次，回滚不再发设备A。 | LSU uncachedAmo与既有STQ.packet_seq；DCache completionHasResponse；IOMSHR journal。完整Core正常/Fault18的16轮实际AMOADD/read、原值/回读/重放链由--require-amo严格计分，既有16写/16回读--require-output同时保留。 |

物理实现另有必须保持的检查：跨域单bit条件先在源域注册，接收链保持
分立同步寄存器，不能映射成SRL；源端Gray寄存器到第一同步级仍需偏斜/
最大延时约束。GHM同top生产综合已消除4项组合前置CDC-10与4项SRL CDC-13；
1742项AsyncQueue数据CE warning仍未签核。具体边界见Seq32_CDC_Rules，
不能把GHM OOC综合或数字PASS当作完整Core物理CDC签核。


普通Checker的MSCRATCH/SSCRATCH shadow W/S/C必须基于同包CPS旧值；仍保留原物理CSR更新/读视图与MPRV，management不污染shadow。最小生产实现已经通过两个scratch×normal/priv×W/S/C的12组合、SSCRATCH ECP及management隔离。旧owner来源normal完整程序写回FAIL保留；当前Scheduler来源的normal/Fault18完整IRQ与16精确trap/xRET、checksum、14负例均通过，P2-07/P4-10已按完整证据关闭。

容量前缀快照保持覆盖架构capture至producer seal receipt，RSU idle不等于已封口。
生产使用原`producer_seal_ready`延迟`capacityClosing`释放；完整25MHz程序已通过
Seq1 END/count64、History64/64→回收/推进→finalfree64与checksum。
P4-12已凭完整证据关闭；新增Scheduler来源完整压力回归独立进行。

### 设备 owner 的连续中断责任 (2026-11-24)

IOMSHR 接受一个受保护设备请求后，从 `mem_access`、`mem_ack`、`resp` 到 retained journal 通过安全条件，`effectPending` 必须连续为真。只保护 `journalValid` 不充分：设备 A 可先改变 MSIP，D 才安装 journal。实际源码为 `inFlightEffect || (journalValid && !journalSafe)`；复用原 Core interruptHold/rebase 接线。RD/WR/AMO 的延迟 A/D 和两次重放组件已通过，原 ACK 前 pending=0 反例已保留。当前owner来源的精确16 MSIP trap/xRET局部与完整Fault40+Seq32已通过；新增Scheduler来源完整回归也已通过，不能据组件关闭 P4-10。见 `bug-palimpsest-io-owner-interrupt-gap.md`。

| ID | 可检查约束 | 生产依据及验收 |
|---|---|---|
| INV-27 | 同组C/BC抢占不得阻断History排空所等待的、仅含外层E的终态调度；所有数据/目录/park仍受原屏障限制。 | Scheduler `grantAckOnly` 与MSHR `baselineOuterReady`。真实旧组件在C→History→E循环失败，长期grantack-preemption组件通过；最终完整Core与严格评分均通过。 |
