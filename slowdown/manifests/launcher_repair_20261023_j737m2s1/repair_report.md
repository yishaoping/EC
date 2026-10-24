# Current launcher 环境故障修复与系统检查

日期：2026-10-23（Asia/Shanghai）。根目录：`/data1/gzh/EC`。

## 结论与证据边界

- `DIRECT_EVIDENCE`：已复现并修复本次 `bwrap: Can't mount proc on /newroot/proc: Operation not permitted`。该失败发生在 Java 启动之前，不是 Java、RTL 或 workload 报错。
- `DIRECT_EVIDENCE`：发现另一项工具身份错误：旧 PATH 首先找到 Conda Verilator **4.226**，而记录和计划使用的是 Nix Verilator **5.048**。现在 Make 实际按名称调用和预检按名称调用都经过各次 build 私有的 `tool-bin`，解析到同一组固定工具。
- `DIRECT_EVIDENCE`：最终完整环境预检 14 项全部 PASS；没有执行 SBT project load、编译、硬件生成、仿真或 workload。环境预检通过不构成后续构建成功证明。
- `UNRESOLVED`：SBT meta-build load、完整依赖解析、Scala/Chisel 类型检查、RTL generation、Verilator 编译以及实际仿真行为仍待用户正式执行。没有产生新 ROI 或 slowdown 结果。旧 `RUN_PROVENANCE=UNRESOLVED` 保持不变。

## 原始症状、直接原因及修复

原始失败运行：`slowdown/runs/current_20261023_210803_35f4e8e0/`；原始日志：`slowdown/build/current_20261023_210803_35f4e8e0/java.version.txt`。原文件均未修改。

`DIRECT_EVIDENCE`：`sandbox_capability.json` 对同一无害 Python 命令进行了三种隔离策略检查：

| 策略 | 返回码 | 结果 |
| --- | --- | --- |
| 原参数，显式 `--proc /proc` | 1 | 与用户报错相同，尚未进入目标程序 |
| 只读 root 继承现有 proc | 0 | Python 和 `/proc/self/status` 读取成功 |
| 显式 `--ro-bind /proc /proc` | 0 | Python 和 `/proc/self/status` 读取成功 |

`STATIC_INFERENCE`：本机内核/宿主策略拒绝此 user namespace 中的新 procfs 挂载；尚未进一步确定到某条内核/LSM 规则。无需更改系统策略即可避免这一操作。

修复采用 `scripts/sandbox_support.py` 中的共享策略：现有 `/proc` 只读绑定，仍使用 `--unshare-all`、只读宿主 root、私有网络 namespace、私有 `/tmp` 和 `/var/tmp`。没有无沙箱回退，没有改为可写宿主 proc。离线 `analysis/extract_trace.py` 中同一处潜伏问题也改为调用共享策略。

## 集中排查及防复发

1. `DIRECT_EVIDENCE`：工具身份检查暴露 PATH 遮蔽。`runtime_probes.json` 记录第一次 PATH 检查失败；`shadowing_verilator_version.log` 确认原 Conda 程序是 4.226。最终 `verilator.preflight.log` 记录从 Make 同样的名称查找路径运行的 5.048。
2. `DIRECT_EVIDENCE`：新增 `--preflight-only`，在正式使用的环境、只读 root 和 SBT 私有 meta-build/target 挂载下执行。默认正式运行也自动执行这一预检；任何预检失败都在编译前停止。
3. `DIRECT_EVIDENCE`：11 项工具版本、实际 PATH 解析、只读 mount flags、网络 namespace、4 个 libc tmpfile/mmap、临时 sidecar、私有 `/tmp`/`/var/tmp`、SBT UNIX socket、zlib 1.2.13 ABI、SBT adapter 命令及缓存 JAR 存在性/大小检查通过。SBT adapter 只打印 argv，不执行 JVM/SBT。
4. `DIRECT_EVIDENCE`：预检会完成彼此独立的检查后汇总错误。对 Java 和 Make 同时注入无害、明确非零退出的诊断程序，两项均记录 FAIL，其他检查继续完成，14 项结果完整保留；不会进入编译。
5. `DIRECT_EVIDENCE`：对两个准备文件的错误哈希使用独立 manifest fixture，身份检查同时报告两项漂移。没有修改真实源码或原始输入，也没有增加自动接受漂移的入口。
6. `DIRECT_EVIDENCE`：预检命令有超时及子进程清理，实测 0.2 秒超时会回收无害等待进程并保存退出状态。生产构建命令也补充中断清理和逐命令 manifest 持久化；未通过启动真实构建测试中断。
7. `STATIC_INFERENCE`：依赖缓存首次复制改为暂存目录复制成功后原子重命名，避免中断的半份缓存被目录存在性检查误认为完整。当前 88 个 SBT boot JAR 和 355 个 Coursier JAR 均存在且大小与 Baseline 缓存一致；未据此声称完整依赖闭合。
8. `DIRECT_EVIDENCE`：离线提取的同一共享策略单独验证通过：旧 runs 和 reader/build 位置只读，私有输出、tmpfile/mmap/socket 可用；没有打开原始 FST，也没有运行 native FST reader。

## 验证索引

- 最终预检 manifest：`slowdown/runs/current_preflight_20261023_212208_ffc0df08/run_manifest.json`。
- 最终 14 项结果：`slowdown/build/current_preflight_20261023_212208_ffc0df08/environment_preflight.json`。
- 逐项版本及 runtime probe 日志：同一 build 目录下的 `*.preflight.log`。
- 有效多故障检查：`slowdown/build/launcher_batchcheck_6gfbk4r6/environment_preflight.json`，其 Java/Make FAIL 是主动注入的预期结果。
- 故障注入早期 fixture 不适用的记录亦保留；第一次 `/bin/sh --version` 实际是 Bash 且成功，未作为有效的第二故障证据。
- 超时、漂移、纯观测性复核及保留状态：本目录 `verification.json`、`trace_static_review.json`、`extraction_sandbox.log`。
- 修改前脚本、文档、原 preparation manifest：本目录 `before/`；Git HEAD/status/index：`before_state.json`。
- 新旧脚本差异：本目录 `repair_patch.diff`；最终身份及静态 CLI 检查：`final_acceptance.json`。

## 保留状态

`DIRECT_EVIDENCE`：Git HEAD 保持 `1697aff10cd6d086da1fc727e2679fe0a0d73f9a`，Git index 未变化。Current 源码 inventory 保持 `5df079ed630ba52e21c8ba28bf8aad5131a51e9ccfe754f1602396689e5b8757`；本次没有修改那 6 个既有 trace-only Scala 文件、Config、软件、Baseline 源码或保护机制。`DOC/Prompt.typ` 未操作。未提交、未同步 Git。

修复需要更新 `manifests/preparation.json` 中修改后的脚本/文档哈希并纳入共享隔离模块；原 manifest 已先保存到本目录的 `before/slowdown/manifests/preparation.json`。硬件/source inventory、固定 ELF/loadmem 和固定依赖身份未重新定义。以后启动仍检查身份，拒绝静默漂移。

## 后续使用

仅环境预检：`/data1/gzh/EC/slowdown/run_current_gapbs512.sh --preflight-only`。

正式一键命令保持：`/data1/gzh/EC/slowdown/run_current_gapbs512.sh`。默认命令会真实生成、编译并仿真，留给用户执行。本次修复阶段没有执行默认模式。
