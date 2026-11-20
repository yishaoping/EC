# 21-only FireSim safety repair report

Observed 2026-11-09. This report records the deployment-control change and the first post-repair run. It does not claim that the final C4/Opt4 bitstream is ready.

## Fixed scope

- The only authorized physical target is PCI BDF `0000:21:00.0`, serial `Xilinx/21770433G02LA`, endpoint `10ee:903f`, upstream bridge `0000:20:03.1`.
- e2 remains `0000:e2:00.0`, serial `21770433G001A`, upstream bridge `0000:e0:03.1`. It is protected and is never a deployment target.
- `scripts/infrasetup.py` accepts only `Native|C4` plus exact BDF 21. `board_batch.py`, `run_isolated_sample.py`, `coverage_first.py`, `suite_queue.py`, and recovery paths use the 21 pointer/lock. `--pair`, e2 BDFs, serial-only programming, `--all-bdfs`, and `--all-serials` are rejected.
- FireSim `fpga-util.py`/`pcielib.py` copies in the campaign, Native, C4, and upstream Alveo script trees validate the complete endpoint BDF and device identity, use only the 21 upstream bridge, and reject global `/sys/bus/pci/rescan`, global XDMA unload/load, and non-target sysfs writes.
- The generic upstream Alveo Manager physical `infrasetup`/enumeration/flash methods are guarded against use on this host. The campaign entry point is the isolated script above.
- No frozen hardware RTL, final tag, C4 source, or bitstream was changed.

## Evidence

- Mapping: [fpga-target-map-20261109.json](../../fpga-target-map-20261109.json)
- Root preflight with PID/start-tick/boot-ID/cgroup and e2 identity: [root-preflight.json](root-preflight.json)
- Static/negative test output: [tests.log](tests.log), result `PASS`, 4 tool trees, 40 negative CLI cases, endpoint-remove/bridge-rescan `PASS`, JTAG scope `PASS`, Manager guards `PASS`, hardware writes during test `0`.
- Source compilation: [syntax-check.json](syntax-check.json), 115 source files compiled in memory without cache writes.
- The first 21 deployment was physically successful and has exact Vivado witness `EC_FPGA_PROGRAMMED serial=Xilinx/21770433G02LA ...`; the old wrapper falsely returned failure because it scanned echoed Tcl source containing `ERROR:`. The original failure is preserved in [FAILED.json](../../batches/Native-single-20261109T022232Z/FAILED.json); reconciled receipt is [latest-deployment.json](../../latest-deployment.json). No second programming was performed.
- e2 Facesim ended naturally at `2026-11-09T02:27:53Z`; its state and all output remain under `runs/native-facesim-simsmall-r1-20261109T014326Z`. The saved pre/post e2 identity is in [protected-e2-after-deploy.json](protected-e2-after-deploy.json); it remained unchanged.

## Current execution

At the last observation, exactly one FireSim process was live and its command contained `+bus=21`: Native Facesim `simmedium r1`, run ID `native-facesim-simmedium-r1-20261109T023353Z`, PID `80081`. The atomic state is [active-0000_21_00.0.json](../../active-0000_21_00.0.json). No e2 FireSim process was live. C4 CAD remains active with Vivado PID `5893` and state [C4-runtime-cad-state.json](../../C4-runtime-cad-state.json), status `RUNNING`, certified bitstream `false`.

The old coverage/native controllers were restarted only after the e2 guest exited. New controller states are [jobs/coverage-first/state.json](../../jobs/coverage-first/state.json) and [jobs/native/state.json](../../jobs/native/state.json); their input hashes bind the new 21-only source. Existing result files and failed attempts were retained.

## Recovery rule

A reconnect first reads each service state, PID, process start ticks, host boot ID, cgroup and active run pointer. A live process is adopted in place. A deployment requires the 21 maintenance lock, no 21 device FD/MMIO conflict, exact PCI/JTAG mapping, and no active 21 guest. It performs only target 21 unbind/remove, JTAG program, target-bridge rescan and rebind. e2 activity is recorded as `other_card_simulations` and is never stopped or used as an idle proof. An incomplete sample is rerun from its last atomic sample boundary; no instruction-level checkpoint is claimed.

Versioned control changes: [changes.patch](changes.patch), [after-sha256.json](after-sha256.json). These record deployment/host controls separately from frozen RTL. The one-time transition script failed only at receipt publication; it is not an enabled service or a scheduler. The corrected deployment was reconciled from actual successful Vivado evidence; existing systemd services now own continuation.
