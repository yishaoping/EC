# DATA / END / count / checker completion

本说明依据当前R_IC/GHM/RocketCore源码及528000/1769000记录，描述当前设计，不作为端到端正确性证明。历史设计中的另一套typed END bridge不是待重复新建的缺失接口。

## Source owner、drain与最终边界

`R_IC`的producer_open/producer_target保存“仍可能新增提交记录”的包身份；package_owned保存“资源尚未被sequenced result释放”的身份，二者不同。调度下一个checker不能让旧ROB drain尾部改属新target。

当前counter统一以`producer_open && producer_target_ic == i && if_correct_process`累加实际ic_incr，覆盖check/cooling/snap及closing边沿。snapshot_accepted同时要求empty ROB、ready/armed/context；close_capture=accepted && producer_open，final_pending是延迟capture事件，随后才置done。最终值须与独立ROB架构退休基准一致，不能用内部counter自证。

Barrier close ACK表示接管关闭命令，不表示final、producer seal、PASS或safe。无free checker、exit、privileged snapshot、提前CANCEL/FAIL、非监控上下文也需要闭合路径。

## 已存在的消息表示

| 层级 | 当前字段/事件 |
|---|---|
| source count | 16bit：bit15 done，bits14:0 count；seq另外携带 |
| DATA CDC | isEnd:1 + seq:32 + dataPayload；真实DATA/零anchor在END之前 |
| END payload | low15 finalCount，上位pad；END不写LSL/BJL，不算load/指令 |
| checker count | 53bit：valid52，seq51:20，reserved19:16，done15，count14:0 |
| RocketCore→R_ICSL | 按package_seq匹配valid/seq后传16bitcount；new_package重置消费者状态 |

GHM end_pending/end_seq/end_count在source seal/final到达后保存，独立于live allocation字段。最后真实DATA/anchor之后才能send_end；只在enq.fire送出后释放pending。晚到旧live count不能回退已收到的final/done；旧END不能覆盖更新sequence。零data anchor的历史settling窗口不能被当成全系统证明无未来data，真实seal/final生命周期仍须验证。

## Checker完成条件（当前源码）

```text
packet_ingress_drained = cdc_empty && previous_cycle(cdc_empty)
producer_sealed_for_package = producer_sealed_valid && seal_seq == package_seq
package_tail_drained = active && matching_seal && ingress_drained && lsl.quiescent
package_data_complete = active && matching_seal && ingress_drained && lsl.quiescent
                        && ARF_complete && (!CSR_required || CSR_complete)
full_check_complete = package_data_complete && R_ICSL.package_exec_done
```

ARF compare另要求ECP完整且seq/epoch正确、quiet状态连续两拍、compare_idle及无transport error。LSL quiescent覆盖FIFO/read/head/response/request生命周期，不能简化成if_empty。

result形成、保持到CDC fire、返回/局部clear、frontend cleanup ack、结果handoff、BOOM release、连续PASS safe分别核对。cleanup ack只控制handoff/admission，不能新接入exec/tail/ARF completion让管理return等自己清理。

## 运行验收

每seq独立scoreboard：CPS PC→全部真实BOOM退休（startup/trap规则单列）→GH_BUF DATA/BJL/CSR→END/final/ECP→checker退休及LSLfire→比较→result/release/safe。覆盖无slot/zero-data/clock slower/CDC full、stale END/late live count、取消/reuse、barrier与mode同拍。源码结构/模块测试通过仍不替代最新整机验证。
