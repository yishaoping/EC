# 528000 fix implementation verification

- Scala compile: `project rocketchip` with the directed generator source; success.
- Full `make verilog CONFIG=v1Config` into `generated` and `generated-final`; FIRRTL/firtool lowering success, 1060 collateral files, no loop/error.
- Verilator lint: generated R_IC, R_ICSL and GHM; success.
- Directed R_IC: 13 cases, including 558+42 ordinary/privileged barrier, no free checker, threshold, mode return, true exit, early release, and exit-after-allocation/zero count; all pass.
- Directed R_ICSL: ordinary/privileged 558->600, zero count, instruction-tail and trap hold; all pass.
- Directed GHM: ordered END, data backpressure, zero anchor, per-slot seal, count CDC backpressure, cancellation/reuse with stale END; all pass.
- `git diff --check -- chipyard/generators`: pass.
- `audit_diff.py`: task-only diff and preservation of pre-existing unrelated changes; pass.

The original 528000 workload has not been rerun. Full runtime proof of BOOM/LSU/cache/barrier interaction remains required.
