# 最终 C4 DUT DCP 独立复用验证

2026-11-10 15:24 CST：已经实际启动Vivado验证，尚未宣称DCP打开或顶层拼接成功。原Vivado PID11088/start_ticks10629保持原地运行；15:23观察VHDL仍3,518,722,048字节，自12:45以来158.27分钟无新增写出，I/O计数不变。

## 已核对依赖

原DUT脚本先成功synth_design，再写DCP；后续`write_vhdl -mode funcsim`位于IP缓存/仿真产物生成步骤。原顶层脚本不引用funcsim网表，DUT的IP描述XML明确声明DCP用于synthesis及implementation；综合stub提供端口声明。DCP ZIP元数据确认Vivado2021.1、xcu280-fsvh2892-2L-e、正确Top及RenamePrefix。独立副本使用DCP内嵌stub，完整DUT和11个已完成IP检查点均核对复制哈希，包含DDR/XDMA。

因此**流程依赖上可绕过VHDL功能仿真导出**；最终可行性还取决于Vivado实际打开、顶层及DCP/XDC拼接、布局布线和时序结果。不能把依赖分析或ZIP结构完整直接当作实现通过。

## 实际执行

- 服务`ec-parsec-c4-dcp-independent.service`独立于SSH/VS Code，单实例锁、持久日志、每阶段原子状态；脚本`/data1/gzh/EC/firesim/final-opt4-20261106/scripts/build_c4_from_dcp.py`。
- 工作目录`/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/`；占用独立data1预算，不增加原CAD卷增长守卫的用量。
- 状态`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/C4-dcp-cad-state.json`；服务入口`jobs/c4-dcp-independent/{state.json,console.log,startup-audit.json}`（相对本实验数据根目录）。
- 私有目录仅复制design、BD/IP生成文件、项目与原顶层脚本/已完成IP结果；不复制原活跃DUT运行目录、.Xil数据库或.jobs，不修改原run结束标记。
- DUT DCP SHA256 `0dbdabf283669fd45d4389742fa9c05fa0163d01496e86e558c77d2bb3be86ae`；总计12个检查点的原始/副本路径、大小、SHA位于状态及工作目录snapshot.complete.json。
- `private-rtl-constraints-binding.json`核验7个design输入与原认证哈希逐字节一致；硬件commit仍为8491167d84b6d9521b151a743673c1516926a1f8，source_id仍为c9f51d3a94aac7783c750682162cd25e9d1460b04974bde9b7541f1d9f4120e7。
- 当前DCP读取的实际Vivado worker PID2163887/start_ticks10679021，15:24 CPU404.5秒、RSS16.75GiB。此为真实执行进展，不等于read成功。
- 初次独立服务因新锁目录写权限失败，未进入CAD、未改变任何活任务；保留console中的失败证据后将独立锁移至可写实验根目录，确认新服务退出后再启动。原CAD/FPGA服务没有restart。

## 最快可行路径与通过标准

1. Vivado真实打开复制DCP并检查part、未解析黑盒及资源。
2. 私有项目只生成原实现脚本，不启动DUT综合或网表导出；执行原顶层RuntimeOptimized综合。
3. 生成的实现脚本必须明确绑定当前DUT DCP，且无任何原CAD目录引用；随后按Explore策略执行opt/place/physopt/route。
4. 要求完整拼接无未解析黑盒、setup/hold slack非负，正常Vivado bitstream DRC通过；失败留痕，不降级时序/正确性标准。
5. 最后再次核对冻结源码、GoldenGate/driver/RTL和约束输入哈希、12个DCP哈希及bitstream哈希，记录独立认证receipt。独立产物尚未发布到活runtime receipt。
6. 认证候选接入唯一首验链后，仍需等21安全边界并通过smoke、功能/checker/排空，才开始13项普通PARSEC正式r1，再补r2/r3。禁止触碰e2或并发占用21。

这条路径复用已耗时完成的DUT综合，不等待功能仿真VHDL，也不重复elaboration、GoldenGate、driver或RTL综合。当前没有基于真实阶段耗时的可靠完工时刻，不能承诺某时上板。DCP读成功、顶层拼接/布局布线/时序成功、bitstream认证及21任务安全边界是判断上板条件的依据。

原导出保留为并行路径；当前没有证据表明增加其线程/优先级或迁盘能加速串行名称比较。独立分支采用nice15、2线程，启动余量80GiB、最低保留60GiB、最大增长120GiB。已有已通过Native样本不覆盖，网络队列继续自动运行。

## 15:32 CST 实际进展

新Vivado已经完成网表排序及924,327个Unisim元件转换，输出`Unisim Transformation completed in 58 CPU seconds`和`Preparing netlist for logic optimization`。worker仍为2163887/start_ticks10679021，CPU882.4秒、RSS27.07GiB；DCP完整打开/黑盒检查尚未返回，不能提前记通过。独立服务继续后续阶段，不依赖当前SSH。

原VHDL仍3,518,722,048字节，自最后写出已167.48分钟；原进程未受信号或输入修改。Native Netferret simsmall仍在21卡执行，正式42/48，Opt4正式0/48未增加。没有运行第二个FPGA实例，也没有触碰e2。

## 16:02 CST 实际推进与认证衔接

DCP真实打开、part核对、零black box门均已通过。第一次顶层失败为私有项目scripts-only刷新后DUT DCP/stub消失，原始证据保存在 `failed-top-20261110T074514Z/`。修复后12个DCP独立存入 `reused-checkpoints/`，恢复所需`.gen`路径；没有重跑DUT综合。顶层综合已返回0，生成 `design_1_wrapper.dcp`（264,612字节）。

实际实现worker PID2302586/start_ticks10852277，监督子进程PID2302531。已读取包括当前DUT在内的12个IP，完成网表排序与928,273个Unisim元件转换，进入 `Preparing netlist for logic optimization`；拼接返回后的零black box门尚待返回。无新ERROR。实现仍需opt/place/physopt/route和最终setup/hold、DRC、bitstream认证。

当前实现线程上限8、nice5；原CAD继续nice15，未给其发送暂停/终止信号。07:49→07:56 UTC，两实际worker各推进约429 CPU秒，新分支新增读取700,017,380字节、RSS5.40→16.66GiB；原导出新增写218,099,712字节（现约3.74GB）。MemAvailable仍约387GiB，256CPU负载约31、内存/I/O压力0，因此没有暂停原CAD依据。289样本低频perf显示EDIF词法解析、netlist traversal、分配等真实checkpoint装入活动；证据 `link-profile.txt` 与 `observations/c4-dcp-resource-*.json`。

重要容量风险：实际DUT报告5,938,927 LUT（U280的455.55%）、424,714 CARRY8（260.62%），须由顶层opt_design后的结果判断是否可布局。不能将DCP/顶层通过当成容量通过。Vivado2021.1支持ExploreArea等映射优化，但尚未启动另一个面积优化作业，不改变或重启当前实现。

`ec-parsec-c4-dcp-admission.service` 已启动，监督PID2305534、实际metadata进程PID2305535，独立实例锁与原子状态 `C4-dcp-admission-state.json`。它等待本分支全部五阶段实际返回0、拼接零black box、setup/hold/DRC/bitstream通过，复核冻结source_id和RTL/约束/12DCP哈希后耐久复制，先发布匹配runtime receipt，再发布canonical CAD就绪信号。第一个认证版本固定于 `C4-selected-certified-build.json`；旧/后续原CAD收据归档，不删除。服务不访问FPGA、不signal CAD。

现有c4-first和coverage-first均保持活跃：认证后等21安全边界→smoke→Blackscholes test/reset探测→simsmall→普通13项C4正式r1优先、再r2/r3。13项软件全部READY，`continue_fpga.py --check-software-only`实际返回SOFTWARE_AND_NATIVE_BINDINGS_VALID。没有发布任何未完成bitstream。Native42/48；Netstreamcluster graceful-close-v3的test/simsmall现有真实有效完成，正式simmedium r1正在21卡执行。Opt4正式仍0/48、有效配对0/16。

2026-11-10 17:05 CST capacity/flow update:

- Reopened immutable DUT DCP reproduces 5,938,927 physical LUT (455.55%) and 424,714 CARRY8 (260.62%). Independent EDIF census verifies primitive totals without ancestor double counting. Current mapping NOT FIT; complete-top post-opt verdict remains pending. Evidence: `../C4-capacity-20261110/CAPACITY_REPORT.md`.
- Diagnostic DUT `opt_design -directive Explore` completed Retarget and Constant propagation and is at Sweep; no post-opt utilization yet. Cell removal counts are not a LUT estimate.
- init_design successfully linked but the added gate rejected the sole generated dbg_hub_CV placeholder. Independent 11-IP shell reconstruction identified it as IS_DEBUG_CORE=1; the original generated flow implements it later with implement_debug_core. Failed process confirmed exited; full evidence preserved in `failed-init-design-20261110T084756Z/`.
- Resumed only the failed independent DCP controller, retaining successful DCP-read and top-synth stages. Exact dbg_hub placeholder is permitted at link; all functional boxes must resolve, and all boxes must resolve after implement_debug_core. No DUT resynthesis, no original CAD/Native signals, no FPGA operations.
- Complete top opt_design now saves utilization/DRC and capacity.complete before placement. If physical resources exceed device capacity it exits before place/route, retaining the optimized checkpoint. The report parser was checked against the real existing over-capacity report; missing functional IP rejection was separately verified. Frozen source and launched script hashes match receipts.
- Candidate-only exact arithmetic factoring passed arithmetic/width checks, 2048-cycle generated-leaf comparison and real leaf synthesis (83,179 LUT, 16 DSP). This is not full-DUT fit or formal hardware. Candidate receipt: `/data1/gzh/EC/firesim/final-opt4-20261106/candidates/capacity-exact-factor-20261110/candidate.json`.
