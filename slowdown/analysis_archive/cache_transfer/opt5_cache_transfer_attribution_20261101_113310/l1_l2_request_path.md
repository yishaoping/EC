# L1 → L2 request transport 与 capacity 分开

源码：`boom/.../lsu/mshrs.scala:404–446,909–915,1128–1143`，`dcache.scala:772–809,848–900`；L2 `Scheduler.scala:157–219,385–405,515–552`、`SinkA.scala`。行号对应本次 `source_evidence.json`。

| 问题 | 已证实结构 | 本次可测范围 |
|---|---|---|
| 连续发出 miss？ | 单 A 输出；6个MSHR fixed lowest-index仲裁。Acquire单beat，ready持续可连续发；无全局“必须等前一miss完成”限制 | 未保存 A valid/ready/age；不能声称实际持续发或经常堵塞 |
| queue 经常 full？ | SinkA request、Put list、directory/same-set/normalMSHR admission可能反压；Acquire/Get本身无Put payload | 无 occupancy 或 first-A wait，full频率未知 |
| MSHR 不满却不能发？ | 可以：同set/tag不匹配、secondary state/RPQ、SDQ、A仲裁、下游ready、E finish均独立于全局full | B full0、max occupancy2/6不排除此链；39,072 not-ready谓词/20,433 valid rejects也不直接测TL ready |
| critical/old 优先？ | LDQ wakeup已有AgePriorityEncoder；MSHR A fixed index，不识别ROB criticality；L2 schedule RR，入口C高于A | 缺少oldest-wait/critical-A histories，不证明饥饿或显著收益 |
| retry 重仲裁？ | 被nack的LSU token retained且executed清零，经LDQ age wakeup重新做S0/S2 lookup；若已merge到RPQ，不需要每次重发新A | repeated S2不是每次一个下级miss；不能用47,162估A包数 |
| merge/HOL？ | same-set不同tag可能blocked；同line secondary须tag/state/RPQ等允许，drainAdmissionClosed关新入队；741 merges | per-set/tag blocked时长、critical token对应关系未知 |
| source/sink？ | L1 source0..5 MSHR，source6WB；Grant sink/E保持。L2普通MSHR2+BC/C2，outer source2 checkpoint专用 | 没有source exhaustion/sink-credit等待计数；full0不是无source ordering |

L2源端 schedule 必须相关 A/B/C/D/E/dir resource ready；C > control > A 的入口优先、same-set MSHR阻塞及目录ready可产生 HOL。lineage-unaware不安全请求可停放在source-indexed clientWait，暂时不占MSHR/set/bank/D流水，等watermark及set可用再replay；因此L2 MSHR full0不能排除较长的checker请求等待。

外层A是 `preservation.io.a` 优先、`sourceA.io.a` 次之的 TLArbiter。multibeat使用beatsLeft锁定packet，checkpoint在自身read/delay阶段没有valid仍保持已开始packet仲裁归属；这可在“平均利用率不高”时阻挡普通miss。源码证明存在该结构；本B缺少临界A等待与checkpoint状态，实际次数/时间/独立关键预算未知。

当前无法分解 `detect→L2issue`：native detect→alloc包含本地admission，alloc→physicalrefill还包含整个下游及安装；不能把两者误标成 request transport latency。
