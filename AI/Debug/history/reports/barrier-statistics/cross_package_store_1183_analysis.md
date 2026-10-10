# `cross_package_store=1183` 分析

## 结论

`test.log` 中的 1183 不是 1183 条唯一的架构 store，也不能直接解释为 1183 次物理重复写。当前硬件在 `GH_REAL_BARRIER_ENABLED=true` 时统计的是 **跨包 store 被屏障阻塞的一次次观测/等待事件**。统计点使用 `l1CrossPackageBlocked` 的边沿，不要求 `dataWriteArb.io.in(0).fire`；同一条 store 在 nack/replay 过程中可能再次形成边沿。因此该数同时包含：

1. 不同包对同一 cache line 的真实跨包修改尝试；
2. 同一 cache line 被多个后续包重复修改的合法事件；
3. store 被屏障 nack 后重新进入流水线产生的再次观测，当前代码没有用 store token 做去重。

## 日志证据

来自 `/data1/gzh/EC/chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.log`：

| 项目 | 数值 | 解释 |
|---|---:|---|
| benchmark | `gapbs_bfs`, 512 nodes, 8192 edges | 方向优化 BFS |
| checker package | 32 allocated/completed/passed | 统计窗口内有 32 个校验包 |
| BOOM 指令 | 649956 | 窗口内执行规模 |
| 架构 store | 3713 | 提交点 store 统计 |
| cache store | 3698 | 绝大多数 store 命中可缓存路径 |
| cross package store | 1183 | 当前屏障观测事件 |
| cross 平均等待 | 1755.052 BOOM cycles | 约 8.775 us，200 MHz |
| cross pending/dropped | `0/0` | 桶统计收敛且没有溢出 |

几个比例说明其量级：

- `1183 / 3713 = 31.85%`，说明约三分之一的提交 store 处在包边界造成的共享 cache-line 竞争环境中；
- `1183 / 32 = 36.97`，平均每个包约 37 次跨包等待观测；
- 地址统计只显示 260 条 cache line，但 `1183 / 260 = 4.55`，这不矛盾。260 是窗口内不同 line 的数量，1183 统计的是这些 line 在多个包之间反复改变 provenance 的次数/等待观测，不能用唯一 line 数限制它。

`seen=resolved=1183, pending=0, dropped=0, valid=1` 只证明延迟桶内部没有丢事件或未结算事件，不证明 1183 对应 1183 条唯一 store。

## Benchmark 为什么容易产生这类事件

`gapbs_bfs_run_512` 使用 512 个节点、每节点 16 条边的环形图。BFS 反复更新以下紧凑数组：

- `parent[node]`：top-down 和 bottom-up 阶段都会写；
- `next_bits[node]`、`front_bits[node]`：每轮清零、复制；
- `frontier[]`、`next_frontier[]`：每轮重新生成和搬运；
- `out_offset/in_offset/out_edge/in_edge`：构图阶段顺序写入。

这些数组的 cache line 数量有限且访问密集。不同校验包覆盖 BFS 的连续指令区间，因此后一个包很容易再次写入仍带有前一个包 provenance 的同一 L1 line。方向优化 BFS 还会在 top-down 和 bottom-up 之间反复扫描并写回同一批数组，形成大量合法的跨包 line ownership transition。这个行为与 `parent_checksum` 和 BFS 验证通过并不冲突；它是数据布局和访问模式的结果。

## 硬件信号链

### 1. line provenance

在 `dcache.scala` 中，真实 data-array 写入发生在：

```scala
dataWriteArb.io.in(0).fire
```

写入后，`dirtyPacketSeq(set)(way)` 被更新为当前 `s3_req.packet_seq`，并将 `dirtyPacketTracked` 置位。该状态表示 resident line 最近被哪个校验包修改。

### 2. 跨包阻塞条件

当前 `crossPackageBlockCondition` 的条件是：

```text
REAL_BARRIER_ENABLED
&& s2_valid
&& t_lsu 写请求
&& 当前请求 packet_seq != 0
&& resident line 已 tracked
&& 旧 packet_seq != 当前 packet_seq
&& 旧 packet_seq > safePacketWatermark
```

满足后，`l1CrossPackageBlocked` 进入 `s2_nack`，LSU 将 store 重新执行。此时 store 还没有进行 data-array 写入。

### 3. 当前 1183 的统计点

真实屏障打开时：

```scala
val crossPackageWaitStarted =
  l1CrossPackageBlocked && !crossPackageWaitActive

val crossPackageBarrierEvent = trafficCounting &&
  crossPackageWaitStarted
```

这里没有 `dataWriteArb.io.in(0).fire`，所以该事件的定义是“进入阻塞等待”，不是“完成了一次跨包 store 写入”。`crossPackageWaitActive` 在 `l1CrossPackageBlocked` 变低时清零，而 nack/replay、流水线气泡或请求切换都可能让这个 level 短暂变低。同一架构 store 后续再次进入 `s2` 时，可能再次产生 `crossPackageWaitStarted`。

此外，`crossPackagePending` 只有一个全局 pending line。多个 set/way 同时发生跨包竞争时，统计事件可以继续产生，但 pending 状态不能为每个 line 独立保存；这进一步说明 1183 是监控到的阻塞尝试数，而不是唯一事务数。

## 根因分层

- **直接原因，已由源码证明**：统计在 `s2` 阻塞边沿，未要求物理写入 fire。
- **数量放大的架构原因，已由源码证明**：nack 会使 store replay；统计边沿寄存器在 level 下降后重新武装，可能重复观测同一 store。
- **工作负载原因，强支持**：BFS 对少量紧凑、共享 cache line 的数组进行多轮清零、复制和 parent 更新，32 个包之间产生大量 line provenance 转换。
- **尚未由当前 test.log 单独证明**：1183 中有多少是同一 store 的 replay 重复，有多少是不同包对同一 line 的合法独立修改。日志没有打印地址、packet_seq、STQ index 或 uop/token；需要从 VCD 同时统计 `crossPackageWaitStarted`、`s2_nack`、`dataWriteArb.io.in(0).fire` 和请求身份才能精确拆分。

## 建议的统计修正

应把两个指标分开：

1. **barrier wait events**：保留当前 `s2` 阻塞边沿，用于测量理论屏障等待次数和等待周期；
2. **unique cross-package store writes**：只在真实 `dataWriteArb.io.in(0).fire` 时计数，并携带架构提交 token。对 `(line, new_packet_seq, store_token)` 做一次性消费，nack/replay 不重复计数。

如果目标是测量每个 line 的屏障等待，而不是每次 store，pending 结构也应从单个全局项扩展为按 line/tag 保存的有界表；否则多条 line 并发等待时，计数和实际等待对象无法一一对应。

## 验证边界

本分析只读取了 `test.log`、benchmark 源码和当前 Scala 源码，没有重新仿真或生成 RTL。当前日志能证明计数已经收敛，但不能仅凭 35 行文本恢复每个事件的 store 身份；事件去重比例需要后续用已有 VCD 做定向波形统计。
