# Resume optimization only after an explicit decision

Stable version: **Opt4**

Slowdown: **~1.7x (1.7050071)**

Optimization status: **paused**

First read ../OPT4_BASELINE.md and OPTIMIZATION_HISTORY.md. Use the stable frozen
source for current DAC experiments; do not execute historical READY/one-shot commands.
Current stable source commit476a760910f3bfbd3c111000ebe40343870ab439;
current archive commit preserves the exact post-Opt4 scripts, patches and small reports.

## Deprioritized or excluded as a main direction

- SVB32/capacity expansion: remaining_slowdown/; local full-episode bound5,254.
- Promotion-only: remaining_slowdown/; safe→terminal union24,569 is not critical gain.
- Pure MSHR-capacity hypothesis: l1_capacity/ and load_critical_path/; do not expand MSHRs without new cause evidence.
- OuterA packet-lock-through-ACK: preservation_outerA/; refuted. Intrinsic-gap-only bound34,104 is scoped and insufficient.
- Direct load-path-only sub1.5: load_critical_path/; scoped53,845/80,832 envelopes do not establish sufficient savings.

## Not fully closed

- SourceC reservation→victim Release/ReleaseAck→Acquire HOL: sourcec_hol/. Static PROVEN;
  runtime benefit UNKNOWN. Two-file waitAck bypass prepared but not dynamically validated.
- Cache-transfer serialization: cache_transfer/ and preservation_outerA/. Exposure is
  not saving; checkpoint/critical-request join incomplete.
- L1 capacity/retry amplification: l1_capacity/.64KiB B1,648,923 reference signal;
  strict A/new-B pairing pending. Do not promote64KiB to finalOpt5.
- BOOM/checker backpressure and scheduler availability: remaining_slowdown/; no
  unique critical-cycle allocation established.
- Checker frontend: LAST_RESORT; require package completion→result→BOOM critical
  progress evidence, not frontend stall totals alone.

## Recover exact experimental source without repeating analysis

1. Read experimental_patches/README.md and cleanup_evidence/patch_replay_validation.json.
2. Protect the stable branch; use a separate branch/worktree from476a76091. Restore
   either all_post_opt4_changes.patch or the four ordered patches, never both.
3. Recover the original AI/Debug script bytes from this archive commit or the
   pre_cleanup_files snapshots. Reproduce exact source/tool/software identities;
   old seals intentionally fail against frozen Opt4. Hardcoded root paths require review.
4. Read checker_seq67/ before using paired geometry results; retain original capture
   FAIL and lossless corrected B result. Do not silently relax ownership/capture gates.
5. SourceC one-shot was unconsumed at pause. After explicit resume, revalidate its
   complete source seal and all offline checks before considering its historical command.
   One future formal run at most: <50k saving stops SourceC;50k–100k moderate;
   ≥100k strong; ROI<1,502,513 sub1.5, with all correctness gates first. No observation-only
   run or second SourceC micro-tuning experiment was authorized by that plan.

No elaboration, build, benchmark, remote operation or performance work is part of
this freeze. Original heavy artifacts remain in place; archive_inventory.json and
opt4/frozen_manifest.json identify the evidence needed to restart.
