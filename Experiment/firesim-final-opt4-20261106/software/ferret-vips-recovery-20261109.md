# Ferret / Vips 实际恢复与网络完整 ROI 诊断

更新：2026-11-09 12:50 UTC（北京时间20:50）。实际只访问21卡，C4/FPGA/coverage-first原服务未停止或重启；冻结硬件和bitstream未修改。旧33个正式有效样本不改写。

## Vips：启动前内存布局错误，已实际修复

原失败 `runs/native-vips-test-r1-20261109T042304Z` 在guest ready/应用启动前出现 `Kernel stack overflow`，epc/badaddr `0xffffff8004000000`。原OpenSBI DTB拷贝地址0x82200000落入加载于0x80200000的38,593,536字节内核Image。只重建固件，将FW_PAYLOAD_FDT_ADDR与FW_JUMP_FDT_ADDR设为0xbfe00000；应用ELF、rootfs、kernel、ROI、mem=2G和硬件不变。

新 `vips-safe-fdt` Native/C4固件均验证DTB不重叠；复用QEMU做boot/归档完整性检查。原队列动态读新profile后已在21执行并通过test与simsmall。它们不是正式性能样本。

|阶段|状态|ROI cycles|Host秒|输出|
|---|---|---:|---:|---|
|test|有效功能通过|205258452|234.344145|output.pixels/output.shape OK；result/complete有效|
|simsmall|有效功能通过|2668393167|395.790637|output.pixels/output.shape OK；result/complete有效|

状态与原始命令：[vips恢复](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/vips-safe-fdt-recovery.json)；[QEMU证据](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/vips-safe-fdt-boot-diagnostic.json)。未来计划仅将Vips固件profile改为safe-fdt，没有改运行任务输入。

## Ferret：目录遍历顺序差异，稳定软件profile已接入

原simsmall应用exit0且ROI完成，但output.txt整文件SHA不符。相同诊断ELF、官方simsmall与argv在QEMU Linux复现：16条查询均完整、唯一，每条排名/距离文本与旧串行参考完全一致，只是readdir顺序不同（initramfs与宿主文件系统目录顺序）。旧FPGA失败没有回收完整output，因果链先由同ELF的Linux差异复现支持；修复后Native FPGA simsmall已实际通过全部输出和ROI gate，进一步确认该最小修复能解除板级阻塞。旧失败输出本身仍无逐字节证据，不把离线文件冒充原FPGA文件。

独立 `ferret-serial-staged-stable-directory-order/1` 只对原preload helper收集的目录entries排序，排序在ROI前。原scan/JPEG/features/query/rank/结果格式化完整留在原ROI。计算源码与object不变；不是把失败结果排序后放宽正确性门。新profile的参考输出仍要求完整字节SHA，Native/Opt4同ELF/输入/线程/ROI。

ELF SHA256 `aa201077237e4a1c19167eb65cc3a59fcbbc44130e2454b2b60454d4fcf600be`。补丁 `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/ferret-order-recovery-20261109T123400Z/stable-directory-order.patch` / SHA256 `947b17b65494d064809a24ec7e23cfeb6c9b16217f342e6fef7ea5b0d2a2ae3d`。三输入QEMU user/Linux输出逐字节一致，且全部逐查询结果与原串行参考一致；diagnostic ROI trace没有同步syscall。

|输入|离线完整输出SHA256|FPGA|
|---|---|---|
|test|4d1802954a45bc028a3f725fd051d0f43c56d5b5c9c5b33724ec346af9119157|有效通过，24,112,674 cycles / Host187.882552s|
|simsmall|7e5346f70cfb376526399f589532e5af9b2c11bd5f4f36fc989d781e0a131331|有效通过，1,887,901,090 cycles / Host302.987259s|
|simmedium|3102067fb39cc04e71e4ffd5acb17e87688a4f92430882c07f6c632338c72784|等待实时FPGA结果，不将QEMU算通过|

[恢复状态](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/ferret-order-recovery.json)；[软件/配置复用审计](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/ferret-order-recovery-20261109T123400Z/software-reuse-audit.json)；[旧计划](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/plan-history/before-ferret-stable-order-20261109T123802Z.json)。两组新的apps/rootfs/kernel/safe-fdt固件就绪，现有coverage-first已自动完成test后simsmall，现正执行正式simmedium r1；未新建FPGA队列。后续先补正式r1再r2/r3，最终C4认证就绪仍走原优先验证链。

软件恢复服务已经正常退出，状态是BOUND_FOR_EXISTING_QUEUE；服务COMPLETE本身不算FPGA验证。期间两次固件构建守卫/诊断解析器失败保留完整日志；修复仅影响该软件服务，未重启任何正常CAD/FPGA服务。

## 网络：本轮新增离线成果与不能省略的限制

三个最新候选又实际执行了私有IPC/mount/net命名空间下的完整原ROI test，Netdedup全解码等于输入；Netferret/Netstreamcluster完整输出与既有同profile参考精确一致。Netferret stable-joined补齐真实hooks server ELF及hash（编译级，未假称checker通过）。之前三输入Linux/QEMU正确性证据全部保留复用。

|程序|本轮完整原ROI trace可直接证明的调用|状态|
|---|---|---|
|netdedup|futex, clock_nanosleep, clock_gettime, openat, write, mmap|OFFLINE_PROTOCOL_OUTPUT_AND_TRACE_PASSED|
|netferret|clone, futex, clock_nanosleep, clock_gettime, openat, read, write, mmap|OFFLINE_PROTOCOL_OUTPUT_AND_TRACE_PASSED|
|netstreamcluster|clone, futex, clock_nanosleep, clock_gettime, openat, read, write, mmap, shmget, shmat|OFFLINE_PROTOCOL_OUTPUT_AND_TRACE_PASSED|

上述是实际观察到的调用种类；多线程QEMU trace文本存在交错，解析计数可能不完整，prefix PID不是guest TID，不用它们计算体系结构时间或严格调用总量。

辅助输出文件/分配/CPU拓扑查询可研究预建与预驻留；但user-TCP定时器/收包worker、pthread管线创建和同步/阻塞是完整原工作量的一部分。初始化提前不能消除多线程BEGIN拒绝；只改time调用也不能解决clone/futex。不得把实际网络计算搬出ROI。

源码链已进一步核实：C4驱动拒绝get_nr_threads!=1及context_started；固件generation只允许第一次安装，未知SBI op返回ENOTSUPP；checker异常trap记fault后清satp并park，没有Linux syscall dispatcher；DacRoiController在running或ended&&busy的trap/特权/satp变化置fault8。故现有软件没有可合法暂停→syscall→重新arm且仍覆盖完整原ROI的接口。

Native原driver/observer没有C4的线程/trap限制，因此网络Native并非由硬件版本必然阻塞；仍需独立双进程guest启动、镜像/结果身份绑定与板级验证。当前网络profile不冒用正式单进程收据，不占用Ferret/Vips的恢复队列。

要让冻结C4兼容完整原ROI，尚需证明纯用户态协作执行保留全部网络/线程语义，或另行设计并版本化可处理中断/上下文、真实task比较/排空和连续总ROI的集成协议。后者会涉及软件和观察控制逻辑/bitstream的变更，尚未实施，也没有改冻结DUT或掩fault。本轮先继续13项可运行程序。

[网络完整证据](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/network-complete-roi-probe.json)；真实Netferret server SHA256 `149f41d3f340bdc2928e3289d79f42d9a96a265366a2f9a24136b38174a58fb7`。该profile formal_eligible=false。

## C4与恢复

Vivado worker11088/start10629仍在原synth_design；runme.log已有完成Cross Boundary and Area Optimization、资源报告、Applying XDC Timing Constraints的真实阶段记录，最新为Start Timing Optimization。最后日志2026-11-09 10:57:29 UTC；尚无.bit。CPU继续计算不保证Timing Optimization收敛，保持原作业，不重启。原c4-first等待最终bitstream版本/哈希认证及21安全边界，smoke/checker/排空门通过才进入正式。

新软件长任务沿用job_service：vips-safe-fdt-recovery、ferret-order-recovery、network-complete-roi-probe。每个都有instance/领域锁、jobs/<name>/console.log、PID/start_ticks/boot_id、原子状态与逐case完整证据。重连先audit和核对；活进程只监控，不停止或重复启动；确认退出才复用精确版本检查点补缺。统计快照不是指令检查点。

持续真实状态以COVERAGE_STATUS_LIVE.md、coverage-first-state.json、active-0000_21_00.0.json和runs/*/{result,complete}.json为准。
