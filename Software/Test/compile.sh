#!/usr/bin/env bash
# Build HTIF bare-metal tests and emit a compact loadable ELF plus a focused
# source/disassembly report.  Use -p checker|big|both|off for perf collection.

set -euo pipefail

source_file=""
clean_files=""
object_file=""
malloc_file=""
perf_mode="${MEEK_PERF_MODE:-checker}"

while getopts "c:r:o:m:p:" flag; do
    case "${flag}" in
        c) source_file=${OPTARG} ;;
        r) clean_files=${OPTARG} ;;
        o) object_file=${OPTARG} ;;
        m) malloc_file=${OPTARG} ;;
        p) perf_mode=${OPTARG} ;;
        *) exit 2 ;;
    esac
done

case "${perf_mode}" in
    checker)
        perf_flags=(-DMEEK_ENABLE_BIG_CORE_PERF=0
                    -DMEEK_ENABLE_CHECKER_PERF=1)
        ;;
    big)
        perf_flags=(-DMEEK_ENABLE_BIG_CORE_PERF=1
                    -DMEEK_ENABLE_CHECKER_PERF=0)
        ;;
    both)
        perf_flags=(-DMEEK_ENABLE_BIG_CORE_PERF=1
                    -DMEEK_ENABLE_CHECKER_PERF=1)
        ;;
    off)
        perf_flags=(-DMEEK_ENABLE_BIG_CORE_PERF=0
                    -DMEEK_ENABLE_CHECKER_PERF=0)
        ;;
    *)
        echo "error: invalid perf mode '${perf_mode}' (checker, big, both, off)" >&2
        exit 2
        ;;
esac

cc=${RISCV_CC:-riscv64-unknown-elf-gcc}
objcopy=${RISCV_OBJCOPY:-riscv64-unknown-elf-objcopy}
objdump=${RISCV_OBJDUMP:-riscv64-unknown-elf-objdump}
nm=${RISCV_NM:-riscv64-unknown-elf-nm}

common_flags=(-fno-common -fno-builtin-printf -specs=htif_nano.specs
              -march=rv64imafd -O2 -g -ffunction-sections -fdata-sections
              -Wall -Wextra)
link_flags=(-static -Wl,--gc-sections)

if [[ ${clean_files} == "all" ]]; then
    rm -f -- ./*.o ./*.riscv ./*.dump \
        ./.*.unstripped.riscv ./.*.stripped.riscv
    echo ">> Removed generated object, ELF, and dump files"
fi

build_test() {
    local name=$1
    local source="${name}.c"
    local output="${name}.riscv"
    local stripped_output=".${name}.stripped.riscv"
    local dump_output="${name}.dump"
    local support_sources
    local objects

    if [[ ! -f ${source} ]]; then
        echo "error: source file '${source}' does not exist" >&2
        exit 1
    fi

    if [[ ${name} == "test" ]]; then
        support_sources=(tasks.c clint.c ght_config.c performance.c
                         store_stats.c test_workload.c)
    else
        # Historical TC_*.c programs provide their own GHT/CLINT framework.
        support_sources=(tasks.c performance.c store_stats.c)
    fi

    objects=("${name}.o")
    for support in "${support_sources[@]}"; do
        objects+=("${support%.c}.o")
    done

    rm -f -- "${objects[@]}" "${output}" "${stripped_output}" "${dump_output}"
    echo ">> Building ${source} (perf=${perf_mode})"

    "${cc}" "${common_flags[@]}" "${perf_flags[@]}" \
        -c "${source}" "${support_sources[@]}"

    local extra_objects=()
    if [[ -n ${malloc_file} ]]; then
        extra_objects+=("${malloc_file}")
    fi

    "${cc}" "${common_flags[@]}" "${perf_flags[@]}" \
        "${link_flags[@]}" "${objects[@]}" "${extra_objects[@]}" \
        -o "${output}"

    # Keep application code plus the HTIF startup/syscall path used by printf.
    # This makes a stalled tohost/fromhost handshake directly visible in the
    # focused dump instead of leaving the waveform PC outside the report.
    local dump_symbols=(
        _start _start_main _start_secondary htif_syscall
        trap_entry main __main handle_trap checker
        clint_read_mtime clint_trigger_software_interrupt
        clint_schedule_timer_interrupt clint_enable_timer_interrupt
        clint_enable_software_interrupt ght_configure test_run_workload
        performance_read_cycles performance_read_instruction_count
        performance_begin_big_core performance_end_big_core
        performance_begin_checker performance_end_checker
        performance_report_checkers performance_report
        store_stats_publish store_stats_wait_all store_stats_print_report
        printf _printf_r _vfiprintf_r
        putc _putc_r fputc _fputc_r __sputc_r __sfputc_r __swbuf_r
        write _write _write_r
        r_ini perfstart perfend
    )

    : > "${dump_output}"
    for symbol in "${dump_symbols[@]}"; do
        if "${nm}" --defined-only "${output}" | \
                awk '{print $3}' | grep -Fxq "${symbol}"; then
            "${objdump}" -d -S --disassemble="${symbol}" "${output}" \
                >> "${dump_output}"
        fi
    done

    # FESVR discovers the memory-mapped HTIF handshake through the ELF symbol
    # names.  Keep only those runtime-critical symbols while removing DWARF
    # and unrelated application/library symbols from the simulator image.
    "${objcopy}" --strip-all --remove-section=.comment \
        --keep-symbol=_start \
        --keep-symbol=tohost \
        --keep-symbol=fromhost \
        "${output}" "${stripped_output}"
    mv -f -- "${stripped_output}" "${output}"

    for required_symbol in tohost fromhost; do
        if ! "${nm}" --defined-only "${output}" | \
                awk '{print $3}' | grep -Fxq "${required_symbol}"; then
            echo "error: stripped ELF lost required HTIF symbol '${required_symbol}'" >&2
            exit 1
        fi
    done

    rm -f -- "${objects[@]}"
    echo ">> Generated ${output} and focused ${dump_output}"
}

if [[ -n ${source_file} ]]; then
    build_test "${source_file}"
fi

if [[ -n ${object_file} ]]; then
    if [[ ! -f ${object_file}.c ]]; then
        echo "error: source file '${object_file}.c' does not exist" >&2
        exit 1
    fi
    rm -f -- "${object_file}.o"
    "${cc}" "${common_flags[@]}" "${perf_flags[@]}" \
        -c "${object_file}.c" -o "${object_file}.o"
    echo ">> Generated ${object_file}.o"
fi
