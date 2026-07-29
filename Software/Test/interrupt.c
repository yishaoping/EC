#include "interrupt.h"

#include <riscv-pk/encoding.h>

volatile int timer_flags[TIMER_HARTS] = {0};

uint64_t get_mtime(void)
{
    volatile uint32_t *mtime_low = (uint32_t *)CLINT_MTIME_ADDRESS;
    volatile uint32_t *mtime_high = (uint32_t *)(CLINT_MTIME_ADDRESS + 4);
    uint32_t hi;
    uint32_t lo;

    do {
        hi = *mtime_high;
        lo = *mtime_low;
    } while (hi != *mtime_high);

    return ((uint64_t)hi << 32) | lo;
}

void mtimecmp_cfg(void)
{
    uint64_t hart_id;
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));

    volatile uint32_t *mtimecmp_low =
        (uint32_t *)(CLINT_BASE + CLINT_MTIMECMP_OFFSET(hart_id));
    volatile uint32_t *mtimecmp_high =
        (uint32_t *)(CLINT_BASE + CLINT_MTIMECMP_OFFSET(hart_id) + 4);
    uint64_t current = get_mtime();
    uint64_t cmp_val = current + TIMER_COMPARE_DELTA;

    *mtimecmp_low = (uint32_t)cmp_val;
    *mtimecmp_high = (uint32_t)(cmp_val >> 32);
}

void handle_trap(void)
{
    uint64_t hart_id;
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));

    uint64_t mcause_val = read_csr(mcause);
    uint64_t interrupt = mcause_val >> 63;
    uint64_t cause_code = mcause_val & UINT64_C(0x7FFFFFFFFFFFFFFF);

    if (interrupt) {
        if ((read_csr(mip) & 0x8) != 0) {
            volatile uint32_t *msip =
                (uint32_t *)(CLINT_BASE + CLINT_MSIP_OFFSET(hart_id));
            *msip = 0x0;
        } else if ((read_csr(mip) & 0x80) != 0) {
            unsigned long long current_time = get_mtime();
            if (hart_id == 0) {
                timer_flags[0] += 1;
                if (timer_flags[0] < TIMER_LIMIT) {
                    volatile uint32_t *mtimecmp =
                        (uint32_t *)(CLINT_BASE +
                                     CLINT_MTIMECMP_OFFSET(hart_id));
                    uint64_t new_cmp = get_mtime() + TIMER_COMPARE_DELTA;
                    *(uint64_t *)mtimecmp = new_cmp;
                } else if (timer_flags[0] >= TIMER_LIMIT) {
                    unsigned int mie_val = read_csr(mie);
                    write_csr(mie, mie_val & ~0x80);
                    unsigned int mstatus_val = read_csr(mstatus);
                    write_csr(mstatus, mstatus_val & ~0x8);
                }
            } else if (hart_id == 1) {
                timer_flags[1] += 1;
                if (timer_flags[1] < TIMER_LIMIT) {
                    volatile uint32_t *mtimecmp =
                        (uint32_t *)(CLINT_BASE +
                                     CLINT_MTIMECMP_OFFSET(hart_id));
                    uint64_t new_cmp = get_mtime() + TIMER_COMPARE_DELTA;
                    *(uint64_t *)mtimecmp = new_cmp;
                } else if (timer_flags[1] >= TIMER_LIMIT) {
                    unsigned int mie_val = read_csr(mie);
                    write_csr(mie, mie_val & ~0x80);
                    unsigned int mstatus_val = read_csr(mstatus);
                    write_csr(mstatus, mstatus_val & ~0x8);
                }
            } else if (hart_id == 2) {
                timer_flags[2] += 1;
                if (timer_flags[2] < TIMER_LIMIT) {
                    volatile uint32_t *mtimecmp =
                        (uint32_t *)(CLINT_BASE +
                                     CLINT_MTIMECMP_OFFSET(hart_id));
                    uint64_t new_cmp = get_mtime() + TIMER_COMPARE_DELTA;
                    *(uint64_t *)mtimecmp = new_cmp;
                } else if (timer_flags[2] >= TIMER_LIMIT) {
                    unsigned int mie_val = read_csr(mie);
                    write_csr(mie, mie_val & ~0x80);
                    unsigned int mstatus_val = read_csr(mstatus);
                    write_csr(mstatus, mstatus_val & ~0x8);
                }
            } else if (hart_id == 3) {
                timer_flags[3] += 1;
                if (timer_flags[3] < TIMER_LIMIT) {
                    volatile uint32_t *mtimecmp =
                        (uint32_t *)(CLINT_BASE +
                                     CLINT_MTIMECMP_OFFSET(hart_id));
                    uint64_t new_cmp = get_mtime() + TIMER_COMPARE_DELTA;
                    *(uint64_t *)mtimecmp = new_cmp;
                } else if (timer_flags[3] >= TIMER_LIMIT) {
                    unsigned int mie_val = read_csr(mie);
                    write_csr(mie, mie_val & ~0x80);
                    unsigned int mstatus_val = read_csr(mstatus);
                    write_csr(mstatus, mstatus_val & ~0x8);
                }
            }
            (void)current_time;
        }
    } else {
        switch (cause_code) {
        case 11:
            write_csr(mepc, read_csr(mepc) + 4);
            __asm__ volatile("csrr a0, mepc");
            break;
        default:
            break;
        }
    }

    __asm__ volatile("csrr a0, mepc");
}
