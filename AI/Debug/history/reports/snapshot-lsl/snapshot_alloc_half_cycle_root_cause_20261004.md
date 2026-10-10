# Snapshot allocation half-cycle failure

## Evidence

The failing run is `chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd`.
At the first failing boundary:

| FST time | Signal | Observation |
|---:|---|---|
| 393085 | `R_IC.fsm_state` | enters `fsm_snap` |
| 393089 | `snapshot_ready`, `snapshot_accepted`, `if_dosnap`, `package_allocated` | become high after the clock transition |
| 393091 | `package_allocated` | returns low; `packet_seq_counter` remains 1 and `active_packet_seq` remains 1 |
| 393653 | Rocket LSL dequeue | first checked load request starts |
| 393657 | `ELU.err_ld` | request/response addresses differ; request is `0x200bff8`, response is `0x80087f58` |

`allocated_packet_seq` is already 2 at 393091, but the sequential registers that
own the package remain 1. This proves that the allocation pulse was visible as a
combinational level but was not high across the edge that updates the R_IC
registers. The resulting package owner and memory-stream boundary are different.

## Failure chain

```text
snapshot_quiet rises with the ROB empty
 -> R_IC generates a half-cycle snapshot/allocation pulse
 -> R_IC misses the pulse in its sequential allocation update
 -> active_packet_seq stays on package 1 while the next boundary is being sent
 -> Rocket LSL consumes a stream with the wrong package boundary
 -> ELU detects request/response address mismatch
 -> package is cancelled, watermark cannot advance, and BOOM eventually hangs
```

The 461000 assertion is the BOOM pipeline watchdog symptom. Lowering its bit only
changed the observed stop time.

## Source fix

`boom/src/main/scala/exu/core.scala` now registers the quiet predicate once more:

```scala
val snapshot_quiet_armed = RegNext(snapshot_quiet, false.B)
ic_master.io.if_ready_snap_shot := snapshot_quiet_armed.asUInt
```

This makes R_IC see a full-cycle readiness level before it accepts the snapshot.
Dispatch remains blocked by the existing snapshot drain while the ROB is empty,
so the extra cycle cannot admit a new uop between readiness and capture.

The original watchdog threshold (`idle_cycles.value(20)`) was restored. Existing
`dontTouch` probes remain in place.

## Verification

```text
./.conda-env/bin/sbt -batch 'project boom' Compile/compile
git diff --check -- chipyard/generators/boom/src/main/scala/exu/core.scala
```

Both checks pass. No RTL generation and no simulation were run.
