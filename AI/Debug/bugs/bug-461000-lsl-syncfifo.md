# Bug 461000 / 459000：LSL 类型错配与同步 FIFO 生命周期

**状态：历史已确认机制；最新运行是否复现未定。**

461000 的 first functional error 是 R_LSL load request 消费 store FIFO head，ELU 报 `io_error_ld`，包取消、safe 停滞、DCache 跨包阻塞，最后 BOOM watchdog。首次加入 type/address match 后，ready 依赖 SyncReadMem head，产生 head-match→read-enable→head-match 的 deadlock，表现为 459000。

当前源代码包含 prefetch/read、registered head payload/valid、registered response 和仅 matching fire 出队；生成 RTL 还必须检查 RAM output 稳定性。历史 static compile/generation 通过不等于全路径 dynamic validation。

- Last good / First bad：旧461000 run中FST393653 load dequeue、393657 store payload返回/ELU报错；其后独立459000 run中的FIFO有head但read/fire不发生。不要跨run拼同一时间线。
- Fix：prefetch/read与dequeue分离，registered payload/valid/response、type/address匹配；mismatch response可报错但不消费head。
- Validation：528000 RCA独立扫描3201次deq均match，RAM raw输出归零后registered payload保持，旧LSL first-bad在该run消失。
- Regression：首次match-gated read修复引入同步RAM等待环；empty head PC仍需独立检查。
- 来源：history/reports/snapshot-lsl/与history/evidence/528000/lsl_audit_summary.txt。
