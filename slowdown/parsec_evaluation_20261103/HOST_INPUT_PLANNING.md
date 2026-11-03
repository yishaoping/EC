# Simulation input feasibility

Host profiles count official Streamcluster function calls with `-pg -fno-inline`
in a separate host executable. They do not measure RISC-V instructions, target
cycles, cache behavior or slowdown. The target executable and kernel are unchanged.
Exact host commands, source hash, gprof output, gmon data and host executable are
preserved in `raw/diagnostics/streamcluster_host_work_profile/`.

| Input | Points | Dimensions | dist calls (host) | pgain calls (host) | dist × dimensions / simdev |
|---|---:|---:|---:|---:|---:|
| simdev | 16 | 3 | 10063 | 621 | 1.00 |
| project32 | 32 | 3 | 18177 | 552 | 1.81 |
| project64 | 64 | 3 | 40231 | 621 | 4.00 |
| project256 | 256 | 16 | 196170 | 759 | 103.97 |

The measured simdev target application requires 854140 native cycles and 920602
detection cycles. A linear distance-work extrapolation alone would put project256
near 89 million native cycles (more than a day at the observed approximately
700 correction-model cycles/host second), before allowing for altered branches,
cache misses, version traffic or different target floating-point/RNG behavior.
This is a feasibility estimate, not a target performance prediction or result.
Project64 is the larger practical candidate; project32 is a prepared fallback.
Target runs determine the actual completion cost and correctness.

Blackscholes project64 preserves 100 official pricing rounds and derives the first
64 options from official simsmall/in_4K, with the parent and derived input hashes
recorded. It is 4x the 16-option pilot while remaining below the 10-million-cycle
per-run ceiling. Full 4096-option simsmall is approximately 256 times the pilot
and is impractical at the measured Verilator throughput.

Canneal project400 uses the official 100.nets with 400 swaps per temperature and
two temperature steps, versus 100 swaps and two steps in simdev. It is 4x the swap
loop; the graph remains 100 nodes. Its host integer routing cost is 4789. The
prepared project1k variant would run 20x the simdev swaps and is excluded from the
main matrix on cycle-budget grounds. Official simsmall uses 100000.nets, 10000
swaps and 32 steps, exceeding this firmware's memory and simulation budget.

These project inputs characterize official serial kernels at simulation scale.
They cannot support claims about full PARSEC working sets or parallel scaling.
