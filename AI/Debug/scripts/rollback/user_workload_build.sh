#!/usr/bin/env bash
# Build the directed workload without running the simulator.
set -euo pipefail
repo=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../../../.." && pwd)
: "${PALIMPSEST_SW_OUT:?Choose a fresh absolute directory under the repository AI/TMP}"
case "$PALIMPSEST_SW_OUT" in "$repo"/AI/TMP/*) ;; *) exit 2;; esac
[[ ! -e "$PALIMPSEST_SW_OUT" ]] || { echo 'Output already exists' >&2; exit 2; }
profile_flags=()
case "${PALIMPSEST_WORKLOAD_PROFILE:-full}" in
  full) ;;
  compact) profile_flags+=(-DPALIMPSEST_COMPACT_WORKLOAD);;
  compact-trap-io) profile_flags+=(-DPALIMPSEST_COMPACT_WORKLOAD -DPALIMPSEST_TRAP_IO_WORKLOAD);;
  compact-mmio-output) profile_flags+=(-DPALIMPSEST_COMPACT_WORKLOAD -DPALIMPSEST_TRAP_IO_WORKLOAD -DPALIMPSEST_MMIO_OUTPUT_WORKLOAD);;
  compact-mmio-amo) profile_flags+=(-DPALIMPSEST_COMPACT_WORKLOAD -DPALIMPSEST_TRAP_IO_WORKLOAD -DPALIMPSEST_MMIO_AMO_WORKLOAD);;
  compact-sv39) profile_flags+=(-DPALIMPSEST_COMPACT_WORKLOAD -DPALIMPSEST_SV39_WORKLOAD);;
  *) echo 'PALIMPSEST_WORKLOAD_PROFILE must be full, compact, compact-trap-io, compact-mmio-output, compact-mmio-amo or compact-sv39' >&2; exit 2;;
esac
mkdir -p "$PALIMPSEST_SW_OUT/include/riscv-pk"
sw="$repo/Software/Test"
toolchain=${PALIMPSEST_RISCV_TOOLS:-"$repo/chipyard/.conda-env/riscv-tools"}
gloss="$repo/chipyard/toolchains/libgloss"
ln -s "$repo/chipyard/toolchains/riscv-tools/riscv-pk/machine/encoding.h" "$PALIMPSEST_SW_OUT/include/riscv-pk/encoding.h"
ln -s "$gloss/util/htif.ld" "$PALIMPSEST_SW_OUT/htif.ld"
python3 -B "$repo/AI/Debug/scripts/rollback/source_manifest.py" "$PALIMPSEST_SW_OUT/sources.json"
cd "$PALIMPSEST_SW_OUT"
"$toolchain/bin/riscv64-unknown-elf-gcc" -fno-common -fno-builtin-printf \
  -specs="$gloss/util/htif_nano.specs" -L"$gloss/build" \
  -I"$PALIMPSEST_SW_OUT/include" -I"$sw" -march=rv64imafd -O2 -static \
  "${profile_flags[@]}" \
  -DMEEK_ENABLE_BIG_CORE_PERF=0 -DMEEK_ENABLE_CHECKER_SEGMENT_PERF=1 \
  "$repo/AI/Debug/scripts/rollback/fullcore_test.c" "$sw/hw/interrupt.c" \
  "$sw/stat/report.c" "$sw/core/secondary.c" "$sw/cfg/init.c" \
  "$sw/core/checker.c" "$sw/hw/spin_lock.c" -o palimpsest.riscv
"$toolchain/bin/riscv64-unknown-elf-objdump" -d -S palimpsest.riscv > palimpsest.dump
sha256sum palimpsest.riscv palimpsest.dump > workload.sha256
echo "Workload ready: $PALIMPSEST_SW_OUT/palimpsest.riscv"
