#!/usr/bin/env python3
"""Cached directed tests -> one pilot -> main input -> selective final regression.

Stops on any correctness failure. Performance results remain recovery-provisional.
No baseline/C1/C2 simulations are launched. A reservation forbids implicit retries.
"""
import datetime
import importlib.util
import json
import os
from pathlib import Path
import subprocess
import sys
import time
import traceback
import uuid
import experiment_cache as cache

ROOT=cache.ROOT
REC=ROOT/'slowdown/recovery_perf_20261104'
AREA=ROOT/'slowdown/parsec_evaluation_20261103'
OUT=cache.OUT/'runs'/('screen_'+datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%d_%H%M%S_')+uuid.uuid4().hex[:6])
STATE=dict(state='STARTED',pid=os.getpid(),results={},tests={},recovery_acceptance=False)


def save():
    p=OUT/'status.tmp';p.write_text(json.dumps(STATE,indent=2)+'\n');p.replace(OUT/'status.json')
    print('STATE='+STATE['state'],flush=True)


def command(name,argv):
    log=OUT/(name+'.log')
    with log.open('x') as f:
        rc=subprocess.call([str(x) for x in argv],cwd=ROOT,stdout=f,stderr=subprocess.STDOUT)
    if rc:raise RuntimeError(f'{name}: exit {rc}; evidence {log}')
    return log


def directed(name,script,target,inputs):
    expected=dict(kind=name,inputs={str(p):cache.sha(p) for p in [script]+inputs},
                  verilator=subprocess.check_output(['verilator','--version'],text=True).strip())
    key=cache.digest(expected)
    with cache.locked():
        index=cache.discover()
        old=next((x for x in index['directed_tests'] if x['key']==key),None)
        if old:
            if old['status']=='PASS' and Path(old['log']).exists() and cache.sha(old['log'])==old['log_sha256']:
                STATE['tests'][name]=dict(reused=True,**old);return
            raise RuntimeError(f'Prior directed test exists, do not retry implicitly: {old}')
        entry=dict(key=key,identity=expected,status='RUNNING',pid=os.getpid(),log=str(OUT/(name+'.log')))
        index['directed_tests'].append(entry);cache.save(index)
    try:
        log=command(name,[sys.executable,script,target]);entry.update(status='PASS',log_sha256=cache.sha(log))
    except BaseException:
        entry['status']='FAIL';raise
    finally:
        with cache.locked():
            index=cache.read(cache.INDEX)
            index['directed_tests']=[entry if x['key']==key else x for x in index['directed_tests']];cache.save(index)
        STATE['tests'][name]=entry;save()


def perf(workload,revision,source,cycles):
    seal=cache.read(revision)
    if workload=='bfs':
        soft=Path('/data1/gzh/EC/check/software_common_builds/gapbs512_20261023_03')
        elf,loadmem=soft/'test.riscv',soft/'test.loadmem_hex'
        sw=dict(benchmark='gapbs_bfs512_8192_source0',roi_scope='BFS_AMOW_plus_BFS_plus_STOP')
        script=REC/'scripts/run_bfs_profile.py';argv=[sys.executable,script,revision]
    else:
        soft=AREA/'build'/workload;sw=cache.read(soft/'build.manifest.json')
        elf,loadmem=soft/'protected.riscv',soft/'protected.loadmem_hex'
        script=REC/'scripts/run_profile.py';argv=[sys.executable,script,workload,revision,'--max-cycles',str(cycles)]
    ini=ROOT/'chipyard/generators/testchipip/src/main/resources/dramsim2_ini'
    expected=dict(hardware={k:source[k] for k in ['hardware_sha256','restored_resource_sha256','config','n_svb_entries','checker_harts']},
        simulator_sha256=seal['simulator_sha256'],benchmark=workload,design='correction',workload_input=sw,
        elf_sha256=cache.sha(elf),loadmem_sha256=cache.sha(loadmem),seed=1,max_cycles=cycles,
        roi_scope=sw['roi_scope'],measurement=dict(runner_sha256=cache.sha(script),event_limit=64*1024*1024,
        compact_capture_sha256=cache.sha(ROOT/'slowdown/optimization_4_svb/scripts/compact_capture.py'),
        analyzer_sha256=cache.sha(AREA/'scripts/analyze_pilot.py'),full_checker_work=True),
        dramsim_ini={str(p.relative_to(ini)):cache.sha(p) for p in ini.rglob('*') if p.is_file()},
        settings=['-s','1','+cycle-count','+safe-chain-events','+safe-chain-budgeted','+cache-opportunity','+dramsim','+loadmem_addr=80000000'])
    key=cache.digest(expected)
    with cache.locked():
        hit=cache.exact_run(expected)
        if hit:return dict(run=hit['run'],ROI_cycles=hit['roi_cycles'],reused=True,status='PASS')
        index=cache.read(cache.INDEX)
        previous=next((x for x in index['launches'] if x['key']==key),None)
        if previous:raise RuntimeError('Prior matching simulation exists; no implicit retry: '+str(previous))
        entry=dict(key=key,identity=expected,status='RUNNING',pid=os.getpid(),log=str(OUT/(workload+'.log')))
        index['launches'].append(entry);cache.save(index)
    STATE['state']='RUNNING_'+workload;save()
    try:
        log=command(workload,argv)
        paths=[x.split('=',1)[1] for x in log.read_text().splitlines() if x.startswith('RUN_DIRECTORY=')]
        assert len(paths)==1,paths
        run=Path(paths[0]);m=cache.read(run/'run_manifest.json')
        result=cache.read(run/('result.json' if workload=='bfs' else 'analysis.json'))
        assert result['status']=='PASS' and m['exit_status']==0,result
        full=cache.read(run/'full_checker_work.json') if workload=='bfs' else result['full_session_checker_work']
        assert full['complete'],full
        m['experiment_cache_identity']=expected
        (run/'run_manifest.json').write_text(json.dumps(m,indent=2)+'\n')
        entry.update(status='PASS',run=str(run),ROI_cycles=result['ROI_cycles'])
        STATE['results'][workload]=dict(status='PASS',run=str(run),ROI_cycles=result['ROI_cycles'],full_checker_work=full)
        return STATE['results'][workload]
    except BaseException:
        entry['status']='FAIL';raise
    finally:
        with cache.locked():
            index=cache.read(cache.INDEX);index['launches']=[entry if x['key']==key else x for x in index['launches']];cache.save(index)
        save()


def main():
    OUT.mkdir(parents=True,exist_ok=False)
    latest=cache.read(cache.OUT/'LATEST.json');latest.update(screen_pid=os.getpid(),screen_status=str(OUT/'status.json'))
    (cache.OUT/'LATEST.json').write_text(json.dumps(latest,indent=2)+'\n');save()
    while True:
        with cache.locked():index=cache.read(cache.INDEX)
        builds=index['local_builds'];assert builds,builds
        build=builds[-1]
        if build['status']!='RUNNING':break
        assert Path('/proc/'+str(build['pid'])).exists(),'Build supervisor exited without final status'
        STATE['state']='WAIT_BUILD';save();time.sleep(30)
    assert build['status']=='PASS',build
    bid=build['build_id'];generated=ROOT/'slowdown/optimization_6_overlap/build'/bid/'generated'
    STATE['build']=build;STATE['state']='DIRECTED_TESTS';save()
    svb=generated/'gen-collateral/SpeculativeVersionBuffer.sv';dc=generated/'gen-collateral/BoomNonBlockingDCache.sv'
    directed('svb_retention',REC/'scripts/test_svb_retention.py',generated,[svb,REC/'scripts/svb_retention_driver.cpp'])
    directed('rescue_gate',REC/'scripts/test_emitted_rescue_gate.py',dc,[dc])
    directed('rescue_pulses',REC/'scripts/test_emitted_rescue_pulses.py',dc,[dc])
    directed('epoch_boundary',REC/'scripts/test_epoch_private.py',dc,[dc,AREA/'scripts/test_emitted_epoch_cone.py',AREA/'scripts/emitted_epoch_cone.cpp'])
    spec=importlib.util.spec_from_file_location('seal',REC/'scripts/seal_candidate.py')
    mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod)
    revision=REC/'build'/bid/'revision.json'
    if not revision.exists():revision=mod.seal(bid)
    STATE['revision']=str(revision)
    for workload in ['streamcluster_simdev','streamcluster_project64','canneal_project400','blackscholes_project64']:
        dest=AREA/'build'/workload
        if not dest.exists():dest.parent.mkdir(parents=True,exist_ok=True);dest.symlink_to(Path('/data1/gzh/EC-opt4-recovery-perf/slowdown/parsec_evaluation_20261103/build')/workload,target_is_directory=True)
    source=cache.read(REC/'build'/bid/'run_manifest.json')['source']
    pilot=perf('streamcluster_simdev',revision,source,2200000)
    # No old-hardware pilot is rerun. Main-input profiling supports screening
    # even when the pilot benefit is small; reject a large pilot regression.
    if pilot['ROI_cycles']>1452774*1.01:
        STATE['state']='REJECTED_PILOT_REGRESSION';save();return 0
    stream=perf('streamcluster_project64',revision,source,5500000)
    STATE['streamcluster_vs_C2_reduction']=1-stream['ROI_cycles']/3441485
    if stream['ROI_cycles']>=3441485*0.99:
        STATE['state']='REJECTED_MAIN_GAIN_BELOW_ONE_PERCENT';save();return 0
    canneal=perf('canneal_project400',revision,source,2500000)
    if canneal['ROI_cycles']>489737*1.005:
        STATE['state']='REJECTED_CANNEAL_REGRESSION';save();return 0
    perf('blackscholes_project64',revision,source,8000000)
    perf('bfs',revision,source,3000000)
    STATE['state']='PERFORMANCE_SCREEN_COMPLETE_RECOVERY_UNVALIDATED';save()
    return 0


if __name__=='__main__':
    try:rc=main()
    except BaseException:
        STATE['state']='FAILED';STATE['error']=traceback.format_exc()
        if OUT.exists():save()
        raise
    finally:
        if OUT.exists():
            # Produce a self-contained partial/rejection report as well.
            with (OUT/'report_generation.log').open('a') as f:
                subprocess.call([sys.executable,str(cache.OUT/'summarize_results.py'),str(OUT/'status.json')],cwd=ROOT,stdout=f,stderr=subprocess.STDOUT)
    sys.exit(rc)
