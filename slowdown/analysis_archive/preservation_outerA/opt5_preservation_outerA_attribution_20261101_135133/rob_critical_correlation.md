# ROB / scheduler关联：缺事件的位置明确保持未知

| Metric | Observed value | 仅靠现有边际可给的范围 |
|---|---|---|
| ROB_HEAD_WAIT_DURING_PRESERVATION | null | direct headmiss [0,53,845] |
| ROB_HEAD_WAIT_DURING_OUTER_A_LOCK | null | direct headmiss [0,53,845] |
| ROB_HEAD_WAIT_ON_REQUEST_BLOCKED_BY_OUTER_A | null | 身份与因果更强，不能由raw overlap补齐 |
| outer_a_lock && rob_head_load_wait | null | 若放宽全部direct headpending [0,80,832] |
| preservation_drain_pending && rob_head_load_wait | null | 同上；candidate/active/drain先分定义 |
| outer_a_lock && scheduler_unavailable | null | [0,347,409]，没有lock边际无法收紧 |
| outer_a_lock && l1_retry_active | null | [0,47,162] exact ROI retry-cycle边际；非associated events |

raw overlap仅同时成立；independent overlap需排除更早不可越过依赖，且不能把几个predicate交集相加；headmiss53,845嵌套all headpending80,832。union(A∩H, B∩H)≤|H|，因此direct-head范围去重上限分别53,845/80,832，**不是整个checker/nonhead因果链上界**。

现有SC7可还原scheduler，但不含exact ROB noCommit轨迹：flag10只在snap/cooling有empty语义，flag13未进入change signature。SC38只是writefire，不含head req identity。既无outer-A锁interval，也无法完成cycle intersection；不以release phase代替lock。

本轮额外可算的代理关联：lastC→firstbank区间在完整prefix内与scheduler unavailable交集 **94 cycles**（仅release代理），不代表outer-A锁×scheduler、亦不说明checkpoint关键作用不存在。前轮首C→ACK交集151，二者定义不同，不拼接到未知suffix。

contentSeq是resident或incoming **写入版本**，不是当前消费者package。必须沿请求source/serial→MSHR/LDQ token→head position或checker requester package建join，不能因同seq或同line就宣称关键因果。
