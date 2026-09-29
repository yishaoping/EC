# Benchmark 阻塞开启与实际触发核对

核对对象：

- VCD/FST：`chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd`
- 日志：`chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.log`
- benchmark：`gapbs_bfs nodes=512 edges=8192`
- 本次只读取已有日志、生成物和波形，没有重新仿真或生成 RTL。

## 结论

两个功能阻塞都已开启，并且都在该 benchmark 运行期间实际触发：

1. L1 DCache 跨包 Store 阻塞：已直接从波形确认。
2. L2-DRAM 屏障协议实际导致 BOOM 流水线/ROB 停顿：已直接从请求、close-ack、`barrierServiceActive`、`io_if_pipeline_stall` 和 `rob.io_gh_stall` 的时序确认。当前波形不能把 ROB stall 的每一个周期单独拆分成 `functionalBarrierStall` 与 `ic_stall` 两个组合项。

## 1. L1 跨包 Store 阻塞

源码开关是 `GH_REAL_BARRIER_ENABLED`，定义为 `true`：

`chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala:9`

运行时逻辑位于：

`chipyard/generators/boom/src/main/scala/lsu/dcache.scala:797-803, 1004-1017`

其链路为：

```text
crossPackageBlockCondition
  -> l1CrossPackageBlocked
  -> s2_nack(0)         // 仅对 LSU 写操作并入
  -> s2_send_nack(0)
  -> LSU replay/store retry
```

波形中的实际证据：

| 信号 | 结果 |
|---|---:|
| `dcache.l1CrossPackageBlocked` 上升沿 | 1183 |
| `dcache.crossPackageBarrierStats.eventAccepted` 事件 | 波形中可见（该内部脉冲在尾部窗口与阻塞边沿存在统计窗口差异） |
| `dcache.s2_nack_0` 在阻塞上升沿同时为 1 | 1183/1183 |
| 首次阻塞 | VCD 时间 389201 |
| 最后一次阻塞 | VCD 时间 396293 |
| 首次阻塞处理 | `crossPackagePending` 在 389203 置 1 |
| writeback 发出 | `crossPackageWbReq_valid` 在 396257 置 1 |
| writeback active/done | 396261 / 396291 |
| meta clear pending | 396293 |

因此 `cross_package_store seen=1183` 不是只存在于统计寄存器中的假事件；波形中 1183 次 `l1CrossPackageBlocked` 上升沿都对应 DCache nack，且日志最终收敛为 1183 个已解析事件。统计事件脉冲与日志汇总还受到统计窗口/同步时序影响，不能用某个内部脉冲信号的简单边沿数替代日志计数。计数的单位是阻塞等待事件/边沿，不是 1183 个不同的静态地址，也不是 1183 次已经提交的架构 Store。

## 2. L2-DRAM 功能屏障

BOOM 源码中的功能路径位于：

`chipyard/generators/boom/src/main/scala/exu/core.scala:2012-2076`

关键逻辑是：

```text
l2BarrierReq -> barrierServiceActive
             -> functionalBarrierStall
             -> rob.io.gh_stall
```

本次波形事件表：

| VCD 时间 | 信号 | 解释 |
|---:|---|---|
| 595271 | `core.gh_l2_dram_barrier_request_0=1` | L2-DRAM 屏障请求到达 BOOM |
| 595271 | `core.gh_l2_dram_barrier_request_seq_0=0x100000` | 请求序号 |
| 595279 | `core.barrierServiceActive=1` | BOOM 开始服务屏障 |
| 595281 | `core.rob.io_gh_stall=1` | ROB 实际停止提交；同时 `core.ic_master.io_if_pipeline_stall=1` |
| 595283 | `l2.gh_l2_dram_barrier_close_ack_0=1` | L2 返回 close-ack |
| 595283 | `l2.gh_l2_dram_barrier_close_ack_seq_0=0x100000` | ack 与 request 序号一致 |
| 595707 | `core.rob.io_gh_stall=0` | ROB 停止解除 |
| 595709 | `core.barrierServiceActive=0` | 屏障服务结束 |
| 595709 | `l2.gh_l2_dram_barrier_close_ack_0=0` | ack 脉冲结束 |

日志也记录了：

```text
l2_dram_replacement seen=1 resolved=1 pending=0 dropped=0
```

生成 annotation 中保留了 request、request sequence、close-ack、close-ack sequence 和统计输出。`functionalBarrierStall` 组合节点本身没有作为独立顶层探针保留。源码显示：

```text
functionalBarrierStall = enabled && barrierServiceActive && request && close_ack && seq_match
ic_stall               = ic_master.io.if_pipeline_stall
rob.io.gh_stall        = ... || ic_stall || ... || functionalBarrierStall
```

本次波形中 request 同步后，`barrierServiceActive` 在 595279 置 1；`io_if_pipeline_stall` 和 `rob.io_gh_stall` 在 595281 置 1；匹配序号的 close-ack 在 595283 置 1，并一直保持到释放前。由此可以确认 L2-DRAM 屏障协议真实触发，并且已经造成流水线/ROB 停顿。由于 `functionalBarrierStall` 与 `ic_stall` 最终在同一个 `rob.io_gh_stall` OR 汇合点，当前波形不能把 ROB stall 的全部周期单独归因给 `functionalBarrierStall`；但从 595283 起其组合条件已满足，功能屏障项至少在该段时间被激活。

## 可复用命令

```bash
EC_REPO_DIR=/data1/gzh/EC \
  /home/guozh/.codex/skills/ec-debug-analysis/scripts/ec_fst_trace.sh \
  chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd \
  0 2635097 \
  '(^|\\.)l1CrossPackageBlocked$' '(^|\\.)s2_nack_0$' \
  '(^|\\.)crossPackagePending$' '(^|\\.)crossPackageWbReq_valid$' \
  '(^|\\.)crossPackageWbActive$' '(^|\\.)crossPackageWbDone$'

EC_REPO_DIR=/data1/gzh/EC \
  /home/guozh/.codex/skills/ec-debug-analysis/scripts/ec_fst_trace.sh \
  chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd \
  590000 600000 \
  'gh_l2_dram_barrier_request_0' 'gh_l2_dram_barrier_request_seq_0' \
  'gh_l2_dram_barrier_close_ack_0' 'gh_l2_dram_barrier_close_ack_seq_0' \
  'barrierServiceActive' 'rob.io_gh_stall'
```
