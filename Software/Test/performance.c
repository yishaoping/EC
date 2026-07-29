/**
 * @file performance.c
 * @brief Hardware-matched GHE counter snapshots and execution reporting.
 *
 * GHE funct 0x76 only resets or selects a cumulative counter; it does not
 * start or stop a sampler.  A measurement interval is therefore represented
 * by resetting at its beginning and snapshotting every required selector at
 * its end.  Cross-hart Storecount reporting is kept in store_stats.c because
 * it must remain active independently of the optional performance modes.
 */

#include "performance.h"

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#include "clint.h"
#include "ghe.h"
#include "spin_lock.h"
#include "test_config.h"

#if MEEK_ENABLE_BIG_CORE_PERF
typedef struct {
    uint64_t elapsed_cycles;
    uint64_t scheduler_blocked;
    uint64_t scheduler_cycles;
    uint64_t check_cycles;
    uint64_t other_thread_cycles;
    uint64_t all_busy_cycles;
    uint64_t scheduler_other_cycles;
    int valid;
} big_core_snapshot_t;

static big_core_snapshot_t big_core_snapshot;
#endif

#if MEEK_ENABLE_CHECKER_PERF
typedef struct {
    uint64_t checking_cycles;
    uint64_t postchecking_cycles;
    uint64_t other_thread_cycles;
    uint64_t nonchecking_cycles;
    uint64_t checkpoints;
    uint64_t checkpoint_transfer_cycles;
    uint64_t worst_check_latency;
    uint64_t replay_stores;
    uint64_t replay_loads;
    int valid;
} checker_snapshot_t;

/*
 * Each checker writes one slot and hart 0 reads all slots after the
 * store_stats ready/fence handshake.  Volatile prevents either side from
 * caching shared fields across that cross-hart synchronization point.
 */
static volatile checker_snapshot_t checker_snapshots[TEST_NUM_CHECKERS];

/*
 * The checker checkpoint restores general-purpose registers.  In particular,
 * a hart_id kept in a callee-saved register by checker() can become BOOM's
 * saved value after replay.  Read the architectural hart ID at each API entry
 * instead of accepting a value that crossed a checkpoint restore.
 */
static uint64_t current_hart_id(void)
{
    uint64_t hart_id;
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));
    return hart_id;
}
#endif

uint64_t performance_read_cycles(void)
{
    uint64_t cycles;
    asm volatile("rdcycle %0" : "=r"(cycles));
    return cycles;
}

uint64_t performance_read_instruction_count(void)
{
    return ghe_csr_perf_read(0);
}

#if MEEK_ENABLE_BIG_CORE_PERF
void performance_begin_big_core(void)
{
    big_core_snapshot.valid = 0;
    ghe_perf_reset();
}

void performance_end_big_core(void)
{
    /* Selector 7 is the free-running R_IC cycle counter after reset. */
    big_core_snapshot.elapsed_cycles =
        ghe_perf_read_selected(GHE_BIG_PERF_ELAPSED_CYCLES);
    big_core_snapshot.scheduler_blocked =
        ghe_perf_read_selected(GHE_BIG_PERF_SCHED_BLOCKED);
    big_core_snapshot.scheduler_cycles =
        ghe_perf_read_selected(GHE_BIG_PERF_SCHED_CYCLES);
    big_core_snapshot.check_cycles =
        ghe_perf_read_selected(GHE_BIG_PERF_CHECK_CYCLES);
    big_core_snapshot.other_thread_cycles =
        ghe_perf_read_selected(GHE_BIG_PERF_OTHER_THREAD);
    big_core_snapshot.all_busy_cycles =
        ghe_perf_read_selected(GHE_BIG_PERF_ALL_BUSY);
    big_core_snapshot.scheduler_other_cycles =
        ghe_perf_read_selected(GHE_BIG_PERF_SCHED_OTHER);

    big_core_snapshot.valid = 1;
}

static void print_big_core_snapshot(void)
{
    if (!big_core_snapshot.valid) {
        printf("[BOOM_GHE_PERF] snapshot=not-ready\r\n");
        return;
    }

    printf("[BOOM_GHE_PERF] elapsed=%" PRIu64
           " scheduler_blocked=%" PRIu64
           " scheduler=%" PRIu64 " check=%" PRIu64 "\r\n",
           big_core_snapshot.elapsed_cycles,
           big_core_snapshot.scheduler_blocked,
           big_core_snapshot.scheduler_cycles,
           big_core_snapshot.check_cycles);
    printf("[BOOM_GHE_PERF] other_thread=%" PRIu64
           " all_busy=%" PRIu64 " scheduler_other=%" PRIu64 "\r\n",
           big_core_snapshot.other_thread_cycles,
           big_core_snapshot.all_busy_cycles,
           big_core_snapshot.scheduler_other_cycles);
}
#endif

#if MEEK_ENABLE_CHECKER_PERF
static int checker_index(uint64_t hart_id)
{
    if (hart_id < TEST_FIRST_CHECKER_HART_ID ||
        hart_id > TEST_LAST_CHECKER_HART_ID) {
        return -1;
    }
    return (int)(hart_id - TEST_FIRST_CHECKER_HART_ID);
}

void performance_begin_checker(void)
{
    uint64_t hart_id = current_hart_id();
    int index = checker_index(hart_id);
    if (index < 0) {
        return;
    }

    checker_snapshots[index].valid = 0;
    ghe_perf_reset();
}

void performance_end_checker(void)
{
    uint64_t hart_id = current_hart_id();
    int index = checker_index(hart_id);
    volatile checker_snapshot_t *snapshot;
    if (index < 0) {
        return;
    }
    snapshot = &checker_snapshots[index];

    snapshot->checking_cycles =
        ghe_perf_read_selected(GHE_CHECKER_PERF_CHECKING);
    snapshot->postchecking_cycles =
        ghe_perf_read_selected(GHE_CHECKER_PERF_POSTCHECKING);
    snapshot->other_thread_cycles =
        ghe_perf_read_selected(GHE_CHECKER_PERF_OTHER_THREAD);
    snapshot->nonchecking_cycles =
        ghe_perf_read_selected(GHE_CHECKER_PERF_NONCHECKING);
    snapshot->checkpoints =
        ghe_perf_read_selected(GHE_CHECKER_PERF_CHECKPOINTS);
    snapshot->checkpoint_transfer_cycles =
        ghe_perf_read_selected(GHE_CHECKER_PERF_CPS_TRANSFER);
    snapshot->worst_check_latency =
        ghe_perf_read_selected(GHE_CHECKER_PERF_WORST_LATENCY);
    snapshot->replay_stores =
        ghe_perf_read_selected(GHE_CHECKER_PERF_STORES);
    snapshot->replay_loads =
        ghe_perf_read_selected(GHE_CHECKER_PERF_LOADS);

    snapshot->valid = 1;
}

void performance_report_checkers(void)
{
    /* Pair with the fence preceding each checker's store_stats ready flag. */
    asm volatile("fence rw, rw" ::: "memory");
    lock_acquire(&uart_lock);
    for (uint32_t index = 0; index < TEST_NUM_CHECKERS; ++index) {
        uint64_t hart_id = TEST_FIRST_CHECKER_HART_ID + index;
        volatile checker_snapshot_t *snapshot = &checker_snapshots[index];

        if (!snapshot->valid) {
            printf("[CHECKER_GHE_PERF] hart=%" PRIu64
                   " snapshot=not-ready\r\n", hart_id);
            continue;
        }

        printf("[CHECKER_GHE_PERF] hart=%" PRIu64
               " checking=%" PRIu64 " postchecking=%" PRIu64
               " other_thread=%" PRIu64 " nonchecking=%" PRIu64 "\r\n",
               hart_id, snapshot->checking_cycles,
               snapshot->postchecking_cycles, snapshot->other_thread_cycles,
               snapshot->nonchecking_cycles);
        printf("[CHECKER_GHE_PERF] hart=%" PRIu64
               " checkpoints=%" PRIu64 " cps_transfer=%" PRIu64
               " worst_latency=%" PRIu64 " stores=%" PRIu64
               " loads=%" PRIu64 "\r\n",
               hart_id, snapshot->checkpoints,
               snapshot->checkpoint_transfer_cycles,
               snapshot->worst_check_latency, snapshot->replay_stores,
               snapshot->replay_loads);
    }
    lock_release(&uart_lock);
}
#endif

void performance_report(uint64_t cycle_start, uint64_t cycle_end,
                        uint64_t instruction_start,
                        uint64_t instruction_end)
{
    lock_acquire(&uart_lock);
    printf("CPU execution took %" PRIu64 " cycles\n",
           cycle_end - cycle_start);
    printf("Boom-Perf: CSR execution-inst = %" PRIu64 " \r\n",
           instruction_end - instruction_start);
#if MEEK_ENABLE_BIG_CORE_PERF
    print_big_core_snapshot();
#endif
    lock_release(&uart_lock);
}
