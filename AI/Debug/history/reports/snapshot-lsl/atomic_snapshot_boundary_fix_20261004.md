# Atomic snapshot boundary fix (2026-10-04)

## Problem addressed

The previous boundary used `rob.io.can_commit_withoutGC` as snapshot readiness.
That signal means that the current ROB head can commit; it does not mean that
the ROB is empty.  The waveform showed the snapshot and delayed R_RSU capture
followed by a BOOM commit of `addi a2,a2,-1`, so the saved x12 value was one
architectural update behind the checker value.  The resulting d7 mismatch
stopped the safe watermark and eventually filled the STQ, producing the
`Pipeline has hung` assertion.

## Source changes

- `boom/src/main/scala/exu/core.scala`
  - Snapshot readiness now requires `rob.io.empty` plus registered quiet-cycle
    guards for commit, CSR stall, exception, and RSU activity.
  - Added `snapshot_dispatch_block`: new dispatch is blocked while R_IC drains
    the ROB and while R_RSU performs its delayed snapshot capture.
  - ROB retirement remains enabled during the drain; it is blocked only after
    the snapshot pulse is accepted.
  - Added assertions that a snapshot cannot be accepted with a non-empty ROB or
    a simultaneous architectural commit.

- `rocket-chip/src/main/scala/r/R_IC.scala`
  - Added `rob_empty` input and local `snapshot_ready` guard.
  - Added `snapshot_drain` and `snapshot_capture` observation outputs.
  - In `fsm_snap`, `if_pipeline_stall` is low while waiting for the ROB to
    drain, then high on the accepted snapshot edge.

- `rocket-chip/src/main/scala/r/R_RSU.scala`
  - Preserved `doSnapshot`, request, and saved `arfs_ss(12)` in generated waves.

- `rocket-chip/src/main/scala/r/R_ICSL.scala`
  - Preserved `sl_counter`, `ic_counter_shadow`, `ic_counter_done`, and
    `new_commit` so the tail completion rule can be checked in the same run.

The packet allocation remains tied to the existing `snapshot_accepted` pulse;
the new dispatch/RSU hold guarantees that no architectural state changes occur
between allocation and the delayed ARF capture.

## Static validation

```text
git diff --check -- chipyard/generators/boom/src/main/scala/exu/core.scala \
  chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala \
  chipyard/generators/rocket-chip/src/main/scala/r/R_RSU.scala
PASS

./.conda-env/bin/sbt -batch 'project boom' Compile/compile
[success] Total time: 19 s
```

`check_debug_invariants.py` also passed its source checks.  Existing unrelated
whitespace warnings remain in `Experiment/流量分析.typ`.  No simulation, RTL
generation, or generated collateral modification was performed.

## Expected waveform invariant

At each `snapshot_capture` pulse:

```text
rob.empty = 1
rob.commit.arch_valids = 0
snapshot_dispatch_block = 1
R_RSU.doSnapshot = 1 one cycle later
arfs(12) is unchanged through the capture hold
```

The existing `R_ICSL` `sl_counter + 1` completion rule was left unchanged.  It
is a separate tail-accounting rule and the saved d7 waveform did not prove that
it was the primary cause of the ARF mismatch.

The pre-change evidence was preserved as:

- `Debug/test_before_atomic_snapshot_fix_20261004.vcd`
- `Debug/test_before_atomic_snapshot_fix_20261004.log`
