#!/usr/bin/env python3
from pathlib import Path
import csv,json

R=Path(__file__).resolve().parents[1]
A=R.parents[1]; B=A.parents[1]
F=B/'firesim/final-opt4-20261106/C4/chipyard/generators'
S=B/'check/source/chipyard/generators'
def link(p,line=None,label=None):
    p=Path(p)
    return f'[{label or p.name+(":"+str(line) if line else "")}]({p}'+(f':{line}' if line else '')+')'
def f(p,n):return link(F/p,n)
def s(p,n):return link(S/p,n)
def rtl(n):return link(A/'rtl/palimpsest.sv',n)
def local(p):return link(R/p)
def write(p,text):(R/p).write_text(text.strip()+'\n')
summary=json.loads((R/'results/area_summary.json').read_text())
rows=list(csv.DictReader((R/'results/module_area.csv').open()))
rows=[r for r in rows if r['sequence_bits']=='32']
table='| 模块组（建议实例数） | RAM bit | DFF bit | GE（含 DFF、不含 RAM） | Low | Typical | High |\n|---|---:|---:|---:|---:|---:|---:|\n'
for r in rows:
    table+=f"| {r['component']} | {int(r['RAM_bits']):,} | {int(r['DFF_bits']):,} | {float(r['GE_excluding_RAM']):,.1f} | {float(r['low_mm2_model']):.6f} | {float(r['typical_mm2_model']):.6f} | {float(r['high_mm2_model']):.6f} |\n"
table+='| **原语预算小计** | **818,176** | **3,452** | **113,338.5** | **0.220304** | **0.488425** | **1.160604** |\n'

write('reports/area_audit.md',f'''
# PALIMPSEST 面积评估修订 r2（2026-11-13）

**0.1923 mm² 的旧计算可以精确复现，但不能作为当前实验的完整面积开销。** 旧值使用 `check` 的 512 KiB L2、Seq16 和未集成的原语预算。当前冻结运行入口绑定的是 1 MiB/16 路 L2，且 packet sequence 为 32 位。在明确保留的缩减标识设计假设下，修订后的原语 Typical 小计为 **0.488425 mm²**；沿用旧缓冲和余量规则为 **0.500837 mm²**。两者均为分析模型，既不是完整 PALIMPSEST−PEEK 差值，也不是 28 nm 综合实测。

本轮保留原 RTL、原报告和原结果；所有新增文件只放在本修订目录。只做静态检查、哈希核验、26 个小规模参数形态的 generic 综合和短单元测试。没有启动 SoC 综合、FPGA、PARSEC，也没有操作其他任务。{local('evidence/provenance-checks.json')} 核验原始清单 870 项、生成清单 746 项未变；最终保全检查见 {local('evidence/preservation-check.json')}。

## 1. 配置来源与比较平台

| 参数 | 旧 `check` 平台 | 本轮主口径：冻结实验几何 | 生效依据 |
|---|---|---|---|
| 核心 | 1 BOOM + 4 Rocket | 1 BOOM + 4 Rocket | {f('rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala',10)}；{f('chipyard/src/main/scala/config/RocketConfigs.scala',27)} |
| BOOM 宽度 / ROB / IQ | decode3 / 96 / 72 | decode3 / 42 / 72（16+32+24） | {s('boom/src/main/scala/common/config-mixins.scala',187)}；{f('boom/src/main/scala/common/config-mixins.scala',240)} |
| LDQ/STQ | 24/24 | 16/16 | {s('boom/src/main/scala/common/config-mixins.scala',196)}；{f('boom/src/main/scala/common/config-mixins.scala',249)} |
| Main L1I | 32 KiB / 8 路 | 32 KiB / 8 路 / 64 sets | {f('boom/src/main/scala/common/config-mixins.scala',261)} |
| Main L1D | 32 KiB / 8 路 / 4 MSHR | 32 KiB / 2 路 / 256 sets / 6 MSHR | {s('boom/src/main/scala/common/config-mixins.scala',204)}；{f('boom/src/main/scala/common/config-mixins.scala',258)} |
| Checker L1I / L1D | I32 KiB/8 路；D4 KiB/2 路 | I、D 均 4 KiB/2 路/32 sets | {s('rocket-chip/src/main/scala/subsystem/Configs.scala',249)}；{f('rocket-chip/src/main/scala/subsystem/Configs.scala',249)}、{f('rocket-chip/src/main/scala/subsystem/Configs.scala',258)} |
| L2 | **512 KiB / 8 路 / 1024 sets** | **1 MiB / 16 路 / 1024 sets** | {link(B/'check/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/chipyard.TestHarness.v1Config.dts',186)}；{f('chipyard/src/main/scala/config/RocketConfigs.scala',20)} |
| L2 MSHR | 7 | 4 | 两份生成 DTS：旧 :192；{link(B/'firesim/final-opt4-20261106/builds/C4-elaborate-20261106T100250.032318Z/firesim.firesim.FireSim.dts',199)} |
| Cache line | 64 B | 64 B | 同一冻结 DTS :18、:190 |
| 频率 | target 200/100 MHz | target 200/100 MHz，非 STA 结果 | {f('chipyard/src/main/scala/config/RocketConfigs.scala',10)}；运行绑定 :115 |
| 内存 | 256 MiB 地址空间 | 16 GiB 地址空间，guest 限 2 GiB | 运行绑定 :102、:117；冻结 DTS :169 |
| 内存时序模型 | 不作跨平台外推 | FASED 读写 latency30、并发4/4；没有 DDR3-1066 实证 | {link(B/'Experiment/parsec8-simmedium-ec-r2-20261112/runs/blackscholes/binding.json',7)} |
| 保护实现 | PEEK 风格旧实现，segment ID 有 tie-off | 已带 EC 的 SW/SVB/receipt，不是干净 PEEK | {s('rocket-chip/src/main/scala/r/R_IC.scala',117)}；{f('boom/src/main/scala/lsu/dcache.scala',631)}、{f('boom/src/main/scala/lsu/dcache.scala',1745)} |

冻结生成参数见 {link(B/'firesim/final-opt4-20261106/builds/C4-parameters-20261106T100204.040607Z/parameters.json',653)}，DTS 确认 L2 1,048,576 B；运行 {link(B/'Experiment/parsec8-simmedium-ec-r2-20261112/runs/blackscholes/binding.json',3)} 选用的二进制实算 SHA256 与 :197 的 `cc2993bd…b2867` 一致。它证明选定硬件入口，不证明本次 PARSEC 样本有效，更不证明面积。冻结源码与生成物的对应仍以冻结构建记录为准；本轮未重做 elaboration。

当前 `DAC_2027_EC.pdf` 的 Table I 也已写成 ROB42、IQ72、L2 1 MiB/16 路（{link(A/'evidence/DAC_2027_EC.txt',415)}）。本报告没有把文档当作参数生效证据。`outerLatencyCycles=12`/`memCycles=12` 是控制器参数，不能在未测量命中流水线前等同“L2 hit latency12”；3.2/1.6 GHz 也没有本轮物理时序证据。

## 2. L1D/L2 位数与标识语义

旧原型字段为 `Seq16 + Epoch4 + CurGen8 + Cur1 + preserved1 = 30 bit/line`，不是论文规定的位宽。Main L1D 共有 `32768/64=512` 行；旧 L2 `524288/64=8192` 行，故 `512×30 + 8192×30 = 261,120 bit`。此数**只对应旧 512 KiB 几何下的设计假设**，不是冻结实验已经实现的 PAL 元数据。

| 几何 / 字段假设 | 每行 bit | L1D bit | L2 bit | 合计 bit |
|---|---:|---:|---:|---:|
| 旧 512 KiB / Seq16 | 30 | 15,360 | 245,760 | 261,120 |
| 冻结 1 MiB / 仍假设 Seq16 | 30 | 15,360 | 491,520 | 506,880 |
| 冻结 1 MiB / Seq32，其他假设不变 | 46 | 23,552 | 753,664 | 777,216 |

{f('rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala',20)} 的实际包号宽度是 32。若选 16，必须另行实现并证明 32→16 窗口映射、回绕和旧响应隔离；本轮没有这个机制。46 位场景只保留完整 packet sequence，**没有保留冻结接口的完整 image identity**，因此只能称“缩减标识设计预算”。

冻结 `CacheImageKey` 实际为 `valid1 + writer16 + generation32 + contentSeq32 = 81` 位（{f('rocket-chip/src/main/scala/tilelink/CacheImage.scala',12)}）。其 generation 是内容/写入身份，`slotEpoch16` 是驻留槽身份，session epoch 是会话身份；都不能直接替代论文的恢复 Epoch/Current generation。若暂时保留整个 81 位 key，再独立添加恢复 Epoch4、CurGen8 和两个标志，会形成 **95 bit/line、合计 1,605,120 bit** 的另一种设计敏感性；尚未综合、也不代表应该全部新增。

冻结 L2 源码的普通 directory 之外已经声明 `dcache1 + packetSeq32 + packetTracked1 + image81 + outerPreserved1 = 116 bit/line`，16,384 行对应 **1,900,544 个声明位**；其中 image+receipt 的 82 位子集为 1,343,488 bit（{f('sifive-cache/design/craft/inclusivecache/src/Directory.scala',28)}）。这些字段包含统计用途，未做生产版本裁剪或映射优化，不能当成实测面积；但足以说明 46 位预算不是现有 EC 全部逻辑的清单。116 位总数和 82 位子集**不得相加**。详见 {local('results/frozen_identity_inventory.csv')}。

生成物进一步确认：{link(B/'Experiment/firesim-final-opt4-20261106/cycleprecise-frozen-full-metasim-r1-20261111/host/FireSim-generated.sv',117473)} 的 L2 directory 是 **16×1024×143=2,342,912 bit**（含普通tag/coherence及上述EC字段）；不是旧目录 `1024×168`。该生成文件的实算hash与冻结plan记录相同，结构统计见 {local('evidence/generated-identity-audit.json')}。这里的2,342,912和1,900,544是整体与子集，也不能相加；更不能再把777,216位设计sidecar无条件叠加后称为净增量。

保持原 data arrays 不复制整套 Cache：版本占用已有 ways，会影响有效容量和冲突率；若为保持有效容量而扩容 Data/Tag，则必须在三种配置中重新定义实验，不可把扩容藏在元数据预算中。L1I 和 checker cache 没有在本模型额外加入历史版本位；这依赖单主核、其他写入为可信 BASE 的接口契约。多主核扩展必须重新计 owner、SW 和端口。

## 3. 上下文、EVT、LSL 与重复计费

**上下文。** 原型 `8 slots ×80 words×64 bit =40,960 RAM bit`。80 来自 `32 integer +32 FP +13 shadow CSR +PC +FCSR +priv/mode`；原 PEEK 捕获寄存器见 {s('rocket-chip/src/main/scala/r/R_RSU.scala',60)}，13 项 CSR 的确切列表见 {s('rocket-chip/src/main/scala/rocket/Instructions.scala',1582)}。这只是按现有接口打包：x0、PC40/FCSR8 对齐有冗余；未证明覆盖 satp、完整陷阱状态、所有可恢复 CSR、计数器/中断/设备语义，不能称完整 ISA checkpoint。8 不是由 4 checkers 自动推出，论文 §IV 没有给出 8 的证明。

必须建立 `retained = 恢复锚点 + 已分配未安全退休的所有段起点 + capture/恢复并发预留` 的生命周期不变量，并对 admission、PASS holes、rollback 和 capture 施加上限。没有上限就不能确定 8 槽是否够用。PEEK 既有主核 snapshot、checker 的 CPS/ECP/GMode 数组各计一次（{s('rocket-chip/src/main/scala/r/R_RSUSL.scala',81)}）；它们有现有消费者，不能在未证明端口和寿命可共享前直接当成 8 个空闲保留槽。新增预算保守保留整池，但未来复用后应按净变化扣除，并补齐捕获/恢复 adapter。

**EVT。** Seq16、Epoch4、16 entries 的寄存器数量为 `16×(2×16+1)+4=532`；Seq32 为 `16×(2×32+1)+4=1044`。原报告的 8 query lanes 无法同时评价一个 16 路 set，本轮改为 16；它仅支持每次一个 16-way 查询，L1/L2/visibility 之间仍需串行仲裁或增加端口/副本。32 位场景 EVT generic 为 70,647 GE，不是 SRAM 按 bit 计价；深度16和 Epoch4仍是设计选择。{rtl(29)} 没有 epoch GC/rebase，15 次 rollback 后 fail-closed；CurGen8 到255后也需要受控排空/重建。

**LSL。** 原 `R_LSL` 有 `2×255×130=66,300 bit/checker` payload，约 8.09 KiB；64-bit 地址+64-bit数据占 8,160 B，另有标志和 CSR/RoCC queues。冻结实例仍传255（{f('rocket-chip/src/main/scala/rocket/RocketCore.scala',838)}），不能称物理实现只有4 KiB。该存储在 PEEK 与 PAL 共同保护基线中保留，**未在增量重复加入**。原 dequeue 已在 checker 读取时破坏性弹出（{s('rocket-chip/src/main/scala/r/R_LSL.scala',119)}）；必须说明新增 reclaim 到底释放什么尚存资源，不能把 ParaMedic 的恢复日志保留策略假定为 PEEK 的实现。

新增 `4×8` release 描述符仅是原型预算，和8个全局 context、16-entry SW window没有统一 admission 证明；实际 block/页分配器、holes reuse、rollback cancellation 均未实现。若无需新增此描述符表，应去掉对应 **0.0155134 mm² Typical**，而不是再增加一份 LSL data。

**Bitmap/SW。** 旧 check 的 `core_bitmap/cp_bitmap` 是调度编码，不是验证前缀（{s('rocket-chip/src/main/scala/r/R_IC.scala',385)}），所以旧模型没有发现可直接抵扣的 SW。冻结源码已有256-entry `DirtyWritebackBitmap` 与32-bit SW（{f('boom/src/main/scala/lsu/dcache.scala',1738)}）；若复用它，禁止再叠加原型的16-entry SW。原型 SW 的 Typical 0.0008176 mm²仅是可去重原语，不等于既有256-entry模块的面积，也不证明恢复跨 epoch 接口已满足。

**其他去重。** 原 WB line buffer、L2 BankedStore/dir 和 SRAM 宏都在共同基线计一次；跨层保存优先锁住源 way 并复用 WB reader。旧额外2×64B buffer是未实例化假设，本轮原语小计删除。冻结32-entry SVB 和较宽 image/receipt 若保留，必须按真实映射计入 PAL；若被重构替换，只计 `new−old`，不得把整个冻结 EC 当 PEEK 后再整套叠加。源码 {f('boom/src/main/scala/lsu/speculative-version-buffer.scala',15)}、:107 声明的数据为 `32×64B=16,384 bit`（未含 key/状态/ECC）；这既不能遗漏，也不能在新复制 buffer 中重复计费。

生成 RTL 也可看到 SVB 的81位key接口、4×128-bit行输入（{link(B/'Experiment/firesim-final-opt4-20261106/cycleprecise-frozen-full-metasim-r1-20261111/host/FireSim-generated.sv',195290)}）以及32组数据寄存器。这说明现有SVB并非本轮原语模型的SRAM黑盒；若保留其当前Reg实现，需要真实cell映射或明确改为macro，不能直接按SRAM单价增加16,384位后就称完成核算。逐资源归属另见 {local('results/accounting_ledger.csv')}。

## 4. 模块面积明细与 Low / Typical / High

下表为 **1 MiB/16 路 L2、2 路 L1D、Seq32、Epoch4、CurGen8、context8、reclaim8/checker、EVT16×16-query** 的条件预算；单元未构成系统实例。所有面积单位 mm²，列名代表物理敏感性假设。GE 按 DFF6、MUX3、XOR2、AND/OR1、INV0.5 等权重折算；DFF 已在 GE 中，**没有再按 SRAM bit 重复收费**。可复算数据：{local('results/module_area.csv')}，逐形态资源与日志：{local('results/synthesis/seq32/summary.json')}。

{table}

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

**SRAM 映射风险。** Yosys 原输出把 way mask 表示成8/16写端口；本轮 `memory_share` 证明可合并为同一地址、按way mask的1写端口，仍有1同步读端口（{local('results/memory_port_audit.json')}）。因此不能按真正16个独立W端口处罚，但也不能直接假定可用理想1RW macro：独立读写同周期、mask粒度、同地址 read-before-write、736-bit宽行、输出寄存器、banking、reset/bypass和ECC都需要宏匹配/仲裁。所有 RAM 在 generic 逻辑中是黑盒，按bit的面积完全是估算。

反向敏感性：若这818,176位最终全部落成 DFF，单按 DFF6 和 Typical NAND2 假设，存储单元本体就是 **3.436339 mm²**（还没有存储端口 mux/decoder），应替换原0.409088的SRAM项。只有2×64B小buffer若采用FF，DFF本体也约0.004301 mm²，而旧SRAM计价仅0.000512。以上都不是标准库映射面积或上界。

## 5. 三个统一基线与能确认的净增量

可复用的三套**声明配置**已写入 {local('config/matched_profiles.json')}；本轮未 elaboration/synthesis，不能伪称已存在三个可执行硬件构建。三者统一采用本报告冻结几何（1 BOOM、4 native Rockets、ROB42/IQ72、相同I/D/L2、16 GiB target address space、200/100 MHz target约束）。Unprotected 仍保留4个普通 Rocket，移除保护专用 snapshot/LSL/checker控制；若使用单BOOM基线，应另列，不能用于本次同核数净增量。

| 配置 | 相同共同硬件 C | 保护硬件 | 标准单元面积 | SRAM宏面积 | 总面积 |
|---|---|---|---|---|---|
| Unprotected | 包含 | 无保护专用逻辑 | 待同配置综合 | 待宏映射 | U=C，未知 |
| PEEK | 包含 | H_PEEK，只计一次 | 待同配置综合 | 待宏映射 | P=C+H_PEEK，未知 |
| PALIMPSEST | 包含 | H_PEEK+净变化Δ | 待集成后综合 | 待宏映射 | P+Δ，未知 |

完整系统边界统一包含所有5核、所有 L1/L2 Data/Tag、宏及外围、互连/CDC、同一片上内存接口和保护控制。排除外部DRAM颗粒、FireSim host/bridge及纯测量观察器；若片上DDR控制器并不存在，不凭空添加。共同 Data payload 是 `(32KiB×2 +4×4KiB×2 +1MiB)×8=9,175,040 bit`，不含Tag/ECC；这是共同资源位数，**不是一个已知的 mm² 总面积**。旧 `1024×168 bit` directory 只适用旧生成物，不能用于1 MiB新目录。

可确认的是：旧值存在几何和位宽口径偏小；修订的条件原语预算约0.49 mm²。**完整净增量目前仍是 UNVERIFIED**：

`Δ = 原语预算 + 未实现的数据通路/恢复/仲裁/事务管理 + 宏与端口实现修正 − 经证明可复用或删除的逻辑`。

0.472094/0.488425/0.500837均不能替代这个尚未知的Δ，也不能声称“至少0.49”。已有逻辑可减，遗漏逻辑可加，端口/标识设计也会改变资源。相对 PEEK 百分比只能在获得同边界 P 后计算 `100×Δ/P`；相对未保护为 `100×(H_PEEK+Δ)/U`。PEEK论文的 `3.96+4×0.27=5.04 mm²` 来自另一核配置/物理边界（{link(A/'evidence/Micro26_PEEK.txt',941)}），3.89又是MEEK而非未保护；本轮撤销以它为分母的项目开销结论。旧约3.8%仅是异配置参考除法。

几何变化、LSL实际容量、队列准入和集成并行度会影响性能/面积比较本身，不能仅修改表格数字后保留不匹配的实验结论。若性能数据确实来自同一冻结几何，旧512KiB面积预算只是需要重新计算；若两个变体使用不同几何或LSL语义，必须重建可比实验。没有完成数据复制或恢复闭环则涉及功能正确性；这比表格措辞问题更严重。频率与latency字段应分别标明target设定、控制器参数或STA/命中测量结果，不能混用。

## 6. 完整性与发表判断

10个原语覆盖了论文机制的部分控制表达，但**没有完成 Section IV 的系统实现**。逐模块审计见 {local('reports/rtl_coverage.md')}；带现有源码接点、协议、测试和阶段出口的最小集成方案见 {local('reports/integration_plan.md')}。两个特别有证据的前进性限制由新短测试复现：EVT16在15次rollback后拒绝；8-bit preserve TID在255个已ACK事务后即使空闲也永久停止，测试日志 {local('results/limits-1.log')}。它们保护身份不误用，但不能满足长期运行前进性。

现在可以写入论文的是：实际平台几何、原语 generic 资源、明确标注假设的分析模型及限制。可以写“当前条件原语预算约0.49 mm²；完整净增量尚待集成与物理映射”。**不能写**“PALIMPSEST在28nm综合面积0.19/0.49mm²”“比PEEK增加3.8%”“完整Section IV已实现”“已达3.2GHz”“DDR3-1066系统面积”。DAC硬件开销节需要同配置三基线、功能闭环、宏映射、统一时序约束、面积和STA原始报告之后再给定量结论；本轮没有这些系统实测结果。

## 7. 本轮产物与复算

先运行 `python3 scripts/synthesize_shapes.py`（每形态每阶段60秒超时，仅独立原语），再运行 `python3 scripts/recalculate.py` 和 `python3 scripts/write_reports.py`。不会调用旧 `run_all.py` 或写旧结果。新 testbench 由 {local('results/limits-test.json')} 记录准确命令；原有测试结果保留在 {link(A/'results/tests.json')}。物理假设独立于结构敏感性，Low/Typical/High都固定Seq32等结构参数。配置、模块明细、三基线和元数据CSV均位于本修订的 `config/`、`results/`。

图：{local('figures/primitive_budget.pdf')}、{local('figures/model_scenarios.pdf')}（附SVG/PNG）。前者拆分RAM假设与generic逻辑；后者只比较采用同一旧计价规则的三个设计场景。图中没有用假柱状图补齐未知的三基线系统总面积。
''')

write('reports/rtl_coverage.md',f'''
# 10 个独立 RTL 原语的机制覆盖审计

所有结论指向未经修改的 {link(A/'rtl/palimpsest.sv')}。原测试通过意味着原语测试范围内成立；generic 可综合也不代表 Cache/SoC 集成成立。论文机制来源为 {link(A/'evidence/DAC_2027_EC.txt',327)}（§IV-A）、:330（§IV-C）、:387（§IV-D）、:370（§IV-E）。本轮没有修补原 RTL，以下缺口仍然存在。

| 原语 | 已提供 | 接入缺口 / 对面积和行为的影响 | 证据 |
|---|---|---|---|
| pal_metadata_ram | packed synchronous sidecar，masked write | 没有字段bundle、cache valid/reset gating、tag/way bypass对齐；同一写数据只能广播到mask选中的ways，不能同拍清旧Cur并写新版本不同字段，需串行atomic更新或重做端口。多请求调度/宏wrapper未计 | {rtl(8)} |
| pal_evt | 历史interval截断、history-valid查询、有限容量拒绝 | 4-bit恢复Epoch/深度16无生命周期证明；没有reference GC/rebase；查询端口数量要随实际并行需求定；旧8-query不足16-way同时查询 | {rtl(29)} |
| pal_version_select | 单层set内Normal/Recovery选择，取max Seq&lt;boundary | 没有数据返回、跨L1/L2/SVB候选比较、下层promotion、CurGen原子更新；normal还依赖history_valid，须解决命中路径时序；多个Current仅报flag。现有Mux1H只允许一个tag hit，不能原样接入重复tag | {rtl(75)}；旧 {s('boom/src/main/scala/lsu/dcache.scala',646)}；冻结 {f('sifive-cache/design/craft/inclusivecache/src/Directory.scala',144)} |
| pal_visibility | safe=history-valid且Seq≤producer SW；允许自身unsafe | 依赖外部可信producer/requester，必须遍历Get/Acquire/Probe/Release/AMO/uncached/DMA/DRAM每个出口及所有data beats；不是单个load信号相与即可。多producer SW查找未计 | {rtl(107)} |
| pal_store_policy | 同段in-place，否则选择reusable/victim，阻止未保全覆盖 | `victim_requires_history`/`secured`由外部提供，无保留策略；**新way部分写必须先复制/填充旧Current完整64B**，否则未写字节是旧垃圾。缺line-copy、mask合并、AMO/LRSC、异常/重放原子性及租约 | {rtl(122)}；真实部分写接点 {s('boom/src/main/scala/lsu/dcache.scala',905)} |
| pal_preserve | 源锁、key/tid/type匹配ACK、cancel后等待已发事务完成 | 没有payload/目的way reservation/目的数据落盘；不能自行证明PreserveACK；只有所有WB共享该入口才能全局串行；缺obsolete未发WB抑制、跨路径每地址排序、drain/rebase。8-bit TID255后停止，ADDR40/key宽也未与实际物理地址契约统一 | {rtl(159)}；{local('results/limits-1.log')} |
| pal_lsl_reclaim | descriptor alloc、PASS+inputs_consumed、held release | 不含data/block allocator，8/checker无依据；缺holes reuse、rollback/cancel回收、stale release隔离。现有LSL已经消费即出队，必须先确认新增表必要性 | {rtl(219)}；{s('rocket-chip/src/main/scala/r/R_LSL.scala',119)} |
| pal_safe_watermark | 有界PASS前缀、epoch过滤、静止rebase接口 | 没有回滚后保留旧epoch有效PASS与新结果的协调；WINDOW16与context8/32descriptors未统一admission；冻结已有256-entrybitmap，不应双重实例化 | {rtl(285)}；{f('boom/src/main/scala/lsu/dcache.scala',1741)} |
| pal_rollback | halt→flush→EVT→context→restart握手骨架 | fault请求没有epoch，旧FAIL可能触发新恢复；没有真实BOOM ARF/PRF/CSR恢复、rename map/freelist重建、ROB/LSQ/前端/旧响应drain；一般branch rollback不能代替提交段恢复 | {rtl(317)}；冻结主核CSR恢复仍tie-off {f('boom/src/main/scala/exu/core.scala',2412)} |
| pal_context_store | 8×80×64流式写完才commit；按slot+seq+epoch读 | payload完整性、段边界原子capture、allocation/retention、实际恢复端口未实现；release只有slot，依赖可信allocator防止旧释放。PEEK checkpoint不是可自动替代的保留池 | {rtl(357)}；{s('rocket-chip/src/main/scala/r/R_RSU.scala',60)} |

## 机制层面的完成度

| 论文 Section IV 机制 | 状态 | 必须完成的闭环 |
|---|---|---|
| 跨层保存 / Preserve ACK | PARTIAL | L1源锁→reader→L2目的预留→历史payload+key原子安装→matching ACK→源复用；L2有victim时递归保存 |
| SW可见性 | PARTIAL | 对每条跨核/DRAM路径生效；SW来自完整可靠的checker结果前缀，回滚重建不混epoch |
| Safe DRAM版本与顺序 | PARTIAL | 最老/最新允许版本的WB抑制、逐地址ACK前串行、真实外层终端ACK契约；C.last/CacheGrant不是证明 |
| LSL提前回收 | PARTIAL / 基线语义待定 | PASS且输入不再需要后真实allocator释放，与恢复版本存储解耦；确认相对PEEK是否新增收益 |
| EVT / Epoch有效性 | 原语测试通过，系统PARTIAL | 跨Cache/MSHR/ACK/结果的身份一致；回绕/GC/重基准后还能长期运行 |
| 回滚Current重建 | PARTIAL | 查询整个可恢复域（含保留的SVB），选全局max-valid Seq&lt;n，再原子提升；只有证明无候选才取safe DRAM |
| Checkpoint恢复 | PARTIAL | 完整架构状态、PRF/rename/freelist/CSR/PC加载、kill旧请求、恢复执行结果一致 |
| Backpressure / 前进性 | PARTIAL | 真实early close/dispatch，资源预留、无环依赖、事务排空、bitmap/context准入；有限身份停止问题解决 |

源代码里的 `Scheduler.evict_safe/grant_safe` 是数据端口hazard互锁，不能拿来代替验证安全性（旧 {s('sifive-cache/design/craft/inclusivecache/src/Scheduler.scala',329)}）。冻结SVB/receipt实现提供了可复用接口，但没有由这些原语构成完整的Epoch/Current/architectural rollback链路。短测试明确观察有限容量停止，不是system liveness通过。新Seq32参数形态本轮完成generic检查；没有声称完成所有Seq32功能回归。
''')

write('reports/integration_plan.md',f'''
# PALIMPSEST 最小完整集成方案（设计产物，尚未修改源码）

主分支建议从冻结 `firesim/final-opt4-20261106/C4/chipyard` 派生隔离实现，保持1 MiB/16-way几何；旧 `check/source` 用于PEEK机制取证，不直接将其512KiB构建与冻结实验相比较。本轮只制定方案和声明配置，未创建/执行新SoC build。

## 1. 三个编译变体与归属

在同一源版本、参数集和约束下增加互斥保护模式：`Unprotected`、`PEEK`、`PALIMPSEST`，统一 {local('config/matched_profiles.json')}。先单独隔离measurement-only counters/observer，三个变体共同排除。PEEK模式保留原snapshot/transport/LSL/checker验证，显式关闭新增EC recovery/SVB/barrier路径；PAL模式逐项复用或替换这些路径。当前冻结EC不能直接重命名为PEEK。所有 enable必须在generated hierarchy证明实际移除/保留，并保存配置hash与参数、宏清单。

对冻结现有字段建立 ownership 表：Seq32共用；CacheImageKey81保留还是替换须协议决定；slotEpoch16/sessionEpoch与RecoveryEpoch分开；SW/bitmap只留一个权威来源；SVB数据一份；PEEK capture和checker snapshot每个现有消费者一份；新增retained context只按净变化。没有完成该表前不发布净面积。

## 2. 统一接口契约

| 接口 | 必须携带与握手语义 | 原型之外的工作 |
|---|---|---|
| SegmentResult | producer、Seq32、恢复Epoch、PASS/FAIL/CANCEL、inputs_consumed，valid/ready | 会话epoch不是恢复epoch；CDC消息不能是裸脉冲，旧结果仅影响其本身资源 |
| CommittedStoreIdentity | Seq32、恢复Epoch、owner、字节mask、AMO/effect token | 段归属在架构边界确定并随STQ/replay持有；不能在晚到DCache写时读取实时段号 |
| PreserveReq | line address、不可变版本key、源/目的reservation、tid、kind、full64B/beat序号与最后拍 | 先预留目的与数据通路，再迁移；阻塞期间源数据与key不可变化 |
| PreserveAck | 完整key+tid+kind、目的已持久占有/有效、失败/取消状态 | 仅目的数据+metadata原子可用才ACK；旧ACK不能解锁新way或新epoch |
| SafeWBReq / WBAck | 地址、版本key、数据/beat、tid、终端response | 区分PreserveACK、ReleaseAck、外部write终端ACK；同地址旧事务终结前不得放行后继 |
| RecoveryLookup | address、boundary、恢复epoch/gen、各层candidate seq/key/data/valid，request-id | 先查L1/L2/保留SVB再比较全局max；没有候选的证明先于DRAM fallback |
| ContextCapture/Restore | 完整payload定义、slot、Seq/Epoch、begin/word/commit、restoreDone | 周期边界一致；旧release需身份验证；restoreDone必须来自真实架构状态完成 |
| Quiesce/Rebase | 停止准入、drain各层MSHR/probe/WB/CDC、所有旧引用归零的ACK | 处理Seq/Epoch/CurGen/TID耗尽；不能清零计数器后允许旧消息重新命中 |

最小实现可先串行：一个全局跨层preserve/WB调度器、一个恢复查询（最多16-way）、一个context stream。这样降低CAM/多端口复杂度，但要确保早派段/验证/ACK不等待同一被占资源；这种串行化会改变性能，必须用同实现重测性能，不能沿用多并行路径数据。保留有限队列并对容量施加admission反压，不能靠“通常不满”。

## 3. 修改接点和每个模块的连接

| 新增/复用模块 | 现有源码接点 | 最小修改与尚缺信号 |
|---|---|---|
| Seq/Epoch与段准入 | {f('rocket-chip/src/main/scala/r/R_IC.scala',211)}；{f('boom/src/main/scala/lsu/lsu.scala',295)}、:1093、:2040 | 复用现有packet_seq通路，核对issue→commit→重放段边界；添加恢复epoch，统一SW/context/LSL窗口准入；early-close请求真正到R_IC并排空提交快照 |
| pal_metadata_ram | {f('boom/src/main/scala/lsu/dcache.scala',709)}；{f('sifive-cache/design/craft/inclusivecache/src/Directory.scala',74)} | 先选择字段复用/重构，再和existing meta/valid/tag/dirty同一事务更新；增加冲突仲裁、同步读对齐、read/write bypass、宏wrapper。多way不同字段更新需要atomic序列或新端口 |
| pal_version_select | 旧L1 tag/permission {s('boom/src/main/scala/lsu/dcache.scala',622)}；冻结L2 {f('sifive-cache/design/craft/inclusivecache/src/Directory.scala',144)} | 原Mux1H前用Current/valid/history筛选；历史重复tag不当普通coherence副本；Recovery返回候选并跨层比较；新Current升格原子化 |
| pal_store_policy + line-copy engine（缺失） | 旧L1 {s('boom/src/main/scala/lsu/dcache.scala',905)}；冻结L1源身份/租约 {f('boom/src/main/scala/lsu/dcache.scala',720)} | 新段首次partial store先full-line copy/merge到新way；控制source/dest lease，处理同set、ECC、probe、refill、AMO、LR/SC、跨行拆分和rollback取消；原型没有该data engine |
| pal_preserve + reader/receipt | 冻结 {f('boom/src/main/scala/lsu/dcache.scala',26)}、:194、:278、:631；{f('boom/src/main/scala/lsu/speculative-version-buffer.scala',79)} | 复用WB reader/SVB immutable snapshot和matching completion；补跨层历史way目的预留及保留决策；把32位真实key/TID方案与原型8位耗尽协调；不能只有source_locked |
| L2 preserve scheduler | {f('sifive-cache/design/craft/inclusivecache/src/Directory.scala',28)}；{f('sifive-cache/design/craft/inclusivecache/src/MSHR.scala',37)}；{f('sifive-cache/design/craft/inclusivecache/src/Scheduler.scala',802)} | Directory read/result从one winner扩展可恢复候选；MSHR/Schedule携带版本与租约；BankedStore读写beat、atomic metadata commit后ACK；历史项不向普通sharer广播为Current |
| pal_visibility | 冻结 {f('rocket-chip/src/main/scala/tilelink/CacheImage.scala',25)}；L1 probe/WB和L2各Source/Sink | 复用producer key和SW，扩展恢复history-valid；区分own、checker、DMA、external，覆盖所有数据和permission出口，AMO返回旧字节也必须安全 |
| Safe DRAM WB manager（缺失） | {f('sifive-cache/design/craft/inclusivecache/src/SourceC.scala',108)}；{f('rocket-chip/src/main/scala/tilelink/ToAXI4.scala',233)} | 审核TL-C/CacheCork/外部manager→AXI-B实际路径；按地址抑制obsolete未发WB、保序到terminalAck，跟踪错误/取消/旧epoch排空。AXI-B是控制器完成契约，并非非易失掉电持久性 |
| pal_safe_watermark / EVT | 冻结 {f('boom/src/main/scala/lsu/dcache.scala',737)}、:1745；原型 {rtl(29)}、{rtl(285)} | 只用一个SW前缀authority；对PASS hole、FAIL、旧epoch、已发WB的关系建立不变量。EVT使用仲裁共享16query或重新算端口；加GC/排空重基准 |
| pal_lsl_reclaim | 冻结 {f('rocket-chip/src/main/scala/r/R_LSL.scala',69)}；旧dequeue {s('rocket-chip/src/main/scala/r/R_LSL.scala',119)} | 先明确消费即释放的FIFO和恢复日志区别；若现有LSL不保留历史则不新增32个表项，仅补真实所需的描述符。若block allocator重做，需holes/cancel/free路径和CDC ACK |
| pal_context_store | {f('boom/src/main/scala/exu/core.scala',2074)}；PEEK {s('rocket-chip/src/main/scala/r/R_RSU.scala',60)} | 复用RSU捕获流，保留池按admission上限定容；保留段起点不是任意时刻采样；核对全部ISA/OS状态、capture commit与slot release身份 |
| pal_rollback + restore adapters（缺失） | 冻结 {f('boom/src/main/scala/exu/core.scala',2412)}；ROB、`exu/rename/rename-stage.scala`、`rename-maptable.scala`、`rename-freelist.scala`、`register-read/regfile.scala` | halt准入，kill未提交和旧epoch效果，drain已接受事务；清ROB/LSQ/忙位，恢复ARF/FP/CSR/PC，重建rename/freelist/PRF约定；epoch更新后才restart，ordinary branch rollback不够 |

所有表中“复用”均为待实现的明确方案，不代表本轮完成连接。需逐个实际验证frozen接口，不能将旧版行号直接作为补丁位置。

## 4. 最小依赖顺序与验收测试

| 阶段 | 最小交付 | 功能测试 / 不变量 | 完成判据 |
|---|---|---|---|
| A：统一基线 | 三模式同参数、production边界、字段ownership、payload及准入证明 | 自动比对generated core/cache/memory参数；每块资源只归一个owner | 参数manifest一致，差异仅保护逻辑；当前尚未完成 |
| B：L1多版本 | meta/selector/store+full-line copy+租约，先2-way | 两段写同地址不同字节，未写字节保持；duplicate tag、same-set conflict、AMO/LRSC、refill/probe/replay、source/dest并发rollback | 与逐字节参考模型一致，无多Current/早复用 |
| C：跨层保存/可见性 | L1→L2→safe外存闭环，shared transaction arbiter | A8→保存A7→L2 victimD6不安全→等待SW→WB终端ACK→PreserveACK；checker/DMA请求unsafe必须阻塞；旧ACK/重复ACK/乱序ACK | 所有path逐拍检查key/data，source hold到matchingACK，无unsafe外泄 |
| D：LSL/context | 生命周期分离、bounded admission、real allocator | PASS乱序/FAIL/Cancel、输入尚未消耗、holes、FIFO消耗、所有slot满、capture中断 | 无丢日志/早释放/永久占位；8slots是否够用有上界证明 |
| E：恢复闭环 | 完整checkpoint恢复、EVT、跨层max候选和Cur提升 | 段8失败选A7而非DRAMA1；不同层/SVB的较新候选、连续两次rollback、旧FAIL/response、无候选safe fallback、trap/CSR/页表/中断、PRF复用 | 与checkpoint参考执行得到相同架构状态和内存；不是只有restoreDone脉冲 |
| F：前进性 | early dispatch、drain/rebase、全资源饱和模型 | 超过15rollbacks、255preserves、255CurGen；seq边界；bitmap满、context满、SVB满、MSHR/probe竞争、64B隔离timer flags | 在公平ACK/checker假设下持续完成，或有明确可恢复的受控排空；有限ID不永久停机 |
| G：物理面积 | 同库同PVT同约束三基线，真实macro映射 | 未映射memory检查，macro读写/mask/latency契约，STA setup/hold和约束覆盖；防DCE删保护状态 | 标准单元+各macro分表及总计，PPA日志/网表/脚本/hash可复现 |

本轮只做了原语资源与有限容量特性验证；A–G没有被整体完成。无需先跑PARSEC或完整综合就可开展B–F的小型cache/coherence测试，但发表系统综合必须在闭环后运行G。性能/latency实验应使用G相同机制和并行度的可执行模型；串行最小实现的面积不能配用另一吞吐实现的性能结果。

## 5. 最终面积报告应保存的证据

三模式的源码commit/patch、配置manifest、generated RTL及memory清单；同一标准单元库/28nm工艺与PVT、SRAM宏型号/端口/面积表、synthesis constraints、compile和area原始日志、被排除observer清单、timing coverage及STA、必要的clock/CDC约束。分别给出标准单元面积、L1/L2 data/tag宏、checkpoint/LSL宏和总面积；统一计算 `Δ=A_PAL−A_PEEK` 及 `Δ/A_PEEK`。保留外部DRAM的容量/时序模型描述，但不把16GiB外部颗粒计入SoC mm²。
''')

write('README.md',f'''
# PALIMPSEST 面积评估 r2

修订日期2026-11-13。保留上一轮所有成果；不覆盖原RTL，不启动SoC/FPGA/PARSEC。

- {local('reports/area_audit.md')}：配置核对、位数、去重、三基线、逐模块及Low/Typical/High、发表判断。
- {local('reports/rtl_coverage.md')}：10个原语与论文Section IV机制覆盖、未实现项。
- {local('reports/integration_plan.md')}：最小接点、接口、顺序和功能/物理验证计划。
- {local('config/matched_profiles.json')}：三种同几何声明配置，尚未生成系统RTL。
- {local('results/module_area.csv')}、{local('results/area_scenarios.csv')}、{local('results/cache_metadata.csv')}：可复算资源预算。
- {local('results/accounting_ledger.csv')}：基线保留、新增、复用/替换及遗漏项归属。
- {local('figures/primitive_budget.pdf')}、{local('figures/model_scenarios.pdf')}：带假设标签的独立导出图。
- {local('evidence/provenance-checks.json')}、{local('results/limits-test.json')}：哈希与短验证证据。

旧0.1923mm²算术成立，但针对512KiB/Seq16和不完整原语。冻结实验为1MiB/16-way；Seq32缩减标识设计的条件原语预算Typical0.488425mm²，旧缓冲/余量规则0.500837mm²。完整同配置PAL−PEEK面积和百分比未知，所有mm²均为分析模型，未取得28nm映射综合结果。
''')
print('Wrote README and 3 reports under',R)
