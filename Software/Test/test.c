#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#include "checker_config.h"
#include "cycle.h"
#include "ghe.h"
#include "ght.h"
#include "interrupt.h"
#include "rocc.h"
#include "spin_lock.h"
#include "test_config.h"

#define TOTAL_CSR_PERF 84

uint64_t csr_read_s[TOTAL_CSR_PERF];
uint64_t csr_read_e[TOTAL_CSR_PERF];

int main(void)
{
    r_ini(NUM_CHECKERS);
    csr_software_cfg();
    msip_cfg();

    lock_acquire(&uart_lock);
    printf("Software interrupt test complete!\n");
    lock_release(&uart_lock);

    while (ght_get_initialisation() == 0) {
    }

    uint64_t Hart_id = 0;
    asm volatile("csrr %0, mhartid" : "=r"(Hart_id));
    lock_acquire(&uart_lock);
    printf("[Boom-C%lx]: Test is now started: \r\n", Hart_id);
    printf("[MEEK_PERF_CFG] big=%d checker=%d interval=%" PRIu64
           " checker_limit=2000\r\n",
           MEEK_ENABLE_BIG_CORE_PERF, MEEK_ENABLE_CHECKER_SEGMENT_PERF,
           (uint64_t)FPGA_PERF_INTERVAL_CYCLES);
    lock_release(&uart_lock);

    csr_read_s[0] = ghe_csr_perf_read(0);

    ght_set_satp_priv();
    mtimecmp_cfg();
    csr_timer_cfg();

    ROCC_INSTRUCTION(1, 0x31);
    ROCC_INSTRUCTION_S(1, 0X01, 0x70);

    uint64_t start_cpu = read_cycles();
    float a = 0.1;
    float b = 0.2;
    float c = 0.3;
    float d = (a + b + c) * 1.7 * 3.2;

    uint64_t CSR = 0;
    asm volatile("csrr %0, cycle" : "=r"(CSR));
    asm volatile("csrr %0, instret" : "=r"(CSR));
    asm volatile("csrr %0, mhartid" : "=r"(Hart_id));

    double e = (c - b + a) * 1.1;
    double f = ((e + d) * (d - b)) / 2.1;
    double g = (c + 1.1) / 2;
    double h = a - 0.05;
    double i = f + 1.1;
    double j = a + b + c + d + e + f + g + h + i;

    if ((j * Hart_id) == 0) {
        for (int i; i < 3; i++) {
            e = i * 1.2 + 3;
            b = j + 1.7;
            a = (e + b) * 2.2;
            asm volatile("csrr %0, cycle" : "=r"(CSR));
            asm volatile("csrr %0, instret" : "=r"(CSR));
            asm volatile("csrr %0, mhartid" : "=r"(Hart_id));
            a = a + CSR;
            __asm__ volatile("ecall");
            if (a > Hart_id) {
                __asm__ volatile(
                    "li   t0,   0x81000000;"
                    "li   t1,   0x55552000;"
                    "li   t2,   0x55553000;"
                    "j    .loop_store1;");

                __asm__ volatile(
                    ".loop_store1:"
                    "li   a5,   0x810008FF;"
                    "lr.w a0,   (t0);"
                    "sc.w a0,   t1,   (t0);"
                    "sd         t1,   (t0);"
                    "sd         t2,   16(t0);"
                    "sd         t1,   32(t0);"
                    "sd         t2,   64(t0);"
                    "divw       t3,   t1, t2;"
                    "addi t0,   t0,   0x10;"
                    "frflags    a3;"
                    "fsflags    a3;"
                    "csrrc  a3, fflags, a3;"
                    "csrrwi a3, frm, 0x3;"
                    "csrrsi a3, fflags, 0x1F;"
                    "csrrci a3, fflags, 0x0F;"
                    "blt  t0,   a5,  .loop_store1;");

                __asm__ volatile(
                    "li   t0,   0x81000000;"
                    "j    .loop_load1;");

                __asm__ volatile(
                    ".loop_load1:"
                    "li   a5,   0x810008FF;"
                    "lr.w a0,   (t0);"
                    "sc.w a0,   t1,   (t0);"
                    "ld         t1,   (t0);"
                    "ld         t2,   16(t0);"
                    "ld         t1,   32(t0);"
                    "ld         t2,   64(t0);"
                    "mulw       t3,   t1, t2;"
                    "divw       t3,   t1, t2;"
                    "frflags    a3;"
                    "li         a3,   0x55;"
                    "fsflags    a3;"
                    "divu       t2,t2,t1;"
                    "addi t0,   t0,   0x10;"
                    "blt  t0,   a5,  .loop_load1;");

                __asm__ volatile(
                    "li   t0,   0x81000000;"
                    "li   t1,   0x81000100;"
                    "li   t2,   1;"
                    "j    .loop_add1;");

                __asm__ volatile(
                    ".loop_add1:"
                    "li   a5,   0x810008FF;"
                    "amoadd.w.aq t1,   t2, (t0);"
                    "addi t2,   t2,   0x01;"
                    "addi t0,   t0,   0x10;"
                    "blt  t0,   a5,  .loop_add1;");
            }
        }
    }

    ROCC_INSTRUCTION_S(1, 0X02, 0x70);
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    ROCC_INSTRUCTION(1, 0x32);

    csr_read_e[0] = ghe_csr_perf_read(0);

    uint64_t status;
    while ((status = ght_get_status()) < 0x1FFFF) {
    }

    uint64_t end_cpu = read_cycles();

    lock_acquire(&uart_lock);
    printf("CPU execution took %" PRIu64 " cycles\n", end_cpu - start_cpu);
    lock_release(&uart_lock);

    lock_acquire(&uart_lock);
    printf("Boom-Perf: CSR execution-inst = %" PRIu64 " \r\n",
           csr_read_e[0] - csr_read_s[0]);
    printf("[Boom-C%lx]: Test is now completed. \r\n", Hart_id);
    lock_release(&uart_lock);

    ght_unset_satp_priv();
    ROCC_INSTRUCTION(1, 0x30);
    return 0;
}
