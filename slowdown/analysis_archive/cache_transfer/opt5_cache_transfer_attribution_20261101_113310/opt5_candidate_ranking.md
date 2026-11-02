# 最多5个候选：设计审查顺序，均未获正式Opt5资格

排序按具体机制/证据与下一步价值，不代表已有可兑现收益。cache-transfer优先展示；frontend未入选。L1 refill按用户优先级已先审完，发现旁路/decoupling已存在，当前最具体的新结构疑点移到L2 preservation。

| Rank | Mechanism | Independent critical UB | Conservative gain | RTL complexity | Area/timing risk | Confidence |
|---|---|---|---:|---|---|---|
| 1 | WRITEBACK_REFILL_INTERFERENCE / L2 preservation drain + strided Put | UNKNOWN；已测release phase100,915不覆盖全部机制 | 0 | 中：full-line snapshot buffer/pipelined reader/held burst | 512bit+control；bank节奏/ordering中高风险 | 结构高，运行主因低 |
| 2 | L1_REFILL_SERIALIZATION / shared LB read + row staging | UNKNOWN；直接head pending envelope80,832非全局UB | 0 | 小到中：extra row holding/age arb/skid | 不加端口方案较低；若改SRAM则高 | 结构高，critical预算低 |
| 3 | L1_L2_REQUEST_ARBITRATION / response resource coupling | UNKNOWN；无A/D ready-low | 0 | 小到中：age/fairness或bounded response skid，先定瓶颈 | ready路径、TL lock/credit中风险 | 结构高，选择哪一处低 |
| 4 | L1_PORT_CONFLICT + progress-aware LSU retry | UNKNOWN；nack不能直接兑换cycles | 0 | 中：resource-release wake/retained blocked reason | token/epoch/flush状态与forward progress中高风险 | retry放大高，可删cycle低 |
| 5 | BOOM_CHECKER_BACKPRESSURE / ownership-result availability | UNKNOWN；scheduler exposure347,409 | 0 | 未定，先按pkg分解wait | CDC/ownership/watermark高风险 | control暴露高，removable归因低 |

## 每个设计的9项成本/收益约束

| Rank | RTL修改点 | 新storage | 新port | SRAM timing | Hit latency | Correctness风险 | Estimated critical benefit | Fixed-trace UB | 与64K叠加 |
|---|---|---|---|---|---|---|---|---|---|
| 1 | L2Preservation.scala read/delay/send；Scheduler outerA/borrow/lock | 64B checkpoint buffer+beat/control | 可用现有bank读端，不预设新增 | 读请求更密可能增竞争；实现待审 | 不直接改L1 hit；L2争用可能变 | 旧脏image一致、CachePreserveTxn/source、整包、terminal ACK；不能早解锁或释放 | UNKNOWN | UNKNOWN；post-firstC activity只是局部100,915 | 结构可独立；B已64K，需测交互，不加历史58,940 |
| 2 | mshrs LB read arb/rowValid/refill，dcache owner/dataWriteArb | 约1 row+identity/skid（方案待定） | 不加为优先；双端口另评 | 不加端口也需验证read/write时序 | 保持既有hit pipeline是设计目标 | LB响应owner、row order、flush、RPQ terminal、reserved epoch | UNKNOWN | UNKNOWN；direct head上包络80,832仅局部 | 可能；不同miss并发/替换会改变预算 |
| 3 | MSHR A/E arbiters，L2入口/SourceD D/ACK skid（仅选实测堵点） | age bits或小skid，未定 | 无 | ready/arb组合路可能增 | 不增加hit latency是目标 | multibeat held-valid、source/sink、ACK credit、防饥饿/deadlock | UNKNOWN | UNKNOWN | 可能，非保证可加 |
| 4 | LSU age-wakeup/nack retention + dcache真实blocked reason释放 | 每LDQ少量reason/epoch状态 | 无 | wake组合扇出需审；不改array目标 | hit可立即调度需保持 | 不漏probe/WB/owner变化唤醒，flush/token重用、SC/AMO forward progress | UNKNOWN；首先可能只降访问/功耗 | UNKNOWN；已测direct miss<=53,845 | 可能，64K降低可抑制事件 |
| 5 | R_IC scheduler/ownership/result CDC，先不改 | 未定 | 非cache SRAM port问题 | 无直接array改动 | 无直接L1 hit改动 | release必须真实result acceptance，不能把frontend空闲当available | UNKNOWN | UNKNOWN；347,409仅状态暴露 | 可能，需package critical attribution |

这些是有明确修改边界的**设计假设**，没有硬件patch、默认新配置或正式run launcher。优先无容量/way增加、无hit延迟、无新增SRAM端口；不能用面积成本替代收益证据。不会重做已经存在的ordinary-load LB bypass/LDQ age priority，也不会盲改BankedStore优先级（SourceC>SinkD等有coherence原因）。

唯一主候选判断仍为 `NONE_JUSTIFIED`。L2preservation最值得继续审，不足以声称当前能独立恢复146k，或宣称必须64K+fix即可达标。
