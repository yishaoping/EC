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
    uint64_t l2_pending;
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
        state->l2_pending = ghe_traffic_counter_read(
            GHE_TRAFFIC_L2_DRAM_WB_UNVERIFIED_PENDING);
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
        if (state->completed == state->allocated && state->pending == 0 &&
            state->l2_pending == 0) {
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

static void print_uint128_fixed(uint128_t integer, uint64_t fraction_thousandths)
{
    print_uint128(integer);
    printf(".%03" PRIu64, fraction_thousandths);
}

static const char *traffic_hart_name(int hart)
{
    static const char *const names[NUM_HARTS] = {
        "boom", "c1", "c2", "c3", "c4"};
    return hart >= 0 && hart < NUM_HARTS ? names[hart] : "hart?";
}

static uint64_t checker_traffic_sum(int counter)
{
    uint64_t total = 0;
    for (int hart = 1; hart < NUM_HARTS; hart++) {
        total += hart_traffic[hart][counter];
    }
    return total;
}

/* STOP 后等待 BOOM 的架构/严格计数收敛，避免读取到尾部未结算快照。 */
static int wait_for_boom_strict_pending(void)
{
    uint64_t start_cycle = read_cycles();
    while (1) {
        uint64_t pending =
            ghe_traffic_counter_read(GHE_TRAFFIC_STRICT_PENDING);
        if (pending == 0) {
            return 1;
        }
        if (read_cycles() - start_cycle >= PACKAGE_DRAIN_TIMEOUT_CYCLES) {
            printf("[TRAFFIC_DIAG] strict_pending=%" PRIu64
                   " status=TIMEOUT\n", pending);
            return 0;
        }
    }
}

/* 仅在不一致时输出有符号差值，便于直接定位多记或漏记。 */
static void print_counter_difference(const char *name,
                                     uint64_t left, uint64_t right)
{
    if (left == right) {
        return;
    }
    printf("[ASSERT_DIAG] %s=%c%" PRIu64 "\n", name,
           left >= right ? '+' : '-',
           left >= right ? left - right : right - left);
}

/* 输出 BOOM 架构、BOOM 严格路径和 checker 三套访存口径，并执行一致性断言。 */
static int print_boom_traffic_consistency(void)
{
    const volatile uint64_t *boom = hart_traffic[0];
    uint64_t arch_store = boom[GHE_TRAFFIC_ARCH_STORE_TOTAL];
    uint64_t arch_store_cache = boom[GHE_TRAFFIC_ARCH_STORE_CACHE];
    uint64_t arch_store_uncache = boom[GHE_TRAFFIC_ARCH_STORE_UNCACHE];
    uint64_t arch_load = boom[GHE_TRAFFIC_ARCH_LOAD_TOTAL];
    uint64_t arch_load_cache = boom[GHE_TRAFFIC_ARCH_LOAD_CACHE];
    uint64_t arch_load_uncache = boom[GHE_TRAFFIC_ARCH_LOAD_UNCACHE];

    uint64_t strict_store = boom[GHE_TRAFFIC_STRICT_STORE_TOTAL];
    uint64_t strict_store_cache = boom[GHE_TRAFFIC_STRICT_STORE_CACHE];
    uint64_t strict_store_uncache = boom[GHE_TRAFFIC_STRICT_STORE_UNCACHE];
    uint64_t strict_load = boom[GHE_TRAFFIC_STRICT_LOAD_TOTAL];
    uint64_t strict_load_cache = boom[GHE_TRAFFIC_STRICT_LOAD_CACHE];
    uint64_t strict_load_uncache = boom[GHE_TRAFFIC_STRICT_LOAD_UNCACHE];
    uint64_t strict_load_response =
        boom[GHE_TRAFFIC_STRICT_LOAD_CACHE_RESPONSE];
    uint64_t strict_load_forward = boom[GHE_TRAFFIC_STRICT_LOAD_FORWARD];

    uint64_t checker_store = checker_traffic_sum(GHE_TRAFFIC_STORE_TOTAL);
    uint64_t checker_store_cache = checker_traffic_sum(GHE_TRAFFIC_STORE_CACHE);
    uint64_t checker_store_uncache =
        checker_traffic_sum(GHE_TRAFFIC_STORE_UNCACHE);
    uint64_t checker_load = checker_traffic_sum(GHE_TRAFFIC_LOAD_TOTAL);
    uint64_t checker_load_cache = checker_traffic_sum(GHE_TRAFFIC_LOAD_CACHE);
    uint64_t checker_load_uncache = checker_traffic_sum(GHE_TRAFFIC_LOAD_UNCACHE);
    uint64_t checker_load_forward = checker_traffic_sum(GHE_TRAFFIC_LOAD_FORWARD);

    printf("[TRAFFIC_ARCH] boom store=%" PRIu64 " load=%" PRIu64 "\n",
           arch_store, arch_load);
    printf("[TRAFFIC_ARCH] store_cache=%" PRIu64
           " store_uncache=%" PRIu64 " load_cache=%" PRIu64
           " load_uncache=%" PRIu64 "\n",
           arch_store_cache, arch_store_uncache,
           arch_load_cache, arch_load_uncache);

    printf("[TRAFFIC_STRICT] boom store=%" PRIu64 " load=%" PRIu64 "\n",
           strict_store, strict_load);
    printf("[TRAFFIC_STRICT] store_cache=%" PRIu64
           " store_uncache=%" PRIu64 " load_cache=%" PRIu64
           " load_uncache=%" PRIu64 " load_cache_response=%" PRIu64
           " load_forward=%" PRIu64 " pending=%" PRIu64 "\n",
           strict_store_cache, strict_store_uncache,
           strict_load_cache, strict_load_uncache,
           strict_load_response, strict_load_forward,
           boom[GHE_TRAFFIC_STRICT_PENDING]);

    printf("[TRAFFIC_CHECKER] sum store=%" PRIu64 " load=%" PRIu64 "\n",
           checker_store, checker_load);
    printf("[TRAFFIC_CHECKER] store_cache=%" PRIu64
           " store_uncache=%" PRIu64 " load_cache=%" PRIu64
           " load_uncache=%" PRIu64 " load_forward=%" PRIu64 "\n",
           checker_store_cache, checker_store_uncache,
           checker_load_cache, checker_load_uncache, checker_load_forward);

    int store_ok = arch_store == strict_store && arch_store == checker_store;
    int load_ok = arch_load == strict_load && arch_load == checker_load;
    int store_class_ok = arch_store_cache == strict_store_cache &&
                         arch_store_uncache == strict_store_uncache &&
                         arch_store_cache == checker_store_cache &&
                         arch_store_uncache == checker_store_uncache;
    int load_class_ok = arch_load_cache == strict_load_cache &&
                        arch_load_uncache == strict_load_uncache &&
                        arch_load_cache == checker_load_cache &&
                        arch_load_uncache == checker_load_uncache;
    int path_ok = strict_load_cache ==
                      strict_load_response + strict_load_forward &&
                  strict_load == strict_load_cache + strict_load_uncache;
    int checker_path_ok = checker_load ==
                          checker_load_cache + checker_load_uncache +
                              checker_load_forward;
    int counter_ok = boom[GHE_TRAFFIC_COUNTER_ASSERT_FAIL] == 0 &&
                     boom[GHE_TRAFFIC_STRICT_PENDING] == 0;

    printf("[ASSERT] store arch=%" PRIu64 " strict=%" PRIu64
           " checker=%" PRIu64 " result=%s\n",
           arch_store, strict_store, checker_store,
           store_ok && store_class_ok ? "PASS" : "FAIL");
    printf("[ASSERT] load arch=%" PRIu64 " strict=%" PRIu64
           " checker=%" PRIu64 " result=%s\n",
           arch_load, strict_load, checker_load,
           load_ok && load_class_ok && path_ok && checker_path_ok
               ? "PASS" : "FAIL");
    printf("[ASSERT] traffic_counter_fail=%" PRIu64
           " pending=%" PRIu64 " result=%s\n",
           boom[GHE_TRAFFIC_COUNTER_ASSERT_FAIL],
           boom[GHE_TRAFFIC_STRICT_PENDING], counter_ok ? "PASS" : "FAIL");
    if (!store_ok || !store_class_ok) {
        print_counter_difference("store_arch_minus_strict",
                                 arch_store, strict_store);
        print_counter_difference("store_arch_minus_checker",
                                 arch_store, checker_store);
        print_counter_difference("store_cache_arch_minus_strict",
                                 arch_store_cache, strict_store_cache);
        print_counter_difference("store_uncache_arch_minus_strict",
                                 arch_store_uncache, strict_store_uncache);
    }
    if (!load_ok || !load_class_ok || !path_ok || !checker_path_ok) {
        print_counter_difference("load_arch_minus_strict",
                                 arch_load, strict_load);
        print_counter_difference("load_arch_minus_checker",
                                 arch_load, checker_load);
        print_counter_difference("load_cache_arch_minus_strict",
                                 arch_load_cache, strict_load_cache);
        print_counter_difference("load_uncache_arch_minus_strict",
                                 arch_load_uncache, strict_load_uncache);
        print_counter_difference("load_cache_minus_response_forward",
                                 strict_load_cache,
                                 strict_load_response + strict_load_forward);
    }
    return store_ok && load_ok && store_class_ok && load_class_ok && path_ok &&
           checker_path_ok && counter_ok;
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
#if TEST_REPORT_VERBOSE
        printf("[LATENCY_VERBOSE] hart=%s events=%" PRIu64
               " cycle_sum=%" PRIu64 " time_sum_ns=",
               traffic_hart_name(hart),
               hart_traffic[hart][GHE_TRAFFIC_STORE_UNCACHE], cycle_sum);
        print_uint128(hart_time_ns[hart]);
        printf(" frequency_hz=%" PRIu64 "\n", frequency_hz);
#endif

        if (hart != 0) {
            checker_time_ns += hart_time_ns[hart];
            checker_count +=
                hart_traffic[hart][GHE_TRAFFIC_STORE_UNCACHE];
        }
    }

    if (checker_count != (uint128_t)boom_count) {
        printf("[LATENCY] store_uncache events=boom=%" PRIu64
               " checker=", boom_count);
        print_uint128(checker_count);
        printf(" average=n/a reason=count_mismatch\n");
#if TEST_REPORT_VERBOSE
        printf("[LATENCY_VERBOSE] boom_time_sum_ns=");
        print_uint128(hart_time_ns[0]);
        printf(" checker_time_sum_ns=");
        print_uint128(checker_time_ns);
        printf("\n");
#endif
        return;
    }
    if (boom_count == 0) {
        printf("[LATENCY] store_uncache events=0 average=n/a reason=no_events\n");
        return;
    }

    int negative = checker_time_ns < hart_time_ns[0];
    uint128_t difference_ns = negative ? hart_time_ns[0] - checker_time_ns
                                       : checker_time_ns - hart_time_ns[0];
    uint128_t average_ns = difference_ns / boom_count;
    uint64_t average_ns_fraction =
        (uint64_t)(((difference_ns % boom_count) * 1000) / boom_count);

    /* 将纳秒差换算为 BOOM 等效周期，便于与其它 BOOM 延迟指标比较。 */
    uint128_t average_cycle_numerator =
        difference_ns * (uint128_t)BOOM_CORE_FREQUENCY_HZ;
    uint128_t average_cycle_denominator =
        (uint128_t)boom_count * UINT64_C(1000000000);
    uint128_t average_cycles =
        average_cycle_numerator / average_cycle_denominator;
    uint64_t average_cycle_fraction = (uint64_t)(
        ((average_cycle_numerator % average_cycle_denominator) * 1000) /
        average_cycle_denominator);

    printf("[LATENCY] store_uncache events=boom=%" PRIu64
           " checker=", boom_count);
    print_uint128(checker_count);
    printf(" average=");
    if (negative) {
        printf("-");
    }
    print_uint128_fixed(average_cycles, average_cycle_fraction);
    printf("cycles/");
    print_uint128_fixed(average_ns, average_ns_fraction);
    printf("ns\n");
#if TEST_REPORT_VERBOSE
    printf("[LATENCY_VERBOSE] boom_time_sum_ns=");
    print_uint128(hart_time_ns[0]);
    printf(" checker_time_sum_ns=");
    print_uint128(checker_time_ns);
    printf("\n");
#endif
}

/* 输出并校验 BOOM L1 到 L2 的未校验脏写回分类统计。 */
static void print_unverified_dirty_writeback_summary(void)
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

    uint64_t safe_watermark = traffic[GHE_TRAFFIC_SAFE_PACKET_WATERMARK];
    int package_ok = stats_valid == 1 && result_dropped == 0 &&
                     arithmetic_overflow == 0 && failed == 0 &&
                     cancelled == 0 && completed == allocated &&
                     passed == completed;
    int dirty_ok = stats_valid == 1 && pending == 0 && other == 0 &&
                   result_dropped == 0 && arithmetic_overflow == 0 &&
                   failed == 0 && cancelled == 0 && completed == allocated &&
                   passed == completed && classified_required == verify_required &&
                   classified_unverified == unverified_at_writeback &&
                   classified_dirty == traffic[GHE_TRAFFIC_L1_L2_WB_DIRTY];

    printf("[VERIFY] packages allocated=%" PRIu64 " completed=%" PRIu64
           " passed=%" PRIu64 " failed=%" PRIu64 " cancelled=%" PRIu64
           " status=%s\n",
           allocated, completed, passed, failed, cancelled,
           package_ok ? "PASS" : "FAIL");
    printf("[VERIFY] dirty_wb total=%" PRIu64 " verified=%" PRIu64
           " unverified=%" PRIu64 " resolved=%" PRIu64
           " pending=%" PRIu64 " other=%" PRIu64 " status=%s\n",
           verify_required, verified_at_writeback, unverified_at_writeback,
           resolved, pending, other, dirty_ok ? "PASS" : "FAIL");
    /* test.c uses these two sums to calculate the average verification
       latency after report_end has frozen the BOOM snapshot. */
    printf("[VERIFY] dirty_wb_cycle_sum writeback_cycle_sum=%" PRIu64
           " verification_cycle_sum=%" PRIu64 "\n",
           writeback_cycle_sum, safe_cycle_sum);

#if TEST_REPORT_VERBOSE
    printf("[VERIFY_VERBOSE] safe_watermark=%" PRIu64
           " result_dropped=%" PRIu64 " arithmetic_overflow=%" PRIu64
           " stats_valid=%" PRIu64 "\n",
           safe_watermark, result_dropped, arithmetic_overflow, stats_valid);
#else
    if (!package_ok || !dirty_ok || safe_watermark != completed) {
        printf("[VERIFY_DIAG] safe_watermark=%" PRIu64
               " result_dropped=%" PRIu64 " arithmetic_overflow=%" PRIu64
               " stats_valid=%" PRIu64 "\n",
               safe_watermark, result_dropped, arithmetic_overflow,
               stats_valid);
    }
#endif
}

static void print_traffic_report(void)
{
    printf("[TRAFFIC] hart  store[total/cache/unc]       "
           "load[total/cache/unc/fwd]\n");
    for (int hart = 0; hart < NUM_HARTS; hart++) {
        printf("[TRAFFIC] %-5s %" PRIu64 "/%" PRIu64 "/%" PRIu64
               "                 %" PRIu64 "/%" PRIu64 "/%" PRIu64 "/%" PRIu64
               "\n",
               traffic_hart_name(hart),
               hart_traffic[hart][GHE_TRAFFIC_STORE_TOTAL],
               hart_traffic[hart][GHE_TRAFFIC_STORE_CACHE],
               hart_traffic[hart][GHE_TRAFFIC_STORE_UNCACHE],
               hart_traffic[hart][GHE_TRAFFIC_LOAD_TOTAL],
               hart_traffic[hart][GHE_TRAFFIC_LOAD_CACHE],
               hart_traffic[hart][GHE_TRAFFIC_LOAD_UNCACHE],
               hart_traffic[hart][GHE_TRAFFIC_LOAD_FORWARD]);
    }
    printf("[TRAFFIC] checker_sum store=%" PRIu64 " load=%" PRIu64 "\n",
           checker_traffic_sum(GHE_TRAFFIC_STORE_TOTAL),
           checker_traffic_sum(GHE_TRAFFIC_LOAD_TOTAL));

    uint64_t total_lr = 0;
    uint64_t total_sc_success = 0;
    uint64_t total_sc_fail = 0;
    uint64_t total_amo = 0;
    for (int hart = 0; hart < NUM_HARTS; hart++) {
        uint64_t lr = hart_traffic[hart][GHE_TRAFFIC_LR];
        uint64_t sc_success = hart_traffic[hart][GHE_TRAFFIC_SC_SUCCESS];
        uint64_t sc_fail = hart_traffic[hart][GHE_TRAFFIC_SC_FAIL];
        uint64_t amo = hart_traffic[hart][GHE_TRAFFIC_AMO_TOTAL];
        total_lr += lr;
        total_sc_success += sc_success;
        total_sc_fail += sc_fail;
        total_amo += amo;
        if (lr != 0 || sc_success != 0 || sc_fail != 0 || amo != 0) {
            printf("[TRAFFIC] atomics hart=%s lr=%" PRIu64
                   " sc_success=%" PRIu64 " sc_fail=%" PRIu64
                   " amo=%" PRIu64 "\n",
                   traffic_hart_name(hart), lr, sc_success, sc_fail, amo);
        }
    }
    /* 始终输出零值，避免因省略行而误认为计数器缺失。 */
    printf("[TRAFFIC] atomics total lr=%" PRIu64
           " sc_success=%" PRIu64 " sc_fail=%" PRIu64
           " amo=%" PRIu64 "\n",
           total_lr, total_sc_success, total_sc_fail, total_amo);

    printf("[TRAFFIC] dcache l1_l2_c=%" PRIu64 " wb_dirty=%" PRIu64
           " verify_required=%" PRIu64 "\n",
           hart_traffic[0][GHE_TRAFFIC_L1_L2_C_TOTAL],
           hart_traffic[0][GHE_TRAFFIC_L1_L2_WB_DIRTY],
           hart_traffic[0][GHE_TRAFFIC_L1_L2_WB_DIRTY_VERIFY_REQUIRED]);
    printf("[TRAFFIC] dram l2_wb_total=%" PRIu64 " l2_wb_dirty=%" PRIu64
           "\n",
           hart_traffic[0][GHE_TRAFFIC_L2_DRAM_WB_TOTAL],
           hart_traffic[0][GHE_TRAFFIC_L2_DRAM_WB_DIRTY]);
    printf("[TRAFFIC] dram_verify required=%" PRIu64
           " verified=%" PRIu64 " unverified=%" PRIu64
           " resolved=%" PRIu64 " pending=%" PRIu64 " other=%" PRIu64
           " status=%s\n",
           hart_traffic[0][GHE_TRAFFIC_L2_DRAM_WB_VERIFY_REQUIRED],
           hart_traffic[0][GHE_TRAFFIC_L2_DRAM_WB_VERIFIED],
           hart_traffic[0][GHE_TRAFFIC_L2_DRAM_WB_UNVERIFIED],
           hart_traffic[0][GHE_TRAFFIC_L2_DRAM_WB_UNVERIFIED_RESOLVED],
           hart_traffic[0][GHE_TRAFFIC_L2_DRAM_WB_UNVERIFIED_PENDING],
           hart_traffic[0][GHE_TRAFFIC_L2_DRAM_WB_OTHER],
           hart_traffic[0][GHE_TRAFFIC_L2_DRAM_WB_STATS_VALID] == 1
               ? "PASS" : "FAIL");
    printf("[TRAFFIC] dram_verify_cycle_sum writeback=%" PRIu64
           " verification=%" PRIu64 "\n",
           hart_traffic[0][GHE_TRAFFIC_L2_DRAM_WB_WRITEBACK_CYCLE_SUM],
           hart_traffic[0][GHE_TRAFFIC_L2_DRAM_WB_VERIFY_CYCLE_SUM]);
}

int report_end(uint64_t start_cpu, uint64_t end_cpu, uint64_t hart_id)
{
    (void)hart_id;
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
    int pending_ok = wait_for_boom_strict_pending();
    for (int counter = 0; counter < GHE_TRAFFIC_COUNTERS; counter++) {
        hart_traffic[0][counter] = ghe_traffic_counter_read(counter);
    }

    lock_acquire(&uart_lock);
    printf("[PERF] boom_cycles=%" PRIu64 " boom_inst=%" PRIu64 "\n",
           end_cpu - start_cpu, csr_read_e[0] - csr_read_s[0]);
    if (package_drain_status != PACKAGE_DRAIN_COMPLETE) {
        const char *reason = package_drain_status == PACKAGE_DRAIN_HARD_ERROR
                                 ? "hard_error"
                                 : "timeout";
        printf("[VERIFY_DIAG] package_drain=FAIL reason=%s"
               " allocated=%" PRIu64 " completed=%" PRIu64
               " pending=%" PRIu64 " result_dropped=%" PRIu64
               " l2_pending=%" PRIu64
               " writeback_dropped=%" PRIu64
               " arithmetic_overflow=%" PRIu64
               " elapsed_cycles=%" PRIu64 "\n",
               reason, package_drain_state.allocated,
               package_drain_state.completed, package_drain_state.pending,
               package_drain_state.l2_pending,
               package_drain_state.result_dropped,
               package_drain_state.writeback_dropped,
               package_drain_state.arithmetic_overflow,
               package_drain_state.elapsed_cycles);
    }
    print_traffic_report();
    int traffic_ok = print_boom_traffic_consistency() && pending_ok;
    printf("[LATENCY] clock=boom:%" PRIu64 "Hz checker:%" PRIu64 "Hz\n",
           (uint64_t)BOOM_CORE_FREQUENCY_HZ,
           (uint64_t)CHECKER_CORE_FREQUENCY_HZ);
    print_store_uncache_latency();
    print_unverified_dirty_writeback_summary();
    lock_release(&uart_lock);
    return package_drain_status == PACKAGE_DRAIN_COMPLETE && traffic_ok;
}
