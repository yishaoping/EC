# Palimpsest Seq 8 故障注入

## 配置与正常数据通路

`PalimpsestFault8Config` 继承 `v1Config`，在 Chisel elaboration 令 `PalimpsestFaultSeq = BigInt(8)`。默认值为 0，`PalimpsestAdditionalFaultSeqs` 默认为空。RocketCore 取这两个配置键，构造 `R_RSUSLParams(xLen, 32, ...)` 并交给每个 Rocket Checker 的 `R_RSUSL`。配置本身未指定 hart。Seq 8 归当次 R_IC 调度实际选中的 Checker。Seq 是检查包序号，覆盖从本包 CPS 到 ECP 的一段动态退休指令。槽位通过带 Seq 的 result CDC 回执释放。 [PalimpsestConfigs.scala](/data1/gzh/EC/chipyard/generators/chipyard/src/main/scala/config/PalimpsestConfigs.scala:11) · [RocketCore.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala:841) · [R_IC.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala:273)

- BOOM 在退休时更新架构 FARF 镜像。包边界的 R_RSU 延迟 capture 冻结这份镜像。发送给旧包 owner 的 ECP 把浮点 64 位放在 128 位 ARF/FARF payload 的高半，包内索引 0 对应架构浮点寄存器 `f0`（ABI 名称 `ft0`）。Checker 将此半字写入按寄存器索引寻址的 `farfs_ss_ECP`。同一边界也可以给新包 owner 发送 CPS。 [BOOM FARF](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/exu/core.scala:2067) · [R_RSU capture](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/r/R_RSU.scala:105) · [ECP 写入](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/r/R_RSUSL.scala:290)
- Checker FPU 的真实寄存器存储采用 HardFloat recoded 表示。FPU 导出 `ieee(regfile(i))` 为 64 位架构位串，RocketCore 送至 `core_farfs_in(i)`。检查启动沿锁存 Checker 本地的 32 个整数和 32 个浮点寄存器。真实比较逐项对整数和浮点取位串不等，整数 x0 固定为零，浮点 f0 正常比较。此处依 IEEE-754 编码位比较，结果与浮点指令数值比较的 NaN、符号零语义无关。 [FPU.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/tile/FPU.scala:807) · [RocketCore 连接](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala:1126) · [R_RSUSL 比较](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/r/R_RSUSL.scala:455)

## 真实注入代码

下列两段取自 `R_RSUSL.scala`。第二段位于现有 compare FSM 的正常分支内，优先级低于 package clear/start、compare abort 和 ECP frame start。

```scala
private val faultSeqs = (Seq(params.faultSeq) ++ params.additionalFaultSeqs).filter(_ != 0)
require(faultSeqs.distinct.size == faultSeqs.size &&
  faultSeqs.forall(s => s > 0 && s < (BigInt(1) << GH_GlobalParams.GH_PACKET_SEQ_BITS)))
val injectedOnce = faultSeqs.map(_ => RegInit(false.B))
val injectF0 = injectedOnce.zip(faultSeqs).map { case (used, seq) =>
  !used && io.package_seq === seq.U
}.reduceOption(_ || _).getOrElse(false.B)
```

```scala
when (io.compare_start && !do_check.asBool && !compare_done_valid_reg) {
  do_check := 1.U
  checking_counter := 0.U
  checking_counter_memdelay := 0.U
  compare_reads_issued := false.B
  compare_read_valid := false.B
  compare_error_accum := false.B
  compare_seq_reg := io.package_seq
  compare_epoch_reg := ecp_frame_epoch
  for (i <- 0 until params.numARFS) {
    checker_arfs_snapshot(i) := (if (i == 0) 0.U else io.core_arfs_in(i))
    checker_farfs_snapshot(i) := (if (i == 0) Mux(injectF0, io.core_farfs_in(i) ^ 1.U, io.core_farfs_in(i)) else io.core_farfs_in(i))
  }
  for ((used, seq) <- injectedOnce.zip(faultSeqs)) {
    when (io.package_seq === seq.U) { used := true.B }
  }
}
```

数据修改发生在 **Checker 比较侧快照的写入**。XOR 只翻转该 64 位快照的 bit 0。主核 ECP、SCP、History 和主核、Checker 的真实寄存器文件使用各自的数据通路。流水线读寄存器仍读真实值。生成的正常 RTL 为 `checker_farfs_snapshot_0 <= io_core_farfs_in_0;`，编译期消除注入寄存器、Seq8 等值比较、专用 Mux 和附加扇出。Fault8 RTL 每个物理 Checker 有一位 `injectedOnce_0`、Seq 等值条件及 bit 0 XOR。 [注入条件](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/r/R_RSUSL.scala:335) · [锁存点](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/r/R_RSUSL.scala:491) · [正常生成 RTL](/data1/gzh/EC/AI/TMP/ec-test-20261125/probe-publication/v1Config/generated-src/chipyard.TestHarness.v1Config/gen-collateral/R_RSUSL.sv:595) · [Fault8 生成 RTL](/data1/gzh/EC/AI/TMP/ec-test-20261125/probe-publication/PalimpsestFault8Config/generated-src/chipyard.TestHarness.PalimpsestFault8Config/gen-collateral/R_RSUSL.sv:598)

## 触发时序与恢复

1. RocketCore 要求活跃包、匹配 Seq 的完整 ECP、有效的生产端 seal、CDC ingress 排空、LSL quiescent、架构状态连续两拍稳定，且没有传输错误。满足条件才驱动 `compare_start`。 `injectF0` 组合条件可在等待比较期间为高，实际翻位与 once 锁存仅发生在启动沿。
2. 启动后第一条 `compare_issue` 访问索引 0 的 ECP 同步读口。读口的返回拍由 `compare_read_valid` 和延时索引对齐，`arf_mismatch` 逐项比较并送入累加器。最后索引 31 的读返回后，汇总错误与 Seq、ECP epoch 一同进入 `compare_done_*`。RocketCore 核对这些 owner 字段，并与 ELU、CSR 错误汇总。
3. 包完成后，正常状态选择逻辑把已汇总的错误编码为 FAIL。Rocket result queue、GHM result CDC 和 BOOM DCache 接收同一个 Seq。活 owner 的失败进入 `rollbackError`，控制器定位并 pin 该包 SCP，安装 EVT，等待 Cache／LSU、Checker owner 和 RSU 排空，再执行恢复及重启。Cache 历史查询可以在后续 refill 或 load 重试发生时命中。单个注入能覆盖哪些内存版本路径由恢复地址和实际命中记录决定。 [Checker 条件](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala:1472) · [Checker 结果](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala:1557) · [GHM result CDC](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala:589) · [BOOM 错误请求](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/lsu/dcache.scala:3033) · [恢复 FSM](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/exu/PalimpsestRecovery.scala:333)

一次性状态属于 **每个 Checker、每个配置 Seq**，由硬件 reset 清零。普通 rollback 不复用数值 Seq，R_IC 在恢复后继续使用更大的编号。物理重基可重新使用 Seq 8，原 Checker 的 once 位仍为 1。若新的 Seq 8 由另一颗尚未注入的 Checker 持有，该 Checker 可以再触发一次。给定 EC-Test 运行远低于 Fault8 继承的生产重基阈值。原仓库的 Fault40Seq41 使用针对 hart 的配置，把刻意重基时的注入限制在指定 Checker。 [R_IC 恢复与重基](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala:497) · [故障及重基组合配置](/data1/gzh/EC/chipyard/generators/chipyard/src/main/scala/config/PalimpsestConfigs.scala:32)

## 波形与验证边界

本轮传输修复候选的 Fault8 整核波形中，实际 Seq 8 owner 为 hart 4。FST 每个 BOOM 周期两点，该段每个 Checker 周期四点。

| FST 点 | 实测值 |
|---:|---|
| 174901 | `compare_start` 有效。 |
| 174905 | 锁存 Seq 8，`injectedOnce_0` 第一次置位，真实 `f0` 为 `0x3ff8000000000000`（1.5），比较快照为 `0x3ff8000000000001`。 |
| 174909 | 第 0 项读回进入真实比较器，`arf_mismatch` 置位。 |
| 174913 | 比较移至第 1 项，`arf_mismatch` 回落。 |
| 175037 | `compare_done_error_reg` 置位。 |

Seq 8 的 SCP PC 为 `0x80000944`，对应 `update_lines` 的字节 store。结果日志依次记录 FAIL、EVT、恢复和同 PC 重启，epoch 由 0 到 1。该候选后续在独立的冷地址查询问题上触发 watchdog。 [比较波形](../../TMP/ec-test-20261125/cps-anchor/fault8-first-compare.trace) · [Fault8 候选日志](../../TMP/ec-test-20261125/cps-anchor/PalimpsestFault8Config/ec-fault8/run.log)

最终 `probe-publication` 整核与最新版 ELF 的完整波形中，四个 Checker 合计只观察到一次 `injectedOnce_0` 上升，持有者为 hart 4。FST 175749 启动比较，175753 锁存 Seq 8 并把 `0x3ff8000000000000` 的 bit 0 翻为 1，175757 比较器报 mismatch，175885 汇总错误。SCP 和重启 PC 均为 `0x80000964`，对应 `update_lines` 的字节 store。FAIL 后 EVT 标记范围 8–9，epoch 进入 1，检查包从 Seq 10 接续。程序在 422873 周期退出 0，126 个 Checker PASS、1 个 FAIL，逐轮 `f0` 与最终 3.5 均通过。 [波形提取](../../TMP/ec-test-20261125/probe-publication/acceptance/s8-compare.trace) · [整核执行](../../TMP/ec-test-20261125/probe-publication/PalimpsestFault8Config/ec-fault8/run.log:15) · [反汇编](/data1/gzh/EC/Software/Test/test.dump:900)

当前实现能检验第零项真实比较、错误汇总、跨域传递、回滚和重新执行。它模拟比较输入发生错误。真实架构寄存器损坏、实体 SRAM 损坏和错误数据已向外传播的场景需要能改变相应真实状态的独立测试。`store-replay` 的 S8 首次重执行所跟踪的历史查询主要未命中。最终版指定旧版本的命中、选择与恢复数据由 Hierarchy 的定向断言验证。Fault18 沿用相同的比较输入注入，选择包含设备效果的包，严格计分验证了 journal 重放区间内原始物理 TL A 恰好一次。 [Hierarchy 定向测试](../../TMP/ec-test-20261125/probe-publication/components/hierarchy.run.log) · [Fault18 设备计分](../../TMP/ec-test-20261125/probe-publication/acceptance/historical-io.log)
