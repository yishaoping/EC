# Follow-on cache audit

This records source reasoning separately from benchmark/RTL evidence. A completed
at 1.424459x and B at 1.172810x; their exact patches and validation are retained in
`results/direct_sourcec_v2/` and `results/terminal_fetch8_prefix/`. Terminal bypass,
prefix fusion and fetch8 are validated B hardware. Candidate C remains separate.

## Completion overlap

`dcache.scala` has three distinct boundaries:

1. S2 captures the grant, AMO/SC return value and modified data in `s3_req` and
   `s3_result` (the return value is not calculated at completion dequeue).
2. `s3_effect_fire` is the accepted physical data-array write. On this edge image
   generation, provenance, duplicate-effect identity, and the SVB fast lease are
   updated together.
3. `completionQ` holds the identity-checked terminal result until a response lane
   and the LSU consumer accept it. Only this event releases functional STQ ownership.

The terminal arbiter can enqueue on boundary 2 instead of waiting one extra cycle
for `s3_applied`. A full completion queue still holds S3. `s3_applied` prevents a
second physical effect while blocked; failed SC, duplicate and cancellation paths
retain their existing registered handling. B also enables native empty-queue
flow-through: enqueue and dequeue may accept on the physical-effect edge. A
terminal never acknowledges a physical write that the array did not accept.

Removing the global `completionQ.count != 0` write-admission gate is separate.
The affected hit slot remains blocked by `completionPending(set)(way)`. Refills
and MSHR metadata changes are separately blocked by `installDrain` and
`mshrMetaDrain`; probe/victim drains also retain the per-slot/set completion guard.
MSHR reservation alone does not change `slotEpoch`: the epoch changes only at the
physical install/clear boundary, which is guarded. Thus reservation of a future
replacement cannot invalidate an outstanding completion. Replay launch still
requires S3 and the completion queue to drain; this candidate deliberately does
not relax that path.

Do not additionally allow simultaneous S3 turnover yet. A same-slot younger S2
request observes the pre-effect image generation, and the current S3 retirement
assignments have priority over S2 acquisition. That extension needs explicit
same-slot conflict handling and register-assignment proof.

Required dynamic validation: exactly-once effects and terminal results under
array/response backpressure; failed SC; AMO old-value return; duplicate token;
branch/exception cancellation; same-slot replacement/probe; pinned benchmark.

The upstream LSU audit found a further global barrier: `can_fire_store_commit`
waits for *all* older `functional_inflight` entries to complete, even after their
physical data effect. Thus removing the DCache queue-count gate alone is unlikely
to recover much with this producer. A refined prepared candidate,
`terminal_bypass.patch`, also enables native terminal-queue flow-through and
forwards an identity-matched accepted terminal into the LSU's older-store barrier
on that same edge. The next request is only entering S0 then; its physical effect
still follows the older accepted effect. The ordinary STQ terminal handler remains
the sole release point. An older replay-causing nack disables forwarding.

For empty-queue flow-through, the dequeue ownership assertion accepts only an
identical completion simultaneously accepted at enqueue, with the same live slot
epoch. A queued terminal still requires the registered pending responsibility.
The enqueue and dequeue updates leave the pending bit clear after a bypass; a
full queue still retains the applied S3 grant without repeating its effect.

These changes reduce effect-to-terminal latency. A younger store still waits for
the identity-matched terminal of every older inflight store. The implementation
was validated in `overlap_terminal_fetch8_prefix_20261103_031553_2a566233` and
committed as `40c8a18ca`.

For an empty terminal queue, free response lane and a hit that reaches S2 without
another blocker, the source-level cycle example is:

| Boundary | Frozen path | Candidate |
| --- | --- | --- |
| Older store S0 | n | n |
| S2 grant | n+2 | n+2 |
| Physical S3 effect | n+3 | n+3 |
| Terminal accepted in queue | n+4 | n+3 |
| Terminal delivered to LSU | n+5 | n+3 |
| Earliest younger store S0 | n+6 | n+3 |

This is a conditional local latency argument, not an observed stall breakdown or
a prediction of benchmark savings. Cache misses, response occupancy, replay,
LSU scheduling, and preservation can hide or change it. SC50 records actual
effect-edge enqueues/deliveries and identity-forwarded successor admissions.

The actual emitted IBuf RTL passes the independent stream scoreboard at both
fetch widths. Each run includes mixed RVC/RVI, cross-word RVI, branch-end
ownership, random stalls, C.EBREAK/ECALL/EBREAK suppression and three kills.
The driver checked 7,059 instructions in 11,410 cycles at four-byte fetch and
7,421 in 10,154 cycles at eight-byte fetch. Because kills occur at fixed cycles,
these totals cover different random stream suffixes and are correctness witnesses,
not a paired throughput benchmark. Hashes/results are in `ibuf_rtl_test.json`.

## Safe predecessor capture — withheld

The prepared one-line candidate routes a safe predecessor without a lower receipt
through SVB rather than legacy destructive writeback/invalidation. It is attractive
for hit retention, but broadens recovery dependence on SVB's SPEC state.

`svbFlush := io.traffic_reset || io.lsu.exception`; the SVB flush discards all SPEC
entries, including safe entries. WB_WAIT is retained through ACK. The failure-only
invalidate path correctly keeps safe SPEC, but it is not the only recovery-related
boundary. A safe captured snapshot can therefore be discarded before promotion
if an exception intervenes. Do not apply this optimization without first defining
and validating retention/promotion across epoch boundaries. This is a rejection
of the candidate's present correctness argument, not proof that the baseline's
full recovery path is validated.

The previous 4,774 unsupported-fallback events are rising-edge events, include
descriptor/resource guards, and cannot be called 4,774 avoidable stores or cycles.

## Retain the acknowledged safe copy in L1 — candidate C

This is separate from the withheld safe-SVB capture. SC8 in run A contains 787
complete observed legacy handoffs inside ROI. Their observed phases total 10,512
cycles from descriptor entry to safety, 766 from safety to WB acceptance, 51,079
from WB acceptance to receipt, and 787 from receipt to metadata clear. Optional
capture has gaps; these are observed local exposures, not full-run totals or
causal savings. The clear creates an additional demand refill that this phase
sum does not measure.

For a resident with T permission, send the existing safe WB as ReleaseData TtoT.
`MSHR.scala` explicitly retains TRUNK and the client bit for TtoT; this path is
already exercised by the validated SVB publications. At L1 the same freeze,
source allocation, same-line SVB ordering, data drain, full C transfer and exact
ReleaseAck are retained. Only the receipt transition changes: when resident tag,
slot epoch and image key still match, set `lowerPreserved` and release the freeze
without the destructive metadata clear. Branch permission retains the original
invalidating fallback. The candidate adds no permission-acquisition shortcut.

The resident may still need a probe downgrade/upgrade. A real ProbeAck remains
a coherence event; a simultaneous invalidating probe suppresses retained-receipt
acceptance. A prior probe that revoked the resident causes the identity match to
fail. Neither case resurrects local state, clears an active WB source early or
creates a receipt for another epoch. A non-invalidating probe can leave Branch;
ordinary permission checks still require an upgrade before writing.

The safe image is copied to the lower level before the matching ACK. The next
local write retains the existing lower receipt gate and clears that receipt on
its physical effect. If a newer image later reaches L2, L2 must preserve the safe
predecessor before overwrite, exactly as with a normal refill-derived receipt.
Historical protection, checker-result semantics and the watermark are unchanged.
No safe image is newly entrusted to SPEC SVB entries, so this candidate does not
broaden reliance on SPEC survival across exception/epoch flush.

An assertion checks the post-receipt resident epoch/key/receipt and freeze release;
existing frozen-snapshot assertions prevent physical writes or refills before ACK.
SC51 adds one mandatory traffic-window snapshot, reaching exactly 128 observer
identities. It counts requests, retaining requests, receipts, retained receipts,
revoked owners and invalidating clears. The analyzer requires source/capture
conservation, window equality and event subsets, without requiring request/receipt
equality across the sampled boundary.

Seven independent CPU contracts pass, including delayed copy/ACK, exact identity,
probe races, repeated lower-level historical retention and corrupted diagnostics.
These are source/abstract witnesses only. Scala/FIRRTL, combinational-loop checks,
firtool, generated geometry/clock comparison and C++ build passed in
`overlap_retained_copy_20261103_040650_0a6ef6bc`. The sealed binary is now running
the pinned BFS workload; top-level runtime validation remains pending.

The actual emitted `BoomWritebackUnit.sv` from sealed B was also tested directly
with Verilator: 300 voluntary TtoT/TtoN transactions, 1,600 accepted data beats,
300 exact receipts, 900 attempts blocked by a busy voluntary source, and 100
probe data transfers during the older ACK wait. Random stalls cover the row
reader, LSU-release notification and C channel. The scoreboard checks full bytes,
address, permission report, image key, epoch and receipt identity; probe buffering
cannot replace the older receipt owner. This validates the unchanged WB engine,
not the new top-level retained-receipt controller. Witness: `wb_rtl_test.json`;
reproducer: `scripts/run_wb_rtl.py GENERATED_DIRECTORY`.
