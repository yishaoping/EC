# History

`reports/` 保存从原 `Debug/` 和原 `AI/Debug/` 归档的分析文档；`evidence/` 保存窄 trace、manifest、验证日志和可复核小型证据。这里的结论按运行身份解释，不能直接当 current state。

主要运行链：

- 2026-09-30：sequence ownership、address statistics、verified=0 初始问题。
- 2026-10-01～04：watermark、barrier traffic、snapshot/ARF、SyncReadMem 和组合环。
- 2026-10-05：461000/459000 LSL 错类型与同步 FIFO deadlock，后续修复与回归边界。
- 2026-10-08：528000 count/drain first bad，`558 → 600` 计数分叉。
- 2026-10-09～10：1769000 前端方案及 459000 redirect regression；静态生成通过不等于整机动态通过。
- 最新：291 packages PASS 但 `verified=0`，进入 `state/current_debug_state.md`。
