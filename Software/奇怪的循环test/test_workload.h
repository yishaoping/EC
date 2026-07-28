/**
 * @file    test_workload.h
 * @brief   hart 0 混合指令测试负载接口
 *
 * @details 负载用于产生 GuardianCouncil 需要捕获和重放的浮点、CSR、
 *          异常、load/store、LR/SC 与 AMO 事件，不负责自行判定结果。
 */

#ifndef TEST_WORKLOAD_H
#define TEST_WORKLOAD_H

#include <stdint.h>

/** 执行混合负载并返回执行期间重新读取的 mhartid。 */
uint64_t test_run_workload(uint64_t hart_id);

#endif // TEST_WORKLOAD_H
