# Strict store underflow / replay identity

- 状态：历史波形root cause已确认；本次没有新硬件验证。
- Failure：strictStorePending underflow，历史log约198000/FST396351–396353。
- Last good/first bad：架构store记一次pending，replay/refill物理写又产生无身份completion；完整事件表见原RCA。
- Causal chain：physical write被当architecture completion →重复/迟到事件 →pending下溢。
- Broken invariant：一个架构提交token只完成一次，STQ复用/reset不继承旧replay。
- Fix：提交处分配monotonic token，贯穿MSHR/RPQ，按live slot/token匹配消费；STQ必要时延迟回收。
- Validation：Scala parser/BOOM compile/diff通过；runtime once-only仍需新run。
- Regression：token导致延迟回收，须核对STQ completion/nack/execute-head优先级。
- 来源：history/reports/cache-replay/assert74_*。
