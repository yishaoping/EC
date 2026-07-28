/**
 * @file    spin_lock.h
 * @brief   多核 UART 输出使用的 RISC-V 原子自旋锁
 *
 * @details 使用 RISC-V "A" (Atomic) 扩展指令实现简单的自旋锁：
 *          - lock_acquire():  使用 amoswap.w.aq 获取锁（带 acquire 语义）
 *          - lock_release():  使用 amoswap.w.rl 释放锁（带 release 语义）
 *
 *          默认测试用该锁串行化 hart 0~4 的 printf，避免串口行交错。
 *          内存序保证：
 *          - .aq (acquire)：获取锁之后的所有内存操作不会被重排到获取之前
 *          - .rl (release)：释放锁之前的所有内存操作不会被重排到释放之后
 */

#ifndef SPIN_LOCK_H
#define SPIN_LOCK_H

#include <stdint.h>

/**
 * @brief  获取自旋锁（阻塞等待直到成功）
 * @param  lock  指向锁变量的指针（0=未锁定，非0=已锁定）
 *
 * @note   使用 amoswap.w.aq 原子交换指令。该锁无公平性、超时或 WFI，
 *         因而只适合短临界区；持锁代码不得等待其他 hart 获取同一锁。
 *         将锁位置为 1（锁定），返回旧值。
 *         如果旧值非 0（已被锁定），则循环重试（自旋）。
 */
static inline void lock_acquire(int *lock)
{
    int temp0 = 1;

    __asm__(
        "loop%=: "                          // %= 为每次宏展开生成唯一标签
        "amoswap.w.aq %1, %1, (%0);"       // 写 1 并读取旧锁值
        "bnez %1,loop%="                    // 旧值非零则继续忙等
        :
        : "r" (lock), "r" (temp0)
        :
    );
}

/**
 * @brief  释放自旋锁
 * @param  lock  指向锁变量的指针
 *
 * @note   使用 amoswap.w.rl 原子交换指令：
 *         将锁位置为 0（解锁），旧值丢弃（x0）。
 *         .rl 语义保证释放前的所有存储操作对其他核可见。
 */
static inline void lock_release(int *lock)
{
    __asm__(
        "amoswap.w.rl x0, x0, (%0);"       // 写 0，旧值丢弃到 x0
        :
        : "r" (lock)
        :
    );
}

#endif // SPIN_LOCK_H
