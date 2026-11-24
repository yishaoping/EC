# Seq32 生命周期的实现与证据

普通回滚不清 packet_seq_counter；R_IC 的 snapshot_allowed 在 counter 全1时禁止分配，identityUnavailable 同时进入既有停止路径。序号比较不采用模环绕。v1Config 在 2^32−257 进入重基保留区，Core 从刚建立的空 SCP 发起计划重基。Seq16 仅降低触发门槛，所有状态和通道仍保持32位。

| 所有者 | 建立 | 结束与复用条件 | 实际实现 |
|---|---|---|---|
| R_IC Checker槽与SCP | snapshot_accepted分配非零Seq，注册packet_alloc_valid | 槽只由Main域精确结果release释放；SCP被Controller pin时不能回收 | R_IC package_owned/checker_segment_id_reg；ContextMemory pinned/discard |
| DATA与END | 实际beat或显式空anchor建立包，seal之后才发END | DATA源端已同步读指针追上写指针，且无end_pending/selected_segment | GHM u_data_cdc.enq_empty / forwardDrained |
| ARF/CPS | 每beat携带相同完整Seq，路由字段剥离后再拼Seq | 先有对应DATA anchor；所有ARF源端取得空收据 | GHM selectedArfPayload / arfAfterData / u_arfs_cdc.enq_empty |
| count与producer seal | Main注册进度，真实END固定最终计数 | 无countPending、控制队列源端空；Checker域清receivedCount | GHM u_b2l_ctrl_cdc / resetCheckerTags |
| result及release | Checker结果入AsyncQueue，Main dequeue持有release | Main释放原槽且Checker域result源端空，才允许清标签 | GHM result_release_pending / u_result_cdc.enq_empty |
| Rocket本地上下文 | 包admission、LSL/RSUSL/前端/结果形成共同owner | 包内trap/xRET/special return已结束，所有存储及结果owner空，ACK保持 | RocketCore checker_storage_idle/packet_seq_reset_ready；R_ICSL package_idle |
| L1/L2版本与物理事务 | 真实cache/保存/外写协议接受时取得责任 | 已停核且SW=tail，所有Checker、L1/SVB/archive空；L2逐行维护与真实ACK完成 | DCache maintenanceLocalDrained / physicalDrained；L2维护证书 |
| Seq32归零 | 物理证书与transport四域收据汇合 | bank观察SW=0，空EVT安装完成，所有ACK返回低后Restart | DCache sequenceReset/resetPublished/releaseAfterReset；Controller/SCP |

AsyncQueue保持原Gray指针复用协议。接受侧短暂valid低不能作为源端空收据；没有对FIFO进行单边强制reset。请求payload保持到四个Checker及L2 bank的ACK高、请求降低、ACK全低，之后才允许下一次收据。包外管理异常保留CSR/PC/深度，只有清包标签收据使用package_idle；新包执行仍要求完整context_idle。

本批测试以0x80000001、0xfffffefd和0xfffffffe为实际32位标签，并携带独特DATA与ARF payload。Checker停钟/下游背压期间无消费、无reset ACK；ARF不能越过DATA anchor。旧result跨域后Main仍持有槽时继续阻止清空。所有收据高低阶段结束后Seq1只消费新的DATA/ARF/END；等待额外100拍也无旧数据或release。三条高位路径均实际通过。

这项证明与整核小门槛互补：相同生产GHM、R_IC、RocketCore/RocketTile、DCache和Controller源码的三配置整核已构建通过，正常/Fault8异常MMIO严格配对，以及23次真实物理重基→新Seq1 PASS完整程序通过。高位测试不替代真实Rocket/L1/L2集成，小门槛不替代32位标签通道测试。source hash核验及实际命令在seq_lifecycle_closure.json。

因此关闭原P2-09、P3-03、P5-09。P3-15涉及的CurGen/版本reservation以及P4-06所有短owner标签与缓存迁移组合仍有独立验收条件。物理CDC最大偏斜、布局布线与技术STA也不在数字协议测试的证明范围内。

有限owner补充验收：生产L1两个空槽0xffff→1的install/refill普通+1错配
已实际复现并修复（三处nextSlotEpoch），当前生产四次同组替换/完整终态
与整套Hierarchy通过。Epoch/CurGen在真实32位0xffffffdd起始、一次rollback
触发保留区0xffffffde后，真实L1/L2维护必须等待实际外写和matching ACK，
清零/空上下文/重启后再次rollback与最终安装读取正确。只加速reset标签，
未改compact赋值或伪造证书；长期--kind generation实际PASS。

内容serial按(address,writer,Seq)递增，跨Seq重新从1开始；当前段上限
GH_TOTAL_INSTS=5000且每个semantic write只在s3_effect_fire递增一次，
远低于32位范围。failed SC无写效应、不增serial，AMO和byte mask由实际
Hierarchy旧值/邻字/完整行测试验收。事务slot标签只在旧owner终态后循环，
不会作为持久内容排序。普通rollback不复用Seq；计划重基仍须完整数字
收据和物理维护。当前组合Seq16最终回归在途，FIFO物理Gray偏斜/接口
STA/布局布线仍明确未签核，不以数字边界PASS代替。
