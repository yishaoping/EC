# Baseline preservation and minimal background recovery, 2026-11-04

## Baseline verified before process investigation

All three primary Correction runs identify the same evaluated hardware:
`a6e63c75947739dfbb411b32bfe0eb5ed55c5bb1`, simulator SHA256
`4121b8a4005a39db85e7ad2c98f7ccebd7acd0b47b1c95e230f1fd6fbc9adc40`.
Their recorded evaluation worktrees were clean. The 23 sealed hardware-file
hashes equal that commit's contents. Six restored non-Git Verilog resources
also match their sealed hashes and are included in the independent snapshot.
Thus the tag alone is not presented as a complete portable build backup.

- Tag: `opt4-parsec3-pre-rescue-20261104`.
- Branch: `backup/opt4-parsec3-pre-rescue-20261104`.
- Verified read-only payload:
  `/data1/gzh/EC-backups/opt4-parsec3-pre-rescue-20261104/`.
- Completion: `BACKUP_COMPLETE.json`, 18,531 files rehashed; full provenance in
  `MANIFEST.json`, `VERIFICATION.json` and `SHA256SUMS.json`.
- Exact source snapshots: `source/correction/`, `source/detection/`.
- Original primary/repeat run logs, reports, commands, ELF/input/build data:
  `evaluation/` and `software/`. Exact two model executables: `models/`.
- Detector source is historical `b3d7adddd1e2d2cf428dd933529de878226420cd`
  plus the three configuration-only changes. Its saved actual source diff
  byte-matches the configuration patch, whose SHA256 is
  `5f4ba67c8fa0be083ee69082ed304fcca2e924dcf4b652d1bc85a0d4f75dc26e`.
  Native and Check reuse the same sealed detection executable, SHA256
  `60e66a4a8a7b0c89e75ef9b3e91faededd6cc70da75e0176bb3accee53ab956a`.

Hardware chronology, with annotated tags resolved to commits:

| State | Commit |
|---|---|
| Performance Opt4, historical BFS tag | `5343ea33f7ccc1b4d140eef09e2d07ab775ae72c` |
| Snapshot ownership repair | `83dec9d4c10ab8c097fe5ab5c8af1c0a270fba6d` |
| First corrected checkpoint | `1532923803d7451b0c7843e9abad1c90ef9eb9ed` |
| Actually evaluated three-workload r2 | `a6e63c75947739dfbb411b32bfe0eb5ed55c5bb1` |
| ICache candidate | `2b0ea7ff07be09447a1f540c8682b85d15b4a82f` |
| Rescue r2 candidate | `ae0d80a65a5d890b59e4c67575c0cb6af59730ae` |

`CONFIG.md`'s old opening paragraph identifies the first corrected checkpoint;
the sealed manifests and executable/source hashes establish the actual r2
revision. Backup verification finished at 07:36:38 UTC, before the process
audit. No reset, clean, stash, checkout, worktree deletion, FPGA or check source
modification was used.

## Original runner diagnosis

`/proc/4056618` is absent, and an executable/script-argument scan of `/proc`
found no runner, compiler or simulator belonging to either recovery worktree.
PID 4056618 wrote `COMPLETE_WITH_FAILURES` at approximately 07:14:04 UTC
(15:14 Shanghai), then exited. This was a supervised terminal failure, not
evidence of an orphaned simulation or OOM. Its terminal path implies exit 1;
the child exit status 1 is directly recorded. The external launcher did not
record the parent exit code independently, so that distinction is retained.

Candidate 1 completed all four fixed workloads and comparison with exit 0.
Candidate 2 completed RTL generation, C++ compilation and three directed
tests, sealed its revision, then failed this command before allocating any
simulation run directory:

```text
python3 scripts/run_profile.py canneal_project400 <sealed rescue revision> --max-cycles 2500000
AssertionError: Evaluation must start from a clean worktree:
?? slowdown/recovery_perf_20261104/FINAL_COMPARISON.csv
?? slowdown/recovery_perf_20261104/FINAL_STATUS.json
?? slowdown/recovery_perf_20261104/RESULTS.md
?? slowdown/recovery_perf_20261104/UNATTENDED_LAUNCH.json
```

Full command, scripts and logs remain under
`build/overlap_svb_rescue_r2_20261104_042210_dc665532_measurement_5e59b3/`
and `runs/finish_20261104_044755_459677/`. There was no candidate-2 runtime
assertion, simulation timeout or measured application output at this stage.
The earlier private epoch-driver path error was separately fixed and its
successful directed results preserved.

## Completed candidate evidence

| Workload | Native | Check | Frozen correction | ICache correction | Corr/Check | ROI reduction |
|---|---:|---:|---:|---:|---:|---:|
| Blackscholes project64 | 5,920,394 | 5,952,831 | 6,165,734 | 6,114,946 | 1.027233 | 0.8237% |
| Streamcluster project64 | 2,281,930 | 2,499,121 | 3,706,513 | 3,547,466 | 1.419485 | 4.2910% |
| Canneal project400 | 310,942 | 419,398 | 668,878 | 548,437 | 1.307677 | 18.0064% |
| BFS (native normalized separately) | 1,001,675 | N/A | 1,128,052 | 1,125,574 | N/A | 0.2197% |

BFS Correction/Native is 1.123692. All four test processes and the comparison
exit 0. Application ELF/output/retired instructions match; full-session checker
work is complete in all three PARSEC analyses and BFS. Normal protocol,
integrity, ordering and release/ACK checks pass. PARSEC geometric-mean cycle
reduction is 8.0158%, without an observed regression. Small Streamcluster
simdev reduction was 2.1983%, independently of this main-input result.
The requested <1.2 ratios remain unmet. Architectural fault recovery and
area/timing signoff remain outside these no-fault performance validations.

Candidate preservation is independent of the frozen backup:
`/data1/gzh/EC-backups/opt4-recovery-candidates-20261104/` contains 157 verified
read-only files, hardware diffs against the frozen source, changed source
files, manifests, completed raw runs, scripts and original failure logs.

- `opt4-recovery-candidate1-icache4k-20261104` points to `2b0ea7ff0`.
- `opt4-recovery-candidate2-rescue-r2-20261104` points to `ae0d80a65`.
- Both change `Configs.scala` (four checker ICache ways 1→2, total +8 KiB),
  with observation-only additions in BOOM `core.scala` and `dcache.scala`.
  Candidate 2 additionally retries a previously qualified full-SVB fallback
  through existing capture, with persistent cancellation of its permission.
- Candidate 2 admission: 20,025 checks PASS; cancellation: 10 cases / 353
  checks PASS; epoch: 73 cases / 2,818 checks PASS. SVB/WB emitted module
  identities match their previously directed-tested bytes. Main-input
  performance remains unmeasured until the resumed run completes.

## Minimal recovery

Only the four generated report/state filenames are added to `.gitignore`.
The original clean-worktree gate and full hardware/model/input hash checks
remain enforced. No RTL, cache parameter, benchmark or generated build is
modified. Original reports are backed up before they can be updated.

The resume option accepts only this known prelaunch failure, verifies the
same build identifier and sealed executable, and reuses the successful
directed-test results only after matching their emitted RTL hashes. It reuses
the existing sealed revision rather than attempting to seal over that
directory. Candidate 1 and compilation are not repeated.

The detached driver records PID, process group, session ID, timestamps,
commands, child IDs, process snapshots, exit statuses and terminal markers.
After resume it runs only Canneal first; only a validated incremental gain
above 0.5% over the completed ICache candidate, with observed rescue handoff,
permits the remaining three regressions. That Canneal result is reused.
Failures stop with preserved logs.

Latest launch/actual-process verification is recorded separately in
`/data1/gzh/EC-backups/opt4-process-recovery-20261104/RECOVERY_STATUS.json`,
with `UNATTENDED_LAUNCH.json` and `FINAL_STATUS.json` providing the live job
locations. The initial failed status is preserved and is not relabeled PASS.
