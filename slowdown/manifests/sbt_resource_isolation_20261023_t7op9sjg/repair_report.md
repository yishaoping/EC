# Current BlackBox 缺失与 SBT 输出隔离修复

## 结论

`DIRECT_EVIDENCE`：失败运行 `current_20261023_215133_bad42e29` 报
`BlackBoxNotFoundException: BlackBox '/vsrc/plusarg_reader.v' not found`。
Current 对应源文件实际存在，SHA256 为
`482a63c1f24a7ac920909620bd0df108e6954eabf9520de6e72334a2b5450efb`。
缺失发生在生成器运行时的 classpath，不是原始 RTL 文件缺失，也不是 FireSim workload 依赖。

`DIRECT_EVIDENCE`：旧 adapter 使用
`set every target := file(sys.env("SLOWDOWN_SBT_TARGET")) / thisProject.value.id`。
失败日志中不同编译批次的 classes 目录都为
`scala/chipyardRoot/scala-2.13/classes`；Scala 输出根实际只有 `chipyardRoot` 一个目录。
`chipyard_2.13-1.6.jar` 和 `rocketchip_2.13-1.6.jar` 的 `vsrc/` 都只有 `SimDTM.v`，没有 plusarg reader。
`copyResources` 的最终同步映射只有 Sodor 的 `/vsrc/SimDTM.v`。

`STATIC_INFERENCE`：旧 session-scoped 表达式使多个项目共享 target、classes、
resource synchronization 和增量缓存。资源同步相互清理/覆盖，打包得到不完整或属于其他项目的资源。
这比单独复制一个缺失 Verilog 文件更上游，必须修复整个输出空间隔离。

## 修复范围

- `scripts/sbt_external.py`：改用 34 个带 build 身份的显式 `ProjectRef / target`，
  目标路径是本次 run 的 `scala/<build>/<project>`，不再依赖当前 session 的 `thisProject`。
- `scripts/sbt_inputs.py`：静态识别两份固定 build 定义，计算 Chipyard 的 26 项 Compile 依赖闭包。
  扫描 987 个 Scala 文件，检查 75 条 literal/Config 资源引用，覆盖 65 个不同资源名。
- `manifests/sbt_resource_inputs.json`：固定资源提供者、源文件哈希、Config 哈希和 7 条动态引用的审阅。
  缺失、未审阅动态引用、源码/Config 漂移均拒绝继续。不会恢复或合成 RTL，也不引入 Baseline 资源。
- `scripts/launch_current.py` / `runtime_probe.py`：身份检查和实际沙箱挂载视图均检查资源身份。
  既有只读源码、私有 build、独立 tmp、隔离网络、固定工具路径策略保持生效。
- README 和 preparation 哈希随上述基础设施变化显式更新；原 preparation 和所有改动前脚本
  保留在本目录 `before/`。Current 源码身份未重新接受或改变。

## 同类风险检查

`DIRECT_EVIDENCE`：源码中存在两组不同内容的同名 classpath 资源：

| 资源 | 提供者 | 处理 |
| --- | --- | --- |
| `/vsrc/plusarg_reader.v` | Rocket Chip、IOCell/barstools | 资源所属源引用要求 Rocket Chip 的固定内容；旧 IOCell 副本没有 WIDTH 参数，也不读取 plusargs |
| `/vsrc/SimDTM.v` | Rocket Chip、Sodor | 保留原始各自副本；对实际 classpath 首选结果与源引用所属模块进行校验 |

`STATIC_INFERENCE`：独立打包会避免旧共享 classes 让这些文件互相覆盖。
仍需校验实际 classpath 的首选提供者，不能以“存在同名文件”作为正确版本证明。
本轮没有更改原始资源、过滤资源或重排原始依赖。

`STATIC_INFERENCE`：7 条动态引用中，ClockGate 的 addPath/addResource 两条由
`v1Config -> AbstractConfig:59 -> WithClockGateModel` 的 `/vsrc/EICG_wrapper.v` 闭合，
同时拒绝宿主同名绝对路径绕过 classpath 检查。其余 RoCC example、CVA6、Ibex、NVDLA、DspReal
不由固定 Config 选择。源码哈希固定，旧失败 FIR 的 extmodule family 列表作为佐证，
不把旧 FIR 当作修复后生成产物。详见 `failed_fir_extmodules.json` 和资源审阅 JSON。

## 用户正式启动时的关卡

1. 原有环境预检和新的静态资源身份检查。
2. SBT 实际求值 34 组 target 与 Compile/classDirectory；68 项观测必须符合独立路径。
   不符合时在正式 Scala 编译前终止。
3. 单独完成 Scala 依赖编译和打包，读取实际 `Runtime / fullClasspathAsJars` export。
   批量验证所属 JAR 包含原始资源、SHA256 正确，且 classpath 首选提供者正确。
   缺失和版本错误统一报告，在 Generator/elaboration 之前终止。
4. 检查再次通过后，才转交 Make 原来的 `chipyard.Generator` 命令。

上述 2–4 步只属于未来用户正式运行。本轮没有执行。
每次 guard 创建独立 `build/<run_id>/sbt_input_guard_*/`，记录 project plan、
evaluated target log、target_check、compiled classpath log 和 classpath_resource_check。
用户重试仍使用 `/data1/gzh/EC/slowdown/run_current_gapbs512.sh`，无需额外参数或手工修补资源。
新 run 不复用失败 run 的 classes/JAR/model；旧产物不删除。

## 已执行验证

`DIRECT_EVIDENCE`：`check_infrastructure.py` 的 11 项无编译检查通过，包括：
显式 target 唯一、旧共享 target 拒绝、68 个求值检查安排、正向资源 ZIP 检查、
旧 WIDTH-less plusarg 遮蔽拒绝、多文件缺失批量报告、未审阅动态引用拒绝。
ZIP fixture 仅包含原始资源字节，没有 Java class，保留在本审计目录，永不用于正式运行。
记录见 `infrastructure_checks.json` 与 `fixture_*`。

`DIRECT_EVIDENCE`：旧失败运行的实际 classpath 也被离线检查并拒绝，
所有 65 个资源名均存在缺失/内容不符/所属输出不符，结果见 `old_failed_classpath_check.json`。
130 条诊断是资源选择与所属输出的两类检查结果，不代表 130 个独立缺失文件。

`DIRECT_EVIDENCE`：launcher `--static-check` 通过；`bash -n` 通过；
`prepare_trace_visibility.py` 通过，181 个原 trace alias 不变，功能文本检查通过。

`DIRECT_EVIDENCE`：新环境预检
`slowdown/runs/current_preflight_20261023_221541_c3ddbd1d/run_manifest.json`
结果 `ENVIRONMENT_PREFLIGHT_PASSED`，14 项检查通过。
实际沙箱内 75 条资源引用检查通过，Verilator 固定为 Nix 5.048。
adapter 只打印命令，没有启动 Java/SBT project load。

## 身份和未闭合事项

`DIRECT_EVIDENCE`：Git HEAD 保持
`1697aff10cd6d086da1fc727e2679fe0a0d73f9a`；Current source digest 保持
`5df079ed630ba52e21c8ba28bf8aad5131a51e9ccfe754f1602396689e5b8757`。
Git index 与 Current diff 在前后比较中保持不变，未提交或同步任何内容。
固定 ELF/loadmem 的哈希和既有证据不变，原工作区修改不清理。

`UNRESOLVED`：真实 SBT 设置求值、修复后的 Scala 打包、Generator、Verilator 编译和仿真
尚未由本轮执行；静态 fixture 和环境预检不是完整构建成功证明，也不保证不存在其他类型错误。
`RUN_PROVENANCE=UNRESOLVED` 以及既有 cache/package/DRAM drain、完整正确性限制均保持。

本轮没有编译、elaboration、RTL generation、仿真、workload、分支切换或 index 修改。
所有新文件和修复只位于 `/data1/gzh/EC/slowdown/`。
