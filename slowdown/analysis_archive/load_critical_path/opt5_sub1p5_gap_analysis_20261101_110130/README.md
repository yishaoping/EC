# Opt5 sub-1.5 gap：当前证据不支持达标方案

结论：`OPT5_1P5_TARGET_NOT_SUPPORTED_BY_CURRENT_EVIDENCE`；`NEXT_ACTION = MORE_OFFLINE_ATTRIBUTION`。
本轮只做离线分析，未修改硬件，未 elaboration / RTL generation / Verilator build / simulation，未准备新硬件运行。

B 的 exact-ROI head miss wait 为 **53,845 cycles**，放宽到全部 head-load pending 为 **80,832 cycles**，分别只覆盖约146,410缺口的36.8%和55.2%。两者嵌套，禁止相加。
`LOAD_PATH_ALONE_CANNOT_REACH_1P5` 在这里指固定观测轨迹中直接删除已测 head-load 等待不足以达标；它不是所有非head依赖或时序反馈收益的全局不可能性定理。

结构性 `RETRY_AMPLIFICATION` 已有 RTL 证据，但没有足够大的可恢复关键路径收益归因。B 的47,162 retries不能当成47,162或更多可恢复cycles。64KiB/2-way 保留为causal probe/可选组件，尚无最终Opt5定义；`OPT5_INCLUDE_64K_2WAY=NO` 表示本轮未成立方案，并非证明64KiB无效。

旧A / 新B只作 `REFERENCE_COMPARISON`；A′未执行，保持 `STRICT_PAIRING_PENDING`，不因缺A′停止分析，也不建议机械重跑。
B正确性已在前轮独立派生capture视图闭合；原始host-cap FAIL和所有seal/claim保持原样。

- [146k缺口与非相加分解](146k_gap_analysis.md)
- [真实nack原因与数据缺口](nack_retry_breakdown.md)
- [head等待与重叠](rob_head_remaining_wait.md)
- [重试放大机制及边界](retry_amplification.md)
- [各候选上界](candidate_upper_bounds.md)
- [三个最小设计选项](opt5_design_options.md)
- [收益预算](opt5_gain_budget.md)
- [1.5可行性](sub1p5_feasibility.md)
- [下一步离线计划](next_run_plan.md)

复现仅使用CPU离线分析：
```bash
python3 -I -B AI/Debug/scripts/analyze_opt5_sub1p5_gap.py --previous /data1/gzh/EC/AI/TMP/l1_one_shot_postanalysis_20261101_095815 --out AI/TMP/opt5_sub1p5_gap_analysis_<new_timestamp>
```
输出必须是不存在的新目录。`numeric_audit.json`保存全部数值、窗口、prefix intervals和未知值；`source_evidence.json`保存源码/生成物行号及SHA256；`provenance.json`保存本轮输入hash；`validation_result.json`保存验证边界。
