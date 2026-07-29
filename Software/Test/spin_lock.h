#ifndef SPIN_LOCK_H
#define SPIN_LOCK_H

extern int uart_lock;

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

static inline void lock_release(int *lock)
{
    __asm__(
        "amoswap.w.rl x0, x0, (%0);"
        :
        : "r"(lock));
}

#endif
