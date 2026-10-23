# Baseline FST 为空：根因、修复及复用现有构建

`DIRECT_EVIDENCE`：`runs/b3_20261023_150240_wpx9m7qv/test.fst` 为 0 字节，启动器因此报 `STOP: Missing/empty required FST waveform`。同次 simulator exit code=0，四个要求的 marker 均出现，stderr 以 `*** PASSED *** Completed after 1200611 cycles` 结束。不能将这次报错解释为 workload hang 或计算自检失败；也不能把软件 marker 通过升级为完整实验/硬件正确性通过。

所有本轮修改及新增证据均位于 `/data1/gzh/EC/baseline/`。未编译软件、硬件或工具，未运行 elaboration、RTL generation、simulator 或 workload。保留原失败运行、成功构建、规范历史源码、Current 和两个 Git index。

## 因果链

| 层次 | 证据与判断 | 证据级别 |
|---|---|---|
| 直接症状 | 原运行 `test.fst` 为0字节；launcher 在软件/harness完成之后才检查波形 | `DIRECT_EVIDENCE` |
| 上游触发 | 原 bwrap 策略将 `/` 只读挂载，仅开放 baseline；没有可写 `/tmp`。设置了 baseline `TMPDIR`，但 libc `tmpfile()` 仍返回 errno=30 / `EROFS` | `DIRECT_EVIDENCE`，见 `old_policy_tmpfile.json`；使用同样挂载策略的非仿真复现 |
| 写入器创建条件 | 安装的 `gtkwave/fstapi.c:252` 调用 libc `tmpfile()`；`:1186` 起同时创建四个临时流；任一失败即在清理后返回 NULL，留下已创建但没有内容的输出 | `DIRECT_EVIDENCE`（源码）；原运行的返回值未被记录 |
| 直接阻断 | 该挂载策略必然阻止上述临时流创建，因此无法成功创建 FST writer，完整解释0字节输出；现有 simulator 动态符号确实引用 `tmpfile@GLIBC_2.2.5` | `STATIC_INFERENCE`，由源码、链接符号、原运行命令和最小复现闭合；未声称拥有原进程 syscall trace |
| 错误被放大 | `gen-collateral/emulator.cc:295` 注册 trace，`:296` 调用 `tfp->open()`，没有 `isOpen()` 检查。`verilated_fst_c.cpp:103` 起也未将 NULL writer 转换为启动失败。于是计算继续，直到完整运行后才由外部脚本发现波形为空 | `DIRECT_EVIDENCE`（源码）与 `STATIC_INFERENCE`（原运行机制） |

排除的直接解释：不是未传 `-v`（原 argv 明确传入新运行目录 `test.fst`）；不是关闭 FST 构建（原 build.log 包含 `--trace-fst`、`VM_TRACE=1`、`VM_TRACE_FST=1`、`CY_FST_TRACE`）；不是正常循环尚未结束（exit=0，有最终完成 marker）；不是仅因文件后缀不匹配。

源码边界：所引用 driver 来自成功构建的 `generated-src/chipyard.TestHarness.v1Config/gen-collateral/emulator.cc`；Verilator writer 来自 build.log 所使用的 `/data1/gzh/EC/chipyard/.conda-env/share/verilator/include/`，不是将 Current RTL 作为历史硬件证据。

## 实际修复

1. `launch_baseline.py::invoke()` 将沙箱的 `/tmp` 和 `/var/tmp` bind 到该次命令的 baseline 私有临时目录。物理写入仍在 baseline，宿主 `/tmp` 不开放写入；Current 和规范 `source/` 保持只读，继续禁网。拒绝目录外、symlink 或规范历史源码内的 TMPDIR。
2. 新增 `runtime_io_probe.py`：实际检查挂载身份、四个同时打开的 libc `tmpfile()`、读写/mmap、输出及相邻 `.hier` 文件权限和 TMPDIR I/O。隔离条件失败时跳过所有创建文件的步骤，避免有人直接调用探针而向宿主临时目录写入。既在通用预检执行，也在确切的新运行目录、确切的运行环境下再次执行；失败就停止，不进入 simulator。
3. 新增独立日志观察逻辑。先保存 marker、退出码、harness cycles、ROI 和自检结果，再判断波形；增加 `waveform_bytes`、`waveform_status`。波形为空仍然使本次 run 失败，但不会再丢失已观测的软件完成信息。波形非空仅记为 `NONEMPTY_NOT_DECODED`，不伪称已验证 FST 内容或完整实验正确性。
4. 增加实际沙箱 I/O、无隔离拒绝执行、危险 TMPDIR、探针失败、空波形失败时保留 ROI、错误 ROI 和进程失败的回归覆盖。未改变硬件功能、软件二进制、workload、计时边界或退出/drain 语义。

`DIRECT_EVIDENCE`：最终19项基础设施回归通过，详见 `regression_checks_final.log`。这些检查没有调用真实 simulator；涉及 run 生命周期的检查使用明确的假日志和假调用。实际执行的原生检查仅为 libc/文件系统 I/O。Python AST 和 Bash 语法检查通过；`--check --workload .../gapbs512_20261023_03/workload.json` 静态检查通过。没有重新执行 SBT 依赖解析或完整构建预检。

## 原运行的观测值

`DIRECT_EVIDENCE`：只读解析原始 stdout/stderr，结果另存 `observed_run.json`，没有改写原 manifest。

- 软件 ROI：`1182700 - 181025 = 1001675 cycles`；hart0 cycle计数器，沿用软件 ROI 合同。
- Harness：`1200611 cycles`，沿用 emulator 的 trace_count 定义，不能与上述 ROI 互换。
- BFS：nodes=512，source=0，reached=512，edges=8192，verified=1，checksum=43439728。
- `cache_package_drain=UNRESOLVED`；marker只证明约定范围内的软件自检通过。

`UNRESOLVED`：原运行缺少波形，无法从日志恢复信号历史。本轮未验证修复后的实际 FST 内容，也未验证完整package、缓存和恢复正确性。不做净slowdown推断，保持 `RUN_PROVENANCE=UNRESOLVED` 和 `BASELINE_GAPBS_COMPARISON_IS_APPROXIMATE`。

## 用户下一步

`DIRECT_EVIDENCE`：只读执行现有 `verified_build()`，成功核验 simulator、generated model和执行源码副本身份（包括已记录的资源恢复）。因此修复此挂载问题不需要重新生成或编译 simulator。

构建：`/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/`。

Simulator SHA256：`987a86fcbaee7a113912233b303b318da774550710a4aa9879f38f9d64b00ae2`。

用户执行下列命令，只复用现有构建并创建全新运行目录：

```bash
/data1/gzh/EC/baseline/start_baseline_experiment.sh \
  --run /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp \
  --workload /data1/gzh/EC/baseline/software_common_builds/gapbs512_20261023_03/workload.json
```

上述仿真命令本轮没有执行。下一次正式运行应先显示 `RUNTIME_IO_PREFLIGHT=PASS`，再启动 simulator；完成后仍需检查实际非空 FST和原有正确性证据，不能仅凭预检承诺全部运行结果。

## 证据文件

- `before.json`：修复前源码/脚本、原运行、构建及软件产物、Git index和Prompt的大小与SHA256，及HEAD/工作区状态；`*.before` 为被修改文件的先前内容。
- `old_policy_tmpfile.json`：旧挂载策略的真实 libc最小失败复现；没有启动硬件模型。
- `existing_build_verification.json`：现有构建只读身份核验；没有执行simulator。
- `observed_run.json`：原始运行的独立解析记录；原运行结果仍为FAILED。
- `regression_checks.log`：中间18项回归结果；`regression_checks_final.log`：最终19项结果。
- `syntax_checks.txt`：最终Python语法结果；Bash `-n` 同样通过。
- `positive_runtime_probe.json`、`validation.json`：修复后实际沙箱探针、检查汇总。
- `preservation.json`：最终输入保全与Git状态核对；无原始运行/构建产物改动。
