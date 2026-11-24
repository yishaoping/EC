# 执行停止与 I/O 效果终态的整核交接缺口

本条属于 C/E 恢复控制与 I/O 的同一功能链验收。证据在
`AI/TMP/singlecore_function_closure_20261123/`；原通过的 Seq32 生命周期另按其
实际范围保留，本条不修改 watchdog 或放宽整核判定。

正常 Sv39 的直接失败是 LSU `lsu.scala:865`：执行单元的 Valid 请求没有任何
incoming 调度路径消费。原整核只读探针记录 tick624150，hart3 的 Seq30 在
尚未开始执行时触发 package_progress_timeout；已收到 producer seal，ARF/exec
timeout 与 transport error 均为0。tick624164，错误经原结果 CDC 到 Main，
Controller 仍处 idle，但 held Error 已将 stop 拉高。原 load 执行结果仍在返回。
旧 LSU 只将 load can-fire 以 stop 屏蔽，未屏蔽输入 Valid，于是触发原断言。
上游原因由 sv39_admission_probe 同一原模型证明：最后Seq30/hart3及Seq31/hart2
仍package_start_pending，context_idle=1且RSU ready，但Checker软件已经退出
检查循环并store_from_checker恢复管理上下文。软件以GHM status=FINISH退出；
原GHM仅按FINISH加输入队列空判定会话完成，越过尚未COPY/执行的包。

`LsuRecovery` 夹具实例化完整生产 LSU，原代码对同拍 stop+load 直接触发同一
断言，见 `lsu_stop_before_wired/run_lsu_recovery.log`。前几次夹具因 manager
Get权限、未定宽SInt和诊断Boring sink缺失而生成失败，均保留原日志。它们不是
硬件运行反例。最终原代码的 FIR/Verilog 与来源哈希在
`control_io_contract_fix/lsu_before_generation.json`。

同时，首次真实 uncached AMOADD 整核测试确认两处接口错误：

| 顶层周期 tick | 信号 | 含义 |
|---|---|---|
| 81294 | activeSeq=18，I/O state=issue | 前缀已经封口，AMO应属于新效果包 |
| 81295 | 设备 A 已接受，IOMSHR req.seq=17 | 沿用地址生成时旧 STQ Seq，错误归属前缀 |
| 81302 | journalSeq=17，旧值0x1234000000001000 | 设备效果与旧值被记录 |
| 81303 | journal清除；resp=1、token=0x16e0、completion队列仍空 | SW17使错误归属的效果提前安全；IOMSHR提供第一次旧值 |
| 81304 | resp=1、同token、completion队列非空 | DCache把STQ terminal再次变成架构响应 |
| 81305 | ROB not-busy writeback assertion | 同一AMO重复写回，原整核失败 |

该链由 `mmio_amo/normal/effects.log` 与独立同模型
`mmio_amo_response_probe/signals.log` 证明。tick 是完整仿真顶层周期，不是
退休指令数。旧模型同时打印 SCP18 的 PC0x800005e4。STQ地址生成发生在前置
屏障之前，普通store在提交时重绑Seq，但AMO设备效果发生在ROB提交之前，旧
字段直到提交才更新，因而漏掉了该类指令。

实现采用四个既有协议边界：

- GHM在源端持有finishPending，forwardDrained后才入session控制CDC。它复用
  R_IC包槽真实释放、END/count和源端FIFO空收据；Checker输入队列空不能替代
  包执行完成。SeqTransport原反例已失败；修后夹具保留segment直到真实释放，
  验收未消费数据、未生成结果及Main未释放三个阶段均不能FINISH。

- LSU 在 SFENCE 复制之后，以 rollbackStop 屏蔽所有尚未获内存 owner 的执行
  Valid。已提交前缀的 store 调度与已接受 HellaCache/Cache 响应仍走原独立路径。
  恢复本身的全量 SFENCE 由 rollbackReset 的原通道发出。
- 只有未提交 uncached AMO 在设备授权时从当前 active_packet_seq 取得效果包号，
  接受时写入既有 STQ packet_seq；保持原请求/effect token。普通已提交 store
  与 cached AMO 的规则不扩大修改。
- IOMSHR 是 uncached AMO 的唯一旧值响应方。DCache 的后续 terminal 只送
  store_done，完成 STQ owner；cached AMO 继续用原 terminal 生成唯一响应。

没有新增 owner 状态位、计数器、队列、RAM、全局保护信号或 FSM。
必须验收五类执行请求stop边界、普通执行positive control、cached AMO、真实
uncached AMO原值/最终设备值/一次效果、Fault18重放、正常/Fault8/Seq16与原
Sv39完整程序。四配置完整Core与11项组件已按固定生产来源启动，尚未取得最终结果，不记为已闭环。

当前固定来源正常Core已在原失败Sv39同一ELF完整成功退出：555912周期，
31包全部PASS、零取消/额外恢复；16次PC0x8000045c的实际LOAD精确核验
0x8000a000/0x8000b000及两组数据。证据priority_original_failures/sv39/
保存模型/ELF/来源哈希、raw run.exit0、完整正常oracle及physical_loads。
原上游FINISH早退和其后取消/LSU断言均消失。Fault8配对及AMO/CLINT写
完整联合验收仍在途，不将正常Sv39单项PASS扩大为整批控制/I/O完成。

正常/Fault8 trap_io完整严格配对PASS；当前生产CLINT写normal/Fault18及
uncached AMO normal/Fault18完整联合计分均PASS。AMO实际16轮设备A+回读
及全部old/new正确，首效果Seq18，raw_word0x1234000000001000重放、同PC恢复、
原逻辑操作至重放结清设备A恰好1；4项后续轮次损坏负例拒绝。原重复ROB
响应及journal提前SW17释放缺陷消失。P4-09按原屏障任务范围关闭，重基/
中断压力仍由P5-10/P4-10验收。见io_barrier_closure.json。

Sv39 normal/Fault8也已通过新的精确物理/提交联合oracle。旧脚本错误假定
故障仅16次物理读取，V6/V10/current均18，实测SCP8在round3后捕获，
废弃round4/5并重执行。新计分逐物理request/response/terminal与真实Main
commit x5/x12配对，SCP/Restore截断逻辑后缀，存活16/16，物理16/18全部
数据正确；废弃数据损坏等4负例拒绝。旧失败保留，RCA见sv39_physical_oracle_rca。
