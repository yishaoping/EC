#ifndef TEST_REPORT_H
#define TEST_REPORT_H
#include <stdint.h>
#include "../cfg/config.h"
extern volatile uint32_t hart_traffic_ready[NUM_HARTS];
int report_end(uint64_t start_cpu, uint64_t end_cpu, uint64_t hart_id);
#endif
