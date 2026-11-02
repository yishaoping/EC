# Independent critical UB：范围与未知值

缺口146,410，严格整数saving至少146,411；tier阈值分别>=150k、100k–150k、50k–100k、<50k。只有有归因的独立关键路径上界才能分tier；activity duration不能冒充critical-removable budget。

| Mechanism / scope | Measured exposure / scoped upper envelope | Independent critical UB | Conservative credit | Tier |
|---|---:|---|---:|---|
| L1 release 首C→ACK，固定B中该阶段同时发生的直接阻塞 | ROI union100,915；并非source总生命周期 | 未证明critical交集；phase-local最多100,915 | 0 | exposure落100k–150k；未取得Tier2资格 |
| 其中lastC→firstL2bank | 同cohort67,366 duration | 未证明；phase-local≤67,366 | 0 | 不是已成立Tier3 |
| 其中lastbank→ACK | 同cohort4,546 duration | phase-local≤4,546，critical交集未知 | 0 | 此局部ACK回程单独为Tier4 envelope |
| L1 refill/端口/request arbitration整机制 | 未导出phase exposure | UNKNOWN | 0 | UNKNOWN |
| L2 checkpoint/drain/outerA/peer wait，包括checker与非head链 | 未导出duration与critical join | UNKNOWN；100,915不能上限整个机制 | 0 | UNKNOWN |
| 已测direct main-core headmiss | 53,845 | 删除所标直接wait≤53,845 | 0 | 仅该受限范围Tier3 |
| 已测all direct headload pending | 80,832，包含上行53,845 | 删除该nested envelope≤80,832 | 0 | 仅该受限范围Tier3 |
| BOOM scheduler unavailable | 347,409 | 该control状态暴露上界；removable部分UNKNOWN | 0 | 尚非Tier1候选 |

只根据边际计数，ROI release phase与headmiss交集为[0,53,845]、与all headpending为[0,80,832]；没有精确join。phase exposure不限制提前/延后导致的依赖链反馈，也不覆盖pre-C source reservation、checker请求或checkpoint transaction。因此 **不发布“所有transfer UB=80,832”或“所有WB UB=100,915”**。

需要分别说明四层：直接症状为retry/head wait；立即blocking谓词为MSHR not-ready/victim/WB等（存在与计数PROVEN）；上游trigger是否是具体refill/channel/checkpoint阶段（UNPROVEN）；下游重复retry放大结构PROVEN，但其关键cycle预算UNPROVEN。报告没有“已排除缓存传输”的结论。

没有把nack events×假定penalty、misses×average service、checkpoint数×burst间隙作为ROI估计。既有58,940 reference ROI改善与当前B已包含64K，不能从B再加一次；未来transfer fix叠加64K也需重新执行验证。direct head wait、retry、refill、writeback、scheduler等交集未闭合，不允许相加凑146k。

`INDEPENDENT_CRITICAL_UPPER_BOUND=null (whole-mechanism unknown)`，`EXPECTED_RECOVERABLE=null`，`CONSERVATIVE_RECOVERABLE=0`。0是当前不授予收益的保守记账，**不是证明实际收益为0**。没有候选满足当前>=100k归因门槛。
