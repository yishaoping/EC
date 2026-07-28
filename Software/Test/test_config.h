/**
 * @file test_config.h
 * @brief BOOM/Rocket cooperative-checking test configuration.
 *
 * Keep platform-dependent values in this file.  The C modules implement
 * behavior and should not contain topology, MMIO, workload-address, or
 * performance-mode literals unless the value is part of an instruction ABI.
 */

#ifndef TEST_CONFIG_H
#define TEST_CONFIG_H

#include <stdint.h>

/* One BOOM producer (hart 0) and four Rocket checker harts (hart 1..4). */
#define TEST_BIG_CORE_HART_ID              UINT64_C(0)
#define TEST_FIRST_CHECKER_HART_ID         UINT64_C(1)
#define TEST_NUM_CHECKERS                  4U
#define TEST_NUM_HARTS                     (TEST_NUM_CHECKERS + 1U)
#define TEST_LAST_CHECKER_HART_ID          \
    (TEST_FIRST_CHECKER_HART_ID + TEST_NUM_CHECKERS - 1U)

/* Cross-hart store report timeout and per-clock-domain cycle conversion. */
#define TEST_STORECOUNT_WAIT_CYCLES        UINT64_C(1000000)
#define TEST_BIG_CORE_CLOCK_MHZ            200U
#define TEST_CHECKER_CLOCK_MHZ             100U

/*
 * The original test enables CLINT timer traffic on hart 0..3.  Hart 4 still
 * participates as a checker, but does not receive this additional stimulus.
 */
#define TEST_NUM_TIMER_HARTS               4U
#define TEST_TIMER_INTERRUPT_LIMIT         50U
#define TEST_TIMER_INTERVAL_TICKS          UINT64_C(0x20)

/* SiFive-style CLINT register layout used by the Chipyard platform. */
#define TEST_CLINT_BASE                    UINT64_C(0x02000000)
#define TEST_CLINT_MSIP_OFFSET(hart_id)    ((uint64_t)(hart_id) * 4U)
#define TEST_CLINT_MTIMECMP_OFFSET(hart_id) \
    (UINT64_C(0x4000) + (uint64_t)(hart_id) * 8U)
#define TEST_CLINT_MTIME_OFFSET            UINT64_C(0xBFF8)

/* GuardianCouncil completion and monitor-control parameters. */
#define TEST_GHT_COMPLETE_STATUS           UINT64_C(0x1FFFF)
#define TEST_CHECKER_COMPLETE_STATUS       UINT64_C(0x02)
#define TEST_CHECKER_ELU_COUNT             2U
#define TEST_PIPELINE_DRAIN_NOPS           26

/* Fixed physical region reserved for the mixed instruction workload. */
#define TEST_WORKLOAD_MEMORY_BASE          0x81000000
#define TEST_WORKLOAD_MEMORY_LIMIT         0x810008FF
#define TEST_WORKLOAD_ATOMIC_INITIAL       0x81000100
#define TEST_WORKLOAD_STORE_DATA_A         0x55552000
#define TEST_WORKLOAD_STORE_DATA_B         0x55553000
#define TEST_WORKLOAD_ITERATIONS           3U

/* Compile-time performance modes selected by compile.sh -p. */
#ifndef MEEK_ENABLE_BIG_CORE_PERF
#define MEEK_ENABLE_BIG_CORE_PERF          0
#endif

#ifndef MEEK_ENABLE_CHECKER_PERF
#define MEEK_ENABLE_CHECKER_PERF           1
#endif

#if (MEEK_ENABLE_BIG_CORE_PERF != 0) && (MEEK_ENABLE_BIG_CORE_PERF != 1)
#error "MEEK_ENABLE_BIG_CORE_PERF must be 0 or 1"
#endif

#if (MEEK_ENABLE_CHECKER_PERF != 0) && (MEEK_ENABLE_CHECKER_PERF != 1)
#error "MEEK_ENABLE_CHECKER_PERF must be 0 or 1"
#endif

#endif /* TEST_CONFIG_H */
