# Debug 演化时间线

2026-10-30：按用户要求准备一次性最终FST诊断入口，状态`READY_FOR_OPT4_SVB_WAVEFORM_RUN`，硬件根因仍证据不足。新入口fresh generation/debug build、窗口sim time1500000至终止、主BOOM/Rob/LSU/cache/fast-line gates/WB/probe/6MSHR/TL/safe控制高覆盖，4455只读aliases、189项排除、启动前compiled trace审查；关键既有snapshot/事件不再受verbose门控。仅build-local observation overlay与host FST退出处理，功能源码及性能入口不改；唯一FST留waveform_debug/run下并hash，8192-event失败ring保留，无resume/自动重跑。88offline tests、全部表达式fixture lint/trace audit、SVB独立静态trace audit、native FST字面量fixture和source identity通过。未fresh elaboration/整机build/仿真；下一步用户唯一命令`bash /data1/gzh/EC/slowdown/run_optimization_4_svb_waveform_debug.sh --jobs 8`。见 [准备报告](../../TMP/opt4_svb_waveform_debug_prepare_20261030_091449_2f46ad8a/README.md)。

2026-10-30：最新Opt4 diagnostic user run `optimization_4_svb_20261029_120415_a83514b4` 再于time2099000 watchdog exit1，未完成benchmark。查明全部诊断printf被`verbose&&done_reset`关闭（launcher未启用verbose），failure ring只有2 fatal，owner snapshot无法恢复；旧READY的静态检查漏掉runtime enable。仅修offline native-watchdog识别与SVB16 manifest容量fallback，消除NO_WATCHDOG漏检和59 slot误报；corrected prefix6999/6999、SVB325/325/325、conflict/invalidACK/regression0，仍缺footer/最终correctness。70tests、BOOM compile/parser、host fixture、SV lint、static-check、patch/diff PASS。没有功能RTL改动/新观测run/生成/build/仿真；状态HANG_DIAGNOSTIC_EVIDENCE_INSUFFICIENT，硬件根因仍unresolved，不ready正式rerun。见 [结果与修复边界](../../TMP/opt4_svb_hang_rootcause_fix_20261030_a83514b4_7c92e1d0/README.md)。

2026-10-29：Opt4 最终 hang diagnostic 准备完成，状态 `READY_FOR_FINAL_HANG_DIAGNOSTIC_RUN`，根因仍 unresolved。fresh build-only run `optimization_4_svb_20261029_110442_61fcd0f2` 的 RTL generation/Verilator build PASS，manifest `simulation=NOT_STARTED` 且没有启动标记。21+3+11+20+8 项离线测试、launcher static-check、patch reverse-check、shell syntax 和 diff check PASS。已准备 fast-line、unrelated preservation gate、WB/probe/MSHR/promotion、watchdog snapshot、failure-only 8192-event/1MiB ring 与 wait-for analyzer；没有执行仿真。用户下一步仅一次 fresh 默认运行，不带 `--resume`：`bash /data1/gzh/EC/slowdown/run_optimization_4_svb.sh`。见 [最终诊断准备](../../TMP/opt4_svb_hang_fix_20261029_9f3c2d71/README.md)。

2026-10-29：Opt4 run `optimization_4_svb_20261029_062302_0291a6b9` build通过后在 BOOM idle watchdog exit1。
kind15反复观察到 seq183/line `0x80008040`、old seq182、watermark182、lowerPreserved=0；没有 seq183 pending handoff 记录。缺最终SVB/WB/probe/MSHR/slot状态和ROB commit波形，无法确认死锁环或根因。seq179同线promotion有ACK/completion，seq183 checker后来 `package_progress_timeout` 取消；protocol summary另报duplicate-selection错误及不完整footer，correctness/performance无效。
新增稀疏 age snapshots、watchdog last-commit/reset记录和 failure-only 1MiB/8192-line host ring；仅诊断，未作功能修复。51 offline tests、launcher static-check、patch reverse-check、diff check PASS；未编译/生成/build/sim。状态 `HANG_ROOT_CAUSE_STILL_UNRESOLVED`。见 [诊断报告](../../TMP/opt4_svb_hang_fix_20261029_9f3c2d71/README.md)。

2026-10-29：Opt4 run `optimization_4_svb_20261029_020351_481d089a` generation/build通过，
因逐写/逐阻塞周期观测耗尽48MiB而被capture中止。改为精确counter+4096间隔样例，
协议/样例/summary预算隔离，超限继续workload、必需丢失拒绝PASS，异常状态标ABORTED。
57offline tests、Scala compile、SV lint-only及静态交付检查通过；原前缀22,222条必需记录离线回放零丢失。
未执行新生成/build/硬件仿真；备份正确性/slowdown仍待fresh run。
见 [预算中止修复](../bugs/opt4_observation_budget_abort_20261029.md)。

2026-10-26：safe-chain 用户仿真在 ROI 前耗尽 KIND10 的 50,000 条预算；原日志全部为 boot-held RESET。修复观测器 RESET/START 上升沿采样与首次失败诊断保存；35 项离线测试及静态 identity 通过，未重新生成/构建/仿真。旧 guard 和证据保留，仅准备用户显式替代入口。见 [根因、修复及验证边界](../bugs/safe_chain_held_boundary_overflow_20261026.md)。

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


## 2026-10-27 — Safe-chain RCA / Optimization 2 delivery, static only

成功 safe_chain_20261026_141031_5b330641 exit0，GAPBS512 verified/checksum43439728，ROI4,706,513。原summary离线精确重现，compact TSV12,633,982B / 53 footers完整；此前“repaired run pending”状态已过时。全部pending3,178,984（strict unsafe3,100,681）：result未形成2,993,080、transfer3,720、prefix87,361、watermark传播178、post-safe78,275、multi16,370。Top1=OPT2_TARGET_CHECKER_RESULT_LATENCY；2,981,282在exec_done前，其中2,867,231在producer seal后。调度偏置贡献未隔离，不能承诺同数ROI收益。

最大frontier缺失50,424（当时没有later PASS），最大actual PASS阻塞12,772，最大放大3个later PASS。commit/MSHR exact同源归因缺连续字段；525,854为delta−pending算术差，不是已证明未解释损失。R_IC无safe→gate直接边，result release为共同上游。

保留此前两文件Opt2（ght_sch/R_IC，实际allocation触发availability-aware轮转，原fallback/ownership/safe不改）。旧Opt2 build成功后pre-Popen缺compact_capture，实际仿真没启动；补依赖提前检查与限定known-failure的显式现有build复用，旧guard/manifest/build不改且禁止自动重试。18项mock/file回归、AST/bash/diff、冻结source/事件/旧guard/model身份审计PASS；本轮无RTL改动、仿真、生成、SBT或任何编译/benchmark。READY_TO_RUN_OPTIMIZATION_2只指静态交付就绪，动态收益/正确性PENDING。

16份报告、最小patch、launcher转发、分析器snapshot与hash索引：
[最终交付](../../TMP/opt2_rootcause_final_20261026_f3d927c1/README.md)。用户命令：`./slowdown/run_optimization_2.sh --resume-built-run optimization_2_20261026_202323_9020fd02`。全局drain/RUN_PROVENANCE及未观测downstream指标继续unresolved。

## 2026-10-27 — Opt2b checker execution / bounded SVB go-no-go

用户成功 Opt2 `optimization_2_20261027_144838_fdf571b7` exit0、GAPBS512
verified/checksum43439728、ROI4,707,273（比Opt1 +760）；allocation已均衡
82/85/82/82。旧“Opt2 dynamic pending”状态由此取代。331 accepted results，
FAIL/CANCEL/collision/stale/duplicate0、53 observer coverage COMPLETE。
Stage1 L1/LSU exit drain PASS；full cache/package/DRAM drain 与 RUN_PROVENANCE未关闭。

离线证据：pending3,241,793、strict unsafe3,162,560；unformed result3,019,697，
其中sealed→exec_done2,897,079。全部assignment早于seal，流式执行；
assign→admit均值14.93、admit→done均值28,893.46 main cycles。
650,116 checked instructions，weighted main CPI14.7108；top10 latency包只关联
7.301% unsafe pending。广泛执行成本有支持，内部主stall旧trace仍不足以判定。

SVB未实现：深度/容量coverage均null，串行trace看不到未发出Store；
3,162,560只是宽松OPPORTUNITY_UPPER_BOUND，不是ROI gain。
具体no-go是P1 PASS/P2 FAIL需要恢复SVB P1，而现有路径只有sticky/fail-closed，
无SVB safe restore selector；原WB读live L1、voluntary T→N且ACK后清metadata，
不能只换seq就发布旧P1并继续持有newest P2。snapshot后failure/probe不能靠
allocation前fallback解决。本轮没有以“复杂”代替正确性反例，也未声称机会小。

仅一个功能优化：Frontend当前READY响应被FQ接受时，同拍允许已解析successor
Icache req.fire，移除固定EMPTY issue空拍；每eligible chunk至多提前一个checker
local cycle，性能收益未测。RocketCore owned-package stall分类/时间戳、Frontend
累计状态计数、DCache semantic write/first block均仅观测，67 observer；
Opt1/Opt2与其他dirty修改/删除保留，不修改L2/DRAM功能。

13份报告和三文件增量patch已准备；19项offline synthetic/contract tests与
纯static-check通过（27 source、26 dependency projects），日志和provenance原地保存。
本轮未Scala/SBT/native/software编译、elaboration、RTL生成、Verilator、仿真或benchmark。
**READY_TO_RUN_OPT2B_CHECKER**；下一次由用户执行
`bash /data1/gzh/EC/slowdown/run_optimization_2b.sh`，一次完整GAPBS512/seed1，
无FST/VCD、无自动retry。局部分类不是旧2.897M的精确因果加权分摊，动态收益/正确性待测。
[交付与证据](../../TMP/opt2b_checker_and_multiversion_20261027_184537_3891819a/README.md)。
## 2026-10-28 — Opt2b attribution and Opt3 checker delivery

Opt2b completed with GAPBS512 checksum `43439728`, ROI `3,760,243` main
cycles, and complete compact evidence. The dominant checker category is
`WAIT_INSTRUCTION`: 1,980,533 of 3,739,176 owned local cycles, rising to
75.2005% after producer seal. Strict cross-package same-line Store exposure is
2,296,726 main cycles, but serialized WaitSafe execution cannot establish SVB
depth/occupancy, and the P1 PASS/P2 FAIL restore invariant remains unclosed.

The next single optimization is `CHECKER_FRONTEND_BOUND`. `Frontend.scala`
now classifies the accepted S2 response on the response edge, removes the
mandatory `checker_classify` state, retains FQ/BJL/redirect/partial-RVC
ownership semantics, and emits four kind16 cumulative observers. Static
identity/resource/contract checks pass. No hardware generation, compilation,
simulation, or benchmark was run; status is `READY_TO_RUN_CHECKER_OPT3` for
the user-run launcher.


## 2026-10-28 — Opt3 run measured, clear gain over Opt2b

`optimization_3_checker_20261028_090640_a56794e2` SUCCEEDED/exit0, GAPBS512 verified/checksum43439728.
ROI 2,928,347; vs Opt2b reduction 831,896 (22.123464%), vs original
reduction 1,806,534 (38.153736%); 2.923450x Baseline. 315 PASS results,
all observed FAIL/CANCEL/stale/duplicate/collision counters0; Stage1 L1/LSU
drain PASS. 71 complete observers; independent compact parse/hash and
classification-partition checks PASS. 630,932 fused responses, CLASSIFY0.
Strict unsafe WaitSafe decreases to 1,547,483; instruction wait to 1,346,930
local cycles. Full drain/provenance/failure-probe recovery remain open.
Raw summary uses inherited Opt2 performance labels; corrected comparison
in [results](../../TMP/opt3_results_20261028_122909_092f25bb/README.md), original artifacts preserved.
This continuation only reads existing simulation evidence and writes reports.

## 2026-10-28 — Opt3 frontend design and source release

Documented Opt2b accepted-response handoff and Opt3 fused S2 classification,
ownership/BJL/RVC guards, checker gated-clock scope, measured performance and
validation boundaries in [Opt3 design](../../Design/opt3_checker_frontend_optimization_20261028.md).
The release retains the successful run's hardware bytes and required cumulative
Opt1/Opt2/Opt2b dependencies, including both shared observer resources. Large
runtime products, old evidence and unrelated paper edits remain local and intact.

Release tooling now reports Opt3 gains against the correct Opt2b reference,
checks every kind16 partition/counter snapshot, recreates empty runtime directories
after checkout and supports explicit repetition of the latest successful complete
run with unchanged source/software identity. Default/failed-run no-retry guards
remain in force. Sixteen offline regression tests, source contracts and static
preflight passed; offline replay reproduced ROI 2,928,347, 22.123464% gain,
COMPLETE coverage and OBSERVED_CHECKS_PASS. No hardware generation, compilation,
simulation or benchmark was executed. Full drain/provenance/failure recovery and
timing closure remain open; Git/index/source identity is audited separately.
Historical comparison inputs are pinned as small versioned snapshots with source
hashes; the analyzer no longer reads the old untracked safe-chain run directory.

## 2026-10-30 — Opt4 FST root cause closed and RTL fixed (runtime pending)

Final saved FST proved stale fast-line ownership after replacement at core1,827,940.
The original store completed on another way; unrelated preservation was still
blocked at the watchdog, with all shared backend resources idle and ROB empty.
Implemented identity-loss revocation, exact bypass identity, line-scoped legacy
handoff admission and single-freeze mutual exclusion. Retained SVB16/order/ACK
semantics preserved. Final Scala + fresh FIRRTL/firtool/comb-loop checks, 102 offline
(12 directed) tests and launcher/static checks passed. No simulator executed.
State READY_TO_RERUN_OPT4_SVB_AFTER_FST_FIX; next run is formal non-trace correctness
and ROI validation. [Evidence and patch](../../TMP/opt4_svb_fst_rootcause_fix_20261030_114113_773ea77d/README.md).


## 2026-10-30 — Opt4 formal result check: optimization_4_svb_20261030_044205_dbaf743b

Confirmed normal simulator exit0, host cycles2449614, verified1/checksum43439728,
COMPUTATION/END PASS, no assertions/watchdog. Protocol PASS with 7408 Release/ACK
and 391 SVB completion pairs, no retained/outstanding entries; stale publications0.
Overall FAILED because fingerprint observer mismatch84 plus incomplete/inconsistent
fingerprint ledger and SC/host occupancy/depth histogram mismatch. Actual backup
corruption versus observation/accounting error remains unresolved. ROI1707863 is raw,
performance_valid=false; no validated slowdown gain. Source mode/patch matches the
FST owner fix. Read existing manifest/stdout/stderr/summary only; updated status docs;
no RTL edit, build, or simulation. See latest current_debug_state.md for evidence links.


## 2026-10-30 — Opt4 one-shot integrity/observer/capacity closure

Existing complete run only: proved 76 duplicate observer increments and 8 unlocalized
final hash failures; no basis to claim all observer-only. Reconstructed391 promotions,
406=391+12+3 aggregate; missing15 terminal identities explicitly marked unknown.
Closed STOP histogram one-cycle bug offline, SVB16 sufficient (full16 0.2844%,fallback1),
no cache geometry candidate because S0 sanity fails. Added allocation serial +
three-stage/transfer hashes/terminal ledger, host/parser/window/shadow fixes; functional
control/data untouched by exact inverse proof. Full Scala/FIRRTL/firtool/comb-loop,
120 offline checks PASS; no hardware simulation. Final status CURRENT_DATA_FUNDAMENTALLY_INSUFFICIENT,
FINAL_OPT4_VALIDATION_PREPARED; no new pure diagnostic run. See current state and
AI/TMP/opt4_one_shot_closure_20261030_143326_a1dcf391/README.md.
