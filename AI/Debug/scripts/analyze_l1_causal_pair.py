#!/usr/bin/env python3
"""Analyze paired native causal counters; never estimates ROI from miss counts."""
import argparse
import hashlib
import json
from pathlib import Path

def read(p):return json.loads(p.read_text())
def dump(p,o):p.write_text(json.dumps(o,indent=2,sort_keys=True)+'\n')
def md(p,s):p.write_text(s.strip()+'\n')

def arm(revision,name):
    manifests=sorted((revision/'arms'/name/'runs').glob('*/run_manifest.json'))
    if len(manifests)!=1:raise ValueError(f'{name}: expected exactly one run in sealed revision, got {len(manifests)}')
    manifest=read(manifests[0]);run=manifests[0].parent
    summary=read(run/'analysis/summary.json')
    cache_path=run/'cache_opportunity.jsonl'
    raw=[json.loads(line) for line in cache_path.read_text().splitlines()] if cache_path.exists() else []
    l1=next((x for x in raw if x['level']==1),{});l2=next((x for x in raw if x['level']==2),{})
    roi_path=run/'roi.json'
    roi=read(roi_path) if roi_path.exists() else {};causal=l1.get('causal',{})
    boundaries=all(type(roi.get(k)) is int for k in ['start_cycle','stop_cycle'])
    roi_cycles=roi['stop_cycle']-roi['start_cycle'] if boundaries else None
    gates={
      'elaboration_rtl':manifest.get('hardware_generation')=='PASS',
      'verilator_build':manifest.get('verilator_build')=='PASS',
      'simulation':manifest.get('simulation')=='COMPLETED' and manifest.get('exit_status')==0,
      'functional':summary.get('correctness',{}).get('status')=='PASS' and summary.get('performance_valid') is True,
      'benchmark':summary.get('benchmark_result')=={'verified':1,'checksum':43439728},
      'integrity':summary.get('integrity',{}).get('status')=='PASS',
      'protocol':summary.get('protocol',{}).get('status')=='PASS',
      'ordering':summary.get('data_ordering',{}).get('status')=='PASS',
      'capture':summary.get('capture_evidence',{}).get('status')=='PASS',
      'bounded_stop_counters':summary.get('remaining_observation',{}).get('status')=='PASS',
      'complete_cache_summaries':bool(l1) and bool(l2),
      'completed_software_roi':boundaries and roi_cycles>0,
      'l1_s0':l1.get('geometry_decision_eligible') is True,
      'l2_snapshot':l2.get('s0_replay_complete') is True and l2.get('snapshot_errors')==0 and l2.get('lookup_key_errors')==0,
      'l2_s0':l2.get('geometry_decision_eligible') is True,
      'causal':causal.get('status')=='PASS',
      'exact_roi':boundaries and causal.get('roi_start')==roi['start_cycle'] and causal.get('roi_stop')==roi['stop_cycle'],
      'roi_marker_records':(boundaries and causal.get('roi_marker_events')==2 and causal.get('roi_snapshot_lookup_errors')==0 and
        causal.get('roi_marker_requested_cycles')==[roi['start_cycle'],roi['stop_cycle']] and
        causal.get('roi_marker_snapshot_found')==[1,1] and
        len(causal.get('roi_marker_observed_cycles',[]))==2 and
        all(0<=observed-requested<64 for observed,requested in zip(causal.get('roi_marker_observed_cycles',[]),causal.get('roi_marker_requested_cycles',[])))),
      'roi_accounting':boundaries and causal.get('counts',{}).get('sample_cycles')==roi_cycles==summary.get('opt4_roi_cycles'),
      'geometry':tuple(l1.get(k) for k in ['sets','ways','block_bytes','mshrs'])==((256 if name=='A' else 512),2,64,6),
    }
    counts=causal.get('counts',{})
    if gates['causal']:
      n=counts['sample_cycles'];h=counts['ROB_HEAD_WAITING_ON_LOAD_MISS_CYCLES']
      s=counts['scheduler_unavailable_cycles'];both=counts['ROB_HEAD_LOAD_BLOCK_AND_SCHEDULER_UNAVAILABLE_CYCLES']
      partition=dict(head_miss_only=h-both,scheduler_only=s-both,both=both,neither=n-h-s+both)
      gates['partition']=all(x>=0 for x in partition.values()) and sum(partition.values())==n
      gates['occupancy']=sum(causal['mshr_occupancy_histogram'])==n
      gates['overlaps']=(0<=both<=min(h,s) and counts['mshr_full_cycles']<=counts['mshr_busy_cycles']<=n and
        counts['ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_FULL_CYCLES']<=counts['ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_BUSY_CYCLES'] and
        counts['SCHEDULER_UNAVAILABLE_AND_MSHR_FULL_CYCLES']<=counts['SCHEDULER_UNAVAILABLE_AND_MSHR_BUSY_CYCLES'] and
        counts['ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_BUSY_CYCLES']<=min(h,counts['mshr_busy_cycles']) and
        counts['ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_FULL_CYCLES']<=min(h,counts['mshr_full_cycles']) and
        counts['SCHEDULER_UNAVAILABLE_AND_MSHR_BUSY_CYCLES']<=min(s,counts['mshr_busy_cycles']) and
        counts['SCHEDULER_UNAVAILABLE_AND_MSHR_FULL_CYCLES']<=min(s,counts['mshr_full_cycles']))
      gates['latency_histograms']=all(sum(hist)==counts[key] for hist,key in zip(causal['latency_histograms'],
         ['detect_alloc_samples','alloc_refill_samples','detect_data_samples']))
    else:partition=None
    return dict(arm=name,run=str(run),manifest=str(manifests[0]),roi=roi,
      roi_cycles=roi.get('roi_cycles',roi_cycles),
      gates=gates,valid=all(gates.values()),source=manifest['source'],software=manifest['software'],
      actual_l1=l1.get('actual'),causal=causal,roi_partition=partition,
      l1_s0_misses=l1['models'][0]['stats']['miss'] if l1.get('models') else None,
      actual_l2_geometry={k:l2.get(k) for k in ['sets','ways','block_bytes','mshrs']},
      l2_observer={k:l2.get(k) for k in ['actual','s0_replay_complete','read_consistent_snapshots','snapshot_errors',
        'lookup_key_errors','temporal_mirror_disagreements','geometry_decision_eligible']},
      remaining_stop_counters=summary.get('remaining_observation'),
      integrity={k:summary.get('integrity',{}).get(k) for k in ['status','allocations','completions','terminal_counts','duplicate_beats']},
      runtime={k:manifest.get(k) for k in ['simulation','exit_status','result','phase']},
      missing_evidence=[label for label,present in [('L1 final cache summary',bool(l1)),('L2 final cache summary',bool(l2)),
        ('completed software ROI',boundaries),('native causal final counters',bool(causal))] if not present])

def analyze(root,revision):
    a,b=arm(revision,'A'),arm(revision,'B')
    seal=read(revision/'source_seal.json')
    paired={
      'same_sealed_source':a['source']['paired_source_fingerprint']==b['source']['paired_source_fingerprint']==seal['paired_source_fingerprint'],
      'same_hardware_hashes':a['source']['hardware_sha256']==b['source']['hardware_sha256']==seal['hardware_sha256'],
      'same_tools':a['source']['tool_sha256']==b['source']['tool_sha256']==seal['tool_sha256'],
      'same_software':a['software']==b['software'],
      'software_matches_seal':all(a['software'][k]==v for k,v in seal['software'].items()),
      'same_l2_geometry':a['actual_l2_geometry']==b['actual_l2_geometry'],
      'expected_configs':(a['source']['config'],b['source']['config'])==('L1Causal32Config','L1Causal64Config'),
      'single_geometry_variable':[(a['source'][k],b['source'][k]) for k in ['l1_ways','l1_block_bytes','l1_mshrs','n_svb_entries']]==[(2,2),(64,64),(6,6),(16,16)],
    }
    execution=read(root/'simulation_execution_provenance.json')
    generated=read(root/'generated_configuration_audit.json')
    resources=read(root/'native_resource_copy_validation.json')
    paired['same_actual_execution_arguments']=(execution['status']=='PASS' and execution['argv_A'][1:]==execution['argv_B'][1:])
    paired['actual_executable_configs']=(Path(execution['argv_A'][0]).name,Path(execution['argv_B'][0]).name)==('simulator-chipyard-L1Causal32Config','simulator-chipyard-L1Causal64Config')
    paired['generated_configuration_audit']=generated['status']=='PASS'
    paired['native_resource_copy_audit']=resources['status']=='PASS'
    valid=a['valid'] and b['valid'] and all(paired.values())
    dump(root/'baseline_result.json',a);dump(root/'l1_64k_2way_result.json',b)
    validation=dict(status='PASS' if valid else 'FAIL',arm_A=a['gates'],arm_B=b['gates'],paired=paired,
      source_seal=str(revision/'source_seal.json'),simulations_executed=True,
      default_opt4_reference_preserved=True)
    dump(root/'validation_result.json',validation)
    manifest=dict(experiment='L1-Causal-1',revision=str(revision),source_fingerprint=seal['paired_source_fingerprint'],
      arm_A_manifest=a['manifest'],arm_B_manifest=b['manifest'],paired=paired,
      software=a['software'],seed=seal['seed'],max_cycles=seal['max_cycles'],verilator_threads=seal['verilator_threads'])
    manifest['actual_execution_provenance']=execution
    manifest['generated_configuration_audit']=str(root/'generated_configuration_audit.json')
    manifest['native_resource_copy_audit']=str(root/'native_resource_copy_validation.json')
    if (root/'r1_measurement_failure.json').exists():
      manifest['excluded_revision_evidence']=str(root/'r1_measurement_failure.json')
    dump(root/'run_manifest.json',manifest)
    if not valid:
      decision='INCONCLUSIVE_DUE_TO_CORRECTNESS_OR_MEASUREMENT'
      failed={name:{k:v for k,v in gates.items() if not v} for name,gates in [('A',a['gates']),('B',b['gates']),('pair',paired)]}
      md(root/'README.md',f'# L1-Causal-1\n\n{decision}\n\nNEXT_OPTIMIZATION = NONE_JUSTIFIED\n\nA ROI={a["roi_cycles"]}；B ROI={b["roi_cycles"]}。没有有效paired delta。\n\n验证失败项：`{json.dumps(failed,ensure_ascii=False)}`。不解释未经闭合的performance。\n\n详见validation_result.json。')
      for name in ['observer_validation.md','performance_attribution.md','opt5_decision.md','causal_counter_comparison.md']:
        md(root/name,f'# {decision}\n\nGate failures: `{json.dumps(failed)}`\n\nNEXT_OPTIMIZATION = NONE_JUSTIFIED\n\nNOT YET PROVEN')
      questions=['Run A ROI cycles','Run B ROI cycles','净改善cycles','占A ROI百分比','L1 miss变化','miss reduction百分比',
        'MSHR allocation','MSHR full cycles','MSHR busy cycles','MSHR occupancy distribution','load replay count / cycles',
        'load miss latency','ROB-head miss wait','ROB-head与MSHR交集','scheduler unavailable','scheduler与MSHR交集',
        'ROI改善的定量解释','miss下降但critical counters不变？','是否可能有其他performance来源？','observer / correctness']
      answers=[str(a['roi_cycles']),str(b['roi_cycles']) if b['roi_cycles'] is not None else 'UNAVAILABLE：未完成软件ROI']+\
        ['UNAVAILABLE：correctness/measurement gate未通过，禁止计算或解释paired performance']*17+\
        [f"A valid={a['valid']}；B valid={b['valid']}；详见validation_result.json。"]
      md(root/'answers_20.md','# 20项结果回答\n\n'+'\n\n'.join(
        f'{i}. **{q}**：{value}' for i,(q,value) in enumerate(zip(questions,answers),1)))
      return dict(decision=decision,causality_answer='NOT YET PROVEN',failed=failed)
    ac,bc=a['causal']['counts'],b['causal']['counts']
    delta={k:ac[k]-bc[k] for k in ac};gain=a['roi_cycles']-b['roi_cycles'];pct=100*gain/a['roi_cycles']
    miss=a['actual_l1']['miss']-b['actual_l1']['miss'];miss_pct=100*miss/max(a['actual_l1']['miss'],1)
    roi_miss_a=ac['load_tag_miss_requests']+ac['store_tag_miss_requests']
    roi_miss_b=bc['load_tag_miss_requests']+bc['store_tag_miss_requests']
    roi_miss_delta=roi_miss_a-roi_miss_b
    hkey='ROB_HEAD_WAITING_ON_LOAD_MISS_CYCLES'
    chain=(gain>0 and miss>0 and delta['load_tag_miss_requests']>0 and delta[hkey]>0 and delta['ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_BUSY_CYCLES']>0 and
       (delta['mshr_primary_allocations']>0 or delta['mshr_busy_cycles']>0 or delta['load_rpq_replays']>0))
    if gain<5000:decision='REJECT_L1_CAPACITY_AS_OPT5'
    elif gain<max(17000,a['roi_cycles']*.01) or not chain:decision='WEAK_L1_CAPACITY_SIGNAL'
    elif gain>=80000 and chain and delta[hkey]>=gain*.5:decision='OPT5_DIRECTION_JUSTIFIED'
    elif gain>=30000 and delta[hkey]>=gain*.5:decision='STRONG_OPT5_CANDIDATE'
    else:decision='L1_CAPACITY_OPT5_CANDIDATE'
    # A candidate is not a selected production implementation; costs were not measured.
    next_opt='NONE_JUSTIFIED'
    answer='YES' if chain else 'NO' if miss>0 and abs(delta[hkey])<500 and abs(gain)<5000 else 'NOT YET PROVEN'
    rows=['|Counter（正delta=A−B）|A|B|Delta|','|---|---:|---:|---:|']
    for k in ac:rows.append(f'|{k}|{ac[k]:,}|{bc[k]:,}|{delta[k]:+,}|')
    md(root/'causal_counter_comparison.md','# Exact software ROI causal counters\n\n'+'\n'.join(rows)+'\n\nMSHR occupancy A/B：\n\n'+json.dumps([a['causal']['mshr_occupancy_histogram'],b['causal']['mshr_occupancy_histogram']])+
      '\n\nRPQ replay、nack retry、raw S2 miss attempts、unique request misses分别计数，不能混加。nack reason位可重叠。\n'
      '\nNative tag/permission类在每个queue token的首次失败lookup确定；legacy actual.miss只分类每个token的首次lookup。先hit后miss的重试可进入前者而不进入后者。两者窗口和请求分类也不同；不要求其总数相等，详见causal_counter_schema.md。\n')
    md(root/'observer_validation.md',f'''# Observer / integrity独立验证

两组functional、benchmark、lifecycle、protocol、ordering、mandatory capture、STOP40–45、
L1/L2 S0、L2 snapshot/key审计、native causal counters、软件ROI边界与守恒全部PASS。

L2 A：`{json.dumps(a['l2_observer'])}`

L2 B：`{json.dumps(b['l2_observer'])}`

L2 latest-accepted mirror disagreement仅为诊断；S0采用delayed read snapshot独立tag比较，不能将该诊断数当RTL数据错误。
原Opt4 ROI有效性保持；两组新run才是本次paired performance证据。
''')
    partitions={k:a['roi_partition'][k]-b['roi_partition'][k] for k in a['roi_partition']}
    latency=[]
    for label,n,s in [('detect→alloc','detect_alloc_samples','detect_alloc_sum'),('alloc→refill','alloc_refill_samples','alloc_refill_sum'),('detect→data','detect_data_samples','detect_data_sum')]:
      latency.append(dict(metric=label,A_samples=ac[n],B_samples=bc[n],
        A_mean=ac[s]/ac[n] if ac[n] else None,B_mean=bc[s]/bc[n] if bc[n] else None))
    def cc(k):
      return f"{ac[k]:,}→{bc[k]:,}（A−B {delta[k]:+,}）"
    answers=[
      ('Run A ROI cycles',f"{a['roi_cycles']:,}"),
      ('Run B ROI cycles',f"{b['roi_cycles']:,}"),
      ('净改善cycles',f"{gain:+,}"),
      ('占A ROI百分比',f"{pct:+.4f}%"),
      ('L1 miss变化',f"exact软件ROI tag-miss requests {roi_miss_a:,}→{roi_miss_b:,}；load "+cc('load_tag_miss_requests')+'；store '+cc('store_tag_miss_requests')+f"；宽traffic窗口 actual {a['actual_l1']['miss']:,}→{b['actual_l1']['miss']:,}"),
      ('miss reduction百分比',f"exact软件ROI {100*roi_miss_delta/max(roi_miss_a,1):.4f}%；宽traffic窗口 {miss_pct:.4f}%"),
      ('MSHR allocation',cc('mshr_primary_allocations')+'；upgrade '+cc('mshr_upgrade_allocations')+'；merge '+cc('mshr_merges')),
      ('MSHR full cycles',cc('mshr_full_cycles')),
      ('MSHR busy cycles',cc('mshr_busy_cycles')),
      ('MSHR occupancy distribution',f"bins0–6 A={a['causal']['mshr_occupancy_histogram']}；B={b['causal']['mshr_occupancy_histogram']}；每组sum=ROI"),
      ('load replay count / cycles','RPQ events '+cc('load_rpq_replays')+'；active cycles '+cc('load_rpq_replay_cycles')+'；nack retry '+cc('load_nack_retries')+' / '+cc('load_nack_retry_cycles')),
      ('load miss latency',json.dumps(latency,ensure_ascii=False)+'；completion-in-ROI cohort，不乘miss数；raw hist见各arm causal.latency_histograms'),
      ('ROB-head miss wait',cc(hkey)),
      ('ROB-head与MSHR交集','busy '+cc('ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_BUSY_CYCLES')+'；full '+cc('ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_FULL_CYCLES')),
      ('scheduler unavailable',cc('scheduler_unavailable_cycles')),
      ('scheduler与MSHR交集','busy '+cc('SCHEDULER_UNAVAILABLE_AND_MSHR_BUSY_CYCLES')+'；full '+cc('SCHEDULER_UNAVAILABLE_AND_MSHR_FULL_CYCLES')+'；head∩scheduler '+cc('ROB_HEAD_LOAD_BLOCK_AND_SCHEDULER_UNAVAILABLE_CYCLES')),
      ('ROI改善的定量解释',f"head wait delta {delta[hkey]:+,}，ROI delta {gain:+,}；互斥ROI分区delta {partitions} 精确合计{sum(partitions.values()):+,}。这是会计闭合；事件链/同cycle交集支持因果机制，不把各暴露delta相加称可恢复收益。"),
      ('miss下降但critical counters不变？',f"本对照tag-miss delta {roi_miss_delta:+,}，head-miss wait delta {delta[hkey]:+,}，head∩busy delta {delta['ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_BUSY_CYCLES']:+,}；链条判定{answer}，不得以miss下降单独判断。"),
      ('是否可能有其他performance来源？','单变量geometry干预的净ROI效应可归于该干预；其中命中/仲裁、checker/package调度、计算与存储重叠的反馈不能逐cycle分离。neither分区包含未识别活动，不能冒充纯计算，也不证明所有收益来自MSHR/replay。'),
      ('observer / correctness','两组功能、checksum、integrity、protocol、ordering、capture、STOP40–45、L1/L2 S0、L2 snapshot/key和causal measurement gates全部PASS。'),
    ]
    md(root/'answers_20.md','# 20项结果回答\n\n正delta均为A−B；cycle counters均为exact软件ROI，特别标明的legacy cache actual/S0除外。\n\n'+
       '\n\n'.join(f"{i}. **{q}**：{v}" for i,(q,v) in enumerate(answers,1))+\
       '\n\n返回仍在critical head：'+cc('miss_returns_still_head')+'；完成的miss曾阻塞head：'+cc('completed_misses_ever_head')+'；其head episode累计cycles：'+cc('completed_miss_head_episode_cycles')+'。这些是completion-in-ROI cohort；不能替代全ROI逐cycle head wait。')
    md(root/'performance_attribution.md',f'''# Paired performance attribution

A ROI **{a['roi_cycles']:,}**；B ROI **{b['roi_cycles']:,}**；A−B **{gain:+,} cycles / {pct:+.4f}%**。
原cache observer的traffic START→STOP窗口，实际L1 unique tag misses **{a['actual_l1']['miss']:,}→{b['actual_l1']['miss']:,}**，delta{miss:+,}/{miss_pct:.4f}%。
这个窗口略宽于软件ROI，不与下方exact-ROI counts混算。软件ROI内native unique tag miss requests
**{roi_miss_a:,}→{roi_miss_b:,}**，delta **{roi_miss_delta:+,}**，其中load **{ac['load_tag_miss_requests']:,}→{bc['load_tag_miss_requests']:,}**、store **{ac['store_tag_miss_requests']:,}→{bc['store_tag_miss_requests']:,}**。
load/store分项来自native token counters，定义与shadow miss estimate分别列示，绝不以shadow1,301充作B实测值。
Native在首次失败lookup分类tag/permission miss；legacy actual仅分类token的首次lookup。
先hit后miss的请求可能只进入native miss总体，加上窗口和queue分类差别，两者总数不要求一致；不能把差值全归因于窗口。

MSHR primary delta{delta['mshr_primary_allocations']:+,}、upgrade{delta['mshr_upgrade_allocations']:+,}、merge{delta['mshr_merges']:+,}；
busy{delta['mshr_busy_cycles']:+,}、full{delta['mshr_full_cycles']:+,} cycles。
load RPQ replay{delta['load_rpq_replays']:+,} events/{delta['load_rpq_replay_cycles']:+,} cycles；
nack retry{delta['load_nack_retries']:+,} events/{delta['load_nack_retry_cycles']:+,} cycles。
ROB-head miss wait delta **{delta[hkey]:+,}**；head∩MSHRbusy **{delta['ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_BUSY_CYCLES']:+,}**；
scheduler∩MSHRbusy **{delta['SCHEDULER_UNAVAILABLE_AND_MSHR_BUSY_CYCLES']:+,}**。

## 互斥ROI分区（非独立可恢复收益）

|谓词分区|A|B|A−B|
|---|---:|---:|---:|
'''+ '\n'.join(f"|{k}|{a['roi_partition'][k]:,}|{b['roi_partition'][k]:,}|{partitions[k]:+,}|" for k in partitions)+f'''

每组HeadMiss/Scheduler实测同cycle交集用于inclusion-exclusion，四项互斥并精确守恒ROI；
分区delta总和={sum(partitions.values()):+,}=ROI delta。这是数值会计闭合，不声称每项都是可独立删除的反事实时间。
paired干预只有geometry，净ROI变化可归于该干预的整体时序反馈；具体miss/MSHR/replay路径支持程度由上述实测交集判断。
其他control/gate/计算/并行路径仍可抵消或放大直接head-load效应，不能把all-MSHR busy当ROB stall。

## Latency cohort

`{json.dumps(latency)}`

三种hist按末事件在ROI的cohort统计，允许ROI前开始；未完成请求censored。
不能把不同cohort的均值相减当总ROI归因，不能用miss delta×mean penalty估计收益。

L1 miss reduction→critical-path cycle reduction：**{answer}**。
''')
    decision_obj=dict(status=decision,next_optimization=next_opt,causality_answer=answer,
      baseline_roi=a['roi_cycles'],l1_64k_roi=b['roi_cycles'],delta_cycles=gain,delta_percent=pct,
      actual_miss_delta=miss,actual_miss_reduction_percent=miss_pct,counter_delta=delta,
      exact_roi_tag_misses_A=roi_miss_a,exact_roi_tag_misses_B=roi_miss_b,exact_roi_tag_miss_delta=roi_miss_delta,
      roi_partition_delta=partitions,latency_comparison=latency,observer_and_correctness='PASS',
      formal_opt5_implemented=False)
    decision_obj['next_action']=('Compare L1 capacity/associativity/MSHR/replay cost-performance before selecting a production change'
      if decision in ['L1_CAPACITY_OPT5_CANDIDATE','STRONG_OPT5_CANDIDATE','OPT5_DIRECTION_JUSTIFIED']
      else 'Review measured MSHR/replay/LSU/scheduler critical-path evidence; no automatic policy change')
    decision_obj['analysis_script_sha256']=hashlib.sha256(Path(__file__).read_bytes()).hexdigest()
    dump(root/'comparison.json',decision_obj)
    md(root/'opt5_decision.md',f'''# Opt5判决

**{decision}**

`NEXT_OPTIMIZATION = {next_opt}`

paired ROI delta{gain:+,}/{pct:+.4f}%；miss delta{miss:+,}；head miss wait delta{delta[hkey]:+,}。
因果链判定{answer}。全部observer/integrity gate PASS。
17k/30k/80k分档分别对应约1%/几十k/接近85k参考门槛；不是统计显著性阈值。
若判为candidate/direction，也没有自动把64KiB命名成正式Opt5：仍须评估data SRAM×2、line metadata×2、
访问能耗与物理时序；本实验没有综合/PPA。若reject/weak，则保留SVB16，利用精确counter转向MSHR/replay/LSU/scheduler机制审查，
不自动增加MSHR、不改policy、不开始额外geometry sweep。
''')
    md(root/'README.md',f'''# L1-Causal-1

**{decision}**

`NEXT_OPTIMIZATION = {next_opt}`

|配置|ROI cycles|实际L1 tag misses|ROB-head miss wait|
|---|---:|---:|---:|
|A Opt4/SVB16 32KiB/2-way|{a['roi_cycles']:,}|{a['actual_l1']['miss']:,}|{ac[hkey]:,}|
|B 同instrumentation 64KiB/2-way|{b['roi_cycles']:,}|{b['actual_l1']['miss']:,}|{bc[hkey]:,}|

净改善 **{gain:+,} cycles / {pct:+.4f}%**。observer/correctness **PASS**。
MSHR busy/full delta{delta['mshr_busy_cycles']:+,}/{delta['mshr_full_cycles']:+,}；
RPQ replay delta{delta['load_rpq_replays']:+,}；scheduler∩MSHRbusy delta{delta['SCHEDULER_UNAVAILABLE_AND_MSHR_BUSY_CYCLES']:+,}。
L1 miss reduction转化为critical-path cycle reduction：**{answer}**。

[设计](experiment_design.md) · [改动](code_changes.md) · [counter比较](causal_counter_comparison.md) ·
[observer验证](observer_validation.md) · [归因](performance_attribution.md) · [判决](opt5_decision.md) ·
[validation](validation_result.json) · [manifest](run_manifest.json)

本结论仅使用`{revision.relative_to(root)}/arms/`的paired runs与build。
R0 elaboration失败且未仿真；r1 A功能/ROI通过但causal marker测量失效，r1 B随后中止。
前像、旧seal/build/run和provenance均保留，详见[ROI marker RCA](roi_marker_rca.md)，不混用旧revision计数。
本次未实施MSHR/replay/scheduler/promotion/L2性能优化；A/B仅BOOM L1D nSets256→512。
''')
    return decision_obj

def main():
    ap=argparse.ArgumentParser();ap.add_argument('root',type=Path);ap.add_argument('--revision',type=Path,required=True);a=ap.parse_args()
    result=analyze(a.root.resolve(),a.revision.resolve())
    print(json.dumps({k:v for k,v in result.items() if not isinstance(v,(dict,list))},indent=2))

if __name__=='__main__':main()
