# Stage 3 首次动态失败：uncached stimulus 与 client 配置不一致

## 结论与验证边界

**分类 C：directed harness 的配置/刺激不一致。** 首个失败是
`same_line_safe_dirty_wait_ack` 收尾阶段的 replacement-pressure Get(b) miss。
该请求正常经过 victim Release/ReleaseAck 和 refill，最终产生 clean TIP；
fixture 却把只用于 uncached Get/Put 的 source 1 声明为 Probe client，使
transition table 的静态能力 `m=false`，将该 uncached miss 路径判为不可能。
另外，同一个阶段未等第一个 Get 返回 D 就排入第二个 Get，二者都用 source 1，
没有 A→D 生命周期保护，存在未完成 source 复用风险。旧 trace 没记录 inner A/D
握手，不能报告具体重叠拍；它不是已证实的本次 assertion 原因，也不是
`abc_mshrs_0` 的 reset/reuse race，但应从刺激中消除。

本轮只修改 Stage3 fixture 的 client 配置、source 分配和诊断。生产 MSHR、
transition table、所有生产断言及 preservation gate 保持本轮开始时逐字不变。
未执行 build、Scala/C++ compile、elaboration、RTL generation、FIRRTL、Verilator、
simulation、runner 或测试。修复后的动态行为尚待用户运行原单入口验证。
`STAGE3_STATUS=PATCHED_PENDING_REBUILD`，`STAGE3_CLOSURE=NO`。

## 证据身份

- 用户 run：`AI/TMP/stage3_runs/run_1_d9fdyq/`，原记录
  `SOURCE_PROVENANCE=PASS / BUILD=PASS / DIRECTED=FAIL / SYSTEM=NOT_RUN`。
- 当前及 run 的 HEAD 均为 `1ed07c28067fad6d8aed697323b465b925895914`。
- 修复前两份 fixture 均与 `build/fixture/` 和 `inputs.json` 的 SHA256 相同。
  保存清单内 sifive-cache 及本次推导所用 CacheCork/TL Parameters 共 25 份文件，
  均与实际源码 hash 一致。该核对不是重新执行整阶段 provenance gate。
- 主 trace：`directed/module.trace.log`，SHA256
  `ace21c813135997c14eba8da3b582240f86ab69a8ce5b6f08d1d2e9af75079a1`。
- 原 generated：`build/generated/Stage3Harness.v`，断言打印在 12515 行，
  `$fatal` 在 12527 行。生成物、原 trace 和错误清单均保持原样。
- 本轮证据、fixture 修复前副本及精确增量：
  `AI/TMP/stage3_invalid_tip_fix_3slovmd6/`，见 `identity.before.json`、
  `transition-table.audit.json`、`mshr-assignment.audit.out`、两份 fixture `.diff`
  和 `static.review.json`。

保存的 directed 只有文本 trace，没有波形或每条事件的周期戳。
`[254]` 是该模型的 Verilator 时间；host 每个 tick 调用一次 `timeInc(1)`，
不能将它当作整机 BOOM cycle，也不能据此补造中间握手的逐周期值。
下面区分 trace 直接观测与由同源 RTL/确定刺激推出的必要事件。

## A. assertion、五元组与模块定位

`Scheduler.scala:110` 对全部 MSHR 使用同一个 `MSHR(params)` 类；
`abc_mshrs = mshrs.init.init`。fixture 有 4 个 MSHR，其中 2 个普通 ABC MSHR，
其后是 BC/C 专用项。`abc_mshrs_0` 是普通 MSHR index 0；这个 index 不是
inner A 的 source ID。失败请求的 inner source 为 1，外层 victim source 为 0。

源文件：
`chipyard/generators/sifive-cache/design/craft/inclusivecache/src/MSHR.scala`。
断言体在 433 行，调用在 451 行：

```scala
transition(S_INVALID, S_TIP, m) // MMIO read
```

检查时机是 448 行的 `!s_writeback && no_wait && io.schedule.ready`。
五元组来自 401–406 行的 **elaboration 配置** `cfg=(p,c,m,r,f)`：

| 位 | 值 | 源表达式 / 含义 |
|---|---|---|
| p | false | `!params.lastLevel`；本配置没有 outer Probe 路径 |
| c | true | `!params.firstLevel`；存在 coherent inner client，可 Acquire |
| m | false | `inner.client.clients.exists(!_.supports.probe)`；原 fixture 没有声明 non-probe client |
| r | false | `outer.manager.managers.exists(!_.alwaysGrantsT)`；无只能授 B 的只读目标 |
| f | true | `params.control`；启用了 flush/control |

它们不是五个当拍事件，也不是 preservation/ACK 的布尔向量。

`cacheState`（387–399 行）将 `!hit` 强制映射为 `S_INVALID`。
`before=cacheState(meta,meta.hit)`，因此请求 tag miss 就会得到 `S_INVALID`，
即使 `meta` 实际保存着有效、dirty 的 victim。
TIP + clients=0 + dirty=0 才映射为 `S_TIP`。
保存 RTL 对这两个 coverage 状态编码为 8 和 7；它们不是物理目录 state 的编码。

保存 RTL 的触发式为：

```text
!reset && !s_writeback && no_wait && io_schedule_ready
&& before_ == 4'h8 && after == 4'h7
```

fatal 直接证明提交 gate 和这两个 coverage 值同时成立。
`no_wait` 还证明 `w_rprobeacklast / w_releaseack / w_grantlast /
w_pprobeacklast / w_grantack` 均已满足。它没有证明发生过 INVALID 复位态恢复。

## B. FIRST FAILING CASE 与因果链

CASE 是 **`same_line_safe_dirty_wait_ack`**。原 host 在开始时设置 `current`，
直到 `idle()` 完成后才进入 `full_provenance_collision`。失败位于该 `idle()` 中，
不是后面的 `speculative_set_victim_blocks_outer`。

`a=0x80000000`、`b=0x80000080`，二者 set=0、tag 分别为 0/1。
该段同时输出四个子检查 PASS：outer backpressure、delayed ACK、pending same-line、
pending replacement pressure；它们不表示整个第一 CASE 已通过。
原 `std::cout` 缓冲使这些行在 RTL assertion 文本之后才刷出，不能按混合 stdout
行位置认定它们发生在 fatal 之后。

| 顺序 | trace/刺激证据 | MSHR、目录与 preservation 解释 |
|---|---|---|
| 1 | Acquire(a)，随后 ReleaseData(P)，gen=1/seq=0 | 正常 allocation、directory lookup、refill；P 为 safe dirty resident |
| 2 | 再 Acquire(a)，enqueue ReleaseData(Q)，gen=2/seq=1；host 暂停 outer ready 和写 ACK | Q 尚不能覆盖 P，checkpoint 捕获并锁定 P |
| 3 | `L2_PRESERVE_PENDING txn=1`，early matching ACK 的 `ignored=1`，随后 `L2_PRESERVE_REQ` | 未发送完成的 ACK 不解锁；真正 checkpoint Put 发出后仍等待 ACK，P 身份不变 |
| 4 | 依次 enqueue Get(a)、Get(b)，均为 opcode=4/source=1；四项子检查 PASS | 两个请求在 P 后面等待；未等待首个 D 就排入相同 source 的第二请求，有额外 source 复用风险 |
| 5 | host `validate(q)`，再取消 `holdWrites`；`L2_PRESERVE_ACK txn=1` 后 Q 的 `L2_EXECUTE` | watermark=1；P 的 exact receipt 生效后 Q 才安装，原 P→Q barrier 工作 |
| 6 | Get(a) 的 `L2_EXECUTE tag=0 opcode=4 prio=1` | 命中 Q；随后取出 replacement-pressure Get(b) |
| 7 | `L2_VICTIM_REQ txn=6 source=0`，tag=0/gen=2/seq=1，随后 `L2_VICTIM_ACK` 同一全身份 | b miss 选中了含 Q 的 way 0；Q 已 validation，故允许写 outer；等待真实 ReleaseAck，victim snapshot 保持 |
| 8 | 同源 RTL/刺激推导：延迟的 outer Acquire(b)→CacheCork Get→AccessAckData→GrantData(toT) | `a.valid` 必须等待 `s_release && w_releaseack && s_pprobe`；只有随后 refill 才能满足 `w_grantlast` |
| 9 | `L2_EXECUTE tag=1 old_gen=2 old_seq=1 dirty=1 outer=0 new_valid=0 opcode=4 prio=1`，随后首个断言 | b 的 tag miss 使 before=INVALID；正常 Get refill 使 after=clean TIP，原 cfg 的 m=false 因而报错 |

最后一步的具体计算（MSHR.scala:270–290）：

```text
request = A.Get, control=false, opcode=4, param=0
meta.hit=false，物理 victim = TIP_D / tag0 / gen2 / seq1
req_needT=false, req_acquire=false
gotT=true, bad_grant=false
final.state=TIP, final.dirty=false, final.clients=0, final.tag=1
final.image=BASE(valid=0), final.outerPreserved=true
before=S_INVALID, after=S_TIP
```

这些 request 字段是 MSHR 保存的请求，不代表故障拍 inner A 刚发生 handshake。
故障拍直接能确定的是最终目录调度及全部 no_wait 条件；原 trace 没有当拍
sinkd.valid/allocate.valid 等信号，故不补造其取值。watermark 已由 host 设为 1，
其后未改变；victim ACK 和 refill 是达到该提交状态所必需的前序事件。

`gotT=true` 既由 fatal 的 after 值及 Get miss 计算唯一推出，也符合 CacheCork
对 writable memory 的 GrantData 自动提升为 toT（CacheCork.scala:139–155）。
`bad_grant=true` 会把 miss 的 final state 覆盖为 INVALID，不能产生本次 after。
`L2_EXECUTE.old_valid` 是 CacheImage.valid，不是 directory hit；
`outer=0` 是 victim 旧 receipt。普通 victim 的真实 ReleaseAck 通过
`w_releaseack` 记完成，不会把旧 receipt 写成 1，因此该字段不能用于否定已经观察到的 ACK。

因果层次：

- **直接症状，已证实**：最终目录调度发生 INVALID→TIP，m=false assertion fatal。
- **直接判错条件，已证实**：两 probe clients 的配置使表中 uncached 路径不启用。
- **上游触发，已证实/同源推导**：首 CASE 排队的 Get(b) miss，经正常 victim ACK/refill 生成 TIP。
- **诊断放大因素，已证实**：无 CASE_BEGIN、stdout 缓冲；另有静态发现的并发 source 复用风险。
- A/B/D/E 均不是该 first failure 的根因：没有新的 TIP 恢复写点，旧表已经支持 m=true；
  没有 reset/free 跳过计划的证据；ReleaseAck 和 preserved completion 都不写 TIP。

## C. FIX

1. `AI/Debug/scripts/stage3/Stage3Generate.scala:35`：保留 coherent source 0，
   将原第二个 probe client 改为 non-probe client `[1,3)`，准确描述 host 的
   uncached Get/Put。修正后 cfg 为 `(false,true,true,false,true)`；所有 MSHR
   共享正确参数，不对 `abc_mshrs_0` 单独处理。
2. `AI/Debug/scripts/stage3/stage3_test.cpp:17`：使用具名的 coherent/uncached/
   pressure source；首 CASE 的 Get(a)/Get(b) 使用 1/2，其余串行 Get/Put 用 1，
   Acquire、Release、ProbeAck 仍用 0。保留两个并发请求和原压力刺激。
3. fixture 只读导出 inner D.source；host 从首个 A beat handshake 到最后一个
   D beat 跟踪 outstanding source，检查重复使用、无请求的 D 完成及 source
   traffic class，`idle()` 也检查 outstanding 排空。外层故意注入 stale/early/
   duplicate ACK 的路径不被此 inner A 检查替代。
4. 增加带 host cycle、即时 flush 的 `CASE_BEGIN` 和 A/D 请求完成日志；已有
   `CASE ... PASS` 同样 flush。原 18 个 CASE 名称、顺序、断言和 checker gate 未改。

本次无需生产状态机修复：修正的是状态机输入模型的能力声明及事务身份。
TileLink 整体规范是否允许某个 Probe client 发 Get，不是本结论的前提；这里依据
本 InclusiveCache 的 `m`/transition-table contract，以及 source 1 实际始终作为
uncached requester、从未 Acquire 或持有 coherent ownership 的 fixture 用法。

## D. WHY ASSERTION IS KEPT

MSHR.scala 的完整 transition/eviction/bypass 表与 HEAD 逐字一致；本轮整个
MSHR.scala 也与修复前、保存 run 的 hash 相同。没有删除、disable 或放宽表项。

原 `transition(S_INVALID,S_TIP,m)` 已经把 uncached read miss 列为合法路径。
Get 不分配 inner coherent ownership；outer 授 T 后 L2 自己成为 TIP，且 refill
为 clean，这是原协议的合法状态。coherent Acquire 则通过 `req_acquire` 添加
请求者 client bit，获得 TRUNK_C，而不会成为无 client 的 TIP。
所以原表在真正的 m=false 配置中仍会产生同一个 impossible-transition assertion；
在准确声明 non-probe traffic 的本 fixture 中按原设计采用 m=true 的合法表项。
assertion 本身没有过时，不需要修改。dirty、client ownership、snapshot、ACK
identity、speculative outer write、duplicate preserve、premature overwrite 等
其余生产断言继续保留。

## E. RELATED PATH AUDIT

| 路径 | 静态审查结果 |
|---|---|
| 所有 S_INVALID / S_TIP entry | 搜索全部状态定义、映射、赋值和表项；9 个 coverage 状态、72 个不同状态 pair 无重复/缺项；实际 miss→TIP/TIP_D 仅分别来自 uncached read/write，Acquire miss→TRUNK_C |
| 其他相同配置根因 | 原 m=false 也会误拒绝 INVALID→TIP_D、TIP→TIP_D、TIP_C→TIP_D；纠正同一 fixture client 参数同时覆盖这些 trusted Put 路径，不逐个改表 |
| meta/state/hit 写点 | bulk `meta:=new_meta`；nested b_toB→BRANCH / b_toN→hit=false；final Release、flush、A、bad_grant 分支；未发现 preservation completion→TIP 恢复赋值 |
| victim snapshot / generation | 每个新 execution plan 增 serial、清 sent/issued；调度 Release 冻结 snapshot；ACK 前要求 meta 与 snapshot 逐字相同；匹配含已发送与 generation，源码不变 |
| Release / ReleaseAck | 真实 SourceC last beat 才标 sent；匹配且未 denied 才置 w_releaseack；stale/early/duplicate 不释放等待；ACK 不写 meta.state/hit |
| delayed Acquire / tag / refill | a.valid 仍受 w_releaseack；目录 valid 仍为 !s_writeback && no_wait；refill 来源 Grant 更新 gotT/bad_grant 和等待，final miss 清旧 key 为 BASE，无绕过 barrier |
| preservation pending / validation | checkpoint 只接受 safe candidate，锁 set 并排空 bank；完成只按完整 set/way/tag/image 更新 receipt；ACK 当拍仍冻结 mutating schedule；validation 只影响 gate，不赋 TIP |
| allocate / free / reuse | request/meta valid 在 no_wait 调度释放；同拍 reload 由后续 allocate 覆盖；repeat 用 final metadata，different tag 重新查 directory；新计划重置 gotT/bad_grant/probe/wait/release 标志；保留 allocate overlap assertion |
| 同拍 ACK / validation / directory | checkpoint complete 与 watermark 改变不会赋状态；原 receipt-mutation race assertion 保留；victim ACK 后下一次才可发 Acquire，新计划生成与 ACK 身份检查保持 |
| denied Grant / flush / nested Release | denied miss→INVALID，denied upgrade→BRANCH；flush 清目录；C Release 必须 hit，TRUNK 可降 TIP 并清 owner bit；没有 INVALID 直接从旧 snapshot 恢复的分支 |
| 全部 fixture issue 点 | 两个 concurrent Get 为 source1/2；warmSet、trusted Put、最后 Probe CASE 的 uncached Get 均 source1 且等待 drain；所有 Acquire/C 为 source0；未新增虚假第二 coherent owner |

Stage3 两条 invariant 的保护未变：

1. Q 覆盖 P 前，若 P dirty 且无 exact outer receipt，Scheduler 仍阻止 destructive
   D/bank/目录操作，checkpoint 仅在 P safe 后写 outer，并一直锁定到真实 ACK。
2. speculative resident 未 validation 前，checkpoint capture 与 victim SourceC
   都要求 `CacheImage.safe`；Acquire/refill、tag 更新仍等待 victim ReleaseAck。

本次观察中 Q 的 seq=1 在 victim 写出前已被 `validate(q)` 覆盖，不是 speculative
outer write。未为消除断言提前 Acquire、refill 或撤销 preservation barrier。

## F. STATIC REVIEW

完成 `git diff --check`、Python AST/shell syntax（不执行脚本）、源码/旧 RTL 对照、
MSHR assignment/use 搜索、全部 transition pair/静态 capability 条件核对、
18 CASE 的静态清单核对以及增量修复和原证据 hash 核验。
**18/18 是清单保持不变，不是本轮动态 CASE PASS。** C++/Scala 只做静态 review，
没有运行类型编译或生成新模型。

```ini
STATIC_REVIEW=PASS
STATE_MACHINE_AUDIT=PASS
STAGE3_INVARIANT_PRESERVED=YES
STAGE1_STAGE2_REGRESSION_RISK=本轮仅Stage3_fixture变化；无新增生产RTL风险；当前树的整机回归仍待SYSTEM
STAGE3_STATUS=PATCHED_PENDING_REBUILD
STAGE3_CLOSURE=NO
```

25 份生产源码本轮 hash 不变，Stage1/Stage2 的历史 closure 和已有用户改动均保留。
最新用户 run 的 SYSTEM 尚未运行；本轮静态 PASS 不能替代当前共享 Stage3 修改的
Stage1/Stage2 动态回归。

## G. USER ACTION / provenance

仍使用现有无参单入口。fixture Scala/C++ hash 参与 BUILD contract；本次改动使旧
BUILD 及其下游依赖失效。runner 应自动在新的 immutable run 中 BUILD→DIRECTED→SYSTEM，
任一步失败即停；旧 run 不改写，旧模型和失败定向不能借 PASS 文件复用。
本轮未执行入口，唯一用户命令保留在 current state/最终回复中。
