# Opt4 等价面积优化实际推进

证据时间：2026-11-11T05:48:20.759777+00:00。唯一功能基线8491167d84b6d9521b151a743673c1516926a1f8；不增加功能。Native暂停，严格21-only。没有进行任何FPGA、驱动或PCIe操作，没有终止/重启正常CAD，没有改变两条活综合的输入。

## 整机与容量

| 版本 | 当前直接证据 | 实测整机资源/FIT |
|---|---|---|
|9ae9a7fc|实际DUT Vivado PID1886276/start16844839；日志由179270增加到429976字节，完成RTL Optimization Phase2、Cross Boundary and Area Optimization、XDC，进入Start Timing Optimization|新资源报告尚未产生；FIT未知|
|e0c3737f|实际DUT Vivado PID2484262/start18404293；独立8核/MemoryMax128GiB服务，DUT综合中|新资源报告尚未产生；FIT未知|
|8da24a26（最近完成的旧版）|完整top post-opt报告，已NOT_FIT_POSTOPT，容量门阻止布局|3215683LUT、92789CARRY8、195DSP；U280容量1303680LUT，超1912003LUT|

9ae的实际阶段日志：[dut_synth-attempt-1.log](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-bucket-tag-cad-9ae9a7fc/dut_synth-attempt-1.log)。Cross Boundary/Area完成CPU04:41:34、elapsed04:46:07；XDC完成CPU04:44:30、elapsed04:49:19。不是只凭CPU增长判定阶段推进。

旧版8da层级：addressStats1265491LUT、BOOM core244938LUT、MSHRFile222552LUT（内部最大MSHR187591LUT）、L2168544LUT；DCache包含地址统计/MSHR等，共2124812LUT。这些是旧版的包含关系，不能相加当额外面积，也不能当9ae/e0新实测。

## DCache 完整验证与实测边界

- 2210930f：实际GoldenGate完成、真实类来源/冻结参数/7项ABI核对通过，状态RTL_READY_REAL_ABI_CHECKED。
- 完整DCache匹配面积作业实际运行候选综合，随后同控制器运行参考。实际PID2557949；真实生成RTL接口完全相同，保留512×32generation输出及原DontTouch观察。完整模块面积还未产生，不能宣称完整模块节省175540LUT。
- 已完成的**存储观察边界**：265176→89636LUT，减少175540（66.2%）；FF41984→16896。范围包含12个可变读端和全部512个generation观察，仍不是完整DCache/整机收益。
- 源绑定状态归纳、实际Arbiter2互斥及reset/冲突测试已通过；未声称单体完整DCache/整机形式证明。
- 新提取真实GG生成RTL：3584个参考字段next-state块、候选单写memory/512个有效mask转换、全部512个generation拓扑。原联合SAT有4034401变量/10975959子句，600秒超时。失败证据完整保留；超时不能记PASS。
- 已实际启动独立分区恢复服务ec-opt4-auto-dcache-generated-owner-proof-r3b-2210930f.service，先等待原SAT真实退出，复用哈希认证miter；每组8项、覆盖全部512项，solver超时才自动拆分，真实语义反例立即保留失败。正向完成后要求对真实候选写数据位翻转得到反例。当前状态RUNNING_PARTITIONED_GENERATED_TRANSITION_PROOF，已覆盖120/512；尚未完成不得写全证明通过。
- 分区形式范围仍是实际生成存储transition cut；未改DUT，未缩位宽、未删观察，未将其冒充完整DCache/整机形式证明。

## 地址组合与下一整机

- e21194b2完整地址仍在实际map；已完成冻结6144周期/52输出对照、独立global reset及源绑定组合归纳。没有用00847或27f7的单独面积代替组合面积。
- 99c25302提前组合验证已完成：精确disjoint源码组合、10个改动源码全部类型检查、冻结C4/SVB32/core/cache/memory参数相等、组合类重新生成的地址RTL逻辑与e211一致；状态PASS_EXACT_DISJOINT_COMPOSITION_FULL_CHANGED_SOURCE_TYPECHECK_FROZEN_PARAMETERS_AND_EMITTED_ADDRESS_RTL_NOT_AREA_ADMITTED。完整最终GG/7ABI仍须按面积门接续。
- 已准备不可变下一CAD r3：仅将真实DUT utilization/hierarchical报告提前到DCP导出前，缩短等报告时间。未改RTL/约束/当前活脚本。检查文件：/data1/gzh/EC/firesim/final-opt4-20261106/candidates/owner-update-sequence-cad-r3-20261111/source-and-flow-check.json。
- canonical请求/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/unattended-opt4/requests/owner-update-sequence-cad-r3-99c25302.json目前DEFERRED；两条整机正常运行时绝不启动第三条。
- 放行条件仍要求真实完整DCache节省≥75000LUT、e211完整地址<872880LUT、精确组合/GG/ABI；之后等待现有整机安全退出。NOT FIT在place前停；FIT立即实现/时序/DRC/bitstream/认证/21-only runtime。

## 连续运行与资源

资源审计2026-11-11T05:44:39.743511+00:00：可用内存322.42GiB，磁盘空闲366.27GiB。四条实际Vivado作业CPU均有增长，nr_throttled=0、memory.failcnt=0、CPU/内存/I/O PSI无明显等待。没有证据支持停止现有CAD。hybrid/v1 cgroup取实际cpu,cpuacct与memory控制器路径，未误用统一cgroup路径。

无人值守主服务持续运行，已完成24轮。独立round24实际产生3d29eff9 slotEpoch结构候选并通过16位算术SAT和错误级联increment负例；存储边界/完整模块面积仍待验证，不计面积收益、不合入。服务存活不等于FIT；每轮原始输出位于/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/unattended-opt4/rounds/。

新分区请求首次把证据文件误放executable输入类，被broker拒绝，尚未启动子进程；原拒绝receipt保留。已改为独立evidence_inputs、所有绑定预检通过，使用新不可变r3b任务名，真实service已启动。

## 自动恢复与上板门

分区服务有单实例锁、PID/start_ticks/boot_id、持续日志、每partition原子result和覆盖记录；重连先核验身份并接管。原SAT超时与提取输入保留，不覆盖有效证据。现有broker/headless继续接续失败/无收益候选。

当前没有9ae/e0的新整机FIT结果，没有认证Opt4 bitstream，没有上板/正式样本。99c运行模板已生成，runtime仍等待真正CAD完成、同源绑定/ABI、时序/DRC/bitstream认证及21卡安全边界；不得用排队/准备就绪代替上板。Native继续暂停。

## 证据入口

- 本审计原始与后续资源：resource-progress.json、resource-progress-followup.json。
- /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-dcache-full-pair-r1-state.json
- /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-address-update-sequence-r1-state.json
- /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-dcache-generated-owner-proof-r2-state.json（原超时）
- /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-dcache-generated-owner-proof-r3-state.json（当前分区）
- /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-generated-owner-proof-r3-20261111/
- /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-owner-sequence-precheck-r1-state.json（已通过）
- /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/unattended-opt4/campaign-policy.json、state.json、snapshot.json、ledger.jsonl
