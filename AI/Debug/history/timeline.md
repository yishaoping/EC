# Debug 演化时间线

| 时间/标识 | last good → first bad | 根因/状态 | 证据位置 |
|---|---|---|---|
| 10-17 / Stage 1 final validation closure | 修复后的新 binary → 九项 closure gates 全 PASS | provenance PASS、serial_success、verified=1、main/checker 155606=155606、AMO 双 lane、clear/lifecycle/duplicate/lost effect 全 PASS、真实退出 drain=0；`STAGE1_STATUS=CLOSED`，无需新仿真 | `history/reports/stage1_closure_20261017.md` 第 11 节、`AI/TMP/stage1_closure_run_g3Y7Oi9x/` |
| 10-17 / Stage 1 缺失 simulator header | 用户 build → emulator.cc:24 找不到 stage1_exit.h → make Error 1/2 | SIM_FILE_REQS 漏列 header；补一行，隔离真实 staging 规则复现前失败/后通过，32 tests PASS；本轮未 hardware build/sim，完整 build/dynamic pending | `history/reports/stage1_exit_header_build_fix_20261017.md`、`AI/TMP/stage1_exit_header_fix_dgopfbpr/` |
| 10-17 / Stage 1 最终 preflight | 两项已归因补丁 → accounting/exit/coverage 静态复核通过 | PRE_FLIGHT=PASS，无 blocker；32 tests、语法、workload 身份、diff 检查 PASS；功能代码未改，冻结后待一次新 build + sim，本轮未启动 | `history/reports/stage1_final_preflight_20261017.md` |
| 10-17 / Stage 1 全项 closure 审计 | provenance/verified/338 packages PASS → main-checker -329、exit真实请求0x52788 | 329条全部唯一归因于owned drain统计资格；统一R_IC ownership修复，反事实extra/missing均0；有限HTIF exit+真实quiescence等待；修analyzer诊断，32离线tests PASS；全部补丁待一次联合动态验证，本轮未hardware build/sim | `history/reports/stage1_closure_20261017.md`、`stage1_closure_20261017_transactions.tsv`、`AI/TMP/stage1_audit_20261017_atpbr625/` |
| 10-16 19:22 后 / Stage 1 TestHarness 类型修复 | 用户 build → collect 类型推断失败、Nothing.hartId → make Error 1 | 直接匹配 BoomTileAttachParams 并收集 Seq[Int] hart IDs；三条 Scala error 同一根因，源码已修，静态 diff 检查通过；本轮未重新编译或仿真 | `AI/TMP/stage1_closure_build_d1DLDfai/build.log`、`state/current_debug_state.md` |
| 10-16 / Stage 1 readiness preflight | 原 workload 仅 AMO low lane / 无真实退出快照 → 取证链补齐 | PRE_FLIGHT=PASS；独立软件构建证明双 lane、live RTL exit probes、精确 `_exit` 分类、clear mode B、全新 build/run provenance 和统一 analyzer；23 项离线测试通过，本轮未硬件编译或仿真 | `history/reports/stage1_readiness_20261016.md` |
| 10-16 / Stage 1 L1 closure checkpoint | serial success + verified=1 → BOOM/checker `707/1715` | 完成只读归因；LSQ 统计资格遗漏 `traffic_check`，AMO.W 上 lane 仍待动态覆盖；加入流式 analyzer、AMO/cycle instrumentation；未重新 build/run | `history/reports/stage1_closure_20261016.md` |
| 10-14 / 两个 MSHR drain closure | state3持续polling→旧RTL1000cycle不退出 | 统一state3/state12 gate；完整v1Config生成/build、5短RTL场景PASS；可以进入大仿真，真实整机效果待验证 | `history/reports/mshr_both_drain_closure_20261014.md` |
| 10-14 / mshrs 静态审计 | 保存closure→当前源码逐字一致，无新divergence | state12 gate、Phase-1/19原assert保留；最小生成与lintPASS；early-drain/global公平性仍pending，功能源码未改 | `history/reports/mshrs_static_audit_20261014.md` |
| 10-14 / HTIF tail RPQ drain | read MSHR安装完成→drain持续secondary入队→writer nack且host零响应 | 关闭state12 admission；Scala/整机生成/四模块场景PASS，真实writer公平性及BFS pending | `history/reports/mshr_rpq_drain_closure_20261014.md`, `bugs/bug-mshr-rpq-drain-admission.md` |
| 早期 / BootROM-CDC-trap | load响应依赖/anchor/result/admission失配 | 多个独立run的历史结论，未合并为当前事实 | `history/reports/legacy_ai/` |
| 09-30 / 254 pkg | ownership 前窗口 → seq 0/旧 live seq event | package ownership 与地址统计边界错误；已实施静态修复，需动态回归 | `history/reports/ownership-address/current_run_254_packages_and_verify_failure.md` |
| 10-01 / 259 pkg | PASS/safe seq 0x62 → 同包尾 store | `<= safe` 错把同包尾事件判旧；修为 `<` | `history/reports/ownership-address/current_run_259pkg_address_stats_root_cause_20261001.md` |
| 10-04 / d7 | can-commit quiet → snapshot/ARF mismatch | snapshot 空 ROB/架构 next-PC 和组合环问题；修复后需生成/运行验证 | `history/reports/snapshot-lsl/current_run_snapshot_boundary_root_cause_20261004.md` |
| 10-05 / 461000→459000 | LSL request → wrong store head / later no read fire | 类型地址错配；首次修复引入 SyncReadMem ready/read 环，随后加入 prefetch/head register | `history/reports/snapshot-lsl/assert21_461000_root_cause_20261005.md` |
| 10-08 / 528000 | seq 0x15 PASS → seq 0x16 R_IC done=558 while BOOM still drains | final count 早于旧包真实终点；600/558/42 chain confirmed | `bugs/bug-528000-count-boundary.md`, `history/evidence/528000/` |
| 10-09/10 / 1769000→459000 | redirect → ordinary startup stream corruption | frontend redirect pending/settle 方案的回归；静态生成通过，动态未证实 | `bugs/bug-1769000-frontend-regression.md` |
| 最新 / 291 pkg | run end → `verified=0` | 291/291/291 平衡但 BOOM/checker 流量差 164/258；first bad unresolved | `state/current_debug_state.md` |
