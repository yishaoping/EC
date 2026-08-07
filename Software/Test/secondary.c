#include <stdint.h>

#include "checker.h"
#include "ghe.h"
#include "interrupt.h"
#include "test_config.h"

#define TRAFFIC_COUNTERS 7
#define NUM_HARTS (NUM_CHECKERS + 1)

extern volatile uint64_t hart_traffic[NUM_HARTS][TRAFFIC_COUNTERS];
extern volatile uint32_t hart_traffic_ready[NUM_HARTS];

void idle(void)
{
    while (1) {
    }
}

/* 每个 checker 只写自己的统计和 ready 槽，避免并发写入互相覆盖。 */
static void save_checker_traffic(uint64_t hart_id)
{
    if (hart_id >= NUM_HARTS) {
        return;
    }

    for (int counter = 0; counter < TRAFFIC_COUNTERS; counter++) {
        hart_traffic[hart_id][counter] = ghe_traffic_counter_read(counter);
    }
    __sync_synchronize();
    hart_traffic_ready[hart_id] = 1;
    idle();
}

int __main(void)
{
    uint64_t Hart_id = 0;
    asm volatile("csrr %0, mhartid" : "=r"(Hart_id));

    switch (Hart_id) {
    case 0x01:
        csr_software_cfg();
        msip_cfg();
        mtimecmp_cfg();
        csr_timer_cfg();
        checker(Hart_id);
        save_checker_traffic(Hart_id);
        break;
    case 0x02:
        csr_software_cfg();
        msip_cfg();
        mtimecmp_cfg();
        csr_timer_cfg();
        checker(Hart_id);
        save_checker_traffic(Hart_id);
        break;
    case 0x03:
        csr_software_cfg();
        msip_cfg();
        mtimecmp_cfg();
        csr_timer_cfg();
        checker(Hart_id);
        save_checker_traffic(Hart_id);
        break;
    case 0x04:
        checker(Hart_id);
        save_checker_traffic(Hart_id);
        break;
    default:
        break;
    }

    idle();
    return 0;
}
