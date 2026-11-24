# 排空确认之后接受 Probe，重启使用了旧就绪条件

状态：V6 真实缓存反例和独立控制器反例均已复现。V7 已补最终握手的实时检查，15 项组件通过，三配置整核回归中。

真实反例在 AI/TMP/singlecore_checker_20261122_082540/hierarchy_real_tracked_c_v6/。
生产 L1 持有 Seq8 Current，Pending7 已归档于 L2。可信 host 读取同址行引发真实
ProbeAckData，两个 C 队列槽均持有 Seq8。L2 为 dirty BASE 发出真实多拍外写，
host 扣住其 D ACK，随后依次送 FAIL8、FAIL7。两个 EVT 均能完成安装。

放开外写 ACK 后，旧 Probe 完成。L2 根据已失效的 Seq8 重新规划可信读，并发出
第二次 Probe。控制器在两次 Probe 之间短暂看到缓存空闲，进入 restore；新 Probe
随后到达，旧代码仍在 resume 发出 restart，触发已有断言。

只读信号探针 hierarchy_real_tracked_c_trace_v6/ 复用原生成库。cycle 为夹具
顶层上升沿序号，既不等于整核退休计数，也不能与其他运行的 tick 混用。

| cycle | Controller | quiesced | SCP pin | Probe state | 解释 |
|---|---|---|---|---|---|
| 981 | drain | 1 | 1 | 0 | 第一次排空条件成立 |
| 982 | restore | 0 | 1 | 1 | 新 Probe 已成为 owner |
| 983 | restore | 0 | 1 | 2 | Probe 继续 |
| 984 | resume | 0 | 1 | 3 | 旧 restart.valid 引发断言 |

直接症状、即时阻塞和上游触发均由同一生成模型记录。异常并非 SCP 丢失，
也不是拒绝旧 C 或放弃外写 owner。下游断言阻止了错误重启，不能删除或放宽。
独立组件将 quiesced 在 restore 完成后拉低并使 restartReady 为高，旧模型
在 cycle152 报 restart bypassed a late coherence owner，记录在
recovery_late_owner_before_v7_retry/。初次链接因相对目标路径失败，原日志保留。

V7 在 PalimpsestRollbackController 的 restart.valid 使用当前 quiesced 和
checkpointReady。resume 继续保持 stop、target 和 SCP pin，直到新的 owner 完成。
这一路是可重新判定就绪的恢复握手；既有更早 FAIL 和 identityUnavailable
仍然具有优先级。没有新增状态、计数器、队列或全局禁止 Probe。

长期 recovery_test.cpp 检查就绪撤回后不能 restart、SCP 保持和就绪恢复后的
单次 restart。hierarchy_test.cpp::realTrackedC 覆盖真实 L1、满 C、同址 BASE
外写 ACK、两次 EVT 和重查 Probe，逐 accepted 外写 beat 核对 BASE 的全部字。
`rtl_regression_v7/` 的 Scala/Chisel/FIRRTL 与 15 项实际运行均通过，两个新增
用例分别输出 `restart_rechecks_late_owner PASS` 和
`real_tracked_c_outer_owner PASS`。完整来源清单前后一致。原外层 zsh 在收尾
赋值只读变量 status，driver.exit=1；独立核验 15 条 PASS、无 assertion/UNCOVERED、
来源一致后记录 reviewed.exit=0，原收尾失败保留。实际完整程序的 V7 复验仍按
各自来源记录，不能以 V6 通过代替。
