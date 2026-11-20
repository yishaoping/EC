# 最终 Opt4 FireSim 双 FPGA 实验统一入口

更新时间：2026-11-07T02:06:04.396369+00:00。用户已确认两卡可用并明确授权部署；本次覆盖此前“仅交接、不构建、不运行”限制。

**有效 FPGA PARSEC 样本 5，有效 smoke 3，正式样本 3。** 构建完成、部署完成、OpenSBI 启动、Linux 启动、ROI 验证分别记录，不互相替代。当前运行样本见 [campaign-state.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/campaign-state.json)。

## 最终硬件绑定

- 冻结 commit `8491167d84b6d9521b151a743673c1516926a1f8`，tag `opt4-final-performance-fpga-20261106`，branch `frozen/opt4-final-performance-20261106`；未修改。
- 冻结源码备份 `/data1/gzh/EC-backups/opt4-final-performance-20261106/source/chipyard`。
- 本次 Correction 实际输入 `/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard`，source_id `c9f51d3a94aac7783c750682162cd25e9d1460b04974bde9b7541f1d9f4120e7`。
- [hardware-revalidation-20261106.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/hardware-revalidation-20261106.json) 核验实际 1,914 项核心源码：1,908 项与冻结逐字节相同，六项平台集成差异完整记录在 [frozen-to-firesim.patch](/data1/gzh/EC/firesim/final-opt4-20261106/frozen-to-firesim.patch)，patch SHA256 `53de40eafec804db9b87250ae75fcd9855a7c50636feaabd46f6e53083961265`。
- `v1Config`、4 checkers、SVB32、L2 report-permission repair；[goldengate-functional-witnesses.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/goldengate-functional-witnesses.json) 记录实际 GoldenGate SV 的 SVB 第32槽和四个 L2 MSHR 修复逻辑。不是凭工作目录名称判版本。
- [integration.json](/data1/gzh/EC/firesim/final-opt4-20261106/integration.json) 绑定 elaborate → GoldenGate → 原始 driver。旧 opt4-linux-v6 只作 checkpoint/tool lineage，不是本次 C4 DUT 输入。
- FireSim 上游 1.17.0 `07efa6a6da18bd64d1159ae84a4701b37abb1228`，兼容集成 checkpoint `7345ef3cf162c311153d7d0db983da22361b181b`；Vivado2021.1。环境 `/data1/gzh/EC/firesim/envs/manager-1.17.1` 名字不代表上游版本。
- Native `/data1/gzh/EC/firesim/final-opt4-20261106/Native/chipyard` 为单 BOOM、零 Rocket checker，source_id `be443a3dc2992eb52be4d3da55d687e13e9a21a0dccc1d136a2f23c2c3f436e4`；[native-reuse.json](/data1/gzh/EC/firesim/final-opt4-20261106/native-reuse.json) 逐项核验87项既有产物。Native bitstream SHA256 `bbe70b655538fa8d17deb72c4307ac66167ee0510aa12d0270ce2c9e37a34aea`，不作为 Opt4 产物。

## 构建与空间

最终 C4 compile、parameters、elaboration、GoldenGate、原始 host driver 全部完成，证据 [C4-build-state.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/C4-build-state.json)。最终 bitstream **RUNNING**，不宣称已完成。

- CAD PID/PGID `3969606`，自动状态 [C4-cad-state.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/C4-cad-state.json)，输出 `/tmp/guozh-firesim-final-opt4-20261106/C4-bitstream-20261106T112129.447082Z`，日志 `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-bitstream-20261106T112129.447082Z`。
- CAD 使用与 /data1 不同文件系统的 `/tmp/guozh-firesim-final-opt4-20261106`，逻辑入口 `/data1/gzh/EC/firesim/final-opt4-20261106/cad-work`。启动可用 231.6 GiB，最近自动快照可用 228.0 GiB，保留80GiB启动守卫、60GiB停止余量和120GiB增长预算，没有只降阈值启动。
- 原综合在HOptDfg reconvergent graph合并耗时，10秒perf采样491项、无丢失，见 [cad-synth-profile-report.txt](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cad-synth-profile-report.txt)。原构建保留；独立RuntimeOptimized候选状态 `RUNNING`，[C4-runtime-cad-state.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/C4-runtime-cad-state.json)，同最终RTL/driver/50MHz约束，仅改变支持的综合directive；[runtime-cad-variant.patch](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runtime-cad-variant.patch) 保留脚本差异。仅选择完成全部实现/时序并通过原来源核验的候选；选中receipt `None`。不把任一在途候选称成已生成bitstream。
- 仅清理旧废弃 `opt4-linux-v6/builds/C4-bitstream-20261103T105502.826002Z/.Xil/**/*.rtd`，释放 14.99 GiB；/data1 清理前 47.27 GiB、后 62.26 GiB。完整清单 [cleanup.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/batches/Native-20261106T113308Z/cleanup.json)，所有日志、报告、manifest、DCP、源与既有bitstream保留。
- host-only derivative `/data1/gzh/EC/firesim/final-opt4-20261106/runtime/Native-observed-driver.json` 和 `C4-observed-driver.json` 已编译：启用五项FASED寄存器读回、5秒print流刷新。原始 driver/源码/RTL不改，差异和父receipt独立绑定。编译不等于runtime读回通过。

## 双卡部署与真实启动

| BDF | U280 JTAG序列号 |
| --- | --- |
| `0000:e2:00.0` | `21770433G001A` |
| `0000:21:00.0` | `21770433G02LA` |

XDMA编号会在重新枚举后变化，运行必须由BDF解析，不固化xdma0/1。统一维护采用两卡均无具体设备冲突后 unload既有xdma → 两卡程序加载 → insmod既有模块poll_mode1，不更新系统驱动/板卡flash，不重启服务器，不停止他人进程。

- 初次工具误报已作废：Vivado interactive Tcl 在 `close_hw_target` 报错后仍返回0；[deployment-verification.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/batches/Native-20261106T113308Z/deployment-verification.json)。该次smoke停在wait_for_init，未启动Linux，失败原证据保留。
- 部署工具独立修复 `/data1/gzh/EC/firesim/final-opt4-20261106/deployment-tools`：batch模式、可选target关闭、强制serial/file成功见证、失败后恢复PCIe可见性。
- 既有他人 `hw_server:3121` 刷新后无目标；未终止它。本任务自有root `hw_server:3122` 可见两块准确序列号，证据 [jtag-discovery-3122.log](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/jtag-discovery-3122.log)、[owned-hw-server-3122.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/owned-hw-server-3122.json)。
- 最近部署 [latest-deployment.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/latest-deployment.json)，两卡真实 `program_hw_devices` 完成证据位于最新batch的 `program-Xilinx_*.log`。当前最新部署状态 `DEPLOYED_NOT_RUN`，开始于 `2026-11-06T12:53:54.647621+00:00`。
- Native 已在真实 FPGA 启动 OpenSBI v0.8 和 Linux 6.2，smoke及Blackscholes test已实际通过，见下方有效样本。早期错误ISA元数据panic和UART波特率不匹配的失败原证据保留。[linux-isa-metadata-repair.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/linux-isa-metadata-repair.json) 与 [uart-baud-repair.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/uart-baud-repair.json) 分别记录两组软件DT修复；不改冻结DUT。
- 发现 `earlycon=sbi` 已在DT请求但内核未选 `CONFIG_RISCV_SBI_V01`，已构建两组相同早期控制台增量内核，保留原输出；分别 `software/{Native,C4}/earlyconsole-kernel-build.json`。新的固件receipt与每次run manifest绑定。

## 软件与运行命令

- PARSEC `/data1/gzh/EC/Software/PARSEC` commit `a06d35960951c9bfad61eb4826bca8d167f98c19`。[apps-build.json](/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-build.json) 为真实静态Linux RISC-V ELF、原算法serial单线程、O3 rv64gc，官方test/simsmall的argv/输入hash/参考输出绑定。
- 共用不可写initramfs `/data1/gzh/EC/firesim/final-opt4-20261106/software/rootfs-20261106T100529Z/initramfs.cpio`，SHA256 `a33e7b7d5a6ae0810b69c91b9b256fa8c2a5a6376cd76ac865b26048dfb5aff1`。每卡guest RAM/rootfs独立；不共享可写块镜像。
- 两组硬件均为16GiB `[0x80000000,0x480000000)`、36位物理上限、SECTION27；当前共同Linux profile见 [matched-guest-mem2g.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/matched-guest-mem2g.json)，统一 `mem=2G`。Native UART实际Linux范围 `[0x80200000,0x100200000)`（OpenSBI保留最初2MiB），C4还需对应运行核验。首批输入预算覆盖Blackscholes simmedium等，峰值尚未测量。16GiB无cap和诊断profile不混计。
- 正式Blackscholes官方simmedium（16384 options、NUM_RUNS100、serial单线程）已准备，[formal-apps-build.json](/data1/gzh/EC/firesim/final-opt4-20261106/software/formal-apps-build.json) 的QEMU参考已实际执行并核对官方价格；尚需FPGA验证。独立 [formal-rootfs-build.json](/data1/gzh/EC/firesim/final-opt4-20261106/software/formal-rootfs-build.json)、`software/{Native,C4}/formal-kernel-build.json` 与逐run固件绑定；不混用原test/simsmall镜像。
- C4 DT仅Linux hart0，hart1..4为真实固件checker service；实验SBI扩展 `0x08004f50`。
- BOOM/uncore目标200MHz、checker100MHz；CAD宿主50MHz。slowdown只按目标ROI周期，宿主墙钟/吞吐单列。
- FASED `/data1/gzh/EC/firesim/final-opt4-20261106/runtime/fased-common/manifest.json` 显式统一LatencyBandwidthPipe，read/writeLatency30、read/writeMaxReqs4、relaxFunctionalModel0；新采集器要求5项实际runtime读回相等。

以下为本次实际使用的入口，完整argv/PID/PGID/start_ticks、超时、日志均写在样本manifest/state。

```sh
cd /data1/gzh/EC
python3 firesim/final-opt4-20261106/scripts/build_bitstream.py
sudo python3 firesim/final-opt4-20261106/scripts/board_batch.py --deploy-only
sudo python3 firesim/final-opt4-20261106/scripts/run_isolated_sample.py Native smoke test --bdf 0000:21:00.0 --timeout 600
```

`board_batch.py`进行全局维护，仅两卡无任务时运行；`run_isolated_sample.py`只运行目标卡，不重载、重扫或部署。全局维护独占锁与各实例共享维护锁互斥，各卡另持独立锁。

## Streamcluster与未解决接口

- 原Streamcluster ROI含stderr write及输出fopen/fstat/write/close，C4 `user_no_trap_one_mm` 不接受ROI中trap/非U态/satp变化；该缺口是真功能限制，未忽略syscall或缩掉有效计算。
- 软件接入候选 [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/streamcluster-staged-diagnostic-20261106T115645Z/result.json) 保留原ROI hook位置、数学计算、输入生成和输出格式化，将文件open/close及外部写延后，日志写内存流，预置分配驻留。QEMU test/simsmall均与原版输出hash一致、原ROI内未见同步syscall。仅诊断ELF，尚未装FPGA镜像；需两组同用并标记staged IO，不能称原版正式结果。
- Canneal/Blackscholes test软件诊断原ROI未见同步syscall，但异步中断/实际checker/drain仍待板级验证。优先Blackscholes取得有效首组。
- C4当前固件每boot一个ROI，尚不支持同guest多ROI。原Native observer不接受driver重启后的非零bridge序号，失败证据保留。独立 `runtime/Native-restart-driver.json` 保留实际绝对序号及每stream偏移，收集器必须看到新target reset才允许后续ROI；[native-restart-runtime-validation.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/native-restart-runtime-validation.json) 为实际smoke通过证据。C4没有该重启证明，当前保守采用样本间统一重新部署；全局维护仍须等两卡结束。
- [fpga-continuation-state.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/fpga-continuation-state.json) 为已启动的最终C4实际续跑进程：只等待本次bitstream成功，等两卡结束后统一Native/C4部署，依次执行C4 smoke、小输入及3次simmedium。任一步具体失败即停并保留证据，不放宽有效性检查。Native正式重复批次由 `run_repetitions.py` 运行，完整状态位于 `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/sampling-batches`。
- 重启后host clock累计计数不会自动清零，原driver的吞吐率summary不能直接用作单次吞吐。独立 `runtime/C4-efficiency-driver.json` 增加host-only起止差值采集，原驱动/RTL不改。体系结构slowdown始终仅使用有效ROI目标周期。
- 严格latency缺同一单元BOOM执行完成与Rocket真比较完成的统一时基配对，保留null；PACKAGE_BEGIN不算BOOM完成。
- PACKAGE_RESULT waiting路径observer字段有限；实际收集要求正的generated=completed=passed、0fault/failed/cancel/drop/outstanding、真实full_compare事件、全部task匹配、firmware parked15。缺一则失败，不产生有效标记。
- C4软件driver已增加真正DRAIN及firmware park之后读取既有128项traffic寄存器；独立增量kernel/payload实际已构建、尚未上板。[traffic-counter-map.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/traffic-counter-map.json) 给出冻结源码的索引及指标含义，[manifest.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/traffic-readback-integration/manifest.json) 记录软件补丁，不改DUT。内存回写/安全水位cycle sum不冒充严格checker latency。利用率及队列占用缺已验证运行接口，明确缺失。
- 真实Check源码证据 [real-check-source-audit.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/real-check-source-audit.json)，尚未FireSim构建；不阻塞Native/Correction。2/8checker、面积和消融后续处理。

## 样本证据与恢复

| 组 | 程序输入 | 状态 | ROI周期 | 原始结果 |
| --- | --- | --- | --- | --- |
| Native | blackscholes simmedium | 有效 | 829737734 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-blackscholes-simmedium-r1-20261106T125841Z/result.json) |
| Native | blackscholes simmedium | 有效 | 828230479 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-blackscholes-simmedium-r2-20261106T130737Z/result.json) |
| Native | blackscholes simmedium | 有效 | 829885720 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-blackscholes-simmedium-r3-20261106T131036Z/result.json) |
| Native | blackscholes test | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-blackscholes-test-r1-20261106T124955Z/result.json) |
| Native | blackscholes test | 有效 | 208702 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-blackscholes-test-r1-20261106T125530Z/result.json) |
| Native | canneal test | 有效 | 24480 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-canneal-test-r1-20261106T131219Z/result.json) |
| Native | smoke test | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T113339Z/result.json) |
| Native | smoke test | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T114605Z/result.json) |
| Native | smoke test | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T120448Z/result.json) |
| Native | smoke test | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T121201Z/result.json) |
| Native | smoke test | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T121323Z/result.json) |
| Native | smoke test | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T122201Z/result.json) |
| Native | smoke test | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T122810Z/result.json) |
| Native | smoke test | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T123007Z/result.json) |
| Native | smoke test | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T124105Z/result.json) |
| Native | smoke test | 有效 | 5772 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T124817Z/result.json) |
| Native | smoke test | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T125842Z/result.json) |
| Native | smoke test | 有效 | 5871 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T130155Z/result.json) |
| Native | smoke test | 有效 | 5803 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T140002Z/result.json) |

运行目录 `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/<run-id>` 持续写UART/host/ROI或必要RTL事件，30秒state/snapshot刷盘；完整结果result.json与complete.json原子提交，绑定源码/硬件/软件/输入identity hash。快照不是指令级checkpoint。失败/超时/不完整保留，恢复只补缺项，正式统计排除不完整样本。

正式采样以有效标记为准：先smoke → Blackscholes test/小输入真比较验证 → 统一正式输入各一轮 → 初始3次重复。没有有效配对时不计算slowdown；Verilator历史1.1995×只作参考。长任务由程序持续保存，人工正常检查不少于5分钟；检查新增状态/log，不反复遍历进程或重算大产物hash。
