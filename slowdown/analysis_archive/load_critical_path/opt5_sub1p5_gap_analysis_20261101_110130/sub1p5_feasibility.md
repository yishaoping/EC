# sub-1.5可行性决策

`OPT5_1P5_TARGET_NOT_SUPPORTED_BY_CURRENT_EVIDENCE`

当前不能提出一个有可信收益预算、硬件可落地且只需最多一次主要验证就能合理期待<1.5的Opt5。缺少>100k-cycle首阻塞归因；观测head-miss包络仅53,845，即使全部head-load pending也只有80,832。
`LOAD_PATH_ALONE_CANNOT_REACH_1P5` 只是在固定观测head-wait直接删除模型下成立。非head依赖与时序反馈仍可能改变新执行，但现有日志不能证明其recoverable budget；更宽的148,359..159,519相关exposure也不能弥补这一证据缺口。

realistic target：先保住当前B实测1.646165673x；若后续确证load子优化，可把“有所低于1.646”作为验证目标，不能承诺数值区间。1.592410712x是理想删除全部head-miss的局部极限场景，1.565468840x是更宽head-pending理想场景，均不是预计收益，更未到1.5。
若只从已测head路径获益，要进一步达标仍需约65.6k–92.6k额外周期来自另一个**已归因**方向或非head反馈。最大已识别独立control候选为scheduler exposure347,409，但它不是证明可恢复的347,409；不纳入此次load主题Opt5。保持SVB16/L2/checker已闭合结论，不为目标重开无关优化。

```text
TARGET_ROI = 1502513
TARGET_SLOWDOWN = 1.5
CURRENT_B_ROI = 1648923
REMAINING_GAP = 146410
REMAINING_ROB_HEAD_LOAD_WAIT = 53845
REMAINING_NACK_RETRY = 47162
REMAINING_REPLAY = 229
MAIN_MECHANISM = NONE_JUSTIFIED
OPT5_PRIMARY = NONE_JUSTIFIED
OPT5_INCLUDE_64K_2WAY = NO
EXPECTED_RECOVERABLE_CYCLES = UNKNOWN (conservative credit = 0)
UPPER_BOUND_CYCLES = 80832 (fixed-trace all-head-load-pending; narrower miss = 53845)
EXPECTED_FINAL_ROI = UNKNOWN (no-credit current B = 1648923)
EXPECTED_FINAL_SLOWDOWN = UNKNOWN (no-credit current B = 1.646165672)
CONFIDENCE = LOW
VERDICT = OPT5_1P5_TARGET_NOT_SUPPORTED_BY_CURRENT_EVIDENCE
NEXT_ACTION = MORE_OFFLINE_ATTRIBUTION
```

LOW指候选正收益估计置信度；已测head exposure不足的算术判断为HIGH（限上述范围）。NO指未选定方案，64K仍可选，不是NOT_NEEDED结论。
