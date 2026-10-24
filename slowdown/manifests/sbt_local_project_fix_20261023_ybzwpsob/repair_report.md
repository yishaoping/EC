# Verilator 启动时 SBT 误复制 FireSim workload 的根因修复

日期：2026-10-23（Asia/Shanghai）。本次只修复 `slowdown` 启动基础设施。

## 根因

`DIRECT_EVIDENCE`：失败运行 `current_20261023_213733_78d0d71d` 的 `rtl_generation.log` 显示异常来自 `sbt.Resolvers.local` → `sbt.io.IO.copyDirectory`，发生在 SBT project load，尚未进入 `chipyard.Generator`。报错文件 `chipyard/sims/firesim/deploy/workloads/ping-latency/bbl-vmlinux` 是指向缺失的 `../linux-uniform/br-base-bin` 的符号链接。

`DIRECT_EVIDENCE`：对当前实际 SBT 1.8.2 JAR 做只读字节码检查，`Resolvers$.$anonfun$local$2(File, File)` 先调用 `File.canWrite()`；为真时直接返回原始本地 build 目录，为假时调用 `creates(staging, ... copyDirectory ...)`。字节码记录在 `sbt_resolvers_bytecode.txt`。原来的只读根目录映射使该判定为假，引发整棵 Current 源码 staging；复制因此碰到与 Verilator workload 无关的悬空链接。命令行 `set every target` 此时尚未执行，无法阻止这一复制。

`DIRECT_EVIDENCE`：`chipyard/build.sbt:138` 将 `midasTargetUtils` 定义为 `ProjectRef(firesimDir, "targetutils")`；rocketchip/hardfloat 等普通 Chipyard 模块使用该公共 Scala 库。`sims/firesim/sim/build.sbt` 也有返回 Chipyard 的本地 `ProjectRef`。读取这些公共构建定义不等于运行 FireSim。正式启动任务仍为 `chipyard.Generator`、Verilator debug simulator 和固定 GAPBS512 ELF/loadmem。

`STATIC_INFERENCE`：直接删除 FireSim/targetutils 引用或设置 `FIRESIM_STANDALONE` 会改变或破坏 Chipyard 的公共构建依赖；补造 workload 文件只能掩盖第一次复制失败，其他无关悬空链接及 source staging 仍可能失败。因此本次修复目录解析原因，未恢复或运行任何 FireSim workload。

## 修复

- `scripts/sbt_layout.py` 为 Chipyard 根及 `sims/firesim/sim` 根建立私有目录 backing，均位于当次 `slowdown/build/<run_id>/sbt-roots/`。
- 根目录 inode 可写，使 SBT 直接解析本地 build。普通源码文件和子目录逐项只读绑定到原路径，不复制硬件源码，不修改 `.sbt` 定义；`project`/`target` 仍由本次构建的独立目录提供。
- 保留符号链接原始目标，不递归跟随 FireSim workload 链接。构建输出即使使用源码侧的虚拟路径，实际 backing 也位于 `slowdown`。
- `sandbox_support.py` 支持明确的只读/可写 bind 类型；所有可写 backing 仍必须处于允许的输出根下。只读宿主根、独立网络、只读 proc 和私有临时目录策略保留。
- 预检增加本地 build 根 inode/backing 对应、可写性、源码只读 mount flags、两份 `build.sbt` 以及 14 个关键 Current 文件的视图内 SHA256 检查。`sbt_layout.json` 和各次 run manifest 记录完整映射。
- 原 `preparation.json` 已归档；仅更新已授权修改的脚本/文档哈希并纳入新 helper。Current 源码、Config、固定软件、保护机制和 Git index 不变。

## 直接验证

`DIRECT_EVIDENCE`：`probe_existing_sbt_resolver.py` 经固定 JDK 的 JNI 调用已经编译好的 `java.io.File.canWrite` 和上述原版 SBT resolver 叶子方法；没有调用 SBT main、加载 project 或编译测试程序。

| 本地 build 根 | Java File.canWrite | SBT 返回同一个 File | 创建 staging |
| --- | --- | --- | --- |
| `/data1/gzh/EC/chipyard` | true | true | 否 |
| `/data1/gzh/EC/chipyard/sims/firesim/sim` | true | true | 否 |

结果见 `existing_sbt_resolver.stdout.json`。该 probe 在调用 SBT 前先断言可写，禁止进入递归复制分支；完全只读映射的负对照在此断言处按预期拒绝，见 `readonly_control.stderr.log`，没有为了复现而复制源码树。

`DIRECT_EVIDENCE`：最新完整环境预检运行：

`slowdown/runs/current_preflight_20261023_214640_49b34a7d/run_manifest.json`

14 项检查全部通过；其 build 目录下的 `runtime_probe.preflight.log` 包含 `SBT_LOCAL_ROOTS=PRIVATE_WRITABLE_SOURCES_READ_ONLY`、`CURRENT_SOURCE_BYTES=PASS`、实际工具 PATH、只读源码、私有临时文件和网络隔离检查。`final_acceptance.json` 另记录最终静态、身份及保留状态检查。

`UNRESOLVED`：本次没有启动 SBT project load、软件/Scala/C++ 编译、elaboration、RTL generation、Verilator build 或仿真。对原版 resolver 分支的直接验证支持本次根因已被消除，不构成完整后续构建通过的证明。原始失败运行中已执行的命令是用户此前执行的历史证据，不计为本轮验证。

## 证据和状态

- 原始错误日志、运行 manifest 和旧 staging 目录均保留，没有删除或覆盖。
- 修改前 HEAD/status/index/current diff：`before_state.json`；修改前准备 manifest/脚本：`before/`；补充重建的旧脚本快照如有使用，均必须与归档准备 manifest 的 SHA256 完全相符。
- 修复 diff：`repair_patch.diff`；最终哈希与静态检查：`final_acceptance.json`。
- `libriscv not found` 是当前 Makefile 明确处理的可选库 warning；本次 fatal error 是 SBT local resolver 的复制异常，未以安装无关 FireSim workload 处理。
- 旧 `RUN_PROVENANCE=UNRESOLVED` 保持不变；本次预检不产生 ROI 或 slowdown 结果。未修改硬件功能、软件、Git index；未提交或同步 Git。

用户仍使用原命令：`/data1/gzh/EC/slowdown/run_current_gapbs512.sh`。该默认模式才会真实构建和运行 Verilator；本轮没有执行它。
