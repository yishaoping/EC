# 同组 C 抢占阻塞外层 GrantAck，History 发布形成循环等待

2026-11-24：最小生产Scheduler修复、有效权限组件与当前5配置12完整程序/严格评分已全部通过。原反例和早期夹具边界继续保留。

证据目录 `AI/TMP/singlecore_function_closure_20261123/`。原失败为
`continuous_io_owner_fullcore/normal/irq/run.exit=1`，16轮MSIP中断已正确完成，
随后checksum阶段 `Pipeline has hung`。不能以中断局部通过替代完整程序验收。

只读 `irq_tail_wb_diagnostic` 使用同一个真实模型及同一个完整ELF，638个窄信号，
没有修改状态、ACK、断言或激励。1071000周期诊断上限exit2不算PASS。
`tail.log` 的tick为十进制Core仿真周期；`run.log` DCache cycle是十六进制内部计数，
该运行相差复位期间的0x63，C输入还经过配置队列。两者按握手链核对，不能直接混用。

| 观察 tick | 事件 | 含义 |
|---|---|---|
| 1040778 | C MSHR接受set0xbe、tag0x1003、source6的ReleaseData；ABC1同组等待tag0x1000的外层refill。 | C正常抢占ABC1，两个事务对应不同way。 |
| 1040793 | ABC1 `w_grantlast=1`，`s_grantack=0`、E valid=1。 | 完整外层Grant已返回，仍欠实际GrantAck。 |
| 1040918 | History `publish.valid=1`。 | 发布需要排空该组已接受外层事务；D执行暂停。 |
| 1069056 | 上述条件不变，SourceD空、preservation无锁且idle。 | 无外部终态在途可自行解除等待。 |

症状（已证实）：L1 source6、line0x80032f80完整C已发送，永久等待D ReleaseAck。
直接阻塞（已证实）：嵌套C的D执行被History发布屏障保持。
上游触发（已证实）：History等ABC1的外层E，Scheduler同组C抢占却阻挡ABC1的全部调度，
包括无bank/目录副作用的E。循环为C→History→ABC1 E→C。
放大因素（已证实）：全局SourceD发布门控使其他set也停止，最终Main/Checker均无法前进。

生产改动仅在 `sifive-cache/.../Scheduler.scala` 的 `mshr_request`：
一个调度包仅含E，且A/B/C/D/X、目录和park均无效时，允许越过同组C/BC抢占。
仍复用同一个轮转仲裁器和SourceE，仍需所有原stage3Allowed/owner/发布条件。
不绕过基线锁，不允许伴随数据或目录操作，不改MSHR请求、版本或恢复语义。
0新寄存器、0队列、0FSM，无新CDC信号。

`baseline_publication/grantack_preemption_test.cpp` 的最终有效激励：Main以真实Acquire取得T，
用真实SVB ingress归档Pending3，再发另一way的peer Acquire并延迟外层Grant。
Main持T期间的后继C7与SW3更新交叠，发布3等待ABC外层E，C7同时保持同组抢占。
返回完整Grant后，修复允许实际E收尾，3先发布并ACK，C7再正常ACK；SW7后才能发布7。
每个accepted外写beat检查完整数据，最终通过真实peer TtoN、flush归还全部权限。
没有强制内部ready/owner，没有伪造ACK或降低断言。

最终有效对照 `grantack_preemption_owned_history_review`：同一bench旧1/新0，
bench.cpp及SHA已固化。长期CLI结果见 `grantack_preemption_owned_history_longterm`。
四同址发布用例、压力组件与当前生产Hierarchy全套另行PASS。

早期fixture证据保留但不作为最终验收：初版省略Main重新Acquire就发第二个C；
初版cleanup还漏peer权限返回导致末尾flush1。第一次补齐权限后C提前完成，
说明未覆盖所需History交叠（非RTL回归）；已新增真实Pending3/SW3与C7竞争。
`grantack_preemption_permission_review` 的before build2是旧ccache相对PCH依赖路径失效，
改为独立输出重新生成并构建后得到上述有效旧1/新0。原日志和各bench版本均保留。
不得再把早期缺权限fixture的PASS当作最终C协议证据。

最终整核须回收 `grantack_preemption_fullcore` 和 `grantack_preemption_stress_retry`，
完成normal/Fault8/Fault18、Fault40+Seq41、原25MHz满History的完整程序与严格oracle。
在这些证据闭合前，任务维持65 VERIFIED、4 IN_PROGRESS，不冻结69/69。


2026-11-24最终验收更新：当前生产Core/CSR/IOMSHR/Scheduler五配置已完成
Scala/Chisel/LowFIR/CheckCombLoops/SV/C++模型构建；12个完整程序全部raw/oracle0。
严格trap/Sv39/CLINT写/AMO/IRQ、完整Fault40Seq41和满History全部通过，
IRQ14/重基9/压力8负例全部拒绝。完整压力实际64/64→回收→Seq143→free64。
normal IRQ原C0xfe115/0xfe127 now匹配D ReleaseAck0xfe20d，完整checksum正确。
最终证据`grantack_preemption_system_acceptance/result.json`，独立来源复核
`final_review_current_scheduler/result.json`；原失败和早期夹具不足均保留原范围。
本结论仅功能验收，物理签核独立，暂不推进比特流/时序仿真。
