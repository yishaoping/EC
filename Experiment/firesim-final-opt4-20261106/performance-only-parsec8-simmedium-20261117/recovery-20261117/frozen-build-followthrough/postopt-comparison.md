# Performance-Only CSR/RSU repair: matching post-opt comparison

| Metric | Before | After | Delta |
|---|---:|---:|---:|
| CLB LUTs | 824809 | 815919 | -8890 |
| CLB Registers | 448466 | 448361 | -105 |
| Register as Flip Flop | 448465 | 448360 | -105 |
| F7 Muxes | 43726 | 44334 | +608 |
| F8 Muxes | 9633 | 10342 | +709 |
| F9 Muxes | 0 | 0 | +0 |
| Block RAM Tile | 698.5 | 698.5 | +0 |
| URAM | 0 | 0 | +0 |
| LUT as Memory | 41252 | 41252 | +0 |

Not measurable from unplaced post-opt; use placed congestion and per-SLR reports

Top 80 nets only; absence of metadata names does not prove their exact fanout
