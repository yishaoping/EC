# L1-Causal-1 最终状态

**INCONCLUSIVE_DUE_TO_CORRECTNESS_OR_MEASUREMENT**

`NEXT_OPTIMIZATION = NONE_JUSTIFIED`

两组均完成真实 elaboration、RTL generation、Verilator build，并实际执行仿真。
**A 完整 PASS，ROI1,707,863；B 触发 checker3 ownership watchdog/assert24，exit1，未完成ROI。**
因此不存在有效的ROI、miss或critical-path paired delta，不能支持或否定L1 capacity的性能收益。

|指标|A 32KiB/2way|B 64KiB/2way|A−B|
|---|---:|---:|---:|
|软件ROI cycles|1,707,863|UNAVAILABLE|UNAVAILABLE|
|净改善 cycles / %|—|—|UNAVAILABLE / UNAVAILABLE|
|实际L1首次lookup tag misses（traffic窗口）|3272|UNAVAILABLE|UNAVAILABLE|
|MSHR busy / full cycles（精确ROI）|313,150 / 0|UNAVAILABLE|UNAVAILABLE|
|RPQ replay events / active cycles|321 / 321|UNAVAILABLE|UNAVAILABLE|
|nack retry events / active cycles|111,548 / 111,548|UNAVAILABLE|UNAVAILABLE|
|ROB-head miss-wait cycles|139,694|UNAVAILABLE|UNAVAILABLE|
|head∩MSHRbusy / full|139,500 / 0|UNAVAILABLE|UNAVAILABLE|
|scheduler unavailable|318,150|UNAVAILABLE|UNAVAILABLE|
|scheduler∩MSHRbusy / full|154 / 0|UNAVAILABLE|UNAVAILABLE|
|head∩scheduler|17|UNAVAILABLE|UNAVAILABLE|

A 功能、verified1/checksum43439728、integrity、protocol、ordering、L2 read-consistent observer、
STOP40–45、ROI marker与native causal/守恒检查全部PASS。B 的 start marker698301有效，
但无stop、verified/checksum、最终L1/L2 summaries；B correctness FAIL，其observer最终验证不可用。
已观测prefix的integrity ledger通过不等于整次run正确。

已定位到seq67本地CANCEL入队后context cleanup未闭合、result handoff未开放的直接阻塞链；
具体上游trap/start/return触发条件尚未证明。下一步先关闭该correctness问题，再考虑新成对性能实验。
没有改checker、MSHR、replay/scheduler、SVB16或L2策略，没有4way或正式Opt5。

L1 miss reduction转化为critical-path cycle reduction：**NOT YET PROVEN**。

[失败分析](r2_B_correctness_failure.md) · [20项回答](answers_20.md) ·
[设计/审查](experiment_design.md) · [改动](code_changes.md) · [计数口径](causal_counter_schema.md) ·
[计数对照](causal_counter_comparison.md) · [observer](observer_validation.md) ·
[性能归因](performance_attribution.md) · [Opt5判决](opt5_decision.md) ·
[validation](validation_result.json) · [manifest](run_manifest.json)

最终结果只使用`revisions/r2/arms/`。source fingerprint
`b6f9a8739a0be1a64cd349625e37dc8b5b8cd246b418041bc3ee68dd1af414b1`。
两组source/software/tool seal一致，实际仿真参数一致，时钟/L2生成配置一致；仅BOOM sets256→512。
原有效Opt4结论保持。R0 elaboration失败；r1 marker失效的测量已排除，旧证据均保留，见[marker RCA](roi_marker_rca.md)。
