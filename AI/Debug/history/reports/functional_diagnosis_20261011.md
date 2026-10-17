# 当前实现功能诊断：2026-10-11

结论：真实 L2→DRAM barrier 已参与门控并在当前运行中完成释放，但不能据此宣布 cache/coherence 正确。已定位一处 shadow writeback metadata clear 与流水线 store 的 ordering bug，导致已提交 store 被后续 refill 覆盖。main/checker 的两个统计 FAIL 则来自 BOOM package tag 的边界漏计；重建的同包实际访存数量逐包一致。软件到达收尾和 HTIF 退出，但 benchmark 功能失败，且退出时并非所有请求都静止。

本次仅诊断，未修改正式硬件或软件，未重新生成 RTL、编译或运行仿真。方法使用 `/home/guozh/.codex/skills/ec-debug-analysis/SKILL.md`。原有工作树状态 `D AI/debug` 保留。

## 1. 证据身份与时间

- Git HEAD：`a68183c83e08ed837c677aec7836c97895e3a95e`。
- 当前输出：`chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/{test.log,test.out,test.vcd}`；`.vcd` 实际为 FST，范围 `0..9304241`。
- 当前软件 `Software/Test/test.riscv` SHA256：`7d440cced710e16958d0121fcac377d57266c9c54a82845e2d5dc9a3a0a9c686`。
- 日志 SHA256：`79782f0868fee7fb91608ddf3dbcafaa3fc93c4bb001e27f07d41adb463ec8f9`。
- 当前 `test.out` SHA256：`15cfd0a159ac872de18f9c8649421054ca05a82a7960f8b1f18e6b9e05206975`。
- 当前 FST SHA256：`e6da4832429aaf2748706c8ad874534f8d30414fbd50167412a9f606cf59c095`。
- 当前日志和软件与 `AI/Debug/state/evidence/latest/manifest.json` 一致；当前 output/FST 与该旧 manifest 不同。本报告使用当前波形，不把旧报告窗口当成当前动态证明。关键 Scala 源码及 BoomCore 等生成物与旧 manifest hash 一致；当前生成 LSU 已确认包含 LSQ scope 锁存逻辑。尚未建立整机 source→simulator→FST 的完整构建溯源。
- 当前身份清单：`AI/TMP/diagnosis_20261011_current_manifest.json`。

`chipyard/generators/chipyard/src/main/resources/csrc/emulator.cc:337,344` 分别 dump `2*trace_count` 和 `2*trace_count+1`，BOOM 时钟在奇数 timestamp 上升。以下时间均为 **FST timestamp**，不是纳秒，也不是直接的 BOOM cycle；一 BOOM cycle 对应两个 timestamp。FST 值是 eval 后的稳定值；报告中的“接受沿”按下一上升沿的拍前 valid/ready 重建。例如 clear 在 `432469` 后有效，在 `432471` 接受，不能把两种时间标记混用。

## 2. test.log 的全部 FAIL

| 日志位置 | 实际触发逻辑 | 分类 |
|---|---|---|
| 行 17：`store arch=60491 strict=60491 checker=60655 result=FAIL` | `Software/Test/stat/report.c:338,340,357`：总数或 cache/uncache 子类不相等 | BOOM 计数/身份传播 bug；不是 checker 多执行 164 条 store 的证据 |
| 行 20：`load arch=84480 strict=84480 checker=84738 result=FAIL` | `report.c:339,344,348,351,374`：总数、子类或 response/forward 路径分解不相等 | BOOM 少计 258 条 cacheable load；路径分解本身成立 |
| 行 41：`[END] hart=0 status=FAIL` | `Software/Test/test.c:88-91` 打印 `report_end()` 返回值；`report.c:1060,1069` 汇总统计检查 | 上述两个 FAIL 的汇总，不是第三个独立 cache assert |
| 行 6：`verified=0`，没有字面 FAIL | `Benchmark/gapbs/gapbs_bfs.c:368` 检查 source parent、parent 范围和图边合法性 | 真实 benchmark 功能失败；独立于统计 FAIL |

具体算式：store 差值全在 cache 类，`60442-60606=-164`，uncache 两边均为 49。load 差值全在 cache 类，`84183-84441=-258`，uncache 两边均为 297。`82517+1666=84183`，所以 response/forward 分解并未失败；checker 的 `84441+297+0=84738` 也成立。日志没有 traffic-counter underflow/failure、package drain timeout、address-stat invariant failure 或 barrier drop/overflow 的 FAIL。

## 3. main/checker 为何不同：最早统计 divergence

以 `R_IC.producer_open && active_packet_seq!=0` 为包执行窗口，在 BOOM 上升沿采样 ROB 普通架构 store/load，并与各 checker counter 按 `package_seq_reg` 的增量配对：

| 口径 | store | load |
|---|---:|---:|
| BOOM 同包实际退休重建 | 60655 | 84738 |
| checker 汇总 | 60655 | 84738 |
| BOOM arch / strict 打印 | 60491 | 84480 |
| BOOM 漏计 | 164 | 258 |

291 个包的实际普通 store/load 数分别逐包一致。422 个漏计事件全部在 R_IC `fsm_snap=4` 退休，live LSU seq 均为 0。不能由此证明全部指令/数据正确，但它排除了这两个差值来自 checker 额外普通访存的解释。

最早漏计 store：接受沿 `1327493`，seq=103，lane=1，PC=`0x80000820`。seq103 实际/checker store 都为 624，BOOM counter 为 623。最早漏计 load：`3236737`，seq=127，lane=2，PC=`0x80000bdc`。

首个 store 的上游证据更早：

1. `1327161`：STQ11 已有效。
2. `1327167`：R_IC 从 check 进入 postcheck；`producer_open=1`、owner seq 仍为 103，但 `core.io_lsu_active_packet_seq` 已变 0。
3. `1327169`：STQ11 的物理地址 `0x800173e4` 和 `traffic_scope_valid=1` 被捕获，`packet_seq` 却保留 0。
4. `1327493`：该 store 退休，`archStoreEvents_1=0`；稍后 `1327499` 后 DCache 的实际 data-write 请求仍携带 seq=0。

根因链 **已证实**：

- `boom/exu/core.scala:2363` 只在 alloc 或 `debug_maincore_status==2` 时向 LSU 发送非零 seq。
- `rocket-chip/r/R_IC.scala:558` 的 status==2 只覆盖 `fsm_check`，不覆盖仍归旧包的 postcheck/cooling/snap drain。
- `boom/lsu/lsu.scala:1105,1130` 第一次地址生成时锁存 live seq，同时置 `traffic_scope_valid`；零身份因此也被锁存为“有效 scope”。
- `lsu.scala:1841` 退休计数要求 entry seq 非零；`lsu.scala:1893` 的 strict token 资格复用同一个 `arch_store_in_scope`，所以 arch 和 strict 一起少计而仍相等。

当前 `gen-collateral/LSU.sv:5647,5666` 已包含 entry scope/seq 退休门控，`BoomCore.sv:18599` 已包含 status==2 的 seq mux。因此不是仅凭旧波形推断“新 LSQ 修正没有生成”；修正已在当前生成物中，但它锁存的输入身份仍错误。

这是明确的身份传播和统计 bug。它还影响 `address_stats_event`、strict token 和 cross-package 判断：`dcache.scala:1045,1051,1598` 均用非零 seq。首个零 tag store 恰好落在已 tracked 为 103 的 line 上，不能凭这一例断言 unsafe data 已逃逸；但“所有 unchecked state 都被 barrier 覆盖”不能成立为已验证结论。

软件统计 STOP 点也不同：checker 在 `core/checker.c:37,45` 完成状态后停止；BOOM 在 `stat/report.c:1006-1022` 等 checker 快照和 package drain 后停止。动态重建表明本次差值由上述包边界漏计解释，不应加固定补偿数，也不应只调整 STOP 时机。

## 4. 真正 cache/coherence 错误：clear 后旧 hit store 被 refill 覆盖

从 `test.out` 逐条重建 BOOM 寄存器和私有 BFS 数组的 byte memory，最早已定位的架构读写不一致为：

- `test.out:645276`，BOOM 第 153039 条打印 commit，PC=`0x80000784`：向 `0x8005a1e8` 写 `0x1080`。
- `test.out:2549416`，第 227820 条打印 commit，PC=`0x800007c0`：同址读回 `0`，期望 `0x1080`。
- `test.dump:773` 给出 `out_offset` 基址 `0x80059dc8`，故目标为 `out_offset[264]`；`build_graph()` 在 `gapbs_bfs.c:295` 写 `264*16=0x1080`，在行 301 使用此 offset 构造边数组。
- DCache 在 `1776443` 后对同址的 hit response 也显示 data=0，支持错误源于 cache 数据，而非最终 printf。

其更早的 line 事件已完整定位。line=`0x8005a1c0`，set=135，way mask=`01`（way0）：

| FST 时间 | 事件与解释 |
|---:|---|
| 432433 后 / 432435 接受沿 | shadow WB request，old seq1、`param=1=TtoN` |
| 432449..432461 后 | 四个 ReleaseData beats，目标 word 尚为 0，写回的是旧前驱 |
| 432469 后 | metadata clear valid；目标 store `0x8005a1e8` 同时仍在 S1 |
| 432471 接受沿后 | clear 将本地权限清为 invalid，并立即清 `crossPackagePending`；S2 对同址 store 仍持有旧 `coh_state=3`、way mask01、hit=1，nack=0，send_resp=1 |
| 432473 后 / 432475 接受沿 | S3 对同址真正写 data array，word=`0x1080`，way mask01 |
| 432479 后 | 下一 store `0x8005a1ec` 已看到 invalid metadata，走 miss；MSHR3 保存该地址 |
| 432517..432529 后 | MSHR3 `s_commit_line=11`，把同一 line 的旧 refill 数据写回同一 way |
| 432525 后 / 432527 接受沿 | row offset0x20 的 refill data=`0x00000000000000000000107000001060`；含目标 offset0x28 的高64位为0，覆盖 `0x1080` |
| 432531 后 | MSHR3 进入 `s_drain_rpq=12`；后续 replay 从 `0x8005a1ec` 开始，已经成功响应的 `0x8005a1e8` store 没被重放补回 |

**已证实的直接违例**：已成功完成的 store 没有进入 ReleaseData，也没有留在 refill 后的 line，更没有进入该 MSHR 的 replay 恢复，后续架构 load 读到旧值。

**已证实的上游触发**：clear 接受后 pending 立即解除，但 clear 当拍的 S1 访问仍能将旧 metadata/hit 推进 S2；没有对应的 metadata 写冲突 nack 或 line invalidation interlock。源码路径：

- `dcache.scala:695` 的 S1 metadata 冲突处理针对 prober，未把新增 shadow metadata clear 纳入同一 hazard。
- `dcache.scala:726-732` 把 tag/coherence/hit 信息寄存到 S2。
- `dcache.scala:1049-1055,1096-1099` 依靠 pending line 门控，并在 clear fire 立即解除。
- `dcache.scala:1515,1554` 由 S2 旧 hit/nack 派生 S3 array write。
- `mshrs.scala:329-358` 在 commit_line refill 后 drain replay；它不能自行恢复此前被误判为 hit 成功的 store。

**下游放大，强支持**：错误发生在 build_graph，早于 BFS traversal；坏 offset 可使后续边数组写入使用错误下标，继而污染 graph/parent。当前重建保留了前100个 mismatch，但脚本最多保存100项，不能称总共只有100个；也尚未把每个 mismatch 都归到同一首因。

旧 bug 的复核：当前生成 `crossPackageWbReq_bits_param=3'h1`，该 line 的真实 C param 同样为1；全程 shadow WB/metadata clear 观察到153/153。因此历史 TtoB 与 clear 期间重复发起 WB 的症状本次未重现。现在的问题是 clear/pipeline/refill 的隔离范围仍不完整。

修复原则仅供下一步设计：让 shadow invalidation 与已有 probe/MSHR metadata hazard 同样覆盖在途请求；在重新确认 metadata 前禁止 stale-hit store 成功响应/完成，保留原 STQ/token 供重试。不能仅延迟统计清零、把 refill 算为 store 完成，或去掉 barrier 来掩盖此问题。

## 5. barrier 的正确范围与统计含义

可以确认 **L2→DRAM 的真实门控已生效**：

- `InclusiveCache.scala:280-295` 判定 dirty、tracked、nonzero seq 且 seq>safe 的候选；只有 matching close ACK 且 watermark 达到该 seq 才 release。
- `Scheduler.scala:136` 把 `barrier_allow` 接入 C schedule 的实际可执行条件。
- seq105 动态链：`1480251` unsafe candidate/allow0 → `1480253` active105 → `1480261` BOOM service105 → `1480263` R_IC ACK105 → `1483677` safe105/released/allow1 → `1483679` active0。
- `1483677` 是 SourceC **request** 可调度时间；实际 outer C valid 在 `1483683` 后才出现，携带 tracked seq105。request 与外层 beat 不是同一事件。
- 所提取的 L2 dirty DCache request 记录中，没有 tracked seq>当时 safe 的实际 request；本次五次 unsafe candidate 最终均释放。

不能把它推广为“所有 cache/memory 边界都禁止 unchecked”：`test.log:24` 明确打印 L1→L2 `unverified=430,resolved=430`；当前波形也重建到430次 tracked unsafe L1 writeback。`dcache.scala:938,1620` 的 L1 replacement 事件只接入 latency monitor，没有 safe 等待门控。项目当前 `design/barrier_cache_tilelink.md` 与历史方案区分了最终 L2→DRAM 屏障和 L1→L2 理论代价。如果用户要求 L1→L2 同样严格隔离，当前实现明确未实现该约束；按当前 L2 屏障设计，允许进入 L2 是预期行为。

正常路径方面：程序和五个 L2 barrier 都继续前进，未见永久 barrier 阻塞；但不能确认没有不必要的停顿。`Scheduler.scala:136` 的 allow 是所有带 C action 的 MSHR 共用条件，safe/control C action 也可能受当前 barrier 影响，需要独立计数才能量化。

三个 `[BARRIER] PASS` 检查的是 `valid/pending/dropped/seen==resolved` 和包结果，不检查 store 数据保持或 coherence 状态转移。异常大 `cross_package_store seen=394798` 的源码原因是 `dcache.scala:1567-1575` 统计 blocked 从0到1的**重试片段**；同一 store 在 WB/LSU pipeline 交替时可反复产生事件，而实际 shadow WB 为153。`wait_cycle_sum=5736181739` 是这些片段分别等 safe 的累计和，不能当作实际 BOOM stalled cycles 或独立 store 数。L2物理 unverified=0而 barrier seen=5也合理：前者在释放后的真实传输统计，后者在释放前候选处统计。

## 6. 为什么 package 全 PASS，程序却错

`R_LSL.scala:244-251` 给 checker 返回 BOOM 传来的 load data；`R_ELU.scala:93` 的 load error 只比较类型/地址，行101注释明确说明 load data 不比较。store 则在行94比较类型、地址和数据。checker 与 BOOM 可以共同使用已损坏的 load 值继续重放，ARF 也可能一致。

因此291/291/291证明包结果已完成并通过既有 checker 检查，不证明 cache 读值满足此前已提交 store，也不是独立内存参考模型。此处是检查覆盖范围，不应未经设计要求称成 checker 算错。

另有明确 test 缺陷：`test.c:88-91` 的 `[END]` 只汇总 `report_end()`，没有合并 `result->verified`；`main()` 在行105无条件返回0。`emulator.cc:363-385` 依据 HTIF/DTM/TSI exit code 与 timeout 输出 PASSED。即便只修好统计，benchmark `verified=0` 仍可能打印 END PASS 并让 simulator PASS。

当前 checksum=`947892178`；512节点且所有 parent 均合法时 checksum最大只能是 `512*sum(1..512)=67239936`，因此当前结果也不满足合法 parent 的基本上界。按当前 BFS算法做独立 Python参考重建得到 reached512、verified1、checksum43439728；这是算法参考计算，不是硬件回归验证。

## 7. 预期结束与残留状态

已到达 benchmark 收尾、`[END]`、各 checker 软件 idle 和 HTIF `_exit`。`test.out` 尾部 simulator 为 `*** PASSED *** Completed after 4652121 cycles`。这只能确认退出完成，功能验收失败。

最终观察：

- safe watermark=291；barrierActive=0；crossPackagePending/Issued/MetaClearPending 均为0；strictStorePending=0。
- 四个 checker 的 check_active、start_pending、result_waiting、result_outstanding、cleanup_pending 均为0；R_ICSL 为nonchecking=1；LSL quiescent=1。
- 日志所有 validation/writeback/barrier/address-stat pending 检查通过，没有待决包结果。
- L1 512个 set/way attribution 中356个仍 tracked，但非零 seq最大291，没有 tracked seq>safe。这些是已安全归属，不应把 tracked=1本身解释为unchecked残留。零tag访存问题意味着尚不能排除“未被正确归属”的状态。
- DCache WB/prober均idle，六个cache MSHR中只有MSHR3未idle：`state=12=s_drain_rpq`，addr=`0x80007c80=tohost`，`io_fence_rdy=0`；STQ也仍有退出循环的请求。
- 尾部MSHR在`9304221`刚进入refill_req，`9304223`进入refill_resp，`9304235`进入drain；仿真于`9304241`结束。`test.dump:8627-8638` 与当前commit尾部证明 `_exit` 循环反复写 tohost/fromhost。这支持正常HTIF退出尾流，不能把六个timestamp的drain直接判成死锁；也不能宣称全机outstanding request已排空。

## 8. 最值得增加的四组小检查

1. **line ordering assert，最高优先级**：以shadow `{line,way}` 锁定失效事务；记录S1/S2/S3与clear的冲突；断言完成TtoN/clear后不得有未经重新确认metadata的hit write成功。对目标line记录 `{addr,seq,STQ,token}` 与 WB/refill/replay fire，确保已完成store不会被旧refill无补偿覆盖。
2. **身份完整性 assert/stat**：producer_open且属于本包的普通退休访存，必须有正确非零LSQ seq；第一次捕获记录live seq/FSM/ROB/STQ或LDQ；按seq对齐producer retirement、LSQ计数、checker计数。增加 `zero_tag_owned_mem`，防止仅因arch==strict隐藏同源漏计。
3. **真实barrier效果的少量stat/assert**：在L2 outer dirty C first-fire断言tracked seq<=safe；增加未归属dirty writeback计数；分开 `unique {STQ,token}` 阻塞、retry次数、实际blocked cycles。需要判断误阻塞时再加 `safe_C_blocked_by_barrier`。L1→L2是否要同样的安全assert取决于设计边界。
4. **结束验收**：让`verified`与report合并，并传播非零退出码；在进入HTIF退出之前记录checker/result/validation/strict-pending、tracked-unsafe count和DCache ordered/fence/MSHR状态。把该快照与tohost退出尾流分开，避免最终模拟器PASS掩盖功能失败。

目前无需先扩大统计或加很多printf；先修复/验证line ordering，再修复身份源，最后做同软件、同RTL来源的整机功能回归。

## 9. 可复现的窄证据

当前提取工具为 `AI/TMP/diagnosis_20261011_fst_baseline`，源码同目录 `.c`；相对原reader增加baseline读取。临时中间结果保留在AI/TMP，没有删除旧证据。

- `diagnosis_20261011_findings.json`：首个架构读写错误、两类首个漏计、逐包数量核对。
- `diagnosis_20261011_cache_event_table.tsv`：clear窗口的紧凑状态表。
- `diagnosis_20261011_clear_store_baseline.txt`、`diagnosis_20261011_clear_store_control.txt`：`432430..432548` pipeline/clear/refill。
- `diagnosis_20261011_scope_capture.txt`：`1326900..1327496` 首个零身份捕获。
- `diagnosis_20261011_count_first_baseline.txt`：`1327300..1327504` 首个退休漏计。
- `diagnosis_20261011_l2_barrier_chain.txt`、`diagnosis_20261011_l2_barrier_ack.txt`：seq105的门控与ACK链。
- `diagnosis_20261011_requests_final.txt`、`diagnosis_20261011_outstanding_tail.txt`、`diagnosis_20261011_final.txt`：最终状态与退出尾流。
- `diagnosis_20261011_accounting.py`、`.json`：BOOM pre-edge retirement与checker按seq增量核对。
- `diagnosis_20261011_memory.py`、`.json`：私有BFS byte-memory重建；保留mismatch上限100，地址范围之外的并发管理内存不参与该检查。

示例复现（输出写入AI/TMP，不生成RTL或运行仿真）：

```sh
FST_TRACE_BASELINE=1 AI/TMP/diagnosis_20261011_fst_baseline \
  chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd \
  432430 432548 \
  'boom_tile.dcache.(debug_cross_package.*|debug_s[123].*|s[123]_req.*|dataWriteArb.*|metaWriteArb.io_in_2.*|mshrs.io_(refill|replay).*|mshrs.mshrs_3.(state|req_addr))([[:space:]]|$)' \
  > AI/TMP/diagnosis_20261011_reproduce_line.txt
```

尚未验证：所有后续mismatch是否同一首因；零tag访问是否在其他line导致真实未归属数据越界；safe/control C的额外阻塞量；完整构建来源的一致性。没有用compile通过、package PASS或程序退出替代上述验证。
