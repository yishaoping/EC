# LSL SyncReadMem Prefetch Fix

## Root cause

The LSL matching logic compared the FIFO head type/address before the
`SyncReadMem` head had been read. `GH_MemFIFO.io.deq_bits` was driven by
`mem.read(readPtr, io.deq_ready)`, while `io.deq_ready` was asserted only after
the comparison succeeded. A nonempty FIFO therefore stayed permanently
unread and blocked checker ownership cleanup.

## Implemented protocol

`GH_MemFIFO` now exposes `io.deq_read` separately from `io.deq_ready`.

- `deq_read` launches the synchronous RAM read and does not change pointers,
  occupancy, or dequeue counters.
- `deq_ready` remains the committed dequeue handshake and is the only signal
  that advances `readPtr` or decrements occupancy.
- Existing register FIFO (`GH_FIFO`) behavior is unchanged.
- Non-LSL memory FIFO users connect `deq_read` to their existing dequeue
  signal, preserving their previous timing.

Each LSL memory bank has:

- `lsl_prefetch`: occupied bank with no valid prefetched head;
- `lsl_head_valid`: one-cycle-later indication that `SyncReadMem` data is
  available for comparison;
- type/address matching before dequeue;
- `resp_packet_reg`, loaded on the actual dequeue fire and used for the
  response in the same registered response phase.

The resulting chain is:

```text
FIFO nonempty -> deq_read -> SyncReadMem response -> head_valid
-> type/address match -> deq_ready/deq_fire -> resp_packet_reg/resp_valid
```

## Observation points

`R_LSL` keeps `dontTouch` on `lsl_prefetch`, `lsl_head_valid`, selected head
fields, match predicates, `lsl_deq_fire`, and `resp_packet_reg`. These points
allow a later trace to distinguish enqueue, RAM prefetch, valid head, match,
dequeue, and response without relying on generated signal optimization.

## Verification boundary

- `sbt -batch 'rocketchip/compile'` passed after the change.
- `sbt -batch 'chipyard/compile'` passed after the change.
- `git diff --check` passed for all modified source files.
- No simulation was run and no RTL/hardware was generated.

The next simulation should specifically verify that each nonempty LSL bank
shows one `deq_read` pulse before its first matching `deq_ready`, that a type or
address mismatch does not decrement FIFO occupancy, and that each response
payload remains stable while `resp_valid` is asserted.

## FIRRTL generation error follow-up

The first generation attempt after this change failed before RTL emission with:

```text
java.lang.NumberFormatException: For input string: "_selected_head_valid_T"
```

The generated FIRRTL showed that `dontTouch(selected_head_valid)` had been
applied to the raw dynamic expression `lsl_head_valid(lsl_deq_bank)`. The old
FIRRTL target parser interpreted the generated temporary name as a numeric Vec
index. `selected_head_valid` is now an explicit named `WireInit`, assigned from
the dynamic Vec read, and `dontTouch` is applied to that named wire. This keeps
the observation point while avoiding the temporary target path.
