/**
 * @file    test.c
 * @brief   GuardianCouncil 大核/checker 核协同验证测试入口
 *
 * @details 本程序验证的不是普通 SMP 并行计算，而是 GuardianCouncil 的
 *          checkpoint-and-replay 冗余校验链路：hart 0 上的 BOOM 大核执行
 *          指令负载并产生检查包，hart 1~4 上的 checker 核从大核上下文
 *          快照开始重放检查窗口，并对 load/store、CSR、控制流和寄存器
 *          结束状态进行硬件辅助校验。
 *
 *          本文件仅保留流程编排；配置、负载、运行时同步和 checker 实现
 *          分别位于 test_config.h、test_workload.c、test_runtime.c 和 tasks.c。
 */

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#include "rocc.h"
#include "clint.h"
#include "ghe.h"
#include "ght.h"
#include "gth_init.h"
#include "spin_lock.h"
#include "tasks.h"
#include "test_config.h"
#include "test_runtime.h"
#include "test_workload.h"

/**
 * @brief  hart 0 主测试入口。
 *
 * @details 依次完成 GHT 过滤/调度配置、各核中断冒烟测试、checker 就绪
 *          同步、检查窗口启动、混合指令负载执行、硬件完成等待及性能统计。
 * @return 0。超时只通过串口报告，当前测试不会用返回码表达失败。
 */
int main(void)
{
    // 配置被追踪的指令类型，并把四个 checker 映射到四个执行单元。
    r_ini(TEST_NUM_CHECKERS);

    // 向 hart 0 自身发送 MSIP，用于覆盖软件中断进入和清除路径。
    csr_software_cfg();
    msip_cfg();

    lock_acquire(&uart_lock);
    printf("Software interrupt test complete!\n");
    lock_release(&uart_lock);

    // 所有 checker 在 ghe_initailised(1) 后，此状态才会变为非零。
    while (ght_get_initialisation() == 0) {
    }

    uint64_t hart_id = 0;
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));

    lock_acquire(&uart_lock);
    printf("[Boom-C%" PRIx64 "]: Test is now started: \r\n", hart_id);
    lock_release(&uart_lock);

    // 清零并启动 GHE 性能计数，保存监控开始前的提交指令计数。
    ghe_perf_ctrl(0x01);
    ghe_perf_ctrl(0x00);
    uint64_t instruction_count_start = ghe_csr_perf_read(0);

    // 让硬件捕获主核地址空间/特权上下文，并同时覆盖机器定时器中断。
    ght_set_satp_priv();
    mtimecmp_cfg();
    csr_timer_cfg();

    // 0x31 打开大核监控；0x70/rs1=1 启动检查窗口调度。
    ROCC_INSTRUCTION(1, 0x31);
    ROCC_INSTRUCTION_S(1, 0x01, 0x70);

    // 负载刻意混合 FP、CSR、异常、访存和原子指令以驱动检查包链路。
    uint64_t start_cpu = test_read_cycles();
    hart_id = test_run_workload(hart_id);

    // 先通知检查窗口停止，再留出固定空操作使在途指令排空。
    ROCC_INSTRUCTION_S(1, 0x02, 0x70);
    for (int i = 0; i < TEST_PIPELINE_DRAIN_NOPS; i++) {
        asm volatile("nop");
    }
    // 0x32 停止向 GuardianCouncil 继续采集大核事件。
    ROCC_INSTRUCTION(1, 0x32);

    uint64_t instruction_count_end = ghe_csr_perf_read(0);

    // 等待硬件完成所有已发出的检查窗口；超时避免主核永久卡死。
    uint64_t status = 0;
    int ght_done = test_wait_for_ght_done(&status);
    if (!ght_done) {
        lock_acquire(&uart_lock);
        printf("[Boom-C%" PRIx64 "]: GHT completion timeout, status=0x%" PRIx64 "\r\n",
               hart_id, status);
        lock_release(&uart_lock);
    }

    // 主核发布本地 store 统计，并等待四个 checker 的完成钩子发布结果。
    uint64_t end_cpu = test_read_cycles();
    test_publish_storecount(hart_id);
    int storecounts_done = test_wait_for_storecounts();
    if (!storecounts_done) {
        lock_acquire(&uart_lock);
        printf("[Boom-C%" PRIx64 "]: storecount wait timeout\r\n", hart_id);
        lock_release(&uart_lock);
    }

    lock_acquire(&uart_lock);
    printf("CPU execution took %" PRIu64 " cycles\n", end_cpu - start_cpu);
    lock_release(&uart_lock);

    // 选择并读取 GHE 的执行时间与调度阻塞事件计数。
    ghe_perf_ctrl(0x07 << 1);
    uint64_t execution_time = ghe_perf_read();

    lock_acquire(&uart_lock);
    printf("Boom-Perf: Execution-time = %" PRIu64 " \r\n", execution_time);
    printf("Boom-Perf: Execution-inst = %" PRIu64 " \r\n",
           instruction_count_end - instruction_count_start);
    lock_release(&uart_lock);

    ghe_perf_ctrl(0x01 << 1);
    uint64_t scheduler_block_time = ghe_perf_read();

    lock_acquire(&uart_lock);
    printf("Boom-Perf: Sch-bloc-time = %" PRIu64 " \r\n", scheduler_block_time);
    test_print_storecount_report(storecounts_done);
    printf("[Boom-C%" PRIx64 "]: Test is now completed. \r\n", hart_id);
    lock_release(&uart_lock);

    // 取消上下文同步并复位监控状态，为下一次测试运行恢复初始状态。
    ght_unset_satp_priv();
    ROCC_INSTRUCTION(1, 0x30);
    return 0;
}

/**
 * @brief  hart 1~4 的统一启动入口。
 *
 * @details 启动代码在非主核上调用该符号。合法 checker 进入 checker()，
 *          其他 hart 以及 checker() 返回后的 hart 都进入永久空闲循环。
 * @return 实际不可达。
 */
int __main(void)
{
    uint64_t hart_id = 0;
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));

    if (test_is_checker_hart(hart_id)) {
        checker(hart_id);
    }

    idle();
    return 0;
}
