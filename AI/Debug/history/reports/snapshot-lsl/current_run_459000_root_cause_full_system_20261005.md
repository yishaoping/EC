# 当前 459000 失败：全系统根因复核（只读）

## 结论

当前日志中的

```text
[459000] ... assert__assert_22: little core 1 has hung
```

是 BOOM 侧 checker ownership watchdog 的最终症状，不是首个功能错误。当前首因是
`R_LSL.scala` 新增的类型/地址匹配逻辑与 `GH_MemFIFO` 的同步读接口形成闭环：
FIFO 已经非空，但队首数据只有在 `io_deq_ready` 为高时才会从
`SyncReadMem` 建立；而 `io_deq_ready` 又被要求先通过队首类型和地址匹配。因此
队首永远读不出来，也永远不能 dequeue。

这次运行与历史 `461000/assert__assert_21` 不同。历史修改解决了“load 无条件消费
store 队首”的错误，却把读请求启动和真正 dequeue 合并成了一个条件，产生了新的
同步 FIFO 死锁。快照/包分配边界在当前波形中已经形成稳定的 `seq=1`，不是本轮
首因；DCache、地址统计和跨包 writeback 也没有先于 LSL 进入故障状态。

## 证据边界

- 日志：[test.log](/data1/gzh/EC/chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.log)
- 当前 FST（扩展名仍为 `.vcd`）：[test.vcd](/data1/gzh/EC/chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd)
- 当前生成 RTL：[R_LSL.sv](/data1/gzh/EC/chipyard/sims/verilator/generated-src/chipyard.TestHarness.v1Config/gen-collateral/R_LSL.sv)、[GH_MemFIFO_1.sv](/data1/gzh/EC/chipyard/sims/verilator/generated-src/chipyard.TestHarness.v1Config/gen-collateral/GH_MemFIFO_1.sv)、[BoomCore.sv](/data1/gzh/EC/chipyard/sims/verilator/generated-src/chipyard.TestHarness.v1Config/gen-collateral/BoomCore.sv)
- 当前 FST 结束于 `917376`，日志停止点为 `459000`；本次 trace 中 FST 时间约为日志时间的 2 倍。下表时间均为 FST 时间。
- 生成 RTL 时间为 2026-10-05 08:42，波形/日志时间为 09:53；它们属于同一轮当前源码生成的运行。没有把历史波形与当前波形混作同一修订。

## 断言含义

生成 RTL 的 `BoomCore.sv:6884` 映射到当前源码
`boom/src/main/scala/exu/core.scala:2130`：

```scala
assert(!little_status1(checkerHangWatchdogBit), "little core 1 has hung")
```

当前 `checkerHangWatchdogBit = ecWatchdogBit = 18`，`WideCounter` 的生成 RTL
检查的是 `large_1[13]`，即 2^18 量级。计数器在 checker `ic_status_1` 保持有效
且尚未收到 clear 时持续增加。降低阈值只能改变停止时间，不能修复协议阻塞。

## 直接事件表

| FST 时间 | 观测 | 解释 |
|---:|---|---|
| 393091 | `snapshot_accepted=1`、`if_dosnap=1` | BOOM 接受快照 |
| 393093 | `packet_alloc_valid=1`、`packet_alloc_seq=1`、`active_packet_seq=1`、`package_owned_1=1` | 当前包分配已经在内部和 LSU/DCache 侧对齐 |
| 393257 | channel 0 `W1_en=1`，写入 130-bit LSL 项，最高两位为 `10`，低 40 位为 `0x80087f58` | 队列写入一个 store 项 |
| 393261 | channel 0 `io_empty` 从 1 变 0 | FIFO 已非空 |
| 393265 | channel 1 写入同样最高两位为 `10` 的项，低 40 位为 `0x80087f68` | 第二个 FIFO 也开始积压 store 项 |
| 393269 | channel 1 `io_empty` 从 1 变 0 | 两个 LSL FIFO 均有内容 |
| 393481/393485 | `icsl_run` 脉冲，`R_ICSL.fsm_state=010` | checker 进入普通 checking 状态（枚举值 2） |
| 393637 | `sl_counter=1` | 只观察到极少的 checker 指令提交 |
| 393645 | `lsl_req_valid=1`、`req_cmd=01`、`req_addr=0x200bff8` | checker 发出 load 请求 |
| 393645 以后 | channel 0/1 `io_deq_ready=0`、`deq_valid=0`、`lsl_deq_fire=0`、`mem_ext.R0_en` 没有变 1 | 没有一次真正的 LSL 读/出队 |
| 402233 起 | `R_ICSL.fsm_state` 在 `010` 与 `100` 间往返 | 仍未进入 postchecking/cleanup；`100` 是 self-exception 状态 |
| 波形末端 | channel 0/1 `io_empty=0`，`selected_head=0`，`selected_head_is_{load,store}=0`，`io_deq_ready=0` | 队列仍非空，队首数据从未建立 |
| 459000 | `assert__assert_22` | checker ownership watchdog 触发 |

## 同步 FIFO 闭环

源码 `rocket-chip/src/main/scala/guardiancouncil/GH_FIFO.scala:142,195` 使用：

```scala
val mem = SyncReadMem(...)
io.deq_bits := mem.read(readPtr, io.deq_ready)
```

生成的 `GH_MemFIFO_1.sv` 明确给出：

```verilog
.R0_en   (io_deq_ready)
.R0_data (io_deq_bits)
```

生成的 `mem_combMem_0.sv` 进一步显示 `_GEN <= R0_en`，只有 `_GEN` 为高时
`R0_data` 才读取 `Memory[_GEN_0]`，否则输出未定义值（Verilator trace 中表现为 0）。

当前 `R_LSL.scala:137-149` 的依赖关系是：

```text
selected_head <- u_channel.io_deq_bits <- SyncReadMem(readPtr, io_deq_ready)
lsl_req_type_match/address_match <- selected_head
lsl_req_match <- type_match && address_match && nonempty
lsl_deq_fire <- req_valid && lsl_req_match
io_deq_ready <- lsl_deq_fire
```

因此非空 FIFO 的初始状态为：

```text
empty=0
deq_bits=0/无效
type/address match=0
deq_ready=0
SyncReadMem 不读
deq_bits 继续无效
```

这是闭环死锁，不是 CDC 入队丢失。当前波形还直接证明了入队已经发生：两个
`empty` 已变 0，且持续存在；同时整个 FIFO handshake trace 没有
`R0_en=1`、`io_deq_ready=1` 或 `deq_valid=1`。

## 为什么历史 461000 与当前 459000 不矛盾

历史版本的 dequeue 条件约为：

```scala
deq_valid := bank === i && io.req_valid && !empty && !req_kill
io.req_ready := any_nonempty
```

它会先启动同步读，下一拍用 `RegNext(deq_valid)` 对齐响应，但没有校验类型/地址，
所以出现过“load 消费 store 队首、ELU 报地址错误”的功能错误。

当前版本把类型/地址校验直接放进 `lsl_deq_fire`，确实阻止了错误消费，但同时也
阻止了启动首读。也就是说，修复了旧错误的判定条件，却破坏了同步 RAM 的
`read-request -> registered-data -> compare -> consume` 两阶段协议。

## 完整放大链

```text
LSL FIFO 已入队
  -> 同步读未启动，队首类型/地址永远无效
  -> lsl_deq_fire=0，LSL 不返回响应且不消费队首
  -> checker 的 load/store 请求反复等待/replay
  -> lsl.io.if_empty 始终为 0
  -> RocketCore.package_data_complete / arf_compare_ready 不成立
  -> package_result_event 不产生，result queue 不入队
  -> checker_cleanup_done 不成立，R_IC 不清 ic_status/package ownership
  -> BOOM ic_status_1/package_owned_1 保持有效
  -> little_status1 累加到 2^18
  -> assert__assert_22 at log 459000
```

源码对应关系：

- `RocketCore.scala:1334-1336`：checker cleanup 要求 `lsl.io.if_empty`；
- `RocketCore.scala:1413-1422`：ARF compare/data completion 要求 LSL empty；
- `RocketCore.scala:1482-1515`：只有完整完成或取消才生成并允许 handoff result；
- `core.scala:2112-2133`：`ic_status_1` 未清除时 watchdog 不复位并最终断言。

当前保存 trace 中 `checker1_result_chain` 只有 handoff-allowed 的早期变化，没有
`package_result_fire`；`recheck_459000_release_chain.txt` 只看到
`package_owned_1=1`，没有对应 clear。它与 LSL 队列末端状态一致。

## 已排除或暂不能归因的部分

### 当前首因已排除的替代解释

- **快照半周期/包序号错位**：当前 `393093` 同时看到 `packet_alloc_seq=1`、
  `active_packet_seq=1`、LSU/DCache 采到 1；历史的 seq 脉冲问题在本轮不是首因。
- **CDC 入队丢失**：channel 0/1 的写使能、写数据和 `empty=0` 均可见。
- **DCache 跨包 writeback**：在 package data 尚未完成前，LSL 已经阻塞；不能把
  之后的 DCache 路径当作首因。
- **地址统计窗口/259 包统计**：当前仿真在 checker watchdog 处停止，尚未到达结果和
  统计收尾；历史统计修复不能解释本轮首个停滞点。

### 修复 LSL 后必须重新复核、但当前尚未证明为首因的风险

1. `R_LSL` 同步读出的 payload、请求元数据、`resp_valid`、`resp_replay` 是否一拍严格对齐。
2. 类型/地址不匹配时队首必须保持，匹配后只能消费一次，不能重复响应。
3. `R_ICSL.scala:135-139` 的 `sl_counter + 1` 尾完成判断仍有历史记录的边界风险。
4. LSL 清空后，`package_data_complete -> result enqueue -> GHM dequeue -> ic_status clear`
   的顺序必须保持；不能用修改 watchdog 阈值掩盖 release 不完整。
5. 恢复后再检查 259 包、地址统计、packet sequence 和屏障开关下流量口径。

## 本次检查范围

只读检查了当前日志、当前 FST、生成 RTL、当前 Scala 源码、历史 Debug 记录，并运行了
`check_debug_invariants.py`（通过）。没有修改硬件/软件源码，没有生成 RTL，没有运行仿真。
