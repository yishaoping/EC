# PALIMPSEST Hardware Overheads：R3 面积口径审计

**主结论：0.48842495 mm²及9.69097%的算术无误；没有证据支持将其改成一个更低的已校准点估计。** 9.69%是“含L2的条件原语预算 / PEEK论文核面积参考和”，不能称统一边界的面积开销。R3保留原预算，修正解释并给出密度敏感性；没有以降低百分比为目标。

## 1. 输入、范围与证据级别

已读取 [area_audit.md](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/reports/area_audit.md)、[rtl_coverage.md](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/reports/rtl_coverage.md)、[hardware_area_breakdown.csv](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/dac_hardware_overheads/hardware_area_breakdown.csv)。固定L2 1MiB/16-way、Seq32、Main L1D32KiB/2-way、line64B；其余Epoch4/CurGen8、context8、EVT16×16query等均沿用R2假设，不能称全部来自冻结配置。本轮没有修改RTL、没有综合/功能测试/PARSEC、没有操作U280/FireSim任务。

现有generic综合提供逻辑计数和抽象RAM位数；mm²依赖假设换算。PEEK论文3.96/0.27来自其TSMC28nm综合报告的论文数值，不是项目当前网表实测。未找到适用28nm SRAM macro/Memory Compiler面积资料。

## 2. 46bit/line审核

| 字段 | 位数 | 必要语义 / 复用判断 |
|---|---:|---|
| Seq | 32 | Producing segment and SW comparison; required with Epoch for reused execution histories；Potential single-storage reuse, not an additional copy; PEEK ownership not established |
| Recovery Epoch | 4 | Distinguish surviving and discarded histories with reused Seq；Cannot merge with slot/session epoch without semantics proof |
| Current Generation | 8 | Invalidate old Current mappings lazily across rollback；Cannot substitute CacheImageKey.generation; different update lifetimes |
| Current flag | 1 | Distinguish ongoing Current from historical ways with equal address；Coherence-valid does not encode Current; derived encoding would change model/control |
| Preserved receipt | 1 | Exact-key predecessor retained elsewhere before reuse；Existing receipt is a reuse candidate; dirty/safe status cannot replace it |

来源：原型 [palimpsest.sv](/data1/gzh/EC/check/area_eval/rtl/palimpsest.sv:8)、:29、:75；冻结 [CacheImage.scala](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/rocket-chip/src/main/scala/tilelink/CacheImage.scala:12)；[Directory.scala](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Directory.scala:28)。Seq32有冻结依据；恢复Epoch4、CurrentGeneration8是设计假设。slotEpoch16、会话epoch、image generation32的更新事件不同，不能据名字相似合并。Cur不是coherence-valid；preserved不是dirty或Seq≤SW：后者分别描述权限/脏状态和验证安全，不证明对应历史数据已经在其他位置保存。

普通Tag/dirty/state/clients已在Cache基线，46位没有再包含它们；冻结image.valid/writer/generation等也没有在原预算逐项额外加入。模型更像一种缩减身份的设计方案，而非冻结实现所有字段的完整清单。当前所有“可复用”判断仅防止再叠加一份，不证明这份字段本来属于PEEK。

每way配置完整字段是当前dense sidecar结构：L2`1024sets×16ways×46=753664bit`，L1D`512×46=23552bit`。invalid/safe状态下不用某些值，只能降低活动率，不能减少已分配SRAM。对于任一时刻任意way可含版本的设计，没有占用上界就不能按平均speculative比例删位。字典编码、per-segment共享、稀疏记录或状态复用需要指针/epoch/valid/map/溢出处理，当前无此实现或面积证据，因此不计压缩收益。EVT已将历史区间集中存储，每行仍需索引；GlobalCurGen是全局比较值，每行generation是版本标签，二者不属于重复记录。

## 3. L2计费无重复，0.3837851的展开

`L2 = 753664×0.40×1.25/1e6 + (912+8615+406)×0.70/1e6`

| 项目 | mm² | 依据 |
|---|---:|---|
| 元数据RAM | 0.3768320 | [result.json](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/results/synthesis/seq32/l2_metadata/result.json:21) |
| metadata wrapper，912GE | 0.0006384 | 同result:11 |
| version selector，8615GE | 0.0060305 | [result.json](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/results/synthesis/seq32/selector_l2/result.json:22) |
| store policy，406GE | 0.0002842 | [result.json](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/results/synthesis/seq32/store_l2/result.json:22) |
| **合计** | **0.3837851** | RAM一次，三个逻辑形态各一次 |

selector/store未作为另一个模块行再次计费。EVT在独立行负责history-valid，selector消费其结果并选winner，并不是同一逻辑。Wrapper mask gates与未来macro端口外围有潜在边界重叠，但没有选定宏，不能直接扣掉912GE或任何外围金额。

## 4. SRAM单位面积与packing

项目搜索包含ignored/hidden候选文件；详见 [macro-asset-search.json](/data1/gzh/EC/check/area_eval/revisions/r3-area-audit-20261113/evidence/macro-asset-search.json)。发现ASAP7和Sky130资产，未发现适用28nm宏面积标定。ASAP7自带SRAM甚至明确是blank dummy且4×缩放：[README.md](/data1/gzh/EC/firesim/conda-env/lib/python3.10/site-packages/hammer/technology/asap7/README.md:29)；不能从这些LEF尺寸推导28nm密度，也没有运行任何compiler。搜索不代表检查了项目外/未挂载的PDK。

Bitcell area仅为存储单元；完整macro还含译码、sense amp、write driver、mux、控制、冗余/repair等。已知macro时应直接用macro边界面积（LEF宽×高或compiler area）及实际实例数，外围不能再加一遍。standard-cell/FF array则应按实际映射cell及端口逻辑计费，不能套SRAM bitcell单价。

原始 [scenarios.json](/data1/gzh/EC/check/area_eval/config/scenarios.json:14) 只给0.40和packing1.25，没有说明0.40的物理来源、外围是否已含，或1.25如何分摊。R2未另加periphery金额，也未加旧15%interface margin，因此**没有已证实的外围重复收费**；但0.40若本来代表完整macro有效单位面积，1.25就会构成第二次加成。不能把这个“若”当成事实，故并列两种解释：

- R2解释：`A(rho)=0.07933695+818176×rho×1.25/1e6`；1.25为一次性未标定的packing/外围余量，不再另加外围。
- 已含外围的有效密度解释：`A(rho_eff)=0.07933695+0.818176×rho_eff`；不再乘1.25。
- 0.127仅为用户指定理论bitcell参考，未作独立工艺验证；即使乘1.25也不证明足以组成真实macro。0.20/0.30/0.40同样只是敏感性点。

| 输入μm²/bit | 再乘1.25：mm² | ÷5.04参考% | 已含外围不再乘：mm² | ÷5.04参考% |
|---|---:|---:|---:|---:|
| 0.127（仅理论） | 0.20922239 | 4.15 | 0.18324530 | 3.64 |
| 0.20 | 0.28388095 | 5.63 | 0.24297215 | 4.82 |
| 0.30 | 0.38615295 | 7.66 | 0.32478975 | 6.44 |
| 0.40 | 0.48842495 | 9.69 | 0.40660735 | 8.07 |

![SRAM sensitivity](/data1/gzh/EC/check/area_eval/revisions/r3-area-audit-20261113/figures/sram_sensitivity.png)

**83.7566%的原预算是RAM面积假设**（0.409088mm²），其余16.2434%是generic逻辑换算（0.07933695mm²）；换算成原5.04分母分别贡献8.1168和1.5741个百分点，均不是已测量的真实净增量。这不是“83.76%被高估”。若0.40已经是完整macro密度，取消额外1.25会减少0.0818176mm²、即旧参考归一化的1.6234个百分点，预算变为0.40660735mm²/8.0676%；当前没有证据确认应作此扣减。

## 5. 资源复用和净增量

新增/复用/替换/潜在重复/遗漏完整清单：[resource_ledger.csv](/data1/gzh/EC/check/area_eval/revisions/r3-area-audit-20261113/results/resource_ledger.csv)。PEEK checkpoint、LSL payload、普通Cache/Tag均未在原增量重复收费。冻结EC的SW256、SVB、contentSeq32、receipt已存在，禁止在它们上面重复叠加同义资源；但冻结EC本身已经包含PAL/EC机制，不能把这些都划给PEEK然后作为PAL−PEEK减项。

可量化的**结构重叠参考**：若只是给冻结EC新增恢复标记，并证明复用原contentSeq32和exact-key receipt1，则16,896行的33位共557,568bit不用再分配，按原密度的代理金额为0.278784mm²；再不增加一份SW原型，少0.0008176mm²，剩余0.20882335mm²。该数字保留原所有其他逻辑计数，不是重新综合后面积；它依赖身份/receipt接口能够共享，更换了比较基线，**不是PAL−PEEK、不是可以报告的4%左右开销，未应用到主结果**。Epoch/CurGen等未删，LSL描述符整块也没有因“看起来可能不需要”而扣除。被替换控制逻辑面积没有同配置cell/macro证据，因此主模型的已应用复用/替换扣减为0。

## 6. Core-only / Full SoC / Incremental 三种口径

PEEK论文 [Micro26_PEEK.txt](/data1/gzh/EC/check/area_eval/evidence/Micro26_PEEK.txt:869) 给出3.96、0.27，和为5.04mm²；MEEK参考3.89+4×0.26=4.93mm²，所以(5.04−4.93)/4.93=2.2312%。这是两个论文核心实现的对比，不是约束PAL估计上限，不能把2.23%与9.69%直接相加、相减或类比其系统边界。

| 统计边界 | 本模型可算量 | 参考除法 | 严格统一配置/工艺开销 |
|---|---|---|---|
| Core-local | L1组、1个preserve、1个visibility、4个reclaim、SW：0.03029170mm² | 0.6010% | 未知；PEEK具体macro边界及相同网表无证据 |
| Core-attributed，若全把中央恢复归核 | 再加EVT/context/rollback，合计0.10339805mm² | 2.0515% | 仅分摊方案，不是实际core-only结果 |
| L2相关预算 | L2组+下层preserve/visibility：0.38502690mm² | 不除核心面积 | 不属于core-only分子 |
| Full SoC | 共同L1/L2 Data/Tag、macro、互连、控制+各自保护 | 无可用分母 | **无法计算** |
| Incremental Hardware | 相同配置PAL新/改逻辑−PEEK被替换逻辑，已有只计一次 | 无完整同边界P及净差值 | **无法计算** |

中央EVT/context/rollback小计0.07310635mm²，分摊未由真实集成hierarchy确定。两个core参考数不是误差上下界。无论选哪个分摊，9.69%都不是core-only，因其分子仍含L2。如果未来确认5.04完全不含L2且为相同配置，Full SoC公式才可写Δ/(5.04+L2+interconnect+other)；当前连L1/macro包含范围也不完全确定，不填造一个L2数字。R3所有严格百分比字段均留空。

## 7. 修订模块明细和建议值

| 模块 | R2 / R3主预算mm² | 占主预算% | 已证明可扣的PEEK重叠 |
|---|---:|---:|---:|
| L1 Version Metadata | 0.01271890 | 2.60 | 0 |
| L2 Version Metadata | 0.38378510 | 78.58 | 0 |
| Version Preservation | 0.00214620 | 0.44 | 0 |
| Visibility Control | 0.00115500 | 0.24 | 0 |
| Early LSL Reclamation | 0.01551340 | 3.18 | 0 |
| EVT | 0.04945290 | 10.12 | 0 |
| Rollback Controller | 0.00034930 | 0.07 | 0 |
| Recovery Context Storage | 0.02330415 | 4.77 | 0 |
| **合计** | **0.48842495** | **100.00** | **0** |

0表示没有可依据同配置PEEK边界应用的扣减，不表示没有复用可能。CSV包含每模块两种密度解释的全部敏感性列。原0.4884不是计量单位算错，也不是已证明metadata重复，而是高度依赖SRAM假设且参照边界不统一。

**证据允许的建议：保留0.4884mm²作为未校准的条件设计预算；在原packing解释下，0.20–0.40敏感性为0.2839–0.4884mm²。** 若密度参数被定义为已含外围的完整macro有效密度，对应0.2430–0.4066mm²。这两组不是可信区间，不能以0.30中点或最低值替换“Typical”声称更准确。尚不能将9.69%的某几个百分点认定为真实过高；可以确定的只有该数的公式组成、潜在25%RAM加成效应以及分子分母不一致。

## 8. 可写论文的证据区分

- **已有证据**：R2独立generic资源计数、冻结源码/生成物字段、RAM位数、原预算算术；PEEK论文报告其28nm核心面积。
- **分析假设**：所有PAL mm²、SRAM单位面积及packing、NAND2 GE单价、dense46-bit设计和context/EVT/descriptor规模、本文结构复用代理值。
- **没有证据**：PAL/PEEK同配置28nm映射面积、适用SRAM macro面积与外围分解、实际替换cell节省、严格core-only或FullSoC净开销。

更新LaTeX：[hardware_overheads.tex](/data1/gzh/EC/check/area_eval/revisions/r3-area-audit-20261113/latex/hardware_overheads.tex)；表：[area_models.tex](/data1/gzh/EC/check/area_eval/revisions/r3-area-audit-20261113/latex/area_models.tex)。本轮仅修订估算表述，没有开展新的硬件工作。
