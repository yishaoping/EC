# Fixed-trace UB1–UB4及去重：可测、结构有界、未知分开

| Requested bound | Value | 当前可信范围 / 原因 |
|---|---|---|
| UB1 PRESERVATION_PENDING_UB | UNKNOWN | engine.active未导出；安全candidate前等待也未记；仅trivial[0,1,648,923] |
| UB2 OUTER_A_BLOCKING_UB | UNKNOWN | beatsLeft且normalHead.valid、ready provenance未保存；trivial[0,1,648,923] |
| UB3 OUTER_A_CRITICAL_UB | UNKNOWN | direct headmiss交集[0,53,845]；放宽all direct headpending[0,80,832]；非实际交集 |
| UB4 PRESERVATION_CRITICAL_UB | UNKNOWN | 同上，drain/active需分开；无precise interval |
| INDEPENDENT_CACHE_TRANSFER_UB | UNKNOWN | 四类union按cycle去重；direct-head union≤53,845或放宽80,832，**不是**全部非head/checker链上界 |

没有lock/pending边际，Fréchet不能产生比trivial更强的全机制bound。缺数值不能用67,366、347,409或hist tail169k填替；也不能因unknown就选>=100k候选。

## 新闭合的有限服务槽上界：只删packet内强制gap

源码每beat read→delay1→delay2→send，accepted A之间至少3个nonvalid槽，共7×3=21；normalSourceA为单beat无data，只有checkpoint产生本Scheduler multibeat A。较大traffic窗口内memory_writes=1,623同时含checkpoint A和SourceC data C，所以checkpoint firstA数 **≤1,623**。ROI完全在该窗口内；singleton checkpoint engine允许最多1个先前已开始packet跨入窗口。

```text
INTRINSIC_A_GAP_ONLY_UB
    = (1623 + 1 carry-in) × (8−1) × 3
    = 34,104 cycles
```

这是由真实FSM和packet-count ceiling推得的**必有服务槽删除上包络**，没有人为penalty；并非实际stall估算。各packet在单一A输出不重叠，ROI clipping只能减小这个slot union；若把全部这些槽都视作可删关键时间也低于50k。排除bank-read等待、send ready-low、pre-capture drain、waitAck、hit/非head/checker的时序反馈；完整outer-A-lock或preservation UB仍未知。

不将1,623−48当checkpoint精确数：SourceC req统计与实际outer C首beatcohort不同，且无数据Release不计memory write。使用所有1,623作为保守上限避免跨边界错减。

**停止项**：只优化intrinsic gap的packet方向属于用户情况D局部上界<50k，终止作为主线；“packet锁跨ACK”结构不存在，该子假设可删除等待为0。不能把局部D结论推广成“所有preservation收益<50k”。SourceC waitAck预约、drain/入口HOL整机制因未测不具备A/B/C资格，本轮选择move下一离线瓶颈。

目标至少146,411，direct head范围或34,104局部slot均单独不足；它们互有重叠，禁止相加凑预算。当前B已含64K，不能再加历史58,940 reference收益。候选收益expected UNKNOWN、保守credit0；0表示不给收益，不表示实际无机会。
