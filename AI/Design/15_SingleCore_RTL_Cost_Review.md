# 单主核 RTL 成本与时序选择

2026-11-21。源码结构和 Stage3 通用粗综合。验证矩阵保存实际运行结果。

| 任务 | 选择与替代方案 | 实际开销与路径 |
|---|---|---|
| P2-06/P2-10 | PRF 32 路专用并行恢复改为顺序写，复用第 0 写口；SCP 在握手完成前保持。 | 每个 PRF 一个 6-bit 索引及 done，原写口增加地址/数据 MUX。33 次写（含 p0），不增加 32 个 RAM 写口；不对正常读路径增加历史搜索。 |
| P2-06/P2-07/P2-10 | Rename map/free/busy、CSR 在各自真实写边界确认，Core 汇合 owner done。 | 小型 done 寄存器与 AND；PRF 最慢的完成决定恢复延迟。没有全局固定周期计时器。 |
| P3-15/P4-06 | transaction/slot 复用现有 owner 生命周期；不拓宽 ID、不保留饱和 fatal。 | slot 和空闲 MSHR 的 next-ID 加一个跳过 0 的 MUX；LSU 完整组分配跳过尾部。合法 TL owner 未结束不重用其槽。 |
| P1-05/P3-15 | 内容 serial 限定在 (address,writer,Seq) 内，跨 Seq 重启本地 serial。 | 复用每行已有 generation；去除全局每 Store 饱和停机。受保护段内 Store 数由段长度限制，远小于 2^32。 |

| P1-02 | SW 只检查下一个 Seq 的 tagged bitmap，源端寄存 Gray。 | 去掉仅用于 +0/+1 的 256 项连续前缀组合链；bitmap 本体不增加。CDC 的 max-skew/reset/bundle 稳定仍需用户工具验证。 |
| P3-07/08 | 冷历史查询和安全发布用单索引扫描；全行在 Mem。 | data 64×512=4KiB；metadata 每项 address64+key81+valid，约 9344bit，另有索引/候选/ingress/WB 寄存器。Mem 是异步选择读形式，不能据此保证特定 SRAM 宏映射。每次扫描约 N 拍，不增加普通 hit 的历史比较器。 |
| P1-03/P3-13 | 扫描时局部淘汰 dead/同 Seq 中间值/被新 safe 替代的旧 safe。 | 重用一次选中的 metadata 比较器；不做 N² 个赢家比较，不做主动全 Cache 回收。WB 精确 owner 不参与复用。 |
| P4-09 | 单效果 journal + Core 六态边界。 | journal 保存一个地址/PC/Seq/cmd/size/operand/raw response 与 valid/replay 位；保护流量只到 IOMSHR0，其他实例捕获逻辑被参数关闭。复用设备数据通路，无外部日志 RAM。重放匹配比较位数有限；不在缓存普通 hit 路径。 |
| P3-10 | addressed baseline receipt + obsolete metadata，复用目录 read/write 队列。 | 每 L2 line 新增 1bit；v1 1MiB/64B 共有16384行，新增16384bit（2KiB）目录位。小 FSM 持锁完成一次读/写；未创建全地址发布 CAM。既有 MSHR metadata 同步带该位，并可重新规划旧命中。 |
| P4-12 | 4 项 escape 保留在64项 history内；保存锁排他信用。 | 4×64B=256B 是原4KiB中的预留，不新增data array；普通可用项降为60。信用判断复用 occupancy/held ingress/lock。 |
| P4-12/13 | 外部Release/Acquire尚未发出的A请求park（可已完成inner Probe），复用原 native-client wait 结构扩到实际 TL sources。 | 每 source 一个 FullRequest+Seq+valid，仅 metadata，无完整行数据。保留 source 一次一事务约束；代价随本配置的 source 数线性变化，不做多 Main 通用框架。 |
| P4-12 | 仅v1分出最后一way给非image-aware读数/取权限miss（Get/Acquire等）。 | 复用原data/metadata SRAM。16-way配置的普通miss可替换15-way，额外1-way用于replay取指/页表读取；没有新增Cache容量。普通命中仍查询全部ways；假设replay text/页表不由保护代码改写。 |

EVT容量维护使用现有Directory读口与way元数据选择、set/way索引、7态服务FSM、原flush/Probe/Release/ACK通道和一对held控制跨域信号。它顺序清空Cache/history，不新增line数据RAM；仅表满或Epoch/G近边界时执行，延迟按实际Probe/外存ACK决定。普通rollback仍无全Cache扫描。目录冷端新增一个metadata way选择（复用读出ways），不增加全行历史组合搜索。

Core六态I/O FSM提取为生产模块，不复制状态；新增一个effectPending状态观察向Core屏蔽异步中断、journal mismatch沿现有error/SCP通道retry。uncached AMO复用原response和terminal，增加握手顺序，无新数据缓冲。

Seq32 重基复用上述扫描和原 AsyncQueue 指针，增加 Main、bank 和每 Checker 的握手状态与同步位。每个域清除自己的 Seq 标签，原 CSR/PRF/SCP 恢复通路保持。计划重基偶尔需要清空物理目录，耗时取决于目录行数、Probe 和外存终态。具体控制见 [Seq32 CDC 规则](SingleCore_RTL_Baseline/Seq32_CDC_Rules.md)。

2026-11-22 V4 将 R_ICSL 的包空闲条件与可开始下一包的异常上下文条件分开，RocketCore共享原RSUSL/LSL/前端空闲逻辑。新增一个组合输出，不新增寄存器、比较网络、队列、存储或FSM；管理trap保留原CSR/PC/depth。SeqTransport新增的R_ICSL只属于测试top。本项尚无技术综合的增量面积/时序数据。

Yosys 对相同 fullC Stage3Harness 做修复前后对比。粗综合的通用单元从 10,328 增到 10,674，`$mem_v2` 均为 129。展开 RAM 后，通用映射的单元数从 164,034 增到 169,576，最长组合路径均为 162 级。见 [验证矩阵](SingleCore_RTL_Baseline/Verification_Matrix.md)。

Vivado 在 `xcu250-figd2104-2-e` 上对 Stage3Harness 做独立综合。5 ns 时钟约束下，表中三个版本均未满足 setup。

| 版本 | LUT | FF | BRAM | WNS | TNS |
|---|---:|---:|---:|---:|---:|
| C 准入修复前 | 21,104 | 15,893 | 7.5 | −7.526 ns | −61,922.445 ns |
| 精确 C 收据版 | 20,425 | 15,914 | 7.5 | −8.779 ns | −74,653.438 ns |
| 历史 SourceC 准入版 | 21,550 | 16,093 | 7.5 | −9.514 ns | −74,848.547 ns |

历史 SourceC 准入版最差路径从 L2 History 的 `valid_60_reg` 到 MSHR 的 `s_acquire_reg`。数据路径为 14.504 ns，包含 10.861 ns 的布线估计。该历史版本通用粗综合的层次总计为 11,309 个单元。Stage3Harness 对比跨越数个源码变更，且不实例化生产 bank 外层屏障。实际布局布线和 ASIC STA 仍待完成。见 [历史 SourceC Vivado 报告](../TMP/singlecore_rtl_20261121_171154/sourcec_synth11/timing.rpt) 和 [通用粗综合报告](../TMP/singlecore_rtl_20261121_171154/sourcec_synth11/coarse.log)。

SourceC 准入继续复用原 victim 安全条件、发布优先级和 set owner。bank 封口逻辑少一个 `barrierBlocksOuter` 位，移除到 Scheduler 的通用准入门，没有新增状态、队列或数据阵列。

本次 C 修复复用原两拍 C 队列、一份完整行暂存和目录的现有 image 字段。新增两位待查/通过状态及与目录读延迟对齐的收据位。跟踪的 C 完整行多一次低优先级目录读，过时检测只比较该地址实际收据与暂存行 key，没有扩大目录 RAM 或引入全地址 CAM。已接受外部传输继续使用原终态条件。

EVT 邮箱增加一位操作类型，复用现有 payload 同步、每域 ACK 与上下文寄存器。安装直接走 ACK 状态边界，减少一次 SVB 与 L2 的查询。上述综合数字对应 C 收据版 Stage3 夹具，夹具的 EVT 邮箱输入关闭。

缓存 AMO 与普通 Store 共用 `svbEligibleCandidate` 的整行捕获和 S3 写效应 owner。准入增加对现有 AMO 命令译码的使用。该改动在 L1 DCache，开销单独跟踪。见 [缓存 AMO 记录](../Debug/bugs/bug-palimpsest-cached-amo-predecessor.md)。

查询跨重试空窗复用 DCache 原 `recoveryMiss` 状态及候选整行寄存器，修改释放条件。BOOM 的 trap tracker 复用原有执行标记，SCP 每项增加三位，恢复时复用已有 CSR 恢复边界。这两部分在 Stage3 夹具之外。

## Checker回执与本次互锁

- P2-09/P4-05：每Checker增加1个ACK寄存器，Main增加4×8级ACK同步位；原payload/request同步与EVT context寄存器由生产receiver接管，未增加第二份EVT副本。Main只在冷mailbox路径做ACK归约，不改变正常L1 hit数据路径。
- P3-15：compact与L1已有quiesced/SVB/archive/package-owner条件汇合，不使用新的延时计数器；resident全空检查为assertion，不用全行恢复搜索。
- P3-10：publishPending增加当前SW变化检测，safe candidate准入复用已有pending标志；无新存储或CAM。它可能推迟direct safe Put，完整并发前进仍需用户运行Pressure/Baseline/Hierarchy。
- P5-04：新fixture实例化完整GHM及其生产AsyncQueue，只影响测试top，不增加v1生产配置的缓冲。

## 2026-11-22 Checker 迟到 COPY 修复

RocketCore 复用现有 package owner、EVT、R_ICSL context_idle、RSUSL core_hang_up 和 pc_special。新增普通 COPY 布尔准入、custom JLR 目标选择和复制尾拍清理条件，没有新增寄存器、队列、存储或状态机。增加候选 Seq 的存活性检查；已提交 owner 的同一 Seq 检查可供综合共享。实际比较器门数及该增量的面积、时序尚无实测结果。

2026-11-22 冷恢复与可信写修复复用 MSHR 原有 recoveryActive/recoveryData 和
Grant 首拍标志，没有新增整行寄存器、队列或 FSM。V2 移除 Main 的候选/SW 比较，改由 L2 bank 按已选 MSHR 的候选 Seq 做一次
32 位共享比较。新增一位 D 用户元数据和现有 SourceD 请求流水中的相应位，
候选身份复用 A.CacheImage 和 FullRequest.image，不增加每行标签；DCache 移除重复的整行替换 MUX 和 image MUX。
L2 复用 publishPending 延续 D 准入条件。该屏障可能延迟其他 set 的响应，
需要用并发回归检查前进性。此增量尚无综合实测；上表是明确版本的历史数据。
Hierarchy 新增 TL host、Xbar 和驱动端口只属于测试 top。

V1 Stage3 综合已实际完成（归档 stage3_synth_v1）：Yosys 通用单元 11315，mem_v2=129；Vivado xcu250 为 LUT21521、FF16041、BRAM7.5。5ns 约束下 WNS=-9.608ns、TNS=-76838.273ns，时序 FAIL。数字只覆盖 V1 L2 夹具；后续 V2 夹具结果及其证书裁剪限制见下文，不能代替整核面积或时序结论。

V2 实测 `stage3_synth_v2/result.json`：通用单元11315、mem_v2=129、LUT21521、FF16041、BRAM7.5；5ns 下 WNS=-9.608ns/TNS=-76838.273ns，时序FAIL。此夹具固定 A hint=BASE 且不协商 D 证书位，证书比较和流水位被裁剪，因此相同数字只证明该 L2 夹具回归，不能当作有效证书增量或整核面积。有效证书开销的技术映射尚未测量。

V5 的 DTLB 和共享 Rocket TLB 使用已存在的 `invalidate_refill` 门控数组写入。旧响应终结 owner 的状态路径保持原有实现。新增开销是组合写使能条件，无新增寄存器、队列、比较器或 FSM，尚无本次增量的综合面积与时序实测。

V6的I/O后置快照复用LSU已有ioIssueReady输出，替换Core接入的全STQ空谓词。
无新增状态、寄存器、队列、比较器或FSM；物理owner和已提交store的排空逻辑
已用于I/O发射前屏障。本项增量尚无技术综合数据，不能使用历史Stage3结果代替。

最终 restart 增加现有 quiesced/checkpointReady 门控。完整 Core 的 RSU 排空
判定复用已有 snapshot_rsu_prev 寄存器，不新建 owner 存储；缓存和 LSU 仍实时
检查。旧 RSU busy 包括组合 snapshot offer，不能直接反馈到 restart/SCP release。
新增开销仅为已有一位条件的组合连接，无新增队列、RAM 或 FSM。该增量尚无实测
面积与时序，V7/V8 的整核 FIRRTL 失败记录不能当作综合结果。

## 当前恢复/I/O及GHM物理映射实测（2026-11-23）

本批生产LSU stop门控、uncached AMO授权包号与唯一旧值响应、GHM FINISH顺序修复均复用已有字段和握手，不增加状态。对同一生产GHM前后Yosys proc/opt比较为798→802个泛型cell，仅4个AND；寄存器和队列数量不变。

当前GHM独立Vivado2021.1/U250 OOC综合完成：98,742 LUT、336,628寄存器。这是全部现有GHM队列/数据通路总量，不能当作修复增量；5ns内部WNS+1.898ns，未布线，801输入/1533输出未约束外部延时，不能证明整核/接口时序。来源和报告见本批ghm_ooc_synthesis/。

物理CDC实际未通过：4个forwardDrained组合前置CDC-10、4个ACK同步链SRL映射CDC-13及218个缺ASYNC_REG。独立生成物实验增加4个源端请求寄存器，并保持已有同步寄存器的ASYNC_REG/SHREG_EXTRACT属性后，8项Critical与缺属性警告消失，数字高位/四相/FINISH仍PASS。映射后为98,773 LUT、337,298寄存器；增加的映射寄存器还包含防止合并/SRL替代的既有同步级，不能只按新增4位估算FPGA成本。1742项AsyncQueue数据CE警告仍在，仍须按数据保持/Gray路径约束审查。实验不是生产Scala验收；Scala候选独立生成在途。没有基于旧Stage3数字宣称当前完整Core满足面积/时序。

生产合入后同一未裁剪GHM top实测（production_cdc_synthesis/）：LUT98895、
FF336652，5ns内部WNS+1.448ns；同步器全部226项CDC-3 Info，原8项
Critical和缺属性警告消失。1742项FIFO数据CE警告仍单独审查，未布线/
端口未约束，不宣称整核时序。实际功能新增只有每Checker源端1bit请求
寄存器共4bit；其余寄存器差值来自保持既有同步链和禁止SRL/合并的映射。
slot epoch修复为三处统一跳零组合比较，无新增状态，生产完整层次与
finite-slot四次同组miss/安装/终态回归通过。
