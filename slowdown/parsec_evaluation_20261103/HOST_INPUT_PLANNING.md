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

Blackscholes project32 preserves 100 official pricing rounds and derives the first
32 options from official simsmall/in_4K, with the parent and derived input hashes
recorded. Full 4096-option simsmall is approximately 256 times the 16-option pilot
in pricing work and is unsuitable for the current approximately 700 cycle/second
simulation throughput. Project64 would double project32; selection must also
reserve practical time for three baselines and repeatability checks.

Canneal project1k uses 100.nets with 1000 swaps per temperature and four temperature
steps, versus 100 swaps and two steps in simdev. The netlist is not 1000 nodes.
The exact host routing cost is 4293. Its irregular swap loop is enlarged without
claiming a simsmall-sized graph or a large cache footprint. Official simsmall has
100000.nets, 10000 swaps and 32 steps and exceeds this firmware's practical memory
and target simulation budget.

These project inputs characterize official serial kernels at simulation scale.
They cannot support claims about full PARSEC working sets or parallel scaling.
