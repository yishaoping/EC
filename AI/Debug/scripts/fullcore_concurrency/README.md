# 完整Core并发计分

`io_rebase_scoreboard.py`使用实际reset握手建立物理事务namespace，避免把不同namespace的相同数值Seq误当重复设备效果。它严格要求完整程序/128ecall/正常架构配对、初始真实Fault40及其journal重放、Seq41未结效果不能预留/归零、效果释放后才维护、每一次reset后新Seq1 PASS，以及完整16轮48次真实mtime高/低/高设备读，不能只证明首段。

输入为同次`--normal`、`--fault`、`--effects`、`--overlap`和新的`--report`路径。原观察器完整footer、事件数、每次state transition均验证，未裁剪或伪造结束记录。真实完整正例`AI/TMP/singlecore_function_closure_20261123/io_rebase_injection_scope/scoped_core/program/`已成功退出：1,277,543周期、8次实际物理reset及8个新Seq1 PASS、48次设备读。`io_rebase_negative_test.py`对该完整运行的9种破坏全部拒绝，结果在`io_rebase_complete_negative_retry/`。第一次负例误删初始namespace的Seq1而未破坏reset后的验收条件，修正为删除第一次真实reset后的Seq1，原失败保留。

Fault40注入范围要明确：原R_RSUSL的once标志为每Checker本地。普通递增Seq运行只会有一个owner，物理Seq重基之后其他Checker仍可能第一次遇到40，因此“一次全局故障”专门配置必须限制初始真实owner，复用其原once位。原多注入运行保持原始记录，不被新输入或计分覆盖。

`build_interrupt_observer.py`链接只读`interrupt_observer.cc`，同时记录实际CLINT pending、CSR interrupt/trap、恢复stop、I/O屏障和journal；原IOMSHR记录保留。`interrupt_scoreboard.py`要求同ELF完整normal/Fault18的严格恢复链、16次handler、16次真实MSIP写1及16次handler清0、CLINT置位/清除与实际trap配对，以及恢复stop和未结效果交叠时IRQ被阻止。它需完整带footer的独立运行。当前生产Core/CSR/IOMSHR/Scheduler最终来源的normal/Fault18完整程序与严格IRQ均已PASS，旧失败仍保留。


`build_msip_workload.py --out <新的AI/TMP目录>`从长期`msip_workload.c`和
`msip_interrupt.c`构建原16轮MSIP/128ecall程序，复用现有Software/Test启动与Checker。
仅专用测试handler增加每hart计数，不改变一般软件handler。
`msip_longterm_equivalence/`已实际编译并逐字节核对：与原候选的loadable sections及
loadmem完全相同。该等价证明不替代完整Core运行。


2026-11-24：IRQ 正式计分现在要求 actual effectPending、live owner、journalSafe、starting、hold、精确 trap cause 和 xRET 字段；旧十字段 IRQ 日志不再能通过最终关闭入口。启动 MSIP 仍保留原样，保护窗口从第一个真实 set 对齐，但必须保留 16 set、16 clear、16 MSIP trap 和逐次返回。`interrupt_negative_test.py` 验证门控/cause/trap/return/设备轮次及footer损坏。旧 `final_irq_gate` 完整程序 raw/oracle 虽为0，但严格计分发现后六轮重复trap，FAIL保留，不是最终PASS。

`pressure_scoreboard.py --program RUN_LOG --pressure PRESSURE_LOG --run-exit RUN_EXIT --report NEW_REPORT` 验收完整64项History程序：实际Seq1 seal/END/count64、64/64满表、释放到至少48空槽并推进Seq、后续Checker PASS、结束时全部64空槽、完整checksum和模拟器退出。`pressure_negative_test.py` 用同样输入和 `--out NEW_DIR` 要求8类破坏全拒绝。原候选完整程序与8负例已实际通过；最终源码关系仍独立审查。


最终组合评分（必须等全部所选运行完整退出；输出目录须为新目录）：

```sh
python3 -B AI/Debug/scripts/fullcore_concurrency/system_acceptance.py \
  --core-runs AI/TMP/singlecore_function_closure_20261123/grantack_preemption_fullcore \
  --rebase-run AI/TMP/singlecore_function_closure_20261123/grantack_preemption_stress_retry/io-rebase \
  --pressure-run AI/TMP/singlecore_function_closure_20261123/grantack_preemption_stress_retry/pressure \
  --out AI/TMP/singlecore_function_closure_20261123/REPLACE_WITH_NEW_ACCEPTANCE_OUTPUT
```

该入口独立执行trap、Sv39、CLINT写、AMO、IRQ、Fault40+Seq32和满History严格计分，并运行IRQ/重基/压力损坏负例。PASS仅表示这些真实运行的验收条件通过，不自动提升任务状态；压力来源增量审查、64项历史依赖复核和物理实现报告仍需独立核验。当前实际结果在 `grantack_preemption_system_acceptance/result.json`：12个完整程序全部raw/oracle0；严格评分PASS，IRQ14/重基9/压力8负例全部拒绝。重新计分请替换新的输出目录，保留既有结果。


满History压力的原输入已长期保存为 `history_pressure_workload.c`，配置为 `SlowCheckerPressureConfig.scala`（Main200MHz、四Checker25MHz，复用v1Config原64项History/escape4）。`build_pressure_workload.py --out NEW_AI_TMP_DIR` 复用现有Software/Test启动/Checker构建同一程序。`pressure_longterm_equivalence/equivalence.json` 已实际验证新长期入口生成的loadmem与原完整通过的压力输入逐字节相同，未缩减96条stride65536、16轮或最终所有word oracle。
