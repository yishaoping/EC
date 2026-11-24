# PALIMPSEST L2 C 准入与同址发布

正常 v1 整核运行在进入受保护段前停止前进。实际缺少的是 `0x80007380` 的 Probe 响应终态。晚到的 BOOM watchdog 是后续症状。

| 事件 | 证据 |
|---|---|
| BOOM 开始 WB | [run.log:749468](../../TMP/singlecore_rtl_20261121_171154/fullcore03_loadmem/run.log#L749468)，DCache cycle `0x36fea` |
| L2 等保存脏 BASE | [run.log:749531](../../TMP/singlecore_rtl_20261121_171154/fullcore03_loadmem/run.log#L749531)，bank 0 / set `0x1ce` / tag `0x1000`，旧行 dirty 且未保存 |
| BOOM watchdog | [run.log:1394161](../../TMP/singlecore_rtl_20261121_171154/fullcore03_loadmem/run.log#L1394161)，BOOM cycle `0x77067`。DCache 快照仍留着相同 Probe、WB 尚未发送完成及等待 WB 的 MSHR。 |

整核 run 的源码版本见 [sources.before.json](../../TMP/singlecore_rtl_20261121_171154/fullcore03/sources.before.json)。该生成 RTL 的 Scheduler 从队列输入的 fire 开始设置 `historyCPartial`，SinkC 在队列输出依赖旧行保存许可，而候选保存等待 `historyCPartial` 清除。定向测试在生产 `fullC` 两拍缓冲下独立复现这条环，记录到队列满、SinkC 拒绝、保存引擎空闲且候选不可运行。该性质由旧生成 RTL 和定向运行共同确认。整核日志没有逐拍记录内部 staging 状态。

另两个反例涉及 History 正在选择或已确认新基线。

1. 安全 History 和同组 Probe 并发时，旧 drain 等整个组的 Probe 完成，但 Probe 先等 History。不同 tag 或较旧收据无需等 Probe。收据可能覆盖驻留行时，同址安全副本可先放行 Probe，较旧响应不进入 History。等 Probe 终态后再写 DRAM、收 ACK 和更新目录。
2. A7 完成外写和目录收据后，控制夹具让上层持原权限送回 A6 ReleaseData。旧 RTL 完成合法 ReleaseAck 的同时把 A6 再送入 History，使 DRAM 从 A7 倒退为 A6。旧的 `baselineObsolete` 只记一位，比较 A6 与目录原本的 A5 会丢失 A7 的身份。修复复用 obsolete 条目的 image 字段记录准确收据身份，并让 ingress 通过已有目录口检查。合法 C 终态仍结清。

前后证据及源码哈希见 [验证基准](../../Design/SingleCore_RTL_Baseline/Verification_Matrix.md)。协议影响见 [同址发布规则](../../Design/SingleCore_RTL_Baseline/Baseline_Publication_Rules.md)。

## EVT 安装在途外写期间的回归

加入迟到 C 收据后，Hierarchy 的已接受多拍外写用例在收到 FAIL7 后停在 Epoch1。夹具每拍只让 Main 走一次上升沿。周期 11940 发出 FAIL8 的安装请求，当时地址 `0x80108000` 的完整 C 行仍占有 staging，保存引擎处于 `send`。周期 12000 四个 Checker ACK 已全部为高，L2 的 `historyQuerySent` 和 `historyAck` 仍为零。周期 41952 仍停在同一状态并触发夹具超时。该反例对应 c_receipt02 的生成 RTL。[窄信号记录](../../TMP/singlecore_rtl_20261121_171154/c_receipt02_hierarchy_trace02/run.log#L1142) · [生成时源码哈希](../../TMP/singlecore_rtl_20261121_171154/c_receipt02/sources.before.json)

近因是 `historyQueryClear` 把安装请求当成地址查询，要求整条 C 先移交。此处的 C 和正在发送的安全外写同组，旧外写的 set lock 持续到终态。安装回执未返回阻止 Main 释放第一份请求，因而无法发送已接收的更早 FAIL7 对应的 EVT。相关信号在定向运行中已确认。该运行用外部背压固定住实际 owner，从而观察恢复协议本应允许的并行顺序。

DCache 在现有四相邮箱中用 `installOnly` 区分 EVT 安装与地址查询。L2 和各 Checker 捕获 EVT 后直接回执。C 归档、地址查询和旧外写继续走原有各自的终态条件。扩展后的 Hierarchy 在释放外存背压前要求第二次 EVT 的 ACK 完成高低两阶段，随后才检查 SCP7 重启及实际读数。[握手基准](../../Design/SingleCore_RTL_Baseline/Interface_and_Handshake.md) · [验证基准](../../Design/SingleCore_RTL_Baseline/Verification_Matrix.md)
