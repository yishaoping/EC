# DCache killed-store replay fix

## Change

`chipyard/generators/boom/src/main/scala/lsu/dcache.scala` now retains one
complete LSU STQ request when an older S2 store raises `s2_store_failed` in the
same cycle that the newer request fires. The request is stored in
`killed_store_replay_req`, and the next available LSU pipeline slot replays it
with its original address, uop/STQ index, packet sequence, strict-store token,
and traffic fields.

The normal S1 kill remains for the conflicting request. The S2-wide kill was
removed so the internal compensation replay cannot be killed a second time;
if it encounters a resource conflict, the normal DCache nack reaches LSU and
LSU rewinds `stq_execute_head` for another retry.

`io.lsu.req.ready` is blocked while the compensation replay is pending, so a
second request cannot overwrite the single replay slot. New waveform probes
are available as `debug_killed_store_replay_*` for the valid/fire/STQ/token
identity.

Completion and statistics logic were not changed. A strict store is still
counted only at the token-qualified physical data-array write, and LSU still
consumes completion only after STQ index and token match.

## Compile check

```text
cd /data1/gzh/EC/chipyard
./.conda-env/bin/sbt -batch 'project boom' Compile/compile
```

Passed on 2026-10-01. No RTL generation or simulation was run.

## Runtime check still required

The next benchmark run should verify that the former STQ0/token `0x7108`
window shows `debug_killed_store_replay_valid`, followed by
`debug_killed_store_replay_fire`, then a valid S2/S3 event and one matching
`cacheCompletionAccepted`. Package, store, and completion counts must be
compared against the prior run; this source change has not been runtime
validated in this step.
