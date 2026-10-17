# Bug：MSHR RPQ replay drain 持续 secondary admission

- 状态：根因与最小模块修复 verified；整机 writer opportunity unresolved。
- Run identity：HEAD `a68183c83e08ed837c677aec7836c97895e3a95e`＋原dirty Phase-1，v1Config。历史FST与本轮生成物分开，manifest见报告。
- Failure：BFS verified=1后首条PERF printf卡HTIF syscall，tohost store架构提交但没有cache写效果；host一直读0。
- First divergence：历史FST t10387259，MSHR2 transaction0x4da进入state12仍开放secondary；470 BOOM cycles入119出117，occupancy8..11。至t41845875仍未publish。
- Causal chain：polling read primary→writer需要T被拒→安装完成→drain收新loads→RPQ不空→metadata/MSHR无法退休→writer无法upgrade→host没有请求可ACK。
- Broken invariant：drain accepted work集合没有冻结，可被无限外部producer扩张。
- Fix：仅在s_drain_rpq关闭全部secondary admission，保留已有RPQ/replay/terminal及publish条件；assert无secondary accept/无RPQ enqueue。
- Validation：Scala、v1Config elaboration/FIRRTL/CheckCombLoops/Verilog/memory宏PASS；旧RTL1026cycle有界测试复现，修复四模块场景PASS，accepted/retired一一对应。
- Regression boundary：stub提供TL/DCache tagged completion，尚未证明真实STQ store succeeded或内存数据效果；BFS未运行。
- Remaining risks：固定优先级其他MSHR流量、incoming loads、无限RET​RY/永久背压；不宣称全局fairness。
- 下一步：真实LSU短同linepolling＋committed store，检查退休后load hit、writer acquire/terminal/STQ.succeeded，再测多MSHR/probe。
- 报告：[2026-10-14设计实施验证](../history/reports/mshr_rpq_drain_closure_20261014.md)。证据：`AI/TMP/rpq_drain_closure_20261014_100756/`。
