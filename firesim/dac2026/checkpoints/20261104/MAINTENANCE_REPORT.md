# Maintenance completion

| Item | Commit | Branch | Status |
|---|---|---|---|
| Candidate 2 hardware | `0d6ea4b9f468720a3fc7bee40dcb53a564ce9779` | `milestone/opt4-candidate2-parsec-20261104` | Reused; 23 inputs and six resources match evaluated bytes |
| Candidate 2 evidence / runner fix | `e939029dba420e4bcaa5052ccb402fb611ccb867` | Same milestone branch | Reused; full milestone tag added without moving old tags |
| FireSim/FPGA source checkpoint | `69f29e459588e6baad76f502d9b894ba6297b429` | `firesim/fpga-checkpoint-20261104` | 566 source/checkpoint files; seven nested commits in NESTED_COMMITS.json |
| FireSim experiment infrastructure | `c4a46bc92ba442a2c58db6560a54ddfca1f2f6d4` | Same FireSim branch | 599 recipes, patches, receipts and summaries |
| Historical PARSEC results | `8b18d40f0dade3e2f3b3f30106936395a627cc4a` | `opt4/final-eval-20261103` | 14 existing report/selection/repeatability files preserved |
| Git housekeeping | This commit | `firesim/fpga-checkpoint-20261104` | Scoped project ignores and audited local exclusions |
| Aggressive WIP | `1abba36059bf3b62208708d14fa2e9f18bf0765b` | `opt4/aggressive-perf-20261104` | Original source and preservation tag unchanged |

Candidate 2 remains a normal-execution/performance milestone; rollback restoration
is unproven. No aggressive RTL was mixed into it. Its 23 source files already
existed in Git, so no duplicate hardware commit was made. Both existing milestone
scripts were inspected and preserved. The existing hardware tag is unchanged;
`opt4-candidate2-parsec-20261104` now identifies the complete evidence checkpoint.

The parent source checkpoint has 566 tracked files. The seven independent
repository commits contain 34 source files and one updated BOOM gitlink.
The copied-tree snapshots contain 186 source overlays and 152 additional build
inputs; unchanged source comes from pinned Git objects. All 442,803 selected
source inputs across 17 trees passed identity verification. B v5 and C4 v6 source
restoration into new directories also passed. Eleven copied FPGA Verilog inputs
are preserved, including the same six resources independently tracked by C2.

Initial status was 1,276 entries in EC plus 14 in EC-opt4-perf, or 1,290 across
the seven EC worktrees. The final housekeeping commit stages all remaining three
ignore files and this report/verification record. No other EC worktree changes
remain. The final machine-readable status is stored in the external audit folder.

470 initially visible generated files remain on disk and are ignored. This includes
raw simulation evidence, guest binaries/images, large source inventories, runtime
logs and the two pinned dependency archives. Their exact paths and SHA256 values
are retained in INITIAL_FILE_CLASSIFICATION.json. An additional 38 untracked Scala
compiler-cache files in the B API-config submodule are locally excluded. No
preserved source or lightweight evidence file matches the new ignore rules.

The independently versioned Software/PARSEC reference remains dirty with exactly
its original 210 entries. This copied external reference is excluded only from
the EC parent status; it is not added as a new submodule. Its original complete
tracked binary diff is backed up outside EC, and the relevant modified FireSim
PARSEC source subset is committed in the source overlay. Editor state and large
input/output files remain local. No source, raw evidence or build artifact was
deleted. All 1,275 initially visible ordinary files/symlinks remain present; the
only edited one is the intended FireSim ignore file.

The aggressive build completed successfully and all four directed checks passed.
Its existing Streamcluster pilot subsequently ended on its own: the simulator
reported exit 0, but no ROI/output and validation FAILED; the runner returned 1
and the screen status became FAILED. Maintenance did not kill/restart any process,
modify that worktree, or rerun any benchmark. Its source hashes still match the
original 29 hardware/resource identities. The failure evidence remains in the
original run directory and the final status is copied into the audit folder.

The original baseline backup passed all 18,531 entries in its existing checksum
manifest. All old tags, main, recovery and aggressive branch refs are unchanged.
The historical evaluation branch received only the additive result commit.

Open the complete saved states in new worktrees:

```sh
git -C /data1/gzh/EC worktree add --detach /data1/gzh/EC-restore-candidate2 opt4-candidate2-parsec-20261104
git -C /data1/gzh/EC worktree add --detach /data1/gzh/EC-restore-firesim firesim/fpga-checkpoint-20261104
git -C /data1/gzh/EC worktree add --detach /data1/gzh/EC-restore-aggressive opt4-aggressive-wip-preserved-20261104
```

For individual nested repository commits and copied source restoration, follow
README.md and NESTED_COMMITS.json in this directory. The audit and backup bundles
are under `/data1/gzh/EC-backups/git-maintenance-20261104-continuation/`.
