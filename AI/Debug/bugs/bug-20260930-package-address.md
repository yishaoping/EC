# 2026-09-30/10-01：package ownership 与 address statistics

**状态：历史结论；需要最新 workload 回归。**

早期运行在 allocation 前产生 sequence 0 / stale live-sequence event；259-package 运行进一步证明同包 tail store 在 checker safe watermark 等于该 seq 后仍合法到达，旧 `packetSeq <= safeWatermark` 错误拒绝，导致 `ADDRESS_STATS error=0x10`。修复方向是 LSQ latch ownership、严格 earlier 比较 `<`、并将统计窗口/包生命周期分开。

不要用 package allocation/completion/PASS 数量相等证明地址统计或 `verified=1`。

- Last good/first bad：旧259pkg seq0x62已PASS/safe=0x62后，同seq尾store在FST1062091到达被旧<=检查拒绝；旧seq0是另一份254包run。
- Broken invariant：LSQ所有权锁存而不重新采样live seq；同seq尾部不误判为strictly older。
- Fix：LSQ latched seq/window + watermark严格小于；不drop旧事件强行PASS。
- Validation：compile/static通过；最新run全路径pending/error/owner时序仍未审计。
- Regression：START/STOP、same-seq尾提交、连续PASS水位、旧LSQ回收必须覆盖。
