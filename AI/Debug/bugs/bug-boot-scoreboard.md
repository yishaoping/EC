# BootROM load / scoreboard / replay writeback

- 状态：历史bug；原生成物与源版本有差异，非当前最新首因。
- Failure：checker从BootROM load后使用旧a0=0x4000，mret至0x4000反复fault，无法COPY。
- First bad：WB miss路径在无有效load响应时破坏scoreboard或RF；Scoreboard.clearAll错误last-connect更新在enable=false仍影响已有next。
- Causal chain：load依赖丢失 →csrw mepc用旧值 →trap loop →checker不启动 →BOOM slot watchdog。
- Broken invariant：miss/replay不是架构完成，未响应load保持依赖；条件清除不得覆盖其它有效更新。
- Fix/Validation：见guardian_protocol_audit、runtime_bootaddr/signal_chain；不同中间patch被恢复/修正，不能照历史指令回滚当前代码。源码compile不证明旧wave验证新实现。
- Regression：检查ordinary handler/redirect/replay身份与WB真正完成，先生成匹配RTL。
- 来源：history/reports/legacy_ai/guardian_protocol_audit.md、runtime_bootaddr_replay_analysis.md。
