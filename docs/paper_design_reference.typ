#set document(
  title: "Cache-Image Preservation and Correction Framework Reference",
  author: "基于当前工作树 RTL/Scala/Chisel 的静态分析",
)
#set page(paper: "a4", margin: (x: 18mm, y: 17mm), numbering: "1 / 1")
#set text(lang: "zh", size: 10.5pt)
#set par(justify: true, leading: 0.72em)
#set heading(numbering: "1.1")

= Cache-Image Preservation and Correction Framework

本文是面向后续 DAC 论文 Section 3/4/5 写作的代码级参考，不是论文正文。分析对象是当前工作树中的 BOOM L1 DCache、Rocket-Chip TileLink 扩展和 SiFive InclusiveCache L2。这里的“纠错”具体指：在 GuardianCouncil package 验证状态变化时，安全地保存旧 cache image、约束新 image 的物理生效，并在完成必要的 lower-level transfer 后释放旧 owner。已检查路径中没有发现 ECC syndrome 到数据位修复的机制；不要把本文描述成 ECC repair。

证据标记：*[CONFIRMED]* 表示当前源码可直接确认；*[INFERRED]* 表示由多个代码路径共同推得、但源码没有单点直接声明；*[OPEN QUESTION]* 表示当前实现、验证或系统契约不足以确认。源码行号以本工作树当前版本为准。当前工作区包含未提交实现；Stage 3 的最新状态为 `PATCHED_PENDING_REBUILD`，因此源码结构结论与硬件闭环结论必须分开。

= Framework Overview

== Design Goals

- [CONFIRMED] 给每个由 BOOM 本地语义写产生的 cache image 标注 writer、generation 和 GuardianCouncil package sequence，使数据身份与 TileLink source ID、权限状态分离。代码定义的 image key 是 81 bit：`valid:1 + writer:16 + generation:32 + contentSeq:32`。`BASE` 表示 coherent lower-level image；`contentSeq=0` 表示被视为安全的 trusted image。证据：`chipyard/generators/rocket-chip/src/main/scala/tilelink/CacheImage.scala:6-20`、`chipyard/generators/boom/src/main/scala/lsu/dcache.scala:2341-2364`。
- [CONFIRMED] 新写只有在 resident owner、image identity 和 preservation predicate 都匹配时才进入 L1 data-array 写口；对同一效果 token 的重复 replay 返回记录结果而不重复物理写。证据：`chipyard/generators/boom/src/main/scala/lsu/dcache.scala:2082-2107,2159-2199`。
- [CONFIRMED] dirty L2 image 在尚未安全或尚未有 exact-image lower receipt 时，不得因同址版本替换、ProbeAckData 安装或 set victim 流程而丢失。L2 对同址改写用 non-destructive A-channel checkpoint，对 set eviction 用 C-channel Release/ReleaseAck。证据：`chipyard/generators/sifive-cache/design/craft/inclusivecache/src/L2Preservation.scala:19-22,57-60`、`Scheduler.scala:127-195`、`MSHR.scala:576-619`。
- [CONFIRMED] transaction completion 与请求身份绑定。L1 voluntary writeback 要求完整 C 传输和匹配 `CacheImageKey` 的 D ReleaseAck；L2 checkpoint 和 victim 各自使用 64-bit transaction serial，且 victim 还要求实际 last C beat 已被外部接受。证据：`dcache.scala:69-88,1369-1382`、`L2Preservation.scala:118-150`、`MSHR.scala:576-609`。
- [INFERRED] 这些机制共同实现 state preservation、speculative visibility control、exactly-once data effect 和 replacement completion ordering；它们不是对任意协议错误进行回滚的通用恢复器。

== Major Components

- `BoomL1DCache`（`dcache.scala`）：持有 per-set/way image identity、epoch、lower receipt、effect token、slot reservation 和 completion state；在 S2 admission、S3 data-array write、refill、probe invalidate、victim writeback 和跨 package shadow clear 上实施互锁。
- `BoomWritebackUnit`（`dcache.scala`）：读取并缓冲一条 L1 line，发送 voluntary `ReleaseData`，保存被发送 image key 与 epoch，等完整传输及下层 receipt 后报告 `done`。
- `BoomMSHR` / `BoomMSHRFile`（`mshrs.scala`）：保存 refill image、事务 owner、write-domain sequence 与 RPQ 请求；维护有限 drain 阶段、replay owner/result matching 和 refill/writeback 时序。
- `CacheImage` / `CachePreserveTxn`（`tilelink/CacheImage.scala`）：分别表示 cache 内容身份与一次 preservation transfer 的 completion echo。image key 经 TileLink user field 传播；transaction serial 经 echo field 传播。
- `InclusiveCache.Directory` / `MSHR`：directory 保存 line image、dirty/permission/client 与 `outerPreserved` receipt；MSHR 负责 victim plan、inner probe、Release、ACK matching 及最终目录更新。
- `Scheduler`、`SinkC`、`SourceC`、`SourceD`、`SinkD`、`BankedStore`：在 L2 入站 ProbeAckData、内部 A 写、bank 写读和外部 C/D/A 传输之间实施 admission、set lock、SRAM 排序和 ACK 生成。
- `L2Preservation`：每个 L2 bank 一个共享 checkpoint engine；读出已确认安全的 dirty image，发完整 line `PutFullData`，只在匹配成功的 `AccessAck` 后向 owner MSHR 回报 exact-image receipt。
- TileLink endpoint/adapters：`InclusiveCache.scala` 协商 user/echo metadata；`CacheCork.scala` 转换 ReleaseData 与 Put 并转发 echo；`TLToAXI4.scala` 和 `AXI4UserYanker.scala` 在 AXI B response 恢复 request echo；当前 harness 的 `Serdes.scala`、`TLRAM`/`TLROM` 也需透传 echo。动态端到端有效性尚未完成当前 Stage 3 重建验证。

== End-to-End Flow

=== Validation and L1 write path

1. BOOM DCache 接收 LSU store/AMO/SC。`CacheImage.safe(key, watermark)` 的 predicate 为：

```text
safe(key, W) = !key.valid || key.contentSeq == 0 || key.contentSeq <= W
```

`W` 是已连续 PASS 的 package watermark，不是简单的“最近 PASS package”。L1 通过 allocation/completion/PASS bitmap 只推进连续前缀，并将 Gray-coded watermark 跨域送往 L2。证据：`CacheImage.scala:18-20`、`dcache.scala:1617-1726`、`InclusiveCache.scala:244-258`。

2. S2 对 hit store 计算 `L1Preservation.allow`。同 package（`incomingSeq != 0 && old.contentSeq == incomingSeq`）可以继续更新；否则旧 image 必须已经安全，且 incoming seq 非零时旧 image 必须已有 lower copy。若不允许，store nack/retry；跨 package owner 可能进入 shadow writeback 流程。证据：`phase1.scala:69-82`、`dcache.scala:1449-1498`。

3. S3 data-array 写口再验证 resident/replay owner、epoch、image generation、preservation predicate、kill/duplicate 条件。物理 `dataWriteArb.io.in(0).fire` 才是 semantic effect；随后 generation 递增、写入新 key、清除 `lowerPreserved`。证据：`dcache.scala:2082-2107,2159-2199,2228-2234,2341-2368`。

4. 跨 package predecessor 若不能直接覆盖，L1 锁存 set/way/tag/epoch/key，阻止同 line 新 store，并等待 old package 安全；待已有 owner、probe、completion 和流水线冲突排空后，复用 `BoomWritebackUnit` 发送旧 image。只有 C 全部发出、D 为正确 opcode/size、未 denied/corrupt 且 `CacheImageKey` 完全相等，WB 才置完成；DCache 核对 epoch/key 后标记 lower-preserved，再提交 metadata clear/invalidate 并推进 epoch。证据：`dcache.scala:69-88,1426-1498,1509-1597`、`dcache.scala:1369-1382`。

5. 被 nack 的 LSU store 之后通过正常请求路径重新进入；miss/refill/replay 沿 MSHR owner、transaction token、slot epoch 和 image identity 继续。该请求生命周期由真实 BOOM pipeline/MSHR 决定，本文不将静态状态推导当作动态 closure。

=== L2 same-line checkpoint

1. `SinkC` 从每个 C beat 直接取得 `CacheImageKey`，并检查一笔 multibeat transaction 内 identity 不变。对首个带数据的 ProbeAck，Scheduler 在 bank write 和 response metadata 更新之前计算候选；不同 key 且旧 L2 image 被 `L2Preservation.blocked` 判定时，`probeAllow` 为 false，`SinkC` 不接受该首 beat。
2. 同址 `ReleaseData` 或成功的 trusted A Put/AMO 若将改变 resident image，也会形成候选。block predicate 为 `!safe(old) || (dirty && !outerPreserved)`。安全但 dirty、且没有 exact receipt 的旧 image 需要保存；unsafe image 等 watermark 变化。
3. 候选 MSHR quiescent 后，Scheduler 等 `SourceD`/`SourceC` pipeline idle、SinkC bank address 空闲，再冻结候选并占用该 set。checkpoint FSM 用 SourceC 侧 bank read port 逐 beat 取 line，发单独 source ID 的 A-channel `PutFullData`；data/beat/serial 在背压期间保持稳定。
4. `L2Preservation` 只有在所有 A beat 已送出后才接受匹配的 `AccessAck`：source、opcode、size、64-bit `CachePreserveTxn` echo 均匹配，且 response 未 denied/corrupt。完成后通知 MSHR，给同一 key 设置 `outerPreserved`。后续数据身份变化会撤销 receipt；校验 watermark 变化本身不改 key 或 receipt。

证据：`L2Preservation.scala:19-22,47-60,74-124,125-153`、`Scheduler.scala:127-189`、`SinkC.scala:80-98,113-137`、`MSHR.scala:611-620`。

=== L2 replacement / victim release

1. Directory hit/miss 和 LFSR victim selection 产生 MSHR plan。若 miss victim 有 resident state，MSHR 先完成需要的 inner probes；若 victim dirty 且没有 receipt，外发 `ReleaseData`，否则发送 data-free `Release`。证据：`Directory.scala:122-147`、`MSHR.scala:696-767,356-368`。
2. victim dirty image 的 outer Release 在 image safe 前不能被调度。Scheduler 将 actual last C beat handshake 的 txn echo 送回对应 MSHR；`ReleaseAck` 只有在 `releaseIssued`、`releaseSent`、generation/echo 匹配且未 denied 时才完成。
3. `s_acquire` 等待 `w_releaseack`；directory final write/reload 需要 `no_wait`，也包含 `w_releaseack`。因此旧 tag/data ownership 保留到 terminal completion 后，new Acquire/refill 和最终 tag replacement 才继续。证据：`MSHR.scala:137-160,208-239,576-609`。

== Figure Blueprint

建议绘制双层、分离 same-line 与 set-victim 过程的图：

```text
GuardianCouncil package alloc / checker PASS
                 | seq, PASS
                 v
 BOOM L1 bitmap --> contiguous safe watermark (32b, Gray CDC) --> each L2 bank
       |                                                        |
       | CacheImageKey {writer, generation, contentSeq}         | same key + watermark
       v                                                        v
 L1D S2 admission -> S3 effect gate                         L2 Scheduler gates
       |                                                        |
       +--> data array / MSHR / RPQ                       +-----+------+
       |                                                  |            |
       | L1 C ReleaseData / ProbeAckData                  | same-line  | set victim
       v                                                  | checkpoint| Release path
 L2 SinkC -> directory/MSHR -> BankedStore                 v            v
       ^                                          L2Preservation      SourceC
       |                                          SRAM read + snap   ReleaseData
       |                                          A Put + txn echo     |
       |                                              |                |
       +--------- matching completion/receipt <------+----- outer memory
                                                          AccessAck / ReleaseAck
```

图中区分两类 metadata：`CacheImageKey` 描述 bytes 的来源/版本并跟随 A/C/D user field；`CachePreserveTxn` 描述单次 checkpoint/victim completion，跟随 echo field。还应画出 L2 per-set lock 到 Scheduler request admission、SinkC first ProbeAckData、SourceD/SourceC/SinkD 物理写入保护的控制箭头。

= Correction Framework Design

== State Identification

`CacheImageKey` 的语义在代码注释和 predicate 中可确认：

- `valid=0` 且全 key 为零：`BASE`/coherent lower image；`CacheImage.base` 在 A/C 构造时清零该字段。
- `valid=1`：本地 authored image；`writer` 区分 writer namespace，`generation` 是本地语义写 serial，`contentSeq` 关联 package 生命周期。
- `contentSeq=0`：trusted safe write；非零 seq 在 `seq <= safePacketWatermark` 后才 safe。
- L1 的 `lowerPreserved` 表示当前本地 image 的下层副本收据是否仍有效；每次 semantic write 清除，Refill 设置，跨 package WB 成功并匹配 resident owner 后设置。
- L2 的 `outerPreserved` 是与当前完整 image key 绑定的 receipt。clean coherent refill 设为 true；dirty semantic change 或不同 image 的更新不能继承旧 receipt。

证据：`CacheImage.scala:6-28`、`dcache.scala:572-577,1239-1245,1287-1298,2341-2364`、`MSHR.scala:285-290,323-338`、`Directory.scala:28-43`。

`slotEpoch`、`lineGeneration`、MSHR transaction token 与 replay request/effect token 分别回答“物理 slot 是否还是原 owner”“当前内容是否同一 image”“MSHR allocation 是否同一事务”“该语义 effect 是否已应用”。不应以单个 source ID、tag 或 packet sequence 替代这些身份字段。证据：`dcache.scala:556-586,1160-1170,1220-1303,2082-2107`、`mshrs.scala:122-134,182-208`。

== Correction Eligibility

L1 overwrite predicate（直接来自 `L1Preservation.allow`）：

```text
samePackage = old.valid && incomingSeq != 0 && old.contentSeq == incomingSeq
allow       = !present || samePackage ||
              (safe(old, watermark) &&
               (incomingSeq == 0 || lowerPreserved))
```

其效果：同 package 可以连续产生新 generation；其他 package 的写要求旧 image 已安全，且 incoming 为 authored image 时旧 bytes 已有 lower copy；BASE/trusted replacement 只要求旧 image safe。它不等价于“比较 generation 大小”，也不做版本排序；版本身份由完整 key 与 owner 生命周期维护。

L2 candidate/block 逻辑：

```text
blocked(old) = !safe(old.image, watermark) ||
               (old.dirty && !old.outerPreserved)

candidate = destructive_same_line_change && blocked(old)
checkpoint = candidate && safe(old.image) && dirty && !outerPreserved && drained
```

`destructive_same_line_change` 在代码中分三类：不同 key 的 inner `ReleaseData`；成功的 trusted A write；不同 key 的首个带数据 ProbeAck。相同有效 authored key 作为 immutable transport copy 不触发 checkpoint。`BASE` 不走 identical-authored-key 优化；trusted A 更新总会撤销旧 receipt。

证据：`phase1.scala:69-82`、`L2Preservation.scala:19-22,57-60`、`Scheduler.scala:127-155`、`MSHR.scala:323-338`。

== State Preservation

L1 跨 package 流程冻结的 descriptor 是 set/way/tag/epoch/key。候选必须仍是同一个 resident slot；任何 MSHR owner、S1/S2 pre-freeze 请求、S3 held effect、completion、probe、或 pending WB 都会延迟 checkpoint/clear。WB ACK 只允许 exact key + exact epoch 完成；同一行在 pending 阶段的写会 nack/retry。对已经在该 line 上的同 package MSHR secondary，MSHR 另比较 `writeDomainSeq`，拒绝不同 package 的 secondary 加入旧事务；RPQ drain 期间关掉 secondary admission，RETRY 保留 RPQ head 与 SDQ owner。证据：`dcache.scala:1426-1498,1519-1597,2108-2158`、`mshrs.scala:153-180,182-220,285-316`。

L2 checkpoint 不先改 directory 或 data SRAM。`snapshot` 保存 tag/set/way、image、dirty、receipt、reason；锁覆盖捕获、bank read、multibeat Put、匹配 ACK 和 ACK 更新周期。收到成功 completion 后，只给相同 set/way/tag/key 的 resident 设置 receipt。证据：`L2Preservation.scala:49-85,118-153`、`Scheduler.scala:175-189`、`MSHR.scala:611-620`。

== Victim and Replacement Handling

Directory replacement 发生在新请求 miss 且选中的 resident way 有效时；victim 来自 directory LFSR victim selection，不是 correction FSM 自选。MSHR 用 victim 的 tag/way/dirty/receipt 做 Release plan。干净且 lower copy 已存在、或 dirty 且有 exact receipt 时可以 data-free Release；dirty 且无 receipt 时发送 ReleaseData。victim 的 `releaseSnapshot` 防止 pending ACK 期间 resident metadata 变化。

旧实现中的“先 schedule Release、再 invalid directory、ACK 前允许 Acquire”在当前 Stage 3 MSHR 中被改成等待实际 terminal ReleaseAck：`s_acquire.valid` 需要 `w_releaseack`，最终 directory write 由 `no_wait` 约束，`no_wait` 又包含 `w_releaseack`。真实 C last beat handshake 由 Scheduler 产生 `releaseSent`，再与 `releaseGeneration` echo 一起匹配。证据：`MSHR.scala:113-116,208-239,576-609`、`Scheduler.scala:207-219`。

[CONFIRMED] Stage 3 方向上 refill 不能越过 victim ACK；[OPEN QUESTION] 这条修改后的完整协议目前还未在最新 source identity 下完成 directed/system run，因此动态证明 pending。

== Speculative-State Protection

L1 speculative 判定不是 branch speculation bit，而是 image 的 `contentSeq` 相对功能 PASS watermark 是否安全。L1 store/replay 在 S2 和 S3 共用 preservation predicate；写前先冻结或 nack，不安全 image 不能被其他 package/trusted image 覆盖。Refill 有 owner token/epoch/image 校验；已有 resident slot 的同址 image copy 还要通过 `copyAllowed`，新 owner 则由 reservation、epoch 和 MSHR victim/writeback 顺序保护。`BoomMSHR` 将 GrantData 首 beat捕获的 image 复用于后续 beat，并断言各 beat key 一致；denied/corrupt refill 不能被认证。证据：`mshrs.scala:158-166,365-373`、`dcache.scala:1220-1303,2162-2178`。

L2 outgoing dirty victim 的 C request 与实际 C beat 都断言 `CacheImage.safe`；same-line checkpoint A Put 也在发出时检查 safe。普通外部 observation 受 L1/L2 的 coherent ordering 与 lower completion gate 控制。证据：`SourceC.scala:172-180`、`L2Preservation.scala:104-124`、`Scheduler.scala:542-556`。

这里的 barrier 是物理效果/发送 gate；它不提供 FAIL rollback。package FAIL/CANCEL 是否需要丢弃、保留或重放尚未 safe image，不能从上述 gate 推出完整系统恢复语义。

== Concurrency and Ordering

- L1 same-line / same-slot：epoch 与 owner tuple 阻止 stale S1/S2/replay 在 way 被重分配后写入；S3 held grant、clear、probe invalidation、refill 和 completion drain 互锁。`completionPending` 阻止同 slot 另一终端责任重叠。
- L1 replay concurrency：RPQ head 被 `hold_head` 保留直到非-RETRY terminal；`resultMatches` 同时比较 MSHR、transaction、request/effect token、SDQ、way、epoch。STALE completion 触发 assertion。证据：`mshrs.scala:182-220`。
- L1 concurrent stores：同 line secondary 继承 MSHR owner；不同 `writeDomainSeq` secondary write 不准加入；两个 RPQ drain phase 关闭新 secondary，避免 drain 集合无限增长。证据：`mshrs.scala:158-180`。
- L1 Probe/WB/refill race：`probeDrainReady` / `victimDrainReady` 等 S3 与 completion；refill / metadata write 还检查 S1/S2 pre-freeze、WB 和 slot reservation。证据：`dcache.scala:1230-1238,1313-1324,2148-2158`。
- L2 same-line collision：ReleaseData、ProbeAckData 和 trusted A 更新在最早的 directory write / bank address 接受点前走共同 blocked predicate；ProbeAckData 在 SinkC first beat 前 gate，SourceD trusted write 由 Scheduler gate；receipt 更新周期也断言没有 simultaneous directory/reload/probe/nested metadata change。证据：`Scheduler.scala:127-189`、`SinkC.scala:85-98,113-157`、`MSHR.scala:611-619`、`InclusiveCache.scala:532-537`。
- L2 same-set requests：pending checkpoint 锁 set，阻止新的 A/X/C request；跨 set 可以继续，但 checkpoint engine 与 SourceC bank read port 是 per-bank shared resource。证据：`Scheduler.scala:175-189,343-351,515-518`。
- L2 refill/release race：MSHR retains victim plan until matching ReleaseAck；Acquire/refill and final directory write wait for ACK. SourceD 对 final bank write 与 ReleaseAck enqueue 同步，D ACK 不可提前于最后的真实 bank write。证据：`MSHR.scala:576-619`、`SourceD.scala:292-330`。
- 多 beat / backpressure：SourceC 对每个队列 beat 带 image/txn metadata；L2 checkpoint beat/data 在 `a.fire` 才推进；L1 WB `allSent` 与 D ACK 分开。source reuse 不由单独 source ID 认证。证据：`SourceC.scala:83-180`、`L2Preservation.scala:95-145`、`dcache.scala:66-88`。

== Correctness Invariants

=== Invariant 1 — L1 Effect Ownership

`dataWriteArb.io.in(0).fire => owner_match && image_match && preservationAllowed && !duplicate && !killed`。replay owner 同时约束 MSHR/transaction/request/effect/SDQ/way/epoch；fresh physical write 才能换 generation。若被破坏，旧 replay 可能把 stale data 写入已重分配 slot，或重复应用 AMO/SC。

证据：`dcache.scala:2082-2107,2159-2199,2228-2234`；assertions `held write grant owner revoked`、`write grant has stale image dependency`、`write grant bypassed L1 preservation`；辅助定向证据：`AI/Debug/scripts/stage2/stage2_test.cpp:168-207,263-309`。Stage 2 历史系统 trace 在 `AI/Debug/state/current_debug_state.md:74-89`。

=== Invariant 2 — Unsafe Predecessor Preservation

若 resident old image unsafe 且 incoming 不是同 package image，则 L1 semantic write/refill/clear 不能覆盖它；L2 destructive same-line update 不能进入 directory/bank effect，直到 predecessor safe 且 dirty bytes 已有 exact lower receipt。

证据：`phase1.scala:69-82`、`dcache.scala:1449-1470,1239-1298,2162-2178`、`L2Preservation.scala:19-22`、`Scheduler.scala:127-195`。可见断言包括 `same-address refill would destroy an unpreserved image`、`refill bypassed L1 preservation`、`write grant bypassed L1 preservation` 与 L2 physical-effect guards。辅助测试：Stage 2 `cross_package_wait_safe_then_receipt` / `speculative_refill_replay_gate`（`stage2_test.cpp:283-309`）；Stage 3 `repeated_speculative_same_line` / `speculative_set_victim_blocks_outer`（`stage3_test.cpp:246-290`）。违反会造成正确旧 bytes 被 speculative 新版本覆盖或外泄。

=== Invariant 3 — L2 Checkpoint Completion Before Same-Line Mutation

对于 safe dirty image `P`，若它尚无 exact receipt，则新的不同 image `Q` 不得改变 directory identity 或 bank bytes，直到 `P` 的完整 checkpoint Put 收到匹配成功 ACK；成功仅给被捕获完整 key 的 resident 设置 receipt。

证据：`L2Preservation.scala:74-124,125-153`、`Scheduler.scala:175-189,532-537`、`MSHR.scala:611-620`。关键断言：snapshot 稳定、serial 未耗尽、Put 首 beat 唯一、ACK 完整匹配、receipt 周期没有 concurrent mutation。辅助 directed case：`same_line_safe_dirty_wait_ack`、`delayed_ack_freezes_predecessor`、`outer_backpressure_exactly_once`、`stale_ack_ignored`（`stage3_test.cpp:203-236`）。违规会导致只排队未完成的下层写被误当成旧版本已保存。

=== Invariant 4 — Victim Reusable Only After Matching ReleaseAck

victim tag/ownership 及其替代 refill 在 dirty ReleaseData 全部发送且 matching successful ReleaseAck 前不得提交 directory final state 或 Acquire。

证据：`MSHR.scala:208-239,576-609`、`Scheduler.scala:207-219`。断言：`L2_PREMATURE_OVERWRITE_ERROR acquire`、`L2_PREMATURE_OVERWRITE_ERROR victim tag`、`L2 pending victim identity changed`、`L2_DUP_PRESERVE_ERROR victim`。辅助 tests：`safe_dirty_set_victim_wait_ack`、`validated_victim_preserve_ack_replace`、`stale_ack_ignored`、`flush_clear_normal_writeback_barrier`（`stage3_test.cpp:281-309`）。违规会使 refill 覆盖仍是唯一正确副本的 victim。

=== Invariant 5 — ReleaseAck Follows Real Data Commit

L1/L2 ReleaseAck 只能在对应数据 transaction 的最后必要效果完成后生效；L1 还要求 full C transfer；L2 victim 要求真实 outer last-C handshake；L2 inner SourceD ReleaseAck 要求最终 BankedStore write 接受。

证据：`dcache.scala:69-88,1371-1374`、`Scheduler.scala:216-218`、`MSHR.scala:576-609`、`SourceD.scala:292-330`。断言/trace：`WB receipt before full C transfer or duplicate receipt`、`ReleaseAck before final bank commit`、`STAGE2_TX LOWER_COMMIT`、`STAGE3_TX L2_VICTIM_ACK`。违反会过早释放保存责任或丢失数据。

=== Invariant 6 — Denied Operation Has No New Image Effect

denied trusted A write 不得退休到 bank write/bypass，也不得把 resident speculative identity 重新标成 BASE；directory/data identity 保留原 image。

证据：`SourceD.scala:99-103,292-330`、`MSHR.scala:294-338`。Stage 2 directed test 有 `denied_a_put_preserves_image` 和 `denied_a_amo_preserves_image`，测试 oracle 同时检查 directory key/state/dirty、response 与 bank writes（`stage2_test.cpp:219-255,378-384`）。违反会使 denied 事务产生不可见的数据变更或污染 image provenance。

= Implementation

== Modified Hardware Structures

#table(
  columns: (1.25fr, 1.45fr, 2.2fr, 1.6fr, 1.5fr),
  [Module], [Original role], [Added/changed mechanism], [State / metadata], [Purpose],
  [`BoomL1DCache`], [L1 tags/data/LSU request arbitration], [S2/S3 preservation gate；epoch owner reservation；refill/writeback/probe drain；跨 package shadow clear], [per set/way key、epoch、generation、receipt、effect token；global watermark 与 pending descriptor], [不让错误 owner 或 unsafe image 改写 resident bytes],
  [`BoomWritebackUnit`], [Probe/voluntary release data collection], [voluntary WB 等 full C transfer 与 exact D receipt；source 未完成时不复用], [buffered line；pending key/epoch/index；allSent/acked/ackPending], [为 L1 lowerPreserved 提供 terminal receipt],
  [`BoomMSHR` / `BoomMSHRFile`], [miss、refill、victim、secondary、RPQ], [refill key 验证；跨 package secondary 拒绝；RPQ retry owner lifecycle；terminal exact-once], [refill image；transaction/write domain；RPQ owner tuple；effect/request tokens], [保留 request 与物理 slot/line image 的因果关系],
  [`DirectoryEntry` / `MSHR`], [L2 permission/client/dirty tracking 与事务 plan], [directory image + exact outer receipt；victim snapshot/ACK serial；same-line preservation candidate completion], [每 line CacheImageKey 与 outerPreserved；每 MSHR releaseGeneration/issued/sent/snapshot], [关联缓存内容身份、coherence state 和外部副本],
  [`Scheduler` / `SinkC`], [L2 请求 arbitration、C ingress、MSHR 调度], [same-line candidate、first ProbeAckData gate、set lock、quiescent/drain 选择、unsafe victim schedule gate], [candidate key/reason；checkpoint lock；per-set admission 条件], [在最早破坏性效果前挡住 destructive transaction],
  [`L2Preservation` / `SourceC`], [L2 外发 C 与 BankedStore data read/write], [新增共享 checkpoint A Put FSM；C queue carrying key/txn/first/last metadata；outer-safe asserts], [7 个状态、64-bit serial/lastAck、beat、单 outer-beat data reg、snapshot metadata], [先把安全 dirty predecessor 写至 terminal outer memory],
  [`SourceD` / `SinkD`], [L2 trusted A write/Grant 与 D response path], [denied write不退休；ReleaseAck 经 2-entry queue 且晚于最终 bank write；D echo/key route], [release ACK queue；SourceD stage commit metadata], [保证 inner data effect 和 completion 的先后],
  [TileLink adapters / test harness], [协议字段、Cork、AXI/串行传输], [user CacheImage + echo CachePreserveTxn 端到端透传；Cork ReleaseData-to-Put echo；RAM/ROM/Serdes echo wiring], [81-bit identity 与 64-bit transaction echo], [让终端 ACK 可鉴别 checkpoint/victim 请求],
)

主要实现证据：`phase1.scala:27-82`、`dcache.scala:547-586,1426-1597,2162-2199,2341-2368`、`mshrs.scala:118-220,343-378`、`Directory.scala:28-43`、`MSHR.scala:89-116,576-619`、`Scheduler.scala:127-219,532-556`、`L2Preservation.scala:24-153`、`SourceD.scala:224-330`、`SinkD.scala:23-83`、`SourceC.scala:24-180`、`CacheImage.scala:11-43`、`InclusiveCache.scala:78-103`。

== Metadata and Lifecycle

#table(
  columns: (1.2fr, 1fr, 1.45fr, 2.35fr, 2fr),
  [Metadata], [Scope / exact width], [Set / capture], [Clear / update], [Lifetime / use],
  [`CacheImageKey`], [每 line identity；81 bits], [L1 semantic write assign static writer + fresh generation + packet seq；L2 directory 从 inner C/新写更新；refill 从 D 捕获], [L1 invalidate/slot release 后 imageValid 清除；L2 invalidate/flush 清零；semantic data change 产生新 key 或 BASE], [跨 A/C/D user field传播；描述 bytes，不描述 permission 或 validation],
  [`CachePreserveTxn`], [echo field；64 bits], [L2 checkpoint capture 时 serial 加一；victim 使用 MSHR releaseGeneration], [checkpoint 完成保留 lastAck 用于 duplicate/stale 诊断；新的 MSHR plan 新 serial；耗尽 assertion], [唯一识别 transaction completion，不能只用可复用 source ID],
  [`lowerPreserved`], [L1 per set/way；1 bit], [successful refill 设置；matching full ReleaseAck 后跨 package WB 设置], [每 semantic write、invalidate、新 owner 清除], [当前 L1 image 在 coherent lower level 已有可用副本],
  [`outerPreserved`], [L2 directory per entry；1 bit], [clean coherent refill；或 exact-image checkpoint AccessAck], [trusted A byte update、不同 key bytes 更新、invalidate 清除；permission-only/validation变化可保留], [该 exact L2 key 的 bytes 已被安全送到 outer terminal],
  [`slotEpoch` / `lineGeneration`], [L1 per set/way；16 / 32 bits], [slot invalidate/reallocate 增 epoch；data effect 分配新的 generation], [对应 owner生命周期更迭；generation 在新语义写生效时更新], [防 stale read/replay/refill 对新 owner 生效；serial exhaustion fail-stop],
  [`transaction_token`, `request_token`, `effect_token`], [MSHR/request/effect lifecycle；transaction 32 bits，effect token 64 bits；request token 由请求结构定义], [MSHR allocation、请求生成、semantic effect grant], [terminal retirement、RPQ cancel/retry lifecycle], [区分 MSHR reuse、request reuse 和重复物理 effect],
  [`safePacketWatermark`], [BOOM global；32 bits], [PASS bitmap 推进连续 package prefix], [reset/baseline 初始化；measurement reset 不应改协议 owner/key], [安全判定输入；Gray crossing 到 L2 每 bank],
  [`L2Preservation.snapshot` / `releaseSnapshot`], [每 bank 单 checkpoint engine / 每 MSHR victim plan], [checkpoint capture 前 drain；victim schedule 时捕获完整 DirectoryResult], [matching success 后释放 checkpoint lock；victim 在计划结束/新事务 boot 时重置], [ACK 等待期间冻结 predecessor identity；不是全 line data duplicate],
)

状态记录与传输 metadata 常被放在多个并行结构中；上表不是净 area 增量，也没有把同一 key 在目录、queue、pipeline 的复制重复汇总成芯片总位数。L1 `safePacketWatermark` 的连续推进依赖 `allocated/completed/passed/seq` 256-slot bitmap；L2 `DirectoryEntry.packetSeq/packetTracked` 是沿用的 package 统计字段，image key 与 receipt 才是当前 preservation 数据身份字段。证据：`dcache.scala:1411-1425,1681-1726`、`Directory.scala:28-43`。

== Control Logic

- L1 `L1Preservation.allow` 在 hit store S2 与 held S3 write effect 两处检查；相关 block 还与 miss allocation、owner stale、slotReserved、completionPending、probe 与 victim drain 逻辑合并。
- L1 cross-package preservation 使用多个 pending/issued/clear 标志实现隐式阶段机：WaitSafe/WaitOwnerDrain -> WB issued -> WB done/receipt -> metadata clear -> request retry。它不是显式 Chisel `Enum`。
- `BoomMSHR` 仍使用 18 个既有状态（如 `s_refill_resp`、`s_drain_rpq`、`s_wb_req`、`s_commit_line`）；本轮关键变化通过状态转换与 admission predicates实现，不能描述为新增 18-state machine。
- L2 `L2Preservation` 有 7 个显式状态：`idle/read/delay1/delay2/send/waitAck/failed`。一个 bank 共享一套 FSM 与 checkpoint serial。
- Scheduler 用 safe/quiescent candidate 优先级选择、SourceD/SourceC idle drain、set lock 与 `stage3Allowed` gate；已有 MSHR round-robin arbitration仍负责计划服务。
- SourceD 增加 depth-2 ReleaseAck queue，且 `earlyD.valid` 等 `s4_ready`；否则 D multibeat lock 与 ACK queue 反压可能互相阻塞。
- 终端匹配分别为：L1 release D 对 `source/opcode/size/key/allSent`；L2 checkpoint D 对 `source/opcode/size/txn/full-send`；L2 victim D 对 MSHR source routing、release generation、issued、last-C sent。

== Data Path Changes

- 没有新增整条 cache line 的专用副本。L1 重用现有 `BoomWritebackUnit.wb_buffer` 路径作为跨 package predecessor export；L2 checkpoint 使用现有 BankedStore，通过 SourceC SRAM read port 逐 beat读出，仅寄存当前 outer beat data。
- 新增 L2 checkpoint A-channel `PutFullData` 数据流。`InclusiveCache` 要求 last-level outer domain 且协商 64-bit echo；`CacheCork` 透传 checkpoint echo，并把 L1/L2 C ReleaseData 转成 A Put；AXI adapter/Yanker 将 echo关联到 B response。
- L2 ProbeAckData 仍由 SinkC 直接写 BankedStore；新 gate 在首个 data beat 的 `c.ready`、`bs_adr.valid` 和 response 之前生效。
- trusted A Put/AMO 的物理 data-array/bank write 仍走 SourceD/BankedStore；新 identity/denied 条件影响 retirement 与 bypass，未替换 atomic datapath。
- replacement Release/ReleaseAck 继续走 SourceC/SinkD，但增加完整身份与延迟 ACK/final directory update 约束；refill 受这条 transaction ordering 影响。

== Potential Timing-Critical Logic

以下是结构风险而非已测量的时序回归：

- L1 S2 nack/MHSR admission 路径上组合 `L1Preservation.allow`、`safePacketWatermark`、selected set/way key、owner/epoch/conflict predicate。
- L1 S3 physical-write enable 将 owner/effect token/image generation/sequence watermark/duplicate/kill 条件相与，可能延长写口 arbiter enable 路径。
- L2 Scheduler 在多个 MSHR 的 directory result、C candidate、trusted A、probe candidate 间做 81-bit key 比较、优先级选择、safe/quiescent 判定，再影响 MSHR schedule ready。
- `preservation.lock` 同时影响 request accept、SinkC probe first beat、SourceD/SourceC SRAM ports、SinkD physical write guard，扩大跨模块 ready/valid 与组合 fanout。
- checkpoint A Put 与 normal SourceA Acquire 共享 outer A arbiter；checkpoint data read 有 SRAM latency、beat counter 和 backpressure hold。
- SourceD final bank write、2-entry ACK enqueue、D-channel arbiter/s4 ready 存在新的 ready/credit dependency。当前代码有意避免在 ACK credit 不足时启动阻塞 D multibeat。

当前没有可归因于上述路径的 synthesis slack、Fmax 或 post-route timing 报告；不得写成已知频率/性能下降。

== Hardware Cost Sources

- 每个 resident cache line/way 需要保存 81-bit image identity 与 receipt/epoch/generation 等状态；TL queues、MSHR snapshots 和 pipeline transaction 中也携带身份字段。
- L1 维持 owner token、effect idempotence 记录、RPQ retry ownership、lower-preserved 状态与 256-entry 功能验证 bitmap。
- L2 每个 directory entry 增加 exact image 与 `outerPreserved`；每 bank 增加 7-state checkpoint FSM、64-bit transaction serial/echo、候选比较、bank lock 控制和 ACK counters。
- SourceC queued beat 增加 image、dirty/provenance、first/last sideband；SourceD 增加 2-entry ReleaseAck queue。
- 额外 transaction latency 来自安全 watermark wait、bank pipeline drain、checkpoint A Put/terminal ACK 与 victim ReleaseAck gate。没有从 RTL 推测 area/power 数字。

= Evidence and Validation Boundary

当前源代码中的断言和 trace marker 包括：L1 `write grant has stale image dependency`、`write grant bypassed L1 preservation`、`same-address refill would destroy an unpreserved image`、`WB receipt before full C transfer`；L2 `L2_SPEC_OUTER_WRITE_ERROR`、`L2_PREMATURE_OVERWRITE_ERROR`、`L2 pending victim identity changed`、`ReleaseAck before final bank commit`。源码位置详见本文件相应章节。

Stage 2 的历史 run 在 `AI/Debug/state/current_debug_state.md:60-89` 记录 L1 preservation 的 build/directed/system PASS 与 trace checker closure；Stage 1 的历史 closure 记录在同文件 `:183-209`。这些结果属于相应 run 的 source identity。Stage 3 当前在 `current_debug_state.md:3-28` 标为 `PATCHED_PENDING_REBUILD`：最新 echo wiring 修复之后尚未重新 Scala compile、elaborate、生成、Verilator 或仿真；Stage3 18 个 directed CASE 是测试源代码覆盖计划，不是当前动态 PASS。此前 Stage2 L1 closure 不能替代新增 L2 path 的当前系统验证。

定向测试源码：Stage 2 fixture 在 `AI/Debug/scripts/stage2/stage2_test.cpp:168-207,263-384` 覆盖 matching/stale/early ACK、package gate、refill/replay、AMO/SC、denied A；Stage 3 fixture 在 `AI/Debug/scripts/stage3/stage3_test.cpp:203-325` 设计覆盖 same-line checkpoint、victim ACK、flush、stale/duplicate echo、backpressure 与 validation 同拍。测试刺激可以验证行为，但不能取代生产 RTL 证据。

= Open Questions

- [OPEN QUESTION] 当前 Stage 3 source identity 尚未完成 fresh build、FIRRTL/组合环、Verilator、18 CASE directed run 和 v1Config system run。尤其是新增 TL echo 在 Serdes、TLRAM/TLROM、CacheCork、AXI B response 的端到端连通性仍待动态验证。
- [OPEN QUESTION] 32-bit package sequence/watermark 的 wraparound、复位/epoch 重建和长期 exhaustion 语义未形成完整的形式化协议；当前 safety 使用无符号 `seq <= watermark` 比较。
- [OPEN QUESTION] `L2Preservation.failed` 在 denied/corrupt matching ACK 后没有源码可见的 retry/rollback transition；当前断言会报告错误，但系统级错误恢复契约尚未确认。
- [OPEN QUESTION] checkpoint engine 在单 bank 共享；安全 runnable candidate 选择的长期公平性、持续背压下 progress 和任意多 MSHR/Probe/Refill 混合流量的无死锁性没有全空间证明。
- [OPEN QUESTION] writer namespace 与相同 package sequence 在多 BOOM writer/多 tile、多 writer 同址并发场景下的唯一性与 merge/recovery 语义，当前资料不足以确证。
- [OPEN QUESTION] `AccessAck`/`ReleaseAck` 是当前终端协议完成，不表示 NVRAM、电源故障或 reset 之后的持久化；若 DAC claim 使用 durable persistence，需要额外系统契约证据。
- [OPEN QUESTION] 本文检查路径未找到 ECC syndrome/data correction pipeline。若论文中的 correction 指数据错误检测/修复而不是 package-version/cache-image preservation，需要明确连接到其他 RTL 模块或重定义术语。

= Source Index

- L1 implementation: `chipyard/generators/boom/src/main/scala/lsu/dcache.scala`, `mshrs.scala`, `phase1.scala`。
- TileLink identity and terminal transport: `chipyard/generators/rocket-chip/src/main/scala/tilelink/CacheImage.scala`, `CacheCork.scala`, `ToAXI4.scala`, `SRAM.scala`; `chipyard/generators/rocket-chip/src/main/scala/amba/axi4/UserYanker.scala`; `chipyard/generators/testchipip/src/main/scala/Serdes.scala`。
- L2 implementation: `chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Directory.scala`, `InclusiveCache.scala`, `L2Preservation.scala`, `MSHR.scala`, `Scheduler.scala`, `SinkC.scala`, `SourceC.scala`, `SourceD.scala`, `SinkD.scala`, `BankedStore.scala`。
- Directed tests/status: `AI/Debug/scripts/stage2/stage2_test.cpp`, `AI/Debug/scripts/stage3/stage3_test.cpp`, `AI/Debug/state/current_debug_state.md`。
