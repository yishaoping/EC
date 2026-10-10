# Shadow writeback permission / metadata clear

- 状态：historical conclusion，最新verified=0的root cause未定位。
- Failure：旧BFS verified=0且结果数平衡，parent数据不正确。
- First bad：旧记录显示shadow C param=000(TtoB)随后本地meta Nothing；writeback完成到metadata clear之间允许再次请求。精确完整事件见原报告。
- Causal chain：对L2宣称保留B权限但本地失效 + clear窗口重发 → coherence/provenance不一致 → parent checksum错误。
- Broken invariant：释放权限与本地状态一致；同一事务完成/metadata clear前不重发。
- Fix：TtoN；serialize WB idle/completion/meta clear/request release。
- Validation：静态/compile已记录；保存后续窄波形有param001与clear期间无重发，不证明最新291包数据正确。
- Regression：检查TL A/C/D、line/seq、safe以及strict tokens；不要把latest verified=0直接归到旧root cause。
- 来源：history/reports/cache-replay/verified0_cross_package_coherence_root_cause.md、fix_checker_completion_first_three.md。
