# 当前 BOOM mshrs.scala 静态审计（2026-10-14）

## 结论与证据边界

**当前实现基本正确；RPQ drain fix 正确；可以继续。** 当前文件逐字等于保存的 closure 版本，也等于真实 prepatch 快照应用已保存增量 patch 后的结果。没有发现后续 agent 回退、混入性能 RTL 修改或删除原检查的证据。无需恢复功能源码。

这个判断针对“已确认保留的 Phase-1 实施 + state12 admission closure”的实现一致性，不代表完整 Phase-1、任意流量下的公平性或整机 BFS 已验证。state3 `s_drain_rpq_loads` 的持续新 load、probe/多 MSHR 竞争和真实 LSU writer opportunity 仍有独立验证边界。本轮未运行仿真，未修改功能源码，未执行 reset/checkout/stash/clean/提交。

本轮证据目录：`AI/TMP/mshrs_static_audit_20261014_131925/`。`source-equivalence.json` 保存源码等价证据；`preservation-check.json` 保存审计前后文件核对；`diff.txt` 和 `hunk-index.json` 是下表的完整 diff 和索引。

## 工作树与正确基线

| 项目 | 结果 |
|---|---|
| HEAD | `a68183c83e08ed837c677aec7836c97895e3a95e` |
| 当前 mshrs.scala | modified，1082 行，无 staged diff |
| 当前 SHA256 | `53a3b2795cccc92268f41b9542fdc248079f6785496a27af875f1c650727ef3b` |
| 相对 HEAD | +334/-48，30 个 context hunks；包含此前未提交 Phase-1，不是 closure 的增量大小 |
| 相对真实 prepatch | +10/-1；只添加 state12 admission gate、解释注释和两条 assertion |
| 全仓库 staged diff | 空；本轮前后保持空 |
| 功能源码保留 | 前置 manifest 的 1461 个 Scala 文件逐个 SHA256 未变化 |
| 默认 generated-src | 前置 manifest 的 6790 个文件 size/mtime 未变化，无新增/丢失 |
| diff whitespace | `git diff --check` exit 0 |

同时存在 dcache.scala、lsu.scala、util.scala、core.scala、prefetcher.scala、Rocket NBDcache.scala 的原 dirty 修改，以及 untracked phase1.scala；全部保留，不能整体覆盖为 HEAD/upstream。完整 status 在 `status.txt`。

基线分三层：

1. 仓库最早 BOOM 导入版本 `431ae2ea2`（0612Orig）与 HEAD：用 `git log/show/diff/blame` 确认项目既有 package 参数、packet_seq/traffic 字段变化；该提交不冒充经核验的纯 upstream hash。
2. 已有 Phase-1 的真实 prepatch：`AI/TMP/mshr_drain_closure_20261014/mshrs.before.scala`，SHA256 `135c7a1dcd5e82f5e616ef7c5c2aaccbfb1bcc24728b8ce70132e0f549f79e7f`。
3. 正确 closure：上述 prepatch + `AI/TMP/rpq_drain_closure_20261014_100756/incremental-fix.patch`，在内存重建后与当前源码相同；保存的 `rpq_drain_closure_20261014_100756/mshrs.before.scala` 实际已含 closure，也与当前相同。独立报告 `mshr_drain_closure_independent_20261014.md` 的 final manifest 记录同一源码 hash。

`git blame` 的未提交标签不能确认具体 agent 作者或修改时间。这里能确认内容来源和一致性，不能声称恢复了所有未提交修改的作者身份。Phase-1 解释采用 implementation notes 的 2026-10-12 closure 修订，而不是已被 supersede 的早期 replay_effect_done/generation 映射。

## Secondary admission 与所有 producer

`mshrs.scala:159–163`：

```scala
val drainAdmissionClosed = state === s_drain_rpq
val sec_rdy = !cmd_requires_second_acquire && !io.req_is_probe &&
  !cross_package_secondary_write && !protocolFault && !drainAdmissionClosed &&
  !state.isOneOf(s_invalid, s_meta_write_req, s_mem_finish_1, s_mem_finish_2)
// line 249
io.req_sec_rdy := sec_rdy && rpq.io.enq.ready
```

以下“允许”仅表示 state gate 允许，还必须满足权限、非 probe、write domain、无 fault、RPQ 空间以及 MSHRFile 的同 set/tag、cacheable、selected valid、SDQ ready 条件。

| 编码 | state | secondary state gate |
|---|---|---|
| 0 | s_invalid | 禁止 |
| 1 | s_refill_req | 允许 |
| 2 | s_refill_resp | 允许 |
| 3 | s_drain_rpq_loads | 允许；早期 drain 的独立活性边界 |
| 4 | s_meta_read | 允许 |
| 5 | s_meta_resp_1 | 允许 |
| 6 | s_meta_resp_2 | 允许 |
| 7 | s_meta_clear | 允许 |
| 8 | s_wb_meta_read | state gate 允许；没有现有有效进入路径 |
| 9 | s_wb_req | 允许 |
| 10 | s_wb_resp | 允许 |
| 11 | s_commit_line | 允许 |
| 12 | s_drain_rpq | 全部禁止，包括新 prefetch secondary |
| 13 | s_meta_write_req | 禁止 |
| 14 | s_mem_finish_1 | 禁止 |
| 15 | s_mem_finish_2 | 禁止 |
| 16 | s_prefetched | state gate 允许；没有现有有效进入路径 |
| 17 | s_prefetch | state gate 允许；当前 finish_to_prefetch 从未置 true，无 reset 可达新入口 |

唯一 RPQ producer 是 line171 的 primary/secondary handshake 且非 prefetch。primary ready 只在 state0/17 为 true，state12 不可能 primary enqueue。MSHRFile line894 产生 sec_val，line957 聚合 sec_rdy，line1053–1055 控制 selected lane ready；line1056 的 block_hit 保持旧 MSHR 同 line 排他性直至 invalid。没有绕过 admission 的内部 requeue 或晚响应 enqueue。

进入 state12 的那个时钟沿仍可接收前一 state 合法 accepted 请求，它已进入旧 owner 的 RPQ，属于有限既有集合。state12 之后新请求不再增加集合。replay.fire 创建的是既有队头的一次执行 attempt，不是新外部 ownership；RETRY 保留原 head，不 enqueue 副本。

## 已 accepted 请求、replay/terminal、SDQ

line179–217 保存 immutable issued descriptor 与 replay_inflight。line503–514 仅在无 in-flight 时 issue；RPQ hold_head 在 attempt 完成前保留 head，terminal 才允许 dequeue。RETRY 清 in-flight 但保留 head，下一 attempt 继续相同 request ownership；APPLIED/CANCEL 为 terminal。未 issue 的分支/exception 取消通过 discarded 退休；已 issue 的取消仍由 matching terminal 退休。discarded 的 `!replay_inflight` 避免同一已 issue owner 双重退休。

resultMatches（line190–202）保留 MSHR ID、transaction、request token/value+valid、epoch、SDQ、way、effect token/value+valid，以及 replay_grant 后的 generation/image 匹配。generation/image 的 inflightGrantValid 条件在真实 prepatch 已存在，没有被 closure 放宽；DCache S2 grant 会更新当前 image，而 S1 kill 可能在未 grant 时形成 cancellation，不能简单改为无条件 generation compare。

SDQ owner 在 enqueue 锁存；line972–989 按 immutable retired descriptor 匹配释放，line1067 检查 replay 的 SDQ owner。不是 replay issue 时提前释放。关闭 admission 不触碰这些路径，未发现新增丢响应、重复 terminal、orphan entry 或复用 allocation 接收旧 completion 的路径。

MMIO writes/AMO 从 D response 后的 held completion 返回；AMO 数据仍在 completion.data，经 DCache terminal response 返回 LSU。`send_resp = isRead && !isWrite` 不能单独作为 AMO 丢响应的证据。

## Publish、退休与收敛

真正 new-line publish 的前置条件在 line522：

```scala
rpq.io.empty && !rpq.io.enq.valid && !replay_inflight
```

该条件、line525–542 的 metadata/E/retire 顺序与真实 prepatch **完全相同**；相对旧 HEAD，Phase-1 增加 `!replay_inflight`，没有降为只检查 RPQ empty。line435 的 meta_write 是 victim invalidation，不是 new-line publish，不能误套 RPQ empty 条件。

DCache line1186–1200 另保留 S3、completionPending、prefreeze S1/S2 drain；有效 metadata fire 后才释放 slotReserved/installActive，并 assert 无 pending functional completion。held GrantAck 由完整 Grant 捕获，从 replay 独立完成；MSHR finish 仍等待其清除。

**state12 drain 可在明确前提下证明收敛**：进入后 accepted work set 不增长，RPQ 至多 nRPQ 项、in-flight 至多一项；取消项自行跳过，terminal 删除一个既有 owner，RETRY 不增加 owner。若每次 attempt 最终收到 matching completion、同一请求 RETRY 次数有限且下游 metadata/E/仲裁最终服务，则有限集合排空并 retire。允许无限 RETRY 或永久不响应时，不能作无条件 liveness 保证。未发现 state12 的 producer 可无限制造新的 owned work。

残留边界不是 closure 回退：state3 允许持续新纯 load，同速 enqueue/dequeue 可让 queue 始终非空，永不到 meta/install；这有源级持续刺激反例，但尚未证明真实工作负载会产生该无限流。它与本次 state12 修复目标不同，应单独验证，不能用 state12 收敛冒充整个 MSHR 必然收敛。

## Store retry 与 writer 公平性

DCache line993 的 nack_miss 仍取 miss 且 MSHR 不 ready。LSU line1654–1690 以 live STQ + functional token 验证 nack，清 succeeded/functional_inflight，必要时 rewind execute head；未删除该 committed store。line721 的重试资格保留，terminal 才标记真正完成。关闭 state12 admission 没有新增另一条丢弃或双重 nack 的路径。

MSHR retire 后，固定同 line 且 resident 未再次驱逐时，polling load 应走 hit，不自动持续新建 read MSHR。因此源码不支持“closure 新增了 load 永远抢 read MSHR”的结论。但 LSU line789–800 本来就给 incoming load/hella/PTW/retry 较高优先级；line1567 附近的 15 周期机制仅压 wakeup。无限 incoming/PTW、多 MSHR 固定优先级流量下 writer 无饥饿没有全局证明，真实 STQ.succeeded 和 tohost 可见性仍需后续定向验证。这不是本轮新性能优先级修改。

## rowValid/rowData 与 LineBuffer/install

所有 row state 写点：

| 位置 | 条件 | 写入 |
|---|---|---|
| 129 | reset | rowValid=false；rowData 无 reset、由 valid 保护 |
| 308 | 新 primary accepted | rowValid=false |
| 480–484 | lb_read.fire && state11 && installStarted && grant_had_data && !protocolFault | rowData=lb_resp，rowValid=true |
| 499 | refill.fire | rowValid=false，refill_ctr++ |

installStarted 在 reset、新 primary 清零，install.fire（line465）置一。rowValid 唯一置一入口要求既有 installStarted；新 primary 同时清二者。因此从 reset 可归纳 `rowValid => installStarted`，普通 state3 load 不能污染 install row。当前只有一个 rowData 写入口，没有多驱动；GrantData 只写 LineBuffer，不写 rowValid。

LineBuffer line796–810 按 MSHR ID/row 编址，write 优先、read/write 互斥；被选 read.fire 才驱动 lb_read_data，每个 MSHR 仅在自己的 fire 捕获。该 MSHR/LB slot 在 retire 前不复用。完整 GrantData 收齐后才进入 load drain/install；无 data upgrade 经过 install handshake 后直接 replay drain，不伪造 row。install read 等 owner active，held row 在 refill backpressure 下保持，last row fire 才进入 state12。

line487 的 addr 仍经 BoomCacheRefill/L1DataWriteReq 的 untagBits 字段用于 array；line489 的 line_addr 从锁存 req_block_addr 携带 block-aligned physical identity，所有 row 稳定。DCache install/refill 的 transaction/MSHR/epoch/way/tag/set/alignment/active owner 检查仍在。未发现普通 load 捕获恢复、旧 row 泄漏或错误事务 LB 数据被 install 的后续改动。

## Assertion 清单

真实 prepatch 19 条，当前 21 条，原 19 条文本全部保留；新增两条 state12 no-accept/no-enqueue。

| 行 | invariant |
|---|---|
| 169 | invalid 时 RPQ empty |
| 175、177 | state12 无 secondary accepted / 无 RPQ enqueue |
| 183 | replay_grant 匹配 issued request/transaction |
| 205 | replay_result 匹配当前 immutable in-flight owner |
| 220、221 | install/refill owner fault 为 false |
| 282 | secondary 继承 transaction/epoch/way owner |
| 299 | primary 有 RPQ 空间 |
| 301、303、306 | primary owner、write domain、非零 transaction |
| 317 | 已获权限的直接 drain primary 为 write |
| 367、369 | 新 line 必须完整 GrantData；无 data 不允许 dirty victim |
| 519 | store terminal 前已获 write permission |
| 616、619、656 | MMIO AMO 支持边界、无 SC、无 cache owner |
| 982 | terminal 释放 SDQ 的 owner 匹配 |
| 1067 | replay 读取 SDQ 的 owner 匹配 |

175/177 可由当前 gate 与唯一 producer 组合推出，属于冗余 intent invariant，不是独立 liveness 证明；没有矛盾恒假断言。相对旧 HEAD 的 no-data dirty-victim 检查改为当拍 edge.hasData，避免寄存器上一拍值，并新增 new-line 必须 data 的更强约束，不属于删检查绕过故障。原 DCache owner/publish fault assertion 未弱化。

## 30 个 diff hunk 分类

A=已确认需要保留且符合当前 Phase-1 语义的实现；不等于全回归通过。B=本次 closure。C=有明确静态合理性但相关泛化行为尚未验证。D=明显无关、E=疑似破坏、F=内容来源无法确认。混合 hunk 按具体变化拆分标记。

| hunk | 当前行/context | 类别 | 修改内容与判断 |
|---|---|---|---|
| 1 | 29–34 | A | 删除 Internal 重复 sdq_id，继承已搬至 base 的字段 |
| 2 | 64–70 | A | refill 改用带 identity 的 BoomCacheRefill |
| 3 | 83–101 | A | tagged replay/result/grant/install/fault/owner 接口；legacy Bool 只是观察口 |
| 4 | 119–142 | A | transaction/write domain/install/row 寄存器与 owner 默认连接 |
| 5 | 152–169 | A+B | A：write-domain/fault/holdable RPQ；B：159–163 state12 admission closure |
| 6 | 171–227 | A+B | A：in-flight owner、terminal、fault、grantack reset；B：174–177 两条断言 |
| 7 | 231–241 | C | probe_rdy 收紧至0/1/2；属于已有 Phase-1，跨 probe/coherence progress 未全面验证 |
| 8 | 244–294 | A | 完整 payload 默认、held E、secondary identity/domain；不再可变 max(packet_seq) |
| 9 | 298–314 | A | 新 primary owner 验证、transaction、row/install/fault/domain 初始化 |
| 10 | 363–372 | A | 完整 Grant 当拍 hasData、新 line data assertion、无data进入install握手 |
| 11 | 397–416 | A/C | A：load token/retirement，killed primary 仍 install；C：取消后不进入prefetch的泛化影响待测 |
| 12 | 435–441 | A | victim metadata tag payload 补全 |
| 13 | 460–531 | A | install handshake、install-only row、physical line sideband、immutable replay/terminal/publish |
| 14 | 534–540 | A | finish 等 held E completion；配套 line267 全局 E 驱动 |
| 15 | 567–573 | A | MMIO tagged completion 接口 |
| 16 | 621–649 | A | MMIO load/AMO/write routing，held response/completion，D后完成统计 |
| 17 | 651–660 | A | MMIO 新请求清握手状态、assert 无 cache owner |
| 18 | 666–674 | A | MMIO 两类需要的握手均完成才 idle |
| 19 | 705–725 | A | lookup/admission、install、result/grant、MMIO、owner view 接口 |
| 20 | 730–752 | A | refill Bundle 与 legacy observation 连接；不以 raw Bool 释放生命周期 |
| 21 | 760–768 | A/C | A：PriorityEncoder 选 valid lane、raw lookup；C：泛化多 lane/probe selector 未全面验证；不是性能 rewrite |
| 22 | 774–780 | A | cacheability 用 raw lookup，避免 effective ownership path 的组合依赖 |
| 23 | 783–793 | A | SDQ immutable owner 随 data enqueue 锁存 |
| 24 | 829–840 | A | refill Bundle、install/MMIO completion 同 Bundle 仲裁 |
| 25 | 844–871 | A | owner view/admission defaults、MMIO 区分 |
| 26 | 875–889 | A | set/tag/way lookup 从 raw 获取，导出持有 owner line |
| 27 | 893–922 | A | admission 继承旧 owner或新 transaction；连接 fault/result/grant；SDQ ID 来源统一 |
| 28 | 969–993 | A | immutable terminal 匹配释放 SDQ、并行 retire mask |
| 29 | 1011–1020 | A | MMIO copyBase、无 cache owner、completion arbiter |
| 30 | 1057–1079 | A | terminal 才 free SDQ，replay 读取 owner assertion |

没有发现需要剔除的 D/E 功能 hunks。F：git 不能确定未提交代码由哪个 agent 写，但上述内容可由真实快照、增量 patch、修订文档和独立 manifest 定位；不能把这点当作功能未知。旧 unused observation ports、空白注释和未使用状态没有 correctness 恢复必要。

性能专项：未发现后续 flatten Vec、替换动态 owner/slot 索引、合并 FSM、重写 RPQ/replay mux、移除 assert/debug 或改 nSets/nWays。当前动态 sdqOwner(r.sdq_id) 等仍在。PriorityEncoder/raw lookup 是 prepatch 已有 Phase-1 admission 实施，不能为了剔除所谓“性能改动”恢复旧 OHToUInt。

## 静态编译与生成 RTL

本轮实际重新执行：

```sh
cd /data1/gzh/EC/chipyard
/data1/gzh/EC/chipyard/.conda-env/bin/sbt -java-home /data1/gzh/EC/chipyard/.conda-env/lib/jvm ';project boom; compile'
```

Scala compile PASS（增量 up-to-date）；`compile.log` 为本轮日志，有既有 SBT deprecation/multiple-main 告警。

真实 BoomMSHRFile 的 v1Config 最小 harness 从已有 `harness-classes` 调用 `draincheck.EmitMSHR`，本轮用当前编译 classpath 生成到本轮 `module-current/`，不是复用旧生成文件。准确 argv 在 `elaboration-command.json`，classpath 来源 `AI/TMP/mshr_drain_closure_20261014/harness-command.json`。nMSHRs=6、nRPQ=16、nSets=256、nWays=2、memWidth=1、row128、block64B；输入/分支更新完整绑定，真实 negotiated TL edge。Chisel elaboration、Scala FIRRTL lowering、Verilog generation PASS。

本轮 `LazyModule.v` SHA256 `e81ba6c14a9cf5138194ced76acd321d18226786e773d7c68d1bb8dea1f865fa`，与之前同源码生成物字节相同。检查到：

```verilog
// module-current/LazyModule.v:19618,19622,19623,19630,24010
wire drainAdmissionClosed = state == 5'hc;
wire _sec_rdy_T_7 = ~drainAdmissionClosed;
wire _sec_rdy_T_8 = _sec_rdy_T_4 & ~protocolFault & _sec_rdy_T_7;
wire sec_rdy = _sec_rdy_T_8 & _sec_rdy_T_16;
assign io_req_sec_rdy = sec_rdy & rpq_io_enq_ready;
// line24395：唯一RPQ producer
assign rpq_io_enq_valid = (io_req_pri_val & io_req_pri_rdy |
                          io_req_sec_val & io_req_sec_rdy) & ~_rpq_io_enq_valid_T_5;
// line20089：new-line publish state13 transition
wire [4:0] _GEN_624 = rpq_io_empty & ~rpq_io_enq_valid & _T_217 ? 5'hd : state;
// _T_217 = ~replay_inflight
// line24507：issued head lifetime
assign rpq_io_hold_head = replay_inflight & ~replayTerminal;
```

因此 state12 判定实在进入 secondary ready 的组合 cone，未被 Scala 写法遗漏。rowData RTL 更新仍包含 install_row_read_fire（line20020–20022），不是所有 lb_read.fire。

```sh
verilator --lint-only --assert -Wall -Wno-fatal --top-module BoomMSHRFile AI/TMP/mshrs_static_audit_20261014_131925/module-current/LazyModule.v
```

lint PASS，exit0；DECLFILENAME 1、UNUSEDSIGNAL 87（legacy 观察口、未用 uop/payload bit 等）。无 Error、WIDTH、PINMISSING、UNDRIVEN、MULTIDRIVEN、LATCH、UNOPTFLAT。保留告警而非称“零告警”。lint 不证明状态可达性，unused enum 状态已在 state 表单独列出。

完整 v1Config TestHarness/firtool verify-each/CheckCombLoops/内存宏本轮**未重新执行**；同 hash 源码上轮 PASS 记录在 `AI/TMP/mshr_drain_closure_20261014/v1-elaboration-lowering.log` 和 `v1-generated/`。该证据明确作为历史复用，不冒充本轮整机生成。本轮没有 Verilator executable 构建或动态仿真。

## 最小恢复建议

无需恢复源码；没有建议应用的 patch。保留当前 Phase-1 + admission closure 的原工作树。后续对 early load drain、probe/多 MSHR、真实 STQ writer opportunity 做单独定向验证；没有本轮静态证据要求移除某个 correctness hunk。完整 Phase-1 正确性与 BFS 正常退出继续 pending。
