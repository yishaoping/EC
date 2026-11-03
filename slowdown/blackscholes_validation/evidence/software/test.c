#include <inttypes.h>
#include <stdio.h>

#include "cfg/init.h"
#include "cfg/config.h"
#include "hw/cycle.h"
#include "hw/ghe.h"
#include "hw/ght.h"
#include "hw/interrupt.h"
#include "hw/rocc.h"
#include "hw/spin_lock.h"
#include "stat/report.h"
extern void blackscholes_prepare(void);
extern void blackscholes_run(void);
extern int blackscholes_verify(void);
static uint64_t retired_start, retired_stop;

/* A finite HTIF exit lets L1 drain. libgloss's repeated tohost/fromhost
 * stores create new work after the host has already observed success. */
extern volatile uint64_t tohost;
extern volatile uint64_t fromhost;
void __attribute__((noreturn, noinline)) _exit(int code)
{
    __asm__ volatile("csrci mstatus, 8" ::: "memory");
    fromhost = 0;
    tohost = (((uint64_t)(unsigned int)code << 1) | 1) & ((1ULL << 48) - 1);
    __asm__ volatile("fence rw,rw\n1: j 1b" ::: "memory");
    __builtin_unreachable();
}

/* Shared GHT, interrupt, privilege, and timer setup. */
static uint64_t test_setup(void)
{
    r_ini(NUM_CHECKERS);
    csr_software_cfg();
    msip_cfg();

    lock_acquire(&uart_lock);
    printf("[INIT] software_interrupt=pass\n");
    lock_release(&uart_lock);

    while (ght_get_initialisation() == 0) {
    }

    uint64_t hart_id = 0;
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));
    lock_acquire(&uart_lock);
    printf("[RUN] hart=%lx status=started\n", hart_id);
    printf("[CONFIG] common_abi=1 harts=5 timer_stride=64 legacy_readback=off\n");
    lock_release(&uart_lock);

    ght_set_satp_priv();
    mtimecmp_cfg();
    csr_timer_cfg();
    ghe_common_observer_init();
    ghe_common_observer_start();
    return hart_id;
}

/* Same protected-session start/stop and completion protocol as common BFS. */
int main(void) {
    uint64_t hart_id=test_setup(), start_cpu, end_cpu;
    blackscholes_prepare();
    ROCC_INSTRUCTION(1,0x31);
    ROCC_INSTRUCTION_S(1,0x01,0x70);
    __asm__ volatile(".global common_roi_start\ncommon_roi_start:\nrdcycle %0" : "=r"(start_cpu) :: "memory");
    __asm__ volatile("rdinstret %0" : "=r"(retired_start) :: "memory");
    blackscholes_run();
    ROCC_INSTRUCTION_S(1,0x02,0x70);
    for(int i=0;i<26;i++) __asm__ volatile("nop");
    ROCC_INSTRUCTION(1,0x32);
    while(ght_get_status()<0x1ffff) {}
    __asm__ volatile("rdinstret %0" : "=r"(retired_stop) :: "memory");
    __asm__ volatile(".global common_roi_stop\ncommon_roi_stop:\nrdcycle %0" : "=r"(end_cpu) :: "memory");
    int ok=blackscholes_verify();
    ok=report_end(start_cpu,end_cpu,hart_id) && ok;
    printf("[WORK] roi_instret=%lu expected_pricings=400\n",(unsigned long)(retired_stop-retired_start));
    printf("[COMPUTATION] status=%s scope=parsec_blackscholes_test4_100runs\n",ok?"PASS":"FAIL");
    printf("[END] hart=0 status=%s\n",ok?"PASS":"FAIL");
    ght_unset_satp_priv(); ROCC_INSTRUCTION(1,0x30);
    return ok?0:1;
}
