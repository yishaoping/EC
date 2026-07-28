/**
 * @file    tasks.h
 * @brief   Checker 核控制任务及生命周期钩子接口
 *
 * @details checker() 驱动硬件重放检查。两个 hook 在 tasks.c 中有弱默认
 *          实现，test_runtime.c 用强实现接入中断配置和跨核统计发布。
 *          task_synthetic_malloc() 是默认测试路径之外的辅助负载。
 */

#include <stdint.h>
#include <stdio.h>

// uart_lock 定义于 clint.c；shadow 是兼容旧测试代码保留的外部声明。
extern int uart_lock;
extern char* shadow;

/** 启动指定 hart 的 checker 接收、重放、错误查询与释放流程。 */
int checker(int hart_id);
/** 可选的堆分配/顺序访存辅助负载。 */
uint64_t task_synthetic_malloc(uint64_t base);
/** checker 宣告 GHE 初始化完成后调用。 */
void checker_initialised_hook(uint64_t hart_id);
/** checker 完成最终检查后、释放 GHE 前调用。 */
void checker_complete_hook(uint64_t hart_id);
