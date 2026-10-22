# 可复用 Debug 工具

Stage3 唯一入口（2026-10-19）：
`bash /data1/gzh/EC/AI/Debug/scripts/stage3/stage3_run.sh`，不接受参数。
自动 BUILD → DIRECTED → SYSTEM，任一步失败立即停止；不要求设置 STAGE3_ROOT。
每次创建 `AI/TMP/stage3_runs/run_*`，打印实际路径并保留现场。旧阶段只读复用，
核验 HEAD/source、输入/工具/环境、模型、trace/checker 和完整上游依赖；
仅 PASS 文件或时间戳不能复用。失败、中断及 provenance 不匹配的阶段在新目录重跑。
定向必须 19/19（原18项及lineage-unaware peer项）、END PASS、correctness error=0；整机必须 Stage1/Stage2/Stage3
及 progress/drain 全通过。不自动运行 offline tests，不把静态审查标为硬件通过。
Stage3在capture输入前自动准备已变更/缺失的软件manifest，保留旧manifest和独立ELF目录；
实际ELF须满足timer counter逐hart独占64B block。源码未变但artifact hash错误直接失败。
因此修改timer控制域后仍只执行同一入口，无需另外手工编译软件。
旧人工分阶段 wrapper 已删除。详细失效规则见
[单入口运行器交接](../history/reports/stage3_runner_20261018.md)，协议覆盖边界见
[Stage3 设计](../../Design/stage3_l2_preservation_20261018.md)。
命令失败/超时或 module 生成不完整时，终端汇总同次日志的全部不同错误/失败诊断，
保留 `<log>.errors.out/json`（含行号、上下文、原始退出码和日志 hash）。
固定 summary 增加 RAW_EXIT_CODE、FAILURE_DIAGNOSTIC_COUNT、FAILURE_ERRORS_TEXT/JSON；
诊断数包含编译器汇总，不等于独立根因数。不会为收集错误继续运行后续阶段。
最新 run_ybxmr7og 的首Acquire已Grant/commit/free，P/Q preservation尚未进入，
host idle在首CASE timeout。根因是reset cycle0假B被新增Probe账本记录，pendingProbes
永久不空；现统一reset记账门控，不清活跃账本、不删drain/改timeout或barrier。
硬件drain四条件/全部入口已静态复审，补SourceD/C busy masks、preservation状态、
Scheduler诊断透出和有限日志；任何until超时打印含CASE/cycle/host队列/硬件子条件
的 `DRAIN_BLOCKER=<具体项>`。详见 [drain liveness审计](../history/reports/stage3_drain_liveness_audit_20261019.md)。
此前capability与flush提交域修复保留，原72条普通transition表及assertion不改。
静态工具 `stage3/transition_audit.py` 仅解析九状态与布尔表，不生成/模拟 RTL，
明确区分 NORMAL/FLUSH/EVICT/BYPASS；18 CASE 路径族为人工审计映射。
完整 [第二次失败与18 CASE审计](../history/reports/stage3_tip_invalid_config_audit_20261019.md)、
[允许/禁止矩阵](../history/reports/stage3_transition_matrix_20261019.md)。
本轮仅静态检查，原单入口需 fresh build/directed/system；生产及 fixture hash
参与 BUILD provenance，旧模型及其下游自动失效，旧 run 保留。
PassExceptions 摘要优先显示具体 FIRRTL 错误，完整批量报告和 fail-fast 保持。

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

## Stage 2：L1 preservation（已关闭）

最新运行 `AI/TMP/stage2_validation_agciqdp_/` 的 build/directed/system 均 PASS/exit0，
33 pin wiring、10 CASE、整机 Stage1/Stage2 checker 与退出排空已完成。
当前11479 source/16 scripts/fixture与该run完全匹配，本轮没有功能/checker/trace修改。
详见[最新证据与关闭边界审计](../history/reports/stage2_evidence_audit_20261018.md)。
现有 PASS 已满足当前 Stage 2 safety closure；本轮没有重建或重跑硬件。以下入口仅供
后续源码变化后的重新验证，不是当前 closure 的前置条件。最终状态为
`STAGE2_STATUS=CLOSED`、`NEXT_SIM_REQUIRED=NO`。

一条命令：`/data1/gzh/EC/AI/Debug/scripts/stage2_build_and_run.sh all`。从原 Stage 1 环境的任意工作目录启动，脚本自行定位项目并创建唯一的 `AI/TMP/stage2_validation_*/`；`all` 不复用继承的旧 `STAGE2_ROOT`，无需 cd/export。按用户要求移除重复的已通过离线检查，严格串行 build → directed → system，后阶段强制前阶段 PASS 和完整来源一致；失败/缺覆盖停止，保留日志，不自动重试。构建前仍保存源码/fixture、工作负载、工具、环境与构建参数清单，不依赖或伪造 OFFLINE=PASS。

保留 `offline|build|directed|system` 分步入口和已有 `module` 别名。`offline` 仅显式调用时运行，无硬件；`build` 可独立创建新 root，生成/编译两个模型但不运行；`directed` 与 `system` 各一个仿真进程。directed 现含 10 个 CASE；新增实际 L2 MSHR→SourceD 的 denied Put/AMO 与成功对照，检查真实 schedule、directory、bank、D 事件，没有额外仿真进程。

若 directed 在运行期失败，`stage2_test.cpp` 会先输出带 case 的
`STAGE2_CHECK_FAIL`；preservation 的 C beat 前置条件还会区分请求未发出、
未形成停顿和观察到的 valid/fire。runner 会把同次日志中的所有结构化失败、
缺失/未运行 CASE、独立 effect 判据和 denied/成功 L2 事件缺口写入
`directed.coverage.json`，并在终端的失败原因中一并列出；旧 generated model
与当前源码不匹配时不能复用。

定向 fixture 的 sbt 显式使用 `-J-Xms512M -J-Xmx8G -J-Xss8M -J-XX:+ExitOnOutOfMemoryError -J-Dsbt.supershell=false`，参数计入 inputs.json 和匹配门禁。原直接调用 sbt 绕过 Stage 1 Makefile 的 8G 默认，用户运行发生 1G 堆 OOM；sbt 后台异常即使返回 0，也会被异常日志、生成完成标记与完整 RTL 产物检查拦截，失败直接指向 `module.emit.log`，不再只报缺文件。

fixture 消费实际 L1 的 33 个 BoringUtils source：保留控制/统计和 exit probes；已经由 TL CacheImage 替代的 64 个旧地址 CAM 发布端及对应 fixture sink 一并移除。生成时在 WiringTransform 前逐 pin 检查 source/sink，报告所有缺失/重复连接及目标，保存 `generated/stage2.wiring.out`；该报告必须成功并计入构建产物 hashes。定向 Verilator lint/build 使用 `--error-limit 0` 收集同次调用能继续发现的错误，保留原结构错误和覆盖门禁。

`Stage2WiringAudit` 必须是公开的顶层无参类：本地 FIRRTL 1.5.5 会把普通 transform 实例转成类依赖后再反射构造。每次报告路径从 CircuitState 的 `TargetDirAnnotation` 获取，缺失时明确失败。EmitModule 在 elaboration 前用真实 `Dependency[Stage2WiringAudit].getObject()` 提前检查构造契约；当前33 pin版本已在agciqdp_的完整构建中通过。

失败时终端输出原日志里全部不同的错误/失败诊断（过滤重复堆栈），保存 `<原日志>.errors.out` 和 `.errors.json`，包含原行号、清晰文本及原始文本/上下文、原始退出码和日志 hash；过滤被 sbt 误标为 error 的普通 JVM options 提示及 ANSI 控制序列，FIRRTL generic Internal Error 的摘要选实际 Caused by。整机构建失败还读取本次实际最终 appended annotation，一次列出所有缺失/重复 source/sink 与目标，保存 `system.wiring.out/json` 并并入错误汇总；缺失/损坏/仅数量一致均不会报告硬件 PASS。status 与 summary 给出汇总绝对路径。前阶段失败时后阶段仍为 NOT_RUN；不重复自动构建，不恢复已移除的自动 offline。

终端中文输出各阶段状态、失败原因/首个错误和绝对日志路径；完整运行记录 `runner.log`，总摘要 `summary.out`，各阶段 `*.status.json`。工具失败保留原始返回码（信号换算 128+信号）；判据失败返回 1，覆盖缺失返回 3，参数/缺工具返回 2；工具恰好返回 3 时仍记录 FAIL，不能混同 UNCOVERED。历史修复见 [整机 CAM 连线与错误摘要](../history/reports/stage2_system_wiring_fix_20261018.md)、[审计类无参构造修复](../history/reports/stage2_audit_ctor_fix_20261017.md)、[wiring 与完整错误汇总](../history/reports/stage2_wiring_build_fix_20261017.md)、[OOM 修复](../history/reports/stage2_emit_oom_fix_20261017.md)。当前覆盖范围与独立判据以最新证据审计为准；不能把首错退出后的未运行CASE或精确同拍race当作动态覆盖。

历史 r8baqbfq 的 CAM 连线失败、d5wr10l1 的 epoch 请求阻塞已由后续 agciqdp_ 越过。
本轮只审计已有证据，没有编译/生成/仿真或单元测试；没有修改运行输入，也没有覆盖原run。
