# Bug 528000：drain 后 final count 过早结束

**状态：历史已确认；修复的整机回归未证明。**

- Failure：checker 1 watchdog at 528000；seq `0x16` 无 release，LSL 有 5 个尾 store。
- Last good：seq `0x15` PASS/release/safe=0x15。
- First bad：FST 536427，R_IC 在 ROB 尚未空时发布 `ic_counter=558` 与 done；536537 首批 3 条仍归属 seq 0x16 的 BOOM retirement 未计入。
- Causal chain：barrier close → R_IC postcheck/cooling 停止计数 → BOOM 老 ROB drain 42 条 → checker 按 558 停止 → 5 stores 留在 LSL → quiescent/exec/result/release 无法完成 → watchdog。
- Broken invariant：final count 必须覆盖该 sequence 的全部架构退休；END/seal 必须晚于 producer drain。
- Fix design：让 producer close/stop、boundary capture、final count、producer END/seal 成为独立有序事件；保留 LSL、DATA/END、barrier 和 result gate。
- Validation：directed R_IC/R_ICSL/GHM tests 与生成/静态记录通过；原始 528000 workload 未重跑，不能称为动态修复。

证据：`history/evidence/528000/`；完整报告：`history/reports/drain-count/current_run_528000_root_cause_20261008.md`。
