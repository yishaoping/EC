# Opt4 freeze and workspace cleanup — 2026-11-02

CURRENT_STABLE_OPT = Opt4; OPTIMIZATION_STATUS = PAUSED.
No hardware generation, build or benchmark run. No remote operation.

|Class|Scope|Action|
|---|---|---|
|KEEP|Opt4 functional RTL at476a760910f3bfbd3c111000ebe40343870ab439; pinned software; all manifests, raw performance/correctness data, waveforms and source seals|Keep original paths and content. Hash-check measured hardware.|
|KEEP|slowdown/optimization_4_svb and existing launch paths|Keep structure. Use versioned Opt4 patch guard; retain proven host-only correctness/shadow separation. Remove paired experimental launch mode.|
|ARCHIVE|13 dirty hardware/resource files plus3 host tools afterOpt4|Save actual diffs and exact pre-cleanup file bytes, verify patch replay, then restore Opt4 hardware. Save seq67, L1 config, SourceC and other changes separately.|
|ARCHIVE|Opt5 reports, analysis and scripts|Commit small report copies/indexes under analysis_archive, retain AI originals and every sealed run/build path; existing scripts remain at compatible AI paths, now historical.|
|ARCHIVE|root dramsim.log and chipyard/sims/verilator/dramsim.log|No unique run identity; relocate unchanged into unclassified_logs with hash/mtime/reason. Already run-scoped logs remain in place.|
|DELETE|46 inventoried untracked/ignored *.pyc files (604542bytes at initial inventory)|Delete only after source/identity review. Reproducible Python caches; no research data. Remove their empty __pycache__ directories.|
|UNKNOWN|All existing heavyweight build/dependency caches, temporary directories and older runtime artifacts|Retain; do not infer uselessness from age or size. No broad directory cleanup.|

## Execution order

Git status/diff/index inspection → preserve sources/patches and report copies →
verify forward reconstruction → restore only enumerated experimental hardware/tools →
freeze Opt4 identity and document stable offline recertification → relocate unclassified
logs → remove enumerated bytecode → CPU/shell/path/hash tests → explicit staged diff
review → local commit(s) → git status. No reset --hard / git clean / blanket checkout.

Stable Opt4 source commit already exists. A freeze commit is needed only for necessary
host-only analysis/reproduction metadata; a separate archive commit records organization.
No artificial functional RTL commit is introduced. No tags exist in this repository;
do not introduce a release tag convention. Do not push.

Deletion and log manifests in analysis_archive/cleanup_evidence record exact actions.
All unspecified files remain. Important runtime paths stay compatible; archived
historical launch commands are superseded by PAUSED and must not be executed now.
