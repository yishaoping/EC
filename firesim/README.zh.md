# 本机 FireSim 使用说明

本次采用原地重构：将原 `upstream/` 中的官方 FireSim 提升到本目录，使用官方 Manager、YAML、工作负载和 target-design 机制。2026-11-27起，FireSim及下载依赖的源码全部作为普通文件纳入EC父仓库；本目录不再保留独立Git仓库或子模块gitlink。原 `dac.py`、site/readiness JSON、批处理调度及多层构建封装不再作为入口。没有迁入、修改外部 `../chipyard` 的最新 EC 硬件，没有生成 RTL、综合、布局布线、烧写或执行 FPGA 仿真。

## 版本必须成组维护

| 项目 | 固定来源 / 版本 |
|---|---|
| FireSim | `https://github.com/firesim/firesim.git`，1.17.1，`b473147af03edc854a5bc2a95d1bc404c8711b2a` |
| 配套 Chipyard | FireSim 官方 `target-design/chipyard` gitlink：`336f225143590f9060ebe7101e96f235f96db985`；其 CHANGELOG 为 1.10.0 系列 |
| BOOM | 配套 Chipyard gitlink `1a153d4974977a2d5f8baa9b4de51b3337d230fe` |
| Rocket Chip | `47f7b7144727f0340d511d35b9f6c7a91b2a276f` |
| FireMarshal | `f553a22b2831a37868e921afa98cf30a6c633a61` |
| Scala / Chisel | 2.13.10 / 3.5.6；SBT 1.8.2，Java 17.0.3，Python 3.10.9 |
| Vivado / RISC-V GCC | 2021.1 / 12.2.0；宿主驱动编译应采用系统 GCC，避免混用 Conda sysroot |
| 系统 XDMA / XRT | XDMA 2020.2.2，内核 5.15.0-139-generic；XRT 2.16.204（2023.2）。本平台走 native XDMA，未更新 XRT |

主工程中的 Chipyard 是上述官方固定版本。外部 `/data1/gzh/EC/chipyard` 是带 EC 修改的 1.9.0 基线，不是本工程的硬件输入。旧 EC 适配使用 FireSim 1.17.0 `07efa6a6da18bd64d1159ae84a4701b37abb1228` 加兼容补丁；它与干净主工程有不同源码身份。

不要单独升级 FireSim 或把外部 Chipyard 替换进 `target-design`。以后应先确定配套组合，再评估 EC 接口迁移。当前配对来自FireSim上游原始Chipyard gitlink，28项源码来源与精确提交保存在 `UPSTREAM_SOURCES.json`；已下载代码由EC直接跟踪。原 `.gitmodules` 改名为 `.gitmodules.upstream`，仅保留上游URL和可选依赖版本参考，不作为EC子模块配置。Chipyard内部反向的 `sims/firesim` 按官方standalone机制保持未初始化。

对应版本官方文档：<https://docs.fires.im/en/1.17.1/>。U280 文档也随源码保存在 `docs/Getting-Started-Guides/On-Premises-FPGA-Getting-Started/`。本机已有 FPGA 基础设施，不重跑文档中的系统安装、驱动和枚举步骤。

## 目录与配置

整理前：`upstream/`、`dac2026/{work,config,scripts,...}`、`final-opt4-20261106/`、`envs/`、失败的 `conda-env/`。

整理后：

```text
firesim/
  UPSTREAM_SOURCES.json         28项上游来源/pin；源码统一由 ../.git 管理
  sourceme-manager.sh, env.sh    官方初始化入口及本机环境选择
  deploy/
    config_build.yaml           要构建的硬件、构建农场
    config_build_recipes.yaml   官方硬件配方：DESIGN/TARGET_CONFIG/PLATFORM_CONFIG
    config_hwdb.yaml            保留比特流和配套预编译驱动
    config_runtime.yaml         运行拓扑、内存模型参数、工作负载
    bit-builder-recipes/        官方 FPGA 构建器
    build-farm-recipes/         官方构建主机机制
    run-farm-recipes/           官方运行主机机制
    workloads/                 官方 JSON 与镜像；含 legacy-native-ferret.json
    bitstreams/                两组历史参考产物；未作为新版 EC 默认设计
  sim/                         Golden Gate、桥、驱动和官方 Makefile
  target-design/chipyard/       与FireSim配套的硬件生成器，普通源码目录
  platforms/xilinx_alveo_u280/  U280 平台与本机必要板级定义
  sw/firesim-software           指向配套 FireMarshal 的官方符号链接
  conda-reqs/                  官方锁文件、local-explicit.txt 本机包清单
  envs/manager-1.17.1/          唯一 FireSim 用户环境，保留旧安装前缀
  .conda-env -> envs/manager-1.17.1
  docs/, scripts/, utils/, ... 官方目录
```

`envs/manager-1.17.1` 是历史命名，不能用它推断正在运行的源码版本。保留前缀是因为已有 ELF、共享库和外部历史证据引用它。`.conda-env` 是指向同一环境的链接，没有第二套环境。需要在新的用户目录复现包集合时，可运行 `conda create -p /新路径 --file conda-reqs/local-explicit.txt`，再调整本地 `env.sh` 的激活路径；该步骤依赖包源可达，不对当前前缀覆盖安装。失败的 `conda-env/` 已移除；其他工程使用的 `../chipyard/.conda-env`、用户的 Conda 基础环境未改。

## 日常命令

使用 Bash：

```bash
cd /data1/gzh/EC/firesim
source sourceme-manager.sh --skip-ssh-setup
command -v firesim python3 java riscv64-unknown-linux-gnu-gcc
firesim --help
cd deploy
```

Git操作统一在 `/data1/gzh/EC` 执行：`git status`、`git diff -- firesim`、`git add firesim`、`git commit`。不要在FireSim或依赖目录重新执行 `git init`。本机源码已经导入；上游 `build-setup.sh` 的嵌套仓库初始化在EC模式下只给出说明，不重建Git子模块或覆盖现有环境。

这是唯一日常环境入口。`env.sh` 用 `conda activate` 复用既有环境，启用官方 `FIRESIM_STANDALONE`；不进行求解、联网安装或 FPGA 操作。其显式 PATH 优先级避免继承旧 Chipyard Python。系统 Vivado 可用 `source /tools/Xilinx/Vivado/2021.1/settings64.sh` 加载，再重新 source 本工程入口；不要混用其他版本的 Vivado。

以下是官方命令及其用途；**构建、部署和运行均未在本次整理中执行**：

```bash
# 生成配置模板，会备份/替换 deploy 下现有配置。当前配置已生成并整理，不必再次运行。
firesim managerinit --platform xilinx_alveo_u280

# 以后准备好硬件与构建资源后：
firesim -b config_build.yaml -r config_build_recipes.yaml buildbitstream
firesim -b config_build.yaml -r config_build_recipes.yaml builddriver

# 设备操作需另行审阅并获确认；本机保留的 Manager 限制会拒绝物理 Alveo 操作。
firesim -c config_runtime.yaml -a config_hwdb.yaml infrasetup
firesim -c config_runtime.yaml -a config_hwdb.yaml runworkload
```

`buildbitstream` 当前配方指向官方 `FireSimRocketConfig`，不是 EC。`config_runtime.yaml` 当前引用有历史证据的 Native 预编译参考产物，作为配置解析和以后验收的依据，**不表示当前卡已加载该硬件**。不要用干净 Chipyard 重编译旧 EC 驱动：HWDB 使用官方 `driver_tar` 机制绑定原驱动，保留原 ABI。

修改硬件参数：先在 `target-design/chipyard/generators/` 中找到配置 Scala 类，再修改 `config_build_recipes.yaml` 的 `TARGET_CONFIG`；平台参数在 `PLATFORM_CONFIG` 和 `platform_config_args`。`config_build.yaml` 选择配方和构建主机。运行参数在 `config_runtime.yaml`，其中内存模型五项 plusargs 来自原验证配置，不能用不同硬件默认值替代。

工作负载：官方 `deploy/workloads/<name>.json` 指向同名目录内 bootbinary/rootfs；当前 Native 镜像自带 initramfs，`common_rootfs: null`。JSON 只能描述原 Guest 启动行为，不会凭空接通 Guest 内的 ROI/工作负载协议。保留镜像只供历史验收参考，不把它当成通用自动性能测试。需要新 Linux 工作负载时，使用 `sw/firesim-software/marshal` 的官方 build/install 流程并明确新硬件接口；其尚未下载的Linux/Buildroot等源码须按 `UPSTREAM_SOURCES.json` 中的FireMarshal原始pin选择性导入，并由EC跟踪；当前 `init-submodules.sh` 会说明此要求，不在EC父仓库运行上游子模块命令。

## 两块 FPGA 的本机基础设施

2026-11-26 只读核查：

| BDF | `/opt/firesim-db.json` 的 JTAG UID | 当前 XDMA | 链路 |
|---|---|---|---|
| `0000:e2:00.0` | `Xilinx/21770433G001A` | `xdma1` | 8.0 GT/s ×16 |
| `0000:21:00.0` | `Xilinx/21770433G02LA` | `xdma2` | 8.0 GT/s ×16 |

两卡 PCI ID 均为 `10ee:903f`，子系统 `10ee:0007`，均绑定 `xdma`。系统登记器件为 `xcu280_u55c_0`；既有构建的精确 part 为 `xcu280-fsvh2892-2L-e`。型号来自既有平台、数据库和构建证据，本次未通过重新配置/枚举测量型号。XDMA 序号会随启动和设备操作改变，历史文档的 xdma0/1 已过时；使用 BDF 和 JTAG UID。

必须保留的系统文件（本次均未改）：

- `/opt/firesim-db.json`：JTAG / BDF 的双卡映射，不能按旧顺序重建或覆盖。
- `/usr/local/bin/{pcielib.py,program_fpga.tcl,firesim-fpga-util.py}`：已有定向 PCIe 操作与明确 JTAG 编程确认。
- `/usr/local/bin/firesim-load-xdma-module`、`firesim-remove-xdma-module`、权限工具和现有内核 `xdma.ko`。
- `/etc/udev/rules.d/52-xilinx-*`、`99-xocl.rules`、`99-xclmgmt.rules`，以及现有 XRT/服务配置。

FireSim 的 U280 `scripts`、部分 Tcl 和构建脚本原本就链接到 U250 公共实现，这是官方结构，不是失效路径。

必要本地差异：

1. 保留 Manager 对物理 Alveo `load/unload/flash/infrasetup/enumerate/start` 的原有限制，避免官方通用流程卸载全局驱动或重配另一张卡。错误信息已指向本文。没有新增部署封装。
2. 保留 `platforms/xilinx_alveo_u250/scripts/` 的 `21:00.0` / `21770433G02LA` 单卡限制、固定上游 bridge `0000:20:03.1`、定向 rescan/bind、显式 JTAG 与编程完成检查，禁用历史多卡脚本；U280 共享这些实现。原始补丁已归档。
3. U280 随工程保留此前实际采用的 board XML：`cl_firesim/board_files/au280/1.1`，板型 VLNV 为 `xilinx.com:au280:part0:1.1`（历史构建注明物理 revision 1.2）。本地 Tcl 仅从构建目录读取该定义；没有写 Vivado 安装目录。
4. `env.sh` 与环境包清单仅指定现有用户环境；其余核心 FireSim / 配套 Chipyard 未接入 EC 硬件。
5. 下载源码改为EC普通文件管理；Chipyard脚本按脚本位置定位工程根目录，相关bootstrap入口不再操作EC子模块配置；FireMarshal按依赖子目录记录EC提交和dirty状态，避免将无关目录的改动当作该依赖变化。官方U280共享脚本、FireMarshal、target-rtl等工程内部相对链接保持有效。

本次观察到其他用户的 Vivado/hw_server 活动，且普通账号不能读取全部 `/proc`。未见可见 FD 占用不代表卡空闲。`enumeratefpgas` 会烧写识别硬件，不能当只读查询。`infrasetup`、reset、remove/rescan、bind/unbind、驱动加载/卸载、JTAG 编程与 flash 都必须先单独确认；单卡限制也不能代替占用核查和操作授权。纯文件检查可用 `lspci -Dnn`、`lsmod`、`readlink /sys/bus/pci/devices/<BDF>/driver` 和 `/sys/class/xdma/`。

## 保留的硬件与历史资料

归档根：`/data1/gzh/EC/AI/TMP/FireSim-native-20261126`，索引见其中 `README.zh.md`。

| 参考产物 | 定位 | 验证边界 |
|---|---|---|
| Native / B ROI v5 | `deploy/bitstreams/legacy-native-v5/`；HWDB `legacy_native_v5` | 既有真实板级 Ferret simsmall 记录 valid=true；本次仅核验源记录、镜像、驱动、bitstream 哈希，没有重跑 |
| EC ROI / checker `74810f4` | `deploy/bitstreams/legacy-roi-checker-74810f4/`；HWDB `legacy_roi_checker_74810f4` | 保留原时序/DRC证书和完整重编译驱动，证书明确 `NOT_FPGA_VALIDATED`；本次不新增运行结论 |
| 原完整 EC C4 集成 | 归档 `reference-sources.tar.gz` 的 `firesim/final-opt4-20261106/C4/chipyard` | 保留 EC / Linux ROI / FireSim Bridge / host 接口，原完整版本不是已通过 FPGA 的最终实现 |
| 历史版本差异 | `source-history.bundle`、`source-history-index.json` | 108 个最终优化快照合并到同一 Git 对象集合；旧 1.9 / 1.17 兼容补丁另见 reference |

原始 `.bit`、官方 `firesim.tar.gz`、`driver-bundle.tar.gz` 均保留，方便人工核对及原生 HWDB 使用；压缩包是此次封装既有文件，不是新硬件生成物。精确 SHA256、来源与运行证据位于 `runtime-index.json`。新旧硬件、不同驱动及证据不能交叉拼接。旧两个 performance-only / privilege 中间比特流被 `74810f4` 的 ROI/checker 修复替代，原证书和源码差异保留，不再保留重复可生成比特流。

已取消 `dac.py`、`dac2026/env.sh`、JSON site/readiness/manifest gate 和无人值守构建/运行体系的日常入口；使用官方 `sourceme-manager.sh`、Manager YAML、HWDB、workloads 和命令。必要 Guest ROI/checker、Bridge、主机采集和单卡平台逻辑保留作参考。原运行记录在 `../Experiment/`，其绝对路径是历史 provenance，未批量改写；对应旧文件的去向在归档清单。旧外部实验证据引用的环境前缀保持有效。历史脚本须按新目录人工审阅，不能直接重启。

## 以后迁入最新 EC 硬件

先对比外部 EC Chipyard 1.9.0 与这里 `336f225` 的 CDE、BOOM/Rocket、Binder 和 FireSim Bridge API，选定一个整体兼容的版本组合。随后在独立分支按功能迁入 generator、配置、Bridge、Guest 协议，复用归档的兼容差异；不要复制旧 `work/` 或替换整个依赖树。依次验证 Scala、参数、elaboration、Golden Gate、driver、独立构建和获授权的最小运行，各阶段保留同源码的版本对应。本次没有实施这些硬件迁移步骤。

## 本次验收

已完成：上游源码版本核对、干净 shell 环境初始化、Manager CLI、官方 managerinit、BuildConfigFile/RuntimeConfig/HWDB/WorkloadConfig 实际解析、SBT 工程加载与 Scala 版本、官方 Makefile 干跑、保留产物 SHA256 和驱动动态库解析、归档解包内容校验及双卡只读前后对比。验收结果和磁盘对比在归档 `audit/validation.json`、`DISPOSITION.md`。

没有执行：硬件功能编译、RTL 生成、新比特流、设备部署、FPGA 运行、reset、驱动/系统升级。配置解析和历史有效样本都不能代替重构后板级运行验收。AWS、VCU118、NiteFury 等非 U280 平台及大型 Guest 软件子模块保持按需初始化；这不是本机 U280 源码版本不配套。

官方示例 workloads 的 Linux/Fedora 链接指向尚未构建的 FireMarshal 镜像，`tests/htif.ld` 依赖按需初始化的 libgloss；Guest overlay 内指向 `/etc/systemd/...` 的绝对链接只在 Guest 内解析。这些保留官方含义，详见 `audit/broken-links-after.json`；当前选定的参考 workload 和必要源码路径均有效。

2026-11-27 已按用户授权使用 sudo 删除剩余 **7.079 GiB** 的旧生成物，`cleanup-needs-root/` 已不存在，文件清理全部完成。当前主工程约 5.058 GiB、精简归档约 0.291 GiB；相对重构前合计减少约 127.779 GiB。清理记录见归档 `audit/cleanup-completed-20261127.json` 和 `DISPOSITION.md`。两块 FPGA 的 PCIe、驱动绑定和 XDMA 映射与前次核查一致。

Git提交包含有效源码、本机必要差异、YAML配置、版本来源与精简归档的校验索引 `ARCHIVE_SHA256SUMS`。`envs/`、bitstream/Guest二进制、缓存及 `AI/TMP` 继续作为本地资产，不混入源码提交；其保留状态不依赖隐藏源码改动。
