# 2026-11-04 Stage B 与 C4 综合诊断

结论：Stage B 当前是在完成有明确终点的 Linux 内存元数据初始化，已有实际地址推进证据，不能判为卡死。但原 native 软件配置效率不适合继续作为完整 PARSEC 的无期限等待路线。建议转向隔离的短 Linux/checker smoke；当前任务按用户要求保留，本轮不停止、不重复启动。

## 证据边界

- Stage B attempt：`20261103T132309.330455Z`，identity `b88c102b268ffddb3e93dc57b5c22b170d88ac858c1c7f696825ea104b4658e9`。
- 模拟器 PID 982710；runner 982695；等待 Stage B PASS 的 Stage C continuation PID 1002289。
- kernel receipt 来自运行 manifest 内固件绑定的 `native-HTIF-kernel-20261103T131553.567157Z/result.json`；实际 vmlinux SHA 与 receipt 相符。没有使用 latest 软件指针替代本次运行绑定。
- 只读取压缩日志的有限历史窗口和尾部，没有解压或读取整个日志。恢复 raw deflate 时用两种不同初始字典，仅采用两次结果完全相同的退休日志字段，排除依赖未知字典的字节。
- 一组有间隔的检查：资源/空间 15:25:30—15:34:48，目标指针 15:26:32—15:34:48（北京时间）。之后不再查询运行进展。

## Stage B 的实际调用及范围

直接证据链：`setup_arch → misc_mem_init → sparse_init`。`memory_present`/`memblocks_present` 内联进 `sparse_init`，在 `0xffffffff8060ffc0` 调用 `memblock_alloc_try_nid`，后者在 `0xffffffff8060e712` 调用 `__memset`。

日志在调用入口给出：

- `a2 = 0x01000000`，即 16 MiB；`a1 = 0`。
- `t0` 初值 `0xffffffd80edf5800`。
- `__memset+0x3c` 的 `add a3,t0,a4` 得到终点 `0xffffffd80fdf5800`。
- 分配器返回物理地址 `0x8eff5800`，日志给出的 `va_pa_offset = 0xffffffd77fe00000` 与上述虚拟地址一致。

因此本次正在清零的区间为虚拟地址 `[0xffffffd80edf5800, 0xffffffd80fdf5800)`，对应物理地址 `[0x8eff5800, 0x8fff5800)`。这不是在清零全部 256 MiB DRAM，也不是 checker 的 ROI。

对象是 `mem_section` 根指针表：`memory_present()` 中 `if (!mem_section)` 的首次分配。绑定内核启用 `CONFIG_SPARSEMEM_EXTREME`，RISC-V `MAX_PHYSMEM_BITS=56`、`SECTION_SIZE_BITS=27`，`sizeof(struct mem_section)=16`，每个 root 容纳 `4096/16=256` 个 section。故根表大小为 `8 × (2^(56−27)/256) = 16 MiB`，即使 guest 只有 256 MiB，该全物理地址宽度的根表仍为 16 MiB。仅缩小 DTB 中的 RAM 不会消除它。

循环体每轮执行 32 次 8 字节 store，随后 `addi t0,t0,256`，并比较 `t0 < a3`。本轮有效退休字段显示：

| 时刻（北京时间） | t0（下一个循环块） | 附近目标周期 |
| --- | --- | --- |
| 15:26:32 | `0xffffffd80f006700` | 14,928,022 |
| 15:34:48 | `0xffffffd80f011d00` | 15,031,301 |

指针前进 46,592 字节，目标周期前进 103,279；两个窗口内的精确 t0 样本均单调递增。较早历史窗口依次见 `...0edffd00`、`...0ee2a700`、`...0eef3700`，和当前地址顺序一致。没有观察到回到起点或重新发起同一根表分配。由于未读取全部日志，不对所有未采样区间声称已经排除每次重入。

直接症状已证明为有限清零；上游原因已证明为通用 56-bit SPARSEMEM 根表的首次零初始化；逐指令/缓存日志和单线程 RTL 是额外开销，但各项加速倍数未经对照测量。

## 耗时及路线决定

本轮约 495 秒推进 46,592 字节，约 94 B/s、208 个目标周期/s、0.451 B/目标周期。末次 t0 对应已处理 2,213,120 字节（13.19%），剩余 14,564,096 字节（13.89 MiB）。按相同速度，本次清零还需约 **43 小时**、约 **3230 万目标周期**；用 40—50 小时作为当前阶段的粗略范围。该估算仅覆盖这一次 memset，不覆盖后续页元数据、驱动、initramfs、用户程序或 PARSEC。

当前 guest 尚未输出 smoke command，package begin/result 均为 0。该路径使用 HTIF 和版本绑定的 init 自动执行，无需人工输入 shell。Linux 启动和 PARSEC 总剩余时间没有足够阶段成本数据，无法可靠估计；到 `max-cycles=200000000` 的上限仍可能需要约 10 天，这只是运行上限的速度外推，并非预计完成时间。

明确建议：**改善验证路线，不继续把现有完整 native PARSEC 当作默认等待项。** 保留原运行的证据及任务，在决定停止前采用本报告的具体依据与替代方案；本轮没有停止操作。

优先方案是独立的诊断 Linux 内核：将支持的最大物理地址宽度限制为 36 bit（覆盖 64 GiB；本 native guest 的 RAM/MMIO 均在该范围内），根表由 16 MiB 降到 16 字节。候选 `DIAGNOSTIC-ONLY-maxphys36.patch` 已通过 `git apply --check`，尚未应用、编译或运行。需在独立软件树内生成新 receipt、内核、固件和 attempt，保留原 RTL/checker 及原始软件。它是降低启动软件负担的诊断配置，不等于正式配置，不能直接和 B/FireSim 组成性能、slowdown 或 latency 比较。

先验证新软件能完成短 smoke、真实 package begin/result 与 drain/teardown，再决定是否只运行 Blackscholes 的最小正确性输入。不要先安排完整 PARSEC。原 Stage C continuation 仍只绑定原 smoke，通过前不会启动；本轮未改其绑定。

## 仿真开销

- `VM_THREADS=1`；主模拟器约占一个核，末次 RSS 111 MiB。OS 看到 256 个线程不表示模型用了 256 个核。
- `VM_TRACE=VM_TRACE_VCD=VM_TRACE_FST=0`，不是波形写盘拖慢；运行参数没有波形输出。
- `+verbose` 开启逐指令、空闲 checker 和缓存事务的 Chisel 输出。已产生约 11.96 GB 未压缩文本，压缩文件约 1.14 GB；本轮约 755 次 write 系统调用/s。格式化和输出开销明确存在，其耗时占比没有 profiler/A-B 数据，不能承诺具体倍数。
- Python collector 累计 CPU 约 4.3%，不是仅凭 gzip 就能解释主模拟器一个核的占用。未发现当前 CPU、内存或 IO pressure；模拟器和综合无任务内 swap 证据，不能把主要原因归于整机资源争用。
- 编译日志中有 `-O3 ... -Os`；最终生成模型热路径受最后的 `-Os` 控制。单独评估 `OPT_FAST=-O3` 或适度模型并行有可能改善，但收益待测，不能承诺线性加速，也无需先并发多个新构建。
- 不能直接删 `+verbose` 后宣称验证仍等价：目前 package/ROI 必需事件也由 Chisel printf 输出。若优化日志，应单独保留必要事件、断言、计数器与进度，再关闭逐周期/逐指令打印；该工作与新内核方案分别验证。

## C4 综合

构建启动器 PID 3626122；wrapper 综合 PID 3664002，末次运行约 20h34m，累计 CPU 74139 秒，RSS 20.2 GiB。对照中 CPU 从 73581 增至 74139 秒，辅助 worker 2702785/2702992 CPU 无增量。

已有的历史阶段证据：11 月 3 日其他 11 个 OOC IP 已生成 `.dcp` 和 `.vivado.end.rst`；主 wrapper 完成 RTL/资源推断报告和 XDC，11 月 4 日 07:20（北京时间）进入 `Timing Optimization`。

本轮没有新的阶段证据：`runme.log`（5,552,545 字节）、`.vds`、`vivado.pb` 的大小/时间不变；限定在该 run 的 `.Xil` 临时子树内，最新文件仍早于 07:20；综合进程 rchar/wchar/read_bytes/write_bytes 全部不变；无 wrapper end/error 标记、无最终 receipt。

因此结论严格保持 **持续计算，阶段推进未证实**。没有足够证据升级为“综合正常”，也不能据此确定死锁或给出完成时间。

## 空间

对照期间整个 `Experiment/dac2026` 分配空间从 2,213,638,144 增至 2,217,398,272 字节，增加 3,760,128 字节（3.59 MiB），约 0.54 GiB/天；压缩 RTL 增加约 3.54 MiB，是主要来源。按当前阶段速率，余下 43 小时约再增加 1 GiB。该任务日志单独看不会立即耗尽磁盘，后续阶段输出速率仍可能变化。

`/data1` 可用空间由 189,809,356,800 降至 189,070,680,064 字节，即 176.1 GiB，约 9m18s 少 704 MiB；绝大多数不是本实验目录增长。若全盘该消耗速度持续，粗略约 1.65 天即可耗尽，比本 memset 预测完成时间更短；这是短窗口外推，不能当作可靠剩余寿命。未扫描全盘定位他人写入，不能归属其来源。当前综合进程 IO 未增长，但后续 CAD 阶段空间需求未知。

这也是不宜继续盲等 43 小时的理由。后续应先与空间所有者确认增长来源或安排新的日志/构建存放位置，保留原始证据，不能自动删除本实验或他人文件。

本轮仅新增诊断报告、抽取证据、对照数据和未应用的补丁；没有修改运行源码、启动测试、生成波形、停止长任务或操作 FPGA/驱动/服务器。
