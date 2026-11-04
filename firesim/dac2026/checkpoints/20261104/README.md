# FireSim / FPGA development checkpoint — 2026-11-04

This is a development checkpoint, not a validated FPGA release. It preserves the
existing B and C4 work, including incomplete Linux/checker integration and the
separate diagnostic36 variants. It does not change functional source bytes,
launch builds or benchmarks, or operate an FPGA.

The EC branch `firesim/fpga-checkpoint-20261104` is based on
`2ea467ba08f773dd55b77383da9f4f5c025b9607`. Candidate 2 remains separate on
`milestone/opt4-candidate2-parsec-20261104`, with hardware tag
`opt4-candidate2-hardware-20261104` and complete evidence tag
`opt4-candidate2-parsec-20261104`. Its rollback restoration remains unproven.

## Source preservation

`NESTED_COMMITS.json` records seven new commits in the five independent FireSim
repositories and the B baseline Chipyard/BOOM repositories. Those commits change
only Git history and the index; the original working source bytes are unchanged.
Existing upstream branches and tags have not been moved. Historical build receipts
still name the original upstream commit: these are historical observations and
have not been relabeled as builds of the new commits.

`manifests/` and `overlays/` preserve 17 source trees: seven Chipyard variants,
nine Linux/OpenSBI/BusyBox trees, and the modified PARSEC build source subset.
Each manifest combines pinned Git base trees with exact source overlays, records
file modes and a complete source identity, and explicitly identifies omitted build
products. Restored trees contain source inputs; environments, generated RTL,
binaries and run outputs are retained at their original disk locations.
The C4 v6 overlay includes all eleven copied Verilog resource inputs. The six
Candidate 2 resources remain independently tracked at its hardware milestone.

`WORK_INPUTS.json` and `work-inputs/` preserve additional kernel/BusyBox `.config`
files, linker scripts, device trees, candidate configurations and compile scripts
that were inside otherwise ignored build directories. `DEPENDENCY_ARCHIVES.json`
pins the two upstream repair archives by URL and SHA256; the repaired source bytes
are also preserved, so those archives need not be added as large Git binaries.
Board definitions and their license are tracked under `deps/boards/`.

Verify committed source identities and overlays without simulation:

```sh
python3 firesim/dac2026/checkpoints/20261104/restore_sources.py
```

Also check every preserved local source file against its original identity:

```sh
python3 firesim/dac2026/checkpoints/20261104/restore_sources.py --verify-current
```

Restore a source tree into a new directory (the destination must not exist):

```sh
python3 firesim/dac2026/checkpoints/20261104/restore_sources.py \
  --restore opt4-linux-v6-c4 --destination /path/to/new-c4-source
```

Labels are listed in `SOURCE_SNAPSHOTS.json`. The helper reads the pinned local
Git repositories; use `--repo-map OLD=NEW` when relocating a dependency. Independent
repository commits can also be opened directly using
`git -C REPOSITORY worktree add --detach NEW_DIRECTORY COMMIT` with values from
`NESTED_COMMITS.json`. Backup bundles are retained under
`/data1/gzh/EC-backups/git-maintenance-20261104-continuation/nested/`.

## Evidence and local files

`INITIAL_FILE_CLASSIFICATION.json` classifies and hashes every initially visible
untracked file. Source, scripts, patches and lightweight receipts/summaries are
committed separately from housekeeping. Large source inventories, raw logs,
waveforms, initramfs/loadmem images and dependency archives remain on disk and
are suppressed using scoped ignore rules or exact machine-local exclude entries.
No logs, images, input files or build intermediates are deleted.

`Software/PARSEC` is an independently versioned copy of an external reference,
with pre-existing editor state, software edits and input files. It remains
unchanged. Its relevant modified FireSim build source is preserved by the PARSEC
overlay. Its original status and complete tracked binary patch are backed up
outside the EC worktree; its remaining dirty state is not a new EC submodule.

The active aggressive Opt4 worktree, commit and tag remain unchanged. Its source,
configuration, build directory and running screen/Streamcluster processes are
outside this checkpoint. The original baseline backup was verified against all
18,531 entries in its existing SHA256SUMS.json without changing the backup.
