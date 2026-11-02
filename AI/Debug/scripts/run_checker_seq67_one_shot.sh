#!/usr/bin/env bash
# User-run entry point. No clean, A run, retry, or diagnostic-only benchmark.
set -eo pipefail
cd "$(dirname "${BASH_SOURCE[0]}")/../../.."
source chipyard/env.sh
exec python3 -I -B AI/Debug/scripts/launch_checker_seq67_one_shot.py "$@"
