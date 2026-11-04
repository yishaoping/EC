# Measured mechanism and recovery acceptance — 2026-11-04

Candidate 1 is a substantial performance milestone: Canneal project400 falls
from 668,878 to 548,437 application ROI cycles (18.006423%). Its hardware commit
is `2b0ea7ff07be09447a1f540c8682b85d15b4a82f`. Candidate 2 already combines this
change with full-SVB fallback rescue, commit
`ae0d80a65a5d890b59e4c67575c0cb6af59730ae`. Its completed Canneal result is
489,737 cycles, 1.167714200 Correction/Check: 26.782313% below the frozen baseline
and 10.703144% below Candidate 1. Remaining workload results must come from the
existing suite, not extrapolation.

## Input and comparison boundary

The measured 2.1983% pilot is **Streamcluster simdev**, not a Canneal small-input
run: 1,452,774 → 1,420,838 cycles with the same 1,094,668 application instructions.
No measured small-input Canneal comparison exists in these artifacts. Thus the
claim that *Canneal* grows from 2.20% to 18.01% is not supported. What can be
explained is why checker ICache enlargement benefits these workloads differently.
The fixed Streamcluster project64 improvement is 4.291014%.

All PARSEC comparisons use their existing matching ELF, input, configuration,
application-only ROI, output and application instruction count. Native/Check
denominators remain frozen. Four checkers and the 200/100 MHz frequency ratio
are unchanged. BFS retains its pinned ELF, 512 nodes/8,192 edges/source 0,
checksum 43,439,728 and Native denominator 1,001,675. There is no matching frozen
BFS Check-only denominator in this evaluation; it must be reported N/A.

## Supported causal chain for Candidate 1

The functional change is checker ICache 32 sets × 1 way (2 KiB) → 32 × 2
(4 KiB), adding 8 KiB across four checkers plus tags. BOOM data-cache geometry,
SVB capacity, safe-watermark rules and ACK ownership are unchanged. Capacity
and associativity changed together; these measurements do not separate them.

| Observed metric, frozen → Candidate 1 | Canneal project400 | Streamcluster project64 |
|---|---:|---:|
| Four-checker ICache acquisitions | 11,939 → 2,184 | 11,757 → 2,774 |
| Checker frontend empty local cycles, traffic window | 167,819 → 60,847 | 168,124 → 74,404 |
| Physical L1 data misses | 8,707 → 8,276 | 233 → 225 |
| Physical L1 replacements | 3,138 → 3,050 | 69 → 59 |
| Physical L1 set-full misses | 5,429 → 5,040 | 41 → 34 |
| Physical L2 misses | 1,292 → 1,289 | 237 → 240 |
| L1 MSHR-full cycles | 225 → 333 | 0 → 0 |
| SVB occupancy >8 cycles | 346,747 → 266,939 | 490,769 → 383,368 |
| SVB fully occupied cycles | 47,718 → 50,920 | 90,590 → 72,547 |
| SourceC wait-ACK cycles | 19,894 → 19,147 | 36,934 → 35,933 |

These physical counters use each recorded traffic window, including preparation;
they are not all application ROI counters. Checker cycles are local checker
cycles. Overlapping counters must never be added as saved BOOM cycles.

Canneal's complete captured in-ROI checker package starvation decreases from
268,029 to 104,083 local cycles; full-session checker active cycles decrease
927,650 → 724,618. Application instructions remain 392,248, and all 139/129
timing-dependent package results have complete checker-work accounting. The
package-count difference is not skipped checking.

Matched complete SC1/3/4/6/8 streams classify Canneal's preservation waits:

| Main-cycle exposure | Frozen | Candidate 1 |
|---|---:|---:|
| Required result not yet available | 118,043 | 51,403 |
| Of which checker execution/tail not complete | 116,989 | 50,743 |
| Of which formed result/cleanup/transport | 1,054 | 660 |
| Post-safe wait | 36,778 | 33,154 |
| Multiple causes | 3,148 | 3,092 |
| Prefix propagation | 17 | 11 |

This strongly supports: fewer checker instruction refills/starvation → earlier
verification completion → shorter unsafe-version preservation waits. The
changed cache and result counters support this chain; no claim is made that
all 120,441 saved ROI cycles belong to one counter. Max SVB occupancy remains
16, max same-line depth remains 4, and full occupancy actually increases.
SourceC ACK reduction of 747 cycles cannot explain the large ROI gain.
Protected-way-specific conflict reduction is unproven; set-full misses do not
identify protected ways.

The Streamcluster simdev pilot also reduces acquisitions 10,207 → 2,209 and
frontend empty local cycles 144,023 → 59,737, yet its legacy preservation
pending exposure remains 480,964 → 474,975 sampled main cycles. Faster fetch
therefore shortens a smaller part of its critical path. This supports workload
dependence, not an invented Canneal input-size mechanism. Project64 optional
state streams are incomplete: the detailed wait classifier returns N/A, and no
missing values are replaced by zero.

## Candidate 2's measured rescue mechanism

The completed Canneal run records 30 actual in-ROI rescue handoffs. Compared
with Candidate 1, sampled freeze-set ingress blocking decreases
82,438 → 53,080; legacy-preservation pending 87,087 → 57,841; MSHR admission
blocking 15,902 → 2,755; MSHR-active exposure 231,720 → 193,275. Sampling covers
546,816/488,448 cycles, omitting 1,621/1,289 ROI boundary cycles respectively.
These are exposures and do not sum to the 58,700 saved ROI cycles. Refills
increase 6,180 → 6,264, ACK-pending exposure increases 88,928 → 91,442 and
SVB-full exposure increases 50,920 → 79,359. The benefit is supported by the
rescue handoff and blocking counters, not fewer refills or less full occupancy.

Before performance testing, emitted Candidate 2 admission tests (20,025
vectors), pulse tests (10 cases/353 checks), and epoch tests (73 cases/2,818
checks) passed. The SVB and writeback modules are byte-identical to Candidate 1.
This is meaningful control-path validation; it does not prove rollback.

## Actual injected failure: recovery acceptance blocked

New private harness evidence:
`build/real_checker_fault_20261104_081702/` in the isolated validation worktree.
The harness links the original Candidate 1 model archive/objects read-only;
only a new emulator object and private executable are built. Active Candidate 2
sources, objects, executable and simulation are untouched. Assertions remain
enabled. Injection flips bit 0 of checker hart 1's captured integer register 31;
it does not force result status, comparator output, watermark, ACK or cache data.

Time below is the private emulator loop tick, one full top-level low/high clock
iteration. It is not a checker-local cycle. Injection waits for an unsafe SPEC
entry to persist at least 1,024 ticks, with matching line/sequence/generation.
At injection, all 16 slots are valid; versions of the same lines with different
sequence/generation and their exact 64-byte payloads are recorded.

| Harness tick | Direct observation |
|---:|---|
| 107,179 | Hart 1, package 1, x31 snapshot `0x823 → 0x822`; safe watermark 0 |
| 107,241 | Real checker `compare_error_accum` asserted |
| 107,304 | Real DCache accepted failure edge; sticky failed sequence becomes 1 |
| 107,304 | All 16 pre-existing SPEC slots invalidated; their sequences are 1 or 2, above safe watermark 0; flush=0 |
| 111,400 | Probe ends after 4,096 further ticks; historical restoration unproven |

The post-FAIL log also records `CACHE_HANG_SNAPSHOT reason=PRESERVATION_WAIT`
with the unsafe sequence still 1 and safe watermark still 0. This is direct
evidence that the failed package cannot satisfy its normal preservation gate;
it is not evidence of a successful recovery transition.

The first sampled bad snapshot is a checker-state fault and may leave main
architectural data correct; therefore correct surviving program output would
not be a historical-memory restoration oracle. The test proves genuine
detection and accepted FAIL with persistent data present. It **does not prove
rollback**, nor does invalidating unsafe versions alone prove that a safe copy
was lost. The safe-copy provenance and an architectural memory/register/PC
restore path must be established separately before acceptance.

The source audit explains the missing proof:

* `speculative-version-buffer.scala:51` exposes capture/promotion/invalidate/
  flush/ACK, but no recovery lookup/read/restore port. Ordinary loads do not
  select SVB entries. `:242` assigns `recoveryFromSvb := io.acked`, counting
  successful promotion ACK, not historical restoration.
* `dcache.scala:2662–2695` turns actual FAIL/CANCEL into sticky failure, invalidates
  SPEC entries newer than the safe watermark and informs the L2 barrier. The
  failed package blocks the contiguous safe watermark.
* `InclusiveCache.scala:300` turns failure into barrier error; the ordinary
  unsafe barrier is released only after its sequence becomes safe. This audit
  finds no historical data replay path on that edge.
* BOOM's `core.scala:2066–2075` synchronizes L2 barrier error. The audited
  `l2BarrierErrorAny` has no downstream use. Existing ROB rollback machinery
  handles ordinary speculation; it is not connected here to checker FAIL.

Existing emitted-SVB tests are reused rather than rerun: persistent unsafe
versions for 1,024 cycles; delayed promotion/ACK for 1,024 cycles; WB_WAIT payload
and ownership through flush/epoch; same-line versions for 512 cycles;
safe-watermark invalidation boundaries; exact-key ACK reclamation; deliberate
wrong-key and wrong-entry ACK assertions. Evidence:
`candidates/svb_retention_test.json`, driver SHA256
`3e4b62d57436b5b311c48cb1b9eb7c9c411adf02f38653de5157422616f63423`;
SVB emitted SHA256
`a9543c2c3bf0bd8d678e5ff5dc4ba737625f8605208c5ab0072d17b9feaaec5b`.
These component boundary checks pass. They do not establish safe-point memory
restoration, register/PC rollback, fault replay, or end-to-end flush recovery.
SPEC flush invalidates SPEC entries by design; WB_WAIT remains until ACK.

Acceptance status: **BLOCKED — no demonstrated architectural restore/replay**.
Performance candidates remain valuable milestones, but neither is promoted as
a validated recovery implementation. Original baseline preservation is not
evidence that its recovery architecture is complete either.

## Next architectural priorities

Correctness first: specify the safe checkpoint (PC/registers plus memory image),
its ownership and lifetime through outstanding writes/ACK, how FAIL freezes
younger execution/publication, how historical lines are located and restored,
how speculative cache/L2 state is revoked, and when checkpoint/version storage
may be reclaimed. Add a deterministic historical-data oracle with corrupted
main-core data and verified post-rollback replay. Do not fix this by suppressing
FAIL, advancing the watermark, dropping ACK ownership or increasing checkers.

Performance next: Candidate 2 Canneal is already below 1.2× Check. Streamcluster
is the higher-priority target if its full regression remains above 1.4×.
Candidate 1 project64 samples show 1,039,348 freeze-ingress cycles and 1,024,837
legacy-preservation pending cycles out of 3,547,136 sampled cycles (overlapping,
about 29%), while refills are only 416, MSHR-active 6,660 and admission-block 51.
Prioritize decoupling preservation capture/ownership and package sealing from
set-wide LSU freezing, with a bounded versioned queue and explicit ACK/recovery
ownership. First instrument complete result/tail reasons for Streamcluster;
current optional streams cannot separate execution, sealing and cleanup waits.
Naively letting dispatch run during a required ROB drain can deadlock sealing
against transfer/retirement; preserve the drain ordering in any experiment.
Larger DCache, more MSHRs and small SourceC tweaks lack evidence of comparable
impact on this workload. C2's pending Streamcluster result determines how much
of this bottleneck the rescue already removes.
