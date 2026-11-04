#!/usr/bin/env python3
"""Wait for untouched Candidate 2 driver, fill unrun workloads, preserve evidence.

The original driver's performance threshold can skip the full comparison. The
current user explicitly requests all four workloads. Reuse every completed test
and launch the missing suite only after the original driver has terminated.
"""
import csv
import datetime
import hashlib
import io
import json
import math
import os
from pathlib import Path
import shutil
import subprocess
import sys
import time
import traceback

ROOT=Path(__file__).resolve().parents[3]
OUT=ROOT/'slowdown/recovery_perf_20261104'
RESCUE=Path('/data1/gzh/EC-opt4-recovery-rescue')
R=RESCUE/'slowdown/recovery_perf_20261104'
C1=Path('/data1/gzh/EC-opt4-recovery-perf/slowdown/recovery_perf_20261104/runs/regressions_20261104_034748_d5167f/comparison.json')
C2STATE=R/'build/overlap_svb_rescue_r2_20261104_042210_dc665532_measurement_d449f8/status.json'
REVISION=R/'build/overlap_svb_rescue_r2_20261104_042210_dc665532/revision.json'
DRIVER=1352340


def read(p):
    return json.loads(p.read_text())


def write(p,value):
    tmp=p.with_name(p.name+'.tmp')
    tmp.write_text(json.dumps(value,indent=2)+'\n');tmp.replace(p)


def alive(pid):
    try:
        stat=Path(f'/proc/{pid}/stat').read_text()
        return stat[stat.rfind(')')+2] != 'Z'
    except FileNotFoundError: return False


def sha(p):
    h=hashlib.sha256()
    with p.open('rb') as f:
        for chunk in iter(lambda:f.read(1048576),b''):h.update(chunk)
    return h.hexdigest()


def run(work,state,name,argv):
    log=work/(name+'.log')
    with log.open('xb') as f:
        p=subprocess.Popen(argv,cwd=RESCUE,stdout=f,stderr=subprocess.STDOUT)
        state['active_child']=dict(phase=name,pid=p.pid,command=argv,log=str(log))
        write(work/'status.json',state)
        rc=p.wait()
    state.pop('active_child',None)
    state[name]=dict(exit_status=rc,log=str(log))
    write(work/'status.json',state)
    assert rc==0,(name,rc,str(log))
    return log


def make_report(work,state,c1,c2):
    rows=[]
    for label,c in [('Candidate 1',c1),('Candidate 2 (C1 + rescue)',c2)]:
        for n,v in c['benchmarks'].items():
            rows.append(dict(candidate=label,workload=n,native=v['native_cycles'],check=v['check_cycles'],
                baseline=v['frozen_correction_cycles'],cycles=v['candidate_correction_cycles'],
                correction_check=v['candidate_correction_check'],correction_native=v['candidate_correction_cycles']/v['native_cycles'],
                reduction_percent=100*v['relative_ROI_reduction']))
        b=c['bfs']
        rows.append(dict(candidate=label,workload='GAPBS BFS',native=b['native_cycles'],check=None,
            baseline=b['frozen_correction_cycles'],cycles=b['result']['ROI_cycles'],correction_check=None,
            correction_native=b['candidate_correction_native'],reduction_percent=100*b['relative_ROI_reduction']))
    write(work/'exact_results.json',rows)
    f=io.StringIO();w=csv.DictWriter(f,fieldnames=list(rows[0]));w.writeheader();w.writerows(rows)
    (work/'exact_results.csv').write_text(f.getvalue())
    # This choice is explicitly performance-only; actual recovery is blocked.
    deltas={n:c2['benchmarks'][n]['candidate_correction_cycles']/v['candidate_correction_cycles']-1 for n,v in c1['benchmarks'].items()}
    deltas['bfs']=c2['bfs']['result']['ROI_cycles']/c1['bfs']['result']['ROI_cycles']-1
    key=['canneal_project400','streamcluster_project64']
    geomean=math.prod(1+v for v in deltas.values())**0.25
    key_geomean=math.prod(1+deltas[n] for n in key)**0.5
    better=all(deltas[n]<=0.01 for n in deltas) and geomean<1 and key_geomean<1
    winner=c2 if better else c1
    hardware=winner['revision']['canonical_hardware_commit']
    state.update(state='COMPLETE_RECOVERY_NOT_VALIDATED',best_performance_commit=hardware,
        candidate_two_relative_to_one=deltas,recovery_acceptance='BLOCKED_NO_PROVEN_ARCHITECTURAL_ROLLBACK',
        performance_selection_rule=dict(maximum_workload_regression=0.01,four_workload_geomean_ratio=geomean,
            canneal_streamcluster_geomean_ratio=key_geomean,combined_passes=better),
        baseline_commit='a6e63c75947739dfbb411b32bfe0eb5ed55c5bb1',baseline_preserved=True)
    selected=winner['benchmarks']
    stream=selected['streamcluster_project64']
    canneal=selected['canneal_project400']
    counts=stream['stall_profile']['groups']['53'].get('counts',{})
    sampled=counts.get('cycles')
    freeze=counts.get('freeze_set_ingress_block')
    legacy=counts.get('legacy_preservation_pending')
    slowest=max(selected,key=lambda name:selected[name]['candidate_correction_check'])
    if slowest=='streamcluster_project64' and sampled and freeze is not None and freeze/sampled>=0.10:
        target='Streamcluster preservation capture and package sealing; decouple its frozen-set lifetime using a bounded versioned queue with explicit recovery and ACK ownership'
    else:
        target=f'{slowest}: collect a complete split of its largest sampled stall before choosing an RTL change'
    state['next_performance_priority']=target
    lines=['# Candidate evaluation and recovery acceptance', '',
        'Best measured performance candidate: `'+hardware+'`. **Recovery acceptance is blocked.** No hardware is promoted as a validated rollback implementation.', '',
        'The original baseline remains `a6e63c75947739dfbb411b32bfe0eb5ed55c5bb1`; its existing tag and read-only backup are unchanged.', '',
        'Candidate 2 already combines Candidate 1’s checker ICache change with full-SVB fallback rescue. No third additive implementation is needed.', '',
        'Performance selection requires a lower four-workload geometric mean, a lower Canneal/Streamcluster geometric mean, and no workload regression over 1%. Recovery acceptance remains a separate mandatory gate.', '',
        '| Candidate | Workload | Frozen Correction | Candidate ROI | Correction/Check | Correction/Native | Reduction |',
        '|---|---|---:|---:|---:|---:|---:|']
    for r in rows:
        cc=f"{r['correction_check']:.9f}" if r['correction_check'] is not None else 'N/A'
        lines.append(f"| {r['candidate']} | {r['workload']} | {r['baseline']:,} | {r['cycles']:,} | {cc} | {r['correction_native']:.9f} | {r['reduction_percent']:.6f}% |")
    lines += ['', 'Final selection and next priority:', '',
        f"Canneal / Check = {canneal['candidate_correction_check']:.9f}; Streamcluster / Check = {stream['candidate_correction_check']:.9f} for the selected performance candidate.",
        ('Canneal has already met the 1.2× Check target.' if canneal['candidate_correction_check']<=1.2 else 'Canneal has not reached the 1.2× Check target.'),
        f'After implementing and validating architectural recovery, prioritize {target}.',
        f'Selected Streamcluster sampled cycles={sampled}, freeze-set ingress exposure={freeze}, legacy-preservation pending exposure={legacy}. These overlap and are not additive savings.', '',
        '| C2 sampled main-cycle exposure | Canneal | Streamcluster |', '|---|---:|---:|']
    for group,key in [('53','freeze_set_ingress_block'),('53','legacy_preservation_pending'),('53','release_ack_pending'),('53','mshr_admission_block'),('54','refill_beats'),('54','mshr_active'),('54','svb_full_cycles'),('55','rescue_handoffs')]:
        values=[c2['benchmarks'][n]['stall_profile']['groups'].get(group,{}).get('counts',{}).get(key,'N/A') for n in ['canneal_project400','streamcluster_project64']]
        lines.append(f'| {key} | {values[0]} | {values[1]} |')
    fault_summaries=[]
    for p in sorted((OUT/'build/evidence_20261104').glob('*injected_failure.json')):
        fault=read(p)
        fault_summaries.append(dict(hardware_commit=fault['hardware_commit'],injection=fault['injection'],
            accepted_fail=fault['accepted_fail'],detection_and_accepted_FAIL=fault['detection_and_accepted_FAIL'],
            restoration_validated=fault['restoration_validated']))
    lines += ['', 'BFS has no matching frozen Check-only measurement in this experiment; no ratio is inferred. Native is 1,001,675 cycles. PARSEC Native/Check denominators and exact floating-point ratios are in exact_results.json.', '',
        'All performance comparisons require successful matching ELF, application instruction count and output, complete checker work, and existing protocol/integrity/ACK validation. These are no-fault performance checks and do not establish recovery.', '',
        '## Mechanism and recovery evidence checkpoint', '',
        'The following analysis was recorded after Canneal completed and before the remaining suite. The final table and selected-candidate counters above supersede pending performance statements in this checkpoint.', '',
        (OUT/'MECHANISM_AND_RECOVERY.md').read_text(), '',
        '## Reproducibility', '',
        f'Candidate 1 comparison: `{C1}`.', f'Candidate 2 comparison: `{state["candidate_two_comparison"]}`.',
        'Original backup: `/data1/gzh/EC-backups/opt4-parsec3-pre-rescue-20261104/`.',
        'Performance milestone sources and evidence: `/data1/gzh/EC-backups/opt4-recovery-candidates-20261104/`.',
        'No recovery-validated best-version tag is created because the required restoration proof is absent. Existing candidate tags preserve the optimization milestones without changing the original baseline.']
    lines += ['', 'Completed injected fault observations (restoration remains a mandatory separate gate):', '',
        '```json',json.dumps(fault_summaries,indent=2),'```']
    (work/'REPORT.md').write_text('\n'.join(lines)+'\n')
    write(work/'status.json',state)
    (OUT/'LATEST_EVALUATION.txt').write_text(str(work)+'\n')


def preserve(work,state):
    stamp=datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%d_%H%M%S')
    backup=Path('/data1/gzh/EC-backups')/('opt4-recovery-validation-'+stamp)
    backup.mkdir()
    # Preserve complete new fault evidence and exact final comparisons. Existing
    # immutable candidate/source/binary backups remain referenced, never changed.
    shutil.copytree(work,backup/'evaluation')
    shutil.copy2(OUT/'MECHANISM_AND_RECOVERY.md',backup/'MECHANISM_AND_RECOVERY.md')
    shutil.copy2(C1,backup/'candidate1_comparison.json')
    shutil.copy2(Path(state['candidate_two_comparison']),backup/'candidate2_comparison.json')
    # New C2 measurements were not present in the earlier candidate backup.
    c2=read(Path(state['candidate_two_comparison']))
    for name,value in c2['benchmarks'].items():
        source=Path(value['test']['run'])
        assert read(source/'run_manifest.json').get('exit_status')==0
        shutil.copytree(source,backup/'candidate2_runs'/name)
    bfs=Path(c2['bfs']['test']['run'])
    shutil.copytree(bfs,backup/'candidate2_runs/bfs')
    for label,revision in [('candidate1',Path('/data1/gzh/EC-opt4-recovery-perf/slowdown/recovery_perf_20261104/build/overlap_checker_icache4k_20261104_021411_630679e4/revision.json')),('candidate2',REVISION)]:
        sealed=read(revision)
        # Derive the worktree from the absolute sealed artifact path.
        source_root=Path('/data1/gzh/EC-opt4-recovery-perf') if label=='candidate1' else RESCUE
        dest=backup/'sealed_hardware'/label;dest.mkdir(parents=True)
        shutil.copy2(revision,dest/'revision.json')
        binary=source_root/sealed['simulator']
        assert sha(binary)==sealed['simulator_sha256']
        shutil.copy2(binary,dest/'simulator-chipyard-v1Config')
        libraries=subprocess.check_output(['ldd',str(binary)],text=True)
        (dest/'ldd.txt').write_text(libraries)
        for line in libraries.splitlines():
            fields=line.split()
            original=Path(fields[2]) if len(fields)>2 and fields[1]=='=>' else Path(fields[0]) if fields and fields[0].startswith('/') else None
            if original and original.is_file():
                target=dest/'shared_libraries'/original.name;target.parent.mkdir(exist_ok=True)
                shutil.copy2(original,target)
        shutil.copytree(source_root/'chipyard/generators/testchipip/src/main/resources/dramsim2_ini',dest/'dramsim2_ini')
        build=binary.parents[1]
        shutil.copytree(build/'generated/gen-collateral',dest/'generated_collateral')
        for name in ['verilator_build.log','rtl_generation.log']:
            if (build/name).exists():shutil.copy2(build/name,dest/name)
        shutil.copy2(source_root/sealed['build_manifest'],dest/'run_manifest.json')
        manifest=read(source_root/sealed['build_manifest'])
        for group in ['hardware_sha256','restored_resource_sha256']:
            for source,digest in manifest['source'][group].items():
                original=source_root/source
                assert sha(original)==digest,(source,'source seal mismatch; refuse backup')
                target=dest/'source'/source;target.parent.mkdir(parents=True,exist_ok=True)
                shutil.copy2(original,target)
    subprocess.run(['git','bundle','create',str(backup/'candidate_commits.bundle'),
        'refs/tags/opt4-recovery-candidate1-icache4k-20261104','refs/tags/opt4-recovery-candidate2-rescue-r2-20261104',
        '^a6e63c75947739dfbb411b32bfe0eb5ed55c5bb1'],cwd=ROOT,check=True)
    shutil.copytree(OUT/'scripts',backup/'scripts',ignore=shutil.ignore_patterns('__pycache__'))
    for fault in (OUT/'build').glob('real_checker_fault_*'):
        shutil.copytree(fault,backup/fault.name)
    shutil.copytree(OUT/'build/evidence_20261104',backup/'mechanism_profiles')
    paths=[p for p in backup.rglob('*') if p.is_file()]
    manifest={str(p.relative_to(backup)):dict(bytes=p.stat().st_size,sha256=sha(p)) for p in paths}
    write(backup/'MANIFEST.json',manifest)
    assert all(sha(backup/k)==v['sha256'] for k,v in manifest.items())
    write(backup/'BACKUP_COMPLETE.json',dict(files=len(paths),verified=True,recovery_validated=False,
        original_baseline_preserved=True,best_performance_commit=state['best_performance_commit']))
    for p in backup.rglob('*'):
        p.chmod(0o555 if p.is_dir() else 0o444)
    backup.chmod(0o555)
    state['evidence_backup']=str(backup);write(work/'status.json',state)
    with (work/'REPORT.md').open('a') as f:
        f.write('\nVerified read-only evaluation backup: `'+str(backup)+'`.\n')


def main():
    stamp=datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%d_%H%M%S')
    work=OUT/'runs'/('complete_comparison_'+stamp);work.mkdir(parents=True)
    state=dict(state='WAIT_UNTOUCHED_CANDIDATE2',pid=os.getpid(),candidate2_status=str(C2STATE),start_utc=stamp)
    write(work/'status.json',state)
    print('EVALUATION_DIRECTORY='+str(work),flush=True)
    try:
        # Neither read-only polling nor this script sends any signal to the job.
        while alive(DRIVER): time.sleep(30)
        s=read(C2STATE)
        state['original_candidate2_terminal_state']=s['state'];write(work/'status.json',state)
        assert s.get('canneal',{}).get('ROI_cycles'), 'Original Canneal did not validate; preserve failure, never relaunch it'
        suite=s.get('regressions',{}).get('suite')
        if suite is None:
            # Also detect any separately launched suite to prevent duplicate tests.
            matches=[]
            for p in (R/'runs').glob('regressions_*/status.json'):
                v=read(p)
                if v.get('revision')==str(REVISION):matches.append(p.parent)
            assert len(matches)<=1, 'Multiple suites need manual evidence reconciliation'
            if matches:
                suite=str(matches[0]);assert read(Path(suite)/'status.json')['state']=='PASS'
            else:
                state['state']='COMPLETE_REQUESTED_CROSS_WORKLOAD_COMPARISON';write(work/'status.json',state)
                log=run(work,state,'remaining_workloads',[sys.executable,str(R/'scripts/run_regressions.py'),str(REVISION),'--reuse-canneal',s['canneal']['run']])
                found=[l.split('=',1)[1] for l in log.read_text().splitlines() if l.startswith('SUITE_DIRECTORY=')]
                assert len(found)==1;suite=found[0]
        comparison=Path(suite)/'comparison.json'
        if not comparison.exists():
            run(work,state,'compare',[sys.executable,str(R/'scripts/compare_results.py'),suite])
        c1,c2=read(C1),read(comparison)
        assert c1['status']==c2['status']=='PASS'
        state['candidate_two_comparison']=str(comparison)
        # Fault logs must also be complete before sealing the evidence backup.
        from summarize_recovery_probe import summary
        from profile_legacy_waits import profile
        for p in (OUT/'build').glob('real_checker_fault_*/manifest.json'):
            while alive(read(p).get('pid',0)):time.sleep(30)
            # Failed launcher directories have no manifest and are ignored.
            fault=summary(p.parent)
            write(OUT/'build/evidence_20261104'/(p.parent.name+'_injected_failure.json'),fault)
        for name,value in c2['benchmarks'].items():
            write(work/(name+'_waits.json'),profile(Path(value['test']['run'])))
        make_report(work,state,c1,c2)
        preserve(work,state)
        (OUT/'LATEST_EVALUATION.txt').write_text(str(work)+'\n')
        print(json.dumps(state),flush=True)
    except BaseException:
        state.update(state='FAILED_EVIDENCE_PRESERVED',error=traceback.format_exc())
        write(work/'status.json',state);print(state['error'],flush=True);raise


if __name__=='__main__':main()
