#!/usr/bin/env bash
# Build one or all Embench workloads with the bare-metal MEEK wrapper.

set -eo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
SUPPORT_DIR="$SCRIPT_DIR/embench-iot/support"
SRC_DIR="$SCRIPT_DIR/embench-iot/src"
BUILD_DIR="$SCRIPT_DIR/build_meek"

usage() {
  echo "Usage: $0 <benchmark_name|all|clean> [checker|big|both|off]"
  echo "Default perf mode: checker"
  echo "Available benchmarks:"
  find "$SRC_DIR" -mindepth 1 -maxdepth 1 -type d -printf '  %f\n' | sort
}

if [[ $# -lt 1 || $# -gt 2 ]]; then
  usage
  exit 1
fi

PERF_MODE="${2:-${MEEK_PERF_MODE:-checker}}"
case "$PERF_MODE" in
  checker)
    PERF_DEFINES=(-DMEEK_ENABLE_BIG_CORE_PERF=0 -DMEEK_ENABLE_CHECKER_SEGMENT_PERF=1)
    ;;
  big)
    PERF_DEFINES=(-DMEEK_ENABLE_BIG_CORE_PERF=1 -DMEEK_ENABLE_CHECKER_SEGMENT_PERF=0)
    ;;
  both)
    PERF_DEFINES=(-DMEEK_ENABLE_BIG_CORE_PERF=1 -DMEEK_ENABLE_CHECKER_SEGMENT_PERF=1)
    ;;
  off)
    PERF_DEFINES=(-DMEEK_ENABLE_BIG_CORE_PERF=0 -DMEEK_ENABLE_CHECKER_SEGMENT_PERF=0)
    ;;
  *)
    echo "error: invalid perf mode '$PERF_MODE' (expected checker, big, both, or off)" >&2
    exit 1
    ;;
esac

if [[ "$1" == "clean" ]]; then
  rm -rf "$BUILD_DIR"
  echo "Cleaned: $BUILD_DIR"
  exit 0
fi

CC="${RISCV_GCC:-riscv64-unknown-elf-gcc}"
OBJDUMP="${RISCV_OBJDUMP:-riscv64-unknown-elf-objdump}"

# The system compiler may have the same name but lacks Chipyard's HTIF specs.
if ! command -v "$CC" >/dev/null 2>&1 || \
   [[ "$($CC -print-file-name=htif_nano.specs 2>/dev/null || true)" == "htif_nano.specs" ]]; then
  # shellcheck disable=SC1091
  source "$REPO_ROOT/env.sh"
fi

if ! command -v "$CC" >/dev/null 2>&1; then
  echo "error: $CC is not available" >&2
  exit 1
fi
if [[ "$($CC -print-file-name=htif_nano.specs)" == "htif_nano.specs" ]]; then
  echo "error: $CC cannot find htif_nano.specs; source $REPO_ROOT/env.sh" >&2
  exit 1
fi

set -u

WARMUP_HEAT="${WARMUP_HEAT:-1}"
CFLAGS=(
  -std=gnu11
  -O2
  -fno-common
  -fno-builtin-printf
  -specs=htif_nano.specs
  -march=rv64imafd
  -mabi=lp64d
  -I"$SUPPORT_DIR"
  -DCPU_MHZ=1
  -DWARMUP_HEAT="$WARMUP_HEAT"
  -DHAVE_BOARDSUPPORT_H
  "${PERF_DEFINES[@]}"
)
LDFLAGS=(
  -static
  -specs=htif_nano.specs
  -march=rv64imafd
  -mabi=lp64d
)

build_benchmark() {
  local bench="$1"
  local bench_dir="$SRC_DIR/$bench"
  local obj_dir="$BUILD_DIR/.obj/$bench"
  local output="$BUILD_DIR/$bench.riscv"
  local src obj start_address
  local -a objects=()
  local -a bench_sources=()

  if [[ ! -d "$bench_dir" ]]; then
    echo "error: unknown benchmark '$bench'" >&2
    return 1
  fi

  mapfile -t bench_sources < <(find "$bench_dir" -maxdepth 1 -type f -name '*.c' -print | sort)
  if [[ ${#bench_sources[@]} -eq 0 ]]; then
    echo "error: no C sources found for '$bench'" >&2
    return 1
  fi

  mkdir -p "$obj_dir"
  echo "=== Building MEEK-wrapped $bench ==="

  for src in meek.c tasks.c main_meek.c board.c beebsc.c; do
    obj="$obj_dir/${src%.c}.o"
    "$CC" "${CFLAGS[@]}" -c "$SUPPORT_DIR/$src" -o "$obj"
    objects+=("$obj")
  done

  for src in "${bench_sources[@]}"; do
    obj="$obj_dir/$(basename "${src%.c}").o"
    "$CC" "${CFLAGS[@]}" -I"$bench_dir" -c "$src" -o "$obj"
    objects+=("$obj")
  done

  "$CC" "${LDFLAGS[@]}" "${objects[@]}" -lm -o "$output"
  start_address=$("$OBJDUMP" -f "$output" | awk '/start address/ {print $3}')
  if [[ "$start_address" != "0x0000000080000000" ]]; then
    echo "error: $bench entry point is $start_address, expected 0x80000000" >&2
    return 1
  fi
  "$OBJDUMP" -d -S "$output" > "$BUILD_DIR/$bench.dump"
  echo "=== Done: $output ==="
}

mkdir -p "$BUILD_DIR"
echo "MEEK perf mode: $PERF_MODE"

if [[ "$1" == "all" ]]; then
  mapfile -t benchmarks < <(find "$SRC_DIR" -mindepth 1 -maxdepth 1 -type d -printf '%f\n' | sort)
  for benchmark in "${benchmarks[@]}"; do
    build_benchmark "$benchmark"
  done
else
  build_benchmark "$1"
fi
