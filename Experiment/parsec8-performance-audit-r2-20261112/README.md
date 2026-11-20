# 八项 PARSEC 性能数据复核与复用

已实际复核此前独立 CPU 会话完成的八项首轮及三轮重复，共24对/48份真实周期精确 Golden Gate 日志。历史 Native FPGA 八项各三轮也已复核，保留其数据；当前CPU测量与历史Linux simmedium workload/ROI/OS不同，分母全部采用同环境Native CPU，不跨平台拼接。

本目录只读核查原会话，没有重启、修改原任务或重复已完成实验。首轮原始CSV为first-round.csv，所有重复为paired-repeats.csv，论文图为Performance.pdf/svg/png。历史FPGA为historical-native-fpga.csv，资格状态为coverage-status.csv。完整原始日志的路径、compressed/raw SHA256、原始字节数及完成收据见cpu-raw-log-audit.json/csv，原数据保持原目录。436项快照文件、源码/模型/ABI/平台参数/输入、48份完整原始日志重新解压校验，EC包完整通过并排空才接受配对。

| 项目 | Native ROI cycles | EC ROI cycles | Slowdown | 测量范围 |
|---|---:|---:|---:|---|
| blackscholes | 60832 | 63547 | 1.044631× | 64 options, one bs_thread iteration |
| fluidanimate | 16949 | 28077 | 1.656558× | AdvanceParticles phase, 64 particles, real captured state |
| bodytrack | 125929 | 146905 | 1.166570× | ImageErrorEdge/Inside likelihood phase, real frame0 maps |
| freqmine | 166379 | 467929 | 2.812428× | Official 3-transaction test, hot4 cache and quiet ROI |
| swaptions | 167237 | 337633 | 2.018889× | Original worker, 16 trials |
| ferret | 24720 | 34184 | 1.382848× | EMD distance matrix, 126 real region pairs; excludes flow solution |
| dedup | 211667 | 407603 | 1.925680× | Official 6-byte test pipeline, 16MiB buffer, preloaded hash table |
| streamcluster | 303982 | 609828 | 2.006132× | Original streamCluster, 16 points, FP contraction disabled |

这些是声明输入/阶段的真实target-cycle比值；不是模型估算，也不是整应用、完整simmedium或FPGA Slowdown。Fluidanimate、Bodytrack和Ferret只测所列阶段，其他输入也有缩小/改配置，不能外推完整应用。三轮确定性模拟的重复一致性不等于不同输入/布局的统计不确定度。Native/EC共享应用对象、ISA、处理器/内存配置、单线程和ROI口径；boot ELF/链接地址及初始cache布局不同这一既有限制保留。所有旧失败/超时/取消的profile保持排除，未被成功小profile“修复”。

完整EC FPGA仍无认证可运行映像；SVB-only数据完全不进入此图。当前八项选定profile三轮均完成，没有为重复同一测量启动新模拟器。独立CPU会话原调度器已以COMPLETE_THREE_ACCEPTED_PAIRED_REPEATS自然结束。原测量方法完整保留在original-methods.md。更大/完整输入仍须另立匹配的Native/EC测量，不能用本表推算。

历史Blackscholes三轮的state.json在收据保存后正常从RUNNING更新为COMPLETE；与收据绑定的snapshot.json仍精确一致，原始UART/ROI/manifest/result均未变化，详见native-mutable-metadata-resolution.json。原r1严格审计的partial状态与原输出保留，本r2复用同轮48份完整原始日志解压校验收据，不再重复12.7GB解压。Performance图已调整说明位置，避免遮挡横轴标签。

复核：`python3 verify.py`，不启动仿真或访问FPGA。
