# seq67 one-shot — generation-blocker correction ready

The parent's user-run RTL generation failed because trace.exception fed retire/wb_valid
back into check_exception. The corrected gate uses existing raw CSR r_exception with
no added delay. Old claim/seal/build/logs remain immutable; no benchmark had started.

```bash
bash AI/Debug/scripts/run_checker_seq67_one_shot.sh --report AI/TMP/checker_seq67_one_shot_20261031_103130 --jobs 4
```

Only the user runs hardware generation/build/benchmark. This report requests the same
single B64KiB/2way, not a second benchmark. A noninterference remains unproven; no A is
scheduled. See combloop_root_cause.md, dispatch_dependency_audit.json, fix_design.md,
validation_result.json and one_shot_run_plan.md. Old A correctness remains valid.
