# 单主核 Rollback 测试计划

当前实测项目、预期、命令和日志见 [验证矩阵](SingleCore_RTL_Baseline/Verification_Matrix.md)。每次使用新的 `AI/TMP` 输出目录。单项 PASS 需要正确的退出状态、指定结果标记，以及没有断言失败和 UNCOVERED。

组件测试使用仓库的 Scala/Java 工具和 PATH 中的 Verilator。可用 PALIMPSEST_SBT、PALIMPSEST_JAVA_DIR、PALIMPSEST_VERILATOR 选择工具。省略 PALIMPSEST_TESTS 运行全部组件。以下只选恢复、CDC、基线、压力、真实缓存层次和精确异常。

```bash
cd /data1/gzh/EC
out="$(mktemp -d "$PWD/AI/TMP/palimpsest-retest.XXXXXXXX")"
python3 -B AI/Debug/scripts/rollback/static_check.py
PALIMPSEST_OUT="$out/components" PALIMPSEST_RUN=1 \
  PALIMPSEST_TESTS='CheckerRecovery SeqTransport Baseline Pressure Hierarchy PreciseException TranslationRecovery PtwRecovery' \
  bash AI/Debug/scripts/rollback/user_build.sh
```

Hierarchy 检查 SW6、Pending7、FAIL8 下的真实 L1 读取、外存写入及邻字。它还检查已接受请求的迟到终态、字节掩码、AMO、慢 Checker 的 ACK 高低及 34 次不相交回滚。满表用例将安全脏行放在独立 L2 set，先阻塞外存 A，再接收完整安全写并扣住 D ACK。检查 ACK 到达前没有 compact、没有 restart，以及安装空 EVT 后仍只读到安全内容。SVB 用不同地址填满 owner，用同地址同 Seq 的另一个子用例验证中间版本合并。精确异常测试直接用生产 ROB 覆盖较老 lane、空 lane、年轻异常、stop、backend reset 和重执行。

Baseline 与 Pressure 采用生产 `fullC` 两拍队列。Baseline 扣住保存的 D ACK，检查待准入的四拍 Probe 能填满队列且不能提前写 bank。另两个场景让安全 History 分别与不同 tag 的同组 Probe、同址迟到 Probe 重叠。收据后再送较旧 A6 ReleaseData，检查其能收到 ReleaseAck，DRAM 和返回数据仍为 A7，较新 A8 仍能发布。Hierarchy 另在停住的多拍写回期间送 FAIL8、FAIL7，要求第二次 EVT ACK 完成高低两阶段且仍然停核。外存继续后检查 SCP7、写回终态和恢复后实际读数。

Pressure 另在独立实例填入 60 条 Pending 历史并保持 SW=0。Checker 对同组另一地址的 Acquire 必须先使 BASE 脏 victim 精确写入外存一次，再收到 Grant。测试同时检查 Grant 到达时 History 压力仍为高。两个场景各有判定标记，最后统一检查进程退出码。

正常、Fault8 和小上界重基使用同一二进制。构建脚本保存 ELF 和 `loadmem` 镜像的哈希，使用 `--verbose` 采集 SCP、EVT、结果和恢复事件。可独立执行三个配置。正常与 Fault8 完成后再比较最终状态、实际恢复的目标 Seq 及其在日志中的顺序。

构建脚本默认采用 1,024 行数据的完整 workload。设置 `PALIMPSEST_WORKLOAD_PROFILE=compact` 可复现冻结记录中的 64 行诊断 workload。该激励保留 16 轮和原逐字结果检查，并增加常规指令以覆盖 Fault8 和 Seq16。

```bash
PALIMPSEST_SW_OUT="$out/workload" bash AI/Debug/scripts/rollback/user_workload_build.sh
bin="$out/workload/palimpsest.riscv"
for cfg in v1Config PalimpsestFault8Config PalimpsestSeqRebaseTestConfig; do
  PALIMPSEST_FULL_OUT="$out/$cfg" PALIMPSEST_BINARY="$bin" PALIMPSEST_CONFIG="$cfg" \
    bash AI/Debug/scripts/rollback/user_fullcore.sh
done
python3 -B AI/Debug/scripts/rollback/fullcore_scoreboard.py \
  --normal "$out/v1Config/run.log" --fault "$out/PalimpsestFault8Config/run.log"
python3 -B AI/Debug/scripts/rollback/fullcore_scoreboard.py \
  --rebase "$out/PalimpsestSeqRebaseTestConfig/run.log"
```

正常与 Fault8 检查所有初始化字节、存储更新、AMO 返回值、f0、mscratch 和最终 checksum。小上界为 Seq16。计分器对每次重基分别核对目标、对应的归零、重启、首个 Seq1 检查点和 Checker PASS。真实 MMIO 与精确异常同时遇到 FAIL，以及 Seq 重基与未结效果重放的组合在任务板中单独跟踪。

`PALIMPSEST_WORKLOAD_PROFILE=compact-trap-io` 生成另一份64行激励，在受保护区间执行128次真实 `ecall`，每轮读取CLINT `mtime`，并检查Main的异常返回计数和非零输入。异常计数按hart使用独立缓存行，只有此编译宏启用；默认软件行为不变。用这一份ELF重跑上述三个配置后，在两条计分命令中均增加 `--require-trap-io`。该选项要求唯一的 `ecalls=128 expected=128 mmio_nonzero=1`，同时保留原架构oracle和恢复事件顺序检查。软件编译成功不能替代这三次动态验收。

Hierarchy 还包含满表等待中的更早FAIL：保留Pending63，FAIL64使32个区间占满，SW62时不得启动物理维护；随后FAIL63合并相邻废弃区间，恢复SCP63/Epoch33并从Seq65读回安全Seq61。此路径不再需要物理维护，不能把“没有maintenanceRequest”误判成RTL停滞。原34次物理维护用例仍独立执行。

运行 Baseline 时会生成 `Stage3Harness.v`。用同一份生成 RTL 和两个黑盒定义复现通用粗综合、通用展开及逻辑级数。以下命令沿用上面的 `out`。

```bash
gen="$out/components/generated"
read_stage3="read_verilog -sv -DSYNTHESIS $gen/SafeChainEventLogger.v $gen/CacheOpportunityObserver.sv $gen/Stage3Harness.v"
yosys -l "$out/stage3-coarse.log" -p "$read_stage3; hierarchy -check -top Stage3Harness; synth -top Stage3Harness -run coarse; stat"
yosys -l "$out/stage3-generic.log" -p "$read_stage3; hierarchy -check -top Stage3Harness; synth -top Stage3Harness -flatten; stat; ltp -noff"
```

`TranslationRecovery` 对生产 DTLB 与 BOOM 取指路径实例化的共享 TLB 注入迟到响应。全量 SFENCE 之后必须等待旧 walk 收尾，下一查找必须 miss 并使用新 walk 的物理地址。验收普通页、超页、非同质条目，以及 SFENCE 与 PTW 接受或响应同拍。

`PtwRecovery` 检查真实生产 PTW 的 non-leaf cache 与 L2 TLB。夹具按 HellaCache 取消语义响应实际读取，以物理页表地址和新 PPN 判断 fence 后的迟到响应是否污染缓存。测试还确认非失效 walk 的缓存仍能命中。

只读I/O效果观察可链接到已经生成的整核模型，保持原生成RTL、断言与库不变。
`build_io_observer.py`保存来源及链接输入，要求新的输出目录；默认库为该模型的
`VTestHarness__ALL.a`。若使用单独的大C++低优化库，必须显式传`--model-library`，
并保留该库原有来源记录。观察器路径仅适用于当前单主核模型，层次不同会编译失败。

```bash
python3 -B AI/Debug/scripts/rollback/build_io_observer.py   --model-dir "$model_dir" --out "$out/io-observer"
PALIMPSEST_IO_EFFECT_LOG="$out/io-effects.log"   "$out/io-observer/simulator" --verbose +permissive +max-cycles=2000000   "+loadmem=$hex" +loadmem_addr=80000000 +permissive-off "$bin" > "$out/io-run.log" 2>&1
python3 -B AI/Debug/scripts/rollback/io_effect_scoreboard.py   --effects "$out/io-effects.log" --normal "$normal" --fault "$out/io-run.log"   --failed-seq 40 --report "$out/io-scoreboard.json"
```

完整效果验收要求成功程序oracle、严格正常/故障配对、同PC恢复与journal原值重放，
且从原请求至重放完成只能有一次真实设备A握手。IOMSHR的state1→state2仅由
`mem_access.fire`产生；重放应state0→state3。tick等于完整顶层周期，逐eval观察
不会漏掉下降相位。独立日志包含结束记录和事件总数，缺失、交错或截断均失败。
`--focused`仅检查按诊断上限结束的信号链，不能生成完整程序验收PASS。

长期配置 `PalimpsestFault40TestConfig` 可在第一次受保护的 CLINT 读之后触发
FAIL40。用同一份 `compact-trap-io` ELF 生成正常日志后，运行以下命令。
脚本会链接只读观察器，并将设备计数、原值重放、同 PC 恢复和程序结果联合计分。

```bash
PALIMPSEST_FULL_OUT="$out/fault40" PALIMPSEST_CONFIG=PalimpsestFault40TestConfig \
  PALIMPSEST_BINARY="$bin" PALIMPSEST_IO_NORMAL_LOG="$out/v1Config/run.log" \
  PALIMPSEST_MAX_CYCLES=2000000 bash AI/Debug/scripts/rollback/user_fullcore.sh
```

CLINT 输出使用长期 profile `compact-mmio-output` 与
`PalimpsestFault18TestConfig`。每轮向 hart0 mtimecmp 写入
`0x1234000000001000 + round` 并立即回读；128 次 ecall 和原内存/FP/CSR oracle
继续启用。正常与故障必须使用同一 ELF。以下命令最后联合核验所有 16 次实际写、
16 次回读的值与顺序，以及 FAIL18 后同 PC 重放 ACK 且不重复设备 A。

```bash
PALIMPSEST_SW_OUT="$out/output-workload" PALIMPSEST_WORKLOAD_PROFILE=compact-mmio-output \
  bash AI/Debug/scripts/rollback/user_workload_build.sh
output_bin="$out/output-workload/palimpsest.riscv"
PALIMPSEST_FULL_OUT="$out/output-normal" PALIMPSEST_CONFIG=v1Config \
  PALIMPSEST_BINARY="$output_bin" PALIMPSEST_MAX_CYCLES=2000000 \
  bash AI/Debug/scripts/rollback/user_fullcore.sh
PALIMPSEST_FULL_OUT="$out/output-fault18" PALIMPSEST_CONFIG=PalimpsestFault18TestConfig \
  PALIMPSEST_BINARY="$output_bin" PALIMPSEST_IO_NORMAL_LOG="$out/output-normal/run.log" \
  PALIMPSEST_MAX_CYCLES=2000000 bash AI/Debug/scripts/rollback/user_fullcore.sh
```

独立重判已有同次信号日志时，在 `io_effect_scoreboard.py` 中指定
`--failed-seq 18 --require-output`。该标志同时要求正常和故障的输出结果标记，
不会把程序的单个最后读数当作 16 次物理设备操作的证明。

验证计分器本身可重放真实通过日志并注入额外FAIL/取消/恢复等负例：

```bash
python3 -B AI/Debug/scripts/rollback/scoreboard_negative_test.py   --normal "$normal" --fault "$fault8" --rebase "$seq16" --out "$out/score-negative"
```

Baseline的`tracked_c_buffer_across_evt`复用原fullC测试流程，将四拍ProbeAckData
标记为Seq8，先等待两拍队列占满，再在BASE外写ACK扣住时安装FAIL8和更早FAIL7。
释放ACK后必须响应硬件重查产生的第二次BtoN，可信读返回原BASE。可选逐accepted
外写beat oracle覆盖全部八个字，SW跨过两个tombstone之后也不得发布Seq7/8。
此项有真实生产L2/History/Preservation和fullC队列，但peer由协议host提供；真实L1
与另一层同时迁移仍单独保留在任务板中。

V7 的 Hierarchy 增加 `real_tracked_c_outer_owner`：真实 L1 持有 Seq8 Current，
Pending7 已在 L2；可信读产生的 ProbeAckData 填满两拍 C 队列。同址 dirty BASE
外写 ACK 扣住时送 FAIL8→FAIL7，两个 EVT 均须完成高低阶段。释放 ACK 后还会
产生第二次 Probe，Controller 必须重新检查实时 owner，保持 stop 和 SCP7，直到
真正排空才重启。逐 accepted 外写 beat 检查 BASE 首字 0xabc0 及全部邻字，恢复
后可信读仍返回 BASE。V6 原模型在 cycle984 的 restart 断言失败；V7 全套组件中
该用例通过。Recovery 的 `restart_rechecks_late_owner` 独立检查 restore 后撤回
quiesced 时不能重启，重新就绪后只重启一次。两者由原 user_build.sh 入口重跑。

## 完整恢复、会话与I/O功能批次

`function_closure_regression.py`使用四配置生产Core，输入均为显式现有ELF及相邻`.hex`。命令如下，所有输出须使用新的AI/TMP目录；`serial_sbt`为现有flock串行SBT包装器。

```bash
python3 -B AI/Debug/scripts/rollback/function_closure_regression.py \
  --out "$fresh_absolute_directory" --trap-io "$trap_elf" \
  --sv39 "$original_sv39_elf" --output "$clint_write_elf" --amo "$uncached_amo_elf" \
  --sbt "$serial_sbt"
```

正常/Fault8必须严格配对，Sv39还核验PC0x8000045c的全部物理LOAD地址/数据及按SCP截断后的16次存活提交（当前fault为18次尝试、2次废弃，废弃值仍核验）；Seq16核验每次物理reset及新Seq1 PASS；Fault18分别用`--require-output`与`--require-amo`验收16轮真实设备操作和唯一重放效果。任何build/run/score/物理oracle失败均使总driver非零。每次来源哈希、命令、退出码保留在输出目录。长期新增`compact-mmio-amo`与原反例loadmem已相同；`compact-sv39`已恢复原组合oracle表达式，当前重编loadmem与原反例逐字节一致；既有原输入仍保留用于复验。

## 同址发布与有限owner边界

- `AI/Debug/scripts/baseline_publication/run.py`在已生成的生产Stage3上实际验收3/5/7多版本、SW扫描、迟到C、可信Put和held ACK期间安全合并；来源核验和四用例结果见该目录README。
- `AI/Debug/scripts/finite_identity/run.py`只将两个真实空L1槽reset初值加速到0xffff，核验实际seed后驱动完整reservation/install/refill/MSHR终态和四条同组替换；未改变任何协议准入或响应结果。原反例FAIL，三处nextSlotEpoch已合入生产，重新生成的Hierarchy与长期slot边界实际通过；`--kind generation`另验32位CurGen保留区及真实物理维护证书。
- `AI/Debug/scripts/synthesis/synchronizers.xdc`须在综合前读入，保留Rocket既有同步器寄存器；现用firtool丢普通FIRRTL属性，不能只检查Scala注解。GHM源端4位注册已合入生产，同top实际firtool生产综合消除原Critical、226项CDC-3；1742项FIFO数据CE仍需保持/Gray偏斜约束，未完成布局布线与完整Core物理签核。


## 连续恢复与设备效果/计划重基联合验收

长期配置`PalimpsestTwoFaultTestConfig`分别在Seq8、Seq24通过真实f0比较器产生一次FAIL，不能把两次组件错误或一次FAIL加一次计划重基视作两个独立FAIL。`PalimpsestFault40Seq41TestConfig`使Seq40拥有CLINT journal时Seq41达到计划重基门槛；先完成真实错误恢复和journal重放、释放效果后才预留重基。两配置均可由`user_fullcore.sh`构建。

```bash
PALIMPSEST_SW_OUT="$out/concurrency-workload" PALIMPSEST_WORKLOAD_PROFILE=compact-trap-io \
  bash AI/Debug/scripts/rollback/user_workload_build.sh
bash chipyard/scripts/smartelf2hex.sh "$out/concurrency-workload/palimpsest.riscv" \
  > "$out/concurrency-workload/palimpsest.hex"
python3 -B AI/Debug/scripts/rollback/concurrency_regression.py \
  --out "$out/concurrency" --binary "$out/concurrency-workload/palimpsest.riscv" \
  --sbt "$serial_sbt" --jobs 8 --max-cycles 3000000
```

该入口从当前生产分别生成normal、双FAIL和Fault40+Seq41三份完整Core，使用完全相同的ELF和hex，保存每次来源及退出码。`concurrency_scoreboard.py`要求完整程序与128ecall/MMIO/内存/FP/CSR oracle通过。双FAIL精确要求[8,24]、无CANCELLED、恰好两份EVT/Restore/Restart及各自新执行PASS。效果/重基要求原效果至重放只有一个设备A，Seq41未结journal时不能预留或reset；原效果释放后才允许真实维护，而且完整程序中每次reset均须新Seq1 PASS。旧350000周期诊断不能通过这一完整计分入口。

`build_io_observer.py --with-rebase`链接只读IOMSHR和reservation/reset观察器，额外输出路径由`PALIMPSEST_OVERLAP_LOG`指定。不得改写模型字段制造owner或物理证书。`FaultInjection`组件独立检查两个选定Seq各一次真实比较器FAIL、重复同Seq不再次注入以及held result/ACK。该夹具新增序号端口，CheckerRecovery明确固定Seq8。

当前这些新增整核运行处于执行阶段，不能由入口存在推定PASS。实际状态以长期验证矩阵和current_debug_state为准。


## 完整I/O与Seq32物理重基（已实际通过）

长期入口：`AI/Debug/scripts/fullcore_concurrency/io_rebase_scoreboard.py`。
使用同次完整原程序normal/fault/effects/overlap，真实reset划分事务namespace；
执行命令见`AI/TMP/singlecore_function_closure_20261123/io_rebase_injection_scope/scoped_core/program/scoreboard.command.json`。
实际结果1277543周期成功退出、8次reset及8个新Seq1 PASS、48次设备读，
完整128ecall/内存/FP/CSR与唯一FAIL40恢复链均PASS。
9种真实记录破坏由`io_rebase_negative_test.py`拒绝，命令和结果见
`io_rebase_complete_negative_retry.command.json`及同名目录。
该结果只关闭对应功能子任务，History压力与当前最小scratch中断回归仍独立验收。

## 最小scratch与真实MSIP（生产整核回归中）

当前CSRFile组件使用`AI/Debug/scripts/csr_shadow/run.py`和生产`CSR.scala`。
参数与真实命令见`AI/TMP/singlecore_function_closure_20261123/csr_scratch_longterm_production.command.json`；
已实际通过两种scratch镜像、priv/management隔离及normal物理MPRV置位/清零。
宽CSR路由候选已因原Sv39正常整核watchdog被否决，不能沿用其两个IRQ程序的PASS。

实际重新构建及原完整程序在`csr_scratch_production_fullcore/`；
信号完整MSIP在`csr_scratch_irq_signal_fullcore/`，两个新目录中的driver均由当前生产三配置构建驱动。
只读观察器通过`AI/Debug/scripts/fullcore_concurrency/build_interrupt_observer.py --model-dir <既有完整Core模型目录> --out <新的AI/TMP目录>`链接，
运行时设`PALIMPSEST_IO_EFFECT_LOG`与`PALIMPSEST_IRQ_LOG`。
严格计分入口`interrupt_scoreboard.py`实际参数为`--normal`、`--fault`、
`--normal-effects`、`--fault-effects`、`--normal-irq`、`--fault-irq`和新的`--report`。
它要求完整程序和同PC恢复、16次handler结果、16次真实MSIP写1/清0、
CLINT pending/trap逐轮对应，并覆盖pending+recovery stop+未结journal时IRQ被阻止。
当前该整核结果仍在途，不按脚本存在标为通过。

## 慢Checker容量前缀封口（实际反例/候选在途）

原25MHz及50MHz完整Core分别在`slow_checker_pressure_candidate/`和
`slow_checker50_pressure_candidate/`实际watchdog失败，History只占3/5槽，不能计满表覆盖。
原模型只读`boundary_probe/`证明RSU idle先于CDC ready，capacityClosing提前释放，
旧包最终count已到而producer seal/END未到；根因见capacity-seal-release长期记录。
`capacity_seal_handshake_candidate/`仅增加既有seal receipt作为原保持释放条件，
无新增硬件状态，固定runtime jars和源差异，Scala/Chisel已通过，整核构建中。
必须使用同一原25MHz配置/ELF证明first bad消失、旧包END/PASS和完整程序成功退出，
再继续实际History压力门限/封口/释放检查。64项满表组件证据不能替代此整核验收。


2026-11-24 最终验收补强：原Core/CSR整核MSIP的raw/oracle0不能证明中断边界，已观察到后六轮额外trap。必须按 `fullcore_concurrency/README.md` 使用 `interrupt_observer.cc` 的live owner、实际effectPending、journalSafe、starting/hold、精确cause及MEPC/xRET字段。`interrupt_scoreboard.py` 要求16保护轮次与逐次返回；`interrupt_negative_test.py` 不得仅检查原失败轮次。生产IOMSHR ACK前责任缺失原组件反例已保存，最小连续owner修复已组件PASS。

满History必须使用 `pressure_scoreboard.py` 检查完整程序checksum974ea63763416da0、Seq1真实seal/END/count64、实际64/64、回收/Seq前进和结束free64；`pressure_negative_test.py` 的8种损坏须实际拒绝。新 `system_acceptance.py` 聚合最终三Core和Fault40Seq41/压力完整结果及负例，缺运行、缺oracle或任何失败均返回非零。工具不会自动改变原69任务状态。


2026-11-24最终调度前进性回归：`baseline_publication/run.py --suite grantack-preemption`
在真实生产L2接受外层refill后延迟其Grant，随后接受同set另一way的ReleaseData，
使History发布与C嵌套重叠。要求外层E真实完成、History新BASE完整正确、内层
Grant/ReleaseAck、peer权限归还及最终flush全部结束。旧实现稳定循环失败，
最小生产E-only抢占例外通过。该组件结果不替代完整normal IRQ checksum。
对应新完整Core批次 `AI/TMP/singlecore_function_closure_20261123/grantack_preemption_fullcore/`
及 `grantack_preemption_stress_retry/`，保持原10程序、Fault40Seq41、25MHz满History
完整输入和全部严格oracle/负例。用户最新优先级为RTL功能与功能仿真，暂不推进
比特流或时序仿真；综合/STA估算辅助记录并与69项功能状态分开。
