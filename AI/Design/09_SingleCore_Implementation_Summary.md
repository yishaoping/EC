# 单主核实现进度

当前原始69项：VERIFIED=69、IN_PROGRESS=0、CODE_READY=0、BLOCKED=0。
任务ID和原定义未改变；最后P2-07/P4-10/P4-13/P5-10依据当前源码完整动态证据关闭，
P4-12保留已取得成果并完成新Scheduler来源复验。
功能验证完成，物理实现签核未完成。用户要求先完成RTL和功能仿真，暂不推进比特流/时序仿真。

| 最后任务 | 原阻塞及最终结果 |
|---|---|
| P2-07 CSR / Privileged State恢复 | scratch影子RMW保留本包CPS旧值；12组件组合通过；完整normal/Fault18各16轮精确MSIP trap与匹配MEPC/xRET、CSR/异常/Sv39联合验收通过。 |
| P4-10 Fence / Atomic / Interrupt边界 | ACK前live设备owner的pending空窗已修；16写/16回读、16AMO旧值/16回读、恢复门控及原效果重放唯一性通过，IRQ14负例拒绝。 |
| P4-12 资源耗尽 / Backpressure | 容量保持等待真实producer seal；当前最终源码原25MHz完整程序真实History64/64→释放48空槽→继续143个Checker PASS→free64，checksum974ea63763416da0；8负例拒绝。 |
| P4-13 Forward Progress / Deadlock Avoidance | 原normal IRQ checksum尾部C→History→外层GrantAck→C循环已修。仅含E调度可越过同组抢占，原发布/数据/目录锁保持。真实有效权限组件旧1/新0，Hierarchy、四发布、压力组件及12个完整程序全部通过。 |
| P5-10 MMIO / Forward Progress测试 | 长期脚本/完整输入/严格oracle固化。Fault40+Seq41真实8reset/8新Seq1 PASS/48设备读，9负例拒绝；IRQ14/压力8负例也全拒绝。 |

最终五配置Scala/Chisel/LowFIR/CheckCombLoops/SystemVerilog/C++模型全部构建通过。
12个完整程序（normal5、Fault8两项、Fault18三项、Fault40Seq41和25MHz压力）raw/oracle均0。
严格trap/Sv39/output/AMO/IRQ/rebase/pressure联合评分全部0。
Sv39正常16次物理读取与16次提交；Fault8有18次物理尝试，2次恢复废弃，存活严格16次。
normal IRQ原line0x80032f80的C0xfe115/0xfe127已在D0xfe20d得到匹配ReleaseAck并完整退出。

| 工作流 | 功能验收范围 |
|---|---|
| A 版本与安全基线 | 同址3/5/7、SW扫描、Put/迟到C/安全9合并/EVT与真实外写终态、最终安全基线通过。 |
| B Seq32与CDC | DATA/ARF/END/结果/四相ACK/实际释放/序号复用组件保留；23次Seq16完整整核和当前Fault40Seq41的8次重基通过。 |
| C Checker至Restart | GHM源域许可、结果释放、SCP pin、EVT/Restore/Lazy/Restart及多/慢Checker、双FAIL完整既有证据保留，最终跨模块回归通过。 |
| D 缓存/History/Scheduler | 当前生产Hierarchy、所有发布入口、维护、迟到owner、有效权限C/E循环反例和满资源完整程序通过。 |
| E 整核异常与并发 | 当前12完整程序和严格计分、31负例通过。I/O输入一致、瞬态故障、单Main既定架构假设保持。 |

最终证据：`AI/TMP/singlecore_function_closure_20261123/grantack_preemption_system_acceptance/result.json`；
独立来源/输入/工具哈希与69项审查：`final_review_current_scheduler/result.json`；
关闭记录：`final_closure_current_scheduler.json`。原提前69声明及旧watchdog/重复trap FAIL保留，未改写为PASS。
三个主要目标的1083份生成SV逐字节不变，仅Scheduler.sv有新增量；当前全套动态回归验证其集成影响。

正式固化文件见[任务板](05_SingleCore_Taskboard.md)、[系统验收](SingleCore_RTL_Baseline/System_Acceptance.md)、
[实现矩阵](SingleCore_RTL_Baseline/Feature_Implementation_Matrix.md)、[验证矩阵](SingleCore_RTL_Baseline/Verification_Matrix.md)
及同目录implementation_manifest.json、架构/握手/恢复/基线/Seq32/不变量/决策文档。

既有辅助OOC综合结果保留。Scheduler2way5ns综合前后WNS-10.841/-11.019ns均FAIL，
不能宣称时序满足；完整ChipTop综合尚无最终报告且来源早于owner/Scheduler增量。
布局布线、端口延时、AsyncQueue数据CE/Gray偏斜和最终Core物理签核仍未完成。

最终功能基线已冻结并完成9296份文件独立内容哈希校验。基线与最终元数据/复现工具补充包由 [Functional_Baseline_Archive.json](SingleCore_RTL_Baseline/Functional_Baseline_Archive.json) 共同标识；不是比特流或物理签核。
