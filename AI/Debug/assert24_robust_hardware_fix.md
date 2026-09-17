# Robust hardware fix for `assert__assert_24`

## Scope

This change closes the two independent failure paths identified in
`assert24_1187_comprehensive_analysis.md` without changing the BOOM ownership
watchdog:

1. a timer interrupt in checker postchecking leaked an architectural trap into
   the next package;
2. a type-insensitive data-ready OR allowed memory logs to overrun R_LSL.

No simulation, waveform replay, RTL elaboration, or hardware generation was
run while implementing this change.

## Protocol invariants implemented

### Exception and return lifecycle

- R_ICSL records `trap_depth` and `resume_state` for both normal and privileged
  checking.
- Exceptions have priority over completion and direct return in checking and
  postchecking.
- A postchecking exception resumes postchecking only after the matching
  architectural xRET.
- `if_rh_cp_pc` and privileged return stay blocked while `excpt_mode`, local
  trap depth, or the current exception pulse is active.
- New package admission uses `context_idle`, which requires local cleanup, no
  architectural trap, no local trap, and no pending special-PC return.
- COPY remains pending until a data-anchored package owns a clean context.

### Atomic packet consumption

The checker data channel now follows a conventional head-valid/beat-ready
contract:

```text
GHM AsyncQueue head valid + payload
  -> RocketTile sequence ownership check
  -> per-lane type decode
  -> AND of every addressed lane's destination ready
  -> one atomic beat-ready level back to GHM
  -> dequeue fire and exactly-once consumer valid
```

- Memory, CSR, RoCC, and BJL readiness are selected by the actual lane type.
- A mixed two-lane beat advances only when every addressed destination can
  accept it.
- A newer sequence cannot dequeue while the current sequence is owned.
- Stale and reserved-zero sequence heads are drained without entering a local
  consumer, so they cannot block a valid data/ARF pair.
- ARF/CPS remains on its independent CDC path and is accepted only when it
  matches the fired data anchor or the currently owned sequence.
- Unsupported addressed data types mark the package as a protocol error rather
  than entering an arbitrary consumer.

### Lossless and bounded LSL behavior

- GH_FIFO and GH_MemFIFO expose their actual enqueue readiness.
- R_LSL exposes separate memory, CSR, and RoCC ingress readiness.
- The existing `depth - 2` reservation covers the registered ingress stage and
  a maximum two-lane beat.
- An enqueue-capacity violation produces `ingress_overflow`; RocketCore emits a
  sequenced `CANCELLED` result and resets R_LSL instead of silently losing a
  record and waiting for the BOOM watchdog.
- Dequeue selection skips an unexpectedly empty round-robin bank when another
  bank contains data. Lossless traffic keeps the original order; the fallback
  prevents one bank hole from causing permanent replay.

### Local progress supervision

Package ownership now has a 16-bit no-progress watchdog covering START_WAIT,
INGRESS, EXEC, TRAP, and RETURN gaps. Only package-relevant events reset it;
management or trap-handler commits outside checker mode do not. The existing
short ARF-tail and execution-tail timeouts remain as more specific diagnostics.

On timeout, overflow, or other bounded cancellation:

```text
local CANCELLED(seq)
  -> result queue / result CDC
  -> BOOM ownership release

local R_ICSL/R_LSL cleanup
  -> wait for a live trap's matching xRET, if required
  -> controlled return to pc_special for an executing package
  -> context_idle
  -> next-package admission
```

Result delivery and local cleanup remain intentionally decoupled.

## Files changed

- `chipyard/generators/rocket-chip/src/main/scala/r/R_ICSL.scala`
- `chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala`
- `chipyard/generators/rocket-chip/src/main/scala/tile/Core.scala`
- `chipyard/generators/rocket-chip/src/main/scala/tile/RocketTile.scala`
- `chipyard/generators/rocket-chip/src/main/scala/r/R_LSL.scala`
- `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GH_FIFO.scala`
- `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala`

## Static verification

The following compile-only check passed:

```sh
cd /data1/gzh/EC/chipyard
sbt 'project rocketchip' compile
```

This compiled the modified Scala sources to JVM classes only. It did not
elaborate Chisel or generate RTL. Use `check_assert24_hardware_fix.sh` for the
repeatable source checks and optional compile-only check.

## Useful future waveform signals

For a later user-authorized run, retain these signals in addition to the
existing `trace_assert24_1187.sh` sets:

```text
R_ICSL: trap_depth, resume_state, io_context_idle, io_return_pending
RocketCore: arch_trap_depth, excpt_mode, package_progress_timeout_counter
RocketCore: io_packet_active_seq, io_packet_current_seq_active
RocketTile: dataHeadValid, dataBeatReady, dataBeatFire, dataSeqDiscard
R_LSL: io_cdc_ready_mem/csr/rocc, io_ingress_overflow, *_deq_bank
GHM: u_data_cdc.io_deq_valid/ready, dataHeadInOrder
```
