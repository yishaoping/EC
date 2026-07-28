/**
 * @file    tasks.c
 * @brief   GuardianCouncil checker 核控制任务
 *
 * @details hart 1~4 执行 checker()，通过 GHE 自定义指令进入接收模式，
 *          等待大核检查点和事件包，驱动 Rocket checker 重放检查窗口，
 *          查询 ELU/RSU 错误状态，并在完成后释放硬件资源。
 *
 *          checker 并不直接调用 test_run_workload()。load/store、CSR、分支
 *          和寄存器状态由硬件检查包约束或比较。文件末尾的 malloc 任务
 *          是保留的独立辅助负载，默认 test.c 流程没有调用它。
 */

#include <stdio.h>
#include <stdlib.h>
#include "rocc.h"
#include "spin_lock.h"
#include "ght.h"
#include "ghe.h"
#include <inttypes.h>
#include "tasks.h"

// 弱钩子让 tasks.c 可独立复用；本测试由 test_runtime.c 提供强定义。
__attribute__((weak)) void checker_complete_hook(uint64_t hart_id)
{
    (void)hart_id;
}

__attribute__((weak)) void checker_initialised_hook(uint64_t hart_id)
{
    (void)hart_id;
}

/**
 * @brief  启动并监管一个 checker 核的硬件重放流程。
 * @param  hart_id  硬件线程 ID（核心编号 1~4）
 * @return 0。调用者 __main() 随后进入 idle()，因此该 hart 不再执行其他任务。
 *
 * @details 流程分为接收端初始化、上下文/PC 记录、两个 ELU 通道检查、
 *          RSU 恢复处理和完成清理。真正的逐指令重放发生在 checker Rocket
 *          流水线及 R_LSL/R_BJLR/R_RSUSL 等硬件模块中。
 */
int checker(int hart_id)
{
    // 接收端初始化：准备接收大核快照/事件，并向主核公布 checker 已就绪。
    ghe_asR();                          // 选择 R（Receiver/Reliability）模式
    ght_set_satp_priv();                // 使硬件接管检查所需的地址空间/特权上下文
    ghe_go();                           // 启动当前 checker 的 GHE 事件通道
    ghe_initailised(1);                 // 设置本 hart 的初始化完成标志
    checker_initialised_hook(hart_id);

    // 清零/启动 checker 侧性能计数器。
    ghe_perf_ctrl(0x01);
    ghe_perf_ctrl(0x00);


    // 建立检查窗口的上下文和 PC 记录控制状态。
    ROCC_INSTRUCTION(1, 0x75);          // doRecord：记录/准备上下文操作
    ROCC_INSTRUCTION(1, 0x73);          // doStoreFromMain：接收主核侧上下文
    ROCC_INSTRUCTION(1, 0x64);          // doRecordPC：记录 checker 当前 PC

    // 依次请求两个 ELU 观测通道完成检查并排空错误项。
    for (int sel_elu = 0; sel_elu < 2; sel_elu++) {
        ROCC_INSTRUCTION_S(1, sel_elu, 0x65);   // 选择并检查 ELU 通道

        // 非零表示 ELU 仍有错误/观测项；0x63 将所选通道出队后继续检查。
        while (elu_checkstatus() != 0) {
            printf("C%x: Error detected for ELU %x.\r\n", hart_id, sel_elu);
            ROCC_INSTRUCTION_S(1, sel_elu, 0x63);   // doDeqELU：错误项出队
        }
    }

    // 等待检查窗口完成；若 RSU 处于需处理状态，则触发上下文复制/恢复跳转。
    while (ghe_checkght_status() != 0x02) {
        // 掩码 0x18 后等于 0x08 表示当前 RSU 状态需要恢复处理。
        if ((ghe_rsur_status() & 0x18) == 0x08) {
            ROCC_INSTRUCTION(1, 0x60);              // doCopy：触发 ARF 上下文复制
            R_INSTRUCTION_JLR(3, 0x00);             // 自定义恢复跳转
        }
    }


    // 保存 checker 结束点上下文并要求硬件执行最终复制/比较。
    ROCC_INSTRUCTION(1, 0x72);          // doStoreFromChecker：保存 checker 上下文
    ROCC_INSTRUCTION(1, 0x60);          // doCopy：推进最终上下文操作

    // 固定 NOP 为自定义指令和流水线状态传播留出间隔。
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");

    // 强钩子读取该 checker 的 store 计数并向 hart 0 发布 ready。
    checker_complete_hook(hart_id);
    __asm__ volatile("nop");
    __asm__ volatile("nop");


    // 确认后处理未改变完成状态，再释放该 checker 的 GHE 资源。
    while (ghe_checkght_status() != 0x02) {
    }

    ghe_release();                      // 释放 GHE 资源
    ght_unset_satp_priv();              // 恢复 SATP 权限设置

    return 0;
}


/**
 * @brief  独立的堆分配与顺序访存辅助负载。
 * @param  base  填充数组的基值
 * @return 数组元素之和（用于验证内存操作正确性）
 *
 * @details 分配 32 个 int，写入 base+i 后求和并释放。它可用于额外制造
 *          堆访问，但不是硬件 malloc 正确性证明，也未被默认 test.c 调用。
 */
uint64_t task_synthetic_malloc(uint64_t base)
{
    int *ptr = NULL;
    int ptr_size = 32;
    int sum = 0;

    ptr = (int*)malloc(ptr_size * sizeof(int));

    // 裸机堆耗尽时打印错误并结束当前程序。
    if (ptr == NULL) {
        printf("Error! memory not allocated. \r\n");
        exit(0);
    }

    // 顺序写入后再顺序读取，形成简单、可预测的堆访存模式。
    for (int i = 0; i < ptr_size; i++) {
        *(ptr + i) = base + i;
    }

    for (int i = 0; i < ptr_size; i++) {
        sum = sum + *(ptr + i);
    }

    free(ptr);

    return sum;
}
