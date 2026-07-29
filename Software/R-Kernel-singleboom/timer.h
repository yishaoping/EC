#include <stdint.h>

#define CLINT_BASE 0x2000000
#define MTIME      (*(volatile uint64_t*)(CLINT_BASE + 0xBFF8))
#define MTIMECMP   (*(volatile uint64_t*)(CLINT_BASE + 0x4000))

// 中断处理函数原型
void __attribute__((interrupt)) timer_interrupt_handler(void);

// 中断标志（volatile保证可见性）
volatile int timer_triggered = 0;
volatile int timer_handled = 0;

// 单次定时器初始化（interval为触发间隔）
void timer_init_single(uint64_t interval);

// 单次中断处理逻辑（新增定义）
void handle_single_trigger();