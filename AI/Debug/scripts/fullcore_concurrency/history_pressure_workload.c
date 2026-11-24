/* P5-04/P5-11. Link with the existing Software/Test startup and Checker code.
 * This runs on the actual BOOM Main; no software rollback or golden stores
 * repair the result. The same binary is used by normal and Fault8 configs.
 */
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include "cfg/init.h"
#include "cfg/config.h"
#include "hw/ght.h"
#include "hw/ghe.h"
#include "hw/interrupt.h"
#include "hw/rocc.h"
#include "hw/spin_lock.h"
#if defined(PALIMPSEST_SV39_WORKLOAD)
#include "sv39_workload.h"
#endif

#if defined(PALIMPSEST_COMPACT_WORKLOAD)
enum { LINES = 64, ROUNDS = 16 };
#else
enum { LINES = 96, ROUNDS = 16 };
#endif
#if defined(PALIMPSEST_TRAP_IO_WORKLOAD)
extern volatile timer_flag_t palimpsest_ecall_counts[8];
static volatile uint64_t io_last;
#if defined(PALIMPSEST_MMIO_OUTPUT_WORKLOAD) || defined(PALIMPSEST_MMIO_AMO_WORKLOAD)
static volatile uint64_t *const timer_compare =
    (volatile uint64_t *)(CLINT_BASE + CLINT_MTIMECMP_OFFSET(0));
static const uint64_t timer_compare_base = UINT64_C(0x1234000000001000);
#endif
#endif
static volatile uint64_t (*const values)[8192] = (volatile uint64_t (*)[8192])UINT64_C(0x81000000);
extern volatile uint64_t tohost, fromhost;

void __attribute__((noreturn, noinline)) _exit(int code)
{
    __asm__ volatile("csrci mstatus, 8" ::: "memory");
    fromhost = 0;
    tohost = (((uint64_t)(unsigned)code << 1) | 1) & ((1ULL << 48) - 1);
    __asm__ volatile("fence rw,rw\n1: j 1b" ::: "memory");
    __builtin_unreachable();
}

int main(void)
{
    r_ini(NUM_CHECKERS);
    csr_software_cfg(); msip_cfg();
    while (ght_get_initialisation() == 0) {}
#if defined(PALIMPSEST_SV39_WORKLOAD)
    if (!setup_sv39()) _exit(3);
#endif
    ght_set_satp_priv();
    /* Initialize outside the protected interval. Checkers replay the original
     * control stream; they do not independently execute this initialization.
     */
    for (unsigned i=0; i<LINES; ++i)
        for (unsigned j=0; j<8; ++j) values[i][j] = (uint64_t)i*17+j;
#if defined(PALIMPSEST_MMIO_AMO_WORKLOAD)
    *timer_compare = timer_compare_base;
#endif
    const uint64_t fp_seed=0x3ff8000000000000ULL;
    __asm__ volatile("fmv.d.x f0, %0\ncsrw mscratch, zero" :: "r"(fp_seed) : "f0", "memory");
    ROCC_INSTRUCTION(1, 0x31);
    ROCC_INSTRUCTION_S(1, 0x01, 0x70);
#if defined(PALIMPSEST_SV39_WORKLOAD)
    unsigned sv39_checks=0;
#endif
    for (uint64_t round=0; round<ROUNDS; ++round) {
#if defined(PALIMPSEST_SV39_WORKLOAD)
        const unsigned which = (unsigned)round & 1;
        map_alias(which);
        if (read_alias() != sv39_values[which]) _exit(4);
        ++sv39_checks;
#endif
        for (unsigned i=0; i<LINES; ++i) {
#if defined(PALIMPSEST_TRAP_IO_WORKLOAD)
            if ((i & 7) == 0) __asm__ volatile("ecall" ::: "memory");
#endif
            values[i][0] += round+i+1;
            ((volatile uint8_t *)&values[i][1])[round&7] = (uint8_t)(round^i);
            uint64_t previous;
            __asm__ volatile("amoadd.d %0, %2, (%1)"
                             : "=r"(previous) : "r"(&values[i][2]), "r"(1ULL) : "memory");
            /* Keep integer/FP dependencies live across segment boundaries. */
            __asm__ volatile("fadd.d f1, f0, f0" ::: "f1");
#if defined(PALIMPSEST_COMPACT_WORKLOAD)
            /* Keep enough protected instructions to reach Fault8 and Seq16. */
            __asm__ volatile(".rept 128\naddi zero,zero,0\n.endr");
#endif
            if (previous != (uint64_t)i*17+2+round) _exit(2);
        }
#if defined(PALIMPSEST_TRAP_IO_WORKLOAD)
#if defined(PALIMPSEST_MMIO_AMO_WORKLOAD)
        uint64_t old_compare;
        __asm__ volatile("amoadd.d %0, %2, (%1)"
                         : "=r"(old_compare) : "r"(timer_compare), "r"(UINT64_C(1)) : "memory");
        if (old_compare != timer_compare_base + round) _exit(5);
        io_last = *timer_compare;
        if (io_last != timer_compare_base + round + 1) _exit(6);
#elif defined(PALIMPSEST_MMIO_OUTPUT_WORKLOAD)
        *timer_compare = timer_compare_base + round;
        io_last = *timer_compare;
        if (io_last != timer_compare_base + round) _exit(5);
#else
        io_last = get_mtime();
#endif
#endif
        __asm__ volatile("csrw mscratch, %0" :: "r"(round) : "memory");
    }
    ROCC_INSTRUCTION_S(1, 0x02, 0x70);
    for (unsigned n=0; n<26; ++n) __asm__ volatile("nop");
    ROCC_INSTRUCTION(1, 0x32);
    while (ght_get_status() < 0x1ffff) {}
    uint64_t fp, scratch;
    __asm__ volatile("fmv.x.d %0, f0\ncsrr %1, mscratch" : "=r"(fp), "=r"(scratch));
#if defined(PALIMPSEST_SV39_WORKLOAD)
    int ok=(fp==fp_seed && scratch==ROUNDS-1 && sv39_checks==ROUNDS);
#else
    int ok=(fp==fp_seed && scratch==ROUNDS-1);
#endif
#if defined(PALIMPSEST_TRAP_IO_WORKLOAD)
    ok &= palimpsest_ecall_counts[0].value == ROUNDS*((LINES+7)/8) && io_last != 0;
#endif
    uint64_t checksum=0, expected_checksum=0;
    for (unsigned i=0; i<LINES; ++i) {
        uint64_t expected[8];
        for (unsigned j=0; j<8; ++j) expected[j]=(uint64_t)i*17+j;
        expected[0] += (uint64_t)ROUNDS*(i+1)+(ROUNDS*(ROUNDS-1))/2;
        expected[2] += ROUNDS;
        for (unsigned round=0; round<ROUNDS; ++round) {
            unsigned shift=8*(round&7);
            expected[1]=(expected[1]&~(0xffULL<<shift))|((uint64_t)(uint8_t)(round^i)<<shift);
        }
        for (unsigned j=0; j<8; ++j) {
            uint64_t actual=values[i][j];
            ok &= actual==expected[j];
            checksum ^= actual+(uint64_t)(i*8+j)*0x9e3779b97f4a7c15ULL;
            expected_checksum ^= expected[j]+(uint64_t)(i*8+j)*0x9e3779b97f4a7c15ULL;
        }
    }
    ght_unset_satp_priv(); ROCC_INSTRUCTION(1, 0x30);
    lock_acquire(&uart_lock);
#if defined(PALIMPSEST_TRAP_IO_WORKLOAD)
    printf("PALIMPSEST_TRAP_IO_RESULT ecalls=%u expected=%u mmio_nonzero=%u\n",
           (unsigned)palimpsest_ecall_counts[0].value, ROUNDS*((LINES+7)/8), (unsigned)(io_last != 0));
#if defined(PALIMPSEST_MMIO_OUTPUT_WORKLOAD)
    printf("PALIMPSEST_MMIO_OUTPUT_RESULT checks=%u last=%016" PRIx64 "\n",
           ROUNDS, io_last);
#elif defined(PALIMPSEST_MMIO_AMO_WORKLOAD)
    printf("PALIMPSEST_MMIO_AMO_RESULT checks=%u last=%016" PRIx64 "\n",
           ROUNDS, io_last);
#endif
#endif
#if defined(PALIMPSEST_SV39_WORKLOAD)
    printf("PALIMPSEST_SV39_RESULT checks=%u expected=%u\n", sv39_checks, ROUNDS);
#endif
    printf("PALIMPSEST_WORKLOAD_RESULT ok=%u checksum=%016" PRIx64
           " expected=%016" PRIx64 " fp=%016" PRIx64 " csr=%016" PRIx64 "\n",
           (unsigned)ok,checksum,expected_checksum,fp,scratch);
    printf("PALIMPSEST_WORKLOAD_END status=%s\n",ok?"PASS":"FAIL");
    lock_release(&uart_lock);
    return ok?0:1;
}
