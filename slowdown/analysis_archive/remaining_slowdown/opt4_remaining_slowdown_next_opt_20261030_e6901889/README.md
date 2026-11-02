# Opt4 剩余 706,188 cycles 与下一优化决策

状态：`NEXT_OPTIMIZATION_NOT_YET_JUSTIFIED`；`NEXT_OPTIMIZATION = NONE_JUSTIFIED`。

有效 reference 是 `optimization_4_svb_20261030_072604_18475a92`，Opt4 ROI **1,707,863 cycles**，baseline **1,001,675**，剩余 **706,188**。Opt4 correctness 已闭合；L2 shadow 失败不再错误地推翻它。

- `KEEP_SVB16` / `DO_NOT_EXPAND_SVB`：唯一 full episode 的固定轨迹局部收益上限 **5,254 cycles**。
- promotion 的 safe→terminal 区间并集 **24,569 cycles**，不能据此支持作为下一主优化。
- L1 S0 sanity PASS；64KiB/2-way 是最优的条件性 cache 假设，尚无足够证据证明约 **85,393 cycles** 的可恢复关键路径机会。
- 最大可辨识控制暴露是完整前缀内 scheduler unavailable **267,087 cycles**；它不是已归因的可恢复 ROI。
- L2 旧 observer 的 accepted-write mirror 与 delayed-read image 不一致，已实现只读 snapshot 修复；当前 run 缺原始顺序，无法精确离线重放。
- **没有实现任何功能优化，没有 READY Opt5 launcher，也没有准备纯观察实验。** 新 observer 只供下一次已有独立依据的功能实验集成。

本轮执行：离线重分析、58 项 CPU 离线测试、7 个 Scala 源文件 `-Ystop-after:typer` 类型检查；均 PASS。未运行 elaboration、RTL generation、Verilator build、硬件仿真或 benchmark。源码逆变换与证据 hash 审查见收尾文件。

## 报告入口

- [18 个问题逐项回答](answers_18.md)
- [非加法 slowdown 分解](remaining_706188_breakdown.md)
- [SVB16 容量上限](svb16_capacity_upper_bound.md) / [promotion](promotion_pressure.md)
- [L1 shadow](l1_shadow_results.md) / [geometry 成本](l1_geometry_cost.md)
- [L2 根因](l2_shadow_rootcause.md) / [修复与语义](l2_shadow_fix.md)
- [候选排序](candidate_ranking.md) / [唯一下一优化决策](next_optimization.md)
- [实现范围](implementation.md) / [下一次实验约束](next_run_plan.md)
- [证据索引](evidence_index.md) / [最终机器可读指标](../../../../AI/TMP/opt4_remaining_slowdown_next_opt_20261030_e6901889/closure_analysis/metrics.json)

原 run 的所有证据保持原样。修正后的 summary 单独保存于 [closure_analysis/corrected_summary.json](../../../../AI/TMP/opt4_remaining_slowdown_next_opt_20261030_e6901889/closure_analysis/corrected_summary.json)。
