# 容量边界在旧包封口前提前释放

根因与最小生产修复已完成最终完整压力及5配置整核验收。当前结果见文末2026-11-24更新；下文保留原失败与定位证据。

证据根目录：`AI/TMP/singlecore_function_closure_20261123/slow_checker_pressure_candidate/`。实际25 MHz Checker、原64项History、四Checker及真实同组store/AMO程序；无强制owner/ACK，无watchdog调整。`run.exit=1`为真实little core 1 watchdog，`end_probe/`、`seal_probe/`、`boundary_probe/`是同一原Verilator库的只读链接，诊断周期上限退出2不算完整程序PASS。相应源码哈希与当前Core/R_IC/GHM/BoomTile逐项一致。

观测tick取`sc_time_stamp()`，与该模型`max-cycles`同一模拟器计数单位；以下不是Checker时钟周期数。Checker频率为25 MHz，Main为200 MHz。

| tick | 已观察事件 | 含义 |
|---|---|---|
| 56545 | capacityClosing置1 | 因实际缓存资源请求保持一个非空ROB的已提交前缀 |
| 56549 | R_IC进入trans，boundary_seq=1，分配Seq2 | 旧Seq1边界已捕获，新SCP分配不代表旧包已封口 |
| 56550 | Main count1=0x8040 | 已完成64条架构提交，final标志为1 |
| 56781 | RSU busy清0，同拍big_hang=1 | merge已退出，但CDC队列仍在背压 |
| 56782 | capacityClosing清0 | 原清除条件只检查新Seq和RSU idle，未等producer seal |
| 56787 | big_hang清0 | 此时ROB仍非空，容量快照边界已经消失 |
| 60992 | Checker sl_count=65、count_shadow=64、done=0 | 全部数据/ARF已到，但永远等不到END；源端end_pending和producerSeals始终0 |

直接症状（已证）：Checker watchdog。立即阻塞（已证）：旧包没有producer seal，GHM不能发END，R_IC trans等待同一seal receipt。上游触发（已证）：`core.scala`容量保持仅按RSU idle释放，CDC背压使封口稍晚；释放后`producerSealCoreReady`的`ROB empty || ioSnapshotBoundary`永久为假。下游放大（已证）：Checker已到指令末尾却无法完整终结，最终watchdog；后续local trap不是最初原因。

50 MHz独立正常配置也复现同类watchdog、实际History最多占5槽，故原失败不证明History满表；满64项定向组件证据另计。

最小设计：在原`capacityClosing`清除条件中增加既有`io.producer_seal_ready`，保持同一已捕获前缀直至BoomTile的sticky seal receipt被R_IC消费。保留recoveryStop取消路径。不增加寄存器、队列、FSM、全局owner或排序网络。候选与固定runtime jar、Scala/Chisel构建及完整Core运行入口在`capacity_seal_handshake_candidate/`；原失败和全部TMP保留。

精确生产合入及哈希见`capacity_scratch_production_integration/result.json`；独立class与生产来源关系见`integrated_capacity_scratch_candidate/effective_production_source_relation.json`。

验收须包括：同一25 MHz/原ELF的旧first bad消失、Seq1实际END/PASS、后续包能够完成、完整程序oracle；History是否达到压力阈值独立计分。合入后还需整核正常/Fault8、Sv39、中断/设备效果回归，不能用单个Scala编译或有界first-bad诊断代替。


2026-11-24最终验收更新：当前生产Core/CSR/IOMSHR/Scheduler五配置已完成
Scala/Chisel/LowFIR/CheckCombLoops/SV/C++模型构建；12个完整程序全部raw/oracle0。
严格trap/Sv39/CLINT写/AMO/IRQ、完整Fault40Seq41和满History全部通过，
IRQ14/重基9/压力8负例全部拒绝。完整压力实际64/64→回收→Seq143→free64。
normal IRQ原C0xfe115/0xfe127 now匹配D ReleaseAck0xfe20d，完整checksum正确。
最终证据`grantack_preemption_system_acceptance/result.json`，独立来源复核
`final_review_current_scheduler/result.json`；原失败和早期夹具不足均保留原范围。
本结论仅功能验收，物理签核独立，暂不推进比特流/时序仿真。
