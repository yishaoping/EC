# Opt5 load opportunity：复用规则与证据边界（2026-11-01）

完整本轮报告：`AI/TMP/opt5_sub1p5_gap_analysis_20261101_110130/`。
只使用完成的旧A `optimization_4_svb_20261030_135448_0c744900` 和校正B
`optimization_4_svb_20261031_024551_8fbf8937`。B使用前轮另建的lossless capture恢复视图；
原host128身份cap FAIL不改写。A′未运行，旧A/B仍为REFERENCE_COMPARISON。

本轮没有hardware implementation或dynamic validation。结论是没有得到能支持sub1.5
收益预算的Opt5候选；64KiB/2way只是probe/可选组件。原Opt4/SVB16/checker正确性结论保持。

- exact软件ROI与traffic窗口不同。actual lookup misses属于traffic；native causal counters
  属于exact软件ROI。B外部窗口有11,160cycles，STOP值不能无条件当ROI计数。
- head-miss53,845包含于all head-load pending80,832；两者不相加。删除所有后者的
  fixed-trace理想情形仍为1.565468840x，高于1.5。此上界仅限制直接head-wait删除，
  不证明新的执行轨迹、非head依赖和资源反馈也不可能带来额外收益。
- nack/retry事件及延迟cohort sums不是stall损失。miss/retry/refill/replay共享生命周期；
  各自head包络重叠，不能将上界加总。MSHRbusy不是refill-conflict或full。
- native kind14是每次cacheable S2 miss lookup，first-detected token仅计一次；kind21/22
  是nack/retry。SC14/15属于store-preservation，命名空间不同。成功日志没有保留native
  per-event history，address在native causal模型里被忽略，因此逐line/token retry分布、
  critical retry factor、最大retry/head episode不可离线制造。
- 稳定LDQ token、generated16个LDQ槽允许给miss lookup attempts/token做carry-in边界：
  B40033/(1062+16)..40033/1062 =37.1364..37.6959；至少一个token有38次miss lookup。
  它不是retry events/unique retry requests，不能给后者错误套用1062分母。
- retained LDQ与AgePriorityEncoder已存在；普通load line-buffer forwarding已存在。
  MSHRFile not-ready还包含same-set/tag、RPQ/state/SDQ等门控；same-set/finite drain/owner
  保护不能通过简单放开来优化。活动generated bank-nack常量0，full0，不支持bank/MSHR扩容方向。
- 缺optional suffix时只能用保守complete prefix重建状态区间，不能hold-last填满ROI。
  更宽noCommit∩anyLoadPending148359..159519是相关exposure，尚非load因果stall。

离线工具：`AI/Debug/scripts/analyze_opt5_sub1p5_gap.py`；17项边界测试覆盖严格整数目标、
嵌套exposure、Fréchet交集、traffic→ROI、carry-in token、未知分母、SC7状态解码和hash失配。
新硬件run只有在独立证明一个值得验证的functional机制后才可准备，诊断应与该改动同版本，
不安排diagnostic-only run、cache sweep或机械重跑A′。
