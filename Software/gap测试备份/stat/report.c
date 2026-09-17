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

static void format_uint128_fixed(char *buffer, size_t buffer_size,
                                 uint128_t integer,
                                 uint64_t fraction_thousandths, int negative)
{
    char digits[40];
    int index = (int)sizeof(digits) - 1;

    digits[index] = '\0';
    do {
        digits[--index] = (char)('0' + integer % 10);
        integer /= 10;
    } while (integer != 0);
    snprintf(buffer, buffer_size, "%s%s.%03" PRIu64,
             negative ? "-" : "", &digits[index], fraction_thousandths);
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

static void print_traffic_row(const char *source,
                              uint64_t store_total, uint64_t store_cache,
                              uint64_t store_uncache, uint64_t load_total,
                              uint64_t load_cache, uint64_t load_uncache,
                              int has_load_response, uint64_t load_response,
                              int has_load_forward, uint64_t load_forward)
{
    printf("[TRAFFIC] %-11s %10" PRIu64 " %10" PRIu64 " %10" PRIu64
           " %10" PRIu64 " %10" PRIu64 " %10" PRIu64,
           source, store_total, store_cache, store_uncache,
           load_total, load_cache, load_uncache);
    if (has_load_response) {
        printf(" %10" PRIu64, load_response);
    } else {
        printf(" %10s", "-");
    }
    if (has_load_forward) {
        printf(" %10" PRIu64, load_forward);
    } else {
        printf(" %10s", "-");
    }
    printf("\n");
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

/* 表格输出 BOOM 架构、严格路径与 checker 口径，并执行一致性断言。 */
static int print_boom_traffic_consistency(void)
{
    const volatile uint64_t *boom = hart_traffic[0];
    uint64_t arch_store = boom[GHE_TRAFFIC_STORE_TOTAL];
    uint64_t arch_store_cache = boom[GHE_TRAFFIC_STORE_CACHE];
    uint64_t arch_store_uncache = boom[GHE_TRAFFIC_STORE_UNCACHE];
    uint64_t arch_load = boom[GHE_TRAFFIC_LOAD_TOTAL];
    uint64_t arch_load_cache = boom[GHE_TRAFFIC_LOAD_CACHE];
    uint64_t arch_load_uncache = boom[GHE_TRAFFIC_LOAD_UNCACHE];

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

    printf("[TRAFFIC] %-11s %10s %10s %10s %10s %10s %10s %10s %10s\n",
           "source", "st_total", "st_cache", "st_uncache", "ld_total",
           "ld_cache", "ld_uncache", "ld_response", "ld_forward");
    print_traffic_row("boom_arch", arch_store, arch_store_cache,
                      arch_store_uncache, arch_load, arch_load_cache,
                      arch_load_uncache, 0, 0, 0, 0);
    print_traffic_row("boom_strict", strict_store, strict_store_cache,
                      strict_store_uncache, strict_load, strict_load_cache,
                      strict_load_uncache, 1, strict_load_response,
                      1, strict_load_forward);
    print_traffic_row("checker_sum", checker_store, checker_store_cache,
                      checker_store_uncache, checker_load, checker_load_cache,
                      checker_load_uncache, 0, 0, 1, checker_load_forward);
    for (int hart = 1; hart < NUM_HARTS; hart++) {
        print_traffic_row(traffic_hart_name(hart),
                          hart_traffic[hart][GHE_TRAFFIC_STORE_TOTAL],
                          hart_traffic[hart][GHE_TRAFFIC_STORE_CACHE],
                          hart_traffic[hart][GHE_TRAFFIC_STORE_UNCACHE],
                          hart_traffic[hart][GHE_TRAFFIC_LOAD_TOTAL],
                          hart_traffic[hart][GHE_TRAFFIC_LOAD_CACHE],
                          hart_traffic[hart][GHE_TRAFFIC_LOAD_UNCACHE],
                          0, 0, 1,
                          hart_traffic[hart][GHE_TRAFFIC_LOAD_FORWARD]);
    }

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

    if (!store_ok || !store_class_ok) {
        printf("[ASSERT] store arch=%" PRIu64 " strict=%" PRIu64
               " checker=%" PRIu64 " result=FAIL\n",
               arch_store, strict_store, checker_store);
        print_counter_difference("store_arch_minus_strict",
                                 arch_store, strict_store);
        print_counter_difference("store_arch_minus_checker",
                                 arch_store, checker_store);
        print_counter_difference("store_cache_arch_minus_strict",
                                 arch_store_cache, strict_store_cache);
        print_counter_difference("store_uncache_arch_minus_strict",
                                 arch_store_uncache, strict_store_uncache);
        print_counter_difference("store_cache_arch_minus_checker",
                                 arch_store_cache, checker_store_cache);
        print_counter_difference("store_uncache_arch_minus_checker",
                                 arch_store_uncache, checker_store_uncache);
    }
    if (!load_ok || !load_class_ok || !path_ok || !checker_path_ok) {
        printf("[ASSERT] load arch=%" PRIu64 " strict=%" PRIu64
               " checker=%" PRIu64 " result=FAIL\n",
               arch_load, strict_load, checker_load);
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
        print_counter_difference("load_cache_arch_minus_checker",
                                 arch_load_cache, checker_load_cache);
        print_counter_difference("load_uncache_arch_minus_checker",
                                 arch_load_uncache, checker_load_uncache);
    }
    if (!counter_ok) {
        printf("[ASSERT] traffic_counter_fail=%" PRIu64
               " pending=%" PRIu64 " result=FAIL\n",
               boom[GHE_TRAFFIC_COUNTER_ASSERT_FAIL],
               boom[GHE_TRAFFIC_STRICT_PENDING]);
    }
    return store_ok && load_ok && store_class_ok && load_class_ok && path_ok &&
           checker_path_ok && counter_ok;
}

static void print_latency_header(void)
{
    printf("[LATENCY] %-22s %10s %-8s %12s %14s %14s\n",
           "metric", "events", "clock", "frequency_hz",
           "avg_cycles", "avg_ns");
}

static void print_latency_row(const char *metric, uint64_t events,
                              const char *clock, uint64_t frequency_hz,
                              int negative, uint128_t average_cycles,
                              uint64_t average_cycle_fraction,
                              uint128_t average_ns,
                              uint64_t average_ns_fraction)
{
    char cycles[48];
    char ns[48];

    format_uint128_fixed(cycles, sizeof(cycles), average_cycles,
                         average_cycle_fraction, negative);
    format_uint128_fixed(ns, sizeof(ns), average_ns,
                         average_ns_fraction, negative);
    printf("[LATENCY] %-22s %10" PRIu64 " %-8s %12" PRIu64
           " %14s %14s\n",
           metric, events, clock, frequency_hz, cycles, ns);
}

static void print_latency_unavailable(const char *metric, uint64_t events,
                                      const char *clock,
                                      uint64_t frequency_hz,
                                      const char *reason)
{
    printf("[LATENCY] %-22s %10" PRIu64 " %-8s %12" PRIu64
           " %14s %14s reason=%s\n",
           metric, events, clock, frequency_hz, "n/a", "n/a", reason);
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
        uint64_t event_count = hart == 0
                                   ? boom_count
                                   : hart_traffic[hart]
                                         [GHE_TRAFFIC_STORE_UNCACHE];

        hart_time_ns[hart] = cycle_sum_to_ns(cycle_sum, frequency_hz);
#if TEST_REPORT_VERBOSE
        printf("[LATENCY_VERBOSE] hart=%s events=%" PRIu64
               " cycle_sum=%" PRIu64 " time_sum_ns=",
               traffic_hart_name(hart), event_count, cycle_sum);
        print_uint128(hart_time_ns[hart]);
        printf(" frequency_hz=%" PRIu64 "\n", frequency_hz);
#endif

        if (hart != 0) {
            checker_time_ns += hart_time_ns[hart];
            checker_count += event_count;
        }
    }

    if (checker_count != (uint128_t)boom_count) {
        print_latency_unavailable("store_uncache", boom_count, "boom_eq",
                                  BOOM_CORE_FREQUENCY_HZ,
                                  "count_mismatch");
        printf("[LATENCY_DIAG] store_uncache boom_events=%" PRIu64
               " checker_events=", boom_count);
        print_uint128(checker_count);
        printf("\n");
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
        print_latency_unavailable("store_uncache", 0, "boom_eq",
                                  BOOM_CORE_FREQUENCY_HZ, "no_events");
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

    print_latency_row("store_uncache", boom_count, "boom_eq",
                      BOOM_CORE_FREQUENCY_HZ, negative, average_cycles,
                      average_cycle_fraction, average_ns,
                      average_ns_fraction);
#if TEST_REPORT_VERBOSE
    printf("[LATENCY_VERBOSE] boom_time_sum_ns=");
    print_uint128(hart_time_ns[0]);
    printf(" checker_time_sum_ns=");
    print_uint128(checker_time_ns);
    printf("\n");
#endif
}

/* Package 状态先于所有流量表输出。 */
static void print_package_verification_summary(void)
{
    const volatile uint64_t *traffic = hart_traffic[0];
    uint64_t failed = traffic[GHE_TRAFFIC_FAILED_PACKAGES];
    uint64_t stats_valid =
        traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_STATS_VALID];
    uint64_t result_dropped = traffic[GHE_TRAFFIC_PACKAGE_RESULT_DROPPED];
    uint64_t allocated = traffic[GHE_TRAFFIC_ALLOCATED_PACKAGES];
    uint64_t completed = traffic[GHE_TRAFFIC_COMPLETED_PACKAGES];
    uint64_t passed = traffic[GHE_TRAFFIC_PASSED_PACKAGES];
    uint64_t cancelled = traffic[GHE_TRAFFIC_CANCELLED_PACKAGES];
    uint64_t arithmetic_overflow =
        traffic[GHE_TRAFFIC_STATS_ARITHMETIC_OVERFLOW];
    uint64_t safe_watermark = traffic[GHE_TRAFFIC_SAFE_PACKET_WATERMARK];
    int package_ok = stats_valid == 1 && result_dropped == 0 &&
                     arithmetic_overflow == 0 && failed == 0 &&
                     cancelled == 0 && completed == allocated &&
                     passed == completed;

    if (package_ok) {
        printf("[VERIFY] packages allocated=%" PRIu64
               " completed=%" PRIu64 " passed=%" PRIu64 " status=PASS\n",
               allocated, completed, passed);
    } else {
        printf("[VERIFY] packages allocated=%" PRIu64
               " completed=%" PRIu64 " passed=%" PRIu64
               " failed=%" PRIu64 " cancelled=%" PRIu64
               " status=FAIL\n",
               allocated, completed, passed, failed, cancelled);
    }

#if TEST_REPORT_VERBOSE
    printf("[VERIFY_VERBOSE] safe_watermark=%" PRIu64
           " result_dropped=%" PRIu64 " arithmetic_overflow=%" PRIu64
           " stats_valid=%" PRIu64 "\n",
           safe_watermark, result_dropped, arithmetic_overflow, stats_valid);
#else
    if (!package_ok || safe_watermark != completed) {
        printf("[VERIFY_DIAG] safe_watermark=%" PRIu64
               " result_dropped=%" PRIu64 " arithmetic_overflow=%" PRIu64
               " stats_valid=%" PRIu64 "\n",
               safe_watermark, result_dropped, arithmetic_overflow,
               stats_valid);
    }
#endif
}

static void print_dirty_writeback_latency(void)
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
    uint64_t resolved = traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_RESOLVED];
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

    const char *reason = NULL;
    if (stats_valid != 1 || pending != 0 || other != 0 ||
        result_dropped != 0 || failed != 0 || cancelled != 0 ||
        arithmetic_overflow != 0 || completed != allocated ||
        passed != completed || resolved != unverified_at_writeback ||
        (uint128_t)verify_required !=
            (uint128_t)verified_at_writeback + unverified_at_writeback ||
        (uint128_t)dirty_wb_total !=
            (uint128_t)verify_required + nonverify_dirty_wb) {
        reason = "statistics_invalid";
    } else if (resolved == 0) {
        reason = "no_events";
    } else if (verification_cycle_sum < writeback_cycle_sum) {
        reason = "cycle_sum_underflow";
    }
    if (reason != NULL) {
        print_latency_unavailable("dirty_wb", resolved, "boom",
                                  BOOM_CORE_FREQUENCY_HZ, reason);
        return;
    }

    uint64_t latency_cycle_sum =
        verification_cycle_sum - writeback_cycle_sum;
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

    print_latency_row("dirty_wb", resolved, "boom", BOOM_CORE_FREQUENCY_HZ,
                      0, average_cycles, average_cycle_fraction,
                      average_ns, average_ns_fraction);
}

static void print_l2_dram_dirty_writeback_latency(void)
{
    const volatile uint64_t *traffic = hart_traffic[0];
    uint64_t total = traffic[GHE_TRAFFIC_L2_DRAM_WB_TOTAL];
    uint64_t dirty = traffic[GHE_TRAFFIC_L2_DRAM_WB_DIRTY];
    uint64_t required = traffic[GHE_TRAFFIC_L2_DRAM_WB_VERIFY_REQUIRED];
    uint64_t verified = traffic[GHE_TRAFFIC_L2_DRAM_WB_VERIFIED];
    uint64_t unverified = traffic[GHE_TRAFFIC_L2_DRAM_WB_UNVERIFIED];
    uint64_t resolved = traffic[GHE_TRAFFIC_L2_DRAM_WB_UNVERIFIED_RESOLVED];
    uint64_t pending = traffic[GHE_TRAFFIC_L2_DRAM_WB_UNVERIFIED_PENDING];
    uint64_t nonverify = traffic[GHE_TRAFFIC_L2_DRAM_WB_NONVERIFY];
    uint64_t other = traffic[GHE_TRAFFIC_L2_DRAM_WB_OTHER];
    uint64_t writeback_sum =
        traffic[GHE_TRAFFIC_L2_DRAM_WB_WRITEBACK_CYCLE_SUM];
    uint64_t verify_sum = traffic[GHE_TRAFFIC_L2_DRAM_WB_VERIFY_CYCLE_SUM];
    uint64_t valid = traffic[GHE_TRAFFIC_L2_DRAM_WB_STATS_VALID];

    const char *reason = NULL;
    if (valid != 1 || pending != 0 || other != 0 || resolved != unverified ||
        total < dirty || (uint128_t)dirty !=
            (uint128_t)required + nonverify ||
        (uint128_t)required != (uint128_t)verified + unverified ||
        verify_sum < writeback_sum) {
        reason = "statistics_invalid";
    } else if (resolved == 0) {
        reason = "no_events";
    }
    if (reason != NULL) {
        print_latency_unavailable("l2_dram_dirty_wb", resolved, "l2",
                                  L2_CORE_FREQUENCY_HZ, reason);
        return;
    }

    uint64_t latency_sum = verify_sum - writeback_sum;
    uint64_t average_cycles = latency_sum / resolved;
    uint64_t average_fraction = (uint64_t)(
        ((uint128_t)(latency_sum % resolved) * 1000) / resolved);
    uint128_t ns_numerator =
        (uint128_t)latency_sum * UINT64_C(1000000000);
    uint128_t ns_denominator =
        (uint128_t)L2_CORE_FREQUENCY_HZ * resolved;
    uint128_t average_ns = ns_numerator / ns_denominator;
    uint64_t ns_fraction =
        (uint64_t)(((ns_numerator % ns_denominator) * 1000) / ns_denominator);

    print_latency_row("l2_dram_dirty_wb", resolved, "l2",
                      L2_CORE_FREQUENCY_HZ, 0, average_cycles,
                      average_fraction, average_ns, ns_fraction);
}

static void print_cache_traffic_row(const char *path,
                                    uint64_t total, uint64_t dirty,
                                    uint64_t verify_required,
                                    uint64_t verified, uint64_t unverified,
                                    uint64_t resolved, uint64_t nonverify,
                                    int status_ok)
{
    printf("[TRAFFIC] %-8s %10" PRIu64 " %10" PRIu64 " %15" PRIu64
           " %10" PRIu64 " %10" PRIu64 " %10" PRIu64,
           path, total, dirty, verify_required, verified, unverified, resolved);
    printf(" %10" PRIu64, nonverify);
    printf(" %-6s\n", status_ok ? "PASS" : "FAIL");
}

static int print_cache_hierarchy_traffic_report(void)
{
    const volatile uint64_t *traffic = hart_traffic[0];
    uint64_t l1_total = traffic[GHE_TRAFFIC_L1_L2_C_TOTAL];
    uint64_t l1_dirty = traffic[GHE_TRAFFIC_L1_L2_WB_DIRTY];
    uint64_t l1_required =
        traffic[GHE_TRAFFIC_L1_L2_WB_DIRTY_VERIFY_REQUIRED];
    uint64_t l1_verified = traffic[GHE_TRAFFIC_VERIFIED_DIRTY_WB];
    uint64_t l1_unverified = traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_SEEN];
    uint64_t l1_resolved = traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_RESOLVED];
    uint64_t l1_pending = traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_PENDING];
    uint64_t l1_other = traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_OTHER];
    uint64_t l1_nonverify = traffic[GHE_TRAFFIC_NONVERIFY_DIRTY_WB];
    uint64_t failed = traffic[GHE_TRAFFIC_FAILED_PACKAGES];
    uint64_t cancelled = traffic[GHE_TRAFFIC_CANCELLED_PACKAGES];
    uint64_t allocated = traffic[GHE_TRAFFIC_ALLOCATED_PACKAGES];
    uint64_t completed = traffic[GHE_TRAFFIC_COMPLETED_PACKAGES];
    uint64_t passed = traffic[GHE_TRAFFIC_PASSED_PACKAGES];
    uint64_t result_dropped = traffic[GHE_TRAFFIC_PACKAGE_RESULT_DROPPED];
    uint64_t arithmetic_overflow =
        traffic[GHE_TRAFFIC_STATS_ARITHMETIC_OVERFLOW];
    uint64_t l1_stats_valid =
        traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_STATS_VALID];
    uint64_t l1_writeback_sum =
        traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_CYCLE_SUM];
    uint64_t l1_verify_sum =
        traffic[GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_SAFE_CYCLE_SUM];
    int l1_ok = l1_stats_valid == 1 && l1_pending == 0 && l1_other == 0 &&
                l1_total >= l1_dirty && l1_verify_sum >= l1_writeback_sum &&
                result_dropped == 0 && arithmetic_overflow == 0 &&
                failed == 0 && cancelled == 0 &&
                completed == allocated && passed == completed &&
                (uint128_t)l1_required ==
                    (uint128_t)l1_verified + l1_unverified &&
                l1_resolved == l1_unverified &&
                (uint128_t)l1_dirty ==
                    (uint128_t)l1_required + l1_nonverify;

    uint64_t l2_total = traffic[GHE_TRAFFIC_L2_DRAM_WB_TOTAL];
    uint64_t l2_dirty = traffic[GHE_TRAFFIC_L2_DRAM_WB_DIRTY];
    uint64_t l2_required = traffic[GHE_TRAFFIC_L2_DRAM_WB_VERIFY_REQUIRED];
    uint64_t l2_verified = traffic[GHE_TRAFFIC_L2_DRAM_WB_VERIFIED];
    uint64_t l2_unverified = traffic[GHE_TRAFFIC_L2_DRAM_WB_UNVERIFIED];
    uint64_t l2_resolved =
        traffic[GHE_TRAFFIC_L2_DRAM_WB_UNVERIFIED_RESOLVED];
    uint64_t l2_pending = traffic[GHE_TRAFFIC_L2_DRAM_WB_UNVERIFIED_PENDING];
    uint64_t l2_nonverify = traffic[GHE_TRAFFIC_L2_DRAM_WB_NONVERIFY];
    uint64_t l2_other = traffic[GHE_TRAFFIC_L2_DRAM_WB_OTHER];
    uint64_t l2_writeback_sum =
        traffic[GHE_TRAFFIC_L2_DRAM_WB_WRITEBACK_CYCLE_SUM];
    uint64_t l2_verify_sum =
        traffic[GHE_TRAFFIC_L2_DRAM_WB_VERIFY_CYCLE_SUM];
    uint64_t l2_stats_valid = traffic[GHE_TRAFFIC_L2_DRAM_WB_STATS_VALID];
    int l2_ok = l2_stats_valid == 1 && l2_pending == 0 &&
                l2_resolved == l2_unverified && l2_total >= l2_dirty &&
                (uint128_t)l2_required ==
                    (uint128_t)l2_verified + l2_unverified &&
                (uint128_t)l2_dirty ==
                    (uint128_t)l2_required + l2_nonverify &&
                l2_other == 0 &&
                l2_verify_sum >= l2_writeback_sum;

    printf("[TRAFFIC] %-8s %10s %10s %15s %10s %10s %10s %10s %-6s\n",
           "path", "total", "dirty", "verify_required", "verified",
           "unverified", "resolved", "nonverify", "status");
    print_cache_traffic_row("L1-L2", l1_total, l1_dirty, l1_required,
                            l1_verified, l1_unverified, l1_resolved,
                            l1_nonverify, l1_ok);
    print_cache_traffic_row("L2-DRAM", l2_total, l2_dirty, l2_required,
                            l2_verified, l2_unverified, l2_resolved,
                            l2_nonverify, l2_ok);

    if (!l1_ok) {
        printf("[TRAFFIC_DIAG] L1-L2 status=FAIL");
        if (l1_pending != 0) printf(" pending=%" PRIu64, l1_pending);
        if (l1_other != 0) printf(" other=%" PRIu64, l1_other);
        if (result_dropped != 0) printf(" result_dropped=%" PRIu64,
                                        result_dropped);
        if (arithmetic_overflow != 0)
            printf(" arithmetic_overflow=%" PRIu64, arithmetic_overflow);
        if (l1_stats_valid != 1) printf(" stats_valid=%" PRIu64, l1_stats_valid);
        printf("\n");
    }
    if (!l2_ok) {
        printf("[TRAFFIC_DIAG] L2-DRAM status=FAIL");
        if (l2_pending != 0) printf(" pending=%" PRIu64, l2_pending);
        if (l2_other != 0) printf(" other=%" PRIu64, l2_other);
        if (l2_stats_valid != 1)
            printf(" stats_valid=%" PRIu64, l2_stats_valid);
        printf("\n");
    }
#if TEST_REPORT_VERBOSE
    printf("[TRAFFIC_VERBOSE] L1-L2 cycle_sum writeback=%" PRIu64
           " verification=%" PRIu64 "\n",
           l1_writeback_sum, l1_verify_sum);
    printf("[TRAFFIC_VERBOSE] L2-DRAM cycle_sum writeback=%" PRIu64
           " verification=%" PRIu64 "\n",
           l2_writeback_sum, l2_verify_sum);
#endif
    return l1_ok && l2_ok;
}

static int print_auxiliary_traffic_report(void)
{
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
    if (total_lr != 0 || total_sc_success != 0 || total_sc_fail != 0 ||
        total_amo != 0) {
        printf("[TRAFFIC] atomics total lr=%" PRIu64
               " sc_success=%" PRIu64 " sc_fail=%" PRIu64
               " amo=%" PRIu64 "\n",
               total_lr, total_sc_success, total_sc_fail, total_amo);
    }

    return print_cache_hierarchy_traffic_report();
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
               " pending=%" PRIu64 " l2_pending=%" PRIu64
               " result_dropped=%" PRIu64
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
    print_package_verification_summary();
    int traffic_ok = print_boom_traffic_consistency() && pending_ok;
    int cache_traffic_ok = print_auxiliary_traffic_report();
    print_latency_header();
    print_store_uncache_latency();
    print_dirty_writeback_latency();
    print_l2_dram_dirty_writeback_latency();
    lock_release(&uart_lock);
    return package_drain_status == PACKAGE_DRAIN_COMPLETE && traffic_ok &&
           cache_traffic_ok;
}
