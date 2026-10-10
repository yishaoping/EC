# EC/Chipyard Debug Handoff (2026-10-08)

## Evidence boundary and current status

This document is a handoff of the conclusions that are supported by the
current source tree and the saved Debug artifacts. The repository is a live
Debug worktree. It contains unstaged source changes, untracked Debug traces and
reports, and must not be reset, checked out, cleaned, stashed, or committed.

The latest available run is:

- log: `chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.log`
- output: `chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.out`
- waveform: `chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd`
- failure: `[528000] ... assert__assert_22: little core 1 has hung`
- source location reported by the log: `core.scala:2154`

The latest log does **not** contain a new first-bad-state trace. It proves the
528000 watchdog symptom only. Do not reuse the 459000 or 461000 first-bad cycle
as a fact about this latest run. The current `.vcd` file has FST contents even
though its suffix is `.vcd`; historical traces commonly have approximately a
2:1 FST-time to BOOM-log-cycle ratio, but that conversion is run-specific and
must be re-established before using it.

At the time of writing, `git status --short` shows 21 modified tracked files,
about 1155 inserted and 127 deleted lines in the tracked diff, and many
untracked Debug artifacts. The staged diff is empty. The two documentation
files (`Doc/Run/Run.typ` and `Experiment/流量分析.typ`) are experiment/report
changes and are not hardware evidence.

The saved Debug notes report that the generated collateral associated with the
latest unbarriered run has `GH_REAL_BARRIER_ENABLED=false` and folds the L2
barrier request to zero. Barrier-enabled numbers in the historical `.typ`
reports therefore cannot be compared directly with this `test.vcd` unless the
software image and generated RTL are first shown to be identical apart from
that setting.

No source was changed while preparing this handoff. No simulation, RTL
generation, elaboration, or synthesis was run in this handoff turn.

## System model and invariants

The design is one BOOM large core with Rocket checker cores connected through
GuardianCouncil structures and CDC paths, sharing an inclusive L2. The useful
logical path is:

```text
BOOM architectural commit
  -> GH_BUF/GHM and CDC
  -> Rocket RSU/RSUSL/LSL
  -> instruction, data, ARF and CSR comparison
  -> result and safe packet watermark
  -> BOOM package ownership release
```

The following boundaries are essential:

1. BOOM ROB retirement is architectural/committed state. An invalid ROB head
   slot contains stale storage and is not a valid next PC. A speculative branch
   redirect, a DCache S2/S3 request, an MSHR state, and a TileLink handshake are
   not architectural retirement events.
2. A package needs a stable, nonzero sequence and one owner. Allocation,
   snapshot ARF/PC capture, commit records, LSQ entries, CDC records, checker
   replay, result acceptance and ownership release must refer to that same
   sequence. LDQ/STQ entries must retain their own sequence and traffic-window
   qualification; retirement must not resample a live global sequence.
3. A checker result is released only after data, ARF/CSR, instruction tail,
   LSL, CDC ingress and outstanding physical transactions satisfy their tail
   conditions. PASS, barrier close ACK, result dequeue, and safe watermark
   advancement are distinct events.
4. `SyncReadMem` is a two-stage protocol: launch a read, register and hold its
   payload, compare it, then dequeue. `ready` means permission to accept a
   transaction; only `valid && ready` is fire. A nonempty FIFO or an ACK does
   not prove that a response or all outstanding TL transactions exist.
5. Replay/nack paths preserve request identity. A strict store completion is a
   once-only event associated with a committed store token, not an unqualified
   physical write pulse. A reused STQ index alone cannot identify a request.
6. Barrier close must close the relevant package while allowing the normal
   package lifecycle to continue. L1/L2 barrier state, TL C-channel completion,
   metadata clearing, safe watermark, checker PASS and BOOM release cannot be
   substituted for one another.
7. A completion predicate must not feed checker mode, stall, kill, or pipeline
   valid through a same-cycle combinational path back into itself. Any quiet or
   tail condition that depends on live ROB/RSU/FIFO state must be registered or
   otherwise kept outside the feedback path.

## Main bugs and their status

### 1. Package ownership and sequence-0 events (2026-09-30)

**Failure.** The 254-package run reported `ADDRESS_STATS status=FAIL valid=0
error=0x10`; an address event occurred before a valid `packet_alloc_valid` and
carried sequence zero. Earlier code also sampled the live active sequence when
an older LDQ/STQ entry finally retired.

**First bad state and chain.** Address-statistics traffic became enabled just
before the first valid allocation (saved evidence around VCD/FST 383639-383663).
Events with no package owner entered `PackageAddressStats`, and later retired
entries could inherit a newer package's global sequence:

```text
traffic window opens before package ownership
  -> sequence-0 or stale live-sequence LSQ event
  -> malformed address event / wrong package attribution
  -> address statistics stop with error 0x10 and package totals diverge
```

**Fix implemented.** LDQ/STQ entries received packet-sequence fields and
traffic-scope ownership. The sequence is captured at the entry/translation
boundary and reused at retirement; zero/unowned operations do not become
package-owned events. The active sequence mux retains allocation priority and
does not make a retired entry sample a later global package.

**Validation.** BOOM compile, `git diff --check`, and the repository invariant
script passed. The saved 259-package run later showed balanced package results;
runtime validation of all sequence paths must still be repeated with the latest
RTL.

### 2. Address-statistics watermark boundary (`error=0x10`)

**Failure.** In the 259-package run, allocations/completions/PASS were all
259, but a same-package tail store arrived after the checker safe watermark had
already advanced to that same sequence. The event was rejected by the old
`packetSeq <= safeWatermark` test. The first malformed event was around FST
1062091; its address/size did not cross a cache line and its sequence was
explicitly `0x62`, not zero.

**Root cause and chain.** Checker PASS/safe-watermark advancement is not proof
that BOOM has retired every LSQ entry carrying that package:

```text
checker PASS seq 0x62 -> safeWatermark=0x62
  -> BOOM tail store seq 0x62 commits later
  -> old <= test calls a legal same-package tail malformed
  -> address statistics become invalid and are permanently stopped
```

**Fix implemented.** `PackageAddressStats.scala` changed the stale test to
strictly earlier (`packetSeq < safeWatermark`). LSQ-latched sequence ownership
was retained. This preserves rejection of genuinely older events.

**Validation.** Compile/static checks passed; a post-fix full runtime proving
`ADDRESS_STATS valid=1,error=0` with the latest worktree is not present here.

### 3. Barrier package lifecycle and traffic-window undercount

**Failure.** The barrier-enabled report showed the same benchmark instruction
count but approximately 3713 stores/32 packages versus approximately 60570
stores/279 packages in the comparison record. A second run showed BOOM/checker
window deltas such as `61299 vs 60587` stores and `84940 vs 82691` loads.

**Root cause.** Two separate boundary mistakes were identified:

- `R_IC` used the barrier close path as `ctrl=3`, which is full checker-session
  exit. The state machine skipped normal package scheduling/snapshot flow, so a
  close could stop subsequent package allocation.
- BOOM ordinary architectural traffic qualification was tied to
  `traffic_counting && traffic_check_state`, where `traffic_check_state` meant
  only R_IC `fsm_check`. A real barrier moves R_IC through postcheck/cooling
  while BOOM can still retire the package tail, so valid tail stores/loads were
  omitted.

**Fix implemented.** Barrier close is kept distinct from true session exit and
continues the normal package lifecycle. Ordinary BOOM load/store accounting is
controlled by the measurement window and stable LSQ ownership, while checker
state remains available for checker/package-specific traffic qualification.
`R_ICSL` checker counting is limited to package-owned checking and postchecking
states so setup/nonchecking instructions are excluded while package tails are
retained.

**Validation.** Static compile and invariant checks passed. The historical
open/closed barrier numbers were not a strict same-binary/same-generated-RTL
A/B; they must not be treated as a performance conclusion. The latest run has
no barrier-specific summary in `test.log`.

### 4. Cross-package L1/L2 coherence and shadow writeback

**Failure.** A `verified=0` run had a wrong parent checksum while package result
counts were balanced. The waveform showed a shadow writeback C-channel
permission of `000` (`TtoB`) followed by local metadata reset to `Nothing`, and
also showed a second writeback request overlapping the metadata-clear window.

**Broken protocol.** L2 was told that the client retained Branch permission
while BOOM had invalidated its local line. Separately, a writeback completion
cleared the issued bit before metadata clear, allowing the same line to be
accepted again:

```text
cross-package dirty overwrite
  -> wrong TtoB permission / local Nothing mismatch
  -> metadata-clear and reissue overlap
  -> stale/duplicated line ownership
  -> corrupted parent[] data and verified=0
```

**Fix implemented.** The shadow writeback sends `TLPermissions.TtoN`; request
valid is suppressed while metadata clear is pending; writeback completion,
writeback-unit idle, metadata clear fire, and blocked-line release are kept in
that order. The fix does not turn result-count equality into data correctness.

**Validation.** Static/compile records report success. The saved follow-up
notes report C-channel `param=001` and no reissue during metadata clear in the
available waveform, but the latest 528000 run has not been analyzed for the
full coherence chain.

### 5. Strict-store completion underflow and identity

**Failure.** A strict-store completion assertion occurred around log 198000
(FST about 396351-396353). An architectural store incremented the in-flight
count, then a replay/refill physical write produced an extra completion without
an architectural store identity.

**Root cause.** A physical data-array write is not inherently one architectural
store completion. Replays, delayed writes, STQ reuse and traffic reset can all
produce an unqualified or stale physical event.

**Fix implemented.** A token is allocated at architectural store commit,
propagated through DCache/MSHR/RPQ/replay, and consumed exactly once at a
matching physical completion. Exception/branch kill/STQ reuse/window reset
invalidate it. STQ reclamation waits for token completion where required.

**Validation.** `scalac` parser, BOOM compile, and diff checks passed. Runtime
must still prove one completion per token under replay/nack/reset overlap.

### 6. Killed-store replay and STQ execute-head ordering

**Failure.** Historical runs produced a sustained replay/nack loop and an STQ
`stq_execute_head` assertion around logs 728000 and 1181000.

**First bad states.** In one run an older S2 store nack killed a younger S1
request after LSU had already reported a request fire. In another, a late nack
rewound the execute head to an already completed/reclaimed STQ entry. The
necessary invariant was that a fire must retain the request or replay it, and a
late nack must match a live, unfinished entry.

**Fix implemented.** DCache captures the exact killed S1 store with its address,
uop, STQ index, packet sequence, strict token and traffic metadata, blocks
overwriting the one-entry replay slot, and replays it once. `storeNackMatchesLiveStq`
guards nack-driven execute-head rollback by slot validity, success state and
strict-token identity. Completion of the execute-head entry advances that head
only when the matching token completion is accepted; completion and nack
priority is explicit.

**Validation.** Compile/static checks passed. The saved notes require runtime
confirmation that each replay fires once, S2/S3 completion occurs once, and the
token is consumed once. Do not weaken the STQ assertion or saturate counters.

### 7. Snapshot/ARF boundary and combinational loop

**Original failure.** A d7 checker mismatch around FST 2836357-2848129 showed
R_RSU captured x12=`0x2b`, then BOOM committed `addi a2,a2,-1`, while the checker
observed `0x2c`. `can_commit_withoutGC` meant that the current ROB head could
commit; it did not mean the ROB was empty or that no commit could appear in the
next cycle.

**Root cause and chain.**

```text
can_commit/short quiet pulse
  -> snapshot accepted while old ROB state can still retire
  -> delayed R_RSU ARF capture is one commit behind
  -> ARF/ECP mismatch
  -> package fails; safe watermark stops
  -> cross-package store/replay and ROB stall amplify the failure
```

The first attempted snapshot guard also made a FIRRTL combinational loop:

```text
ROB commit valid
 -> snapshot quiet -> R_IC snapshot -> R_RSU hang/stall
 -> ROB gh_stall -> ROB commit valid
```

**Fix implemented.** Snapshot readiness requires empty ROB, a valid committed
next PC, registered quiet guards and an armed full-cycle readiness observation.
New dispatch is held while the ROB drains and delayed R_RSU capture completes;
existing committed entries may retire during the drain. Live commit/RSU/CSR
signals are not fed directly back into snapshot admission. `R_IC` allocation
outputs were also made an explicitly held/register-aligned handshake in the
related package-boundary fix.

**Validation.** Compile/static checks passed and the loop was directly reported
and then removed from the source dependency. The latest 528000 log does not
prove that all snapshot boundaries are correct; the latest first bad state is
still unknown.

### 8. Empty ROB stale-head PC

**Failure.** In the 459000 reanalysis, FST 393085 showed `ROB empty=1` with
invalid head slots but `rob.io_r_next_pc=0x800004ac`, the stale PC of a load that
had already retired. R_RSU latched that PC at 393095; BOOM's actual next valid
path was `0x80000368` at 393097 onward. Rocket replayed the retired load and
then issued a memory request that did not match the package's first store
stream.

**Root cause.** The first snapshot fix made the ROB empty boundary stricter but
left `r_next_pc` unconditionally reading the current head slot. Empty ROB is
not equivalent to valid head PC.

**Fix implemented.** `rob.scala` now tracks an explicit architectural next-PC
register and validity bit updated by committed uops/architectural redirects;
invalid head entries are gated. `core.scala` requires `r_next_pc_valid` for
snapshot admission and passes the architectural redirect information to the
ROB. This separates committed continuation state from speculative/invalid ROB
storage.

**Validation.** The source and generated/current reports support the diagnosis
and compile checks passed. The latest 528000 waveform has not been traced to
confirm the invariant at its current failure.

### 9. R_LSL wrong-type dequeue and synchronous FIFO deadlock

**Historical 461000 failure.** The old R_LSL dequeue condition required only
request valid, nonempty FIFO and no kill. A checker load consumed a store FIFO
head around FST 393657; ELU raised `error_ld`, the package was cancelled, the
safe watermark stopped, DCache cross-package requests blocked, and the BOOM
watchdog eventually fired.

**First attempted fix.** R_LSL added request type/address matching and refused
to consume a mismatching head. That correctly removed the unsafe store-for-load
consumption but put the match in the same condition that enabled
`SyncReadMem.read`, creating:

```text
head match needed for ready
  -> ready enables SyncReadMem read
  -> read is needed to obtain head for match
```

This produced the 459000 checker hang: FIFO `empty=0`, but no read/dequeue/fire,
no checker result and no ownership clear.

**Second fix implemented.** `GH_MemFIFO` exposes separate `deq_read` and
`deq_read_valid`. `R_LSL` adds per-bank prefetch-pending, registered head
payload/valid, match checks and a registered response packet. `deq_read` launches
the RAM read; only matching `deq_ready` advances the FIFO. Mismatch is reported
through ELU and does not consume the head. `RocketCore` uses LSL `quiescent` for
package cleanup and completion gating.

**Important unresolved risk.** The saved 459000 reanalysis found that
`selected_head` still reads the raw `SyncReadMem` output while
`lsl_head_valid` remains set. If the RAM output is not guaranteed stable after
read-enable deasserts, valid and payload can diverge again. This is a protocol
and timing risk, not a conclusion about the latest 528000 run. It must be
checked with the generated RAM semantics and a focused waveform.

**Validation.** Rocketchip/Chipyard compile and diff checks passed. An earlier
generation attempt failed with a FIRRTL `NumberFormatException` caused by a
dynamic `dontTouch` target; that issue was handled as described below. No saved
post-fix full runtime proves the LSL protocol for all mismatch/replay cases.

### 10. R_ICSL tail completion and package-release loop

**Failure/tool symptom.** FIRRTL reported a combinational loop through
`package_exec_completion -> checker mode/stall -> Rocket pipeline valid/inflight
-> package_exec_completion`.

**Fix implemented.** `R_ICSL` adds registered `instruction_tail_waiting`, clears
it on reset/cancel/package completion, sets it at the instruction boundary, and
uses it to suppress overtake/replay while waiting. `RocketCore` gates package
tail completion on a sequence-qualified BOOM producer seal, drained CDC ingress,
LSL quiescence and ARF/data completion. A BOOM tile-side sticky producer seal
also waits for GH_BUF filters to drain before crossing to checkers.

**Validation.** The source-level combinational feedback is cut and the affected
Scala compile was reported successful. Runtime behavior for self-exception in
the same cycle as the boundary, xRET restoration, overtake/replay, and the
latest 528000 run remains unconfirmed.

## Current Git diff: purpose and validation level

### BOOM files

- `exu/core.scala`: snapshot quiet/empty/armed/drain logic; architectural
  next-PC and producer-seal integration; L2 barrier request/close sideband;
  common watchdog bit; DCache/LSU traffic and debug probes. The snapshot and
  barrier changes are functional, not merely probes.
- `exu/rob.scala`: explicit committed next-PC register/valid bit and invalid
  head gating. This is the direct fix for stale empty-head PC.
- `lsu/lsu.scala`: per-LSQ packet/traffic ownership, strict store tokens,
  completion matching, killed-store/nack/replay and STQ pointer protection,
  ordinary traffic-window accounting, and diagnostics.
- `lsu/dcache.scala`: token/replay metadata through S0-S3/MSHR, killed-store
  compensation, cross-package blocking and serialized shadow writeback,
  `TtoN`, safe-watermark and barrier probes/statistics.
- `lsu/PackageAddressStats.scala`: same-sequence tail events accepted by changing
  stale comparison from `<=` to `<`.
- `common/tile.scala`: BOOM tile producer-seal crossing and traffic-window
  semantic comments/wiring.

### Rocket/GuardianCouncil files

- `R_IC.scala`: snapshot/barrier FSM, package allocation alignment, close versus
  true session exit, and boundary probes.
- `R_ICSL.scala`: package-tail/instruction-tail state, checker traffic window,
  registered loop break, and new FIFO read connection.
- `R_LSL.scala`: FIFO prefetch/read/dequeue separation, type/address matching,
  mismatch response, quiescent state and debug probes.
- `GH_FIFO.scala`: synchronous memory FIFO `deq_read` and response-valid
  interface; ordinary FIFO behavior remains intended to be unchanged.
- `R_ELU.scala`, `R_RSU.scala`, `R_RSUSL.scala`: mismatch and new FIFO-read
  connections plus snapshot/FIFO probes.
- `RocketCore.scala`: LSL mismatch wiring and package completion gate joining
  producer seal, CDC drain, ARF/data completion and LSL quiescence.
- `GHM.scala`, `HasTiles.scala`, `BaseTile.scala`, `Core.scala`,
  `RocketTile.scala`: result/CDC and producer-seal bridge wiring across tile and
  hart boundaries.

### What has and has not been proven

The following have direct source plus saved waveform/tool support in at least
one historical run: stale empty-head PC, wrong-type LSL dequeue, synchronous
FIFO deadlock, snapshot combinational loop, package sequence ownership errors,
watermark equality error, shadow-writeback permission/reissue errors, strict
store identity errors, killed-store replay alignment, and barrier traffic-window
qualification.

Compile records exist for the current source changes (BOOM/Rocket/Chipyard
compile passes are recorded in the Debug notes). This is not equivalent to
latest elaboration, generated RTL, or runtime validation. The current
`test.log` only proves that the current run reached 528000 and hit the checker
watchdog. It does not prove whether the old first bad states disappeared, nor
whether the producer-seal and LSL payload fixes are correct in this run.

## Hypotheses already ruled out or not to repeat blindly

- Watchdog time is a symptom/amplifier; changing its bit only changes when the
  run stops.
- Equal package allocation/completion/PASS counts do not prove checker saw all
  instructions or that memory coherence is correct.
- A barrier ACK is not PASS and is not proof that all outstanding TileLink
  transactions are complete.
- `ROB empty` does not make the current head `debug_pc` valid.
- `can_commit_withoutGC` means a head can commit; it does not mean ROB empty.
- FIFO `empty=0` does not mean a synchronous RAM payload is currently valid.
- `ready=1` is not fire; response fields must be held until the matching
  handshake.
- L1/L2 latency buckets only measure events; they cannot absorb, postpone or
  complete a missing hardware request.
- The 259-package `error=0x10` was not a lost checker result, a sequence-zero
  event, or a cache-line crossing; it was a same-sequence tail event rejected by
  the old `<=` boundary.
- The old 728000/1181000 STQ assertions were not proof of queue-capacity
  overflow; the saved chains point to replay/nack/completion identity and
  execute-head ordering.
- Do not attribute a nearby barrier nack to an unrelated STQ entry without
  matching address, index, packet sequence and token.
- Do not call a package-result count balance a proof of `verified=1` or a correct
  parent checksum.

## Static-check omissions and tool/elaboration lessons

### Evidence available from terminal/tool records

The original conversation screenshots are not available as image files in the
current repository/session. The only discoverable images under `/tmp` are
`/tmp/ignite-pages/p-05.png` through `p-08.png`, which are unrelated MICRO'23
paper pages, not EC terminal output. Their contents provide no Debug evidence
and must not be cited as such. Therefore this section records only errors
preserved in `Debug/*.md` and generated/tool logs; it does not invent a
pixel-level transcription of unavailable chat screenshots.

### Dynamic `dontTouch` FIRRTL target parsing

**Observed error.** Hardware generation failed with
`java.lang.NumberFormatException: For input string: "stq_head"`, later with
`"debug_modifying_set"`, and during the LSL work with
`"_selected_head_valid_T"`.

**Mechanism and code area.** `dontTouch` was applied directly to a dynamic
Vec/Memory selection such as `stq(stq_head)`, or to an alias that FIRRTL still
represented as an indexed temporary. The old FIRRTL target parser treated the
dynamic index component as if it were a numeric static index.

**Handling.** The selected values were first materialized into explicitly named
`Wire`s, and `dontTouch` was applied to those named wires. This is observation
only; the underlying control path must remain unchanged.

**Future check.** After every probe change, inspect the FIRRTL annotation/target
names and run elaboration/generation, not just Scala compilation. Avoid
`dontTouch` on raw dynamic selections.

### SyncReadMem interface expansion and missing connections

**Observed issue.** Adding `deq_read`/`deq_read_valid` to `GH_MemFIFO` required
connections in every instance. Missing one can survive a local source review
and surface only in elaboration/FIRRTL initialization or generated wiring.

**Affected paths.** R_LSL memory banks, R_ELU, R_RSUSL and the R_ICSL debug FIFO
must each connect the new read control/response signals. Ordinary register FIFO
behavior must not be changed accidentally.

**Handling.** The current diff adds explicit connections, and compile records
report success. The latest generated/runtime validation is still required.

### Scala/Chisel type, width and API mistakes

**Observed external tool error.** A separate project (not this EC worktree)
reported `Tage.scala:501: value asBools is not a member of chisel3.Data` for
`writeWayMask.asBools`. The static type was `Data`, not a concrete `UInt`.

**Why static review missed it.** Scala parser-level review and algorithm review
do not resolve Chisel's inferred hardware types or API receiver types.

**Future check.** Check every changed `Wire`, `Reg`, `IO`, `Bool/UInt/SInt`
width, `Mux/MuxLookup` collection type, dynamic Vec index, assignment
direction, and API method receiver with the actual project compile. This error
must not be attributed to `/data1/gzh/EC`; it came from
`/data1/GB/chipyard-boom-fdip/soc-generator`.

### FIRRTL combinational loops

**Observed error.** FIRRTL reported a `BoomCore` loop containing
`rob.io.commit.arch_valids -> snapshot_quiet -> R_IC.if_dosnap_priv ->
R_RSU.core_hang_up -> rsu_stall -> rob.io.gh_stall -> rob.io.commit.arch_valids`.
Another checker-tail loop went through
`package_exec_completion -> checker mode/stall -> Rocket pipeline valid/inflight
-> package_exec_completion`.

**Why static review missed it.** Each local assignment looked reasonable, but
the loop crossed module boundaries and only elaboration/FIRRTL's global graph
could report it.

**Handling.** Snapshot guards use registered previous-cycle state; checker-tail
completion uses registered `instruction_tail_waiting` and explicit producer/CDC/
LSL drain conditions. The source graph should still be rechecked after any
interface or completion change.

### Generated semantics versus source semantics

The LSL prefetch fix initially looked correct in Scala but the generated RAM
behavior exposed a deeper issue: `SyncReadMem` output may not retain the old
payload after read-enable goes low. A registered `head_valid` without a
registered payload is insufficient. Always inspect generated RAM RTL and prove
payload stability, response latency, and dequeue fire alignment.

## What the next Debug session must do

1. Treat 528000 as a new run. Identify its own log-to-FST conversion and first
   divergence before naming a root cause. Start from the last known good package,
   allocation/result sequence, checker status, LSL prefetch/valid/payload,
   producer seal, package-tail gate, and BOOM commit/ownership signals.
2. First check whether the old empty-ROB PC invariant is restored:
   `rob_empty`, `r_next_pc_valid`, committed next PC, snapshot capture PC,
   `active_packet_seq`, and checker CPS PC must agree at the boundary.
3. Separately check each LSL bank:
   enqueue fire, `empty`, `deq_read`, `deq_read_valid`, registered payload,
   head valid, request type/address, `req_ready`, `deq_fire`, response valid,
   and FIFO occupancy. A mismatch must not consume the head; a match must
   consume exactly once.
4. Trace package release in order:
   producer seal sequence -> GH_BUF/CDC ingress drain -> LSL quiescent -> ARF/
   data completion -> instruction tail completion -> result enqueue/dequeue ->
   BOOM clear and safe watermark. Do not infer any link from a level alone.
5. For cache/TL problems, correlate packet sequence, line address, set/way,
   STQ index and strict token through S0-S3/MSHR/replay, physical write fire,
   TL A/C/D fire and metadata clear. Check `TtoN`, no duplicate writeback while
   metadata clear is pending, and once-only completion.
6. Keep barrier close, checker PASS, safe watermark, package result and actual
   outstanding TL completion as separate events. Confirm whether the L2-to-DRAM
   barrier is enabled in the generated collateral before interpreting a trace.
7. Use compile, elaboration/FIRRTL, then runtime waveform validation as separate
   gates. Compile success alone does not prove no FIRRTL loop, no missing IO
   connection, no invalid `dontTouch` target, or correct synchronous RAM timing.

## Recommended evidence files

The most useful saved reports/traces are:

- `Debug/current_run_459000_root_cause_reassessment_20261006.md`
- `Debug/current_run_459000_full_system_reanalysis_20261005.md`
- `Debug/current_run_459000_lsl_fifo_handshake.txt`
- `Debug/fresh_459000_lsl_head_393250_393700.txt`
- `Debug/fresh_459000_result_release_fullrun.txt`
- `Debug/fresh_459000_packet_route_393080_393285.txt`
- `Debug/current_run_snapshot_boundary_root_cause_20261004.md`
- `Debug/atomic_snapshot_boundary_fix_20261004.md`
- `Debug/package_ownership_fix_20260930.md`
- `Debug/current_run_259pkg_address_stats_root_cause_20261001.md`
- `Debug/fix_checker_completion_first_three.md`
- `Debug/assert74_statistical_fix_implementation.md`
- `Debug/killed_store_replay_s1_alignment_root_cause_20261002.md`
- `Debug/assert_stq_execute_head_off_track_1181000.md`
- `Debug/lsl_syncread_prefetch_fix_20261005.md`
- `Debug/combinational_loop_snapshot_guard_20261003.md`

The latest failure artifacts remain the authoritative inputs for the next
session; the historical files above explain mechanisms and prior repairs only.
