#set document(title: "GuardianCouncil 软件测试阅读指南")
#set page(
  paper: "a4",
  margin: (x: 2.2cm, y: 2cm),
  numbering: "1",
)
#set text(font: ("Noto Sans CJK SC", "Droid Sans Fallback"), size: 10.5pt, lang: "zh")
#set par(justify: true, leading: 0.72em)
#set heading(numbering: "1.1")
#set table(stroke: 0.45pt + rgb("b8bec6"), inset: 5pt)
#show raw: set text(font: ("Noto Sans Mono CJK SC", "DejaVu Sans Mono"), size: 8.5pt)
#show link: set text(fill: rgb("185fa5"))

#align(center)[
  #text(size: 22pt, weight: "bold")[GuardianCouncil 软件测试阅读指南]
  #v(0.5em)
  #text(size: 12pt, fill: rgb("4a5560"))[`Software/test` 的测试目标、实现机制与源码导读]
]

#v(1em)

#box(
  width: 100%,
  inset: 10pt,
  stroke: 0.8pt + rgb("5b6570"),
  fill: rgb("f5f7f9"),
  radius: 3pt,
)[
  *核心结论：* 这套程序验证的是片上“1 个大核 + 4 个 checker 小核”的
  checkpoint-and-replay 冗余校验机制。它不是五个核共同完成同一份并行计算，
  也不是逐周期 lockstep。hart 0 上的 BOOM 大核正常执行；硬件在提交端提取
  关键事件和上下文，分发给 hart 1 至 4 的 Rocket checker，使 checker 从检查点
  重放一段指令窗口，并比较 load/store、CSR、控制流和最终寄存器状态。
]

= 文档范围

本文以 `/home/gzh/EC/Software/test/test.c` 为入口，解释 `Software/test` 下的
可维护源码和编译脚本。`test.riscv` 是静态链接后的 RISC-V ELF，`test.dump`
是反汇编生成物；二者用于运行和诊断，不是手工维护的源码。

与硬件架构的对应关系可继续参考：

- `DOC/Architecture/big_little_guardian_council_verification.typ`
- `chipyard/generators/boom/src/main/scala/trans/GH_BUF.scala`
- `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/`
- `chipyard/generators/rocket-chip/src/main/scala/r/`

= 这套 test 在测试什么

== 首要目标：端到端冗余执行校验

默认配置包含 5 个 hart：

#table(
  columns: (0.9fr, 1.4fr, 3.8fr),
  table.header([*Hart*], [*角色*], [*测试中的职责*]),
  [`0`], [BOOM 大核], [配置 GuardianCouncil，执行混合负载，产生检查窗口、事件包和上下文快照，最后汇总统计。],
  [`1..4`], [Rocket checker], [接收大核检查点与事件包，从快照状态重放窗口，检查不可重复事件和结束架构状态。],
)

被验证的端到端链路是：

```text
BOOM 提交/LDQ/STQ/CSR/分支/ARF
  -> GH_BUF 过滤并打包
  -> GHM + AsyncQueue 跨核/跨时钟域传输
  -> checker GHE
  -> R_LSL / R_BJLR / R_RSUSL / R_ICSL
  -> Rocket checker 重放
  -> ELU/完成状态/反压返回大核
```

因此，这不是一个只验证 `test_workload.c` 算术结果的单元测试。程序成功走完意味着
至少覆盖了软件控制命令、硬件过滤/打包、跨时钟域传输、checker 上下文恢复、窗口
重放、完成握手和统计回传。它仍不等价于完整形式验证：当前软件没有统一的 pass/fail
返回协议，部分错误仅打印到 UART，超时也不会令 `main()` 返回非零。

== 具体覆盖面

#table(
  columns: (1.25fr, 2.05fr, 3.25fr),
  table.header([*测试方面*], [*软件刺激*], [*希望覆盖的校验路径*]),
  [浮点执行], [`float`/`double` 加减乘除], [F/D 扩展执行、浮点寄存器状态进入上下文与结束点比较。],
  [CSR], [`cycle`、`instret`、`mhartid`、`fflags`、`frm` 的读写/位操作], [CSR/PRF 事件提取、checker CSR 重放以及特权上下文一致性。],
  [普通访存], [`ld`/`sd` 的固定步长地址模式], [GH_BUF 从 LDQ/STQ 取得地址与数据，R_LSL 在 checker 侧提供可重复响应。],
  [原子访存], [`lr.w`、`sc.w`、`amoadd.w.aq`], [原子指令过滤、地址/结果包、寄存器返回值及内存相关重放。],
  [整数运算], [`mulw`、`divw`、`divu`], [扩大窗口内数据依赖，最终通过架构寄存器结束点比较发现偏差。],
  [同步异常], [`ecall`], [`handle_trap()` 返回 `epc+4`，覆盖 trap 上下文及机器态 CSR 变化。],
  [异步中断], [每 hart 自触发 MSIP，并配置机器定时器], [在检查窗口前后引入软件/定时器中断，覆盖异步状态变化及恢复。],
  [调度和 CDC], [4 个 checker、200/100 MHz 时钟域、带完成等待], [SE 路由、GHM AsyncQueue、checker 反压和完成状态汇聚。],
  [性能观测], [GHE perf、Storecount、128 位 Storecyclesum], [检查窗口执行时间、调度阻塞、各 hart store 数和累计周期采集。],
)

== 明确不应误解为已覆盖的内容

- checker 不会调用 `test_run_workload()`。它重放的是硬件下发的检查窗口，而不是执行同一 C 函数形成软件级双模冗余。
- `task_synthetic_malloc()` 是保留的辅助负载，默认 `test.c` 没有调用；因此默认运行不能证明堆分配路径已被测试。
- `timer.c` 提供独立的 hart 0 单次定时器，默认主路径实际使用的是 `clint.c` 的统一 trap/周期定时器逻辑。
- GHT 初始化配置了 RVC load/store 过滤器，但 `compile.sh` 的 `-march=rv64imafd` 未启用 C 扩展，默认负载不会产生压缩指令。
- 当前没有软件注入一个已知错误并断言 ELU 必须检测到，因此主要验证“正常重放和状态通路可工作”，不是完整的故障覆盖率测试。

= 软件模块组织

#table(
  columns: (1.55fr, 4.9fr),
  table.header([*文件*], [*职责*]),
  [`test.c`], [只编排 hart 0 主流程和 hart 1 至 4 的 `__main()` 入口。],
  [`test_config.h`], [集中保存 5 核拓扑、超时、200/100 MHz 换算参数、排空长度和保留内存地址。],
  [`test_workload.c/.h`], [产生 FP、CSR、ecall、load/store、LR/SC、AMO 和乘除法刺激。],
  [`test_runtime.c/.h`], [完成状态轮询、跨核 Storecount 发布、128 位周期换算和汇总输出；实现 checker 生命周期钩子。],
  [`gth_init.c/.h`], [配置过滤器、数据选择、SE 调度范围和 checker 包映射。历史文件名是 `gth`，接口语义是 GHT 初始化。],
  [`tasks.c/.h`], [checker 接收模式、上下文/PC 控制、ELU 查询、RSU 恢复、完成与资源释放。],
  [`ght.h`], [Guardian Heart Table 的监控状态、过滤器、mapper、SE 和 SATP/privilege 控制接口。],
  [`ghe.h`], [Guardian Heart Engine 的状态、事件、初始化、RSU/ELU 和性能 RoCC 接口。],
  [`clint.c/.h`], [每 hart 软件中断、周期定时器、M-mode ecall 处理和 UART 锁。],
  [`timer.c/.h`], [默认路径之外的 hart 0 单次定时器辅助接口。],
  [`rocc.h`], [custom0 至 custom3 机器字编码、固定寄存器绑定和内联汇编封装。],
  [`spin_lock.h`], [用 `amoswap.w.aq/rl` 串行化多核 UART 输出。],
  [`compile.sh`], [以 HTIF nano specs 编译、静态链接并生成源码交叉反汇编。],
)

= 从启动到完成的时序

== 阶段 1：hart 0 配置过滤和路由

`main()` 首先调用 `r_ini(TEST_NUM_CHECKERS)`：

1. `ght_set_numberofcheckers(4)` 告诉硬件本次启用四个 checker。
2. `ght_cfg_filter()` 配置标准 load、store、CSR 和 atomic 指令。
3. `ght_cfg_filter_rvc()` 预配置压缩 load/store。
4. `ght_cfg_se()` 把 SE0..SE3 分别绑定到 checker hart 1..4。
5. `r_set_corex_p_s()` 为每个 checker 配置普通检查包与上下文/快照包映射。
6. `ght_debug_filter_width(0)` 取消额外调试宽度限制。

过滤器里的 `sel_d` 指定事件数据来源：例如 load 取 LDQ，store 取 STQ，CSR 取
PRF/CSR 相关数据。过滤器并不执行检查，它决定大核提交时哪些信息值得形成检查包。

== 阶段 2：每个 hart 完成中断冒烟测试和就绪握手

hart 0 调用 `csr_software_cfg()` 和 `msip_cfg()`，给自己发送 MSIP。hart 1 至 4 在
`checker()` 中先调用 `ghe_initailised(1)`，再经 `checker_initialised_hook()` 执行
相同的软件中断流程，并设置 `mtimecmp`、使能 MTIE。

`handle_trap()` 的行为：

- MSIP：写零当前 hart 的 CLINT MSIP。
- MTIP：暂时关闭 MTIE，累计 `timer_flags[hart]`，未达到 50 次则重装比较值。
- M-mode ecall（cause 11）：返回 `epc + 4`，跳过负载中的 32 位 `ecall`。

hart 0 轮询 `ght_get_initialisation()`，确保 checker 接收端已经启动后才打开监控。

== 阶段 3：打开 GuardianCouncil 检查窗口

主核执行：

```c
ght_set_satp_priv();
ROCC_INSTRUCTION(1, 0x31);          // 打开大核监控
ROCC_INSTRUCTION_S(1, 0x01, 0x70); // ISAX_Go / 启动窗口调度
```

`ght_set_satp_priv()` 让硬件捕获或控制检查所需的 SATP/特权上下文。`0x31` 打开
大核事件监控；`0x70` 的 rs1=1 使指令窗口控制逻辑进入运行状态。从这时起，
`test_run_workload()` 产生的相关提交事件可以进入 GH_BUF/GHM/checker 链路。

== 阶段 4：hart 0 产生混合指令刺激

`test_run_workload()` 先执行浮点和显式 CSR 读取，然后重复三轮固定汇编负载。
固定地址区间是 `0x81000000..0x810008ff`，每轮包括：

- Store 段：LR/SC、四个不同偏移的 `sd`、`divw`、`fflags/frm` 读写。
- Load 段：LR/SC、四个不同偏移的 `ld`、`mulw/divw/divu`。
- AMO 段：步长 16 字节的 `amoadd.w.aq`。
- 每轮前执行一次 `ecall`，由 `handle_trap()` 跳过后继续。

负载只允许 hart 0 进入固定物理地址访问段。checker 的等价执行来自硬件重放，
这点对理解系统非常重要。

== 阶段 5：checker 如何完成重放和比对

每个 checker 的软件入口是 `__main()`，核心控制函数是 `checker(hart_id)`：

1. `ghe_asR()` 把 GHE 设为接收/可靠性模式。
2. `ght_set_satp_priv()`、`ghe_go()` 和 `ghe_initailised(1)` 建立接收端。
3. funct `0x75/0x73/0x64` 准备记录、接收主核上下文并记录 PC。
4. 对 ELU 0 和 1 发出 `0x65` 检查；状态非零时打印错误并用 `0x63` 出队。
5. 轮询 `ghe_checkght_status()`。若 `(ghe_rsur_status() & 0x18) == 0x08`，用
   funct `0x60` 触发上下文复制，并执行 custom3 恢复跳转。
6. funct `0x72` 保存 checker 结束点上下文，`0x60` 推进最终复制/比较。
7. 完成钩子发布 Storecount，随后 `ghe_release()` 释放硬件资源。

软件只负责控制和轮询。真正的重放检查由 checker Rocket 内部模块完成：

#table(
  columns: (1.2fr, 4.9fr),
  table.header([*硬件模块*], [*在重放中的作用*]),
  [`R_ICSL`], [接收窗口指令计数，控制 checking/postchecking 状态，阻止 checker 越过窗口尾部。],
  [`R_LSL`], [接收大核 load/store/CSR 包；checker 模式下为流水线提供可重复的数据和地址响应。],
  [`R_BJLR`], [提供大核分支/跳转结果，避免预测差异产生假错误。],
  [`R_RSUSL`], [加载检查点 ARF/FARF/FCSR/PC，并在结束点比较 checker 架构状态。],
  [`R_ELU`], [汇总 load/store 观测和寄存器状态不匹配，供软件查询和出队。],
)

== 阶段 6：停止、排空和完成等待

主核执行 `0x70/rs1=2` 停止窗口，插入 26 条 `nop` 为在途指令和自定义控制传播
留出间隔，再以 `0x32` 停止监控。随后 `test_wait_for_ght_done()` 轮询状态，目标
阈值是 `0x1ffff`，最多等待 100,000,000 个 hart 0 cycle。

这个超时只保证软件不会永久等待。超时后程序打印最后状态并继续统计，因此自动化
测试若需要严格 pass/fail，应解析超时/错误日志，或后续把错误转换为非零退出码。

= 检查数据如何流动

== 普通事件包

BOOM 提交端的 load/store/CSR/branch 事件由 GH_BUF 形成 136 位包：

```text
packet[135:128] = 8-bit header
packet[127:0]   = 128-bit payload

header[7]   = enable/valid
header[6:3] = target checker hart id
header[2:0] = subtype
```

常见 subtype 是 load=1、store=2、CSR=3、branch/jump=4。包经 GHM 的每 checker
AsyncQueue 跨时钟域送到 Rocket checker，分别进入 LSL 或 BJLR。若 GH_BUF、CDC
或 checker FIFO 接近满，反压会最终阻止 BOOM ROB 继续 commit，防止检查信息丢失。

== 上下文包

大核 R_RSU 生成 ARF/FARF/FCSR/PC 检查点和结束点数据，经独立的 ARFS 通道送到
checker R_RSUSL。开始时 checker 从 checkpoint 恢复；结束时将本地架构状态与
end checkpoint 比较。普通算术指令不一定需要逐条事件包，因为它们的错误最终会
表现为架构寄存器不一致。

== 为什么不是 lockstep

大核和 checker 时钟分别配置为 200 MHz 和 100 MHz，且大核通常会继续执行后续
工作。checker 是按窗口异步追赶，而不是每周期和 BOOM 对齐。系统依靠检查点、
事件包、指令计数、结束点和反压维持语义一致性。因此阅读日志时不能用“两个核同一
周期执行同一指令”的模型解释。

= RoCC 控制指令速查

下表只列本测试主路径直接使用的命令。所有命令都通过 `rocc.h` 编码到 custom1，
恢复跳转例外地使用 custom3。

#table(
  columns: (1fr, 1.5fr, 4fr),
  table.header([*funct*], [*调用位置*], [*测试语义*]),
  [`0x1b`], [`ght_get_initialisation`], [读取 checker 初始化聚合状态。],
  [`0x1c`], [`ght_set_numberofcheckers`], [设置启用 checker 数量。],
  [`0x30/31/32`], [`test.c` / `ght_set_status`], [复位、启动、停止大核监控。],
  [`0x40/43`], [`ghe_go/release`], [启动或释放 checker GHE 事件通道。],
  [`0x50/51`], [`ghe_initailised`], [清除或设置 checker 初始化标志。],
  [`0x55`], [`ghe_csr_perf_read`], [按索引读取硬件 CSR 性能事件。],
  [`0x60`], [`tasks.c`], [触发 ARF 上下文复制/最终比较相关操作。],
  [`0x61`], [`ghe_rsur_status`], [读取 RSU 原始状态。],
  [`0x63`], [`tasks.c`], [把所选 ELU 的待处理项出队。],
  [`0x64/65/66`], [`tasks.c`], [记录 PC、选择 ELU 检查、读取 ELU 状态。],
  [`0x70`], [`test.c`], [rs1=1 启动、rs1=2 停止检查窗口调度。],
  [`0x72/73/75`], [`tasks.c`], [checker 上下文、主核上下文和 record 控制。],
  [`0x76/77/78`], [`ghe.h`], [性能控制、通用性能读取、RAW 停顿读取。],
  [`0x79`], [`test_runtime.c`], [select 0 读 Storecount，select 2/3 读累计周期低/高 64 位。],
)

= 性能与统计输出怎么解释

默认程序输出下列指标：

#table(
  columns: (1.65fr, 4.85fr),
  table.header([*输出*], [*含义和限制*]),
  [`CPU execution took`], [`rdcycle` 从负载开始到 GHT 完成等待后的差值，包含停止和完成等待，不是纯负载 cycle。],
  [`Execution-time`], [GHE 事件选择 `0x07 << 1` 后读取的硬件计数，具体计数边界由 GHE 实现定义。],
  [`Execution-inst`], [GHE CSR perf 索引 0 的结束值减开始值。],
  [`Sch-bloc-time`], [选择 `0x01 << 1` 后读取的调度阻塞事件计数。],
  [`Storecount[h]`], [hart h 通过 funct `0x79`、select 0 读取的 store 数。],
  [`Cyclesum[h]`], [select 2/3 得到 128 位累计周期，再按 hart 频率换算为纳秒。],
  [`Cycle Avg`], [当前实验公式：`(sum(checker cyclesum_ns) - main cyclesum_ns) / main storecount`，下限截为 0。],
)

周期换算公式是：

$ t_("ns") = ("cycles" times 1000) / f_("MHz") $

因此 `TEST_MAIN_HART_CLOCK_MHZ=200` 和 `TEST_CHECKER_HART_CLOCK_MHZ=100` 必须
与硬件 tile 时钟配置一致。`Cycle Avg` 是项目当前定义的派生指标，不能脱离硬件
Storecyclesum 的计数语义，把它直接当成通用的单次 store latency。

`test_publish_storecount()` 的跨核发布顺序是：写结果 -> `fence rw,rw` -> 写 ready
-> `fence rw,rw`。hart 0 只有在所有 ready 就绪后才汇总；等待超过 1,000,000 个
hart 0 cycle 时输出 `not-ready` 并令平均值为 0。

= 源码阅读顺序

建议按行为从上到下阅读，而不是先陷入 RoCC 宏细节：

1. `test_config.h`：先确认五核拓扑、频率、超时和内存地址。
2. `test.c`：建立完整时间线，知道每个阶段何时发生。
3. `test_workload.c`：看主核究竟产生哪些指令类型。
4. `gth_init.c`：把负载指令与过滤器 GID、`sel_d` 和 checker 路由对应起来。
5. `tasks.c`：理解 checker 软件只是控制硬件重放，而非执行相同负载函数。
6. `test_runtime.c`：理解完成条件、超时和最终统计。
7. `clint.c`：理解 MSIP、MTIP 和 ecall 如何改变检查窗口中的机器态上下文。
8. `ghe.h`、`ght.h`、`rocc.h`：最后查自定义指令细节。
9. 再进入硬件文档和 `GH_BUF/R_IC/R_RSU/R_LSL/R_BJLR/R_RSUSL` 源码。

= 构建与产物

在 `Software/test` 下使用 Chipyard 配套工具链：

```bash
export PATH=/home/gzh/EC/chipyard/.conda-env/riscv-tools/bin:$PATH
./compile.sh -c test
```

脚本执行三步：

1. 以 `-march=rv64imafd -O2 -specs=htif_nano.specs` 编译入口和支持模块。
2. 静态链接为 `test.riscv`；`--allow-multiple-definition` 用于兼容历史头文件定义。
3. 用 `objdump -d -S` 生成 `test.dump`，可核对 C 与自定义机器字。

`./compile.sh -r all` 的现有语义是“清理后重建默认 test”，不是只清理，因为
`source_file` 默认保持为 `test`。若自动化脚本需要纯清理，应调整脚本控制流。

= 修改测试时必须同步检查的配置

#table(
  columns: (1.7fr, 4.8fr),
  table.header([*修改项*], [*需要同步核对*]),
  [checker 数量], [`TEST_NUM_CHECKERS`、`TEST_NUM_CORES`、`NUM_TIMER_HARTS`、硬件 `GH_NUM_CORES`、SE 数量与 `r_set_corex_p_s()` 位宽。],
  [核频率], [`TEST_*_CLOCK_MHZ` 与 Chipyard tile frequency；否则纳秒统计错误。],
  [负载地址], [`0x81000000..0x810008ff` 必须可写、不会覆盖程序、栈、设备或其他 hart 数据。],
  [新增指令类型], [`gth_init.c` 是否有过滤规则、GH_BUF 是否会打包、checker 是否有对应重放模块。],
  [启用 C 扩展], [`-march`、RVC 过滤器和分支/PC 包中的指令长度语义。],
  [调整超时], [超时以调用 hart 的 `rdcycle` 计数，不是墙钟时间；异步 checker 变慢时需重新估算。],
  [改变 RoCC funct], [`ghe.h/ght.h`、GHE 硬件解码、本文速查表和 `test.dump` 必须一致。],
)

= 当前测试的判定与改进方向

当前可观察的异常信号包括：

- `Error detected for ELU`：checker 的 ELU 有待处理错误/观测项。
- `GHT completion timeout`：全局检查未在超时内达到完成状态。
- `storecount wait timeout` 或 `not-ready`：至少一个 hart 未发布统计。
- 程序未打印 `Test is now completed`：流程在更早阶段挂起或异常终止。

若把该程序接入回归测试，建议后续增加：

- 统一的全局错误位和非零退出码，而不仅依赖日志。
- 已知错误注入用例，明确断言 ELU/RSU 必须发现不一致。
- 对正常路径的期望 checker 完成掩码进行精确比较，而不是只用状态数值阈值。
- 把单次定时器和 malloc 辅助负载做成显式可选测试项，避免误认为默认已覆盖。
- 为每个 RoCC funct 建立软件枚举或命名封装，减少业务流程中的裸十六进制常量。

= 一句话复盘

`Software/test` 用一个混合指令负载驱动 BOOM 大核产生检查窗口，通过片上
GuardianCouncil 数据通路把不可重复事件和架构上下文送给四个异步 Rocket checker，
由 checker 硬件重放并比较结果，软件负责配置、启动、trap 覆盖、状态监管和统计收尾。
