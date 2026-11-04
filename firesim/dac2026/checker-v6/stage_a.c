#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include "cfg/init.h"
#include "cfg/config.h"
#include "hw/cycle.h"
#include "hw/ghe.h"
#include "hw/ght.h"
#include "hw/interrupt.h"
#include "stat/report.h"

/* Real Opt4 software interface. No simulated checker or substituted result. */
static volatile uint64_t values[128];
extern volatile uint64_t tohost, fromhost;
void __attribute__((noreturn)) _exit(int code)
{
    __asm__ volatile("csrci mstatus,8" ::: "memory");
    fromhost = 0;
    tohost = ((uint64_t)(unsigned)code << 1) | 1;
    __asm__ volatile("fence rw,rw\n1: j 1b" ::: "memory");
    __builtin_unreachable();
}

int main(void)
{
    r_ini(4);
    csr_software_cfg();
    msip_cfg();
    while (!ght_get_initialisation()) {}
    ght_set_satp_priv();
    ghe_fpga_perf_reset();
    ghe_fpga_perf_start();
    for (unsigned i = 0; i < 128; ++i) values[i] = i;
    printf("EC_OPT4_A_START rounds=8192 checker_mask=15\n");
    ROCC_INSTRUCTION(1, 0x31);
    ROCC_INSTRUCTION_S(1, 1, 0x70);
    uint64_t begin = read_cycles();
    for (unsigned i = 0; i < 8192; ++i) values[i & 127] += 3;
    uint64_t end = read_cycles();
    ROCC_INSTRUCTION_S(1, 2, 0x70);
    ROCC_INSTRUCTION(1, 0x32);
    uint64_t deadline = read_cycles();
    int timeout = 0;
    while (ght_get_status() < 0x1ffff) {
        if (read_cycles() - deadline > 2000000) { timeout = 1; break; }
    }
    uint64_t generated = 0, completed = 0, passed = 0;
    uint64_t previous_generated = UINT64_MAX, previous_completed = UINT64_MAX;
    unsigned stable_samples = 0;
    while (!timeout && stable_samples < 8) {
        generated = ghe_traffic_counter_read(GHE_TRAFFIC_ALLOCATED_PACKAGES);
        completed = ghe_traffic_counter_read(GHE_TRAFFIC_COMPLETED_PACKAGES);
        passed = ghe_traffic_counter_read(GHE_TRAFFIC_PASSED_PACKAGES);
        if (generated == completed && completed == passed &&
            generated == previous_generated && completed == previous_completed) {
            ++stable_samples;
        } else {
            stable_samples = 0;
        }
        previous_generated = generated;
        previous_completed = completed;
        if (read_cycles() - deadline > 2000000) timeout = 1;
    }
    uint64_t failed = ghe_traffic_counter_read(GHE_TRAFFIC_FAILED_PACKAGES);
    uint64_t cancelled = ghe_traffic_counter_read(GHE_TRAFFIC_CANCELLED_PACKAGES);
    uint64_t dropped = ghe_traffic_counter_read(GHE_TRAFFIC_PACKAGE_RESULT_DROPPED);
    uint64_t drained = read_cycles();
    uint64_t checksum = 0;
    for (unsigned i = 0; i < 128; ++i) checksum += values[i];
    int ok = !timeout && checksum == 32704 && generated >= 2 &&
        generated == completed && completed == passed && !failed && !cancelled && !dropped;
    printf("EC_OPT4_A_RESULT cycles=%" PRIu64 " drain_cycles=%" PRIu64
           " generated=%" PRIu64 " completed=%" PRIu64 " passed=%" PRIu64
           " failed=%" PRIu64 " cancelled=%" PRIu64 " dropped=%" PRIu64
           " outstanding=%" PRIu64 " checksum=%" PRIu64
           " expected=32704 timeout=%d status=%s\n",
           end-begin, drained-end, generated, completed, passed, failed, cancelled,
           dropped, generated >= completed ? generated-completed : UINT64_MAX,
           checksum, timeout, ok ? "PASS" : "FAIL");
    ght_unset_satp_priv();
    ROCC_INSTRUCTION(1, 0x30);
    return ok ? 0 : 1;
}
