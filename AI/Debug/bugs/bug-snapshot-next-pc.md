# Snapshot / empty ROB committed next PC

- 状态：historical conclusion；最新回归 unresolved。
- Failure：d7 ARF差异、后续checker错误与watchdog。
- First bad：旧459000 FST393085，ROB empty但next PC是已退休load 0x800004ac；393095 RSU capture，正确 continuation为0x80000368。
- Causal chain：更严格empty-ROB snapshot → 仍读invalid head storage → checker重放旧load → LSL错配 → result/safe停滞。
- Broken invariant：snapshot PC/ARF属于同一架构边界；invalid ROB slot不能产生valid next PC。
- Fix：明确committed next-PC与valid、quiet/armed；避免live commit/RSU stall反馈组合环。
- Validation：528000 RCA中23个snapshot全满足empty/valid/no commit，PC与随后首条commit吻合；只证明该运行这些边界。
- Regression：snapshot/drain开放旧ROB退休后产生528000 count漏洞；不能按“源码未改LSL”断言无回归。
- 来源：history/reports/snapshot-lsl/、history/evidence/528000/commit_audit_summary.txt。
