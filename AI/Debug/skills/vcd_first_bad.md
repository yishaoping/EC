# Skill：VCD/FST first-bad tracing

1. 记录 FST/VCD 文件、生成 RTL、软件 hash、HEAD/diff hash 和时间单位。
2. 用 `scripts/ec_fst_trace.sh FST START END REGEX...` 只提取窄信号集；不要把整个 FST 展开为文本。
3. 建立 `time / signal / transition / interpretation` 表，按 rising edge 前状态判断 fire/commit。
4. 从 watchdog 向上追到第一个缺失/错配 handshake，再从 producer 向下追到 release；分开 symptom、blocking condition、upstream trigger、amplifier。
5. 先复查旧 first-bad 是否消失，再命名当前 root cause；不能由终止时刻倒推。
6. 将窄 trace 放 `AI/TMP`，把 confirmed chain 和可复用 signal set 写回 `bugs/` 或 `scripts/`。
