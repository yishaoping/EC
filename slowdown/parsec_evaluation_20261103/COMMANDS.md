# Reproduction commands

Work only in `/data1/gzh/EC-opt4-perf`, branch `opt4/final-eval-20261103`.
The canonical hardware tag is `opt4-final-corrected-20261103`. Main project and
historical detection sources remain read-only. Build and run directories are
fresh and never reused; select a new name or preserve a prior directory before
rebuilding. Do not execute historical FireSim image scripts.

```sh
cd /data1/gzh/EC-opt4-perf
python3 slowdown/parsec_evaluation_20261103/scripts/build_pilot.py blackscholes simdev
python3 slowdown/parsec_evaluation_20261103/scripts/build_pilot.py streamcluster simdev
python3 slowdown/parsec_evaluation_20261103/scripts/build_pilot.py canneal simdev
python3 slowdown/parsec_evaluation_20261103/scripts/host_reference.py blackscholes_simdev
python3 slowdown/parsec_evaluation_20261103/scripts/host_reference.py streamcluster_simdev
python3 slowdown/parsec_evaluation_20261103/scripts/host_reference.py canneal_simdev
```

Commit evaluation script/document changes before launch. The launcher checks that
the evaluation worktree is clean, verifies existing hardware and model hashes,
and records the exact model command in every `run_manifest.json` and `command.sh`.

```sh
python3 slowdown/parsec_evaluation_20261103/scripts/run_pilot.py blackscholes_simdev native --max-cycles 5000000
python3 slowdown/parsec_evaluation_20261103/scripts/run_pilot.py blackscholes_simdev check --max-cycles 5000000
python3 slowdown/parsec_evaluation_20261103/scripts/run_pilot.py blackscholes_simdev correction --max-cycles 5000000
```

Use the same launcher with the other supported workload names and a recorded
finite cycle bound. Native uses its one-word mode variant; check and correction
use an identical ELF. Bounded startup diagnostics are excluded from performance.
The first C++ pilot binaries exposed misaligned HTIF boot synchronization and were
preserved and excluded. The corrected builder aligns all C++ BSS input sections
to 64 bytes and checks boot-sync/timer alignment before permitting a run.

After normal completion, pass its fresh directory to analysis:

```sh
python3 slowdown/parsec_evaluation_20261103/scripts/analyze_pilot.py slowdown/parsec_evaluation_20261103/runs/RUN_ID
python3 slowdown/parsec_evaluation_20261103/scripts/summarize.py
python3 slowdown/parsec_evaluation_20261103/scripts/seal_runs.py
```

`primary_selection.json` records exactly which triplets enter the primary table.
The summarizer rejects instruction/output/input/ELF mismatches and unclean launch
checkpoints. The raw sealer uses exclusive creation, verifies identical reexports,
compresses without changing original logs, and retains the source/software manifests.
Raw run commands are the authoritative exact simulator invocations.

The recovery component suite compiles only the existing frozen emitted SVB:

```sh
python3 slowdown/parsec_evaluation_20261103/scripts/run_recovery_component.py
```

It never regenerates hardware and does not prove integrated rollback. See
`recovery/README.md` for the remaining fault-injection plan and observed limitations.
