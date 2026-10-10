# 证据身份规则

每份波形、日志、生成 RTL 和分析报告必须同时记录：Git HEAD、工作树 diff hash、软件 hash、生成目录、文件 mtime/size/hash、FST/VCD 类型、时间单位和是否来自当前源码。

结论分四级：

- **verified fact**：源码与同一版本生成物/动态证据直接支持。
- **historical conclusion**：某次旧运行成立，不能外推到最新运行。
- **hypothesis**：待验证的解释或设计方案。
- **deprecated/unresolved**：已被新证据替代，或仍没有足够证据。

旧运行的 FST 时间、assert 行号、package 序号和 cycle 换算不是常数。报告先写证据边界，再写 last good → first bad → failure；不要把 watchdog 时刻当 root cause。
