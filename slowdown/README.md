# EC slowdown experiments

Current stable optimization: **Opt4**

Approximate slowdown: **~1.7x** (measured1.7050071×)

**Optimization work is paused.**

All subsequent experiments should use Opt4 unless explicitly stated otherwise.

- [Frozen Opt4 identity, metrics and correctness boundaries](OPT4_BASELINE.md)
- Historical checking reference: [check/](../check/README.md). The old directory and compatibility symlink are removed; sealed evidence paths are resolved in memory at their current locations.
- Stable implementation/run tools: [optimization_4_svb/](optimization_4_svb/); config `v1Config`, SVB16, BOOM L1D32KiB.
- Read-only verification: `python3 -I -B slowdown/scripts/verify_opt4_frozen.py` and `bash slowdown/run_optimization_4_svb.sh --static-check`.
- Existing compatible benchmark entry: `slowdown/run_optimization_4_svb.sh`; it starts hardware when explicitly run. No benchmark is started by this cleanup.
- [Small reproducibility records and guard patch](opt4/), [shared scripts](scripts/), [local run products](runs/).
- [Optimization history](analysis_archive/OPTIMIZATION_HISTORY.md), [resume guide](analysis_archive/RESUME_OPTIMIZATION.md), [archived reports](analysis_archive/).
- [Cleanup result](CLEANUP_RESULT.md), [cleanup plan](CLEANUP_PLAN.md), [Git safety snapshot](GIT_PRE_CLEANUP_STATE.md), [validation evidence](analysis_archive/cleanup_evidence/).
- [Unclassified legacy DRAMSim logs](unclassified_logs/); known run logs stay with their runs. [Numbered root-log relocation map](manifests/workspace_relocation_20261102.json).

Directories optimization_1/2/2b, safe_chain/ and original Current tools are historical,
with original paths retained for reproducibility. No launcher path was broadly moved.
Heavy build products, caches, waveforms and raw logs remain ignored/local. The archived
64KiB L1/seq67/SourceC changes are not active Opt4 hardware. Historical README commands
and READY statements are superseded by this pause; consult the resume guide first.
