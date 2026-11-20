# 网络程序 Native 实跑与恢复入口

2026-11-09：不改冻结硬件、现有 FPGA/CAD/调度服务，已补齐三个网络程序的 Native 软件接入。只运行 `0000:21:00.0` / `21770433G02LA`。正式三轮仍由现有 coverage-first 统一调度，顺序为 test → simsmall → simmedium 首轮覆盖 → 补 r2/r3；单项失败跳过，已通过的精确版本样本自动复用。

## 已发生的 FPGA 执行

- Netferret test 有效通过：`runs/native-netferret-test-r1-20261109T152353Z/result.json`，ROI 4,537,692,629 cycles，Host 634.38722867 秒。完整输出 SHA256 一致、server/client 都退出 0、ROI 原始事件完整、无 fault/timeout。`complete.json` 绑定结果 SHA256 与 identity；这是功能验证，不是正式性能样本。
- 上述样本完成后，原调度器自动接续 Netdedup test，并已有效通过：`runs/native-netdedup-test-r1-20261109T153429Z/`，ROI 5,435,376 cycles，Host 230.62746955 秒；压缩输出精确匹配、完整解码与输入一致、两端退出0、无fault/timeout，result/complete哈希已核验。随后自动运行 `runs/native-netdedup-simsmall-r1-20261109T153822Z/`（PID 1052971，2026-11-09 15:44 UTC尚运行中，不能记通过）。最终状态以目录内 result/complete 和实时矩阵为准。
- Netstreamcluster 已完成双进程启动链的 QEMU Linux test 精确输出验证，Native 正式软件绑定齐备，等待原队列。保留本地 simmedium 实际映射 simlarge 的完整工作量。

## 软件与测量边界

Native 的既有 ROI driver 没有 C4 的单线程拒绝，Native 观测器没有 trap/non-U/satp 的 fault8 路径。已经逐源码核对并记录哈希，不能把 C4 限制泛化为 Native 不可运行。Native ROI 周期包含原始 server hooks 之间完整网络计算、等待、Linux 调度和 syscall 的目标时钟区间，没有去除这些时间。

Netferret、Netstreamcluster 共用新 rootfs，来源为 `/data1/gzh/EC/firesim/final-opt4-20261106/software/network-native-20261109T151913Z/`。Netferret 沿用明确版本化的 stable-joined 修复 ELF，完整查询和排序数值参考保留。原真实 hooks 未换成诊断 hooks。

Netdedup 使用独立 `/data1/gzh/EC/firesim/final-opt4-20261106/software/netdedup-native-20261109T153251Z/` profile。被测 server SHA256 `b65cad95447a164c03c0736c56b2088ad0d7656502beb74d340900e2bb1614c1` 保持不变；server 正常退出/ROI 完成后，独立校验解码器全流解码并对原输入 SHA256，且压缩输出自身也要求精确 SHA256。解码器的诊断 hooks 不产生第二个真实 ROI，且不替代被测网络工作。首次离线验证发现解码触发第二对 hooks 的失败证据仍保留在第一份 profile 的 netdedup-wrapper-test.json，不改写。

两份镜像均复用原 Native 内核增量构建；除 initramfs 路径以外配置逐行相等，ec_dac_roi.o SHA256 相同。OpenSBI 使用既有 safe-FDT 地址 0xbfe00000，保持 mem=2G、FASED 和目标频率。没有重新构建/烧录 Native bitstream。每样本继续由原 run_isolated_sample 保存 UART、ROI、heartbeat、版本 identity 并原子提交。

应用 worker 参数为 1，原 user-TCP 服务线程和 Netferret pipeline 仍保留；不能把顶层 threads=1 解读为进程只有一个线程。case 的 thread_definition 记录了这一点。程序两端各有自己的日志/PID；guest watchdog 只终止本样本的两端，不用全局 pkill。

## 恢复与持续状态

- 原 FPGA 调度：`../coverage-first-state.json`、`../active-0000_21_00.0.json`、`../COVERAGE_STATUS_LIVE.md`。
- 软件准备状态：`network-native-preparation.json`、`netdedup-native-preparation.json`。
- 软件服务：`../jobs/network-native-preparation/` 和 `../jobs/network-netdedup-native/`，包含 startup-audit、state、console 和脚本输入哈希。两服务已完成，不能把服务 COMPLETE 当作 FPGA 正式通过。
- 源码与软件绑定快照：本目录 `network-native-bindings-*.json`，包含脚本、apps/rootfs/firmware 和首个有效 FPGA test 的哈希。
- 断线后先核验 boot_id、PID/start_ticks 和状态；活任务只监控。只有确认退出后才补缺项，不替换活 guest 的镜像或输入。

C4 综合继续原作业。网络三项 C4 仍缺完整线程/syscall/context 协议，未创建会放行它们的 C4 firmware receipt；不能屏蔽 fault、关闭 checker、缩减 ROI 或把 Native 通过冒充 C4 通过。最终冻结 C4 bitstream 认证后，原首验服务等待21卡安全边界并优先接管；软件准备服务没有设备部署路径。

## 2026-11-10 网络超时与接收线程收尾排查

Native现已42/48，Netdedup三轮齐备。Netferret simsmall和Netstreamcluster test返回124，均不得记通过。独立软件作业正在验证最小接收线程join候选，并修复失败日志不回传的问题；原队列/CAD/冻结硬件保持。证据和恢复入口见 [本次排查报告](network-native-wait-20261110.md)。实时状态以两个network-native-wait JSON与原coverage-first/active状态为准，不把离线通过当FPGA通过。
