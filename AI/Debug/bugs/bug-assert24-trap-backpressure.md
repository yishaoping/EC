# assert24：异常生命周期与数据 ready 原子性

**状态：历史静态结论；整机回归未证明。**

seq40 postchecking 的 timer interrupt 可能把 `excpt_mode` 带入下一包，seq45 在不可恢复上下文中 admission；另有多 lane packet-ready OR 可能在某个 LSL lane 不 ready 时消费整包。修复记录要求 matching xRET/trap depth、clean context admission、per-lane atomic ready、overflow 可观测和 bounded progress。

这些风险必须在异常、xRET、FQ/LSL 背压和 CDC full 组合中定向验证。

- Last good/first bad：seq40 postchecking trap未matching mret返回，seq45在excpt_mode下admit；另checker4近满LSL ready下降但其它ready OR仍推进DATA，属于独立transport first-bad。
- Causal chain：trap lifecycle遗漏→non-runnable admission→数据积压无请求→watchdog；backpressure支链会独立丢logs。
- Broken invariant：clean executable context才admit；每个有效lane有自己的acceptance，DATA整体只能原子fire。
- Fix：trap_depth/resume、matching xRET、type-specific beat readiness/overflow、bounded progress。
- Validation：历史project chipyard compile成功，未生成/仿真；最新拓扑/ordered END需要重新review。
- Regression：postcheck/trap/completion同拍、handler与clear、CDC full/slot reuse覆盖。
- 来源：history/reports/legacy_ai/assert24_1187_comprehensive_analysis.md与assert24_robust_hardware_fix.md。
