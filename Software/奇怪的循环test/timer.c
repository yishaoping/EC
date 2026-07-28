/**
 * @file    timer.c
 * @brief   可选的 hart 0 CLINT 单次定时器实现
 *
 * @details 实现与默认 clint.c 周期性 trap 路径分离的最小单次定时器：
 *          1. 设置 mtvec 指向中断处理函数
 *          2. 写入 mtimecmp = mtime + interval 设定触发时刻
 *          3. 使能 MTIE (机器定时器中断) 和 MIE (全局中断)
 *          4. 中断触发后只设置标志位，不重新装载比较值。
 *
 * @note   默认 GuardianCouncil 测试不调用本模块；它是附加实验接口。
 */

#include <stdint.h>
#include "timer.h"

/**
 * @brief  在 hart 0 上初始化单次机器定时器。
 * @param  interval  从当前 mtime 起算的 tick 间隔
 *
 * @note   单次触发：中断处理函数不会重新设置 mtimecmp，
 *         因此定时器只触发一次。
 */
void timer_init_single(uint64_t interval)
{
    // 直接接管 mtvec；不得与外部 trap_entry 路径同时使用。
    asm volatile("csrw mtvec, %0" : : "r" (timer_interrupt_handler));

    // MTIMECMP 宏固定映射 hart 0。
    MTIMECMP = MTIME + interval;

    // mie[7]=MTIE。
    asm volatile("csrs mie, %0" : : "r" (0x80));

    // mstatus[3]=MIE。
    asm volatile("csrs mstatus, 0x8");
}

/**
 * @brief  记录单次机器定时器中断已经发生。
 *
 * @note   使用 __attribute__((interrupt)) 属性，
 *         编译器会自动保存/恢复上下文并使用 mret 返回。
 *         本函数只设置触发标志，不更新 mtimecmp（单次触发）。
 */
void __attribute__((interrupt)) timer_interrupt_handler()
{
    uint32_t cause;
    asm volatile("csrr %0, mcause" : "=r" (cause));

    // 当前实现只检查低 31 位 cause=7；入口由 mtvec 专用于本定时器。
    if ((cause & 0x7FFFFFFF) == 7) {
        timer_triggered = 1;
        // 不重装 MTIMECMP，因此软件把该接口视为单次触发。
    }
}

/**
 * @brief  由轮询方确认单次中断已被消费。
 *
 * @note   在主循环中轮询 timer_triggered 标志，触发后调用本函数。
 */
void handle_single_trigger(void)
{
    timer_handled = 1;
}
