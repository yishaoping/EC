# 完整 EC FireSim FPGA：结构与可实现性判断

更新：2026-11-12T21:45:13.177988+08:00（北京时间）。用户截止日期 2026-11-18，未指定时刻。

**当前完整 EC 仍 NOT FIT，没有完整 EC 认证 bitstream，也没有八项完整 EC FPGA Slowdown。当前已验证的实现无法上板；截至本报告，没有足以证明能在 11 月 18 日前完成的实现方案。未来结构方案仍可验证，不能用正在运行或局部 PASS 代替这一判断。**

## 真实面积与缺口

唯一功能基线 `8491167d84b6d9521b151a743673c1516926a1f8`。当前 owner-MCRams 使用派生目标 `3656aec4`，完整生成 host post-opt **2,420,482 LUT / 1,303,680**，超出 **1,116,802 LUT**。该结果尚不包含 U280 shell；0 black boxes，1,696,013 FF、80,990 CARRY8、192 DSP、898.5 BRAM、0 URAM。

下面是不重复计数的分区，合计精确等于 2,420,482。不能将父层级与其子层级相加。

| 分区 | LUT | host 占比 |
|---|---:|---:|
| 地址统计 PackageAddressStats | 881,587 | 36.42% |
| 三处 barrier 统计 | 187,696 | 7.75% |
| 其余 DCache | 475,702 | 19.65% |
| BOOM domain 其余部分 | 272,148 | 11.24% |
| 四个完整 checker domain | 210,766 | 8.71% |
| L2 wrapper 其余部分 | 125,879 | 5.20% |
| DigitalTop 其余部分 | 125,611 | 5.19% |
| DigitalTop 外 host/bridge | 141,093 | 5.83% |

直接证据：[disjoint-lut-accounting.json](disjoint-lut-accounting.json)，原始报告及 SHA 绑定在该 JSON。层级计数是映射后的逻辑归属，并非每个模块独立综合的面积。

**即使假设地址统计和全部 barrier 统计面积都降为零，host 仍有 1,351,199 LUT，超容量 47,519，且尚未计 shell。** 因而只优化一个地址模块不可能消除当前全部缺口；必须同时降低其余 DCache/通信/其他模块成本。当前 host 至少须减少约 46.14%；整机还需 shell 及实际物理余量。已完成 e0 整机同一构建 DUT→shell post-opt 为 2,705,170→2,789,012（增加 83,842）；这仅说明 shell 成本不可忽略，不能把另一个版本的差值当新版本准确面积。

## 本轮真正执行的工作

1. 原 SVB 认证 bitstream、上板收据和实际应用 replay 全部保留。停止给无人值守优化器分配新的 SVB 补测/物理修复，既有健康任务未被发信号、重启或改输入。独立 CPU 会话不干预。
2. 新增并实际启动完整 barrier 存储候选验证与成对 **GoldenGate host** 面积服务 `ec-opt4-barrier-fullmodule-host-pair-r2-20261112.service`，CPU218–219、64GiB 上限。实际完整 256-slot 模块 8,192 周期、263 个输出（7公共输出+256个完整161bit虚拟bucket视图）正例 PASS；真实 candidate `seen` 寄存器故障注入在 cycle1000 被精确拒绝。包含正常 reset、resetStats、同槽累积、立即完成、碰撞、resolve/reallocate、64位随机时间戳激励（未宣称覆盖所有计数溢出状态）。此为有限逐周期对照，不是完整系统形式等价或 host 运行通过。
3. 同一服务在正/负例通过后串行生成 Reference 和 Candidate 的真实 GoldenGate host 并综合。Reference 当前实测 **83,888 LUT / 44,457 FF / 3,016 CARRY8 /16 DSP /0 BRAM**。**Candidate完整host实测158,516 LUT /131,077 FF /3,013 CARRY8 /16 DSP /2.5 BRAM，反而增加74,628 LUT、86,620 FF，已经拒绝整合。** 两边完整报告/DCP/RTL的SHA全部复核通过。256个静态读端口和FAME通道/输出保存开销抵消了单writer RAM收益；不得重复同结构或把周期PASS当作面积可行。r1 首次尝试因 Chisel proof 文件命名期望不符自然退出，源码编译/展开成功；r2 仅纠正 proof 产物检查，失败证据保留，未重复或重启活 CAD。
4. 保留既有 packed 完整地址模块 Reference→Candidate 唯一面积任务及其 6,144 周期/5,684输出/真实寄存器变异对照结果。本任务测量的是完整 target 模块，不能直接当整个生成 host 收益。
5. 已将现有独立无人值守监督器的可持久化工作指令收敛为完整 EC FPGA P0，移除当前 prompt 中互相冲突的历史 SVB/CPU P0（原文已归档）。既有优化轮次实际接续完整80-source、四粒度、256-slot 地址直方图 FAME5 时间复用，先验证2/4模型 token 支持，再做完整尺寸的同 harness host 面积，不新建第二优化器或子代理。新增结构没有面积结论。
6. 复核并绑定两个既有真实结构测量：reservation RegVec→Mem 局部 **108,308→4,565 LUT（−103,743）**；installed-image RegVec→Mem 局部 **22,415→955 LUT（−21,460）**。它们尚未通过当前完整 DCache/host 组合验证，不能直接从 2,420,482 相减。slot-epoch 静态候选实际增加8,003 LUT，明确排除。见 [reusable-structural-candidates.json](reusable-structural-candidates.json)。
7. 真实 Vivado 支持检查已完成：65位加法实际2DSP48E2、0LUT、0FF，AREG/BREG/CREG/MREG/PREG全部0。已实际启动 `ec-opt4-address-dsp-fullmodule-pair-r1-20261112.service`，CPU220–221/64GiB，提取当前完整生成host中的60MB实际地址模块，对全部3,072个现有宽加法节点仅添加USE_DSP属性；删除属性后RTL逐字一致，没有新增目标状态或周期。完整Candidate→Reference成对默认面积综合串行，尚无收益数字。单加法器支持结果不外推完整模块或FIT。

详细新任务产物：`../../build-logs/Opt4-barrier-fullmodule-host-pair-r2-20261112/`。所有 production source、原始整机输入和物理约束未被本轮修改。

## 哪些结构仍值得验证

- **时间复用存储和算术，令额外步骤只消耗 host cycles。** 必须以 FireSim token/target clock enable 固定目标周期：不能加目标 pipeline、改变事件可见周期、漏掉同周期多项更新、缩窄计数、删除5120个地址bucket观察或 checker/rollback。FAME5 已存在于安装源码，但只支持一个被选择的 module type，并有2次幂线程限制；不能仅开配置就认为任意巨大模块已被序列化。
- **真正减少物理端口。** 已拒绝的地址 RAM 258R/256W bank 实测57,148→117,874 LUT并随后生成堆耗尽。它证明高端口通道和复用开销足以抵消 RAM 收益；只加 Java heap 不能改善结构。新的 barrier 方案把 payload 改为单 writer，独立 valid/sequence-initialized mask 保留 resolve 后 seq 和无效 count/request=0。
- **剩余 DCache 独立结构组合。** 即使统计块优化很成功，仍需利用 reservation/installed-image 等尚未兑现的结构，以及按实际端口/CDC语义审计其余宽存储。已有 owner-MCRams 节省已包含在当前 host 数字中，绝不重复记账。
- 当前 BRAM 尚余1,117.5 tile，URAM960未用，DSP尚余8,832；不是存储位数总量已经耗尽。将状态映射到这些硬块并降低大量 mux/算术/通道开销有物理动机，但收益和时序均须实测。

这些是可实做的结构方向，**尚无已验证组合足以翻转 FIT**。

## 21-only 兼容硬件与 checkpoint 路径

只读检查 `0000:21:00.0` 的 PCIe身份和驱动，以及当前 workspace/CAD/checkpoint 产物树；未访问另一板卡、JTAG、BAR、编程、重置、驱动解绑或全局 PCIe。

库存共391个DCP（包含 IP/中间/重复checkpoint，绝非391个完整实现）和3个bit文件。两个bit路径是已知Native构建的重复副本，另一个是已经认证上板的SVB组件。当前 `C4-selected-certified-build.json` 不存在。完整目录和边界见 [compatible-artifact-inventory.json](compatible-artifact-inventory.json)。

- Native/SVB 可复用 shell/IP/约束加载与认证流程；硬件功能不等于完整 EC，不能改名用作 Slowdown。
- owner-MCRams postopt.dcp 保存完整生成 host，但它是真实 NOT FIT，不能靠直接恢复 route 跨越器件容量。
- e0 最新完整 shell postopt2,789,012 LUT明确NOTFIT。8d独立DUT综合保留，其当前运行状态没有新的FIT证据。
- 同卡上的FAME5/专用多周期模型是可验证的软件实现路径；多板分区需其他板卡，本次不执行。没有发现能直接加载、功能等于8491167d且认证过的完整EC checkpoint。

## 截止日前的判断与自动接续

完整 owner-MCRams host 综合/postopt这一次实际用了32,344.9秒，约9小时。新结构还需要源码/完整周期/ABI验证、完整host容量、shell链接、布局布线、全时钟setup/hold/DRC/bitstream、认证和真实应用。容量通过不代表可布线或时序通过。八项首轮还需要各自真实运行时间、正确性及同输入Native分母；现阶段没有这些完整EC FPGA结果。

**技术判断：按当前已经验证的实现，不能完成完整上板；11月18日前是否能靠新结构完成尚未得到证据支持，交付风险高，不能承诺。** 六天允许继续做结构验证和CAD，但不能将剩余时间本身当作可实现性。没有替代的现成完整EC镜像或其他已授权板卡来兜底。

无人值守继续：成对实测→实质收益与组合/周期门→新完整host；NOTFIT保留报告、重排真实大模块、继续结构优化与重建；FIT立即接原shell/physical/certification/21-only runtime。已存在的 `ec-opt4-fpga-priority-handoff-r1.service` 保留，八项按blackscholes、fluidanimate、bodytrack、freqmine、swaptions、ferret、dedup、streamcluster优先，各先完成一轮，失败留证并跳过。任何派生版本必须绑定自己的RTL、driver、ABI、bitstream和收据，不冒用冻结baseline身份。


更新：DSP完整模块任务的输入/安装绑定见 `../../build-logs/Opt4-address-dsp-fullmodule-pair-r1-20261112/state.json` 及 candidate inputs.json。barrier完整host面积已完成并明确退化；DSP完整地址模块面积和真实物理时序仍为待验证项。

最新实测负例：[barrier-pair-rejection.json](barrier-pair-rejection.json)。完整EC缺口没有因此减少。


## 吞吐也约束结构选择

已只读复核八项准备好的simmedium Native FPGA参考，每项三次、hash匹配。这些分母不能代替EC样本。Freqmine现有Native ROI约893.6亿cycles；八项均值合计约1215亿cycles。若假设host40MHz且有效FMR256，按这些Native周期量级单Freqmine约159小时，八项约216小时，尚未计EC额外周期/启动/排空。这是吞吐规划情景，不是EC实测、预测或下界。

因此，不能只求LUT下降而把全部256桶串行化。后续优先16个相同bank×每bank16个并行桶，或32×8，再共享bank计算；总目标桶数仍256、目标周期不变，线程数16/32也符合既有FAME5单module-type/2次幂限制。保留已启动的不可变原型，不抢占。场景和边界见[throughput-structure-planning.json](throughput-structure-planning.json)。
