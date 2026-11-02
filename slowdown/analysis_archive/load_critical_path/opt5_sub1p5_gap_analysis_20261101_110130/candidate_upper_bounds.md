# 候选机制：固定观测轨迹的上界与保守预算

“上界”仅指删除当前记录的直接head等待的局部模型；不含重新运行时序反馈。unknown不是0；conservative0表示目前不能保证正收益，不表示物理收益为零。

| Candidate | Exposure | Critical overlap | Theoretical removable upper bound | Conservative recoverable | Confidence |
|---|---|---|---|---:|---|
| nack amplification | 47,163 nack / 47,162 retry issue cycles | head-miss∩retry [0,47,162]，未测 | 仅删除retry issue∩head最多47,162；包括issue之间等待的完整机制只能借head-miss53,845/宽80,832包络，不能用事件数作机制上界 | 0 | 循环HIGH；收益LOW |
| refill/admission serialization | busy194,905，detect→alloc/refill latency为不同cohort | head-miss∩busy53,795，非refill-conflict计数 | 以相关head-wait作为宽包络最多53,845；真正local refill port子集unknown，可能远小于此 | 0 | structural HIGH；attribution LOW |
| RPQ replay serialization | 229 replay issue cycles；全部229 issue时MSHR busy | head-miss∩issue [0,229] | 直接issue重叠≤229；issue间持有/排队未测，全部load replay机制只能用53,845/80,832宽包络 | 0 | LOW |
| all ROB-head miss wait | 53,845 | 53,845 | 53,845（包括不可消除外部服务等待） | 0 | exposure HIGH；recoverability LOW |
| all head-load pending | 80,832 | 80,832 | 80,832，包含上项，禁止加53,845 | 0 | exposure HIGH；recoverability LOW |
| data bank conflicts | 0，active duplicated array常量false | 0 | 此active bank-nack机制为0 | 0 | HIGH |
| LSU load request port backpressure | traffic load request valid&&!ready共1,541 cycles | 未测；exact ROI子集[0,1,541] | 仅删除已发起load请求的ready等待≤1,541；不能外推到尚未选入LSU的load或后续nack间隔 | 0 | exposure HIGH；gain LOW |
| more MSHRs | full0，max2/6 | head∩full0 | 直接full-stall删除为0；不能据此推断同set admission完全可消除 | 0 | 不支持扩容HIGH |
| scheduler interaction | 347,409 | head miss0；busy269/full0 | head-miss共同状态的直接删除0；整个control方向最多347,409 exposure但可恢复unknown、属于独立主题 | 0 | overlap HIGH；gain LOW |
| broader nonhead dependence | STOP noCommit∩anyLoadPending159,519，ROI范围148,359..159,519 | 没有load→head blocker身份join | 仅是宽相关exposure，尚无可恢复上界或>100k机制证明 | 0 | LOW |

nack/refill/replay是同一生命周期的不同阶段/事件；其完整head包络高度重叠，不能把三个53,845加起来超过146k。也不能把47,162+53,795+229称为可恢复预算。scheduler与head miss在B不重叠，也不证明删除两者会取得两个干预收益之和。

优先使用实际head-cycle aggregate；连续head episode和retry episode未保留，因此不编造episode max/p95。已保存完整可观测control prefix interval分布仅用于下一步control归因，不用替代load episode。
