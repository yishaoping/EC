/**
 * @file    clint.h
 * @brief   GuardianCouncil 测试使用的 CLINT 中断/异常接口
 *
 * @details 定义平台 CLINT 地址、机器态中断配置和统一 trap 回调。默认
 *          测试让 hart 0~4 分别触发自发软件中断，并在检查期间配置机器
 *          定时器，以验证 GuardianCouncil 面对 trap/CSR 状态变化时仍能
 *          正确完成上下文恢复和重放。
 *
 *          CLINT 寄存器布局：
 *          - MSIP:   软件中断寄存器（偏移 0x0000 + hart*4）
 *          - mtimecmp: 定时器比较寄存器（偏移 0x4000 + hart*8）
 *          - mtime:  全局 64 位时间计数器（偏移 0xBFF8）
 *
 *          测试实际使用的服务：
 *          - 软件中断 (MSIP):     msip_cfg() 触发, handle_trap() 清除
 *          - 定时器中断 (MTIP):   mtimecmp_cfg()+csr_timer_cfg() 配置
 *          - 异常处理:            handle_trap() 处理 ecall 等异常
 */

#ifndef CLINT_H
#define CLINT_H

#include <stdint.h>
#include <stdio.h>
#include "spin_lock.h"
#include <riscv-pk/encoding.h>

// ==================== CLINT 寄存器地址定义 ====================

#define CLINT_BASE       0x2000000                         // 平台 CLINT MMIO 基址
#define MSIP_OFFSET(h)   ((h) * 4)                         // hart h 的 32 位 MSIP 偏移
#define TIMECMP_OFFSET(h) (0x4000 + (h) * 8)               // hart h 的 64 位 mtimecmp 偏移
#define MTIME_ADDR       (CLINT_BASE + 0xBFF8)             // 全局 64 位 mtime 地址

// ==================== 定时器配置常量 ====================

#define NUM_TIMER_HARTS   5                                // 与测试拓扑一致：hart 0~4
#define timer_limitation  50                               // 每 hart 最多处理 50 次定时器中断
#define timer_cmp         0x10000                          // 相邻 mtimecmp 目标的 mtime tick 间隔

// ==================== 全局变量声明 ====================

extern volatile int timer_flags[NUM_TIMER_HARTS]; // 每 hart 已处理的周期定时器中断数
extern int uart_lock;                  // 保护多核 printf，定义于 clint.c


// ==================== 函数声明 ====================

uint64_t get_mtime(void);              // 以一致的高/低/高序列读取 mtime
void     msip_cfg(void);               // 向当前 hart 自身发送机器软件中断
void     mtimecmp_cfg(void);           // 设置当前 hart 的下一次定时器目标
void     csr_timer_cfg(void);          // 置位当前 hart 的 MTIE
void     csr_software_cfg(void);       // 置位当前 hart 的 MSIE 和全局 MIE
/** 处理软件/定时器中断及机器态 ecall，返回应写回 mepc 的地址。 */
uint64_t handle_trap(uint64_t epc, uint64_t cause, uint64_t tval, uint64_t *regs);

#endif // CLINT_H
