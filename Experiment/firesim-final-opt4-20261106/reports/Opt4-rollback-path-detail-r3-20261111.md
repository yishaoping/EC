# Opt4 rollback and recovery interface audit, revision 3

## Revision and scope

Static source trace for 8da24a269b98a0d6a8f57b030353a310812c4344, source ID 7e77ddda28298ac88be13c28dbe98771982bc6ca9587f810adf875bffd580cc1, in `W/Opt4-fit-20261110`. The source hashes below bind the claims to that candidate. This is not a fault-injection run, a rollback experiment, full-DUT formal proof, or hardware test. No RTL, firmware, host driver, live unit, or hardware input was changed.

## Signal chain

| Stage | Source evidence | Assessment |
| --- | --- | --- |
| Trigger | `RocketCore.scala:1523-1541` creates PASS, FAIL, or CANCELLED from a completed checker comparison or an owned transport/progress failure. `DCache.scala:2650-2668` accepts sequenced FAIL/CANCEL results. | The functional checker can report package failure; no fault source is thereby implied. |
| Immediate consequence | `DCache.scala:2669-2695` latches the first failing sequence, asserts `svbInvalidate` for `safePacketWatermark`, and sources sticky failure plus sequence to the L2. | Speculative memory-version invalidation and a sequenced diagnostic are directly wired. |
| L2 consequence | `InclusiveCache.scala:299-302` combines a timed-out active barrier with a sequenced failure whose sequence is at or before the barrier. `:356-361` publishes `barrierError`; `:397-407` passes it to the barrier-statistics module's `fatalProtocolError`. | The error invalidates local barrier statistics and is exported across the hierarchy. |
| BOOM error consumer | `exu/core.scala:2099-2108` sinks and synchronizes each bank's barrier-error bit and forms `l2BarrierErrorAny`. A source search in this file finds no read of that value after its definition. | No architectural action is driven by this synchronized error vector in the audited source. |
| Architectural rollback | `exu/rob.scala:705-727` derives `exception_thrown` from `can_throw_exception` on a ROB head and produces `io.com_xcpt`; `:971-1000` enters `s_rollback` after that exception and returns to normal when the ROB is empty. | The checker result and barrier error are not inputs to the ROB exception/rollback path. No application-restart request or completion witness was found. |

Thus, a checker FAIL/CANCEL is an observed package-result event. Its immediate blocking/protection effect is SVB invalidation; its downstream amplifier is barrier-statistics invalidation. It does not establish a committed architectural exception, ROB rollback, restore, or replay.

## Injection and observation interfaces

The ROI MMIO map in `DacRoiPeripheral.scala:64-83` writes commands and ROI identity fields and reads response/count/fault state; it provides no injection or rollback-completion register. `DacRoi.scala:34-48,76-80,100-136` accepts arm/end/drain/abort and records trap/count faults. Abort reports observer state only. The software hook UAPI has begin/end/drain and checker-query operations, with no injection or recovery operation.

The legacy `use_fi_mode` packet-corruption logic is not a supported input: `GHT.scala` declares and forwards the input, but `RocketTile.scala:293-315` instantiates the GHT without driving it; the corresponding BOOM GH buffer port is commented out. The generated-RTL audit at `build-logs/Opt4-rollback-interface-audit-r1-20261111/audit.json` reports no `use_fi_mode` occurrence and no GHT/GHT_FILTER_PRFS module declarations. It therefore cannot be controlled by the current software profile or used as evidence for the generated candidate.

## Safest verification available

An isolated simulation-only testbench can inject a valid, allocated FAIL result at the existing BOOM DCache checker-result input and observe, for one sequence, result acceptance, SVB invalidation, L2 failure/error propagation, and barrier-statistics invalidation. It should also observe the ROB exception/rollback signals and application-visible completion, expecting no rollback/restart claim unless those signals actually occur. This test can verify failure handling at that boundary without changing the frozen or live design. It is not an end-to-end fault injection and cannot prove rollback/restart because the source has no such connection or completion protocol.

An actual fault-triggered recovery experiment requires a separately versioned diagnostic design with an explicit, deterministic fault injection point, an architectural restore/replay contract, and independently observable restore completion, restart-PC retirement, correct full output, and complete checker drain. That design would need the same source-bound proof, whole-DUT implementation, certified timing/DRC/bitstream, broker runtime binding, and ordinary validation gates as any candidate. No such diagnostic design or certified bitstream is currently evidenced, so no runtime profile can honestly be prepared for it.

## Source hashes

All paths are relative to `W/Opt4-fit-20261110`.

| File | SHA-256 |
| --- | --- |
| `chipyard/generators/boom/src/main/scala/lsu/dcache.scala` | `0fb9e4b3931827120aed8311dbbc87a2d25e697c76505717af7162a0a9f1663d` |
| `chipyard/generators/sifive-cache/design/craft/inclusivecache/src/InclusiveCache.scala` | `c612fb7eb0767c8d7f09f797f96f23b17b2d4bd2915ecc3a2aabe4eb6de34d82` |
| `chipyard/generators/boom/src/main/scala/exu/core.scala` | `1883cef9fa9c24cb5f39715a132d0b89aa104e8b2aefa594bc812ad5e03c74c8` |
| `chipyard/generators/boom/src/main/scala/exu/rob.scala` | `81406711678554e6fa40354b8f169bc3ebff4c3868d645c2df479572ff703b38` |
| `chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala` | `92c65bd8130abe53db7eb75c830958f8ffdbb2f97aef93ca2074abef02912ac0` |
| `chipyard/generators/rocket-chip/src/main/scala/tile/RocketTile.scala` | `d7ca08cd4604f44e83f0d9d3c3425bb303ad8ca1626aa0cc49c46bfb7fc872f4` |
| `chipyard/generators/rocket-chip/src/main/scala/util/DacRoi.scala` | `e41828d04b47ad2a209defc28c700113e3a74e53451e00a846c0ab63df9c4ed2` |
| `chipyard/generators/chipyard/src/main/scala/example/DacRoiPeripheral.scala` | `28b4bae58b07125369b09a784dae4775f3949a748d7f9f7749474d491d0936a2` |
| `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHT.scala` | `c3d778b7044d67a406c4b5b8ed302f552552fd2ae036deff33ec07229e219e19` |
| `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/ght_filter_prfs.scala` | `130f7f6908cc5b89de6b125b974dfee70e703a5c02712147e07e42680cad1d6d` |

## Limits

This is a static source and generated-RTL interface audit. It does not prove the absence of unrelated external lab-only injection tooling. No simulation or RTL regeneration was run, and no deployment, rollback sample, or FPGA result is claimed.
