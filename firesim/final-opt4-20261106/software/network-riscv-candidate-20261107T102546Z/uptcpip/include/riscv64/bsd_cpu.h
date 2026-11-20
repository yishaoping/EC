#ifndef _BSD_MACHINE_CPU_H_
#define _BSD_MACHINE_CPU_H_
#include <machine/bsd_cpufunc.h>
static __inline unsigned long long get_cyclecount(void) { return rdtsc(); }
#endif
