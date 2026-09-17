# BOOM/Rocket Store-Load 计数不匹配：原因总结

## 结论

本次差异不是 Rocket 小核重复执行了 BFS、`memcpy` 或某个软件循环，也不是软件读回计数器时发生了重复累加。波形中，BOOM 在检查状态下提交的访存条数与四个 Rocket checker 的完成条数一致：

```text
BOOM status=2 提交：store=60570，load=95062
Rocket checker 汇总：store=60570，load=95062
```

真正不一致的是 **BOOM DCache traffic counter 的记账口径**：它按 DCache 请求进入、响应、data-array 写入和 STQ forwarding 等微结构完成点统计；Rocket 按 LSL 返回且 WB 成功的 checker 重执行事件统计。两边的检查窗口、事件完成点和状态采样点不是同一件事。

因此，日志里的“checker 多记”应准确理解为：相对于 BOOM traffic counter，checker 净多出了一些 cacheable 事件；在具体 PC 上同时存在 BOOM 多记和 BOOM 少记，不能把差异归结为小核额外执行。

## 观测值与归一化

来源：`chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.log`。

| 类别 | BOOM | Rocket checker 汇总 | 差值（checker - BOOM） |
|---|---:|---:|---:|
| store total | 60566 | 60570 | +4 |
| cacheable store | 60517 | 60521 | +4 |
| uncacheable store | 49 | 49 | 0 |
| load total | 94965 | 95062 | +97 |
| cacheable load | 93101 | 94765 | +1664（分类差异） |
| uncacheable load | 297 | 297 | 0 |
| BOOM STQ-forward load | 1567 | 0 | 不同分类 |

BOOM 的 STQ-to-LDQ forwarding 在 DCache response 之外完成，Rocket checker 没有该路径，而是通过 LSL 再读出。因此可比较的 BOOM cacheable load 是：

```text
93101 + 1567 = 94668
94765 - 94668 = 97
```

最终可比较的净差是 **4 个 cacheable store、97 个 cacheable load**；49 个 uncacheable store 和 297 个 uncacheable load 完全一致。

## 已确认的证据

### 1. 软件没有重复执行

- 从 VCD 统计 `debug_maincore_status == 2` 时 BOOM ROB 的精确访存提交，得到 `store=60570`、`load=95062`。
- 该结果与四个 checker 的汇总完成数完全相等。
- 高计数 PC 仍是正常应用/库代码，例如 BFS 的 `0x80000948`、`0x80000954` 和 `memcpy` 的 `0x800032ae`，不是统计打印循环。

### 2. 软件读回和 checker 计数器没有重复

- 波形中的 checker 最终计数器与 `test.log` 逐项一致。
- 每个 checker 的 `checker_store_complete`/`checker_load_complete` 与对应 LSL `st_deq`/`ld_deq` 一一对应；没有发现同一条 LSL 记录被重复 dequeue。
- 完整包校验通过：`allocated=280 completed=280 passed=280 failed=0 cancelled=0`。
- 因此包协议通过与访存统计相等是两个独立条件；包全部通过不能证明 DCache 计数口径正确。

### 3. 波形直接看到请求状态与完成状态错位

发现 16 个 cacheable BOOM response 满足：

```text
response.traffic_check = 0
当前 debug_maincore_status = 2
response.traffic_cacheable = 1
```

这些请求进入 DCache 时没有带检查标记，稍后响应时主核已经进入 `fsm_check`，所以 BOOM 不计数，而对应的 checker 重执行会计数。事件涉及的典型 PC 为：

```text
0x80000788 (3), 0x8000078c (2), 0x80000954 (7),
0x80000b20 (1), 0x80000ba4 (2), 0x800032ae (1)
```

这直接证明了“响应时状态”不能替代“请求进入时的检查窗口归属”。

### 4. PC 对齐显示存在正负抵消

cacheable load 中，checker 相对 BOOM 的主要正差为：

| PC | 指令/位置 | 净差 |
|---|---|---:|
| `0x800032ae` | `memcpy`: `lb t2,0(a1)` | +93 |
| `0x80000954` | BFS: `lbu t1,0(t1)` | +37 |
| `0x80000ba4` | BFS frontier/parent: `lw t4,0(a2)` | +12 |
| `0x80000a04` | parent: `lw a2,0(a3)` | +7 |
| `0x80000a18` / `0x80000a1c` | bookkeeping loads | +6 / +5 |
| `0x8000090c` / `0x80000a20` | BFS bookkeeping loads | +5 / +4 |
| `0x80000788` / `0x8000078c` | BFS graph loads | +3 / +2 |

这些正差合计约 `+176`；BOOM 在 `0x80000948` 等 PC 上多记约 `79`，净值才是 `+97`。这说明根因是事件归属/完成点错位，而不是某个循环整体多执行。

cacheable store 的主要正差为：

```text
0x800007e8  sh a2,0(a4)     +2
0x80000848  sw zero,316(a4) +1
0x80000970  sw a6,0(a5)     +1
0x80000a30  sw a0,12(s7)    +1
0x80000c04  sw t1,0(a1)     +1
```

`memcpy/memset` 的 `0x800032b2`、`0x800032c4` 上 BOOM 各多记一次，trap 入口/出口栈 store 的正负差又相互抵消，最终留下 `+4`。

## RTL 根因链

### BOOM：请求入口采样，完成点统计

1. `chipyard/generators/boom/src/main/scala/common/tile.scala:603-604` 将
   `debug_maincore_status === 2.U` 接成 `traffic_check_state`。
2. `chipyard/generators/boom/src/main/scala/lsu/dcache.scala:637-642` 仅在 LSU 请求进入 DCache 时把该状态采样到 `s0_req(w).traffic_check`；之后该元数据随 MSHR/replay/response 传播。
3. cacheable store 在 `dataWriteArb.io.in(0).fire` 统计；uncacheable store 在 TileLink A 接受时统计。
4. load response 在 `lsu.scala:1414-1426` 以 `traffic_check && !traffic_seen && mem_cmd == M_XRD` 统计；STQ forwarding 在 `lsu.scala:1494-1498` 另行统计。

这些点都不是 ROB retirement。请求可能是推测路径、可能跨越 R_IC 状态切换，也可能在请求没有检查标记时于检查状态中返回。

尤其是 forwarding 的归属在 `lsu.scala:1137-1140` 通过全局状态延迟两拍得到：

```scala
mem_forward_traffic_check = RegNext(io.dmem.traffic_check_state)
wb_forward_traffic_check  = RegNext(mem_forward_traffic_check)
```

它不是每条 load 的 request-level 元数据，所以状态边界附近的 forwarding 容易被错归类。

### Rocket：checker LSL/WB 完成点统计

`chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala:891-907` 使用：

```scala
checker_mem_complete = checker_mode && wb_valid && wb_ctrl.mem &&
                       lsl_resp_valid && !lsl_resp_replay
```

再按精确 `M_XWR`/`M_XRD` 分类。`R_ICSL.scala:508-545` 在自身 perf window 内累加完成事件；Rocket 在 `fsm_postchecking` 仍保持 checker mode（`R_ICSL.scala:256-265`）。

所以 Rocket 的统计窗口是“checker 重执行完成”，BOOM 的窗口是“请求入口时采样的 `fsm_check` + 后续微结构完成”，两者并不严格相同。

## 不能作为主因的解释

- **不是 checker 软件循环重复执行。** 提交级访存数与 checker 汇总相等。
- **不是 GHE/CSR 读回重复累加。** 波形最终计数器和日志一致。
- **不是 LSL 同一记录重复 dequeue。** completion 与 LSL dequeue 一一对应。
- **不能只归因于 BOOM STOP 后的在途 response。** 波形确实存在 STOP 附近的尾部响应，但它没有单独证明恰好产生 `4+97`，且其中部分属于窗口外普通 BOOM 执行；主因仍是请求入口状态采样与完成窗口不一致。
- **不能把 `4`、`97` 当作固定补偿常数。** 不同 workload、包边界和 cache/replay 行为会改变差异。

## 修复原则（不改变访存和包协议）

1. **先定义唯一比较口径。** 若目标是让大小核访存数匹配，应比较同一检查窗口内的架构访存完成/提交事件；不要将 BOOM 的物理 data-array handshake 与 checker 的 WB 事件直接当成同一事件。
2. **保留物理流量与架构计数的区分。** DCache 命中、TileLink A 接受、响应、forwarding 等可继续用于 latency/traffic 分析，但应单独命名，不能冒充 checker 指令数。
3. **检查标记必须按请求携带。** load response、replay、MSHR 和 STQ forwarding 都应使用该条请求保存的 window/sequence 元数据；forwarding 不能只采样全局信号并延迟两拍。
4. **统一窗口边界。** 明确 `fsm_check`、`fsm_postchecking`、perf START/STOP 和 checker WB 的包含关系；必要时对窗口关闭前已发出的请求排空，或用窗口/包序号进行归属，而不是立即关闭计数。
5. **严格去重和分类。** 只在精确的 `M_XWR`/`M_XRD` 完成点计数；`traffic_seen` 只能由窗口内的有效完成消耗，不能被窗口外 speculative response 提前置位。LR/SC/AMO 必须保持独立。
6. **验证时同时检查三组数。** 对每个窗口分别比较：BOOM ROB/提交级事件、BOOM DCache 物理完成事件、Rocket checker WB 事件，并做 PC/包序号对齐；同时检查：

```text
BOOM load_total = load_cache + load_uncache + load_forward
Rocket load_total = load_cache + load_uncache
store_total = store_cache + store_uncache
```

本次分析未修改 RTL、软件或包释放逻辑；只新增本总结文件。工作区中原有未提交修改应继续保留。
