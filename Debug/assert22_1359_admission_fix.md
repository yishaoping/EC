# `assert__assert_22` admission-order fix

This note records the source-only fix for the sequence-57 admission deadlock
described in
[`assert22_1359_waveform_analysis.md`](assert22_1359_waveform_analysis.md).
No generated RTL, simulation output, or hardware collateral was changed.

## Fixed invariants

1. A candidate sequence must not be blocked by the candidate's own presence
   in the CDC queue. The new-package admission predicate therefore checks
   only local checker cleanup (`R_ICSL`, RSUSL, and LSL), not the aggregate
   `io.cdc_empty` level.
2. A newer data sequence must not be dequeued while the previous package or
   its result is still being cleaned up. The Rocket checker now gates
   `io.packet_cdc_ready`, which is the bit used by GHM as the data-CDC dequeue
   permission.
3. Once a sequence is admitted, or is in the `start_pending`/`checking`
   phase, its remaining data beats continue to flow. ARF/CPS/ECP dequeue
   remains ordered behind the data anchor in GHM.

## Source change

In
[`RocketCore.scala`](../chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala),
the cleanup predicate is now split as:

```scala
val checker_local_cleanup_done = icsl.io.cleanup_done &&
  (rsu_slave.io.rsu_status === 0.U) && lsl.io.if_empty
val checker_cleanup_done = checker_local_cleanup_done
```

The data dequeue permission is derived from the package lifecycle:

```scala
val package_data_admission_ready = package_seq_reg === 0.U ||
  package_check_active || package_start_pending || package_ready_for_new
val packet_cdc_ready_raw = rsu_slave.io.cdc_ready |
  lsl.io.cdc_ready.asUInt | io.imem.bjl_cdc_ready.asUInt
io.packet_cdc_ready := Mux(package_data_admission_ready,
  packet_cdc_ready_raw, 0.U)
```

Consequently, when a new data head is waiting, the sequence can be admitted
as soon as the old local state is clean; the data head does not make
`checker_cleanup_done` false. If cleanup is not complete, GHM retains the
head in its AsyncQueue instead of writing an orphan packet into LSL/RSUSL.

The existing sequence latch, data-anchor ordering, independent result CDC,
held BOOM release level, and bounded cancellation paths remain in place.

## Verification

```text
sbt -batch 'project chipyard' compile  PASS
bash -n Debug/trace_assert22_1359.sh  PASS
trace_assert22_1359.sh FST extraction  PASS
```

The saved FST was not replayed after this source change, so runtime behavior
must be confirmed by a later normal Chipyard build and simulation run. That
validation is intentionally outside this source-only fix.
