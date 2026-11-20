# Performance-Only blackscholes simmedium：一次只读健康诊断

诊断结论：FPGA target clock 持续推进，Guest 已实际启动 blackscholes，但 checker hart1、hart3 已出现不可恢复的 OpenSBI 指令访问异常。本样本当前不具备有效认证条件；有效完成仍为 0/8，无 Slowdown。不能把时钟推进或进程存在理解为有效计算前进。

## 两次采样

|项目|第一次|第二次|
|---|---:|---:|
|北京时间|2026-11-17 10:08:20.606|2026-11-17 10:11:48.716|
|heartbeat target cycle|2,479,786,005|2,620,013,318|
|heartbeat 文件内累计秒数|3727|3937|
|UART 文件大小|13001|13001|
|RTL event 文件大小|410|410|

采样操作相隔 208.110 秒；文件内两条 heartbeat 记录相隔 210 秒（最近一条记录各自有采样延迟）。target cycle 增加 140,227,313，约 667,749 cycle/s。heartbeat.cc:34 调用 clock.tcycle() 读取 FPGA 计数，:40 用 std::endl 刷新到 heartbeat.csv；不是 CPU 占用推算，也不是仅 Host 循环计数。我们只读已有 heartbeat 文件，未另行发起 MMIO/latch 或采样写操作。

FireSim PID 1531902、RNs、CPU 99.9%；串行控制器 PID 1529793。21 卡仍为 xdma、PCIe Gen3 x16、runtime active，AER correctable/nonfatal/fatal 计数均 0。没有发现 Host 停机或 PCIe 错误；这不能排除 Guest/checker 停机。host.log 在开始仿真后本来就只在结束时写 summary，因此 mtime 不变本身不等于阻塞。

## 命令、输入与日志链

- 09:42:24：Guest READY 被识别，uart.in 写入唯一的 `/opt/ec-fpga/run-one blackscholes simmedium 1 blackscholes; echo EC_COMMAND_EXIT=$?`。
- 10:02:21 的历史读取：uart.log 9772 字节，只有命令回显，尚无 EC_SAMPLE_START。
- 10:03:15 前后：EC_SAMPLE_START、PARSEC Benchmark Suite、EC_PARSEC_BENCH_BEGIN id=0 已出现。这是 Guest 执行的独立确认，不只是 Host 发送成功。
- 10:06:59 之前已有 EC_OPT4_INSTALLED hart1–4 与 EC_OPT4_CONTEXT，随后 hart1/hart3 的 sbi_trap_error 寄存器转储。10:08–10:11 两次样本内无更多 UART/RTL 输出。

实际绑定的 rootfs `rootfs-20261106T123225Z/tree/opt/ec-fpga/run-one` 第 11 行先校验全部 25 个文件、总计 24,923,163 字节，第 14 行复制输入，然后第 15 行才 echo EC_SAMPLE_START。故约 20 分 51 秒的无标记区间定位于校验/复制准备区间，现有证据无法把这两项耗时进一步分开。校验输出重定向到 Guest /tmp/ec-integrity-$$.log，成功时不打印。

已从相同 rootfs 的展开文件及 manifest 核对 run-one、blackscholes ELF、simmedium 输入 in_16K.txt（1,034,991 字节）、argv 和 SHA256SUMS 的哈希全匹配。实际 argv 为 `1 in_16K.txt prices.txt`。EC_SAMPLE_START 之后的路径没有其他命令可以产生应用 banner，且 EC_OPT4_CONTEXT 来自该应用 ROI begin ioctl，因此可确认二进制成功执行，并已越过输入解析阶段到达 checker 初始化。不能以宿主机文件存在代替 Guest 当前 /proc 观察；没有第二条无扰动的 Guest 管理通道，未注入 ps/ls/strace，当前 Guest PID 和 R/S/D/Z 状态未知。

UART 桥 uart.cc:156–158 打开普通日志文件，put() 逐字节 ::write，无 stdio 块缓冲；shell echo 的 EC_SAMPLE_START 不应卡在应用 stdout 缓冲。应用的 Num of Options/Num of Runs 输出经过 FIFO+tee，printf 没有紧接 fflush，可能被块缓冲，缺少这些行不能用来断言输入未解析。bench-begin hook 明确 fflush，所以该行是应用执行证据。

ROI hook `apps-formal-20261106T123109Z/src/hooks/dac_roi.c:25–53` 先 mmap/residency、EC_DAC_BEGIN ioctl、EC_CMD(0x31)/EC_SET(0x70,1)，最后执行真实 `.word 0x6b100013`。它不向 UART 输出一个独立的 ROI-begin 字符串。当前只有一条硬件请求日志：CYCLE 2429063290、token=0x101、epoch=0、state=0、计数全零；其源码 printf 在 request.fire 上输出更新前寄存器，不能把它当 ARM 失败证明，也不能从没有后续 print 反推 marker 一定没有退休。准确结论是没有完整、可确认的有效 ROI/任务计数证据。

## 真正异常：checker trap

|hart|mcause|mepc / mtval|符号或地址归属|
|---|---|---|---|
|1|1（Instruction access fault）|0xffffffff80002e00|当前绑定 vmlinux 的 handle_exception|
|3|1（Instruction access fault）|0x0000003f9c8aa020|service_va 0x3f9c8aa000 + 0x20|

二者均进入 OpenSBI `sbi_trap_error`，并报告 `trap handler failed (error -2)`。该函数是 noreturn，输出后调用 sbi_hart_hang()（同构建源 lib/sbi/sbi_trap.c:71），不会自动返回 checker 服务。因此保持本 boot 继续等待不能恢复完整四 checker 的有效认证。

固件 ELF SHA256 与绑定收据一致。实际反汇编证明 ec_opt4_secondary 在 0x80006a32 写 mtvec=ec_opt4_trap(0x80006ab0)，ec_opt4_enter 安装 satp 并执行标准 mret；源码没有可据此直接认定的漏装 satp 或漏写 mtvec。为何故障最终经常规 OpenSBI handler 而非预期 checker 专用 handler，需要继续追踪 checker 的特权/CSR shadow、异常入口和管理/执行上下文切换。现有日志不能区分硬件 context 接管、固件运行时寄存器改变或其他上游原因；不能直接归罪于 DDR、面积优化或某个 RTL 改写。记录中的 mstatus 也不能孤立证明真实特权，checker 模式可能读取 shadow CSR，必须先和实际网表/源快照绑定。

## 与历史正常 blackscholes 比较

三个正式 Native simmedium 结果完全匹配应用/rootfs、1 thread、warmup0、2 GiB、200 MHz target 和 FASED 设置；只是 Native 硬件无 C4 checker 启动流程、实际 FPGA host 50 MHz，本轮为 10 MHz。

|Native 样本|完整 Host 时间(s)|ROI target cycles|
|---|---:|---:|
|r1|177.370|829,737,734|
|r2|176.580|828,230,479|
|r3|176.938|829,885,720|

r1 ROI begin/end ticks 为 1,752,562,345 / 2,582,300,079，Host 实际 target throughput 约 16.45M cycle/s。本轮约 0.668M，约慢 24.6 倍；这是仿真执行速率差，不是架构 Slowdown。r2/r3 旧 driver summary 的累积 target cycle 不能直接除当次 wall time比较吞吐。

历史 UART 没有逐行 Host 时间戳，历史状态仅 30 秒粒度且已覆盖，不能恢复 Linux READY→SAMPLE_START 或命令→ROI 的精确正常 wall 时间。因此不能认定 20 分钟一定是死锁，也不能声称已证明它正常。当前的严重异常判定来自明确的 checker trap，而非这个时间猜测。

## 下一步与已准备修复

1. 已保存两份日志、heartbeat、状态和 SHA256 清单；保持 21-only，未发送信号、未打开额外 UART、未停机/复位/重编程、未改 RTL/bitstream、未创建第二任务、未恢复周期巡检。
2. 原运行器 run.py:230 的 fatal list 只有 Kernel panic / EC_OPT4_INVALID / EC_SAMPLE_FAILED，漏掉 sbi_trap_error，导致明确 fatal 后仍显示 RUNNING 并等 12 小时。这是已证明的状态/失败检测缺陷。已准备独立 proposed-fatal-check.patch，同时增加最终 verifier 的 fatal 拒收；Python 编译和 git apply --check 通过，未应用到当前运行器，未中途改变当前样本。
3. 修复优先级为 checker 启动/管理到执行上下文、真实异常/CSR shadow/mtvec 关系；先在绑定软件与硬件快照上做静态对应和最小离线验证。尚无证据支持直接改 DDR、RTL、关闭 checker 或绕开 ARM。
4. 按本次明确禁止停止/复位的要求保留当前进程；诊断状态标记为 checker fatal，不能称为正常认证继续。没有在同一镜像上重复启动认证。真正恢复该 boot 的四 checker 需要超出本次只读范围的干预，当前没有实施。

当前不能产出 Slowdown，不能将本样本或整组计成功。
