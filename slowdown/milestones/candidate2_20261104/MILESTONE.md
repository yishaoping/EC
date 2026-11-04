# Candidate 2 performance milestone

This checkpoint preserves the exact evaluated Candidate 2 hardware from
`ae0d80a65a5d890b59e4c67575c0cb6af59730ae`. All 23 manifest hardware inputs
and six restored Verilog resources match the saved build byte for byte.
The six resources were previously ignored; they are source inputs, not generated RTL.
The checkpoint commit is resolved by the immutable tag
`opt4-candidate2-parsec-20261104`; SOURCE_IDENTITY.json records the complete
manifest source/configuration identity. No newer aggressive changes are included.

Candidate 2 combines a 4 KiB checker instruction cache with cancellation-aware
retry of eligible full-SVB fallbacks when capture capacity returns. Snapshot
ownership, exact entry/key ACK, watermark checks and four checker harts remain.

| Workload | Input | Native ROI | Check ROI | Candidate 2 ROI | C2/Native | C2/Check |
|---|---|---:|---:|---:|---:|---:|
| PARSEC Blackscholes | project64 | 5,920,394 | 5,952,831 | 6,114,946 | 1.032861326459016 | 1.0272332609476063 |
| PARSEC Streamcluster | project64 | 2,281,930 | 2,499,121 | 3,441,485 | 1.5081466127357106 | 1.377078180688330 |
| PARSEC Canneal | project400 | 310,942 | 419,398 | 489,737 | 1.5750107737134256 | 1.1677141998769665 |
| GAPBS BFS | 512 vertices / 8192 edges / source 0 | 1,001,675 | N/A | 1,126,805 | 1.124920757730801 | N/A |

PARSEC geometric mean C2/Native: **1.3487238460653828**.
PARSEC geometric mean C2/Check: **1.1821014331491617**. BFS is excluded.
Benchmark inputs, protected ELF hashes, ROI definitions and command lines
are retained in the evidence metadata. No baseline or candidate test was rerun.

Build: v1Config, 16 SVB entries, four checker harts, Verilator 5.048,
one Verilator thread, assertions enabled, STAGE1_EXIT_PORTS and SAFE_CHAIN_EVENTS,
DRAMSim, no waveform tracing, seed 1. Host build parallelism does not define
simulated hardware. Exact source/tool hashes and build command are archived.

All four normal-execution regressions exit 0 with verified output, complete
checker work, protocol/integrity/data-ordering/capture checks passing and no
assertion failures. Package PASS/FAIL/CANCELLED counts: Blackscholes 1138/0/0,
Streamcluster 1226/0/0, Canneal 135/0/0, BFS 282/0/0.

**This is a performance-validated, normal-execution-validated milestone.
Actual rollback restoration of historical PC/register/memory state remains
unproven. It is not a recovery-validated release.** The prior strict C2 fault
probe exited 0 without meeting its injection preconditions; that is unexercised
coverage, not a successful rollback test.

The original frozen baseline `a6e63c75947739dfbb411b32bfe0eb5ed55c5bb1`
and `/data1/gzh/EC-backups/opt4-parsec3-pre-rescue-20261104/` remain untouched.
The aggressive optimization continues in its separate worktree and branch.

Hardware checkpoint commit: `0d6ea4b9f468720a3fc7bee40dcb53a564ce9779`.

Run `python3 slowdown/milestones/candidate2_20261104/verify_milestone.py`
to verify committed sources and archived evidence without simulation.
The milestone branch adds metadata and ignore maintenance after this hardware
checkpoint; the release tag identifies the complete reproducible checkpoint.
