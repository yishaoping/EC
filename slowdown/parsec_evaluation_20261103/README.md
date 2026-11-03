# Current evaluation status

Streamcluster exposed a second correctness defect in the previous frozen model. The explicit candidate repair is hardware commit `19d19360a`; build and mandatory regressions are pending. The old canonical tag is preserved as historical evidence. No complete accepted primary triplet or geometric mean is available yet. See [STREAMCLUSTER_CORRECTNESS.md](STREAMCLUSTER_CORRECTNESS.md).

# Corrected Opt4 PARSEC evaluation

Canonical final hardware:1532923803d7451b0c7843e9abad1c90ef9eb9ed
(hardware delta last changed at83dec9d4c10ab8c097fe5ab5c8af1c0a270fba6d).
Branch:opt4/final-eval-20261103; annotated tag:opt4-final-corrected-20261103.
Old opt4-final-bfs-20261103 remains historical pre-fix evidence, not final hardware.

Evaluation is in the private EC-opt4-perf worktree. Main/FPGA and canonical check
sources are read-only. No performance RTL changes are planned. Reuse sealed
correction and matched detection simulators; use only fresh private run paths.

Phases: freeze/config identity; supported-workload discovery; three-workload
pilot and feasibility checks; expand supported cases; repeat deterministic
cases; summarize raw measurements. Recovery validation is a separate directed
suite and must not be included in normal performance means.

Current phase: support discovery and workload adaptation. No suite results or
geometric means are claimed until complete valid comparable runs exist.
