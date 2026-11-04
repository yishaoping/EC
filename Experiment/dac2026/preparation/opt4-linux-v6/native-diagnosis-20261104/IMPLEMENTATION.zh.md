# 轻量诊断路线（2026-11-04）

旧 B/C 已按授权停用：`old-chain-stopped.json` 保存 PID 归属核对、停止原因、退出状态。旧 B 不通过，旧 C 未启动且永久取消 continuation；旧日志未覆盖。

诊断源码在 `firesim/dac2026/work/opt4-linux-v6/diagnostic36`，保留正式 Linux/OpenSBI/原 native executable。Linux 唯一新语义限制是 MAX_PHYSMEM_BITS 56→36（64 GiB 物理上限），SECTION_SIZE_BITS=27、Sv39、satp/PPN、64 位物理地址类型不改。全部 native DTS RAM/MMIO reg 区间、实际 firmware ELF PT_LOAD 均已核对，见 `diagnostic36-address-audit.json`。RoCC 指令字段、SBI extension ID 不是 MMIO 地址。原 16 MiB sparse 根表变成 16 字节；vmemmap 的虚拟保留范围不变。

诊断内核和带相同 checker 服务的 OpenSBI 编译成功。诊断 native 来自冻结的 C4 native 生成模型：只对 9 个 EC_OPT4_PACKAGE_BEGIN/RESULT/ROI 打印的 guard 去掉 verbose 条件，逆向修改逐字节还原审计已通过；功能表达式和 fatal assertion/stop 块不改。另加每 65536 harness 周期读取真实 BOOM cycle 的宿主进度输出。其余逐指令/缓存打印保留在模型内，由不传 +verbose 关闭。构建没有重新 elaborate RTL、没有关闭真实比较；单独 executable 和 receipt 保存于 diagnostic36。

先运行现有 stage-A short.riscv 测实际速度（native-short 新 attempt），以真实 begin/result 序号、full comparison fire、软件硬件计数一致和末尾排空判定。它是新增 native C4 观测链验证，不替代原已通过的 opt4 bare-metal Stage A，也不提前声称 Linux 已启动。

Stage B prepare 已通过：`linux/partial/20261104T082633.251577Z`，包含新内核、OpenSBI、native executable、DTS/DTB、原 app/rootfs/输入哈希及加载镜像绑定。短验证结束后顺序启动；不并行启动重型 native 实例。

Linux 当前支持范围仍为单进程、单线程、单 mm、一启动一次 ROI；checker hart 1..4 由 OpenSBI 保留，Linux 只使用 BOOM hart0。M-mode firmware 安装同一 satp，标准 mret 进入 U-mode RX 服务页；任务通过原 CPS/ECP COPY/JLR 机制重执行并在真实 full_check_complete/result fire 后交给 CDC/BOOM release。正常服务 U-mode、原合成异常处理 M-mode、服务结束 ecall 返回 M-mode 停泊是三条不同路径，本轮没有统一修改特权级。原 S-mode 合成返回不在本诊断支持范围。

应用 mlockall(MCL_CURRENT|MCL_FUTURE) 预留驻留页。尚未声明完全保证无中断：ROI 期间任何 trap、特权离开 U、satp 改变会使硬件 fault8 锁存，样本无效；生成失败/取消/丢弃为 fault16。timer 或不可避免的用户路径 trap 也必须判无效，不吞掉。END/DRAIN、四 hart 实际 satp 安装、真实 begin/result 序号、PASS/故障/积压、cleanup/CDC 空和 firmware 返回 mask15 均需真实日志证明。

该软件配置只用于协议/正确性诊断，slowdown_eligible=false。不能与冻结 B 的正式性能结果相除。Blackscholes test/in_4.txt 仍只作功能验证。

C4 CAD 原运行保持，driver 已构建但未执行，bitstream 尚无完成 receipt。无 FPGA/设备/XDMA 操作。

## Native 短验证真实结果

`native-short/partial/20261104T082544.031144Z/verification.json` 已有效提交：实际 C4 RTL 上 generated=completed=passed=21，21 个 begin/result 序号逐项对应，full_compare 均为真实硬件结果 fire 时的 1，failed/cancelled/dropped/outstanding/timeout=0。ROI 291050 周期，末尾排空 9844 周期；最终 BOOM 周期 347221，宿主耗时 1620.986 秒，实测 214.204 周期/秒。+verbose 关闭，必需事件仍完整。该速度与旧 Linux memset 窗口工作负载不同，不做加速倍数对比。Linux smoke 已由顺序执行器在短验证 PASS 后启动，尚不能据此声称新内核启动完成或 Linux checker 通过。

## 根据实测速率进一步缩小诊断软件

仅去除逐指令打印没有明显改善实测约 214 周期/秒，不能继续把它当作启动加速方案。首个 36-bit Linux smoke 目前仍是早期启动，未有应用/checker 结果。已先停用其自动 Stage C 调度，保留模拟器直至替代软件就绪；不会让过期软件自动进入 PARSEC。

新隔离 profile `diagnostic36-small`：通过已有 `mem=32M` 标准启动参数限制 Linux 可用 RAM（真实 native DRAM 容量仍 256 MiB，设备地址不变）；独立内核把 sparse section 从 128 MiB 缩至 16 MiB（SECTION_SIZE_BITS 27→24，仍大于 2 MiB pageblock），使 32 MiB guest 只需约 512 KiB struct-page 存储，避免即便减小 RAM 仍按整 128 MiB section 预分配元数据。MAX_PHYSMEM_BITS=36，根表 128 字节；Sv39/satp/PPN/驱动及 checker 逻辑不变。这是 Linux 元数据布局诊断修改，不是 opt4 比较语义修改，不作正式性能配对。

rootfs 只移除 ELF 非装载调试段，CPIO 从约 8.9 MiB 降到 2,663,424 字节。程序入口、PT_LOAD 属性和所有运行时代码/数据逐字节一致；strip-debug 在首个 PT_LOAD 中更新的 ELF section-header 元字段（e_shoff/e_shentsize/e_shnum/e_shstrndx）经明确归一化后比较，未声称整 ELF 字节相同。实际更小应用 SHA/BUILD/镜像哈希重新绑定；输入原样复制。不改算法，不缩短 Blackscholes 100 runs。开启启动阶段 kernel loglevel=7，以实际日志定位下一阶段，仍不启用 RTL +verbose。

较小诊断内核/固件已成功构建并通过 prepare，当前实际 Linux smoke attempt 为 `linux/partial/20261104T092509.309639Z`，由软件专用顺序执行器启动。原首个 36-bit diagnostic attempt `20261104T082633.251577Z` 的调度已取消，其绑定进程退出，原始 gzip/控制台/进度保留，标记为因诊断确认启动耗时过长主动停止且无效；完整结果目录没有其完成提交。旧调度会话结束时其管理子进程一并结束，未收到正常 exit 回调，因此 exit 记录保留 returncode=null/interrupted=true，不编造退出码。停止前保存了其原 runner.py，以便审计；后续 verifier 更改使用冻结 receipts 验证旧样本，仍为 INVALID。

`diagnostic36-small-audit.json` 记录新 RAM cap、元数据布局及全部来源。新 kernel Image 15,524,864 字节，rootfs 2,663,424 字节；32 MiB 对短程序和单线程 Blackscholes test 的适用性须由实际启动/分配结果确认，尚未声称 Linux 已启动。

当前最后合并检查见 `CURRENT-STATUS.json`：新的 32 MiB Linux smoke 正在真实 RTL 早期启动，已观察 BOOM 周期前进；尚无内核启动完成/guest smoke command/实际 Linux package 事件，不能称 Linux 或 PARSEC 已通过。软件专用顺序执行器继续接收日志并等待真实退出；smoke 有效且原子提交后自动构建绑定 test DTB/固件并运行 Blackscholes，不需要用户手动启动。不另起并行重型仿真。C4 bitstream 综合保持，未出现完成 receipt，未操作 FPGA。
