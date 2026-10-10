# Killed S1 store / stale nack / STQ execute head

- 状态：历史源码+波形已确认，最新回归未验证。
- Failure：728000/1181000 stq_execute_head got off track，1260000持续无提交。
- First bad：老S2 nack杀年轻S1但LSU已看到fire；另一运行迟到nack回退至已完成/回收slot。具体地址/slot/time只在对应run有效。
- Causal chain：accepted request丢失或stale nack身份不匹配 →指针倒退/重放缺口 →STQ/ROB停滞。
- Broken invariant：每次fire被保留或合法重试；nack只作用live未完成且identity一致entry。
- Fix：保存被kill的精确S1 metadata并重试一次；nack匹配valid/completed/token；明确completion与rollback优先级。
- Validation：历史compile/static通过；需要runtime验证one fire/one completion/one token consume。
- Regression：backpressure/replay/reset、slot复用、strict-token等待回收、barrier nack不能按附近地址猜测归属。
- 来源：history/reports/cache-replay/killed_store*、lsu_assert*、assert_stq*、boom_assert21_1260000*。
