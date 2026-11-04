#!/usr/bin/env bash
set -euo pipefail
kit="$(cd -- "$(dirname -- "$0")/.." && pwd)"
# Read-only inspection + NEW report files. Exit 2 means formal readiness blocked.
exec python3 "$kit/dac.py" preflight "$@"
