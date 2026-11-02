#!/usr/bin/env python3
"""Offline fixed-trace Opt5 opportunity audit. Never invokes a hardware tool.

Inputs are the named completed A/B raw evidence and separately recovered B view.
The report text targets this evidence pair; other run identities fail closed.
Missing event histories stay null. No event-count times penalty prediction is used.
"""
import argparse
from fractions import Fraction
import hashlib
import importlib.util
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[3]
DEFAULT_PREVIOUS = ROOT / 'AI/TMP/l1_one_shot_postanalysis_20261101_095815'
HEAD = 'ROB_HEAD_WAITING_ON_LOAD_MISS_CYCLES'
HEAD_BUSY = 'ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_BUSY_CYCLES'
HEAD_SCHED = 'ROB_HEAD_LOAD_BLOCK_AND_SCHEDULER_UNAVAILABLE_CYCLES'
POLICY = ('Fixed observed trace only: deleting marked direct head-load waiting; '
          'not a bound on timing feedback, dependency propagation or a new execution.')


def read(path):
    return json.loads(Path(path).read_text())


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for block in iter(lambda: f.read(1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def require(ok, message):
    if not ok:
        raise ValueError(message)


def target_math(native, current, baseline, ratio=Fraction(3, 2)):
    exact = native * ratio
    # Strict inequality; works whether the product is integral or fractional.
    max_roi = (exact.numerator - 1) // exact.denominator
    return dict(native_roi=native, target_slowdown=float(ratio),
                exact_threshold=str(exact), max_integer_roi_below_target=max_roi,
                user_exclusive_roi_threshold=max_roi + 1,
                current_b_roi=current, baseline_roi=baseline,
                approximate_gap=current - (max_roi + 1),
                minimum_integer_saving=current - max_roi,
                total_minimum_integer_saving=baseline - max_roi,
                current_slowdown=current / native)


def overlap_bounds(a, b, total):
    require(0 <= a <= total and 0 <= b <= total, 'invalid marginal exposure')
    return [max(0, a + b - total), min(a, b)]


def traffic_roi_bounds(exposure, traffic, roi):
    ta, tb = traffic
    ra, rb = roi
    require(ta <= ra < rb <= tb, 'software ROI must be contained in traffic window')
    require(0 <= exposure <= tb - ta, 'invalid traffic exposure')
    outside = tb - ta - (rb - ra)
    return [max(0, exposure - outside), min(exposure, rb - ra)]


def attempt_amplification(attempts, first_detections, physical_ldq_entries):
    require(0 < first_detections <= attempts and physical_ldq_entries > 0,
            'invalid miss-attempt cohort')
    lo = first_detections
    hi = min(attempts, first_detections + physical_ldq_entries)
    return dict(attempts=attempts, first_detections_in_roi=first_detections,
                maximum_boundary_carry_in_tokens=physical_ldq_entries,
                affected_miss_token_count_bounds=[lo, hi],
                attempts_per_miss_token_bounds=[attempts / hi, attempts / lo],
                some_token_attempt_count_at_least=(attempts + hi - 1) // hi,
                assumptions=['stable functional token over LDQ lifetime',
                             'no observer-slot alias between different live LDQ entries',
                             'one first detection per token, tag/permission cases partition',
                             'at most physical LDQ size already detected at ROI entry'],
                metric='miss lookup attempts per affected miss token; NOT nack retry factor')


def retry_factor(events, affected=None):
    if not events:
        return dict(value=None, bounds=None, reason='empty cohort')
    if affected is None:
        return dict(value=None, bounds=[1, events],
                    reason='unique affected retry-token count was not exported')
    require(1 <= affected <= events, 'invalid affected cohort')
    return dict(value=events / affected, bounds=[events / affected] * 2)


def scheduler_unavailable(words):
    # SC7 packing: d[2] condition bits; d[3] low3=hart, upper bits=FSM.
    return words[3] >> 3 == 2 and not words[2] & (1 << 6)


def fixed_trace_envelopes(roi, head_miss, head_pending, native):
    require(0 <= head_miss <= head_pending <= roi, 'head exposures must be nested')
    return dict(scope=POLICY, head_miss_cycles=head_miss,
                all_head_load_pending_cycles=head_pending,
                additional_nonmiss_head_pending=head_pending - head_miss,
                # These are nested alternatives, never an additive budget.
                combined_upper_bound=head_pending,
                ideal_miss_deletion_roi=roi - head_miss,
                ideal_miss_deletion_slowdown=(roi - head_miss) / native,
                ideal_all_head_load_deletion_roi=roi - head_pending,
                ideal_all_head_load_deletion_slowdown=(roi - head_pending) / native)


def load_module(path, name):
    spec = importlib.util.spec_from_file_location(name, path)
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    return m


def audit_hashes(expected):
    failures = []
    for path, digest in expected.items():
        p = Path(path)
        if not p.is_absolute():
            p = ROOT / p
        if not p.is_file() or sha(p) != digest:
            failures.append(str(p))
    require(not failures, 'evidence/source digest mismatch: ' + str(failures))
    return len(expected)


SOURCE_RANGES = {
    'chipyard/generators/boom/src/main/scala/lsu/dcache.scala':
        [(451, 461), (772, 809), (848, 862), (889, 900), (1033, 1042),
         (1250, 1304), (1330, 1355), (1495, 1535), (2890, 2908),
         (3001, 3014), (4419, 4470)],
    'chipyard/generators/boom/src/main/scala/lsu/mshrs.scala':
        [(220, 240), (310, 315), (447, 477), (575, 604), (849, 866),
         (967, 983), (1074, 1093), (1136, 1143)],
    'chipyard/generators/boom/src/main/scala/lsu/lsu.scala':
        [(517, 526), (650, 672), (740, 760), (785, 815), (1230, 1239),
         (1684, 1697), (2499, 2515)],
    'chipyard/generators/rocket-chip/src/main/resources/csrc/cache_opportunity.cc':
        [(70, 82), (104, 183), (198, 217)],
    'chipyard/generators/boom/src/main/scala/common/config-mixins.scala': [(238, 283)],
    'chipyard/generators/boom/src/main/scala/common/parameters.scala': [(50, 58)],
}


def source_audit(generated):
    evidence = {}
    for rel, ranges in SOURCE_RANGES.items():
        path = ROOT / rel
        lines = path.read_text().splitlines()
        evidence[rel] = dict(sha256=sha(path), excerpts=[
            dict(start=a, end=b, lines=[f'{i}: {lines[i-1]}' for i in range(a, b+1)])
            for a, b in ranges])
    dcache = (ROOT / 'chipyard/generators/boom/src/main/scala/lsu/dcache.scala').read_text()
    mshr = (ROOT / 'chipyard/generators/boom/src/main/scala/lsu/mshrs.scala').read_text()
    lsu = (ROOT / 'chipyard/generators/boom/src/main/scala/lsu/lsu.scala').read_text()
    signatures = {
        'nack_miss_is_not_ready_predicate': 's2_valid(w) && !s2_hit(w) && !mshrs.io.req(w).ready' in dcache,
        'same_set_tag_secondary_readiness': 'sdq_rdy && Mux(idx_match(w), tag_match(w) && sec_rdy, pri_rdy)' in mshr,
        'secondary_drain_closed': '!drainAdmissionClosed' in mshr,
        'direct_line_buffer_load_response_exists': 'io.resp.valid     := rpq.io.deq.valid && io.lb_read.fire && drain_load' in mshr,
        'ldq_age_wakeup_exists': 'ldq_wakeup_idx = RegNext(AgePriorityEncoder' in lsu,
        'nack_clears_executed': 'ldq(idx).bits.executed := false.B' in lsu,
    }
    path = generated / 'BoomNonBlockingDCache.sv'
    found, data_lanes = [], set()
    with path.open() as f:
        for n, line in enumerate(f, 1):
            data_lanes.update(map(int,re.findall(r'debug_s2_nack_data_(\d+) =',line)))
            if any(s in line for s in ('debug_s2_nack_data_0 =',
                                      'debug_s2_nack_miss_0 =',
                                      'debug_s2_nack_victim_0 =')):
                found.append(dict(line=n, text=line.rstrip()))
    signatures['generated_bank_nack_constant_zero'] = any(
        "debug_s2_nack_data_0 = 1'h0;" in x['text'] for x in found)
    signatures['generated_single_memory_lane'] = data_lanes == {0}
    require(all(signatures.values()), 'source/collateral predicate audit failed')
    evidence[str(path)] = dict(sha256=sha(path), excerpts=found)
    # Config mixin is not in the old 19-file seal. Confirm the active geometry
    # and memory-lane/boundary capacity against the actual generated LSU too.
    path = generated / 'LSU.sv'
    indices, ldq_wires = set(), []
    with path.open() as f:
        for n, line in enumerate(f, 1):
            indices.update(map(int, re.findall(r'\bldq_(\d+)_valid\b', line)))
            if 'ldq_15_valid' in line and len(ldq_wires) < 2:
                ldq_wires.append(dict(line=n, text=line.rstrip()))
    require(indices == set(range(16)), 'generated LDQ size no longer 16')
    evidence[str(path)] = dict(sha256=sha(path), physical_ldq_entries=16, excerpts=ldq_wires)
    path = generated / 'BoomMSHRFile.sv'
    eqs = []
    with path.open() as f:
        for n,line in enumerate(f,1):
            if any(s in line for s in ('assign slowdown_mshr_file_req_ready_0 =',
                                      'assign io_secondary_miss_0 =', 'assign io_block_hit_0 =')):
                eqs.append(dict(line=n,text=line.rstrip()))
    signatures['generated_sdq_same_set_admission_equation'] = any(
        'slowdown_mshr_sdq_ready & (idx_match_0 ? tag_match_0 &' in x['text'] for x in eqs)
    require(signatures['generated_sdq_same_set_admission_equation'], 'generated admission equation changed')
    evidence[str(path)] = dict(sha256=sha(path), excerpts=eqs)
    return dict(status='PASS', signatures=signatures, artifacts=evidence)


def arm_analysis(arm, run, runtime, old):
    require(runtime['valid'] and all(runtime['gates'].values()), f'{arm} runtime gates not closed')
    raw = [json.loads(line) for line in (run / 'cache_opportunity.jsonl').open() if line.strip()]
    cache = next(d for d in raw if d['level'] == 1)
    causal = cache['causal']
    roi = read(run / 'roi.json')
    require(causal == runtime['causal'], f'{arm} raw/recovered causal mismatch')
    require(cache['actual'] == runtime['actual_l1'], f'{arm} raw/recovered actual cache mismatch')
    require(causal['status'] == 'PASS' and causal['errors'] == 0, 'invalid causal counters')
    start, stop = roi['start_cycle'], roi['stop_cycle']
    c = causal['counts']
    require(c['sample_cycles'] == stop-start == runtime['roi_cycles'], 'ROI count mismatch')
    require(sum(causal['mshr_occupancy_histogram']) == stop-start, 'occupancy does not partition ROI')
    rows, cutoff, capture, offset = old.read_events(run)
    cutoff = min(cutoff, stop)
    traffic_start = next(r['cycle'] for r in rows if r['kind']==10 and r['d'][1])
    traffic_stop = next(r['cycle'] for r in rows if r['kind']==30)
    require(traffic_stop-traffic_start == cache['cycles'], 'L1 traffic-window mismatch')
    groups = {str(r['kind']): r['d'] for r in rows if r['kind'] in range(40, 46) and r['hart']==0}
    require(groups == runtime['remaining_stop_counters']['groups'], 'STOP counters differ from raw')
    control = old.spans(rows, 7, start, cutoff)
    scheduler_intervals = old.merge([[x['start'], x['end']] for x in control
                                    if scheduler_unavailable(x['d'])])
    prefix_cycles = old.duration(scheduler_intervals)
    # Same state predicate as native scheduler observer, proven by existing analyzer.
    require(prefix_cycles <= c['scheduler_unavailable_cycles'], 'prefix exceeds full counter')
    hist = []
    for i, name in enumerate(['detect_to_alloc', 'alloc_to_refill', 'detect_to_data']):
        h = causal['latency_histograms'][i]
        hist.append(dict(metric=name, samples=sum(h), at_least_1024=sum(h[11:]),
                         at_least_4096=sum(h[13:]), highest_nonempty_bin=max(i for i,n in enumerate(h) if n),
                         bins=h))
    return dict(arm=arm, run=str(run), software_roi=[start,stop],
                traffic_window=[traffic_start,traffic_stop], roi_cycles=stop-start,
                actual_l1=cache['actual'], causal=causal, stop_groups=groups,
                optional_complete_prefix=[start,cutoff], optional_unknown_suffix_cycles=stop-cutoff,
                optional_records_omitted=capture['optional_records_omitted'],
                simulator_time_minus_boom_cycle=offset,
                scheduler_prefix=dict(cycles=prefix_cycles, intervals=scheduler_intervals,
                    distribution=old.distribution([b-a for a,b in scheduler_intervals]),
                    left_boundary_censored=bool(scheduler_intervals and scheduler_intervals[0][0]==start),
                    right_boundary_censored=bool(scheduler_intervals and scheduler_intervals[-1][1]==cutoff),
                    full_roi_native_cycles=c['scheduler_unavailable_cycles'],
                    unknown_suffix_native_total=c['scheduler_unavailable_cycles']-prefix_cycles,
                    scope='complete optional prefix only; suffix interval locations unknown'),
                latency_cohort=causal['latency_cohort'], latency=hist,
                miss_attempt_amplification=attempt_amplification(c['load_miss_lookup_attempts'],
                    c['load_tag_miss_requests'] + c['load_permission_miss_requests'], 16),
                retry_amplification=retry_factor(c['load_nack_retries']),
                critical_retry_amplification=dict(value=None, bounds=None,
                    reason='critical event/token association absent; empty critical cohort possible'),
                per_request_retry_histogram=None, per_line_retry_histogram=None,
                maximum_retry_episode_cycles=None, contiguous_head_episode_histogram=None)


def analyze(previous):
    paths = read(previous / 'input_paths.json')
    parent = Path(paths['actual_completed_report'])
    a_run, b_run = Path(paths['A_run']), Path(paths['B_run'])
    require(a_run.name == 'optimization_4_svb_20261030_135448_0c744900' and
            b_run.name == 'optimization_4_svb_20261031_024551_8fbf8937',
            'report template is scoped to the named completed A/B evidence pair')
    refresh = previous / 'baseline_refresh'
    require(not list(refresh.rglob('A_prime_result.json')) and
            not list(refresh.rglob('run_manifest.json')) and
            not list(refresh.glob('*CLAIM*')), 'A-prime evidence appeared: review strict pair first')
    a_runtime = read(parent / 'runtime_baseline_A.json')
    b_runtime = read(previous / 'runtime_B_recovered.json')
    seal = read(parent / 'sealed/source_seal.json')
    provenance = read(previous / 'runtime_provenance_rechecked.json')
    require(provenance['status']=='PASS' and all(provenance['checks'].values()), 'prior provenance not closed')
    checked = dict(hardware=audit_hashes(seal['hardware_sha256']),
                   sealed_tools=audit_hashes(seal['tool_sha256']),
                   original_evidence=audit_hashes(read(previous/'original_evidence_hashes.json')))
    generated_records = []
    for value in provenance['generated'].values():
        if isinstance(value, list):
            generated_records.extend(x for x in value if isinstance(x,dict) and 'path' in x and 'sha256' in x)
    for value in provenance['native_resources'].values():
        generated_records.extend(value)
    checked['prior_generated_native_files'] = audit_hashes({x['path']:x['sha256'] for x in generated_records})
    old = load_module(ROOT/'AI/Debug/scripts/analyze_opt4_remaining.py', 'opt5_existing_intervals')
    arms = {k:arm_analysis(k, r, runtime, old) for k,r,runtime in
            [('A',a_run,a_runtime), ('B',b_run,b_runtime)]}
    b = arms['B']; c = b['causal']['counts']; ac = arms['A']['causal']['counts']
    target = target_math(1001675, b['roi_cycles'], arms['A']['roi_cycles'])
    envelope = fixed_trace_envelopes(b['roi_cycles'], c[HEAD], c['rob_head_load_pending_cycles'], 1001675)
    overlap = {name:overlap_bounds(c[HEAD],c[key],b['roi_cycles']) for name,key in
               [('head_miss_AND_nack','load_nack_cycles'),
                ('head_miss_AND_retry','load_nack_retry_cycles'),
                ('head_miss_AND_replay_issue','load_rpq_replay_cycles')]}
    overlap.update(head_miss_AND_mshr_busy=[c[HEAD_BUSY]]*2,
                   head_miss_AND_scheduler=[c[HEAD_SCHED]]*2,
                   head_miss_AND_mshr_full=[0,0],
                   head_miss_AND_refill_wait=None, head_miss_AND_port_conflict=None,
                   head_miss_AND_data_bank_conflict=[0,0])
    overlap['all_head_pending_AND_scheduler'] = [
        max(c[HEAD_SCHED], c['rob_head_load_pending_cycles']+c['scheduler_unavailable_cycles']-b['roi_cycles']),
        min(c['scheduler_unavailable_cycles'],c[HEAD_SCHED]+c['rob_head_load_pending_cycles']-c[HEAD])]
    broad = traffic_roi_bounds(b['stop_groups']['43'][11],b['traffic_window'],b['software_roi'])
    audit = source_audit(b_run.parent.parent/'build'/b_run.name/'generated/gen-collateral')
    delta = {k:c[k]-ac[k] for k in c}
    decision = dict(TARGET_ROI=target['user_exclusive_roi_threshold'], TARGET_SLOWDOWN=1.5,
        CURRENT_B_ROI=b['roi_cycles'], REMAINING_GAP=target['approximate_gap'],
        REMAINING_ROB_HEAD_LOAD_WAIT=c[HEAD], REMAINING_ALL_HEAD_LOAD_PENDING=c['rob_head_load_pending_cycles'],
        REMAINING_NACK_RETRY=c['load_nack_retries'], REMAINING_REPLAY=c['load_rpq_replays'],
        MAIN_MECHANISM='NONE_JUSTIFIED', STRUCTURAL_AMPLIFIER='RETRY_AMPLIFICATION',
        OPT5_PRIMARY='NONE_JUSTIFIED', OPT5_INCLUDE_64K_2WAY='NO',
        CACHE_64K_ROLE='OPTIONAL_CAUSAL_PROBE_OR_FUTURE_COMPONENT',
        EXPECTED_RECOVERABLE_CYCLES=None, CONSERVATIVE_RECOVERABLE_CYCLES=0,
        UPPER_BOUND_CYCLES=envelope['combined_upper_bound'], UPPER_BOUND_SCOPE=POLICY,
        EXPECTED_FINAL_ROI=None, EXPECTED_FINAL_SLOWDOWN=None,
        NO_CREDIT_PLANNING_ROI=b['roi_cycles'], NO_CREDIT_PLANNING_SLOWDOWN=b['roi_cycles']/1001675,
        CONFIDENCE='LOW', NEGATIVE_EVIDENCE_CONFIDENCE='HIGH_WITHIN_OBSERVED_HEAD_WAIT_SCOPE',
        VERDICT='OPT5_1P5_TARGET_NOT_SUPPORTED_BY_CURRENT_EVIDENCE',
        LOAD_PATH_VERDICT='LOAD_PATH_ALONE_CANNOT_REACH_1P5',
        NEXT_ACTION='MORE_OFFLINE_ATTRIBUTION', STRICT_PAIRING='STRICT_PAIRING_PENDING',
        HARDWARE_RUNS_PREPARED=0, HARDWARE_PHASES_EXECUTED=[])
    return dict(target=target, arms=arms, fixed_trace_envelopes=envelope,
                overlaps=overlap, broad_no_commit_AND_load_pending_roi_bounds=broad,
                comparison=dict(label='REFERENCE_COMPARISON', strict_pairing='STRICT_PAIRING_PENDING',
                    roi_delta=b['roi_cycles']-arms['A']['roi_cycles'],
                    actual_lookup_miss_delta=b['actual_l1']['miss']-arms['A']['actual_l1']['miss'],
                    actual_miss_window='traffic window; causal counters use exact software ROI',
                    causal_deltas=delta),
                source_audit=audit, revalidated_hash_counts=checked, decision=decision,
                inputs=paths, previous_report=str(previous))


def write_reports(out, m):
    a,b = m['arms']['A'],m['arms']['B']
    c,ac = b['causal']['counts'],a['causal']['counts']
    t,e,d = m['target'],m['fixed_trace_envelopes'],m['decision']
    def save(name, text):
        (out/name).write_text(text.strip()+'\n')
    def table(keys):
        return '\n'.join(f'| {k} | {ac[k]:,} | {c[k]:,} | {c[k]-ac[k]:+,} |' for k in keys)
    save('README.md', f'''# Opt5 sub-1.5 gap：当前证据不支持达标方案

结论：`{d['VERDICT']}`；`NEXT_ACTION = {d['NEXT_ACTION']}`。
本轮只做离线分析，未修改硬件，未 elaboration / RTL generation / Verilator build / simulation，未准备新硬件运行。

B 的 exact-ROI head miss wait 为 **53,845 cycles**，放宽到全部 head-load pending 为 **80,832 cycles**，分别只覆盖约146,410缺口的36.8%和55.2%。两者嵌套，禁止相加。
`LOAD_PATH_ALONE_CANNOT_REACH_1P5` 在这里指固定观测轨迹中直接删除已测 head-load 等待不足以达标；它不是所有非head依赖或时序反馈收益的全局不可能性定理。

结构性 `RETRY_AMPLIFICATION` 已有 RTL 证据，但没有足够大的可恢复关键路径收益归因。B 的47,162 retries不能当成47,162或更多可恢复cycles。64KiB/2-way 保留为causal probe/可选组件，尚无最终Opt5定义；`OPT5_INCLUDE_64K_2WAY=NO` 表示本轮未成立方案，并非证明64KiB无效。

旧A / 新B只作 `REFERENCE_COMPARISON`；A′未执行，保持 `STRICT_PAIRING_PENDING`，不因缺A′停止分析，也不建议机械重跑。
B正确性已在前轮独立派生capture视图闭合；原始host-cap FAIL和所有seal/claim保持原样。

- [146k缺口与非相加分解](146k_gap_analysis.md)
- [真实nack原因与数据缺口](nack_retry_breakdown.md)
- [head等待与重叠](rob_head_remaining_wait.md)
- [重试放大机制及边界](retry_amplification.md)
- [各候选上界](candidate_upper_bounds.md)
- [三个最小设计选项](opt5_design_options.md)
- [收益预算](opt5_gain_budget.md)
- [1.5可行性](sub1p5_feasibility.md)
- [下一步离线计划](next_run_plan.md)

复现仅使用CPU离线分析：
```bash
python3 -I -B AI/Debug/scripts/analyze_opt5_sub1p5_gap.py --previous {m['previous_report']} --out AI/TMP/opt5_sub1p5_gap_analysis_<new_timestamp>
```
输出必须是不存在的新目录。`numeric_audit.json`保存全部数值、窗口、prefix intervals和未知值；`source_evidence.json`保存源码/生成物行号及SHA256；`provenance.json`保存本轮输入hash；`validation_result.json`保存验证边界。
''')
    save('146k_gap_analysis.md', f'''# 146k gap分析

native/reference=1,001,675；旧Opt4/A=1,707,863；B=1,648,923，slowdown={t['current_slowdown']:.9f}。
用户目标 `ROI < 1,502,513`，近似缺口146,410。严格1.5阈值为1,502,512.5；整数ROI最大1,502,512，需至少节省 **146,411**；相对Opt4至少205,351（用户近似205,350）。

| exact-ROI观测 | A | B | B−A |
|---|---:|---:|---:|
{table([HEAD,'rob_head_load_pending_cycles','load_nack_retry_cycles','load_rpq_replay_cycles','mshr_busy_cycles','mshr_full_cycles','scheduler_unavailable_cycles'])}

以下是固定轨迹的互斥状态分区，不是干预收益分解：

| 分区 | A | B | B−A |
|---|---:|---:|---:|
| head miss only | 139,677 | 53,845 | −85,832 |
| scheduler only | 318,133 | 347,409 | +29,276 |
| both | 17 | 0 | −17 |
| neither | 1,250,036 | 1,247,669 | −2,367 |

分区各列之和等于各自ROI；分区变化之和−58,940。head total减少85,849同时scheduler total增加29,259，不能把85,849再加进58,940，更不能把每个miss平均分配固定代价。时序变化/窗口内事件变化和未闭合pairing都可能改变分区。

head miss53,845 ⊆ all head-load pending80,832，后者包含额外26,987非已标记miss的head load等待。nack47,163 cycles / retry47,162 cycles / replay229 issue cycles可能互相重叠并落在head等待内；没有逐cycle join，不相加。
仅head miss理想删除后ROI1,595,078/{e['ideal_miss_deletion_slowdown']:.9f}x；全部head-load pending理想删除后1,568,091/{e['ideal_all_head_load_deletion_slowdown']:.9f}x，仍分别缺92,566/65,579才能严格低于1.5。

不能忽略的更宽证据：STOP traffic窗口 `ROB no-commit AND any load pending`159,519；扣除窗口外11,160后，ROI交集在 **148,359..159,519**。它名义上够大，但any-load与head blocker没有因果身份关联，可能与IC/GC/其他条件同时成立。该项不是已证明load stall，也不是可删除预算；它保留了非head依赖传播待归因空间。

独立control方向：native scheduler exposure347,409，head-miss交集0、MSHRbusy交集269/full0。它不是memory问题的已证放大器，不能捆入Opt5。作为以后独立方向可先离线归因，但目前也没有347k可恢复收益证明。
''')
    reason_rows = '\n'.join(f'| {label} | {ac[k]:,} | {c[k]:,} | {meaning} |' for label,k,meaning in [
        ('s2_nack_miss','nack_mshr_not_ready','S2 miss且MSHRFile req.ready低；非独占首阻塞原因'),
        ('s2_nack_victim','nack_victim','S2 hit但同set/way有不同tag的MSHR owner'),
        ('s2_nack_data','nack_data','活动duplicated data array常量false，生成RTL亦为0'),
        ('s2_nack_wb','nack_writeback','S2 miss且同set writeback匹配'),
        ('s2_nack_hit','nack_hit','S1 probe/metadata hazard延迟到S2')])
    save('nack_retry_breakdown.md', f'''# nack / retry：真实原因、窗口与观测限制

active memory width=1，因此下列load reason事件数也是该predicate被采样为真的nack-cycle exposure；predicate之间不互斥。普通load的S2原因与LSU nack对齐；stale-S3 nack为store-only。数值来自exact软件ROI。

| RTL predicate | A events/cycles | B events/cycles | 定义 |
|---|---:|---:|---|
{reason_rows}

总load nacks A111,557/B47,163；retry A111,548/B47,162。`miss`与`victim`因`!s2_hit`/`s2_hit`互斥，B并集47,159；仅4个nack在两者之外。writeback2,354和probe25可能与这些原因重叠；不能把原因之和当总nack，也不能把4解释为精确owner类总数。未导出原因还可与miss/victim同时出现。

`s2_nack_miss`并不证明MSHR数量不足：ready由所选lane、cacheable/MMIO、全局SDQ、同set/tag匹配、primary ready、secondary状态/RPQ ready共同决定。即使有空MSHR，同set不同tag也不允许primary；同tag secondary在drain/meta/finish/probe/第二acquire/跨package写/协议fault/RPQ满时也可能不ready。req.valid=0时ready也可低，故39,072是nack predicate，不等于真实valid&&!ready rejection20,433。MSHR full=0、最大occupancy2/6，排除“必须增加MSHR”结论。

完整nack OR（dcache.scala:1250–1304，已保存逐行摘录）：

- 上述miss/probe/victim/data/writeback。
- `s2_clear_freeze_read_bypass_miss`：clear-freeze旁路只准hit，miss退回。
- `s2_owner_block`：clearing、stale slot epoch、frozen/reserved/completionPending hit，或reserved非secondary miss。
- `s2_clear_slot_conflict`：freeze同set/way且tag不命中。
- `s2_write_busy`：S3有效或completionQ非空，对write生效。
- lane0 `s2_realloc_owner_conflict`：tagmiss拟重分配到同周期S3旧store effect的set/way。
- lane0 `l1CrossPackageBlocked`：跨package保护下的write；与上项必须保留owner/order语义。
- stale-S3 store nack输出路径独立存在，本次普通load因果计数不应解释为该store路径。

port/arbitration backpressure不必产生nack：LSU ready由meta/data arbiter及freeze许可共同决定。meta读优先级replay/probe/WB/MSHRmeta/LSU/prefetch；data读replay/WB/LSU。refill写在pipeline/effect写之后；replay还受replayPipelineBusy/S3/completionQ限制。这些是结构条件，缺少实际blocked-cycle细分，不能归为已测refill-conflict损失。

load/store现有范围：STOP为traffic窗口B load nack47,210、store nack4,088，A load nack{a['stop_groups']['43'][9]:,}、store nack{a['stop_groups']['43'][10]:,}。B load/store request wait1,541/81,784；总83,325。exact ROI仅有load细分，未导出store nack逐原因。STOP的load nack与native精确ROI的47,163不同，不能混窗。

缺失值明确为null：逐request/line重试次数与直方图、最大retry episode、head相关nack/token join、refill/port独占阻塞周期。原日志未保留native14/15/21/22的逐事件；SC14/15是store-preservation命名空间，不能冒充load miss事件。成功运行没有saved FST/VCD，ring不在成功时导出，compact capture过滤掉S1/refill printf，因此离线无法恢复这些被丢弃的信息。
''')
    rows = '\n'.join(f'| {k} | {v if v is not None else "UNOBSERVED"} |' for k,v in m['overlaps'].items())
    save('rob_head_remaining_wait.md', f'''# B剩余head load waiting

exact ROI `[698301,2347224)`，1,648,923 BOOM cycles。时间采用原SC pre-edge cycle，所有区间为半开区间；simulator time与BOOM cycle的偏移见numeric_audit，不将其他clock域cycle直接混入。
head由ROB索引与live LDQ functional_token匹配且未succeeded得到，native再匹配该token的已观测miss状态。窄定义head miss53,845；宽定义head pending80,832。STOP的head-load∩any-load-pending80,037是另一种较弱身份定义，且窗口不同，不能替换精确计数。

| 与head miss的交集 | exact值或仅由marginals所得上下界 |
|---|---|
{rows}

head miss∩busy53,795，outside busy50；full0。busy只表示某MSHR非空，不能替代refill仍未到达或refill写port被占用。nack/retry/replay交集为Fréchet bounds，非实测关联；229 replay issue cycles更不等于229 cycles的完整replay停顿。

251个在ROI完成的miss曾到head；其累计head周期53,845恰等于head miss counter。本指标是per-token累计headCycles之和，不是连续head-blocking episode直方图；不能据此声称max/p95 head episode。

latency completion-in-ROI队列可起于ROI之前，未完成样本censored：

| B cohort | N | 累计latency sum | ≥1024 samples | ≥4096 samples | 最大非空bin |
|---|---:|---:|---:|---:|---|
| detect→alloc | 960 | 157,622 | 18 | 12 | 14=[8192,16383] |
| alloc→refill | 1,883 | 157,331 | 8 | 5 | 14=[8192,16383] |
| detect→data | 1,052 | 211,045 | 22 | 16 | 14=[8192,16383] |

这些latency sum可跨请求并发、包含pre-ROI、不同cohort，不能相加、不能减作ROI收益。detect→data长尾说明少量长延迟存在，但缺少head/retry join，不能证明这些长尾贡献146k。

直接head miss全部理想删除上界53,845；宽定义全部删除80,832。`LOAD_PATH_ALONE_CANNOT_REACH_1P5`。该判断只限制观测到的直接head等待，未否定非head依赖、unblock提前、资源反馈等尚未归因的收益。必须避免用此上界作为所有load优化的全局反事实上界。
''')
    amp = b['miss_attempt_amplification']; aa=a['miss_attempt_amplification']
    save('retry_amplification.md', f'''# retry amplification：循环已证明，关键路径倍率未测得

RTL闭环：LDQ保留immutable functional_token → DCache lookup → S2被结构条件nack → LSU核对live token并清executed → registered AgePriorityEncoder从LDQ head挑可执行load → 同一token再次lookup，直至资源/owner状态改变。一次实际miss或同set owner窗口可以容纳很多次这种尝试；tag-miss attempts会对同token每次增加，首次miss-request计数只增加一次。

这支持“容量改变减少冲突窗口 → 重复lookup/nack随之大幅减少 → 某些load更早解除head阻塞”的结构解释。它没有证明所有64,386 retry减少来自648个actual miss减少：actual misses在更大的traffic窗口，retry在精确ROI，而且旧A/新B非严格pair。两run之间也没有同token对应关系。不能用64,386/648推导每miss固定代价。

用户定义 retry events / unique affected retry requests：B分子47,162，分母未导出；精确倍率null，安全但很宽的bounds **[1,47,162]**。A为[1,111,548]。不是用1,062个first miss当分母，因为hit-victim/probe/uncached等nack cohort不等于首次cacheable miss cohort。
critical retry events / unique critical requests：二者关联均未导出，critical事件可能为0，倍率可能未定义；若条件性假设至少1个critical事件，则倍率在[1,47,162]。head∩retry-cycle最多47,162、最少0，不证明任一token的critical amplification。

可以独立给出较有信息量的**miss lookup attempt**倍率边界：

| arm | attempts | ROI首次tag+permission detections | 含carry-in的affected miss token bounds | attempts/token bounds | 至少一个token尝试≥ |
|---|---:|---:|---:|---:|---:|
| A | {aa['attempts']:,} | {aa['first_detections_in_roi']:,} | {aa['affected_miss_token_count_bounds']} | {aa['attempts_per_miss_token_bounds'][0]:.4f}..{aa['attempts_per_miss_token_bounds'][1]:.4f} | {aa['some_token_attempt_count_at_least']} |
| B | {amp['attempts']:,} | {amp['first_detections_in_roi']:,} | {amp['affected_miss_token_count_bounds']} | {amp['attempts_per_miss_token_bounds'][0]:.4f}..{amp['attempts_per_miss_token_bounds'][1]:.4f} | {amp['some_token_attempt_count_at_least']} |

推导：本次生成RTL有16个LDQ槽；ROI开始前已detected、但在ROI里再次lookup的token最多16；ROI中新detected的每个token至少有一次kind14。stable token/slot lifetime保证分母在[first,first+16]，由鸽巢原理B至少一个token有38次miss lookup（至少37次重复）。这是cohort-bound，不能冒称实测逐token nack histogram或critical factor。native忽略address，无法建立每line retry分布。

七个机制判断：

1. 一个miss导致大量重复lookup：结构证明且上述aggregate bound支持；具体request nack次数未记录。
2. refill window内重新发起：当窗口仍使ready/owner条件不满足时结构上成立；缺少refill-state/token时间join，未测该子集大小。
3. miss占共享资源：同set MSHR排他、RPQ admission/drain、meta/data端口/WB/owner保留均有源码证据；各自占关键周期未测。
4. critical load受普通请求挤压：端口固定优先级可能造成等待，但未测关键请求被挤压多久；不能称已确认饥饿。
5. hit/miss特定状态重复nack：victim8,087、miss-not-ready39,072支持，S2具体first blocker未分解。
6. retry缺少age/保留：已排除。LDQ已保留请求且有age priority；重复增加age仲裁/queue不是新优化。
7. refill/replay/lookup serialization：结构存在；普通load已可从line-buffer直接返回，RPQ replay held-until-terminal是正确性协议。尚未分开外部服务时间与本地可消除serialization。

四层证据：症状=47,162 retries（PROVEN）；直接阻塞=S2谓词及MSHR admission（PROVEN，数量细分有限）；上游trigger=每次具体owner/refill/SDQ条件（UNPROVEN逐事件）；下游amplifier=保留token的重复lookup循环（PROVEN），其ROI可恢复周期（UNPROVEN）。
''')
    save('candidate_upper_bounds.md', '''# 候选机制：固定观测轨迹的上界与保守预算

“上界”仅指删除当前记录的直接head等待的局部模型；不含重新运行时序反馈。unknown不是0；conservative0表示目前不能保证正收益，不表示物理收益为零。

| Candidate | Exposure | Critical overlap | Theoretical removable upper bound | Conservative recoverable | Confidence |
|---|---|---|---|---:|---|
| nack amplification | 47,163 nack / 47,162 retry issue cycles | head-miss∩retry [0,47,162]，未测 | 仅删除retry issue∩head最多47,162；包括issue之间等待的完整机制只能借head-miss53,845/宽80,832包络，不能用事件数作机制上界 | 0 | 循环HIGH；收益LOW |
| refill/admission serialization | busy194,905，detect→alloc/refill latency为不同cohort | head-miss∩busy53,795，非refill-conflict计数 | 以相关head-wait作为宽包络最多53,845；真正local refill port子集unknown，可能远小于此 | 0 | structural HIGH；attribution LOW |
| RPQ replay serialization | 229 replay issue cycles；全部229 issue时MSHR busy | head-miss∩issue [0,229] | 直接issue重叠≤229；issue间持有/排队未测，全部load replay机制只能用53,845/80,832宽包络 | 0 | LOW |
| all ROB-head miss wait | 53,845 | 53,845 | 53,845（包括不可消除外部服务等待） | 0 | exposure HIGH；recoverability LOW |
| all head-load pending | 80,832 | 80,832 | 80,832，包含上项，禁止加53,845 | 0 | exposure HIGH；recoverability LOW |
| data bank conflicts | 0，active duplicated array常量false | 0 | 此active bank-nack机制为0 | 0 | HIGH |
| LSU load request port backpressure | traffic load request valid&&!ready共1,541 cycles | 未测；exact ROI子集[0,1,541] | 仅删除已发起load请求的ready等待≤1,541；不能外推到尚未选入LSU的load或后续nack间隔 | 0 | exposure HIGH；gain LOW |
| more MSHRs | full0，max2/6 | head∩full0 | 直接full-stall删除为0；不能据此推断同set admission完全可消除 | 0 | 不支持扩容HIGH |
| scheduler interaction | 347,409 | head miss0；busy269/full0 | head-miss共同状态的直接删除0；整个control方向最多347,409 exposure但可恢复unknown、属于独立主题 | 0 | overlap HIGH；gain LOW |
| broader nonhead dependence | STOP noCommit∩anyLoadPending159,519，ROI范围148,359..159,519 | 没有load→head blocker身份join | 仅是宽相关exposure，尚无可恢复上界或>100k机制证明 | 0 | LOW |

nack/refill/replay是同一生命周期的不同阶段/事件；其完整head包络高度重叠，不能把三个53,845加起来超过146k。也不能把47,162+53,795+229称为可恢复预算。scheduler与head miss在B不重叠，也不证明删除两者会取得两个干预收益之和。

优先使用实际head-cycle aggregate；连续head episode和retry episode未保留，因此不编造episode max/p95。已保存完整可观测control prefix interval分布仅用于下一步control归因，不用替代load episode。
''')
    save('opt5_design_options.md', '''# 三个最小设计选项（设计评估，均未实现/未准备运行）

目前没有同时满足“>100k-cycle可归因critical上界、明确首阻塞、低中复杂度修复”的方案。下面是由真实RTL结构支持的研究选项；64KiB均可独立保持/关闭，当前不把它定为Opt5。

| Option | 模块与信号 | 最小状态/逻辑 | timing / area | correctness / 独立验证 | 当前阻碍 |
|---|---|---|---|---|---|
| 1 依赖资源进展的LDQ retry抑制 | lsu.scala `ldq_wakeup_idx` eligibility、nack live token；dcache/MSHR反馈具体not-ready子原因与blocking owner generation | 每LDQ槽blocked reason + owner/set generation标记；复用16槽LDQ，不新建request queue；相关refill/owner release/SDQ/RPQ进展解除，另保留有界recheck保证活性 | 低至中：若仅3-bit reason+1valid每槽约64b，但owner generation/set标记另计，不能声称总共64b。eligibility必须注册，避免ready组合路径回到age arbiter | 保留branch kill/exception、token代际、ordering/uncached/LR/AMO规则；进展事件丢失或owner复用不能永久睡眠。age仲裁与请求保留已存在。可在32K/64K独立验证 | 目前miss-not-ready不是唯一first blocker；无retry∩critical时间join；抑制lookup可省端口工作，却可能不提前数据/ROI |
| 2 定向refill/meta进展仲裁 | dcache.scala dataWriteArb pipeline/effect与refill、meta读写、`refillOwnerMatch`；mshrs状态/line buffer | 仅对已证critical阻塞加入一个held urgent/refill-age状态，复用现有grant；具体选择策略须等port-wait归因，不能提前指定抢占 | 中：arbitration选择路径/扇出会变长；必须注册或维持held grant，不能新增长head-token→array-ready组合锥 | 不抢占S3 held write、不越过reserved/completionPending/epoch/order；ordinary load line-buffer直返已存在。可独立于cache容量 | 没有实际refill valid&&!ready、meta publish等待、head overlap；不能判断外部grant慢还是本地端口慢，不能把busy194,905全删 |
| 3 SDQ门控对load特化 | mshrs.scala global `sdq_rdy`用于`pri_val`/secondary valid/`io.req.ready` | cacheable普通只读load不消耗SDQ时，全部相关valid/ready条件一致特化；通常无需新queue/state，不能只改ready导致伪fire | 低逻辑面积，改shared admission扇出；须审查read/write、AMO/prefetch/MMIO分类与SDQ id使用 | 保留store/AMO容量与数据所有权；valid/fire分配一致，协议fault及同set限制不放松。32K/64K均能单独验证 | 未导出SDQfull周期/critical overlap，可能全程没有此机会；收益下界0 |

不建议直接放松same-set/secondary-drain/owner guards：需要新owner并行协议或改变有限drain集合，已超出“廉价小改”且可能破坏package保护。也不新增age queue、不声称linebuffer bypass是新发明。
三项不打包；任何进入下一次主要functional run的实现必须先选定一个有收益证据的主因果机制。此次不改RTL、不编译，不存在“实现已验证”的声明。
''')
    save('opt5_gain_budget.md', f'''# Opt5收益预算：当前没有205k可支持预算

| Component | 数值 | 类型 | 可计入预计收益？ |
|---|---:|---|---|
| A 64KiB/2-way相对旧A | 58,940 cycles | measured reference delta，非strict causal estimate | 仅参考，不能保证 |
| B retry amplification fix相对B | unknown；保守0 | 尚无实现/关键路径归因；head-miss局部包络53,845 | 不把上界当预计值 |
| C 同因果链refill/replay小改 | unknown；保守0 | 与B共享head包络，不能相加 | 不计入 |
| total expected vs Opt4 | unknown | 没有可靠点估计 | 不支持≥205,350 |

保守规划不给未证实优化任何cycle credit：B维持1,648,923/{t['current_slowdown']:.9f}x。这是current measured result/no-credit planning case，**不是已实现Opt5的预测**。新候选expected final ROI/slowdown为null。

用于审查目标的乐观固定轨迹情形：

| 情形 | vs Opt4总改善 | 最终ROI | slowdown | 距严格1.5仍缺 |
|---|---:|---:|---:|---:|
| reference容量delta + 理想删除B全部head miss | 58,940+53,845=112,785 | 1,595,078 | {e['ideal_miss_deletion_slowdown']:.9f} | 92,566 |
| reference容量delta + 理想删除B全部head pending | 58,940+80,832=139,772 | 1,568,091 | {e['ideal_all_head_load_deletion_slowdown']:.9f} | 65,579 |

上述是从当前B删除已观测周期的illustration，容量delta已包含在B，不再次从B扣58,940。第二行包含第一行，不能加总。capacity与retry优化也可能有负交互：容量已消掉很多可抑制的retry。没有严格pairing和新候选运行，不能把两项独立测量当无交互收益。
''')
    save('sub1p5_feasibility.md', f'''# sub-1.5可行性决策

`OPT5_1P5_TARGET_NOT_SUPPORTED_BY_CURRENT_EVIDENCE`

当前不能提出一个有可信收益预算、硬件可落地且只需最多一次主要验证就能合理期待<1.5的Opt5。缺少>100k-cycle首阻塞归因；观测head-miss包络仅53,845，即使全部head-load pending也只有80,832。
`LOAD_PATH_ALONE_CANNOT_REACH_1P5` 只是在固定观测head-wait直接删除模型下成立。非head依赖与时序反馈仍可能改变新执行，但现有日志不能证明其recoverable budget；更宽的148,359..159,519相关exposure也不能弥补这一证据缺口。

realistic target：先保住当前B实测1.646165673x；若后续确证load子优化，可把“有所低于1.646”作为验证目标，不能承诺数值区间。1.592410712x是理想删除全部head-miss的局部极限场景，1.565468840x是更宽head-pending理想场景，均不是预计收益，更未到1.5。
若只从已测head路径获益，要进一步达标仍需约65.6k–92.6k额外周期来自另一个**已归因**方向或非head反馈。最大已识别独立control候选为scheduler exposure347,409，但它不是证明可恢复的347,409；不纳入此次load主题Opt5。保持SVB16/L2/checker已闭合结论，不为目标重开无关优化。

```text
TARGET_ROI = {d['TARGET_ROI']}
TARGET_SLOWDOWN = 1.5
CURRENT_B_ROI = {d['CURRENT_B_ROI']}
REMAINING_GAP = {d['REMAINING_GAP']}
REMAINING_ROB_HEAD_LOAD_WAIT = {d['REMAINING_ROB_HEAD_LOAD_WAIT']}
REMAINING_NACK_RETRY = {d['REMAINING_NACK_RETRY']}
REMAINING_REPLAY = {d['REMAINING_REPLAY']}
MAIN_MECHANISM = NONE_JUSTIFIED
OPT5_PRIMARY = NONE_JUSTIFIED
OPT5_INCLUDE_64K_2WAY = NO
EXPECTED_RECOVERABLE_CYCLES = UNKNOWN (conservative credit = 0)
UPPER_BOUND_CYCLES = 80832 (fixed-trace all-head-load-pending; narrower miss = 53845)
EXPECTED_FINAL_ROI = UNKNOWN (no-credit current B = 1648923)
EXPECTED_FINAL_SLOWDOWN = UNKNOWN (no-credit current B = {t['current_slowdown']:.9f})
CONFIDENCE = LOW
VERDICT = OPT5_1P5_TARGET_NOT_SUPPORTED_BY_CURRENT_EVIDENCE
NEXT_ACTION = MORE_OFFLINE_ATTRIBUTION
```

LOW指候选正收益估计置信度；已测head exposure不足的算术判断为HIGH（限上述范围）。NO指未选定方案，64K仍可选，不是NOT_NEEDED结论。
''')
    bp,ap = b['scheduler_prefix'],a['scheduler_prefix']
    save('next_run_plan.md', f'''# 下一步：MORE_OFFLINE_ATTRIBUTION

没有准备新Opt5硬件运行，没有COMMANDS_FOR_USER。A′未运行，`STRICT_PAIRING_PENDING`；本轮不启动也不机械要求A′。旧A′封存命令仍是历史资料，未更改其seal/guard/claim。

可立即继续的离线工作：

1. 对现有control complete prefix的长区间做FSM/IC/GC/commit条件归因，检验更宽noCommit∩load-pending是否主要在control阻塞期间；没有逐cycle load trace时保持不能join，而非用时间接近冒充因果。
2. 在源码和已有模块offline模型中审查option1进展唤醒/kill/token代际的活性、option3 SDQ load特化是否会生成false fire。仅设计/CPU模型，不做elaboration或仿真；若发现新静态机制仍须说明其runtime exposure未知。
3. 分离本地refill-port阻塞与外部grant服务时间所需的最小计数规格；只作为以后**独立证明值得跑的functional candidate**的附带诊断，不准备diagnostic-only run。需同版本记录blocked reason、token generation、head overlap、refill/meta valid&&!ready、SDQfull、逐请求retry bounded histogram及溢出计数。不能retrofit到旧run。

已有bounded reconstruction（本次numeric_audit保存intervals）：

| arm | complete optional ROI prefix | unknown suffix | scheduler prefix cycles | interval N | p50 / p95 / max |
|---|---|---:|---:|---:|---|
| A | {a['optional_complete_prefix']} | {a['optional_unknown_suffix_cycles']:,} | {ap['cycles']:,} | {ap['distribution']['n']} | {ap['distribution']['p50']}/{ap['distribution']['p95']}/{ap['distribution']['max']} |
| B | {b['optional_complete_prefix']} | {b['optional_unknown_suffix_cycles']:,} | {bp['cycles']:,} | {bp['distribution']['n']} | {bp['distribution']['p50']}/{bp['distribution']['p95']}/{bp['distribution']['max']} |

prefix基于8MiB host optional budget与每record≤448B的保守完整性证明；未知suffix不能hold-last。interval统计包括ROI/截止边界截断，非完整run episode分布。B native scheduler总347,409，prefix280,215，suffix总67,194但位置未知。没有FST也不尝试伪造head-load interval。

未来唯一新主要run的准入条件：一个明确主机制、够大且不重复计数的critical机会、最小RTL实现和offline正确性/活性证明、与B基线的兼容/差异审计。届时把functional改动与完整correctness/performance计数放同版，最多准备1次user-run candidate；能复用B就不重跑B，不先跑diagnostic，不做geometry sweep/MSHR扩容/无关bundle。本轮条件未满足。
''')


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--previous', type=Path, default=DEFAULT_PREVIOUS)
    p.add_argument('--out', type=Path, required=True)
    args = p.parse_args()
    require(not args.out.exists(), 'refusing existing output directory')
    m = analyze(args.previous.resolve())
    args.out.mkdir(parents=True)
    write_reports(args.out, m)
    (args.out/'numeric_audit.json').write_text(json.dumps(m,indent=2,sort_keys=True)+'\n')
    (args.out/'final_decision.json').write_text(json.dumps(m['decision'],indent=2,sort_keys=True)+'\n')
    (args.out/'source_evidence.json').write_text(json.dumps(m['source_audit'],indent=2,sort_keys=True)+'\n')
    paths = [args.previous/'input_paths.json', args.previous/'runtime_B_recovered.json',
             args.previous/'reference_comparison.json',args.previous/'original_evidence_hashes.json',
             args.previous/'runtime_provenance_rechecked.json',
             ROOT/'AI/Debug/scripts/analyze_opt4_remaining.py', Path(__file__)]
    for arm in m['arms'].values():
        paths.extend(Path(arm['run'])/f for f in
                     ['cache_opportunity.jsonl','safe_chain_events.tsv','roi.json','capture_summary.json','run_manifest.json'])
    manifest = dict(input_sha256={str(x.resolve()):sha(x) for x in paths},
                    original_rechecked=m['revalidated_hash_counts'],
                    immutable_inputs=True, hardware_phases_executed=[])
    (args.out/'provenance.json').write_text(json.dumps(manifest,indent=2,sort_keys=True)+'\n')
    validation = dict(status='PASS', scope='offline evidence/attribution audit; no new hardware validation',
        raw_native_vs_recovered_view='PASS', raw_STOP_vs_saved_view='PASS',
        exact_roi_occupancy_partition='PASS', source_generated_signatures='PASS',
        sealed_hardware_tools_original_evidence_unchanged='PASS',
        old_A_vs_B='REFERENCE_COMPARISON', strict_pairing='STRICT_PAIRING_PENDING',
        A_prime_executed=False, hardware_sources_modified=0, new_hardware_runs_prepared=0,
        hardware_generation='NOT_EXECUTED',verilator_build='NOT_EXECUTED',simulation='NOT_EXECUTED',
        missing_per_token_retry_and_head_episode_history='EXPLICIT_NULL',
        bounds_scope=POLICY, offline_tests='SEE_FINAL_VALIDATION_ADDENDUM')
    (args.out/'validation_result.json').write_text(json.dumps(validation,indent=2,sort_keys=True)+'\n')
    print(json.dumps(dict(out=str(args.out),decision=m['decision']),indent=2))


if __name__ == '__main__':
    main()
