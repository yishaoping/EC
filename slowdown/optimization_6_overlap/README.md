# Opt4 performance work

Worktree: `/data1/gzh/EC-opt4-perf`, branch `opt4/perf-20261103`.
The FPGA/main working tree is independent and must not be reset or cleaned.

| Implementation | ROI cycles | Slowdown vs native | Validation |
| --- | ---: | ---: | --- |
| Frozen Opt4 `476a76091` | 1,707,863 | 1.705007x | Frozen verifier / original measured run |
| Direct checker delivery + SourceC waitAck overlap | 1,426,845 | 1.424459x | Functional, integrity, ordering, protocol and capture PASS |
| Terminal bypass + prefix fusion + fetch8 | 1,174,774 | 1.172810x | Functional, integrity, ordering, protocol, capture and SC48/49/50 PASS |
| Retain acknowledged safe T copy in L1 | Pending | Pending | RTL generation/configuration and WB unit tests PASS; sealed simulation running |

All rows use the pinned GAPBS BFS workload (512 nodes, 8,192 edges, source 0),
native ROI 1,001,675 cycles, expected checksum 43,439,728. Four 100 MHz checkers,
200 MHz BOOM, cache geometries and line sizes remain fixed. Fetch8 changes the
checker instruction-supply width; scalar decode/retirement stays at one.

The current best validated run is
`overlap_terminal_fetch8_prefix_20261103_031553_2a566233`.
Its compact results, exact source patch, binary seal and generated configuration
check are in [`results/terminal_fetch8_prefix`](results/terminal_fetch8_prefix).
The first milestone is retained in [`results/direct_sourcec_v2`](results/direct_sourcec_v2).
The validated hardware commits are `4250b35fe` (A) and `40c8a18ca` (B).
The ignored run/build directories retain full mandatory evidence and all failed
attempts. [`OPTIMIZATION_LOG.md`](OPTIMIZATION_LOG.md) records decisions;
[`CANDIDATE_AUDIT.md`](CANDIDATE_AUDIT.md) separates source arguments from runtime
evidence. [`CACHE_VERSION_STATE.md`](CACHE_VERSION_STATE.md) reconstructs the
image/receipt/epoch, preservation, result and eviction boundaries. Candidate patch
files are historical preparation artifacts; active
changes are the Git diff and each run's sealed `source.patch`.

From this worktree's root:

```sh
python3 -I -B slowdown/optimization_6_overlap/scripts/run_experiment.py --static-check
python3 -I -B slowdown/optimization_6_overlap/scripts/offline_overlap_tests.py
# Use the IBuf runner only while other SBT jobs in this worktree are idle.
python3 -I -B slowdown/optimization_6_overlap/scripts/run_ibuf_rtl.py
python3 -I -B slowdown/optimization_6_overlap/scripts/run_experiment.py --jobs 16 --label candidate
python3 -I -B slowdown/optimization_6_overlap/scripts/analyze_overlap.py RUN_DIRECTORY --output RESULT.json
python3 -I -B slowdown/optimization_6_overlap/scripts/verify_configuration.py BUILD_DIRECTORY/generated
```

The runner freezes software/source/tool inputs, uses private build directories,
and rechecks its seal before simulation. Do not edit hardware/runner or commit
until `SIMULATION_STARTED.json` exists. Failed or incomplete builds cannot be
resumed as successful binaries. Simulation inputs are never reused after start.

Reported activity counters are overlapping local observations, not causal cycle
savings. Optional frontend prefix snapshots have explicit gaps. SC48/49/50 final
snapshots require complete mandatory capture and conservation. L2 shadow-model
fidelity fails and its geometry estimates are not decision evidence. A passing
benchmark and SVB lifecycle ledger do not establish all rollback paths or full
durable recovery/drain; synthesis timing and FPGA signoff are outside these tests.
