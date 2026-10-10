# Watchdog threshold and snapshot static audit (2026-10-04)

## Changes checked

- `BoomCore` pipeline watchdog now uses bit 18 (`2^18` cycles).
- Checker and release protocol watchdogs use the same `ecWatchdogBit` value,
  so all three diagnostics have the requested common threshold.
- `R_IC` cooling no longer asserts `if_pipeline_stall`.  BOOM dispatch remains
  blocked by `snapshot_drain`, while existing ROB entries can retire and reach
  the `rob_empty`-gated snapshot boundary.
- The registered `snapshot_quiet_armed` level remains in place to avoid the
  earlier half-cycle allocation pulse.  `R_IC` still requires both this level
  and `rob_empty`, and `snapshot_accepted` is restricted to `fsm_snap`.

## Static checks

```text
cd /data1/gzh/EC/chipyard
./.conda-env/bin/sbt -batch 'project boom' Compile/compile
success (2026-10-04)

python3 /home/guozh/.codex/skills/ec-debug-analysis/scripts/check_debug_invariants.py /data1/gzh/EC
PASS: all known source/protocol checks

git diff --check -- chipyard/generators/boom/src/main/scala/exu/core.scala \
  chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala \
  chipyard/generators/rocket-chip/src/main/scala/r/R_RSU.scala
PASS for the three target files
```

The repository-wide check still reports pre-existing trailing whitespace in
`Experiment/流量分析.typ`; it is unrelated to these changes.

## Boundary invariants to verify in the next waveform

At every `snapshot_capture` pulse:

```text
rob.empty = 1
rob.commit.arch_valids = 0
packet_alloc_valid = 1 for one cycle
packet_alloc_seq = active_packet_seq + 1 (the registered active value updates on that edge)
R_RSU.doSnapshot = 1 on the following cycle
```

During `fsm_cooling` and `fsm_snap`, `snapshot_dispatch_block` must remain high
until the delayed R_RSU capture has completed.  No simulation or RTL generation
was run for this audit.
