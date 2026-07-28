/**
 * @file    timer.h
 * @brief   可选的 hart 0 CLINT 单次定时器接口
 *
 * @details 这是与 clint.c 周期定时器路径相互独立的辅助实现：它直接把
 *          mtvec 指向 GCC interrupt 函数，只操作 hart 0 的 mtimecmp，并以
 *          标志位通知调用者。默认 test.c 不调用 timer_init_single()，但
 *          compile.sh 为兼容独立实验仍编译 timer.c。
 */

#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>
#include "clint.h"

// 该辅助接口只映射 hart 0 的 64 位比较寄存器。
#define MTIME       (*(volatile uint64_t*)(MTIME_ADDR))
#define MTIMECMP    (*(volatile uint64_t*)(CLINT_BASE + 0x4000))

/** GCC 生成 mret 序列的机器定时器中断处理函数。 */
void __attribute__((interrupt)) timer_interrupt_handler(void);

// 变量定义保留在头文件中是历史接口；链接脚本允许重复定义。
volatile int timer_triggered = 0;   // 中断处理函数已观察到 cause=7
volatile int timer_handled   = 0;   // 软件已执行后处理

/** 在 hart 0 上安排 interval 个 mtime tick 后的单次中断。 */
void timer_init_single(uint64_t interval);
/** 把单次中断标记为已由软件处理。 */
void handle_single_trigger(void);

#endif // TIMER_H
