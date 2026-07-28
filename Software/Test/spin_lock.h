/**
 * @file spin_lock.h
 * @brief Minimal RV64A spin lock used to serialize multi-hart UART output.
 */

#ifndef TEST_SPIN_LOCK_H
#define TEST_SPIN_LOCK_H

static inline void lock_acquire(int *lock)
{
    int previous = 1;

    asm volatile(
        "1:\n\t"
        "amoswap.w.aq %0, %0, (%1)\n\t"
        "bnez %0, 1b"
        : "+r"(previous)
        : "r"(lock)
        : "memory");
}

static inline void lock_release(int *lock)
{
    asm volatile("amoswap.w.rl zero, zero, (%0)"
                 :
                 : "r"(lock)
                 : "memory");
}

#endif /* TEST_SPIN_LOCK_H */
