# Bank仲裁：checkpoint不是被normal数据请求低优先饿死

`BankedStore.scala:88–174`固定优先：**SinkC > SourceC(由checkpoint借用) > SinkD > SourceDw > SourceDr**。4个8B单端口subbanks，L2 inner/outer都是8B beat。重叠bank选择高优先保留；不重叠bank可并行。无“全cache一把SRAM锁”。

| 问题 | 源码结论 | 实测状态 |
|---|---|---|
| preservation与谁竞争？ | capture后读挂SourceC优先端，仅SinkC重叠bank可挡它；SourceC本身被mux隔离 | 不知道相关ready-low次数 |
| fixed/fair？ | BankedStore固定priority，无age/RR；candidate选择也固定priority，MSHR schedule另为RR | 无starvation episode |
| normal refill能饿死checkpoint？ | SinkD与SourceD均低优先，**不能通过该bank arb挡它** | 此“normal数据抢占致starvation”子假设否定 |
| 反过来挡normal？ | checkpoint read优先SinkD/SourceD；连续候选还可global drain | 存在结构，duration/critical未知 |
| 共享单点？ | 单engine、单SourceC借口、单outerA输出；4SRAM子bank不等于4个独立L2 scheduler | B1cachebank |
| same-set？ | 目标set至ACK保留；入口高优先选中被锁C时还可能挡低优先A，即使A本身另一set | 无事件join |
| metadata/data并行？ | directory是单独SRAM，read/write互斥（read优先）；data为4subbanks。可有物理并行，但Scheduler要求相关schedule resources同时ready | 不把两者误称单端口 |
| one-cycle port被长占？ | waitAck已无checkpoint读，却SourceC schedule/read仍全局禁止；那是预约范围，不是SRAM在写 | 具体优化审查点，未赋收益 |

**不能从ProbeAckData24×8推bank-stall上界**：SinkC为wormhole流预留bank，`bs_adr.valid`可在C暂时无valid时送noop（noop只关bankEn，bankSel仍可压低优先）。实际阻塞包括valid gap，统计包数不含其时长。drain只看已入bank queue，capture后仍可能有其他set ProbeAck。这也阻止用流量低判定无等待。

SourceC>SinkD与SourceDw>SourceDr有数据/eviction顺序原因；直接调priority或给checkpoint降优先可能破坏forward progress/旧image读取，不能作为低风险默认fix。尚无事实证明67k主要在eligible→bankgrant，所以不把这一步写成已测主因。
