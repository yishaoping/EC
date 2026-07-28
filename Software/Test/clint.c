/**
 * @file clint.c
 * @brief CLINT MSIP/MTIP stimulus used while validating replay across traps.
 */

#include "clint.h"

#include <stddef.h>
#include <stdint.h>

#include <riscv-pk/encoding.h>

int uart_lock;
volatile uint32_t timer_flags[TEST_NUM_TIMER_HARTS] = {0};

#define MIP_MSIP_MASK       UINT64_C(0x08)
#define MIP_MTIP_MASK       UINT64_C(0x80)
#define MIE_MSIE_MASK       UINT64_C(0x08)
#define MIE_MTIE_MASK       UINT64_C(0x80)
#define MSTATUS_MIE_MASK    UINT64_C(0x08)
#define MCAUSE_INTERRUPT    (UINT64_C(1) << 63)
#define MCAUSE_CODE_MASK    (~MCAUSE_INTERRUPT)
#define MCAUSE_ECALL_M      UINT64_C(11)

static uint64_t read_hart_id(void)
{
    uint64_t hart_id;
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));
    return hart_id;
}

static volatile uint32_t *clint_msip(uint64_t hart_id)
{
    return (volatile uint32_t *)(uintptr_t)(
        TEST_CLINT_BASE + TEST_CLINT_MSIP_OFFSET(hart_id));
}

static volatile uint32_t *clint_mtimecmp_low(uint64_t hart_id)
{
    return (volatile uint32_t *)(uintptr_t)(
        TEST_CLINT_BASE + TEST_CLINT_MTIMECMP_OFFSET(hart_id));
}

uint64_t clint_read_mtime(void)
{
    volatile uint32_t *low = (volatile uint32_t *)(uintptr_t)(
        TEST_CLINT_BASE + TEST_CLINT_MTIME_OFFSET);
    volatile uint32_t *high = low + 1;
    uint32_t high_before;
    uint32_t high_after;
    uint32_t low_value;

    /* Re-read if the low word wrapped between the two high-word reads. */
    do {
        high_before = *high;
        low_value = *low;
        high_after = *high;
    } while (high_before != high_after);

    return ((uint64_t)high_before << 32) | low_value;
}

static void write_mtimecmp(uint64_t hart_id, uint64_t compare_value)
{
    volatile uint32_t *low = clint_mtimecmp_low(hart_id);
    volatile uint32_t *high = low + 1;

    /*
     * RV32-compatible three-write sequence.  Moving the high word to the
     * maximum first prevents a torn compare value from raising a spurious
     * timer interrupt while the low word is updated.
     */
    *high = UINT32_MAX;
    *low = (uint32_t)compare_value;
    *high = (uint32_t)(compare_value >> 32);
    asm volatile("fence iorw, iorw" ::: "memory");
}

static void set_mtie(int enabled)
{
    uint64_t mie_value = read_csr(mie);
    if (enabled) {
        write_csr(mie, mie_value | MIE_MTIE_MASK);
    } else {
        write_csr(mie, mie_value & ~MIE_MTIE_MASK);
    }
}

void clint_trigger_software_interrupt(void)
{
    *clint_msip(read_hart_id()) = 1U;
    asm volatile("fence iorw, iorw" ::: "memory");
}

void clint_schedule_timer_interrupt(void)
{
    uint64_t hart_id = read_hart_id();
    write_mtimecmp(hart_id, clint_read_mtime() + TEST_TIMER_INTERVAL_TICKS);
}

void clint_enable_timer_interrupt(void)
{
    set_mtie(1);
}

void clint_enable_software_interrupt(void)
{
    write_csr(mie, read_csr(mie) | MIE_MSIE_MASK);
    write_csr(mstatus, read_csr(mstatus) | MSTATUS_MIE_MASK);
}

static void handle_timer_interrupt(uint64_t hart_id)
{
    if (hart_id >= TEST_NUM_TIMER_HARTS) {
        set_mtie(0);
        return;
    }

    timer_flags[hart_id]++;
    if (timer_flags[hart_id] < TEST_TIMER_INTERRUPT_LIMIT) {
        write_mtimecmp(hart_id,
                       clint_read_mtime() + TEST_TIMER_INTERVAL_TICKS);
        return;
    }

    /* Match the original test: stop MTIP and close the global M-mode gate. */
    set_mtie(0);
    write_csr(mstatus, read_csr(mstatus) & ~MSTATUS_MIE_MASK);
}

uint64_t handle_trap(uint64_t epc, uint64_t cause, uint64_t tval,
                     uint64_t *registers)
{
    (void)tval;
    (void)registers;

    uint64_t hart_id = read_hart_id();
    if ((cause & MCAUSE_INTERRUPT) != 0U) {
        uint64_t pending = read_csr(mip);
        if ((pending & MIP_MSIP_MASK) != 0U) {
            *clint_msip(hart_id) = 0U;
            asm volatile("fence iorw, iorw" ::: "memory");
        } else if ((pending & MIP_MTIP_MASK) != 0U) {
            handle_timer_interrupt(hart_id);
        }
        return epc;
    }

    if ((cause & MCAUSE_CODE_MASK) == MCAUSE_ECALL_M) {
        return epc + 4U;
    }

    /* Unknown exceptions retain the original behavior and retry the epc. */
    return epc;
}
