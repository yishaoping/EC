# 唯一下一功能优化决策

`NEXT_OPTIMIZATION = NONE_JUSTIFIED`

`NEXT_OPTIMIZATION_NOT_YET_JUSTIFIED`

伴随决策：`KEEP_SVB16`、`DO_NOT_EXPAND_SVB`、
`L2_GEOMETRY_DEFERRED_UNTIL_NEXT_FUNCTIONAL_RUN`。

这是根据本次现有证据的选择，不是因为L2 S0失败而重开SVB correctness。
Opt4正式ROI有效。L1独立S0已经PASS，照样进入候选比较。
但没有miss→MSHR service→ROB停顿身份关联，shadow replacement/invalidation又不完全等价，
不能把60.4% miss reduction直接当ROI gain。当前不能证明约85,393 cycles的合理临界收益。

条件性最推荐的cache是64KiB/2-way：预期机制是保留更多working-set line，减少重装；
shadow减少1,985 misses，proxy192,641，比较器保持2。严格保证的临界收益为0，
315,637只是全部L1 MSHR活动的共同资源包络，尚不是该geometry的反事实upper bound。
若未来有独立足够证据，functional scope只改真实Config的capacity/index，保留6MSHR、SVB16和correctness fixes，
同时携带已修好的observer。**本轮没有实行这个条件性改动。**

SVB32局部上限5,254、promotion直接safe-entry活动包络24,569均不足作为主方向。
控制scheduler等待暴露很大，但没有确认哪项可安全缩短，以及可恢复多少commit关键路径。
L2既无有效counterfactual，也没有真实set-full证据。没有候选达成现有证据门槛。

因此没有可发布的`READY_TO_RUN_OPT5_*`。不创建可执行纯观察run，也不提供会误导用户立即开跑的Opt5命令。
后续若提供/获得其他已有的精确critical-path证据，可以直接据此实现唯一功能方向；
缺失旧数据无法由更多离线解析凭空恢复。
