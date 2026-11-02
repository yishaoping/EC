# 三个最小设计选项（设计评估，均未实现/未准备运行）

目前没有同时满足“>100k-cycle可归因critical上界、明确首阻塞、低中复杂度修复”的方案。下面是由真实RTL结构支持的研究选项；64KiB均可独立保持/关闭，当前不把它定为Opt5。

| Option | 模块与信号 | 最小状态/逻辑 | timing / area | correctness / 独立验证 | 当前阻碍 |
|---|---|---|---|---|---|
| 1 依赖资源进展的LDQ retry抑制 | lsu.scala `ldq_wakeup_idx` eligibility、nack live token；dcache/MSHR反馈具体not-ready子原因与blocking owner generation | 每LDQ槽blocked reason + owner/set generation标记；复用16槽LDQ，不新建request queue；相关refill/owner release/SDQ/RPQ进展解除，另保留有界recheck保证活性 | 低至中：若仅3-bit reason+1valid每槽约64b，但owner generation/set标记另计，不能声称总共64b。eligibility必须注册，避免ready组合路径回到age arbiter | 保留branch kill/exception、token代际、ordering/uncached/LR/AMO规则；进展事件丢失或owner复用不能永久睡眠。age仲裁与请求保留已存在。可在32K/64K独立验证 | 目前miss-not-ready不是唯一first blocker；无retry∩critical时间join；抑制lookup可省端口工作，却可能不提前数据/ROI |
| 2 定向refill/meta进展仲裁 | dcache.scala dataWriteArb pipeline/effect与refill、meta读写、`refillOwnerMatch`；mshrs状态/line buffer | 仅对已证critical阻塞加入一个held urgent/refill-age状态，复用现有grant；具体选择策略须等port-wait归因，不能提前指定抢占 | 中：arbitration选择路径/扇出会变长；必须注册或维持held grant，不能新增长head-token→array-ready组合锥 | 不抢占S3 held write、不越过reserved/completionPending/epoch/order；ordinary load line-buffer直返已存在。可独立于cache容量 | 没有实际refill valid&&!ready、meta publish等待、head overlap；不能判断外部grant慢还是本地端口慢，不能把busy194,905全删 |
| 3 SDQ门控对load特化 | mshrs.scala global `sdq_rdy`用于`pri_val`/secondary valid/`io.req.ready` | cacheable普通只读load不消耗SDQ时，全部相关valid/ready条件一致特化；通常无需新queue/state，不能只改ready导致伪fire | 低逻辑面积，改shared admission扇出；须审查read/write、AMO/prefetch/MMIO分类与SDQ id使用 | 保留store/AMO容量与数据所有权；valid/fire分配一致，协议fault及同set限制不放松。32K/64K均能单独验证 | 未导出SDQfull周期/critical overlap，可能全程没有此机会；收益下界0 |

不建议直接放松same-set/secondary-drain/owner guards：需要新owner并行协议或改变有限drain集合，已超出“廉价小改”且可能破坏package保护。也不新增age queue、不声称linebuffer bypass是新发明。
三项不打包；任何进入下一次主要functional run的实现必须先选定一个有收益证据的主因果机制。此次不改RTL、不编译，不存在“实现已验证”的声明。
