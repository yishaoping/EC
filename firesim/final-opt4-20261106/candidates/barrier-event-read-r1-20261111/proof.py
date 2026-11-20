#!/usr/bin/python3
"""Detached source-bound local SAT and complete frozen latency comparison.

Only accepted, exact-output checkpoints may be reused. Failed attempts require
a separately versioned recovery. No synthesis, whole build or device access.
"""
from pathlib import Path
import datetime as dt, fcntl, hashlib, json, os, re, shutil, subprocess, time
from generate_tb import generate

C=Path(__file__).resolve().parent
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-fit-barrier-event-read-r1-20261111'
S=D/'Opt4-fit-barrier-event-read-proof-r1-state.json'

def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def read(p): return json.loads(Path(p).read_text()) if Path(p).is_file() else {}
def now(): return dt.datetime.now(dt.timezone.utc).isoformat()
def save(p,x):
    p=Path(p);p.parent.mkdir(parents=True,exist_ok=True);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
    with q.open('w') as f:json.dump(x,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
    os.replace(q,p)
def exact(p,text):
    if p.exists():assert p.read_text()==text,str(p)
    else:p.write_text(text)
def identity(pid):
    try:
        x=Path(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split()
        return dict(pid=pid,start_ticks=x[19],process_state=x[0],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    except FileNotFoundError:return {}
def live(x):
    y=identity(x.get('pid',0))
    return bool(y and all(str(x.get(k))==str(y[k]) for k in ['start_ticks','host_boot_id']) and y['process_state'] not in ['Z','X'])

def main():
    O.mkdir(exist_ok=True);lock=(O/'proof.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    old=read(S);assert not live(old) and not live(old.get('child',{})), 'adopt live controller/child'
    cfg=read(C/'config.json');b=cfg['binding'];F=Path(cfg['worktree']);src=F/cfg['source_relative']
    hashes=read(C/'input-hashes.json');assert all(sha(p)==h for p,h in hashes.items()),'immutable input mismatch'
    assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==b['hardware_commit']
    assert src.read_bytes()==subprocess.check_output(['git','show',b['hardware_commit']+':'+cfg['source_relative']],cwd=F)
    assert subprocess.check_output(['git','diff','--name-only',b['parent_commit'],b['hardware_commit']],cwd=F,text=True).splitlines()==[cfg['source_relative'],'lineage.json']
    # Reconstruct the parent byte-for-byte by reversing only the read change.
    text=src.read_text();parent=(C/'parent.scala.txt').read_text()
    assert text[text.index('  when (io.resetStats)'):].replace('when (!eventValid || eventResolve)','when (!buckets.valid(eventIndex) || bucketResolve(eventIndex))').replace('eventCount + 1.U','buckets.count(eventIndex) + 1.U').replace('eventRequestCycleSum + io.currentCycle','buckets.requestCycleSum(eventIndex) + io.currentCycle') == parent[parent.index('  when (io.resetStats)'):]
    assert text[text.index('  val buckets ='):text.index('  // Decode once')] == parent[parent.index('  val buckets ='):parent.index('  val eventBucketAvailable')]
    st=dict(schema='ec-opt4-barrier-event-read-proof/1',**identity(os.getpid()),hardware_commit=b['hardware_commit'],source_id=b['source_id'],status='STARTING',started_utc=now(),stages=old.get('stages',{}),fpga_access=False,full_dut_formal=False,whole_dut_admission=False,source_sha256=sha(src),limits='Actual256x64 selector SAT plus complete frozen/parent/candidate 8192-cycle comparison of all7 outputs and1024 bucket state fields. Not whole-DUT formal, FIT, timing or FPGA evidence.')
    save(S,st)
    def update(**kw):st.update(kw,updated_utc=now());save(S,st)
    env={**os.environ,'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':'','OMP_NUM_THREADS':'4','CCACHE_DISABLE':'1','MAKEFLAGS':'-j4'}
    def run(label,args,sub,outputs=(),negative=False):
        sub.mkdir(parents=True,exist_ok=True);rp=sub/(label+'-result.json');r=read(rp)
        if r:
            assert r['hardware_commit']==b['hardware_commit'] and r['source_id']==b['source_id']
            assert r['accepted_result'] and not r['missing_outputs'],'failed stage needs versioned recovery'
            assert all(sha(p)==h for p,h in r['outputs'].items());st['stages'][label]=r;save(S,st);return Path(r['log'])
        while int(next(l.split()[1] for l in Path('/proc/meminfo').read_text().splitlines() if l.startswith('MemAvailable:')))<48*2**20 or shutil.disk_usage(W).free<40*2**30:
            update(status='WAITING_RESOURCE_GATE',next_stage=label);time.sleep(300)
        log=sub/(label+'-attempt-1.log');assert not log.exists(),'incomplete stage needs versioned recovery'
        argv=list(map(str,['nice','-n','10',*args]))
        with log.open('xb',buffering=0) as f:
            p=subprocess.Popen(argv,cwd=sub,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT)
            r=dict(hardware_commit=b['hardware_commit'],source_id=b['source_id'],argv=argv,log=str(log),started_utc=now(),**identity(p.pid));st['stages'][label]=r
            update(status='RUNNING_'+label.upper(),child=identity(p.pid),active_stage=label)
            while p.poll() is None:
                try:p.wait(timeout=30)
                except subprocess.TimeoutExpired:pass
                update();os.fsync(f.fileno())
        ok=p.returncode!=0 if negative else p.returncode==0
        r.update(returncode=p.returncode,accepted_result=ok,negative=negative,ended_utc=now(),outputs={str(p):sha(p) for p in outputs if p.is_file()},missing_outputs=[str(p) for p in outputs if not p.is_file()])
        save(rp,r);st['stages'][label]=r;update(child={});assert ok and not r['missing_outputs'],(label,p.returncode,str(log))
        return log
    classes=O/'classes';classes.mkdir(exist_ok=True)
    cp=str(classes)+':'+':'.join(cfg['classpath'])
    compiler=[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',':'.join(cfg['classpath']),'-Xplugin:'+cfg['plugin'],'-d',classes]
    run('compile',compiler+[src,C/'Emit.scala'],O,[classes/'opt4barrierevent/Emit.class'])
    proof=O/'proof/EventReadProof.v';proof.parent.mkdir(exist_ok=True)
    run('emit-proof',[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',cp,'opt4barrierevent.Emit','proof',proof.parent],proof.parent,[proof])
    for prop,negative in [('equivalent',False),('mutantEquivalent',True)]:
        log=run('sat-'+prop,['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {proof}; prep -top EventReadProof -flatten; sat -verify -prove io_{prop} 1 -timeout 180'],proof.parent,negative=negative)
        assert ('proof did fail' if negative else 'SUCCESS') in log.read_text() and 'TIMEOUT' not in log.read_text()
    update(local_formal='PASS_ARBITRARY_256X64_UNQUALIFIED_READ',negative_mutation_rejected=True)
    for variant in ['candidate','parent','frozen']:
        sub=O/variant;sub.mkdir(exist_ok=True);rtl=sub/'GHBarrierLatencyStats.v'
        if variant=='candidate':
            run('emit-'+variant,[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',cp,'opt4barrierevent.Emit','module',sub],sub,[rtl])
        else:
            copied=sub/'BarrierLatencyStats.scala';exact(copied,(C/(variant+'.scala.txt')).read_text())
            refclasses=sub/'classes';refclasses.mkdir(exist_ok=True)
            refcompiler=compiler[:-1]+[refclasses]
            run('compile-'+variant,refcompiler+[copied,C/'EmitReference.scala'],sub,[refclasses/'opt4barrierreference/Emit.class'])
            run('emit-'+variant,[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',str(refclasses)+':'+':'.join(cfg['classpath']),'opt4barrierreference.Emit',sub],sub,[rtl])
        assert len(re.findall(r'^  reg \[63:0\] buckets_count_\d+;',rtl.read_text(),re.M))==256
    sub=O/'comparison';sub.mkdir(exist_ok=True)
    frozen=sub/'FrozenBarrier.v';parentrtl=sub/'ParentBarrier.v'
    exact(frozen,(O/'frozen/GHBarrierLatencyStats.v').read_text().replace('module GHBarrierLatencyStats(','module FrozenBarrier(',1))
    exact(parentrtl,(O/'parent/GHBarrierLatencyStats.v').read_text().replace('module GHBarrierLatencyStats(','module ParentBarrier(',1))
    tb=sub/'tb.v';exact(tb,generate());exe=sub/'compare.vvp'
    run('compile-comparison',['/usr/bin/iverilog','-g2012','-s','tb','-o',exe,frozen,parentrtl,O/'candidate/GHBarrierLatencyStats.v',tb],sub,[exe])
    log=run('complete-comparison',['/usr/bin/vvp',exe],sub)
    assert 'BARRIER_COMPLETE_FROZEN_PARENT_CANDIDATE_PASS cycles=8192 observations=16384 outputs=7 bucket_fields=1024' in log.read_text()
    update(status='PASS_LOCAL_SAT_AND_COMPLETE_FROZEN_8192_CYCLES_MAPPING_PENDING',complete_module_comparison='PASS_ALL7_OUTPUTS_AND1024_BUCKET_STATE_FIELDS_8192_CYCLES',ended_utc=now(),child={},rtl_hashes={v:sha(O/v/'GHBarrierLatencyStats.v') for v in ['frozen','parent','candidate']})
    save(O/'proof-result.json',st)

if __name__=='__main__':
    try:main()
    except Exception as exc:
        state=read(S)
        if state.get('pid')==os.getpid():state.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=now());save(S,state)
        raise
