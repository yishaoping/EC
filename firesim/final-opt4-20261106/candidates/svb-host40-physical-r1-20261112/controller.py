#!/usr/bin/python3
"""Conditional physical recovery of an actual-MMCM host40 SVB DCP; no device I/O."""
import fcntl
import importlib.util
import os
from pathlib import Path
import resource
import re
import shutil
import signal
import subprocess
import sys
import time

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
ROOT=D/'cycleprecise-svb-postroute-recovery-r1-20261111'
OUT=D/'cycleprecise-svb-host40-implementation-r1-20261112'
PROBE=D/'cycleprecise-svb-hostclock-probe-r2-20261112'
STATE=D/'Opt4-svb-host40-physical-r1-state.json'
R1=W/'routes/svb-postroute-recovery-r1-20261111'
R4=W/'candidates/svb-physical-pinreplicate-r4-20261112'
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
SID='b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f'
PROFILE='OriginalSVB32-component-trace-host40'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import read,save,sha,identity,live,now
ST={}


def module(name,path):
    sp=importlib.util.spec_from_file_location(name,path)
    m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m);return m


def update(status,**extra):
    ST.update(status=status,updated_utc=now(),**extra);save(STATE,ST);save(OUT/'state.json',ST)


def verify():
    p=read(D/'unattended-opt4/campaign-policy.json')
    assert p['functional_baseline_commit']==BASE and p['area_equivalence_only']
    assert p['native_paused'] and not p['functional_extensions_allowed']
    assert p['board_allowlist']==['0000:21:00.0']
    pins=read(C/'inputs.json')
    assert pins['functional_baseline']==BASE and pins['source_id']==SID and pins['profile']==PROFILE
    for path,h in pins['files'].items():assert sha(path)==h,('immutable host40 input changed',path)
    return pins


def workers():
    # Known component services only; actual Vivado executable distinguishes a
    # harmless waiting Python controller from a physical worker.
    units=['ec-opt4-auto-svb-physical-resource-recovery-r51-v1.service',
      'ec-opt4-auto-svb-physical-resume-r3-v1-8491167d.service',
      'ec-opt4-auto-svb-physical-pinreplicate-r4-v1-8491167d.service',
      'ec-opt4-svb-host40-physical-r1.service',
      'ec-opt4-frozen-svb-fpga-r2.service','ec-opt4-original-svb-spread-impl-r1.service']
    rows=[]
    for unit in units:
        cg=Path('/sys/fs/cgroup/systemd/system.slice')/unit
        if not cg.exists():continue
        assert (cg/'cgroup.procs').is_file()
        for pid in set(int(x) for p in cg.rglob('cgroup.procs') for x in p.read_text().split()):
            try:
                argv=(Path('/proc')/str(pid)/'cmdline').read_bytes().split(b'\0')
                if argv and argv[0].decode().endswith('/unwrapped/lnx64.o/vivado'):
                    rows.append(dict(unit=unit,**identity(pid),argv=[x.decode() for x in argv if x]))
            except FileNotFoundError:pass
    return rows


def main():
    verify();OUT.mkdir(exist_ok=True)
    lock=(OUT/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    old=read(OUT/'state.json')
    assert not live(old) and not live(old.get('child',{})),'adopt live host40 physical task'
    if (OUT/'result.json').exists():return
    assert not (OUT/'recovery.log').exists(),'partial CAD evidence requires independent recovery version'
    assert {250,251}<=set(os.sched_getaffinity(0));os.sched_setaffinity(0,{250,251})
    resource.setrlimit(resource.RLIMIT_AS,(64*2**30,)*2)
    ST.update(schema='ec-original-svb-host40-physical/1',**identity(),functional_baseline=BASE,
       source_id=SID,profile=PROFILE,target_rtl_changed=False,host_clock_changed=True,
       complete_opt4=False,fpga_access=False,native_paused=True,started_utc=now(),cpus=[250,251])
    guard=module('host40_r4_guard',R4/'controller.py')
    physical_lock=(ROOT/'instance.lock').open('a')
    verified_probe_sha=None
    while True:
        verify()
        if (ROOT/'chosen-physical-result.json').exists():
            update('ADOPT_EXISTING_50MHZ_CHOICE_NO_CAD');return
        probe=read(PROBE/'result.json')
        if probe.get('status')!='COMPLETE_DIAGNOSTIC_NOT_CERTIFIED':
            update('WAITING_SEALED_SUCCESSFUL_HOST40_PROBE_NO_CAD',probe_status=probe.get('status'));time.sleep(300);continue
        assert probe['functional_baseline']==BASE and not probe['fpga_access'] and not probe['target_rtl_changed']
        assert probe['returncode']==0 and not probe['route_started'] and not probe['bitstream_written']
        if verified_probe_sha is None:
            assert all(sha(p)==h for p,h in probe['outputs'].items())
            match=re.search(r'^EC_SVB_ACTUAL_HOST_CLOCK_PROBE_COMPLETE divider=30 period=([0-9.]+) WNS=',(PROBE/'probe.log').read_text(errors='replace'),re.M)
            assert match and abs(float(match[1])-24.9975)<0.002
            verified_probe_sha=sha(PROBE/'result.json')
        else:assert sha(PROBE/'result.json')==verified_probe_sha, 'sealed probe changed while waiting'
        if not guard.exact_exited_empty(guard.R51UNIT):
            update('WAITING_R51_EXACT_CGROUP_RELEASE_NO_CAD');time.sleep(300);continue
        active=workers()
        if len(active)>1:
            update('WAITING_FREE_COMPONENT_SLOT_NO_THIRD_ROUTE',workers=active);time.sleep(300);continue
        mem=int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:')))
        disk=shutil.disk_usage(W).free;load=float(Path('/proc/loadavg').read_text().split()[0])
        priority=read(D/'Opt4-fit-runtime-priority.json')
        if mem<128*2**20 or disk<96*2**30 or load>=48 or priority.get('status') in ['ACTIVE','REQUESTED_AT_SAFE_BOUNDARY']:
            update('WAITING_UNCHANGED_RESOURCE_OR_FULL_OPT4_PRIORITY',memory_kib=mem,disk_bytes=disk,load1=load);time.sleep(300);continue
        try:fcntl.flock(physical_lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
        except BlockingIOError:
            update('WAITING_GLOBAL_COMPONENT_PHYSICAL_LOCK_R4_MUTUAL_EXCLUSION');time.sleep(300);continue
        if len(workers())>1:
            fcntl.flock(physical_lock,fcntl.LOCK_UN);time.sleep(300);continue
        break
    verify();assert guard.exact_exited_empty(guard.R51UNIT) and len(workers())<=1
    checkpoint=OUT/'sealed-host40-probe.dcp';shutil.copyfile(PROBE/'host40-probe.dcp',checkpoint)
    assert sha(checkpoint)==probe['outputs'][str(PROBE/'host40-probe.dcp')]
    save(OUT/'sealed-inputs.json',dict(functional_baseline=BASE,source_id=SID,profile=PROFILE,
        host_clock_period_ns=24.9975,mmcm_clkout0_divide_f=30.0,physical_only=True,target_rtl_changed=False,
        probe_result=str(PROBE/'result.json'),probe_result_sha256=sha(PROBE/'result.json'),
        probe_input_sha256=probe['input_manifest_sha256'],sealed_checkpoint=str(checkpoint),
        sealed_checkpoint_sha256=sha(checkpoint),inputs_sha256=sha(C/'inputs.json'),sealed_utc=now()))
    code=(R1/'recover.tcl.in').read_text().replace('19.998','24.9975').replace('> 0.001','> 0.002')
    code=code.replace('route_design -preserve -directive Explore -tns_cleanup','route_design -directive Explore -tns_cleanup')
    clockcheck='''set mmcm [get_cells -hier -filter {NAME == design_1_i/clk_wiz_0/inst/mmcme4_adv_inst}]
if {[llength $mmcm] != 1 || [get_property CLKOUT0_DIVIDE_F $mmcm] != 30.0 || [get_property CLKFBOUT_MULT_F $mmcm] != 4.0 || [get_property DIVCLK_DIVIDE $mmcm] != 1} {error "host40 physical MMCM mismatch"}
'''
    code=code.replace('target_clock\nsaved_reports initial',clockcheck+'target_clock\nsaved_reports initial')
    extra='''set skew [report_bus_skew -return_string -no_detailed_paths -warn_on_violation]
set f [open {@OUT@/bus-skew-final.rpt} w]; puts $f $skew; close $f
if {[regexp -nocase {VIOLATED} $skew]} {error "bus skew gate failed"}
report_cdc -file {@OUT@/cdc-final.rpt}
'''
    code=code.replace('write_bitstream -force',extra+'write_bitstream -force')
    code=code.replace('original-svb-recovered.bit','original-svb-host40.bit').replace('EC_SVB_RECOVERY_BITSTREAM_COMPLETE','EC_SVB_HOST40_BITSTREAM_COMPLETE')
    assert '-preserve' not in code and 'create_clock' not in code and 'set_false_path' not in code
    tcl=OUT/'recover.tcl';tcl.write_text(code.replace('@CHECKPOINT@',str(checkpoint)).replace('@OUT@',str(OUT)))
    argv=['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(OUT/'vivado.log'),'-source',str(tcl)]
    start=time.monotonic()
    with (OUT/'recovery.log').open('xb',buffering=0) as log:
        p=subprocess.Popen(argv,cwd=OUT,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,start_new_session=True,env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'2'})
        update('RUNNING_HOST40_SHELL_PHYSICAL_RECOVERY_NO_FPGA',child=identity(p.pid),argv=argv,admission_workers=active)
        while p.poll() is None:
            try:p.wait(timeout=300)
            except subprocess.TimeoutExpired:pass
            os.fsync(log.fileno());update('RUNNING_HOST40_SHELL_PHYSICAL_RECOVERY_NO_FPGA',host_wall_seconds=time.monotonic()-start,log_bytes=log.tell())
            if time.monotonic()-start>18*3600 and p.poll() is None:
                os.killpg(p.pid,signal.SIGTERM)
                try:p.wait(timeout=30)
                except subprocess.TimeoutExpired:os.killpg(p.pid,signal.SIGKILL);p.wait()
                break
    bit=OUT/'original-svb-host40.bit';text=(OUT/'recovery.log').read_text(errors='replace')
    good=p.returncode==0 and bit.exists() and 'EC_SVB_HOST40_BITSTREAM_COMPLETE' in text
    result=dict(schema='ec-original-svb-host40-physical/1',status='HOST40_BITSTREAM_PENDING_INDEPENDENT_CERTIFICATION' if good else 'FAILED_WITH_EVIDENCE',
       functional_baseline=BASE,source_id=SID,profile=PROFILE,target_rtl_changed=False,host_clock_changed=True,
       host_clock_period_ns=24.9975,mmcm_clkout0_divide_f=30.0,complete_opt4=False,fpga_access=False,
       input_manifest_sha256=sha(C/'inputs.json'),sealed_inputs_sha256=sha(OUT/'sealed-inputs.json'),
       returncode=p.returncode,host_wall_seconds=time.monotonic()-start,completed_utc=now(),
       bitstream=str(bit) if good else None,bitstream_sha256=sha(bit) if good else None,
       outputs={str(p):sha(p) for p in OUT.iterdir() if p.is_file() and p.name not in ['instance.lock','state.json','result.json','complete.json']})
    save(OUT/'result.json',result)
    if good:save(OUT/'complete.json',dict(result_sha256=sha(OUT/'result.json')))
    update(result['status'],child={},result=str(OUT/'result.json'))


if __name__=='__main__':
    try:main()
    except Exception as e:
        if OUT.exists():update('FAILED_WITH_EVIDENCE',error=repr(e))
        raise
