#ifndef TEST_CONFIG_H
#define TEST_CONFIG_H

#include <stdint.h>

/* 协同拓扑：1 个 BOOM hart 加 NUM_CHECKERS 个 Rocket checker hart。 */
#define NUM_CHECKERS 4
#define NUM_HARTS (NUM_CHECKERS + 1)

/* CLINT 和定时器相关配置。 */
#define TIMER_HARTS 4
#define TIMER_LIMIT 50
#define TIMER_COMPARE_DELTA UINT64_C(0x20)
#define CLINT_BASE UINT64_C(0x2000000)
#define CLINT_MSIP_OFFSET(hart_id) ((hart_id) * 4)
#define CLINT_MTIMECMP_OFFSET(hart_id) (UINT64_C(0x4000) + (hart_id) * 8)
#define CLINT_MTIME_ADDRESS (CLINT_BASE + UINT64_C(0xBFF8))

/* CSR 性能计数器数量。 */
#define TOTAL_CSR_PERF 84

#ifndef BOOM_CORE_FREQUENCY_HZ
#define BOOM_CORE_FREQUENCY_HZ UINT64_C(200000000)
#endif

#ifndef CHECKER_CORE_FREQUENCY_HZ
#define CHECKER_CORE_FREQUENCY_HZ UINT64_C(100000000)
#endif

#ifndef FPGA_PERF_INTERVAL_CYCLES
#define FPGA_PERF_INTERVAL_CYCLES 5000ULL
#endif

#ifndef PACKAGE_DRAIN_TIMEOUT_CYCLES
#define PACKAGE_DRAIN_TIMEOUT_CYCLES UINT64_C(100000)
#endif

#ifndef MEEK_ENABLE_BIG_CORE_PERF
#define MEEK_ENABLE_BIG_CORE_PERF 0
#endif

#ifndef MEEK_ENABLE_CHECKER_SEGMENT_PERF
#define MEEK_ENABLE_CHECKER_SEGMENT_PERF 1
#endif

/* Human-readable report by default; set to 1 for raw per-hart diagnostics. */
#ifndef TEST_REPORT_VERBOSE
#define TEST_REPORT_VERBOSE 0
#endif

#if MEEK_ENABLE_BIG_CORE_PERF != 0
#error "The retained test.riscv configuration requires MEEK_ENABLE_BIG_CORE_PERF=0"
#endif

#if MEEK_ENABLE_CHECKER_SEGMENT_PERF != 1
#error "The retained test.riscv configuration requires MEEK_ENABLE_CHECKER_SEGMENT_PERF=1"
#endif

#endif
