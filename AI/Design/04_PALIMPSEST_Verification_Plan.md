# PALIMPSEST 验证现状与后续计划

## 版本、验证层次与通过标准

审计日期 2026-11-21；HEAD `75f2905693d6eec3b92d733e65bafa7a9c4be6dc`，分支 `firesim/fpga-checkpoint-20261104`。本轮只读代码与已有证据，写入设计文档；**未执行 Scala compile、elaboration、RTL 仿真、故障注入或新测试。** Chipyard 源码无未提交修改。功能矩阵的状态与动态验证覆盖分开，见 [01](01_PALIMPSEST_Feature_Matrix.md)。

后续每次验证分别记录以下层次，不能互相替代：

| 层次 | 目的 | 不能证明的内容 |
|---|---|---|
| L0：契约/reference model/host checker | 检查历史模型、候选选择 oracle、trace 分析器的正反样例 | 不运行 RTL；不能证明握手/存储路径实现 |
| L1：Scala compile | 类型与源级依赖正确 | 不证明 elaboration、组合环或行为 |
| L2：elaboration/FIRRTL/RTL lint | 目标参数下连线、width、CDC 接口、组合环 | 不证明运行时正确性 |
| L3：模块 RTL fixture | SVB、EVT/CP、真实 cache bank/ACK 的定向行为 | 不证明整机 Checker/流水线恢复闭环 |
| L4：单 Main 集成/整机 | 实际 Error→SCP→历史→内存→Restart；架构 trace 对照 | 不证明双 Main 或未覆盖资源/时钟配置 |
| L5：多核/随机/属性验证 | 一致性、并发、资源约束、连续回滚、外部可见性 | 必须明示公平假设、界限和覆盖范围 |

每个测试结果至少包含：配置/容量/时钟、source 与 generated/binary 哈希、软件哈希、seed、初始 CP/EVT/版本分布、事件 trace、期望与实际数据、断言结果、未完成责任、失败原因。缺必要覆盖记 COVERAGE_MISSING/Unverified，超时记具体阻塞责任，不把没跑记 PASS。

<a id="existing-evidence"></a>
## 已有证据及本轮核验

所有路径相对 Chipyard。本轮核验的是清单与文件身份，没有重跑其仿真，也未重新解析完整 FST。

| 证据 | 已确认内容 | 使用限制 |
|---|---|---|
| `../slowdown/opt4/frozen_manifest.json` | 20/20 frozen_source_sha256 与当前文件一致；12/12 measured_hardware_sha256 一致；6/6 raw_evidence_sha256 一致 | 关联当前相关源码与历史证据，但不是当前 HEAD 的新仿真/全仓库来源证明 |
| 清单关联 `../slowdown/optimization_4_svb/runs/optimization_4_svb_20261030_072604_18475a92/` | BFS512，benchmark verified=1；清单 correctness/PASS、无 failed/cancelled result，ordering/protocol PASS | 正常无错误执行，不能证明回滚；清单保留 baseline RUN_PROVENANCE 与完整 cache/package/DRAM durable-drain 未闭合 |
| 同清单 integrity | allocations=406，PROMOTED_COMPLETED=391，COALESCED=12，FLUSH_DISCARDED=3；无重复 beat/errors | 分配生命周期及正常数据完整性；3 次 flush 不等于已证明对所有 outstanding CP 安全 |
| `../AI/Debug/scripts/stage2/Stage2Generate.scala`、`stage2_test.cpp:278` 起 | 有真实 L1/SourceD 相关定向 fixture；源码含 10 CASE：同包、跨包等待、receipt、AMO/SC、refill、替换及 denied A | 本轮未运行；CASE 输出文本不能当实际 PASS |
| `../AI/Debug/scripts/stage3/Stage3Generate.scala`、`stage3_test.cpp` | 有真实 L2 preservation/probe/victim 的 fixture 和 directed 驱动 | 本轮未运行，不确认所有配置与当前 HEAD 源码一致 |
| `../AI/TMP/stage3_runs/run_igda2knt/summary.json` | 实际 BUILD=PASS、DIRECTED=FAIL，`repeated_speculative_same_line` 等 flush completion 超时；SYSTEM=NOT_RUN | 历史失败，未建立与当前 HEAD 的逐项源码身份关联，不能断言当前仍有同一 bug |
| `../AI/TMP/stage3_runs/run_qx63gyhc/summary.json` | BUILD/DIRECTED/SYSTEM 均 PASS，SOURCE_PROVENANCE=PASS、STAGE3_STATUS=VALIDATION_PASS；STAGE3_CLOSURE=NO | 历史成功也需保留；本轮未将其源码哈希关联到当前 HEAD，不能外推当前所有配置或 Rollback 已通过 |
| `../slowdown/optimization_4_svb/scripts/offline_protocol_tests.py:54` 起 | host 分析器合成 trace 用例覆盖 delayed ACK、source 生命周期、wrong ACK、重复/缺失信息 | 是 Python checker 测试，不是 RTL 故障恢复仿真 |
| 当前硬件 assertions | dcache:3084/3085 stale-image/保存许可；:1623 ACK 匹配；SVB:244 completion key/entry；Scheduler:779–782 锁内禁止覆盖；MSHR:828/829 WB 完成前禁止 acquire/tag 更新 | assertion 存在不代表触发过；没有 EVT/恢复读/架构恢复不变量覆盖 |

未发现可连接当前主核的 RollbackController、EVT、CurGen 或 LatestSurviving，因此不能给这些功能标“已有 RTL recovery test PASS”。`../check/area_eval/rtl/palimpsest.sv` 位于面积评估目录，未作为当前 Chipyard production 调用链证据。

关键当前源码 SHA256（便于后续判断本报告是否过期）：

| 相对源码 | SHA256 |
|---|---|
| `generators/boom/src/main/scala/lsu/dcache.scala` | `c6e335f0c9da7efdc19a8e47cd728f0900693c96713fbf5cc5f35cb9dcd3c5a5` |
| `generators/boom/src/main/scala/lsu/speculative-version-buffer.scala` | `06ea7878bc47cd55b076fc8634d9ef62db53509435fd87225d9e6b82d41df870` |
| `generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala` | `c542db732d6d57d9b3f589d14505a4629a9ada7b8c420e076af9bdf779ecce85` |
| `generators/sifive-cache/design/craft/inclusivecache/src/L2Preservation.scala` | `c044da2da26941b93fe7776a1f690e194d5ed9daa2a5fde2fa6ab7e98b8e64fc` |

## Oracle 与必须采集的状态

建立独立于实现 FSM 的 reference history：记录每核每段起点 CP、已提交 Store 的地址/byte mask/值、分配 Epoch/Seq、有效区间和外部传播事件。恢复 oracle 对目标 CP 在有效历史中求最后一次写，不能以 RTL 自己的 `entrySafe` 或命中的版本作为期望值。

普通执行 oracle 比较 architectural commits 和外部数据；恢复 oracle 额外比较：SCP 的完整架构状态、废弃后缀、恢复后第一次及后续访存、新 Epoch 的继续执行、尚存旧 CP 的可恢复性。safe baseline 是每地址实际已安全对外提交的值，不得硬编码“总是 A1”或“Seq 最大就是正确”。

关键事件采集：error producer/Queue/CDC dequeue、CP pin/read/restore commit、停 issue/commit、EVT/G 更新提交、每层 candidate key/data、实际 bank write、recover install、TL 首/末 beat 与 ACK、owner/txn/source/epoch、SW old/new、restartPermit。以同一 source/generated/binary 版本关联，不混用旧波形和新行号。

<a id="test-cases"></a>
## 定向测试用例

以下均为**后续计划**；“当前预期”是静态分析对已知缺口的判断，不表示本轮测试结果。T01–T04 等正常保存用例可回归已有能力；包含恢复操作的用例需在相应阶段新增 RTL 后执行。

### T01：Same-segment Store 与 byte mask

- 初始：DRAM/L2 baseline 整行为已知非零字节图案，Main 当前段 s，L1 Current 来自前驱；有空历史槽。
- 操作：s 内对同址重复 Store，覆盖不同字节/word；加入 AMO、SC success/failure 子例并固定独立 reservation 条件。
- 预期：只保留段起点需要的前驱，不为每个中间值创建 rollback CP；最后 Current 数据等于逐次 mask/原子操作组合，SC fail 无写效果。
- 判据：实际数据与独立 byte-level oracle 相等，semantic effect 恰好一次，内容身份只在真实效果更新，旧 CP 仍可恢复。
- 层次：L3（真实 data array/StoreGen），L4。关联 B4/B5、路线 0/4。

### T02：Cross-segment Version Creation

- 初始：SW6，A7 在 L1、Seq7 pending，SCP8 已保存，SVB 空；DRAM A1。
- 操作：Seq8 第一次普通 Store A8，随机 backpressure 行读取/capture.ready；随后再写 A8'。
- 预期：整行 A7 捕获完成前不写 A8；之后 A7 历史+当前 A8'，第二次同段写不额外保留 A8。
- 判据：snapshot 全字节等于写前 A7；Store effect 严格晚于 capture.fire，数据/key 不混段。当前快路径有基础，其他命令 fallback 分别计覆盖。
- 层次：L3/L4。关联 B2/B4/B7、路线 0/4。

### T03：Preserve-before-reuse 与 ACK

- 初始：L1 或 L2 victim 是某 outstanding CP 唯一需要的旧版本，目标将被重用。
- 操作：延迟下层 ready、末 bank write、Preserve/Release ACK；插入错误 source/key/size/txn、重复 ACK 和 denied/corrupt 子例。
- 预期：下层实际保有副本且匹配 ACK 前，原责任/数据不释放；错误 ACK 不授权覆盖，失败保留诊断和责任。
- 判据：每次物理覆盖有准确 key 的已保存证明；首 beat/入队不是保存完成；源 ID 不在 ACK 前复用。
- 层次：L3（真实 L1 WB、L2 SourceD、outer engine），L4；关联 B7/B8/C8，路线 0/5。

### T04：SW 阻塞与乱序解除（Figure 4(a)）

- 初始：SW3，Seq5/6 已 PASS，Seq4 pending；L2 D6 必须外写才有空间保存 A7。
- 操作：提出保存/替换请求，延迟 PASS4；允许检查器/控制流继续；随后发 PASS4。
- 预期：SW 未到6前 D6 不可写 DRAM；PASS4 之后连续推进到6，WB ACK→A7 保存 ACK→后续覆盖按次序完成。
- 判据：所有真实外层 A/C data beat 的版本均有效且 Seq≤对应 SW；close ACK 不能提前冒充 PASS 或 WB ACK。
- 层次：L3/L4；关联 A6/C2/C4/E2/E3，路线 1/3/6。

### T05：Figure 4(b) 的 FAIL8→A7→新 Epoch

- 初始：DRAM A1，SW6，A7 未验证，A8 为 Current，SCP8=Seq8 起点；保留 A7 在 SVB。另设 Seq9 已 PASS、Seq10 已分配。
- 操作：真实 Checker 注入寄存器或 Store 数据 mismatch 形成 FAIL8，经 Queue/CDC 交付；恢复后 Load A 并继续执行新段。
- 预期：SCP8 恢复；8–10 原执行无效，7 有效；A7 即使 pending 也保留并被读取；新 Epoch 从大于10的 Seq 开始；A8/旧 PASS9 不影响恢复。
- 判据：架构状态和每个恢复后内存读与 oracle 一致，第一次读=A7，绝非 A8/A1；无废弃数据外传；继续执行并完成新验证。
- 层次：L3 子路径→L4 真 Checker→L5 交错；当前预期缺恢复控制且 FAIL 可能删除 A7。关联 D1–D16，路线 0–5。

### T06：有效但 Unsafe 的历史保留

- 初始：多个 outstanding CP，A7/A8 历史，SW6，其中 A7 是 SCP8 唯一合格 predecessor。
- 操作：FAIL8；分别插入普通 exception、统计 RESET、会话边界；独立子例让 A7 有/无另一可靠副本。
- 预期：有效且仍需要的 A7 不因大于 SW 或普通 flush 消失；有副本时可以搬移/释放，但仍可定位恢复。
- 判据：每个 live CP/地址的 required-version 集合始终有可用副本；不要只比较 SVB occupancy。当前 FAIL cutoff/flush 分支预计违反该保证。
- 层次：L0 oracle、L3/L4；关联 B9/D6/E7，路线 0/3/4。

### T07：无合格 Cache Version 时 SafeBaseline

- 初始：情况 a：目标 CP[A]=A1，缓存无 surviving candidate，DRAM 确为 safe A1；情况 b：DRAM A1 但仍有 surviving A7。
- 操作：触发 staleCurrent 恢复 Load，强制 L1/L2 miss；b 将 A7 放在更低层或延迟查询响应。
- 预期：a 使用 A1；b 必须等待/选择 A7，不能把上层 noCandidate 当整个域无候选。不存在可证明正确数据时应保持等待/报错，不能猜 baseline。
- 判据：响应数据、选择理由与 oracle 一致；恢复安装绑定新 G，内容生产身份保留。
- 层次：L3 跨层 fixture、L4；关联 D11–D14，路线 4。

### T08：连续 Rollback 与跨 Epoch 存活区间

- 初始：e0 有效至7，第一次恢复后 e1 分配11/12，旧 SCP7 仍未解决；保留不同 Epoch 需要的数据。
- 操作：先 FAIL8 恢复，再 FAIL12 恢复；另子例在第一次恢复后收到有效的旧 FAIL7。
- 预期：EVT 保留各次所需有效区间，Seq 不重用，第二次恢复选择正确跨 Epoch predecessor；旧有效 FAIL7 仍可恢复至 SCP7。
- 判据：每次恢复后架构/内存 oracle 相等；不因新 Epoch 只允许本 Epoch 而排除合法旧版本；CP pin/EVT 项不早回收。
- 层次：L3/L4/L5；关联 D7/D8/D11，路线 2–5。

### T09：错误之后已 PASS 的段与多错误仲裁

- 初始：7 pending、8 pending、9 PASS；多个 Checker 可同周期返回不同 Seq 错误。
- 操作：同时或前后返回 FAIL10/FAIL8，恢复期间再到旧 PASS9 和 PASS7。
- 预期：选择最早仍有效错误；作废8及后缀，忽略废弃结果；保留有效 PASS7；新 SW 只按有效前缀推进。
- 判据：对比独立有效区间模型；sticky failure 不永久污染新执行；位图槽环形复用不误接旧结果。
- 层次：L3 result/EVT、L4；关联 A5/A6/D6/D8，路线 1/3/5。

### T10：Cache Miss / Refill 与 Rollback 并发

- 初始：MSHR 已分配，GrantData/LineBuffer/RPQ/SDQ 在不同阶段；部分请求属于将废弃后缀。
- 操作：在首/末 D beat、refill install、replay grant、physical Store effect 的邻拍注入 FAIL；改变 backpressure。
- 预期：总线已接受责任完成，错误历史的响应不能安装有效 Current 或重复执行效果；surviving 请求按既定协议处理。
- 判据：slot/token/txn owner 不误配；安装后 key/data/G 全一致；恢复 Load 不读废弃数据；D/E 协议无孤儿。
- 层次：L3 真实 MSHR+bank、L4；关联 D5/D15/E6，路线 1/4/5。

### T11：结果与 DATA/ARF/END 在途

- 初始：独立 CDC 中有当前段和后续段片段、结果；CP 槽即将释放/复用。
- 操作：Error 已被 Main 接收后，继续交付旧后缀的 END/ARF/PASS；延迟有效前驱的 PASS；阻塞 result ready。
- 预期：不丢有效前驱结果，不复活废弃历史；pin 的 SCP 不被 slot reuse 覆盖；每条结果/控制责任恰好终结。
- 判据：跨域 enqueue/dequeue fire、Seq/Epoch/core 归属匹配，不能从 queue empty 的一拍推断 drain。
- 层次：L3 CDC integration、L4；关联 A1/A4/A5/D8/D15，路线 1/2/3/5。

### T12：在途 Preserve 与 Rollback

- 初始：旧值在 capture read、captureHold、SPEC 或 WB_WAIT 各状态；A7 是有效历史，A8 是废弃历史。
- 操作：分别在 capture.fire、promote.fire、C 首/末 beat、ReleaseAck 同拍/前后发 FAIL；加入同址新恢复安装。
- 预期：A7 不能被错误删项；已接受 C packet 完成；匹配 ACK 只终结旧 reservation，不能清恢复后新 owner。
- 判据：全行 hash/字节在 producer→buffer→C→bank→recovery read 一致；责任守恒，无提前 free/重复 completion。
- 层次：L3/L4；关联 B8/D15/E6，路线 0/4/5。

### T13：在途 DRAM Writeback 与旧版本覆盖抑制

- 初始：safe K6 正在 outer Put/Release，K7/K8 存在片上；另子例旧 safe K5 延后试图写同地址。
- 操作：延迟/重放 ACK，交换其他地址响应顺序；在此期间回滚及安装新 Current。
- 预期：有效 safe K6 可以正确完成；旧 K5 不覆盖已更新 baseline；废弃版本不因新 SW 增大获得外传资格。
- 判据：DRAM device 逐写 scoreboard 比较每地址版本顺序和实际字节；ACK echo 只完成对应 immutable snapshot；不以输出队列 enqueue 认定 DRAM 完成。
- 层次：L3 L2+真实 outer adapter/memory fixture、L4；关联 C4/C8/D15/E6，路线 3/5。

### T14：Backpressure、异步时钟与 ACK 身份

- 初始：request/result/CP/recovery-response 每个 Decoupled 口可受阻；Main/Checker/L2 用不同合法时钟比。
- 操作：随机 ready-low、ACK 延迟/重复/陈旧事务、SW 一次推进多个段；恢复提交跨时钟。
- 预期：valid 和 payload 保持，所有责任只在 fire/匹配 terminal 更新；SW/history 信息不会撕裂导致提前许可。
- 判据：稳定性断言与端到端事务守恒；在允许的 CDC 延迟之后解除阻塞。特别审查当前 `newSW ^ (newSW>>1)` 多步跃迁的跨域安全假设，不能假定多位变化仍是单步 Gray。
- 层次：L2 CDC 检查、L3/L5；关联 A1/A6/B8/E3，路线 1/3/5。

### T15：双 Main Coherence / Isolation / Ownership

- 初始：A/B 核各自 Seq/Epoch/SW；A 持 unsafe A7，B image-aware，另设普通 Rocket/DMA unaware peer。
- 操作：B 发 Get/AcquirePerm/AcquireBlock/AMO，A 保持后续冲突写；A PASS 后允许 B 接收，再由 B 写新值；A/B 各自独立回滚。
- 预期：其他 Main 与 unaware peer 都等 producing core 对应安全条件；同核内部 unsafe 访问可继续；B 后续 Store 使用 B 历史；A 回滚不失效 B。
- 判据：数据与权限的实际 D/Grant 发出时满足 HistoryValid&&Seq≤SW[producer]；不能仅按 isImageAware 豁免。用 coherence reference model 检查 sharer/owner mask 与数据。
- 层次：L3 两真实 client+L2、L5；关联 C5/C6/D17，路线 6。

### T16：资源受限与 Full Fallback

- 初始：SVB 取1/2项、小 set/way、MSHR/RPQ/SDQ/ACK queue 接近满；多个地址/CP 竞争。
- 操作：持续跨段 Store/替换/Probe，限制下层吞吐；在满资源时要求 early close 或 Rollback。
- 预期：正确 backpressure，不覆盖必要历史；存在可用的检查/close/drain/recovery 路径；解除压力后继续执行。
- 判据：有界进度在明确公平/外部响应假设下成立；所需历史集合不丢，不能用 CANCELLED 或 watchdog 超时当成功。记录阻塞资源依赖图。
- 层次：L3/L4/L5；关联 B10/E1/E4/E5，路线 0/4/6。

### T17：完整 Architectural Restore

- 初始：int/FP/PC/FCSR 和约定 CSR 都为独立非零图案，不同 Seq 的 SCP 可区分；PRF/rename map 与提交 shadow 不同。
- 操作：错误段修改所有架构状态，含权限边界子例；恢复对应 SCP 后读回并执行依赖指令。
- 预期：恢复值来自段首而非段尾/最新 shadow；PRF/映射/空闲表/busy 状态一致；x0 不被破坏。
- 判据：恢复 commit 时逐项比较，随后 instruction trace 与 fault-free SCP 重放一致；不能仅检查 PC。
- 层次：L3 restore engine/rename、L4；关联 A4/D3/D4，路线 2。

### T18：Trap、MMIO 与不可重复 I/O

- 初始：device counter/read-to-clear/write-once mock，当前段含尚未验证运算；另有 timer/exception/privilege 转换及 live history。
- 操作：在 unsafe 执行即将发 I/O 时要求 early close；分别 PASS/FAIL；恢复过程中注入 trap，随后重执行。
- 预期：先关闭并验证规定前缀，再允许外部一次性动作；FAIL 不产生不可撤销效果，重执行不重复 I/O；普通 trap 不丢必要历史。
- 判据：device side-effect 总数/次序精确匹配合法执行；TL 首 beat 需独立验证许可，非仅 ROB committed；架构/CSR/trap 状态正确。
- 层次：L3 IOMSHR+device，L4/L5；当前通用验证屏障缺失。关联 C7/D4/E5，路线 0/2/6。

### T19：EVT/G/Seq/serial 边界与容量耗尽

- 初始：缩小测试位宽、EVT/CP 表容量；有旧 Epoch surviving 版本和在途 ACK。
- 操作：连续回滚至表满，推动 Seq/G/slot epoch/content serial 接近回绕；反复分配释放 CP。
- 预期：不复用仍可能被引用的执行/事务身份；空间不足正确阻塞/压缩/安全停止，不能静默 wrap。
- 判据：无旧 ACK/旧结果被认成新 owner，无错误 history-valid 命中；各容量释放满足 CP oracle。具体位宽/满表策略是设计决定。
- 层次：L0/L3/属性验证；关联 A3/D7/D8/D9/D15，路线 2/3/5。

### T20：Rollback 与 Cache Replacement/Coherence 同拍

- 初始：恢复所需 A7 位于待替换 way/历史 sidecar，Current A8 另处；Probe/refill 命中同 set。
- 操作：交错恢复 query、victim capture、directory write、recovery install、ACK；同 set 不同地址与同地址两种。
- 预期：selected candidate 在返回/安装前被 pin 或重新验证；不能读一半旧行一半新行；锁和 owner 无交叉释放。
- 判据：数据/key/CurGen 原子一致；每个覆盖有保留证书；恢复后第一次 Load 与 CP oracle 相等。
- 层次：L3 real bank+directory、L4；关联 B7/D14/D15/E6，路线 4/5。

### T21：Pending Coherence 优先与长期冲突写

- 初始：外核请求因 producing core unsafe line 被 park；producer 不断发同址后续 Store。
- 操作：先使请求版本安全，继续竞争 bank/MSHR 和同址写；重复多个 requester。
- 预期：pending coherence 获得相对后续冲突写的优先机会，不被无限延期；必要时正确关段。
- 判据：在公平假设下请求最终收到安全数据/ownership；资源等待不能因无关进度永久刷新 watchdog。
- 层次：L3/L5 活性；关联 C6/E1/E2/E5，路线 6。

### T22：多层历史与多个 Checkpoint

- 初始：A7 在 L2 history、A8 在 SVB、A9 在 L1，DRAM A1；各 SCP 都仍可能成为恢复目标，至少一个前驱 pending。
- 操作：分别选择不同错误段，恢复过程中搬移/回收其他版本；再执行新 Epoch Store。
- 预期：每次按有效历史选择目标 CP 所需最新版本；历史跨层位置变化不改变可恢复性；新 Store 正确继承整行。
- 判据：对所有 live CP 的 required-version 检查不变量，不只测试当前一个错误段；跨层 query 汇总候选，不提前 baseline。
- 层次：L3 跨层 fixture、L4/L5；关联 B6/B9/D11/D14，路线 4/6。

### T23：False sharing / Timer flag / 中断前进

- 初始：不同 hart 的同步/中断标志分别采用同 cache line 和独立64字节 line 两种布局；unsafe 数据与 handler 读取竞争。
- 操作：producer 等待 consumer，consumer 因隔离等 producer 验证；加入 timer trap、关段及恢复。
- 预期：论文 IV-G 的独立行布局下避免无关阻塞；存在正确的 handler/producer 进度路径；同 line 情况明确限制和处理策略。
- 判据：不在不安全可见性的代价下解除等待；跟踪实际 producer seal/Checker 进度，不能只看 timer interrupt 被触发。
- 层次：L4/L5；关联 E1/E5、IV-G，路线 6。

### T24：端到端故障回归与正常执行回归

- 初始：小程序可枚举 fault-free trace，再扩到现有 BFS/内存压力 workload；固定可复现 fault seed。
- 操作：注入寄存器、Store-data、检查结果延迟、替换和 ACK 交错；多次恢复后完整运行，末尾要求所有必要责任闭合。
- 预期：可恢复错误回到指定 CP 并继续；最终架构状态、内存和外部动作等价于合法参考执行；正常无故障能力保持。
- 判据：benchmark verified、architectural+memory oracle、历史/事务守恒、全部断言共同通过；exit0/package 数平衡单独不足。区分 PENDING_RETAINED 与真正 durable drain。
- 层次：L4/L5；关联全矩阵，路线 7。

### T25：Checker 单状态失配与真实错误事件覆盖

- 初始：Main 与 Checker 的 SCP/ECP/Seq 归属一致；构造无额外访存、各 int/FP/PC/FCSR/约定 CSR 可独立区分的短段，先建立完全匹配的 PASS 对照。
- 操作：每个子例只使一个合法段尾状态不同，优先 f0-only，再逐个 f1–f31、x1–x31、PC、FCSR flags/rounding 及约定 CSR；覆盖普通段和 trap 边界。保持传输、其他寄存器和内存操作一致，避免另一种失配代替目标检测；对照 x0 的常零语义。延迟结果 ready，观察完整 Queue/CDC 链。
- 预期：f0 与其他可写 FP 寄存器同样进入比较，目标失配准确产生所属段 FAIL；匹配对照 PASS，未将 CANCELLED 当作检测成功。PC/FCSR 子例用于建立当前待验证的覆盖证据；异步 CSR 位按事先定义的合法 mask 判定。
- 判据：从具体比较器 mismatch 到 compare_done/package_error、结果入队、GHM dequeue、DCache 接收逐级对应同一 Seq，停顿下事件只交付一次；不能直接注入 FAIL 代替状态失配。当前 f0 比较循环静态跳过 0，预期先重现覆盖缺口；是否最终错误 PASS 仍需实际 RTL 验证。
- 层次：L3 R_RSUSL/CSR/真实 RocketCore fixture，再 L4；关联 A5/D1，路线 1/7。与 T17 的恢复正确性分别验收。

## 建议断言/属性（后续实现）

| 属性 | 必须检查的语义 |
|---|---|
| CP-available | 每个可能被选择的错误段都有完整、未覆盖的 SCP；pin 到 restore commit 后才能释放 |
| Checker-coverage | 每个约定可检查状态都进入所属段比较，包含 f0；单状态失配形成 FAIL，不能由取消或无关失配掩盖 |
| History-preserved | 对所有有效 outstanding CP，每地址所需 predecessor 存在于可检索的某层或正确 baseline |
| No-discarded-read | 普通/恢复 Load 都不能返回已废弃历史；G 不匹配必须走恢复选择 |
| Safe-external | 每个 DRAM/跨核数据与 ownership 的实际传输满足版本有效且 Seq≤producing-core SW |
| Exact-receipt | ACK 只能完成其原 key/txn/reservation；责任在末数据效果和准确 terminal 以前不复用 |
| Restore-atomic | restartPermit 蕴含 arch_restore_done、history_committed、inflight_reconciled；无旧事务污染可能 |
| Fresh-history | Seq 不复用，Epoch/G 更新关系明确；过期结果不能推进新 SW |
| Progress | 公平与下层最终响应假设下，有界资源压力最终解除；timeout 不是正确性成功 |

属性实现应基于独立 ghost/reference 状态或真实效果点，避免把 DUT 自己的 permit 信号再断言等于它自己。所需数据保护可先在模块 scoreboard 构建，再扩展跨层 owner/CP oracle。

## 最小验收批次

1. 保留基础：T01–T04、T06、T16；先证明 A7 不丢、覆盖/ACK 次序正确。
2. 单核恢复：T25、T05、T07–T12、T17；包括真实检错、A7 pending、后续段已 PASS 和连续 Rollback。
3. 允许重启：T10/T12/T13/T14/T20 各关键同拍/邻拍，确认旧事务不污染恢复。
4. 完整部署：T15/T18/T19/T21–T24；双 Main、外部 I/O、资源极限、false sharing 和整机回归。

每批先通过 source/type/elaboration 等必需检查，再运行有明确 oracle 的 RTL fixture。保留原始 FAIL、历史 PASS 与各自运行身份；Stage3 历史失败是否在当前代码消失须建立版本关联后验证，不能通过替换旧文件或引用不同版本的正常运行抹平。

## 本轮可复现审计命令

在 Chipyard 目录执行的只读检查主要为：

```sh
git rev-parse --show-toplevel
git branch --show-current
git rev-parse HEAD
git status --porcelain=v1 --untracked-files=normal
git diff --stat -- generators
pdftotext -layout -f 3 -l 5 ../AI/Ref/DAC_2027_EC.pdf -
sha256sum ../AI/Ref/DAC_2027_EC.pdf
rg -n '\b(EVT|CurGen|LatestSurviving|NeededForRollback|RollbackController)\b' generators/boom/src/main/scala generators/rocket-chip/src/main/scala generators/chipyard/src/main/scala generators/sifive-cache/design/craft/inclusivecache/src
```

随后用 `nl -ba` 沿实际端口读取本文与 01 列出的路径。另以 Python hashlib 对 frozen manifest 的 20/12/6 项逐项核验，未改文件。`git submodule status` 在当前 EC 根因无 `Software/R-Kernel` 映射报错；当前受审代码由 EC 主仓库直接跟踪，审计用 HEAD+逐文件哈希，不推定子模块独立版本。
