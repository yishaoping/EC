#!/usr/bin/env bash
# Software-only compilation and ELF-to-loadmem conversion. No make/simulator.
set -euo pipefail
repo=/data1/gzh/EC
manifest="${STAGE1_WORKLOAD:-$repo/AI/TMP/stage1_workload.json}"
mkdir -p "$repo/AI/TMP" "$(dirname "$manifest")"
workload_dir=$(mktemp -d "$repo/AI/TMP/stage1_workload_XXXXXXXX")
python3 "$repo/AI/Debug/scripts/stage1_workload.py" --manifest "$manifest" --capture-source "$workload_dir/source.before.json"
TEST_OUTPUT_DIR="$workload_dir" bash "$repo/Software/Test/compile.sh" >"$workload_dir/software-build.log" 2>&1
python3 "$repo/AI/Debug/scripts/stage1_workload.py" --manifest "$manifest" --prepare "$workload_dir" --source-snapshot "$workload_dir/source.before.json"
