/**
 * @file    rocc.h
 * @brief   GuardianCouncil 软件使用的 RISC-V RoCC 指令编码宏
 *
 * @details 基于 Schuyler Eldridge 的 rocket-rocc-examples，用 .word 在 C 内
 *          生成 custom0~custom3 指令。test 目录中的 GHT/GHE 控制接口主要
 *          使用 custom1；R_INSTRUCTION_JLR 使用 custom3 承载恢复跳转。
 *
 *          宏把 C 操作数固定绑定到 a0(x10)、a1(x11)、a2(x12)，并用
 *          xd/xs1/xs2 位告诉 RoCC 命令路由器哪些寄存器有效。funct 参数
 *          最终进入指令 funct7 字段，由 GHE 硬件解释。
 *
 *          指令格式（R-type 类）：
 *          | funct7[6:0] | rs2[4:0] | rs1[4:0] | xd | xs1 | xs2 | rd[4:0] | opcode[6:0] |
 *
 *          宏命名规则：
 *          - ROCC_INSTRUCTION_DSS: 读1个目标寄存器 + 2个源寄存器
 *          - ROCC_INSTRUCTION_DS:  读1个目标寄存器 + 1个源寄存器
 *          - ROCC_INSTRUCTION_D:   只读1个目标寄存器
 *          - ROCC_INSTRUCTION_SS:  只写2个源寄存器
 *          - ROCC_INSTRUCTION_S:   只写1个源寄存器
 *          - ROCC_INSTRUCTION:     无寄存器操作数
 *          - R_INSTRUCTION_JLR:    跳转并链接指令
 *
 *          自定义操作码：
 *          - CUSTOM_0: 0b0001011
 *          - CUSTOM_1: 0b0101011
 *          - CUSTOM_2: 0b1011011
 *          - CUSTOM_3: 0b1100111 (CUSTOM Jump)
 */

// 上游来源：Schuyler Eldridge, Boston University, rocket-rocc-examples。
// 保留链接用于追溯原始宏：https://github.com/seldridge/rocket-rocc-examples/blob/master/src/main/c/rocc.h

#ifndef SRC_MAIN_C_ROCC_H
#define SRC_MAIN_C_ROCC_H

#include <stdint.h>

// 双层字符串化先展开常量表达式，再把最终机器字写入内联汇编文本。
#define STR1(x) #x
#define STR(x) STR1(x)
#define EXTRACT(a, size, offset) (((~(~0 << size) << offset) & a) >> offset)

// RISC-V custom opcode 槽；custom3 在本工程中还用于恢复跳转类命令。
#define CUSTOMX_OPCODE(x) CUSTOM_ ## x
#define CUSTOM_0 0b0001011
#define CUSTOM_1 0b0101011
#define CUSTOM_2 0b1011011
#define CUSTOM_3 0b1100111

// 生成 32 位 RoCC 命令字：X 选 custom 槽，xd/xs1/xs2 声明操作数有效性，
// rd/rs1/rs2 是物理寄存器编号，funct 是交给 GHE 解码的 7 位命令码。
#define CUSTOMX(X, xd, xs1, xs2, rd, rs1, rs2, funct) \
  CUSTOMX_OPCODE(X)                     |             \
  (rd                 << (7))           |             \
  (xs2                << (7+5))         |             \
  (xs1                << (7+5+1))       |             \
  (xd                 << (7+5+2))       |             \
  (rs1                << (7+5+3))       |             \
  (rs2                << (7+5+3+5))     |             \
  (EXTRACT(funct, 7, 0) << (7+5+3+5+5))

// 公共封装固定使用 ABI 参数寄存器：rd=x10(a0), rs1=x11(a1), rs2=x12(a2)。

/** 发出带 rd、rs1、rs2 的 RoCC 命令。 */
#define ROCC_INSTRUCTION_DSS(X, rd, rs1, rs2, funct) \
    ROCC_INSTRUCTION_R_R_R(X, rd, rs1, rs2, funct, 10, 11, 12)

/** 发出带 rd、rs1 的 RoCC 命令。 */
#define ROCC_INSTRUCTION_DS(X, rd, rs1, funct) \
    ROCC_INSTRUCTION_R_R_I(X, rd, rs1, 0, funct, 10, 11)

/** 发出只有 rd 返回值的 RoCC 命令。 */
#define ROCC_INSTRUCTION_D(X, rd, funct) \
    ROCC_INSTRUCTION_R_I_I(X, rd, 0, 0, funct, 10)

/** 发出带 rs1、rs2 且无返回值的 RoCC 命令。 */
#define ROCC_INSTRUCTION_SS(X, rs1, rs2, funct) \
    ROCC_INSTRUCTION_I_R_R(X, 0, rs1, rs2, funct, 11, 12)

/** 发出带 rs1 且无返回值的 RoCC 命令。 */
#define ROCC_INSTRUCTION_S(X, rs1, funct) \
    ROCC_INSTRUCTION_I_R_I(X, 0, rs1, 0, funct, 11)

/** 发出不带寄存器操作数的 RoCC 命令。 */
#define ROCC_INSTRUCTION(X, funct) \
    ROCC_INSTRUCTION_I_I_I(X, 0, 0, 0, funct)

/** 发出 custom3 恢复跳转命令；xs2=1 用作硬件跳转类别标志。 */
#define R_INSTRUCTION_JLR(X, funct) \
    ROCC_INSTRUCTION_JLR(X, 0, 0, 0, funct)

// 底层宏负责寄存器绑定和 .word 发射，业务代码应优先使用上面的公共封装。

/**
 * @brief  三操作数形式：硬件写 rd，软件提供 rs1 和 rs2。
 * @note   rd 使用输出约束，两个源操作数通过固定寄存器输入约束保持活跃。
 */
#define ROCC_INSTRUCTION_R_R_R(X, rd, rs1, rs2, funct, rd_n, rs1_n, rs2_n) { \
    register uint64_t rd_  asm ("x" # rd_n);                                 \
    register uint64_t rs1_ asm ("x" # rs1_n) = (uint64_t) rs1;               \
    register uint64_t rs2_ asm ("x" # rs2_n) = (uint64_t) rs2;               \
    asm volatile (                                                           \
        ".word " STR(CUSTOMX(X, 1, 1, 1, rd_n, rs1_n, rs2_n, funct)) "\n\t"  \
        : "=r" (rd_)                                                         \
        : [_rs1] "r" (rs1_), [_rs2] "r" (rs2_));                             \
    rd = rd_;                                                                \
  }

/**
 * @brief  双操作数形式：硬件写 rd，软件提供 rs1。
 */
#define ROCC_INSTRUCTION_R_R_I(X, rd, rs1, rs2, funct, rd_n, rs1_n) {     \
    register uint64_t rd_  asm ("x" # rd_n);                              \
    register uint64_t rs1_ asm ("x" # rs1_n) = (uint64_t) rs1;            \
    asm volatile (                                                        \
        ".word " STR(CUSTOMX(X, 1, 1, 0, rd_n, rs1_n, rs2, funct)) "\n\t" \
        : "=r" (rd_) : [_rs1] "r" (rs1_));                                \
    rd = rd_;                                                             \
  }

/**
 * @brief  只返回 rd、没有软件源操作数的形式。
 */
#define ROCC_INSTRUCTION_R_I_I(X, rd, rs1, rs2, funct, rd_n) {           \
    register uint64_t rd_  asm ("x" # rd_n);                             \
    asm volatile (                                                       \
        ".word " STR(CUSTOMX(X, 1, 0, 0, rd_n, rs1, rs2, funct)) "\n\t"  \
        : "=r" (rd_));                                                   \
    rd = rd_;                                                            \
  }

/**
 * @brief  无返回值、软件提供 rs1 和 rs2 的形式。
 */
#define ROCC_INSTRUCTION_I_R_R(X, rd, rs1, rs2, funct, rs1_n, rs2_n) {    \
    register uint64_t rs1_ asm ("x" # rs1_n) = (uint64_t) rs1;            \
    register uint64_t rs2_ asm ("x" # rs2_n) = (uint64_t) rs2;            \
    asm volatile (                                                        \
        ".word " STR(CUSTOMX(X, 0, 1, 1, rd, rs1_n, rs2_n, funct)) "\n\t" \
        :: [_rs1] "r" (rs1_), [_rs2] "r" (rs2_));                         \
  }

/**
 * @brief  无返回值、软件仅提供 rs1 的形式。
 */
#define ROCC_INSTRUCTION_I_R_I(X, rd, rs1, rs2, funct, rs1_n) {         \
    register uint64_t rs1_ asm ("x" # rs1_n) = (uint64_t) rs1;          \
    asm volatile (                                                      \
        ".word " STR(CUSTOMX(X, 0, 1, 0, rd, rs1_n, rs2, funct)) "\n\t" \
        :: [_rs1] "r" (rs1_));                                          \
  }

/**
 * @brief  不读写通用寄存器的控制命令形式。
 */
#define ROCC_INSTRUCTION_I_I_I(X, rd, rs1, rs2, funct) {                 \
    asm volatile (                                                       \
        ".word " STR(CUSTOMX(X, 0, 0, 0, rd, rs1, rs2, funct)) "\n\t" ); \
  }

/**
 * @brief  custom3 跳转控制形式；xs2=1 仅作硬件类别标志。
 */
#define ROCC_INSTRUCTION_JLR(X, rd, rs1, rs2, funct) {                 \
    asm volatile (                                                       \
        ".word " STR(CUSTOMX(X, 0, 0, 1, rd, rs1, rs2, funct)) "\n\t" ); \
  }

#endif  // SRC_MAIN_C_ROCC_H
