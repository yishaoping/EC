# Stage 3 L2 predecessor preservation — source design / static audit

Status (2026-10-20): PATCHED_PENDING_REBUILD; STAGE3_CLOSURE=NO.
The selected architecture is BLOCK_SPECULATIVE_TRANSFER_TO_LINEAGE_UNAWARE_ROCKET.
The source implementation and bounded static progress review are complete;
READY_FOR_DYNAMIC_VALIDATION=YES. No build or simulation was performed.

## Ordinary client boundary (supersedes the Rocket-lineage extension)

BOOM retains its existing CacheImage/writer/seq/local generation machinery.
Ordinary Rocket stores/returns no CacheImage and allocates no generation.
Only BOOM coherent endpoint nodes implement CacheImageClient. L2 classifies
real remapped source ranges by that origin marker, not Xbar field unions.
Unmarked clients default to unaware. Unsafe Get/Acquire/permission/AMO-old-value
responses cannot enter SourceD for an unaware client. Safe/BASE traffic follows
the existing ordinary state plan. No outer or cross-package exception is added.

Unsafe requests park in source-specific slots with original request+required seq,
not resident directory/way snapshots. Early park issues no coherence work; late
park completes probes/outer E and accepted SinkC bank effects before committing
only their ownership changes. MSHR/set/D resources are released. Replay after
validation uses a fresh lookup of an idle set and rechecks the current identity.
The existing sequenced package-close path is requested by client waits; peer-only
close does not freeze SourceC. BOOM same-package supersede and all predecessor
preservation/ACK barriers remain unchanged. Rocket's later BASE data remains a
normal safe trusted write, still requiring preservation of a dirty predecessor.

Parking alone does not prove autonomous checker progress. The remaining timer
cycle has now been concretely identified: saved hart2 owns seq2 and retains its
PASS while a timer trap reads another word of BOOM's unsafe seq2 timer block.
Result handoff waits trap cleanup, so the old shared layout plus the new gate
can self-deadlock. Per-hart timer counters now occupy distinct aligned64B
control blocks; runtime stacks are already private and handler device accesses
are CLINT MMIO. No unsafe-client exception or hardware/provenance extension is
needed. The next runner invocation automatically rebuilds changed software,
checks actual ELF timer symbol alignment/size and binds new workload identity.
The current-workload timer unsafe-transfer loop is statically excluded after
this fix; arbitrary application software and universal cache fairness are not
claimed. See the [concrete wait graph/control-domain audit](../Debug/history/reports/stage3_timer_control_domain_20261020.md)
and [original boundary audit](../Debug/history/reports/stage3_lineage_unaware_boundary_20261020.md).

## Confirmed dependency graph and root cause (before implementation)

* BOOM dcache physical writes allocate `CacheImageKey(valid,writer,generation,
  contentSeq)`; generation is a non-wrapping writer serial. Release/ProbeAck carry
  this identity through TL CacheImage. Validation changes the functional safe
  watermark, not the image key. BASE and seq0 are safe; otherwise seq<=watermark.
* InclusiveCache SinkC ReleaseData -> ListBuffer -> Scheduler -> MSHR -> SourceD
  s4 -> BankedStore. ReleaseAck is generated after the last bank write (Stage 2).
* SinkC ProbeAckData -> one-entry bank address queue -> BankedStore is a separate
  overwrite entry, before MSHR's first/last response metadata update.
* Directory performs hit lookup and LFSR way selection. MSHR captures the chosen
  DirectoryResult. Scheduler serializes each set, with special C/BC preemption
  and nested metadata forwarding. A miss is a set victim, C data on a hit is a
  same-line version; neither safety obligation is encoded in the original plan.
* Directory has state(valid), dirty, clients, dcache attribution, packetSeq,
  packetTracked, tag and CacheImage. Selected way lives in DirectoryResult/MSHR.
  There is no exact-image outer receipt. Dirty is a coherence obligation, not
  permission to export unvalidated bytes.
* All resident outer data uses SourceC -> outer C -> CacheCork C-to-Put -> memory.
  SourceA originally only emits Acquire and has no data write. Flush is SinkX ->
  MSHR's same eviction plan. SinkD is the refill bank writer. SourceD handles
  trusted A Put/AMO in addition to releases and reads.
* SourceC request.fire only reserves its SRAM/pipeline/queue capacity. C.fire
  means a beat was accepted downstream. ReleaseData completion is outer D
  ReleaseAck, transformed from memory AccessAck by CacheCork. TLToAXI4 creates
  write AccessAck from AXI B, and AXI4UserYanker restores echoes at B, not AW/W.
  Release without data can be ACKed locally: it proves no new dirty copy.
* Original MSHR sets directory invalid simultaneously with scheduling Release,
  and allows Acquire after s_release rather than w_releaseack. This destroys
  ownership and can permit refill before preservation completion.
* Original ReleaseAck consumer matches only reused MSHR source. Existing L2
  barrier is optional and based on one selected DCache packet candidate, rather
  than an unconditional safety predicate on every data source. It does not
  protect either same-line overwrite entry and its global release can select a
  different MSHR. No hardware Stage 3 run exists to combine with these findings.

## Protocol to implement

Same-line changes use a non-destructive full-line outer A Put with a reserved
source, an immutable snapshot and non-wrapping 64-bit echo serial. A completed
receipt is attached to the exact resident key. Probe writes and scheduled
SourceD writes share this gate; different-key unsafe supersede conservatively
waits validation. Identical-key transport copies preserve identity/receipt.

Set eviction/flush retains the existing Release protocol, waits validation,
uses an echoed release generation and actual last-C handshake, and retains
data/tag/ownership until its matching outer ReleaseAck. Acquire/refill cannot
start before that ACK. Clean coherent resident bytes already have an outer
copy; dirty bytes only get a receipt from successful full write completion.

Safety is unconditional, independent of measurement reset and the optional
pressure-close statistics policy. A pending same-line snapshot reserves its set;
existing SourceD/SinkC bank operations must drain before preservation reads.
Both outgoing write sources use the same safe predicate. All identity changes
clear the old receipt; validation alone does not change keys or receipts.

## Implemented protocol

The same `L2Preservation.blocked` admission predicate protects SourceD changes
and SinkC's first ProbeAckData, before its metadata response or bank queue.
`CacheImage.safe` has exactly Stage2's BASE/seq0/functional-watermark semantics.
Different-package unsafe same-line versions wait for validation. A newer
generation in the same valid speculative package may replace an unsafe
generation in place: the Stage 2 package rule carries the original safe-
predecessor obligation across that update. BASE and contentSeq=0 are not
classified as speculative package updates. Once the resident is safe, the
existing dirty/unpreserved checkpoint rule still applies. Identical **valid
authored** keys are immutable transport copies. BASE never gets this
optimization; BASE data writes and trusted A Put/AMO always revoke the receipt,
even when key bits are unchanged.
Every trusted A byte update schedules a directory write, including an already
dirty hit; otherwise its new BASE bytes could retain the preceding image's
receipt. Completion bits for release/probe/execute use the same complete-probe
conditions as their request-valid predicates.

```
same-line candidate -> unsafe: validation wait / existing pressure-close request
                    -> safe clean or exact receipt: execute
                    -> safe dirty: drain prior bank pipelines
                       -> snapshot + reserve set
                       -> SRAM read / two-cycle read latency / hold Put beat
                       -> all beats accepted -> matching successful AccessAck
                       -> attach exact receipt, retain lock through ACK cycle
                       -> execute later; changed bytes revoke receipt

set victim / flush -> complete all inner probes and metadata
                   -> unsafe: validation barrier, no discard or outer write
                   -> safe: ReleaseData (Release if clean or receipt exists)
                   -> freeze resident; actual final C handshake records sent
                   -> matching successful ReleaseAck
                   -> Acquire/refill/final tag write/flush completion allowed
```

Same-line immutable snapshot: tag/set/way, complete Stage2 CacheImage, dirty,
receipt and reason (Release/ProbeAck/trusted A). A non-wrapping 64-bit echo serial
names that snapshot. Bank instance + reserved source define its routing domain.
For BASE, the serial and frozen bytes bind the content without inventing a
global BASE version. Victim identity is bound by the routed MSHR source, its
non-wrapping plan generation, frozen DirectoryResult and unchanged request/
control reason. SourceC carries image/echo/last-beat information through queues.

Safe/quiescent candidates have priority over unsafe waiters. Before capture,
new SourceD/SourceC work stops while earlier pipeline work drains. Pending
checkpoint reserves its set, including the ACK cycle, and exclusively uses the
SourceC SRAM read port; other sets may progress. Existing SourceD hazards and
SinkC-over-SourceC bank priority remain for normal victim writeback.

Dirty completion comes from terminal memory, not a local queue: Configs.scala
connects CacheCork, and subsystem Ports.scala connects TLToAXI4/AXI4UserYanker.
The yanker restores echoes at B. `testchipip/csrc/mm.cc` writes backing bytes
before enqueuing B after final W; `mm_dramsim2.cc` adds B in `write_complete`.
ReleaseData uses the same Put completion transformed to ReleaseAck. Data-free
Release can complete in Cork because clean coherent bytes or an exact receipt
already establish the terminal copy. This is normal memory completion, not
nonvolatile persistence across power loss. Denied writes retain the barrier
and assert; they never authorize overwrite. Serial exhaustion is fail-stop.
CacheCork's locally synthesized Grant/ReleaseAck and C-to-Put preserve echo;
PhysicalFilter's synthesized denial now also preserves it. The current v1Config
memory bus has no built-in TL error/zero or backing SRAM manager; its default
control-bus error device is outside this L2 outer routing domain. Those unrelated
managers were not changed.

## Required ten-question source cross-check

1. Earliest destructive same-line effect is directory write acceptance/bypass (before
   s4 bank writes), or first accepted ProbeAckData bank address. Both admission
   sites use the shared predicate; no different-generation same-packet bypass.
2. Safe dirty P without receipt cannot schedule either effect. Only full-send,
   matching successful AccessAck creates receipt; the lock still holds on that
   cycle. Victim Acquire/refill and final directory/flush completion explicitly
   require matched ReleaseAck, retaining old tag/data/ownership beforehand.
3. The complete outgoing-data inventory is SourceC ReleaseData and checkpoint
   A Put. Both assert the same safe predicate at actual output handshakes.
   SourceC's queued key accompanies every beat; dirty agrees with opcode data.
   The outgoing A mux also asserts Put originated from the safe checkpoint.
   Safety does not depend on dcache attribution or the optional stats barrier.
4. Checkpoint ACK checks reserved source, opcode/size, full-send state and
   serial. Victim checks routed source, generation, issued and actual last-C
   state. Stale/duplicate branches change no effective completion state.
5. Capture drains prior writers/readers; same-set schedules/new/nested requests
   and first probe data are blocked through ACK. Four assertions cover directory
   write admission plus physical SourceD, SinkC and SinkD effects. An older
   queued directory write may finish publishing the same predecessor identity;
   no new conflicting write can enter the queue during reservation. Victim blocks nested C after
   issue and asserts its entire DirectoryResult snapshot remains unchanged.
6. Same-line candidates derive from exact-hit byte changes/direct probe data;
   victims derive from the original miss/flush Release plan and name old tag.
   Their snapshots, reason/event namespaces and ACK protocols are distinct.
7. Validation changes only the safe predicate on immutable contentSeq. Once
   safe, candidates can checkpoint and victims can issue Release. Stage3 waits
   feed the existing pressure-close path before any SourceC request exists.
8. Snapshot serial is allocated once. Put beat/data/identity hold while stalled;
   beat advances only on fire and issued asserts first-beat uniqueness. Victim
   s_release/releaseIssued/releaseSent enforce one request and one last send.
9. Safe clean is an unmodified coherent outer image. Exact receipt permits
   dirty-state data-free Release too. All new bytes/BASE writes revoke receipts;
   validation and permission-only changes preserve exact-key receipts.
10. Flush uses the victim plan; no independent runtime L2 clear writer exists.
    Refill cannot start before ACK because Acquire is gated. Retry/secondary/
    reload/nested work reenters the same admission rules. Cold reset wipes
    directory/transport under the existing coordinated TL reset contract and
    emits no speculative outer data; warm-reset persistence is outside Stage3.

Receipt updates explicitly assert exclusion from simultaneous directory lookup/
reload, probe data and nested metadata writes. The completion cycle remains
reserved. Validation itself writes no key/receipt, so coincident ACK/validation
and bank-write/validation transitions have deterministic independent effects.
Measurement START/STOP/RESET does not reset protocol records or generations.

## Directed coverage added (NOT RUN)

The fixture instantiates production Scheduler/Directory/BankedStore/all sources
and sinks plus production CacheCork. The host models upper clients and terminal
memory only. It compares all 64 predecessor bytes, commits memory at completion,
independently forbids pending bank/tag effects and checks stalled outer data/
identity. It warms both real ways by observing two hits with no outer Get,
rather than assuming the LFSR prefers invalid ways.

| # | CASE | Proof sought |
|---|---|---|
| 1 | same_line_safe_dirty_wait_ack | P bytes in checkpoint; Q waits ACK |
| 2 | same_line_already_outer_preserved | clean coherent P needs no new Put; trusted write over dirty P revokes receipt and next Q preserves the new BASE bytes |
| 3 | safe_dirty_set_victim_wait_ack | refill/Grant waits victim ACK |
| 4 | speculative_set_victim_blocks_outer | both ways unsafe; zero outer writes |
| 5 | validated_victim_preserve_ack_replace | validation -> Release -> ACK -> Grant |
| 6 | outer_backpressure_exactly_once | held identity/data; reject early matching ACK |
| 7 | delayed_ack_freezes_predecessor | no bank/tag effects before completion |
| 8 | stale_ack_ignored | old checkpoint/victim echo cannot free new work |
| 9 | duplicate_ack_ignored | effective completion count unchanged |
| 10 | repeated_speculative_same_line | same-package changed generation commits without a redundant checkpoint Put; readback ownership is returned with clean TtoN before validated flush |
| 11 | same_set_different_line_replacement | actual different-tag victim bytes/address |
| 12 | pending_same_line_request | queued real A cannot change predecessor |
| 13 | pending_replacement_pressure | real same-set miss preserves pending identity |
| 14 | validation_and_ack_same_cycle | actual watermark-change + matching ACK counter |
| 15 | validation_and_refill_replacement_same_cycle | actual probe-bank install + validation counter |
| 16 | flush_clear_normal_writeback_barrier | flush waits safety and outer completion |
| 17 | safe_clean_victim_no_write | full clean-set replacement emits no data Put |
| 18 | full_provenance_collision | same address/set, changed gen/seq, stale echo |
| 19 | lineage_unaware_peer_waits_validation | early/late park, no unsafe Grant, same-set BOOM and preservation progress, validation/relookup, ordinary BASE C returns |

Case 15 tests direct ProbeAck bank installation; outer miss refill is case 5.
Only the existing runtime L2 clear entry (flush) is claimed. Precise race cases
require independently sampled coincident signals; missing coincidence fails.
The repeated same-line case checks ReleaseAck and real bank effects while
blocked: SinkC buffering of C beats is legal and is not treated as an install.
After readback, the fixture explicitly returns the acquired client permission
with clean TtoN before cleanup. It then validates the package, flushes the now
unowned resident, and checks the durable outer bytes. This avoids depending on
an implicit host Probe responder and keeps validation and speculative-write
barriers intact.
Runner requires 19 unique CASE markers, balanced full-provenance events, counts
matching trace, race counters, simulator exit0 and `[END] status=PASS`.
The automatic system phase follows strict directed PASS and uses the same v1Config model and applies
Stage1, Stage2 and bank-aware Stage3 protocol analysis to that same trace.

## Static checks performed and remaining dynamic gates

Passed: git diff/check, all instantiation/assignment/write/ACK/validation searches
and manual source review; Python AST parsing, shell bash -n, lexical Scala/C++
delimiters, exactly 18 unique CASE source markers. No repository test/module was
imported or run; no compilation, generation, elaboration, Verilator, simulation
or regression was executed.

```
STATIC_REVIEW=PASS
OUTER_WRITE_PATHS_AUDITED=YES
ACK_PROVENANCE_AUDITED=YES
VALIDATION_RACES_AUDITED=YES
STAGE3_STATUS=READY_FOR_BUILD_AND_DIRECTED_VALIDATION
STAGE3_CLOSURE=NO
```

Dynamic gates remain: Scala/API/initialization and generated combinational-loop/
pin checks; actual SRAM timing/arbitration under the new stimuli; v1Config echo
negotiation; and Stage1/2 regression under added L2 serialization. Static PASS
does not claim hardware closure or use the old generated model as new evidence.

## Sole user command (agent did NOT execute)

The no-argument entry owns BUILD -> DIRECTED -> SYSTEM. No STAGE3_ROOT or manual
phase selection is required. Each invocation creates AI/TMP/stage3_runs/run_*;
prior completed phase directories are read-only and are reused only after full
HEAD/source/input/tool/environment/model/evidence/upstream-dependency checks.
Failed, interrupted or invalidated phases rerun in the new invocation. The old
manual-mode wrapper was removed. No script rewrites or deletes itself.

```bash
cd /data1/gzh/EC && source /data1/gzh/EC/chipyard/env.sh && bash /data1/gzh/EC/AI/Debug/scripts/stage3/stage3_run.sh
```

A fresh BUILD generates the directed target and v1Config target once each,
matching Stage2's two-model workflow, without simulation. DIRECTED runs one
process and requires exactly 18 unique CASE PASS markers, a unique END PASS,
zero preservation correctness errors and the existing precise race counters.
Injected stale/duplicate ACK observations are required; only explicitly ignored
ACKs with independent host checks are allowed in directed mode. SYSTEM starts
only after verified DIRECTED PASS and runs one process, then checks Stage1,
Stage2, Stage3 and bounded successful progress/live exit drain. Any failure
stops all later phases. A wall timeout stops the process group and fails.

Checker-only changes can reuse compatible upstream phases. Source/HEAD,
fixture, tool, environment or shared runner changes invalidate BUILD and all
transitive dependents. A changed directed checker invalidates DIRECTED/SYSTEM;
a system checker change invalidates SYSTEM. Reuse re-parses the original trace
with the current checker, rehashes artifacts and verifies phase seals and
upstream tokens; old phased-run PASS files are not eligible. See
[runner handoff](../Debug/history/reports/stage3_runner_20261018.md) for details.

Return the printed STAGE3_ROOT, summary.out/json, failure.json/log on failure,
and the directed/system evidence paths. A reused phase has reference.json
pointing to its original sealed result; the original logs stay there. No full
trace paste is required. The workload remains the verified existing
AI/TMP/stage1_workload.json. No build, elaboration, RTL generation, Verilator or
simulation was executed during this runner-only update.
