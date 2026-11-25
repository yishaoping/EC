/*
 * 原有工作负载接口暂时保留，当前 GAPBS benchmark 不引用本文件。
 * 需要恢复旧测试时，删除下面的注释标记，并在 test.c/compile.sh 中重新接入。
 */
// #ifndef TEST_WORK_H
// #define TEST_WORK_H
//
// #include <stdint.h>
//
// /* 执行覆盖浮点、CSR、访存、LR/SC 和 AMO 的指令工作负载。 */
// void run_work(uint64_t hart_id);
//
// #endif
