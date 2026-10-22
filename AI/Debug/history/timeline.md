# Debug 演化时间线

| 时间/标识 | last good → first bad | 根因/状态 | 证据位置 |
|---|---|---|---|
| 2026-10-21 / Stage3 final closure evidence | `run_qx63gyhc` BUILD/DIRECTED/SYSTEM PASS → all closure gates PASS | 19/19 directed CASE、Stage 1/2/3 scoreboard、architectural data、main/checker、effect/terminal/release、clear/refill、progress、exit drain 和 provenance/seals 全部通过；同一 metadata-clear witness 完成 `PRESERVE_DONE → CLEAR_CHECK fire → EFFECT → TERMINAL → RELEASE`。Stage 3 closure YES；bounded v1Config/workload evidence，未改 RTL。 | `history/reports/stage3_closure_evidence_20261021.md`、`AI/TMP/stage3_runs/run_qx63gyhc/` |
| 10-19 / Stage3 host drain timeout | run_ybxmr7og 首 Acquire 已Grant/commit/free → host idle timeout，P/Q preservation尚未进入 | reset cycle0假B被上轮新增Probe账本记录，pendingProbes永不空；统一reset握手记账门控，保留drain/timeout/barrier，审计九入口及Probe/trusted写，补硬件四子条件与DRAIN_BLOCKER；仅静态检查，PATCHED_PENDING_REBUILD | `history/reports/stage3_drain_liveness_audit_20261019.md`、`AI/TMP/stage3_drain_audit_99ciq6nn/` |
| 10-19 / Stage3 第二次动态 TIP→INVALID | run_e23qwk6h m=true、首 CASE PASS → full_provenance_collision 的 cleanup flush(b) assertion | C 类：ACK 后延迟 INVALID 提交误入普通 transition 域；保留原72表项，新增严格 flush terminal proof，统一六状态路径；修 fixture B 地址恢复、审计18 CASE与生命周期/有限事件日志；仅静态检查，PATCHED_PENDING_REBUILD | `history/reports/stage3_tip_invalid_config_audit_20261019.md`、`history/reports/stage3_transition_matrix_20261019.md`、`AI/TMP/stage3_config_audit_quv22_u8/` |
| 10-19 / Stage3 首次动态 INVALID→TIP | run_1_d9fdyq BUILD PASS → 首 CASE 收尾 Get(b) miss assertion；SYSTEM NOT_RUN | C 类 fixture：将 uncached Get/Put source 声明成 Probe client，m=false 误拒正常 miss→TIP；并发 Get 还复用 source1。改为 coherent0/non-probe1–2、独立 source 和 CASE/source 诊断；生产FSM/表/assertion不改，仅静态审查，PATCHED_PENDING_REBUILD | `history/reports/stage3_invalid_tip_fixture_fix_20261019.md`、`AI/TMP/stage3_invalid_tip_fix_3slovmd6/` |
| 10-19 / Stage3 SerialTL echo | run_vsb0kdix module 生成/lint/build exit0 → 整机 FIRRTL 3处 echo 未初始化 | merged serial packet 未编码/解码 echo；补 A/C/D 双向透传和同路径 TLRAM/TLROM 返回身份，摘要显示具体错误；仅静态审查，未重新构建/仿真，PATCHED_PENDING_REBUILD | `history/reports/stage3_serdes_echo_fix_20261019.md` |
| 10-18 / Stage3 compile API and batch diagnostics | run_5hyf3lau BUILD FAIL，DIRECTED/SYSTEM NOT_RUN → 最小修复待重建 | SinkC 的 Chisel legacy import 未暴露 chiselTypeOf，改明确 chisel3 引用；runner 失败/超时/生成不完整汇总全部日志诊断并保存原码/路径；仅语法与静态 review，未构建/仿真，protocol 未改 | `history/reports/stage3_compile_diagnostics_20261018.md` |
| 10-18 / Stage3 automatic runner | 人工 build/directed/system → 单一无参入口 | immutable run、按 HEAD/source/模型/上游依赖复用、18/18 与零 correctness error、系统三阶段 checker/progress 门禁；旧 wrapper 删除；只做语法/静态检查，protocol 未改，未构建/仿真 | `history/reports/stage3_runner_20261018.md` |
| 10-18 / Stage3 source implementation | Stage1/2 closure → L2 full-path static RCA | same-line checkpoint/receipt、victim ACK gate、ProbeAckData gate、完整 echo/provenance、18 CASE 和分步手动入口；静态 review PASS，用户禁止的编译/生成/仿真/回归均未运行；PATCHED_PENDING_USER_BUILD | `history/reports/stage3_static_20261018.md`、`AI/Design/stage3_l2_preservation_20261018.md` |
| 10-18 / Stage 2 L1 preservation closure | agciqdp_ build/directed/system PASS → safety invariant closure | 21项 closure 条件全部 PASS；receipt+probe/reﬁll 精确同拍由 RTL priority/owner/drain/epoch/full-key 静态推出，列为非阻塞 coverage gap；长期公平性列为 Stage 2 范围外；无新代码改动、无需追加仿真 | `history/reports/stage2_evidence_audit_20261018.md`、`AI/TMP/stage2_validation_agciqdp_/` |
| 10-18 / Stage 2 最新 PASS 证据审计 | d5wr10l1 epoch 阻塞 → agciqdp_ 三阶段 PASS | 当前11479 source/16 scripts/fixture/HEAD/workload与run完全匹配；10定向CASE、整机1216 preservation闭合、退出排空全PASS；没有新功能/checker/trace改动，仅文档更新，最终关闭判断待定；本轮未编译/生成/仿真/测试 | `history/reports/stage2_evidence_audit_20261018.md`、`AI/TMP/stage2_validation_agciqdp_/`、`AI/TMP/stage2_evidence_audit_bbmws5qc/` |
| 10-17 / Stage 1 final validation closure | 修复后的新 binary → 九项 closure gates 全 PASS | provenance PASS、serial_success、verified=1、main/checker 155606=155606、AMO 双 lane、clear/lifecycle/duplicate/lost effect 全 PASS、真实退出 drain=0；`STAGE1_STATUS=CLOSED`，无需新仿真 | `history/reports/stage1_closure_20261017.md` 第 11 节、`AI/TMP/stage1_closure_run_g3Y7Oi9x/` |
| 10-17 / Stage 1 缺失 simulator header | 用户 build → emulator.cc:24 找不到 stage1_exit.h → make Error 1/2 | SIM_FILE_REQS 漏列 header；补一行，隔离真实 staging 规则复现前失败/后通过，32 tests PASS；本轮未 hardware build/sim，完整 build/dynamic pending | `history/reports/stage1_exit_header_build_fix_20261017.md`、`AI/TMP/stage1_exit_header_fix_dgopfbpr/` |
| 10-17 / Stage 1 最终 preflight | 两项已归因补丁 → accounting/exit/coverage 静态复核通过 | PRE_FLIGHT=PASS，无 blocker；32 tests、语法、workload 身份、diff 检查 PASS；功能代码未改，冻结后待一次新 build + sim，本轮未启动 | `history/reports/stage1_final_preflight_20261017.md` |
| 10-17 / Stage 1 全项 closure 审计 | provenance/verified/338 packages PASS → main-checker -329、exit真实请求0x52788 | 329条全部唯一归因于owned drain统计资格；统一R_IC ownership修复，反事实extra/missing均0；有限HTIF exit+真实quiescence等待；修analyzer诊断，32离线tests PASS；全部补丁待一次联合动态验证，本轮未hardware build/sim | `history/reports/stage1_closure_20261017.md`、`stage1_closure_20261017_transactions.tsv`、`AI/TMP/stage1_audit_20261017_atpbr625/` |
| 10-16 19:22 后 / Stage 1 TestHarness 类型修复 | 用户 build → collect 类型推断失败、Nothing.hartId → make Error 1 | 直接匹配 BoomTileAttachParams 并收集 Seq[Int] hart IDs；三条 Scala error 同一根因，源码已修，静态 diff 检查通过；本轮未重新编译或仿真 | `AI/TMP/stage1_closure_build_d1DLDfai/build.log`、`state/current_debug_state.md` |
| 10-16 / Stage 1 readiness preflight | 原 workload 仅 AMO low lane / 无真实退出快照 → 取证链补齐 | PRE_FLIGHT=PASS；独立软件构建证明双 lane、live RTL exit probes、精确 `_exit` 分类、clear mode B、全新 build/run provenance 和统一 analyzer；23 项离线测试通过，本轮未硬件编译或仿真 | `history/reports/stage1_readiness_20261016.md` |
| 10-16 / Stage 1 L1 closure checkpoint | serial success + verified=1 → BOOM/checker `707/1715` | 完成只读归因；LSQ 统计资格遗漏 `traffic_check`，AMO.W 上 lane 仍待动态覆盖；加入流式 analyzer、AMO/cycle instrumentation；未重新 build/run | `history/reports/stage1_closure_20261016.md` |
| 10-14 / 两个 MSHR drain closure | state3持续polling→旧RTL1000cycle不退出 | 统一state3/state12 gate；完整v1Config生成/build、5短RTL场景PASS；可以进入大仿真，真实整机效果待验证 | `history/reports/mshr_both_drain_closure_20261014.md` |
| 10-14 / mshrs 静态审计 | 保存closure→当前源码逐字一致，无新divergence | state12 gate、Phase-1/19原assert保留；最小生成与lintPASS；early-drain/global公平性仍pending，功能源码未改 | `history/reports/mshrs_static_audit_20261014.md` |
| 10-14 / HTIF tail RPQ drain | read MSHR安装完成→drain持续secondary入队→writer nack且host零响应 | 关闭state12 admission；Scala/整机生成/四模块场景PASS，真实writer公平性及BFS pending | `history/reports/mshr_rpq_drain_closure_20261014.md`, `bugs/bug-mshr-rpq-drain-admission.md` |
| 早期 / BootROM-CDC-trap | load响应依赖/anchor/result/admission失配 | 多个独立run的历史结论，未合并为当前事实 | `history/reports/legacy_ai/` |
| 09-30 / 254 pkg | ownership 前窗口 → seq 0/旧 live seq event | package ownership 与地址统计边界错误；已实施静态修复，需动态回归 | `history/reports/ownership-address/current_run_254_packages_and_verify_failure.md` |
| 10-01 / 259 pkg | PASS/safe seq 0x62 → 同包尾 store | `<= safe` 错把同包尾事件判旧；修为 `<` | `history/reports/ownership-address/current_run_259pkg_address_stats_root_cause_20261001.md` |
| 10-04 / d7 | can-commit quiet → snapshot/ARF mismatch | snapshot 空 ROB/架构 next-PC 和组合环问题；修复后需生成/运行验证 | `history/reports/snapshot-lsl/current_run_snapshot_boundary_root_cause_20261004.md` |
| 10-05 / 461000→459000 | LSL request → wrong store head / later no read fire | 类型地址错配；首次修复引入 SyncReadMem ready/read 环，随后加入 prefetch/head register | `history/reports/snapshot-lsl/assert21_461000_root_cause_20261005.md` |
| 10-08 / 528000 | seq 0x15 PASS → seq 0x16 R_IC done=558 while BOOM still drains | final count 早于旧包真实终点；600/558/42 chain confirmed | `bugs/bug-528000-count-boundary.md`, `history/evidence/528000/` |
| 10-09/10 / 1769000→459000 | redirect → ordinary startup stream corruption | frontend redirect pending/settle 方案的回归；静态生成通过，动态未证实 | `bugs/bug-1769000-frontend-regression.md` |
| 最新 / 291 pkg | run end → `verified=0` | 291/291/291 平衡但 BOOM/checker 流量差 164/258；first bad unresolved | `state/current_debug_state.md` |

- 2026-10-17：Stage 2 L1 preservation 实现交付，新增完整 key/receipt gate、WB ACK owner 和 L2 commit-time ACK；44 项离线工具测试及静态检查通过，未运行硬件生成/仿真。手动入口 `stage2_build_and_run.sh all`，动态状态 pending；详见 `AI/Design/stage2_l1_preservation_20261017.md`。

- 2026-10-17：Stage 2 targeted preflight 修复 TL/Atomics default、probe 真实完成、early matching ACK、fixture 高半宽度、denied identity 与验证判据；四阶段 source/artifact/参数 gate 已落地，64 项离线 tests 通过。`PREFLIGHT_READY_PENDING_BUILD`，未执行硬件阶段；见 `history/reports/stage2_preflight_20261017.md`。

- 2026-10-17：完善现有 Stage 2 all：任意 cwd 绝对路径启动、唯一 root、严格串行、原始退出码与中文失败/总摘要。原定向进程新增实际 L2 MSHR→SourceD denied Put/AMO 和成功对照（10 CASE），修复 fixture lastLevel 参数及 denied full Put bank/bypass 问题；75 项离线测试与语法检查通过，未执行 all 或硬件阶段，无已知构建前阻塞。见 `history/reports/stage2_all_entry_20261017.md`。

- 2026-10-17：用户 all run `stage2_validation_llhv_oen` Scala compile 失败，唯一错误为 fixture 的 TLMessages.ProbeBlock 不存在；最小改为本地 API 的 Probe。75 项离线测试与 API 成员核对通过，未重新编译/生成/仿真；状态 PATCHED_PENDING_REBUILD，原失败证据保留。见 `history/reports/stage2_probe_api_build_fix_20261017.md`。

- 2026-10-17：用户最新 `stage2_validation_qodffn_8` 已通过 fixture Scala compile，生成时因直接调用 sbt 的 1G 默认堆 OOM，后台异常仍 exit 0。显式设置与 Stage 1 相同的 8G heap、OOM 退出、异常/完成标记/RTL 联合检测；按用户要求从 all 移除重复 offline，保留来源/产物/覆盖门禁及三阶段失败停止。42 项纯运行器测试和语法/diff 检查通过，未运行硬件步骤；原失败现场保留，PATCHED_PENDING_REBUILD。见 `history/reports/stage2_emit_oom_fix_20261017.md`。

- 2026-10-17：用户 `stage2_validation_5iv7ungc` 通过 Scala compile/越过 OOM，FIRRTL WiringTransform 因独立 fixture 缺少 L1 97 个 bore 的 sink 失败。按实际名称/宽度一次补齐只读接收端，新增 wiring 全量审计、同次日志全部不同错误持久汇总和定向 Verilator error-limit=0；原门禁/失败停止/跳过自动 offline 保留。48 项运行器测试与静态检查通过，未重新构建/生成/仿真；PATCHED_PENDING_REBUILD。见 `history/reports/stage2_wiring_build_fix_20261017.md`。

# 2026-10-20：Stage 3 CASE 10 flush timeout traced to host ownership lifecycle

`run_igda2knt` had completed the repeated same-package update body: ReleaseAck,
bank write, no additional preservation Put, and new-key/data readback all
passed. Cleanup then accepted flush while readback Acquire still owned the line.
Hardware emitted a Probe to the coherent client; the fixture never supplied
ProbeAck, so flush could not issue its Release. Preservation was idle and the
line had already been validated. Fixture now returns ownership with clean
TtoN before cleanup validation/flush and checks committed outer bytes. Added
read-only per-MSHR flush diagnostics. Transition table/assertions and
preservation gates are unchanged. Static checks pass; no build, RTL generation,
Verilator, runner or simulation ran. `PATCHED_PENDING_REBUILD`, closure NO.
See `history/reports/stage3_case10_flush_ownership_20261020.md`.

- 2026-10-17：用户 `stage2_validation_mzljfuss` Scala compile 成功，上一轮带参 Stage2WiringAudit 在 FIRRTL 类反射构造时报缺 `<init>()`。核对本地 Compiler/fromTransform/getObject 字节码后改为顶层无参类，从 TargetDirAnnotation 取报告目录；原进程在 elaboration 前提前执行真实反射构造检查，保留全部审计/门禁。只做源码/旧 class 与 jar 静态检查及语法/diff 检查，未编译/生成/仿真；原现场保留，PATCHED_PENDING_REBUILD。见 `history/reports/stage2_audit_ctor_fix_20261017.md`。

- 2026-10-18：用户 `stage2_validation_r8baqbfq` 完成模块生成/lint/C++ 编译，整机 FIRRTL 因旧 CAM 的 64 个孤立 source 失败。一次移除已被 TL CacheImage 替代的 CAM 发布端及 fixture 对应 sink；补整机失败时的最终 annotation 全量清单，修正 JVM banner/ANSI/首 cause 摘要。56 项纯运行器回归与定向源码检查通过，未重新构建/生成/仿真；all 保留跳过 offline 和严格停止，PATCHED_PENDING_REBUILD。见 `history/reports/stage2_system_wiring_fix_20261018.md`。
## 2026-10-18：Stage 2 directed preservation request被 epoch 误索引抑制

用户 run `AI/TMP/stage2_validation_d5wr10l1/` 在 directed 的
`prematureAck` 前置条件失败：日志反复出现 `STAGE2_TX BLOCK`，但没有
`STAGE2_TX PRESERVE`。核对该 run 的 generated RTL 与 `source.patch` 后确认
它仍包含旧的 `s2_lookup_epoch(0)(s2_store_way)`，而当前源码中该值已经是
选中 way 的完整 epoch；旧代码把 way 当作 bit index，way 1/epoch 1 时抑制
了 cross-package preservation 请求。已改为完整 epoch 与对应 slot epoch
比较，保留原 gate 语义。定向 C++ 诊断现在区分 preservation C 未发出、未
形成停顿和观察到的 valid/fire 状态；runner 统一汇总结构化失败和未运行
case，避免只暴露首个通用异常。

本轮 57 项 runner 单元测试、Python/shell 语法及 diff 检查通过；没有重新
编译、生成 RTL、elaboration、Verilator 或运行任一仿真。旧 generated model
不能验证当前修复，待用户使用新 root 的 `stage2_build_and_run.sh all` 重建
后确认；Stage 2 仍为 `PATCHED_PENDING_REBUILD`。

## 2026-10-18：Stage 2 最新已完成运行与当前 working tree 同源

最新真实 `stage2_validation_agciqdp_` 已完成 build/directed/system，全 PASS、exit0；
33 pin wiring/结构检查、10个定向CASE（含独立字节/effect/真实MSHR denied对照）、
整机 Stage1/Stage2 checker 全通过。旧 epoch 前置条件故障消失。当前11479 source、
16 scripts、fixture副本与run记录逐项hash一致，清单无增减，原三次provenance PASS。
本轮只读 source/log/hash 和文档回写，没有功能/checker/trace改动、编译/生成/仿真或测试。
明确记录 checker/精确同拍覆盖边界，不把有限PASS当作全交错证明；没有已知静态blocker，
READY_FOR_VALIDATION，最终关闭判断pending。见完整11节交接报告；原失败run不覆盖/不清理。

## 2026-10-20 — Stage3 system closure audit / coherent peer lineage

三方baseline/old/current对比未证明旧d223跨过：最新更早cec7卡住，直接首因在b24af的
ordinary Rocket ProbeAckData丢失CacheImage，被错误当成BASE覆盖unsafe seq2。
共享C->BOOM WB->installDrain是cec7停止前进的放大链。错误数据未观测，15个effect
缺口是未完成事务，不是已证实永久丢失。上轮same-package修复判PARTIAL。
实现coherent peer导入/变更/双C返回lineage、BOOM返还gen避碰、writer-aware package
helper，新增协议roundtrip CASE，现严格19/19。保留所有outer/跨包/ACK/断言安全门。
静态语法/表/assignment/handshake/diff通过；未build/生成/仿真，closure仍NO。
[完整RCA、wait graph、receipt与覆盖边界](reports/stage3_system_lineage_closure_audit_20261020.md)。

- 2026-10-20：用户收缩Stage3为lineage-unaware Rocket；撤回DCache/HellaCache扩展、恢复BOOM本地serial，L2按endpoint/source分类gate unsafe D并park/relookup，复用package-close且peer-only不冻结SourceC。旧peer CASE替换、仍19项；语法/table/scope静态检查PASS。发现timer runtime trap等待safe Grant与checker入场/validation的条件循环尚未排除，STATIC_REVIEW=FAIL、READY_FOR_DYNAMIC_VALIDATION=NO；未build/生成/仿真。详见 [boundary/progress审计](reports/stage3_lineage_unaware_boundary_20261020.md)。

- 2026-10-20：将剩余timer环落实为具体hart2/seq2链：旧FST1459857已有PASS2入队但handoff0；1459889进入timer trap；1460361 handler PC800006bc对80007e40发Acquire，word2与BOOM unsafe writer0/genb920/seq2的word0共行，watermark1。当前gate会使handler与自己的PASS交付互等。最小修复仅timer C/header按hart隔离64B完整block，硬件1463文件hash未变；2个provenance脚本检查真实ELF布局并在用户下次执行同入口时自动准备变更软件。C syntax-only/Python/shell/mock-only/diff静态PASS；已知timer unsafe-transfer环切断，READY_FOR_DYNAMIC_VALIDATION=YES、closure仍NO。未运行任何build/生成/仿真或runner。详见 [timer wait graph与control-domain修复](reports/stage3_timer_control_domain_20261020.md)。

- 2026-10-20：用户run_jp4_qkjb在workload preparation失败：新增符号size解析把objdump的`.hidden`误当size。统一处理可选visibility并复用到_exit；3项offline测试及实际新ELF261符号/5个hidden、timer aligned64/size256、AMO/HTIF/LOAD头静态检查PASS。未改硬件或控制域设计，未build/转换/仿真或执行runner；同一入口待用户重跑，closure仍NO。详见 [symbol parser修复](reports/stage3_workload_symbol_parser_20261020.md)。
