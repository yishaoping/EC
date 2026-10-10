# 屏障开启后架构 Store 统计骤减

## 现象

`Experiment/流量分析.typ` 的两段 GAPBS BFS 结果都为 512 nodes、8192 edges、
`boom_inst=649956`，但架构访存统计不同：

| 运行 | `boom_cycles` | `boom_arch.store` | `boom_arch.load` | 包数 |
| --- | ---: | ---: | ---: | ---: |
| 开屏障 | 905862 | 3713 | 723 | 32 |
| 未开屏障记录 | 1012405 | 60570 | 95062 | 279 |

Store 比例为 `60570 / 3713 = 16.31`。指令数和 BFS 校验一致，而统计差异只出现在
访存计数，说明是统计资格丢失，不是 benchmark 提前结束。两份记录仍需以同一个
`test.riscv`、同一 generated RTL 做最终 A/B；当前 `test.log` 对应的 generated RTL
中 `GH_REAL_BARRIER_ENABLED=false`。

## 根因链

原来 LSU 提交点使用：

```scala
arch_store_in_scope = arch_store && stq(idx).valid &&
  io.dmem.traffic_counting && io.dmem.traffic_check_state
```

`traffic_counting` 是性能统计窗口；`traffic_check_state` 则由
`BoomTile` 接成 `debug_maincore_status === 2.U`，只表示 R_IC 当前处于
`fsm_check`。真实屏障关闭当前包时，R_IC 进入 `fsm_postcheck`/cooling，
因此 `traffic_check_state` 暂时为 0。ROB 仍然提交普通 store，但
`arch_store_in_scope` 为 0，导致以下内容同时漏计：

* `boom_arch` store/load 计数；
* `boom_strict` 的普通 store token 与完成计数；
* `address_stats_event`。

这也解释了为什么原有 `boom_arch == boom_strict == checker_sum` 仍能 PASS：
三者共享了同一个错误门控。

## 包数差异的边界

包数问题也已定位到同一屏障改动。原来的 R_IC 屏障分支把 `ctrl` 设为 `3`：

```scala
ctrl := Mux(io.ic_exit_isax || barrierCloseRequest, 3.U, ...)
```

在 R_IC 状态机中 `ctrl=3` 是退出整个检查流程的控制码；`fsm_trans` 会进入
`fsm_reset`，而包分配条件是：

```scala
package_allocated = snapshot_accepted && !ctrl(0)
```

所以屏障关闭当前包时既没有走普通调度，也不会产生下一包的
`packet_alloc_valid`。这解释了开屏障记录只有 32 个包、而普通运行有 279 个包。

已修改 `rocket-chip/src/main/scala/r/R_IC.scala`：屏障关闭仍然进入
`fsm_postcheck`，但使用 `ctrl=0` 继续 `fsm_sch -> fsm_snap -> fsm_trans`，从而
按正常包边界分配新的 sequence；真实 `io.ic_exit_isax` 仍保持 `ctrl=3` 的会话退出
语义。

这次修正只改变屏障包边界控制，不改变 checker 的比较内容或 BOOM 的执行结果。
未生成 RTL，未运行仿真；修正后的包数和统计仍需固定输入后验证。

## 已实施的修正

在 `chipyard/generators/boom/src/main/scala/lsu/lsu.scala`：

```scala
arch_store_in_scope = arch_store && stq(idx).valid &&
  io.dmem.traffic_counting
arch_load_in_scope = arch_load && ldq(idx).valid &&
  io.dmem.traffic_counting
```

普通架构访存的统计窗口现在只由 `traffic_counting` 决定，屏障冷却期间不会丢掉
已提交的普通访问。`traffic_check_state` 仍用于请求阶段的 `traffic_check`，
因此 LR/SC/AMO 和包校验路径的原语义保持不变。`trafficSessionSeen` 也改为只看
`traffic_counting`，避免统计窗口内没有经过 `fsm_check` 时跳过最终一致性检查。

## 检查

已执行：

```text
scalac -Ystop-after:parser .../lsu.scala .../tile.scala       PASS
chipyard/.conda-env/bin/sbt -batch 'project boom' Compile/compile PASS
```

未生成 RTL，未运行仿真。修正后的开屏障/未开屏障数字需要在固定 benchmark、
固定 `test.riscv` 和同一 generated RTL 下重新运行后确认；本次用户约束禁止该步骤。
