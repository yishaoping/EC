# Checker 包在 COPY 前取消后仍执行回放

状态：根因已证实；修复正在整核编译和回归，尚未通过验收。

旧版本证据：`AI/TMP/singlecore_rtl_20261121_171154/seq_cancel_trace22/`。
模型来自同归档 `sourcec_full_PalimpsestSeqRebaseTestConfig`；激励为
`workload_compact_probe/palimpsest.riscv`，各输入 SHA-256 见 `run.inputs.sha256`。
窄探针只在 eval 后读取状态，不驱动任何 RTL。

探针时间是 emulator 的 `trace_count`，对应系统时钟周期；Rocket 分频后的
退休周期号不能与它直接等同。以下时间只属于该次运行。

| 系统周期 | 观测与结论 |
|---|---|
| 233680 | hart 2 捕获 Seq16，`package_start_pending=1`，R_ICSL 仍为 nonchecking。 |
| 233748 | RSUSL 的 CPS 接收完成，`rsu_status=1`，管理软件可以观察到 ready。 |
| 233762 | 新 EVT 淘汰 Seq16，`package_cancelled=1`。 |
| 233764–233774 | 本地结果入队，R_ICSL reset/nonchecking，结果释放，cleanup 清除。 |
| 233860 | 迟到 COPY 仍被原逻辑接受；没有包 owner，`icsl_normal_start_allowed=0`。 |
| 235208 以后 | Checker 已按未校验的真实内存值进入 `_exit(2)`，并写出 tohost。 |

直接症状：模拟器 `tsi_fail / code=2`（已证实）。立即原因：Checker 在
nonchecking 模式执行了 Main 控制流（已证实）。上游触发：管理软件在 EVT
取消前看见 ready，取消后继续发 COPY/JLR；原 COPY 无条件粘贴寄存器，JLR
无条件使用 RSU PC（源码及窄探针已证实）。下游放大：LSL 屏蔽失效，原应
作为回放数据的 AMO 会走真实内存路径（源码强支持，未单独采集该拍 AMO 总线
握手）；外部 tohost 写及退出失败已由日志与窄探针证实。

当前修复在 RocketCore：普通 COPY 仅在一个存活包被 R_ICSL 接受时粘贴；
失效的 COPY 保留管理寄存器，紧随的 custom JLR 返回原 pc_special 重新轮询。
管理上下文恢复 COPY 仍使用现有 store_from_checker 路径。结果释放复用
RSUSL core_hang_up 等待复制 RAM 尾拍结束。没有新增寄存器、队列或恢复状态机。

验证：旧版本完整复现如上。新版本 Scala/Chisel/FIRRTL、整核 Seq16→Seq1
复用与最终 oracle 尚在执行。此记录不把另一个 Fault8 的 HTIF 失败归为同一根因。
