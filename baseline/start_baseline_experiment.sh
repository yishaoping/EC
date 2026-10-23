#!/usr/bin/env bash
# Manual entry point. Preparation used bash -n only; this file was not run.
# Shared software: --workload /absolute/common-build-directory/workload.json
# Its schema-2 descriptor binds ELF/loadmem SHA256 and final ROI symbols/PCs.
set -euo pipefail
[[ ! -L "$0" ]] || { echo 'Refusing a symlinked launcher' >&2; exit 2; }
baseline_dir=$(cd -P -- "$(dirname -- "$0")" && pwd)
[[ "$baseline_dir" == /data1/gzh/EC/baseline ]] || { echo 'Unexpected baseline directory' >&2; exit 2; }
exec /usr/bin/python3 -I -B "$baseline_dir/launch_baseline.py" "$baseline_dir" "$@"
