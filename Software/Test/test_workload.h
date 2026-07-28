/**
 * @file test_workload.h
 * @brief Mixed BOOM instruction stream used to exercise checker replay.
 */

#ifndef TEST_WORKLOAD_H
#define TEST_WORKLOAD_H

#include <stdint.h>

/** Execute FP, CSR, trap, load/store, LR/SC, and AMO stimuli on hart 0. */
uint64_t test_run_workload(uint64_t hart_id);

#endif /* TEST_WORKLOAD_H */
