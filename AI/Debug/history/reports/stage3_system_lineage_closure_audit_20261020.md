# Stage 3 system closure audit — coherent peer lineage loss

> Superseded architecture: the provenance-aware Rocket implementation below was
> explicitly withdrawn. Observed old-run evidence remains valid for its saved
> revision. See [lineage-unaware boundary](stage3_lineage_unaware_boundary_20261020.md)
> for the current implementation and unresolved runtime/validation progress dependency.

The current failure is a proved liveness failure at the first returning ordinary
Rocket dirty image, not observed bad architectural data. The patch preserves
that client's imported speculative lineage and advances exact byte identities.
Dynamic closure remains unresolved; this task ran no hardware/model build,
elaboration, RTL generation, Verilator, runner, or simulation.

## A. Three-run progress delta

| Evidence | Stage1 CLOSED baseline | Previous Stage3 failure | Current Stage3 failure |
|---|---|---|---|
| run | stage1_closure_run_g3Y7Oi9x | run__wqr821z | run_zr8umvan |
| simulator SHA256 prefix | 5a38407bb123 | ba5368cfb8ab | 1474bf1638d1 |
| first unfinished store token | none | d223 | cec7 |
| PC / address | matching workload events complete | 800008dc / 80015e6a | 80000844 / 80056184 |
| package sequence | scheduling-dependent | 0x10 | 3 |
| first-bad reference | none | 0xb90dc | 0xb24af |
| fatal | none; serial_success, verified=1 | BOOM pipeline watchdog | little core 2 watchdog |

PREVIOUS_FIRST_BAD_CYCLE=0xb90dc (the user's prior reference: d223's first
admission=6 after its image was displaced; its original S2 attempt was b90c8).
CURRENT_FIRST_BAD_CYCLE=0xb24af (first persistent shared-C gate; cec7 was issued
at b24a2, secondary-admitted at b24a7).
PREVIOUS_FIRST_BAD_PC=0x800008dc; PREVIOUS_FIRST_BAD_ADDR=0x80015e6a;
PREVIOUS_FIRST_BAD_TOKEN=0xd223.
CURRENT_FIRST_BAD_PC=0x80000844; CURRENT_FIRST_BAD_ADDR=0x80056184;
CURRENT_FIRST_BAD_TOKEN=0xcec7.
PREVIOUS_FIRST_BAD_REASON=same-package newer-generation ReleaseData gated.
CURRENT_FIRST_BAD_REASON=ordinary coherent peer returned BASE instead of its
modified imported speculative lineage; ProbeAckData waits on validation.
PREVIOUS_FIRST_FAILURE_CROSSED=NO; SYSTEM_PROGRESS_ADVANCED=NO;
PREVIOUS_FIX_EFFECTIVE=PARTIAL; PREVIOUS_BUG_CLOSED_IN_SYSTEM=UNPROVEN.
NEW_FAILURE_DISTANCE=-27693 DCache cycles relative to b90dc, and -860 token IDs.
Current trace never reaches d223. A later wall-time watchdog is not progress.

The previous fix is present in the sealed generated Scheduler: the exact
`same writer, nonzero equal seq, strictly newer generation, resident unsafe`
predicate exists in both C paths. Current trace has six actual same-package
newer-generation L2_EXECUTEs, e.g. line2598720 gen b870 -> b872 seq1, outer=0.
However changed preservation timing exposes an earlier peer integration failure.
This evidence supports partial effectiveness, not closure of the old system
failure. Previous FST independently confirms the old abc_mshrs_0 request
(writer0,seq16,genbc13) versus resident (writer0,seq16,genbbfb).

The three workload benchmark/dump/loadmem SHA256 values are identical:
64d450b7288198d7ba0b317221914ffe7930d9223ef4868e66bda691386a3ce3,
ab5bd2f9b8cd7a2cf8a62ce028cbe75cc788483065b2460d987b039b0db4abb8,
51df982469bac5ddb4d5fd2d778c60423ff2b986390dba5bf4e2189103507530.
Use the saved workload dump, not today's Software/Test/test.dump (different).
Both Stage3 HEADs are 1ed07c28067fad6d8aed697323b465b925895914;
inputs.json source hashes match the corresponding system provenance. Relevant
saved Scheduler/DCache/MSHR/SourceD RTL and simulator hashes match their seals.
Before this patch the current production source matched current inputs. The
old/current source differences were CacheImage, MSHR diagnostics, Scheduler;
fixture changes came from the already completed CASE10 repair. DCache generated
RTL was byte-identical across the two failing runs. Full revision boundaries
and task preimages are retained under the evidence directory below.

## B. Current transaction and first divergent handshake

FST units are NOT DCache cycles. In all sampled models,
`t_fst = 2 * csr_cycle + 205` at rising-edge values. For example current
FST1462101 -> CSR b2744. Gate combinational transition FST1460779 -> b24af;
the following sampling edge records the printed validation-block event.

| DCache cycle / evidence | Event |
|---|---|
| b20c2, trace2638725 | BOOM ce81 at PC80000564 writes timer_flags[0], line80007e40; new image writer0/genb920/seq2 |
| trace2641861..2641984 | Existing BASE predecessor checkpoint txn68 captures/ACKs before BOOM ProbeAck overwrites its L2 copy |
| trace2642014, 2642068, 2642200 | Acquire service retains genb920/seq2 on line80007e40; multiple ordinary coherent runtime clients share/transfer ownership |
| b2458, FST1460605 | Rocket hart1 completes acquisition; later write to timer_flags[1], address80007e44, needs upgrade |
| b2490, FST1460717 | Rocket hart1's upgrade completes |
| b2494, FST1460725 | Actual Rocket buffered store physical write, high 32-bit mask f0, data 0x0000000600000006; imports/lineage were not represented in this DCache |
| b2496, FST1460729 | L2 abc_mshrs_0 handles source24 AcquireBlock NtoT for line80007e40, clients=2, waits ProbeAck from source28/hart1 |
| b24af, FST1460779 | SinkC first data beat sees BASE key (all fields zero), resident writer0/genb920/seq2, watermark1. probeNeedsGate=1, probeBlock=1 |
| abort snapshot | C source28 opcode5 ProbeAckData TtoN addr80007e40, valid1 ready0; meta dirty1/outer0/TRUNK clients2; w_pprobeackfirst/last=0; checkpoint FSM IDLE, no lock/ACK outstanding |

The physical store address/mask are supported by the saved waveform and
runtime workload's shared timer_flags array; the instruction is ordinary
runtime traffic, not checker replay (replay suppresses DCache accesses).
Hart1's C queue has already accepted the response locally, so its release FSM
can return idle while L2 C remains blocked. That is buffering, not missing peer
handshake. Source28 maps to hart1; requester source24 is hart2. The watchdog says
little core2 because its normal coherent acquisition cannot finish.

Predicate in the FAILED generated Scheduler.sv:
`probeChange = first ProbeAckData && residentFound &&
 !samePackageSupersede && (!incoming.valid || incoming != resident)`;
`probeNeedsGate = probeChange && (!residentSafe || dirty && !outerPreserved)`.
Incoming BASE makes samePackageSupersede false and probeChange true. Resident
seq2 > watermark1 is unsafe. Waiting for validation is appropriate for an
independent different-package overwrite; the incoming identity is wrong here.
HellaCache had not negotiated CacheImage and Rocket DCache had no imported key
storage or mutation/return logic. The fabric supplies default zero C metadata.
No downstream gate can recover the identity from that response.

FIRST_BAD_EVENT=first dirty coherent return held behind validation;
FIRST_BAD_MODULE=L2 Scheduler/SinkC;
FIRST_BAD_PREDICATE=probeNeedsGate -> !probeAllow -> probeBlock;
FIRST_BAD_ADDR=0x80007e40 (causal line); impacted architectural store=0x80056184.
EXPECTED_NEXT_EVENT=admit same-lineage newer descendant into SinkC, finish
ProbeAck, Grant requester, release shared C, then complete BOOM writeback/install.
ACTUAL_NEXT_EVENT=C stays valid/!ready until watchdog.

BOOM cec7's own path is separate but blocked by that shared C channel:
ARCH_STORE b232d -> ISSUE b24a2 -> S1 b24a3 -> S2 b24a4 admission6 ->
S2 b24a7 admission1 -> MSHR3 obtains GrantData genb931/seq3 -> s_commit_line(11).
At abort installOwnerMatch=1, installPreservationAllowed=1, installDrain=0.
The blocking subcondition is WB io_idx/io_pending_idx valid, set86. WB holds
ReleaseData for line8005e180 genac7a/seq0, valid1 ready0. Its shared C arbitration
cannot pass source28's stalled multibeat response. This is not an install
preservation failure or absent Grant. No EFFECT/TERMINAL/STQ RELEASE for cec7.
Expected store result from baseline/previous completed matching event is
0x00000cd000000cc0 (mask f0); actual current result is ABSENT, not a different
value. STQ completion is downstream and is correctly retained.

Deadlock (handshake stops proved; validation-to-runtime dependency strongly supported
by the shared runtime line and checker watchdog): checker2 Acquire waits hart1 ProbeAckData -> ProbeAck admission waits
seq2 validation -> seq2 checker/runtime progress needs coherent timer line ->
checker2 Acquire. Amplifier: stalled shared C -> BOOM WB -> installDrain ->
cec7 replay/effect -> STQ release and subsequent workload progress.

## C. Architectural classification and baseline differential

BAD_DATA_VALUE_OBSERVED=NO; LOST_EFFECT_OBSERVED=NO;
STUCK_TRANSACTION_OBSERVED=YES; DUPLICATE_EFFECT_OBSERVED=NO;
PREMATURE_RELEASE_OBSERVED=NO; MISSING_EFFECT_AT_ABORT=15.
`LOST_EFFECT=UNRESOLVED` must not be rewritten to a proved permanently dropped
store. Current architectural_errors contains only the watchdog plus Verilator
stop; errors={} and error_samples=[]. All duplicate/terminal/release/clear
correctness counters are zero. Stage2 checker PASS; Stage3 has checkpoint105/105,
victim807/807 and all four preservation correctness error counts zero. Its FAIL
is runtime assertion, not observed speculative outer or stale ACK effect.
MAIN_CHECKER/EXIT_OUTSTANDING unresolved remain downstream; no independent fix.

Baseline matching PC80000844/address80056184 (token ca4e) has EFFECT9f554,
TERMINAL9f556, RELEASE9f557 and correct bytes above. Previous run matching token
cec7 completes EFFECTb289b, TERMINALb289d, RELEASEb289e; current cec7 does not.
Previous d223's corresponding baseline event (token cd38) completes EFFECTa5409,
TERMINALa540b, RELEASEa540c. IDs and package sequences differ with timing; compare
PC/address/operation/mask/value, not token equality across unlike timelines.
Baseline FST source28 ProbeAckData for timer line80007e40 has ready1 and completes
its beats (e.g. FST1294701..1294729); current same protocol return has ready0.
Stage3's new destructive-change interpretation is the first blocking semantic
change on that return, not the ultimate architectural scoreboard label.

## D. Why the directed suite missed it

All existing fixtures synthesize CacheImage on C explicitly. They test authored
BOOM-style generation supersedes, preservation and outer barriers, but do not
instantiate a stock Rocket DCache that imports a speculative Grant, executes a
normal runtime store, and returns it while another client needs the line.
System adds shared timer_flags, multiple clients, repeated ownership transfers,
a C queue and interleaved BOOM writebacks. Latest DIRECTED PASS is useful evidence
for those original 18 cases, not coverage of coherent peer key lifecycle.

## E. Common-cause implementation

* CacheImage.scala: shared samePackageIdentity / samePackageSupersede,
  nextGeneration and coherentMutation helpers. A peer ordinary write retains
  imported writer/seq and advances generation. BASE writes become safe seq0
  in the local writer namespace. No receipt or outer permission is created.
* HellaCache.scala: blocking coherent Rocket clients negotiate C request and D
  response CacheImage; NBDCache/scratchpad do not claim this capability.
* DCache.scala: per-slot imported key initialized with tag reset sweep, installed
  on successful cached Grant tag commit. Identity updates on physical buffered
  store retirement, including merged stores/AMO, excluding killed requests and
  zero-mask ECC repair. Return key reads actual frozen selected slot after old
  stores drain, not an early victim snapshot. It travels with every queued C
  beat on ProbeAckData and ReleaseData. Permission changes retain key; replacing
  a slot installs a new key. A image explicitly BASE after edge construction.
  Assertions check generation exhaustion, store/refill collision, return versus
  same-slot mutation/refill, and stable multibeat D/C keys. Minimal peer logs.
* BOOM dcache.scala: writer-local generation advances past the imported generation
  when the lineage returns from a peer; this avoids a later collision/stale ACK
  identity and a strictly-newer admission failure. Physical-write/debug identity
  use the same chosen serial. No early effect or receipt is introduced.
* phase1.scala: L1 same-package admission includes writer, via the shared helper,
  preventing equal seq in another writer namespace from bypassing protection.
* Scheduler.scala: both ReleaseData and first ProbeAckData use the common helper.
  New entry/change-only L2_PROBE_BLOCK log includes source, both keys, dirty,
  receipt, watermark, same-package and generation ordering. No gate relaxed.
* Fixture/generator/checker/static-table inventory: add one protocol CASE and
  production helper observations; exact completeness now requires 19/19. All
  original CASE names and correctness criteria remain required.

MSHR.scala, Directory.scala, L2Preservation.scala, SourceA/C/D, SinkC/D,
CacheCork.scala and InclusiveCache.scala were reviewed but are UNCHANGED by this
task. MSHR D execution already waits w_pprobeacklast; therefore updating its key
at last ProbeAckData is consistent with SourceD's metadata/data pairing and did
not need an early-key patch. Exact key inequality in directory receipts is
intentional, not an additional full-generation admission barrier.

## F. Stage2/3 semantics and receipt audit

Package identity is `(valid, writer, nonzero equal seq)`. Generation distinguishes
bytes, not packages. Strictly newer same-package unsafe descendants can replace
L2 resident bytes because the safe-ancestor obligation was satisfied before the
first speculative modification; no intermediate descendant must be exported.
The ordinary peer is not creating a different speculative execution domain: its
mixed runtime bytes conservatively retain the imported validation debt. This
is stricter than relabeling the line BASE or seq0, and validation is still
required to write any speculative descendant to outer memory.

| Lifecycle event | Exact current-image receipt | Safe ancestor obligation |
|---|---|---|
| safe predecessor checkpoint ACK | exact key gets outerPreserved | fulfilled for that predecessor |
| speculative descendant install | not inherited from changed key | already fulfilled before destructive update |
| same-package generation update | revoked on byte/key change | carried through the chain |
| validation | identity/receipt unchanged | changes safe predicate only |
| trusted A Put/AMO | revoke current receipt, BASE safe result | old unsafe/dirtiness gate still required |
| ordinary peer import/mutation | import key / mutation newer, no receipt granted | imported seq debt retained |
| replacement/flush | outer safe first; matching last-beat/ACK then commit | no bypass for same-package outer export |

L1 admission and S3 physical effect use one writer-aware helper. Copy/install
sites intentionally keep exact-key/slot/epoch/lower-copy checks: they copy data
from an existing lower image, not create a same-package local write. SourceD
and SinkC bank writes consume already-admitted descriptors; neither adds a
second generation-mismatch blocker. MSHR nestedwb/dir commit forward the selected
image and revoke outerPreserved on changed key. Validation association remains
by seq; full key and serial remain required for receipts and ACKs.

SAME_PACKAGE_DEFINITION_UNIFIED=YES; RECEIPT_LIFETIME_AUDITED=YES;
ALL_STAGE3_BLOCKERS_AUDITED=YES.

## G. Blocking-point audit

CAN_CLEAR assumes legal peers eventually handshake and the relevant checker can
validate. Permanent external backpressure/failed validation is intentionally
not an unconditional liveness guarantee. No timeout has been increased.

| BLOCKER | SET_BY | CLEARED_BY | CAN_CLEAR_WHILE_BLOCKED | POSSIBLE_CYCLE / review |
|---|---|---|---|---|
| preservation drain | safe dirty selected candidate | SourceD/C idle, admitted SinkC bank queue empty, selected MSHR quiescent | YES | runnable safe candidates drain older admitted work; blocked first C beat excluded; no new gate change |
| validation barrier | unsafe victim or destructive changed image | authenticated watermark/close ACK | YES for independent validation | PROVED current peer-lineage cycle repaired; true cross-package remains intentionally blocked |
| same-line admission | changed unsafe or dirty unreceipted predecessor | validation then exact preservation ACK | YES | same-package helper shared; no full-key reblock downstream |
| set victim admission | valid chosen old way | inner probes then validated Release/ACK | YES | B can run before c.valid; outer data never uses supersede permission |
| pending-set freeze | capture immutable snapshot | matching checkpoint AccessAck | YES | reserves only captured set; checkpoint A/D and bank read stay live |
| SourceC outer gate | unsafe resident / checkpoint reservation | watermark / checkpoint completion | YES | safe assertion at request and emitted beat remains |
| ProbeAckData gate | first changed data beat | obligation satisfied or valid newer same lineage | YES after peer fix | BASE-loss cycle eliminated by provenance, not C bypass |
| ReleaseData gate | scheduled destructive C overwrite | same predicates as ProbeAckData | YES after peer fix | symmetric helper and peer key return; ACK remains after bank commit |
| delayed Acquire | victim pending ReleaseAck | matching serial/source/size ACK after last C | YES | outer D remains accepted independently; no refill ahead of ACK |
| delayed directory commit | no_wait false | probe/refill/GrantAck/ReleaseAck tails | YES | forwarding and final key update have no new unsafe gate |
| victim ACK wait | releaseIssued, not ACKed | matching successful response | YES | duplicate/stale/denied cannot release new transaction |
| checkpoint ACK wait | sent full-line Put | matching successful AccessAck | YES | snapshot/key/serial stable; no enqueue-as-completion |
| flush wait | selected real control MSHR | inner ProbeAck, validation, outer Release/ACK, dir commit | YES after peer fix | original fixture ownership repair already dynamically passed; production peer key fixes same dirty return path |
| BOOM installDrain | older writeback on set | physical C progress/WB pending clear | YES after peer fix | current amplifier via shared-C head; install owner/receipt conditions were already true |

KNOWN_LIVENESS_CYCLES_REMAINING=NONE identified in this static current-config
scope. This is not a proof of system closure or arbitrary external fairness.
Normal non-speculative imported BASE/seq0 writes stay safe and need no validation;
dirty byte changes still revoke receipt. Speculative descendants stay unsafe
across trusted runtime modifications. Generation exhaustion is fail-stop,
not wrap/reuse. No assertion was disabled; the production transition table,
victim ACK, preservation barrier and outer-write guards remain unchanged.

## H. Regression coverage

Added `coherent_peer_lineage_roundtrip`, independent of system addresses:
unsafe origin Grant -> production coherentMutation with lagging local serial ->
ReleaseData generation N+1 -> reacquire/readback -> mutation N+2 -> concurrent
Get/Probe -> ProbeAckData -> correct data/key and progress before validation ->
clean ownership release -> validation/flush -> correct durable outer bytes.
It checks zero new checkpoint/outer Put before validation, writer/seq retention,
strict generation advance, and both C paths. It exercises the actual production
helper and L2 pipeline. It does NOT instantiate the whole Rocket cache, so its
slot reset/refill/store-buffer wiring still requires next system validation.
Original 18 cases remain required; parser/checker and static inventory require
all 19 exactly once plus END PASS and zero preservation correctness errors.

## I. Static validation and remaining boundary

STATIC_REVIEW=PASS; FIRST_DIVERGENCE_IDENTIFIED=YES;
SYSTEM_BASELINE_COMPARED=YES; PREVIOUS_FAILED_RUN_COMPARED=YES;
SYSTEM_PATH_AUDIT=PASS (source/handshake/provenance review only);
CURRENT_CONFIG_TRANSITION_AUDIT=PASS (18 ordinary allowed,54 forbidden,9 self,
6 separate flush edges; unchanged MSHR/table/assertion helper;19 CASE mapping).
Python AST, bash syntax, git diff --check, Scala parser-only (stops before typing)
and C++ -fsyntax-only with saved/new port declaration stub PASS. Neither syntax
check establishes Chisel type correctness, elaboration, combinational-loop
absence, generated ports, or dynamic behavior. No C++ model compilation/link,
Scala typecheck/backend, hardware generation, Verilator or simulation was run.
Static assignment/use review covers optional A/C/D fields, per-slot init,
physical write versus killed/replayed request, refill commit, stable return
slot/queue, generation/receipt association and all wait releases above.
STAGE2_INVARIANT_PRESERVED=YES; STAGE3_INVARIANT_PRESERVED=YES (design/static);
SPECULATIVE_OUTER_WRITE_ALLOWED=NO; CROSS_PACKAGE_BARRIER_PRESERVED=YES;
ASSERTIONS_DISABLED=NO; KNOWN_RELATED_BUGS_REMAINING=NONE identified statically;
DYNAMIC_VALIDATION=PENDING; STAGE3_STATUS=PATCHED_PENDING_REBUILD;
STAGE3_CLOSURE=NO. Fresh source identity invalidates BUILD and all downstream
seals; do not reuse old directed PASS as evidence for this patch.

Evidence: `AI/TMP/stage3_system_closure_audit_bo5r1ef7/` contains revision
boundaries/hashes, preimages, task-only diff, compact three-run event comparisons,
narrow FST extractions and explicit binary decodes, baseline timer C acceptance,
static transition inventory and syntax results. Saved immutable runs untouched.
