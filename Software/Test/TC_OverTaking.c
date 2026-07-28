#include <stdio.h>
#include <stdlib.h>
#include "rocc.h"
#include "spin_lock.h"
#include "ght.h"
#include "ghe.h"
#include "tasks.h"
#include "marchid.h"
#include <inttypes.h>
#include <riscv-pk/encoding.h>

#define NUM_CHECKERS 4
int uart_lock;
size_t total_cycle_s;  
size_t total_commit_s; 
size_t total_issue_s;  
size_t Fetch_Bubble_s; 
size_t Load_commit_s;  
size_t Store_commit_s;  
size_t fp_commit_s;      
size_t br_commit_s;
size_t jal_commit_s;         
size_t jalr_commit_s;     
size_t int_commit_s;
size_t csr_commit_s;
size_t csrw_commit_s;

size_t total_mispred_s;
size_t br_mispred_s;
size_t flush_s;        
size_t icache_miss_s;
size_t dcache_miss_s;

size_t total_cycle_e;  
size_t total_commit_e; 
size_t total_issue_e;  
size_t Fetch_Bubble_e; 
size_t Load_commit_e;  
size_t Store_commit_e;  
size_t fp_commit_e;      
size_t br_commit_e;
size_t jal_commit_e;         
size_t jalr_commit_e;     
size_t int_commit_e;
size_t csr_commit_e;
size_t csrw_commit_e;

size_t total_mispred_e;
size_t br_mispred_e;
size_t flush_e;        
size_t icache_miss_e;
size_t dcache_miss_e;

size_t retire;         
size_t fetch_bound;    
size_t bad_speculation;
size_t backend_bound;  

void perfstart(){
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

  write_csr(mhpmevent15,0x0101);
  write_csr(mhpmevent16,0x0201);
  write_csr(mhpmevent17,0x0401);

  write_csr(mhpmevent18,0x0102);
  write_csr(mhpmevent19,0x0202);

  total_cycle_s   = read_csr(mcycle);
  total_commit_s  = read_csr(mhpmcounter3);
  total_issue_s   = read_csr(mhpmcounter4);
  Fetch_Bubble_s  = read_csr(mhpmcounter5);
  Load_commit_s   = read_csr(mhpmcounter6); 
  Store_commit_s  = read_csr(mhpmcounter7); 
  fp_commit_s     = read_csr(mhpmcounter8); 
  br_commit_s     = read_csr(mhpmcounter9); 
  jal_commit_s    = read_csr(mhpmcounter10);
  jalr_commit_s   = read_csr(mhpmcounter11);
  int_commit_s    = read_csr(mhpmcounter12);
  csr_commit_s    = read_csr(mhpmcounter13);
  csrw_commit_s   = read_csr(mhpmcounter14);
 
  total_mispred_s = read_csr(mhpmcounter15);
  br_mispred_s    = read_csr(mhpmcounter16);
  flush_s         = read_csr(mhpmcounter17);
  icache_miss_s   = read_csr(mhpmcounter18);
  dcache_miss_s   = read_csr(mhpmcounter19);
  printf("Perf Test begin \n");
}

void perfend(){
  total_cycle_e   = read_csr(mcycle) - total_cycle_s;
  total_commit_e  = read_csr(mhpmcounter3)  - total_commit_s  ;
  total_issue_e   = read_csr(mhpmcounter4)  - total_issue_s   ;
  Fetch_Bubble_e  = read_csr(mhpmcounter5)  - Fetch_Bubble_s  ;
  Load_commit_e   = read_csr(mhpmcounter6)  - Load_commit_s   ; 
  Store_commit_e  = read_csr(mhpmcounter7)  - Store_commit_s  ; 
  fp_commit_e     = read_csr(mhpmcounter8)  - fp_commit_s     ;   
  br_commit_e     = read_csr(mhpmcounter9)  - br_commit_s     ; 
  jal_commit_e    = read_csr(mhpmcounter10) - jal_commit_s    ;         
  jalr_commit_e   = read_csr(mhpmcounter11) - jalr_commit_s   ;     
  int_commit_e    = read_csr(mhpmcounter12) - int_commit_s    ; 
  csr_commit_e    = read_csr(mhpmcounter13) - csr_commit_s    ;
  csrw_commit_e   = read_csr(mhpmcounter14) - csrw_commit_s    ;
  
  total_mispred_e = read_csr(mhpmcounter15) - total_mispred_s ;
  br_mispred_e    = read_csr(mhpmcounter16) - br_mispred_s    ;
  flush_e         = read_csr(mhpmcounter17) - flush_s ;
  
  icache_miss_e   = read_csr(mhpmcounter18) - icache_miss_s   ;
  dcache_miss_e   = read_csr(mhpmcounter19) - dcache_miss_s   ;

  retire          = (total_commit_e*100)/(total_cycle_e*3);
  fetch_bound     = (Fetch_Bubble_e*100)/(total_cycle_e*3);
  bad_speculation = (100*((total_issue_e-total_commit_e)+30*(total_mispred_e+flush_e)))/(total_cycle_e*3);
  backend_bound   = 100-retire-fetch_bound-bad_speculation;
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

  while (ght_get_initialisation() == 0){
    // Wait for the checkers to be completed 
 	}
  uint64_t Hart_id = 0;
  asm volatile ("csrr %0, mhartid"  : "=r"(Hart_id));
  printf("[Boom-C%x]: Test is now started: \r\n", Hart_id);
  ghe_perf_ctrl(0x01);
  ghe_perf_ctrl(0x00); 

  ght_set_satp_priv();
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
                        "addi a3,   a3,   0x21;"
                        "fsflags    a3;"
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

  //=================== Post execution ===================//
  ROCC_INSTRUCTION (1, 0x32); // stop monitoring
  ROCC_INSTRUCTION_S (1, 0X02, 0x70); // ISAX_Stop
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");

  // perfend();

  // printf("total cycle %lu\n \
  //   total commit %lu\n \
  //   total_issue %lu\n \
  //   Fetch_Bubble %lu\n \
  //   Load_commit %lu \n \
  //   Store_commit %lu \n \
  //   fp_commit   %lu \n \
  //   br_commit %lu \n \
  //   jal_commit  %lu \n \
  //   jalr_commit %lu \n \
  //   int_commit %lu \n \
  //   csr_commit %lu \n \
  //   csrw_commit %lu \n \
  //   total_mispred %lu \n \
  //   br_mispred %lu \n \
  //   flsuh %lu \n \
  //   icache_miss %lu \n \
  //   dcache_miss %lu\n \
  //   ",total_cycle_e,
  //   total_commit_e ,
  //   total_issue_e  ,
  //   Fetch_Bubble_e ,
  //   Load_commit_e  ,
  //   Store_commit_e ,
  //   fp_commit_e    ,
  //   br_commit_e    ,
  //   jal_commit_e   ,
  //   jalr_commit_e  ,
  //   int_commit_e   ,
  //   csr_commit_e   ,
  //   csrw_commit_e  ,
  //   total_mispred_e,
  //   br_mispred_e   ,
  //   flush_e,
  //   icache_miss_e  ,
  //   dcache_miss_e  );
  // //top down level 1
  // printf("retire %lu front bound %lu bad speculation: %lu backend bound %lu\n",retire,fetch_bound,bad_speculation,backend_bound);

  uint64_t status;
  while ((status = ght_get_status()) < 0x1FFFF) {

  }

  uint64_t end_cpu = read_cycles();
  uint64_t perf_val = 0;
  ghe_perf_ctrl(0x07<<1);
  perf_val = ghe_perf_read();
  printf("CPU execution took %" PRIu64 "cycles\n", end_cpu - start_cpu);
  // printf("CPU conv end at %" PRIu64 " cycle\n", end_cpu);

  
  printf("Boom-Perf: Execution-time = %d \r\n", perf_val);

  ghe_perf_ctrl(0x01<<1);
  perf_val = ghe_perf_read();
  printf("Boom-Perf: Sch-bloc-time = %d \r\n", perf_val);
  
  printf("[Boom-C%x]: Test is now completed. \r\n", Hart_id);
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
        checker(Hart_id);
      break;

      case 0x02:
        checker(Hart_id);
      break;

      case 0x03:
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
  ght_cfg_filter(0x03, 0x02, 0x73, 0x01);
  ght_cfg_filter(0x03, 0x01, 0x73, 0x01);

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
  ght_debug_filter_width(1);
  lock_acquire(&uart_lock);
  printf("R: Initialisation is completed!\r\n");
  lock_release(&uart_lock);
}