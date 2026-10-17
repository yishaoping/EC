#!/usr/bin/env bash
# Verify-only launcher: one simulator invocation, no regeneration or retries.
set -euo pipefail
if [[ $# -ne 0 ]]; then
  echo "Stage 1 accepts configuration through documented STAGE1_* variables only" >&2
  exit 2
fi
repo=/data1/gzh/EC
chipyard="$repo/chipyard"
: "${STAGE1_SIM:?use stage1_build_and_run.sh or provide an attested simulator}"
: "${STAGE1_GENERATED:?generated model path required}"
: "${STAGE1_PROVENANCE:?build provenance required}"
workload="${STAGE1_WORKLOAD:-$repo/AI/TMP/stage1_workload.json}"
python3 "$repo/AI/Debug/scripts/stage1_workload.py" --manifest "$workload"
python3 "$repo/AI/Debug/scripts/stage1_provenance.py" --root "$chipyard" --sim "$STAGE1_SIM" --generated "$STAGE1_GENERATED" --manifest "$STAGE1_PROVENANCE"
[[ -x "$STAGE1_SIM" ]]
if [[ -n "${STAGE1_RUN_ROOT:-}" ]]; then
  run_root="$STAGE1_RUN_ROOT"
  mkdir "$run_root"
else
  run_root=$(mktemp -d "$repo/AI/TMP/stage1_closure_run_XXXXXXXX")
fi
run_root=$(cd -- "$run_root" && pwd)
benchmark=$(python3 -c 'import json,sys; print(json.load(open(sys.argv[1]))["benchmark"])' "$workload")
loadmem=$(python3 -c 'import json,sys; print(json.load(open(sys.argv[1]))["loadmem"])' "$workload")
cp "$STAGE1_PROVENANCE" "$run_root/provenance.json"
cp "$workload" "$run_root/workload.json"
cp "$repo/AI/Debug/scripts/stage1_trace_scoreboard.py" "$run_root/stage1_trace_scoreboard.py"
# Emulator options precede all HTIF/Verilog arguments: the emulator stops
# parsing its own options when it encounters a recognized HTIF argument.
args=()
if [[ "${STAGE1_WAVEFORM:-1}" == 1 ]]; then
  args+=("-v" "$run_root/trace.fst")
fi
args+=(+verbose +permissive +dramsim
  +dramsim_ini_dir="$chipyard/generators/testchipip/src/main/resources/dramsim2_ini"
  +max-cycles=500000000 +loadmem="$loadmem" +loadmem_addr=80000000 +permissive-off)
python3 - "$run_root" "$STAGE1_SIM" "${args[@]}" "$benchmark" <<'PY'
import hashlib, json, os, sys
from pathlib import Path
root = Path(sys.argv[1])
files = ['provenance.json', 'workload.json', 'stage1_trace_scoreboard.py']
record = dict(schema=1, run_directory=str(root.resolve()), argv=sys.argv[2:],
              waveform=str(root/'trace.fst') if '-v' in sys.argv else None,
              environment={k: os.environ.get(k) for k in ('LD_LIBRARY_PATH', 'PATH', 'VERILATOR_ROOT')},
              input_sha256={p: hashlib.sha256((root/p).read_bytes()).hexdigest() for p in files})
(root/'run.json').write_text(json.dumps(record, indent=2)+'\n')
PY
printf 'STAGE1_RUN_ROOT=%s\nFST_PATH=%s\nTRACE_PATH=%s\n' "$run_root" "$run_root/trace.fst" "$run_root/trace.log"
set +e
(cd "$run_root" && "$STAGE1_SIM" "${args[@]}" "$benchmark" </dev/null) >"$run_root/trace.log" 2>&1
sim_rc=$?
printf 'SIMULATOR_EXIT_CODE=%s\n' "$sim_rc" | tee "$run_root/simulator.status"
# Analyze failed/partial runs too, and preserve JSON + concise summary.
python3 "$run_root/stage1_trace_scoreboard.py" "$run_root/trace.log" --workload "$run_root/workload.json" --json "$run_root/scoreboard.json" >"$run_root/scoreboard.out" 2>&1
score_rc=$?
set -e
cat "$run_root/scoreboard.out"
[[ "$sim_rc" == 0 ]] || exit "$sim_rc"
exit "$score_rc"
