# Snapshot guard combinational loop

## Symptom

FIRRTL reported a `BoomCore` combinational loop through `rob.io.commit.arch_valids`, `if_ready_snap_shot`, `R_IC.if_dosnap_priv`, `R_RSU.core_hang_up`, `rsu_stall`, and `rob.io.gh_stall`.

## Cause

`snapshot_quiet` directly consumed live ROB commit and RSU busy outputs while driving the R_IC snapshot request. The snapshot request feeds back into the same ROB stall path.

## Fix

`core.scala` now uses registered previous-cycle commit/RSU/CSR/exception guards and keeps `rob.io.can_commit_withoutGC` as the snapshot readiness condition. The registered guards break the combinational path while preserving the original snapshot handshake. Relevant signals remain `dontTouch`-ed for waveform inspection.

No simulation or hardware generation was run for this source-only fix.
