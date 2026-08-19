#ifndef GHE_H
#define GHE_H

#include <stdint.h>

#include "rocc.h"

/*
 * GHE/GuardianCouncil 的软件接口封装。
 * 这些函数最终都会编译成 RoCC 指令；funct 值和 rs1/rd 的使用方式必须
 * 与硬件侧 GHE.scala 保持一致。这里不直接访问内存映射寄存器。
 */

/* 将当前 hart 切换到 R_IC/检查器相关状态。 */
static inline void ghe_asR(void)
{
    ROCC_INSTRUCTION_S(1, 0x01, 0x01);
}

/* 读取 GHT 通道状态，返回值由硬件定义。 */
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

/* 通知 GHE 可以开始推进检查流程。 */
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

/*
 * 性能统计控制字：bit 0 为复位，bit 5/6 分别为 START/STOP 脉冲；
 * bits 4:1 仍保留原有性能选择器。硬件把控制字锁存到 tile 内，
 * 因此每个统计命令都发送一次控制字，再发送 0 清除控制脉冲。
 */
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

/*
 * RoCC 流量统计向量的固定布局。
 *
 * 这些编号是软硬件协议的一部分，必须与
 * GH_GlobalParams.GH_TRAFFIC_* 完全一致，不能按软件需要重新排序。
 * 0--17 为基础访存、写回和不可缓存 store 的周期和统计；
 * 18--34 为 L1->L2 校验分类、包生命周期、完成水位及诊断信息；
 * 35 为需要校验的脏写回总数。
 */
enum ghe_traffic_counter {
    /* 基础访存分类计数。 */
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

    /* BOOM L1 DCache 到 L2 的 C 通道事务计数；只在 BOOM hart 0 有意义。 */
    GHE_TRAFFIC_L1_L2_C_TOTAL,
    /* 兼容旧调用方的枚举名称，数值仍为 C 通道事务总数。 */
    GHE_TRAFFIC_L1_L2_WB_TOTAL = GHE_TRAFFIC_L1_L2_C_TOTAL,
    GHE_TRAFFIC_L1_L2_WB_DIRTY,

    /* 当前保留的 L2 到 DRAM 基础计数；本轮未增加延迟分类。 */
    GHE_TRAFFIC_L2_DRAM_WB_TOTAL,
    GHE_TRAFFIC_L2_DRAM_WB_DIRTY,

    /* 不可缓存 store 事件对应的完成时刻 CSR cycle 总和。 */
    GHE_TRAFFIC_STORE_UNCACHE_CYCLE_SUM,

    /* 未校验脏写回的出现、结算、挂起和丢弃情况。 */
    GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_SEEN,
    GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_RESOLVED,
    GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_PENDING,
    GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_OTHER,
    GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_DROPPED =
        GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_OTHER,
    GHE_TRAFFIC_FAILED_PACKAGES,

    /* 延迟计算的两个周期总和及统计有效标志。 */
    GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_SAFE_CYCLE_SUM,
    GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_CYCLE_SUM,
    GHE_TRAFFIC_UNVERIFIED_DIRTY_WB_STATS_VALID,

    /* 完成位图整理得到的连续安全包水位及结果异常数。 */
    GHE_TRAFFIC_SAFE_PACKET_WATERMARK,
    GHE_TRAFFIC_PACKAGE_RESULT_DROPPED,

    /* 写回时已校验计数，以及独立的非校验脏写回诊断。 */
    GHE_TRAFFIC_VERIFIED_DIRTY_WB,
    GHE_TRAFFIC_NONVERIFY_DIRTY_WB,
    GHE_TRAFFIC_UNTRACKED_DIRTY_WB = GHE_TRAFFIC_NONVERIFY_DIRTY_WB,

    /* 包分配、checker 返回、通过和取消的生命周期计数。 */
    GHE_TRAFFIC_ALLOCATED_PACKAGES,
    GHE_TRAFFIC_COMPLETED_PACKAGES,
    GHE_TRAFFIC_PASSED_PACKAGES,
    GHE_TRAFFIC_CANCELLED_PACKAGES,

    /* 桶计数、周期求和或 pending 账目出现溢出的诊断计数。 */
    GHE_TRAFFIC_STATS_ARITHMETIC_OVERFLOW,
    /* 需要校验的脏写回总数，等于 verified + unverified_seen。 */
    GHE_TRAFFIC_L1_L2_WB_DIRTY_VERIFY_REQUIRED,
    GHE_TRAFFIC_COUNTERS
};

/*
 * 通过 funct=0x7B 读取当前 hart 所在 tile 的一个统计项。
 *
 * BOOM hart 0 返回自己的 DCache/L1->L2 统计以及共享 L2 的基础统计；
 * checker hart 对这些项目返回 0，但会返回自己的 store/load/LR/SC/AMO
 * 计数和 store_uncache 完成周期和。返回值为 64 位无符号计数。
 * counter_index 越界时硬件返回 0，因此调用者仍应使用合法枚举值。
 */
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

/* 读取当前 checker 使能位图，具体位含义由硬件配置定义。 */
static inline uint64_t ghe_get_checker_mask(void)
{
    uint64_t mask;
    ROCC_INSTRUCTION_D(1, mask, 0x7E);
    return mask;
}

#endif
