# PARSEC Blackscholes independent Opt4 validation

Work is private to `/data1/gzh/EC-opt4-perf`. Main/FPGA source and processes and
canonical `/data1/gzh/EC/check/source` remain untouched. No optimization is done.
Frozen BFS hardware is tagged `opt4-final-bfs-20261103` at `5343ea33f`; permanent
BFS report is ../optimization_6_overlap/frozen_final_20261103/README.md.
Validation branch: `opt4/validate-blackscholes-20261103`.

## Workload

Official PARSEC3.0 `test/in_4.txt`, 4 options, original `NUM_RUNS=100`, serial
`bs_thread`, 400 pricings. Original source SHA256:
`0925afb46301eea609b9f5249afa4b01fc93af495330b8d6c14a0f9b0e34d796`;
input SHA256 `9a40f4a6f4b96a32bb834333487d6dcec4436eceae7efbf836574aacb1e6ce46`.
Source is extracted from the project's PARSEC3.0 core archive, rather than the
locally modified Linux/FPGA application. Price kernels and 100-run loop are
unchanged. File parsing/allocation are adapted to embedded static input with
identical struct-of-arrays preparation outside ROI. No Linux or pthread runtime.
Original file-I/O main is renamed and removed by section GC; pricing loop remains
present in disassembly. Both designs execute exactly one shared ELF and loadmem.

The existing `check/software_common` HTIF, startup, interrupt, GHE/GHT checker
initialization, start/stop/session completion and report code are reused via a
private copy. BFS-specific pinned data layout is replaced with ordinary aligned
BSS, retaining the HTIF linker/startup contract. GCC12.2.0, `rv64imafd/lp64d`, -O2,
no fast-math. Math is newlib `libm`. Host reference uses host libm, so small
cross-libm float differences are expected: target prices are checked against the
provided DG reference with the upstream serial ERR_CHK tolerance1e-4. The two
RISC-V runs must additionally match all four exact float bit patterns/checksum.
Verification occurs after ROI; no repeated per-price verification added to kernel.

ROI is hart0 `rdcycle` at common_roi_start/stop, around the original serial
100-run loop plus shared STOP/session completion. Embedded input preparation,
startup, correctness output and final HTIF exit are outside ROI. This differs
from PARSEC Linux hooks only by the explicit common checker-completion tail.
`rdinstret` is supplemental; differing completion polling/timer paths may vary it.
Total harness counts include reset/startup/reporting. Four checkers100MHz,
BOOM200MHz, seed1, DRAMSim2, same ini files, assertions enabled,
1 simulator thread, same host. Waveform and verbose printf are disabled.
The primary comparison uses Verilator5.048 and Clang16. Historical and first
matched check builds actually used Verilator4.226 and conda g++, despite an
environment probe reporting5.048/Clang. Generated makefiles and actual compiler
commands exposed the PATH mismatch; see evidence/tool_version_audit.json.
Those runs are auxiliary. A fresh matched_check_v5048 simulator reuses the exact
matched detection RTL with absolute tools, the same model optimization flags,
and the frozen correction's DRAMSim archive. No RTL regeneration is involved.

The official **test** input is small and fits in cache. It is the initial reliable
Verilator validation, not simsmall/simmedium/native performance evidence. The
100 original rounds are not reduced. Interpretation must account for fixed
session overhead and tiny data working set.

## Configuration controls

The historical prebuilt `check` at b3d7adddd1e2d2cf428dd933529de878226420cd is
attested using its existing verified_build function before replay. It differs
from frozen correction: BOOM ROB96 vs42, PRF100/96 vs128/128, LQ/SQ24 vs16,
L1D32KiB64sets×8ways/4MSHR vs256sets×2ways/6MSHR; checker I$32KiB vs2KiB;
L2 512KiB8ways/latency40 vs1MiB16ways/latency12. Thus its number is retained as
an auxiliary historical comparison, not an isolated correction-cost measure.

A second **check_matched** build is a private byte copy of b3 detection source
with exactly three configuration files changed: append the frozen BOOM config
constructor, select it and frozen L2 parameters, set checker I$32sets×1way.
Historical detection datapaths/protocols and fetch4 remain unchanged. The exact
configuration-only patch is committed under evidence/. Generated JSON and all
clock summaries match frozen correction (configuration_check PASS). Checker
fetch8 is an intentional optimized-design difference. The build reuses check's
resource manifests, offline SBT dependencies, Makefile and bwrap isolation.
The source copy and caches are separate; main/canonical check writes are blocked
by a read-only root mount. Long sbt socket paths are handled via private /tmp.

## Commands

From `/data1/gzh/EC-opt4-perf`:

```sh
python3 -I -B slowdown/blackscholes_validation/scripts/build_workload.py
python3 -I -B slowdown/blackscholes_validation/scripts/run_workload.py check --smoke
python3 -I -B slowdown/blackscholes_validation/scripts/run_workload.py correction --smoke
python3 -I -B slowdown/blackscholes_validation/scripts/run_workload.py check
python3 -I -B slowdown/blackscholes_validation/scripts/run_workload.py correction
python3 -I -B slowdown/blackscholes_validation/scripts/build_matched_check.py
python3 -I -B slowdown/blackscholes_validation/scripts/verify_configuration.py
python3 -I -B slowdown/blackscholes_validation/scripts/run_workload.py check_matched --smoke
python3 -I -B slowdown/blackscholes_validation/scripts/run_workload.py check_matched
python3 -I -B slowdown/blackscholes_validation/scripts/build_matched_tools.py
python3 -I -B slowdown/blackscholes_validation/scripts/run_workload.py check_matched_v5048 --smoke
python3 -I -B slowdown/blackscholes_validation/scripts/run_workload.py check_matched_v5048
```

Fresh output directories only; exact simulator argv, source/software/binary seals,
seed, host and wall-time measurements are in each run_manifest.json and command.sh.
The smoke runs deliberately time out at10,000 cycles and are excluded from results.
Historical full run completed; frozen correction failed a real assertion, described
in CORRECTNESS_FINDING.md. The configuration build's initial sbt path failure and
resume logs are preserved; corrected clean reproduction uses /tmp from the outset.

A minimal correctness repair, permitted by the validation task, passed Blackscholes:

```sh
python3 -I -B slowdown/blackscholes_validation/scripts/test_capture_cancellation.py
python3 -I -B slowdown/optimization_6_overlap/scripts/run_experiment.py --jobs 16 --label blackscholes_capture_flush_fix --build-only
# New build ID printed by runner; this session's ID is:
# overlap_blackscholes_capture_flush_fix_20261103_064936_fd6cd4a6
python3 -I -B slowdown/blackscholes_validation/scripts/run_workload.py correction --smoke --smoke-cycles 40000 --correction-build overlap_blackscholes_capture_flush_fix_20261103_064936_fd6cd4a6
python3 -I -B slowdown/blackscholes_validation/scripts/run_workload.py correction --correction-build overlap_blackscholes_capture_flush_fix_20261103_064936_fd6cd4a6
python3 -I -B slowdown/blackscholes_validation/scripts/analyze_workload.py RUN_DIRECTORY
python3 -I -B slowdown/optimization_6_overlap/scripts/run_experiment.py --resume overlap_blackscholes_capture_flush_fix_20261103_064936_fd6cd4a6
```

## Result status

See [RESULTS.md](RESULTS.md) for the complete result, controls, counters and
limitations. Primary matched check: ROI385,066; harness436,938; wall252.8040s.
C plus correctness repair: ROI431,820; harness507,130; wall700.9308s.
**Target ROI correction/check=1.121418146×**. Separate host simulation-cost
ratio=2.772625273×. Both software outputs pass; repair additionally closes161
PASS package results with zero FAIL/CANCELLED and complete protocol/integrity/
capture evidence. Frozen C fails and has no valid Blackscholes ratio.
The common software ROI ends before three final hardware results; the last
arrives10,204 cycles later. The ratio describes the shared program ROI, while
161-package closure is verified through exit; it is not a full-drain latency.

Historical check: ROI318,510; harness370,068; wall486.8543s. The first matched
check using4.226: ROI386,141; harness438,187; wall487.0510s. Both are auxiliary.
Frozen failure wall43.8948s is time to assertion, not a workload time. BFS repair
regression on the same simulatorPASS: ROI1,128,052, identical to frozen C;
checksum43439728, protocol/integrity/capture/ordering/SC48–51PASS.

Workload analysis reuses protocol/integrity/capture and SC48–51 validators,
but deliberately does not call BFS-specific correctness or its1,001,675-cycle
baseline calculation. Complete-package checker profiles explicitly exclude
crossing or incomplete captures. Cache shadow estimates remain ineligible if
fidelity fails. Software completion alone does not prove durable recovery/drain.
