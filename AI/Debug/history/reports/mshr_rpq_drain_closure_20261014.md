# BOOM MSHR RPQ drain admission closure

日期：2026-10-14，Asia/Shanghai。结论：方案 A 的最小改动已在 working tree，Scala、v1Config elaboration/FIRRTL/CheckCombLoops 和四个短 RTL 模块场景通过。旧 RTL 同刺激复现持续入队活锁。真实 LSU 仲裁下的 writer opportunity、多个 MSHR 竞争和 BFS 收尾未动态验证，建议 **需要补测试后提交**。没有运行长 BFS，没有提交。

## 1. 根因与证据边界

`s_drain_rpq` 同时承担关闭事务前的 replay drain 和新 secondary admission，持续同 line loads 扩大 RPQ，导致原 publish 安全条件永远不满足。

原运行 first divergence：FST t=10387259，MSHR2 transaction=0x4da 进入 state12，仍开放 secondary admission。随后 940 FST units / 470 BOOM cycles 中 enqueue119、dequeue117、occupancy8..11；至 t=41845875 仍没有 meta publish。BOOM cycle=(odd FST t−205)/2。这些是原运行观察，不是本轮模块测试 cycle。

直接症状：guest 卡在首条 `[PERF]` SYS_write 的 fromhost polling（已证明）；直接阻塞：committed tohost store 尚未完成 cache 写效果、host 只看到0（已证明）；上游触发：只读 MSHR drain 持续接收 loads（已证明）；放大因素：polling 循环持续生产、replay 需等待 tagged terminal（已证明）。不是 HTIF handler 丢 ACK。

HEAD `a68183c83e08ed837c677aec7836c97895e3a95e`，working tree 已含其他 Phase-1 改动。真正实施前快照：`AI/TMP/mshr_drain_closure_20261014/mshrs.before.scala`，SHA256 `135c7a1dcd5e82f5e616ef7c5c2aaccbfb1bcc24728b8ce70132e0f549f79e7f`。本轮恢复上下文时最小改动及隔离构建已存在；未重复覆盖源码。独立核对该快照与现源码的增量，而不是把相对 HEAD 的整个 Phase-1 diff 算作本修复。

证据目录：`AI/TMP/rpq_drain_closure_20261014_100756/`。原取证报告和摘要已从 /tmp 复制留存，原始输出/FST未改动。旧模块使用默认目录的历史 BoomMSHR/RPQ/RAM；新模块使用本轮隔离 v1Config 生成物。两个文件清单和 SHA256 分别记录，未把旧 FST 冒充修复验证。

## 2. 修改前状态机审计

`BoomMSHR` enum18，secondary 的状态排除仅为 invalid/meta_write_req/mem_finish_1/mem_finish_2；所以条件满足时 refill_req、refill_resp、drain_rpq_loads、meta_read、meta_resp_1/2、meta_clear、wb_meta_read、wb_req、wb_resp、commit_line、drain_rpq、prefetched、prefetch 都允许。wb_meta_read/prefetched 在当前流程未见有效进入路径。

资格条件：不需要第二次 Acquire、不是 probe、不违反 write domain、无 protocolFault、RPQ 有空间；MSHRFile 再限定 cacheable、同 set/tag、SDQ 可用及被选请求 lane。owner inheritance assertion 保留。原注释“Always accept secondary misses”体现减少 nack 的开放策略，但源码没有全局公平性保证；不能推断作者原意是任意流量下永久开放。

RPQ 只有 primary/secondary 两个 enqueue producer。非 prefetch accepted request 入 RPQ；prefetch secondary 不入 RPQ，可更新事务 command/coherence 并在 prefetch 状态触发后续流程，但没有正常 load/store 的新 RPQ companion owner。因此 A 连 prefetch secondary 一并关闭，避免额外事务变化。

进入 drain 前已 accepted 请求、同一进入沿 accepted 的 secondary 都由原队列持有。进入 drain 后原实现唯一能增加请求集合的外部来源是 secondary。Grant capture/安装已完成；RET​RY 不 enqueue，保留队头并清 attempt inflight；kill/cancel 或真正 terminal 才释放队头。单个 replay inflight 是 RPQ head 的一次 attempt，不是另一个独立请求。

原安全路径：primary → Acquire/完整 Grant → LineBuffer 普通 load drain（可先响应）→ victim metadata/writeback → install → 完整 row refill（或无数据升级的 install ACK）→ RPQ replay/terminal → `rpq.empty && !rpq.enq.valid && !replay_inflight` → metadata fire → 等 held E 清零 → mem_finish_2 → invalid。Trunk/Dirty 命中仅需写 dirty metadata 的 primary 可以直接进入 replay drain。

publish 条件本身没有实现“集合冻结”；原早期 drain_rpq_loads 中曾检查 empty/无 enqueue，而最后 replay drain 缺少 admission closure。修复仅关闭最后 replay drain，不扩大到其他状态。

## 3. 方案比较与正确性

| 项目 | A：全部关闭 drain secondary | B：准许不增加工作者 |
|---|---|---|
| correctness | 复用既有 nack/retry；无新 completion 类型 | 普通请求目前需要 RPQ/response ownership，须新增或证明旁路 |
| progress | 排除无限外部 producer；内部响应公平时收敛 | 必须逐类型证明不延长生命周期 |
| 复杂度/验证 | 一个 Bool，两个 assertion | 数据可用性、旁路、终端顺序与 owner 都需新增验证 |
| 性能 | drain 窗口额外 nack/retry | 或能少量减少 nack，收益未测 |
| 耦合 | 只改变 admission | 牵涉 response/replay/install 边界 |

选择 A。当前没有已实现、可直接复用且证明不增加 drain work 的普通 secondary 快速路径，B 不适合作为最小 correctness 修复。

- **Load**：拒绝不获得新 MSHR owner；DCache `s2_nack_miss` 走既有 nack。LSU 匹配 token 后清 LDQ.executed，重新 wakeup；不 silent drop、不产生额外响应。重试仍走普通一致性/owner 检查，不绕过数据顺序；重试时间延后可能合法观察更新的数据，不保证数值与原开放调度相同。eventual service 依赖仲裁和响应进展。
- **Store**：读 primary 本来就拒绝需写权限的 store；写 primary 原可在 drain 接 compatible store，新行为让这些请求继续留在 STQ 重试。匹配 nack 清 functional_inflight/succeeded 并必要时回退 execute head，terminal 才标记真正完成；SDQ 仅 req.fire 获得新 ownership。permission/older-store ordering 保持。
- **Replay/ownership**：accepted RPQ、immutable inflight、request/effect/transaction/epoch/way 匹配和 tagged terminal 完全保留。RET​RY 不退休，取消已 issue 的 head 仍等待自己的 terminal，未 issue cancellation 仍释放原 companion resources。拒绝的 lookup descriptor 不构成 ownership transfer。
- **Metadata/coherence**：没有放宽 publish。install/refill先于 drain，probe 保护、新 coherence、dirty 更新、held E/ACK 和 retire 路径保持。新 store 不能在旧同 line owner 退休前错误抢占。
- **Phase-1**：未改 rowValid/rowData、install read、LineBuffer、physical line sideband、generation、watermark、preservation fact 或 resident owner；只拒绝最后 drain 窗口的新请求。publish 可能因少接新工作更早到达，但仍必须等待原安全条件，没有提前发布未完成事务。

收敛论证边界：令 W 为 drain 入口的未完成 accepted 请求，最多 nRPQ 项；replay inflight 属于该集合。closure 后没有外部增加 W，匹配非 RET​RY terminal/合法 CANCEL 减少 W。若每个 attempt 最终收到响应且有限次 RET​RY 后 terminal、metadata/E 获服务，则 W 排空并 retire；如每项完成有界才能得到周期上界。无限 RET​RY、永久下游背压或不公平 replay 仲裁不能由本条件证明排除。

## 4. 代码与新不变量

唯一功能文件：`chipyard/generators/boom/src/main/scala/lsu/mshrs.scala`。

- 159：新增 `drainAdmissionClosed = state === s_drain_rpq`；162：secondary ready 增加 `!drainAdmissionClosed`。
- 174–177：drain 中 assert 无 secondary accepted、无 RPQ enqueue.fire。

本次增量 +10/-1，未改 enum、publish 条件、终端 owner check、Phase-1、软件或任何 HTIF 地址。没有新增寄存器，增加 state12 decode 对 secondary ready 的组合资格；不引入跨模块 raw owner 反馈。assertion C 复用已有 secondary owner inheritance、stale completion 和 SDQ owner 检查，未新增复杂历史计数。

完整 `git diff -- mshrs.scala` 保存为证据目录 `git-diff-mshrs-full.txt`，包含原先 Phase-1 改动；本轮独立增量是 `incremental-fix.patch`。

## 5. 实际验证

| 验证 | 结果/边界 |
|---|---|
| BOOM Scala compile | PASS，1 个源码编译；既有 Array conversion deprecation/feature warnings |
| v1Config Chisel elaboration | PASS，本轮包含 closure 和两条 assert 的 FIR |
| Scala FIRRTL low lowering | PASS，652 s |
| firtool verify-each/CheckCombLoops/Verilog | PASS；原有 unprocessed annotation 告警，无本改动相关 width/connection/组合环错误 |
| top/model memory macro 生成 | PASS；隔离 verilog target 复查 exit0、Nothing to be done |
| assertion compile | 新 RTL 含两条 assert，Verilator `--assert` 构建及四场景通过 |
| 模块 lint/build | 无 WIDTH/PIN/UNDRIVEN/UNOPTFLAT 告警；仅 fixture timescale 与 C++ coroutine flag 告警 |
| diff/工作区 | git diff --check PASS；prepatch dirty file SHA256 只有 mshrs.scala 改变；默认 generated 6790 文件 size/mtime_ns 均一致 |

真实生成 `BoomMSHR.sv` + `BranchKillableQueue.sv` + 7 类实际 RAM，非行为模型。地址为普通 line0x80001000，writer A=+0、polling B=+8，无 HTIF 特判。环境提供 TL Grant、LineBuffer、metadata 和 matching tagged completion；未包含真实 DCache array/LSU/STQ/TL fabric。各测试仅82–244模块周期；旧对照1026周期，无长 regression。

| 场景 | 观察 |
|---|---|
| 旧 RTL、持续 polling + writer retry | drain入口26；额外1000周期仍state12，drain接受201新请求，publish0，store拒绝60次 |
| 修复、相同刺激 | drain接受0；原15个请求全部完成，74周期后MSHR invalid；后续store upgrade/replay terminal完成 |
| 修复、RET​RY及背压 | RET​RY1次、refill stalls2、meta stalls70、E stalls197；184周期退出；无提前publish/重复完成 |
| 分支取消未issue项 | 全部15个accepted请求最终retired，47周期退出 |
| 已issue replay遇kill/CANCEL | 保持owner至CANCEL terminal，cancel1；全15个退休，22周期退出 |

每个修复场景还覆盖：无数据 Branch→Trunk upgrade、closure 前 accepted secondary store/load、无额外 refill 的权限升级、Trunk primary直接进入drain。最终19 accepted/19 retired，拒绝请求没有被假退休。普通 LineBuffer load的数据字检查通过，rowValid未被污染，refill stall payload保持稳定。store完成仅表示stub返回matching APPLIED并由MSHR处理，不是整机STQ.succeeded或真实内存写验证。

脚本和命令：`make_module_tb.py`生成端口驱动；`rtl_files.txt`/`old-rtl_files.txt`是分别的输入；`suite-results.json`和`old-result.json`记录实际命令/exit。`fixed-*.log`、`old-run.log`、build日志为结果。首次 Icarus 不支持 CIRCT 的 labelled immediate assert，改用 Verilator保留全部assert；一次fixture E ready未恢复导致state14等待，修正环境后保留失败日志并重跑，未修改RTL解决测试失败。测试 `$finish` 仅在有界模块证据检查后结束，与被调查的TestHarness退出路径无关。

## 6. 第二层 starvation 与下一步

MSHRFile采用request lane PriorityEncoder，replay/meta是固定优先级仲裁；当前v1 memWidth=1。LSU incoming load优先，load wakeup也在committed store之前；已有1W st→ld conflict/15-cycle guard会压住wakeup，但不覆盖所有incoming load、PTW或其他流量，故不存在本审计能证明的全局writer公平上界。

对固定同line polling、无额外失效/eviction的场景，read MSHR正常publish/retire后Branch line已resident，`block_hit`随MSHR退出解除，load变为命中，不会每次释放都重新申请read MSHR。store随后需要upgrade。因此“polling每次抢新read MSHR”的同一机制在该前提下被消除。原波形已显示store周期性送到DCache但被权限/admission拒绝，主要阻塞不是未获得LSU发射机会。

尚未证明：真实LSU同line循环下store一定得到发射机会、其他MSHR固定优先级竞争、其他开放阶段持续流量、probe/eviction反复使line失效、无限RET​RY。它们是独立风险，没有证据要求本次同时修改仲裁；不得把本模块测试宣称为全局公平证明。

提交前最小补测：真实BOOM/DCache/LSU短程序，同64B line的polling load和已提交store，观察旧MSHR metadata fire/retire、load恢复hit、store upgrade acquire/terminal、STQ.succeeded与数据可见；再加多MSHR竞争/一次probe或eviction、正常secondary merge回归。若这才证明writer始终拿不到机会，再单独设计公平性修复。BFS及 `[PERF]/[END]/io_success` 本轮未验证。

建议：**需要补测试后提交**，原因是MSHR局部bug已有RTL对照证明，而用户要求的完整writer opportunity仍缺真实仲裁动态证据。
