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

typedef unsigned __int128 test_uint128_t;

/* test.c 直接输出脏写回延迟，避免把周期总和截断为 64 位中间结果。 */
static void test_print_uint128(test_uint128_t value)
{
    char buffer[40];
    int index = (int)sizeof(buffer) - 1;

    buffer[index] = '\0';
    do {
        buffer[--index] = (char)('0' + value % 10);
        value /= 10;
    } while (value != 0);
    printf("%s", &buffer[index]);
}

static void test_print_uint128_fixed(test_uint128_t integer,
                                     uint64_t fraction_thousandths)
{
    test_print_uint128(integer);
    printf(".%03" PRIu64, fraction_thousandths);
}

/*
 * 根据 BOOM 统计快照计算未校验脏写回的平均验证延迟。
 * writeback_cycle_sum 和 verification_cycle_sum 都由硬件按事件累加，
 * 软件只做差值并除以已完成验证的写回数。
 */
static void test_print_dirty_writeback_latency(void)
{
    const volatile uint64_t *traffic = hart_traffic[0];
    uint64_t verify_required =
        traffic[GHE_TRAFFIC_L1_L2_WB_DIRTY_VERIFY_REQUIRED];
    uint64_t verified_at_writeback =
        traffic[GHE_TRAFFIC_VERIFIED_DIRTY_WB];
    uint64_t unverified_at_writeback =
        traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_SEEN];
    uint64_t dirty_wb_total = traffic[GHE_TRAFFIC_L1_L2_WB_DIRTY];
    uint64_t nonverify_dirty_wb =
        traffic[GHE_TRAFFIC_NONVERIFY_DIRTY_WB];
    uint64_t resolved =
        traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_RESOLVED];
    uint64_t pending = traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_PENDING];
    uint64_t other = traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_OTHER];
    uint64_t verification_cycle_sum =
        traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_SAFE_CYCLE_SUM];
    uint64_t writeback_cycle_sum =
        traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_CYCLE_SUM];
    uint64_t stats_valid =
        traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_STATS_VALID];
    uint64_t result_dropped = traffic[GHE_TRAFFIC_PACKAGE_RESULT_DROPPED];
    uint64_t failed = traffic[GHE_TRAFFIC_FAILED_PACKAGES];
    uint64_t cancelled = traffic[GHE_TRAFFIC_CANCELLED_PACKAGES];
    uint64_t allocated = traffic[GHE_TRAFFIC_ALLOCATED_PACKAGES];
    uint64_t completed = traffic[GHE_TRAFFIC_COMPLETED_PACKAGES];
    uint64_t passed = traffic[GHE_TRAFFIC_PASSED_PACKAGES];
    uint64_t arithmetic_overflow =
        traffic[GHE_TRAFFIC_STATS_ARITHMETIC_OVERFLOW];

    printf("[SOFTWARE_VERIFY] dirty_wb required=%" PRIu64
           " verified_at_writeback=%" PRIu64
           " unverified_at_writeback=%" PRIu64
           " writeback_cycle_sum=%" PRIu64
           " verification_cycle_sum=%" PRIu64 "\n",
           verify_required, verified_at_writeback, unverified_at_writeback,
           writeback_cycle_sum, verification_cycle_sum);

    const char *reason = NULL;
    if (stats_valid != 1 || pending != 0 || other != 0 ||
        result_dropped != 0 || failed != 0 || cancelled != 0 ||
        arithmetic_overflow != 0 || completed != allocated ||
        passed != completed || resolved != unverified_at_writeback ||
        (test_uint128_t)verify_required !=
            (test_uint128_t)verified_at_writeback + unverified_at_writeback ||
        (test_uint128_t)dirty_wb_total !=
            (test_uint128_t)verify_required + nonverify_dirty_wb) {
        reason = "statistics_invalid";
    } else if (resolved == 0) {
        reason = "no_events";
    } else if (verification_cycle_sum < writeback_cycle_sum) {
        reason = "cycle_sum_underflow";
    }

    if (reason != NULL) {
        printf("[LATENCY] dirty_wb average=n/a reason=%s\n", reason);
#if TEST_REPORT_VERBOSE
        printf("[LATENCY_VERBOSE] safe_cycle_sum=%" PRIu64
               " writeback_cycle_sum=%" PRIu64 " resolved=%" PRIu64
               " frequency_hz=%" PRIu64 "\n",
               verification_cycle_sum, writeback_cycle_sum, resolved,
               (uint64_t)BOOM_CORE_FREQUENCY_HZ);
#endif
        return;
    }

    uint64_t latency_cycle_sum =
        verification_cycle_sum - writeback_cycle_sum;
    uint64_t average_cycles = latency_cycle_sum / resolved;
    uint64_t average_cycle_fraction = (uint64_t)(
        ((test_uint128_t)(latency_cycle_sum % resolved) * 1000) / resolved);
    test_uint128_t latency_ns_numerator =
        (test_uint128_t)latency_cycle_sum * UINT64_C(1000000000);
    test_uint128_t latency_ns_denominator =
        (test_uint128_t)BOOM_CORE_FREQUENCY_HZ * resolved;
    test_uint128_t average_ns =
        latency_ns_numerator / latency_ns_denominator;
    uint64_t average_ns_fraction = (uint64_t)(
        ((latency_ns_numerator % latency_ns_denominator) * 1000) /
        latency_ns_denominator);

    printf("[LATENCY] dirty_wb events=%" PRIu64 " average=", resolved);
    test_print_uint128_fixed(average_cycles, average_cycle_fraction);
    printf("cycles/");
    test_print_uint128_fixed(average_ns, average_ns_fraction);
    printf("ns\n");
#if TEST_REPORT_VERBOSE
    printf("[LATENCY_VERBOSE] safe_cycle_sum=%" PRIu64
           " writeback_cycle_sum=%" PRIu64 " resolved=%" PRIu64
           " frequency_hz=%" PRIu64 "\n",
           verification_cycle_sum, writeback_cycle_sum, resolved,
           (uint64_t)BOOM_CORE_FREQUENCY_HZ);
#endif
}

/* 根据 L2->DRAM 硬件快照计算未校验脏写回的平均验证延迟。 */
static void test_print_l2_dram_dirty_writeback_latency(void)
{
    const volatile uint64_t *traffic = hart_traffic[0];
    uint64_t required = traffic[GHE_TRAFFIC_L2_DRAM_WB_VERIFY_REQUIRED];
    uint64_t verified = traffic[GHE_TRAFFIC_L2_DRAM_WB_VERIFIED];
    uint64_t unverified = traffic[GHE_TRAFFIC_L2_DRAM_WB_UNVERIFIED];
    uint64_t resolved = traffic[GHE_TRAFFIC_L2_DRAM_WB_UNVERIFIED_RESOLVED];
    uint64_t pending = traffic[GHE_TRAFFIC_L2_DRAM_WB_UNVERIFIED_PENDING];
    uint64_t other = traffic[GHE_TRAFFIC_L2_DRAM_WB_OTHER];
    uint64_t writeback_sum = traffic[GHE_TRAFFIC_L2_DRAM_WB_WRITEBACK_CYCLE_SUM];
    uint64_t verify_sum = traffic[GHE_TRAFFIC_L2_DRAM_WB_VERIFY_CYCLE_SUM];
    uint64_t valid = traffic[GHE_TRAFFIC_L2_DRAM_WB_STATS_VALID];

    printf("[SOFTWARE_VERIFY] l2_dram_dirty_wb required=%" PRIu64
           " verified_at_writeback=%" PRIu64
           " unverified_at_writeback=%" PRIu64
           " other=%" PRIu64
           " writeback_cycle_sum=%" PRIu64
           " verification_cycle_sum=%" PRIu64 "\n",
           required, verified, unverified, other, writeback_sum, verify_sum);
    printf("[LATENCY] clock=l2:%" PRIu64 "Hz\n",
           (uint64_t)L2_CORE_FREQUENCY_HZ);

    const char *reason = NULL;
    /* `other` is a valid non-verification dirty-writeback class.  It is
       reported for diagnosis, but must not invalidate the latency of the
       writebacks that actually require checker verification. */
    if (valid != 1 || pending != 0 || resolved != unverified ||
        (test_uint128_t)required !=
            (test_uint128_t)verified + unverified ||
        verify_sum < writeback_sum) {
        reason = "statistics_invalid";
    } else if (resolved == 0) {
        reason = "no_events";
    }
    if (reason != NULL) {
        printf("[LATENCY] l2_dram_dirty_wb average=n/a reason=%s\n", reason);
        return;
    }

    uint64_t latency_sum = verify_sum - writeback_sum;
    uint64_t average_cycles = latency_sum / resolved;
    uint64_t average_fraction = (uint64_t)(((test_uint128_t)(latency_sum % resolved) * 1000) / resolved);
    test_uint128_t ns_num = (test_uint128_t)latency_sum * UINT64_C(1000000000);
    test_uint128_t ns_den = (test_uint128_t)L2_CORE_FREQUENCY_HZ * resolved;
    test_uint128_t average_ns = ns_num / ns_den;
    uint64_t ns_fraction = (uint64_t)(((ns_num % ns_den) * 1000) / ns_den);
    printf("[LATENCY] l2_dram_dirty_wb events=%" PRIu64 " average=", resolved);
    test_print_uint128_fixed(average_cycles, average_fraction);
    printf("cycles/");
    test_print_uint128_fixed(average_ns, ns_fraction);
    printf("ns\n");
}

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
    int report_ok = report_end(start_cpu, end_cpu, hart_id);
    /* report_end 已冻结并读回 BOOM 统计快照；此处由测试程序计算延迟。 */
    lock_acquire(&uart_lock);
    test_print_dirty_writeback_latency();
    test_print_l2_dram_dirty_writeback_latency();
    printf("[END] hart=%lx status=%s\n", hart_id,
           report_ok ? "PASS" : "FAIL");
    lock_release(&uart_lock);
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
