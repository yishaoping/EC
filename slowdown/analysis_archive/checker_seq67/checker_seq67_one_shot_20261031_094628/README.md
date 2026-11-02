# Checker seq67 one-shot — command ready

ROOT_CAUSE = MOST_LIKELY_WITH_BOUNDED_RUNTIME_CONFIRMATION
FIX_READY = YES (source/type/offline; dynamic validation pending)
A_NON_INTERFERENCE_PROVEN = NO
NUMBER_OF_FULL_RUNS_REQUESTED = 1
RUN_TARGET = B_ONLY_64K_2WAY

A trap/privileged-dispatch race is repaired with held dispatch priority and entry-edge
trap capture. Cleanup/result/watchdog guards are preserved. B diagnostics accompany the
same fix, with ≤832 new bounded records. The old A remains correctness-valid, but its
701 host-dropped SC6 rows prevent a complete noninterference proof. No A is scheduled.

```bash
bash AI/Debug/scripts/run_checker_seq67_one_shot.sh --report AI/TMP/checker_seq67_one_shot_20261031_094628 --jobs 4
```

Start with seq67_first_divergence.md, cleanup_root_cause.md, fix_design.md and
one_shot_run_plan.md. Evidence hashes/preimages and old RTL excerpts are retained.
validation_result.json distinguishes type/offline PASS from unexecuted hardware phases.
After the user command, one_shot_result.json and runtime_validation.json hold combined
results; reference_comparison.json is explicitly unpaired until noninterference is proved.

No hardware generation/build/benchmark was executed by the agent in this turn.
