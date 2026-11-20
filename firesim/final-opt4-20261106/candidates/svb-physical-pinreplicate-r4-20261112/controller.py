#!/usr/bin/python3
"""Persistently wait for one released component slot, then replicate exact FD Q nets.

No live task input is changed. This one versioned attempt replaces the r51 slot
only after its exact systemd cgroup is empty; r3 may continue in the other slot.
No synthesis, clock change, target modification or device access is permitted.
"""
import fcntl
import importlib.util
import os
from pathlib import Path
import resource
import shutil
import signal
import subprocess
import sys
import time

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U=D/'unattended-opt4'
ROOT=D/'cycleprecise-svb-postroute-recovery-r1-20261111'
OUT=ROOT/'pinreplicate-r4-spread-physopt'
STATE=D/'Opt4-svb-physical-pinreplicate-r4-state.json'
R1=W/'routes/svb-postroute-recovery-r1-20261111'
R3=W/'candidates/svb-physical-resume-r3-20261112'
QUERY=W/'candidates/svb-activeidx-pinquery-r1-20261112'
QUERYOUT=D/'cycleprecise-svb-activeidx-pinquery-r1-20261112'
R51UNIT='ec-opt4-auto-svb-physical-resource-recovery-r51-v1.service'
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
SID='b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import read,save,sha,identity,live,now
ST={}


def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path)
    m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m


def update(status,**extra):
    ST.update(status=status,updated_utc=now(),**extra);save(STATE,ST)
    if OUT.exists():save(OUT/'state.json',ST)


def policy():
    p=read(U/'campaign-policy.json')
    assert p['functional_baseline_commit']==BASE and p['area_equivalence_only']
    assert p['native_paused'] and not p['fpga_access'] and not p['functional_extensions_allowed']
    assert p['board_allowlist']==['0000:21:00.0']


def exact_exited_empty(unit):
    assert unit in [R51UNIT,'ec-opt4-frozen-svb-fpga-r2.service','ec-opt4-original-svb-spread-impl-r1.service']
    raw=subprocess.check_output(['systemctl','show',unit,'-p','MainPID','-p','ActiveState','-p','ControlGroup'],text=True)
    row=dict(x.split('=',1) for x in raw.splitlines() if '=' in x)
    if row.get('MainPID')!='0' or row.get('ActiveState') not in ['inactive','failed']:return False
    expected='/system.slice/'+unit
    assert row.get('ControlGroup','') in ['',expected]
    root=Path('/sys/fs/cgroup/systemd');assert root.is_dir()
    cg=root/expected.lstrip('/')
    if not cg.exists():return True
    assert (cg/'cgroup.procs').is_file()
    return all(not p.read_text().strip() for p in cg.rglob('cgroup.procs'))


def verify():
    policy();pins=read(C/'inputs.json')
    assert pins['functional_baseline']==BASE and pins['source_id']==SID
    for p,h in pins['files'].items():assert sha(p)==h,('immutable candidate input changed',p)
    return pins


def main():
    verify()
    lock=(ROOT/'pinreplicate-r4-instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert {254,255}<=set(os.sched_getaffinity(0))
    os.sched_setaffinity(0,{254,255});resource.setrlimit(resource.RLIMIT_AS,(64*2**30,)*2)
    ST.update(schema='ec-original-svb-pinreplicate/4',**identity(),functional_baseline=BASE,
       source_id=SID,target_changed=False,fpga_access=False,complete_opt4=False,
       native_paused=True,cpus=[254,255],started_utc=now())
    gate=module('r4_component_gate',R3/'controller.py')
    prior=module('r4_original_physical',R1/'run.py')
    while True:
        policy()
        if (ROOT/'chosen-physical-result.json').exists():
            update('ADOPT_EXISTING_BITSTREAM_CHOICE_NO_CAD');return
        priority=read(D/'Opt4-fit-runtime-priority.json')
        query=read(QUERYOUT/'result.json')
        ready=query.get('status')=='PASS_EXACT_ACTIVEIDX_PIN_QUERY' and query.get('returncode')==0
        if not ready:
            update('WAITING_ACTUAL_EXACT_QUERY_PASS_NO_CAD',query=query);time.sleep(300);continue
        assert 'EC_ACTIVEIDX_EXACT_PINQUERY_PASS nets=2' in (QUERYOUT/'probe.log').read_text(errors='replace')
        if not exact_exited_empty(R51UNIT):
            update('WAITING_R51_EXACT_CGROUP_RELEASE_NO_CAD');time.sleep(300);continue
        workers=gate.component_workers()
        if len(workers)>1:
            update('WAITING_FREE_SECOND_COMPONENT_SLOT_NO_CAD',workers=workers);time.sleep(300);continue
        if priority.get('status') in ['ACTIVE','REQUESTED_AT_SAFE_BOUNDARY']:
            update('WAITING_COMPLETE_OPT4_PRIORITY_NO_CAD');time.sleep(300);continue
        mem=int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:')))
        disk=shutil.disk_usage(W).free;load=float(Path('/proc/loadavg').read_text().split()[0])
        if mem<128*2**20 or disk<96*2**30 or load>=48:
            update('WAITING_UNCHANGED_RESOURCE_ADMISSION_NO_CAD',memory_kib=mem,disk_bytes=disk,load1=load);time.sleep(300);continue
        break
    verify()
    assert not OUT.exists(),'preserve previous attempt; versioned recovery required'
    physical_lock=(ROOT/'instance.lock').open('a');fcntl.flock(physical_lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert exact_exited_empty(R51UNIT) and len(gate.component_workers())<=1
    OUT.mkdir()
    prior.unit_empty=exact_exited_empty
    checkpoint=prior.seal('spread','replicate',OUT)
    bound=read(OUT/'sealed-inputs.json')
    bound.update(physical_retry='r4-exact-FD-Q-query',query_result_sha256=sha(QUERYOUT/'result.json'),query_log_sha256=sha(QUERYOUT/'probe.log'),query_source_sha256=sha(QUERY/'query.tcl'))
    save(OUT/'sealed-inputs.json',bound)
    code=(R1/'recover.tcl.in').read_text()
    code=code.replace('route_design -preserve -directive Explore -tns_cleanup','route_design -directive Explore -tns_cleanup')
    insert=(QUERY/'query.tcl').read_text()+'''
set active_nets [original_activeidx_nets {@OUT@/forced-replication-before.tsv}]
report_high_fanout_nets -max_nets 40 -timing -file {@OUT@/fanout-before-forced-replication.rpt}
phys_opt_design -force_replication_on_nets $active_nets
write_checkpoint -force {@OUT@/forced-replicated.dcp}
report_high_fanout_nets -max_nets 100 -timing -file {@OUT@/fanout-after-forced-replication.rpt}
report_utilization -file {@OUT@/utilization-after-forced-replication.rpt}
puts "EC_SVB_EXACT_ACTIVEIDX_FORCED_REPLICATION_COMPLETE nets=[llength $active_nets]"
route_design -directive Explore -tns_cleanup
saved_reports forced-replication-routed
'''
    marker='target_clock\nsaved_reports initial'
    assert code.count(marker)==1
    code=code.replace(marker,'target_clock\n'+insert+'\nsaved_reports initial')
    extra='''set bus_skew [report_bus_skew -return_string -no_detailed_paths -warn_on_violation]
set fp [open {@OUT@/bus-skew-final.rpt} w]; puts $fp $bus_skew; close $fp
if {[regexp -nocase {VIOLATED} $bus_skew]} {error "bus skew timing gate failed"}
'''
    code=code.replace('write_bitstream -force',extra+'write_bitstream -force')
    assert '-preserve' not in code and 'create_clock' not in code and 'set_false_path' not in code
    tcl=OUT/'recover.tcl';tcl.write_text(code.replace('@CHECKPOINT@',str(checkpoint)).replace('@OUT@',str(OUT)))
    argv=['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(OUT/'vivado.log'),'-source',str(tcl)]
    started=time.monotonic()
    with (OUT/'recovery.log').open('xb',buffering=0) as log:
        p=subprocess.Popen(argv,cwd=OUT,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,start_new_session=True,env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'2'})
        update('RUNNING_EXACT_FD_Q_REPLICATION_AND_ROUTE',child=identity(p.pid),argv=argv,
           admission=dict(memory_kib=mem,disk_bytes=disk,load1=load,existing_component_workers=workers))
        while p.poll() is None:
            try:p.wait(timeout=300)
            except subprocess.TimeoutExpired:pass
            update('RUNNING_EXACT_FD_Q_REPLICATION_AND_ROUTE',host_wall_seconds=time.monotonic()-started,log_bytes=log.tell());os.fsync(log.fileno())
            if time.monotonic()-started>18*3600 and p.poll() is None:
                os.killpg(p.pid,signal.SIGTERM)
                try:p.wait(timeout=30)
                except subprocess.TimeoutExpired:os.killpg(p.pid,signal.SIGKILL);p.wait()
                break
    rc=p.returncode;bit=OUT/'original-svb-recovered.bit';text=(OUT/'recovery.log').read_text(errors='replace')
    good=rc==0 and bit.exists() and 'EC_SVB_RECOVERY_BITSTREAM_COMPLETE' in text
    result=dict(schema='ec-original-svb-pinreplicate/4',status='BITSTREAM_WRITTEN_PENDING_INDEPENDENT_CERTIFICATION' if good else 'FAILED_WITH_EVIDENCE',
       functional_baseline=BASE,source_id=SID,complete_opt4=False,target_changed=False,fpga_access=False,
       producer='spread',mode='exact-activeidx-FD-Q-replicate',input_manifest_sha256=sha(OUT/'sealed-inputs.json'),
       capsule_inputs_sha256=sha(R1/'inputs.json'),pinreplicate_inputs_sha256=sha(C/'inputs.json'),
       returncode=rc,host_wall_seconds=time.monotonic()-started,completed_utc=now(),
       bitstream=str(bit) if good else None,bitstream_sha256=sha(bit) if good else None,
       outputs={str(p):sha(p) for p in OUT.iterdir() if p.is_file() and p.name not in ['state.json','result.json','complete.json']})
    save(OUT/'result.json',result)
    if good:
        save(OUT/'complete.json',dict(result_sha256=sha(OUT/'result.json')))
        publish_lock=(ROOT/'choice-publish.lock').open('a');fcntl.flock(publish_lock,fcntl.LOCK_EX)
        if not (ROOT/'chosen-physical-result.json').exists():
            save(ROOT/'chosen-physical-result.json',dict(result=str(OUT/'result.json'),result_sha256=sha(OUT/'result.json'),source_id=SID,functional_baseline=BASE,chosen_utc=now(),fpga_access=False))
    update(result['status'],child={},result=str(OUT/'result.json'))


if __name__=='__main__':
    try:main()
    except Exception as e:
        update('FAILED_WITH_EVIDENCE',error=repr(e));raise
