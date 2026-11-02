# 下一步：MOVE_TO_NEXT_OFFLINE_BOTTLENECK

`COMMANDS_FOR_USER=[]`；无run launcher或硬件patch。尚未同时满足>=100k independent critical UB、清楚运行root cause、低中复杂度fix，不准备Opt5 run，不跑A′/新B/diagnostic-only。

**本轮终止的是“outer A packet锁跨整个drain/ACK”和“仅压缩intrinsic gaps即可做Opt5”的方向。** 保留真实但未计量的间接链，下一离线目标为 **其他cache-transfer仲裁：SourceC借口在checkpoint waitAck期间的全局预约 → 无关dirty victim Release → 同MSHR Acquire**，随后L2入口C优先HOL/SourceD服务。再不足才查BOOM/checker资源backpressure，frontend最后。

下一离线审查应证明SourceC在waitAck使用borrow端的安全边界：检查所有pipeline/hazard与下一capture重drain，建立小范围状态/资源依赖而不生成硬件；只有出现可信预算才将功能改动与诊断同版本准备一次正式run。当前成功日志不足以恢复真实episode，不循环要求同一missing trace或追加观察run。

## 最小bounded instrumentation设计（未实现/未运行）

以本L2 scheduler 200MHz域计数，一次ROI完整边界snapshot；candidate-wait、drainRequested、engineActive/targetSetLock、outerPacketLock分开。packet episode以首A accepted建立序号，末A accepted结束；engine episode以capture/terminalACK结束，分别关联CachePreserveTxn，不能将两者duration混用。

固定资源建议：32或64个64bit counter，32bin hist，top20最长episode（约20×若干64bit字段，payload不记录），2个normal-source request serial/待发记录，1个checkpoint active记录；overflow/censor/unknown身份明确计数，不做全局cycle dump。

必须导出：

- UB1 active/pending、unsafe-watermark wait、runnable drain的duration及各等待SourceD/C/SinkC/quiescent原因mask。
- UB2 `packetLocked && normalHeadValid && downstreamReady`及原始`packetLocked&&normalHeadValid`，与外部ready-low分别计，slot union不重复。
- packet start/end/max/hist；held invalid gaps按read-wait、fixed delay1/2、send ready-low、最后beat等类别分开；frame内distinct head serial和FIFO count/highwater，不能每valid-cycle算unique。
- SourceC路径专用：`waitAck && sourceC candidate(other set) && otherwise_resources_ready`、global lock blocked cycles、victimMSHR `!s_release`或`!w_releaseack`阻Acquire的duration、eventual source/txn。
- 内层入口：selected C locked且另一个A原本可admit的机会；bank各client valid&&!ready与更高priority交集，包含noop reservation。
- UB3/UB4及去重：ROB实际head token/等待谓词，与packet/drain/SourceC限制exact联合计数和union。checker请求需source→requester package→finish/result acceptance→BOOM ownership链；不能用CacheImage seq当请求者。
- top20包含capture/drain-ready/selected/first&lastA/terminalACK/firstbank、set/oldImage key/source/txn、blocked request serial集的计数、原因、head/scheduler/retry交集。所有字段区分有无观察与ROI boundary censor，跨reset拒绝join。

held request与LSU retry是不同概念；若要RETRY_AMPLIFICATION需token关联并输出分母0/未知。对head overlaps输出raw、nested union、经过依赖确认的独立可删候选，不能只靠overlap宣称speedup。

这些仅是与未来已成立功能候选同版的诊断规格；当前不为收counter启动硬件，不扩cache/MSHR、不改frontend、不做SVB32/promotion。
