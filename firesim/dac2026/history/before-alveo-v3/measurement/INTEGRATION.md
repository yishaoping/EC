# 测量接入与验收要求

状态：`passive_stats.hpp` 是可编译的宿主侧统计核心，`ec_dac/measurement.py` 是离线参考模型。
**尚无已接线的 FireSim bridge、Linux ROI 驱动或可启动的 checker Linux 系统。**
下列是接线合同和源码定位，不是已完成的硬件验证。不要只把三个 `*_verified` 改成 true。

## 1. 校验单元和唯一身份

候选单元为一次 producer 分配、封口、由一个 Rocket 最终比较的 package，身份是
`(observer_epoch:uint64, packet_seq:uint32)`。epoch 每个样本重新建立，seq 在同 epoch 内
不得复用或回绕。Rocket slot/hart 不能替代 seq：slot 会在整个运行期间反复分配。

当前 EC 参考点均在原源码树 `chipyard/generators`，不是独立上游 Chipyard 已有的接口：

| 事件 | 源文件及锚点 | 应观察的事实 |
|---|---|---|
| 分配/封口/owner | `rocket-chip/src/main/scala/r/R_IC.scala` 的 `package_allocated`、`allocated_packet_seq`、`producer_open`、`close_capture`、`checker_segment_id_reg` | 每个 package 的 seq、所属 checker 和存活成员 |
| BOOM 执行完成 | `boom/src/main/scala/exu/core.scala`、`rob.scala` 的 dispatch、`wb_resps`、`lsu_clr_bsy` 及 kill/replay 路径 | 每条最终存活指令**原始**执行完成时间 |
| Rocket 最终比较 | `rocket-chip/src/main/scala/rocket/RocketCore.scala` 的 `package_data_complete`、`full_check_complete`、`package_completion_pulse` | data/ARF/CSR/tail 比较及 `icsl.io.package_exec_done` 全部完成且结果 PASS |
| 结果传输/释放 | `rocket-chip/src/main/scala/guardiancouncil/GHM.scala` 的 `result_deq_fire`、`checker_result_release`，以及 BOOM owner clear | 作为排空条件；不能替代最终比较时间 |
| 真实消融开关 | `GH_GlobalParams.scala` 的 `GH_REAL_BARRIER_ENABLED`，BOOM `barrierForceClose`、L1 dcache、L2 `InclusiveCache.scala` | 正常运行 barrier 路径；不是完整纠错开销 |

行号可能变化，须在实际构建源码上重新搜索这些锚点，并记录源文件 hash。
历史 D 具有不同接口；必须单独完成相同定义的映射，不能沿用 C 的信号名就认为等价。

## 2. 执行时间绝不能被提交时间替换

在 dispatch 为 ROB 项生成单调 serial，用 `(epoch, dispatch_serial, rob_index)` 区分 ROB
回绕和复用。记录所有实际执行完成通道，包括普通 writeback、store/LSU busy clear、
例外路径；replay 要撤销旧完成并记录最终成功执行，flush/kill 要删除被取消的一代。
仅在确定 package 成员时，把对应原执行时间加入该 package 的 max；提交事件只证明
成员存活，**提交时钟不是该时间戳**。

`t_boom_exec_done(package) = max(t_exec_done of every surviving member)`。
package 元数据可能在成员执行以后才分配/观察，不能强制 `allocation_time <= execution_time`。
缺任意存活成员执行时间即使应用正常退出也不得准入。空 package 须明确定义独立边界，
单独统计并验证，不能自动用提交或封口时间填充。

`ExecutionTracker` 只实现宿主侧身份和时间关联，不会自动找齐源级 writeback 通道。
需针对多发射、同周期 dispatch/complete/commit、replay、exception、flush、ROB 回绕、
store、多周期操作、跨 package 边界和零指令单元提供证据。当前这些硬件测试未运行。

## 3. 最终比较、统一时钟与被动性

只计每个 seq 第一次、完整条件满足的 PASS。`package_exec_done` 单独为真不足以完成
校验；`full_check_complete` 可能持续多周期，必须按身份去重。FAIL、CANCELLED、丢包、
未关联或重复比较使整项样本无效；正常无故障实验不能将它们排除后继续算较低尾延迟。

候选时间单位为 BOOM cycle tick，候选 BOOM/uncore 200 MHz、Rocket 100 MHz。
精确边沿转换应来自 FireSim clock bridge 的有理数时钟计划及复位/相位关系，不是按
宿主调用顺序乘 2，也不是拿异步队列到达时刻当源事件时刻。源事件保留原 timestamp，
bridge 的 join 可按通知的任意次序到达。若不能证明统一原点、比例和 phase，必须阻断。

桥只消费仿真 token 并在宿主内聚合，不把 observer ready/valid 连回目标协议，不为
计数注入目标 stall。宿主采集拥塞可以降低仿真速度，不能改变目标时序或静默丢事件。
默认只每 20 秒宿主时间发累计 snapshot 和每项一条 end，不输出逐指令/逐包日志。
禁用现有 debug printf 的动作也应纳入统一配置并审核，不能让不同组使用不同 debug 逻辑。

## 4. ROI 与控制 ABI

工作副本 hooks 调用 `dac_roi.c`：BEGIN ioctl 排空前序任务并 arm；随后 hart0 上
`0x6b100013` 标准 NOP marker 建立 ROI 起点；END marker `0x6b200013` 建立终点，
随后 END ioctl 封口，DRAIN ioctl 等待最终比较、各传输队列和 owner 全部释放。
BEGIN 返回的是 arm 确认，不能声称返回尚未执行的 marker 时间。

驱动须证明 BEGIN 不把前序包混入 ROI，END 不遗漏包含最后 ROI 指令的包；marker
不应触发其他程序的 ROI，须绑定 app pid/地址空间与实际 BOOM hart。必须统一约定 marker
在架构接受/退休处取边界；这是 **ROI 边界**，不改变上面的执行完成延迟定义。
边界 syscall、context switch、中断及 checker 内核活动如何归属须记录并在 B/D/C 一致。

当前 `/dev/ec_dac_roi` 没有实现：hooks 会退出 125，不能回退为 gettimeofday/printf。
本目录不提供“空 ioctl 成功”的伪驱动。Linux DT/firmware 还须预留 checker harts、服务
重复 PARSEC 进程并确认 guest CPU0 对应 BOOM hart0；当前裸机 hardcoded hart1–4
程序不能直接充当这个运行时。B 也要有相同 marker/边界控制，但 checker 任务数为 0。

## 5. 周期分类和汇总

`roi_cycles = end_tick - begin_tick` 用于 slowdown；`drain_cycles = release_tick - end_tick`
单独报告尾部排空。latency 对 ROI 归属的全部 package 收集，允许在 ROI 后比较完成，
不截断尾部。只有 drain 后才可原子提交完整结果。

至少接入 generated/completed/exceptions/outstanding、latency count/sum/max/histogram、
checker busy 的 ROI/drain 两组积分、队列占用积分/max/full ticks、BOOM protection
blocked ticks 和原因。busy 是预留 checker 执行有效任务的 target 区间，不是 Linux idle。
一个输出队列指标必须注明具体队列/容量；多队列须扩展 schema，不能混成模糊“占用”。
各阻塞原因默认允许重叠，只分别画图。只有每周期明确互斥优先级分类且总和严格等于
blocked ticks，才能标记 `blocking_reasons_exclusive=true` 并做堆叠。所有硬件计数器
uint64、加法和占用积分溢出均应使样本失败。histogram：0–255 精确分桶，>=256 每 octave
16 桶，宽度为 `2^(floor(log2(x))-4)`，报告 P50/P95/P99 的 [lo,hi] 而非虚假精确值。

## 6. 运行 adapter 与宿主持续接收合同

部署和运行是两个独立、显式配置、SHA256 固定的可执行 adapter，入口见 `config/site.json`。
没有可用默认 adapter；禁止以 shell 包装上游全局 infrasetup/enumeratefpgas 来绕过隔离。
部署参数：`--config ID --bdf BDF`。运行参数：`--config ID --jobs FILE --campaign DIR`；
一个运行 adapter 对该配置启动一次 Linux，guest 顺序执行 jobs，不在 guest 重启才回收。

运行 adapter stdout 仅输出聚合 JSONL，stderr 持续写宿主日志。每条记录含：

```json
{"type":"start","sample_id":"manifest中的ID","attempt":1,"event_seq":1,
 "identity_digest":"SHA256(canonical manifest sample，不含attempt/previous_state)",
 "definition":"package-exec-to-final-compare/1"}
```

后续 event_seq 严格加 1；`snapshot`/`end` 附 `metrics`，失败用 `failed`/`timeout`/
`interrupted` 和 reason。metrics 全字段见 `ReferenceObserver.snapshot()`，正式记录必须
`synthetic=false`；它不是可照抄的有效数据。传输 uint64 不能经丢精度的 JS Number。
每样本 start 立即通知宿主，bridge 最迟按 snapshot_seconds 输出新累计快照；宿主在
3 倍间隔内无新 snapshot 会保存部分记录、标记 timeout 并停止自己启动的 adapter。

guest control backend 接收 `operation sample_id attempt`，返回匹配 sample_id 且 ack=true
的 JSON。operations：drain-before、arm、output-verified:<sha256>、seal-and-drain、
sample-complete/failed/timeout。需把 guest 控制、进程状态、输出校验与 bridge 同一 epoch
的真实 metrics 关联，不能用退出码/guest printf 冒充观察数据。支持 guest 失败后排空；
排空失败则停止整批，不让污染样本继续。尚未实现这个板卡/镜像专用 backend。

## 7. 分阶段证据准入

`deploy --phase link` 和 `plan --stage link` 为首次测量链路保留 bootstrap 入口：先有
平台/镜像/checker/observer 结构审查和结构配置证据，再由用户执行链路验证；不会要求
先完成同一次链路测试才能启动。link 仍要求真实 hook 静态连接证据和输出 validator。
正式 main/recovery/scan/ablation 还须 ROI、执行时间、最终比较、CDC、单 boot 批处理、
输出正确性和 B/D/C 可比性测试全部有 hash 固定的证据。`config/compatibility.example.json`
给出字段。所有配置初始不 ready，`validated_configurations` 初始为空。

验收至少包含：前序包污染/尾包跨 ROI、异步反压和结果迟到、seq/ROB 复用、重复记录、
中断/重新执行、输出错误、超时、磁盘 fsync 失败、三次完整重复和各配置公平性。
本次只测试宿主离线合同，不启动这些硬件/仿真验收。
