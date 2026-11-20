from pathlib import Path
import json,os,datetime
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');U=D/'unattended-opt4';a=json.loads((U/'last-foreground-structural-audit.json').read_text());O=Path(a['audit']);snap=json.loads((O/'snapshot.json').read_text());utc=snap['utc']
text=f'''# Opt4 结构性存储优化与受限双 DUT 综合实际推进

记录时刻：{utc}。原始进程/日志/状态快照：[snapshot.json]({O}/snapshot.json)。

唯一功能基线8491167d84b6d9521b151a743673c1516926a1f8；仅功能和周期等价优化。Native保持暂停；所有FPGA流程仅允许0000:21:00.0/21770433G02LA。本轮没有任何FPGA、e2、XDMA、reset、rescan操作。

| 项目 | 实际状态 | 面积/验证结论 |
|---|---|---|
| 9ae9a7fc 整机 | DUT synth仍实际计算，保留原PID/输入 | 未产生该版DUT或post-opt报告；FIT未知 |
| e0c3737f 整机 | **新独立服务已启动，实际DUT synth** | Vivado1884262并非本次worker；正确实际worker为2484262，身份在snapshot。尚无该版资源报告 |
| DCache2210930f | 源绑定组合校验/编译/冻结参数/elaboration通过，GoldenGate进行中 | 完整模块面积待真实配对综合；不能宣称完整DCache已省175540LUT |
| DCache完整配对 | 独立作业已经启动，等待候选GoldenGate | 保留所有原端口、512×32generation输出和匹配的原DontTouch标识；候选/参考依次真实综合 |
| e21194b2完整地址 | 正在实际模块综合 | 已通过冻结6144周期/52输出、独立reset及继承序列存储归纳证明；面积待产出 |
| 99c25302组合 | 独立源码提交已准备，等待实际模块面积门 | 未获准整机，未完成组合编译/GG；不能当作已验证硬件或FIT |
| bitstream/Opt4 FPGA | 未产生认证bitstream，未上板 | 真实样本0；没有用历史Verilator比值代替FPGA结果 |

最近完成的真实整机仍为8da24a26：post-opt **3,215,683 LUT /92,789 CARRY8 /195 DSP**。U280 LUT容量1,303,680，缺口1,912,003LUT。该版NOT_FIT_POSTOPT，未进入place。这个数不能冒充9ae/e0/99c的新结果。

## DCache实际突破及证明边界

保留全部generation观察的源感知12个变量读端口存储边界：

| 版本 | LUT | FF | CARRY8 | DSP |
|---|---:|---:|---:|---:|
| reference | 265176 | 41984 | 0 | 0 |
| candidate | 89636 | 16896 | 0 | 0 |

实测节省175540LUT(66.2%)。报告：
- {D}/build-logs/Opt4-fit-dcache-owner-observed-map-r1-20261111/reference/utilization.rpt
- {D}/build-logs/Opt4-fit-dcache-owner-observed-map-r1-20261111/candidate/utilization.rpt

原始完整面积状态漏写source_id，导致system-r2的verify-combination KeyError，而不是SAT失败。本轮保留原始结果，创建system-r4；通过原map配置、source-contract、source_validation_receipt与实际源码哈希建立新补充绑定：
{D}/build-logs/Opt4-fit-dcache-owner-system-r4-20261111/observed-map-source-binding.json。

等价证据包括：50处原读表达式与写守卫逐字节反向复原；512word存储任意状态/掩码的逐位转移归纳；实际Chisel Arbiter2证明两写来源互斥及复位优先；8192周期146位、碰撞、独立reset和全部512generation读对照。由逐位关系提升至146位，保留81/32/32/1完整字段。**这是明确范围的源绑定组合等价，尚无单次完整DCache生成RTL SAT结论。**

新的真实完整模块对比从两个已绑定GoldenGate原始RTL提取相同顶层；只在隔离面积副本增加512×32generation观察出口，实际正式RTL不改。匹配全部普通端口和保留观察，检查零blackbox后保存真实fullDCache utilization/DCP。不会把存储边界节省或组件面积相加当成整机FIT。

状态：{D}/Opt4-fit-dcache-full-pair-r1-state.json
日志：{D}/build-logs/Opt4-fit-dcache-full-pair-r1-20261111/

## 已实际启动e0，避免无限等待9ae

9ae worker1886276在04:37 CPU为1535084ticks，04:57为1656826ticks；RSS约14.16GiB。阶段日志仍179270bytes，最后更新时间03:12UTC。CPU增长证明仍在计算，不能证明综合阶段已推进或必将收敛；没有新DCP/资源报告，未因沉默终止它。

评估可安全重叠后，新e0由独立systemd作业启动：
- unit: ec-opt4-auto-e0-safe-overlap-cad-r4-e0c3737f.service
- controller PID2484108；实际Vivado2484262，start_ticks和boot_id见snapshot。
- 源码/RTL/ABI保持e0原绑定，source ID b058237185f3c6f1c730e4a128e4c3670299eb45a250627fa61aeb3eb631d235。
- 作业路径：{U}/jobs/e0-safe-overlap-cad-r4-e0c3737f/
- 资源：8核quota、96GiB MemoryHigh、128GiB MemoryMax、禁用该cgroup swap；开始前要求256GiB可用内存、250GiB磁盘、load<96。已完成整机历史峰值约33GiB，当前snapshot仍可用{snap['available_memory_gib']:.1f}GiB内存/{snap['free_disk_gib']:.1f}GiB磁盘。
- 原排队r3仅DEFERRED，保留原receipt并标记被新控制器替代，避免未来重复启动。标准jobs/request账本已注册新服务，后续broker拒绝第三个整机。
- 只允许两个独立DUT综合；e0顶层实现等待9ae安全退出。已有版本一旦实测FIT，优先其实现/runtime。未修改已加载的9ae脚本。

## 下一版的实际自动接续

99c25302ab9139907416e4673bfa39e07e2dc38e，source ID692f804534a9c73890d6d86b348aa6470f8d1d9a222b3e05975766ec33f8cd63：
{W}/Opt4-fit-owner-update-sequence-r1-20261111。

它只把221的DCache字节与e211的PackageAddressStats/AddressBucketSequenceMemory字节组合，其他字节保持共同e0父版本；尚待面积门和组合验证。完整DCache实测节省>=75000LUT、e211完整地址优于872880LUT后，验证精确不重叠源码组合、编译、冻结参数、类来源、GG及七项ABI。没有验证通过之前不进入整机。

新组合接续最初期待了旧组件的完成状态名，而e211真实producer输出为VERIFIED_AND_MAPPED_COMPLETE_ADDRESS_MODULE_NOT_WHOLE_DUT。本轮只结束新建且无子任务的闲等待consumer，完整保留证据，在独立system-r2/cad-r2更正producer/consumer契约；所有Vivado及完整模块作业未受影响。

- 组合状态：{D}/Opt4-fit-owner-update-sequence-system-r2-state.json
- 契约核验：{W}/candidates/owner-update-sequence-system-r2-20261111/producer-consumer-contract.json
- 整机请求：{U}/requests/owner-update-sequence-cad-r2-99c25302.json，目前DEFERRED，绝非已启动第三个综合。
- runtime描述：{W}/runtime-candidates/99c25302.json
- 21-only模板已实际生成：{W}/runtime/Opt4-fit-99c25302/bundle.json
- 启动请求等待真实认证bitstream：{U}/request-results/99c25302-start-runtime.json

最短实现路径：当前9ae/e0的DUT报告→顶层link/opt与实际容量门→FIT立即place/route→setup/hold及DRC→bitstream→哈希/版本/七项ABI认证→21安全边界→smoke/checker/排空/正确性→13项首轮正式采样。NOT FIT在place前停止，切换已证明/有实测收益的下一版。原版本的故障行为完整保留；没有新architectural rollback扩展，也不能把无故障smoke声称为故障恢复验证通过。

无人值守ec-opt4-unattended.service保持，snapshot每300秒记录已知PID树和日志变化。重连只按boot_id+PID+start_ticks接管；活进程不重复启动，不修改输入，已完成阶段按哈希receipt复用。
'''
# Correct accidental illustrative PID in draft; report contains only actual worker.
text=text.replace('Vivado1884262并非本次worker；正确实际worker为2484262，身份在snapshot。','实际Vivado2484262，身份在snapshot。')
(O/'REPORT.md').write_text(text)
entry=f'''# 最新实际推进（{utc}）

9ae整机保持，e0已在独立8核/128GiB服务中实际进入DUT综合；二者均尚无新资源报告。DCache源绑定组合证明通过、GoldenGate进行中；真实完整DCache匹配面积作业等待该RTL。保留全部generation观察的存储边界265176→89636LUT，节省175540，不能当完整模块或整机收益。e211完整地址正在map。99c25302独立组合及既有21-only认证/runtime模板已准备，但受真实面积/证明门和无第三整机守卫约束，未获准整机。

本轮实际操作、进程身份、资源与完整证据：[REPORT.md]({O}/REPORT.md)。最近完成整机仍8da：3215683LUT/92789CARRY8/195DSP，NOTFIT。无认证bitstream、无Opt4FPGA样本。Native暂停，仅8491167d功能/周期等价优化，禁止功能扩展与e2/全局设备操作。

'''
for p in [W/'UNATTENDED_OPT4.md',Path('/data1/gzh/EC/slowdown/final_opt4_freeze_20261106/FIRESIM_START_HERE.md')]:
 content=p.read_text() if p.exists() else '';q=p.with_name(p.name+'.tmp-latest');q.write_text(entry+content);os.replace(q,p)
p=U/'foreground-area-owner.json';j=json.loads(p.read_text());j.update(status='COMPLETED_HANDOFF_LIVE_DUAL_DUT_AND_FULL_DCACHE_JOBS',latest_report=str(O/'REPORT.md'),next='Preserve live9ae/e0; no thirdwhole. Adopt owner-system-r4, fullDCache pair r1 and combo-system-r2 canonical e211 producer status. Continue independent highgain structural optimization until realFIT, then implementation/runtime priority. Existing external model proxy availability remains a limit; never claim unlimited disconnected AI without network.');q=p.with_suffix('.tmp-handoff');q.write_text(json.dumps(j,indent=2)+'\n');os.replace(q,p)
print(O/'REPORT.md')
