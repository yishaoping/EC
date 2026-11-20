#!/usr/bin/python3
"""One admitted extra small postroute slot; A routing/placement, then B FD replication."""
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
OUT=D/'cycleprecise-svb-host40-shell-recovery-r2-20261112'
PROBE=D/'cycleprecise-svb-hostclock-probe-r2-20261112'
R1=W/'candidates/svb-host40-physical-r1-20261112'
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
SID='b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f'
PROFILE='OriginalSVB32-component-trace-host40'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import read,save,sha,identity,live,now
ST={}


def update(status,**extra):
    ST.update(status=status,updated_utc=now(),**extra);save(OUT/'state.json',ST)


def verify():
    pins=read(C/'inputs.json')
    p=read(D/'unattended-opt4/campaign-policy.json')
    assert p['functional_baseline_commit']==BASE and p['native_paused'] and p['area_equivalence_only']
    assert not p['functional_extensions_allowed'] and p['board_allowlist']==['0000:21:00.0']
    assert pins['functional_baseline']==BASE and pins['source_id']==SID and pins['profile']==PROFILE
    for path,h in pins['files'].items():assert sha(path)==h,('immutable r2 shell input changed',path)
    a=read(pins['resource_admission'])
    assert a['decision']=='ADMIT_ONE_ADDITIONAL_SMALL_SVB_POSTROUTE_RECOVERY_ON224_225_MAX64GIB'
    assert a['no_fpga_io'] and a['limits']['cpus']==[224,225] and a['limits']['max_component_vivado']==3
    return pins,a


def workers():
    spec=importlib.util.spec_from_file_location('r2_host40_worker_scope',R1/'controller.py')
    m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
    rows=m.workers()
    unit='ec-opt4-svb-host40-shell-physical-r2.service'
    cg=Path('/sys/fs/cgroup/systemd/system.slice')/unit
    if cg.exists():
        assert (cg/'cgroup.procs').is_file()
        for pid in set(int(x) for p in cg.rglob('cgroup.procs') for x in p.read_text().split()):
            try:
                argv=(Path('/proc')/str(pid)/'cmdline').read_bytes().split(b'\0')
                if argv and argv[0].decode().endswith('/unwrapped/lnx64.o/vivado'):
                    rows.append(dict(unit=unit,**identity(pid),argv=[x.decode() for x in argv if x]))
            except FileNotFoundError:pass
    return rows


def admitted():
    _,a=verify();limits=a['limits'];rows=workers()
    mem=int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:')))
    disk=shutil.disk_usage(W).free;load=float(Path('/proc/loadavg').read_text().split()[0])
    good=len(rows)<limits['max_component_vivado'] and mem>=limits['min_available_gib']*2**20 and disk>=limits['min_disk_gib']*2**30 and load<limits['max_load1']
    return good,dict(workers=rows,memory_kib=mem,disk_bytes=disk,load1=load)


def attempt(mode,checkpoint):
    out=OUT/mode
    if (out/'result.json').exists():return read(out/'result.json')
    assert not (out/'recovery.log').exists(),'preserve partial CAD; independent recovery required'
    while True:
        good,admission=admitted()
        if good:break
        update('WAITING_ADMITTED_THIRD_SMALL_COMPONENT_RESOURCE_GUARD',admission=admission);time.sleep(300)
    out.mkdir(exist_ok=True)
    sealed=out/'sealed-source.dcp';shutil.copyfile(checkpoint,sealed)
    assert sha(sealed)==sha(checkpoint)
    probe=read(PROBE/'result.json')
    save(out/'sealed-inputs.json',dict(functional_baseline=BASE,source_id=SID,profile=PROFILE,
       target_rtl_changed=False,physical_only=True,host_clock_period_ns=24.9975,mmcm_clkout0_divide_f=30.0,
       probe_result=str(PROBE/'result.json'),probe_result_sha256=sha(PROBE/'result.json'),probe_input_sha256=probe['input_manifest_sha256'],
       sealed_checkpoint=str(sealed),sealed_checkpoint_sha256=sha(sealed),inputs_sha256=sha(C/'inputs.json'),
       mode=mode,source_checkpoint=str(checkpoint),source_checkpoint_sha256=sha(checkpoint),sealed_utc=now()))
    strategy='phys_opt_design -routing_opt -placement_opt'
    if mode=='B-shell-FD-replicate':
        strategy='''if {![llength $observed_nets]} {error "no safe negative shell FD Q nets available for strategyB"}
if {[llength $observed_nets]>32} {error "bounded shell replication selected too many nets"}
phys_opt_design -force_replication_on_nets $observed_nets
'''
    periods=read(C/'physical-clock-contract.json')['periods_ns']
    clocks=' '.join('{'+k+'} '+str(v) for k,v in periods.items())
    code=(C/'recover.tcl.in').read_text().replace('@CHECKPOINT@',str(sealed)).replace('@OUT@',str(out)).replace('@CLOCKS@',clocks).replace('@SHELL_QUERY@',(C/'shell-nets.tcl').read_text()).replace('@STRATEGY@',strategy)
    assert not any(x in code for x in ['-retime','AddRetime','create_clock','set_false_path','-preserve'])
    tcl=out/'recover.tcl';tcl.write_text(code)
    argv=['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(out/'vivado.log'),'-source',str(tcl)]
    start=time.monotonic()
    with (out/'recovery.log').open('xb',buffering=0) as log:
        p=subprocess.Popen(argv,cwd=out,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,start_new_session=True,env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'2'})
        update('RUNNING_ADMITTED_HOST40_SHELL_RECOVERY',mode=mode,child=identity(p.pid),argv=argv,admission=admission)
        while p.poll() is None:
            try:p.wait(timeout=300)
            except subprocess.TimeoutExpired:pass
            os.fsync(log.fileno());update('RUNNING_ADMITTED_HOST40_SHELL_RECOVERY',mode=mode,host_wall_seconds=time.monotonic()-start,log_bytes=log.tell())
    bit=out/'original-svb-host40.bit';text=(out/'recovery.log').read_text(errors='replace')
    good=p.returncode==0 and bit.exists() and 'EC_SVB_HOST40_BITSTREAM_COMPLETE' in text
    result=dict(schema='ec-original-svb-host40-shell-recovery/2',status='HOST40_BITSTREAM_PENDING_INDEPENDENT_CERTIFICATION' if good else 'FAILED_WITH_EVIDENCE',
       functional_baseline=BASE,source_id=SID,profile=PROFILE,target_rtl_changed=False,host_clock_changed=True,
       host_clock_period_ns=24.9975,mmcm_clkout0_divide_f=30.0,complete_opt4=False,fpga_access=False,mode=mode,
       input_manifest_sha256=sha(C/'inputs.json'),sealed_inputs_sha256=sha(out/'sealed-inputs.json'),
       returncode=p.returncode,host_wall_seconds=time.monotonic()-start,completed_utc=now(),
       bitstream=str(bit) if good else None,bitstream_sha256=sha(bit) if good else None,
       outputs={str(p):sha(p) for p in out.iterdir() if p.is_file() and p.name not in ['state.json','result.json','complete.json']})
    save(out/'result.json',result)
    if good:save(out/'complete.json',dict(result_sha256=sha(out/'result.json')))
    update(result['status'],mode=mode,child={},result=str(out/'result.json'))
    return result


def main():
    pins,a=verify();OUT.mkdir(exist_ok=True)
    lock=(OUT/'extra-component-slot.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    old=read(OUT/'state.json');assert not live(old) and not live(old.get('child',{})),'adopt live r2 recovery'
    if (OUT/'chosen-result.json').exists():return
    assert {224,225}<=set(os.sched_getaffinity(0));os.sched_setaffinity(0,{224,225});resource.setrlimit(resource.RLIMIT_AS,(64*2**30,)*2)
    ST.update(schema='ec-original-svb-host40-shell-recovery/2',**identity(),functional_baseline=BASE,
      source_id=SID,profile=PROFILE,fpga_access=False,target_rtl_changed=False,complete_opt4=False,
      cpus=[224,225],resource_admission_sha256=sha(pins['resource_admission']),started_utc=now())
    probe=read(PROBE/'result.json')
    assert probe['status']=='COMPLETE_DIAGNOSTIC_NOT_CERTIFIED' and probe['returncode']==0
    assert all(sha(p)==h for p,h in probe['outputs'].items())
    checkpoint=PROBE/'host40-probe.dcp'
    for mode in ['A-shell-routing-placement','B-shell-FD-replicate']:
        r=attempt(mode,checkpoint)
        if r['status']=='HOST40_BITSTREAM_PENDING_INDEPENDENT_CERTIFICATION':
            save(OUT/'chosen-result.json',dict(result=str(OUT/mode/'result.json'),result_sha256=sha(OUT/mode/'result.json'),profile=PROFILE,source_id=SID,created_utc=now()))
            update('HANDED_TO_INDEPENDENT_HOST40_CERTIFICATION',child={});return
        # Reuse the successful routed checkpoint and preserved physical ECOs,
        # never resynthesize or repeat strategyA after an A timing failure.
        final=OUT/mode/'final.dcp'
        if final.exists() and str(final) in r['outputs']:
            assert sha(final)==r['outputs'][str(final)];checkpoint=final
    update('BOUNDED_SHELL_STRATEGIES_FAILED_WITH_ALL_CHECKPOINTS_RETAINED',child={})


if __name__=='__main__':
    try:main()
    except Exception as e:
        if OUT.exists():update('FAILED_WITH_EVIDENCE',error=repr(e))
        raise
