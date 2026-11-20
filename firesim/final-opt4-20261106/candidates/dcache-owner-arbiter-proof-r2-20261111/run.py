#!/usr/bin/python3
from pathlib import Path
import datetime,hashlib,json,os,fcntl,subprocess
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');C=Path(__file__).resolve().parent
O=D/'build-logs/Opt4-fit-dcache-owner-arbiter-proof-r2-20261111';S=D/'Opt4-fit-dcache-owner-arbiter-proof-r2-state.json'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def save(j):
 t=S.with_name(S.name+'.tmp-'+str(os.getpid()))
 with t.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(t,S)
def identity(pid):
 try:
  v=Path('/proc',str(pid),'stat').read_text().rsplit(')',1)[1].split();return dict(pid=pid,start_ticks=v[19],process_state=v[0],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
 except FileNotFoundError:return {}
def main():
 O.mkdir(exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 cfg=json.loads((C/'config.json').read_text());b=cfg['binding'];F=Path(cfg['worktree']);src=F/cfg['source_relative'];s=src.read_text()
 assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==b['hardware_commit']
 assert 'val dataWriteArb = Module(new Arbiter(new L1DataWriteReq, 2))' in s
 assert 'when (dataWriteArb.io.in(1).fire && refillLastBeat && refillOwnerMatch)' in s
 assert 'when (dataWriteArb.io.in(0).fire)' in s
 assert s.count('ownerWriteEnable := true.B')==2
 st=dict(schema='ec-opt4-owner-arbiter-transition-proof/1',**identity(os.getpid()),status='STARTING',started_utc=now(),hardware_commit=b['hardware_commit'],source_id=b['source_id'],functional_baseline_commit=b['frozen_commit'],source_sha256=sha(src),fpga_access=False,whole_dut_admission=False,stages={})
 def update(**kw):st.update(kw,updated_utc=now());save(st)
 def run(name,args,negative=False):
  log=O/(name+'.log');assert not log.exists()
  with log.open('xb',buffering=0) as f:
   p=subprocess.Popen(list(map(str,['nice','-n','10',*args])),cwd=O,env={**os.environ,'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':''},stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT)
   update(status='RUNNING_'+name.upper(),active_stage=name,child=identity(p.pid))
   while p.poll() is None:
    try:p.wait(timeout=30)
    except subprocess.TimeoutExpired:pass
    update(child=identity(p.pid));os.fsync(f.fileno())
  ok=p.returncode!=0 if negative else p.returncode==0;st['stages'][name]=dict(returncode=p.returncode,accepted=ok,log=str(log),sha256=sha(log));update(child={});assert ok,(name,p.returncode);return log
 update();classes=O/'classes';classes.mkdir(exist_ok=True);cp=':'.join(cfg['classpath'])
 run('compile',[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=2','-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,'-Xplugin:'+cfg['plugin'],'-d',classes,C/'Emit.scala'])
 run('emit',[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=2','-cp',str(classes)+':'+cp,'opt4ownerarbiter.Emit',O])
 rtl=O/'OwnerArbiterTransition.v';assert rtl.is_file()
 for name,negative in [('equivalent',False),('neverBoth',False),('mutationEquivalent',True)]:
  log=run('sat-'+name,['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {rtl}; prep -top OwnerArbiterTransition -flatten; sat -verify -prove io_{name} 1 -timeout 180'],negative=negative)
  text=log.read_text();assert ('proof did fail' if negative else 'SUCCESS') in text and 'timed out' not in text
 update(status='PASS_ACTUAL_ARBITER2_512WORD_WRITE_COALESCING_AND_RESET_INDUCTION_LIFT_TO146_NOT_FULL_DUT_FORMAL',ended_utc=now(),rtl_sha256=sha(rtl),source_bound_write_exclusion=True,proof_scope='Actual chisel3 Arbiter2 full valid/ready controls and arbitrary extra refill guard. Arbitrary512bit stored payload+mask, independent9bit indices and data. Proves original two write effects versus coalesced1W with sync reset; bitwise lifts to146bits. Exact source reversal/typecheck receipt remains required; not full-DCache/full-DUT generated-RTL formal or area admission.')
 (O/'result.json').write_text(json.dumps(st,indent=2,sort_keys=True)+'\n')
if __name__=='__main__':
 try:main()
 except Exception as e:
  if S.exists():
   j=json.loads(S.read_text())
   if j.get('pid')==os.getpid():j.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(j)
  raise
