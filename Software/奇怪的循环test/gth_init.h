/**
 * @file    gth_init.h
 * @brief   Guardian Heart Table 过滤与调度配置接口
 *
 * @details r_ini() 配置以下提交事件的过滤规则，并把主核产生的检查包和
 *          上下文快照分发给 checker：
 *          - Load 指令（GID=0x01, sel_d=0x02=LDQ）
 *          - Store 指令（GID=0x02, sel_d=0x03=STQ）
 *          - CSR 读指令（GID=0x03, sel_d=0x01=PRFs）
 *          - Atomic 指令（GID=0x01, sel_d=0x05=STQ+PRFs）
 */

#ifndef GTH_INIT_H
#define GTH_INIT_H

#include <stdint.h>

/** 配置过滤器、SE 调度范围和 checker 映射；成功路径固定返回 0。 */
int r_ini(int num_checkers);

#endif // GTH_INIT_H
