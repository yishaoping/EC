#include "report.h"

#include <inttypes.h>
#include <stdio.h>

#include "../hw/cycle.h"
#include "../hw/interrupt.h"
#include "../hw/spin_lock.h"

uint64_t csr_read_s[TOTAL_CSR_PERF];
uint64_t csr_read_e[TOTAL_CSR_PERF];

/* hart 0 为 BOOM，其余 hart 为 Rocket checker。 */
volatile uint64_t hart_traffic[NUM_HARTS][GHE_TRAFFIC_COUNTERS];
/* checker 完成快照写入后置位对应的 ready 标志。 */
volatile uint32_t hart_traffic_ready[NUM_HARTS];

typedef unsigned __int128 uint128_t;

typedef enum {
    PACKAGE_DRAIN_COMPLETE,
    PACKAGE_DRAIN_HARD_ERROR,
    PACKAGE_DRAIN_TIMEOUT,
} package_drain_status_t;

typedef struct {
    uint64_t allocated;
    uint64_t completed;
    uint64_t pending;
    uint64_t result_dropped;
    uint64_t writeback_dropped;
    uint64_t arithmetic_overflow;
    uint64_t elapsed_cycles;
} package_drain_state_t;

/* 等待包生命周期和未校验脏写回桶全部排空。 */
static package_drain_status_t wait_for_package_statistics_to_drain(
    package_drain_state_t *state)
{
    uint64_t start_cycle = read_cycles();

    while (1) {
        state->allocated =
            ghe_traffic_counter_read(GHE_TRAFFIC_ALLOCATED_PACKAGES);
        state->completed =
            ghe_traffic_counter_read(GHE_TRAFFIC_COMPLETED_PACKAGES);
        state->pending = ghe_traffic_counter_read(
            GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_PENDING);
        state->result_dropped =
            ghe_traffic_counter_read(GHE_TRAFFIC_PACKAGE_RESULT_DROPPED);
        state->writeback_dropped = ghe_traffic_counter_read(
            GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_DROPPED);
        state->arithmetic_overflow = ghe_traffic_counter_read(
            GHE_TRAFFIC_STATS_ARITHMETIC_OVERFLOW);
        state->elapsed_cycles = read_cycles() - start_cycle;

        if (state->result_dropped != 0 || state->writeback_dropped != 0 ||
            state->arithmetic_overflow != 0) {
            return PACKAGE_DRAIN_HARD_ERROR;
        }
        if (state->completed == state->allocated && state->pending == 0) {
            return PACKAGE_DRAIN_COMPLETE;
        }
        if (state->elapsed_cycles >= PACKAGE_DRAIN_TIMEOUT_CYCLES) {
            return PACKAGE_DRAIN_TIMEOUT;
        }
    }
}

/* 手工输出 128 位无符号整数，避免依赖运行库的扩展格式化支持。 */
static void print_uint128(uint128_t value)
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

/* 将指定频率下的周期总和转换为纳秒总和。 */
static uint128_t cycle_sum_to_ns(uint64_t cycle_sum, uint64_t frequency_hz)
{
    return (uint128_t)cycle_sum * UINT64_C(1000000000) / frequency_hz;
}

/* 输出不可缓存 store 的 BOOM 到 checker 近似检测延迟。 */
static void print_store_uncache_latency(void)
{
    uint128_t hart_time_ns[NUM_HARTS];
    uint128_t checker_time_ns = 0;
    uint128_t checker_count = 0;
    uint64_t boom_count = hart_traffic[0][GHE_TRAFFIC_STORE_UNCACHE];

    for (int hart = 0; hart < NUM_HARTS; hart++) {
        uint64_t frequency_hz = hart == 0 ? BOOM_CORE_FREQUENCY_HZ
                                         : CHECKER_CORE_FREQUENCY_HZ;
        uint64_t cycle_sum =
            hart_traffic[hart][GHE_TRAFFIC_STORE_UNCACHE_CYCLE_SUM];

        hart_time_ns[hart] = cycle_sum_to_ns(cycle_sum, frequency_hz);
        printf("hart%d store_uncache timestamp_cycle_sum=%" PRIu64
               " frequency_hz=%" PRIu64 " time_sum_ns=",
               hart, cycle_sum, frequency_hz);
        print_uint128(hart_time_ns[hart]);
        printf("\r\n");

        if (hart != 0) {
            checker_time_ns += hart_time_ns[hart];
            checker_count +=
                hart_traffic[hart][GHE_TRAFFIC_STORE_UNCACHE];
        }
    }

    printf("store_uncache latency inputs: boom_count=%" PRIu64
           " checker_count=", boom_count);
    print_uint128(checker_count);
    printf(" boom_time_sum_ns=");
    print_uint128(hart_time_ns[0]);
    printf(" checker_time_sum_ns=");
    print_uint128(checker_time_ns);
    printf("\r\n");

    if (checker_count != (uint128_t)boom_count) {
        printf("store_uncache average detection latency unavailable: "
               "event counts do not match\r\n");
        return;
    }
    if (boom_count == 0) {
        printf("store_uncache average detection latency unavailable: "
               "no events\r\n");
        return;
    }

    int negative = checker_time_ns < hart_time_ns[0];
    uint128_t difference_ns = negative ? hart_time_ns[0] - checker_time_ns
                                       : checker_time_ns - hart_time_ns[0];
    uint128_t average_ns = difference_ns / boom_count;
    uint64_t average_fraction =
        (uint64_t)(((difference_ns % boom_count) * 1000) / boom_count);

    printf("store_uncache approx_average_detection_latency_ns=");
    if (negative) {
        printf("-");
    }
    print_uint128(average_ns);
    printf(".%03" PRIu64 "\r\n", average_fraction);
}

/* 输出并校验 BOOM L1 到 L2 的未校验脏写回延迟统计。 */
static void print_unverified_dirty_writeback_latency(void)
{
    const volatile uint64_t *traffic = hart_traffic[0];
    uint64_t unverified_at_writeback =
        traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_SEEN];
    uint64_t resolved = traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_RESOLVED];
    uint64_t pending = traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_PENDING];
    uint64_t other = traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_OTHER];
    uint64_t verified_at_writeback =
        traffic[GHE_TRAFFIC_VERIFIED_DIRTY_WB];
    uint64_t verify_required =
        traffic[GHE_TRAFFIC_L1_L2_WB_DIRTY_VERIFY_REQUIRED];
    uint64_t nonverify = traffic[GHE_TRAFFIC_NONVERIFY_DIRTY_WB];
    uint64_t failed = traffic[GHE_TRAFFIC_FAILED_PACKAGES];
    uint64_t safe_cycle_sum =
        traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_SAFE_CYCLE_SUM];
    uint64_t writeback_cycle_sum =
        traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_CYCLE_SUM];
    uint64_t stats_valid =
        traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_STATS_VALID];
    uint64_t result_dropped = traffic[GHE_TRAFFIC_PACKAGE_RESULT_DROPPED];
    uint64_t allocated = traffic[GHE_TRAFFIC_ALLOCATED_PACKAGES];
    uint64_t completed = traffic[GHE_TRAFFIC_COMPLETED_PACKAGES];
    uint64_t passed = traffic[GHE_TRAFFIC_PASSED_PACKAGES];
    uint64_t cancelled = traffic[GHE_TRAFFIC_CANCELLED_PACKAGES];
    uint64_t arithmetic_overflow =
        traffic[GHE_TRAFFIC_STATS_ARITHMETIC_OVERFLOW];
    uint64_t classified_required =
        verified_at_writeback + unverified_at_writeback;
    uint64_t classified_unverified = pending + resolved + other;
    uint64_t classified_dirty = verify_required + nonverify;

    printf("dirty writeback verification: verified=%" PRIu64
           " unverified_seen=%" PRIu64
           " pending=%" PRIu64 " resolved=%" PRIu64
           " other=%" PRIu64 "\r\n",
           verified_at_writeback, unverified_at_writeback, pending, resolved,
           other);
    printf("package verification: allocated=%" PRIu64
           " completed=%" PRIu64 " passed=%" PRIu64
           " failed=%" PRIu64 " cancelled=%" PRIu64
           " safe_watermark=%" PRIu64 " result_dropped=%" PRIu64
           " arithmetic_overflow=%" PRIu64 " stats_valid=%" PRIu64 "\r\n",
           allocated, completed, passed, failed, cancelled,
           traffic[GHE_TRAFFIC_SAFE_PACKET_WATERMARK], result_dropped,
           arithmetic_overflow, stats_valid);
    printf("unverified dirty writeback latency inputs: safe_cycle_sum=%" PRIu64
           " writeback_cycle_sum=%" PRIu64 " boom_frequency_hz=%" PRIu64
           "\r\n",
           safe_cycle_sum, writeback_cycle_sum,
           (uint64_t)BOOM_CORE_FREQUENCY_HZ);

    if (stats_valid != 1 || pending != 0 || other != 0 ||
        result_dropped != 0 || arithmetic_overflow != 0 || failed != 0 ||
        cancelled != 0 || completed != allocated || passed != completed ||
        classified_required != verify_required ||
        classified_unverified != unverified_at_writeback ||
        classified_dirty != traffic[GHE_TRAFFIC_L1_L2_WB_DIRTY]) {
        printf("unverified dirty writeback average latency unavailable: "
               "statistics are incomplete or invalid\r\n");
        return;
    }
    if (resolved == 0) {
        printf("unverified dirty writeback average latency unavailable: "
               "no resolved events\r\n");
        return;
    }
    if (safe_cycle_sum < writeback_cycle_sum) {
        printf("unverified dirty writeback average latency unavailable: "
               "cycle sum underflow\r\n");
        return;
    }

    uint64_t latency_cycle_sum = safe_cycle_sum - writeback_cycle_sum;
    uint64_t average_cycles = latency_cycle_sum / resolved;
    uint64_t average_cycle_fraction = (uint64_t)(
        ((uint128_t)(latency_cycle_sum % resolved) * 1000) / resolved);
    uint128_t latency_ns_numerator =
        (uint128_t)latency_cycle_sum * UINT64_C(1000000000);
    uint128_t latency_ns_denominator =
        (uint128_t)BOOM_CORE_FREQUENCY_HZ * resolved;
    uint128_t average_ns = latency_ns_numerator / latency_ns_denominator;
    uint64_t average_ns_fraction = (uint64_t)(
        ((latency_ns_numerator % latency_ns_denominator) * 1000) /
        latency_ns_denominator);

    printf("unverified_dirty_writeback_average_latency_cycles=%" PRIu64
           ".%03" PRIu64 " average_latency_ns=",
           average_cycles, average_cycle_fraction);
    print_uint128(average_ns);
    printf(".%03" PRIu64 "\r\n", average_ns_fraction);
}

void report_end(uint64_t start_cpu, uint64_t end_cpu, uint64_t hart_id)
{
    /* 等待所有 checker 写入本地统计快照。 */
    while (hart_traffic_ready[1] == 0 || hart_traffic_ready[2] == 0 ||
           hart_traffic_ready[3] == 0 || hart_traffic_ready[4] == 0) {
    }
    __sync_synchronize();

    package_drain_state_t package_drain_state = {0};
    package_drain_status_t package_drain_status =
        wait_for_package_statistics_to_drain(&package_drain_state);

    /* 先冻结硬件统计，再读取 RoCC 计数器，避免读回过程污染统计窗口。 */
    ghe_fpga_perf_stop();
    for (int counter = 0; counter < GHE_TRAFFIC_COUNTERS; counter++) {
        hart_traffic[0][counter] = ghe_traffic_counter_read(counter);
    }

    lock_acquire(&uart_lock);
    printf("CPU execution took %" PRIu64 " cycles\n", end_cpu - start_cpu);
    if (package_drain_status != PACKAGE_DRAIN_COMPLETE) {
        const char *reason = package_drain_status == PACKAGE_DRAIN_HARD_ERROR
                                 ? "hard_error"
                                 : "timeout";
        printf("package statistics drain incomplete: reason=%s"
               " allocated=%" PRIu64 " completed=%" PRIu64
               " pending=%" PRIu64 " result_dropped=%" PRIu64
               " writeback_dropped=%" PRIu64
               " arithmetic_overflow=%" PRIu64
               " elapsed_cycles=%" PRIu64 "\r\n",
               reason, package_drain_state.allocated,
               package_drain_state.completed, package_drain_state.pending,
               package_drain_state.result_dropped,
               package_drain_state.writeback_dropped,
               package_drain_state.arithmetic_overflow,
               package_drain_state.elapsed_cycles);
    }
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
            printf("hart0 dcache traffic: l1_l2_c_total=%" PRIu64
                   " l1_l2_wb_dirty=%" PRIu64
                   " l1_l2_wb_dirty_verify_required=%" PRIu64 "\r\n",
                   hart_traffic[hart][GHE_TRAFFIC_L1_L2_C_TOTAL],
                   hart_traffic[hart][GHE_TRAFFIC_L1_L2_WB_DIRTY],
                   hart_traffic[hart]
                       [GHE_TRAFFIC_L1_L2_WB_DIRTY_VERIFY_REQUIRED]);
        }
    }
    printf("shared dcache traffic: l2_dram_wb_total=%" PRIu64
           " l2_dram_wb_dirty=%" PRIu64 "\r\n",
           hart_traffic[0][GHE_TRAFFIC_L2_DRAM_WB_TOTAL],
           hart_traffic[0][GHE_TRAFFIC_L2_DRAM_WB_DIRTY]);
    print_store_uncache_latency();
    print_unverified_dirty_writeback_latency();
    printf("[Boom-C%lx]: Test is now completed. \r\n", hart_id);
    lock_release(&uart_lock);
}
