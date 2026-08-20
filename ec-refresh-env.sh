#!/usr/bin/env bash

# Generate the small runtime export cache consumed by ec-env.sh.
set -euo pipefail

if [ -n "${BASH_SOURCE[0]:-}" ]; then
    ec_refresh_source="${BASH_SOURCE[0]}"
else
    ec_refresh_source="$0"
fi
EC_ROOT="$(cd "$(dirname "$ec_refresh_source")" && pwd)"
ec_cache_dir="${XDG_CACHE_HOME:-$HOME/.cache}/ec-env"
ec_cache="$ec_cache_dir/runtime.env"
mkdir -p "$ec_cache_dir"
ec_tmp="$(mktemp "$ec_cache.XXXXXX")"
trap 'rm -f "$ec_tmp"' EXIT

cd "$EC_ROOT"
nix develop --no-write-lock-file "path:$EC_ROOT" --command bash -c '
    printf "PATH=%s\n" "$PATH"
    printf "CC=%s\n" "$CC"
    printf "CXX=%s\n" "$CXX"
    printf "OBJCACHE=%s\n" "$OBJCACHE"
    printf "CCACHE_BASEDIR=%s\n" "$CCACHE_BASEDIR"
    printf "CCACHE_DIR=%s\n" "$CCACHE_DIR"
    printf "RISCV=%s\n" "$RISCV"
    printf "JAVA_HOME=%s\n" "$JAVA_HOME"
    printf "SBT_BIN=%s\n" "$SBT_BIN"
    printf "FIRTOOL_BIN=%s\n" "$FIRTOOL_BIN"
    printf "CPLUS_INCLUDE_PATH=%s\n" "$CPLUS_INCLUDE_PATH"
    printf "LIBRARY_PATH=%s\n" "$LIBRARY_PATH"
    printf "IN_NIX_SHELL=%s\n" "$IN_NIX_SHELL"
' > "$ec_tmp"

chmod 600 "$ec_tmp"
mv -f "$ec_tmp" "$ec_cache"
trap - EXIT
printf 'EC environment cache written to %s\n' "$ec_cache"
