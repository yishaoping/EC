# Root Cause Analysis prompt

> 读取 `AI/Debug/README.md`、`state/current_debug_state.md` 和相关 bug。先记录证据版本与时间单位；建立 last good → first bad → failure 表。分别证明 symptom、immediate blocker、upstream trigger、downstream amplifier，明确 broken invariant 和 ruled-out hypotheses。root cause 未确认前不要 patch；优先 first bad/first divergence，不围绕最终 watchdog 猜测。
