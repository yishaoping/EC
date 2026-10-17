# Cache recovery mechanism：目标、当前 RTL、波形与 gap（2026-10-11）

当前实现有部分 L1 跨包等待/写回，以及真实的 L2→DRAM barrier，但还不能支持目标的 package 级 memory recovery。最直接的反例是：L2 的 safe seq4 line 被 speculative seq6 替换前没有下推 DRAM；另有 clear→stale hit→refill 已经造成成功 store 丢失。仅有 seq/tracked 和 barrier 不足以保存 validated predecessor。

本轮只做诊断和设计资料整理，没有修改正式代码、重新生成 RTL、编译或运行新仿真。

后续针对正常执行期间四个缺口的统一方案见[cache_version_preservation_unified_design_20261011.md](cache_version_preservation_unified_design_20261011.md)：只完成设计评审，尚未实施；该轮暂不实现package FAIL rollback。

## 1. 证据身份与时间

- 当前 HEAD：`a68183c83e08ed837c677aec7836c97895e3a95e`。
- 当前输入：`chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/{test.log,test.out,test.vcd}`；`.vcd` 实际为 FST，范围 `0..9304241`。
- log SHA256：`79782f0868fee7fb91608ddf3dbcafaa3fc93c4bb001e27f07d41adb463ec8f9`。
- FST SHA256：`e6da4832429aaf2748706c8ad874534f8d30414fbd50167412a9f606cf59c095`。
- 软件 SHA256：`7d440cced710e16958d0121fcac377d57266c9c54a82845e2d5dc9a3a0a9c686`。
- 完整 source/generated/run 清单：[manifest.json](../TMP/cache_recovery_gap_20261011/manifest.json)。当前 run 与本轮 functional diagnosis 相同，不能与 2026-10-10 留存 FST 混用。关键逻辑已经对照 generated RTL；完整 source→compiled simulator 构建来源仍未完全证明。

`emulator.cc:337,344` 用 `2*trace_count` / `2*trace_count+1` dump。BOOM 上升沿是奇数 timestamp，一拍对应两个 timestamp，不是纳秒。以下表中 **settled t** 是 eval 后的稳定值；该时刻 valid/ready 成立的接受沿为下一上升沿 **t+2**。用“接受沿”描述已经发生的写入，用“settled”描述当拍组合请求。

## 2. 目标语义与 backup 的必要条件

目标不变量记作：I1，新 speculative version 不破坏未安全保存的 predecessor；I2，新版本向下一层移动前，safe predecessor 先再向下一层移动；I3，speculative state 不越过 L2→DRAM recovery boundary。另有基础内存正确性 I0：成功 store 不能被旧 refill 无补偿地丢失。

**目标不必要求每个 cache 内都有双份 data。** 按目标先下推、再覆盖，L1 的 predecessor 可以留在 L2，L2 的 predecessor 可以留在 DRAM；阻塞和有序确认可以实现该版本链。需要的是可证明的下层副本和生命周期，而不是仅增加 seq 或统计桶。

当前没有通用 recovery backup：`dirtyPacketSeq/tracked` 只记归属；`crossPackagePending` 只存 set/way/tag/seq；16 项 sideband CAM 只存地址/seq；`wb_buffer` 只服务当前一次发送；L2 directory/data 仍是单 resident 版本。普通 coherence 会保存和迁移**当前值**，不会自动保留 package recovery 所需的旧 validated 值。当前部分 shadow WB 可以保存一个 predecessor，但全路径没有这项保证。

## 3. 当前 RTL 机制还原

路径缩写：B=`chipyard/generators/boom/src/main/scala`；L2=`chipyard/generators/sifive-cache/design/craft/inclusivecache/src`。行号属于本次 source hash。

| 路径 | 当前真实机制、状态与限制 | 源码位置 |
|---|---|---|
| 同包 L1 store | S1/S2 hit→S3→`dataWriteArb.in(0).fire`；按 mask 写 data；非零 seq 更新为最大 seq，不存旧 data | B/lsu/dcache.scala:1515,1554,1590 |
| cross-package LSU hit | 仅 `t_lsu && hit && write && new_seq!=old_seq && old_tracked && old_seq>safe` 触发 nack；单 pending 槽锁存 line，等待 safe 后发 shadow WB | B/lsu/dcache.scala:1027,1043 |
| shadow WB/clear | `WaitSafe→crossPackageIssued→WB idle→MetaClearPending`；`TtoN` ReleaseData，经 `wbArb` port2；metadata clear fire 立即撤销 pending | B/lsu/dcache.scala:1057–1108 |
| old 已 safe | 上述条件为假；没有 save-before-overwrite 请求或确认 | B/lsu/dcache.scala:1048 |
| S1/S2 invalidation hazard | S1 nack 主要检查 prober；shadow clear 没有同等覆盖已锁存 S1/S2，S3可继续写 | B/lsu/dcache.scala:695,809,1515 |
| 普通 L1 replacement/probe | MSHR WB port1、probe WB port0，共用 `BoomWritebackUnit`；读取当前 line 到临时 `wb_buffer` 后送 C；没有 speculative admission 的 predecessor-save gate | B/lsu/dcache.scala:26–147,924–944 |
| refill/retry | MSHR `s_meta_read→s_meta_clear→s_wb_req/resp→s_commit_line→s_drain_rpq→s_meta_write_req`；RPQ保存请求并逐个 replay；普通 LSU nack 可重试，已经成功离开队列的 stale-hit store 不再重试 | B/lsu/mshrs.scala:133,289–367 |
| replay | `t_replay` 强制 hit；RPQ出队 ready 只检查读端 arbitration；未经过普通 LSU cross-package gate；secondary miss 可合并不同 seq，主 request seq 取最大，但RPQ每项仍有自己的 seq | B/lsu/dcache.scala:571,732,1044；mshrs.scala:172–179,345 |
| refill/invalidate provenance | 每个 refill data beat 无条件将 set/way 的 seq/tracked 清零；shadow invalidate 不同步清这组寄存器；metadata、data、provenance 没有统一版本 epoch | B/lsu/dcache.scala:1085,1583–1603 |
| L2 接收 inner Release | SinkC put buffer→Scheduler/MSHR C-priority request→SourceD `rel_pop`→S4 `bs_wadr/wdat`→BankedStore；directory 改为新 seq；C请求计划通常仅执行D/目录，不创建先发旧值的 outer-C 状态 | L2/SinkC.scala:96–184；MSHR.scala:297,617–632；SourceD.scala:166,244–288 |
| L2 普通 replacement | A miss 遇到 resident victim 时设置 `s_release=false/w_releaseack=false`，按当前 resident metadata 发 C，再 acquire；有 clients 时先 probe，nested WB可更新line seq | L2/MSHR.scala:164–168,335–350,653–680 |
| L2→DRAM barrier | tracked DCache dirty candidate `seq>safe`→`barrierActive`；Scheduler真实阻止带C action的schedule；matching close ACK且safe达到seq后release；SourceC queue携带每beat seq/tracked | L2/InclusiveCache.scala:280–324；Scheduler.scala:121–180；SourceC.scala:75–157 |
| validation | allocation/result bitmap只推进连续PASS watermark；FAIL/CANCEL sticky停止相应safe推进；没有cache rollback动作 | B/lsu/dcache.scala:1116–1214 |

L2→L1 GrantData 还有一处结构性缺口：`SourceDRequest` **继承** `FullRequest`，字段中有seq，但 `MSHR.schedule.d.bits := request` 使用Acquire请求身份，而非resident data版本；`SinkA.scala:95–96`给该请求seq0/tracked0。标准TL D和BOOM refill没有返回resident版本身份，L1 refill又清零。因此从 speculative L2 返回的 data 并不会可靠地继承原所属包，后续Q可能绕过old-P检查。这是源码/generated字段路径证据；尚无本轮完整“丢tag→越界DRAM”动态反例。

## 4. 真实 transaction 的逐拍证据

### T1：同包直接写入，以及 unsafe old 的等待/下推

同包快路径：settled `393957,393959,393961,393963`，line `0x80087f80` 中四个地址依次写入；new seq=old seq=1/tracked1，safe=0，`dataWriteFire=1/blocked=0`。接受沿各为t+2。证明同包写未被水位错误阻塞，不证明所有正常访问都没有额外停顿。

line `0x8005a1c0`（L1 set135 way0）的跨包路径：

| settled t / 接受沿 | 观察 | 解释 |
|---:|---|---|
| 398151 / 398153 | seq2的普通LSU hit被nack；old seq1/tracked1，safe0 | old unsafe 分支确实阻止该store |
| 398153 | pending=1/old seq1 | 锁存等待事务 |
| 432433 / 432435 | safe=1，shadow WB request fire，param=TtoN | 先等P安全再下推 |
| 432449..432461 / 各t+2 | 四个L1 ReleaseData beat | 实际发送旧line，非统计“理论释放” |
| 432461..432467 | L2 D输出ReleaseAck；L1收到ACK后WB转idle | ACK链走通 |
| 432469 / 432471 | metadata clear fire，随后pending=0 | TtoN后失效本地copy |

注意L2内部data beats仍写到settled `432477`、接受沿 `432479`；**普通ReleaseAck早于最后data beat落入array**。这是SourceD现有流水线行为，不能单凭它判定协议错误，也不能把ACK自动当成全部data已durable。设计需要用same-address ordering/hazard或显式save-done定义保证可恢复副本已承诺，不能只等固定拍数。

### T2：old 已 safe 时直接 overwrite

| settled t / 接受沿 | 观察 |
|---:|---|
| 433881 | S1 seq4 store addr=`0x8005a208` |
| 433883 | S2 type4=t_lsu，valid/hit1、nack0、send_resp1；safe2 |
| 433885 / 433887 | S3 newseq4，oldseq2/tracked1，dataWriteFire1；pending0、blocked0、shadowWBfire0、WB idle |

`old_seq<=safe` 的分支没有强制先保存P再应用Q，目标要求尚未实现。这个窄窗口证明**没有版本保存握手**，不单凭它断言下层恰好不存在任何旧值副本。不要用T1中 `432473/432475` 的同一line作这个分支的反例：那条line的P已经shadow WB。

### T3：L2 safe predecessor 未下推即被 speculative value 覆盖

line **`0x80035e00`**：L2 set376、tag4099、way0，safe watermark=5。

| settled t / 接受沿 | 当前 transaction |
|---:|---|
| 480573 | L1开始发送safe seq4 line |
| 480577 / 480579 | SinkC req seq4/tracked1，地址匹配 |
| 480581 / 480583 | Directory安装dirty seq4，set376 way0 |
| 480587 / 480589 | L2 data beat0=`0x0006000500040003` |
| 480589 / 480591 | L2 data beat1=0；最后beat接受约480603 |
| 480755 | L1发送speculative seq6 line（6>safe5） |
| 480759 / 480761 | SinkC接受同址seq6/tracked1 |
| 480781..480785 | 同址directory lookup；480785的MSHR old meta为dirty seq4/tracked1、way0 |
| 480785 / 480787 | Directory直接写newseq6，没有predecessor-flush状态 |
| 480793 / 480795 | `SourceD.bs_wadr/wdat`接受beat1=`0x0000000900080007`，覆盖old beat1=0；新line最后beat接受约480807 |

`480535..480825` 窄trace中 `SourceC.req_valid/c_valid` 始终0；另审计 **0..480825的全部SourceC**，在该地址未出现任何outer C beat。L2 SourceA仅发AcquireBlock/AcquirePerm，不提供另一条旧line data写出路径。故seq4副本没有按目标先经外层C保存到DRAM，即被seq6覆盖：这是 **I1/I2顺序违例的直接波形证据**。本例不是unsafe数据进DRAM的I3反例，也不声称已经触发实际FAIL后的rollback失败。

L1→L2的430个unsafe dirty WB本身**不等于违规**：目标允许它们，只要L2先保存predecessor。T3才是没有满足该前提的具体反例。禁止把修复方案写成“全部speculative L1 eviction等自身safe”来代替用户要求的协议。

### T4：metadata clear→old hit store→refill overwrite

目标地址 **`0x8005a1e8`**，属于T1的line。

| settled t / 接受沿 | 最早异常与后续数据丢失 |
|---:|---|
| 432469 / 432471 | shadow metadata clear；同拍S1已有该store的旧metadata |
| 432471 | pending已清；S2仍命中coh3，nack0/send_resp1 |
| 432473 / 432475 | S3将seq2的`0x1080`写入L1，provenance变seq2/tracked1 |
| 432517 / 432519 | MSHR3进入`s_commit_line` refill；第一个beat就将该way provenance清为0/untracked |
| 432525 / 432527 | 目标row refill高64位=0；覆盖已经写入的`0x1080` |
| 432531之后 | RPQ从后续请求replay，原成功store不在RPQ；432539后seq2恢复只是另一store的写入 |

`test.out` commit153039（PC `0x80000784`）写`0x1080`；commit227820（PC `0x800007c0`）读回0；load响应在FST `1776443`已是0。当前已确认的局部first-bad是432471 stale-hit成功，接受写432475、确定丢值432527，不要从最终checksum倒推首因。

**分类：** 首先违反I0（成功store持久性/同址coherence ordering）。该例保存过旧P，丢的是新Q；不能把它单独当作“旧safe predecessor丢失”或“I3 unsafe进入DRAM”的证据。它发生在局部pipeline，但根因是新协议缺少line ownership、drain/stale-request取消、refill/replay完成握手。需要完善状态机与旧cache hazard集成；只延迟pending清零、加固定等待或调整统计不能证明正确。

### T5：MSHR replay 绕过普通 LSU 的跨包控制

line `0x80018400`，safe=111；三次S3 write均由 **t_replay** 路径进入（检查对应前一拍S2）。

| settled S3 t / 接受沿 | new seq / addr | 写前line归属 |
|---:|---|---|
| 2034567 / 2034569 | seq111 / `0x80018402` | untracked |
| 2034569 / 2034571 | seq112 / `0x80018406` | seq111/tracked1 |
| 2034571 / 2034573 | seq111 / `0x80018404` | seq112/tracked1（112>safe111），blocked0、writeFire1 |

这是不同word，不证明同一word的新值被旧请求反序覆盖；却证明同一line可混入跨包写，普通`t_lsu`等待约束在replay未执行。最大seq只保守保留112，不能恢复111/112两版data。必须在RPQ出队/secondary admission或可保留请求的replay ownership状态处理；不能到S2简单nack一个已经RPQ出队的replay。

### T6：L2 victim barrier→validation→release 正常链

seq105 victim line `0x80037680`（set474/tag4099）：

| settled t / 接受沿 | 观察 |
|---:|---|
| 1480251 | safe104，unsafe candidate105，allow0，无SourceC request |
| 1480253 | barrierActive1/seq105 |
| 1480261..1480263 | BOOM service105→R_IC close ACK105 |
| 1483677 / 1483679 | L2 safe105，release1/allow1，SourceC request seq105接受 |
| 1483683 / 1483685 | 外层C第一beat seq105/tracked1接受 |

本轮五个candidate最终均resolved；已审计的tracked dirty DCache实际request没有`seq>safe`。日志L2 dirty45、required8、verified8、unverified0，其中37个nonverify。可以确认这条**有正确provenance的候选/发送链**遵守I3，不能提升成全路径形式证明。

## 5. 目标→当前实现→gap 对照

| 目标 | 当前状态 | recovery影响 / 证据 |
|---|---|---|
| 同包重复store直接覆盖 | 实现 | T1快路径；不需要每次保存同包中间值 |
| Q等unsafe P validated，再保存P | 普通tracked LSU hit部分实现 | T1有效，但T4失效后pipeline不隔离，T5 replay不检查 |
| old已经safe也先推L2 | 未实现 | T2直接写；I1/I2保证缺失，lower副本是否恰好存在需另证 |
| safe L1 replacement正常写L2 | 原cache路径支持 | safe写不需等水位；没有证明全路径无额外stall |
| speculative L1 eviction前L2 predecessor到DRAM | 未实现接收前保存/确认 | T3直接覆盖；普通WB port1统计不实现此条件 |
| speculative L2 victim等safe再进DRAM | 正确tag条件下已实现 | T6；不等于provenance全覆盖，也不是rollback |
| refill/invalidate/retry保存版本与数据顺序 | 不完整 | T4直接清tag/丢data；GrantData返回resident版本身份缺失 |
| P FAIL丢弃P及以后、恢复validated memory | 未实现 | failure sticky有诊断，无cache数据恢复/epoch状态机；本轮无FAIL package可动态验证 |

## 6. 最严重的五个 gap 与修改优先级

1. **G1，P0：clear/pipeline/refill所有权失序。已证明数据bug。** 首先修T4，让pending line被冻结、在途请求drain或被明确重试，clear/way reuse/refill不能让stale-hit写成功。整个事务不能只用set/way判断，需tag及generation防way复用。
2. **G2，P1：L1版本切换遗漏safe-old和MSHR replay。已发生绕过。** 同包保留快路径；不同包不论old当前safe与否，必须确认最近safe值在L2，再允许Q修改。所有写array入口执行同一版本规则；T2/T5不能只加一个普通LSU nack解决。
3. **G3，P1：L2接收speculative数据前没有保存predecessor。已证明I1/I2违例。** 内层C可以先留put buffer，但在旧值安全并保存DRAM之前不得改写resident bank/dir。需要same-address冻结、predecessor write/ack与incoming commit状态，见T3。
4. **G4，P0/P1：functional provenance和validation还依赖统计结构，refill又丢身份。** 已证明的zero-tag/统计bug和T4 tag clear需要先处理；结构上`measuredPacketAlloc=packet_alloc_valid&&trafficCounting`（dcache:1116），resultAccepted依赖该bitmap，`traffic_reset`清pending/CAM/bitmap且把safe直接设baseline（1003,1101,1413–1424）。真实barrier却直接使用这些状态。必须分离functional ownership/validated watermark与START/STOP/RESET统计；reset期间有pending的动态反例本轮未触发。返回speculative Grant也必须带来源版本或保留明确的L2 recovery ownership，不能把refill默认当safe。
5. **G5，P2但完成recovery必需：FAIL/epoch恢复控制缺失。** `barrierFailureSeq`只锁存错误；`core.scala:2064`的`l2BarrierErrorAny`未接入恢复控制。需要停止新包、选择最近**连续validated**且小于P的恢复点、处理L1/L2与MSHR/RPQ/in-flight grant、恢复检查点并重新执行；旧epoch的result/grant不能污染新执行。若P前仍有未验证包，不能假设P-1已safe。当前run291 PASS不能验证这条失败路径。

建议按 **G1+G4基础身份/状态隔离→G2/G3保存协议→G5恢复控制** 实施和验证；在G5完成前不能宣称package recovery可用。容量不足必须等待/失败关闭，不能沿用历史monitor“overflow仍旁路”的策略。

建议的状态职责（不是正式patch）：

```text
L1不同包写：WaitOldSafe → FreezeLine/Drain → SaveSafeToL2
            → OrderedSaveDone → Invalidate/Reacquire/Retry → ApplyQ
L2新spec版本：HoldIncoming → WaitResidentSafe → FreezeResident
             → SaveResidentToDRAM → RecoverableSaveDone → CommitIncoming
```

`SaveDone`必须表示旧完整data已在下层有保证、同址后续请求不会看到旧值/未完成覆盖；普通ReleaseAck允许提前，需明确现有hazard能否提供等价顺序，或新增确认。冻结期间需让完成保存必需的probe/response优先前进，保留incoming put buffer容量，避免“持有资源等safe/ack”形成死锁。无需先承诺多版本大buffer，但必须证明有限容量、backpressure和事务owner完整。

## 7. barrier仍无法覆盖的未证实风险

- `tracked=0/seq=0`访问没有I3资格：已有main seq103身份错误，但未找到由此造成真实unsafe outer-C的数据反例。
- L1地址CAM不是随C transaction分配/确认的身份：16项复用、无epoch/lifetime ACK可能丢失或串配；尚未找到本run独立错误counterexample。
- barrierActive只保存seq，不保存selected MSHR/line。`barrierAllow=...||barrierReleased` 在release拍允许当前被选的C；若候选换了或nestedWB把seq提高，可能放行另一个unsafe请求。源码风险，当前五次未观察到逃逸；应在**最终选中request**重新检查seq，而非只信原barrierSeq。
- global allow0会阻止其他带C action的safe/control请求；是否错误阻断必要数据路径、是否存在依赖死锁，当前退出/五次resolved不足以证明全场景无问题。
- 完整失败恢复、sequence wrap/new epoch、uncached/MMIO/外部coherent agent的可撤销边界未验证。这里的结论限于本配置和上述cache路径，不延伸为多核或I/O恢复证明。

## 8. 修改前最小debug/assert/stat

| 最小观测组 | 信号 | 最小性质 |
|---|---|---|
| L1 line owner | `{addr,set,way,tag,generation}`；S1/S2/S3 seq/STQ/token/type；clear valid/fire、hit/nack/send_resp；store/refill write fire+mask/data；RPQ replay fire | clear/owner变更后，stale请求不得成功写或完成；已成功store只能由更年轻同址写覆盖，或完整进入WB/重试，不能被旧refill无补偿丢失 |
| predecessor顺序 | old/new seq、safe；snapshot/hash；save req/fire/done；L2 innerC commit与old/new dir、bank write；outerC ACK | 不同包apply Q前有当前P完整safe副本的save-done；L2 commit speculative Q前，同地址predecessor已经recoverably保存DRAM |
| 身份/barrier | LSQ owned seq→WB active seq→SinkC txn seq→directory→Grant/refill→SourceC queue；最终selected MSHR/line/seq及allow/release | owned包访存不得无解释变seq0；speculative refill不得变untracked；最终tracked dirty C request/fire均`seq<=safe`，包括release拍 |
| failure/drain | fail seq、恢复cut/epoch、每类owner/pending；统计RESET与functional水位 | FAIL后旧epoch不可继续修改data；RESET统计不清功能pending、不虚增safe；恢复完成才能admit新epoch |

先增加三个事件计数即可：`different_pkg_apply_without_save`（区分LSU/replay）、`l2_spec_commit_without_pred_save`、`stale_store_after_clear`；预期全为0。barrier的cycle/attempt计数与独立store/line、物理handshake分开。assert需要用generation和数据承诺，而非“只要hit就是合法”或“收到ACK就默认完整保存”。

## 9. FAIL、程序结束与统计口径

全部FAIL触发逻辑、逐包重建和首次统计divergence详见[functional diagnosis](../Debug/history/reports/functional_diagnosis_20261011.md)。本轮gap分析不把统计FAIL当成cache恢复证明：

- `test.log:17,20` store差164、load差258全在cacheable类；main在snapshot边界把所属seq输出0而少计。291个包实际普通访存重建与checker逐包一致，属于main身份/计数bug；身份也用于barrier，不能说只是无关显示问题。
- `test.log:6 verified=0`为真实benchmark功能失败；T4已有具体data丢失及后续错误读。不声称全部parent mismatch都已由这一个地址逐一解释。
- `test.log:41 END FAIL`汇总traffic report，**没有合并benchmark verified**；程序main又返回0，所以test.out simulator PASSED只确认退出，并不确认功能正确。
- L1-L2 `unverified=430`允许speculative移动，不能单凭数量判错；T3证明缺少predecessor保存。L2 `unverified=0`是在watermark放行后的物理点统计，与5次barrier候选不矛盾。
- `cross_package_store seen=394798`计blocked重试片段，非独立store/line，也非实际stall周期；153次实际shadow WB不能与其直接一一比较。

结束时safe=291、checker/result/validation/strict/barrier pending排空，L1没有已正确tracked且`seq>safe`的line；356个tracked line为safe归属，不等同unchecked残留。MSHR3仍处于`tohost`的`s_drain_rpq`、fence_rdy0并有退出循环STQ，属于正常HTIF退出尾流的证据；整机没有完全静止，身份缺口也使“所有unchecked state均不存在”尚无法确认。

## 10. 可复现证据

新增窄trace位于 `AI/TMP/cache_recovery_gap_20261011/`，不删除旧证据：

- T1：`same_package_writes.txt`、`cross_wait_safety.txt`、`shadow_l2_clear.txt`。
- T2：`safe_predecessor_overwrite.txt`（432790..433930）。
- T3：`l2_safe_predecessor_overwritten.txt`（480535..480825）、`outer_c_before_l2_overwrite.txt`（0..480825）、`outer_c_predecessor_audit.json`（目标地址outer C列表为空）。
- T4：`clear_refill_event_values.json`，以及functional diagnosis的`432430..432548`窄trace。
- T5：`older_replay_on_newer_line.txt`（2034515..2034590）。
- T6：`l2_barrier_accept.txt`、`l2_barrier_event_values.json`。

已有baseline FST reader可复用，不需重新运行仿真。例如：

```sh
FST_TRACE_BASELINE=1 AI/TMP/diagnosis_20261011_fst_baseline \
  chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd \
  480535 480825 \
  'subsystem_l2_wrapper.l2.(l2SafeWatermark|mods_0.(sinkC.io_req_.*|directory.io_.*|sourceC.io_.*|sourceD.io_bs_w.*|abc_mshrs_0.(request_.*|meta_.*)))' \
  > AI/TMP/cache_recovery_gap_20261011/l2_predecessor_recheck.txt
python3 AI/TMP/cache_recovery_gap_20261011/trace_table.py \
  AI/TMP/cache_recovery_gap_20261011/l2_safe_predecessor_overwritten.txt \
  480785,480793 \
  '^mods_0\.(abc_mshrs_0\.meta_.*|directory\.io_write.*|sourceD\.io_bs_w.*|sourceC\.io_(req_valid|c_valid))$|^l2SafeWatermark$'
```

历史monitor规格见[cross_package_barrier_monitoring.md](cross_package_barrier_monitoring.md)。它的无stall/overflow旁路限制属于早期测量阶段，已被本轮用户的functional recovery目标取代，不能作为功能实现的例外。
