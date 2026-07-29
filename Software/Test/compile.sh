#!/usr/bin/env bash

set -euo pipefail

script_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
cd "$script_dir"

gcc_name=riscv64-unknown-elf-gcc
gcc_path=

if command -v "$gcc_name" >/dev/null 2>&1; then
    gcc_path=$(command -v "$gcc_name")
elif [[ -n ${RISCV:-} && -x ${RISCV}/bin/${gcc_name} ]]; then
    gcc_path=${RISCV}/bin/${gcc_name}
else
    candidates=(
        "$script_dir/../../../Chipyard1130/.conda-env/riscv-tools/bin/$gcc_name"
        "$script_dir/../../chipyard/.conda-env/riscv-tools/bin/$gcc_name"
    )
    for candidate in "${candidates[@]}"; do
        if [[ -x $candidate ]]; then
            gcc_path=$candidate
            break
        fi
    done
fi

if [[ -z $gcc_path ]]; then
    echo "error: $gcc_name was not found; activate the Chipyard toolchain" >&2
    exit 1
fi

objdump_path=${gcc_path%gcc}objdump
if [[ ! -x $objdump_path ]]; then
    echo "error: riscv64-unknown-elf-objdump was not found beside $gcc_path" >&2
    exit 1
fi

build_dir=$(mktemp -d "${TMPDIR:-/tmp}/meek-test.XXXXXX")
trap 'rm -rf -- "$build_dir"' EXIT

sources=(
    interrupt.c
    test.c
    secondary.c
    checker_config.c
    checker.c
    spin_lock.c
)

"$gcc_path" \
    -fno-common \
    -fno-builtin-printf \
    -specs=htif_nano.specs \
    -march=rv64imafd \
    -O2 \
    -DMEEK_ENABLE_BIG_CORE_PERF=0 \
    -DMEEK_ENABLE_CHECKER_SEGMENT_PERF=1 \
    -static \
    "${sources[@]}" \
    -o "$build_dir/test.riscv"

mv -- "$build_dir/test.riscv" test.riscv
"$objdump_path" -d -S test.riscv > "$build_dir/test.dump"
mv -- "$build_dir/test.dump" test.dump

echo "generated: $script_dir/test.riscv"
echo "generated: $script_dir/test.dump"
