# 下一步：MORE_OFFLINE_ATTRIBUTION

没有准备新Opt5硬件运行，没有COMMANDS_FOR_USER。A′未运行，`STRICT_PAIRING_PENDING`；本轮不启动也不机械要求A′。旧A′封存命令仍是历史资料，未更改其seal/guard/claim。

可立即继续的离线工作：

1. 对现有control complete prefix的长区间做FSM/IC/GC/commit条件归因，检验更宽noCommit∩load-pending是否主要在control阻塞期间；没有逐cycle load trace时保持不能join，而非用时间接近冒充因果。
2. 在源码和已有模块offline模型中审查option1进展唤醒/kill/token代际的活性、option3 SDQ load特化是否会生成false fire。仅设计/CPU模型，不做elaboration或仿真；若发现新静态机制仍须说明其runtime exposure未知。
3. 分离本地refill-port阻塞与外部grant服务时间所需的最小计数规格；只作为以后**独立证明值得跑的functional candidate**的附带诊断，不准备diagnostic-only run。需同版本记录blocked reason、token generation、head overlap、refill/meta valid&&!ready、SDQfull、逐请求retry bounded histogram及溢出计数。不能retrofit到旧run。

已有bounded reconstruction（本次numeric_audit保存intervals）：

| arm | complete optional ROI prefix | unknown suffix | scheduler prefix cycles | interval N | p50 / p95 / max |
|---|---|---:|---:|---:|---|
| A | [712114, 2289264] | 130,713 | 267,087 | 70 | 3180/8526/13762 |
| B | [698301, 2192911] | 154,313 | 280,215 | 76 | 2604/10522/12504 |

prefix基于8MiB host optional budget与每record≤448B的保守完整性证明；未知suffix不能hold-last。interval统计包括ROI/截止边界截断，非完整run episode分布。B native scheduler总347,409，prefix280,215，suffix总67,194但位置未知。没有FST也不尝试伪造head-load interval。

未来唯一新主要run的准入条件：一个明确主机制、够大且不重复计数的critical机会、最小RTL实现和offline正确性/活性证明、与B基线的兼容/差异审计。届时把functional改动与完整correctness/performance计数放同版，最多准备1次user-run candidate；能复用B就不重跑B，不先跑diagnostic，不做geometry sweep/MSHR扩容/无关bundle。本轮条件未满足。
