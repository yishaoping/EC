# PALIMPSEST 硬件开销评估结果

**最可信的结果是RTL结构与generic资源统计，尚无可发表的28nm实际面积。** 对`check`基线、每line30-bit元数据、8份恢复上下文、每级单lookup/store lane的独立模块，面积敏感性模型的Typical约为 **0.19 mm²**，Low/High约 **0.09/0.45 mm²**。相对PEEK论文5.04 mm²核心合计的参考归一化约 **3.8%**，范围约 **1.7–9.0%**。这些百分比不等于当前项目的同配置PALIMPSEST/PEEK综合差值。

原有代码未改，独立实现与单元测试位于`rtl/`、`tests/`。完整Chipyard连接、SRAM宏映射、主核精确恢复、身份安全回收和死锁自由仍未完成。**相对未保护架构的总开销目前无法可靠给出数值**，因为3.89 mm²是User-only MEEK，不是未保护BOOM；3.96 mm²是PEEK内BOOM，不能冒充无保护基线。

## 论文依据及适用边界

- `DOC/Ref/Micro26_PEEK.pdf` Table 2、Table 3、§7.6。提取文本`evidence/Micro26_PEEK.txt:646`、`:853`、`:939`。Table 3确认TSMC28nm/DC2020.12；BOOM3.96、Rocket0.27 mm²，核心合计3.96+4×0.27=5.04 mm²。User-only MEEK是3.89/0.26，属于受保护架构。27.3%是四Checker相对3.96的增量，不是与本项目实测未保护主核之比。
- `DOC/Ref/DAC_2027_EC.pdf` §III、§IV-A–E；对应提取文本`:281`、`:327`、`:301`、`:330`、`:387`、`:370`。Preserve-before-reuse、safe-only传播、per-address WB串行与身份匹配、EVT区间、CurGen逻辑失效和按需恢复均直接依据原文。§V-E当前只有标题，未给可核实面积数值，见文本`:532`。
- PEEK Table2（4-wide/ROB128、L1I/D4-way）与check（3-wide/ROB96、L1I/D8-way）不同；最新PALIMPSEST TableI（ROB42、L2 1MiB/16-way）也与check不同。本结果固定check缓存几何，不将上述容量变化算进PALIMPSEST增量。
- 论文没有给出Seq/Epoch/CurGen位宽、EVT深度、上下文份数、SRAM宏组织、ECC扩展或恢复pipeline接口时序。所有这类量明确存放在`config/scenarios.json`作为设计场景。

## 硬件开销明细（固定Typical架构参数）

Added Storage包括新增大RAM位数与综合后DFF数；保留原有PEEK LSL/快照/转发fabric，不重复计入。

| Component | Added Storage (bits) | Added Logic (generic GE, excl. RAM) | Area model Low/Typical/High (mm²) | Typical / PEEK参考值 | Evidence |
|---|---:|---:|---:|---:|---|
| L1 Version Metadata | 15,360 | 2,763.5 | 0.0045 / 0.0096 / 0.0224 | 0.191% | results/synthesis/l1_metadata/result.json x1; results/synthesis/selector_l1/result.json x1; results/synthesis/store_policy/result.json x1 |
| L2 Version Metadata | 245,760 | 2,795.5 | 0.0505 / 0.1248 / 0.3174 | 2.477% | results/synthesis/l2_metadata/result.json x1; results/synthesis/selector_l2/result.json x1; results/synthesis/store_policy/result.json x1 |
| Version Preservation | 152 | 2,429.0 | 0.0012 / 0.0017 / 0.0024 | 0.034% | results/synthesis/preserve/result.json x2 |
| Visibility Barrier | 0 | 256.0 | 0.0001 / 0.0002 / 0.0003 | 0.004% | results/synthesis/visibility/result.json x2 |
| Early LSL Reclamation | 1,308 | 16,012.0 | 0.0080 / 0.0112 / 0.0160 | 0.222% | results/synthesis/reclaim/result.json x4 |
| EVT | 532 | 22,828.0 | 0.0114 / 0.0160 / 0.0228 | 0.317% | results/synthesis/evt/result.json x1 |
| Rollback Controller | 27 | 323.0 | 0.0002 / 0.0002 / 0.0003 | 0.004% | results/synthesis/rollback/result.json x1 |
| Checkpoint / Context Storage | 41,141 | 2,469.0 | 0.0094 / 0.0222 / 0.0549 | 0.441% | results/synthesis/context/result.json x1 |
| Verification Bitmap / SW | 36 | 744.5 | 0.0004 / 0.0005 / 0.0007 | 0.010% | results/synthesis/sw/result.json x1 |
| Additional Buffers / Interfaces | 1,024 | 0.0 | 0.0015 / 0.0058 / 0.0165 | 0.116% | config/scenarios.json; 未实现缓冲/接口余量 |
| Total Incremental Area model | 305,340 | 50,620.5 | 0.0872 / 0.1923 / 0.4538 | 3.816% | 独立模块模型合计，非完整系统综合 |

CSV `results/module_area.csv`进一步分开Storage、Combinational、Sequential、Buffer/Interface Area。模块实例数是拟议连接方案：1份L1/L2元数据及选择器、每级1个preserve槽/可见性判定、每Checker8个LSL描述符、全局1份EVT/SW/rollback/context。它们尚未在Chipyard中实际实例化。

新增大RAM共303,104 bit，其中metadata261,120 bit、context40,960 bit、可选2行暂存1,024 bit；DFF共2,236 bit。大RAM逻辑位数不会因multi-version而增加完整Data Array。历史版本消耗现有way，主要代价还包括有效容量下降/冲突增加，不能由面积模型替代性能验证。

新增元数据为Seq16+Epoch4+CurGen8+Cur1+preserved1=30 bit/line。L1D512line×30=15,360 bit；L2 8,192line×30=245,760 bit。相对512bit数据line为5.859%逻辑位数，**不等于Cache或系统面积增幅**。8,192line×1bit的任何额外字段会再增加8,192bit。单主核owner可省；多主核需要至少ceil(log2(Nmain))位及按owner查询SW/EVT的逻辑。

EVT为16epoch×(lo16+hi16)+16live+4current=532 DFF；8个查询端口的mux和比较器不可忽略。上下文8×80×64=40,960 bit，另有181 DFF的索引/标签/控制。每份5,120bit来自现有32ARF+32FARF+13shadowCSR+PC+FCSR+privilege/mode的64-bit对齐方案，不代表完整ISA恢复状态已证明足够。

## 综合结果与面积模型的区别

`results/synthesis/summary.json`来自真实Yosys0.60+70的proc/opt/memory/techmap/ABC统计。用固定NAND2权重转换为generic GE：DFF6、MUX3、XOR/XNOR2、AND/OR/NAND/NOR1、INV0.5、ANDNOT/ORNOT1.5。GE依赖所选等效权重；不是工艺库Cell Area，也不含布线、clock tree、scan、拥塞/STA修复面积。

大RAM在RTL收集后抽象为有读写端口的memory macro，位数、depth、width和端口数逐一记录；未将黑盒面积当零。EVT和小描述符有多端口/全体截断/复位写入需求，显式实现成DFF与组合逻辑。Macro模型包含其输出寄存器时，不再重复加输出DFF；真实宏若需要额外输出pipeline、bank、ECC和读写冲突旁路，必须重新评估。

| 实测资源项 | RAM bits | DFF bits | GE（不含RAM） | 范围 |
|---|---:|---:|---:|---|
| l1_metadata | 15,360 | 0 | 296.0 | 每个独立实例 |
| l2_metadata | 245,760 | 0 | 328.0 | 每个独立实例 |
| evt | 0 | 532 | 22,828.0 | 每个独立实例 |
| selector_l1 | 0 | 0 | 2,250.5 | 每个独立实例 |
| preserve | 0 | 76 | 1,214.5 | 每个独立实例 |
| store_policy | 0 | 0 | 217.0 | 每个独立实例 |
| visibility | 0 | 0 | 128.0 | 每个独立实例 |
| reclaim | 0 | 327 | 4,003.0 | 每个独立实例 |
| sw | 0 | 36 | 744.5 | 每个独立实例 |
| rollback | 0 | 27 | 323.0 | 每个独立实例 |
| context | 40,960 | 181 | 2,469.0 | 每个独立实例 |

基线组件也实际运行了Yosys：R_RSU在优化后有5,007寄存器bit（包括原始单快照/控制），R_LSL有66,300 RAM bit和3,747寄存器bit。后者包含原有CSR/RoCC队列/暂存/控制。这些不是PALIMPSEST增量。完整BOOM/四Checker/总线的映射综合未运行，所有系统实测面积和关键路径ns仍为UNVERIFIED。细节在`results/baseline_synthesis`；原始memory接口和实例清单在`results/baseline_inventory.json`。

环境有SMIC28 `.db`，但PATH没有可用dc_shell/lc_shell；Yosys不读取Synopsys DB，且未取得TSMC28标准单元或匹配SRAM宏。不将SMIC、TSMC或FPGA LUT数据直接互换。Vivado可用但本次未启动任何CAD任务，也未停止已有任务。

物理Low/Typical/High **保持同一套Typical字段/槽数**，只改变工程假设：

| 物理假设 | 大RAM μm²/bit | SRAM packing系数 | NAND2 μm²/GE | 额外接口逻辑余量 |
|---|---:|---:|---:|---:|
| Low | 0.20 | 1.00 | 0.50 | generic逻辑面积的5% |
| Typical | 0.40 | 1.25 | 0.70 | 15% |
| High | 0.80 | 1.60 | 1.00 | 30% |

这些密度没有当前工艺库characterization来源，只是公开、可替换的工程敏感性假设，**不是PEEK校准出的工艺参数、实测误差条或上下界保证**。PEEK只用于参考分母，未把其核心面积倒推出SRAM密度。

公式：A_storage=B_RAM×density×packing/10^6；A_comb=GE_comb×area_GE/10^6；A_seq=GE_seq×area_GE/10^6；A_interface=margin×(A_comb+A_seq)。再加可选行缓冲模型。独立逻辑模块间共享/跨级连线/时序优化未知，不能将总和称为精确SoC面积。当前接口余量也不能保证覆盖未完成的分配器、CDC、coherence、多端口与epoch回收设计。

若将全部新增RAM强制展开为FF，单计存储就至少303,104×6=1,818,624额外GE，还未计读写mux/decoder/enables；这只说明实现方式敏感，绝不是SRAM面积或完整FF实现面积上界。

## PEEK与PALIMPSEST总体比较及归一化

| Architecture | 当前check配置真实面积 | 外部参考/模型 | 可信度 |
|---|---|---|---|
| Unprotected baseline | 待综合，U | 不使用3.89或3.96冒充U | UNVERIFIED |
| PEEK | 待同配置综合，P | 论文核心合计5.04mm² | PAPER_REFERENCE，非当前硬件面积 |
| PALIMPSEST | 待集成综合，P+D | 参考5.04+模型0.19≈5.23mm² | 仅示意；未统一微架构/宏边界，不用于实测开销声明 |

A：真实PAL相对PEEK增量为100×D/P。B：真实相对未保护总体开销为100×(P+D−U)/U。C：本模型各模块贡献见下图/CSV。因为P、U未实测且原论文缓存/外围面积边界未完全说明，A/B当前都不具备可发表精确数值。

| 假设 | 模型增量mm² | 增量/PEEK论文5.04 | 增量/PEEK BOOM3.96 | 参考和模型合计mm² |
|---|---:|---:|---:|---:|
| low | 0.087 | 1.73% | 2.20% | 5.127 |
| typical | 0.192 | 3.82% | 4.86% | 5.232 |
| high | 0.454 | 9.00% | 11.46% | 5.494 |

如果仅为与原论文叙述保持可比，采用PEEK BOOM3.96作参考核心面积，Checker本身的4×0.27/3.96=27.27%；加入Typical模型后，参考表达式(1.08+0.1923)/3.96≈32.1%。**这是“相对PEEK BOOM”的反事实参考口径，绝不能标为“相对未保护架构的已测总开销”。**

Cache归一化的可验证部分：L2现有data4,194,304bit+directory172,032bit，元数据额外245,760bit，占两者合计5.628%位数。若用同一假设density/packing为原有L2 data+directory建宏代理，Typical为2.183mm²；L2版本元数据含单lookup/store逻辑模型占此代理5.72%，全PAL增量占此代理8.81%。L2控制器和宏真实面积未知，这两项仅为模型比较。

若论文5.04明确不含共享L2，可再以5.04+2.183作为**示意**分母，Typical增量约2.66%。若5.04已经含L2，则不能再加。外围面积X未知，包含外围时用D/(P+L+X)，不填虚构X；结果CSV保留空值。共享L2和SRAM宏包含/排除必须在真正的成对综合中一致。

## 主要贡献和敏感参数

Typical模型前三项：L2版本元数据约0.125mm²（约65%），Checkpoint/Context约0.022mm²（约12%），EVT约0.016mm²（约8%）。其余约15%。前两项主要是存储，EVT主要是多端口选择/比较控制。具体值随端口和宏组织而变。

1. L2 line数量与元数据字段位宽：容量翻倍时metadata位数翻倍；不能只按数据容量给固定“几百个寄存器”。
2. Epoch位宽：EVT槽数采用2^E时指数增长；目前4bit=16epoch，无回收时最多15次rollback后停机。8bit=256槽并不意味着低开销。小EVT配安全槽回收可取代全空间表，但需要引用生命周期证明。
3. 查询/写端口数、BOOM load/store银行与pipeline：当前只有每级单lookup/store资源。复制端口、并发preserve/MSHR、owner扩展、coherence sideband可显著加逻辑。
4. Context份数、需要覆盖的CSR/特权状态、是否能安全复用现有快照。不能因已有R_RSU就把长期checkpoint retention全记零。
5. SRAM macro字宽/深度、banking、masked write支持、复位与ECC。逻辑位数小不保证窄sidecar物理面积小。
6. LSL乱序空洞再分配策略、额外staging buffer及事务/Seq回绕策略。早回收本身不增加一整套LSL。

字段敏感性与物理敏感性分别报告，避免混淆。以下只是容量计算，未声称Low/High字段重新完成gate综合：

| 字段场景 | bits/line | L1新增bits | L2新增bits | EVT interval/live bits | Context payload bits |
|---|---:|---:|---:|---:|---:|
| low | 21 | 10752 | 172032 | 200 | 10240 |
| typical | 30 | 15360 | 245760 | 528 | 40960 |
| high | 58 | 29696 | 475136 | 16640 | 81920 |

## 图表、数据和复现

- `figures/incremental_modules.pdf/.svg/.png`：模块贡献，明确标为面积模型。
- `figures/system_reference_only.pdf/.svg/.png`：Unprotected未知、PEEK论文参考、Reference+model；不伪造同配置系统对比。
- `figures/cache_metadata_sensitivity.pdf/.svg/.png`：30bit/line下Cache容量影响。
- `results/module_area.csv`、`normalization.csv`、`system_comparison.csv`、`field_sensitivity.csv`、`cache_capacity_sensitivity.csv`可直接导入论文绘图流程。
- `results/synthesis`为真实generic合成统计；`results/tests.json`和`test-*.log`为测试证据。
- `reports/implementation.md`包含版本、实际配置、模块映射与每个未连接接口。新增改动文件范围仅`check/area_eval`，原有check源码保持可恢复。

从`/data1/gzh/EC/check/area_eval`执行：

```sh
python3 scripts/run_all.py
python3 scripts/report_area.py
```

脚本只读原始代码和生成RTL；测试/综合输出仅写area_eval。已有Yosys结果按RTL、参数与脚本SHA缓存；使用`scripts/synthesize.py --force`可重跑独立模块。所有子CAD步骤设60秒超时，未启动完整SoC/FPGA/PARSEC。工具路径与版本在`evidence/tools.json`。

## 达到可发表结果仍需完成

- 统一成对的未保护、PEEK、PALIMPSEST配置；至少明确BOOM宽度/ROB/IQ/LSQ、Checker数、cache容量/相联度/line/端口和SRAM边界；冻结并绑定生成RTL SHA。
- 将真实Seq/Epoch结果身份接入R_IC/GHM/Checker；连接bitmap/SW、Cache元数据、preserve/ACK、版本选择数据通路、DRAM/coherence屏障及迟到回复过滤。current key更新需原子化，历史重复tag不得被旧coherence命中逻辑误选。
- 为原双FIFO完成可重分配的LSL段/块组织，验证乱序完成的空洞是否真的可再利用；保持完整检查输入语义，不仅修改head/tail。
- 完成跨L1/L2的max Seq选择、on-demand Current重建及安全DRAM基线条件。接通主核flush、重命名/ROB/LSQ复位、PRF/ARF/CSR恢复、精确PC/特权/中断状态。
- 证明preserve/WB终止顺序、obsolete unissued传输抑制、epoch/transaction/sequence安全回收、checkpoint保留边界及压力下早派发可打断环依赖。有限表耗尽停止不能作为长期forward progress结论。
- 选定有授权的28nm工艺、相同库corner和真实SRAM compiler/macro；按相同约束做完整成对综合/STA。分别报告stdcell、所有SRAM宏、共享L2、外围、物理优化和critical path；无macro的FF实现必须另表。
- 完成端到端故障注入及架构状态差分验证，再发表恢复正确性、延迟和总体面积。当前0.19mm²只能作为明确假设的设计空间估算，不能填进“measured/synthesized area”列。
