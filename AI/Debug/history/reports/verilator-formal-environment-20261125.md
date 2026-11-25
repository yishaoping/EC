# 正式 Verilator 环境整理（2026-11-25）

正式入口为 `/data1/gzh/EC/chipyard/sims/verilator`。默认模型、加载文件和观测器已就绪，运行无需 `simroot`、`sim_dir`、`BREAK_SIM_PREREQ` 或初始化脚本。用户随后取消本轮完整仿真验收和硬件生成要求；后续整机验收由用户执行。

## 产物与复用

以下路径均相对于正式入口：

| 模型 | 可执行文件 | 构建目录（位于 `generated-src/`） |
|---|---|---|
| v1 fast，4 线程 | `simulator-chipyard-v1Config` | `chipyard.TestHarness.v1Config/chipyard.TestHarness.v1Config/` |
| v1 FST，4 线程 | `simulator-chipyard-v1Config-debug` | `chipyard.TestHarness.v1Config/chipyard.TestHarness.v1Config.debug/` |
| Fault8 fast/debug，4 线程 | `simulator-chipyard-PalimpsestFault8Config`、对应 `-debug` | `chipyard.TestHarness.PalimpsestFault8Config/` 内分别保留 fast/debug 子目录 |
| 12.5 MHz History | `simulator-chipyard-Palimpsest12p5MHzHistoryPressureConfig` | `chipyard.TestHarness.Palimpsest12p5MHzHistoryPressureConfig/` |
| Seq 重基 | `simulator-chipyard-PalimpsestSeqRebaseTestConfig` | `chipyard.TestHarness.PalimpsestSeqRebaseTestConfig/` |

六个主仿真器、RTL、FIRRTL、C++、对象和模型静态库直接复制自 `AI/TMP/ec-test-20261125/probe-publication`。可执行文件、对象和静态库保持原始字节；文本仅修正迁移路径。既修正绝对路径，也修正 `.d` 中与旧目录深度有关的相对路径。核对来源后，统一整理构建时间戳并保持依赖顺序；没有删除或绕过源码依赖。

原临时验收目录完整保留。此前正式目录内被替换的 v1 产物保存在 `AI/TMP/verilator-formal-20261125/before/`，不参与正式构建。

只重新构建了无法原样迁移的 Clang 预编译头、只读压力观测器对象及其链接程序，并执行正常 SBT 源码编译检查。没有重新运行 Chisel elaboration、FIRRTL lowering、Verilator 代码生成或整机 C++ 全量编译。压力观测器位于该配置 fast 模型目录的 `pressure-observer/simulator`。

## 必要修改

- `chipyard/sims/verilator/Makefile`：默认四线程；FST 默认扩展名改为 `.fst`；清空传给子构建的 `CCACHE_BASEDIR`，避免实测出现的 Clang PCH 强制包含路径重写和 `plusArgs` 重定义；增加 `run-binary-pressure-hex`，复用原只读观测器和已有模型库。
- `chipyard/common.mk`：HEX 比较对应 ELF 内容，修复切换到其他目录中同名、较旧 ELF 时误用 HEX 的问题；内容未变时不重写 HEX。fast 日志同时收集 stderr，保留周期、Fault8 和重基记录。
- `PalimpsestHistoryPressureConfig.scala`：原样复制已有 12.5 MHz 配置到正常 Scala 源码目录，使后续普通 SBT 构建能找到该配置。
- `AI/Debug/scripts/fullcore_concurrency/pressure_observer.cc` 和 `.mk`：保存已有观测器源码和原有链接方式，解除其对临时源码的依赖。仅将 C++ include 改为相对正式 Debug 源码的路径。

硬件功能逻辑、S8 注入逻辑、153 行 EC-Test 程序、判据及 benchmark 切换机制均未修改。

## 配套检查与验证边界

最终检查包括四类 CONFIG、六个 fast/debug 构建树的内外层 `make -q`，以及下列五条运行命令的 `make -n`：均识别现有产物，不计划生成或编译硬件。六个模型的预编译头均通过实际 C++ 使用检查。29701 个生成文本文件未发现 `AI/TMP` 路径；活动构建树没有符号链接。此前进行的五类模型 1000 周期文件访问跟踪均未访问 `AI/TMP`。旧编译文件名仍可能出现在二进制诊断字符串中，但不是文件依赖。

EC-Test 的 ELF 与 dump 和已验收版本、`Software/EC-Test/.build/` 中的版本一致，无需重新编译。ELF SHA256 为 `4dbde258ff8d7d567bcf5f579dd70d40dc6291b1c18ceece0fe06a56b35fb7c5`。四个 CONFIG 的默认 `test.loadmem_hex` 和 ELF 内容快照均已准备。实际检查 EC-Test → 同名但更旧的 GAPBS ELF → EC-Test 的切换，HEX 每次均对应选择的 ELF，重复调用不改变 HEX 时间戳。

用户改变验证范围之前，fast 与 Fault8 已完整运行，分别为 345597 和 422873 周期，直接采集的 make 返回值为 0；软件分别报告 97 PASS/0 FAIL、126 PASS/1 FAIL。Fault8 的唯一 FAIL 为 Seq 8，恢复事件与原验收逐项一致，SCP/restore/restart PC 均为 `0x80000964`。额外的退出前硬件 PASS 不并入软件已经读取的 PASS 快照。

此前启动的默认 FST 运行已到达完整 EC-Test PASS 和 345597 周期成功终态，`test.fst` 保存在默认 output 中。强制重基已到达完整 EC-Test PASS 和 677729 周期成功终态，六次 reset 后的新 Seq 1 全部 PASS，事件与原验收一致。这两次早期运行的一次性外层采集命令误用了 zsh 的只读变量 `status`，因此外层采集退出 1；仿真成功终态与日志保留，后续退出码采集已改用 Python。

用户取消完整验收后，停止尚在运行的压力测试和重复 FST 检查。它们分别停在 1122834 和 227673 周期，**不作为完整通过证据**，即使仿真器在 SIGINT 后打印成功或返回 0。12.5 MHz 完整 1234316 周期、64/64、重分配及最终回收的功能结论仍引用原 `probe-publication` 验收证据；本轮模型字节相同。25 MHz 冻结压力的原覆盖差异继续保留，未改硬件或放宽判据。

原始迁移、来源、HEX、依赖和运行记录保存在 [配套检查目录](../../../TMP/verilator-formal-20261125/)。历史功能证据保存在 [原验收目录](../../../TMP/ec-test-20261125/probe-publication/acceptance/)。这些证据目录不参与正式运行或重建。

## 增量构建

Scala/Chisel、源 RTL 和支持源码仍走 Chipyard 原有依赖链；变更对应输入后，正常构建更新需要的阶段。fast/debug 使用独立模型目录，不同 CONFIG 使用独立生成目录、可执行文件和 output。未修改硬件源码来验证依赖，仅检查现有依赖及 `make -W ... -n` 的阶段触发。

软件编译和 benchmark 切换继续使用原 `Software/Test/Makefile` 接口；当前默认 EC-Test 产物已准备，无需额外编译。ELF 内容更新后，运行目标只更新相应 HEX，不引发硬件构建。HEX 旁的 `.elf` 文件是自动维护的内容快照，无需手动复制。

显式改变线程数、trace 模式等构建选项时，仍需按 Chipyard 原有方式清理对应 fast/debug 模型再重建；本轮没有增加构建选项管理框架。默认线程数已固定为四线程，后续普通重建不会回退到一线程。

## 直接使用

全部命令的工作目录相同：

```sh
cd /data1/gzh/EC/chipyard/sims/verilator
```

日常高性能仿真：

```sh
make CONFIG=v1Config timeout_cycles=750000 EXTRA_SIM_FLAGS=+cycle-count \
  run-binary-fast-hex BINARY=../../../Software/Test/test.riscv
```

FST 波形调试，无需指定波形扩展名：

```sh
make CONFIG=v1Config VERBOSE_FLAGS= timeout_cycles=750000 EXTRA_SIM_FLAGS=+cycle-count \
  run-binary-debug-hex BINARY=../../../Software/Test/test.riscv
```

S8 故障注入，保留恢复链必要日志：

```sh
make CONFIG=PalimpsestFault8Config timeout_cycles=750000 \
  'EXTRA_SIM_FLAGS=+cycle-count +verbose' \
  run-binary-fast-hex BINARY=../../../Software/Test/test.riscv
```

History 12.5 MHz 满容量压力及只读观测：

```sh
make CONFIG=Palimpsest12p5MHzHistoryPressureConfig timeout_cycles=2000000 \
  EXTRA_SIM_FLAGS=+cycle-count \
  run-binary-pressure-hex BINARY=../../../Software/Test/test.riscv
```

Seq 强制物理重基：

```sh
make CONFIG=PalimpsestSeqRebaseTestConfig timeout_cycles=1000000 \
  'EXTRA_SIM_FLAGS=+cycle-count +verbose' \
  run-binary-fast-hex BINARY=../../../Software/Test/test.riscv
```

普通输出均在 `output/chipyard.TestHarness.<CONFIG>/`：`test.log`、`test.loadmem_hex`，debug 另有 `test.out` 和 `test.fst`。压力目标每次打印并创建新的 `pressure.XXXXXX/`，其中保存 `test.log`、`history.log`、`effects.log` 和 `run.exit`。压力及重基目标运行成功并不能单独替代原有完整功能判据。
