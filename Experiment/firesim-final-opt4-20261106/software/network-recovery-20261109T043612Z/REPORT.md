# 2026-11-09 持续实验与网络软件恢复实测

最终进程快照：2026-11-09 05:04:18 UTC（北京时间 13:04:18）。冻结硬件仍为 `8491167d84b6d9521b151a743673c1516926a1f8`，C4 / SVB32 / L2 report-permission repair。FPGA、CAD、coverage-first 和正式软件/执行计划均未停止、重启或修改；没有设备编程、XDMA、PCIe、e2 操作。

## FPGA 正式结果与接续

Native **26/48** 个有效正式样本，**10/16** 项至少完成正式 r1，**8/16** 项三轮齐备；Opt4 **0/48**，有效配对 **0/16**。相比用户给定的 25 样本，新增的是 **Raytrace simmedium r1**：ROI **2,400,529,768 cycles**，宿主 **1743.334587791 s**，输出校验和原子完成标记均有效。不是 Ferret 正式通过。

当前只运行 **X264 simmedium r1**，设备 `0000:21:00.0` / `21770433G02LA`，PID **1272563**，启动 tick **1052933**。boot_id 为 `d6c6e410-10ad-4326-86ba-79b657eabd96`，身份仍匹配。heartbeat 的累计 FPGA tick 在两次低频观测间从 **142,841,460,417** 增至 **149,577,441,600**；当前 ROI 事件仍为 running、faults=0，尚无 ROI_END，不能提交或报告最终 ROI cycles。该累计 tick 不是本样本 ROI 长度。

Coverage-first PID **80044**、C4 首验等待器 PID **71732** 均身份匹配。下一项按现有优先级为 **Raytrace r2 → Facesim r2**；X264 r1 有效提交后，其 r2 也会进入原队列，顺序由原 priority 决定。最终 C4 就绪时先走既有安全首验，不抢占当前样本。全部16项仍在原执行计划内，13项有正式软件绑定。

Native **Ferret simsmall** 是输出 SHA 不符（程序退出0不算通过）；**Vips test** 是 `Kernel panic: Kernel stack overflow`。两者功能门阻塞各自正式轮次，未阻塞 Raytrace/X264 等其他项。三个网络程序仍明确软件阻塞，未偷写正式收据让队列越过兼容门。

- [16项逐轮表](16-program-round-status.md)：区分 test、小输入、正式 r1/r2/r3、失败、运行、未定义、软件阻塞。
- [正式样本 JSON](accepted-formal-samples.json) / [CSV](accepted-formal-samples.csv)：逐样本 cycles、Host时间、有效性、原始证据与身份/结果/完成标记哈希；缺失指标为空，不估计。Native checker 指标不适用。
- [前25样本保留审计](preserved-formal-results-audit.json)：既有有效结果和完成标记未覆盖。
- [进程与CAD快照](final-process-cad-snapshot.json)、[原队列任务快照](experiment-snapshot.json)。

## C4 非侵入式诊断结论

仍在 `design_1_firesim_wrapper_0_0_synth_1 / synth_design`。Vivado worker PID **11088**、启动 tick **10629**；真正计算线程 **11091** 为 R，主线程等待 futex，第三线程 select。RSS **18,863,956 KiB**，swap=0；CAD cgroup 无内存限额，memory.failcnt=0，系统可用内存约278 GiB，未见 OOM/崩溃证据。

既有5分钟观测的 CPU 从 **11,622.00 s** 增至 **11,921.80 s**、**12,221.62 s**；最终只读快照为 **12,264.06 s**。但这不是阶段推进的证明。两次19 Hz、12秒的 perf 采样均进入 `librdi_synth.so` 的 **HOptDfg::mergeReconvergentPartitionsFromPin / mergeReconvergentPartitionsForGraph**，表明确实在数据流图合并优化。采样没有暂停或重启目标。

**runme.log / 当前 .vds 从 01:41:22 UTC 到最终快照仍未更新，无新主模块 DCP/完成标记，尚无 .bit。** 因而可确认在执行优化，不能确认阶段前进、收敛或完成时间，也没有足够证据宣称死循环。保持原综合运行，未改变 watchdog、内存或空间守卫。

证据：`../../cad-diagnostics/synth-worker-20261109T0438.{perf,txt}`、`...T0444.{perf,txt}`、内核/dmesg错误筛查文件、`../../cad-runtime-progress-observations.jsonl`。CAD工作盘仍有约331 GiB，不是当前存储瓶颈。

Opt4 首验链仍等待严格绑定 source_id `c9f51d3a94aac7783c750682162cd25e9d1460b04974bde9b7541f1d9f4120e7` 的最终产物。原软件检查返回 `SOFTWARE_AND_NATIVE_BINDINGS_VALID`、fpga_access=false。产物完成后须认证 commit/source/hash，等21卡当前样本安全结束并取得21维护锁，再按原链执行 smoke、Blackscholes test/simsmall、真实 checker比较/任务匹配/排空/零故障/输出与ROI门；这些通过才允许正式 Opt4 采样。没有旧 Opt4 bitstream 替代。

## Receipt 不一致：原因与实际修复

Builder 重启把 PID、boot_id、时间、active_log 与后续 readelf/字节相同 hooks 重编命令写进 mutable receipt，导致整份 JSON SHA 变化。旧 SHA `eb8c7b23...` 与当前 `1771028d...` 的**实际6个ELF、4个栈库、依赖和patch全部匹配**，语义字段相同；不是硬件版本变化。[精确差异](binding-reconciliation.json)。

新增 `scripts/network_binding.py` 对实际文件哈希、全部语义字段和允许的诊断命令逐项验证后，复用最早不可变构建收据。实际软件/配置变化保留新身份；错误 ELF 哈希及真实 port_version 变化的负向验证已拒绝。没有改写原收据、失败证据或正式样本。

已恢复/复用独立软件服务 network-candidates、network-offline、network-followup、network-ferret-reference、network-linux、network-streamcluster-linux；均已收齐证据正常退出，不将服务 COMPLETE 当作各 case 通过。新的 Netferret 诊断也只用原 job_service 托管；single-instance lock、持久日志、PID/start tick/boot_id 和逐 case 原子状态保持。原 FPGA/CAD/调度服务代码和unit未改。

## 三个网络程序实际达到的阶段

|程序|本轮实际成果|尚未完成|
|---|---|---|
|Netdedup|修复收据复用；逐项核对 framed 候选的 test/small/formal Linux 既有通过证据，完整解码与输入一致；实际链接原位置的 ec_dac_roi hooks，保存新 ELF/hash|新真实hooks ELF未上板；完整原ROI的线程/syscall/context兼容路径、正式镜像和FPGA门未通过|
|Netstreamcluster|当前ELF/输入绑定核对；test/small/formal Linux精确输出证据复用；实际链接原位置的真实ROI hooks|真实checker动态兼容未验证，不能把诊断hooks成功当作通过；本地simmedium实际映射simlarge，保持原工作量|
|Netferret|定位MAXFLOAT空槽被误当邻居的断言；原文件系统查询顺序导致的SHA不匹配；独立候选保留全部查询，增加确定次序、listen就绪握手及ROI外cancel后的join；最新候选完成三种输入QEMU user/Linux验证|新候选未正式采用/入队；旧候选test退出134保留。原ROI线程/context问题仍存在，真实checker未验证|

Netferret 最新独立profile为 `netferret-stable-joined-candidate/1`。Linux test/small/formal 两端均exit0，原ROI BEGIN/END完整，分别 **1 / 16 / 64** 条查询无遗漏/重复，完整文件与该profile QEMU user逐字节同SHA。small/formal的每条查询所有排名和值也与独立原RISC-V socket参考一致；test明确去掉原版MAXFLOAT空槽错误打印，保留真实邻居。这是明确标注的修复profile，**不与旧软件结果混算**。

原Linux检查器绑定旧profile的整文件SHA，所以其原 `FAILED_WITH_EVIDENCE` 收据未改写；新profile的独立严格复核另存 [offline-review.json](netferret-stable-joined-candidate-offline-review.json)，同时绑定候选ELF、输入、QEMU user参考、原socket逐查询参考、完整console、退出状态和输出哈希。更早无join候选的 test exit134 与 instrumented probe 的成功都保留，不能由一个成功probe证明退出异常根因；线程取消未等待即释放资源是源代码可证的生命周期缺口，添加join后本轮三个case均正常，但没有宣称已经证明原exit134的唯一原因。

新真实hooks候选 Netdedup server SHA `b65cad95447a164c03c0736c56b2088ad0d7656502beb74d340900e2bb1614c1`；Netstreamcluster server SHA `cb985b8a39742665c15c0f1027cdde39e32c2afbdfb6302cf253bc289fa981ae`。绝对路径、client/hash、hooks对象与链接命令见 `/data1/gzh/EC/firesim/final-opt4-20261106/software/network-runtime-candidates.json`。这些保持 `formal_eligible=false`，不伪造正式软件就绪。

三者共同的真实限制见 [ROI admission audit](roi-admission-audit.json)：C4驱动 `ec_dac_roi.c:234` 拒绝多线程进程；`DacRoi.scala:76` 在ROI内trap/非U特权/satp变化记fault8；原应用/user-TCP区间确实含线程、clone/futex/nanosleep等操作。**收据问题已在CPU上解决，但换hooks本身无法解决原ROI协议。** 未关闭checker、屏蔽fault、移除校验或缩减有效计算区间，也未改冻结DUT。

网络程序进入原自动队列的条件：完成支持整个原ROI的上下文/系统调用接入，绑定同版本apps/rootfs/两组firmware，再做板级小输入真实比较与排空验证。没有创建会让缺项被误判就绪的正式收据；不让它们阻塞其他13项。

## 断线恢复与版本证据

先读 `jobs/<name>/state.json`、领域状态和console；用PID、start_ticks、boot_id核验。活进程只接管监控；确认退出后复用完整case和精确哈希，失败/中断重新验证，新profile单独目录。统计快照不是执行检查点。软件新任务 nice15、每个QEMU 2GiB，未扩大FPGA调度。

原始补丁/收据/日志均保留。`software-service-changes-final.patch` 与 `final-source-sha256.json` 记录本轮软件变化；所有正式结果继续由原发布器和收数器实时写入 Experiment。没有将离线验证计入26个正式样本，也没有用宿主耗时计算体系结构slowdown。
