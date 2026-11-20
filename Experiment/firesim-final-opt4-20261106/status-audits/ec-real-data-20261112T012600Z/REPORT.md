# 实际执行接续：2026-11-12

唯一功能基线8491167d84b6d9521b151a743673c1516926a1f8；保持C4/SVB32/L2修复、原target-cycle语义及全部原功能。Native暂停；仅0000:21:00.0/21770433G02LA。前台没有执行FPGA、JTAG、驱动或PCIe操作，没有停止任何活CAD/FPGA/model，也没有改其输入或重复启动。仅新建且错误分类的闲置控制器经严格身份/cgroup核对后退役，见下文。

| 路线 | 完成的真实证据 | 当前实际动作与缺项 |
| --- | --- | --- |
| 原SVB组件 | 完整host/shell postopt200342LUT/12790CARRY8/3DSP，FIT。原和spread均完成布线但时序失败；spread优化checkpoint WNS−1.373ns/WHS+0.001ns | 已实际启动独立resume-r3，从保存的physical-1恢复route/TNS cleanup，修正-preserve与Explore不兼容，未重做综合或3小时physopt。r51 original保持。最多两条组件route。尚无认证bitstream或FPGA样本 |
| SVB完整真实应用replay | standalone原SVB及force-all GG replay正例通过、真实payload mutation拒绝：1759001targetedges、19698670定义输出wordchecks、capture/promote/ACK各659、零mismatch | board-admission-ready已产生；已有两个互斥profile应用follower存活，等待真认证+短定向板测，随后复用同bit，不reflash |
| Canneal metasim | ROI536456cycles/392248instructions，131package全部真实BOOMacceptedPASS、pending0，接受排空332CSRcycles | 原始日志/hash/完整seq-hart join独立复核。CPU数据，不是FPGA或严格checkerDone−samepackageBOOMDone |
| Blackscholes metasim | ROI6166433cycles/3562647instructions，1122package严格匹配PASS、接受排空9655CSRcycles | 完整原ELF与ROI，raw3.19GBlossless stdout独立复核。CPU数据 |
| MCRams完整host资源 | 真实owner-only完整GG已生成；孤立入口405706→24192LUT；实际生成ownerwrapper3245LUT/2906FF/0CARRY8/0DSP/1.5BRAM | 新full-host-capacity-r1已实际启动完整FPGATop OOC synth+opt。此时暂无整机LUT；不含shell，OOC FIT不能当完整物理系统FIT |
| MCRams owner-only完整周期对照 | Plain已完整通过；旧MC因180minhostwatchdog在ROI前退出，保留失败证据，不计PASS | 新MC-only r2已实际启动，同模型ELF/max5Mtarget；仅改hosttimeout57600s，复用成功Plain；不声称执行检查点恢复 |
| 完整Opt4 e0 | e0正常进程保持；最近完整9aepostopt2847382LUT/90740CARRY8/195DSP，超U2801543702LUT | e0 TimingOptimization日志自11-11T09:02:47Z无新阶段。单线程CPU仍计算且IO无变化，仅能证计算，不能证收敛。保留并用MCRams新容量路线并行推进 |

## 本轮实际托管任务

- `ec-opt4-auto-svb-physical-resume-r3-v1-8491167d.service`，controller2377491/start25815868；CPU252–253，64GiB。状态：`D/Opt4-svb-physical-resume-r3-state.json`；日志：`D/cycleprecise-svb-postroute-recovery-r1-20261111/resume-r3-spread-physical1/recovery.log`。
- `ec-opt4-auto-mcrams-full-host-capacity-r1-3656aec4.service`，controller2379596/start25825420；CPU240–247/8threads/128GiB；`D/Opt4-mcrams-full-host-capacity-r1-state.json`，`D/build-logs/Opt4-mcrams-full-host-capacity-r1-20261112/run.log`。
- `ec-opt4-auto-owner-mc-runtime-r2-3656aec4.service`，controller2378806/start25817526、模型2378807；`D/Opt4-mcrams-owner-mc-runtime-r2-state.json`。原Plain不重跑。
- `ec-opt4-auto-svb-actual-hostclock-probe-r2-8491167d.service`，r2恢复已实际运行；独立CPU250–251/32GiB，只改真实MMCM divider24→30进行全时钟STA诊断。不route、不bitgen、不FPGA，不放宽XDC，不改50MHz活任务或认证门。新host频率如果有效仍需独立认证与全shell时序；诊断不是认证。`D/cycleprecise-svb-hostclock-probe-r2-20261112/`。

D=`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106`。所有新长任务均由既有systembroker托管，带单实例锁、持久日志、原子状态、输入哈希；断线不终止。恢复先比对PID/start_ticks/boot_id，活则接管；失败保留并创建独立恢复版本，不覆盖现有证据。不要仅凭broker STARTED/服务存活或CPU增长记结果PASS。

## 未解决及自动后继

原SVB关键瓶颈为时序/拥塞而非总容量，activeIdx扇出5794。原50MHz不通过时不得绕过；r3只有全clocksetup/hold/DRC/fullroute/clockcoverage/pulse/busskew满足才写bit。已有rootcertificate follower独立恢复finalDCP审计→21only锁/实际冲突核对→短定向trace→同bit应用trace，服务保持等待，不重复部署。

MCRams最大的地址统计RegVec并非DefMemory，不能靠盲目加注释解决。正在独立准备严格保持多写优先、复位与debug观察的真实memory转换局部验证；同步/readwrite backend限制如实记录，未证候选不得进入正式硬件。新完整host资源报告用于排序最大瓶颈；容量不够不跑无效place。OOC候选还需完整targetparity和shell物理容量/时序验证。

缺少：认证SVBbitstream与真实板测、完整Opt4FIT与bitstream、统一内存/软件输入的Native–Opt4配对FPGA性能；现有trace观察不提供严格同一package的BOOM executionDone事件，不能把SVBownership lifetime当checker验证延迟。

## 原始证据

- `snapshot-first.json`、`new-jobs-progress-1.json`：原始状态及进程身份。
- `e0-process-diagnostic-first.json`、`e0-nonintrusive-diagnosis.json`：CPU/IO/线程与阶段证据边界。
- `D/cycleprecise-svb-physical-resume-r3-20261112/REPORT.md`：时序失败、脚本参数修复、实际STARTED与认证输入审计。
- `D/cycleprecise-original-svb-gg-stream-replay-r3-20261111/full-result.json` 与 `board-admission-ready.json`：完整应用replay/负例与上板输入绑定。
- `D/cycleprecise-frozen-full-gg-blackscholes-observed-r1-20261111/result.json`：完整Blackscholes真实结果。
- `D/overnight-ec-evidence-audit-r4-20261112/`：独立raw/hash/seq/trace审计已通过，complete.json绑定summary SHA；388项哈希绑定、131/1122完整packagejoin、完整binary连续性和659项完整SVB生命周期均独立核验。

补充：真实activeIdx Q-pin probe已通过，两驱动扇出5794/5774；独立r4条件恢复已排队，必须r51真实退出/空cgroup才能占用其254–255槽，不增加第三route。hostclock r1因诊断输出命令不支持自然失败，未改MMCM；证据保留，独立r2改为list_property/get_property已实际启动。所有原50MHz任务未受影响。

## 独立审计已完成的可复现数据

完整结果：`D/overnight-ec-evidence-audit-r4-20261112/summary.json`，原子完成标记`complete.json`。`workloads.csv`、`replays.csv`、`svb-latency.csv`、`svb-lifetimes.csv`与1cycle精度直方图均已产生。

659项完整SVB ownership生命周期，capture→ACK均值6844.215478、median7150、P958089、P998398、max8753targetcycles；promotion→ACK均值80.968134、median83、P9590、P9994、max98。零删失样本。这是原trace观察且CPU原SVB精确replay验证的ownership/写回事件间隔，**不是FPGA测量、不是checker执行延迟、不是饱和吞吐量**。

全应用replay负例确实在tick1092660的`io_promote_bits_data_0[0]`捕获d7700b1e→d7700b1f的单bit真实payload错误；standalone负例harness退出0表示符合预期捕获唯一mismatch，GG负例退出1。不能仅凭exit0否定或通过，已检查原始REPLAY_SUMMARY/mismatch事件。

## 真实host-clock物理参数试验（不是假放宽约束）

独立DCP内真实MMCME4_ADV divider24→30，自动派生物理host period19.998→24.9975ns；原target RTL、bridge逻辑比率、所有其他clockperiod、target寄存器归属和netlist topology计数不变。没有新增/放宽XDC，没有route/bitgen或访问FPGA。

全设计setup WNS−2.010→−0.424ns，hold+0.001不变，失败setup端点10203→5840。仍NOTCERTIFIED：shell独立PCIe/MIG时序违例没有被host降频消除。可作为下一独立物理profile优先修shell，必须完整全clock STA/hold/DRC/bus-skew再独立认证；不得冒用原50MHz证书或混用频率数据。证据与SHA在`hostclock-real-mmcm-sta-diagnostic.json`。原r3/r51保持。

最新执行协调：新增host40后继评估由svb_physical持有，须等待probe完整结果/封存DCP和实际route槽释放，再单独实现与认证；不将STA试验称timing通过。新地址MCRams原型已做word级SAT与真实优先级负例，但compile-Reg失败，独立修复进行，不能计面积或整机准入。

资源实核（01:42UTC）：409.87GiB MemAvailable、304.43GiB磁盘、load10.19/256CPU；两条SVB物理作业真实RSS各约7.64/7.23GiB、固定254–255/252–253；新完整hostCAD5.09GiB固定240–247，e0主进程14.51GiB并保留原子worker。未据此改变现有并发门，未迁移活任务。详见`physical-cpu-memory-admission-evidence.json`。

## 仅缺陷闲置控制器的安全交接

新建r1 MCRams continuation把未来大型物理作业错误标analysis且缺少完整物理gate。核实其exactsystemdcgroup只有CPUwrapper2395830与等待controller2395831，无任何CAD/model，未提交physicalrequest；保存全部state/job，退役并disable仅此闲置控制服务，替换为独立严格r2。所有area/MC/e0/SVBr3 producer PID/start_ticks/boot_id前后活身份不变，未改输入。证据`idle-continuation-handoff/{before.json,complete.json}`，不是停止正常综合或实验任务。

## host40完整自动链路已实际安装

独立immutableinstaller已实际root执行，三systemd服务运行：`ec-opt4-svb-host40-physical-r1.service` PID2402382，state=`WAITING_R51_EXACT_CGROUP_RELEASE_NO_CAD`；`ec-opt4-svb-host40-follow-r1.service` PID2402383，等待独立物理bitstream；`ec-opt4-svb-host40-application-follow-r1.service` PID2402384，等待真认证及短板测。没有第三route、FPGA、JTAG或driver操作。详细actualstate/PIDstartboot核对见`host40-installed-real-services.json`。

host40占250–251，但只有r51退出+共享global物理锁（与r4互斥）+最多1existingroute+原128GiB/96GiB/load门成立后才CAD。保留真实MMCM30和其他clockperiods，严格全clocksetup/hold/DRC/routecoverage/pulse/busskew。独立profile=`OriginalSVB32-component-trace-host40`，不接/改原50MHz证书或输入。驱动DONE/token轮询、AXI异步converter等9项来源审计通过；最终仍必须实际板测。已有有效50MHz组件自然赢出，host40跳过重复部署。同bit完整replay服务不reflash，只拿共享21两锁和准确已部署bit/source绑定。

认证后数据将记录物理host频率和targetcycle事件，物理host周期不得用作体系结构target频率。没有开始真实板测以前不计FPGA数据。

## 完整MCRams后继已实际接通

纠正r2consumer已运行PID2403708；只读接管原完整hostCAD及MC周期对照。真实OOC容量+有限targetparity均通过才提交准确module类shell物理作业，必须原area释放exactjob/共享大型锁+256GiB内存/150GiB磁盘，不开第三大型综合。复用FPGAToppostopt DCP，仅综合小F1Shim/physicalwrapper，拼11个原shellDCP并在place前做真实topopt容量；失败保留checkpoint。全clock比例/覆盖、route、setup/hold、pulse、bus-skew与DRC门均已补齐。

完整独立runtime rootfollower `ec-opt4-mcrams-owner-runtime-follow-r1.service`已实际安装，PID2405137，等待真实物理bitstream和认证。13普通程序软件/images复用Native已绑定ELF输入；7生成接口文件6个逐字节相同，1个implementationXDC为精确物理实例名改变，目标clock比率仍实际检查。private runtime=`W/runtime/Opt4-fit-mcrams-owner-r1`，复合hosttransform/sourceID c8e5bfa5…与target3656明确分开，不能冒充未变更的原host。认证后复用既有严格21onlysmoke→功能/checker/排空→13程序首轮优先队列。未生成证书、未部署、未采FPGA样本。安装实证`mcrams-composite-runtime-installed.json`。

本轮接续快照：`snapshot-final.json`；正常CAD/FPGA/model未停止，Native未恢复，新FPGA测量0。所有后继在systemd/broker下运行或等待严格门，不依赖本前台会话保持连接。
