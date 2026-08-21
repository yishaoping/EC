#ifndef TEST_WORK_H
#define TEST_WORK_H

#include <stdint.h>

/* 执行覆盖浮点、CSR、访存、LR/SC 和 AMO 的指令工作负载。 */
void run_work(uint64_t hart_id);

#endif
