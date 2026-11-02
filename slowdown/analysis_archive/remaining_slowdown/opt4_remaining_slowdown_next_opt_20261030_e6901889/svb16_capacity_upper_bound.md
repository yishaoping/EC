# SVB32 固定轨迹局部机会：不超过 5,254 cycles

结论：`KEEP_SVB16`；`DO_NOT_EXPAND_SVB`。

406 allocations完整身份重建的occupancy各bin与保存histogram完全一致。
max occupancy16、max line depth5、occupancy>8为65,102 cycles、would-full-at8为56 captures。
16满仅4,888 cycles，占traffic0.2844%；full fallback只有1个上升沿事件。

| 事件 | 半开主核cycle区间 | 长度 |
|---|---|---:|
| 唯一SVB16 full区间 |[1598087,1602975)|4,888|
| 与其重叠的legacy preservation episode |[1598099,1603353)|5,254|
| episode中unsafe部分 |由完整kind8状态重建|4,875|

该episode observation entry370，target seq137，line `0x80009f40`。
full开始时16个owner均未safe；最早safe发生在1602974。因此这次full压力来自等待安全水位，
没有证据表明是已经safe的条目因promotion drain吞吐不足而塞满。

## 上限的严格适用范围

把该唯一重叠legacy episode的**全部5,254 cycles**都慷慨计为SVB32可删除，
包括post-safe工作，可得 **固定已记录轨迹、局部episode删除模型** 的上限5,254。
占Opt4 ROI **0.3076%**，占remaining **0.7440%**，远小于85,393的门槛。
只删除unsafe部分的更窄局部量是4,875。

ROB head/Store关键路径重叠没有保存，所以实际局部ROI贡献可以为0。
此数字不是带时序反馈的全系统严格上界：扩大SVB可能改变后续request/package时序，现有run无法证明那些反事实。
也不能把full occupancy的4,888与episode5,254相加。

原始pre-bypass WaitSafe总周期、replacement/probe造成的实际release阻塞和完整fallback原因周期分区均未记录。
4,774 unsupported fallback是事件，不是4,774等待周期；不能归给SVB容量。
