# Reproducible evidence boundaries

Validated FPGA Native samples: 45; programs: 15/16. Opt4 FPGA samples: 0; paired FPGA comparisons: 0.

Original result and atomic complete hashes were checked; raw logs remain at their original paths and are not overwritten. Hardware/software/input identity and historical BDF are retained.

CPU RTL replay: cycleprecise-frozen-canneal-20261111 (new execution, await complete.json). It uses the sealed 8491167d simulator and identical project400 ELF/input; it is not Linux simmedium or FPGA performance.

Space/time prototype: cycleprecise-route-a-r2-20261111 and cycleprecise-metasim-r4-20261111. Boundary read/reset/overlap tests do not constitute whole EC equivalence. FMR measures host cost, never target slowdown.

Never report the historical protection-disabled detection-model Native as the strict single-BOOM baseline. A new true Native cycle-precise comparison needs the same target memory model/software/ROI; existing FPGA rows can only cross-check a matching metasim.

The original architectural rollback behavior must be measured as implemented. No new recovery controller is part of this route; normal PASS, SVB invalidation and process exit do not establish architectural restore/restart.
