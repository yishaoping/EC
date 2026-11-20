# 网络 PARSEC 软件准备证据

**2026-11-09 15:36 UTC Native 已实际恢复上板：** 三项 Native 软件接入齐备，原 coverage-first 自动执行 Netferret test 并有效通过（ROI 4,537,692,629 cycles，Host 634.39 s，非正式样本），随后自动开始 Netdedup test。Native 允许原线程/syscall；C4 的单上下文/陷阱限制不能套用到 Native。详见 [Native 实跑、版本与恢复入口](NETWORK_NATIVE_RUNNING.md)。没有修改冻结硬件、现有调度服务、正常CAD作业或e2。

**2026-11-09 12:49 UTC 新增实测：** 三项最新候选再次实际完成保留完整原ROI的QEMU test：Netdedup全解码与输入相等；Netferret/Netstreamcluster完整输出精确匹配既有参考。新增[完整ROI诊断收据](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/network-complete-roi-probe.json)保存ELF/hash、私有命名空间日志、逐case结果和真实hooks Netferret候选。实际trace仍有clone/futex/clock_nanosleep等；驱动多线程拒绝、固件只安装一次且无pause/resume、checker异常fault+park、monitor fault8共同阻止现有C4软件分epoch绕过。没有缩ROI/屏蔽fault/改冻结硬件。详见[当前恢复与协议报告](ferret-vips-recovery-20261109.md)；本轮软件服务正常完成，但未把离线成功计入FPGA。旧失败全部保留。

**2026-11-09 更新：** 版本绑定故障已修复，独立软件服务已恢复；Netdedup framed / Netstreamcluster Linux 三输入有效证据已核验。Netferret 新的 `netferret-stable-joined-candidate/1` 已完成三输入 QEMU user/Linux 全输出及独立原socket逐查询数值复核，原失败保留。三项仍受完整原 ROI checker/context 协议限制，尚非正式 FPGA 就绪。真实路径、ELF/patch/hash、逐case结果和剩余条件见 [最新实测报告](network-recovery-20261109T043612Z/REPORT.md)；下文为2026-11-07历史快照，不以它替代最新case证据。

快照时间（UTC）：2026-11-07T11:20:16.579282+00:00。这些结果均不是 FPGA 正式样本。冻结硬件未改变。

| 程序 | 已实际完成 | Linux guest | C4/FPGA 入队状态 |
|---|---|---|---|
| netdedup | RISC-V 静态 server/client ELF；test/simsmall/正式映射均完成；完整解码与输入一致，x86 压缩输出相同 | test: FAILED_WITH_EVIDENCE；simsmall: FAILED_WITH_EVIDENCE | 未进入正式执行；原 ROI 的多线程/trap 协议未解决 |
| netferret | RISC-V 静态 server/client ELF；test/simsmall/正式映射均完成；完整输出与同 RISC-V 原 socket 参考逐字节相同 | test: FAILED_WITH_EVIDENCE | 未进入正式执行；原 ROI 的多线程/trap 协议未解决 |
| netstreamcluster | RISC-V 静态 server/client ELF；test/simsmall/正式映射均完成；完整输出与同 RISC-V 原 socket 参考逐字节相同 | test: LINUX_PROTOCOL_AND_EXACT_OUTPUT_PASSED；simsmall: LINUX_PROTOCOL_AND_EXACT_OUTPUT_PASSED；simmedium: LINUX_PROTOCOL_AND_EXACT_OUTPUT_PASSED | 未进入正式执行；原 ROI 的多线程/trap 协议未解决 |

完整 ELF/输入/补丁哈希、命令和各级原始证据：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/network-preparation-summary.json

## 版本与测量边界

v2 共享内存 SPSC ring 使用 acquire/release 发布消费顺序，原始 PARSEC 应用计算源码和 ROI 保留。ELF 使用诊断 hooks，不能用来提交真实 checker 样本。旧 v1 与 v2 的 trace 失败证据保留。
Netdedup 的原始 server CLI 与 client 文件名有接入缺陷，候选显式拆分，仍使用原 test/media.dat 文件。Netstreamcluster 必须保留本地 simmedium 实际调用 simlarge 的正式工作量。Netferret 使用原网络 pthread pipeline。
跨 x86 的差异不以放宽容差判通过；Netferret/Netstreamcluster 采用同 ISA、未改计算源码的原 socket 参考完成精确比较。单核 Linux 的实跑结果另存，不能用 user-mode 成功覆盖 Linux 失败。

Netdedup 独立 graceful-close 候选及 Netferret 独立 framed-I/O/end-tag 候选都已完成 QEMU user test/simsmall/simmedium，输出与 v2 一致；这些是新软件版本的证据，未正式采用。Netdedup 单靠 linger 仍未证明 Linux 可完成，且上游 _sleep 忽略 timo，不能声称其内部超时有效；外层 guest 超时仍生效。Netferret 新候选 Linux test 已观察到 t_out 的 obj != NULL 断言，根因未证实，不屏蔽断言/丢弃结果。各候选补丁、ELF 哈希和独立 Linux case 状态在 JSON 的 independent_repair_candidate 字段。

## 确认的 C4 接入限制

驱动 /data1/gzh/EC/firesim/final-opt4-20261106/software/C4/linux/drivers/misc/ec_dac_roi.c 的 dac_begin 明确要求 get_nr_threads(current)==1；网络栈/应用会创建线程。ROI 监测 /data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/rocket-chip/src/main/scala/util/DacRoi.scala 对区间内 trap、非 U 特权或 satp 变化记 fault 8。保存的诊断已观察到实际 clone/futex/nanosleep，不能去掉守卫或屏蔽 fault 当作兼容。
仅将 I/O/网络搬出原 ROI 或把 pthread 换成别的算法不能提交原实验。需要完整原 ROI 的可证明 checker context 路径，之后绑定真实 hooks、rootfs、两组 firmware，再做 FPGA smoke、小输入、真实比较/排空和正式采样。当前不生成会误触发队列的正式 apps/rootfs/firmware 收据。

## 持续作业与重连

软件作业复用现有 job_service：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/jobs/network-*/{state.json,console.log,startup-audit.json}。正常 FPGA、CAD 和调度服务未改造、未重启。
Linux 持续状态：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/network-linux-validation.json 与 netstreamcluster-linux-validation.json；单核 Netdedup 收尾诊断：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/network-linux-probe.json；独立排空候选：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/netdedup-linger-preparation.json 与 netdedup-linger-linux-validation.json；Netferret：netferret-protocol-preparation.json 与 netferret-protocol-linux-validation.json。
重连先核对 PID、start_ticks、boot_id；存活作业只接管监控。每个完整 case 的 result.json 为软件验证检查点，确认退出后才补缺项；失败证据留存。统计/诊断快照不是指令级检查点。
全套 16 项逐轮进度继续由现有服务维护：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/COVERAGE_STATUS_LIVE.md 和 coverage-status-live.json；C4 综合状态为 /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/C4-runtime-cad-state.json。
全套 16 项已登记，13 项有正式软件绑定。网络三项在真正软件/ROI 条件满足后由原 coverage-first 动态读取正式收据，不另起第二套队列。C4 bitstream 通过版本/哈希认证后仍走既有 first 验证链，成功才放行后续正式队列。
