#!/usr/bin/env python3
"""Validated measurements only. Missing observation is N/A, never zero."""
import csv,json,math,statistics
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];OUT=ROOT/'slowdown/parsec_evaluation_20261103'
NA='N/A'
FIELDS=['benchmark','input','design','run_id','hardware_commit','simulator_sha256','elf_sha256','native_model','roi_start','roi_end','roi_cycles','total_harness_cycles','roi_instructions','roi_IPC','host_seconds','target_cycles_per_host_second','packages','PASS','FAIL','CANCELLED','checked_instructions','checked_loads','checked_stores','checker_active_capacity_lower_bound','checker_idle_cycles','package_transition_bubbles','checker_frontend_starvation_local_cycles','package_queue_empty_cycles','package_queue_full_cycles','checker_backpressure_BOOM_cycles','package_dispatch_stalls','result_queue_stalls','AsyncQueue_full_cycles','AsyncQueue_empty_cycles','SourceC_ACK_wait_cycles','store_result_wait_cycles','verification_result_wait_cycles','L1_load_hits','L1_load_misses','L1_store_hits','L1_store_misses','L1_aggregate_hits','L1_aggregate_misses','L1_refills','L1_evictions','L1_probe_evictions','L1_writebacks','SVB_created','SVB_completed','SVB_coalesced','SVB_discarded','SVB_retained_final','SVB_peak','SVB_peak_line_depth','version_management_block_cycles','protected_replacement_stalls','demand_blocked_by_version_cycles','safe_watermark_advances','safe_watermark_stall_cycles','prevented_invalidation_refetch_events','snapshot_created','snapshot_release','snapshot_flush_drop','ACK_count','L2_accesses','L2_misses','memory_read_requests','memory_write_requests','memory_read_bytes','memory_write_bytes','counter_window_cycles','outstanding_packages_at_app_end','last_verification_cycle','drain_tail_cycles','app_start_to_verified_cycles','correct']
def dump(p,x):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(json.dumps(x,indent=2)+'\n')
def csvout(p,rows,fields):
    p.parent.mkdir(parents=True,exist_ok=True)
    with p.open('w',newline='')as f:w=csv.DictWriter(f,fieldnames=fields,lineterminator='\n');w.writeheader();w.writerows(rows)
def mdtable(fields,rows):return '\n'.join(['|'+'|'.join(fields)+'|','|'+'|'.join(['---']*len(fields))+'|',*['|'+'|'.join(str(r.get(k,NA))for k in fields)+'|'for r in rows]])
def metrics(run,m,a):
    r={k:NA for k in FIELDS};r.update(benchmark=m['software']['benchmark'],input=m['software']['input_class'],design=m['design'],run_id=m['run_id'],roi_cycles=m['roi_cycles'],total_harness_cycles=m['total_harness_cycles'],roi_instructions=m['roi_instret'],roi_IPC=m['ipc'],host_seconds=m['host_wall_seconds'],correct=a['status'])
    r.update(hardware_commit=m.get('canonical_hardware_commit') or m['build_evidence'].get('base_commit',NA),simulator_sha256=m['simulator_sha256'],elf_sha256=m['elf_sha256'],native_model=m.get('native_model','correction_auxiliary'if m['design']=='native'else NA),roi_start=m['roi_start'],roi_end=m['roi_end'],target_cycles_per_host_second=m['total_harness_cycles']/m['host_wall_seconds'])
    if m['design']=='native':r.update(packages=NA if m.get('native_model')=='detection'else 0,SVB_created=0)
    if m['design']!='correction':return r
    p=a['packages'];work=a['full_session_checker_work'];cp=a['checker_profile'];sc=a['sourcec']['counters'];cache=a['cache_opportunity'];acc=cache['entry_accounting'];prot=a['protocol']
    r.update(packages=p['generated'],PASS=p['PASS'],FAIL=p['FAIL'],CANCELLED=p['CANCELLED'],checker_active_capacity_lower_bound=cp['observed_active_capacity_fraction'],checker_frontend_starvation_local_cycles=cp['local_priority_cycles']['instruction_starvation'],SourceC_ACK_wait_cycles=sc['wait_ack_cycles'],SVB_created=acc['allocations'],SVB_completed=acc['completions'],SVB_coalesced=acc['coalesced'],SVB_discarded=acc['discarded'],SVB_retained_final=acc['occupancy'],snapshot_created=acc['allocations'],snapshot_release=prot['svb_promotions_issued'],snapshot_flush_drop=acc['discarded'],ACK_count=prot['release_acks_matched'],counter_window_cycles=sc['sample_cycles'],outstanding_packages_at_app_end=p['outstanding_at_app_end'],last_verification_cycle=p['ROI_work_last_verification_cycle'],drain_tail_cycles=p['ROI_work_drain_tail_cycles'],app_start_to_verified_cycles=p['ROI_work_start_to_verified_cycles'])
    if work['complete']:
        for k in ['checked_instructions','checked_loads','checked_stores']:r[k]=work[k]
    for model in cache['models']:
        if model['level']==1:
            r.update(L1_aggregate_hits=model['actual']['hit'],L1_aggregate_misses=model['actual']['miss'],L1_probe_evictions=model['probe_evictions'],L1_writebacks=model['writebacks'])
        if model['level']==2:
            r.update(L2_accesses=model['actual']['access'],L2_misses=model['actual']['miss'],memory_read_requests=model['dram_facing_reads'],memory_write_requests=model['dram_facing_writes'],memory_read_bytes=model['dram_facing_read_bytes'],memory_write_bytes=model['dram_facing_write_bytes'])
    from analyze_pilot import stable
    events=stable.parse_events(run/'safe_chain_events.tsv')
    ends=[x for x in events if x['kind']==16 and x['hart']==0]
    if ends:r.update(SVB_peak=ends[-1]['nums'][9],SVB_peak_line_depth=ends[-1]['nums'][10])
    ends=[x for x in events if x['kind']==31 and x['hart']==0]
    if ends:r['version_management_block_cycles']=ends[-1]['nums'][2]
    c=a['terminal_snapshots']['snapshots'].get('50:0',{}).get('counters',{})
    r['store_result_wait_cycles']=c.get('terminal_blocked_cycles',NA)
    r['result_queue_stalls']=sum(h.get('lifecycle_local_cycles',{}).get('result_queue_backpressure',0) for h in cp['harts']) if all(h.get('lifecycle_captured_packages',0)>0 for h in cp['harts']) else NA
    return r
def main():
    rows=[];runs={};excluded=[]
    revision_path=OUT/'hardware_revision.json';revision=json.loads(revision_path.read_text()) if revision_path.exists() else {}
    for run in sorted((OUT/'runs').iterdir()):
        mp=run/'run_manifest.json';ap=run/'analysis.json'
        if not mp.exists():continue
        m=json.loads(mp.read_text())
        if not ap.exists()or(run/'EXCLUDED.json').exists():
            excluded.append({'run_id':run.name,'state':m['state'],'reason':json.loads((run/'EXCLUDED.json').read_text())['reason']if(run/'EXCLUDED.json').exists()else'analysis pending or run incomplete'});continue
        a=json.loads(ap.read_text())
        if a['status']!='PASS':excluded.append({'run_id':run.name,'state':'INVALID','reason':str(a['errors'])});continue
        r=metrics(run,m,a);rows.append(r);runs[run.name]=(m,a,r)
    csvout(OUT/'counters/RUNS.csv',rows,FIELDS);dump(OUT/'logs/exclusions.json',excluded)
    selection_path=OUT/'primary_selection.json';selection=json.loads(selection_path.read_text())if selection_path.exists()else{}
    selected={rid for ids in selection.values() for rid in ids.values()}
    dump(OUT/'logs/primary_exclusions.json',[{'run_id':rid,'reason':'Auxiliary/pilot/repeat measurement outside the explicit main input selection; retained as raw evidence'}for rid in runs if rid not in selected])
    comparisons=[];equivalence=[];correctness=[];mechanisms=[];drains=[]
    for workload,ids in selection.items():
        if not all(ids.get(k) in runs for k in ['native','check','correction']):continue
        triplet={k:runs[ids[k]]for k in ['native','check','correction']}
        same_inst=len({x[0]['roi_instret']for x in triplet.values()})==1
        same_output=len({tuple(x[0]['output'])for x in triplet.values()})==1
        same_input=len({json.dumps({k:x[0]['software'].get(k)for k in ['input_sha256','parameters','iterations','options']},sort_keys=True)for x in triplet.values()})==1
        same_protected_elf=triplet['check'][0]['elf_sha256']==triplet['correction'][0]['elf_sha256']
        clean=all(x[0].get('evaluation_git_status')==''for x in triplet.values())
        accepted=revision.get('status')=='ACCEPTED' and triplet['correction'][0].get('canonical_hardware_commit')==revision.get('canonical_hardware_commit') and triplet['correction'][0]['simulator_sha256']==revision.get('simulator_sha256') and triplet['native'][0].get('native_model')=='detection' and triplet['native'][0]['simulator_sha256']==triplet['check'][0]['simulator_sha256']
        eq={'workload':workload,'identical_ROI_instructions':same_inst,'identical_output':same_output,'identical_input_and_loops':same_input,'identical_protected_ELF':same_protected_elf,'clean_source_at_launch':clean,'accepted_canonical_hardware':accepted,'valid':all([same_inst,same_output,same_input,same_protected_elf,clean,accepted])};equivalence.append(eq)
        if not eq['valid']:continue
        n,c,o=[triplet[k][0]['roi_cycles']for k in ['native','check','correction']]
        app=triplet['correction'][0]['software']['benchmark'];inp=triplet['correction'][0]['software']['input_class'];nr,cr,orr=[triplet[k][2]for k in ['native','check','correction']]
        comparisons.append(dict(benchmark=app,input=inp,native_ROI=n,check_ROI=c,correction_ROI=o,check_native=c/n,correction_native=o/n,correction_check=o/c,native_baseline_scope='matched detection hardware without recovery datapath, protected session disabled'))
        correctness.append(dict(benchmark=app,input=inp,ROI_instructions=orr['roi_instructions'],check_PASS=cr['PASS'],correction_PASS=orr['PASS'],correction_FAIL=orr['FAIL'],correction_CANCELLED=orr['CANCELLED'],correct='PASS',work_equivalence='PASS',checker_coverage_comparison='N/A: detection has no equivalent accepted-result/work ledger'))
        mechanisms.append(dict(benchmark=app,input=inp,checker_active_capacity_lower_bound=orr['checker_active_capacity_lower_bound'],checker_backpressure_BOOM_cycles=orr['checker_backpressure_BOOM_cycles'],version_management_block_cycles=orr['version_management_block_cycles'],SourceC_ACK_wait_cycles=orr['SourceC_ACK_wait_cycles'],result_queue_stalls=orr['result_queue_stalls'],drain_tail_cycles=orr['drain_tail_cycles'],counter_window_cycles=orr['counter_window_cycles']))
        drains.append(dict(benchmark=app,input=inp,native_app_ROI=n,check_app_ROI=c,correction_app_ROI=o,correction_outstanding_at_app_end=orr['outstanding_packages_at_app_end'],correction_drain_tail=orr['drain_tail_cycles'],correction_start_to_verified=orr['app_start_to_verified_cycles'],check_start_to_verified=NA,app_correction_check=o/c,verified_correction_check=NA))
    fields=['benchmark','input','native_ROI','check_ROI','correction_ROI','check_native','correction_native','correction_check','native_baseline_scope']
    csvout(OUT/'RESULTS.csv',comparisons,fields);dump(OUT/'counters/work_equivalence.json',equivalence)
    for name,data,columns in [('CORRECTNESS',correctness,['benchmark','input','ROI_instructions','check_PASS','correction_PASS','correction_FAIL','correction_CANCELLED','correct','work_equivalence','checker_coverage_comparison']),('MECHANISMS',mechanisms,['benchmark','input','checker_active_capacity_lower_bound','checker_backpressure_BOOM_cycles','version_management_block_cycles','SourceC_ACK_wait_cycles','result_queue_stalls','drain_tail_cycles','counter_window_cycles']),('DRAIN',drains,['benchmark','input','native_app_ROI','check_app_ROI','correction_app_ROI','correction_outstanding_at_app_end','correction_drain_tail','correction_start_to_verified','check_start_to_verified','app_correction_check','verified_correction_check'])]:
        csvout(OUT/'counters'/(name+'.csv'),data,columns)
    stats={}
    for ratio in ['check_native','correction_native','correction_check']:
        vals=[r[ratio]for r in comparisons]
        if vals:stats[ratio]={'n':len(vals),'geometric_mean':math.exp(statistics.mean(map(math.log,vals))),'arithmetic_mean':statistics.mean(vals),'median':statistics.median(vals),'min':min(vals),'max':max(vals),'minimum_benchmark':min(comparisons,key=lambda r:r[ratio])['benchmark'],'maximum_benchmark':max(comparisons,key=lambda r:r[ratio])['benchmark']}
    dump(OUT/'counters/summary_statistics.json',stats)
    # Results remain explicitly pending until selected triplets pass every gate.
    text=['# PARSEC characterization','','Native denotes the unprotected execution mode defined in CONFIG.md. Host seconds are simulation cost. Only validated, work-equivalent selected triplets on the accepted hardware revision enter normalized means. Historical pilot rows are not primary comparisons.','',mdtable(fields,comparisons),'','## Statistics','','```json',json.dumps(stats,indent=2),'```','','## Correctness and work equivalence','',mdtable(['benchmark','input','ROI_instructions','check_PASS','correction_PASS','correction_FAIL','correction_CANCELLED','correct'],correctness),'','Detection package counts and checker-work coverage are N/A because this sealed detection model has no equivalent accepted-result/work ledger. Identical protected ELF, application retired instructions, input/loops and output are independently required.','','## Mechanism counters','',mdtable(['benchmark','input','checker_active_capacity_lower_bound','checker_backpressure_BOOM_cycles','version_management_block_cycles','SourceC_ACK_wait_cycles','result_queue_stalls','drain_tail_cycles'],mechanisms),'','Checker activity is a lower bound from fully captured packages inside the ROI. Stall counters cover the recorded hardware traffic window, not necessarily the application ROI; categories can overlap. They do not constitute an additive explanation of slowdown.','','## Application versus verified completion','',mdtable(['benchmark','input','correction_app_ROI','correction_outstanding_at_app_end','correction_drain_tail','correction_start_to_verified','check_start_to_verified','verified_correction_check'],drains),'','The correction drain includes all packages allocated before application end. Detection software session completion is not the same observable and is not substituted for verified completion.','','## Validated raw measurements','',mdtable(['benchmark','input','design','roi_cycles','roi_instructions','roi_IPC','host_seconds','correct'],rows),'','Missing counters are N/A in counters/RUNS.csv. See CONFIG.md for counter-window and partial-package scope. Invalid, aborted and pending runs are listed in logs/exclusions.json. Recovery results are separate in recovery/.','']
    (OUT/'RESULTS.md').write_text('\n'.join(text))
    print(json.dumps({'validated_runs':len(rows),'valid_primary_triplets':len(comparisons),'excluded_or_pending':len(excluded),'stats':stats},indent=2))
if __name__=='__main__':main()
