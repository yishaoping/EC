# 当前 459000 运行：Root Cause Report（只读复核）

## 1. Failure Summary

`test.log` 在 `[459000]` 报 `BoomCore.sv:6884/assert__assert_22: little core 1 has hung`。这是 BOOM 等待 checker 1 释放 package ownership 的 watchdog，不是第一处错误。当前运行的第一个**被消费的错误架构状态**是 seq=1 快照 PC：BOOM 的下一个实际提交 PC 为 `0x80000368`，快照却锁存、传输并让 Rocket 重播了此前已执行的 `0x800004ac`。另有独立的 LSL 同步 FIFO 队首协议违例：`head_valid=1` 后数据没有被保持，最终既无法匹配也无法出队。两者在同一运行中同时存在；不能把后一处错误或最终 watchdog 单独当成首因。

## 2. Expected Behavior

软件 `Software/Test/test.c:50-64` 在计时初始化之后执行协同运行的 RoCC 命令，再运行 GAPBS BFS。`Software/Test/test.dump:518-521` 显示该边界附近 `0x80000364` 为 RoCC 命令，顺序下一条为 `0x80000368: rdcycle s3`，随后 `0x36c` 和 `0x370: jal gapbs_bfs_run_512`。一个空 ROB、无同步退休的快照应使 Rocket 从这个**下一条架构指令**继续，而不是从过去已经退休的指令重新开始。

BOOM 的架构提交（`commit.arch_valids`）经一拍寄存送入 `GH_BUF`；load/store/CSR/branch/RoCC 记录按目标 checker 经 GHM 与异步 CDC 到 Rocket 的 RSUSL/LSL。Rocket 应使用同一 seq 的 CPS/ARF/PC 重播指令，LSL 按存储操作类型和地址匹配 BOOM 的提交记录；同步 RAM 的读返回数据与 `head_valid` 应在整个等待和实际 dequeue 期间属于同一队首。完整数据、ARF、指令边界校验之后产生 result，GHM 据此释放 BOOM ownership；PASS 才推进 cache 的安全包水位。

## 3. Relevant Architecture 与 barrier 语义

`v1Config` 配置一个 BOOM、四个异步 Rocket checker、共享 inclusive L2。`R_IC` 在 cooling/snap 阻止新 dispatch、允许现有 ROB 项退休，等 `rob.empty` 和注册的 quiet/armed 条件成立后发 snapshot；`R_RSU` 延迟一拍抓取 ARF 与 `pcarf_in`，尾项经 GHM CDC 进入 `R_RSUSL.pcarfs_ss`。空 ROB 保证退休边界稳定，**并不保证 `rob_uop(head).debug_pc` 仍是有效的下一 PC**，也不等于全部 L1/L2/TL transaction 已完成。

功能性 cache barrier 默认启用（`GH_GlobalParams.scala:9`，`v1Config` 未覆盖），有两处。L1 DCache 对命中写入比较当前 `packet_seq`、该行旧的 `dirtyPacketSeq/Tracked` 与 `safePacketWatermark`；跨包覆盖尚未 PASS 的脏行时，在 S2 nack/replay 并保留 `crossPackagePending`。旧包变安全后，shadow writeback 通过 TL C 发 `TtoN`，待 writeback 结束及 metadata 清理后撤销 pending。L2 在待调度的脏、可归属包的 writeback seq 高于同步来的安全水位时，拉低 `scheduler.io.barrier_allow`（只约束需要 C 通道的该项调度）并向 BOOM 送 request/seq；`R_IC` 在对应包 close 到 postcheck、`!rsu_busy` 后给 ACK，L2 还必须看到 `seq <= safeWatermark` 才解除。ACK 不是 PASS，也不是任意 outstanding TL 已全部清空的证明。跨时钟 request/ACK 和 Gray 水位均经过同步。本次未提交 DCache/LSU diff 同时改变了 store nack/replay 的身份约束、包序号归属、跨包影子写回的 `TtoN` 参数及观测点；这些机制会影响后续物理事务，但不改变本次首个 PC 错位的时间顺序。

本次 seq=1 首坏之前，BOOM `barrierServiceActive`、`io_barrier_force_close`、`barrierCloseAckReg` 均为 0；它们在整份 FST 也未变为 1。L2 `barrierCandidateUnsafe/barrierActive/barrierRequest` 全程为 0。L1 `crossPackagePending` 到 `396827` 才因 seq=2 写覆盖 seq=1 脏行而置 1，属于后续放大，不可能造成 `393091-393095` 的错误快照 PC。

## 4. Complete Signal / State Causal Chain

```text
软件：mtimecmp_cfg 中 0x800004ac 的 lw 早已执行；之后到 0x80000364 RoCC 协同命令
 -> BOOM 退休 0x364，ROB 清空；真实后继将是 0x368
 -> 新增 rob.empty/quiet/armed snapshot guard 允许 seq=1 快照
 -> ROB head 移到 invalid 槽；rob.io.r_next_pc 无 valid 限定，输出残留 0x4ac
 -> core.rsu_master.io_pcarf_in = 0x4ac，R_RSU.pcarf_ss 锁存
 -> GHM/CDC CPS 尾项 -> R_RSUSL.pcarfs_ss -> Rocket.rsu_pc -> checker 起点 0x4ac
 -> Rocket 重播已退休 lw，LSL 请求 load 0x200bff8
 -> 与 seq=1 BOOM 真实提交流先到的 store 0x80087f58/0x80087f68 不匹配
 -> LSL 同时存在独立损坏：同步预取后的 payload 消失而 head_valid 留高
 -> 没有 lsl_deq_fire；LSL 不空，full_check_complete/result/release 均不产生
 -> seq=1 未 PASS，后来 seq=2 跨包脏行覆盖进入 L1 pending
 -> BOOM checker 1 ownership watchdog 继续计数，在 log 459000 断言
```

这里的 `rob_uop.debug_pc` 在 `rob_head_vals_0/1/2=0` 时只是**无效槽的旧内容**，不是 speculative 指令，也不是 committed/architectural 的下一 PC。已退休的 `0x4ac` load 是先前架构事实；把它复制进新 CPS 才造成重播错位。GH_BUF 的记录来自 `commit.arch_valids`，属于本包 BOOM 的架构记录；DCache S2/S3、TL ready-valid-fire 和 watermark 则是之后的物理事务/验证状态，不可与退休事件混同。

## 5. VCD Timeline：last good → first bad → failure

以下均为**当前** `test.vcd`（实际 FST）原生时间；范围 `0..917376`，约为日志时间的 2 倍，不把旧 Debug 波形的时间混入。波形 2026-10-05 18:48，相关生成 RTL 17:24；本次 Scala 源文件修改时间均早于生成 RTL。关键原始抽取见本报告末尾。

| FST 时间 | 观测及解释 |
|---:|---|
| 392823→392845 | `commit_uops_0.debug_pc=0x800004ac`，后 `commit_arch_valids_0=1`；`test.dump:608` 确认这是 `lw a5,-8(a4)`。它早于 seq=1。 |
| 393083 | `commit_arch_valids_2=1`，`rob.io_r_next_pc=0x80000364`；这是边界前最后的有效退休。 |
| 393085 | `rob.io_empty=1`，`rob_head_idx=0x34`，三个 `rob_head_vals` 都为 0；同一时刻 `rob.io_r_next_pc/rsu_master.io_pcarf_in=0x800004ac`。这是首个**错误候选输入**，但还未锁存。 |
| 393091→393095 | `snapshot_accepted/io_snapshot=1`；`393093` 分配 seq=1，然后 `doSnapshot=1`，`R_RSU.pcarf_ss=0x800004ac`。`393095` 是本包首个已锁存的坏 CPS/PC 状态。 |
| 393097→393105 | BOOM 同一个空 ROB 边界后的新有效 head PC 变为 `0x80000368`，并在 `393105` 以 `arch_valid=1` 退休；排除了合法回跳 `0x4ac` 的解释。 |
| 393249→393257 | Rocket RSUSL 收到 CPS `packet_index=0x20`、低 40 位 PC=`0x800004ac`；`pcarfs_ss=0x4ac`，随后 `rsu_pc=0x4ac`。seq=1 在 `393113` 已传给 checker。 |
| 393239→393269 | GHM/CDC 将 BOOM store `0x80087f58`、`0x80087f68` 送往 LSL；bank0 入队、`empty=0`。`393261` 发 `deq_read=1`，`393265` 有正确 store payload 且 `head_valid=1`；`393269` `deq_bits/selected_head=0` 而 valid 保持 1。bank1 在 `393269/273/277` 重复。 |
| 393645→393649 | checker `lsl_req_valid=1`，`cmd=01` (load)，地址 `0x200bff8`；随后 WB PC=`0x800004ac`。它既不匹配第一 store，且此时 `selected_head` 已无效。 |
| 396825→396827 | DCache 对 seq=2 store 报 `crossPackageBlockCondition=1`，随后 `crossPackagePending=1`、旧 seq=1；在首坏之后。 |
| 917376 / log 459000 | LSL bank0 仍非空、`lsl_deq_fire` 全程未拉高，`package_owned=1`、`full_check_complete=0`、`package_result_event=0`；最终 checker 1 watchdog 断言。 |

## 6. Root Cause 与置信度

**Confirmed — 首个架构状态根因：空 ROB 快照把 invalid head PC 当作下一架构 PC。** `rob.scala:280,536` 无条件从当前 head 的 `debug_pc` 产生 `r_next_pc`；`core.scala:2254` 无条件送入 RSU。此次 diff 把 snapshot 准入从“当前 head 可提交”改为“ROB 已空并 quiet”，但没有改变 PC 来源；因此准入条件恰好使 PC 从 invalid head 读取。代码预测、`393085` 无效位与 PC、`393095` 锁存、`393253` checker CPS、`393645` 重播 load 和 BOOM 随后提交 `0x368` 完整闭合。

**Confirmed — 并存的独立 LSL 根因：valid 与同步读 payload 生命周期不一致。** 当前 diff 将 `GH_MemFIFO.io.deq_read` 与 dequeue 分离，使首次预取确实发生，排除旧报告所谓“完全没有读”的判断。但 `R_LSL` 只把 `lsl_head_valid` 寄存，`selected_head` 始终连在 `mem.read(readPtr, deq_read)` 的瞬态输出。生成 `mem_combMem_0.sv:105` 在读使能失效时返回未定义值（该次 Verilator 波形为 0），而 `head_valid` 保持 1、预取条件不再成立。故读过一次后再无可比较队首。即使只纠正 PC，当前 LSL 也不能可靠地消费正常的第一项；即使只纠正 LSL，当前错误重播的 load 仍不能匹配本包首个 store。这里描述的是两个已观测 invariant 违例，并非在未运行反事实仿真的情况下宣称单独修正任一项后其余行为必然如何。

## 7. Downstream Symptoms

`lsl_req_match=0 -> lsl_deq_fire=0 -> lsl.io.if_empty=0`，RocketCore 的 `arf_compare_ready/package_data_complete/full_check_complete` 被 LSL 非空阻断；无 result 也无 GHM 的 sequenced release，`R_IC.package_owned_1` 与 `ic_status_1` 保持 1，BOOM `little_status1` 累计至第 18 位触发断言。Rocket ICSL 后续在 checking/self-exception 间往返。L1 seq=1 脏行因安全水位没有 PASS 而阻塞 seq=2 覆盖；这是先前失败在 cache 层的放大，而不是最早原因。L2 close request 在该波形中未触发。

## 8. Source / Git diff / VCD Evidence

- 软件：`Software/Test/test.c:40-64`，`Software/Test/test.dump:518-521,608-610`。
- BOOM：`boom/.../exu/rob.scala:279-280,530-536`；`exu/core.scala:2151-2168,2178-2195,2252-2256,2110-2133`。工作区 diff 新增空 ROB/quiet guard、dispatch drain 与 seq allocation；`rob.scala` 本身未修改。
- 传输/重播：`boom/.../common/tile.scala:295-309`；`trans/GH_BUF.scala:94-158,195-299`；`rocket-chip/.../r/R_RSU.scala:94-124,188-205`；`R_RSUSL.scala:286,393`；`RocketCore.scala:1047,1106,1413-1422,1961-1972`；`rocket/CSR.scala:1195`；`GHM.scala:480-528`。
- LSL：`R_LSL.scala:109-199`、`GH_FIFO.scala:136-206`；生成 `R_LSL.sv:162-177,319-329`、`GH_MemFIFO_1.sv:138-148`、`mem_combMem_0.sv:73,105`。本次 diff 引入 read/dequeue 分离，但 payload 没有随 valid 保持。
- cache/barrier：`boom/.../lsu/dcache.scala:1025-1098,1180-1250,1565-1603`；`boom/.../exu/core.scala:2020-2105`；`rocket-chip/.../r/R_IC.scala:205-225,375-393`；`sifive-cache/.../InclusiveCache.scala:240-323`；`Scheduler.scala:127-143`。本次 DCache diff 改动 store replay/metadata/TL `TtoN` 及诊断；L2 相关代码当前不在未提交 diff 中，仍属于实际静态协议。
- Git 现场：14 个已跟踪文件有 unstaged 修改，`git diff --cached --name-only` 为空；原有 untracked Debug 资料保持原样。本报告和 `fresh_459000_*` 定点抽取均仅新增于 `Debug/`。
- 当前 FST 的原始定点证据：`Debug/fresh_459000_preboundary_commit_392700_392855.txt`、`fresh_459000_pc_boundary_392825_393160.txt`、`fresh_459000_checker_pc_393080_393720.txt`、`fresh_459000_packet_route_393080_393285.txt`、`fresh_459000_lsl_head_393250_393700.txt`、`fresh_459000_lsl_invariants_fullrun.txt`、`fresh_459000_barrier_fullrun.txt`、`fresh_459000_l2_barrier_fullrun.txt`、`fresh_459000_l1barrier_396700_397250.txt`、`fresh_459000_result_release_fullrun.txt`。用只读 `AI/Debug/fst_signal_trace test.vcd START END REGEX...` 从同一 FST 抽取；没有运行仿真或生成 RTL。

## 9. Ruled-out / 未证明假设

- **Ruled out（首因）**：L2 barrier 已启动、ACK 错误或 TL C 停顿导致首坏 PC。全程 L2 `barrierActive/barrierRequest=0`、BOOM `barrierServiceActive=0`；L1 pending 首次出现于 `396827`，比首坏晚。不能据此断言 cache/TL 的所有后续行为正确。
- **Ruled out**：当前 LSL 从未 prefetch、CDC 没有将 store 送达、seq=1 未分配。当前 FST 分别可见 `deq_read=1`、LSL 入队与 `packet_seq=1`。
- **Ruled out（本包首因）**：BOOM 在快照后合法回跳到 `0x4ac`。其有效 head/提交 PC 依次为 `0x368` 及后续顺序路径，`0x4ac` 已在分配前退休。
- **Candidate、尚不归因**：其它 packet 的 store token/replay、TL sideband 或地址统计风险；本次不需要假定它们有错，就能解释首坏和最终 watchdog。先前 Debug 文档及其它旧波形不是当前运行的事件证据。

## 10. Confidence

快照 PC 错位、LSL payload/valid 违例、result/release 未发生及 watchdog 传播均为 **Confirmed**（源码、生成 RTL、当前 FST、软件反汇编相互吻合）。`396827` L1 pending 是下游放大为 **Confirmed**；L2 barrier 作为当前首因是 **Ruled out**。仅“修正其中一个缺陷后仍会如何运行”的反事实属于未验证范围。

## 11. 下一阶段应处理的机制 / invariant（不含实现方案）

需要维护以下边界契约：空 ROB 快照的 PC 必须是与同一批 committed ARF 对应的下一架构 PC，且跨延迟捕获稳定；LSL 每个 bank 的 `head_valid` 必须代表可保持、可比较的同一 payload，读请求、dequeue、响应各有清晰 fire；包序号与提交记录、CDC、checker 重播、result release 一致；cache 旧包脏行与新包写、TL C 完成、metadata 清理、安全水位，以及 L2 close ACK 与 PASS 的关系不可混淆。
