# I/O 边界的包封口未完成，引起额外取消恢复

状态：Main 后置边界的 STQ 等待环已证实；V6最小接线修复通过15项组件和正常/Fault8异常MMIO严格配对，Seq16组合继续验证。

V3 与 V4 的 `compact-trap-io` 正常/Fault8 都能执行128次真实 `ecall`，
读取 CLINT，成功退出且架构校验和正确。然而严格配对计分失败：正常配置的
Seq0x28 以 CANCELLED 返回，Main 恢复 SCP40，PC为get_mtime内的0x80000858。
V4 Seq16 的两次重基已经通过，随后相同位置的Seq0xa也因普通取消触发恢复，
使只接受重基重启的严格计分器失败。旧记录完整保留在
`AI/TMP/singlecore_checker_20261122_082540/reviewed_v{3,4}_fullcore*`。

只读 V4 原生成库探针位于
`AI/TMP/singlecore_checker_20261122_082540/trap_io_cancel_probe_v4_retry/`。
源库哈希、链接命令、激励和观察信号均保存，没有修改硬件状态。tick单位是
emulator的sc_time_stamp，每个完整顶层时钟周期计一次；Checker每两拍一个上升沿。

| tick | 观测 |
|---|---|
| 118763 | hart1 接受 Seq0x28，保留包 owner。 |
| 118875 | 开始正常 checking。 |
| 119917→120877 | 一次真实 trap 与返回，R_ICSL 正常恢复 checking。 |
| 123971 | 到达一项 LSL 数据。 |
| 124097→124099 | LSL 请求和响应终结，之后不再有包进展。 |
| 255169 | 65535个 Checker 上升沿之后，package_progress_timeout与package_cancelled同时为1。 |
| 255171 | 取消脉冲结束，后续由既有结果与恢复链释放。 |

直到首次取消，`producer_sealed_for_package=0`、
`rsu_slave.ecp_complete_reg=0`、`arf_check_complete=0`。
`arf_wait_timeout`、`package_exec_timeout`、
`package_transport_error(_now)` 均未触发。周期性管理中断仍正常返回，却
不构成该包的执行进展。事件与终态保存于 `selected_evidence.json`。
该窄探针在270000拍按诊断上限exit2，不能记作程序通过。

接续探针 `trap_io_boundary_probe_v4/` 同时观察 Main 的IoBoundary、
R_IC producer/封口及 Checker 的指令计数。在确认上游条件之前不得改阈值、
伪造封口或放宽完整程序验收规则。首次探针因生成的C++字符串换行错误未编译，
其link.exit=2保留，不能当作RTL反例。

## Main 上游首个阻塞及 V6 修复

`trap_io_store_owner_probe_v4/` 在原 V4 生成库上只增加只读 eval 观察。
同一 ELF 在 tick123900..126000 中，唯一有效 STQ 项为2，未提交、无在途
功能请求，PC=0x800005c4（get_mtime 返回后的 `sd a0,0(s0)`）。
`stq_head=stq_commit_head=2` 始终成立。DCache ordered 在 MMIO 请求的
123949..123957 窗口为0，随后恢复1。MMIO 于123959退休，边界转 closeAfter；
R_IC于123962进入等待快照，STQ该项却始终有效，fencei_rdy始终为0。
该探针按诊断上限126000拍exit2，不能当作验收PASS。信号、源库哈希、
链接输入与事件保存在其 `selected_evidence.json`、`inputs.sha256` 和 `trace.log`。

因果链：`closeAfter → postReady=fencei_rdy → 要求整个STQ为空 → 年轻store待提交
→ retirementHold阻止年轻退休 → STQ无法清空 → 无后置快照/封口 → Checker等待
ECP最终计数/ARF → package_progress_timeout → CANCELLED → 额外恢复`。
LSU只允许已提交且收到功能终态的store释放。I/O之后的年轻项不属于当前
已提交ARF或ECP，却被错误纳入后置物理排空条件。这一等待环已闭合。

V6仅将Core的 `ioBoundary.io.postReady` 从 `io.lsu.fencei_rdy` 改为
已有 `io.lsu.ioIssueReady`，复用已提交前缀排空、DCache ordered与HellaCache idle。
I/O单步退休、prefix安全水位、journal、interrupt hold、旧owner终态和Checker
完整计分规则均继续使用原机制。无新增状态、寄存器、队列、FSM或阈值。
`fencei_rdy`仍用于其原有架构围栏语义。

V5生成FIR及源码在修改前核验并保存到 `v5_pre_v6_generation_checkpoint.json`；
V6源码与差异在 `sources_v6.json`、`io_post_boundary_candidate_v6/production.patch`。
`rtl_regression_v6/`运行长期15项；`*_rtl_v6/`构建三配置并重跑compact与
同一compact-trap-io。最终必须由严格配对和Seq重基计分结果判断修复；
host直接提供postReady的IoBoundary组件测试只能验证状态机，不能验证Core接线。

V6组件已回收：长期15项同次回归全部PASS，driver exit0，前后来源一致。
独立核验记录在rtl_regression_v6/reviewed_results.json；三份整核Chisel FIR
已核验sources_v6并保存v6_generation_checkpoint.json。整核仍在编译，尚无
本项接线修复的动态整核PASS。

逐相位复核 `trap_io_rsu_phase_probe_v4/`（after每次eval，诊断124500拍exit2）
确认RSU于118820结束merge，snapshot_rsu_prev于118821变0，之后直至后置
closeAfter都保持空闲。旧 `trap_io_boundary_probe_v4` 仅取每tick首个eval，
漏掉了这两项下降沿，其末值1不能作为RSU占有证据。新探针的事件在
selected_evidence.json；逐相位事件可能比旧首eval事件早一tick，不能混拼。
这排除了另一条RSU等待链，继续只验证V6的一处postReady接线修改。

V6独立模型已越过旧first bad：正常配置Seq0x28以同一PC=0x80000858
开始，随后Seq0x29..0x2d覆盖后续CLINT读取边界，各包均PASS，观察时点
无CANCELLED及Restart。部分证据在v6_io_old_firstbad_review.json。
这只证明原局部阻塞消失，完整程序oracle、正常/Fault8配对及Seq16仍在运行。

V6正常compact-trap-io已完整通过：独立O0大文件模型在808703周期成功
退出，128次ecall/MMIO及架构oracle成立，353包全PASS，零FAIL/CANCELLED/
Restart。事件和判定在v6_fast_model/normal/trap_io/。Fault8配对与Seq16
仍在运行；原O1模型的同一profile另在执行，分别保留来源。

本轮正常/Fault8的完整compact-trap-io严格配对已PASS：正常808703周期、
Fault8 967701周期均成功退出，128ecall和MMIO/内存/FP/CSR oracle正确。
正常353包全PASS、零恢复；Fault8有353个PASS、唯一FAIL8、无CANCELLED，
仅一次EVT/restore/restart，SCP8与恢复PC相同。严格配对见
`v6_trap_io_pair_review/scoreboard.log/.exit`。计分器另显式拒绝额外错误/取消/
恢复，11个负例全部被拒绝，见`strict_scoreboard_v6/negative/results.json`。
这些结果确认原正常配置的取消恢复已消失；Seq16完整profile及真实效果后FAIL40
仍单独验收，不能据此关闭其余I/O组合。
