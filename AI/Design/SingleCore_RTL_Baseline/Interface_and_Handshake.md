# 接口及握手

当前验收（2026-11-24）：69项功能VERIFIED；当前5模型/12完整程序/31负例与严格联合评分全部PASS。来源、范围和独立物理状态见[系统验收](System_Acceptance.md)。

| 路径 | 接收条件和释放条件 | RTL 定位 |
|---|---|---|
| Main producer → Checker | `packet_alloc_valid` 给新 Seq，`closing_valid/seq` 保持到 RSU capture、merge 和 GH_BUF seal。数据/空 anchor 先于 ARF 及 END。 | R_IC `snapshot_accepted / final_pending`，BoomTile `producerSeals`，GHM `empty_anchor_en / send_end` |
| Checker COPY / custom JLR | 普通 COPY 只在存活的待启动包、CPS ready 和 R_ICSL clean context 同拍准入时写寄存器。已取消包的迟到 COPY 不粘贴，紧随的 custom JLR 返回 pc_special 重新轮询。管理上下文恢复走原 store_from_checker COPY。 | RocketCore `checker_copy_allowed / checker_replay_owned / icsl_copy_start_accepted` |
| Checker result → Main | Rocket 在本地清理完成后允许 result 入 CDC；包括 RSUSL core_hang_up=0，等待快照复制的 RAM 读出及寄存器尾拍。GHM dequeue 产生结果 pulse，release 保持到 Main 清掉原槽的 status。 | RocketCore `package_result_handoff_allowed`，GHM `result_release_pending`，R_IC `package_owned` |
| Held Error → Controller | DCache 只接受有效且精确 tag 匹配的结果。最早 FAIL 从 held Error 交给 Controller，支持重选更早 SCP。 | dcache `errorPending / earliestFailure`，PalimpsestRollbackController `earlier` |
| EVT → L2 / Checker | Main 用 `installOnly` 持有安装请求。各 bank 接收后同拍更新本地和 Scheduler 的 EVT 并保持 ACK，即使 C 或外写在途。每个 Checker 安装后保持自己的 ACK。Main 收齐 ACK 高才降 request，ACK 全低才复用邮箱。 | dcache `historySync / historyAllAccepted / historyAllLowered`，InclusiveCache `historyQuerySent / historyAck`，Scheduler `recoveryContext`，PalimpsestHistoryReceiver |
| Lazy Recovery → L2 / SVB | 地址查询复用同一邮箱，`installOnly=0`。L2 等待 C staging 可见并完成该地址的 History 扫描后才保持结果与 ACK，DCache 与 SVB 结果合并后降 request。 | Scheduler `historyQueryClear`，PalimpsestVersionHistory `queryScan / respond`，dcache `recovered.fire` |
| 内层 C → Scheduler / SinkC → History | C 队列接收协议拍，SinkC 实际准入时才取得 staging owner。完整 authored 行在末拍后等待 History 收下，下一笔 C 此时停在队列。安全 History 覆盖的旧同址 Probe 保留 C 终态，省去已被覆盖数据的重复归档。 | Scheduler `bufferedC / historyCPartial / historyCPending / pendingSafeBaseline`，SinkC `probeAllow` |
| SVB → L2 | archive request 携地址、key、完整字节。L2 capture.fire 接管 buffer。ACK 返回原 key。SVB 原 `WB_WAIT` 保持至 exact receipt，之后等待 ACK 拉低再复用 mailbox。 | dcache `archiveState`，SVB `releaseBlocked`，InclusiveCache archive mailbox |
| L2 → DRAM | 保持 set lock 和原事务，最后一拍和真实 matching AccessAck/ReleaseAck 结束外部 owner。History Put 的锁还覆盖目录收据。 | L2Preservation `snapshot / serial / sent / baseline`，MSHR `releaseSnapshot / releaseIssued` |
| L2 → Main 封口 | 有效的待验证 Seq 大于 SW 且仍存活时，bank 保持该 Seq 的封口请求。SW 覆盖目标或 EVT 将目标作废后释放。SourceC 按 Scheduler 对实际 victim、发布顺序和 owner 的检查发射。 | InclusiveCache `barrierCandidateUnsafe / barrierSeq / barrierReleased`，Scheduler `stage3Allowed` |
| Main 容量封口 owner | 请求 Seq 必须匹配 R_IC 的实际 `traffic_package_open` 和 activeSeq，才能启动 capacity 保持。会话结束仍保留 activeSeq，迟到旧请求只走 R_IC 已关闭包 ACK，不能等待不存在的 successor。 | Core `barrierCloseForActivePackage / capacityStart`；R_IC `barrierAlreadyClosed`，INV-23 |
| Restore → Restart | Controller 持有 SCP，直到 int/FP PRF、rename、CSR、ROB 完成并且 DCache/跨域维护 ready。恢复许可可因新 Probe 撤回，最终 fire 必须同时满足实时 quiesced 与 checkpointReady。`restart.fire` 才释放 SCP 和恢复 PC。 | core `rollback.io.restored`，Controller `restart.valid`，PalimpsestContextMemory `pinned` |
| I/O 后置 ECP → 快照/封口 | I/O退休后保持年轻退休暂停。复用LSU `ioIssueReady` 等待已提交STQ前缀、DCache ordered及HellaCache idle；年轻未提交项可继续占据STQ。随后按原快照/RSU/GH_BUF握手封口，安全水位覆盖effectSeq后才释放退休。 | Core `ioBoundary.io.postReady`，LSU `ioIssueReady`，PalimpsestIoBoundary `closeAfter / waitAfter`；INV-21。V10正常/Fault8/Seq16异常MMIO通过；当前最终源码五配置完整重验已通过。 |

Seq32 重基期间，DCache 持有 PALIMPSEST_SEQ_TRANSPORT_REQUEST。GHM 等每个 Checker 域清理收到的序号并返回 ACK，再清 BOOM 域的发送标签。归零后的 DCache 另持有 PALIMPSEST_SEQ_WATERMARK_REQUEST，每个 bank 在物理维护状态下观察同步后的 SW=0 再确认。两项收据和原 EVT 邮箱都执行完整四相握手。

Rocket 的清标签收据与下一包执行准入分开：R_ICSL `package_idle` 证明包 FSM、包内 trap/depth 和待返回 owner 都已空，RocketCore 另汇合 RSUSL、LSL、前端和结果 owner；此时可接受 Seq reset。`context_idle` 还要求架构异常返回，仅它允许 admission、COPY 和结果交付。维护期间发生的无包管理异常不使用包标签，继续保留原异常状态，待 L2 解除新 A 冻结后走原 handler/xRET。

Acquire → Grant 的恢复 hint/证书：BOOM A.CacheImage 携带候选 key；SinkA 仅对 Acquire 保留。L2 MSHR 只输出候选 Seq 给 Scheduler 的共享比较器，不将 hint 贴给目录字节。Scheduler 在实际 SourceD 选择时以 bank SW 生成 D.CacheRecoverySafe，一位结果随现有 SourceD 请求流水冻结。L1 首个 Grant fire 固定恢复选择，后续 beats 检查证书一致；缺失证书不能静默通过恢复。实际 D.CacheImage 仍描述真实一致性字节。

恢复 CSR 时，BOOM Core 与 LSU 分别向取指和数据侧发全量 SFENCE，Core 同时将它送到 PTW。已握手的旧遍历保留 owner，直到收到 PTW 响应。两个 TLB 在等待旧响应期间保留 `s_wait_invalidate`，将同拍 SFENCE 一并计入 `invalidate_refill`。旧响应仍令查询重试和释放 owner，三类条目均禁止写入。共享 Rocket TLB 的 GPA 副数据也受该条件约束。详见 [迟到翻译记录](../../Debug/bugs/bug-palimpsest-translation-refill.md)。

本批新增明确约束（生产实现已落地，当前固定来源回归中）：

- 会话FINISH不是DATA/ARF收完：GHM的finishPending等待同一个Checker的forwardDrained，再入session AsyncQueue。START不依赖包完成；FINISH继续保持原epoch匹配及电平状态。R_IC直到精确result release才清checker_segment_id，故等待同时覆盖尚未COPY、正在执行和Main尚未释放的最后包。
- Main stop到LSU：先广播SFENCE再屏蔽全部exe_req.valid，避免在途返回被can-fire屏蔽但仍留下未消费Valid。已接受owner和已提交prefix继续原独立终态路径。恢复SFENCE仍走rollbackReset。
- 未提交uncached AMO：其STQ地址可能在前置屏障前生成；设备请求与fire后STQ.packet_seq均使用授权时的active_packet_seq，保留functional_token。cached AMO和普通store原规则保持。
- uncached AMO两种收据：IOMSHR响应携旧值，completionQ.store_done只释放STQ，不能再次写回ROB；cached AMO仍从terminal获得唯一响应。

对应INV-24/25/26及执行停止/I/O交接根因记录。

上述C/E四个生产接口修复现有完整证据：正常/Fault8异常I/O严格配对、
原Sv39正常/Fault8、CLINT写Fault18、uncached AMO Fault18及11真实组件均
通过。AMO效果包Seq18与journal一致，IOMSHR唯一响应和STQ terminal职责
已在真实ROB运行闭合，设备效果至恢复重放仅一次A。更广重基/中断并发
仍以独立任务边界验收，详见io_barrier_closure.json和验证矩阵。


CSR replay：普通Checker的MSCRATCH/SSCRATCH显式W/S/C将结果写入现有architectural shadow，读改写旧值使用同包CPS shadow。普通物理CSR更新/读视图和MPRV不变；priv replay仍使用已有shadow，management更新不污染它。该最小实现已生产合入并通过12命令、SSCRATCH ECP及management/MPRV测试。此前覆盖所有CSR的宽路由候选已经因Sv39 watchdog否决，不能作为生产行为。

容量封口：`R_RSU.rsu_busy=0`不保证GHM CDC已接受或BoomTile已建立producer seal。
生产`capacityClosing`在RSU idle且已有`producer_seal_ready`确认后才释放，沿用原Seq匹配。
25MHz完整程序已实际达到History64/64、回收并最终free64及完整checksum通过；
新增Scheduler修复后的同程序另行重验。来源和原反例均见验证矩阵。


2026-11-24 连续设备 owner 责任：`BoomIOMSHR.io.effectPending` 从受保护请求接受后的 live state 开始，覆盖 A 背压、D 延迟和响应终态，再由 retained journal 继续持有至 `journalSafe`。`busy` 仍只表示 live state，journal 不重新成为 drain 依赖。Core 原 `interruptHold` / rebase 读取同一 pending，不增加跨域握手或 owner 存储。整核验证状态见验证矩阵。


外层GrantAck与同组抢占：`mshr_request.grantAckOnly`要求E有效且A/B/C/D/X/dir/park均无效，才可越过同组C/BC interlock；SourceE、轮转仲裁、stage3Allowed仍适用。History排空继续等待实际E握手，不能伪造baselineOuterReady。长期测试见baseline_publication `--suite grantack-preemption`。
