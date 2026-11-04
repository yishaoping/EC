#!/usr/bin/env bash
set -euo pipefail
kit="$(cd -- "$(dirname -- "$0")/.." && pwd)"
# Full identity-valid completed samples are automatically skipped.
exec python3 "$kit/dac.py" run "$@"
