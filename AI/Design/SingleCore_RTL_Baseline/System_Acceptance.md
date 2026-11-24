# EC单主核最终功能验收

2026-11-24，**69 VERIFIED / 0 IN_PROGRESS / 0 CODE_READY**。
当前单主核范围功能实现、必要功能验证及整核回归完成；物理实现签核未完成。
原任务ID和定义保持，C5/D17多主核项继续在单核范围外。

| 最后五项 | 原主要阻塞 | 最终证据与状态 |
|---|---|---|
| P2-07 CSR / Privileged State恢复 | scratch CPS/physical旧值不同；IRQ精确trap/return证据不足 | 12种真实CSR命令组合；normal/Fault18完整IRQ各16trap及16匹配MEPC/xRET，恢复/异常/Sv39联合通过。VERIFIED。 |
| P4-10 Fence / Atomic / Interrupt边界 | 设备A先改变MSIP、D建journal之前丢pending | IOMSHR live owner并入原effectPending；慢A/D组件、16轮IRQ与恢复门控、CLINT写/AMO完整联合及14IRQ负例通过。VERIFIED。 |
| P4-12 资源耗尽 / Backpressure | 容量保持先于真实seal回执释放；满表完整程序未结束 | 原producer_seal_ready约束；最终25MHz完整程序实际64/64→回收→Seq143/free64、checksum及8负例通过。保留VERIFIED并完成最终源码复验。 |
| P4-13 Forward Progress / Deadlock Avoidance | normal IRQ尾部C→History→外层GrantAck→C循环 | Scheduler仅含E调度越过同组抢占；真实权限/History组件旧1新0，Hierarchy/发布/压力及12完整Core全部通过；旧C0xfe115/0xfe127新D0xfe20d匹配ACK。VERIFIED。 |
| P5-10 MMIO / Forward Progress测试 | 完整重基/中断/满资源组合证据未闭合 | 长期输入与严格入口实际运行：Fault40Seq41八次真实reset、八个新Seq1 PASS、48设备读，9负例拒绝；其余完整评分及负例通过。VERIFIED。 |

| 层级 | 当前实际结果 |
|---|---|
| 整核构建 | normal、Fault8、Fault18、Fault40Seq41、25MHz压力五配置，Scala/Chisel/LowFIR/CheckCombLoops/SV/C++模型全部0。 |
| 完整程序 | 12项raw exit和架构oracle全部0；原完整程序未缩减，无watchdog放宽。 |
| 严格评分 | trap、Sv39、CLINT写、AMO、IRQ、重基、满History联合全部通过。 |
| IRQ | normal/Fault18各16set、16clear、16精确MSIP trap和16匹配MEPC返回；Fault18恢复/未安全效果交叠保持IRQ禁止。 |
| CLINT输出/AMO | 16写+16回读、16AMO旧值+16回读；恢复重放仅一次外部设备A。 |
| Sv39 | 正常16物理/16存活提交；Fault8共18物理尝试，恢复废弃2次、存活16，废弃payload也核验。 |
| Seq32重基 | 当前Fault40Seq41八次物理reset、八个新Seq1 PASS和48设备读；既有32位生命周期/慢ACK/23次Seq16等有效证据保留。 |
| 满History | 实际64/64，回收至48空槽并继续143次Checker PASS，结束free64，checksum974ea63763416da0。 |
| 负例 | IRQ14、重基9、压力8，共31类破坏全部拒绝。 |
| 来源 | 当前生产源与生成输入、12份程序/模型、计分工具和报告哈希独立核验；69项实际文件映射完整。 |

五个工作流A版本基线、B Seq32/CDC、C Checker至Restart、D缓存/History/Scheduler、
E整核异常并发均达到当前冻结假设下的必要功能验收。所有发布/终态/恢复门控继续保留。
该结论来自定向测试、断言和整核组合，未声称形式化穷尽证明。

关键证据：

- [完整严格验收](../../TMP/singlecore_function_closure_20261123/grantack_preemption_system_acceptance/result.json)
- [源码与69项独立审查](../../TMP/singlecore_function_closure_20261123/final_review_current_scheduler/result.json)
- [最终关闭记录](../../TMP/singlecore_function_closure_20261123/final_closure_current_scheduler.json)
- [原写回首坏消失](../../TMP/singlecore_function_closure_20261123/grantack_preemption_fix/first_bad_resolved.json)
- [长期有效协议反例与修复](../../TMP/singlecore_function_closure_20261123/grantack_preemption_owned_history_longterm/result.json)
- [基线归档与补充包正式回执](Functional_Baseline_Archive.json)

原重复trap、normal IRQ watchdog及容量watchdog的FAIL原样保留；早期缺权限fixture、
未覆盖交叠及构建资源/PCH错误保留为历史，未冒充最终有效证据。

最终四项生产修复均未新增寄存器/队列/FSM，分别复用seal回执、scratch shadow、live IOMSHR和原SourceE。
既有GHM为CDC注册源端许可增加的4bit单独已验证，未在最终修复中重复增加。

用户当前要求先完成RTL和功能仿真，暂不推进比特流和时序仿真。
已有辅助组件综合可用；Scheduler2way5ns OOC时序前后WNS-10.841/-11.019ns均FAIL，不能声称达标。
完整ChipTop综合观察时尚无最终报告且来源早于最后两项修复。最终Core布局布线、端口延时、
AsyncQueue数据CE/Gray偏斜与物理签核仍未完成，未来工作独立于69项功能状态。
机器可读细节见[System_Acceptance.json](System_Acceptance.json)。
