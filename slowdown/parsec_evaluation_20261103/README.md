# Current evaluation status

The previous frozen model had a Streamcluster DCache ownership race. The accepted repair is hardware commit `a6e63c75947739dfbb411b32bfe0eb5ed55c5bb1`, tagged `opt4-final-corrected-r2-20261103`. The earlier candidate `19d19360a` failed startup because its epoch barrier treated the default-high observer reset as active ownership and is excluded. The old canonical tag is preserved as historical evidence. See [STREAMCLUSTER_CORRECTNESS.md](STREAMCLUSTER_CORRECTNESS.md).

# Corrected Opt4 PARSEC evaluation

Historical hardware (superseded by the Streamcluster finding):1532923803d7451b0c7843e9abad1c90ef9eb9ed
(hardware delta last changed at83dec9d4c10ab8c097fe5ab5c8af1c0a270fba6d).
Accepted final hardware: a6e63c75947739dfbb411b32bfe0eb5ed55c5bb1.
Branch:opt4/final-eval-20261103; annotated tag:opt4-final-corrected-r2-20261103.
Old opt4-final-bfs-20261103 remains historical pre-fix evidence, not final hardware.

Evaluation is in the private EC-opt4-perf worktree. Main/FPGA and canonical check
sources are read-only. No performance RTL changes are planned. Reuse sealed
correction and matched detection simulators; use only fresh private run paths.

Phases: freeze/config identity; supported-workload discovery; three-workload
pilot and feasibility checks; expand supported cases; repeat deterministic
cases; summarize raw measurements. Recovery validation is a separate directed
suite and must not be included in normal performance means.

The r2 candidate passed BFS, Blackscholes, Streamcluster, Canneal, and emitted
epoch-controller acceptance gates. All three simdev pilot triplets are
work-equivalent and pass correctness/protocol accounting. Current phase:
project64/project400 Native, Check, and Correction characterization. No primary
large-input results or geometric means are claimed until all selected triplets
pass their equivalence and correctness gates.
