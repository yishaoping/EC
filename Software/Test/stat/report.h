#ifndef TEST_REPORT_H
#define TEST_REPORT_H

#include <stdint.h>

#include "../hw/ghe.h"
#include "../cfg/config.h"

/* BOOM 和 checker 的统计快照，由报告模块定义、secondary.c 写入 checker 行。 */
extern uint64_t csr_read_s[TOTAL_CSR_PERF];
extern uint64_t csr_read_e[TOTAL_CSR_PERF];
extern volatile uint64_t hart_traffic[NUM_HARTS][GHE_TRAFFIC_COUNTERS];
extern volatile uint32_t hart_traffic_ready[NUM_HARTS];

/* 等待统计收敛、冻结快照并输出本次 benchmark 的报告。 */
void report_end(uint64_t start_cpu, uint64_t end_cpu, uint64_t hart_id);

#endif
