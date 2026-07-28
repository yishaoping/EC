#ifndef TEST_GHE_H
#define TEST_GHE_H

#include <stdint.h>

#include "rocc.h"

#define GHE_FULL 0x02
#define GHE_EMPTY 0x01


static inline uint64_t ghe_status ()
{
  uint64_t status;
  ROCC_INSTRUCTION_D (1, status, 0x00);
  return status; 
  // 0b01: empty; 
  // 0b10: full;
  // 0b00: data buffered;
  // 0b11: error
}

static inline void ghe_asR(void)
{
  ROCC_INSTRUCTION_S (1, 0x01, 0x01);
}



static inline uint64_t ghe_top_func_opcode ()
{
  uint64_t packet = 0x00;
  if (ghe_status() != 0x01) {
    ROCC_INSTRUCTION_D (1, packet, 0x0A);
  }
  return packet;
}

static inline uint64_t ghe_pop_func_opcode ()
{
  uint64_t packet = 0x00;
  if (ghe_status() != 0x01) {
    ROCC_INSTRUCTION_D (1, packet, 0x0B);
  }
  return packet;
}


static inline uint64_t ghe_top_data ()
{
  uint64_t packet = 0x00;
  if (ghe_status() != 0x01) {
    ROCC_INSTRUCTION_D (1, packet, 0x0C);
  }
  return packet;
}


static inline uint64_t ghe_pop_data ()
{
  uint64_t packet = 0x00;
  if (ghe_status() != 0x01) {
    ROCC_INSTRUCTION_D (1, packet, 0x0D);
  }
  return packet;
}


static inline uint64_t ghe_checkght_status ()
{
  uint64_t status;
  ROCC_INSTRUCTION_D (1, status, 0x07);
  return status; 
}


static inline void ghe_complete ()
{
  // uint64_t get_status = 0;
  // uint64_t set_status = 0x01;
  ROCC_INSTRUCTION (1, 0x41);
}

static inline void ghe_release ()
{
  // uint64_t get_status = 0;
  // uint64_t set_status = 0xFF;
  ROCC_INSTRUCTION (1, 0x43);
}

static inline void ghe_go ()
{
  // uint64_t get_status = 0;
  // uint64_t set_status = 0;
  ROCC_INSTRUCTION (1, 0x40);
}

static inline uint64_t ghe_agg_status ()
{
  uint64_t status;
  ROCC_INSTRUCTION_D (1, status, 0x10);
  return status;
  // 0b01: empty; 
  // 0b10: full;
  // 0b00: data buffered;
  // 0b11: error
}

static inline void ghe_agg_push (uint64_t header, uint64_t payload)
{
  ROCC_INSTRUCTION_SS (1, header, payload, 0x11);
}

static inline uint64_t ghe_sch_status ()
{
  uint64_t status;
  ROCC_INSTRUCTION_D (1, status, 0x20);
  return status; 
  // 0b01: empty; 
  // 0b10: full;
  // 0b00: data buffered;
  // 0b11: error
}

static inline void ghe_initailised (uint64_t if_initailised)
{
  if (if_initailised == 0){
    ROCC_INSTRUCTION (1, 0x50);
  }

  if (if_initailised == 1){
    ROCC_INSTRUCTION (1, 0x51);
  }
}

static inline uint64_t ghe_get_bufferdepth ()
{
  uint64_t depth;
  ROCC_INSTRUCTION_D (1, depth, 0x25);
  return depth;
}

/* RSU Features */
static inline uint64_t ghe_rsur_status ()
{
  uint64_t status;
  ROCC_INSTRUCTION_D (1, status, 0x61);
  return status;
	  // 0b00: idle
    // 0b01: snapshot received 
    // 0b11: snapshot and results recieved
    // 0b10: wrong status
}

static inline uint64_t elu_checkstatus ()
{
  uint64_t status;
  ROCC_INSTRUCTION_D (1, status, 0x66);
  return status; 
}


/*
 * Hardware performance ABI implemented by GHE.scala:
 *   funct 0x76: bit 0 resets all local debug counters; bits 4:1 select one.
 *   funct 0x77: returns the currently selected 64-bit counter.
 *
 * Counters run continuously whenever reset is deasserted.  The hardware has
 * no start, stop, sampling interval, trace buffer, or record-advance command.
 */
#define GHE_PERF_CTRL_RESET          UINT64_C(0x01)
#define GHE_PERF_SELECTOR_SHIFT      1U

/* BOOM R_IC counter selectors.  Selector 0 is not implemented. */
#define GHE_BIG_PERF_SCHED_BLOCKED   1U
#define GHE_BIG_PERF_SCHED_CYCLES    2U
#define GHE_BIG_PERF_CHECK_CYCLES    3U
#define GHE_BIG_PERF_OTHER_THREAD    4U
#define GHE_BIG_PERF_ALL_BUSY        5U
#define GHE_BIG_PERF_SCHED_OTHER     6U
#define GHE_BIG_PERF_ELAPSED_CYCLES  7U

/* Rocket R_ICSL selectors whose counters are active in the current RTL. */
#define GHE_CHECKER_PERF_CHECKING       1U
#define GHE_CHECKER_PERF_POSTCHECKING   2U
#define GHE_CHECKER_PERF_OTHER_THREAD   3U
#define GHE_CHECKER_PERF_NONCHECKING    4U
#define GHE_CHECKER_PERF_CHECKPOINTS    7U
#define GHE_CHECKER_PERF_CPS_TRANSFER  10U
#define GHE_CHECKER_PERF_WORST_LATENCY 11U
#define GHE_CHECKER_PERF_STORES        12U
#define GHE_CHECKER_PERF_LOADS         13U

static inline void ghe_perf_ctrl(uint64_t control)
{
  ROCC_INSTRUCTION_S(1, control, 0x76);
}

/** Pulse the hardware reset bit, then immediately allow counters to run. */
static inline void ghe_perf_reset(void)
{
  ghe_perf_ctrl(GHE_PERF_CTRL_RESET);
  ghe_perf_ctrl(0);
}

static inline uint64_t ghe_perf_read(void)
{
  uint64_t value;
  ROCC_INSTRUCTION_D(1, value, 0x77);
  return value;
}

/** Select and read one cumulative counter from the current hart. */
static inline uint64_t ghe_perf_read_selected(uint64_t selector)
{
  ghe_perf_ctrl(selector << GHE_PERF_SELECTOR_SHIFT);
  return ghe_perf_read();
}

static inline uint64_t ghe_csr_perf_read(int csr_index)
{
  uint64_t perf_val;
  ROCC_INSTRUCTION_DS (1, perf_val, csr_index, 0x55);
  return perf_val;
}

static inline uint64_t ghe_raw_perf_read(void)
{
  uint64_t perf_val;
  ROCC_INSTRUCTION_D (1, perf_val, 0x78);
  return perf_val;
}

/*
 * funct 0x79 reads the 128-bit store statistics implemented by GHE.scala.
 * The selector is supplied in rs1; each call returns one 64-bit word.
 */
#define GHE_STORE_COUNT_LO_SELECTOR       0U
#define GHE_STORE_COUNT_HI_SELECTOR       1U
#define GHE_STORE_CYCLE_SUM_LO_SELECTOR   2U
#define GHE_STORE_CYCLE_SUM_HI_SELECTOR   3U

static inline uint64_t ghe_store_counter_read(uint64_t selector)
{
  uint64_t value;
  ROCC_INSTRUCTION_DS(1, value, selector, 0x79);
  return value;
}

#endif /* TEST_GHE_H */
