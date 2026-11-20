#!/usr/bin/python3
"""One useful host-counter run of exact Canneal traffic; never reprograms."""
from pathlib import Path
import csv,fcntl,importlib.util,json,os,re,signal,subprocess,sys,time

C=Path(__file__).resolve().parent
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
L=D/'svb-clock-measurement-fpga-r1-20261112'
BUILD=D/'svb-clock-measurement-build-r1-20261112'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import identity,live,now,read,save,sha
import board_batch as bb
from coverage_first import sample_busy
spec=importlib.util.spec_from_file_location('inherited_svb_admission',W/'candidates/svb-routed-conditional-r7-20261112/application.py')
parent=importlib.util.module_from_spec(spec);spec.loader.exec_module(parent)

def main():
    assert os.geteuid()==0
    parent.policy_check()
    pins=read(C/'run-inputs.json')
    for p,h in pins['files'].items(): assert sha(p)==h,('new input changed',p)
    validation=read(BUILD/'driver-validation.json');assert validation['passed']
    driver=C/'SVBStreamingReplay-xilinx_alveo_u280'
    assert sha(driver)==validation['driver_sha256']
    component=parent.completed_component();assert component
    admission,expected,budget=parent.verify_ready(*component)
    # Small prior directed validation + identical target-control source diff;
    # original exact application full CPU replay and payload-negative stay bound.
    assert sha(C/'StreamingReplay.cc')==validation['source_sha256']
    plan=read(C/'plan.json')
    assert not plan['target_or_model_modified'] and not plan['bitstream_rebuild_required']
    for p,h in plan['inputs'].items():assert sha(p)==h,('plan input changed',p)
    cert=component[1]
    L.mkdir(exist_ok=True)
    instance=(L/'instance.lock').open('a');fcntl.flock(instance,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (L/'run-started.json').exists() and not (L/'result.json').exists(),'preserve existing run'
    state=dict(schema='ec-svb-host-clock-replay/1',**identity(),functional_baseline=parent.BASE,
               board_bdf=bb.TARGET_BDF,board_serial=bb.TARGET_SERIAL,source_id=parent.SID,
               no_reflash=True,deployment_operations=[],complete_opt4=False)
    held=[]
    while True:
        parent.policy_check()
        if not parent.whole_priority() and not sample_busy():
            try:
                for name in ['maintenance-0000_21_00.0.lock','card-0000_21_00.0.lock']:
                    f=(D/'locks'/name).open('a');held.append(f);fcntl.flock(f,fcntl.LOCK_EX|fcntl.LOCK_NB)
                if parent.whole_priority() or sample_busy():raise BlockingIOError()
                check=bb.precheck(target_bdfs=[bb.TARGET_BDF])
                save(L/'pre-run.json',check)
                assert not check['permission_denied'],'complete process visibility required'
                if check['open_devices'] or check['simulation_processes']:raise BlockingIOError()
                latest=read(D/'latest-deployment.json')
                assert latest['bdfs']==[bb.TARGET_BDF] and latest['source_id']==parent.SID
                assert latest['bitstream_sha256']==cert['bitstream_sha256']
                break
            except BlockingIOError:
                for f in held:f.close()
                held=[]
        state.update(status='WAITING_SAFE_21_BOUNDARY',updated_utc=now());save(L/'state.json',state)
        time.sleep(30)
    save(L/'certified-component.json',cert)
    save(L/'driver-validation.json',validation)
    argv=[str(driver),'+permissive','+domain=0000','+bus=21','+device=00','+function=0',
          '+bar=0','+pci-vendor=10ee','+pci-device=903f','+svb-trace='+admission['trace'],
          '+svb-state='+str(L/'target-progress.json'),'+svb-force-all-inputs',
          '+svb-clock-events='+str(L/'fpga-event-intervals.csv'),'+seed=8491167','+permissive-off']
    receipt=dict(utc=now(),argv=argv,bitstream_sha256=cert['bitstream_sha256'],
                 deployment_sha256=sha(D/'latest-deployment.json'),
                 trace=admission['trace'],trace_sha256=admission['trace_sha256'],
                 original_admission_sha256=sha(parent.CPU/'board-admission-ready.json'),
                 driver_sha256=sha(driver),driver_validation_sha256=sha(L/'driver-validation.json'),
                 run_inputs_sha256=sha(C/'run-inputs.json'),deployment_operations=[])
    save(L/'run-started.json',receipt)
    log=L/'hardware-replay.log';start=time.monotonic()
    with log.open('xb',buffering=0) as f:
        child=subprocess.Popen(['/usr/bin/stdbuf','-oL','-eL',*argv],cwd=L,
            stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True,
            env={**os.environ,'LD_LIBRARY_PATH':''})
        active=dict(schema='ec-original-component-run/1',run_id=L.name,run_dir=str(L),
                    configuration=parent.PROFILE,status='RUNNING',board_bdf=bb.TARGET_BDF,
                    board_serial=bb.TARGET_SERIAL,**identity(child.pid))
        save(D/'active-0000_21_00.0.json',active)
        while child.poll() is None:
            state.update(status='RUNNING_REAL_FPGA_CLOCK_MEASUREMENT',child=identity(child.pid),
                         progress=read(L/'target-progress.json'),updated_utc=now(),wall_seconds=time.monotonic()-start)
            save(L/'state.json',state)
            try:child.wait(timeout=30)
            except subprocess.TimeoutExpired:pass
            if child.poll() is None and time.monotonic()-start>min(budget,600):
                os.killpg(child.pid,signal.SIGTERM)
                try:child.wait(timeout=20)
                except subprocess.TimeoutExpired:os.killpg(child.pid,signal.SIGKILL);child.wait()
        os.fsync(f.fileno())
    wall=time.monotonic()-start;txt=log.read_text(errors='replace')
    def summary(marker):
        m=re.search('^'+marker+' (.*)$',txt,re.M)
        return {k:float(v) if '.' in v else int(v) for k,v in (x.split('=',1) for x in m[1].split())} if m else {}
    got=summary('SVB_GG_STREAM_SUMMARY');clock=summary('SVB_CLOCK_SUMMARY')
    keys=[k for k in expected if k!='host_wall_seconds']
    good=child.returncode==0 and all(got.get(k)==expected[k] for k in keys)
    good=good and '[SVBProbe]PASS Test' in txt and not any(x in txt for x in ['SVB_GG_STREAM_MISMATCH','unstable value','*** FAILED','Assertion failed'])
    events=list(csv.DictReader((L/'fpga-event-intervals.csv').open()))
    good=good and len(events)==clock.get('event_rows') and clock.get('fpga_hcycle_elapsed',0)>0
    for name,key in [('capture','capture_accepted'),('promotion','promote_accepted'),('ack','acked')]:
        good=good and sum(int(e[name]) for e in events)==got.get(key)
    good=good and all(int(e['fpga_hcycle_after'])>=int(e['fpga_hcycle_before']) for e in events)
    result=dict(schema='ec-real-fpga-clock-replay/1',status='PASS_REAL_SVB_FPGA_HOST_COUNTER_REPLAY' if good else 'FAILED_WITH_EVIDENCE',
                functional_baseline=parent.BASE,source_id=parent.SID,board_bdf=bb.TARGET_BDF,
                board_serial=bb.TARGET_SERIAL,bitstream_sha256=cert['bitstream_sha256'],
                summary=got,clock_summary=clock,host_wall_seconds=wall,returncode=child.returncode,
                run_started_sha256=sha(L/'run-started.json'),raw_log=str(log),raw_log_sha256=sha(log),
                event_csv_sha256=sha(L/'fpga-event-intervals.csv'),trace_sha256=admission['trace_sha256'],
                no_reflash=True,deployment_operations=[],full_opt4=False,completed_utc=now())
    save(L/'result.json',result)
    if good:save(L/'complete.json',dict(result_sha256=sha(L/'result.json')))
    active.update(status=result['status'],ended_utc=now());save(D/'active-0000_21_00.0.json',active)
    state.update(status=result['status'],child={},updated_utc=now(),result=str(L/'result.json'));save(L/'state.json',state)
    print(json.dumps(result,indent=2));assert good,'preserve failing evidence'

if __name__=='__main__':main()
