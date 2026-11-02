# 本次资源缺失根因、批量修复与验证

日期：2026-10-23。任务边界：所有新写入位于 baseline；不代用户执行硬件源码编译、elaboration、RTL generation、Verilator 构建、仿真或 workload。Current、规范历史源码、软件产物及既有失败现场不修改。

## 原因及此前漏检

`DIRECT_EVIDENCE`：`../../build/b3_20261023_132835_9a758qw4/rtl_generation.log:4535–4540` 报 `firrtl.transforms.BlackBoxNotFoundException: BlackBox '/vsrc/plusarg_reader.v' not found`。该次日志已经显示 Scala 编译及地址图/时钟打印完成；最后因资源提取失败而退出。原日志 SHA256 为 `20a0dabc8cc9daf29efb8c1223f87f67385b51af69ff1c009bbfe3ce8ae5af4a`。

`DIRECT_EVIDENCE`：b3 的 `chipyard/generators/rocket-chip/.gitignore` 包含 `*.v`。规范历史树中整个 Rocket Chip `src/main/resources/vsrc/` 缺失；`util/PlusArg.scala:54` 却需要其中的 plusarg_reader。Git clean/完整 commit SHA 只能证明 tracked 状态，不能证明忽略掉的原始输入存在。

`DIRECT_EVIDENCE`：此前 `baseline_preflight.py` 的 metadata_copy 只复制构建定义，检查依赖 update 和 JAR，没有检查硬件资源。其 PASS 被用作用户重试的依据，覆盖范围不足。截图上的统一 `RTL_GENERATION failed` 又掩盖了底层不同原因。这是准备和检查方法的问题，不能仅补一个文件后再次声称全流程已验证。

## 批量调查结果

`DIRECT_EVIDENCE`：扫描 b3 build.sbt 实际 Compile source roots 中 978 个 Scala 文件；排除 main/old、main/v0、无关测试及 FPGA 工程。发现 74 条字面量资源引用、7 条动态引用。另由 v1Config → AbstractConfig:59 → WithClockGateModel 默认参数补入 EICG_wrapper 检查，共 75 条字面量/配置资源检查。

`DIRECT_EVIDENCE`：未经恢复的规范历史树缺少以下 5 个资源；详见 `resources_before.json`。

| 资源 | 客户端证据 | 本轮处理 |
|---|---|---|
| `/vsrc/plusarg_reader.v` | util/PlusArg.scala:54；原失败日志 | 恢复 |
| `/vsrc/SimJTAG.v` | devices/debug/Periphery.scala:236 | 恢复 |
| `/vsrc/ClockDivider2.v` | util/ClockDivider.scala:24 | 恢复，预先消除同类缺项 |
| `/vsrc/ClockDivider3.v` | util/ClockDivider.scala:32 | 恢复，预先消除同类缺项 |
| `/vsrc/EICG_wrapper.v` | subsystem/Configs.scala:524；AbstractConfig:59 | 恢复；不能被纯字面量调用扫描遗漏 |

`DIRECT_EVIDENCE`：只读解析本次用户失败后留下的 FIR，得到 9 种 BlackBox defname，包括 188 个 plusarg_reader、5 个 EICG_wrapper 和 1 个 SimJTAG。详见 `existing_fir_blackboxes.json`。这只证明已有失败产物的实例化结果，不是新运行或成功的 RTL。

`STATIC_INFERENCE`：另外 7 条动态 API 引用逐项固定源文件 SHA 和解释；ClockGate 的两条 API 分支解析到上述 EICG_wrapper。Rocc 示例、CVA6、Ibex、NVDLA、DspReal 不由固定 v1Config 选择，已有 FIR 的 extmodule 列表也没有它们。任何动态引用或其源码 SHA 变化都会使预检拒绝静默沿用判断。

## 恢复来源与身份边界

`DIRECT_EVIDENCE`：从 Chipyard 1.9.1 公布的 Rocket Chip 指针定位固定上游 `25e2c63567689ebe1fc5e60fdfe3375a8dba071c`。保存完整递归树响应 `upstream_rocket_tree.json`，所有下载资源均按 Git blob SHA1、长度及 SHA256 核验。358 个重叠的 Scala/C++ 文件中 341 个与 b3 完全相同；完整结果在 `upstream_comparison.json`。

`DIRECT_EVIDENCE`：b3 PlusArg.scala、ClockGate.scala、ClockDivider.scala 与该上游文件完全一致。Periphery.scala 存在 EC 修改，但从 class SimDTM 起至文件结尾（包含 SimJTAG BlackBox）完全一致；差异在 `Periphery.diff`。5 个启用的恢复资源也都与现有 Current 对应资源逐字节相同，但下载和身份依据来自固定上游，并非直接用 Current 硬件覆盖 Baseline。

`STATIC_INFERENCE`：证据支持这 5 个缺失接口资源的兼容恢复，不能证明被扁平化 EC 仓库当初的完整上游 gitlink。`resource_restoration.json` 和构建 manifest 明确记录“b3 tracked 源码 + 可追溯兼容资源恢复”，不冒称纯 tracked b3 实验。

`DIRECT_EVIDENCE`：9 个上游资源被保存用于核对，只有配置清单中的 5 个进入执行副本。其他 4 个不启用：SimDTM 会与 Sodor 同名不同内容资源冲突；RoccBlackBox 未由 v1Config 选择且 Current 内容不同；TestDriver 仅用于其他仿真流程；b3 AsyncResetReg 为 Chisel 实现。不会盲目复制整个 Current vsrc 目录。

## 已落实的防回归

1. 静态 preflight 汇总缺失/冲突资源、未经复核的动态引用、完整 SIM_FILE_REQS 及无条件 Make include（23 项），补查 jq/perl 等实际使用工具。
2. metadata scaffold 保留原始资源拓扑及历史内部符号链接，只复制资源/构建定义，不复制硬件 Scala 编译输入。不执行任何可选硬件预处理脚本。
3. SBT 实际执行 27 个依赖范围的 update 和 copyResources，再按各 project 的真实 classDirectory 布局检查 65 项实际资源及 SHA256。不会只看目录存在或源码资源文件存在。
4. 新建执行副本后才复制 5 个恢复资源，禁止覆盖原有文件、写入规范源码或接受损坏的 payload。随后再检查实际副本中的 Scala 引用、资源提供者及哈希，确认与 preflight 一致，才允许用户流程进入硬件任务。
5. 构建 manifest 记录资源清单、provenance 和实际输入检查哈希；source_copy_identity 包括恢复文件。既有失败目录保留，不复用其不完整产物。
6. 构建失败时直接打印第一批错误和最终异常的日志行号、内容及完整日志路径，manifest 也保存摘录。

## 实际验证

`DIRECT_EVIDENCE`：`../preflight_a4l1906l/manifest.json` 为本轮最终非硬件预检，结果 `PASS_NO_HARDWARE_OR_SIMULATION`。27 个 dependency scopes、274 个 JAR 的 ZIP/CRC/SHA、65 项实际 SBT 复制资源、10 组 native 检查通过；资源复制错误列表为空。Java/工具版本探测、C++ 头文件预处理和 bwrap 隔离检查均仅用于基础设施检查。

`DIRECT_EVIDENCE`：`regression.log` 记录 13 项检查通过，包括：原缺失资源可批量暴露、路径名必须精确、注释不能误判、恢复副本冲突、payload 损坏、动态源码变化、实际复制资源损坏/源码遗漏、内部/可选失效符号链接保留、错误摘要、既有缓存和权限回归检查。`actual_input_copy_check.json` 另记录真实 Compile Scala/resource roots 的独立复制与回读核验，未运行硬件工具。

`DIRECT_EVIDENCE`：自检过程的 `../preflight_kibrr0tb/`、`../preflight_9wjukquy/` 保留。前者暴露历史可选 CVA6 符号链接，已改为保留其拓扑而非改历史文件；后者暴露 iocell/tapeout 共用资源在不同 project 输出的检查歧义，已改为按 b3 明确 project base 定位。这两次均在非硬件自检阶段处理，没有让用户代为试错。

`UNRESOLVED`：完整硬件生成、Verilator 编译及运行正确性尚未由本轮执行；不能据非硬件 PASS 承诺后续无任何错误。未验证任何新的 cycle、吞吐、drain、性能因果或 baseline/current slowdown。`RUN_PROVENANCE=UNRESOLVED` 与 `BASELINE_GAPBS_COMPARISON_IS_APPROXIMATE` 保持不变。

## 继续方式

用户入口仍为 `/data1/gzh/EC/baseline/run_baseline_gapbs512.sh`，不需要手工放资源、设置额外环境或复用失败目录。它会自动重新进行扩展预检，再由用户启动后续硬件流程。本轮到准备和检查完成为止。

保全核验与最终脚本身份在 `preservation.json`；本轮修改前的启动器、预检、自检脚本及 README 快照也保存在本目录。
