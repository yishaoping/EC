
= R_IC FSM 死锁分析与修复报告

== 问题概述

在 RISC-V 多核冗余执行系统（Boom 大核 + 4 个 checker 小核）的 Verilator 仿真中，`core.scala` 中的看门狗断言触发失败：

```scala
assert(!little_status2(16), "little core 2 has hung")
```

表现为 `little_status2` 计数器在 `ic_status(2)` 持续为 1 的情况下溢出（达到 65536 周期）。

== 信号路径追踪

=== 关键信号链

#figure(
  table(
    columns: 3,
    [*层级*], [*信号*], [*文件:行号*],
    [计数器], [`little_status2`], [core.scala:2033],
    [清零条件], [`!ic_master.io.ic_status(2).asBool`], [core.scala:2037],
    [R_IC 输出], [`ic_status(2)` 寄存器], [R_IC.scala:82],
    [唯一清零路径], [`clear_ic_status(2)`], [R_IC.scala:245],
    [外部清零源], [`clear_ic_status_tomain`], [GHM.scala:216],
    [CDC 源], [`b_rctrl(2)(7)`], [GHM.scala:188],
    [小核发送], [Checker Core 2 完成信号], [小核→CDC FIFO→GHM],
  ),
  caption: [信号路径层级表]
)

=== `little_status2` 看门狗机制

```scala
// core.scala
val little_status2 = freechips.rocketchip.util.WideCounter(32)  // 32位自由计数器

when(!ic_master.io.ic_status(2).asBool) {
    little_status2 := 0.U    // ic_status(2)=0 时复位
}
// 否则每周期自增

assert(!little_status2(16), "little core 2 has hung")  // 第16位=1 → 65536周期 → 断言失败
```

== 根因分析：`ic_status` 寄存器饱和死锁

=== R_IC FSM 状态机流程

#figure(
  table(
    columns: 2,
    [*状态*], [*功能*],
    [`fsm_reset`], [初始化，等待 ISAX_Go],
    [`fsm_presch`], [预调度，等待 `ic_run_isax`],
    [`fsm_sch`], [FPS 调度器选择可用 checker 核],
    [`fsm_cooling`], [冷却等待 RSU 不忙],
    [`fsm_snap`], [设置 `ic_status(crnt_target)=1`，捕获快照],
    [`fsm_trans`], [快照传输过渡],
    [`fsm_check`], [检查模式：累计指令计数],
    [`fsm_postcheck`], [检查完成：标记 counter，选择下一状态],
  ),
  caption: [R_IC FSM 状态说明]
)

=== 核心缺陷

在 `fsm_snap` 状态中，`ic_status` 被置 1 后，#strong[FSM 内部没有任何状态负责自动清零]：

```scala
// R_IC.scala fsm_snap 状态
ic_status(i) := Mux(clear_ic_status(i).asBool, 0.U,           // ① 仅靠外部 CDC 清零
                Mux((crnt_target === i.U) && (ctrl(0) === 0.U), 1.U, ic_status(i)))  // ② 置1后永久保持
```

`clear_ic_status` 信号需要经过完整链路：Checker 小核 → CDC FIFO → GHM → BundleBridge → BoomTile → core.scala → R_IC。延迟大且可能丢失。

=== test.c 中 ecall 加速了饱和

测试程序有 3 个 `ecall`，每次触发 `mode_switch`，导致 FSM 走 `fsm_check → fsm_postcheck → ... → fsm_sch` 完整循环：

#figure(
  table(
    columns: 7,
    [*轮次*], [*触发*], [*调度核*], [`1`], [`2`], [`3`], [`4`],
    [初始], [ISAX_Go], [-], [0], [0], [0], [0],
    [第1轮], [fsm_snap], [core1], [*1*], [0], [0], [0],
    [ecall#1], [mode_switch], [core2], [1], [*1*], [0], [0],
    [ecall#2], [mode_switch], [core3], [1], [1], [*1*], [0],
    [ecall#3], [mode_switch], [core4], [1], [1], [1], [*1*],
    [第5轮], [调度], [*无核可用*], [1], [1], [1], [1],
  ),
  caption: [`ic_status` 累积饱和过程（`GH_NUM_CORES=5`，索引 0=大核，1-4=checker 核）]
)

=== 死锁后果

当全部 4 个 checker 核的 `ic_status` 都为 1 后：
+ `fsm_sch` 中 FPS 调度器 `nocore_available = 1`
+ FSM #strong[永久卡在 `fsm_sch`] 状态
+ `ic_status(2)` 始终为 1 → `little_status2` 持续递增 → #strong[65536 周期后断言失败]

== 修复方案

=== 修改位置

文件：`chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala`\
状态：`fsm_postcheck`（第 245 行）

=== 修改内容

```diff
 for (i <- 0 to params.totalnumber_of_cores - 1) {
-    ic_status(i) := Mux(clear_ic_status(i).asBool, 0.U,  ic_status(i))
+    ic_status(i) := Mux(clear_ic_status(i).asBool, 0.U,  Mux((crnt_target === i.U), 0.U, ic_status(i)))
     ic_counter(i) := ...
 }
```

=== 修复原理

`fsm_postcheck` 是检查轮次 #strong[完成] 的状态。在此状态下：

1. *外部清零保留*：`clear_ic_status(i)` 优先级最高
2. *新增内部自动清零*：`crnt_target === i` 时清零，使刚完成检查的核重新变为可用
3. *其他位保持*：不在当前目标的核保持原有状态

=== 修复效果对比

#figure(
  table(
    columns: 2,
    [*修复前*], [*修复后*],
    [`ic_status` 仅靠外部 CDC 清零], [`ic_status` 在 `fsm_postcheck` 自动清零],
    [4 核逐步饱和 → FSM 死锁], [每轮完成后当前核立即释放],
    [`little_status2` 溢出 → assert FAIL], [正常轮转，断言通过],
  ),
  caption: [修复效果对比]
)

== 后续问题：后两个小核未做检查

=== 波形关键信号

+ `debug_maincore_status = 3` → `!if_correct_process` → RoCC(GHE)加速器已挂起大核流水线
+ `checker_mode = 0` → checker 核未被激活

=== 因果链

#figure(
  table(
    columns: 2,
    [*步骤*], [*事件*],
    [1], [`ic_status` 全部饱和 → FSM 卡在 `fsm_sch`],
    [2], [`ic_stall=1 → rob.io.gh_stall=1 → ROB 停摆`],
    [3], [`无指令提交 → ic_incr=0 → 阈值永不触发`],
    [4], [`GHE 等待快照完成 → if_correct_process=0`],
    [5], [`GHM 无法向小核发送检查包 → checker_mode=0`],
    [6], [`后两个小核（core3、core4）始终未被调度`],
  ),
  caption: [小核未检查的因果链]
)

=== FPS 调度器的 Sticky 机制

`GHT_SCH_ANYAVILIABLE` 调度器有 "粘滞" 特性：

```scala
change_dest := ((io.core_na(current_dest-1.U) === 1.U) && !nocore_available.asBool)
```

`current_dest` 寄存器指向的核只要 `ic_status=0`（可用），就保持选中不变。只有当前核变忙时才会推进到下一个核。

因此修复后 FPS 调度器能正确实现 round-robin：1→2→3→4→1→...

== 涉及的源文件

- `chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala` — R_IC FSM 主体，修复位置
- `chipyard/generators/boom/src/main/scala/exu/core.scala` — 看门狗断言 `little_status2`
- `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala` — `clear_ic_status_tomain` CDC 路径
- `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/ght_sch.scala` — FPS 调度器
- `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala` — 全局参数 (`GH_NUM_CORES=5`, `GH_TOTAL_INSTS=3970`)
- `/home/gzh/EC/Software/test/test.c` — 测试程序（含 3 个 ecall）

== 总结

根本原因是 R_IC FSM 中的 `ic_status` 寄存器缺乏内部自动清零机制，仅依赖外部异步 CDC 信号清零。当测试程序中的 `ecall` 触发多次 `mode_switch` 后，所有 checker 核的 `ic_status` 累积饱和，导致 FSM 调度器死锁，最终看门狗计数器溢出触发断言。

修复方法：在 `fsm_postcheck` 状态中对当前完成检查的 `crnt_target` 对应的 `ic_status` 位进行自动清零，恢复正常的 round-robin 调度。
