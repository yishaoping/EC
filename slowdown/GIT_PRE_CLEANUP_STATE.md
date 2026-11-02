# Git before cleanup — 2026-11-02

BRANCH = main

HEAD = 476a760910f3bfbd3c111000ebe40343870ab439

DIRTY_FILES = 19

UNTRACKED_FILES = 45

Index was empty. No reset/clean/checkout or restore was used before preservation.

Commands executed first: `git status --short`, `git diff --stat`, `git diff`, `git diff --cached`. Complete outputs and all dirty/untracked source bytes are preserved in [cleanup evidence](analysis_archive/cleanup_evidence/). The inventory excludes files newly created by this cleanup.

## Tracked changes

- `AI/Debug/history/timeline.md`
- `AI/Debug/scripts/README.md`
- `AI/Debug/state/current_debug_state.md`
- `chipyard/generators/boom/src/main/scala/exu/core.scala`
- `chipyard/generators/boom/src/main/scala/exu/rob.scala`
- `chipyard/generators/boom/src/main/scala/lsu/dcache.scala`
- `chipyard/generators/boom/src/main/scala/lsu/lsu.scala`
- `chipyard/generators/chipyard/src/main/scala/config/RocketConfigs.scala`
- `chipyard/generators/rocket-chip/src/main/resources/csrc/cache_opportunity.cc`
- `chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala`
- `chipyard/generators/rocket-chip/src/main/scala/r/R_ICSL.scala`
- `chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala`
- `chipyard/generators/rocket-chip/src/main/scala/util/SafeChainObservation.scala`
- `chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Directory.scala`
- `chipyard/generators/sifive-cache/design/craft/inclusivecache/src/L2Preservation.scala`
- `chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala`
- `slowdown/optimization_4_svb/analysis/analyze_svb.py`
- `slowdown/optimization_4_svb/scripts/compact_capture.py`
- `slowdown/optimization_4_svb/scripts/launch_optimization_4_svb.py`

## Untracked files

- `AI/Debug/bugs/l1_causal_64k_checker3_ownership_20261030.md`
- `AI/Debug/bugs/l2_shadow_read_image_semantics_20261030.md`
- `AI/Debug/bugs/seq67_capture_identity_cap_20261101.md`
- `AI/Debug/bugs/seq67_priv_dispatch_trace_retire_combloop_20261031.md`
- `AI/Debug/references/opt5_cache_transfer_limits.md`
- `AI/Debug/references/opt5_load_opportunity_limits.md`
- `AI/Debug/references/opt5_preservation_outer_a_limits.md`
- `AI/Debug/references/remaining_slowdown_observer_schema.json`
- `AI/Debug/scripts/__pycache__/inspect_checker_seq67_evidence.cpython-310.pyc`
- `AI/Debug/scripts/analyze_checker_seq67_one_shot.py`
- `AI/Debug/scripts/analyze_l1_causal_pair.py`
- `AI/Debug/scripts/analyze_opt4_remaining.py`
- `AI/Debug/scripts/analyze_opt5_cache_transfer.py`
- `AI/Debug/scripts/analyze_opt5_preservation_outer_a.py`
- `AI/Debug/scripts/analyze_opt5_sub1p5_gap.py`
- `AI/Debug/scripts/audit_seq67_dispatch_dependencies.py`
- `AI/Debug/scripts/collect_l1_causal_provenance.py`
- `AI/Debug/scripts/finish_l1_causal_pair.py`
- `AI/Debug/scripts/implement_l1_causal.py`
- `AI/Debug/scripts/inspect_checker_seq67_evidence.py`
- `AI/Debug/scripts/l1_causal_status.py`
- `AI/Debug/scripts/launch_checker_seq67_baseline_refresh.py`
- `AI/Debug/scripts/launch_checker_seq67_one_shot.py`
- `AI/Debug/scripts/launch_opt5_sourcec.py`
- `AI/Debug/scripts/opt5_cache_transfer_reports.py`
- `AI/Debug/scripts/opt5_preservation_outer_a_reports.py`
- `AI/Debug/scripts/recover_seq67_capture.py`
- `AI/Debug/scripts/review_l1_causal_results.py`
- `AI/Debug/scripts/run_checker_seq67_baseline_refresh.sh`
- `AI/Debug/scripts/run_checker_seq67_one_shot.sh`
- `AI/Debug/scripts/run_opt5_sourcec.sh`
- `AI/Debug/scripts/seal_l1_causal.py`
- `AI/Debug/scripts/summarize_l1_causal_failure.py`
- `AI/Debug/scripts/test_checker_seq67_baseline_refresh.py`
- `AI/Debug/scripts/test_checker_seq67_one_shot.py`
- `AI/Debug/scripts/test_l1_causal.py`
- `AI/Debug/scripts/test_l1_causal_pair_analysis.py`
- `AI/Debug/scripts/test_opt4_remaining.py`
- `AI/Debug/scripts/test_opt5_cache_transfer.py`
- `AI/Debug/scripts/test_opt5_preservation_outer_a.py`
- `AI/Debug/scripts/test_opt5_sourcec.py`
- `AI/Debug/scripts/test_opt5_sub1p5_gap.py`
- `AI/Debug/scripts/test_seq67_capture_recovery.py`
- `AI/Debug/scripts/write_l1_causal_failed_report.py`
- `slowdown/optimization_5_pending_decision/README.md`

Classification and exact post-Opt4 restoration are recorded in experimental_patches/README.md and CLEANUP_PLAN.md.
