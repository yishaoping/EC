#include <stdint.h>
#include <stdio.h>
#include "hw/interrupt.h"
extern volatile uint64_t tohost,fromhost;
extern void workload_prepare(void),workload_run(void);
extern int workload_verify(void);
volatile uint64_t eval_protected __attribute__((section(".eval_mode")))=0;
void __attribute__((noreturn,noinline)) _exit(int code) {
 __asm__ volatile("csrci mstatus,8":::"memory"); fromhost=0;
 tohost=(((uint64_t)(unsigned int)code<<1)|1)&((1ULL<<48)-1);
 __asm__ volatile("fence rw,rw\n1: j 1b":::"memory");__builtin_unreachable();
}
int main(void) {
 uint64_t hart,start,end,is,ie;
 __asm__ volatile("csrr %0,mhartid":"=r"(hart));
 if(hart!=0)return 2;
 printf("[CONFIG] profile=clean-single-boom no_checker=1 threads=1 native_boot_adapter=1\n");
 __asm__ volatile("csrc mie, %0" :: "r"((uint64_t)128) : "memory");
 workload_prepare();
 __asm__ volatile(".global common_roi_start\ncommon_roi_start:\nrdcycle %0\nrdinstret %1":"=r"(start),"=r"(is)::"memory");
 uint64_t timer_before=timer_flags[0].value;
 workload_run();
 __asm__ volatile(".global common_roi_stop\ncommon_roi_stop:\nrdinstret %1\nrdcycle %0":"=r"(end),"=r"(ie)::"memory");
 printf("[ROI] hart=0 start=%lu stop=%lu cycles=%lu\n",start,end,end-start);
 printf("[IRQ] policy=main_timer_disabled before=%lu after=%d mie=%lu\n",timer_before,timer_flags[0].value,(unsigned long)read_csr(mie));
 int ok=workload_verify();
 printf("[APP] protected=0 start=%lu end=%lu cycles=%lu instret=%lu session_stop=%lu\n",start,end,end-start,ie-is,end);
 printf("[COMPUTATION] status=%s scope=official_serial_kernel\n",ok?"PASS":"FAIL");
 printf("[END] hart=0 status=%s\n",ok?"PASS":"FAIL");return ok?0:1;
}
