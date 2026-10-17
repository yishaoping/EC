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
| stage1_prepare_workload.sh + stage1_workload.py | 当前 Test source → 独立 ELF/dump/loadmem + 软件 manifest | 仅软件编译；保留原 test.riscv；验证 directed AMO.W 双 lane 和 `_exit` 符号身份 |
| stage1_provenance.py | 构建前后 source + 全 generated debug model + simulator → provenance gate | schema 2；要求 EXIT_DRAIN/CLEAR_CHECK 等 markers；run 时不能补写或更新 manifest |
| stage1_run_trace.sh | 已验证 workload/model manifests → 新 run、FST、trace、统一 scoreboard | 只启动一次 simulator；默认 FST；运行失败也保留分析；不触发构建 |
| stage1_trace_scoreboard.py | trace + workload manifest → 流式 lifecycle/AMO/clear/accounting/exit gates | `--workload`、`--json`；缺证据 UNRESOLVED；0=PASS，1=FAIL，2=UNRESOLVED |
| test_stage1_trace_scoreboard.py + test_stage1_provenance.py + test_stage1_exit_policy.py | 离线 synthetic trace/临时文件 → 32 项正负例 | Python `unittest`；exit predicate 用 g++ 编译独立 FakeHarness，不加载 RTL/generated model 或 simulator |
| stage1_build_and_run.sh | 当前 source → 一次新 debug build → provenance → 一次 workload run | `AI/TMP/stage1_closure_build_XXXXXXXX`；拒绝复用已有目录，不覆盖历史 simulator/output |

常规示例：

```sh
AI/Debug/scripts/capture_run.py run-20261010 --artifact path/to/run.fst --artifact path/to/Frontend.sv
AI/Debug/scripts/ec_fst_trace.sh path/to/run.fst 100 300 'core\.(package_|lsl\.)' > AI/TMP/run-20261010/trace.txt
AI/Debug/scripts/summarize_trace.py AI/TMP/run-20261010/trace.txt
AI/Debug/scripts/trace_profile.sh path/to/run.fst watchdog 0 2000
```

当前 Stage 1 状态为 `CLOSED`；最终九项动态 closure、计数和非阻塞 coverage 观察见
[2026-10-17 closure audit](../history/reports/stage1_closure_20261017.md) 第 11 节，最终 run 为
`AI/TMP/stage1_closure_run_g3Y7Oi9x`。不需要新的 Stage 1 仿真。
原 [2026-10-16 readiness](../history/reports/stage1_readiness_20261016.md) 是本次运行前的历史准入。
当前 `AI/TMP/stage1_workload.json` 对应 directed AMO.W + BFS + 有限 HTIF exit 的独立 ELF；
修改软件后用以下独立入口重建（不触发硬件工具）：

```sh
/data1/gzh/EC/AI/Debug/scripts/stage1_prepare_workload.sh
```

经用户决定开始昂贵验证时，完整入口为：

```sh
/data1/gzh/EC/AI/Debug/scripts/stage1_build_and_run.sh
```

它先验证软件 source/ELF/dump/loadmem hashes，再创建全新 build 目录并构建当前
working tree，写入 provenance 后只运行一次 simulator。脚本自身没有重试或测试集循环。
默认 `STAGE1_WAVEFORM=1`，输出在新的 `AI/TMP/stage1_closure_run_XXXXXXXX/`：
`trace.fst`、`trace.log`、`run.json`、`simulator.status`、`scoreboard.out/json`，
以及本次 provenance/workload/analyzer 副本。build 日志为新 build 目录的 `build.log`。

配置均为环境变量，不能传位置参数：`STAGE1_WORKLOAD` 指定软件 manifest；
`STAGE1_SIM_ROOT`/`STAGE1_RUN_ROOT` 可指定尚不存在的目录；
`STAGE1_WAVEFORM=0` 可显式关闭 dump。build wrapper 拒绝旧 `STAGE1_BUILD_ROOT`
和直接 binary/generated/provenance overrides。单独 run launcher 必须显式提供
`STAGE1_SIM`、`STAGE1_GENERATED`、`STAGE1_PROVENANCE`，只校验已有身份。

`ARCH_STORE` 是不受统计资格过滤的功能提交；request/effect token 贯穿
S1/S2、replay、EFFECT、TERMINAL、STORE_DONE、RELEASE。INSTALL/REFILL 使用
line/slot/epoch/MSHR/transaction 关联，checker 用稳定 package seq 关联统计。
`CLEAR_CHECK` 支持实际 clear overlap 的自动 invariant 检查。
`EXIT_DRAIN snapshot=sim_exit`/`EXIT_STQ` 来自最后一次正常 eval 后的 live RTL
输出，不用 traffic_stop 替代退出。停驻预取 owner 与活动 MSHR 分开计数。
`_exit` 仅按 manifest + 精确 live STQ owner 分类，不能豁免已接受事务或丢失 effect。

2026-10-17 的统计资格由 R_IC `producer_open && if_correct_process` 统一定义，
LSQ 锁存后跨 retry/STOP 尾部保持；单个 fsm_check 状态不能代表整个 package 生命周期。
analyzer 的 JSON `accounting_sets` 输出 MAIN_ONLY/CHECKER_ONLY 与 DUP_IN_MAIN/DUP_IN_CHECKER，
按 occurrence 保留循环访问次数。checker 新 trace 的 `(hart,ordinal)` 才是独立 event identity；
旧日志缺该身份且其余计数已相等时为 UNRESOLVED。负 PC 差按绝对差完整显示；
counter snapshot 必须和全部 trace events 相符，完全缺事件也不能假 PASS。
软件 ASSERT/END 的 FAIL 单独进入 software_report gate；缺 END 状态不能完整 closure。

Stage 1 build 的 `STAGE1_EXIT_PORTS` 还启用 emulator 的真实排空退出策略：host success
先锁存，继续正常 eval，待 `stage1_exit.h` 检查 cache/LSU 无活动工作才成功退出。
没有固定附加周期，原 max-cycles 上限与立即失败退出保留。软件 `_exit` 只写一对
fromhost/tohost，fence 后停驻，避免排空期间不断产生新 L1 工作。
新关键 LSU events 使用 DCache 同一 CSR cycle；LOAD_TERMINAL 增加 seq/check，
KILL/RACE_OBSERVE 记录 kill/replay 条件。并发 coverage 按周期计数，零次须标 NOT_OBSERVED。

离线检查命令（不启动仿真）：

```sh
python3 -B -m unittest discover -s AI/Debug/scripts -p 'test_stage1*.py'
python3 -B AI/Debug/scripts/stage1_trace_scoreboard.py path/to/trace.log --workload path/to/workload.json --json path/to/scoreboard.json
```

只有 verified、serial_success、全部 closure gates 和必需 coverage 都通过，
才输出 `STAGE1_TRACE=PASS`；缺快照或覆盖返回 UNRESOLVED，不能把错误计数为零当完成。

profiles 用于选信号；波形是 FST 时后缀可为 .vcd。真 VCD 需独立转换到 TMP 后读取。`regression_cases/README.md` 说明手写回归源码的依赖与历史验证级别。case-specific `audit_diff.py` 留在历史 evidence，不能对最新 HEAD 直接重跑覆盖原 patch 记录。

Typst验证命令（CLI已安装时）：

```sh
typst compile AI/DebugFlow.typ AI/TMP/DebugFlow.pdf
```

本次使用隔离安装的Python typst0.15实际编译2页、pdftoppm渲染检查；临时编译工具按收尾授权清除。以后可以直接用既有Typst编译器，或把临时工具安装到TMP。不在长期区保存编译缓存。
