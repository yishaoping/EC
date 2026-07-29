#include <stdint.h>

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

static inline uint64_t ghe_asR ()
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


static inline void ghe_perf_ctrl (uint64_t ctrl_code)
{
  ROCC_INSTRUCTION_S (1,ctrl_code, 0x76);
}

#define GHE_FPGA_PERF_CTRL_RESET (1ULL << 0)
#define GHE_FPGA_PERF_CTRL_START (1ULL << 5)
#define GHE_FPGA_PERF_CTRL_STOP  (1ULL << 6)

static inline void ghe_fpga_perf_command (uint64_t command)
{
  ghe_perf_ctrl(command);
  ghe_perf_ctrl(0);
}

static inline void ghe_fpga_perf_reset (void)
{
  ghe_fpga_perf_command(GHE_FPGA_PERF_CTRL_RESET);
}

static inline void ghe_fpga_perf_start (void)
{
  ghe_fpga_perf_command(GHE_FPGA_PERF_CTRL_START);
}

static inline void ghe_fpga_perf_stop (void)
{
  ghe_fpga_perf_command(GHE_FPGA_PERF_CTRL_STOP);
}


static inline uint64_t ghe_perf_read ()
{
  uint64_t perf_val;
  ROCC_INSTRUCTION_D (1, perf_val, 0x77);
  return perf_val;
}

#define GHE_FPGA_PERF_SEL_SAMPLE_COUNT  0
#define GHE_FPGA_PERF_SEL_STATUS        1
#define GHE_FPGA_PERF_SEL_DATA_LO       2
#define GHE_FPGA_PERF_SEL_DATA_HI       3
#define GHE_FPGA_PERF_SEL_ADVANCE       4
#define GHE_FPGA_PERF_SEL_TOTAL_CYCLES  5
#define GHE_FPGA_PERF_SEL_TOTAL_ALLBUSY 6
#define GHE_FPGA_PERF_SEL_TOTAL_RSU     7
#define GHE_FPGA_PERF_SEL_TOTAL_GH      8
#define GHE_FPGA_PERF_SEL_TOTAL_BCOUNT  9

static inline void ghe_fpga_perf_select (uint64_t selector)
{
  ghe_perf_ctrl(selector << 1);
  __asm__ volatile("nop; nop; nop; nop" ::: "memory");
}

static inline uint64_t ghe_fpga_perf_read_sel (uint64_t selector)
{
  ghe_fpga_perf_select(selector);
  return ghe_perf_read();
}

static inline void ghe_fpga_perf_read_record (uint64_t *data_lo,
                                               uint64_t *data_hi)
{
  ghe_fpga_perf_select(GHE_FPGA_PERF_SEL_DATA_LO);
  (void)ghe_perf_read();
  *data_lo = ghe_perf_read();
  *data_hi = ghe_fpga_perf_read_sel(GHE_FPGA_PERF_SEL_DATA_HI);
}

static inline void ghe_fpga_perf_advance (void)
{
  ghe_fpga_perf_select(GHE_FPGA_PERF_SEL_ADVANCE);
}

static inline void ghe_fpga_perf_set_interval (uint64_t cycles)
{
  ROCC_INSTRUCTION_S (1, cycles, 0x79);
}

#define GHE_PERF_SEL_MEM_INST       0
#define GHE_PERF_SEL_BCOUNTER       1
#define GHE_PERF_SEL_SCH_STATE      2
#define GHE_PERF_SEL_CHECK_STATE    3
#define GHE_PERF_SEL_OTHER_THREAD   4
#define GHE_PERF_SEL_ALLBUSY        5
#define GHE_PERF_SEL_SCH_STATE_OT   6
#define GHE_PERF_SEL_CCOUNTER       7
#define GHE_PERF_SEL_RSU_STALL      8
#define GHE_PERF_SEL_GH_STALL       9
#define GHE_PERF_SEL_INST          10
#define GHE_PERF_SEL_KERNEL_INST   11
#define GHE_PERF_SEL_EXCEPTION     12
#define GHE_PERF_SEL_INTERRUPT     13
#define GHE_PERF_SEL_STALL_EXCPT   14
#define GHE_PERF_SEL_STALL_INTERR  15
#define GHE_PERF_COUNTER_COUNT     16

static inline uint64_t ghe_perf_read_sel (uint64_t selector)
{
  ghe_perf_ctrl(selector << 1);
  return ghe_perf_read();
}

static inline uint64_t ghe_csr_perf_read (int csr_index)
{
  uint64_t perf_val;
  ROCC_INSTRUCTION_DS (1, perf_val, csr_index, 0x55);
  return perf_val;
}

static inline uint64_t ghe_raw_perf_read ()
{
  uint64_t perf_val;
  ROCC_INSTRUCTION_D (1, perf_val, 0x78);
  return perf_val;
}

/* Runtime Configurable Checker Mask */
static inline void ghe_set_checker_mask (uint64_t mask)
{
  ROCC_INSTRUCTION_S (1, mask, 0x7D);
}

static inline uint64_t ghe_get_checker_mask ()
{
  uint64_t mask;
  ROCC_INSTRUCTION_D (1, mask, 0x7E);
  return mask;
}

static inline uint64_t ghe_get_checker_state (uint64_t checker_index)
{
  uint64_t state;
  ROCC_INSTRUCTION_DS (1, state, checker_index, 0x7F);
  return state;
}
