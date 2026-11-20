# FPGA21 bounded boot recovery: Linux passed, checker execution health failed

Observed 2026-11-17, Shanghai time. This supplements the earlier 900-second timeout diagnosis; it does not overwrite that failed attempt or any runner result. Frozen hardware commit: `8f67d038273d3cdc8ecce45cc4e8c5efb5cbbaa4`. Existing bitstream SHA256 remains `a6a3c73e82222b2ce11f86042be73f518a198f927ee99ba32d774dcde08e8b13`.

## Natural completion and acceptance

The single recovery attempt started at 18:15:23.059 and ended at 19:12:23.054. The runner rejected the diagnostic application failure and stopped its driver. This investigation did not stop, reset, reprogram or restart the FPGA. Root read-only precheck at 19:16:29 found no FPGA21 device holders, mappings or simulator processes, with zero permission-denied observations. Board identity remains `0000:21:00.0` / `21770433G02LA`.

Linux completed boot and entered `/init`/userspace. All four checker contexts were installed, but **four-hart execution health did not pass**. There were no package BEGIN/RESULT events or positive completed-checker accounting. No blackscholes command or PARSEC run was started. Valid certification remains **0/8**, with no Slowdown.

## Timestamped progression

Times below are host observations from `progress.jsonl`, not inferred printk timestamps.

| Shanghai time | Wall seconds from driver start | Evidence |
|---|---:|---|
| 18:15:23.059 | 0 | Single FPGA21 driver started |
| 18:50:38.618 | 2115.558 | Linux continued beyond device initialization |
| 18:51:29.238 | 2166.178 | `/init` startup progressed |
| 18:51:40.263 | 2177.202 | `EC_GUEST_READY` observed; smoke command delivered |
| 19:12:07.543 | 3404.482 | `EC_SAMPLE_START run_id=health program=smoke` observed |
| 19:12:20.579–22.084 | 3417.519–3419.023 | Four `EC_OPT4_INSTALLED` lines and context message, then ROI seal failure and failed sample |
| 19:12:23.054 | 3419.997 total driver wall seconds | Failure finalized; controller blocked PARSEC |

The UART includes `Run /init as init process`, `EC_GUEST_READY`, an echoed smoke command, four installed harts 1–4 with SATP `80000000000829f9`, and `EC_OPT4_CONTEXT version=6 checkers=4 ... hardware_initialized=1`. It then reports:

```text
DAC ROI end/seal failed: Input/output error
EC_SAMPLE_EXIT ... application_exit=125 capture_exit=0
EC_SAMPLE_FAILED ... reason=application_or_capture_exit
EC_COMMAND_EXIT=1
```

There is no successful checksum output, GUEST_DONE, valid ROI, park/drain or four-checker execution evidence. Installation alone is insufficient to certify the privilege repair.

## Timeout and progress checks passed

Actual boot to command delivery was **2177.202 s**, consistent with the prior comparable **2178.422 s**. The new BOOT allowance is 3600 s and 2.4 billion target cycles. READY was observed with the last heartbeat at 1,443,963,451 cycles, comfortably below the cycle limit. Checksum/input preparation then used its independent budget: 1227.280 s until SAMPLE_START. Smoke execution was only about 15.5 s when the application failed; this was **not a timeout**.

All 297 heartbeat records increased strictly, from 7,577,513 cycles at 18 s to 2,271,473,596 at 3414 s; maximum recorded sampling interval was 12 s. Final driver target cycles were 2,275,408,277. The 120 s stall detector uses these target-cycle advances, not UART silence. No deadline fired, and no serial silence was misclassified. Cycle growth establishes simulator progress, not Guest/checker correctness.

## New immediate blocker: ROI marker observation

The complete RTL event file has exactly two command records:

```text
CYCLE 2273740854: token=0101 epoch=0 state=0 begin=0 end=0 generated=0 completed=0 busy=0 faults=0
CYCLE 2273752080: token=0202 epoch=1 state=1 begin=0 end=0 generated=0 completed=0 busy=0 faults=0
```

These are request-time prints. ARM was accepted (the following request sees epoch 1, ARMED). On END request, the observer was still ARMED with no recognized start/end marker. `DacRoiController` accepts END only when state is ENDED and faults are zero; therefore it rejects this END. The kernel's `dac_command()` returns `-EIO` when `DAC_ERROR` is nonzero, before printing `EC_OPT4_SNAPSHOT`. This directly explains the observed end/seal error without invoking a boot timeout or checker trap.

## Source → generated RTL evidence

An offline audit found a concrete pre-existing measurement-source defect:

1. `GH_Config.scala:18` sets `EnableROBDebug => false`.
2. `rob.scala:375–379` creates the real debug instruction memory only when that flag is enabled. With it disabled, the two separate `getOrElse { SyncReadMem(1, ...) }` expressions create independent fallback memories for writes and reads.
3. `core.scala:1921–1925` supplies delayed architectural commit-valid signals to the ROI observer but obtains its instructions from `rob.io.commit.debug_insts`.
4. The exact generated SystemVerilog used by the project contains a **one-entry, read-only** `rob_debug_inst_rdata_MEM_flattened` array, whose output drives `io_commit_debug_insts_0/1/2` and then `dac_io__insn_0/1/2`. There is no functional assignment to that array. Its only assignment is under simulation-only `RANDOMIZE_MEM_INIT`.
5. `DacRoiController` compares those inputs to `0x6b100013` / `0x6b200013`, so it has no connected stream of real retired marker instructions.
6. The unchanged smoke ELF actually contains BEGIN at PC `0x10708` and END at PC `0x107a0`; their absence in the application binary is excluded. The binary reaching END ioctl supports execution through the hooks, but no retired-PC trace was captured.

Generated evidence: `full-r2/host/FireSim-generated.sv:730737`, `:742419`, `:742464`, `:803984`; marker comparisons at `:772906`. The project `design/FireSim-generated.sv` has the identical SHA256. Selected lines and hashes are saved in `evidence/generated-marker-chain.txt` and `diagnosis.json`.

The four relevant Scala files are byte-identical to the **pre-privilege-repair baseline** `80da038d800f77baa53dd97ac0436eb352410953`. This defect was not introduced by the two CSR/RSU privilege changes.

Proven: the END command arrived before any accepted ROI markers; the generated observation memory has no functional writer. Strongly supported causal explanation: disconnected retired instruction observation prevents normal ROI boundaries. Not established: the exact optimized physical value of the undriven memory or the internal signal values on FPGA. No post-synthesis probe, fault-time PC/CSR/PTE dump, checker package execution or complete target/checker equivalence was captured.

## Fatal-trap and device findings

No new `sbi_trap_error`, `sbi_hart_hang`, mcause dump, checker mismatch, kernel panic or DMA error was found in the captured UART/host logs. Absence of traps before useful checker execution does **not** prove the original hart1/hart3 issue resolved. The runner correctly rejected the failed measurement and blocked all eight benchmarks. Driver `*** PASSED ***` after controlled termination is not certification success.

## Next verification and repair boundary

Do not retry this identical health configuration, increase deadlines again or bypass the ROI checker gates. Linux boot budgeting is now validated; the observation path needs a narrow offline reproduction that models debug-disabled ROB elaboration and proves real BEGIN/END instruction delivery. Determine whether the existing hardware exposes another equivalent, already certified observation path before proposing reuse. No software-only workaround preserving the current ROI rules has been demonstrated.

If an RTL correction is necessary, isolate only the retirement observation wiring/storage and verify same-edge timestamps, privilege/SATP qualification, flush/stall behavior and original ROI arithmetic. Do not enable all ROB debugging indiscriminately, substitute host timestamps, force controller state or mask the error. A hardware change would require its own generated-RTL proof and strict rebuild/certification before FPGA21 health and blackscholes can resume. **No such modification, rebuild or extra FPGA run was performed in this investigation.**

## Preserved evidence

`evidence/health/` is a complete copy of the finished health attempt. `evidence/` also preserves launcher/controller state, deployment and runtime provenance, previous timeout report and regression records. `evidence-manifest.json` records 43 snapshot files with SHA256; `diagnosis.json` records cycle/timing calculations, source comparison and unchanged bitstream hash. The original run directory and all authoritative failed states remain unchanged.
