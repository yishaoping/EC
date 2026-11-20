# SVB 实际 FPGA 数据补测及论文导出

本轮已实际复用同一认证 bitstream 在 `0000:21:00.0` 完成一次有新增测量价值的 Canneal project400 重放。未烧录、复位PCIe或改变XDMA/硬件；未控制独立CPU PARSEC会话。唯一功能基线8491167d。

**真实FPGA结果：**1759001条targetedges、19698670次定义输出wordchecks、659capture/promotion/ACK、零mismatch，返回0。软件计时驱动仅读取现有ClockBridge，原全部输入写入、输出校验、step/reset保留。372边沿软件adapter正例及payload变异拒绝均通过；旧完整CPU应用正/负例继续绑定。

| 时间域，capture→ACK | 均值 | P95 | P99 |
|---|---:|---:|---:|
| Target cycles | 6844.215478 | 8089 | 8398 |
| FPGA host cycles，握手边沿区间界 | 8744979.373–8745268.983 | 10451264–10451553 | 11303284–11303573 |
| Host wall-clock ms，握手边沿区间界 | 218.626617–218.638572 | 261.284699–261.296591 | 282.585607–282.597509 |

Target cycles不可用物理host频率换算；后两行包含真实MMIO/驱动/主机停顿，不是自主SVB最短流水延迟。Promotion→ACK平均80.968134/P9590/P9994targetcycles。ACK为SVB所有权/writeback完成，不是checker完成或rollback。

本轮FPGAhost counter增量2569226669cycles，driverloop64.232895913s，外层host64.346417563s，重放27384.737602targetedges/hostsecond、10.259541ACK/hostsecond。实际频率39.999182521MHz；认证名义物理40.004000400MHz/24.9975ns另列。ClockBridge targettokens跨同bit多次进程累计：原1759374→新3518375，增量恰为1759001。新日志rawFMR/EffectiveTargetFrequency不能当作本轮速率，CSV已按本轮计数重算。

布线后完整shell+SVBhost：197902LUT/141885registers/12790CARRY8/3DSP/125.5BRAM。WNS/TNS0/0ns，WHS/THS+0.001/0ns；255876nets全布通，0routingerror；DRC0Error/49已评审保留Warning。未称CDC零critical。

末次capture→最后ACK6968cycles，→首次空occupancy预边沿观测6969cycles。源应用报告ROIstop→最后ACK512cycles，报告session_stop→最后ACK270cycles、→首次空occupancy271cycles。仅SVB尾部观察，未注入新drain请求，不冒充完整EC/checker排空。

**[论文可直接使用的数据、PDF/SVG、原始日志及trace](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/paper-svb-real-fpga-r1-20261112/README.md)** 已完成：36项artifact、23项原始source的SHA256及659条配对/分位数验证PASS。大原始trace保持原文件并以symlink/manifest指向。CSV包含生命周期、三时间域、target直方图/CDF、resources/frequency/runs/drain/FIT/coverage。复核命令：`python3 /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/paper-svb-real-fpga-r1-20261112/verify.py`。完整测量定义见METHODS.md。

完整MCRams真实postopt2420482LUT/80990CARRY8/192DSP/1696013FF/898.5BRAM，NOTFIT、缺1116802LUT（不含shell）。完整EC无bitstream/FPGA性能样本。8项优先PARSEC尚无完整SVBpayloadtrace可安全放行；Blackscholes已存CPU观测不包含512bitSVBpayload，不能伪造。

新地址模块完整6144周期/5684输出parity及真实无效寄存器bit变异拒绝已PASS；单一既有service仍`RUNNING_MAP-REFERENCE`，阶段时间1560.2s，保持参考→候选相同directive面积配对自动运行。完整模块收益未知。真实Vivado3368055持续约100%CPU，正常8d整机3138447/r51/原接续均保留。无人值守ec-opt4-unattended-r2 active，policy/prompt已更新：取实际配对面积后决定composition/GG/targetcycle验证及下一版整机综合；不外推局部收益、不重复活任务，不重放同Canneal来增加样本数。

原始快照normal-task-snapshot.json、校验收据publication-verification.json。本报告时间2026-11-12T11:35:47.979117+00:00。
