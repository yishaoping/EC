# Follow-on cache audit

This is source reasoning, distinct from benchmark/RTL evidence. The first
experiment completed at 1.424459x. Its sealed source patch is retained under
`results/direct_sourcec_v2/`. Terminal bypass, prefix fusion and fetch8 are active
only in the follow-on candidate currently being built.

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
retain their existing registered handling. Queue flow-through is disabled, so a
newly enqueued terminal result cannot be consumed before the physical-effect edge.

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
the identity-matched terminal of every older inflight store. The candidate is
active in `overlap_terminal_fetch8_prefix_20261103_031553_2a566233`.

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
