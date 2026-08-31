#!/usr/bin/env bash

set -euo pipefail

script_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
repo_dir=$(cd -- "$script_dir/../.." && pwd)
chipyard_dir="$repo_dir/chipyard"
cd "$script_dir"

gcc_name=riscv64-unknown-elf-gcc
gcc_path=

compiler_has_newlib() {
    local compiler=$1

    [[ -x $compiler ]] || return 1
    "$compiler" -E -x c -o /dev/null - >/dev/null 2>&1 <<'EOF'
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
EOF
}

candidates=()
if [[ -n ${RISCV:-} ]]; then
    candidates+=("$RISCV/bin/$gcc_name")
fi
candidates+=("$chipyard_dir/.conda-env/riscv-tools/bin/$gcc_name")
if command -v "$gcc_name" >/dev/null 2>&1; then
    candidates+=("$(command -v "$gcc_name")")
fi

for candidate in "${candidates[@]}"; do
    if compiler_has_newlib "$candidate"; then
        gcc_path=$candidate
        break
    fi
done

if [[ -z $gcc_path ]]; then
    echo "error: no complete $gcc_name toolchain was found" >&2
    echo "       expected $chipyard_dir/.conda-env/riscv-tools or a valid RISCV prefix" >&2
    exit 1
fi

objdump_path=${gcc_path%gcc}objdump
if [[ ! -x $objdump_path ]]; then
    echo "error: riscv64-unknown-elf-objdump was not found beside $gcc_path" >&2
    exit 1
fi

libgloss_dir="$chipyard_dir/toolchains/libgloss"
htif_specs="$libgloss_dir/util/htif_nano.specs"
htif_linker_script="$libgloss_dir/util/htif.ld"
htif_library_dir="$libgloss_dir/build"
encoding_header="$chipyard_dir/toolchains/riscv-tools/riscv-pk/machine/encoding.h"

required_files=(
    "$htif_specs"
    "$htif_linker_script"
    "$htif_library_dir/libgloss_htif.a"
    "$encoding_header"
)
for required_file in "${required_files[@]}"; do
    if [[ ! -f $required_file ]]; then
        echo "error: required build input is missing: $required_file" >&2
        exit 1
    fi
done

build_dir=$(mktemp -d "${TMPDIR:-/tmp}/meek-test.XXXXXX")
trap 'rm -rf -- "$build_dir"' EXIT

mkdir -p "$build_dir/riscv-pk"
ln -s "$encoding_header" "$build_dir/riscv-pk/encoding.h"
ln -s "$htif_linker_script" "$build_dir/htif.ld"

sources=(
    "$script_dir/hw/interrupt.c"
    "$script_dir/test.c"
    "$script_dir/Benchmark/gapbs/gapbs_bfs.c"
    "$script_dir/stat/report.c"
    "$script_dir/core/secondary.c"
    "$script_dir/cfg/init.c"
    "$script_dir/core/checker.c"
    "$script_dir/hw/spin_lock.c"
)

(
    cd "$build_dir"
    "$gcc_path" \
        -fno-common \
        -fno-builtin-printf \
        -specs="$htif_specs" \
        -L"$htif_library_dir" \
        -I"$build_dir" \
        -I"$script_dir" \
        -march=rv64imafd \
        -O2 \
        -DMEEK_ENABLE_BIG_CORE_PERF=0 \
        -DMEEK_ENABLE_CHECKER_SEGMENT_PERF=1 \
        -static \
        "${sources[@]}" \
        -o test.riscv
)

(
    cd "$build_dir"
    "$objdump_path" -d -S test.riscv > test.dump
)
mv -- "$build_dir/test.riscv" test.riscv
mv -- "$build_dir/test.dump" test.dump

echo "generated: $script_dir/test.riscv"
echo "generated: $script_dir/test.dump"
