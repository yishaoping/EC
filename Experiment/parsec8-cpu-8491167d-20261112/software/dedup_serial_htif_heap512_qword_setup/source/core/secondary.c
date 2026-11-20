#include <stdint.h>

#include "checker.h"
#include "../hw/ghe.h"
#include "../hw/interrupt.h"
#include "../cfg/config.h"

#include "../stat/report.h"

void idle(void)
{
    /* checker 完成后保持 hart 空闲，避免再次进入测试代码。 */
    while (1) {
    }
}

/* Preserve the completion store and fence; no statistics snapshot. */
static void publish_checker_completion(uint64_t hart_id)
{
    if (hart_id >= NUM_HARTS) {
        return;
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
        publish_checker_completion(Hart_id);
        break;
    case 0x02:
        csr_software_cfg();
        msip_cfg();
        mtimecmp_cfg();
        csr_timer_cfg();
        checker(Hart_id);
        publish_checker_completion(Hart_id);
        break;
    case 0x03:
        csr_software_cfg();
        msip_cfg();
        mtimecmp_cfg();
        csr_timer_cfg();
        checker(Hart_id);
        publish_checker_completion(Hart_id);
        break;
    case 0x04:
        checker(Hart_id);
        publish_checker_completion(Hart_id);
        break;
    default:
        break;
    }

    idle();
    return 0;
}
