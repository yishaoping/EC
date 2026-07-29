/**
 * @file tasks.c
 * @brief Rocket checker control loop for checkpoint-and-replay validation.
 */

#include "tasks.h"

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#include "clint.h"
#include "ghe.h"
#include "ght.h"
#include "performance.h"
#include "rocc.h"
#include "spin_lock.h"
#include "store_stats.h"
#include "test_config.h"

int checker(uint64_t hart_id)
{
    /* Put the local GHE into receiver mode and announce checker readiness. */
    ghe_asR();
    ght_set_satp_priv();
    ghe_go();
    ghe_initailised(1);

#if MEEK_ENABLE_CHECKER_PERF
    performance_begin_checker();
#endif

    /* Capture the checker context, import BOOM's checkpoint, and record PC. */
    ROCC_INSTRUCTION(1, 0x75);
    ROCC_INSTRUCTION(1, 0x73);
    ROCC_INSTRUCTION(1, 0x64);

    /* Drain any mismatches already queued by the two ELU instances. */
    for (uint32_t elu = 0; elu < TEST_CHECKER_ELU_COUNT; ++elu) {
        ROCC_INSTRUCTION_S(1, elu, 0x65);
        while (elu_checkstatus() != 0U) {
            lock_acquire(&uart_lock);
            printf("C%" PRIx64 ": Error detected for ELU %" PRIx32 ".\r\n",
                   hart_id, elu);
            lock_release(&uart_lock);
            ROCC_INSTRUCTION_S(1, elu, 0x63);
        }
    }

    /*
     * Wait for a replay window.  RSU status 0x08 means the checkpoint is
     * ready: funct 0x60 installs it and custom3 jumps to the restored PC.
     */
    while (ghe_checkght_status() != TEST_CHECKER_COMPLETE_STATUS) {
        if ((ghe_rsur_status() & UINT64_C(0x18)) == UINT64_C(0x08)) {
            ROCC_INSTRUCTION(1, 0x60);
            R_INSTRUCTION_JLR(3, 0x00);
        }
    }

#if MEEK_ENABLE_CHECKER_PERF
    performance_end_checker();
#endif

    /* Save the checker endpoint and ask RSU/ELU to perform final comparison. */
    ROCC_INSTRUCTION(1, 0x72);
    ROCC_INSTRUCTION(1, 0x60);
    asm volatile(".rept 5\n\tnop\n\t.endr" ::: "memory");

    while (ghe_checkght_status() != TEST_CHECKER_COMPLETE_STATUS) {
    }

    /*
     * Checkpoint restore may have replaced the register holding hart_id with
     * BOOM's saved value.  Re-read mhartid before indexing the shared result.
     */
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));
    store_stats_publish(hart_id);

    /*
     * Do not print on a checker: GHT completion requires every release event,
     * so a slow HTIF/UART printf here would keep BOOM in its status poll and
     * the other checkers spinning on uart_lock.  Hart 0 prints the snapshots
     * after observing every store_stats ready flag.
     */
    ghe_release();
    ght_unset_satp_priv();

    /* A checker hart must never fall through into an unrelated runtime path. */
    idle();
    return 0;
}
