# 4915b82 第一轮物理失败归因 r4

本报告属于 **EC Performance-Only**，分析的是 `AltSpreadLogic_high` 的失败结果。
第二轮 `SSI_SpreadSLLs` 继续运行，不复用第一轮失败路由。现有控制器只有这两种
实现策略，第二轮失败后保存证据并退出、释放两把 CAD 锁，没有第三种策略。

证据根目录：
`/var/tmp/guozh-ec-rtl-timing-r2-20261115/physical-r3-20261116/implementation/candidates/bjl-result-cdc-10mhz-altspreadlogic_high`

机器可读分组、原始路径和报告 SHA：
`/var/tmp/guozh-ec-physical-root-r4-20261116/physical-root-cause-r4.json`

## 直接阻断与证据限制

第一轮最终 WNS -0.019 ns / TNS -0.094 ns（7 个 setup 端点），WHS -0.171 ns /
THS -14.798 ns（862 个 hold 端点）；903 个冲突网络、288 个重叠节点，未合法布线。
这些结果不能作为 signoff。

`route-status.rpt` 只列前 10 个错误网络；`drc.rpt` 的 RTSTAT-6 只列前 15/903。
日志另列最严重 10 个重叠节点及其竞争网络。不能根据这些有偏样本推算 903 个
网络的比例，不能把 load pin 当作 net，也不能宣称已有全量源/目的拓扑或物理跨度。
现有 DCP 内 EDIF/XDEF 为 Xilinx 编码数据，不能直接按文本 EDIF 解读。

`after-current.py` 已准备单次 pidfd 接续：只有当前控制器实际退出且未成功生成
bitstream，才取得两把 CAD 锁，使用一个只读 Vivado 提取第一/第二轮的完整
`report_route_status -show_all`、冲突 pin/LOC/SLR、全部 setup 负路径、worst100 hold。
它不执行 place/route/phys_opt，不会启动第三种物理实现；成功时跳过，保留现有
认证接续优先权。此之前，完整 903 网络归因和 7 个 setup 端点全路径明确标记为待提取。

## A. 已确认的冲突逻辑锥

最严重的 **10/10 重叠节点全部属于 SVB**。节点落在 INT_X42–52、Y593–618
附近（SLR2），与 `svb/state_24[1]_i_3025` 等合成组合单元相关，竞争网络包括：

- `_T_992` = `{key_0_contentSeq, key_0_generation}`。
- `_T_996` = `{key_2_contentSeq, key_2_generation}`。
- `_T_999` = `{key_3_contentSeq, key_3_generation}`。
- `_T_1038/_T_1044/_T_1047/_T_1056/_T_1059/_T_1062` 等同类 64 位 key 总线。

对应生成 RTL：`full-combined-qualified/host/FireSim-generated.sv:157259` 起。
对应 Chisel：`chipyard/generators/boom/src/main/scala/lsu/speculative-version-buffer.scala`，
原版第 130–142 行构造 `orderLess/orderEqual`，第 315–316、393 行用于 coalescing
和准确 successor 观察。32 个槽位有 496 对 64 位比较及相等关系，虽然对称共享
已减少重复方向，仍形成每个 key 向其余 31 槽广播的连接结构。

**已证明**：失败日志中的 top10 热点与这些比较输入一一对应。
**强支持**：宽比较 clique 与同一 SVB 内密集控制归约造成局部 pin/route 压力。
**未证明**：它占全部 903 冲突的具体比例；必须等待完整 DCP 拓扑提取。

另有 route-status 样本对应 `ghm_dataConsumedSeq_2/ghm_receivedSeq_2`、
`ic_master/packet_seq_counter` 经 `bitmapAllocated_115_i_*` 的网络。
它们可能在综合后跨层级别名化，不能仅按 net 前缀断言真正逻辑拥有者。
前 20 个已观察逻辑锥（含独立 hold 分组）保存于
`/var/tmp/guozh-ec-physical-root-r4-20261116/top20-observed-cones.tsv`。
该表是证据清单，不是全 903 网络的 top20 排名。

MSHR 高扇出是另一个已测网络问题：`installArb/req_way_en[1]` fanout 3212，
`req_addr[6..10]` fanout 2970/2906/2874/2850/2258，均主要位于 SLR2。
驱动类型 MUXF7，Vivado 32-699 明确拒绝对这些驱动强制复制；LUT/FLOP/LATCH
才支持该操作。它与 SVB top10 冲突不同，目前没有证据把它算入全部 903 的某个比例。

## B. 全部 862 个 hold 端点

原始端点 TSV 有 862 行和 862 个唯一 endpoint；完整 worst100 含实际时钟路径。
以下 THS 为打印 slack 求和，和 summary 内部精度存在舍入差异。

| 时钟关系 | 端点 | 打印 THS ns | WHS ns |
|---|---:|---:|---:|
| buildtop → lopt | 104 | -7.779 | -0.171 |
| buildtop → buildtop | 220 | -2.539 | -0.040 |
| XDMA axi → XDMA axi | 286 | -2.400 | -0.040 |
| lopt → lopt | 76 | -0.801 | -0.058 |
| tile → tile | 90 | -0.703 | -0.036 |
| GT TXOUTCLK → XDMA axi | 34 | -0.231 | -0.018 |
| DDR mmcm_clkout0 → 同域 | 22 | -0.200 | -0.037 |

Host/Target 共 490 个端点，domain 表 THS -11.819 ns（约 79.9%）。全部实际数据
起止跨 SLR 为 92 个端点、打印 THS -7.711 ns。其中 FTQ→trace 的 **91 个
SLR1→SLR0 端点贡献 -7.687 ns，约占全局 52%**；其他 770 个端点不能解释为同一
跨 SLR 问题。

最差路径：

`.../frontend/ftq/io_debug_fetch_pc_1_REG_reg[20]/C`
→ `.../PipeChannel_tracerv_trace_insns_1_iaddr/tokens/elts_1_reg[22]/D`

- Launch `buildtop_reference_clock`，capture `lopt`，均 99.960 ns，有共同 MMCM
  祖先，属于物理相关时钟。target 中的 CDC 命名不是添加异步例外的依据。
- Source SLICE_X84Y348（SLR1），destination SLICE_X81Y236（SLR0）。
- Min data 0.865 ns = cell 0.109 + net 0.756；1 级 CARRY8。
- SCD 6.236 ns，DCD 5.495 ns，CPR -1.177 ns；报告 skew +0.436 ns。
- Inter-SLR compensation +0.540 ns；endpoint hold 要求 0.060 ns。
- 报告预算：0.865 - 0.436 - 0.540 - 0.060 ≈ -0.171 ns。
- 此 hold 报告未单列 uncertainty；空字段不解释为零。
- 数据 net fanout 为 3，**不是**高扇出数据广播或宽 MUX 关键路径。

映射：源为 BOOM FTQ debug-fetch-PC 寄存器，目标来自
`midas/core/Channel.scala:30` 实例化 `ShiftQueue(gen,2)`，其 payload FF 位于
`rocket-chip/util/ShiftQueue.scala`。这条路径证明跨 SLR 补偿与相对 clock skew
共同造成 hold，不证明 queue 功能错误，也不支持为了 hold 增加 target cycle。

当前 RTL 候选 A（trace queue bank/local control）应先做结构审查；该最差数据
net fanout=3，因此盲目控制复制或 bank 化没有已证明的收益。优先在合法路由后
hold fixing、局部同 SLR 布局/时钟网络修复，保留 token、握手和可见延迟。

## C. Setup 和 DDR

7 个 setup 端点全部属于 `mmcm_clkout0` 同域；原 summary 只保存一条详细代表：

`design_1_i/ddr4_0/inst/u_ddr4_mem_intfc/u_ddr_cal_top/rst_r1_reg/C`
→ `.../u_ddr_cal/u_ddr_cal_addr_decode/rd_vref_value_reg[34]/R`

实际周期 3.332 ns，数据 3.006 ns（cell 0.080、net 2.926，97.34% 为 route），
零组合逻辑级数；skew -0.219 ns，uncertainty 0.052 ns。源 SLICE_X131Y51，目的
SLICE_X117Y69，均 SLR0；复位别名 net fanout 428。该路径完全位于原 Xilinx DDR
校准模块，不在用户 Chisel 或 Golden Gate 计算逻辑中。

DDR hold summary 为 WHS -0.037 ns / THS -0.203 ns、22 端点；逐 endpoint 打印
合计 -0.200 ns。**不能**为了这类 IP 内复位/数据路径修改 BOOM，也不能改变
3.332 ns 约束。应在用户逻辑互连压力下降后，针对 DDR reset 网络做合法物理
复制/局部布局和 hold 修复。剩余 6 个 setup endpoint 及全部精确数据待独占提取。

## 三个独立候选及准入条件

| 候选 | 已有证据与优化机制 | 功能风险 | 低成本验证 |
|---|---|---|---|
| SVB 捕获边沿关系缓存（优先 C） | 将 496 对常驻宽比较改为 32 路新 key 比较，同一边沿更新派生关系；减少 key clique | 新派生状态失配、复位/槽重用；不能改变 coalescing/successor | 任意 key 的 pair 状态不变式、真实 SVB 全输出逐周期、GG token；后续独占模块综合 |
| MSHR install 仲裁的 one-hot 选择（B） | MUXF7 驱动 3212-load 网络无法物理复制；等价 one-hot 分解尝试改变选择结构 | 无 valid 时 bits 默认值、优先级/ready 变化 | 全组合输入 SAT；保留 invalid 输出默认、全参数接口；检查实际 MUXF/扇出，不凭源码判收益 |
| Trace channel 局部化（A） | 91 个跨 SLR FTQ→tokens 端点贡献 52% THS；具体 min net fanout 3 | 任意额外队列级数可能改变 token 延迟/背压 | 暂不增加寄存器；审查 queue 两槽布局与时钟关系，若 RTL 无明确结构收益则淘汰，转物理同 SLR/hold fixing |

SVB 第一轮只缓存 orderLess/orderEqual，保留 line/writer 相等逻辑；第二轮再评估
是否值得缓存同线/同 writer 的组合关系。两轮分开证据、补丁与验证，不把模块
逻辑减少直接等同于整机布线改善。若新增状态与互连反而恶化，保留失败证据并淘汰。

完整实现仍保持 4915b82 不变；新工作区为
`Opt4-performance-only-physical-root-r4-20261116`，分支
`ec-performance-only-physical-root-r4-20261116`。不启动竞争 CAD，不恢复周期巡检。
任何组合候选只有周期/协议验证、Golden Gate、实际模块和整机 post-opt 证据
齐全后才允许下一次全新物理实现，不会自动执行新的 placement strategy。

## 2026-11-16 独立 RTL 实施及两轮筛选更新

已逐字节确认 `reference-svb.scala` 等于 `4915b82` 中的实际 SVB 源码；MSHR
patch 的输入也等于 `4915b82` 的 `mshrs.scala`。不使用更早、存储结构不同的
SVB 当作本轮面积或功能参考。运行中的 4915b82 source、XDC、DCP 均未修改。

### 已实施：SVB 捕获边沿排序关系缓存

改动文件：

- `chipyard/generators/boom/src/main/scala/lsu/CaptureOrderRelations.scala`。
- `chipyard/generators/boom/src/main/scala/lsu/speculative-version-buffer.scala:130`。

该实现只在原本写入 immutable key 的同一个 target edge 更新两两关系，不增加
target cycle。有效槽位之间的 less/equal 是原 key 的派生状态，释放后仍可保留，
重新分配时更新对应行/列；硬件 reset 清空 valid，因而不需要复位这 992 位。
四路 payload row memory、容量 32、分配/ACK/提交/背压接口不变。

低成本结构统计（Yosys `proc; opt`，不是 FPGA LUT 测量）：

| 指标 | 4915b82 SVB | 候选 |
|---|---:|---:|
| 64 位 unsigned less 比较 | 496 | 32 |
| 64 位 equality 比较 | 496 | 32 |
| FF 状态位，不含 memory | 11,187 | 12,179 |

减少 464 路常驻宽 less 和 464 路宽 equality，新增 992 位关系状态；不能将
93.55% 的比较数量下降解释为同幅度 LUT 或拥塞下降。新 capture/enable 网络
与关系状态的物理局部性仍须实测。

验证证据：

- `/var/tmp/guozh-ec-physical-root-r4-20261116/svb-order-r1/validation-result.json`：
  127 个实际输出端口，directed + 8,192 随机周期对照通过。
- 同目录 `proof-2x64-reset-induction-v3.log`、
  `proof-4x8-reset-induction-v3.log`：任意 key、覆盖写、reset 下的 pair 状态
  归纳证明通过。只初始化 validity 为硬件 reset 后的 0；其余 key/关系位任意。
  这是关系辅助状态的证明，不声称整个 SVB 已完成全状态形式等价。
- `/var/tmp/guozh-ec-physical-root-r4-20261116/svb-order-host-r1/state.json`：
  实际 Golden Gate 转换与 host token 对照通过。2,362 个 target tokens、
  136 次真实 promotion/ACK、801 个 stall 周期，含两轮各 32 条同时保留、
  同线/同 writer 合并、槽位复用。八个 row RAM model（参考/候选各四）均已提取。
- 同目录 `NEGATIVE_CONTROL.log`：故意破坏参考 payload，在 token 146 检出
  `SVB_HOST_MISMATCH`。原始失败 proof/harness 日志保留，未覆盖成成功。

### 已实施：MSHR 六路 install 选择器的独立 patch

`mshr-install-onehot.patch` 仅替换 `mshrs.scala:932` 的 install arbiter，并增加
`OneHotInstallArbiter.scala`。**当前尚未将该 patch 与 SVB 合并到生产源码。**
选择器保留固定优先级、每路 ready、out.valid、全部 payload、chosen，以及
全部 valid 为 0 时仍选择最后一路 bits/chosen 的原始行为。没有寄存器或新周期。

证据支持的第一轮：串联 priority payload MUX 改成 one-hot；发现 payload 的
MUX 链由 5 降至 1，但通用最长算子深度由 5 增至 8，不能判定 setup 改善。
第二轮显式平衡 reduction，MUX 链仍为 1，通用最长算子深度为 9、最短为 3
（参考最短为 1）。通用算子把 bit mask、Boolean 和 mux 视为等权，不等于 LUT
级数或任何实际延迟，因此两个版本均只进入面积/网表筛选，不能凭源码择优。

两个版本均已完成：

- 使用真实 `BoomCacheInstall` 全字段，1/2/6/8 路全输入组合 SAT 通过；包含
  invalid 输出 bits 和 chosen，未用 valid 掩盖差异。
- 实际候选 `mshrs.scala` 编译通过。
- Golden Gate 转换及 2,048 个 host tokens、64 种 valid mask、真实 ready
  stall、所有 payload 位对照通过；参考输入变异的负向控制能检出不一致。

证据分别位于 `mshr-install-r2` / `mshr-install-host-r3` 和
`mshr-install-balanced-r3` / `mshr-install-host-balanced-r4`。
原始未平衡实现保存在 `OneHotInstallArbiter-unbalanced-r1.scala`。

**准入条件**：实际 Vivado 映射后检查 req_way_en/req_addr 的驱动是否仍是
MUXF7、是否变为可复制的 LUT，并检查 LUT/FF/MUXF、最长/最短路径和最终整机
fanout。本方案没有删除 3,212 个 sink；若没有改善最终驱动/物理拓扑，不整合。

### Trace 候选 A 的审查结论

不能把当前最差 FTQ→trace 路径描述为集中式高扇出 MUX：实际数据 fanout=3，
只有一级 CARRY8，trace 队列保持原 `ShiftQueue(gen,2)`。目前没有证据支持
增加流水线、替换时钟或更改 clock-group 关系。该路径属于相关 generated clocks。

优先评估同一局部区域的 token bank/producer 布局及合法 hold fixing，但同 SLR
会同时减少 data minimum delay，**不能**直接宣称去掉 crossing 就修好 hold。
每次必须重新评估 skew、0.540 ns inter-SLR compensation、setup 和 min delay。
第三个 RTL 后备假设是 SVB 同线关系的 capture-edge 缓存（原有 496 对 40 位
line equality）；只有全量冲突归因或前一候选综合确认该关系仍是瓶颈才实施，
避免为凑三个修改而重写 trace queue。

## 确定性的后续执行与边界

第二轮当前仍由原 PID 3958372 控制器和唯一 Vivado 持锁执行。原控制器仅包含
AltSpreadLogic_high、SSI_SpreadSLLs 两轮；成功则走原严格 bitstream/21-only
接续，失败则退出并释放锁，未增加第三种物理策略。

已有单次 pidfd 等待进程 PID 516684 负责在该控制器退出后、失败分支下独占
读取失败 DCP。补充的 `diagnostic.tcl` 只做 report/query：记录全部坏网络
直接 driver/load pin、LOC/SLR、fanout、clock region 和 source register pin，
全部 hold 端点与七个 setup 端点的完整路径。若重新打开失败 DCP 后计数与原
903 不一致，将同时记录两者，绝不将恢复不全的拓扑称为完整 903 归因。

`queued-module-area.py` 在该诊断进程实际退出后才等待两把锁，按顺序进行
有限的模块综合：SVB GG control 成对、完整 target SVB 成对、MSHR 参考和两个
候选。GG control 的四个 payload RAM 在外部；完整 target 含原始异步 row
memory。这两个口径单独报告，不能将其中任一个冒充整机 shell 或完整 host。
它不会执行 placement/routing、周期巡检、外部模型请求或 FPGA 操作。

完整 shell 当前仍只有已实测的 **824,809 LUT / 448,466 FF**；新 RTL 候选尚无
新的完整 shell LUT、物理 WNS/WHS 或合法 bitstream 结果。模块综合和整机
Golden Gate/post-opt、最终布线都尚未完成，不能用本轮局部通过替代这些结论。
