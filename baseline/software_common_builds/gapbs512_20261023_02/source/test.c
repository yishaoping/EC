#include <inttypes.h>
#include <stdio.h>

#include "cfg/init.h"
#include "cfg/config.h"
#include "hw/cycle.h"
#include "hw/ghe.h"
#include "hw/ght.h"
#include "hw/interrupt.h"
#include "hw/rocc.h"
#include "hw/spin_lock.h"
#include "stat/report.h"
#include "Benchmark/gapbs/gapbs_bfs.h"
#include "bench/stage1_amo.h"

/* A finite HTIF exit lets L1 drain. libgloss's repeated tohost/fromhost
 * stores create new work after the host has already observed success. */
extern volatile uint64_t tohost;
extern volatile uint64_t fromhost;
void __attribute__((noreturn, noinline)) _exit(int code)
{
    __asm__ volatile("csrci mstatus, 8" ::: "memory");
    fromhost = 0;
    tohost = (((uint64_t)(unsigned int)code << 1) | 1) & ((1ULL << 48) - 1);
    __asm__ volatile("fence rw,rw\n1: j 1b" ::: "memory");
    __builtin_unreachable();
}

/* Shared GHT, interrupt, privilege, and timer setup. */
static uint64_t test_setup(void)
{
    r_ini(NUM_CHECKERS);
    csr_software_cfg();
    msip_cfg();

    lock_acquire(&uart_lock);
    printf("[INIT] software_interrupt=pass\n");
    lock_release(&uart_lock);

    while (ght_get_initialisation() == 0) {
    }

    uint64_t hart_id = 0;
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));
    lock_acquire(&uart_lock);
    printf("[RUN] hart=%lx status=started\n", hart_id);
    printf("[CONFIG] common_abi=1 harts=5 timer_stride=64 legacy_readback=off\n");
    lock_release(&uart_lock);

    ght_set_satp_priv();
    mtimecmp_cfg();
    csr_timer_cfg();
    ghe_common_observer_init();
    ghe_common_observer_start();
    return hart_id;
}

/* 执行下方 [BENCHMARK SIZE] 选择的 GAPBS 节点规模。 */
static void gapbs_bfs(uint64_t hart_id, uint64_t *start_cpu,
                      uint64_t *end_cpu, gapbs_bfs_result_t *result)
{
    ROCC_INSTRUCTION(1, 0x31);
    ROCC_INSTRUCTION_S(1, 0X01, 0x70);

    __asm__ volatile(".global common_roi_start\ncommon_roi_start:\nrdcycle %0"
                     : "=r"(*start_cpu) : : "memory");
    int amo_ok = stage1_amo_w_test();
    (void)hart_id;
    /*
     * [BENCHMARK SIZE]
     * 修改这一行即可切换规模：gapbs_bfs_run_14、_512、_1024、_2048、_4096。
     */
    gapbs_bfs_run_512(result);
    result->verified = result->verified && amo_ok;

    ROCC_INSTRUCTION_S(1, 0X02, 0x70);
    for (int nop_count = 0; nop_count < 26; nop_count++) {
        __asm__ volatile("nop");
    }
    ROCC_INSTRUCTION(1, 0x32);

    uint64_t status;
    while ((status = ght_get_status()) < 0x1FFFF) {
    }
    __asm__ volatile(".global common_roi_stop\ncommon_roi_stop:\nrdcycle %0"
                     : "=r"(*end_cpu) : : "memory");
}

/* Report computation and ROI after the stop sample, then notify HTIF. */
static int test_report(uint64_t hart_id, uint64_t start_cpu,
                        uint64_t end_cpu, const gapbs_bfs_result_t *result)
{
    lock_acquire(&uart_lock);
    printf("[RUN] benchmark=gapbs_bfs nodes=%" PRIu32 " source=%" PRIu32
           " reached=%" PRIu32 " edges=%" PRIu32
           " verified=%" PRIu32 " parent_checksum=%" PRIu64 "\n",
           result->node_count, result->source, result->reached_nodes,
           result->traversed_edges, result->verified, result->parent_checksum);
    lock_release(&uart_lock);
    int report_ok = report_end(start_cpu, end_cpu, hart_id) &&
                    result->verified == 1 && result->node_count == 512 &&
                    result->source == 0 && result->reached_nodes == 512 &&
                    result->traversed_edges == 8192;
    lock_acquire(&uart_lock);
    printf("[COMPUTATION] status=%s scope=amo_w_and_bfs_result\n",
           report_ok ? "PASS" : "FAIL");
    printf("[END] hart=%lx status=%s\n", hart_id,
           report_ok ? "PASS" : "FAIL");
    lock_release(&uart_lock);
    ght_unset_satp_priv();
    ROCC_INSTRUCTION(1, 0x30);
    return report_ok;
}

int main(void)
{
    uint64_t hart_id = test_setup();
    uint64_t start_cpu = 0;
    uint64_t end_cpu = 0;
    gapbs_bfs_result_t result = {0};
    gapbs_bfs(hart_id, &start_cpu, &end_cpu, &result);
    return test_report(hart_id, start_cpu, end_cpu, &result) ? 0 : 1;
}
