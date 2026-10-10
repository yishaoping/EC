# Fix Design prompt

> 仅基于已确认 root cause 设计最小修复。先写 invariant 恢复条件、状态生命周期、ready/valid/fire、reset/kill、CDC/owner 和不会新增的等待边；列出组合环、stale replay、slot reuse、count/END、barrier/cache 回归风险。把 hypothesis 与 verified fact 分开，不把方案写成已通过。
