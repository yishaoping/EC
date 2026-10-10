# LSU assertion at 728000 (LSU.sv:7790)

## Assertion meaning

The generated assertion is `lsu.scala:306-310`:

```scala
assert(io.core.brupdate.b2.mispredict ||
       stq(stq_execute_head).valid ||
       stq_head === stq_execute_head ||
       stq_tail === stq_execute_head)
```

At the failing edge, the execute pointer selected an invalid STQ slot while it
was different from both the reclaim head and allocation tail. This is an STQ
ordering invariant failure, not a traffic-counter assertion.

## Waveform chain

The FST stored in `test.vcd` ends at time 1455230. The failing BOOM cycle is
approximately 728000 (the trace has a two-time-unit clock representation).
Near the end of the trace:

1. `stq_execute_head` repeatedly moves forward when a store request fires and
   moves backward when an older store nack arrives.
2. A strict store at STQ index `1010` receives `cacheCompletionAccepted` at
   about FST 1455221. This is the real DCache data-array write completion;
   the LSU marks the entry succeeded and consumes its strict token.
3. A delayed nack carrying the same STQ index arrives at about FST 1455225.
   It belongs to an older pipeline copy that overlapped the killed-store
   replay path, so it is no longer a replay request for the live STQ entry.
4. The old logic only tested `IsOlder(nack_idx, stq_execute_head, stq_head)`.
   It therefore rewound `stq_execute_head` from `1011` to completed index
   `1010`.
5. The index-`1010` entry is then reclaimed/invalidated while the execute
   pointer still points at it. On the next assertion edge, index `1010` is
   invalid, `stq_head` is `1011`, and `stq_tail` is different, causing the
   assertion at line 7790.

The same pattern is visible earlier: nack pulses follow request fires in the
7/8/9 ring slots, and the pointer oscillates as the cache is blocked. Those
oscillations are expected only while the referenced STQ entry is still live;
the final late nack violates that precondition.

## Hardware correction

`lsu.scala` now builds `storeNackMatchesLiveStq`. A store nack can rewind the
execute pointer, or suppress a completion advance, only when:

- the referenced STQ slot is still valid;
- the slot has not already succeeded; and
- for strict stores, the nack token still matches the slot token.

Both the nack handler and `olderStoreNackForcesReplay` use this same predicate.
This prevents a late response from an older DCache copy from rewinding into a
completed or recycled slot. It does not change request, store, packet, or
strict-completion counter update points.

## Verification performed

The BOOM generator compiles successfully with:

```text
cd /data1/gzh/EC/chipyard
./.conda-env/bin/sbt -batch 'project boom' Compile/compile
```

No RTL generation or simulation was run.
