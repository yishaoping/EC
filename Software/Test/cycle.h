#ifndef CYCLE_H
#define CYCLE_H

#include <stdint.h>

static inline uint64_t read_cycles(void)
{
    uint64_t cycles;
    asm volatile("rdcycle %0" : "=r"(cycles));
    return cycles;
}

#endif
