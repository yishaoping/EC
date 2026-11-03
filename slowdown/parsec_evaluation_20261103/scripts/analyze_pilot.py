#!/usr/bin/env python3
"""Workload-specific correctness plus reused protocol/capture/checker validators.
No BFS correctness predicates or baseline constants are used here.
"""
import argparse,collections,importlib.util,json,re
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def module(name,path):
    s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
stable=module('svb',ROOT/'slowdown/optimization_4_svb/analysis/analyze_svb.py')
overlap=module('overlap',ROOT/'slowdown/optimization_6_overlap/scripts/analyze_overlap.py')
checker=module('checker',ROOT/'slowdown/optimization_6_overlap/scripts/profile_checkers.py')
def dump(p,x):p.write_text(json.dumps(x,indent=2)+'\n')
def analyze(run):
    manifest=json.loads((run/'run_manifest.json').read_text());logs='\n'.join((run/n).read_text()for n in ['stdout.log','stderr.log']);errors=[]
    bits=[]
    output=manifest.get('output',[])
    if len(output)!=1 or 'verified=1' not in output[0]:errors.append('Missing benchmark verification')
    if manifest['software']['benchmark']=='canneal':
        host=ROOT/'slowdown/parsec_evaluation_20261103/build'/ (manifest['software']['benchmark']+'_'+manifest['software']['input_class'])/'host_reference.json'
        if host.exists():
            expected=re.findall(r'routing_cost=(\d+)',json.loads(host.read_text())['stdout'])
            if re.findall(r'routing_cost=(\d+)',output[0])!=expected:errors.append('Canneal routing cost differs from independent host execution')
    if not manifest.get('software_correct'):errors.append('Software/normal simulation completion failed')
    assertions=len(re.findall(r'(?i)assertion|%Error|\*\*\* FAILED',logs))
    if assertions:errors.append('Runtime assertion/error marker')
    out={'design':manifest['design'],'run_id':manifest['run_id'],'ROI_cycles':manifest.get('roi_cycles'),'total_harness_cycles':manifest.get('total_harness_cycles'),'host_wall_seconds_simulation_cost':manifest.get('host_wall_seconds'),'software_correct':manifest.get('software_correct'),'price_bits':bits,'output':output,'main_hart_roi_instret':manifest.get('roi_instret'),'assertion_or_failure_markers':assertions,'errors':errors,'validation_scope':'software output and completion; correction additionally requires package/protocol/integrity/capture checks; detection has no equivalent sequenced-result or per-checker work counters'}
    if manifest['design']=='correction' and manifest.get('roi_cycles'):
        records=stable.parse_events(run/'safe_chain_events.tsv');cap=json.loads((run/'capture_summary.json').read_text())
        protocol=stable.protocol_ledger(records,run/'safe_chain_events.tsv',16);integrity=stable.integrity_ledger.build(records);ordering=stable.data_ordering(records);evidence=stable.capture_evidence(run,True,True)
        allocations=[r for r in records if r['kind']==2 and r['nums'][0]]
        results=[r for r in records if r['kind']==3 and r['nums'][1]&2]
        seqs=[r['nums'][0]for r in allocations];result_ids=[(r['hart'],r['nums'][0]&0xffffffff)for r in results]
        statuses=collections.Counter((r['nums'][0]>>32)&3 for r in results)
        result_flags={name:sum(bool(r['nums'][1]&(1<<bit))for r in records if r['kind']==3)for bit,name in [(2,'stale'),(3,'held_duplicate'),(4,'failed'),(5,'cancelled')]}
        packages={'generated':len(allocations),'unique_generated':len(set(seqs)),'accepted_results':len(results),'PASS':statuses[0],'FAIL':statuses[1],'CANCELLED':statuses[2],'invalid_status':statuses[3],'result_ids':result_ids,'generated_sequences':seqs,'scope':'full captured protected session; accepted BOOM-domain results, not local done'}
        packages['all_result_observation_flags']=result_flags
        roi=json.loads((run/'roi.json').read_text())
        packages['accepted_before_software_ROI']=sum(r['cycle']<roi['start_cycle']for r in results)
        packages['accepted_inside_software_ROI']=sum(roi['start_cycle']<=r['cycle']<roi['stop_cycle']for r in results)
        packages['accepted_after_software_ROI']=[{'hart':r['hart'],'seq':r['nums'][0]&0xffffffff,'cycle':r['cycle']}for r in results if r['cycle']>=roi['stop_cycle']]
        packages['last_accepted_cycle']=max((r['cycle']for r in results),default=None)
        packages['hardware_result_tail_after_software_ROI_cycles']=max(0,(packages['last_accepted_cycle'] or 0)-roi['stop_cycle'])
        packages['start_to_last_accepted_result_cycles']=(packages['last_accepted_cycle']-roi['start_cycle'])if results else None
        if not seqs:errors.append('No protected packages generated')
        if result_flags['failed'] or result_flags['cancelled']:errors.append('Unexpected failed/cancelled flag on a result observation')
        if len(set(seqs))!=len(seqs) or len(set(result_ids))!=len(result_ids):errors.append('Duplicate allocation/result identity')
        if statuses[1]or statuses[2]or statuses[3]:errors.append('FAIL/CANCELLED result')
        if collections.Counter(seqs)!=collections.Counter(x[1]for x in result_ids):errors.append('Generated/accepted package mismatch')
        cache=stable.cache_opportunity(run,True,integrity)
        cache['shadow_validation_status']='PASS' if cache.get('models') and all(m.get('geometry_decision_eligible') and m.get('analyzer_s0_miss_relative_error',1)<=0.10 for m in cache['models']) else 'FAIL'
        cache['shadow_validation_by_level']={str(m.get('level'))+':'+str(m.get('instance')):('PASS' if m.get('geometry_decision_eligible') and m.get('analyzer_s0_miss_relative_error',1)<=0.10 else 'FAIL')for m in cache.get('models',[])}
        if cache.get('status')!='PASS':errors.append('Cache physical accounting validation '+str(cache.get('status')))
        windows={m['cycles'] for m in cache.get('models',[])if m.get('level')==2 and 'cycles'in m};window=next(iter(windows))if len(windows)==1 else None
        phases=overlap.sourcec(records,cap,window);terminal=overlap.terminal_snapshots(records,cap,window,True);retention=overlap.retained_copy(records,cap,window,True)
        for n,v in [('protocol',protocol),('integrity',integrity),('ordering',ordering),('capture',evidence),('SourceC',phases),('terminal',terminal),('retention',retention)]:
            if v.get('status')!='PASS':errors.append(n+' validation '+str(v.get('status')))
        if integrity['completions']!=protocol['svb_completions']:errors.append('SVB integrity/protocol completions differ')
        accounting=cache.get('entry_accounting',{});terms=integrity.get('terminal_counts',{})
        for k,v in [('allocations',integrity.get('allocations')),('completions',terms.get('PROMOTED_COMPLETED',0)),('coalesced',terms.get('COALESCED',0)),('discarded',terms.get('FLUSH_DISCARDED',0)+terms.get('INVALIDATED',0))]:
            if accounting.get(k)!=v:errors.append('Final SVB accounting mismatch '+k)
        profile=checker.profile(run);dump(run/'checker_profile.json',profile)
        harts=profile['harts'];instructions=sum(h['checked_instructions']for h in harts)
        counts={k:sum(h['counters'][k]for h in harts)for k in checker.CATEGORIES}
        loads=sum(p['checked_loads']for p in profile['packages']);stores=sum(p['checked_stores']for p in profile['packages'])
        profile_summary={'fully_captured_ROI_packages':len(profile['packages']),'checked_instructions':instructions,'checked_loads':loads,'checked_stores':stores,'excluded':profile['excluded'],'local_priority_cycles':counts,'local_cycles_per_checked_instruction':{k:v/instructions if instructions else None for k,v in counts.items()},'scope':profile['scope'],'harts':harts}
        groups=collections.defaultdict(list)
        for r in records:
            if r['kind']==11 and 1<=r['hart']<=4 and r['nums'][0]:groups[(r['hart'],r['nums'][0])].append(r)
        closed={}
        for identity,rows in groups.items():
            rows.sort(key=lambda r:r['time'])
            starts=[r for r in rows if r['nums'][2]&128 and not r['nums'][3]]
            ends=[r for r in rows if r['nums'][2]&2]
            if not starts or not ends:continue
            first,last=starts[0],ends[-1]
            if first['time']>last['time'] or any(first['nums'][3:]) or last['nums'][3]!=sum(last['nums'][4:13]):errors.append('Invalid full-session checker counter interval')
            if any(any(a<b for b,a in zip(x['nums'][3:],y['nums'][3:]))for x,y in zip(rows,rows[1:])):errors.append('Full-session checker counters decreased')
            closed[identity]=last
        full_work_complete=set(closed)==set(result_ids)
        full_work={'fully_captured_session_packages':len(closed),'complete':full_work_complete,'checked_instructions':sum(r['nums'][13]for r in closed.values()),'checked_loads':sum(r['nums'][14]for r in closed.values()),'checked_stores':sum(r['nums'][15]for r in closed.values()),'checker_local_active_cycles':sum(r['nums'][3]for r in closed.values()),'scope':'entire protected session, including four packages crossing software ROI; counter interval validated for every BOOM-accepted result; management/boundary instructions can differ from hart0 rdinstret'}
        profile_summary['observed_active_capacity_fraction']=sum(counts.values())/(2*out['ROI_cycles'])
        profile_summary['active_capacity_fraction_scope']='lower bound from complete packages wholly inside ROI; denominator four checkers at half BOOM clock, 4*ROI/2; excludes four boundary packages'
        out.update(packages=packages,full_session_checker_work=full_work,protocol=protocol,integrity=integrity,data_ordering=ordering,capture=evidence,cache_opportunity=cache,sourcec=phases,terminal_snapshots=terminal,retained_copy=retention,checker_profile=profile_summary,cancelled_snapshots_drained=None,cancelled_snapshot_counter_scope='UNOBSERVED: new diagnostic printf remains verbose-gated in this build; zero captured lines is not a zero event count')
    if manifest['design']=='native':
        records=stable.parse_events(run/'safe_chain_events.tsv')
        allocations=[r for r in records if r['kind']==2 and r['nums'][0]]
        svb_allocations=[r for r in records if r['kind']==32]
        cap=json.loads((run/'capture_summary.json').read_text())
        if allocations or svb_allocations:errors.append('Native mode generated protected packages or versions')
        if not cap['mandatory_evidence_complete']:errors.append('Native observation incomplete')
        out['native_evidence']={'package_allocations':len(allocations),'SVB_allocations':len(svb_allocations),'capture_complete':cap['mandatory_evidence_complete'],'scope':manifest['software']['native_scope']}
    out['status']='FAIL'if errors else 'PASS';dump(run/'analysis.json',out);return out
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('run',type=Path);args=p.parse_args();r=analyze(args.run);print(json.dumps({k:r[k]for k in ['run_id','status','ROI_cycles','host_wall_seconds_simulation_cost','errors']},indent=2));raise SystemExit(r['status']!='PASS')
