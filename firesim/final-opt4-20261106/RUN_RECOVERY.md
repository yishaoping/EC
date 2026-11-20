# PARSEC 作业服务与断线恢复

<!-- unattended-opt4-20261111 -->
当前硬件优先无人值守入口：[UNATTENDED_OPT4.md](/data1/gzh/EC/firesim/final-opt4-20261106/UNATTENDED_OPT4.md)。`ec-opt4-unattended.service` 已启动，状态/轮次/请求在实验目录 `unattended-opt4/`；Native 后续调度暂停。现有 CAD/模块活任务保持。独立模型网络仍有 SSH 代理依赖，详见该入口，不能把服务 active 当作 FPGA 成功。

实验根目录：`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106`。
实际程序、输入和版本范围由 `parsec-suite-inventory.json` 与 `suite-execution-plan.json` 绑定；正式结果只接受 `result.json` 与匹配哈希的 `complete.json`。

后续统一遵守用户指定的“可运行优先、覆盖优先”：先运行当前就绪且未完成三轮的程序，先首轮再补重复；单项失败按精确软件profile签名记录并跳过，其余任务立即继续，CPU上独立修复完成后新版本重新入队。只有Native没有可运行正式任务，才在21空闲边界运行必要的板级诊断；诊断不得抢占正式实验。C4最终产物认证后仍按原首验链在当前样本安全结束后优先切换。2026-11-09只读核查与完整32行配置/程序矩阵保存在 [调度策略核查](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/scheduling-policy-current.json)：全16项无遗漏，Native就绪缺项Ferret/Vips没有当前profile失败挡路，旧失败签名不影响新profile。现有coverage-first已满足该策略，未改代码、未重启服务、未另起FPGA流程。

2026-11-09 12:49 UTC：已实际修复并恢复 Ferret/Vips，见[恢复实测报告](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/ferret-vips-recovery-20261109.md)。Vips `vips-safe-fdt` 仅修正固件DTB重叠；Ferret `ferret-stable-order-safe-fdt` 仅在原ROI前固定预载目录顺序，计算object和原完整ROI不变。两者test/simsmall均已21卡有效通过，Ferret正式r1已由原coverage-first启动；Vips正式r1随后，三轮由原队列补缺。当前运行状态及完成轮次以实时矩阵为准，不改正在运行样本输入，不覆盖旧结果。

新增软件作业均沿用原job_service且已完成：`vips-safe-fdt-recovery`、`ferret-order-recovery`、`network-complete-roi-probe`。领域状态分别为 `software/vips-safe-fdt-recovery.json`、`software/ferret-order-recovery.json`、`software/network-complete-roi-probe.json`；持久日志 `jobs/<name>/console.log` 和领域log_dir。恢复先 `python3 scripts/job_service.py audit <name>`，身份存活只监控；确认退出后核验逐case/hash检查点，成功绑定的profile直接复用，不能因软件服务inactive而另起FPGA流程。三个网络候选完整原ROI的最新离线trace/output已保存，Netferret修复版已补真实hooks ELF；仍未证明C4完整线程/trap协议，不生成虚假的正式就绪收据。Native driver没有C4的线程/trap限制，但网络双进程guest与收数绑定仍待接入，不混成已板级通过。

2026-11-09 持续实验、C4 非侵入式诊断及三个网络程序 receipt/离线修复实测见 [本轮报告](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/network-recovery-20261109T043612Z/REPORT.md)。最新 Netferret 独立修复候选三种输入已完成 QEMU user/Linux 精确输出复核；真实 checker/context 仍有原 ROI 协议阻塞，未写正式就绪收据。正常 FPGA/CAD/coverage-first 服务未重启或修改。**当前所有部署、运行和恢复严格只允许 `0000:21:00.0`，禁止 e2、双卡和全局驱动/PCIe 操作。** 下文较早双卡/e2安排仅属历史，不适用于当前恢复。

三个网络程序的独立软件准备入口：[NETWORK_PREPARATION.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/NETWORK_PREPARATION.md)。该文档区分候选 ELF、QEMU user/socket 精确参考、单核 Linux 验证及尚未解决的 C4 原 ROI 协议；完整哈希和原始证据在同目录 `network-preparation-summary.json`。它们尚不是正式 FPGA 软件收据，不能用离线通过替代真实 checker 通过。持续软件状态为 `software/network-linux-validation.json`、`software/netdedup-linger-preparation.json`、`software/netdedup-linger-linux-validation.json`；每个完整 case 的 `result.json` 是重连检查点，旧失败和软件版本均保留。各软件作业沿用 `jobs/network-*/state.json`、`console.log` 与原 `job_service.py audit <name>`，不重启/改造 FPGA、C4 或现有调度。候选进入正式队列前须补齐目标 Linux、真实 ROI/checker 兼容性与版本绑定的 apps/rootfs/firmware 收据；既有 16 项队列动态发现，不新建重复队列。

Netstreamcluster 的 test/simsmall/本地正式 simmedium→simlarge 三项单核 Linux 输出现均已精确核对，通过收据分布在 `software/network-linux-validation.json`（test）与 `software/netstreamcluster-linux-validation.json`（small/formal）。它仍受 C4 原 ROI 协议限制。Netdedup 的 graceful-close 与 exact-length framing 候选、Netferret 的 framed-I/O/end-tag 候选分别保存在独立 ELF/patch/收据下，未正式采用：`software/netdedup-framed-preparation.json`、`software/netdedup-framed-linux-validation.json`、`software/netferret-protocol-preparation.json`、`software/netferret-protocol-linux-validation.json`。COMPLETE_REVIEW_EVIDENCE 只表示作业已收齐证据，必须逐项读取 case 结果；它不代表正确性或 FPGA 通过。原失败的日志和版本边界保持不变。网络软件作业不访问 FPGA、不持有卡锁、不执行 XDMA 操作；新验证使用 nice 15 与每实例 2 GiB QEMU 内存，不干扰原 FPGA/CAD 所有者。

2026-11-07 覆盖优先接管：`ec-parsec-coverage-first.service` 已安装、启用并运行；状态为 `coverage-first-state.json`，持久日志为 `jobs/coverage-first/{console.log,state.json,startup-audit.json}` 和 `coverage-first-logs/`。新增服务首次启用时尚未运行样本，完成接入校正后重新启动；原有 FPGA 样本、队列进程和 CAD 均未停止或迁移。原队列在未来任务边界读到 `managed_by_existing_queue` 后跳过已委托项，当前 Freqmine repetitions 子进程仍自行完成 r2/r3。旧定向 Dedup / Fluidanimate 和 C4 首批验证器不重启，先保留其已加载批次；新服务对后续缺项按 r1 全覆盖、r2、r3 轮转。未来优先级在执行计划 `coverage_priority` 中，当前16项全部纳入，三个网络程序缺软件时明确阻塞，不构造成功状态。

旧 C4 的非活跃 Canneal continuation 状态（旧boot、PID已不存在）已归档并设为 `DELEGATED_TO_COVERAGE_FIRST_SERVICE`，使仍活跃的旧 C4 suite 等待，避免它的循环顶部全局部署恢复与新所有者竞争。新服务只有确认当前 boot、原队列无活子任务、卡无活样本及原修复批次已结束（或被已完成CAD的既有守卫禁止启动）后才能接管。C4 首批验证器先完成真实 smoke / 功能门；CAD未完成时Native继续。切换配置和失败guest恢复复用已认证bitstream，调用原 `board_batch.py` 的维护独占锁与部署前冲突检查，不重建RTL/bitstream、不触碰第二卡缺失端点。

恢复时先执行 `python3 scripts/job_service.py audit coverage-first` 和读取 `coverage-status-live.json`。PID/start_ticks/boot_id匹配则接管监控，不能直接另起调度器。该新服务专用 `resume_after_adopted_exit`：已接管的旧子进程确认退出后再核对原子完成标记并续跑；其他现有服务的策略不变。失败键绑定硬件/软件receipt、程序、输入和重复号，失败阶段保留原因且不阻塞其他程序；新profile签名变化自动重试，原profile不会无限循环重跑。中断无完成标记的样本从头重跑，不恢复到中断指令。服务异常有systemd有限重试，任务失败本身由队列记录并继续。

逐轮表 `COVERAGE_STATUS_LIVE.md`、完整身份与状态 `coverage-status-live.json` 由原publisher每300秒更新。Native Blackscholes旧3轮分别绑定 observed / restart 驱动：已审阅host-only patch，变化为journal序号原点与宿主效率输出，硬件、ROI tick字段及内存模型不变，目标周期可复用；宿主效率保留原版本标签。其当前profile缺失test/simsmall仍显示PENDING，历史其他rootfs功能结果单独保留，不冒记通过。`facesim` / `raytrace` 当前没有计算型test，显示NOT_DEFINED，以simsmall作为功能门。

新长任务由系统级 `ec-parsec-*.service` 托管，独立于 VS Code、SSH、终端和用户登录会话。只管理本实验自己的 unit，不更改 sudoers、系统驱动或板卡固件。`ec-parsec-recovery-coordinator.service` 统一原有作业的开机恢复顺序；原有工作 unit 不并发开机启动。协调器先接管/启动 CAD，等当前 boot 的状态，再启动 Native 和 C4 控制器，避免旧中断状态使等待者提前失败。新增coverage-first服务单独enable，但必须等待当前boot的旧队列协调完成，因此不会越过恢复门。它不会重启原有活服务。`RequiresMountsFor` 等待实际工作盘挂载。

|任务|unit|作业状态/持久日志|领域检查点|
|---|---|---|---|
|最终 C4 CAD|ec-parsec-cad.service|Experiment/.../jobs/cad/{state.json,console.log,service.log}|C4-runtime-cad-state.json、其 log_dir、原 Vivado 项目中完成的 run 标记和 DCP|
|Native 缺项队列|ec-parsec-native.service|jobs/native/{state.json,console.log,service.log}|suite-native-queue-state.json、sampling-batches/*/state.json、runs/*/complete.json|
|C4 首批|ec-parsec-c4-first.service|jobs/c4-first/{state.json,console.log,service.log}|fpga-continuation-state.json、精确版本匹配的样本|
|C4 全套续跑|ec-parsec-c4-suite.service|jobs/c4-suite/{state.json,console.log,service.log}|suite-c4-queue-state.json、样本原子完成标记|
|状态发布|ec-parsec-publisher.service|jobs/publisher/{state.json,console.log,service.log}|results-summary.json、parsec-suite-progress.json|
|CAD 低频观测|ec-parsec-cad-monitor.service|jobs/cad-monitor/{state.json,console.log,service.log}|cad-runtime-progress-latest.json|
|Native 定向补跑|ec-parsec-idle-repairs.service|jobs/idle-repairs/{state.json,console.log,service.log}|idle-repairs-state.json、idle-repair-logs/*|
|Fluidanimate 输出分析|ec-parsec-fluidanimate-output-analysis.service|jobs/fluidanimate-output-analysis/{state.json,console.log,service.log}|software/fluidanimate-fpga-output-analysis.json、runs/*/diagnostic-output-analysis.json|
|Fluidanimate 已授权正式接入|ec-parsec-fluidanimate-stable-adopt.service|jobs/fluidanimate-stable-adopt/{state.json,console.log,service.log}|software/fluidanimate-stable-formal-adoption.json、版本绑定的正式apps/rootfs/kernel/firmware收据|
|Fluidanimate 修复版 Native 定向补跑|ec-parsec-fluidanimate-stable-native.service|jobs/fluidanimate-stable-native/{state.json,console.log,service.log}|fluidanimate-stable-native-state.json、精确匹配的样本完成标记|

`jobs/<name>/startup-audit.json` 记录启动前的只读核验，`before-*.json` 保留旧作业状态。进程身份同时使用 PID、`/proc/PID/stat` 启动 tick 与 boot_id；不以 PID 相同、状态文件写 RUNNING 或日志无增长认定仍在运行。

重连或 reload 后先运行（只读）：

```sh
python3 /data1/gzh/EC/firesim/final-opt4-20261106/scripts/job_service.py audit
systemctl show ec-parsec-cad ec-parsec-native ec-parsec-c4-first ec-parsec-c4-suite -p Id -p ActiveState -p SubState -p MainPID -p ExecMainStartTimestamp
```

身份匹配且存活时只接管监控，不 stop/restart、不迁移进程、不重新启动同一任务、不改正在运行任务的输入。systemd 重复 `start` 已激活 unit 不会重启；作业实例锁以及原 CAD、队列、板卡/维护锁继续防止重复运行。对既有外部活进程，托管器只通过 pidfd 监控原进程，退出后保存 `ADOPTED_PROCESSES_EXITED_REVIEW_CHECKPOINT`，不自动复制一个任务。

确认退出后先保留旧状态与原始日志，再核验版本和完成标记。主机重启导致的旧 RUNNING 状态归档到 `interruptions/host-reboot-<new_boot_id>/`，改记 INTERRUPTED；有效结果不改写。需要恢复的已退出 unit 才可 `systemctl start ec-parsec-<name>.service`。具体软件/构建失败保存 `FAILED_WITH_EVIDENCE` 并停在该失败，不进行无界自动重试。

CAD 恢复校验冻结 source_id、实际 CAD RTL/约束与完成 DCP 哈希，复用同一项目的完成 run；没有完成 DCP 的被中断阶段重做，不重新 elaboration、GoldenGate 或 host driver。若 CAD 已成功生成认证 bitstream，开机服务直接复用完成检查点。软件、输入、重复次数变化不重建 bitstream。

2026-11-07 06:40 UTC，用户明确授权停止一个已失败的 CAD 作业。停止前保存了 unit、完整 cgroup 进程树、领域/服务状态及故障日志；仅停止 `ec-parsec-cad.service`，Native 的 PID、启动 tick、boot_id 均保持一致。证据位于 `interruptions/authorized-failed-cad-20261107T064048Z/`。原 Vivado 异步启动子进程报 `runme.sh` 不存在并崩溃，但文件随后实际存在；根本原因尚未证明，不能仅凭该日志认定文件永久缺失。恢复修复包括：恢复这个已停止 CAD 项目中 20 个 root 创建文件的原属主，归档/移除 2 个未完成 run 的过期 begin/queue 标记，以原用户 `guozh` 执行 Vivado，先生成全部综合脚本，再同步执行未完成 DUT/top 综合脚本，使启动失败直接返回而非永久等待。11 个已完成 IP DCP 保留；DUT/RTL、约束、GoldenGate 和 driver 均未重建或更改。

当前 CAD 新状态绑定 supervisor PID/start tick/boot_id；实际 Vivado worker 由 `.vivado.begin.rst` 与 `cad-runtime-progress-latest.json` 记录。构建恢复时曾使等待器正常退出，因此在只读确认其原进程已退出后，重新启动 C4 首批、C4 全套等待器和 CAD 观测服务。没有重启活服务。相关审计为 `jobs/after-authorized-cad-repair-audit.json`。

软件准备也由独立服务托管：`ec-parsec-x264-no-progress.service`、`ec-parsec-raytrace-headless.service`、`ec-parsec-fluidanimate-diagnostic-preparation.service`。各自使用相同 `jobs/<name>/` 状态、锁和持久日志；完成的 apps/rootfs/kernel/firmware receipt 可直接复用。更新未来程序 profile 时先确认其尚未运行，归档旧计划到 `plan-history/` 并记录活动样本命令保持不变。不得改写已开始样本的 ELF、输入、rootfs 或参数。

大镜像的固件地址修复由 `ec-parsec-large-payloads-preparation.service` 完成，证据为 `software/large-payloads-preparation.json`。Dedup 的旧启动失败是 OpenSBI 默认 DTB 拷贝地址 `0x82200000` 与内嵌 initramfs 的内核 Image 重叠；`*-safe-fdt` 仅将两组固件的 DTB 拷贝地址统一改为 `0xbfe00000`，显式检查 mem=2G 范围和不重叠。四组 QEMU 启动/完整性通过不计 FPGA 样本。`plan-history/safe-fdt-20261107T072041Z-receipt.json` 保存后续 Dedup/Facesim/Ferret/Raytrace 绑定变更，正在运行的 Freqmine 不变。旧 Dedup FAILED 不从队列内存自动重试，不重启活队列；须在现有队列空闲边界安排有独立锁的定向补跑。

`ec-parsec-idle-repairs.service` 是针对已确认两项失败的补跑器，不启动第二套全套流程。只有当前 Native 队列在 `WAITING_REMAINING_SOFTWARE`、无运行中样本/子采样进程、全部就绪任务已完成或明确失败、当前部署仍为 Native，且最终 C4 尚未就绪时才执行。每300秒读状态；整批持共享维护锁阻止重载，实际运行继续使用原 runner 的单卡排他锁。仅跑安全固件 Dedup test→simsmall→缺失正式三轮，再用原 ELF/输入/ROI 的诊断 profile 回传 Fluidanimate simsmall 失败输出；不改现有队列的输入或失败证据。Dedup 完成后主队列通过精确结果标记自动复用。若 C4 先就绪则让其优先，该 Native 补跑保持等待，不擅自重新部署 Native。

输出分析服务等待诊断 run 的 `result.json`，严格核对唯一同 run ID 的 BEGIN/END 信封、base64、精确字节数；拒绝截断、重复和长度不符。完整文件保存到该 run 的 `diagnostic-files/out.fluid`，按原参考哈希核验并报告粒子字段差异/记录顺序；不放宽正式正确性校验，不把诊断 capture 计正式完成。重连只监控以上活服务，已完成样本不重做。

`ec-parsec-fluidanimate-linux-reference.service` 用独立 initramfs 和复用的 Linux 构建运行原 reference ELF，诊断完整 OS 与 QEMU user 的差异；没有访问 FPGA，不能提交正式样本。首次实际运行发现镜像 BusyBox 缺少 base64 applet，应用退出0但传输失败，原证据保留。修复使用镜像已有的 `uuencode -m | sed '1d;$d'`，已用绑定的 RISC-V BusyBox 对完整 1,314,152 字节参考文件进行回传验证。只有确认该失败诊断服务退出后才重启它。`ec-parsec-fluidanimate-capture-repair.service` 生成新的 v2 诊断镜像，保留原镜像/收据，在确认定向补跑器仍等待、活动样本仍为 Freqmine 时仅更新尚未开始诊断子任务的绑定，变更与旧收据见 `software/fluidanimate-capture-transport-repair*.json`/目录。运行中的 Freqmine、CAD 及现有全套队列均未 stop/restart。

2026-11-07 的 Linux reference QEMU 任务本身退出0且完整打印 `EC_LINUX_REFERENCE_DONE`；首个解析器因 UART 传输区夹入一行 printk 而把已完成诊断误记为 FAILED。`scripts/diagnose_fluidanimate_system.py --recover-existing` 只读现存 console.log，要求唯一 BEGIN/END、正常应用退出、严格合法的 base64 分块、声明字节数及 guest SHA 全匹配；恢复输出原子写入原诊断日志目录，并另存 `software/fluidanimate-linux-reference-recovery.json`。它不重启 QEMU，不改 FPGA 样本；旧 FAILED 状态保存在 recovery receipt。作业服务接受 `COMPLETE_RECOVERED_FROM_EVIDENCE` 检查点，后续重连不会重跑已完成诊断。

`ec-parsec-fluidanimate-pairs.service` 是独立、低优先级的软件诊断，状态为 `software/fluidanimate-pair-selection-diagnostic.json`，PID/start tick/boot_id 与持久日志在 `jobs/fluidanimate-pairs/`。它在新副本中只增加粒子对过滤计数，不变更计算谓词、数值更新、正式 ELF 或测量输入；保存补丁及原输出哈希。官方 `fluidcmp` 显式启用位置/速度/bbox 的零容差检查；不传这些参数的 `fluidcmp` 实际不执行数值测试，不能当作正确性通过。该服务在私有 QEMU user/Linux 环境执行，结果一律 diagnostic_only，不访问 FPGA。

该诊断在 simsmall 第一帧密度阶段复现同为3,246,500个候选对，而 QEMU user/Linux 分别漏掉3,662/6,798个半径内跨cell对。仪表化程序逐字节复现各自未仪表化原输出，5帧内两个阶段均有日志，证明并非传输损坏。`ec-parsec-fluidanimate-stable-candidate.service` 使用独立收据 `software/fluidanimate-stable-order-candidate.json` 和相同 job 管理规则。其两处谓词替换为 `(cindexNeigh<cindex)||(cindexNeigh==cindex&&iparNeigh<ipar)` 后，QEMU user/Linux 输出SHA均为 `f496414b8226b30ca2a4f9bf7164361e908ac274246fb7ef53b0aa5b4f1990c4`，5帧/两个阶段计数一致、半径内跨cell漏算0。候选与旧错误结果不同，不是失败的判据；它尚未纳入正式软件，须获得明确的软件语义修复决定再在两组同版本重验。完整原始日志和最小补丁在对应 log_dir，不将该诊断计正式结果。

`ec-parsec-fluidanimate-stable-prepare.service` 已完成无计数的候选 ELF 和 test/simsmall/simmedium 参考及 strace 检查，三项 ROI 内均未观察到同步syscall，simsmall与上述双环境候选哈希相同。Native/C4的候选rootfs、内核、OpenSBI已生成并核对原ROI驱动object不变；没有生成bitstream，没有FPGA执行。其检查点为 `software/fluidanimate-stable-candidate-preparation.json` 的 `READY_UNBOUND_PENDING_DECISION`，后续重连直接复用。执行计划仍绑定原fluidanimate；须收到用户决定后生成明确标注的新正式profile并在空闲边界接入，禁止通过修改活队列或假写任务完成状态绕过。候选参考/编译/补丁/镜像路径都在该收据中，不修改已运行样本的原收据。

2026-11-07 用户明确回复“允许修复 profile，两组重新验证和采样（推荐）”。此授权覆盖上述两处配对判序修复，保留原输入、5帧计算和原ROI。`ec-parsec-fluidanimate-stable-adopt` 校验候选源码相对原profile恰好两处替换，其余源码/输入/argv/线程/预热不变，复用候选ELF，生成正式 `fluidanimate-stable-formal` apps/rootfs和两组kernel/firmware。旧候选/旧正式收据不覆盖；rootfs内嵌新正式BUILD.json，因此仅软件增量重建，不重建硬件。授权、最小patch、ELF哈希、全部新收据、活动样本及计划变更前后哈希在 `software/fluidanimate-stable-formal-adoption.json` 和其evidence_dir。只有 `BOUND_FOR_BOTH_CONFIGURATIONS` 后才允许执行。

未来计划中该程序Native由 `ec-parsec-fluidanimate-stable-native` 唯一持有，C4继续由原全套队列持有。原Native全套队列的FAILED在其内存中保留，故不重启或改写它；只将未来fluidanimate标为Native已由独立定向补跑负责。该服务每300秒检查本boot队列进入 `WAITING_REMAINING_SOFTWARE`、无活样本、原idle-repairs终止且其锁已释放、当前仍部署Native、最终C4未先就绪，再取得维护共享锁，使用原runner卡锁运行test→simsmall→缺失正式三轮；故障停为FAILED_WITH_EVIDENCE，不启动另一套全套队列、不重载驱动、不重新部署。恢复时精确核对apps/rootfs/firmware/driver/硬件来源及原子完成标记，只补缺项。若C4先就绪则等待后续既有Native批次，不能为了它中断C4。即时只读判定入口为 `python3 scripts/run_fluidanimate_stable_native.py --check-only`。

2026-11-07 08:42 UTC空间快照：`/data1`位于`/dev/sdb1`，空闲约451.62 GiB；CAD仍位于`/dev/sdc3`的`/var/tmp/...`，空闲约342.20 GiB。原始快照见 `reconnection-space-snapshot-20261107T0843Z.json`。本轮未删除文件，也不将外部出现的空闲增长记作本轮清理收益；不迁移活跃CAD或改变80/60 GiB构建守卫。

FPGA 恢复只补匹配 ELF、输入、rootfs、硬件、配置与 ROI 的缺失、失败或中断样本。guest 没有指令级检查点：中断样本从头重跑，统计快照不冒充可恢复执行状态。当前只允许21卡及其专用维护锁；部署前核对当前 boot、21 BDF/序列号与具体设备冲突。禁止操作 e2、全局 XDMA 卸载/加载、全局 PCIe 重扫；不重启服务器，不为另一卡打断21的活任务。

日志直接落盘，作业状态每 30 秒原子替换并 fsync，guest UART/ROI 日志和 30 秒快照由原收数器持续保存；发布器/CAD 观测器每 300 秒合并读取。正常人工查询间隔至少 5 分钟，长 CAD 10 分钟；失败事件可立即诊断。完整样本原子提交，截断尾部、重复记录及版本不匹配不能进入正式汇总。

2026-11-07 两次 host boot_id 改变均由外部发生，本实验未执行服务器重启。最近一次从 `09ba1a37-9f6d-4a9e-ad1b-9c057e9ad64c` 变为 `e5c9abda-56be-46db-9a2a-03b472f81a5a`，打断 Bodytrack formal r1 与未完成的 DUT 综合。具体原始证据见 interruption receipt；不据此推断重启原因。


## 2026-11-10 网络收尾候选与失败证据恢复

网络真实失败和软件修复入口为`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/network-native-wait-20261110.md`。Netferret的failure-evidence-v2已由原coverage-first自动上板；Netstreamcluster joined-v2 test失败，不能复用为通过。

独立作业`ec-parsec-netstreamcluster-graceful-close.service`只进行CPU/QEMU验证与Native软件镜像构建，不部署FPGA、不改CAD/冻结硬件/调度代码。状态为`Experiment/firesim-final-opt4-20261106/software/netstreamcluster-graceful-close.json`（相对EC根目录）；持久日志、单实例锁、boot_id/PID/start_ticks和启动输入哈希在`Experiment/firesim-final-opt4-20261106/jobs/netstreamcluster-graceful-close/`。每项QEMU保存原子result.json；不完整目录保留为interrupted后缀，确认原进程退出后才补跑。全部离线门槛满足后，只向现有计划发布独立软件版本`netstreamcluster-graceful-close-v3`；原队列唯一拥有21卡执行，test/simsmall失败即跳过该版本。C4网络协议限制仍在，绝不凭Native通过创建C4放行收据。

## 2026-11-10 独立 DCP 复用验证

用户明确授权在独立目录验证绕过低效功能VHDL导出。新服务`ec-parsec-c4-dcp-independent.service`以guozh运行CAD，单实例锁`Experiment/firesim-final-opt4-20261106/.c4-dcp-independent.lock`，状态`Experiment/firesim-final-opt4-20261106/C4-dcp-cad-state.json`；工作目录`firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/`。作业PID/start_ticks/boot_id、输入脚本哈希和持久日志在`Experiment/firesim-final-opt4-20261106/jobs/c4-dcp-independent/`；各Vivado阶段脚本、日志、返回码与检查点清单在状态的log_dir。此作业没有FPGA访问或部署入口，不写原CAD目录及原runtime状态。

独立副本复制当前DUT的3,339,470,089字节DCP（SHA256 `0dbdabf283669fd45d4389742fa9c05fa0163d01496e86e558c77d2bb3be86ae`）与11个已完成IP的DCP，逐项核对复制前后大小、mtime和SHA256；不以DUT尚无end标记否认完整DCP，也不伪造原run完成标记。VHDL/Verilog funcsim网表不是顶层综合/实现输入，DCP及其内嵌综合stub才是需要验证的复用产物。

阶段为DCP真实打开→在副本中生成实现脚本（scripts_only）→原顶层综合脚本→原实现脚本的DCP/XDC拼接及Explore布局布线→setup/hold时序门槛与正常bitstream DRC→独立产物认证。阶段返回0才写有效检查点；DCP可读不等于顶层已拼接或bitstream可用。原始冻结源码、RTL/时钟约束、GoldenGate和driver哈希在开始/认证时核对。每个CAD使用2线程、nice15；data1启动余量80GiB、保留60GiB和增长120GiB预算，与原CAD磁盘守卫分离。旧原Vivado及其wall-limit guard保持。

重连先核对新服务与其state的boot_id/PID/start_ticks。活进程只接管监控，不启动重复分支；确认退出后才复用本分支已成功阶段。原21卡任务保持唯一coverage-first拥有，C4正式仍优先。独立候选未完成bitstream和认证前，不修改原runtime receipt或启动FPGA首验；候选通过后还需安全接入唯一首验/队列，不能把独立认证误报为自动部署已经发生。

## 2026-11-10 Opt4 优先交接与 CAD 外层超时保护

Opt4 13项普通 PARSEC 的软件准备审计入口为 `Experiment/firesim-final-opt4-20261106/opt4-readiness-latest.json`。它一次性核验 ELF、原始输入/参考输出、rootfs、内核/固件、driver、CAD实际输入及 Native 三轮相同软件/输入/ROI绑定；`READY_HASH_VERIFIED_FPGA_PENDING` 只表示离线准备完成。

`ec-parsec-c4-first.service` 现在只负责精确认证 bitstream 的21卡部署及 smoke → Blackscholes test/reset探测 → simsmall。全套正式轮次由原 coverage-first 服务执行：所有可运行 C4 优先于 Native 网络补项，每种配置先补全可运行 r1，再补 r2/r3，按原子完成标记跳过已通过样本，失败版本留痕后继续其他程序。2026-11-10只在核实两协调器无child、21卡active为COMPLETE并持有21维护锁的边界加载该调整；未重启任何CAD或FPGA worker。

原 `resume_bitstream.py` 的Python监督循环有24小时总墙钟上限，而DUT综合本身已耗22小时，后面仍有实现和布线。为防止无故杀死正常CAD，新服务 `ec-parsec-cad-wall-limit-guard.service` 使用原PID/start_ticks/boot_id及pidfd，只在恢复运行23小时后暂停外层Python监督器的计时循环。实际Vivado、子进程、PGID及cgroup不暂停、不迁移、不重启；CAD输入和冻结RTL不变。原60 GiB磁盘余量与120 GiB增长预算仍检查。

只读恢复入口：

```sh
cat /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cad-wall-limit-guard-state.json
systemctl show ec-parsec-cad-wall-limit-guard ec-parsec-cad ec-parsec-c4-first ec-parsec-coverage-first -p Id -p ActiveState -p MainPID
cat /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cad-runtime-progress-latest.json
```

Guard日志在 `jobs/cad-wall-limit-guard/{console.log,service.log,state.json}`，每300秒原子更新独立状态。`wrapper_paused=true` 时原CAD监督器的T状态和旧updated_utc是预期现象，必须结合guard与真实Vivado worker/产物判断进展。不要手工唤醒仍有活CAD子进程的包装器，否则其旧24小时上限可能终止Vivado。子进程退出后guard自动唤醒原包装器；原包装器继续原时序成功、输入未变和产物哈希认证，将认证bitstream写入既有receipt，首验自动接续。停止/失败/重连时先核实guard身份与日志，不复制新CAD。统计快照仍不等于指令或CAD任意点恢复。

## 2026-11-10 独立 DCP 快速路径及认证衔接

`ec-parsec-c4-dcp-independent.service` 使用独立工作目录 `dcp-work/C4-dcp-20261110T071734Z`，状态为 `Experiment/firesim-final-opt4-20261106/C4-dcp-cad-state.json`，持久日志为 `build-logs/C4-dcp-20261110T071734Z/`。原 DUT checkpoint（SHA256 `0dbdabf283669fd45d4389742fa9c05fa0163d01496e86e558c77d2bb3be86ae`）与11个已完成IP复用，不重新综合DUT，不改冻结RTL，不访问FPGA。实际DCP读取/part/零black box检查和顶层综合已通过；完成状态以逐阶段 returncode 为准。

第一次顶层失败是 scripts-only 刷新后私有 `.gen` 中缺失 DUT DCP；证据已保存在 `failed-top-20261110T074514Z/`。修复将12个DCP另存于工作目录 `reused-checkpoints/`，逐哈希验证后恢复生成目录所需文件与原DCP内的真实stub。只恢复已确认退出的独立分支，复用已通过阶段。旧 `error` 字段保留了首个失败的证据；当前状态须结合 `status/current_stage/stages`，不能把旧错误当作仍失败。实现脚本在原生成脚本上只添加拼接后零black box检查并将 general.maxThreads 改为8，差异收据为 `implementation-adaptation.json`。

`ec-parsec-c4-dcp-admission.service` 只做认证收据和耐久bitstream复制，不部署或启动样本，不给CAD发送信号。状态 `C4-dcp-admission-state.json`，作业入口 `jobs/c4-dcp-admission/{state.json,console.log,startup-audit.json}`。等待DCP分支全部五个真实阶段返回0、冻结source_id/12个DCP/RTL约束哈希一致、拼接零black box、setup/hold通过及正常write_bitstream DRC成功，再将bitstream复制到 `images/C4-dcp-20261110T071734Z/`。先发布匹配的 `bitstream-runtime-build.json`，最后原子发布现有 `C4-runtime-cad-state.json` 的就绪信号。首个选中认证收据固定在 `C4-selected-certified-build.json`；之后原CAD产生的其他收据归档保留，服务恢复固定版本。已有 `ec-parsec-c4-first` 等待该入口，在21卡安全边界接管，smoke→Blackscholes test→simsmall，然后原coverage-first优先C4普通13项r1，再补r2/r3。不得绕过首验或并行占用21卡。

重连后先审计这两个service与其状态PID/start_ticks/boot_id。活进程只监控；若确认分支退出，先保留失败阶段日志和状态，按已完成阶段续跑。不要再次执行DUT综合或DCP可读性检查。若canonical已选中独立分支，恢复构建时必须使用原 `build-logs/.../original-cad-receipt.json` 的原CAD绑定，不能将已选中DCP收据误当原构建输入。原 wrapper 仍由已有wall-limit guard管理。

容量风险：DUT综合利用率报告为5,938,927 LUT（455.55%）和424,714 CARRY8（260.62%），尚非顶层优化后占用。必须检查后续opt/place实际容量报告，不能假定该DCP一定可布局。资源观察保存在 `observations/c4-dcp-resource-*.json`；2026-11-10 07:49 UTC仍有约406 GiB MemAvailable、256CPU负载约29、CPU/memory/I/O压力均0，原CAD继续保留，无暂停依据。

## C4 capacity audit (2026-11-10)

Capacity evidence: `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-capacity-20261110/CAPACITY_REPORT.md` and `capacity-summary.json`. The flat mapped DUT report was independently reproduced: 5,938,927 LUT / 1,303,680 (455.55%); current mapping NOT FIT. This is distinct from the complete-top post-opt verdict.

`ec-parsec-c4-capacity-vivado.service` reads the immutable DUT DCP and performs diagnostic `opt_design` before placement; state: `C4-capacity-vivado-state.json`. `ec-parsec-c4-capacity-top-postopt.service` waits for the independent full-top optimization checkpoint and reports utilization/DRC before routing completion; state: `C4-capacity-top-postopt-state.json`. These services never access FPGA or signal the live CAD. On reconnect, audit their stored PID/start_ticks/boot_id identities before any start; do not duplicate live audits or modify their inputs. The existing publisher refreshes the capacity report from their saved evidence.

The isolated arithmetic-factor candidate under `candidates/capacity-exact-factor-20261110/` is NOT formal hardware, NOT admitted, and does not prove full-design fit. Its receipt binds arithmetic checks, 2048-cycle leaf comparison and actual leaf mapping. Frozen/live source hashes remain unchanged. Only an explicitly approved derived profile with complete validation may replace formal hardware; no capacity-based termination follows from pre-opt counts alone.

2026-11-10 17:00 CST: Independent DCP init_design exited because the added early gate rejected Vivado-generated `dbg_hub_CV` (`IS_DEBUG_CORE=1`). Shell-only reconstruction proved this identity. Original generated flow implements it at the place-stage `implement_debug_core`. The failed stage and receipts are archived at `build-logs/C4-dcp-20261110T071734Z/failed-init-design-20261110T084756Z/`; no live process was killed. The gate now permits that exact transient debug placeholder, still rejects all unresolved functional cells, and requires all black boxes to be resolved after implement_debug_core. The confirmed-dead DCP controller was resumed from successful DCP/top checkpoints, without DUT synthesis. Inline post-opt complete-top capacity reports avoid a second multi-GB DCP read and block placement if capacity exceeds the real device. The top-postopt observer is only restarted after auditing its prior exit. No FPGA actions occur in this diagnosis.

## Opt4-fit independent optimization (2026-11-10)

User authorized derived C4 feasibility optimization. Independent repository: `Opt4-fit-20261110/`, branch `opt4-fit/20261110`; `candidate-binding.json` and `bindings/<commit>.json` preserve lineage and source IDs. Original frozen input, Native jobs and the original CAD remain unchanged. Do not relabel derived results as frozen 8491167 results.

Module-only services: `ec-parsec-opt4-fit-modules.service` (Scala compile/elaboration with private classes), `ec-parsec-opt4-fit-mapping.service` (matched OOC Vivado maps, at most two workers), `ec-parsec-opt4-fit-verification.service` (universal carry SAT + generated module comparisons), `ec-parsec-opt4-fit-scanner.service` (exact scanner extraction, SAT index identity, full-size RTL comparison and matched mapping). States are `Opt4-fit-{modules,mapping,verification,scanner}-state.json` under Experiment, with jobs/* persistent console logs and per-module logs in `build-logs/Opt4-fit-modules-20261110/`.

Reconnection first audits PID/start_ticks/boot_id and monitors live workers, never duplicates, stops or changes their input. Preserve all completed module RTL/hash/receipt/checkpoints. The address/barrier module revision and newer scanner revision are bound separately; never silently mix versions. The independent verifier's initial port-count assertion was an offline harness error (52 real exported ports), preserved before repair; it was not an RTL mismatch or FPGA result.

`FIT_STATUS.md`/JSON publish only completed mapping evidence. Resource parsing uses the positive Available device rows, not repeated zero per-SLR rows. A full-DUT build is gated on resource feasibility evidence and functional checks; module simulation/map is not full-design equivalence, fit, timing or FPGA validation. All these jobs have no FPGA access. Continue 21-only Native scheduling independently.

Second local optimization revision `8da24a269b98a0d6a8f57b030353a310812c4344` (source ID `7e77ddda28298ac88be13c28dbe98771982bc6ca9587f810adf875bffd580cc1`) replaces serial latency reductions with exact width-growing balanced trees and replaces per-slot distance/minimum arithmetic with shared high increment/two priority encoders/one subtraction. `ec-parsec-opt4-fit-round2.service` uses immutable `git show` source snapshots and independently compares the full-size original generated module before mapping. State `Opt4-fit-round2-state.json`; logs `build-logs/Opt4-fit-modules-20261110/round2/`. It does not modify the live first-round tests or reinterpret their source IDs.

`ec-parsec-opt4-fit-priority-proof.service` completed a universal SAT proof over all 264 input bits (256 arbitrary failure bits and 8-bit cyclic origin); status `PASS_UNIVERSAL_264_INPUT_BITS`, state `Opt4-fit-priority-proof-state.json`, evidence `build-logs/Opt4-fit-modules-20261110/priority-proof/`. Together with the earlier universal 40-input-bit sequence/index identity and full generated-module regressions this checks the local transformation; no full-DUT proof/admission is claimed. Reconnect audits apply identically to both additional module jobs. Do not restart completed maps merely to fix a presentation/parser problem; retain original reports and publish corrected derived receipts instead.

The original address Icarus compile reached its configured 1,800-second timeout at 2026-11-10 09:52 UTC; no address comparison result was produced, so it is not a functional mismatch or pass. After identity audits confirmed all old verifier processes exited, `ec-parsec-opt4-fit-address-verilator.service` starts only the missing address comparison using unchanged full-size RTL and the same 52-output, 6,144-cycle testbench. State `Opt4-fit-address-verilator-state.json`; logs/snapshots/executable under `build-logs/Opt4-fit-modules-20261110/address-verilator/`. The copied old state/console preserve the failure. No barrier or SAT rerun and no FPGA access. The chosen tool/version and all source/executable hashes are recorded; successful completion is reused after reconnect.

`ec-parsec-opt4-fit-integration-compile.service` compiles all five modified production sources together from pinned git-show snapshots, using private class outputs and the compatible original cached classpath. State `Opt4-fit-integration-compile-state.json`, logs `build-logs/Opt4-fit-modules-20261110/integration-compile/`. It validates Scala integration only and never elaborates/synthesizes a full DUT or touches FPGA. Completed first module preparation/scanner/proof jobs have completion-state guards in their specs, with pre-change specs and identity audits under `jobs/<name>/completed-recovery-preparation/`; they do not overwrite completed artifacts on a later boot.


## 2026-11-10 18:45 CST：Opt4-fit 已进入真实整机综合

本节替代先前“等模块评估后才启动整机”及“保留原冻结导出”等旧状态。独立硬件 `Opt4-fit-C4-SVB32-20261110`：commit `8da24a269b98a0d6a8f57b030353a310812c4344`，source ID `7e77ddda28298ac88be13c28dbe98771982bc6ca9587f810adf875bffd580cc1`。不冒充冻结 `8491167`。

- 整机参数核对、elaboration、五个修改类的真实加载来源、GoldenGate 已完成。新 RTL 在 `Opt4-fit-20261110/builds/system-8da24a26/goldengate-attempt-1/`，绑定在该 system 目录的 `inputs.json` 及 `Experiment/.../Opt4-fit-rtl-state.json`。
- `ec-parsec-opt4-fit-cad.service` 已实际进入 `synth_design`（启动时 controller PID 2790677、wrapper PID 2790743；重连须再核验 start_ticks/boot_id）。独立目录 `Opt4-fit-20261110/builds/cad-8da24a26/`；状态 `Experiment/firesim-final-opt4-20261106/Opt4-fit-cad-state.json`，日志 `build-logs/Opt4-fit-cad-8da24a26/` 和 `jobs/opt4-fit-cad/console.log`。
- 仅复用逐哈希核对的 11 个未变 U280 平台 IP DCP。已比较 FPGATop 外部接口和 defines；冻结 DUT DCP/cache 不进入新综合。新 DUT → 新顶层综合 → 拼接与黑盒检查 → opt_design。保存优化检查点、LUT/CARRY8/DSP/FF/BRAM/URAM 及层次报告后判容量；NOT FIT 停在布局前。容量通过才自动 place/physopt/route、setup/hold、DRC、bitstream；省略全部非实现必需的 funcsim Verilog/VHDL 网表导出。
- 当前新整机资源**尚未产生，FIT 尚不能判断**。地址统计 OOC 两个活 worker 保持运行，不阻塞整机；全尺寸地址原/新 RTL 6144-cycle、52 输出比较已通过，非全设计等价证明。模块资源及权重排名：`build-logs/Opt4-fit-modules-20261110/{FIT_STATUS.md,RESOURCE_PRIORITIES.md}`。
- 冻结原 DUT opt_design 后 LUT 5,741,353/1,303,680、CARRY8 366,817/162,960，确认为 NOT FIT。已按授权结束原无效导出 cgroup，确认所有原 PID/start_ticks 身份退出；原 CAD 与 wall-limit guard 禁用，原 CAD 状态 `RETIRED_NOT_FIT` 并有恢复完成守卫，防止重连再次启动。收据 `frozen-cad-retirement.json`；保留所有 DCP/日志/容量证据。独立的冻结完整顶层 opt_design 诊断继续，其容量门会阻止无效布局。
- 新 GoldenGate 的 const.h、const.vh、defines、两份 XDC、DTS、Dromajo 参数共 7 项与已编译 C4 host driver 输入逐字节相同。已独立复制原 efficiency driver 并记录**兼容复用，非重新编译**：`runtime/Opt4-fit-C4-driver-compatibility.json`、`runtime/Opt4-fit-8da24a26/FireSim-xilinx_alveo_u280`。不修改冻结/现有 runtime 收据，不代表 FPGA 验证已通过。
- 新硬件目前无 bitstream、无 Opt4 正式样本、未发布到冻结 C4 首验入口；后续认证须使用独立派生 profile，在 21 卡安全边界接入唯一首验/调度，checker/排空/输出通过后才允许正式样本。Native 活任务及 21-only 调度保持不变。

恢复时用 `job_service.py audit opt4-fit-rtl`、`job_service.py audit opt4-fit-cad` 只读审计；活进程只接管监控，失败已确认退出才续缺失阶段。成功阶段通过源 ID、输出哈希收据复用，不重跑 DUT；不使用统计快照冒充任意指令/CAD 恢复点。启动命令为 `systemctl start ec-parsec-opt4-fit-{rtl,cad}.service`，**仅在审计确认无活实例且确需续跑时使用**。不要重启 Native 或触碰 e2/global XDMA/PCIe。


## 2026-11-10 地址统计独立 round3（不修改当前整机输入）

- 当前整机继续固定 `8da24a269b98a0d6a8f57b030353a310812c4344` / source ID `7e77ddda28298ac88be13c28dbe98771982bc6ca9587f810adf875bffd580cc1`。`Opt4-fit-cad-state.json` 的 DUT/top/opt 资源报告尚未生成时，不可声称 FIT 或给出局部相减的预测值。容量通过后按已有服务自动进入 place/route/timing/bitstream，不等待 round3。
- 独立 worktree `Opt4-fit-address-round3-20261110`，branch `opt4-fit/address-round3-20261110`，commit `aca893e0aa3f7e23e16067ab40713afea41558e8`，source ID `d5ca949536b50c2d6bf2f9ef1c2748282f88bac0fa5f2d4cc7ffa5b6c94feb28`。仅修改地址命中归约组合逻辑，保留所有 64 位状态/输出、256 packet slots、队列与表容量、EC/checker/rollback、原事件/溢出/error/ROI/STOP/drain周期语义。
- 原访问 size 是2位，最多8字节；每个 masked hit 最多8 byte、3 word4、2 word8、1 line，包括跨line裁剪。Yosys已完成96输入位的无约束通用上界证明；8项/80项归约分别在136/1360输入位域、上述已证明边界条件下通用等价证明通过。每级归约仅用自身子树项数的严格上界，不把每个叶子先拓展成最终宽度。该证明不等于整机等价。
- `ec-parsec-opt4-fit-address-round3.service` 托管后续全尺寸 elaboration、原始冻结RTL与新RTL的6144周期/52输出对照、同设置Vivado归约探针/三种64位更新与溢出实现探针、完整地址模块综合。更新探针尚未写入候选生产源码；只有真实 LUT/CARRY8 收益及通用74输入位证明后才评估下一独立提交。不得提前报告收益或移入当前整机。
- 状态 `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-address-round3-state.json`；持久日志 `jobs/opt4-fit-address-round3/console.log` 与 `build-logs/Opt4-fit-address-round3-20261110/`，源快照、patch、binding均保留。恢复先 `job_service.py audit opt4-fit-address-round3`；活PID/start_ticks/boot_id只接管监控，已退出失败按收据恢复缺失阶段，不覆盖成功结果。
- Native Netstreamcluster r2的result/complete身份及结果哈希均核验有效，ROI 99,353,979,454周期、Host 6047.767924856秒；当前正式44/48，r3继续在21卡。未触碰e2、驱动或PCIe，未重启Native、当前整机综合或调度器。


### 地址 round3 实测更新

80项四粒度归约探针：1843→957 LUT（-48.07%）、6→2 CARRY8；DSP均0。三种16路64位更新/溢出探针均完成74输入位通用等价证明，但split为368 LUT/144 CARRY8、prefix为2016 LUT/32 CARRY8，均劣于原写法160 LUT/144 CARRY8的当前LUT目标，**不采用到生产源码**。完整原/新地址RTL已6144周期、52输出逐周期一致；新完整地址模块已实际启动OOC综合，真实完整模块面积待报告。报告 `Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-round3-20261110/MEASURED_RESULTS.md`。上述为局部探针，不是整机FIT结论，当前整机8da24a26继续运行，不等待新优化。

## 地址 probes4 与派生 runtime 准备

`ec-parsec-opt4-fit-address-probes4.service` 仅作CPU算术探针，最终状态
`PROBES_MAPPED_NOT_INSTALLED`；其中heap80通用证明超时，不是通过。
两种DSP推断结果与原算术相同，不安装到硬件。
状态：`Experiment/firesim-final-opt4-20261106/Opt4-fit-address-probes4-state.json`；
阶段收据：`build-logs/Opt4-fit-address-probes4-20261110/`；
服务日志：`jobs/opt4-fit-address-probes4/console.log`。
恢复先 `python3 scripts/job_service.py audit opt4-fit-address-probes4`；
活实例只监控，无活实例时才按阶段输入/输出哈希复用；完成guard跳过已完成探针。
原proof80超时日志和退出前state均保留，恢复不改写失败证据。

派生13项软件清单：`runtime/Opt4-fit-8da24a26/software-suite.json`；
driver版本绑定：`runtime/Opt4-fit-8da24a26/driver-receipt.json`。
`python3 scripts/prepare_opt4_fit_runtime.py` 只核验/记录软件，不启动FPGA。
`python3 scripts/prepare_opt4_fit_runtime.py --certify` 只在真实CAD全部门通过后认证派生产物，
完成前返回等待，不写冻结C4入口，不部署。
派生自动接管目前未安装，不能把派生产物写进冻结C4 canonical receipts来唤醒旧服务。
主CAD保持8da24a26输入，FIT后已有自动实现/时序/bitstream流水线继续，不等待探针。
上板仍只允许21，须由唯一运行者在安全样本边界执行。

## 派生 Opt4-fit 自动链路（2026-11-10 已启用）

本节替代先前“派生自动接管未安装”。服务 `ec-parsec-opt4-fit-runtime.service`，
状态 `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-runtime-state.json`，
持久日志 `jobs/opt4-fit-runtime/console.log` 与 `Opt4-fit-runtime-logs/`。
单实例锁 `locks/opt4-fit-runtime.lock`；部署与样本共用既有21维护锁/单卡锁。
恢复先 `python3 scripts/job_service.py audit opt4-fit-runtime`，活controller/child按
PID/start_ticks/boot_id接管监控，不重复启动。确认全部退出才
`systemctl start ec-parsec-opt4-fit-runtime.service`；成功样本按result/complete哈希复用，
失败阶段按固定software signature记录并跳过；中断样本从程序起点重跑，保留原始证据。

当前无证书时仅每300秒读CAD状态，Native不受影响。认证后才写
`Opt4-fit-runtime-priority.json`，禁止旧入口新启动，等待现有样本结束，再21-only部署。
不得手工将priority状态改成ACTIVE、将派生产物写入冻结C4入口或修改software-suite来绕过门。
运行器/部署器仅在带正确 `--opt4-fit-receipt` 时接受派生版本。
所有可运行派生任务结束后priority自动YIELD，Native可继续；单个程序失败不会阻塞其他。
离线测试命令 `python3 scripts/validate_opt4_fit_runtime.py`，其结果严格标fixture，
不得视为FPGA通过；真实smoke、full_compare、四checker安装/排空和输出校验保持必需。

独立地址bit-heap proof/micro-map服务 `ec-parsec-opt4-fit-address-heap-proof.service`，
状态 `Opt4-fit-address-heap-proof-state.json`、证据 `build-logs/Opt4-fit-address-heap-proof-20261110/`。
先audit再恢复，不影响当前8da24a26整机或round3地址完整模块综合。


## 2026-11-10：用户暂停 Native，集中 Opt4 硬件实现

本节覆盖此前 Native 自动续跑描述。Native/coverage-first 已在最后样本 COMPLETE、
实际 PID 退出、协调器无 sample 子任务的安全边界 stop/disable；没有 FPGA、驱动或
PCIe 操作。暂停证据：`Experiment/firesim-final-opt4-20261106/Native-user-paused.json`，
以及该文件指向的 `interruptions/native-user-pause-*/` 原状态和服务前后快照。
网络软件修复未启动新作业；已完成的软件成果和原始样本不变。

未经用户要求恢复 Native，不要启动/enable `ec-parsec-native.service` 或
`ec-parsec-coverage-first.service`，包括重连/服务 reload 后。旧状态中的等待 PID
是历史记录，必须以进程身份与 systemd 实态判断。保留 Opt4-fit CAD、模块验证和
`ec-parsec-opt4-fit-runtime.service`；后者独立等待派生 bitstream 认证，部署严格21-only。

独立共享散射归约候选：`Opt4-fit-address-sort-20261110`，commit
`11edd71981aa30ff3a26aab1f2f7327ac0266ee1`，source ID
`f8a4239fe5a4818e15d98791f76d9d877172f342cdc0bc036ac6811e68de3cec`。
服务 `ec-parsec-opt4-fit-address-sort.service`；状态
`Experiment/firesim-final-opt4-20261106/Opt4-fit-address-sort-state.json`；
日志 `jobs/opt4-fit-address-sort/console.log` 与
`build-logs/Opt4-fit-address-sort-11edd719-20261110/`。
先 audit 精确 PID/start_ticks/boot_id，活实例只监控。确认退出后才从哈希绑定的
成功阶段收据继续；证明失败/超时不能算通过。验证/映射服务不自动晋升候选。

该候选共享组合排序和分段前缀和，替换每桶重复 N 路归约；保留全部256桶、
64位状态/65位溢出检查、队列/表容量、原事件与周期逻辑。只读比较确认桶增量
块以外源码不变。当前 8da24a26 整机、aca893e0 与 c41d42f 完整模块综合输入不变。
实际面积必须使用该候选完整模块报告；局部形式证明与回归不等于整机形式等价。


### 下一整机候选的容量门与衔接（11edd719）

`ec-parsec-opt4-fit-sort-system.service` 已启用，持久状态
`Experiment/firesim-final-opt4-20261106/Opt4-fit-sort-system-continuation-state.json`，
日志 `jobs/opt4-fit-sort-system/console.log` 与
`build-logs/Opt4-fit-sort-system-continuation-11edd719/`。
它只在新地址模块的局部证明、8192向量×1024输出实规模对照、冻结完整模块
6144周期×52输出对照全部通过，并取得至少25%真实LUT下降后，才编译新版本全部
六个源码、参数审计、私有类来源审计和GoldenGate。独立适配脚本与哈希在
`Opt4-fit-address-sort-20261110/pipeline/templates.json`，没有修改当前整机脚本。

下一整机 Vivado 仅在当前8da24a26实际post-opt状态为 NOT_FIT_POSTOPT 后启动；
当前版若已产生合格bitstream则优先当前版，不启动新CAD。工具失败不冒充NOT FIT。
下一版仍有独立容量门，超量停止于布局前；FIT才继续布局布线、时序、DRC和bitstream。
其profile为`Opt4-fit-C4-SVB32-sort-20261110`，不能用旧8da或冻结849的运行收据。
本衔接没有硬件部署权限入口；新版本产物仍须建立自己的完整软件/认证绑定再首验，
不可伪造旧profile。当前8da自动认证/21-only首验服务保持独立有效。

7项控制门离线正反测试通过，证据
`build-logs/Opt4-fit-sort-system-continuation-11edd719/offline-control-validation.json`；
它们是fixture，未访问FPGA。重连先audit本service和四个独立状态的PID/start_ticks/boot_id。
活进程只接管监控，成功阶段收据按精确source/输出哈希复用，失败证据原样保存。


### 共享归约候选的实际验证完成（2026-11-10 22:34 CST）

`11edd719` 已实际通过生成 RTL 比较交换绑定 SAT、128 路零一排序 SAT、3/4路
完整散射等价 SAT（在已证明的叶子边界下）；负变异被检出。实际80路、256桶、
四粒度组合对照8192组、每组1024输出全部一致。原冻结完整地址模块与候选在
6144周期、52输出逐周期一致。验证收据
`build-logs/Opt4-fit-address-sort-11edd719-20261110/verified-regressions.json`。
这些不是整机形式证明或FPGA验证，面积仍以实际模块综合结果为准。

验证程序曾有Verilator C++宽向量迭代接口编译失败，已修复，旧证据在harness-failure-v1；
随后单个约30MB生成函数的-O1编译超过17分钟，已只结束本轮新候选验证编译进程组，
保留日志/PCH/对象并从已成功证明收据以-O0续跑。其真实规模对照和完整模块对照随后
实际通过。没有向任何现有Vivado或FPGA进程发信号。
25个本来inactive的Native/网络软件服务也已disable自动启动；完整清单在Native-user-paused.json。


### 共享归约核真实映射与完整模块启动（2026-11-10 22:50 CST）

实规模80路、256桶、四粒度共享归约核已完成Vivado OOC映射：
**388,563 LUT、1,160 CARRY8、0 DSP、0 FF**。
报告 `build-logs/Opt4-fit-address-sort-11edd719-20261110/micro80/map/utilization.rpt`，
对应RTL、DCP与report哈希均在成功阶段收据。这个归约核比此前只求一个桶的探针
范围更大，不能互作面积基准，也不能与完整模块1,500,571 LUT直接相减。
完整候选PackageAddressStats已自动开始OOC综合，状态为RUNNING_MAP-FULL-ADDRESS；
完整模块资源报告尚未生成，不能提前宣称25%面积门通过或整机FIT。

当前8da24a26整机仍RUNNING_DUT_SYNTH，尚无资源/FIT/bitstream；所有旧Vivado
worker和输入保持不变。下一整机服务已在确认自身失败等待进程退出后恢复，
继续等待新模块实际资源门，无重复整机综合、无FPGA访问。
