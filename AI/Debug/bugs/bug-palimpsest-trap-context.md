# PALIMPSEST 异常执行上下文随 SCP 恢复

BOOM 的系统调用边界标记由 handler 状态、pending 和 age 三个位组成。旧实现只保存 CSR。回滚跨越 trap 入口或 MRET 时，若沿用旧边界状态，重执行会漏发或重复发出 Checker 边界。恢复分两处收敛。

- `PalimpsestTrapTracker` 将原三个状态位作为 SCP 字段，在 `core.scala` 恢复 CSR 时同步装入。stop 限制旧路径停止推进。恢复后的状态由检查点决定。
- `R_IC` 在停核时清除临时 `boundary_priv`。`R_RSU` 在普通快照入口也写入 `crt_mode`，避免复用已废弃模式。

`AI/TMP/singlecore_rtl_20261121_171154/trap_context05/run_precise_exception.log` 的 `checker_trap_context_restored` 用生产 tracker 和 SCP RAM 覆盖两个回滚方向并检查 pending 只消费一次。Scala 生成和 C++ 激励分别见同目录的 `emit.log` 和 `fixtures.sha256`。验证矩阵记录同一源码版本的完整回归。整核 PTW、异常和未结 I/O 并发仍需闭环证据。
