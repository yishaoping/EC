# Opt4 architectural optimization — 2026-11-04

Branch `opt4/aggressive-perf-20261104`, isolated worktree
`/data1/gzh/EC-opt4-aggressive-perf`, starts from the exact Candidate 2 hardware
source hashes at `fd7d4a0f9ad98e8534b27d96c44d76cc55f2c8e6` (hardware
`ae0d80a65a5d890b59e4c67575c0cb6af59730ae`). The original Candidate 2 Blackscholes
process was verified live before editing; none of its source/build artifacts
is modified. Frozen baseline `a6e63c75947739dfbb411b32bfe0eb5ed55c5bb1` and its
read-only backup remain unchanged.

| Workload | Native | Check | Frozen Correction | C1 | C2 |
|---|---:|---:|---:|---:|---:|
| Blackscholes project64 | 5,920,394 | 5,952,831 | 6,165,734 | 6,114,946 | 6,114,946 |
| Streamcluster project64 | 2,281,930 | 2,499,121 | 3,706,513 | 3,547,466 | 3,441,485 |
| Canneal project400 | 310,942 | 419,398 | 668,878 | 548,437 | 489,737 |
| BFS 512/8192/source0 | 1,001,675 | N/A | 1,128,052 | 1,125,574 | 1,126,805 |

Existing results, binaries, inputs and tools are indexed rather than rerun.
No new version can inherit an older version's performance result. Build and
simulation launches consult the machine-readable experiment index. Successful
raw results are immutable inputs; new work uses fresh directories. Native,
Check, frozen Correction and C1/C2 results are reused.

C2 completed naturally, exit0, checker1138 PASS/0 FAIL/0 CANCELLED on
Blackscholes, software/checker/protocol/integrity/data-ordering PASS and zero
assertion/failure markers. Blackscholes C2/Native=1.032861326459016,
C2/Check=1.0272332609476063; no improvement over C1,0.8237137703313135%
fewer cycles than frozen Correction. Streamcluster C2/Native=1.5081466127357106,
C2/Check=1.37707818068833; Canneal1.5750107737134256 and1.1677141998769665.
All three improve over frozen Correction (0.823714%,7.150332%,26.782313%).
PARSEC geometric means: Check/Native1.1409544124080222,
frozen Correction/Native1.5381132128814299, C1/Native1.4148218762996656,
C2/Native1.3487238460653828, C2/Check1.1821014331491617. BFS is excluded.
Exact source artifacts and validation summaries are retained in
`reference_results.json`; no simulation was relaunched to obtain them.

## Measured bottleneck and candidate A: buffer verified predecessors

C2 Streamcluster sampled ROI (3,440,640 cycles, 845 boundary cycles omitted):
freeze-set ingress blocked 927,272; legacy preservation pending 906,015;
capture pending 81,801; ACK outstanding 180,013; MSHR admission blocked 49;
MSHR active 6,664; refill beats 412; full SVB 119,594. Physical L1 misses244,
L2 misses239, MSHR-full0. These are overlapping exposures, not additive savings.
Checker captured-package instruction starvation208,339 and dependency1,218,064
are local checker cycles. Result-queue backpressure0. Four checkers are retained.

Saved SC8 observations cover only the early 98,939–973,685 main-cycle window:
219,174 pending cycles, of which 53,681 already-safe and 165,493 unsafe.
Within the safe exposure, WB already issued51,497, pending52,867, sent41,380.
Of826 observed descriptors,744 are already safe when first saved. Optional
suffix records were omitted; these are prefix observations, not whole-ROI
attribution. Whole-ROI safe-wait totals are unavailable.

`L1Preservation.allow` requires either a same-package image, or both a safe
predecessor and a lower-level preservation receipt. `dcache.scala` originally
offers the SVB snapshot path only for an unsafe predecessor; a safe-but-local
copy therefore freezes the L1 set through its normal writeback and ACK.
This is a proven immediate serialization condition; its whole-ROI avoidable
cost remains to be measured. Faster checker execution would address the
larger unsafe-wait component; merely enlarging L1 or MSHRs is unsupported here.

Candidate A extends the existing immutable snapshot path to already-safe
predecessors. A16-entry shared buffer separates L1 overwrite admission from
lower-level publication/ACK. No data capacity is added;16 `safeAtCapture`
state bits preserve these irrevocable publication obligations across flush,
epoch and later watermark changes. Normal load selection remains unchanged.
Already-safe bytes cannot be discarded before matching ACK or a complete
newer safe same-line image. Existing epoch-boundary cancellation, exact-key
fast-line leases, SourceC ownership and the full-buffer fallback remain live.
Coalescing transfers the irrevocable obligation to the complete safe successor;
it is suppressed during flush/invalidation. One additional drain-state bit
blocks new captures across an epoch/session boundary until all retained owners
have completed. This also handles reset reusing epoch/sequence values without
cross-session publication reordering. No extra data storage is introduced.

Potential gain is bounded by how much safe-copy waiting actually lies on the
critical path, not all906,015 pending cycles. Small-input screening is required
before a main-input run. Risks include promotion fairness, ordering across
epochs and safe-copy lifetime; directed emitted-RTL tests must cover these
before system simulation. No area/timing signoff exists.

## Recovery boundary

The inherited implementation has actual comparator/accepted-FAIL evidence but
no demonstrated architectural register/PC/memory restore/replay engine. Passing
the no-fault suite is performance validation only. Candidate A changes version
ownership: it cannot receive final recovery acceptance without an actual
historical-state restoration test. Component payload/ACK/flush tests are scoped
separately and will not be described as architectural rollback. Existing
recovery evidence is preserved in the validation worktree, not repeated.
The stricter C2 probe (`real_checker_fault_20261104_083111`) completed exit0
without any `RECOVERY_INJECT` record: its required simultaneous persistent
unsafe snapshot, positive watermark, WB_WAIT and active ARF comparison was
not exercised. It is a coverage failure, not a rollback pass.

## Rejected or deferred directions

Candidate A initial RTL (commit `bd9e71f67`, build
`overlap_safe_snapshot_a_20261104_104051_dad7186d`) was rejected before any
performance simulation. Actual emitted SVB test
`recovery_perf_20261104/build/svb_retention_12012c52/result.json` failed:
a version safe only after capture was discarded at a simultaneous flush.
The unused new simulator compilation was stopped; generated RTL/failure logs
are retained. Repair latches a publication obligation for every entry when
it becomes safe, and uses pre-edge safety to suppress flush/invalidation
deletion. Directed tests now require all already-verified predecessors to
survive invalidation/flush until coalescing or matching ACK, even when safety
arrives on the boundary edge. The next build has a different source key.

* Larger L1/more MSHRs: misses and admission blocking are too small on C2
  Streamcluster to justify making these the first target.
* More checkers: forbidden, and unnecessary for the proposed decoupling.
* Simply ignoring preservation/ACK: violates historical-data ownership.
* Removing dispatch drain during package sealing: can deadlock ROB draining
  against stalled retirement; not implemented.
* Treating full occupancy as lost cycles: C2 Canneal improved despite more
  full-SVB exposure; occupancy is not a counterfactual saving.
