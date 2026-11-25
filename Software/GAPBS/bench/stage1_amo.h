#ifndef STAGE1_AMO_H
#define STAGE1_AMO_H

#include <stdint.h>

/* Both words share one aligned XLEN word in ordinary cacheable DRAM.
 * Distinct signed old values expose wrong-lane selection and RV64 extension.
 * These instructions run unconditionally inside the measured/checking window.
 */
static volatile uint32_t stage1_amo_words[2] __attribute__((aligned(64)));

static __attribute__((noinline)) int stage1_amo_w_test(void)
{
    uint64_t low_old, high_old, low_new, high_new;
    uint64_t swap = 0x76543210U;
    uint64_t add = 7;
    stage1_amo_words[0] = 0x80000001U;
    stage1_amo_words[1] = 0xfffffffcU;
    __asm__ volatile("fence rw,rw" ::: "memory");
    __asm__ volatile("amoswap.w.aqrl %0,%2,(%1)"
                     : "=r"(low_old)
                     : "r"(&stage1_amo_words[0]), "r"(swap) : "memory");
    __asm__ volatile("amoadd.w.aqrl %0,%2,(%1)"
                     : "=r"(high_old)
                     : "r"(&stage1_amo_words[1]), "r"(add) : "memory");
    /* Read returned values again with opposite signs, on both lanes. */
    __asm__ volatile("amoadd.w.aqrl %0,%2,(%1)"
                     : "=r"(low_new)
                     : "r"(&stage1_amo_words[0]), "r"(add) : "memory");
    __asm__ volatile("amoswap.w.aqrl %0,%2,(%1)"
                     : "=r"(high_new)
                     : "r"(&stage1_amo_words[1]), "r"(swap) : "memory");
    return low_old == UINT64_C(0xffffffff80000001) &&
           high_old == UINT64_C(0xfffffffffffffffc) &&
           low_new == UINT64_C(0x76543210) && high_new == 3 &&
           stage1_amo_words[0] == 0x76543217U &&
           stage1_amo_words[1] == 0x76543210U;
}
#endif
