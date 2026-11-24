# 真实软件中断后的CSR比较分歧（最小生产修复，整核重验中）

当前状态：原first bad及上游写入根因均已证明；宽候选因原Sv39 FAIL被否决，最小scratch镜像已合入生产且真实CSRFile动态PASS。最小生产实现的完整IRQ/Sv39/设备回归在途，尚无端到端验收结论。

证据在`AI/TMP/singlecore_function_closure_20261123/interrupt_candidate/`，使用完整C/E固定来源的normal v1与Fault18完整模型；生产随后合入的slot/GHM delta与新增双注入参数不属于这份模型，来源边界由inputs.json和模型source清单明确。候选软件每轮真实写CLINT MSIP，原handler真实清中断并维护每hart独立计数，共16轮和原128ecall、内存/FP/CSR oracle。无强制模型字段、无放宽比较器。

- 设备效果：normal tick82120真实CLINT ipi0变1；tick82122 journal建立；effect释放tick82317后才允许CSR IRQ，cause=0x8000000000000003，tick82320进入trap。Fault18模型tick82316..82317同时pending=1、stop=1、journal有效且irq=0，已覆盖真实I/O与恢复交叠。
- 症状：normal未配置注入却出现真实Seq23 FAIL；不能视为正确故障激励或关闭P2-07/P4-10。
- 首次直接分歧：first_divergence/normal_retry的只读观察在tick85652、Checker hart1、Seq23，package_error_now有效，ARF mismatch为0，全部32 integer/FP快照相等，CSR正在compare idx3(mscratch)。Main ECP mscratch=0，Checker reg_shadow3=0x80032f60，其他待比较CSR值单独保留，不据此提前断言全部相等。
- 立即条件：CSR比较读取实时reg_shadow，而RSUSL使用其专用architectural snapshot；CSR启动来自checker_arch_check_done，ARF启动还要求arch_snapshot_stable与完整包尾。
- 上游待证：CSR影子值在哪个CPS/CSR写/trap边界改变，local handler与比较是否交叠；timeline观察器正在同时追踪mscratch变更、check_done、quiet、privmode、CSR compare、PC和Seq。不能仅凭两条不同准入条件判定根因。
- 下游：无注入反复FAIL导致额外恢复。原normal/fault运行、所有FAIL与首次观察器编译失败（x0被常量优化）保留；修正只读字段后重跑，不改RTL。

下一步：完整复现同一first bad，反向定位首个错误影子写入，再选择复用原tail/quiet/模式握手的最小充分实现；必要新增快照必须明确硬件代价，并重跑原异常/I/O/Sv39回归。现不修改watchdog、不屏蔽CSR差异、不当作I/O输入变化问题。


更新：first_divergence/normal_timeline跟踪确认Seq23比较从tick85644至85672，PC稳定0x80000384、quiet=1、privmode=0，mscratch影子在比较前就为旧栈值。真实CSRFile（原生产class）注入CPS mscratch=0x80032f60，再在normal checker模式执行csrw mscratch,0，随后priv模式读取仍是旧值，before_run_retry.exit=1。原所有64个ARF相等不是因流水线比较时状态移动。

根因已证实：CSRFile为represented CSR的读视图及显式命令目的bank仅检查io.checker_priv_mode，普通checker_mode的CSR写入真实管理bank，未更新后续CSR边界要检查的影子。正常程序过去未覆盖异步handler返回后的此组合。候选CSR_minimal.scala把已有两检查模式的OR用于现有represented CSR读/写目的bank；实际trap-entry与synthetic-return代码保持原条件。无新寄存器、队列或恢复FSM。

独立候选Scala编译、Chisel/FIRRTL及真实CSRFile动态均PASS：normal写影子、priv写影子、management写不污染影子；minimal_run_retry.exit=0。候选完整normal/Fault18 Core已独立class路径生成，保留生产不变和全部输入哈希。尚未取得完整IRQ/旧正常异常/I/O/Sv39动态回归，不宣称该缺口修复验收或P2-07/P4-10完成。

长期真实CSRFile夹具及runner已放在`AI/Debug/scripts/csr_shadow/`，`csr_shadow_candidate/longterm_candidate/result.json`实际PASS。原normal完整程序最终触发Main pipeline hang断言（run.exit1），不因候选组件PASS覆盖此原失败。完整候选normal/Fault18已通过实际Scala/Chisel生成，后端构建/原IRQ程序及既有trap/Sv39/CLINT写/AMO正在执行。


最小生产更新：`csr_scratch_mirror_candidate/production.patch`只修改MSCRATCH/SSCRATCH显式写，normal仍更新物理寄存器并镜像到原shadow；读视图和其他物理CSR/MPRV行为保留。较宽候选切换所有normal CSR路由，在原Sv39程序触发little core 1 watchdog，原FAIL保留，两个宽候选完整IRQ PASS不计最小生产通过。最小生产当前`csr_scratch_longterm_production/`的Scala/Chisel/FIRRTL/动态全PASS，MPRV置位/清零控制亦通过。`csr_scratch_production_fullcore/`重新从生产SBT构建normal/Fault8/Fault18并运行原完整IRQ、Sv39、trap、CLINT、AMO；`csr_scratch_irq_signal_fullcore/`另链接长期只读IRQ observer执行严格16轮set/clear/trap与恢复未结效果交叠。最终结果以这些新目录为准。


追加已证CSRRS/CSRRC缺口：当前scratch镜像仍将共享`wdata`（按normal物理读视图计算）写入shadow。当CPS=0x1234、management physical scratch=0x80032f60时，normal CSRRS mask0x80应把architectural shadow更新为0x12b4，但实际采用physical旧值；`scratch_rmw_before_retry/run.exit1`稳定复现。最初probe误用CSR编码1而非实际W5，其初始化失败单独保留；修正真实命令后才将目标CSRRS失败认定为反例。

独立候选只把两个scratch的shadow更新改为`readModifyWriteCSR(cmd, existingShadow, operand)`，normal物理写和读视图不变，priv原语义等价。`scratch_rmw_all_commands/`实际Scala/Chisel/FIRRTL/Verilator全0：MSCRATCH/SSCRATCH各normal/priv的W/S/C共12组合、management隔离、SSCRATCH真实ECP以及normal真实MPRV均通过。RMW候选尚未生产合入；`integrated_capacity_scratch_candidate/`将其与已证容量seal保持候选一起进行独立完整Core验证，不能把只有CSRW的既有中断程序当作所有CSR命令正确的证明。
