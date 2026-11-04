#!/usr/bin/env bash
set -euo pipefail
kit="$(cd -- "$(dirname -- "$0")/.." && pwd)"
# Requires --campaign, --config; add --execute ONLY for a manual recovery run.
exec python3 "$kit/dac.py" run --interrupt-after 1 "$@"
