# Blackscholes validation result — 2026-11-03

The primary matched comparison is **431,820 / 385,066 = 1.121418146×**
(12.1418% additional target ROI cycles) for **final C plus a correctness repair**.
Original frozen C fails an assertion and has **no valid Blackscholes ratio**.
No architectural performance optimization was performed during this validation.

| Design | Official PARSEC input | Target ROI cycles | Total harness cycles | Host Verilator time | Correctness observed |
| --- | --- | ---: | ---: | ---: | --- |
| Detection-only b3, matched core/cache/tool configuration | test/in_4.txt, 4 options × 100 rounds | 385,066 | 436,938 | 252.8040 s | Software output/completion PASS; no assertion |
| Frozen optimized C, 5343ea33f | identical | unavailable | assertion before completion | 43.8948 s to failure | FAIL: snapshot accepted after owner cleared |
| C + capture/exception ownership repair | identical | 431,820 | 507,130 | 700.9308 s | Software, package, protocol, integrity and capture PASS |

**Host simulation-cost ratio = 700.9308 / 252.8040 = 2.772625273×.** This is
not hardware slowdown. Correction enables mandatory compact observation and
cache instrumentation absent from historical detection. Host load was not
controlled; the correction run overlapped a separate BFS regression, while
the detection run overlapped the end of compilation. Times include host event
capture, exclude software/RTL build and offline analysis, and are one sample.

## Frozen implementation and isolation

Frozen hardware commit: `5343ea33f7ccc1b4d140eef09e2d07ab775ae72c`.
Frozen optimization branch: `opt4/perf-20261103`, documentation HEAD
`5e7a6277cb28da4edf2cc72217fc191714ddf904`.
Annotated tag: `opt4-final-bfs-20261103`.
Permanent BFS report: [frozen_final_20261103/README.md](../optimization_6_overlap/frozen_final_20261103/README.md).
It preserves the measured 1,128,052-cycle / 1,001,675-cycle = 1.126165672× BFS
result and the 281,018 + 252,071 + 46,722 = 579,811-cycle improvement history.

Validation uses `/data1/gzh/EC-opt4-perf`, branch
`opt4/validate-blackscholes-20261103`. Correctness repair commit: `83dec9d4c10ab8c097fe5ab5c8af1c0a270fba6d`. The sole hardware delta is
`dcache.scala` capture cancellation. The optimization branch/tag are preserved.
Build/run seals record the pre-commit documentation HEAD with this dirty patch;
the sealed hardware hashes match committed repair83dec9d4c. Use the hashes and
patch, not the pre-commit HEAD field alone, to identify the executed hardware.
Main `/data1/gzh/EC` FPGA work was not changed; canonical `check/source` stays
clean and read-only. Detection configuration and tool rebuilds live in private
copies under this validation directory.

## Workload and experimental controls

This is official PARSEC3.0 **test/in_4.txt**, not simsmall/native. The four
options and original `NUM_RUNS=100` execute400 pricings. Unmodified upstream
`blackscholes.c` comes from the project's `parsec-3.0-core.tar.gz`; the original
serial `bs_thread`, CNDF and pricing functions are retained. An adapter embeds
the official input and performs identical structure-of-arrays setup outside
ROI. The file-I/O main is discarded at link; no Linux/pthread runtime is used.

Both primary runs use the same ELF SHA256
`bc6aa36e442d9f77528b0ca5a8cd7d9c1c64ea51463da082fb38efe13f33ecc9`,
GCC12.2.0, rv64imafd/lp64d, -O2, no fast-math, newlib libm. Compressed ELF,
loadmem, disassembly, exact upstream/input, adapter and common harness files
are preserved in evidence/software; hashes and compiler invocation are in
evidence/software_build.manifest.json.

ROI is the same `common_roi_start=0x80000328` through
`common_roi_stop=0x8000037c`: original100-round loop plus shared
STOP/session completion; preparation/startup/output/HTIF termination excluded.
Detection rdcycle=17,543→402,609; repaired correction=24,157→455,977.
Both hart0 ROI rdinstret values are **220,637**. Absolute startup cycles differ;
the program region is identical. Harness counts also include reset/startup/output.
The common GHT software-completion poll does not guarantee hardware result
release. Of161 BOOM-accepted results,158 arrive inside ROI and three arrive
afterward (seq159 at460,741;161 at463,653;160 at466,181). The last is10,204 cycles
after ROI stop; correction start-to-last-result is442,024 cycles. This is a
separate correction timing observation, not a matched drain-latency ratio:
detection has no equivalent sequenced completion timestamp. The primary ratio
is therefore explicitly for the shared software ROI, with full-session checking
verified separately. Full durable-cache recovery/drain remains unvalidated.

Both configurations use BOOM200MHz, four Rocket checkers100MHz, seed1,
DRAMSim2 and the same ini files, Verilator5.048, assertions, one simulation
thread, no waveform or verbose printf, Clang16.0.6 and the same model
optimization switches (-O3 plus generated -Os). BOOM ROB42, PRF128/128,
LQ/SQ16; L1D32KiB/256sets/2ways/6MSHR; checker I$2KiB/32sets/1way,
D$4KiB/32sets/2ways; L2 1MiB/1024sets/16ways/outerLatency12;64-byte lines.
Generated machine JSON and both clock summaries match byte-for-byte.
Detection retains its original fetch4 and protocol; correction includes the
frozen fetch8/frontend/package changes. These are intended design differences.

Historical check b3's original prebuilt configuration has larger ROB/queues,
different L1 ways/MSHRs, checker I$ and L2 latency/capacity. Its successful
318,510-cycle result is auxiliary. A configuration-only private b3 build
changes exactly three config files, with no detection datapath edits. Its first
run used Verilator4.226/conda C++, despite an environment probe reporting
5.048/Clang. Generated makefiles and actual commands caught that PATH mismatch.
The primary385,066-cycle run re-Verilates the same matched RTL with explicit
5.048/Clang paths. Exact configuration patch, source hashes, actual tool evidence,
logs and configuration checks are under evidence/.

Detection links the frozen correction DRAMSim archive; the repaired build's
DRAMSim source and compiled member payloads match it byte-for-byte. Archive
container hashes differ solely in member timestamps. See
evidence/dramsim_build_equivalence.json. No target configuration was inferred
from a misleading tool probe.

## Correctness, work and counters

Both primary runs exit0 normally with no assertion and identical price bits
`40984d36, 3f4f0062, 406dbc33, 4109777a`, checksum `937ac83b6f649674`.
Every result is within the official serial1e-4 tolerance of DGrefval. Host libm
reference also passes the tolerance; its float bits need not equal newlib's.

Correction generates161 unique packages and accepts161 matching BOOM-domain
results: **161 PASS, 0 FAIL, 0 CANCELLED**, no duplicate/missing identities.
All161 complete checker counter intervals close: **220,638 checked instructions,
35,765 loads, 12,066 stores**,710,587 checker-local active cycles. The one
instruction difference from hart0 is not localized to a particular instruction;
the counters use different boundaries and are not interchangeable. Historical detection exposes no
equivalent sequenced-result/work counters, so software completion and identical
workload/output do not independently prove identical internal detection coverage.

For157 packages wholly inside the software ROI (four crossing packages excluded),
checker totals are209,270 instructions,33,975 loads,11,503 stores. Priority cycle
partition: issue_available242,500; instruction_starvation172,682; dependency173,965;
LSLwait4,260; setup/redirect/management81,338; other1,127; DCache-blocked/replay0.
Their675,872 local active cycles / (4 × 431,820/2) = **78.2585%** is a lower
bound on active checker capacity, excluding the four boundary packages. It is
not an additive explanation of BOOM's46,754 extra cycles. All result-queue
backpressure counters for these157 intervals are0.

Physical cache/protocol/SVB results:

| Counter | Observed correction value |
| --- | ---: |
| Full-run releases / matched ACKs | 34 / 34 |
| Invalid ACKs / source conflicts / outstanding at end | 0 / 0 / 0 |
| SVB allocations / flush-discarded / promotions / completions | 692 / 692 / 0 / 0 |
| SVB fingerprint mismatches / final occupancy | 0 / 0 |
| Maximum SVB occupancy / per-line depth | 4 / 1 |
| Would-full-at8 / cycles above8 / capture failures | 0 / 0 / 0 |
| SourceC reserved / ACK wait / target lock cycles | 3,135 / 915 / 4,050 |
| Releases accepted during ACK wait | 0 |
| Semantic store effects / effect-edge terminal enqueues | 14,052 / 14,052 |
| Effect-edge terminal deliveries | 13,230 |
| Terminal enqueues / deliveries | 14,101 / 14,101 |
| Applied-S3 blocking / terminal queued-blocked cycles | 0 / 1,004 |
| Forwarded successor store admissions | 8,180 |
| Retaining requests / retaining receipts / all WB receipts | 31 / 31 / 34 |
| Invalidating clears / owner mismatches / probe revokes | 3 / 0 / 0 |
| L1D accesses / misses / replacements / MSHR-full cycles | 55,689 / 252 / 0 / 0 |
| L2 accesses / misses / replacements / MSHR-full cycles | 18,235 / 62 / 0 / 0 |

These hardware traffic statistics span464,266 BOOM cycles from observer START
to STOP, including preparation and correctness/output outside the software ROI;
checker clocks contribute232,133 cycles each in that window. Full lifecycle/
protocol counters cover the captured session through exit. Counter windows must
not be substituted for the431,820-cycle primary ROI. The exact counters and
their schemas are in blackscholes_analysis.json and checker_profile.json.
Capture has95 active producer/observer identities, all conserved, zero omitted
mandatory or optional records. Protocol, allocation integrity, same-line ordering,
SC48/49/50/51 validation pass. L1/L2 cache-shadow fidelity fails: geometry or
cycle predictions from those models are excluded.

## Failure, repair and verification limits

Frozen C's accepted WB snapshot outlives a flush that clears the DCache capture
owner, then incorrectly allocates into the new epoch. The assertion fires at
BOOM30,045; exact cause/evidence and the minimal patch are in
[CORRECTNESS_FINDING.md](CORRECTNESS_FINDING.md). The repair retains an issued
descriptor until the snapshot arrives, marks it cancelled on flush and drains
it without new-epoch allocation; unissued requests cancel immediately. Identity
and owner assertions remain enabled. The new discard diagnostic is still
verbose-gated; its precise event count is **unobserved**, not zero.

Six reduced cancellation contracts,11 overlap contracts,7 retention contracts
pass. Actual unchanged WB RTL passes160 snapshots, including80 returned after
modeled controller cancellation. Actual repaired full-system RTL passes a40,000-
cycle reproduction of the original flush/read interleaving, followed by this
complete Blackscholes run. Reduced contracts and the WB unit are supporting
evidence; the complete system execution is the runtime validation.

**All692 allocated SVB images are flush-discarded; none is durably promoted.**
Allocation/fingerprint conservation PASS therefore does not establish durable
recovery. This is the pre-existing general flush/recovery limitation, beyond
the narrow in-flight descriptor repair. No fault injection, rollback recovery,
exhaustive trap timing, synthesis timing or FPGA signoff is claimed.

The1.12142× result supports low additional correction overhead on this small,
cache-resident independent no-fault workload. It is consistent with the BFS
low-overhead observation but uses a **different denominator**: BFS1.12617× is
correction/native; Blackscholes1.12142× is repaired-correction/detection. Their
numeric similarity is not equivalence. This sample leaves workload-dependent
frontend/dependency/management activity; no causal46,754-cycle attribution is
available from detection counters. No optimization follows this result.

## Exact commands and artifacts

From `/data1/gzh/EC-opt4-perf`:

```sh
python3 -I -B slowdown/blackscholes_validation/scripts/build_workload.py
python3 -I -B slowdown/blackscholes_validation/scripts/build_matched_check.py
python3 -I -B slowdown/blackscholes_validation/scripts/verify_configuration.py
python3 -I -B slowdown/blackscholes_validation/scripts/build_matched_tools.py
python3 -I -B slowdown/blackscholes_validation/scripts/run_workload.py check_matched_v5048 --smoke
python3 -I -B slowdown/blackscholes_validation/scripts/run_workload.py check_matched_v5048
python3 -I -B slowdown/optimization_6_overlap/scripts/run_experiment.py --jobs 16 --label blackscholes_capture_flush_fix --build-only
python3 -I -B slowdown/blackscholes_validation/scripts/run_workload.py correction --smoke --smoke-cycles 40000 --correction-build overlap_blackscholes_capture_flush_fix_20261103_064936_fd6cd4a6
python3 -I -B slowdown/blackscholes_validation/scripts/run_workload.py correction --correction-build overlap_blackscholes_capture_flush_fix_20261103_064936_fd6cd4a6
python3 -I -B slowdown/blackscholes_validation/scripts/analyze_workload.py slowdown/blackscholes_validation/runs/check_matched_v5048_test4_20261103_072238_9f052bd1
python3 -I -B slowdown/blackscholes_validation/scripts/analyze_workload.py slowdown/blackscholes_validation/runs/correction_test4_20261103_072928_2409f537
```

Build IDs are generated per invocation; substitute the fresh printed correction
ID on reproduction. Build scripts refuse to overwrite started artifacts. The
initial matched build needed `resume_matched_check.py` to fix an sbt socket path;
clean reproduction now maps its private temp directory to/tmp from the outset.

Exact absolute simulator argv, seed, host, software/binary/source seals and wall
times are in each evidence/RUN_ID/run_manifest.json and command.sh. Full compact
events, cache observation and checker profiles are preserved, including the
original failed C and successful smoke. Build logs/manifests, exact hardware
patch and SHA256SUMS.json accompany them. The frozen-C failure used
`run_workload.py correction` with the original sealed binary; after the repair
this command correctly rejects the changed hardware hash unless the repair's
explicit build ID is selected. Never relabel a repaired run as frozen C.

The same-binary BFS regressionPASS: **1,128,052 ROI cycles**, unchanged from
frozen C (delta0),1.126165672×native, checksum43439728. Protocol/integrity/
ordering/capture/SC48–51PASS; zero FAIL/CANCELLED/assertions. Mandatory capture
is complete;538 optional diagnostic records were omitted by the fixed budget,
the same count as frozen C. Exact regression command:

```sh
python3 -I -B slowdown/optimization_6_overlap/scripts/run_experiment.py --resume overlap_blackscholes_capture_flush_fix_20261103_064936_fd6cd4a6
```

BFS raw event stream, summaries and profiles are preserved under
evidence/overlap_blackscholes_capture_flush_fix_20261103_064936_fd6cd4a6;
evidence/bfs_regression.json records the comparison. Correctness repair is
commit83dec9d4c10ab8c097fe5ab5c8af1c0a270fba6d. Validation is complete; no
further build, experiment or optimization is planned.
