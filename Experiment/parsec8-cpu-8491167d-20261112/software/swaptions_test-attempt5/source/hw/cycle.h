#ifndef CYCLE_H
#define CYCLE_H

#include <stdint.h>

/* 读取当前 hart 的 RISC-V cycle CSR。 */
static inline uint64_t read_cycles(void)
{
    uint64_t cycles;
    asm volatile("rdcycle %0" : "=r"(cycles));
    return cycles;
}

#endif
