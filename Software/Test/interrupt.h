#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <stdint.h>

#include <riscv-pk/encoding.h>

#include "test_config.h"

extern volatile int timer_flags[TIMER_HARTS];

uint64_t get_mtime(void);
void mtimecmp_cfg(void);
void handle_trap(void);

static inline void msip_cfg(void)
{
    uint64_t hart_id;
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));

    volatile uint32_t *msip =
        (uint32_t *)(CLINT_BASE + CLINT_MSIP_OFFSET(hart_id));
    *msip = 0x1;
}

static inline void csr_timer_cfg(void)
{
    uint64_t hart_id;
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));
    unsigned int csr_tmp = read_csr(mie);
    write_csr(mie, csr_tmp | 0x80);
}

static inline void csr_software_cfg(void)
{
    uint64_t hart_id;
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));
    unsigned int csr_tmp = read_csr(mie);
    write_csr(mie, csr_tmp | 0x8);
    csr_tmp = read_csr(mstatus);
    write_csr(mstatus, csr_tmp | 0x8);
}

#endif
