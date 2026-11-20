# Opt4 rollback and fault-injection audit

## Evidence boundary

This is a static source audit of hardware commit `8da24a269b98a0d6a8f57b030353a310812c4344`, source ID `7e77ddda28298ac88be13c28dbe98771982bc6ca9587f810adf875bffd580cc1`. No RTL was regenerated, no simulation was run, and no device was accessed.

The audited source hashes are:

| Source | SHA-256 |
| --- | --- |
| `chipyard/generators/rocket-chip/src/main/scala/util/DacRoi.scala` | `e41828d04b47ad2a209defc28c700113e3a74e53451e00a846c0ab63df9c4ed2` |
| `chipyard/generators/rocket-chip/src/main/scala/r/R_ICSL.scala` | `7f4728f0981fa0fede24713e4daad22a0b37faf8b9adfea8294dd4e1fdb5edeb` |
| `chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala` | `92c65bd8130abe53db7eb75c830958f8ffdbb2f97aef93ca2074abef02912ac0` |
| `chipyard/generators/chipyard/src/main/scala/example/DacRoiPeripheral.scala` | `28b4bae58b07125369b09a784dae4775f3949a748d7f9f7749474d491d0936a2` |
| `chipyard/generators/boom/src/main/scala/exu/rob.scala` | `81406711678554e6fa40354b8f169bc3ebff4c3868d645c2df479572ff703b38` |
| `scripts/run_isolated_sample.py` | `c6ecfce4e206e1e9f2cdaee7decfd24d4322c8366f47b3d96fa1f574e393e2ce` |
| guest `/opt/ec-fpga/run-one` | `2a25c4b7738c0e694d1e88c95b19cf189fdb5cc9f1e68a3287f49a2eab334cfe` |

## Findings

`DacRoiRequest` carries only `token`, `epoch`, `satp`, and `hart`; it has no fault-injection control (`DacRoi.scala:9-26`). The ROI controller raises sticky observer faults for trap/context changes, bad ROI marker sequences, checker count failures/cancellation/drop, and counter overflow (`DacRoi.scala:71-80, 83-110, 143-144`). Its request operations are arm, end, drain, and an abort that returns to idle only when the checker is idle and generated/completed counts match (`DacRoi.scala:100-136`). The peripheral exposes one command register plus epoch/context fields and read-only reply fields; there is no separate injection register (`DacRoiPeripheral.scala:48-83`). These are observation and control operations, not a supported way to inject a checker fault.

In `RocketCore.scala`, a compare error selects `GH_CHECKER_STATUS_FAIL`; bounded transport/no-progress failures select `GH_CHECKER_STATUS_CANCELLED` (`RocketCore.scala:1499-1531`). The package-result trace records status, full-comparison completion, and cancellation (`RocketCore.scala:1542-1549`). The cancellation input to `R_ICSL` is driven by that bounded cancellation condition (`RocketCore.scala:1501-1506, 1685-1687`). `R_ICSL` documents that package failure releases BOOM through the result CDC while the checker returns to its management PC (`R_ICSL.scala:331-363`). Its local `kill_pipe` output is tied low (`R_ICSL.scala:506`), and the corresponding RocketCore pipeline-kill assignment is commented out (`RocketCore.scala:1232`). This path establishes package-result handling and checker return, not an application restart or architectural replay after a detected mismatch.

The BOOM ROB does contain a rollback state, entered from `exception_thrown` and used for exception/branch recovery (`boom/src/main/scala/exu/rob.scala:971-1000`). The current runtime verifier does not observe that state or require a restart: it accepts only PASS, full comparison, and no cancellation, and rejects nonzero `faults`, failed packages, or cancelled packages (`scripts/run_isolated_sample.py:39-45, 58-76`). The guest wrapper invokes the selected application once and checks its output once; it has no fault-injection or retry argument (`software/rootfs-20261109T123448Z/tree/opt/ec-fpga/run-one:5-15, 21-35, 36-85`). A clean strict-comparison/drain sample therefore cannot demonstrate fault-triggered rollback/restart.

## Safe validation path

There is no supported hardware injection command in the audited request bundle, peripheral, guest wrapper, or sample verifier, so no diagnostic software profile can honestly exercise this path on the current bitstream. Do not treat `faults`, a cancelled result, host bridge reset, or a normal PASS as evidence of rollback.

The least intrusive next check is a separate simulation-only harness that injects a one-shot mismatch at the checker compare boundary and records the full chain: injected compare mismatch, package FAIL result, checker return, any BOOM flush/ROB rollback and restart point that the design actually implements, then successful application output. The test must fail if the chain ends at package release without architectural restart. Only after that contract is demonstrated should a separately versioned diagnostic hardware candidate expose a narrowly gated one-shot injection control and be certified/deployed through the existing broker. No such candidate or profile was created in this audit.
