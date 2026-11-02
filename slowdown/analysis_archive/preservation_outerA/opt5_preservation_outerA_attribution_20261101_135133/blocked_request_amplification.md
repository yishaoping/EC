# 是否一次锁阻塞多个请求？先定义观察位置

`REQUEST_AMPLIFICATION = blocked unique A requests / preservation episodes` 的运行值、lower/upper非平凡数据界 **UNKNOWN**；preservation分母和请求身份历史都缺失。不能把2,231个release当preservation episode数，不能把valid&&!ready每cycle当新request。

| 观察位置 | 可证明结构界 | 运行估计/置信度 |
|---|---|---|
| 本Scheduler outer arb上的SourceA.io.a head | **单个连续packet lock中unique呈现head∈[0,1]** | 非实测；结构高 |
| SourceA queue中的pending requests | FIFO深2，两个normal outer sources0/1 | 非实测occupancy；结构高 |
| 同一lock内间接受阻的内层A/Get/Acquire、MSHR尚未排队需求 | 可有入口排队与依赖影响；无法从一根outer head推计数 | UNKNOWN |
| 多个checkpoint连续episodes累积造成同一head等待 | 可能，priority不看age；每episode重复阻塞仍是同一个token | 运行episode/身份未知 |

head界证明：SourceA→Queue_34(depth2)→outer arb，generated `do_deq=io_deq_ready&&!empty`。preservation锁持有时normal ready0，所以FIFO head不变、不会drop/retry；一episode中反复valid为**held request**。当head起初为空可入队一个后保持；不存在head换成第二笔而仍称同一个连续锁。队尾请求可被间接延迟，不能据[0,1]否定所有HOL。

`RETRY_AMPLIFICATION = associated blocked/retried events / blocked unique request` 运行值UNKNOWN，cohort可能空，不能给伪精确比值。主BOOM47,162 LSU retries是本地S2重lookup事件，不是TL arb每cycleretry。TL held-ready协议不重发新身份；只有经source/txn/LDQ token连接才允许映射。

本轮没有任何真实episode的blocked unique A/acquire/get/miss/retry/source/bank/set分解。省略数据的下界只可为0；整个B现有已接受A counts不约束因backpressure尚未接受的token。无关set可在inner lookup/SourceD hit进展，direct outer packet锁不是所有内层请求的全局停顿。

允许的逻辑链为：一个held outer miss → queue/MSHR/HOL → 多个dependent demand延迟；但累计request latency可以重叠、放大于时长，**ROI关键时间不能用请求数×锁长相加**。是否存在超67k的indirect critical损失仍NOT_PROVEN。
