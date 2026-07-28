/**
 * @file performance.h
 * @brief Hardware-matched GHE counter control for the BOOM/checker test.
 */

#ifndef TEST_PERFORMANCE_H
#define TEST_PERFORMANCE_H

#include <stdint.h>

#include "test_config.h"

uint64_t performance_read_cycles(void);
uint64_t performance_read_instruction_count(void);
#if MEEK_ENABLE_BIG_CORE_PERF
/** Reset BOOM-local debug performance counters. */
void performance_begin_big_core(void);
/** Snapshot BOOM-local debug performance counters. */
void performance_end_big_core(void);
#endif
#if MEEK_ENABLE_CHECKER_PERF
/** Reset one checker hart's counters at the beginning of replay. */
void performance_begin_checker(uint64_t hart_id);
/** Snapshot one checker hart's counters before final context comparison. */
void performance_end_checker(uint64_t hart_id);
/** Print a previously captured checker snapshot under the shared UART lock. */
void performance_report_checker(uint64_t hart_id);
#endif
void performance_report(uint64_t cycle_start, uint64_t cycle_end,
                        uint64_t instruction_start,
                        uint64_t instruction_end);

#endif /* TEST_PERFORMANCE_H */
