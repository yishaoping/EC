#!/usr/bin/env python3
"""Write complete inconclusive artifacts when one sealed arm aborts before ROI end."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
root = Path((ROOT / 'AI/TMP/.l1_causal_active').read_text().strip())
a = json.loads((root / 'baseline_result.json').read_text())
b = json.loads((root / 'l1_64k_2way_result.json').read_text())
validation = json.loads((root / 'validation_result.json').read_text())
assert validation['status'] == 'FAIL' and a['valid'] and not b['valid']
assert b['roi_cycles'] is None and b['runtime']['exit_status'] == 1
evidence = json.loads((root / 'r2_B_failure_evidence.json').read_text())
assert evidence['run'] == b['run']
c = a['causal']['counts']
status = 'INCONCLUSIVE_DUE_TO_CORRECTNESS_OR_MEASUREMENT'
def md(name, value):
    (root / name).write_text(value.strip() + '\n')

metrics = [
 ('软件ROI cycles', f"{a['roi_cycles']:,}", 'UNAVAILABLE', 'UNAVAILABLE'),
 ('净改善 cycles / %', '—', '—', 'UNAVAILABLE / UNAVAILABLE'),
 ('实际L1首次lookup tag misses（traffic窗口）', str(a['actual_l1']['miss']), 'UNAVAILABLE', 'UNAVAILABLE'),
 ('MSHR busy / full cycles（精确ROI）', f"{c['mshr_busy_cycles']:,} / {c['mshr_full_cycles']:,}", 'UNAVAILABLE', 'UNAVAILABLE'),
 ('RPQ replay events / active cycles', f"{c['load_rpq_replays']} / {c['load_rpq_replay_cycles']}", 'UNAVAILABLE', 'UNAVAILABLE'),
 ('nack retry events / active cycles', f"{c['load_nack_retries']:,} / {c['load_nack_retry_cycles']:,}", 'UNAVAILABLE', 'UNAVAILABLE'),
 ('ROB-head miss-wait cycles', f"{c['ROB_HEAD_WAITING_ON_LOAD_MISS_CYCLES']:,}", 'UNAVAILABLE', 'UNAVAILABLE'),
 ('head∩MSHRbusy / full', f"{c['ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_BUSY_CYCLES']:,} / {c['ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_FULL_CYCLES']}", 'UNAVAILABLE', 'UNAVAILABLE'),
 ('scheduler unavailable', f"{c['scheduler_unavailable_cycles']:,}", 'UNAVAILABLE', 'UNAVAILABLE'),
 ('scheduler∩MSHRbusy / full', f"{c['SCHEDULER_UNAVAILABLE_AND_MSHR_BUSY_CYCLES']} / {c['SCHEDULER_UNAVAILABLE_AND_MSHR_FULL_CYCLES']}", 'UNAVAILABLE', 'UNAVAILABLE'),
 ('head∩scheduler', str(c['ROB_HEAD_LOAD_BLOCK_AND_SCHEDULER_UNAVAILABLE_CYCLES']), 'UNAVAILABLE', 'UNAVAILABLE')]
table = '\n'.join(['|指标|A 32KiB/2way|B 64KiB/2way|A−B|', '|---|---:|---:|---:|'] +
                  ['|' + '|'.join(row) + '|' for row in metrics])

md('README.md', f'''# L1-Causal-1 最终状态

**{status}**

`NEXT_OPTIMIZATION = NONE_JUSTIFIED`

两组均完成真实 elaboration、RTL generation、Verilator build，并实际执行仿真。
**A 完整 PASS，ROI1,707,863；B 触发 checker3 ownership watchdog/assert24，exit1，未完成ROI。**
因此不存在有效的ROI、miss或critical-path paired delta，不能支持或否定L1 capacity的性能收益。

{table}

A 功能、verified1/checksum43439728、integrity、protocol、ordering、L2 read-consistent observer、
STOP40–45、ROI marker与native causal/守恒检查全部PASS。B 的 start marker698301有效，
但无stop、verified/checksum、最终L1/L2 summaries；B correctness FAIL，其observer最终验证不可用。
已观测prefix的integrity ledger通过不等于整次run正确。

已定位到seq67本地CANCEL入队后context cleanup未闭合、result handoff未开放的直接阻塞链；
具体上游trap/start/return触发条件尚未证明。下一步先关闭该correctness问题，再考虑新成对性能实验。
没有改checker、MSHR、replay/scheduler、SVB16或L2策略，没有4way或正式Opt5。

L1 miss reduction转化为critical-path cycle reduction：**NOT YET PROVEN**。

[失败分析](r2_B_correctness_failure.md) · [20项回答](answers_20.md) ·
[设计/审查](experiment_design.md) · [改动](code_changes.md) · [计数口径](causal_counter_schema.md) ·
[计数对照](causal_counter_comparison.md) · [observer](observer_validation.md) ·
[性能归因](performance_attribution.md) · [Opt5判决](opt5_decision.md) ·
[validation](validation_result.json) · [manifest](run_manifest.json)

最终结果只使用`revisions/r2/arms/`。source fingerprint
`b6f9a8739a0be1a64cd349625e37dc8b5b8cd246b418041bc3ee68dd1af414b1`。
两组source/software/tool seal一致，实际仿真参数一致，时钟/L2生成配置一致；仅BOOM sets256→512。
原有效Opt4结论保持。R0 elaboration失败；r1 marker失效的测量已排除，旧证据均保留，见[marker RCA](roi_marker_rca.md)。
''')

rows = ['|Exact-ROI counter|A|B|A−B|', '|---|---:|---:|---:|']
rows += [f'|{key}|{value:,}|UNAVAILABLE|UNAVAILABLE|' for key, value in c.items()]
latencies = []
for label, n, total in [('load detect→accept', 'detect_alloc_samples', 'detect_alloc_sum'),
                       ('MSHR alloc→refill', 'alloc_refill_samples', 'alloc_refill_sum'),
                       ('load detect→data', 'detect_data_samples', 'detect_data_sum')]:
    latencies.append(f"{label}: A samples={c[n]}, mean={c[total]/c[n]:.4f} cycles；B unavailable")
md('causal_counter_comparison.md', '# 计数对照：没有有效paired delta\n\n' + '\n'.join(rows) +
   '\n\nA MSHR occupancy bins0–6：`' + json.dumps(a['causal']['mshr_occupancy_histogram']) + '`；sum=1,707,863。\n\n' +
   '\n\n'.join(latencies) + '\n\n三类是completion-in-ROI不同cohort，不能相乘/相减推算收益。\n\n' +
   'B aborted，缺少final summaries，不以0或shadow1,301补齐。Native首次失败lookup与legacy首次lookup的定义不同，详见causal_counter_schema.md。')

md('observer_validation.md', f'''# Observer / correctness 独立状态

|验证项|A|B|
|---|---|---|
|软件完成/benchmark|PASS，verified1/checksum43439728|FAIL，未完成，exit1|
|运行时断言|无|checker3 ownership assert24|
|ROI marker|712114/2419977，均lookup_valid1|只有start698301，lookup_valid1；stop缺失|
|Native causal/ROI/occupancy/hist/overlap守恒|PASS|UNAVAILABLE，无final JSON|
|Integrity ledger|全程PASS：406=391completed+12coalesced+3discarded|已记录prefix PASS：149=53completed+94discarded+2invalidated；非完整run认证|
|Protocol/mandatory capture/end accounting|PASS|INCOMPLETE，abort后无producer footer；非证明每个所报footer缺失都是独立RTL bug|
|L1 S0|PASS|UNVALIDATED，无final summary|
|L2 read-consistent snapshot/key/S0|PASS，snapshot_errors0/key_errors0|UNVALIDATED，无final summary；没有观察到L2 mismatch报警|
|STOP40–45|PASS|UNAVAILABLE，未到STOP|

A L2 read snapshots42,225；latest accepted镜像的temporal disagreements40,220是已区分的诊断，
read-consistent snapshot独立比较PASS，不能把它当RTL损坏。
本次B失败来自已有ownership watchdog，不能以放宽observer或关闭断言消除。
完整的B功能数据正确性和observer都没有闭合，禁止性能解读。

实际执行参数/二进制hash、source/tool/software seal、生成配置和native source copy检查PASS。
validation中`same_l2_geometry=false`是B缺少动态最终geometry，**不是**生成的L2配置变了；
generated_configuration_audit证明两组L2 JSON和clock摘要byte-identical。

详见[runtime失败](r2_B_correctness_failure.md)与[结构化gate](validation_result.json)。
''')

md('performance_attribution.md', f'''# Performance attribution：禁止解释失败对照

**{status}**

{table}

A 的miss-associated ROB-head wait139,694，head∩busy139,500，busy313,150/full0，
表明本轮instrumentation能观测到miss关联head waiting；这并不证明减少miss会减少这些周期。
B未完成，无法建立miss→MSHR/replay→ROB critical→ROI的paired delta。
也无法判断“miss显著下降而critical counters不变”、或“收益主要由其它反馈产生”。

禁止用B失败前缀与完整A比较；禁止用历史shadow64K miss1301代替B实际miss；
禁止把A的exposures加成剩余slowdown，或用miss×mean latency估收益。
A的四项互斥分区只作A内部会计守恒：`{json.dumps(a['roi_partition'])}`。
没有B分区，不存在净收益分解。

L1 miss reduction → critical-path cycle reduction：**NOT YET PROVEN**。
''')

md('opt5_decision.md', f'''# Opt5 判决

**{status}**

`NEXT_OPTIMIZATION = NONE_JUSTIFIED`

B runtime correctness失败且测量不完整，不能套用5k/17k/几十k/85k性能档位。
本判决既不是REJECT，也不是WEAK/CANDIDATE/DIRECTION_JUSTIFIED。
保持有效Opt4、SVB16和此前不扩大SVB/不以promotion为主方向的结论。

下一步：先针对checker3 seq67的trap/start/return、cleanup和CANCEL handoff→BOOM release
关闭correctness问题；本轮没有实施超出geometry的功能修复，也未启动其它优化实验。
正确性闭合后，才评估重新封存并执行完整同instrumentation A/B。
面积、能耗、物理时序仍未测量，64KiB并未命名为正式Opt5。

因果问题：**NOT YET PROVEN**。A alone的head-miss关联不等于干预收益证据。
''')

questions = ['Run A ROI cycles', 'Run B ROI cycles', '净改善cycles', '占A ROI百分比',
 'L1 miss变化', 'miss reduction百分比', 'MSHR allocation', 'MSHR full cycles',
 'MSHR busy cycles', 'MSHR occupancy distribution', 'load replay count / cycles',
 'load miss latency', 'ROB-head miss wait', 'ROB-head与MSHR交集', 'scheduler unavailable',
 'scheduler与MSHR交集', 'ROI改善的定量解释', 'miss下降但critical counters不变？',
 '是否可能有其他performance来源？', 'observer / correctness']
na = 'UNAVAILABLE；B未完成，不能计算paired delta'
answers = [f"{a['roi_cycles']:,}，精确软件区间[712114,2419977)",
 'UNAVAILABLE；start698301有效，但无stop，不能把assertion tick当终点', na, na,
 f"A legacy首次lookup tag misses3272；native load{c['load_tag_miss_requests']} / store{c['store_tag_miss_requests']}；B unavailable。两总体定义不同。",
 na, f"A primary{c['mshr_primary_allocations']} / upgrade{c['mshr_upgrade_allocations']} / merge{c['mshr_merges']}；B unavailable",
 f"A {c['mshr_full_cycles']}；B unavailable", f"A {c['mshr_busy_cycles']}；B unavailable",
 'A bins0–6 '+str(a['causal']['mshr_occupancy_histogram'])+'；B unavailable',
 f"A RPQ {c['load_rpq_replays']} events/{c['load_rpq_replay_cycles']} active cycles，nack retry {c['load_nack_retries']} events/{c['load_nack_retry_cycles']} cycles；B unavailable",
 '；'.join(latencies), f"A {c['ROB_HEAD_WAITING_ON_LOAD_MISS_CYCLES']}；B unavailable",
 f"A head∩busy {c['ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_BUSY_CYCLES']} / full {c['ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_FULL_CYCLES']}；B unavailable",
 f"A {c['scheduler_unavailable_cycles']}；B unavailable。完整计数不是旧稀疏prefix的267087。",
 f"A scheduler∩busy {c['SCHEDULER_UNAVAILABLE_AND_MSHR_BUSY_CYCLES']} / full {c['SCHEDULER_UNAVAILABLE_AND_MSHR_FULL_CYCLES']}，head∩scheduler {c['ROB_HEAD_LOAD_BLOCK_AND_SCHEDULER_UNAVAILABLE_CYCLES']}；B unavailable",
 '不能定量解释：没有B完整ROI/counters，不能进行exposure加法或miss×penalty推算',
 '无法判断：B实际miss和critical counters都缺失，不使用shadow1301替代',
 '无法判断：没有有效paired performance。Geometry的warmup/时序反馈存在可能性，但未测出净效应',
 'A全部PASS；B runtime assertion FAIL，完整observer/ROI/counters未验证；已记录prefix完整性不是整次run认证']
assert len(questions) == len(answers) == 20
md('answers_20.md', '# 20项结果回答\n\n本表精确说明已测A与不可用B；不填零，不比较不等长prefix。\n\n' +
   '\n\n'.join(f'{i}. **{q}**：{v}' for i, (q, v) in enumerate(zip(questions, answers), 1)))

decision = dict(status=status, next_optimization='NONE_JUSTIFIED', causality_answer='NOT YET PROVEN',
 baseline_roi=a['roi_cycles'], l1_64k_roi=None, delta_cycles=None, delta_percent=None,
 miss_delta=None, mshr_busy_delta=None, mshr_full_delta=None, replay_delta=None,
 head_wait_delta=None, scheduler_overlap_delta=None, formal_opt5_implemented=False,
 reason='B checker3 ownership watchdog assertion before software ROI stop and final counters',
 next_action='Close checker3 sequence67 trap/start/return cleanup and CANCEL handoff correctness before any new paired performance experiment',
 baseline_result='baseline_result.json', failed_probe_result='l1_64k_2way_result.json',
 failure_evidence='r2_B_failure_evidence.json', source_script_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())
(root / 'inconclusive_decision.json').write_text(json.dumps(decision, indent=2) + '\n')
print(json.dumps(decision, indent=2))
