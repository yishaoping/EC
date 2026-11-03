# Blackscholes validation finding: exception during snapshot read

Frozen final hardware `5343ea33f` fails the first no-fault Blackscholes execution.
Run `correction_test4_20261103_064146_55b93744`, sealed original simulator
SHA256 `66ab0661ba28dc040cc2fb6dae6bf5f6be6d21ed4bf035a94861dff7c9110e6a`.
No ROI completion or valid correction/check ratio can be inferred from this run.

## Evidence chain

The generated assertion is `BoomNonBlockingDCache.sv:118954`,
`assert__assert_30`, mapping to `dcache.scala:1883`:
`svbCapturePending && svbCaptureIssued` at snapshot consumption. Proven symptom:
a snapshot was accepted by SVB after the DCache capture descriptor was cleared.
The waveform `$time` printed as `[30000]` is rounded; event core cycle at the
failing edge is 30,045 (hex755d), not universally cycle30,000.

| BOOM cycle | Observation | Meaning |
| ---: | --- | --- |
| 30,018 (7542) | WB_START capture line8002bec0 | WB accepts old-image reader request |
| 30,025 (7549) | SC32 allocation1; FASTLINE_ACQUIRE | First read closes normally |
| 30,029 (754d) | FASTLINE_RELEASE matching write | First lease consumed |
| 30,038 (7556) | WB_START capture line8002be80 | Second accepted reader request owns immutable key |
| 30,040 (7558) | SC35 allocation1 reason3=flush | Exception/epoch boundary flushes SPEC |
| 30,045 (755d) | SC32 allocation2; assertion30 | Old WB snapshot crosses the flush boundary |

The source establishes the upstream cause: `svbFlush := traffic_reset ||
lsu.exception` unconditionally clears both capture-pending and capture-issued;
WB has no cancellation input and continues its accepted fill-buffer request.
SVB capture ready is inhibited only on the flush edge, then accepts the late
snapshot under the new `svbEpoch`. This source chain plus the reason3 SC35 event
strongly supports exception/epoch cancellation as the cause. The initial session
traffic reset occurred much earlier. Exact trap cause is not in this capture.

This is an existing functional Opt4 ownership gap, outside A/B/C's intended
performance mechanisms. The BFS result stays a valid recorded BFS result, but
its validation scope does not cover this interleaving. A no-fault program can
still take architectural interrupts/exceptions; no error injection was enabled.

## Minimal correctness repair

On branch `opt4/validate-blackscholes-20261103`, preserve an accepted capture's
single freeze descriptor until the WB snapshot returns. On an exception mark
it cancelled; drain the complete old snapshot without SVB allocation or fast-line
lease. An unissued request is cancelled immediately and cannot fire on the flush
edge. A simultaneous flush/response also discards. Existing key/line/slot-epoch
and owner assertions remain active for both consumed and discarded responses.
The original frozen hardware tag and optimization branch are preserved.

Six reduced CPU ownership tests cover read/hold timing, full SVB, flush before
admission, simultaneous flush/response, identity mismatch and the old bug witness.
The 11 overlap and 7 retained-copy CPU contracts also pass. Actual emitted WB
RTL passed160 snapshots, including80 responses after a modeled controller cancel;
all data/key/line/slot-epoch fields remain stable through backpressure. This unit
has no cancellation input and is unchanged by the proposed repair.

Actual repaired full-system RTL completed a40,000-cycle smoke regression
`correction_smoke_20261103_072805_0ca5667a` without assertion. The accepted read
at30,038 and flush at30,040 reproduce the original trigger. Mandatory SC32 has
no allocation at30,045; the bounded diagnostic ring then shows a new WB request
at30,049 (7561), allocation at30,056 (7568), and matching semantic write at30,060.
This proves the original interleaving now progresses through a fresh capture.
See evidence/capture_flush_smoke_event_window.json and the preserved smoke ring.
The new SVB_CAPTURE_DISCARD printf remains verbose-gated in this build, so its
zero captured lines must not be reported as zero cancelled snapshots. Full
Blackscholes `correction_test4_20261103_072928_2409f537` then completes normally:
ROI431,820, identical exact prices/checksum,161/161 sequenced PASS results,
zero FAIL/CANCELLED/assertion, protocol/integrity/capture/SC48–51PASS. All692
allocated SVB images flush-discard, with no promotion: this does not validate
general durable recovery. The same-binary BFS regression alsoPASS: ROI1,128,052
unchanged, checksum43439728, protocol/integrity/capture/ordering/SC48–51PASS.
Repair commit:83dec9d4c10ab8c097fe5ab5c8af1c0a270fba6d.
Reduced models do not validate the hardware fix by themselves. No optimization
performed.
