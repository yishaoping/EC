# Retry cause → 实际 transfer/resource 映射

原始B exact software ROI causal counters；源码 `dcache.scala:1268–1305`、`mshrs.scala:967–983,1074–1093,1138–1143`、LSU nack/wakeup逻辑。原因是谓词计数，可能重叠；不强行partition47,163 total，也不把event当duration。

| Retry cause | Events/predicate | Critical requests | ROB-head overlap | 实际 resource / 限制 |
|---|---:|---|---|---|
| MSHR request not ready | 39,072 | null | null | S2 valid miss & !mshrs.req.ready；SDQ、same-set/tag、secondary state/RPQ、primary readiness；不是TL ready直接采样 |
| victim transient hit | 8,087 | null | null | S2 hit & secondary_miss；MSHR同set transient/eviction状态，不等于所有正在refill |
| same-set WB | 2,354 | null | null | valid nonhit & s2_wb_idx_matches；WB当前/待ACK同set冲突，有具体writeback关联，但不分row capture与ACK等待 |
| probe / hit path | 25 | null | null | RegNext(s1_nack)，prober/meta相关路径，非泛称response queue full |
| data bank conflict | 0 | 0 | 0 | active DuplicatedDataArray nack constant0；不排除meta/owner/effect conflict |
| refill active本身 | 未独立导出 | null | null | 真实可能阻LB读/安装/同set，不是已定义nack cause |
| TL A/D ready low | 未导出 | null | null | 需按MSHRsource/txn与LSU token关联，不能拿not-ready谓词替代 |
| owner/clear/effect conflict | load分原因未单列 | null | null | s2_owner_block、clear freeze/slot、S3/completion等存在，不能凭总数差值算独立原因 |
| RPQ replay issue | 229 | null | null | 所有229在MSHRbusy，full0；已入RPQ终结/owner检查，非229新miss或229个可删周期 |

结构性放大链 **PROVEN**：stable retained LDQ token → repeated S0/S2 lookup → nack → executed=false → AgePriorityEncoder重试。upstream trigger分支 **PROVEN存在**（not-ready、victim、WB等），但各分支具体被什么transfer phase长期压住、同一critical token的nack次数和连续时长 **UNPROVEN**。后续ROB等待与下游checker/package关键链无法从汇总counter完成join。

当前retries47,162、nacks47,163；MSHR rejects20,433属于valid req cohort，不能与39,072谓词等同。miss lookup attempts40,033也不等于A包数。direct headmiss53,845与headpending80,832嵌套，不能把nack或WB exposure再加到它们上面。

旧A→B reference：miss−648、retry−64,386、headmisswait−85,849，说明少量miss变化与大幅retry/wait变化相关；没有严格pair、逐miss服务阶段或critical token trace，不能选择其中一条放大链作为唯一实测原因。A′仍不运行。
