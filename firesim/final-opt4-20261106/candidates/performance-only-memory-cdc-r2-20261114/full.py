#!/usr/bin/env python3
"""Frozen Performance-Only composition with four equivalent memory-backed queues."""
import datetime as dt
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import time

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
Q=D/'performance-only-memory-cdc-r2-20261114'
O=Q/os.environ.get('EC_CDC_FULL_RUN','complete-shell-r1')
RECOVERY=Path(os.environ['EC_CDC_FULL_RECOVERY_FROM']) if os.environ.get('EC_CDC_FULL_RECOVERY_FROM') else None
TREE=W/'Opt4-performance-only-memory-cdc-r2-20261114'
BASE='6fada307bb77be90b39720d3f95404fece0e431b'
HARDWARE='6e1e9b9'
PROFILE='EC Performance-Only: same-capacity memory-backed GHM data queues'
sys.path.insert(0,str(W/'scripts'))
ST=dict(profile=PROFILE,hardware_commit=HARDWARE,functional_baseline=BASE,
        full_PALIMPSEST=False,fpga_access=False,model_requests=False)

def now():return dt.datetime.now(dt.timezone.utc).isoformat()
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def read(p):return json.loads(Path(p).read_text())
def save(p,v):
    p=Path(p);tmp=p.with_suffix('.tmp');tmp.write_text(json.dumps(v,indent=2)+'\n');os.replace(tmp,p)
def update(status,**kw):ST.update(status=status,utc=now(),**kw);save(O/'state.json',ST)
def load(name,p):
    s=importlib.util.spec_from_file_location(name,p);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m

def stage(name,args,outputs=(),timeout=10800):
    if RECOVERY and name in ['OVERLAY_COMPILE','PARAMETERS','ELABORATE']:
        old=RECOVERY/(name+'-receipt.json');receipt=read(old)
        assert receipt['returncode']==0 and not receipt['missing']
        assert all(sha(p)==h for p,h in receipt['outputs'].items())
        for target in outputs:
            src=RECOVERY/target.relative_to(O)
            assert str(src) in receipt['outputs'] and sha(src)==receipt['outputs'][str(src)]
            if target.exists():assert sha(target)==sha(src)
            else:target.symlink_to(src)
        save(O/(name+'-reused.json'),dict(receipt=str(old),receipt_sha256=sha(old),unchanged_source_binding=True))
        return RECOVERY/(name+'.log')
    log=O/(name+'.log');assert not log.exists()
    update('RUNNING_'+name,child_pid=None)
    with log.open('wb') as f:
        p=subprocess.Popen([str(a) for a in args],cwd=TREE/'chipyard',stdin=subprocess.DEVNULL,
            stdout=f,stderr=subprocess.STDOUT,start_new_session=True,
            env={**os.environ,'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':'','OMP_NUM_THREADS':'4','TMPDIR':str(O)})
        update(ST['status'],child_pid=p.pid)
        try:p.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            import signal
            os.killpg(p.pid,signal.SIGTERM)
            try:p.wait(timeout=30)
            except subprocess.TimeoutExpired:os.killpg(p.pid,signal.SIGKILL);p.wait()
            raise
    receipt=dict(argv=[str(a) for a in args],returncode=p.returncode,log_sha256=sha(log),
        outputs={str(x):sha(x) for x in outputs if Path(x).is_file()},missing=[str(x) for x in outputs if not Path(x).is_file()])
    save(O/(name+'-receipt.json'),receipt)
    update('RECORDED_'+name,child_pid=None)
    assert p.returncode==0 and not receipt['missing'],(name,p.returncode)
    return log

def main():
    os.sched_setaffinity(0,set(range(240,248)))
    O.mkdir(exist_ok=False)
    hardware=subprocess.check_output(['git','rev-parse',HARDWARE],cwd=TREE,text=True).strip()
    ST['hardware_commit']=hardware
    changed=subprocess.check_output(['git','diff','--name-only',BASE,hardware,'--','chipyard'],cwd=TREE,text=True).splitlines()
    expected=['chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala',
              'chipyard/generators/rocket-chip/src/main/scala/util/LocalMemAsyncQueue.scala']
    assert sorted(changed)==sorted(expected)
    for rel in expected:
        assert subprocess.check_output(['git','show',hardware+':'+rel],cwd=TREE)==(TREE/rel).read_bytes()
    binding=dict(hardware_commit=hardware,source_id=hashlib.sha256(''.join(sha(TREE/p) for p in sorted(expected)).encode()).hexdigest(),
        baseline=BASE,changed_sources={p:sha(TREE/p) for p in expected},profile=PROFILE)
    save(O/'hardware-binding.json',binding)
    if RECOVERY:
        assert read(RECOVERY/'state.json')['error']=="AssertionError(('all four data queues must use equivalent storage', 1))"
        assert read(RECOVERY/'hardware-binding.json')==binding
    cfg=read(W/'candidates/common-composed-source-r2-20261113/config.json')
    previous=D/'build-logs/Opt4-performance-only-fpga-r1-20261113'
    baseline_classes=previous/'classes'
    assert (baseline_classes/'boom/lsu/LSUDMemIO.class').is_file()
    # Preserve the exact complete Performance-Only compile closure, overlay only
    # the two reviewed sources. Record every reused bytecode digest.
    inventory={str(p):sha(p) for p in sorted(baseline_classes.rglob('*.class'))}
    assert inventory
    save(O/'baseline-bytecode.json',dict(classes=inventory,original_compile_receipt=read(previous/'compile-source-receipt.json')))
    classes=O/'classes';classes.mkdir()
    if RECOVERY:shutil.copytree(RECOVERY/'classes',classes,dirs_exist_ok=True)
    cp=':'.join([str(baseline_classes),cfg['firechip'],*cfg['classpath']])
    java=[cfg['java'],'-Xmx64G','-Xss32M','-XX:ActiveProcessorCount=4','-Dec.dac.firesim=true']
    stage('OVERLAY_COMPILE',java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,
        '-Xplugin:'+cfg['plugin'],'-d',classes,*[TREE/p for p in reversed(expected)]],
        [classes/'freechips/rocketchip/guardiancouncil/GHM.class',classes/'freechips/rocketchip/util/LocalMemAsyncQueue.class'])
    java+=['-cp',str(classes)+':'+cp]
    params=O/'parameters.json'
    stage('PARAMETERS',java+['firesim.firesim.DacParameterAudit','firesim.firesim.DacOpt4C4',params],[params])
    assert read(params)==read(cfg['frozen_parameters'])
    elab=O/'elaborate';elab.mkdir()
    fir=elab/'firesim.firesim.FireSim.fir';anno=elab/'firesim.firesim.FireSim.anno.json'
    log=stage('ELABORATE',java[:1]+['-verbose:class']+java[1:]+['chipyard.Generator','--target-dir',elab,
        '--name','firesim.firesim.FireSim','--top-module','firesim.firesim.FireSim','--legacy-configs','firesim.firesim:DacOpt4C4'],[fir,anno])
    loaded=log.read_text(errors='replace')
    recorded_origin=RECOVERY/'classes' if RECOVERY else classes
    for cls in ['freechips.rocketchip.guardiancouncil.GHM','freechips.rocketchip.util.LocalMemAsyncQueue']:
        assert any(cls in line and str(recorded_origin) in line for line in loaded.splitlines()),cls
    for cls in ['boom.lsu.LSUDMemIO','boom.lsu.LSU','boom.lsu.BoomNonBlockingDCache']:
        assert any(cls in line and str(baseline_classes) in line for line in loaded.splitlines()),cls
    text=fir.read_text()
    queues=re.findall(r'(?m)^\s*inst u_data_cdc_\d+ of LocalMemAsyncQueue(?:_\d+)?\b',text)
    assert len(queues)==4,('all four data queues must use equivalent storage',len(queues))
    assert not any(re.search(r'(?m)^\s*(?:module|inst)\b[^\n]*\b'+n+r'\b',text)
                   for n in ['PackageAddressStats','GHBarrierLatencyStats','bucketSequenceMemory'])
    update('WAITING_MODULE_FORMAL_AND_GENERATED_HOST_GATES',queue_instances=4)
    start=time.monotonic()
    while True:
        formal=Q/'formal-r2/result.json';host=Q/'host-r2/state.json'
        if formal.is_file() and host.is_file() and read(formal)['status'].startswith('PASS_ALL_STATE') and read(host)['status'].startswith('PASS_TWO_CLOCK'):
            break
        if host.is_file() and read(host)['status'].startswith('FAILED'):
            raise RuntimeError('Host token gate failed; version recovery, no full CAD admission')
        if time.monotonic()-start>14400:raise RuntimeError('Bounded module equivalence gate exceeded; no unvalidated system synthesis')
        time.sleep(15)
    area=read(Q/'area-r1/state.json')
    assert area['savings_per_queue']['CLB Registers']>70000 and area['savings_per_queue']['CLB LUTs']>15000
    save(O/'module-admission.json',dict(formal=read(formal),host=read(host),area=area,
        functional_baseline=BASE,whole_system_area_gain_not_assumed=True))
    hostdir=O/'host';hostdir.mkdir()
    log=stage('GOLDENGATE_FULL_HOST',java+['midas.stage.GoldenGateMain','-i',fir,'-td',hostdir,'-faf',anno,
        '-ggcp','ecperformanceonly','-ggcs','HostConfig','--output-filename-base','FireSim-generated'],
        [hostdir/'FireSim-generated.sv',hostdir/'FireSim-generated.synthesis.xdc'])
    assert 'Skipping Combinational Loop Detection' not in log.read_text()
    listing=hostdir/'firrtl_black_box_resource_files.f'
    with (hostdir/'FireSim-generated.sv').open('ab') as f:
        for name in listing.read_text().splitlines() if listing.exists() else []:
            if name.strip():
                p=Path(name.strip());p=p if p.is_absolute() else hostdir/p
                f.write(p.read_bytes()+b'\n')
    assert all(sha(p)==h for p,h in inventory.items()),'Baseline compile closure changed'
    project=O/'project';(project/'bindings').mkdir(parents=True)
    save(project/'bindings'/(hardware+'.json'),dict(source_id=binding['source_id'],frozen_commit='8491167d84b6d9521b151a743673c1516926a1f8',hardware_commit=hardware,profile=PROFILE))
    names=['FireSim-generated.sv','FireSim-generated.defines.vh','FireSim-generated.synthesis.xdc','FireSim-generated.implementation.xdc']
    save(O/'rtl-state.json',dict(status='GOLDENGATE_COMPLETE_NOT_SYNTHESIZED',hardware_commit=hardware,
        source_id=binding['source_id'],goldengate_dir=str(hostdir),configuration_matches_frozen_parameters=True,
        modified_class_origins_verified=True,outputs={str(hostdir/n):sha(hostdir/n) for n in names}))
    cad=load('memory_full_postopt',C/'cad_postopt.py')
    cad.COMMIT,cad.F=hardware,project
    cad.O,cad.L=project/'builds'/('cad-'+hardware[:8]),O
    cad.S,cad.R=O/'cad-state.json',O/'rtl-state.json'
    update('RUNNING_COMPLETE_SHELL_POSTOPT',child_pid=None)
    while True:
        try:cad.main();break
        except BlockingIOError:update('WAITING_OTHER_COMPLETE_SHELL_CAD_LEASE');time.sleep(30)
    resources=cad.utilization(O/'top-postopt-utilization.rpt')
    fit=all(v['used']<=v['available'] for v in resources.values())
    save(O/'postopt-result.json',dict(profile=PROFILE,resources=resources,capacity_fit=fit,legal_routing=False,bitstream=None))
    if not fit:update('NOT_FIT_REAL_COMPLETE_SHELL_RESTRUCTURING_REQUIRED',resources=resources);return
    # Reuse the proven strict route/timing/DRC gate. Start with the new memory
    # netlist as generated; remap MUXFs only on a measured failed placement.
    physical=load('memory_whole_physical',W/'candidates/performance-only-routability-r1-20261114/campaign.py')
    physical.O=O/'physical';physical.O.mkdir();(physical.O/'candidates').mkdir();(physical.O/'tmp').mkdir()
    physical.ST.update(hardware_commit=hardware,functional_baseline=BASE,candidates=[],profile=PROFILE)
    cp=O/'shell-postopt.dcp'
    for name,remap in [('memory-spread-r1',False),('memory-remap-spread-r2',True)]:
        code=physical.physical_code(str(cp),'AltSpreadLogic_high').replace('general.maxThreads 8','general.maxThreads 4')
        if not remap:
            code=code.replace('stage muxf_remap {opt_design -muxf_remap}','puts "EC_MEMORY_NETLIST_UNCHANGED_NO_MUXF_REMAP"')
        result=physical.run(name,code)
        if result.get('routing',{}).get('legal'):
            update('BITSTREAM_GENERATED_RUNTIME_CERTIFICATION_PENDING' if result['bitstream_generated'] else
                   'LEGAL_ROUTE_TIMING_OR_CLOCK_CONSTRAINT_RECOVERY_REQUIRED',physical_result=result)
            return
    update('MEMORY_COMPLETE_SHELL_PHYSICAL_SCREEN_FAILED_RESTRUCTURING_REQUIRED',physical_state=str(physical.O/'state.json'))

if __name__=='__main__':
    try:main()
    except Exception as e:
        if O.is_dir():
            update('FAILED_WITH_EVIDENCE',error=repr(e),child_pid=None)
            state=O/'cad-state.json'
            if state.exists():
                row=read(state);row.update(status='FAILED_WITH_EVIDENCE',error=repr(e),updated_utc=now(),child_pid=None);save(state,row)
        raise
