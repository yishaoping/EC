# Opt5：功能方向待证据，不是运行入口

`NEXT_OPTIMIZATION_NOT_YET_JUSTIFIED`

`NEXT_OPTIMIZATION = NONE_JUSTIFIED`

Reference：`optimization_4_svb_20261030_072604_18475a92`，有效ROI1,707,863，
baseline1,001,675，remaining706,188。

`KEEP_SVB16` / `DO_NOT_EXPAND_SVB`。
L1条件性首选64KiB/2-way，但尚未证明约85,393cycles关键路径机会，未改配置。
L2 geometry延后到下一次真正的功能优化run，不能使用失效旧S1–S3。

此目录仅保存决策。没有launcher、build、仿真或observer-only运行入口。
已经实现的L2 read-consistent snapshot与kind40–45 STOP counters只在下一功能实验中集成。
原Opt4 launcher的source/patch保护没有放宽；当前staged observer源码不是READY Opt5 revision。

功能方向独立获得依据后，使用`optimization_5_<chosen_name>/`保存唯一主要功能改动，
并在一个完整功能实验中同时获取ROI、correctness、Opt4比较、L2 shadow和SVB16统计。
本轮未运行elaboration、RTL generation、Verilator build、hardware simulation或benchmark。

完整分析：[报告](../../AI/TMP/opt4_remaining_slowdown_next_opt_20261030_e6901889/README.md)
与[候选排序](../../AI/TMP/opt4_remaining_slowdown_next_opt_20261030_e6901889/candidate_ranking.md)。
