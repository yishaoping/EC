# 下一步：MORE_OFFLINE_ATTRIBUTION，无硬件命令

`NEXT_ACTION=MORE_OFFLINE_ATTRIBUTION`，`COMMANDS_FOR_USER=[]`。本轮没有可证明>=100k独立critical预算的明确优化，因此不准备或执行Opt5硬件run；也不要求diagnostic-only run、A′、geometry/MSHR sweep。缺少的per-cycle事件不能从已保存汇总凭空恢复。

离线下一步已收敛到一个具体问题：**能否在保留终端ACK/旧image锁语义的情况下，缩短L2 preservation采集/发送和全局drain，并证明它影响的是package/关键请求？**

1. 继续静态审查checkpoint候选与directory/SourceD四级quiescence依赖，确认全局drain的最小安全范围、full-line预读能否避免outerA packet valid-gap、是否有能由既有源码严格给出的服务槽上界；不从事件数乘固定penalty构造收益。
2. 复用已保存mandatory pkg/ownership/result与SC8/SC20/38/21，按line/image/pkg只做身份支持的连接，先定位pre-C等待、same-set冲突和长尾模式。image contentSeq只是写入版本，不等于请求者package，不能直接把release pkg当critical消费者。
3. 核对checker client source区间、async bridge容量与peerWait回放路径；静态界定哪些机制可在BOOM MSHR idle时拖延package完成。若已有事件不足，结论继续unknown；不要求为补counter单跑。

## 未来一次功能候选run中才合入的bounded diagnostics设计

以下仅设计清单，**本轮未改RTL、未收新数据**。这些counter不足以自动证明removable，需要在同版本候选优化里验证性能和阶段减少，并沿用现有正确性/ROI gates。只允许届时选择一个已收敛功能候选。

| 位置 | 有界counter/histogram | 关键关联 |
|---|---|---|
| L2Preservation/Scheduler | capture/req/ACK计数，drain请求cycles、等待SourceD/C/SinkC原因mask，read/delay/send/waitAck各state cycles，lock cycles，outerA held&&本引擎!valid gaps，SourceA valid被lock/ready阻cycles | head/BOOM请求与checker source分别计；held gaps必须确认已持有arb，不能将任意idle计入 |
| L2 directory/requests/clientWait | A首beat等待、same-set/normalMSHR/dirready/locked/unsafe peerWait partition；每source或client类accumulated/max-age | source+line+request serial+requester pkg，pkg不可从旧image seq偷换 |
| SourceD/BankedStore/SinkD | first-ready到Dfire，bank read/write valid&&!ready，分阻塞priority；D queue高水位、outerD grantsafe阻塞 | stage occupancy原因可重叠，输出union与multi-cause mask，避免重复计账 |
| L1 MSHR/LB/refill | alloc→Afire→first/lastD→ordinary response→victim snapshot→install rows→meta→E；LB读被写抢cycles、rowValid等dataWrite、same-set WB pending | source+MSHR generation/txn+stable LDQ token，head标记只用于对应请求；行安装和load response允许不同顺序 |
| LSU/ROB + ownership | retry reason-release cycles、同token retry hist；headmiss/any-head/noCommit与上述resource exact intersections | commit与scheduler必须独立取实际信号，不能用SC7 sparse flag13代替 |
| checker/package | package活跃阶段memory待响应、local completion、result CDC、BOOM acceptance、ownership释放 | cache请求者身份→package completion→accepted result→scheduler阻塞链；保持现有release终态定义 |

存储预算建议：固定64bit counter bank（约64项/相关域），32bin logarithmic latency hist，按实际MSHR/source已有事务table跟踪，不加无限per-request log；每类最多top8尾部记录，身份/丢失/溢出有明确counter，ROI start/stop bounded snapshots并使用现有exact-rdcycle采样语义。clock域内计数，转换到200MHz要显式标记区间/边沿；不把checker周期直接相加。

必须保留：程序verified/checksum、完整320 package lifecycle/PASS平衡、held valid、source/sink与整包协议、CacheImage/epoch/txn身份、水位安全、最终bank commit和terminalACK guards、capture完整性、ROI/native provenance。功能与bounded诊断同版本，尽量复用当前B作reference，不自执行、不自动retry。

若后续仍无法给足够大且独立的关键预算，维持NONE_JUSTIFIED；不会因为流程需要下一步就选择frontend或加容量。
