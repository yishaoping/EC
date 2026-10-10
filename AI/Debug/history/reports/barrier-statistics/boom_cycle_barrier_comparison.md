# BOOM 周期与屏障对比记录

## 结论

当前工作区的两份记录并不是同一 benchmark、同一二进制、同一动态包流量下的屏障 A/B：

| 记录 | `boom_cycles` | `boom_inst` | packages | store | load |
|---|---:|---:|---:|---:|---:|
| `Experiment/流量分析.typ` | 905862 | 649956 | 32 | 3713 | 723 |
| `chipyard/.../test.log` | 1012405 | 649956 | 279 | 60570 | 95062 |

因此当前文件实际显示 `test.log` 比 `.typ` 多 106543 cycles，约 11.76%，不是更小。

两次 benchmark 的 BFS 校验结果相同（512 nodes、8192 edges、checksum 43439728），但这只能证明架构结果相同，不能证明执行路径相同。`test.riscv` 也不同：

```text
Software/gap测试备份/test.riscv  md5=a6be9906e727cd6194444f59e12861fa
Software/Test/test.riscv        md5=097c409c0d100c9495e97c08b61113b9
```

`.typ` 的旧运行有 32 个包且 checker c4 没有流量；当前 `test.log` 有 279 个包、c4 有流量，L1-L2 replacement barrier 为 370 次而旧运行为 45 次。这个差异远大于一次屏障停顿的影响，不能据此归因于“开屏障后变快/变慢”。

## 屏障是否真的影响大核

现有 VCD 已观察到一次 L2-DRAM functional barrier：

```text
request=595271
barrierServiceActive=595279
rob.io_gh_stall=595281..595707
close_ack=595283
```

VCD 时间单位每两个单位对应一个 BOOM 周期，因此该段 ROB stall 约为 213 个 BOOM cycles，约占当前 1012405 周期的 0.021%。L1 跨包 store 的路径则主要是 LSU s2 nack/replay，不直接驱动 `rob.io_gh_stall`。

`cross_package_store` 等 latency bucket 只记录“事件到 safe watermark”的统计延迟，不参与 cache ready/valid 或 ROB 调度；多个事件可以并行等待，等待区间也可以重叠，不能把 `wait_cycle_sum` 加到 `boom_cycles`。

## 可信 A/B 的要求

后续若要量化屏障 slowdown，必须固定同一 `test.riscv`、同一 generated RTL、同一 benchmark 输入和测量窗口，只改变 `GH_REAL_BARRIER_ENABLED`，并同时记录：

1. `boom_cycles` 和 `boom_inst`；
2. `rob.io_gh_stall` 高电平总周期；
3. L1 跨包 nack/replay 周期；
4. L2 barrier request/ack/stall 区间；
5. 包数量和各级 traffic。

