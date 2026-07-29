#set document(
  title: "BOOM/Rocket 协同校验 Workload 手册",
  author: "EC Project",
)
#set page(
  paper: "a4",
  margin: (x: 2.0cm, y: 1.8cm),
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
  #text(size: 21pt, weight: "bold")[BOOM/Rocket 协同校验 Workload 手册]
  #v(0.45em)
  #text(size: 11pt, fill: rgb("4a5560"))[
    `Software/Test` 代码结构、执行时序与维护约束
  ]
  #v(0.25em)
  #text(size: 9pt, fill: rgb("69727c"))[基于 2026-07-29 工作区版本]
]

#v(0.8em)

= 阅读目标与范围

本文面向第一次接触该 workload 的开发者。读完后应能回答以下问题：

- 五个 hart 分别执行什么代码，为什么 hart 0 与 hart 1 至 4 的入口不同；
- BOOM 何时开始和停止监控，Rocket checker 如何进入重放与比较流程；
- GHT 过滤器、调度引擎、checker mapper 和 checker mask 在哪里配置；
- workload 覆盖了哪些 RISC-V 指令、访问哪段内存、如何产生中断；
- 如何只生成 `test.riscv` 和 `test.dump`，如何在 Chipyard 中运行；
- 程序卡住或输出异常时，应先检查哪个状态；
- 修改源码时，哪些看似不规范的代码不能未经验证就“顺手修复”。

本文描述 `/home/gzh/EC/Software/Test` 当前内容。软件接口的最终语义还取决于
所使用硬件配置中的 GHT/GHE RTL；文中把“源码明确做了什么”和“硬件应如何
解释”分开说明。

== 最短上手路径

第一次阅读建议按这个顺序进行：

1. 先读本文的“系统结构”和“端到端执行时序”；
2. 对照 `test.c` 理解 BOOM 主流程；
3. 对照 `secondary.c` 和 `checker.c` 理解 Rocket 路径；
4. 再读 `checker_config.c`、`ght.h` 和 `ghe.h`；
5. 最后通过 `test.dump` 确认编译器实际生成的机器指令。

只想立即构建时执行：

```bash
cd /home/gzh/EC/Software/Test
./compile.sh
```

构建成功后，目录中保留的产物只有：

- `test.riscv`：可由 Chipyard 仿真器加载的 RISC-V ELF；
- `test.dump`：带源码交织信息的反汇编，用于确认实际指令流。

#pagebreak()

= 系统结构

== 基本术语

#table(
  columns: (1.35fr, 4.9fr),
  table.header([*术语*], [*在本 workload 中的含义*]),
  [BOOM], [hart 0 上的乱序大核，是被校验指令流的生产者。],
  [Rocket checker], [hart 1 至 4 上的小核，接收检查信息并执行恢复、重放和比较。],
  [GHT], [大核侧的路径。软件用它配置过滤、路由、监控目标和全局状态。],
  [GHE], [每个核可通过 RoCC 访问的控制接口。checker 用它声明接收模式、操作上下文、读取状态和释放资源。],
  [RoCC], [RISC-V Rocket Custom Coprocessor 指令接口。本项目把控制命令编码在 custom opcode 的 `funct` 字段中。],
  [ELU], [checker 侧用于校验事件或执行结果的单元。软件轮询两个 ELU 的状态。],
  [RSU], [checker 恢复路径的状态来源。特定状态出现时，软件安装快照并跳转至恢复 PC。],
  [CLINT], [Core-Local Interruptor，提供每 hart 的 MSIP、MTIMECMP 和全局 MTIME。],
)

== Hart 拓扑

#table(
  columns: (0.75fr, 1.55fr, 4.55fr),
  table.header([*Hart*], [*角色*], [*行为*]),
  [`0`], [BOOM 大核], [`main()`：初始化 GHT，触发中断，打开监控，执行混合 workload，等待 checker 完成并打印性能数据。],
  [`1`], [Rocket checker], [`__main()`：配置 MSIP/MTIP 后进入 `checker(1)`。],
  [`2`], [Rocket checker], [`__main()`：配置 MSIP/MTIP 后进入 `checker(2)`。],
  [`3`], [Rocket checker], [`__main()`：配置 MSIP/MTIP 后进入 `checker(3)`。],
  [`4`], [Rocket checker], [`__main()`：不注入 CLINT 中断，直接进入 `checker(4)`。],
)

`NUM_CHECKERS=4` 与 checker mask `0xF` 必须一致：mask 的低四位分别启用四个
checker。`TIMER_HARTS=4` 只覆盖 hart 0 至 3，因此 hart 4 没有本测试主动产生的
软件/定时器中断。

== 数据与控制路径

```text
hart 0: BOOM 执行 workload
        |
        | commit / load / store / CSR / atomic 等被过滤事件
        v
      GHT 过滤 + SE 调度 + mapper 路由
        |
        | 检查信息、上下文和状态
        v
hart 1..4: GHE -> 上下文恢复 -> checker 重放 -> ELU/RSU 检查
        |
        | checker 完成状态
        v
hart 0: 轮询 GHT 完成值 -> 打印结果 -> 复位监控
```

checker 并不从 C 入口重新调用 `main()` 中的 workload。它通过硬件传递的上下文
和事件进入校验过程，所以理解本程序时不能把它当成五个 hart 同时运行相同函数。

= 文件职责

== 顶层与功能模块

#table(
  columns: (1.7fr, 4.7fr),
  table.header([*文件*], [*职责*]),
  [`test.c`], [hart 0 的 `main()`，包含完整被测指令流、监控窗口和最终输出。],
  [`secondary.c`], [次级 hart 的 `__main()`；按 `mhartid` 分发 checker 和中断配置，最后进入 `idle()`。],
  [`checker.c/.h`], [Rocket checker 的初始化、上下文记录/恢复、ELU 查询、RSU 恢复和完成等待。],
  [`checker_config.c/.h`], [BOOM 启动时调用的 `r_ini()`；配置过滤器、四个 SE、mapper 和 checker mask。],
  [`interrupt.c/.h`], [CLINT 地址访问、MSIP/MTIP 配置以及 `handle_trap()`。],
  [`spin_lock.c/.h`], [定义 UART 全局锁并用 `amoswap.w.aq/rl` 串行化多 hart 输出。],
  [`test_config.h`], [checker 数、CLINT 地址、timer 参数和性能开关的集中配置。],
)

== 底层接口

#table(
  columns: (1.7fr, 4.7fr),
  table.header([*文件*], [*职责*]),
  [`rocc.h`], [custom0 至 custom3 的指令编码，以及 0、1、2 个输入和有/无返回值的内联汇编宏。],
  [`ght.h`], [GHT 状态、监控目标、过滤器、SE、mapper 和 checker 数量的 `static inline` 包装。],
  [`ghe.h`], [GHE 接收/释放、checker 状态、ELU/RSU、性能和 checker mask 的 `static inline` 包装。],
  [`cycle.h`], [`rdcycle` 的最小封装。],
)

这些头文件中的 `static inline` 有意保留：RoCC 宏需要在调用位置绑定固定寄存器
并发射机器字，不适合改成普通外部函数。`test.c` 虽然以主函数为主，但其中的
汇编负载本身就是测试内容，不能仅按 C 层“代码整洁度”判断是否可拆分。

== 构建与产物

`compile.sh` 只链接以下六个源文件：

```text
interrupt.c
test.c
secondary.c
checker_config.c
checker.c
spin_lock.c
```

其他文件只有被这些源文件包含时才参与构建。脚本使用临时目录保存链接和
反汇编过程中的中间结果，退出时自动删除临时目录，最后只移动
`test.riscv` 和 `test.dump` 回当前目录。

= 构建与运行

== 工具链查找顺序

构建需要 `riscv64-unknown-elf-gcc` 和同目录的
`riscv64-unknown-elf-objdump`。脚本依次查找：

1. 当前 `PATH`；
2. `RISCV/bin`（即环境变量 `RISCV` 指向目录下的 `bin`）；
3. 仓库中两个预设的 Chipyard Conda 工具链路径。

推荐先加载 Chipyard 环境，再构建：

```bash
cd /home/gzh/EC/chipyard
source ./env.sh
cd /home/gzh/EC/Software/Test
./compile.sh
```

关键编译选项如下。

#table(
  columns: (1.8fr, 4.65fr),
  table.header([*选项*], [*影响*]),
  [`-march=rv64imafd`], [生成 RV64 I/M/A/F/D 指令，不启用 C 压缩扩展。],
  [`-O2`], [优化会直接决定最终校验可见的机器指令流。],
  [`-static`], [生成静态 ELF。],
  [`-specs=htif_nano.specs`], [使用 HTIF 裸机启动与精简运行时；次级 hart 入口和 trap 接入依赖该环境。],
  [`-fno-common`], [避免多个暂定定义被静默合并。],
  [`-fno-builtin-printf`], [保持工程运行时的 `printf` 调用方式。],
)

链接器可能提示 ELF 含 RWX `LOAD` segment。若脚本最终打印两个 `generated:`
路径且返回 0，该提示本身不是构建失败；如果平台要求更严格的段权限，应从
HTIF specs/链接脚本层面处理，不能通过随意改变 workload 链接方式来隐藏警告。

== 在 Chipyard Verilator 中运行

当前仓库的仿真目录是 `chipyard/sims/verilator`。使用绝对二进制路径可以避免
`Test/test` 大小写或相对目录层级错误：

```bash
cd /home/gzh/EC/chipyard
source ./env.sh
cd sims/verilator
make -j32 CONFIG=v0Config run-binary-debug-hex \
  BINARY=/home/gzh/EC/Software/Test/test.riscv
```

`run-binary-debug-hex` 会生成带调试信息的仿真并通过 loadmem 加载 ELF 转换结果，
对应的日志、反汇编日志和波形位于 Verilator 的 `output` 路径中，具体文件名由
Chipyard Makefile 和本次配置决定。仅需要快速运行、不要详细指令日志时，可在
确认调试版本正常后使用相应的 `run-binary-fast-hex` 目标。

这个 workload 使用自定义 RoCC/GHT/GHE 接口，不能在普通 Spike、QEMU 或没有
这些硬件模块的标准 Rocket 配置上得到等价行为。

= 端到端执行时序

== 启动阶段

HTIF 运行时让 hart 0 进入 `main()`，次级 hart 进入 `__main()`。两条路径并行
启动，没有由软件创建线程。

hart 0 首先执行：

1. `r_ini(NUM_CHECKERS)` 配置四个 checker 的过滤和路由；
2. `csr_software_cfg()` 打开 `mie.MSIE` 与 `mstatus.MIE`；
3. `msip_cfg()` 写当前 hart 的 CLINT MSIP，主动产生一次软件中断；
4. 打印 `Software interrupt test complete!`；
5. 轮询 `ght_get_initialisation()`，直到 checker 初始化完成。

hart 1 至 3 分别打开并触发软件中断、设置 `mtimecmp`、打开 MTIE，然后进入
`checker()`。hart 4 直接进入 `checker()`。每个 checker 调用
`ghe_initailised(1)` 后，hart 0 才有机会通过初始化轮询。

初始化轮询没有超时。若日志只出现 GHT 配置输出或软件中断完成输出，随后长期
无进展，应优先检查四个 checker 是否全部到达 `ghe_initailised(1)`，以及硬件
聚合初始化状态是否回到 hart 0。

== Hart 0 的监控窗口

通过初始化屏障后，`main()` 的顺序如下：

1. 读取 `mhartid` 并打印测试开始和性能配置；
2. 用 `ghe_csr_perf_read(0)` 保存 CSR 性能计数起值；
3. `ght_set_satp_priv()` 捕获当前 SATP/特权上下文作为监控目标；
4. 设置首次 `mtimecmp` 并打开 MTIE；
5. funct `0x31` 把 GHT 置为测试开始状态；
6. funct `0x70`、rs1=`1` 打开 checker 控制窗口；
7. 读取 `rdcycle` 起值并执行 FP、CSR、异常、访存和 atomic 混合负载；
8. funct `0x70`、rs1=`2` 关闭 checker 控制窗口；
9. 连续执行 26 条 `nop`，为在途控制与数据提供排空空间；
10. funct `0x32` 把 GHT 置为测试结束状态；
11. 保存 CSR 性能计数终值；
12. 轮询 `ght_get_status()`，直到返回值不小于 `0x1FFFF`；
13. 读取结束 cycle，打印耗时和 CSR 指令计数差；
14. 清除 SATP/特权监控目标，并用 funct `0x30` 复位 GHT 状态。

注意：源码使用的是 `status < 0x1FFFF` 的数值比较，不是严格相等比较，也没有
超时。`0x1FFFF` 是当前软件采用的完成阈值；若修改 checker 数或硬件状态编码，
必须重新确认这个判断。

== Checker 的重放路径

每个 hart 1 至 4 都执行同一份 `checker(hart_id)`：

1. `ghe_asR()` 将本 hart 声明为接收/checker 模式；
2. 设置 SATP/特权上下文，执行 `ghe_go()`，发布 initialized；
3. 按软件接口依次配置性能区间；
4. funct `0x75` 请求记录上下文；
5. funct `0x73` 选择来自大核的上下文；
6. funct `0x64` 记录恢复 PC；
7. 对 `sel_elu=0` 和 `1` 分别选择 ELU，若状态非零就打印错误并出队；
8. 等待 `ghe_checkght_status()==0x02`；
9. 等待期间若 `(ghe_rsur_status() & 0x18)==0x08`，先用 funct `0x60`
   安装/复制快照，再执行 custom3 的恢复跳转指令；
10. 停止软件定义的性能区间，funct `0x72` 选择 checker 末端上下文；
11. funct `0x60` 触发末端复制/比较，再次等待状态 `0x02`；
12. `ghe_release()` 释放 checker 资源，清除 SATP/特权目标，永久空转。

checker 正常完成后不会返回到运行时，也不会打印 PASS；末尾的无限循环是设计
行为。全局是否完成由 hart 0 的 GHT 状态判断。

== 时序关系速查

#table(
  columns: (0.7fr, 2.85fr, 2.85fr),
  table.header([*阶段*], [*BOOM / hart 0*], [*Rocket / hart 1..4*]),
  [`A`], [配置 GHT、触发 MSIP。], [进入接收模式，配置中断。],
  [`B`], [等待初始化聚合状态。], [发布 initialized。],
  [`C`], [设置监控目标，打开窗口。], [记录/装入上下文，准备重放。],
  [`D`], [执行混合 workload。], [处理检查信息，查询 ELU/RSU。],
  [`E`], [关闭窗口，执行 26 个 `nop`。], [完成末端上下文比较。],
  [`F`], [等待 `status >= 0x1FFFF` 并输出。], [释放资源后永久 idle。],
)

= GHT 过滤、调度与路由

== `r_ini()` 做了什么

`checker_config.c` 中的 `r_ini(4)` 是 BOOM 侧唯一的集中配置入口，顺序为：

1. 用 funct `0x1C` 告诉硬件本次激活四个 checker；
2. 写入普通 32 位指令和 RVC 指令的过滤表；
3. 配置四个 scheduling engine（SE）；
4. 为 core id 1 至 4 写入 mapper；
5. 把 debug filter width 设为 0；
6. 用 funct `0x7D` 写 checker mask `0xF`，再用 `0x7E` 回读；
7. 串行打印 mask 和初始化完成信息。

虽然默认编译使用 `rv64imafd`、不会生成 C 扩展指令，配置代码仍保留 RVC
load/store 过滤项。这些条目属于硬件过滤表初始化，不代表当前 ELF 一定包含
压缩指令。

== 过滤类别

#table(
  columns: (1.25fr, 0.9fr, 1.15fr, 3.2fr),
  table.header([*类别*], [*Index*], [*sel_d*], [*匹配内容*]),
  [Load], [`0x01`], [`0x02`], [整数 load opcode `0x03`、浮点 load opcode `0x07`，以及对应 RVC 形式。],
  [Store], [`0x02`], [`0x03`], [整数 store opcode `0x23`、浮点 store opcode `0x27`，以及对应 RVC 形式。],
  [CSR/System], [`0x03`], [`0x01`], [opcode `0x73` 下 funct 1、2、3、5、6、7，即寄存器和立即数 CSR 类。],
  [Atomic], [`0x01`], [`0x05`], [opcode `0x2F` 下配置的 32/64 位原子类。],
)

这里的 `index`、`func`、`opcode`、`sel_d` 最终被 `ght.h` 打包成 GHT 配置字。
`sel_d` 的精确数据源语义以目标 RTL 为准；软件只负责按上述常量写入。

`ght_cfg_se()` 配置四条记录：SE0 至 SE3 的起始 id 分别为 1 至 4，结束 id
也分别为 1 至 4，policy 均为 1。随后 `r_set_corex_p_s(core_id)` 为每个 checker
写入 12 条 mapper 记录，并把其目标位设置为 `1 << (core_id - 1)`。因此四个
checker 在软件层是一一对应的独立目的位。

== 修改 checker 数时的联动项

不能只改 `NUM_CHECKERS`。至少要同步验证：

- Chipyard 配置实际实例化的 hart 数与 BOOM/Rocket 排列；
- `NUM_CHECKERS`、`TIMER_HARTS` 和 `timer_flags[]` 大小；
- `secondary.c` 中 `mhartid` 的 case 范围；
- `r_ini()` 中 SE 数量与 mapper 循环；
- checker mask，四个 checker 是 `0xF`；
- GHT 完成状态的编码与 `0x1FFFF` 阈值；
- 仿真配置名和生成的硬件是否支持同一套 RoCC ABI。

= RoCC 接口

== 宏的参数约定

`rocc.h` 通过 `.word` 直接发射 custom 指令。高层宏含义如下：

#table(
  columns: (2.05fr, 1.25fr, 3.15fr),
  table.header([*宏*], [*操作数*], [*用途*]),
  [`ROCC_INSTRUCTION(X,f)`], [无输入、无输出], [只发送 funct 命令。],
  [`ROCC_INSTRUCTION_S(X,s,f)`], [1 输入], [输入值绑定到 x11/rs1。],
  [`ROCC_INSTRUCTION_SS(X,s1,s2,f)`], [2 输入], [输入值绑定到 x11/rs1 和 x12/rs2。],
  [`ROCC_INSTRUCTION_D(X,d,f)`], [1 输出], [返回值绑定到 x10/rd。],
  [`ROCC_INSTRUCTION_DS(X,d,s,f)`], [1 输入、1 输出], [按索引读取状态或计数。],
  [`ROCC_INSTRUCTION_DSS(...)`], [2 输入、1 输出], [GHT 配置/状态类读写。],
  [`R_INSTRUCTION_JLR(3,f)`], [特殊跳转], [使用 custom3 触发 checker 的恢复跳转路径。],
)

本 workload 的常规命令使用 `X=1`，即 custom1 opcode `0b0101011`。修改宏、
固定寄存器或 `xd/xs1/xs2` 位会直接改变硬件握手和机器码，必须同时核对 RTL。

== Workload 使用的主要 funct

#table(
  columns: (0.8fr, 1.7fr, 3.95fr),
  table.header([*Funct*], [*调用位置*], [*软件侧用途*]),
  [`0x01`], [`ghe_asR`], [把当前 GHE 设为 receiver/checker。],
  [`0x06`], [GHT helpers], [配置过滤/SE/mapper，或读取大核完成聚合状态。],
  [`0x07`], [`ghe_checkght_status`], [读取 checker 观察到的 GHT 状态。],
  [`0x16`], [SATP/priv helpers], [rs1=1 设置监控目标，rs1=2 清除。],
  [`0x1B/0x1C`], [初始化], [读取 checker 初始化聚合状态 / 设置激活 checker 数。],
  [`0x30/31/32`], [`test.c`], [复位 / 开始 / 结束 GHT 监控状态。],
  [`0x40/0x43`], [checker 生命周期], [go / release。],
  [`0x50/0x51`], [初始化状态], [清除 / 发布 initialized；当前 checker 使用 `0x51`。],
  [`0x55`], [CSR perf], [按 rs1 索引读取 CSR 性能计数。],
  [`0x60/0x61`], [恢复路径], [安装/复制快照 / 读取 RSU 状态。],
  [`0x63..0x66`], [ELU/PC], [ELU 出队、记录 PC、选择 ELU、读取 ELU 状态的接口约定。],
  [`0x70`], [checker control], [rs1=1 打开、rs1=2 关闭 workload 检查窗口。],
  [`0x72/0x73/0x75`], [上下文], [选择 checker 末端 / 大核来源，以及触发记录。],
  [`0x76/0x79`], [checker perf], [软件当前用于 reset/start/stop 和 interval。兼容性见下文。],
  [`0x7D/0x7E`], [checker mask], [写入 / 回读启用 mask。],
)

不要仅凭十六进制数猜测硬件行为。调试 ABI 时应同时查看 `ghe.h`、`ght.h`、
`rocc.h` 和本次仿真实际生成所对应的 `GHE.scala`。

== 当前 RTL ABI 复核提示

#box(
  width: 100%,
  inset: 9pt,
  stroke: 0.8pt + rgb("b26a00"),
  fill: rgb("fff8ea"),
  radius: 3pt,
)[
  *重要：* 当前软件用 funct `0x65/0x66` 选择和读取 ELU，但当前工作区的
  `GHE.scala` 未见这两个 funct 的直接 decode，`elu_sel` 也未见对应更新逻辑。
  此外，`ghe.h` 把 funct `0x79` 当作性能采样间隔设置命令，并把
  funct `0x76` 的 bit 5/6 当作 start/stop。当前工作区的 `GHE.scala` 未见
  `0x79` decode，且 `debug_perf_ctrl` 只有 5 位，只接收 rs1 的 bits 4:0。
  因而 reset bit 0 可生效，但 bit 5/6 会被截断。新人不应仅凭接口函数名判断
  ELU 查询或分段性能窗口已由硬件实现；运行前必须与目标 RTL 分支重新核对。
]

`test_config.h` 中的 `MEEK_ENABLE_BIG_CORE_PERF=0` 和
`MEEK_ENABLE_CHECKER_SEGMENT_PERF=1` 当前主要用于约束构建配置和打印信息，
checker 中的性能命令仍是无条件发出的。日志里的 `checker_limit=2000` 是固定
字符串，而默认 `FPGA_PERF_INTERVAL_CYCLES` 是 5000，两者也不是同一个可靠的
硬件配置读回值。

= 被测指令流

== 高层结构

监控窗口内首先执行 `float` 和 `double` 运算，然后读多个 CSR。hart 0 的
`Hart_id` 为 0，因此 `(j * Hart_id) == 0` 条件成立，程序会到达外层循环条件；
但具体循环次数仍受下文未初始化变量影响，必须以当前 `test.dump` 为准。

#table(
  columns: (1.35fr, 2.45fr, 2.8fr),
  table.header([*类别*], [*主要指令/行为*], [*校验目的*]),
  [浮点], [`float/double` 加减乘除], [覆盖 F/D 执行路径和浮点状态。],
  [CSR], [`cycle`、`instret`、`mhartid`], [产生普通 CSR 读并覆盖监控上下文。],
  [异常], [`ecall`], [进入机器态 trap，验证不可直接重放的控制事件。],
  [存储], [`sd`，每轮多个偏移], [产生连续 store 事件和地址/数据组合。],
  [加载], [`ld`，每轮多个偏移], [产生 load 事件和相关整数计算。],
  [LR/SC], [`lr.w`、`sc.w`], [覆盖 reservation 与条件写。],
  [Atomic], [`amoadd.w.aq`], [覆盖 AMO 和 acquire 语义。],
  [整数运算], [`mulw`、`divw`、`divu`], [增加长延迟和数据相关。],
  [浮点 CSR], [`frflags`、`fsflags`、`csrr* fflags/frm`], [覆盖浮点异常标志和舍入模式 CSR。],
)

== Workload 内存图

#table(
  columns: (2.25fr, 1.7fr, 2.65fr),
  table.header([*项目*], [*值*], [*说明*]),
  [基地址], [`0x81000000`], [三个汇编循环都从这里开始。],
  [循环比较上界], [`0x810008FF`], [每次尾部用 `blt t0,a5` 判断下一轮；它不是全部访存的最高地址。],
  [迭代步长], [`0x10`], [每次地址增加 16 字节。],
  [store 数据], [`0x55552000` / `0x55553000`], [交替写入基址及多个固定偏移。],
  [atomic 寄存器初值], [`t1=0x81000100`，`t2=1`], [`t1` 是 rd、随后被内存旧值覆盖；`t2` 是逐轮增加的加数。],
  [实际最高访问字节], [`0x81000937`], [最后一个 `t0=0x810008F0`，`ld/sd 64(t0)` 会访问 8 字节。],
)

store 循环每次除写 `0(t0)` 外，还写 `16(t0)`、`32(t0)` 和 `64(t0)`；由于
下一轮 `t0` 只增加 16 字节，相邻轮次会覆盖部分地址。这是当前刺激模式的一部分，
不是简单的线性数组初始化。

因此目标平台至少要保证 `0x81000000..0x81000937` 是可访问 RAM，并且不得覆盖
ELF、栈、堆或 MMIO。若更换内存映射，只改基地址还不够，需要检查循环比较
上界、所有固定偏移、访问宽度和原子访问对齐。

== 必须保留的未初始化循环变量

#box(
  width: 100%,
  inset: 9pt,
  stroke: 0.9pt + rgb("a33a32"),
  fill: rgb("fff2f0"),
  radius: 3pt,
)[
  *二进制兼容性警告：* `test.c` 当前写有
  `for (int i; i < 3; i++)`，循环变量按 C 语言规则未初始化，属于未定义行为。
  该写法在一般软件中应修复，但本项目此前发现把它改为 `int i = 0` 会改变
  checker 可见的机器指令流。若要求保持现有 `test.riscv` 功能和校验行为，
  不得未经完整二进制与仿真回归就修改它。
]

因为这是未定义行为，即使源码不变，不同 GCC 版本、优化器版本或编译选项也
可能生成不同结果。因此可复现性必须绑定工具链和 `-O2` 选项，不能只依赖源码
文本相同。

== 窗口末尾的 26 条 NOP

停止 funct `0x70` 后，源码显式写了 26 条独立 `nop`，再发送 funct `0x32`。
这些 NOP 用于保持当前机器指令时序和排空距离。不要把它们合并、改成 C 循环或
删除；编译器对 C 循环的优化结果不等价于 26 条确定的汇编 NOP。

= 中断与异常

== CLINT 地址

所有常量集中在 `test_config.h`：

#table(
  columns: (2.2fr, 1.65fr, 2.75fr),
  table.header([*项目*], [*值*], [*地址计算*]),
  [CLINT base], [`0x02000000`], [平台 CLINT 基地址。],
  [MSIP], [每 hart 32 位], [`base + hart_id * 4`。],
  [MTIMECMP], [每 hart 64 位], [`base + 0x4000 + hart_id * 8`。],
  [MTIME], [全局 64 位], [`base + 0xBFF8`。],
  [timer delta], [`0x20`], [每次比较值设为当前 MTIME 加 32 tick。],
  [timer limit], [`50`], [每个受测 hart 达到 50 次后关闭 MTIE 和全局 MIE。],
)

`get_mtime()` 使用 high-low-high 重读，避免 RV64 平台上通过两个 32 位 MMIO 读
发生低位进位撕裂。`mtimecmp_cfg()` 设置首次比较值；后续 timer trap 每次把
比较值推进到“当前时间 + 0x20”。

== Trap 处理

`handle_trap()` 读取 `mcause`，先区分 interrupt 与 exception：

- 若 `mip.MSIP` 置位，向当前 hart 的 MSIP 写 0 清除软件中断；
- 否则若 `mip.MTIP` 置位，增加对应 `timer_flags[hart_id]`，未到 50 次则重设
  MTIMECMP，到达上限后清除 `mie.MTIE` 和 `mstatus.MIE`；
- 若是 exception cause 11，即机器态 `ecall`，把 `mepc` 增加 4 后返回；
- 其他同步异常没有恢复策略，只落入默认分支。

当前编译不启用 C 扩展，且 `ecall` 本身是 4 字节指令，所以 cause 11 路径固定
执行 `mepc += 4`。如果以后把 handler 扩展到处理可能为 16 位的其他异常指令，
不能继续无条件加 4。

`handle_trap()` 没有在 C 代码中显式写 `mtvec`；它依赖 `htif_nano.specs` 对应的
启动/运行时把 trap 入口接入该符号。更换裸机运行时后必须重新验证这一点。

= 完成条件与输出

== 正常输出的关键标志

一次正常运行通常能看到以下语义性输出，多个 hart 的精确交错顺序不应作为
测试条件：

```text
R: Checker mask set to 0xf
R: Initialisation is completed!
Software interrupt test complete!
[Boom-C0]: Test is now started:
[MEEK_PERF_CFG] ...
CPU execution took <N> cycles
Boom-Perf: CSR execution-inst = <N>
[Boom-C0]: Test is now completed.
```

成功判断至少应同时满足：

- checker mask 回读为 `0xF`；
- BOOM 越过 checker 初始化屏障；
- 日志中没有 `Error detected for ELU`；
- BOOM 越过 `status >= 0x1FFFF` 的完成轮询；
- 出现最终 `Test is now completed`。

程序没有统一的 `PASS` 字符串，也没有对每个等待点设置超时。自动回归应在
仿真外层配置超时，并保存最后一条 UART 输出、PC 和关键 RoCC 状态。

== 计数值如何理解

`CPU execution took` 是从监控窗口刚打开后到所有 checker 完成后的 `rdcycle`
差值，因此它不仅包含 BOOM 混合 workload，还包含窗口关闭和等待 checker 的时间。

`Boom-Perf: CSR execution-inst` 是 `ghe_csr_perf_read(0)` 的结束值减起始值。数组
`csr_read_s/e` 各预留 84 项，但当前只使用下标 0。这个值的具体硬件事件定义
取决于 GHE 的 `csr_counter_in(0)` 接线，不能直接假定等于 C 源码中的某一种
指令数量。

前述性能 ABI 差异意味着 `[MEEK_PERF_CFG]` 只能说明软件编译配置和发送意图，
不能单独证明 checker 分段计数已经按 interval/start/stop 工作。

= 使用 `test.dump` 理解真实指令流

C 源码不是校验窗口内机器指令的最终真值。优化、内联、寄存器分配和汇编块
共同决定 ELF。推荐每次改动后至少做以下检查：

```bash
cd /home/gzh/EC/Software/Test
rg -n '<main>|<__main>|<checker>|<handle_trap>' test.dump
less test.dump
```

当前二进制中的主要符号地址如下；重新构建后地址变化不一定表示错误，但必须
解释变化来源：

#table(
  columns: (1.75fr, 1.55fr, 3.1fr),
  table.header([*符号*], [*当前地址*], [*用途*]),
  [`main`], [`0x80000230`], [BOOM 主流程。],
  [`handle_trap`], [`0x80000668`], [MSIP、MTIP 和 ecall 处理。],
  [`__main`], [`0x800008DC`], [次级 hart 分发入口。],
  [`checker`], [`0x80000E30`], [Rocket 重放/检查流程。],
)

当前产物基线，仅用于确认本文对应的版本：

```text
test.riscv  43568 bytes
SHA-256     720f3d3241a4137510cea1232fa7b4c6cf7d4ffea045e22340ad8f96c067e1cd

test.dump   194069 bytes
SHA-256     f887f79753a86ee62b165ebd64d7e263241f9be5f83723e5f82ecb6511c8f930
```

若项目有意更新 workload，这些 hash 应随手册一起更新；不能把旧 hash 当成所有
未来版本的永久正确值。

= 安全修改流程

== 修改前先判断目标

“保持 C 语义”与“保持 checker 可见机器指令流”是两个不同目标。本项目要求不
改变 `test.riscv` 功能时，应采用更严格的第二种标准。即使输出字符串相同，新增
函数调用、改变初始化、调整内联边界或更换编译器，也可能改变监控窗口内的指令。

== 推荐检查清单

1. 记录修改前 `test.riscv`、`test.dump` 的 hash 和工具链版本；
2. 明确改动是否位于 funct `0x31` 与 `0x32` 的监控区间内；
3. 不改 RoCC 宏固定寄存器、custom opcode 或 funct，除非同步修改 RTL；
4. 不擅自初始化未初始化的循环变量，不删除 26 条 NOP；
5. 保持 `NUM_CHECKERS=4`、mask `0xF`、四个 SE 和 hart 1 至 4 的一致性；
6. 保持 workload 地址合法、原子访问对齐、CLINT 地址匹配平台；
7. 使用相同 GCC、`-O2` 和 `-march=rv64imafd` 重新构建；
8. 比较 `test.dump` 中 `main`、`checker`、`handle_trap` 的指令差异；
9. 运行 `v0Config` 仿真，检查 UART、ELU 错误、完成状态和波形；
10. 只有在二进制差异和硬件行为都被解释后，才接受新的基线。

仅修改注释或文档时无需重建 ELF。调整 `printf` 也可能改变链接布局和函数地址，
因此若项目以整个 ELF hash 为基线，输出文本改动同样不是“零风险”。

= 故障定位

#table(
  columns: (2.2fr, 4.2fr),
  table.header([*现象*], [*优先检查*]),
  [找不到交叉编译器], [是否执行 `source chipyard/env.sh`，`RISCV` 是否正确，gcc 旁是否有 objdump。],
  [仿真提示找不到 binary], [`Test` 大小写、当前目录以及 `BINARY` 路径；优先使用手册中的绝对路径。],
  [出现 illegal instruction], [是否误用普通 Rocket/Spike；当前 CONFIG 是否实例化 custom1/custom3 与 GHT/GHE。],
  [停在初始化之前], [四个 checker 是否到达 `ghe_initailised(1)`，checker mask/数量和跨核初始化聚合。],
  [ELU 查询异常], [先核对目标 RTL 是否 decode `0x65/0x66`，再检查所选 ELU、出队命令 `0x63` 和大/小核结果差异。],
  [停在 checker 恢复], [`ghe_rsur_status()` 位 `0x18`、funct `0x60`、custom3 JLR 的恢复 PC。],
  [停在 workload 的 ecall], [HTIF trap 入口是否连接 `handle_trap`，`mcause` 是否为 11，`mepc` 是否推进。],
  [访问 `0x81000000` 异常], [平台内存映射、地址保留范围、PMP/PMA、原子扩展和总线可达性。],
  [BOOM 完成前永久等待], [四个 checker 的 `0x02` 状态、GHT 聚合值是否能达到 `0x1FFFF`。],
  [性能 interval/start/stop 无效果], [核对当前 RTL 是否 decode `0x79`，以及 `debug_perf_ctrl` 位宽；不要只看软件日志。],
  [UART 输出相互穿插], [所有新增多 hart 输出是否使用 `uart_lock`；checker 的错误打印当前没有加锁。],
)

调试卡死时，最有效的最小信号集合通常是：各 hart PC、`mhartid`、当前 RoCC
funct/rs1/rs2、checker initialized、GHT 聚合状态、GHE checker 状态、ELU 状态、
RSU 状态、`mcause/mepc` 和 CLINT MSIP/MTIP。

= 已知限制

- 外层 `for` 使用未初始化变量，依赖当前工具链结果，不具备标准 C 可移植性；
- 初始化轮询、checker 完成轮询和 GHT 完成轮询均无软件超时；
- 除 cause 11 的 `ecall` 外，其他同步异常没有通用恢复或失败上报；
- workload 使用固定物理地址，不能直接迁移到不同内存图；
- checker 结束后永久循环，不独立报告 PASS；
- ELU 错误打印未使用 UART spin lock，可能与其他输出交错；
- `0x65/0x66` ELU 软件约定与当前工作区 RTL 存在前述差异；
- `0x79` 和 `0x76` 性能控制的软件约定与当前工作区 RTL 存在前述差异；
- 固定完成阈值 `0x1FFFF` 与当前四 checker 硬件协议绑定；
- 测试完成说明该混合刺激能够走通，不代表覆盖全部指令、异常和微架构状态。

= 常量速查

#table(
  columns: (2.7fr, 1.5fr, 2.2fr),
  table.header([*常量/约定*], [*当前值*], [*定义位置*]),
  [Checker 数量], [`4`], [`test_config.h`],
  [Checker mask], [`0xF`], [`checker_config.c`],
  [有 timer 的 hart], [`0..3`], [`test_config.h` / `secondary.c`],
  [Timer 次数上限], [`50`], [`test_config.h`],
  [Timer 增量], [`0x20` MTIME tick], [`test_config.h`],
  [CLINT base], [`0x02000000`], [`test_config.h`],
  [循环基址/比较上界], [`0x81000000 / 0x810008FF`], [`test.c`],
  [实际访问覆盖范围], [`0x81000000..0x81000937`], [`test.c` 中的最大偏移和访问宽度],
  [Workload 步长], [`0x10`], [`test.c`],
  [监控开始/结束], [`0x31 / 0x32`], [`test.c`],
  [Checker 窗口开/关], [`0x70: 1 / 2`], [`test.c`],
  [排空 NOP], [`26`], [`test.c`],
  [全局完成阈值], [`0x1FFFF`], [`test.c`],
  [Checker 完成状态], [`0x02`], [`checker.c`],
  [ISA], [`rv64imafd`], [`compile.sh`],
)

= 总结

掌握这个 workload 的关键不是记住每条 funct，而是建立三层对应关系：

```text
C/内联汇编产生什么机器指令
        <->
GHT/GHE 通过 RoCC 传递什么控制和检查信息
        <->
五个 hart 在哪个状态等待、恢复或完成
```

任何修改都应同时从这三层验证。对于当前基线，最重要的不变量是四个 checker
拓扑、mask `0xF`、固定监控顺序、workload 地址、26 条 NOP、完成阈值，以及
未初始化循环变量所产生的现有机器指令流。
