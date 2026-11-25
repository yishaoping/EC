#include <inttypes.h>
#include <stdio.h>

#include "cfg/init.h"
#include "hw/ghe.h"
#include "hw/ght.h"
#include "hw/interrupt.h"

enum { LINES = 96, ROUNDS = 4 };
/* A 64 KiB stride selects the same L2 set in v1Config. */
static volatile uint64_t (*const lines)[8192] = (void *)UINT64_C(0x81000000);
static volatile uint32_t *const msip = (void *)CLINT_BASE;
static volatile uint64_t *const mtimecmp = (void *)(CLINT_BASE + CLINT_MTIMECMP_OFFSET(0));
static const uint64_t timer_base = UINT64_C(0x1234000000001000);
static const uint64_t fp_seed = UINT64_C(0x3ff8000000000000); /* 1.5 */
static const double fp_increment = 0.5;

extern volatile uint64_t tohost, fromhost;

_Noreturn void _exit(int code)
{
    asm volatile("csrci mstatus, 8" ::: "memory");
    fromhost = 0;
    tohost = ((uint64_t)(unsigned)code << 1) | 1;
    asm volatile("fence rw,rw\n1: j 1b" ::: "memory");
    __builtin_unreachable();
}

static int fail(const char *test, uint64_t actual, uint64_t expected)
{
    printf("EC-Test FAIL %s actual=%016" PRIx64 " expected=%016" PRIx64 "\n",
           test, actual, expected);
    return 1;
}

static __attribute__((noinline)) uint64_t update_lines(unsigned round)
{
    uint64_t difference = 0;
    for (unsigned i = 0; i < LINES; ++i) {
        volatile uint64_t *line = lines[i];
        const uint64_t delta = (i & 1) ? 3 * i + 1 : i + 1;
        const uint64_t old = line[0];
        difference |= old ^ (i + round * delta);
        line[0] = old + delta;
        ((volatile uint8_t *)&line[1])[round] = (uint8_t)(round ^ i);
    }
    return difference;
}

int main(void)
{
    r_ini(NUM_CHECKERS);
    csr_software_cfg();
    while (ght_get_initialisation() == 0) {}
    ght_set_satp_priv();

    for (unsigned i = 0; i < LINES; ++i) {
        lines[i][0] = i;
        lines[i][1] = UINT64_C(0xa5a5a5a500000000);
    }
    volatile uint32_t *const lanes = (volatile uint32_t *)&lines[0][2];
    lanes[0] = 10;
    lanes[1] = 20;
    *mtimecmp = timer_base;
    asm volatile("fmv.d.x f0, %0\ncsrw sscratch, zero" :: "r"(fp_seed) : "f0", "memory");

    uint64_t memory_difference = 0, amo_difference = 0, io_difference = 0, csr_difference = 0;
    uint64_t fp_difference = 0;
    ghe_fpga_perf_start();
    ROCC_INSTRUCTION(1, 0x31);
    ROCC_INSTRUCTION_S(1, 1, 0x70);
    for (unsigned round = 0; round < ROUNDS; ++round) {
        memory_difference |= update_lines(round);
        uint64_t fp;
        asm volatile("fadd.d f0, f0, %1\nfmv.x.d %0, f0"
                     : "=r"(fp) : "f"(fp_increment) : "f0");
        const uint64_t expected = UINT64_C(0x4000000000000000) + ((uint64_t)round << 50);
        fp_difference |= fp ^ expected;
        amo_difference |= __atomic_fetch_add(&lanes[0], 1, __ATOMIC_ACQ_REL) ^ (10 + round);
        amo_difference |= __atomic_fetch_add(&lanes[1], 2, __ATOMIC_ACQ_REL) ^ (20 + 2 * round);

        csr_difference |= swap_csr(sscratch, round | 16) ^ round;
        csr_difference |= clear_csr(sscratch, 16) ^ (round | 16);
        write_csr(sscratch, round + 1);
        asm volatile("ecall\nfence iorw,iorw" ::: "memory");

        uint64_t previous;
        asm volatile("amoadd.d %0, %2, (%1)"
                     : "=r"(previous) : "r"(mtimecmp), "r"(UINT64_C(1)) : "memory");
        io_difference |= previous ^ (timer_base + round);
        io_difference |= *mtimecmp ^ (timer_base + round + 1);
        *msip = 1;
        while (palimpsest_msip_counts[0].value <= (int)round) {}
        io_difference |= *msip;
    }

    ROCC_INSTRUCTION_S(1, 2, 0x70);
    asm volatile(".rept 26\nnop\n.endr");
    ROCC_INSTRUCTION(1, 0x32);
    while (ght_get_status() < 0x1ffff) {}
    ghe_fpga_perf_stop();

    const uint64_t passed = ghe_traffic_counter_read(GHE_TRAFFIC_PASSED_PACKAGES);
    const uint64_t failed = ghe_traffic_counter_read(GHE_TRAFFIC_FAILED_PACKAGES);
    const uint64_t cancelled = ghe_traffic_counter_read(GHE_TRAFFIC_CANCELLED_PACKAGES);
    const uint64_t dropped = ghe_traffic_counter_read(GHE_TRAFFIC_PACKAGE_RESULT_DROPPED);
    const uint64_t watermark = ghe_traffic_counter_read(GHE_TRAFFIC_SAFE_PACKET_WATERMARK);
    const uint64_t l1_wb = ghe_traffic_counter_read(GHE_TRAFFIC_L1_L2_WB_DIRTY);
    const uint64_t l2_wb = ghe_traffic_counter_read(GHE_TRAFFIC_L2_DRAM_WB_DIRTY);
    uint64_t fp;
    asm volatile("fmv.x.d %0, f0" : "=r"(fp));
    const uint64_t scratch = read_csr(sscratch);
    ght_unset_satp_priv();
    ROCC_INSTRUCTION(1, 0x30);

    if (memory_difference) return fail("memory.old", memory_difference, 0);
    for (unsigned i = 0; i < LINES; ++i) {
        const uint64_t delta = (i & 1) ? 3 * i + 1 : i + 1;
        const uint64_t expected = i + ROUNDS * delta;
        uint64_t actual = lines[i][0];
        if (actual != expected) return fail("memory.word", actual, expected);
        uint64_t bytes = UINT64_C(0xa5a5a5a500000000);
        for (unsigned round = 0; round < ROUNDS; ++round)
            bytes |= (uint64_t)(round ^ i) << (8 * round);
        actual = lines[i][1];
        if (actual != bytes) return fail("memory.bytes", actual, bytes);
    }
    if (amo_difference) return fail("amo.old", amo_difference, 0);
    const uint64_t lane_pair = (uint64_t)lanes[1] << 32 | lanes[0];
    const uint64_t expected_pair = (uint64_t)(20 + 2 * ROUNDS) << 32 | (10 + ROUNDS);
    if (lane_pair != expected_pair) return fail("amo.lanes", lane_pair, expected_pair);
    if (csr_difference) return fail("csr.rmw", csr_difference, 0);
    if (scratch != ROUNDS) return fail("csr.final", scratch, ROUNDS);
    if (fp_difference) return fail("register.f0.round", fp_difference, 0);
    const uint64_t expected_fp = UINT64_C(0x400c000000000000); /* 3.5 */
    if (fp != expected_fp) return fail("register.f0.final", fp, expected_fp);
    if (io_difference) return fail("mmio", io_difference, 0);
    if (palimpsest_msip_counts[0].value != ROUNDS)
        return fail("trap.msip", palimpsest_msip_counts[0].value, ROUNDS);
    if (palimpsest_ecall_counts[0].value != ROUNDS)
        return fail("trap.ecall", palimpsest_ecall_counts[0].value, ROUNDS);
    if (!passed) return fail("ec.checker-pass", passed, 1);
    if (!watermark) return fail("ec.watermark", watermark, 1);
    if (cancelled) return fail("ec.checker-cancelled", cancelled, 0);
    if (dropped) return fail("ec.checker-dropped", dropped, 0);
    if (!l1_wb || !l2_wb) return fail("cache.writeback", (l2_wb << 32) | l1_wb, 0x100000001);

    printf("EC-Test PASS rounds=%u lines=%u checker_pass=%" PRIu64
           " checker_fail=%" PRIu64 " safe=%" PRIu64
           " l1_wb=%" PRIu64 " l2_wb=%" PRIu64 "\n",
           ROUNDS, LINES, passed, failed, watermark, l1_wb, l2_wb);
    return 0;
}
