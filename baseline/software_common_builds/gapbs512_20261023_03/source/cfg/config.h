#ifndef TEST_CONFIG_H
#define TEST_CONFIG_H
#include <stdint.h>

#define NUM_CHECKERS 4
#define NUM_HARTS (NUM_CHECKERS + 1)
#define TIMER_HARTS 4
#define TIMER_LIMIT 50
#define TIMER_COMPARE_DELTA UINT64_C(0x20)
#define CLINT_BASE UINT64_C(0x2000000)
#define CLINT_MSIP_OFFSET(hart_id) ((hart_id) * 4)
#define CLINT_MTIMECMP_OFFSET(hart_id) (UINT64_C(0x4000) + (hart_id) * 8)
#define CLINT_MTIME_ADDRESS (CLINT_BASE + UINT64_C(0xBFF8))
#endif
