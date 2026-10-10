# Bug 1769000 / 459000：frontend redirect regression

**状态：历史 unresolved；方案和静态生成记录保留，动态修复未验证。**

1769000 规格基于旧 e4 重复交付 ret 的证据，要求 Frontend/IBuf/R_BJL 保证一次取指交付的 prefix、reservation、FQ fire、commit/rollback 生命周期。实施后出现 459000 watchdog；现有记录把当前 first bad 判为 redirect patch 破坏普通启动 context，而不是旧 e4 根因已被验证。

风险点：redirect 当拍不能用旧 live checker mode；pending 只能在目标 ICache `req.fire` 释放；S1/S2/TLB/BTB/replay owner 必须与同一次接受事件对齐；不能用组合 `req.valid → FQ valid` 门控制造环。

1769000 的 Scala compile、Chisel elaboration、FIRRTL lowering、firtool/CheckCombLoops 和 RTL 生成通过，但没有整机仿真；因此这是“可运行验收的静态候选 patch”，不是已验证修复。

- 原1769000 last good/first divergence：checker3 e4，FST3009393..3009417的FQ前缀重复交付ret PC0x8000489a；WB随后多退休一次，4074源指令+合法startup=4075预算在最后LSL load前用完。
- Causal chain：未截断的RVC后缀重复交付→多退休→tail提前等待→最后load已在LSL却无指令消费→safe停e3→shadow writeback/BOOM watchdog。剩余load无需等待writeback“产生”，不能凭空建立该等待边。
- Broken invariant：reserve一次、emit一次、owning CFI WB真退休commit一次；redirect目标及owner保持到真实fire。
- Fix：registered checker descriptor/prefix/endMask、post-commit rollback；后续459000 regression由pending+settle+capturedPC重做redirect生命周期。
- Validation：10-10独立v1Config编译/elaboration/FIRRTL/firtool生成通过，当前Frontend源码/生成物hash吻合；没有由该记录提供动态first-bad消失证明。最新整机291包运行不再watchdog结束，但仍verified=0，不能宣称本bug完整验证。
- Regression：09日首次编译PASS却出现req.valid→emit/FQ/IBuf→take_pc→req.valid组合环；修正环后又出现更早ordinary启动regression。
- Unresolved：allocation→admission timeout覆盖缺口、其它配置latency1/VM/ITIM/clockgate边界。
- 来源：history/reports/frontend/1769000_fix_spec.md与1769000_sol_review.md第4–6节。
