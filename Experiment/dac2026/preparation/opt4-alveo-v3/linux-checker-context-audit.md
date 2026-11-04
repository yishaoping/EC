# Linux/checker 上下文协议缺项（静态证据，未运行）

工作源码为 `/data1/gzh/EC/firesim/dac2026/work/opt4-alveo-v3/C4/chipyard/generators/rocket-chip/src/main/scala`。
具体文件 hash 和结论边界保存在相邻 `linux-checker-context-audit.json`；没有修改冻结功能源码或执行目标程序。

直接证明的事实：

- `rocket/Instructions.scala:1551` 起的 CSRshadowsindex/CSRshadows 定义了 mstatus/mie/mtvec/mscratch/mepc/mip、
  sstatus/sie/sscratch/sepc/scause/stval/sip，未包含 satp 或 stvec。
- `rocket/CSR.scala:578` 起的 CPS/ECP 接收写入 reg_shadow/reg_shadow_ECP；`:1207` 的 io.ptbr 仍由本地 reg_satp 驱动。
  不能从 CSR shadow CPS 已接收推断 Linux 用户进程的页表根已安装。
- `rocket/Frontend.scala:269` 起把 checker 取指接到 TLB/PTW，使用 s1_pc、实际 PTW privilege，passthrough=false；
  `:286` 的 ICache 物理地址来自 TLB 响应。没有在该路径看到“checker 无需地址转换”的依据。
- `guardiancouncil/GHE.scala:220` 起的 monitor 配置存储 satp PPN 用于进程选择；这一比较不等于向 Rocket 传送页表上下文。
- `Software/Test/core/secondary.c` 在一次 checker 会话后永久 idle，且仅列 hart1..4；原 checker 入口未提供 Linux 会话邮箱协议。

因此，**“旧 checker 外加 while 循环就成为 Linux checker runtime”没有源码依据**。
这不是一条已观察到的运行失败；尚无运行证据可以说明具体第一个 fault 或 deadlock 在哪里。
缺少正式的地址空间/特权/会话协议足以阻断当前 Linux/PARSEC 测量准入。

后续接入必须明确：为每个 epoch 固定 mm 生命周期及 satp mode/ASID/PPN；Rocket 使用何种权限进行取指和页表遍历；
sfence/ICache 无效化顺序；BOOM syscall/中断/地址空间切换产生的 package 归属；checker 本地 firmware CSR 如何保护；
完成/失败后何时允许释放进程页表和重启下一会话。DT 与 firmware 还须实际预留 Rocket harts。
CSR/packet 协议若扩展，应作为明确的 Linux 适配补丁单独记录，不能仍声称 Opt4 功能源完全未变。

基础 B BusyBox/Linux/OpenSBI 编译通过、B initramfs/DTB 打包通过，只证明构建基础可用，不能解除这些 blocker。
当前 `compatibility_evidence=null`、配置 ready=false、observer verified=false 继续保留；真实运行通过数为 0。
