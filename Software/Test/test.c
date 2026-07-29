/**
 * @file test.c
 * @brief Top-level BOOM producer and Rocket checker orchestration.
 *
 * This file deliberately contains only the cooperative-checking framework.
 * Platform constants live in test_config.h; CLINT, GHT setup, workload,
 * checker execution, performance collection, and cross-hart store reporting
 * are implemented separately.
 */

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#include "clint.h"
#include "ght.h"
#include "ght_config.h"
#include "performance.h"
#include "rocc.h"
#include "spin_lock.h"
#include "store_stats.h"
#include "tasks.h"
#include "test_config.h"
#include "test_workload.h"

#define STRINGIFY_IMPL(value) #value
#define STRINGIFY(value) STRINGIFY_IMPL(value)

static uint64_t read_hart_id(void)
{
    uint64_t hart_id;
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));
    return hart_id;
}

/** hart 0: configure, run the BOOM workload, then wait for replay completion. */
int main(void)
{
    ght_configure(TEST_NUM_CHECKERS);

    /* Exercise the machine-software-interrupt path before monitoring starts. */
    clint_enable_software_interrupt();
    clint_trigger_software_interrupt();

    lock_acquire(&uart_lock);
    printf("Software interrupt test complete!\n");
    lock_release(&uart_lock);

    /* Every checker calls ghe_initailised(1) before this status becomes set. */
    while (ght_get_initialisation() == 0U) {
    }

    uint64_t hart_id = read_hart_id();
    lock_acquire(&uart_lock);
    printf("[Boom-C%" PRIx64 "]: Test is now started: \r\n", hart_id);
    printf("[MEEK_PERF_CFG] big=%d checker=%d hardware_counters=1\r\n",
           MEEK_ENABLE_BIG_CORE_PERF, MEEK_ENABLE_CHECKER_PERF);
    lock_release(&uart_lock);

    uint64_t instruction_start = performance_read_instruction_count();

    /* Capture BOOM's privilege context and add periodic MTIP stimulus. */
    ght_set_satp_priv();
    clint_schedule_timer_interrupt();
    clint_enable_timer_interrupt();
#if MEEK_ENABLE_BIG_CORE_PERF
    performance_begin_big_core();
#endif

    /* Start GuardianCouncil monitoring and open a replay window. */
    ROCC_INSTRUCTION(1, 0x31);
    ROCC_INSTRUCTION_S(1, 0x01, 0x70);

    uint64_t cycle_start = performance_read_cycles();
    hart_id = test_run_workload(hart_id);

#if MEEK_ENABLE_BIG_CORE_PERF
    performance_end_big_core();
#endif
    ROCC_INSTRUCTION_S(1, 0x02, 0x70);
    asm volatile(
        ".rept " STRINGIFY(TEST_PIPELINE_DRAIN_NOPS) "\n\t"
        "nop\n\t"
        ".endr"
        ::: "memory");
    ROCC_INSTRUCTION(1, 0x32);

    uint64_t instruction_end = performance_read_instruction_count();
    while (ght_get_status() < TEST_GHT_COMPLETE_STATUS) {
    }
    uint64_t cycle_end = performance_read_cycles();

    /* Publish BOOM's endpoint, then collect the four checker endpoints. */
    store_stats_publish(hart_id);
    int all_store_stats_ready = store_stats_wait_all();
    if (!all_store_stats_ready) {
        lock_acquire(&uart_lock);
        printf("[Boom-C%" PRIx64 "]: storecount wait timeout\r\n", hart_id);
        lock_release(&uart_lock);
    }

    performance_report(cycle_start, cycle_end,
                       instruction_start, instruction_end);
#if MEEK_ENABLE_CHECKER_PERF
    performance_report_checkers();
#endif

    lock_acquire(&uart_lock);
    store_stats_print_report(all_store_stats_ready);
    printf("[Boom-C%" PRIx64 "]: Test is now completed. \r\n", hart_id);
    lock_release(&uart_lock);

    ght_unset_satp_priv();
    ROCC_INSTRUCTION(1, 0x30);
    return 0;
}

/** hart 1..4: enter the checker loop; other secondary harts remain idle. */
int __main(void)
{
    uint64_t hart_id = read_hart_id();

    if (hart_id >= TEST_FIRST_CHECKER_HART_ID &&
        hart_id <= TEST_LAST_CHECKER_HART_ID) {
        /* Preserve the original topology: MTIP/MSIP stimulus on hart 1..3. */
        if (hart_id < TEST_NUM_TIMER_HARTS) {
            clint_enable_software_interrupt();
            clint_trigger_software_interrupt();
            clint_schedule_timer_interrupt();
            clint_enable_timer_interrupt();
        }
        checker(hart_id);
    }

    idle();
    return 0;
}

#undef STRINGIFY
#undef STRINGIFY_IMPL
