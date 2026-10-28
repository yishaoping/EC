# Current Debug State

## Opt3 design and Git delivery prepared (2026-10-28)

Detailed frontend mechanism, ownership guards, clock domain, measured results,
cumulative source dependencies and user-run reproduction commands are recorded
in [Opt3 design](../../Design/opt3_checker_frontend_optimization_20261028.md).
The release preserves the exact hardware bytes of the successful Opt3 run:
source digest `dece4a35a99eb0c2ed30fb917a9f8946e9d8d53a48d7f99c36e51f15a15e1fae`.
The commit includes required Opt1/Opt2/Opt2b prerequisites and both observer
resources; it does not include local build/run/cache/tmp artifacts or unrelated
paper edits. Existing run directories, manifests and attempt guards are retained.

Release-only tooling changes correct Opt3-vs-Opt2b performance labels, validate
kind16 partitions/monotonicity, recreate missing empty output directories, and
allow `--repeat-from RUN_ID` only for the latest successful complete attempt with
the same hardware/workload identity. The default still refuses another attempt;
failed/incomplete runs cannot be bypassed. Sixteen offline regression tests,
source contracts and the static entry check passed. Offline replay of the saved
Opt3 compact trace reproduces ROI 2,928,347, 22.123464% gain vs Opt2b, COMPLETE
coverage, OBSERVED_CHECKS_PASS and 630,932 fused classifications.
The analyzer uses a versioned small summary snapshot with the original file hash
instead of requiring an untracked historical safe-chain run directory.

No new hardware generation, SBT/Scala/native/software compilation, simulation,
or benchmark is part of this release. Full drain, RUN_PROVENANCE, failure/probe
recovery and timing closure remain unresolved as described below. User command:
`bash slowdown/run_optimization_3_checker.sh --repeat-from optimization_3_checker_20261028_090640_a56794e2`.

## Opt3 measured: successful, 22.12% ROI reduction vs Opt2b (2026-10-28)

User run `optimization_3_checker_20261028_090640_a56794e2` finished with exit0/SUCCEEDED,
ROI 2,928,347 main cycles. Reduction vs Opt2b: 831,896 (22.123464%);
vs original Current: 1,806,534 (38.153736%). Baseline ratio 2.923450x.
GAPBS512 verified/checksum43439728, 315 accepted checker results,
FAIL/CANCEL/stale/held-duplicate/collision0; Stage1 L1/LSU exit drain PASS.
71-observer coverage COMPLETE; 127,466 events + 71 footers, 39,029,794 bytes,
no overflow/truncation. Independent read, hashes, kind16 conservation and
run/preparation/current-source identity match.

630,932 fused classifications; separate CLASSIFY counter zero (Opt2b 630,955).
Instruction wait 1,980,533 -> 1,346,930 local cycles; aggregate mean package
latency 23,083.33 -> 17,792.74 main cycles. Strict unsafe WaitSafe
2,296,540 -> 1,547,483; after-seal-before-done pending 2,098,732 -> 1,407,280.
312 vs 324 complete ROI package windows: aggregate, not matched causal savings.
Remaining instruction wait is 48.53% overall and 67.64% post-seal.
Full package/cache/DRAM durable drain and RUN_PROVENANCE remain unresolved;
PASS workload does not exercise failure/probe recovery.

Raw opt3_summary keeps old performance field names/comparison against Opt2.
Explicit corrected Opt3-vs-Opt2b numbers and evidence boundary:
[Opt3 results](../../TMP/opt3_results_20261028_122909_092f25bb/README.md).
Current status: **OPT3_MEASURED_MEANINGFUL_GAIN**. No new hardware run or
source change in this results analysis. Earlier runtime-pending notes below
are historical and superseded.

## Opt2b attributed; Opt3 checker patch ready for user-run validation (2026-10-28)

The first Opt3 launcher attempt stopped before build with a private SBT socket
path of 110 bytes. This was a launcher path-length guard, not an RTL/SBT
failure. `launch_optimization_3_checker.py` now allocates a one-character
private temporary leaf under `optimization_3_checker/tmp`; the socket path is
102 bytes and remains inside the sandbox. Static check and offline contracts
pass after the fix.

Opt2b GAPBS512 completed successfully with checksum `43439728` and ROI
`3,760,243` main cycles. This is `947,030` cycles (`20.118442%`) below Opt2
and `974,638` (`20.584213%`) below the original current run. Compact evidence
was complete: 67 Opt2b observers, 325 accepted results, no FAIL/CANCEL/stale/
duplicate/collision, and no event overflow or truncation. Full package/cache/
DRAM drain and `RUN_PROVENANCE` remain unresolved; the PASS workload does not
exercise failure recovery/probe behavior.

Checker attribution is now closed enough for one functional choice. Owned
checker execution consumed 3,739,176 local cycles; `WAIT_INSTRUCTION` was
1,980,533 (52.9671%), and sealed-to-done instruction wait was 1,285,131 of
1,708,940 (75.2005%). The four checker mean/p95 main-cycle latencies are
23032.22/48140, 22786.33/47632, 22406.12/45036, and 24126.88/48750.
Strict same-line cross-package Store preservation exposure is 2,296,726 main
cycles across 186 timed episodes/92 lines, but SVB depth and occupancy are not
observable in the serialized trace. SVB recovery remains open for P1 PASS/P2
FAIL, so no SVB RTL was added.

The selected and implemented next change is `CHECKER_FRONTEND_BOUND`:
accepted S2 response capture and CFI classification are fused in
`rocket/Frontend.scala`, removing the mandatory classifier state. The patch
retains one response owner, FQ hold semantics, BJL reservation only in
`WAIT_BJL`, redirect/clear handling, and held partial-RVC tail state. Kind16
four-hart cumulative classification observers and assertions were added.
Static source identity, resource closure, Python syntax, and offline contracts
pass. No Scala/SBT compile, hardware generation, Verilator build, simulation,
or benchmark was run. User entry:
`bash /data1/gzh/EC/slowdown/run_optimization_3_checker.sh`.

Status: **READY_TO_RUN_CHECKER_OPT3** (static delivery only; dynamic gain and
correctness remain pending).

## Opt2 measured; Opt2b checker handoff prepared, user run pending (2026-10-27)

This supersedes the older Opt2-runtime-pending status below. Successful user
run `optimization_2_20261027_144838_fdf571b7` exited 0, GAPBS512 verified,
checksum 43439728, ROI 4,707,273 main cycles. Opt1 was 4,706,513: +760,
essentially unchanged; Baseline 1,001,675. Opt2 allocation 82/85/82/82 is
balanced, but package count balance did not shorten checker service time.
331 results accepted; FAIL/CANCEL/collision/stale/duplicate 0. Its 53-observer
compact evidence is COMPLETE. Stage1 L1/LSU exit drain passed; full
package/cache/DRAM drain and RUN_PROVENANCE remain unresolved.

Observed same-line preservation pending is 3,241,793 main cycles; strict
unsafe 3,162,560. Unformed-result wait is 3,019,697 (93.149% of pending),
including 2,897,079 after producer seal but before exec_done. Per-package
done-to-formed is 68 main cycles; result CDC about 4. These are blocking
stages, not additive avoidable ROI loss. Opt2 ROB-critical overlap is not
observed. Old Opt1 counters/ROB overlap are kept separately, not transplanted.

Packages stream before seal: all 331 assignments precede seal. Mean
assign-to-admit is 14.93 main cycles; admit-to-done 28,893.46, p95 74,940.
Old first-active is a sampled proxy, not accepted start/issue. 650,116 checked
instructions, 49..4,999/package, weighted main CPI 14.7108 (about 7.3554 local;
one checker cycle is two main cycles). Instruction/latency correlation .9186;
top10 latency packages associate with only 7.301% of strict unsafe wait.
Broad execution cost is supported; internal dominant stall remains unknown.

SVB is NOT implemented. Capacity/depth coverage for 2/3/4 total versions and
2/4/8/16 global entries is null: serial traces hide never-issued younger
Stores. The loose opportunity upper bound is 3,162,560 waiting cycles,
not ROI gain or a capacity prediction. Concrete correctness no-go:
L2=P0 safe / SVB=P1 / L1=P2; P1 PASS then P2 FAIL must restore P1, but
current recovery lacks an SVB newest-safe selector. Existing WB reads live
L1 and uses voluntary T-to-N plus metadata clear; publishing P1 while
retaining P2 needs additional ownership/directory/ACK semantics. Sticky
failure/fail-closed is not rollback data restoration. Pre-allocation WaitSafe
fallback cannot solve failure/probe after snapshot.

The ONE functional Opt2b is Frontend same-cycle accepted FQ response to
resolved successor Icache request handoff, avoiding the fixed EMPTY issue
bubble. It saves at most one local issue cycle per eligible chunk; it does
not prove ROI gain or explain all 2.897M wait. Held response, fault/replay,
redirect, BJL resolution and sole-owner conditions remain guarded. Opt1,
Opt2 round robin and other existing dirty changes/deletions are preserved.
RocketCore and DCache additions are observation-only: per-owned-package
local priority stall counters/timestamps, sparse Frontend cumulative counts,
semantic cache writes/first blocks without cacheline bytes. 67 expected
observer instances. No new functional cache, result, watermark or CDC path.

Status: **READY_TO_RUN_OPT2B_CHECKER** means static delivery ready only.
19 offline synthetic/contract tests and the launcher's pure static identity,
path/resource checks passed (27 source files, 26 dependency projects).
Source digest: ea894cdb25f72aa1c9b818f68d33e085089919b27c2a8d3bb7a8127a2d732618.
Scala compilation, elaboration, RTL generation, native/software compilation,
Verilator, simulation and benchmark are NOT_EXECUTED in this task.

User-only entry (one fresh full GAPBS512, seed1; no FST/VCD/automatic retry):

```bash
bash /data1/gzh/EC/slowdown/run_optimization_2b.sh
```

Reports (13), incremental three-file patch, existing evidence statistics,
validation/provenance and retained synthetic fixtures:
[Opt2b delivery](../../TMP/opt2b_checker_and_multiversion_20261027_184537_3891819a/README.md).
The next run measures the functional handoff and internal checker categories
together; observed local post-seal counters are not an exact causal weighted
partition of the old 2.897M main-cycle wait. Dynamic correctness/performance,
full drain/provenance and SVB recovery remain unresolved.

## Safe-chain result-production bottleneck; Opt2 ready for user-run validation (2026-10-27)

This supersedes the older repaired-runtime-pending notes below. Successful
safe_chain_20261026_141031_5b330641 exited 0 with GAPBS512 verified/checksum
43439728 and ROI 4,706,513 main cycles. Its compact TSV is 12,633,982 bytes,
41,337 SC1 rows plus 53 observer footers, coverage COMPLETE, below all caps.
The router discarded seven nonmatching diagnostic lines (540 bytes); required
ROI/workload/host-success/L1-LSU drain markers are retained. Stage1 L1/LSU
exit drain PASS does not close full cache/package/DRAM drain or RUN_PROVENANCE.

Offline replay reproduces the saved summary exactly. Decision is
OPT2_TARGET_CHECKER_RESULT_LATENCY. All pending: 3,178,984 cycles / 1,152
entries; strictly unsafe WaitSafe: 3,100,681. Exclusive breakdown: unformed
result 2,993,080; formed-result transfer 3,720; prefix hole 87,361; registered
watermark propagation 178; post-safe release 78,275; multi-cause 16,370;
unresolved pending classification 0. Of unformed-result wait, 2,981,282 is
before exec_done, including 2,867,231 after producer seal. The dominant
waiting stage is proven; scheduling alone causing all that wait is not.

Maximum allocated missing-frontier lifetime is 50,424 (seq112, no later PASS
held behind); maximum actual later-PASS blocking is 12,772 (hole320); peak
single-hole amplification is three later PASS. Commit-ready opportunities,
per-MSHR lifetimes and exact causal/avoidable ROI cost are not continuously
observed. Remaining delta 3,704,838 minus pending gives arithmetic remainder
525,854, not proven independent lost cycles. R_IC does not consume L1 safe
watermark; result release is the common upstream of gate and safety branches.

Existing Opt2 functional delta is only ght_sch.scala and R_IC.scala:
availability-aware round-robin advance on actual package allocation, with
existing first-available fallback when a target becomes busy. Ownership,
admission, safe prefix, result CDC, cache preservation and Opt1 stay intact.
Observed checker assignments 97/94/91/50 and static low-index priority support
the policy experiment, but do not establish its isolated performance benefit
or perfect fairness. No RTL was changed in this continuation.

Prior optimization_2_20261026_202323_9020fd02 completed verilog/default builds
and observer audits, then failed before simulator Popen with missing
compact_capture. It did not run the Opt2 workload. The dependency is now
provided and checked before build/attempt guards. Explicit --resume-built-run
permits one simulation using only that verified existing build; checks old
failure/no simulation artifacts, source/software/executable/model identities,
observer hierarchy and unique guard. Old guard/manifest/build are preserved;
a new durable guard prevents any second attempt. No automatic retry.

READY_TO_RUN_OPTIMIZATION_2 means static implementation/launch/analysis ready;
Opt2 dynamic correctness and ROI gain are PENDING. All 18 mock/file tests,
Python AST, shell/diff, source/old-evidence identity, phase conservation and
actual saved-model static audits PASS. No simulation, hardware generation,
SBT, native/software/hardware compilation or benchmark was executed in this
continuation. User alone runs the dynamic command:

```bash
cd /data1/gzh/EC
./slowdown/run_optimization_2.sh \
  --resume-built-run optimization_2_20261026_202323_9020fd02
```

Reports (16), minimal patch, launcher entry, snapshots and evidence hashes:
[Opt2 final delivery](../../TMP/opt2_rootcause_final_20261026_f3d927c1/README.md).
Exact downstream commit/MSHR/set-collateral/replay metrics remain explicitly
UNOBSERVED/null in the new analyzer; no additional observation run is proposed.

## Safe-chain boot observer overflow fixed; repaired runtime pending (2026-10-26)

DIRECT_EVIDENCE: user run safe_chain_20261026_114110_076b64d2 completed
RTL generation and Verilator build (both return code 0), then failed with
SAFE_CHAIN_OBSERVER_OVERFLOW before software ROI. Its 50,000 TSV records
are exclusively KIND=10/hart=0/RESET=1, cycles 0..49,999; no START, ROI or
SC_END. The old boundary logger had ROI=true, level-sensitive RESET/START
sample and force_event=true. Boot-held RESET therefore exhausted its budget.
This supersedes older notes below saying no safe-chain simulation had started.

The repair changes RESET/START boundary logging to rising edges using two
logger-only RegNext registers. STOP uses its existing pulse. No functional
cache, Opt1, watermark, protection, statistics or workload logic changes;
no Opt2 functionality. Per-observer and byte budgets remain unchanged.
Capture retains the exact overflow observer identity, exit code and byte/count
statistics; a secondary close error no longer masks the first failure.

Old evidence and guards remain immutable. Default launcher still refuses
another simulation. A user-only explicit replacement for this known pre-ROI
failure is prepared with --retry-observer-overflow
safe_chain_20261026_114110_076b64d2. It requires a different source identity,
validates the complete old RESET prefix, and permits no further replacement
after the replacement simulation starts. No automatic retry or guard deletion.

Validation: all 35 offline tests and static identity/resource/AST/JSON/bash/diff
checks passed. The original failed run hashes, HEAD and index are preserved.
Validation in this repair is offline synthetic/static only; no Scala/native
compilation, elaboration, RTL generation, workload or simulation. Existing
generated RTL belongs to the failed old source, not the edge-logging repair.
Runtime completeness, Opt2 attribution, ROB critical-path impact,
RUN_PROVENANCE and full cache/package/DRAM drain remain UNRESOLVED.

Evidence: AI/TMP/safe_chain_boundary_overflow_fix_20261026_abd48b5a/.
User entry: slowdown/run_safe_chain_trace.sh (explicit recovery option above).

## Safe-chain generation errors fixed; hierarchy audit rechecked offline (2026-10-26)

DIRECT_EVIDENCE: existing RTL-only run safe_chain_rtl_20261026_090815_3f50a7ca
completed its make verilog command with return code 0. Its final FAILED status
came from the old observer audit counting KIND text in module definitions.
One deduplicated Rocket definition contains KIND=6; four checker Rocket
instances give four KIND=6 observers. The prior explanation calling KIND=6
a single main-core observer was incorrect and is superseded by this evidence.

The audit now joins the full TestHarness instance hierarchy to KIND parameters
in each parent's emitted RTL. Exact counts remain 53 total, with four each
for KIND=3/4/5/6 and 32 for KIND=9. Missing checkers, unreachable definition
decoys, duplicate hierarchy paths, unavailable hierarchy, mismatched RTL and
output-bearing logger resources are rejected. Existing generated RTL passes
offline re-audit; all 21 recorded source hashes match current preparation
(source digest 4dd7c81e158619d10778d13e36a9fd8615fb43985e42ca88fe03abb2f1bc1c4d).

Earlier Bool padding, unknown-width getWidth, and whole-IO dontTouch failures
are addressed by the existing fixed UInt observation sinks and removal of the
unnecessary annotation. No hardware source was changed in this continuation.
The observation-only review patch was reconstructed in memory from the saved
pre-observation delta; 17 prior Opt1 input hashes and all marked source
boundaries match. Its stale top-level hash is now checked by identity preflight.

The later RTL-only run safe_chain_rtl_20261026_094812_33ad715f has no visible
live process, no final return code and a stale IN_PROGRESS manifest. It is
incomplete evidence, not a passing run. Original manifests/logs are retained.
No new generation, Verilator build, workload or simulation was started in
this continuation. User-only entry: slowdown/run_safe_chain_trace.sh.
Runtime correctness, Opt2 attribution, RUN_PROVENANCE and full cache/package/
DRAM drain remain UNRESOLVED. No Opt2 functionality or Git index change.

Evidence: AI/TMP/safe_chain_error_fix_20261026_0b61333e/.

## Safe-chain compact observation prepared; new run NOT executed (2026-10-25)

Current + Opt1 now has OBSERVATION_ONLY safe-chain instrumentation. No Opt2
functional change is included. Source fingerprint:
912e879e81823ee4541a8074f7f23f4f8556e6286764a04301925b9de3502ba7.
The earlier Opt1 user run optimization_1_20261025_123241_e7c5f139 succeeded:
ROI 4,706,513 cycles versus Original Current 4,734,881 and Baseline 1,001,675;
observed improvement is 28,368 cycles (0.599128%). Older dynamic-not-run notes
below are history for their original preparation states.

User-only entry: /data1/gzh/EC/slowdown/run_safe_chain_trace.sh.
No launcher mode, SBT, elaboration, hardware/software/native compilation or
simulation was executed in this preparation. Normal nontrace Verilator build;
no full FST/VCD, no +verbose. The logger routes event rows through stderr apart
from byte-stream UART stdout into one bounded TSV (96 MiB); diagnostic logs
are capped at 8 MiB each. It captures traffic START through exit, then clips
by unchanged software rdcycle ROI. 53 observer count/episode/footer checks,
exact-tag checkpoint, main-clock time alignment and one-attempt guard prevent
silent partial attribution or automatic expensive retries.

Offline synthetic checks: 19 passed. Static source review confirms existing
Opt1 functional code is unchanged outside marked observation blocks; generated
RTL/compiler/runtime behavior remains unverified. Analysis classifies result
formation/mandatory cleanup/CDC/L1 acceptance separately from prefix holes,
registered watermark propagation and post-safe release. Decision remains
ROOT_CAUSE_STILL_UNRESOLVED until complete future evidence. Activity is not
ROB critical-path loss, avoidable cycles or a mechanism slowdown estimate.
RUN_PROVENANCE and full cache/package/DRAM drain remain UNRESOLVED.

Reports: AI/TMP/safe_chain_targeted_trace_20261025_baab7979/.
Sealed launcher/schema/source/resource inputs: slowdown/safe_chain/manifests/.
Original evidence, user deletion docs/paper_design_reference.typ, untracked
DOC/Figure and the Git index are preserved. No staging/commit/push/cleanup.

## Optimization 1 trace gate remediation; dynamic validation not run (2026-10-25)

The user-run attempt `optimization_1_20261025_083906_1d2467bb` completed RTL
generation but intentionally stopped before Verilator build when the generated
RTL trace gate reported missing aliases. Source-to-generated review separated
the report into 13 false negatives from CIRCT instance flattening
(`ghm_slowdown_opt1_*`) and seven actual DCache direct aliases that disappeared
before emitted FIRRTL. The seven probes now use observation-only `WireInit`
aliases before `dontTouch`; generated RTL and compiled-trace audits now match a
complete flattened leaf with only an optional numeric Vec suffix. The previous
failed build/run evidence is retained. The repair passed 16 synthetic
parser/contract/ledger tests, Python AST, JSON, bash syntax, and diff checks.
The repaired source has not been regenerated, built, or simulated.

## Optimization 1 candidate prepared; dynamic validation not run (2026-10-24)

Decision: `IMPLEMENT_SET_FREEZE_OPTIMIZATION_FIRST`. One functional DCache
change admits qualified ordinary different-tag loads to hit-only lookup during
unsafe WaitSafe; misses nack with MSHR valid/fire suppressed. Existing snapshot
drain, watermark, ACK, barrier and recovery conditions remain. GHM, R_IC and
InclusiveCache changes are observation aliases only. This candidate has NOT
been elaborated, compiled or simulated; the sealed Stage 3 results below apply
to their original source/run, not to these new source bytes.

Design/evidence: `AI/TMP/low_sim_optimization_plan_20261024_e5076be7/` and
`slowdown/optimization_1/analysis/design/`. Persistent preparation and static
checks: `slowdown/optimization_1/manifests/`. User-only Verilator entry:
`/data1/gzh/EC/slowdown/run_optimization_1.sh`. No launcher mode was executed
in this preparation. `RUN_PROVENANCE=UNRESOLVED` and full package/cache/DRAM
drain remain unresolved. Complete offline analysis of the first run before
considering another hardware version.

## Stage 3 closure evidence reviewed (2026-10-21)

The sealed run `AI/TMP/stage3_runs/run_qx63gyhc/` passed the final evidence
review. HEAD, 11,480 source hashes, four Stage 3 script hashes, 40 workload
source hashes, 3,077 generated model files, simulator identity, phase seals and
upstream tokens all match. BUILD/DIRECTED/SYSTEM are PASS; all 19 directed CASE
markers are unique and PASS, with one `[END] status=PASS` and zero preservation
correctness errors. System Stage 1, Stage 2 and Stage 3 scoreboards, progress,
software report and exit drain are all PASS. The metadata-clear witness now has
`PRESERVE_DONE -> CLEAR_CHECK fire=1` with all S1/S2 and conflict fields zero,
followed by EFFECT, TERMINAL and RELEASE; the prior watchdog path is absent.

```ini
STAGE3_DYNAMIC_VALIDATION=PASS
STAGE1_REGRESSION=NONE
STAGE2_REGRESSION=NONE
STAGE3_INVARIANTS=PASS
ALL_DIRECTED_CASES=PASS
OUTSTANDING_TRANSACTIONS=NONE
STAGE3_STATUS=CLOSED
STAGE3_CLOSURE=YES
NEXT_ACTION=MAINTAIN_STAGE3_CLOSED_STATUS
```

The original run summary remains an immutable pre-review record with
`STAGE3_CLOSURE=NO`. Full checklist, fields and independent provenance audit:
[Stage 3 closure evidence review](../history/reports/stage3_closure_evidence_20261021.md)
and `AI/TMP/stage3_closure_review_20261021_bjm5zr2m/`.

## 最新终端错误：workload符号表解析已修复，等待重跑（2026-10-20）

用户run_jp4_qkjb停在software manifest preparation，未进入hardware build/directed/system。
根因是上轮新增size读取把GNU objdump符号的可选`.hidden`当作十六进制size；实际新ELF
stage1_workload_2Raas2GM已编译，timer_flags为aligned64/size256，控制域布局没有失败。
stage1_workload.py统一解析size与visibility，_exit范围也复用解析结果；新增3项offline
parser回归覆盖default/hidden/protected/internal、flag变体与坏size拒绝。实际ELF261符号
（含5个hidden）、源码snapshot、AMO/HTIF/_exit/LOAD头只读检查PASS；Python/shell/diff PASS。
本轮未准备/转换软件、build、生成、仿真或执行runner；未改C/Scala/harness和任何协议。
旧失败run与manifest保留；仍使用同一Stage3单入口自动准备变更软件并重新验证。
STATIC_REVIEW=PASS；READY_FOR_DYNAMIC_VALIDATION=YES；STAGE3_CLOSURE=NO。
详见 [符号visibility解析RCA与验证](../history/reports/stage3_workload_symbol_parser_20261020.md)。

## 当前：Stage 3 timer/trap validation 环已定位并以控制数据隔离切断（2026-10-20）

原布局的条件环已确认 REACHABLE：旧 run_zr8umvan 的 hart2 完成 seq2 PASS 后，
result queue 仍 valid1/ready0；timer trap(mcause=0x8000000000000007)阻止 context_idle。
handler PC800006bc 读取 timer_flags[2]=80007e48，与 BOOM timer_flags[0] 的
unsafe writer0/genb920/seq2 共用 line80007e40，watermark1。当前新 gate 若应用到
该状态，会使 handler 等 seq2 validation，而 retained PASS 的 handoff 又等 handler xRET。
不是“checker尚未算出PASS”，也不能以 close ACK 或释放MSHR代替validation。

最小修复仅2个生产C/header文件：timer counter 改为每hart独占、对齐64B的完整block，
保持原计数/中断/CSR行为。handler其他物理访问为private管理栈和CLINT MMIO；RSUSL/
RocketCore原有异常SP/GP恢复保证local trap使用管理栈，replay内存访问仍由LSL服务。
BOOT BSS初始化在seq0；BOOM后续只写slot0，因此Rocket的slot1..3不带BOOM unsafe key。
未修改任何Scala/hardware、CacheImage、Rocket、L2 gate、validation或preservation逻辑。

2个必要provenance脚本增量：stage1_workload检查实际ELF timer_flags对齐64/大小256并
记录domain；Stage3原单入口在用户下次执行时自动准备已变更软件，保留旧manifest，
之后再capture/验证输入。旧ELF/旧system结果不能替代新软件证据；本轮没有执行准备。

STATIC_REVIEW=PASS；KNOWN_DEADLOCK_CYCLES=NONE（本轮已知timer unsafe-transfer环）；
READY_FOR_DYNAMIC_VALIDATION=YES；STAGE3_STATUS=PATCHED_PENDING_REBUILD；STAGE3_CLOSURE=NO。
RISC-V C syntax-only、Python AST、shell syntax、mock-only provenance与git diff检查PASS；
1463个Scala源码hash逐项未变，directed fixture未变。未build、typecheck、生成、Verilator、
simulation或runner。该静态排除针对当前v1Config/Test timer路径，不冒充任意软件/全局fairness证明。
详见 [具体wait graph、地址域、修复与边界](../history/reports/stage3_timer_control_domain_20261020.md)。
证据/本轮preimages：`AI/TMP/stage3_timer_wait_ecs_zsrg/`；全部旧run保留。

## 历史：Stage 3 收缩为 lineage-unaware Rocket；L2 gate 已实现，系统 progress 当时未闭合（2026-10-20）

架构固定为 BLOCK_SPECULATIVE_TRANSFER_TO_LINEAGE_UNAWARE_ROCKET。精确撤回 Rocket
DCache/HellaCache 上轮 CacheImage 功能扩展，两文件与扩展前副本一致；BOOM 恢复本地
imageSerial，保留 CacheImage/同包与 preservation 语义，只新增 coherent endpoint marker。
L2 使用 marker+真实 remapped source range 分类，默认未知 client unaware。在 MSHR/
Scheduler->SourceD 阻止 unsafe Get/Acquire/old-value AMO response，停放原 request/seq，
释放 MSHR/set/D 资源；晚发现 ProbeAckData unsafe 时先完成 C/E/bank tail、仅提交 probe
ownership 变化。validation 后空闲 set 重新 allocation/lookup，禁止复用旧 directory snapshot。
独立 client wait 使用已有 package-close 请求，但 peer-only wait 不冻结 SourceC。

替换旧 coherent_peer_lineage_roundtrip 为 lineage_unaware_peer_waits_validation；严格
19/19，原18项保留，覆盖早/晚park、同set BOOM、other-set preservation/ACK、验证后
fresh retry、普通BASE Release/ProbeAckData。fixture主动注入watermark，不证明system进展。

静态语法/scope/table检查 PASS（原9状态/72行及assertion helper未改，18 allowed/54 forbidden、
6 flush edges），未运行任何 hardware build、Scala typecheck、RTL生成、Verilator、runner或simulation。
完整 STATIC_REVIEW=FAIL：尚不能排除 runtime timer handler 等 safe Grant -> validation 等
checker -> checker context_idle 等 trap xRET -> handler 的条件等待环。源码证明这些依赖存在，
旧run证明shared timer行曾被unsafe交给普通Rocket；新排序下是否阻塞负责该seq/更早seq的checker
尚未证明。释放L2资源/package close ACK不能替代PASS或抹掉这个缺口。

READY_FOR_DYNAMIC_VALIDATION=NO；STAGE3_STATUS=STATIC_PROGRESS_REVIEW_UNRESOLVED；
STAGE3_CLOSURE=NO。生产8文件（其中2个仅撤回），无新增Rocket store/AMO/generation功能。
详见 [收缩架构、完整静态审计及剩余progress阻塞](../history/reports/stage3_lineage_unaware_boundary_20261020.md)。
证据 `AI/TMP/stage3_unaware_boundary_5be1nixk/`；旧run/报告/preimages均保留。

## 历史（已被下述收缩架构取代）：Stage 3 provenance-aware Rocket 提案（2026-10-20）

用户最新 `run_zr8umvan` 的 BUILD/DIRECTED 已 PASS，SYSTEM 因 little core2
watchdog FAIL；不是已观测错误 data。error_samples 为空、重复/过早 release 错误为0，
Stage2 checker PASS，checkpoint105/105、victim807/807闭合；15个缺 effect token
仍属于 abort 时 outstanding，不能宣称永久丢失。未单独修改 MAIN_CHECKER/EXIT 项。

三方同 workload event/FST 比较：旧 d223 的 reference first bad=b90dc；当前更早
cec7/PC80000844/addr80056184未完成。直接 causal line=80007e40（timer_flags），
FST1460779 对应 DCache cycle=b24af，较旧 reference 早27693周期。
`PREVIOUS_FIX_EFFECTIVE=PARTIAL`，旧失败点未跨过、system进度未推进。当前生成
Scheduler已含上一轮双C路径same-package bypass，并有6次真实newer-generation
supersede，但 ordinary Rocket返回BASE key，使resident writer0/seq2/genb920在
watermark1下被probeNeedsGate阻塞。源source28/hart1的dirty ProbeAckData等待validation；
source24/hart2的Acquire不能完成，共享C进而卡住BOOM writeback、set86 installDrain，
MSHR3已收到Grant但cec7无法install/effect/terminal/release。baseline同PC/addr成功，
旧run cec7也成功，当前不是d223复发。

本轮实现blocking coherent Rocket的C/D CacheImage协商、slot key安装/实际buffered
store更新/双C路径返回，普通修改继承imported lineage及validation debt并取更大gen；
BOOM同lineage重新取得ownership后跳过peer已使用gen。CacheImage helper统一
writer+seq package定义；L1入场补writer比较，L2两条C路径共用supersede helper。
精确current receipt仍在key改变时撤销，不能继承成outer权限。新增有限peer/probe日志。
MSHR/Directory/L2Preservation/SourceA/C/D/SinkC/D/CacheCork/InclusiveCache本轮功能不变。

新增协议CASE `coherent_peer_lineage_roundtrip`，覆盖unsafe Grant->普通peer连续
变更->ReleaseData/ProbeAckData->validation前无outer写->验证后durable flush；原18项
保留，runner/checker清单改为严格19/19。它验证生产helper和L2管线，不实例化整个Rocket
DCache，slot/refill/store wiring仍待system。源/fixture identity变化使旧BUILD与下游失效。

STATIC_REVIEW=PASS；9状态/原断言表及19 CASE映射、Python/shell语法、Scala parser-only、
C++声明桩syntax、assignment/handshake/receipt review及git diff --check通过。
未执行Scala类型编译、elaboration、RTL生成、Verilator、模型编译链接、runner或simulation。
`STAGE3_STATUS=PATCHED_PENDING_REBUILD`，`STAGE3_CLOSURE=NO`；Stage2/3 invariant静态保留，
所有Stage3 blocker清单已审查，未发现其他有证据的等待环，不等于动态closure证明。
证据 `AI/TMP/stage3_system_closure_audit_bo5r1ef7/`，旧run与预存改动保留。
详见 [system closure审计与coherent peer根因](../history/reports/stage3_system_lineage_closure_audit_20261020.md)。

## 当前：Stage 3 CASE 10 cleanup 缺失 inner ownership release，静态修复待重建（2026-10-20）

用户 run `AI/TMP/stage3_runs/run_igda2knt/` 的 CASE 10 主体已经完成并打印 PASS：
同包 gen=4/seq=2 ReleaseData 在不新增 preservation Put 的前提下完成 bank commit，
随后 Get 返回新 key/data。失败发生在 cleanup flush：flush 已接受，MSHR lookup 命中
dirty TRUNK、clients=1 的 resident，向唯一 coherent client 发 Probe；host 没有应答，
pendingProbes=1、MSHR 仍 active。flush 尚未发 outer Release/ReleaseAck，也没有目录
invalidate。根因是 readback Acquire 重新取得 client ownership 后，fixture 直接
flush，没有 ProbeAck responder 或先行 Release。不是 preservation/validation FSM 卡死。

fixture 现在在读回校验后用真实 clean `Release(TtoN)` 归还 client ownership，再
执行现有 cleanup validation 与 flush；确认 durable outer bytes 等于 Q3 后才打印
CASE PASS。未增加 outer Put、未提前 validation，也未更改 Stage3 safety gate。
增加 MSHR flush-only observation bundle 与最小 probe/release/commit event log，
timeout 输出 `FLUSH_BLOCKER`、MSHR/key/validation/preservation/Probe/Release/commit 状态；
这些输出不连接协议控制。MSHR/Scheduler 删除新增 diagnostic 后逐字还原本轮之前
源码；ordinary transition table/assertions未动。

run HEAD、相关八份生产源码、fixture/生成器副本及保存 RTL hash 与失败 run provenance
一致。静态 transition table 18 allowed/54 forbidden/9 implicit self，独立 flush 域
6 条，18 CASE 清单通过。Python AST、shell syntax、保存端口宽度声明桩下 C++ syntax、
diagnostic assignment、protocol-source-with-observations-removed、`git diff --check`
均 PASS。未运行 Scala compile/elaboration、RTL generation、Verilator、模型构建、runner
或 simulation；新 Chisel diagnostic bundle 尚未验证编译/生成。

`STAGE3_STATUS=PATCHED_PENDING_REBUILD`、`STAGE3_CLOSURE=NO`。directed 失败 run 与
原有 Stage1/2 closure、用户改动全部保留。详见
[`CASE 10 flush RCA 与 ownership cleanup`](../history/reports/stage3_case10_flush_ownership_20261020.md)。

## 当前：Stage 3 host drain 孤儿 Probe 已修，硬件 liveness 静态审计完成（2026-10-19）

最新用户现场 `AI/TMP/stage3_runs/run_ybxmr7og/`：SOURCE_PROVENANCE/BUILD PASS，
DIRECTED FAIL（same_line_safe_dirty_wait_ack，timeout: drain），SYSTEM NOT_RUN。
17行 trace 显示首个合法 Acquire 的 Grant/目录 commit/MSHR free均已完成；P 的
ReleaseData、Q到达、preservation pending均尚未发生。本轮不把这次 host idle
timeout误判为已经进入 checkpoint drain，也不重新调查已修的 capability/flush表。

确定首个坏事件是 reset 的 cycle0，host错误记录 B(addr80000000)；上轮新增
pendingProbes账本漏了reset门控，硬件同步reset后取消状态，host却永久等不存在的
ProbeAck。现统一禁止 reset期所有host握手/计数/queue/stall-history记账，reset
仍正常打时钟、host valid/ready拉低；不清活跃账本、不删除drain、不改timeout。
reset后检查零事务状态，任何until超时先打印完整 DRAIN_BLOCKER snapshot。

逐项审查硬件capture predicate：SourceD idle、SourceC idle、已准入SinkC bank
queue空、selected MSHR probe/refill quiescence。九类用户指定路径以及ProbeAckData、
trusted A写均已静态审计，未发现其他有源码证据的内部等待环，未改硬件功能gate。
仅增L2Preservation/SourceD/C观察输出、Scheduler诊断bundle/有限事件日志及fixture
透出；MSHR/SinkC/Directory不变。原全局pipeline收尾与局部selected quiescence保留。

`STATIC_REVIEW=PASS`、`DRAIN_LIVENESS_AUDIT=PASS`、`STAGE3_STATUS=PATCHED_PENDING_REBUILD`、
`STAGE3_CLOSURE=NO`。仅源码/日志/旧生成物/纯静态Python、shell syntax、diff及assignment
检查；未编译/生成/elaborate/FIRRTL/Verilator/仿真/测试，未执行runner。活性结论
仍要求合法peer最终完成握手/validation，不声称任意永久背压可自动解除。
源码与fixture identity改变使旧BUILD及下游失效，用户仍使用原无参单入口。

详见 [drain RCA、双重predicate和全部入口等待图](../history/reports/stage3_drain_liveness_audit_20261019.md)。
本轮证据 `AI/TMP/stage3_drain_audit_99ciq6nn/`；旧run与Stage1/2 closure证据保留。

## 历史：Stage 3 第二次动态 flush 断言域修复，配置及 18 CASE 静态审计完成（2026-10-19）

最新用户现场 `AI/TMP/stage3_runs/run_e23qwk6h/`：SOURCE_PROVENANCE/BUILD PASS，
DIRECTED FAIL、SYSTEM NOT_RUN。生成模型明确 m=true，Get(b) 已完成、第一 CASE
与 duplicate ACK CASE 已通过；上一轮 fixture capability 修复生效，不再调查 m=false。
当前首错在 `full_provenance_collision` 开始的 cleanup：真实 flush(b) 命中 clean
TIP（clients=0、dirty=0、BASE），clean Release txn8 与匹配 ACK 完成，目录最终
提交 INVALID 时触发原普通表 `TIP->INVALID, p=false`；fatal generated RTL:12988。

根因分类 C：Stage3 把目录 invalidate 延迟到 ACK 后，但普通 transition table
仍假定 flush 走 eviction 域。本轮为 control 最终提交建立严格 FLUSH_COMMIT 域，
要求有效 hit、issued/sent/matching ACK、清空全部 ownership/dirty/provenance；
普通 72 条表项及其 assertion helper、eviction 检查原样保留，未改协议数据流/gate。
同因覆盖六种 reachable resident 到 INVALID（当前 TIP 加五种潜在状态）。
静态枚举九状态、18 ordinary allowed/54 forbidden/9 implicit self；18 CASE 全部
人工生命周期审计并核查路径族，未发现其他已证实的普通非法 transition 根因。
补齐 fixture inner B.address 的生产 restoreAddress 边界；增加 C/Probe 生命周期、
严格 drain、MSHR/flush/cleanup/validation/preservation 有限事件诊断。

只完成源码修复与静态 Python/表展开、shell syntax、assignment/use、差异及证据
检查；未编译/生成/elaboration/FIRRTL/Verilator/仿真/测试，未执行 runner。
`STAGE3_STATUS=PATCHED_PENDING_REBUILD`、`STAGE3_CLOSURE=NO`。Stage1/2 旧 closure
保留为原树证据；fresh directed/system 与新增断言/日志的编译效果仍待验证。
原无参 runner 因 MSHR/Scheduler/fixture identity 改变自动使旧 BUILD/下游失效。

详见 [第二次失败 RCA、全配置与 18 CASE 审计](../history/reports/stage3_tip_invalid_config_audit_20261019.md)、
[完整 transition 矩阵](../history/reports/stage3_transition_matrix_20261019.md)。
证据目录 `AI/TMP/stage3_config_audit_quv22_u8/`；旧 run 未改写或删除。

## 历史：Stage 3 首次动态 assertion 已定位并修复 fixture，待重建（2026-10-19）

最新用户现场 `AI/TMP/stage3_runs/run_1_d9fdyq/`：`SOURCE_PROVENANCE=PASS`、
`BUILD=PASS`、`DIRECTED=FAIL`、`SYSTEM=NOT_RUN`。旧编译/SerialTL echo 阻塞已越过。
首错为普通 `abc_mshrs_0` 在目录最终调度时触发 `S_INVALID -> S_TIP` assertion，
generated `Stage3Harness.v:12527`，Verilator 时间 `[254]`。

根因分类 C：fixture 将 source 1 声明为 Probe client，却用它发 uncached Get/Put，
导致静态 cfg `(p,c,m,r,f)=(false,true,false,false,true)` 中 m 错为 false。
第一 CASE `same_line_safe_dirty_wait_ack` 收尾的 Get(b) miss，经真实 victim ACK 和
正常 refill 得到 clean TIP；`before=INVALID` 来自 tag miss，不是 MSHR reset 状态。
Q 的 seq=1 此时已 validation；没有 ReleaseAck/completion 直接恢复 TIP 的赋值。
保存 trace 无波形/逐事件周期戳，中间握手顺序由同源 RTL 和确定刺激推出。

已仅修 Stage3 两份 fixture：coherent source 0，non-probe sources `[1,3)`；
两个并发 Get 改用 1/2，消除旧 host 未等 D 就排入相同 source 第二请求的复用风险。
增加 inner A→D source 生命周期检查、带周期并立即 flush 的 CASE_BEGIN/A/D 日志。
18 CASE 与 checker 不变，生产 MSHR、transition table、全部 assertion 和
preservation/validation/Acquire/目录 gate 本轮未改。25 份相关生产文件与保存
inputs.json 同源，且本轮 hash 不变；两份 fixture 修复前也与 run 副本逐字相同。

静态 assignment/use、72 个不同状态 pair、18 CASE 清单及 diff/语法检查通过；
未执行 build、编译、生成/elaboration/FIRRTL/Verilator、simulation、runner 或测试。
当前 `STAGE3_STATUS=PATCHED_PENDING_REBUILD`，`STAGE3_CLOSURE=NO`；动态修复效果与
当前 Stage1/Stage2 SYSTEM 回归均待验证。原 closure/用户改动/失败现场全部保留。
证据 `AI/TMP/stage3_invalid_tip_fix_3slovmd6/`；详见
[首次动态 assertion RCA 与状态机审查](../history/reports/stage3_invalid_tip_fixture_fix_20261019.md)。

用户继续使用现有无参单入口 `AI/Debug/scripts/stage3/stage3_run.sh`。fixture identity
变化自动使旧 BUILD 及下游失效；runner 在新目录 BUILD→DIRECTED→SYSTEM，失败即停。
本轮未执行入口，不允许复用旧生成物验证新 fixture。

## 历史：Stage 3 SerialTL echo 缺口已修，待重建（2026-10-19）

`STAGE3_STATUS=PATCHED_PENDING_REBUILD`，`STAGE3_CLOSURE=NO`。
最新用户现场 `AI/TMP/stage3_runs/run_vsb0kdix/` 已越过旧 SinkC Scala 编译错误，
Stage3Harness 生成、lint、模型编译均 exit0；BUILD 随后的整机 FIRRTL 检查失败。
原日志有3处 RefNotInitialized：TLSerdesser 的 D、TLSerdesser_1 的 A/C 均缺
`echo.cache_preserve_txn`。make Error 1 / runner exit2 为后续汇总；11条日志诊断
不代表11个独立根因。annotation 的130 pin 数量正常，不是本次阻塞。

已修复 Serdes.scala 的 merged packet echo 编码/解码，A/C/D 透传原身份、B/E 的
无效 echo payload 确定置零。静态继续追踪原 FIRRTL 发现实际 harness TLRAM/TLROM_1
也缺返回 echo；因原串行格式未读取它而未在此次错误清单出现，现一并补齐。
TLRAM echo 与 source/size 按相同 A→R→D enable 寄存并按相同响应级选择，
ROM 在原组合响应上透传。未修改 preservation FSM、ACK 匹配或写入 gate。
shared first_error 摘要现在优先显示 PassExceptions 后的具体错误，批量报告仍保留。

修复前三份源码均与该 run 的 inputs.json hash 一致；现场和旧产物保持原样。
仅做 Python AST、shell syntax、git diff --check 和日志/源码/旧 FIRRTL 静态审查。
本轮没有执行 build、Scala compile、elaboration、RTL generation、FIRRTL、Verilator、
simulation、regression、runner 或单元测试；新序列化格式及端到端功能仍待验证。
证据目录 `AI/TMP/stage3_serdes_echo_fix_v5355woc/`；
详见 [SerialTL echo 修复](../history/reports/stage3_serdes_echo_fix_20261019.md)。

用户仍只执行无参 `AI/Debug/scripts/stage3/stage3_run.sh`；source/helper identity 改变
会自动使 BUILD 和下游失效，在新目录重建。DIRECTED/SYSTEM 本次用户运行均 NOT_RUN，
没有有效的整阶段 BUILD seal；不得复用其局部 module PASS 或旧模型。

## 历史：Stage 3 编译 API 错误已修，批量诊断就绪，待重建（2026-10-18）

`STAGE3_STATUS=PATCHED_PENDING_REBUILD`，`STAGE3_CLOSURE=NO`。
用户实际运行 `AI/TMP/stage3_runs/run_5hyf3lau/` 在 BUILD 的 Scala compile 失败，
完整 module.emit.log 只有一个真实编译错误：SinkC.scala:74 找不到 chiselTypeOf。
该文件的修复前 hash 与该 run 的 inputs.json 一致；症状不是 preservation 动态失败。
已将该处改为明确的 `chisel3.chiselTypeOf`，没有修改协议状态机或 gate。
命令失败/超时及退出0但 module 生成不完整时，runner 现在打印并保存全部不同日志
诊断到 `<log>.errors.out/json`；failure.json 和固定 summary 保留原始码、诊断数和路径。
计数是日志诊断数，不是独立根因数；仍任一阶段失败即停止，下游 NOT_RUN。
见 [编译修复与诊断交接](../history/reports/stage3_compile_diagnostics_20261018.md)。

唯一入口为 `AI/Debug/scripts/stage3/stage3_run.sh`，无需参数或 STAGE3_ROOT。
自动 BUILD → DIRECTED → SYSTEM，失败立即停止；每次新建 immutable run，
完整验证来源、模型/证据哈希、checker 和上游依赖后才复用已完成阶段。
旧人工 mode 与 stage3_build_and_run.sh 已移除；runner 不修改/删除自身或旧证据。

本轮仅修复一个 Scala API 名称引用并修改运行器诊断、状态和文档，未改 Stage3 preservation protocol。
未执行编译、生成/elaboration、Verilator、simulation、regression 或 runner 测试。
只做 Python AST、shell syntax、git diff --check 与静态 review；静态 PASS 不等于硬件 PASS。

协议的 checkpoint/receipt、victim ACK gate、ProbeAckData gate、18 CASE 保持原样。
当前 source/runner identity 已改变，旧失败 BUILD 不可复用；原单一命令自动新建目录、
重建后再定向/整机验证。本轮未执行该命令，编译与全部动态 gate 仍 unresolved。
见 [单入口交接](../history/reports/stage3_runner_20261018.md)、
[协议静态交接](../history/reports/stage3_static_20261018.md) 与
[设计及唯一命令](../../Design/stage3_l2_preservation_20261018.md)。
Stage1/Stage2 旧 closure 保留为原树证据，当前硬件仍待 fresh validation。
本轮不运行验证入口、不清理旧 run、不 reset、同步或提交工作区。

## 当前：Stage 2 L1 preservation 已关闭（2026-10-18）

`STAGE2_STATUS=CLOSED`，`NEXT_SIM_REQUIRED=NO`，`KNOWN_STATIC_CORRECTNESS_BLOCKERS=0`，
`CODE_CHANGES=NONE`。最新真实 run 是 `AI/TMP/stage2_validation_agciqdp_/`：
build/directed/system 三份 status 均 PASS/exit0；33 pin wiring、lint、完整构建和
三次 provenance 验证通过；10 个定向 CASE 各一次，独立 effect/denied Put/AMO 对照完整。
旧 d5wr10l1 的 epoch 阻塞已在该次运行消失，不再作为当前待重建故障。

本轮重新比对 run 记录的 11479 个 source、16 个 scripts 和完整清单，全部匹配当前
文件；HEAD/workload manifest/fixture 副本也匹配。审计证据
`AI/TMP/stage2_evidence_audit_bbmws5qc/{identity.audit.json,inventory.audit.json}`。
未重新 hash 整个 generated/binary/2.7GB trace，采用运行时原 provenance/artifact gate；
不混同本轮 source 检查和完整产物重验。

整机 Stage2 checker：errors=[]、missing_coverage=[]，PRESERVE/receipt/done 各1216；
MODIFY144225、NORMAL135486、REPLAY8739、AMO90、SAME_PACKAGE95072、IMPORT9415。
实际 trace 保存了 safe/lower0 阻塞→L2 commit→准确 ACK→done→refill→新包 replay effect
因果链。复用本次原 Stage1 checker 的全 PASS 与真实 exit drain 全零；Stage1 保持已关闭。

没有发现新 RTL correctness bug，不制造功能/checker/trace 修改。receipt+probe revoke
和 receipt+refill 的精确同拍场景由 RTL next-state、owner/drain、epoch/full-key 和
写口仲裁静态严格保护，归类为 `NON_BLOCKING_COVERAGE_GAP`；长期公平性属于
`OUT_OF_SCOPE_FOR_STAGE2`，不是 L1 preservation safety blocker。
现有 checker 的边界包括：LOWER_COMMIT/ACK 按完整 key 关联而非独立地址/source、safe
由 RTL trace 提供而独立时序检查来自定向 stimulus、refill row 依赖生产断言和原 owner
checker。matching done+probe revoke / refill+done 精确同拍无独立 CASE，但由静态 next-state
和 owner/drain 互锁严格推出；任意压力公平性属于 Stage 2 范围外。这些边界不伪报覆盖，
也不据此推断已经存在功能缺陷。

完整 closure checklist、race 分类、producer matrix 和实际动态 evidence 见
[完整11节审计报告](../history/reports/stage2_evidence_audit_20261018.md)。没有源码变化就
无需为文档更新重跑已通过硬件。若后续 Stage 2 源码变化，仍使用原绝对路径
`stage2_build_and_run.sh all` 重新建立同源 run；不要覆盖已有 run。

本轮未执行任何编译、生成/elaboration/FIRRTL/Verilator、仿真、regression 或单元测试；
仅源码/日志/清单/hash/差异检查和文档更新。未 reset/清理/同步/提交或修改 sources/，
全部 Stage1/Stage2/用户改动及历史失败现场保留。

## 历史：Stage 2 directed preservation gate 修复，待重新构建验证（2026-10-18）

用户最新定向现场为 `AI/TMP/stage2_validation_d5wr10l1/`。该次 build 通过，
但 directed 在 `prematureAck` 报 `premature ACK needs stalled first C beat`。
原始 trace 在同一行反复输出 `STAGE2_TX BLOCK`（旧 image `epoch=1`、
`lower=0`、`safe=1`），始终没有 `STAGE2_TX PRESERVE`；因此本次观察到的
是 preservation 请求未启动，尚不能把它解释成提前 ACK。该 run 的 generated
RTL 是修复前产物，不能与当前源码混用。

已确认并修复 `chipyard/generators/boom/src/main/scala/lsu/dcache.scala`
中的 epoch 误索引：`s2_lookup_epoch(0)` 已是选中 way 的完整 epoch，旧代码
再次按 way 取 bit，way 1/epoch 1 会错误抑制 cross-package block/preservation
建立；当前比较完整 epoch 与对应 `slotEpoch(set)(way)`。同时增强
`AI/Debug/scripts/stage2/stage2_test.cpp` 的 precondition 诊断，记录 C
valid/fire；`stage2_validation.py` 在 directed 失败时汇总所有结构化 case、
缺失 case、独立 effect 事件和 L2 denied/成功事件缺口。

本轮已检查：57 项 `test_stage2_validation`、Python 编译、三个 shell 语法、
`git diff --check`；静态证据和当前源文件 hash 记录在
`AI/TMP/stage2_directed_epoch_fix_4_eyionz/static.correction.json`。这些检查不启动硬件工具。未检查：当前源码的 Scala 类型
编译、RTL 生成、FIRRTL/elaboration、Verilator、directed/system 仿真和真实
动态覆盖。旧 Stage 1/Stage 2/用户改动均保留，未 reset、同步、清理、提交或
修改 `sources/`。当前状态：`STAGE2_STATUS=PATCHED_PENDING_REBUILD`；下一步
需用新 root 执行绝对路径 `stage2_build_and_run.sh all`，只有 fresh build
通过后才能判断该 gate 和后续 CASE。

## 前一轮：Stage 2 整机残留 CAM 的 64 条连线问题已修，待重新构建（2026-10-18）

用户最新 run `AI/TMP/stage2_validation_r8baqbfq/` 已完成独立 fixture 的 Scala compile、完整生成、97 pin wiring 审计、Verilator lint 与模型 C++ 编译，越过前轮构造问题；整机在 WiringTransform 报 `NoSuchElementException: gh_l1_l2_packet_tracked_15`。核对该次真正输入的 appended annotation，确认共有 64 个旧 CAM source 没有 sink：Stage 2 SinkC 已迁移到 TL CacheImage，但 L1 仍发布旧 CAM。其余 130 个 pin 数量正常；详见 [整机连线修复](../history/reports/stage2_system_wiring_fix_20261018.md)。

已一次移除无消费者的 64 个旧发布端及其 CAM 状态，fixture 同步移除对应 sink、保留 33 个真实接收端，原 preservation/TL/统计门禁不变。运行器清除错误摘要的 ANSI 和 JVM options 普通提示，首错显示实际 cause；整机构建失败自动从该次最终 annotation 列出所有异常到 system.wiring.out/json，保留原始退出码和完整原日志，不增加硬件运行。all 仍跳过 offline，严格 build→directed→system。

本轮证据 `AI/TMP/stage2_system_wiring_fix_oo_upv1_/`：56 项纯运行器测试通过，最外层禁止外部进程；源码/精确差异、原日志只读重判、Python AST/shell syntax/diff 检查已做。当前源码没有重新编译、生成、elaboration、执行 FIRRTL/Verilator 或仿真。用户原 run 的 directed/system 未运行；当前 33 pin fixture、整机完整构建和动态覆盖全部 pending。无已知构建前阻塞，用户执行原绝对路径 all。`STAGE2_STATUS=PATCHED_PENDING_REBUILD`。保留全部 Stage 1/Stage 2/用户改动与失败现场，未同步/reset/清理/提交或修改 sources/。

## 历史：Stage 2 审计 transform 无参构造已修，待重新构建（2026-10-17）

用户最新 run `AI/TMP/stage2_validation_mzljfuss/` Scala compile 完成后，FIRRTL 在构造 Stage2WiringAudit 时失败；module.emit.log:335 的 NoSuchMethodException 明确缺少 `<init>()`。这是上一轮新增带 reportPath 构造参数的审计类引入的问题：本地 Compiler→Dependency.fromTransform 把普通对象转为类依赖，再反射调用无参构造。原日志、旧 class 的 javap 与 FIRRTL jar 字节码已相互核对，详见 [无参构造修复](../history/reports/stage2_audit_ctor_fix_20261017.md)。

正式 fixture 已改为公开顶层无参类，报告路径由每次 CircuitState 的 TargetDirAnnotation 提供，缺失明确失败；EmitModule 在 elaboration 前用真实 Dependency.getObject 提前检查相同构造链路。97 个只读 sink、批量审计/错误报告、成功产物门禁和原 all 三阶段/跳过自动 offline 均保留，未改生产 RTL。

本轮证据 `AI/TMP/stage2_audit_ctor_fix_qxwo_iry/`：只做源码/精确差异、现有 class/jar 的静态 javap、Python AST/shell syntax/diff 检查，未重跑完整 offline suite，未构建、生成、elaboration、执行 FIRRTL transform、Verilator 或仿真。用户本次失败发生在 wiring 审计前，不能宣布此前 97 个 sink 已动态验证；新增无参构造、报告目录及后续完整生成/硬件行为仍待实测。无已知构建前阻塞，可由用户执行原绝对路径 all。`STAGE2_STATUS=PATCHED_PENDING_REBUILD`。保留所有 Stage 1/Stage 2/用户改动和旧现场，未同步/reset/清理/提交或修改 sources/。

## 历史：Stage 2 WiringTransform 缺 sink 已补齐，错误报告改为批量，待重新构建（2026-10-17）

最新用户 run `AI/TMP/stage2_validation_5iv7ungc/` Scala compile 成功，已越过上一处 1G OOM，首次失败为 module.emit.log:60 的 FIRRTL `Wrong number of sources or sinks!`，栈在 WiringTransform。fixture 未实例化 InclusiveCache/TestHarness 消费者，实际 L1 的 97 个 BoringUtils source 均无 sink；本地 FIRRTL jar 字节码确认这正是有 source/零 sink 分支。已按实际 source 名称/宽度一次补齐只读 sink，无协议回馈或生产 RTL 修改。源码展开核对缺失 97→0，宽度不匹配 0；生产 dcache hash 与原失败清单一致，详见 [wiring 修复](../history/reports/stage2_wiring_build_fix_20261017.md)。

新增 WiringTransform 前置审计，一次列出所有坏 pin/目标并保存 generated/stage2.wiring.out；成功报告必须参与生成完成及产物来源门禁。运行器在失败时显示同次日志里全部不同的错误/失败诊断，保留 `<log>.errors.out/json`、上下文/原码/hash 与摘要路径；定向 Verilator error-limit=0，不改错误严重度。all 仍为 build→directed→system，前阶段失败后续 NOT_RUN，已通过的 offline 不再自动运行。

本轮证据 `AI/TMP/stage2_wiring_fix_3nol05y4/`：最终 48 项受影响运行器测试、Python AST/shell syntax/diff 检查通过，所有硬件动作替换；源码 inventory 与 jar API 为静态检查。未启动构建/Scala compile、生成、elaboration、FIRRTL、Verilator 或任何仿真。没有已知需要构建前继续修复的阻塞，下一步用户执行原绝对路径 all；新增接收端、Scala 审计及完整硬件正确性仍待实测。`STAGE2_STATUS=PATCHED_PENDING_REBUILD`。原失败 root、Stage 1/Stage 2/用户改动全部保留，未同步/reset/清理/提交或修改 sources/。

## 历史：Stage 2 生成 OOM 已修，all 移除重复离线检查，待重新构建（2026-10-17）

用户最新 run `AI/TMP/stage2_validation_qodffn_8/` 显示 fixture Scala compile 已成功，随后 Chisel/FIRRTL 转换在 Java 1G heap OOM；sbt 后台线程异常仍 exit 0，旧入口最终只报无 RTL。module 直接调用 sbt 未获得 Stage 1 Makefile 的 8G 默认，是本次根因。已显式传入 8G/Xss8M 和 ExitOnOutOfMemoryError，参数写入来源清单；exit 0 后仍检查异常日志、顶层产物和正常完成标记，失败指向 module.emit.log 并保留 raw code。详见 [OOM 修复](../history/reports/stage2_emit_oom_fix_20261017.md)。

按用户要求，原一条命令 `stage2_build_and_run.sh all` 现为 build→directed→system，不再自动重跑已通过的 offline tests；仍强制保存/核对源码、fixture、参数、环境、工具、workload、模型/binary 和覆盖状态。offline 只保留为显式选项，未运行不会标 PASS。唯一 root、严格串行、失败即停及中文日志/摘要继续保留。

实际本轮脚本检查证据 `AI/TMP/stage2_emit_oom_fix_v_0k0s2e/`：最终 42 项受影响运行器测试（硬件动作均替换）、Python AST、shell syntax、diff 检查通过；只读重判原失败日志准确识别 OOM。未执行完整 offline suite、build、Scala compile、elaboration、FIRRTL、Verilator 或任何仿真；硬件正确性仍未验证。无已知构建前阻塞，建议用户重新执行原绝对路径 all 命令；8G 是否足够仍待构建实测。`STAGE2_STATUS=PATCHED_PENDING_REBUILD`。未 reset、清理、同步、提交或修改 sources/；旧失败现场完整保留。

## 历史：Stage 2 fixture Probe API 编译错误已修，待重新构建（2026-10-17）

用户 run `AI/TMP/stage2_validation_llhv_oen/` 的 module.emit 在 Scala compile 阶段失败，唯一错误是 `Stage2Generate.scala:142` 引用不存在的 `TLMessages.ProbeBlock`。已按本地 Bundles.scala/TLEdgeIn.Probe 改为 `TLMessages.Probe`，仅一行 fixture 变更；原失败副本、日志和所有既有改动保留。详见 [Probe API 修复](../history/reports/stage2_probe_api_build_fix_20261017.md)。

实际最新离线证据 `AI/TMP/stage2_validation_8h7j2vpe/`：75 项离线测试与现有语法/diff 检查通过，额外当前 TLMessages/TLPermissions/TLAtomics 成员名核对无缺项；已证明相对失败副本只有这一行修改。本轮未重跑 Scala compile、硬件生成、elaboration、Verilator 或仿真，不能宣布构建通过。下一步用户重新执行原绝对路径 `stage2_build_and_run.sh all`，自动新建 root。`STAGE2_STATUS=PATCHED_PENDING_REBUILD`。

## 历史：Stage 2 单命令 all 与 denied 回归就绪（2026-10-17）

继续 `PREFLIGHT_READY_PENDING_BUILD`，无已知构建前阻塞。用户在原 Stage 1 环境任意目录只需执行 `/data1/gzh/EC/AI/Debug/scripts/stage2_build_and_run.sh all`。现有入口自动定位项目、创建唯一 root，严格 offline→build→directed→system，保留全部 provenance/匹配/覆盖门禁；中文显示阶段与总结果、失败原因/首个错误和日志绝对路径，保存 runner.log/summary.out。工具失败保留原始码，覆盖不足与工具退出3分开记录。

新增生产 L2 MSHR→SourceD 的 denied Put/ADD 与成功对照，合并原定向进程，10 CASE；检查完整旧 key/provenance、真实 schedule/directory/D/bank 事件、denied 零写及成功数据。补覆盖时修复 fixture CACHED outer edge 违反 lastLevel 参数要求，以及 SourceD denied full Put 缺 old-data read 却可能写 bank/bypass：denied 不再进入 bank retirement/bypass。真实目录存储/互连与整机主动 denied 仍有覆盖边界，见 [单命令交付](../history/reports/stage2_all_entry_20261017.md)。

最新实际证据 `AI/TMP/stage2_validation_53whknp_/`：从 `/tmp` 绝对路径运行 offline，75 项纯离线测试、Python AST、shell syntax、diff、C++ declaration-stub syntax-only 通过。单元测试的硬件动作全部替换，不是硬件 PASS。本轮没有执行 all、build、elaboration、FIRRTL、Verilator 或任何仿真；新增动态回归全部待用户运行。未同步、reset、清理、提交或修改 sources/，所有已有改动保留。

## 历史：Stage 2 构建准入复核完成（2026-10-17）

`STAGE2_STATUS=PREFLIGHT_READY_PENDING_BUILD`。以本地 `1ed07c280` 和全部 Stage 1/Stage 2 未提交改动为准，继续保留现场；未同步、reset、清理、提交或修改 `sources/`。

本轮修复 SourceD 内部 Atomics 的新 TL 字段未初始化、probe 借 WB ready 误判完成、C 全部发送前 matching-key ACK 锁存、fixture 128-bit 高半观察缺失、denied A 操作重标旧 image。新增 freeze admission/实际写口断言、独立 effect guard、完整 CASE 名单和 key/epoch/receipt analyzer。字段/目录、bank ACK、buffer/credit/probe、freeze 与 ACK 生命周期六项源码复核见 [preflight 报告](../history/reports/stage2_preflight_20261017.md)。

手动入口拆成 `stage2_build_and_run.sh offline → build → directed → system`，同一新 `STAGE2_ROOT`、相同环境；前阶段失败/缺覆盖或 source/model/参数/环境不匹配时，后阶段拒绝运行。Stage 1 仅增加显式 build-only 出口，默认行为保留。

实际最新离线证据：`AI/TMP/stage2_validation_u_xd___4/`，`OFFLINE=PASS`；64 项纯离线 tests、Python AST、3 个 shell syntax、declaration-stub C++ syntax-only、diff 检查通过，附 15 Scala 文件 lexical balance（不等于类型检查）。此前 root 保留，后续源码改变会被输入 gate 拒绝。本轮没有运行 sbt/make、Scala 编译、硬件生成、elaboration、FIRRTL、Verilator 或任何仿真，build/directed/system 都未执行。

无已知需要在 build 前先修的阻塞；建议用户从新 offline root 开始四阶段验证。实际 Scala API/初始化/组合环、generated ports、动态背压/并发和全系统进度仍待验证。Stage 1 旧 PASS 不证明本轮 RTL。Stage 3 lower predecessor FSM、rollback/escape/pressure-close 不在本轮。


## Stage 1 已正式关闭（2026-10-17）

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
# Optimization 2 root-cause review; no safe RTL candidate yet (2026-10-25)

The successful Optimization 1 run `slowdown/optimization_1/runs/optimization_1_20261025_123241_e7c5f139/` is now dynamic evidence: ROI is 4,706,513 cycles versus the pinned Original Current ROI 4,734,881, an actual reduction of 28,368 cycles (0.599128%), not the earlier informal 80k estimate. Same-set different-line exposure fell from 273,179 to 996 observed cycles, while MSHR lifetime stayed approximately unchanged (mean 88.3239 -> 88.0368, p95 107) and direct IC gate opportunity did not fall.

The Opt1 trace was replayed offline into `AI/TMP/optimization2_rootcause_and_impl_20261025_d9703cb7/opt1_causal/`. Pending samples separate target PASS absence at the observed endpoint (3,012,446 cycles), result/prefix propagation (88,235 cycles), and post-safe WB/meta-clear stages (about 77k cycles). The first category is not an optimization proof; the prefix category has only 12 intervals and lacks per-predecessor/epoch evidence. R_IC gate ownership/snapshot conditions do not consume the L1 safe watermark directly. No common safe predecessor root cause is closed.

Decision: `NO_SIMULATION_YET`. No Optimization 2 RTL, patch, build, elaboration, Verilator run, or workload was executed. `RUN_PROVENANCE=UNRESOLVED` and full cache/package/DRAM drain remain unresolved. Future evidence must add checker instruction/tail progress, per-slot predecessor state, R_ICSL/RocketCore cleanup/result lifecycle, and complete MSHR release joins before any safe release optimization is designed.
