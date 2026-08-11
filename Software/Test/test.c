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
#define NUM_HARTS (NUM_CHECKERS + 1)

uint64_t csr_read_s[TOTAL_CSR_PERF];
uint64_t csr_read_e[TOTAL_CSR_PERF];
/* 每个 hart 保存自己的流量计数器，hart 0 负责最后统一打印。 */
volatile uint64_t hart_traffic[NUM_HARTS][GHE_TRAFFIC_COUNTERS];
/* hart 1--4 完成统计读取后分别置位，避免改动原有 GHT 等待逻辑。 */
volatile uint32_t hart_traffic_ready[NUM_HARTS];

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
        for (int i = 0; i < 3; i++) {
            e = i * 1.2 + 3;
            b = j + 1.7;
            a = (e + b) * 2.2;
            asm volatile("csrr %0, cycle" : "=r"(CSR));
            asm volatile("csrr %0, instret" : "=r"(CSR));
            asm volatile("csrr %0, mhartid" : "=r"(Hart_id));
            a = a + CSR;
            __asm__ volatile("ecall");
            if (a > Hart_id) {
                /* Keep the register-carrying microbenchmark in one asm block. */
                __asm__ volatile(
                    "li   t0, 0x81000000\n"
                    "li   t1, 0x55552000\n"
                    "li   t2, 0x55553000\n"
                    "1:\n"
                    "li   a5, 0x810008FF\n"
                    "lr.w a0, (t0)\n"
                    "sc.w a0, t1, (t0)\n"
                    "sd   t1, 0(t0)\n"
                    "sd   t2, 16(t0)\n"
                    "sd   t1, 32(t0)\n"
                    "sd   t2, 64(t0)\n"
                    "divw t3, t1, t2\n"
                    "addi t0, t0, 0x10\n"
                    "frflags a3\n"
                    "fsflags a3\n"
                    "csrrc a3, fflags, a3\n"
                    "csrrwi a3, frm, 0x3\n"
                    "csrrsi a3, fflags, 0x1F\n"
                    "csrrci a3, fflags, 0x0F\n"
                    "blt  t0, a5, 1b\n"
                    "li   t0, 0x81000000\n"
                    "2:\n"
                    "li   a5, 0x810008FF\n"
                    "lr.w a0, (t0)\n"
                    "sc.w a0, t1, (t0)\n"
                    "ld   t1, 0(t0)\n"
                    "ld   t2, 16(t0)\n"
                    "ld   t1, 32(t0)\n"
                    "ld   t2, 64(t0)\n"
                    "mulw t3, t1, t2\n"
                    "divw t3, t1, t2\n"
                    "frflags a3\n"
                    "li   a3, 0x55\n"
                    "fsflags a3\n"
                    "divu t2, t2, t1\n"
                    "addi t0, t0, 0x10\n"
                    "blt  t0, a5, 2b\n"
                    "li   t0, 0x81000000\n"
                    "li   t1, 0x81000100\n"
                    "li   t2, 1\n"
                    "3:\n"
                    "li   a5, 0x810008FF\n"
                    "amoadd.w.aq t1, t2, (t0)\n"
                    "addi t2, t2, 0x01\n"
                    "addi t0, t0, 0x10\n"
                    "blt  t0, a5, 3b\n"
                    :
                    :
                    : "a0", "a3", "a5", "t0", "t1", "t2", "t3", "memory");
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

    /* hart 0 直接把本地流量计数器写入自己的统计行。 */
    for (int counter = 0; counter < GHE_TRAFFIC_COUNTERS; counter++) {
        hart_traffic[0][counter] = ghe_traffic_counter_read(counter);
    }
    /* GHT 同步完成后，再独立等待各 checker 的统计读取完成。 */
    while (hart_traffic_ready[1] == 0 || hart_traffic_ready[2] == 0 ||
           hart_traffic_ready[3] == 0 || hart_traffic_ready[4] == 0) {
    }
    __sync_synchronize();

    lock_acquire(&uart_lock);
    printf("CPU execution took %" PRIu64 " cycles\n", end_cpu - start_cpu);
    lock_release(&uart_lock);

    lock_acquire(&uart_lock);
    printf("Boom-Perf: CSR execution-inst = %" PRIu64 " \r\n",
           csr_read_e[0] - csr_read_s[0]);
    for (int hart = 0; hart < NUM_HARTS; hart++) {
        printf("hart%d traffic: store_out=%" PRIu64
               " store_cache=%" PRIu64 " store_uncache=%" PRIu64 "\r\n",
               hart, hart_traffic[hart][GHE_TRAFFIC_STORE_TOTAL],
               hart_traffic[hart][GHE_TRAFFIC_STORE_CACHE],
               hart_traffic[hart][GHE_TRAFFIC_STORE_UNCACHE]);
        printf("hart%d traffic: load_out=%" PRIu64
               " load_cache=%" PRIu64 " load_uncache=%" PRIu64
               " load_forward=%" PRIu64 "\r\n",
               hart, hart_traffic[hart][GHE_TRAFFIC_LOAD_TOTAL],
               hart_traffic[hart][GHE_TRAFFIC_LOAD_CACHE],
               hart_traffic[hart][GHE_TRAFFIC_LOAD_UNCACHE],
               hart_traffic[hart][GHE_TRAFFIC_LOAD_FORWARD]);
        printf("hart%d traffic: lr_out=%" PRIu64
               " sc_success=%" PRIu64 " sc_fail=%" PRIu64 "\r\n",
               hart, hart_traffic[hart][GHE_TRAFFIC_LR],
               hart_traffic[hart][GHE_TRAFFIC_SC_SUCCESS],
               hart_traffic[hart][GHE_TRAFFIC_SC_FAIL]);
        printf("hart%d traffic: amo_out=%" PRIu64
               " amo_cache=%" PRIu64 " amo_uncache=%" PRIu64 "\r\n",
               hart, hart_traffic[hart][GHE_TRAFFIC_AMO_TOTAL],
               hart_traffic[hart][GHE_TRAFFIC_AMO_CACHE],
               hart_traffic[hart][GHE_TRAFFIC_AMO_UNCACHE]);
        if (hart == 0) {
            printf("hart0 dcache traffic: l1_l2_wb_total=%" PRIu64
                   " l1_l2_wb_dirty=%" PRIu64 "\r\n",
                   hart_traffic[hart][GHE_TRAFFIC_L1_L2_WB_TOTAL],
                   hart_traffic[hart][GHE_TRAFFIC_L1_L2_WB_DIRTY]);
        }
    }
    printf("shared dcache traffic: l2_dram_wb_total=%" PRIu64
           " l2_dram_wb_dirty=%" PRIu64 "\r\n",
           hart_traffic[0][GHE_TRAFFIC_L2_DRAM_WB_TOTAL],
           hart_traffic[0][GHE_TRAFFIC_L2_DRAM_WB_DIRTY]);
    printf("[Boom-C%lx]: Test is now completed. \r\n", Hart_id);
    lock_release(&uart_lock);

    ght_unset_satp_priv();
    ROCC_INSTRUCTION(1, 0x30);
    return 0;
}
