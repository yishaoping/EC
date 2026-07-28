/**
 * @file    test_runtime.h
 * @brief   GuardianCouncil 测试的多核同步与统计接口
 *
 * @details 该模块连接 tasks.c 中的 checker 生命周期钩子，收集每个 hart
 *          的 store 数量和累计延迟，并为主核提供带超时的完成等待。
 */

#ifndef TEST_RUNTIME_H
#define TEST_RUNTIME_H

#include <stdint.h>

/** 读取当前 hart 的 cycle CSR。 */
uint64_t test_read_cycles(void);
/** 判断 hart_id 是否属于配置的 checker 范围 1..TEST_NUM_CHECKERS。 */
int test_is_checker_hart(uint64_t hart_id);
/** 等待 GHT 达到完成状态；返回 1 表示完成，0 表示超时。 */
int test_wait_for_ght_done(uint64_t *last_status);
/** 读取并发布指定 hart 的 store 计数和累计周期。 */
void test_publish_storecount(uint64_t hart_id);
/** 等待所有 hart 发布统计；返回 1 表示齐备，0 表示超时。 */
int test_wait_for_storecounts(void);
/** 打印逐 hart 统计及派生的平均延迟。调用者负责持有 UART 锁。 */
void test_print_storecount_report(int storecounts_done);

#endif // TEST_RUNTIME_H
