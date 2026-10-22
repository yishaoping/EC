#!/usr/bin/env bash
# offline is hardware-free. build generates/compiles RTL but never simulates.
# directed/system execute one simulator each, only after matching prior PASS.
# all owns a fresh unique AI/TMP root; invoke by absolute path from any cwd.
# all runs build -> directed -> system; offline tests are an explicit option.
# Source/fixture/tool/environment/parameter snapshots remain mandatory.
set -euo pipefail
repo=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../../.." && pwd)
if [[ $# == 0 ]]; then set -- all; fi
exec python3 -B "$repo/AI/Debug/scripts/stage2_validation.py" "$@"
