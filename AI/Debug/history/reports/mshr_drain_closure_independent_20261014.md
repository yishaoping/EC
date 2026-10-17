# BOOM MSHR replay drain：设计审计与独立验证

日期：2026-10-14，Asia/Shanghai。结论：采用 A，关闭 `s_drain_rpq` 的全部 secondary admission。只改一个功能文件，增量 +10/-1；Scala、完整 v1Config elaboration/lowering/CheckCombLoops 和短 RTL 单元对照通过。**需要补测试后提交**：真实 LSU/STQ writer opportunity、DCache store 数据效果与多 MSHR 公平性尚未动态验证。

本报告的证据目录为 `AI/TMP/mshr_drain_closure_20261014/`，与工作区同时出现的 `rpq_drain_closure_20261014_100756/` 记录独立；保留已有报告，不混用其历史 FST 数值、测试周期或数据正确性结论。原 HTIF 动态链由本轮用户提供，本轮用源码与独立 RTL 反例验证 admission 首因。

## 1. 源码状态机审计

以当前源码而非旧行号为准：`boom/src/main/scala/lsu/mshrs.scala`。

- Primary：invalid 中 `req_pri_val && req_pri_rdy` 调用 `handle_pri_req`，锁存目的 way/epoch/transaction/write domain，非 prefetch 入 RPQ。tag mismatch 走 Acquire/Grant；Branch 权限不足走 upgrade；已有 Trunk/Dirty 只需写 dirty metadata 的 primary 可直接进入 `s_drain_rpq`。
- 原 secondary eligibility 排除 invalid、meta_write_req、mem_finish_1/2，因此 refill_req/resp、drain_rpq_loads、meta_read、meta_resp_1/2、meta_clear、wb_req/resp、commit_line、drain_rpq、prefetch 都可能接收。枚举 wb_meta_read/prefetched 也不被 predicate 排除，但当前未见进入分支，不能把它们算作已验证可达路径。
- MSHRFile 还要求 cacheable、同 set/tag、被选 lane、SDQ 有空间；单 MSHR 要求不需要第二次 Acquire、不是 probe、write domain 兼容、无 protocolFault、RPQ ready。secondary owner assertion 要求继承原 transaction/epoch/way。原“Always accept secondary misses”注释及这些条件反映了合并以减少 nack 的策略；未发现与之配套的截止/公平预算。
- RPQ 仅有一条 enqueue assignment，来源是 primary 或 secondary accepted。普通 load/store/LR/SC/AMO 都入队；prefetch 不入队，但 accepted prefetch 可改变命令/coherence及 prefetched-line 后续流程，因此不等于无事务副作用。普通 secondary 没有现成的免 RPQ、免 replay ownership 的快速完成路径。
- 完整 GrantData 先写 LineBuffer；普通 RPQ load 可在 `s_drain_rpq_loads` 提前响应。随后 metadata read/victim WB、install ACK、全部 row refill，最后进入 replay drain；无数据 Grant 也先 install ACK，跳过 row read/refill，再 drain。直接 dirty-metadata primary 是既有独立入口。
- drain 中 `io.replay.fire` 建立 immutable inflight，但 RPQ head 保留。匹配 tagged result 的 RETRY 只清 attempt inflight，保留 head；非 RETRY terminal 才 dequeue/retire，SDQ 按 immutable owner 释放。未 issue 的 kill 由 discarded cancellation 退休；已 issue 的 kill 仍保留 head 直到 terminal。
- 最终 publish 入口仍是 `rpq.empty && !rpq.enq.valid && !replay_inflight`。terminal 必须先握手使 inflight 清零；metadata 写还受 DCache S3/completionPending、冻结前 S1/S2 引用 drain 条件约束，meta_write.fire 才释放 slotReserved/installActive。之后等待 held GrantAck/E 清零，再经 mem_finish_2 retire。
- drain 已无 install row producer、Grant/refill producer；replay response 不重新 enqueue，内部补偿 store replay 在 DCache 独立路径，不能绕过 MSHR `req_sec_rdy` 进入 RPQ。late secondary 以实际握手时 state 为准；进入 drain 的时钟沿之前 accepted 的项已入队，仍归旧事务。
- 原设计有“完成前必须 empty/无 enqueue/无 inflight”的排空要求，但没有冻结 admission 的锁存概念。新增 state decode 补足最后 replay drain 的闭集合条件，不改变其他状态。

## 2. A/B 比较与正确性

| 方面 | A：drain 全关 | B：只接不增加工作者 |
|---|---|---|
| 正确性 | 沿用 nack/retry，不引入新 completion 或 owner | 要逐种请求证明免 RPQ/免 owner 且保持响应和数据顺序 |
| 进展 | 排除无限外部 producer，有限工作在下游进展假设下收敛 | 需证明准许类别永远不延长 transaction lifetime |
| 复杂度、验证 | 一个 Bool，两条 assertion | 新旁路/data-ready/response 仲裁的证明负担较大 |
| 性能 | drain 窗口增加 nack/retry，吞吐收益未测 | 或能减少少量 nack，收益未测 |
| 耦合 | admission 单点 | 通常会牵涉 LineBuffer、replay 和 terminal ownership |

选择 A。prefetch 虽免入队仍有副作用，普通 secondary 均有队列责任；B 没有可直接保留的安全旁路。

- **Load**：drain 拒绝传到 MSHRFile req.ready=0；同 line block_hit 仍有效，因此 DCache 不误报 hit，而产生 s2_nack_miss。普通 LSU nack 保留原 functional token，匹配 LDQ 后清 executed，再由 wakeup 重试；成功 response 与 nack 原本互斥。拒绝没有 ownership transfer，也不会产出第二份 response。重试仍受原 coherence/epoch/ordering 检查；延后可合法读到更新的数据，不会增加一个绕过检查的旧数据来源。eventual service 依赖仲裁进展，不作无限流量的无条件保证。
- **Store**：read primary 原本已拒绝需要 write intent 的 secondary；write primary 原可接兼容 secondary store，关闭后增加重试。SDQ 只在 cacheable write req.fire 分配。LSU 匹配活 STQ token 后清 functional_inflight/succeeded，必要时回退 execute head；已提交 entry 保留，terminal 才最终完成。没有改 permission upgrade、older-store ordering 或 store 数据。
- **Replay/ownership**：改动只在 readiness；RPQ head、inflight、grant matching、tagged terminal、CANCEL、SDQ owner assertion 没有变化。lookup 的候选 owner descriptor 不等于 accepted ownership；reservation 和 SDQ 都由 fire 建立。进入 drain 前 accepted 项及进入沿的 accepted 项继续完成，不 orphan，不重复。
- **Metadata/coherence**：原 RPQ/inflight guard、install/refill ordering、completionPending、probe protection、dirty 更新、held E 及 retire 时序均保持。达到安全条件可能因少接工作而更早，但不跳过条件；旧 MSHR idx/tag.valid 在 retire 前保留，新同 line primary 不能抢占。
- **Phase-1**：rowValid/rowData 只在 commit_line 的 qualified install read 更新，末 row refill 完成后才进入 drain；关闭 drain admission 不会使 install read 不发生，也不改变 rowValid 生命周期。LineBuffer、commit_line、physical line、grant/install/replay token、generation、preservation fact/resident metadata 逻辑全部原样。terminal 没有被跳过。

收敛证明：设 W 为 drain 入口尚未完成的 accepted 请求集合，至多 nRPQ 项，单个 inflight replay 是其中队首的一次 attempt。closure 后没有新外部请求增加 W，匹配非 RETRY terminal 或合法 pre-issue cancellation 减少 W；RETRY 不加入新项。若 arbitration/downstream 最终服务每个 attempt，且每项有限次 RETRY 后终结，则 W 最终为空，原 publish/retire 顺序继续执行。只有在服务延迟也有上界时才可给周期上界；无限 RETRY、永久背压和固定优先级饥饿不能由此 patch 消除。

## 3. 第二层 starvation 与性能边界

MSHRFile 的 lane 选择是 PriorityEncoder（固定低 lane 优先），空闲 MSHR 是 AgePriorityEncoder 加 rotating head；后者是分配器资源轮转，不是请求者公平仲裁。replay/meta/refill/response 的 MSHR 间 Arbiter 仍为固定优先级。

v1Config BOOM 为 memWidth=1。LSU incoming loads 优先，store commit 最低；load wakeup 在 store 可发但阻塞 15 周期后被抑制，另有同址无法 forwarding 时抑制 wakeup。它提供 wakeup 对 store 的让行，但不覆盖无限 incoming load、hellacache/PTW、持续下游背压。matching nack 会恢复活 STQ 的重试资格，不提供完整调度公平性证明。older inflight store 也继续阻塞年轻 store，以保持顺序。

对于没有外部 probe/eviction 的固定 resident line，旧 read 事务 publish 并 retire 后，polling 普通 load 在 DCache 按 resident metadata 命中；无需重新申请 read MSHR。因此不会仅凭这些 polling loads 每次重建 read MSHR，从而持续击败 writer upgrade。writer 已被恢复为可重试项，正常 issue 时有权限升级机会。真正 core-level STQ succeeded 尚未动态验证。

若要求对任意无限 incoming 流量、外部反复撤权限/替换和多 MSHR 竞争都保证 writer eventually succeeds，当前固定优先级链不能证明，需独立公平性改动；不能声称本次完全解决全局 starvation。当前没有证据显示该风险阻止所定位 state12 的修复，故不扩改 LSU。更早 `s_drain_rpq_loads` 仍开放 admission，在足够连续的新 load 流下也可能延长该阶段；本轮只证明进入最终 replay drain 后的收敛，未修所有 admission 状态。

## 4. 实际修改与不变量

唯一功能改动：`mshrs.scala:157–177`，新增 `drainAdmissionClosed`，sec_rdy 增加 `!drainAdmissionClosed`，删除已不准确的 Always accept 注释，并增加：

```scala
when (drainAdmissionClosed) {
  assert(!(io.req_sec_val && io.req_sec_rdy), "secondary accepted during RPQ replay drain")
  assert(!rpq.io.enq.fire, "RPQ enqueue during closed replay drain")
}
```

A 覆盖所有 secondary，包括免 RPQ 的 prefetch；B assertion 的前提由唯一 primary/secondary enqueue producer 审计支持。C 复用既有 token/owner/SDQ assertions，不新增历史计数器。closure、外部工作不增长、ownership 保留、原 publish 条件、reject 可重试满足源码不变量；eventual writer opportunity 仅在上节明确的服务假设下成立。

实施前工作树已有 Phase-1 更改。`fix.diff` 是相对本轮 `mshrs.before.scala` 的 +10/-1；`mshrs.final.git.diff` 是执行 `git diff -- chipyard/generators/boom/src/main/scala/lsu/mshrs.scala` 的完整输出，包含旧 Phase-1，更改不能全部归本轮。原 dirty 功能文件核对只有 mshrs.scala hash 变化。所有本轮 generated/test collateral 留在 AI/TMP，未改默认 simulator/trace/threads/logging 或 benchmark。

## 5. 验证结果

| 项目 | 结果 |
|---|---|
| Scala compile | PASS，`project boom; compile`，仅本功能文件增量编译 |
| 实际 v1Config elaboration | PASS，隔离 build_dir 下完整 TestHarness |
| Scala FIRRTL low lowering | PASS |
| firtool verify-each、CheckCombLoops、Verilog/内存宏 | PASS，已有 annotation warnings，未出现新 width/connection/loop failure |
| assertion compile | 两条新 assertion 出现在完整 v1Config RTL；Icarus 编译真实 BoomMSHRFile/RPQ/SDQ/LineBuffer 测试 DUT PASS |
| 静态比较/diff | publish/retire、install row、primary/secondary owner update、MSHRFile arbitration/SDQ 与本轮基线逐段相等；git diff --check PASS |

独立短测试使用真实 BoomMSHRFile 及 6 MSHR，v1Config BOOM tile 参数（nRPQ=16、64B line、128b row、memWidth=1）。地址 A=0x80000100、B=0x80000108；持续 B load＋A writer retry；Grant、metadata、terminal 由环境提供。测试环境没有真实 LSU、DCache array、STQ 或 TL fabric，不把 APPLIED stub 等同实际 store 数据效果。Icarus 的部分 generated fatal 可能 exit0，脚本要求 PASS/OLD marker 并排除 FATAL/assertion 字符串。

| 场景 | 结果 |
|---|---|
| 修改前快照，同持续刺激 | 2000周期仍 state12，接收409 load，writer拒绝250次、replay301次/terminal299次，read publish=0；复现旧 livelock |
| 修改后，同刺激 | drain cycle124→read publish220（96周期）；writer cycle223 primary upgrade、224 BtoT Acquire、237/243 matching store terminal；write publish292，全 retire294 |
| 逐请求 ownership | case0 accepted117/completed117，无重复/orphan；SDQ两次释放=两次 store terminal |
| 已有 Trunk 的写 primary直接 drain | 18周期完成，1 accepted/1 completed；首次 RETRY 后同 token完成 |
| 带 GrantData 的写 miss＋secondary | 138周期，16 accepted/16 completed，2 store terminal；refill row字节/SDQ payload检查通过 |
| pre-issue exception kill | 66周期，16 accepted/16 completed，其中14合法 cancellation、2 store terminal；SDQ释放2次 |
| 故意错 transaction token | 原 stale replay completion / MSHR allocation reuse assertion 按预期触发，无 PASS |

各正常场景包含 replay terminal 延迟5周期、一次内部 RETRY、周期性 install/refill/metadata/E ready 背压，以及 drain 中持续的新请求。read/row 数据字与 grant row对照；terminal model 不实际执行 DCache store，所以不能宣称整机内存写已验证。全部新和原 assertions 在正向场景无失败。

复现命令见证据目录 `commands.md`；静态/动态结果见 `static-results.json`、`dynamic-results.json`。没有重跑 BFS，没有构建整机新的 Verilator executable，没有调整仿真性能参数。核级 load/store ordering、post-retire store grant/STQ.succeeded、multi-MSHR/probe、公平性以及完整 Phase-1 preservation regression **未验证**。

## 6. 提交判断

**需要补测试后提交**。最小源码修复与模块层 drain 收敛有直接对照证据；下一项应是短核级同 line polling＋committed writer，检查 metadata publish/retire→load hit→store retry/Acquire/真实写→tagged terminal→STQ.succeeded。其次覆盖多 MSHR 与 probe/eviction 竞争；不需要先跑3小时 BFS。
