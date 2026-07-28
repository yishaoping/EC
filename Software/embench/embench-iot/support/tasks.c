#include <stdio.h>
#include <stdlib.h>
#include "rocc.h"
#include "spin_lock.h"
#include "ght.h"
#include "ghe.h"
#include <inttypes.h>
#include "tasks.h"


int checker (int hart_id)
{
  (void)hart_id;

  //================== Initialisation ==================//
  ghe_asR();
  ght_set_satp_priv();
  ghe_go();
  ghe_initailised(1);

#if MEEK_ENABLE_CHECKER_SEGMENT_PERF
  ghe_fpga_perf_set_interval(FPGA_PERF_INTERVAL_CYCLES);
  ghe_fpga_perf_reset();
  ghe_fpga_perf_start();
#endif

  //===================== Execution =====================//
  ROCC_INSTRUCTION (1, 0x75); // Record context
  ROCC_INSTRUCTION (1, 0x73); // Store context from main core
  ROCC_INSTRUCTION (1, 0x64); // Record PC
  // for (int sel_elu = 0; sel_elu < 2; sel_elu ++){
  //   ROCC_INSTRUCTION_S (1, sel_elu, 0x65);

  //   while (elu_checkstatus() != 0){
  //     printf("C%x: Error detected for ELU %x.\r\n", hart_id, sel_elu);
  //     ROCC_INSTRUCTION_S (1, sel_elu, 0x63);
  //   }
  // }
  
  while (ghe_checkght_status() != 0x02){
    if ((ghe_rsur_status() & 0x18) == 0x08){
      ROCC_INSTRUCTION (1, 0x60);
      R_INSTRUCTION_JLR (3, 0x00);
    }
  }

#if MEEK_ENABLE_CHECKER_SEGMENT_PERF
  ghe_fpga_perf_stop();
#endif

  ROCC_INSTRUCTION (1, 0x72); // Store context from checker core
  ROCC_INSTRUCTION (1, 0x60);

  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");
  __asm__ volatile("nop");



  if(0){
    uint64_t perf_val = 0;
    ghe_perf_ctrl(0x07<<1);
    perf_val = ghe_perf_read();
    printf("Perf: N.CP = %" PRIu64 " \r\n", perf_val);

    ghe_perf_ctrl(0x01<<1);
    perf_val = ghe_perf_read();
    printf("Perf: N.Checking = %" PRIu64 " \r\n", perf_val);

    ghe_perf_ctrl(0x02<<1);
    perf_val = ghe_perf_read();
    printf("Perf: N.PostChecking = %" PRIu64 " \r\n", perf_val);

    ghe_perf_ctrl(0x03<<1);
    perf_val = ghe_perf_read();
    printf("Perf: N.OtherThread = %" PRIu64 " \r\n", perf_val);

    ghe_perf_ctrl(0x04<<1);
    perf_val = ghe_perf_read();
    printf("Perf: N.NonChecking = %" PRIu64 " \r\n", perf_val);
  }


  
  while (ghe_checkght_status() != 0x02){
  }

  ghe_release();
  ght_unset_satp_priv();

  // uint64_t raw_read = ghe_raw_perf_read();
  // lock_acquire(&uart_lock);
  // printf("core %d stalld %" PRIu64 " cycles by RAW\n", hart_id, raw_read);
  // lock_release(&uart_lock);


  while(1){

  }

  return 0;
}


uint64_t task_synthetic_malloc (uint64_t base)
{
  int *ptr = NULL;
  int ptr_size = 32;
  int sum = 0;

  ptr = (int*) malloc(ptr_size * sizeof(int));

  // if memory cannot be allocated
  if(ptr == NULL) {
    printf("Error! memory not allocated. \r\n");
    exit(0);
  }

  for (int i = 0; i < ptr_size; i++)
  {
    *(ptr + i) = base + i;
  }

  for (int i = 0; i < ptr_size; i++)
  {
    sum = sum + *(ptr+i);
  }

  free(ptr);

  return sum;
}
