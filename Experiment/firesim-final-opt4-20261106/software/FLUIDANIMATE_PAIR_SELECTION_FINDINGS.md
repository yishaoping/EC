# Fluidanimate 原软件配对判序诊断

本次证据证明了原软件在 QEMU user 与相同 RISC-V ELF 的完整 Linux 环境中有不同的粒子对漏算；尚未取得 Native FPGA 完整失败输出，不能把这个软件问题宣称为 FPGA 失配的唯一原因。

两次 Native simsmall 样本退出后未通过原 exact-byte 正确性门槛，均保留为无效。原 Linux reference 应用退出0，UART 已有完整传输；恢复出的1,314,152字节输出与guest SHA一致。解析器忽略一条明确格式的printk后，从原日志恢复，无重跑。Linux SHA为 `00108e71973751aae83de393245c73e5ba0fa33e1d44d3402ba988e858d2f6fd`，QEMU user SHA为 `918f0fa738a3bfd533d651cc909cb22285a2011d7a31acc0d9099237206face4`。36,504条记录只有1,440条逐字节相同，记录multiset也不同，不能解释成纯排序差异。官方fluidcmp在显式启用位置、速度、bbox零容差时全部FAIL；未给测试参数的fluidcmp不会检查这些字段。

直接症状（已证明）：两个环境的输出不同。直接条件（已证明）：第一帧密度阶段，同为3,246,500个候选对时，实际选中对数为2,985,791与2,958,381。上游触发（已证明）：GetNeighborCells只枚举当前cell和编号较低的邻居，而ComputeForces再次按粒子存储地址比较过滤。溢出cell由独立分配的pool提供，可能在主cells数组之前或之后；被指针过滤掉的低编号跨cell粒子对不会在反方向再访问。下游放大（已观察）：第一帧密度/力阶段后，后续帧的粒子位置及候选集合进一步分歧；对FPGA实际失败的贡献仍待完整输出证据。

|事件|QEMU user|Linux QEMU|含义|
|---|---:|---:|---|
|第0帧密度候选|3246500|3246500|首次过滤前相同|
|第0帧密度选中|2985791|2958381|首次过滤已分歧|
|第0帧密度被拒跨cell|58108|85518|地址顺序影响跨cell访问|
|第0帧密度漏掉半径内对|3662|6798|这些对不会在反向枚举中弥补|
|五帧密度阶段累计漏对|22812|48574|力阶段相同位置也有对应漏对|

只增加计数的私有诊断二进制分别逐字节复现两个环境各自原输出，证明计数没有改变本次被观察的数值轨迹。原始source和所有正式ELF、输入、ROI、rootfs、FPGA/DUT均未改变。

最小候选只把ComputeForces的密度和力计算中两处谓词改为：

```c++
if (cindexNeigh < cindex || (cindexNeigh == cindex && iparNeigh < ipar))
```

候选保留原邻居枚举、完整5帧计算和ROI，使用稳定逻辑编号确保相同cell内每个无序对一次、不同cell的低编号邻居全部参与。QEMU user/Linux十组阶段计数完全一致、半径内跨cell漏对均0；两环境输出SHA同为 `f496414b8226b30ca2a4f9bf7164361e908ac274246fb7ef53b0aa5b4f1990c4`。与原错误输出不同是预期的语义修复，并非候选失败。但不能隐式将此候选纳入本地原版套件结论；采用前需明确标注软件修复，并在Native/最终C4使用同一ELF、输入、ROI重新验证。候选尚未计入正式结果。

绑定收据与原始日志：

- `software/fluidanimate-linux-reference-recovery.json`：恢复规则、完整日志SHA、输出SHA及旧FAILED状态。
- `software/fluidanimate-pair-selection-diagnostic.json`：原版计数、两环境原输出一致性、官方fluidcmp及全部构建/运行命令。
- `software/fluidanimate-stable-order-candidate.json`：候选补丁、两环境计数和完整输出SHA。
- `software/fluidanimate-stable-order-candidate-20261107T083401Z/candidate-only.patch`：两处谓词最小差异。
- `software/fluidanimate-stable-candidate-preparation.json`：无计数的候选ELF/三种输入/Native与C4软件准备；尚未绑定执行计划。
- `jobs/fluidanimate-{pairs,stable-candidate,stable-prepare}/`：systemd任务PID/start tick/boot_id、单实例锁、状态及持久日志。

冻结硬件commit仍为 `8491167d84b6d9521b151a743673c1516926a1f8`。本诊断没有重新elaborate、GoldenGate或生成bitstream。下一项板级验证是等待当前Native队列自然空闲后的原版输出回收；采用候选的决定不应停止活跃Freqmine或CAD，也不影响其他PARSEC程序继续运行。

2026-11-07追加：用户已明确授权采用修复profile，两组重新验证并采样。正式接入收据为 `software/fluidanimate-stable-formal-adoption.json`，新profile `fluidanimate-stable-formal`；它复用无计数候选ELF，但生成新的正式BUILD.json/rootfs及两组kernel/firmware，不覆盖候选或原软件收据。Native由 `ec-parsec-fluidanimate-stable-native` 在已有全套队列和旧定向修复结束后补跑，C4由原全套队列执行。历史“候选未获决定”表述仅属于此前阶段；本追加授权不将任何QEMU结果或未运行软件改记FPGA通过。原版失败仍保留，新版从test/simsmall门槛开始验证。
