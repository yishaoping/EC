# `assert__assert_22` deadlock fix

This note records the source changes made after
[`assert22_current_waveform_analysis.md`](assert22_current_waveform_analysis.md).
The fix is source-only. No simulation, Verilator replay, RTL generation, or
hardware generation was run.

## Root cause addressed

The old result path required:

```text
R_ICSL.clear_ic_status
 -> package_locally_ready
 -> Rocket result CDC handoff
 -> GHM result release
 -> BOOM clear_ic_status_tomain
```

`R_ICSL.clear_ic_status` was only asserted in the local reset state, while the
checker could remain in `fsm_checking` after the package result was formed.
That made result delivery and local checker cleanup mutually dependent.

## Implemented protocol changes

### 1. Explicit R_ICSL completion and cleanup state

`R_ICSLIO` now exports:

- `package_exec_done`: sticky instruction-stream completion, set after the
  normal/privileged instruction boundary and cleared at package start, reset,
  or cancellation;
- `cleanup_done`: asserted only while R_ICSL is in reset/nonchecking.

The package result is not considered a normal completion until both the data
side tail and `package_exec_done` are true.

### 2. Result handoff is independent of local clear

`RocketCore` now connects the local result queue directly to the GHM
`valid/ready` handshake:

```text
package_result_queue.deq.valid
    -> io.package_result_valid
package_result_queue.deq.ready
    <- io.package_result_ready
```

`icsl.io.clear_ic_status` no longer gates this handoff. GHM's sequenced result
CDC dequeue remains the only BOOM ownership release event.

### 3. Cleanup remains a separate admission barrier

`package_cleanup_pending` is set when a result enters the local result queue.
A newer package is admitted only after:

```text
result handoff completed
R_ICSL cleanup_done
RSU status is idle
LSL is empty
GHM packet ingress is empty
```

New sequence pulses remain held by the existing pending-sequence register while
this barrier is active. This prevents a released result from allowing the old
R_ICSL state to be overwritten by a new package.

### 4. Bounded execution-completion cancellation

If data/ARF/CSR/LSL completion is reached but `package_exec_done` is not
observed for 65,535 Rocket checker cycles, the package enters the existing
`package_cancelled` path. That path resets R_ICSL and emits a sequenced
CANCELLED result, so the BOOM slot can still be released without waiting for an
unbounded local execution condition.

The timeout is below the BOOM checker watchdog budget and only starts after the
package data tail is complete. It does not change normal package completion.

### 5. CDC ordering and first-package races

An older ARF fragment at the CDC head is drained as stale when its sequence is
below the data head. This avoids a mutual wait where data cannot dequeue until
ARF advances while ARF is held waiting for data. The initial data anchor is
also accepted when it arrives before the GHE `COPY` pulse; the package remains
start-pending until R_ICSL accepts that pulse. `COPY` itself is held across the
one-cycle R_ICSL reset/nonchecking transition.

## Files changed

- [R_ICSL.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/r/R_ICSL.scala)
- [RocketCore.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala)
- [GHM.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala)

Existing GHM result-release logic in
[GHM.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala)
was retained: `result_deq_fire` drives a held release level until BOOM observes
the checker status clear. Its data/ARF CDC ordering now also drains stale ARF
heads independently.

## Static checks

```text
sbt -batch 'project chipyard' compile  PASS
git diff --check                          PASS
```

No generated collateral was updated, so the saved FST cannot validate this
source revision. A later validation run must generate normal Chipyard
collateral and capture a new waveform.
