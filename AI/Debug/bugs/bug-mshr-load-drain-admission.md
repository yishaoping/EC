# Bug：MSHR load drain 持续 secondary admission

- 状态：静态根因、最小修复、完整v1Config生成/build及5短RTL场景verified；可以进入最终大仿真。
- 与旧bug区别：s_drain_rpq已关闭admission，s_drain_rpq_loads仍accept普通load并RPQ enqueue；无需replay_inflight也可续命。
- 反例：入口Q>0，dequeue旧load同时enqueue新load，Q_next=Q，empty/non-load-head出口永远不成立；writer无法等待owner释放。
- Fix：mshrs.scala:159统一两drain状态的drainAdmissionClosed；现有gate/assert复用，所有consumer/owner/publish/Phase-1条件保留。
- Validation：旧RTL1000cycle仍state3、新入1000；新5短场景全部退出、no-admission/no-enqueue、逐token完成；真实MSHR/RPQ/RAM，stub提供下游completion。
- Build：Scala/完整Chisel/FIRRTL/CheckCombLoops/SV/宏/Verilator debug simulator全部PASS。
- Boundary：下游有界服务和有限RETRY条件下局部收敛；无全局LSU writer公平上界证明，真实STQ/内存效果和BFS待大仿真。
- Provenance：HEAD a68183c + dirty Phase-1，pre/post hash和完整/增量diff见独立证据目录。
- Evidence：`AI/TMP/mshr_both_drain_closure_20261014_165012/`。
- 报告：[方案、实施、验证](../history/reports/mshr_both_drain_closure_20261014.md)。
