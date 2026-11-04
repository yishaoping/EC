# Recovery performance investigation, 2026-11-04

Frozen hardware: `a6e63c75947739dfbb411b32bfe0eb5ed55c5bb1`, preserved by
`opt4-final-corrected-r2-20261103` and `opt4-recovery-perf-baseline-20261104`.
Evaluation checkpoint: `a0833a772`. The completed reports were uncommitted in
the evaluation worktree; their snapshot is in `baseline/`. That worktree and
the FPGA worktree are untouched. Changes use branch `opt4/recovery-perf-20261104`
in `/data1/gzh/EC-opt4-recovery-perf`.

## Measurement consistency

The old Blackscholes 1.121418146 ratio uses test4, 100 rounds, 220,637 retired
instructions and a software ROI including STOP/session polling. The current
1.035765 ratio uses project64, 100 rounds, 3,562,647 retired instructions and
an application-only ROI. The old repair is `83dec9d4c`; current hardware adds
the accepted epoch/owner repair through `a6e63c759`. These are different
experiments. Neither ratio uses host simulation seconds. CONFIG.md in the old
evaluation directory has a stale first paragraph; hardware_revision.json and
the sealed simulator/source hashes identify the actual accepted revision.

Current triplets use matching input, protected ELF for Check/Correction,
application output and ROI retired instructions. Native changes only the mode
word. Detection has the matched BOOM/cache/clocks and four checkers, fetch4;
correction has fetch8. Their ratio measures the net final-design difference.
Detection does not expose an equivalent sequenced internal coverage ledger;
that limitation remains explicit.

## Initial quantitative evidence

| Observation | Streamcluster project64 | Canneal project400 |
|---|---:|---:|
| Check application cycles | 2,499,121 | 419,398 |
| Frozen correction application cycles | 3,706,513 | 668,878 |
| Application instructions | 3,017,385 | 392,248 |
| Hardware traffic observation cycles | 3,712,739 | 1,521,296 |
| Physical L1 misses in traffic window | 233 | 8,707 |
| MSHR full cycles in traffic window | 0 | 225 |
| L2 checkpoint ACK wait, traffic window | 36,934 | 19,894 |
| SVB peak entries / per-line depth | 16 / 3 | 16 / 4 |
| SVB allocations / completed / discarded | 9892 / 1785 / 8107 | 667 / 660 / 7 |
| Store candidate with older inflight, traffic window | 439,779 | 541,099 |

These overlapping, differently windowed counters cannot explain an additive
ROI slowdown. In particular Canneal preparation is outside the application
ROI but inside the traffic window. Cache shadow geometry validation failed;
counterfactual cache predictions are excluded. Streamcluster's saved optional
checker samples cover only 287/1213 packages; its reported 12.84% activity is
a lower bound, not utilization of all packages.

## Profiling build

SC52 samples cumulative BOOM counters every 1024 cycles. Commit cycles and
eight priority categories of no-commit cycles are disjoint and conserved.
Priority: GH buffer, RSU, IC controller, big_hang, dispatch drain, CSR, nonempty
ROB, empty ROB. Raw gate counts are also retained. This measures blocked
retirement exposure, not a counterfactual speedup.

SC53/54 sample overlapping DCache request, replay, capture, replacement,
MSHR, refill, publication and ACK exposures. Offline profiling clips to saved
samples inside the application ROI and reports the unmeasured boundary cycles
(at most 2048). Counters have no control consumers and checker count stays four.

First build failed before source compilation because old JGit cannot discover
a newly created linked worktree. Private worktree metadata now has the same
JGit compatibility links/config as the pre-existing evaluation worktree.
No shared source or FPGA configuration was edited. Failed build logs remain.

No performance change or benefit has been accepted yet.

Profiling generated RTL validation: epoch cone 73 directed cases / 2818
ownership checks PASS (`logs/epoch_cone_a12391b6.json`); actual emitted WB
300 transactions, 100 probes during ACK, 1600 beats, 300 receipts PASS
(`baseline/profile_wb_unit.json`). These validate their controller/unit scopes,
not whole-system fault recovery.

Canneal's complete legacy wait trace classifies 117,975 ROI cycles as target
checker execution/tail not yet finished, 68 as formed-result transport/cleanup,
and 17 as watermark register propagation. 36,778 post-safe wait cycles and
3,148 overlapping conditions remain. The frontend's saved ROI windows show
11,794 ICache acquisitions across the four checkers and 268,029 local
instruction-starvation cycles in complete ROI packages. The proposal under
`candidates/` tests a bounded ICache parameter change only after the profiled
baseline is sealed. It is not an accepted optimization or measured benefit.

## Candidate 1: bounded checker ICache associativity/capacity

The observation-only build passed and launched sealed Streamcluster simdev
`streamcluster_simdev_correction_20261104_020844_4954a08f`. Its initial saved
window has 18,894 freeze-set ingress blocked cycles / 78,848 BOOM cycles,
with zero S2 write-busy exposure. Observed legacy wait phases include 10,692
checker-execution/tail cycles, 124 formed-result transport cycles, 2 watermark
propagation cycles and 6,899 post-safe handoff cycles. These are exposures,
not additive causal savings; full-run reproducibility remains pending.

Candidate 1 changes only checker ICache nWays 1 to 2 (2 KiB to 4 KiB per
checker, four checkers, total +8 KiB data RAM plus tags/replacement state).
The original main-core DCache, SVB, ACK, watermark and verification controls
are unchanged. Measurement and regression gates decide keep/reject; no
area/timing signoff or achieved speedup is claimed.

## Steady-window source audit and rejected shortcuts

Streamcluster simdev [200704,399360) has 198,656 measured BOOM cycles:
64,640 commit cycles, 26,611 no-commit/IC-gate cycles, 54,726 no-commit with a
nonempty ROB, and 51,345 no-commit with an empty ROB (the remaining priority
categories account for the balance). Cache exposures overlap: 52,770 freeze-set
ingress cycles, 47,730 legacy-preservation-pending cycles, 7,032 capture-pending
cycles, 15,259 ACK-pending cycles, zero physical refill beats, zero MSHR-active
cycles, and zero S2 write-busy cycles. This does not justify a larger main-core
DCache, additional MSHRs, or speculative S3 turnover changes for Streamcluster.

Observed SC7 state durations in [200000,400000) include 14,322 scheduling-state
cycles and 12,289 transfer-state cycles, of which 12,052 show RSU busy. These
are preliminary state exposures. The SC7 change key deliberately excludes the
pipeline-stall bit: replaying its saved bit alone undercounts threshold-edge
stalls (100 cycles in this window), so SC52 supplies the authoritative gate
counter. Optional record accounting must also be checked before using a full
SC7 interval as complete evidence.

An apparent snapshot/dispatch overlap shortcut was rejected by source audit:
`core.scala:2289` requires ROB empty for producerSealCoreReady, while R_IC's
transfer state stalls retirement until close_tail_ready. Allowing dispatch
alone during transfer can make the ROB nonempty and deadlock sealing. Relaxing
this requires a new proof that all younger work is excluded from the old
producer, plus boundary/rollback tests; the current candidate does neither.

A second proposed shortcut, capturing already-safe predecessors in SVB by
removing the eligibility safety test, is not applied. L1Preservation.allow
requires both safety and a preserved lower copy; PASS alone is insufficient.
SVB SPEC entries can be removed on an exception/epoch flush before promotion,
while only WB_WAIT retains through ACK. Extending this path would require
persistent historical-version recovery tests and a complete flush/epoch
ownership design. The existing no-fault tests do not establish that broader
recovery property. No ACK, preservation, flush, epoch or reclamation control
has been relaxed in candidate 1.

## Baseline complete and capture-host repair

Baseline simdev exactly reproduces 1,452,774 application cycles, 1,094,668
retired instructions and checksum 5e0eed7ac7af71fb. All 525 packages have
complete checker-work intervals; protocol, integrity, data ordering, SourceC
and snapshot ledgers pass. Original capture/analysis remain FAIL because the
host producer dictionary retained its old 128-identity cap while observer
identities had been raised to 144. The missing final statistics are only
optional identities 4:4, 5:3 and 5:4. No missing producer totals are fabricated:
a separate immutable reanalysis retains their unobserved metadata status,
checks independent emitted-event footers against the sealed logger/RTL limit,
and reclassifies only the proved optional-metadata error. Unchanged validators
then PASS. See baseline/capture_reanalysis_proof.json and the separate analysis
directory in baseline/profile_reproducibility.json. Original raw evidence is
untouched. The collector now shares IDENTITY_LIMIT=144 for both dictionaries,
retains bounded malformed-record diagnostics, and rejects identity 145 in a
directed host test. The waiting candidate driver was superseded before it
launched any simulation; its replacement uses the qualified baseline analysis.

## Candidate 1 provisional windows (complete pilot still running)

The initial [110592,189440) window is unfavorable: retirement 50,707 to
46,059 and freeze-set ingress exposure 18,894 to 29,899 cycles. It is retained,
not discarded. In the later [200704,399360) window, retirement increases
144,136 to 169,232 while freeze-set ingress falls 52,770 to 32,952, legacy
pending 47,730 to 26,746, ACK outstanding 15,259 to 9,028, and SVB-full
exposure 12,792 to 4,139 cycles. S2 write-busy and physical refill exposure
remain zero in that later interval. Before main cycle 400,000, the four
checkers latest frontend samples show cumulative ICache acquisitions
851/697/639/663 (baseline) versus 247/255/197/174 (candidate); endpoints differ
by several thousand cycles and workload progress differs, so these are
provisional exposures, not a matched full-ROI miss-rate or speedup claim.
Both windows are saved under candidates/. The complete pilot and the fixed
main inputs determine the final keep/reject decision.

The reproducible Canneal classifier refines the historical result endpoint:
SC6 bit9 is full_check_complete and directly creates local result valid; bit16
is local result enqueue, bit15 is result output valid. CDC SC4 enqueue occurs
later. All 144 local formation endpoints precede CDC enqueue in the real
trace. The old 117,975/68 execution-or-tail/transport split used CDC enqueue
and includes local cleanup in its broad tail bucket. The refined split is
116,989 not-yet-formed and 1,054 formed-result/cleanup/transport cycles; total
RESULT_NOT_AVAILABLE remains exactly 118,043. A fixture check expecting the
old subphase split failed, so the endpoint distinction was audited and saved
in baseline/canneal_phase_endpoint_check.json. The earlier artifacts remain.
