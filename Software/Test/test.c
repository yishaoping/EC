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

/* 启动前配置：初始化 GHT、软件中断、权限和性能统计窗口。 */
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
    printf("[CONFIG] big_core_perf=%s checker_perf=%s interval_cycles=%" PRIu64
           " sample_readback=not_collected\n",
           MEEK_ENABLE_BIG_CORE_PERF ? "on" : "off",
           MEEK_ENABLE_CHECKER_SEGMENT_PERF ? "on" : "off",
           (uint64_t)FPGA_PERF_INTERVAL_CYCLES);
    lock_release(&uart_lock);

    csr_read_s[0] = ghe_csr_perf_read(0);
    ght_set_satp_priv();
    mtimecmp_cfg();
    csr_timer_cfg();
    ghe_fpga_perf_reset();
    ghe_fpga_perf_start();
    return hart_id;
}

/* 执行下方 [BENCHMARK SIZE] 选择的 GAPBS 节点规模。 */
static void gapbs_bfs(uint64_t hart_id, uint64_t *start_cpu,
                      uint64_t *end_cpu, gapbs_bfs_result_t *result)
{
    ROCC_INSTRUCTION(1, 0x31);
    ROCC_INSTRUCTION_S(1, 0X01, 0x70);

    *start_cpu = read_cycles();
    (void)hart_id;
    /*
     * [BENCHMARK SIZE]
     * 修改这一行即可切换规模：gapbs_bfs_run_14、_512、_1024、_2048、_4096。
     */
    gapbs_bfs_run_4096(result);

    ROCC_INSTRUCTION_S(1, 0X02, 0x70);
    for (int nop_count = 0; nop_count < 26; nop_count++) {
        __asm__ volatile("nop");
    }
    ROCC_INSTRUCTION(1, 0x32);

    csr_read_e[0] = ghe_csr_perf_read(0);
    uint64_t status;
    while ((status = ght_get_status()) < 0x1FFFF) {
    }
    *end_cpu = read_cycles();
}

/* 收尾阶段：等待 checker、冻结并打印统计结果，然后关闭协同状态。 */
static void test_report(uint64_t hart_id, uint64_t start_cpu,
                        uint64_t end_cpu, const gapbs_bfs_result_t *result)
{
    lock_acquire(&uart_lock);
    printf("[RUN] benchmark=gapbs_bfs nodes=%" PRIu32 " source=%" PRIu32
           " reached=%" PRIu32 " edges=%" PRIu32
           " verified=%" PRIu32 " parent_checksum=%" PRIu64 "\n",
           result->node_count, result->source, result->reached_nodes,
           result->traversed_edges, result->verified, result->parent_checksum);
    lock_release(&uart_lock);
    report_end(start_cpu, end_cpu, hart_id);
    ght_unset_satp_priv();
    ROCC_INSTRUCTION(1, 0x30);
}

int main(void)
{
    uint64_t hart_id = test_setup();
    uint64_t start_cpu = 0;
    uint64_t end_cpu = 0;
    gapbs_bfs_result_t result = {0};
    gapbs_bfs(hart_id, &start_cpu, &end_cpu, &result);
    test_report(hart_id, start_cpu, end_cpu, &result);
    return 0;
}
