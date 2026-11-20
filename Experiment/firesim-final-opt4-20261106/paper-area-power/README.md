# EC Performance-Only FPGA hardware resource and power audit

审计日期：2026-11-14（Asia/Shanghai）。仅审计已失败的 R6 build；不跟随当前优化候选更新数值。

## 结论与论文使用范围

**有真实 Vivado 报告支撑的是 mapped FPGA 资源用量；不是 ASIC mm²、不是完整 PALIMPSEST 增量、不是成功 post-route 实现。** 完整 shell post-opt 为 1,023,687 LUT（78.5229%）、1,019,173 个 CLB registers（39.0883%）、678.5 BRAM36-equivalent（33.6558%）、115 DSP（1.2744%）、15,706 CARRY8（9.6379%）、0 URAM。该版本通过容量门，但后续布线失败。

原有 `report_power` 确实存在，报 15.350 W 总 on-chip、11.890 W dynamic、3.460 W device static；**这些数值只作为失败 build 的诊断，不适合用作论文定量功耗结论**：非法布线、Low confidence、无仿真活动文件，并出现 reset 活动不合理警告。合法 placed checkpoint 的独立 vectorless 报告如成功，单独列在下方，绝不与 post-opt 资源或失败 route 的功耗混成同一阶段。

## Build 身份与保存边界

- 唯一数值来源 build：`build-logs/Opt4-performance-only-support-r6-20261113`，configuration `DacOpt4C4`。
- Hardware revision：`6fada307bb77be90b39720d3f95404fece0e431b`；controller/experiment revision：`cef2d0bd09ec1480db0f29034c2b0a29a28b949f`。见 [state.json](raw/r6/state.json:9)。
- Source ID：`461e1b98833d1a78a8bd27c0eed2d3353c648dfbf29ae5588db31bbce0f77369`；generated RTL SHA256：`d2cfb70488d2826cbd997c47954b2be0fc17a5342a430235481b07539a32cf94`。已重新读取 R6 RTL 验证哈希，见 `evidence/revision_verification.json`。
- R6 复用 R5 已完成的 Golden Gate/MCRams host generation，由 `predecessor-release.json` 和 `rtl-state.json` 记录，属于同一硬件配置的明确输入链；不是把 R5 的面积当作 R6。源码树 generators 对硬件 revision 的 diff 和工作区 status 均为空。
- Vivado v2021.1，SW Build 3247384；part `xcu280-fsvh2892-2L-e`，U280。[top-postopt-utilization.rpt](raw/r6/top-postopt-utilization.rpt:3)。
- `evidence/source_manifest.json` 保存原路径、字节数、mtime 和 SHA256；`raw/r6` 保存报告、日志、Tcl/XDC；`checkpoints` 保存 synthesis、opt、placed、physopt、failed-route DCP 的独立副本。Native 单独保存在 `raw/native-B`，不进入 R6 分项合计。
- 后缀 `_routed` 和 `Design State: routed` 不等于合法布线；以 route status、DRC 和日志判断有效性。工具进程 returncode=0 也不等于物理门通过。

## 各阶段证据

| 阶段 | 报告时间（报告原文） | LUT | CLB registers | 含 shell | 可用于论文的口径 |
|---|---|---:|---:|---|---|
| DUT synthesis / Synthesized | Fri Nov 13 13:05:09 2026 | 939,850 | 927,968 | 否 | DUT-only synthesis，不能加减其他阶段 shell |
| Full-shell post-opt / Optimized | Fri Nov 13 13:28:51 2026 | 1,023,687 | 1,019,173 | 是 | pre-route mapped resources |
| Full-shell placed / Fully Placed | Fri Nov 13 15:39:30 2026 | 1,015,701 | 1,019,298 | 是 | pre-route mapped resources |

这三个 LUT 数值不同是同一 build 的实现阶段差异，不能交叉加减推断“shell 面积”。分项主表统一取 post-opt；placed 另存 CSV。

| 资源 | post-opt used | U280 available | 利用率 |
|---|---:|---:|---:|
| CLB LUTs | 1,023,687 | 1,303,680 | 78.5229% |
| CLB Registers | 1,019,173 | 2,607,360 | 39.0883% |
| Register as Flip Flop | 1,019,172 | 2,607,360 | 39.0883% |
| Block RAM Tile | 678.5 | 2,016 | 33.6558% |
| RAMB36/FIFO | 658 | 2,016 | 32.6389% |
| RAMB18 | 41 | 4,032 | 1.0169% |
| URAM | 0 | 960 | 0.0000% |
| DSPs | 115 | 9,024 | 1.2744% |
| CARRY8 | 15,706 | 162,960 | 9.6379% |
| F7 Muxes | 113,074 | 651,840 | 17.3469% |
| F8 Muxes | 41,904 | 325,920 | 12.8571% |

资源依据：[top-postopt-utilization.rpt](raw/r6/top-postopt-utilization.rpt:38)、[top-postopt-utilization.rpt](raw/r6/top-postopt-utilization.rpt:80)、[top-postopt-utilization.rpt](raw/r6/top-postopt-utilization.rpt:96)。BRAM36-equivalent = RAMB36 + RAMB18/2 = 658 + 41/2 = 678.5；RAMB18 与 BRAM tile 不能再次相加。CLB Registers 比严格 FF 多 1 个 AND/OR primitive；层级表虽然标为 FFs，合计对应 CLB Registers。

## 不重复计数的层级拆分（统一 post-opt）

| 资源组 | LUT | 占全设计 LUT | Registers | BRAM36-eq. | DSP |
|---|---:|---:|---:|---:|---:|
| BOOM + L1 / local controls (excl. SVB, GH_BUF) | 418,603 | 40.89% | 199,156 | 32 | 36 |
| Shared L2 cache and coherence wrapper | 16,117 | 1.57% | 7,278 | 292 | 0 |
| Speculative Version Buffer (SVB) | 64,699 | 6.32% | 20,711 | 0 | 0 |
| Four checker Load-Store Logs (LSL) | 15,172 | 1.48% | 14,332 | 16 | 0 |
| Four checker domains (excl. LSL) | 276,644 | 27.02% | 275,182 | 8 | 76 |
| EC communication (system GHM CDC + GH_BUF) | 122,369 | 11.95% | 380,975 | 0 | 0 |
| Other target interconnect / peripherals | 11,501 | 1.12% | 13,308 | 4 | 0 |
| FireSim host / bridges / FAME harness | 14,372 | 1.40% | 16,995 | 193 | 0 |
| U280 shell / DDR4 / PCIe / debug | 84,210 | 8.23% | 91,236 | 133.5 | 3 |

方法：解析实际 instance 缩进与 Module，按父总量减去直接子模块总量形成有符号 residual，再将每个 residual 仅归入一个资源组。Vivado 对共享 LUT 的层级归属会使少数父总量小于子模块总量之和；**不把负 residual 截零**，以免高估。保存全部 residual，分组后每一项均非负且九种资源均与顶层精确相等。这是层级会计分配，不是恢复了已被优化掉的 RTL 对应门数，也不能把某个组当作“纯新增保护逻辑”。

- BOOM 组：main tile PRCI domain，扣除 SVB 和 GH_BUF，补回 FAME hoist 到 target 根部的两个 BOOM register-file RAM models。包括 L1、MSHR、local protection/control；不能视作未保护 BOOM。
- SVB：[top-postopt-hierarchical.rpt](raw/r6/top-postopt-hierarchical.rpt:4005)；LSL 四实例见 [top-postopt-hierarchical.rpt](raw/r6/top-postopt-hierarchical.rpt:4277)、[top-postopt-hierarchical.rpt](raw/r6/top-postopt-hierarchical.rpt:4418)、[top-postopt-hierarchical.rpt](raw/r6/top-postopt-hierarchical.rpt:4559)、[top-postopt-hierarchical.rpt](raw/r6/top-postopt-hierarchical.rpt:4700)。
- Checker 组：四个 TilePRCIDomain，扣除各自 LSL；仍包括本核 checking/replay/control 和私有 cache。四个 RocketTile 的含 LSL 原始 inclusive 行另存 `results/key_hierarchy_inclusive_postopt.csv`，不得再和本表相加。
- Communication 组：system 下 `ghm_*` CDC queues/synchronizers 加 BOOM `gh_buf`；范围明确且不包含所有 checker 内部控制。系统级 CDC 单独为 113,319 LUT、367,896 registers；GH_BUF 为 9,050 LUT、13,079 registers。[top-postopt-hierarchical.rpt](raw/r6/top-postopt-hierarchical.rpt:2625)。
- L2 组含 cache array、coherence、version/control 和包装逻辑；不是“新增元数据”的纯增量面积。
- FireSim host/harness = linked `firesim_wrapper_0` 减 `sim/target`，包括桥接、trace/print 流缓冲、时序模型和 FAME channels。Shell = 全设计减 linked `firesim_wrapper_0`，包括 DDR4 controller/PHY、PCIe/XDMA、clock/reset、debug。不能将这些实现开销作为处理器 ASIC 面积。
- 原始层级报告没有逐模块 CARRY8 列；仅报告其可信顶层总量，不按 LUT 比例编造 CARRY8 分项。

## Placement / routing / timing / DRC 有效性

- placed utilization 明确为 Fully Placed；LUT 1,015,701，registers 1,019,298。放置完成不代表最终可布线或时序通过。
- route status：1,790,138 条 routable nets，仅 741,299 条 fully routed；1,048,839 条存在 routing resource conflicts。见 [design_1_wrapper_route_status.rpt](raw/r6/impl_1/design_1_wrapper_route_status.rpt:10)。
- 日志记录 2,702,263 node overlaps，`Router completed with failures`。见 [implementation-attempt-1.vivado.log](raw/r6/implementation-attempt-1.vivado.log:3820)。
- 失败 checkpoint 的 STA 为 WNS −19.489 ns、WHS −0.487 ns；仅用于说明失败，不能换算可运行频率、不能称收敛后的时序。[timing-summary.rpt](raw/r6/timing-summary.rpt:140)。
- 最终 DRC 为 Partially Routed，281 条，其中 RTSTAT-13 Insufficient Routing 为 Critical Warning；还明确说明未布线太多而未执行部分 RTSTAT checks。见 [final-drc.rpt](raw/r6/final-drc.rpt:10)、[final-drc.rpt](raw/r6/final-drc.rpt:31)。
- 没有本轮认证 bitstream、板级运行或板级功耗。`postopt_capacity_fit=true`，`physical_fit=false`，`full_system_fit=false`。[postopt-result.json](raw/r6/postopt-result.json:53)。

## 功耗来源、设置与局限

原 failed-route report：[design_1_wrapper_power_routed.rpt](raw/r6/impl_1/design_1_wrapper_power_routed.rpt:33)。Total 15.350 W = Dynamic 11.890 W + Device Static 3.460 W（报告精度）；另分 FPGA 15.097 W、HBM 0.253 W。HBM 项是 Vivado 器件模型项，并不证明本设计使用 HBM，也不包含板卡全电源、外部 DDR4、供电损耗或主机功耗。

原报告主要 dynamic 层级：FireSim wrapper 2.651 W，XDMA/PCIe 7.568 W，DDR4 controller/PHY 1.472 W；这些为 inclusive dynamic 值，不能把父子行相加，也不含全器件 static。原报告层级深度不足以给出独立 BOOM/LSL/SVB 功耗，未按资源比例分摊。见 `results/power_hierarchy_failed_route.csv`。

- Process = typical、Characterization = Production，表示 FPGA 工具模型，**不是 28 nm ASIC 综合或实测功耗**。
- Clock 由 checkpoint/报告约束决定：host `clk_out1_design_1_clk_wiz_0_0` 在功耗报告中四舍五入为 20.0 ns；STA 精确为 19.998 ns / 50.005 MHz。PCIe AXI 4 ns /250 MHz；DDR controller clock 约 3.3 ns。这些不是论文架构核 3.2/1.6 GHz 的物理时钟。target 模拟时钟/ratio 也不能作为 FPGA power clock。
- 无 SAIF/VCD，`Simulation Activity File = ---`，`Design Nets Matched = NA`；日志明确 `Running Vector-less Activity Propagation`。没有 workload 活动向量覆盖率可报告，不能把传播/默认活动当作实测覆盖率。
- 原报告：>95% clock nodes 有 user-specified clocks；>75% inputs 缺 user activity；<25% internal nodes 有 user-specified activity。这些不是 workload-SAIF 覆盖率。
- 原 report 命令没有全局活动覆盖；但 checkpoint 内嵌的 PCIe IP XDC 对 `user_reset`、`sync_sc_clr`、`src_arst*`、`sys_reset*` 四组局部 nets 显式设定 `-toggle_rate 1.000 -static_probability 0.010`。placed 与 failed-route DCP 均找到这些约束，保存于 `raw/r6/checkpoint_constraints` 和 `evidence/checkpoint_activity_constraints.json`。这不是 target workload 的 activity 注释。未注释 target nets 的内置默认数值未写入原报告，故不把常见默认 12.5% 或 0.5 当作已核实的这次输入；新增报告保存 switching-activity/advisory 和 checkpoint 属性（若工具支持）。
- 原 thermal 假设为 ambient 25°C、250 LFM、中等 heatsink、12–15 层通用板和 ΘJA 0.4°C/W。报告预测 junction 31.7°C；均非 U280 实测温度。[design_1_wrapper_power_routed.rpt](raw/r6/impl_1/design_1_wrapper_power_routed.rpt:132)。
- 原警告 `Power 33-332`：默认/传播活动使高扇出 reset 被过长时间置有效，可能严重低估或扭曲大量寄存器/逻辑的 dynamic power；禁止将小 dynamic 值当作能效收益。[implementation-attempt-1.vivado.log](raw/r6/implementation-attempt-1.vivado.log:3937)。

独立 report-only 功耗：`generated/placed/power_vectorless.rpt`，状态 `placed`；Total **15.378 W**，Dynamic **11.918 W**，Device Static **3.460 W**，confidence `Low`。这是合法 placed、尚未布线的 **vectorless estimate**，采用估计互连寄生，不是最终实现功耗。所有活动/clock/advisory、执行约束和日志保存在 `generated/placed`；细分见 `results/power_hierarchy_placed_vectorless.csv`。即使 checkpoint 合法，也不能据此报告实际板级功耗或 PALIMPSEST 相对 PEEK 的功耗增量。

重开 placed DCP 时工具还提示 `xiphy_riu_or` 和 `genVref.u_hpio_vref` 无 power model；保留于 `generated/placed/console.log`。未对未建模部分臆测补值。

新报告可直接取得的主要 inclusive dynamic 为：FireSim wrapper **2.646 W**、XDMA/PCIe **7.543 W**、DDR4 controller/PHY **1.539 W**。`-hier all` 展开了资源类别，文字报告仍只输出 shell 顶部若干层；因此没有独立 BOOM、SVB、LSL、checker 或 target/host 分离功耗。它们明确记为未提供，未按 LUT 数量分摊。

主 `report_power` 已在日志中明确 `completed successfully`。其后的辅助 `report_switching_activity` 调用缺少 objects 参数而报错，未生成活动摘要；这一 API 调用错误不影响此前完整的功耗报告，也不改变缺失 workload SAIF/VCD 的事实。额外 `report_power -advisory` 又开始重复传播；为避免继续耗时，已只终止本轮自己的独立报告进程，保留 `optional_advisory_stop.json` 和日志。`invocation.json` 的 wrapper returncode=143 / FAILED_WITH_LOG 对应这个附加阶段被终止，**不是主 report_power 失败**。原始 invocation 状态未改写成成功；没有终止任何既有 FPGA 优化进程，也没有为辅助摘要重开 Vivado。

## Native / PEEK / ParaMedic 对比边界

找到 Native B 的真实 U280 Fully Placed 报告：357,590 LUT、204,054 registers、444.5 BRAM36-eq.、39 DSP、2,932 CARRY8。对应构建 `B-bitstream-20261102T095746.955739Z`；同阶段本轮 EC 为 1,015,701 LUT、1,019,298 registers、678.5 BRAM36-eq.、115 DSP。仅在 `results/baseline_comparison.csv` 作为两份真实报告的背景列示；**没有把 post-opt EC 与 placed Native 相除**。

已静态比较两份参数 JSON：相同 BOOM 参数及 L1、相同 1 MiB/16-way L2 geometry、相同 memory-model 参数与 16 GiB target address space。Native 一核，EC 一 BOOM 加四 checker；这本来就是系统范围差异。此外两个 build 的源码日期、保护逻辑、FireSim trace/stream 和物理优化未做配对控制，也没有 Native 的同阶段相同层级 host/target 对照，不能将总差值或比例归因为 PALIMPSEST 净增量。原有 matched-parameters JSON 是更早的上下文证据，未替代本轮报告。

Native 的 routed power 13.966 W 也为 Low confidence vectorless；EC 原值来自非法 route，新值来自 pre-route placed，活动未配对。**不计算/发布功耗 overhead 百分比**。在本次搜索的 Experiment 和 dac2026/work 报告路径中，未找到可确认同配置、同边界的 PEEK / ParaMedic 真实 FPGA 报告；这不是宣称所有外部位置都不存在。搜索路径清单保存于 `evidence/baseline_report_search.json`。

## Performance-Only 实际删减范围

`raw/profile/6fada307-PROFILE.md` 与该 revision 的 `pruning-edits.json` 是实际范围依据。其明确删去 PackageAddressStats、三份 GHBarrierLatencyStats、L1/L2 dirty-writeback diagnostic buckets/reductions 及相关统计接口；真实 LSL、SVB、cache version/isolation、safe-prefix bitmap、checker package results、commit/release 和 capture/full backpressure 保留。源码连续性 receipt 保存了实际 SVB ready/valid 和 probe backpressure 的位置，作为静态源码证据，不作为 FPGA 执行证明。

**与任务描述的一处差异：这个 revision 的 PROFILE 明确写 “R1 retains EC fault recovery logic ... not ... every allowed recovery-only cut is implemented”。** 已核查 R5 generators 对 `6fada307` 无新增差异；本轮没有证据支持“已删除部分 recovery logic”的具体清单，不能按意图写成已发生。也不能据此反向宣称完成 recovery 的系统验证。论文最稳妥称谓是 **EC Performance-Only prototype with diagnostic instrumentation removed**；该版本的 FPGA 资源不能冒充完整 PALIMPSEST 的经过恢复验证的面积/功耗。

## 建议论文写法与不能发布的结论

可放主表：标明 revision、U280、Vivado 2021.1、完整 shell、post-opt/pre-route 的 LUT/register/BRAM/URAM/DSP/CARRY8，以及一致阶段的层级拆分。资源数字是实际工具报告，不是面积分析模型，但物理实现尚未成功。

功耗只可放明确标注 vectorless、pre-route、assumptions 的补充估算，且必须披露 reset/activity 问题；失败 route 的 15.350 W 建议仅留审计/失败分析，不进论文 Hardware Overhead 主表。没有 vector-based 数据时不声称测得功耗或能效改善。

不可发布为已完成结果：最终 post-route area、timing-closed Fmax、U280 measured board power、完整 PALIMPSEST hardware overhead、相对 PEEK/ParaMedic 的匹配净增量百分比、以 FPGA LUT 换算的 28 nm ASIC mm²。本文既有 0.4884 mm² SRAM/GE 分析模型与本轮 FPGA mapped resources 属于不同证据边界，不互相“验证”。

论文成品：`latex/hardware_overhead_table.tex`；`latex/hardware_overhead_analysis.tex`。默认主表只有资源，不把有问题的功耗估算塞入主资源表。英文段落已区分未闭合物理实现、vectorless estimate 与实测。

## 复现与本轮操作

1. `python3 scripts/archive_reports.py`：只读 R6，复制/校验报告和 checkpoint。
2. `python3 scripts/archive_context.py`：保存独立 Native 上下文、revision profile 与绑定验证。
3. `python3 scripts/inspect_checkpoint_constraints.py`：只读 DCP 内嵌 XDC，保存实际 IP 活动约束。
4. `python3 scripts/extract_results.py`：仅从 snapshot 提取 CSV/LaTeX，核对层级分组总量。
5. `python3 scripts/write_audit.py`：刷新本审计；`python3 scripts/verify_artifacts.py` 校验 snapshot、算术、引用并生成 artifact SHA256 清单。

补充功耗的确切命令在 `generated/placed/invocation.json`；Tcl 在 `scripts/report_preroute_power.tcl`。只打开独立 placed DCP，调用 report，不运行 synth_design/opt_design/place_design/phys_opt_design/route_design，不写 checkpoint、不打开原 project、不接触板卡。限制 2 threads、CPU 252/253、nice19、96 GiB 地址空间、30 min timeout，启动前检查可用内存与 load；不杀/重启既有进程。

原始报告和 checkpoint 已独立保存，SHA256 可复核。Native 数字仅标为 reference context。所有新文件限定于 paper-area-power；既有 RTL、实验配置、运行状态与 CAD 输入不修改。
