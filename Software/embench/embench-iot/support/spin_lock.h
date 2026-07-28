#ifndef MEEK_SPIN_LOCK_H
#define MEEK_SPIN_LOCK_H

#include <stdint.h>

static inline void lock_acquire(int *lock)
{
	int previous;
	int one = 1;
	do {
		__asm__ volatile(
			"amoswap.w.aq %0, %2, (%1)"
			: "=r" (previous)
			: "r" (lock), "r" (one)
			: "memory");
	} while (previous != 0);
}

static inline void lock_release(int *lock)
{
	__asm__ volatile(
		"amoswap.w.rl x0, x0, (%0)"
		:
		: "r" (lock)
		: "memory");
}

#endif
