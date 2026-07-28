/**
 * @file store_stats.h
 * @brief Cross-hart Storecount and Storecyclesum collection.
 *
 * Each hart publishes its local GHE store counters exactly once after its
 * assigned work has completed.  Hart 0 waits for those publications and
 * prints one report for the complete BOOM/Rocket group.
 */

#ifndef TEST_STORE_STATS_H
#define TEST_STORE_STATS_H

#include <stdint.h>

/** Read and publish one hart's local store counters to shared memory. */
void store_stats_publish(uint64_t hart_id);

/**
 * Wait until all configured harts have published their store counters.
 *
 * @return 1 if every hart is ready, or 0 after the configured timeout.
 */
int store_stats_wait_all(void);

/**
 * Print every hart's Storecount/Storecyclesum and the derived Cycle Avg.
 * The caller must hold uart_lock so the multi-line report is not interleaved.
 */
void store_stats_print_report(int all_ready);

#endif /* TEST_STORE_STATS_H */
