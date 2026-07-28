/**
 * @file    test_workload.c
 * @brief   驱动 GuardianCouncil 检查链路的混合指令负载
 *
 * @details 该负载不以计算出某个黄金数值为目标，而是让 BOOM 提交端产生
 *          多种必须被捕获、传输和重放的事件。它覆盖单/双精度浮点运算，
 *          cycle/instret/mhartid 与浮点 CSR，机器态 ecall，普通 load/store，
 *          LR/SC、AMOADD、乘除法以及固定地址范围内的重复访存。
 *
 * @warning TEST_WORKLOAD_MEMORY_BASE..LIMIT 必须是平台为测试保留的可访问
 *          物理地址区间；在其他内存映射上运行前必须重新配置。
 */

#include <stdint.h>

#include "test_config.h"
#include "test_workload.h"

#define TEST_STRINGIFY_IMPL(value) #value
#define TEST_STRINGIFY(value) TEST_STRINGIFY_IMPL(value)

/**
 * @brief  在 hart 0 上执行混合指令刺激。
 * @param  hart_id 调用者传入的 hart ID；函数内再次读取 mhartid 进行确认。
 * @return 执行期间读到的 mhartid。
 *
 * @note   checker 不调用本函数。它们通过硬件下发的检查包和上下文重放
 *         hart 0 的检查窗口，而不是并行执行同一个 C 函数。
 */
uint64_t test_run_workload(uint64_t hart_id)
{
    // 生成 F 扩展和 D 扩展运算，并让结果参与后续控制/整数路径。
    float a = 0.1;
    float b = 0.2;
    float c = 0.3;
    float d = (a + b + c) * 1.7 * 3.2;

    // 显式 CSR 读取覆盖 cycle、instret 和 hart 身份相关状态。
    uint64_t csr_value = 0;
    asm volatile("csrr %0, cycle" : "=r"(csr_value));
    asm volatile("csrr %0, instret" : "=r"(csr_value));
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));

    double e = (c - b + a) * 1.1;
    double f = ((e + d) * (d - b)) / 2.1;
    double g = (c + 1.1) / 2;
    double h = a - 0.05;
    double i = f + 1.1;
    double sum = a + b + c + d + e + f + g + h + i;

    // 保护条件确保只有 hart 0 执行固定物理地址上的汇编负载。
    if ((sum * hart_id) != 0) {
        return hart_id;
    }

    for (int iteration = 0; iteration < TEST_WORKLOAD_ITERATIONS; iteration++) {
        // 每轮刷新 CSR，并用 ecall 覆盖 trap 入口及 mepc+4 返回路径。
        e = iteration * 1.2 + 3;
        b = sum + 1.7;
        a = (e + b) * 2.2;
        asm volatile("csrr %0, cycle" : "=r"(csr_value));
        asm volatile("csrr %0, instret" : "=r"(csr_value));
        asm volatile("csrr %0, mhartid" : "=r"(hart_id));
        a = a + csr_value;
        asm volatile("ecall");

        if (!(a > hart_id)) {
            continue;
        }

        // Store/LR-SC 段同时产生地址、数据、原子和浮点 CSR 检查事件。
        asm volatile(
            "li   t0, " TEST_STRINGIFY(TEST_WORKLOAD_MEMORY_BASE) ";"
            "li   t1, " TEST_STRINGIFY(TEST_WORKLOAD_STORE_DATA_A) ";"
            "li   t2, " TEST_STRINGIFY(TEST_WORKLOAD_STORE_DATA_B) ";"
            "j    1f;"
            "1:"
            "li   a5, " TEST_STRINGIFY(TEST_WORKLOAD_MEMORY_LIMIT) ";"
            "lr.w a0,   (t0);"
            "sc.w a0,   t1,   (t0);"
            "sd         t1,   (t0);"
            "sd         t2,   16(t0);"
            "sd         t1,   32(t0);"
            "sd         t2,   64(t0);"
            "divw       t3,   t1, t2;"
            "addi t0,   t0,   0x10;"
            "frflags    a3;"
            "fsflags    a3;"
            "csrrc  a3, fflags, a3;"
            "csrrwi a3, frm, 0x3;"
            "csrrsi a3, fflags, 0x1F;"
            "csrrci a3, fflags, 0x0F;"
            "blt  t0,   a5,  1b;"
            :
            :
            : "a0", "a3", "a5", "t0", "t1", "t2", "t3", "memory");

        // Load 段读取同一地址模式，并混入 MULW、DIVW 和 DIVU。
        asm volatile(
            "li   t0, " TEST_STRINGIFY(TEST_WORKLOAD_MEMORY_BASE) ";"
            "j    1f;"
            "1:"
            "li   a5, " TEST_STRINGIFY(TEST_WORKLOAD_MEMORY_LIMIT) ";"
            "lr.w a0,   (t0);"
            "sc.w a0,   t1,   (t0);"
            "ld         t1,   (t0);"
            "ld         t2,   16(t0);"
            "ld         t1,   32(t0);"
            "ld         t2,   64(t0);"
            "mulw       t3,   t1, t2;"
            "divw       t3,   t1, t2;"
            "frflags    a3;"
            "li         a3,   0x55;"
            "fsflags    a3;"
            "divu       t2, t2, t1;"
            "addi t0,   t0,   0x10;"
            "blt  t0,   a5,  1b;"
            :
            :
            : "a0", "a3", "a5", "t0", "t1", "t2", "t3", "memory");

        // AMO 段对步进地址执行 acquire 语义的 32 位原子加法。
        asm volatile(
            "li   t0, " TEST_STRINGIFY(TEST_WORKLOAD_MEMORY_BASE) ";"
            "li   t1, " TEST_STRINGIFY(TEST_WORKLOAD_ATOMIC_INITIAL) ";"
            "li   t2,   1;"
            "j    1f;"
            "1:"
            "li   a5, " TEST_STRINGIFY(TEST_WORKLOAD_MEMORY_LIMIT) ";"
            "amoadd.w.aq t1,   t2, (t0);"
            "addi t2,   t2,   0x01;"
            "addi t0,   t0,   0x10;"
            "blt  t0,   a5,  1b;"
            :
            :
            : "a0", "a3", "a5", "t0", "t1", "t2", "t3", "memory");
    }

    return hart_id;
}

#undef TEST_STRINGIFY
#undef TEST_STRINGIFY_IMPL
