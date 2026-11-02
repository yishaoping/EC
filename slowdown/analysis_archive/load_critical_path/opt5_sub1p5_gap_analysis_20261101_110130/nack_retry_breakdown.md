# nack / retry：真实原因、窗口与观测限制

active memory width=1，因此下列load reason事件数也是该predicate被采样为真的nack-cycle exposure；predicate之间不互斥。普通load的S2原因与LSU nack对齐；stale-S3 nack为store-only。数值来自exact软件ROI。

| RTL predicate | A events/cycles | B events/cycles | 定义 |
|---|---:|---:|---|
| s2_nack_miss | 111,074 | 39,072 | S2 miss且MSHRFile req.ready低；非独占首阻塞原因 |
| s2_nack_victim | 474 | 8,087 | S2 hit但同set/way有不同tag的MSHR owner |
| s2_nack_data | 0 | 0 | 活动duplicated data array常量false，生成RTL亦为0 |
| s2_nack_wb | 3,885 | 2,354 | S2 miss且同set writeback匹配 |
| s2_nack_hit | 0 | 25 | S1 probe/metadata hazard延迟到S2 |

总load nacks A111,557/B47,163；retry A111,548/B47,162。`miss`与`victim`因`!s2_hit`/`s2_hit`互斥，B并集47,159；仅4个nack在两者之外。writeback2,354和probe25可能与这些原因重叠；不能把原因之和当总nack，也不能把4解释为精确owner类总数。未导出原因还可与miss/victim同时出现。

`s2_nack_miss`并不证明MSHR数量不足：ready由所选lane、cacheable/MMIO、全局SDQ、同set/tag匹配、primary ready、secondary状态/RPQ ready共同决定。即使有空MSHR，同set不同tag也不允许primary；同tag secondary在drain/meta/finish/probe/第二acquire/跨package写/协议fault/RPQ满时也可能不ready。req.valid=0时ready也可低，故39,072是nack predicate，不等于真实valid&&!ready rejection20,433。MSHR full=0、最大occupancy2/6，排除“必须增加MSHR”结论。

完整nack OR（dcache.scala:1250–1304，已保存逐行摘录）：

- 上述miss/probe/victim/data/writeback。
- `s2_clear_freeze_read_bypass_miss`：clear-freeze旁路只准hit，miss退回。
- `s2_owner_block`：clearing、stale slot epoch、frozen/reserved/completionPending hit，或reserved非secondary miss。
- `s2_clear_slot_conflict`：freeze同set/way且tag不命中。
- `s2_write_busy`：S3有效或completionQ非空，对write生效。
- lane0 `s2_realloc_owner_conflict`：tagmiss拟重分配到同周期S3旧store effect的set/way。
- lane0 `l1CrossPackageBlocked`：跨package保护下的write；与上项必须保留owner/order语义。
- stale-S3 store nack输出路径独立存在，本次普通load因果计数不应解释为该store路径。

port/arbitration backpressure不必产生nack：LSU ready由meta/data arbiter及freeze许可共同决定。meta读优先级replay/probe/WB/MSHRmeta/LSU/prefetch；data读replay/WB/LSU。refill写在pipeline/effect写之后；replay还受replayPipelineBusy/S3/completionQ限制。这些是结构条件，缺少实际blocked-cycle细分，不能归为已测refill-conflict损失。

load/store现有范围：STOP为traffic窗口B load nack47,210、store nack4,088，A load nack111,719、store nack6,311。B load/store request wait1,541/81,784；总83,325。exact ROI仅有load细分，未导出store nack逐原因。STOP的load nack与native精确ROI的47,163不同，不能混窗。

缺失值明确为null：逐request/line重试次数与直方图、最大retry episode、head相关nack/token join、refill/port独占阻塞周期。原日志未保留native14/15/21/22的逐事件；SC14/15是store-preservation命名空间，不能冒充load miss事件。成功运行没有saved FST/VCD，ring不在成功时导出，compact capture过滤掉S1/refill printf，因此离线无法恢复这些被丢弃的信息。
