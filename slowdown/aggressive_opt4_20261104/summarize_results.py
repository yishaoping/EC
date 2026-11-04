#!/usr/bin/env python3
"""Read measured artifacts, report complete means only, preserve provisional work."""
import argparse
import datetime
import json
import math
from pathlib import Path
import subprocess
import tarfile
import experiment_cache as cache

REFERENCE={
 'blackscholes_project64':[5920394,5952831,6165734,6114946,None],
 'streamcluster_project64':[2281930,2499121,3706513,3547466,3441485],
 'canneal_project400':[310942,419398,668878,548437,489737],
 'bfs':[1001675,None,1128052,1125574,1126805]}
ORIGINAL=Path('/data1/gzh/EC-opt4-recovery-rescue/slowdown/parsec_evaluation_20261103/runs/blackscholes_project64_correction_20261104_082501_067a3c42')


def main():
    p=argparse.ArgumentParser();p.add_argument('status',type=Path);args=p.parse_args()
    state=cache.read(args.status);out=args.status.parent
    if (ORIGINAL/'analysis.json').exists():
        m=cache.read(ORIGINAL/'run_manifest.json');a=cache.read(ORIGINAL/'analysis.json')
        if m.get('exit_status')==0 and a.get('status')=='PASS' and a.get('full_session_checker_work',{}).get('complete'):
            REFERENCE['blackscholes_project64'][4]=a['ROI_cycles']
    rows={};profiles={}
    for name,ref in REFERENCE.items():
        result=state.get('results',{}).get(name);new=result['ROI_cycles'] if result else None
        rows[name]=dict(zip(['Native','Check','Frozen','Candidate1','Candidate2'],ref))
        rows[name].update(New=new,New_Native=new/ref[0] if new else None,
            New_Check=new/ref[1] if new and ref[1] else None,
            improvement_vs_C2=1-new/ref[4] if new and ref[4] else None,
            status=result['status'] if result else 'NOT_RUN',run=result.get('run') if result else None)
        if result:
            profile=Path(result['run'])/'stall_profile.json'
            if profile.exists():profiles[name]=cache.read(profile)
    parsec=[k for k in rows if k!='bfs'];means={}
    for col in ['Check','Frozen','Candidate1','Candidate2','New']:
        if all(rows[k][col] is not None for k in parsec):
            means[col+'_Native']=math.prod(rows[k][col]/rows[k]['Native'] for k in parsec)**(1/3)
    if all(rows[k]['New'] for k in parsec):means['New_Check']=math.prod(rows[k]['New']/rows[k]['Check'] for k in parsec)**(1/3)
    summary=dict(state=state['state'],hardware=state.get('revision'),rows=rows,PARSEC_geomeans=means,
        profiles=profiles,directed_tests=state.get('tests'),architectural_recovery='UNVALIDATED; no restored PC/register/memory oracle',
        area_timing='NOT_MEASURED; 17 publication/drain bits plus control; unchanged data capacity/four checkers',
        reference_measurements_reused=18+int(REFERENCE['blackscholes_project64'][4] is not None),
        new_simulations_executed=len(state.get('results',{})),
        strict_C2_fault_probe='Completed exit 0, no RECOVERY_INJECT or accepted FAIL; NOT_EXERCISED, never a rollback pass')
    (out/'results.json').write_text(json.dumps(summary,indent=2)+'\n')
    def fmt(x):return 'pending' if x is None else f'{x:.9f}x'
    lines=['# Opt4 safe snapshot experiment', '', 'State: '+state['state'], '',
        'All new results are recovery-provisional. Normal execution and component publication tests do not prove architectural rollback.', '',
        '| Workload | Native | Check | C2 | New | New/Native | New/Check | Reduction vs C2 |',
        '|---|---:|---:|---:|---:|---:|---:|---:|']
    for k,r in rows.items():
        gain='pending' if r['improvement_vs_C2'] is None else f"{100*r['improvement_vs_C2']:.6f}%"
        lines.append(f"| {k} | {r['Native']} | {r['Check'] or 'N/A'} | {r['Candidate2'] or 'pending'} | {r['New'] or 'pending'} | {fmt(r['New_Native'])} | {fmt(r['New_Check']) if k!='bfs' else 'N/A'} | {gain} |")
    lines+=['','BFS uses the pinned GAPBS512/8192/source0 workload and is excluded from PARSEC means.','',
        'PARSEC geometric means (only complete sets): '+json.dumps(means), '',
        'Measured bottleneck evidence and candidate design: [REPORT.md](../../REPORT.md).', '',
        'Raw per-workload evidence:', '']
    for k,r in rows.items():
        if r['run']:lines.append(f"* {k}: `{r['run']}`")
    if state.get('error'):lines+=['','Failure recorded without automatic retry:','```',state['error'],'```']
    (out/'RESULTS.md').write_text('\n'.join(lines)+'\n')
    # Preserve only a final shortlist with no significant side-workload regression.
    # Tag/backup explicitly say provisional: recovery acceptance remains forbidden.
    eligible=all(r['New'] and r['Candidate2'] for r in rows.values()) and all(
        r['New']<=r['Candidate2']*1.005 for r in rows.values()) and means.get('New_Native',float('inf'))<means.get('Candidate2_Native',0)
    if eligible and state['state']=='PERFORMANCE_SCREEN_COMPLETE_RECOVERY_UNVALIDATED':
        revision=cache.read(Path(state['revision']));commit=revision['canonical_hardware_commit']
        stamp=datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%d_%H%M%S')
        tag='opt4-safe-snapshot-provisional-'+stamp
        subprocess.run(['git','tag','-a',tag,commit,'-m','Measured performance shortlist only; architectural recovery NOT validated'],cwd=cache.ROOT,check=True)
        backup=Path('/data1/gzh/EC-backups')/tag;backup.mkdir(exist_ok=False)
        build=state['build'];source=cache.read(cache.ROOT/'slowdown/recovery_perf_20261104/build'/build['build_id']/'run_manifest.json')['source']
        with tarfile.open(backup/'hardware-and-evidence.tar.gz','w:gz') as tar:
            for rel in set(source['hardware_sha256'])|set(source['restored_resource_sha256']):tar.add(cache.ROOT/rel,arcname=rel)
            tar.add(out,arcname='screen-evidence')
            tar.add(cache.OUT/'REPORT.md',arcname='design-report.md')
            tar.add(cache.ROOT/'slowdown/optimization_6_overlap/runs'/build['build_id'],arcname='build-evidence')
            tar.add(build['simulator'],arcname='simulator-chipyard-v1Config')
            tar.add(Path(state['revision']),arcname='revision.json')
        preservation=dict(tag=tag,commit=commit,backup=str(backup),archive_sha256=cache.sha(backup/'hardware-and-evidence.tar.gz'),recovery_accepted=False)
        (out/'preservation.json').write_text(json.dumps(preservation,indent=2)+'\n')
        (backup/'preservation.json').write_text(json.dumps(preservation,indent=2)+'\n')
    print(json.dumps(dict(results=str(out/'results.json'),report=str(out/'RESULTS.md'),means=means)),flush=True)


if __name__=='__main__':main()
