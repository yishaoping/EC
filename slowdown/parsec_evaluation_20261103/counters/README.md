# Counter scopes

`RUNS.csv` holds every validated run, including pilot and repetition runs.
`RESULTS.csv` selects one validated equivalent triplet per main workload; repeats
are not extra benchmarks in the geometric mean. N/A means no suitable observation,
not zero activity. Diagnostic and aborted runs do not enter either table.

| Field family | Window and interpretation |
|---|---|
| ROI cycles / instructions / IPC | Application call only; `rdcycle`, `rdinstret`; samples identical in every mode |
| Total harness cycles | Reset/startup/application/output/exit drain; architectural target cycles |
| Host seconds | Wall time inside capture; simulation cost, excludes compilation |
| Packages, PASS/FAIL/CANCELLED | Full protected session; BOOM-domain accepted results, not local done |
| Checked instructions/loads/stores | Full protected session only when every package has valid start/end counter snapshots; otherwise N/A |
| Checker active-capacity lower bound | Complete, fully captured packages entirely inside application ROI; sum of local active cycles / (4 × ROI/2); boundary/omitted packages excluded |
| Checker frontend starvation | Sum of the same packages' checker-local priority partition; not BOOM stall cycles |
| Result queue backpressure | Available checker lifecycle snapshots only; observed subset, not a full-session total |
| SourceC ACK wait | Existing full traffic-window count; overlaps other activity; not causal savings |
| Store-result wait | Existing terminal queue blocked cycles in the traffic window; not all main-core stalls |
| Version-management block | Existing first preservation-admission block cycles, event 31; not every possible version-related delay |
| L1 aggregate hits/misses | Existing unique first-S2 request-token observations; load/store split unavailable |
| L1 probe evictions | Probe metadata eviction count only; total evictions N/A |
| L1 writebacks | Existing L1 writeback observation count |
| L2 accesses/misses | A-channel directory lookups, including retries; not application load count |
| Memory requests/bytes | Existing DRAM-facing read/write observations in traffic window |
| SVB created/completed/coalesced/discarded/retained | Full-run conservation, independent of observation RESET/START/STOP |
| SVB peak/depth | Maximum retained occupancy/same-line depth during the hardware measurement window |
| Snapshot release | SVB promotion-issued count; excludes normal releases |
| Snapshot flush/drop | Full-run discarded count; detailed reason remains in integrity ledger |
| ACK count | Matched normal+SVB ReleaseAcks over full captured session |
| Outstanding at app end / last verification / drain | Packages allocated before app end, including start boundary package; later STOP packages excluded |

Checker frontend/live-window counters and terminal queue snapshots remain in each
run's complete `analysis.json`; the CSV is not a replacement for raw evidence.
Queue-empty/full, checker-idle, safe-watermark stall and prevented-refetch counts
are N/A where no counter of the requested meaning exists. No heavyweight
instrumentation was added. No cache-shadow geometry estimate is used as a measured
cache count or predicted performance improvement.
