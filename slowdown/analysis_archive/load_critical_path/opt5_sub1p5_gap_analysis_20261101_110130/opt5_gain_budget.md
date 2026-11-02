# Opt5收益预算：当前没有205k可支持预算

| Component | 数值 | 类型 | 可计入预计收益？ |
|---|---:|---|---|
| A 64KiB/2-way相对旧A | 58,940 cycles | measured reference delta，非strict causal estimate | 仅参考，不能保证 |
| B retry amplification fix相对B | unknown；保守0 | 尚无实现/关键路径归因；head-miss局部包络53,845 | 不把上界当预计值 |
| C 同因果链refill/replay小改 | unknown；保守0 | 与B共享head包络，不能相加 | 不计入 |
| total expected vs Opt4 | unknown | 没有可靠点估计 | 不支持≥205,350 |

保守规划不给未证实优化任何cycle credit：B维持1,648,923/1.646165672x。这是current measured result/no-credit planning case，**不是已实现Opt5的预测**。新候选expected final ROI/slowdown为null。

用于审查目标的乐观固定轨迹情形：

| 情形 | vs Opt4总改善 | 最终ROI | slowdown | 距严格1.5仍缺 |
|---|---:|---:|---:|---:|
| reference容量delta + 理想删除B全部head miss | 58,940+53,845=112,785 | 1,595,078 | 1.592410712 | 92,566 |
| reference容量delta + 理想删除B全部head pending | 58,940+80,832=139,772 | 1,568,091 | 1.565468840 | 65,579 |

上述是从当前B删除已观测周期的illustration，容量delta已包含在B，不再次从B扣58,940。第二行包含第一行，不能加总。capacity与retry优化也可能有负交互：容量已消掉很多可抑制的retry。没有严格pairing和新候选运行，不能把两项独立测量当无交互收益。
