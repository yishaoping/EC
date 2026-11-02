# Code changes

Hardware delta relative to r2 is `one_shot_delta.patch` (new cumulative seal retains all
prior Opt4/L1 observer changes). Preimages and SHA256 manifest are preserved.

- RocketCore.scala: initialize privileged pending state, held current-trap/current-return
  dispatch exclusion; bounded SC46/47 input-only observation.
- R_ICSL.scala: capture real trap on nonchecking→privileged-entry edge.
- Existing launcher: sealed B-only contract guard and persist actual simulation argv.
  Default Opt4 guard and original strict paired analyzer are not weakened.
- seal_l1_causal.py: narrowly allow the two reviewed Rocket sources; optional one-shot
  contract hashes, and hash the new launcher/analyzers/offline tests.
- run_checker_seq67_one_shot.sh + launch_checker_seq67_one_shot.py: source the real env,
  verify inputs/proofs, claim exactly one B launch, call the existing launcher once,
  then offline postanalysis. No automatic retry, A, extra configuration or diagnostic run.
- inspect_checker_seq67_evidence.py: saved A/B first divergence and capture coverage audit.
- analyze_checker_seq67_one_shot.py: unchanged24 arm gates plus mandatory seq67 diagnostics,
  generated clocks/L2/config/native resource/actual argv checks; strict causal comparison
  gated by sealed noninterference proof. NO proof means explicit unpaired reference only.
- test_checker_seq67_one_shot.py: CPU protocol specification, bounded diagnostic parser,
  missing/dirty/out-of-order/CANCEL/lost-evidence cases and static-only no-launch guard.

No old seal, build, simulator, run log or old report result is overwritten. Separate
pointer `.checker_seq67_one_shot` does not move `.l1_causal_active` / `.l1_causal_revision`.

## Generation-blocker correction

RocketCore privileged_start_ready now consumes raw CSR r_exception instead of trace.exception. Added archived-FIR dependency audit plus three CPU regression tests for structural constant-comparison dependence, register boundaries and old/new loop behavior. See combloop_fix_delta.patch.
