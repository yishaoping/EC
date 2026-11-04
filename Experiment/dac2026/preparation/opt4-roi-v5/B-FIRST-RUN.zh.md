# B v5 首次运行入口

B v5 功能源码冻结，source_id=`be443a3dc2992eb52be4d3da55d687e13e9a21a0dccc1d136a2f23c2c3f436e4`。
不等待 C4、严格 latency、通用批量框架或图表。本文所有启动操作由用户执行。

## 当前状态与具体缺项

| 产物/条件 | 状态 |
|---|---|
| 单 BOOM 目标参数、elaboration、GoldenGate、native driver | 已通过；四阶段同一 B v5 source_id |
| B Linux、initramfs、OpenSBI、内嵌 DTB、短程序、PARSEC test/simsmall | 已编译并核验内容；未启动 |
| Host 动态依赖 | `/usr/bin/ldd` 全部可解析；未执行 driver |
| B 最短手动 launcher、live raw 日志、smoke verifier | 脚本已生成；静态语法/路径/内容核验；未启动 |
| B v5 bitstream | 当前为实际 CAD 构建，见下方准确日志；成功与否只以 result.json 为准 |
| FPGA 安全部署 | 当前不具备：21:00.0 和 e2:00.0 各有 FireSim driver，另有 manager；还有 /proc 权限不可见项 |
| 首次 Linux→smoke→ROI→host→正常退出 | 待用户运行；当前真实运行通过数为 0 |

首次 bitstream 尝试 `B-bitstream-20261102T095254.993088Z` 已失败并保留日志：
`[Board 49-71] board_part ... au280:part0:1.2 ... not found`。
已在独立 `firesim/dac2026/deps/boards/au280/1.1` 复制服务器自带的 AU280 定义，
其 FPGA part 同为 `xcu280-fsvh2892-2L-e`，XML 明示物理 board revision=1.2、definition file_version=1.1。
只在独立 CAD 副本选择实际存在的 part0:1.1 并设置 board.repoPaths，没有改 B 功能源码或服务器公共 Vivado 安装。
对应证据 `u280-board-definition.json`。

当前构建目录：

```text
/data1/gzh/EC/Experiment/dac2026/build-logs/opt4-roi-v5/B-bitstream-20261102T095746.955739Z
/data1/gzh/EC/firesim/dac2026/work/opt4-roi-v5/builds/B-bitstream-20261102T095746.955739Z
```

采用 FireSim 1.17.0 原生 U280 `main.tcl`、BD、综合和要求时序通过的实现流程；jobs=2、主 Vivado maxThreads=2、nice=15。
FPGA host clock=50 MHz；目标 BOOM/uncore 仍为 200 MHz，host clock 不能用于体系结构 slowdown。
原平台的 OOC Vivado 子进程由其 run 脚本启动，不能把主进程 maxThreads 当作所有子进程总 CPU 数。

## 源码、工具和产物对应

硬件及 manager 源码根：
`/data1/gzh/EC/firesim/dac2026/work/opt4-roi-v5/B/chipyard/sims/firesim`。
实际 FireSim=`07efa6a6da18bd64d1159ae84a4701b37abb1228` / 1.17.0。
依赖环境 `/data1/gzh/EC/firesim/envs/manager-1.17.1` 只是历史目录名。
独立安装仍使用正常 Chipyard→GoldenGate→FireSim native platform 集成。

driver：
`firesim/dac2026/work/opt4-roi-v5/builds/B-driver-20261102T093023.904481Z/FireSim-xilinx_alveo_u280`。
payload：
`firesim/dac2026/work/software-v3/builds/firmware-20261102T085039.525331Z/platform/generic/firmware/fw_payload.elf`。
payload 内已有 kernel/DTB/initramfs，不需额外磁盘镜像。v4 软件复用到 v5 的 DT 一致性和 payload hash 见
`software-reuse-v4-v5-corrected.json` 和 `B-raw-bridge-compile-content-verified.json`。

旧 `config/site.json` 和 `env.sh` 是 v3 完整矩阵入口，不用于本次 B 首跑。
新脚本 `scripts/b_v5_first_run.py` 直接绑定上述 B v5 receipt，产出 plan.json；不经过旧的 C4/latency 前置门槛。

## 1. 检查构建与两张卡（只读）

```bash
cd /data1/gzh/EC
tail -n 30 Experiment/dac2026/build-logs/opt4-roi-v5/B-bitstream-20261102T095746.955739Z/build.log
cat Experiment/dac2026/build-logs/opt4-roi-v5/B-bitstream-20261102T095746.955739Z/result.json

# 部署或运行前重做；需要管理员可见性，不得拿普通用户的空 FD 列表证明空闲。
sudo /usr/bin/python3 firesim/dac2026/scripts/b_v5_first_run.py preflight \
  --out /data1/gzh/EC/Experiment/dac2026/preparation/opt4-roi-v5/user-preflight-01.json
```

如果 result.json 尚不存在，构建仍在进行或被中断；先查 build.log 和进程，不要启动第二份相同构建。
仅当需要新建一次纯 CAD 构建时，入口为：

```bash
/usr/bin/python3 firesim/dac2026/scripts/build_b_v5_bitstream.py
```

不会调用 driver 或任何设备。每次创建新的独立输出和日志，不覆盖当前构建。

本次 preflight 已保存为 `first-run-preflight.json`：
`0000:e2:00.0` 的 driver PID=1970507，`0000:21:00.0` 的 driver PID=2861930；manager PID=1967655。
PID 为本次快照，不能作为将来占用判据。BDF/serial 映射来自只读 `/opt/firesim-db.json`：
e2→21770433G001A，21→21770433G02LA，仍须在未来维护窗口核对实际部署身份。

## 2. 部署条件

当前禁止部署。两张卡有实际任务，且普通用户存在 /proc 不可见项；没有安全烧写命令可以在此状态直接执行。
原 native `fpga-util.py` 的按 BDF 编程路径包含 PCIe remove/rescan，manager infrasetup 还有全局 XDMA 风险，
所以本工具包不调用这些入口，也不提供忽略检查的开关。

下一动作是：在已有任务自然结束并获得明确独占维护窗口后，以管理员可见性重查两卡，
确认目标 BDF/serial、当前驱动、PCIe 编程恢复的影响范围，再选择能保持约定范围的部署路径。
不能通过选一张卡或直接调用 JTAG Tcl 绕过 PCIe/XDMA 影响检查。
若需要 remove/rescan 或驱动变更，须先单独解决部署范围问题；当前 launcher 不包含这些操作。

`config/B-v5-deployment-record.template.json` 只用于记录**已经实际安全部署**的 bitstream hash、BDF、serial、operator 和独占有效期。
模板不是部署证据，不应填成“已部署”来绕过条件；该声明无法用软件自动读回证明芯片里是哪一份 bitstream。

## 3. 生成并执行 B 独立启动命令

以下 prepare 只在 bitstream 构建 result.json 已存在且通过时成功；该条件与 C4 无关。
示例选 21 卡仅用于展示完整 BDF，不代表该卡当前空闲。

```bash
cd /data1/gzh/EC
/usr/bin/python3 firesim/dac2026/scripts/b_v5_first_run.py prepare \
  --bdf 0000:21:00.0 \
  --bitstream-result /data1/gzh/EC/Experiment/dac2026/build-logs/opt4-roi-v5/B-bitstream-20261102T095746.955739Z/result.json \
  --out /data1/gzh/EC/Experiment/dac2026/first-run/B-v5-smoke-01
```

prepare 会打印完整 native driver argv，并将 driver、firmware、FASED、bitstream 和源码 receipt 的 hash 绑定到 plan.json。
不执行 driver。当前另有不含 bitstream 的命令草案 `first-run/B-v5-prepared-20261102/plan.json`，明确带 blocker，不能运行。

完成真实安全部署及独占记录后，由用户启动：

```bash
sudo /usr/bin/python3 /data1/gzh/EC/firesim/dac2026/scripts/b_v5_first_run.py run \
  --plan /data1/gzh/EC/Experiment/dac2026/first-run/B-v5-smoke-01/plan.json \
  --deployment-record /data1/gzh/EC/firesim/dac2026/config/B-v5-deployment-record.json
```

这条命令会启动仿真 driver，只访问计划中的目标 BDF；再次检查全部 FPGA 任务/FD/权限和独占有效期。
不烧写、不复位、不卸载/重载驱动、不做 remove/rescan，不调用 infrasetup/enumeratefpgas。
当前两卡占用状态下必定拒绝。操作管理员也不能跳过检测。

driver 实际参数包含：

```text
+domain=0000 +bus=21 +device=00 +function=0 +bar=0
+pci-vendor=10ee +pci-device=903f
+ec-dac-roi-log=<本次 run 目录>/roi-raw.jsonl +ec-dac-snapshot-seconds=20
+mm_readLatency_0=30 +mm_readMaxReqs_0=4 +mm_relaxFunctionalModel_0=0
+mm_writeLatency_0=30 +mm_writeMaxReqs_0=4
+permissive-off +prog0=<上述 fw_payload.elf>
```

## 4. Guest 短验证与宿主机收数

看到 OpenSBI、`Linux version ...`、`EC_DAC_B_ROI_CANDIDATE...` 和交互 shell 后，在 guest 执行：

```sh
/opt/ec-dac/manual-link.sh smoke
```

这是首次会话只运行的一个程序。预期包含：

```text
EC_DAC_PREREQUISITE_START mode=smoke formal_sample=false ...
DAC_SMOKE checksum=500500 expected=500500
EC_DAC_PREREQUISITE_END mode=smoke output_valid=true formal_sample=false
```

若 `/dev/ec_dac_roi` 未绑定、BEGIN/marker/END/DRAIN 失败或输出不对，脚本会非零退出，不能将该次当成功。
程序用真实 `/dev/ec_dac_roi` 和源 BOOM marker；没有替代性计时后端。

另一个 host 终端可以运行以下只读分析，不必等 driver 关机：

```bash
cd /data1/gzh/EC
/usr/bin/python3 firesim/dac2026/scripts/inspect_roi_raw.py \
  Experiment/dac2026/first-run/B-v5-smoke-01/roi-raw.jsonl \
  --out Experiment/dac2026/first-run/B-v5-smoke-01/roi-inspection-live-01.json \
  --allow-partial
cat Experiment/dac2026/first-run/B-v5-smoke-01/roi-inspection-live-01.json
```

应看到 epoch=1，states=[1,2,3,4]、faults=0、reset_seen=false、source_boundaries_complete=true、roi_cycles>0。
ROI 周期来自 end_tick−begin_tick，不预设数值，也不使用 host 墙钟。
raw JSONL 每条 fsync 后才确认消费；console.log 在运行期间 flush；宿主机目录中的 started.json/plan.json 保留来源。
B 的 generated/completed 恒为 0，原因是真实结构无 checker，且 B Linux 驱动还会检查这些寄存器为零；latency 不适用。

确认 host 已收到完整 ROI 后，在 guest 正常关机：

```sh
/bin/busybox sync
/bin/poweroff -f
```

已静态核验 DT 有 ucb,htif0、OpenSBI 有 HTIF reset，TSI bridge 依 FESVR done/exit_code 结束。
正常退出路径尚待实际验证；如果仅停在 Power down、没有 driver 退出，必须记录为未完成，不能用强杀假装正常退出。

driver 退出后在 host 执行：

```bash
cd /data1/gzh/EC
sudo /usr/bin/python3 firesim/dac2026/scripts/b_v5_first_run.py verify \
  --run-dir /data1/gzh/EC/Experiment/dac2026/first-run/B-v5-smoke-01 \
  --out /data1/gzh/EC/Experiment/dac2026/first-run/B-v5-smoke-01/smoke-result.json
```

有效条件：绑定产物未变、确有 launcher started、恰好一个完整无故障 ROI epoch、smoke 正确输出与结束标记、driver rc=0，
且无 observer 错误。成功结果 `status=FIRST_RUN_PASSED`、实际 `roi_cycles`、checks=0/0、latency=null、formal_sample=false。
这是 B 首次链路验证，不是正式 PARSEC 样本，也不证明 C4/slowdown/strict latency。

## 5. 中断与下一个小输入

短验证中断时保留整个 run 目录，`inspect_roi_raw.py --allow-partial` 可读完整前缀并显示尾部字节和不完整 epoch。
没有 `exit.json`、ROI 不完整、marker/output 不全都不会通过 verify。重新验证使用新的 `B-v5-smoke-02` 目录；
尚未实现进程执行现场恢复，也不把部分数据混入结果。

首次 smoke 通过后可在新的运行中使用 `/opt/ec-dac/manual-link.sh test`，再用 `simsmall`；
二者已在 payload 中，test 预期 `BLACKSCHOLES_OUTPUT_VALID count=4 absolute_tolerance=0.0001`。
当前 smoke verifier 只认证 smoke；PARSEC 结束标记和输出摘要的正式绑定随后加到有效 slowdown 阶段，不能借 smoke 认证。
长实验的周期快照、原子样本提交、只补缺项继续保留为后续工作，不阻塞本页短运行。
