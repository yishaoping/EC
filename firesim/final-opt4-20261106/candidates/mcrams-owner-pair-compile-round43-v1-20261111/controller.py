#!/usr/bin/python3
"""Prepare and compile two exact-target CPU models, with each model's own ABI.

No GG regeneration, synthesis, runtime workload, device access or admission.
The broker may defer this ordinary module job; it never takes an auxiliary slot.
"""
import argparse
import datetime
import fcntl
import hashlib
import json
import os
from pathlib import Path
import resource
import shutil
import subprocess
import time
import traceback

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
C = Path(__file__).resolve().parent
O = D/'cycleprecise-owner-pair-compile-round43-v1-20261111'
S = D/'Opt4-mcrams-owner-pair-compile-round43-v1-state.json'
AUDIT = D/'build-logs/Opt4-mcrams-dcache-owner-audit-round43-r3-20261111'
PRODUCER = D/'build-logs/Opt4-mcrams-dcache-owner-system-r1-20261111'
PLAIN_GG = W/'Opt4-fit-dcache-field-read-prune-r1-20261111/builds/system-3656aec4-r4/goldengate'
TEMPLATE = D/'cycleprecise-frozen-full-metasim-r1-20261111'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
HARDWARE = '3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
SOURCE_ID = '79aedd9ada6137e018d7f9c9c175fd4a06f53820d235ddcbe4b4a185e75fd68d'
NAME = 'mcrams-owner-pair-compile-r43-v1-3656aec4'
ST = {}

def now(): return datetime.datetime.now(datetime.timezone.utc).isoformat()
def read(p): return json.loads(Path(p).read_text())
def sha(p):
    h=hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda:f.read(2**20),b''): h.update(b)
    return h.hexdigest()
def save(p,j):
    p=Path(p);t=p.with_name(p.name+'.tmp-'+str(os.getpid()))
    with t.open('x') as f:
        json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
    os.replace(t,p)
def policy():
    p=read(U/'campaign-policy.json')
    assert p['functional_baseline_commit']==BASE
    assert p['area_equivalence_only'] and not p['functional_extensions_allowed']
    assert p['native_paused'] and not p['fpga_access']
    assert p['board_allowlist']==['0000:21:00.0']
    return p
def ident(pid):
    try:
        st=Path(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split()
        return dict(pid=pid,start_ticks=st[19],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    except FileNotFoundError: return {}
def update(**kw):
    ST.update(kw,updated_utc=now());save(S,ST)
def bind_copy(p,q,inputs,staged):
    h=sha(p);q.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(p,q)
    assert sha(q)==h
    inputs[str(p)]=h;staged[str(q)]=h

def prepare():
    policy()
    assert not O.exists() and not S.exists() and not (C/'plan.json').exists(), 'adopt existing stage'
    a=read(AUDIT/'result.json');completed=read(AUDIT/'complete.json')
    assert sha(AUDIT/'result.json')==completed['result_sha256']
    assert a['status']=='PASS_EXACT_FULL_PREHOST_TARGET_AND_DCACHE_WRAPPER_NOT_FULL_HOST_PARITY_OR_FIT'
    assert a['functional_baseline']==BASE and a['derived_hardware']==HARDWARE
    assert a['complete_prehost_target_byte_identical'] and a['all_35_read_ports_preserved']
    assert a['all_518_generation_debug_observations_preserved_by_exact_DCache_comparison']
    assert not a['whole_fit'] and not a['full_host_parity_passed']
    mc=read(PRODUCER/'result.json');assert sha(mc['host_rtl'])==mc['host_rtl_sha256']
    cfg=read(W/'candidates/mcrams-dcache-owner-system-r1-20261111/plan.json')
    pb=read(TEMPLATE/'binding.json')
    inputs={str(C/'controller.py'):sha(C/'controller.py'),**cfg['inputs'],**cfg['evidence_sources']}
    inputs.update(read(AUDIT/'input-binding.json'))
    for p in [AUDIT/'result.json',AUDIT/'complete.json',AUDIT/'input-binding.json',
              PRODUCER/'result.json',TEMPLATE/'binding.json']:
        inputs[str(p)]=sha(p)
    # These are complete source-bound compiler/module validation receipts.
    for name in ['Opt4-fit-dcache-field-read-prune-r1-state.json',
                 'Opt4-fit-dcache-field-read-generated-r2-state.json',
                 'Opt4-fit-dcache-field-read-exact-identity-round31-v4-state.json']:
        p=D/name;j=read(p)
        assert j['hardware_commit']==HARDWARE and j['source_id']==SOURCE_ID
        assert j['status'].startswith('PASS_')
        inputs[str(p)]=sha(p)
    for p,h in inputs.items(): assert sha(p)==h, p
    O.mkdir();staged={}
    for dirname in ['external-headers','external-libs']:(O/dirname).mkdir()
    for p in sorted((TEMPLATE/'external-headers').iterdir()):
        assert p.is_file();bind_copy(p,O/'external-headers'/p.name,inputs,staged)
    for p in sorted((TEMPLATE/'external-libs').iterdir()):
        target=p.resolve();inputs[str(target)]=sha(target);(O/'external-libs'/p.name).symlink_to(target)
    modes=[]
    collateral=['FireSim-generated.sv','FireSim-generated.const.h','FireSim-generated.const.vh',
                'FireSim-generated.defines.vh','FireSim-generated.synthesis.xdc',
                'FireSim-generated.implementation.xdc']
    for label,src,driver in [('MC',PRODUCER/'goldengate','OwnerMCRams3656'),
                             ('Plain',PLAIN_GG,'OwnerPlain3656')]:
        out=O/label/'host';out.mkdir(parents=True)
        for name in collateral:bind_copy(src/name,out/name,inputs,staged)
        for name in ['dromajo_params.h']:
            p=TEMPLATE/'host'/name
            if p.exists():bind_copy(p,out/name,inputs,staged)
        # Never reuse the frozen model's generated address map or driver.
        command=[a.replace('DRIVER_NAME=FrozenOpt4','DRIVER_NAME='+driver)
                  .replace(str(TEMPLATE/'host'),str(out)) for a in pb['command']]
        assert 'GEN_DIR='+str(out) in command
        driverarg=next(a for a in command if a.startswith('DRIVER='))
        libraries=[p for p in driverarg[len('DRIVER='):].split() if p.endswith('.a')]
        for name in driverarg[len('DRIVER='):].split():
            p=Path(name);inputs[str(p)]=sha(p)
            assert inputs[str(p)]==pb['input_sha256'][str(p)]
        env={k:v.replace(str(TEMPLATE),str(O)) for k,v in pb['environment'].items()}
        env['LDFLAGS']+=' '+' '.join(libraries)+' -lstdc++ -lpthread -lgmp -l:libdwarf.so -l:libelf.so -lz'
        env.update(MAKEFLAGS='-j2',OMP_NUM_THREADS='2',CCACHE_DISABLE='1',LD_LIBRARY_PATH='')
        modes.append(dict(label=label,command=command,environment=env,
            binary=str(out/('V'+driver)),host_dir=str(out),
            source_host_rtl=str(src/'FireSim-generated.sv'),
            host_rtl_sha256=inputs[str(src/'FireSim-generated.sv')],
            generated_headers_from_matching_model=True,existing_driver_reused=False))
    fs=W/'C4/chipyard/sims/firesim/sim'
    roots=[fs/'midas/src/main/cc',fs/'firesim-lib/src/main/cc',fs/'src/main/cc/firesim',
           fs/'midas/src/main/verilog',W/'C4/chipyard/generators/testchipip/src/main/resources/testchipip/csrc']
    for root in roots:
        for p in root.rglob('*'):
            if p.is_file() and (p.suffix in ['.h','.hpp','.cc','.v','.sv'] or p.name=='Makefile' or p.name.startswith('Makefrag')):
                inputs[str(p)]=sha(p)
    for tool in [pb['environment']['CXX'],'/nix/store/bj3wbpawbk71c082cvrnqkfyix7ipx0g-verilator-5.048/bin/verilator']:
        inputs[tool]=sha(tool)
    plan=dict(schema='ec-owner-same-target-paired-host-compile-plan/1',functional_baseline=BASE,
        hardware_commit=HARDWARE,source_id=SOURCE_ID,created_utc=now(),modes=modes,
        complete_prehost_target_sha256=a['complete_prehost_target_sha256'],
        raw_target_fir_sha256=sha(W/'Opt4-fit-dcache-field-read-prune-r1-20261111/builds/system-3656aec4-r4/elaborate/firesim.firesim.FireSim.fir'),
        input_sha256=inputs,staged_sha256=staged,
        comparison_scope='Same 3656 complete target and original observations, Plain host versus existing ten RF annotations plus one ownerImageMemory annotation; compile is not target parity.',
        max_compile_jobs=2,address_space_limit_gib=64,minimum_memory_gib=96,minimum_disk_gib=100,
        sequential_models=True,compile_only=True,runtime_started=False,full_host_parity_passed=False,
        whole_cad=False,whole_fit=False,production_admission=False,fpga_access=False,
        next='After both compile receipts, prepare exact same ELF/input/DRAM timing pair and stall-aware target-cycle/print/checker/SVB trace comparisons. Preserve r5 and existing full-MCRams run; no parallel second Canneal.')
    save(O/'build-plan.json',plan);save(C/'plan.json',plan)
    # The broker requires source inputs to reside under W. Copy external
    # evidence into a capsule; the compile phase checks original paths too.
    capsule=C/'evidence';capsule.mkdir();bound={};copies={}
    for name,h in inputs.items():
        p=Path(name)
        if p.resolve().is_relative_to(W):bound[name]=h
        else:
            q=capsule/(h[:16]+'-'+p.name)
            if not q.exists():shutil.copy2(p,q)
            assert sha(q)==h;bound[str(q)]=h;copies[name]=str(q)
    save(C/'evidence-copies.json',copies)
    for p in [C/'plan.json',C/'evidence-copies.json']:bound[str(p)]=sha(p)
    req=dict(action='cpu_job',spec=dict(name=NAME,kind='module',cwd=str(C),
        argv=['/usr/bin/python3',str(C/'controller.py'),'--compile'],inputs=bound,
        outputs=[str(O/'result.json')],checkpoints=[str(S)]))
    save(C/'request.json',req)
    print(json.dumps(dict(prepared=str(O/'build-plan.json'),input_files=len(inputs),
        staged_files=len(staged),request=str(C/'request.json'),submitted=False)))

def compile_pair():
    policy();lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not S.exists() and not (O/'result.json').exists(), 'use a versioned recovery after any partial run'
    plan=read(O/'build-plan.json');assert sha(C/'plan.json')==sha(O/'build-plan.json')
    for p,h in {**plan['input_sha256'],**plan['staged_sha256']}.items():assert sha(p)==h, p
    ST.update(schema='ec-owner-paired-host-compile-state/1',**ident(os.getpid()),
        functional_baseline=BASE,hardware_commit=HARDWARE,source_id=SOURCE_ID,
        started_utc=now(),status='WAITING_RESOURCE_GUARDS',fpga_access=False,compile_only=True)
    update()
    resource.setrlimit(resource.RLIMIT_AS,(64*2**30,64*2**30))
    results=[]
    for mode in plan['modes']:
        policy()
        while True:
            available=int(next(l.split()[1] for l in Path('/proc/meminfo').read_text().splitlines() if l.startswith('MemAvailable:')))
            if available>=96*2**20 and shutil.disk_usage(O).free>=100*2**30:break
            update(status='WAITING_RESOURCE_GUARDS',next_mode=mode['label']);time.sleep(300);policy()
        label=mode['label'];b=Path(mode['binary']);log=O/label/'compile-attempt-1.log'
        assert not b.exists() and not Path(str(b)+'.csrc').exists() and not log.exists(), 'never overwrite partial compilation'
        start=time.monotonic()
        with log.open('xb',buffering=0) as out:
            p=subprocess.Popen(mode['command'],cwd=C,env={**os.environ,**mode['environment']},
                stdin=subprocess.DEVNULL,stdout=out,stderr=subprocess.STDOUT)
            update(status='RUNNING_'+label.upper()+'_HOST_COMPILE',child=ident(p.pid),log=str(log))
            while p.poll() is None:
                try:p.wait(timeout=300)
                except subprocess.TimeoutExpired:pass
                os.fsync(out.fileno());update(host_wall_seconds=time.monotonic()-start)
        receipt=dict(label=label,returncode=p.returncode,host_wall_seconds=time.monotonic()-start,
            log=str(log),log_sha256=sha(log),binary=str(b),binary_sha256=sha(b) if b.is_file() else None,
            generated_const_h_sha256=sha(Path(mode['host_dir'])/'FireSim-generated.const.h'),
            build_plan_sha256=sha(O/'build-plan.json'),completed_utc=now())
        save(O/label/'compile-receipt.json',receipt);results.append(receipt)
        update(child={},last_receipt=str(O/label/'compile-receipt.json'))
        assert p.returncode==0 and b.is_file(), 'preserve failure; independent recovery required'
    result=dict(status='BUILT_BOTH_SAME_TARGET_HOST_MODELS_FULL_PARITY_AND_AREA_PENDING',
        functional_baseline=BASE,hardware_commit=HARDWARE,source_id=SOURCE_ID,
        build_plan_sha256=sha(O/'build-plan.json'),models=results,completed_utc=now(),
        runtime_started=False,full_host_parity_passed=False,production_admission=False,
        whole_fit=False,whole_cad=False,fpga_access=False,next=plan['next'])
    save(O/'result.json',result);update(status=result['status'],result=str(O/'result.json'))

if __name__=='__main__':
    ap=argparse.ArgumentParser();ap.add_argument('--prepare',action='store_true');ap.add_argument('--compile',action='store_true');a=ap.parse_args()
    try:
        assert a.prepare != a.compile
        prepare() if a.prepare else compile_pair()
    except Exception as exc:
        if O.exists():
            save(O/('prepare-failure.json' if a.prepare else 'compile-failure.json'),dict(error=repr(exc),traceback=traceback.format_exc(),utc=now()))
            if ST:update(status='FAILED_WITH_EVIDENCE',error=repr(exc))
        raise
