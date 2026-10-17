# Current Debug State

## 当前：Stage 1 已正式关闭（2026-10-17）

最新 final validation run `AI/TMP/stage1_closure_run_g3Y7Oi9x` 已完成，未再启动仿真。`PROVENANCE=PASS`（11478 source、3003 generated files），simulator `serial_success`/exit code 0，`verified=1`，334/334/334 packages PASS，软件 END PASS；scoreboard `STAGE1_TRACE=PASS`、`errors={}`，全部 closure gates PASS。

```ini
STAGE1_STATUS=CLOSED
NEXT_SIM_REQUIRED=NO
PROVENANCE=PASS
SIM_EXIT=SUCCESS
ARCH_ERROR=0
AMO_LOW_LANE_SEEN=1
AMO_HIGH_LANE_SEEN=1
AMO_ERROR=0
MAIN_COUNT=155606
CHECKER_COUNT=155606
MAIN_CHECKER_DIFF=0
DUP_EFFECT=0
LOST_EFFECT=0
EFFECT_WITHOUT_TERMINAL=0
DUP_TERMINAL=0
TERMINAL_WITHOUT_STQ_RELEASE=0
DUP_STQ_RELEASE=0
CLEAR_RACE_VIOLATION=0
EXIT_REAL_OUTSTANDING=0
```

九项均 PASS：architectural data/error、AMO.W、main/checker、clear/S1/S2/refill、effect→terminal、terminal→STQ release、duplicate effect、lost effect、exit outstanding。main/checker 六 counters 完全一致（store 60567、load 95039，cache/uncache 分项也一致）；退出 DCACHE/LSU snapshot 全部归零并 `fence_ready=1`。实际未发生的 clear/refill、refill/effect、S1/S2 replay-killed 交叉继续作为非阻塞 coverage 观察项记录。最终 trace SHA256 为 `a838739c4240e3cd8df3dd20875b0a6633f082c64bb5fa378347b237edd9fa87`，FST SHA256 为 `85c6917e8a6d5dce11e96fe6cd403e7d56057f132d3139cc689a9c075627c97e`。完整 closure 证据见 [最终 closure 报告](../history/reports/stage1_closure_20261017.md) 及 run 内 `scoreboard.out/json`、`trace.log`、`trace.fst`。

## 历史：Stage 1 simulator 缺失头文件依赖已修（2026-10-17）

用户新 build `stage1_closure_build_e0hlkAyW` 在 simulator C++ 编译时报 `emulator.cc:24: stage1_exit.h file not found`，尚未进入 simulation。根因是 Verilator Makefile 的 `SIM_FILE_REQS` 漏列新 header，未复制到 gen-collateral；已仅补一行依赖。上一轮 preflight 漏检了这条 staging 链路，下面的运行准入记录保留为历史，不能代替这次实际构建失败。

直接提取真实 staging 规则的隔离 before/after 验证已复现并消除缺失：复制/filelist 两项 false→true，host 预处理退出 1→0；32 项现有离线测试和 diff 检查 PASS。本轮未执行硬件编译/Verilator/仿真，未修改旧 build/generated 或功能逻辑。`STAGE1_STATUS=PATCHED_PENDING_FINAL_VALIDATION`，`NEXT_SIM_REQUIRED=YES`；完整 build 及动态验证仍待用户运行原 `stage1_build_and_run.sh`。详见 [修复记录](../history/reports/stage1_exit_header_build_fix_20261017.md)，证据在 `AI/TMP/stage1_exit_header_fix_dgopfbpr/`。

## 历史：Stage 1 最终运行准入（2026-10-17）

`PRE_FLIGHT=PASS`，`STAGE1_STATUS=PATCHED_PENDING_FINAL_VALIDATION`，`NEXT_SIM_REQUIRED=YES`，`NEXT_ACTION=RUN_STAGE1_BUILD_AND_RUN`，`EXPECTED_SIM_COUNT=1`。本轮仅复核 accounting、有限 HTIF exit/drain 和一次运行覆盖链，未发现 blocker，未修改功能源码/analyzer/workload/运行脚本，未执行任何硬件编译或仿真。32 项现有离线测试、六文件 Python AST、shell syntax、默认 workload 身份及 diff 检查全部通过；代码冻结。具体五项 YES/NO、退出 predicate 与 analyzer 的严格程度、诊断和准确运行命令见 [最终 preflight 记录](../history/reports/stage1_final_preflight_20261017.md)。补丁仍待下一次全新 build + 一次联合 simulation 动态验证。

## 历史：Stage 1 全项审计与联合补丁（2026-10-17）

`STAGE1_STATUS=PATCHED_PENDING_FINAL_VALIDATION`，`NEXT_SIM_REQUIRED=YES`，`MINIMUM_SIM_COUNT=1`，`PRE_FLIGHT=PASS_STATIC_ONLY`。本轮没有运行硬件/Scala build、elaboration、FIRRTL、Verilator 或 simulation。完整身份、九项 matrix、全部 counter、330 条失败归因、invariants 和下轮判据见 [全项审计报告](../history/reports/stage1_closure_20261017.md)。

最新昂贵 run 为 `AI/TMP/stage1_closure_run_vRXs98g3`，build 为 `stage1_closure_build_PlMlLDP7`；修改前来源验证 PASS，sim SHA256 `84dbe6de62f1a8114e4decf1c85d3702cb3730e474c3f3a8cec619fe383d88b9`。正常 serial_success、verified=1、338/338/338 packages。此前 TestHarness 的三条类型 error 已在该成功 build 中消失。

旧 run 两个独立失败均已完整归因：main155274/checker155603，store差-87、load差-242；全部329条均唯一关联到正确 seq、check0 的 owned drain 功能提交，功能 effect/terminal/release 完整。R_IC 导出 canonical producer ownership，经 Core/Tile 驱动 LSQ 统计资格，统一覆盖 cooling/snapshot/postcheck；旧波形反事实补回329、额外0、遗漏0。另一项是 libgloss 无限 HTIF exit stores：退出 token0x52788 在 MSHR5/txn0x57e/S2/replay，另14条 unissued tail，不能称为 lost/deadlock。workload 现为一次 tohost/fromhost 后 fence/park；Stage 1 emulator 在 host success 后按真实 probes 等待 L1/LSU 排空，保留原 timeout 和真实失败。

Architectural data、AMO.W low/high、clear mode B、effect→terminal、terminal→release、duplicate/lost effect、replay 在原 run 均通过。实际 clear/S1=183、clear/S2=16、kill/replay并发172、install/hit161、refill/hit791、install/effect9，违例0；clear/refill、refill/effect、真实 replay cancellation 未观察，报告单列静态保护与覆盖边界。

Analyzer 已修负 PC 差隐藏、occurrence 集合、重复 event identity、counter/event 一致性、issued exit JSON 分类、软件 ASSERT/END 失败及并发计数；缺独立 checker identity/END 不能假 closure PASS。旧 trace 的修订分析仍保留两个真实根因及软件 FAIL 传播。32项离线 tests（含独立 host predicate 测试）、Python/shell syntax、31处 printf arity、diff 检查通过。新软件已独立构建并核对 `_exit` 反汇编，默认 `AI/TMP/stage1_workload.json` 身份通过，原 ELF/manifest 保留。

下一步由用户另行安排一次全新 build + 一次联合 simulation，验证统计 ownership、有限 exit 和真实排空、checker ordinal、显式 cycle，以及所有原 Stage 1 gates；本轮不启动。下列旧 checkpoint 是历史来源，不能覆盖本节的当前结论。

## Stage 1 用户构建报错修复（2026-10-16 19:22 后）

用户运行 `stage1_build_and_run.sh` 在 Scala compile 阶段失败，完整日志为 `AI/TMP/stage1_closure_build_d1DLDfai/build.log`。日志显示 RocketCore 和 BOOM 三个源文件编译完成；TestHarness 的三条 error 均来自新增观察代码：先 `map(_.tileParams)` 得到依赖 `CanAttachTile.TileType` 的存在类型，再匹配 BoomTileParams，导致 collect 类型推断失败并连锁得到 `Nothing.hartId`；make Error 1 是同一失败的传播，没有进入本次 elaboration 或 simulation。

已将 `TestHarness.scala` 改为直接匹配具体 `BoomTileAttachParams`，收集明确的 `Seq[Int]` hart IDs，再选择唯一 BOOM 的 hart。观察端口、schema、BoringUtils 名称和缓存控制均保持原有语义。源码类型链与仓库同类 attach pattern 已核对，`git diff --check` 通过；按此前限制，本轮未重新执行 Scala/hardware build 或仿真，因此编译通过仍待验证。日志开头 `libriscv not found` 来自 Makefile 的可选链接 warning，不是本次失败原因。

## Stage 1 simulation readiness preflight (2026-10-16，当前)

`PRE_FLIGHT=PASS`，`NEXT_ACTION=RUN_STAGE1_BUILD_AND_RUN`。本轮没有执行硬件/Scala 编译、elaboration、FIRRTL、Verilator 或 simulator；这是运行准入，未宣布新源码动态 correctness PASS。完整九项结论与证据见 [readiness report](../history/reports/stage1_readiness_20261016.md)。

已补齐最小取证缺口：directed AMO.W 在 checking window 内无条件覆盖 low `0x80007e00` 和 high `0x80007e04`，两 lane 各 swap/add；独立软件构建和反汇编已完成，默认 manifest 为 `AI/TMP/stage1_workload.json`，原 ELF 保留。LSU/DCache/TestHarness 连续只读 probes 由 emulator 在最后正常 eval 后采样，产生真实 `EXIT_DRAIN` 和精确 `EXIT_STQ`；活动 MSHR 与停驻预取 owner 分开。ARCH_STORE 独立于统计口径，`_exit` 仅在精确 live committed/physical/data-ready 且未被 L1 接受时分类为软件尾部，已接受/丢失/未 terminal/release 的事务继续失败。

main/checker 有六 counters 和 package seq 自动 diff；CLEAR_CHECK 与 epoch/owner/refill 检查采用 closure mode B，覆盖本次实际 clear 决策，不能空集 PASS。checker 的 package_seq_reg 观察连接已移至声明后。23 项 Python 离线测试、shell 语法、Python AST 和 diff 检查通过；新增 Scala/C++ probes 仍需下轮编译验证。

下一步由用户执行 `/data1/gzh/EC/AI/Debug/scripts/stage1_build_and_run.sh`：当前 working tree、全新 build/provenance、一次 simulator，默认 FST。输出为新的 `AI/TMP/stage1_closure_build_XXXXXXXX/` 和 `stage1_closure_run_XXXXXXXX/`（含 trace.fst/log、run.json、scoreboard.out/json）。不复用历史 simulator，不在本轮执行。

## Stage 1 L1 closure checkpoint (2026-10-16，历史运行)

The existing run `AI/TMP/stage1_trace_20261016_120118/` is provenance-consistent and ended with `STAGE1_SIM_EXIT reason=serial_success`, `verified=1`, and 332/332 checker packages passed. It still reports BOOM/checker traffic differences of `707` stores and `1715` loads. Read-only attribution is complete: `lsu.scala` qualified architectural events with `traffic_scope_valid && packet_seq!=0` but omitted the LSQ-captured `traffic_check`, so setup/post-window accesses were counted. The working tree now requires `traffic_check` for both load/store qualification.

The AMO.W source fix is also in the working tree: `dcache.scala` uses `LoadGen.wordData`, so RV64 upper-word accesses select `addr[2]` before sign extension. S3 retains AMO old/operand values and emits cycle/address/mask fields for the next run; `RocketCore.scala` debug checker tokens use `package_seq_reg`. No build or simulator was run after these edits. The current run did not cover upper AMO.W lane or provide an exit drain snapshot.

The streaming analyzer is `scripts/stage1_trace_scoreboard.py`. The historical analysis of the saved run proves observed effect/terminal/STQ exactly-once and replay closure, but reports `MAIN_CHECKER=FAIL`, `AMO_W=UNRESOLVED`, and `EXIT_OUTSTANDING=UNRESOLVED`: 15 committed identities belong to the `_exit` tohost/fromhost loop and that saved simulator had no live L1 drain marker. The new observation path above has not been run. Historical status: [stage1 closure checkpoint](../history/reports/stage1_closure_20261016.md).

## 最新：两个 MSHR drain admission closure（2026-10-14）

**可以进入最终大仿真**。在原state12 closure基础上，mshrs.scala:159统一覆盖s_drain_rpq和s_drain_rpq_loads；本轮硬件增量只有一个Bool、两行注释和两条assertion文案（+5/-5），原Phase-1/queue/owner/publish逐字保留。源码SHA256 `594b0a9bc4d990d8a0b9c16a010fa41268adf6fa99c66c98b632eedb4e02123f`。

完整v1Config Scala compile、Chisel elaboration、FIRRTL low/CheckCombLoops/SV/内存宏、Verilator debug FST simulator build均PASS。两个状态禁止secondary accept和RPQ enqueue；原退出/publish未放宽。真实RTL短对照：旧state12-only版本在state3持续1000周期、新enqueue1000、不退出；修复5场景全PASS，正常早期drain5周期/背压16周期，accepted逐token退休，包含branch kill、issued CANCEL、RETRY及commit_line=false路径。fixture不含真实LSU/DCache，store terminal由环境提供，不能声称整机store效果验证完成。

下方历史报告中state3仍开放的描述已被本轮修复推进。静态收敛依赖下游服务/有限RETRY；固定resident同line polling转hit，writer有重新竞争机会，全局无限incoming流量仲裁公平性仍未证明，未发现第三个同类drain-admission状态。下一步大仿真验证真实STQ完成/数据可见、Phase-1和BFS，不因尚未进行该下一步而拒绝准入。

独立新simulator/生成物/完整diff/构建日志：`AI/TMP/mshr_both_drain_closure_20261014_165012/`。默认旧binary未覆盖，本轮未运行长仿真、未提交。报告：[两个drain closure](../history/reports/mshr_both_drain_closure_20261014.md)。

## 最新：mshrs.scala 静态一致性审计（2026-10-14）

结论：**当前实现基本正确；RPQ drain fix 正确；可以继续，无需恢复源码。** 当前 `mshrs.scala` SHA256 `53a3b2795cccc92268f41b9542fdc248079f6785496a27af875f1c650727ef3b` 与保存 closure 版本逐字相同；真实 prepatch + 保存 patch 重建也相同。相对 prepatch 仅 +10/-1，19 条原 assertion 全保留，新增2条。未发现后续性能对话混入功能 RTL 改动、回退或误改；未提交作者归属无法靠 blame 确定。

本轮重新执行 BOOM Scala compile、v1Config 最小真实 BoomMSHRFile Chisel/FIRRTL/Verilog generation、Verilator lint，均 PASS；RTL 确认 state12 gate 进入 sec_rdy/RPQ producer，publish仍等待 RPQ/enqueue/in-flight。lint只有 DECLFILENAME/UNUSEDSIGNAL，没有 width/connection/multiple-driver/latch/UNOPTFLAT。完整整机生成复用下方同源码上轮证据，本轮没有启动仿真。1461个Scala源码hash、默认6790个generated文件size/mtime均保持，功能源码未修改。

state12只在 eventual matching completion、有限RETRY、下游公平前提下证明有限集合收敛；state3 `s_drain_rpq_loads`仍开放新load，可在持续enqueue/dequeue下不退出；真实全局writer/probe公平性未证明。这些是原有独立活性边界，不是本轮发现agent破坏。完整Phase-1/BFS继续pending。详细审计含30个hunk分类、state/row/assert表：[mshrs_static_audit_20261014.md](../history/reports/mshrs_static_audit_20261014.md)。证据：`AI/TMP/mshrs_static_audit_20261014_131925/`。

## 独立复核：最终 replay drain closure（2026-10-14）

本轮 `AI/TMP/mshr_drain_closure_20261014/` 的真实 BoomMSHRFile 同刺激对照：prepatch 2000周期无read publish；修复后read drain周期124→publish220，writer upgrade/两个matching store terminal后周期294全部退休。逐token117 accepted/117 completed，SDQ释放2次；Trunk直接drain、GrantData写miss和14项pre-issue exception cancellation分别PASS，故意错transaction触发原owner assertion。完整v1Config compile/elaboration/low lowering/firtool verify-each/CheckCombLoops PASS。该证据与下方另一模块验证记录分开，周期不混用。

真实LSU/STQ.succeeded、DCache实际store数据效果、多MSHR/probe公平性和BFS未验证。1W LSU的15周期机制只抑制wakeup，不保证无限incoming load公平；s_drain_rpq_loads仍开放。建议需要补测试后提交。独立设计与验证报告：[mshr_drain_closure_independent_20261014.md](../history/reports/mshr_drain_closure_independent_20261014.md)。

## 最新：MSHR RPQ drain closure，静态与模块验证通过（整机 writer opportunity pending）

2026-10-14：GAPBS BFS `verified=1` 后 HTIF 等待的真正阻塞为 committed tohost store 没有完成 cache 写效果。MSHR2 transaction0x4da 的只读事务进入 `s_drain_rpq` 后仍接收 fromhost polling loads，RPQ边出边进，不能 publish/retire。旧FST的首次进入窗口为t10387259，末尾t41845875仍state12/meta_write0；BOOM cycle=(odd t−205)/2。

方案A最小修复已在working tree：仅 `mshrs.scala` 增加 `drainAdmissionClosed` 关闭state12 secondary，加两条no-accept/no-enqueue assertion，保留全部原publish、replay/terminal owner、FSM及Phase-1条件。恢复上下文时改动及隔离构建已存在，本轮核对实施前快照、未重复覆盖源码。相对真实prepatch快照+10/-1，其余原dirty功能文件hash未变。

BOOM Scala compile、v1Config Chisel/FIRRTL low/firtool verify-each/CheckCombLoops/Verilog与内存宏生成PASS。生成物在 `AI/TMP/mshr_drain_closure_20261014/v1-generated/`；默认generated目录6790文件未变化。真实生成MSHR/RPQ/RAM的独立短RTL对照：旧版持续刺激1000周期仍drain且新接受201请求/publish0；修复版15个旧请求全部完成，正常74周期退出、带RET​RY及metadata/E背压184周期退出；未issue分支取消和issued CANCEL也通过。每场景另覆盖无data升级、closure前secondary store/load、Trunk直接drain，最终19 accepted/19 retired。

**验证边界**：模块环境提供matching APPLIED/CANCEL/TL/metadata响应，没有真实LSU/STQ/DCache/TL fabric，故store terminal完成不能等同整机store succeeded/内存可见。真实同line固定resident条件下load在退休后应hit，不持续重建read MSHR；LSU已有wakeup限流不覆盖所有incoming/PTW/其他仲裁，无法声称全局公平。真实writer opportunity、多MSHR/probe竞争和BFS收尾仍unresolved。未运行长BFS、未提交，建议“需要补测试后提交”。

报告：[MSHR RPQ drain closure](../history/reports/mshr_rpq_drain_closure_20261014.md)。Bug：[RPQ drain admission](../bugs/bug-mshr-rpq-drain-admission.md)。增量patch/旧版对照/四场景日志/manifest：`AI/TMP/rpq_drain_closure_20261014_100756/`。下一步真实BOOM/LSU短程序验证同linepolling＋committed store、metadata fire/retire→load hit→writer acquire/terminal→STQ.succeeded/数据可见，不先跑长BFS。

## Latest user run: post-Scheme-A failure near 625000 (RCA complete)

The new failure is a direct `mshrs_3` `assert(!io_refill_fault)` at generated
`BoomMSHR.sv:579`, not a watchdog. The exact first bad state is FST 1250539 /
cycle 625269: an ordinary RPQ load in `s_drain_rpq_loads` fires the shared
LineBuffer read and sets the install-only `rowValid` while `installStarted=0`.
The row remains held through metadata and victim writeback; at FST 1250563 /
cycle 625281, `s_commit_line` presents refill with `installActive=0`, and
`io_refill_fault_3` becomes 1. MSHR/transaction/epoch/reservation/physical
line predicates match; only active install ownership fails.

Full-run evidence found 22,449 row captures, with exactly one outside the
install state, the failing event. This confirms a deterministic refill/install
row provenance bug in the current `mshrs.scala` control: Chisel's lexical
placement of `rowValid` does not qualify its generated register update, and
the common `io.lb_read.fire` capture accepts both load-drain and install reads.
Scheme A's `line_addr` fix is working in this run; the new fault is independent
of physical tag extraction. No functional source was changed during this RCA.

Report: [`phase1_625000_row_capture_rca_20261012.md`](../history/reports/phase1_625000_row_capture_rca_20261012.md)
Evidence: `AI/TMP/rca_phase1_625000_20261012_212146/`

更新时间：2026-10-12（Asia/Shanghai）。本文件只描述当前有效状态；历史运行进入 `history/` 与 `bugs/`。

## 最新：方案 A 已实现，修复后静态检查 PASS（仿真 pending）

2026-10-12 用户授权的方案 A 已在原 working tree 实施：BoomCacheRefill新增coreMaxAddrBits宽line_addr，从MSHR已锁存req生成block aligned地址；DCache physical tag检查使用line_addr，并验证与原array addr的set一致及block alignment。原addr继续保持untagBits数组语义，全部owner/token/MSHR/epoch/fault/assert保留。相对实施前快照只有phase1.scala、mshrs.scala、dcache.scala的+7/-1，没有新增FSM、preservation、generation/watermark、owner生命周期、allocation或TileLink变化。

修复后审查与实际v1Config构建已完成：Scala compile、Chisel elaboration、Scala FIRRTL low lowering、firtool verification/CheckCombLoops、Verilog及top/model内存宏生成全部exit 0。最终RTL确认原array addr14位，line_addr40位经6路同Bundle仲裁完整传递；有效row来源req_addr[39:6]补6零，DCache比较line_addr[39:14]，没有常量tag0、漏接或sideband截断。无相关width/connection/unused告警，已有annotation告警类型与修复前一致。审查本轮没有修改功能源码，前后hash一致。

结论：**本次接口修复静态PASS，可以开始第一轮定向仿真YES**。尚未验证首cache miss、refill_fault、原watchdog或后续Phase-1行为，不宣称完整Phase-1已通过。报告：[方案A静态审查](../history/reports/phase1_refill_sideband_review_20261012.md)；独立生成物和命令证据在`AI/TMP/phase1_refill_sideband_review_20261012_193958/`。本轮未构建/运行新Verilator executable，下一步由用户运行原testcase。下方“未修复”是修复前RCA历史状态。

## 最新用户运行 [1000]：refill tag 接口 RCA（未修复）

用户已于2026-10-12 16:57 +08构建默认debug simulator并运行；默认日志/FST与下方“未运行”的历史状态不同。最新日志为`BoomMSHR.sv:578 / mshrs_0.assert__assert_4`，源码`mshrs.scala:208` active refill owner mismatch。只读RCA已确认：`BoomCacheRefill`继承14-bit数组addr，`dcache.scala:1169`却从该字段右移14位提取物理tag。首个normal cacheable line0x80087fc0的reservedTag=0x20021，refill array addr=0x3fc0，computed tag=0；context/install/slot/epoch/transaction/MSHR/resident-epoch关系全部匹配。FST2861 first valid refill fault，最后低沿2862；下一上升沿abort。日志[1000]是时间格式化值，不是精确DCache cycle，trace_count约1431。

报告：[refill tag RCA](../history/reports/phase1_refill_tag_rca_20261012.md)；完整证据在`AI/TMP/rca_phase1_1000_20261012_175456/`，含源码/生成RTL/C++摘录、500-cycle窄波形、逐谓词证明、manifest与旧源码重建hash。旧[264000]case在启动same-line refill已卡住，watchdog只是迟报；当前descriptor/reservation正确，旧MMIO污染/early STQ释放在本事务中未重现，但新增tag条件破坏normal refill。本轮没有功能源码修改、compile、RTL生成或新仿真。

建议而未实施：显式完整physical line侧带从immutable MSHR descriptor经refill arbiter传到DCache；array addr保留原14-bit语义；tag校验使用完整line，保留全部owner检查。当前normal regression会触发，须先恢复接口后动态验证fill/install/replay/terminal，以及历史clear/order反例。完整Phase-2 certificate与独立AMO.W terminal result问题未在本轮修复，不把它们冒充本次首因。

## 最新 elaboration 报错修复与生成验证

2026-10-12 用户终端的 `InvocationTargetException` 实际由 `dcache.scala:916` 的 `OHToUInt(candidateWay)` 输入宽度未知引起。已将 candidateWay 显式声明为 `Wire(UInt(nWays.W))`，保留原 hit/replacement 选择逻辑。隔离目录 `AI/TMP/phase1_elaboration_fix_20261012_151358/generated` 中的 v1Config Chisel elaboration、Scala FIRRTL low lowering、firtool verification/CheckCombLoops、Verilog 与 top/model 内存宏生成均通过；两个 make 目标退出码均为 0，`git diff --check` 通过。该次Agent没有构建新 Verilator executable 或运行仿真；此后用户的新运行与最新失败见上方，不再将默认路径视为旧证据。

报告：[Phase-1 elaboration 位宽修复](../history/reports/phase1_elaboration_width_fix_20261012.md)。该次只修生成错误，没有修改已知 cacheable AMO.W terminal result 的字选择/符号扩展问题。该次允许第一轮定向 regression 的静态判断随后被用户运行推进；上方RCA新增证明normal-path refill tag接口必然错误，后续重跑前须先修复该接口，动态功能验证未通过。

## 最新 Phase-1 closure 源码实施（动态验证 pending）

2026-10-12 在原 working tree 上完成 Phase-1 源码修改：统一 admission/current S2 effective payload；primary reservation 与 resident epoch 分离；secondary 继承、MMIO 无 cache owner；完整 MSHR/RPQ/SDQ identity；held S3/terminal completion、功能 STQ token 与 older-store ordering；逐语义写 local image serial；clear/probe/replacement drain 与 resident recheck；full-line install 最末 data fire 提交 owner；完整 Grant 捕获后独立 held E；统计 RESET 不清功能 bitmap/safe/owner/pending。真实 owner mismatch 为 assertion/fault，保留责任并停止共享 LineBuffer 读口申请，不转普通 retry。

已完成 BOOM Scala compile 和源码静态审计，记录在 [closure implementation notes](../../Design/cache_version_preservation_phase1_implementation_notes_20261011.md)、`AI/TMP/phase1_closure_20261012/identity-audit.md` 和 `compile-final-nodata.log`。**该次源码实施只做 compile；后续 elaboration/FIRRTL/硬件生成结果见上方最新验证，仿真仍未执行，未声称 watchdog 或旧功能反例已动态修复。** 旧 RCA/FST 仍属于修改前证据：[264000 RCA](../../TMP/rca_phase1_264000_20261012/report.md)。

后续动态验证覆盖 primary/secondary/MMIO、SC/AMO、clear/refill 和 backpressure，最后运行原软件并检查 `verified=1` 与实际字节结果；不得以 package PASS 数或 simulator PASSED 代替功能验证。完整 Phase-2 preservation 未实施。下方原生成报错及旧运行诊断保留为历史上下文。

## 最新 Phase 1 生成报错修复

2026-10-12 用户硬件生成遇到 `BoomNonBlockingDCache.s0_req_0_effect_token_valid` 组合环。源码根因已确认：token 分配条件读取其自身赋值的输出 flag。已在 `dcache.scala` 分离 `s0_selected_req` 输入与 `s0_req` 输出，条件只读输入，消除这条直接组合反馈。BOOM Scala compile 于 08:43:23 +08 通过，源码 `git diff --check` 通过。用户负责硬件生成和仿真，本轮未执行 elaboration/FIRRTL/仿真，尚不能确认整机组合环检查或 Phase 1 功能回归通过。记录见 [Phase 1 implementation notes](../../Design/cache_version_preservation_phase1_implementation_notes_20261011.md)。下方波形与功能诊断仍属于修复前运行。

## 最新只读诊断

报告：[functional_diagnosis_20261011.md](../history/reports/functional_diagnosis_20261011.md)。本轮未修改正式代码、生成 RTL、编译或运行新仿真；分析当前 output 路径已经存在的运行。

本轮 recovery 设计差距分析：[cache_recovery_gap_analysis_20261011.md](../../Design/cache_recovery_gap_analysis_20261011.md)。部分 L1 cross-package shadow writeback 和真实 L2→DRAM barrier 有效；完整的 predecessor 保存链与 package-level cache rollback 未实现。新增证据：safe-old 分支直接写（接受沿433887）；L2地址`0x80035e00`的safe seq4在没有同址outer C下推时被speculative seq6改写（接受沿480795）；MSHR replay可绕过跨包控制（settled2034571）。已知clear/refill race丢的是新Q的store，首先是普通数据顺序违例，不能单独当作unsafe越过DRAM的证据。目标可以通过下层副本和有序握手保存predecessor，并非必需本地双份data；本轮只更新设计资料，未改正式代码或运行新仿真。

正常执行期间的统一设计评审：[cache_version_preservation_unified_design_20261011.md](../../Design/cache_version_preservation_unified_design_20261011.md)。2026-10-11 revision 2 已收敛 preservation certificate：证书绑定完整 `content_seq+generation`，区分事实与resident附着bit；validation不清版本身份；L1跨包handoff、L2同址predecessor和异址victim使用分离FSM。当前last-level Cork约束下，同址保存采用TtoB→BtoT，异址eviction保留TtoN；C/D按transaction锁存provenance和barrier许可，ProbeAckData直写旁路仍需合并，SourceD晚ACK独立。Phase1修local ownership/effect completion，Phase2接完整保存链，Phase3落实有界escape与drain credits。该liveness分析是源码依赖结论而非本run新死锁证据；TL字段、Grant无data和资源容量仍需实施前核对。本轮未改正式RTL，不实现FAIL rollback，尚无新方案动态验证。

- 当前 HEAD：`a68183c83e08ed837c677aec7836c97895e3a95e`。原路径输出时间为 2026-10-11 10:05 +08；当前日志和软件 hash 与下方旧 manifest 一致，但 `test.out`、FST hash 不同，不能静默视为旧运行。当前 manifest 位于 `AI/TMP/diagnosis_20261011_current_manifest.json`。
- **已定位功能错误**：`out_offset[264]`（`0x8005a1e8`）写 `0x1080` 后读回0；更早的 FST 窄波形证明 shadow metadata clear 当拍的 S1 store 使用旧 hit 信息通过 S2，并在 clear 后写 data array，随后旧 refill 覆盖它。接受沿为 clear `432471`、store write `432475`、refill覆盖目标row `432527`。FST 时间为 `2*trace_count+half_cycle`。
- **已定位统计/身份错误**：同包 BOOM 实际普通访存重建为 store60655/load84738，291个包与checker逐包一致。BOOM漏计164/258，全部在snapshot退休；首个store在seq103、FST `1327493`。更早 `1327169` 的STQ捕获锁存了零seq，因为 `core.scala:2363` 在非check状态已输出0，而producer仍拥有seq103。当前generated LSU已包含scope锁存修正，输入身份仍有bug。
- **barrier边界**：L2→DRAM候选/门控/close ACK/safe/release链真实生效，五个候选最终释放；L1→L2仍允许430次unchecked dirty writeback，该类replacement统计为monitor。零tag访存会影响barrier归属，不能由tracked路径通过推断全覆盖。
- **收尾**：checker/result/validation/strict/barrier pending排空，tracked L1 attribution没有seq>safe291；最终MSHR3在tohost的drain状态、fence_rdy=0，属于有证据支持的退出尾流，整机没有完全静止。软件未把verified纳入END或exit code，故功能FAIL与simulator PASSED同时出现。
- **尚未验证**：所有后续mismatch是否同一首因、零tag是否导致其他line真实越界、safe/control C额外停顿、完整构建来源，以及任何修复后的回归。

## 工作树身份

- 运行采集时的代码基线：`ba883dac9e9c50eca94a8a09ac8dd542457798cc`（同步时已从该未发布提交移除旧 Debug 生成物，映射见 `../references/git_sync.md`）。
- 本次整理及同步没有修改 Chipyard 正式功能代码；当前 HEAD/分支同步状态以 `git status --short --branch` 为准。
- 配置：`v1Config`，源码默认 `GH_REAL_BARRIER_ENABLED=true`，1 个 BOOM + 4 个 Rocket checker。
- 软件：`Software/Test/test.riscv` SHA256 `7d440cced710e16958d0121fcac377d57266c9c54a82845e2d5dc9a3a0a9c686`。

## 保留的 2026-10-10 运行记录

原输入路径：`chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/{test.log,test.out,test.vcd}`。这些路径已被新运行覆盖；下面的时间、hash和大小只属于旧manifest。`.vcd` 实际是 FST 容器；日志时间 2026-10-10 18:07:23 +08，FST 时间 18:07:25 +08；该运行的波形为 2,275,433,245 bytes（约 2.12 GiB）。

- 程序到达 `[END]`，但 `verified=0`，`parent_checksum=947892178`。
- `packages allocated/completed/passed = 291/291/291`，这只说明 package result 数量平衡。
- `boom_arch`：store 60491、load 84480。
- `boom_strict`：store 60491、load 84480。
- `checker_sum`：store 60655、load 84738；差值分别为 164、258。
- address stats、L1-L2、L2-DRAM 的本次打印结果不能替代 `verified=1`。

最新证据 manifest：[manifest.json](evidence/latest/manifest.json)；日志副本：[test.log](evidence/latest/test.log)；模拟器结尾：[completion_excerpt.txt](evidence/latest/completion_excerpt.txt)。独立 FST reader 验证范围 `0..9304241`。原 `test.out` 的 `*** PASSED *** Completed after 4652121 cycles` 与 `test.log` 功能 FAIL 同时存在：模拟器返回/退出条件与 benchmark correctness 必须分别判断。完整 output/FST 的独立备份已按用户要求删除；长期区保留日志、manifest 和窄证据，原仿真 output 路径可能被后续运行覆盖。

## 2026-10-10 留存结论

**当时已证实的事实**：程序完成但功能校验失败；package 数量平衡；BOOM 与 checker 流量计数不一致。仅该日志没有提供 first bad state、root cause 或修复通过证据；当前波形的后续诊断见本文件顶部。

**历史上已证实、需要先复核的机制**：528000 的旧 run 曾证明 R_IC 在 barrier close 后过早发布 `count=558/done`，而 BOOM 同一 seq 实际退休 600 条，造成 42 条尾部（5 条 store）留在 LSL；459000/461000 曾分别证明同步 FIFO head 生命周期、LSL 类型/地址匹配和 frontend redirect 生命周期存在独立问题。详见 `bugs/`。

**当时尚未验证**：291-package 运行的 first bad / root cause；计数差值是否是同一首因；源码→生成 RTL→simulator→波形的完整对应关系；barrier、LSL、snapshot、drain、strict-token 回归。当前诊断已分别定位功能首因和统计首因，但没有修复/新回归通过证据。

## 下一步

1. 先针对shadow metadata clear/S1/S2/store/refill的已证实ordering违例设计line interlock和最小assert，保留正确的STQ/token重试语义。
2. 修正包边界的身份源；增加owned memory零tag检查，验证按seq的retirement/LSQ/checker计数相等。
3. 把benchmark verified合并到END和exit code；在进入HTIF退出前采集完整drain状态。
4. 用户授权实施后，依次做源码静态、elaboration/FIRRTL、定向验证和同软件的整机回归；不能用package PASS替代内存正确性。
5. 未验证问题继续保留，trace/大型中间结果留在 `AI/TMP`，不得自行清理。

## 状态维护规则

每次 `Root Cause → Fix Design → Implementation → Validation` 完成后，更新本文件；结论进入 bug/history；通用经验进入 skills/checks；脚本进入 scripts；大型输出只进 TMP。
