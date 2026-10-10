# Debug 演化时间线

| 时间/标识 | last good → first bad | 根因/状态 | 证据位置 |
|---|---|---|---|
| 早期 / BootROM-CDC-trap | load响应依赖/anchor/result/admission失配 | 多个独立run的历史结论，未合并为当前事实 | `history/reports/legacy_ai/` |
| 09-30 / 254 pkg | ownership 前窗口 → seq 0/旧 live seq event | package ownership 与地址统计边界错误；已实施静态修复，需动态回归 | `history/reports/ownership-address/current_run_254_packages_and_verify_failure.md` |
| 10-01 / 259 pkg | PASS/safe seq 0x62 → 同包尾 store | `<= safe` 错把同包尾事件判旧；修为 `<` | `history/reports/ownership-address/current_run_259pkg_address_stats_root_cause_20261001.md` |
| 10-04 / d7 | can-commit quiet → snapshot/ARF mismatch | snapshot 空 ROB/架构 next-PC 和组合环问题；修复后需生成/运行验证 | `history/reports/snapshot-lsl/current_run_snapshot_boundary_root_cause_20261004.md` |
| 10-05 / 461000→459000 | LSL request → wrong store head / later no read fire | 类型地址错配；首次修复引入 SyncReadMem ready/read 环，随后加入 prefetch/head register | `history/reports/snapshot-lsl/assert21_461000_root_cause_20261005.md` |
| 10-08 / 528000 | seq 0x15 PASS → seq 0x16 R_IC done=558 while BOOM still drains | final count 早于旧包真实终点；600/558/42 chain confirmed | `bugs/bug-528000-count-boundary.md`, `history/evidence/528000/` |
| 10-09/10 / 1769000→459000 | redirect → ordinary startup stream corruption | frontend redirect pending/settle 方案的回归；静态生成通过，动态未证实 | `bugs/bug-1769000-frontend-regression.md` |
| 最新 / 291 pkg | run end → `verified=0` | 291/291/291 平衡但 BOOM/checker 流量差 164/258；first bad unresolved | `state/current_debug_state.md` |
