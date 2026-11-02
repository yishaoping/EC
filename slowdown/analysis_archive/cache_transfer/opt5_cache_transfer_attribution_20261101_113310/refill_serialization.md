# L1 refill serialization：共享row资源，不是全局whole-line锁

`mshrs.scala:849–915`：nLBEntries=nMSHRs=6，`Mem(nLBEntries*cacheDataBeats, UInt(encRowBits.W))`，即6×4×128bit的full-line容量。**一个共享LB访问调度**：incoming D写优先，只有otherwise执行固定索引read arb；ordinary waiting-load response和install row fetch共用读端。持续D写可以推迟LB读，即使array安装空闲；没有相关blocked-cycle counter。

`mshrs.scala:536–575`：每个MSHR可持有install状态，按row执行 `io.lb_read` → register `rowValid` → `io.refill.fire`清rowValid，再读下一row。现有单row暂存形成每row读/交付的交替阶段；6个MSHR能同时待refill，但LB/refill/meta/install arb逐次串行。没有一个锁令整条cache line从头到尾排他占全局所有hit端口。

`dcache.scala:1434–1540`：install owner需pending WB same-set、S3/completion及pre-freeze访问drain；refill写必须匹配reserved MSHR/txn/epoch/tag/image；pipeline effect的dataWriteArb input0优先于refill input1；final metadata publish另等local drain。set/slot reservation可能造成同set长尾，不能移除owner验证以换速度。

当前使用 **BoomDuplicatedDataArray**（源码439–461/798，已生成instance与bank-nack常0核对），每lane/way独立逻辑read与write，`io.nacks=false`。因此不能声称refill写必然互斥所有普通read hit；同地址/owner冲突仍由cache逻辑约束。metadata lookup与publication另有arb/ready，不等同独立数据读端；共享meta read优先 replay/probe/WB/MSHR/LSU/prefetch，data read优先replay/WB/LSU。

| 目标量 | B观测 | 能否作为收益 |
|---|---:|---|
| physical final-row completions | 1,883 | event count，非stall cycles |
| all MSHRbusy | 194,905 | 同时包含request/service/RPQ/victim/install/E，非REFILL_BUSY |
| `REFILL_BUSY_CYCLES` | null | 不把MSHRbusy改名 |
| `REFILL_BLOCKING_L1_ACCESS_CYCLES` | null | 不能用row数×固定penalty估计 |
| `ROB_HEAD_WAITING_DURING_REFILL_CYCLES` | null | direct head-miss53,845只是更宽的已测上包络 |
| headmiss AND MSHRbusy | 53,795 | 证明busy同时存在，不定位refill阶段 |

可审查的小改动：一个额外row holding register、LB read/response skid、在不改SRAM端口的前提下允许fetch下一row与交付当前row重叠；或按age的共享读仲裁。需证明读写hazard、held valid、flush/RPQ terminal、install owner与generation不变。普通load已有LB bypass，不能重复将其列为新收益。是否影响SRAM timing取决于实现，不宣称可免费双端口。active prefetch/reacquire路径未完全量化，故不发布 `4*(allocations+upgrades+6)` 类未经闭合的service-slot上界。

结论：结构性potential serialization已确认；造成多少nack/ROB/checker critical stall尚未证明，独立>=100k预算未知。本轮不扩大MSHR、不改容量或端口。
