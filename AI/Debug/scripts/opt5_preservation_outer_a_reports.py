"""Report renderer: source-backed lock semantics, explicit missing runtime joins."""
import json

REQUIRED=['README.md','preservation_state_machine.md','outer_a_lock_semantics.md',
 '67k_latency_decomposition.md','episode_analysis.md','blocked_request_amplification.md',
 'rob_critical_correlation.md','bank_arbitration_analysis.md','hol_blocking_analysis.md',
 'upper_bound.md','candidate_fixes.md','next_run_plan.md','validation_result.json']


def write_reports(out,m):
    def save(name,text): (out/name).write_text(text.strip()+'\n')
    e=m['episodes']; b=m['intrinsic_gap_bound']; d=m['decision']; c=m['counts']
    save('README.md',f'''# Preservation / outer A：否定跨 ACK 的 packet 锁，未证明运行中的关键放大

**结论：没有证据证明“一个preservation通过outer A锁住多个后续请求，恢复>=100k critical cycles”。** 两项具体静态结论已闭合：

1. **否定锁生命周期假设**：outer A `beatsLeft` packet锁只从首个accepted Put beat之后保持到最后beat接受；不覆盖pre-capture drain，不等terminal AccessAck。target-set preservation锁才持续到ACK。L2 hit Get也不经outer A。
2. **保留另一个明确耦合**：checkpoint在waitAck时已不读bank，但全局SourceC schedule/读端仍被`preservation.io.lock.valid`禁止；其他set dirty-victim Release可能受阻，而其MSHR Acquire必须等自己的ReleaseAck。这是 **global SourceC reservation → release/acquire HOL** 的真实静态路径，尚无运行频率/critical预算。

只移除每packet必有的read/delay间隙，在当前固定轨迹中可删除的该类slot最多 **{b['cycle_upper_bound']:,} cycles**（traffic内preservation首A数≤1,623，单引擎carry-in≤1，每包7×3=21）。这是实际结构服务槽的有范围上界；**不包含bank等待、ready-low、全局drain、waitAck或执行反馈**，不限制整个preservation机制。这个局部方向低于50k，停止将“缩短outer-A intrinsic gaps”作为Opt5主线。

67,366仍是2,231笔release lastC→firstbank的实测duration，不能拆成并不存在的已记录T1–T5。尚无capture/drain/arb/outerA逐episode时间，真正preservation/lock top20和request→ROB join均为null；报告另给20个**真实release pre-bank代理episode**，绝不冒称preservation episode。

最终：`AMPLIFICATION_PROVEN=NOT_PROVEN`；`MAIN_MECHANISM=NONE_JUSTIFIED`；`OPT5_STATUS=NONE_JUSTIFIED`；`SUB1P5_FEASIBILITY=NOT_SUPPORTED`；`NEXT_ACTION=MOVE_TO_NEXT_OFFLINE_BOTTLENECK`。下一离线对象为SourceC跨ACK全局预约和release/acquire HOL，并接着看L2入口/SourceD服务。frontend保持LAST_RESORT。

软件ROI `[698301,2347224)`=1,648,923；目标 `<1,502,513`，严格saving至少146,411。全程BOOM/L2 200MHz cycles，event simulator time=cycle+103；checker100MHz不直接相加。optional完整prefix `[698301,2192911)`，未知suffix154,313。B原始正确性/capture恢复结论保持，A/newB仍REFERENCE_COMPARISON/STRICT_PAIRING_PENDING，A′未跑。

## 交付与验证

本目录包含用户要求的13项文件，加numeric/source/provenance、top20 release proxies、CPU abstract contract witness、最终决策。`source_evidence.json`保存source/generated行号和hash；synthetic witness只是协议反例/模型证据，**不是本B运行观测或RTL仿真**。

`preservation_state_machine.md`和`outer_a_lock_semantics.md`回答资源/状态；`67k_latency_decomposition.md`和`episode_analysis.md`给分布及不可恢复项；amplification/correlation/bank/HOL报告给归因边界；`upper_bound.md`给UB1–UB4和去重范围；`candidate_fixes.md`最多4项风险；`next_run_plan.md`给下一离线路径及最小bounded诊断设计。

仅新建AI下离线工具/报告及更新长期状态。本轮无硬件patch、elaboration、RTL generation、Verilator build、benchmark simulation、observation-only run、新A/B、geometry/MSHR/frontend/SVB32/promotion改动或清理。

复现（仅CPU，输出必须为新目录）：

```bash
python3 -I -B AI/Debug/scripts/analyze_opt5_preservation_outer_a.py --out AI/TMP/opt5_preservation_outerA_attribution_NEW_UNIQUE_TIMESTAMP
python3 -I -B AI/Debug/scripts/test_opt5_preservation_outer_a.py
```
''')
    save('preservation_state_machine.md','''# Preservation真实状态机与资源

来源：`sifive-cache/.../inclusivecache/src/Scheduler.scala:186–275,312–338,770–817`，`L2Preservation.scala:1–160`、MSHR、SinkC、Directory；`source_evidence.json`保存当前source及completed-B generated对应方程。候选名称中的“entry/drain”必须区分C数据缓冲、组合candidate、snapshot和bank流水排空。

```mermaid
stateDiagram-v2
    [*] --> idle
    idle --> read: candidate safe+dirty+!outerPreserved AND drained / capture
    read --> delay1: bs_adr.fire
    delay1 --> delay2
    delay2 --> send: latch SRAM read data
    send --> read: a.fire AND !finalBeat
    send --> waitAck: a.fire AND finalBeat
    waitAck --> idle: matching terminal AccessAck / complete
    waitAck --> failed: matching denied/corrupt ACK
```

从任意active state，合法零延迟末beatACK可直接完成；错source/txn/opcode/size回执被忽略并计stale。snapshot保持set/way/tag/旧image/reason，serial64bit独立身份。水位合法之后才capture；不能用新image seq替代resident key。

| 问题 | RTL答案 |
|---|---|
| 1. entry创建处 | Scheduler从每MSHR resident+schedule.D组合生成candidate，另有first ProbeAckData candidate；L2Preservation唯一snapshot在capture边沿创建 |
| 2. trigger | resident hit且destructive change；`blocked=!safe(oldImage)||(dirty&&!outerPreserved)`；safe dirty old image需checkpoint，unsafe先等水位 |
| 3. 与C关系 | ReleaseData改变resident版本且非same-unsafe-package supersede可触发reason1；ProbeAckData为reason2；trusted A写为reason3；不是每个C都创建checkpoint |
| 4. buffer深度 | checkpoint engine1个candidate snapshot+单个64bit data寄存器，**不是64B queue**。ReleaseData另有SinkC2 lists/16×64bit beats；候选仍留在原MSHR/Probe入口，非独立preservation FIFO |
| 5. drain eligible | selectable candidate valid、对应MSHR`quiescent=w_rprobeacklast&&w_pprobeacklast&&w_grantlast`且old image safe；Probe候选quiescent常true |
| 6. 谁选择 | probe bit0优先，其后MSHR固定低索引；可runnable优先，否则valid优先。BC/C同set preempt可屏蔽低优先MSHR candidate；不是fair RR |
| 7. drain与bank竞争 | pre-capture先等现有SourceD/SourceC idle、SinkC已入bank queue为空、目标quiescent；之后checkpoint借SourceC bank读端，与SinkC最高优先端竞争 |
| 8. 需要哪些端口 | candidate来自已读resident，不新增tag lookup或replacement；capture自身不写data/dir；读取旧line需data SRAM read。完成更新匹配MSHR的outerPreserved，不在ACK边沿直接重写directory；后续dir publish仍需单端口directory调度 |
| 9. drain/操作完成 | pipeline drain=上述idle条件；checkpoint完成=全Put已发且匹配source2/64B/CachePreserveTxn的无错误AccessAck；二者不能同名 |
| 10. 哪个ACK等drain | checkpoint AccessAck先要capture/read/send；incoming L1 ReleaseAck须新ReleaseData最终bank commit，若旧image checkpoint必要会间接等其完成；无checkpoint的C也可直接写 |
| 11. outer A要等吗 | 正常outer A与pre-capture drain无直接global gate；仅已开始checkpoint packet及当周期更高优先preservation.valid挡SourceA dequeue。SourceA FIFO2可先enqueue |
| 12–15. 锁范围/顺序 | 详outer_a_lock_semantics；多beat锁per-packet共享输出，target-set锁per-set，SourceC预约却跨set全局持续active；normal victim的ReleaseAck→Acquire为独立MSHR顺序 |

`drainForCheckpoint=runnable.orR&&!preservation.lock.valid` 在capture前抑制新C和D schedule，不能描述为“停止所有请求”。普通A schedule可继续，入口directory/queue仍有门控；active之后该drainForCheckpoint为false，其他set D可以继续。target set通过locked(set)及物理写assert保护，直到matching ACK。

idle且unsafe candidate不具备capture条件，不应将其等待全部计为engine pending；candidate-valid/unsafe-watermark wait、runnable drain wait、active engine三类必须分别计数。现存engine counters(2)仅active cycles，未导出到B成功日志。
''')
    save('outer_a_lock_semantics.md','''# Outer A lock的精确定义

**三种锁/预约不同生命周期**：

| 资源 | 建立 | 释放 | 范围 | 阻塞对象 |
|---|---|---|---|---|
| preservation target-set | capture组合边沿或state!=idle | matching terminal ACK完成后state回idle | 当前L2 scheduler中一个set，B只有一个cache bank | 该set新request、MSHR schedule及物理mutation |
| outer A packet `beatsLeft` | idle且下游ready接受首个checkpoint A，剩余7beats | 最后A accepted减到0，**不等ACK** | 此Scheduler outer-A输出per-transaction，全set/source共享 | 唯一SourceA输出head；packet间隙也不能插入另一A |
| SourceC预约 | `preservation.lock.valid`（含capture→waitAck） | terminal ACK后lock清 | 当前scheduler的SourceC模块/借用data读port，跨全部set | 所有SourceC schedule与read ready，包含已不需bank的waitAck |

源码 TLArbiter88–125：`idle=beatsLeft==0`，`latch=idle&&sink.ready`；`beatsLeft=Mux(latch,initBeats,beatsLeft-sink.fire)`；非idle只给已选择state的ready。generated Scheduler中普通A精确ready为：

```text
SourceA.io.a.ready = io_out_a_ready & (idle ? ~preservation_io_a_valid : state_1)
```

该方程**没有preservation.lock、ACK或drainForCheckpoint输入**。L2Preservation在final A fire后state=waitAck/a.valid=0；下个cycle packet idle，normal SourceA可fire，同时target-set仍锁住。CPU contract witness中A fires4,8,…,32，cycle33可normal A，terminalACK可等到70；这是结构反例，非B实际时间。

packet保护多beat消息边界，TileLink A没有可将两个事务data交错后重新恢复的beat索引。不能“每发一beat放锁”或给不同source/set插队；source字段不同也不能豁免multibeat规则。当前B只有一个L2 bank，不能将4个SRAM subbanks误作4条outer-A输出；per-subbank A锁不能绕开单一TL通道。

lock前bank read/delay期间a.valid=0，normal A可通行；已开始packet后后续read/delay/state send ready-low均可空转保持beatsLeft。无stall accepted beat间4cycles，首末span28，内含21个强制read/delay gap slots；bank等待和下游ready-low能再拉长，未保存runtime时长。

**请求类型**：SourceA只构造AcquireBlock/AcquirePerm，无payload、单beat。inner Get hit经SourceD回包，不经过该outer arb；Get miss引起outer Acquire，随后CacheCork转Get；升级可被CacheCork本地Grant，不一定到DRAM。不能将inner Get38,633或Acquire1,914全当被outerA阻塞的请求。

CacheCork还有**第二个**A packet仲裁：SourceC ReleaseData转Put优先，原A次之；那是下游normal eviction/C→A竞争，与本Scheduler checkpoint packet锁不同。memory ready可经Cork返回，因此“outerA ready低”也不能单凭一根线归给preservation。

运行量 `OUTER_A_LOCK_CYCLES/EPISODES/MAX/P90/P99` 均null；没有beatsLeft/fire边沿。normal SourceA本身无multi-data lock，Release走C，checkpoint Put是本Scheduler A arb唯一已知multibeat数据源；不能把它们当六种互斥实测原因计数。target-set active计数器存在于RTL但B未输出，不得读source初始化值替代runtime值。
''')
    phase=e['phase_distributions']['last_C_to_first_bank']
    rows=[]
    for name in ['first_C_to_last_C','last_C_to_first_bank','first_bank_to_last_bank','last_bank_to_ACK']:
        x=e['phase_distributions'][name]
        rows.append(f"| {name} | {x['sum']:,} | {x['n']} | {x['mean']:.3f} | {x['median']} | {x['p90']} | {x['p99']} | {x['max']} |")
    save('67k_latency_decomposition.md',f'''# 67,366 cycles：能恢复的边界与不可伪造的子阶段

| Measured phase | Total cycles | Episodes | Average | Median | p90 | p99 | Max |
|---|---:|---:|---:|---:|---:|---:|---:|
{chr(10).join(rows)}

ROI2,231完整release，normal1,793笔prebank49,248、SVB438笔18,118；lastC→firstbank直方图主模式43和1。分位nearest-rank，区间左闭右开，首末bankspan7表示8次连续accepted写。

用户建议T1–T5不构成当前RTL的统一逐笔串行分解：**SinkC在首C beat就触发req/分配list**，directory及candidate可能在末C前开始；checkpoint不由每个release必然创建。L1末128bit C accepted也不是L2末64bit C accepted，中间还有width/buffer。不能默认entry ready在lastC之后，再将差值硬拆成正时间。

| Proposed phase | 对应实际节点 | Total/count/avg/median/p90/p99/max | Top-N |
|---|---|---|---|
| T1 lastC→entry ready | L1 C endpoint vs SinkC首beat req→directory/resident candidate；可能不同顺序 | 全部null，且非每C checkpoint | unavailable |
| T2 entry→eligible | old resident safe + quiescent +not preempted；非incoming image seq比较 | 全部null | unavailable |
| T3 eligible→selected | combinational固定priority选择；没选中的candidate等待可多cycle；非独立queue grant | 全部null | unavailable |
| T4 selected→bank grant | 包含drained、engine idle/capture、逐beatbs_adr.ready；不是一个grant | 全部null | unavailable |
| T5 grant→first write | checkpoint是bank**read**→old-image Put→ACK；新ReleaseData再经SourceD four-stage→bank**write** | 全部null | unavailable |

真实依赖图（条件分支，不能以未知阶段求总和）：

```mermaid
flowchart LR
 Cfirst[SinkC first beat req/list] --> DIR[directory/resident]
 DIR --> NEED{{old image needs checkpoint?}}
 NEED -->|no| SD[SourceD schedule / release buffer / pipeline]
 NEED -->|yes| SAFE[old-image safe / candidate quiescent / selection]
 SAFE --> DRAIN[SourceD idle + SourceC idle + SinkC queue empty]
 DRAIN --> CP[capture / 8 bank reads / outer Put / terminal ACK]
 CP --> SD
 SD --> WRITE[first actual new-image bank write]
 Clast[L1 last C accepted] --> BUF[widget / TL C buffers / remaining data]
 BUF --> SD
```

因此 **尚不能确定67,366主要属于哪一内部阶段**。已排除的只是末bank→ACK为主因及最终8个bank写之间长气泡；未证明43-cycle模式对应checkpoint。以本cohort观测最短1cycle作非因果参照，额外phase duration为65,135，但不能称RTL必需floor或可恢复收益。

最长20个可观测release代理见episode_analysis，不冒充preservation/outerA锁。SC38记录新ReleaseData写，完全不记录checkpoint旧image bank读；同line相邻事件不能替代missing capture/ACK事务。

补充长尾现象：prebank≥55的24笔，其firstbank cycles全部满足 `cycle mod40=4`，top20也均如此；43-cycle主模式的firstbank分布并不固定该相位。这是从当前尾部选择得到的时间模式，未保存memory/checkpoint ACK对应事件，不能据此断言DRAM/refresh为root cause。它支持后续检查服务/回执时序，不支持把长尾当成bank固定仲裁starvation。
''')
    top=[]
    for rank,t in enumerate(e['top20_release_proxies'],1):
        rr=t['raw_rows']
        top.append(f"| {rank} | {t['start_cycle']} | {t['end_cycle']} | {t['duration']} | {t['release_owner']}/{t['release_image_seq']}/{t['release_generation']} | {hex(t['line_address'])} / {t['l2_set']} | {rr['last_c']} / {rr['bank'][0]} |")
    save('episode_analysis.md',f'''# Episode级top20与证据可用性

**真实preservation/outer-A lock episode列表不可恢复（null，不是0笔）。** 成功B没有保存capture/Put first,last/ACK或beatsLeft状态；因而不能输出20笔“preservation episode”并填假边界。

以下20笔按**已测lastC→firstbank**排序，只是ReleaseData代理，bank均为L2 bank0。release image seq/generation属于incoming新image；preservation保存的是被覆盖resident旧image，不能将二者等同。

| Rank | Last C cycle | First bank write | Duration | Release owner/seq/gen | Line / set | Raw TSV lastC / firstbank row |
|---|---:|---:|---:|---|---|---|
{chr(10).join(top)}

`top20_release_proxies.json`给每笔全部要求字段。preservation txn/source/old-image、drain-ready、arb-selected、bank-grant、outer-A lock duration、blocked请求/unique misses/retries、ROB overlap、eventual critical load都显式null；start/end定义为release prebank，不暗示preservation边界。源SC20/38/21 raw行可逐笔核对，20笔均没有被标成critical。

完整B6,735笔release仍全部source6闭合；本轮复用前轮重建并重新hash/identity校验，没有重写旧报告。prebank phase union=sum=67,366，source6阶段不重叠；多个资源episode可能重叠，不可由此推广。

证据盘点：保存stdout/stderr/TSV中的L2_PRESERVE_PENDING/REQ/ACK、STAGE3_DRAIN记录数都为0；compact捕获丢弃一般diagnostic {m['evidence_availability']['discarded_diagnostic_lines']:,}行，成功ring未dump且file=null。counter存在于RTL不代表成功日志有值；SC32–37是L1/SVB完整性链，SC38是actual bank write，均不是checkpoint状态。无保存FST可读；这不是请求重跑观察的理由。

在optional完整prefix内可恢复的水位仅能比较incoming key。分类见numeric_audit：即使incoming seq已safe，旧resident是否safe、dirty、outerPreserved仍未知；所以该关联不能证明checkpoint或安全水位gate主导。
''')
    save('blocked_request_amplification.md','''# 是否一次锁阻塞多个请求？先定义观察位置

`REQUEST_AMPLIFICATION = blocked unique A requests / preservation episodes` 的运行值、lower/upper非平凡数据界 **UNKNOWN**；preservation分母和请求身份历史都缺失。不能把2,231个release当preservation episode数，不能把valid&&!ready每cycle当新request。

| 观察位置 | 可证明结构界 | 运行估计/置信度 |
|---|---|---|
| 本Scheduler outer arb上的SourceA.io.a head | **单个连续packet lock中unique呈现head∈[0,1]** | 非实测；结构高 |
| SourceA queue中的pending requests | FIFO深2，两个normal outer sources0/1 | 非实测occupancy；结构高 |
| 同一lock内间接受阻的内层A/Get/Acquire、MSHR尚未排队需求 | 可有入口排队与依赖影响；无法从一根outer head推计数 | UNKNOWN |
| 多个checkpoint连续episodes累积造成同一head等待 | 可能，priority不看age；每episode重复阻塞仍是同一个token | 运行episode/身份未知 |

head界证明：SourceA→Queue_34(depth2)→outer arb，generated `do_deq=io_deq_ready&&!empty`。preservation锁持有时normal ready0，所以FIFO head不变、不会drop/retry；一episode中反复valid为**held request**。当head起初为空可入队一个后保持；不存在head换成第二笔而仍称同一个连续锁。队尾请求可被间接延迟，不能据[0,1]否定所有HOL。

`RETRY_AMPLIFICATION = associated blocked/retried events / blocked unique request` 运行值UNKNOWN，cohort可能空，不能给伪精确比值。主BOOM47,162 LSU retries是本地S2重lookup事件，不是TL arb每cycleretry。TL held-ready协议不重发新身份；只有经source/txn/LDQ token连接才允许映射。

本轮没有任何真实episode的blocked unique A/acquire/get/miss/retry/source/bank/set分解。省略数据的下界只可为0；整个B现有已接受A counts不约束因backpressure尚未接受的token。无关set可在inner lookup/SourceD hit进展，direct outer packet锁不是所有内层请求的全局停顿。

允许的逻辑链为：一个held outer miss → queue/MSHR/HOL → 多个dependent demand延迟；但累计request latency可以重叠、放大于时长，**ROI关键时间不能用请求数×锁长相加**。是否存在超67k的indirect critical损失仍NOT_PROVEN。
''')
    save('rob_critical_correlation.md',f'''# ROB / scheduler关联：缺事件的位置明确保持未知

| Metric | Observed value | 仅靠现有边际可给的范围 |
|---|---|---|
| ROB_HEAD_WAIT_DURING_PRESERVATION | null | direct headmiss [0,53,845] |
| ROB_HEAD_WAIT_DURING_OUTER_A_LOCK | null | direct headmiss [0,53,845] |
| ROB_HEAD_WAIT_ON_REQUEST_BLOCKED_BY_OUTER_A | null | 身份与因果更强，不能由raw overlap补齐 |
| outer_a_lock && rob_head_load_wait | null | 若放宽全部direct headpending [0,80,832] |
| preservation_drain_pending && rob_head_load_wait | null | 同上；candidate/active/drain先分定义 |
| outer_a_lock && scheduler_unavailable | null | [0,347,409]，没有lock边际无法收紧 |
| outer_a_lock && l1_retry_active | null | [0,47,162] exact ROI retry-cycle边际；非associated events |

raw overlap仅同时成立；independent overlap需排除更早不可越过依赖，且不能把几个predicate交集相加；headmiss53,845嵌套all headpending80,832。union(A∩H, B∩H)≤|H|，因此direct-head范围去重上限分别53,845/80,832，**不是整个checker/nonhead因果链上界**。

现有SC7可还原scheduler，但不含exact ROB noCommit轨迹：flag10只在snap/cooling有empty语义，flag13未进入change signature。SC38只是writefire，不含head req identity。既无outer-A锁interval，也无法完成cycle intersection；不以release phase代替lock。

本轮额外可算的代理关联：lastC→firstbank区间在完整prefix内与scheduler unavailable交集 **{e['prebank_prefix_scheduler_overlap']} cycles**（仅release代理），不代表outer-A锁×scheduler、亦不说明checkpoint关键作用不存在。前轮首C→ACK交集151，二者定义不同，不拼接到未知suffix。

contentSeq是resident或incoming **写入版本**，不是当前消费者package。必须沿请求source/serial→MSHR/LDQ token→head position或checker requester package建join，不能因同seq或同line就宣称关键因果。
''')
    save('bank_arbitration_analysis.md','''# Bank仲裁：checkpoint不是被normal数据请求低优先饿死

`BankedStore.scala:88–174`固定优先：**SinkC > SourceC(由checkpoint借用) > SinkD > SourceDw > SourceDr**。4个8B单端口subbanks，L2 inner/outer都是8B beat。重叠bank选择高优先保留；不重叠bank可并行。无“全cache一把SRAM锁”。

| 问题 | 源码结论 | 实测状态 |
|---|---|---|
| preservation与谁竞争？ | capture后读挂SourceC优先端，仅SinkC重叠bank可挡它；SourceC本身被mux隔离 | 不知道相关ready-low次数 |
| fixed/fair？ | BankedStore固定priority，无age/RR；candidate选择也固定priority，MSHR schedule另为RR | 无starvation episode |
| normal refill能饿死checkpoint？ | SinkD与SourceD均低优先，**不能通过该bank arb挡它** | 此“normal数据抢占致starvation”子假设否定 |
| 反过来挡normal？ | checkpoint read优先SinkD/SourceD；连续候选还可global drain | 存在结构，duration/critical未知 |
| 共享单点？ | 单engine、单SourceC借口、单outerA输出；4SRAM子bank不等于4个独立L2 scheduler | B1cachebank |
| same-set？ | 目标set至ACK保留；入口高优先选中被锁C时还可能挡低优先A，即使A本身另一set | 无事件join |
| metadata/data并行？ | directory是单独SRAM，read/write互斥（read优先）；data为4subbanks。可有物理并行，但Scheduler要求相关schedule resources同时ready | 不把两者误称单端口 |
| one-cycle port被长占？ | waitAck已无checkpoint读，却SourceC schedule/read仍全局禁止；那是预约范围，不是SRAM在写 | 具体优化审查点，未赋收益 |

**不能从ProbeAckData24×8推bank-stall上界**：SinkC为wormhole流预留bank，`bs_adr.valid`可在C暂时无valid时送noop（noop只关bankEn，bankSel仍可压低优先）。实际阻塞包括valid gap，统计包数不含其时长。drain只看已入bank queue，capture后仍可能有其他set ProbeAck。这也阻止用流量低判定无等待。

SourceC>SinkD与SourceDw>SourceDr有数据/eviction顺序原因；直接调priority或给checkpoint降优先可能破坏forward progress/旧image读取，不能作为低风险默认fix。尚无事实证明67k主要在eligible→bankgrant，所以不把这一步写成已测主因。
''')
    save('hol_blocking_analysis.md','''# HOL与循环依赖审查

## 已否定的长锁链

`C last → full preservation active → outer A packet locked until terminal ACK → all subsequent inner A blocked` 不是实际RTL。candidate可能先于lastC、pre-capture无packet锁、waitAck不再锁A、inner Get hits可走SourceD。不能为这条不存在的跨ACKpacket锁设计“提前释放到C末beat”的patch；C与A是两条不同消息。

## 仍存在的三条具体依赖

```mermaid
flowchart LR
 PA[checkpoint waitAck / target-set lock] -->|global !lock gate| SC[unrelated-set SourceC schedule blocked]
 SC --> REL[dirty victim Release not issued]
 REL --> ORD[MSHR s_release / w_releaseack unsatisfied]
 ORD --> ACQ[that MSHR new Acquire not eligible]
 CP[checkpoint first..last A] --> PK[beatsLeft packet lock]
 PK --> HA[held SourceA head]
 HA --> Q[2-entry queue / resource-ready / later miss waits]
 CD[high-priority C at locked set] --> IN[request mux selects C, locked set kills request]
 IN --> IA[lower-priority inner A not admitted]
```

第一条在`Scheduler.scala:334–336,776–779`与`MSHR.scala:249`有精确条件，**structural path PROVEN**；它是否在B中发生、对哪个miss/head/package关键 **NOT_PROVEN**。这是下一离线资源目标，不继续笼统称outer A packet锁。

第三条源自`request.bits=Mux(sinkC.valid,C,Mux(sinkX.valid,X,clientA))`，然后对选择的set检查locked；clientA.ready还要求!C.valid&&!X.valid。一个不ready的高优先C可以挡无关A，不能因per-set lock就断言没有跨set入口HOL。改为skip locked C涉及incoming multibeat/C优先和deadlock设计，需另审。

## Circular wait检查

| 疑似循环 | 实际破环条件 | 结论 |
|---|---|---|
| pre-capture drain等A，而A等本checkpoint packet解锁 | checkpoint尚未capture/发A；`drainForCheckpoint`无普通A直接gate；unquiescent candidate不runnable不会请求global drain | 未发现此必然闭环 |
| checkpoint等bank、normal bank work又等checkpoint A | checkpoint挂SourceC优先端；只有SinkC更高，可在外部C缺beat/背压时等，但不是normalSourceD/SinkD抢占 | 无封闭自持环证明；外部C/downstream wait可能长 |
| waitAck持有packet锁，ACK所需正常A发不出 | final A已解packet锁，AccessAck由terminal完整Put返回且独立D ready=true | 跨ACK packet环否定 |
| waitAck禁SourceC，SourceC不发就checkpoint ACK不来 | checkpoint完整A已发送、source/txn独立；其ACK不依赖新的无关SourceC req | 未发现必要循环；却可造成victim/A delay |
| 新D multibeat挡旧ReleaseAck credit又不能继续D | SourceD separate ReleaseAck queue+`earlyD.valid=s3_valid_d&&s4_ready`已有防环 | 本轮不撤销该guard |

这不是所有cache/interconnect无deadlock的形式证明，也不是成功退出证明无stall。外部DRAM/Cork、Probe流、水位、peerWait还可引入长等待；现存数据不能封闭全系统依赖图。

锁粒度判断：target-set锁已per-set，不能提前到C末beat/末A或只按source释放；旧image terminalACK是正确性合同。outerA multibeat锁已仅必要packet周期，按source/subbank插队不合法。**全局SourceC预约在waitAck的范围比checkpoint物理读需求更宽**，值得审查按“仍需bank读”条件交还端口同时保留target-set锁，而不是删preservation。
''')
    save('upper_bound.md',f'''# Fixed-trace UB1–UB4及去重：可测、结构有界、未知分开

| Requested bound | Value | 当前可信范围 / 原因 |
|---|---|---|
| UB1 PRESERVATION_PENDING_UB | UNKNOWN | engine.active未导出；安全candidate前等待也未记；仅trivial[0,1,648,923] |
| UB2 OUTER_A_BLOCKING_UB | UNKNOWN | beatsLeft且normalHead.valid、ready provenance未保存；trivial[0,1,648,923] |
| UB3 OUTER_A_CRITICAL_UB | UNKNOWN | direct headmiss交集[0,53,845]；放宽all direct headpending[0,80,832]；非实际交集 |
| UB4 PRESERVATION_CRITICAL_UB | UNKNOWN | 同上，drain/active需分开；无precise interval |
| INDEPENDENT_CACHE_TRANSFER_UB | UNKNOWN | 四类union按cycle去重；direct-head union≤53,845或放宽80,832，**不是**全部非head/checker链上界 |

没有lock/pending边际，Fréchet不能产生比trivial更强的全机制bound。缺数值不能用67,366、347,409或hist tail169k填替；也不能因unknown就选>=100k候选。

## 新闭合的有限服务槽上界：只删packet内强制gap

源码每beat read→delay1→delay2→send，accepted A之间至少3个nonvalid槽，共7×3=21；normalSourceA为单beat无data，只有checkpoint产生本Scheduler multibeat A。较大traffic窗口内memory_writes=1,623同时含checkpoint A和SourceC data C，所以checkpoint firstA数 **≤1,623**。ROI完全在该窗口内；singleton checkpoint engine允许最多1个先前已开始packet跨入窗口。

```text
INTRINSIC_A_GAP_ONLY_UB
    = (1623 + 1 carry-in) × (8−1) × 3
    = {b['cycle_upper_bound']:,} cycles
```

这是由真实FSM和packet-count ceiling推得的**必有服务槽删除上包络**，没有人为penalty；并非实际stall估算。各packet在单一A输出不重叠，ROI clipping只能减小这个slot union；若把全部这些槽都视作可删关键时间也低于50k。排除bank-read等待、send ready-low、pre-capture drain、waitAck、hit/非head/checker的时序反馈；完整outer-A-lock或preservation UB仍未知。

不将1,623−48当checkpoint精确数：SourceC req统计与实际outer C首beatcohort不同，且无数据Release不计memory write。使用所有1,623作为保守上限避免跨边界错减。

**停止项**：只优化intrinsic gap的packet方向属于用户情况D局部上界<50k，终止作为主线；“packet锁跨ACK”结构不存在，该子假设可删除等待为0。不能把局部D结论推广成“所有preservation收益<50k”。SourceC waitAck预约、drain/入口HOL整机制因未测不具备A/B/C资格，本轮选择move下一离线瓶颈。

目标至少146,411，direct head范围或34,104局部slot均单独不足；它们互有重叠，禁止相加凑预算。当前B已含64K，不能再加历史58,940 reference收益。候选收益expected UNKNOWN、保守credit0；0表示不给收益，不表示实际无机会。
''')
    save('candidate_fixes.md','''# 最多4项设计方向与风险：没有达到run准备门槛

| Rank | Mechanism | Critical UB | Conservative gain | Complexity | Risk | Confidence |
|---|---|---|---:|---|---|---|
| 1 | SourceC预约跨checkpoint waitAck → release/acquire HOL | UNKNOWN | 0 | 中 | coherence/borrow-port中高 | 静态路径高，关键预算低 |
| 2 | preservation pre-capture global C/D drain范围 | UNKNOWN | 0 | 中到高 | snapshot hazard/forward progress高 | 条件高，冗余部分未知 |
| 3 | outer A intrinsic multibeat gap | 局部fixed-slot≤34,104；整机制UNKNOWN | 0 | 中（buffer/pipeline） | TL packet/image中高 | 局部上界高，无主线资格 |
| 4 | locked高优先C阻低优先inner A ingress | UNKNOWN | 0 | 中 | C priority/order/deadlock高 | 静态路径高，发生次数低 |

## 1. SourceC waitAck交还端口：优先继续离线审查

- RTL modules：Scheduler、L2Preservation状态/borrow信号，SourceC hazard与MSHR release/acquire。
- changed state/signals（设计，未实现）：以“checkpoint仍可能读bank”的专用phase信号控制borrow，而不是整个lock.valid；waitAck时允许非locked set的SourceC schedule/read。engine直到ACK不接受新snapshot，target-set锁全程保留。
- correctness invariant：旧image完整8beats已accepted；source2/txn/size/terminalACK原样；target set bank/dir不可mutation；无关SourceC使用自己的safe image与source0/1；matching receipt不能race mutation。
- ordering风险：SourceC pipeline可越过preservation ACK但只不同set，需核对directory/nestedWB/SourceD grantsafe/evictsafe及下一capture前重排空；不能仅改一个ready忽略schedule gate。
- TL/protocol：末A已发送不意味terminalACK已到；target锁不可释放。CacheCork C转A有自己的packet仲裁，不能让C打断仍未完全发完的checkpoint packet。
- SVB/preservation：SVB source/ACK身份、下级版本义务保持；正常victim外发安全watermark与ReleaseAck合同不变。
- area：专用phase predicate/少量控制为目标，无容量/way/MSHR/端口增加；timing：多一层schedule/borrow选择，需检查ready路径与组合环，尚未编译/生成。
- expected gain/whole UB UNKNOWN、conservative0；静态链可信，运行主因未证。

## 2. 更窄的pre-capture drain

将global idle条件收敛为目标set/way相关在途read/write排空，同时允许无关SourceD schedule。需全4stage、skid、SinkC队列及borrow读pipeline身份，不能只看MSHR set；Directory与bank跨phase hazard、write-after-read/old-image稳定和engine starvation都需证明。新增比较/scoreboard、timing/ordering风险较高，无已测预算。不是当前可低风险落地patch。

## 3. 连续发送checkpoint，保留整个TL packet锁

L2Preservation先流水读入64B bounded buffer再burst，或合法深度的小skid预取；不在beat间插入其他source。buffer512bit+控制、不新增SRAM port目标，可能增bank竞争/首beat等待；保留immutable image、target-set至terminalACK。intrinsic gap删除局部上界34,104，不足50k，不准备主线；bank/ready延迟不能由该上界或设计免费解决。

## 4. locked C入口HOL bypass

Scheduler入口优先Mux可以评估跳过暂不可服务高优先C，让其他set A前进。需证明C packet held稳定、同set order、C请求与其后data buffer/list、一致性break-deadlock优先关系；incoming source不能在未fire前推进。无新增大queue为目标，但组合仲裁和循环风险不低。统计应测“C selected but locked AND otherwise admissible A”，不是所有C.valid。

不提出“packet锁到ACK前释放”“per-source允许A beat交错”“用4子bank拆4个outerA”方案：前者已如此，后两者不符合当前物理/协议。所有方向均未改硬件，NONE_JUSTIFIED。
''')
    save('next_run_plan.md','''# 下一步：MOVE_TO_NEXT_OFFLINE_BOTTLENECK

`COMMANDS_FOR_USER=[]`；无run launcher或硬件patch。尚未同时满足>=100k independent critical UB、清楚运行root cause、低中复杂度fix，不准备Opt5 run，不跑A′/新B/diagnostic-only。

**本轮终止的是“outer A packet锁跨整个drain/ACK”和“仅压缩intrinsic gaps即可做Opt5”的方向。** 保留真实但未计量的间接链，下一离线目标为 **其他cache-transfer仲裁：SourceC借口在checkpoint waitAck期间的全局预约 → 无关dirty victim Release → 同MSHR Acquire**，随后L2入口C优先HOL/SourceD服务。再不足才查BOOM/checker资源backpressure，frontend最后。

下一离线审查应证明SourceC在waitAck使用borrow端的安全边界：检查所有pipeline/hazard与下一capture重drain，建立小范围状态/资源依赖而不生成硬件；只有出现可信预算才将功能改动与诊断同版本准备一次正式run。当前成功日志不足以恢复真实episode，不循环要求同一missing trace或追加观察run。

## 最小bounded instrumentation设计（未实现/未运行）

以本L2 scheduler 200MHz域计数，一次ROI完整边界snapshot；candidate-wait、drainRequested、engineActive/targetSetLock、outerPacketLock分开。packet episode以首A accepted建立序号，末A accepted结束；engine episode以capture/terminalACK结束，分别关联CachePreserveTxn，不能将两者duration混用。

固定资源建议：32或64个64bit counter，32bin hist，top20最长episode（约20×若干64bit字段，payload不记录），2个normal-source request serial/待发记录，1个checkpoint active记录；overflow/censor/unknown身份明确计数，不做全局cycle dump。

必须导出：

- UB1 active/pending、unsafe-watermark wait、runnable drain的duration及各等待SourceD/C/SinkC/quiescent原因mask。
- UB2 `packetLocked && normalHeadValid && downstreamReady`及原始`packetLocked&&normalHeadValid`，与外部ready-low分别计，slot union不重复。
- packet start/end/max/hist；held invalid gaps按read-wait、fixed delay1/2、send ready-low、最后beat等类别分开；frame内distinct head serial和FIFO count/highwater，不能每valid-cycle算unique。
- SourceC路径专用：`waitAck && sourceC candidate(other set) && otherwise_resources_ready`、global lock blocked cycles、victimMSHR `!s_release`或`!w_releaseack`阻Acquire的duration、eventual source/txn。
- 内层入口：selected C locked且另一个A原本可admit的机会；bank各client valid&&!ready与更高priority交集，包含noop reservation。
- UB3/UB4及去重：ROB实际head token/等待谓词，与packet/drain/SourceC限制exact联合计数和union。checker请求需source→requester package→finish/result acceptance→BOOM ownership链；不能用CacheImage seq当请求者。
- top20包含capture/drain-ready/selected/first&lastA/terminalACK/firstbank、set/oldImage key/source/txn、blocked request serial集的计数、原因、head/scheduler/retry交集。所有字段区分有无观察与ROI boundary censor，跨reset拒绝join。

held request与LSU retry是不同概念；若要RETRY_AMPLIFICATION需token关联并输出分母0/未知。对head overlaps输出raw、nested union、经过依赖确认的独立可删候选，不能只靠overlap宣称speedup。

这些仅是与未来已成立功能候选同版的诊断规格；当前不为收counter启动硬件，不扩cache/MSHR、不改frontend、不做SVB32/promotion。
''')
