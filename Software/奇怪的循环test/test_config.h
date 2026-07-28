/**
 * @file    test_config.h
 * @brief   GuardianCouncil 软件测试的集中配置
 *
 * @details 这些值同时描述测试拓扑、轮询超时、异步核时钟和汇编负载
 *          使用的保留内存区。修改核心数量或时钟频率时，应同步检查硬件
 *          GH_NUM_CORES、tile 频率配置和 CLINT 的 NUM_TIMER_HARTS。
 */

#ifndef TEST_CONFIG_H
#define TEST_CONFIG_H

#include <stdint.h>

// 1 个 BOOM 主核（hart 0）和 4 个 Rocket checker（hart 1~4）。
#define TEST_NUM_CHECKERS                4
#define TEST_NUM_CORES                   (TEST_NUM_CHECKERS + 1)

// 主核等待硬件完成和各核统计发布时使用的 rdcycle 超时阈值。
#define TEST_GHT_DONE_STATUS             UINT64_C(0x1FFFF)
#define TEST_GHT_DONE_WAIT_CYCLES        UINT64_C(100000000)
#define TEST_STORECOUNT_WAIT_CYCLES      UINT64_C(1000000)

// 用于把各时钟域累计周期换算为纳秒；必须与 SoC 配置一致。
#define TEST_MAIN_HART_CLOCK_MHZ         200U
#define TEST_CHECKER_HART_CLOCK_MHZ      100U

// 停止监控后的流水线排空长度，以及混合负载的重复次数。
#define TEST_PIPELINE_DRAIN_NOPS         26
#define TEST_WORKLOAD_ITERATIONS         3

// 汇编访存负载覆盖的保留物理地址范围和写入模式。
#define TEST_WORKLOAD_MEMORY_BASE        0x81000000
#define TEST_WORKLOAD_MEMORY_LIMIT       0x810008FF
#define TEST_WORKLOAD_ATOMIC_INITIAL     0x81000100
#define TEST_WORKLOAD_STORE_DATA_A       0x55552000
#define TEST_WORKLOAD_STORE_DATA_B       0x55553000

#endif // TEST_CONFIG_H
