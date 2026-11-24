# PALIMPSEST 功能对照矩阵

## 范围与判定方法

基线：2026-11-21，分支 `firesim/fpga-checkpoint-20261104`，HEAD `75f2905693d6eec3b92d733e65bafa7a9c4be6dc`。Git 根为 EC，Chipyard 下无代码差异；审计前只有 `?? ../AI/Ref/`。论文、哈希和执行限制见 [入口](00_PALIMPSEST_Overview.md)。所有源码定位均相对 Chipyard，行号属于当前工作区；非 Chipyard 证据用 `../` 表示。

状态严格使用：`Implemented`、`Partial`、`Missing`、`Different`、`Unverified`、`N/A`。`Missing` 依据端口/状态/调用链检查及 active source 搜索共同判断，不以未命中某个单词单独证明不存在。`Different` 不等于已证明正常运行错误。对多主核项不记 N/A：当前配置只有一个主核，但论文要求的扩展能力仍应记录缺口。

验证标记：**S/H** = 当前源码静态核对、结论可信度高；**S/M** = 局部路径已确认，端到端或可达性待验证；**R** = 存在源码哈希关联的历史正常运行支持；**HIST** = 旧 fixture/运行，不能外推当前 HEAD；**NR** = 无本轮动态验证。功能状态和验证标记互相独立。优先级 P0=单核恢复正确性前置，P1=完整隔离/跨层/活性，P2=扩展与回归；P0 也可表示必须保留的已有基础能力。

证据编号在本文件后半部分定义，每项包含相对路径、精确行号、生产者/消费者及硬件效果；矩阵中的编号均指该索引。

## A. 基础执行与检查（7 项）

| ID | 功能 | 论文依据 | 当前 RTL 证据 | 状态 | 差异/缺失 | 验证情况 | 优先级 |
|---|---|---|---|---|---|---|---|
| A1 | Main–Checker 接口 | III、Fig.3 | E01/E02/E03：BoomTile→GHM DATA/ARF/控制 CDC→RocketCore；结果反向返回 | Implemented | 当前 1+4 配置路径闭合；不等于多主核恢复接口 | S/H，R，NR | P0 |
| A2 | Segment 生成、关闭、分发 | III、IV-G | E02/E04：R_IC snapshot_accepted/package_allocated、producer seal、barrier_force_close | Implemented | 提前关闭需 ROB drain；压力下必定关段属 E1/E5 | S/H，R，NR | P0 |
| A3 | Seq 生成与传播 | III、IV-A | E02/E05/E06：packet_seq_counter→LSQ→image.contentSeq；DATA/ARF 各带 Seq | Implemented | 当前执行内递增，零保留，回绕 assert；Rollback 语义另见 D8 | S/H，R，NR | P0 |
| A4 | Register CP 保存、定位、恢复接口 | III、IV-E、Fig.3 | E07/E08：R_RSU 单快照，Checker R_RSUSL SCP/ECP RAM | Partial | 已捕获 int/FP/PC/FCSR，特定边界 CSR；无主核可读的持久 CP 目录/恢复口及完整 CP 生命周期 | S/H，NR | P0 |
| A5 | Verification Result 传输、保存、处理 | III、IV-C | E03/E09：Queue/AsyncQueue→checker_results→completed/passed；FAIL sticky | Implemented | PASS/FAIL/CANCELLED 可追踪；FAIL 处理并不包含恢复，见 D2/D6 | S/H，R（PASS 路径），NR | P0 |
| A6 | SW 计算与推进 | III、IV-C/E | E09：256 项带完整 Seq 的 bitmap，连续 PASS 循环；E18：传到 L2 | Partial | 正常前缀已实现；无 EVT，不能跳过回滚废弃区间，FAIL 后前缀永久留洞 | S/H，R（无错误），NR | P0 |
| A7 | LSL 保存与释放 | III、IV-D | E03/E10：GH_BUF→CDC→R_LSL，内存/CSR/RoCC FIFO，deq/cleanup | Implemented | 保存重执行输入而非 undo history，按消费释放并独立归还 Checker；不等待 SW | S/H，R，NR | P0 |

## B. Cache Version 管理（10 项）

| ID | 功能 | 论文依据 | 当前 RTL 证据 | 状态 | 差异/缺失 | 验证情况 | 优先级 |
|---|---|---|---|---|---|---|---|
| B1 | Line version metadata | IV-A | E06/E11/E16：CacheImageKey、imageKey、DirectoryEntry.image | Partial | writer/逐写 generation/Seq 已贯穿；无执行 Epoch、Cur/CurGen、有效历史信息 | S/H，R（身份链），NR | P0 |
| B2 | 同地址多个版本 | IV-A/B、Alg.1 17–22 | E11/E12：L1 resident+SVB；E16：L2 tag lookup | Different | SVB 能保留多个同址快照；L2 未实现同址 Historical ways/版本查询，存储组织不同于论文 | S/H，R（SVB），NR | P0 |
| B3 | Current/Historical 区分 | IV-A/B | E12：SVB 不参与普通 Load；E14：普通 tag/data mux | Different | 隐式 resident/快照区分已存在；没有论文 Current mapping 及 generation 验证 | S/H，NR | P0 |
| B4 | 跨段 Store 建新版本、保留旧版 | IV-B、Alg.1 13–22 | E13：unsafe 普通 M_XWR 可 capture；E15：覆盖门控和实际 masked 写 | Partial | 普通快路径可保留旧整行后写新值；其他请求/满缓冲走 WaitSafe，保留判断非 NeededForRollback(CP,EVT) | S/H，R（普通 Store），NR | P0 |
| B5 | 同段重复 Store | IV-B、Alg.1 14–15 | E06/E15：samePackageIdentity(writer,Seq) 允许，实际写更新当前数据 | Implemented | 不为每次同段 Store 保留可寻址历史；每次内容写分配新 serial 可作为实现细节，执行 Epoch 缺口见 D7 | S/H，R；mask/AMO 扩展覆盖待补 | P0 |
| B6 | 跨 Cache level 版本迁移 | IV-C/D/E | E06/E17：C/D 带 CacheImage，L2 接收真实 bank 写，L1 refill 导入身份 | Partial | unsafe 当前副本可 L1→L2；SVB 下推只选 safe；无历史寻址/跨层 recovery 协议 | S/H，R，NR | P0 |
| B7 | Preserve-before-reuse | IV-D、Fig.4(a) | E13/E15/E17/E19：capture/freeze、lowerPreserved、set lock、outerPreserved | Partial | 正常覆盖及 victim 保护有实际门控；无 CP/EVT 所需历史集合证明，FAIL/flush 可破坏仍需历史 | S/H，R（特定场景），NR | P0 |
| B8 | Preserve ACK/WB ACK | IV-D | E17/E19/E20：ReleaseAck 在末 bank 写之后；L1 key 匹配；outer txn echo | Implemented | 正常保存责任直到匹配 ACK；没有 Rollback reservation 身份，不覆盖 D15 | S/H，R；旧 fixture 另记 HIST | P0 |
| B9 | Historical 释放回收 | IV-D | E12/E21：safe coalesce、ACK 后 free；FAIL/flush 删除 | Different | 有安全下推与回收；按 SW/异常清理，未按 CP+EVT 判断保留。FAIL 会删有效 unsafe predecessor | S/H，R（正常回收）；故障未仿真 | P0 |
| B10 | 替换与资源不足阻塞 | IV-A/D/G | E12：capture.ready/freeAny；E13：full fallback；E16/E19：原替换+阻塞 | Partial | 有界 SVB 和 WaitSafe、L2 阻塞存在；无 CP-aware 历史替换/容量活性闭环 | S/H，R（有限压力），NR | P1 |

## C. 隔离与可见性（8 项）

| ID | 功能 | 论文依据 | 当前 RTL 证据 | 状态 | 差异/缺失 | 验证情况 | 优先级 |
|---|---|---|---|---|---|---|---|
| C1 | Unsafe 识别 | IV-A/C | E06/E09：valid && contentSeq!=0 && Seq>SW | Partial | 正常历史按 SW 正确分类；未判断 EVT 有效性及 producing-core 对应 SW | S/H，R，NR | P0 |
| C2 | SW 约束写回 | IV-C/D | E12：SVB entrySafe；E18/E19/E20：L2 外层 A/C 门控 | Implemented | 在当前单主核、有效身份下有真实 gate；不要求所有 L1→L2 写回安全，见 C3 | S/H，R，NR | P0 |
| C3 | Unsafe L1→L2 迁移 | IV-C | E17：携带原 key 的 ReleaseData/ProbeAckData；E19：阻挡破坏旧 unsafe resident | Implemented | 对可接收的目标确实允许 unsafe 迁移；同址多历史/资源阻塞能力见 B6/B10 | S/H，R，NR | P1 |
| C4 | LLC→DRAM 安全边界 | III、IV-C/D | E19/E20：SourceC safe、checkpoint Put safe、末响应后可重用 | Partial | 直接 A/C 边界已有门控；完整规则还需 EVT，且不覆盖绕行 MMIO；正常路径可沿用 | S/H，R（保存/外写），NR | P0 |
| C5 | 不同 Main 之间可见性 | IV-F | E22：仅 !isImageAware 才等待；E01：当前一个 Main | Partial | 对普通 peer 有 gate；两个 BOOM 都 image-aware 会豁免，没有比较 requester core 与 producing core | S/H（条件缺失），双主核动态 NR | P1，扩多核前 P0 |
| C6 | Coherence/ownership transfer | IV-F/G | E22：MSHR parkEarly/parkLate，等待槽重放；E13：SVB 阻止年轻 Release/Probe | Partial | unaware Get/Acquire/AMO 暴露受限，E 独立排空；aware peer、历史排除/恢复仲裁缺失 | S/H；完整一致性 S/M、NR | P1 |
| C7 | Uncacheable/MMIO/不可重复 I/O | IV-C | E23：BoomIOMSHR s_mem_access 直接发 BASE Get/Put/AMO；E04：普通分段 | Different | 通常的 ROB 非推测发射≠Checker 已验证；未见通用 close→wait SW→I/O 许可。syscall 信号不能覆盖任意 MMIO | S/H（局部直通），平台所有 I/O 端到端待验证 | P0 |
| C8 | 旧版写回抑制/同址顺序 | IV-D | E12：safe 同址 coalesce；E13：releaseBlocked；E19/E20：set lock/事务串行 | Partial | 正常下推有具体次序；未实现跨 epoch/跨核的 obsolete-writeback 判定及安全 baseline 版本目录 | S/H，R（正常序列），NR | P0 |

## D. Rollback/Recovery（17 项）

| ID | 功能 | 论文依据 | 当前 RTL 证据 | 状态 | 差异/缺失 | 验证情况 | 优先级 |
|---|---|---|---|---|---|---|---|
| D1 | Checker 检错与事件 | III、Fig.3 | E03/E08/E24：ELU/ARF/CSR→package_error→FAIL Queue→DCache；结束比较索引 1–31 | Partial | 错误结果路径闭合，但结束比较跳过 f0；PC/FCSR 完整覆盖待验证。CANCELLED 与架构错误需分型 | S/H（f0 跳过及事件路径）；故障链动态 NR | P0 |
| D2 | Rollback Controller 及连接 | III、IV-E、Fig.3 | E21/E25：FAIL 消费者是 sticky/SVB invalidate/barrier；无 restore 输出 | Missing | 没有停机、CP 请求、历史提交、恢复完成和 restart 状态机 | S/H，NR | P0 |
| D3 | 定位错误段 SCP | III、IV-E | E02/E07/E08：checker slot/Seq 与本地 SCP RAM | Partial | 有分段身份及 Checker SCP；无主核恢复可寻址接口、pin/release 及持久 CP 目录 | S/H，NR | P0 |
| D4 | PC/int/FP/CSR 架构恢复 | III、IV-E | E07/E25：主核只输出快照，CSR 导入口常量关闭；Rocket 恢复口在 Checker | Missing | BOOM committed shadow 不能替代 PRF/rename/CSR 的恢复。无完整恢复提交点 | S/H，NR | P0 |
| D5 | Flush、取消请求、执行重启 | IV-E | E14/E26：branch/exception/ROB flush 和 local cancel 现存 | Partial | 只服务通常流水线恢复/重试；没有 Checker FAIL 驱动的恢复屏障 | S/H，NR | P0 |
| D6 | 错误段及后续历史失效 | IV-E、Fig.3 | E21：SVB invalidate.bits=SW，删 Seq>SW | Different | 应失效同核有效历史的错误后缀，现会误删错误段前的 unsafe 历史，且未失效 resident/L2/bitmap/检查任务 | S/H，NR | P0 |
| D7 | 执行 Epoch 与 EVT | IV-A/E/F | E06/E11/E21：key 无 Epoch；svbEpoch 按 exception 变化；E08 的 epoch 为 ECP 帧 | Missing | 没有执行历史区间表；本地槽/帧/session epoch 都不能替代 EVT | S/H，NR | P0 |
| D8 | 回滚后 Seq 与有效历史 | III、IV-E | E02：单调 counter；E09：只认连续数值 PASS | Partial | 可沿用 counter；无新执行 Epoch、有效区间跳洞、作废结果过滤/任务取消 | S/H，NR | P0 |
| D9 | Cur/CurGen/G 管理 | IV-A/E、Alg.1 4–9 | E06/E15：generation 是 imageSerial，每次数据写递增 | Different | 无 Cur、CurGen 或每核逻辑映射 generation；不能把 slotEpoch 当论文 G | S/H，NR | P0 |
| D10 | 回滚逻辑失效 Current mapping | IV-A/E | E14：普通 tag/permission lookup；E11：resident 身份数组 | Missing | 无 FAIL→G advance→lookup stale 的控制；正常 load 可继续命中错误 A8 | S/H，NR | P0 |
| D11 | LatestSurviving 查找选择 | IV-B/E、Alg.1 7 | E12：全局最大 safe 仅用于下推；E14/E16：地址查询不带历史条件 | Missing | 无按地址过滤 EVT、跨层候选比较并返回数据的接口 | S/H，NR | P0 |
| D12 | Safe DRAM Baseline 回退 | IV-E、Alg.1 8 | E17/E23：普通 refill 路存在；E19：safe 保存到 DRAM | Partial | 具备安全 baseline 的物理基础；无确认该值适合 CP、缓存无合格候选时才回退的控制 | S/H；端到端 S/M，NR | P0 |
| D13 | Recovery version 提升 Current | IV-A/E、Alg.1 9 | E12/E17：SVB promote→WB C→L2，非 Load 返回 | Missing | 没有恢复安装及绑定新 G 的动作；recoveryFromSvb=ACK 不是恢复 | S/H，NR | P0 |
| D14 | 跨层按需恢复 | IV-B/E | E17：当前 line refill/key 导入；E16/E19：L2 单 resident | Partial | 传输数据与 key 可复用；没有恢复查询、历史保留/枚举与候选归并 | S/H，NR | P0 |
| D15 | 在途请求/异步 ACK | IV-D/E | E17/E20/E26：正常 key/txn/slot 身份、保留到 ACK | Partial | 正常事务责任较完整；无 epoch discard、恢复 reservation 或 quiesce ACK，旧 refill/ACK 可能修改恢复状态 | S/H；竞态实际可达性 S/M，NR | P0 |
| D16 | 恢复完成与重启 | III、IV-E | E25：无 recover_done/restart 消费链 | Missing | 必须合并架构恢复、历史提交和在途事务处理的完成条件 | S/H，NR | P0 |
| D17 | 多主核独立回滚一致性 | IV-F | E01/E18/E22：一个主核、单 SW、GHM result deq clock0 | Missing | 每核 Epoch/EVT/CP/G/SW 与按 writer 选历史均未闭合；不能因 checker owner 字段推定支持 | S/H，双主核 NR | P2，扩多核前 P0 |

## E. 活性与正确性（7 项）

| ID | 功能 | 论文依据 | 当前 RTL 证据 | 状态 | 差异/缺失 | 验证情况 | 优先级 |
|---|---|---|---|---|---|---|---|
| E1 | Preserve/WB/coherence 前进 | IV-D/G | E04/E19/E22：提前关闭、runnable 优先、drain、peer park | Partial | 有解除阻塞路径；无所有资源压力/错误后有界前进证明；当前失败后 SW 留洞 | S/H（机制），整体 S/M，R 有限 | P1 |
| E2 | 提前关闭 Segment | IV-C/G | E04/E18：L2 validationSeq→分 bank close→R_IC→snapshot | Partial | L2 blocked victim/覆盖/peer 请求可触发；L1/SVB 满、所有活性环路和 I/O 不保证都有该入口 | S/H，R（有限关闭），NR | P1 |
| E3 | Backpressure 传播和解除 | IV-D/G | E03/E12/E17/E19：valid/ready、captureHold、set lock、末 ACK 释放 | Implemented | 正常保存握手闭合；不据此断言任意调度无死锁或 Rollback 可解除 | S/H，R，NR | P1 |
| E4 | Version 资源耗尽 | IV-D/G | E12/E13：SVB 满 fallback；E19：L2 unsafe victim 阻塞 | Partial | 不覆盖所需历史而阻塞；缺 CP-aware 容量管理、预留 escape/close credit | S/H，有限 R；极限压力 NR | P1 |
| E5 | 防死锁/无限等待 | IV-G | E19/E22/E24：drain/park/watchdog；E04：snapshot 要 ROB empty | Partial | timeout/CANCELLED 多为诊断或失败，非正确恢复；资源循环和 peer 优先后续冲突写需专门证明 | S/M，有限 R，NR | P1 |
| E6 | Rollback 与正常 WB 竞态 | IV-D/E | E20/E21：有正常事务识别，SVB WB_WAIT 不因 invalidate 释放 | Missing | 无 Rollback 协调协议；保留 WB owner 有帮助，但不足以阻止过期内容或 ACK 修改新历史 | S/H，NR | P0 |
| E7 | 测试、仿真、断言覆盖 | V、功能正确性要求 | E27：Stage2/3 fixture、Opt4 trace 检查及现有运行 | Partial | 正常保存/身份有证据；无 A7 恢复/EVT/双核恢复覆盖；Stage3 有历史 FAIL 与 PASS，不能合并为当前全绿 | S/H，R/HIST 分开，NR | P0 |

<a id="evidence-index"></a>
## 当前源码证据索引

### E01：配置与适用拓扑

`generators/chipyard/src/main/scala/config/RocketConfigs.scala:9`、`:20`、`:27`、`:28` 定义 v1Config 的 L2 和 Main/Checker 数；`generators/rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala:9`、`:10`、`:11`、`:20`、`:25` 定义 barrier 默认 true、1+4、32 位 Seq 和结果编码。注释写 opt-in 不能推翻参数默认 true 的代码。单主核配置并未满足论文 IV-F 的完整多主核能力。

### E02：分段与 Seq 生产者

`generators/rocket-chip/src/main/scala/r/R_IC.scala:129` 保存 slot Seq，`:130` 定义全局于该 BOOM/checker 组的 counter；`:227`、`:238` 原子快照，`:263`、`:265`、`:273`、`:278`、`:282` 实际分配并递增。`:276` 禁止回绕到零，`:292`、`:297` 区分 closing 与仍拥有 producer 的流量。`:268` 在结果释放后清 slot；不存在回滚 counter 重置/历史区间操作。

### E03：检查输入与结果的端到端运输

`generators/boom/src/main/scala/trans/GH_BUF.scala:128`、`:130` 从提交产生内存/分支/CSR 等输入，`:246` 输出。`generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala:139`、`:151` 分别建立 DATA/ARF AsyncQueue；`:186`、`:195` 选择 Seq，`:279`、`:285` 产生 anchor/END，`:305` 起协调独立流的 Seq。

`generators/rocket-chip/src/main/scala/rocket/RocketCore.scala:1451`、`:1459` 合并数据/ARF/CSR/执行尾；`:1525` 形成 PASS/FAIL/CANCELLED，`:1531`、`:1535` 保持结果到 Queue 接受；`:1553`、`:1555`、`:1558` 清理完成才允许 handoff。`generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala:555`、`:559`、`:565`、`:575`、`:576` 通过独立 CDC 在 BOOM 域形成结果脉冲并保持 release；deq clock 明确接主核 0。

`generators/boom/src/main/scala/common/tile.scala:665`、`:673`、`:676` 把 LSU、分配事件及结果接到 DCache。这条闭环不包含恢复请求。

### E04：提前关段与真实架构边界

`generators/rocket-chip/src/main/scala/r/R_IC.scala:246` 比较 barrier_force_close_seq 和当前 producer；`:250` 说明并实现 ACK 仅为命令接受；`:453`、`:469` 进入 postcheck 后正常分段。`generators/boom/src/main/scala/exu/core.scala:2046` 接每 bank 请求，`:2091` 锁存仲裁服务，`:2146`、`:2153` 发送 close/ACK；`:2213` 要求 ROB empty/稳定 next-PC，`:2252` 阻止新 dispatch，`:2260` 形成 producer seal。命令接受不能等同于快照已完成、Checker PASS 或 SW 已推进。

### E05：Seq 进入 LSQ

`generators/boom/src/main/scala/lsu/lsu.scala:1171`、`:1177`、`:1196`、`:1202` 在翻译成功时锁存 LDQ/STQ Seq，`:1087`、`:1243`、`:1245` 把它带入 cache request/write domain。Seq 的存储不是历史有效性查询；这里没有执行 Epoch。

### E06：跨层内容身份与安全谓词

`generators/rocket-chip/src/main/scala/tilelink/CacheImage.scala:12` 定义 `{valid, writer[16], generation[32], contentSeq[32]}`，`:32` 定义 safe，`:34`、`:38` 判断同 writer/同 Seq 及更高内容 serial，`:56` 定义 64 位 CachePreserveTxn。无执行 Epoch、Cur、CurGen。`valid=false` 是 BASE 身份，不是“错误段已经被 EVT 作废”。

### E07：主核捕获快照，未形成可恢复 Context Memory

`generators/boom/src/main/scala/exu/core.scala:2002`、`:2007`、`:2009`、`:2011` 在提交时更新 int/FP shadow；`:2346` 输入 committed next-PC。`generators/rocket-chip/src/main/scala/r/R_RSU.scala:20` 的输入、`:39` 的序列输出及 `:60` 的一组快照寄存器，构成 Main→Checker 数据流。`:105` 保存 int/FP/PC/FCSR；`:115` 才额外保存 CSR shadow。该模块没有由 Seq 寻址多份 CP 的恢复读口，当前快照会被下一次覆盖；不能当成论文的持久 CP 存储。

### E08：Checker 本地 SCP/ECP 与比较

`generators/rocket-chip/src/main/scala/r/R_RSUSL.scala:111`、`:113` 是各一份 SCP/ECP int/FP RAM；`:58`、`:60` 接 package start/Seq，`:177` 的 ecp_frame_epoch 是 ECP 帧身份；`:374`、`:393` 输出用于 Checker 初始化的寄存器/PC，`:474` 启动结束比较，`:497`、`:503` 汇总错误。`generators/rocket-chip/src/main/scala/rocket/RocketCore.scala:1112`、`:1123`、`:1672`、`:1997` 将这些恢复输出接到 Rocket RF/CSR/FPU；接收者不是 BOOM。

### E09：正常 SW bitmap

`generators/boom/src/main/scala/lsu/dcache.scala:1724`、`:1728` 分配 256 项 bitmap；`:2493` 在测量窗口外也分配功能状态，`:2528` 检查完整 Seq/状态/重复，`:2547` 保存 completed/passed；`:2582`–`:2592` 只扫描紧接 SW 的连续 PASS；`:2617` 清除已覆盖槽；`:2632` 提交 SW。不存在废弃区间跳过。FAIL/CANCELLED 不作为 PASS，这一隔离属性应保留。

### E10：LSL 数据和空间释放

`generators/rocket-chip/src/main/scala/r/R_LSL.scala:69`、`:70`–`:73` 定义内存/CSR/RoCC FIFO，`:134` 检查 head 类型/地址，`:215` 在实际消费后释放 head，`:245` 返回原执行 load value，`:257` 定义完整 quiescent。`:264`、`:265` 输出消费事件；接口不接 SW/CP/EVT。`RocketCore.scala:1451` 等 LSL quiescent 才提交检查结果。物理 FIFO 条目在检查消费时释放，Checker slot 在结果交付后释放，不保留跨检查段的 undo log。

### E11：L1 resident/快照 metadata

`generators/boom/src/main/scala/lsu/dcache.scala:704` slotEpoch 是物理槽 incarnation；`:711` lineGeneration、`:718` imageKey、`:720` lowerPreserved、`:723` imageSerial 是内容/保存责任；无论文映射 G。`generators/boom/src/main/scala/lsu/speculative-version-buffer.scala:18` 快照含整行 data、line、key、本地 epoch；`:53` 列出全部端口，无按地址恢复读请求/响应。

### E12：SVB 分配、选择、回收

`generators/boom/src/main/scala/lsu/speculative-version-buffer.scala:101`–`:107` 为每项保存 valid/state/line/key/epoch/data；`:123` freeAny 控制 capture.ready；`:125` 只把同当前本地 epoch 且 Seq≤SW 的 SPEC 视为 entrySafe。`:175`、`:224`、`:229` 选择全局最大 safe Seq 用于下推，并保持到 ACK；不是给指定地址找最大有效 Seq。`:240`、`:242` 明确 recoveryFromSvb 等于 acked。

`:280` 合并同址同 writer 较旧 safe SPEC；`:302` 匹配 ACK 后释放 WB_WAIT。`:315` 按 invalidate cutoff 删除 SPEC；`:324` flush 删除全部 SPEC；WB_WAIT 不被两者直接释放。无 outstanding CP 集合输入。

### E13：L1 跨段捕获及同址顺序

`generators/boom/src/main/scala/lsu/dcache.scala:1766` 覆盖许可；`:1780` 检出跨域覆盖，`:1786` 限定快路径为普通 cacheable M_XWR、较新非零 Seq、unsafe old image；`:1793`、`:1794` 在有空位时 capture，否则 fallback。`:1852`、`:1865`、`:1878` 用 WB 行读取器捕获并等实际 snapshot handshake；`:1953` 先 drain 已在管线内的访问。

`:1395`、`:1556`–`:1572` 与 SVB `speculative-version-buffer.scala:113` 配合，阻止同址较年轻正常 Release/Probe 越过保留的 predecessor，直到它匹配 ACK 后释放。

### E14：正常读取与普通 flush

`generators/boom/src/main/scala/lsu/dcache.scala:1049`、`:1050`、`:1100`、`:1173` 按 tag、coherence 和现有 pipeline 选择 resident data；无 CurGen/EVT 或 SVB lookup。`:1029` 等依照 branch/exception 清推测 load。原生 BOOM `generators/boom/src/main/scala/exu/core.scala:1036` 的 rename.rollback 接 ROB rollback，`generators/boom/src/main/scala/exu/rob.scala:246` 是通常 ROB 状态机；不能恢复早已提交到其他 Segment 的状态。

### E15：实际数据覆盖及保存规则

`generators/boom/src/main/scala/lsu/phase1.scala:69`、`:73`、`:79` 规则是“不存在/同 package，或 safe 且有 lower receipt”，不读 CP/EVT。`generators/boom/src/main/scala/lsu/dcache.scala:3077`–`:3087` 在 S3 再检查许可并以真实 dataWrite fire 为效果点；`:3319`、`:3332`、`:3334`、`:3342`–`:3346` 每次写生成新内容 serial、设置 writer/Seq、撤销旧 receipt。same-segment 数据更新成立，但该 serial 不是 Rollback 的 G。

### E16：L2 仍是单 resident directory

`generators/sifive-cache/design/craft/inclusivecache/src/Directory.scala:28`、`:40` 每 way 只有一个 image，`:52` 查询仅 set/tag，`:144`、`:150`、`:152` 从命中 ways 选择，没有 Current/Historical/EVT 条件。`MSHR.scala:411` 接收 ReleaseData 后以 incoming image 更新 resident；没有独立地址+版本选择协议。因此不能任意增加同 tag ways 后继续沿用现有 Mux1H 命中逻辑。

### E17：真实 L1/L2 保存与 ACK

`generators/boom/src/main/scala/lsu/dcache.scala:164`、`:165` 在 WB C 数据带 key；`:1603` 把 SVB promote 接 WB，`:1614`–`:1623` 检查 D source/opcode/size/key/denied；`:95`、`:112`、`:120` 保留 WB owner 到全行发送及 ACK。

`generators/sifive-cache/design/craft/inclusivecache/src/SourceD.scala:225`、`:322`、`:330`、`:332` 在末 bank write 后形成携带原 image 的 ReleaseAck。`generators/boom/src/main/scala/lsu/dcache.scala:3309`–`:3312` 在 refill 安装后将下层 image 标为已保存；这是普通当前副本数据路径，尚无 recovery 版本选择。

### E18：SW 与关段跨域路径

`generators/boom/src/main/scala/lsu/dcache.scala:2609` 发送 SW Gray 值；`generators/sifive-cache/design/craft/inclusivecache/src/InclusiveCache.scala:244`、`:248`、`:257`、`:258` 同步并接 Scheduler。`:285`–`:301` 从 unsafe victim/同址保存/peer wait 形成请求；`:297` 的 close ACK 与 `:304` 的 SW 共同解除。所有接口为单一 SW，未由 writer/core ID 选择。

### E19：L2 覆盖保护与安全 DRAM 保存

`generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala:195`–`:205` 阻止异 key 覆盖旧 resident，`:214`–`:220` 对 ProbeAckData 同样保护；`:254`、`:257` 优先可执行且 safe 的候选，`:264` 停新工作以 drain；`:312`、`:333` 按 set lock 和 safe 许可。

`generators/sifive-cache/design/craft/inclusivecache/src/L2Preservation.scala:19` 判 blocked，`:48` 明确限定 terminal last-level；`:51` FSM idle/read/delay/send/waitAck/failed，`:64`–`:66` 只捕获 safe dirty 且未 outerPreserved 的旧值；`:105`、`:108` 用原地址 PutFullData 写到外层，不是分配另一个历史地址/way。`:128`–`:139` 等全行发完且匹配 AccessAck 才完成。

### E20：外层边界与异步响应责任

`generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala:333` 的 outerSafe、`:777` 锁定期间禁止物理覆盖、`:784`–`:800` 对实际 SourceC/外层 A 发射断言 safe。`SourceC.scala:175`、`:181` 再检查请求和 beat。

`MSHR.scala:804`–`:819` 以 releaseIssued、完整 sent、事务 echo 匹配 ReleaseAck，`:828`、`:829` 阻止 acquire/tag 更新越过旧 WB ACK；`:839`–`:847` 仅对 set/way/tag/精确 image 匹配的 preservation completion 设置 outerPreserved。`L2Preservation.scala:148` 对迟到/重复 ACK 计错并忽略，`:155` 断言责任只能在匹配完成后解除。无 execution-history epoch 或 recovery reservation。

### E21：当前错误处理直接破坏有效 unsafe 历史

`generators/boom/src/main/scala/lsu/dcache.scala:2555` 合并 FAIL/CANCELLED；`:2561`–`:2565` 保存第一次选择到的失败 Seq（同周期按 checker 优先编码，非最小 Seq），且没有恢复后清除。`:2569` 以 `traffic_reset || lsu.exception` flush SVB；`:2570`–`:2571` 把错误事件的失效 cutoff 设为 SW，非 failedSeq-1；`:2572`–`:2575` 对 RESET 清本地 epoch、exception 自增。`speculative-version-buffer.scala:315`–`:329` 执行删项。

`generators/boom/src/main/scala/common/tile.scala:669` 证明 traffic_reset 来自性能控制 RESET 位。常规 pipeline exception 也经 `lsu.scala:987` 进入 cache exception；它不是一次经 EVT 管理的回滚。两种 flush 均没有判断 outstanding CP 或另一存储是否仍保留所需 unsafe 历史。

### E22：普通 peer 的隔离和多 Main 缺口

`generators/sifive-cache/design/craft/inclusivecache/src/Parameters.scala:194`–`:200` 以 CacheImageClient 契约标记 image-aware；`generators/boom/src/main/scala/lsu/dcache.scala:541`、`:559` BOOM 是该类客户端。`MSHR.scala:263`–`:283` 仅对 !isImageAware 的不安全暴露执行 park，等待探测/GrantAck 责任完成；`Scheduler.scala:155`–`:176` 为 unaware source 保存等待请求，安全后 replay；`:317`、`:321`、`:461`、`:464` 再拦截/断言。

这些判定没有比较请求者是否与 image.writer 属于同一 Main。writer 目前是静态 cache 客户端 namespace，并非完整每核历史表索引。新增第二个 image-aware 主核后，不能依赖该豁免维持 IV-F 隔离。

### E23：MMIO 路径缺验证许可

`generators/boom/src/main/scala/lsu/mshrs.scala:642`–`:652` 的 IOMSHR 接口没有 SW/检查完成/close 许可；`:664` FSM，`:676`–`:688` 构造 BASE Get/Put/AMO，`:696` 仅按 s_mem_access 置 valid；`:1126`、`:1128` 接入真实 mem_acquire 仲裁。已有非推测内存语义避免年轻于 ROB 提交，却不能等待滞后的 Checker。`generators/boom/src/main/scala/exu/core.scala:2197` 的 syscall 控制、`R_IC.scala:464` 的过滤也不构成通用 MMIO 的 close/wait-safe 机制。

### E24：错误检测及 watchdog 的真实含义

`generators/rocket-chip/src/main/scala/r/R_ELU.scala:93`、`:94` 比较地址/Store 数据，`:136`、`:137` 报告错误；`generators/rocket-chip/src/main/scala/rocket/RocketCore.scala:1315` 收集 ELU/CSR 错误，`:1410` 接 ARF 完成错误，`:1525` 形成结果。ARF 错误见 E08。`:1463`、`:1471`、`:1497` 的 timeout 进入 `:1502` package_cancelled，`:1520` 延迟清 LSL；这提供诊断终止与资源释放，不能当成正确执行恢复。

**静态检错覆盖风险：f0 未进入结束比较。** `generators/rocket-chip/src/main/scala/r/R_RSUSL.scala:313`、`:476` 将 checking_counter 置 1，`:336`、`:337` 用同一索引读取 int/FP ECP，`:438`–`:441` 对比两组寄存器，`:490`、`:498` 在索引 31 终止。FP 数据没有偏移重映射：`generators/rocket-chip/src/main/scala/tile/FPU.scala:820` 输出实际 `regfile(i)`，`RocketCore.scala:1117` 直接接到 core_farfs_in；`R_RSUSL.scala:282` 按 packet_index_ECP 写入。跳过 x0 合理，却同时跳过了可写的 f0。由此可构造“段尾仅 f0 不同，未影响已检查访存/其他状态”的遗漏场景；这是静态覆盖缺口，尚未观察到实际错误 PASS。当前链中未找到独立 f0 比较器，D1 因而标 Partial。

PC/FCSR 的完整结束比较另列待验证，不能由“已保存”推出“已检查”。`generators/rocket-chip/src/main/scala/rocket/CSR.scala:588`、`:589` 导入 FCSR shadow，`:634` 在特定 trap 边界投影 mepc，`:652` 形成 CSR 比较错误；这既不能证明所有段尾 PC/FCSR 已覆盖，也不支持笼统断言完全没有 PC 检查。04/T25 用单状态失配分别建立覆盖证据。

### E25：回滚主控和主核 restore 的缺失证据

检查 active `generators/boom/src/main/scala`、`generators/rocket-chip/src/main/scala`、`generators/chipyard/src/main/scala` 和 inclusivecache 源目录的 RollbackController/EVT/CurGen/LatestSurviving/restore 接口，结合 Main/Checker 端口及 FAIL 全部消费者：只有 E21 的清理和 E18 的 barrier failure，没有 FAIL→恢复 CP→架构导入→重启链。

`generators/boom/src/main/scala/exu/core.scala:2349`–`:2364` 主核的 FCSR/CSR checkpoint 导入/检查相关端口常量关闭，R_RSU 只输出到 Checker；`:1036` 的现有 rollback 来自 ROB。`InclusiveCache.scala:300`、`:356`、`:360` 将 FAIL/timeout 变成 barrier error；`core.scala:2075` 定义 l2BarrierErrorAny，但当前源中无后续消费该值的恢复控制。即使错误被检测，也没有自动重启功能。

### E26：可复用的本地事务生命周期

`generators/boom/src/main/scala/lsu/phase1.scala:27`、`:39` 等 token/slot incarnation 与 `mshrs.scala:365`–`:377` 的 primary owner、write-domain、transactionSerial 可用于防止重复效果；`dcache.scala:673`–`:689` 将 replay completion/cancel 与普通 exception 分开。`mshrs.scala:1131`–`:1135` 的 BranchKillableQueue 在普通 exception 下清 load response。这些接口没有 failed-history epoch，不能直接跨越 committed-history Rollback 使用。

### E27：已有测试与实际证据

`../AI/Debug/scripts/stage2/stage2_test.cpp:278`–`:384` 有 10 个定向 CASE 源码，覆盖重复同包、跨包等待/receipt、AMO/SC、refill 和真实 SourceD；`../AI/Debug/scripts/stage3/stage3_test.cpp:650` 是其测试成功出口，不代表实际执行成功。旧 `../AI/TMP/stage3_runs/run_igda2knt/summary.json` 实为 BUILD PASS、DIRECTED FAIL、SYSTEM NOT_RUN。另有 `../AI/TMP/stage3_runs/run_qx63gyhc/summary.json` 记录 BUILD/DIRECTED/SYSTEM 均 PASS、SOURCE_PROVENANCE PASS、STAGE3_STATUS VALIDATION_PASS，但 STAGE3_CLOSURE 仍为 NO。本轮未逐项将这两份 Stage3 运行源码身份关联到当前 HEAD；历史失败不能充作当前失败，历史通过也不能扩张为当前所有配置或 Rollback 已验证。

`../slowdown/opt4/frozen_manifest.json` 的 20 个 frozen_source_sha256、12 个 measured_hardware_sha256 与当前文件全部匹配；6 个 raw_evidence_sha256 也匹配。清单记录正常 BFS verified=1，406 次 SVB allocations、391 下推完成、12 coalesced、3 flush-discarded，以及正常协议/顺序 PASS。尚未建立被 flush 的 3 项对所有 CP 无需保留的证明。

`../slowdown/optimization_4_svb/scripts/offline_protocol_tests.py:54`–`:85` 是 host trace 检查器的合成样例测试，不是 RTL 仿真。完整验证分层及后续用例见 [04](04_PALIMPSEST_Verification_Plan.md)。

<a id="design-decisions"></a>
## 论文要求与设计待决策

论文明确要求：按 CP/有效历史保存最新所需版本；执行 Epoch+EVT；Cur/CurGen 对本核 G 的逻辑映射失效；按需 LatestSurviving；只有有效且 Seq≤本核 SW 才能对外传播；回滚前处理在途事务；跨核独立历史；压力提前关闭和 coherence 请求优先。不能把这些降为可选细节。

以下细节论文未固定，须标“设计待决策”：

| 设计问题 | 论文约束 | 可选择的 RTL 方案及边界 |
|---|---|---|
| 历史放置 | 同址多个可恢复版本、跨层保持可检索 | 常规 cache ways、SVB/历史 sidecar 或混合；sidecar 是组织差异，若实现相同语义可保留，但需说明与论文 ways 组织的差异 |
| CP 容量与生命周期 | 每个可回滚段 SCP 可定位、恢复前不被覆盖 | 集中 RAM、分布式 Checker RAM 加独立 pin/read 协议；不能只复用立即释放的 slot |
| 在途处理 | 旧 transfer/ACK 不改变恢复结果 | 保守 drain 或 epoch 标记取消；TL 已接收责任仍须完成，不能简单拉低 valid/清空所有 MSHR |
| EVT 编码和回收 | 保留跨 epoch 有效区间，Seq 不复用 | interval RAM/压缩边界等；位宽、满表与连续 rollback 策略必须定义 |
| Current 逻辑映射 | 按 G 失效而不全 cache 扫描 | Cur/CurGen 位或等效 mapping sidecar；仅整 cache invalidate 会改变论文机制且可能丢历史 |
| Baseline 追踪 | 仅无合格历史且 DRAM 表示所需值时回退 | 可证明的写回序列不变量或显式每地址/事务 baseline 记录；不能默认 DRAM 总是所需 CP 值 |
| CSR/翻译/中断状态 | 恢复架构状态且可正确继续执行 | CSR 集合、TLB/fetch 缓冲是否清理、不可回放中断/计数器策略需定义；论文未列出每个 CSR 的布线 |
| Liveness 资源 | 保留必要版本且能推进检查 | escape credit、预留槽、压力关闭阈值和公平仲裁；具体数量未由论文给定 |

静态覆盖的局限：未对所有平台外设/DMA、所有参数配置、跨异步时钟更新或全部 MMIO 地址映射证明端到端性质。已确认的局部门控如实列为事实，未见全局证明的项保留待验证，不能将正常 PASS 扩张为恢复正确。
