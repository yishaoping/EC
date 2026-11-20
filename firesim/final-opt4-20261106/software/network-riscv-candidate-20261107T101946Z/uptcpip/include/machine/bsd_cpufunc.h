/* Only user-stack primitives; privileged x86 operations are not stubbed. */
#ifndef _BSD_MACHINE_CPUFUNC_H_
#define _BSD_MACHINE_CPUFUNC_H_
static __inline void cpu_spinwait(void) { __asm__ __volatile__("nop" ::: "memory"); }
static __inline unsigned long long rdtsc(void) { unsigned long v; __asm__ __volatile__("rdcycle %0" : "=r"(v) :: "memory"); return v; }
#endif
