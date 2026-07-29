#include <stdint.h>
#include "timer.h"

// 单次定时器初始化（interval为触发间隔）
void timer_init_single(uint64_t interval) {
    // 1. 设置中断处理程序
    asm volatile("csrw mtvec, %0" : : "r" (timer_interrupt_handler));
    
    // 2. 配置定时器比较值（仅设置一次）
    MTIMECMP = MTIME + interval;
    
    // 3. 使能机器模式定时器中断
    asm volatile("csrs mie, %0" : : "r" (0x80));  // MIE[7] = MTIE
    
    // 4. 全局中断使能
    asm volatile("csrs mstatus, 0x8");            // mstatus.MIE
}

// 中断处理函数（不再更新MTIMECMP）
void __attribute__((interrupt)) timer_interrupt_handler() {
    uint32_t cause;
    asm volatile("csrr %0, mcause" : "=r" (cause));

    // 验证是否为定时器中断（mcause[6:0] = 7）
    if ((cause & 0x7FFFFFFF) == 7) {
        timer_triggered = 1;  // 设置触发标志
        
        // 关键点：不修改MTIMECMP，实现单次触发
        // 中断标志会自动清除（通过CLINT机制）
    }
}

// 单次中断处理逻辑（新增定义）
void handle_single_trigger() {
    timer_handled = 1;  // 设置GPIO输出
}