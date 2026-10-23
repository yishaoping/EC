# GAPBS512 独立实验准备结果

`DIRECT_EVIDENCE`：已成功软件编译、生成ELF/loadmem、验证反汇编/符号/布局、固定一键入口；非硬件preflight通过。未执行一键入口、硬件生成、Chisel/RTL、Verilator硬件构建、仿真、workload或Current重跑。

`BASELINE_GAPBS_COMPARISON_IS_APPROXIMATE`

## 用户入口

```bash
/data1/gzh/EC/baseline/run_baseline_gapbs512.sh
```

Baseline HEAD：`b3d7adddd1e2d2cf428dd933529de878226420cd`，父提交 `6d899a71d68e5e15cb4c108a48375ea60edb2280`；独立规范源码 `baseline/source/` 保持clean，未编辑任何历史硬件。全部写入仅在baseline内。根index、历史index、原软件、Current全部tracked文件及原始日志/FST/verbose输出都列入本轮前后保全检查，用户原有 `Experiment/流量分析.typ` 和 `DOC/Prompt.typ` 保留。

软件：`baseline/software_common_builds/gapbs512_20261023_03/test.riscv`，SHA256 `da8897e790f0c5e91eff3e9560d2b0e7b4e1de6dff208788fb4d9e2ae462c81c`。

loadmem：同目录 `test.loadmem_hex`，SHA256 `f1c0335e8a7ffc6f57232e9bcb8c80a49f45eacaa1e4f533f4cb3af91ad308ad`。

`DIRECT_EVIDENCE`：GCC12.2.0实际编译成功，ELF64 little-endian RISC-V、静态链接、entry0x80000000；软件编译命令和库哈希在build.manifest.json。loadmem覆盖512KiB，包含全部PT_LOAD文件/BSS映射；从匹配ELF导出，未运行loadmem或ELF。最终软件ROI为0x80000340..0x8000039c，布局合同18项通过，原BFS、AMO、timer handler/64字节布局源文件哈希匹配旧Current软件manifest。runtime correctness尚未验证。

## 变更范围

- 修复baseline软件builder与launcher的bwrap兼容性：旧版本无`--clearenv`、当前内核不允许新的proc挂载；采用最小环境、显式setenv及继承只读proc，未放宽可写挂载。
- 增加一键入口，绑定真实软件descriptor SHA；无参数即新建硬件build+run，jobs1、maxcycles500M、seed1、最低50GiB。
- launcher增加preflight缓存/磁盘/隔离探针，明确`verilog`/`debug`两个历史Make目标，记录阶段日志；增加独立raw stdout/stderr、combined test.log、command.txt、test.fst、run_manifest.json。
- 保留旧README副本后更新当前README。先前审计与软件构建失败目录不覆盖。

## 命令依据

`DIRECT_EVIDENCE`：历史 `source/chipyard/common.mk:285-288` 提供`verilog: $(sim_common_files)`；`sims/verilator/Makefile:28-40,105-125,230-233` 提供`debug`、simulator命名、FST选项和构建规则。`variables.mk:64-74,227-228`规定chipyard/TestHarness与SBT入口；历史 `RocketConfigs.scala:10-30` 和 `GH_GlobalParams.scala:5-6` 定义v1Config与1+4拓扑。

`DIRECT_EVIDENCE`：命令结构也参照既有 `AI/TMP/control_stop_sync_20261021_audit/source/stage1_build_and_run.sh`，不执行该Current脚本，不添加`STAGE1_EXIT_PORTS`或Current生成模型。调用历史driver `generators/chipyard/src/main/resources/csrc/emulator.cc:134-206,287-295,351-385` 的`-v/-s/+verbose/+cycle-count/+max-cycles`；loadmem/dramsim参数见历史 `SimDRAM.cc:34-50`、`mm.cc:135起`。

## 输出及接受范围

每次创建 `baseline/build/b3_<时间>_<随机>/` 和 `baseline/runs/b3_<时间>_<随机>/`；不复用旧build，input快照逐项哈希；generated model、source snapshot和simulator可核验。历史Make在构建副本内写入，规范source只读。全部子工具通过bwrap宿主只读、baseline可写、网络关闭执行，Current工具链仅只读复用。

`DIRECT_EVIDENCE`：preflight `../preflight_m8eu3149/manifest.json`为PASS，隔离探针只在该新目录创建一个文件；版本探测没有调用SBT项目或Make目标。`static_checks.json`验证Bash/Python语法、入口执行权限、软件输入哈希、ELF布局/ROI、旧文件拒绝覆盖、历史目标/driver支持；capture_fixture只运行Python打印stdout/stderr，不运行硬件或workload。

`UNRESOLVED`：离线缓存已具有SBT1.8.2及Scala2.13.10关键jar，但全部项目依赖和工具版本的实际硬件构建兼容性未执行验证；用户构建失败则停止，不自动下载或绕开隔离。软件/硬件交互是否运行完成须用户首轮仿真检查。完整package/error-detection与L2/DRAM drain不能由软件ready或HTIF PASS代替。缺失历史R-Kernel不参与静态HTIF ELF运行或所查硬件构建，不恢复/编译它。

`UNRESOLVED`：`RUN_PROVENANCE=UNRESOLVED`保持；新Baseline manifest会记录充分身份字段，但不会自动把未审阅运行升级为闭合性能比较。两个旧Current证据集合分开，见current_evidence.md。

## 本轮文件

| 文件 | 用途 |
|---|---|
| current_evidence.md | Current配置/日志/FST/软件来源与近似比较限制 |
| static_checks.json | 静态和真实软件产物验收；无硬件执行 |
| preservation.before.json / preservation.after.json | 原工程、index、用户文件和原始结果保全 |
| verify_preparation.py | 可审阅的静态验收及Python文本捕获fixture |
| preservation_check.py | 只读哈希和Git身份采集 |
| README.previous.md | 本轮更新前原始Baseline使用说明 |

用户运行唯一命令后，软件PASS与harness成功仅标为 `PROCESS_AND_EXPECTED_MARKERS_PASSED`；完整硬件正确性、退出drain、关键路径因果仍需后续审阅，不由准备脚本宣布。
