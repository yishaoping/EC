# Writeback / victim / checkpoint interference

L1 `BoomWritebackUnit`（dcache26–297）只有一份4×128bit victim buffer，voluntary source6由`ackPending`保护，直到完整C发出并收到匹配D ACK才可复用；等待ACK时probe可复用数据buffer。WB请求仲裁优先probe、MSHR、SVB capture、cross-package fallback；C arb中WB先于prober，多beat锁定。

**关键区别**：WB `s_fill_buffer` 的最后row捕获时即 `io.resp := reqIsMshr`（245）；MSHR `s_wb_resp`通常等victim snapshot完成，**不是等ReleaseAck**。但WB source继续占用、pending same-set install drain、后续victim admission可能等ACK，因此ACK延迟仍可能间接反馈。SC20首beat在row采集之后；本次恢复不覆盖request→source allocation→snapshot→首C，不能把它称总source占用上界。

L2 `SinkC`将ReleaseData存入2lists/16beats，经Scheduler/SourceD实际写bank；ReleaseAck仅在最后bank commit后排入2-entry ACK queue。ProbeAckData另有bank queue1。L2 preservation保存**将被覆盖的旧脏image**，不是L2 victim替换；可使普通ReleaseData命中处理先等旧版本checkpoint。

完整mandatory链共6,735笔、53,880个BOOM实际bank word写；另有source20/28/24的SC38，明确排除。没有source重叠、未匹配ACK、丢word、重复word、版本错配或末尾outstanding。ROI cohort共2,231，normal1,793/SVB438，无boundary-crossing事务；量化如下：

| Phase | N | Sum (cycles) | Average | Median | p90 | p99 | Max |
|---|---:|---:|---:|---:|---:|---:|---:|
| first_C_to_last_C | 2231 | 13386 | 6.000 | 6 | 6 | 6 | 6 |
| first_C_to_first_bank | 2231 | 80752 | 36.195 | 49 | 49 | 62 | 82 |
| last_C_to_first_bank | 2231 | 67366 | 30.195 | 43 | 43 | 56 | 76 |
| first_bank_to_last_bank | 2231 | 15617 | 7.000 | 7 | 7 | 7 | 7 |
| last_C_to_last_bank | 2231 | 82983 | 37.195 | 50 | 50 | 63 | 83 |
| last_bank_to_ACK | 2231 | 4546 | 2.038 | 2 | 2 | 2 | 9 |
| last_C_to_ACK | 2231 | 87529 | 39.233 | 52 | 52 | 65 | 85 |
| first_C_to_ACK | 2231 | 100915 | 45.233 | 58 | 58 | 71 | 91 |

分位数为nearest-rank，sum为事务phase duration之和；单source不重叠，因此首C→ACK sum等于ROI phase区间并集。区间 `[first_C, ACK)`不含ACK边沿；这不是sampled sourceBusy register计数。8次bank写全部连续，最大interbeat gap=1；bankspan=7是首末边沿差，不能误报只有7个写beat。

**延迟定位**：lastC→ACK合计87,529，其中lastC→firstbank 67,366、连续bankspan15,617、末bank→ACK4,546；三段可加且同cohort。52-cycle lastC→ACK模式1,405笔、10-cycle模式690笔，最大85。大头在bank写启动之前，无法进一步区分directory/MSHR排队、checkpoint、安全watermark、SourceD admission/port arbitration。与checkpoint对应关系是待证假设。

L2 traffic-window汇总：actual misses159、dirty replacement48、outer reads159、outer writes1,623；写流量远多于dirty replacement。SourceC req计数48与outerC first可能存在边界cohort差，`1623−48≈1575`只能作同窗aggregate residual、与checkpoint Put路径相容，不能声称精确匹配1,575笔checkpoint或把1,575×任意latency当ROI收益。A Gets38,633、AcquireBlock1,914；无per-source Get拆分，不把所有Get都归checker。

checkpoint源码链（Scheduler250–338,770–785 / L2Preservation48–157）：runnable safe candidate → drain停新C/D schedule → 等SourceD idle/SourceC idle/SinkC bank空与target quiescent → capture锁target set → 单引擎每beat read/delay1/delay2/send → 完整outer Put → 匹配terminal AccessAck解锁。无stall时accepted A每4cycles一次，首末8beat间28cycles；这期间outer A packet保持仲裁锁。不能将该结构的21个相对理想burst间隙乘事务数当关键收益。

**锁范围**：capture前drain对新C/D schedule全局起作用；capture后locked只挡目标set，其他set的D在stage3Allowed可继续，但SourceC调度/借用bank读在checkpoint锁期间仍受限制，outerA已有packet锁时普通miss A要等。不能把整个waitAck阶段描述成全cache完全停止。

可审查设计：先流水读入一个512bit checkpoint buffer，再连续burst outerA；保留target set锁、image身份、水位与terminal ACK，单一source不变。不增加cache容量或SRAM端口；增加line buffer/control，可能改变bank读节奏和仲裁；理论可缩短部分outerA valid gaps，实际critical gain未知。长等待如果来自watermark或memory ACK，该设计不解决它。尚不具备准备正式Opt5 run的收益证据。
