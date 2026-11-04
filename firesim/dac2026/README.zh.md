# DAC / Opt4 实验准备

**最新推进方式：B v5 已冻结，独立首跑不等待 C4 或 strict latency。**
准确命令、当前 bitstream 构建和两卡占用阻碍见
`/data1/gzh/EC/Experiment/dac2026/preparation/opt4-roi-v5/B-FIRST-RUN.zh.md`。
原 Opt4 裸机运行、checker 机制和 Linux 真正缺项见同目录 `C4-ORIGINAL-AND-GAPS.zh.md`。
首跑入口为 `scripts/b_v5_first_run.py`；旧 site.json/完整矩阵 gate 不用于 B 首跑。

当前主矩阵 **B、C2、C4、C8**；先打通 B/C4，之后推进 C2/C8、真实结构消融和 ASIC 面积。
check 检错实现不接入、不安排硬件构建或实验；历史源码及结果均保留。
本工具包尚未完成可启动的实验链路，不能用于产生正式论文结果。

本轮 C4 Linux checker 接入、阶段 A/B/C 入口及当前构建/阻碍见
`/data1/gzh/EC/Experiment/dac2026/preparation/opt4-linux-v6/C4-LINUX-AND-PARSEC.zh.md`。
C4 native Verilator 已构建完成并绑定在 `work/opt4-linux-v6/native-build.json`；Stage A/B/C 均只有准备记录，没有真实运行结果。native smoke 与 Blackscholes 的精确 attempt 命令见 `Experiment/dac2026/preparation/opt4-linux-v6/C4-LINUX-AND-PARSEC.zh.md`。
C4 Linux v6 的 FireSim parameters、elaboration、GoldenGate 和 U280 host driver 已构建；C4 bitstream 尚未构建，bitstream 脚本需 Stage A 与 native Stage B smoke 的有效运行凭据。
2026-11-02 15:20 UTC 只读 preflight 再次检出 e2/libquantum、21/hmmer FireSim workload，且当前用户有 4255 项 `/proc` 不可见，故安全入口拒绝启动。没有打开或触碰两卡，也未执行 `infrasetup`/`enumeratefpgas`。B v5 bitstream 已有成功 receipt；当前无 B Vivado 构建进程，B 保持冻结。
`slowdown/opt4` 与 B v5 冻结源码保持不变。

v3 兼容性证据见 `/data1/gzh/EC/Experiment/dac2026/preparation/opt4-alveo-v3/`；
B ROI 控制候选见 `Experiment/dac2026/preparation/opt4-roi-v4/`；
最新 raw passive bridge 候选见 `Experiment/dac2026/preparation/opt4-roi-v5/`。
可复制命令和本轮变更见 `Experiment/dac2026/preparation/PROGRESS-ROI-20261102.md`。各版本都没有真实运行通过样本。
原先选用上游 1.17.1、含 D 的安排已失效，历史文档在 `history/`。

## 源码身份与目录

- Opt4 身份目录：`/data1/gzh/EC/slowdown/opt4`，不是硬件源码目录。
- 冻结硬件源：`/data1/gzh/EC/chipyard/generators`，配置 `chipyard.v1Config`。
- 原构建入口：`/data1/gzh/EC/slowdown/run_optimization_4_svb.sh`。
- 功能提交 `476a760910f3bfbd3c111000ebe40343870ab439`；冻结提交 `962c4b87db2a810bc025a87f5f7289dd7aedc5cf`。
- 原 EC HEAD `2ea467ba08f773dd55b77383da9f4f5c025b9607`；冻结源码只读核验 626 项通过，见 `Experiment/dac2026/preparation/opt4-minimal-v2/opt4-source.json`。
- 活跃独立工作树：`firesim/dac2026/work/opt4-alveo-v3/{B,C4}/chipyard`。
- B ROI 新工作树：`firesim/dac2026/work/opt4-roi-v4/B/chipyard`。当前无 v4 C4；v3 的八阶段构建已重新核验，不能把它们当作 v4 的产物。
- B raw passive bridge 工作树：`firesim/dac2026/work/opt4-roi-v5/B/chipyard`，保留v4。v5首次GoldenGate失败及修复记录保留；以v5当前同一源码hash的四阶段receipt为准。
- 两个独立 FireSim clone 都在各自工作树的 `sims/firesim`；manager、硬件 Scala、GoldenGate 和 driver 必须来自同一组工作树。
- B 来源为上游 Chipyard 1.9.0 `7475bfb1a05802ac4dfc3990a889f93164b8d798`，BOOM `deae9f70469336a3787fa7fcc10135ffb93d21d9`。它是单 BOOM，无 Rocket/GuardianCouncil；只复制 Opt4 的 BOOM 参数，不复制纠错数据通路。
- PARSEC 参考 `/home/wtl/parsec_gc` 已复制到 `/data1/gzh/EC/Software/PARSEC`；修改副本为 `firesim/dac2026/work/parsec-20261102`。
- 依赖、源码、构建、软件镜像在 `firesim/`；日志、进度、实验数据和报告只在 `Experiment/`。

B/C4 的 v3 Chipyard 工作根是归档/复制树，FireSim 子目录是独立 Git clone。不要用工作根中向父目录回溯得到的 EC HEAD 冒充上游 Chipyard 或 Linux 提交；以 source-mapping.json、baseline-origin-git.json 和内容 hash 为准。

Opt4 指硬件实现，与编译器的 `-O` 等级无关。

## FireSim 兼容性与纯构建

Chipyard 原 gitlink `68e5113887d36e87bb6202e7fd1e7e51e786a91b` 已验证 B/C4 Scala 编译和目标生成，但该版本无 native Alveo。
当前 Alveo 候选为 **FireSim 1.17.0 `07efa6a6da18bd64d1159ae84a4701b37abb1228`**：按平台支持和 Chipyard API 选择，并在独立树适配；没有固定 1.17.1 或直接追随最新版本。
`firesim/envs/manager-1.17.1` 只是保留的独立工具环境目录名，不能据此推断实际 FireSim 版本。
具体每阶段结果以 `Experiment/dac2026/build-logs/opt4-alveo-v3/*/result.json` 为准。

当前 B/C4 均已通过参数审查、目标生成、native Alveo GoldenGate 转换和 native U280 driver 编译/链接；
driver 使用宿主 gcc/g++ 11.4.0，避免 Conda 旧 sysroot 与 Alveo native libc 混用。
driver 从未执行，bitstream 和时序实现尚未构建。

```bash
cd /data1/gzh/EC
python3 firesim/dac2026/scripts/build_minimal.py B parameters
python3 firesim/dac2026/scripts/build_minimal.py B elaborate
# 将上一条打印的日志目录/result.json 原样填入；必须来自同配置/同源码：
python3 firesim/dac2026/scripts/build_minimal.py B goldengate --input-result /绝对路径/B-elaborate-时间/result.json
python3 firesim/dac2026/scripts/build_minimal.py B driver --input-result /绝对路径/B-goldengate-时间/result.json
# C4 逐条执行相同阶段，将 B 改为 C4。
```

脚本只编译，不启动目标、不访问设备。一次一个构建，Java 2 CPU / 8 GiB（GoldenGate 16 GiB），make -j1，nice15，含内存/磁盘/负载检查。
每次记录源码内容 ID、FireSim commit、命令/环境、输入产物 hash、返回码及输出 hash。
GoldenGate/driver 拒绝无明确上一阶段证据或源码已变的产物。所有失败日志保留。

两组 BOOM 同为 fetch8/decode3、ROB42、PRF128/128、LQ/SQ16、L1I 32KiB/8way、L1D 32KiB/2way/6MSHR、L2 1MiB/16way/outerLatency12。
共同策略将 nPerfCounters 设为29，并关闭 commit/branch/memory 调试打印；BOOM/系统200MHz、Rocket/GC100MHz。
`useSupervisor=false,useVM=true` 在 RocketChip `hasSupervisorMode=useSupervisor||useVM` 下仍提供 S-mode，不构成 Linux 缺少 S-mode 的证据。
FASED 当前结构为 LatencyBandwidthPipe。**最终 RTL 的默认 max requests 为 B=4、C4=6，不能直接使用各自硬件默认值。**
已固定候选共同设置 read/write latency=30、read/write max requests=4、relaxFunctionalModel=0：
`config/firesim/memory-opt4-alveo-v3/fased-common.args`，对应 manifest 记录生成 RTL/寄存器证据和 hash。
两组均须传入全部五项参数；200MHz 下请求的 latency=150ns。此模型没有独立 bandwidth 运行寄存器，不能称为 FRFCFS。
这里只完成生成产物的静态核对，实际寄存器读回、时序及吞吐验证待用户运行。

## 软件与测量状态

已编译的静态 RV64GC 短程序和 blackscholes：
`firesim/dac2026/images/opt4-minimal-v2/20261102T052203Z`，含 input_test/in_4.txt 与 input_simsmall/in_4K.txt 的 hash、二进制/源 hash 和反汇编证据。该目录名字不是硬件版本绑定；最终 campaign 必须明确引用其 manifest。

**尚未执行**；基础 BusyBox/Linux/generic OpenSBI 和仅供 B 的交互 initramfs/DTB/payload 已编译，
证据见 `Experiment/dac2026/preparation/opt4-alveo-v3/software-build-status.json`。
这些不是已准入的实验 Linux/checker 镜像。v3 仍无 ROI 控制设备、checker 服务或完整被动测量桥。
新 v4 已实现 B 的源域 marker 控制器和 MMIO 外设，硬件生成及 GoldenGate 转换通过；
B-only ROI 驱动也已编译入独立 Linux。含静态短程序/输入的候选镜像仍须核验对应构建证据。
C4 驱动接入被明确拒绝，等待真实 Linux/checker 上下文协议。
v5新增真正的 B raw passive bridge 与 C++ bridge driver，参数/目标生成/GoldenGate/native driver四阶段及内容核验已通过；
实现了按宿主周期请求源域快照、逐记录fsync后才确认出队，但这些运行时行为尚未执行验证。
它尚未关联正式sample/job身份和输出校验，不能提交正式完成标记。
详见 `measurement/linux/README.zh.md`、`measurement/hardware/README.zh.md` 和 v4 进度报告。
基础构建可复现命令见 `images/README.md`；init 不会自动运行应用。
短程序和 PARSEC 的 hooks 要求真实 `/dev/ec_dac_roi`；设备缺失时退出125，不会回退为宿主时间或虚假 ioctl 成功。

Slowdown 为共同输入/二进制/线程和配置下，纠错 ROI 目标时间除以真实单 BOOM B 时间。
校验单元是 Opt4 producer 封口的 package，用 `(epoch,packet_seq)` 关联；延迟为存活成员最大原始执行完成时间到 Rocket 第一次完整 PASS 比较完成的时间。
提交只证明成员存活，result dequeue 只证明释放，两者都不能替代定义中的完成事件。
B 的校验延迟明确为 N/A。详细接线与验收合同见 `measurement/INTEGRATION.md`，合同/离线参考模型不是已实现硬件。

## 用户手动验证入口与当前限制

以下是工具入口；**真实 bridge、Linux/checker、产物清单和安全部署 adapter 未完成前会退出2，当前没有可以成功启动 B/C4 仿真的准确命令**。
不能把填入几个 ready=true 或 `firesim --help` 成功当作链路完成。

```bash
cd /data1/gzh/EC
source firesim/dac2026/env.sh
python3 firesim/dac2026/dac.py preflight
python3 firesim/dac2026/dac.py plan --campaign opt4-link-v3 --stage link --configs B C4 --benchmarks roi-smoke blackscholes --reps 1
# 仅当上述证据准入实际通过后，由用户启动：
python3 firesim/dac2026/dac.py stage --campaign opt4-link-v3 --stage link --execute
```

设备操作当前被安全门槛阻断。两块 FPGA 可能已有任务，未证明单卡隔离安全；选中一张卡也不能允许全局 XDMA 卸载/重载。
本工具不调用 infrasetup/enumeratefpgas，不烧写/复位/解绑/重扫，不启动 FireSim、RTL、QEMU、Spike 或 benchmark。

软件输入在 guest `/opt/ec-dac` 安装完成后，短程序预期输出 `DAC_SMOKE checksum=500500 expected=500500`；blackscholes 分别运行 `1 in_4.txt prices.txt` 与 `1 in_4K.txt prices.txt`。
`guest/verify_reference.py --mode blackscholes --atol 0.0001` 根据输入第9列 DGrefval 校验输出个数、有限数值和精度；短程序必须检验 checksum。
这些是待运行预期，不是真实输出证据。

v4 候选 initramfs 增加了 guest 内手动前置验证脚本（不会自动启动，也不提交正式样本）：

```bash
# 以下只在用户已手动启动且 B ROI 设备实际绑定的 guest 交互 shell 中执行：
/opt/ec-dac/manual-link.sh smoke
/opt/ec-dac/manual-link.sh test
/opt/ec-dac/manual-link.sh simsmall
```

脚本核验二进制/输入 SHA256，检查 smoke checksum；blackscholes 使用同一输入第9列参考值，
要求输出个数正确、数值有效、每项绝对误差严格小于1e-4。
它们是 guest 前置验证命令，不是当前可执行的宿主仿真启动命令；未接通真实宿主统计前不产生正式数据。

## 持续保存、中断与补跑

宿主 collector 采用带边界/校验的追加 journal 并 fsync；默认每20秒保存累计快照，结束时原子提交完整结果及绑定源码/配置/软件/输入的完成标记。
连续三个快照间隔无新硬件统计时失败；只存 guest 文件或关机后回收不符合准入要求。
每个样本全量记录 ROI、延迟直方图、生成/完成/异常/未完成数、末尾排空、队列、阻塞和 checker busy；部分样本保留但不进入正式数值。
当前 collector/ledger 的离线合同测试通过，不代表硬件持续采集已接通。
本轮宿主离线检查累计35项通过，日志 `Experiment/dac2026/preparation/opt4-roi-v5/host-offline-tests.log`；
包括新增raw日志完整前缀/中断尾行与输出校验，不执行目标程序。

在真实链路通过后由用户执行：

```bash
python3 firesim/dac2026/dac.py plan --campaign opt4-recovery-v3 --stage recovery --configs B C4 --benchmarks roi-smoke blackscholes --reps 2
python3 firesim/dac2026/dac.py run --campaign opt4-recovery-v3 --config C4 --interrupt-after 1 --execute
python3 firesim/dac2026/dac.py recover --campaign opt4-recovery-v3
python3 firesim/dac2026/dac.py status --campaign opt4-recovery-v3
python3 firesim/dac2026/dac.py pending --campaign opt4-recovery-v3 --configs C4
python3 firesim/dac2026/dac.py run --campaign opt4-recovery-v3 --config C4 --execute
```

有效性判据：已完成样本 hash 和完成标记不变；中断样本整项重跑，attempt 增加；补跑仅选择缺失/失败项；最终 generated=completed、outstanding=0、零丢失/异常/溢出、排空及输出验证通过。
快照不是指令现场检查点。运行中止只终止本工具启动的 adapter 进程组，不能终止现有他人任务。

```bash
python3 firesim/dac2026/dac.py analyze --campaigns opt4-link-v3 --out /data1/gzh/EC/Experiment/dac2026/analysis/opt4-link-v3
```

分析以有效完整样本及共同 benchmark 集合计算 B/C4 默认组和 B/C2/C4/C8 数量扫描，缺失/失败/中断显式列出；B 延迟为 N/A。分桶分位数报告区间。
跨阶段复用公共 B 必须使用 hash 固定的共同比较上下文及每配置准入证据，详见 `measurement/COMPARISON.md`；
完整样本身份和运行时 source/site/kit 门槛仍严格绑定，旧完成标记不会自动获得新配置身份。
C2/C8 的具体改动和协议阻碍见 `Experiment/dac2026/preparation/opt4-alveo-v3/C2-C8-review.md`。
ASIC 面积独立于 FireSim 观测逻辑，等待共同库/时钟/内存处理条件；FPGA 资源不能冒充 ASIC 面积。
