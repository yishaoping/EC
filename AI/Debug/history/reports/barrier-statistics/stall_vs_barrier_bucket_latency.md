# 阻塞、ROB stall 与延迟桶的区别

## 结论

这次 benchmark 中：

- **L1 跨包 Store 阻塞确实发生，但没有形成等量的长时间大核 ROB stall。** 1183 次主要表现为 DCache 对 Store 的短脉冲 `s2_nack`，随后由 LSU replay；它不直接连接 `rob.io_gh_stall`。
- **L2-DRAM 屏障确实造成了大核流水线/ROB 停顿。** 本次事件中 `rob.io_gh_stall` 从 VCD 时间 595281 保持到 595707。VCD 每 2 个时间单位对应一个 BOOM 时钟周期，因此约为 **213 个 BOOM 周期**。
- 日志中的 `cross_package_store wait_cycle_sum=2076227` 和平均 `1755.052` **不是大核实际 stall 周期**，也不是把阻塞装进桶后消除了。它们是统计模块记录的“事件发生周期到对应 safe watermark 到达周期”的延迟，多个事件可以同时等待、时间区间可以重叠，因此不能累加到 `boom_cycles`。

## L1：短 nack/replay，不是 ROB 全局停顿

源码链路：

```text
l1CrossPackageBlocked
  -> dcache.s2_nack(0)      // 仅阻塞当前 Store
  -> dcache.s2_send_nack(0)
  -> LSU replay/store retry
```

位置：

- `chipyard/generators/boom/src/main/scala/lsu/dcache.scala:797-805`
- `chipyard/generators/boom/src/main/scala/lsu/dcache.scala:1004-1016`

当前实现没有把 `l1CrossPackageBlocked` 接到 `rob.io.gh_stall`。因此一次 L1 跨包 Store 会被 DCache 拒绝并重放，但 BOOM 仍可能继续执行或提交其他独立指令。

已有 VCD 统计：

| 项目 | 结果 |
|---|---:|
| `l1CrossPackageBlocked` 上升沿 | 1183 |
| 与 `s2_nack_0=1` 同时出现 | 1183/1183 |
| 单次高电平持续时间 | 2 至 4 个 VCD 时间单位，约 1 至 2 个周期 |
| 1183 次事件所在窗口 | VCD 时间 389201 至 396293 |
| 该窗口中 `rob.io_gh_stall` | 1183 次 L1 阻塞的高电平区间与 ROB stall 没有重合；ROB stall 在 389171-389195 和 396319-396455 等独立区间出现 |

因此“每次等待平均 1755 周期”不能理解为每次都让 ROB 停 1755 周期。L1 事件统计的是等待条件进入，DCache 的实际 nack 脉冲很短；后续安全水位推进、writeback 和 replay 过程在硬件中并行进行。

## L2：确实出现 ROB stall

源码位置：

`chipyard/generators/boom/src/main/scala/exu/core.scala:2071-2076`

```text
functionalBarrierStall = enabled && barrierServiceActive &&
                         l2BarrierReq && close_ack && seq_match
rob.io.gh_stall = ... || ic_stall || ... || functionalBarrierStall
```

本次 VCD 事件：

| VCD 时间 | 信号 | 结果 |
|---:|---|---|
| 595271 | `gh_l2_dram_barrier_request_0` | 请求到达，seq=`0x100000` |
| 595279 | `barrierServiceActive` | 置 1 |
| 595281 | `ic_master.io_if_pipeline_stall` | 置 1 |
| 595281 | `rob.io_gh_stall` | 置 1，提交 valid 同时降为 0 |
| 595283 | `ic_master.io_barrier_close_ack` | 置 1，seq 匹配 |
| 595707 | `rob.io_gh_stall` | 释放，提交 valid 恢复 |
| 595709 | `barrierServiceActive` / close-ack | 清零 |

595281 到 595707 共 426 个 VCD 时间单位，即约 213 个 BOOM 周期。这里 `rob.io_gh_stall` 还包含 `ic_stall` 等 OR 分支，所以当前波形不能把每个周期精确拆成 `functionalBarrierStall` 单独贡献；但从 595283 起 `functionalBarrierStall` 的条件已满足，L2 屏障的功能停顿确实被激活。

## 延迟桶到底统计什么

统计模块位于：

`chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/BarrierLatencyStats.scala`

关键逻辑是：

```text
event 发生时：bucket.requestCycleSum += currentCycle
safe watermark 到达时：safeCycleSum += currentCycle * bucket.count
软件计算：wait_cycle_sum = safeCycleSum - requestCycleSum
```

因此 `wait_cycle_sum` 测量的是：

```text
跨包事件发生 -> 该事件所属 package 进入 safe watermark
```

它不是：

```text
rob.io_gh_stall 为 1 的周期数
```

本次数据：

```text
cross_package_store:
  seen=1183
  wait_cycle_sum=2076227
  average=1755.052

l2_dram_replacement:
  seen=1
  wait_cycle_sum=216
```

L2 的 216 个统计周期与波形观测到的约 213 个 ROB stall 周期接近，因为该事件只有一个且屏障服务与安全水位推进高度重合。L1 的 2076227 不能这样解释：1183 个事件的安全水位等待高度重叠，平均值反映 checker/package 完成延迟，不是 1183 次串行 ROB 停顿。

## 是否“装进桶里缓解”

不是。桶只保存计数和时间戳，不参与 DCache、LSU 或 ROB 的 ready/stall 控制：

- `GHBarrierLatencyStats` 的事件输入是 `Valid`，没有反压输出；
- 桶满时只增加 `dropped` 并清除 `statsValid`，不会吸收或延后硬件请求；
- L1 的真实阻塞由 `s2_nack` 实现；
- L2 的真实停顿由 `rob.io.gh_stall` 实现。

“感觉没有明显 slowdown”的主要原因是：

1. L1 阻塞只重放发生冲突的 Store，不冻结整个 ROB；
2. 多个 L1 事件的 request-to-safe 延迟并行重叠，不能相加；
3. benchmark 总量为 `boom_cycles=905862`、`boom_inst=649956`，而日志没有输出一个名为“所有 barrier stall cycles”的总计数；
4. L2 本次只有一个屏障事件，约 213 个周期，相对 905862 个总周期占比很小。

本次只读取已有 VCD、日志和源码，没有重新仿真或生成硬件。
