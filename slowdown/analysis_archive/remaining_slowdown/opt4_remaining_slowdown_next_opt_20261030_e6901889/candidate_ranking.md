# 候选排序：数值的语义优先于大小

GO建议门槛：5%×1,707,863=**85,393.15 cycles**（取整约85,393）。
“Proxy”“活动包络”“固定轨迹局部上限”不是同一种收益估计；没有任何一项已证明足够的optimizer-specific临界收益。

|Candidate|量化机会与限制|Confidence|Hardware cost|Recommend|
|---|---|---|---|---|
|L1 32K→64K，2way|1,985 shadow misses；proxy192,641；保证临界收益0；共同MSHR资源包络315,637|流量中等；ROI低|data×2、逐line元数据×2，比较器仍2|条件性首选cache；当前NO GO|
|other：checker/package scheduling|完整前缀unavailable267,087；未知suffix130,713；全ROI活动范围[267,087,397,800]|状态暴露较高；可恢复性未证|依具体scheduler/ownership机制而定，尚无安全改法|优先因果追查；当前NO GO|
|L1 2→4 ways，32K|1,792 misses；proxy173,911；保证临界收益0|流量中等；ROI低|comparators2→4、mux2:1→4:1，data不增|排在64K/2way后；NO GO|
|L1 64K/4way|2,108 misses；proxy204,578；相对S2仅+123miss/+11,937proxy|增量价值较低|data×2加4way比较/mux|不选最大配置|
|faster promotion|safe→terminal并集24,569；前缀legacy重叠1,171；不是全局反事实上界|局部活动高；因果收益低|并行source/ACK、line顺序、terminal协议更复杂|不作下一主优化|
|SVB32|固定轨迹唯一full episode局部上限5,254；ROB重叠未知、可为0|局部上限高；全局反馈未证|SVB entry/data/meta×2及选择网络增大|DO_NOT_EXPAND_SVB|
|L2 capacity|无可采纳geometry特定cycle估计；actual149 misses、set-full0；L2 MSHR busy190,049含hit/C|不足|data/tag/元数据约随容量增，未作PPA|DEFER|
|L2 associativity|无可采纳geometry特定cycle估计；valid way max8/16；旧S0 FAIL|不足|16→32比较器/mux/目录组织增大|DEFER|

该顺序是“条件性工程价值与继续分析优先级”，不是伪装成同精度cycle收益的排名。
L1 proxy=avoided shadow misses×(317,542/3,272)，是equal-service假设，仅比较假设敏感性。
所有候选都没有实测ROI预测点值；不把proxy173k–205k写成会恢复的cycles。

控制活动范围的上端仅把未知suffix全部视为unavailable；它不表示397,800可优化。
L1 all-MSHR busy和控制unavailable可能重叠，并可能包括baseline必需工作。
L2旧S1–S3完全不参与排行，DRAM latency也无可用测量。
