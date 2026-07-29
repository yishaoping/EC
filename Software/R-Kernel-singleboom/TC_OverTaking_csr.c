#include <stdio.h>
#include <stdlib.h>
#include "rocc.h"
#include "spin_lock.h"
#include "ght.h"
#include "ghe.h"
#include "tasks.h"
#include <inttypes.h>
#include "timer.h"
#include <riscv-pk/encoding.h>

#define U32         *(volatile unsigned int *)
#define msip_offest 4
#define timer_limitation 50
#define timer_cmp 0x20

#define CLINT_BASE      0x2000000
#define MSIP_OFFSET(h)  (h * 4)
#define TIMECMP_OFFSET(h) (0x4000 + h * 8)
#define MTIME_ADDR      (CLINT_BASE + 0xBFF8)

volatile int timer_flags[4] = {0};

#define NUM_CHECKERS 4
#define totalcsrperf 84
#ifndef FPGA_PERF_INTERVAL_CYCLES
#define FPGA_PERF_INTERVAL_CYCLES 5000ULL
#endif

uint64_t csr_read_s[totalcsrperf];
uint64_t csr_read_e[totalcsrperf];

#if 0
static void print_ic_perf_counters(void);
#endif
#if MEEK_ENABLE_BIG_CORE_PERF
static void print_fpga_perf_trace(void);
#endif

void handle_trap();
void csr_cfg();
void mtimecmp_cfg();
void msip_cfg();


int uart_lock;
size_t total_cycle_s;  
size_t total_commit_s; 
size_t total_csr_s;  
size_t csrw_s; 
size_t mstatus_s;  
size_t misa_s;  
size_t medeleg_s;      
size_t mideleg_s;
size_t mie_s;         
size_t mtvec_s;     
size_t mcounen_s;
size_t mscratch_s;
size_t mepc_s;
size_t mcause_s;
size_t mtval_s;
size_t mip_s;
size_t mtval2_s;
size_t menvcfg_s;
size_t mseccfg_s;
size_t pmpcfg0_s;
size_t pmpaddr0_s;
size_t mcountinh_s;
size_t fflags_s;

size_t total_cycle_e;  
size_t total_commit_e; 
size_t total_csr_e;  
size_t csrw_e; 
size_t mstatus_e;  
size_t misa_e;  
size_t medeleg_e;      
size_t mideleg_e;
size_t mie_e;         
size_t mtvec_e;     
size_t mcounen_e;
size_t mscratch_e;
size_t mepc_e;
size_t mcause_e;
size_t mtval_e;
size_t mip_e;
size_t mtval2_e;
size_t menvcfg_e;
size_t mseccfg_e;
size_t pmpcfg0_e;
size_t pmpaddr0_e;
size_t mcountinh_e;
size_t fflags_e;

// 安全读取64位mtime
uint64_t get_mtime() {
  volatile uint32_t* mtime_low = (uint32_t*)MTIME_ADDR;
  volatile uint32_t* mtime_high = (uint32_t*)(MTIME_ADDR + 4);
  uint32_t hi, lo;
  do {
      hi = *mtime_high;
      lo = *mtime_low;
  } while (hi != *mtime_high);
  return ((uint64_t)hi << 32) | lo;
}

// 核心独立的软件中断配置
void msip_cfg() {
  uint64_t hart_id;
  asm volatile ("csrr %0, mhartid" : "=r"(hart_id));
  
  volatile uint32_t* msip = (uint32_t*)(CLINT_BASE + MSIP_OFFSET(hart_id));
  *msip = 0x1; // 触发当前核心的中断
  // lock_acquire(&uart_lock);
  // printf("Core%d: MSIP at 0x%p\n", hart_id, msip);
  // lock_release(&uart_lock);
}

// 核心独立的定时器配置
void mtimecmp_cfg() {
  uint64_t hart_id;
  asm volatile ("csrr %0, mhartid" : "=r"(hart_id));
  
  volatile uint32_t* mtimecmp_low = (uint32_t*)(CLINT_BASE + TIMECMP_OFFSET(hart_id));
  volatile uint32_t* mtimecmp_high = (uint32_t*)(CLINT_BASE + TIMECMP_OFFSET(hart_id) + 4);
  
  uint64_t current = get_mtime();
  uint64_t cmp_val = current + timer_cmp; // 1M cycles间隔
  
  *mtimecmp_low = (uint32_t)cmp_val;
  *mtimecmp_high = (uint32_t)(cmp_val >> 32);
  // lock_acquire(&uart_lock);
  // printf("Core%d: mtimecmp@0x%p\n", hart_id, mtimecmp_low);
  // lock_release(&uart_lock);
}

// CSR interrupt configuration function
void csr_timer_cfg()
{
  uint64_t hart_id;
  asm volatile ("csrr %0, mhartid" : "=r"(hart_id));
  unsigned int csr_tmp;
  //mie.MEIE
  csr_tmp = read_csr(mie);
  // U32(DEBUG_VAL) = csr_tmp;
  //write_csr(mie,0x0);
  write_csr(mie,(csr_tmp | 0x80));
  // lock_acquire(&uart_lock);
  // printf("Core:%d: Timer configuration complete\n", hart_id);
  // lock_release(&uart_lock);
}
void csr_software_cfg()
{
  uint64_t hart_id;
  asm volatile ("csrr %0, mhartid" : "=r"(hart_id));
  unsigned int csr_tmp;
  //mie.MEIE
  csr_tmp = read_csr(mie);
  // U32(DEBUG_VAL) = csr_tmp;
  //write_csr(mie,0x0);
  write_csr(mie,(csr_tmp | 0x8));
  //mstatus.MIE
  csr_tmp = read_csr(mstatus);
  // U32(DEBUG_VAL) = csr_tmp;
  //write_csr(mstatus,0x0);
  write_csr(mstatus,(csr_tmp | 0x8));
  // lock_acquire(&uart_lock);
  // printf("Core:%d: Software configuration complete\n", hart_id);
  // lock_release(&uart_lock);
}

void handle_trap() {
  // uint64_t saved_mepc = mepc; // 立即保存到局部变量
  // 进入中断处理
  // U32(DEBUG_SIG) = 0x5;
  uint64_t hart_id;
  asm volatile ("csrr %0, mhartid" : "=r"(hart_id));

  uint64_t mcause_val = read_csr(mcause);
  uint64_t interrupt = mcause_val >> 63;  // 最高位表示中断还是异常
  uint64_t cause_code = mcause_val & 0x7FFFFFFFFFFFFFFF;

  if(interrupt){
    // 处理软件中断
    if ((read_csr(mip) & 0x8) != 0) { // 检查MSIP
      // U32(0x2000000) = 0x0;        // 清除软件中断
      volatile uint32_t* msip = (uint32_t*)(CLINT_BASE + MSIP_OFFSET(hart_id));// 清除当前核心的MSIP
      *msip = 0x0;
    }
    // // 处理定时器中断
    // else if((read_csr(mip) & 0x80) != 0) {
    //   // 安全读取当前时间
    //   unsigned long long current_time = get_mtime();
    //   // U32(0x2004000) = (unsigned int)(current_time + timer_cmp);     // 写入低32位
    //   // U32(0x2004004) = (unsigned int)((current_time + timer_cmp) >> 32); // 写入高32位
    //   volatile uint32_t* mtimecmp = (uint32_t*)(CLINT_BASE + TIMECMP_OFFSET(hart_id));
    //   uint64_t new_cmp = get_mtime() + 0x10;
    //   *(uint64_t*)mtimecmp = new_cmp; // 直接写入64位
    // }
  
    // 处理定时器中断
    else if ((read_csr(mip) & 0x80) != 0) { // 检查MTIP
      // 安全读取当前时间
      unsigned long long current_time = get_mtime();
      if(hart_id == 0){
        timer_flags[0] += 1;
        // 更新mtimecmp（当前时间 + 间隔0x10）
        if(timer_flags[0] < timer_limitation){
          // U32(0x2004000) = (unsigned int)(current_time + timer_cmp);     // 写入低32位
          // U32(0x2004004) = (unsigned int)((current_time + timer_cmp) >> 32); // 写入高32位
          volatile uint32_t* mtimecmp = (uint32_t*)(CLINT_BASE + TIMECMP_OFFSET(hart_id));
          uint64_t new_cmp = get_mtime() + timer_cmp;
          *(uint64_t*)mtimecmp = new_cmp; // 直接写入64位
        }
        // 达到条件后禁用定时器中断
        else if (timer_flags[0] >= timer_limitation) {
            unsigned int mie_val = read_csr(mie);
            write_csr(mie, mie_val & ~0x80); // 清除 MTIE (Bit7)
            // printf("Timer interrupts disabled.\n");
            // 清除 MIE 位（Bit3）
            unsigned int mstatus_val = read_csr(mstatus);
            write_csr(mstatus, mstatus_val & ~0x8); 
        }
      }
      else if(hart_id == 1){
        timer_flags[1] += 1;
        // 更新mtimecmp（当前时间 + 间隔0x10）
        if(timer_flags[1] < timer_limitation){
          // U32(0x2004000) = (unsigned int)(current_time + timer_cmp);     // 写入低32位
          // U32(0x2004004) = (unsigned int)((current_time + timer_cmp) >> 32); // 写入高32位
          volatile uint32_t* mtimecmp = (uint32_t*)(CLINT_BASE + TIMECMP_OFFSET(hart_id));
          uint64_t new_cmp = get_mtime() + timer_cmp;
          *(uint64_t*)mtimecmp = new_cmp; // 直接写入64位
        }
        // 达到条件后禁用定时器中断
        else if (timer_flags[1] >= timer_limitation) {
            unsigned int mie_val = read_csr(mie);
            write_csr(mie, mie_val & ~0x80); // 清除 MTIE (Bit7)
            // printf("Timer interrupts disabled.\n");
            // 清除 MIE 位（Bit3）
            unsigned int mstatus_val = read_csr(mstatus);
            write_csr(mstatus, mstatus_val & ~0x8); 
        }
      }
      else if(hart_id == 2){
        timer_flags[2] += 1;
        // 更新mtimecmp（当前时间 + 间隔0x10）
        if(timer_flags[2] < timer_limitation){
          // U32(0x2004000) = (unsigned int)(current_time + timer_cmp);     // 写入低32位
          // U32(0x2004004) = (unsigned int)((current_time + timer_cmp) >> 32); // 写入高32位
          volatile uint32_t* mtimecmp = (uint32_t*)(CLINT_BASE + TIMECMP_OFFSET(hart_id));
          uint64_t new_cmp = get_mtime() + timer_cmp;
          *(uint64_t*)mtimecmp = new_cmp; // 直接写入64位
        }
        // 达到条件后禁用定时器中断
        else if (timer_flags[2] >= timer_limitation) {
            unsigned int mie_val = read_csr(mie);
            write_csr(mie, mie_val & ~0x80); // 清除 MTIE (Bit7)
            // printf("Timer interrupts disabled.\n");
            // 清除 MIE 位（Bit3）
            unsigned int mstatus_val = read_csr(mstatus);
            write_csr(mstatus, mstatus_val & ~0x8); 
        }
      }
      else if(hart_id == 3){
        timer_flags[3] += 1;
        // 更新mtimecmp（当前时间 + 间隔0x10）
        if(timer_flags[3] < timer_limitation){
          // U32(0x2004000) = (unsigned int)(current_time + timer_cmp);     // 写入低32位
          // U32(0x2004004) = (unsigned int)((current_time + timer_cmp) >> 32); // 写入高32位
          volatile uint32_t* mtimecmp = (uint32_t*)(CLINT_BASE + TIMECMP_OFFSET(hart_id));
          uint64_t new_cmp = get_mtime() + timer_cmp;
          *(uint64_t*)mtimecmp = new_cmp; // 直接写入64位
        }
        // 达到条件后禁用定时器中断
        else if (timer_flags[3] >= timer_limitation) {
            unsigned int mie_val = read_csr(mie);
            write_csr(mie, mie_val & ~0x80); // 清除 MTIE (Bit7)
            // printf("Timer interrupts disabled.\n");
            // 清除 MIE 位（Bit3）
            unsigned int mstatus_val = read_csr(mstatus);
            write_csr(mstatus, mstatus_val & ~0x8); 
        }
      }
    }
  } else {
    switch (cause_code)
    {
    case 11:
      // 更新 mepc 到下一条指令
      write_csr(mepc, read_csr(mepc) + 4);
      // 将更新后的 mepc 值读取到 a0 寄存器
      __asm__ volatile ("csrr a0, mepc");  // handle_trap之后会用a0更新mepc
      break;
    
    default:
      break;
    }
  }
  
  // return saved_mepc;
  // 确保 a0 始终保存当前 mepc，供 trap_entry 写回
  __asm__ volatile ("csrr a0, mepc");
  // return saved_mepc;
}


void perfstart(){
  for(int i = 0; i < totalcsrperf; i++){
    csr_read_s[i] = ghe_csr_perf_read(i);
  }
  write_csr(mhpmevent3,0x0200);
  write_csr(mhpmevent4,0x0400);
  write_csr(mhpmevent5,0x0800);
  write_csr(mhpmevent6,0x1000);
  write_csr(mhpmevent7,0x2000);
  write_csr(mhpmevent8,0x4000);
  write_csr(mhpmevent9,0x8000);
  write_csr(mhpmevent10,0x10000);
  write_csr(mhpmevent11,0x20000);
  write_csr(mhpmevent12,0x40000);
  write_csr(mhpmevent13,0x80000);
  write_csr(mhpmevent14,0x100000);
  write_csr(mhpmevent15,0x200000);
  write_csr(mhpmevent16,0x400000);
  write_csr(mhpmevent17,0x800000);
  write_csr(mhpmevent18,0x1000000);
  write_csr(mhpmevent19,0x2000000);
  write_csr(mhpmevent20,0x4000000);
  write_csr(mhpmevent21,0x8000000);
  write_csr(mhpmevent22,0x10000000);
  write_csr(mhpmevent23,0x20000000);
  write_csr(mhpmevent24,0x40000000);//22
  asm volatile ("csrrw	tp,sscratch, tp");
  asm volatile ("csrrw	tp,sscratch, tp");
  asm volatile ("csrw sscratch, x0");

  total_cycle_s     = read_csr(mcycle);
  total_commit_s    = read_csr(mhpmcounter3);
  total_csr_s       = read_csr(mhpmcounter4);
  csrw_s            = read_csr(mhpmcounter5);
  mstatus_s         = read_csr(mhpmcounter6); 
  misa_s            = read_csr(mhpmcounter7); 
  medeleg_s         = read_csr(mhpmcounter8); 
  mideleg_s         = read_csr(mhpmcounter9); 
  mie_s             = read_csr(mhpmcounter10);
  mtvec_s           = read_csr(mhpmcounter11);
  mcounen_s         = read_csr(mhpmcounter12);
  mscratch_s        = read_csr(mhpmcounter13);
  mepc_s            = read_csr(mhpmcounter14);
  mcause_s          = read_csr(mhpmcounter15);
  mtval_s           = read_csr(mhpmcounter16);
  mip_s             = read_csr(mhpmcounter17);
  mtval2_s          = read_csr(mhpmcounter18);
  menvcfg_s         = read_csr(mhpmcounter19);
  mseccfg_s         = read_csr(mhpmcounter20);
  pmpcfg0_s         = read_csr(mhpmcounter21);
  pmpaddr0_s        = read_csr(mhpmcounter22);
  mcountinh_s       = read_csr(mhpmcounter23);
  fflags_s          = read_csr(mhpmcounter24);//23
  lock_acquire(&uart_lock);
  printf("Perf Test begin \n");
  lock_release(&uart_lock);
}

void perfend(){
  total_cycle_e     = read_csr(mcycle) - total_cycle_s;
  total_commit_e    = read_csr(mhpmcounter3)  - total_commit_s  ;
  total_csr_e       = read_csr(mhpmcounter4)  - total_csr_s   ;
  csrw_e            = read_csr(mhpmcounter5)  - csrw_s  ;
  mstatus_e         = read_csr(mhpmcounter6)  - mstatus_s   ; 
  misa_e            = read_csr(mhpmcounter7)  - misa_s  ; 
  medeleg_e         = read_csr(mhpmcounter8)  - medeleg_s     ;   
  mideleg_e         = read_csr(mhpmcounter9)  - mideleg_s     ; 
  mie_e             = read_csr(mhpmcounter10) - mie_s    ;         
  mtvec_e           = read_csr(mhpmcounter11) - mtvec_s   ;     
  mcounen_e         = read_csr(mhpmcounter12) - mcounen_s    ; 
  mscratch_e        = read_csr(mhpmcounter13) - mscratch_s    ;
  mepc_e            = read_csr(mhpmcounter14) - mepc_s    ;
  mcause_e          = read_csr(mhpmcounter15) - mcause_s;
  mtval_e           = read_csr(mhpmcounter16) - mtval_s    ;
  mip_e             = read_csr(mhpmcounter17) - mip_s    ;
  mtval2_e          = read_csr(mhpmcounter18) - mtval2_s    ;
  menvcfg_e         = read_csr(mhpmcounter19) - menvcfg_s    ;
  mseccfg_e         = read_csr(mhpmcounter20) - mseccfg_s    ;
  pmpcfg0_e         = read_csr(mhpmcounter21) - pmpcfg0_s    ;
  pmpaddr0_e        = read_csr(mhpmcounter22) - pmpaddr0_s    ;
  mcountinh_e       = read_csr(mhpmcounter23) - mcountinh_s    ;
  fflags_e          = read_csr(mhpmcounter24) - fflags_s;

  for(int i = 0; i < totalcsrperf; i++){
    csr_read_e[i] = ghe_csr_perf_read(i) - csr_read_s[i];
  }
}


int r_ini (int num_checkers);
static uint64_t read_cycles() {
  uint64_t cycles;
  asm volatile ("rdcycle %0" : "=r" (cycles));
  return cycles;

  // const uint32_t * mtime = (uint32_t *)(33554432 + 0xbff8);
  // const uint32_t * mtime = (uint32_t *)(33554432 + 0xbffc);
  // return *mtime;
}

#if 0
static void print_ic_perf_counters(void)
{
  static const char *const names[GHE_PERF_COUNTER_COUNT] = {
    "MemInstCounter", "BCounter", "SchState", "CheckState",
    "OtherThread", "SchState_Allbusy", "SchState_OT", "CCounter",
    "rsu_stall", "gh_stall", "InstCounter", "kernel_instcnt",
    "excep_cnt", "interr", "stall_excpt", "stall_interr"
  };
  uint64_t values[GHE_PERF_COUNTER_COUNT];

  for (int selector = 0; selector < GHE_PERF_COUNTER_COUNT; selector++) {
    values[selector] = ghe_perf_read_sel(selector);
  }

  uint64_t cycles = values[GHE_PERF_SEL_CCOUNTER];
  uint64_t inst = values[GHE_PERF_SEL_INST];
  uint64_t mem_inst = values[GHE_PERF_SEL_MEM_INST];
  uint64_t check_cycles = values[GHE_PERF_SEL_CHECK_STATE];
  uint64_t allbusy_cycles = values[GHE_PERF_SEL_ALLBUSY];

  lock_acquire(&uart_lock);
  printf("[IC_PERF] begin\r\n");
  for (int selector = 0; selector < GHE_PERF_COUNTER_COUNT; selector++) {
    printf("[IC_PERF] sel=%d %-20s = %" PRIu64 "\r\n",
           selector, names[selector], values[selector]);
  }
  printf("[IC_PERF] ipc_x1000=%" PRIu64 " mem_pct=%" PRIu64
         "%% check_pct=%" PRIu64 "%% allbusy_pct=%" PRIu64 "%%\r\n",
         cycles ? inst * 1000 / cycles : 0,
         inst ? mem_inst * 100 / inst : 0,
         cycles ? check_cycles * 100 / cycles : 0,
         cycles ? allbusy_cycles * 100 / cycles : 0);
  printf("[IC_PERF] end\r\n");
  lock_release(&uart_lock);
}
#endif

#if MEEK_ENABLE_BIG_CORE_PERF
static void print_fpga_perf_trace(void)
{
  uint64_t sample_count = ghe_fpga_perf_read_sel(GHE_FPGA_PERF_SEL_SAMPLE_COUNT);
  uint64_t status = ghe_fpga_perf_read_sel(GHE_FPGA_PERF_SEL_STATUS);
  uint64_t overflow = status & 0x1;
  uint64_t depth = (status >> 1) & 0x1fff;
  uint64_t interval = (status >> 14) & 0xffffffff;
  uint64_t total_cycles = ghe_fpga_perf_read_sel(GHE_FPGA_PERF_SEL_TOTAL_CYCLES);
  uint64_t total_allbusy = ghe_fpga_perf_read_sel(GHE_FPGA_PERF_SEL_TOTAL_ALLBUSY);
  uint64_t total_rsu = ghe_fpga_perf_read_sel(GHE_FPGA_PERF_SEL_TOTAL_RSU);
  uint64_t total_gh = ghe_fpga_perf_read_sel(GHE_FPGA_PERF_SEL_TOTAL_GH);
  uint64_t total_bcounter = ghe_fpga_perf_read_sel(GHE_FPGA_PERF_SEL_TOTAL_BCOUNT);

  lock_acquire(&uart_lock);
  printf("[FPGA_PERF_TOTAL] cycles=%" PRIu64 " allbusy=%" PRIu64
         " rsu_stall=%" PRIu64 " gh_stall=%" PRIu64 " bcounter=%" PRIu64 "\r\n",
         total_cycles, total_allbusy, total_rsu, total_gh, total_bcounter);
  printf("[FPGA_PERF] begin samples=%" PRIu64 " depth=%" PRIu64
         " interval_cycles=%" PRIu64 " overflow=%" PRIu64 "\r\n",
         sample_count, depth, interval, overflow);

  for (uint64_t index = 0; index < sample_count; index++) {
    uint64_t data_lo;
    uint64_t data_hi;
    ghe_fpga_perf_read_record(&data_lo, &data_hi);

    printf("[FPGA_PERF] index=%" PRIu64 " cycles=%" PRIu64
           " allbusy=%" PRIu64 " inst=%" PRIu64 " mem_inst=%" PRIu64 "\r\n",
           index, data_hi >> 32, data_hi & 0xffffffff,
           data_lo >> 32, data_lo & 0xffffffff);

    if (index + 1 < sample_count) {
      ghe_fpga_perf_advance();
    }
  }

  printf("[FPGA_PERF] end\r\n");
  lock_release(&uart_lock);
}
#endif

/* Core_0 thread */
int main(void)
{
  // int *arr = (int *)malloc(1024 * sizeof(int));
  // perfstart();
  // for (int i = 0; i < 1024; i++) {
  //   arr[i] = i;
  // }

  // // 跳跃式访问数组元素，破坏空间局部性
  // for (int i = 0; i < 512; i += 16) {
  //     printf("%d ", arr[i]);
  // }
  // free(arr);
  r_ini(NUM_CHECKERS);
  //configuration
  csr_software_cfg();

  //msip software interrupt
  msip_cfg();

  // printf("interrupt test complete!\n");
  lock_acquire(&uart_lock);
  printf("Software interrupt test complete!\n");
  lock_release(&uart_lock);

  while (ght_get_initialisation() == 0){
    // Wait for the checkers to be completed 
 	}
  uint64_t Hart_id = 0;
  asm volatile ("csrr %0, mhartid"  : "=r"(Hart_id));
  lock_acquire(&uart_lock);
  printf("[Boom-C%x]: Test is now started: \r\n", Hart_id);
  printf("[MEEK_PERF_CFG] big=%d checker=%d interval=%" PRIu64
         " checker_limit=2000\r\n",
         MEEK_ENABLE_BIG_CORE_PERF, MEEK_ENABLE_CHECKER_SEGMENT_PERF,
         (uint64_t)FPGA_PERF_INTERVAL_CYCLES);
  lock_release(&uart_lock);
#if MEEK_ENABLE_BIG_CORE_PERF
  ghe_fpga_perf_set_interval(FPGA_PERF_INTERVAL_CYCLES);
  ghe_fpga_perf_reset();
#endif

  // uint64_t perf_val_start = 0;
  // ghe_perf_ctrl(0x07<<1);
  // perf_val_start = ghe_perf_read();
  csr_read_s[0] = ghe_csr_perf_read(0);

  ght_set_satp_priv();
  mtimecmp_cfg();
  csr_timer_cfg();
#if MEEK_ENABLE_BIG_CORE_PERF
  ghe_fpga_perf_start();
#endif

  ROCC_INSTRUCTION (1, 0x31); // start monitoring
  ROCC_INSTRUCTION_S (1, 0X01, 0x70); // ISAX_Go
  //===================== Execution =====================//

  uint64_t start_cpu = read_cycles();
  float a = 0.1;
  float b = 0.2;
  float c = 0.3;

  /* Testing RCU */
  float d = (a + b + c) * 1.7 * 3.2;
  
  uint64_t CSR = 0;
  /* Testing CSR Registers */
  asm volatile ("csrr %0, cycle"  : "=r"(CSR));
  asm volatile ("csrr %0, instret"  : "=r"(CSR));
  asm volatile ("csrr %0, mhartid"  : "=r"(Hart_id));
  
  /* Testing Floating Points */
  double e = (c - b + a) * 1.1;
  double f = ((e + d) * (d - b)) / 2.1;
  double g = (c + 1.1)/2;
  double h = (a - 0.05);
  double i = (f + 1.1);
  double j = a + b + c + d + e + f + g + h + i;
  // Test the correctness of the CSR insts

  

  if ((j * Hart_id) == 0) {
    for (int i; i < 3; i++){
      e = i * 1.2 + 3;
      b = j + 1.7;
      a = (e + b) * 2.2;
      asm volatile ("csrr %0, cycle"  : "=r"(CSR));
      asm volatile ("csrr %0, instret"  : "=r"(CSR));
      asm volatile ("csrr %0, mhartid"  : "=r"(Hart_id));
      a = a + CSR;
      __asm__ volatile("ecall");  // 触发环境调用
      if (a > Hart_id) {
      //=================== Post execution ===================//   
      // Testing LD & SD
      __asm__ volatile(
                        "li   t0,   0x81000000;"         // write pointer
                        "li   t1,   0x55552000;"         // data
                        "li   t2,   0x55553000;"
                        "j    .loop_store1;");

      __asm__ volatile(
                        ".loop_store1:"
                        "li   a5,   0x810008FF;"
                        "lr.w a0,   (t0);"            // load reserved word from memory to a0
                        "sc.w a0,   t1,   (t0);"      // attempt to store t1 at t0
                        "sd         t1,   (t0);"
                        "sd         t2,   16(t0);"
                        "sd         t1,   32(t0);"
                        "sd         t2,   64(t0);"
                        "divw       t3,   t1, t2;"
                        "addi t0,   t0,   0x10;"         // write address + 0x10
                        "frflags    a3;"
                        "fsflags    a3;"
                        // === 补充的 CSR 指令实验（仅操作 fflags 和 frm）===
                        // 1. csrrc：原子清除 fflags 的某些位（用 a3 的掩码）
                        "csrrc  a3, fflags, a3;"           // a4 = 原 fflags，fflags &= ~a3
                        
                        // 2. csrrwi：立即数写 frm（设置舍入模式）
                        "csrrwi a3, frm, 0x3;"             // a4 = 原 frm，frm = 0x3（舍入模式：向下舍入）
                        
                        // 3. csrrsi：立即数置位 fflags 的某些位
                        "csrrsi a3, fflags, 0x1F;"         // a4 = 原 fflags，fflags |= 0x1F（置位低5位）
                        
                        // 4. csrrci：立即数清除 fflags 的某些位
                        "csrrci a3, fflags, 0x0F;"         // a4 = 原 fflags，fflags &= ~0x0F（清除低4位）
                        // "ecall;"
                        "blt  t0,   a5,  .loop_store1;");
      __asm__ volatile(
                        "li   t0,   0x81000000;"         // read pointer
                        "j    .loop_load1;");

      __asm__ volatile(
                        ".loop_load1:"
                        "li   a5,   0x810008FF;"
                        "lr.w a0,   (t0);"            // load reserved word from memory to a0
                        "sc.w a0,   t1,   (t0);"      // attempt to store t1 at t0
                        "ld         t1,   (t0);"
                        "ld         t2,   16(t0);"
                        "ld         t1,   32(t0);"
                        "ld         t2,   64(t0);"
                        "mulw       t3,   t1, t2;"
                        "divw       t3,   t1, t2;"
                        "frflags    a3;"
                        "li         a3,   0x55;"
                        "fsflags    a3;"
                        "divu       t2,t2,t1;"
                        "addi t0,   t0,   0x10;"         // write address + 0x10
                        "blt  t0,   a5,  .loop_load1;");

    __asm__ volatile(
                        "li   t0,   0x81000000;"         // read pointer
                        "li   t1,   0x81000100;"
                        "li   t2,   1;"
                        "j    .loop_add1;");

      __asm__ volatile(
                        ".loop_add1:"
                        "li   a5,   0x810008FF;"
                        "amoadd.w.aq t1,   t2, (t0);"    // load reserved word from memory to a0
                        "addi t2,   t2,   0x01;"
                        "addi t0,   t0,   0x10;"         // write address + 0x10
                        "blt  t0,   a5,  .loop_add1;");
      }
    }
  }

  // __asm__ volatile(
  //   "li   t0, 0x81000000\n\t"      // 基地址
  //   // 大跨度非连续访问（跨越多个缓存行）
  //   "ld   t1,  0(t0)\n\t"          // 偏移0
  //   "ld   t2,  512(t0)\n\t"        // 偏移512（跨度大）
  //   "ld   t3,  128(t0)\n\t"        // 偏移128
  //   "ld   t4,  1024(t0)\n\t"       // 偏移1024（新页）
  //   "ld   t6,  768(t0)\n\t"        // 偏移768
  //   // 重复时打乱顺序
  //   "ld   t2,  512(t0)\n\t"        // 重复访问大跨度地址
  //   "ld   t4,  1024(t0)\n\t"       // 跨页访问
  //   "ld   t1,  0(t0)\n\t"          // 不按原顺序访问
  //   "ld   t3,  128(t0)\n\t"        
  //   "ld   t5,  1536(t0)\n\t"       // 新增更大跨度（1536）
  //   "ld   t6,  768(t0)\n\t"
  //   // 新增完全无规律的地址
  //   "ld   t2,  384(t0)\n\t"        // 中等跨度
  //   "ld   t3,  896(t0)"            // 无规律终点
  // );

  // __asm__ volatile(
  //                       "li   t0,   0x81000000;"         // read pointer
  //                       "ld         t1,   (t0);"
  //                       "ld         t2,   16(t0);"
  //                       "ld         t3,   32(t0);"
  //                       "ld         t4,   64(t0);"
  //                       "ld         t5,   128(t0);"
  //                       "ld         t6,   256(t0);"
  //                       "ld         t1,   (t0);"
  //                       "ld         t2,   16(t0);"
  //                       "ld         t3,   32(t0);"
  //                       "ld         t4,   64(t0);"
  //                       "ld         t5,   128(t0);"
  //                       "ld         t6,   256(t0);"
  //                       "ld         t2,   16(t0);"
  //                       "ld         t3,   32(t0);"
  //                       "ld         t4,   64(t0);"
  //                       "ld         t5,   128(t0);"
  //                       "ld         t6,   256(t0);");

  //=================== Post execution ===================//
#if MEEK_ENABLE_BIG_CORE_PERF
  ghe_fpga_perf_stop();
#endif
  ROCC_INSTRUCTION_S (1, 0X02, 0x70); // ISAX_Stop
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  ROCC_INSTRUCTION (1, 0x32); // stop monitoring

  // perfend();

  // printf("total cycle %lu, total commit %lu\n \
  //   csr commit %lu %lu, csrw commit %lu %lu\n \
  //   mstatus %lu %lu, misa %lu %lu\n \
  //   medeleg %lu %lu, mideleg %lu %lu\n \
  //   mie  %lu %lu, mtvec %lu %lu\n \
  //   mcounen %lu %lu, mscratch %lu %lu\n \
  //   mepc %lu %lu, mcause %lu %lu\n \
  //   mtval %lu %lu, mip %lu %lu\n \
  //   mtval2 %lu %lu, menvcfg %lu %lu\n \
  //   mseccfg %lu %lu, pmpcfg0 %lu %lu\n \
  //   pmpaddr0 %lu %lu %lu %lu %lu %lu %lu %lu %lu\n \
  //   mcountinh %lu %lu\n \
  //   mevents %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu\n \
  //   mncause %lu, mnepc %lu, mnscratch %lu, mnstatus %lu\n \
  //   dcsr %lu, dpc %lu, dscratch0 %lu, dscratch1 %lu\n \
  //   tselect %lu, tdata1 %lu, tdata2 %lu, tdata3 %lu, mcontext %lu\n \
  //   fflags %lu %lu, fcsr %lu, frm %lu\n \
  //   sstatus %lu, sie %lu, stvec %lu, sounteren %lu\n \
  //   senvcfg %lu\n \
  //   sscratch %lu, sepc %lu, scause %lu, stval %lu, sip %lu\n \
  //   satp %lu, scontext %lu\n \
  //   ",total_cycle_e, total_commit_e, 
  //   total_csr_e, csr_read_e[0],
  //   csrw_e, csr_read_e[1],
  //   mstatus_e, csr_read_e[2],
  //   misa_e, csr_read_e[3],
  //   medeleg_e, csr_read_e[4],
  //   mideleg_e, csr_read_e[5],
  //   mie_e, csr_read_e[6],
  //   mtvec_e, csr_read_e[7],
  //   mcounen_e, csr_read_e[8],
  //   mscratch_e, csr_read_e[9],
  //   mepc_e, csr_read_e[10],
  //   mcause_e, csr_read_e[11],
  //   mtval_e, csr_read_e[12],
  //   mip_e, csr_read_e[13],
  //   mtval2_e, csr_read_e[14],
  //   menvcfg_e, csr_read_e[15],
  //   mseccfg_e, csr_read_e[16],
  //   pmpcfg0_e, csr_read_e[17],
  //   pmpaddr0_e, csr_read_e[18], csr_read_e[19], csr_read_e[20], csr_read_e[21], csr_read_e[22], csr_read_e[23], csr_read_e[24], csr_read_e[25],
  //   mcountinh_e, csr_read_e[26],
  //   csr_read_e[27], csr_read_e[28], csr_read_e[29], csr_read_e[30], csr_read_e[31], csr_read_e[32], csr_read_e[33], csr_read_e[34], csr_read_e[35], 
  //   csr_read_e[36], csr_read_e[37], csr_read_e[38], csr_read_e[39], csr_read_e[40], csr_read_e[41], csr_read_e[42], csr_read_e[43], csr_read_e[44],
  //   csr_read_e[45], csr_read_e[46], csr_read_e[47], csr_read_e[48], csr_read_e[49], csr_read_e[50], csr_read_e[51], csr_read_e[52], csr_read_e[53],
  //   csr_read_e[54], csr_read_e[55],
  //   csr_read_e[56], csr_read_e[57], csr_read_e[58], csr_read_e[59],
  //   csr_read_e[60], csr_read_e[61], csr_read_e[62], csr_read_e[63],
  //   csr_read_e[64], csr_read_e[65], csr_read_e[66], csr_read_e[67], csr_read_e[68],
  //   fflags_e, csr_read_e[69], csr_read_e[70], csr_read_e[71],
  //   csr_read_e[72], csr_read_e[73], csr_read_e[74], csr_read_e[75],
  //   csr_read_e[76],
  //   csr_read_e[77], csr_read_e[78], csr_read_e[79], csr_read_e[80], csr_read_e[81],
  //   csr_read_e[82], csr_read_e[83]
  // );
  // printf("csr commit %lu %lu, csrw commit %lu %lu\n \
  //   mstatus write %lu %lu, misa %lu %lu\n \
  //   medeleg %lu %lu, mideleg %lu %lu\n \
  //   mie %lu %lu, mtvec %lu %lu\n \
  //   mcounen %lu %lu, mscratch %lu %lu\n \
  //   mepc %lu %lu, mcause %lu %lu\n \
  //   mtval %lu %lu, mip %lu %lu\n \
  //   mtval2 %lu %lu, menvcfg %lu %lu\n \
  //   mseccfg %lu %lu, pmpcfg0 %lu %lu\n \
  //   pmpaddr0 %lu %lu %lu %lu %lu %lu %lu %lu / %lu %lu %lu %lu %lu %lu %lu %lu\n \
  //   mcountinh %lu %lu\n \
  //   mevents %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu\n \
  //   mevents_s %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu\n \
  //   mncause %lu %lu, mnepc %lu %lu, mnscratch %lu %lu, mnstatus %lu %lu\n \
  //   dcsr %lu %lu, dpc %lu %lu, dscratch0 %lu %lu, dscratch1 %lu %lu\n \
  //   tselect %lu %lu, tdata1 %lu %lu, tdata2 %lu %lu, tdata3 %lu %lu, mcontext %lu %lu\n \
  //   fflags %lu %lu, fcsr %lu %lu, frm %lu %lu\n \
  //   sstatus %lu %lu, sie %lu %lu, stvec %lu %lu, sounteren %lu %lu\n \
  //   senvcfg %lu %lu\n \
  //   sscratch %lu %lu, sepc %lu %lu, scause %lu %lu, stval %lu %lu, sip %lu %lu\n \
  //   satp %lu %lu, scontext %lu %lu\n \
  //   ",csr_read_e[0], csr_read_s[0], csr_read_e[1], csr_read_s[1],
  //   csr_read_e[2], csr_read_s[2], csr_read_e[3], csr_read_s[3],
  //   csr_read_e[4], csr_read_s[4], csr_read_e[5], csr_read_s[5],
  //   csr_read_e[6], csr_read_s[6], csr_read_e[7], csr_read_s[7],
  //   csr_read_e[8], csr_read_s[8], csr_read_e[9], csr_read_s[9],
  //   csr_read_e[10], csr_read_s[10], csr_read_e[11], csr_read_s[11],
  //   csr_read_e[12], csr_read_s[12], csr_read_e[13], csr_read_s[13],
  //   csr_read_e[14], csr_read_s[14], csr_read_e[15], csr_read_s[15],
  //   csr_read_e[16], csr_read_s[16], csr_read_e[17], csr_read_s[17],
  //   csr_read_e[18], csr_read_e[19], csr_read_e[20], csr_read_e[21], csr_read_e[22], csr_read_e[23], csr_read_e[24], csr_read_e[25], csr_read_s[18], csr_read_s[19], csr_read_s[20], csr_read_s[21], csr_read_s[22], csr_read_s[23], csr_read_s[24], csr_read_s[25],
  //   csr_read_e[26], csr_read_s[26],
  //   csr_read_e[27], csr_read_e[28], csr_read_e[29], csr_read_e[30], csr_read_e[31], csr_read_e[32], csr_read_e[33], csr_read_e[34], csr_read_e[35], 
  //   csr_read_e[36], csr_read_e[37], csr_read_e[38], csr_read_e[39], csr_read_e[40], csr_read_e[41], csr_read_e[42], csr_read_e[43], csr_read_e[44],
  //   csr_read_e[45], csr_read_e[46], csr_read_e[47], csr_read_e[48], csr_read_e[49], csr_read_e[50], csr_read_e[51], csr_read_e[52], csr_read_e[53],
  //   csr_read_e[54], csr_read_e[55],
  //   csr_read_s[27], csr_read_s[28], csr_read_s[29], csr_read_s[30], csr_read_s[31], csr_read_s[32], csr_read_s[33], csr_read_s[34], csr_read_s[35], 
  //   csr_read_s[36], csr_read_s[37], csr_read_s[38], csr_read_s[39], csr_read_s[40], csr_read_s[41], csr_read_s[42], csr_read_s[43], csr_read_s[44],
  //   csr_read_s[45], csr_read_s[46], csr_read_s[47], csr_read_s[48], csr_read_s[49], csr_read_s[50], csr_read_s[51], csr_read_s[52], csr_read_s[53],
  //   csr_read_s[54], csr_read_s[55],
  //   csr_read_e[56], csr_read_s[56], csr_read_e[57], csr_read_s[57], csr_read_e[58], csr_read_s[58], csr_read_e[59], csr_read_s[59], 
  //   csr_read_e[60], csr_read_s[60], csr_read_e[61], csr_read_s[61], csr_read_e[62], csr_read_s[62], csr_read_e[63], csr_read_s[63], 
  //   csr_read_e[64], csr_read_s[64], csr_read_e[65], csr_read_s[65], csr_read_e[66], csr_read_s[66], csr_read_e[67], csr_read_s[67], csr_read_e[68], csr_read_s[68],
  //   csr_read_e[69], csr_read_s[69], csr_read_e[70], csr_read_s[70], csr_read_e[71], csr_read_s[71], 
  //   csr_read_e[72], csr_read_s[72], csr_read_e[73], csr_read_s[73], csr_read_e[74], csr_read_s[74], csr_read_e[75], csr_read_s[75], 
  //   csr_read_e[76], csr_read_s[76], 
  //   csr_read_e[77], csr_read_s[77], csr_read_e[78], csr_read_s[78], csr_read_e[79], csr_read_s[79], csr_read_e[80], csr_read_s[80], csr_read_e[81], csr_read_s[81], 
  //   csr_read_e[82], csr_read_s[82], csr_read_e[83], csr_read_s[83]
  //   );

  csr_read_e[0] = ghe_csr_perf_read(0);

  uint64_t status;
  while ((status = ght_get_status()) < 0x1FFFF) {

  }

  uint64_t end_cpu = read_cycles();
  


  lock_acquire(&uart_lock);
  printf("CPU execution took %" PRIu64 " cycles\n", end_cpu - start_cpu);
  lock_release(&uart_lock);

#if MEEK_ENABLE_BIG_CORE_PERF
  print_fpga_perf_trace();
#endif

  lock_acquire(&uart_lock);
  printf("Boom-Perf: CSR execution-inst = %" PRIu64 " \r\n",
         csr_read_e[0] - csr_read_s[0]);
  printf("[Boom-C%x]: Test is now completed. \r\n", Hart_id);
  lock_release(&uart_lock);

	ght_unset_satp_priv();
	ROCC_INSTRUCTION (1, 0x30); // reset monitoring
  return 0;
}


/* Core_1 & 2 thread */
int __main(void)
{
  uint64_t Hart_id = 0;
  asm volatile ("csrr %0, mhartid"  : "=r"(Hart_id));
  
  switch (Hart_id){
      case 0x01:
        //configuration
        csr_software_cfg();
      
        //msip software interrupt
        msip_cfg();
        mtimecmp_cfg();
        csr_timer_cfg();
        checker(Hart_id);
      break;

      case 0x02:
        //configuration
        csr_software_cfg();
        
        //msip software interrupt
        msip_cfg();
        mtimecmp_cfg();
        csr_timer_cfg();
        checker(Hart_id);
      break;

      case 0x03:
        //configuration
        csr_software_cfg();
        
        //msip software interrupt
        msip_cfg();
        mtimecmp_cfg();
        csr_timer_cfg();
        checker(Hart_id);
      break;

      case 0x04:
        checker(Hart_id);
      break;

      
      default:
      break;
  }
  
  idle();
  return 0;
}

int r_ini (int num_checkers){
  //================== Initialisation ==================//
  ght_set_numberofcheckers(num_checkers);
  // ght_debug_filter_width(0x00); // Default width
  
  // Insepct load operations 
  // GID: 0x01 
  // Func: 0x00; 0x01; 0x02; 0x03; 0x04; 0x05; 0x06
  // Opcode: 0x03
  // Data path: LDQ - 0x02
  ght_cfg_filter(0x01, 0x00, 0x03, 0x02); // lb
  ght_cfg_filter(0x01, 0x01, 0x03, 0x02); // lh
  ght_cfg_filter(0x01, 0x02, 0x03, 0x02); // lw
  ght_cfg_filter(0x01, 0x04, 0x03, 0x02); // lbu
  ght_cfg_filter(0x01, 0x05, 0x03, 0x02); // lhu
  ght_cfg_filter(0x01, 0x03, 0x03, 0x02); // ld
  ght_cfg_filter(0x01, 0x06, 0x03, 0x02); // lwu
  // Func: 0x02; 0x03; 0x04
  // Opcode: 0x07
  // Data path: LDQ - 0x02
  ght_cfg_filter(0x01, 0x02, 0x07, 0x02); // flw
  ght_cfg_filter(0x01, 0x03, 0x07, 0x02); // fld
  ght_cfg_filter(0x01, 0x04, 0x07, 0x02); // flq
  // C.load operations 
  // GID: 0x01
  // Func: 0x02; 0x03; 0x04; 0x05; 0x06; 0x07
  // MSB: 0
  // Opcode: 0x00
  ght_cfg_filter_rvc(0x01, 0x02, 0x00, 0x00, 0x02); // c.fld, c.lq
  ght_cfg_filter_rvc(0x01, 0x03, 0x00, 0x00, 0x02); // c.fld, c.lq
  ght_cfg_filter_rvc(0x01, 0x04, 0x00, 0x00, 0x02); // c.lw
  ght_cfg_filter_rvc(0x01, 0x05, 0x00, 0x00, 0x02); // c.lw
  ght_cfg_filter_rvc(0x01, 0x06, 0x00, 0x00, 0x02); // c.flw, c.ld
  ght_cfg_filter_rvc(0x01, 0x07, 0x00, 0x00, 0x02); // c.flw, c.ld

  // GID: 0x01
  // Func: 0x02; 0x03; 0x04; 0x05; 0x06; 0x07
  // MSB: 0
  // Opcode: 0x2
  ght_cfg_filter_rvc(0x01, 0x02, 0x02, 0x00, 0x02); 
  ght_cfg_filter_rvc(0x01, 0x03, 0x02, 0x00, 0x02);
  ght_cfg_filter_rvc(0x01, 0x04, 0x02, 0x00, 0x02);
  ght_cfg_filter_rvc(0x01, 0x05, 0x02, 0x00, 0x02);
  ght_cfg_filter_rvc(0x01, 0x06, 0x02, 0x00, 0x02);
  ght_cfg_filter_rvc(0x01, 0x07, 0x02, 0x00, 0x02);

  // Insepct store operations 
  // GID: 0x02
  // Func: 0x00; 0x01; 0x02; 0x03
  // Opcode: 0x23
  // Data path: STQ - 0x03
  ght_cfg_filter(0x02, 0x00, 0x23, 0x03); // sb
  ght_cfg_filter(0x02, 0x01, 0x23, 0x03); // sh
  ght_cfg_filter(0x02, 0x02, 0x23, 0x03); // sw
  ght_cfg_filter(0x02, 0x03, 0x23, 0x03); // sd
  // Func: 0x02; 0x03; 0x04
  // Opcode: 0x27
  // Data path: LDQ - 0x02
  ght_cfg_filter(0x02, 0x02, 0x27, 0x03); // fsw
  ght_cfg_filter(0x02, 0x03, 0x27, 0x03); // fsd
  ght_cfg_filter(0x02, 0x04, 0x27, 0x03); // fsq
  // C.sotre operations 
  // GID: 0x02
  // Func: 0x02; 0x03; 0x04; 0x05; 0x06; 0x07
  // MSB: 1
  // Opcode: 0x00
  ght_cfg_filter_rvc(0x02, 0x02, 0x00, 0x01, 0x03); // c.fsd, c.sq
  ght_cfg_filter_rvc(0x02, 0x03, 0x00, 0x01, 0x03); // c.fsd, c.sq
  ght_cfg_filter_rvc(0x02, 0x04, 0x00, 0x01, 0x03); // c.sw
  ght_cfg_filter_rvc(0x02, 0x05, 0x00, 0x01, 0x03); // c.sw
  ght_cfg_filter_rvc(0x02, 0x06, 0x00, 0x01, 0x03); // c.fsw, c.sd
  ght_cfg_filter_rvc(0x02, 0x07, 0x00, 0x01, 0x03); // c.fsw, c.sd

  // GID: 0x02
  // Func: 0x02; 0x03; 0x04; 0x05; 0x06; 0x07
  // MSB: 1
  // Opcode: 0x2
  ght_cfg_filter_rvc(0x02, 0x02, 0x02, 0x01, 0x03); 
  ght_cfg_filter_rvc(0x02, 0x03, 0x02, 0x01, 0x03);
  ght_cfg_filter_rvc(0x02, 0x04, 0x02, 0x01, 0x03);
  ght_cfg_filter_rvc(0x02, 0x05, 0x02, 0x01, 0x03);
  ght_cfg_filter_rvc(0x02, 0x06, 0x02, 0x01, 0x03);
  ght_cfg_filter_rvc(0x02, 0x07, 0x02, 0x01, 0x03);


  // Insepct CSR read operations
  // GID: 0x01
  // Func: 0x02
  // Opcode: 0x73
  // Data path: PRFs - 0x01
  ght_cfg_filter(0x03, 0x01, 0x73, 0x01);
  ght_cfg_filter(0x03, 0x02, 0x73, 0x01);
  ght_cfg_filter(0x03, 0x03, 0x73, 0x01);
  ght_cfg_filter(0x03, 0x05, 0x73, 0x01);
  ght_cfg_filter(0x03, 0x06, 0x73, 0x01);
  ght_cfg_filter(0x03, 0x07, 0x73, 0x01);
  

  // Insepct atomic operations
  // GID: 0x2F
  // Func: 0x02; 0x03
  // Opcode: 0x2F
  // Data path: STQ + PRFs - 0x00
  ght_cfg_filter(0x01, 0x02, 0x2F, 0x05); // 32-bit
  ght_cfg_filter(0x01, 0x03, 0x2F, 0x05); // 64-bit

  // se: 00, end_id: 0x01, scheduling: rr, start_id: 0x01
  ght_cfg_se(0x00, 0x01, 0x01, 0x01);
  // se: 01, end_id: 0x02, scheduling: rr, start_id: 0x02
  ght_cfg_se(0x01, 0x02, 0x01, 0x02);
  // se: 02, end_id: 0x03, scheduling: rr, start_id: 0x03
  ght_cfg_se(0x02, 0x03, 0x01, 0x03);
  // se: 03, end_id: 0x04, scheduling: rr, start_id: 0x04
  ght_cfg_se(0x03, 0x04, 0x01, 0x04);

  // Map: GIDs for cores
  // r_set_corex_p_s(1);
  // r_set_corex_p_s(2);
  // r_set_corex_p_s(3);
  // r_set_corex_p_s(4);
  for(int i = 1; i <= NUM_CHECKERS; i++){
    r_set_corex_p_s(i);
  }


  // Shared snapshots
  // ght_cfg_mapper (0b00001111, 0b0011);
  // ght_cfg_mapper (0b00010111, 0b0011);

  // ght_cfg_mapper (0b00001111, 0b0011);
  // ght_cfg_mapper (0b00010111, 0b0011);
  // ght_cfg_mapper (0b00011111, 0b0110);
  // ght_cfg_mapper (0b00100111, 0b1100);

  // To do: add RVC commands
  // ...
  //================== Initialisation ==================//
  ght_debug_filter_width(0);

  // Set checker mask: all 4 checkers belong to this big core (mask = 0xF)
  ghe_set_checker_mask(0xF);
  uint64_t rd_mask = ghe_get_checker_mask();
  lock_acquire(&uart_lock);
  printf("R: Checker mask set to 0x%lx\r\n", rd_mask);
  lock_release(&uart_lock);

  lock_acquire(&uart_lock);
  printf("R: Initialisation is completed!\r\n");
  lock_release(&uart_lock);
}
