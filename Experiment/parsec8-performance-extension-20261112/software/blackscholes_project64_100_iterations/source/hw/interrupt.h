#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <stdint.h>

#include <riscv-pk/encoding.h>

#include "../cfg/config.h"

/* v1Config uses 64-byte coherence blocks. A checker timer interrupt must not
 * share a block with BOOM's package-tagged timer counter: its xRET can be a
 * prerequisite for publishing that package's validation result. Keep both
 * the first and last byte of every hart's control slot on private blocks.
 */
#define TIMER_CONTROL_BLOCK_BYTES 64
typedef struct __attribute__((aligned(TIMER_CONTROL_BLOCK_BYTES))) {
    int value;
    unsigned char padding[TIMER_CONTROL_BLOCK_BYTES - sizeof(int)];
} timer_flag_t;
_Static_assert(sizeof(timer_flag_t) == TIMER_CONTROL_BLOCK_BYTES,
               "timer control slots must occupy exactly one coherence block");
_Static_assert(_Alignof(timer_flag_t) == TIMER_CONTROL_BLOCK_BYTES,
               "timer control slots must start on a coherence block");

extern volatile timer_flag_t timer_flags[TIMER_HARTS];

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
