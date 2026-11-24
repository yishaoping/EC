# Seq 重基的 transport 收据与管理异常上下文

状态：循环等待已证实；V4 生产 RTL 已实现最小修复，验证进行中。

证据根目录为 `AI/TMP/singlecore_checker_20261122_082540/`。V2 的独立整核
运行在 `reviewed_v2/seq/`，tick496000 触发 Main pipeline watchdog，exit1，
没有 Seq reset/restart。V1 归档模型的只读 `eval_step` 探针分别保存在
`seq_maintenance_probe_v1/`、`seq_transport_detail_v1/` 和
`seq_trap_lifecycle_v1/`。各版本不得互作验收。时间单位为 emulator 的
`sc_time_stamp()/trace_count`，每个完整高低时钟周期递增一次。

| V1 周期 | 观测 |
|---|---|
| 254295 | 所有旧 Checker 包释放后，Main 拉高 maintenanceRequest。 |
| 258717 | hart3 在没有包/结果 owner 时进入架构异常。 |
| 267327 | hart2 在没有包/结果 owner 时进入架构异常。 |
| 355009 | L2 扫描结束后，Main 拉高 transportRequest。 |
| 355025 | 四个 GHM localCleared permit 均为1；hart1/4 发起 packetSeqReset。 |
| 355027–355029 | hart1/4 保持 ACK，GHM 对应 localCleared 成立。hart2/3 无 ACK。 |
| 449536 | hart2/3 仍 excpt_mode=1、arch_trap_depth=1；context_idle 和 reset_ready 为0。 |

选定信号和终态保存在 `seq_transport_detail_v1/selected_evidence.json`。
该探针以450000拍上限退出2，是诊断运行，不能记为通过。

已证实的立即阻塞：RocketCore 将 `packet_seq_reset_ready` 与
`checker_local_cleanup_done` 相与；后者要求 R_ICSL `context_idle`。
`context_idle` 同时表示包 FSM 已空以及架构异常已返回。hart2/3 的
RSUSL、LSL、前端清理及结果 owner 均已空，但架构异常仍存活。

上游循环等待由生命周期探针和源码共同证实：Scheduler 的
`maintActive` 在 maintDone 仍为真，停止新的内层 A；Main 必须先取得
transport ACK 才能降低 maintenance。若空闲 Checker 的管理 trap handler
在维护期间发起真实访存，等待其 xRET 才清传输标签会形成闭环。
`seq_trap_lifecycle_v1/selected_evidence.json` 证实：hart3 的 R_ICSL 一直处于
nonchecking，258715 发出异常后 WB 停在管理轮询 PC 0x800034c0；hart2
267325 发出异常后 WB 停在 handler PC 0x8000014c（csrr mscratch，后续
要保存 trap frame）。到278528仍没有真实 insn_ret。两者都没有包 FSM 的
trap/resume owner；新 handler 访存/取指被维护屏障阻塞。WB PC 只能定位
已到流水线的边界，未单独采集具体 I/D A 请求，不据此区分首个阻塞通道。
该280000拍诊断运行同样以超时 exit2 保存。

修复设计：包 admission、COPY、结果 handoff 仍需完整的可执行异常上下文。
传输标签归零只需证明旧包 FSM、trap/resume/return、RSUSL/LSL/前端及结果
owner 已终结，并取得 GHM 的完整 FIFO 空证书。无包 owner 的管理异常若
不使用包标签，可以保持自身 CSR/PC/异常状态，等待维护释放后正常完成。
不得为了取得 ACK 清除 excpt_mode、伪造 xRET 或放宽 Main watchdog。
R_ICSL 已复用既有 FSM/depth/return 状态输出独立的包空闲条件；RocketCore
只在 Seq reset 收据中采用该条件，其他准入和结果路径继续使用 context_idle。
不新增寄存器、队列或 FSM。完整 RTL 回归仍须确认 reset→Restart→Seq1 及
管理异常正常返回，组件通过不能代替该整核验收。

修复前组合反例为 `seq_management_before_v4_retry/`：生产 GHM 与 R_ICSL，
管理异常一直保持，所有源端 FIFO 都可排空，但旧 context_idle 门控使 hart1
无法 ACK，cycle4455 exit1（其余活动端 ACK=6）。最初夹具 import 使用了
新版本 Chisel 路径，编译失败保留在 `seq_management_before_v4/`；重试的首次
Verilator 调用缺少 `-y generated`，失败日志亦保留，`build_retry.exit=0`
才产生上述反例。它们属于工具调用错误，不能当作 RTL 反例。

V4 长期 SeqTransport 额外检查包内异常、取消、匹配 xRET、special-PC 返回
分别对清理的约束。全部组件在 `rtl_regression_v4/`，三配置整核在
`*_rtl_v4/` 构建；在实际完成前均不得写 PASS。源码修改前见 `before_v4/`
与 `v3_generation_checkpoint/`，修改后初始清单为 `sources_v4.json`。

V4聚焦组合已通过：`seq_management_v4_focused/run_corrected.log`/`.exit`为0，
两个新增CASE与既有CDC全部PASS。首次激励把self_xcpt保持跨两个Checker上升沿，
实际形成深度2，因预期1失败；失败源码与日志保留。只改激励为单Checker边沿
脉冲，链接同一V4硬件库后通过，未再修改RTL。长期输入已同步。完整组件driver
与整核driver原先捕获了旧激励哈希；其末尾比较失败将保留，由独立核验运行确认
全部生产源码前后相同、只存在这一个C++变化，不将它记作硬件失败或原driver通过。

V4完整整核结果已回收，来源核验和日志在
`reviewed_v4_fullcore_frozen/`。compact Seq16运行与严格计分均exit0，
真实发生两次目标→标签归零→Restart→首个Seq1→Checker PASS，最终架构
checksum与正常运行一致。普通/Fault8 compact配对亦通过。异常与I/O
profile仍因额外普通包取消而严格计分FAIL，与本等待环分开跟踪。
V4 FIR在生产V5翻译修复之前已记录哈希，原source-cmp失败和后续已知差异
全部保存。不得把V5工作树当作V4生成输入。
