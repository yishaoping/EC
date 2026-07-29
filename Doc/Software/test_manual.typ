#set document(
  title: "GuardianCouncil BOOM/Rocket 协同校验软件手册",
  author: "EC Project",
)
#set page(
  paper: "a4",
  margin: (x: 2.1cm, y: 1.9cm),
  numbering: "1",
)
#set text(
  font: ("Noto Sans CJK SC", "Droid Sans Fallback"),
  size: 10.5pt,
  lang: "zh",
)
#set par(justify: true, leading: 0.72em)
#set heading(numbering: "1.1")
#set table(stroke: 0.45pt + rgb("b8bec6"), inset: 5pt)
#show raw: set text(
  font: ("Noto Sans Mono CJK SC", "DejaVu Sans Mono"),
  size: 8.5pt,
)
#show link: set text(fill: rgb("185fa5"))

#align(center)[
  #text(size: 21pt, weight: "bold")[GuardianCouncil BOOM/Rocket 协同校验软件手册]
  #v(0.45em)
  #text(size: 11pt, fill: rgb("4a5560"))[
    `Software/Test` 源码组织、运行流程与维护约束
  ]
]

#v(0.8em)

#box(
  width: 100%,
  inset: 10pt,
  stroke: 0.8pt + rgb("5b6570"),
  fill: rgb("f5f7f9"),
  radius: 3pt,
)[
  *核心结论：* 本测试实现的是 hart 0 BOOM 大核与 hart 1 至 4 Rocket
  checker 小核之间的 checkpoint-and-replay 协同校验。大核产生检查窗口、
  上下文快照和不可重复事件；小核从检查点恢复并重放窗口。它不是逐周期
  lockstep，也不是五个 hart 同时运行同一份 C 负载。
]

= 文档范围

本文对应目录 `/home/gzh/EC/Software/Test`，主入口是 `test.c`。文档说明：

- 软件模块的职责和依赖关系；
- hart 0 与 hart 1 至 4 的启动、监控、重放和结束时序；
- GHT/GHE/RoCC、CLINT trap 和硬件累计性能计数接口；
- 编译脚本、性能模式、`.riscv` 和 `.dump` 产物；
- 修改核心数、平台地址、测试负载时必须同步检查的参数。

硬件机制的完整说明见：

- `DOC/Architecture/big_little_guardian_council_verification.typ`；
- `chipyard/generators/boom/src/main/scala/trans/GH_BUF.scala`；
- `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/`；
- `chipyard/generators/rocket-chip/src/main/scala/r/`。

= 测试目标

默认拓扑如下。

#table(
  columns: (0.8fr, 1.25fr, 4.3fr),
  table.header([*Hart*], [*角色*], [*职责*]),
  [`0`], [BOOM 大核], [配置过滤器和 checker 路由，打开监控，执行混合负载，等待检查完成并输出性能数据。],
  [`1..4`], [Rocket checker], [接收大核上下文和事件包，从检查点重放窗口，查询 ELU/RSU 状态并完成末端架构状态比较。],
)

端到端数据路径可以概括为：

```text
BOOM commit / LDQ / STQ / CSR / branch / ARF
  -> GH_BUF 过滤与打包
  -> GHM / AsyncQueue 跨核、跨时钟域传输
  -> Rocket checker GHE
  -> R_LSL / R_BJLR / R_RSUSL / R_ICSL
  -> 重放执行与 ELU 结果比较
  -> 完成状态和反压返回 BOOM
```

当前软件覆盖 FP、CSR、ecall、普通 load/store、LR/SC、AMO、乘除法、
软件中断、定时器中断、checker 路由和性能计数。测试正常结束说明主链路可以
完成一次无故障重放，但不等价于形式验证或完整故障覆盖率测试。

= 目录与模块

== 主测试模块

#table(
  columns: (1.7fr, 4.8fr),
  table.header([*文件*], [*职责*]),
  [`test.c`], [只保留顶层流程：hart 0 主流程和次级 hart 的 `__main()` 分发。],
  [`test_config.h`], [集中配置核心拓扑、CLINT 地址、定时器、完成状态、负载地址、排空长度和性能开关。],
  [`clint.c/.h`], [CLINT MMIO、MSIP/MTIP 配置、64 位 `mtime/mtimecmp` 访问和 HTIF trap 回调。],
  [`ght_config.c/.h`], [GHT 指令过滤器、SE 调度范围、checker mapper 和已激活 checker 数量。],
  [`test_workload.c/.h`], [产生 FP、CSR、ecall、load/store、LR/SC、AMO 和整数乘除刺激。],
  [`tasks.c/.h`], [Rocket checker 的初始化、上下文恢复、ELU 查询、完成比较、store 统计发布和资源释放。],
  [`performance.c/.h`], [cycle/CSR 指令计数、GHE debug counter 快照，以及由 hart 0 汇总输出 checker 性能。],
  [`store_stats.c/.h`], [读取各 hart 的 128 位 Storecount/Storecyclesum，以 fence/ready 协议发布结果，并由 hart 0 统一输出报告。],
  [`compile.sh`], [交叉编译、函数级垃圾回收、聚焦反汇编和最终 ELF strip。],
)

== 底层接口头文件

#table(
  columns: (1.55fr, 4.95fr),
  table.header([*文件*], [*职责*]),
  [`rocc.h`], [custom0 至 custom3 指令编码和固定寄存器内联汇编包装。],
  [`ght.h`], [GHT 状态、过滤器、mapper、SE、SATP/privilege 和监控命令的零开销内联包装。],
  [`ghe.h`], [checker GHE、RSU、ELU、性能计数和 Storecount 的零开销内联包装。],
  [`spin_lock.h`], [使用 `amoswap.w.aq/rl` 串行化多 hart UART 输出。],
  [`encoding.h`], [RISC-V CSR、异常原因和特权位定义。主测试使用工具链提供的 `riscv-pk/encoding.h`。],
)

这些底层头文件中的 `static inline` 是有意保留的例外：RoCC 指令需要在调用点
绑定寄存器并直接发射机器字。可配置参数和高层行为没有继续混在这些头文件中。

== 历史测试

`TC_MisPred.c`、`TC_OverTaking.c`、`TC_OverTaking_div.c`、`TC_Synth.c`、
`TC_Sys.c` 和 `interrup_test.c` 是历史/专项测试。它们保留各自的 `main()` 和
`r_ini()`，不参与默认 `test.c` 的模块化链接。构建脚本仍支持单独编译
`TC_*.c`，但默认手册和默认产物只针对 `test`。

= 配置入口

所有平台和实验参数集中在 `test_config.h`。

#table(
  columns: (2.65fr, 1.25fr, 2.7fr),
  table.header([*宏*], [*默认值*], [*修改约束*]),
  [`TEST_NUM_CHECKERS`], [`4`], [必须与 `GH_NUM_CORES - 1`、实例化的 checker 数和 SE 数一致。],
  [`TEST_NUM_HARTS`], [`5`], [由一个 BOOM hart 加 `TEST_NUM_CHECKERS` 派生，决定 store 共享结果槽数量。],
  [`TEST_NUM_TIMER_HARTS`], [`4`], [保持原测试行为：hart 0 至 3 有 MTIP，hart 4 仅做 checker。],
  [`TEST_CLINT_BASE`], [`0x02000000`], [必须与 Chipyard 地址映射一致。],
  [`TEST_TIMER_INTERVAL_TICKS`], [`0x20`], [单位是 CLINT `mtime` tick，不等价于 CPU cycle。],
  [`TEST_TIMER_INTERRUPT_LIMIT`], [`50`], [达到上限后关闭 MTIE 和机器态全局 MIE。],
  [`TEST_GHT_COMPLETE_STATUS`], [`0x1ffff`], [必须与硬件完成状态编码一致。],
  [`TEST_STORECOUNT_WAIT_CYCLES`], [`1000000`], [hart 0 等待五个 hart 发布 store 统计的 `rdcycle` 超时阈值。],
  [`TEST_BIG_CORE_CLOCK_MHZ`], [`200`], [BOOM Storecyclesum 从 cycle 换算为 ns 时使用，必须与 tile 时钟一致。],
  [`TEST_CHECKER_CLOCK_MHZ`], [`100`], [Rocket Storecyclesum 从 cycle 换算为 ns 时使用，必须与 tile 时钟一致。],
  [`TEST_PIPELINE_DRAIN_NOPS`], [`26`], [停止窗口后发射的连续 `nop` 数，使用汇编 `.rept` 保证数量。],
  [`TEST_WORKLOAD_MEMORY_BASE`], [`0x81000000`], [起止区间必须由平台为裸机测试保留，不得覆盖程序、栈、堆或设备 MMIO。],
  [`MEEK_ENABLE_BIG_CORE_PERF`], [`0`], [是否采集 BOOM 本地 GHE 累计计数器，通常由 `compile.sh -p` 设置。],
  [`MEEK_ENABLE_CHECKER_PERF`], [`1`], [是否采集各 Rocket checker 本地 GHE 累计计数器，通常由 `compile.sh -p` 设置。],
)

修改 checker 数时至少同步检查：硬件 hart 数、`TEST_NUM_CHECKERS`、
SE 数、`__main()` 的 hart 范围、CLINT timer hart 数和仿真配置。软件通过
funct `0x1c` 把已激活 checker 数量送入当前 GHE 硬件，不再使用不存在的
`0x7d/0x7e/0x7f` checker-mask 指令。

= 软件与硬件性能 ABI

当前软件以
`chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHE.scala`
为指令协议真值。性能相关 RoCC funct 如下。

#table(
  columns: (0.8fr, 1.5fr, 4.1fr),
  table.header([*Funct*], [*接口*], [*当前硬件语义*]),
  [`0x55`], [`ghe_csr_perf_read`], [按 rs1 索引读取 core CSR 性能计数输入。主测试用 index 0 统计提交指令。],
  [`0x76`], [`ghe_perf_ctrl`], [rs1 bit 0 复位本 hart 的 debug perf counters；bits 4:1 选择一个累计计数器。],
  [`0x77`], [`ghe_perf_read`], [返回当前 selector 对应的 64 位累计计数。],
  [`0x78`], [`ghe_raw_perf_read`], [返回硬件 RAW counter 输入；默认主流程不读取。],
  [`0x79`], [`ghe_store_counter_read`], [selector 0/1 返回 128 位 Storecount 的低/高 64 位，selector 2/3 返回 128 位 Storecyclesum 的低/高 64 位。],
)

*当前 RTL 没有动态采样周期、start/stop、trace buffer 或 record advance。*
旧软件曾把 `0x79` 当成 `ghe_fpga_perf_set_interval()`，并把 `0x76` 的 bit 5/6
当成 start/stop；但 `GHE.scala` 的 `debug_perf_ctrl` 只有 5 位，bit 5/6 会被
截断，而 `0x79` 已用于 store 统计。相关伪接口现已删除。

`performance.c` 对 debug counters 使用以下硬件匹配策略：

- 区间开始时用 `0x76` 脉冲 reset，清零本 hart 的 debug counters；reset
  拉低后硬件自动连续累计，不需要 start；
- 区间结束时依次选择并读取所需 counter，以软件快照代替不存在的 stop；
- store 统计不再混入 BOOM/checker 性能快照，因而不会重复输出
  `[BOOM_STORE]` 或 `[CHECKER_STORE]`。

`store_stats.c` 仿照参考目录 `Software/奇怪的循环test` 的跨 hart 汇总语义：

- 每个 checker 在最终完成状态后读取并发布本地统计，随后立即执行
  `ghe_release()`；checker 路径不再执行性能 `printf`；
- BOOM 在 GHT 全局完成后读取本地统计，再等待五个 ready flag；
- 每个 128 位硬件数采用 high-low-high 重读，避免低 64 位进位时撕裂；
- Storecount 输出低 64 位，Storecyclesum 保持 128 位，并分别按 BOOM
  200 MHz、checker 100 MHz 换算为 ns；
- Rocket 侧的计数窗口来自 R_ICSL 的完整检查会话，覆盖 checking、
  self-exception 和 postchecking 的普通/特权状态，不再仅依赖可能提前拉低的
  `checker_mode`/`checker_priv_mode`；
- checker store 第一次到达 WB 时即计数；若此时发生 `replay_wb`，硬件保存
  PC+指令标签并抑制同一条 store 的后续 retry，直到它非 replay 到达 WB 或
  当前检查会话结束，避免一条 store 被累计数百次；
- 发布顺序是写性能快照和 store 结果、`fence rw,rw`、写 ready；hart 0 看到
  全部 ready 后再执行 fence 并读取结果，超时 hart 显示 `not-ready`；
- hart 0 一次性输出 `Storecount[i]`、`Cyclesum[i]` 和 `Cycle Avg`。

Storecount/Storecyclesum 没有软件复位接口，因此这里报告的是各 hart
在发布点读到的硬件累计值，不是性能窗口的 `end - start`。多个 64 位 word
仍然通过连续 RoCC 命令顺序读取，会包含少量观测时间差。

`Cycle Avg` 保持参考实验定义：

```text
(Cyclesum[1] + Cyclesum[2] + Cyclesum[3] + Cyclesum[4] - Cyclesum[0])
/ Storecount[0]
```

公式中的 Cyclesum 已换算为 ns；减法饱和到 0，任一 hart 未就绪或
`Storecount[0] == 0` 时平均值输出 0。它是当前 BOOM/checker 实验的跨核
派生指标，不应解释为通用的单次 store 硬件延迟。

BOOM 的 `R_IC` 当前有效 selector 为 1 至 7，分别表示 scheduler blocked、
scheduler cycles、check cycles、other-thread、all-busy、scheduler-other 和
elapsed cycles。Rocket checker 的 `R_ICSL` 当前读取 selector 1/2/3/4/7/
10/11/12/13，分别表示 checking、postchecking、other-thread、nonchecking、
checkpoint 数、checkpoint transfer、worst latency、replay store 和 replay load。

= 软件执行时序

== hart 0：大核主流程

`main()` 按以下顺序执行：

1. `ght_configure(4)` 配置过滤器、SE、mapper，并通过 funct `0x1c` 设置已激活 checker 数量。
2. 打开 MSIE/MIE，并通过当前 hart 的 CLINT MSIP 给自己发送软件中断。
3. 轮询 `ght_get_initialisation()`，等待所有 checker 宣布就绪。
4. 记录 GHE CSR 性能计数起点，设置 SATP/privilege 上下文同步。
5. 配置 `mtimecmp` 和 MTIE；按性能模式复位 BOOM 本地 debug counters。
6. RoCC funct `0x31` 打开大核监控，funct `0x70`、rs1=`1` 打开检查窗口。
7. 记录 `rdcycle`，调用 `test_run_workload()` 产生混合指令刺激。
8. 按性能模式快照 BOOM debug counters，funct `0x70`、rs1=`2` 关闭窗口。
9. 连续发射 26 条 `nop` 排空在途控制，再用 funct `0x32` 停止监控。
10. 读取结束计数并轮询 GHT 状态，直到状态不小于 `0x1ffff`。
11. BOOM 发布本地 store 统计，并在最多 `1000000` 个 BOOM cycle 内等待四个 checker 发布。
12. 输出 CPU cycle、可选 GHE debug counter、CSR execution-inst 和统一 store 报告。
13. 清除 SATP/privilege 同步，并用 funct `0x30` 复位监控状态。

checker 初始化和 GHT 完成轮询没有软件超时。如果硬件无法到达这两个状态，
程序会保留在轮询位置，便于波形定位；store ready 等待有软件超时，但自动
回归仍必须配置外部仿真超时。

== hart 1 至 4：checker 流程

HTIF 次级核入口调用 `__main()`：

- hart 1 至 3 先自触发 MSIP，并配置周期 MTIP；
- hart 4 保持原有行为，不增加 CLINT timer 刺激；
- hart 1 至 4 随后统一进入 `checker(hart_id)`；
- 其他 hart 进入 `idle()`。

`checker()` 的关键阶段：

1. `ghe_asR()` 把 GHE 设为接收模式。
2. 设置 privilege 上下文，执行 `ghe_go()` 并发布 initialized 状态。
3. funct `0x75/0x73/0x64` 记录本地上下文、导入大核上下文并记录 PC。
4. 依次选择两个 ELU；状态非零时打印错误并用 funct `0x63` 出队。
5. 等待 checker 状态 `0x02`。若 RSU 状态 `(status & 0x18) == 0x08`，
   funct `0x60` 安装快照，custom3 跳转到恢复 PC。
6. funct `0x72` 保存 checker 末端上下文，funct `0x60` 触发最终比较。
7. 再次确认完成状态，发布本 hart 的 store 统计。
8. 可选输出 checker debug counters，释放 GHE 和 privilege 上下文，然后永久 idle。

= GHT 过滤和路由

`ght_config.c` 把被观察指令映射到检查包 GID 和数据来源。

#table(
  columns: (1.25fr, 1.05fr, 1.2fr, 2.95fr),
  table.header([*类别*], [*GID*], [*数据源*], [*指令/Opcode*]),
  [整数 load], [`0x01`], [LDQ `0x02`], [`lb/lh/lw/lbu/lhu/ld/lwu`, opcode `0x03`],
  [浮点 load], [`0x01`], [LDQ `0x02`], [`flw/fld/flq`, opcode `0x07`],
  [整数 store], [`0x02`], [STQ `0x03`], [`sb/sh/sw/sd`, opcode `0x23`],
  [浮点 store], [`0x02`], [STQ `0x03`], [`fsw/fsd/fsq`, opcode `0x27`],
  [CSR], [`0x03`], [PRF `0x01`], [`csrrw/csrrs/csrrc` 及立即数形式，opcode `0x73`],
  [Atomic], [`0x01`], [STQ+PRF `0x05`], [32/64 位 LR/SC/AMO，opcode `0x2f`],
)

代码还配置了 RVC load/store 过滤器。当前 `-march=rv64imafd` 没有启用 C
扩展，因此默认二进制不会产生压缩负载；这些配置用于保持硬件过滤表完整，
将来切换 `rv64imafdc` 时无需重新增加规则。

SE0 至 SE3 分别对应 checker hart 1 至 4。`r_set_corex_p_s()` 为每个 checker
配置普通事件包和上下文/快照包映射；已激活 checker 数量默认是 4。

= 混合负载

`test_workload.c` 只在 hart 0 上访问固定物理地址区间。checker 不调用这个函数，
而是依靠硬件提供的检查点和事件包进行重放。

#table(
  columns: (1.5fr, 2.25fr, 2.8fr),
  table.header([*刺激*], [*主要指令*], [*校验目的*]),
  [FP], [`float/double` 运算、类型转换], [覆盖 F/D 执行和浮点架构状态。],
  [CSR], [`cycle/instret/mhartid/fflags/frm`], [覆盖 CSR 事件包、PRF 结果和特权状态。],
  [异常], [`ecall`], [覆盖 trap 入口、mepc 更新及恢复执行。],
  [普通访存], [`ld/sd`], [覆盖 LDQ/STQ 地址与数据传递。],
  [原子访存], [`lr.w/sc.w/amoadd.w.aq`], [覆盖原子过滤、返回值和内存重放。],
  [整数运算], [`mulw/divw/divu`], [增加数据依赖，通过末端架构状态比较发现错误。],
)

三个汇编刺激函数使用扩展内联汇编并显式声明被修改寄存器和 `memory` clobber；
循环标签使用局部数字标签，避免函数复制或编译器优化时产生全局标签冲突。
原代码中未初始化的 C 循环变量已改为从 0 开始，固定执行三轮。

= CLINT 与 trap ABI

`clint.c` 使用以下寄存器布局：

```text
MSIP(hart)     = CLINT_BASE + 0x0000 + hart * 4
mtimecmp(hart) = CLINT_BASE + 0x4000 + hart * 8
mtime          = CLINT_BASE + 0xbff8
```

64 位 `mtime` 采用“高 32 位 -> 低 32 位 -> 再读高 32 位”的一致性读取。
`mtimecmp` 采用“high=UINT32_MAX -> low -> final high”的三写序列，避免更新期间
出现撕裂比较值和伪中断。

HTIF `trap_entry` 的 C ABI 是：

```c
uint64_t handle_trap(uint64_t epc, uint64_t cause,
                     uint64_t tval, uint64_t *registers);
```

启动代码把返回值写回 `mepc`。处理规则是：

- MSIP：清零当前 hart 的 MSIP；
- MTIP：递增当前 hart 计数，未达到 50 次时重装 `mtimecmp`；
- M-mode ecall（cause 11）：返回 `epc + 4`，跳过 32 位 `ecall`；
- 未识别异常：返回原 `epc`，保持历史上的重试行为。

旧代码声明 `void handle_trap()` 并依赖内联汇编碰巧把 `mepc` 留在 `a0`；现在的
签名与 HTIF 启动汇编一致，不再依赖未声明的调用约定。

= 性能模式

`compile.sh -p` 支持四种模式。

#table(
  columns: (1fr, 1.7fr, 1.9fr, 2fr),
  table.header([*模式*], [*BOOM 累计计数*], [*checker 累计计数*], [*适用场景*]),
  [`checker`], [关闭], [开启], [默认模式，观察各 checker 重放阶段。],
  [`big`], [开启], [关闭], [只观察 BOOM 大核监控窗口。],
  [`both`], [开启], [开启], [联合分析，会增加 RoCC 读取和串口输出。],
  [`off`], [关闭], [关闭], [最小观测扰动。],
)

也可用环境变量设置默认值：

```bash
export MEEK_PERF_MODE=both
```

硬件没有 interval 配置；四种模式均不会发送动态采样周期。所有模式都会保留
`rdcycle` 执行周期、GHE CSR perf index 0 的 execution-inst 差值，以及独立
于性能开关的五 hart Storecount/Storecyclesum 统一报告。因此 `-p off` 只关闭
debug counters，不会关闭 funct `0x79` 的 store 统计。

checker 的 checkpoint 恢复会覆盖通用寄存器，编译器保存于 `s2` 等寄存器的
`hart_id` 不能跨恢复点继续使用。`performance_begin_checker()` 和
`performance_end_checker()` 均在函数入口直接读取 `mhartid`，最终
`store_stats_publish()` 前也会重新读取一次。每个 checker 只写自己的
`volatile` 快照槽；hart 0 在 `store_stats_wait_all()` 的 ready/fence 握手后调用
`performance_report_checkers()`，统一读取 C1--C4 的快照并输出。

这一输出顺序也是完成协议的一部分。GHM 的 BOOM 完成状态依赖所有 checker 的
`ghe_release()` 事件；若 checker 在 release 前执行 HTIF/newlib `printf`，一个
checker 会长期持有 `uart_lock`，其余 checker 卡在 `amoswap.w.aq`，BOOM 则卡在
funct `0x06` 的 `ght_get_status()` 轮询。将输出集中到 hart 0 后，低速字符输出
不再位于 GHT 完成关键路径，同时不删除任何 GHE/GHM、性能或 store 计数功能。

= 构建

在 `Software/Test` 中执行：

```bash
export PATH=/home/gzh/EC/chipyard/.conda-env/riscv-tools/bin:$PATH
cd /home/gzh/EC/Software/Test

./compile.sh -c test -p checker
./compile.sh -r all -c test -p both
./compile.sh -c TC_MisPred -p off
```

脚本要求 Chipyard 配套 `riscv64-unknown-elf-*` 工具链和
`htif_nano.specs`。`-c` 参数不带 `.c` 后缀；`-r all` 清理 `.o`、`.riscv`
和 `.dump` 后继续处理同一命令中的 `-c`。`-o name` 只生成单独的 `name.o`。

默认 `test` 链接：

```text
test.c + tasks.c + clint.c + ght_config.c
       + performance.c + store_stats.c + test_workload.c
```

专项 `TC_*.c` 额外链接 `tasks.c + performance.c + store_stats.c`；这些文件
保留自己的 GHT/CLINT 框架。checker 会发布 store 端点，但只有默认 `test.c`
执行五 hart 等待和统一输出。

== 产物瘦身策略

编译脚本先生成带 `-g` 的临时链接结果，用它产生源码交叉反汇编；随后对最终
`.riscv` 执行 strip。具体措施如下：

- `-ffunction-sections -fdata-sections`；
- 链接器 `--gc-sections` 删除未引用函数和数据；
- dump 聚焦反汇编 trap、主/次入口、checker、CLINT、GHT、负载、性能函数，
  并保留 `printf/__swbuf_r/_write_r` 等实际使用的 newlib/HTIF 输出路径；
- 最终 ELF 删除 DWARF、`.comment` 和无关符号，但显式保留 `_start`、
  `tohost`、`fromhost` 及其最小符号/字符串表；FESVR 必须通过后两者定位
  HTIF 请求和应答地址；
- 中间 `.o` 和带调试信息的链接文件不会留在源码目录。

默认 checker 模式的原始版本与当前硬件适配版本结果：

#table(
  columns: (1.5fr, 1.45fr, 1.45fr, 1.8fr),
  table.header([*项目*], [*原始版本*], [*硬件适配后*], [*说明*]),
  [`.riscv` 文件], [`48,264 B`], [`18,040 B`], [保留 FESVR 必需符号，并包含统一性能/store 报告的格式化支持],
  [ELF `.text`], [`11,826 B`], [`11,014 B`], [包含 hart 0 checker 快照汇总、store high-low-high 读取和十进制 128 位输出],
  [ELF `.bss`], [`2,080 B`], [`824 B`], [包含五 hart 的 store 结果/ready 槽和 4 个 checker debug 快照],
  [`.dump`], [`215,237 B / 4,522 行`], [`128,939 B / 3,150 行`], [保留启动、HTIF syscall、`__swbuf_r` 和性能/store 汇总函数],
)

以上当前产物由 `./compile.sh -c test -p checker` 生成；因此 ELF 包含 checker
累计计数路径，不包含 BOOM 可选累计计数路径。

最终 ELF 仍保留 `.text/.rodata/.data/.bss/.htif` 和 RISC-V attributes。
HTIF 链接脚本会给单一 LOAD segment 设置 RWE，因此链接器仍提示 RWX warning；
这是当前 `htif.ld` 的段布局，不是本次模块拆分引入的新警告。

= 仿真运行

下面是 v0Config 的典型调用。实际模拟器目录和 make target 以当前 Chipyard
环境为准。

```bash
cd /home/gzh/EC/chipyard
source ./env.sh
cd sims/verilator

make CONFIG=v0Config run-binary-debug-hex \
  BINARY=/home/gzh/EC/Software/Test/test.riscv
```

运行时重点检查：

- 串口出现 activated checker count `4` 和初始化完成；
- 所有 checker 完成 initialized 握手；
- 没有持续出现 `Error detected for ELU`；
- hart 0 输出 `CPU execution took` 和 `CSR execution-inst`；
- hart 0 输出五组 `Storecount[i]`、`Cyclesum[i]` 和一个 `Cycle Avg`；
- 正常路径不出现 `storecount wait timeout` 或 `not-ready`；
- 最后出现 `[Boom-C0]: Test is now completed.`；
- 仿真没有在初始化或 `0x1ffff` 完成状态轮询处超时。

= 调试方法

== 使用 dump

`test.dump` 保留源码、地址、机器码和函数标签，优先检查：

- `trap_entry` 到 `handle_trap` 的四参数调用和 `mepc` 写回；
- `main` 中 funct `0x31/0x32/0x70` 的顺序；
- `checker` 中 funct `0x60/0x72/0x73/0x75` 和 custom3 跳转；
- `store_stats_publish` 中 funct `0x79` 的 selector 0/1/2/3 读取和 fence；
- `store_stats_wait_all` 的 ready 轮询超时，以及 `store_stats_print_report` 的统一输出；
- `performance_report_checkers` 是否只由 `main` 调用，以及
  `printf/__swbuf_r/_write_r` 中 HTIF 字符输出的实际 PC；
- `test_run_workload` 中是否存在 `ecall`、`lr.w/sc.w`、`amoadd.w.aq`、
  `csrrc/csrrwi/csrrsi/csrrci` 以及 FP 指令。

最终 `test.riscv` 已删除调试信息和绝大多数符号，源码诊断仍应使用
`test.dump`。ELF 中保留的 `_start/tohost/fromhost` 是启动和 HTIF 通信元数据，
不能为了继续缩小文件而删除。需要完整 DWARF 时，可临时跳过 strip，或在链接
完成、strip 之前保留调试 ELF；该文件不应作为长期仿真产物提交。

== 常见卡点

#table(
  columns: (2fr, 4.5fr),
  table.header([*现象*], [*优先检查*]),
  [卡在 checker 初始化], [hart 1..4 是否启动、GHE RoCC 是否挂载、funct `0x1c` 设置的 checker 数是否与硬件拓扑一致。],
  [BOOM 卡在 funct `0x06`，checker 卡在 `uart_lock`], [检查是否使用旧版 checker-side 性能输出。GHM 等待所有 `ghe_release()`；性能日志必须由 hart 0 在 ready/fence 汇总后输出。],
  [卡在 GHT 完成轮询但 checker 未等待锁], [GH_BUF/GHM 反压、checker 状态、RSU snapshot、ICSL 窗口计数和 ELU 队列。],
  [反复触发 MTIP], [`mtimecmp` 地址、`mtime` tick、hart 数、定时器上限和 MIE/MTIE 位。],
  [固定地址访问异常], [`0x81000000..0x810008ff` 是否属于可访问且保留的 DRAM。],
  [C3 的 PC 不在旧 dump], [旧地址 `0x80001dc2/0x80001df4/0x80001e06` 位于 newlib `__swbuf_r` 字符输出路径，说明 checker 正在执行 `printf`，不是未知代码；当前 focused dump 已加入这些运行时函数。],
  [dump 缺少其他函数], [该函数可能被内联或 `--gc-sections` 删除；先确认主流程是否实际引用，并按需加入 `compile.sh` 的 `dump_symbols`。],
  [ELF 出现 RWX warning], [检查 `htif.ld`；当前是 HTIF 链接脚本的单 LOAD segment 属性。],
)

= 维护原则

新增测试能力时遵守以下边界：

1. 可调参数放入 `test_config.h`，不要在多个 `.c` 文件重复硬编码。
2. `test.c` 只增加阶段调用，不把长汇编、过滤表或统计实现放回入口。
3. 新指令刺激放入 `test_workload.c`，同时在 `ght_config.c` 检查过滤器覆盖。
4. 新 checker 生命周期操作放入 `tasks.c`，不要让 checker 直接执行 BOOM 负载。
5. trap 行为放入 `clint.c`，并保持 `handle_trap` 的 HTIF ABI。
6. 新 debug 性能指标放入 `performance.c`，用性能模式控制观测扰动。
7. 跨 hart 的 store 统计只放入 `store_stats.c`，保持所有性能模式一致。
8. 新全局变量只能在一个 `.c` 中定义，头文件只写 `extern` 声明。
9. 修改后至少构建 `checker/big/both/off` 四种模式，并检查 dump 中关键指令。

当前测试的主要剩余限制是：checker 初始化和 GHT 完成没有内部轮询超时、
没有统一非零失败返回码、没有主动注入已知错误并断言 ELU 必须检测。因此批量
回归应同时解析 UART 错误字符串、store 超时/not-ready、最终完成字符串和外部
仿真超时。
