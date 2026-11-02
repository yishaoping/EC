#!/usr/bin/env bash
# User-only A-prime; no B, retry, cleanup or geometry sweep.
set -eo pipefail
cd "$(dirname "${BASH_SOURCE[0]}")/../../.."
source chipyard/env.sh
exec python3 -I -B AI/Debug/scripts/launch_checker_seq67_baseline_refresh.py "$@"
