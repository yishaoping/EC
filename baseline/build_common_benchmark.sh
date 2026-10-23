#!/usr/bin/env bash
# Prepared only. This script intentionally compiles software when invoked later.
set -euo pipefail
[[ ! -L "$0" ]] || { echo 'Refusing a symlinked builder' >&2; exit 2; }
common_root=$(cd -P -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
[[ "$common_root" == /data1/gzh/EC/baseline ]] || exit 2
exec /usr/bin/python3 -I -B "$common_root/prepare_common_build.py" "$@"
