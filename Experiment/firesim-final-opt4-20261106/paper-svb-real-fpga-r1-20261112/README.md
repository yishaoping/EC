# 真实 SVB 组件 FPGA 数据

认证 bitstream 在 `0000:21:00.0` 实测，通过完整 Canneal project400 事件流重放。功能基线 `8491167d84b6d9521b151a743673c1516926a1f8`；仅 SVB 组件，不是完整 EC/8项 PARSEC FPGA 性能。

| 指标 | 实测值 |
|---|---:|
| Capture→ACK，均值/P95/P99 | 6844.215478 / 8089 / 8398 target cycles |
| Promotion→ACK，均值/P95/P99 | 80.968134 / 90 / 94 target cycles |
| 本轮重放速率，含MMIO/驱动 | 27384.737602 target edges/host s |
| 本轮 ACK/主机秒，含整条trace闲置区间 | 10.259541 |
| 本轮 FPGA host counter 增量 | 2569226669 FPGA host cycles |
| 本轮驱动循环/外层主机耗时 | 64.232895913 / 64.346417563 s |
| 实测 FPGA host 频率 | 39.999182521 MHz |
| 认证物理时钟名义值 | 40.004000400 MHz |
| 布线后完整 shell+SVB host 资源 | 197902 LUT / 141885 registers / 12790 CARRY8 / 3 DSP / 125.5 BRAM |
| WNS/TNS/WHS/THS | 0 / 0 / +0.001 / 0 ns |
| DRC | 0 Error / 49 reviewed Warning |
| 最后capture→最后ACK/首次空occupancy观测 | 6968 / 6969 target cycles |
| 整机 MCRams post-opt | 2420482 LUT，NOT FIT，缺1116802 LUT（shell未计入） |

本轮 1759001 target edges、19698670 输出wordchecks，659 capture/promotion/ACK，零mismatch。659是同一真实负载内的事件样本，不是659次独立程序运行。原始72.2107秒重放与本轮64.2329秒重放使用同一trace，分开保存在runs.csv；差异不能解释为硬件加速。

CSV：`latency-target-cycles.csv`、`lifetimes.csv`、`latency-replay-host-bounds.csv`、`runs.csv`、`resources.csv`、`frequency.csv`、`timing-drc.csv`、`drain-observations.csv`、`opt4-fit.csv`、`workload-coverage.csv`。CDF供论文直接引用，见PDF/SVG。逐事件原始计数器CSV和真实FPGA日志位于evidence/，大体积完整原始输入trace通过符号链接保留，manifest记录其绝对路径/字节数/SHA256。

必须按METHODS.md解释：target cycles不能用40MHz物理host频率换算；FPGA host-cycle握手区间包含MMIO/主机停顿；应用session_stop后SVB尾部与完整EC/checker排空不是同一指标。ACK不是checker完成或rollback。现阶段无完整EC FPGA bitstream/8项PARSEC性能结论。
