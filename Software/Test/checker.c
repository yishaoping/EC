#include "checker.h"

#include <stdio.h>

#include "ghe.h"
#include "ght.h"
#include "rocc.h"
#include "test_config.h"

int checker(int hart_id)
{
    ghe_asR();
    ght_set_satp_priv();
    ghe_go();
    ghe_initailised(1);

    ghe_fpga_perf_set_interval(FPGA_PERF_INTERVAL_CYCLES);
    ghe_fpga_perf_reset();
    ghe_fpga_perf_start();

    ROCC_INSTRUCTION(1, 0x75);
    ROCC_INSTRUCTION(1, 0x73);
    ROCC_INSTRUCTION(1, 0x64);
    for (int sel_elu = 0; sel_elu < 2; sel_elu++) {
        ROCC_INSTRUCTION_S(1, sel_elu, 0x65);

        while (elu_checkstatus() != 0) {
            printf("C%x: Error detected for ELU %x.\r\n", hart_id, sel_elu);
            ROCC_INSTRUCTION_S(1, sel_elu, 0x63);
        }
    }

    while (ghe_checkght_status() != 0x02) {
        if ((ghe_rsur_status() & 0x18) == 0x08) {
            ROCC_INSTRUCTION(1, 0x60);
            R_INSTRUCTION_JLR(3, 0x00);
        }
    }

    ghe_fpga_perf_stop();

    ROCC_INSTRUCTION(1, 0x72);
    ROCC_INSTRUCTION(1, 0x60);

    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");

    while (ghe_checkght_status() != 0x02) {
    }

    /* 先通知 GHT 当前 checker 已完成，避免统计读取阻塞完成同步。 */
    ghe_release();
    ght_unset_satp_priv();

    /* 返回 secondary.c，由当前 hart 读取并保存本地流量统计。 */
    return 0;
}
