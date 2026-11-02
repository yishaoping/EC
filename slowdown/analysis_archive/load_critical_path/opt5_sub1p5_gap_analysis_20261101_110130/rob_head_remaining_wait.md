# B剩余head load waiting

exact ROI `[698301,2347224)`，1,648,923 BOOM cycles。时间采用原SC pre-edge cycle，所有区间为半开区间；simulator time与BOOM cycle的偏移见numeric_audit，不将其他clock域cycle直接混入。
head由ROB索引与live LDQ functional_token匹配且未succeeded得到，native再匹配该token的已观测miss状态。窄定义head miss53,845；宽定义head pending80,832。STOP的head-load∩any-load-pending80,037是另一种较弱身份定义，且窗口不同，不能替换精确计数。

| 与head miss的交集 | exact值或仅由marginals所得上下界 |
|---|---|
| head_miss_AND_nack | [0, 47163] |
| head_miss_AND_retry | [0, 47162] |
| head_miss_AND_replay_issue | [0, 229] |
| head_miss_AND_mshr_busy | [53795, 53795] |
| head_miss_AND_scheduler | [0, 0] |
| head_miss_AND_mshr_full | [0, 0] |
| head_miss_AND_refill_wait | UNOBSERVED |
| head_miss_AND_port_conflict | UNOBSERVED |
| head_miss_AND_data_bank_conflict | [0, 0] |
| all_head_pending_AND_scheduler | [0, 26987] |

head miss∩busy53,795，outside busy50；full0。busy只表示某MSHR非空，不能替代refill仍未到达或refill写port被占用。nack/retry/replay交集为Fréchet bounds，非实测关联；229 replay issue cycles更不等于229 cycles的完整replay停顿。

251个在ROI完成的miss曾到head；其累计head周期53,845恰等于head miss counter。本指标是per-token累计headCycles之和，不是连续head-blocking episode直方图；不能据此声称max/p95 head episode。

latency completion-in-ROI队列可起于ROI之前，未完成样本censored：

| B cohort | N | 累计latency sum | ≥1024 samples | ≥4096 samples | 最大非空bin |
|---|---:|---:|---:|---:|---|
| detect→alloc | 960 | 157,622 | 18 | 12 | 14=[8192,16383] |
| alloc→refill | 1,883 | 157,331 | 8 | 5 | 14=[8192,16383] |
| detect→data | 1,052 | 211,045 | 22 | 16 | 14=[8192,16383] |

这些latency sum可跨请求并发、包含pre-ROI、不同cohort，不能相加、不能减作ROI收益。detect→data长尾说明少量长延迟存在，但缺少head/retry join，不能证明这些长尾贡献146k。

直接head miss全部理想删除上界53,845；宽定义全部删除80,832。`LOAD_PATH_ALONE_CANNOT_REACH_1P5`。该判断只限制观测到的直接head等待，未否定非head依赖、unblock提前、资源反馈等尚未归因的收益。必须避免用此上界作为所有load优化的全局反事实上界。
