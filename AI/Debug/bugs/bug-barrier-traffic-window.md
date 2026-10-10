# Barrier close、session exit与traffic window

- 状态：历史source诊断+compile记录，严格同输入A/B未完成。
- Failure：barrier开启报告3713 store/32包，对比60570/279；另有61299 vs60587流量不一致。
- First bad：旧R_IC barrier close使用ctrl3全会话退出；LSU普通架构资格被fsm_check live状态门控，postcheck/cooling仍退休但漏计。
- Causal chain：close误成exit + measurement窗口混同checker状态 →后续包/尾提交漏计 →统计差。
- Broken invariant：关闭一包不退出会话；统计资格随真实事件/owner锁存，不能按完成时live状态重判。
- Fix：barrier close与true exit分开；架构统计使用traffic_counting/LSQ锁存归属；checker统计保留合法包tail。
- Validation：parser/compile记录通过，无严格软件+RTL一致的A/B；不能给性能结论。
- Regression：close开放drain后还要检查final count/END，不能只改ctrl或increment条件。
- 来源：history/reports/barrier-statistics/。
