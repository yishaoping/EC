# Current measured results — 2026-11-04

**Candidate 2 Canneal complete; Streamcluster, Blackscholes and BFS running. Recovery acceptance is blocked.**

| Workload | Frozen Correction ROI | Candidate 1 ROI | C1 / Check | C1 reduction | Candidate 2 ROI | C2 / Check | C2 reduction |
|---|---:|---:|---:|---:|---:|---:|---:|
| blackscholes_project64 | 6,165,734 | 6,114,946 | 1.027233261 | 0.823714% | running | pending | pending |
| streamcluster_project64 | 3,706,513 | 3,547,466 | 1.419485491 | 4.291014% | running | pending | pending |
| canneal_project400 | 668,878 | 548,437 | 1.307676718 | 18.006423% | 489737 | 1.167714200 | 26.782313% |
| GAPBS BFS | 1,128,052 | 1,125,574 | N/A | 0.219671% | running | pending | pending |

BFS Candidate 1 / Native = 1.123691816. Matching BFS Check-only result is unavailable; no denominator is invented.

Final report and exact CSV will be written by the detached supervisor to `REPORT.md` and `exact_results.csv` in the directory recorded by `LATEST_EVALUATION.txt`. It waits for the untouched original driver and reuses completed runs. Failures remain in status.json and logs.

Canneal Candidate 2: same ELF, 392,248 application instructions, matching output; 135/135 accepted PASS results, complete checker-work coverage, protocol/integrity/data-ordering/capture PASS; zero fault/assertion markers. ROI excludes final verification drain; start-to-last-verification is 493,969 cycles. These no-fault checks do not establish rollback.

Original baseline: `a6e63c75947739dfbb411b32bfe0eb5ed55c5bb1`, permanent backup `/data1/gzh/EC-backups/opt4-parsec3-pre-rescue-20261104/` unchanged.

Candidate 1 milestone: `2b0ea7ff07be09447a1f540c8682b85d15b4a82f`; combined Candidate 2: `ae0d80a65a5d890b59e4c67575c0cb6af59730ae`. Existing candidate tags/backups retained. No recovery-validated best hardware tag is created.

See [MECHANISM_AND_RECOVERY.md](MECHANISM_AND_RECOVERY.md) for measured counter causality, the corrected pilot identity, actual injected FAIL and the missing architectural-restore proof.
