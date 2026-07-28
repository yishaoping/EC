/**
 * @file    test_runtime.c
 * @brief   GuardianCouncil 测试的多核同步、完成等待和统计实现
 *
 * @details 每个 hart 在本地工作结束时通过 ROCC funct=0x79 读取硬件
 *          Storecount 与 128 位 Storecyclesum。checker 由 tasks.c 的完成
 *          钩子发布数据，hart 0 在停止监控后发布数据；ready 标志和 fence
 *          构成最小的跨核共享内存发布协议。
 */

#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "rocc.h"
#include "clint.h"
#include "ght.h"
#include "tasks.h"
#include "test_config.h"
#include "test_runtime.h"

// 128 位累计值避免大量 store 的周期总和溢出 64 位。
typedef unsigned __int128 test_uint128_t;

// 仅本模块拥有共享结果；ready 在数据写完并执行 fence 后才置位。
static volatile uint64_t storecount_results[TEST_NUM_CORES] = {0};
static volatile test_uint128_t cyclesum_ns_results[TEST_NUM_CORES] = {0};
static volatile uint32_t storecount_ready[TEST_NUM_CORES] = {0};

/** @brief 读取当前 hart 的 cycle CSR，用作性能测量和轮询超时基准。 */
uint64_t test_read_cycles(void)
{
    uint64_t cycles;
    asm volatile("rdcycle %0" : "=r"(cycles));
    return cycles;
}

/** @brief 判断 hart 是否为本次测试启用的 checker（hart 1~4）。 */
int test_is_checker_hart(uint64_t hart_id)
{
    return hart_id > 0 && hart_id < TEST_NUM_CORES;
}

/**
 * @brief  等待 GHT 报告全局检查完成。
 * @param  last_status 非空时返回最后一次读取的硬件状态，便于超时诊断。
 * @return 1 表示状态达到 TEST_GHT_DONE_STATUS；0 表示等待超时。
 */
int test_wait_for_ght_done(uint64_t *last_status)
{
    uint64_t start_wait = test_read_cycles();
    uint64_t status = 0;

    while ((status = ght_get_status()) < TEST_GHT_DONE_STATUS) {
        if ((test_read_cycles() - start_wait) > TEST_GHT_DONE_WAIT_CYCLES) {
            if (last_status != NULL) {
                *last_status = status;
            }
            return 0;
        }
    }

    if (last_status != NULL) {
        *last_status = status;
    }
    return 1;
}

/** @brief 返回 hart 所在时钟域的配置频率，用于周期到纳秒的换算。 */
static uint32_t configured_hart_clock_mhz(uint64_t hart_id)
{
    return hart_id == 0 ? TEST_MAIN_HART_CLOCK_MHZ : TEST_CHECKER_HART_CLOCK_MHZ;
}

/**
 * @brief  读取 Storecount 扩展计数器的一个 64 位选择项。
 * @note   funct=0x79，select=0 读取 store 数；select=2/3 读取累计周期低/高位。
 */
static uint64_t read_store_counter_word(uint64_t select)
{
    uint64_t value = 0;
    ROCC_INSTRUCTION_DS(1, value, select, 0x79);
    return value;
}

static uint64_t read_storecount(void)
{
    return read_store_counter_word(0x0);
}

/** @brief 组合硬件返回的低、高 64 位，得到 128 位累计 store 周期。 */
static test_uint128_t read_storecyclesum_cycles(void)
{
    test_uint128_t low = read_store_counter_word(0x2);
    test_uint128_t high = read_store_counter_word(0x3);
    return low | (high << 64);
}

/**
 * @brief  按 hart 时钟频率把累计周期换算为纳秒。
 * @note   换算式为 cycles * 1000 / MHz，因此频率常量必须匹配硬件配置。
 */
static test_uint128_t convert_cyclesum_to_ns(test_uint128_t cyclesum, uint64_t hart_id)
{
    if (hart_id >= TEST_NUM_CORES) {
        return 0;
    }

    return (cyclesum * (test_uint128_t)1000U) /
           (test_uint128_t)configured_hart_clock_mhz(hart_id);
}

/**
 * @brief  发布一个 hart 的硬件统计快照。
 * @details 先写数据，再执行 fence，最后置 ready；主核据此避免读取半更新值。
 */
void test_publish_storecount(uint64_t hart_id)
{
    if (hart_id >= TEST_NUM_CORES) {
        return;
    }

    storecount_results[hart_id] = read_storecount();
    cyclesum_ns_results[hart_id] =
        convert_cyclesum_to_ns(read_storecyclesum_cycles(), hart_id);
    asm volatile("fence rw, rw" ::: "memory");
    storecount_ready[hart_id] = 1;
    asm volatile("fence rw, rw" ::: "memory");
}

/** @brief 检查所有 5 个 hart 是否已经发布 Storecount 统计。 */
static int all_storecounts_ready(void)
{
    for (int hart_id = 0; hart_id < TEST_NUM_CORES; hart_id++) {
        if (storecount_ready[hart_id] == 0) {
            return 0;
        }
    }

    asm volatile("fence rw, rw" ::: "memory");
    return 1;
}

/** @brief 带超时等待所有 hart 发布统计，防止 checker 异常时永久挂起。 */
int test_wait_for_storecounts(void)
{
    uint64_t start_wait = test_read_cycles();

    while (!all_storecounts_ready()) {
        if ((test_read_cycles() - start_wait) > TEST_STORECOUNT_WAIT_CYCLES) {
            return 0;
        }
    }

    return 1;
}

/** @brief 用十进制打印无标准 printf 格式支持的 unsigned __int128。 */
static void print_u128(test_uint128_t value)
{
    char buffer[40];
    int index = (int)sizeof(buffer) - 1;

    buffer[index] = '\0';
    if (value == 0) {
        printf("0");
        return;
    }

    while (value != 0 && index > 0) {
        buffer[--index] = '0' + (int)(value % 10);
        value /= 10;
    }

    printf("%s", &buffer[index]);
}

/**
 * @brief  输出逐 hart 的 store 数量、累计纳秒和派生平均值。
 * @details Cycle Avg 使用 checker 累计值之和减去主核累计值，再除以主核
 *          Storecount。该公式是当前实验定义的派生指标，不等同于单次访存
 *          的通用硬件延迟；任一统计未就绪时平均值输出 0。
 */
void test_print_storecount_report(int storecounts_done)
{
    for (int hart_id = 0; hart_id < TEST_NUM_CORES; hart_id++) {
        if (storecount_ready[hart_id] != 0) {
            printf("Storecount[%d] = %" PRIu64 " \r\n", hart_id, storecount_results[hart_id]);
            printf("Cyclesum[%d] = ", hart_id);
            print_u128(cyclesum_ns_results[hart_id]);
            printf(" ns \r\n");
        } else {
            printf("Storecount[%d] = not-ready \r\n", hart_id);
            printf("Cyclesum[%d] = not-ready \r\n", hart_id);
        }
    }

    test_uint128_t cycle_sum = 0;
    for (int hart_id = 1; hart_id < TEST_NUM_CORES; hart_id++) {
        cycle_sum += cyclesum_ns_results[hart_id];
    }

    cycle_sum = cycle_sum > cyclesum_ns_results[0]
                    ? cycle_sum - cyclesum_ns_results[0]
                    : 0;
    test_uint128_t cycle_average =
        (storecounts_done && storecount_results[0] != 0)
            ? cycle_sum / storecount_results[0]
            : 0;

    printf("Cycle Avg:");
    print_u128(cycle_average);
    printf(" ns \r\n");
}

/** @brief tasks.c 在 checker 完成比对后调用，用于发布该 hart 的统计。 */
void checker_complete_hook(uint64_t hart_id)
{
    test_publish_storecount(hart_id);
}

/**
 * @brief tasks.c 在 checker 宣告 GHE 就绪后调用。
 * @details 每个 checker 在进入重放前执行一次软件中断冒烟测试，并配置
 *          周期性机器定时器，从而让检查窗口覆盖中断/异常相关状态变化。
 */
void checker_initialised_hook(uint64_t hart_id)
{
    if (!test_is_checker_hart(hart_id)) {
        return;
    }

    csr_software_cfg();
    msip_cfg();
    mtimecmp_cfg();
    csr_timer_cfg();
}
