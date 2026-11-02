# Preservation / outer A：否定跨 ACK 的 packet 锁，未证明运行中的关键放大

**结论：没有证据证明“一个preservation通过outer A锁住多个后续请求，恢复>=100k critical cycles”。** 两项具体静态结论已闭合：

1. **否定锁生命周期假设**：outer A `beatsLeft` packet锁只从首个accepted Put beat之后保持到最后beat接受；不覆盖pre-capture drain，不等terminal AccessAck。target-set preservation锁才持续到ACK。L2 hit Get也不经outer A。
2. **保留另一个明确耦合**：checkpoint在waitAck时已不读bank，但全局SourceC schedule/读端仍被`preservation.io.lock.valid`禁止；其他set dirty-victim Release可能受阻，而其MSHR Acquire必须等自己的ReleaseAck。这是 **global SourceC reservation → release/acquire HOL** 的真实静态路径，尚无运行频率/critical预算。

只移除每packet必有的read/delay间隙，在当前固定轨迹中可删除的该类slot最多 **34,104 cycles**（traffic内preservation首A数≤1,623，单引擎carry-in≤1，每包7×3=21）。这是实际结构服务槽的有范围上界；**不包含bank等待、ready-low、全局drain、waitAck或执行反馈**，不限制整个preservation机制。这个局部方向低于50k，停止将“缩短outer-A intrinsic gaps”作为Opt5主线。

67,366仍是2,231笔release lastC→firstbank的实测duration，不能拆成并不存在的已记录T1–T5。尚无capture/drain/arb/outerA逐episode时间，真正preservation/lock top20和request→ROB join均为null；报告另给20个**真实release pre-bank代理episode**，绝不冒称preservation episode。

最终：`AMPLIFICATION_PROVEN=NOT_PROVEN`；`MAIN_MECHANISM=NONE_JUSTIFIED`；`OPT5_STATUS=NONE_JUSTIFIED`；`SUB1P5_FEASIBILITY=NOT_SUPPORTED`；`NEXT_ACTION=MOVE_TO_NEXT_OFFLINE_BOTTLENECK`。下一离线对象为SourceC跨ACK全局预约和release/acquire HOL，并接着看L2入口/SourceD服务。frontend保持LAST_RESORT。

软件ROI `[698301,2347224)`=1,648,923；目标 `<1,502,513`，严格saving至少146,411。全程BOOM/L2 200MHz cycles，event simulator time=cycle+103；checker100MHz不直接相加。optional完整prefix `[698301,2192911)`，未知suffix154,313。B原始正确性/capture恢复结论保持，A/newB仍REFERENCE_COMPARISON/STRICT_PAIRING_PENDING，A′未跑。

## 交付与验证

本目录包含用户要求的13项文件，加numeric/source/provenance、top20 release proxies、CPU abstract contract witness、最终决策。`source_evidence.json`保存source/generated行号和hash；synthetic witness只是协议反例/模型证据，**不是本B运行观测或RTL仿真**。

`preservation_state_machine.md`和`outer_a_lock_semantics.md`回答资源/状态；`67k_latency_decomposition.md`和`episode_analysis.md`给分布及不可恢复项；amplification/correlation/bank/HOL报告给归因边界；`upper_bound.md`给UB1–UB4和去重范围；`candidate_fixes.md`最多4项风险；`next_run_plan.md`给下一离线路径及最小bounded诊断设计。

仅新建AI下离线工具/报告及更新长期状态。本轮无硬件patch、elaboration、RTL generation、Verilator build、benchmark simulation、observation-only run、新A/B、geometry/MSHR/frontend/SVB32/promotion改动或清理。

复现（仅CPU，输出必须为新目录）：

```bash
python3 -I -B AI/Debug/scripts/analyze_opt5_preservation_outer_a.py --out AI/TMP/opt5_preservation_outerA_attribution_NEW_UNIQUE_TIMESTAMP
python3 -I -B AI/Debug/scripts/test_opt5_preservation_outer_a.py
```
