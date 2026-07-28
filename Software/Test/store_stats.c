/**
 * @file store_stats.c
 * @brief GHE store-counter snapshots and cross-hart result publication.
 *
 * GHE funct 0x79 exposes two free-running 128-bit values local to each hart:
 * Storecount and Storecyclesum.  Every checker publishes its endpoint after
 * final comparison; BOOM publishes after the global GHT completion status.
 * A release/acquire-style fence protocol prevents hart 0 from observing a
 * ready flag before the associated counter words are visible.
 */

#include "store_stats.h"

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#include "ghe.h"
#include "test_config.h"

typedef unsigned __int128 store_uint128_t;

typedef struct {
    uint64_t low;
    uint64_t high;
} store_counter128_t;

/*
 * These arrays reside in shared memory.  A producer writes both result arrays,
 * executes a full fence, and only then sets its ready slot.  Volatile keeps
 * every polling access and publication visible at the C abstract-machine level.
 */
static volatile uint64_t storecount_results[TEST_NUM_HARTS];
static volatile store_uint128_t cyclesum_ns_results[TEST_NUM_HARTS];
static volatile uint32_t store_stats_ready[TEST_NUM_HARTS];

/** Read the local cycle CSR for the bounded hart-0 wait loop. */
static uint64_t read_cycles(void)
{
    uint64_t cycles;
    asm volatile("rdcycle %0" : "=r"(cycles));
    return cycles;
}

/**
 * Read a coherent 128-bit free-running counter.
 *
 * The low word can wrap while two RoCC reads are in flight.  Reading
 * high-low-high and retrying when the high words differ avoids combining a
 * pre-wrap high word with a post-wrap low word.
 */
static store_counter128_t read_counter128(uint64_t low_selector,
                                          uint64_t high_selector)
{
    store_counter128_t value;
    uint64_t high_after;

    do {
        value.high = ghe_store_counter_read(high_selector);
        value.low = ghe_store_counter_read(low_selector);
        high_after = ghe_store_counter_read(high_selector);
    } while (value.high != high_after);

    value.high = high_after;
    return value;
}

static store_uint128_t counter128_to_uint128(store_counter128_t value)
{
    return ((store_uint128_t)value.high << 64) | value.low;
}

/** Return the configured clock for the selected hart's hardware counter. */
static uint32_t hart_clock_mhz(uint64_t hart_id)
{
    return hart_id == TEST_BIG_CORE_HART_ID
               ? TEST_BIG_CORE_CLOCK_MHZ
               : TEST_CHECKER_CLOCK_MHZ;
}

/** Convert hardware cycles to ns using cycles * 1000 / frequency_MHz. */
static store_uint128_t cycles_to_ns(store_counter128_t cycle_sum,
                                    uint64_t hart_id)
{
    store_uint128_t cycles = counter128_to_uint128(cycle_sum);
    return (cycles * (store_uint128_t)1000U) / hart_clock_mhz(hart_id);
}

void store_stats_publish(uint64_t hart_id)
{
    store_counter128_t count;
    store_counter128_t cycle_sum;

    if (hart_id >= TEST_NUM_HARTS) {
        return;
    }

    /* Snapshot hardware before the shared-result stores affect local counts. */
    count = read_counter128(GHE_STORE_COUNT_LO_SELECTOR,
                            GHE_STORE_COUNT_HI_SELECTOR);
    cycle_sum = read_counter128(GHE_STORE_CYCLE_SUM_LO_SELECTOR,
                                GHE_STORE_CYCLE_SUM_HI_SELECTOR);

    /* Match the reference report, whose Storecount field is the low 64 bits. */
    storecount_results[hart_id] = count.low;
    cyclesum_ns_results[hart_id] = cycles_to_ns(cycle_sum, hart_id);

    asm volatile("fence rw, rw" ::: "memory");
    store_stats_ready[hart_id] = 1U;
    asm volatile("fence rw, rw" ::: "memory");
}

/** Check all ready flags, then acquire visibility of the published data. */
static int all_harts_ready(void)
{
    for (uint32_t hart_id = 0; hart_id < TEST_NUM_HARTS; ++hart_id) {
        if (store_stats_ready[hart_id] == 0U) {
            return 0;
        }
    }

    asm volatile("fence rw, rw" ::: "memory");
    return 1;
}

int store_stats_wait_all(void)
{
    uint64_t wait_start = read_cycles();

    while (!all_harts_ready()) {
        if ((read_cycles() - wait_start) > TEST_STORECOUNT_WAIT_CYCLES) {
            return 0;
        }
    }

    return 1;
}

/** Print an unsigned 128-bit value without relying on a nonstandard format. */
static void print_uint128(store_uint128_t value)
{
    char buffer[40];
    int index = (int)sizeof(buffer) - 1;

    buffer[index] = '\0';
    if (value == 0) {
        printf("0");
        return;
    }

    while (value != 0 && index > 0) {
        buffer[--index] = (char)('0' + (value % 10U));
        value /= 10U;
    }
    printf("%s", &buffer[index]);
}

void store_stats_print_report(int all_ready)
{
    store_uint128_t checker_cycle_sum = 0;
    store_uint128_t cycle_sum;
    store_uint128_t cycle_average = 0;

    for (uint32_t hart_id = 0; hart_id < TEST_NUM_HARTS; ++hart_id) {
        if (store_stats_ready[hart_id] != 0U) {
            printf("Storecount[%" PRIu32 "] = %" PRIu64 " \r\n",
                   hart_id, storecount_results[hart_id]);
            printf("Cyclesum[%" PRIu32 "] = ", hart_id);
            print_uint128(cyclesum_ns_results[hart_id]);
            printf(" ns \r\n");
        } else {
            printf("Storecount[%" PRIu32 "] = not-ready \r\n", hart_id);
            printf("Cyclesum[%" PRIu32 "] = not-ready \r\n", hart_id);
        }
    }

    for (uint32_t hart_id = TEST_FIRST_CHECKER_HART_ID;
         hart_id < TEST_NUM_HARTS; ++hart_id) {
        checker_cycle_sum += cyclesum_ns_results[hart_id];
    }

    /*
     * Preserve the reference experiment's definition:
     *   (sum of checker Storecyclesum in ns - BOOM Storecyclesum in ns)
     *   / BOOM Storecount.
     * This is a cross-core derived metric, not a generic store latency.
     */
    cycle_sum = checker_cycle_sum > cyclesum_ns_results[TEST_BIG_CORE_HART_ID]
                    ? checker_cycle_sum -
                          cyclesum_ns_results[TEST_BIG_CORE_HART_ID]
                    : 0;
    if (all_ready && storecount_results[TEST_BIG_CORE_HART_ID] != 0U) {
        cycle_average =
            cycle_sum / storecount_results[TEST_BIG_CORE_HART_ID];
    }

    printf("Cycle Avg:");
    print_uint128(cycle_average);
    printf(" ns \r\n");
}
