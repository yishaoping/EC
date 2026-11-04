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
