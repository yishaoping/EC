# Watchdog early-stop and waveform probes

## Change

The BOOM idle-pipeline watchdog in
`chipyard/generators/boom/src/main/scala/exu/core.scala` now asserts on
`idle_cycles.value(18)` instead of `value(20)`. This is a debug-only earlier
stop, reducing the no-commit observation window from `2^20` to `2^18` BOOM
cycles while retaining the same reset conditions and assertion meaning.

## Added observation points

The following source files contain `dontTouch` probes. They are observation
only and do not drive control, handshake, completion, or statistics state.

* `lsu/lsu.scala`: STQ head/tail/commit/execute pointers, full condition,
  current STQ entry valid/committed/succeeded/address/packet/token, LSU DMem
  request valid/fire/STQ index/token, nack valid/index, cache and uncache
  completion index/token, strict completion acceptance, pending counters,
  underflow, older-store replay guard, and `clear_store`.
* `lsu/dcache.scala`: S2 request type/valid/STQ index/packet/token, each S2
  nack reason, MSHR request valid/ready/fire, replay valid/fire and identity,
  S3 store identity, data-array write fire, raw cache/uncache completion,
  cross-package block/pending/issued/meta-clear state, pending sequence, and
  safe packet watermark.

Probe signal names are emitted below the LSU/DCache instance hierarchy with
`debug_` prefixes. Use them together with the existing `stq_*`, `s2_*`,
`mshrs_*`, and completion signals to distinguish a missing completion from a
replay, barrier, or STQ-head ordering stall.

## Verification

Compile-only check performed from `/data1/gzh/EC/chipyard`:

```text
./.conda-env/bin/sbt -batch 'project boom' Compile/compile
```

It completed successfully on 2026-09-30. No RTL generation and no simulation
were run. Existing uncommitted functional changes were preserved.

## FIRRTL target annotation fix

The first hardware-generation attempt reported:

```text
java.lang.NumberFormatException: For input string: "stq_head"
```

The cause was a `dontTouch` annotation applied directly to fields selected by
the dynamic expression `stq(stq_head)`. FIRRTL's target conversion treats a
dynamic Vec component as a static index and attempted to parse `stq_head` as
an integer. The probes now copy those selected fields into named `Wire`s and
apply `dontTouch` only to the named wires. This leaves the observed values and
all LSU control logic unchanged.

The BOOM compile-only check was rerun after this fix and completed
successfully.
