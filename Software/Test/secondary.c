#include <stdint.h>

#include "checker.h"
#include "interrupt.h"

void idle(void)
{
    while (1) {
    }
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
        break;
    case 0x02:
        csr_software_cfg();
        msip_cfg();
        mtimecmp_cfg();
        csr_timer_cfg();
        checker(Hart_id);
        break;
    case 0x03:
        csr_software_cfg();
        msip_cfg();
        mtimecmp_cfg();
        csr_timer_cfg();
        checker(Hart_id);
        break;
    case 0x04:
        checker(Hart_id);
        break;
    default:
        break;
    }

    idle();
    return 0;
}
