#include <stdint.h>
#include <stdio.h>

#ifndef MEEK_ENABLE_BIG_CORE_PERF
#define MEEK_ENABLE_BIG_CORE_PERF 0
#endif

#ifndef MEEK_ENABLE_CHECKER_SEGMENT_PERF
#define MEEK_ENABLE_CHECKER_SEGMENT_PERF 1
#endif

#ifndef FPGA_PERF_INTERVAL_CYCLES
#define FPGA_PERF_INTERVAL_CYCLES 5000ULL
#endif

#if (MEEK_ENABLE_BIG_CORE_PERF != 0) && (MEEK_ENABLE_BIG_CORE_PERF != 1)
#error "MEEK_ENABLE_BIG_CORE_PERF must be 0 or 1"
#endif

#if (MEEK_ENABLE_CHECKER_SEGMENT_PERF != 0) && (MEEK_ENABLE_CHECKER_SEGMENT_PERF != 1)
#error "MEEK_ENABLE_CHECKER_SEGMENT_PERF must be 0 or 1"
#endif

extern int uart_lock;
extern char* shadow;

int checker (int hart_id);
uint64_t task_synthetic_malloc (uint64_t base);
