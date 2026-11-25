# Current: Test 统一公共运行环境 (2026-11-25)

公共运行环境的 17 个文件已直接移入 `Software/Test/{cfg,core,hw,stat}` 和 `htif.mk`，原独立运行环境目录已移除。EC-Test、GAPBS 的 Makefile 及五个有效回归脚本改用 Test 路径；Test 的 benchmark 分派机制保持不变。EC-Test → GAPBS → 默认 EC-Test 构建通过，两个 ELF 与迁移前逐字节相同，dump 和既有 HEX 匹配。未修改硬件、仿真器或 Verilator 构建规则。用户最后要求仅做简单移动合并、不要仿真，剩余仿真已停止，不再追加验证。

正式入口已恢复到 `chipyard/sims/verilator`。v1 fast/FST、Fault8 fast/debug、12.5 MHz History 和 Seq 重基的现有模型及构建树已复制并修正路径，默认四线程，HEX 已准备；普通 Make 运行不需要 `simroot`、`sim_dir`、`BREAK_SIM_PREREQ` 或初始化脚本。用户随后取消本轮完整仿真验收及硬件生成要求；尚在运行的压力和重复 FST 已停止，不作为通过证据。新增只读压力 Make 目标，保留原软件和全部硬件功能。日常命令以 [正式环境报告](../history/reports/verilator-formal-environment-20261125.md) 为准；下方为本日先前功能验收记录。

本轮目标为修复 MSIP 组合场景及后续前进性错误、验收 EC-Test，并交付日常和 FST 仿真入口。当前生产 RTL 与 `probe-publication` 模型对应。六个配置构建成功，七组组件通过。EC-Test ELF、反汇编和 HEX 已生成。 [根因及验收报告](../bugs/bug-palimpsest-arf-data-backpressure.md) · [S8 专项报告](../bugs/palimpsest-s8-injection.md) · [本轮产物](../../TMP/ec-test-20261125/probe-publication/)

- 正常 345597 周期、321.686 秒、97 PASS／0 FAIL。FST 同周期和结果，507.045 秒。Fault8 为 422873 周期、341.397 秒、126 PASS／1 次预期 Seq 8 FAIL。三条 Make 命令均实际退出 0。S8 波形确认 hart 4 一次翻位，SCP/RESTART PC 为 `0x80000964`。 [运行日志](../../TMP/ec-test-20261125/probe-publication/acceptance/) · [S8 波形](../../TMP/ec-test-20261125/probe-publication/acceptance/s8-compare.trace)
- 强制重基 677729 周期、593.563 秒、退出 0。六次物理 reset 后的新 Seq 1 分别通过。原第四次重基反例中，旧 STQ 2 NACK 已清 inflight，指针回退被随后跳过取消项的赋值覆盖。修改复用 `olderStoreNackForcesReplay`。 [强制重基日志](../../TMP/ec-test-20261125/probe-publication/PalimpsestSeqRebaseTestConfig/ec-rebase/) · [原 STQ 停点](../../TMP/ec-test-20261125/maintenance-drain/PalimpsestSeqRebaseTestConfig/ec-rebase-stq/)
- 12.5 MHz 的 EC-Test 压力在 1234316 周期、1013.127 秒退出 0，实测封口、占满 64 槽、重分配、回收和最终空表。冻结 16 轮 ELF 在 1162441 周期、930.117 秒退出 0，原严格计分通过 Seq 1 END/count 64、64/64、回到 48 个空槽且检查包前进、54 次 Checker PASS、最终全空及 checksum。25 MHz 同一冻结 ELF 在 759165 周期退出 0，其原严格计分因 END/count 16 保留失败，容量峰值 40/64。 [EC-Test 容量计分](../../TMP/ec-test-20261125/probe-publication/acceptance/12p5-ec-pressure.json) · [冻结严格计分](../../TMP/ec-test-20261125/probe-publication/acceptance/12p5-frozen-strict.json) · [25 MHz 严格结果](../../TMP/ec-test-20261125/probe-publication/acceptance/25-frozen-strict.log)
- L2 由 `hasData && CacheImage.valid` 决定哪些 C 拍等待 History 暂存。冻结 ELF 的两次 Checker 停点分别涉及无数据 ProbeAck 和无版本身份的 ProbeAckData。之后的 HTIF 停点来自两个不同组的 Probe 前驱依赖。仅当 History 唯一待发布行在另一组且等该组 drain 时，允许队头的安全前驱走原外写和 ACK。定向组件对照在旧版 944 周期失败，新版 589 周期通过。 [旧反例](../../TMP/ec-test-20261125/probe-publication/directed-c-staging.log) · [现有基线回归](../../TMP/ec-test-20261125/probe-publication/baseline-with-directed.run.log)
- 历史重基原判据通过，2085846 周期、1679.60 秒、23 次物理 reset 和 23 个新 Seq 1 PASS。Sv39 原判据通过，正常／Fault8 分别 547623／589140 周期，物理读次数 16／18，其中 Fault8 的 2 次由回滚废弃，两边均有 16 次存活提交。历史 IRQ 和 AMO 正常／Fault18 均退出 0，严格计分通过各 16 轮及 journal 重放前仅一次实际设备 TL A。 [历史重基判据](../../TMP/ec-test-20261125/probe-publication/PalimpsestSeqRebaseTestConfig/historical-rebase/oracle.log) · [Sv39 判据](../../TMP/ec-test-20261125/probe-publication/sv39-driver.log) · [设备判据](../../TMP/ec-test-20261125/probe-publication/acceptance/historical-io.log)
- 17:43 CST 整核实验收齐。正常与 Fault8 的只读观测各确认四次物理 MSIP set/clear、四次精确中断和匹配 xRET、四次设备 AMO 及读回，联合计分退出 0。本轮整核、组件与计分均已结束。日常、FST、Fault8 和 12.5 MHz 压力命令已写入验收报告。 [联合计分](../../TMP/ec-test-20261125/probe-publication/acceptance/ec-observer.json) · [运行汇总](../../TMP/ec-test-20261125/probe-publication/make-and-regression-driver.log) · [运行命令](../bugs/bug-palimpsest-arf-data-backpressure.md#运行命令)
- 下方 69 项记录属于 11 月 24 日封存基线。当前测试未进行物理布局或时序签核。12.5 MHz 严格通过的证据覆盖实际触发的容量与前进性边界。

---

# 单主核功能验收完成，69项VERIFIED；物理签核独立 (2026-11-24)

当前 **69 VERIFIED、0 IN_PROGRESS、0 CODE_READY**。最终来源复核和12个完整程序/31负例已通过，P2-07/P4-10/P4-13/P5-10真正关闭；P4-12已完成新Scheduler来源完整复验。旧69项提前声明仍为superseded，原FAIL不改写。

- 当前5配置Scala/Chisel/LowFIR/CheckCombLoops/SV/C++模型与observer全部0。12完整程序raw/oracle0：normal IRQ/trap/Sv39/output/AMO、Fault8 trap/Sv39、Fault18 IRQ/output/AMO、Fault40Seq41、25MHzHistory压力。
- 严格联合 `grantack_preemption_system_acceptance/result.json` PASS。normal/Fault18各16set/clear/精确MSIP trap/匹配MEPC xRET；恢复与未安全设备效果交叠时IRQ阻止。IRQ14负例全拒绝。
- CLINT写16/回读16、AMO旧值16/回读16，Fault18原效果到journal重放只有1次设备A；Fault40Seq41真实8reset/8新Seq1 PASS/48设备读，9负例拒绝。Sv39 normal16物理/16提交，Fault8含2次恢复废弃共18物理、存活16。
- 最终满History完整程序：Seq1真实seal/END/count64，tick255884实际64/64，269708回收48空槽，后续143个Checker PASS，最终free64/checksum974ea63763416da0，8负例拒绝。
- 本轮最终RTL修复：IOMSHR已有live owner并入effectPending，消除设备A至D建journal前的MSIP中断空窗；Scheduler仅含E且无数据/目录/park操作的调度可越过同组C/BC抢占，解除C→History→外层E循环。两项均0新寄存器/队列/FSM。原seal回执/最小scratch shadow RMW修复保留。
- 原normal IRQ line0x80032f80、Seq0/gen4的C首末拍仍0xfe115/0xfe127，新源码D0xfe20d匹配ReleaseAck，完整程序退出。有效协议fixture含真实Main Acquire T、SVB3、C7/SW3及peer TtoN，旧1/新0；早期缺权限fixture不作为最终证据。生产Hierarchy、4发布/压力组件及当前整核全部通过。
- 来源核对 `final_review_current_scheduler/result.json`：69项当前文件、5模型、12完整激励、计分器和报告哈希通过；三主要目标1083份SV逐字节不变，仅Scheduler.sv变化。关闭记录 `final_closure_current_scheduler.json`，长期状态见 `AI/Design/SingleCore_RTL_Baseline/System_Acceptance.json`。
- 用户要求先RTL/功能仿真，暂不推进比特流与时序仿真。辅助物理观察已独立冻结：`final_physical_observation_20261124/observation.json`。Scheduler2way5ns OOC WNS-10.841→-11.019ns均FAIL；完整ChipTop在观察时尚无最终报告、来源早于owner/Scheduler增量。无完整Core布局布线/端口延时/物理CDC签核，不宣称全面签核。

最终功能基线已由guarded `freeze_final_baseline.py`建立，9296份文件均从归档独立解压读取并核验哈希通过。位置与SHA256见 `final_freeze_location.json`；最终文档/构建包装工具补充包与正式完整回执见 `AI/Design/SingleCore_RTL_Baseline/Functional_Baseline_Archive.json`。功能完成、物理签核未完成。

---

# Superseded provisional closure (not final acceptance)

# Current: EC 单核功能闭环完成，物理签核独立保留 (2026-11-24)

当前功能任务状态为 **69 VERIFIED、0 CODE_READY、0 IN_PROGRESS**。五项最后任务已在当前生产 `core.scala` / `CSR.scala` 来源上完成整核动态验收；物理综合/布局布线/完整Core STA 仍单独标记，不能把功能闭环描述为全芯片物理签核。

- 生产 RTL 最终两项最小修正已合入：容量保持在 `producer_seal_ready` 回执前不释放；MSCRATCH/SSCRATCH 影子 W/S/C 使用本包 CPS shadow 作为读改写旧值。两项均为 0 新寄存器、0 新队列、0 新 FSM。精确 before/after、源码哈希和测试理由见 `AI/TMP/singlecore_function_closure_20261123/capacity_scratch_production_integration/result.json`。
- 当前来源 normal/Fault8/Fault18 三目标已通过 Scala/Chisel/FIRRTL、组合环检查、firtool RTL 生成和 C++ 模型构建。来源关系见 `integrated_capacity_scratch_candidate/effective_production_source_relation.json` 与 `firrtl_validation.json`。
- 最终整核组合严格验收在 `final_integrated_closure/`：normal 5 profiles（IRQ、Sv39、trap_io、CLINT output、CLINT AMO）、Fault8 2 profiles（Sv39、trap_io）、Fault18 3 profiles（IRQ、CLINT output、CLINT AMO）全部 raw exit 0、架构 oracle 0。trap、Sv39、output、AMO、IRQ 五个严格 scoreboard 全部 PASS。
- IRQ 证据要求 16 次 MSIP set、16 次 handler clear、16 次实际 trap；Fault18 在 recovery stop 和未结效果交叠期间保持 IRQ 阻止，设备效果只发射一次。计分器已修正为按 live stop/I/O boundary 判定；`journalValid` 是已提交效果的保留重放记录，不能单独作为未完成效果。
- History/容量最终验收已通过：原 25 MHz 同 ELF 的旧 first bad 消失，Seq1 真实 END、最终 count=64、Seq1/Seq2 及后续结果 PASS；实际 `freeCount=0`（64/64）后回收至 48 空槽，后续 Seq82 仍前进，最终完整程序 oracle PASS，checksum=`974ea63763416da0`。证据 `capacity_seal_fastlink/history_full_observed.json`、`run.exit`、`oracle.exit`。
- Fault40+Seq32 独立完整验收保留并复核：8 次真实物理 reset、8 个新 Seq1 PASS、48 次设备读、9 个负例全拒绝，checksum=`75f3f507c3419640`。证据 `io_rebase_complete_closure.json` 和 `io_rebase_complete_negative_retry/results.json`。
- CSR 组件最终长期 runner 覆盖两个 scratch、normal/priv W/S/C 共 12 组合、management 隔离、SSCRATCH ECP 和物理 MPRV；结果 PASS。完整组合回归进一步证明 CSR、中断、Sv39、精确异常、I/O 屏障和恢复一致。
- 当前功能固化文件已重新生成：任务板、Feature/Verification Matrix、Function Closure Audit、implementation manifest、状态机/接口/不变量/决策文档均与 69 VERIFIED 状态同步。最终机器可读汇总为 `AI/TMP/singlecore_function_closure_20261123/final_functional_closure.json`。
- 物理实现状态独立记录在 `physical_signoff_status.json`：既有 GHM OOC 综合结果保留（98,895 LUT、336,652 FF、内部 5 ns WNS +1.448 ns）；带 memory models 的完整 ChipTop 尝试完成 RTL elaboration，但未产出最终 utilization/timing/CDC 报告，未布局布线，也未完成 AsyncQueue data CE/Gray 偏斜签核。因此物理 signoff 仍未完成。

---

# Historical milestone: 最终owner/CDC组合恢复里程碑通过 (2026-11-23)

69项逐项盘点、原定义和状态变更见 `AI/Design/SingleCore_RTL_Baseline/Function_Closure_Audit.json/.md`、任务板及manifest。当前 **64 VERIFIED、5 IN_PROGRESS、0 CODE_READY**。本批证据根目录 `AI/TMP/singlecore_function_closure_20261123/`。

- 最终组合整核 `integrated_owner_seq_candidate_wired/` 的 Scala/Chisel/FIRRTL、C++构建、完整异常/MMIO程序与严格oracle全部0；23次真实物理重基均有新Seq1 PASS，checksum=75f3f507c3419640。GHM/DCache候选与合入生产逐字节一致，通用同步器只有物理属性差异且状态转移相同；实际firtool采用综合前XDC。运行输入哈希已复核。
- `recovery_integration_closure.json`逐项关闭原P2-05/P2-08/P2-10、P3-04/P3-05/P3-08/P3-09/P3-11/P3-12/P3-13/P3-15、P4-01/P4-02/P4-03/P4-05。依据最终整核与生产Hierarchy/SeqTransport、真实0xffff slot完整终态、32位CurGen真实维护证书、四同址发布/回收和当前完整C/E配对；没有重构已通过功能。
- 既有17项VERIFIED保留：Seq32跨域生命周期、基线发布/回收、I/O效果屏障、有限owner及版本生命周期；各closure JSON保留原理由和来源。
- `reviewed_control_milestone/result.json`五项严格计分全0、9个完整程序raw0，正常/Fault8 trap_io、原Sv39物理+提交配对、Seq16、CLINT16写/16回读与uncached AMO16旧值/16回读均PASS。原`control_chain_fullcore.driver.exit=1`保留，旧Sv39错误物理次数oracle及停止冗余运行已单独解释。Sv39 fault18次物理读取含2次恢复废弃，存活16次且废弃值也检查；四负例拒绝。
- 生产`final_owner_components` SeqTransport/Hierarchy来源前后相同并PASS。`production_slot_epoch_boundary`四次真实同组替换及完整MSHR安装/终态PASS；原0xffff分配1/安装0反例FAIL保留。`production_generation_boundary`只加速32位reset标签，真实外写/ACK阻止提前清标签，真实证书后归零/空上下文/再次rollback并读对存活字节PASS，未伪造维护ACK。
- `baseline_publication_four_current`四真实生产L2联合用例PASS，逐外写beat检查：同址3/5/7、SW扫描、迟到C6、可信Put、held ACK3下安全9合并、EVT5..8与外写owner并发，最终查询无泄漏。
- 生产GHM同top U250综合exit0：原4个组合前置CDC-10和4个ACK SRL CDC-13消失，226项CDC-3；98,895 LUT/336,652 FF，5ns内部综合WNS+1.448ns。1742项AsyncQueue数据CE warning仍未签核；未布局布线、无接口外延时，不能宣称完整Core物理CDC/面积/时序达标。

当前新增必要验证（不调整watchdog、不放宽计分、不删除TMP）：

1. `concurrency_fullcore/`已完成三配置Scala/Chisel/FIRRTL降级、全部普通C++单元；三个完整模拟器构建现已exit0，已开始同一完整程序。已真实观察FAIL8/FAIL24两次同SCP PC恢复，但完整程序尚未退出；Fault40效果重放、推迟至Seq45以及首次实际reset已发生。已经启动当前生产normal、两次真实比较器FAIL8/FAIL24、Fault40+Seq41三配置整核构建和完整程序。新长期入口`concurrency_regression.py`、`concurrency_scoreboard.py`、只读`concurrency_observer.cc`。需要真实退出与全部oracle，350000周期旧首段不替代完整验收。
2. 双FAIL仅扩展既有f0注入参数，默认空不生成额外状态；每个选定Seq只注入一次，未修改PASS/result或Controller。`concurrency_components`首次F0/双注入均PASS，但CheckerRecovery夹具新增seq端口漏接导致初始化失败，已接固定Seq8，原driver1保留，`concurrency_components_retry`重跑中。后续必须回收当前来源PASS。
3. 剩余6个IN_PROGRESS：P2-07/P4-10真实中断与未结I/O/恢复交叠；P3-14同一完整程序两次独立FAIL；P4-12完整Core实际History满资源前进性；P4-13/P5-10完整Fault40+Seq41及上述压力/中断。P5-07 CODE_READY仍按原定义与已有证据逐项完成验收，不能一律当作功能未实现或一律提升。

当前静态来源/69任务检查 `recovery_closed_retry.static.log` PASS；原漏同步feature状态的静态失败保留，已同步49 features和summary。双FAIL组件retry已实际PASS且来源前后相同。中断候选无注入模型也有FAIL：first_divergence/normal_retry在tick85652、hart1、Seq23观察所有32个整数/FP相等而CSR idx3(mscratch) expected0/checker栈地址不同，尚需定位更上游写入时刻；P2-07/P4-10保持未完成。完整History普通1024行探针仅占用2槽，未覆盖满表，另启动真实同组store burst，不强制owner。中断原normal最终pipeline hang/exit1保留，Fault18虽然完整exit0且16轮oracle成功，但额外非注入FAIL存在，仍不通过严格验收。CSR_minimal.scala已用长期真实CSRFile runner验证原反例消失、normal/priv写shadow/management隔离PASS；生产尚未合入。独立normal/Fault18候选完整Core已生成，后端构建及IRQ/旧trap/Sv39/CLINT/AMO回归在途。实际同L2 set压力已用96条stride65536、DRAM0x81000000显式初始化绕开BSS空洞，尚未满；额外25MHz慢Checker配置已真实生成，复用全部原协议，无强制owner/ACK。后续回收三配置构建与候选完整Core，继续真实满History验收，不建立新版本号作为目标。

---

# Historical: V10 已关闭包 owner 修复整核回归中，V9 整核 FIRRTL 通过 (2026-11-23)

证据根目录 AI/TMP/singlecore_checker_20261122_082540/。用户要求逐项稳步推进。
69 项仍为 34 CODE_READY、32 IN_PROGRESS、3 VERIFIED，整体未完成。

- V7 实时 restart 检查修复迟到Probe反例，15组件PASS；整核FIRRTL因最终IFU
  redirect→snapshot→RSU busy→quiesced→restart反馈FAIL。V8只拆redirect仍因
  SCP discard→capture.ready→snapshot→RSU busy反馈FAIL，两份正常driver.exit2
  均保留；V7冗余fault/seq构建主动停止exit143。
- V9复用并前移原snapshot_rsu_prev，R_IC以recoveryStop禁止新snapshot，RSU
  仅观察既有工作排空，cache/LSU/Checker继续实时门控。恢复原snapshot guard，
  无新增寄存器/队列/FSM。真实正常整核Scala/Chisel/FIRRTL已PASS，原两条环
  消失；firrtl_validation.json保存低FIR及原来源哈希。V9后续firtool/C++构建
  主动停止exit143，完整动态回归统一交V10，不当作整核运行PASS。
- 原V6 Sv39 Fault8根因已确认。sv39_capacity_owner_probe_v6/在tick559795
  记录producer_open=0、protected=0、R_IC=presch、retained activeSeq=35，迟到
  L2请求Seq35却启动capacityStart。次拍capacityClosing锁住，563384原请求退出
  后仍等不存在的successor而永久保持退休。原watchdog与575000周期诊断exit2
  保留。完整信号链在capacity_closed_owner_candidate_v10/design.json。
- V10在barrierCloseForActivePackage加入已有traffic_package_open，一位组合
  条件，无新状态；迟到请求仍走R_IC原barrierAlreadyClosed ACK。三配置整核
  normal/fault/seq_rtl_v10/已启动，run_fullcore_v10.py安排同一trap_io ELF及
  原Sv39正常/Fault8完整程序、16次实际译址读和严格配对；尚无V10通过结论。
- rtl_regression_v8/的15项组件实际PASS。固定14个FIR哈希及全部CPP/fixture
  不变；生成之后6个已知Core/config/整核测试文件变化导致原source-cmp exit1，
  保留原失败，独立reviewed.exit0。组件不含Core，不能证明V9/V10生产改动。
- V6 CLINT写正常800769、Fault18 939211周期退出，完整严格配对和同次effects
  联合计分PASS：唯一FAIL18、同PC0x800005cc恢复、Seq21直接重放ACK且无第二
  次A。实际mtimecmp 16写/16回读值及顺序正确，128ecall和架构oracle通过。
  长期compact-mmio-output/Fault18/--require-output已固化，重编loadmem与候选
  完全一致；长期计分PASS并拒绝4个后续轮次损坏负例。新RTL入口未完整重跑，
  uncached AMO整核仍缺。
- V6 Seq16异常/MMIO完整程序23次重基PASS。Fault40长期入口完整联合验收PASS。
  Fault40+Seq41首次交叠计分PASS，journal未结不预留，Seq43重放PASS及释放后
  Seq45归零、新Seq1 PASS；350000周期诊断exit2只证明首段，非组合完整程序。
- 静态69项检查PASS，不代替整核动态验收。历史U250 5ns/WNS=-9.608ns为旧
  Stage3 FAIL，不代表当前整核面积/时序。

下一步先回收V10生成来源/FIRRTL/编译，再按原Sv39 first bad及完整oracle验收，
并继续uncached AMO、真实I-TLB/旧物理响应及其他多owner未完成项。
新独立归档AI/TMP/palimpsest_checkpoint_20261123_103556_v10_owner_and_rsu/
已完成：162份文件校验、80个源码覆盖文件，完整源哈希
cc5dcf1327cefc22c33713ea35fc98493af06494dac5fddbb4b9649daf675825。
归档complete=false，旧失败与在途边界保留。V10三配置Chisel FIR与输入均匹配
sources_v10.json，保护在v10_generation_checkpoint.json；生成不等于FIRRTL或运行。

---

# Historical: V9 复用既有 RSU 排空寄存器，CLINT 写已固化；Sv39 capacity owner 取证中 (2026-11-23)

证据根目录 AI/TMP/singlecore_checker_20261122_082540/。用户要求逐项稳步推进。
69 项仍为 34 CODE_READY、32 IN_PROGRESS、3 VERIFIED，整体未完成。

- V7 实时 restart 门控的 15 项组件全部实际通过。完整 Core 的 FIRRTL 失败：
  restart→最终 IFU redirect→snapshot→RSU busy→quiesced→restart 成环。正常
  driver.exit2，冗余 Fault8/Seq16 生成已停止且exit143，来源和原失败保留。
- V8 仅将snapshot guard改为已注册的普通redirect来源，实际FIRRTL仍失败：
  restart→SCP discard→capture.ready→snapshot→RSU busy→restart，driver.exit2。
  该修订不充分，不得宣称PASS。V8原FIR及来源独立保护；rtl_regression_v8/
  已生成14个FIR并在运行15项组件。前后来源会因V9 Core和长期测试修改而不同，
  原source-cmp失败保留；组件不含Core，新生产Core仍须真实整核验证。
- V9撤回V8的redirect-only修改，恢复原snapshot guard，前移/复用原先已有的
  snapshot_rsu_prev。在recoveryStop禁止新snapshot的前提下，用该寄存器证明
  已接受RSU capture/merge工作已结束。cache/LSU/Checker继续实时重查，故新
  Probe仍撤回restart。没有新寄存器/队列/FSM/接口。根因及差异在
  restart_rsu_drain_candidate_v9/，完整来源sources_v9.json。normal_rtl_v9/
  正编译生成；尚无V9整核通过结论。Bug见restart-snapshot-loop长期记录。
- V6 CLINT写正常800769、Fault18 939211周期退出，完整严格配对和同次effects
  计分PASS：唯一FAIL18，PC0x800005cc恢复，Seq21直接重放ACK、无第二次A。
  实际mtimecmp共16写/16回读，全部操作数/值/顺序正确，128ecall和架构oracle
  通过。长期compact-mmio-output/Fault18/--require-output已固化；重新编译后的
  loaded sections及loadmem与候选逐字节一致。长期计分重判PASS，4个后续轮次
  负例均拒绝。新RTL长期入口尚未运行，uncached AMO整核仍缺。
- V6 Fault40+Seq41首次交叠计分PASS：Seq41不在未结journal时预留，Seq43重放
  PASS、journal释放后才以Seq45物理reset，同PC重启、新Seq1 PASS。
  extended/ run.exit2是350000周期诊断上限，仅计分scope首段，非完整程序。
- Sv39原V6正常通过；Fault8完成16次映射读后HTIF fromhost轮询watchdog仍FAIL。
  sv39_watchdog_probe_v6/确认tick559800..619900 capacityBoundaryHold=1，其他
  恢复/重基/I/O/RSU stall和缓存均空闲，R_IC=presch、ROB head固定。原模型的
  sv39_capacity_owner_probe_v6/正在记录capacity启动/包owner/activeSeq转变，
  未确认上游触发之前不patch。该运行575000周期诊断上限，使用原V6库。
- V6长期Fault40完整联合验收与Seq16异常/MMIO的23次重基完整程序均PASS。
  历史U250 5ns/WNS=-9.608ns为旧Stage3 FAIL，不代表当前整核时序。

下一步优先回收V9整核FIRRTL，再回收Sv39 first bad；确认后才动下一处RTL。
本轮新冻结归档仍待生成；旧v6_io_and_tracked_c归档早于本轮结果。

---

# Historical: V8 消除整核 restart/snapshot 组合反馈，CLINT 写联合验收通过 (2026-11-23)

证据根目录 AI/TMP/singlecore_checker_20261122_082540/。用户要求逐项稳步推进。
69 项仍为 34 CODE_READY、32 IN_PROGRESS、3 VERIFIED，整体未完成。

- V7 的 15 项组件实际全部通过，来源前后一致；真实 L1 满 C/BASE 外写 ACK/
  FAIL8→FAIL7 的原 restart 反例消失，组件撤回就绪也通过。外层 zsh 只读 status
  收尾错误保留 driver.exit1，独立 reviewed.exit0。不能当作整核已通过。
- V7 正常整核 FIRRTL CheckCombLoops 失败，driver.exit2。最终 IFU redirect→
  snapshot→RSU busy→实时 quiesced→restart→IFU redirect 成环。三份已生成 FIR
  与来源清单保护在 v7_generation_checkpoint.json。Fault8/Seq16 冗余构建停止，
  各 exit143，停止清单保留；不得当作设计成功或运行结果。
- V8 只改 Core snapshot guard，直接读取原已注册 arch_redirect_valid 与 B2
  mispredict，正常准入等价；恢复期间仍由 recoveryStop 禁止 snapshot。保留
  Controller 实时 owner/SCP 检查，无新增硬件状态。根因及唯一生产差异在
  restart_redirect_candidate_v8/；sources_v8.json。normal_rtl_v8/ 正生成与构建，
  rtl_regression_v8/ 等待同一串行 SBT 锁后执行15组件，尚无V8通过结论。
- V6 CLINT 写正常800769周期、Fault18 939211周期退出，完整严格配对和同次
  effects联合计分均PASS。Seq18在PC0x800005cc的首个写效果后FAIL，Seq21直接
  journal ACK重放且无第二次A。实际mtimecmp为16写/16回读，全部操作数与顺序
  正确，128ecall、内存、FP、CSR oracle通过。证据 mmio_output_candidate_v6/
  full/fault18/full_effect_report.json 与 device_rounds_report.json；长期profile
  尚待固化，uncached AMO整核仍缺。
- V6 Fault40+Seq41首次交叠链计分PASS：tick123963分配Seq41不预留，journal
  释放125148后才于125156预留Seq45，227899物理reset，同PC重启且新Seq1 PASS。
  extended/ run.exit2为350000周期诊断上限，scoreboard.exit0仅适用首次交叠，
  不能记组合完整程序PASS。原180000周期缺reset的失败记录保留。
- Sv39原V6正常通过；Fault8完成16次映射读后HTIF fromhost轮询watchdog仍FAIL。
  sv39_watchdog_probe_v6/ 在tick559800..619900确认capacityBoundaryHold=1，
  恢复/重基/I/O/RSU stall均0且缓存最后空闲；R_IC=presch、ROB head固定。
  原模型已链接更窄的 sv39_capacity_owner_probe_v6/，记录capacity启动、包owner、
  activeSeq和封口请求的转变。上游触发尚未证明，不先patch。
- V6长期Fault40完整联合验收PASS；Seq16异常/MMIO完整退出及23次重基PASS，
  原200万周期timeout保留。当前回归不能用旧V6证据替代V8。

下一步先确认V8整核无组合环，再回收capacity owner探针证明Sv39 first bad；
固化CLINT写长期profile，并继续真实译址/旧响应、多owner和uncached AMO缺口。
历史U250 5ns/WNS=-9.608ns为旧Stage3 FAIL，不代表当前整核时序。
本轮尚未生成新冻结归档；旧v6_io_and_tracked_c归档早于上述结果。

---

# Historical: V7 重启实时排空检查回归，V6 I/O 与 Seq16 结果已回收 (2026-11-23)

证据根目录 AI/TMP/singlecore_checker_20261122_082540/。用户要求逐项稳步推进。
任务仍为 34 CODE_READY、32 IN_PROGRESS、3 VERIFIED，整体未完成。

- V6 长期 Fault40 入口与原 O1 联合观察均 PASS：929646 周期退出，唯一 FAIL40，
  同 PC 恢复，Seq43 重放原值0x26b，设备 A 握手一次。完整程序与设备信号同次判定。
- Seq16 的两份 200 万周期运行均 timeout，保留 run.exit2 和计分失败。使用同一
  模型和 ELF 增加到300万预算后，2061735周期完整 PASS；23次重基后均有 Seq1
  PASS，128ecall、MMIO、内存、FP及CSR全部正确。没有修改硬件 watchdog。
- V6 真实 L1 满 C、Pending7、同址 BASE 外写 ACK 与 FAIL8→FAIL7 的新反例，
  在重查 Probe 到达时触发 restart assertion。旧 Controller 在 cycle981
  收到排空，982接受新 Probe，984却仍发 restart。SCP始终有效。
  独立组件反例 cycle152 也失败。来源在 hierarchy_real_tracked_c_trace_v6/
  和 recovery_late_owner_before_v7_retry/，根因已记录于 bugs/。
- V7 的 PalimpsestRollbackController 在 restart.valid 重新检查当前 quiesced
  和 checkpointReady。等待新owner期间保持stop和SCP，不增加硬件状态。长期
  Recovery 和 Hierarchy 已增加反例。rtl_regression_v7/ 的15项回归正在执行，
  normal/fault/seq_rtl_v7/ 正在生成/构建并执行同一异常MMIO程序。
- Sv39正常676834周期成功退出。Fault8在同PC0x800004bc恢复后完成16次真实映射
  读，并输出SV39_RESULT；随后在HTIF fromhost轮询期间触发Main watchdog，
  run.exit1。不得记为完整PASS。sv39_watchdog_probe_v6/ 正使用旧生成库观察
  阻塞信号，未经确认不修改译址或HTIF逻辑。
- CLINT写正常运行800769周期成功退出。真实效果包号为Seq18，fault18_build/
  已完成，full/fault18/ 正运行并观察同PC写重放和设备握手次数。纯写journal保存
  ACK、不保存读数，计分器相应以journalWord=0而非陈旧grant_word判断原写终态。
- Fault40+Seq41原180000周期诊断只证明journal未结时分配Seq41不预留重基；
  journal释放后Seq45才成为重基目标。原计分缺reset，失败保留。extended/
  用同一原模型增加至350000周期，继续验收第一次真正归零和新Seq1 PASS。

下一步先回收V7组件及真实L1反例，然后按Sv39停滞、外设写、重基与未结效果顺序
推进。旧I-TLB/物理迟到响应整核组合、uncached AMO仍未完整验收。
历史U250 5ns/WNS=-9.608ns仍为FAIL，不代表V7整核时序。

---

# Historical: V6 Fault40 整核 I/O 效果联合验收通过 (2026-11-22)

证据根目录 `AI/TMP/singlecore_checker_20261122_082540/`。
用户要求逐项稳步推进。69项仍为34 CODE_READY、32 IN_PROGRESS、3 VERIFIED，整体未完成。

- `fault40_io_ledger_o1_v6/trap_io/` 的 run.exit 与 scoreboard.exit 均为0。
  同一次完整 Fault40 模拟在929646周期成功退出。唯一FAIL40、同PC0x80000858
  恢复、Seq43重放0x26b及一次设备A握手均由日志证明。128次ecall与内存/FP/CSR
  严格配对通过。联合判定在 `full_effect_report.json`，长期配置展开与候选的
  Chisel FIR 一致，`fault40_longterm_v6/` 正独立复跑长期测试入口。
- Seq16的两个异常/MMIO运行中，独立模型与原优化模型分别已观测至少22次和15次
  完成重基，无FAIL或CANCELLED，完整oracle仍待退出。临时Fault40+Seq41配置的
  只读探针会记录同一次运行的SCP分配、effectPending、rebasePending和缓存归零。
- Sv39 正常/Fault8 同一 ELF 已经观察到实际两页交替；故障版在 Seq8 恢复后
  继续读到两页对应的数据。最终检查要求16次真实物理读、同PC恢复和完整程序
  严格配对。真实I-TLB、旧物理响应与恢复同拍仍待单独覆盖。
- 新的 CLINT 写测试使用 hart0 的 mtimecmp，写入远大于观测期间 mtime 的值，
  并检查每轮读回。正常运行与 Fault40 第一段定位已经启动，将以实际写入包号
  确定故障配置。uncached AMO 现仍只有组件证据。

## V6 本阶段先前记录

- V6 `postReady := io.lsu.ioIssueReady` 一处生产接线修改保持。15项组件同次通过，
  原优化模型compact正常/Fault8严格配对、Seq16两次重基也通过。
- 本轮回收 `v6_fast_model/fault/trap_io/`：967701周期成功退出，128ecall、MMIO、
  内存/FP/CSR oracle均正确。正常808703周期、353包全PASS；故障运行353包PASS、
  唯一FAIL8、无CANCELLED，仅一次EVT/restore/restart。严格配对在
  `v6_trap_io_pair_review/`，scoreboard.exit0。两个大型C++单元O0，来源与原O1运行分开。
- `fullcore_scoreboard.py`明确拒绝额外FAIL/CANCELLED/EVT/restore/restart，并核对
  Seq重基的EVT→restore→compact→reset→同PC restart→Seq1 PASS完整顺序。
  原V6 compact正常/Fault8及Seq16日志重判通过；`strict_scoreboard_v6/negative/`
  用真实事件日志构造11种负例，全部拒绝。旧计分器和前后哈希已保留。
- `fault40_fast_model_v6_observed/fault40/trap_io/`仍执行：首次CLINT效果后FAIL40，
  同PC0x80000858恢复，Seq43 journal重放已出现，尚无完整程序退出/配对结果。
  旧观察器混用stdout导致日志交错，不能据其缺字段记录证明raw word或设备次数。
- 已固化 `io_effect_observer.cc`、`build_io_observer.py`、`io_effect_scoreboard.py`。
  观察器只读每次eval后的IOMSHR寄存器，独立流并逐事件flush，不写硬件状态。
  `fault40_io_ledger_v6/focused/`使用同一生成库，180000周期仅作诊断信号证据。
  已见123951真实A握手→123955存journal_word=0x26b→124156 replay标志→
  124952 Seq43直接idle→response，grant_word仍0x26b，无第二次A；短探针已按180000周期诊断上限exit2，信号链计分exit0，结果在focused/effect_chain.json；5个损坏/错误信号负例全部被拒绝。
- 原Fault40 O1编译exit0，driver只因新增5个验证脚本的source-cmp失败。
  复核器初次核对时发现helper在build-end前后有已知修订，拒绝继续；原失败保留。
  retry核验旧helper可重建哈希、固定FIR及精确脚本差异后，用原O1库链接同一只读
  观察器。`fault40_io_ledger_o1_v6/trap_io/`正在运行，完整结束后自动严格配对和效果计分。
- Seq16完整trap_io仍在运行，有持续重基和新包PASS，但尚未完整oracle；
  原O1三配置trap_io独立运行也未回收。不得以部分重基或正常/Fault8通过代替。
- 新脚本只改验证输入。硬件/FIR仍是原V6；后续原构建source-cmp若失败保留原记录。
  当前脚本来源另存 `sources_v6_io_validation.json`，旧清单和归档不覆盖。

新增 `tracked_c_longterm_reused_v6/` 与 `tracked_c_pressure_v6/`：长期Baseline
复用原fullC流程，增加Seq8 tracked Probe数据、Pending7、BASE外写ACK背压和
FAIL8→FAIL7组合。两个EVT安装期间两拍C队列保持满；重查的第二次BtoN完成后
返回BASE，逐accepted外写beat检查八个字，SW跨8之后仍无dead字节发布。
最终Baseline全套与共享agent的Pressure重编回归均exit0。原候选include宏冲突
编译失败、漏回第二次Probe导致的激励超时均保留；均不属于RTL缺陷。
此项仅真实L2+协议host，不关闭真实L1多层同时迁移。

原O1正常和Fault8的异常MMIO严格配对已PASS，
见`v6_trap_io_o1_pair.log/.exit`。正常O1与独立模型的970个PALIMPSEST事件相同。
`sv39_workload_candidate_v6/`已编译并用原正常/Fault8模型运行。该激励通过真实
三层页表和MPRV模式读验证两页重映射，每轮修改PTE并执行SFENCE，使用同一ELF。
此阶段正在确认真实译址，仍缺 I-TLB 与物理旧响应在回滚时在途的联合证据。历史U250 5ns WNS=-9.608ns仍为FAIL，非V6整核时序结论。

---

# Historical: V6 I/O后置封口最小修复，首轮回归 (2026-11-22)

证据根目录 `AI/TMP/singlecore_checker_20261122_082540/`。用户要求逐项稳步推进。
本轮先处理V3/V4异常/I/O组合的额外CANCELLED恢复，不改watchdog和严格计分。
69项状态仍为34 CODE_READY、32 IN_PROGRESS、3 VERIFIED，整体未完成。

- `trap_io_store_owner_probe_v4/` 已结束：诊断上限126000、run.exit2，非验收。
  MMIO123959退休后，唯一STQ2为年轻未提交store，PC=0x800005c4；head与commit_head
  都为2，无functional inflight。DCache ordered于123957恢复1。全STQ非空导致
  fencei_rdy持续0，closeAfter与retirementHold互相等待，后续无ECP/seal，Checker
  package_progress_timeout。根因链和信号在selected_evidence.json，长期根因记录已更新。
- `trap_io_rsu_phase_probe_v4/`已结束，逐eval观察确认RSU118820已空闲，
  snapshot_rsu_prev118821降0，此后保持0。旧首eval探针漏掉下降沿，不能用其末值
  断言RSU等待；新证据排除第二条owner阻塞，不扩大生产修改。诊断exit2非验收。
- V6仅将Core的postReady改用已有LSU ioIssueReady，等待已提交前缀、DCache ordered、
  HellaCache idle；不等年轻未提交STQ。不新增状态、寄存器、队列或FSM。实际修改及
  前后哈希在io_post_boundary_candidate_v6/，当前源码清单sources_v6.json。
- `rtl_regression_v6/`同一次长期15项全PASS、driver exit0、前后清单一致，`run_fullcore_v6.py`构建正常/Fault8/Seq16
  并执行compact和同一compact-trap-io，尚无V6整核PASS。IoBoundary直接激励不能
  证明Core接线，本项必须等真实反例及严格配对/重基计分通过。
- 在V6修改前核验三份V5 Chisel FIR和输入哈希，新增v5_pre_v6_generation_checkpoint.json。
  V5三配置仍构建，来源比较因后续V6修改可能失败，原失败保留。
  run_reviewed_v5_frozen.py等待构建完成，核验原FIR、原清单与唯一已知V6差异后才运行，
  结果单独写reviewed_v5_fullcore_frozen/。不能混作V6验收。

`hierarchy_longterm_v6/`新增两种Pending历史+在途多拍外写+FAIL8/更早FAIL7
联合场景，全套长期Hierarchy通过，build/run exit0、逐accepted外写beat及邻字检查。
只改长期C++激励，差异在v6_test_only_changes.json，sources_v6_stimulus.json；
原V6组件和FIR保留旧激励哈希。原V6整核build的末尾source-cmp预计因该测试变化
返回1，保留原失败；run_reviewed_v6_frozen.py核验固定FIR及唯一测试差异后运行。

旧V5独立复核已回收Fault8 compact和Seq16 compact，模拟器与计分器均exit0；
Seq16真实两次reset→Restart→Seq1 PASS。正常compact和异常/I/O组合仍在运行。
V5原构建source-cmp exit1保留，独立来源见reviewed_v5_fullcore_frozen/*/provenance.json。

V6独立O0大型文件模型三配置已开始trap_io；正常Seq0x28及后续CLINT边界
Seq0x29..0x2d均PASS，无取消/Restart（部分观测，尚非完整验收）。旧first bad
局部已消失，证据v6_io_old_firstbad_review.json。V5正常/Fault8 compact独立
严格配对已PASS，见v5_compact_pair_review/。

相邻覆盖：`fault40_config_v6/`候选仅用生产PalimpsestFaultSeq=40（首项CLINT
效果段），不改生产RTL。已开始fault40_rtl_v6构建；原配置/额外Scala哈希独立记录。
目标是FAIL40后同PC journal重放及无第二次设备发射，最终严格--failed-seq40配对。
候选尚未验收，未作为长期配置或PASS。独立低优化大文件runner亦已准备等待生成。

V6原优化模型compact正常/Fault8严格配对PASS，checksum=75f3f507c3419640，
SCP8→FAIL8→同PC restore/restart成立。证据v6_compact_pair_review/及
reviewed_v6_fullcore_frozen/；trap_io还在执行。

V6独立模型正常trap_io已完整PASS：808703周期exit0、128ecall/MMIO/最终
checksum正确，353包PASS，零FAIL/CANCELLED/Restart。证据v6_fast_model/normal/trap_io/。
V6原优化模型Seq compact也已严格PASS，两次reset→Restart→Seq1；Fault8配对及
Seq16的trap_io仍在执行。

三份V6 Chisel FIR及before清单均已核验，哈希保存在v6_generation_checkpoint.json。

下一步：回收V6整核，优先运行正常trap_io核对原123959后的
后置封口与Seq0x28是否仍取消；严格检查Fault8和Seq16；若失败继续取first bad。
其他缓存迁移、多owner、真实Sv39/CSR/迟到响应组合仍未完成，不能提前标全VERIFIED。

---

# Historical: V5 翻译路径修复与 V4 整核结果 (2026-11-22)

证据根目录 `AI/TMP/singlecore_checker_20261122_082540/`。整体未完成：
69项仍为34 CODE_READY、32 IN_PROGRESS、3 VERIFIED。只读取消探针正在定位
异常/I/O组合的额外恢复；不得以程序exit0或最终checksum替代严格事件计分。

- V5在DTLB和共享Rocket TLB统一使用 `do_refill && !invalidate_refill` 门控。
  旧walk只释放owner，不写回旧翻译。两个真实反例分别在cycle7与cycle64失败。
  `rtl_regression_v5` 的Scala/Chisel/FIRRTL及14项组件全部通过，driver exit0，
  来源前后一致。`rtl_translation_v5_ptw`复跑长期双TLB和生产PTW测试，两项
  PASS、driver exit0、来源一致。真实PTW验证迟到non-leaf和leaf响应、L2命中、
  邻页non-leaf命中与SFENCE同拍；PTW生产源码未改。
- V3正常/Fault8 compact配对PASS，故障在SCP8同一PC恢复，新Epoch1包PASS，
  最终checksum=75f3f507c3419640。V3 Seq16 watchdog仍FAIL，属修复前证据。
- V4完整生成来源在 `v4_pre_v5_generation_checkpoint.json` 保护，原整核构建因
  Chisel生成之后工作树修改而source-cmp exit1，保留原结果。独立
  `reviewed_v4_fullcore_frozen`核验原FIR和源码覆盖包后运行同一模型。
  compact正常/Fault8配对PASS，Seq16真实两次归零→Restart→Seq1 PASS。
- V3与V4的compact-trap-io，正常与Fault8均成功退出，128次ecall/MMIO/架构
  oracle成立；严格配对却FAIL：正常配置seq0x28以CANCELLED完成，触发额外普通
  回滚，restart PC在get_mtime的0x80000858。V4 Seq profile两次重基后也有
  seq0xa普通取消恢复，严格重基计分FAIL。只读探针确认取消由package_progress_timeout触发，producer_sealed保持0；Main上游条件仍在定位，不能修改watchdog
  或放松计分冒充关闭。只读V4 hart1窄探针在 `trap_io_cancel_probe_v4_retry`，
  初次C++字符串换行编译失败保留。三配置V5整核构建在 `*_rtl_v5` 启动，
  此时硬件与长期输入已冻结到 `sources_v5_ptw.json`。

设计入口：[实现基准](../../Design/SingleCore_RTL_Baseline/README.md)。
翻译根因：[SFENCE/迟到响应](../bugs/bug-palimpsest-translation-refill.md)。
管理trap等待环：[Seq transport](../bugs/bug-palimpsest-seq-management-trap.md)。
历史Stage3 U250 5ns时序FAIL/WNS=-9.608ns，不能代表V5整核或有效证书增量。

---

# Historical: V4 Seq transport 与管理异常清理修复 (2026-11-22)

证据根目录 `AI/TMP/singlecore_checker_20261122_082540/`。V2正常整核exit0且
计分器PASS，Fault8在700000拍超时exit2，Seq16在tick496000触发Main watchdog
exit1。V1只读窄探针证实：L2维护完成、四个GHM permit为高，hart2/3却在维护
开始后进入无包管理异常，新的访存/取指被维护冻结，无法xRET；transport ACK
又等待context_idle，形成循环等待。包FSM、结果及RSUSL/LSL owner实际已空。
详细事件/来源见 `bug-palimpsest-seq-management-trap.md`。

V4已在R_ICSL输出复用现有状态的package_idle；RocketCore仅在Seq reset使用
包空条件，admission/COPY/结果handoff继续要求context_idle。没有清异常、
伪造返回或修改watchdog，没有新增寄存器/队列/FSM。修复前GHM＋R_ICSL组合
反例cycle4455 exit1；原夹具import和Verilator搜索路径错误各自保留。
长期SeqTransport增加管理异常保持与包内trap→取消→xRET→special-PC返回用例。
不同地址0x1111/0x2222的冷交接输入已并入长期Hierarchy。

V4聚焦GHM＋R_ICSL组合在`seq_management_v4_focused/`已exit0：管理异常保持、
包内trap→取消→xRET→special-PC返回及既有CDC均PASS。首次激励跨两Checker
上升沿产生两次trap却预期深度1，失败保留；只修激励单边沿脉冲，硬件库未变。
V4 Scala及全部Chisel/FIRRTL已通过；`reviewed_v4_components/`13项均exit0，
无assertion/UNCOVERED，生产源码前后相同。原组件driver的旧Seq激励FAIL和
C++修正后的source cmp失败继续保留；修正激励使用同一V4生成模型，哈希已核验。
三配置`*_rtl_v4/`仍在编译/回归，尚无整核V4 PASS。
后续C++修正造成原source cmp失败时，由独立核验runner确认生产源码未变再运行。
V3完整源码73581文件快照及各Chisel FIR哈希保存在`v3_generation_checkpoint/`。
在途V3原driver将保留因后续V4源码变化产生的比较失败，独立`run_reviewed_v3.py`
只在核验固定FIR、完整来源清单和已知后续变化后运行原模型，不混作V4验收。
任务仍为34 CODE_READY、32 IN_PROGRESS、3 VERIFIED，整体未完成。

---

# Historical: V3 冷查询交接修复与整核验证 (2026-11-22)

证据根目录仍为 `AI/TMP/singlecore_checker_20261122_082540/`。Fault8 归档模型
只读探针证实：完成的空查询在另一冷 offer 出现时先回 Idle，LSU 下一拍重新仲裁
回原地址，查询反复执行而没有请求进入 S0。未修改 V2 的真实层次反例在
`cold_handoff_before_v3/`：cycle8665 失败，8000 拍 51 次查询、零接受。
V3 DCache 在 Miss 当拍用 `beginColdLookup()` 捕获接替地址，复用已有 FSM、
寄存器和查询 payload。源码修改前快照见 `before_v3/`，长期输入为
`hierarchy_test.cpp::alternatingColdHandoff`，根因详见冷查询故障记录。

`rtl_regression_v3/` 的 Scala 编译和全部 Chisel 生成成功，13 项定向仿真 PASS；
driver 完成且前后源码清单相同。为补齐原会话未保留的 PTY 退出结果，
`reviewed_v3_components/` 仅重跑已编译模型，13项均记录 exit0，无 assertion/
UNCOVERED。`cold_handoff_distinct_v3/` 另用0x1111/0x2222区分两地址基线，
整套Hierarchy同样exit0，输入和库哈希独立保存。三个 V3 整核构建由
`run_fullcore_v3.py` 使用同一 SBT 锁串行生成，C++ 构建可并行；每个模型先跑
compact，再跑已保存的 compact-trap-io ELF。当前不能记为整核 PASS。

V1 Seq 只读探针已走完 L2 的 set0..0x3ff，`maintState=maintDone`，Main 发出
transportRequest，但未收到完整清理回执，最终在tick496000触发流水线watchdog，
run.exit=1。故不是 L2 扫描不前进；`seq_transport_detail_v1/` 新增 GHM/Checker
窄探针继续区分 source-empty、permit、local ready 与 ACK，未据此修改生产RTL。
先前不完整信号集的 `seq_transport_probe_v1/` 在采样前被新探针替代，明确标为
INTERRUPTED。模拟器 `sc_time_stamp()`
等于每个完整高低时钟周期递增一次的 `trace_count`，不是 FST 半周期时间。
V2 整核原构建的来源检查失败仍保留。`reviewed_v2/` 已结束：正常配置 exit0、
计分器 PASS（checksum=75f3f507c3419640）；Fault8 在700000拍超时 exit2；
Seq16 在tick496000触发Main watchdog exit1，无reset/restart，均不能记为通过。
Seq窄探针见 hart2/3 已无包/结果 owner，却仍 excpt_mode=1，context_idle和
packet_seq_reset_ready为0；正在追查真实 trap/xRET 生命周期，尚未修改清理条件。
任务状态仍为 34 CODE_READY、32 IN_PROGRESS、3 VERIFIED，整体未完成。

---

# Historical: 整核停滞取证、V2 构建恢复及长期边界测试 (2026-11-22)

上一会话中断终止了在途 EC 构建和诊断；未得到退出码的运行按 INTERRUPTED 保留，
不能作为测试 FAIL 或 PASS。`AI/TMP/singlecore_checker_20261122_082540/resume_v2/`
从原生成物恢复三个 V2 C++ 构建。`generation_inputs/` 保存硬件生成完成时与
`sources_v2.json` 完全一致的源码检查，以及所有生成 C++/头文件/Makefile 哈希。
之后新增长期测试会使原 driver 的末尾工作树比较失败，该失败保留；`reviewed_v2/`
独立核验实际编译输入后运行，不能把原 driver 改记为0。

长期 `hierarchy_test.cpp` 已纳入满 EVT 的 FAIL64→FAIL63 场景，并和全部既有
Hierarchy 用例共同通过。结果和单独重编的激励哈希在 `hierarchy_longterm_v2/`；
硬件仍为 `grant_sw_v2`，无整核执行结论。原34次物理维护也同次通过。

`compact-trap-io` 长期工作负载已编译：128次ecall、每轮CLINT输入及原架构oracle。
`fullcore_scoreboard.py --require-trap-io` 还要求128次及非零输入结果；`--single`
严格检查单日志的正确RESULT、END和成功模拟器退出。最终动态场景仍为NOT_RUN。
软件输出在 `trap_io_workload_longterm/`，不可与早先临时候选ELF混用。

V1只读探针在 `seq_stall_probe_v1/` 和 `fault_stall_probe_v1/`。
Seq16已经到Controller resume，Main与Checker排空后确实发出maintenanceRequest；
因此不能归因为Checker ACK未释放。`seq_maintenance_probe_v1/` 正在采集L2扫描
状态和MSHR终态条件，根因尚未证实。Fault8已有正确RESULT但无END，重复冷查询
原因仍在取证，尚未为此修改生产RTL。

V2 Stage3综合已完成：LUT21521、FF16041、BRAM7.5；5ns时序WNS=-9.608ns，FAIL。
夹具未协商新响应证书，相关逻辑被裁剪，不能代表证书增量或整核开销。
任务仍为34 CODE_READY、32 IN_PROGRESS、3 VERIFIED，整体未完成。

---

# Current: SW/Grant 竞态已复现，V2 响应证书验证中 (2026-11-22)

新真实 Hierarchy 反例在 cycle1037 失败：L2 以 SW6 选好 Grant 后再推进 Main SW8，
V1 按本地 SW 丢掉 Pending7，返回旧 BASE。V1 的 13 项 PASS 不能覆盖这个窗口。
V2 已在生产 RTL 加入一位 CacheRecoverySafe，随 SourceD 响应选择冻结；Acquire
只用既有 CacheImage 携带候选身份，L1 首个 Grant 按证书固定 payload/key。
Bank 级只做一次 Seq/SW 共享比较，移除 Main 的较晚分类，保留 publishPending。
详见 [可信写与 SW/Grant 根因](../bugs/bug-palimpsest-trusted-refill-recovery.md)。

V2 Hierarchy/Baseline/Pressure 及其余十项组件回归全部 PASS，driver exit0 且
前后源码清单一致，证据 directed_results_v2.json。三个 V2 整核构建正在执行。
V1 模型另作诊断，不能作为 V2 验收。中间 rebase_rtl 的320k周期探针已超时：未观察到旧
235514处 tsi_fail，但没有 Seq reset/restart/END，不算整核通过；该模型还缺最终
CPS-ready 条件。任务仍为 34 CODE_READY、32 IN_PROGRESS、3 VERIFIED。

证据归档 `AI/TMP/singlecore_checker_20261122_082540`，新增反例使用
`grant_sw_stimulus_v3.cpp/.sha256`；其来源差异说明和原 driver 失败均保留。
V1 L2 综合成功，5ns 时序 FAIL。V2 Stage3 粗综合通用单元11315，技术综合在执行；
该夹具不协商新证书位，不能用它量化证书有效开销。当前不可宣称全部功能完成。

补充真实层次测试 full_evt_earlier_fail_v2 已通过：满32区间、Pending63 时
FAIL64→FAIL63 合并相邻区间并释放容量，恢复 SCP63/epoch33，实际读回安全 Seq61。
初版激励误等不再需要的物理维护，错误预期和修正说明均保留，无生产 RTL patch。
该额外激励仍需纳入长期 Hierarchy 源码，临时输入及哈希已单独保存。

---

# Current: Checker cancel-before-COPY 修复及整核回归进行中 (2026-11-22)

本轮进一步证实 Fault8 的 HTIF 失败：只读主机探针显示清零 tohost 和设置 fromhost
均已完成后，旧指针再次出现；返回值 125 随后被作为 syscall 编号。见
[冷恢复覆盖可信写](../bugs/bug-palimpsest-trusted-refill-recovery.md)。
MSHR 改为首个 Grant fire 才固定未提交前驱，安全候选采用真实一致性 refill；
DCache 移除二次覆盖，Scheduler 在其他 set 的 preservation 锁期间保持 D 发布屏障。
Hierarchy 新增真实独立 TL host，修复前 cycle 1156 稳定失败，修复版两个 host
用例及其余 12 项定向回归全部通过，driver exit=0 且前后源码清单一致。
三个最终整核配置正在构建，完成后自动运行同一 compact workload。
本轮中间 rebase_rtl 仅含最初 Checker 修复；最终版本还包括 CPS ready 和缓存修复，
不可把该中间版本的结果当作最终全 RTL 的 PASS。

整核旧版本：正常 v1 完成 checksum、END 和 serial_success；Fault8 checksum 正确但
随后 bad syscall #125，无 END；Seq16 在 cycle 235514 以 tohost=2 失败。
窄探针证实 hart 2 的 Seq16 在 COPY 前取消，迟到 COPY 仍改写寄存器，JLR
随后在 nonchecking 模式执行 Main。见 [故障记录](../bugs/bug-palimpsest-checker-cancel-before-copy.md)。

RocketCore 已加入 COPY/JLR 存活 owner 门控，并复用 core_hang_up 等复制尾拍后
释放结果。本轮尚未得到修复后整核 PASS。计分器也要求成功模拟器退出并拒绝
bad syscall、FAILED 或 terminate。新归档为 `AI/TMP/singlecore_checker_20261122_082540`，before/ 与 before.json
保存本轮修改前状态；rebase_rtl 正在整核编译，fault_host_trace 在采集旧版 HTIF
读写。不要将未完成的生成或运行标为 PASS。全部任务状态继续为 34 CODE_READY、
32 IN_PROGRESS、3 VERIFIED；并非硬件全部完成。

---

# Current: PALIMPSEST 单主核 SourceC 压力与整核回归 (2026-11-21)

旧整核模型的 bank 级屏障在 History 达到保留容量后阻塞安全 BASE victim。现行 Scheduler 按实际 victim 的安全资格、发布顺序和 set owner 准入 SourceC。bank 继续用原带 Seq 屏障请求 Main 封口。Pressure 在 SW=0 下检查一次实际外写、真实 ReleaseAck 和 Checker Grant。恢复 bank 级门控的同激励对照在该 Acquire 上超时。整核旧轨迹、对照激励和对应哈希见 [故障记录](../bugs/bug-palimpsest-sourcec-pressure.md)。

SBT 编译和 13 项定向仿真已通过。Hierarchy 使用真实 L1/L2 检查 Figure 4、较早 FAIL、慢 Checker 收据和冷查询重试。三种整核配置的完成情况、综合数据及源码版本见 [验证矩阵](../../Design/SingleCore_RTL_Baseline/Verification_Matrix.md)。任务状态和源码位置见 [实现基准](../../Design/SingleCore_RTL_Baseline/README.md)。证据保存在 `AI/TMP/singlecore_rtl_20261121_171154`。

---

# Historical: PALIMPSEST C 发布及 EVT 安装回执 (2026-11-21)

单主核交付仍在进行。最新任务允许执行 Scala 编译、Chisel 生成、仿真和综合。任务板以 `AI/Design/05_SingleCore_Taskboard.json` 为准。完整实现、接口、不变量及运行证据集中在 [SingleCore_RTL_Baseline](../../Design/SingleCore_RTL_Baseline/RTL_Architecture.md)。

真实 Hierarchy 首次发现完整 C staging 等待同组在途外写时，L2 将 EVT 安装卡在地址查询门控。FAIL7 已到达，Main 仍等 FAIL8 的 bank 回执。DCache、InclusiveCache 和 Scheduler 在原四相邮箱中加入 `installOnly`，各域装载后回执，原地址查询仍等待 C 数据可见。最新 Hierarchy 在保持外写背压时完成第二次安装，接着检查 SCP7 重启和实际读数。前后运行和哈希见 [C 与 EVT 故障记录](../bugs/bug-palimpsest-c-baseline-order.md)。

同一 RTL 版本的 Scala 编译、Chisel 展开及 13 项定向测试通过。Baseline 七项检查包括 fullC 两拍队列、同组和同址 Probe、迟到 ReleaseData、SW 边沿和可信 A 写。SeqTransport 验证 GHM 空证书和 ACK 高低，PreciseException 验证生产 ROB 退休到异常的顺序。三种整核配置的生成、仿真和最终 oracle 见 [验证矩阵](../../Design/SingleCore_RTL_Baseline/Verification_Matrix.md)。

证据目录为 `AI/TMP/singlecore_rtl_20261121_171154`。后面的状态为历史记录。

---

# Current: Checker context receipts + real result CDC join; overall INCOMPLETE (2026-11-21)

Latest frozen single-Main task continues. No Scala/SBT/Mill, Chisel/elaboration,
RTL generation, Verilator lint/build/simulation, synthesis, FI or hardware tests
run. No commit or TMP cleanup. Unrelated DOC deletions left untouched.

69 tasks: CODE_READY=37, IN_PROGRESS=32, VERIFIED=0; 49 features retained,
47 InScope, C5/D17 Deferred. New local ready P5-04 is a directed component
join, NOT proof of full Rocket/BOOM architectural recovery.

New production changes: Rocket uses PalimpsestHistoryReceiver (existing bundled
payload/request synchronization/context, plus held install ACK). Main waits for
all banks AND all four Checkers during both mailbox high and low phases. L2
maintenance certificate is rejoined with L1 real quiesced/SVB/archive/package
owner conditions before compact; physical-resident-empty assertion added.
History pending covers the current SW-change cycle; safe direct resident Put
cannot overtake an already-owned history scan/publication. Full BASE/C/SourceC
same-address ordering remains incomplete.

Authored, NOT RUN: Hierarchy slow Checker ACK-high/ACK-low freeze and compacted
empty-context freeze; Baseline SW-edge dirty BASE candidate/history arbitration
and subsequent trusted writeback; CheckerRecovery actual RSUSL -> complete GHM
result AsyncQueue -> production Controller/SCP/EVT, PASS and f0 FAIL8, stopped
Checker clock, held Main release, cache/restore/restart ACK backpressure. The
fixture supplies local result permission and Main ownership/cache/restore ACKs;
it does not instantiate Rocket package-tail/cleanup or BOOM pipeline.
user_build.sh now emits 10 tops, builds 11 executables. Never run it as Codex.

Latest allowed static source check PASS: 35 Scala lexical scans, 13 C/C++ scans,
69/49 mapping/DAG/render/path, Python AST, bash -n and diff checks. This checks
no Scala types, Chisel, CDC, TileLink or runtime behavior. Final manifests live
under AI/TMP/palimpsest_frozen_20261121: after.json, after/ and
sources.after.20261121_receipts.json; static check in static_receipts.log.
Initial before/baseline preserved.

Next: cross-Rocket/Tile/GHM CDC/tagged-table Seq32 safe reuse; full same-address
SVB/C/SourceC/trusted BASE ordering; persistent I/O mismatch and full-core CSR/
PTW/exception/pressure close; full C staging/multibeat WB/earlier FAIL multi-owner
composition. Do not reset only Main Seq/SW or mark these tasks ready.

---

# Current: PALIMPSEST owner fixes + rare EVT maintenance; overall INCOMPLETE (2026-11-21)

Latest user task and frozen U-D01–U-D10 remain authoritative. Source-only work:
NO Scala/SBT/Mill compile, Chisel/elaboration/RTL generation, Verilator lint/build/
simulation, synthesis, FI, hardware testbench or regression executed. No commit,
no TMP cleanup, no unrelated DOC reverts. Baseline HEAD remains
75f2905693d6eec3b92d733e65bafa7a9c4be6dc; initial relevant dirty sources saved in
AI/TMP/palimpsest_frozen_20261121/before, hashes in baseline.json.

Taskboard: 69 tasks, CODE_READY=36, IN_PROGRESS=33, NEEDS_FIX=0, BLOCKED=0,
VERIFIED=0; 49 original features, 47 InScope, C5/D17 Deferred. New local ready:
P4-11 (actual pre/post close controller + directed source), P5-08 (actual dirty
victim/Probe/accepted multibeat WB/FAIL8 + full history fixtures). P3-15 remains
IN_PROGRESS: ordinary identity cycling and EVT maintenance written; Seq32 safe
reuse across Rocket monotonic package filters/CDC/tagged tables is incomplete.

Current actual changes: sequential real integer/FP PRF restore and owner done;
registered Gray/single-step SW; RAM history scanner/passive coalescing/four reserved
credits; pre/post device boundary; persistent exactly-once journal. Fix capacity
park/baselineReady/quiescent waiting for never-issued Acquire's Grant. Probe may
finish before parking; no external Release/Acquire is abandoned. Checker escape
way now covers non-image-aware Get AND coherent Acquire/translation reads. New
baselineObsolete receipt prevents old resident bytes satisfying new A after a
newer history DRAM ACK. Full same-address trusted BASE ordering remains open.

Core now directly uses production PalimpsestIoBoundary. Every live state has
synchronous flush cancellation; no combinational ROB flush->retirementHold loop.
Journal effectPending stays independent of drain busy, masks interrupts across
rollback until replay verifies. Uncached AMO owns both old-value response and
write completion, with independent backpressure. Mismatch preview requests the
current attempt's existing SCP recovery path without issuing a second device A;
persistent mismatch convergence/full-core privileged composition remain open.

EVT adjacent dead intervals merge. At full capacity (or Epoch/G near boundary),
THIS stopped rollback waits for SW=tail, all Checker package owners released,
LSU/cache quiescence and empty SVB/archive. A held CDC service request makes L2
use the existing directory read port, sequential set/way enumeration and the
original flush/Probe/Release/ACK path. Old EVT stays active: live safe bytes go to
DRAM, dead bytes release permission only. Empty cache/history plus real terminal
ACKs certify compaction; L1 clears EVT/Epoch/G, then publishes empty context via
original mailbox before restart. Ordinary rollback remains lazy/no cache scan.
Seq/SW do NOT reset. A replay-needed journal cannot become safe just because an
old EVT interval was retired. Full System Seq32 rebasing is NOT implemented.

Authored, NOT RUN: Io RD/WR/AMO independent terminal/two rollbacks/mismatch;
IoBoundary production FSM (prefix Pending, RSU, stores, new package, single-step,
flush in all states, interrupt mask across restart); Pressure real Scheduler full
64 entries/four-beat ProbeAckData/Main park/Checker Get+Acquire/resume after PASS;
Hierarchy dirty victim first accepted multibeat WB held across FAIL8/EVT, actual
late ACK and neighbor/lazy-load checks; 34 disjoint rollbacks with actual physical
maintenance, ACK backpressure, safe baseline and no retired dead revival. Recovery
has 96 adjacent retries preserving Pending7/A7, local compact and missing-certificate
fail-closed component tests. Full-core workload/oracle/scoreboard already written.
User-only user_build.sh emits 9 tops and builds 10 executables. See Design/08.

Open: Seq32 cross-Checker/CDC safe reuse; persistent I/O mismatch fault semantics
and full Core CSR/LSU/R_IC/PTW/exception composition; pressure close/full C staging/
earlier FAIL multi-owner combinations; complete same-address SVB/C/SourceC/trusted
BASE publication ordering. All are concrete source/test gaps, not requests for
reconfirming frozen decisions. Do not mark all 69 ready or any task VERIFIED.

Latest allowed static check: 69/49 mapping/DAG/render, 34 Scala lexical delimiter
scans, 11 C/C++ lexical scans, Python AST, bash -n, git diff --check PASS. These do
not check Scala types, Chisel circuits, TileLink behavior, CDC or functional results.
Continue from Design/05/06/07/08/09. Older state sections below are historical.

---

# Current: PALIMPSEST identity guards + real hierarchy fixture; overall INCOMPLETE (2026-11-21)

Resumed the source-only user task. No Scala/SBT/Mill compile, Chisel/RTL emission,
Verilator lint/build/simulation, testbench, synthesis or regression was executed.
No commit; no TMP cleanup or unrelated file overwrite. Baseline unchanged.

Taskboard now: 69 tasks; 30 CODE_READY, 32 IN_PROGRESS, 7 BLOCKED, 0 VERIFIED.
49 original features retained: 47 InScope, C5/D17 Deferred. JSON is authoritative.
New local CODE_READY: P3-15/P4-06/P5-05/P5-06. P5-08 is now IN_PROGRESS.

Production changes: complete-batch LSU functional/strict identity allocator;
saturating L1 slotEpoch + epoch0 primary gate; L2 preservation/release serial
capture/allocate/reload guards; sticky Controller fatal overriding ready restart,
with pinned SCP retained. L2 identity-unavailable level is synchronized to L1 and
connected via Tile/Core with LSU and R_IC Seq exhaustion. MSHR busy is separate
from allocation readiness. rollbackQuiesced now includes recoveryCacheIdle,
covering independent prober/snapshot/capture and killed-store replay owners.

New IdentityHarness + identity_test.cpp and ready-restart race in recovery_test.
New HierarchyGenerate.scala + hierarchy_test.cpp: real BOOM L1 + InclusiveCache +
CacheCork + Controller/SCP + host DRAM. Three authored Figure4 cases: A7 archived,
FAIL during migration, and accepted miss with delayed memory response. Scoreboard
checks actual load A7, unchanged adjacent A1, SCP8/new Epoch/Seq9 and no A8 DRAM
write. It does not instantiate BOOM pipeline. All tests NOT_RUN_BY_CODEX.
user_build.sh now prepares five tops; only the user may execute it or simulators.

Source blockers B-IDENTITY and B-HIERARCHY-TEST are closed at task-local code level.
Open: MMIO pre-I/O/replay/recovery-floor wait cycle; reserved close/drain capacity;
all-address baseline publication ordering; full dirty victim/probe/multibeat WB
concurrency and BOOM end-to-end workload/scoreboard. Overall recovery is INCOMPLETE.

Allowed static checks: 69/49 mapping/DAG/features/summary/render, 30 Scala lexical
scans, Python AST, bash -n, git diff --check PASS. No Scala typing/Chisel/TL/CDC or
functional validation. Continue from Design/05-09; never reuse old run evidence.

---

# Current: PALIMPSEST single-Main rollback INCOMPLETE (2026-11-21)

Latest user task: source implementation only; no Scala/SBT/Mill compile, Chisel
elaboration/RTL generation, Verilator lint/build/simulation, testbench, synthesis,
regression or fault injection may be executed by Codex. No hardware run performed.
No commit. Baseline HEAD 75f2905693d6eec3b92d733e65bafa7a9c4be6dc.

Taskboard: AI/Design/05_SingleCore_Taskboard.json (69 tasks; 26 CODE_READY,
32 IN_PROGRESS, 11 BLOCKED, 0 VERIFIED). All 49 original features mapped;
47 InScope; C5/D17 Deferred. CODE_READY is task-local source readiness only.
Overall recovery is INCOMPLETE, not hardware ready/validated.

Added persistent SCP/controller/EVT, BOOM PRF/rename/CSR restore, f0 comparator fix,
CurGen cold lookup/install, SVB-to-L2 independent archive mailbox, addressed L2
history, Checker tombstone cancellation and LSU cancellation/drain handling.
Controller order: pin SCP -> publish EVT -> drain -> reset/restore -> restart.
Three component fixtures under AI/Debug/scripts/rollback; no real combined
BOOM+L1+L2 recovery fixture. User-only build commands and limits in Design/08.

Open implementation blockers: current-segment MMIO/SW/ROB close cycle;
archive/segment-close reserved capacity/forward progress; complete per-address
baseline publication ordering; slot/token exhaustion functional guards; full
hierarchy/in-flight/end-to-end testbench/workload/scoreboard. No component test
was run. Static delimiter/doc-DAG/AST/shell/diff checks PASS; no Scala typecheck.

Do not use old Opt4/Stage2/Stage3 artifacts as evidence for these modified sources.
Do not resume historical optimization/benchmark commands below for this task.
Continue from Design/05, contracts/06, changes/07, tests/08, actual summary/09.
All hardware execution status: NOT_RUN_BY_CODEX; await explicit user-run evidence
before any VERIFIED status. Known source blockers must still be implemented.

---

# Current: Opt4 frozen, optimization PAUSED (2026-11-02)

Latest user request supersedes every historical READY/NEXT_ACTION command below.
CURRENT_STABLE_OPT=Opt4; STATUS=FROZEN; OPTIMIZATION_STATUS=PAUSED.
Use slowdown/OPT4_BASELINE.md and slowdown/README.md for subsequent DAC experiments.
Opt4 ROI1,707,863 / native1,001,675 =1.7050071×, SVB16, v1Config/L1D32KiB.
Functional hardware restored byte-identically to476a76091; original12 measured hashes
and expanded20-file frozen scope are recorded under slowdown/opt4/frozen_manifest.json.
Seq67 function/diagnostics,64KiB config, causal/snapshot observers and SourceC bypass
are archived, NOT active Opt4. SourceC had no hardware run at pause.

Actual patches reconstruct all16 pre-cleanup hardware/host files (bytes and modes),
with original dirty source/script snapshots under slowdown/analysis_archive/cleanup_evidence/.
Original AI/TMP seals, claims, raw FAIL/recovery/reports and large artifacts remain.
Stable host analyzer keeps proven L2 shadow-vs-correctness separation, not experimental
schema/counters. Stable launcher guard patch now has a versioned slowdown/opt4 copy.
Two unclassified dramsim logs moved to slowdown/unclassified_logs;22 run/evidence logs
kept. Only46 reproducible bytecode files and10 empty cache dirs deleted.
No hardware generation/build/benchmark or performance optimization in this cleanup.
Historical baseline durable-drain/provenance limits and failed L2 S0 remain explicit.

NEXT_ACTION=USE_FROZEN_OPT4_FOR_DAC_EXPERIMENTS.
Optimization resumes only by explicit decision; read slowdown/analysis_archive/RESUME_OPTIMIZATION.md.

---

# Opt5 SourceC waitAck bypass — implementation sealed, user one-shot ready (2026-11-01)

Latest user request supersedes further precision attribution: static quick GO→minimal
RTL fix→one formal candidate experiment. STATIC_HOL_ROOT_CAUSE=PROVEN;
SOURCEC_OPT5_GO=YES under user B/D rules. Global SourceC lease spans checkpoint
waitAck, blocks unrelated victim Release and delays its MSHR Acquire.
Runtime critical gain/upper bound UNKNOWN; static confidence HIGH, gain confidence LOW.

Two L2 files changed vs completed B: L2Preservation exports waitingAck;
Scheduler reserves SourceC only for lock&&!waitingAck. Target-set lock remains
capture→matching terminal ACK. Existing image/watermark, physical overwrite, source,
packet/hazard, ReleaseAck ordering and next-capture drain remain. New SC48 is one
bounded STOP row with8 predicates; no percycle trace/ROB mapping. Raw pending overlaps
other blockers; traffic START→STOP counters are not exact ROI or recoverable savings.

Report (only5 primary files): `AI/TMP/opt5_sourcec_one_shot_20261101_173240/`.
Scala typer PASS (no hardware generation),14 CPU contract/diagnostic/guard tests PASS,
shell/diff checks PASS, real shell --static-check PASS. Seal20hardware/23tools:
`dc55be848aa333d96d2cd5299896c1957208e34b784e156b38a4e6ae53fcb335`.
These are source checks/witnesses, not Chisel/comb-loop/TL runtime validation.
Hardware generation/Verilator/simulation NOT_EXECUTED; no launch claim consumed.
Correctness and performance remain PENDING_USER_RUN. Risk MEDIUM until hardware checks.

NEXT_ACTION=USER_RUN_ONE_OPT5_SOURCEC_EXPERIMENT:
`bash AI/Debug/scripts/run_opt5_sourcec.sh --report AI/TMP/opt5_sourcec_one_shot_20261101_173240 --jobs 4`
Same B64K config/software/ROI/seed1/SVB16/MSHR6/clocks. Candidate compared with current
completed B ROI1,648,923, not a new baseline. One persistent exclusive claim; no retries,
A-prime, sweep or second SourceC micro-tuning run. Host capture overlay changes only
identity dictionaries128→256, preserving byte budgets, priority and all validation gates.
Original B raw FAIL and lossless recovery, old seals/reports/claims are unchanged.
Original19hardware exceptScheduler plus newly changedL2Preservation and all original
sealed tools were verified against pre-edit snapshots. Strict historical A/newB pairing
remains pending. ROI<1,502,513=sub1.5; saving≥100k strong,50k–100k moderate;
<50k STOP_SOURCEC_DIRECTION. All correctness/observer/measurement gates required first.

---

# Opt5 preservation/outer-A — packet-to-ACK hypothesis refuted; move to SourceC HOL (2026-11-01)

Latest report: `AI/TMP/opt5_preservation_outerA_attribution_20261101_135133/` (all13 artifacts).
Offline only; no hardware patch, elaboration/generation/build/simulation, A-prime/newB,
sweep/geometry/MSHR/frontend/SVB32/promotion, subagents or cleanup. Original B closure,
seals/raw FAIL/recovery/claims/old reports unchanged. Strict pairing remains pending.

Source/generated proof distinguishes3 resources: target-set lock capture→terminalACK;
outer-A beatsLeft packet lock first→last accepted Put only; global SourceC reservation
while target lock active. Ordinary SourceA ready contains packet idle/selection, NOT
target lock/ACK. Pre-capture bank reads/delay may allow ordinary A; after final A,
waitAck allows ordinary A while set remains protected. Inner Get hits use SourceD.
SourceA depth2 FIFO keeps one presented unique head during continuous packet lock;
held-valid repeats are NOT blocked unique requests or LSU retry events.

Intrinsic gap-only fixed-trace UB≤(1623 memory-write starts+1possible carry-in)*21=34,104
cycles. This is a scoped service-slot ceiling, NOT whole-lock/preservation UB; excludes
bank waits, downstream ready-low, drain, waitAck and feedback. Refute packet lock
spanning drain/terminalACK; stop intrinsic-gap-only direction as Opt5 main (<50k).

More concrete NEXT offline mechanism: checkpoint waitAck uses no bank read but
Scheduler globally gates all SourceC schedule/read on !preservation.lock.valid.
Unrelated dirty-victim Release can wait; its MSHR new Acquire requires s_release AND
w_releaseack. Structural SourceC reservation→release/acquire HOL proven, runtime
occurrence/critical budget NOT_PROVEN. Design-only narrower borrow phase must retain
target-set lock and terminal ACK/provenance, recheck hazards/next capture drain.
Separate ingress C-priority locked-set HOL and downstream CacheCork C→A arb also exist.
Checkpoint has priority above normal SinkD/SourceD bank work; those cannot starve it
via BankedStore arb. SinkC/noop reservation may block, duration unknown.

67,366 prebank union unchanged; trueT1–T5 not reconstructable (candidate/req may precede
lastC; not everyC triggerspreservation). No actual preservation/packet top20;20 real
release prebank proxies saved with unknown fields null, not mislabeled episodes.
Complete-prefix prebank×scheduler94cycles is proxy only. UB1–UB4, critical joins,
request/retry amplification, independent whole-chain critical UB UNKNOWN; conservative
credit0. Direct head nested envelopes53,845/80,832 are NOT global transfer bounds.

AMPLIFICATION_PROVEN=NOT_PROVEN; MAIN_MECHANISM=NONE_JUSTIFIED;
OPT5_STATUS=NONE_JUSTIFIED; SUB1P5_FEASIBILITY=NOT_SUPPORTED;
CHECKER_FRONTEND_PRIORITY=LAST_RESORT; NEXT_ACTION=MOVE_TO_NEXT_OFFLINE_BOTTLENECK.
Next offline: SourceC waitAck reservation/release-acquire HOL, then L2 ingress/SourceD
service; no functional run prepared. B1,648,923,target<1,502,513,required saving146,411.
19 targeted CPU tests + offline integration PASS, original19 hardware/19tools/85evidence/
8generated-native hashes unchanged. Synthetic contract witness is NOT a runtime trace.
Tools/reference: analyze_opt5_preservation_outer_a.py and renderer;
AI/Debug/references/opt5_preservation_outer_a_limits.md. Historical A-prime commands
below remain superseded by current offline-only scope.

---

# Opt5 cache-transfer attribution — specific pre-bank wait found, critical budget unknown (2026-11-01)

Latest priority: cache transfer/refill/WB/arbitration/backpressure, then LSU/retry,
then BOOM/checker resource availability; checker frontend LAST_RESORT. Offline only:
no elaboration/generation/build/simulation, A-prime, sweep, MSHR expansion, SVB32,
promotion, subagents, cleanup. Existing B correctness and seals remain closed.
Report: `AI/TMP/opt5_cache_transfer_attribution_20261101_113310/` (all13 requested artifacts).

Mandatory SC20/38/21 reconstructs6,735 source6 voluntary ReleaseData transactions,
all53,880 actual L2 bank-word writes (8/8 each), complete matching ACKs. Software ROI
contains2,231 complete transactions (normal1,793/SVB438), no boundary-censored cases.
`[firstC,ACK)` phase union100,915; lastC→firstbank67,366; first→last of8 consecutive
bank writes15,617; lastbank→ACK4,546. lastC→ACK median52/p99=65/max85, firstC→ACK
max91. This is post-first-C phase exposure, NOT whole-source lifetime or removable
critical gain. Long52-cycle mode1,405 cases vs10-cycle mode690 cases has no saved
checkpoint-state join. Optional complete prefix release92,448/scheduler280,215
overlap151; do not extend to missing suffix or infer all cache/checker delays absent.

Source audit: MSHR WB response is final victim row capture, not ReleaseAck; ACK still
holds source/same-set admission. Full Grant creates E responsibility independently
of later RPQ/install/meta; ordinary read already has LB forwarding before physical
install.6 full-line LB slots share write-priority read scheduling and per-MSHR row
staging; active DuplicatedDataArray bank-nack0 does not mean every refill blocks hits.
Most specific static hypothesis: L2 checkpoint global pre-capture drain, target-set
lock, single-engine read/delay1/delay2/send, outerA multibeat arb held across gaps.
After capture other-set D may proceed; SourceC read/schedule remains restricted.
No runtime critical budget. Native detect→data22/1052 tail samples>=1024cycles have
summed elapsed-duration bounds169,083..189,549 out of211,045 total; this is NOT ROI
critical cycles (overlap/pre-ROI starts possible), no Tier1 credit inferred.
Potential512bit checkpoint buffer/burst is design only,
must retain old image/provenance/safe watermark/matching terminal ACK. No hardware patch.

`CACHE_TRANSFER_MAJOR_BOTTLENECK=NOT_PROVEN`; largest measured transfer phase100,915,
whole-mechanism `INDEPENDENT_CRITICAL_UPPER_BOUND=null`; conservative credit0,
expected gainunknown; `MAIN_OPT5_CANDIDATE=NONE_JUSTIFIED`;
`1P5_FEASIBILITY=SUB1P5_NOT_SUPPORTED`; `NEXT_ACTION=MORE_OFFLINE_ATTRIBUTION`.
80,832 direct headpending is NOT a global cache-transfer/checker/nonhead bound.
Current B1,648,923; target<1,502,513; approximate gap146,410, strict saving146,411.
No new hardware run prepared; no diagnostic-only run or frontend promotion.

Reusable `analyze_opt5_cache_transfer.py` + renderer;21 targeted CPU tests PASS,
mandatory identity/word/order/lifetime checks and offline integration audit PASS.
19 hardware/19 sealed tools/85 original evidence/8 prior generated-native hashes
rechecked unchanged. New generated hierarchy/FSM/arbitration/config evidence saved
separately. A/new B remains REFERENCE_COMPARISON/STRICT_PAIRING_PENDING; historical
A-prime commands below are superseded by current offline-only scope. All old reports,
seals/claims/raw FAIL and corrected B recovery preserved. See reference
`AI/Debug/references/opt5_cache_transfer_limits.md` for scope and future bounded counters.

---

# Opt5 sub-1.5 opportunity — no justified candidate from current load evidence (2026-11-01)

Latest user objective supersedes treating 64KiB/2way as final Opt5: seek a coherent
L1/load critical-path optimization with credible sub1.5 budget. Analysis only;
no elaboration/RTL generation/Verilator build/benchmark simulation, no subagents,
no cleanup. Report: `AI/TMP/opt5_sub1p5_gap_analysis_20261101_110130/` (all11 required files).

`OPT5_1P5_TARGET_NOT_SUPPORTED_BY_CURRENT_EVIDENCE`;
`OPT5_PRIMARY=NONE_JUSTIFIED`; `NEXT_ACTION=MORE_OFFLINE_ATTRIBUTION`.
No hardware change or new hardware-run launcher prepared. 64KiB remains a causal
probe/optional future component, not a final Opt5 or a rejected geometry.
A-prime remains unrun; `STRICT_PAIRING_PENDING`. Do not mechanically run the
historical refresh command below. Old A/new B deltas remain reference-only.
Corrected B correctness/capture recovery and old seals/claims remain intact.

Target native1,001,675; current B1,648,923/1.646165672x; user exclusive threshold
1,502,513, approximate gap146,410. Strict integer saving must be146,411.
B head miss53,845; all head-load pending80,832 (nested, not additive); retries47,162;
RPQ replay issues229; head miss AND MSHRbusy53,795/full0; head miss AND scheduler0.
Ideal deletion of direct head-miss wait yields1,595,078/1.592410712x; deleting all
head-load pending yields1,568,091/1.565468840x. `LOAD_PATH_ALONE_CANNOT_REACH_1P5`
is scoped to deleting these measured waits in the fixed observed trace. It is
NOT a universal bound on nonhead dependence or new-execution timing feedback.
STOP noCommit AND anyLoadPending ROI exposure148,359..159,519 remains a wider
unattributed correlation, not recoverable load delay. Scheduler347,409 is a
separate, unproven-removable control opportunity; do not bundle into load Opt5.

Structural retry amplification is proven: retained stable LDQ token -> repeated
S2 lookup/nack -> executed=false -> age-priority wakeup. Age/retention already
exist. MSHR not-ready includes same-set/tag, secondary state/RPQ and SDQ gates;
39,072 reason predicates are not20,433 valid-request rejects or full-MSHR stalls.
Active generated bank-nack constant0; max occupancy2/6/full0. Ordinary load
line-buffer forwarding already exists; RPQ terminal/owner guards must remain.
No per-token/address retry trace or contiguous head episodes were saved. Exact
retry factor is unknown ([1,47162] trivial bounds); miss-lookup-attempt cohort
factor is separately bounded37.1364..37.6959 with at most16 carry-in LDQ tokens,
implying some token has>=38 miss lookups, not a measured critical nack factor.

New offline analyzer/test: `analyze_opt5_sub1p5_gap.py`, `test_opt5_sub1p5_gap.py`.
17 targeted CPU tests PASS; raw counters/STOP and source/generated signatures
audited; all19 hardware/19 sealed tools/85 original evidence hashes unchanged.
Design-only options are progress-aware retry suppression, measured refill/meta
arbitration, and load-specific SDQ admission. Each lacks runtime critical budget;
expected gain/final ROI remain unknown, conservative credit0. Preserve all old
reports; details and revalidation boundary in the latest validation_result.json.

---

# L1-Causal-1 — corrected B PASS after offline host-accounting recovery (2026-11-01)

Latest user request is analysis-only; do not execute elaboration, RTL generation,
Verilator build or benchmark simulation. No subagents, cleanup or automatic retry.
Report: `AI/TMP/l1_one_shot_postanalysis_20261101_095815/` (all9 requested artifacts).

The user named `_094628`, which never simulated. Actual completed B is
`checker_seq67_one_shot_20261031_103130/sealed/arms/B/runs/optimization_4_svb_20261031_024551_8fbf8937`.
B generation/build PASS, simulation exit0, verified1/checksum43439728, exact software
ROI[698301,2347224)=1,648,923. Original overall FAIL is preserved:133 logger identities
exceeded128 host dictionary slots. Five STOP identities16/17/18/30/31:0 were merged
into `other`, but their events/footers and mandatory producer statistics all survive.
Five lost producer-stat entries are optional only. Scoped lossless deaggregation in
a separate derived view passes all24 unchanged arm gates; mandatory conservation
is complete, optional evidence remains incomplete. No raw artifact/seal/claim changed.

ROOT_CAUSE_CONFIRMED: pending privileged CPS meets machine timer trap at939413;
new dispatch defers through architectural eret939857, exception/depth clear939859,
start accepts939861, exec completes940821, result forms940889, special return clears
return_pending940905, cleanup/handoff940907, BOOM accepts PASS940911, ownership busy
clears940912, release deasserts940913. Local depth remains0 because trap is processed
before checker entry. Registered-entry trap-capture alternative is unexercised (counter0).
All320 allocations match320 clean handoffs and320 accepted PASS results; checker3 has84.
No CANCEL, failed/stale/duplicate result, assertion, watchdog or unmatched sequence.
Checker/observer/integrity PASS. L2 S0 exact159; L1 shadow2866 vs actual2624 has9.22%
error within unchanged10% gate. Do not replace actual misses with shadow predictions.

Old A vs new B is REFERENCE_COMPARISON only: ROI1,707,863→1,648,923 saves58,940/3.4511%;
actual lookup misses3272→2624; exact-ROI ROB-head miss wait139694→53845 (−85849);
nack retry111548→47162 (−64386); RPQ321→229; MSHRbusy313150→194905/full0;
scheduler318150→347409, scheduler∩busy269/full0. No MSHR expansion evidence.
A_NON_INTERFERENCE_PROVEN remains NO (old A701 SC6 drops). Strict geometry-only
MISS_TO_CRITICAL_PATH_REDUCTION remains NOT_PROVEN; reference causal signal is strong.

STRICT_BASELINE_REFRESH_JUSTIFIED / STRONG_OPT5_SIGNAL (reference only).
Prepared exactly one A-prime; user execution only, no B rerun:
`bash AI/Debug/scripts/run_checker_seq67_baseline_refresh.sh --report AI/TMP/l1_one_shot_postanalysis_20261101_095815/baseline_refresh --jobs 4`
A-prime's19 hardware inputs equal completed B; baseline config32KiB/2way/6MSHR,
software/checkers/observer/STOP/causal counters/seed unchanged. A separately sealed host
capture copy changes only two identity caps128→256 (budgets/classification unchanged).
Original B seal/guard remains intact; new A-only wrapper calls all original guards,
rejects B, uses persistent one-run claim and never retries. Static preflight PASS;
no A claim or run manifest exists yet.55 offline CPU tests PASS this turn.

After the user runs A-prime, read baseline_refresh/A_prime_result.json and raw A
results. Final pairing must pass identical hardware/software/arguments, generated
geometry/clocks/L2/native copies, full correctness/ROI and host-exception audit.
If A-prime fails, diagnose offline; do not retry or launch another arm automatically.

---

# L1-Causal-1 — fix user RTL-generation combinational loop (2026-10-31)

The user ran the previous one-shot command. It failed RTL_GENERATION before
Verilator build/simulation: all4 Rocket checker modules had
check_exception -> wb_valid -> CSR.retire -> trace.exception -> privileged_start_ready
-> check_exception. The prior source-only claim that unsigned retire>=0 removed
the structural edge before CheckCombLoops was incorrect; Scala typer cannot prove this.

Minimal correction: privileged_start_ready consumes existing CSR r_exception.asBool,
whose raw exception equation has no retire input. The same-cycle trap/return priority
is retained without adding RegNext latency. No other hardware file changed relative
to the failed seal. Saved failed FIRRTL reproduces the old loop in all4 Rocket/CSR
cones; the one-input corrected graph has no such cycle. This is a scoped offline
audit, not a new full FIRRTL PASS. Scala typer PASS;45 offline CPU tests PASS.

New report: `AI/TMP/checker_seq67_one_shot_20261031_103130/`.
New user command:
`bash AI/Debug/scripts/run_checker_seq67_one_shot.sh --report AI/TMP/checker_seq67_one_shot_20261031_103130 --jobs 4`
The old seal, claim, failed generation artifacts/log and NOT_STARTED simulation
manifest remain preserved. No benchmark was consumed by that failure. Exactly one
B64K/2way is still requested; no A or diagnostic-only run. Agent did not elaborate,
generate RTL, build Verilator or simulate. A_NON_INTERFERENCE_PROVEN remains NO.
Full FIRRTL/build/runtime validation is pending the new user command.

---

# L1-Causal-1 — seq67 one-shot B command ready (2026-10-31)

Latest user constraint: **agent must not execute elaboration, RTL generation,
Verilator build or benchmark simulation.** This supersedes the older run permission
below. Target is one user-run corrected B64KiB/2way only; no A or diagnostic-only run.
Report: `AI/TMP/checker_seq67_one_shot_20261031_094628/`.

Offline RCA identifies a TYPE1 privileged-dispatch/architectural-trap race: B seq67
start accepted at939415 with context_idle0, excpt_mode1, local trap_depth0 and ICSL
nonchecking. Normal/fallback start paths are false, so registered privileged entry
is inferred. Old dispatch lacks current-trap exclusion and treats delayed CSR.eret
(also ECALL/EBREAK) as return permission. Final CANCEL67 context wait is proven;
exact CSR cause/vector remains unlogged. ROOT_CAUSE=
MOST_LIKELY_WITH_BOUNDED_RUNTIME_CONFIRMATION, not a justified watchdog increase.

Implemented held privileged CPS dispatch with real-trap/current-return priority,
plus R_ICSL trap capture on the registered privileged-entry edge. Added bounded
SC46/47 diagnostics in the same version. Cleanup/result release/compare/watchdog
guards and all17 previously sealed hardware inputs remain byte-identical. Scala
type-only check PASS;42 offline CPU tests PASS. Hardware phases NOT EXECUTED.

A remains correctness-valid at ROI1,707,863, but **A_NON_INTERFERENCE_PROVEN=NO**:
701 optional SC6 host records were dropped. None of283 retained starts is abnormal;
zero CANCELs does not prove a timing-changing safe deferral never occurred. Thus no
automatic strict old-A/new-B causal interpretation and no prearranged A refresh.

User command (from repository root):
`bash AI/Debug/scripts/run_checker_seq67_one_shot.sh --report AI/TMP/checker_seq67_one_shot_20261031_094628 --jobs 4`
It verifies a new seal, invokes the existing launcher once for B, performs offline
diagnostic/provenance/correctness/observer/ROI checks, and forbids automatic retry.
If B passes, status is CORRECTNESS_CLOSED_BUT_STRICT_PAIRING_REQUIRES_BASELINE_REFRESH;
numeric reference differences stay explicitly unpaired. Discuss A only if that B
first demonstrates worthwhile apparent benefit. No extra geometry/policy work.

---

# L1-Causal-1 — r2 INCONCLUSIVE after B checker3 ownership timeout (2026-10-30)

The user explicitly authorized paired hardware generation/build and real simulations.
Keep the validated original Opt4 ROI1,707,863 / SVB16 conclusions below. Do not substitute
that historical run or r1 A for the final corrected paired baseline.

Report: `AI/TMP/l1_causal_opt5_probe_20261030_200000_4235a1de/`.
Active revision: `revisions/r2`, source fingerprint
`b6f9a8739a0be1a64cd349625e37dc8b5b8cd246b418041bc3ee68dd1af414b1`.
A = Opt4/SVB16, BOOM L1D256sets/2way/64B/6MSHR =32KiB;
B changes only nSets512 =64KiB. Software/checkers/seed/observers/instrumentation match.

R1 A completed exit0, verified1/checksum43439728, exact historical ROI reproduced,
functional/integrity/protocol/STOP40–45 and corrected L2 snapshot PASS. Causal
measurement failed: two ROI snapshot lookup errors. Root source defect: causal
marker selected pre-CSR-mux WB data rather than architectural `debug_wb_wdata`.
R1 B was deliberately interrupted before ROI after this defect was proven.
R1 seals, builds/runs and proofs remain preserved. No r1 paired performance conclusion.
See `roi_marker_rca.md` and `r1_measurement_failure.json` in report.

R2 changes only the read-only marker source to the existing CSR-muxed value, adds
bounded4-line marker diagnostics and fixed2-record JSON fields, and preserves them
as essential capture. Scala9-file typer PASS;82 unique offline tests PASS (including
two new aborted-run report cases), plus separate native count-definition fixture PASS; six-file exact
observation/config inverse PASS. Both RTL generation and Verilator builds PASS.
R2 A completed exit0, verified1/checksum43439728, ROI1,707,863 [712114,2419977),
all24 functional/observer/measurement gates PASS. Both ROI markers have exact timestamps
and lookup_valid1; causal errors0. Exact-ROI MSHRbusy313150/full0, matched head-miss
wait139694, head∩busy139500, scheduler318150. These are exposures, not additive losses.
B build PASS and real simulation terminated exit1 at the existing checker3
ownership assert24 (generated BoomCore.sv:6977; source core.scala:2211; total counter
bit18 =262144 BOOM cycles). B start marker698301 valid, but no stop/benchmark/final
cache/counter summaries. No B ROI, miss delta or causal performance delta is available.
Execution argv equality/generated clocks+L2/native copies/seal audits PASS.

Saved SC6 evidence: checker3 seq67 no-progress timeout at global1070889 enqueues
CANCEL67; final local record1070897 has result_queue_valid/outstanding1,
context_idle0/return_pending1/excpt_mode1/trap_depth1, handoff_allowed0.
Frontend clear ack is present. Local cancellation is not BOOM ownership release.
Upstream trap/start/return trigger remains UNRESOLVED; no functional checker fix,
policy change, waveform run or extra geometry run was attempted.

**INCONCLUSIVE_DUE_TO_CORRECTNESS_OR_MEASUREMENT. NEXT_OPTIMIZATION = NONE_JUSTIFIED.**
**L1 miss reduction -> critical-path cycle reduction: NOT YET PROVEN.**
Next: close seq67 context/cleanup/CANCEL handoff correctness before any new paired
performance experiment. Report README, all required artifacts and20 answers complete;
missing B metrics are explicit null/unavailable, never0 or shadow1301.
[Failure chain](../../TMP/l1_causal_opt5_probe_20261030_200000_4235a1de/r2_B_correctness_failure.md)
· [Durable unresolved finding](../bugs/l1_causal_64k_checker3_ownership_20261030.md).

---

# Latest Opt4 state — validated reference; next optimization not yet justified (2026-10-30)

**Authoritative run:** `optimization_4_svb_20261030_072604_18475a92`.
**Opt4 correctness PASS / ROI VALIDATED:** 1,707,863 cycles; baseline1,001,675;
Opt3 2,928,347; remaining706,188; Opt4/baseline1.705007×; Opt3 reduction41.68%.
exit0, GAPBS verified1, checksum43439728; all406 allocation identities closed as
391 promoted+12 coalesced+3 discarded; fingerprints/protocol/order/histograms PASS.
Do not reopen SVB correctness or rerun Opt4 because L2 shadow fails. The old
analyzer incorrectly coupled cache-model fidelity to functional validity; repaired
offline results keep functional PASS, L1 S0 PASS, and L2 shadow FAIL separate.

**Decision:** `NEXT_OPTIMIZATION_NOT_YET_JUSTIFIED`;
`NEXT_OPTIMIZATION = NONE_JUSTIFIED`; `KEEP_SVB16` / `DO_NOT_EXPAND_SVB`;
`L2_GEOMETRY_DEFERRED_UNTIL_NEXT_FUNCTIONAL_RUN`.
No functional optimization or READY Opt5 launcher is implemented. The pending
Opt5 directory contains a decision note only. No observation-only run is prepared.

Opt4-only analysis: SVB16 full4,888 cycles/0.2844%, fallback1. The unique full-related
legacy episode is [1598099,1603353), 5,254 cycles: fixed-trace local deletion ceiling,
not a global timing-feedback theorem. All16 owners were unsafe at full onset;
first safe1602974. Keep16. Promotion safe→terminal union24,569 cycles; source busy23,788,
queue15,714 in traffic window; not a justified next primary direction.

L1 S0 misses3,286 vs actual3,272 (0.427873% error); alternate misses32K/4way1,494,
64K/2way1,301, 64K/4way1,178. Conditional cache preference64K/2way, but no per-miss
MSHR/ROB identity join to establish ~85,393 recoverable critical cycles. All-L1 MSHR
busy315,637 is a resource envelope, not geometry benefit. Replacement definitions
differ and alternative models omit some mandatory preservation invalidation detail.
Equal-service proxies173,911/192,641/204,578 are not ROI predictions or strict bounds.
Control scheduler-unavailable267,087 is the largest identifiable control exposure
within the complete optional prefix, not proven recoverable slowdown.

Software ROI[712114,2419977); traffic[712021,2430802). Optional records omit3,099;
conservatively proven complete prefix ends2289264, leaving130,713 unknown ROI cycles.
Do not hold sparse state through that suffix or add overlapping activities into706,188.
Exact LSU load/store/request/nack and ROB-critical overlap counters were not in this run.

L2 observer structural defect: accepted-write mirror is not the delayed Directory
read image with queued-write bypass. CPU fixture confirms a false-miss mechanism;
the missing raw lookup/metadata order prevents exact attribution of all40,220 excess
misses in this run. Implemented read-consistent way snapshot + independent key/tag
audit, canonical address restore, A/C/opcode semantics, fail-closed invalid deltas.
Added six bounded STOP observers kind40–45 (121→127/128 identities) for activities,
ROB no-commit overlaps and actual admission-guard priority classes. These source
changes are staged for the next independently justified functional run only.
Old Opt4 launcher source/patch protection is unchanged and does not accept the new
staged source as a READY runnable revision. Do not bypass it or create an observer run.

Validation this turn:58 CPU/offline tests PASS;7 modified Scala files typer-only
(`-Ystop-after:typer`) PASS;7 hardware files exact observation inverse PASS;
original evidence hashes unchanged. No Chisel elaboration, RTL generation,
Verilator build, hardware simulation or benchmark. Dynamic observer validation pending.

[Report](../../TMP/opt4_remaining_slowdown_next_opt_20261030_e6901889/README.md)
· [18 answers](../../TMP/opt4_remaining_slowdown_next_opt_20261030_e6901889/answers_18.md)
· [Candidate ranking](../../TMP/opt4_remaining_slowdown_next_opt_20261030_e6901889/candidate_ranking.md)
· [Validation](../../TMP/opt4_remaining_slowdown_next_opt_20261030_e6901889/validation_result.json)
· [Durable observer finding](../bugs/l2_shadow_read_image_semantics_20261030.md).
All older current/READY/insufficient entries below are historical and superseded
for the authoritative 072604 run; no prior evidence has been deleted.

# Latest Opt4 SVB state — integrity observer closure prepared (2026-10-30)

**CURRENT_DATA_FUNDAMENTALLY_INSUFFICIENT** for retrospectively certifying run
`optimization_4_svb_20261030_044205_dbaf743b`. This is a concrete information loss:
old DPI emitted only aggregate hashes/counts, and success discarded the failure ring.
No additional pure diagnostic run is requested or executed.

84 mismatch increments = 76 proven observer duplicates (72 lower64-bit beats +
4 C128-bit beats caused by 8 repeated version identities) + 8 final hash comparisons
without recorded key/hash. The 8 failing keys cannot be identified from the saved
aggregate. No real functional data bug has been proved or excluded. All 391 promotions
match C/ACK/completion; 406=391+12 coalesced+3 discarded in aggregate, but the last
15 allocation identities/terminals were not recorded. The CSV explicitly marks them
unknown; it is not a fabricated complete lifecycle ledger.

Histogram root cause fully closed: old DPI included STOP edge while SC snapshots
were pre-edge. Both histograms differed only by bin0+1. Revised analyzer normalizes
this exact reviewed legacy patch in memory and preserves raw evidence; no original
run files changed. Correct hardware window is [712021,2430802), 1,718,781 cycles,
distinct from software ROI1,707,863.

SVB16_SUFFICIENT for BFS512: occupancy>8=65,102 cycles/3.79%, would_full_at8=56,
full16=4,888 cycles/0.2844%, full fallback1, max line depth5. Keep16. Old L1/L2 S0
miss errors58.74%/389.26% forbid a geometry candidate; do not change cache geometry.
Current raw ROI remains PENDING_INTEGRITY_CLOSURE.

Observer/analyzer fixes are implemented: episode/allocation serial lifecycle;
SC32 capture hash,33 stored,34 promotion,35 terminal/coalesce successor,36 safe,
37 SVB C beats,38 actual bank writes; immutable/atomic occupancy assertions;
START-inclusive/STOP-exclusive histogram window; S0 metadata replay and deferred
fill/C-only install/probe-invalidation model corrections; fail-closed final validation.
Function data/control logic unchanged, proved by exact inverse source comparison.

BOOM+sifive-cache Scala compile, full fresh v1Config Chisel/FIRRTL/firtool/CheckCombLoops,
120 offline tests (18 new), syntax/lint/patch/launcher/failure-overlay all PASS.
Only domain lint warning references pre-existing default old generated collateral.
No hardware simulation, simulator build, FST or VCD executed in this turn.

Next is one **FINAL_OPT4_VALIDATION** fresh integrated run (not a diagnostic run):

```bash
cd /data1/gzh/EC
source chipyard/env.sh
bash slowdown/run_optimization_4_svb.sh --jobs 8
```

Do not --resume or use the waveform entry. Revision mode
`corrected_svb16_integrity_v2`, 8192 failure ring, no trace. Unique missing evidence
is the allocation-scoped capture/stored/promotion/C/lower fingerprint+terminal ledger,
now included in this final run.

[Report](../../TMP/opt4_one_shot_closure_20261030_143326_a1dcf391/README.md)
· [18 answers](../../TMP/opt4_one_shot_closure_20261030_143326_a1dcf391/answers_18.md)
· [Validation](../../TMP/opt4_one_shot_closure_20261030_143326_a1dcf391/validation_result.json).
Older entries below are historical and superseded.

# Latest Opt4 SVB state — formal run completed, integrity validation failed (2026-10-30)

Run `optimization_4_svb_20261030_044205_dbaf743b` used `corrected_svb16_fst_owner_fix_v1`,
patch SHA256 `c74a132789a70cb021314c9b708f628b0fc33210f855d04c31afc53420d1ee3c` and DCache SHA256
`6b41f67629f7f557b15a0aab6f0020c8774f86f391d93369490a1bab92a486d7`.
Simulation completed normally (exit 0) at host cycle 2,449,614, with no assertion
failure or watchdog. BFS512 verified=1, checksum=43439728, COMPUTATION/END PASS.
This run completed beyond the previously observed hang; broader correctness is pending.

**Overall result FAILED / correctness FAIL / performance_valid=false.**
Data fingerprint observer reports captured405/issued390/matched_lower382/mismatches84,
while full-run SVB accounting has allocations406 and promotions/ACK/completions391.
Analyzer also rejects SC/host occupancy and depth histogram agreement. These are
observed validation failures; actual RTL data corruption versus observer/accounting
error is **UNRESOLVED**. Successful benchmark output alone does not prove backup integrity.

Protocol PASS: 7408 Release/ACK pairs, 391 SVB promotions/ACK/completions, no source
conflicts or invalid ACK, no outstanding or retained entries at end. Observed same-line
stale publications=0. SVB max occupancy16, max per-line depth5, final occupancy0.
Raw ROI=1,707,863 cycles, **not eligible for validated slowdown/gain claims**.
No RTL change, build, or simulation was performed during this result check.

[Run manifest](../../../slowdown/optimization_4_svb/runs/optimization_4_svb_20261030_044205_dbaf743b/run_manifest.json)
· [Analysis](../../../slowdown/optimization_4_svb/analysis/optimization_4_svb_20261030_044205_dbaf743b/summary.json)
· [Benchmark stdout](../../../slowdown/optimization_4_svb/runs/optimization_4_svb_20261030_044205_dbaf743b/stdout.log).
The READY/formal-run-pending entries below are historical.

# Latest Opt4 SVB state — FST root cause fixed, formal run pending (2026-10-30)

**READY_TO_RERUN_OPT4_SVB_AFTER_FST_FIX**. Final FST run
`optimization_4_svb_waveform_20261030_014511_32d45e01` ended at the watchdog,
not benchmark success. Root cause is a stale fast-line bypass lease following
resident slot replacement; global admission then blocked unrelated line
0x80008040. Original owner store completed in way0 but lease retained way1/epoch0x16.
At hang all WB/probe/MSHR/SVB resources were idle/free; ROB empty and STQ full.
Last commit core1,837,022; first bad core1,827,940. No proven ABBA resource cycle.

DCache fix: bounded identity-loss revocation; full S2/S3 way/epoch/key/package
checks; line-scoped legacy handoff conflict; capture/legacy freeze ownership
mutual exclusion. Same-line retained SVB protections through ACK remain.
Other eleven hardware inputs are byte-identical to the FST build.

Final Scala compile and fresh v1Config generation, FIRRTL/firtool/CheckCombLoops,
102 offline tests (12 directed), syntax/lint, patch identity and launcher checks
passed. No hardware simulation was run during this fix. Runtime correctness
and ROI remain **unvalidated**, and no new pure observation run is prepared.

Next user command:

```bash
cd /data1/gzh/EC
source chipyard/env.sh
bash slowdown/run_optimization_4_svb.sh --jobs 8
```

[Report and 26 answers](../../TMP/opt4_svb_fst_rootcause_fix_20261030_114113_773ea77d/README.md);
[confirmed bug](../bugs/opt4_fastline_orphaned_lease_20261030.md).
Older current/READY/UNRESOLVED entries below are historical and superseded for Opt4.

# Current Debug State

## Opt4 final FST diagnostic prepared; user execution pending (2026-10-30)

准备状态 **READY_FOR_OPT4_SVB_WAVEFORM_RUN**；硬件根因仍为 **HANG_DIAGNOSTIC_EVIDENCE_INSUFFICIENT**。本轮仅准备，不启动硬件仿真、fresh Chipyard elaboration或整机模拟器build。原失败版本功能源码、SVB16/ordering/ACK/checker/watermark/geometry/shadow和正式性能launcher默认配置保持。

新增独立入口：`bash /data1/gzh/EC/slowdown/run_optimization_4_svb_waveform_debug.sh --jobs 8`。用户执行时fresh generation/build，FST从simulator time1,500,000至终止，FST raw time约为2倍；主BOOM/Rob/LSU/DCache/SVB/WB/probe/6MSHR/TL B/C/D与safe-chain控制高覆盖。4455只读aliases和189项payload/datapath排除在每次生成物上重新核对，compiled trace声明缺失则仿真前拒绝。关键snapshot/既有稀疏事件启用与verbose无关；普通printf仍关闭。host copy对assertion保存当前eval尾边并非零退出，真正fatal关闭最后完整FST。保留8192-event/1MiB失败ring。

唯一波形留在`slowdown/optimization_4_svb/waveform_debug/<run_id>/hang.fst`，manifest记录hash，解除本次56MiB限制；估算1–20GiB，实际未测。一次性启动guard禁止自动第二次纯诊断run，无resume。用户运行结束后Codex直接读取原FST查last commit→ROB/LSU→cache gate→owner→依赖区间，闭合first-bad/wait-for graph后直接fix或证明非SVB；不凭最终snapshot确认死锁。

88项离线测试、4455/4455声明类型fixture trace审查、SVB695/695静态trace审查、native FST字面量fixture、C++/Python/Bash syntax、source identity与observation-only字节逆变换PASS。整机fresh生成/build/动态覆盖均待用户执行。本次没有新correctness或slowdown结果。见 [waveform preparation](../../TMP/opt4_svb_waveform_debug_prepare_20261030_091449_2f46ad8a/README.md)。下方为原失败证据与历史准备。

## Opt4 latest diagnostic run still hung; diagnostic printf channel disabled (2026-10-30)

状态 **HANG_DIAGNOSTIC_EVIDENCE_INSUFFICIENT**，取代下方旧 READY。用户 fresh run `optimization_4_svb_20261029_120415_a83514b4` generation/build PASS，simulation COMPLETED、exit1/result FAILED，在 `$time=2099000` 再触发 `BoomCore.sv:6915` 的 `assert(~ecWatchdogImminent)`。没有 verified/checksum/完整 ROI，不能报告性能。

已证明诊断失效原因：Makefile `PRINTF_COND=verbose&&done_reset`，emulator 的 verbose 默认为false，pinned launcher没有启用参数。全部新增 Chisel printf（含CORE/DCACHE snapshot、fast-line/WB/probe/MSHR）被关闭；8192-event/1MiB ring只有2条native fatal，无overflow/eviction。生成RTL/compiled C++/源码hash和启动参数闭合。缺失的核心证据是watchdog ownership snapshot，不能从blocked line推断fast owner，也不能据此修改global ordering gate。旧准备未核对该runtime enable；旧分析器的NO_WATCHDOG_OBSERVED为漏检。

修正仅限offline analyzer/tests：native assert按同run生成文件/行识别watchdog，缺snapshot明确判证据不足；protocol缺STOP capacity时使用manifest的16 entries，消除59条误报。当前prefix all Release/ACK6999/6999、SVB325/325/325、conflict0/invalidACK0、C generation regression0；缺footer仍FAIL。最后SVB completion1,837,183，watermark advance1,845,013，checker CANCEL183在1,969,461接受、1,969,462清除；blocked183/0x80008040持续采样到2,088,049。精确last commit和final owner状态未知，未闭合deadlock/livelock/ABBA因果环。

没有改功能RTL、watchdog、launcher参数、16-entry容量或cache opportunity；70离线测试、BOOM compile、Scala parser、native host fixture、SV lint、launcher static-check及patch/diff检查PASS。原run和硬件hash保持；本轮未elaborate/生成RTL/Verilator build/仿真。未准备新的纯观测run，当前不满足READY_TO_RERUN_OPT4_SVB_FIXED。见 [完整结果与工具修复](../../TMP/opt4_svb_hang_rootcause_fix_20261030_a83514b4_7c92e1d0/README.md)、[诊断producer gate缺陷](../bugs/opt4_hang_diagnostic_printf_gate_20261030.md)。

## Opt4 SVB pipeline hang: ready for final diagnostic run; root cause unresolved (2026-10-29)

状态 **READY_FOR_FINAL_HANG_DIAGNOSTIC_RUN**。一次 fresh build-only 预检 `optimization_4_svb_20261029_110442_61fcd0f2` 的 RTL generation 与 Verilator build 均 PASS；manifest 为 `simulation=NOT_STARTED` 且无 `SIMULATION_STARTED.json`。本轮没有执行仿真，动态 hang 根因仍未确认。

当前诊断版包含 fast-line ownership/acquire/release/owner-change 与 one-shot unrelated-line gate 证据，稀疏 WB/probe/MSHR/preservation/promotion 状态和 age 事件、watchdog 状态快照及 progress timestamps。失败时 host ring 上限 8192 events / 1 MiB，仅异常落盘；分析器在运行后生成 `last_progress.json`、`wait_for_graph.json`、`hang_rootcause.md`，未闭合依赖不会判为 confirmed cycle。

21+3+11+20+8 项离线 tests、launcher static-check、patch reverse-check、shell syntax 和 diff check PASS。下一步用户只运行一次 fresh 默认入口，不带 `--resume`：`bash /data1/gzh/EC/slowdown/run_optimization_4_svb.sh`。完整准备与旧失败证据见 [final diagnostic preparation](../../TMP/opt4_svb_hang_fix_20261029_9f3c2d71/README.md)。

### Previous dynamic evidence

状态 **HANG_ROOT_CAUSE_STILL_UNRESOLVED**。最新 run `optimization_4_svb_20261029_062302_0291a6b9` 在 `$time=2099000` 触发 BOOM `Pipeline has hung.`，exit 1；不可据此评价备份 correctness 或 slowdown。
kind15 显示 seq183 / line `0x80008040` 长时间阻塞，old seq182、watermark182、`lowerPreserved=0`；kind8 未显示 seq183 的 crossPackagePending handoff。watchdog core cycle 约 2,098,897，last watchdog counter reset 推算约 1,836,753，但精确最后 commit 未记录。
SVB occupancy/state、最终 WB/probe/MSHR/slot 状态缺失，故 true deadlock/livelock/超长 stall 未分类，也未确认 wait-for cycle。seq179 同线 SVB ReleaseData 在1,837,042发出，1,837,100收到匹配ACK，1,837,101完成；只能排除该笔promotion自身未完成。seq183 后来被 checker 以 `package_progress_timeout` 取消，水位停在182。保存的 protocol 分析另有60条 duplicate-selection错误且覆盖不完整。
源码审查发现全局单行 `svbFastLineValid` 会禁止其他任意line开始SVB fast path / crossPackagePending，直到其owner的匹配semantic write fire或epoch flush；这是可能的head-of-line进展风险，但旧run没有记录该bit/owner，不能定为根因。没有改功能RTL。该次审查时通过了 BOOM Scala compile、51项离线 tests、launcher `--static-check` 和 `git diff --check`，但尚未做Chisel elaboration、RTL生成或Verilator build。随后完成的最终诊断预检见本节顶部。旧诊断报告：[RCA review](../../TMP/opt4_svb_hang_review_20261029_180710_9000d01d/README.md)，前序诊断设计：[bounded diagnostics](../../TMP/opt4_svb_hang_fix_20261029_9f3c2d71/README.md)。死锁仍未修复或验证。

## 先前 Opt4 观测预算修复状态（已被上方 hang 诊断状态取代）

状态 **READY_TO_RERUN_OPT4_SVB_WITH_CACHE_OPPORTUNITY**：静态准备完成，无新有效性能结果。
旧run `optimization_4_svb_20261029_020351_481d089a` 确认已因采集器48MiB预算中止，
不是仍在执行；旧证据及其FAILED结论保留。kind14/15占75.27%的SC行。
本轮只改BOOM observation block/shared input-only logger及采集/分析/launcher工具。
逐事件64位counter+每4096事件抽样，kind31输出traffic-enable窗口STOP前的精确计数；
kind14/15在Opt4 budgeted模式各限1024样例，超限统计省略而不fatal。
host48MiB按39协议/8样例/1summary-footer分区，stream总上限仍56MiB；
预算耗尽继续drain，不终止workload；必需证据丢失/producer-footer不守恒/缺counter/
runtime failure或未正常exit0均禁止correctness/performance PASS。
Capture异常更新simulation=ABORTED，工具/源码hash变化拒绝旧生成物resume。

BOOM Scala compile、shared SV lint-only、57offline tests、source-scope、patch往返/
隔离index重建及launcher static-check PASS。原50MiB前缀离线路由后15,152,548bytes，
22,222条必需记录内容与顺序hash相同，省略114,620条可选记录；无footer仍判证据不完整。
本轮未执行Chisel elaboration/FIRRTL/RTL generation、Verilator model build、hardware simulation/benchmark。
本轮没有新的备份正确性或slowdown测量，不把静态通过/回放当runtime PASS。
SVB功能、source生命周期、cache geometry/checker/watermark/benchmark保持；失败恢复仍暂不实现。

用户下一步fresh执行：`bash /data1/gzh/EC/slowdown/run_optimization_4_svb.sh`，不带--resume。
报告：[观测预算修复](../../TMP/opt4_observation_budget_fix_20261029_0802a3c4/README.md)。
下方为历史状态，旧READY/FAILED不代表本版runtime结论。

## Opt4最新仿真因compact事件预算中止，结果未完成（2026-10-29）

Run `optimization_4_svb_20261029_020351_481d089a`：RTL generation/Verilator build PASS，
旧L2 observer heterogeneous Mux错误没有重现；simulation启动后在12:52:41(+08:00)报
SAFE_CHAIN_EVENT_BUDGET_EXCEEDED而被采集器提前终止，exit -9，result FAILED。
manifest simulation=STARTED是异常退出时保留的字段；当前无对应运行进程，不是仍在执行。
SC日志50,331,374bytes接近48MiB上限，164,352条，无SC_END/footer；kind15/hart0 81,121、kind14/hart0 42,582占大部分。
无verified/checksum、完整ROI/END或cache final summary，performance_valid=false，不能判断SVB备份正确或slowdown收益。
已保留前缀的partial protocol/generation ledger不代替完整运行PASS；现有日志未见assertion/fatal，不排除其他运行期问题。
当前源码/观测工具hash与run manifest核对一致。下一步先审查高频kind14/15并压缩必要证据，不能直接把预算失败当硬件正确。
本次仅只读核对/保存报告/更新状态，未改硬件、未扩大预算、未自动重跑。
报告：[Opt4预算中止状态](../../TMP/opt4_run_status_20261029_481d089a/README.md)。
下方READY和先前静态通过均为历史阶段状态；当前没有新的有效Opt4性能结果。

## Opt4 L2 observer Mux elaboration failure repaired（2026-10-29）

用户run `optimization_4_svb_20261029_013322_1d198f2e`在RTL_GENERATION阶段Chisel展开失败，
make exit2；simulation=NOT_STARTED，没有新ROI。真实异常为Scheduler.scala:697：
`can't create Mux with heterogeneous types ... QueuedRequest and ... FullRequest`。
新增observationLookup直接Mux queued/full bundle；Scala继承允许编译，Chisel运行时拒绝不同形状。
FullRequest仅额外含set，set本来已由directory.io.read.bits.set独立对齐；
修复用`Wire(new QueuedRequest(params), init = request.bits)`按字段投影，再与queue端Mux。
该写法与既有functional MSHR allocation相同，不用asUInt/asTypeOf截断。
strip观察块后的Scheduler主体逐字未变；其他8个hardware/resource文件未变。

已增加source-contract回归并更新launcher到独立新累计patch，旧run/旧报告/旧patch保留。
本次sifive_cache Scala compile、20capacity/cache+11protocol+6launcher=37offline tests、
source-scope/三patch往返/独立index重建、launcher --static-check均PASS。
本轮只做Scala编译及离线/源码/patch检查，不执行新硬件生成、Verilator build、仿真或benchmark。
展开/FIRRTL及runtime尚待用户fresh run，不能把编译通过称为展开已通过。
入口仍为`bash /data1/gzh/EC/slowdown/run_optimization_4_svb.sh`，不带--resume；
旧失败run源码/patch身份不同，不复用其生成物。
报告：[observer Mux fix](../../TMP/opt4_observer_mux_fix_20261029_df6ad056/README.md)。

## Opt4 correctness fix + SVB16 + cache opportunity prepared（2026-10-29）

状态 **READY_TO_RERUN_OPT4_SVB_WITH_CACHE_OPPORTUNITY**：仅静态准备，新版本runtime pending。
旧run `optimization_4_svb_20261028_104359_b1e0aeee`已完成exit1/verified0/checksum43440224，
ROI1720057无效；当前有效Opt3 ROI2928347/checksum43439728，Baseline1001675。
新分析器将明确FAIL正确分类，并从原compact ledger复现17次same-line/writer generation回退：
normal WB较新image发布/ACK后，旧SVB ReleaseData晚到，L2 existing metadata/data覆写会回退版本。
首例line0x80011f40：normal seq119/gen67826 C.first csr1458055、ACK1458071；
SVB seq116/gen65841 C.first1459713。旧日志未记录first-wrong byte/load，不能称全部corruption动态闭环。

新修复对所有retained SVB（含WB_WAIT）做同线普通WB/probe anti-overtake，进入arbiter前门控避免阻塞自身promotion；
capture freeze/drain并核对line/key/resident epoch；equal-seq按generation排序/安全coalesce。
source/ACK共享WB engine主体与preimage逐字不变；原7422/7422、SVB353/353/353协议结果保持独立证据。
SVBEntries默认16且参数化，仅global capacity增加，无32entry/per-line新协议/恢复设计。
shadow8、17-bin hist、全程entry守恒、snapshot/C/L2 bank hash加入；hash非密码学诊断。

L1D32KiB=256×2、L2 1MiB=1024×16、block64B、MSHR/实际geometry/checker/watermark/barrier/benchmark不改。
input-only DPI host观察actual pressure和四shadow geometry（S0 current；S1同容量双ways；S2双容量sameways；S3双容量双ways）。
random-family近似，非cycle-exact；S0 miss误差>10%禁geometry decision，无predicted ROI，最多一个候选假设。

最终Scala BOOM+sifive_cache compile、19新capacity/cache+11protocol+6launcher离线tests、native C++11 fixture、
独立SV lint、Python/Bash语法、17ownership contracts、source-scope、三patch往返/独立index重建及launcher static-check通过。
本轮没有Chisel elaboration/FIRRTL/RTL generation、Verilator model build、hardware simulation或benchmark。
无full FST/VCD或新增逐access地址trace；compact流cap56MiB，shadow仅host memory，no feedback。
新版本数据备份正确性、ROI、容量及geometry机会必须由唯一fresh run取得；8→16的独立ROI不可从组合实验拆出。
失败恢复和完整durable cache/DRAM drain仍unresolved，按用户范围暂不实现。

用户执行（不带--resume，不复用旧failed simulator，无自动retry）：
`bash /data1/gzh/EC/slowdown/run_optimization_4_svb.sh`。
报告：[Opt4 SVB16/cache delivery](../../TMP/opt4_svb_fix_capacity_cache_opportunity_20261029_b1e0aeee/README.md)。
下方旧FAIL/READY记录均为历史状态；原run、patch与Architecture用户删除保持。

## Opt4 source lifecycle runtime PASS; benchmark FAIL（2026-10-29）

用户运行 `optimization_4_svb_20261028_104359_b1e0aeee` 已结束，记录更新时间
2026-10-28 21:39:37 +08:00。RTL generation/Verilator build PASS，simulation COMPLETED，
result FAILED、exit1（tsi_fail）。当前三个硬件文件 hash 与运行 manifest 相符。
不是旧 C source assertion 再现：本次 assertion0，完整协议账本 all Release/ACK7422/7422，
SVB promotion/ACK/completion353/353/353，source conflict0、invalid ACK0、exit outstanding0，
coverage COMPLETE、protocol PASS。STOP snapshot7410/7410与全程7422/7422窗口不同。

但 GAPBS512 verified=0、parent_checksum43440224（成功 Opt3为43439728），
COMPUTATION/END FAIL。ROI1720057 vs Opt3 2928347，原始减少41.261845%，
因计算错误 performance_valid=false，不是已验证 slowdown 收益，也不证明备份数据正确。
SVB alloc/bypass369，full fallback21，max occupancy8、depth4、STOP occupancy0；
busy53900、queued26000、max safe awaiting8。first wrong data/ordering 尚未定位。

现有分析器显式 benchmark FAIL会被总状态标成UNOBSERVED_OR_PENDING，属于分类不足；
以原始FAIL日志与launcher FAILED为准，不能理解为仅缺观察。未修改该工具或硬件。
本轮只核对现有证据、hash并离线重放，summary完全一致；没有编译、生成或新仿真。
报告：[Opt4 runtime results](../../TMP/opt4_results_20261029_b1e0aeee/README.md)。
下方 READY_TO_RERUN 仅是修复交付时的历史状态，已被本次运行推进。

## Opt4 SVB Release source lifecycle 修复，静态通过、runtime pending（2026-10-28）

状态 **READY_TO_RERUN_OPT4_SVB**。旧运行 `optimization_4_svb_20261028_054141_eff5a3cd`
在 TLMonitor_50.sv:904 ($time722487) 因 C source 重用中止、exit1，无完整 ROI。
旧 generated 显示 voluntary source=6 (3 bits)。缺少 C/D observer，无法证明两笔事务的
完整 address/opcode/cycle；最后 kind8 支持 legacy crossPackage WB 紧邻失败，SVB 先发、
normal 后复用是 supported transaction identity，不能当作已观测完整 trace。
源码根因已证实：SVB 与 WB 独立 busy、共用 source，C arbiter 只覆盖多拍而不覆盖 ACK wait。

修复将 SVB 的 immutable snapshot/entry 送入共享 WritebackUnit，普通/SVB voluntary
统一 ackPending reservation，最大 outstanding promotion1，SVB 不再直接驱动 C。
D.fire/source/ReleaseAck/size/denied/corrupt/完整 CacheImage/已发完 C 全匹配后，
WB 定向 entry/key completion 才释放 WB_WAIT；正常 done 与 SVB done 分离。
MSHR completion 使用请求接受时锁存身份，保持 snapshot 不误完成 MSHR 的不变量。
补 A1–A6、retention、global C/D scoreboard、全程 compact protocol ledger 与 busy/queued/
coalescing/conflict counters；修正分析器把 harts1–4 kind16 frontend 误当 SVB 的 bug。
保持8-entry/Store fast path/各 fallback/checker/watermark/benchmark/L2及DRAM barrier。

SBT boom compile、Scala parser、Python AST、6 launcher + 11 protocol offline tests、Bash、
git diff --check、Opt4 static-check、17 source contracts 与 patch往返校验通过。
没有运行 elaboration/FIRRTL、RTL generation、Verilator build 或 hardware simulation。
备份正确性、实际 C/ACK 配对、benchmark PASS、ROI/WaitSafe/occupancy/depth/串行瓶颈待新运行；
退出 pending entry 不等于 durable drain，failure recovery 不在本轮范围。

报告与增量/累计 patch：
[Opt4 source fix](../../TMP/opt4_svb_release_source_fix_20261028_181450_7c08b4/README.md)。
必须 fresh 重新生成与编译，**不可复用旧失败 simulator，不带 --resume**：
`bash /data1/gzh/EC/slowdown/run_optimization_4_svb.sh`。
下一次只跑一次、不启用 FST/VCD、无自动重试。旧失败 evidence 与原 Opt4 patch 原样保留。

## Opt3 design and Git delivery prepared (2026-10-28)

Detailed frontend mechanism, ownership guards, clock domain, measured results,
cumulative source dependencies and user-run reproduction commands are recorded
in [Opt3 design](../../Design/opt3_checker_frontend_optimization_20261028.md).
The release preserves the exact hardware bytes of the successful Opt3 run:
source digest `dece4a35a99eb0c2ed30fb917a9f8946e9d8d53a48d7f99c36e51f15a15e1fae`.
The commit includes required Opt1/Opt2/Opt2b prerequisites and both observer
resources; it does not include local build/run/cache/tmp artifacts or unrelated
paper edits. Existing run directories, manifests and attempt guards are retained.

Release-only tooling changes correct Opt3-vs-Opt2b performance labels, validate
kind16 partitions/monotonicity, recreate missing empty output directories, and
allow `--repeat-from RUN_ID` only for the latest successful complete attempt with
the same hardware/workload identity. The default still refuses another attempt;
failed/incomplete runs cannot be bypassed. Sixteen offline regression tests,
source contracts and the static entry check passed. Offline replay of the saved
Opt3 compact trace reproduces ROI 2,928,347, 22.123464% gain vs Opt2b, COMPLETE
coverage, OBSERVED_CHECKS_PASS and 630,932 fused classifications.
The analyzer uses a versioned small summary snapshot with the original file hash
instead of requiring an untracked historical safe-chain run directory.

No new hardware generation, SBT/Scala/native/software compilation, simulation,
or benchmark is part of this release. Full drain, RUN_PROVENANCE, failure/probe
recovery and timing closure remain unresolved as described below. User command:
`bash slowdown/run_optimization_3_checker.sh --repeat-from optimization_3_checker_20261028_090640_a56794e2`.

## Opt3 measured: successful, 22.12% ROI reduction vs Opt2b (2026-10-28)

User run `optimization_3_checker_20261028_090640_a56794e2` finished with exit0/SUCCEEDED,
ROI 2,928,347 main cycles. Reduction vs Opt2b: 831,896 (22.123464%);
vs original Current: 1,806,534 (38.153736%). Baseline ratio 2.923450x.
GAPBS512 verified/checksum43439728, 315 accepted checker results,
FAIL/CANCEL/stale/held-duplicate/collision0; Stage1 L1/LSU exit drain PASS.
71-observer coverage COMPLETE; 127,466 events + 71 footers, 39,029,794 bytes,
no overflow/truncation. Independent read, hashes, kind16 conservation and
run/preparation/current-source identity match.

630,932 fused classifications; separate CLASSIFY counter zero (Opt2b 630,955).
Instruction wait 1,980,533 -> 1,346,930 local cycles; aggregate mean package
latency 23,083.33 -> 17,792.74 main cycles. Strict unsafe WaitSafe
2,296,540 -> 1,547,483; after-seal-before-done pending 2,098,732 -> 1,407,280.
312 vs 324 complete ROI package windows: aggregate, not matched causal savings.
Remaining instruction wait is 48.53% overall and 67.64% post-seal.
Full package/cache/DRAM durable drain and RUN_PROVENANCE remain unresolved;
PASS workload does not exercise failure/probe recovery.

Raw opt3_summary keeps old performance field names/comparison against Opt2.
Explicit corrected Opt3-vs-Opt2b numbers and evidence boundary:
[Opt3 results](../../TMP/opt3_results_20261028_122909_092f25bb/README.md).
Current status: **OPT3_MEASURED_MEANINGFUL_GAIN**. No new hardware run or
source change in this results analysis. Earlier runtime-pending notes below
are historical and superseded.

## Opt2b attributed; Opt3 checker patch ready for user-run validation (2026-10-28)

The first Opt3 launcher attempt stopped before build with a private SBT socket
path of 110 bytes. This was a launcher path-length guard, not an RTL/SBT
failure. `launch_optimization_3_checker.py` now allocates a one-character
private temporary leaf under `optimization_3_checker/tmp`; the socket path is
102 bytes and remains inside the sandbox. Static check and offline contracts
pass after the fix.

Opt2b GAPBS512 completed successfully with checksum `43439728` and ROI
`3,760,243` main cycles. This is `947,030` cycles (`20.118442%`) below Opt2
and `974,638` (`20.584213%`) below the original current run. Compact evidence
was complete: 67 Opt2b observers, 325 accepted results, no FAIL/CANCEL/stale/
duplicate/collision, and no event overflow or truncation. Full package/cache/
DRAM drain and `RUN_PROVENANCE` remain unresolved; the PASS workload does not
exercise failure recovery/probe behavior.

Checker attribution is now closed enough for one functional choice. Owned
checker execution consumed 3,739,176 local cycles; `WAIT_INSTRUCTION` was
1,980,533 (52.9671%), and sealed-to-done instruction wait was 1,285,131 of
1,708,940 (75.2005%). The four checker mean/p95 main-cycle latencies are
23032.22/48140, 22786.33/47632, 22406.12/45036, and 24126.88/48750.
Strict same-line cross-package Store preservation exposure is 2,296,726 main
cycles across 186 timed episodes/92 lines, but SVB depth and occupancy are not
observable in the serialized trace. SVB recovery remains open for P1 PASS/P2
FAIL, so no SVB RTL was added.

The selected and implemented next change is `CHECKER_FRONTEND_BOUND`:
accepted S2 response capture and CFI classification are fused in
`rocket/Frontend.scala`, removing the mandatory classifier state. The patch
retains one response owner, FQ hold semantics, BJL reservation only in
`WAIT_BJL`, redirect/clear handling, and held partial-RVC tail state. Kind16
four-hart cumulative classification observers and assertions were added.
Static source identity, resource closure, Python syntax, and offline contracts
pass. No Scala/SBT compile, hardware generation, Verilator build, simulation,
or benchmark was run. User entry:
`bash /data1/gzh/EC/slowdown/run_optimization_3_checker.sh`.

Status: **READY_TO_RUN_CHECKER_OPT3** (static delivery only; dynamic gain and
correctness remain pending).

## Opt2 measured; Opt2b checker handoff prepared, user run pending (2026-10-27)

This supersedes the older Opt2-runtime-pending status below. Successful user
run `optimization_2_20261027_144838_fdf571b7` exited 0, GAPBS512 verified,
checksum 43439728, ROI 4,707,273 main cycles. Opt1 was 4,706,513: +760,
essentially unchanged; Baseline 1,001,675. Opt2 allocation 82/85/82/82 is
balanced, but package count balance did not shorten checker service time.
331 results accepted; FAIL/CANCEL/collision/stale/duplicate 0. Its 53-observer
compact evidence is COMPLETE. Stage1 L1/LSU exit drain passed; full
package/cache/DRAM drain and RUN_PROVENANCE remain unresolved.

Observed same-line preservation pending is 3,241,793 main cycles; strict
unsafe 3,162,560. Unformed-result wait is 3,019,697 (93.149% of pending),
including 2,897,079 after producer seal but before exec_done. Per-package
done-to-formed is 68 main cycles; result CDC about 4. These are blocking
stages, not additive avoidable ROI loss. Opt2 ROB-critical overlap is not
observed. Old Opt1 counters/ROB overlap are kept separately, not transplanted.

Packages stream before seal: all 331 assignments precede seal. Mean
assign-to-admit is 14.93 main cycles; admit-to-done 28,893.46, p95 74,940.
Old first-active is a sampled proxy, not accepted start/issue. 650,116 checked
instructions, 49..4,999/package, weighted main CPI 14.7108 (about 7.3554 local;
one checker cycle is two main cycles). Instruction/latency correlation .9186;
top10 latency packages associate with only 7.301% of strict unsafe wait.
Broad execution cost is supported; internal dominant stall remains unknown.

SVB is NOT implemented. Capacity/depth coverage for 2/3/4 total versions and
2/4/8/16 global entries is null: serial traces hide never-issued younger
Stores. The loose opportunity upper bound is 3,162,560 waiting cycles,
not ROI gain or a capacity prediction. Concrete correctness no-go:
L2=P0 safe / SVB=P1 / L1=P2; P1 PASS then P2 FAIL must restore P1, but
current recovery lacks an SVB newest-safe selector. Existing WB reads live
L1 and uses voluntary T-to-N plus metadata clear; publishing P1 while
retaining P2 needs additional ownership/directory/ACK semantics. Sticky
failure/fail-closed is not rollback data restoration. Pre-allocation WaitSafe
fallback cannot solve failure/probe after snapshot.

The ONE functional Opt2b is Frontend same-cycle accepted FQ response to
resolved successor Icache request handoff, avoiding the fixed EMPTY issue
bubble. It saves at most one local issue cycle per eligible chunk; it does
not prove ROI gain or explain all 2.897M wait. Held response, fault/replay,
redirect, BJL resolution and sole-owner conditions remain guarded. Opt1,
Opt2 round robin and other existing dirty changes/deletions are preserved.
RocketCore and DCache additions are observation-only: per-owned-package
local priority stall counters/timestamps, sparse Frontend cumulative counts,
semantic cache writes/first blocks without cacheline bytes. 67 expected
observer instances. No new functional cache, result, watermark or CDC path.

Status: **READY_TO_RUN_OPT2B_CHECKER** means static delivery ready only.
19 offline synthetic/contract tests and the launcher's pure static identity,
path/resource checks passed (27 source files, 26 dependency projects).
Source digest: ea894cdb25f72aa1c9b818f68d33e085089919b27c2a8d3bb7a8127a2d732618.
Scala compilation, elaboration, RTL generation, native/software compilation,
Verilator, simulation and benchmark are NOT_EXECUTED in this task.

User-only entry (one fresh full GAPBS512, seed1; no FST/VCD/automatic retry):

```bash
bash /data1/gzh/EC/slowdown/run_optimization_2b.sh
```

Reports (13), incremental three-file patch, existing evidence statistics,
validation/provenance and retained synthetic fixtures:
[Opt2b delivery](../../TMP/opt2b_checker_and_multiversion_20261027_184537_3891819a/README.md).
The next run measures the functional handoff and internal checker categories
together; observed local post-seal counters are not an exact causal weighted
partition of the old 2.897M main-cycle wait. Dynamic correctness/performance,
full drain/provenance and SVB recovery remain unresolved.

## Safe-chain result-production bottleneck; Opt2 ready for user-run validation (2026-10-27)

This supersedes the older repaired-runtime-pending notes below. Successful
safe_chain_20261026_141031_5b330641 exited 0 with GAPBS512 verified/checksum
43439728 and ROI 4,706,513 main cycles. Its compact TSV is 12,633,982 bytes,
41,337 SC1 rows plus 53 observer footers, coverage COMPLETE, below all caps.
The router discarded seven nonmatching diagnostic lines (540 bytes); required
ROI/workload/host-success/L1-LSU drain markers are retained. Stage1 L1/LSU
exit drain PASS does not close full cache/package/DRAM drain or RUN_PROVENANCE.

Offline replay reproduces the saved summary exactly. Decision is
OPT2_TARGET_CHECKER_RESULT_LATENCY. All pending: 3,178,984 cycles / 1,152
entries; strictly unsafe WaitSafe: 3,100,681. Exclusive breakdown: unformed
result 2,993,080; formed-result transfer 3,720; prefix hole 87,361; registered
watermark propagation 178; post-safe release 78,275; multi-cause 16,370;
unresolved pending classification 0. Of unformed-result wait, 2,981,282 is
before exec_done, including 2,867,231 after producer seal. The dominant
waiting stage is proven; scheduling alone causing all that wait is not.

Maximum allocated missing-frontier lifetime is 50,424 (seq112, no later PASS
held behind); maximum actual later-PASS blocking is 12,772 (hole320); peak
single-hole amplification is three later PASS. Commit-ready opportunities,
per-MSHR lifetimes and exact causal/avoidable ROI cost are not continuously
observed. Remaining delta 3,704,838 minus pending gives arithmetic remainder
525,854, not proven independent lost cycles. R_IC does not consume L1 safe
watermark; result release is the common upstream of gate and safety branches.

Existing Opt2 functional delta is only ght_sch.scala and R_IC.scala:
availability-aware round-robin advance on actual package allocation, with
existing first-available fallback when a target becomes busy. Ownership,
admission, safe prefix, result CDC, cache preservation and Opt1 stay intact.
Observed checker assignments 97/94/91/50 and static low-index priority support
the policy experiment, but do not establish its isolated performance benefit
or perfect fairness. No RTL was changed in this continuation.

Prior optimization_2_20261026_202323_9020fd02 completed verilog/default builds
and observer audits, then failed before simulator Popen with missing
compact_capture. It did not run the Opt2 workload. The dependency is now
provided and checked before build/attempt guards. Explicit --resume-built-run
permits one simulation using only that verified existing build; checks old
failure/no simulation artifacts, source/software/executable/model identities,
observer hierarchy and unique guard. Old guard/manifest/build are preserved;
a new durable guard prevents any second attempt. No automatic retry.

READY_TO_RUN_OPTIMIZATION_2 means static implementation/launch/analysis ready;
Opt2 dynamic correctness and ROI gain are PENDING. All 18 mock/file tests,
Python AST, shell/diff, source/old-evidence identity, phase conservation and
actual saved-model static audits PASS. No simulation, hardware generation,
SBT, native/software/hardware compilation or benchmark was executed in this
continuation. User alone runs the dynamic command:

```bash
cd /data1/gzh/EC
./slowdown/run_optimization_2.sh \
  --resume-built-run optimization_2_20261026_202323_9020fd02
```

Reports (16), minimal patch, launcher entry, snapshots and evidence hashes:
[Opt2 final delivery](../../TMP/opt2_rootcause_final_20261026_f3d927c1/README.md).
Exact downstream commit/MSHR/set-collateral/replay metrics remain explicitly
UNOBSERVED/null in the new analyzer; no additional observation run is proposed.

## Safe-chain boot observer overflow fixed; repaired runtime pending (2026-10-26)

DIRECT_EVIDENCE: user run safe_chain_20261026_114110_076b64d2 completed
RTL generation and Verilator build (both return code 0), then failed with
SAFE_CHAIN_OBSERVER_OVERFLOW before software ROI. Its 50,000 TSV records
are exclusively KIND=10/hart=0/RESET=1, cycles 0..49,999; no START, ROI or
SC_END. The old boundary logger had ROI=true, level-sensitive RESET/START
sample and force_event=true. Boot-held RESET therefore exhausted its budget.
This supersedes older notes below saying no safe-chain simulation had started.

The repair changes RESET/START boundary logging to rising edges using two
logger-only RegNext registers. STOP uses its existing pulse. No functional
cache, Opt1, watermark, protection, statistics or workload logic changes;
no Opt2 functionality. Per-observer and byte budgets remain unchanged.
Capture retains the exact overflow observer identity, exit code and byte/count
statistics; a secondary close error no longer masks the first failure.

Old evidence and guards remain immutable. Default launcher still refuses
another simulation. A user-only explicit replacement for this known pre-ROI
failure is prepared with --retry-observer-overflow
safe_chain_20261026_114110_076b64d2. It requires a different source identity,
validates the complete old RESET prefix, and permits no further replacement
after the replacement simulation starts. No automatic retry or guard deletion.

Validation: all 35 offline tests and static identity/resource/AST/JSON/bash/diff
checks passed. The original failed run hashes, HEAD and index are preserved.
Validation in this repair is offline synthetic/static only; no Scala/native
compilation, elaboration, RTL generation, workload or simulation. Existing
generated RTL belongs to the failed old source, not the edge-logging repair.
Runtime completeness, Opt2 attribution, ROB critical-path impact,
RUN_PROVENANCE and full cache/package/DRAM drain remain UNRESOLVED.

Evidence: AI/TMP/safe_chain_boundary_overflow_fix_20261026_abd48b5a/.
User entry: slowdown/run_safe_chain_trace.sh (explicit recovery option above).

## Safe-chain generation errors fixed; hierarchy audit rechecked offline (2026-10-26)

DIRECT_EVIDENCE: existing RTL-only run safe_chain_rtl_20261026_090815_3f50a7ca
completed its make verilog command with return code 0. Its final FAILED status
came from the old observer audit counting KIND text in module definitions.
One deduplicated Rocket definition contains KIND=6; four checker Rocket
instances give four KIND=6 observers. The prior explanation calling KIND=6
a single main-core observer was incorrect and is superseded by this evidence.

The audit now joins the full TestHarness instance hierarchy to KIND parameters
in each parent's emitted RTL. Exact counts remain 53 total, with four each
for KIND=3/4/5/6 and 32 for KIND=9. Missing checkers, unreachable definition
decoys, duplicate hierarchy paths, unavailable hierarchy, mismatched RTL and
output-bearing logger resources are rejected. Existing generated RTL passes
offline re-audit; all 21 recorded source hashes match current preparation
(source digest 4dd7c81e158619d10778d13e36a9fd8615fb43985e42ca88fe03abb2f1bc1c4d).

Earlier Bool padding, unknown-width getWidth, and whole-IO dontTouch failures
are addressed by the existing fixed UInt observation sinks and removal of the
unnecessary annotation. No hardware source was changed in this continuation.
The observation-only review patch was reconstructed in memory from the saved
pre-observation delta; 17 prior Opt1 input hashes and all marked source
boundaries match. Its stale top-level hash is now checked by identity preflight.

The later RTL-only run safe_chain_rtl_20261026_094812_33ad715f has no visible
live process, no final return code and a stale IN_PROGRESS manifest. It is
incomplete evidence, not a passing run. Original manifests/logs are retained.
No new generation, Verilator build, workload or simulation was started in
this continuation. User-only entry: slowdown/run_safe_chain_trace.sh.
Runtime correctness, Opt2 attribution, RUN_PROVENANCE and full cache/package/
DRAM drain remain UNRESOLVED. No Opt2 functionality or Git index change.

Evidence: AI/TMP/safe_chain_error_fix_20261026_0b61333e/.

## Safe-chain compact observation prepared; new run NOT executed (2026-10-25)

Current + Opt1 now has OBSERVATION_ONLY safe-chain instrumentation. No Opt2
functional change is included. Source fingerprint:
912e879e81823ee4541a8074f7f23f4f8556e6286764a04301925b9de3502ba7.
The earlier Opt1 user run optimization_1_20261025_123241_e7c5f139 succeeded:
ROI 4,706,513 cycles versus Original Current 4,734,881 and Baseline 1,001,675;
observed improvement is 28,368 cycles (0.599128%). Older dynamic-not-run notes
below are history for their original preparation states.

User-only entry: /data1/gzh/EC/slowdown/run_safe_chain_trace.sh.
No launcher mode, SBT, elaboration, hardware/software/native compilation or
simulation was executed in this preparation. Normal nontrace Verilator build;
no full FST/VCD, no +verbose. The logger routes event rows through stderr apart
from byte-stream UART stdout into one bounded TSV (96 MiB); diagnostic logs
are capped at 8 MiB each. It captures traffic START through exit, then clips
by unchanged software rdcycle ROI. 53 observer count/episode/footer checks,
exact-tag checkpoint, main-clock time alignment and one-attempt guard prevent
silent partial attribution or automatic expensive retries.

Offline synthetic checks: 19 passed. Static source review confirms existing
Opt1 functional code is unchanged outside marked observation blocks; generated
RTL/compiler/runtime behavior remains unverified. Analysis classifies result
formation/mandatory cleanup/CDC/L1 acceptance separately from prefix holes,
registered watermark propagation and post-safe release. Decision remains
ROOT_CAUSE_STILL_UNRESOLVED until complete future evidence. Activity is not
ROB critical-path loss, avoidable cycles or a mechanism slowdown estimate.
RUN_PROVENANCE and full cache/package/DRAM drain remain UNRESOLVED.

Reports: AI/TMP/safe_chain_targeted_trace_20261025_baab7979/.
Sealed launcher/schema/source/resource inputs: slowdown/safe_chain/manifests/.
Original evidence, user deletion docs/paper_design_reference.typ, untracked
DOC/Figure and the Git index are preserved. No staging/commit/push/cleanup.

## Optimization 1 trace gate remediation; dynamic validation not run (2026-10-25)

The user-run attempt `optimization_1_20261025_083906_1d2467bb` completed RTL
generation but intentionally stopped before Verilator build when the generated
RTL trace gate reported missing aliases. Source-to-generated review separated
the report into 13 false negatives from CIRCT instance flattening
(`ghm_slowdown_opt1_*`) and seven actual DCache direct aliases that disappeared
before emitted FIRRTL. The seven probes now use observation-only `WireInit`
aliases before `dontTouch`; generated RTL and compiled-trace audits now match a
complete flattened leaf with only an optional numeric Vec suffix. The previous
failed build/run evidence is retained. The repair passed 16 synthetic
parser/contract/ledger tests, Python AST, JSON, bash syntax, and diff checks.
The repaired source has not been regenerated, built, or simulated.

## Optimization 1 candidate prepared; dynamic validation not run (2026-10-24)

Decision: `IMPLEMENT_SET_FREEZE_OPTIMIZATION_FIRST`. One functional DCache
change admits qualified ordinary different-tag loads to hit-only lookup during
unsafe WaitSafe; misses nack with MSHR valid/fire suppressed. Existing snapshot
drain, watermark, ACK, barrier and recovery conditions remain. GHM, R_IC and
InclusiveCache changes are observation aliases only. This candidate has NOT
been elaborated, compiled or simulated; the sealed Stage 3 results below apply
to their original source/run, not to these new source bytes.

Design/evidence: `AI/TMP/low_sim_optimization_plan_20261024_e5076be7/` and
`slowdown/optimization_1/analysis/design/`. Persistent preparation and static
checks: `slowdown/optimization_1/manifests/`. User-only Verilator entry:
`/data1/gzh/EC/slowdown/run_optimization_1.sh`. No launcher mode was executed
in this preparation. `RUN_PROVENANCE=UNRESOLVED` and full package/cache/DRAM
drain remain unresolved. Complete offline analysis of the first run before
considering another hardware version.

## Stage 3 closure evidence reviewed (2026-10-21)

The sealed run `AI/TMP/stage3_runs/run_qx63gyhc/` passed the final evidence
review. HEAD, 11,480 source hashes, four Stage 3 script hashes, 40 workload
source hashes, 3,077 generated model files, simulator identity, phase seals and
upstream tokens all match. BUILD/DIRECTED/SYSTEM are PASS; all 19 directed CASE
markers are unique and PASS, with one `[END] status=PASS` and zero preservation
correctness errors. System Stage 1, Stage 2 and Stage 3 scoreboards, progress,
software report and exit drain are all PASS. The metadata-clear witness now has
`PRESERVE_DONE -> CLEAR_CHECK fire=1` with all S1/S2 and conflict fields zero,
followed by EFFECT, TERMINAL and RELEASE; the prior watchdog path is absent.

```ini
STAGE3_DYNAMIC_VALIDATION=PASS
STAGE1_REGRESSION=NONE
STAGE2_REGRESSION=NONE
STAGE3_INVARIANTS=PASS
ALL_DIRECTED_CASES=PASS
OUTSTANDING_TRANSACTIONS=NONE
STAGE3_STATUS=CLOSED
STAGE3_CLOSURE=YES
NEXT_ACTION=MAINTAIN_STAGE3_CLOSED_STATUS
```

The original run summary remains an immutable pre-review record with
`STAGE3_CLOSURE=NO`. Full checklist, fields and independent provenance audit:
[Stage 3 closure evidence review](../history/reports/stage3_closure_evidence_20261021.md)
and `AI/TMP/stage3_closure_review_20261021_bjm5zr2m/`.

## 最新终端错误：workload符号表解析已修复，等待重跑（2026-10-20）

用户run_jp4_qkjb停在software manifest preparation，未进入hardware build/directed/system。
根因是上轮新增size读取把GNU objdump符号的可选`.hidden`当作十六进制size；实际新ELF
stage1_workload_2Raas2GM已编译，timer_flags为aligned64/size256，控制域布局没有失败。
stage1_workload.py统一解析size与visibility，_exit范围也复用解析结果；新增3项offline
parser回归覆盖default/hidden/protected/internal、flag变体与坏size拒绝。实际ELF261符号
（含5个hidden）、源码snapshot、AMO/HTIF/_exit/LOAD头只读检查PASS；Python/shell/diff PASS。
本轮未准备/转换软件、build、生成、仿真或执行runner；未改C/Scala/harness和任何协议。
旧失败run与manifest保留；仍使用同一Stage3单入口自动准备变更软件并重新验证。
STATIC_REVIEW=PASS；READY_FOR_DYNAMIC_VALIDATION=YES；STAGE3_CLOSURE=NO。
详见 [符号visibility解析RCA与验证](../history/reports/stage3_workload_symbol_parser_20261020.md)。

## 当前：Stage 3 timer/trap validation 环已定位并以控制数据隔离切断（2026-10-20）

原布局的条件环已确认 REACHABLE：旧 run_zr8umvan 的 hart2 完成 seq2 PASS 后，
result queue 仍 valid1/ready0；timer trap(mcause=0x8000000000000007)阻止 context_idle。
handler PC800006bc 读取 timer_flags[2]=80007e48，与 BOOM timer_flags[0] 的
unsafe writer0/genb920/seq2 共用 line80007e40，watermark1。当前新 gate 若应用到
该状态，会使 handler 等 seq2 validation，而 retained PASS 的 handoff 又等 handler xRET。
不是“checker尚未算出PASS”，也不能以 close ACK 或释放MSHR代替validation。

最小修复仅2个生产C/header文件：timer counter 改为每hart独占、对齐64B的完整block，
保持原计数/中断/CSR行为。handler其他物理访问为private管理栈和CLINT MMIO；RSUSL/
RocketCore原有异常SP/GP恢复保证local trap使用管理栈，replay内存访问仍由LSL服务。
BOOT BSS初始化在seq0；BOOM后续只写slot0，因此Rocket的slot1..3不带BOOM unsafe key。
未修改任何Scala/hardware、CacheImage、Rocket、L2 gate、validation或preservation逻辑。

2个必要provenance脚本增量：stage1_workload检查实际ELF timer_flags对齐64/大小256并
记录domain；Stage3原单入口在用户下次执行时自动准备已变更软件，保留旧manifest，
之后再capture/验证输入。旧ELF/旧system结果不能替代新软件证据；本轮没有执行准备。

STATIC_REVIEW=PASS；KNOWN_DEADLOCK_CYCLES=NONE（本轮已知timer unsafe-transfer环）；
READY_FOR_DYNAMIC_VALIDATION=YES；STAGE3_STATUS=PATCHED_PENDING_REBUILD；STAGE3_CLOSURE=NO。
RISC-V C syntax-only、Python AST、shell syntax、mock-only provenance与git diff检查PASS；
1463个Scala源码hash逐项未变，directed fixture未变。未build、typecheck、生成、Verilator、
simulation或runner。该静态排除针对当前v1Config/Test timer路径，不冒充任意软件/全局fairness证明。
详见 [具体wait graph、地址域、修复与边界](../history/reports/stage3_timer_control_domain_20261020.md)。
证据/本轮preimages：`AI/TMP/stage3_timer_wait_ecs_zsrg/`；全部旧run保留。

## 历史：Stage 3 收缩为 lineage-unaware Rocket；L2 gate 已实现，系统 progress 当时未闭合（2026-10-20）

架构固定为 BLOCK_SPECULATIVE_TRANSFER_TO_LINEAGE_UNAWARE_ROCKET。精确撤回 Rocket
DCache/HellaCache 上轮 CacheImage 功能扩展，两文件与扩展前副本一致；BOOM 恢复本地
imageSerial，保留 CacheImage/同包与 preservation 语义，只新增 coherent endpoint marker。
L2 使用 marker+真实 remapped source range 分类，默认未知 client unaware。在 MSHR/
Scheduler->SourceD 阻止 unsafe Get/Acquire/old-value AMO response，停放原 request/seq，
释放 MSHR/set/D 资源；晚发现 ProbeAckData unsafe 时先完成 C/E/bank tail、仅提交 probe
ownership 变化。validation 后空闲 set 重新 allocation/lookup，禁止复用旧 directory snapshot。
独立 client wait 使用已有 package-close 请求，但 peer-only wait 不冻结 SourceC。

替换旧 coherent_peer_lineage_roundtrip 为 lineage_unaware_peer_waits_validation；严格
19/19，原18项保留，覆盖早/晚park、同set BOOM、other-set preservation/ACK、验证后
fresh retry、普通BASE Release/ProbeAckData。fixture主动注入watermark，不证明system进展。

静态语法/scope/table检查 PASS（原9状态/72行及assertion helper未改，18 allowed/54 forbidden、
6 flush edges），未运行任何 hardware build、Scala typecheck、RTL生成、Verilator、runner或simulation。
完整 STATIC_REVIEW=FAIL：尚不能排除 runtime timer handler 等 safe Grant -> validation 等
checker -> checker context_idle 等 trap xRET -> handler 的条件等待环。源码证明这些依赖存在，
旧run证明shared timer行曾被unsafe交给普通Rocket；新排序下是否阻塞负责该seq/更早seq的checker
尚未证明。释放L2资源/package close ACK不能替代PASS或抹掉这个缺口。

READY_FOR_DYNAMIC_VALIDATION=NO；STAGE3_STATUS=STATIC_PROGRESS_REVIEW_UNRESOLVED；
STAGE3_CLOSURE=NO。生产8文件（其中2个仅撤回），无新增Rocket store/AMO/generation功能。
详见 [收缩架构、完整静态审计及剩余progress阻塞](../history/reports/stage3_lineage_unaware_boundary_20261020.md)。
证据 `AI/TMP/stage3_unaware_boundary_5be1nixk/`；旧run/报告/preimages均保留。

## 历史（已被下述收缩架构取代）：Stage 3 provenance-aware Rocket 提案（2026-10-20）

用户最新 `run_zr8umvan` 的 BUILD/DIRECTED 已 PASS，SYSTEM 因 little core2
watchdog FAIL；不是已观测错误 data。error_samples 为空、重复/过早 release 错误为0，
Stage2 checker PASS，checkpoint105/105、victim807/807闭合；15个缺 effect token
仍属于 abort 时 outstanding，不能宣称永久丢失。未单独修改 MAIN_CHECKER/EXIT 项。

三方同 workload event/FST 比较：旧 d223 的 reference first bad=b90dc；当前更早
cec7/PC80000844/addr80056184未完成。直接 causal line=80007e40（timer_flags），
FST1460779 对应 DCache cycle=b24af，较旧 reference 早27693周期。
`PREVIOUS_FIX_EFFECTIVE=PARTIAL`，旧失败点未跨过、system进度未推进。当前生成
Scheduler已含上一轮双C路径same-package bypass，并有6次真实newer-generation
supersede，但 ordinary Rocket返回BASE key，使resident writer0/seq2/genb920在
watermark1下被probeNeedsGate阻塞。源source28/hart1的dirty ProbeAckData等待validation；
source24/hart2的Acquire不能完成，共享C进而卡住BOOM writeback、set86 installDrain，
MSHR3已收到Grant但cec7无法install/effect/terminal/release。baseline同PC/addr成功，
旧run cec7也成功，当前不是d223复发。

本轮实现blocking coherent Rocket的C/D CacheImage协商、slot key安装/实际buffered
store更新/双C路径返回，普通修改继承imported lineage及validation debt并取更大gen；
BOOM同lineage重新取得ownership后跳过peer已使用gen。CacheImage helper统一
writer+seq package定义；L1入场补writer比较，L2两条C路径共用supersede helper。
精确current receipt仍在key改变时撤销，不能继承成outer权限。新增有限peer/probe日志。
MSHR/Directory/L2Preservation/SourceA/C/D/SinkC/D/CacheCork/InclusiveCache本轮功能不变。

新增协议CASE `coherent_peer_lineage_roundtrip`，覆盖unsafe Grant->普通peer连续
变更->ReleaseData/ProbeAckData->validation前无outer写->验证后durable flush；原18项
保留，runner/checker清单改为严格19/19。它验证生产helper和L2管线，不实例化整个Rocket
DCache，slot/refill/store wiring仍待system。源/fixture identity变化使旧BUILD与下游失效。

STATIC_REVIEW=PASS；9状态/原断言表及19 CASE映射、Python/shell语法、Scala parser-only、
C++声明桩syntax、assignment/handshake/receipt review及git diff --check通过。
未执行Scala类型编译、elaboration、RTL生成、Verilator、模型编译链接、runner或simulation。
`STAGE3_STATUS=PATCHED_PENDING_REBUILD`，`STAGE3_CLOSURE=NO`；Stage2/3 invariant静态保留，
所有Stage3 blocker清单已审查，未发现其他有证据的等待环，不等于动态closure证明。
证据 `AI/TMP/stage3_system_closure_audit_bo5r1ef7/`，旧run与预存改动保留。
详见 [system closure审计与coherent peer根因](../history/reports/stage3_system_lineage_closure_audit_20261020.md)。

## 当前：Stage 3 CASE 10 cleanup 缺失 inner ownership release，静态修复待重建（2026-10-20）

用户 run `AI/TMP/stage3_runs/run_igda2knt/` 的 CASE 10 主体已经完成并打印 PASS：
同包 gen=4/seq=2 ReleaseData 在不新增 preservation Put 的前提下完成 bank commit，
随后 Get 返回新 key/data。失败发生在 cleanup flush：flush 已接受，MSHR lookup 命中
dirty TRUNK、clients=1 的 resident，向唯一 coherent client 发 Probe；host 没有应答，
pendingProbes=1、MSHR 仍 active。flush 尚未发 outer Release/ReleaseAck，也没有目录
invalidate。根因是 readback Acquire 重新取得 client ownership 后，fixture 直接
flush，没有 ProbeAck responder 或先行 Release。不是 preservation/validation FSM 卡死。

fixture 现在在读回校验后用真实 clean `Release(TtoN)` 归还 client ownership，再
执行现有 cleanup validation 与 flush；确认 durable outer bytes 等于 Q3 后才打印
CASE PASS。未增加 outer Put、未提前 validation，也未更改 Stage3 safety gate。
增加 MSHR flush-only observation bundle 与最小 probe/release/commit event log，
timeout 输出 `FLUSH_BLOCKER`、MSHR/key/validation/preservation/Probe/Release/commit 状态；
这些输出不连接协议控制。MSHR/Scheduler 删除新增 diagnostic 后逐字还原本轮之前
源码；ordinary transition table/assertions未动。

run HEAD、相关八份生产源码、fixture/生成器副本及保存 RTL hash 与失败 run provenance
一致。静态 transition table 18 allowed/54 forbidden/9 implicit self，独立 flush 域
6 条，18 CASE 清单通过。Python AST、shell syntax、保存端口宽度声明桩下 C++ syntax、
diagnostic assignment、protocol-source-with-observations-removed、`git diff --check`
均 PASS。未运行 Scala compile/elaboration、RTL generation、Verilator、模型构建、runner
或 simulation；新 Chisel diagnostic bundle 尚未验证编译/生成。

`STAGE3_STATUS=PATCHED_PENDING_REBUILD`、`STAGE3_CLOSURE=NO`。directed 失败 run 与
原有 Stage1/2 closure、用户改动全部保留。详见
[`CASE 10 flush RCA 与 ownership cleanup`](../history/reports/stage3_case10_flush_ownership_20261020.md)。

## 当前：Stage 3 host drain 孤儿 Probe 已修，硬件 liveness 静态审计完成（2026-10-19）

最新用户现场 `AI/TMP/stage3_runs/run_ybxmr7og/`：SOURCE_PROVENANCE/BUILD PASS，
DIRECTED FAIL（same_line_safe_dirty_wait_ack，timeout: drain），SYSTEM NOT_RUN。
17行 trace 显示首个合法 Acquire 的 Grant/目录 commit/MSHR free均已完成；P 的
ReleaseData、Q到达、preservation pending均尚未发生。本轮不把这次 host idle
timeout误判为已经进入 checkpoint drain，也不重新调查已修的 capability/flush表。

确定首个坏事件是 reset 的 cycle0，host错误记录 B(addr80000000)；上轮新增
pendingProbes账本漏了reset门控，硬件同步reset后取消状态，host却永久等不存在的
ProbeAck。现统一禁止 reset期所有host握手/计数/queue/stall-history记账，reset
仍正常打时钟、host valid/ready拉低；不清活跃账本、不删除drain、不改timeout。
reset后检查零事务状态，任何until超时先打印完整 DRAIN_BLOCKER snapshot。

逐项审查硬件capture predicate：SourceD idle、SourceC idle、已准入SinkC bank
queue空、selected MSHR probe/refill quiescence。九类用户指定路径以及ProbeAckData、
trusted A写均已静态审计，未发现其他有源码证据的内部等待环，未改硬件功能gate。
仅增L2Preservation/SourceD/C观察输出、Scheduler诊断bundle/有限事件日志及fixture
透出；MSHR/SinkC/Directory不变。原全局pipeline收尾与局部selected quiescence保留。

`STATIC_REVIEW=PASS`、`DRAIN_LIVENESS_AUDIT=PASS`、`STAGE3_STATUS=PATCHED_PENDING_REBUILD`、
`STAGE3_CLOSURE=NO`。仅源码/日志/旧生成物/纯静态Python、shell syntax、diff及assignment
检查；未编译/生成/elaborate/FIRRTL/Verilator/仿真/测试，未执行runner。活性结论
仍要求合法peer最终完成握手/validation，不声称任意永久背压可自动解除。
源码与fixture identity改变使旧BUILD及下游失效，用户仍使用原无参单入口。

详见 [drain RCA、双重predicate和全部入口等待图](../history/reports/stage3_drain_liveness_audit_20261019.md)。
本轮证据 `AI/TMP/stage3_drain_audit_99ciq6nn/`；旧run与Stage1/2 closure证据保留。

## 历史：Stage 3 第二次动态 flush 断言域修复，配置及 18 CASE 静态审计完成（2026-10-19）

最新用户现场 `AI/TMP/stage3_runs/run_e23qwk6h/`：SOURCE_PROVENANCE/BUILD PASS，
DIRECTED FAIL、SYSTEM NOT_RUN。生成模型明确 m=true，Get(b) 已完成、第一 CASE
与 duplicate ACK CASE 已通过；上一轮 fixture capability 修复生效，不再调查 m=false。
当前首错在 `full_provenance_collision` 开始的 cleanup：真实 flush(b) 命中 clean
TIP（clients=0、dirty=0、BASE），clean Release txn8 与匹配 ACK 完成，目录最终
提交 INVALID 时触发原普通表 `TIP->INVALID, p=false`；fatal generated RTL:12988。

根因分类 C：Stage3 把目录 invalidate 延迟到 ACK 后，但普通 transition table
仍假定 flush 走 eviction 域。本轮为 control 最终提交建立严格 FLUSH_COMMIT 域，
要求有效 hit、issued/sent/matching ACK、清空全部 ownership/dirty/provenance；
普通 72 条表项及其 assertion helper、eviction 检查原样保留，未改协议数据流/gate。
同因覆盖六种 reachable resident 到 INVALID（当前 TIP 加五种潜在状态）。
静态枚举九状态、18 ordinary allowed/54 forbidden/9 implicit self；18 CASE 全部
人工生命周期审计并核查路径族，未发现其他已证实的普通非法 transition 根因。
补齐 fixture inner B.address 的生产 restoreAddress 边界；增加 C/Probe 生命周期、
严格 drain、MSHR/flush/cleanup/validation/preservation 有限事件诊断。

只完成源码修复与静态 Python/表展开、shell syntax、assignment/use、差异及证据
检查；未编译/生成/elaboration/FIRRTL/Verilator/仿真/测试，未执行 runner。
`STAGE3_STATUS=PATCHED_PENDING_REBUILD`、`STAGE3_CLOSURE=NO`。Stage1/2 旧 closure
保留为原树证据；fresh directed/system 与新增断言/日志的编译效果仍待验证。
原无参 runner 因 MSHR/Scheduler/fixture identity 改变自动使旧 BUILD/下游失效。

详见 [第二次失败 RCA、全配置与 18 CASE 审计](../history/reports/stage3_tip_invalid_config_audit_20261019.md)、
[完整 transition 矩阵](../history/reports/stage3_transition_matrix_20261019.md)。
证据目录 `AI/TMP/stage3_config_audit_quv22_u8/`；旧 run 未改写或删除。

## 历史：Stage 3 首次动态 assertion 已定位并修复 fixture，待重建（2026-10-19）

最新用户现场 `AI/TMP/stage3_runs/run_1_d9fdyq/`：`SOURCE_PROVENANCE=PASS`、
`BUILD=PASS`、`DIRECTED=FAIL`、`SYSTEM=NOT_RUN`。旧编译/SerialTL echo 阻塞已越过。
首错为普通 `abc_mshrs_0` 在目录最终调度时触发 `S_INVALID -> S_TIP` assertion，
generated `Stage3Harness.v:12527`，Verilator 时间 `[254]`。

根因分类 C：fixture 将 source 1 声明为 Probe client，却用它发 uncached Get/Put，
导致静态 cfg `(p,c,m,r,f)=(false,true,false,false,true)` 中 m 错为 false。
第一 CASE `same_line_safe_dirty_wait_ack` 收尾的 Get(b) miss，经真实 victim ACK 和
正常 refill 得到 clean TIP；`before=INVALID` 来自 tag miss，不是 MSHR reset 状态。
Q 的 seq=1 此时已 validation；没有 ReleaseAck/completion 直接恢复 TIP 的赋值。
保存 trace 无波形/逐事件周期戳，中间握手顺序由同源 RTL 和确定刺激推出。

已仅修 Stage3 两份 fixture：coherent source 0，non-probe sources `[1,3)`；
两个并发 Get 改用 1/2，消除旧 host 未等 D 就排入相同 source 第二请求的复用风险。
增加 inner A→D source 生命周期检查、带周期并立即 flush 的 CASE_BEGIN/A/D 日志。
18 CASE 与 checker 不变，生产 MSHR、transition table、全部 assertion 和
preservation/validation/Acquire/目录 gate 本轮未改。25 份相关生产文件与保存
inputs.json 同源，且本轮 hash 不变；两份 fixture 修复前也与 run 副本逐字相同。

静态 assignment/use、72 个不同状态 pair、18 CASE 清单及 diff/语法检查通过；
未执行 build、编译、生成/elaboration/FIRRTL/Verilator、simulation、runner 或测试。
当前 `STAGE3_STATUS=PATCHED_PENDING_REBUILD`，`STAGE3_CLOSURE=NO`；动态修复效果与
当前 Stage1/Stage2 SYSTEM 回归均待验证。原 closure/用户改动/失败现场全部保留。
证据 `AI/TMP/stage3_invalid_tip_fix_3slovmd6/`；详见
[首次动态 assertion RCA 与状态机审查](../history/reports/stage3_invalid_tip_fixture_fix_20261019.md)。

用户继续使用现有无参单入口 `AI/Debug/scripts/stage3/stage3_run.sh`。fixture identity
变化自动使旧 BUILD 及下游失效；runner 在新目录 BUILD→DIRECTED→SYSTEM，失败即停。
本轮未执行入口，不允许复用旧生成物验证新 fixture。

## 历史：Stage 3 SerialTL echo 缺口已修，待重建（2026-10-19）

`STAGE3_STATUS=PATCHED_PENDING_REBUILD`，`STAGE3_CLOSURE=NO`。
最新用户现场 `AI/TMP/stage3_runs/run_vsb0kdix/` 已越过旧 SinkC Scala 编译错误，
Stage3Harness 生成、lint、模型编译均 exit0；BUILD 随后的整机 FIRRTL 检查失败。
原日志有3处 RefNotInitialized：TLSerdesser 的 D、TLSerdesser_1 的 A/C 均缺
`echo.cache_preserve_txn`。make Error 1 / runner exit2 为后续汇总；11条日志诊断
不代表11个独立根因。annotation 的130 pin 数量正常，不是本次阻塞。

已修复 Serdes.scala 的 merged packet echo 编码/解码，A/C/D 透传原身份、B/E 的
无效 echo payload 确定置零。静态继续追踪原 FIRRTL 发现实际 harness TLRAM/TLROM_1
也缺返回 echo；因原串行格式未读取它而未在此次错误清单出现，现一并补齐。
TLRAM echo 与 source/size 按相同 A→R→D enable 寄存并按相同响应级选择，
ROM 在原组合响应上透传。未修改 preservation FSM、ACK 匹配或写入 gate。
shared first_error 摘要现在优先显示 PassExceptions 后的具体错误，批量报告仍保留。

修复前三份源码均与该 run 的 inputs.json hash 一致；现场和旧产物保持原样。
仅做 Python AST、shell syntax、git diff --check 和日志/源码/旧 FIRRTL 静态审查。
本轮没有执行 build、Scala compile、elaboration、RTL generation、FIRRTL、Verilator、
simulation、regression、runner 或单元测试；新序列化格式及端到端功能仍待验证。
证据目录 `AI/TMP/stage3_serdes_echo_fix_v5355woc/`；
详见 [SerialTL echo 修复](../history/reports/stage3_serdes_echo_fix_20261019.md)。

用户仍只执行无参 `AI/Debug/scripts/stage3/stage3_run.sh`；source/helper identity 改变
会自动使 BUILD 和下游失效，在新目录重建。DIRECTED/SYSTEM 本次用户运行均 NOT_RUN，
没有有效的整阶段 BUILD seal；不得复用其局部 module PASS 或旧模型。

## 历史：Stage 3 编译 API 错误已修，批量诊断就绪，待重建（2026-10-18）

`STAGE3_STATUS=PATCHED_PENDING_REBUILD`，`STAGE3_CLOSURE=NO`。
用户实际运行 `AI/TMP/stage3_runs/run_5hyf3lau/` 在 BUILD 的 Scala compile 失败，
完整 module.emit.log 只有一个真实编译错误：SinkC.scala:74 找不到 chiselTypeOf。
该文件的修复前 hash 与该 run 的 inputs.json 一致；症状不是 preservation 动态失败。
已将该处改为明确的 `chisel3.chiselTypeOf`，没有修改协议状态机或 gate。
命令失败/超时及退出0但 module 生成不完整时，runner 现在打印并保存全部不同日志
诊断到 `<log>.errors.out/json`；failure.json 和固定 summary 保留原始码、诊断数和路径。
计数是日志诊断数，不是独立根因数；仍任一阶段失败即停止，下游 NOT_RUN。
见 [编译修复与诊断交接](../history/reports/stage3_compile_diagnostics_20261018.md)。

唯一入口为 `AI/Debug/scripts/stage3/stage3_run.sh`，无需参数或 STAGE3_ROOT。
自动 BUILD → DIRECTED → SYSTEM，失败立即停止；每次新建 immutable run，
完整验证来源、模型/证据哈希、checker 和上游依赖后才复用已完成阶段。
旧人工 mode 与 stage3_build_and_run.sh 已移除；runner 不修改/删除自身或旧证据。

本轮仅修复一个 Scala API 名称引用并修改运行器诊断、状态和文档，未改 Stage3 preservation protocol。
未执行编译、生成/elaboration、Verilator、simulation、regression 或 runner 测试。
只做 Python AST、shell syntax、git diff --check 与静态 review；静态 PASS 不等于硬件 PASS。

协议的 checkpoint/receipt、victim ACK gate、ProbeAckData gate、18 CASE 保持原样。
当前 source/runner identity 已改变，旧失败 BUILD 不可复用；原单一命令自动新建目录、
重建后再定向/整机验证。本轮未执行该命令，编译与全部动态 gate 仍 unresolved。
见 [单入口交接](../history/reports/stage3_runner_20261018.md)、
[协议静态交接](../history/reports/stage3_static_20261018.md) 与
[设计及唯一命令](../../Design/stage3_l2_preservation_20261018.md)。
Stage1/Stage2 旧 closure 保留为原树证据，当前硬件仍待 fresh validation。
本轮不运行验证入口、不清理旧 run、不 reset、同步或提交工作区。

## 当前：Stage 2 L1 preservation 已关闭（2026-10-18）

`STAGE2_STATUS=CLOSED`，`NEXT_SIM_REQUIRED=NO`，`KNOWN_STATIC_CORRECTNESS_BLOCKERS=0`，
`CODE_CHANGES=NONE`。最新真实 run 是 `AI/TMP/stage2_validation_agciqdp_/`：
build/directed/system 三份 status 均 PASS/exit0；33 pin wiring、lint、完整构建和
三次 provenance 验证通过；10 个定向 CASE 各一次，独立 effect/denied Put/AMO 对照完整。
旧 d5wr10l1 的 epoch 阻塞已在该次运行消失，不再作为当前待重建故障。

本轮重新比对 run 记录的 11479 个 source、16 个 scripts 和完整清单，全部匹配当前
文件；HEAD/workload manifest/fixture 副本也匹配。审计证据
`AI/TMP/stage2_evidence_audit_bbmws5qc/{identity.audit.json,inventory.audit.json}`。
未重新 hash 整个 generated/binary/2.7GB trace，采用运行时原 provenance/artifact gate；
不混同本轮 source 检查和完整产物重验。

整机 Stage2 checker：errors=[]、missing_coverage=[]，PRESERVE/receipt/done 各1216；
MODIFY144225、NORMAL135486、REPLAY8739、AMO90、SAME_PACKAGE95072、IMPORT9415。
实际 trace 保存了 safe/lower0 阻塞→L2 commit→准确 ACK→done→refill→新包 replay effect
因果链。复用本次原 Stage1 checker 的全 PASS 与真实 exit drain 全零；Stage1 保持已关闭。

没有发现新 RTL correctness bug，不制造功能/checker/trace 修改。receipt+probe revoke
和 receipt+refill 的精确同拍场景由 RTL next-state、owner/drain、epoch/full-key 和
写口仲裁静态严格保护，归类为 `NON_BLOCKING_COVERAGE_GAP`；长期公平性属于
`OUT_OF_SCOPE_FOR_STAGE2`，不是 L1 preservation safety blocker。
现有 checker 的边界包括：LOWER_COMMIT/ACK 按完整 key 关联而非独立地址/source、safe
由 RTL trace 提供而独立时序检查来自定向 stimulus、refill row 依赖生产断言和原 owner
checker。matching done+probe revoke / refill+done 精确同拍无独立 CASE，但由静态 next-state
和 owner/drain 互锁严格推出；任意压力公平性属于 Stage 2 范围外。这些边界不伪报覆盖，
也不据此推断已经存在功能缺陷。

完整 closure checklist、race 分类、producer matrix 和实际动态 evidence 见
[完整11节审计报告](../history/reports/stage2_evidence_audit_20261018.md)。没有源码变化就
无需为文档更新重跑已通过硬件。若后续 Stage 2 源码变化，仍使用原绝对路径
`stage2_build_and_run.sh all` 重新建立同源 run；不要覆盖已有 run。

本轮未执行任何编译、生成/elaboration/FIRRTL/Verilator、仿真、regression 或单元测试；
仅源码/日志/清单/hash/差异检查和文档更新。未 reset/清理/同步/提交或修改 sources/，
全部 Stage1/Stage2/用户改动及历史失败现场保留。

## 历史：Stage 2 directed preservation gate 修复，待重新构建验证（2026-10-18）

用户最新定向现场为 `AI/TMP/stage2_validation_d5wr10l1/`。该次 build 通过，
但 directed 在 `prematureAck` 报 `premature ACK needs stalled first C beat`。
原始 trace 在同一行反复输出 `STAGE2_TX BLOCK`（旧 image `epoch=1`、
`lower=0`、`safe=1`），始终没有 `STAGE2_TX PRESERVE`；因此本次观察到的
是 preservation 请求未启动，尚不能把它解释成提前 ACK。该 run 的 generated
RTL 是修复前产物，不能与当前源码混用。

已确认并修复 `chipyard/generators/boom/src/main/scala/lsu/dcache.scala`
中的 epoch 误索引：`s2_lookup_epoch(0)` 已是选中 way 的完整 epoch，旧代码
再次按 way 取 bit，way 1/epoch 1 会错误抑制 cross-package block/preservation
建立；当前比较完整 epoch 与对应 `slotEpoch(set)(way)`。同时增强
`AI/Debug/scripts/stage2/stage2_test.cpp` 的 precondition 诊断，记录 C
valid/fire；`stage2_validation.py` 在 directed 失败时汇总所有结构化 case、
缺失 case、独立 effect 事件和 L2 denied/成功事件缺口。

本轮已检查：57 项 `test_stage2_validation`、Python 编译、三个 shell 语法、
`git diff --check`；静态证据和当前源文件 hash 记录在
`AI/TMP/stage2_directed_epoch_fix_4_eyionz/static.correction.json`。这些检查不启动硬件工具。未检查：当前源码的 Scala 类型
编译、RTL 生成、FIRRTL/elaboration、Verilator、directed/system 仿真和真实
动态覆盖。旧 Stage 1/Stage 2/用户改动均保留，未 reset、同步、清理、提交或
修改 `sources/`。当前状态：`STAGE2_STATUS=PATCHED_PENDING_REBUILD`；下一步
需用新 root 执行绝对路径 `stage2_build_and_run.sh all`，只有 fresh build
通过后才能判断该 gate 和后续 CASE。

## 前一轮：Stage 2 整机残留 CAM 的 64 条连线问题已修，待重新构建（2026-10-18）

用户最新 run `AI/TMP/stage2_validation_r8baqbfq/` 已完成独立 fixture 的 Scala compile、完整生成、97 pin wiring 审计、Verilator lint 与模型 C++ 编译，越过前轮构造问题；整机在 WiringTransform 报 `NoSuchElementException: gh_l1_l2_packet_tracked_15`。核对该次真正输入的 appended annotation，确认共有 64 个旧 CAM source 没有 sink：Stage 2 SinkC 已迁移到 TL CacheImage，但 L1 仍发布旧 CAM。其余 130 个 pin 数量正常；详见 [整机连线修复](../history/reports/stage2_system_wiring_fix_20261018.md)。

已一次移除无消费者的 64 个旧发布端及其 CAM 状态，fixture 同步移除对应 sink、保留 33 个真实接收端，原 preservation/TL/统计门禁不变。运行器清除错误摘要的 ANSI 和 JVM options 普通提示，首错显示实际 cause；整机构建失败自动从该次最终 annotation 列出所有异常到 system.wiring.out/json，保留原始退出码和完整原日志，不增加硬件运行。all 仍跳过 offline，严格 build→directed→system。

本轮证据 `AI/TMP/stage2_system_wiring_fix_oo_upv1_/`：56 项纯运行器测试通过，最外层禁止外部进程；源码/精确差异、原日志只读重判、Python AST/shell syntax/diff 检查已做。当前源码没有重新编译、生成、elaboration、执行 FIRRTL/Verilator 或仿真。用户原 run 的 directed/system 未运行；当前 33 pin fixture、整机完整构建和动态覆盖全部 pending。无已知构建前阻塞，用户执行原绝对路径 all。`STAGE2_STATUS=PATCHED_PENDING_REBUILD`。保留全部 Stage 1/Stage 2/用户改动与失败现场，未同步/reset/清理/提交或修改 sources/。

## 历史：Stage 2 审计 transform 无参构造已修，待重新构建（2026-10-17）

用户最新 run `AI/TMP/stage2_validation_mzljfuss/` Scala compile 完成后，FIRRTL 在构造 Stage2WiringAudit 时失败；module.emit.log:335 的 NoSuchMethodException 明确缺少 `<init>()`。这是上一轮新增带 reportPath 构造参数的审计类引入的问题：本地 Compiler→Dependency.fromTransform 把普通对象转为类依赖，再反射调用无参构造。原日志、旧 class 的 javap 与 FIRRTL jar 字节码已相互核对，详见 [无参构造修复](../history/reports/stage2_audit_ctor_fix_20261017.md)。

正式 fixture 已改为公开顶层无参类，报告路径由每次 CircuitState 的 TargetDirAnnotation 提供，缺失明确失败；EmitModule 在 elaboration 前用真实 Dependency.getObject 提前检查相同构造链路。97 个只读 sink、批量审计/错误报告、成功产物门禁和原 all 三阶段/跳过自动 offline 均保留，未改生产 RTL。

本轮证据 `AI/TMP/stage2_audit_ctor_fix_qxwo_iry/`：只做源码/精确差异、现有 class/jar 的静态 javap、Python AST/shell syntax/diff 检查，未重跑完整 offline suite，未构建、生成、elaboration、执行 FIRRTL transform、Verilator 或仿真。用户本次失败发生在 wiring 审计前，不能宣布此前 97 个 sink 已动态验证；新增无参构造、报告目录及后续完整生成/硬件行为仍待实测。无已知构建前阻塞，可由用户执行原绝对路径 all。`STAGE2_STATUS=PATCHED_PENDING_REBUILD`。保留所有 Stage 1/Stage 2/用户改动和旧现场，未同步/reset/清理/提交或修改 sources/。

## 历史：Stage 2 WiringTransform 缺 sink 已补齐，错误报告改为批量，待重新构建（2026-10-17）

最新用户 run `AI/TMP/stage2_validation_5iv7ungc/` Scala compile 成功，已越过上一处 1G OOM，首次失败为 module.emit.log:60 的 FIRRTL `Wrong number of sources or sinks!`，栈在 WiringTransform。fixture 未实例化 InclusiveCache/TestHarness 消费者，实际 L1 的 97 个 BoringUtils source 均无 sink；本地 FIRRTL jar 字节码确认这正是有 source/零 sink 分支。已按实际 source 名称/宽度一次补齐只读 sink，无协议回馈或生产 RTL 修改。源码展开核对缺失 97→0，宽度不匹配 0；生产 dcache hash 与原失败清单一致，详见 [wiring 修复](../history/reports/stage2_wiring_build_fix_20261017.md)。

新增 WiringTransform 前置审计，一次列出所有坏 pin/目标并保存 generated/stage2.wiring.out；成功报告必须参与生成完成及产物来源门禁。运行器在失败时显示同次日志里全部不同的错误/失败诊断，保留 `<log>.errors.out/json`、上下文/原码/hash 与摘要路径；定向 Verilator error-limit=0，不改错误严重度。all 仍为 build→directed→system，前阶段失败后续 NOT_RUN，已通过的 offline 不再自动运行。

本轮证据 `AI/TMP/stage2_wiring_fix_3nol05y4/`：最终 48 项受影响运行器测试、Python AST/shell syntax/diff 检查通过，所有硬件动作替换；源码 inventory 与 jar API 为静态检查。未启动构建/Scala compile、生成、elaboration、FIRRTL、Verilator 或任何仿真。没有已知需要构建前继续修复的阻塞，下一步用户执行原绝对路径 all；新增接收端、Scala 审计及完整硬件正确性仍待实测。`STAGE2_STATUS=PATCHED_PENDING_REBUILD`。原失败 root、Stage 1/Stage 2/用户改动全部保留，未同步/reset/清理/提交或修改 sources/。

## 历史：Stage 2 生成 OOM 已修，all 移除重复离线检查，待重新构建（2026-10-17）

用户最新 run `AI/TMP/stage2_validation_qodffn_8/` 显示 fixture Scala compile 已成功，随后 Chisel/FIRRTL 转换在 Java 1G heap OOM；sbt 后台线程异常仍 exit 0，旧入口最终只报无 RTL。module 直接调用 sbt 未获得 Stage 1 Makefile 的 8G 默认，是本次根因。已显式传入 8G/Xss8M 和 ExitOnOutOfMemoryError，参数写入来源清单；exit 0 后仍检查异常日志、顶层产物和正常完成标记，失败指向 module.emit.log 并保留 raw code。详见 [OOM 修复](../history/reports/stage2_emit_oom_fix_20261017.md)。

按用户要求，原一条命令 `stage2_build_and_run.sh all` 现为 build→directed→system，不再自动重跑已通过的 offline tests；仍强制保存/核对源码、fixture、参数、环境、工具、workload、模型/binary 和覆盖状态。offline 只保留为显式选项，未运行不会标 PASS。唯一 root、严格串行、失败即停及中文日志/摘要继续保留。

实际本轮脚本检查证据 `AI/TMP/stage2_emit_oom_fix_v_0k0s2e/`：最终 42 项受影响运行器测试（硬件动作均替换）、Python AST、shell syntax、diff 检查通过；只读重判原失败日志准确识别 OOM。未执行完整 offline suite、build、Scala compile、elaboration、FIRRTL、Verilator 或任何仿真；硬件正确性仍未验证。无已知构建前阻塞，建议用户重新执行原绝对路径 all 命令；8G 是否足够仍待构建实测。`STAGE2_STATUS=PATCHED_PENDING_REBUILD`。未 reset、清理、同步、提交或修改 sources/；旧失败现场完整保留。

## 历史：Stage 2 fixture Probe API 编译错误已修，待重新构建（2026-10-17）

用户 run `AI/TMP/stage2_validation_llhv_oen/` 的 module.emit 在 Scala compile 阶段失败，唯一错误是 `Stage2Generate.scala:142` 引用不存在的 `TLMessages.ProbeBlock`。已按本地 Bundles.scala/TLEdgeIn.Probe 改为 `TLMessages.Probe`，仅一行 fixture 变更；原失败副本、日志和所有既有改动保留。详见 [Probe API 修复](../history/reports/stage2_probe_api_build_fix_20261017.md)。

实际最新离线证据 `AI/TMP/stage2_validation_8h7j2vpe/`：75 项离线测试与现有语法/diff 检查通过，额外当前 TLMessages/TLPermissions/TLAtomics 成员名核对无缺项；已证明相对失败副本只有这一行修改。本轮未重跑 Scala compile、硬件生成、elaboration、Verilator 或仿真，不能宣布构建通过。下一步用户重新执行原绝对路径 `stage2_build_and_run.sh all`，自动新建 root。`STAGE2_STATUS=PATCHED_PENDING_REBUILD`。

## 历史：Stage 2 单命令 all 与 denied 回归就绪（2026-10-17）

继续 `PREFLIGHT_READY_PENDING_BUILD`，无已知构建前阻塞。用户在原 Stage 1 环境任意目录只需执行 `/data1/gzh/EC/AI/Debug/scripts/stage2_build_and_run.sh all`。现有入口自动定位项目、创建唯一 root，严格 offline→build→directed→system，保留全部 provenance/匹配/覆盖门禁；中文显示阶段与总结果、失败原因/首个错误和日志绝对路径，保存 runner.log/summary.out。工具失败保留原始码，覆盖不足与工具退出3分开记录。

新增生产 L2 MSHR→SourceD 的 denied Put/ADD 与成功对照，合并原定向进程，10 CASE；检查完整旧 key/provenance、真实 schedule/directory/D/bank 事件、denied 零写及成功数据。补覆盖时修复 fixture CACHED outer edge 违反 lastLevel 参数要求，以及 SourceD denied full Put 缺 old-data read 却可能写 bank/bypass：denied 不再进入 bank retirement/bypass。真实目录存储/互连与整机主动 denied 仍有覆盖边界，见 [单命令交付](../history/reports/stage2_all_entry_20261017.md)。

最新实际证据 `AI/TMP/stage2_validation_53whknp_/`：从 `/tmp` 绝对路径运行 offline，75 项纯离线测试、Python AST、shell syntax、diff、C++ declaration-stub syntax-only 通过。单元测试的硬件动作全部替换，不是硬件 PASS。本轮没有执行 all、build、elaboration、FIRRTL、Verilator 或任何仿真；新增动态回归全部待用户运行。未同步、reset、清理、提交或修改 sources/，所有已有改动保留。

## 历史：Stage 2 构建准入复核完成（2026-10-17）

`STAGE2_STATUS=PREFLIGHT_READY_PENDING_BUILD`。以本地 `1ed07c280` 和全部 Stage 1/Stage 2 未提交改动为准，继续保留现场；未同步、reset、清理、提交或修改 `sources/`。

本轮修复 SourceD 内部 Atomics 的新 TL 字段未初始化、probe 借 WB ready 误判完成、C 全部发送前 matching-key ACK 锁存、fixture 128-bit 高半观察缺失、denied A 操作重标旧 image。新增 freeze admission/实际写口断言、独立 effect guard、完整 CASE 名单和 key/epoch/receipt analyzer。字段/目录、bank ACK、buffer/credit/probe、freeze 与 ACK 生命周期六项源码复核见 [preflight 报告](../history/reports/stage2_preflight_20261017.md)。

手动入口拆成 `stage2_build_and_run.sh offline → build → directed → system`，同一新 `STAGE2_ROOT`、相同环境；前阶段失败/缺覆盖或 source/model/参数/环境不匹配时，后阶段拒绝运行。Stage 1 仅增加显式 build-only 出口，默认行为保留。

实际最新离线证据：`AI/TMP/stage2_validation_u_xd___4/`，`OFFLINE=PASS`；64 项纯离线 tests、Python AST、3 个 shell syntax、declaration-stub C++ syntax-only、diff 检查通过，附 15 Scala 文件 lexical balance（不等于类型检查）。此前 root 保留，后续源码改变会被输入 gate 拒绝。本轮没有运行 sbt/make、Scala 编译、硬件生成、elaboration、FIRRTL、Verilator 或任何仿真，build/directed/system 都未执行。

无已知需要在 build 前先修的阻塞；建议用户从新 offline root 开始四阶段验证。实际 Scala API/初始化/组合环、generated ports、动态背压/并发和全系统进度仍待验证。Stage 1 旧 PASS 不证明本轮 RTL。Stage 3 lower predecessor FSM、rollback/escape/pressure-close 不在本轮。


## Stage 1 已正式关闭（2026-10-17）

最新 final validation run `AI/TMP/stage1_closure_run_g3Y7Oi9x` 已完成，未再启动仿真。`PROVENANCE=PASS`（11478 source、3003 generated files），simulator `serial_success`/exit code 0，`verified=1`，334/334/334 packages PASS，软件 END PASS；scoreboard `STAGE1_TRACE=PASS`、`errors={}`，全部 closure gates PASS。

```ini
STAGE1_STATUS=CLOSED
NEXT_SIM_REQUIRED=NO
PROVENANCE=PASS
SIM_EXIT=SUCCESS
ARCH_ERROR=0
AMO_LOW_LANE_SEEN=1
AMO_HIGH_LANE_SEEN=1
AMO_ERROR=0
MAIN_COUNT=155606
CHECKER_COUNT=155606
MAIN_CHECKER_DIFF=0
DUP_EFFECT=0
LOST_EFFECT=0
EFFECT_WITHOUT_TERMINAL=0
DUP_TERMINAL=0
TERMINAL_WITHOUT_STQ_RELEASE=0
DUP_STQ_RELEASE=0
CLEAR_RACE_VIOLATION=0
EXIT_REAL_OUTSTANDING=0
```

九项均 PASS：architectural data/error、AMO.W、main/checker、clear/S1/S2/refill、effect→terminal、terminal→STQ release、duplicate effect、lost effect、exit outstanding。main/checker 六 counters 完全一致（store 60567、load 95039，cache/uncache 分项也一致）；退出 DCACHE/LSU snapshot 全部归零并 `fence_ready=1`。实际未发生的 clear/refill、refill/effect、S1/S2 replay-killed 交叉继续作为非阻塞 coverage 观察项记录。最终 trace SHA256 为 `a838739c4240e3cd8df3dd20875b0a6633f082c64bb5fa378347b237edd9fa87`，FST SHA256 为 `85c6917e8a6d5dce11e96fe6cd403e7d56057f132d3139cc689a9c075627c97e`。完整 closure 证据见 [最终 closure 报告](../history/reports/stage1_closure_20261017.md) 及 run 内 `scoreboard.out/json`、`trace.log`、`trace.fst`。

## 历史：Stage 1 simulator 缺失头文件依赖已修（2026-10-17）

用户新 build `stage1_closure_build_e0hlkAyW` 在 simulator C++ 编译时报 `emulator.cc:24: stage1_exit.h file not found`，尚未进入 simulation。根因是 Verilator Makefile 的 `SIM_FILE_REQS` 漏列新 header，未复制到 gen-collateral；已仅补一行依赖。上一轮 preflight 漏检了这条 staging 链路，下面的运行准入记录保留为历史，不能代替这次实际构建失败。

直接提取真实 staging 规则的隔离 before/after 验证已复现并消除缺失：复制/filelist 两项 false→true，host 预处理退出 1→0；32 项现有离线测试和 diff 检查 PASS。本轮未执行硬件编译/Verilator/仿真，未修改旧 build/generated 或功能逻辑。`STAGE1_STATUS=PATCHED_PENDING_FINAL_VALIDATION`，`NEXT_SIM_REQUIRED=YES`；完整 build 及动态验证仍待用户运行原 `stage1_build_and_run.sh`。详见 [修复记录](../history/reports/stage1_exit_header_build_fix_20261017.md)，证据在 `AI/TMP/stage1_exit_header_fix_dgopfbpr/`。

## 历史：Stage 1 最终运行准入（2026-10-17）

`PRE_FLIGHT=PASS`，`STAGE1_STATUS=PATCHED_PENDING_FINAL_VALIDATION`，`NEXT_SIM_REQUIRED=YES`，`NEXT_ACTION=RUN_STAGE1_BUILD_AND_RUN`，`EXPECTED_SIM_COUNT=1`。本轮仅复核 accounting、有限 HTIF exit/drain 和一次运行覆盖链，未发现 blocker，未修改功能源码/analyzer/workload/运行脚本，未执行任何硬件编译或仿真。32 项现有离线测试、六文件 Python AST、shell syntax、默认 workload 身份及 diff 检查全部通过；代码冻结。具体五项 YES/NO、退出 predicate 与 analyzer 的严格程度、诊断和准确运行命令见 [最终 preflight 记录](../history/reports/stage1_final_preflight_20261017.md)。补丁仍待下一次全新 build + 一次联合 simulation 动态验证。

## 历史：Stage 1 全项审计与联合补丁（2026-10-17）

`STAGE1_STATUS=PATCHED_PENDING_FINAL_VALIDATION`，`NEXT_SIM_REQUIRED=YES`，`MINIMUM_SIM_COUNT=1`，`PRE_FLIGHT=PASS_STATIC_ONLY`。本轮没有运行硬件/Scala build、elaboration、FIRRTL、Verilator 或 simulation。完整身份、九项 matrix、全部 counter、330 条失败归因、invariants 和下轮判据见 [全项审计报告](../history/reports/stage1_closure_20261017.md)。

最新昂贵 run 为 `AI/TMP/stage1_closure_run_vRXs98g3`，build 为 `stage1_closure_build_PlMlLDP7`；修改前来源验证 PASS，sim SHA256 `84dbe6de62f1a8114e4decf1c85d3702cb3730e474c3f3a8cec619fe383d88b9`。正常 serial_success、verified=1、338/338/338 packages。此前 TestHarness 的三条类型 error 已在该成功 build 中消失。

旧 run 两个独立失败均已完整归因：main155274/checker155603，store差-87、load差-242；全部329条均唯一关联到正确 seq、check0 的 owned drain 功能提交，功能 effect/terminal/release 完整。R_IC 导出 canonical producer ownership，经 Core/Tile 驱动 LSQ 统计资格，统一覆盖 cooling/snapshot/postcheck；旧波形反事实补回329、额外0、遗漏0。另一项是 libgloss 无限 HTIF exit stores：退出 token0x52788 在 MSHR5/txn0x57e/S2/replay，另14条 unissued tail，不能称为 lost/deadlock。workload 现为一次 tohost/fromhost 后 fence/park；Stage 1 emulator 在 host success 后按真实 probes 等待 L1/LSU 排空，保留原 timeout 和真实失败。

Architectural data、AMO.W low/high、clear mode B、effect→terminal、terminal→release、duplicate/lost effect、replay 在原 run 均通过。实际 clear/S1=183、clear/S2=16、kill/replay并发172、install/hit161、refill/hit791、install/effect9，违例0；clear/refill、refill/effect、真实 replay cancellation 未观察，报告单列静态保护与覆盖边界。

Analyzer 已修负 PC 差隐藏、occurrence 集合、重复 event identity、counter/event 一致性、issued exit JSON 分类、软件 ASSERT/END 失败及并发计数；缺独立 checker identity/END 不能假 closure PASS。旧 trace 的修订分析仍保留两个真实根因及软件 FAIL 传播。32项离线 tests（含独立 host predicate 测试）、Python/shell syntax、31处 printf arity、diff 检查通过。新软件已独立构建并核对 `_exit` 反汇编，默认 `AI/TMP/stage1_workload.json` 身份通过，原 ELF/manifest 保留。

下一步由用户另行安排一次全新 build + 一次联合 simulation，验证统计 ownership、有限 exit 和真实排空、checker ordinal、显式 cycle，以及所有原 Stage 1 gates；本轮不启动。下列旧 checkpoint 是历史来源，不能覆盖本节的当前结论。

## Stage 1 用户构建报错修复（2026-10-16 19:22 后）

用户运行 `stage1_build_and_run.sh` 在 Scala compile 阶段失败，完整日志为 `AI/TMP/stage1_closure_build_d1DLDfai/build.log`。日志显示 RocketCore 和 BOOM 三个源文件编译完成；TestHarness 的三条 error 均来自新增观察代码：先 `map(_.tileParams)` 得到依赖 `CanAttachTile.TileType` 的存在类型，再匹配 BoomTileParams，导致 collect 类型推断失败并连锁得到 `Nothing.hartId`；make Error 1 是同一失败的传播，没有进入本次 elaboration 或 simulation。

已将 `TestHarness.scala` 改为直接匹配具体 `BoomTileAttachParams`，收集明确的 `Seq[Int]` hart IDs，再选择唯一 BOOM 的 hart。观察端口、schema、BoringUtils 名称和缓存控制均保持原有语义。源码类型链与仓库同类 attach pattern 已核对，`git diff --check` 通过；按此前限制，本轮未重新执行 Scala/hardware build 或仿真，因此编译通过仍待验证。日志开头 `libriscv not found` 来自 Makefile 的可选链接 warning，不是本次失败原因。

## Stage 1 simulation readiness preflight (2026-10-16，当前)

`PRE_FLIGHT=PASS`，`NEXT_ACTION=RUN_STAGE1_BUILD_AND_RUN`。本轮没有执行硬件/Scala 编译、elaboration、FIRRTL、Verilator 或 simulator；这是运行准入，未宣布新源码动态 correctness PASS。完整九项结论与证据见 [readiness report](../history/reports/stage1_readiness_20261016.md)。

已补齐最小取证缺口：directed AMO.W 在 checking window 内无条件覆盖 low `0x80007e00` 和 high `0x80007e04`，两 lane 各 swap/add；独立软件构建和反汇编已完成，默认 manifest 为 `AI/TMP/stage1_workload.json`，原 ELF 保留。LSU/DCache/TestHarness 连续只读 probes 由 emulator 在最后正常 eval 后采样，产生真实 `EXIT_DRAIN` 和精确 `EXIT_STQ`；活动 MSHR 与停驻预取 owner 分开。ARCH_STORE 独立于统计口径，`_exit` 仅在精确 live committed/physical/data-ready 且未被 L1 接受时分类为软件尾部，已接受/丢失/未 terminal/release 的事务继续失败。

main/checker 有六 counters 和 package seq 自动 diff；CLEAR_CHECK 与 epoch/owner/refill 检查采用 closure mode B，覆盖本次实际 clear 决策，不能空集 PASS。checker 的 package_seq_reg 观察连接已移至声明后。23 项 Python 离线测试、shell 语法、Python AST 和 diff 检查通过；新增 Scala/C++ probes 仍需下轮编译验证。

下一步由用户执行 `/data1/gzh/EC/AI/Debug/scripts/stage1_build_and_run.sh`：当前 working tree、全新 build/provenance、一次 simulator，默认 FST。输出为新的 `AI/TMP/stage1_closure_build_XXXXXXXX/` 和 `stage1_closure_run_XXXXXXXX/`（含 trace.fst/log、run.json、scoreboard.out/json）。不复用历史 simulator，不在本轮执行。

## Stage 1 L1 closure checkpoint (2026-10-16，历史运行)

The existing run `AI/TMP/stage1_trace_20261016_120118/` is provenance-consistent and ended with `STAGE1_SIM_EXIT reason=serial_success`, `verified=1`, and 332/332 checker packages passed. It still reports BOOM/checker traffic differences of `707` stores and `1715` loads. Read-only attribution is complete: `lsu.scala` qualified architectural events with `traffic_scope_valid && packet_seq!=0` but omitted the LSQ-captured `traffic_check`, so setup/post-window accesses were counted. The working tree now requires `traffic_check` for both load/store qualification.

The AMO.W source fix is also in the working tree: `dcache.scala` uses `LoadGen.wordData`, so RV64 upper-word accesses select `addr[2]` before sign extension. S3 retains AMO old/operand values and emits cycle/address/mask fields for the next run; `RocketCore.scala` debug checker tokens use `package_seq_reg`. No build or simulator was run after these edits. The current run did not cover upper AMO.W lane or provide an exit drain snapshot.

The streaming analyzer is `scripts/stage1_trace_scoreboard.py`. The historical analysis of the saved run proves observed effect/terminal/STQ exactly-once and replay closure, but reports `MAIN_CHECKER=FAIL`, `AMO_W=UNRESOLVED`, and `EXIT_OUTSTANDING=UNRESOLVED`: 15 committed identities belong to the `_exit` tohost/fromhost loop and that saved simulator had no live L1 drain marker. The new observation path above has not been run. Historical status: [stage1 closure checkpoint](../history/reports/stage1_closure_20261016.md).

## 最新：两个 MSHR drain admission closure（2026-10-14）

**可以进入最终大仿真**。在原state12 closure基础上，mshrs.scala:159统一覆盖s_drain_rpq和s_drain_rpq_loads；本轮硬件增量只有一个Bool、两行注释和两条assertion文案（+5/-5），原Phase-1/queue/owner/publish逐字保留。源码SHA256 `594b0a9bc4d990d8a0b9c16a010fa41268adf6fa99c66c98b632eedb4e02123f`。

完整v1Config Scala compile、Chisel elaboration、FIRRTL low/CheckCombLoops/SV/内存宏、Verilator debug FST simulator build均PASS。两个状态禁止secondary accept和RPQ enqueue；原退出/publish未放宽。真实RTL短对照：旧state12-only版本在state3持续1000周期、新enqueue1000、不退出；修复5场景全PASS，正常早期drain5周期/背压16周期，accepted逐token退休，包含branch kill、issued CANCEL、RETRY及commit_line=false路径。fixture不含真实LSU/DCache，store terminal由环境提供，不能声称整机store效果验证完成。

下方历史报告中state3仍开放的描述已被本轮修复推进。静态收敛依赖下游服务/有限RETRY；固定resident同line polling转hit，writer有重新竞争机会，全局无限incoming流量仲裁公平性仍未证明，未发现第三个同类drain-admission状态。下一步大仿真验证真实STQ完成/数据可见、Phase-1和BFS，不因尚未进行该下一步而拒绝准入。

独立新simulator/生成物/完整diff/构建日志：`AI/TMP/mshr_both_drain_closure_20261014_165012/`。默认旧binary未覆盖，本轮未运行长仿真、未提交。报告：[两个drain closure](../history/reports/mshr_both_drain_closure_20261014.md)。

## 最新：mshrs.scala 静态一致性审计（2026-10-14）

结论：**当前实现基本正确；RPQ drain fix 正确；可以继续，无需恢复源码。** 当前 `mshrs.scala` SHA256 `53a3b2795cccc92268f41b9542fdc248079f6785496a27af875f1c650727ef3b` 与保存 closure 版本逐字相同；真实 prepatch + 保存 patch 重建也相同。相对 prepatch 仅 +10/-1，19 条原 assertion 全保留，新增2条。未发现后续性能对话混入功能 RTL 改动、回退或误改；未提交作者归属无法靠 blame 确定。

本轮重新执行 BOOM Scala compile、v1Config 最小真实 BoomMSHRFile Chisel/FIRRTL/Verilog generation、Verilator lint，均 PASS；RTL 确认 state12 gate 进入 sec_rdy/RPQ producer，publish仍等待 RPQ/enqueue/in-flight。lint只有 DECLFILENAME/UNUSEDSIGNAL，没有 width/connection/multiple-driver/latch/UNOPTFLAT。完整整机生成复用下方同源码上轮证据，本轮没有启动仿真。1461个Scala源码hash、默认6790个generated文件size/mtime均保持，功能源码未修改。

state12只在 eventual matching completion、有限RETRY、下游公平前提下证明有限集合收敛；state3 `s_drain_rpq_loads`仍开放新load，可在持续enqueue/dequeue下不退出；真实全局writer/probe公平性未证明。这些是原有独立活性边界，不是本轮发现agent破坏。完整Phase-1/BFS继续pending。详细审计含30个hunk分类、state/row/assert表：[mshrs_static_audit_20261014.md](../history/reports/mshrs_static_audit_20261014.md)。证据：`AI/TMP/mshrs_static_audit_20261014_131925/`。

## 独立复核：最终 replay drain closure（2026-10-14）

本轮 `AI/TMP/mshr_drain_closure_20261014/` 的真实 BoomMSHRFile 同刺激对照：prepatch 2000周期无read publish；修复后read drain周期124→publish220，writer upgrade/两个matching store terminal后周期294全部退休。逐token117 accepted/117 completed，SDQ释放2次；Trunk直接drain、GrantData写miss和14项pre-issue exception cancellation分别PASS，故意错transaction触发原owner assertion。完整v1Config compile/elaboration/low lowering/firtool verify-each/CheckCombLoops PASS。该证据与下方另一模块验证记录分开，周期不混用。

真实LSU/STQ.succeeded、DCache实际store数据效果、多MSHR/probe公平性和BFS未验证。1W LSU的15周期机制只抑制wakeup，不保证无限incoming load公平；s_drain_rpq_loads仍开放。建议需要补测试后提交。独立设计与验证报告：[mshr_drain_closure_independent_20261014.md](../history/reports/mshr_drain_closure_independent_20261014.md)。

## 最新：MSHR RPQ drain closure，静态与模块验证通过（整机 writer opportunity pending）

2026-10-14：GAPBS BFS `verified=1` 后 HTIF 等待的真正阻塞为 committed tohost store 没有完成 cache 写效果。MSHR2 transaction0x4da 的只读事务进入 `s_drain_rpq` 后仍接收 fromhost polling loads，RPQ边出边进，不能 publish/retire。旧FST的首次进入窗口为t10387259，末尾t41845875仍state12/meta_write0；BOOM cycle=(odd t−205)/2。

方案A最小修复已在working tree：仅 `mshrs.scala` 增加 `drainAdmissionClosed` 关闭state12 secondary，加两条no-accept/no-enqueue assertion，保留全部原publish、replay/terminal owner、FSM及Phase-1条件。恢复上下文时改动及隔离构建已存在，本轮核对实施前快照、未重复覆盖源码。相对真实prepatch快照+10/-1，其余原dirty功能文件hash未变。

BOOM Scala compile、v1Config Chisel/FIRRTL low/firtool verify-each/CheckCombLoops/Verilog与内存宏生成PASS。生成物在 `AI/TMP/mshr_drain_closure_20261014/v1-generated/`；默认generated目录6790文件未变化。真实生成MSHR/RPQ/RAM的独立短RTL对照：旧版持续刺激1000周期仍drain且新接受201请求/publish0；修复版15个旧请求全部完成，正常74周期退出、带RET​RY及metadata/E背压184周期退出；未issue分支取消和issued CANCEL也通过。每场景另覆盖无data升级、closure前secondary store/load、Trunk直接drain，最终19 accepted/19 retired。

**验证边界**：模块环境提供matching APPLIED/CANCEL/TL/metadata响应，没有真实LSU/STQ/DCache/TL fabric，故store terminal完成不能等同整机store succeeded/内存可见。真实同line固定resident条件下load在退休后应hit，不持续重建read MSHR；LSU已有wakeup限流不覆盖所有incoming/PTW/其他仲裁，无法声称全局公平。真实writer opportunity、多MSHR/probe竞争和BFS收尾仍unresolved。未运行长BFS、未提交，建议“需要补测试后提交”。

报告：[MSHR RPQ drain closure](../history/reports/mshr_rpq_drain_closure_20261014.md)。Bug：[RPQ drain admission](../bugs/bug-mshr-rpq-drain-admission.md)。增量patch/旧版对照/四场景日志/manifest：`AI/TMP/rpq_drain_closure_20261014_100756/`。下一步真实BOOM/LSU短程序验证同linepolling＋committed store、metadata fire/retire→load hit→writer acquire/terminal→STQ.succeeded/数据可见，不先跑长BFS。

## Latest user run: post-Scheme-A failure near 625000 (RCA complete)

The new failure is a direct `mshrs_3` `assert(!io_refill_fault)` at generated
`BoomMSHR.sv:579`, not a watchdog. The exact first bad state is FST 1250539 /
cycle 625269: an ordinary RPQ load in `s_drain_rpq_loads` fires the shared
LineBuffer read and sets the install-only `rowValid` while `installStarted=0`.
The row remains held through metadata and victim writeback; at FST 1250563 /
cycle 625281, `s_commit_line` presents refill with `installActive=0`, and
`io_refill_fault_3` becomes 1. MSHR/transaction/epoch/reservation/physical
line predicates match; only active install ownership fails.

Full-run evidence found 22,449 row captures, with exactly one outside the
install state, the failing event. This confirms a deterministic refill/install
row provenance bug in the current `mshrs.scala` control: Chisel's lexical
placement of `rowValid` does not qualify its generated register update, and
the common `io.lb_read.fire` capture accepts both load-drain and install reads.
Scheme A's `line_addr` fix is working in this run; the new fault is independent
of physical tag extraction. No functional source was changed during this RCA.

Report: [`phase1_625000_row_capture_rca_20261012.md`](../history/reports/phase1_625000_row_capture_rca_20261012.md)
Evidence: `AI/TMP/rca_phase1_625000_20261012_212146/`

更新时间：2026-10-12（Asia/Shanghai）。本文件只描述当前有效状态；历史运行进入 `history/` 与 `bugs/`。

## 最新：方案 A 已实现，修复后静态检查 PASS（仿真 pending）

2026-10-12 用户授权的方案 A 已在原 working tree 实施：BoomCacheRefill新增coreMaxAddrBits宽line_addr，从MSHR已锁存req生成block aligned地址；DCache physical tag检查使用line_addr，并验证与原array addr的set一致及block alignment。原addr继续保持untagBits数组语义，全部owner/token/MSHR/epoch/fault/assert保留。相对实施前快照只有phase1.scala、mshrs.scala、dcache.scala的+7/-1，没有新增FSM、preservation、generation/watermark、owner生命周期、allocation或TileLink变化。

修复后审查与实际v1Config构建已完成：Scala compile、Chisel elaboration、Scala FIRRTL low lowering、firtool verification/CheckCombLoops、Verilog及top/model内存宏生成全部exit 0。最终RTL确认原array addr14位，line_addr40位经6路同Bundle仲裁完整传递；有效row来源req_addr[39:6]补6零，DCache比较line_addr[39:14]，没有常量tag0、漏接或sideband截断。无相关width/connection/unused告警，已有annotation告警类型与修复前一致。审查本轮没有修改功能源码，前后hash一致。

结论：**本次接口修复静态PASS，可以开始第一轮定向仿真YES**。尚未验证首cache miss、refill_fault、原watchdog或后续Phase-1行为，不宣称完整Phase-1已通过。报告：[方案A静态审查](../history/reports/phase1_refill_sideband_review_20261012.md)；独立生成物和命令证据在`AI/TMP/phase1_refill_sideband_review_20261012_193958/`。本轮未构建/运行新Verilator executable，下一步由用户运行原testcase。下方“未修复”是修复前RCA历史状态。

## 最新用户运行 [1000]：refill tag 接口 RCA（未修复）

用户已于2026-10-12 16:57 +08构建默认debug simulator并运行；默认日志/FST与下方“未运行”的历史状态不同。最新日志为`BoomMSHR.sv:578 / mshrs_0.assert__assert_4`，源码`mshrs.scala:208` active refill owner mismatch。只读RCA已确认：`BoomCacheRefill`继承14-bit数组addr，`dcache.scala:1169`却从该字段右移14位提取物理tag。首个normal cacheable line0x80087fc0的reservedTag=0x20021，refill array addr=0x3fc0，computed tag=0；context/install/slot/epoch/transaction/MSHR/resident-epoch关系全部匹配。FST2861 first valid refill fault，最后低沿2862；下一上升沿abort。日志[1000]是时间格式化值，不是精确DCache cycle，trace_count约1431。

报告：[refill tag RCA](../history/reports/phase1_refill_tag_rca_20261012.md)；完整证据在`AI/TMP/rca_phase1_1000_20261012_175456/`，含源码/生成RTL/C++摘录、500-cycle窄波形、逐谓词证明、manifest与旧源码重建hash。旧[264000]case在启动same-line refill已卡住，watchdog只是迟报；当前descriptor/reservation正确，旧MMIO污染/early STQ释放在本事务中未重现，但新增tag条件破坏normal refill。本轮没有功能源码修改、compile、RTL生成或新仿真。

建议而未实施：显式完整physical line侧带从immutable MSHR descriptor经refill arbiter传到DCache；array addr保留原14-bit语义；tag校验使用完整line，保留全部owner检查。当前normal regression会触发，须先恢复接口后动态验证fill/install/replay/terminal，以及历史clear/order反例。完整Phase-2 certificate与独立AMO.W terminal result问题未在本轮修复，不把它们冒充本次首因。

## 最新 elaboration 报错修复与生成验证

2026-10-12 用户终端的 `InvocationTargetException` 实际由 `dcache.scala:916` 的 `OHToUInt(candidateWay)` 输入宽度未知引起。已将 candidateWay 显式声明为 `Wire(UInt(nWays.W))`，保留原 hit/replacement 选择逻辑。隔离目录 `AI/TMP/phase1_elaboration_fix_20261012_151358/generated` 中的 v1Config Chisel elaboration、Scala FIRRTL low lowering、firtool verification/CheckCombLoops、Verilog 与 top/model 内存宏生成均通过；两个 make 目标退出码均为 0，`git diff --check` 通过。该次Agent没有构建新 Verilator executable 或运行仿真；此后用户的新运行与最新失败见上方，不再将默认路径视为旧证据。

报告：[Phase-1 elaboration 位宽修复](../history/reports/phase1_elaboration_width_fix_20261012.md)。该次只修生成错误，没有修改已知 cacheable AMO.W terminal result 的字选择/符号扩展问题。该次允许第一轮定向 regression 的静态判断随后被用户运行推进；上方RCA新增证明normal-path refill tag接口必然错误，后续重跑前须先修复该接口，动态功能验证未通过。

## 最新 Phase-1 closure 源码实施（动态验证 pending）

2026-10-12 在原 working tree 上完成 Phase-1 源码修改：统一 admission/current S2 effective payload；primary reservation 与 resident epoch 分离；secondary 继承、MMIO 无 cache owner；完整 MSHR/RPQ/SDQ identity；held S3/terminal completion、功能 STQ token 与 older-store ordering；逐语义写 local image serial；clear/probe/replacement drain 与 resident recheck；full-line install 最末 data fire 提交 owner；完整 Grant 捕获后独立 held E；统计 RESET 不清功能 bitmap/safe/owner/pending。真实 owner mismatch 为 assertion/fault，保留责任并停止共享 LineBuffer 读口申请，不转普通 retry。

已完成 BOOM Scala compile 和源码静态审计，记录在 [closure implementation notes](../../Design/cache_version_preservation_phase1_implementation_notes_20261011.md)、`AI/TMP/phase1_closure_20261012/identity-audit.md` 和 `compile-final-nodata.log`。**该次源码实施只做 compile；后续 elaboration/FIRRTL/硬件生成结果见上方最新验证，仿真仍未执行，未声称 watchdog 或旧功能反例已动态修复。** 旧 RCA/FST 仍属于修改前证据：[264000 RCA](../../TMP/rca_phase1_264000_20261012/report.md)。

后续动态验证覆盖 primary/secondary/MMIO、SC/AMO、clear/refill 和 backpressure，最后运行原软件并检查 `verified=1` 与实际字节结果；不得以 package PASS 数或 simulator PASSED 代替功能验证。完整 Phase-2 preservation 未实施。下方原生成报错及旧运行诊断保留为历史上下文。

## 最新 Phase 1 生成报错修复

2026-10-12 用户硬件生成遇到 `BoomNonBlockingDCache.s0_req_0_effect_token_valid` 组合环。源码根因已确认：token 分配条件读取其自身赋值的输出 flag。已在 `dcache.scala` 分离 `s0_selected_req` 输入与 `s0_req` 输出，条件只读输入，消除这条直接组合反馈。BOOM Scala compile 于 08:43:23 +08 通过，源码 `git diff --check` 通过。用户负责硬件生成和仿真，本轮未执行 elaboration/FIRRTL/仿真，尚不能确认整机组合环检查或 Phase 1 功能回归通过。记录见 [Phase 1 implementation notes](../../Design/cache_version_preservation_phase1_implementation_notes_20261011.md)。下方波形与功能诊断仍属于修复前运行。

## 最新只读诊断

报告：[functional_diagnosis_20261011.md](../history/reports/functional_diagnosis_20261011.md)。本轮未修改正式代码、生成 RTL、编译或运行新仿真；分析当前 output 路径已经存在的运行。

本轮 recovery 设计差距分析：[cache_recovery_gap_analysis_20261011.md](../../Design/cache_recovery_gap_analysis_20261011.md)。部分 L1 cross-package shadow writeback 和真实 L2→DRAM barrier 有效；完整的 predecessor 保存链与 package-level cache rollback 未实现。新增证据：safe-old 分支直接写（接受沿433887）；L2地址`0x80035e00`的safe seq4在没有同址outer C下推时被speculative seq6改写（接受沿480795）；MSHR replay可绕过跨包控制（settled2034571）。已知clear/refill race丢的是新Q的store，首先是普通数据顺序违例，不能单独当作unsafe越过DRAM的证据。目标可以通过下层副本和有序握手保存predecessor，并非必需本地双份data；本轮只更新设计资料，未改正式代码或运行新仿真。

正常执行期间的统一设计评审：[cache_version_preservation_unified_design_20261011.md](../../Design/cache_version_preservation_unified_design_20261011.md)。2026-10-11 revision 2 已收敛 preservation certificate：证书绑定完整 `content_seq+generation`，区分事实与resident附着bit；validation不清版本身份；L1跨包handoff、L2同址predecessor和异址victim使用分离FSM。当前last-level Cork约束下，同址保存采用TtoB→BtoT，异址eviction保留TtoN；C/D按transaction锁存provenance和barrier许可，ProbeAckData直写旁路仍需合并，SourceD晚ACK独立。Phase1修local ownership/effect completion，Phase2接完整保存链，Phase3落实有界escape与drain credits。该liveness分析是源码依赖结论而非本run新死锁证据；TL字段、Grant无data和资源容量仍需实施前核对。本轮未改正式RTL，不实现FAIL rollback，尚无新方案动态验证。

- 当前 HEAD：`a68183c83e08ed837c677aec7836c97895e3a95e`。原路径输出时间为 2026-10-11 10:05 +08；当前日志和软件 hash 与下方旧 manifest 一致，但 `test.out`、FST hash 不同，不能静默视为旧运行。当前 manifest 位于 `AI/TMP/diagnosis_20261011_current_manifest.json`。
- **已定位功能错误**：`out_offset[264]`（`0x8005a1e8`）写 `0x1080` 后读回0；更早的 FST 窄波形证明 shadow metadata clear 当拍的 S1 store 使用旧 hit 信息通过 S2，并在 clear 后写 data array，随后旧 refill 覆盖它。接受沿为 clear `432471`、store write `432475`、refill覆盖目标row `432527`。FST 时间为 `2*trace_count+half_cycle`。
- **已定位统计/身份错误**：同包 BOOM 实际普通访存重建为 store60655/load84738，291个包与checker逐包一致。BOOM漏计164/258，全部在snapshot退休；首个store在seq103、FST `1327493`。更早 `1327169` 的STQ捕获锁存了零seq，因为 `core.scala:2363` 在非check状态已输出0，而producer仍拥有seq103。当前generated LSU已包含scope锁存修正，输入身份仍有bug。
- **barrier边界**：L2→DRAM候选/门控/close ACK/safe/release链真实生效，五个候选最终释放；L1→L2仍允许430次unchecked dirty writeback，该类replacement统计为monitor。零tag访存会影响barrier归属，不能由tracked路径通过推断全覆盖。
- **收尾**：checker/result/validation/strict/barrier pending排空，tracked L1 attribution没有seq>safe291；最终MSHR3在tohost的drain状态、fence_rdy=0，属于有证据支持的退出尾流，整机没有完全静止。软件未把verified纳入END或exit code，故功能FAIL与simulator PASSED同时出现。
- **尚未验证**：所有后续mismatch是否同一首因、零tag是否导致其他line真实越界、safe/control C额外停顿、完整构建来源，以及任何修复后的回归。

## 工作树身份

- 运行采集时的代码基线：`ba883dac9e9c50eca94a8a09ac8dd542457798cc`（同步时已从该未发布提交移除旧 Debug 生成物，映射见 `../references/git_sync.md`）。
- 本次整理及同步没有修改 Chipyard 正式功能代码；当前 HEAD/分支同步状态以 `git status --short --branch` 为准。
- 配置：`v1Config`，源码默认 `GH_REAL_BARRIER_ENABLED=true`，1 个 BOOM + 4 个 Rocket checker。
- 软件：`Software/Test/test.riscv` SHA256 `7d440cced710e16958d0121fcac377d57266c9c54a82845e2d5dc9a3a0a9c686`。

## 保留的 2026-10-10 运行记录

原输入路径：`chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/{test.log,test.out,test.vcd}`。这些路径已被新运行覆盖；下面的时间、hash和大小只属于旧manifest。`.vcd` 实际是 FST 容器；日志时间 2026-10-10 18:07:23 +08，FST 时间 18:07:25 +08；该运行的波形为 2,275,433,245 bytes（约 2.12 GiB）。

- 程序到达 `[END]`，但 `verified=0`，`parent_checksum=947892178`。
- `packages allocated/completed/passed = 291/291/291`，这只说明 package result 数量平衡。
- `boom_arch`：store 60491、load 84480。
- `boom_strict`：store 60491、load 84480。
- `checker_sum`：store 60655、load 84738；差值分别为 164、258。
- address stats、L1-L2、L2-DRAM 的本次打印结果不能替代 `verified=1`。

最新证据 manifest：[manifest.json](evidence/latest/manifest.json)；日志副本：[test.log](evidence/latest/test.log)；模拟器结尾：[completion_excerpt.txt](evidence/latest/completion_excerpt.txt)。独立 FST reader 验证范围 `0..9304241`。原 `test.out` 的 `*** PASSED *** Completed after 4652121 cycles` 与 `test.log` 功能 FAIL 同时存在：模拟器返回/退出条件与 benchmark correctness 必须分别判断。完整 output/FST 的独立备份已按用户要求删除；长期区保留日志、manifest 和窄证据，原仿真 output 路径可能被后续运行覆盖。

## 2026-10-10 留存结论

**当时已证实的事实**：程序完成但功能校验失败；package 数量平衡；BOOM 与 checker 流量计数不一致。仅该日志没有提供 first bad state、root cause 或修复通过证据；当前波形的后续诊断见本文件顶部。

**历史上已证实、需要先复核的机制**：528000 的旧 run 曾证明 R_IC 在 barrier close 后过早发布 `count=558/done`，而 BOOM 同一 seq 实际退休 600 条，造成 42 条尾部（5 条 store）留在 LSL；459000/461000 曾分别证明同步 FIFO head 生命周期、LSL 类型/地址匹配和 frontend redirect 生命周期存在独立问题。详见 `bugs/`。

**当时尚未验证**：291-package 运行的 first bad / root cause；计数差值是否是同一首因；源码→生成 RTL→simulator→波形的完整对应关系；barrier、LSL、snapshot、drain、strict-token 回归。当前诊断已分别定位功能首因和统计首因，但没有修复/新回归通过证据。

## 下一步

1. 先针对shadow metadata clear/S1/S2/store/refill的已证实ordering违例设计line interlock和最小assert，保留正确的STQ/token重试语义。
2. 修正包边界的身份源；增加owned memory零tag检查，验证按seq的retirement/LSQ/checker计数相等。
3. 把benchmark verified合并到END和exit code；在进入HTIF退出前采集完整drain状态。
4. 用户授权实施后，依次做源码静态、elaboration/FIRRTL、定向验证和同软件的整机回归；不能用package PASS替代内存正确性。
5. 未验证问题继续保留，trace/大型中间结果留在 `AI/TMP`，不得自行清理。

## 状态维护规则

每次 `Root Cause → Fix Design → Implementation → Validation` 完成后，更新本文件；结论进入 bug/history；通用经验进入 skills/checks；脚本进入 scripts；大型输出只进 TMP。
# Optimization 2 root-cause review; no safe RTL candidate yet (2026-10-25)

The successful Optimization 1 run `slowdown/optimization_1/runs/optimization_1_20261025_123241_e7c5f139/` is now dynamic evidence: ROI is 4,706,513 cycles versus the pinned Original Current ROI 4,734,881, an actual reduction of 28,368 cycles (0.599128%), not the earlier informal 80k estimate. Same-set different-line exposure fell from 273,179 to 996 observed cycles, while MSHR lifetime stayed approximately unchanged (mean 88.3239 -> 88.0368, p95 107) and direct IC gate opportunity did not fall.

The Opt1 trace was replayed offline into `AI/TMP/optimization2_rootcause_and_impl_20261025_d9703cb7/opt1_causal/`. Pending samples separate target PASS absence at the observed endpoint (3,012,446 cycles), result/prefix propagation (88,235 cycles), and post-safe WB/meta-clear stages (about 77k cycles). The first category is not an optimization proof; the prefix category has only 12 intervals and lacks per-predecessor/epoch evidence. R_IC gate ownership/snapshot conditions do not consume the L1 safe watermark directly. No common safe predecessor root cause is closed.

Decision: `NO_SIMULATION_YET`. No Optimization 2 RTL, patch, build, elaboration, Verilator run, or workload was executed. `RUN_PROVENANCE=UNRESOLVED` and full cache/package/DRAM drain remain unresolved. Future evidence must add checker instruction/tail progress, per-slot predecessor state, R_ICSL/RocketCore cleanup/result lifecycle, and complete MSHR release joins before any safe release optimization is designed.


本批后续新增观察：`concurrency_fullcore/io-rebase`完整程序仍在运行，已观察重基后另一个数值Seq40的FAIL。原故障配置为所有Checker各自一个injectedOnce，Seq归零后可在其他Checker再次注入，不能按“一次全局故障”宽松计分。`io_rebase_injection_scope`用真实注入位只读探针确认初始owner；将独立测试配置只给该owner保留原Seq40一次性注入，其他Checker关闭同Seq注入，不增加硬件状态。该候选仍未合入生产，原多注入运行/严格失败预期保留。另有独立物理namespace计分，按真实reset区分可合法复用的数值Seq，完整16轮还必须有48次实际高/低/高timer读，未完成程序不得PASS。


连续恢复完整里程碑已通过：`two_independent_faults_closure.json`记录normal/双FAIL同ELF完整退出、严格配对PASS，双FAIL985629周期，恰好FAIL8/24及对应两次SCP/EVT/Restore/Restart/fresh epoch PASS，架构/128ecall/MMIO一致。8个第二故障/PC/Epoch/reconciled/取消/额外FAIL/缺oracle/checksum负例均拒绝。关闭原P3-14和P5-07，当前64 VERIFIED、5 IN_PROGRESS、0 CODE_READY。原io-rebase仍按独立范围待验收，不要求整个含失败子批次为0才保留两个已有完整成功程序；所有来源/输入已逐项复核。
