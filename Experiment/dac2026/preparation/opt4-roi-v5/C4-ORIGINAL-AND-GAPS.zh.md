# C4 原始运行方式与最短依赖链

本次只读审计，未启动仿真、Linux、checker 或 benchmark。当前 C4 工作树没有修改。
证据及文件 SHA256 在 `c4-original-audit/evidence.json`；历史 ELF 的完整反汇编也保存在该目录。

## 1. 原先验证的是裸机

冻结身份目录 `/data1/gzh/EC/slowdown/opt4`，硬件源实际在 `/data1/gzh/EC/chipyard/generators`，
入口 `/data1/gzh/EC/slowdown/run_optimization_4_svb.sh`，目标 `chipyard.v1Config`。
功能提交 `476a760910f3bfbd3c111000ebe40343870ab439`，冻结提交 `962c4b87db2a810bc025a87f5f7289dd7aedc5cf`。
当前 EC HEAD `2ea467ba08f773dd55b77383da9f4f5c025b9607`，本次复查 tracked 未提交修改为空。

直接运行证据：

- `slowdown/opt4/reference/original_run_manifest.json` 的 commands 使用 Chipyard Verilator Makefile 和 `CONFIG=v1Config`，
  software 为 `test.riscv` / loadmem，`simulation_status=SUCCEEDED`、`exit_status=0`、`benchmark_status=PASS`。
- 对应 ELF 的实际 SHA256 为 `da8897e790f0c5e91eff3e9560d2b0e7b4e1de6dff208788fb4d9e2ae462c81c`。
  实存位置为 `/data1/gzh/EC/check/software_common_builds/gapbs512_20261023_03/test.riscv`。
  这里只读核验了当年 Opt4 共用的软件输入，未接入、复制或构建 check 硬件。
  manifest 中已失效的 `/baseline/...` 路径不能当作目前可用文件。
- ELF entry=`0x80000000`，有 `_start`、`_start_secondary`、`__main`、`checker`、`tohost/fromhost`；
  checker 反汇编的 `0x8000172c`、`0x80001730`、`0x80001734` 分别对应原 RoCC AS-R、monitor、GO，
  `0x80001814` COPY、`0x80001818` 自定义跳转进入重执行，`0x800017e8` RELEASE。
- `original_stdout.log:2` 为 checker_mask=0xf ready；`:6` 为 BFS `verified=1 parent_checksum=43439728`；
  `:7` 为 ROI cycles=1707863；`:8` 为 `checker_software_ready=4 cache_drain=UNRESOLVED`；`:10` 为 END PASS。
- `Software/Test/compile.sh` 采用 unknown-elf GCC、libgloss `htif_nano.specs`、静态链接，入口来自 libgloss。
  当前源码与历史 ELF 不是相同软件修订：例如历史 ELF 只写 ready，当前 secondary 会读 traffic counters。
  因此对历史执行指令的结论以保存的 ELF 反汇编为准。

这些证据证明历史裸机 BFS 已运行并通过计算正确性检查，未证明 Linux/PARSEC。
历史 manifest 的 `overall_validation_status=PARTIALLY_VALIDATED`，并记录 cache shadow S0 sanity 失败；
stdout 自身也明示 cache drain 未解决，不能把 END PASS 当作全部缓存/持久化排空证明。

也检查了现有 `Software/R-Kernel-singleboom`、`Software/gap测试备份` 和 embench 的 checker 入口：
R-Kernel-singleboom 的 compile.sh 同样采用 unknown-elf/HTIF，tasks.c 仍是同类 RoCC 裸机 checker。
`Software/R-Kernel` 目录为空。没有据目录名把这些代码认作 Linux kernel/service，亦未混用旧实现。

## 2. 原 checker 的实际工作链

以下 Scala 路径相对于当前隔离 C4 工作根：
`/data1/gzh/EC/firesim/dac2026/work/opt4-alveo-v3/C4/chipyard/generators/rocket-chip/src/main/scala`。

| 阶段 | 已存在的实现与证据 | 语义 |
|---|---|---|
| 多 hart 启动 | `chipyard/toolchains/libgloss/misc/crt0.S:94` 按 mhartid 建 TLS/stack，`:115` 分 secondary；`crtmain.S:22` 调 `__main` | 同一个裸机 ELF 同时运行于 BOOM/Rocket，无 Linux secondary service |
| 初始化 | `Software/Test/cfg/init.c:r_ini` 配四路 mapper、filter、scheduler、mask=0xF；`secondary.c:__main` 仅 hart1..4 | hart1..3 配软件/定时器中断，hart4 直接进入 checker |
| 准备 checker | `Software/Test/core/checker.c:checker` 的 AS-R、monitor、GO、INITIALISED、ELU 自检 | 原有 RoCC 控制接口，不能替换成空循环 |
| 任务与上下文 | BOOM/R_IC 产生带 seq 的任务；GHT/GHM 传 data、CPS/ECP、ARF/CSR；`RocketCore.scala:1032`、`:1089`、`:1125` 解码并交 RSUSL/CSR、COPY | CPS 为起始检查点，ECP 为结束检查点；不仅是软件指针 |
| 执行 | 原软件轮询 RSU_READY，COPY 后自定义跳转；R_ICSL 控制重执行/异常/返回 | 软件管理入口与真正被检查的指令流已存在 |
| 完整比较 | `RocketCore.scala:1451` package_data_complete 要求 producer seal、稳定 ingress drain、LSL quiescent、ARF 完成和所需 CSR 比较；`:1459` 再要求 package_exec_done | 重执行指令数达到边界不足以判完成 |
| 结果传递 | `RocketCore.scala:1521` 起按 seq 形成 PASS/FAIL/CANCELLED，背压时保持 valid；`:1553` 等本地 cleanup 后 handoff | full_check_complete 也可能产生 FAIL，必须检查 status；不能仅以 completion pulse 宣称 PASS |
| BOOM 接收/释放 | `GHM.scala:553` 起结果 CDC 到 BOOM；`:565` dequeue fire；`:575` 保持 release 到 BOOM ic_status 清零；BOOM `lsu/dcache.scala:2515` 起按 seq 接收并区分失败/取消，`:2744` 起统计生成/完成/PASS | Rocket 比较、CDC 接收、BOOM 释放为不同事件 |
| 会话结束 | 软件等 GHT status=2，RELEASE 后写每 hart ready 并永久 idle | 会话完成位与软件 ready 不能代替逐 package 比较成功或 BOOM 资源释放 |

## 3. 已有功能与真实缺项

已有且应复用：四 Rocket 配置、任务编号、CPS/ECP/ARF/部分 CSR 保存与比较、重执行、LSL、producer seal、
最终比较、结果背压队列、结果 CDC、BOOM 所有权释放、PASS/FAIL/CANCELLED 统计。当前 C4 的参数、elaboration、
GoldenGate 和 native U280 driver 已通过编译，最近 driver receipt 为
`Experiment/dac2026/build-logs/opt4-alveo-v3/C4-driver-20261102T072755.964947Z/result.json`。

当前 Linux 链路确实缺少：

1. **checker 启动/所有权**：现有 OpenSBI generic 没有调用这套 checker service；当前只打包过 B 的单核 Linux payload。
   需要在 C4 的 firmware 工作副本预留 hart1..4 及服务入口、栈、陷入处理、内存区域，并保证它们不作为应用 CPU 使用。
   不能直接拿旧 ELF 的 `__main` 当作 Linux 下已运行的 service。
2. **可执行地址空间**：`rocket/Instructions.scala:1551` 起的 shadow 集没有 satp/stvec；`CSR.scala:1207` 的 PTBR 来自本地 reg_satp；
   `Frontend.scala:269` 起 checker 仍用本地 privilege 和 TLB/PTW。`GHE.scala:220` 的 satp PPN 只是被监测进程匹配，
   没有把 Linux 页表根安装给 Rocket。必须定义并实现完整 satp mode/ASID/PPN、执行权限、页表生命周期和失效顺序。
   是否可用现有 CSR 写入路径完成，须结合 firmware 保护的 M/S 地址映射验证，不能预先宣称必需扩包。
3. **特权切换语义**：`CSR.scala:1328` 原注释明确“只是为了verilator实验，实际boot linux，这里应该切到S-mode”，
   实际代码仍 `new_prv := PRV.M.U`。`:1407` 的 check_priv_ret 又依赖本地 mstatus/mpp。
   这涉及架构语义，不是多一层 while 或邮箱即可修复；也不能孤立把 M 改为 S 就宣布完成。
   必须一起确定本地 firmware trap、被检查的 Linux trap/return 和 shadow CSR 的归属。
4. **Linux BEGIN/END/DRAIN 接入**：当前 `measurement/linux/ec_dac_roi.c` 是 B-only，明确拒绝 checker。
   需要把受控、固定 mm 的最小会话接到已有 GHT/GHE 控制和 package 结果，END 后继续接收完成与排空，失败/取消必须使样本失败。
   最初可只支持单 hart0、单线程、固定 mm 的短程序；不把通用多会话、全部图表列为首次条件。
5. **C4 观测接线**：C4 v3 尚无 B v5 的 raw ROI bridge/控制设备；需在 C4 的新工作副本接真正 ROI、生成/完成/PASS/失败、
   outstanding 与 BOOM release。B-only 设备中的零计数实现不能移到 C4。
   现成 traffic 计数也有窗口条件：BOOM `dcache.scala:2492` 的 measuredPacketAlloc 受 trafficCounting 控制，
   `:2746` 的 completedPackages 按所有 accepted result 累积。复用前须在干净会话边界建立相同任务集合，
   保留结束后完成通知，并禁止带 live package 时复位统计（`:2727` resetBoundaryInvalid）。
   不能关闭正确性检查来掩盖窗口不匹配，也不能把取消归入成功完成。

没有观察到“Linux 首先在哪一条指令 fault”的真实记录；以上为静态缺项和未接通接口，不能伪称已运行失败或已修复。
本次没有重设计新的 checker 包协议，没有写入模拟完成或测试替身。

## 4. 最短依赖链

**C4 硬件诊断的最短入口**可以沿用原真实裸机 ELF 与原 checker：绑定到当前 C4 生成产物 → 最小观测真实 PASS/FAIL/生成完成数 →
C4 bitstream 与安全部署 → 用户运行。这样可先确认 FireSim 上的原校验通路，但该入口不是 Linux/PARSEC，也不能与 B Linux 数据相除形成论文 slowdown。
历史 ELF 自身的 software-ready/cache_drain=UNRESOLVED 输出不足以替代新增的真正完成观测。

**C4 第一次 Linux 有效短运行**必须完成上面 1–5 的最小子集 → 编译 C4 firmware/Linux/短程序与 C4 目标/转换/driver →
构建 C4 bitstream → 安全部署后由用户执行一个最小真实任务，要求 generated>0、completed=generated、全部 PASS、无取消/失败、
实际 BOOM release、输出正确、host ROI 周期和日志完整。当前尚无这些新实现或真实运行结果。

**第一组有效 slowdown**随后使用同一静态程序二进制、输入、应用线程与共同 FASED 参数在 B/C4 各运行一次，
以 source BOOM ROI 周期相除；BOOM/uncore 均为 200 MHz。C4 排空单独记录，不能拿包含排空的时间替换 ROI，
也不能为了先得 slowdown 关闭正确完成判定。

严格 latency 不阻塞上述命令。接 C4 观测时保留 `seq`、首次完整比较且 status=PASS、result enq、result CDC deq/release、
producer seal 等事件接口；BOOM 真正执行完成时间戳及 store/fence/replay/flush/exception 覆盖随后单独完善。
现有 writeback 延迟计数与软件 ready 均不等于用户定义的严格 latency。

## 5. 工作分类

| 类别 | 工作 | 实际状态 |
|---|---|---|
| 阻塞 B 首次运行 | B v5 bitstream、两卡安全部署与准确 artifact 绑定 | bitstream 已实际进入 Vivado 综合；两卡均有现存 FireSim 任务，当前部署禁止；B 独立 launcher 已生成 |
| 阻塞 C4 首次 Linux 真实校验 | hart service、地址空间与特权语义、真实会话/完成接线、C4 软件/bitstream | 已定位代码和接口；未实现，未运行；旧 C4 四阶段构建证据仍有效但不能冒充这些功能 |
| 阻塞有效 slowdown | C4 首次校验通过；B/C4 同软件输入/内存/ROI；输出与完成数绑定 | B 最小 smoke collector/validator 已生成；C4 条件未满足 |
| 只阻塞 latency/完整实验 | 逐任务 BOOM 执行时间戳、共同时间原点、分位数；长期样本原子提交、缺项补跑、C2/C8、面积消融和图表 | 延后；不作为 B 首次运行条件 |

C2/C8 的具体位置继续采用 `preparation/opt4-alveo-v3/C2-C8-review.md`：R_IC 3-bit 目标号、R_RSU/GHM 包位段、
4-bit bitmap、GH_NUM_CORES、init mask/mapper、secondary hart 范围必须一起处理。尚未构建这两组 bitstream。
