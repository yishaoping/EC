#ifndef GHE_H
#define GHE_H

#include <stdint.h>

#include "rocc.h"

static inline void ghe_asR(void)
{
    ROCC_INSTRUCTION_S(1, 0x01, 0x01);
}

static inline uint64_t ghe_checkght_status(void)
{
    uint64_t status;
    ROCC_INSTRUCTION_D(1, status, 0x07);
    return status;
}

static inline void ghe_release(void)
{
    ROCC_INSTRUCTION(1, 0x43);
}

static inline void ghe_go(void)
{
    ROCC_INSTRUCTION(1, 0x40);
}

static inline void ghe_initailised(uint64_t initialised)
{
    if (initialised == 0) {
        ROCC_INSTRUCTION(1, 0x50);
    }
    if (initialised == 1) {
        ROCC_INSTRUCTION(1, 0x51);
    }
}

static inline uint64_t ghe_rsur_status(void)
{
    uint64_t status;
    ROCC_INSTRUCTION_D(1, status, 0x61);
    return status;
}

static inline uint64_t elu_checkstatus(void)
{
    uint64_t status;
    ROCC_INSTRUCTION_D(1, status, 0x66);
    return status;
}

static inline void ghe_perf_ctrl(uint64_t ctrl_code)
{
    ROCC_INSTRUCTION_S(1, ctrl_code, 0x76);
}

#define GHE_FPGA_PERF_CTRL_RESET (1ULL << 0)
#define GHE_FPGA_PERF_CTRL_START (1ULL << 5)
#define GHE_FPGA_PERF_CTRL_STOP (1ULL << 6)

static inline void ghe_fpga_perf_command(uint64_t command)
{
    ghe_perf_ctrl(command);
    ghe_perf_ctrl(0);
}

static inline void ghe_fpga_perf_reset(void)
{
    ghe_fpga_perf_command(GHE_FPGA_PERF_CTRL_RESET);
}

static inline void ghe_fpga_perf_start(void)
{
    ghe_fpga_perf_command(GHE_FPGA_PERF_CTRL_START);
}

static inline void ghe_fpga_perf_stop(void)
{
    ghe_fpga_perf_command(GHE_FPGA_PERF_CTRL_STOP);
}

static inline void ghe_fpga_perf_set_interval(uint64_t cycles)
{
    ROCC_INSTRUCTION_S(1, cycles, 0x79);
}

static inline uint64_t ghe_csr_perf_read(int csr_index)
{
    uint64_t perf_val;
    ROCC_INSTRUCTION_DS(1, perf_val, csr_index, 0x55);
    return perf_val;
}

enum ghe_traffic_counter {
    GHE_TRAFFIC_STORE_TOTAL = 0,
    GHE_TRAFFIC_STORE_CACHE,
    GHE_TRAFFIC_STORE_UNCACHE,
    GHE_TRAFFIC_LOAD_TOTAL,
    GHE_TRAFFIC_LOAD_CACHE,
    GHE_TRAFFIC_LOAD_UNCACHE,
    GHE_TRAFFIC_LOAD_FORWARD,
    GHE_TRAFFIC_LR,
    GHE_TRAFFIC_SC_SUCCESS,
    GHE_TRAFFIC_SC_FAIL,
    GHE_TRAFFIC_AMO_TOTAL,
    GHE_TRAFFIC_AMO_CACHE,
    GHE_TRAFFIC_AMO_UNCACHE,
    GHE_TRAFFIC_L1_L2_WB_TOTAL,
    GHE_TRAFFIC_L1_L2_WB_DIRTY,
    GHE_TRAFFIC_L2_DRAM_WB_TOTAL,
    GHE_TRAFFIC_L2_DRAM_WB_DIRTY,
    GHE_TRAFFIC_COUNTERS
};

/* 读取当前 hart 所在 tile 的流量统计：索引 0--16 依次是
 * STORE 总数、可缓存 STORE、不可缓存 STORE、LOAD 总数、
 * 可缓存 LOAD、不可缓存 LOAD、LOAD 转发、LR 完成、
 * SC 成功、SC 失败、AMO 总数、可缓存 AMO、不可缓存 AMO、
 * BOOM DCache L1->L2 写回总数/脏写回数、DCache 来源的共享 L2->DRAM
 * 写回总数/脏写回数。四项只由 BOOM hart 0 返回，checker 对应项为 0。 */
static inline uint64_t ghe_traffic_counter_read(int counter_index)
{
    uint64_t value;
    ROCC_INSTRUCTION_DS(1, value, counter_index, 0x7B);
    return value;
}

static inline void ghe_set_checker_mask(uint64_t mask)
{
    ROCC_INSTRUCTION_S(1, mask, 0x7D);
}

static inline uint64_t ghe_get_checker_mask(void)
{
    uint64_t mask;
    ROCC_INSTRUCTION_D(1, mask, 0x7E);
    return mask;
}

#endif
