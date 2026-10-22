# Stage 2 directed failure: selected-way epoch was indexed twice

## Evidence boundary

The failing directed run is `AI/TMP/stage2_validation_d5wr10l1/`. Its `BUILD=PASS`
was produced before the current source correction, so its generated RTL and
`VStage2Harness` are retained as historical evidence only. They must not be
used to judge the current source. The first meaningful directed diagnostic is
line 72 of `module.trace.log`:

```text
STAGE2_DIRECTED=FAIL reason=premature ACK needs stalled first C beat
```

The preceding trace repeatedly reports `STAGE2_TX BLOCK` for line `0x80001000`
with `epoch=1`, `lower=0`, and `safe=1`, but never reports `STAGE2_TX PRESERVE`.
Therefore the immediate block is a missing preservation request, not an early
ReleaseAck. The test stopped before injecting the ACK because no held C beat
existed.

## Root cause and fix

In `chipyard/generators/boom/src/main/scala/lsu/dcache.scala`,
`s2_lookup_epoch(0)` is the complete epoch captured for the selected way. The
old condition indexed it again with `s2_store_way`:

```scala
s2_lookup_epoch(0)(s2_store_way) === slotEpoch(...)
```

For way 1 and epoch 1 this compares a single bit against the complete epoch,
so the cross-package preservation request is suppressed. The condition now
compares the complete captured value:

```scala
s2_lookup_epoch(0) === slotEpoch(s2_store_set)(s2_store_way)
```

This keeps the existing epoch gate and makes the preservation request eligible
only for the same selected slot identity.

## Diagnostic improvement

`AI/Debug/scripts/stage2/stage2_test.cpp` now records whether a preservation C
beat was ever valid or fired. If the 800-cycle precondition window still sees
no held beat, it emits one structured `STAGE2_CHECK_FAIL` explaining whether
the request was never issued or never exposed a stall, with `c_valid_seen`,
`c_fire_seen`, release count, and active state. The runner in
`AI/Debug/scripts/stage2_validation.py` additionally reports all structured
case failures, missing cases, independent-effect errors, and missing L2
denied/approved event pairs in the terminal summary and coverage JSON.

## Checks performed

- 57 `test_stage2_validation` unit tests passed; these use mocked commands and
  host declaration stubs and do not start hardware tools.
- Python compilation, shell syntax checks, and `git diff --check` passed.
- The historical run was compared with the current source boundary; its
  generated model is stale relative to this correction.

Static evidence and current source hashes are recorded in
`AI/TMP/stage2_directed_epoch_fix_4_eyionz/static.correction.json`.

No Scala compile, hardware generation, elaboration, Verilator build, directed
simulation, or system simulation was run in this round. A fresh `all` run must
regenerate the model before the correction can be validated dynamically.

## Remaining validation

The first directed case must observe a held preservation C beat, reject the
injected matching-key ACK until all C beats are accepted, and then continue to
the remaining cases. The runner must stop before system simulation if any case,
effect guard, key/receipt check, or denied A regression is missing or fails.
