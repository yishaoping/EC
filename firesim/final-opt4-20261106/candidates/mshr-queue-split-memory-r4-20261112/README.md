This is a private MSHR queue implementation, not an installed sprint change.

The complete source implementation and exact reversible projection are in
`mshr-queue-split-memory-r1-20261112`. Only the two MSHR queue construction
sites change. The mutable branch mask remains a per-entry register; immutable
MicroOp fields use a single-write asynchronous memory. Queue depth, request
payload, held-head ownership, flush, branch resolution, discarded output,
dequeue timing and counters remain present.

The r1 production source compiled successfully. The r2-r4 successors reuse
those compiled classes and correct only the test wrapper's TileVisibility
and unused, unspecified branch target-offset width. The actual 16-entry
holdable RPQ passed 65,536 finite cycles with 909-bit payloads. All outputs,
including payloads on invalid cycles, were compared. The branch-mask and
flush controls exercise the queue's actual functional consumers; the unused
branch-resolution b2 fields are tied off in this local probe.

This result is not complete MSHR/DCache/system equivalence or an area result.
The complete MSHR same-harness generated-host area pair is a separate job.
Its measurement must not be multiplied or subtracted from whole-host area.
