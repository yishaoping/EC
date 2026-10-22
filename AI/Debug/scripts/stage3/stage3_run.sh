#!/usr/bin/env bash
# Sole public Stage3 entry; Python owns phase selection, resume and provenance.
set -euo pipefail
repo="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../../../.." && pwd)"
export PYTHONDONTWRITEBYTECODE=1
exec python3 -B "$repo/AI/Debug/scripts/stage3_validation.py" "$@"
