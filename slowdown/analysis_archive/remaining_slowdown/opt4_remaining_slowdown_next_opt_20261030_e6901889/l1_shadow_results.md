# L1 shadow：两种敏感性都存在，但不等于ROI预测

真实L1为32KiB/256sets/2ways/64B/6MSHRs。
实际access156,289、hit153,017、miss3,272。S0 miss3,286，误差 **0.427873%**，sanity **PASS**。

| Model |Geometry|Access|Hit|Miss|Miss reduction vs S0|Raw replacement|Raw dirty victim|
|---|---|---:|---:|---:|---:|---:|---:|
|S0|32KiB/2-way/256sets|156,289|153,003|3,286|0 / 0.0000%|278|0|
|S1|32KiB/4-way/128sets|156,289|154,795|1,494|1,792 / 54.5344%|671|568|
|S2|64KiB/2-way/512sets|156,289|154,988|1,301|1,985 / 60.4078%|467|427|
|S3|64KiB/4-way/256sets|156,289|155,111|1,178|2,108 / 64.1509%|332|296|

32K/4way减少1,792 misses，支持conflict sensitivity；64K/2way减少1,985，支持capacity/index sensitivity。
两者均明显改善，不能把它们相加或当作纯正交的conflict/capacity分解：固定容量改变ways也改变sets/index。
64K/4way比64K/2way仅再少123 misses（约9.45% S2 misses，或S0的3.7432个百分点）。

## Replacement不是同一定义

实际replacement1,419、dirty1,126是primary admission选中valid victim。
S0 replacement278、dirty0是valid metadata tag overwrite；metadata invalidation另有1,415，dirty retirement1,411。
S1/S2/S3为shadow installation victim。因此不能报告可比较的replacement reduction百分比。
原始算术S0-alt为 **-393/-189/-54**；actual-alt为 **748/952/1,087**，都只是不同定义数值相减，**不是硬件replacement收益**。
实际permission misses122、set-full misses991、probe evictions11。
shadow替代模型并未逐项区分全部强制preservation invalidation，S0总miss吻合不证明替代模型的因果保真性。

## 临界路径机会边界

MSHR busy并集315,637；entry-cycles317,542；full0。
317,542/3,272 =97.0483是entry-cycles/actual-miss比值，**不是实测miss latency**。
仅用于敏感性比较的equal-service proxy：

|候选|Proxy cycles|占Opt4 ROI|达到5%门槛所需平均关键周期/avoided shadow miss|
|---|---:|---:|---:|
|32K/4way|173,911|10.183%|47.65|
|64K/2way|192,641|11.280%|43.02|
|64K/4way|204,578|11.979%|40.51|

Proxy=avoided shadow misses×97.0483；它既不是预测ROI，也不是严格上界。
315,637只能提供所有L1 MSHR活动的**资源包络**，不是任何geometry的关键路径保证；
对已存在MSHR活动的局部删除模型，可把其临界交集保守限制在[0,315,637]，
但不能将该共同包络直接标成某候选收益区间，更不能推断时序反馈下的全局上界。

旧run没有逐miss→MSHR lifetime→ROB/LSU stall身份join，也没有被替代模型避免的miss集合的服务时长。
现有数据没有证明上述平均关键周期或足够的未隐藏比例；严格可保证收益仍为0。
条件性首选 **64KiB/2-way**：比32K/4way少193 misses且保留2个tag比较器；仍未获functional GO。
