# BOOM `assert__assert_21` at 1260000: new-waveform root cause

## Conclusion

The assertion at `BoomCore.sv:6869` is the BOOM idle-pipeline watchdog. It is
the final symptom of a store queue entry that was consumed by the LSU request
handshake but dropped by the DCache S1 pipeline. The exact sequence is:

```text
STQ0/token 0x7108 is the execute request
  -> LSU reports dmem_req_fire=1
  -> the same cycle DCache has s2_store_failed=1 for an older STQ store
  -> DCache clears s1_valid for the new request
  -> STQ0 never reaches a valid S2/S3 physical write
  -> no token-qualified completion reaches LSU
  -> STQ0 remains succeeded=0/token_valid=1 at stq_head=0
  -> the STQ fills and BOOM stops retiring
  -> idle_cycles reaches its watchdog threshold
  -> assert__assert_21 fires
```

This is a DCache/LSU handshake ownership bug. It is not an LSU capacity
overflow and it is not a statistics-counter failure. The strict completion
guard correctly refuses to retire a store without a real physical completion.

## Watchdog mapping

The generated assertion is `BoomCore.sv:6869`; its source is
`generators/boom/src/main/scala/exu/core.scala:1753-1762`. The counter resets
on ROB commit, CSR stall, RoCC busy, or reset. The failure therefore means
that no ROB instruction committed for the watchdog interval. In this waveform
the final LSU corruption occurs around FST time `1994981`; the waveform then
contains only the idle interval until its end at `2519504`.

## Decisive waveform window

The relevant FST is
`chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd`.
The file has FST contents despite the `.vcd` suffix; its time range is
`0..2519504` with a 1 ps timescale.

### Before the lost request

At `1994979`:

* LSU's current request is STQ0, token `0x7108`; `stq_execute_head=0`.
* DCache S2 still contains the older STQ15 request, token `0x7107`.

At `1994981`:

* LSU reports `debug_dmem_req_fire_0=1` for the current STQ0/token `0x7108`
  request.
* DCache's S2 request is still the STQ15 store and reports `debug_s2_nack_0=1`
  with `debug_s2_nack_miss_0=1` and `s2_send_nack_0=1`.
* LSU reports a nack for STQ15, not STQ0.
* DCache reports `s1_valid_REG=0` in this same pipeline step.
* DCache's `debug_s3_valid=1` and `debug_data_write_pipeline_fire=1` belong
  to the older pipeline entry; they are not a completion for token `0x7108`.

The source condition in `dcache.scala:665-670` is:

```scala
!(s2_store_failed && io.lsu.req.fire && s0_req(w).uop.uses_stq)
```

and `s2_store_failed` is defined in `dcache.scala:812` as an S2 store nack
condition. Since the S2 metadata at `1994981` is a valid STQ15 store nack and
the LSU request handshake is true for STQ0, this condition clears S1 for the
new STQ0 request. The `s2_store_failed` wire itself is not preserved as a
waveform probe, so this one Boolean is derived from its RTL definition and the
probed S2 signals.

### After the lost request

* At `1994983` DCache S2 is invalid; there is no valid STQ0 S2 transaction.
* At `1994985` the STQ0 token appears only as S2 request metadata while the
  valid bit is not asserted; there is no corresponding S3 write.
* At `1994987` DCache handles another nack and its S2 metadata moves to an
  older request. STQ0 still has no completion.
* There is no `debug_s3_valid`/`debug_data_write_pipeline_fire` event carrying
  STQ0/token `0x7108`, and no `cacheCompletionAccepted` for that token.

The completion definition in `dcache.scala:1594-1606` requires the physical
data-array write handshake. LSU accepts it only when the index and strict token
match (`lsu.scala:1932-1947`). Metadata values while valid is low cannot count
as completion.

## Queue and watchdog propagation

At the end of the active traffic window, STQ0 remains live and committed with
token `0x7108`, `succeeded=0`, and `strict_store_token_valid=1`; `stq_head`
remains 0 while the queue fills. `clear_store` for an ordinary strict store
requires `succeeded && !strict_store_token_valid` (`lsu.scala:2065-2077`), so
the head cannot be reclaimed. Store dispatch then sees a full STQ, the ROB
eventually stops committing, and the generic watchdog fires.

## Root cause and repair requirement

The protocol currently treats `io.lsu.req.fire` as consumption by LSU while
the DCache can still kill that request through `s2_store_failed`. A request
that is killed this way must either:

1. not fire at the LSU/DCache interface, or
2. be explicitly replayed with its original STQ index and strict token.

The LSU execute pointer must advance only for a request that is accepted into a
replay-safe DCache path, and an older nack must not erase the identity of a
newer request that was simultaneously fired. Completion and traffic counters
must continue to use only the token-qualified physical write event; changing
that accounting to hide the lost request would reintroduce the earlier store
and package-count errors.

The source has now been updated accordingly. DCache keeps a one-entry
`killed_store_replay_req` register, blocks a second LSU request while it is
pending, and re-injects the saved request through the normal S0-S2 path. The
internal replay is excluded from the old S2-wide kill; a later resource nack
uses the ordinary LSU nack/re-execute path. See
`Debug/killed_store_replay_fix_20261001.md` for the implementation and compile
check. Runtime validation still requires a new waveform.

## Reusable extraction command

The FST probe utility used for this analysis is `/tmp/ec-fst-signal-trace-test`.
For the decisive window:

```text
/tmp/ec-fst-signal-trace-test test.vcd 1994950 1995010 \
  'tile_reset_domain_boom_tile.lsu.(stq_head|stq_execute_head|debug_dmem_req|debug_dmem_nack)|tile_reset_domain_boom_tile.dcache.(s1_valid_REG|debug_s2_|s2_send_nack|debug_s3_|debug_data_write_pipeline_fire)'
```
