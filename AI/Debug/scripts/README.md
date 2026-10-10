# 可复用 Debug 工具

默认所有生成缓存进 `AI/TMP`；不自动删除任何 TMP 文件。长期脚本保留在本目录，原始 hash 与更新状态在 provenance 清单。shell profile 已修复 repo root，并要求显式 FST 文件以避免把历史时间窗当当前证据。

| 工具 | 输入 → 输出 | 依赖 / 验证边界 |
|---|---|---|
| ec_fst_trace.sh + fst_signal_trace.c | FST、START、END、POSIX ERE → time/path/binary value | bash、C、Verilator gtkwave fstapi/fastlz/lz4、zlib；自动构建到 TMP；仅选定 signal/time，FST_TRACE_FINAL 才扫到末尾 |
| summarize_trace.py | 提取文本/标准输入 → final/count 或 JSON | Python stdlib；默认不积存 events；不解释位值为十进制 |
| trace_profile.sh | 显式 FST、profile、start/end → 窄 trace | watchdog/assert21/assert22/assert24/boot-deadlock；正则为起点，需核对 hierarchy |
| trace_*.sh | 显式 FST、可选窗口/模式 → 历史 signal profile | bash；profile 时间属于原 run，输出空信号集报错 |
| check_debug_invariants.py | repo → source marker/ready/overflow/cleanup 提示 | Python、rg/git；marker 检查不能证明语义/无环/动态正确 |
| check_assert24_hardware_fix.sh | repo source → 历史 marker；--compile 可编译 | bash/rg/git/sbt；PASS 只是 marker，不能作为 invariant proof |
| capture_run.py | run-id、输入日志/波形/RTL/software → manifest 与日志副本 | Python/git；大型文件默认记录 path/size/hash，可 --copy 显式复制；不清理 TMP |
| check_workspace.py | workspace → 分类/链接/大文件/AI 路径与保留证据检查 | Python；--verify-retained-hashes 检查原样保留证据 hash，已删除原件只查删除状态 |

常规示例：

```sh
AI/Debug/scripts/capture_run.py run-20261010 --artifact path/to/run.fst --artifact path/to/Frontend.sv
AI/Debug/scripts/ec_fst_trace.sh path/to/run.fst 100 300 'core\.(package_|lsl\.)' > AI/TMP/run-20261010/trace.txt
AI/Debug/scripts/summarize_trace.py AI/TMP/run-20261010/trace.txt
AI/Debug/scripts/trace_profile.sh path/to/run.fst watchdog 0 2000
```

profiles 用于选信号；波形是 FST 时后缀可为 .vcd。真 VCD 需独立转换到 TMP 后读取。`regression_cases/README.md` 说明手写回归源码的依赖与历史验证级别。case-specific `audit_diff.py` 留在历史 evidence，不能对最新 HEAD 直接重跑覆盖原 patch 记录。

Typst验证命令（CLI已安装时）：

```sh
typst compile AI/DebugFlow.typ AI/TMP/DebugFlow.pdf
```

本次使用隔离安装的Python typst0.15实际编译2页、pdftoppm渲染检查；临时编译工具按收尾授权清除。以后可以直接用既有Typst编译器，或把临时工具安装到TMP。不在长期区保存编译缓存。
