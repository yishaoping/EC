# 已关闭包的迟到封口请求错误保持退休

状态：V6 完整反例和原模型窄探针已确认根因。V10 增加实际 owner 门控，整核回归中。

Sv39 候选程序在 V6 正常整核 676834 周期成功退出。Fault8 完成唯一恢复和
16 次真实虚实地址读取，随后输出 `PALIMPSEST_SV39_RESULT`，在 HTIF fromhost
轮询期间失去 Main 退休进度并触发原 watchdog。不能将已完成的译址读当作完整
程序通过，也不能修改 watchdog 或绕开 HTIF 输出。

`AI/TMP/singlecore_checker_20261122_082540/sv39_watchdog_probe_v6/`
复用原 V6 生成库，只读观察证明 capacityBoundaryHold 持续为高；恢复、重基、
I/O 和 RSU 均空闲，缓存最终排空。进一步的 `sv39_capacity_owner_probe_v6/`
逐 eval 记录 owner/close 条件的变化，未写任何硬件状态。以下 tick 为完整顶层
周期；信号原日志除 tick 外按十六进制编码，表中 Seq 转为十进制。

| tick | producer/open | protected | activeSeq | closeSeq | capacity | 解释 |
|---|---|---|---|---|---|---|
| 559753 | 0 | 0 | 35 | 0 | 0 | 检查会话结束，保留最后分配编号 |
| 559794 | 0 | 0 | 35 | 35 | 0 | 迟到 L2 封口请求到达，旧编号匹配 |
| 559795 | 0 | 0 | 35 | 35 | start=1 | 无开放包却启动容量退休保持，first bad |
| 559796 | 0 | 0 | 35 | 35 | closing=1 | 锁存 capacitySeq=35 |
| 563384 | 0 | 0 | 35 | 35 | closing=1 | bank 请求已退出，local capacityClosing 仍维持 |

直接症状为 Main watchdog，即时阻塞为 capacityBoundaryHold。已证明的上游触发
是 `barrierCloseForActivePackage` 仅比较 retained active_packet_seq 和请求 Seq，
未检查 producer 是否仍开放。下游放大为 capacityClosing 只等待新分配编号推进，
已结束会话不会分配 successor，因此它自己持续 forceClose/退休保持。原 R_IC 已
有 `barrierAlreadyClosed` 的幂等 ACK，错误不在需要丢弃 L2 请求或改写请求编号。

V10 的 Core 在 `barrierCloseForActivePackage` 汇合既有
`ic_master.io.traffic_package_open`。同拍真实 owner 才可启动 capacityStart 和
相应 dispatch 保持；迟到旧请求继续走原 R_IC ACK。现有容量状态、Seq、RSU
传输、L2/History/Probe/外写 owner 全部保留。无新增寄存器、队列、FSM 或接口。
该来源位在 R_IC 已由 producer_open 与 protected process 共同定义，不能用
非零 activeSeq 替代它。

`capacity_closed_owner_candidate_v10/design.json` 保存同次事件表、first bad、
设计和验收条件；其目录内有唯一生产差异及完整前后源码哈希。V9 的 RSU 排空
反馈修复与此缺陷不同，生成来源分别保护；实际最终验收使用 V10。
必须重新生成完整 Core，并用同一 Sv39 ELF 验收正常/Fault8 完整程序及每条真实
映射读，随后通过正常/Fault8/Seq16 的异常/MMIO回归。当前不得标完整 PASS。
