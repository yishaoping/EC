#!/usr/bin/python3
"""Resume sealed successful physical optimization without repeating it.

The r51 controller remains unchanged on CPUs254-255. This one bounded second
component slot runs only on CPUs252-253, never synthesizes RTL or accesses a
device, and publishes only a pending independent-certification bitstream.
"""
import fcntl
import importlib.util
import os
from pathlib import Path
import resource
import shutil
import subprocess
import sys
import time

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U=D/'unattended-opt4'
ROOT=D/'cycleprecise-svb-postroute-recovery-r1-20261111'
OUT=ROOT/'resume-r3-spread-physical1'
STATE=D/'Opt4-svb-physical-resume-r3-state.json'
PRIOR=ROOT/'round51-v1/spread-postroute'
R1=W/'routes/svb-postroute-recovery-r1-20261111'
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
SID='b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import read,save,sha,identity,live,now
ST={}


def update(status,**extra):
    ST.update(status=status,updated_utc=now(),**extra);save(STATE,ST)
    if OUT.exists():save(OUT/'state.json',ST)


def policy():
    p=read(U/'campaign-policy.json')
    assert p['functional_baseline_commit']==BASE and p['area_equivalence_only']
    assert p['native_paused'] and not p['fpga_access'] and not p['functional_extensions_allowed']
    assert p['board_allowlist']==['0000:21:00.0']


def verify():
    policy();pins=read(C/'inputs.json')
    assert pins['functional_baseline']==BASE and pins['source_id']==SID
    for p,h in pins['files'].items():assert sha(p)==h,('immutable resume input changed',p)
    for p,h in read(C/'sealed-prior-evidence.json')['files'].items():
        assert sha(p)==h,('sealed completed physical evidence changed',p)
    receipt=read(PRIOR/'result.json');assert receipt['status']=='FAILED_WITH_EVIDENCE'
    assert receipt['returncode']==1 and receipt['source_id']==SID and receipt['functional_baseline']==BASE
    for p in [PRIOR/'physical-1.dcp',PRIOR/'physical-1-timing.rpt',PRIOR/'sealed-inputs.json']:
        assert sha(p)==receipt['outputs'][str(p)]
    log=(PRIOR/'recovery.log').read_text(errors='replace')
    assert 'EC_SVB_RECOVERY_CHECKPOINT tag=physical-1 WNS=-1.373 WHS=0.001' in log
    assert '"-directive Explore" cannot be used with "-preserve"' in log
    return pins


def component_workers():
    # Count only actual Vivado design processes (not shell wrappers, waiting
    # controllers or full-Opt4 synthesis). Exact known cgroups bound scope.
    units=['ec-opt4-frozen-svb-fpga-r2.service','ec-opt4-original-svb-spread-impl-r1.service',
           'ec-opt4-auto-svb-physical-resource-recovery-r51-v1.service',
           'ec-opt4-auto-svb-physical-resume-r3-v1-8491167d.service']
    units += [f'ec-opt4-svb-recovery-{p}-{mode}-r{r}.service' for r in [1,2]
              for p in ['original','spread'] for mode in ['postroute','replicate']]
    rows=[]
    for unit in units:
        group=Path('/sys/fs/cgroup/systemd/system.slice')/unit
        if not group.exists():continue
        assert (group/'cgroup.procs').is_file(),('unreadable component cgroup',unit)
        pids=set()
        for file in group.rglob('cgroup.procs'):pids.update(map(int,file.read_text().split()))
        for pid in pids:
            proc=Path('/proc')/str(pid)
            try:
                argv=proc.joinpath('cmdline').read_bytes().split(b'\0')
                first=argv[0].decode() if argv else ''
                if first.endswith('/unwrapped/lnx64.o/vivado'):
                    rows.append(dict(unit=unit,**identity(pid),argv=[a.decode() for a in argv if a]))
            except FileNotFoundError:continue
    return rows


def main():
    verify()
    assert read(C/'preflight.json')['status']=='PASS_SEALED_PHYSOPT_RESUME_AND_ROUTER_OPTION_GATES'
    assert not OUT.exists(),'adopt prior resume attempt; versioned recovery required'
    lock=(ROOT/'resume-r3-instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    allowed=set(os.sched_getaffinity(0));assert {252,253}<=allowed
    os.sched_setaffinity(0,{252,253});resource.setrlimit(resource.RLIMIT_AS,(64*2**30,)*2)
    ST.update(schema='ec-original-svb-physical-resume/3',**identity(),functional_baseline=BASE,
              source_id=SID,target_changed=False,fpga_access=False,complete_opt4=False,
              native_paused=True,cpus=[252,253],started_utc=now())
    while True:
        policy()
        workers=component_workers();assert len(workers)<=1,('no free second component route slot',workers)
        mem=int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:')))
        disk=shutil.disk_usage(W).free;load=float(Path('/proc/loadavg').read_text().split()[0])
        if mem>=128*2**20 and disk>=96*2**30 and 0<=load<48:break
        update('WAITING_RESOURCE_ADMISSION_NO_CAD',memory_kib=mem,disk_bytes=disk,load1=load)
        time.sleep(300)
    OUT.mkdir()
    checkpoint=OUT/'sealed-physical-1.dcp';shutil.copyfile(PRIOR/'physical-1.dcp',checkpoint)
    assert sha(checkpoint)==sha(PRIOR/'physical-1.dcp')
    sealed=read(PRIOR/'sealed-inputs.json')
    sealed.update(checkpoint=str(PRIOR/'physical-1.dcp'),checkpoint_sha256=sha(checkpoint),
                  sealed_checkpoint=str(checkpoint),sealed_utc=now(),mode='resume-physical1',
                  prior_result=str(PRIOR/'result.json'),prior_result_sha256=sha(PRIOR/'result.json'),
                  prior_checkpoint_reports={str(p):sha(p) for p in PRIOR.glob('physical-1-*.rpt')})
    save(OUT/'sealed-inputs.json',sealed)
    # Reuse all original final target clock/setup/hold/pulse/DRC/full-route gates.
    # Start by routing existing physical ECOs, no repetition of the 3h physopt.
    code=(R1/'recover.tcl.in').read_text()
    code=code.replace('route_design -preserve -directive Explore -tns_cleanup','route_design -directive Explore -tns_cleanup')
    marker='target_clock\nsaved_reports initial'
    assert code.count(marker)==1
    code=code.replace(marker,'target_clock\nputs "EC_SVB_RESUME_SEALED_PHYSICAL1"\nroute_design -directive Explore -tns_cleanup\nsaved_reports resumed-route')
    extra='''set bus_skew [report_bus_skew -return_string -no_detailed_paths -warn_on_violation]
set fp [open {@OUT@/bus-skew-final.rpt} w]; puts $fp $bus_skew; close $fp
if {[regexp -nocase {VIOLATED} $bus_skew]} {error "bus skew timing gate failed"}
'''
    code=code.replace('write_bitstream -force',extra+'write_bitstream -force')
    assert '-preserve' not in code and 'create_clock' not in code and 'set_false_path' not in code
    tcl=OUT/'resume.tcl';tcl.write_text(code.replace('@CHECKPOINT@',str(checkpoint)).replace('@OUT@',str(OUT)))
    argv=['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(OUT/'vivado.log'),'-source',str(tcl)]
    started=time.monotonic()
    with (OUT/'recovery.log').open('xb',buffering=0) as log:
        p=subprocess.Popen(argv,cwd=OUT,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,
              start_new_session=True,env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'2'})
        update('RUNNING_RESUMED_SPREAD_PHYSICAL1_ROUTE',child=identity(p.pid),argv=argv,
               admission=dict(memory_kib=mem,disk_bytes=disk,load1=load,existing_component_workers=workers))
        deadline=started+18*3600
        while p.poll() is None:
            try:p.wait(timeout=300)
            except subprocess.TimeoutExpired:pass
            update('RUNNING_RESUMED_SPREAD_PHYSICAL1_ROUTE',host_wall_seconds=time.monotonic()-started,
                   log_bytes=log.tell())
            os.fsync(log.fileno())
            if time.monotonic()>deadline and p.poll() is None:
                import signal
                os.killpg(p.pid,signal.SIGTERM)
                try:p.wait(timeout=30)
                except subprocess.TimeoutExpired:os.killpg(p.pid,signal.SIGKILL);p.wait()
                break
    rc=p.returncode;bit=OUT/'original-svb-recovered.bit';text=(OUT/'recovery.log').read_text(errors='replace')
    good=rc==0 and bit.exists() and 'EC_SVB_RECOVERY_BITSTREAM_COMPLETE' in text
    result=dict(schema='ec-original-svb-physical-resume/3',
         status='BITSTREAM_WRITTEN_PENDING_INDEPENDENT_CERTIFICATION' if good else 'FAILED_WITH_EVIDENCE',
         functional_baseline=BASE,source_id=SID,complete_opt4=False,target_changed=False,fpga_access=False,
         producer='spread',mode='resume-physical1',input_manifest_sha256=sha(OUT/'sealed-inputs.json'),
         capsule_inputs_sha256=sha(R1/'inputs.json'),resume_inputs_sha256=sha(C/'inputs.json'),
         returncode=rc,host_wall_seconds=time.monotonic()-started,completed_utc=now(),
         bitstream=str(bit) if good else None,bitstream_sha256=sha(bit) if good else None,
         outputs={str(p):sha(p) for p in OUT.iterdir() if p.is_file() and p.name not in ['state.json','result.json','complete.json']})
    save(OUT/'result.json',result)
    if good:
        save(OUT/'complete.json',dict(result_sha256=sha(OUT/'result.json')))
        publish_lock=(ROOT/'choice-publish.lock').open('a');fcntl.flock(publish_lock,fcntl.LOCK_EX)
        if not (ROOT/'chosen-physical-result.json').exists():
            save(ROOT/'chosen-physical-result.json',dict(result=str(OUT/'result.json'),result_sha256=sha(OUT/'result.json'),
                 source_id=SID,functional_baseline=BASE,chosen_utc=now(),fpga_access=False))
    update(result['status'],child={},result=str(OUT/'result.json'))


if __name__=='__main__':
    try:main()
    except Exception as e:
        update('FAILED_WITH_EVIDENCE',error=repr(e));raise
