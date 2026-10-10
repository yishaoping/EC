# Validation prompt

> 先用同一软件、生成 RTL、Git diff manifest 运行窄模块测试，再运行整机。每个结果用独立 BOOM commit/PC/机器码 scoreboard、DATA/ARF/CPS/END、LSL fire、result/release/safe 验证；修复后确认 broken invariant 恢复。程序跑完、watchdog 延后、package 数相等都不算成功。新 bug 先判断旧 first-bad 是否消失。
