/**
 * @file tasks.h
 * @brief Rocket checker task entry.
 */

#ifndef TEST_TASKS_H
#define TEST_TASKS_H

#include <stdint.h>

/** Run the hardware-assisted replay loop; this function does not return. */
int checker(uint64_t hart_id);

#endif /* TEST_TASKS_H */
