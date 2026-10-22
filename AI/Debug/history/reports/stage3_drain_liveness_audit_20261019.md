# Stage3 drain timeout：reset 期 host 账本污染与全入口 liveness 审计

## 结论与范围

`run_ybxmr7og` 的首错**尚未进入 preservation protocol**。实际卡住的是
`stage3_test.cpp::Run::idle()` 的 host 全事务 drain，确定不释放的项是
`pendingProbes.empty()`。上一轮新增 Probe 生命周期检查时漏了 reset 门控：
host 在 cycle0、第一个同步 reset 上升沿之前将 B.valid 记成 Probe，但 DUT
在 reset 后没有这一事务；账本项永远等不到合法 ProbeAck。

分类为 **C：stale host outstanding 状态**（由 harness 的 reset/握手记账错误
造成），不是存在一个未回应的合法 Probe，也不是 preservation 的 self-deadlock。
修复统一跳过 reset 期间**所有**握手记账、queue/counter 修改及 stall 历史采样；
reset 期间 host valid/ready 确定拉低，reset 仍正常打时钟。没有清空活跃事务账本
来跳过 drain，没有删除任何 drain 条件、改 timeout 或改硬件 barrier。

同时逐项审查 checkpoint drain、全部九类用户指定路径以及 trusted A write /
ProbeAckData 入口。未发现有源码证据的新硬件等待环，故没有无依据改协议。
新增 drain 子条件与 pipeline 观察输出、有限事件/周期日志及 timeout snapshot。

只做静态工作：未构建/编译 Scala 或 C++、未生成/elaborate/FIRRTL/Verilator、
未运行 directed/system simulation、runner 或测试。以下 PASS 是静态审查结论，
不等于动态 18/18 或 SYSTEM PASS，也不是对任意外部不响应的无条件活性保证。

## A. 来源与精确 first bad

现场：`AI/TMP/stage3_runs/run_ybxmr7og/`，SOURCE_PROVENANCE=PASS、BUILD=PASS、
DIRECTED=FAIL、SYSTEM=NOT_RUN。主日志只有17行。

修改前 HEAD `1ed07c28067fad6d8aed697323b465b925895914` 与 run 一致；用户要求的
L2Preservation、Scheduler、SourceD、SinkC、SourceC、MSHR、Directory、两份 fixture
以及相关 SinkD/SourceB/SinkE 均与 inputs.json hash 一致。
新证据目录 `AI/TMP/stage3_drain_audit_99ciq6nn/` 保存 `.before`、身份及旧产物 hash。
旧日志、生成 RTL、fixture 副本、inputs/result 保持原样；没有用新源码描述旧波形。

| 直接证据 | 解释 |
|---|---|
| 首行 `STAGE3_HOST B case= cycle=0 addr=80000000 param=2` | CASE 之前、reset 内的 Probe 记账；这是最早 first bad |
| CASE_BEGIN cycle28；A Acquire source0 addr80000000 cycle28 | 实际第一个合法事务 |
| MSHR ALLOC20、LOOKUP21 miss、ACQUIRE22 | 初始空 line，未有 dirty P |
| REFILL25/28(first/last)，D GrantData cycle39 | 首 Acquire 已正常取得数据 |
| COMMIT33/FREE_OR_RELOAD33，reload0、no_wait1 | 目录进入 physical TRUNK=2、clients=1、dirty=0；MSHR 释放 |
| 后面直接 `reason=timeout: drain` | 首 `fill()` 内的 `acquire()->idle()` 尚未返回 |

MSHR cycle 从 reset 后计数，host cycle 包含8拍 reset，故表中 MSHR33对应 host41；
均使用采样边沿前事件。这个换算只属于当前 fixture。

源码调用顺序是 `fill(a,p,pd) { acquire(a); release(a,p,pd); }`，而 `acquire()`
在 Grant 后调用 idle。既然此处 timeout，**P 的 ReleaseData 尚未执行，Q 尚未
enqueue**；虽然 host 已创建 p/q key，不能把 key 创建当成 resident dirty P。
日志也没有 C/ReleaseAck、L2_PRESERVE_PENDING/REQ/ACK、validation 或 Q bank effect。
因此不能重建一个并未发生的“safe dirty P -> Q -> preservation drain”事件链。

生成 `Stage3Harness.v` 的 SourceB 中：`io_b_valid = busy | io_req_valid`，
`remain` 在 `always @(posedge clock)` 的 reset 分支才清零。生成模型初始化使用
`VL_SCOPED_RAND_RESET_I`；在第一个 reset 上升沿之前，组合 B.valid 不代表合法
协议事务。无需猜具体哪个未复位寄存器为1，日志已经证明 host 在 reset 期采样。

旧 host 每 tick 先 clock0/eval，然后直接对 B.valid/ready 做 insert，最后才
clock1/eval。main 此时 reset=1。新 pendingProbes 仅在最后 ProbeAck beat erase；
DUT reset 清掉相关状态，host 没有也不应为这个假 Probe 制造回复。

## B. 两种 drain 的完整 predicate

### Host 完成 drain（当前 timeout 的来源）

`!io_active && !io_pending && aq/cq/rq/wq/eq/inject 全空 && outstandingA/C 全空 &&
pendingProbes 空 && !flushing && putBeat/grantBeat/readBeat 全为0`。

- io_active：有效 MSHR、SourceD/SourceC pipeline、SinkC 已入队 bank effect；
  io_pending：真实 checkpoint lock，包括 capture/ACK 拍。
- aq/cq：待发送 inner 请求/剩余 beats；rq/wq：memory read/真实写 ACK；eq：inner
  GrantAck；inject：刻意注入的旧 ACK。不能把 ACK 入队当完成。
- outstandingA：首 A 到末 D；outstandingC：首 Release 到 D ReleaseAck；
  pendingProbes：合法 B handshake 到末 ProbeAck beat。它们不是 cache metadata。
- flushing 与多 beat 计数：尚未接受的 X 请求、部分 terminal Put/Grant/read。
- 满足后原 pump8 和 checkpoint req/ack balance 检查保留，确保目录单写队列收尾。

本轮保持这个布尔表达式与 `.before` **逐字符规范化相同**，只抽取成 drained()。
现存假 Probe 地址80000000在集合中，足以永久否决整个 predicate。旧 trace 未
采样最终所有子条件，不能把其他子条件全0冒称为波形观测；它们从合法首 Acquire
的 RTL 收尾可归零。假 Probe 是确定且独立充分的 blocker。

### 硬件 checkpoint capture drain（本次尚未进入）

`Scheduler.preservation.io.drained = SourceD.idle && SourceC.idle && !SinkC.bankBusy
&& selectedCandidateQuiescent`。

| 条件 | 具体含义/保护的 hazard | 是否包含当前未准入的破坏性请求 |
|---|---|---|
| SourceD.idle | `!busy && !s2_full && !s3_full && !s4_full`；等旧读/改写、旧 Put/Release bank retirement，避免 snapshot 读到半更新 P | 不包含尚被 Scheduler gate 的新 io.req.valid，更不等所有 MSHR free |
| SourceC.idle | `!busy && !s2_valid && !s3_valid && !queue.deq.valid`；等旧共享 read port 与 queued outer C，不在途中切给 checkpoint | 不包含还未 schedule 的 victim/当前新 Release；不等待 outer ReleaseAck |
| !SinkC.bankBusy | 等已经进入一拍 queue 的 ProbeAck bank-address effect（含必要 noop ordering） | blocked 的首 ProbeAckData 因 probeBlock 不入 queue；不能拿 raw probe.valid 当 busy |
| selectedCandidateQuiescent | Probe候选常量true；MSHR候选为 `w_rprobeacklast && w_pprobeacklast && w_grantlast`；等所选 resident 的旧 probe/refill 改写结束 | 不等 w_releaseack、inner E、s_execute、request_valid 或自身 free；不是全 MSHR idle |

L2Preservation 的真实状态是 IDLE/READ/DELAY1/DELAY2/SEND/WAIT_ACK/FAILED。
**没有名为 DRAIN 的寄存状态**：`IDLE && need && !drained` 是 drain 等待，
`capture = IDLE && candidate.valid && safe && dirty && !outerPreserved && drained`
才锁 snapshot 并进入 READ。WAIT_VALIDATION 也是 candidate 不安全时的 IDLE 等待。

这是全局 SourceD/SourceC pipeline 收尾加局部 selected-MSHR quiescence，保守但
不等整个 cache/global MSHR free。本轮没有缩小为 selected-way：本次证据并未
证明全局 pipeline drain 是首因；缩小需另证 in-flight read/data queue 与共享
SourceC 端口的所有权，不应为 host 假账本 timeout 改硬件 hazard 契约。

## C. 等待图与共同根因级修复

本次是不可达 completion 的孤儿等待，不是 A->B->C->A 硬件环：

`host idle waits pendingProbes.empty -> erase waits final ProbeAck ->
reset 已取消的“Probe”没有真实事务/回复 -> pendingProbes 永不清`。

旧逻辑把 reset 期观察加入长期账本，引入了“硬件已取消、host 仍等待”的语义
分叉。统一 reset 边界修复覆盖 A/C/B/D/E、memory response、flush、outer Put
计数、validation race 与 backpressure history，而不是仅对 B 增加一次特殊清理。
reset 期 host valid/ready 拉低，clock/time 仍推进，所有功能 handshake bookkeeping
在 guard 的 return 之后；没有 pendingProbes.clear() 或伪造 ProbeAck。
reset 后增加零事务账本断言，首次污染直接报错，不再拖到某个 CASE drain。

修改文件：

- `stage3_test.cpp`：上述 reset 修复；原 drain 等价抽取；所有 until timeout
  前打印 DRAIN_BLOCKER、完整 host 集合/队列/beat 数与硬件 snapshot。
- `Stage3Generate.scala`：只透出 Scheduler 的诊断 bundle，不加 protocol input。
- `Scheduler.scala`：诊断 bundle、drain 四条件/selected OH、MSHR masks、请求
  valid/ready、pending address、issued/ACK；trace开启时状态变化或每256拍记录。
- `L2Preservation.scala`：只观察 state、issued、原始 D.fire；原匹配完成信号保留。
- `SourceD.scala`：只观察 s1_busy/s2_full/s3_full/s4_full。
- `SourceC.scala`：只观察 busy/s2_valid/s3_valid/queue_valid。
- 本报告、current state、timeline、scripts README。

SourceD/SourceC/L2Preservation/Scheduler 去掉上述诊断后必须与本轮 `.before`
逐字相同；静态检查保存这一验证。SinkC/MSHR/Directory 不改。

## D. 全入口 liveness audit

| 路径 | 进展链/候选等待环检查 | 本轮判断 |
|---|---|---|
| same-line safe dirty P / Q | Q 的 D schedule 被 gate，尚未进入 SourceD；等旧 SourceD/C 和已入队 SinkC 清空才 capture。旧 C ReleaseData 已接受的续 beats 不依赖新 request admission。ACK 后 exact receipt 使 destructive gate 解除 | 没有把 Q 自身计入 SourceD drain；当前首错在它之前 |
| set-victim safe dirty | 走 MSHR Release/ReleaseAck victim 路径，不必进入同址 checkpoint capture；SourceC 使用现有 SourceD.evict_safe 等旧读/改写，匹配 ACK 后才能 Acquire/tag commit | 不等被延迟的 Acquire 才产生 ReleaseAck；无反向边 |
| speculative victim validation 后 | unsafe victim 不发 ReleaseData；watermark 使 outerSafe 成立再走前行。unsafe candidate 不霸占 checkpoint 引擎，runnable 优先选 safe+quiescent 候选 | 等外部 validation 是契约，不因全局 freeze 把 validation 本身停掉 |
| outer backpressure | SEND 持有同一个 beat/txn；等 memory ready。此时 capture 已完成，不再反复等待 drained；旧 SourceC 在 capture 前已完成发送 | 外部不给 ready 会停，不能删 barrier；无内部闭环 |
| delayed ACK | 所有 Put beats fire 后进入 WAIT_ACK；dedicated source 的 D.ready 恒真，不经过 pending-set request gate。只有 matching non-denied ACK 释放 | 没有 ACK->新 schedule->ACK 的依赖；stale/early/duplicate 不释放 |
| pending same-line request | capture 后只挡新同 set admission；当前 pipeline 和已接受的 A/C 续 beats仍可收尾。当前 destructive Q 尚未发给 SourceD；queued请求不计入硬件 capture drain | host idle 必须在完成主事务后使用，不能在刻意 held ACK 时当全排空；原 CASE 顺序正确 |
| replacement pressure | 其他 queued MSHR/request 不直接计入 selected quiescence；准备 capture 时停新 D/C schedule，但已有 pipeline 不读此 gate。不同 set 的 refill 不被误当 selected resident 的 pending | 保守全局有限旧 pipeline 等待，无 current-request self count |
| validation+ACK 同拍 | ACK 拍 lock 仍有效，receipt 在寄存沿更新；匹配 complete 使 FSM回 IDLE；下一拍解锁并根据新 receipt 重算 candidate | 不能同拍提前改 P；也没有只置 ACK 却漏清 state 的路径 |
| flush/clear/writeback | flush 命中走 safe victim Release/ACK，unsafe resident先 validation；clean Release 由 Cork 返回本地 ACK。最终 INVALID/X 不参与 checkpoint capture 的 idle 条件 | ACK 不依赖 delayed INVALID 或 free；旧 flush terminal assertions保留 |
| trusted A Put（附加） | 来源与同址 Q 一样先保护旧 dirty key；PutBuffer 未被当成 bankBusy，SourceD 未接收当前 Put，因此不会等待其自己完成 | BASE 变更仍撤销旧 receipt；不绕过安全门 |
| ProbeAckData（附加） | 首拍在 probeBlock 时既不入 bank queue也不发 metadata response；Probe候选 quiescent=true，**不等这个被阻塞的 ProbeAck 自己**；旧 queue排完后保护 P，ACK 后准入首 C beat | 排除了 `capture waits ProbeAck -> ProbeAck waits preserve` 典型环 |

另外逐项复核：

1. **SourceD drain vs gate**：drainForCheckpoint 只限制新 Scheduler D 请求。
   已入 pipeline 的 busy/full 清理由 s1_last/s2_latch/s3_latch/s4_retireReady 推进；
   bank write、PutBuffer/ReleaseBuffer pop、inner D 和已接受续 beats不读 preservation
   freeze。SourceD ReleaseAck queue 已提交的数据无需为 snapshot 再等 inner ACK 消费。
2. **SourceC drain vs共享端口**：capture 前 lock=false，旧 SourceC 仍可使用 read
   port；capture要求 SourceC.idle，故 capture 后切走端口不会截断正在读的 Release。
   SourceC.idle 不等待受 gate 的未来 MSHR.c.valid。
3. **SinkC drain**：bankBusy 观察实际一拍 queue，当前 blocked Probe首拍没有入队，
   旧 admitted Probe continuation可通过并清队列；没有用 raw Probe 请求当 busy。
4. **MSHR quiescence**：需要的 probe/refill completion 从 SinkC/SinkD直达 MSHR，
   不经新 request admission；安全 runnable 才启动全局新 D/C暂停。MSHR自身仍有效
   是正常的 snapshot owner，不要求 free。repeat 也不能在 reservation ACK 拍变 meta。
5. **Directory**：先前写队列可以独立 drain/旁路，request gate 只挡新同 set输入；
   capture不等待当前Q尚未获准的 directory commit；host尾部pump8仍保留。
6. **有效/就绪与同拍完成**：SourceD full位“清旧再装新”的最后连接优先级正确；
   SourceC末 read beat清busy且pipeline/queue仍计非idle；SinkC pipe queue 同拍替换
   不谎报empty；ACK末Put beat同拍可匹配但set锁直到边沿；snapshot身份保持到匹配ACK。
7. **组合依赖**：SourceD.idle不含当前io.req.valid，避免 `drain -> gate -> idle`
   组合环。SourceC.idle用寄存pipeline/queue状态；SinkC.bankBusy为已入队valid；
   selected quiescence用寄存wait位；capture产生lock后不依赖新的schedule fire。
   本轮只是源码依赖审查，没有运行新的 FIRRTL combinational-loop 检查。

有限旧事务 drain 的进展仍要求合法 peer 最终提供剩余 A/C beats、接收 D/C、
返回 outer response，且 validation 最终到达；任意永久 backpressure、denied ACK
的 fail-stop 或无限高优先级流量公平性，不能由本轮静态审查宣称全部解决。
在用户指定入口及当前 finite fixture 的依赖图中，除已修 host 孤儿项外，
**没有证据支持其他内部 deadlock cycle**。

## E. 诊断与静态验证

下一次任何 until timeout 会在失败前打印 `DRAIN_BLOCKER=<并列具体项>`，包括
HOST_PENDING_PROBE、HOST_OUTSTANDING_A/RELEASE、各 host queue、PARTIAL_TRANSFER、
HARDWARE_ACTIVE、CHECKPOINT_SOURCE_D/C、SINK_C_BANK_QUEUE、SELECTED_MSHR_RESPONSES
或 WAIT_VALIDATION。输出含 CASE、cycle、preservation state、四 drain 子条件、
候选 selected/safe、pending地址/set/way、pipeline busy masks、MSHR masks、当前
request valid/ready/fire、issued、raw ACK seen、matching ACK、validation/watermark。

state编码0..6为 IDLE/READ/DELAY1/DELAY2/SEND/WAIT_ACK/FAILED。
SourceD busy mask bit0..3为 s1 busy/s2 full/s3 full/s4 full；SourceC bit0..3为
busy/s2 valid/s3 valid/output queue valid。selected bit0为Probe，bit(i+1)为MSHR i。
没有有效 candidate/lock 时，地址和quiescent等附带值是 don't-care，不能单独据其
判定正在等待。raw ACK seen不等于matching ACK。硬件 trace 前缀 STAGE3_DRAIN 与
checker STAGE3_TX 分离；CASE 由相邻 host日志与共享cycle关联。

静态产物：`AI/TMP/stage3_drain_audit_99ciq6nn/static_review.json`、
`transition_audit.json`。检查包括 git diff --check、所有新增/修改文件空白、
Python AST、bash -n、18 CASE清单/timeout/reset拍数不变、drain predicate等价、
功能协议文本去掉观察项后不变、诊断字段全连接/printf参数计数及旧现场hash不变。
未对 Scala/C++作编译级语法保证，新日志/端口仍需用户 fresh BUILD 验证。

```ini
STAGE3_STATUS=PATCHED_PENDING_REBUILD
STAGE3_CLOSURE=NO
STAGE3_INVARIANT_PRESERVED=YES
SPECULATIVE_OUTER_BYPASS_ADDED=NO
PREDECESSOR_OVERWRITE_BEFORE_ACK=NO
STATIC_REVIEW=PASS
DRAIN_LIVENESS_AUDIT=PASS
ALL_DRAIN_ENTRY_PATHS_AUDITED=YES
KNOWN_DEADLOCK_CYCLES_REMAINING=NONE
```

MSHR、SinkC、Directory与 preservation功能 gate均未改；Stage1/2旧closure属于旧树，
本次观测端口的编译及整机回归仍 pending。用户继续用同一个无参 runner；fixture
与生产源码 identity变化使旧 BUILD/下游失效，新目录 BUILD->DIRECTED->SYSTEM，
失败即停。本轮没有执行入口，不要求手选阶段或设置 STAGE3_ROOT。
