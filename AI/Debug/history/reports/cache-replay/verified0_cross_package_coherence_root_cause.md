# 当前运行 `verified=0` 的失败原因与修复方案

## 结论

当前 `test.log` 不是只有统计窗口差异，而是 benchmark 的内存结果已经错误：

```text
verified=0
parent_checksum=6535936116
```

参考运行是 `verified=1`、`parent_checksum=43439728`。因此不能先用
`61299` 与 `60570` 比较来判断 barrier 的性能影响。

保存的波形直接证明跨包 shadow writeback 存在两个一致性协议错误。第一，使用了
错误的 TileLink 权限参数：

```text
3107759 dcache.wb.io_release_bits_param = 000
```

`TLPermissions.TtoB = 0`，表示写回后仍保留 Branch 权限；但随后硬件在
`crossPackageMetaClear` 中把同一 cache line 的元数据清为 `ClientMetadata.onReset`
（Nothing）。也就是 L2 被告知“BOOM 仍持有 Branch”，而 BOOM 本地已经无效化该行。
这是跨包 writeback 的一致性状态错误，强烈支持它是 `parent[]` 被破坏的直接上游原因。

第二，第一次 writeback 完成后存在重复发起竞态：

```text
3107791 wb.io_idx_valid = 0
3107793 crossPackageWbReq_valid = 1
3107793 crossPackageMetaClearPending = 1
3107793 metaWriteArb.io_out_valid = 1
3107795 crossPackagePending = 0
3107795 wb.io_idx_valid = 1
```

`crossPackageWbDone` 清零 `crossPackageIssued`，但 `crossPackagePending` 要等
metadata clear 才清零；`crossPackageWbReq.valid` 没有禁止
`crossPackageMetaClearPending`，所以同一条 line 在 metadata clear 的同时再次进入
writeback。该顺序直接违反“单次写回完成后再清除/释放”的协议，属于已由波形证明的
功能错误。

另有一个独立的统计协议错误：日志中的

```text
[ADDRESS_STATS] status=FAIL valid=0 error=0x10 pending=0
```

`PackageAddressStats` 中 `0x10` 是 `errMalformedEvent`。普通架构访存统计在屏障
期间只由 `traffic_counting` 门控，而 BOOM 将 `active_packet_seq` 在 R_IC 离开
`fsm_check` 时压成 0；LSU 仍把这些提交事件送入地址统计，事件的
`packetSeq=0` 或已低于安全水位，因而被判为 malformed。这个问题解释地址统计
失败和部分统计口径异常，但单独不能证明 `parent[]` 数据错误。

## 证据链

| 层次 | 观察 | 结论 |
|---|---|---|
| 软件结果 | `reached=512` 但 `verified=0`、checksum 与参考差异两个数量级 | 图结构内存结果被破坏，而不是只少打印了一条统计记录 |
| 包/统计 | `packages allocated=257 completed=257 passed=257` | 包结果通道自洽，不能据此证明架构内存正确 |
| 跨包路径 | 日志 `cross_package_store seen=61248 resolved=61248` | shadow writeback 路径在本次运行中大量触发 |
| 波形 | `crossPackageWbReq_valid` 在 3107757；`wb.io_idx_valid` 在 3107791 变 0；3107793 又重新有效并同时出现 metadata clear | 同一 line 重复发起 writeback，且 clear 与第二次 writeback 重叠 |
| 波形 | 写回 C 通道参数为 `000` | 实际发送 TtoB，而不是失效该行所需的 TtoN |
| 地址统计 | `error=0x10` | malformed event，来自无效/过期 packet sequence |

时间来自 `test.vcd` 的 FST 单位；本次波形端点为 `0..3660949`，未做时间单位
换算为物理纳秒。

## 源码位置

### 1. 跨包 writeback 权限错误

`chipyard/generators/boom/src/main/scala/lsu/dcache.scala` 中：

```scala
crossPackageWbReq.bits.param := 0.U
```

而 `BoomWritebackUnit` 用该字段生成：

```scala
edge.Release(..., shrinkPermissions = req.param, data = ...)
```

TileLink 定义为：

```scala
TLPermissions.TtoB = 0.U
TLPermissions.TtoN = 1.U
```

同一路径随后通过 `crossPackageMetaClear` 写入 `ClientMetadata.onReset`。参数和
本地 metadata 的最终状态不一致。

### 2. 地址统计事件的无效 sequence

`boom/src/main/scala/exu/core.scala` 当前把 LSU 输入写成：

```scala
io.lsu.active_packet_seq := Mux(
  ic_master.io.packet_alloc_valid,
  ic_master.io.packet_alloc_seq,
  Mux(ic_master.io.debug_maincore_status === 2.U,
    ic_master.io.active_packet_seq, 0.U))
```

`boom/src/main/scala/lsu/lsu.scala` 的普通架构 load/store 地址事件使用该值：

```scala
io.dmem.address_stats_event(w).bits.packetSeq := io.core.active_packet_seq
```

但当前架构统计资格已改成只检查 `traffic_counting`，所以离开 `fsm_check` 后仍
可能产生 `packetSeq=0` 的事件。`PackageAddressStats.scala` 将
`packetSeq === 0` 或 `packetSeq <= safeWatermark` 判为 malformed。

## 修复方案

### A. 先修复一致性状态（必须）

将 shadow writeback 的权限参数改为：

```scala
crossPackageWbReq.bits.param := TLPermissions.TtoN
```

同时修复请求状态机，至少满足以下顺序：

1. `crossPackageWbReq.fire` 后保持 pending 和该行阻塞；
2. 等 `BoomWritebackUnit` 完成所有 ReleaseData beat，并收到 ReleaseAck；
3. writeback 完成后进入独立的 `meta_clear_pending` 状态；该状态下
   `crossPackageWbReq.valid` 必须为 0；
4. 只有在 writeback unit 返回 idle 后，才允许 `crossPackageMetaClear.fire`；
5. 清除 metadata 后释放该行的重试 Store，并清除 pending。

建议增加断言：shadow writeback 被接受时参数必须为 `TtoN`，metadata clear 只能
发生在 writeback 已经 idle 且没有新的 writeback 请求被接受的周期。不能把
`crossPackagePending` 提前清零，也不能用忽略 `ReleaseAck` 的固定延迟代替握手。

### B. 修复 packet sequence 生命周期（必须）

普通架构 load/store 的统计事件必须携带该条已提交访存自己的稳定 sequence，不能
在提交拍重新采样 R_IC 的瞬时状态。推荐实现：

1. 在架构提交/包边界处锁存每个 LDQ/STQ 项的 `packet_seq`；
2. 地址事件、架构总量和严格 completion 都使用该锁存值；
3. STOP 或 barrier close 后，已锁存且尚未提交的项目仍归入原包；
4. 新包/无包操作使用明确的 `packet_seq_valid`，不得把 0 当成合法包；
5. 只有所有 BOOM 架构提交和 LSU pending 都越过边界后，才推进
   `safePacketWatermark`。

不要简单把 `packetSeq=0` 的事件丢掉，否则地址统计会“通过”但与架构 Store/Load
总量再次不一致。

### C. 统一 STOP 边界（统计层）

checker STOP、BOOM traffic STOP 和地址统计 drain 应使用同一个完成握手。STOP 后
只排空已锁存事件，不重新打开 counting window。这样才能比较 61299/60587 或
60570 等数字；在 `verified=1` 和 checksum 恢复前，不应把这些数字作为性能结论。

## 排除项与风险

- 当前波形没有证明 LDQ/STQ 容量溢出；标准队列满路径会阻止分派，且本次没有
  queue-overwrite assertion。
- `boom_arch == boom_strict`，说明当前统计差异不是 BOOM 内部严格 Store 重复计数。
- 包结果 `257/257/257` 只证明结果握手计数一致，不能证明数据 cache coherence 正确。
- 现有 `stq_execute_head` 修复保留 token 一次性消费；本次日志没有再次触发该断言，
  不应通过放宽断言来处理本错误。

## 最小验证顺序

1. 同时修复 shadow writeback 的重复发起门控和 `TtoN` 权限，检查 `verified`、
   checksum 及包结果；
2. 再实现稳定 packet sequence 与 watermark/STOP 边界，检查 `ADDRESS_STATS
   valid=1,error=0`；
3. 检查 `boom_arch == boom_strict == checker_sum`；
4. 最后再比较 barrier 开关下的周期和流量。

本次仅完成源码和已有 FST/log 的静态分析，没有运行仿真，也没有生成 RTL。
