# 重启排空检查与 snapshot redirect 的组合反馈

状态：V7、V8 整核 FIRRTL 均失败；已改为复用 RSU 既有 busy 寄存器，等待最终整核验证。

V7 保留的实际失败为
`AI/TMP/singlecore_checker_20261122_082540/normal_rtl_v7/build.log`。
Chisel 展开成功后，FIRRTL CheckCombLoops 在 BoomCore 报告：

```text
io.ifu.redirect_val
 → snapshot_no_redirect → R_IC.snapshot_allowed → if_dosnap_priv
 → R_RSU.rsu_busy → rollback.quiesced → restart.valid/fire
 → recoveryRestart → io.ifu.redirect_val
```

直接症状和完整反馈路径均由工具证明。上游触发是 V7 正确地在最终 restart
重新检查排空，而原 snapshot guard 读取了包含恢复 redirect 的最终前端输出。
RSU busy 包含同拍 snapshot 请求，因而形成组合反馈。不是新的缓存 owner 丢失，
不能撤回实时 quiesced 门控或删除 CheckCombLoops。V7 的 15 项组件虽已通过，
但夹具不包含完整 Core 的前端 redirect/snapshot 连接，不能覆盖这条环。
Fault8 与 Seq16 的冗余 V7 构建已停止，原退出记录及停止进程清单保留于
`restart_redirect_candidate_v8/v7_cancelled_builds.json`。

V8 修改 `boom/src/main/scala/exu/core.scala` 的 snapshot_no_redirect：直接使用
已有寄存器 `arch_redirect_valid` 和 `brupdate.b2.mispredict`，不读取最终
`io.ifu.redirect_val`。正常执行时最终 redirect 的条件恰为这两者的 OR；恢复期间
Core 的 if_ready_snap_shot 与 R_IC 的 snapshot_allowed 都独立受 recoveryStop
禁止，包含最终 restart 握手拍。因此保留正常 snapshot 拒绝条件，也保留 restart
的实时 owner 检查。无新增寄存器、FSM、队列或接口。

`restart_redirect_candidate_v8/` 保存设计、原组合环、修改前源码、完整前后哈希
及唯一生产差异。`v7_generation_checkpoint.json` 保存三配置原 FIR 和输入哈希。
下一验收为真实 BoomCore FIRRTL 无组合环、组件回归和正常/Fault8/Seq16完整程序。
构建成功之前不记录运行 PASS。Sv39 的 HTIF 停滞来自原 V6 运行，另按独立
来源追踪；不能把它归因于尚未运行的 V7/V8。

V8 的实际 `normal_rtl_v8/build.log` 再次由 CheckCombLoops 拒绝，driver.exit2：

```text
snapshot → RSU busy → quiesced → restart.fire → SCP discard
 → capture.ready → snapshot
```

这证明只拆 redirect 来源不充分。最终修订撤回该 V8 workaround，保留原 snapshot
guard，改为在 Controller 排空输入复用既有 `snapshot_rsu_prev`。该寄存器原本就
服务 snapshot 准入；仅将定义前移并复用于恢复，不新增硬件寄存器或接口。

R_IC 的 `snapshot_allowed` 包含 `!recoveryStop`，停止期间没有新 snapshot 请求。
上一拍 RSU busy 覆盖所有已接受 snapshot、下一拍 merge 请求及内部延迟/流状态。
如果上一拍 busy 为低，停止期间既有 RSU owner 已空；若最后一拍刚结束，则多等
一拍。该寄存器只用于 RSU，DCache/LSU/Checker 仍为实时条件，新 Probe 仍可撤回
restart。前后源码、V8 第二条组合环及设计证明在
`restart_rsu_drain_candidate_v9/`。仍须实际完整 Core FIRRTL 和运行回归验收。

V9 真实正常整核 Scala/Chisel/FIRRTL 已通过，GenerateModelStageMain 在 451 秒
成功结束，原两条 CheckCombLoops 均消失，低 FIR 哈希保存在
`restart_rsu_drain_candidate_v9/firrtl_validation.json`。随后主动停止 V9 的 firtool/
C++ 后续构建，原 exit143 保留；完整动态回归统一由包含 capacity owner 修复的
V10 执行。此处只记录整核生成通过，不能当作动态功能 PASS。
