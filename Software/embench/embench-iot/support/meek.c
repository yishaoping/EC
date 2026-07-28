#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#define NUM_CHECKERS 4
#ifndef FPGA_PERF_INTERVAL_CYCLES
#define FPGA_PERF_INTERVAL_CYCLES 5000ULL
#endif
#include "meek.h"
#include <riscv-pk/encoding.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "rocc.h"
#include "spin_lock.h"
#include "ght.h"
#include "ghe.h"
#include "tasks.h"

/* ================================================================
   Timer / Interrupt definitions (from TC_OverTaking_csr)
   ================================================================ */
#define U32               *(volatile unsigned int *)
#define timer_limitation  50
#define timer_cmp         0x20

#define CLINT_BASE        0x2000000
#define MSIP_OFFSET(h)    (h * 4)
#define TIMECMP_OFFSET(h) (0x4000 + h * 8)
#define MTIME_ADDR        (CLINT_BASE + 0xBFF8)

volatile int timer_flags[4] = {0};
int uart_lock = 0;

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

/* ---- mtime read ---- */
static uint64_t get_mtime(void)
{
  volatile uint32_t *mtime_low  = (uint32_t *)MTIME_ADDR;
  volatile uint32_t *mtime_high = (uint32_t *)(MTIME_ADDR + 4);
  uint32_t hi, lo;
  do {
    hi = *mtime_high;
    lo = *mtime_low;
  } while (hi != *mtime_high);
  return ((uint64_t)hi << 32) | lo;
}

/* ---- Software interrupt ---- */
static void msip_cfg(void)
{
  uint64_t hart_id;
  asm volatile("csrr %0, mhartid" : "=r"(hart_id));
  volatile uint32_t *msip = (uint32_t *)(CLINT_BASE + MSIP_OFFSET(hart_id));
  *msip = 0x1;
}

/* ---- Timer interrupt ---- */
static void mtimecmp_cfg(void)
{
  uint64_t hart_id;
  asm volatile("csrr %0, mhartid" : "=r"(hart_id));
  volatile uint32_t *mtimecmp_low  = (uint32_t *)(CLINT_BASE + TIMECMP_OFFSET(hart_id));
  volatile uint32_t *mtimecmp_high = (uint32_t *)(CLINT_BASE + TIMECMP_OFFSET(hart_id) + 4);
  uint64_t cmp_val = get_mtime() + timer_cmp;
  *mtimecmp_low  = (uint32_t)cmp_val;
  *mtimecmp_high = (uint32_t)(cmp_val >> 32);
}

/* ---- CSR timer enable ---- */
static void csr_timer_cfg(void)
{
  unsigned int csr_tmp = read_csr(mie);
  write_csr(mie, csr_tmp | 0x80);        // set MTIE
}

/* ---- CSR software interrupt enable ---- */
static void csr_software_cfg(void)
{
  unsigned int csr_tmp;
  csr_tmp = read_csr(mie);
  write_csr(mie, csr_tmp | 0x8);         // set MSIE
  csr_tmp = read_csr(mstatus);
  write_csr(mstatus, csr_tmp | 0x8);    // set MIE
}

/* ---- Unified trap handler (timer + software + ecall) ---- */
uintptr_t handle_trap(uintptr_t epc, uintptr_t cause, uintptr_t tval,
                      uintptr_t regs[32])
{
  (void)tval;
  (void)regs;

  uint64_t hart_id;
  asm volatile("csrr %0, mhartid" : "=r"(hart_id));

  uint64_t interrupt  = cause >> 63;
  uint64_t cause_code = cause & 0x7FFFFFFFFFFFFFFFULL;

  if (interrupt) {
    // Software interrupt
    if ((read_csr(mip) & 0x8) != 0) {
      volatile uint32_t *msip = (uint32_t *)(CLINT_BASE + MSIP_OFFSET(hart_id));
      *msip = 0x0;
    }
    // Timer interrupt
    else if ((read_csr(mip) & 0x80) != 0) {
      if (hart_id == 0) {
        timer_flags[0] += 1;
        if (timer_flags[0] < timer_limitation) {
          volatile uint32_t *mtimecmp = (uint32_t *)(CLINT_BASE + TIMECMP_OFFSET(hart_id));
          uint64_t new_cmp = get_mtime() + timer_cmp;
          *(uint64_t *)mtimecmp = new_cmp;
        } else if (timer_flags[0] >= timer_limitation) {
          unsigned int mie_val = read_csr(mie);
          write_csr(mie, mie_val & ~0x80);
          unsigned int mstatus_val = read_csr(mstatus);
          write_csr(mstatus, mstatus_val & ~0x8);
        }
      }
      else if (hart_id == 1) {
        timer_flags[1] += 1;
        if (timer_flags[1] < timer_limitation) {
          volatile uint32_t *mtimecmp = (uint32_t *)(CLINT_BASE + TIMECMP_OFFSET(hart_id));
          uint64_t new_cmp = get_mtime() + timer_cmp;
          *(uint64_t *)mtimecmp = new_cmp;
        } else if (timer_flags[1] >= timer_limitation) {
          unsigned int mie_val = read_csr(mie);
          write_csr(mie, mie_val & ~0x80);
          unsigned int mstatus_val = read_csr(mstatus);
          write_csr(mstatus, mstatus_val & ~0x8);
        }
      }
      else if (hart_id == 2) {
        timer_flags[2] += 1;
        if (timer_flags[2] < timer_limitation) {
          volatile uint32_t *mtimecmp = (uint32_t *)(CLINT_BASE + TIMECMP_OFFSET(hart_id));
          uint64_t new_cmp = get_mtime() + timer_cmp;
          *(uint64_t *)mtimecmp = new_cmp;
        } else if (timer_flags[2] >= timer_limitation) {
          unsigned int mie_val = read_csr(mie);
          write_csr(mie, mie_val & ~0x80);
          unsigned int mstatus_val = read_csr(mstatus);
          write_csr(mstatus, mstatus_val & ~0x8);
        }
      }
      else if (hart_id == 3) {
        timer_flags[3] += 1;
        if (timer_flags[3] < timer_limitation) {
          volatile uint32_t *mtimecmp = (uint32_t *)(CLINT_BASE + TIMECMP_OFFSET(hart_id));
          uint64_t new_cmp = get_mtime() + timer_cmp;
          *(uint64_t *)mtimecmp = new_cmp;
        } else if (timer_flags[3] >= timer_limitation) {
          unsigned int mie_val = read_csr(mie);
          write_csr(mie, mie_val & ~0x80);
          unsigned int mstatus_val = read_csr(mstatus);
          write_csr(mstatus, mstatus_val & ~0x8);
        }
      }
    }
  } else {
    if (cause_code == 11) {
      epc += 4;
    }
  }

  return epc;
}

/* ================================================================
   rStartup() — 大核 (hart 0) 初始化
   ================================================================ */
void rStartup(void)
{
  // 1. Filter 初始化：与 TC_OverTaking_csr 的 r_ini 保持一致
  ght_set_numberofcheckers(NUM_CHECKERS);

  // Load
  ght_cfg_filter(0x01, 0x00, 0x03, 0x02);
  ght_cfg_filter(0x01, 0x01, 0x03, 0x02);
  ght_cfg_filter(0x01, 0x02, 0x03, 0x02);
  ght_cfg_filter(0x01, 0x03, 0x03, 0x02);
  ght_cfg_filter(0x01, 0x04, 0x03, 0x02);
  ght_cfg_filter(0x01, 0x05, 0x03, 0x02);
  ght_cfg_filter(0x01, 0x06, 0x03, 0x02);
  // FP load
  ght_cfg_filter(0x01, 0x02, 0x07, 0x02);
  ght_cfg_filter(0x01, 0x03, 0x07, 0x02);
  ght_cfg_filter(0x01, 0x04, 0x07, 0x02);
  // Compressed load
  for (int funct = 0x02; funct <= 0x07; funct++) {
    ght_cfg_filter_rvc(0x01, funct, 0x00, 0x00, 0x02);
  }
  for (int funct = 0x02; funct <= 0x07; funct++) {
    ght_cfg_filter_rvc(0x01, funct, 0x02, 0x00, 0x02);
  }

  // Store
  ght_cfg_filter(0x02, 0x00, 0x23, 0x03);
  ght_cfg_filter(0x02, 0x01, 0x23, 0x03);
  ght_cfg_filter(0x02, 0x02, 0x23, 0x03);
  ght_cfg_filter(0x02, 0x03, 0x23, 0x03);
  // FP store
  ght_cfg_filter(0x02, 0x02, 0x27, 0x03);
  ght_cfg_filter(0x02, 0x03, 0x27, 0x03);
  ght_cfg_filter(0x02, 0x04, 0x27, 0x03);
  // Compressed store
  for (int funct = 0x02; funct <= 0x07; funct++) {
    ght_cfg_filter_rvc(0x02, funct, 0x00, 0x01, 0x03);
  }
  for (int funct = 0x02; funct <= 0x07; funct++) {
    ght_cfg_filter_rvc(0x02, funct, 0x02, 0x01, 0x03);
  }

  // CSR read
  ght_cfg_filter(0x03, 0x01, 0x73, 0x01);
  ght_cfg_filter(0x03, 0x02, 0x73, 0x01);
  ght_cfg_filter(0x03, 0x03, 0x73, 0x01);
  ght_cfg_filter(0x03, 0x05, 0x73, 0x01);
  ght_cfg_filter(0x03, 0x06, 0x73, 0x01);
  ght_cfg_filter(0x03, 0x07, 0x73, 0x01);

  // Atomic
  ght_cfg_filter(0x01, 0x02, 0x2F, 0x05);
  ght_cfg_filter(0x01, 0x03, 0x2F, 0x05);

  // SE 分配
  ght_cfg_se(0x00, 0x01, 0x01, 0x01);
  ght_cfg_se(0x01, 0x02, 0x01, 0x02);
  ght_cfg_se(0x02, 0x03, 0x01, 0x03);
  ght_cfg_se(0x03, 0x04, 0x01, 0x04);

  // 每个 checker 映射到对应 SE
  for (int i = 1; i <= NUM_CHECKERS; i++) {
    r_set_corex_p_s(i);
  }

  ght_debug_filter_width(0);

  // 2. Checker mask：全部归属此大核
  ghe_set_checker_mask(0xF);
  uint64_t rd_mask = ghe_get_checker_mask();
  lock_acquire(&uart_lock);
  printf("R: Checker mask set to 0x%lx\r\n", rd_mask);
  lock_release(&uart_lock);

  // Match TC_OverTaking_csr: exercise and enable the BOOM interrupt path.
  csr_software_cfg();
  msip_cfg();

  // 3. 等待所有 checker 就绪
  while (ght_get_initialisation() == 0) {}

  // 4. SATP 特权
  ght_set_satp_priv();

  // 5. 复位 perf
#if MEEK_ENABLE_BIG_CORE_PERF
  ghe_fpga_perf_set_interval(FPGA_PERF_INTERVAL_CYCLES);
  ghe_fpga_perf_reset();
#endif

  mtimecmp_cfg();
  csr_timer_cfg();

#if MEEK_ENABLE_BIG_CORE_PERF
  ghe_fpga_perf_start();
#endif
  // 6. 启动监控 + ISAX
  ROCC_INSTRUCTION(1, 0x31);
  ROCC_INSTRUCTION_S(1, 0x01, 0x70);

  lock_acquire(&uart_lock);
  printf("[MEEK_PERF_CFG] big=%d checker=%d interval=%" PRIu64
         " checker_limit=2000\r\n",
         MEEK_ENABLE_BIG_CORE_PERF, MEEK_ENABLE_CHECKER_SEGMENT_PERF,
         (uint64_t)FPGA_PERF_INTERVAL_CYCLES);
  printf("[Boom]: MEEK started, running benchmark...\r\n");
  lock_release(&uart_lock);
}

/* ================================================================
   rCleanup() — 大核 (hart 0) 清理
   ================================================================ */
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
  printf("[Boom]: Benchmark complete.\r\n");
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

void rCleanup(void)
{
#if MEEK_ENABLE_BIG_CORE_PERF
  ghe_fpga_perf_stop();
#endif
  ROCC_INSTRUCTION_S(1, 0x02, 0x70);

  for (int i = 0; i < 26; i++) {
    __asm__ volatile("nop");
  }

  ROCC_INSTRUCTION(1, 0x32);

  uint64_t status;
  while ((status = ght_get_status()) < 0x1FFFF) {}

#if MEEK_ENABLE_BIG_CORE_PERF
  print_fpga_perf_trace();
#endif

  ght_unset_satp_priv();
  ROCC_INSTRUCTION(1, 0x30);
}

/* ================================================================
   __main() — 小核 (hart 1-4) 入口
   ================================================================ */
int __main(void)
{
  uint64_t Hart_id = 0;
  asm volatile("csrr %0, mhartid" : "=r"(Hart_id));

  switch (Hart_id) {
    case 0x01:
      csr_software_cfg();
      msip_cfg();
      mtimecmp_cfg();
      csr_timer_cfg();
      checker(Hart_id);
      break;

    case 0x02:
      csr_software_cfg();
      msip_cfg();
      mtimecmp_cfg();
      csr_timer_cfg();
      checker(Hart_id);
      break;

    case 0x03:
      csr_software_cfg();
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
