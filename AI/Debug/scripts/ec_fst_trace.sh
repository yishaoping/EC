#!/usr/bin/env bash
set -euo pipefail

usage() {
  printf 'Usage: %s FST START END [REGEX ...]\n' "$(basename "$0")" >&2
  printf 'Environment: EC_REPO_DIR, FST_TRACE_BIN, FST_TRACE_CACHE, GTKWAVE_INCLUDE_DIR\n' >&2
}

if [[ "${1:-}" == "--help" ]]; then
  usage
  exit 0
fi
if [[ $# -lt 3 ]]; then
  usage
  exit 2
fi

fst_file=$1
start_time=$2
end_time=$3
shift 3
script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

if [[ ! -r "$fst_file" ]]; then
  printf 'cannot read FST/VCD file: %s\n' "$fst_file" >&2
  exit 2
fi

repo_root=${EC_REPO_DIR:-$(cd "$script_dir/../../.." && pwd)}
source_file=${EC_FST_TRACE_SOURCE:-$script_dir/fst_signal_trace.c}
[[ -d "$repo_root/chipyard" ]] || { printf 'not an EC repository: %s\n' "$repo_root" >&2; exit 2; }

trace_bin=${FST_TRACE_BIN:-}
if [[ -z "$trace_bin" || ! -x "$trace_bin" ]]; then
  [[ -r "$source_file" ]] || { printf 'missing FST reader source: %s\n' "$source_file" >&2; exit 2; }
  gtkwave_dir=${GTKWAVE_INCLUDE_DIR:-/usr/local/share/verilator/include/gtkwave}
  for dep in cc "$gtkwave_dir/fstapi.c" "$gtkwave_dir/fastlz.c" "$gtkwave_dir/lz4.c"; do
    if [[ "$dep" == cc ]]; then
      command -v cc >/dev/null || { printf 'missing compiler: cc\n' >&2; exit 2; }
    elif [[ ! -r "$dep" ]]; then
      printf 'missing FST dependency: %s\n' "$dep" >&2
      exit 2
    fi
  done
  cache_dir=${FST_TRACE_CACHE:-$repo_root/AI/TMP/tools/fst-reader}
  mkdir -p "$cache_dir"
  trace_bin=$cache_dir/fst_signal_trace
  if [[ ! -x "$trace_bin" || "$source_file" -nt "$trace_bin" ]]; then
    tmp_bin="$trace_bin.$$"
    cc -O2 -DFST_CONFIG_INCLUDE='"fst_config.h"' \
      -I"$gtkwave_dir" "$source_file" \
      "$gtkwave_dir/fstapi.c" "$gtkwave_dir/fastlz.c" "$gtkwave_dir/lz4.c" \
      -lz -o "$tmp_bin"
    mv "$tmp_bin" "$trace_bin"
  fi
fi

exec "$trace_bin" "$fst_file" "$start_time" "$end_time" "$@"
