# Performance attribution：禁止解释失败对照

**INCONCLUSIVE_DUE_TO_CORRECTNESS_OR_MEASUREMENT**

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

A 的miss-associated ROB-head wait139,694，head∩busy139,500，busy313,150/full0，
表明本轮instrumentation能观测到miss关联head waiting；这并不证明减少miss会减少这些周期。
B未完成，无法建立miss→MSHR/replay→ROB critical→ROI的paired delta。
也无法判断“miss显著下降而critical counters不变”、或“收益主要由其它反馈产生”。

禁止用B失败前缀与完整A比较；禁止用历史shadow64K miss1301代替B实际miss；
禁止把A的exposures加成剩余slowdown，或用miss×mean latency估收益。
A的四项互斥分区只作A内部会计守恒：`{"both": 17, "head_miss_only": 139677, "neither": 1250036, "scheduler_only": 318133}`。
没有B分区，不存在净收益分解。

L1 miss reduction → critical-path cycle reduction：**NOT YET PROVEN**。
