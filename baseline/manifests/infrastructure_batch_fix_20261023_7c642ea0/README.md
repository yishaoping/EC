# Baseline 启动基础设施批量排查与修复

日期：2026-10-23，Asia/Shanghai。

## 结论

`DIRECT_EVIDENCE`：最新失败发生在 SBT 项目加载和插件依赖解析，尚未进入工程源码编译或硬件 elaboration。插件已存在于独立缓存，但启动器的 `-Dsbt.coursier.home=.../v1` 优先于 `COURSIER_CACHE`，SBT 自动追加 `/cache` 后查错目录，继而尝试访问被隔离的网络。这不是三个插件都没有安装。

`DIRECT_EVIDENCE`：修复后的最终非硬件预检为 `../preflight_6j0t9w3i/manifest.json`，结果 `PASS_NO_HARDWARE_OR_SIMULATION`，失败组为空。27 个相关依赖范围解析成功，274 个解析后的 JAR 通过 ZIP/CRC 完整性核验并记录 SHA256。本次未运行工程 Scala/Chisel 编译、RTL generation、Verilator 构建、仿真或 workload。

`UNRESOLVED`：此结论仅闭合启动基础设施和已检查的依赖条件；不能据此宣称硬件构建或 benchmark 一定成功。`RUN_PROVENANCE=UNRESOLVED` 与 `BASELINE_GAPBS_COMPARISON_IS_APPROXIMATE` 保持。

## 故障与改动

| 项目 | 直接证据 | 修复/处理 | 验证范围 |
|---|---|---|---|
| SBT 缓存根目录错误 | `../../build/b3_20261023_124610_tjtbim49/rtl_generation.log` 中三个插件解析失败；实际插件在 `cache/coursier/v1/https/...`，新查找目录为 `v1/cache/https/...` | 移除 `sbt.coursier.home`；使用精确的 `COURSIER_CACHE` 和 `coursier.cache` | 实际 SBT `csrCacheDirectory` 输出正确；断网下插件和27个范围均完成解析 |
| 源码副本丢失可执行位 | 规范 `scripts/numa_prefix` 为0775，失败构建副本为0664；三个后续直接调用的 split 脚本也受相同复制策略影响 | `copytree` 改用 `copy2`，复制身份增加文件mode，并检查其后是否变化 | 三个split脚本实复制，内容哈希与mode一致；启动器自检验证mode回归会被拒绝 |
| zlib开发目录失效 | 首次增强预检 `../preflight_udycujm5/native.configured_CXX.txt` 为 `zlib.h file not found`；原记录的 Nix zlib1.3开发目录不存在 | 从现有只读Conda环境独立复制匹配的zlib1.2.13头文件和库至 `cache/native-zlib`，以 `native_environment.json` 单独记录覆盖，不改原environment记录 | 三条C++入口均通过预处理；加载指定库读取版本为1.2.13；三个文件逐次校验SHA256 |
| 隔离环境JMX异常 | `../preflight_udycujm5/sbt_dependencies.log` 含 `Could not reconfigure JMX`；栈落在JDK17 cgroup指标读取 | 根据本地Log4j类实际属性增加 `-Dlog4j2.disable.jmx=true`，关闭构建日志的可选管理接口 | 最终SBT依赖日志无该异常，解析通过 |
| 预检只验证版本和少数缓存文件 | 旧preflight成功仍未发现本次插件路径错误，也未验证C++头文件 | 增加构建定义副本、批量update、本机检查、依赖JAR核验、失败组汇总；在大规模源码复制及硬件任务前运行 | 全部非硬件检查通过；注入多个失败的启动器自检确认其他检查继续执行 |
| SBT并发与缓存并发 | 旧锁位于preflight之后；SBT默认可按主机CPU数量创建线程 | 锁覆盖preflight；JVM可见CPU=8，SBT task CPUs=4；`--jobs`仍控制用户的Make构建并行度 | 最终实际预检通过；没有启动第二个构建进程 |

上述前四项为 `DIRECT_EVIDENCE`。同一copyfile策略会影响其他可执行文件、失效头文件会在FST C++构建阶段造成失败，属于 `STATIC_INFERENCE`，不是已执行硬件构建的观察。

此前的长SBT Unix socket问题保持原修复：短临时目录和真实AF_UNIX绑定检查。未恢复长build路径临时目录。

## 批量预检实现

- `launch_baseline.py`：普通缺失项集中列出；输入身份、路径越界和隔离失败立即停止。输出preflight目录、各检查组状态及完整失败列表。
- `baseline_preflight.py`：只复制历史 `*.sbt`、`project/*.scala` 和构建properties，不复制硬件Scala；执行构建定义加载和 `update`，不执行工程 `compile`、`runMain`、测试或生成器。
- 依赖范围：26个历史根构建模块，包括chipyard、BOOM、rocket-chip、cache、tapeout、dsptools及依赖，加上FireSim `targetutils`；根构建引用的FireSim插件也在项目加载时解析。
- `resolved_artifacts.json`：根据SBT原生update JSON记录实际选中的模块版本、JAR路径和SHA256，并逐个检查ZIP CRC；不把缓存里所有文件的存在当成解析成功。
- 本机10组检查：配置CXX、DRAMSim硬编码g++、Verilator Makefile的clang++、firtool帮助、Verilator帮助、FESVR归档、历史Verilator参数、zlib运行库身份、历史firtool参数、脚本复制权限。
- 参数探测仅使用工具help/version；C++仅执行预处理到 `/dev/null`，没有编译/链接；zlib仅加载指定主机库查询版本。
- 新构建manifest绑定通过的preflight manifest SHA256，并记录native覆盖及依赖身份。
- bwrap持续保持宿主及Current只读、规范历史源码只读、Baseline可写、网络隔离。没有下载或变更插件版本。

## 复查结果

`DIRECT_EVIDENCE`：

1. `start_baseline_experiment.sh --check --workload .../gapbs512_20261023_03/workload.json` 通过。
2. 最终 `start_baseline_experiment.sh --preflight --workload .../gapbs512_20261023_03/workload.json` 返回0；证据位于 `../preflight_6j0t9w3i/`。
3. `python3 -I -B baseline/check_launcher_infrastructure.py`：5项启动器自检通过，覆盖缓存选择、mode保持/篡改拒绝、元数据副本不含硬件源码、多个静态失败汇总、多个本机失败继续收集。
4. `bash -n baseline/run_baseline_gapbs512.sh baseline/start_baseline_experiment.sh` 通过。
5. 历史 `--trace-threads 1` 在现有Verilator5.048中返回弃用警告并被接受；未改历史硬件Makefile，也未把警告误报为构建成功。
6. 最终预检的 `sbt_dependencies.log` 没有 `[error]` 或JMX异常；274个解析后JAR无损坏、无目录外依赖路径。

## 保全与未验证项

- Git根HEAD仍为 `9b0f34648d5ef483fcebaef6bdfb2c18f1b5014f`。原有 `Experiment/流量分析.typ` 修改、`DOC/`（含Prompt）均保留。
- 规范Baseline HEAD仍为 `b3d7adddd1e2d2cf428dd933529de878226420cd`，工作区干净；硬件功能代码未修改。
- 根index与Baseline index SHA256均与本次修复开始时一致，详见 `preservation_hashes.txt`。
- ELF/loadmem/descriptor SHA256与原固定值一致；没有重新编译或调整workload。
- 两个原失败构建目录、日志以及已有manifest/波形/审计报告均保留。旧目录不被重新用于本次构建。
- 所有新增文件/缓存均位于 `/data1/gzh/EC/baseline/`。没有checkout、worktree、Git index变更、Current写入或原始波形读取器执行。
- `UNRESOLVED`：真实工程编译兼容性、RTL生成、C++/FESVR最终链接、真实simulator启动、包完成/退出drain、运行正确性和性能对比；这些仍须用户的正式流程产生证据。
- `UNRESOLVED`：依赖预检不能保证排除所有源码编译或运行时问题。未来问题会继续按完整阶段日志诊断，不能用预检代替实际硬件验证。

## 用户下一步

仍使用同一条一键命令，入口会自动先做上述批量预检：

```bash
/data1/gzh/EC/baseline/run_baseline_gapbs512.sh
```

该命令由用户执行后才进入历史硬件生成、Verilator构建和仿真。本次修复没有执行它。
