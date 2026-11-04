#!/usr/bin/env bash
set -euo pipefail
kit="$(cd -- "$(dirname -- "$0")/.." && pwd)"
exec python3 "$kit/dac.py" analyze "$@"
