# FPGA 与论文数据冲刺：2026-11-12

本报告区分实际执行、完成与通过；运行时状态以链接中的原子状态及结果为准。唯一功能基线为 `8491167d84b6d9521b151a743673c1516926a1f8`，不增加功能、不改变目标周期。Native FPGA 暂停；仅允许 `0000:21:00.0` / `21770433G02LA`，禁止 e2 及全局设备操作。

## 已实际执行

| 路线 | 实际状态及证据 | 下一自动动作 |
| --- | --- | --- |
| SVB host40 shell 修复 | 02:09:06 UTC 启动 `ec-opt4-svb-host40-shell-physical-r2.service`，控制器 PID2429073/start26106655；复用 sealed DCP，CPU224–225/64GiB。真实 shell 查询选中14个负时序高扇出 FD-Q 网；工具已接受 routing/placement 物理优化 | A 失败则复用已保存 DCP 进行 B 定向物理复制；全时序、路由、DRC、pulse-width、bus-skew 通过才写 bitstream |
| SVB 独立认证与上板 | root 服务 `ec-opt4-svb-host40-shell-follow-r2.service` 与应用服务 `ec-opt4-svb-host40-shell-application-follow-r2.service` 已实际安装，等待真实结果 | 独立认证新 host40 profile → 两个共享21锁 → 21-only 短定向板测 → 同 bit 完整应用 trace replay；已有有效赢家不重刷 |
| 完整 MCRams host | `ec-opt4-auto-mcrams-full-host-capacity-r1-3656aec4.service` 保持原活综合；新 LUT/FIT 报告尚未产生 | synth 后立即资源报告、DCP、opt 后资源报告；通过严格容量/target parity 门才拼接 shell 与物理实现 |
| 地址 RAM 配对面积 | 02:09:49 UTC 实际启动 `ec-opt4-auto-address-bucket-mcrams-area-r2-8491167d.service`，控制器 PID2432698/start26111022；CPU220–221/24GiB | 对 Reg/MemMC 两个实际 GG 模型分别综合，严格交叉核对主资源表、层级与 primitive；局部收益不当整机 FIT |
| 同配置 Native CPU 模型 | r1缺原Native DACROIBRIDGE头文件、r2 make变量解析失败均已自然退出并保留；独立r3已通过真实make dry-run、完成编译和10001-cycle启动，02:29:06 UTC自动进入完整Canneal | 完整Canneal后自动Blackscholes；独立消费者已运行，核对输出、完整日志、版本、ROI指令和配置后才生成比较；不恢复Native FPGA |
| 原 e0 与 SVB50 | 原活综合/物理实现均保留，未停止、迁移或修改输入 | 只读接管；CPU增长与实际阶段进展分开记录 |

进程身份及完整状态快照：[actual-start-snapshot.json](./actual-start-snapshot.json)。本轮 boot_id 为 `d6c6e410-10ad-4326-86ba-79b657eabd96`；重连必须同时匹配 PID、start_ticks、boot_id 和子任务，不能只看 PID。

## 已测得的容量和时序

| 实际对象 | LUT | CARRY8 | DSP | 结论 |
| --- | ---: | ---: | ---: | --- |
| 最近完成的完整9ae post-opt | 2,847,382 | 90,740 | 195 | NOT FIT，U280 LUT容量1,303,680，缺1,543,702 |
| 原SVB组件连host/shell post-opt | 200,342 | 12,790 | 3 | 容量FIT；不代表时序通过，也不代表完整Opt4 FIT |
| 新MCRams完整FPGATop OOC | 未产生 | 未产生 | 未产生 | 尚无法判断；即使OOC FIT仍须拼shell后复核 |

真实 host40 MMCM profile 使用 CLKOUT0_DIVIDE_F=30，实际自动派生周期约24.997ns，另外65个时钟周期不变；不是仅放宽XDC。原封存全路由checkpoint的全clock WNS为−0.424ns，WHS为+0.001ns。最坏两条路径位于250MHz XDMA shell，分别是522扇出FIFO地址网和979扇出reset网，路由占延迟95.48%/98.11%。新物理优化尚无完成的时序报告，不能称已收敛。所有66个时钟及完整时序/DRC门保持。

资源准入实测：[third-small-component-slot-admission.json](./third-small-component-slot-admission.json)。仅为200k-LUT SVB组件增加一个受限物理优化槽，最多3个组件worker；没有第三个大型完整Opt4综合，也未降低通用broker守卫。

## 可引用的已完成数据及边界

独立完成审计：[原始证据、CSV与统计](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/overnight-ec-evidence-audit-r4-20261112/REPORT.md)。388项哈希核对、131/1122完整package join、659项完整SVB生命周期均有原始证据。

| 工作负载 | 数据来源 | ROI cycles | ROI instructions | 实际接受PASS | ROI后接受排空 |
| --- | --- | ---: | ---: | ---: | ---: |
| Canneal project400 | CPU完整GoldenGate metasim，FASED30/max4 | 536,456 | 392,248 | 131 | 332 CSR cycles |
| Blackscholes project64 | CPU完整GoldenGate metasim，FASED30/max4 | 6,166,433 | 3,562,647 | 1,122 | 9,655 CSR cycles |

以上两项原输出验证通过、pending为0、fault为0。它们不是Linux simmedium FPGA正式套件，也不能与既有Native Linux输入直接计算slowdown。匹配的单BOOM无checker Native CPU模型实际准备/编译中，尚无有效配对比值。Host运行时间属于模拟器效率，不能作体系结构slowdown。

完整真实应用SVB trace在原SVB standalone RTL与GoldenGate force-all replay中均通过：1,759,001个target edges、19,698,670个定义输出word checks、capture/promote/ACK各659、零mismatch，真实payload mutation被拒绝。659项完整ownership生命周期，capture→ACK均值6844.215478、中位数7150、P95=8089、P99=8398；promote→ACK均值80.968134、中位数83、P95=90、P99=94。1目标周期分桶，nearest-rank，零删失。这是CPU周期精确事件统计，尚非FPGA测量、严格检错延迟或饱和吞吐率。

**标签勘误：** Canneal ELF `d0d0e9ae99bd963aeed84a8b395e7096f54985d117d11542d553a38680b8397b` 实际为 `canneal_project400`：1线程、400 swaps、300起始温度、100.nets、2温度步。旧审计中human-readable project64标签错误，ELF、输入哈希与数值不变；旧证据保留。Blackscholes为project64。

## 恢复与放行规则

新服务由systemd托管，持单实例锁，持续落盘状态/日志。活CAD输入不改。失败后仅从已完成、哈希有效的checkpoint进入独立恢复版本；部分结果不计正式样本。时序失败继续基于实际路径诊断，不能仅因日志沉默终止进程。

新host40产物与50MHz证书严格分开。独立审计检查实际MMCM、66时钟、目标clock归属、setup/hold、路由完整性、DRC、pulse width和bus skew。通过后才允许部署。21锁覆盖部署及短板测，应用replay继承准确已部署bit，不重复刷卡。完整Opt4认证优先于组件测试，但不抢占活样本。

本轮根前台没有访问FPGA/JTAG、重载驱动或操作PCIe。尚无认证SVB或完整Opt4 bitstream，尚无新EC FPGA样本。严格checker延迟还缺同一package的BOOM最后执行完成事件，不能用BEGIN、SVB ACK或结果接受代替。

实时入口：

- [SVB host40物理修复状态](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r2-20261112/state.json)
- [SVB认证与定向板测状态](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-original-svb-host40-shell-onboard-r2-20261112/state.json)
- [同bit应用replay状态](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-original-svb-host40-shell-application-onboard-r2-20261112/state.json)
- [MCRams完整host容量状态](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-mcrams-full-host-capacity-r1-state.json)
- [MCRams容量后继状态](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-mcrams-full-host-continuation-r2-state.json)
- [地址RAM面积配对状态](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-mcrams-address-bucket-area-r2-state.json)
- [持续工作总账](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/unattended-opt4/state.json)

## 02:36 UTC 接续实绩

- 新SVB A正在处理真实FIFO/DMA/MIG shell网络，XDMA组中间WNS从−0.424改善到−0.417ns；这不是最终全局时序通过。A/B失败后C/D三服务已实际安装：PID2455877等待r2失败及exact cgroup退出，无额外CAD；另两个root服务等待独立认证与同bit应用replay。C为postroute clock-skew物理优化，D为安全shell FD-Q网的最短延迟重布线；都保留66时钟周期、全时序/DRC门。
- 完整MCRams实际日志出现`Finished Synthesize`、`Finished Constraint Validation`与后续FSM推断；仍在`synth_design`，没有资源表/DCP，FIT未知。单bank MemMC面积作业已到`Final Netlist Cleanup`，尚未产生资源表。不能将过程中的primitive或估算当正式LUT结果。
- [论文数据包](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/paper-real-ec-data-r2-20261112/README.md)已真实完成，包含CSV、JSON及PDF/SVG。根独立重核25个新交付文件哈希：[复核证据](./paper-delivery-smallhash-audit.json)。45条Native FPGA样本、两项EC CPU metasim、659项SVB生命周期分别标记，不混算FPGA slowdown。
- 原算法编译对象除独立boot adapter外全部逐字节相等：Canneal12个、Blackscholes7个；两组ROI反汇编均为同序列`rdcycle; rdinstret; jal workload_run; rdinstret; rdcycle`。[对象与ROI证据](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/matched-source-kernel-object-audit-r1-20261112/result.json)。链接地址/寄存器分配及启动cache状态差异明确保留，不能声称相同ELF。
- Native模型r3真实编译成功，10,001target cycles启动探针用时8.469395s，fault0。探针返回1来自cycle-limit，非工作负载PASS。完整Canneal实际运行中，尚未输出完整校验与完成标记；随后自动Blackscholes。比值审核服务`ec-paper-matched-source-cpu-consumer-r1-20261112.service`已实际运行，PID2480746/start26256906；静态共同配置/输入/编译器/ROI审核PASS，实际比值仍等待有效样本。[状态](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/paper-matched-source-cpu-comparison-r1-20261112/state.json)。
- CPU工作负载的checker本地BEGIN→完整PASS结果入队间隔已导出：Canneal n131，mean5593.290076/median5009/P958875/P999805；Blackscholes n1122，mean8558.537433/median9282/P959482/P999674，单位为100MHz checker目标周期，1周期分桶，nearest-rank。它包含该区间内等待，不等于用户定义的严格BOOM executionDone→checkerDone延迟。[CSV](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/paper-real-ec-data-r2-20261112/checker-local-package-statistics.csv)。
- 完整地址存储独立源码候选已准备：20个256×64 RAM，保留全部5120个debug payload与原80项归约/溢出/写优先。机械逆变换复原3656源码，尚不代表完整等价通过。实际启动准入因新内存/负载压力被拒；没有降低门。持久root waiter PID2477391/start26242441已安装，每300s等待MemAvailable≥256GiB、disk≥150GiB、load<48，再启动exact2CPU216–217/24GiB编译/展开/GG，绝不新开大型CAD。[状态](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-mcrams-full-address-rtl-r2-resource-waiter-state.json)。
- 已自然失败Native r2与未启动完整地址r1的DEFERRED receipt经精确身份/空cgroup核实后退役，避免broker空槽后重试同一失败版本；原request、日志和prior receipt保留。[退役证据](./retired-failed-or-unstarted-receipts.json)。没有信号发给活任务。

## 02:42 UTC 首个匹配CPU性能样本正式提交

| Canneal project400，1线程 | Clean Native单BOOM | 冻结EC C4/SVB32 |
| --- | ---: | ---: |
| ROI target cycles | 312,165 | 536,456 |
| ROI instructions | 392,248 | 392,248 |
| 输出、退出状态 | PASS / 0 | PASS / 0 |
| fault、timeout | 0 / 无 | 0 / 无 |
| 完整checker PASS / 最终pending | 无checker | 131 / 0 |
| ROI后接受排空 | — | 332 CSR cycles |

**EC/Native ROI=1.7185014335×；计入上述尾部排空=1.7195649737×。** Native host时间420.8961519s，EC host时间3791.3720847s，仅表示CPU模拟器效率，不用于体系结构比值。两边共享200MHz BOOM参数、I/Dcache、L2与FASED read/write30/max4/relax0；原算法与输入编译对象完全一致，ROI指令数相等。两组启动适配与链接ELF不同，cache初态不能宣称相同。当前每组n=1，属于匹配源码profile的CPU GoldenGate对照，**不是FPGA slowdown，也不是完整Linux套件正式三轮结果**。

独立消费者r1在数据核验后因系统Python缺matplotlib而不能提交图与完成标记，原失败保留。独立r2使用经过实际完整审计/出图验证的conda解释器，已产生原子result/complete、CSV与PDF/SVG；没有重跑应用。root再独立复核全部引用证据、完成标记和比值：[独立审计](./canneal-pair-independent-audit.json)。

- [性能结果与明确边界](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/paper-matched-source-cpu-comparison-r2-20261112/README.md)
- [CSV](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/paper-matched-source-cpu-comparison-r2-20261112/canneal_project400/comparison.csv)
- [PDF图](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/paper-matched-source-cpu-comparison-r2-20261112/canneal_project400/roi-cycles.pdf)
- [原子结果](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/paper-matched-source-cpu-comparison-r2-20261112/canneal_project400/result.json)

Blackscholes于02:36:07 UTC自动接续完整Native CPU运行，PID2483604/start26268793，尚未完成。新消费者`ec-paper-matched-source-cpu-consumer-r2-20261112.service` PID2490751/start26298723已接管Canneal完成结果、静态审核PASS并继续等Blackscholes；新增结果自动复核、分项提交、导出，不需手工续跑。旧r1失败证据未覆盖，活模型未动。

SVB A已完成真实route验证并进入Post Router Timing，尚未产生最终时序/DRC与bitstream。完整MCRams日志还新出现PackageAddressStats的实际BRAM映射，资源报告仍未产生；这能证明映射阶段推进，不能代替LUT/FIT。
