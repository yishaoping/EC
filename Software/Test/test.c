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
/* 本测试固定为 1 个 BOOM hart 加 NUM_CHECKERS 个 Rocket checker hart。 */
#define NUM_HARTS (NUM_CHECKERS + 1)

uint64_t csr_read_s[TOTAL_CSR_PERF];
uint64_t csr_read_e[TOTAL_CSR_PERF];
/*
 * 每个 hart 保存自己的流量计数器快照：hart 0 是 BOOM，hart 1--4 是
 * checker。checker 在 secondary.c 中各自写入自己的行，最后由 hart 0
 * 统一换算和打印，避免多个 hart 并发访问 UART。
 */
volatile uint64_t hart_traffic[NUM_HARTS][GHE_TRAFFIC_COUNTERS];
/*
 * checker 完成全部 RoCC 统计读取后置 1。该标志只表示“统计值已经写入
 * hart_traffic”，不代替 GHT 的包完成状态，因此 hart 0 仍需检查 BOOM
 * 的 completed/pending 等计数。
 */
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

static void print_uint128(uint128_t value)
{
    /* 统计周期和乘以 1e9 后可能超过 64 位，使用十进制手工打印。 */
    char buffer[40];
    int index = (int)sizeof(buffer) - 1;

    buffer[index] = '\0';
    do {
        buffer[--index] = (char)('0' + value % 10);
        value /= 10;
    } while (value != 0);
    printf("%s", &buffer[index]);
}

static uint128_t cycle_sum_to_ns(uint64_t cycle_sum, uint64_t frequency_hz)
{
    /* cycle / Hz = 秒；这里直接计算 cycle * 1e9 / Hz 得到纳秒。 */
    return (uint128_t)cycle_sum * UINT64_C(1000000000) / frequency_hz;
}

static void print_store_uncache_latency(void)
{
    /*
     * BOOM 在不可缓存 store 完成时累加 BOOM CSR cycle；checker 在一个完整
     * 包检查结束时，把该包中的不可缓存 store 数乘以 checker CSR cycle
     * 加入本地总和。两类 cycle 先按各自频率换算成时间，再用总和相减：
     *
     *   平均检测延迟 ~= (四个 checker 时间总和 - BOOM 时间总和)
     *                    / 不可缓存 store 总数
     *
     * 这是总和意义上的近似平均值，不是逐事件地址匹配的精确延迟。
     */
    uint128_t hart_time_ns[NUM_HARTS];
    uint128_t checker_time_ns = 0;
    uint128_t checker_count = 0;
    uint64_t boom_count = hart_traffic[0][GHE_TRAFFIC_STORE_UNCACHE];

    for (int hart = 0; hart < NUM_HARTS; hart++) {
        /* hart 0 为 BOOM，其余 hart 使用 checker 频率。 */
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
        /* 事件数不一致时，两个总和没有相同的分母，不能计算延迟。 */
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
    /* 保留负号作为时间点/频率配置异常的诊断信息，不强行取绝对值。 */
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

static void print_unverified_dirty_writeback_latency(void)
{
    /*
     * 该函数只处理 BOOM L1->L2 的未校验脏写回，不涉及 L2->DRAM。
     * 写回发生时，硬件根据缓存行保存的包序号和当时安全水位分类；若
     * 尚未安全，则把写回 cycle 放入对应序号桶。之后安全水位前进时，
     * 硬件用水位到达时的 CSR cycle 结算这些桶。因此：
     *
     *   延迟周期总和 = safe_cycle_sum - writeback_cycle_sum
     *   平均延迟     = 延迟周期总和 / resolved
     *
     * resolved 而不是 seen 是分母，因为只有成功进入桶并完成结算的样本
     * 才同时拥有写回时刻和安全时刻。任何丢包、失败包、桶丢弃或溢出都会
     * 使统计失去完整性，下面的检查会拒绝打印平均值。
     */
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
    /*
     * 五项验证统计满足两层守恒关系：前两项覆盖全部需要校验的
     * 脏写回，后三项进一步覆盖写回时尚未校验的脏写回。
     */
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

    /*
     * 只有在窗口完整收敛且分类守恒时才输出平均值：
     * - pending/other/result_dropped 表示样本或包结果尚未可靠归档；
     * - failed/cancelled 表示包没有得到“通过”意义下的安全水位；
     * - completed/passed 和脏写回分类核对保证分母与分子对应同一批事件。
     */
    if (stats_valid != 1 || pending != 0 || other != 0 ||
        result_dropped != 0 || arithmetic_overflow != 0 || failed != 0 ||
        cancelled != 0 ||
        completed != allocated || passed != completed ||
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

    /* 两个总和都在 BOOM CSR 时钟域，先相减再除以已结算样本数。 */
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

int main(void)
{
    /* 初始化 GHT、CSR 和软件中断环境；checker 由 secondary.c 并行启动。 */
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

    /*
     * RESET 清空 BOOM DCache 的统计窗口，START 开始记录本次工作负载。
     * 包完成和 checker 结果在硬件中仍会继续排空，不能把 START 当成同步屏障。
     */
    ghe_fpga_perf_reset();
    ghe_fpga_perf_start();

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
                /* 将寄存器约束和访存/原子操作放在同一汇编块中，避免编译器
                 * 重排测试数据相关指令；这里的工作负载会产生多类访存事件。 */
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

    /*
     * 先等待四个 checker 把本地计数器读出并写入共享数组。ready 只表示
     * 软件快照已经可读；随后还要等待 BOOM 的包生命周期和写回桶收敛。
     */
    while (hart_traffic_ready[1] == 0 || hart_traffic_ready[2] == 0 ||
           hart_traffic_ready[3] == 0 || hart_traffic_ready[4] == 0) {
    }
    __sync_synchronize();

    /*
     * stats_valid 在首个失败包到达时就会清零，但此时后续包结果仍可能在途。
     * 因此继续排空包生命周期和写回桶，只在完整收敛、不可恢复的计数错误
     * 或有界超时后结束，避免把“统计无效”误报成“统计已经排空”。
     */
    package_drain_state_t package_drain_state = {0};
    package_drain_status_t package_drain_status =
        wait_for_package_statistics_to_drain(&package_drain_state);

    /*
     * STOP 冻结一次一致的 BOOM DCache 快照。之后的 RoCC 读回会写软件内存，
     * 这些读回本身可能引起新的访存，必须放在 STOP 之后以免污染统计窗口。
     */
    ghe_fpga_perf_stop();

    /* 快照冻结后逐项读取 hart 0 的完整统计向量。 */
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
    printf("[Boom-C%lx]: Test is now completed. \r\n", Hart_id);
    lock_release(&uart_lock);

    ght_unset_satp_priv();
    ROCC_INSTRUCTION(1, 0x30);
    return 0;
}
