# EC 真实数据三路线接续：2026-11-11 21:25 CST

唯一功能基线为 `8491167d84b6d9521b151a743673c1516926a1f8`。Native 保持暂停；任何 FPGA 操作仅允许 `0000:21:00.0` / `21770433G02LA`。本次检查和 CPU 接续没有操作 FPGA、驱动或 PCIe。

| 路线 | 已完成的真实结果 | 正在执行或待完成 |
|---|---|---|
| P0 原版 SVB 独立组件 | 连同 host/shell post-opt 200,342 LUT、12,790 CARRY8、3 DSP，容量 FIT；独立 spread 分支已保存 placed/physopt DCP | 原路由和独立 spread 路由均保持运行；尚无通过时序/DRC 认证的 bitstream，尚无 SVB FPGA 样本 |
| P0 Canneal 原版 GG metasim | 实际退出 0、输出正确；ROI 536,456 cycles / 392,248 instructions，总 1,759,002 target cycles，host 3,136.1126 s；131 个 local checker RESULT | BOOM accepted 独立 observer r3 正在运行，21:23 到 1,403,272 target cycles，未完成不认全排空；r5 全 payload trace 已接自动后继 |
| P1 真实 DCache 存储入口 MCRams | Plain 405,706 LUT → MC 24,192 LUT，省 381,514 / 94.037%；FF 65,886 → 32,721，CARRY8 均 250，DSP 均 0，BRAM 0 → 1.5 | 此为 35R1W81 ownerImageMemory 入口，含 written-mask/reset、35 captures；不是完整 DCache 或整机 FIT；独立 full-system 注释候选继续准备 |
| 完整 Opt4 | 最近完成 9ae9a7fc post-opt 2,847,382 LUT / 90,740 CARRY8 / 195 DSP，NOT FIT，超出 U280 1,543,702 LUT | e0c3737f DUT 综合继续，尚无该版本新整机容量报告；未产生完整 Opt4 bitstream 或 FPGA 正式样本 |

## 物理实现及自动上板

原组件来源 ID：`b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f`。独立物理分支只复用封存 post-opt DCP，没有重综合或修改目标 RTL。

- 原 CAD：`cycleprecise-frozen-svb-fpga-r2-20261111/cad-state.json`，实现日志在其 `cad-logs/implementation-attempt-1.vivado.log`。
- spread CAD：`cycleprecise-svb-spread-implementation-r1-20261111/`。`spread-placed.dcp` 和 `spread-physopt.dcp` 已真实生成。布局后 WNS +0.392 ns、WHS −0.554 ns，只是中间结果，不能作为时序通过。
- 原 route 有 level-6 拥塞和约 −6.568 ns 中间 WNS；路由仍有 overlaps 下降，不能称最终失败或时序通过。
- `ec-opt4-original-svb-spread-impl-r1.service` 独立 CPU254–255 / 64 GiB；原 CAD 不变。
- `ec-opt4-original-svb-onboard-r1.service`、`ec-opt4-original-svb-spread-follow-r2.service` 分别等待对应真实产物。获胜分支须验证实际 routed DCP 的时钟、setup/hold、DRC、bitstream、driver、trace 和来源哈希，再持有同一对 21 卡锁部署。
- 若已有完整 Opt4 认证产物或卡上活任务，组件实验等待安全边界。两个组件分支不能重复部署；只允许移交纯等待的部署控制器，不能终止 CAD 或卡上任务。
- 定向 trace 的 FPGA replay 比较 127 输出 × 333 已定义周期 = 42,291 值。完成后才允许生成 FPGA_VALIDATED 事件指标。当前 RTL 定向 capture→ACK 为 n=15、mean=17.733、median=18、P95/P99=32 target cycles，包含主动等待，不能作为应用延迟或峰值吞吐，也不是 checkerDone/架构恢复延迟。

## Canneal 对照与真实 trace

原 GG 完整工作负载：
`cycleprecise-frozen-full-metasim-sample-r1-20261111/{binding.json,result.json,host.log,rtl-prints-0,rtl-prints-1}`。
checker 本地结果分析：
`build-logs/Opt4-full-gg-package-analysis-round37-v1-20261111/result.json`。

独立原 target RTL 的同 ELF 运行记录为
`cycleprecise-frozen-canneal-20261111/result.json`：ROI 485,329 cycles / 392,248 instructions，136 BOOM accepted PASS、outstanding=0、尾排空 262 cycles。其 DRAMsim2 与 GG 的 FASED LatencyPipe30/maxReqs4 不同；ROI 差 51,127 cycles / 10.5345%，不能声称两者周期等价，也不能未经对照就把差异全归因于内存。

实际接续链：

1. r3 外部 observer 只重新编译 C++ main/relink 原 model archive；原 RTL、模型对象、ELF 和内存参数不变。完成后核对真实 BOOM accepted 的 seq/hart/status 与 local RESULT，未闭合的样本不提交全排空通过。
2. `ec-opt4-external-svb-r5-dispatch.timer` 每 300 秒有限检查，只在前继完整有效后提交一次 r5 完整 trace 作业，不与 r3 重复执行。
3. r5 连续保存 reset 起点、每一个实际 BOOM target edge、62 原始 emitted ports / 101 uint32 words（404 bytes/cycle），包括完整 512-bit payload、idle 和 backpressure，不压缩目标时间。
4. `ec-opt4-original-svb-replay-r1-dispatch.timer` 已真实安装启用。等待完整有效 r5 trace 且存在真实 capture/promote 后，向现有 broker 原子提交一次独立冻结 SVB replay。

启动预备已实际 PASS：
`cycleprecise-original-svb-binary-replay-r1-20261111/result.json`，10,000 实际 GG target edges，109,989 个定义输出 word 检查，0 mismatch，53 reset edges；真实修改 512-bit 数据的定向 mutation 被拒绝。启动阶段没有应用 SVB capture/promote，不能当作应用 replay 或 FPGA 样本。应用完整 replay、严格 checkerDone−BOOMDone 延迟及 architectural restart 尚未验证。

同一 GG 内存环境下完整 Plain/MCRams 对照仍实际运行：
`Opt4-route-a-full-mcrams-parity-round38-v1-state.json`，21:23 到 1,142,914 target cycles。应以最终周期、printf 和输出对照为准，不能由进程存活推断通过。

## MCRams 面积及证据稳定性

资源报告原件：
`build-logs/Opt4-mcrams-dcache-entry-area-r2-20261111/{PlainConfig,MCConfig}/{utilization.rpt,hierarchical.rpt}`。
周期对照原件：`build-logs/Opt4-mcrams-dcache-entry-r5-20261111/result.json`，两种配置各 2,569 target cycles / 178,857 定义值检查，独立 scoreboard、复位、读写冲突和数据 mutation 均保留。

旧面积控制器漏读 `CLB LUTs*`，误取 SLR 0 行，旧 0 LUT 数字无效。独立分析已按 total table、器件容量、hierarchy、primitive 和 blackbox 交叉核对，得到上述真实面积。另发现 r1 定时分析会重写已完成结果的 UTC，导致哈希漂移；其原始结果与本次 snapshot 保留。已只停用该轻量 timer，实际安装启用了 `ec-opt4-mcrams-entry-area-analysis-r2.timer`。r2 完成后反复校验原始 reports/receipts/RTL/DCP，仅更新 monitor-state；真实连续调用后 result SHA 保持 `34fc766d60d2aa577050e88f9fa125ab04096ac3df91494ad8e308f047598e4c`，入口为 `build-logs/Opt4-mcrams-dcache-entry-area-analysis-r2-20261111/result.json`。没有暂停 CAD、仿真或上板等待器。

21:27 CST，真实 ownerImageMemory-only 整机 Golden Gate 已由既有 broker 启动：`ec-opt4-auto-mcrams-owner-system-r1-3656aec4.service`，controller PID 950067 / start21535106，Java PID 951341 / start21535354。`Opt4-mcrams-dcache-owner-system-r1-state.json` 当前 `RUNNING/goldengate-owner-only`。原目标 FIR 字节不改，7450 个原 annotation 全保留，只新增一个 ownerImageMemory annotation；保留 35/518/4/4 读口及复位/写口。完成后须核对整个 post-bridge DCache 模块 hash，再继续真实面积与完整 target parity，尚不能称整机等价或 FIT。

## 无人值守及恢复

各状态入口见本目录 `snapshot.json`；它保存本次读取时间、原始状态副本、boot_id、PID/start_ticks、CPU/RSS 和状态文件哈希，不能当作指令执行检查点。

系统服务和 timer 独立于 VS Code/SSH；重连先核对领域状态、boot_id、PID/start_ticks。活任务只接管监控，不重复启动、不改输入。失败阶段保留原目录、日志及 DCP，在独立版本恢复；完整样本以 result/complete 及哈希绑定为准。常规合并检查不少于 300 秒，整机 CAD 不少于 600 秒。

监督器 `ec-opt4-unattended.service` 未重启。最新策略与 worker prompt 已加入 corrected area、SVB replay preparation、两个实际系统 timer 及物理分支入口。AI 新候选迭代仍受外部模型网络可达性约束；现有系统托管 CAD/metasim/确定性后继不依赖当前聊天存活。
