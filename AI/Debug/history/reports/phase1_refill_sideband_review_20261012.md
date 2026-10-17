# 方案 A 修复后静态 readiness review（2026-10-12）

修改正确性：**PASS**。可以进入第一轮定向仿真：**YES**。本次结论只覆盖 refill 地址接口修复；没有运行 testcase，也没有宣称 watchdog 或完整 Phase-1 动态通过。

方案 A 增量以 `AI/TMP/phase1_refill_line_addr_mb5lcmdw/` 的实施前快照为基准：`phase1.scala` 新增40位 `line_addr`；`mshrs.scala` 从已锁存的 primary descriptor 生成 block 对齐地址；`dcache.scala` 用该字段比较 physical tag，并检查 block alignment 与 array set 一致。完整增量为 +7/-1。working tree 中其他 Phase-1 修改早于本次修复，没有混入本次 scope 结论。

源码、CHIRRTL、Low FIRRTL、最终 RTL 一致：原 array addr 保留14位，line_addr沿6个MSHR→同一个refill arbiter→DCache保持40位。有效row地址为 `{req_addr[39:6], 6'h0}`，没有从reservedTag或当拍install重建；first/middle/last row恒定，row counter仅改变array addr。默认零只用于无有效refill。DCache physical tag比较使用line_addr[39:14]，完整高位未截断；set/alignment以及原ID、token、epoch、owner、fault/assert均保留。字段在最终RTL中明确被使用。

没有新增FSM、preservation、version/generation/watermark、owner生命周期、allocation或TileLink变化；原assertion未弱化。审查前后功能源码hash一致。

- Scala `project boom; compile`：PASS，exit 0，19:40:44完成。
- v1Config Chisel elaboration/FIRRTL emission：PASS，exit 0，19:43:24完成。
- Scala FIRRTL low lowering、firtool `--verify-each=true`、CheckCombLoops、Verilog emission及top/model MacroCompiler：PASS，make verilog exit 0，20:01:27完成。
- git diff --check：PASS。

无sideband width、connection或unused告警。已有Scala弃用/feature、device-tree告警和12类未处理annotation告警仍存在；annotation类型与修复前完全一致。未运行Verilator lint，不宣称全工程无unused信号。

生成物与日志位于独立 `AI/TMP/phase1_refill_sideband_review_20261012_193958/`，没有覆盖默认simulator、generated-src或output。完整命令、源码diff、连接证据、RTL摘录、SHA256 manifest及验证边界见[完整报告](../../../TMP/phase1_refill_sideband_review_20261012_193958/report.md)和[验证摘要](../../../TMP/phase1_refill_sideband_review_20261012_193958/verification-summary.json)。

下一步由用户运行原testcase验证首miss、refill_fault、watchdog及后续Phase-1行为；本轮未修改功能代码、未构建或运行新的Verilator executable。
