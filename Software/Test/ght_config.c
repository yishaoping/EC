/**
 * @file ght_config.c
 * @brief Configure which BOOM commit events are replayed by Rocket checkers.
 */

#include "ght_config.h"

#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "clint.h"
#include "ght.h"
#include "spin_lock.h"
#include "test_config.h"

static void configure_standard_filters(void)
{
    static const uint8_t integer_load_functs[] = {
        0x00, 0x01, 0x02, 0x04, 0x05, 0x03, 0x06,
    };
    static const uint8_t fp_load_functs[] = {0x02, 0x03, 0x04};
    static const uint8_t integer_store_functs[] = {0x00, 0x01, 0x02, 0x03};
    static const uint8_t fp_store_functs[] = {0x02, 0x03, 0x04};
    static const uint8_t csr_functs[] = {0x01, 0x02, 0x03, 0x05, 0x06, 0x07};

    for (size_t i = 0; i < sizeof(integer_load_functs); ++i) {
        ght_cfg_filter(GID_LOAD, integer_load_functs[i], OPCODE_LOAD,
                       DATA_FROM_LDQ);
    }
    for (size_t i = 0; i < sizeof(fp_load_functs); ++i) {
        ght_cfg_filter(GID_LOAD, fp_load_functs[i], OPCODE_FP_LOAD,
                       DATA_FROM_LDQ);
    }
    for (size_t i = 0; i < sizeof(integer_store_functs); ++i) {
        ght_cfg_filter(GID_STORE, integer_store_functs[i], OPCODE_STORE,
                       DATA_FROM_STQ);
    }
    for (size_t i = 0; i < sizeof(fp_store_functs); ++i) {
        ght_cfg_filter(GID_STORE, fp_store_functs[i], OPCODE_FP_STORE,
                       DATA_FROM_STQ);
    }
    for (size_t i = 0; i < sizeof(csr_functs); ++i) {
        ght_cfg_filter(GID_CSR, csr_functs[i], OPCODE_SYSTEM, DATA_FROM_PRF);
    }

    /* LR/SC and AMO events require both the memory and destination values. */
    ght_cfg_filter(GID_LOAD, 0x02, OPCODE_ATOMIC, DATA_FROM_STQ_AND_PRF);
    ght_cfg_filter(GID_LOAD, 0x03, OPCODE_ATOMIC, DATA_FROM_STQ_AND_PRF);
}

static void configure_compressed_filters(void)
{
    /*
     * The current -march does not emit RVC, but programming these filters
     * keeps the hardware table complete for binaries built with C later.
     */
    for (uint32_t msb = 0; msb <= 1; ++msb) {
        uint32_t gid = msb == 0 ? GID_LOAD : GID_STORE;
        uint32_t data_source = msb == 0 ? DATA_FROM_LDQ : DATA_FROM_STQ;

        for (uint32_t opcode = 0; opcode <= 2; opcode += 2) {
            for (uint32_t funct = 2; funct <= 7; ++funct) {
                ght_cfg_filter_rvc(gid, funct, opcode, msb, data_source);
            }
        }
    }
}

void ght_configure(uint32_t num_checkers)
{
    ght_set_numberofcheckers(num_checkers);
    configure_standard_filters();
    configure_compressed_filters();

    /* SE n is dedicated to checker hart n+1 in this four-checker topology. */
    for (uint32_t checker = 0; checker < num_checkers; ++checker) {
        uint32_t hart_id = checker + 1U;
        ght_cfg_se(checker, hart_id, SE_POLICY_ROUND_ROBIN, hart_id);
        r_set_corex_p_s(hart_id);
    }

    ght_debug_filter_width(0);

    lock_acquire(&uart_lock);
    printf("R: Activated checker count set to %" PRIu32 "\r\n",
           num_checkers);
    printf("R: Initialisation is completed!\r\n");
    lock_release(&uart_lock);
}
