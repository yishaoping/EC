# 包消费逻辑静态检查

检查范围：当前工作树中的 BOOM/Rocket 包数据、ARF/CPS、CDC、checker 消费和结果释放链路。
本检查只读源代码；没有运行仿真，也没有生成 RTL/硬件。源码已有的 Scala 编译结果为：
`sbt -batch 'project chipyard' compile` 通过。

## 逻辑链

```text
BOOM R_IC.package_allocated
  -> packet_seq_counter / checker_segment_id
  -> GH_BUF 数据包 + R_RSU ARF/CPS 合并流
  -> GHM 数据 AsyncQueue(256) / ARF AsyncQueue(8)
  -> GHM 序列比较、deq.fire、valid+seq 输出
  -> RocketTile packet_seq_high_watermark / LSL、BJL、RSU
  -> RocketCore package_check_active
  -> ARF/CSR/LSL 完成 -> result queue -> result CDC
  -> GHM BOOM 域 release -> R_IC.clear_ic_status
```

数据和 ARF/CPS 在 GHM 中是两个独立的异步队列。数据是包锚点；`dataConsumedSeq` 记录已经消费的数据序列，使同一序列的后续 ARF/CPS 可以在数据队列暂时为空时继续出队。

## 确认的高风险问题

### 0. 包分配与 data anchor 没有原子握手（本次 assert__assert_21 的直接上游）

`R_IC` 在 `snapshot_accepted` 时无条件分配新的 `packet_seq`，而 `GH_BUF`
只有在存在已提交 uop 且其 FIFO 非空时才产生 data `valid`。R_RSU 的 ARF/CPS
merge 又由 snapshot 的独立延迟脉冲启动。因此可以出现“新 sequence 已分配、
ARF/CPS 已开始发送、但 data 从未发送”的空数据包。保存波形在 FST
`105583`--`105595` 正好显示该顺序：sequence 7 分配后 data CDC
`enq_valid=0`，随后 ARF sequence 7 入队。

GHM 当前的 `arfAfterData` 规则要求先消费过同序列 data 才能释放后续 ARF；
所以空数据包会被永久卡住，而不是被当作合法的 zero-data package 完成。该
问题必须在协议层处理：要么只在 data `enq.fire`/显式空包标记后启动 ARF，要么
为 zero-data package 增加独立的 anchor/完成语义；单纯扩大 FIFO 不能解决。

### 1. 数据 ready 是三路 OR，可能在目标 FIFO 不可接收时消费整包

路径：

- `rocket/RocketCore.scala:1440`：`packet_cdc_ready := rsu_slave.cdc_ready | lsl.cdc_ready | bjl_cdc_ready`。
- `tile/RocketTile.scala:294`：该信号成为 GHE event bit 4。
- `guardiancouncil/GHM.scala:192,207`：bit 4 直接驱动数据 CDC `deq.ready`。
- `r/R_LSL.scala:269`、`r/R_BJL.scala:100`：两路 ready 只分别表示本地 FIFO 未接近满；RSU 的 `cdc_ready` 在 `r/R_RSUSL.scala:271` 还是一次性包处理脉冲。
- `r/GH_FIFO.scala:85-92,164-171`：内部入队没有向上游暴露 ready，满时只是不执行写入。

因此，若 LSL 已 near-full、BJL 仍 ready，或仅因为 RSU 的 ARF/CPS 脉冲使 OR 结果为 1，GHM 仍会取走包含 LSL/BJL 项的数据向量。目标 FIFO 不能接收的槽位没有回滚，数据包会被静默丢弃。这个问题与 GHM 的 CDC 满反压不同，当前 `core.io.big_hang` 不能修复 checker 内部三路 OR 的错误。

建议：把数据包按槽位类型与目标队列容量建立真正的 ready/fire；至少不能把 RSU 的脉冲作为数据 ready，也不能用不同消费队列的简单 OR 代表整个向量可接收。

### 2. R_RSU 在最后一个 ARF/CPS 项上没有遵守满反压

正常合并路径 `r/R_RSU.scala:155-158` 中，`merge_counter` 在 `io.big_hang` 时冻结，但 `merging` 的结束条件没有检查 `!io.big_hang`：当 `merge_counter === 32` 且 `merge_cdc_counter === 1` 时，无条件清零 `merging`。与此同时 `r/R_RSU.scala:227-228` 又要求 `!io.big_hang` 才给出 ARF/ECP 路由目的地。

若 ARF CDC 已满：

```text
big_hang = 1
  -> 最后项没有目的地，GHM 不入队
  -> merge_counter 保持 32
  -> merging 仍被无条件清零
  -> 最后一个 PC/ARF 项永久丢失
```

特权路径 `r/R_RSU.scala:170-174` 对 `merging_priv`、`csr_merge_counter === 7` 存在同样的结束条件问题。ARF CDC 深度只有 8，而一次合并远大于 8 项，所以该条件不是理论上不可达的边界。

另外，`rsu_merging_valid`（`r/R_RSU.scala:257`）不是一个与 CDC `fire` 绑定的 ready/valid 握手，只是内部计数器相位脉冲；当前 GHM 主要靠目的地字段隐式判断 ARF 有效，后续若直接使用该脉冲仍会在反压相位产生无消费确认的脉冲。建议合并状态只能在该项的真实 `enq.fire` 后推进/结束；至少要把 `!io.big_hang` 纳入结束条件，并冻结所有推进计数器。

## 其他高/中风险问题

### 3. 独立 CDC 队列的“空队列”不能证明另一条流没有迟到的旧项

`GHM.scala:202-203` 在另一队列无 valid 时直接放行数据或 ARF。若数据队列暂时看不到 ARF，先消费到序列 `N+1`，随后迟到的序列 `N` ARF 会被 `dataConsumedSeq`/`arfAfterData` 当作旧片段排出；RocketTile `RocketTile.scala:204-210` 又拒绝小于 watermark 的 ARF。结果是该 ARF 被 GHM 消费但 checker 永远看不到。

这要求生产端严格保证同一 checker 的 ARF 尾项先于下一序列数据到达；代码本身没有跨 CDC 的保留/确认机制。若该假设被破坏，RocketCore 的 ARF timeout（`RocketCore.scala:1305-1308`）也可能无法启动，因为 GHM 的 `cdc_empty` 仍被另一条流卡住。

### 4. `package_result_waiting` 时仍可接收新包

`RocketCore.scala:1282-1284` 的 `new_package` 只排除 `package_result_outstanding`，不排除 `package_result_waiting`。当结果队列暂满时，旧结果保存在 waiting 寄存器；此时新序列仍可覆盖 `package_seq_reg` 并启动新检查。旧 waiting 结果随后入队时，新的完成事件可能被 `package_result_fire` 分支清掉而没有入队，导致结果顺序/资源释放失配。

建议：新包准入同时要求 `!package_result_waiting`；或者把 waiting 结果和新包状态放入一个严格有序的结果 FIFO。

当前修订已处理该风险：`RocketCore` 在 active/result-owned 期间把较新的
sequence 保存到单项 pending 寄存器，`R_IC` 还以 per-checker ownership bit
阻止同一 checker 被重新分配。这样 sequence 6 不会再通过覆盖 sequence 5
来取消后者；旧包先完成/有界取消并完成 result handoff，pending 包才准入。

### 5. 会话完成位可能早于 checker 本地 LSL 入队阶段

`GHM.scala:379-382` 只用 `packet_ingress_empty` 置位 `checkerSessionDone`。数据 dequeue 后，RocketCore/R_LSL 仍有寄存器化的 packet 入队阶段；RocketCore 自身在 `RocketCore.scala:1301-1304` 使用两次连续 empty 并结合 `lsl.io.if_empty`，而 GHM 会话完成路径没有同样的本地排空确认。因此软件可见 FINISH 可能早于最后数据真正进入/离开 LSL。

### 6. 旧 22-bit 控制 CDC 仍有脉冲丢失语义

`GHM.scala:267-276` 的 `u_l2b_ctrl_cdc.enq.valid` 直接由 `clear_ic_status`、`ghe_revent`、`ghe_event` 脉冲驱动，没有 pending/ready 保持。新会话控制和结果释放路径已降低其关键性，但任何仍读取该旧控制通道的诊断/兼容逻辑仍可能漏事件。

## 条件性问题

- `GHM.scala:164-184,249` 使用 `Mux1H` 汇聚多个 big core。当前 `GH_NUM_BIG_CORES=1`，若启用多 big core 且两个 big core 同时指向同一 checker，数据/ARF payload 没有仲裁，可能混合。
- `GHM.scala:202-203,258-260` 和 RocketTile 的序列比较使用普通 `<=`；32 位序列回绕后会误判新旧。序列 0 虽被 RocketTile 拒绝，但 GHM 没有在入队侧过滤，若产生零序列会先消费再丢弃。
- `GHM.scala:231-234` 的 producer-empty 只同步 big core 0 的 bit 31；多 big core 配置下不能证明所有生产端都为空。

## 结论

当前代码已具备“数据消费后继续消费同序列 ARF/CPS”的基本机制，但静态检查不能证明包无损。至少问题 1 和问题 2 会在满/近满边界造成实际丢包；问题 3 和问题 4 会在跨队列延迟或结果队列背压下破坏序列/结果协议。应先修复真正的 ready/fire 和 R_RSU 最后一项状态推进，再做后续验证。
