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
