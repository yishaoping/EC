# Opt4 overlap optimization — 2026-11-03

## Baseline and isolation

- Source base: `2ea467ba0`, functional Opt4 `476a76091`; frozen verifier PASS (626 checks).
- Private branch `opt4/perf-20261103`, worktree `/data1/gzh/EC-opt4-perf`. Original working tree unchanged.
- Native ROI 1,001,675; frozen Opt4 ROI 1,707,863; slowdown 1.705007113.
- Workload: pinned GAPBS BFS, 512 nodes/8192 edges/source 0; ELF da8897e790f0c5e91eff3e9560d2b0e7b4e1de6dff208788fb4d9e2ae462c81c.
- Four 100 MHz checkers, BOOM 200 MHz; L1D 32 KiB/2 ways/6 MSHRs; SVB16. No count/clock/cache capacity changes.

## Prior evidence recovered

Opt2b removed an EMPTY fetch handoff cycle; Opt3 fused classification with response capture (ROI 2,928,347). Opt4 added SVB16 plus same-line release ordering, stable snapshot capture and fast-line lease revocation. SVB expansion and promotion-only work have small fixed-trace envelopes (5,254 and 24,569 cycles). 64 KiB L1 experiment was reference-only (1,648,923), with incomplete strict pairing. SourceC waitAck bypass was only statically validated, never measured. Earlier instruction-wait totals are checker local cycles, not additive BOOM savings.

## Cache/version invariants reconstructed

L1 current image is selected by normal tags/data. The key contains content sequence, writer, generation and epoch. A younger same-line semantic overwrite of an unsafe predecessor first freezes/drains/copies its full image into a SPEC SVB entry. Demand loads never select SVB entries. Same-line writes may continue after capture; unrelated hits do not require watermark or global reclamation. If capture cannot proceed, the legacy preservation path waits.

SPEC becomes eligible only in the current epoch when its content sequence is at/below the safe watermark (or untracked/zero). Selection uses sequence and generation; an active WB entry is immutable and remains retained until matching ReleaseAck. Younger same-line release/probe cannot overtake retained predecessor, including WB_WAIT. Only superseded safe SPEC images can coalesce; flush/invalidation cannot discard an active WB owner. FAIL/CANCELLED are not PASS: only the contiguous accepted verification prefix advances the safe boundary; rollback invalidation/epoch rules remain authoritative. Watermark does not rewrite cache tags.

At L2, unsafe images cannot be exposed to non-image-aware clients or outer memory. Same-line safe dirty images must be checkpointed before overwrite unless already preserved. Checkpoint capture drains old bank work, reserves the target set, reads and emits a complete Put, then waits for a matching source/size/transaction AccessAck. Target set remains locked through terminal acknowledgement. SourceC's shared bank port is needed only for reads, never in pure waitAck. Unrelated safe victim releases can therefore overlap pure waitAck without changing retention or publication rules.

## Experiment 1 — overlap

Hypotheses: (1) release SourceC port/admission during pure checkpoint waitAck; (2) bypass checker READY register latency when an accepted S2 response can be classified and FQ accepts it, reserving a matching BJL head on that same accepted delivery. Existing registered/WAIT_BJL fallback handles backpressure and missing/mismatched BJL. Redirect/clear kill both paths; partial RVC tail updates only on FQ fire.

Validation and measurements: pending. Retain/reject decision: pending.

Build infrastructure: legacy sbt-git/JGit lacked linked-worktree support. Added only private gitdir config/worktree and refs/object links for this worktree; no main worktree configuration/source change. Private SBT boot cache copied; compiler targets are worktree-local. Existing 12 fast-line and 11 protocol CPU tests PASS. These are abstract/static tests, not RTL runtime validation.

First RTL-generation attempt stopped at a missing ignored EICG_wrapper.v resource before simulation. Restored six missing BlackBoxes from the frozen resource manifest, verifying every SHA256; recorded in restored_resources.json. The subsequent build uses those exact resources. Failed build/evidence retained.

The second generation (`overlap_direct_sourcec_20261103_011414_b7b6b2cc`)
reached FIRRTL and rejected a combinational loop in all four checker tiles:
flow-through FQ response valid -> Rocket redirect -> classification valid ->
direct FQ enqueue valid. No simulator started. Fixed by separating the owned
classification candidate from its non-redirect acceptance. FQ VALID is independent
of the same-cycle redirect, as on the existing READY path; IBuf kill/FQ reset
discard the killed response, and BJL reservation/state/handoff remain guarded.
The replacement run is `overlap_direct_sourcec_v2_20261103_012634_e6006f81`,
sealed before the next edit with binary SHA256
`7231109a15cf46429c32c08e4a0ec087451af2bb23f10790e998416445b092ec`.
The full pinned BFS run completed with checksum 43439728, zero FAIL/CANCELLED
results and assertions, and PASS for functional correctness, integrity,
same-line ordering, result protocol and mandatory evidence capture. Its ROI is
1,426,845 cycles: 1.424459x native, 281,018 cycles below the frozen 1,707,863
cycle Opt4 baseline. This clears 1.5x but remains above 1.3x.

SC48 closed with 1,436,548 traffic-window samples and passed phase, subset,
footer and producer conservation. Checker snapshots span most, but not all, of
ROI. Per-checker direct deliveries were 158,838, 141,582, 142,659 and 134,659;
WAIT_BJL deltas were 7,927, 16,913, 3,899 and 6,667 local cycles. These counters
describe checker-local activity, not additive BOOM savings. The combined
measurement cannot attribute the 281,018-cycle reduction between frontend
direct delivery and SourceC waitAck overlap. The L2 shadow model again fails
fidelity, so its geometry estimates remain ineligible for decisions.

## Follow-on work prepared during build

`CANDIDATE_AUDIT.md` records the completion/slot proof and a recovery issue that
prevents applying the safe-predecessor candidate as written. The existing exception
flush can discard safe SPEC snapshots before promotion, so broader dependence on
them requires its own retention proof/fix.

The LSU's older-`functional_inflight` gate also serializes stores through terminal
delivery, not merely physical data effect. The prepared `terminal_bypass.patch`
combines effect-edge terminal enqueue, native empty-queue flow-through, and an
identity-checked same-edge terminal bypass of that older-store barrier. All owner
release remains in the existing terminal handler; nack priority is preserved.
The simpler prepared completion-only patch is superseded by this combined candidate.
Neither is active in the v2 build.

## Follow-on candidate — validation in progress

After v2 sealed, combined the terminal-bypass audit, prefix+CFI fusion, and
two-word checker instruction fetch. Checker decode/retirement and all cache
geometries, line sizes, clocks and hart counts stay fixed. Added a bounded SC50
traffic-window snapshot for DCache terminal and LSU forwarding activity, plus
SC49 per-checker local-window snapshots. Capture remains below the existing
128-identity budget (127 expected). Nine completion-model tests and static
source checks pass; the actual IBuf randomized RTL test is still required before
the next full benchmark. Do not treat CPU model tests as RTL runtime evidence.

The actual emitted IBuf RTL passed at fetch widths 1 and 2 words (7,059 and
7,421 checked instructions, each with three kills and random backpressure).
The follow-on run is `overlap_terminal_fetch8_prefix_20261103_031553_2a566233`.
Scala/FIRRTL, combinational-loop checks, firtool and memory generation passed.
Generated configuration again matches frozen cache geometry and clock ratios.
The new binary started simulation around 11:50 local. Runtime result and
SC49/SC50 conservation remain pending; source/runner stayed unchanged until seal.

`prefix_cfi_fusion.patch` is another inactive candidate: if the first CFI has an
available matching BJL head, deliver its straight-line prefix and the CFI together,
using the existing IBuf end mask to carry reservation ownership. Otherwise retain
the existing prefix-only/WAIT_BJL fallback.

Nine CPU model/diagnostic tests PASS, including 1,024 backpressure schedules per
completion mode, full queues, same-slot blocking, response content, duplicate/SC/
cancellation handling, and corrupted/lost diagnostics rejection. These validate
the reduced contracts, not new RTL execution. `analyze_overlap.py` validates SC48
phase/window/producer conservation and reports checker-local cumulative deltas
only between saved snapshots. Baseline frontend deltas are saved separately;
their censored tail is explicit and cannot support full-window stall attribution.

Checker profile extraction corrected an analysis identity error: ECP epoch can
advance during a package, so SC11 is grouped by hart/sequence, with epoch retained
as observed metadata. Complete ROI packages: frozen 278 packages/570,177 checked
instructions; A 270/590,230. Priority-partition local cycles per instruction:

| Category | Frozen | A |
| --- | ---: | ---: |
| Instruction starvation | 2.09273 | 0.72672 |
| Issue available | 1.00018 | 1.00454 |
| Dependency | 0.00040 | 0.10235 |
| Setup/redirect/management | 0.15916 | 0.32014 |
| LSL wait | 0.00009 | 0.00212 |
| Other | 0 | 0.01904 |

Packages change as BOOM timing changes. These are normalized observations of
complete saved packages, not paired package traces or additive BOOM stall savings.
Every accepted start has zero counters; counters are monotonic and sum to the
execution partition. One ROI-boundary package and four incomplete captures are
excluded in both reports. The issue-available category is not retirement count.

Candidate C retains an acknowledged safe T-permission L1 copy instead of forcing
invalidation/refill. The audit is in CANDIDATE_AUDIT.md. Run A's 787 complete
observed traditional WBs expose 51,079 cycles before ACK plus invalidation/refill
work. Seven CPU protocol/diagnostic contracts pass. Build-only started as
`overlap_retained_copy_20261103_040650_0a6ef6bc`; no new full simulation launched
while B's outcome is pending. B hardware is staged independently; C remains an
unstaged delta so each measured milestone can be committed exactly.

Candidate C completed Scala/FIRRTL lowering, combination-loop checking, firtool
and memory generation. Generated geometry/clock comparison PASS. C++ simulator
build is in progress. The actual emitted WB RTL is byte-identical to B's unit;
the reproducible 300-publication/100-concurrent-probe RTL test also passes using
C's emitted unit. Top-level receipt retention is still unvalidated at runtime.

## Experiment 2 — validated below 1.3x

`overlap_terminal_fetch8_prefix_20261103_031553_2a566233` completed with ROI
1,174,774 cycles, slowdown 1.172809544. It saves 252,071 cycles (17.67%) from A
and 533,089 (31.21%) from frozen Opt4. Checksum 43439728 / verified=1, no FAIL,
CANCELLED or assertion. Integrity PASS (293 allocations, 291 completions,
1 coalesced, 1 flush-discarded). Same-line ordering PASS. Full protocol PASS:
7,438 releases and matching ACKs, no conflict/invalid ACK/outstanding source.
Generated clock/cache geometry comparison PASS. All 127 observer identities
and mandatory producer/footer evidence complete. Optional diagnostic limit omitted
731 examples; mandatory capture stayed complete. L2 shadow fidelity still FAIL.

SC48 phase/window/producer conservation PASS: 1,183,175 samples; reservation
54,648, waitAck 15,467, target lock 70,115; one release accepted during waitAck.
SC49 all four full local traffic-window state partitions PASS. SC50 PASS:
61,219 effects all enqueued their terminal on the effect edge; 55,667 also
completed terminal delivery that edge. 55,716 total empty-queue terminal bypasses;
39,196 younger store admissions occurred using an older accepted terminal.
No applied-S3 blocked cycles; 6,528 terminal queue blocked/occupied cycles.
These support exercised mechanisms, not isolated attribution of ROI savings.

Complete captured SC11 packages: 269 / 624,770 checked instructions. Local
priority cycles/instruction: starvation 0.02017, issue available 1.00501,
dependency 0.22094, setup/redirect/management 0.33373, LSL wait 0.00236,
other 0.03863; DCache/replay categories zero. Full captured admission-to-start
sum 13,619 local cycles (about 51 per package), result enqueue backpressure zero.
This does not identify the dependency/management categories as causal BOOM stalls.
It does show broad fetch bandwidth is no longer a strong next target on BFS.

The 851 completely observed B legacy copy-to-clear episodes include 55,505
WB-to-receipt and 851 receipt-to-clear cycles, plus the induced refill work.
Candidate C will test retaining the copied L1 image. Its hardware is the only
unstaged source delta; B staged hardware matches all six sealed source hashes.
Compact B source/seal/configuration/result/diagnostics/profiles are saved under
`results/terminal_fetch8_prefix/`.

B's exact staged hardware was rechecked against every source hash in its binary
seal and committed with compact evidence as `40c8a18ca`. C was excluded from that
commit. C completed the C++ build, with binary SHA256
`66ab0661ba28dc040cc2fb6dae6bf5f6be6d21ed4bf035a94861dff7c9110e6a`
(43,281,728 bytes). Unchanged source/runner/HEAD was verified before resume and
the exclusive simulation-start marker was created before committing B. The
end-to-end C simulation is in progress; no performance claim is made yet.

## Experiment 3 — retain the acknowledged copy, accepted

`overlap_retained_copy_20261103_040650_0a6ef6bc` completed with ROI start 579,235,
stop 1,707,287 and 1,128,052 cycles: **1.126165672x** native. C saves another
46,722 cycles (3.977%) from B, for a cumulative 579,811 (33.950%) reduction from
frozen Opt4. Excess overhead versus native falls from 706,188 to 126,377 cycles,
an 82.104% reduction. Retain C. Four checker cores, clocks, all cache geometries,
line sizes, SVB16 and existing version/result/ownership requirements are preserved.

Checksum 43439728 / verified=1; no assertion, FAIL or CANCELLED. Integrity PASS:
373 allocations close as 368 completed, three coalesced and two flush-discarded.
Same-line generation ordering PASS. Full-run ACK protocol PASS: 7,381 releases
and matching ACKs, zero conflicts/invalid ACK/outstanding source at exit.
All 128 observer and producer identities close; mandatory capture complete with
no incomplete reasons. Optional diagnostic loss is explicit (538 examples).
SC48–51 window, phase, state, subset and producer/footer conservation PASS.
Generated clock/cache comparison PASS. Source patch, every hardware source hash
and simulator binary hash were rechecked after measurement. L1/L2 shadow-model
fidelity still FAIL, so derived geometry estimates remain excluded.

SC51's complete traffic window counts 859 traditional preservation requests,
all T-to-T, with 859 matching retained receipts and zero invalidating clears,
owner mismatches or same-edge probe revocations. Optional SC8 observes 858 complete
WB-to-receipt intervals totaling 55,514 cycles, with no invalidating clear and a
14,809-cycle censored tail. These are activity/exposure observations; the measured
46,722-cycle incremental gain is the whole candidate's ROI result, not a sum of
those phases. Top-level probe revocation and rollback are not exercised here.

SC50 counts 61,219 physical effects, all with effect-edge terminal enqueue;
55,601 also deliver on the effect edge. Terminal enqueue/deliver both 61,268,
applied-S3 blocked zero, queued/blocked 6,588 cycles, accepted terminal forwarding
61,268, forwarded successor admissions 39,364. Candidate older-inflight cycles
decrease from B's 274,254 to 216,282. These predicates overlap ordinary pipeline,
preservation, scheduling and response activity; they are not isolated lost cycles.
SC48 records three releases accepted during waitAck. All L1/L2 MSHR-full counts
are zero; final checker ICache acquires are 26/18/21/30, TLB miss zero.

275 fully captured ROI packages contain 633,972 checked instructions. One crossing
package and three incomplete captures are excluded. Checker-local priority cycles
per instruction: starvation 0.020782, issue available 1.005205, dependency 0.219852,
setup/redirect/management 0.309236, LSL wait 0.002486, other 0.038079; DCache/replay
zero. Captured admission-to-start totals 13,860 local cycles (~50/package), result
queue backpressure zero. Changed package boundaries preclude paired-trace claims.

Current stopping decision: retain measured C without speculative gate removal.
The requested below-1.3x target is exceeded, including a further measured cache
improvement after B. Further fetch/cache/count scaling has weak evidence. More
store issue overlap remains plausible but needs a new proof and focused RTL
coverage for nack ordering, same-slot image generations, S3 turnover, probes,
replay and exact terminal ownership; existing overlapping counters alone do not
justify deleting the barrier. Management/dependency optimization needs finer
attribution first. No additional full benchmark is launched without that evidence.

Compact exact/incremental patches, source/binary seals, run manifest, configuration,
ROI, capture, protocol/integrity results and profiles are in `results/retained_copy/`.
Full run/build artifacts remain in their private ignored directories. The main/FPGA
tree and its processes were not altered.
