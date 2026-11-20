# Opt4 实际映射失败恢复与字段存储优化

更新时间：2026-11-11T06:08:08.840480+00:00（UTC）。本记录覆盖早前REPORT.md中的已变化状态。没有中断9ae/e0，没有修改冻结Tag/活动综合输入，没有FPGA、驱动或PCIe操作。仅8491167d84b6d9521b151a743673c1516926a1f8功能/周期等价优化。Native继续暂停，21-only。

| 项目 | 当前真实状态 | 面积/结论 |
|---|---|---|
|9ae9a7fc整机|DUT综合；完成Cross Boundary/Area和XDC后进入Timing Optimization；后续尚无新阶段报告|暂无其整机LUT/CARRY8/DSP；FIT未知|
|e0c3737f整机|DUT综合实际进程继续|暂无其整机资源；FIT未知|
|e21194b2完整地址|实际map中，冻结6144周期/52输出和reset对照已通过|暂无组合实测面积，不用单独候选面积相加|
|2210930f完整DCache旧评估|实际综合于05:51UTC失败，证据保留|Synth8-3391，不能写通过或推断完整模块收益|
|2210930f完整DCache恢复|RUNNING_FULL_DCACHE_CANDIDATE_SYNTH，新独立service已实际启动|仅同一份RTL的工具映射恢复，资源待实测|
|实际生成存储转换形式验证|512/512分区全部PASS；真实写数据bitflip反例成立|完整146bit状态/512generation拓扑的transition cut，仍不是单体完整DCache/整机形式证明|
|d9d73262字段存储候选|PASS_SOURCE_BOUND_FIELD_STORAGE_RELATION_TYPECHECK_FROZEN_PARAMETERS_NOT_GENERATED_OR_AREA_ADMITTED|源绑定字段归纳/SAT、真实改动源码编译、冻结参数PASS；未获面积/整机准入|
|d9d73262实际GoldenGate|RUNNING_GOLDENGATE，独立服务实际运行|须确认实际81/32/32/1物理存储及新生成RTL/完整DCache面积；当前无其收益数据|
|99c25302下一整机|源码组合/编译/参数/地址RTL一致性预检PASS；恢复prep-r3等待真实面积；CAD-r5为DEFERRED|没有启动第三条整机|
|Opt4 bitstream/实验|尚无认证bitstream、尚无Opt4 FPGA样本|不能部署未认证候选|

最近**已完成**整机仍为旧8da24a26 post-opt：**3215683 LUT、92789 CARRY8、195 DSP**。U280 LUT容量1303680，旧版超**1912003 LUT**。这不是9ae/e0的新结果或剩余缺口预测。最近旧版层级：addressStats1265491、BOOM core244938、MSHRFile222552（含最大MSHR187591）、L2168544 LUT；DCache包含前述地址/MSHR等，总2124812 LUT，不能重复相加。

## 这次实际修复

1. 原512word联合SAT600秒超时，保留原结果，改用64组8word的完整覆盖；每组实际源miter哈希认证，全部成功。负例直接翻转候选写数据bit，SAT确实找到反例。全部partition/miter/log/result哈希再次由待启动整机的准入函数实际读取认证通过。证据generated-proof-positive-admission.json。没有把timeout记通过。
2. 完整DCache的**真实GG RTL**中，Bundle146bits被打包成74752bit单个memory。Vivado报告当前多端口访问模式不支持RAM推断，并因74752bits超过默认dissolve规模拒绝fallback。这是直接错误；不能拿12读端plain-Chisel观察边界的175540LUT收益当完整GG模块收益。
3. 原完整DCache控制器和Vivado已真实退出后，建立独立full-pair-r2，用工具错误明确建议的`dissolveMemorySizeLimit 74752`允许同RTL转寄存器实现。参考/候选都保留完整端口、512×32generation和原DontTouch；仍必须实测收益≥75000LUT才允许后续组合。没有降低正确性或隐藏回退面积。
4. 旧组合等待器因真实依赖失败自然退出；建立prep-r3和待启动CAD-r5，重新绑定恢复producer，补齐生成存储证明硬门，并在未来实际整机Tcl保留同一工具设置。旧DEFERRED请求仅作supersede，原receipt已保存；活9ae/e0脚本、输入和unit均未改。恢复链producer/consumer静态核对通过：recovery-chain-preflight.json。
5. 同时实现真正的结构修复候选**d9d732622601ed792a2647546006b5aae986ab8e**，source ID **1639f464d8675806abb5d7dd04adc5dfd1fcf0e351e016ef6a20adcbea1b6e4e**，父2210930f。仅将打包OwnerPayload存储改为image81/generation32/packetSeq32/tracked1四个物理Mem；同异步读取、同写guard/index/edge、同resetmask。逆向恢复父源码逐字节一致，原50个读取及全部观察保持。
6. d9d73262已完成源绑定字段状态关系SAT、真实数据字段错误的负例、全部9个改动源码类型检查、真实冻结参数对照。它尚无新生成完整DCache证明/面积；因此只启动独立GoldenGate准备，**不允许进入整机**。实际GG后将断言四块物理memory布局，而不是用普通Chisel RTL猜测。

## 持久任务与证据

- 原失败：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-dcache-full-pair-r1-state.json；build-logs/Opt4-fit-dcache-full-pair-r1-20261111/candidate/attempt-1.log。
- 新完整模块恢复：ec-opt4-auto-dcache-full-pair-r2-2210930f.service；/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-dcache-full-pair-r2-state.json；build-logs/Opt4-fit-dcache-full-pair-r2-20261111/。
- 已通过生成存储证明：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-dcache-generated-owner-proof-r3-state.json；build-logs/Opt4-fit-dcache-generated-owner-proof-r3-20261111/result.json。它明确记录whole_dut_formal=false/complete_dcache_formal=false。
- 字段候选：/data1/gzh/EC/firesim/final-opt4-20261106/Opt4-fit-dcache-owner-fieldbanks-r1-20261111；candidates/dcache-owner-fieldbanks-r1-20261111/config.json、candidate.patch、reverse-substitutions.json；/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-dcache-owner-fieldbanks-r1-state.json。
- 字段真实GG：ec-opt4-auto-dcache-fieldbank-system-r1-d9d73262.service；/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-dcache-fieldbank-system-r1-state.json；完成后独立RTL receipt为Opt4-fit-dcache-fieldbank-rtl-state.json。
- 后继组合：Opt4-fit-owner-update-sequence-system-r3-state.json；后继整机请求unattended-opt4/requests/owner-update-sequence-cad-r5-99c25302.json，仍受无第三整机/面积/证明/GG/ABI门限制。
- 早期资源竞争：resource-progress-followup.json，nr_throttled/memory.failcnt均0；latest-recovery-and-cad-status.json记录最近阶段状态。没有内存/CPU竞争证据要求停止活CAD。

## 持续接续

无人值守原服务/现有优化轮次继续；新验证/RTL服务具备锁、boot_id/PID/start_ticks、原子状态和持久日志，断线后按身份接管，禁止重复启动。campaign-policy.json和foreground-area-owner.json已绑定规范新路径。

下一步：full-pair-r2取得真实面积后按收益门决定是否推进99c；d9真实GG完成后核对field写/读、完整观察和生成storage转换，进行完整DCache候选面积，只有完成且同源的参考报告才可复用，不重复活参考作业。候选无收益/NOT FIT继续独立结构优化，任何整机FIT立即优先实现、时序、DRC、bitstream、认证和21-only运行；Native保持暂停。
