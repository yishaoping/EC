# Bug 导航与状态

当前未解决 failure 唯一入口为 ../state/current_debug_state.md。以下是历史机制；禁止把旧root cause直接套入最新run。

- bug-528000-count-boundary：600/558/42 drain计数链，directed验证通过，整机未证明。
- bug-1769000-frontend-regression：重复ret与redirect启动regression，最终静态生成通过，动态未证实。
- bug-461000-lsl-syncfifo：wrong type、ready/read等待环，528000 run中的旧first-bad已消失。
- bug-snapshot-next-pc：invalid empty-head PC与ARF边界；528000中23次snapshot审计通过。
- bug-shadow-writeback-coherence：TtoB/本地Nothing与metadata clear重发。
- bug-strict-store-token、bug-killed-store-stq-replay：exact identity/once-only及迟到nack。
- bug-barrier-traffic-window、bug-20260930-package-address：窗口、ownership和safe等值。
- bug-anchor-admission-result、bug-assert24-trap-backpressure、bug-boot-scoreboard：早期CDC/result/trap/backpressure/boot机制。
- [bug-palimpsest-c-baseline-order](bug-palimpsest-c-baseline-order.md) 记录两拍 C 队列引出的首个整核停顿及同址基线倒退的定向反例。
- [bug-palimpsest-cached-amo-predecessor](bug-palimpsest-cached-amo-predecessor.md) 记录缓存 AMO 等待前驱 PASS 的整核现象及定向反例。
- [bug-palimpsest-cold-lookup-retry](bug-palimpsest-cold-lookup-retry.md) 记录 Restart 后的冷查询重发以及跨 LSU 请求空窗保留查询结果的修复。
- [bug-palimpsest-trap-context](bug-palimpsest-trap-context.md) 记录随 SCP 保存和恢复的异常上下文、R_IC 与 R_RSU 的临时状态。
- [bug-palimpsest-sourcec-pressure](bug-palimpsest-sourcec-pressure.md) 记录 History 压力屏障阻塞安全 Checker victim 的整核轨迹与定向对照。
- [bug-palimpsest-checker-cancel-before-copy](bug-palimpsest-checker-cancel-before-copy.md) 记录 Seq16 取消后的迟到 COPY/JLR 导致 Checker 无校验执行 Main 的反例。
- [bug-palimpsest-trusted-refill-recovery](bug-palimpsest-trusted-refill-recovery.md) 记录主机清零后冷恢复重新引入 tohost 指针的 HTIF 证据与修复验证边界。
- [bug-palimpsest-seq-management-trap](bug-palimpsest-seq-management-trap.md) 记录 Seq transport 等待无包管理异常返回、而该异常被 L2 维护冻结访存的循环等待。

- [bug-palimpsest-translation-refill](bug-palimpsest-translation-refill.md) 记录恢复 SFENCE 后迟到响应重新装入旧物理地址的 DTLB 和 I-TLB 反例。

- [bug-palimpsest-io-seal-cancel](bug-palimpsest-io-seal-cancel.md) 记录真实 I/O 边界下 Checker 缺生产者封口、无进展超时和额外恢复。
- [bug-palimpsest-restart-late-owner](bug-palimpsest-restart-late-owner.md) 记录排空确认后新 Probe 到达，控制器重启未检查实时 owner 的真实缓存反例。
- [bug-palimpsest-restart-snapshot-loop](bug-palimpsest-restart-snapshot-loop.md) 记录实时重启排空检查与完整 Core snapshot/redirect 接线形成的组合反馈及复用寄存 RSU 排空的最终修订。
- [bug-palimpsest-closed-package-capacity-hold](bug-palimpsest-closed-package-capacity-hold.md) 记录检查会话结束后，迟到封口请求匹配保留编号并错误保持退休的整核反例。
- [bug-palimpsest-execution-stop-io-join](bug-palimpsest-execution-stop-io-join.md) 记录真实LSU停止边界、未缓存AMO效果包号与重复旧值响应的完整交接链。

每次修复验证完成补写对应bug的实际证据、独立回归和最终状态，更新history，不继续扩充current的旧问题叙述。

- [GHM维护请求与同步链物理映射](bug-palimpsest-ghm-physical-cdc.md)：实际Vivado组合前置/SRL告警，最小候选实验通过，生产Scala验收待完成。

- [L1 slot epoch边界](bug-palimpsest-slot-epoch-boundary.md)：真实分配跳零而三处install/refill仍普通+1，边界反例FAIL，统一现有规则候选验证中。

- [真实中断后的CSR影子更新分歧](bug-palimpsest-interrupt-csr-compare.md)：真实CLINT/MSIP与恢复交叠，无注入normal首次CSR反例FAIL；无新状态候选组件PASS，完整Core待验收。

- [容量前缀提前释放导致旧包缺seal/END](bug-palimpsest-capacity-seal-release.md)：25/50MHz真实Core反例，独立既有seal握手候选验证中。

- [bug-palimpsest-grantack-preemption](bug-palimpsest-grantack-preemption.md)：同组C→History→外层GrantAck循环，生产最小E-only抢占例外、真实组件反例与整核回归边界。
