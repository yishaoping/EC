# 软件 ABI 与历史配套核实

## 1. 身份与证据层次

[DIRECT_EVIDENCE] 历史源码根 H=/data1/gzh/EC/baseline/source，干净 detached HEAD 为 b3d7adddd1e2d2cf428dd933529de878226420cd。父提交 6d899a71d68e5e15cb4c108a48375ea60edb2280。Current 源码根 C=/data1/gzh/EC，HEAD 为 9b0f34648d5ef483fcebaef6bdfb2c18f1b5014f。下文路径 H/ 与 C/ 均指这两个绝对根，不是任意历史版本。

| 产物 | 身份（DIRECT_EVIDENCE） |
|---|---|
| 历史 ELF | H/Software/Test/test.riscv，18040 bytes，SHA256 5b27ff378ac84ac4c0c0a6f07999e456adffe0866c071ed17be56ed200454b34，Git blob 6c4d73c7ed8ea1e60077e53011fa1b84d8dc37dc。 |
| 修复 ELF | /data1/gzh/EC/baseline/software/fixed_candidate/test.riscv，103288 bytes，SHA256 f5f84a1727e1c5466bd69e5e89c96410f1622297c1e62bf31408f176a2b65610。 |
| 修复 loadmem | 同目录 test.loadmem_hex，SHA256 a3b7a4f8e50cc28101b0a51f55406595fb113f9695ca54ee912555138fe7894c。8192 行，每行 128 hex 字符，即 64 bytes；总解码 524288 bytes，物理起点 0x80000000。 |
| 修复 dump | 同目录 test.dump，SHA256 4eb697da506270ff39ff34e5a6c57b69154b4fffd58a9a762873dabd4e4ff9c7。 |
| 来源 manifest | 同目录 origin.stage1_workload.json；其 40 项 source/link-input hashes 全部与 C 下现有文件一致。完整哈希清单在 preservation.before.json。 |
| ISA/装载 | 两份均 RISC-V ELF64 little endian，entry=0x80000000。候选属性 rv64imafdc、double-float ABI；无 PT_INTERP、PT_DYNAMIC/动态节。历史 filesz=0x31f8、memsz=0x3538；候选 filesz=0x7df8、memsz=0x5f9c8，均为一个 PT_LOAD。 |

[DIRECT_EVIDENCE] 以地址映射到 PT_LOAD，按 dump 指令 hex 解码 little endian，核对历史 1664 个、候选 8056 个 dump 指令位置，均无字节差异。历史 dump 是选定函数集合，不据此声称覆盖全部代码。候选 main、handler、report_end 和 _exit 另用现有 objdump 只读核对。

[DIRECT_EVIDENCE] 依 H/chipyard/generators/testchipip/src/main/resources/testchipip/csrc/mm.cc:134-160 的行内反向字节解析，候选 loadmem 与 ELF 的整个文件段逐字节一致；BSS、段后填充均为零，范围 [0x80000000,0x80080000)。这闭合 ELF/loadmem 配对，不是执行兼容性证明。

[UNRESOLVED] 候选 .comment 包含 GCC 12.2.0 字符串，但没有完整历史编译命令/工具哈希/产物签名链；不能从源哈希匹配推导完全可重建。b3 的提交信息“v1跑通，从头开始”也不证明保留 ELF 的每项统计正确。没有本轮生成模型、simulator 或新运行身份。

## 2. b3 的原配软件是什么

[DIRECT_EVIDENCE] H/Software/Test/test.c:39-115 为 hart 0，__main:119-135 为 checker harts。真正 workload 在 H/Software/Test/test_workload.c:91-133：3 次混合整数/load/store、LR/SC、AMO、DIV、FP、ECALL/CSR 刺激，固定数据区 0x81000000..0x810008ff。不是 GAPBS BFS。

[DIRECT_EVIDENCE] H/Software/Test/compile.sh:47-55,77-103 使用 rv64imafd、静态 htif_nano.specs，test 支持源为 tasks.c、clint.c、ght_config.c、performance.c、store_stats.c、test_workload.c；134-148 strip 保留 _start/tohost/fromhost。配套运行框架是裸机 libgloss HTIF，不是 R-Kernel 启动的用户程序。

[DIRECT_EVIDENCE] b3 对父提交修改了 test.c、tasks.c、performance.c/.h、compile.sh、test.riscv 和 test.dump。tasks.c 的实际修正包括恢复后重读 mhartid 再发布共享统计、避免 checker 在 release 前 printf。父提交是 2026-07-28 的同一测试框架；不能以更早样例或提交信息替代 b3 的实际源码。

[DIRECT_EVIDENCE] b3 历史软件还包含一个自身的统计边界不一致：ghe.h:234-246、store_stats.c:5-9,52-65 发出 funct 0x79 读取 128-bit store 数据，但同一 b3 GHE.scala 的分支/response 没有 0x79。静态预期读回默认零，高低高循环能稳定返回零，不构成真实 store-count 证据。这不等同于所有硬件功能不配套，但不能宣称历史统计 ABI 全部已闭合。

## 3. ABI 差异表

证据列的 S 编号见 evidence_index.md。每行“兼容”均限静态接口，不是运行 PASS。

| 项目 | b3 原配软件与历史硬件 | 修复后候选/Current | 审查结论、接口类别、证据 |
|---|---|---|---|
| workload 入口 | _start -> _start_main -> main；非 boot hart 经 barrier 到 __main | 同样裸机启动；hart 0 main，hart 1..4 checker | [DIRECT_EVIDENCE] 启动约定相同；libgloss/runtime ABI。S1,S3,S11；ELF entry 与实际 startup 核对。 |
| START | custom1 funct31 开监测，funct70 rs1=1 开 replay/checking；之后读 cycle | 相同指令；候选 PC 0x8000035c/0x80000364，rdcycle PC 0x80000368 | [STATIC_INFERENCE] 历史 GHE/R_IC 接受该监测控制；硬件专用接口。不是仿真器 -x/dump-start。S1,S3,S5,S8。 |
| STOP | funct70 rs1=2；26 条展开 NOP；funct32；等 GHT status>=0x1ffff | 相同控制顺序，但 26 NOP 是带减计数/分支的 C 循环；候选 PC 0x80000394/0x800003a8，poll PC 0x800003cc | [DIRECT_EVIDENCE] 数字 26 不代表相同延迟或 drain；同一候选在两硬件上才有相同软件指令序列。S1,S3 与反汇编。 |
| 软件 ROI | cycle_start 在 workload 前，cycle_end 在 GHT 完成后 | 同概念；end rdcycle PC 0x800003d4；[PERF] boom_cycles=end-start | [STATIC_INFERENCE] 可定义共同 BOOM ROI，不是 BFS-only 时间。历史与修复 ELF 的 workload 不同，不能互相比 cycles。S1,S3,S4。 |
| 性能控制 0x76 | GHE 只保存 rs1[4:0]；bit0 reset，bits4:1 selector；旧计数持续运行 | 软件 bit5 START=0x20、bit6 STOP=0x40，Current 保存 7 bits 并驱动 traffic_start/stop | [DIRECT_EVIDENCE] b3 截去 bit5/6；候选 START/STOP 计数控制在 b3 不生效。单独此差异不证明 workload 挂；Current-only 统计控制。S5,S6,S8。 |
| interval 0x79 | 旧软件把带 xd 的 0x79 当 store-stat read，但 b3 GHE 无实现 | 候选 checker 发送 xd=0 的 0x79，rs1=5000；Current GHE 也无 interval 分支 | [DIRECT_EVIDENCE] 5000 是请求/打印值；[STATIC_INFERENCE] 所查活动 GHE 路径不应用它，不能当实测采样间隔。候选 ELF PC 0x80003a68。S2,S5,S6。 |
| timer flag 布局 | clint.c:14 uint32_t[4]，连续 16 bytes，ELF 中从 0x80003238 起，stride4 | aligned timer_flag_t[4]，每槽64 bytes；ELF base0x80007e40、size256，hart0..3 地址 7e40/7e80/7ec0/7f00 | [DIRECT_EVIDENCE] 普通共享 DRAM 数据结构；[STATIC_INFERENCE] 可以保留修复用于两版，独立于新增协议。S2,S3,S7。 |
| timer 参数 | TIMER_HARTS=4，limit50，next=mtime+0x20 ticks；hart4无 timer | 相同；类型从 uint32_t 改 int，仅在0..50内使用 | [STATIC_INFERENCE] 逻辑计数语义相同，cache 行为/中断相位可能改变；不可宣称性能中性。双方同 binary 可控制此软件因素。S2,S3,S7。 |
| timer/interrupt handler | handle_trap(epc,cause,tval,regs) 返回恢复PC；mtimecmp 初设用 high=max、low、high、fence | void handle_trap(void)，从 CSR 取状态并在 a0 放 mepc；初设 low/high 32-bit，重装64-bit SD | [DIRECT_EVIDENCE] handler 不是仅布局变化；候选 ELF a0 返回和既有 trap stub 的 csrw mepc,a0 配合。CLINT 地址/宽度历史硬件支持；实际中断时序和运行正确性 UNRESOLVED。S2,S7,S11。 |
| harts/共享数据 | 1 BOOM+4 checkers；timer0..3；storecount/ready[5]、UART lock | 同拓扑；hart_traffic[5][128]、ready[5]，release 后 secondary 发布统计 | [DIRECT_EVIDENCE] 共享数组是软件内部 ABI，不要求历史硬件硬编码相同地址；[STATIC_INFERENCE] 要保留启动 barrier、fence 与发布顺序。候选 ready 等待无软件 timeout。S1,S3,S4,S9,S11。 |
| checker/GHE | role01、event40/43、init51、copy60、RSU61、record64/75、72/73、custom3 JLR | 相同基本指令；候选还发送 mask7D=0xF/read7E | [DIRECT_EVIDENCE] mask7D/7E/7F 已存在 b3，不是此次 Current 才新增；S5:96-98,259-262。旧 ELU65/66 也无 GHE 分支，不能把旧软件注释“ELU self check”当完整检错证据。 |
| traffic/status 0x7B | b3 无 decode，custom1 路由按 opcode，未知 funct 默认返回0且握手响应 | Current 0x7B 有完整向量；候选用它读 allocated/completed/pending/stats_valid 等 | [STATIC_INFERENCE] 核心阻塞：候选把缺失的有效位零判为 HARD_ERROR；不是无害打印差异。S4,S5,S6，候选 report_end PC 0x80001658..0x8000173c。 |
| benchmark/输入 | mixed instruction iterations3，固定内存刺激 | stage1_amo_w_test + deterministic GAPBS BFS512，source0，每点16边，内置图，alpha15/beta18，无 argv/文件输入 | [DIRECT_EVIDENCE] 两种程序功能不同。不得以历史 ELF 对修复 ELF 直接做公平比较。S1,S3,S12。 |
| 退出 | main 返回0，libgloss _exit 循环写 fromhost=0/tohost=1 | main 同样返回0，即使 report或verified失败；_exit 改一次写 fromhost/tohost，fence 后自旋 | [DIRECT_EVIDENCE] HTIF 编码兼容历史 loader；[STATIC_INFERENCE] process exit0 不能代表正确性 PASS。S3,S10,S11。 |
| drain/最终检查 | GHT completion、26 NOP、store stats ready；harness 见 host success 就退出 | 软件新增 package/valid/pending 检查；Current harness 在 STAGE1_EXIT_PORTS 下等 stage1_l1_drained | [DIRECT_EVIDENCE] 当前/历史终止边界不同。GHT状态、软件统计drain、L1 drain、全系统drain必须分别报告。S4,S9,S10。 |

## 4. timer flag 修复的判断

[DIRECT_EVIDENCE] C/Software/Test/hw/interrupt.h:15-23 强制 64-byte size/alignment；定义在 interrupt.c:5，实际 handler 对各 hart 的访问在 ELF 中是 +0,+64,+128,+192。历史 CacheBlockBytes 默认64；该地址属于普通 DRAM，不是 CLINT 或特定 CSR。

[STATIC_INFERENCE] 修复可以安全作为 Baseline/Current 共同软件布局候选。它改变 false sharing 和 cache 访问的地址/行分布，不改变“各 hart 对自己的计数加一、50次后停 timer”、AMO 自测或 BFS 图与算法语义，不要求 Current 的 preservation/validation 协议才能寻址。不能从静态布局断言两硬件都已运行通过。

[STATIC_INFERENCE] 因此应优先保留相同64-byte布局，让两实现使用同一份最终审定软件，**不能为了匹配历史而回退 flags**。这项可复用结论不等于整个 fixed_candidate 的 Current-only report ABI 也可复用。

[UNRESOLVED] 候选 handler 的初次 mtimecmp 写顺序与历史不同，trap C 函数签名也不同；实际 ELF/stub 的返回约定已核对，但中断次数、相位、是否发生重入/提前MTIP未运行确认。32 tick 设定不保证每次在相同 BOOM PC 中断。任何未来软件适配必须保持双方相同 handler 和timer参数，不能只改一侧补偿 cycles。

## 5. R-Kernel 是否必需

[DIRECT_EVIDENCE] b3 的 Software/R-Kernel 是 gitlink 9978da2da42a5f53f690d99d92c64013a0cb72b9；该对象在当前根 Git 中不可解析。当前和 baseline/source 对应目录均为空，未定位到身份闭合的历史副本。该 gitlink 最近相关变更为 b87f893fd4e16a8d47c0a0f3b0599aa4a3f34b27（2026-06-13）。

[DIRECT_EVIDENCE] 两 ELF 均无动态加载器/共享库依赖。历史 compile.sh 的静态链接对象、当前 compile.sh:55-89 的 libgloss/encoding输入，以及所查历史 hardware build入口/启动器均不引用 R-Kernel。HTIF 的 loader 读取 ELF PT_LOAD 和 tohost/fromhost 符号，不启动 R-Kernel。源码范围与命令在 evidence_index.md。

[STATIC_INFERENCE] 对运行这些已存在 ELF，R-Kernel 既不是需要挂载的运行时、启动镜像，也不需要某个 R-Kernel 环境变量。其缺失不要求先恢复内核。重建 Software/Test 所需的是 newlib/libgloss/encoding/编译器等；b3 clone 中 libgloss 预编译 .a 未就位，只影响未来软件重链接，不妨碍加载已存在静态 ELF。未执行恢复或编译。

[UNRESOLVED] 不声称整个系统任何路径都不存在 R-Kernel 副本；只确认已审计路径和 Git 对象未闭合，也未审计该内核的可选功能。此缺口不改变上述静态 ELF 的依赖判断。
