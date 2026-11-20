# 持续实验只读检查：2026-11-09

证据快照：2026-11-09T05:54:43.726516+00:00（北京时间13:54）。本轮只读核验和追加本目录证据；没有停止、重启、重排、重复启动 FPGA/CAD/调度任务，没有硬件、驱动、输入或软件profile修改。

## Native / Opt4

Native **27/48** 个有效正式样本，**11/16** 项至少正式首轮通过、**8/16** 项三轮齐备。Opt4 **0/48**，有效配对 **0/16**。本轮新增 X264 simmedium r1，严格核对当前软件/硬件身份与 result/complete 哈希，未以进程结束代替有效性。

- ROI：**34,722,053,946 cycles**。
- Host wall：**2274.046998 s**，单独的宿主仿真吞吐率 **16,653,503.599 target cycles/s**；它们不作为体系结构slowdown。
- 应用退出0、capture退出0、`eledream.264: OK`、guest output_valid=1、driver退出0、timedout=false、issues=[]，原子完成标记与身份匹配。
- result：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-x264-simmedium-r1-20261109T043328Z/result.json；SHA256 `3d48975c83b7f15d54324ac9ae14c269a3ac681ca123b005e3abff9b731f37d9`。

当前 **Facesim simmedium r2**，PID **1535084**，start_ticks **1280560**，设备 **0000:21:00.0**。直接进程身份核对匹配；heartbeat 多条累计tick持续递增，原始ROI running、faults=0、无ROI_END。它仍在运行，尚未计为有效样本。当前UART没有持续打印本身不代表停止，heartbeat和源BOOM tick仍推进。

X264 r1 结束后，原调度已自动接续 Facesim r2。按实际执行计划读取顺序，当前样本结束后的候选为 **Raytrace r2 → X264 r2**，之后补三轮；若最终C4先就绪则原链在安全边界优先首验。上一轮根据priority排序给出的下项顺序与实际主循环plan顺序不同；本报告以实际已执行任务和主循环顺序为准，没有调整正常调度。

Native Ferret simsmall 的既有输出SHA失败、Vips test的既有Kernel stack overflow仍明确保留，其各自后续正式轮次被功能门挡住；三个网络项仍软件阻塞。没有新失败、超时、重复活实例或新异常证据；已有失败未被静默丢弃。

逐轮状态：[16-program-status.md](16-program-status.md)。完整27样本的周期、宿主时间、配置、ELF/输入/rootfs/bitstream/ROI身份和原始证据：[formal-samples.json](formal-samples.json) / [CSV](formal-samples.csv)。原始结果未改写，未采指标为null。

## C4：阶段实际推进已经有证据

原 worker 11088/start10629 仍在，计算线程11091为R。低频自动观测最近时间 **2026-11-09T05:53:37.236963+00:00**，累计CPU **15219.75 s**，RSS **34,095,284 KiB**。05:51直接内存审计RSS约29.1 GiB，05:53自动观测约32.5 GiB；swap=0，cgroup峰值约35.3 GiB，memory.failcnt=0、oom_kill=0、under_oom=0；系统MemAvailable约214 GiB，memory PSI平均值0。没有当前内存不足或崩溃证据。

**与05:04前的判断不同，现在已经能证明synth_design内部阶段推进。**

- `runme.log` / 当前 `.vds` 最新修改为 **2026-11-09T05:49:18.526835Z**；分别从旧快照 **231040 / 62142 bytes** 增至本快照 **242713 / 73815 bytes**。
- 工具明确输出 `Finished RTL Elaboration`：工具报告cpu=03:41:22、elapsed=04:00:31。
- 随后输出 `Finished Handling Custom Attributes`、`Finished RTL Optimization Phase 1`：工具报告cpu=03:49:18、elapsed=04:09:17。
- 这些是实际完成事件，强于CPU时间或RSS变化；前一轮长时间的 HOptDfg 图合并热点最终产生了后续完成日志，不能继续称作同一处持续无阶段进展。
- 仍无最终 `.bit`；尚未证明完整综合结束、布局布线完成、资源适配或时序收敛。

风险判断：本次约四小时静默不能据此判死循环，现有明确阶段完成证据使立即重启没有依据。日志中仍有RAM dissolved into registers及接口宽度等综合warning，最终资源/时序需以后续报告确认，不能仅据warning判失败或宣称可装入。保持原任务、watchdog和资源守卫；已有cad-monitor每300秒继续记录CPU/RSS，原Vivado日志持续落盘。若后续再次数小时无完成事件，应对照本次阶段基线、文件变化与热点定位后再判断；本轮不新增诊断服务或修改综合参数。

本目录保存原日志快照、阶段行、文件metadata及14次CPU/RSS自动观测，见 [cad-file-evidence.json](cad-file-evidence.json)、[process-memory-audit.json](process-memory-audit.json)。工具的阶段cpu时间与/proc的进程cpu时间各自保留，不混合为同一计时原点。

## Opt4 自动启动链已核对，当前等待正确产物

coverage-first、Native、CAD、c4-first、c4-suite、cad-monitor、publisher均 active/running，服务启动时间未变化。c4-first PID71732/start267293匹配，领域状态 WAITING_FOR_EXACT_C4_BITSTREAM。

现有代码认证冻结commit `8491167d84b6d9521b151a743673c1516926a1f8`、source_id `c9f51d3a94aac7783c750682162cd25e9d1460b04974bde9b7541f1d9f4120e7`、实际bitstream/receipt的SHA；要求BUILT_NOT_RUN、certified_bitstream和returncode0。Native主循环在CAD就绪后YIELDING_TO_C4_FIRST_DEPLOYMENT，不再抢开新样本；已运行样本继续持有21维护共享锁。

首验等待21安全边界并取得21独占维护锁，再由board_batch重新核对，严格只允许0000:21:00.0。随后smoke → Blackscholes test/simsmall → 正确输出、真实checker比较、任务匹配、排空、零故障和有效ROI → 正式样本；覆盖服务还有matching-smoke/正式完成门。没有Native/Opt4同时占用同一卡的合法路径，没有为此执行部署。全局操作和e2仍被禁止。旧注释提及global maintenance不代表实际动作；实际board_batch入口及既有21-only安全实现仍以单卡目标和锁约束执行。

## 网络软件：保留成果，分析接入边界

三个网络候选、ELF/hash、Linux验证和原失败证据保持；本轮没有重编、改profile或创建正式收据。上一轮最新Netferret三输入独立离线复核仍是非FPGA结果。

源码确认的冲突：`software/C4/linux/drivers/misc/ec_dac_roi.c:234` 在BEGIN要求get_nr_threads(current)==1；`DacRoi.scala:76` 在running或ended且busy时遇trap/非U特权/satp变化记fault8。原user-TCP/pthread ROI包含真实计算、线程创建/同步和收发；现有单核Linux不能靠把线程数参数设为1就消除实际线程。

**当前没有已证明可用的轻量软件适配。** 初始化、纯辅助计时可以在保留语义和统一测量下独立处理，但真实clone/futex/调度/收发不是可静默移出的辅助操作。把线程提前创建仍会在BEGIN被拒；ROI内创建又会触发trap；仅换hooks、去掉guard或屏蔽fault不构成兼容。保留原内核线程/系统调用执行方式时，需要能容纳完整上下文切换和校验排空的协议路径；不能声称现有冻结接口已支持。纯用户态协作执行是否能保留原工作负载与完整ROI尚未证明，属于大规模软件适配，本轮按要求不实施，也不据此断言一定必须修改冻结DUT。

需要真实FPGA确认的部分包括：完整原ROI的真实checker路径、任务逐项对应、跨上下文状态、完成/排空、fault=0及精确输出。QEMU协议/输出成功、真实hooks链接成功不能替代这些。网络阻塞不影响其他就绪benchmark自动运行。

## 本轮操作范围

只读检查进程/身份、单卡运行日志、原调度入口、C4日志/文件/内存，以及追加本目录报告与数据快照。没有启动或停止任何实验/软件/CAD服务，没有修改正常调度、冻结硬件、驱动或活样本输入。当前没有需要立即干预的新增故障。原服务保持自动运行和实时数据提交。
