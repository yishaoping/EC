#!/usr/bin/env bash
# One Opt5 SourceC experiment, reusing B64K; no retry or sweep.
set -eo pipefail
cd "$(dirname "${BASH_SOURCE[0]}")/../../.."
source chipyard/env.sh
exec python3 -I -B AI/Debug/scripts/launch_opt5_sourcec.py "$@"
