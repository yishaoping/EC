# Stage 1 全项 closure 审计 — 2026-10-17（最终动态验证已完成）

本报告先记录了旧 run 的全项离线归因和集中修复；末尾第 11 节补入同一 patch 集合的最终动态验证。旧 run 的两个独立问题是 package drain 尾部统计漏计，以及无限 HTIF exit loop 在 host success 后仍产生 L1 工作。最终 run 已验证两项修复，Stage 1 现可关闭。

前半部分的归因与准入阶段没有运行 Scala/hardware compile、Chisel elaboration、FIRRTL、Verilator、simulation 或 `stage1_build_and_run.sh`；仅做源码修改、已有 FST 的离线读取、Python/host unit tests、独立软件 ELF 构建和静态检查。最终动态验证及其证据单独记录在第 11 节。

## 1. 旧 run 身份与证据边界

```text
RUN_DIR=/data1/gzh/EC/AI/TMP/stage1_closure_run_vRXs98g3
BUILD_DIR=/data1/gzh/EC/AI/TMP/stage1_closure_build_PlMlLDP7
PROVENANCE=PASS（本轮修改前验证；绑定原 run 的源码、生成物、binary）
SIM_HASH=84dbe6de62f1a8114e4decf1c85d3702cb3730e474c3f3a8cec619fe383d88b9
SOURCE_STATE=原 run 的 11477 个 source inputs 一致；当前源码已打补丁，待新 build
GENERATED_MODEL_FILES=3001
SIM_EXIT_CODE=0
SIM_EXIT=reason=serial_success io_success=1 cycles=5441274
BENCHMARK=gapbs_bfs nodes=512 reached=512 edges=8192 verified=1
PACKAGES=allocated338/completed338/passed338
TRACE_SHA256=f62b6e7a99a8f948a2a6be0bbcbf242b682a6da8240a2870fff4539a4ec0718e
FST_SHA256=799be1ae752a62ad69332d58c980f4d1f0acf91255e6394bf645c93d61091076
ORIGINAL_ANALYZER_SHA256=ed8b6345a7960e7a961d44e6f378b41c041e3e71a6e0df1c3bc0004f941a408f
REVISED_ANALYZER_SHA256=47e9ee115fcf41afd38ab768f8c6f68ac13edebfc802da2aee6d05e4553dc53b
```

`trace.log` 为 2688788513 bytes，`trace.fst` 为 2601344328 bytes，运行结束于 2026-10-17 00:46:22 +08。原 ELF SHA256 为 `bcae2a9f4b67a8ce98c56f31085cc37c0cb67e466c51e61d6db645e1146008be`。

原 run 内 `provenance.json`、`workload.json`、analyzer 副本与 `run.json` 的输入 hashes 均核对通过；原始 scoreboard/trace/生成物保留。TestHarness 的旧 `collect`/`Nothing.hartId` 编译错误在这次成功 build 中已消失。

完整 source/generated hashes 在 [原 provenance](/data1/gzh/EC/AI/TMP/stage1_closure_run_vRXs98g3/provenance.json)。本轮 [证据目录](/data1/gzh/EC/AI/TMP/stage1_audit_20261017_atpbr625) 保存 `identity.json`、`source_before.json`、`source_after.json`、`incremental.patch`、原文件快照、FST 提取、逐事务 joins 和修订分析。当前源码发生的变化不会回写为原 build 的 provenance。

时间单位：该 FST 的奇数时刻 post-eval DCache CSR cycle 为 `(t-205)/2`；例如最后 `t=10882547` 对应 `5441171`。printf 中已有 `cycle=` 保留其 pre-edge 语义。旧 LSU 事件没有 cycle 时，仅给日志行号及 `~` 标记的最近先前 cycle，不伪造精确退休/释放时钟。表中的 `CAPTURE_POST_CYCLE` 是 LSQ 状态改变后的 CSR cycle。

## 2. 九项 Stage 1 matrix（旧 run，经修订 analyzer）

| 项目 | 原 run 结论 | 依据 / 当前补丁状态 |
|---|---|---|
| architectural data/error | PASS | verified=1；无 RTL assertion/LSL/data mismatch |
| AMO.W | PASS | low/high 各 swap/add；old/lane/mask/merge/return/sign extension 全部匹配 |
| main/checker | **FAIL** | main 155274、checker 155603；329 条全部唯一归因；已修统计 ownership，待动态验证 |
| clear/S1/S2/refill | PASS，mode B | 184 次 clear 的实际 runtime invariant 均通过；未发生的 overlap 单列于第 4 节 |
| effect → terminal | PASS | 146422 次 cache effect，均有唯一 terminal |
| terminal → STQ release | PASS | 146481 次 terminal/store_done；无 missing/duplicate release |
| duplicate effect | PASS | 0 |
| lost effect | PASS（已观察生命周期） | 0；退出时仍在推进的请求归入 exit gate，不称为已丢失 |
| exit outstanding | **FAIL** | 真实 L1 请求 `0x52788` 尚在 S2/replay/MSHR；已修有限 exit stimulus 和排空边界，待动态验证 |

另有 `replay=PASS`，8365 grant/result 均闭合。`software_report=FAIL` 是 main/checker 漏计在软件 `[ASSERT]`/`[END]` 的传播，不是第三个独立故障。

## 3. Scoreboard 实际 counter

```text
ARCH_ERROR=0
AMO_LOW_LANE_SEEN=1  AMO_LOW_LANE_PASS=YES
AMO_HIGH_LANE_SEEN=1 AMO_HIGH_LANE_PASS=YES
AMO_ERROR=0
MAIN_STORE_COUNT=60479   CHECKER_STORE_COUNT=60566
MAIN_LOAD_COUNT=94795    CHECKER_LOAD_COUNT=95037
MAIN_COUNT=155274        CHECKER_COUNT=155603
MAIN_CHECKER_DIFF=-329
MAIN_CHECKER_STORE_DIFF=-87
MAIN_CHECKER_LOAD_DIFF=-242
MAIN_ONLY=0 CHECKER_ONLY=329
DUP_IN_MAIN=0
DUP_IN_CHECKER=0 detected（原 trace 无 checker 独立 event ordinal，见第 5 节）
DUP_EFFECT=0 LOST_EFFECT=0
EFFECT_WITHOUT_TERMINAL=0 DUP_TERMINAL=0
TERMINAL_WITHOUT_STQ_RELEASE=0 DUP_STQ_RELEASE=0
REPLAY_UNCLOSED=0 CLEAR_RACE_VIOLATION=0
EXIT_REAL_OUTSTANDING=1 EXIT_LOOP_PENDING=15
```

六 counter 顺序为 store total/cache/uncache、load total/cache/uncache：

| 来源 | st_total | st_cache | st_uncache | ld_total | ld_cache | ld_uncache |
|---|---:|---:|---:|---:|---:|---:|
| BOOM arch | 60479 | 60430 | 49 | 94795 | 94498 | 297 |
| BOOM strict | 60479 | 60430 | 49 | 94795 | 94498 | 297 |
| Checker sum | 60566 | 60517 | 49 | 95037 | 94740 | 297 |
| 差 | -87 | -87 | 0 | -242 | -242 | 0 |

事件总数：ARCH_STORE 146585，LOAD_TERMINAL 181667，EFFECT 146422，TERMINAL/STORE_DONE 各 146481，RELEASE 146570（含 fence），INSTALL 8256，REFILL 32300，CLEAR/CLEAR_CHECK 各 184，REPLAY_GRANT/RESULT 各 8365。59 个 MMIO terminal 无 array effect，按 admission 精确分类。328252 个架构功能 token 无重复。

软件其他报告：L1–L2 total/dirty/required/verified/unverified/resolved/nonverify 为 `1448/1407/949/524/425/425/458 PASS`；L2–DRAM 为 `49/47/8/8/0/0/39 PASS`。三个 barrier 的 pending/dropped 均 0、valid=1、PASS。地址统计四种粒度满足软件 bounds；没有其错误/超时诊断。终端两条 `[ASSERT] store/load ... result=FAIL` （L20678255/L20759280）以及 `[END] status=FAIL`（L22248237）均对应第 6 节根因 1。

## 4. 所有失败事务与四个风险点

### B. 329 条统计失败的完整集合

[逐事务表：330 行](stage1_closure_20261017_transactions.tsv) 包括全部 329 个 checker-only 事务及唯一 issued exit 请求。每行有 TX、kind、package、PC、address、首次错误捕获 FST/post-cycle、R_IC 状态、check、最小完整事件链和原日志行号。不能只用按 PC 的总数替代这张表。

连接方法：按 `(package_seq, kind, PC, address, cacheability)` 做 occurrence multiset subtraction，再用独立 ARCH_STORE/LOAD_TERMINAL、稳定 functional token、LSQ FST tags 反向核对。329 条全部只有一个合法功能候选；87 store 均有一次 EFFECT、TERMINAL、STORE_DONE、RELEASE；242 load 均有一次 LOAD_TERMINAL，其中 234 为 cache response、8 为 STQ forwarding。重放 load `0x1d98c` 另关联 MSHR1/txn`0x4be` 的 INSTALL 及四个 REFILL beat，表内及 `owner_install_refill_chains.json` 保留证据。

所有 329 条在地址捕获时 `traffic_check=0`、package 正确、`producer_open=1`、`if_correct_process=1`、`trafficCounting=1`。R_IC 捕获状态分布：fsm_snap(4) 177，fsm_postcheck(7) 80，fsm_cooling(3) 72。旧 Tile 却只在 fsm_check/debug status 2 提供统计资格。

第一个 store：`TX=0xcb1c, seq=1, PC=0x80000818, ADDR=0x8005a314, STQ=9`。首次错误状态 `FST=1308791, post-cycle=654293`，owned drain 被锁存为 check=0；随后 ARCH_STORE（L2341486）→ request（L2342007）→ S1 654421 → S2 hit 654422（set0x8c/way0/epoch0xf）→ effect 654423 → terminal 654425 → release（L2342032）。Checker 在 L2397548 计数该同包提交。功能效果完整，first bad 是统计资格捕获。

第一个 load：`TX=0x12fad, seq=132, PC=0x8000491e, ADDR=0x80008038, LDQ=13`。错误捕获后 cycle=2114741；request L7374506/7 → S1 2114741 → S2 hit 2114742 → LOAD_RESP L7374522 → LOAD_TERMINAL L7374536。Checker 在 L7419596 计数；LSQ 波形保留 seq132/check0。

把新 ownership 表达式应用于旧 trace/FST 的全部未计数功能提交，恰好得到 **329 个补回、0 个额外纳入、0 个遗漏**；这是旧运行的离线反事实检查，不是新 RTL 的仿真结果。其反事实 main 总数为 155603。下轮不硬编码此总数，只要求 main/checker occurrence 集及 counters 相等。

### A. AMO.W 双 lane 的实际语义

Directed 四个事务均为 seq1、set0xf8/way1/epoch9。共 102 个 AMO effect 均通过独立算术参考；其中四个 directed 操作如下（32-bit 列为选择的 word）：

| TX | lane/op | old32 | operand32 | new32 | RV64 return | mask | effect → terminal cycle |
|---|---|---|---|---|---|---|---|
| 0xc8aa | low swap | 80000001 | 76543210 | 76543210 | ffffffff80000001 | 0f | 648441 → 648443 |
| 0xc8ab | high add | fffffffc | 00000007 | 00000003 | fffffffffffffffc | f0 | 648464 → 648466 |
| 0xc8ac | low add | 76543210 | 00000007 | 76543217 | 0000000076543210 | 0f | 648481 → 648483 |
| 0xc8ad | high swap | 00000003 | 76543210 | 76543210 | 0000000000000003 | f0 | 648498 → 648500 |

完整 cache 64-bit 结果依次为 `fffffffc76543210`、`0000000376543210`、`0000000376543217`、`7654321076543217`；未选择 lane 保留。地址分别为 low `0x80007e00` / high `0x80007e04`。四者均有 request→S1→S2 hit→held write→EFFECT→TERMINAL/STORE_DONE→ARCH_STORE→RELEASE；完整链在 `chains.json`。软件 verified=1 同时确认返回值和最终 array words。先前 `LoadGen.wordData` 上 lane 修复已在这次 run 动态通过。

### C. clear/S1/S2/refill 的实际 overlap

下表计数单位为发生并发条件的周期；S1/S2 为 CLEAR_CHECK 目标 set 上的 occupancy，hit 为 S2 admission=hit 的候选，包含可能被 nack 的尝试。

| 条件 | 实际数量 | 结论 |
|---|---:|---|
| clear / S1 | 183 | 其中旧 epoch/before-freeze S1 为 0 |
| clear / S2 | 16 | 其中旧 epoch/before-freeze S2 为 0 |
| clear / refill（全局同周期） | 0 | NOT_OBSERVED |
| LSU S1 kill / replay pipeline busy | 172 | FST 重建；这是并发活动，不等于同一 replay 被杀 |
| S1/S2 replay 真正被 kill | 0 / 0 | NOT_OBSERVED |
| S3 pre-effect kill | 0 | NOT_OBSERVED |
| install / S2 hit 候选 | 161 | 实际竞争覆盖 |
| refill / S2 hit 候选 | 791 | 实际竞争覆盖 |
| install / effect | 9 | 不同受允许 slot 的并行活动 |
| refill / effect | 0 | NOT_OBSERVED；共用 dataWriteArb 的两路不能同时 fire |

184 个 CLEAR_CHECK 全为实际 fire。clear/refill 同 slot 由 `crossPackageSlotConflict` 与 refill 的 live MSHR reservation/installOwner 前提互斥；clear 还必须通过 `crossPackageMetaClearBlock`（旧 S1/S2、S3、completion 排空）。installDrain 拒绝覆盖同 slot 的 S3/completion 和旧流水。effect 验证当前 owner/image/epoch，post-clear INSTALL/REFILL/EFFECT epoch 不能陈旧；REFILL owner、beat 次序/重复、同 slot clear/effect 均由 analyzer 检查，违规 0。

本轮没有观察到 replay 的真实 branch/exception cancellation，不能声称这个动态场景已覆盖。其静态保护是 S2 valid 的 kill gating、`s3_effect_eligible` 排除 `s3_pre_effect_kill/s3_cancelled`，以及 replay kill 产生匹配 owner 的 CANCEL result。保留这些原逻辑，新增 KILL/RACE_OBSERVE 供下轮自动记录。Mode B 对已发生 overlap 的 runtime 检查，加上上述同 slot 互斥，可关闭本轮 clear 结论；没有为本次为零的全局 overlap 添加虚假的 coverage PASS 或另行要求一轮专用仿真。

### D. 退出活动事务与 `_exit` 分类

```text
TX=0x52788, seq=338, STQ=0xa, flags=0xa7
PC=0x80006948, ADDR=0x80007d00 (tohost)
CYCLE_RANGE=ARCH@~5441061 .. exit post-eval5441171
EVENT_CHAIN=committed -> 6 LSU attempts -> S2 upgrade5441160
 -> MSHR5/txn0x57e -> INSTALL5441168 -> replay S1 5441170
 -> live S2 at FST10882547 -> host success stops simulator
FIRST_BAD_EVENT=host success 被直接用作 L1 完成边界；此时没有 effect/terminal/release
ROOT_CAUSE=libgloss 无限 HTIF store loop 持续发出新请求，emulator 立即停止
```

最后 live cache 状态：S1=0、S2=1、active MSHR=1、fence_ready=0、replay_busy=1、install_active=1、slot_reserved=1；LSU committed STQ=15、inflight=1、LDQ valid/pending=0。replay_result_q/completion_q/S3/store_done/WB/probe/refill/pending_response/response/TL A/D/E 均为 0。MSHR5 在末尾从 refill request/response 前进到 commit_line、drain_rpq，再送出该 replay；这是权限 upgrade 的 install，不伪称观察到了额外 GrantData refill beat。

其余 14 条精确 `_exit` PC/address 且 flags0xa3 的 committed/unissued 条目属于软件 pipeline tail；没有被当作 LOST_EFFECT。唯一 issued token 0x52788 在修订 JSON 的 `real_outstanding` 中明确列出。invalid S3/completion payload 的旧 req ID 不代表活动 owner。原严格 filter 没有隐藏这个请求，exit gate 原本就正确 FAIL。

前一 fromhost 请求 `0x52787` 已在 effect5441136/terminal5441138 后 release；当前新请求只观察了几十周期且仍有进展，不能据此认定 L1 deadlock 或丢失。修复 stimulus/观察边界即可，不修改 MSHR datapath/FSM。

## 5. Analyzer false positive / false negative

没有发现会把本 run 的两个真实失败改成 PASS 的 analyzer false positive。修正的诊断/潜在 false negative 为：

1. 负向 PC 差曾在 `most_common(35)` 取样后被零值挤掉，错误输出空列表；现在对非零项按绝对差排序，完整保留 25 个 PC groups。
2. 以前只按总数/粗 package 聚合；现在输出 MAIN_ONLY/CHECKER_ONLY occurrence 集，保留重复地址的正常循环次数，且相同 package 总数不能遮蔽 PC/address 不同的错误；新增 trace/counter 一致性检查，包括全部统计事件缺失而 counter 非零的情况。
3. 原 `real_outstanding` 列表按 PC 把所有 `_exit` 请求移出，虽然 gate FAIL 正确，JSON 却可能显示空列表；现在只有精确 live committed/unissued owner 才不列为活动 L1 事务，0x52788 被保留。
4. 原 trace 没有 checker event ordinal，缺少独立身份时即使总数相等也只能 UNRESOLVED；不能把同 `(seq,PC,address)` 的多次循环访问叫 duplicate。DUP_IN_CHECKER=0 表示未检出，不是独立 event-ID 去重证明；全部事件与功能 occurrence 严格匹配，未解释的额外 checker occurrence 为 0。下轮增加 `(hart,ordinal,cycle)`，analyzer 可精确检出重复记录。
5. 软件 `[ASSERT]` / `[END] FAIL` 以前被忽略；现在独立保留 software_failures/software_report gate，和 architectural_data 分开；缺 END 状态时不能输出完整 closure PASS。当前软件失败是根因 1 的传播；不会错误增加 ARCH_ERROR。
6. 补齐全周期 clear/refill、install/refill 与 hit/effect 的并发计数，以及可选 KILL/RACE_OBSERVE 检查。旧 run 的 kill/replay 计数取自同一 FST，未向原日志注入合成事件。

旧 trace 不含 LSU STORE_DONE/RELEASE 的显式时钟，因此原跨周期顺序只能结合存在性、RTL握手与 token 证明；本轮为关键 LSU 生命周期事件补同一 CSR cycle，下轮可自动检查先后顺序。

## 6. 根因聚类、修复及 invariant

**ROOT_CAUSE_1 — RTL 统计资格不覆盖 owned package drain。**

- BUG：LSQ 锁存 `trafficCounting && (debug_maincore_status==2)`，而 R_IC 的 `count_owned` 包含 producer_open 的 closing drain。
- EVIDENCE：所有 329 个失败唯一功能事务及其 LSQ FST、owner/state/window；反事实补回329/额外0/遗漏0。
- ROOT CAUSE：用 FSM 的单个阶段替代 package ownership 生命周期；此前补上 `traffic_check` 解决了 setup/post-window 多计，但暴露了其上游定义过窄。
- FIX：R_IC 导出 `traffic_package_open=producer_open && if_correct_process`；count_owned 复用此表达式，经 Core/Tile 送给现有 traffic_check_state。LSQ 首次有效地址锁存、retry 保留、非零 seq、退休资格和 STOP tail 规则保持一致。
- POST-FIX INVARIANT：普通架构 load/store 仅在已分配且被当前 checking process 拥有的窗口内取得统计资格；ownership drain 不漏计；关闭后仅残留非零 seq 不能取得资格；重放不创建新统计身份。新增 owned traffic 必须有非零 allocated seq assertion。

**ROOT_CAUSE_2 — 有限程序完成与 L1 quiescence 边界不一致。**

- BUG：libgloss `_exit` 无限 fromhost/tohost 写，host success 立即停止，可能截断其后续真实事务。
- EVIDENCE：0x52788 明确 live S2/MSHR/install/replay，14 条 unissued，上一请求已完整完成。
- FIX：Test workload 强定义 `_exit`：关闭本 hart 的机器中断，一次 fromhost=0、一次 tohost=code，fence rw,rw 后仅寄存器内跳转；Stage 1 emulator 锁存 host success，继续正常时钟直到真实 cache/LSU probes 排空。失败仍立即退出，原 max-cycles 上限保留，没有固定等待周期或状态豁免。
- POST-FIX INVARIANT：host success 是完成候选；成功退出还必须 schema1、fence_ready、active pipeline/MSHR/install/replay/completion/probe/TL/LSU 均空。invalid payload ID、parked prefetch owner 不作为活动事务；所有 committed/valid STQ 及 LDQ 仍需排空。helper 不反馈任何 RTL control。

`SimSerial.cc` 后续 tick 的可行性已静态检查：TSI host_thread 在 `run()` 返回后仍循环 yield 给 target，继续 eval 能让真实 L1 工作退休；没有启动额外 simulator 进程。

**ROOT_CAUSE_3 — Analyzer 诊断遗漏。**

修复第 5 节的集合/负差/outstanding/software failure 输出，保留旧 run 原有真实 FAIL。没有以 analyzer 修正为理由改动 cache 数据路径，也没有放宽 `_exit` loss filter。

## 7. 本轮修改文件

| 文件 | 本轮目的 |
|---|---|
| `rocket-chip/.../r/R_IC.scala` | 导出 canonical traffic ownership、复用 count_owned、非零 seq assertion |
| `boom/.../exu/core.scala` | 路由 traffic_package_open |
| `boom/.../common/tile.scala` | 用 package ownership 驱动统计资格 |
| `boom/.../lsu/lsu.scala` | 加同一 CSR timestamp 输入；关键事件带 cycle；LOAD_TERMINAL 带 seq/check |
| `boom/.../lsu/dcache.scala` | 观察 timestamp 路由；ISSUE 明确 source/cycle；KILL/RACE_OBSERVE |
| `rocket-chip/.../r/R_ICSL.scala` | checker 事件加 hart/ordinal/cycle 与单 instruction 单事件 assertion |
| `Software/Test/test.c` | 有限 HTIF `_exit`，保留 AMO.W/BFS 主测试 |
| `chipyard/.../csrc/emulator.cc` | latch host success 后按真实状态排空；成功 reason 与 verbose 解耦 |
| `chipyard/.../csrc/stage1_exit.h`（新增） | 无 RTL 依赖的可测试排空 predicate |
| `AI/Debug/scripts/stage1_trace_scoreboard.py` | 集合差、重复事件身份、counter/trace 校验、负 PC 差、real outstanding、软件失败、并发 coverage |
| `AI/Debug/scripts/test_stage1_trace_scoreboard.py` | 上述 analyzer 问题的正反例 |
| `AI/Debug/scripts/test_stage1_exit_policy.py`（新增） | standalone host helper 逐 blocker/parked owner 正反例 |
| 本报告、逐事务 TSV、state/timeline/scripts README | 保存当前事实、来源边界与一次最终验证准入 |

其他预先存在的 dirty 文件保留。本轮未修改生成 RTL、MSHR FSM、AMO datapath、L2 设计或既有 build/run wrapper 的运行次数。

## 8. 初始静态与离线验证

```text
Analyzer/provenance/exit-policy unit tests: 32 PASS
Python AST syntax: PASS（6 个 Stage 1 Python 文件）
Shell bash -n: PASS（3 个 Stage 1 shell wrappers + Software/Test/compile.sh）
STAGE1 printf format/argument arity: 31 checks PASS
git diff --check: PASS
WORKLOAD_IDENTITY=PASS（新独立软件 ELF/dump/loadmem/source hashes）
Same trace revised analyzer: 完成；预期 exit 1，两个独立根因仍 FAIL
Trace hash: 与原 run 完全一致
All 329 functional attribution: unique match 329 / ambiguous0
Counterfactual ownership recovery: recovered329 / extra0 / missing0
Scala/hardware compile/elaboration/FIRRTL/Verilator/simulation: NOT_RUN（初始静态阶段按用户禁止；最终动态 run 见第 11 节）
```

unit suite 的新增 host C++ 测试仅编译几十行 FakeHarness/predicate fixture，不加载 generated model 或任何 Verilator 文件。全体真实 cache/LSU blocker 逐项置位均阻止退出；parked owner 和 invalid payload ID 不阻止空闲退出。

同 trace 最终输出在 [scoreboard.final.out](/data1/gzh/EC/AI/TMP/stage1_audit_20261017_atpbr625/scoreboard.final.out) / [scoreboard.final.json](/data1/gzh/EC/AI/TMP/stage1_audit_20261017_atpbr625/scoreboard.final.json)，原 scoreboard 不覆盖。精确修订 analyzer 副本与 SHA 保存于同证据目录。

新软件 manifest 为 `AI/TMP/stage1_workload_final_20261017.json`，并已更新默认 `AI/TMP/stage1_workload.json` 指向同一身份；旧默认副本及原 run manifest 保留。新 ELF `AI/TMP/stage1_workload_M1vSNwQC/test.riscv` SHA256 为 `64d450b7288198d7ba0b317221914ffe7930d9223ef4868e66bda691386a3ce3`。反汇编 `_exit=[0x800007b0,0x800007d8)`：两个一次性 sd，随后 fence 和跳到自身 `0x800007d4`，没有新访存循环。AMO 地址仍为 `0x80007e00/04`。

## 9. 原始准入状态（历史，已由第 11 节更新）

```text
STAGE1_STATUS=PATCHED_PENDING_FINAL_VALIDATION
NEXT_SIM_REQUIRED=YES
MINIMUM_SIM_COUNT=1
PRE_FLIGHT=PASS_STATIC_ONLY
```

旧 run 当时无法关闭 Stage 1；第 11 节的新 provenance-consistent binary 后来完成了唯一要求的一次动态验证。

## 10. 下一轮一次联合验证的准入与判据（已满足）

需要重新 build 的原因：R_IC/Core/Tile 的新统计 ownership 连接、LSU/DCache/checker instrumentation 和 emulator/header 都必须进入同一新 generated model/binary；旧 executable 不包含这些修改。软件已独立准备，无需用旧 ELF 或旧 simulator 混合验证。

用户随后执行了一次 `stage1_build_and_run.sh`，创建新 build/run，校验软件与硬件来源并只调用一个 simulator；结果见第 11 节。

自动 closure 必须同时满足：

- build/run provenance 及 ELF identity PASS；sim 正常 serial_success，软件 verified=1、END PASS、package 的实际 allocated/completed/passed 平衡且没有 failed/cancelled/dropped。
- AMO.W 两 lane 出现、四个 directed 语义/最终 array PASS，ARCH_ERROR/AMO_ERROR=0。
- main/checker 六 counters 和 occurrence 集全部相等；MAIN_ONLY/CHECKER_ONLY/DUP_IN_MAIN/DUP_IN_CHECKER 均 0；新 checker hart/ordinal 提供独立 duplicate identity。
- clear runtime invariants、owner/epoch/refill beat 检查无错；实际 overlap 输出数量；为零的场景继续明确 NOT_OBSERVED，不能伪造覆盖。
- EFFECT/TERMINAL/STORE_DONE/RELEASE exactly-once、顺序与数据一致；无 duplicate/lost effect、无 replay unclosed、无 killed effect。
- host success 后实际 L1/LSU quiescent；EXIT_REAL_OUTSTANDING=0，finite exit 不遗留 committed STQ 工作；保留超时/非零退出诊断。
- 同一次 run 中全部 gates PASS，才可改为 STAGE1_STATUS=CLOSED。

一次联合运行足以给出结论的依据已经得到动态确认：329 条漏计修复后 occurrence/counter 全相等，有限 exit 后真实 drain 归零，且同 workload 的 AMO、clear 和生命周期 gates 全部通过。

## 11. Final validation closure

最新 run 是 `AI/TMP/stage1_closure_run_g3Y7Oi9x`；没有启动第二次仿真。run 内 provenance 重新核验为 PASS（11478 source files、3003 generated files），simulator SHA256 为 `5a38407bb123859499c26ba96a551384d567cb59e0ad66535dbf25d30a30f5a1`，workload ELF SHA256 为 `64d450b7288198d7ba0b317221914ffe7930d9223ef4868e66bda691386a3ce3`，analyzer 副本与当前 analyzer SHA256 均为 `47e9ee115fcf41afd38ab768f8c6f68ac13edebfc802da2aee6d05e4553dc53b`。trace SHA256 为 `a838739c4240e3cd8df3dd20875b0a6633f082c64bb5fa378347b237edd9fa87`，FST SHA256 为 `85c6917e8a6d5dce11e96fe6cd403e7d56057f132d3139cc689a9c075627c97e`。

软件输出为 `gapbs_bfs nodes=512 reached=512 edges=8192 verified=1`，`[VERIFY] packages allocated=334 completed=334 passed=334`，`[END] hart=0 status=PASS`；模拟器为 `STAGE1_SIM_EXIT reason=serial_success ... cycles=5456589`。

```ini
PROVENANCE=PASS
SIM_EXIT=SUCCESS
STAGE1_TRACE=PASS
STAGE1_STATUS=CLOSED
NEXT_SIM_REQUIRED=NO
```

最终九项状态：

| 项目 | 最终状态 | 关键证据 |
|---|---|---|
| architectural data/error | PASS | `verified=1`、`ARCH_ERROR=0`、software `[END] status=PASS` |
| AMO.W | PASS | low/high lane 均见；`AMO_LOW_LANE_SEEN=1`、`AMO_HIGH_LANE_SEEN=1`、`AMO_ERROR=0` |
| main/checker | PASS | six counters 完全相等，occurrence sets 全空 |
| clear/S1/S2/refill | PASS | `CLEAR_RACE_VIOLATION=0`，clear/check/install/refill owner/epoch 检查无错 |
| effect → terminal | PASS | `EFFECT_WITHOUT_TERMINAL=0`、effect/terminal 数据与顺序检查无错 |
| terminal → STQ release | PASS | `TERMINAL_WITHOUT_STQ_RELEASE=0`、`DUP_STQ_RELEASE=0` |
| duplicate effect | PASS | `DUP_EFFECT=0` |
| lost effect | PASS | `LOST_EFFECT=0`，`COMMITTED_OR_GRANTED_WITHOUT_TERMINAL=0` |
| exit outstanding | PASS | `EXIT_REAL_OUTSTANDING=0`，DCACHE/LSU snapshot 均归零、`fence_ready=1` |

最终关键计数：

```text
ARCH_ERROR=0
AMO_LOW_LANE_SEEN=1
AMO_HIGH_LANE_SEEN=1
AMO_ERROR=0
MAIN_STORE_COUNT=60567
CHECKER_STORE_COUNT=60567
MAIN_LOAD_COUNT=95039
CHECKER_LOAD_COUNT=95039
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
REPLAY_UNCLOSED=0
```

最终 scoreboard 的全部 gates（effect/terminal、terminal/release、duplicate/lost effect、AMO.W、architectural data、clear、main/checker、exit、replay、software report）均为 PASS，`errors={}`。实际事件包括 `BOOM_STAT=311212`、`CHECKER_STAT=155606`、`ARCH_STORE=144386`、`EFFECT=144249`、`TERMINAL=144308`、`STORE_DONE=144308`、`RELEASE=144386`、`CLEAR=185`、`CLEAR_CHECK=186`、`INSTALL=8308`、`REFILL=32604`、`REPLAY_GRANT=8295`、`REPLAY_RESULT=8295`；59 个 MMIO terminal 无 array effect，按既有 analyzer 规则分类。退出快照为 DCACHE active/memory/replay/completion/TL 状态全 0 且 `fence_ready=1`，LSU 的 STQ/LDQ/inflight/pending/request/force_order 全 0。

非阻塞观察项：`clear_refill=0`、`refill_effect=0`、`s1_replay_killed=0`、`s2_replay_killed=0` 是本 workload 的实际未观察场景，不是错误或伪造 PASS；它们仍由 analyzer 保持 coverage 记录。Stage 1 的既定 closure 条件不要求为零的交叉场景全部出现，因此不阻塞进入下一阶段。
