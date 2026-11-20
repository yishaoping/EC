# 两条路线真实执行与恢复入口

2026-11-11。唯一功能基线8491167d；Native继续暂停；21-only。以下资源、周期和吞吐率分属不同测量，不能互换。

## 完整硬件：最新容量结论

9ae9a7fc完整顶层post-opt实测：2,847,382 LUT /1,303,680 (218.411%)，90,740 CARRY8 /162,960，195 DSP /9,024，1,028.5 BRAM /2,016，URAM0。**NOT FIT，超1,543,702 LUT**。比8da24a26少368,301 LUT。容量守卫保留优化DCP并停止于place之前；不是工具故障重启。

精确报告：D/build-logs/Opt4-fit-bucket-tag-cad-9ae9a7fc/top-postopt-{utilization,hierarchical}.rpt。非重叠DCache子层级：addressStats892,396；mshrs203,789；crossPackageBarrierStats111,634；svb95,153；wb94,298；prober93,585；l1L2BarrierStats56,391；data49,605；completionQ27,590 LUT。不要把父层级与子层级加总。

e0c3737f完整综合及d9/3656完整DCache、e211地址module map继续，状态见快照。未获得e0整机报告。没有认证完整Opt4 bitstream，没有完整Opt4 FPGA样本。完整地址和DCache的RegVec/宽读端口是重要剩余瓶颈；局部RAM收益不得直接从整机缺口相减。

## 路线A：已经完成的新测试

| 测量 | 实际结果 | 证据 |
|---|---|---|
| GG库512x64、4R2W RAM，U280 OOC | 97,851→352 LUT，0→1 BRAM，8,192 target cycles通过，冲突/复位/背压与负例通过；边界FMR6.86755 | D/cycleprecise-route-a-r2-20261111/result.json |
| GG库512x81、35R1W RAM，U280 OOC | 388,931→3,289 LUT，0→1.5 BRAM，8,192 target cycles通过，边界FMR36.902 | 同上 |
| 同一target FIR/anno实际GoldenGate metasim | 原/MC各2,240个81bit输出相同；10,000自由target cycles FMR1.5016/38.0014，CPU吞吐59,887.5/1,604.79 target cycles/s | D/cycleprecise-metasim-r6-20261111/result.json |
| 原冻结完整target RTL新Canneal运行 | project400 bare-metal；ROI485,329 cycles/392,248 instructions；136 generated/accepted/PASS，FAIL0；校验尾排空262 cycles；输出checksum40b2b50000000000/verified1/routing_cost4789；host2107.6796s | D/cycleprecise-frozen-canneal-20261111/{result,analysis,complete,binding}.json |
| 原SVB32完整模块 | 16定向case/333cycles通过；OOC130,876 LUT/11,474 CARRY8/0DSP | D/cycleprecise-frozen-svb-r3-20261111/result.json |
| 原SVB32 target与真实GG host模型逐周期 | 原完整模块不变；39cycles初始化后333cycles×127输出=42,291值全部通过，位翻转负例被拒；共372cycles | D/cycleprecise-frozen-svb-trace-r4-20261111/result.json |

Canneal是本轮真实重新执行，不是复用历史结果；1,486,308 harness cycles /2107.6796s=705.187cycles/s。它不是Linux正式simmedium，也不是FPGA。真实SVB事件capture→completion：n695、mean6857.142、median7065、P95 8119、P99 8443、max9097，整数周期精度；promotion→ACK mean58.878。完整精确直方图位于D/cycleprecise-frozen-canneal-20261111/fresh-event-intervals.json。此延迟不是同package BOOM执行完成→checker完成的严格latency，后者仍缺匹配事件。

GoldenGate时间复用原理适用：冻结target所有输入采样、同周期多端口优先级/读写冲突、输出与状态更新边界完全保留；host可多拍执行，target只在tokens完成后前进。已测RAM边界/原SVB有限轨迹有通过证据，未声称整机或所有输入的形式等价。MCRams只变换可识别且标注的memory；10处core RF标注不能自动覆盖地址/DCache RegVec。MTModels按相同module共享且当前仅支持一个共享module类；5个tile标注不是5个异构核心可直接共享的证据。

完整冻结MCRams GG变换已完成：D/cycleprecise-frozen-mcrams-20261111/result.json，host RTL c027132fbb6013365ae539a984d0842bfde10d2dbae71c2e64ba1edef51ce776。未通过完整系统parity/FIT门，不启动昂贵整机CAD冒称收益。

## 正在执行与恢复

- ec-opt4-frozen-full-metasim-follow-r3.service：完整原GG host RTL已成功编译并完成link-only依赖修复，复用原生成C++/objects；r2启动参数将+prog放在+permissive-off之前导致无binary，证据保留，r3修正顺序，执行10,000targetcycles有界启动探针。状态D/cycleprecise-frozen-full-metasim-follow-r3-20261111/state.json。启动探针不是benchmark/checker通过。
- ec-opt4-frozen-svb-fpga-r2.service：原SVB独立component构建，不是完整C4。r1漏复制XDC已保存失败；r2验证原GG producer的RTLhash，复制原XDC并显式重定位host adapter层级，复用外部固定ABI/F1Shim，先metasim再次比对42,291值，再编译21-only硬guard硬件driver，再复用11shellIP DCP做容量→place/route→timing/DRC→bitstream。状态D/cycleprecise-frozen-svb-fpga-r2-20261111/state.json及cad-state.json。当前未部署、没有新component FPGA数据。
- 原e0和module maps保持不变；唯一8d50489a后继等待实测显著面积与组合/周期证明。ec-opt4-unattended.service持续进行等价优化；24h sprint watcher保留。

恢复先看PID+start_ticks+boot_id和子进程；活任务接管，不重启、不改输入。退出后只复用哈希有效成功stage；失败/部分尾部保留，使用独立版本恢复。每个任务有instance.lock、原子state、receipts和持续日志，由systemd托管。状态为RUNNING/服务active不等于测试通过。CPU服务不执行FPGA操作；component部署必须通过独立component认证和共享21锁、最新实际占用核对，绝不能借用全Opt4的认证。

历史Native FPGA45/48有效样本、15程序×3在D/paper-evidence-20261111。它们作为独立证据保留，暂未完成与新bare-metalproject400的同profile交叉验证，不计算混用slowdown。旧关闭保护但保留checker的RTL不是单BOOM trueNative。SC32/37/38只有hash，不能恢复完整应用数据payload，原SVB372cycle回放是定向trace，不能称真实应用payload trace。无新增架构恢复功能或architectural rollback/restart验证主张。

W=/data1/gzh/EC/firesim/final-opt4-20261106
D=/data1/gzh/EC/Experiment/firesim-final-opt4-20261106
复现脚本W/routes/cycleprecise-r2-20261111/{run.py,metasim_recovery_r6.py,replay_frozen_canneal.py,fresh_trace_metrics.py,svb_trace_metasim_r4.py,full_metasim_follow_r3.py,svb_fpga_prepare_r2.py}。已完成stage有收据，勿以重跑覆盖。

## 后续真实执行更新（2026-11-11 18:08 CST）

完整冻结GG模型启动探针已结束：实际10,001targetcycles，host26.065s，FMR33.44，因最大周期限制退出1；没有应用/checker通过主张。已复用该模型开启完整Canneal project400 metasim：ec-opt4-frozen-full-metasim-sample-r1.service，独立日志/heartbeat/state，5,000,000 targetcycle上限、3h host timeout、4GiB日志预算；最新已观察285,333targetcycles（509s），未完成不计入有效样本。

原SVB component shell DUT真实综合完成：119,711 LUT、11,724 CARRY8、0DSP、54,768FF（完整host wrapper/bridge范围，区别于130,876 LUT原target OOC）；已进入顶层implementation，尚无完整component post-opt FIT/bitstream。原冻结MTModels+MCRams完整GG实际启动：ec-opt4-frozen-mt-mcrams-r1.service；仅host编译、未经完整parity/资源准入，无第三个昂贵整机CAD。

独立自动21卡component链已实际启动：ec-opt4-original-svb-onboard-r1.service，state=D/cycleprecise-original-svb-onboard-r1-20261111/state.json。先等待component真bitstream，认证source/proof/driver/shell11DCP/capacity/timingDRC及实际target时钟覆盖，再检查完整Opt4优先权、21共享maintenance/card锁和当前设备冲突，使用固定21-only工具定向部署并运行372cycle/42,291值trace。离线绑定正向与4个错误BDF/基线/driver来源/不足proof拒绝测试通过。它不创建完整Opt4或PARSEC样本，也没有声称已上板。当前任务为等待CAD。

新增实际问题：9ae旧shell XDC的host_clock和相对target路径未匹配，原容量NOTFIT结论不受影响，但仅有正WNS不能证明目标时序受约束。原SVB自动认证额外打开routedDCP验证真实BUFGCE输出上的时钟period<=20.01ns、寄存器时钟覆盖及setup/hold；不通过就保留证据并拒绝部署。未改任何活CAD输入。后续完整Opt4认证也必须审计原两目标时钟域，而不能无条件信任旧XDC成功。

新增复现代码：W/routes/cycleprecise-r2-20261111/full_metasim_sample_r1.py、full_mt_mcrams_r1.py、svb_component_runtime_r1.py；对应输入清单svb-component-runtime-r1-inputs.json。持续恢复仍遵循PID/start/boot三元组及成功stage哈希；已有故障证据不覆盖。

## 2026-11-11T10:12:32.326568+00:00 组件容量门实际通过

原SVB32独立component连同完整FireSim host/shell的post-opt真实资源为 **200,342 LUT (15.367%) /12,790 CARRY8 /3 DSP /141,825 FF /125.5 BRAM**，容量门CAPACITY_FITS_POSTOPT_TIMING_PENDING，Vivado已实际进入place_design Phase1。报告/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-frozen-svb-fpga-r2-20261111/cad-logs/top-postopt-utilization.rpt。这是component FIT，绝不是完整Opt4 FIT；尚无bitstream、时序/DRC认证或上板结果。21跟随服务等待真实产物。完整Canneal metasim最新heartbeat453,725targetcycles/807s，未结束，不计通过。
