# Baseline / Current 共用 performance benchmark

日期：2026-10-23。结论：`COMMON_BENCHMARK_READY_TO_BUILD`，仅表示共用源码及未来构建流程已准备，**不表示已经编译、可运行 PASS 或已有可信 slowdown**。`RUN_PROVENANCE=UNRESOLVED`。

## 身份与范围

- [DIRECT_EVIDENCE] 历史硬件固定为 `b3d7adddd1e2d2cf428dd933529de878226420cd`，目录 `/data1/gzh/EC/baseline/source`。Current 的根 Git HEAD 为 `9b0f34648d5ef483fcebaef6bdfb2c18f1b5014f`。本轮未修改两者硬件。
- [DIRECT_EVIDENCE] 软件来源是 `/data1/gzh/EC/Software/Test`，与既有 fixed_candidate manifest 关联；旧 ELF SHA256 为 `f5f84a1727e1c5466bd69e5e89c96410f1622297c1e62bf31408f176a2b65610`。它不是新共用 ELF 的哈希。
- [DIRECT_EVIDENCE] 独立共用源码为 `/data1/gzh/EC/baseline/software_common/`。本轮没有生成共用 ELF/loadmem，所有新 PC、二进制 SHA256 和运行结果目前均为 `UNRESOLVED_NOT_BUILT`。
- [STATIC_INFERENCE] 优先采用软件清理策略 A；没有发现必须为这些 legacy 统计读回恢复 Baseline 核心或缓存硬件的理由。不实施 harness 伪造 valid，也不修改硬件性能路径。

## 已实施的软件修改

| 接口/位置 | 处理 | 相对旧 ROI | 为什么不改变计算语义；缓存影响 | 结果影响/证据 |
|---|---|---|---|---|
| `test.c`：`ghe_csr_perf_read(0)` 两次，旧 `csr_read_s/e` | 删除 funct55 读和统计数组写 | 一次前，一次内 | 只用于旧 boom_inst 报告，不进入 AMO/BFS 的参数、结果或分支；删除一次 ROI 内统计访问，不删算法访问 | architectural result 无依赖；[DIRECT_EVIDENCE] 原 `test.c:54,87` 和 `stat/report.c` 消费路径 |
| `stat/report.c` 原 0x7B valid/drain、128 项读回及详细报告 | 替换成四个 checker ready 等待、ROI 输出 | hart0 stop 之后 | 不再要求 b3 未实现的 statistics valid=1；报告不能充当缓存协议 ACK | 新 PASS 来自实际 result、AMO、ROI 合法性；不再伪造统计验证成功；[DIRECT_EVIDENCE] |
| `core/secondary.c:24-26` 原 128 次 0x7B + snapshot stores | 删除观察者 snapshot，保留 fence、每 hart ready store、idle | 与 hart0 ROI **可能重叠** | 统计数据唯一消费者是被替换的报告；不参与计算或 checker 协议。会减少观察者普通内存写入和 RoCC 访问；不能宣称全机 traffic 零变化 | 保留工作数据的访存与数据布局；此变化是共同 measurement profile 清理，两版均用同一新 ELF；[STATIC_INFERENCE] |
| `core/checker.c` 的 0x79 interval、0x76 高位 START/STOP | 移除 | 原初始化/尾部可能和 hart0 ROI 重叠 | 0x79 在所查 b3/Current GHE 中无有效 interval 实现；START/STOP 高位只配置额外观察窗口，不是 0x70 的 checking 控制 | 必要 replay/复制/release 顺序不删；[DIRECT_EVIDENCE]/[STATIC_INFERENCE] |
| 共用 `hw/ghe.h`：0x76 低位 reset=1、clear=0 | 保留最小共享初始化，checker 在 initialized=1 之前执行 | main ROI 前 | 两版都有低五位寄存器；默认寄存器=1，不能简单遗留长期 reset。selector 保持 0，不触发调试 FIFO 的 15→14 读选择 | 不改变 barrier、功能 bitmap 或 safe watermark；不能由“debug”命名推断安全，依据见 ABI 表；[STATIC_INFERENCE] |
| hart0 0x76 START/clear，STOP/clear | 保留，共用同样指令，但不依赖统计结果 | START 前、STOP 后 | 避免顺手改变 Current 现有观察器运行条件；b3 截掉 bits5/6；主指标完全不用这些控制位 | 不是新增硬件兼容逻辑；不恢复统计 valid 检查；[DIRECT_EVIDENCE] |
| `test.c`：两个 rdcycle | 用 inline label 标记 `common_roi_start/stop`，加入编译器 memory clobber | 边界 | 原 workload 调用、STOP/26次 NOP C 循环/GHT poll 顺序保留；不插入新硬件 fence、MMIO 或计数补偿 | 最终 PC 由未来 ELF 确认；旧 PC 不硬编码；[DIRECT_EVIDENCE] |
| `test.c`：最终返回值 | `verified && nodes/source/reached/edges && ROI合法` 决定 PASS 与退出码 | 后 | 纠正旧 main 即使报告失败仍 return0 的验收漏洞；不进入测量工作量 | 失败经 tohost code=3 等非零退出，不强制成功；[DIRECT_EVIDENCE] |
| `cfg/config.h`、`hw/ghe.h`、`stat/report.h` | 清理不再使用的统计声明/封装 | 定义 | 不遗留 0x7B、0x79 或 0x55 的可达读回路径 | 未来构建后再次扫描实际机器指令，防止只检查源码；[DIRECT_EVIDENCE] |

## 必须保留的工作与数据

[DIRECT_EVIDENCE] 下列文件与 Current 原件逐字节一致：`Benchmark/gapbs/gapbs_bfs.{c,h}`、`bench/stage1_amo.h`、`hw/interrupt.{c,h}`、`hw/ght.h`、`hw/rocc.h`、`cfg/init.c`、`hw/spin_lock.{c,h}`。

- AMO.W 两 lane、RV64 sign extension、自测写入和 fence 全部保留；未为 b3 删除 AMO 检查。
- BFS512，source=0，degree=16，边 `i -> (i+1..i+16) mod512`，alpha=15/beta=18；图构建、parent/frontier/bitset、原算法/验证/汇总循环不变，无外部输入。
- 一 BOOM hart0，四个 checker harts1..4；timer harts0..3，limit50、CLINT delta0x20 ticks，所有必要 timer/interrupt handler 保留。
- 每 hart timer flag 仍为 aligned64、sizeof64；没有恢复紧密排列。其普通 DRAM 布局不依赖 Current 的新增缓存协议。
- 所有 START/STOP checking、上下文记录/复制、特殊 JLR、GHT status 等待、checker release/unset 以及 HTIF finite exit 仍保留。

## 防止代码清理意外移动数据

[DIRECT_EVIDENCE] 软件副本使用独立 `support/htif.ld`；通过 `-fdata-sections` 和显式输出位置固定原候选的 AMO、timer、BFS 九个 mutable 数组、ready、HTIF、heap/stack 边界。**未修改算法文件来加入 section 属性**。具体地址/大小在 `software_common/layout_contract.json`，本轮全部 18 个契约项与旧 ELF 符号核对通过。

[STATIC_INFERENCE] 固定数据块及 BSS/heap/stack 范围减少布局变化引入的缓存混淆；最终链接还必须通过地址/大小门禁。`uart_lock`、AMO、timer、ready 的原 cacheline 相对关系没有被刻意改写。未使用 fallback 地址或自动放宽 linker 约束；如果未来不满足，构建失败且不生成 workload 描述。

[UNRESOLVED] 禁止编译意味着本轮不能证明未来 ELF 已满足此布局，也不能证明 stack frame、所有库全局量、I-cache 布局或每条动态普通访存与旧 ELF 完全相同。PC 变化被本任务允许。**保留的是算法/输入/工作数据布局契约，而非旧统计干扰下的全机请求轨迹。** 如果“普通内存访问不变”被要求包含已经授权删除的统计 snapshot stores，则两要求存在冲突；本版本不应被宣称满足该更强的轨迹等价要求。

## 构建与启动器改动

[DIRECT_EVIDENCE] `baseline/build_common_benchmark.sh` 调用独立 `prepare_common_build.py`，未来用户手动运行时才编译；本轮只做 Bash/AST 语法和静态审查。它先复制共用源码和既有 libgloss 输入，使用新输出目录与 bwrap 主机只读/单输出目录可写隔离，无硬件构建和软件运行步骤。

未来成功产物包括 `test.riscv`、`test.loadmem_hex`、`test.dump`、`test.symbols`、`test.map`、`build.manifest.json`、`workload.json`。descriptor 在数据布局、ROI 指令、禁用统计读回及 ELF/loadmem 门禁通过后才产生。库/编译器/子工具身份和命令写入 manifest。新产物绝不覆盖 fixed_candidate。

[DIRECT_EVIDENCE] Baseline 的 shell/Python 启动器支持 schema2 workload：绑定 ELF/loadmem SHA256、build manifest、最终 ROI 符号/PC、统一 PASS/failure 规则，运行后分别记录 `ROI_cycles` 与 `emulator_reported_cycle_counts`。旧 schema1 继续显式支持，不把旧候选自动标成共用软件。

[UNRESOLVED] 构建脚本、linker gate、启动器新增路径尚未经历真实编译/运行；本轮不启动它们。`COMMON_BENCHMARK_READY_TO_BUILD` 不等同于 `READY_FOR_BASELINE_SMOKE_SIMULATION`。

## 决策

1. [DIRECT_EVIDENCE] 0x7B、0x55、interval0x79 及旧详细 report 属于遗留观察/验收接口，不是 BFS 或 AMO 所需数据。
2. [STATIC_INFERENCE] 可在新的共同 measurement profile 中移除 0x7B，**不能**以“它们全部位于 hart0 stop 之后”作为理由。checker snapshot 与 ROI 的重叠关系没有实测闭合，旧结果不可拼接比较。
3. [STATIC_INFERENCE] 目前不需要改 Baseline 硬件，也没有足够依据优先采用外围 valid 仿真或恢复硬件统计方案。
4. [STATIC_INFERENCE] 应先手动构建这一个共同软件，审核其布局/反汇编/身份，再安排两版使用完全相同 ELF/loadmem 的功能 smoke。若任一侧计算失败则拒绝 performance comparison，不能去掉 AMO/BFS 检查。
5. [UNRESOLVED] 尚无运行正确性、生成模型关联、共同成对 cycles 或净 slowdown。所有历史运行 provenance 限制维持原状。
