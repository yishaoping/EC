# 259 包运行：`ADDRESS_STATS error=0x10` 根因

## 结论

本次不是第 259 个包的 checker 结果失败。日志显示 `259/259/259`：分配、完成、PASS 全部平衡。失败来自 BOOM 地址统计窗口的顺序约束：checker 的安全水位已经推进到包 `0x62`，但 BOOM 仍有该包的架构 store 尚未提交。

该 store 提交事件随后携带 `packetSeq=0x62` 进入 `PackageAddressStats`，而事件入队时保存的 `safeWatermark=0x62`。处理阶段计算：

```scala
processEvent.packetSeq === 0.U ||
processEvent.packetSeq <= processEvent.safeWatermark ||
processCrossesLine
```

第二项成立，产生错误位 4，即 `error=0x10`。

## 波形事件表

波形文件：
`chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd`

| FST 时间 | 事件 | 解释 |
| ---: | --- | --- |
| 1062075 | `resultAccepted_2=1`，checker 结果序列 `0x62` | 包 `0x62` 的 PASS 被 DCache 接受 |
| 1062075 | `newSafePacketWatermark=0x62`，`safeAdvance=1` | checker 连续 PASS 水位推进 |
| 1062077 | `safePacketWatermark` 已更新为 `0x62` | 该值通过 `addressStats.io.safeWatermark` 使用 |
| 1062087 | LSU lane 2 `address_stats_event.valid=1`，`isStore=1`，`packetSeq=0x62` | 包 `0x62` 的架构 store 此时才提交 |
| 1062089 | LSU lane 0 再提交一个 `packetSeq=0x62` 的 store | 同一包还有尾部提交事件 |
| 1062091 | `processValid=1`，`processEvent.packetSeq=0x62`，`processEvent.safeWatermark=0x62`，`processMalformed=1` | `0x62 <= 0x62`，触发 malformed |
| 1062091 | `io_error=0x10`，`io_statsValid=0` | 错误位锁存 |
| 1062093 | `errorReg=0x10`，地址统计队列被清空 | `stopWithError` 终止地址统计模块 |

首个 malformed 事件的地址低 6 位为 `0x02`，size 编码为 `1`（2 字节），没有跨 64B cache line。因此本次不是 `processCrossesLine`，也不是 `packetSeq==0`。

## 源码信号链

1. checker 结果在 `dcache.scala:1130-1170` 形成 `resultAccepted`，并更新 `completedNext/passedNext`。
2. `dcache.scala:1196-1206` 查找连续 PASS 序列并计算 `newSafePacketWatermark`；`dcache.scala:1241` 写回 `safePacketWatermark`。
3. `dcache.scala:1213-1220` 把同一个 checker 水位连接到 `PackageAddressStats.io.safeWatermark`。
4. LSU 在地址翻译完成时把 `io.core.active_packet_seq` 锁存到 LDQ/STQ（`lsu.scala:1092-1135`）。该 tag 在提交时仍为 `0x62`。
5. LSU 架构提交条件位于 `lsu.scala:1834-1840`；cacheable store 在 `lsu.scala:1848-1858` 产生地址事件，并携带 LSQ 中保存的 `packet_seq`。
6. `PackageAddressStats` 在 `PackageAddressStats.scala:595-600` 同时保存事件和当时水位；`240-247` 的 `processMalformed` 判定在 `812-820` 形成错误位，在 `868-873` 清空运行状态。

## 根因分层

- **直接症状，已证实**：`processMalformed=1`，错误位 4，最终 `ADDRESS_STATS status=FAIL valid=0 error=0x10`。
- **立即阻塞条件，已证实**：事件 `packetSeq=0x62` 与保存水位 `0x62` 满足 `<=`。
- **上游根因，已证实**：checker PASS 水位和 BOOM 架构提交不是同一个有序时钟点；安全水位只表示 checker 已完成，不表示该包在 BOOM LSU 中已经没有待提交访问。
- **下游放大效应，已证实**：首个 malformed 使 `stopWithError` 清空地址统计队列并保持 `statsValid=false`，后续地址统计不再恢复，最终报告必然 FAIL。

## 被排除的原因

- 包结果 CDC/队列丢失：日志 `allocated=259 completed=259 passed=259`，且波形结果通道正常握手。
- 包分配冲突：没有 `allocationCollision` 或结果丢弃迹象。
- 地址跨 cache line：首个事件地址偏移为 2、访问 2 字节，条件不成立。
- 零序列归属：首个失败事件的序列明确为 `0x62`。

## 修复方向

优先修复地址统计的安全判定语义，不要屏蔽错误位，也不要改包计数：

1. **最小改动**：把地址事件的旧包判定从 `packetSeq <= event.safeWatermark` 改为 `packetSeq < event.safeWatermark`。同包在 checker PASS 后才到达的合法尾部提交可以被统计；真正早于已安全水位的旧事件仍报错。
2. **更强的架构修复**：由 LSU 导出“BOOM 已提交到某包”的单调水位，地址统计使用 `min(checkerSafeWatermark, boomCommitWatermark)`，从根上把 checker 完成与 BOOM 提交解耦。该方案需要新增跨模块接口，验证范围更大。

当前证据支持先采用方案 1 做窄修复，再用下一次波形确认 `ADDRESS_STATS valid=1 error=0`，并复核 `boom_arch/boom_strict/checker_sum` 与 `259/259/259` 不变。

## 验证边界

本记录只读取现有源码、日志和波形；没有生成 RTL，也没有运行仿真。波形时间为 FST 时间，日志中的 Verilator 时间通常是其两倍，不能直接混用。
