# L2 → L1 response：接收、安装、load完成是不同阶段

L2 `SourceD.scala` 是四级多事务流水，stage1逐beat生成当前事务；bank read有3-entry skid与2-cycle SRAM读时序；stage2可能等Put/Release buffer，stage3发inner D，stage4执行bank update。stage4 ready会反压前级，避免旧ReleaseAck credit与后续多beat D形成死锁。ACK queue深2、ACK优先于early D，且ReleaseAck只能在最后实际bank commit之后形成。

L2 outer D经 `SinkD` 2-entry queue；首beat受grantsafe以及bank ready约束。BankedStore优先级 SinkC > SourceC/borrowed checkpoint > SinkD > SourceDw > SourceDr；上游子bank选择即使未全部获准也会压住重叠低优先请求。无利用率或blocked-cycle数据，不能根据159个L2 misses推断服务等待必小。

L1 `dcache.scala:1423–1432`：D ReleaseAck source6独立接收，其余按source送MSHR。`mshrs.scala:331–334,404–490,876–890`：incoming grant row写LineBuffer，`lb_write.ready=true`，写优先于共享LB读；数据接收不直接等L1 data-array write port。最后GrantData之后记录GrantAck，再进入RPQ普通读load drain；`io.mem_finish.valid=grantack.valid`独立于这些后续state，因此E可以提前发，MSHR退出再确认责任完成。普通读已能从LB `io.resp` 返回；LR/AMO走replay；然后才可能victim处理和physical install。

不能将 `L2 response arrival → final physical refill → dependent wakeup` 当成普遍串行链；对普通读，wakeup可在physical refill之前。`alloc→physicalfinalrefill`不是纯传输延迟，三个native latency cohort也不相同，禁止用均值或hist相减推wakeup gap。

| 请求的分布 | Average / median / p90 / p99 / max | Critical / noncritical |
|---|---|---|
| L2 D available→L1 D fire | 未保存valid/ready histories | unknown |
| L1 first/last D→LB complete | 未保存逐miss D beat timestamps | unknown |
| LB complete→final array/meta install | 无按MSHR/txn的事件历史 | unknown |
| physical refill→dependent wakeup | 普通读不保证该顺序；无paired timestamps | unknown |
| actual bank commit→ReleaseAck | 有mandatory SC38/21，见latency报告 | 仅release cohort，不能替代load response |

没有证据支持“response已到但在L1入口长期等metadata port”，也没有证据证明该时间为0。现有LB decoupling削弱“加个refill buffer即可大幅提速”的泛化方案；加D queue前须先证明当前入口反压及其关键交集。
