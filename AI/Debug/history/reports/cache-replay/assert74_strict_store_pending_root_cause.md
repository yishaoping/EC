# Assert 74: strict store pending underflow

## Scope

This note analyzes the saved FST waveform
`chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd`
and the BOOM LSU/DCache/MSHR sources. No simulation or RTL generation was
run, and no RTL or software file was changed.

The Verilator time scale in the log is twice the FST time scale. The reported
log time `[198000]` corresponds to the final FST interval around `396351..396353`.

## Assertion meaning

The generated assertion at `gen-collateral/LSU.sv:7633` comes from
`chipyard/generators/boom/src/main/scala/lsu/lsu.scala:1894-1902`:

```scala
val committedStrictStores = PopCount(archStoreEvents)
val completedStrictStores =
  io.dmem.traffic_store_cache_complete.asUInt +
    io.dmem.traffic_store_uncache_complete.asUInt
val strictStorePendingBase = strictStorePending + committedStrictStores
val strictStorePendingUnderflow =
  completedStrictStores > strictStorePendingBase
assert(!strictStorePendingUnderflow,
  "[traffic] strict store completion events exceed committed in-flight count")
```

The assertion is a same-cycle accounting check. It permits completions for
stores already pending, plus stores committed in the current cycle. It fails
when a completion arrives with no corresponding committed in-flight store.

## Proven waveform chain

The traffic window is:

```text
traffic_reset        FST 1..383631
traffic_counting=1   FST 383633..
traffic_check_state=1 FST 383665..
traffic_check_state=0 FST 396323
assertion            FST 396353
```

Reconstructing the counters over this window gives:

```text
committedStrictStores  = 870
completedStrictStores  = 871
```

The counters still agree immediately before the failure. At FST `396351`,
one strict cache-store completion consumes the last pending entry. At FST
`396353`, a second strict cache-store completion arrives with
`strictStorePending=0`, `committedStrictStores=0`, and
`completedStrictStores=1`; therefore `strictStorePendingUnderflow=1`.

The two completion events are distinct requests, not a level-sensitive repeat:

| FST time | DCache source | address suffix | result |
| ---: | --- | --- | --- |
| 396351 | `s3_valid=1`, `dataWriteArb.io.in(0).fire` | `...580` | strict cache-store completion |
| 396353 | `s3_valid=1`, `dataWriteArb.io.in(0).fire` | `...5c` | strict cache-store completion |

Both requests carry `traffic_arch_check=1`, `traffic_cacheable=1`,
`uses_stq=1`, and `mem_cmd=M_XWR` into `s3`. The completion expression in
`dcache.scala:1587-1589` therefore emits one event for each physical array
write.

## Replay path

The final requests are MSHR replays:

```text
396345  MSHR 2 replay: stq_idx=11, address ...580
396347  MSHR 2 replay: stq_idx=13, address ...5c
396349  s2 accepts the ...580 replay
396351  s3 completes the ...580 store
396351  s2 accepts the ...5c replay
396353  s3 completes the ...5c store
```

The source preserves the metadata through every replay stage:

* `dcache.scala:543-551` copies `traffic_arch_check`, cacheability, and
  packet sequence from `mshrs.io.replay` into `replay_req`.
* `dcache.scala:837-841` copies the same fields when a request enters an MSHR.
* `mshrs.scala:rpq.io.enq.bits := io.req` stores the complete request in the
  replay queue, and `mshrs.scala:346-349` emits it again after refill.

Thus a delayed store can reach the physical write point long after the ROB
commit event that originally qualified it. The DCache completion signal is
defined by the physical write (`dataWriteArb.io.in(0).fire`), while
`strictStorePending` is defined by ROB architectural commit events. There is
no request identity, completion token, or consumed bit joining those two
domains. A replay that remains live across cache/barrier activity can therefore
produce a second physical completion carrying the old qualification bit after
the pending counter has already been consumed.

## LSU qualification details

At address generation (`lsu.scala:1093-1112`), a store can set
`stq.bits.traffic_arch_check` from the current traffic window before it has
architecturally committed. At retirement (`lsu.scala:1788-1848`), the field is
overwritten with `arch_store_in_scope`, which is the correct architectural
qualification. The waveform shows that the final `stq_idx=11` and `stq_idx=13`
entries did eventually commit, so the early qualification alone is not enough
to identify one particular final request as uncommitted. It is nevertheless a
hazard: an address-stage request can enter an MSHR/RPQ, retain a stale
qualification, and later be replayed after the STQ entry has been cleared or
reused.

The robust invariant is that the bit carried into MSHR/RPQ and the bit used for
the completion counter must be assigned to one architectural store instance,
not merely to an address-stage/STQ lifetime.

## Relation to the uncommitted DCache changes

The uncommitted DCache work adds cross-package blocking, an extra writeback and
metadata-write arbitration input, and barrier-dependent scheduling. Those
changes alter when a resident line is blocked, written back, cleared, and
replayed. The saved waveform does not expose the internal
`crossPackagePending` state, so it cannot attribute the extra event to one
single new line of Chisel. It does prove the contract failure that the changes
expose: replay metadata remains completion-eligible while the LSU pending
account has no matching architectural token.

The original DCache completion predicate is therefore too weak for the new
delayed replay behavior. Counting every qualifying `dataWriteArb` fire as a
new strict store is not idempotent with respect to replay/refill/writeback
activity.

## Root cause

The root cause is a broken one-to-one contract between the two counters:

```text
ROB arch store commit
  -> strictStorePending increment

MSHR/RPQ replay carrying old traffic_arch_check
  -> DCache physical array write
  -> strict-store completion increment
```

The second path has no architectural-store identity or once-only completion
guard. Under the modified cache scheduling/barrier path, two replayed stores
complete after the pending balance reaches zero; the second event causes the
assertion.

## Repair constraints for the next change

Any fix should preserve normal BOOM store execution and keep the traffic
measurement separate from cache correctness. The implementation must:

1. qualify ordinary stores at architectural commit, not at address generation;
2. carry a stable per-store token (or an equivalent once-only completion bit)
   through MSHR/RPQ replay;
3. consume that token exactly once at the physical completion point;
4. clear or invalidate outstanding tokens on exception, branch kill, STQ reuse,
   and traffic-window reset;
5. keep barrier/writeback scheduling from creating a second completion event for
   one token.

Simply saturating `strictStorePending` on underflow would hide the protocol
violation and would make the reported totals incorrect.

## Reusable trace commands

The existing reader is `AI/Debug/fst_signal_trace`. For the failure boundary:

```sh
AI/Debug/fst_signal_trace \
  chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd \
  396330 396354 \
  'tile_reset_domain_boom_tile\\.(lsu\\.(strictStorePending|strictStorePendingBase|strictStorePendingUnderflow|committedStrictStores|completedStrictStores)|dcache\\.(s2_type|s2_valid_REG|s2_req_0_.*|s3_valid|s3_req_.*|io__lsu_traffic_store_cache_complete))'
```

For the MSHR replay source:

```sh
AI/Debug/fst_signal_trace \
  chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd \
  396340 396354 \
  'tile_reset_domain_boom_tile\\.dcache\\.mshrs\\.(io_replay_.*|mshrs_2\\.io_replay_.*)'
```

