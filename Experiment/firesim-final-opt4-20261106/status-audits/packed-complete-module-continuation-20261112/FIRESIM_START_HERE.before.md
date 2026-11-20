最新 FPGA 实测（2026-11-12 18:31 CST）：**首个原版 SVB 认证 bitstream 已生成并实际21-only上板，定向与真实应用 replay 均PASS。** r7K最终 WNS/TNS0.000/0.000ns、WHS/THS+0.001/0.000ns、Setup/Hold零违例，255876网络全布通、DRC0Error/49保留Warning，独立认证通过。定向372targetedges/42291输出值PASS；同bit应用1759001targetedges/19698670wordchecks、659capture/promote/ACK、零mismatch，replay24359.3targetcycles/s（含MMIO）。659样本capture→ACK平均6844.2/P958089targetcycles；这是捕获流量经SVB组件FPGA完整验证，**不是完整EC或8项PARSEC性能**，checker/rollback未测。认证/板测/延迟CSV见[本轮真实结果](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/svb-r6-continuation-20261112/REPORT.md)。

完整owner-MCRams post-opt已完成并保存DCP：**2420482LUT/80990CARRY8/192DSP/1696013FF/898.5BRAM/零blackbox，NOTFIT，缺1116802LUT**（完整FPGATop生成host，shellexcluded）。后继已消费正式结果，不运行无效P&R。最大addressStats881587LUT；新packed候选8192完整尺寸向量PASS，单bucket配对5211→4879LUT，仅局部实测，须完整模块parity/面积后再合入。现有8d整机DUT综合、r51/地址GG及无人值守正常任务保留；仅8491167d等价优化、21-only、CPU PARSEC控制不变。此前条目为历史状态，不覆盖本条新FPGA结果。

最新有效性能数据（2026-11-12 10:42 CST）：首个匹配源码CPU GoldenGate对照已原子提交，Canneal project400 Native312165cycles/392248inst，冻结EC536456cycles/392248inst，输出均PASS；131checker完整PASS、pending0、排空332cycles。EC/Native=1.718501×，含尾排空=1.719565×。每组n=1、不同启动ELF/链接cache初态，不能称FPGA slowdown。独立双重审计、CSV、PDF/SVG见[结果入口](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/paper-matched-source-cpu-comparison-r2-20261112/README.md)。Blackscholes已自动接续完整Native CPU运行，消费者r2已安装自动审核导出。

SVB复用DCP的新A策略已到Post Router Timing，尚无认证bitstream；失败后A→B→条件C/D已托管。MCRams完整host有真实FSM/BRAM映射阶段推进，LUT/FIT仍未知，不能冒用旧9ae报告。论文CSV/统计/图已[独立封存](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/paper-real-ec-data-r2-20261112/README.md)。Native FPGA暂停，21-only；所有正常CAD与模型保持运行。[本轮完整记录](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/fpga-paper-sprint-20261112T020000Z/REPORT.md)。

最新实做（2026-11-12 10:15 CST）：SVB host40关键shell物理修复A已从封存DCP实际运行，CPU224–225/64GiB；14条真实高扇出FD-Q查询通过，不重新综合。A失败自动B；独立r3条件服务也已安装，只在r2实际失败且exact cgroup清空后复用同槽进行clock-skew/局部重布线。完整66clock/时序/DRC门不降，认证后21-only部署与同bit应用replay已接通。MCRams完整host仍无新LUT/FIT；地址RAM局部周期对照已PASS并实际启动Reg/MemMC面积配对。匹配Native CPU模型r1缺原NativeROI driver自然失败，独立r2修复中，Native FPGA不恢复。尚无认证bitstream/新FPGA样本。Canneal ELF d0d0e9ae…实际project400，旧project64 human标签勘误，原数值/hash不变；Blackscholes为project64。

[本轮真实任务、资源与恢复入口](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/fpga-paper-sprint-20261112T020000Z/REPORT.md)。以下旧状态保留历史，以最新状态与已绑定结果为准。

最新补充（2026-11-12 09:55 CST）：SVB50r3实际继续route/physopt；真实host40降频STA完成但shell WNS−0.424ns，独立物理/认证/应用3服务已安装，等现有route释放，不改活50MHz任务。MCRams完整hostCAD、同binaryMC重跑、严格r2后继与独立复合runtime rootfollower均实际运行/等待，13软件已绑定；新整机LUT仍未知。地址RegVec→258R/256W RAM局部原型已进入MemMC运行，面积和完整等价尚未通过，不得先合。正常任务保持，Native暂停，严格21-only。

# 当前真实进展：2026-11-12 09:31 CST

独立证据审计现已完成：388项SHA绑定、131/1122完整校验packagejoin、659项完整SVB生命周期及完整原始日志均通过；[CSV与原始证据](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/overnight-ec-evidence-audit-r4-20261112/REPORT.md)。真实MMCM host40MHz诊断也已完整结束，实际period24.997ns，全clock WNS−0.424ns/WHS+0.001ns，仍未认证；不修改原50MHz活任务。

原SVB组件已完成布线，但尚未通过时序；保存的spread物理优化结果 **WNS−1.373ns / WHS+0.001ns**。已实际启动独立resume-r3，直接从该checkpoint继续route/TNS cleanup，修正Vivado不兼容参数；原r51活任务保留。**尚无认证SVBbitstream或新FPGA样本**。认证→21-only短定向板测→同bit完整应用replay的既有服务均活，等待真实物理结果。

完整真实应用SVB的CPU replay已通过：**1,759,001targetedges、19,698,670定义输出wordchecks，capture/promote/ACK各659，零mismatch，真实payload mutation拒绝**。Canneal完整GG：ROI **536,456cycles /392,248instructions**、131acceptedPASS、排空332CSRcycles；Blackscholes：**6,166,433cycles /3,562,647instructions**、1122acceptedPASS、排空9655CSRcycles。这些是CPU metasim/RTL数据，未当作FPGA实验或严格checkerDone−BOOMDone延迟。

MCRams新完整FPGATop OOC synth+postopt容量作业与owner-only完整Canneal同binary重跑均已**实际启动**；尚无新整机资源报告。完整生成ownerwrapper实测3245LUT/2906FF/0CARRY8/0DSP/1.5BRAM，局部入口405706→24192LUT，不能替代整机FIT。e0保留，但TimingOptimization日志已约16小时无阶段更新，仅证单线程继续计算；最近完整postopt仍9ae **2,847,382LUT/90,740CARRY8/195DSP，NOTFIT，缺1,543,702LUT**。

Native暂停，仅8491167d原功能/targetcycle等价，严格21-only。所有新长任务由既有systembroker托管，先核验PID/start_ticks/boot_id再接管，活任务不重启、不改输入。根前台本轮没有操作FPGA/JTAG/驱动/PCIe。独立真实hostMMCM频率诊断仅STA、不route/bitgen/device，也不能冒用50MHz认证。

[本轮实际服务、原始状态、失败恢复与证据](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/ec-real-data-20261112T012600Z/REPORT.md)。下面旧进度仅保留历史，不作当前放行条件。

---

# 最新实际结果：2026-11-11 22:27 CST

Canneal完整GG metasim已通过：**ROI536,456cycles /392,248instructions，131package实际BOOMaccepted PASS、pending0，ROI后接受排空332cycles**。这属于CPU metasim，尚非FPGA或严格checkerDone−BOOMDone延迟。完整512bit SVB trace r5实际运行，Blackscholes完整原ELF metasim也已启动。

原冻结SVB组件**容量FIT：200,342LUT/12,790CARRY8/3DSP**；原/spread均继续路由，spread有新overlaps下降。**尚无认证bitstream或真实SVB FPGA样本**。原/alternate认证→21-only定向板测→同bit完整应用replay的服务均已实际安装；全trace前置正/负例及force-all规则已验证。

MCRams真实35R1W81存储入口**405,706→24,192LUT，节省381,514**；owner-only整机GG与结构审计已完成，实际模块面积及成对metasim编译排队。局部收益不等于完整DCache或整机FIT。完整Opt4最近9ae仍NOTFIT2,847,382LUT；e0综合保留，尚无新面积。

Native暂停，唯一功能基线8491167d，严格21-only。实际版本、PID、结果、失败恢复及自动链路见 [本次报告](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/ec-real-data-20261111T140811Z/REPORT.md) 和 [原始状态快照](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/ec-real-data-20261111T140811Z/snapshot.json)。新增：同环境冻结Plain/MCRams Canneal的ROI、输出与262条checker本地事件周期/值精确匹配。严格物理失败恢复r2、同bit应用replay与owner-only纯运行timer均已实际安装。SVB spread overlaps18,243，仍无认证bitstream或板测。

以下旧状态作为历史保留，以本条和真实state/result为准。

最新实测与接续（2026-11-11 21:29 CST）：**三条路线均已实际执行。** 原版 SVB 组件连 host/shell post-opt **200,342 LUT /12,790 CARRY8 /3 DSP**；独立 spread 分支已完成 place/physopt 并进入 route，尚无认证 bitstream 或 FPGA 测量。DCache 真实 35R1W81 存储入口 MCRams **405,706→24,192 LUT（−381,514，−94.037%）**，周期对照通过；这不是完整 DCache/整机收益。仅新增 ownerImageMemory 注释的独立整机 Golden Gate 已启动，目标 FIR 不变，保留全部 generation/debug 观察。

Canneal 原 GG 完整 metasim 实际输出通过：**ROI 536,456 cycles /392,248 instructions**，host 3,136.1126s，131 local checker RESULT；BOOM accepted/全排空独立观测还在运行，不能先计通过。真实 SVB binary startup replay **10,000 cycles /109,989 定义输出 word 检查、0 mismatch**，真实应用 trace/replay 自动后继已接通。此为 CPU metasim/RTL 证据，尚无 SVB 或完整 Opt4 FPGA 样本。

完整 Opt4 最近完成 9ae post-opt **2,847,382 LUT /90,740 CARRY8 /195 DSP，NOT FIT，缺1,543,702 LUT**；e0c3737f 活综合保持，暂无该版本新资源报告。Native 继续暂停，严格 21-only。

[本轮真实结果、服务、日志与恢复入口](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/ec-real-data-20261111T1325Z/REPORT.md)。当前状态以本条、各领域原子状态和已绑定完整收据为准；以下旧状态保留为历史，不作为当前放行条件。

---

最新实测（2026-11-11T10:12:32.326568+00:00）：**原SVB32独立组件连同host/shell post-opt FIT**：200,342LUT/12,790CARRY8/3DSP，place_design已运行。它不是完整C4；完整Opt4仍NOT FIT，缺1,543,702LUT。无新bitstream或上板样本。完整Canneal metasim已到453,725targetcycles，未结束不计通过。[全部真实数据与恢复入口](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-two-route-results-20261111T095539Z/REPORT.md)。

最新接续：完整GG启动探针实际10,001cycles/FMR33.44；完整Canneal metasim已运行（ec-opt4-frozen-full-metasim-sample-r1），尚未验证。原SVB component host DUT实测119,711LUT/11,724CARRY8/0DSP，已进入implementation；独立21-only认证/部署/trace跟随服务ec-opt4-original-svb-onboard-r1已实际启动，等待真bitstream及物理时钟审计，尚未上板。完整Opt4仍无bitstream或FPGA样本。当前数据及全部服务入口见[本轮报告](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-two-route-results-20261111T095539Z/REPORT.md)。

# 最新两路线实测（2026-11-11 17:55 CST）

9ae9a7fc顶层post-opt **2,847,382 LUT /90,740 CARRY8 /195 DSP**，NOT FIT，超出U280 **1,543,702 LUT**；比8da少368,301LUT，已在place前容量守卫安全结束。e0和完整DCache/地址maps继续，未认证完整bitstream、无完整Opt4 FPGA样本。

路线A实际完成：GG RAM 4R2W 97,851→352LUT、35R1W 388,931→3,289LUT；各8,192targetcycles测试通过。相同target的GG metasim通过，时间复用FMR约38。原SVB127输出×333有效cycles=42,291值逐周期PASS，原版完整target RTL新Canneal project400通过，ROI485,329cycles/392,248instructions、136PASS、尾排空262cycles、host2107.68s。这是RTL数据，不是FPGA或Linux正式simmedium。完整host metasim已编译，follow-r3执行有界启动探针；独立原SVB componentFPGA-r2构建实际启动，尚未上板。

[本轮报告与原始证据](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-two-route-results-20261111T095539Z/REPORT.md)。systemd状态/日志/恢复规则在报告中；Native暂停、仅8491167d功能/周期等价、严格21-only。以下旧进度保留为历史。

# 最新实际推进（2026-11-11 16:27 CST）

9ae综合内部优化完成，真实单元统计3182510个LUT1–6/89672个CARRY8；工具网表翻译中，正式物理CLB LUT、DSP和顶层post-opt报告尚未产生，不能计算新版本准确FIT缺口。e0及d9完整DCache面积仍运行，未进入物理实现，无认证bitstream/Opt4样本。

d9完整冻结DCache8192周期回归PASS；3656独立字段读优化真实GG/7ABI、完整生成DCache符号结构比较及实际写数据负例PASS（只映射60处相同源码行的诊断行号元数据）。准确异步读端口各561→35/518/4/4，保留512generation观察；无面积收益结论。新完整模块面积请求已排队。只保留一个8d后继等待器，未触碰任何活综合；无人值守第30轮继续，Native暂停，21-only。

真实报告与恢复入口：[REPORT.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-field-cycle-and-successor-20261111T074000Z/REPORT.md)。以下旧状态保留为历史。

# 最新执行（2026-11-11T07:13:24.854581+00:00）

9ae9a7fc已完成Timing Optimization并进入Technology Mapping；e0正常DUT综合。二者仍无新整机资源报告/FIT结论。d9真实GG/7ABI、生成存储512正向+4真实写数据负例通过；完整DCache实际综合已启动。完整cycle-r3 C++接口失败保留，r4已修复Verilator端口编码/宽向量API并复用原模型实际编译，未改RTL。新8d50489a精确组合预检通过，prep-r2实际托管等待真实面积+完整周期门，随后自动GG/ABI/CAD/21only认证。未开第三整机，Native暂停。

最近完成整机仍旧8da：3215683LUT/92789CARRY8/195DSP，旧版超U2801912003LUT，不能当9ae/e0结果。完整DCache面积和当前FIT缺口尚未知，无认证bitstream/Opt4FPGA样本。详见[真实执行报告](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-field-map-and-next-20261111T070420Z/REPORT.md)。以下保留历史记录。

# 最新实际推进（2026-11-11T06:08:08.840480+00:00）

9ae/e0两条整机综合保持，均暂无新资源/FIT报告。真实生成存储512/512分区形式证明及真实写数据位翻转负例全部通过（存储transition cut，不是完整DCache/整机形式证明）。完整DCache旧评估发现74752bit打包memory的Vivado推断/默认回退上限错误，已保留证据并实际启动独立full-pair-r2恢复，后继prep-r3/CAD-r5已重新绑定且不启动第三整机。

新等价结构候选d9d73262拆为81/32/32/1bit四块物理存储，源关系SAT/改动源码编译/冻结参数通过，实际GoldenGate正在运行，尚无面积或整机准入。最近完成整机仍旧8da：3215683LUT/92789CARRY8/195DSP，超U280 1912003LUT；不能将其当9ae/e0新结果。无认证bitstream、无Opt4 FPGA样本。Native暂停、严格21-only。[最新真实证据与恢复入口](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-generated-proof-and-progress-20261111T053104Z/RECOVERY_REPORT.md)。以下旧状态为历史。

# 最新实际推进（2026-11-11T05:48:20.759777+00:00）

9ae9a7fc实际完成跨层面积优化并进入Timing Optimization；e0c3737f实际DUT综合继续，均尚无新整机面积/FIT报告。DCache真实GG与7项ABI通过，完整模块匹配面积评估运行；265176→89636LUT仅为保留全部generation观察的存储边界收益。实际生成存储联合SAT超时后，分区证明服务已启动，当前120/512，未完成不记全通过。99c25302组合源码/全部改动编译/冻结参数/地址RTL一致性预检通过；下一整机仍受完整模块面积门和无第三整机限制。

最近完成整机仍8da：3215683LUT/92789CARRY8/195DSP，超U280 1912003LUT。尚无认证bitstream或Opt4 FPGA样本。仅8491167d等价面积优化，Native暂停、严格21-only。真实证据与持续状态：[REPORT.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-generated-proof-and-progress-20261111T053104Z/REPORT.md)。以下历史状态以本条和状态文件为准。

# 最新实际推进（2026-11-11T04:57:48.249009+00:00）

9ae整机保持，e0已在独立8核/128GiB服务中实际进入DUT综合；二者均尚无新资源报告。DCache源绑定组合证明通过、GoldenGate进行中；真实完整DCache匹配面积作业等待该RTL。保留全部generation观察的存储边界265176→89636LUT，节省175540，不能当完整模块或整机收益。e211完整地址正在map。99c25302独立组合及既有21-only认证/runtime模板已准备，但受真实面积/证明门和无第三整机守卫约束，未获准整机。

本轮实际操作、进程身份、资源与完整证据：[REPORT.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-dcache-full-and-dual-dut-20261111T045748Z/REPORT.md)。最近完成整机仍8da：3215683LUT/92789CARRY8/195DSP，NOTFIT。无认证bitstream、无Opt4FPGA样本。Native暂停，仅8491167d功能/周期等价优化，禁止功能扩展与e2/全局设备操作。

# 当前执行范围：原最终 Opt4 的等价面积实现（2026-11-11 用户最新指令）

唯一功能基线为 `8491167d84b6d9521b151a743673c1516926a1f8`，v1Config/C4/SVB32/L2 report-permission repair。
后续 RTL 只允许功能与周期语义等价的面积优化，完整保留原已有 EC、checker、rollback、排空和观测行为。
独立功能扩展已停止，仅保留历史分支与证据，禁止合入、构建、部署或作为实验完成前提。
此前关于继续新增架构恢复的任务已被本条撤销。

`9ae9a7fcf231a75259e23973b12a93896a443cbb` 整机综合继续运行，实际源码 ID
`3791dd0e8f7d9c380500cd37f11ece4c92e275bc399894780228fa61449df561` 已重新核验。
没有新增恢复模块进入此版本；冻结 tag 仍指向原提交。当前版本资源报告和 FIT 结论尚未产生。
上一完成版本 `8da24a26` post-opt：3,215,683 LUT、92,789 CARRY8、195 DSP，NOT FIT，超出 1,912,003 LUT。
已验证地址统计候选 `00847dc2` 完整模块 OOC：872,880 LUT、30,842 CARRY8、0 DSP；不是整机 FIT 结论。

无人值守服务 `ec-opt4-unattended.service` 保留，后续按原冻结等价优化推进：
NOT FIT/可恢复失败 → 保存证据 → 选择并组合验证收益最大的等价候选 → 下一版整机；
FIT → 立即布局布线、时序/DRC、bitstream 和认证 → 21 卡安全边界的原方案真实实验。
Native 继续暂停，只允许 `0000:21:00.0` / `21770433G02LA`。禁止 e2 或全局板卡/驱动操作。

新 CPU 服务在执行前使用 `scripts/opt4_frozen_scope.py` 检查最新 policy、输入、提交祖先及源码树；
功能扩展分支即使改名也不得进入后续作业。该检查不能替代模块、组合和周期等价验证。
当前综合及已运行面积验证进程未重启；只结束了读取旧指令的 AI 第 19 轮，随后由现有服务按新范围续轮。

状态与恢复入口：

- `Experiment/firesim-final-opt4-20261106/Opt4-fit-bucket-tag-cad-state.json`
- `Experiment/firesim-final-opt4-20261106/unattended-opt4/state.json`
- `Experiment/firesim-final-opt4-20261106/unattended-opt4/campaign-policy.json`
- `Experiment/firesim-final-opt4-20261106/unattended-opt4/WORKER_PROMPT.md`
- `Experiment/firesim-final-opt4-20261106/status-audits/frozen-only-scope-20261111T023049/`

重连先核验 PID、start_ticks、boot_id 和子进程；存活即接管监控，不重复启动。
原始日志、已完成结果和候选全部保留。以下较早条目仅作历史记录，执行范围以本节为准。

# 最终 Opt4 FireSim 实验统一入口

## 2026-11-11 11:42 CST：组合验证/GG/ABI完成，下一整机已进入安全等待队列

`9ae9a7fc` 活整机未重启，仍在 DUT 综合，当前尚无其 LUT/FIT 报告。上一完整 post-opt **3,215,683 LUT /92,789 CARRY8/195 DSP**，LUT 缺口 **1,912,003**。

新组合 **e0c3737f** 修复了遗漏辅助源码与验证脚本路径错误，已通过源绑定组合检查、两模块重新生成 RTL 与已验证版本的一致性、整机 GoldenGate、冻结参数/类来源及7项ABI核对。13项配对软件准备完成。其整机 CAD **已排队、未启动**，由现有守卫等待9ae真实NOT FIT退出后自动接续；认证前 runtime 请求保持等待，不操作FPGA。

独立 **1a571775** 正验证只改写退休清零译码的结构候选；原大规模SAT超时已保留，改用明确记录的逐位模板证明与64位提升，再做完整模块对照/面积。未经证明和实测不合入。小收益DSP/packed算术探针已筛除。Native暂停，21-only。实际作业/失败恢复/证据：[REPORT.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-structural-acceleration-20261111T034259Z/REPORT.md)。


## 2026-11-11 09:45 CST：SVB组合验证/GG/ABI及13项软件准备完成；持续迭代继续

当前整机 **9ae9a7fc仍在DUT综合**，尚无其真实整机FIT结果。最近完成的8da24a26完整post-opt为 **3,215,683 LUT /1,303,680、92,789 CARRY8、195 DSP**，缺口 **1,912,003 LUT**，已自然停在容量门。

独立 **f2d2ca3e** 已通过源绑定组合证明、完整SVB127输出/4096周期对照、真实类/参数核对、GoldenGate及7项ABI核对，13项软件与Native配对绑定也已实际完成。DCache **51a2bd25** 的生成SAT、8192周期及实际256组×2路类型检查通过；匹配面积排队，完整DCache等价尚未成立。后台第16轮已产生 **27f7e7d6** 复制序列表并通过局部SAT/拓扑/8192向量，待完整对照和面积。

仍无认证bitstream、无Opt4 FPGA样本。综合/验证失败不停止持续优化；保留当前活整机，只接入已证明且有实测显著收益的独立组合。Native继续暂停，严格21-only。完整架构restore/restart仍有真实设计接口缺口，已另列契约，不能把SVB invalidation当作架构恢复通过。

本轮实际操作、版本/资源/失败恢复及自动接续条件：[REPORT.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-continuous-20261111T014515Z/REPORT.md)。当前任务入口：[state.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/unattended-opt4/state.json)。以下旧日期状态作为历史保留。

## 2026-11-11 09:01 CST：post-opt门禁已退出；9ae综合继续；13项软件绑定完成

完整顶层8da实测 **3,215,683 LUT、92,789 CARRY8、195 DSP**，LUT超出 **1,912,003**。`NOT_FIT_POSTOPT` 已落盘，原CAD自然退出，保留optimized DCP，未布局布线。9ae9a7fc新整机正在DUT综合，尚无其整机面积结果。

新增实测：SVB选择器 **43,898→3,230 LUT**、**5,952→124 CARRY8**；局部组合证明、反例和8192向量通过，完整candidateSVB映射已完成。此收益不冒充整机收益。13项普通程序已完成新派生版本的真实软件/Native配对绑定。故障注入及架构restore/restart接口仍未建立，不写成通过。

持续任务、独立恢复、所有资源数字和证据见 [REPORT.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-acceleration-20261111T010108Z/REPORT.md)。Native保持暂停，严格21-only，未操作FPGA。下文旧状态按历史保留。

## 2026-11-11 08:46 CST：整机 post-opt NOT FIT；9ae9a7fc 新整机综合已启动

本节覆盖下文旧的“整机资源尚未产生”。完整顶层 post-opt 实测 **3,215,683 LUT / 1,303,680**、**92,789 CARRY8**、**195 DSP**；LUT 超出 **1,912,003**。优化检查点已保存，容量门禁阻止布局布线。现有 8da CAD 不重启。

精确候选 **9ae9a7fc** 已完成参数/来源/GoldenGate及7文件ABI实测核对，**独立 DUT 综合已实际启动**：`ec-opt4-auto-bucket-tag-cad-r1-9ae9a7fc.service`；状态 `Opt4-fit-bucket-tag-cad-state.json`，日志 `build-logs/Opt4-fit-bucket-tag-cad-9ae9a7fc/`。地址OOC **990,905 LUT /55,418 CARRY8/0 DSP**，不推算新整机面积。独立SVB选择、退役宽读候选正在证明/映射，不未经组合验证叠加。

权限、ccache、显式证据manifest、完成收据复用校验和动态快照已修复并实际验证。只重载控制服务；活CAD/GG/优化worker保持。自动认证启动请求已提交，等待真实bitstream；Native继续暂停，严格21-only。fault注入后的架构restore/restart仍缺可用验证接口，不可将正常checker/drain通过当作rollback通过。

本轮实做、版本、PID/日志、恢复规则和完整证据见 [REPORT.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-acceleration-20261111T0046Z/REPORT.md) 与 [audit.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-acceleration-20261111T0046Z/audit.json)。

更新时间：2026-11-10T16:27:08.870068+00:00。用户已授权必要构建、目标卡无具体冲突时的安全部署及实验；无需额外独占凭据。未更新系统驱动、板卡固件或冻结 Tag，未主动重启服务器。

**当前最高优先级：Opt4 硬件 bitstream。Native 调度已在安全边界暂停并禁用自动启动，网络软件修复暂停；只有用户要求恢复后才续跑。** 暂停证据：[Native-user-paused.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Native-user-paused.json)。Opt4-fit CAD 与独立认证/21-only 首验服务继续运行；下文 Native 自动续跑描述为暂停前历史。

**全套共 16 个程序；Native 正式通过 15/16；Opt4 正式通过 0/16；有效配对 0/16。** 正式通过要求相同版本3轮；小输入功能验证另计。逐项 ELF、输入、命令、线程、ROI、正确性、缺项和队列见 [PARSEC_SUITE_PROGRESS.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/PARSEC_SUITE_PROGRESS.md) 与 [parsec-suite-progress.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/parsec-suite-progress.json)。本地正式列表包含13项 apps/kernels及3项netapps，freqmine亦在范围内；未把部分集合称为全套结果。

有效 FPGA PARSEC 样本 80，正式样本 45，有效 smoke 6。当前 C4 CAD `RETIRED_NOT_FIT`；未获得有效 C4 样本前不计算 Correction/Native。[results-summary.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/results-summary.json) 只计原子完成的有效样本并保留失败/缺项。

## 2026-11-10 18:45 CST：Opt4-fit 已进入真实整机综合

<!-- unattended-opt4-20261111 -->
当前硬件优先无人值守入口：[UNATTENDED_OPT4.md](/data1/gzh/EC/firesim/final-opt4-20261106/UNATTENDED_OPT4.md)。`ec-opt4-unattended.service` 已启动，状态/轮次/请求在实验目录 `unattended-opt4/`；Native 后续调度暂停。现有 CAD/模块活任务保持。独立模型网络仍有 SSH 代理依赖，详见该入口，不能把服务 active 当作 FPGA 成功。

本节替代先前“等模块评估后才启动整机”及“保留原冻结导出”等旧状态。独立硬件 `Opt4-fit-C4-SVB32-20261110`：commit `8da24a269b98a0d6a8f57b030353a310812c4344`，source ID `7e77ddda28298ac88be13c28dbe98771982bc6ca9587f810adf875bffd580cc1`。不冒充冻结 `8491167`。

- 整机参数核对、elaboration、五个修改类的真实加载来源、GoldenGate 已完成。新 RTL 在 `Opt4-fit-20261110/builds/system-8da24a26/goldengate-attempt-1/`，绑定在该 system 目录的 `inputs.json` 及 `Experiment/.../Opt4-fit-rtl-state.json`。
- `ec-parsec-opt4-fit-cad.service` 已实际进入 `synth_design`（启动时 controller PID 2790677、wrapper PID 2790743；重连须再核验 start_ticks/boot_id）。独立目录 `Opt4-fit-20261110/builds/cad-8da24a26/`；状态 `Experiment/firesim-final-opt4-20261106/Opt4-fit-cad-state.json`，日志 `build-logs/Opt4-fit-cad-8da24a26/` 和 `jobs/opt4-fit-cad/console.log`。
- 仅复用逐哈希核对的 11 个未变 U280 平台 IP DCP。已比较 FPGATop 外部接口和 defines；冻结 DUT DCP/cache 不进入新综合。新 DUT → 新顶层综合 → 拼接与黑盒检查 → opt_design。保存优化检查点、LUT/CARRY8/DSP/FF/BRAM/URAM 及层次报告后判容量；NOT FIT 停在布局前。容量通过才自动 place/physopt/route、setup/hold、DRC、bitstream；省略全部非实现必需的 funcsim Verilog/VHDL 网表导出。
- 当前新整机资源**尚未产生，FIT 尚不能判断**。地址统计 OOC 两个活 worker 保持运行，不阻塞整机；全尺寸地址原/新 RTL 6144-cycle、52 输出比较已通过，非全设计等价证明。模块资源及权重排名：`build-logs/Opt4-fit-modules-20261110/{FIT_STATUS.md,RESOURCE_PRIORITIES.md}`。
- 冻结原 DUT opt_design 后 LUT 5,741,353/1,303,680、CARRY8 366,817/162,960，确认为 NOT FIT。已按授权结束原无效导出 cgroup，确认所有原 PID/start_ticks 身份退出；原 CAD 与 wall-limit guard 禁用，原 CAD 状态 `RETIRED_NOT_FIT` 并有恢复完成守卫，防止重连再次启动。收据 `frozen-cad-retirement.json`；保留所有 DCP/日志/容量证据。独立的冻结完整顶层 opt_design 诊断继续，其容量门会阻止无效布局。
- 新 GoldenGate 的 const.h、const.vh、defines、两份 XDC、DTS、Dromajo 参数共 7 项与已编译 C4 host driver 输入逐字节相同。已独立复制原 efficiency driver 并记录**兼容复用，非重新编译**：`runtime/Opt4-fit-C4-driver-compatibility.json`、`runtime/Opt4-fit-8da24a26/FireSim-xilinx_alveo_u280`。不修改冻结/现有 runtime 收据，不代表 FPGA 验证已通过。
- 新硬件目前无 bitstream、无 Opt4 正式样本、未发布到冻结 C4 首验入口；后续认证须使用独立派生 profile，在 21 卡安全边界接入唯一首验/调度，checker/排空/输出通过后才允许正式样本。Native 活任务及 21-only 调度保持不变。

恢复时用 `job_service.py audit opt4-fit-rtl`、`job_service.py audit opt4-fit-cad` 只读审计；活进程只接管监控，失败已确认退出才续缺失阶段。成功阶段通过源 ID、输出哈希收据复用，不重跑 DUT；不使用统计快照冒充任意指令/CAD 恢复点。启动命令为 `systemctl start ec-parsec-opt4-fit-{rtl,cad}.service`，**仅在审计确认无活实例且确需续跑时使用**。不要重启 Native 或触碰 e2/global XDMA/PCIe。


## 2026-11-10 地址统计独立 round3（不修改当前整机输入）

- 当前整机继续固定 `8da24a269b98a0d6a8f57b030353a310812c4344` / source ID `7e77ddda28298ac88be13c28dbe98771982bc6ca9587f810adf875bffd580cc1`。`Opt4-fit-cad-state.json` 的 DUT/top/opt 资源报告尚未生成时，不可声称 FIT 或给出局部相减的预测值。容量通过后按已有服务自动进入 place/route/timing/bitstream，不等待 round3。
- 独立 worktree `Opt4-fit-address-round3-20261110`，branch `opt4-fit/address-round3-20261110`，commit `aca893e0aa3f7e23e16067ab40713afea41558e8`，source ID `d5ca949536b50c2d6bf2f9ef1c2748282f88bac0fa5f2d4cc7ffa5b6c94feb28`。仅修改地址命中归约组合逻辑，保留所有 64 位状态/输出、256 packet slots、队列与表容量、EC/checker/rollback、原事件/溢出/error/ROI/STOP/drain周期语义。
- 原访问 size 是2位，最多8字节；每个 masked hit 最多8 byte、3 word4、2 word8、1 line，包括跨line裁剪。Yosys已完成96输入位的无约束通用上界证明；8项/80项归约分别在136/1360输入位域、上述已证明边界条件下通用等价证明通过。每级归约仅用自身子树项数的严格上界，不把每个叶子先拓展成最终宽度。该证明不等于整机等价。
- `ec-parsec-opt4-fit-address-round3.service` 托管后续全尺寸 elaboration、原始冻结RTL与新RTL的6144周期/52输出对照、同设置Vivado归约探针/三种64位更新与溢出实现探针、完整地址模块综合。更新探针尚未写入候选生产源码；只有真实 LUT/CARRY8 收益及通用74输入位证明后才评估下一独立提交。不得提前报告收益或移入当前整机。
- 状态 `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-address-round3-state.json`；持久日志 `jobs/opt4-fit-address-round3/console.log` 与 `build-logs/Opt4-fit-address-round3-20261110/`，源快照、patch、binding均保留。恢复先 `job_service.py audit opt4-fit-address-round3`；活PID/start_ticks/boot_id只接管监控，已退出失败按收据恢复缺失阶段，不覆盖成功结果。
- Native Netstreamcluster r2的result/complete身份及结果哈希均核验有效，ROI 99,353,979,454周期、Host 6047.767924856秒；当前正式44/48，r3继续在21卡。未触碰e2、驱动或PCIe，未重启Native、当前整机综合或调度器。


### 地址 round3 实测更新

80项四粒度归约探针：1843→957 LUT（-48.07%）、6→2 CARRY8；DSP均0。三种16路64位更新/溢出探针均完成74输入位通用等价证明，但split为368 LUT/144 CARRY8、prefix为2016 LUT/32 CARRY8，均劣于原写法160 LUT/144 CARRY8的当前LUT目标，**不采用到生产源码**。完整原/新地址RTL已6144周期、52输出逐周期一致；新完整地址模块已实际启动OOC综合，真实完整模块面积待报告。报告 `Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-round3-20261110/MEASURED_RESULTS.md`。上述为局部探针，不是整机FIT结论，当前整机8da24a26继续运行，不等待新优化。

### 2026-11-10 后续进展

- 冻结 PackageAddressStats standalone OOC synthesis 报告真实记录 1,702,895 LUT、58,190 CARRY8、391,057 FF、216 BRAM tile、0 DSP（`build-logs/Opt4-fit-modules-20261110/baseline-address/vivado/`）。这证明其是重点优化对象，但它是旧冻结 RTL 的独立模块报告，不是任何派生整机容量判断。
- 另启低优先级 CPU-only 的 `ec-parsec-opt4-fit-address-probes4.service`：证明 6-input bit-heap bounded population-count 结构后再做 LUT/CARRY8/DSP 微映射；同时比较小增量算术的 DSP inference。不会修改任一生产源码，DSP 探针不得仅以 LUT 下降采纳（全机 DSP 资源需看真实整机报告）。状态 `Experiment/Opt4-fit-address-probes4-state.json`，结果 `build-logs/Opt4-fit-address-probes4-20261110/`。
- 主派生整机 `8da24a269b98a0d6a8f57b030353a310812c4344` 仍处于 DUT synthesis；指定 Vivado worker有持续 CPU 活动，约 13.5 GiB RSS，日志尚未导出新的阶段/面积报告。地址 round3 的完整模块 OOC synthesis 并行继续。没有推算全机资源，没有 bitstream，没有 Opt4 样本。
- 当前 Native Netstreamcluster r3继续在 serial `21770433G02LA` / BDF `0000:21:00.0` 执行。严格保持 21-only；未触碰 e2、全局 XDMA、reset/rescan、驱动或活任务。
- `Opt4-fit-address-probes4.py` 若证明超时或失败，只保留证据并停止探针，不影响主综合。若整机 post-opt 实报 FIT，CAD guard 自动继续 place/route、timing/DRC和bitstream；之后仍需独立派生 profile 的正确软件、运行身份和 21 卡运行时校验，不可借用冻结 C4 的 source ID/admission。

### 2026-11-10 19:44 CST：独立探针与 13 项软件准备完成

- bit-heap 的8项归约在136输入位上通过 bounded universal SAT；80项在240秒证明超时，保留 `build-logs/Opt4-fit-address-probes4-20261110/heap80/proof80-attempt-1.log`，没有映射或采纳未证明结构。原探针进程确认退出后，从已通过的proof8收据复用，仅继续独立DSP探针；没有重启正常CAD/FPGA任务。
- 两种DSP attribute写法（wire/module）及原算术均通过74输入位RTL算术证明；同设置16路64位加10位增量及溢出映射结果完全相同：160 LUT、144 CARRY8、0 DSP。没有面积收益，均不采用。probe4最终状态 `PROBES_MAPPED_NOT_INSTALLED`，不是所有候选验证通过。
- 新脚本 `scripts/prepare_opt4_fit_runtime.py` 已实际检查13项普通PARSEC：每项3轮现存Native有效完成标记、result/identity绑定、实际ELF/镜像/固件哈希、相同线程/ROI profile/内存cap/bootargs及内嵌rootfs绑定；7项生成ABI/目标描述逐字节相同，兼容复用driver明确标注未重新编译、未上板验证。
- 派生收据只写 `runtime/Opt4-fit-8da24a26/{driver-receipt.json,software-suite.json}` 与 `Experiment/.../build-logs/Opt4-fit-runtime-8da24a26/software-preparation.json`，未改冻结runtime、suite-execution-plan、活runner或调度服务。软件清单不是测试通过，没有创建第二套FPGA队列。
- `python3 scripts/prepare_opt4_fit_runtime.py --certify` 当前实际返回 `WAITING_FOR_REAL_TIMING_DRC_BITSTREAM`。只有真实CAD完成、阶段哈希/11个shell DCP/零功能blackbox/capacity/setup/hold/bitstream门通过，才会复制到派生目录并写独立 `certified-build.json`；它不部署、不改变旧冻结C4 admission。
- 派生运行时自动接管仍未安装：原 `continue_fpga.py` / `coverage_first.py` 的冻结source ID不能用于派生bitstream。真正启动前需在21安全边界为唯一运行者接入派生profile，并保留严格smoke、真实checker、输出和排空验证；当前没有冒称自动首验就绪。

### 2026-11-10 20:19 CST：派生自动认证、21-only部署与实验链路已接通

本节替代上文“派生自动接管未安装”。`ec-parsec-opt4-fit-runtime.service` 已启用并实际运行，controller PID 3135212（重连重新核验start_ticks/boot_id），状态 `Experiment/.../Opt4-fit-runtime-state.json`，日志 `jobs/opt4-fit-runtime/console.log` 及 `Opt4-fit-runtime-logs/`。目前 `WAITING_FOR_DERIVED_BITSTREAM`，没有创建priority预约、没有操作FPGA。

- `continue_opt4_fit.py` 等待当前8da24a26真实CAD成功，自动执行 `prepare_opt4_fit_runtime.certify()`。核验源码版本、生成RTL/11个shell DCP哈希、全部阶段完成、零功能黑盒、LUT/CARRY8/DSP/FF/BRAM/URAM容量、setup/hold、bitstream哈希后，才写独立 `runtime/Opt4-fit-8da24a26/certified-build.json`。认证收据一次写入后保持稳定，冻结C4 canonical收据不修改。
- `board_batch.py` 和 `run_isolated_sample.py` 新增显式 `--opt4-fit-receipt`。只接受精确派生commit/source/profile/收据路径。实际部署仍通过原21-only目标工具，复用维护锁/单卡锁、目标设备占用及JTAG映射检查，禁止e2、双卡、全局驱动或PCIe操作。新样本前缀 `opt4-fit-8da24a26-`，记录真实派生commit/profile与冻结parent，不能被旧C4门当作冻结结果。
- 认证后发布 `Opt4-fit-runtime-priority.json`，只阻止未来的旧配置启动；已运行样本完全不受影响。派生服务先等待活sample退出，部署仍需取得同一维护排他锁。原coverage-first服务不重启；它继续Native任务直到派生认证就绪。新服务不是第二个并发FPGA所有者。
- 全部正式样本之前必须经过smoke及每个profile存在的test/simsmall；复用原严格output/checker/context/task序号/full_compare/drain验证。失败profile/阶段保留证据并跳过；先13项正式r1、再r2/r3；已原子提交且版本匹配样本自动跳过。复用同一bitstream，首次重启探测失败最多保留证据后对同输入fresh deployment重试一次，不重新构建bitstream。
- 新 `validate_opt4_fit_runtime.py` 实际完成27项**不访问硬件**的正反例测试，含真实认证函数的哈希/时序拒绝、目标部署选择、e2/双卡拒绝、SH/EX锁冲突、严格checker拒绝及控制器端到端fixture（活任务等待、单次部署、一个程序失败继续其余、先r1再重复、已完成跳过）。报告 `build-logs/Opt4-fit-auto-runtime-20261110T120100Z/offline-validation.json`。测试fixture从未进入正式runs；这不是上板通过。
- 统计器 `summarize_results.py` 为派生硬件增加profile+commit分组，防止与冻结C4混合重复轮数或面积/性能结论。共同有效Native软件版本仍可配对；周期比明确标派生profile。publisher保存派生runtime状态。
- 地址第一版OOC已完成综合优化、正在网表转换/报告生成；当前8da24a26整机仍在DUT synthesis，尚无全机资源/FIT结论，不等待新候选。独立bit-heap使用对实际生成RTL逐节点解析的加权整数守恒证明：3..6输入压缩器穷举全域、连线/位权守恒、round3已证明leaf边界保证末端无截断；原80项SAT超时不改写。服务 `ec-parsec-opt4-fit-address-heap-proof` 仅做微映射，不改任一生产RTL。

### 2026-11-10 20:35 CST：完整地址模块实测与独立候选修复

- 第一版完整地址模块的匹配OOC综合/检查点现已完成。Vivado权威 `CLB LUTs` 为 **1,500,571**（不是1,502,571），CARRY8 **57,446**，FF **390,171**，BRAM tile **216**，DSP **0**；对应 `build-logs/Opt4-fit-modules-20261110/fit-address/vivado/{utilization.rpt,module.dcp}`。冻结同设置为1,702,895 LUT / 58,190 CARRY8；减少 **202,324 LUT（11.881%）**。独立模块仍比U280全部1,303,680 LUT多196,891；这不是当前整机post-opt容量或FIT结论。当前整机8da24a26保持运行，不更改其输入。
- 独立80项压缩归约探针实测 **840 LUT、0 CARRY8、0 DSP**，比round3平衡树957 LUT少12.226%，比原探针1843 LUT少54.422%。证明为对实际微RTL解析的局部穷举压缩器/位权守恒及已证明leaf上界；原80项整体SAT超时证据仍保留。这不是完整地址模块收益，也不是全DUT等价。
- 实际Chisel候选06b8731在elaboration中因 `Bool.cloneTypeWidth` 对多位pad的require失败。完整栈见 `build-logs/Opt4-fit-address-heap-candidate-20261110/diagnostic/full-stack.log`。故障进程已自然退出并核对PID/start_ticks/boot_id，未结束活任务。独立候选修复为显式Cat零扩展，commit **c41d42f61aa79d8249125c9e911438b797d007ce** / source ID **6fcb790b0d19e832582166c1940f485a00940f95437b38d297d9533f446721d2**。旧commit、失败日志/收据/patch保留，独立新输出 `build-logs/Opt4-fit-address-heap-candidate-c41d42f-20261110/`。
- 服务 `ec-parsec-opt4-fit-address-heap-candidate.service` 已重新启动这项已退出的失败候选，仅执行独立compile/elaboration、冻结完整地址模块6144周期/52输出逐周期对照，通过后才综合完整地址模块。不修改当前整机、round3活综合或FPGA。状态 `Opt4-fit-address-heap-candidate-state.json`，候选未经最终验证/整机资源门，不进入当前生产版。
- 派生自动链路服务 `ec-parsec-opt4-fit-runtime.service` 正常等待真实8da24a26 bitstream，不占用维护锁或21卡；13项已绑定软件不重建、不修改。真实capacity/timing/DRC认证之后才发布优先权、等待Native安全边界、21-only部署及严格首验，正式先r1覆盖再补轮次。

### 2026-11-10 20:53 CST：独立候选完整回归通过；Native 45/48

- 独立候选 **c41d42f61aa79d8249125c9e911438b797d007ce** 已完成elaboration及冻结完整地址RTL **6144周期、52输出逐周期一致**，真实log包含 `ADDRESS_SEQUENTIAL_COMPARISON_PASS vectors=6144 valid_edges=5550 idle_edges=12`；证据 `build-logs/Opt4-fit-address-heap-candidate-c41d42f-20261110/compare/compare-attempt-1.log`。这是完整模块的回归通过，不是全DUT形式等价。已自动进入 **完整地址模块 OOC 综合**，当前整机8da24a26及round3的输入均保持不变；不提前推算新模块面积。
- 完成版第一fit地址DCP的只读分块EDIF分析通过独立Vivado报告交叉核对。解析33,307个压缩块、2,131,629,281字节解压文本；递归层次消除重复计数后得到1,739,756 LUT原语、57,446 CARRY8、390,171 FF、0 DSP。CARRY8/FF/DSP/BRAM与报告完全一致；LUT原语可打包，不能替代权威物理1,500,571 LUT。
- 网表名称相关的互斥组：`bucketStrictWriteRead` **939,525 LUT原语 / 18,016 CARRY8**；`bucketStoreFirst` **161,641 / 16,896**；`bucketLoadFirst` **158,077 / 16,896**。这是名称归因，非完整源级cone证明；表明80项严格命中桶归约及其64位更新/溢出相关逻辑是下一重点，不能只继续优化已经很小的scanner。结果 `build-logs/Opt4-fit-address-attribution-20261110/{ATTRIBUTION.md,result.json,receipt.json}`。早期解析失败及首块零计数伪结果已明确归档为invalid，不被面积汇总使用。
- 当前整机真实日志已从此前模块扫描推进到 **Finished RTL Elaboration**（Vivado报告CPU1:50:16、elapsed1:53:24），仍在DUT综合，尚无全DUT资源报告、FIT结论或bitstream。8da24a26保持运行，无重启。认证/21-only首验服务继续等待。
- Native Netstreamcluster simmedium r3 **原子有效提交通过**：ROI **101,948,687,434周期**，Host **6203.917838224秒**，输出校验通过、driver returncode 0、issues为空，result/complete身份与结果哈希已核对。真实结果 `runs/native-netstreamcluster-simmedium-r3-20261110T110450Z/result.json`。Native正式 **45/48，15/16程序三轮齐备**，剩Netferret3轮因simsmall失败被跳过；未重复已有样本。21卡目前任务安全结束，无Opt4 bitstream可部署；Opt4 **0/48**、有效配对 **0/16**。


### 2026-11-10：用户暂停 Native，集中 Opt4 硬件实现

本节覆盖此前 Native 自动续跑描述。Native/coverage-first 已在最后样本 COMPLETE、
实际 PID 退出、协调器无 sample 子任务的安全边界 stop/disable；没有 FPGA、驱动或
PCIe 操作。暂停证据：`Experiment/firesim-final-opt4-20261106/Native-user-paused.json`，
以及该文件指向的 `interruptions/native-user-pause-*/` 原状态和服务前后快照。
网络软件修复未启动新作业；已完成的软件成果和原始样本不变。

未经用户要求恢复 Native，不要启动/enable `ec-parsec-native.service` 或
`ec-parsec-coverage-first.service`，包括重连/服务 reload 后。旧状态中的等待 PID
是历史记录，必须以进程身份与 systemd 实态判断。保留 Opt4-fit CAD、模块验证和
`ec-parsec-opt4-fit-runtime.service`；后者独立等待派生 bitstream 认证，部署严格21-only。

独立共享散射归约候选：`Opt4-fit-address-sort-20261110`，commit
`11edd71981aa30ff3a26aab1f2f7327ac0266ee1`，source ID
`f8a4239fe5a4818e15d98791f76d9d877172f342cdc0bc036ac6811e68de3cec`。
服务 `ec-parsec-opt4-fit-address-sort.service`；状态
`Experiment/firesim-final-opt4-20261106/Opt4-fit-address-sort-state.json`；
日志 `jobs/opt4-fit-address-sort/console.log` 与
`build-logs/Opt4-fit-address-sort-11edd719-20261110/`。
先 audit 精确 PID/start_ticks/boot_id，活实例只监控。确认退出后才从哈希绑定的
成功阶段收据继续；证明失败/超时不能算通过。验证/映射服务不自动晋升候选。

该候选共享组合排序和分段前缀和，替换每桶重复 N 路归约；保留全部256桶、
64位状态/65位溢出检查、队列/表容量、原事件与周期逻辑。只读比较确认桶增量
块以外源码不变。当前 8da24a26 整机、aca893e0 与 c41d42f 完整模块综合输入不变。
实际面积必须使用该候选完整模块报告；局部形式证明与回归不等于整机形式等价。


### 下一整机候选的容量门与衔接（11edd719）

`ec-parsec-opt4-fit-sort-system.service` 已启用，持久状态
`Experiment/firesim-final-opt4-20261106/Opt4-fit-sort-system-continuation-state.json`，
日志 `jobs/opt4-fit-sort-system/console.log` 与
`build-logs/Opt4-fit-sort-system-continuation-11edd719/`。
它只在新地址模块的局部证明、8192向量×1024输出实规模对照、冻结完整模块
6144周期×52输出对照全部通过，并取得至少25%真实LUT下降后，才编译新版本全部
六个源码、参数审计、私有类来源审计和GoldenGate。独立适配脚本与哈希在
`Opt4-fit-address-sort-20261110/pipeline/templates.json`，没有修改当前整机脚本。

下一整机 Vivado 仅在当前8da24a26实际post-opt状态为 NOT_FIT_POSTOPT 后启动；
当前版若已产生合格bitstream则优先当前版，不启动新CAD。工具失败不冒充NOT FIT。
下一版仍有独立容量门，超量停止于布局前；FIT才继续布局布线、时序、DRC和bitstream。
其profile为`Opt4-fit-C4-SVB32-sort-20261110`，不能用旧8da或冻结849的运行收据。
本衔接没有硬件部署权限入口；新版本产物仍须建立自己的完整软件/认证绑定再首验，
不可伪造旧profile。当前8da自动认证/21-only首验服务保持独立有效。

7项控制门离线正反测试通过，证据
`build-logs/Opt4-fit-sort-system-continuation-11edd719/offline-control-validation.json`；
它们是fixture，未访问FPGA。重连先audit本service和四个独立状态的PID/start_ticks/boot_id。
活进程只接管监控，成功阶段收据按精确source/输出哈希复用，失败证据原样保存。


### 共享归约候选的实际验证完成（2026-11-10 22:34 CST）

`11edd719` 已实际通过生成 RTL 比较交换绑定 SAT、128 路零一排序 SAT、3/4路
完整散射等价 SAT（在已证明的叶子边界下）；负变异被检出。实际80路、256桶、
四粒度组合对照8192组、每组1024输出全部一致。原冻结完整地址模块与候选在
6144周期、52输出逐周期一致。验证收据
`build-logs/Opt4-fit-address-sort-11edd719-20261110/verified-regressions.json`。
这些不是整机形式证明或FPGA验证，面积仍以实际模块综合结果为准。

验证程序曾有Verilator C++宽向量迭代接口编译失败，已修复，旧证据在harness-failure-v1；
随后单个约30MB生成函数的-O1编译超过17分钟，已只结束本轮新候选验证编译进程组，
保留日志/PCH/对象并从已成功证明收据以-O0续跑。其真实规模对照和完整模块对照随后
实际通过。没有向任何现有Vivado或FPGA进程发信号。
25个本来inactive的Native/网络软件服务也已disable自动启动；完整清单在Native-user-paused.json。


### 共享归约核真实映射与完整模块启动（2026-11-10 22:50 CST）

实规模80路、256桶、四粒度共享归约核已完成Vivado OOC映射：
**388,563 LUT、1,160 CARRY8、0 DSP、0 FF**。
报告 `build-logs/Opt4-fit-address-sort-11edd719-20261110/micro80/map/utilization.rpt`，
对应RTL、DCP与report哈希均在成功阶段收据。这个归约核比此前只求一个桶的探针
范围更大，不能互作面积基准，也不能与完整模块1,500,571 LUT直接相减。
完整候选PackageAddressStats已自动开始OOC综合，状态为RUNNING_MAP-FULL-ADDRESS；
完整模块资源报告尚未生成，不能提前宣称25%面积门通过或整机FIT。

当前8da24a26整机仍RUNNING_DUT_SYNTH，尚无资源/FIT/bitstream；所有旧Vivado
worker和输入保持不变。下一整机服务已在确认自身失败等待进程退出后恢复，
继续等待新模块实际资源门，无重复整机综合、无FPGA访问。

当前派生硬件 RTL `GOLDENGATE_COMPLETE_NOT_SYNTHESIZED`；整机 CAD **RUNNING_DUT_SYNTH** / `dut_synth`。实际资源、失败、bitstream 状态以 [Opt4-fit-cad-state.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-cad-state.json) 与 [FIT_STATUS.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-modules-20261110/FIT_STATUS.md) 为准。

## Opt4 首验与优先衔接（2026-11-10）

13 项普通 PARSEC 的 Opt4 软件离线哈希审计为 13/13 就绪，收据 [opt4-readiness-latest.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/opt4-readiness-latest.json) 绑定真实 ELF、输入/参考、rootfs、内核、固件、driver 以及 Native 三轮版本；这不是 C4 FPGA 通过。Fluidanimate 保持已授权的 stable-formal 修复 profile。
最终 bitstream 仍须通过原 CAD 输入/源码/时序与产物哈希认证。认证后在21卡安全边界部署，首验仅执行 smoke → Blackscholes test/reset 探测 → simsmall；全部正式样本由现有 coverage-first 唯一调度。优先级为所有可运行 C4 在先，配置内先覆盖所有 r1，再补 r2/r3；失败按版本保留并跳过，Native 网络任务只能在 C4 尚无可运行任务时执行。不得触碰 e2 或执行全局驱动/PCIe 操作。
原冻结 CAD 已按用户授权在 NOT FIT 证据和精确进程身份核对后退出，wall-limit guard 同时禁用；检查点和日志保留。恢复守卫阻止重连重启该无效导出。当前实际构建为上述独立 Opt4-fit；原完整顶层 opt_design 诊断单独保留。

## 覆盖优先调度与逐轮状态

2026-11-07 新增 `ec-parsec-coverage-first.service`，已启用系统启动恢复。逐项 test、simsmall、r1/r2/r3 及已核实进程身份见 [COVERAGE_STATUS_LIVE.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/COVERAGE_STATUS_LIVE.md) 和 [coverage-status-live.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/coverage-status-live.json)；每300秒随发布器更新。
旧队列保留当前 Freqmine 批次、定向修复服务及 C4 首次部署验证器，未来任务在安全边界交给该唯一服务；它按正式首轮覆盖、第二轮、第三轮推进，只复用精确版本的原子完成样本。失败阶段记录后继续其他程序，缺失软件仍列在32个配置/程序槽中，软件绑定补齐后自动进入队列。
状态 [coverage-first-state.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/coverage-first-state.json)；日志 `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/coverage-first-logs/`、`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/jobs/coverage-first/console.log`。旧 C4 全套等待门标为 `DELEGATED_TO_COVERAGE_FIRST_SERVICE`，避免其部署恢复与新所有者竞争；未停止原有FPGA/CAD任务。详细交接证据见执行计划的 `handoff_receipt`。
Native Blackscholes 既有3轮保留各自原始 observed/restart 驱动哈希；已审阅 host-only patch，仅 journal序号原点/宿主效率记录变化，ROI tick与RTL不变，允许复用目标周期；宿主效率数据按原驱动区分。

## 作业托管与断线恢复

恢复规则、只读核验命令、系统级 unit、状态和日志入口见 [RUN_RECOVERY.md](/data1/gzh/EC/firesim/final-opt4-20261106/RUN_RECOVERY.md)。新长任务由 `ec-parsec-*.service` 托管，启动先核对 PID/启动 tick/boot_id；存活进程只监控，不停止、迁移、重复启动或修改输入。确认退出后按完成 DCP 或精确版本样本原子标记恢复。`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/jobs/<name>/state.json`、`console.log`、`startup-audit.json` 为持久入口。统计快照不是指令级检查点。

## 版本与可复用产物

- 冻结 commit `8491167d84b6d9521b151a743673c1516926a1f8`，Tag `opt4-final-performance-fpga-20261106`，v1Config、4 checkers、SVB32、L2 report-permission repair；未修改。
- 冻结备份 `/data1/gzh/EC-backups/opt4-final-performance-20261106/source/chipyard`。实际 C4 输入 `/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard` 是独立源快照，不以父目录 Git HEAD 冒充版本。source_id `c9f51d3a94aac7783c750682162cd25e9d1460b04974bde9b7541f1d9f4120e7`。
- [integration.json](/data1/gzh/EC/firesim/final-opt4-20261106/integration.json) 和 `/data1/gzh/EC/firesim/final-opt4-20261106/frozen-to-firesim.patch` 绑定集成差异；[hardware-revalidation-20261106.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/hardware-revalidation-20261106.json)、[generated-svb-audit.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/generated-svb-audit.json) 及 GoldenGate receipt 绑定源码到生成产物。实际使用 FireSim 1.17.0 `07efa6a6da18bd64d1159ae84a4701b37abb1228` / Chipyard 1.9 / Vivado 2021.1，未升级工具链。
- Native 真实 0 checker、单 BOOM，无保护；[native-reuse.json](/data1/gzh/EC/firesim/final-opt4-20261106/native-reuse.json) 绑定既有可复用 bitstream，SHA256 `bbe70b655538fa8d17deb72c4307ac66167ee0510aa12d0270ce2c9e37a34aea`。最终 C4 bitstream 尚由当前 CAD receipt 决定，不能用旧 Opt4 代替。
- 不因程序、输入、重复编号或只改软件而重做 bitstream。复用同一硬件时只重启 guest；C4 同部署第二个样本必须通过目标 reset 探测，之后每个样本仍独立核对启动、输出、ROI、真实校验匹配及排空。无效/中断样本保留并补跑；reset/驱动兼容性失败时复用原 bitstream 重新部署。

## 当前构建、空间与中断

- 主机于 2026-11-06 22:07 本地时间重启；旧 `/tmp` CAD/内核/payload 消失，旧两项 C4 CAD 与 Native r4 中断，未计有效。原状态和唯一失败证据保留。
- 2026-11-07 11:35:19 本地时间再次发生主机重启，boot ID 变化；本任务没有执行重启。中断状态及恢复收据：[host-reboot-09ba1a37-9f6d-4a9e-ad1b-9c057e9ad64c](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/interruptions/host-reboot-09ba1a37-9f6d-4a9e-ad1b-9c057e9ad64c/receipt.json)；[host-reboot-d6c6e410-10ad-4326-86ba-79b657eabd96](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/interruptions/host-reboot-d6c6e410-10ad-4326-86ba-79b657eabd96/receipt.json)；[host-reboot-e5c9abda-56be-46db-9a2a-03b472f81a5a](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/interruptions/host-reboot-e5c9abda-56be-46db-9a2a-03b472f81a5a/receipt.json)。本轮 `/var/tmp` CAD/内核/payload 全部保留；当前 CAD 复用已完成 IP 检查点 11 个，仅补建未完成阶段。Native/Opt4 的有效完成样本继续复用，未完成样本明确保留为 INTERRUPTED。
- 原最终 C4 CAD已退役（NOT FIT），历史 PID `5893`，[C4-runtime-cad-state.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/C4-runtime-cad-state.json)，日志 `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-resume-20261109T013827Z`，输出 `/var/tmp/guozh-firesim-final-opt4-20261107-cad/C4-runtime-bitstream-20261107T022025.952528Z`。原DUT综合已完成，仍须结合实际阶段日志判断仿真网表导出，不以CPU增长代替产物进展。
- 用户授权的独立DCP复用验证：状态 `FAILED_WITH_EVIDENCE`，[C4-dcp-cad-state.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/C4-dcp-cad-state.json)，目录 `/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z`，日志 `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-dcp-20261110T071734Z`。只复用当前DUT及11个已完成IP的检查点、原顶层/实现配置；冻结RTL及原Vivado进程不变。DCP可读、顶层综合、拼接、布局布线、时序、bitstream认证与上板验证分别记状态，未认证候选不得部署。恢复说明见 [RUN_RECOVERY.md](/data1/gzh/EC/firesim/final-opt4-20261106/RUN_RECOVERY.md)。
- DCP 快速路径已绕过 funcsim 导出；2026-11-10 顶层综合通过，后续使用原生成实现步骤，拼接后要求零功能 black box（仅允许原流程待实现的 dbg_hub_CV），原 implement_debug_core 后再要求全部零 black box；线程上限8。顶层 opt_design 后直接保存完整 utilization/DRC 和 checkpoint，确认超量即阻止进入 place/route。checkpoint 独立保存在 `reused-checkpoints/`，恢复 `.gen` 路径，避免 scripts-only 刷新删除未完成 IP 输出。认证衔接服务 `ec-parsec-c4-dcp-admission.service` 的状态见 [C4-dcp-admission-state.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/C4-dcp-admission-state.json)；仅在真实 route、setup/hold、DRC 和 bitstream 全部通过、冻结输入/DCP哈希复核后发布现有21-only首验入口。原CAD收据归档到 `build-logs/c4-admission-alternatives/`，首个认证版本固定在 [C4-selected-certified-build.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/C4-selected-certified-build.json)，不存在时表示尚未选出。原DUT综合报告约594万 LUT / U280 455.55%、CARRY8 260.62%，**须由顶层 opt_design 后结果确认容量；目前不能声称可布局或已有有效bitstream**。
- C4 容量专项实测见 [CAPACITY_REPORT.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-capacity-20261110/CAPACITY_REPORT.md)：455.55% 是已映射 DUT 的真实物理 LUT 报告，重新打开 DCP 的报告一致，独立 EDIF 递归原语清点排除层次重复计数；当前映射 NOT FIT。独立 DUT `opt_design` 和完整顶层优化后报告分别检查，不把优化前超量或候选 leaf 通过等同完整顶层结论。主要消耗为 PackageAddressStats、三处 GHBarrierLatencyStats 及散布到其他层次的统计运算。独立精确乘法提取候选 [candidate.json](/data1/gzh/EC/firesim/final-opt4-20261106/candidates/capacity-exact-factor-20261110/candidate.json) 已有宽度/算术检查、2048周期 leaf 对照和真实 Vivado leaf 映射；未应用到冻结/活源码或正式队列，不代表全 DUT 能容纳，正式采用须经批准及完整验证。容量检查与统计报告不访问 FPGA、不控制现有 CAD。
- 2026-11-10 用户授权转入可实现性优化；独立 Git 分支 `/data1/gzh/EC/firesim/final-opt4-20261106/Opt4-fit-20261110` / `opt4-fit/20261110`，版本绑定 [candidate-binding.json](/data1/gzh/EC/firesim/final-opt4-20261106/Opt4-fit-20261110/candidate-binding.json)。冻结 DUT 独立 opt_design 后仍为 5,741,353 LUT（440.40%）、366,817 CARRY8（225.10%）、9024 DSP；完整顶层结果另计。已实现精确乘法提取、地址统计共享加法/进位溢出/有界平衡求和、固定物理槽安全前缀扫描；模块编译、原/新同设置综合和等价/回归服务实际运行，数据见 [FIT_STATUS.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-modules-20261110/FIT_STATUS.md)。已进入独立派生 DUT 综合；整机资源、时序收敛、认证及正式采用仍未完成，不把模块面积相加推断 FIT。每个模块保持源码/RTL/提交绑定；未来正式配对明确使用新 Opt4-fit 身份，并核对 Native 软件/输入/线程/ROI 和共同硬件参数。
- 已获用户例外授权处理失败 CAD，完整证据见 [receipt.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/interruptions/authorized-failed-cad-20261107T064048Z/receipt.json)。仅停止该失败服务，Native 身份不变。恢复脚本现在以原项目用户执行，先生成综合脚本再同步执行，保留11个完成IP检查点；根本启动异常原因仍未证实。当前进度见 [cad-runtime-progress-latest.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cad-runtime-progress-latest.json)，不以外层进程存活代替实际综合 worker。
- CAD 工作区现为持久根分区 `/var/tmp/guozh-firesim-final-opt4-20261107-cad`，启动空闲 361.5 GiB，最近快照 300.3 GiB；80 GiB 启动、60 GiB 停止余量、120 GiB 增长预算。与 `/data1` 是不同文件系统，未降低阈值。
- 已授权旧废弃 `.Xil/**/*.rtd` 清理证据：[cleanup.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/batches/Native-20261106T113308Z/cleanup.json)。此次额外空间来自另一文件系统；没有为腾空间删除有效源码/bitstream/软件/结果。
- formal rootfs、PARSEC 应用、输入与 DTB 持久产物复用；C4 缺失 Linux/OpenSBI 已在 `/var/tmp` 重建，[formal-earlyconsole-kernel-build.json](/data1/gzh/EC/firesim/final-opt4-20261106/software/C4/formal-earlyconsole-kernel-build.json)、[formal-firmware-build.json](/data1/gzh/EC/firesim/final-opt4-20261106/software/C4/formal-firmware-build.json)。恢复后 C4 `.config` SHA256 `cd367595b60ffe7e2c33d1e3a0049a2461a102f71f6681b7e818598693e1377d` 与旧 formal kernel 一致；编译完成仍不是 FPGA 通过。

## 板卡、安全维护与批次

- 单卡恢复入口：21 维护锁 `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/locks/maintenance-0000_21_00.0.lock`；状态 [active-0000_21_00.0.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/active-0000_21_00.0.json)；服务日志 `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/jobs/coverage-first/console.log`。重连先核对 PID、start_ticks、boot_id 与 cgroup，活进程接管监控，确认退出才按原子 complete 补跑。安全切换完成证据：[final-state.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/safety/21-only-20261109/final-state.json)。
- 安全修复与离线检查：[21-only safety report](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/safety/21-only-20261109/REPORT.md)。通用 FireSim Manager 的实体卡 infrasetup/enumeration 已禁用；部署入口为 `/data1/gzh/EC/firesim/final-opt4-20261106/scripts/infrasetup.py Native|C4`，只复用认证 bitstream。
- 当前部署目标固定为 Xilinx U280 `0000:21:00.0` / `21770433G02LA`；`0000:e2:00.0` / `21770433G001A` 保留为不触碰设备。系统映射与两端点型号记录在 [fpga-target-map-20261109.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/fpga-target-map-20261109.json)。旧 `restore_second_pcie.py` 已禁用。
- 每次部署前检查目标 BDF/序列号、所有可见进程和 XDMA FD/MMIO；权限拒绝单独记录；具体目标设备冲突才阻止部署。FireSim `fpga-util.py` 只接受精确 `0000:21:00.0`（序列号仅由核验映射取得，拒绝 serial-only 编程），拒绝 `--all-bdfs` / `--all-serials`。部署按目标设备 unbind/remove/JTAG/上游桥 rescan/rebind，不卸载全局 XDMA 模块，也不写 `/sys/bus/pci/rescan`。21 的运行实例持有单卡共享维护锁；21 部署需单卡独占锁。既有 e2 活样本保持不动，不加载或卸载主机级模块。
- 本任务自有 `hw_server:3122` 的 PID、boot ID、日志位于 [owned-hw-server-3122.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/owned-hw-server-3122.json)。未停止其他服务或任务，未运行有副作用的 enumeratefpgas。
- 最新部署 [latest-deployment.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/latest-deployment.json)，当前 boot ID 匹配：`True`。实际编程证明在该 batch 的 `program-Xilinx_*.log`，部署状态不代替运行验证。
- 续跑进程 [fpga-continuation-state.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/fpga-continuation-state.json)：最终 bitstream 成功及软件绑定通过后，仅在 `0000:21:00.0` 部署，执行 C4 smoke → Blackscholes test/reset 探测 → simsmall，再将所有正式首轮与重复交给 coverage-first。功能门槛不通过时不进入正式测量；重复结果持续保存。
- 后续全套队列 [suite-execution-plan.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/suite-execution-plan.json)；Native 扩展 [suite-native-queue-state.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/suite-native-queue-state.json) 在综合期间仅使用21；C4扩展 [suite-c4-queue-state.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/suite-c4-queue-state.json) 等首个控制器结束后依次运行就绪程序。原 Canneal/Streamcluster 等待控制器已在确认无子任务后并入全套队列，历史状态保留，未中断样本。各程序先小输入门槛再正式3轮，故障逐项保留；C4仅在具体失败guest后由统一维护流程重载同一认证bitstream以恢复，其余软件/输入变化不触发bitstream重建。

## 软件、公平性与观测

- `/data1/gzh/EC/firesim/final-opt4-20261106/software/formal-apps-build.json`、`formal-rootfs-build.json` 为首组 Native/C4 共用软件，rootfs SHA256 `427d0b923bc2be77b67ba0ff11efd47bb83c7bbf28fd990e10c658dcf7178711`；Blackscholes Linux 静态 ELF SHA256 `75b4e2923b0a7b1d096023daa6610f5c622bf04771b4e2966bbdee006e5270ea`。所有输入/argv/参考输出由 manifest 绑定；未把裸机 ELF 当 Linux 程序。
- Blackscholes 官方 simmedium：16384 options、NUM_RUNS=100、串行单线程、无预热；与已完成 Native r1/r2/r3 一致。已有 QEMU 参考与 FPGA Native 输出校验，C4 必须另行通过真实 checker 证明。
- 两组 BOOM/uncore 200 MHz、C4 checker 100 MHz；host FPGA 50 MHz 单列。FASED 为 LatencyBandwidthPipe，读/写延迟30、max requests4、relaxFunctionalModel0，每个样本要求全部寄存器读回相等。
- 实际硬件 RAM `[0x80000000,0x480000000)` 共16 GiB，Linux 两组统一物理位宽36、SECTION27、`mem=2G`、相同 bootargs；与无cap/诊断配置结果分开。[matched-guest-mem2g.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/matched-guest-mem2g.json) 记录布局。不得用宿主墙钟计算体系结构 slowdown。
- C4 固件每次 guest 一个 ROI，hart0 Linux、hart1..4 真实 checker 服务。要求 generated=completed=passed>0，fault/failed/cancelled/dropped/outstanding=0、每个任务序号匹配、full_compare=1、真实 drain 及 firmware park mask15；缺项不提交有效标记。
- 严格 latency 尚缺同一任务 BOOM 执行完成与 Rocket 真比较完成的统一时基事件，保留 null，不把 PACKAGE_BEGIN、入队或采样时刻充数。已有128项 traffic 寄存器在排空后读回；利用率/队列指标仅报告已验证接口。

## Streamcluster 与后续

- 原 Streamcluster ROI 包含进度 stderr write、结果 open/fstat/write/close；这是实际功能缺口。串行候选未发现线程同步或计时 syscall。DacRoiController 在 ROI 内 trap/非U态/satp变化置 fault8，不能跳过。
- 当前正式队列已选 `streamcluster-staged-formal`，绑定官方 simmedium/full original ROI，Native 正式三轮已原子提交；C4 真实比较、输出和排空仍待验证。旧 `streamcluster-staged` 仅保留为功能阶段历史证据，不用于正式汇总。
- 历史软件候选 [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/streamcluster-staged-diagnostic-20261106T115645Z/result.json) 保留原 ROI hook位置、输入生成、聚类和结果格式化，把外部文件/日志 I/O 延后，并预置内存。当前正式 profile 的真实ROI接入为 [streamcluster-staged-formal-apps-build.json](/data1/gzh/EC/firesim/final-opt4-20261106/software/streamcluster-staged-formal-apps-build.json) 和 [streamcluster-staged-formal-rootfs-build.json](/data1/gzh/EC/firesim/final-opt4-20261106/software/streamcluster-staged-formal-rootfs-build.json)；两组同用官方 simmedium、原完整计算及格式化 ROI，不能与旧功能 profile 或原版输入结果混合。Native 已正式通过，C4 真实校验仍待 FPGA 验证。文件输入及异步中断仍未证明。
- x264 新 profile `x264-no-progress` 复用原 encoder、原 staged ELF 和全部编码/延迟帧排空 ROI，在两组及参考一致启用原 CLI 的 `--no-progress`；test/simsmall/simmedium 输出逐字节一致且软件诊断 ROI syscall 为0，仍需 FPGA 验证。Facesim 使用 `facesim-staged-resident` 预载原控制文件，保持读解析/插值/完整求解在原 ROI；Raytrace `raytrace-headless` 仅移除不可达GL显示，保留官方多帧渲染，记录原本未渲染的边缘像素与 test 1x1 无计算限制。它们的实际 profile、输出校验与未解决问题以全套矩阵为准。
- Fluidanimate Native simsmall 两次输出校验失败，保留为无效样本；新诊断镜像复用同一 ELF/输入/ROI，失败前回收完整 out.fluid，禁止正式使用或放宽校验。独立服务 `ec-parsec-idle-repairs` 等现有 Native 全套队列空闲后定向补跑 Dedup 与该诊断；`ec-parsec-fluidanimate-output-analysis` 严格核对 UART 文件信封、字节数与版本，再量化字段差异。入口为 [idle-repairs-state.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/idle-repairs-state.json) 与 [fluidanimate-fpga-output-analysis.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/fluidanimate-fpga-output-analysis.json)，不抢占活样本，不自动重新部署 Native。
- Fluidanimate Linux reference 已从完整 UART 证据恢复，无须重跑 QEMU，收据 [fluidanimate-linux-reference-recovery.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/fluidanimate-linux-reference-recovery.json)。随后两个独立 systemd 软件诊断定位了原程序跨分配指针比较的漏算：第一帧 QEMU user/Linux 分别漏掉3,662/6,798个半径内跨cell对；仅加计数的二进制逐字节复现各自原输出。[fluidanimate-pair-selection-diagnostic.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/fluidanimate-pair-selection-diagnostic.json) 与 [fluidanimate-stable-order-candidate.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/fluidanimate-stable-order-candidate.json) 保存全部计数、来源、补丁和日志。两处稳定编号谓词的候选在两环境输出逐字节一致、跨cell漏算0，但它改变原版错误数值轨迹。用户已于2026-11-07明确授权稳定编号配对修复；正式profile为fluidanimate-stable-formal，两组同ELF/输入/原ROI。Native由定向服务ec-parsec-fluidanimate-stable-native在原队列和idle-repairs结束后补跑，C4由现有全套队列执行；旧失败和原profile保留。实际FPGA通过与正式轮数以全套矩阵为准。 采用收据见 [fluidanimate-stable-formal-adoption.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/fluidanimate-stable-formal-adoption.json)。不能由QEMU结果推断FPGA通过。
- Dedup 首次在应用启动前因 initramfs `broken padding` 失败：OpenSBI 默认 DTB 拷贝地址 `0x82200000` 落入从 `0x80200000` 开始的 57,467,904 字节内核 Image。完整归档本身与内嵌压缩数据逐字节一致，GDB/QEMU 保存了错误和地址证据。软件修复将 Native/C4 固件的 `FW_PAYLOAD_FDT_ADDR` 与 `FW_JUMP_FDT_ADDR` 一致设为 `0xbfe00000`，构建前检查其位于统一 mem=2G 内且不与内核重叠；应用、ROI、输入、rootfs、内核和 bitstream 不改。Dedup/Facesim/Ferret/Raytrace 的 `*-safe-fdt` profile 均已 QEMU 启动并校验全部文件 SHA256 通过，**尚不等于 FPGA 通过**。证据见 [large-payloads-preparation.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/large-payloads-preparation.json)。未来任务计划已绑定新固件，旧失败样本不改写，当前 Freqmine 输入不变。
- 三个网络程序未移出范围。[network-original-roi-audit.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/network-original-roi-audit.json) 记录完整原 ROI 和实际依赖：默认 user TCP/shared-memory 路径不能仅因 CONFIG_NET=n 判不可行，但其 RISC-V 移植、线程/阻塞/上下文支持尚未完成；当前 C4 ROI trap/context 合约不支持直接照搬。Netdedup 正式 runconf 含服务器 getopt 不接受的 -p/-i，且 wrapper 输入不同；Netstreamcluster 的 simmedium 实际选择 simlarge。没有用单机版替代或移出网络计算来计通过，未擅自修改冻结 DUT。
- 共用 uptcpip 已在隔离副本实际尝试 RISC-V 构建：原 Makefile 在缺少 `include/riscv64` 时退出2；独立编译 `uptcp_statis.c` 又因 x86 `%rax/%rbx/%rcx/%rdx` 汇编寄存器失败。[network-riscv-build-probe.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/network-riscv-build-probe.json) 绑定命令、日志哈希和返回码；这不是已完成的网络程序移植，也没有产生ELF。
- 上述网络构建失败是历史证据；后续独立移植及三输入Linux结果见 [NETWORK_PREPARATION.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/NETWORK_PREPARATION.md)。2026-11-09 Native网络双进程guest/真实hooks/完整输出接入已完成，原coverage-first已实际启动网络程序；当前版本与恢复入口见 [NETWORK_NATIVE_RUNNING.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/NETWORK_NATIVE_RUNNING.md)，实时通过状态以完整result/complete哈希为准，不能把离线成功计入FPGA。完整原ROI离线探针见 [network-complete-roi-probe.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/network-complete-roi-probe.json)。Native允许原线程/syscall；C4驱动、固件和monitor仍没有支持完整线程/trap ROI的pause/resume路径，不能通过分段省略、删除guard或mask fault通过，也不把Native通过当C4通过。
- 2026-11-09实际恢复 [ferret-vips-recovery-20261109.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/ferret-vips-recovery-20261109.md)：Vips固件DTB地址重叠已按safe-FDT修复；Ferret独立stable-order profile只在预载阶段固定目录顺序，逐查询结果、计算object和完整ROI保留。两组同ELF/输入/ROI，原队列已接入新profile；Native test/simsmall均有有效FPGA结果，正式轮次见实时矩阵。状态 [vips-safe-fdt-recovery.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/vips-safe-fdt-recovery.json)、[ferret-order-recovery.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/ferret-order-recovery.json)；旧失败保留，未改冻结硬件、bitstream或正常调度服务。
- Canneal、Blackscholes 原 ROI 的软件诊断无同步 syscall；实际 checker/排空仍由板级验证决定。真实 Check 实现审计 [real-check-source-audit.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/real-check-source-audit.json)，尚未 FireSim 构建，不阻塞 Native/C4。2/8 checker、面积及消融后续处理。
- Canneal 独立正式输入 profile：[canneal-formal-apps-build.json](/data1/gzh/EC/firesim/final-opt4-20261106/software/canneal-formal-apps-build.json)、[canneal-formal-rootfs-build.json](/data1/gzh/EC/firesim/final-opt4-20261106/software/canneal-formal-rootfs-build.json)，官方 simmedium 为200000.nets、15000 swaps、初温2000、64 steps、1线程；复用原 ELF，不缩计算。两组内核以现有已构建目录增量构建，仅更换相同 initramfs；[canneal-formal-software-reuse.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/canneal-formal-software-reuse.json) 核对配置（除 initramfs 路径）和 ROI driver object 不变。须先通过该 profile 的 FPGA simsmall 再采正式三轮；不与 Blackscholes 原 profile 混用。

## 实际入口与持续证据

```sh
cd /data1/gzh/EC/firesim/final-opt4-20261106
# 已有构建正在运行；不要重复执行 bitstream 构建。
python3 scripts/continue_fpga.py --check-software-only
sudo python3 scripts/continue_fpga.py --single-board-bdf 0000:21:00.0
```

启动续跑前检查已有状态/PID/boot ID，避免重复控制同一卡。每个 run 目录持续保存 UART、host、ROI/RTL事件；30秒快照刷盘。`result.json` 与 `complete.json` 原子提交并绑定源码/bitstream/driver/软件/输入；统计快照不是指令级恢复检查点。失败、超时、中断和不完整尾部保留；只有匹配版本的有效完成样本可复用。正常主动查询至少间隔5分钟，长构建可10分钟。

| 配置 | 程序输入重复 | 状态 | ROI周期 | 结果 |
| --- | --- | --- | --- | --- |
| Native | blackscholes simmedium r1 (original-parsec-serial) | 有效 | 829737734 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-blackscholes-simmedium-r1-20261106T125841Z/result.json) |
| Native | blackscholes simmedium r2 (original-parsec-serial) | 有效 | 828230479 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-blackscholes-simmedium-r2-20261106T130737Z/result.json) |
| Native | blackscholes simmedium r3 (original-parsec-serial) | 有效 | 829885720 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-blackscholes-simmedium-r3-20261106T131036Z/result.json) |
| Native | blackscholes test r1 (original-parsec-serial) | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-blackscholes-test-r1-20261106T124955Z/result.json) |
| Native | blackscholes test r1 (original-parsec-serial) | 有效 | 208702 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-blackscholes-test-r1-20261106T125530Z/result.json) |
| Native | bodytrack simmedium r1 (bodytrack-serial-staged-input-preallocated-heap-no-aux-timing) | 有效 | 3194624914 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-bodytrack-simmedium-r1-20261107T063100Z/result.json) |
| Native | bodytrack simmedium r2 (bodytrack-serial-staged-input-preallocated-heap-no-aux-timing) | 有效 | 3195119553 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-bodytrack-simmedium-r2-20261107T063624Z/result.json) |
| Native | bodytrack simmedium r3 (bodytrack-serial-staged-input-preallocated-heap-no-aux-timing) | 有效 | 3194104220 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-bodytrack-simmedium-r3-20261107T064149Z/result.json) |
| Native | bodytrack simsmall r1 (bodytrack-serial-staged-input-preallocated-heap-no-aux-timing) | 有效 | 898805472 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-bodytrack-simsmall-r1-20261107T060515Z/result.json) |
| Native | bodytrack test r1 (bodytrack-serial-staged-input-preallocated-heap-no-aux-timing) | 有效 | 202333243 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-bodytrack-test-r1-20261107T060308Z/result.json) |
| Native | canneal simmedium r1 (original-canneal-serial) | 有效 | 1418636771 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-canneal-simmedium-r1-20261107T040043Z/result.json) |
| Native | canneal simmedium r2 (original-canneal-serial) | 有效 | 1416842131 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-canneal-simmedium-r2-20261107T040801Z/result.json) |
| Native | canneal simmedium r3 (original-canneal-serial) | 有效 | 1423403483 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-canneal-simmedium-r3-20261107T041517Z/result.json) |
| Native | canneal simsmall r1 (original-parsec-serial) | 有效 | 426064181 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-canneal-simsmall-r1-20261107T035009Z/result.json) |
| Native | canneal simsmall r1 (original-canneal-serial) | 有效 | 426541923 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-canneal-simsmall-r1-20261107T035606Z/result.json) |
| Native | canneal test r1 (original-parsec-serial) | 有效 | 24480 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-canneal-test-r1-20261106T131219Z/result.json) |
| Native | canneal test r1 (original-parsec-serial) | 有效 | 23874 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-canneal-test-r1-20261107T031341Z/result.json) |
| Native | dedup simmedium r1 (dedup-serial-preload-staged-output-heap256m) | 有效 | 6472778992 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-dedup-simmedium-r1-20261107T120538Z/result.json) |
| Native | dedup simmedium r2 (dedup-serial-preload-staged-output-heap256m) | 有效 | 6464549139 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-dedup-simmedium-r2-20261107T121655Z/result.json) |
| Native | dedup simmedium r3 (dedup-serial-preload-staged-output-heap256m) | 有效 | 6463713978 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-dedup-simmedium-r3-20261107T122808Z/result.json) |
| Native | dedup simsmall r1 (dedup-serial-preload-staged-output-heap256m) | 有效 | 2147874830 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-dedup-simsmall-r1-20261107T115938Z/result.json) |
| Native | dedup test r1 (dedup-serial-preload-staged-output-heap256m) | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-dedup-test-r1-20261107T064713Z/result.json) |
| Native | dedup test r1 (dedup-serial-preload-staged-output-heap256m) | 有效 | 133508 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-dedup-test-r1-20261107T115612Z/result.json) |
| Native | facesim simmedium r1 (facesim-staged-resident-serial) | 有效 | 23266064819 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-facesim-simmedium-r1-20261109T023353Z/result.json) |
| Native | facesim simmedium r2 (facesim-staged-resident-serial) | 有效 | 23269727761 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-facesim-simmedium-r2-20261109T051125Z/result.json) |
| Native | facesim simmedium r3 (facesim-staged-resident-serial) | 有效 | 23263065409 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-facesim-simmedium-r3-20261109T070308Z/result.json) |
| Native | facesim simsmall r1 (facesim-staged-resident-serial) | 有效 | 23253122169 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-facesim-simsmall-r1-20261109T014326Z/result.json) |
| Native | ferret simmedium r1 (ferret-serial-staged-stable-directory-order/1) | 有效 | 5995041333 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-ferret-simmedium-r1-20261109T124827Z/result.json) |
| Native | ferret simmedium r2 (ferret-serial-staged-stable-directory-order/1) | 有效 | 5909124654 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-ferret-simmedium-r2-20261109T131016Z/result.json) |
| Native | ferret simmedium r3 (ferret-serial-staged-stable-directory-order/1) | 有效 | 5903743268 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-ferret-simmedium-r3-20261109T133204Z/result.json) |
| Native | ferret simsmall r1 (ferret-serial-staged-external-io) | 失败/不完整 | 1917479837 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-ferret-simsmall-r1-20261109T032131Z/result.json) |
| Native | ferret simsmall r1 (ferret-serial-staged-stable-directory-order/1) | 有效 | 1887901090 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-ferret-simsmall-r1-20261109T124322Z/result.json) |
| Native | ferret test r1 (ferret-serial-staged-external-io) | 有效 | 24127233 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-ferret-test-r1-20261109T031821Z/result.json) |
| Native | ferret test r1 (ferret-serial-staged-stable-directory-order/1) | 有效 | 24112674 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-ferret-test-r1-20261109T124012Z/result.json) |
| Native | fluidanimate simmedium r1 (fluidanimate-stable-index-pairing-authorized-repair) | 有效 | 2955094722 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-fluidanimate-simmedium-r1-20261107T124945Z/result.json) |
| Native | fluidanimate simmedium r2 (fluidanimate-stable-index-pairing-authorized-repair) | 有效 | 2955023031 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-fluidanimate-simmedium-r2-20261107T125435Z/result.json) |
| Native | fluidanimate simmedium r3 (fluidanimate-stable-index-pairing-authorized-repair) | 有效 | 2953960508 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-fluidanimate-simmedium-r3-20261107T125927Z/result.json) |
| Native | fluidanimate simsmall r1 (fluidanimate-original-serial-no-legacy-checker-harness) | 失败/不完整 | 1275376983 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-fluidanimate-simsmall-r1-20261107T060021Z/result.json) |
| Native | fluidanimate simsmall r1 (fluidanimate-original-serial-no-legacy-checker-harness) | 失败/不完整 | 1275710941 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-fluidanimate-simsmall-r1-20261107T062813Z/result.json) |
| Native | fluidanimate simsmall r1 (fluidanimate-unchanged-app-failed-output-capture-v2) | 失败/不完整 | 1275946919 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-fluidanimate-simsmall-r1-20261107T123922Z/result.json) |
| Native | fluidanimate simsmall r1 (fluidanimate-stable-index-pairing-authorized-repair) | 有效 | 1364786789 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-fluidanimate-simsmall-r1-20261107T124651Z/result.json) |
| Native | fluidanimate test r1 (fluidanimate-original-serial-no-legacy-checker-harness) | 有效 | 27123280 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-fluidanimate-test-r1-20261107T055904Z/result.json) |
| Native | fluidanimate test r1 (fluidanimate-stable-index-pairing-authorized-repair) | 有效 | 28657448 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-fluidanimate-test-r1-20261107T124534Z/result.json) |
| Native | freqmine simmedium r1 (freqmine-serial-staged-input-preallocated-heap-no-aux-timing) | 有效 | 89280523270 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-freqmine-simmedium-r1-20261107T071435Z/result.json) |
| Native | freqmine simmedium r2 (freqmine-serial-staged-input-preallocated-heap-no-aux-timing) | 有效 | 89411029335 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-freqmine-simmedium-r2-20261107T084705Z/result.json) |
| Native | freqmine simmedium r3 (freqmine-serial-staged-input-preallocated-heap-no-aux-timing) | 有效 | 89380362214 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-freqmine-simmedium-r3-20261107T101944Z/result.json) |
| Native | freqmine simsmall r1 (freqmine-serial-staged-input-preallocated-heap-no-aux-timing) | 有效 | 19950377291 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-freqmine-simsmall-r1-20261107T065126Z/result.json) |
| Native | freqmine test r1 (freqmine-serial-staged-input-preallocated-heap-no-aux-timing) | 有效 | 21366691 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-freqmine-test-r1-20261107T064816Z/result.json) |
| Native | netdedup simmedium r1 (netdedup-original-network-full-roi-native/2) | 有效 | 122278776887 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-netdedup-simmedium-r1-20261109T162026Z/result.json) |
| Native | netdedup simmedium r2 (netdedup-original-network-full-roi-native/2) | 有效 | 127809319213 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-netdedup-simmedium-r2-20261109T194910Z/result.json) |
| Native | netdedup simmedium r3 (netdedup-original-network-full-roi-native/2) | 有效 | 94219934597 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-netdedup-simmedium-r3-20261109T220613Z/result.json) |
| Native | netdedup simsmall r1 (netdedup-original-network-full-roi-native/2) | 有效 | 36323953648 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-netdedup-simsmall-r1-20261109T153822Z/result.json) |
| Native | netdedup test r1 (netdedup-original-network-full-roi-native/2) | 有效 | 5435376 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-netdedup-test-r1-20261109T153429Z/result.json) |
| Native | netferret simsmall r1 (network-original-full-roi-native/1) | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-netferret-simsmall-r1-20261109T183156Z/result.json) |
| Native | netferret simsmall r1 (network-full-original-roi-wait-evidence/2) | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-netferret-simsmall-r1-20261110T063425Z/result.json) |
| Native | netferret test r1 (network-original-full-roi-native/1) | 有效 | 4537692629 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-netferret-test-r1-20261109T152353Z/result.json) |
| Native | netferret test r1 (network-full-original-roi-wait-evidence/2) | 有效 | 4962410208 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-netferret-test-r1-20261110T062604Z/result.json) |
| Native | netstreamcluster simmedium r1 (netstreamcluster-full-roi-graceful-client-close/3) | 有效 | 95948907207 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-netstreamcluster-simmedium-r1-20261110T074633Z/result.json) |
| Native | netstreamcluster simmedium r2 (netstreamcluster-full-roi-graceful-client-close/3) | 有效 | 99353979454 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-netstreamcluster-simmedium-r2-20261110T092400Z/result.json) |
| Native | netstreamcluster simmedium r3 (netstreamcluster-full-roi-graceful-client-close/3) | 有效 | 101948687434 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-netstreamcluster-simmedium-r3-20261110T110450Z/result.json) |
| Native | netstreamcluster simsmall r1 (netstreamcluster-full-roi-graceful-client-close/3) | 有效 | 5156726029 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-netstreamcluster-simsmall-r1-20261110T073956Z/result.json) |
| Native | netstreamcluster test r1 (network-original-full-roi-native/1) | 失败/不完整 | 151860037 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-netstreamcluster-test-r1-20261109T193806Z/result.json) |
| Native | netstreamcluster test r1 (network-full-original-roi-wait-evidence/2) | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-netstreamcluster-test-r1-20261110T044235Z/result.json) |
| Native | netstreamcluster test r1 (netstreamcluster-full-roi-graceful-client-close/3) | 有效 | 182537088 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-netstreamcluster-test-r1-20261110T073819Z/result.json) |
| Native | raytrace simmedium r1 (raytrace-original-headless-memory-framebuffer) | 有效 | 2400529768 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-raytrace-simmedium-r1-20261109T035359Z/result.json) |
| Native | raytrace simmedium r2 (raytrace-original-headless-memory-framebuffer) | 有效 | 2392313252 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-raytrace-simmedium-r2-20261109T055553Z/result.json) |
| Native | raytrace simmedium r3 (raytrace-original-headless-memory-framebuffer) | 有效 | 2400206956 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-raytrace-simmedium-r3-20261109T074736Z/result.json) |
| Native | raytrace simsmall r1 (raytrace-original-headless-memory-framebuffer) | 有效 | 859156997 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-raytrace-simsmall-r1-20261109T032637Z/result.json) |
| Native | smoke test r1 (original-parsec-serial) | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T113339Z/result.json) |
| Native | smoke test r1 (original-parsec-serial) | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T114605Z/result.json) |
| Native | smoke test r1 (original-parsec-serial) | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T120448Z/result.json) |
| Native | smoke test r1 (original-parsec-serial) | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T121201Z/result.json) |
| Native | smoke test r1 (original-parsec-serial) | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T121323Z/result.json) |
| Native | smoke test r1 (original-parsec-serial) | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T122201Z/result.json) |
| Native | smoke test r1 (original-parsec-serial) | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T122810Z/result.json) |
| Native | smoke test r1 (original-parsec-serial) | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T123007Z/result.json) |
| Native | smoke test r1 (original-parsec-serial) | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T124105Z/result.json) |
| Native | smoke test r1 (original-parsec-serial) | 有效 | 5772 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T124817Z/result.json) |
| Native | smoke test r1 (original-parsec-serial) | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T125842Z/result.json) |
| Native | smoke test r1 (original-parsec-serial) | 有效 | 5871 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T130155Z/result.json) |
| Native | smoke test r1 (original-parsec-serial) | 有效 | 5803 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261106T140002Z/result.json) |
| Native | smoke test r1 (original-parsec-serial) | 有效 | 5809 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261107T031102Z/result.json) |
| Native | smoke test r1 (original-parsec-serial) | 有效 | 5813 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261107T062632Z/result.json) |
| Native | smoke test r1 (original-parsec-serial) | 有效 | 5813 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-smoke-test-r1-20261109T013929Z/result.json) |
| Native | streamcluster simmedium r1 (streamcluster-staged-io-synthetic-serial) | 有效 | 7859948287 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-streamcluster-simmedium-r1-20261107T053224Z/result.json) |
| Native | streamcluster simmedium r2 (streamcluster-staged-io-synthetic-serial) | 有效 | 7860308074 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-streamcluster-simmedium-r2-20261107T054117Z/result.json) |
| Native | streamcluster simmedium r3 (streamcluster-staged-io-synthetic-serial) | 有效 | 7859659608 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-streamcluster-simmedium-r3-20261107T055010Z/result.json) |
| Native | streamcluster simsmall r1 (streamcluster-staged-io-synthetic-serial) | 有效 | 1436868851 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-streamcluster-simsmall-r1-20261107T032806Z/result.json) |
| Native | streamcluster simsmall r1 (streamcluster-staged-io-synthetic-serial) | 有效 | 1436993042 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-streamcluster-simsmall-r1-20261107T052957Z/result.json) |
| Native | streamcluster test r1 (streamcluster-staged-io-synthetic-serial) | 有效 | 127459 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-streamcluster-test-r1-20261107T032623Z/result.json) |
| Native | streamcluster test r1 (streamcluster-staged-io-synthetic-serial) | 有效 | 127267 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-streamcluster-test-r1-20261107T052856Z/result.json) |
| Native | swaptions simmedium r1 (swaptions-serial-preallocated-heap) | 有效 | 4870809991 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-swaptions-simmedium-r1-20261107T051114Z/result.json) |
| Native | swaptions simmedium r2 (swaptions-serial-preallocated-heap) | 有效 | 4870171180 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-swaptions-simmedium-r2-20261107T051708Z/result.json) |
| Native | swaptions simmedium r3 (swaptions-serial-preallocated-heap) | 有效 | 4870239106 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-swaptions-simmedium-r3-20261107T052301Z/result.json) |
| Native | swaptions simsmall r1 (swaptions-serial-preallocated-heap) | 有效 | 1253797248 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-swaptions-simsmall-r1-20261107T050857Z/result.json) |
| Native | swaptions test r1 (swaptions-serial-preallocated-heap) | 有效 | 142991 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-swaptions-test-r1-20261107T050756Z/result.json) |
| Native | vips simmedium r1 (vips-complete-im-benchmark-resident-io) | 有效 | 8038929294 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-vips-simmedium-r1-20261109T125749Z/result.json) |
| Native | vips simmedium r2 (vips-complete-im-benchmark-resident-io) | 有效 | 8043251779 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-vips-simmedium-r2-20261109T131935Z/result.json) |
| Native | vips simmedium r3 (vips-complete-im-benchmark-resident-io) | 有效 | 8059352129 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-vips-simmedium-r3-20261109T134120Z/result.json) |
| Native | vips simsmall r1 (vips-complete-im-benchmark-resident-io) | 有效 | 2668393167 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-vips-simsmall-r1-20261109T123335Z/result.json) |
| Native | vips test r1 (vips-complete-im-benchmark-resident-io) | 失败/不完整 | None | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-vips-test-r1-20261109T042304Z/result.json) |
| Native | vips test r1 (vips-complete-im-benchmark-resident-io) | 有效 | 205258452 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-vips-test-r1-20261109T122938Z/result.json) |
| Native | x264 simmedium r1 (x264-original-encoder-staged-io-no-progress) | 有效 | 34722053946 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-x264-simmedium-r1-20261109T043328Z/result.json) |
| Native | x264 simmedium r2 (x264-original-encoder-staged-io-no-progress) | 有效 | 34666724065 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-x264-simmedium-r2-20261109T062515Z/result.json) |
| Native | x264 simmedium r3 (x264-original-encoder-staged-io-no-progress) | 有效 | 34670813804 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-x264-simmedium-r3-20261109T081641Z/result.json) |
| Native | x264 simsmall r1 (x264-original-encoder-staged-io-no-progress) | 有效 | 2771389425 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-x264-simsmall-r1-20261109T042734Z/result.json) |
| Native | x264 test r1 (x264-original-encoder-staged-io-no-progress) | 有效 | 5963191 | [result.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-x264-test-r1-20261109T042427Z/result.json) |

历史 Verilator Streamcluster project64 的1.1995×不作为 FPGA 结果或调参目标。当前阶段不对缺少C4配对的数据发布 slowdown；共同有效集合与重复波动由 results-summary.json 明确记录。


2026-11-11结构性存储优化实做：[20261111T042537Z REPORT](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-structural-storage-20261111T042537Z/REPORT.md)。原9ae整机保持运行；e0组合已准备且CAD排队，未开始第二整机。新2210930f完整所有权存储、e21194b2地址共享+序列表组合实际启动独立验证。通用存储探针305778→15888LUT不能当整机收益；保留全部generation观察的实测图与组合验证通过后才可选择。Native暂停、21-only、功能扩展禁止。
