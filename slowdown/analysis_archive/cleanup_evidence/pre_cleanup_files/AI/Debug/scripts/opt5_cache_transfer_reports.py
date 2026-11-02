"""Report rendering for the completed-B offline cache-transfer audit."""
import json

REQUIRED = ['README.md','cache_transfer_path.md','l1_l2_request_path.md',
    'l1_l2_response_path.md','refill_serialization.md','writeback_interference.md',
    'retry_resource_mapping.md','critical_latency_decomposition.md','candidate_upper_bounds.md',
    'opt5_candidate_ranking.md','frontend_last_resort_assessment.md','next_run_plan.md','validation_result.json']


def write_reports(out,m):
    def save(name,body):
        (out/name).write_text(body.strip()+'\n')
    release=m['release']; dist=release['distributions']['all']; c=m['counts']; l2=m['l2']
    def latency_table():
        header='| Phase | N | Sum (cycles) | Average | Median | p90 | p99 | Max |\n|---|---:|---:|---:|---:|---:|---:|---:|'
        return header+'\n'+'\n'.join(f"| {name} | {d['n']} | {d['sum']} | {d['mean']:.3f} | {d['median']} | {d['p90']} | {d['p99']} | {d['max']} |" for name,d in dist.items())
    save('README.md',f'''# Opt5 cache-transfer attribution — 尚未证明足够大的可恢复关键路径

本轮新增的直接证据是：完整恢复 B 的 **{release['full_run_transactions']:,}** 笔 BOOM voluntary ReleaseData，逐笔连接 L1 C 首/末 beat → L2 实际 bank 写入 → L1 ReleaseAck；全部 8/8 word 覆盖、身份与生命周期检查通过。软件 ROI 内完整事务 **{release['roi_contained_transactions']:,}** 笔，首 C → ACK 的阶段区间并集 **{release['roi_phase_union_cycles']:,} cycles**。

这段延迟主要位于 **最后 C beat → 首个 L2 bank 写入**。每笔最终 8 次 bank 写入连续，末次写入 → ACK 中位数 2 cycles。不能把它归因成慢 ACK 回程或 bank 写入过程中大量气泡，也不能把整个阶段视作可恢复收益。

最值得继续离线审查的具体结构是 **L2 preservation 的全局 drain、单引擎逐 beat 读/发，以及外层 A multibeat 锁定**。它可阻塞同 set 的 ReleaseData/其他更新，并可影响其他 set 的调度/外层 miss。现存日志没有 checkpoint 状态时长或关键请求关联，长延迟 52-cycle 模式由该机制引起仍为 **UNPROVEN**。

`CACHE_TRANSFER_MAJOR_BOTTLENECK=NOT_PROVEN`；`MAIN_OPT5_CANDIDATE=NONE_JUSTIFIED`；`1P5_FEASIBILITY=SUB1P5_NOT_SUPPORTED`；`NEXT_ACTION=MORE_OFFLINE_ATTRIBUTION`；checker frontend 保持 `LAST_RESORT`。

目标 B ROI 1,648,923 → <1,502,513，用户 gap 146,410；严格整数最少需节省 **146,411**。80,832 只约束既有轨迹中的直接 head-load 等待，**不是全部 cache transfer、checker completion 或非head依赖的全局上界**。

## 阅读入口

- `cache_transfer_path.md`：实际模块/通道/宽度/时钟/协议链。
- request、response、refill、writeback 四份报告：资源与序列化。
- `retry_resource_mapping.md`、`critical_latency_decomposition.md`：原因映射、分布、top episodes 与未知项。
- `candidate_upper_bounds.md`、`opt5_candidate_ranking.md`：有范围的上界、5 个设计审查方向与成本。
- `frontend_last_resort_assessment.md`、`next_run_plan.md`：资源 backpressure 边界、继续离线计划、未来功能实验的诊断设计。
- `numeric_audit.json`、`release_transactions.json/.csv`、`source_evidence.json`、`provenance.json`、`validation_result.json`：机器可复核证据。

所有时间统一为 BOOM/L2 200MHz cycle；simulator time = cycle +103；checker 100MHz，不把其本地周期直接相加。软件 ROI `{m['software_roi']}`，L1 traffic `{m['traffic_window']}`，L2 counter 窗口 1,660,084 cycles 比 L1 多一个采样边沿。可证明完整 optional prefix `{m['optional_complete_prefix']}`；未知后缀 {m['optional_unknown_suffix_cycles']:,} cycles。以上边界列表均按左闭右开 `[start,stop)` 解释。mandatory release 链完整，可覆盖全运行；optional prefix 不外推。

B correctness/capture 恢复结论保持闭合；原 host FAIL、seal、raw logs、claims 全部保留。旧 A/new B 仅 `REFERENCE_COMPARISON / STRICT_PAIRING_PENDING`；未跑 A′。本轮未修改硬件，未生成 RTL、build 或仿真，未准备新运行命令，未清理文件。

复现（仅 CPU，输出目录必须不存在）：

```bash
python3 -I -B AI/Debug/scripts/analyze_opt5_cache_transfer.py --out AI/TMP/opt5_cache_transfer_attribution_NEW_UNIQUE_TIMESTAMP
python3 -I -B AI/Debug/scripts/test_opt5_cache_transfer.py
```
''')
    save('cache_transfer_path.md','''# 实际 cache transfer path

来源：`source_evidence.json` 保存源码逐行摘录、SHA256 和本次读取的已生成模型连接。源码根为 `chipyard/generators/`。当前未重新 elaboration；新增未封存文件摘录是静态机制证据，已生成的连接/配置是 completed B 结构证据，不把静态推论伪称新运行验证。

```mermaid
flowchart LR
  LDQ[BOOM LDQ / retry] --> L1[L1 S0-S2 meta/data lookup]
  L1 --> M[6 MSHRs + RPQ]
  M -->|Acquire A| W[128↔64 bit TLWidthWidget_13]
  W --> X[tile TLXbar_10 / TLBuffer_19 / sbus]
  X --> L2[L2 TLBuffer_16 / Scheduler / directory]
  L2 --> SD[SourceD / bank read / D response]
  SD -->|GrantData D| W
  W --> LB[6-line LineBuffer]
  LB -->|ordinary load response| LDQ
  LB -->|full Grant captured| E[GrantAck E responsibility]
  LB --> INST[owner reservation / row install / metadata]
  INST --> L1
  L1 --> WB[WB snapshot / single source 6]
  WB -->|ReleaseData C| W
  W --> RC[L2 SinkC / release list / SourceD bank write]
  RC -->|ReleaseAck D after commit| W
  L2 --> OUT[SourceA / SourceC / preservation]
  OUT --> MEM[outer buffers / CacheCork / mbus / TLToAXI4 / SimDRAM]
  MEM -->|outer D / SinkD bank install| L2
```

| Stage | 实际模块与关键握手 | Blocking / ordering |
|---|---|---|
| L1 detect/admit | `BoomNonBlockingDCache` S2 → `mshrs.io.req(w)` | `sdq_rdy`、same-set/tag、primary/secondary ready；not-ready 不等于 full |
| L1 outgoing | `BoomMSHR.io.mem_acquire` → lowest-index A arbiter → `tl_out.a` | A 单输出但 Acquire 不带多 beat 数据；MSHR 可多个 outstanding |
| coherence | L2 SourceB → L1 prober B；WB/prober C arbiter | WB C 优先于 prober reply，packet 锁定；不能丢 probe 或反转安全顺序 |
| interconnect | generated `BoomTile.widget`=`TLWidthWidget_13`；其 `auto_in_a_valid` 接 `_dcache_auto_out_a_valid` | L1 128-bit/4 rows，L2 inner/outer 64-bit/8 beats；widget_1 是另一连接，不混用 |
| L2 ingress | `Scheduler` SinkA/SinkC，directory，requests ListBuffer，4 MSHR | C > control > A；仅 2 个普通 ABC MSHR，另有 BC/C 各1；same-set queue/preemption |
| L2 hit | SourceD 四级流水 → BankedStore → inner D | 非全局单事务；beat-generation/端口/ready 可序列化 |
| L2 miss | SourceA outer A → memory → SinkD → BankedStore | SourceC victim read 优先 SinkD；grantsafe/evictsafe 防覆盖；outer D 有2-entry buffer |
| L1 return | D按source路由；`mshr.io.mem_grant` → LB | source6为WB ACK；source0..5为MSHR；LB先收数据，与实际 array install 解耦 |
| wakeup | `s_drain_rpq_loads` + LB read → `io.resp` | 普通读load先返回；LR/AMO走 replay；并非必须等最终 row/metadata |
| install/finish | install owner + row fetch/refill write + meta publish；独立`mem_finish` E | full Grant capture即持有E责任，可在RPQ/victim/install前发；MSHR终结还需E已发，不把E强制排到metadata之后 |
| dirty writeback | WB fill buffer → `io.resp` → C send → D ACK | MSHR的snapshot完成与release source释放是两个不同事件 |
| L2 preservation | `L2Preservation` non-destructive old-image checkpoint | 安全 watermark、整行旧版本、terminal AccessAck 匹配后才能解锁；不是普通替换 miss |

配置：B L1D64KiB/2way/512sets/64B，6 MSHR，6个full-line LB slots；L2一bank、1MiB/1024sets/16way、4个8B单端口SRAM subbanks；memCycles12；外层normal source预算2，checkpoint独立source2。BOOM/L2/system/memory 200MHz，checker100MHz且跨async coupling。

队列（配置容量，**不是测得占用**）：L2 inner interior `fullC`=C深2，其余无；inner exterior `flowAD`=A/D各深1 flow；outer interior `full`=各通道深2，outer exterior `none`。默认深2见 diplomacy `BufferParams.default`。putLists12/putBeats16，relLists2/relBeats16，secondary8；release ACK queue2；SourceD bank-read skid3；SinkC ProbeAck bank queue1 pipe。保存日志没有这些队列的逐cycle occupancy/ready-low。

64-bit TileLink line transfer至少8个accepted data beats，L1侧4个128-bit rows；这种物理串行本身不证明 stall。利用率低仍可能存在同set锁、priority仲裁、valid gap期间packet锁以及ordered credit/hazard，必须看关键请求是否恰好等待。
''')
    save('l1_l2_request_path.md','''# L1 → L2 request transport 与 capacity 分开

源码：`boom/.../lsu/mshrs.scala:404–446,909–915,1128–1143`，`dcache.scala:772–809,848–900`；L2 `Scheduler.scala:157–219,385–405,515–552`、`SinkA.scala`。行号对应本次 `source_evidence.json`。

| 问题 | 已证实结构 | 本次可测范围 |
|---|---|---|
| 连续发出 miss？ | 单 A 输出；6个MSHR fixed lowest-index仲裁。Acquire单beat，ready持续可连续发；无全局“必须等前一miss完成”限制 | 未保存 A valid/ready/age；不能声称实际持续发或经常堵塞 |
| queue 经常 full？ | SinkA request、Put list、directory/same-set/normalMSHR admission可能反压；Acquire/Get本身无Put payload | 无 occupancy 或 first-A wait，full频率未知 |
| MSHR 不满却不能发？ | 可以：同set/tag不匹配、secondary state/RPQ、SDQ、A仲裁、下游ready、E finish均独立于全局full | B full0、max occupancy2/6不排除此链；39,072 not-ready谓词/20,433 valid rejects也不直接测TL ready |
| critical/old 优先？ | LDQ wakeup已有AgePriorityEncoder；MSHR A fixed index，不识别ROB criticality；L2 schedule RR，入口C高于A | 缺少oldest-wait/critical-A histories，不证明饥饿或显著收益 |
| retry 重仲裁？ | 被nack的LSU token retained且executed清零，经LDQ age wakeup重新做S0/S2 lookup；若已merge到RPQ，不需要每次重发新A | repeated S2不是每次一个下级miss；不能用47,162估A包数 |
| merge/HOL？ | same-set不同tag可能blocked；同line secondary须tag/state/RPQ等允许，drainAdmissionClosed关新入队；741 merges | per-set/tag blocked时长、critical token对应关系未知 |
| source/sink？ | L1 source0..5 MSHR，source6WB；Grant sink/E保持。L2普通MSHR2+BC/C2，outer source2 checkpoint专用 | 没有source exhaustion/sink-credit等待计数；full0不是无source ordering |

L2源端 schedule 必须相关 A/B/C/D/E/dir resource ready；C > control > A 的入口优先、same-set MSHR阻塞及目录ready可产生 HOL。lineage-unaware不安全请求可停放在source-indexed clientWait，暂时不占MSHR/set/bank/D流水，等watermark及set可用再replay；因此L2 MSHR full0不能排除较长的checker请求等待。

外层A是 `preservation.io.a` 优先、`sourceA.io.a` 次之的 TLArbiter。multibeat使用beatsLeft锁定packet，checkpoint在自身read/delay阶段没有valid仍保持已开始packet仲裁归属；这可在“平均利用率不高”时阻挡普通miss。源码证明存在该结构；本B缺少临界A等待与checkpoint状态，实际次数/时间/独立关键预算未知。

当前无法分解 `detect→L2issue`：native detect→alloc包含本地admission，alloc→physicalrefill还包含整个下游及安装；不能把两者误标成 request transport latency。
''')
    save('l1_l2_response_path.md','''# L2 → L1 response：接收、安装、load完成是不同阶段

L2 `SourceD.scala` 是四级多事务流水，stage1逐beat生成当前事务；bank read有3-entry skid与2-cycle SRAM读时序；stage2可能等Put/Release buffer，stage3发inner D，stage4执行bank update。stage4 ready会反压前级，避免旧ReleaseAck credit与后续多beat D形成死锁。ACK queue深2、ACK优先于early D，且ReleaseAck只能在最后实际bank commit之后形成。

L2 outer D经 `SinkD` 2-entry queue；首beat受grantsafe以及bank ready约束。BankedStore优先级 SinkC > SourceC/borrowed checkpoint > SinkD > SourceDw > SourceDr；上游子bank选择即使未全部获准也会压住重叠低优先请求。无利用率或blocked-cycle数据，不能根据159个L2 misses推断服务等待必小。

L1 `dcache.scala:1423–1432`：D ReleaseAck source6独立接收，其余按source送MSHR。`mshrs.scala:331–334,404–490,876–890`：incoming grant row写LineBuffer，`lb_write.ready=true`，写优先于共享LB读；数据接收不直接等L1 data-array write port。最后GrantData之后记录GrantAck，再进入RPQ普通读load drain；`io.mem_finish.valid=grantack.valid`独立于这些后续state，因此E可以提前发，MSHR退出再确认责任完成。普通读已能从LB `io.resp` 返回；LR/AMO走replay；然后才可能victim处理和physical install。

不能将 `L2 response arrival → final physical refill → dependent wakeup` 当成普遍串行链；对普通读，wakeup可在physical refill之前。`alloc→physicalfinalrefill`不是纯传输延迟，三个native latency cohort也不相同，禁止用均值或hist相减推wakeup gap。

| 请求的分布 | Average / median / p90 / p99 / max | Critical / noncritical |
|---|---|---|
| L2 D available→L1 D fire | 未保存valid/ready histories | unknown |
| L1 first/last D→LB complete | 未保存逐miss D beat timestamps | unknown |
| LB complete→final array/meta install | 无按MSHR/txn的事件历史 | unknown |
| physical refill→dependent wakeup | 普通读不保证该顺序；无paired timestamps | unknown |
| actual bank commit→ReleaseAck | 有mandatory SC38/21，见latency报告 | 仅release cohort，不能替代load response |

没有证据支持“response已到但在L1入口长期等metadata port”，也没有证据证明该时间为0。现有LB decoupling削弱“加个refill buffer即可大幅提速”的泛化方案；加D queue前须先证明当前入口反压及其关键交集。
''')
    save('refill_serialization.md','''# L1 refill serialization：共享row资源，不是全局whole-line锁

`mshrs.scala:849–915`：nLBEntries=nMSHRs=6，`Mem(nLBEntries*cacheDataBeats, UInt(encRowBits.W))`，即6×4×128bit的full-line容量。**一个共享LB访问调度**：incoming D写优先，只有otherwise执行固定索引read arb；ordinary waiting-load response和install row fetch共用读端。持续D写可以推迟LB读，即使array安装空闲；没有相关blocked-cycle counter。

`mshrs.scala:536–575`：每个MSHR可持有install状态，按row执行 `io.lb_read` → register `rowValid` → `io.refill.fire`清rowValid，再读下一row。现有单row暂存形成每row读/交付的交替阶段；6个MSHR能同时待refill，但LB/refill/meta/install arb逐次串行。没有一个锁令整条cache line从头到尾排他占全局所有hit端口。

`dcache.scala:1434–1540`：install owner需pending WB same-set、S3/completion及pre-freeze访问drain；refill写必须匹配reserved MSHR/txn/epoch/tag/image；pipeline effect的dataWriteArb input0优先于refill input1；final metadata publish另等local drain。set/slot reservation可能造成同set长尾，不能移除owner验证以换速度。

当前使用 **BoomDuplicatedDataArray**（源码439–461/798，已生成instance与bank-nack常0核对），每lane/way独立逻辑read与write，`io.nacks=false`。因此不能声称refill写必然互斥所有普通read hit；同地址/owner冲突仍由cache逻辑约束。metadata lookup与publication另有arb/ready，不等同独立数据读端；共享meta read优先 replay/probe/WB/MSHR/LSU/prefetch，data read优先replay/WB/LSU。

| 目标量 | B观测 | 能否作为收益 |
|---|---:|---|
| physical final-row completions | 1,883 | event count，非stall cycles |
| all MSHRbusy | 194,905 | 同时包含request/service/RPQ/victim/install/E，非REFILL_BUSY |
| `REFILL_BUSY_CYCLES` | null | 不把MSHRbusy改名 |
| `REFILL_BLOCKING_L1_ACCESS_CYCLES` | null | 不能用row数×固定penalty估计 |
| `ROB_HEAD_WAITING_DURING_REFILL_CYCLES` | null | direct head-miss53,845只是更宽的已测上包络 |
| headmiss AND MSHRbusy | 53,795 | 证明busy同时存在，不定位refill阶段 |

可审查的小改动：一个额外row holding register、LB read/response skid、在不改SRAM端口的前提下允许fetch下一row与交付当前row重叠；或按age的共享读仲裁。需证明读写hazard、held valid、flush/RPQ terminal、install owner与generation不变。普通load已有LB bypass，不能重复将其列为新收益。是否影响SRAM timing取决于实现，不宣称可免费双端口。active prefetch/reacquire路径未完全量化，故不发布 `4*(allocations+upgrades+6)` 类未经闭合的service-slot上界。

结论：结构性potential serialization已确认；造成多少nack/ROB/checker critical stall尚未证明，独立>=100k预算未知。本轮不扩大MSHR、不改容量或端口。
''')
    save('writeback_interference.md',f'''# Writeback / victim / checkpoint interference

L1 `BoomWritebackUnit`（dcache26–297）只有一份4×128bit victim buffer，voluntary source6由`ackPending`保护，直到完整C发出并收到匹配D ACK才可复用；等待ACK时probe可复用数据buffer。WB请求仲裁优先probe、MSHR、SVB capture、cross-package fallback；C arb中WB先于prober，多beat锁定。

**关键区别**：WB `s_fill_buffer` 的最后row捕获时即 `io.resp := reqIsMshr`（245）；MSHR `s_wb_resp`通常等victim snapshot完成，**不是等ReleaseAck**。但WB source继续占用、pending same-set install drain、后续victim admission可能等ACK，因此ACK延迟仍可能间接反馈。SC20首beat在row采集之后；本次恢复不覆盖request→source allocation→snapshot→首C，不能把它称总source占用上界。

L2 `SinkC`将ReleaseData存入2lists/16beats，经Scheduler/SourceD实际写bank；ReleaseAck仅在最后bank commit后排入2-entry ACK queue。ProbeAckData另有bank queue1。L2 preservation保存**将被覆盖的旧脏image**，不是L2 victim替换；可使普通ReleaseData命中处理先等旧版本checkpoint。

完整mandatory链共{release['full_run_transactions']:,}笔、53,880个BOOM实际bank word写；另有source20/28/24的SC38，明确排除。没有source重叠、未匹配ACK、丢word、重复word、版本错配或末尾outstanding。ROI cohort共{release['roi_contained_transactions']:,}，normal1,793/SVB438，无boundary-crossing事务；量化如下：

{latency_table()}

分位数为nearest-rank，sum为事务phase duration之和；单source不重叠，因此首C→ACK sum等于ROI phase区间并集。区间 `[first_C, ACK)`不含ACK边沿；这不是sampled sourceBusy register计数。8次bank写全部连续，最大interbeat gap={release['largest_bank_interbeat_gap']}；bankspan=7是首末边沿差，不能误报只有7个写beat。

**延迟定位**：lastC→ACK合计87,529，其中lastC→firstbank 67,366、连续bankspan15,617、末bank→ACK4,546；三段可加且同cohort。52-cycle lastC→ACK模式1,405笔、10-cycle模式690笔，最大85。大头在bank写启动之前，无法进一步区分directory/MSHR排队、checkpoint、安全watermark、SourceD admission/port arbitration。与checkpoint对应关系是待证假设。

L2 traffic-window汇总：actual misses159、dirty replacement48、outer reads159、outer writes1,623；写流量远多于dirty replacement。SourceC req计数48与outerC first可能存在边界cohort差，`1623−48≈1575`只能作同窗aggregate residual、与checkpoint Put路径相容，不能声称精确匹配1,575笔checkpoint或把1,575×任意latency当ROI收益。A Gets38,633、AcquireBlock1,914；无per-source Get拆分，不把所有Get都归checker。

checkpoint源码链（Scheduler250–338,770–785 / L2Preservation48–157）：runnable safe candidate → drain停新C/D schedule → 等SourceD idle/SourceC idle/SinkC bank空与target quiescent → capture锁target set → 单引擎每beat read/delay1/delay2/send → 完整outer Put → 匹配terminal AccessAck解锁。无stall时accepted A每4cycles一次，首末8beat间28cycles；这期间outer A packet保持仲裁锁。不能将该结构的21个相对理想burst间隙乘事务数当关键收益。

**锁范围**：capture前drain对新C/D schedule全局起作用；capture后locked只挡目标set，其他set的D在stage3Allowed可继续，但SourceC调度/借用bank读在checkpoint锁期间仍受限制，outerA已有packet锁时普通miss A要等。不能把整个waitAck阶段描述成全cache完全停止。

可审查设计：先流水读入一个512bit checkpoint buffer，再连续burst outerA；保留target set锁、image身份、水位与terminal ACK，单一source不变。不增加cache容量或SRAM端口；增加line buffer/control，可能改变bank读节奏和仲裁；理论可缩短部分outerA valid gaps，实际critical gain未知。长等待如果来自watermark或memory ACK，该设计不解决它。尚不具备准备正式Opt5 run的收益证据。
''')
    save('retry_resource_mapping.md','''# Retry cause → 实际 transfer/resource 映射

原始B exact software ROI causal counters；源码 `dcache.scala:1268–1305`、`mshrs.scala:967–983,1074–1093,1138–1143`、LSU nack/wakeup逻辑。原因是谓词计数，可能重叠；不强行partition47,163 total，也不把event当duration。

| Retry cause | Events/predicate | Critical requests | ROB-head overlap | 实际 resource / 限制 |
|---|---:|---|---|---|
| MSHR request not ready | 39,072 | null | null | S2 valid miss & !mshrs.req.ready；SDQ、same-set/tag、secondary state/RPQ、primary readiness；不是TL ready直接采样 |
| victim transient hit | 8,087 | null | null | S2 hit & secondary_miss；MSHR同set transient/eviction状态，不等于所有正在refill |
| same-set WB | 2,354 | null | null | valid nonhit & s2_wb_idx_matches；WB当前/待ACK同set冲突，有具体writeback关联，但不分row capture与ACK等待 |
| probe / hit path | 25 | null | null | RegNext(s1_nack)，prober/meta相关路径，非泛称response queue full |
| data bank conflict | 0 | 0 | 0 | active DuplicatedDataArray nack constant0；不排除meta/owner/effect conflict |
| refill active本身 | 未独立导出 | null | null | 真实可能阻LB读/安装/同set，不是已定义nack cause |
| TL A/D ready low | 未导出 | null | null | 需按MSHRsource/txn与LSU token关联，不能拿not-ready谓词替代 |
| owner/clear/effect conflict | load分原因未单列 | null | null | s2_owner_block、clear freeze/slot、S3/completion等存在，不能凭总数差值算独立原因 |
| RPQ replay issue | 229 | null | null | 所有229在MSHRbusy，full0；已入RPQ终结/owner检查，非229新miss或229个可删周期 |

结构性放大链 **PROVEN**：stable retained LDQ token → repeated S0/S2 lookup → nack → executed=false → AgePriorityEncoder重试。upstream trigger分支 **PROVEN存在**（not-ready、victim、WB等），但各分支具体被什么transfer phase长期压住、同一critical token的nack次数和连续时长 **UNPROVEN**。后续ROB等待与下游checker/package关键链无法从汇总counter完成join。

当前retries47,162、nacks47,163；MSHR rejects20,433属于valid req cohort，不能与39,072谓词等同。miss lookup attempts40,033也不等于A包数。direct headmiss53,845与headpending80,832嵌套，不能把nack或WB exposure再加到它们上面。

旧A→B reference：miss−648、retry−64,386、headmisswait−85,849，说明少量miss变化与大幅retry/wait变化相关；没有严格pair、逐miss服务阶段或critical token trace，不能选择其中一条放大链作为唯一实测原因。A′仍不运行。
''')
    hist_rows=[]
    tail_rows=[]
    for name,h in m['native_histograms'].items():
        def bounds(key):
            a,b=h[key]; return f'[{a},{b}]'
        hist_rows.append(f"| {name} | {h['n']} | {h['sum']} | {h['mean']:.3f} | {bounds('median_bounds')} | {bounds('p90_bounds')} | {bounds('p99_bounds')} | {bounds('max_bounds')} |")
        tail=h['at_least_1024']; lo,hi=tail['elapsed_duration_sum_bounds']; flo,fhi=tail['fraction_of_latency_sum_bounds']
        tail_rows.append(f"| {name} | {tail['samples']} / {h['n']} | [{lo:,}, {hi:,}] | [{100*flo:.2f}%, {100*fhi:.2f}%] |")
    top=[]
    for i,t in enumerate(release['top_episodes'],1):
        top.append(f"| {i} | {t['owner']} / {t['package_seq']} / {hex(t['line_address'])} / {t['generation']} | {t['first_c']} / {t['last_c']} | {t['first_bank']}…{t['last_bank']} | {t['ack']} | {t['ack']-t['last_c']} | {t['raw_rows']['first_c']} / {t['raw_rows']['bank'][0]} / {t['raw_rows']['ack']} |")
    save('critical_latency_decomposition.md',f'''# Latency decomposition 与长尾证据

两类cohort严格分开：native latency是completion-in-ROI，允许start在ROI前、unfinished censored；mandatory release表仅全程位于ROI内的事务。不能跨cohort相减，也不能把所有load都当head-critical。

## Native miss/load latency：只有三个总阶段

| Observed phase | N | Sum | Average | Median interval | p90 interval | p99 interval | Max interval |
|---|---:|---:|---:|---|---|---|---|
{chr(10).join(hist_rows)}

native bin0=0，binN=[2^(N−1),2^N−1]，最后bin饱和。区间是quantile所在bin，**不是精确分位数**。长尾最高非空bin14=[8192,16383]。detect→data并不保证晚于physical install；alloc→final refill包括request/下游/RPQ/victim/install，不能标成DRAM latency。detect→alloc长尾可能由本地ownership/same-set/admission引起，没有资源归因。

用hist各bin真实范围和**精确cohort sum**可以收紧>=1024cycle长尾的累计duration范围：令tail/non-tail各自bin下/上界为L/U，则tail sum属于 `[max(L_tail,total−U_other), min(U_tail,total−L_other)]`，无需任意per-miss penalty。

| Phase | >=1024cycle samples | Tail elapsed-duration sum bounds | Fraction of phase sum |
|---|---:|---|---|
{chr(10).join(tail_rows)}

因此detect→data只有22/1052个长尾样本，却至少占该cohort累计延迟约80%。这证明少量请求可主导**累计请求延迟**；没有这些请求的地址/phase/head身份，不能声称169k是ROI critical cycles、refill损失或可恢复收益。duration可重叠且可从ROI之前开始；top critical episodes仍unknown。

## 请求要求的七段及critical subset

| 分解项 | Avg / median / p90 / p99 / max | ROB-head critical | Non-critical | 缺失证据 |
|---|---|---|---|---|
| L1 detect→L2 issue | null | null | null | req token→MSHR source→A fire |
| L2 queue | null | null | null | inner A first→directory/schedule时间 |
| L2 lookup/service | null | null | null | lookup result→SourceD准入 |
| response wait | null | null | null | D valid/ready、credit、port |
| transfer | null | null | null | 同一miss各D beat accepted timestamp |
| L1 refill | null | null | null | lastD/LB→owner/install rows/meta |
| wakeup | null | null | null | dependent token response/ROB matching |

`T_total`七项不能数值闭合；unknown保持null，没有用均值相减补造。native仅说明尾部可很长，不能列出不存在的top miss/ROB episode。已知251个completed misses ever-head、head-cycle aggregate53,845，不含每episode边界或阶段。

## 新恢复的release子链（不是load miss分解的替代）

{latency_table()}

normal/SVB各自分布见numeric_audit.json；每个原始事件行、8个bank fingerprints/word offset与完整时间戳见release_transactions.json。下面是 **lastC→ACK最慢的release**；没有证据称它们为ROB-critical episodes。

| Rank | Owner / pkg / line / generation | firstC / lastC | first…last bank | ACK | lastC→ACK | TSV row firstC / firstbank / ACK |
|---|---|---|---|---:|---:|---|
{chr(10).join(top)}

optional prefix `{m['optional_complete_prefix']}`中，release phase并集{release['prefix_phase_union_cycles']:,}cycles，与scheduler unavailable的{release['scheduler_prefix_cycles']:,}cycles仅交{release['scheduler_overlap_prefix_cycles']}cycles。说明**已经开始发C之后的这段release阶段**在该prefix大多不与scheduler unavailable同时出现；不排除pre-C、checkpoint、checker请求等待或较早阶段对package completion的影响。

SC7 flags的scheduler bit6及FSM可以恢复上述interval；flag10只在snap/cooling含ROB empty，flag13pipeline stall未参与change signature。故SC7不能恢复逐cycle noCommit/ROB-head，也不能伪造release×ROB overlap。unknown后缀154,313cycles不补齐。
''')
    save('candidate_upper_bounds.md','''# Independent critical UB：范围与未知值

缺口146,410，严格整数saving至少146,411；tier阈值分别>=150k、100k–150k、50k–100k、<50k。只有有归因的独立关键路径上界才能分tier；activity duration不能冒充critical-removable budget。

| Mechanism / scope | Measured exposure / scoped upper envelope | Independent critical UB | Conservative credit | Tier |
|---|---:|---|---:|---|
| L1 release 首C→ACK，固定B中该阶段同时发生的直接阻塞 | ROI union100,915；并非source总生命周期 | 未证明critical交集；phase-local最多100,915 | 0 | exposure落100k–150k；未取得Tier2资格 |
| 其中lastC→firstL2bank | 同cohort67,366 duration | 未证明；phase-local≤67,366 | 0 | 不是已成立Tier3 |
| 其中lastbank→ACK | 同cohort4,546 duration | phase-local≤4,546，critical交集未知 | 0 | 此局部ACK回程单独为Tier4 envelope |
| L1 refill/端口/request arbitration整机制 | 未导出phase exposure | UNKNOWN | 0 | UNKNOWN |
| L2 checkpoint/drain/outerA/peer wait，包括checker与非head链 | 未导出duration与critical join | UNKNOWN；100,915不能上限整个机制 | 0 | UNKNOWN |
| 已测direct main-core headmiss | 53,845 | 删除所标直接wait≤53,845 | 0 | 仅该受限范围Tier3 |
| 已测all direct headload pending | 80,832，包含上行53,845 | 删除该nested envelope≤80,832 | 0 | 仅该受限范围Tier3 |
| BOOM scheduler unavailable | 347,409 | 该control状态暴露上界；removable部分UNKNOWN | 0 | 尚非Tier1候选 |

只根据边际计数，ROI release phase与headmiss交集为[0,53,845]、与all headpending为[0,80,832]；没有精确join。phase exposure不限制提前/延后导致的依赖链反馈，也不覆盖pre-C source reservation、checker请求或checkpoint transaction。因此 **不发布“所有transfer UB=80,832”或“所有WB UB=100,915”**。

需要分别说明四层：直接症状为retry/head wait；立即blocking谓词为MSHR not-ready/victim/WB等（存在与计数PROVEN）；上游trigger是否是具体refill/channel/checkpoint阶段（UNPROVEN）；下游重复retry放大结构PROVEN，但其关键cycle预算UNPROVEN。报告没有“已排除缓存传输”的结论。

没有把nack events×假定penalty、misses×average service、checkpoint数×burst间隙作为ROI估计。既有58,940 reference ROI改善与当前B已包含64K，不能从B再加一次；未来transfer fix叠加64K也需重新执行验证。direct head wait、retry、refill、writeback、scheduler等交集未闭合，不允许相加凑146k。

`INDEPENDENT_CRITICAL_UPPER_BOUND=null (whole-mechanism unknown)`，`EXPECTED_RECOVERABLE=null`，`CONSERVATIVE_RECOVERABLE=0`。0是当前不授予收益的保守记账，**不是证明实际收益为0**。没有候选满足当前>=100k归因门槛。
''')
    save('opt5_candidate_ranking.md','''# 最多5个候选：设计审查顺序，均未获正式Opt5资格

排序按具体机制/证据与下一步价值，不代表已有可兑现收益。cache-transfer优先展示；frontend未入选。L1 refill按用户优先级已先审完，发现旁路/decoupling已存在，当前最具体的新结构疑点移到L2 preservation。

| Rank | Mechanism | Independent critical UB | Conservative gain | RTL complexity | Area/timing risk | Confidence |
|---|---|---|---:|---|---|---|
| 1 | WRITEBACK_REFILL_INTERFERENCE / L2 preservation drain + strided Put | UNKNOWN；已测release phase100,915不覆盖全部机制 | 0 | 中：full-line snapshot buffer/pipelined reader/held burst | 512bit+control；bank节奏/ordering中高风险 | 结构高，运行主因低 |
| 2 | L1_REFILL_SERIALIZATION / shared LB read + row staging | UNKNOWN；直接head pending envelope80,832非全局UB | 0 | 小到中：extra row holding/age arb/skid | 不加端口方案较低；若改SRAM则高 | 结构高，critical预算低 |
| 3 | L1_L2_REQUEST_ARBITRATION / response resource coupling | UNKNOWN；无A/D ready-low | 0 | 小到中：age/fairness或bounded response skid，先定瓶颈 | ready路径、TL lock/credit中风险 | 结构高，选择哪一处低 |
| 4 | L1_PORT_CONFLICT + progress-aware LSU retry | UNKNOWN；nack不能直接兑换cycles | 0 | 中：resource-release wake/retained blocked reason | token/epoch/flush状态与forward progress中高风险 | retry放大高，可删cycle低 |
| 5 | BOOM_CHECKER_BACKPRESSURE / ownership-result availability | UNKNOWN；scheduler exposure347,409 | 0 | 未定，先按pkg分解wait | CDC/ownership/watermark高风险 | control暴露高，removable归因低 |

## 每个设计的9项成本/收益约束

| Rank | RTL修改点 | 新storage | 新port | SRAM timing | Hit latency | Correctness风险 | Estimated critical benefit | Fixed-trace UB | 与64K叠加 |
|---|---|---|---|---|---|---|---|---|---|
| 1 | L2Preservation.scala read/delay/send；Scheduler outerA/borrow/lock | 64B checkpoint buffer+beat/control | 可用现有bank读端，不预设新增 | 读请求更密可能增竞争；实现待审 | 不直接改L1 hit；L2争用可能变 | 旧脏image一致、CachePreserveTxn/source、整包、terminal ACK；不能早解锁或释放 | UNKNOWN | UNKNOWN；post-firstC activity只是局部100,915 | 结构可独立；B已64K，需测交互，不加历史58,940 |
| 2 | mshrs LB read arb/rowValid/refill，dcache owner/dataWriteArb | 约1 row+identity/skid（方案待定） | 不加为优先；双端口另评 | 不加端口也需验证read/write时序 | 保持既有hit pipeline是设计目标 | LB响应owner、row order、flush、RPQ terminal、reserved epoch | UNKNOWN | UNKNOWN；direct head上包络80,832仅局部 | 可能；不同miss并发/替换会改变预算 |
| 3 | MSHR A/E arbiters，L2入口/SourceD D/ACK skid（仅选实测堵点） | age bits或小skid，未定 | 无 | ready/arb组合路可能增 | 不增加hit latency是目标 | multibeat held-valid、source/sink、ACK credit、防饥饿/deadlock | UNKNOWN | UNKNOWN | 可能，非保证可加 |
| 4 | LSU age-wakeup/nack retention + dcache真实blocked reason释放 | 每LDQ少量reason/epoch状态 | 无 | wake组合扇出需审；不改array目标 | hit可立即调度需保持 | 不漏probe/WB/owner变化唤醒，flush/token重用、SC/AMO forward progress | UNKNOWN；首先可能只降访问/功耗 | UNKNOWN；已测direct miss<=53,845 | 可能，64K降低可抑制事件 |
| 5 | R_IC scheduler/ownership/result CDC，先不改 | 未定 | 非cache SRAM port问题 | 无直接array改动 | 无直接L1 hit改动 | release必须真实result acceptance，不能把frontend空闲当available | UNKNOWN | UNKNOWN；347,409仅状态暴露 | 可能，需package critical attribution |

这些是有明确修改边界的**设计假设**，没有硬件patch、默认新配置或正式run launcher。优先无容量/way增加、无hit延迟、无新增SRAM端口；不能用面积成本替代收益证据。不会重做已经存在的ordinary-load LB bypass/LDQ age priority，也不会盲改BankedStore优先级（SourceC>SinkD等有coherence原因）。

唯一主候选判断仍为 `NONE_JUSTIFIED`。L2preservation最值得继续审，不足以声称当前能独立恢复146k，或宣称必须64K+fix即可达标。
''')
    save('frontend_last_resort_assessment.md',f'''# BOOM/checker backpressure 与 frontend 最后手段门槛

B scheduler unavailable {c['scheduler_unavailable_cycles']:,}cycles，scheduler∩MSHRbusy269、scheduler∩headmiss0。optional prefix scheduler unavailable {release['scheduler_prefix_cycles']:,}；与已测post-firstC release阶段交集仅{release['scheduler_overlap_prefix_cycles']}。已量化control暴露，但不能把它归因到frontend，或声称因与BOOM miss少重叠所以与所有cache transfer无关。

BOOM private L1统计不覆盖checker私有cache/async A、L2 shared Get服务、source-indexed peerWait、水位安全gate。checker后端memory wait可能使package finish延迟并传播到scheduler availability，仍属优先检查的资源链。现有mandatory package生命周期可恢复allocation/result/handoff，但缺少对应cache transaction/source stage，尚无“哪个缓存请求拖慢哪个package”的闭合链。

| frontend提升条件 | 当前状态 |
|---|---|
| 全部cache-transfer opportunity<100k | **未证明**，whole-mechanism UB未知；仅一段ACK回程很小 |
| LSU/retry/refill不足 | 直接head范围不足达标已知；非head与传输整机制未闭合 |
| BOOM/checker backpressure不足 | **未证明**，347,409为状态暴露，不能排除或授予收益 |
| frontend stall有大规模critical overlap | 无保存的stage→package→result→BOOM关键join |
| frontend真正拖慢package completion | 无反事实/依赖归因；utilization不是证据 |

未满足提升条件，`CHECKER_FRONTEND_PRIORITY=LAST_RESORT`，不修改frontend，也不因当前缺数据而随意选它。下一步资源归因顺序：缓存transfer和peerWait → LSU progress/retry → package ownership/result availability → 最后frontend。
''')
    save('next_run_plan.md','''# 下一步：MORE_OFFLINE_ATTRIBUTION，无硬件命令

`NEXT_ACTION=MORE_OFFLINE_ATTRIBUTION`，`COMMANDS_FOR_USER=[]`。本轮没有可证明>=100k独立critical预算的明确优化，因此不准备或执行Opt5硬件run；也不要求diagnostic-only run、A′、geometry/MSHR sweep。缺少的per-cycle事件不能从已保存汇总凭空恢复。

离线下一步已收敛到一个具体问题：**能否在保留终端ACK/旧image锁语义的情况下，缩短L2 preservation采集/发送和全局drain，并证明它影响的是package/关键请求？**

1. 继续静态审查checkpoint候选与directory/SourceD四级quiescence依赖，确认全局drain的最小安全范围、full-line预读能否避免outerA packet valid-gap、是否有能由既有源码严格给出的服务槽上界；不从事件数乘固定penalty构造收益。
2. 复用已保存mandatory pkg/ownership/result与SC8/SC20/38/21，按line/image/pkg只做身份支持的连接，先定位pre-C等待、same-set冲突和长尾模式。image contentSeq只是写入版本，不等于请求者package，不能直接把release pkg当critical消费者。
3. 核对checker client source区间、async bridge容量与peerWait回放路径；静态界定哪些机制可在BOOM MSHR idle时拖延package完成。若已有事件不足，结论继续unknown；不要求为补counter单跑。

## 未来一次功能候选run中才合入的bounded diagnostics设计

以下仅设计清单，**本轮未改RTL、未收新数据**。这些counter不足以自动证明removable，需要在同版本候选优化里验证性能和阶段减少，并沿用现有正确性/ROI gates。只允许届时选择一个已收敛功能候选。

| 位置 | 有界counter/histogram | 关键关联 |
|---|---|---|
| L2Preservation/Scheduler | capture/req/ACK计数，drain请求cycles、等待SourceD/C/SinkC原因mask，read/delay/send/waitAck各state cycles，lock cycles，outerA held&&本引擎!valid gaps，SourceA valid被lock/ready阻cycles | head/BOOM请求与checker source分别计；held gaps必须确认已持有arb，不能将任意idle计入 |
| L2 directory/requests/clientWait | A首beat等待、same-set/normalMSHR/dirready/locked/unsafe peerWait partition；每source或client类accumulated/max-age | source+line+request serial+requester pkg，pkg不可从旧image seq偷换 |
| SourceD/BankedStore/SinkD | first-ready到Dfire，bank read/write valid&&!ready，分阻塞priority；D queue高水位、outerD grantsafe阻塞 | stage occupancy原因可重叠，输出union与multi-cause mask，避免重复计账 |
| L1 MSHR/LB/refill | alloc→Afire→first/lastD→ordinary response→victim snapshot→install rows→meta→E；LB读被写抢cycles、rowValid等dataWrite、same-set WB pending | source+MSHR generation/txn+stable LDQ token，head标记只用于对应请求；行安装和load response允许不同顺序 |
| LSU/ROB + ownership | retry reason-release cycles、同token retry hist；headmiss/any-head/noCommit与上述resource exact intersections | commit与scheduler必须独立取实际信号，不能用SC7 sparse flag13代替 |
| checker/package | package活跃阶段memory待响应、local completion、result CDC、BOOM acceptance、ownership释放 | cache请求者身份→package completion→accepted result→scheduler阻塞链；保持现有release终态定义 |

存储预算建议：固定64bit counter bank（约64项/相关域），32bin logarithmic latency hist，按实际MSHR/source已有事务table跟踪，不加无限per-request log；每类最多top8尾部记录，身份/丢失/溢出有明确counter，ROI start/stop bounded snapshots并使用现有exact-rdcycle采样语义。clock域内计数，转换到200MHz要显式标记区间/边沿；不把checker周期直接相加。

必须保留：程序verified/checksum、完整320 package lifecycle/PASS平衡、held valid、source/sink与整包协议、CacheImage/epoch/txn身份、水位安全、最终bank commit和terminalACK guards、capture完整性、ROI/native provenance。功能与bounded诊断同版本，尽量复用当前B作reference，不自执行、不自动retry。

若后续仍无法给足够大且独立的关键预算，维持NONE_JUSTIFIED；不会因为流程需要下一步就选择frontend或加容量。
''')
