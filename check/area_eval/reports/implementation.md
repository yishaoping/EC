# PALIMPSEST 实现、配置与证据边界

本次以 `check/source/chipyard` 和 `check/build/b3_20261023_141155_3qge7ayp` 为基线，新增内容全部放在 `check/area_eval`。原有硬件源码、配置、生成 RTL、实验数据均未修改。没有运行完整 Chipyard 编译、综合、PARSEC 或 FPGA 任务。

## 版本与可恢复基线

- EC Git HEAD：`75d41676a0f988946f416a56d198f31f5c464714`。
- check Chipyard HEAD：`b3d7adddd1e2d2cf428dd933529de878226420cd`。构建 manifest 中记录同一 commit，配置为 `chipyard.v1Config`，见 `../build/b3_20261023_141155_3qge7ayp/manifest.json:6`、`:18`。
- 修改前 Git 状态保存在 `../baseline/git-status-before.txt`；其中已有未跟踪实验目录和 Vivado 日志，本次不覆盖。
- 870 个原始 Scala/配置/论文文件的 SHA256 在 `../baseline/manifest.json`。生成模块和 collateral 哈希在 `../baseline/generated-sha256.json`。`scripts/audit_baseline.py` 会重新校验。
- 新增 RTL 是独立参数化原型，不在原有 Chipyard 实例树内；原有 `v1Config` 仿真结果不会因这些文件自动获得恢复能力。

以下路径以 `/data1/gzh/EC` 为根。为简洁，`S=check/source/chipyard/generators`，`G=check/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config`。

## 实际基础配置

| 参数 | check 基线 | 依据 |
|---|---|---|
| 主核 | 1×3-wide BOOM；fetch8、decode3；ROB96、IQ16+32+24=72、LDQ/STQ24/24 | `S/chipyard/src/main/scala/config/RocketConfigs.scala:9`、`:25`；`S/boom/src/main/scala/common/config-mixins.scala:177` |
| 主核 L1I/D | 各32 KiB、8-way、64-set；L1D MSHR4 | 同上 LargeBoom mixin；`G/*.dts:15`；`G/*.mems.conf:3` |
| Checker | 4×Rocket；D4 KiB/2-way；I32 KiB/8-way | `S/rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala:5`；`S/rocket-chip/src/main/scala/subsystem/Configs.scala:210`、`:249`、`:257`；`G/*.dts:45` |
| L2 | 512 KiB、8-way、1024-set、1 bank、MSHR7 | `G/*.dts:186`；`G/*.l2.json:1`；`G/*.mems.conf:1` |
| Cache line | 64 B | DTS 的 `cache-block-size`、`G/*.l2.json:1` |
| LSL | 每 checker 两个255×130-bit FIFO RAM；510条；66,300 bit | `S/rocket-chip/src/main/scala/rocket/RocketCore.scala:817`；`S/rocket-chip/src/main/scala/r/R_LSL.scala:63`；`G/gen-collateral/R_LSL.sv:409`、`:420`；`mem_combMem_0.sv:87` |
| 时钟 | 配置目标主核200 MHz、Checker100 MHz；非 STA 结果 | `S/chipyard/src/main/scala/config/RocketConfigs.scala:10`；`G/*freq-summary` |
| 仿真内存地址空间 | 256 MiB | `G/*.dts` 的 memory 节点；不由此推断 DRAM 工艺/面积 |

`results/baseline_inventory.json` 对实际生成实例树逐个计数，共3570个模块实例、4个R_LSL。编译器分离的 SRAM 接口计6,449,152 bit；可识别的生成内联数组另计418,712 bit。这不是总寄存器统计，也不是已映射宏面积。LSL 数据RAM全系统8个实例共265,200 bit。

LSL 的4 KiB仅近似数据字段口径：510×64/8=4,080 B；地址+数据=8,160 B；加类型位=8,287.5 B/核。CSR/RoCC FIFO每核另有4×11×64=2,816 bit及控制/暂存寄存器，均属原有结构，不计PALIMPSEST新增。

PEEK Table 2是4-wide/ROB128/IQ96/LSQ32，Checker2 GHz，L1I/D4-way。最新 `DAC_2027_EC.pdf` Table I则已写成ROB42/IQ72/LSQ16、L1D2-way、L2 1 MiB/16-way。两份论文都不能替代本次 `check` 的生成配置。面积分析保持check原有数据阵列与核心规模；不会把容量变化计作恢复机制开销。

## 模块映射与状态

`IMPLEMENTED`仅表示独立模块实现、可综合并完成基本测试；体系结构端到端集成另列。`PARTIAL`不表示已实现完整恢复系统。

| Module | Existing RTL | Required Changes | Implementation Status | Source Location |
|---|---|---|---|---|
| BOOM/Rocket/Cache数据和Tag阵列 | 已实例化 | 保持容量、修改元数据/控制接口 | 原有；Chipyard连接PARTIAL | 上述配置；`S/boom/src/main/scala/lsu/dcache.scala:24`；`S/sifive-cache/design/craft/inclusivecache/src/Directory.scala:27`、`:65` |
| Forwarding Fabric | GH_BUF、GHT过滤调度、GHM多组AsyncQueue | 扩展Seq/Epoch/事务身份；保留原有通路 | 原有；新sideband ESTIMATED | `S/boom/src/main/scala/trans/GH_BUF.scala:72`；`S/rocket-chip/src/main/scala/guardiancouncil/GHT.scala:109`；`GHM.scala` 的 `u_data_cdc/u_arfs_cdc` 实例 |
| LSL | FIFO消费出队，非按完成段乱序释放 | 段描述符、完成匹配、释放握手及分配器 | 控制原语IMPLEMENTED；原FIFO分配器改造PARTIAL | `S/rocket-chip/src/main/scala/r/R_LSL.scala:119`；新增`rtl/palimpsest.sv`的`pal_lsl_reclaim` |
| PEEK Checkpoint | 主核R_RSU；Checker R_RSUSL的ARF/FARF及上下文快照 | 增加段起点上下文保留，接入主核恢复 | 原有快照复用；独立context RAM IMPLEMENTED；完整主核恢复PARTIAL | `S/boom/src/main/scala/exu/core.scala:2018`；`S/rocket-chip/src/main/scala/r/R_RSU.scala:60`；`R_RSUSL.scala:81`；`pal_context_store` |
| Comparator | Checker顺序比较ARF/FARF/CSR，报告差异 | 将错误绑定Seq/Epoch并触发恢复 | 原有；恢复连接PARTIAL | `S/rocket-chip/src/main/scala/r/R_RSUSL.scala:308`；`rocket/CSR.scala:539` |
| CSR、上下文切换 | CSR shadow、RSU、privilege切换已存在 | 接入恢复控制，确认全部必要CSR | 原有；完整恢复PARTIAL | `rocket/CSR.scala:539`、`:540`；`r/R_RSUSL.scala:208`；`rocket/Instructions.scala:1567` |
| Scheduling Engine | GHT_SE、R_IC，按Checker busy/计数调度 | 实际生成段Seq，早关段请求，结果代际匹配 | 原有；新连接PARTIAL | `r/R_IC.scala:87`、`:157`；该版`checker_segment_id`在`:117`、`:121`赋0，不构成真实段序列 |
| Verification Bitmap / SW | 未找到全局成功前缀SW；core_bitmap是路由位图 | 有限窗口、同Epoch PASS、连续推进 | 独立IMPLEMENTED；系统连接PARTIAL | `r/R_IC.scala:385`；新增`pal_safe_watermark` |
| Cache Version Metadata | DirectoryEntry只有dirty/state/clients/tag；主核Cache无版本字段 | Seq/Epoch/Cur/CurGen/preserved，可选owner | 独立RAM IMPLEMENTED；Cache接入PARTIAL | `Directory.scala:27`；新增`pal_metadata_ram` |
| Version Lookup / Store | 既有tag/permission可复用，无历史选择 | 当前代际匹配、同段原位写、新段分配、max Seq历史选择 | 独立IMPLEMENTED；跨级合并及数据读取PARTIAL | `pal_version_select`、`pal_store_policy` |
| Preserve-before-reuse | 既有WB FSM和buffer可复用 | 锁源、请求/ACK身份、背压、取消排空 | 独立单保留槽IMPLEMENTED；多MSHR/TileLink连接PARTIAL | `S/boom/src/main/scala/lsu/dcache.scala:37`、`:46`；`pal_preserve` |
| Visibility Barrier | 既有coherence evict_safe/grant_safe不等于验证SW | 自身unsafe可访问、跨核和DRAM仅safe | 独立判定IMPLEMENTED；数据/权限通道PARTIAL | `pal_visibility`；`S/sifive-cache/design/craft/inclusivecache/src/SourceC.scala:76`不可作为SW证据 |
| EVT | 未找到 | 存活epoch区间、截断、无Cache扫描 | 独立IMPLEMENTED；安全Epoch回收PARTIAL | `pal_evt` |
| Rollback Controller / GlobalCurGen | 未找到 | halt/flush/EVT/restore/restart协调 | 独立IMPLEMENTED；主核/Cache连接PARTIAL | `pal_rollback` |
| Context retention RAM | 无已证明满足多段恢复保留的专用主核Context Memory | 8份完整上下文，索引和原子提交 | 独立IMPLEMENTED；完整ISA状态覆盖PARTIAL | `pal_context_store` |
| 新增行缓冲、宽接口、记录级free bitmap | 未连接 | 可复用现有WB buffer；需定吞吐与分配策略 | ESTIMATED | `config/scenarios.json`；面积表单独计接口预留 |
| 完整PALIMPSEST SoC及可发表ASIC面积 | 当前未具备匹配集成 | 完成上述连接、宏映射与STA | UNSUPPORTED（当前评估产物） | 不把独立模块综合相加称为全系统综合 |

## 参数推导与实现约束

PALIMPSEST Section IV-A明确要求Seq、Epoch、Cur、CurGen、preservation metadata，IV-B多主核要求owner。原文没有给出位宽。`config/scenarios.json`故将其作为设计场景，绝不声称来自论文：

- Typical：Seq16、Epoch4、CurGen8、Cur1、preserved1=30 bit/line；仅1个生产主核，因此owner逻辑为0 bit。独立可见性测试保留1-bit owner端口，便于扩展。
- 不复制既有cache valid/dirty/coherence/tag。Preserved是安全重用确认，不能替代EVT历史有效性，也不能把“已验证”与“已进入SW”混为一谈。
- L1只统计主核可写D-cache。L1I、Checker cache不自动版本化；自修改代码和I-cache恢复失效需集成设计。
- 无活动身份回绕：Seq最大65535；EVT16槽用满后停止分配；CurGen255后拒绝新的恢复；preserve事务ID255后拒绝新请求。外部需证明全体Cache/CDC/在途事务无旧引用，再回收/扩宽身份。有限容量下停止不构成无限运行前进性证明。
- EVT所有存活epoch同时按恢复边界截断，新epoch从边界开始。恢复查询选存活`Seq<n`最大者，正常读只看合法CurGen；不得仅按SW丢弃尚未验证但仍存活的A7。
- 多级恢复需要先检查L1、L2候选，再选择最大Seq；若都不存在才落到已证明安全的DRAM基线。当前selector只完成单级候选选择，未把单级miss冒充安全DRAM回退。
- 当前preserve实现每级1个槽，源数据保持在原cache way。匹配ACK必须带version key、transaction ID及preserve/WB类别。已发请求被取消后等待匹配终止ACK，不提前释放。所有WB串行可满足同址顺序，但不能据此声称拥有高吞吐多地址WB实现；obsolete unissued WB抑制尚未集成。
- early dispatch输出是阻塞通知，不能代替R_IC真正关闭/派发当前段。必须将检查输入、检查点、结果CDC和保留请求排空顺序接通。64-byte定时器flag隔离属于软件布局，不增设硬件Data Array。
- LSL回收需“PASS且输入已消费”；release有效时保持直到ready。段可乱序完成，不依赖全局SW。现有双FIFO只有顺序head/tail；独立描述符尚不能自动让FIFO中间空洞重新分配，因此系统级Early Reclamation仍为PARTIAL。
- 新context保存32个整数+32个浮点+13个shadow CSR+PC+FCSR+privilege/mode=80个64-bit word（5,120 bit/份），含x0/控制word对齐冗余。13来自`Instructions.scala:1567`的现有CSR列表，不代表完整恢复架构只需这13个CSR；satp、trap状态、精确中断/特权状态及ISA完整覆盖仍需审计。原有R_RSU单快照不等于长期多段恢复RAM。

## 验证与综合

命令在`check/area_eval`运行，脚本设置60秒子步骤超时，不调用完整SoC：

```sh
python3 scripts/audit_baseline.py
python3 scripts/run_tests.py
python3 scripts/synthesize_baseline.py
python3 scripts/synthesize.py
python3 scripts/estimate_area.py
```

- Verilator lint通过；Icarus状态测试覆盖元数据mask、段内/跨段store、容量不足、精确ACK/错代ACK/取消排空、LSL容量与乱序释放、Epoch多次截断及耗尽、SW重复结果和环索引、恢复各握手、context部分不可见/原子提交/错误身份拒绝。
- Python独立oracle：2500组版本选择+2500组可见性、4200个EVT身份判断+900周期SW比对。随机种子固定，生成向量及执行日志保存在results；`results/tests.json`绑定被测RTL SHA256。
- 没有用“编译通过”替代主核端到端恢复验证。未测故障覆盖、完整rollback、体系结构状态一致性、死锁自由或PARSEC性能。
- `results/synthesis/*/{collect.ys,collect.log,gates.ys,gates.log,result.json}`包含实际Yosys命令及统计。Cache sidecar/context大RAM保持抽象宏并单报位数；EVT、LSL描述符、context标签显式映射为寄存器，不能按理想SRAM漏计多端口/复位逻辑。
- 没有真实SRAM compiler/macro或时序库映射，故Cell Area、组合/时序mm²和关键路径ns均无实测值。Generic GE是声明权重的NAND2等效模型，不是Yosys直接给出的28nm面积。

关键文件的完整路径和精确行号见[source_evidence.md](source_evidence.md)。
