/* Isolated OpenSBI integration. The firmware supplies an address space and
 * launches the original hardware checker service; it never compares in software. */
#include <sbi/riscv_asm.h>
#include <sbi/riscv_barrier.h>
#include <sbi/sbi_ecall.h>
#include <sbi/sbi_error.h>
#include <sbi/sbi_hart.h>
#include <sbi/sbi_scratch.h>
#include <sbi/sbi_trap.h>

#define EC_OPT4_EXT 0x08004f50UL
/* Experimental SBI range: the vendor catch-all owns 0x09000000..0x09ffffff.
 * Overlap makes sbi_ecall_init fail before Linux can boot. */
_Static_assert(EC_OPT4_EXT < 0x09000000UL || EC_OPT4_EXT > 0x09ffffffUL,
               "checker extension overlaps the OpenSBI vendor registration");
struct ec_context {
    volatile unsigned long generation, satp, entry;
    volatile unsigned long launched[4], returned[4], fault[4];
    volatile unsigned long installed[4];
};
_Static_assert(__builtin_offsetof(struct ec_context, returned) == 56, "assembly ABI");
_Static_assert(__builtin_offsetof(struct ec_context, fault) == 88, "assembly ABI");
_Static_assert(__builtin_offsetof(struct ec_context, installed) == 120, "assembly ABI");
/* Cache-coherent firmware storage, reserved by OpenSBI's existing PMP region. */
struct ec_context ec_opt4_context __attribute__((aligned(64)));
extern void ec_opt4_enter(unsigned long satp, unsigned long entry) __attribute__((noreturn));
extern void ec_opt4_trap(void);

static int ec_handle(unsigned long ext, unsigned long fn, unsigned long *args,
                     unsigned long *value, struct sbi_trap_info *trap)
{
    unsigned long mask = 0, faults = 0;
    unsigned long generation = ec_opt4_context.generation;
    if (current_hartid() != 0) return SBI_ENOTSUPP;
    if (fn == 0) { *value = 0x00060004; return 0; }
    for (unsigned i = 0; i < 4; ++i) {
        if (ec_opt4_context.returned[i] == generation && generation) mask |= 1UL << i;
        if (ec_opt4_context.fault[i]) faults |= 1UL << i;
    }
    if (fn == 2) { *value = mask | (faults << 8); return 0; }
    if (fn == 3 && args[0] >= 1 && args[0] <= 4) {
        *value = ec_opt4_context.installed[args[0]-1]; return 0;
    }
    if (fn != 1) return SBI_ENOTSUPP;
    /* Version 6 deliberately permits one context per boot. No asynchronous
     * overwrite of a live checker context, and no unsafe firmware cancellation. */
    if (generation || !args[0] || (args[0] >> 60) != 8 || !args[1] ||
        args[1] >= (1UL << 38) || (args[1] & 4095)) return SBI_EINVAL;
    ec_opt4_context.satp = args[0];
    ec_opt4_context.entry = args[1];
    smp_wmb();
    ec_opt4_context.generation = 1;
    *value = 1;
    return 0;
}
struct sbi_ecall_extension ec_opt4_extension = {
    .extid_start = EC_OPT4_EXT, .extid_end = EC_OPT4_EXT, .handle = ec_handle,
};

void __attribute__((noreturn)) ec_opt4_secondary(struct sbi_scratch *scratch, unsigned long hart)
{
    if (hart < 1 || hart > 4 || sbi_hart_init(scratch, hart, FALSE)) sbi_hart_hang();
    csr_write(CSR_MIE, 0);
    csr_write(CSR_MEDELEG, 0);
    csr_write(CSR_MIDELEG, 0);
    csr_write(CSR_MTVEC, (unsigned long)ec_opt4_trap);
    csr_set(CSR_MSTATUS, MSTATUS_FS | MSTATUS_XS);
    while (!ec_opt4_context.generation) __asm__ volatile("nop");
    smp_rmb();
    ec_opt4_context.launched[hart-1] = ec_opt4_context.generation;
    smp_wmb();
    ec_opt4_enter(ec_opt4_context.satp, ec_opt4_context.entry);
}
