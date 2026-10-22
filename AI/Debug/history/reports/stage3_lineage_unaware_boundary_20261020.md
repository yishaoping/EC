# Stage 3: lineage-unaware client boundary (static implementation)

Progress status below is historical. The conditional timer cycle was later
confirmed with a concrete hart2/seq2 witness and fixed by per-hart timer
cacheline isolation; no hardware boundary change was needed. See
[timer control-domain audit](stage3_timer_control_domain_20261020.md).

The user selected `BLOCK_SPECULATIVE_TRANSFER_TO_LINEAGE_UNAWARE_ROCKET`.
The previous provenance-aware Rocket proposal is superseded and reverted.
No hardware build, Scala typecheck, elaboration, RTL generation, Verilator,
model build/link, runner or simulation was performed in this task.

## Evidence and revision boundary

Task preimages, exact request, hashes, task-only patch and static artifacts:
`AI/TMP/stage3_unaware_boundary_5be1nixk/`.
The rejected extension's preimages are in
`AI/TMP/stage3_system_closure_audit_bo5r1ef7/preimages/`.
Both sets and all immutable runs are retained. HEAD remains
`1ed07c28067fad6d8aed697323b465b925895914` with preexisting uncommitted Stage2/3 work.
The task diff is against saved task preimages, not a reset of the worktree.

Saved `run_zr8umvan` proves the old immediate block: at FST1460779
(`t_fst = 2 * csr_cycle + 205`, csr cycle 0xb24af), ordinary source28/hart1
returns BASE ProbeAckData for resident line0x80007e40, writer0/genb920/seq2,
watermark1. Source24/hart2 waits on that probe; shared C blocks BOOM writeback
and installDrain for cec7. The saved run was built before either proposed fix.
It does NOT show behavior of today's parked-request implementation.
The old report's prescription to propagate lineage through Rocket is withdrawn;
its observed events and revision hashes remain evidence, not new-model proof.

## Minimal architecture and reversion

- Rocket `DCache.scala` and `HellaCache.scala` exactly equal their saved
  pre-extension versions (also no diff against HEAD). CacheImage slot arrays,
  refill installs, buffered-store generation changes, C return propagation,
  capability fields and associated functional assertions/logs were removed.
- BOOM dcache uses its original local `imageSerial` allocation/increment and
  serial exhaustion assertion. No imported-generation coordination remains.
  BOOM's existing CacheImage storage/propagation, preservation and package
  semantics remain. The only new BOOM functionality is an endpoint marker.
- `CacheImage.coherentMutation` and `nextGeneration` were removed. Existing
  writer-aware package helpers stay; `phase1.scala` is unchanged this task.
- Ordinary peers return default BASE through the existing field defaults.
  No second lineage system, trusted unsafe exception, fallback or outer bypass
  was added. The safe predecessor still requires its exact checkpoint ACK
  before different BASE bytes can replace it.

## Client classification and response gate

`CacheImageClient` is an explicit origin-node contract. Only BOOM's coherent
DCache TLClientNode implements it. InclusiveCache Parameters filters coherent
clients by `nodePath.lastOption`, then uses their negotiated/remapped source
ranges. TLImp prepends intermediate nodes; the origin remains last. Xbar unions
port fields, so merely finding CacheImage in requestFields/responseKeys would
incorrectly classify Rocket as aware. Unknown, Rocket, MMIO and DMA endpoints
are unaware by default. No production numeric source allowlist was added.

At MSHR/Scheduler -> SourceD, block a non-control, non-error A response to an
unaware client if it exposes an unsafe resident image. Exposure includes Get,
AcquireBlock/AcquirePerm and the old-value response of Arithmetic/Logical AMO;
AMO cannot hide an unsafe pre-write value by relabeling its final key BASE.
HintAck and Put AccessAck do not expose old bytes/ownership. The AMO datapath
itself is unchanged; its admission uses the same conservative rule.
The scheduler checks both response image and, for a hit AMO, the pre-write
resident. A final `L2_UNSAFE_CLIENT_TRANSFER` assertion enforces this boundary.
The hit guard avoids confusing an unsafe replacement victim with a new safe
miss refill. No existing assertion/table capability condition was disabled.
Safe/BASE traffic selects the old ordinary plan; parked entries alone add new
request-arbitration traffic.

## Parking and handshake review

A plain D stall would hold the set/MSHR while waiting for validation. Instead:

1. Early unsafe directory hit parks before Probe/Acquire work starts. No
   directory write, D beat or ownership grant occurs.
2. If the image becomes unsafe only in BOOM ProbeAckData, finish outstanding
   probe/refill/outer-E work first. D is suppressed independently of E. Late
   park waits for SinkC's accepted bank queue to empty and directory readiness,
   then publishes only completed probe downgrades/removals. It preserves the
   bytes/key/dirty/exact receipt, and never adds the waiting requester as owner.
3. One independent slot per real unaware source stores FullRequest plus required
   seq, without a selected way, resident snapshot, set lock or MSHR. SourceD
   has accepted no execution for that request. The source remains logically
   outstanding until D completion, as TileLink requires. A parked AMO retains
   its original put-buffer payload reference, not a bank or MSHR reservation.
4. Park consumes one scheduler grant. MSHR request/meta validity and all plan
   flags are retired together. Higher-priority bootstrap logic initializes any
   queued successor normally; original ListBuffer queues are not discarded.
5. When the remembered seq is safe AND that set has no live MSHR, replay enters
   ordinary A allocation with a new Directory lookup. Live A and replay
   alternate. A changed/replaced/newer unsafe resident is re-evaluated and may
   park again; no stale directory metadata is reused.

The same-set normal BOOM request can proceed while a peer is parked. The peer
wait count contributes to scheduler active/diagnostics, not preservation's
physical drain predicate. SourceC, preservation locks/ACK, SinkC/ProbeAck,
normal queued requests and unrelated sets retain their original admission
rules. Early/late park assertions prohibit protocol output, premature response
and requester ownership. Directory's existing write bypass covers the late
commit followed by fresh lookup. All MSHR construction sites use Scheduler,
which supplies the new watermark input.

## Validation progress: local proof and remaining blocker

Peer waits assert a separate clientValidationBlock/seq. InclusiveCache feeds
it to the EXISTING sequenced package-close path; it does not passively assume
the watermark will advance. Peer-only close requests leave SourceC enabled.
The old unsafe outer-write candidate/barrier still blocks unsafe outer writes
independently; the old close ACK/watermark/failure/watchdog checks remain.
`GH_REAL_BARRIER_ENABLED` defaults true. Disabled configurations remain safe,
but automatic close is disabled and peer progress requires an external
watermark advance; no unconditional liveness claim is made for them.

The cache-resource cycle
`Rocket wait -> set/MSHR held -> BOOM preservation blocked -> validation wait`
is removed for parked requests. A late request still must finish legitimate
outstanding protocol handshakes before parking; these must not be cancelled.
Close command acceptance is explicitly not a checker PASS.

**Unresolved system-level progress dependency (do not mark READY):**
`Software/Test/hw/interrupt.c:handle_trap` updates the shared timer_flags array
through ordinary coherent DCache. `RocketCore.scala` normal checker start
requires R_ICSL.context_idle; `R_ICSL.scala` context_idle and arch_compare_ready
both require !excpt_mode/trap_depth==0. The matching xRET cannot occur before a
blocked handler load/store finishes. Therefore this conditional cycle exists:

`handler waits safe Grant -> validation waits checker execution/comparison ->
checker waits handler xRET -> handler waits safe Grant`.

The old trace proves unsafe timer-line ownership by ordinary runtime peers and
that these ordinary paths run outside checker mode. It does not prove whether,
in the NEW ordering, the blocked peer is the checker responsible for that
package (or an earlier package needed by the contiguous watermark). This is a
counterfactual progress risk, not a newly observed dynamic failure. Package
close and parking cannot by themselves prove it absent. No trap/Stage1/CPS
protocol was weakened or changed to conceal it. An executable checker/management
context independent of the blocked shared line, or static package ownership
and event ordering excluding this cycle, is still needed for a complete proof.
The user-requested local L2 implementation is present; full progress review is
FAIL/UNRESOLVED and READY_FOR_DYNAMIC_VALIDATION=NO.

## Directed coverage (specified, not run)

Replace `coherent_peer_lineage_roundtrip` with exactly one
`lineage_unaware_peer_waits_validation`. Original 18 CASE bodies remain; total
inventory is exactly 19. Generator's manual inner edge marks only aware source0,
keeps uncached sources1/2 and adds ordinary coherent source3. Production does
not hardcode these IDs.

The replacement CASE checks no peer Grant beat before validation; no retained
MSHR/SourceD after park; same-set BOOM same-package newer generation while
waiting; independent-set safe dirty predecessor checkpoint with held outer ACK;
validation then fresh replay seeing the NEWER bytes/key; ordinary BASE
ReleaseData and BASE ProbeAckData with required safe-predecessor preservation;
durable bytes and clean ownership cleanup. It also covers late unsafe identity
arriving via BOOM ProbeAckData, bank-queue drain, no peer Grant, validation and
successful retry. Host source/probe ledgers check the actual B target source.
The fixture injects the watermark; it does not instantiate Rocket runtime or
prove timer-handler/checker progress. No obsolete peer mutation helper remains.

Logs add L2_CLIENT_WAIT/RETRY, MSHR CLIENT_PARK, L2_CLIENT_CLOSE/VALIDATED and
client wait/seq in timeout snapshots. Existing transaction/CASE/cycle logs stay.

## Static checks and scope

- git diff --check: PASS (tracked worktree and task/untracked whitespace review).
- Python AST: PASS (runner and transition_audit); bash -n public entry: PASS.
- Scala parser-only: PASS, nine touched Scala files, no typechecking/elaboration.
- C++ declaration-stub -fsyntax-only: PASS, no generated model compile/link.
  Stub verifies host C++ syntax, not real generated port names/widths.
- Source table audit: PASS, 9 states, unchanged 72 ordinary rows/helper,
  configured ordinary 18 allowed/54 forbidden, six strict flush edges, 19 CASEs.
- Precise Rocket pre-extension equality, original BOOM serial, unchanged phase1,
  old 18 CASE inventory and removal of peer allocators: PASS.
- Assignment/handshake review covered early/late park, all flag retirement,
  repeat bootstrap, directory bypass, nested C priority, unsafe response gate,
  same-package/cross-package preservation and safe BASE returns.
- Full system validation-progress proof: unresolved as detailed above. Syntax
  and unchanged table checks do not establish FIRRTL combinational legality or
  dynamic correctness. Historical BUILD/DIRECTED PASS cannot be reused for the
  changed production/fixture identities; closure remains NO.

Production files changed relative to THIS task's preimages: **8** (two are
reversions; six contain scoped BOOM marker/helper/L2 changes):

- rocket-chip/rocket/DCache.scala — reversion only
- rocket-chip/rocket/HellaCache.scala — reversion only
- boom/lsu/dcache.scala — remove peer allocation, restore serial, endpoint marker
- rocket-chip/tilelink/CacheImage.scala — remove peer mutation/allocation, marker/opcode helper
- inclusivecache/Parameters.scala — endpoint/source classification
- inclusivecache/MSHR.scala — unsafe execution gate and resource-free park
- inclusivecache/Scheduler.scala — wait slots/relookup/replay/final admission assertion
- inclusivecache/InclusiveCache.scala — reuse existing close command without peer-only outer freeze

No new Rocket store/AMO/datapath functionality, CacheCork, outer protocol,
Stage1 effect/terminal/STQ, Directory, SourceA/C/D or SinkC/D functionality was
added in this task. Prior unrelated worktree edits are preserved.

## Status

```ini
ROCKET_LINEAGE_AWARE=NO
UNSAFE_TO_ROCKET_BLOCKED=YES
ROCKET_GENERATION_OWNER=NO
ROCKET_OVERREACH_REMOVED=YES
MINIMAL_IMPLEMENTATION=YES
STAGE1_BASE_BEHAVIOR_PRESERVED=YES
STAGE2_INVARIANT_PRESERVED=YES
STAGE3_INVARIANT_PRESERVED=YES
SPECULATIVE_OUTER_WRITE_ALLOWED=NO
CROSS_PACKAGE_BARRIER_PRESERVED=YES
STATIC_SYNTAX_AND_SCOPE_CHECKS=PASS
STATIC_REVIEW=FAIL
LINEAGE_UNAWARE_GATE_AUDITED=YES
VALIDATION_PROGRESS_AUDITED=YES
KNOWN_DEADLOCK_CYCLES=CONDITIONAL_RUNTIME_TRAP_VALIDATION_CYCLE_UNRESOLVED
READY_FOR_DYNAMIC_VALIDATION=NO
STAGE3_STATUS=STATIC_PROGRESS_REVIEW_UNRESOLVED
STAGE3_CLOSURE=NO
```

Safety/BASE-preservation YES flags describe the source-level invariant review,
not a new Stage1/2/3 dynamic closure claim. No runner command was executed.
