# Post-Opt4 experimental changes — preserved, not active

Base: **476a760910f3bfbd3c111000ebe40343870ab439** (`opt4: sync SVB16 implementation and validation tools`).
No independent Opt5 commit/branch existed. These patches are actual working-tree git
diffs (the pre-SourceC intermediate uses git no-index), not hand-reconstructed designs.
All16 hardware/host file bytes and modes replayed successfully in a private Git index;
the real index was unchanged. See [replay evidence](../cleanup_evidence/patch_replay_validation.json).

|Patch|Purpose and validation|Why excluded from Opt4|
|---|---|---|
|[other_post_opt4_changes.patch](other_post_opt4_changes.patch)|Remaining/causal counters, L2 snapshot/native cache observation, paired host launch/capture/analysis. Type/offline checks; B dynamic evidence in archived reports.|Post-Opt4 measurement infrastructure; not the frozen measured source.|
|[l1_64k_probe.patch](l1_64k_probe.patch)|Adds32K/64K paired config classes;64K B completed with recovered correctness. Strict A/new-B pairing still pending.|Capacity reference signal, not accepted final Opt5 or stable Opt4.|
|[checker_seq67_fix.patch](checker_seq67_fix.patch)|Real trap/privileged CPS dispatch/return fix plus bounded46/47 diagnostics; B closes320 packages. See checker_seq67 reports.|Discovered after Opt4 under the L1 experiment; do not silently backport function/diagnostics.|
|[sourcec_experiment.patch](sourcec_experiment.patch)|Pure-waitAck SourceC bypass, target set locked until ACK, SC48. Type check and14 CPU witnesses only; no hardware run.|Runtime correctness/performance unvalidated; optimization now PAUSED.|
|[all_post_opt4_changes.patch](all_post_opt4_changes.patch)|Single complete delta for all16 dirty hardware/host files relative to stable source commit.|Alternative to the four ordered patches; do not apply both.|

## Future recovery (requires explicit optimization resumption)

Read ../RESUME_OPTIMIZATION.md first. Keep current Opt4 working tree intact.
Use the exact base commit in a separate branch/worktree, then apply **either** the
complete delta **or** the four ordered patches above (table order). Run `git apply
--check` before application. The archived AI scripts and exact original host files
are retained in this archive commit under their compatible AI/ paths, and the
pre-cleanup byte snapshot is under ../cleanup_evidence/pre_cleanup_files/.
A worktree at the old base needs those untracked-at-the-time AI scripts copied from
the archive commit before using old tools. Hardware guards must match the historical
seals; do not weaken them or merely refresh hashes. Old scripts hardcode /data1/gzh/EC,
so adapt/verify paths deliberately before any future execution in a different worktree.
Do not execute archived hardware launch commands while optimization is paused.

The current stable analyzer retains only the proven host-side separation of L2 shadow
fidelity from closed functional/integrity correctness. Stable launcher uses a versioned
copy of its existing guard patch. To recover the exact historical experimental tool
bytes, use the old base + patches, not a blind apply over the new stable host tools.

Original reports/seals/claims/raw capture FAIL/recovered results remain at recorded
AI/TMP paths; no log/build/waveform was removed. Patch SHA256s are in replay evidence.
