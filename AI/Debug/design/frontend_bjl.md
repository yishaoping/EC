# Frontend / IBuf / BJL 当前设计边界

来源：history/reports/frontend/1769000_fix_spec.md 与 1769000_sol_review.md第6节；当前源码Frontend/IBuf/R_BJL/RocketCore核对。设计/静态机制不等于最新运行的exactly-once证明。

- descriptor：捕获完整response及PC/seq/GPA，CLASSIFY→WAIT（resident head的PC/长度匹配）→READY；READY持有payload到FQ fire，背压不重复reserve。CFI前面的完整普通指令先交付，避免等后方BJL但前方load阻塞DATA。
- prefixLength定义真实交付前缀，taken不代表截断。bjlEndMask随数据移位/缓存/跨块拼接，仅完整CFI最后半字带ownership。
- reserve、emit、commit分开：WAIT接受一次reserve，FQ fire一次移交，owning CFI只在WB真正退休一次commit；同拍commit+rollback保留post-commit游标，kill/replay不commit。
- 管理bit12 JALR在当前checker软件用于本地启动/管理，不reserve/commit源程序BJL；不要扩大成任意源程序指令豁免。
- redirect：capture pending PC/speculative并settle，只有具体目标ICache req.fire释放pending；未接受时PC/owner保持，不制造ghost S1/S2，不重新解释旧response。
- clear/handler：清旧checker descriptor/owner，等真实redirect杀旧流水后ack；不无目标清handler，也不把ack接入tail/ARF completion形成等待环。
- flow-through FQ/IBuf构成反馈风险：不要组合req.valid门控checker_emit/legacy_emit valid。源码中的state-register切边仍必须目标FIRRTL验证。

待验证边界：ready低、PTW背压、latency1、cross-page CFI、fault/replay、连续redirect、ordinary/checker转换、clear/handler并发、快速slot复用及独立commit scoreboard。
