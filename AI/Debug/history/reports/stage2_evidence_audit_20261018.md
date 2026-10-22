# Stage 2：当前源码与已完成运行的证据审计（2026-10-18）

## 1. Executive verdict

```ini
STAGE2_STATUS=CLOSED
NEXT_SIM_REQUIRED=NO
STATIC_STAGE2_STATUS=READY_FOR_VALIDATION
KNOWN_STATIC_CORRECTNESS_BLOCKERS=0
CODE_CHANGES=NONE
FINAL_CLOSURE_DECISION=CLOSED_ON_EXISTING_EVIDENCE
```

没有发现需要修复的 preservation correctness blocker。最新真实运行已经完成
build、directed、system；当前证据足以关闭本阶段的 L1 preservation safety invariant。
旧 epoch 故障已在后续同源运行中消失；不要求为了两个非阻塞覆盖缺口或长期公平性再跑
Stage 2 仿真。

本轮只读源码/已有日志、hash/清单比对和文档更新；没有执行编译（包括软件编译）、
生成、elaboration、FIRRTL、Verilator、仿真、regression 或单元测试。
Stage 1 保持已关闭，不开展 Stage 3。

### 证据身份

- 当前 HEAD：`1ed07c28067fad6d8aed697323b465b925895914`，以及当前全部本地改动。
- 最新运行：`/data1/gzh/EC/AI/TMP/stage2_validation_agciqdp_/`，下文记为 R。
- 本轮审计：`/data1/gzh/EC/AI/TMP/stage2_evidence_audit_bbmws5qc/`，下文记为 A。
- `A/identity.audit.json`：R 记录的 **11479 个 source、16 个 scripts** 全部与当前文件
  SHA256 相同；HEAD 和 workload manifest 相同。
- `A/inventory.audit.json`：当前 source/scripts 清单无增加/减少；fixture 副本相同；
  `system.build/provenance.json.source_files` 与 `inputs.json.source` 相同。
- R 的三次 `provenance.verify.*.log` 均 PASS；system simulator SHA256：
  `8ca09b7d2ebf40522d62b4ef481972e4218fe71fde8b939bb7766ac6168a88a9`。
- `system.run.wrapper.log` 记录 trace SHA256：
  `ad26b170ff692d45723c4dfc87a94e78dc0b09bb83a0008ca0ed434c3432b260`。
- 本轮没有重新 hash 整个 generated model、binary 或 2.7 GB trace；产物身份采用运行时
  已有 provenance 和 artifact gate，不把本轮 source 比对说成重新完成所有产物验证。
  原始 run/报告没有改写。本轮文档不在上述运行输入清单中。

## 2. 已确认 PASS 的部分

以下 CONFIRMED_PASS 指当前协议和实际测试范围，不是所有交错的形式化证明。

| 项目 | 结论 | 主要证据（均在 R） |
|---|---|---|
| 构建/连接 | CONFIRMED_PASS | build.status.json exit=0；33 pin wiring PASS；module.lint.log；整机 build provenance |
| same-packet overwrite | CONFIRMED_PASS | module.trace.log:166；两次写/读回，preservation 请求数不增加 |
| cross-packet gate | CONFIRMED_PASS | :278；先等待 PASS、再等待 receipt，独立 effect guard 无提前 effect |
| safe predecessor gate | CONFIRMED_PASS | :165；C 背压、延迟 D、early matching ACK 均不释放 |
| lowerPreserved | CONFIRMED_PASS | refill 最后 row fire 或匹配 done 才 set；system 1216 次请求/receipt/done 闭合 |
| ImageKey / stale ACK | CONFIRMED_PASS | :73、117 unmatched，:122 matched；完整 key/epoch/owner 静态链路 |
| normal | CONFIRMED_PASS | normal_amo_sc_success_failure；system NORMAL_EFFECT=135486 |
| replay | CONFIRMED_PASS | speculative_refill_replay_gate；system REPLAY_EFFECT=8739 |
| SC | CONFIRMED_PASS | :279、463；同包成功、无 reservation 失败、跨包 gate 后失败，无数据修改 |
| AMO | CONFIRMED_PASS | :279、463、1611；独立 old/new 数据判据；system AMO_EFFECT=90 |
| refill | CONFIRMED_PASS | :1610、1611；unsafe image 重填后 RPQ retry、连续替换及读回 |
| commit-time ReleaseAck | CONFIRMED_PASS | :1612；真实 SourceD 四拍 128-bit bank fire、held ACK、credit/D beat-lock 测试 |
| denied A Put/AMO | CONFIRMED_PASS | :1613–1618；真实 MSHR→SourceD，denied writes=0/旧 key 保留，成功对照 writes=1/BASE |
| 退出排空 | CONFIRMED_PASS | system EXIT_DRAIN：WB/cross_package_pending/slot_reserved/MSHR 等为0，fence_ready=1 |

`directed.coverage.json`：10 CASE 各一次；exit=0；effect_guard_count=4；
physical_effect_count=35；check_failures/event_errors/missing/duplicate 均为空；
denied/成功 Put/AMO 四个事件各一次。不是参考模型自测：fixture 实例化生产
BoomNonBlockingDCache/MSHR/replay/WB、生产 SourceD，以及用于 denied 回归的生产 L2 MSHR。
C++ 独立控制 PASS/C/D/terminal ready，核对完整旧 image 字节、C header/key 和实际 bank/D 事件。

整机 `stage2.scoreboard.json`：status=PASS，errors=[]，missing_coverage=[]。
PRESERVE=PRESERVE_RECEIPT=PRESERVE_DONE=1216；MODIFY=144225；IMPORT=9415；
SAME_PACKAGE=95072；WAIT_SAFE=4131；WAIT_PRESERVATION=1032。
复用本次整机原 Stage 1 checker 的 PASS：ARCH_ERROR/AMO_ERROR/DUP_EFFECT/LOST_EFFECT/
REPLAY_UNCLOSED/CLEAR_RACE_VIOLATION/EXIT_REAL_OUTSTANDING 均0；main=checker=155604。
这些是本次 run 的结果，不替换历史 Stage 1 的计数，也不重新审查其 datapath。

## 3. 发现的问题

```ini
KNOWN_STATIC_CORRECTNESS_BLOCKERS=0
```

旧 current state、脚本 README、设计文档仍把 r8baqbfq/d5wr10l1 的失败称为最新、
宣称当前 33 pin/epoch 修复未构建；这是证据状态过期，本轮更新文档并保留历史。
没有发现需要 patch 的 RTL bug、preservation bypass 或新的 ABA 缺陷。

以下是实际验证边界，不能把它们隐藏成“所有理论交错均已独立动态覆盖”，也不据此虚构功能 bug：

1. system Stage 2 analyzer 的 LOWER_COMMIT→ACK 按完整 wire key 计数，未独立关联
   block address/source；BASE 为共享零 key。PRESERVE_DONE/receipt/overwrite 另按
   line+epoch+完整 key 关联。它依赖 authored key 在单 writer、不回绕会话中唯一的协议；
   不能将 schema1 称为任意客户端事务的一一对应独立证明。
2. MODIFY 的 safe/lower 来自 RTL；lower 另有 IMPORT/receipt 检查，而 safe 的独立
   动态判据来自定向 stimulus 的 PASS 时机。整机 Stage 2 analyzer 不重新实现独立
   package validator，也不单独检查每一拍 refill；后者由生产断言和既有 Stage 1
   owner/refill checker 支撑。
3. fixture 的 directory result/bank ready/data 是受控接口，不是真实 Directory/BankedStore
   存储。实际存储、互连和系统进度由整机覆盖。整机没有主动制造 denied A；该场景的
   直接证据是生产 MSHR→SourceD 定向路径。
4. 精确同周期 matching done + probe revoke、refill + done 未有独立 CASE；正常压力运行
   不能替代这些交错的必达激励。当前静态优先级/owner 互锁没有已知冲突，见第7节。
5. directed C++ 在首个异常退出；runner 汇总已输出的失败和未运行 CASE。
   不能声称它会在坏状态下继续执行所有独立仿真场景。

现有静态链路 + 独立定向数据/事件检查 + 整机断言/两套 checker 已足以支持当前 Stage 2
safety closure。两个精确同周期场景属于非阻塞 coverage gap；长期公平性属于 Stage 2
范围外的 liveness/stress 问题。无需为 closure 改动 RTL、checker 或新增仿真。

## 4. Preservation invariant 的当前实现

`boom/.../lsu/phase1.scala:69` 的实际 gate：

```text
safe(K,w) = !K.valid || K.contentSeq==0 || K.contentSeq<=w
same = K.valid && incomingSeq!=0 && incomingSeq==K.contentSeq
allow = !present || same || (safe(K,w) && (incomingSeq==0 || lowerPreserved))
copyAllowed = !present || oldKey==incomingKey || (safe(oldKey,w) && lowerPreserved)
```

`same` 比较完整32-bit package sequence，不是 ROB/STQ index 或统计 bucket。
R_IC.scala:258–273 分配全会话单调 sequence、断言不回绕到0；core.scala:2365
把分配边界正确送入 LSU，lsu.scala:1202 在 STQ 捕获；MSHR/RPQ replay 保留请求内
packet_seq。当前配置只有一个 BOOM package writer；外部可信写用 BASE/seq0。
多 BOOM 的跨 writer package namespace 不属于当前协议支持范围。

unsafe 跨包写由 `crossPackageDomainWait` 阻止 hit grant 和 permission-miss admission；
旧包 safe 后，若 lower=false，仍不能 grant。coordinator 的真实顺序是：

```text
crossPackagePending（freeze、WaitSafe）
→ 排空先前 S1/S2/S3/completion、slot/MSHR/probe 冲突
→ crossPackageWbReq.fire（snapshot key 锁定，仅请求被接受）
→ WB capture → C 最后一拍 fire（释放数据缓冲，不结束 pending ACK）
→ L2 最后 bank write fire 与 ReleaseAck enqueue 原子发生
→ D fire + pending_sent/source/size/full-key/!denied/!corrupt 匹配
→ wb.done（pending key + snapshot epoch）
→ resident tag/epoch/key 匹配且未被 probe 同拍撤销：lowerPreserved=true
→ shadow metadata clear → refetch/import/retry → 允许新的 speculative effect
```

safe 且 lower 已为 true 时可直接 grant。每次新语义写都会清除 receipt；同包直接覆盖保留
既有 safe predecessor 的保存义务，不保存每个中间 image。`incomingSeq==0` 不创建新
speculative image，但仍须等旧 unsafe image safe。

实际 system 因果链（trace 的十进制文件行号，不是 cycle；完整摘录见 A）：

| trace 行 | 事件 | 同一 image |
|---:|---|---|
| 2489459 | BLOCK lower=0 safe=1 incoming=1 | line80007e00 / gen b75e / seq0 / writer0 |
| 2489467 | PRESERVE | epoch a，仍未表示保存完成 |
| 2489578 | LOWER_COMMIT data=1 | 真实 SourceD 最后 bank fire/ACK enqueue |
| 2489586 | ACK matched=1 | source6，完整 key 匹配 |
| 2489594 | PRESERVE_DONE accepted=1 | 原 line/epoch/key 匹配 |
| 2489741 | IMPORT | 同一 key，新的 epoch c |
| 2489758 | MODIFY lower=1 safe=1 new_seq=1 | replay，原 req c89a；此时才覆盖 |

保存完成的协议含义：L2 BankedStore 已接受最终所需 subbank 写，edge 上执行 SRAM write；
Scheduler 同时接受对应 directory publish，Directory 的单项写队列/读旁路使之有序可见。
不要求等待一个不存在的 bank response；也不是仅 C 入队、仅发请求或保存到 DRAM。
L2 后续覆盖时如何保留多版本 predecessor 属 Stage 3，本轮不扩展该承诺。

Image identity 是 `(block address, valid1, writer16, generation32, contentSeq32)`。
地址隐含在 header/tag/set；BASE 为全零 wire key，和 slot `imageValid=false` 不同。
每次本地 physical semantic fire 分配跨 line 的新 generation；复制、权限变化、变 safe 不改 key。
snapshot epoch16、MSHR transaction32、request/effect64 分别约束 slot、安装和功能请求，不混作 ImageKey。
generation/epoch/package sequence 耗尽有断言；本协议不承诺任意回绕或非协调局部 reset 后的身份安全。

## 5. Producer matrix

最终 data array 只有 `dataWriteArb` 两个入口（dcache.scala:647、1291、2228）。

| Producer | L1 write/install point | Can introduce speculative image | Gate | Evidence | Status |
|---|---|---:|---|---|---|
| normal store | S2 grant→S3→port0 | 是 | S2 allow、MSHR admission、S3 allow+owner/image recheck | dcache:1142,1449,2013,2164,2228；定向+system | CONFIRMED_PASS |
| replay store | RPQ→S2/S3→port0 | 是 | 同一 gate；blocked 返回 CacheTerminal.retry，head/SDQ 不释放 | dcache:2270；mshrs:186–212,517–527；refill/replay CASE | CONFIRMED_PASS |
| SC success | S2/S3→port0 | 是 | 同一 write grant/effect gate | dcache:2027–2042,2164；成功 SC CASE | CONFIRMED_PASS |
| SC fail | 无 data fire，仅 terminal | 否 | 可保守等待 gate；s3_applied=s2_sc_fail，key/receipt 不改 | dcache:2035；普通/跨包失败+读回 | CONFIRMED_PASS |
| AMO | ALU 结果→S3→port0 | 是 | 同一 grant/effect gate，无旁路写口 | dcache:2080,2164,2228；独立 old/new/terminal 背压 | CONFIRMED_PASS |
| refill/prefetch | MSHR install→每 row port1 | 可复制 speculative key，不新建语义版本 | copyAllowed+owner/transaction/epoch/full-key；new_owner 依赖 victim WB/ACK drain | dcache:1220–1305,2321；连续冲突/unsafe refill/replay | CONFIRMED_PASS |
| Hella/PTW 可缓存写 | normal pipeline→port0 | 当前 seq0 | 同一 allow，不能抹掉 unsafe 归属 | 相同最终写口源码；seq0 定向 | STATIC_PASS；完整客户端组合未独立定向 |
| permission-only Grant | 不写 rows | 否 | install owner/drain；保留原 key/receipt | mshrs:481，install.has_data | STATIC_PASS |
| MMIO/IOMSHR | 无 L1 array write | 否 | 不适用；可信 TL 字段默认 BASE | IOMSHR 独立 TL 路径 | STATIC_PASS |
| probe/clear/eviction metadata | 改权限/撤销，不创建语义 image | 否 | drain+WB/probe completion；新 owner 等 pending ACK | dcache:1190,1230,1537–1599,2108 | STATIC_PASS+定向/整机交互 |

新地址 refill 的 `new_owner` 不用 old-key copyAllowed，但并非无条件毁掉 victim：
MSHR 先 meta-clear/WB capture，installDrain 继续等待活动 WB **和 pending ACK** 退出，
排空旧语义写；部分 refill rows 由 reservation 隔离，最后一拍才发布新 image/receipt。

## 6. lower_preserved 生命周期

```text
creation/reset:
  per-slot bool=false；imageValid=false；key=BASE；epoch=0。
set:
  (a) 完整 refill 最后一个实际 row fire，安装准确 incoming key；
  (b) issued snapshot 的 wb.done，完整 key+epoch 匹配，resident/tag/key/epoch
      仍匹配且同拍无 probe revoke。
held:
  验证 watermark、measurement reset、普通 stall/重试、读、无数据权限转换、
  SC fail、无实际 effect 的 kill，不改变当前 image receipt。
cleared:
  每个 port0 semantic fire（含同包/AMO/成功SC/seq0）新 generation、lower=false；
  非 reserved probe invalidate/shadow clear 撤销 image presence 和 receipt、推进 epoch。
reuse behavior:
  victim 撤销 metadata 时可暂留旧 image 身份；incoming reservation 隔离它，
  等旧 WB pending ACK 结束后才写 rows；最后 row 原子替换 key/epoch/receipt。
  不将旧 receipt 继承给新语义 generation；refill=true 是新收到完整 image 的 receipt。
response matching:
  唯一 voluntary source=cfg.nMSHRs，pending descriptor 在 ACK 消费前不复用；
  必须 C allSent、ReleaseAck、block size、!denied/!corrupt、完整 wire key 相等。
  wb.done 再匹配 snapshot epoch；coordinator 再匹配当前 resident/tag/epoch/key。
```

不 ready 的请求不推进 issued；C stall/延迟 D 不 set lower。
没有 TileLink ReleaseAck NACK/retry 协议：denied/corrupt 是真实断言失败，不能伪造 receipt。
key 不匹配/过早 ACK 不释放。任意恶意重复同 key ACK 在 source 被重新使用后出现不属于
TL 协议允许的行为；合法响应延迟不会通过当前源序列化与 epoch/owner 检查误标新 image。

## 7. 关键 race 清单

STATIC_PASS 表示静态链路明确；已有动态证据额外注明，不表示穷尽交错。

| 场景 | 状态 | 当前依据/下一步 |
|---|---|---|
| same-packet repeated spec write | STATIC_PASS | 已有独立重复写/读回且无额外 preservation |
| cross-packet spec overwrite | STATIC_PASS | unsafe wait→PASS→receipt；定向+system |
| safe but not preserved | STATIC_PASS | lower=0 不 grant；上面真实 system 因果链 |
| preserve backpressure | STATIC_PASS | request.fire 才 issued；C/D stall、bank stall、held ACK 已动态命中 |
| preserve retry | STATIC_PASS | valid 未 fire 不前进；LSU nack/RPQ retry 不丢 owner；ReleaseAck 失败不支持静默重试 |
| late acknowledgement | STATIC_PASS | early/旧 generation 注入均不释放；合法晚到由 pending descriptor 保存 |
| line/slot reuse | STATIC_PASS | 连续超过 associativity 替换/重填通过；epoch+transaction+pending ACK drain |
| refill conflict | STATIC_PASS | 实际 data port1 每拍 gate；unsafe refill/replay 通过；未穷尽所有同周期交错 |
| replay conflict | STATIC_PASS | retry 不释放 head；系统 REPLAY_EFFECT=8739、REPLAY_UNCLOSED=0 |
| SC success | STATIC_PASS | 同包成功经统一 grant/port0；成功的跨包 SC 未独立定向 |
| SC fail | STATIC_PASS | 无 port0 fire/key change；保守 preservation 可能发生，但不产生 SC 数据 effect |
| AMO interaction | STATIC_PASS | 跨包阻塞、old/new、terminal stall 不重复 effect 已测 |
| preserve completion + overwrite same cycle | STATIC_PASS | pending line 仍 freeze；lower 是寄存 set；issued/clearPending 禁止两写口命中 snapshot |
| exit outstanding | STATIC_PASS | ordered 包括 active WB+pending ACK+coordinator；真实 exit snapshot 全归零 |
| matching receipt + 同拍 probe invalidate 的精确撤销分支 | STATIC_PASS / NON_BLOCKING_COVERAGE_GAP | `preservationRevoked` 与 `crossPackageWbDone` 同拍求值；只有未撤销才置 `lowerPreserved`，probe meta write 同时更新 resident/epoch。无独立 CASE，但 RTL next-state 唯一且有冻结/epoch断言 |
| refill 与 receipt 的精确同拍争用 | STATIC_PASS / NON_BLOCKING_COVERAGE_GAP | 两个 dataWriteArb 输入只能产生一个实际 data fire；同 slot refill 还受 `installDrain` 的 active/pending WB 检查，incoming image 必须匹配 reservation/epoch/transaction/full key。无独立 CASE，但不能把旧 receipt转给新 image |
| 任意长期压力下进度/所有仲裁排列 | OUT_OF_SCOPE_FOR_STAGE2 | 属 liveness/fairness/stress；当前静态状态机无已知永久吞请求路径，已有运行 `unclosed_preservation=0`、`EXIT_REAL_OUTSTANDING=0` 且正常排空。它不是本阶段 safety acceptance 条件 |

WB 数据缓冲在 C-last 后可服务 probe，pending ACK 独立；WaitSafe 不占 WB。
L2 releaseAck queue 与 earlyD beat-lock 仲裁，earlyD 开始前须 s4_ready；避免
ACK queue满→s4停→新多拍D锁住→ACK无法排空。该特定环在真实 SourceD 的三份 clean
receipt+四拍 Grant 场景排空，ACK/D 数量及完整数据独立检查通过。有限测试不证明无限公平性。

## 8. 实际修改

```ini
CODE_CHANGES=NONE
FUNCTIONAL_CHANGES=NONE
CHECKER_CHANGES=NONE
TRACE_CHANGES=NONE
```

仅 documentation-only：本报告、`state/current_debug_state.md`、`history/timeline.md`、
`scripts/README.md`、`AI/Design/stage2_l1_preservation_20261017.md` 更新当前证据入口和边界。
审计 hash、git 状态/patch、原始事件摘录保存在 A，不进入运行输入。
本轮 `git diff --check` exit0，5份文档的本地 Markdown 链接无缺失；这些是文本检查，
不构成新的编译、离线测试或硬件验证结果。
未 reset/清理/同步/提交，未修改 sources/，全部用户/Stage 1/Stage 2 改动保留。

## 9. 最终关闭判断所需的真实检查项

| 检查 | 实际名称/来源 | 条件 |
|---|---|---|
| overwrite gate | `write grant bypassed L1 preservation`；Stage2 analyzer `speculative_overwrite_without_safe_preserved_predecessor` / `different_writer_overwrote_unsafe_image` | 断言不触发，errors 无对应条目 |
| receipt 归属 | `preservation_flag_without_matching_receipt` / `preserve_done_without_matching_snapshot_and_ack` | errors=[] |
| lower 因果 | `ReleaseAck before final bank commit`；`matched_ack_without_lower_commit` | 断言不触发，errors=[]；结合真实 SourceD 独立 bank 判据 |
| freeze/drain | `WB snapshot accepted before old grants/install owner drained`；`semantic write changed a frozen WB snapshot`；`refill changed a frozen WB snapshot` | 断言不触发 |
| refill | `same-address refill would destroy an unpreserved image`；`refill bypassed L1 preservation gate`；`active refill owner changed` | 断言不触发；Stage 1 owner/refill checker PASS |
| exactly once / closure | `duplicate_pending_snapshot` / `duplicate_pending_preserve` / `unclosed_snapshot` / `unclosed_preservation` / `duplicate_physical_effect` | errors=[]；PRESERVE/receipt/done 全闭合 |
| 独立数据/提前 effect | `STAGE2_STIM FORBID/ALLOW`、`STAGE2_MSHR`、10个 CASE、directed.coverage.json | 无 event/check failures、缺失/重复；denied writes0、成功对照 writes1 |
| architectural/exit | 既有 `DUP_EFFECT`、`LOST_EFFECT`、`REPLAY_UNCLOSED`、`CLEAR_RACE_VIOLATION`、`EXIT_REAL_OUTSTANDING`、`EXIT_DRAIN` | 全0；fence_ready=1，Stage 1 gates PASS |

没有名为 `stale_preserve_ack_accepted` 的现存 counter，不编造它；过期确认靠生产匹配逻辑、
定向 unmatched 注入、effect guard 和数据判据支持。system LOWER_COMMIT=8066、ACK=8061
来自不同客户端总体，不能把差5解释成 lost ACK。退出与每个 preservation 的闭合另有证据。

## 10. 交给用户执行的命令

本轮没有可执行代码变化，**已有同源 PASS 可复用，无须为文档修改重建/重跑**。
优先做 D/E 交接复核；若用户安排新的最终运行，A–C 用现有一条命令完成。
所有硬件命令仅供手动执行，本轮未执行。

### A. build / generation；B. directed；C. system

在原 Stage 1 环境，从任意 cwd 执行：

```bash
/data1/gzh/EC/AI/Debug/scripts/stage2_build_and_run.sh all
```

自动新建唯一 root，严格 build→directed→system；保留 source/fixture/参数/环境/tool/workload/
generated/binary/覆盖门禁，不再自动重复 offline。Stage 2 已在 R 上闭合；这些命令只用于
后续源码变化后的重新验证，不是 closure 的前置条件。

| 阶段 | 产物 | PASS/停止条件 |
|---|---|---|
| A | module.emit.log、generated/stage2.wiring.out、module.lint.log、module.build.log、system.build/build.log、build.status.json、build.artifacts.json、provenance.verify.*.log | 真实 compile/emit/wiring/lint/model/system build 及 provenance 全通过；失败立即停，不运行 B/C |
| B | module.trace.log、directed.coverage.json、directed.status.json | simulator exit0、10 CASE 各一次、独立effect/denied事件完整、无失败；失败/缺覆盖不运行 C |
| C | system.run/{trace.log,trace.fst,scoreboard.out/json,stage2.scoreboard.out/json,run.json}、system.status.json | 原 Stage1 gates + Stage2 PASS、errors=[]、missing_coverage=[]、真实退出排空 |

全部通过才可采用 summary.out 的“当前测试通过”。本报告在既有同源 PASS 和静态 race
审计基础上给出 Stage 2 CLOSED；这仍不扩展为任意未来配置、Stage 3 或无限 liveness 证明。
工具失败保留原始 exit code；判据失败1、缺覆盖3、参数/缺工具2；用 status 区分工具退出3。
失败先看 root/summary.out 和 root/runner.log，再看其中指定的原始阶段日志及 `.errors.out/json`。
`all` 不自动增加随机种子/其他 workload，也不补第7节列出的非阻塞精确同拍 coverage gap。

如确需分阶段停点（可选，保持同一终端环境；不用这组命令重复已有 PASS）：

```bash
export STAGE2_ROOT="/data1/gzh/EC/AI/TMP/stage2_final_$(date -u +%Y%m%dT%H%M%S)_$$"
/data1/gzh/EC/AI/Debug/scripts/stage2_build_and_run.sh build
```

A 成功后 B：

```bash
/data1/gzh/EC/AI/Debug/scripts/stage2_build_and_run.sh directed
```

B 成功后 C：

```bash
/data1/gzh/EC/AI/Debug/scripts/stage2_build_and_run.sh system
```

后阶段自行拒绝非 PASS/来源不匹配；失败后保留 root，不覆盖重跑。A 设置的 root 初始必须不存在。

### D. provenance validation（现有 PASS run 的只读复核）

```bash
python3 -B /data1/gzh/EC/AI/Debug/scripts/stage1_provenance.py \
  --root /data1/gzh/EC/chipyard \
  --sim /data1/gzh/EC/AI/TMP/stage2_validation_agciqdp_/system.build/simulator-chipyard-v1Config-debug \
  --generated /data1/gzh/EC/AI/TMP/stage2_validation_agciqdp_/system.build/generated-src/chipyard.TestHarness.v1Config/chipyard.TestHarness.v1Config.debug \
  --manifest /data1/gzh/EC/AI/TMP/stage2_validation_agciqdp_/system.build/provenance.json
```

只核对来源/完整 generated/binary，不编译仿真。预期 `PROVENANCE=PASS`、exit0；失败停止采用
该 run 的最终结论，保留具体 mismatch，不覆盖原 manifest。该脚本不单独核对16个 Stage2脚本；
本轮 A 的 identity/inventory audit 提供这部分证据，新 all 的输入门禁也会核对。

### E. result extraction（现有报告，不重跑 checker/仿真）

```bash
python3 -B - <<'PY'
import json
from pathlib import Path
r = Path('/data1/gzh/EC/AI/TMP/stage2_validation_agciqdp_')
print((r/'summary.out').read_text())
for name in ('build.status.json', 'directed.status.json', 'system.status.json',
             'directed.coverage.json', 'system.run/stage2.scoreboard.json'):
    print(name)
    print(json.dumps(json.loads((r/name).read_text()), ensure_ascii=False, indent=2))
print((r/'system.run/scoreboard.out').read_text())
PY
```

读取已有小型报告，输出阶段退出码、10CASE、Stage2 counts/errors/coverage、原 Stage1 gates。
这是报告提取，不是新的动态验证。若要对 trace 独立重分析，用原 Stage2 analyzer，写新文件：

```bash
python3 -B /data1/gzh/EC/AI/Debug/scripts/stage2_trace_scoreboard.py \
  /data1/gzh/EC/AI/TMP/stage2_validation_agciqdp_/system.run/trace.log \
  --json /data1/gzh/EC/AI/TMP/stage2_evidence_audit_bbmws5qc/stage2.reanalysis.json
```

这只流式读取已有 trace，不启动硬件；会扫描2.7GB。本轮未执行。预期 STAGE2_TRACE=PASS、
ERROR_COUNT=0、MISSING_COVERAGE 为空，exit0；失败保留新报告，不能把原 PASS 继续当作无条件结论。
新硬件运行后将 D/E 的根目录换为它实际打印的新 root，不混用两次 evidence。

## 11. 返回分析者的最小证据包

1. 本报告与实际 run 的绝对路径；HEAD、是否又修改 RTL/fixture/checker/参数。
2. `inputs.json`、`system.build/provenance.json`、三份 `provenance.verify.*.log`；
   本轮复用证据另带 A 的 identity/inventory audit。
3. `summary.out`、`build/directed/system.status.json`（真实 exit/status）。
4. `directed.coverage.json`、`module.trace.log`（仅280KB，保留10CASE/独立effect/denied对照）。
5. `system.run/scoreboard.out`、`stage2.scoreboard.out/json`、`run.json`。
6. A 的 directed/system key-events 摘录、system.exit.txt，或新 run 对应的一条完整
   BLOCK→PRESERVE→LOWER_COMMIT→ACK→DONE→IMPORT→MODIFY 链和退出 snapshot。
7. FAIL 时额外返回原阶段日志、`.errors.out/json`、首错前后文及未运行/缺覆盖状态。

无需发送2.7GB trace/完整 FST；保留其原路径/运行时 hash，只有新分歧需要时才做窄范围提取。
同周期精确 race、任意压力公平性、多 BOOM/跨 reset/回绕边界继续显式保留，不以一次 PASS 消除。
