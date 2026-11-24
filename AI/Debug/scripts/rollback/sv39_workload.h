#ifndef PALIMPSEST_SV39_WORKLOAD_H
#define PALIMPSEST_SV39_WORKLOAD_H

/* M-mode test code stays at physical addresses. MPRV applies S translation
 * only to the single data load, so an unexpected fault leaves a clear PC. */
static volatile uint64_t root_pt[512] __attribute__((aligned(4096)));
static volatile uint64_t middle_pt[512] __attribute__((aligned(4096)));
static volatile uint64_t leaf_pt[512] __attribute__((aligned(4096)));
static volatile uint64_t data_pages[2][512] __attribute__((aligned(4096)));
static const uint64_t sv39_values[2] = {0x3742579900000021ULL, 0x69d1e20500000043ULL};
static uint64_t pte(const volatile uint64_t *page, uint64_t flags)
{
    return ((uintptr_t)page >> 12 << 10) | flags;
}
static void map_alias(unsigned which)
{
    leaf_pt[1] = pte(data_pages[which], 0xc3); // V/R/A/D, supervisor page
    __asm__ volatile("sfence.vma zero, zero" ::: "memory");
}
static uint64_t read_alias(void)
{
    uint64_t original, result;
    const uintptr_t alias = 0x40001000;
    __asm__ volatile("csrr %0, mstatus" : "=r"(original));
    const uint64_t translated = (original & ~((3ULL << 11) | 8ULL)) | (1ULL << 11) | (1ULL << 17);
    __asm__ volatile("csrw mstatus, %2\nld %0, 0(%1)\ncsrw mstatus, %3"
                     : "=&r"(result) : "r"(alias), "r"(translated), "r"(original) : "memory");
    return result;
}
static int setup_sv39(void)
{
    uint64_t actual;
    const uint64_t satp = (8ULL << 60) | ((uintptr_t)root_pt >> 12);
    // This bare-metal test owns hart 0. Give S-mode access to its test pages.
    __asm__ volatile("csrw pmpaddr0, %0\ncsrw pmpcfg0, %1" :: "r"(~0ULL), "r"(0x1fULL) : "memory");
    root_pt[1] = pte(middle_pt, 1);
    middle_pt[0] = pte(leaf_pt, 1);
    data_pages[0][0] = sv39_values[0];
    data_pages[1][0] = sv39_values[1];
    __asm__ volatile("csrw satp, %1\ncsrr %0, satp" : "=r"(actual) : "r"(satp) : "memory");
    map_alias(0);
    return actual == satp && read_alias() == sv39_values[0];
}

#endif
