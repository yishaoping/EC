# Opt4 freeze / archive result — 2026-11-02

Stable optimization **Opt4**, optimization **PAUSED**. No functional change to Opt4;
post-Opt4 experiments restored to the measured source only after preservation.
Freeze commit **962c4b87db2a810bc025a87f5f7289dd7aedc5cf**; functional-source
identity remains476a760910f3bfbd3c111000ebe40343870ab439.
The archive commit is the commit containing this report (`git log -1 --format=%H -- slowdown/CLEANUP_RESULT.md`).

- **Preserved:**200 small analysis report files;5 actual-diff patches; exact dirty source/
  script snapshots. Four ordered patches reconstruct all16 hardware/host files with
  byte/mode identity. Original AI/TMP reports/seals/claims/raw FAIL/recovered B, raw
  performance/correctness data, manifests, software, build products and waveforms remain.
- **Relocated:**2 unclassified legacy dramsim.log files (root and simulator CWD).
  All22 other run/evidence logs stay at existing paths with identical hashes.
- **Deleted:**46 reproducible Python bytecode files (604,542bytes) and10 empty
  __pycache__ directories. Exact paths/hashes/reasons in deleted_files.json; no unique
  runtime/research/benchmark evidence deleted.
- **Unknown:**19 build/cache/tmp directory groups retained. No broad cleanup by age/size.
- **Checked:**122 CPU tests in8 suites;599 frozen source/software/patch/report/evidence
  audits;24 shell syntax checks;147 local links in109 documentation files; original
  Opt4 run reanalysis equals prior corrected result for every correctness/ROI gate.
  Failed original L2 S0 remains explicit, not promoted to valid geometry evidence.
- **Not executed:**hardware generation, Verilator build, benchmark, optimization or
  remote operation. No tag created because no existing tag convention was found.

[Validation](analysis_archive/cleanup_evidence/validation_result.json),
[cleanup plan](CLEANUP_PLAN.md), [Git pre-state](GIT_PRE_CLEANUP_STATE.md),
[log relocation](analysis_archive/cleanup_evidence/log_relocation.json),
[deletions](analysis_archive/cleanup_evidence/deleted_files.json),
[unknown retained](analysis_archive/cleanup_evidence/unknown_kept.json).

Current DAC entry: [OPT4_BASELINE](OPT4_BASELINE.md) and existing
optimization_4_svb/v1Config runner. Future Opt5 recovery starts with
[history](analysis_archive/OPTIMIZATION_HISTORY.md),
[resume guide](analysis_archive/RESUME_OPTIMIZATION.md) and
[experimental patches](analysis_archive/experimental_patches/README.md).
Final post-commit Git status is recorded locally in
AI/TMP/opt4_freeze_cleanup_20261102/final_git_state.json; no unrelated dirty files
were identified during the pre-commit review.
