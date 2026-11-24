# 已接受设备 owner 到 journal 安装之间的中断空窗

2026-11-24。最小生产修复与最终来源5配置12完整程序/严格IRQ及31负例已通过，剩余4项已按完整证据关闭。下文保留原失败和修复前因果链。

`final_irq_gate/{normal,fault18}` 是 Core/CSR 两项修复后的完整整核运行，两边 raw exit 和工作负载 oracle 都为 0。加强 IRQ 计分仍失败：正常/Fault18 的 round 10..15 各多一次软件中断 trap。原“69 项关闭”结论提前写入，已撤回并保存在 `final_evidence_review/`。不能把 handler 计数 16 等同于 trap 次数 16，也不能把任意异常当作 MSIP trap。

直接信号链（该次正常运行的 emulator tick，Main 一周期一个 tick）：

| tick | 实际事件 | 含义 |
|---|---|---|
| 596130 | IOMSHR idle→mem_access，req Seq239 | 设备 owner 已接受 |
| 596131 | A fire，写 CLINT MSIP=1 | 外部中断可随即变为 pending |
| 596133 | CLINT pending=1 | 设备已执行 |
| 596134 | CSR IRQ=1、boundary=idle、journalValid=0、effectPending=0 | ACK 前存在中断放行空窗 |
| 596135 | D/install journal，effectPending=1 | 旧 pending 定义此时才开始 |
| 596146 | trace.exception=1，cause=MSIP，effectPending=1 | 之前进入流水线的中断到达 trap |
| 598004 | xRET，CLINT 仍 pending | handler 读到被门控为 0 的 MIP，未清 MSIP |
| 601430 | journalSafe=1，IRQ 再放行 | 安全条件此时才满足 |
| 601459 | 第二次 MSIP trap | 同一逻辑轮次重复进入 |
| 620158 | handler 清 MSIP 的设备 A | 只有第二次实际清除并计数 |

独立 `irq_trap_edge_diagnostic_retry/edge.log` 已到达旧first bad并确认这是实际CSR状态变更：tick596147 MIE由1变0、MEPC由0x8000038c改为0x800005f0；598005 xRET把MIE恢复1且MEPC保持0x800005f0；601459确有第二次CSR异常交付。并非只读探针的post-eval重复采样。该诊断有界640000周期，只作为RCA，不替代完整程序。启动引导阶段两次 MSIP 不计入 16 轮保护程序，但它们没有被删去。

根因来自 `mshrs.scala` 的 `effectPending := journalValid && !journalSafe`：journal 直到设备 D 返回才安装，而 A 已可能改变外部 MSIP。实际 accepted owner 的 mem_access/mem_ack/resp 状态未纳入责任期。Core 既有门控把外部中断输入（也就是 handler 的 MIP 视图）清零，因此这段空窗会让已接纳中断进入一个尚不能处理设备效果的 handler。

组件原 RTL 反例 `io_pending_before_ack_counterexample/run.exit=1`：同一生产 IOMSHR 接受 Seq8 后，延迟 A/ACK，effectPending=0，新增必要断言稳定失败。修复只把已有 `state != idle && req.packet_seq != 0 && protectedJournal` 合并入 pending，保留原 journal 安全条件。0 新寄存器、0 新队列、0 新 FSM；沿用原 pending 的跨模块接线。Seq0 管理/引导请求和非主 journal 通道不扩展保护范围。

`io_pending_owner_component/` 实际 Scala compile、Chisel/FIRRTL、Verilator build_retry 和运行均 0。RD/WR/AMO 分别覆盖 A 背压、D 延迟、旧值/完成响应背压、两次 rollback、唯一设备效果和安全后释放。原首次构建因缺 `-y generated` 失败，原日志保留。

必需整核回归：`continuous_io_owner_fullcore/` normal/Fault8/Fault18 的 IRQ、trap、Sv39、CLINT 写与 AMO；`continuous_io_owner_rebase/` 完整 Fault40+Seq41；IRQ 严格计分及损坏负例。现有 `final_source_stress/pressure` 不含此增量，必须完成后证明新增 inFlightEffect 在该负载始终为 0，或按影响范围补跑。旧源码 I/O-rebase 在途运行已用 SIGTERM 结束并保存 superseded 原因，不能当作成功。


2026-11-24最终验收更新：当前生产Core/CSR/IOMSHR/Scheduler五配置已完成
Scala/Chisel/LowFIR/CheckCombLoops/SV/C++模型构建；12个完整程序全部raw/oracle0。
严格trap/Sv39/CLINT写/AMO/IRQ、完整Fault40Seq41和满History全部通过，
IRQ14/重基9/压力8负例全部拒绝。完整压力实际64/64→回收→Seq143→free64。
normal IRQ原C0xfe115/0xfe127 now匹配D ReleaseAck0xfe20d，完整checksum正确。
最终证据`grantack_preemption_system_acceptance/result.json`，独立来源复核
`final_review_current_scheduler/result.json`；原失败和早期夹具不足均保留原范围。
本结论仅功能验收，物理签核独立，暂不推进比特流/时序仿真。
