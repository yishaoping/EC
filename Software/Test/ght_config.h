/**
 * @file ght_config.h
 * @brief Guardian Heart Table filter, scheduler, and checker routing setup.
 */

#ifndef TEST_GHT_CONFIG_H
#define TEST_GHT_CONFIG_H

#include <stdint.h>

/* GHT packet fields used by the filter table in ght_config.c. */
enum ght_filter_config {
    GID_LOAD = 0x01,
    GID_STORE = 0x02,
    GID_CSR = 0x03,
    OPCODE_LOAD = 0x03,
    OPCODE_FP_LOAD = 0x07,
    OPCODE_STORE = 0x23,
    OPCODE_FP_STORE = 0x27,
    OPCODE_SYSTEM = 0x73,
    OPCODE_ATOMIC = 0x2f,
    DATA_FROM_PRF = 0x01,
    DATA_FROM_LDQ = 0x02,
    DATA_FROM_STQ = 0x03,
    DATA_FROM_STQ_AND_PRF = 0x05,
    SE_POLICY_ROUND_ROBIN = 0x01,
};

void ght_configure(uint32_t num_checkers);

#endif /* TEST_GHT_CONFIG_H */
