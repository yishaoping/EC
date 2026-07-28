/**
 * @file    ghe.h
 * @brief   Guardian Heart Engine（GHE）RoCC 控制接口
 *
 * @details GHE 是软件进入 GuardianCouncil 硬件校验机制的主要控制面。
 *          大核用它启停检查窗口、读取状态与性能计数；checker 用它选择
 *          接收模式、查询 RSU/ELU、接收事件并释放资源。本文件只封装
 *          custom1 指令，不实现检查算法本身。
 *
 * @warning 调用本头文件前必须先包含 rocc.h，以提供 ROCC_INSTRUCTION_*
 *          宏。接口名称 initailised 是硬件/旧软件沿用的拼写。
 *
 *          主要功能模块：
 *          - 状态查询：   ghe_status(), ghe_agg_status(), ghe_sch_status()
 *          - 数据操作：   ghe_top/pop_func_opcode(), ghe_top/pop_data()
 *          - 聚合通信：   ghe_agg_push()
 *          - 执行控制：   ghe_go(), ghe_complete(), ghe_release(), ghe_initailised()
 *          - checker 接口：ghe_checkght_status(), ghe_rsur_status(), elu_checkstatus()
 *          - 性能计数：   ghe_perf_ctrl(), ghe_perf_read(), ghe_csr_perf_read()
 *
 *          ROCC 指令编码：
 *          funct=0x00: 读取 GHE 状态
 *          funct=0x01: 设置 GHE 为 R 模式
 *          funct=0x07: 查询 GHT 状态
 *          funct=0x40: 启动 GHE (go)
 *          funct=0x41: 完成当前操作
 *          funct=0x43: 释放 GHE 资源
 *          funct=0x50/0x51: 设置/清除初始化标志
 *          funct=0x55: 读取 CSR 性能计数器
 *          funct=0x76/0x77: 性能计数器控制/读取
 */

#include <stdint.h>

// ==================== GHE 状态码定义 ====================
#define GHE_FULL  0x02    // GHE 缓冲区已满
#define GHE_EMPTY 0x01    // GHE 缓冲区为空


/**
 * @brief  读取 GHE 主状态寄存器
 * @return 状态码：0b01=空, 0b10=满, 0b00=有数据缓冲, 0b11=错误
 */
static inline uint64_t ghe_status()
{
    uint64_t status;
    ROCC_INSTRUCTION_D(1, status, 0x00);
    return status;
}

/**
 * @brief  设置 GHE 为 R（Receiver）模式
 *         checker 核调用以准备接收主核的上下文数据
 * @return 无。uint64_t 返回类型是历史遗留，调用者不得使用返回值。
 */
static inline uint64_t ghe_asR()
{
    ROCC_INSTRUCTION_S(1, 0x01, 0x01);
}

/**
 * @brief  查看 GHE 栈顶的函数操作码（不弹出）
 * @return 栈顶操作码；缓冲区为空时返回 0。
 */
static inline uint64_t ghe_top_func_opcode()
{
    uint64_t packet = 0x00;
    if (ghe_status() != 0x01) {
        ROCC_INSTRUCTION_D(1, packet, 0x0A);
    }
    return packet;
}

/**
 * @brief  弹出 GHE 栈顶的函数操作码
 * @return 弹出的操作码；缓冲区为空时返回 0 且不发出 pop。
 */
static inline uint64_t ghe_pop_func_opcode()
{
    uint64_t packet = 0x00;
    if (ghe_status() != 0x01) {
        ROCC_INSTRUCTION_D(1, packet, 0x0B);
    }
    return packet;
}

/**
 * @brief  查看 GHE 栈顶的数据（不弹出）
 * @return 栈顶数据；缓冲区为空时返回 0。
 */
static inline uint64_t ghe_top_data()
{
    uint64_t packet = 0x00;
    if (ghe_status() != 0x01) {
        ROCC_INSTRUCTION_D(1, packet, 0x0C);
    }
    return packet;
}

/**
 * @brief  弹出 GHE 栈顶的数据
 * @return 弹出的数据；缓冲区为空时返回 0 且不发出 pop。
 */
static inline uint64_t ghe_pop_data()
{
    uint64_t packet = 0x00;
    if (ghe_status() != 0x01) {
        ROCC_INSTRUCTION_D(1, packet, 0x0D);
    }
    return packet;
}

/**
 * @brief  查询 GHT 的比对状态
 * @return 当前 checker/大核检查状态；tasks.c 将 0x02 解释为完成。
 */
static inline uint64_t ghe_checkght_status()
{
    uint64_t status;
    ROCC_INSTRUCTION_D(1, status, 0x07);
    return status;
}

/**
 * @brief  发出 doEvent 完成事件（funct=0x41）。
 */
static inline void ghe_complete()
{
    ROCC_INSTRUCTION(1, 0x41);
}

/**
 * @brief  发出 release 事件（funct=0x43），释放 checker GHE 资源。
 */
static inline void ghe_release()
{
    ROCC_INSTRUCTION(1, 0x43);
}

/**
 * @brief  发出 go 事件（funct=0x40），启动 checker 接收/检查流程。
 */
static inline void ghe_go()
{
    ROCC_INSTRUCTION(1, 0x40);
}

/**
 * @brief  读取 GHE 聚合状态寄存器
 * @return 聚合状态：0b01=空, 0b10=满, 0b00=有数据缓冲, 0b11=错误
 */
static inline uint64_t ghe_agg_status()
{
    uint64_t status;
    ROCC_INSTRUCTION_D(1, status, 0x10);
    return status;
}

/**
 * @brief  向 GHE 聚合缓冲区推送数据包（header + payload）
 * @param  header   数据包头部（如核心 ID、类型等）
 * @param  payload  数据包负载
 */
static inline void ghe_agg_push(uint64_t header, uint64_t payload)
{
    ROCC_INSTRUCTION_SS(1, header, payload, 0x11);
}

/**
 * @brief  读取 GHE 调度器状态
 * @return 调度器状态：0b01=空, 0b10=满, 0b00=有数据缓冲, 0b11=错误
 */
static inline uint64_t ghe_sch_status()
{
    uint64_t status;
    ROCC_INSTRUCTION_D(1, status, 0x20);
    return status;
}

/**
 * @brief  设置 GHE 初始化标志
 * @param  if_initailised  0 清除、1 设置；其他值不发出指令
 * @note   主核通过 ght_get_initialisation() 等待所有启用 checker 就绪。
 */
static inline void ghe_initailised(uint64_t if_initailised)
{
    if (if_initailised == 0) {
        ROCC_INSTRUCTION(1, 0x50);      // 清除初始化标志
    }
    if (if_initailised == 1) {
        ROCC_INSTRUCTION(1, 0x51);      // 设置初始化标志
    }
}

/**
 * @brief  读取 GHE 缓冲区深度
 * @return 当前缓冲区中的数据条目数
 */
static inline uint64_t ghe_get_bufferdepth()
{
    uint64_t depth;
    ROCC_INSTRUCTION_D(1, depth, 0x25);
    return depth;
}

// ==================== RSU (Recovery State Unit) 接口 ====================

/**
 * @brief  读取 RSU（恢复状态单元）的状态
 * @return 原始 RSU 状态位。tasks.c 使用 (status & 0x18) == 0x08
 *         判断是否需要触发上下文复制/恢复；低位的具体阶段由硬件定义。
 */
static inline uint64_t ghe_rsur_status()
{
    uint64_t status;
    ROCC_INSTRUCTION_D(1, status, 0x61);
    return status;
}

/**
 * @brief  检查 ELU（错误日志/观测单元）的待处理状态。
 * @return 0 表示所选通道无待处理项；非 0 时 tasks.c 记录错误并出队。
 */
static inline uint64_t elu_checkstatus()
{
    uint64_t status;
    ROCC_INSTRUCTION_D(1, status, 0x66);
    return status;
}

// ==================== 性能计数器接口 ====================

/**
 * @brief  控制 GHE 性能计数器
 * @param  ctrl_code  硬件定义的清零/启动或事件选择控制码
 * @note   test.c 使用 0x01/0x00 初始化，并用事件索引左移 1 后选择读数。
 */
static inline void ghe_perf_ctrl(uint64_t ctrl_code)
{
    ROCC_INSTRUCTION_S(1, ctrl_code, 0x76);
}

/**
 * @brief  读取 GHE 性能计数器值
 * @return 当前性能计数值
 */
static inline uint64_t ghe_perf_read()
{
    uint64_t perf_val;
    ROCC_INSTRUCTION_D(1, perf_val, 0x77);
    return perf_val;
}

/**
 * @brief  按索引读取 CSR 性能计数器
 * @param  csr_index  CSR 性能计数器索引（0~83，共84个）
 * @return 对应硬件 CSR 事件的性能计数值；默认测试仅读取索引 0。
 */
static inline uint64_t ghe_csr_perf_read(int csr_index)
{
    uint64_t perf_val;
    ROCC_INSTRUCTION_DS(1, perf_val, csr_index, 0x55);
    return perf_val;
}

/**
 * @brief  读取 RAW 冒险导致的停顿周期数
 * @return RAW 停顿周期数
 */
static inline uint64_t ghe_raw_perf_read()
{
    uint64_t perf_val;
    ROCC_INSTRUCTION_D(1, perf_val, 0x78);
    return perf_val;
}
