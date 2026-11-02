# Promotion 压力与吞吐决策

结论：当前不把faster promotion选为下一主优化。只读分析不改变串行promotion或ACK所有权语义。

| 指标 | 数值 | 语义 |
|---|---:|---|
| max safe awaiting |14 entries|traffic counter|
| safe queue waiting |15,714 cycles|traffic活动|
| source busy涉及SVB |23,788 cycles|traffic活动|
| safe waiting区间并集 |15,563 cycles|软件ROI lifecycle|
| issued/inflight区间并集 |22,837 cycles|软件ROI lifecycle|
| safe→terminal区间并集 |24,569 cycles|软件ROI；不可相加前两行|
| safe→terminal与legacy pending重叠 |1,171 cycles|完整optional前缀|

391个promotion issue→completion latency：min18、p50=60、p95=63、max91、mean57.40665 cycles。
capture→issue：min63、p50=6,876、p95=18,310、max20,990、mean7,675.50。
长capture年龄主要包含等待safe的寿命；不能用它证明promotion服务很慢。

唯一full区间开始时没有safe owner，最早safe恰在full结束前一周期。
因此这次容量压力没有呈现“safe queue持续积压导致无法分配”的因果链。

24,569只是已观测safe-entry活动的固定轨迹包络（约1.439% Opt4 ROI）；ROB临界交集未知。
即使按全部包络看，也远低于约85k主方向门槛；它并非全系统时序反馈下的无条件收益上限。
two outstanding promotion需要重新证明source/ACK复用、同line版本顺序和terminal归属，当前没有足够收益依据承担这些功能成本。
