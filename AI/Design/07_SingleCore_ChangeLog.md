# 单主核 Rollback 变更记录

## 2026-11-23 迟到容量请求与已关闭包

- 原 V6 Sv39 Fault8 的只读 owner 探针在 tick559795 证实：producer_open=0、protected=0、R_IC=presch，迟到 L2 请求仍匹配 retained activeSeq=35，错误启动 capacityClosing。原请求在563384退出，local hold却继续等永远不会分配的新包，最终Main watchdog。
- V10 的 Core 将既有 traffic_package_open 加入 active close 匹配，保留 R_IC 已关闭包 ACK；一位组合条件，不新增状态。正常/Fault8/Seq16 同一异常MMIO程序及原 Sv39 正常/Fault8 正在重新生成并回归。原失败继续保留，新版本尚无完整PASS。

## 2026-11-23 整核 restart/snapshot 组合环

- V7 的 15 项组件已实际通过，但正常整核在 FIRRTL CheckCombLoops 失败。完整路径为最终 IFU redirect→snapshot→RSU busy→实时 quiesced→restart→最终 redirect。Fault8/Seq16 的冗余构建已停止，失败和停止记录均保留。
- V8 仅把 snapshot guard 改为原有已注册的 architectural redirect 和 B2 mispredict；正常运行条件等价，恢复期间仍由 recoveryStop 禁止 snapshot。保留 V7 的实时 cache owner 检查，无新增硬件状态。整核正在重新生成，尚无 V8 PASS。
- V8 实际整核仍因 `restart→SCP discard→capture.ready→snapshot→RSU busy` 组合环失败。V9 撤回 redirect-only 修改，复用并前移已有 snapshot_rsu_prev，恢复排空只观察停核前已接受的 RSU 工作；cache/LSU/Checker 条件仍实时。正常整核重编中，未宣称通过。
- V6 Fault40+Seq41 的首次交叠链计分已通过：未结 journal 时分配 Seq41 不预留重基，Seq43 重放 PASS、journal 释放后才以 Seq45 完成物理 reset，随后新 Seq1 PASS。有界诊断 exit2 保留，不代表完整程序通过。
- V6 CLINT 写正常与Fault18完整退出，实际16写/16回读与同PC ACK重放联合验收PASS。长期 compact-mmio-output、Fault18 配置和 --require-output 已固化，重新编译加载字节完全一致；4个后续轮次设备错误负例全部拒绝。该测试入口不计入生产硬件新增状态。

## 2026-11-23 重启前的迟到 Probe

- P2-10/P4-01/P4-08。真实 L1 与 L2 的满 C、同址 BASE 外写和连续 FAIL8→FAIL7 场景，在第二次 Probe 到达时触发旧 restart 断言。只读原模型记录：cycle981 排空，982 新 Probe，984 仍尝试重启。组件独立反例在 cycle152 失败。
- V7 的 Controller 在 restart.valid 重新检查实时 quiesced 和 checkpointReady，等待期间保留 SCP 和 stop。没有增加硬件状态。长期 Recovery 增加就绪撤回用例，Hierarchy 增加真实 tracked C 联合场景及逐 beat 的安全 BASE 检查。15 项回归及三配置整核复验已启动，结果分别记录。
- V6 长期 Fault40 入口也已通过联合验收。Seq16 异常/MMIO 使用同一模型和 ELF，将仿真预算从 200 万增至 300 万后，在 2061735 周期通过 23 次重基及完整 oracle。原两次 200 万周期超时保留。
- Sv39 正常运行通过，Fault8 已完成 16 次映射读，但 HTIF 输出期间遇到 Main watchdog，仍为 FAIL；不能记为完整译址恢复验收通过。

## 2026-11-22 I/O 后置封口及恢复后的真实设备效果

- P4-09/P4-10/P5-10。V6 的 Main 后置封口复用 LSU 的 `ioIssueReady`。该信号等待已提交前缀及 DCache/HellaCache，解除年轻未提交 store 与退休保持之间的等待环。生产修复不增加寄存器、队列或状态机。
- V6 Scala/Chisel 与 15 项组件验证通过。正常/Fault8 的 `compact-trap-io` 严格配对通过。新增长期 Fault40 配置和只读效果观察器。原优化库联合验证在 929646 周期退出，只有 FAIL40、一次同 PC 恢复，并由 Seq43 原值重放，设备 A 握手一次。实际事件和来源见 [验证矩阵](SingleCore_RTL_Baseline/Verification_Matrix.md)。
- 长期 Baseline 增加满两拍 C 队列时的 tracked Probe、Pending 历史与连续 FAIL，在外写 ACK 反压期间持续核验发布数据。真实 L1 多层同时迁移继续跟踪。

## 2026-11-22 Seq transport 与管理异常循环等待

- P2-09/P3-15/P4-05/P4-13。V2 Seq16 在tick496000触发Main watchdog；V1只读探针证实L2扫描已结束，四个permit都高，hart2/3却因维护期间发生的无包管理异常而拒绝reset。维护冻结新A又阻止handler完成，形成循环等待。
- R_ICSL复用原FSM、trap depth和return owner输出`package_idle`，`context_idle`继续要求架构异常已返回。RocketCore只在Seq reset收据采用包空条件，并保留LSL/RSUSL/前端/结果owner约束；admission、COPY和结果交付仍用完整context。无新增寄存器、队列或FSM，没有清除异常状态或修改watchdog。
- SeqTransport夹具接生产hart1 R_ICSL；修复前组合反例cycle4455 FAIL。V4 Scala/Chisel/FIRRTL与13项组件独立复验全部通过；原driver的旧激励失败和C++修正后的来源比较失败保留。三配置整核尚在执行，不能记为通过。原V3完整源码/Chisel输入已存`v3_generation_checkpoint/`，在途V3若因V4源码变化触发原driver比较失败，保留该失败并由独立核验runner运行原生成物，不改写版本结论。
- 将V3不同基线的冷交接补充用例并入长期Hierarchy输入，接替地址和原地址分别要求0x2222和0x1111。

## 2026-11-22 冷查询交接活锁

- P3-08/P3-12/P4-02/P4-13。Fault8 只读整核探针确认 `recoveryMiss → Idle → Query` 的重复链；未修改 V2 层次模型用相同仲裁窗口在 cycle8665 失败，8000 拍内 51 次空查询、没有接受请求。
- DCache 提取 `beginColdLookup()`，复用已有地址、查询上下文和 FSM，在 Miss 当拍捕获接替地址；保留空 valid 结果及 stop 的原终止规则。未增加寄存器、队列、状态或数据副本。
- 长期 Hierarchy 新增 `alternatingColdHandoff`。V3 Scala 编译与 Chisel/FIRRTL 生成通过；13 项组件复验全部 exit0，前后源码清单一致。另以不同地址字节0x1111/0x2222补充运行整套Hierarchy，exit0。正常/Fault8/Seq16 整核构建进行中，尚无 V3 整核完成结论。

## 2026-11-21 EVT 安装与地址查询

- P2-09/P2-10/P4-01/P4-05/P4-07。真实层次复现 C 暂存与多拍外写把首次 EVT 回执卡住。DCache、InclusiveCache 和 Scheduler 用原四相邮箱的 `installOnly` 区分安装与读行，安装在各域装载后回执。
- P5-08。Hierarchy 要求 FAIL8 后来更早的 FAIL7，并在外写仍停住时收齐第二次 EVT 的高低回执。外写结束后检查 SCP7 重启、整行和邻字。反例、修复前后运行和哈希在 [验证基准](SingleCore_RTL_Baseline/Verification_Matrix.md)。

## 2026-11-21 C 准入和同址收据

- P1-03/P3-10/P4-02/P4-08/P4-13。将完整行历史采集从 C 队列入口移到 SinkC 接受拍。满队列不能阻止保存它自身等待的脏基线。查询、维护和可信 A 仍考虑未移交的 C。
- P3-10/P4-02。History drain 仍等待同组的外部 owner。只在收据会修改驻留行时等待对应 Probe。同址安全副本存在时，准入 Probe 并避免旧数据重入 History。
- P3-10/P4-08。过时目录项保留确认的基线 key。完整 tracked C 暂存复用目录查询并接受正在完成的收据，阻止旧 ReleaseData 在新基线后再次发布。旧 C 保留 ReleaseAck 与物理权限终态，较新的更新仍可归档。
- P5-06/P5-08。Baseline 用生产 fullC 夹具，检查两拍队列、同组/同址 Probe、迟到 A6 ReleaseData、A7 外存和较新 A8。Hierarchy 覆盖停住的多拍 WB 期间 FAIL8→FAIL7 后实际取数。当前测试和输入版本见验证矩阵。
- 旧整核 watchdog 的首个等待与定向复现，以及各版本使用的工件路径见 [C 准入与同址发布记录](../Debug/bugs/bug-palimpsest-c-baseline-order.md)。

## 2026-11-21 续作：Checker安装ACK、维护尾部与result CDC组合测试

- P2-09/P4-05：补各Rocket Checker的held上下文安装ACK；Main的mailbox高/低阶段均汇合L2与全部Checker。Hierarchy实例化相同生产receiver，独立慢时钟测试request高和低阶段停钟；Stage2显式连接组件接收端；无Checker的非保护TraceGenerator在构造时关闭此回执端点，正式Main默认启用。
- P3-15：L2维护证书后再汇合L1本地真实owner空闲条件，并assert物理resident为空才compact。Hierarchy在compact后冻结一个Checker，要求空EVT安装ACK之前禁止restart。
- P1-03/P1-08/P3-10：SW变化当拍立即声明history pending；direct safe resident Put等待history扫描/发布owner。Baseline新增精确SW边沿的dirty BASE候选/Seq7历史/后续可信写回排序用例。完整同址入口仍未关闭。
- P5-04：新增CheckerRecoveryGenerate.scala/checker_recovery_test.cpp：生产RSUSL的x0归一化/f0 mismatch，经完整GHM的真实result CDC触发生产SCP8/EVT/Controller。覆盖PASS不回滚、停止Checker时钟、held release、cache/restore/restart独立ACK及无重复结果。Rocket整包tail/cleanup和BOOM未实例化；此任务局部CODE_READY。
- user_build.sh现为10次emit、11个executable；脚本未执行。来源清单增加Stage2目录。任务板37 CODE_READY、32 IN_PROGRESS、0 VERIFIED；整体未完成。
- 允许的词法/任务板/AST/shell/diff静态检查已通过；不构成Scala类型、Chisel、CDC、TileLink或功能证据。未运行任何硬件编译、RTL生成、仿真、综合或FI。

## 2026-11-21 续作：真实 owner 等待环与生产 I/O 边界测试

- P4-02/12/13：修正 capacityIsolated 误等尚未发出 Acquire 的 Grant；inner Probe 全部完成、外部 Release/Acquire 尚未发出即可提交 Probe 元数据后 park。baselineReady/quiescent同样区分未发请求与已接受owner，解除 publish→计划 Grant 的等待环。
- P4-09/10/11：提取 PalimpsestIoBoundary，Core 直接实例化，保持原 ROB/LSU/RSU/R_IC/SCP 输入。新增各状态 flush 同步取消；flush 不组合反馈退休 hold。journal effectPending 经 DCache/Tile 接到 Core，跨 rollback 继续屏蔽异步中断，验证后释放，不增加 drain 依赖。
- P4-09：uncached AMO 同时返回实际旧值与独立写终态，修复仅完成 STQ 而无法唤醒 ROB 的阻塞。journal mismatch 由独立 preview 报告当前 attempt Seq，经已有最早错误与 held error 重新进入 SCP rollback，不外发第二笔设备请求；持续不匹配仍未证明可收敛。
- P4-12：Checker escape 从 Get 扩展到非 image-aware 的读数/取权限请求，包括 coherent page-table Acquire。复用最后一 way，无新数据 RAM；依赖 text/page-table 不被保护代码改写。
- P3-14/15：EVT真正合并相邻dead intervals（33bit +1比较防溢出）；96次retry保留Pending7/A7。满表后保持旧EVT，等待SW=tail/所有R_IC owner释放/SVB空，L2单目录口逐way复用原flush/Probe/Release/ACK清除所有引用，然后compact并经原context mailbox同步；普通rollback仍lazy。Epoch/G接近上界提前请求同一服务。Seq32仍单调，跨Rocket/CDC复用未闭合，P3-15保持IN_PROGRESS。
- P5-08/10：新增 pressure_test（真实64项history全满、四拍ProbeAckData、Main park、同set Checker Get+Acquire逃生、验证后重试）；hierarchy_test 新增真实 dirty victim 已接受多拍WB首拍/FAIL8/EVT/背压/ACK/邻字与恢复读取。IoHarness增加AMO、两轮rollback及地址/操作数mismatch retry；io_boundary_test使用生产Core模块；Hierarchy增加34次不相交rollback/真实维护ACK/保留safe dirty字节。修正host repeated-restart粘位，避免第二次测试误读第一次restart。
- Stage3 terminal agent 允许真实 DRAM ACK 之后、set lock 释放之前的 addressed receipt 元数据写；其他 data/metadata 仍禁止。Scheduler 新增只读观察，不参与admission。维护另新增单端口索引FSM/held CDC请求ACK；不增加数据RAM或普通hit历史CAM。
- user_build 现在 emit 9 个 top、构建 10 个可执行入口；Codex 未执行。static_check 新增 C/C++ 词法括号扫描，仍不调用编译器。

局部状态：36 CODE_READY / 33 IN_PROGRESS / 0 NEEDS_FIX / 0 BLOCKED / 0 VERIFIED。本次 P4-11、P5-08 源码和必要定向测试就绪；整体仍 INCOMPLETE。当前缺口以05/09最新记录为准，下文是历史记录。

## 2026-11-21 U-D01–U-D10 冻结后的实际续作

基线源码及56个先前 dirty/untracked 相关文件保存在 `AI/TMP/palimpsest_frozen_20261121/before/`，SHA256 见该目录上级 baseline.json；本轮无 commit/无清理，不处理用户其他 DOC 路径变动。

| Task | 实际变更/文件组 | 测试与边界 |
|---|---|---|
| P1-02 | dcache.scala 的 SW+1 单检查与寄存 Gray | Hierarchy 乱序 PASS/逐拍 SW 断言；未运行 |
| P2-06/07/10 | regfile、fp-pipeline、rename map/free/busy/stage、CSR、core | 复用写口顺序 PRF；逐 owner done；RestoreHarness 检查64/65bit全部架构槽、两轮导入 |
| P3-15/P4-06 | LSU/MSHR、dcache slotEpoch、L2Preservation/MSHR、PalimpsestHistory allocator | 普通 ID 循环；内容 serial 按地址/Seq；EVT32 仍停机，P3-15 从 CODE_READY 改 NEEDS_FIX |
| P1-03/P3-07/08/13 | PalimpsestVersionHistory / SVB | 多周期 Mem 扫描/局部合并/4项预留；无普通 hit 历史 CAM |
| P4-09/10/11 | ROB、Core、LSU、IOMSHR、tracegen | actual head、pre/post close、前驱验证、single-step、设备效果日志；IoHarness 真实 A/D 反压/延迟/重放 |
| P3-10/P4-05/07 | L2Preservation、Scheduler、Directory、MSHR | exact baseline receipt、obsolete位、旧请求replan、C物理owner保留、ready/valid gate一致；baseline_test复用Stage3真实缓存/外存agent |
| P4-11/12/13 | Core held-prefix close、history credit、Scheduler park、Directory replacement、v1 config | 4项预留不加新data RAM；保存锁保留信用；无信用且协议已隔离的请求park释放set；v1 Checker Get保留way；全满/WB/Probe交错测试仍缺 |
| P5-01/05/06/07/08 | HierarchyGenerate、hierarchy_test | 新SB/AMO/邻字/连续两次rollback、out-of-order PASS；仍不等同BOOM pipeline |
| P5-04/11 | fullcore_test.c、user_workload_build.sh、fullcore_scoreboard.py、结果事件printf | 实际BOOM与原四Checker启动、正常/Fault8同binary、内存/FP/CSR oracle、SCP/FAIL/EVT/restore/restart/newSeq；未编译/运行 |
| P5-12/13 | user_build/source_manifest/static_check/render、05–15及Debug state | 用户专用8个top构建入口；tracked/untracked/fixture/Software源码哈希；静态检查不冒充硬件验证 |

当前34 CODE_READY、34 IN_PROGRESS、1 NEEDS_FIX、0 BLOCKED、0 VERIFIED。B-ENDTOEND 的“未写 workload/scoreboard”源码缺口解除；B-EVT-REUSE/当前 B-MMIO/B-CAPACITY/B-BASELINE 仍实际未完，详情见05/09。此前有限身份“饱和门控即完成”不再适用于用户 U-D07。

另修复压力扫描尚无Seq或Seq已covered时错误锁存 Seq0 close 的等待环：InclusiveCache 只为未验证非零Seq申请close，covered/dead直接释放等待；不重复等待已无必要的close ACK。

仅执行允许的词法/AST/bash/任务板/diff 检查。所有硬件构建/仿真/综合/FI仍 NOT_RUN_BY_CODEX。下文是较早实施记录，保留作来源。


2026-11-21；基线 firesim/fpga-checkpoint-20261104 / 75f2905693d6eec3b92d733e65bafa7a9c4be6dc。初始 Chipyard 干净；现有 00–04 审计与论文目录为用户资料，未重写基线结论。未 commit。所有硬件执行 NOT_RUN_BY_CODEX。

下列路径相对 /data1/gzh/EC。任务状态以 05 JSON 为准；记录“已写”不等于任务全链完成。

## 本次续作：有限身份与真实缓存层次测试

- P3-15/P4-06：PalimpsestHistory.scala 新增生产用整组 IdentityAllocator；LSU functional/strict token 改由它分配，预留同拍 dispatch/commit/Hella 最坏需求并在不足时停止分配。slotEpoch 的 recovery/probe/clear 三个递增点改饱和；MSHRFile 禁止 epoch0 primary。保留断言并将耗尽变为功能性停止。
- P3-15/P4-06：R_IC Seq、L1 slot/image/MSHR serial、L2 preservation/release serial 的耗尽汇合至 Controller。新增端口经 tile/Core 完整连接；L2 用 sticky level CDC。fatal 立即阻止同拍 restart，之后保持 failed/pin，旧 ACK 和已接受 owner 不因新增门控被清空。L2 allocate/reload/capture 受门控，原 final plan 可继续完成。
- P4-02：MSHR busy 与 allocation-ready 分离；fence/active_transactions 按真实 owner 状态统计，避免 idle-but-exhausted MSHR 造成假 drain 等待。
- P4-01/P4-07：rollbackQuiesced 补完整 recoveryCacheIdle 条件，包含独立 prober、SVB snapshot/cross-package capture 和 killed-store replay owner；原 LSU ordered 单独不足以允许 backend reset。
- P5-09：新增 IdentityHarness/identity_test.cpp，小位宽变量组消耗至边界；recovery_test.cpp 新增 identity fatal 与 ready-restart 同拍竞争、pin 不泄漏/不提前释放检查。
- P5-05/P5-06/P5-08：新增 HierarchyGenerate.scala/hierarchy_test.cpp，真实 BOOM L1 + InclusiveCache + CacheCork + Controller/SCP + host DRAM。真实 Checker-result 输入 FAIL8；覆盖 A7 已归档、SVB 迁移重叠、accepted miss 等迟到外存响应三例。检查 load A7/未改字 A1/SCP8/Epoch1/Seq9/A8 不外写。迁移未重叠明确报 UNCOVERED。dirty victim/probe/多拍 WB 定向交错仍 P5-08 IN_PROGRESS。
- P5-12：user_build.sh 新增 EmitIdentity/EmitHierarchy，五个 simulator 仍由用户另行运行；fixture SHA/manifest 包含新增文件。Stage2 baseline lower 补 L2 identity-unavailable 的 false source，不伪装真实 history。

本次仅执行允许的材料静态检查，没有硬件构建/运行。P3-15、P4-06、P5-05、P5-06 提升为局部 CODE_READY，P5-08 从缺 fixture 的 BLOCKED 改为 IN_PROGRESS；整体仍 INCOMPLETE（30 CODE_READY / 32 IN_PROGRESS / 7 BLOCKED / 0 VERIFIED）。

| 文件/目录 | Task IDs | 实际变化及目的 | 限制/共用模块影响 |
|---|---|---|---|
| chipyard/generators/boom/src/main/scala/exu/PalimpsestRecovery.scala | P2-01/02/03/04/11，P3-01/02/03/15，P4-01 | 新增持久 SCP、held error/CP、Controller、32 个 EVT interval；更早错误重选；pin 释放同拍可回收；EVT/identity 耗尽进入 failed | bounded capacity，无 tombstone 回收；源码未编译 |
| chipyard/generators/boom/src/main/scala/exu/core.scala | P2-02..10，P4-01/10/11 | 真实分段边界捕获 SCP，停止提交/dispatch，分拍 backend reset/PRF/CSR 恢复，SCP PC restart；合并 cache close 请求；接 memory/controller 完成条件；增加恢复事件日志 | architectural/PTW/interrupt 全边界未闭合；非 v1 配置未检查 |
| chipyard/generators/boom/src/main/scala/exu/register-read/regfile.scala | P2-06 | 可选 dedicated restore 口写 p1..p32，p0=0；断言无 normal WB | 默认 false，不给其他 PRF 新增必接端口 |
| chipyard/generators/boom/src/main/scala/exu/fp-pipeline.scala | P2-06 | FP restore 经过 recode；恢复可写 f0 | 目标 RV64D；其他 FP 配置未编译 |
| chipyard/generators/boom/src/main/scala/exu/rename/rename-stage.scala | P2-06 | restore 分发至 map/free/busy | 接口属于共用 stage |
| chipyard/generators/boom/src/main/scala/exu/rename/rename-maptable.scala | P2-06 | 整数 x0→p0、xi→p(i+1)，FP fi→p(i+1) | 配合 full backend reset |
| chipyard/generators/boom/src/main/scala/exu/rename/rename-freelist.scala | P2-06 | 重建 free mask，清 branch lists/暂存 valid | 不能单独用于原 speculative rollback |
| chipyard/generators/boom/src/main/scala/exu/rename/rename-busytable.scala | P2-06 | restore 清 busy | backend 停止期间使用 |
| chipyard/generators/boom/src/main/scala/ifu/frontend.scala | P2-05/08 | FTQ 在 recovery reset/restart 复位，fresh redirect 不访问旧 entry；沿用 fetch flush | prediction/RAS/PTW 整体仍需验收 |
| chipyard/generators/rocket-chip/src/main/scala/rocket/CSR.scala | P2-07，P4-10 | 本地打包/解包实际 8192bit CSR，含 PMP/breakpoint/custom/FCSR/instret/HPM；清 WFI；cycle/time 不回滚 | 共用 CSRFile 新输入；Rocket tieoff；可选配置宽度未 typecheck |
| chipyard/generators/rocket-chip/src/main/scala/r/R_RSUSL.scala | P1-01，P5-11 | 比较索引从 0 开始，归一化 x0、真实比较 f0；指定 Seq 一次翻转 f0 snapshot，经原 mismatch/result 路径检错 | 不屏蔽 PASS/FAIL；普通配置 faultSeq=0 |
| chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala | P1-02，P2-09/10，P3-03 | stop allocation，后缀 owner 等原 CDC release，restart 不重置 Seq；禁止 Seq 回绕分配 | producer/late-fragment 清理仍需组合检查 |
| chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala | P1-01/10，P2-09，P3-05，P4-05 | CSR restore tieoff；接收 held EVT mailbox；废弃 package 走原 cancellation/LSL/compare_abort/result cleanup | 不强清 CDC；迟到 fragments 全链仍待确认 |
| chipyard/generators/boom/src/main/scala/lsu/dcache.scala | P1-02..09，P3-01..15，P4-01..13 | 最早有效错误；FAIL cutoff=failedSeq-1；单步 SW/Gray；CurGen/EVT；SVB+L2 held query；EVT 先同步再跳洞；旧 resident 真 Release/ACK/clear 后 Acquire T 安装；存活 prefix store 可在 stop 下 cold recovery；独立 archive mailbox；CANCEL 返回 LSU；归档日志改独立事件 | 单 lane/64B；baseline、容量、完整并发仍未闭合；有限身份已采用显式停机 |
| chipyard/generators/boom/src/main/scala/lsu/lsu.scala | P2-08，P4-01/03/05/10 | 未接受 suffix 取消，accepted owner 等终态；完成/取消独立计数与 arch=completed+cancelled 断言；清 live_store_mask/LSQ/局部 busy/异常；停止新 Hella owner；严格完成加法扩位 | 统计是尝试窗口，旧跨 hart/performance 软件不理解 cancellation；不声称性能指标可直接比较 |
| chipyard/generators/boom/src/main/scala/lsu/mshrs.scala | P3-11/12/15，P4-02/05/06/09 | 按 immutable block latch recovery line，load-drain/refill/install 用选中数据/key，Acquire T；MMIO pre-accept gate；transactionSerial 耗尽禁止 primary；busy 与 ready 分离 | MMIO gate 存在 close 循环；完整并发仍未闭合 |
| chipyard/generators/boom/src/main/scala/lsu/speculative-version-buffer.scala | P1-03/04/08/09/10，P3-06/09/13，P4-08 | addressed held query；pending A7 保留；SPEC suffix 丢弃、WB_WAIT 精确 ACK；存活版本升序 archive transfer；关闭 safe coalescing | 旧 promote/WB_WAIT 名称保留，但不再表示 TL Release/DRAM 安全 |
| chipyard/generators/rocket-chip/src/main/scala/tilelink/PalimpsestHistory.scala | P1-03/09，P3-07/09/13，P4-08/12 | 新 64-entry addressed history，held query，最大 surviving Seq/serial，exact-key safe publish/ACK，tombstone 回收 | 本地 RAM 升序不足以单独证明全层 baseline 次序 |
| chipyard/generators/sifive-cache/design/craft/inclusivecache/src/InclusiveCache.scala | P3-07，P4-01/08 | archive/query 四相 CDC；RAM capture 才 receipt；EVT 更新后 tombstoned close waiter 可释放；FAIL 不再当 barrier timeout | 明确单 bank require；无多 Main 扩展 |
| chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala | P1-03/07，P3-05/07/10，P4-05/07/08/12 | 接 history sidecar、unsafe preservation、incoming C staging；query barrier；active/parked peer EVT；保留失效 directory 的真实 victim 义务；discarded release 无数据化 | 普通 SourceC 与历史 publish 次序仍需完整论证；不能伪造 clients0 |
| chipyard/generators/sifive-cache/design/craft/inclusivecache/src/MSHR.scala | P3-05，P4-05/07 | live historyContext，使 active MSHR 也判断 discarded，而非只看 SW | native peer 隔离；不扩展多 Main |
| chipyard/generators/sifive-cache/design/craft/inclusivecache/src/SourceC.scala | P3-05，P4-05 | request/beat 外写断言加入 HistoryValid | 保留原 TL owner/ACK 生命周期 |
| chipyard/generators/sifive-cache/design/craft/inclusivecache/src/L2Preservation.scala | P1-07/08，P3-07/10，P4-04/08 | unsafe predecessor 整行读后 archive；safe history 复用真实 Put/echo/ACK 引擎；held key/lock | archive receipt 不是 DRAM ACK；容量前进未闭合 |
| chipyard/generators/boom/src/main/scala/common/tile.scala | P2-02/08/10，P4-01 | Core/LSU/DCache 显式恢复端口完整互连，合并 quiesced | 不扩大 Main 数 |
| chipyard/generators/boom/src/main/scala/lsu/tracegen.scala | P2-08，P5-12 | 新恢复输入 tieoff | tracegen 未运行；新增 Boring source 的非 v1 集成仍需检查 |
| chipyard/generators/chipyard/src/main/scala/config/PalimpsestConfigs.scala | P5-11 | PalimpsestFault8Config，沿用 v1 拓扑，仅 Seq8 一次 f0 注入 | 没有专用整核 workload/scoreboard |
| AI/Debug/scripts/stage2/Stage2Generate.scala | P5-01/06/12 | 新口 tieoff、baseline-only history mailbox agent、standalone L2 MSHR context | 此 lower agent 不保存 archive，不能证明 recovery；旧 directed scoreboard 需适配 |
| AI/Debug/scripts/stage3/Stage3Generate.scala | P5-01/06/12 | 新 archive/query/result 口 tieoff | 原 directed harness，无 rollback stimulus；不能证明 Figure4 |
| AI/Debug/scripts/rollback/RecoveryGenerate.scala | P5-01..05/07/09，P3-15/P4-06 | Controller/SCP/EVT/history join、真实 R_RSUSL f0 harness、真实 SVB 与 Identity harness | 四个组件，无 BOOM pipeline |
| AI/Debug/scripts/rollback/HierarchyGenerate.scala、hierarchy_test.cpp | P5-05/06/08/09 | 真实 L1+InclusiveCache+CacheCork+Controller/SCP；Figure4/迁移/accepted miss 的 actual-load scoreboard | 真实层次测试未执行；不覆盖 BOOM pipeline/MMIO/全部 victim/probe/WB 交错 |
| AI/Debug/scripts/rollback/identity_test.cpp | P3-15/P4-06，P5-09 | 生产 allocator 缩小至 4 bit，变量批量和永久停止检查 | 未执行；生产大宽度连接另由用户整核构建检查 |
| AI/Debug/scripts/rollback/recovery_test.cpp | P5-02/03/05/07/09 | SCP8、A7/A8、held response、重复/更早错误、连续 rollback、safe exact ACK、missing SCP、EVT32 容量停机 | 未运行 |
| AI/Debug/scripts/rollback/f0_test.cpp | P1-01，P5-04 | x0 garbage、only f0 mismatch、f31 terminal mismatch、held result/ACK | 未运行 |
| AI/Debug/scripts/rollback/svb_test.cpp | P5-01/02/05/09 | A7 保留、SPEC 后缀失效、WB_WAIT 迟到 ACK、full backpressure、同 Seq serial 选择 | 未运行 |
| AI/Debug/scripts/rollback/user_build.sh、source_manifest.py | P5-12 | 用户专用 SBT/Verilator build-only；五个 top；新目录；源码含 untracked 哈希；before/after 比较；不自动跑 simulator | Codex 未执行 build 脚本 |
| AI/Debug/scripts/rollback/static_check.py、render_taskboard.py | P0-03/07，P5-12/13 | 69/49 覆盖、依赖 DAG、状态/路径、MD/JSON 同步、Scala 括号、Python AST、shell/diff | 仅语法表层，不能替代 Scala typecheck/Chisel/功能验证 |
| AI/Design/05–09、AI/Debug/state/current_debug_state.md | P0-01..07，P5-12/13 | 任务/架构/变更/人工测试/实际完成与阻塞；旧 state 保留历史 | 没有把原审计或旧运行改为新实现证据 |

## 本次静态复核发现并修复的具体问题

- 恢复顺序改为 pin SCP → EVT publish → drain，解除失败 WaitSafe 的 drain-before-invalidate 循环。
- SVB 历史迁移改独立 archive receipt，避免用旧 ReleaseData 表示不真实的权限释放。
- ContextMemory 同拍 read/reclaim 优先 pin，restart/pin-release 同拍可回收，避免缺失或泄漏 SCP。
- DCache 的 CANCEL 以前被静默丢掉，会留下 STQ functional_inflight；现送回责任终态，并禁止产生数据 response。
- LSU reset 清 live_store_mask；取消 strict token 独立结算；同时发生 cache/uncache 完成使用扩位加法。
- G 改变后允许 stop 期间存活 prefix store 恢复冷行，否则 prefix drain 无法前进；mapped Current 再次检查 HistoryValid，拒绝迟到 discarded install。
- fresh SCP redirect 复位 FTQ 并禁止读取不存在的旧 FTQ entry；不触发 reset-vector 启动。
- active L2 MSHR/native peer 也接 EVT；没有通过伪造目录 INVALID/clients0 放弃 live coherence 义务。

## 静态验证边界

允许的检查由 static_check.py 执行，最终结果见 09。没有运行任何 SBT/Scala 编译、elaboration、RTL 生成、Verilator lint/build/simulation、testbench、故障注入或综合。CODE_READY 最大仅表示源码局部准备；整体仍为 INCOMPLETE。
