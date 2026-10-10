# Assert: `stq_execute_head got off track` at 1181000

## 结论

本次断言不是包计数或普通 Store 统计断言，而是 BOOM LSU 的 STQ 队列一致性断言：

```scala
assert(
  io.core.brupdate.b2.mispredict ||
  stq(stq_execute_head).valid ||
  stq_head === stq_execute_head ||
  stq_tail === stq_execute_head,
  "stq_execute_head got off track."
)
```

对应生成 RTL 为：

```verilog
_T_4 = io_core_brupdate_b2_mispredict |
       _stq_stq_execute_head_valid_0 |
       stq_head == stq_execute_head |
       stq_tail == stq_execute_head;
```

失败时的必要条件是：

```text
b2.mispredict = 0
stq[stq_execute_head].valid = 0
stq_head != stq_execute_head
stq_tail != stq_execute_head
```

## 证据边界和时间换算

- 日志：`chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.log`
- 波形：`chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd`
- 断言源：`chipyard/generators/boom/src/main/scala/lsu/lsu.scala:305-309`
- 生成断言：`chipyard/sims/verilator/generated-src/chipyard.TestHarness.v1Config/gen-collateral/LSU.sv:7726`
- 本次 VCD 时间单位与日志时间约为 2:1；末段使用 VCD `2362580..2362620` 追踪。仅对保存的这次运行作结论，未运行仿真或生成 RTL。

## 末段事件表

| VCD 时间 | 事件 | 解释 |
| ---: | --- | --- |
| 2362581 | `stq_execute_head=15`，nack valid，nack 的 STQ idx=13 | DCache 返回较老 Store 的 nack，LSU 后续会回退执行头 |
| 2362583 | `stq_execute_head=13`；请求字段为 STQ idx=13，但 `dmem_req_fire=0` | LSU 重新选择 Store 13，但本拍没有真正握手 |
| 2362595 | `will_fire_store_commit=1`，请求为 STQ idx=14，带 strict token | 这是执行意图，不能等同于 DCache fire |
| 2362601 | 请求变为非 STQ 请求，`dmem_req_fire=1`；Store commit 为 0 | 真正 fire 的请求不是 Store 13，因此 `stq_execute_head` 不推进 |
| 2362607 | nack valid，nack 的 STQ idx=13 | Store 13 再次触发回退/replay 路径 |
| 2362613 | `will_fire_store_commit=1`，请求 STQ idx=13，`uses_stq=1` | LSU 再次准备发 Store 13 |
| 2362615 | 请求已经变为非 STQ idx=9，`uses_stq=0`，但 `dmem_req_fire=1`；同时 `cacheCompletionAccepted=1`，完成 idx=13 | Store 13 的新 LSU 请求没有 fire；旧 DCache replay 的物理写入却完成并消费 token |
| 2362617 | `clear_store=1` | Store 13 的 `succeeded=1` 且 token 已消费，满足当前回收条件 |
| 2362619 | `stq_13_valid=0`，`stq_head=14`，`stq_execute_head` 仍为 13 | 断言不变量被破坏：执行头指向刚回收的无效槽，且不等于 head/tail |

对整个指针/valid trace 做状态重建，在本次波形末端得到：

```text
execute_head = 13
stq_head      = 14
stq_tail      = 9
stq[13].valid = 0
```

## 完整信号逻辑链

```text
DCache 对 Store 13 产生 nack
  -> LSU lsu.scala:1579-1581 用 IsOlder 回退 stq_execute_head=13
  -> LSU 在 lsu.scala:1009-1028 尝试重新发 Store 13
  -> 该拍 dmem_req_fire=0；下一拍仲裁到非 STQ 请求并 fire
  -> 旧请求的 DCache/M SHR replay 仍携带 Store 13 的 strict token
  -> dcache.scala:1591-1603 产生 cache completion(idx=13, token)
  -> LSU lsu.scala:1932-1938 接受 completion，置 succeeded=1 并清 token
  -> lsu.scala:2041-2043 得到 clear_store=1
  -> lsu.scala:2046-2063 清除 stq[13]、stq_head=14
  -> stq_execute_head 没有在该拍通过 dmem_req_fire 推进
  -> 下一采样点执行头仍为 13，指向 invalid STQ
  -> lsu.scala:305 断言失败
```

## 根本原因

当前设计把三个不同事件混在了两个独立推进条件中：

1. `stq_execute_head` 只在 LSU 请求真正 `dmem_req_fire` 时推进；nack 会把它回退到重试项。
2. 严格 Store 的 token completion 来自 DCache 物理写入/replay，可以在当前 LSU 重试请求尚未 fire 时到达。
3. `clear_store` 只要求队首 Store `succeeded && !strict_store_token_valid`，没有要求执行头已经离开该槽。

因此旧 replay 完成可以先消费 token、回收 `stq_head`，而 `stq_execute_head` 仍停留在同一个 STQ index。这个是队列指针与物理完成事件之间缺少顺序约束的竞态；不是 LSU 容量溢出的直接证据，也不是统计计数器本身的断言。

## 对已有统计修复的影响

- 断言发生在 LSU STQ 指针维护，不表示 `archStoreTotal`、`strictStoreTotal` 或包计数已经被该断言直接修改。
- `cacheCompletionAccepted` 已通过 `stq_idx + strict_store_token` 匹配；本次波形显示 token 匹配本身成功，问题是匹配成功后回收与执行头推进不同步。
- 不能删除或放宽断言，也不能把 completion 事件改回无条件计数，否则会重新引入跨 replay 重复统计。
- 修复必须保留 token 的一次性消费、包序号和普通架构 Store 提交点统计。

## 修复方案与实现

在接受 `cacheCompletionAccepted`/`uncacheCompletionAccepted` 时，如果完成项正好是 `stq_execute_head`，则推进执行头一格。这样旧 replay 已经完成并消费该 Store 的 token 后，不会让 `clear_store` 回收执行头仍指向的槽位。实现中同时处理：

- 如果同拍有不同的较老 Store nack 需要回退，则保留 nack 回退优先级；
- completion 和 Store 请求同拍 fire 时，同一个 STQ 项只推进一次，不同项分别推进；
- cache/uncache 两条完成路径；
- fence、分支清除、异常和 STQ index 复用；
- token 只消费一次，不能产生新的 strict Store 或包统计事件。

已在 `chipyard/generators/boom/src/main/scala/lsu/lsu.scala` 实施：执行头推进只由已接受的 cache/uncache token completion 触发，且仅当 completion index 与执行头相同。completion 仍使用原来的 `STQ index + strict_store_token` 接受条件，strict Store 计数与 token 清除逻辑未改变。

本次仅做静态检查，未运行仿真、未生成硬件；因此运行时对 nack/completion 同周期交叠的验证仍待后续回归。

## 可复用追踪命令

```bash
/home/guozh/.codex/skills/ec-debug-analysis/scripts/ec_fst_trace.sh \
  chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd \
  2362580 2362620 \
  '.*tile_reset_domain_boom_tile\\.lsu\\.(stq_execute_head|stq_head|stq_tail|stq_[0-9]+_valid|io_dmem_nack_0_valid|io_dmem_nack_0_bits_uop_stq_idx|io_dmem_req_bits_0_bits_uop_stq_idx|io_dmem_req_bits_0_bits_uop_uses_stq|dmem_req_fire_0|will_fire_store_commit_0_will_fire|clear_store|cacheCompletionAccepted|io_dmem_traffic_store_cache_complete.*)'
```
