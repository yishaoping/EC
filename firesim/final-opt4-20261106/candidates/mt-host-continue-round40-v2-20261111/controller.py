#!/usr/bin/python3
"""Isolated continuation from round 39; CPU-only, immutable input capsule."""
from pathlib import Path
import datetime, fcntl, hashlib, json, os, resource, shutil, subprocess, sys, time, traceback

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
C = Path(__file__).resolve().parent
O = D / 'build-logs/Opt4-mt-host-continue-round40-v2-20261111'
S = D / 'Opt4-mt-host-continue-round40-v2-state.json'
PREV = D / 'build-logs/Opt4-mt-clock-repair-round39-v5-20261111'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
NAME = 'mt-host-continue-r40-v2-8491167d'
ST = {}

def read(p): return json.loads(Path(p).read_text())
def now(): return datetime.datetime.now(datetime.timezone.utc).isoformat()
def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda: f.read(4*2**20), b''): h.update(b)
    return h.hexdigest()
def save(p, j):
    p = Path(p); t = p.with_name(p.name + '.tmp-' + str(os.getpid()))
    with t.open('x') as f:
        json.dump(j, f, sort_keys=True, indent=2); f.write('\n'); f.flush(); os.fsync(f.fileno())
    os.replace(t, p)
def policy():
    p = read(U / 'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert not p['functional_extensions_allowed'] and not p['fpga_access'] and p['native_paused']
    assert p['board_allowlist'] == ['0000:21:00.0']
    return p
def ident(pid):
    try:
        fields = Path(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split()
        return dict(pid=pid, start_ticks=fields[19], host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    except FileNotFoundError: return {}
def update(**kw):
    ST.update(kw, updated_utc=now()); save(S, ST)

def prepare():
    policy()
    assert not (C/'plan.json').exists() and not O.exists() and not S.exists()
    previous = read(PREV/'result.json')
    assert previous['status'].startswith('PASS_ORIGINAL_INFER_AND_FAME_')
    assert previous['functional_baseline'] == BASE and previous['check']['returncode'] == 0
    old = read(D/'Opt4-mt-clock-repair-round39-v5-state.json')
    assert ident(old['pid']) != {k:old[k] for k in ['pid','start_ticks','host_boot_id']}
    config_path = W/'candidates/mt-clock-repair-round39-v5-20261111/plan.json'
    cfg = read(config_path)['cfg']
    capsule = C/'evidence'; capsule.mkdir()
    bound = {str(C/'controller.py'):sha(C/'controller.py'), str(C/'Continue.scala'):sha(C/'Continue.scala')}
    copies = {}
    for n in ['result.json','post-fame-transform.fir','post-fame-transform.json']:
        src=PREV/n; expected=previous['outputs'][str(src)] if n!='result.json' else sha(src)
        dst=capsule/n;shutil.copy2(src,dst);assert sha(dst)==expected
        copies[n]=str(dst);bound[str(dst)]=expected
    original_plan=read(config_path)
    for x in dict.fromkeys(cfg['classpath']+cfg['compiler']):
        digest=sha(x);assert digest==original_plan['original_inputs'][x];bound[x]=digest
    source_root=W/'C4/chipyard/sims/firesim/sim/midas/src/main/scala'
    for rel in ['midas/passes/MidasTransforms.scala','midas/stage/GoldenGateCompilerPhase.scala',
                'midas/passes/SimulationMapping.scala','midas/passes/fame/MultiThreadFAME5Models.scala']:
        f=source_root/rel;bound[str(f)]=sha(f)
    bound[str(config_path)]=sha(config_path)
    plan=dict(schema='ec-opt4-host-continuation-plan/1', functional_baseline=BASE,
              inputs=bound,copies=copies,cfg=cfg,created_utc=now(),memory_limit_gib=64,
              guard_memory_gib=96,guard_disk_gib=100,scope='Saved host checkpoint only; original compiler passes; no MT sharing or target changes',
              production_admission=False,fpga_access=False)
    save(C/'plan.json',plan)
    request=dict(action='cpu_job',spec=dict(name=NAME,kind='rtl',cwd=str(C),
        argv=['/usr/bin/python3',str(C/'controller.py'),'--run'],
        inputs={**bound,str(C/'plan.json'):sha(C/'plan.json')},outputs=[str(O/'result.json')],checkpoints=[str(S)]))
    save(C/'request.json',request)
    print(json.dumps(dict(request=str(C/'request.json'),inputs=len(bound))))

def stage(name, argv, timeout):
    policy();log=O/(name+'.log');start=time.monotonic()
    with log.open('xb',buffering=0) as f:
        child=subprocess.Popen(list(map(str,argv)),cwd=O,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,
                               env={**os.environ,'OMP_NUM_THREADS':'2','JAVA_TOOL_OPTIONS':''})
        update(status='RUNNING_'+name.upper(),child=ident(child.pid),stage_log=str(log))
        while True:
            try: rc=child.wait(timeout=30);break
            except subprocess.TimeoutExpired:
                policy();update(stage_wall_seconds=time.monotonic()-start)
                if time.monotonic()-start>timeout:
                    child.terminate()
                    try:child.wait(timeout=30)
                    except subprocess.TimeoutExpired:child.kill();child.wait()
                    raise RuntimeError(('owned_stage_timeout',name))
    r=dict(argv=list(map(str,argv)),returncode=rc,wall_seconds=time.monotonic()-start,log=str(log),
           log_sha256=sha(log),child_peak_rss_kib=resource.getrusage(resource.RUSAGE_CHILDREN).ru_maxrss)
    save(O/(name+'-receipt.json'),r);update(child={});assert rc==0,(name,rc,str(log));return r

def run():
    policy();assert not O.exists() and not S.exists(),'Adopt existing job, preserve partial stages'
    plan=read(C/'plan.json')
    for p,h in plan['inputs'].items():assert sha(p)==h,('changed_input',p)
    O.mkdir();lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    ST.update(schema='ec-opt4-host-continuation-state/1',**ident(os.getpid()),functional_baseline=BASE,
              fpga_access=False,production_admission=False,started_utc=now())
    update(status='WAITING_RESOURCE_GUARDS')
    while True:
        policy()
        available=int(next(l.split()[1] for l in Path('/proc/meminfo').read_text().splitlines() if l.startswith('MemAvailable:')))
        if available>=plan['guard_memory_gib']*2**20 and shutil.disk_usage(O).free>=plan['guard_disk_gib']*2**30:break
        time.sleep(300)
    resource.setrlimit(resource.RLIMIT_AS,(plan['memory_limit_gib']*2**30,)*2)
    cfg=plan['cfg'];cp=':'.join(cfg['classpath']);classes=O/'classes';classes.mkdir()
    compile_receipt=stage('compile',[cfg['java'],'-Xmx4G','-Xss8M','-XX:ActiveProcessorCount=2','-cp',
        ':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,'-d',classes,C/'Continue.scala'],300)
    rtl=O/'goldengate';rtl.mkdir()
    continuation=stage('continue',[cfg['java'],'-Xmx32G','-Xss8M','-XX:ActiveProcessorCount=2','-Dec.dac.firesim=true',
        '-cp',str(classes)+':'+cp,'midas.passes.FrozenMTContinue',plan['copies']['post-fame-transform.fir'],
        plan['copies']['post-fame-transform.json'],rtl],7200)
    assert 'FROZEN_MT_MCRAMS_HOST_RTL_EMITTED_RUNTIME_PARITY_REQUIRED' in (O/'continue.log').read_text()
    required=['FireSim-generated.sv','FireSim-generated.const.h','FireSim-generated.const.vh']
    assert all((rtl/n).stat().st_size>0 for n in required)
    result=dict(schema='ec-opt4-host-continuation-result/1',functional_baseline=BASE,
        status='HOST_RTL_EMITTED_FROM_VERIFIED_CLOCK_CHECKPOINT_RUNTIME_PARITY_REQUIRED',
        compile=compile_receipt,continuation=continuation,outputs={str(f):sha(f) for f in rtl.iterdir() if f.is_file()},
        input_plan_sha256=sha(C/'plan.json'),target_source_changed=False,live_inputs_changed=False,
        mt_sharing_gain_claimed=False,full_target_equivalence=False,whole_fit=False,formal_fpga_sample=False,
        production_admission=False,fpga_access=False,completed_utc=now(),
        next='Authenticate complete ABI/blackbox closure and same-target metasim before area or runtime admission')
    save(O/'result.json',result);update(status=result['status'],result=str(O/'result.json'))

if __name__=='__main__':
    if '--prepare' in sys.argv:prepare()
    elif '--run' in sys.argv:
        try:run()
        except BaseException as e:
            if O.exists():
                save(O/'failure.json',dict(error=repr(e),traceback=traceback.format_exc(),utc=now()))
                update(status='FAILED_WITH_EVIDENCE',error=repr(e))
            raise
    else:raise SystemExit('Use --prepare or --run')
