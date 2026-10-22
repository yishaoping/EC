# Stage3 第二次动态失败：flush 提交域与当前配置全表审计

## 结论与验证边界

当前首错属于用户分类 **C**：生产协议允许的 control flush，被 Stage3 延迟到
ReleaseAck 后的目录提交错误地送进普通 A/C transition table。不是 uncached
capability 复发，也没有证据支持非法 source 复用、提前 free 或 preservation
错误恢复状态。表的事件域没有跟随 Stage3 延迟目录提交同步，是共同根因。

修复保留普通 `transition()` 函数、全部 72 个表项及原有 eviction 检查，给
`request.control` 的最终提交建立独立且更严格的 flush 终态证明。当前配置
六个非 INVALID、非 BRANCH 覆盖状态到 INVALID 共用这个修复，不逐条放宽表项。
另补 fixture B.address restoration、C/Probe 生命周期检查及有限事件日志。

本轮仅保存现场、读源码/同源 RTL/日志、运行纯静态 Python 表展开、Python AST、
shell syntax、差异与 assignment/use 检查。未编译 Scala/C++，未运行生成、
elaboration、FIRRTL、Verilator、directed/system simulation、runner 或测试。
**静态 PASS 不代表下一轮动态 18/18 或 SYSTEM 已通过。**

## A. 当前首错与同源证据

现场：`AI/TMP/stage3_runs/run_e23qwk6h/`；保留 BUILD PASS、DIRECTED FAIL、
SYSTEM NOT_RUN。生成断言位置 `build/generated/Stage3Harness.v:12988`，
`abc_mshrs_0` 为 `Scheduler.abc_mshrs(0)`，即生产 `MSHR` 的普通 ABC 槽。
原源表 `MSHR.scala:476` 的 `transition(S_TIP, S_INVALID, p)`，由原
`MSHR.scala:433` 的 `transition()` 生成该断言；行号只属于失败 run。

本轮修改前 HEAD `1ed07c28067fad6d8aed697323b465b925895914` 与保存 HEAD 一致。
MSHR、Scheduler、Directory、Parameters、L2Preservation、SourceC/D、SinkX、
SourceX 以及两份 fixture 均与该 run inputs.json 的 hash 一致。
对应 `.before`、源码/产物 hash 在
`AI/TMP/stage3_config_audit_quv22_u8/identity.before.json`。
新源码不冒充旧生成 RTL；旧 run 不改写、不删除。

| 直接日志证据 | 解释 |
|---|---|
| A source1 Get(a) cycle227；A source2 Get(b) cycle228 | 两个非 probe source，各自独立生命周期 |
| D source1 cycle236；D source2 cycle256 | 前一组 Get 均已完成 |
| Get(b) 前 victim txn6/tag0/Q seq1 ReleaseData 与匹配 ACK | 已 validation 的 Q 完成真实保存；随后 b refill |
| `CASE validation_and_ack_same_cycle PASS`、`same_line_safe_dirty_wait_ack PASS` | 上一轮首 CASE 已越过 |
| duplicate ACK ignored，随后 `CASE_BEGIN full_provenance_collision cycle=271` | 当前 CASE 已明确打印 |
| victim txn8/source0/set0/way0/tag1/valid0/dirty0/reason2 | flush 命中 b=0x80000080；不是新 Acquire 或 Get |
| txn8 ACK/reason2 后 `TIP -> INVALID` fatal，`[313]` | 在 flush 最终提交遇到错误事件域的断言 |

保存 trace 没有逐周期内部波形。下列内部事件链由**匹配 hash 的刺激、RTL 与源码**
严格推出；不把推导写成已观测波形：

1. `full_provenance_collision` 首句是 `cleanup({{a,q},{b,{}}})`，先 validation、
   drain，再顺序走真实 control flush。不是该 CASE 的 ABA 主体失败。
2. 前一组 replacement 已逐出 a；flush(a) miss，无目录写，仅 X completion。
   b 是刚从 outer 得到的 clean TIP：physical state=3、hit=1、dirty=0、clients=0，
   image.valid=0（BASE）、outerPreserved=1。BASE 不等于无 cache line。
3. `SinkX` 将 flush(b) 编为 prioA=1、control=1、opcode=0、source=0。
   这里 opcode0 是 control 编码，不能当成 uncached Put。
4. MSHR lookup 命中；control 初始化清 s_flush/s_writeback/s_release/w_releaseack，
   无 clients，因此没有 inner Probe。SourceC 接受 clean Release(TtoN)，txn8。
   CacheCork 为 clean Release 生成携带原 txn 的本地 ReleaseAck，不写 outer 数据。
5. MSHR 仅在 issued、sent（或同拍末 beat sent）、source 路由正确、txn matching
   且未重复 ACK 时置 w_releaseack。随后 no_wait=1，目录提交与 X response 可调度。
6. **写 next metadata 的是 `MSHR.final_meta_writeback` 的 control 分支**：
   hit=0/state=INVALID/dirty=0/clients=0，provenance 清零。Scheduler 仅把
   `schedule.dir` 送 Directory，Directory 单元素 write queue 存储给定 entry。
7. Stage3 之前 flush 在 eviction schedule 写 invalid，不走普通 final transition。
   Stage3 为 ACK barrier 改成 `dir.valid := !s_writeback && no_wait`，并给命中的
   flush 清 s_writeback，因此此时走进了仍假定“flushes run as evictions”的表。
   `p=false` 将普通 `TIP->INVALID` 判 forbidden，于是触发当前 fatal。
8. request_valid/meta_valid 只在终态 schedule/no_wait 才清；repeat allocate 的
   later assignment 与 final metadata 旁路合法重装，并没有 free 后复活 TIP。

首错当拍：control flush 最终目录提交/允许 X response 与 free；相关外部 ACK
已完成。无 uncached Get/Put、Acquire/refill、新 victim replacement、validation
变更或同址 checkpoint completion。victim snapshot 是本次 flush 的 b；txn8
不是先前 Q checkpoint txn1，也不是 replacement txn6。

## B. 五元组与上一轮修复

| 位 | 源定义 | 当前值 / 意义 |
|---|---|---|
| p | `!params.lastLevel` | false，末级无 outer Probe |
| c | `!params.firstLevel` | true，有可 Acquire 的 inner client |
| m | `inner.clients.exists(!_.supports.probe)` | true，sources1/2 为非 probe Get/Put client |
| r | `outer.managers.exists(!_.alwaysGrantsT)` | false，无仅授 B 的 outer manager |
| f | `params.control` | true，有原生 control flush |

生成 RTL 的 assertion 文本明确为 `(false,true,true,false,true)`；Get(b) 已完成，
first CASE PASS。上一轮 m=false 问题已解决，没有重改 client capability。
`p=false` 不表示不能 flush；f=true 是独立能力。

## C. 配置级 transition audit

完整九状态矩阵见 [机器展开的允许/禁止表](stage3_transition_matrix_20261019.md)。
纯静态工具 `scripts/stage3/transition_audit.py` 解析真实九个 CacheState、72 个
有向非自环表项，安全展开布尔表达式；不执行 Scala，不生成或模拟硬件。
本轮还逐项及逐字比较旧 run 同源 `.before` 中的表项与 assertion helper。

- NORMAL：18 个允许 pair、54 个禁止 pair；9 个自环原表没有显式 transition()
  检查，明确标为 implicit，不冒充独立证明。BRANCH/BRANCH_C 因 b=r||p=false
  不可起源；物理 TRUNK 在 coverage 中展开为 TRUNK_C/TRUNK_CD，没有单独 S_TRUNK。
- EVICT：当前允许 TIP、TIP_C、TIP_CD、TIP_D、TRUNK_C、TRUNK_CD；在 tag miss 时
  `before=INVALID`，victim 自己由 evict 检查，不能混为 resident INVALID 恢复。
- FLUSH_COMMIT：上述六个 hit 状态均可清到 INVALID；能力条件与 eviction 一致，
  且要求 f、prioA、有效 resident hit、真实 issued/sent/matching ACK、no_wait、
  不发 Acquire/inner D、最终 state/clients/dirty/dcache/provenance 均清空。
- BYPASS/repeat：六个 resident 状态及 INVALID 可承接下一个请求；INVALID 由
  f||p 允许（flush 后的新请求）。禁止两个 BRANCH 覆盖态。
- 18 CASE 人工审查出的路径族逐项映射普通表，全部一致；静态脚本不声称能从
  C++ 控制流自动证明时序或运行所有 CASE。

除当前 TIP 外，发现五个同因潜在 forbidden flush：TIP_C、TIP_CD、TIP_D、
TRUNK_C、TRUNK_CD -> INVALID，已统一修复。这是六种状态类型的域冲突，并非
声称下次运行一定实际经过全部六种。没有发现其他已证实的普通 transition 根因。

## D. 修复与为什么保留生产断言

生产 flush 合法性不仅来自测试：HEAD 原实现的 control 初始化已经为 hit 发送
Release、按需要向所有 children Probe toN；原 eviction helper 单独覆盖 flush，
最终目录写当时发生在 eviction schedule。当前要求 matching ACK 后再清目录，
更晚的提交不会使这一生产操作失去合法性。末级 clean T 权限可用 Release(TtoN)
无数据归还，dirty 数据必须已 validation 且完成真实 outer preservation。

故修的是**断言事件域**：普通 72 条 transition 及其函数体不变，只负责
`!request.control`；control 最终提交由严格 FLUSH_COMMIT 终态断言承担。
若普通 A/C 仍产生 TIP->INVALID，原 assertion 继续失败；若 flush 提前提交、
残留 owner/dirty/key、未发送/未等 ACK、无 f、无 resident hit，也全部失败。
没有删除、disable 或将普通表的 p 条件改成 p||f，没有 protocol 数据流修改。

修改内容：

1. `MSHR.scala`：事件域分类、flush 终态断言、trace=false 默认的事件日志。
2. `Scheduler.scala`：仅传递可选 trace 和槽号；默认生产调用关闭新日志。
3. `Stage3Generate.scala`：只对 directed fixture 开启 trace；inner B.address
   使用 restoreAddress，与生产 InclusiveCache 对 A/B/C 的恢复边界一致。
   旧 host 没比较 Probe 地址，未触发首错；新的 Probe lifecycle 检查需要正确地址。
4. `stage3_test.cpp`：检查 inner Release source 到 ReleaseAck、Probe 到末 beat
   ProbeAck、A 到末 D 的生命周期；drain 加 multibeat/flush/Probe/C outstanding
   和 checkpoint balance 检查；等待 Directory 单 pending write 落 SRAM 后再确认。
   cleanup 保持真实 flush，不用 fixture reset/强制目录清零绕过生产 FSM。
5. `transition_audit.py`、矩阵、报告和当前状态：固定配置可复查静态证据。

## E. 全部 18 CASE 生命周期

缩写 I=INVALID、T=TIP、TD=TIP_D、TC=TRUNK_C、TCD=TRUNK_CD、TBC=TIP_CD。
共同尾部：实际请求 allocate -> lookup/同 tag repeat -> hit/victim decision ->
所需 wait -> 真正 Release/ACK（如有）-> Acquire/refill（miss 时且在 ACK 后）->
需要时 directory commit -> schedule/no_wait free/reload。**inner D 可早于目录
终态提交**，Acquire 的终态还等 E，不能把 D completion 当 MSHR free。
idle 显式等所有 host/hardware 队列及 pending/多 beat 排空，再 pump8 确认。
source0 仅 coherent，1/2 仅 Get/Put；inner A 和 C 为独立 source 名字空间。

| CASE | 完整生命周期中的路径与等待 / CASE 边界 |
|---|---|
| same_line_safe_dirty_wait_ack | a: I->TC(Acquire/refill)->TD(P ReleaseData)->TCD(Acquire hit)->TD(Q)。Q 覆盖先 checkpoint P/真实 ACK。Get(a) hit；Get(b) miss 经安全 Q victim ReleaseData/ACK 才 refill I->T；两 D 与全 drain 后主 CASE 完成。 |
| outer_backpressure_exactly_once | 上行 Q 的共享子检查：P reservation 保持，outer 未接受，early ACK 不释放；此处故意尚未 free。 |
| delayed_ack_freezes_predecessor | 同一事务 Put 已发完，ACK held，目录/bytes/ReleaseAck 不动；真 ACK 后才进入主 CASE 尾部。 |
| pending_same_line_request | Get(a) source1 排队在 P 后，不替换 reservation；Q 完成后执行并回 D，主尾部 drain。 |
| pending_replacement_pressure | Get(b) source2 与1区分；先等 P，再 lookup/victim/ReleaseAck/refill/commit/D/free；不以入队当完成。 |
| validation_and_ack_same_cycle | 共享 Q validation 与 P checkpoint ACK 同拍；锁仍覆盖 ACK 拍，下一拍才能 Q 修改；主 CASE 收尾排空。 |
| duplicate_ack_ignored | 主 CASE 已 drain；再发旧 checkpoint ACK，counter/directory/pending 不变；不分配新 MSHR。 |
| full_provenance_collision | **先 cleanup a,b（当前首错位置）**；再 fill(a,Q) I->TC->TD，Acquire->TCD，Q2 等 Q checkpoint/ACK 后->TD、D/free。stale 子检查 PASS 时 ACK 故意仍 held，随后释放并 idle。 |
| stale_ack_ignored | 上述 Q2 的共享子检查，旧 txn 不得解锁新 key；随后与父事务共同完成，无额外 allocation。 |
| repeated_speculative_same_line | Q2 TD->TCD；Q3 新 generation、相同 seq 被 validation 阻塞；validate Q2 后保存 Q2/ACK，Q3->TD/D/free；validate Q3 后 cleanup a,b。 |
| same_line_already_outer_preserved | fresh I->TC，clean 已有 outer 副本，Q ReleaseData->TD 不发 checkpoint；validate+flush 清理。附带 trusted Put 先保存旧 dirty P，TD->TD 发布 BASE/revoke receipt，再 Acquire->TCD，后续 Q 必须保存 BASE/ACK 才->TD；最后 validate+flush。 |
| speculative_set_victim_blocks_outer | 真实 Get/warmSet 使 a,b 均 T，hit Acquire/ReleaseData 使两者 TD；Acquire(c) allocate/miss，任一 LFSR victim 均 speculative，阻止 Release 与 refill；共享事务暂不 free。 |
| same_set_different_line_replacement | 上述 validate a,b 后，victim TD 的真实 ReleaseData 与原地址数据匹配；ACK held，不能 Acquire(c)；与后两行共用事务。 |
| safe_dirty_set_victim_wait_ack | 同一 dirty victim 已安全但仍等 matching ACK，无 premature refill/Grant；此处故意 pending。 |
| validated_victim_preserve_ack_replace | stale victim ACK 无效；真 ACK 后 outer Acquire/refill，c 的普通覆盖为 I->TC（victim 独立 EVICT），Grant/E/commit/free；随后 c clean Release TtoN ->T，cleanup a,b,c。 |
| safe_clean_victim_no_write | warmSet 两 T；miss c，clean victim Release/本地 ACK、无 outer Put，之后 refill I->TC；Grant/E/free，c Release TtoN ->T，再 cleanup 三地址。 |
| flush_clear_normal_writeback_barrier | I->TC->TD(speculative f)；control allocate/hit，validation 前无 ReleaseData；validate 后 ReleaseData、hold ACK 时不响应，真 ACK 后 strict TD->I + X/free/drain；无 Acquire/refill。 |
| validation_and_refill_replacement_same_cycle | P I->TC->TD->TCD；Get(a) source1 触发 B(toB)，ProbeAckData(TtoB,Q) 在直写前保存 P/ACK；validation Q 与实际 bank write 同拍。MSHR 元数据 TCD->TBC，Get 读 Q/D/free；最后 clean Release BtoN TBC->TD、validate+flush->I。ProbeAck 本身无 D；按末 C beat 完成 Probe 生命周期。 |

并非每个 `CASE ... PASS` 都代表独立完整事务：共享子检查在阻塞中 PASS 是有意
覆盖点，父事务最终负责真实完成与 drain；报告/工具明确区分，未为强制清零而
重置硬件。cleanup 会保留 durable outer 数据及单调 watermark，符合刺激预期；
不会假设 LFSR 总选空 way，warmSet 以两次真实 hit 证明填满。未发现新的 A source
提前复用、未收 D 的 Release source 重用、跨主事务 pending 泄漏或 reset/reuse
导致的非法覆盖态根因。新运行仍要用增强检查确认这些静态判断。

## F. Stage3 路径与 Stage1/2 风险复审

- delayed Acquire 与 delayed directory commit：原 `w_releaseack` gate 不变。
  tag miss 的 before=I 与 victim 状态分离；不能把 victim ACK 解释为状态恢复。
- victim snapshot/generation：计划初始化才递增 serial；发送后保存完整 meta；
  等 ACK 期间 identity assertion 锁定。stale/duplicate 不修改 w_releaseack。
- matching ReleaseAck：检查 request_valid/issued/sent/txn 和 source 路由；
  同拍最后 C beat 被允许，最终 commit 仍在状态寄存之后。allocate/repeat 重置
  sent/issued/probes/gotT/bad_grant，不沿用上个 transaction 的 ACK。
- preservation receipt：只更新完整 set/way/tag/key 匹配的 outerPreserved；
  Scheduler 在 ACK 拍仍锁 mutating entries。validation 不抹 key，不直接改 state。
- ProbeAckData 先完成旧 key checkpoint，再允许 SinkC bank write；MSHR meta
  用最后 C beat 的 image/dirty，等最后 probe beat 后再交 D；没有以 wormhole
  prefix 提前提交。fixture B 地址与这条生产路径的 wrapper 契约现已对齐。
- Directory result/一写队列 bypass：没有第二套“状态恢复”赋值；repeat/new tag
  分别选 final metadata 或新 directory result；final commit 与 free 同 schedule。
- 所有 meta.state、hit、dirty、clients、s_writeback、w_releaseack、valid、
  generation assignment/use 已搜索；本轮无新增功能状态赋值/协议 gate。
- Stage1/2 数据通路、接口、preservation engine 和其 assertions 未改；共享 MSHR
  只变断言事件域，生产 trace 默认关闭，风险集中于新增断言/日志的待编译性及
  真实 flush terminal checks。SYSTEM 回归仍必须在 fresh DIRECTED PASS 后运行。

```ini
STAGE3_STATUS=PATCHED_PENDING_REBUILD
STAGE3_CLOSURE=NO
STAGE3_INVARIANT_PRESERVED=YES
ASSERTIONS_DISABLED=NO
SPECULATIVE_OUTER_BYPASS_ADDED=NO
STATIC_REVIEW=PASS
CURRENT_CONFIG_TRANSITION_AUDIT=PASS
ALL_18_CASE_LIFECYCLES_AUDITED=YES
LIKELY_NEXT_TRANSITION_FAILURES_FIXED=5_ADDITIONAL_FLUSH_STATE_TYPES
```

## G. 检查产物与用户动作

`AI/TMP/stage3_config_audit_quv22_u8/transition_audit.json` 保存配置、18 allowed /
54 forbidden pair、六个旧域冲突、共享 CASE 映射及源码 hash。
`static_review.json` 保存语法/差异/原表与功能赋值不变/旧证据 hash 检查结果。
新日志前缀 `STAGE3_MSHR` 不混进 `STAGE3_TX` correctness checker；state codes
每次模型启动打印，不假定 Scala singleton 初始化顺序。MSHR cycle 从脱离 reset
计，host cycle 包含8拍 reset，二者相差8（本 fixture）；均为采样边沿前的输入
与计算终态，COMMIT 才代表提交，等待中 after 只是候选值。

用户仍使用原无参单入口。MSHR/Scheduler/fixture identity 已变化，旧 BUILD 与
下游失效；runner 新建目录 BUILD->DIRECTED->SYSTEM，任一 FAIL 立即停止。
不添加第二个动态入口，不手选阶段，不复用旧模型验证新源码。本轮未执行入口。
