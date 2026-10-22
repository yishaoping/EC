#!/usr/bin/env bash
# EXPLICIT expensive entry point: one fresh debug build, one simulator process.
set -euo pipefail
if [[ $# -ne 0 ]]; then
  echo "Stage 1 accepts configuration through documented STAGE1_* variables only" >&2
  exit 2
fi
for name in STAGE1_BUILD_ROOT STAGE1_SIM STAGE1_GENERATED STAGE1_PROVENANCE; do
  if [[ -v "$name" ]]; then
    printf 'Unsupported build-wrapper override: %s; use STAGE1_SIM_ROOT for a fresh build directory\n' "$name" >&2
    exit 2
  fi
done
repo=/data1/gzh/EC
chipyard="$repo/chipyard"
workload="${STAGE1_WORKLOAD:-$repo/AI/TMP/stage1_workload.json}"
python3 "$repo/AI/Debug/scripts/stage1_workload.py" --manifest "$workload"
mkdir -p "$repo/AI/TMP"
if [[ -n "${STAGE1_SIM_ROOT:-}" ]]; then
  sim_root="$STAGE1_SIM_ROOT"
  # Never relabel an incremental/stale build as newly built evidence.
  mkdir "$sim_root"
else
  sim_root=$(mktemp -d "$repo/AI/TMP/stage1_closure_build_XXXXXXXX")
fi
sim_root=$(cd -- "$sim_root" && pwd)
build_root="$sim_root/generated-src/chipyard.TestHarness.v1Config"
sim="$sim_root/simulator-chipyard-v1Config-debug"
generated="$build_root/chipyard.TestHarness.v1Config.debug"
manifest="$sim_root/provenance.json"
ln -s "$chipyard/sims/verilator/Makefile" "$sim_root/Makefile"
python3 "$repo/AI/Debug/scripts/stage1_provenance.py" --root "$chipyard" --manifest "$sim_root/source.before.json" --capture-source
printf 'STAGE1_BUILD_ROOT=%s\n' "$sim_root"
make -C "$sim_root" -f "$chipyard/sims/verilator/Makefile" \
  base_dir="$chipyard" sim_dir="$sim_root" build_dir="$build_root" \
  CONFIG=v1Config VERILATOR_FST_MODE=1 EXTRA_SIM_CXXFLAGS=-DSTAGE1_EXIT_PORTS debug \
  2>&1 | tee "$sim_root/build.log"
python3 "$repo/AI/Debug/scripts/stage1_provenance.py" --root "$chipyard" --sim "$sim" --generated "$generated" --manifest "$manifest" --source-snapshot "$sim_root/source.before.json" --write
if [[ "${STAGE1_BUILD_ONLY:-0}" == 1 ]]; then
  printf 'STAGE1_BUILD=PASS\nSTAGE1_SIMULATION=NOT_RUN_BUILD_ONLY\n'
  exit 0
fi
STAGE1_SIM="$sim" STAGE1_GENERATED="$generated" STAGE1_PROVENANCE="$manifest" \
STAGE1_WORKLOAD="$workload" exec "$repo/AI/Debug/scripts/stage1_run_trace.sh" "$@"
