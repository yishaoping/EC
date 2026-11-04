> 2026-11-04 最新诊断路线：旧 Linux smoke/C 等待链已主动停止并保留为无效；独立 36-bit 内核/固件/native 观测版本已构建，native C4 短验证真实通过 21 个任务（214.204 BOOM 周期/秒），新 Linux smoke attempt `20261104T092509.309639Z` 已顺序启动（32 MiB Linux cap、16 MiB sparse section、独立精简调试段 rootfs）；首个 36-bit 诊断 attempt 已保留并主动停止，Blackscholes 尚未运行。详见 `native-diagnosis-20261104/IMPLEMENTATION.zh.md`。C4 CAD 保持，未部署 FPGA。

# Opt4 C4 Linux / PARSEC v6 交付

## 2026-11-03 13:25 UTC：真实启动失败已修复，复跑中

旧 Stage B `20261103T040138.912938Z` 已判 **INVALID**，原始日志和退出状态保留。
退休指令和对应 ELF 反汇编证明：新增 SBI 扩展号 `0x09004f50` 与 OpenSBI
`ecall_vendor` 注册的 `[0x09000000,0x09ffffff]` 重叠，`sbi_ecall_init` 返回
`-3/SBI_EINVAL`；`init_coldboot` 进入 `sbi_hart_hang`，没有进入 Linux。
证据在该 attempt 的 `boot-failure-evidence.json`、`failure-diagnosis.json` 与
`verification.json`。这是固件启动错误，不是 checker 比较失败或 UART 静默推断。

已同时修正隔离 OpenSBI、Linux driver 和 checker-v6 参考代码中的私有 SBI ID 为
实验范围 `0x08004f50`，并在固件添加 vendor 范围编译断言。checker RTL、任务/比较/
CDC/释放语义、应用二进制和输入没有改动。新 HTIF 内核与 smoke/test 固件编译均通过：

- `native-HTIF-kernel-20261103T131553.567157Z/result.json`。
- `native-HTIF-firmware-20261103T132214.897538Z/result.json`（smoke）。
- `native-HTIF-firmware-20261103T132422.266455Z/result.json`（test）。

新 Stage B attempt 为 `linux/partial/20261103T132309.330455Z`，已启动，session `60723`。
新 Stage C attempt 为 `linux/partial/20261103T132500.630358Z`，已 prepare、未启动；
续跑 session `95198` 仅在新 B 原子提交有效完成结果后启动 test。
两者均使用同一修复后内核、同一 native RTL、rootfs、应用和输入，不复用旧失败日志。
旧 test `20261103T103553.695861Z` 的续跑因为其 B 无效而拒绝启动，保持原始状态。

C4 driver 和纯 CAD bitstream 构建对应的硬件源码没有变化，无需因 SBI ID 软件修复而
重新生成硬件。FireSim UART 内核/固件需要成对重建；正在推进独立 UART kernel 构建，
不会将 native HTIF 固件混入 FireSim。当前 bitstream 仍绑定其启动时的旧 B manifest，
部署前还须绑定新的有效 smoke 和更新后的 UART 软件；部署入口拒绝未通过的 native
smoke。没有 FPGA 部署或设备操作。Blackscholes 尚无真实有效结果。

## 2026-11-03 10:45 UTC 执行记录（优先于历史记录）

软件 RTL 仿真已获授权，由 agent 执行；FPGA 部署和设备操作没有授权。
下文 11 月 2 日的“待用户运行”、旧 UART attempt 和旧启动命令为历史记录。
当前 native 使用已存在的 HTIF/SBI 控制台，自动执行 guest 的真实
`manual-link.sh`、记录退出状态并同步、正常关机，不需要手动输入 guest 命令。

| 阶段 | 真实状态 | 证据 |
| --- | --- | --- |
| A：原 opt4 短任务 | **真实 RTL 通过** | `stage-A/partial/20261103T010323.872020Z/verification.json`、`protocol-evidence.json` 与对应 complete 标记 |
| B：Linux smoke | **正在执行，未验证** | `linux/partial/20261103T040138.912938Z/STARTED.json`、对应 raw 目录；尚无应用/任务结果 |
| C：Blackscholes test | **已构建并 prepare，未启动** | `linux/partial/20261103T103553.695861Z/manifest.json`；只有 B 提交有效完成结果才自动启动 |
| C4 native | **编译通过** | `work/opt4-linux-v6/native-build.json`，模拟器 SHA `9e3313dfb64b15cbc9d4ea4b811def22034b2f506424f10060f88db61f9f5a5f` |
| C4 FireSim driver | **编译通过，未运行** | `C4-driver-20261102T142123.460974Z/result.json` |
| C4 FireSim bitstream | **纯 CAD 构建已启动，未部署** | `C4-bitstream-20261103T105502.826002Z/command.json`，jobs/maxThreads 均为 2 |

表内结果相对根目录为 `/data1/gzh/EC/Experiment/dac2026/opt4-linux-v6/`；
构建日志根目录为 `/data1/gzh/EC/Experiment/dac2026/build-logs/opt4-linux-v6/`。

Stage A：generated=completed=passed=21，failed/cancelled/dropped/outstanding/timeout
均为 0；ROI 291811、drain 9552 周期。原始 SC1 事件按 seq 1..21 逐项核对
new/start/compare_done/result_fire/handoff_fire/CDC enqueue/dequeue 与 BOOM release，
不是仅凭 checksum 32704 判定。此结果属于原冻结 opt4 裸机配置，不能替代 Linux C4 验证。

Stage B 保持原 PID 3471636、原模拟器和原 attempt；最近保存的 BOOM 周期为
5497348（10:34 UTC）。退休指令已证明 OpenSBI 在 timer/FDT 初始化中推进，
无 Linux 用户程序或 checker package 的运行证据。控制台静默不作为死锁判据。
宿主持续保存 `raw/20261103T040138.912938Z/rtl.log.gz`、
`htif-console.log` 与每 5 秒刷盘的 `progress.jsonl`。不要重复启动此 attempt。

Stage C test DTB 与固件已经构建：

- DTB：`firesim/dac2026/images/opt4-linux-v6/native-htif/fdt-20261103T103501.949464Z/C4.dtb`。
- 固件成功收据：`Experiment/dac2026/build-logs/opt4-linux-v6/native-HTIF-firmware-20261103T103512.759847Z/result.json`。
- test aggregate identity：`08d3804acbb450922c7662e86887aab73910e7c0f61930510dc4b89b6d70b5a9`。
- test 和正在执行的 smoke 使用相同 native、内核、rootfs、apps；区别是版本绑定的
  `ec_dac_mode=test` DTB/固件及最大目标周期。smoke 的原始收据保存在其 manifest 内，
  不会被 test 的 latest 指针替换。

顺序续跑进程已启动，状态保存在 test attempt 的
`continuation-owner.json`、`continuation-state.json`；它通过 inotify 等待有效 smoke
完成标记，不查询进程表、不按定时器重复读任务状态。B 无效时 C 不启动；B 有效时调用
现有 `opt4_linux_run.py run`，结果保存在该 test attempt 和独立 raw 目录。
续跑原始输出为 `continuation-run.log`。当前 live session 分别为 B `66332`、续跑 `41063`。

当前仍不能声称 Blackscholes 通过，也不能计算 native C4/B FireSim slowdown。
Linux v6 仍限定单进程、单线程、同一 Sv39 地址空间、ROI 内无 syscall/异常/抢占；
原合成异常 M-mode 路径没有被改成 S-mode。超出范围由硬件 fault 位、driver 或 firmware
使样本无效；不吞 trap、不跳过失败比较。严格 latency、C2/C8、消融、面积和图表暂缓。

10:55 UTC：纯 CAD 入口支持绑定**正在执行**的 B manifest，显式记录
`linux_runtime_validation_at_build_start=RUNNING_NOT_VALIDATED`、
`runtime_validation=NOT_RUN`、`deployment_eligible=false`。真实运行验证与部署检查
不由综合结果替代。先前构建 `C4-bitstream-20261103T105421.649960Z` 因包装器预先创建
目标目录后 `copytree` 拒绝已存在目录而失败，尚未启动 Vivado；已保存失败结果，修复为
`dirs_exist_ok=True` 后创建新构建。当前 CAD live session 为 `62334`，不打开 FPGA 设备。

## 2026-11-02 当前状态

本节为当前权威状态，覆盖下文较早的进度记录。C4 native Verilator 已完成：`native-build.json` 的 `returncode=0`，source ID `e9d85c4c16ee4179d5451ad618a49c90cb6d61892063c73422f82560185a7b38`，模拟器 SHA-256 `9e3313dfb64b15cbc9d4ea4b811def22034b2f506424f10060f88db61f9f5a5f`。Smoke 与 Blackscholes `prepare` 均已成功，并创建下列 attempt；Stage A/B/C 都没有 `STARTED.json`、host 原始运行日志或 `verification.json`，状态仍是“已构建、待用户运行”。

依次启动：

```sh
cd /data1/gzh/EC
python3 firesim/dac2026/scripts/opt4_stage_a.py run --attempt /data1/gzh/EC/Experiment/dac2026/opt4-linux-v6/stage-A/partial/20261102T114242.905221Z
python3 firesim/dac2026/scripts/opt4_linux_run.py run --attempt /data1/gzh/EC/Experiment/dac2026/opt4-linux-v6/linux/partial/20261102T145135.113381Z
# Stage B 的 Linux shell: /opt/ec-dac/manual-link.sh smoke
python3 firesim/dac2026/scripts/opt4_linux_run.py run --attempt /data1/gzh/EC/Experiment/dac2026/opt4-linux-v6/linux/partial/20261102T145135.318045Z
# Stage C 的 Linux shell: /opt/ec-dac/manual-link.sh test
```

每个 guest 程序结束后执行 `/bin/busybox sync; /bin/busybox poweroff -f`。host run 每 5 秒保存日志和进度；请在各阶段运行后提供原始日志与 `verification.json`/完成标记，才能判定结果。

C4 FireSim v6 的 parameters/elaboration/GoldenGate/driver 已构建，source ID `bc340555ee99fbbf32e2fbc5930f1fa47a03a8e01338b714f1a5a2a22d2ab5eb`，FireSim 1.17.0 commit `07efa6a6da18bd64d1159ae84a4701b37abb1228`。静态参数比较 `parameter_comparison_passed=true`、B/C4 common cache/memory 差异为空；共同 FASED 为 LatencyBandwidthPipe、16 GiB、read/write latency=30、max requests=4、relax=0。`runtime_comparability` 仍是 `NOT_VALIDATED`。尚无 C4 `firesim.bit`。当前 bitstream 构建入口要求 Stage A 有效完成和 C4 Stage B smoke 的 `verification.json` 为 PASS；两份凭据齐全后才运行以下纯 CAD 命令：

```sh
python3 firesim/dac2026/scripts/build_opt4_c4_bitstream.py --goldengate-result /data1/gzh/EC/Experiment/dac2026/build-logs/opt4-linux-v6/C4-goldengate-20261102T134256.430246Z/result.json --driver-result /data1/gzh/EC/Experiment/dac2026/build-logs/opt4-linux-v6/C4-driver-20261102T142123.460974Z/result.json --stage-a-result /data1/gzh/EC/Experiment/dac2026/opt4-linux-v6/stage-A/complete/<attempt>.json --stage-b-result /data1/gzh/EC/Experiment/dac2026/opt4-linux-v6/linux/partial/20261102T145135.113381Z/verification.json
```

安全入口为 `scripts/opt4_firesim_c4.py`；其 `preflight` 只读 PCI/XDMA、进程和 FD，不打开设备。最新快照 [preflight-20261102T152019Z.json](/data1/gzh/EC/Experiment/dac2026/opt4-linux-v6/firesim/preflight-20261102T152019Z.json)，时间 `2026-11-02T15:20:56Z`：e2 卡运行 libquantum（PID 1970507），21 卡运行 hmmer（PID 2861930），另有 FireSim manager（PID 1967655）；当前用户有 4255 个 `/proc` 项不可见，`occupancy=BUSY`、`allowed_for_driver_start=false`，命令 exit 2。没有打开设备或操作 FPGA。FireSim 1.17.0 的 U280 `infrasetup_instance()` 会全局 `unload_xdma()`、flash、`load_xdma()`；禁止用 `infrasetup` 或 `enumeratefpgas` 绕过该阻碍。FireSim 自带 `fpga-util.py --serial` 可通过 Vivado JTAG 只选择一个序列号目标，但会要求整机 warm reboot；仅在两卡任务结束并获准维护重启后使用，当前也不可执行。native Stage C 通过也不能替代 FireSim 运行。

只有 bitstream 已构建且经单独审核的手动装载完成后，才使用以下 runner 入口。`prepare` 输出的目录代替 `<attempt>`；部署 JSON 必须包含目标 BDF/序列号、已加载 bitstream SHA、操作者、programming review、`other_card_idle_during_programming=true`、`both_cards_idle_at_driver_start=true`、两张卡的 reservation 和未过期的 `exclusive_until_utc`。当前两卡忙，以下 driver 命令不得运行。

```sh
sudo python3 firesim/dac2026/scripts/opt4_firesim_c4.py preflight --bdf <完整BDF> --out /data1/gzh/EC/Experiment/dac2026/opt4-linux-v6/firesim/preflight-<UTC>.json
python3 firesim/dac2026/scripts/opt4_firesim_c4.py prepare --bdf <完整BDF> --driver-result /data1/gzh/EC/Experiment/dac2026/build-logs/opt4-linux-v6/C4-driver-20261102T142123.460974Z/result.json --bitstream-result <新bitstream的result.json> --mode smoke
sudo python3 firesim/dac2026/scripts/opt4_firesim_c4.py run --plan /data1/gzh/EC/Experiment/dac2026/opt4-linux-v6/firesim/partial/<attempt>/plan.json --deployment-record <deployment.json>
# guest smoke: /opt/ec-dac/manual-link.sh smoke
python3 firesim/dac2026/scripts/opt4_firesim_c4.py verify --attempt /data1/gzh/EC/Experiment/dac2026/opt4-linux-v6/firesim/partial/<attempt>
python3 firesim/dac2026/scripts/opt4_firesim_c4.py prepare --bdf <完整BDF> --driver-result /data1/gzh/EC/Experiment/dac2026/build-logs/opt4-linux-v6/C4-driver-20261102T142123.460974Z/result.json --bitstream-result <新bitstream的result.json> --mode test
# fresh-boot guest test: /opt/ec-dac/manual-link.sh test
```

runner 每 5 秒 fsync `raw/<attempt>/console.log`、`opt4-events.jsonl` 和 `progress.jsonl`；driver 退出后验证任务与结果序号、真实 full comparison、ROI/drain、程序输出及 checker teardown。中断 attempt 留在 `partial/`，不会生成有效完成标记。

上板流程进一步核对：U280 manager 的默认 `infrasetup_instance()` 会 `sudo rmmod xdma`，禁止使用。FireSim 自带的 `fpga-util.py --serial` 分支经过 Vivado JTAG Tcl，只选择包含目标 serial 的一个 hardware target，不执行 PCI remove/rescan，也不卸载 XDMA；但该分支明确打印 “Please warm reboot the machine”。warm reboot 会影响整台宿主机，因此只能在两卡 workload 都结束、获准维护重启时由你手动执行。serial 参数按源码注释去掉末尾 `A`：BDF `0000:e2:00.0` 用 `21770433G001`，BDF `0000:21:00.0` 用 `21770433G02L`。

```sh
# 仅在两个现有 workload 全部结束、bitstream 已通过 receipt 核验、并确认宿主机可重启后执行。
sudo python3 /data1/gzh/EC/firesim/dac2026/work/opt4-linux-v6/C4/chipyard/sims/firesim/platforms/xilinx_alveo_u280/scripts/fpga-util.py --serial 21770433G001 --bitstream <certified-firesim.bit> --vivado-bin /tools/Xilinx/Vivado/2021.1/bin/vivado --hw-server-bin /tools/Xilinx/Vivado/2021.1/bin/hw_server
# 等待工具要求的人工 warm reboot；重启后以 root 做 fresh 双卡预检。
sudo python3 /data1/gzh/EC/firesim/dac2026/scripts/opt4_firesim_c4.py preflight --bdf 0000:e2:00.0 --out /data1/gzh/EC/Experiment/dac2026/opt4-linux-v6/firesim/preflight-<UTC>.json
```

只有 fresh preflight `allowed_for_driver_start=true`、`proc_permission_denied=0`，且双卡独占记录有效时才可继续。`prepare` 在普通用户下生成 smoke plan；随后必须用 `sudo python3 .../opt4_firesim_c4.py run --plan <attempt>/plan.json --deployment-record <deployment.json>` 启动 driver（runner 强制 root），guest 执行 `/opt/ec-dac/manual-link.sh smoke` 并关机。Smoke 有效后为 test 新建 plan，复用同一 C4 BDF 和已认证 bitstream；执行 `/opt/ec-dac/manual-link.sh test`。test 结束后运行 `python3 .../opt4_firesim_c4.py verify --attempt <attempt>`。本段是未来维护窗口命令；当前两张卡都在运行，不能执行。

## 当前结论

本轮新增了 Linux checker 服务、真实 GHT/ROI 接口、Blackscholes 小输入镜像和宿主机验证器，并修复了 Linux 服务漏掉的原 opt4 管理上下文恢复序列。**C4 native Verilator、Linux、OpenSBI、PARSEC 和 FireSim elaboration/GoldenGate/driver 均已构建；Stage A/B/C 没有真实运行结果；C4 FPGA bitstream 尚未构建。**

两张 FPGA 保持原任务。B v5 的 source ID 仍为 `be443a3dc2992eb52be4d3da55d687e13e9a21a0dccc1d136a2f23c2c3f436e4`；B v5 bitstream 已由 `B-bitstream-20261102T095746.955739Z/result.json` 认证成功，SHA-256 `bbe70b655538fa8d17deb72c4307ac66167ee0510aa12d0270ce2c9e37a34aea`。本轮检查时没有 B/C4 Vivado 构建进程，B 保持冻结。2026-11-02 15:20 UTC 新鲜只读 preflight 再次发现 e2 卡运行 libquantum、21 卡运行 hmmer，且当前用户有 4255 项 `/proc` 记录不可见；driver 启动安全门 exit 2 拒绝。没有烧写、重置、卸载或打开设备。C4 native 使用真实 Opt4 RTL，但 256 MiB DRAMSim2 不适合作为 B/C4 slowdown 配对。

## 源码和配置

- 原 Opt4 身份目录：`/data1/gzh/EC/slowdown/opt4`。它保存冻结 manifest 和证据，不是硬件源码副本。
- 原始硬件：`/data1/gzh/EC/chipyard/generators`，入口 `slowdown/run_optimization_4_svb.sh`，配置 `chipyard.v1Config`，功能提交 `476a760910f3bfbd3c111000ebe40343870ab439`，冻结提交 `962c4b87db2a810bc025a87f5f7289dd7aedc5cf`。
- 本轮隔离工作硬件：`/data1/gzh/EC/firesim/dac2026/work/opt4-linux-v6/C4/chipyard`。它从已适配 C4 v3 工作副本衍生并加了 Linux ROI 外设、BOOM 周期/计数器连接、Rocket 被动事件和 teardown CSR。变更清单/patch 在 [source-identity.json](source-identity.json) 与同目录 `v3-to-v6.patch`。原 `R_IC.scala`、`R_ICSL.scala`、`R_RSU.scala`、`GHM.scala` 字节均未改变；没有改写原任务分配、CPS/ECP、LSL 重放、最终比较、结果 CDC 或 BOOM 接受逻辑。
- 本轮配置 `chipyard.DacLinuxC4` 继承 `v1Config`，仍是一个 BOOM 和四个 Rocket，频率目标 200/100 MHz。native TestHarness 使用原生 DRAMSim2，256 MiB。该模型不能与 B v5 的 FireSim FASED 16 GiB 运行直接组成 slowdown。
- FireSim 为隔离树中的 1.17.0 commit `07efa6a6da18bd64d1159ae84a4701b37abb1228`，不能根据 `manager-1.17.1` 环境目录名误判。本轮 Linux v6 参数审查、elaboration、GoldenGate 和 U280 host driver 已构建；receipts 为 `C4-parameters-20261102T133656.572363Z/result.json`、`C4-elaborate-20261102T133801.870690Z/result.json`、`C4-goldengate-20261102T134256.430246Z/result.json`、`C4-driver-20261102T142123.460974Z/result.json`。四阶段 source ID 一致：`bc340555ee99fbbf32e2fbc5930f1fa47a03a8e01338b714f1a5a2a22d2ab5eb`。FireSim C4 Linux payload/FDT 独立构建并固定在 `firesim-software/`，没有覆盖 native 版本。
- 工作软件与构建只在 `/data1/gzh/EC/firesim`；PARSEC 只从 `/data1/gzh/EC/Software/PARSEC` 的副本输入；日志和样本只放 `/data1/gzh/EC/Experiment`。

## Checker 服务路径

OpenSBI 在 harts 1-4 到达冷启动同步点后保留这些 hart，不把它们交给 Linux/HSM。Linux 单 hart 启动在 hart 0，device tree 仍列出 harts 1-4 供 OpenSBI 建立 hart 表，但将其标成 Linux 不可用。原版 boot ROM 会唤醒这些 secondary hart。固件只接受一次完整 Sv39 `satp` 和服务入口；checker hart 在安装并读回相同 `satp` 后用标准 `mret` 进入用户态服务页。

驱动把只读、可执行服务页映射进发起 ioctl 的同一个 BOOM `mm`，保留 `mm` 和 mmu notifier，且只接受单进程、单线程、单 hart 0。服务页执行原 GHE AS-R、监控上下文、GO、initialized、management snapshot、COPY、特殊返回 PC；收到 CPS ready 后按原协议 COPY 并执行原自定义 JLR，继续等待下一项。GHT FINISH 不被当成 package 完成：U-mode 服务还要等 Rocket 的真实 cleanup、结果入队/CDC 空、无本地/待交接结果的只读 CSR `0xcc0` 连续安全。然后 Linux 服务恢复了裸机 `checker.c` 原有的 `0x72`（切回 management/GMode 快照）、最终 `0x60` COPY（恢复服务自己的寄存器上下文）、五个 NOP 和 GHT status=`0x02` 复查，最后才发 RELEASE 并通过 ecall 回 M-mode。此前 Linux 服务漏掉 `0x72`/最终 COPY，会在服务仍处于被 checker 覆写的寄存器上下文时释放 hart；这会破坏后续服务执行，现已修复。M-mode trap handler 只把带退出 magic 的 ecall 作为正常 park；其他异常记录 fault、解除 `satp`、执行 `sfence.vma`，但不报告成功。

CSR 状态转换核对结果：OpenSBI `mstatus_init()` 设 `MSTATUS_XS=3`，`sbi_hart_switch_mode()` 读取现有 mstatus 后只改 MPP/MPIE，因此 BOOM/Linux 得到的 XS 仍有效；checker hart 服务入口也明确设置 FS/XS 后用标准 `mret` 进入 U。`CSR.scala` 的 SSTATUS 写分支确实不写 XS，所以 driver 的 S 态 `csr_set(CSR_STATUS, SR_XS)` 不是 XS 的来源，只是冗余设置；当前路径依赖 OpenSBI 已证明会保留的 MSTATUS.XS，不需改 CSR 语义。没有根据注释单独更换 privilege 常量。

异常范围必须区分：裸机/M-mode 管理器的 EXIT ecall 与 firmware park 闭环已接入；checker 上的其他 U-mode syscall/异常会被 OpenSBI 记为 fault 并 park，不能继续当成 PASS。BOOM 原生 delegated S trap/xRET 路径仍在 opt4 RTL 中，但 replay 的 `CSR.scala` 合成路径 `check_exception && check_priv==1`（约第 1330 行）仍转入 M-mode，源码注释也标明实际 Linux 应转 S；`check_priv_ret` 合成返回（约第 1409 行）也走 M-status/MRET 状态更新。Linux v6 当前明确不支持 ROI 内 syscall、异常、timer/异步 trap、抢占、线程/进程切换、改映射或第二个 address space，不能把这些情况默默算作已校验。C4 ROI controller 的 `faults` 是锁存位图：bit 3 表示 BOOM trap、特权级或 SATP 偏离，bit 4 表示 failed/cancelled/dropped 计数非零；不是异常次数计数器。driver 的 END/DRAIN 对非零 faults 失败，RTL `EC_OPT4_ROI` 请求快照仍会由 host 保存到 `verification.json`，使失败样本保留任务统计和 fault 位。有效样本必须 faults=0。mmu notifier 会在活跃映射失效时保留页表并使样本无效，必要时要求重置模拟器。首轮仍选小、单线程 serial 程序。

原裸机 checker 在 `Software/Test/core/checker.c` 由主测试通过 wakeup 启动 secondary，执行 AS-R/GHT 监控/GO/initialized、ELU 自检、管理 snapshot/COPY/special-PC；loop 中按 CPS ready COPY 和 JLR；等待 GHT finish 后做 RELEASE 与 unset context。Linux 版本接入了前述真实任务及比较链，firmware 接管 hart 生命周期；不执行原 ELU 自检/统计输出，也不声称 kernel/trap 重放可用。这些是 v6 限定支持范围，尚待 Stage A/B 的 RTL 运行验证。

## 构建证据

以下均为“已构建，待运行”：

- Stage A 短裸机程序：使用冻结 Opt4 Verilator 可执行文件 `/data1/gzh/EC/slowdown/optimization_4_svb/build/optimization_4_svb_20261030_072604_18475a92/verilator/simulator-chipyard-v1Config`，由 run manifest SHA-256 `9c108a79a08837c19bf656f13e977f56f10b40b20af502e01a95d59e10bb59e5` 绑定；使用工作副本中的原 checker/secondary，hash 分别为 `07695f626f13817b4fc2b8dd5f89513fe32d70eb8d79c5a86928c0a4c434288b` 和 `4072a78e007d11b8d480b3b800ecb6097f675fda2c22d11dc1433199f6c91a3d`，没有 checker 替身。新增 payload 循环修改 128 项 volatile 数组，期望 checksum 32704，至少生成两项任务。构建 receipt：`firesim/dac2026/work/opt4-linux-v6/stage-a-build.json`。
- Linux 服务 blob：`service-build/20261102T121037.734265Z/result.json`，RISC-V assembler/ld/objcopy 成功，140 bytes，SHA-256 `0c0c5fc724e8948b7b52f64f53b9e4f8a898df774c46ed4fb91cde31da4a609b`；反汇编能看到 `0x72`、最终 `0x60`、五个 NOP、GHT `0x07` 复查与 `0x43` RELEASE。
- C4 kernel + driver：`Experiment/dac2026/build-logs/opt4-linux-v6/kernel-20261102T121131.590796Z/result.json`，`returncode=0`，`CONFIG_EC_DAC_ROI=y`、`ec_dac_roi.o` 编入，kernel `Image` SHA-256 `0a97d2c14dc56b95c3e344f43215e2e7d915eb15338f757e6d9676440acfe4e8`。kernel source ID `5ab180f444af7151f80ad5f5c8bb8a5f7c31648b3f23fa2e5432a77cdc91f95f`。
- C4 OpenSBI payload：`Experiment/dac2026/build-logs/opt4-linux-v6/firmware-20261102T121810.978739Z/result.json`，`returncode=0`、source ID `91f0364109e83667581a95daa135c93821ddc28cd95aafaeff8c349c29ab4e6c`；payload 包含上述精确 kernel 与 `C4.dtb`。ELF 的 `ec_opt4_secondary`、`ec_opt4_enter`、`ec_opt4_trap`、`ec_opt4_extension` 符号已核对。两者均为 BUILT_NOT_RUN。
- 共用应用：`.../apps-20261102T104634.523700Z/result.json`。`blackscholes` 取原 PARSEC serial 源，`ENABLE_PARSEC_HOOKS`、`ENABLE_THREADS` 未定义，gcc/g++ `-O3 -march=rv64gc -mabi=lp64d -static`，1 个应用线程。输入 `test/in_4.txt`，4 项、原程序 100 runs。输出按 4 个 reference value 检查，绝对误差 `<1e-4`。另有 1000 次加法 `roi-smoke`。
- C4 initramfs 和 native FDT：`rootfs-20261102T105148.076424Z/result.json`、`fdt-20261102T110345.734906Z/result.json`。root init 只开 shell，不自动执行应用；本轮 sample 要求每个 ROI fresh boot。
- native Chisel/FIRRTL/GoldenGate-like FIRRTL lowering 与分层 Verilog 已生成；六个实时 DCache 统计量到 BOOM observer、服务 idle 到 CSR 的连线由生成 RTL 检查，证据见 [generated-connectivity.json](generated-connectivity.json)。
- native C++ 编译输入：`C4-native-20261102T110754.343794Z`，已完成。最终 `native-build.json` 绑定 source ID 与可执行文件 SHA-256 `9e3313df...f5a5f`；续编使用单独 `C4-native-complete-20261102T113434.891961Z` receipt，保留先前对象并完成余下 C++ 单元。`opt4_linux_run.py prepare --mode smoke` 与 `--mode test` 已通过并分别生成 attempt `linux/partial/20261102T145135.113381Z`、`linux/partial/20261102T145135.318045Z`。两者都只有 `PREPARED_NOT_RUN` manifest；没有 `STARTED.json`、console/UART 原始日志、RTL event 日志或 runtime `verification.json`。因此它们可供用户直接启动，但 native 编译/prepare 通过不等于 Stage B/C 运行通过。B v5 源码保持冻结，bitstream 已有成功 receipt。
- B 共用软件副本：同一 PARSEC 应用/输入和 B v5 现有 Linux 源构建在 `work/opt4-linux-v6/B-software`，单独 kernel/initramfs/OpenSBI pointer，已编译；原 B 首跑软件没有覆盖。B v5 bitstream 已构建，实际部署仍要求双卡全局安全条件满足。

## 阶段 A：原 Opt4 短 RTL

这条现成原始实现路径不依赖当前 C4 native 构建。已准备 attempt `20261102T114242.905221Z`，尚未运行：

```sh
cd /data1/gzh/EC
python3 firesim/dac2026/scripts/opt4_stage_a.py run \
  --attempt /data1/gzh/EC/Experiment/dac2026/opt4-linux-v6/stage-A/partial/20261102T114242.905221Z
```

预期 `EC_OPT4_A_RESULT` 至少有 2 个生成、生成=完成=PASS、零 failed/cancelled/dropped/outstanding/timeout，checksum `32704`，ROI 与 drain 周期均非零。通过后脚本会在 `stage-A/complete/` 原子创建标记；只在验证器成功后接受，cache-shadow 的历史 FAIL 不由该短样本重新认证。

## 阶段 B：C4 Linux smoke

native C4 可执行文件 receipt 出现后，手动准备 smoke：

```sh
cd /data1/gzh/EC
python3 firesim/dac2026/scripts/opt4_linux_run.py prepare --mode smoke
```

将输出的 `/data1/gzh/EC/Experiment/dac2026/opt4-linux-v6/linux/partial/<UTC>` 路径代入：

```sh
python3 firesim/dac2026/scripts/opt4_linux_run.py run --attempt /data1/gzh/EC/Experiment/dac2026/opt4-linux-v6/linux/partial/<UTC>
```

Linux shell 出现后只由用户手动执行：

```sh
/opt/ec-dac/manual-link.sh smoke
/bin/busybox sync; /bin/busybox poweroff -f
```

Stage C 每次同样 fresh boot，使用以下 host 命令；prepare 输出的新 attempt 路径代入 run：

```sh
cd /data1/gzh/EC
python3 firesim/dac2026/scripts/opt4_linux_run.py prepare --mode test
python3 firesim/dac2026/scripts/opt4_linux_run.py run \
  --attempt /data1/gzh/EC/Experiment/dac2026/opt4-linux-v6/linux/partial/<UTC>
```

Linux shell 中执行 `/opt/ec-dac/manual-link.sh test`，随后 `/bin/busybox sync; /bin/busybox poweroff -f`。该模式运行 serial Blackscholes，1 个应用线程，4 个 options、100 runs、`inputs/test/in_4.txt`；guest 逐项与输入第 9 列 reference 比较，绝对误差 `<1e-4`。host runner 复核该输入文件实际 SHA、4 个正确性结果、应用退出/捕获状态，以及相同程序包版本。

host `run` 每 5 秒 fsync 宿主机 UART、压缩后的 RTL stdout/stderr 与 `progress.jsonl`；中断只留下 `partial/` 和 `raw/`，绝不转成完成样本。正常退出后自动严格验证并提交 complete marker。样本验证要求：实际软件、PARSEC 输入 manifest/hash 匹配；恰好 4 个 Rocket 的安装 `satp` 与 BOOM Linux `satp` 一致；所有 package begin 是 hart 1-4/U privilege，同一 satp；真实比较结果 PASS 且 sequence 无重复/丢失；ROI 任务非零且 generated=completed=passed；failed/cancelled/dropped/faults/outstanding 都为零；END 和 DRAIN 时间有效；最终 firmware parked mask=`0xf`；应用输出、退出/捕获状态正确；native simulator 正常退出。否则只留 INVALID/partial，不能纳入正式结果。失败时 Linux 快照和原始 RTL 请求快照分别保留；host 从 `EC_OPT4_ROI` 行解码 generated/completed/passed/failed/cancelled/dropped/outstanding 与 fault 位。

主要观测行：RTL stdout 的 `EC_OPT4_PACKAGE_BEGIN hart seq satp prv`、`EC_OPT4_PACKAGE_RESULT hart seq status full_compare cancelled`；UART 的 `EC_OPT4_INSTALLED`、`EC_OPT4_CONTEXT`、`EC_OPT4_SNAPSHOT`、`EC_OPT4_CONTEXT_DRAINED`；ROI controller 的 `EC_OPT4_ROI`。BEGIN 来自 Rocket 新包接受，RESULT 在真实 `full_check_complete`/cancel 结果入队点发出。BOOM/CDC 释放不是 RESULT printf 本身：`package_result_handoff_allowed` 等本地 checker cleanup，随后 handoff 需握手，`ec_service_safe` 还要求无待处理包/结果且 CDC empty；最终 DRAIN 检查 generated=completed、零 outstanding、checker idle 和 firmware mask=`0xf`。宿主机压缩保存完整原始 RTL log，并把关键事件/计数及所有输入、源码和配置 hashes 写入 `verification.json`/complete marker。

**较早记录已过期：** native simulator 已构建，Stage B/C 已有绑定当前 receipt 的 prepared attempt；两者均等待用户实际启动。当前准确入口见本文“2026-11-02 当前状态”。

## 同程序 B/C4 slowdown

已为 B 建立同一 `apps-build.json`、输入和 hooks 的 kernel/initramfs/payload，但 B baseline 部署仍必须使用冻结 B v5 硬件；不要用 C4 关掉 checker。B smoke 仍可使用原 `b_v5_first_run.py`；首组 PARSEC 用新的 `b_shared_apps.py`，要求 B v5 bitstream receipt 和人工安全部署记录。脚本会重用 B v5 全局预检查，若 FPGA 任务可见会拒绝启动。

native C4 的 256 MiB DRAMSim2 与 B FireSim FASED 16 GiB 不同，因此 native 结果只验证协议/软件，不能计算正式 slowdown。C4 FireSim 的可比参数、Linux/payload/rootfs、GoldenGate 和 driver 已构建，bitstream 尚缺；bitstream 构建等待 Stage A 与 native Stage B smoke 的真实验收。严格 latency 时间戳/分位数、C2/C8、消融与面积仍后续开展。

## 本轮没有通过的事情

没有任何新仿真、Linux boot、checker、PARSEC 或 B/C4 benchmark 真实运行结果。CLI 语法、Scala/Chisel/driver/kernel/OpenSBI/应用编译、生成 RTL 连接检查都不是 runtime PASS。两张 FPGA 的部署条件未满足；不得尝试绕开 B v5 现有的两卡保护。
