# Targeted recovery validation, separate from performance

The frozen emitted `SpeculativeVersionBuffer.sv` passed 16 directed component
cases (328 component clocks), with RTL assertions enabled. Exact commands, emitted
RTL hashes, output and scope are in `component_090326.json`. No hardware was
regenerated or modified. These cases drive the SVB invalidate interface that the
DCache drives on FAIL/CANCELLED; they do not inject an error into a live checker.

| Boundary | Component result | End-to-end status |
|---|---|---|
| Old SPEC version retained while younger version changes | PASS: two immutable payloads retained | CPU rollback not tested |
| FAIL/invalidate at watermark advancement | PASS: younger SPEC dropped; safe predecessor available | Checker-detectable error not injected |
| Before ACK, with varying send/ACK delays | PASS: WB_WAIT bytes and release block retained | Architectural restore not tested |
| FAIL/flush at ACK edge | PASS: matching owner ACK completes once | CPU restart not tested |
| Consecutive versions on one line | PASS: newest safe sequence selected | Recovery selection not implemented by test |
| Same-sequence, multiple generations | PASS: generation order and safe coalescing | CPU restore not tested |
| FAIL when predecessor is newer than watermark | Observed: SPEC predecessor discarded | Historical-state availability not established |
| Flush before selection | Observed: SPEC snapshot discarded | Flush-near-FAIL restore not established |
| After L1 eviction / refill | SVB has no L1 request interface | NOT TESTED |
| Outstanding CPU store during FAIL | SVB has no CPU/store-queue interface | NOT TESTED |

Source evidence: `speculative-version-buffer.scala` exposes capture, promote,
invalidate, flush and ACK; ordinary load selection does not read SVB. Its
`recoveryFromSvb` output equals `io.acked`, which counts successful promotion ACKs.
It does not demonstrate a fault-triggered restore. DCache FAIL/CANCELLED handling
invalidates versions above the safe watermark and publishes sticky barrier failure.
Exception flush discards SPEC versions. These observations establish a validation
gap, not successful durable recovery. No claim about restoring architectural state
is made from the no-fault PARSEC results or this component suite.

The remaining integrated suite needs a private test harness that: (1) records a
known pre-fault architectural register and memory state; (2) creates and retains
an old version; (3) modifies the new version; (4) corrupts a checker-observed value
before reclamation; (5) proves a real accepted FAIL; (6) observes rollback; and
(7) compares recovered state and final application output with an uncorrupted
reference. Repeat at before/near ACK, before/after watermark, resident/evicted L1,
refill/writeback, consecutive same-line versions, flush-near-FAIL and outstanding
store boundaries. If the frozen design cannot provide a restore path, mark the
case unsupported; implementing one would require an explicitly revised hardware
version and BFS/Blackscholes regressions. These cases are never part of slowdown
means.

The historical Canneal simdev correction pilot on revision 153292380 completed
206 SVB allocations through matching promotion ACKs, with no discard and zero
final occupancy. Its 39 generated packages all passed. This is additional
no-fault evidence that the promotion/ACK path is used, not evidence of rollback
or architectural restoration. The revised model must be measured separately.
