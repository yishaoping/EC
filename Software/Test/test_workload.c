/**
 * @file test_workload.c
 * @brief Instruction stimulus for the GuardianCouncil end-to-end test.
 *
 * The workload is intentionally heterogeneous rather than algorithmic.  Its
 * purpose is to make BOOM commit FP/CSR/memory/atomic events that GH_BUF sends
 * to Rocket checkers.  The physical address range in test_config.h must be
 * reserved and accessible on the target platform.
 */

#include "test_workload.h"

#include <stdint.h>

#include "test_config.h"

#define STRINGIFY_IMPL(value) #value
#define STRINGIFY(value) STRINGIFY_IMPL(value)

static void run_store_and_fp_csr_stimulus(void)
{
    asm volatile(
        "li      t0, " STRINGIFY(TEST_WORKLOAD_MEMORY_BASE) "\n\t"
        "li      t1, " STRINGIFY(TEST_WORKLOAD_STORE_DATA_A) "\n\t"
        "li      t2, " STRINGIFY(TEST_WORKLOAD_STORE_DATA_B) "\n\t"
        "li      a5, " STRINGIFY(TEST_WORKLOAD_MEMORY_LIMIT) "\n\t"
        "1:\n\t"
        "lr.w    a0, (t0)\n\t"
        "sc.w    a0, t1, (t0)\n\t"
        "sd      t1, 0(t0)\n\t"
        "sd      t2, 16(t0)\n\t"
        "sd      t1, 32(t0)\n\t"
        "sd      t2, 64(t0)\n\t"
        "divw    t3, t1, t2\n\t"
        "addi    t0, t0, 0x10\n\t"
        "frflags a3\n\t"
        "fsflags a3\n\t"
        "csrrc   a3, fflags, a3\n\t"
        "csrrwi  a3, frm, 0x3\n\t"
        "csrrsi  a3, fflags, 0x1f\n\t"
        "csrrci  a3, fflags, 0x0f\n\t"
        "blt     t0, a5, 1b\n\t"
        :
        :
        : "a0", "a3", "a5", "t0", "t1", "t2", "t3", "memory");
}

static void run_load_and_integer_stimulus(void)
{
    asm volatile(
        "li      t0, " STRINGIFY(TEST_WORKLOAD_MEMORY_BASE) "\n\t"
        "li      t1, " STRINGIFY(TEST_WORKLOAD_STORE_DATA_A) "\n\t"
        "li      a5, " STRINGIFY(TEST_WORKLOAD_MEMORY_LIMIT) "\n\t"
        "1:\n\t"
        "lr.w    a0, (t0)\n\t"
        "sc.w    a0, t1, (t0)\n\t"
        "ld      t1, 0(t0)\n\t"
        "ld      t2, 16(t0)\n\t"
        "ld      t1, 32(t0)\n\t"
        "ld      t2, 64(t0)\n\t"
        "mulw    t3, t1, t2\n\t"
        "divw    t3, t1, t2\n\t"
        "frflags a3\n\t"
        "li      a3, 0x55\n\t"
        "fsflags a3\n\t"
        "divu    t2, t2, t1\n\t"
        "addi    t0, t0, 0x10\n\t"
        "blt     t0, a5, 1b\n\t"
        :
        :
        : "a0", "a3", "a5", "t0", "t1", "t2", "t3", "memory");
}

static void run_atomic_stimulus(void)
{
    asm volatile(
        "li          t0, " STRINGIFY(TEST_WORKLOAD_MEMORY_BASE) "\n\t"
        "li          t1, " STRINGIFY(TEST_WORKLOAD_ATOMIC_INITIAL) "\n\t"
        "li          t2, 1\n\t"
        "li          a5, " STRINGIFY(TEST_WORKLOAD_MEMORY_LIMIT) "\n\t"
        "1:\n\t"
        "amoadd.w.aq t1, t2, (t0)\n\t"
        "addi        t2, t2, 1\n\t"
        "addi        t0, t0, 0x10\n\t"
        "blt         t0, a5, 1b\n\t"
        :
        :
        : "a5", "t0", "t1", "t2", "memory");
}

uint64_t test_run_workload(uint64_t hart_id)
{
    float a = 0.1f;
    float b = 0.2f;
    float c = 0.3f;
    float d = (a + b + c) * 1.7f * 3.2f;
    uint64_t csr_value;

    asm volatile("csrr %0, cycle" : "=r"(csr_value));
    asm volatile("csrr %0, instret" : "=r"(csr_value));
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));

    double e = (c - b + a) * 1.1;
    double f = ((e + d) * (d - b)) / 2.1;
    double g = (c + 1.1) / 2.0;
    double h = a - 0.05;
    double i = f + 1.1;
    double sum = a + b + c + d + e + f + g + h + i;

    /* Only the BOOM producer may touch the fixed workload address range. */
    if ((sum * hart_id) != 0.0) {
        return hart_id;
    }

    for (uint32_t iteration = 0; iteration < TEST_WORKLOAD_ITERATIONS;
         ++iteration) {
        e = iteration * 1.2 + 3.0;
        b = (float)(sum + 1.7);
        a = (float)((e + b) * 2.2);
        asm volatile("csrr %0, cycle" : "=r"(csr_value));
        asm volatile("csrr %0, instret" : "=r"(csr_value));
        asm volatile("csrr %0, mhartid" : "=r"(hart_id));
        a += (float)csr_value;

        /* HTIF trap_entry calls handle_trap(), which advances mepc by four. */
        asm volatile("ecall");

        if (a > (float)hart_id) {
            run_store_and_fp_csr_stimulus();
            run_load_and_integer_stimulus();
            run_atomic_stimulus();
        }
    }

    return hart_id;
}

#undef STRINGIFY
#undef STRINGIFY_IMPL
