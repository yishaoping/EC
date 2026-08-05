#set page(
  paper: "a4",
  margin: (top: 1.8cm, bottom: 1.8cm, left: 2cm, right: 2cm),
)
#set text(font: "Noto Serif CJK SC", size: 10.5pt)
#set par(leading: 0.65em)

= hart0 workload 循环次数异常：波形、指令与内联汇编的完整溯源

== 1. 调试范围与结论

本文针对 Chipyard BOOM 大核 + Rocket checker 小核协同测试中，hart0 在 `frflags` 附近长时间重复的问题进行记录。分析使用的主要文件为：

- 波形：`/home/gzh/EC/chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd`。
- 软件源码：`/home/gzh/EC/Software/Test/test.c`。
- 修复前后反汇编：`/home/gzh/EC/Software/Test/test.dump`。
- BOOM 提交和 Guardian Council 信号实现：`chipyard/generators/boom/src/main/scala/exu/core.scala` 及相关硬件模块。

本次结论是：hart0 的异常长循环首先是软件编译约束错误，不是大小核心同步通道首先失效。内联汇编未声明对 `a5`、`t0`、`t1`、`t2`、`t3`、`a0`、`a3` 的破坏，导致编译器把被汇编覆盖的 `a5` 继续当作 C 外层循环上限使用。hart0 因此没有执行完成命令 `funct=0x32`，checker 等待状态 2 是该问题的后果。

最终修复包括两部分：

+ 将未定义的 `for (int i; i < 3; i++)` 改为 `for (int i = 0; i < 3; i++)`。
+ 将三个依赖寄存器传递的内联汇编段合并为一个 asm 块，使用局部数字标签，并声明完整的寄存器和内存 clobber。

修复后重新执行 `Software/Test/compile.sh` 成功生成 `test.riscv` 和 `test.dump`，新的反汇编明确显示外层计数器只比较上限 3。

== 2. 从波形开始的现象确认

=== 2.1 trap 返回后进入 workload

hart0 在波形中先执行机器态定时器 trap 入口，恢复序列为：

```asm
800001e6: 30200073    mret
```

随后回到主程序的 workload 区域。用户观察到 hart0 最终在 `0x80000404: frflags a3` 附近长时间重复。必须注意，`frflags` 不是一个等待同步状态的指令，它位于一个显式的内层循环中；真正控制回跳的是后面的 `blt`。

修复前反汇编的 store 子循环为：

```asm
800003d4: ...         # 设置 a5 = 0x810008ff
800003e4: lr.w  a0,(t0)
800003e8: sc.w  a0,t1,(t0)
800003ec: sd    t1,0(t0)
800003f0: sd    t2,16(t0)
800003f4: sd    t1,32(t0)
800003f8: sd    t2,64(t0)
80000400: addi  t0,t0,16
80000404: frflags a3
80000408: fsflags a3
8000040c: csrrc a3,fflags,a3
80000410: fsrmi a3,3
80000414: csrrsi a3,fflags,31
80000418: csrrci a3,fflags,15
8000041c: blt   t0,a5,800003d4
```

`t0` 从 `0x81000000` 开始，每轮增加 `0x10`，终点为 `0x810008ff`。因此一个 store 子循环的迭代数是：

```text
(0x810008ff - 0x81000000) / 0x10 = 144
```

这解释了一个短时间内重复 `frflags` 的正常部分，但不能解释 hart0 长时间重复整个 workload。

=== 2.2 波形中的可复核计数

波形中应同时观察以下 BOOM 信号：

- `TOP.TestHarness.chiptop.system.tile_prci_domain.tile_reset_domain_boom_tile.core.io_commit_uops_0_debug_pc`
- `TOP.TestHarness.chiptop.system.tile_prci_domain.tile_reset_domain_boom_tile.core.io_commit_valids_0`
- `TOP.TestHarness.chiptop.system.tile_prci_domain.tile_reset_domain_boom_tile.core.io_gh_stall`
- `TOP.TestHarness.chiptop.system.tile_prci_domain.tile_reset_domain_boom_tile.ghe_ght_status_reg`

从 `io_commit_uops_0_debug_pc` 提取 `0x80000404` 可看到：

+ 每一段连续的 store 循环包含 144 个 `0x404` 提交 PC。
+ 整个波形在结束前已经出现 22 个完整的 144 次段，并且末尾仍处于下一段中。
+ 这远大于 C 代码期望的 3 次外层循环，即期望的 `3 * 144 = 432` 次 store 段 `frflags`。

这是“循环确实继续前进并重新进入下一轮”的证据，不是一个 `frflags` 指令在流水线中无提交地保持不动。用户在 GTKWave 中应以 `io_commit_valids_0` 对提交 PC 做门控，排除无效 commit 槽位；BOOM 的提交信号定义见下一节。

波形中还应寻找 `0x800004b0`：

```asm
800004b0: addiw s1,s1,1
800004b4: bne   s1,a5,80000388
```

修复前可反复看到 `0x4b0 -> 0x4b4 -> 0x388 -> 0x3d4` 的路径，而不是落入 `0x4b8` 后继续执行 `funct=0x02`。这说明异常重复发生在 BOOM 完成 GHT 之前。

=== 2.3 定时器造成的间隔不是根因

`test_config.h` 中定时器比较间隔为 `0x20`，`interrupt.c` 中 hart0 在 50 次定时器中断后关闭定时器：

```c
#define TIMER_COMPARE_DELTA UINT64_C(0x20)
#define TIMER_LIMIT 50
```

因此波形中可能出现 `0x404` 提交之间的较大间隔。这些间隔来自 trap 保存寄存器、执行 `handle_trap` 和 `mret` 的开销；定时器只能改变循环的时间分布，不能把一个应执行 3 次的外层循环变成无限重复。定时器停止后仍能观察到连续的 144 次 store 段，进一步排除了“只是中断占用时间过长”的解释。

== 3. C 源码与修复前反汇编的对应

=== 3.1 外层循环本身存在未定义行为

修复前源码为：

```c
if ((j * Hart_id) == 0) {
    for (int i; i < 3; i++) {
        ...
    }
}
```

`i` 没有初始化，读取它进行 `i < 3` 比较属于 C 未定义行为。修复前这份二进制恰好在函数入口附近生成了 `li s1,0`，所以它不是本次“次数过多”的唯一原因；但源码不能依赖这种偶然寄存器分配，必须显式写成 `int i = 0`。

=== 3.2 为什么编译器会把外层上限放在 `a5`

`a5` 不是 C 源码指定的循环上限寄存器，而是 GCC 寄存器分配器的选择。外层条件 `i < 3` 需要长期保存常数 3；在修复前这份二进制中，GCC 选择 `s1` 保存 `i`，选择 `a5` 保存常数 3，并把常数装载放在循环入口：

```asm
80000384: li a5,3
```

GCC 可以使用 `a5`，是因为修复前的 asm 对编译器声称自己不会修改任何通用寄存器。`asm volatile` 中的 `volatile` 只要求编译器保留这段 asm，不能自动删除或合并它；它不表示“汇编可以任意修改所有寄存器”，也不表示编译器会自动保存和恢复 asm 中出现的寄存器。寄存器副作用仍必须通过输出操作数或 clobber 列表显式声明。

从编译器视角看，修复前代码近似于：

```text
s1 = 0
a5 = 3
loop:
    执行一个不会改写任何寄存器的 opaque asm
    s1 = sign_extend_32(s1 + 1)
    if (s1 != a5) goto loop
```

因此编译器认为 `a5` 在整个循环体后仍然等于 3，不会在底部比较前重新装载它。这是合法优化；错误来自内联汇编提供了不真实的寄存器约束。

=== 3.3 哪些指令实际改写了 `a5`

修复前的六个 asm 块都类似下面的形式：

```c
__asm__ volatile(
    ".loop_store1:"
    "li   a5, 0x810008FF;"
    ...
    "blt  t0, a5, .loop_store1;");
```

这些 asm 没有输出操作数，也没有 clobber 列表。实际汇编却直接改写了 `a5`、`t0`、`t1`、`t2`、`t3`、`a0` 和 `a3`，并且这些寄存器的值还跨越了多个独立 asm 块传递。

源码中的 `li a5,0x810008ff` 是伪指令。因为常数不能放入单条 12 位立即数指令，汇编器将它展开为以下四条真实指令：

```asm
lui   a5,0x81
addiw a5,a5,1
slli  a5,a5,12
addi  a5,a5,-1793
```

这四条指令在 BOOM 上正常执行并写回架构寄存器 `x15/a5`，最终得到：

```text
a5 = 0x00000000810008ff
```

它不是编译器临时显示出来的值，也不是波形显示错误，而是处理器实际提交的寄存器写操作。store、load、add 三个内层循环都会执行同样的 `li a5,0x810008ff`；而且 `li` 位于各自的循环标签处，所以每个内层迭代都会再次把 `a5` 写成这个地址上限。

修复前外层循环相关反汇编为：

```asm
80000384: li    a5,3
...
800003d4: ...   # store asm 把 a5 改成 0x810008ff
8000042c: ...   # load asm 再次把 a5 改成 0x810008ff
80000490: ...   # add asm 再次把 a5 改成 0x810008ff
800004b0: addiw s1,s1,1
800004b4: bne   s1,a5,80000388
```

`a5` 的实际变化可以逐阶段写成：

#table(
  columns: (1.1fr, 1.1fr, 1.8fr, 3fr),
  inset: 5pt,
  [*阶段*], [*关键 PC*], [*硬件中的 `a5`*], [*含义*],
  [外层入口], [`0x384`], [`0x3`], [GCC 希望用它作为外层上限],
  [store 内层], [`0x3d4--0x3e0`], [`0x810008ff`], [内联汇编将它改为 store 地址上限],
  [load 内层], [`0x42c--0x438`], [`0x810008ff`], [再次改写为 load 地址上限],
  [add 内层], [`0x490--0x49c`], [`0x810008ff`], [最后一次改写，退出内层循环后仍保持该值],
  [外层比较], [`0x4b4`], [`0x810008ff`], [BNE 实际拿该地址与 `s1` 比较，而不是拿 3 比较],
)

=== 3.4 改写后为什么外层循环无法退出

修复前底部两条指令为：

```asm
800004b0: addiw s1,s1,1
800004b4: bne   s1,a5,80000388
```

`bne s1,a5` 的编码操作数是 `x9/s1` 和 `x15/a5`。第一次外层循环开始时 `s1=0`、`a5=3`；但在到达 `0x4b0` 之前，三个内层 asm 已经把 `a5` 改成 `0x810008ff`。因此第一次底部比较的真实过程是：

```text
0x4b0: s1 = 0 + 1 = 1
0x4b4: 比较 1 != 0x00000000810008ff
        条件成立，跳到 0x388
```

回跳目标 `0x388` 又跳过了 `0x384: li a5,3`。这说明编译器确信循环不变量 3 已经在 `a5` 中，无需重装；但硬件中的 `a5` 实际仍是地址上限。即使重新经过内层循环，三个 `li a5,0x810008ff` 也会在下一次底部比较前再次覆盖它。于是控制流变为：

```text
0x388 -> store 144 次 -> load 144 次 -> add 144 次
      -> 0x4b0 增加 s1
      -> 0x4b4 将 s1 与 0x810008ff 比较
      -> 0x388
```

这正是波形中反复出现完整 144 次 `0x404` 段的原因。

此外，`s1` 使用的是 `addiw`，会把 32 位结果符号扩展到 64 位；而 `a5` 中的地址上限是零扩展的正数 `0x00000000810008ff`。当 `s1` 的低 32 位进入符号位为 1 的范围时，两者的 64 位表示也无法相等。因此该错误路径不是一个可接受的“多跑几轮”，而是可能长期甚至永久无法退出的循环。

更具体地说，当 `s1` 的低 32 位最终为 `0x810008ff` 时，`addiw` 得到的是 `0xffffffff810008ff`，它仍然不等于 `a5` 中的 `0x00000000810008ff`。继续递增后 `s1` 最终按 32 位回绕，比较仍不会成立。对于这份已经生成的指令序列，外层循环不能靠计数自然退出。

== 4. 硬件信号语义与因果链

=== 4.1 为什么 BOOM commit PC 可以证明指令行为

在 `chipyard/generators/boom/src/main/v0/exu/core.scala` 中，BOOM 将 ROB 提交信息导出：

```scala
gh_commit_valids(i) := rob.io.commit.arch_valids(i) &&
                       !exception_mode_test &&
                       !if_mret_or_sret(i) &&
                       !if_ecall(i)

io.commit_valids := gh_commit_valids
io.commit_uops   := rob.io.commit.uops
```

因此：

+ `io_commit_uops_0_debug_pc` 是 ROB 提交槽位 0 的微操作 PC。
+ `io_commit_valids_0` 用于判断该槽位是否是有效架构提交。
+ `0x404`、`0x4b0` 等 PC 的有效重复，代表 BOOM 确实反复提交这些指令，而不是仅仅在取指或预测阶段看到它们。

`io_gh_stall` 和 `gh_buf/io_cdc_not_ready` 可以用来区分硬件停顿：修复前已经观察到 `0x404` 之后继续出现 `0x41c`、`0x3d4` 和下一段循环，说明 BOOM 并非永久停在 GHE/CDC back-pressure 上。

如果需要在 GTKWave 中直接核对 `0x4b4` 的两个分支操作数，可在 `iregister_read` 的四个动态发射槽中寻找匹配槽位 `N`：

```text
core.iregister_read.rrd_uops_N_REG_debug_pc
core.iregister_read.rrd_uops_N_REG_lrs1
core.iregister_read.rrd_uops_N_REG_lrs2
core.iregister_read.rrd_rs1_data_N_REG
core.iregister_read.rrd_rs2_data_N_REG
```

当 `rrd_uops_N_REG_debug_pc = 0x800004b4` 时，逻辑源寄存器应为 `lrs1=9`（`s1`）和 `lrs2=15`（`a5`）。修复前预期可看到 `rrd_rs1_data_N_REG` 为当前小整数循环计数，而 `rrd_rs2_data_N_REG` 为 `0x00000000810008ff`。由于 BOOM 是乱序核，具体 `N` 会动态变化，不能只固定观察一个发射槽。

=== 4.2 为什么 checker 循环是后果

主核只有在 workload 结束后才执行：

```c
ROCC_INSTRUCTION_S(1, 0x02, 0x70);
ROCC_INSTRUCTION(1, 0x32);
```

其中 `0x32` 用于结束 GHT。由于 hart0 被错误外层循环拖住，`0x32` 没有及时提交，GHE 的 `ght_status_reg` 保持 started 状态 1，而不是 finished 状态 2。

checker 的软件逻辑是：

```c
while (ghe_checkght_status() != 0x02) {
    if ((ghe_rsur_status() & 0x18) == 0x08) {
        ROCC_INSTRUCTION(1, 0x60);
        R_INSTRUCTION_JLR(3, 0x00);
    }
}
```

因此 hart1、hart3、hart4 在 `0xfac--0xfbc` 查询循环，hart2 根据 RSU 包到达情况执行特殊 JLR 恢复，都是“主核尚未报告完成”的合理后果。同步通道的表面症状不能反向证明同步通道是第一根因。

完整因果链为：

```text
未初始化 i + 无 clobber 的硬编码内联汇编
  -> a5 的循环上限被内层 asm 覆盖
  -> 0x4b4 比较错误，外层循环不退出
  -> hart0 持续提交 0x3d4--0x41c 和后续 load/add 子循环
  -> funct=0x32 未提交，ghe_ght_status_reg 保持 1
  -> GHM/小核读不到完成状态 2
  -> checker 反复查询并执行必要的 RSU 恢复路径
```

== 5. 修复方案的产生与实现

=== 5.1 修复外层 C 循环

源码改为：

```c
for (int i = 0; i < 3; i++) {
    ...
}
```

这消除了未定义行为，并明确要求编译器保留一个从 0 到 2 的循环计数。

=== 5.2 合并寄存器传递的 asm 块

三个 store/load/add 微基准依赖 `t0/t1/t2` 在块之间传递，不能把它们当作互相独立且无副作用的 asm。修复后使用一个 asm 块：

```c
__asm__ volatile(
    "li t0, 0x81000000\n"
    "...\n"
    "1:\n"
    "...\n"
    "blt t0, a5, 1b\n"
    "...\n"
    "2:\n"
    "...\n"
    "blt t0, a5, 2b\n"
    "...\n"
    "3:\n"
    "...\n"
    "blt t0, a5, 3b\n"
    :
    :
    : "a0", "a3", "a5", "t0", "t1", "t2", "t3", "memory");
```

这样做有三个作用：

1. 局部数字标签避免跨多个 asm 块的全局标签和编译器控制流分析发生歧义。
2. 单个 asm 块内部允许 `t0/t1/t2` 按设计传递，不需要欺骗编译器认为它们在块之间保持不变。
3. clobber 告诉编译器 `a5` 只是 asm 内部临时寄存器，不能把 C 外层循环上限放在 `a5` 中跨越该 asm 使用。

修复后的寄存器分配正好验证了 clobber 生效：GCC 改用 `a4` 保存外层计数器、`a2` 保存常数 3，而 `a5` 只在 asm 内部保存 `0x810008ff`。`a2` 和 `a4` 没有出现在 asm 指令文本中，因此能够安全跨越该 asm 保持值。

=== 5.3 修复后的反汇编检查

重新生成的 `test.dump` 显示：

```asm
8000035c: li    a4,0
80000380: li    a2,3
...
800004a0: addiw a4,a4,1
800004a4: bne   a4,a2,80000384
800004a8: li    a1,2
800004ac: .word 0xe005a02b
```

现在外层循环计数器是 `a4`，上限是独立的 `a2=3`；三个内层循环各自使用 `a5=0x810008ff`，不会污染外层比较。完成第三次循环后，控制流落入 `0x4a8`，随后才能执行 GHT 阶段命令。

== 6. 生成与验证记录

执行命令：

```text
cd /home/gzh/EC/Software/Test
./compile.sh
```

结果：

- 进程退出码为 0。
- 生成 `/home/gzh/EC/Software/Test/test.riscv`，大小 44136 bytes。
- 生成 `/home/gzh/EC/Software/Test/test.dump`，大小 197898 bytes。
- `test.riscv` 被识别为 64 位 RISC-V ELF 可执行文件。
- `git diff --check` 无空白错误。

编译器/链接器仍报告 `LOAD segment with RWX permissions` 警告；该警告来自当前裸机链接布局，不影响本次指令生成成功，也不是循环次数异常的原因。

本次只重新编译和检查 ELF/反汇编，没有重新启动仿真。后续若生成新的波形，建议优先同时观察：

```text
BOOM core.io_commit_valids_0
BOOM core.io_commit_uops_0_debug_pc
BOOM ghe_ght_status_reg
BOOM cmdRouter.io_in_bits_inst_funct
BOOM core.io_gh_stall
GHM  ghm_io_ghm_status_outs_*
Rocket checker core.wb_reg_valid/core.wb_reg_pc
```

修复后的判据是：hart0 的 `0x404` store-loop 只出现 3 个完整段；随后出现 `0x4a8`、GHT 结束命令和 `ghe_ght_status_reg` 向 finished 状态推进。只有在该判据成立后，才有必要继续判断 GHM CDC 或 RSU/JLR 是否存在独立问题。
