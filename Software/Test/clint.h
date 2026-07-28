/**
 * @file clint.h
 * @brief Per-hart CLINT interrupt setup and machine-mode trap handling.
 */

#ifndef TEST_CLINT_H
#define TEST_CLINT_H

#include <stdint.h>

#include "test_config.h"

/* Shared by all harts to serialize UART output. */
extern int uart_lock;

/* Number of timer interrupts handled by each timer-enabled hart. */
extern volatile uint32_t timer_flags[TEST_NUM_TIMER_HARTS];

uint64_t clint_read_mtime(void);
void clint_trigger_software_interrupt(void);
void clint_schedule_timer_interrupt(void);
void clint_enable_timer_interrupt(void);
void clint_enable_software_interrupt(void);

/**
 * HTIF trap ABI callback.  trap_entry passes mepc, mcause, mtval, and the
 * saved integer register frame, then writes this function's return value to
 * mepc.  Synchronous M-mode ecall is therefore resumed at epc + 4.
 */
uint64_t handle_trap(uint64_t epc, uint64_t cause, uint64_t tval,
                     uint64_t *registers);

#endif /* TEST_CLINT_H */
