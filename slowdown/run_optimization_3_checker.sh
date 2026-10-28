#!/usr/bin/env bash
set -euo pipefail
slowdown_dir=$(cd -- "$(dirname -- "$0")" && pwd -P)
exec /usr/bin/python3 -I -B "$slowdown_dir/optimization_3_checker/scripts/launch_optimization_3_checker.py" "$@"
