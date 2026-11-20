EC Performance-Only: data preservation + cache isolation — round 192

Hardware remains `6fada307bb77be90b39720d3f95404fece0e431b`. No new cuts,
restarts, duplicate tests, target generation, host generation, CAD jobs, or FPGA
operations were launched in this round. This prototype is excluded from the
full EC / PALIMPSEST results ledger.

R5 completed normal MCRams host conversion, then failed on its missing
`cad_engine.py`. Preinstalled R6 (`cef2d0b`) authenticated that exact failure,
predecessor cgroup release, successful regression, and completed host receipts.
R6 reused the host and started the sole prototype complete-shell CAD pipeline
at 2026-11-13 03:40:47 UTC. Its DUT synthesis started at 03:40:49 UTC. The private
project reuses eleven unchanged shell IP checkpoints. A completed shell link,
zero unresolved functional blackboxes, and post-opt resources remain required.

| Existing evidence | Direct observation | Scope and limit |
|---|---|---|
| R5 DCache finite regression | PASS: 8,192 cycles, 24,575 observations, 2,446 signals / 66,503 compared bits, 512 generation taps; assertions enabled; C beats = 0 | Surviving functional ports and observed state compared against the frozen model. This run provides no SVB/WB traffic coverage claim. |
| Foreground directed DCache preservation R2 (`a3264168`) | PASS: 8,192 cycles, 24,575 observations; 34 captures; peak occupancy 32; 3,126 full wait cycles; 199 C backpressure cycles; 16 C beats; 3 SVB acknowledgments; final occupancy 0 | New stimulus linked against the existing translated C++ archive. Checks frozen/candidate SVB ownership events and prevents early C publication before supplied checker results. Checker results are injected at the DCache boundary. This is finite DCache coverage, without integrated checker execution. |
| Foreground real LSL R1 (`f792ba09`) | PASS: 1,310 cycles; 508 records saved and consumed; exact 64-bit data and original outputs compared; two mismatches and one killed request preserved the head; capacity backpressure observed | Finite LSL module comparison. The complete checker and whole system did not execute in this test. |
| Actual complete prototype shell | Pending | No prototype LUT total, capacity verdict, physical timing result, bitstream, runtime certificate, or onboard benchmark sample exists at this observation. |

The foreground tests were consumed, authenticated, and preserved; they were not
duplicated. `artifact-audit.json` authenticates 167 bound files across the R6 and
foreground validation bindings, six successful stage receipts and their logs,
the foreground coverage evidence, and the unchanged full-EC shell ledger.

The actual hardware cut removes diagnostic AddressStats, three barrier-statistics
instances, dirty-writeback diagnostic buckets, and the LSU statistics interface.
R1/R2 hardware retains recovery logic as well as ordinary miss replay and CPU
recovery. It retains real LSL/SVB storage, cache geometry, Cache Versioning,
isolation, checker completion logic, safe normal commit/release, and their
backpressure. Source continuity establishes retained source identity; it does
not establish dynamic execution. Removed diagnostic metrics are unsupported /
invalid, and zero diagnostic pending is not a drain certificate.

Preserve R6 through actual complete-shell post-opt before any further hardware
cut. NOTFIT requires the new actual hierarchy before a targeted substantial
cut. FIT proceeds through physical implementation and exact profile timing,
DRC, bitstream identity, ABI/software and card21 certification, with genuine
integrated checker, boot, preservation/isolation and drain validation before
performance sampling. Only `0000:21:00.0`, serial `21770433G02LA`, is allowed.
Healthy old full-design CAD remains owned by its existing services; the separate
CPU session and preserved SVB campaign were not controlled or monitored.
