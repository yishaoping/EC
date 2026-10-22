# Stage 2 生成 OOM 与重复离线检查修复（2026-10-17）

当前状态 `PATCHED_PENDING_REBUILD`。本次修复对应用户运行 `AI/TMP/stage2_validation_qodffn_8/`，没有重新运行构建或仿真。没有已知需要在下一次构建前修复的阻塞；8G 是否足以完成生成，以及全部硬件行为，仍待真实运行。

原始证据 `module.emit.log:57` 显示 Scala compile 已完成，上一处 Probe API 错误已消失。第 60 行 GC 诊断显示 heap/max 均 1.00GB，第 61 行为 `Exception in thread "sbt-bg-threads-1" java.lang.OutOfMemoryError: Java heap space`，堆栈进入 Chisel/FIRRTL 转换。随后 sbt 打印 success，`commands.jsonl` 记录 raw exit 0，`generated/` 为空。旧 runner 最终只报 `no freshly emitted Stage2Harness.v`，且 build.status 的 first_error 为空。原失败副本、日志和状态保留，没有修改。

根因链：module 直接调用 sbt → 绕过 `chipyard/variables.mk` 的 `JAVA_HEAP_SIZE ?= 8G` → 本地 sbt launcher 使用 `sbt_default_mem=1024` → 生成阶段 Java heap OOM。sbt 的后台异常没有使进程返回非零，进一步掩盖真实错误。没有证据表明顶层文件名错误。

实际修改：

- `scripts/stage2_validation.py`：module sbt 显式传入 `-J-Xms512M -J-Xmx8G -J-Xss8M -J-XX:+ExitOnOutOfMemoryError -J-Dsbt.supershell=false`，写入 schema 3 的 inputs.json，仍参与源码/参数/环境匹配。`first_error` 识别 JVM OOM/异常；exit 0 后还检查异常日志、顶层 RTL 和正常完成标记，失败保留 raw code 0、返回判据失败 1，指向原始 module.emit.log。
- `scripts/stage2/Stage2Generate.scala`：仅在 emitVerilog 正常返回后打印 `STAGE2_EMIT=PASS top=Stage2Harness`；保留上次修复的 `TLMessages.Probe`。
- `scripts/stage2_build_and_run.sh` 与 runner：按用户要求 all 仅执行 build → directed → system。离线测试保留为显式 offline 选项，不自动重跑，不报告虚假的 OFFLINE=PASS。构建前独立捕获源码、fixture、工具、参数、环境及 workload；继续拒绝缺失/变化的 fixture、不同来源和被修改的产物。build 可独立初始化新 root，all 仍每次创建唯一 root，失败不重试/覆盖。
- `scripts/test_stage2_validation.py`：覆盖跳过 offline 但保留快照、三阶段串行/失败停止、初始化失败、JVM 参数进入来源清单、sbt exit 0 + OOM、部分 RTL/缺完成标记、原错误与 raw code 的持久记录。所有硬件动作均替换，无硬件生成或模型执行。

本轮检查证据在 `AI/TMP/stage2_emit_oom_fix_v_0k0s2e/`。首轮 41 项运行器测试通过；最终补充跨阶段 OOM 失败记录用例后，42 项运行器测试通过，另有 Python AST、shell syntax、diff 检查。只读复查原失败日志可准确返回 OutOfMemoryError、原日志绝对路径和 raw code 0，见 `saved_failure_recheck.json`。最终检查记录和源码 hashes 见 `final.checks.json`。没有重跑完整 offline suite，也没有执行 Scala compile、硬件生成、elaboration、FIRRTL、Verilator、仿真或最终 all。

下一步仍是一条绝对路径命令 `/data1/gzh/EC/AI/Debug/scripts/stage2_build_and_run.sh all`，由用户在原 Stage 1 环境执行。失败先看终端指明的原始日志，再看同一新 root 的 runner.log、summary.out 和阶段 status；本处 OOM 对应 module.emit.log。当前测试通过只表示运行器的受测行为通过，不能代替硬件验证。
