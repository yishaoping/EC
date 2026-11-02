#set document(
  title: "BOOM/Rocket LR/SC 双路径追踪与失败计数修复",
  author: "Chipyard GuardianCouncil 工作记录",
)
#set page(
  paper: "a4",
  margin: (x: 18mm, y: 17mm),
  numbering: "1 / 1",
)
#set text(lang: "zh", size: 10.5pt)
#set par(justify: true, leading: 0.72em)
#set heading(numbering: none)
#show heading.where(level: 1): it => block(
  above: 1.2em,
  below: 0.65em,
  stroke: (bottom: 0.7pt + rgb("#455a64")),
  inset: (bottom: 0.25em),
)[#it]
#show heading.where(level: 2): it => block(above: 1em, below: 0.45em)[#it]
#show raw.where(block: true): it => block(
  fill: rgb("#f4f6f7"),
  stroke: 0.5pt + rgb("#c7cdd1"),
  inset: 8pt,
  radius: 3pt,
  width: 100%,
)[#it]

#align(center)[
  #text(size: 19pt, weight: "bold")[BOOM/Rocket LR/SC 双路径追踪与失败计数修复]
  #v(0.5em)
  #text(size: 10.5pt, fill: rgb("#455a64"))[Chipyard 中“BOOM 大核执行、Rocket 小核校验”的协同工作框架]
]

#v(0.8em)

本文记录在现有 store/load 流量统计协议上增加 LR/SC 统计的软硬件修改，并复盘 `hart0 sc_fail` 漏计问题。统计仍以“指令完成”为口径，而不是请求进入缓存的次数；LR 只统计完成，SC 按架构返回值拆成成功和失败。软件可见接口由七项扩展为十项，原有索引 `0..6` 保持不变，新增 `7..9`。

本工作的约束是：不把 LR/SC 混入普通 store/load，不因 nack 或 replay 重复计数，不运行仿真，不执行 Chisel elaboration、Verilog 生成或其他硬件生成。文中波形和 `test.log` 数值来自工作区已有结果；本次文档整理只进行静态检查。

#outline(title: [目录], depth: 3)

= 第一章：LR/SC 语义和统计口径

== 1.1 架构返回值与三类计数

LR（load-reserved）读取数据并建立 reservation。它没有类似 SC 的架构失败返回，因此只统计成功到达完成点的 LR，不再拆分成功与失败。

SC（store-conditional）尝试在 reservation 仍有效时写入。目的寄存器返回：

```text
SC result == 0  -> SC 成功，条件写入成立
SC result != 0  -> SC 失败，条件写入没有成立
```

新增计数器定义为：

#table(
  columns: (0.75fr, 1.65fr, 2.8fr, 2.25fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*索引*], [*名称*], [*BOOM 主核*], [*Rocket checker*]),
  [7], [`lr`], [LSU 收到 `M_XLR` 的有效 DCache/IOMSHR response。], [checker 的 `M_XLR` 在 LSL response 有效后通过 WB。],
  [8], [`sc_success`], [`M_XSC` response 有效且返回数据等于零。], [checker 的 `M_XSC` 完成且 `lsl_resp_data == 0`。],
  [9], [`sc_fail`], [`M_XSC` response 有效且返回数据非零。], [checker 的 `M_XSC` 完成且 `lsl_resp_data != 0`。],
)

必须满足的基本不变量是：

```text
sc_attempt = sc_success + sc_fail
sc_success 与 sc_fail 对同一个完成响应互斥
```

不能对每个 hart 强制要求 `lr == sc_success + sc_fail`。检查窗口可能从 LR/SC 对的中间开始或结束，Rocket checker 也可能把不同片段分配给不同 hart。完整工作负载汇总后可以检查二者是否相等，但它是测试程序属性，不是计数器接口本身的不变量。

== 1.2 与普通 Store/Load 的隔离

LR/SC 虽然使用 LDQ/STQ 和缓存流水线，但不能用 `uses_ldq`、`uses_stq`、`isRead` 或 `isWrite` 直接归类。所有计数在完成点精确匹配 memory command：

```text
M_XRD -> 普通 load
M_XWR -> 普通 store
M_XLR -> LR
M_XSC -> SC
```

因此新增 LR/SC 不改变已有 store/load 总数公式：

```text
BOOM:
  store_total = store_cache + store_uncache
  load_total  = load_cache + load_uncache + load_forward

Rocket checker:
  store_total  = store_cache + store_uncache
  load_total   = load_cache + load_uncache
  load_forward = 0
```

成功 SC 确实会写数据，但不能再计作普通 store；失败 SC 不写 data array，同样不能计作 store。LR 读取了数据，也不能再计作普通 load。

== 1.3 完成、窗口和去重

统计只在有效完成响应上发生。请求入口、MSHR allocate、nack 和 replay 都不是完成点。BOOM 使用随请求传播的 `traffic_check` 表示该指令属于 R_IC 的检查窗口，并使用队列项中的 `traffic_seen` 防止同一指令因 replay 或重复响应被再次计数。

新增规则沿用 store/load 的约束：

1. LR 只有在 DCache response 到达 LSU、窗口有效、LDQ entry 尚未计数时加一。
2. SC 只有在 DCache response 到达 LSU、窗口有效、STQ entry 尚未计数时按返回值加到成功或失败之一。
3. 窗口外的推测响应不能提前消耗应由后续窗口内重执行使用的去重状态。
4. Rocket checker 必须同时满足 checker 模式、WB 有效、LSL response 有效且非 replay。

= 第二章：BOOM 主核的 LR/SC 完成路径

== 2.1 DCache 的 reservation 与 SC 结果

BOOM DCache 使用 `lrsc_count`、`lrsc_addr` 和地址匹配维护当前 reservation。LR 命中或 replay 成功后更新 reservation；SC 检查 reservation 是否仍有效且 block 地址是否匹配：

```text
LR request
  -> DCache s2_lr
  -> 建立 lrsc_addr / lrsc_count
  -> response 返回 LSU
  -> traffic_lr_complete

SC request
  -> DCache s2_sc
  -> reservation 无效或地址不匹配 -> s2_sc_fail
  -> response data 为非零，且不写 data array
  -> LSU 按 response data 产生 traffic_sc_fail_complete

  -> reservation 有效且地址匹配
  -> response data 为零，成功写入
  -> LSU 产生 traffic_sc_success_complete
```

`s2_sc_fail` 是 DCache 内部对 SC 失败的直接判定，但统计没有在 s2 请求阶段加一。最终仍以送达 LSU 的有效 response 为完成点，从而继承 kill、nack 和 replay 的正确语义。

== 2.2 LSU 的精确分类

LR response 使用 LDQ 路径。其核心条件为：

```scala
val count_lr = io.dmem.resp(w).bits.traffic_check &&
  !ldq(ldq_idx).bits.traffic_seen &&
  io.dmem.resp(w).bits.uop.mem_cmd === M_XLR

io.dmem.traffic_lr_complete(w) := count_lr
```

SC response 使用 STQ 路径。返回数据是架构可见的 SC 结果：

```scala
val count_sc = io.dmem.resp(w).bits.traffic_check &&
  !stq(stq_idx).bits.traffic_seen &&
  io.dmem.resp(w).bits.uop.mem_cmd === M_XSC

io.dmem.traffic_sc_success_complete(w) :=
  count_sc && (io.dmem.resp(w).bits.data === 0.U)
io.dmem.traffic_sc_fail_complete(w) :=
  count_sc && (io.dmem.resp(w).bits.data =/= 0.U)
```

完成后相应队列项的 `traffic_seen` 被置位。这样同一 SC 最多进入一个计数器，失败码也不会因为 replay 被重复累计。

== 2.3 DCache 的三个新增计数器

LSU 输出每个 memory lane 的完成脉冲，DCache 用 `PopCount` 累加 LR、SC 成功和 SC 失败：

```scala
val lr_count         = RegInit(0.U(64.W))
val sc_success_count = RegInit(0.U(64.W))
val sc_fail_count    = RegInit(0.U(64.W))

when (completed_lr.reduce(_|_)) {
  lr_count := lr_count + PopCount(completed_lr)
}
when (completed_sc_success.reduce(_|_)) {
  sc_success_count := sc_success_count + PopCount(completed_sc_success)
}
when (completed_sc_fail.reduce(_|_)) {
  sc_fail_count := sc_fail_count + PopCount(completed_sc_fail)
}
```

它们追加到原七项 `traffic_counter` 的末尾。计数器保存在 DCache，而不是在 LSU、tile 和 GHE 多处重复保存；后续模块只传输或读回。

= 第三章：Rocket checker 的重执行统计

== 3.1 WB 与 LSL 的完成判定

Rocket checker 不统计普通 Rocket DCache 的请求入口。它在 checker 指令经过 LSL 并成功通过 WB 时产生完成脉冲：

```scala
val checker_mem_complete =
  (checker_mode.asBool || checker_priv_mode.asBool) &&
  wb_valid && wb_ctrl.mem && lsl_resp_valid && !lsl_resp_replay

val checker_lr_complete =
  checker_mem_complete && wb_ctrl.mem_cmd === M_XLR
val checker_sc_complete =
  checker_mem_complete && wb_ctrl.mem_cmd === M_XSC
```

`wb_valid` 已排除 WB replay、异常和 checker exception。SC 的分类继续使用 LSL 返回数据：

```scala
val checker_sc_success_complete =
  checker_sc_complete && (lsl_resp_data === 0.U)
val checker_sc_fail_complete =
  checker_sc_complete && (lsl_resp_data =/= 0.U)
```

这与 BOOM 侧使用相同的架构口径，而不依赖 Rocket DCache 内部的 `s2_sc_fail` 信号。

== 3.2 R_ICSL 保存和输出

`RocketCore` 把三个完成脉冲连接到 `R_ICSL`：

```text
checker_lr_complete         -> icsl.io.lr_deq
checker_sc_success_complete -> icsl.io.sc_success_deq
checker_sc_fail_complete    -> icsl.io.sc_fail_deq
```

`R_ICSL` 新增三个 64 位寄存器，并受原有 `debug_perf_reset` 控制。输出顺序与 BOOM 完全一致：

```text
[store_total, store_cache, store_uncache,
 load_total,  load_cache,  load_uncache, load_forward,
 lr, sc_success, sc_fail]
```

Rocket 的 `load_forward` 仍固定为零。LR/SC 三项则来自 checker 自己的 LSL/WB 完成路径，不能读取 BOOM DCache 的计数器代替。

= 第四章：十项 GHE 接口和软件读出

== 4.1 硬件传输路径

硬件接口统一扩展为 `Vec(10, UInt(64.W))`。两类 tile 分别提供本地计数，然后沿原 store/load 通路送入 GHE：

```text
BOOM:
  LSU completion pulses
    -> BoomNonBlockingDCacheModule counters
    -> BOOM tile / RoCC command router
    -> GHE traffic_counter_in

Rocket:
  RocketCore checker completion pulses
    -> R_ICSL counters
    -> RocketCore / RocketTile / RoCC command router
    -> GHE traffic_counter_in
```

涉及的公共接口包括 `HellaCache.scala`、`Core.scala` 和 `LazyRoCC.scala`。GHE 保留 `funct=0x7B`，以 `rs1` 作为索引：

```scala
doGetTrafficCounter -> Mux(
  rs1_val < 10.U,
  io.traffic_counter_in(rs1_val),
  0.U)
```

合法索引由 `0..6` 扩展为 `0..9`，越界仍返回零。旧软件读取前七项的含义和顺序不变，因此接口扩展不破坏原 store/load 索引。

== 4.2 软件协议、同步和打印

`Software/Test/ghe.h` 用枚举集中定义十项协议，避免 C 文件中继续散落数字常量：

```c
enum ghe_traffic_counter {
    GHE_TRAFFIC_STORE_TOTAL = 0,
    GHE_TRAFFIC_STORE_CACHE,
    GHE_TRAFFIC_STORE_UNCACHE,
    GHE_TRAFFIC_LOAD_TOTAL,
    GHE_TRAFFIC_LOAD_CACHE,
    GHE_TRAFFIC_LOAD_UNCACHE,
    GHE_TRAFFIC_LOAD_FORWARD,
    GHE_TRAFFIC_LR,
    GHE_TRAFFIC_SC_SUCCESS,
    GHE_TRAFFIC_SC_FAIL,
    GHE_TRAFFIC_COUNTERS
};
```

`ghe_traffic_counter_read()` 仍通过 `ROCC_INSTRUCTION_DS(1, value, counter_index, 0x7B)` 读取当前 hart 所在 tile。`test.c` 和 `secondary.c` 的数组及循环边界改用 `GHE_TRAFFIC_COUNTERS`：hart 1--4 完成 checker 后保存本地十项并置 `hart_traffic_ready`，hart 0 等待所有 ready 后统一打印。LR/SC 单独占一行：

```text
hartN traffic: lr_out=<lr> sc_success=<success> sc_fail=<fail>
```

== 4.3 `compile.sh` 与软件产物

原脚本可能优先选到 `/usr/bin/riscv64-unknown-elf-gcc`，但该编译器缺少 Newlib 头文件，导致 `stdint.h`、`inttypes.h` 或 `stdio.h` 不可用。修复后的脚本先预处理这些头文件，只接受完整工具链；候选顺序为 `$RISCV/bin`、Chipyard `.conda-env/riscv-tools/bin` 和 `PATH`。

链接输入改为从当前仓库解析并逐项检查：

```text
chipyard/toolchains/libgloss/util/htif_nano.specs
chipyard/toolchains/libgloss/util/htif.ld
chipyard/toolchains/libgloss/build/libgloss_htif.a
chipyard/toolchains/riscv-tools/riscv-pk/machine/encoding.h
```

脚本在临时目录中准备 `riscv-pk/encoding.h` 和 `htif.ld` 链接，使用绝对源文件路径编译，再以匹配编译器前缀的 `objdump -d -S` 生成反汇编。成功后把两项结果移动到 `Software/Test`：

```text
test.riscv -> 64-bit RISC-V 静态链接 ELF
test.dump  -> 带源代码交错的反汇编文本
```

当前工作区中的两项产物均已生成；`compile.sh` 也通过 `bash -n` 语法检查。

= 第五章：`hart0 sc_fail` 漏计的诊断与修复

== 5.1 故障现象与排除过程

故障日志曾显示 BOOM 的 LR 和成功 SC 可以统计，但失败 SC 为零：

```text
hart0: lr=864 sc_success=860 sc_fail=0
```

这不是测试中没有失败 SC。故障波形中可以观察到四次满足以下条件的事件：

```text
s2_sc_fail = 1
resp_valid = 1
mem_cmd = M_XSC
traffic_check = 0
count_sc = 0
```

汇总信号也表现为：

```text
s2_sc_fail=4
count_sc=860
sc_success_complete=860
sc_fail_complete=0
```

因此 DCache 已正确判断并返回四次 SC 失败，错误位于“是否属于检查窗口”的统计归属，而不是 reservation 判定、SC 返回码或软件打印。

== 5.2 根因：LR/SC 对跨越检查窗口

原实现让每条请求独立锁存当时的 `traffic_check`。测试中的 LR 在 `fsm_check` 内完成，但与之配对的 SC 稍后才到 DCache；此时 R_IC 已离开该状态，于是 SC response 携带 `traffic_check=0`。

```text
fsm_check 内：
  LR response -> traffic_check=1 -> lr_count + 1

离开 fsm_check 后：
  SC response -> s2_sc_fail=1, result=1
              -> 自己的 traffic_check=0
              -> LSU count_sc=0
              -> sc_fail 未增加
```

LR/SC 是一个由 reservation 关联的操作对。若统计目标是检查窗口内启动的原子序列，则 SC 应继承最近一次完成 LR 的统计归属，不能只采样 SC 自己到达 DCache 时的瞬时 FSM 状态。

== 5.3 修复：保存 LR 的统计归属直到 SC 完成

`dcache.scala` 新增两个寄存器：

```scala
val lr_traffic_check = RegInit(false.B)
val lr_traffic_check_valid = RegInit(false.B)
```

LR response 有效时保存其 `traffic_check`；SC response 有效且存在已保存归属时，覆盖 response 上原本的窗口位；SC 完成后清除 valid：

```scala
io.lsu.resp(w).bits.traffic_check := Mux(
  resp(w).bits.uop.mem_cmd === M_XSC && lr_traffic_check_valid,
  lr_traffic_check,
  resp(w).bits.traffic_check)

when (lr_response_valid) {
  lr_traffic_check := lr_response_traffic_check
  lr_traffic_check_valid := true.B
} .elsewhen (sc_response_valid) {
  lr_traffic_check_valid := false.B
}
```

保存动作放在 LR 的有效 response，而不是请求入口，因此 nack 或尚未完成的 LR 不会建立统计归属。没有可用 LR 记录的 SC 继续使用自己的 `traffic_check`。新的 LR 会覆盖旧记录，这与每个 hart 只有一个有效 reservation、最近 LR 定义当前 reservation 的语义一致。

该修复只改变 LR/SC 统计的窗口归属，不改变 `lrsc_addr`、`lrsc_count`、`s2_sc_fail`、缓存写入条件或架构返回值。

= 第六章：结果、文件和验证边界

== 6.1 当前日志结果

当前工作区的 `chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.log` 显示：

#table(
  columns: (1.15fr, 1.65fr, 1.65fr, 1.65fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*来源*], [*LR*], [*SC 成功*], [*SC 失败*]),
  [BOOM hart 0], [864], [860], [4],
  [Rocket hart 1], [316], [313], [0],
  [Rocket hart 2], [240], [239], [1],
  [Rocket hart 3], [308], [308], [3],
  [Rocket hart 4], [0], [0], [0],
  [Rocket hart 1--4 汇总], [864], [860], [4],
)

BOOM 与四个 checker 汇总后的三项完全一致，并满足：

```text
864 LR = 860 successful SC + 4 failed SC
```

单个 checker 的 LR 与 SC 尝试数不必相等，例如 hart 3 的片段包含跨分配边界的操作；正确比较对象是 BOOM hart 0 与全部已激活 checker 的汇总。

== 6.2 主要修改文件

#table(
  columns: (2.85fr, 4.15fr),
  inset: 5pt,
  stroke: 0.5pt + rgb("#c7cdd1"),
  table.header([*文件*], [*职责*]),
  [`generators/boom/src/main/scala/lsu/lsu.scala`], [在 DCache response 到 LSU 的完成点精确识别 LR、SC 成功和 SC 失败，并使用队列项去重。],
  [`generators/boom/src/main/scala/lsu/dcache.scala`], [保存三个新增计数器；保存 LR 的窗口归属并传给后续 SC；输出十项 `Vec`。],
  [`generators/rocket-chip/src/main/scala/rocket/RocketCore.scala`], [在 checker WB + LSL 完成点识别 LR/SC，并按返回值区分 SC 成败。],
  [`generators/rocket-chip/src/main/scala/r/R_ICSL.scala`], [保存 Rocket 的 LR、SC 成功和 SC 失败计数器，并构造十项输出。],
  [`generators/rocket-chip/src/main/scala/guardiancouncil/GHE.scala`], [`funct=0x7B` 的合法索引扩展到 `0..9`。],
  [`generators/rocket-chip/src/main/scala/rocket/HellaCache.scala`, `tile/Core.scala`, `tile/LazyRoCC.scala`], [把公共 `traffic_counter` 接口统一扩展为十项。],
  [`Software/Test/ghe.h`], [定义十项枚举和统一的 RoCC 读取函数。],
  [`Software/Test/test.c`, `secondary.c`], [按 hart 保存、同步并打印 LR/SC 三项。],
  [`Software/Test/compile.sh`], [选择完整 RISC-V/Newlib 工具链并显式提供 HTIF 链接输入，生成 `test.riscv` 和 `test.dump`。],
)

== 6.3 验证状态与后续检查

已完成的检查包括：软件脚本能够生成 `test.riscv` 和 `test.dump`，`compile.sh` 通过 shell 语法检查，BOOM Scala 修改曾在 Java 11 环境下通过 `boom/compile`。当前已有日志表明 `sc_fail=4`，并与 checker 汇总结果一致。

本次文档整理没有重新运行 Verilator，没有执行硬件 elaboration 或 Verilog 生成。后续修改统计逻辑时应优先检查以下不变量：

```text
1. LR/SC 只在有效 response 或 checker WB 完成点计数。
2. M_XLR/M_XSC 与普通 M_XRD/M_XWR 严格隔离。
3. SC success 和 SC fail 互斥，二者之和等于 SC 尝试数。
4. nack/replay 不计数，同一队列项不会重复计数。
5. SC 对统计窗口的归属跟随最近完成 LR，SC 完成后清除。
6. BOOM hart 0 与所有 checker hart 汇总比较，不要求逐 checker 配对。
7. 软件、GHE、RoCC、tile、core 和计数器模块均保持十项同序。
```
