# Opt4 L2 observer：QueuedRequest/FullRequest异构Mux

状态：源码修复/静态检查通过，Chisel重新展开及runtime未验证。
Failure：2026-10-29用户run optimization_4_svb_20261029_013322_1d198f2e，RTL_GENERATION exit2，simulation未开始。
First bad：Scheduler.scala旧697行observationLookup；上一轮只有Scala编译，无成功的新observer展开reference。
根因：QueuedRequest与其多set字段的子类FullRequest直接Mux，Scala可编译，Chisel runtime cloneSupertype拒绝异构Bundle。
修复：FullRequest先Wire(new QueuedRequest, init=...)按字段投影再Mux，与既有functional分配路径一致；set独立pipeline不变。
功能范围：只改observer，移除observer后Scheduler主体逐字一致；其他8个hardware/resource未变。
验证：Scala compile、37offline tests、source-scope、patch往返/独立index、launcher static-check PASS。
回归：offline_capacity_cache_tests.py/test_l2_observation_mux_projects_full_request_by_fields（source contract，非展开测试）。
未验证：Chisel/FIRRTL/full RTL generation、Verilator build、simulation/benchmark；遵守用户原先不执行生成/仿真约束。
报告与日志：[Mux fix](../../TMP/opt4_observer_mux_fix_20261029_df6ad056/README.md)。
经验：Scala继承/compile PASS不足以证明Chisel aggregate Mux合法；observer同样须保证Mux两侧runtime Bundle形状一致。
