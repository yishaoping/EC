# Opt4 完成事件接线审查（源码证据，不是运行通过）

工作源码根：`/data1/gzh/EC/firesim/dac2026/work/opt4-alveo-v3/C4/chipyard/generators`。
本报告的源码版本由 source-mapping.json 和构建日志 sources.json 绑定。

单元为 producer package；身份 `(observer_epoch, packet_seq)`，不得用 checker slot 替代。
`r/R_IC.scala:263` 的 package_allocated / allocated_packet_seq 产生身份，producer_open / close_capture
及 per-slot seal 确定成员和封口。分配可能晚于成员的原执行时间，因此不能强制执行时间晚于分配。

## Rocket 完整完成

`rocket-chip/src/main/scala/rocket/RocketCore.scala:1451`：

- package_data_complete 同时要求 package_check_active、producer seal、packet ingress drained、LSL quiescent、ARF 完成及所需 CSR 完成。
- :1459 full_check_complete 还要求 `icsl.io.package_exec_done`，单独重执行结束不够。
- :1524 package_completion_pulse 在完整条件第一次满足且未等待结果时出现。
- :1525 package_result_status 为 CANCELLED，或 package_error/package_error_now 导致 FAIL，只有其余情况为 PASS。
- :1544 result enqueue 与 :1560 handoff 为后续传输事件；GHM result_deq_fire 及 BOOM owner clear 用于排空。

应以同一 seq 的第一次完整 PASS 条件取 Rocket 源域原时间；FAIL/CANCELLED 使整个无故障样本失效。
不能把 enq.fire、GHM dequeue、owner clear 或 session finish 当作比较完成时间。

## BOOM 原执行完成的接线缺项

`boom/src/main/scala/exu/rob.scala:427` 的普通 wb_resps 清 busy，`:444` 的 lsu_clr_bsy 清 store busy。
必须关联 dispatch generation/ROB index，并在存活成员确定后使用原事件时间。
错误预测/flush、replay、例外及 ROB 复用不能借用旧时间。

Fence 特别需要单独处理：

- rob.scala:409 对 fence/fencei 在入 ROB 时即设为非 busy，它们不通过普通 WB。
- core.scala:1091 的 unique dispatch 等待 ROB 空和 lsu.fencei_rdy；:1095 等待 RoCC。
- lsu.scala:583 的 fencei_rdy 要求 STQ 空且 dmem.ordered。
- lsu.scala:2290 以后仍存在 committed fence 在 STQ 头等待 dmem.ordered、清理条目的路径。
- store 的 ROB busy clear 与之后 functional_done / terminal completion / STQ release 也是不同事件。

**当前尚未证明上述全部类型及异常/重放路径的统一执行完成事件覆盖，因此不能生成正式 latency。**
不得为缺失的 fence/store 时间自动填提交时间、封口时间或 result 释放时间。
已有宿主 ExecutionTracker 是关联工具，不是这些目标事件已经接通的证据。

## Linux 与 ROI

`Software/Test/core/secondary.c` 只启动 hart1..4，完成后永久 idle；不是可服务重复 PARSEC 进程的 Linux checker runtime。
`guardiancouncil/GHE.scala:223` 绑定 satp PPN；:238 的 if_correct_process 匹配 PPN，不含原来注释掉的 privilege 限定。
Linux syscall、切换地址空间、中断、checker trap 返回和每个 epoch 的重入都需要真实运行时处理和验证。
不能把原裸机 checker 链接到 Linux 用户程序就宣称完成。

当前 hooks 中 `/dev/ec_dac_roi` ABI 尚无实现；marker 只定义 ROI 时间边界，不是 package 执行时间。
没有 driver、firmware checker service、真实被动桥和跨时钟原点证明前，链路应保持未准入。
