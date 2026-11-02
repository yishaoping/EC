# Non-strict performance reference

`REFERENCE_COMPARISON`; `A_NON_INTERFERENCE_PROVEN = NO`. Delta=B−A; negative means lower. These are observed differences between old A and corrected B, not the final geometry-only effect. B normal completion:exit0, verified1, checksum43439728; software ROI start698301/stop2347224,1,648,923 cycles. The two causal snapshots match exact marker cycles; this is not a partial assertion prefix.

| Metric | Old A | New B | Delta (B−A) | Delta % |
|---|---:|---:|---:|---:|
| ROI cycles | 1,707,863 | 1,648,923 | -58,940 | -3.4511% |
| L1 lookup misses (traffic window) | 3,272 | 2,624 | -648 | -19.8044% |
| ROB-head load-miss waiting | 139,694 | 53,845 | -85,849 | -61.4550% |
| nack retry events | 111,548 | 47,162 | -64,386 | -57.7204% |
| RPQ replay events | 321 | 229 | -92 | -28.6604% |
| RPQ replay cycles | 321 | 229 | -92 | -28.6604% |
| MSHR busy cycles | 313,150 | 194,905 | -118,245 | -37.7599% |
| MSHR full cycles | 0 | 0 | +0 | N/A (A=0) |
| scheduler∩MSHR busy | 154 | 269 | +115 | +74.6753% |
| scheduler∩MSHR full | 0 | 0 | +0 | N/A (A=0) |
| scheduler unavailable cycles | 318,150 | 347,409 | +29,259 | +9.1966% |
| load tag-miss requests | 1,533 | 1,060 | -473 | -30.8545% |
| store tag-miss requests | 2,478 | 2,324 | -154 | -6.2147% |
| MSHR primary allocations | 2,162 | 1,883 | -279 | -12.9047% |
| MSHR upgrades | 115 | 74 | -41 | -35.6522% |
| MSHR merges | 952 | 741 | -211 | -22.1639% |
| MSHR request rejects | 47,064 | 20,433 | -26,631 | -56.5847% |
| ROB-head any pending load | 151,352 | 80,832 | -70,520 | -46.5934% |
| any LDQ miss pending | 145,926 | 57,440 | -88,486 | -60.6376% |

Lookup misses use matching hardware traffic-window definitions (A[712021,2430802), B[698208,2358291)); they are not advertised as exact software-ROI miss counts. The remaining table counters are from exact software ROI snapshots. Load/store tag miss request counters are distinct from unique-token lookup misses; do not sum their different definitions.

Latency cohorts: completions in ROI, may begin before ROI, unfinished requests censored. Means are observed cohort averages, not per-miss penalties or guaranteed service latencies.

| Metric | A samples | B samples | A mean cycles | B mean cycles |
|---|---:|---:|---:|---:|
| load miss detection→allocation | 1380 | 960 | 324.3130 | 164.1896 |
| MSHR allocation→refill | 2162 | 1883 | 126.9519 | 83.5534 |
| load miss detection→data | 1530 | 1052 | 347.8379 | 200.6131 |
| completed load miss ever at ROB head: waiting per miss | 409 | 251 | 341.5501 | 214.5219 |

MSHR exact-ROI occupancy A=[1394713, 312184, 953, 13, 0, 0, 0], B=[1454018, 194510, 395, 0, 0, 0, 0]. Mean occupancy 0.183931→0.118441; busy fraction18.3358%→11.8201%; max observed3→2 with6 available. Full0 in both. More MSHRs have no measured direct saturation justification.

All3 latency distributions are in reference_comparison.json (bin0=0, binN=[2^(N−1),2^N−1], bin31 saturates). No per-ROB blocking-episode duration distribution was recorded. Completed misses ever at head409→251 and aggregate head episode cycles139,694→53,845 are available; the mean per completed head-touching miss is descriptive and not a full distribution. No independent DRAM-only latency counter is present.
