# PALIMPSEST 面积评估修订 r2（2026-11-13）

**0.1923 mm² 的旧计算可以精确复现，但不能作为当前实验的完整面积开销。** 旧值使用 `check` 的 512 KiB L2、Seq16 和未集成的原语预算。当前冻结运行入口绑定的是 1 MiB/16 路 L2，且 packet sequence 为 32 位。在明确保留的缩减标识设计假设下，修订后的原语 Typical 小计为 **0.488425 mm²**；沿用旧缓冲和余量规则为 **0.500837 mm²**。两者均为分析模型，既不是完整 PALIMPSEST−PEEK 差值，也不是 28 nm 综合实测。

本轮保留原 RTL、原报告和原结果；所有新增文件只放在本修订目录。只做静态检查、哈希核验、26 个小规模参数形态的 generic 综合和短单元测试。没有启动 SoC 综合、FPGA、PARSEC，也没有操作其他任务。[provenance-checks.json](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/evidence/provenance-checks.json) 核验原始清单 870 项、生成清单 746 项未变；最终保全检查见 [preservation-check.json](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/evidence/preservation-check.json)。

## 1. 配置来源与比较平台

| 参数 | 旧 `check` 平台 | 本轮主口径：冻结实验几何 | 生效依据 |
|---|---|---|---|
| 核心 | 1 BOOM + 4 Rocket | 1 BOOM + 4 Rocket | [GH_GlobalParams.scala:10](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala:10)；[RocketConfigs.scala:27](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/chipyard/src/main/scala/config/RocketConfigs.scala:27) |
| BOOM 宽度 / ROB / IQ | decode3 / 96 / 72 | decode3 / 42 / 72（16+32+24） | [config-mixins.scala:187](/data1/gzh/EC/check/source/chipyard/generators/boom/src/main/scala/common/config-mixins.scala:187)；[config-mixins.scala:240](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/boom/src/main/scala/common/config-mixins.scala:240) |
| LDQ/STQ | 24/24 | 16/16 | [config-mixins.scala:196](/data1/gzh/EC/check/source/chipyard/generators/boom/src/main/scala/common/config-mixins.scala:196)；[config-mixins.scala:249](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/boom/src/main/scala/common/config-mixins.scala:249) |
| Main L1I | 32 KiB / 8 路 | 32 KiB / 8 路 / 64 sets | [config-mixins.scala:261](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/boom/src/main/scala/common/config-mixins.scala:261) |
| Main L1D | 32 KiB / 8 路 / 4 MSHR | 32 KiB / 2 路 / 256 sets / 6 MSHR | [config-mixins.scala:204](/data1/gzh/EC/check/source/chipyard/generators/boom/src/main/scala/common/config-mixins.scala:204)；[config-mixins.scala:258](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/boom/src/main/scala/common/config-mixins.scala:258) |
| Checker L1I / L1D | I32 KiB/8 路；D4 KiB/2 路 | I、D 均 4 KiB/2 路/32 sets | [Configs.scala:249](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/subsystem/Configs.scala:249)；[Configs.scala:249](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/rocket-chip/src/main/scala/subsystem/Configs.scala:249)、[Configs.scala:258](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/rocket-chip/src/main/scala/subsystem/Configs.scala:258) |
| L2 | **512 KiB / 8 路 / 1024 sets** | **1 MiB / 16 路 / 1024 sets** | [chipyard.TestHarness.v1Config.dts:186](/data1/gzh/EC/check/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/chipyard.TestHarness.v1Config.dts:186)；[RocketConfigs.scala:20](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/chipyard/src/main/scala/config/RocketConfigs.scala:20) |
| L2 MSHR | 7 | 4 | 两份生成 DTS：旧 :192；[firesim.firesim.FireSim.dts:199](/data1/gzh/EC/firesim/final-opt4-20261106/builds/C4-elaborate-20261106T100250.032318Z/firesim.firesim.FireSim.dts:199) |
| Cache line | 64 B | 64 B | 同一冻结 DTS :18、:190 |
| 频率 | target 200/100 MHz | target 200/100 MHz，非 STA 结果 | [RocketConfigs.scala:10](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/chipyard/src/main/scala/config/RocketConfigs.scala:10)；运行绑定 :115 |
| 内存 | 256 MiB 地址空间 | 16 GiB 地址空间，guest 限 2 GiB | 运行绑定 :102、:117；冻结 DTS :169 |
| 内存时序模型 | 不作跨平台外推 | FASED 读写 latency30、并发4/4；没有 DDR3-1066 实证 | [binding.json:7](/data1/gzh/EC/Experiment/parsec8-simmedium-ec-r2-20261112/runs/blackscholes/binding.json:7) |
| 保护实现 | PEEK 风格旧实现，segment ID 有 tie-off | 已带 EC 的 SW/SVB/receipt，不是干净 PEEK | [R_IC.scala:117](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala:117)；[dcache.scala:631](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/boom/src/main/scala/lsu/dcache.scala:631)、[dcache.scala:1745](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/boom/src/main/scala/lsu/dcache.scala:1745) |

冻结生成参数见 [parameters.json:653](/data1/gzh/EC/firesim/final-opt4-20261106/builds/C4-parameters-20261106T100204.040607Z/parameters.json:653)，DTS 确认 L2 1,048,576 B；运行 [binding.json:3](/data1/gzh/EC/Experiment/parsec8-simmedium-ec-r2-20261112/runs/blackscholes/binding.json:3) 选用的二进制实算 SHA256 与 :197 的 `cc2993bd…b2867` 一致。它证明选定硬件入口，不证明本次 PARSEC 样本有效，更不证明面积。冻结源码与生成物的对应仍以冻结构建记录为准；本轮未重做 elaboration。

当前 `DAC_2027_EC.pdf` 的 Table I 也已写成 ROB42、IQ72、L2 1 MiB/16 路（[DAC_2027_EC.txt:415](/data1/gzh/EC/check/area_eval/evidence/DAC_2027_EC.txt:415)）。本报告没有把文档当作参数生效证据。`outerLatencyCycles=12`/`memCycles=12` 是控制器参数，不能在未测量命中流水线前等同“L2 hit latency12”；3.2/1.6 GHz 也没有本轮物理时序证据。

## 2. L1D/L2 位数与标识语义

旧原型字段为 `Seq16 + Epoch4 + CurGen8 + Cur1 + preserved1 = 30 bit/line`，不是论文规定的位宽。Main L1D 共有 `32768/64=512` 行；旧 L2 `524288/64=8192` 行，故 `512×30 + 8192×30 = 261,120 bit`。此数**只对应旧 512 KiB 几何下的设计假设**，不是冻结实验已经实现的 PAL 元数据。

| 几何 / 字段假设 | 每行 bit | L1D bit | L2 bit | 合计 bit |
|---|---:|---:|---:|---:|
| 旧 512 KiB / Seq16 | 30 | 15,360 | 245,760 | 261,120 |
| 冻结 1 MiB / 仍假设 Seq16 | 30 | 15,360 | 491,520 | 506,880 |
| 冻结 1 MiB / Seq32，其他假设不变 | 46 | 23,552 | 753,664 | 777,216 |

[GH_GlobalParams.scala:20](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala:20) 的实际包号宽度是 32。若选 16，必须另行实现并证明 32→16 窗口映射、回绕和旧响应隔离；本轮没有这个机制。46 位场景只保留完整 packet sequence，**没有保留冻结接口的完整 image identity**，因此只能称“缩减标识设计预算”。

冻结 `CacheImageKey` 实际为 `valid1 + writer16 + generation32 + contentSeq32 = 81` 位（[CacheImage.scala:12](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/rocket-chip/src/main/scala/tilelink/CacheImage.scala:12)）。其 generation 是内容/写入身份，`slotEpoch16` 是驻留槽身份，session epoch 是会话身份；都不能直接替代论文的恢复 Epoch/Current generation。若暂时保留整个 81 位 key，再独立添加恢复 Epoch4、CurGen8 和两个标志，会形成 **95 bit/line、合计 1,605,120 bit** 的另一种设计敏感性；尚未综合、也不代表应该全部新增。

冻结 L2 源码的普通 directory 之外已经声明 `dcache1 + packetSeq32 + packetTracked1 + image81 + outerPreserved1 = 116 bit/line`，16,384 行对应 **1,900,544 个声明位**；其中 image+receipt 的 82 位子集为 1,343,488 bit（[Directory.scala:28](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Directory.scala:28)）。这些字段包含统计用途，未做生产版本裁剪或映射优化，不能当成实测面积；但足以说明 46 位预算不是现有 EC 全部逻辑的清单。116 位总数和 82 位子集**不得相加**。详见 [frozen_identity_inventory.csv](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/results/frozen_identity_inventory.csv)。

生成物进一步确认：[FireSim-generated.sv:117473](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-frozen-full-metasim-r1-20261111/host/FireSim-generated.sv:117473) 的 L2 directory 是 **16×1024×143=2,342,912 bit**（含普通tag/coherence及上述EC字段）；不是旧目录 `1024×168`。该生成文件的实算hash与冻结plan记录相同，结构统计见 [generated-identity-audit.json](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/evidence/generated-identity-audit.json)。这里的2,342,912和1,900,544是整体与子集，也不能相加；更不能再把777,216位设计sidecar无条件叠加后称为净增量。

保持原 data arrays 不复制整套 Cache：版本占用已有 ways，会影响有效容量和冲突率；若为保持有效容量而扩容 Data/Tag，则必须在三种配置中重新定义实验，不可把扩容藏在元数据预算中。L1I 和 checker cache 没有在本模型额外加入历史版本位；这依赖单主核、其他写入为可信 BASE 的接口契约。多主核扩展必须重新计 owner、SW 和端口。

## 3. 上下文、EVT、LSL 与重复计费

**上下文。** 原型 `8 slots ×80 words×64 bit =40,960 RAM bit`。80 来自 `32 integer +32 FP +13 shadow CSR +PC +FCSR +priv/mode`；原 PEEK 捕获寄存器见 [R_RSU.scala:60](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/r/R_RSU.scala:60)，13 项 CSR 的确切列表见 [Instructions.scala:1582](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/rocket/Instructions.scala:1582)。这只是按现有接口打包：x0、PC40/FCSR8 对齐有冗余；未证明覆盖 satp、完整陷阱状态、所有可恢复 CSR、计数器/中断/设备语义，不能称完整 ISA checkpoint。8 不是由 4 checkers 自动推出，论文 §IV 没有给出 8 的证明。

必须建立 `retained = 恢复锚点 + 已分配未安全退休的所有段起点 + capture/恢复并发预留` 的生命周期不变量，并对 admission、PASS holes、rollback 和 capture 施加上限。没有上限就不能确定 8 槽是否够用。PEEK 既有主核 snapshot、checker 的 CPS/ECP/GMode 数组各计一次（[R_RSUSL.scala:81](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/r/R_RSUSL.scala:81)）；它们有现有消费者，不能在未证明端口和寿命可共享前直接当成 8 个空闲保留槽。新增预算保守保留整池，但未来复用后应按净变化扣除，并补齐捕获/恢复 adapter。

**EVT。** Seq16、Epoch4、16 entries 的寄存器数量为 `16×(2×16+1)+4=532`；Seq32 为 `16×(2×32+1)+4=1044`。原报告的 8 query lanes 无法同时评价一个 16 路 set，本轮改为 16；它仅支持每次一个 16-way 查询，L1/L2/visibility 之间仍需串行仲裁或增加端口/副本。32 位场景 EVT generic 为 70,647 GE，不是 SRAM 按 bit 计价；深度16和 Epoch4仍是设计选择。[palimpsest.sv:29](/data1/gzh/EC/check/area_eval/rtl/palimpsest.sv:29) 没有 epoch GC/rebase，15 次 rollback 后 fail-closed；CurGen8 到255后也需要受控排空/重建。

**LSL。** 原 `R_LSL` 有 `2×255×130=66,300 bit/checker` payload，约 8.09 KiB；64-bit 地址+64-bit数据占 8,160 B，另有标志和 CSR/RoCC queues。冻结实例仍传255（[RocketCore.scala:838](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala:838)），不能称物理实现只有4 KiB。该存储在 PEEK 与 PAL 共同保护基线中保留，**未在增量重复加入**。原 dequeue 已在 checker 读取时破坏性弹出（[R_LSL.scala:119](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/r/R_LSL.scala:119)）；必须说明新增 reclaim 到底释放什么尚存资源，不能把 ParaMedic 的恢复日志保留策略假定为 PEEK 的实现。

新增 `4×8` release 描述符仅是原型预算，和8个全局 context、16-entry SW window没有统一 admission 证明；实际 block/页分配器、holes reuse、rollback cancellation 均未实现。若无需新增此描述符表，应去掉对应 **0.0155134 mm² Typical**，而不是再增加一份 LSL data。

**Bitmap/SW。** 旧 check 的 `core_bitmap/cp_bitmap` 是调度编码，不是验证前缀（[R_IC.scala:385](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala:385)），所以旧模型没有发现可直接抵扣的 SW。冻结源码已有256-entry `DirtyWritebackBitmap` 与32-bit SW（[dcache.scala:1738](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/boom/src/main/scala/lsu/dcache.scala:1738)）；若复用它，禁止再叠加原型的16-entry SW。原型 SW 的 Typical 0.0008176 mm²仅是可去重原语，不等于既有256-entry模块的面积，也不证明恢复跨 epoch 接口已满足。

**其他去重。** 原 WB line buffer、L2 BankedStore/dir 和 SRAM 宏都在共同基线计一次；跨层保存优先锁住源 way 并复用 WB reader。旧额外2×64B buffer是未实例化假设，本轮原语小计删除。冻结32-entry SVB 和较宽 image/receipt 若保留，必须按真实映射计入 PAL；若被重构替换，只计 `new−old`，不得把整个冻结 EC 当 PEEK 后再整套叠加。源码 [speculative-version-buffer.scala:15](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/boom/src/main/scala/lsu/speculative-version-buffer.scala:15)、:107 声明的数据为 `32×64B=16,384 bit`（未含 key/状态/ECC）；这既不能遗漏，也不能在新复制 buffer 中重复计费。

生成 RTL 也可看到 SVB 的81位key接口、4×128-bit行输入（[FireSim-generated.sv:195290](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-frozen-full-metasim-r1-20261111/host/FireSim-generated.sv:195290)）以及32组数据寄存器。这说明现有SVB并非本轮原语模型的SRAM黑盒；若保留其当前Reg实现，需要真实cell映射或明确改为macro，不能直接按SRAM单价增加16,384位后就称完成核算。逐资源归属另见 [accounting_ledger.csv](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/results/accounting_ledger.csv)。

## 4. 模块面积明细与 Low / Typical / High

下表为 **1 MiB/16 路 L2、2 路 L1D、Seq32、Epoch4、CurGen8、context8、reclaim8/checker、EVT16×16-query** 的条件预算；单元未构成系统实例。所有面积单位 mm²，列名代表物理敏感性假设。GE 按 DFF6、MUX3、XOR2、AND/OR1、INV0.5 等权重折算；DFF 已在 GE 中，**没有再按 SRAM bit 重复收费**。可复算数据：[module_area.csv](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/results/module_area.csv)，逐形态资源与日志：[summary.json](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/results/synthesis/seq32/summary.json)。

| 模块组（建议实例数） | RAM bit | DFF bit | GE（含 DFF、不含 RAM） | Low | Typical | High |
|---|---:|---:|---:|---:|---:|---:|
| L1D metadata and selection | 23,552 | 0 | 1,347.0 | 0.005384 | 0.012719 | 0.031494 |
| L2 metadata and selection | 753,664 | 0 | 9,933.0 | 0.155699 | 0.383785 | 0.974623 |
| Preservation controllers | 0 | 184 | 3,066.0 | 0.001533 | 0.002146 | 0.003066 |
| Visibility checks | 0 | 0 | 482.0 | 0.000241 | 0.000337 | 0.000482 |
| LSL release descriptors (conditional) | 0 | 1,820 | 22,162.0 | 0.011081 | 0.015513 | 0.022162 |
| EVT 16 entries / 16 queries | 0 | 1,044 | 70,647.0 | 0.035324 | 0.049453 | 0.070647 |
| Rollback controller | 0 | 43 | 499.0 | 0.000249 | 0.000349 | 0.000499 |
| Context 8 x 80 x 64 (conditional) | 40,960 | 309 | 4,034.5 | 0.010209 | 0.023304 | 0.056463 |
| SW bitmap 16 (conditional new instance) | 0 | 52 | 1,168.0 | 0.000584 | 0.000818 | 0.001168 |
| **原语预算小计** | **818,176** | **3,452** | **113,338.5** | **0.220304** | **0.488425** | **1.160604** |


`A = [RAM_bits×SRAM_density×packing + GE×NAND2_area]/10^6`。密度单位 μm²/bit，NAND2 单位 μm²/GE：

| 假设 | SRAM density | packing | NAND2 area | 旧 interface margin（仅用于历史对照） |
|---|---:|---:|---:|---:|
| Low | 0.20 | 1.00 | 0.50 | 5% |
| Typical | 0.40 | 1.25 | 0.70 | 15% |
| High | 0.80 | 1.60 | 1.00 | 30% |

这些数没有标准单元库或 SRAM compiler 标定，**不是统计置信区间，也不是工程上下界**。本轮没有把未知接入工作用15%认证为已覆盖；原语小计中不再含该余量。Typical 的 RAM 项是 `818176×0.4×1.25/1e6=0.409088`；逻辑项是 `113338.5×0.7/1e6=0.07933695`，相加0.48842495。

| 场景 | Low | Typical | High | 含义 |
|---|---:|---:|---:|---|
| 旧512 KiB/Seq16原报告 | 0.087197 | 0.192302 | 0.453780 | 303,104 RAM bit、50,620.5 GE，含2 buffer及旧余量 |
| 1 MiB/Seq16原语 | 0.141752 | 0.318978 | 0.765604 | 只作缩窄包号假设；需要映射协议 |
| 1 MiB/Seq16，旧规则 | 0.143566 | 0.326249 | 0.786225 | 16-way selector、16-query EVT已重统计 |
| **1 MiB/Seq32原语** | **0.220304** | **0.488425** | **1.160604** | 缩减 image identity 设计，未补接入成本 |
| 1 MiB/Seq32，旧规则 | 0.223343 | 0.500837 | 1.195916 | 加假设2 buffer和旧余量，仅敏感性对照 |
| Seq32，不新增SW及LSL描述符 | 0.208639 | 0.472094 | 1.137274 | 有条件复用/删除，非确认净增量 |

**SRAM 映射风险。** Yosys 原输出把 way mask 表示成8/16写端口；本轮 `memory_share` 证明可合并为同一地址、按way mask的1写端口，仍有1同步读端口（[memory_port_audit.json](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/results/memory_port_audit.json)）。因此不能按真正16个独立W端口处罚，但也不能直接假定可用理想1RW macro：独立读写同周期、mask粒度、同地址 read-before-write、736-bit宽行、输出寄存器、banking、reset/bypass和ECC都需要宏匹配/仲裁。所有 RAM 在 generic 逻辑中是黑盒，按bit的面积完全是估算。

反向敏感性：若这818,176位最终全部落成 DFF，单按 DFF6 和 Typical NAND2 假设，存储单元本体就是 **3.436339 mm²**（还没有存储端口 mux/decoder），应替换原0.409088的SRAM项。只有2×64B小buffer若采用FF，DFF本体也约0.004301 mm²，而旧SRAM计价仅0.000512。以上都不是标准库映射面积或上界。

## 5. 三个统一基线与能确认的净增量

可复用的三套**声明配置**已写入 [matched_profiles.json](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/config/matched_profiles.json)；本轮未 elaboration/synthesis，不能伪称已存在三个可执行硬件构建。三者统一采用本报告冻结几何（1 BOOM、4 native Rockets、ROB42/IQ72、相同I/D/L2、16 GiB target address space、200/100 MHz target约束）。Unprotected 仍保留4个普通 Rocket，移除保护专用 snapshot/LSL/checker控制；若使用单BOOM基线，应另列，不能用于本次同核数净增量。

| 配置 | 相同共同硬件 C | 保护硬件 | 标准单元面积 | SRAM宏面积 | 总面积 |
|---|---|---|---|---|---|
| Unprotected | 包含 | 无保护专用逻辑 | 待同配置综合 | 待宏映射 | U=C，未知 |
| PEEK | 包含 | H_PEEK，只计一次 | 待同配置综合 | 待宏映射 | P=C+H_PEEK，未知 |
| PALIMPSEST | 包含 | H_PEEK+净变化Δ | 待集成后综合 | 待宏映射 | P+Δ，未知 |

完整系统边界统一包含所有5核、所有 L1/L2 Data/Tag、宏及外围、互连/CDC、同一片上内存接口和保护控制。排除外部DRAM颗粒、FireSim host/bridge及纯测量观察器；若片上DDR控制器并不存在，不凭空添加。共同 Data payload 是 `(32KiB×2 +4×4KiB×2 +1MiB)×8=9,175,040 bit`，不含Tag/ECC；这是共同资源位数，**不是一个已知的 mm² 总面积**。旧 `1024×168 bit` directory 只适用旧生成物，不能用于1 MiB新目录。

可确认的是：旧值存在几何和位宽口径偏小；修订的条件原语预算约0.49 mm²。**完整净增量目前仍是 UNVERIFIED**：

`Δ = 原语预算 + 未实现的数据通路/恢复/仲裁/事务管理 + 宏与端口实现修正 − 经证明可复用或删除的逻辑`。

0.472094/0.488425/0.500837均不能替代这个尚未知的Δ，也不能声称“至少0.49”。已有逻辑可减，遗漏逻辑可加，端口/标识设计也会改变资源。相对 PEEK 百分比只能在获得同边界 P 后计算 `100×Δ/P`；相对未保护为 `100×(H_PEEK+Δ)/U`。PEEK论文的 `3.96+4×0.27=5.04 mm²` 来自另一核配置/物理边界（[Micro26_PEEK.txt:941](/data1/gzh/EC/check/area_eval/evidence/Micro26_PEEK.txt:941)），3.89又是MEEK而非未保护；本轮撤销以它为分母的项目开销结论。旧约3.8%仅是异配置参考除法。

几何变化、LSL实际容量、队列准入和集成并行度会影响性能/面积比较本身，不能仅修改表格数字后保留不匹配的实验结论。若性能数据确实来自同一冻结几何，旧512KiB面积预算只是需要重新计算；若两个变体使用不同几何或LSL语义，必须重建可比实验。没有完成数据复制或恢复闭环则涉及功能正确性；这比表格措辞问题更严重。频率与latency字段应分别标明target设定、控制器参数或STA/命中测量结果，不能混用。

## 6. 完整性与发表判断

10个原语覆盖了论文机制的部分控制表达，但**没有完成 Section IV 的系统实现**。逐模块审计见 [rtl_coverage.md](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/reports/rtl_coverage.md)；带现有源码接点、协议、测试和阶段出口的最小集成方案见 [integration_plan.md](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/reports/integration_plan.md)。两个特别有证据的前进性限制由新短测试复现：EVT16在15次rollback后拒绝；8-bit preserve TID在255个已ACK事务后即使空闲也永久停止，测试日志 [limits-1.log](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/results/limits-1.log)。它们保护身份不误用，但不能满足长期运行前进性。

现在可以写入论文的是：实际平台几何、原语 generic 资源、明确标注假设的分析模型及限制。可以写“当前条件原语预算约0.49 mm²；完整净增量尚待集成与物理映射”。**不能写**“PALIMPSEST在28nm综合面积0.19/0.49mm²”“比PEEK增加3.8%”“完整Section IV已实现”“已达3.2GHz”“DDR3-1066系统面积”。DAC硬件开销节需要同配置三基线、功能闭环、宏映射、统一时序约束、面积和STA原始报告之后再给定量结论；本轮没有这些系统实测结果。

## 7. 本轮产物与复算

先运行 `python3 scripts/synthesize_shapes.py`（每形态每阶段60秒超时，仅独立原语），再运行 `python3 scripts/recalculate.py` 和 `python3 scripts/write_reports.py`。不会调用旧 `run_all.py` 或写旧结果。新 testbench 由 [limits-test.json](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/results/limits-test.json) 记录准确命令；原有测试结果保留在 [tests.json](/data1/gzh/EC/check/area_eval/results/tests.json)。物理假设独立于结构敏感性，Low/Typical/High都固定Seq32等结构参数。配置、模块明细、三基线和元数据CSV均位于本修订的 `config/`、`results/`。

图：[primitive_budget.pdf](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/figures/primitive_budget.pdf)、[model_scenarios.pdf](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/figures/model_scenarios.pdf)（附SVG/PNG）。前者拆分RAM假设与generic逻辑；后者只比较采用同一旧计价规则的三个设计场景。图中没有用假柱状图补齐未知的三基线系统总面积。
