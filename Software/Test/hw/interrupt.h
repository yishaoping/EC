#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <stdint.h>

#include <riscv-pk/encoding.h>

#include "../cfg/config.h"

extern volatile int timer_flags[TIMER_HARTS];

/* 读取 CLINT 的 mtime 计数器。 */
uint64_t get_mtime(void);

/* 为当前 hart 设置下一次定时器比较值。 */
void mtimecmp_cfg(void);

/* 处理软件中断、定时器中断和 ecall。 */
void handle_trap(void);

/* 打开当前 hart 的软件中断。 */
static inline void msip_cfg(void)
{
    uint64_t hart_id;
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));

    volatile uint32_t *msip =
        (uint32_t *)(CLINT_BASE + CLINT_MSIP_OFFSET(hart_id));
    *msip = 0x1;
}

/* 打开当前 hart 的定时器中断。 */
static inline void csr_timer_cfg(void)
{
    uint64_t hart_id;
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));
    unsigned int csr_tmp = read_csr(mie);
    write_csr(mie, csr_tmp | 0x80);
}

/* 打开当前 hart 的软件中断和全局中断。 */
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
