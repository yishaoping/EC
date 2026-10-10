# DATA anchor / admission / result handoff

- 状态：多次历史确认，属于不同run，不合并为单一发生链。
- Failure：ARF/CPS不完整导致COPY不发，或result已形成但BOOM永不clear；seq57存在CDC数据却无法admission。
- First bad：早期80465 data dequeue后ARF ready被data valid永久压低；另一运行result等待local clear、local clear又等result；seq57 admission把自身CDC head当旧cleanup未完。
- Broken invariant：data anchor按seq持久化；candidate不被自己的presence阻塞；result handoff与cleanup/admission偏序不成环。
- Fix：dataConsumedSeq/anchor、持有result直到fire、held BOOM release、local cleanup与新data admission分开；缺包无data不能靠瞬时empty证明。
- Validation：历史源码编译与FST extraction，未自动等同新RTL动态通过。
- Regression：ordered END、zero anchor、stale ARF、slot reuse、allocation→admission bounded failure仍需检查。
- 来源：history/reports/legacy_ai/watchdog_signal_chain.md、assert22_*、arf7_data_arrival_vs_absence.md。
