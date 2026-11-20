#ifndef SPIN_LOCK_H
#define SPIN_LOCK_H

extern int uart_lock;

/* 使用 AMOSWAP 获取自旋锁。 */
static inline void lock_acquire(int *lock)
{
    int temp0 = 1;

    __asm__(
        "loop%=: "
        "amoswap.w.aq %1, %1, (%0);"
        "bnez %1,loop%="
        :
        : "r"(lock), "r"(temp0));
}

/* 使用 release 语义释放自旋锁。 */
static inline void lock_release(int *lock)
{
    __asm__(
        "amoswap.w.rl x0, x0, (%0);"
        :
        : "r"(lock));
}

#endif
