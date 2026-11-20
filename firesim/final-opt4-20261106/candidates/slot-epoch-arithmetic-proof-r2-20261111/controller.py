#!/usr/bin/python3
"""Light full16-bit transition proof; no mapping, elaboration or FPGA access."""
from pathlib import Path
import datetime,fcntl,hashlib,json,os,subprocess,time
C=Path(__file__).resolve().parent
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
B=W/'candidates/slot-epoch-static-r2-20261111'
O=D/'build-logs/Opt4-fit-slot-epoch-arithmetic-proof-r2-20261111'
S=D/'Opt4-fit-slot-epoch-arithmetic-proof-r2-state.json'
def read(p):return json.loads(Path(p).read_text())
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def save(p,j):
 p=Path(p);p.parent.mkdir(parents=True,exist_ok=True);tmp=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with tmp.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(tmp,p)
BOOT=Path('/proc/sys/kernel/random/boot_id').read_text().strip()
def identity(pid):
 try:
  a=(Path('/proc')/str(pid)/'stat').read_text().rsplit(')',1)[1].split()
  return dict(pid=pid,start_ticks=a[19],host_boot_id=BOOT,process_state=a[0])
 except FileNotFoundError:return {}
def policy():
 p=read(D/'unattended-opt4/campaign-policy.json');assert p['area_equivalence_only'] and not p['fpga_access'] and not p['functional_extensions_allowed']
def main():
 policy();O.mkdir(exist_ok=False);lock=(O/'instance.lock').open('x');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 b=read(B/'binding.json');cfg=read(B/'toolchain.json');F=Path(b['worktree']);rel='chipyard/generators/boom/src/main/scala/lsu/'
 src=F/rel/'dcache.scala';helper=F/rel/'SlotEpochBank.scala'
 assert sha(src)==b['dcache_sha256'] and sha(helper)==b['helper_sha256']
 source=src.read_text();parent=(B/'parent.scala.txt').read_text();back=source
 for new,old,count in reversed(read(B/'reverse-substitutions.json')):back=back.replace(new,old,count)
 assert back==parent
 assert source.count('"slot epoch exhausted"')==parent.count('"slot epoch exhausted"')==3
 assert 'slotEpochBank.write(0, pset, pway, slotEpochBank.read(pset, pway) + 1.U)' in source
 assert 'slotEpochBank.write(1, crossPackagePendingSet, crossPackagePendingWay,\n      slotEpochBank.read(crossPackagePendingSet, crossPackagePendingWay) + 1.U)' in source
 assert 'slotEpochBank.write(2, set, way, reservedEpoch(set)(way))' in source
 assert 'for (i <- 0 until entries; p <- 0 until 3)' in helper.read_text()
 st=dict(schema='ec-opt4-epoch-arithmetic-proof/1',**identity(os.getpid()),hardware_commit=b['hardware_commit'],source_id=b['source_id'],frozen_commit=b['frozen_commit'],status='STARTING',stages={},started_utc=now(),source_bound=True,fpga_access=False,whole_dut_admission=False,scope='Full16bit per-word arithmetic/priority/reset proof, complementary to independent full512-entry decode proof; not fullDCache RTL formal or area evidence.')
 def update(**kw):st.update(kw);st['updated_utc']=now();save(S,st)
 update();env={**os.environ,'JAVA_TOOL_OPTIONS':'','LD_LIBRARY_PATH':'','CCACHE_DISABLE':'1','OMP_NUM_THREADS':'1'}
 def run(name,argv,negative=False):
  policy();log=O/(name+'.log');assert not log.exists()
  with log.open('xb',buffering=0) as f:
   p=subprocess.Popen(list(map(str,['nice','-n','10',*argv])),cwd=O,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT)
   update(status='RUNNING_'+name.upper(),child=identity(p.pid))
   while p.poll() is None:
    try:p.wait(timeout=30)
    except subprocess.TimeoutExpired:pass
    update(child=identity(p.pid));os.fsync(f.fileno())
  good=p.returncode!=0 if negative else p.returncode==0
  st['stages'][name]=dict(returncode=p.returncode,accepted=good,log=str(log),sha256=sha(log));update(child={})
  assert good,(name,p.returncode,str(log));return log
 classes=O/'classes';classes.mkdir();cp=':'.join(cfg['classpath'])
 run('compile',[cfg['java'],'-Xmx4G','-Xss4M','-XX:ActiveProcessorCount=1','-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,'-Xplugin:'+cfg['plugin'],'-d',classes,C/'Emit.scala'])
 rtl=O/'EpochArithmetic.v'
 run('emit',[cfg['java'],'-Xmx4G','-Xss4M','-XX:ActiveProcessorCount=1','-cp',str(classes)+':'+cp,'opt4epocharithmetic.Emit',O]);assert rtl.is_file()
 for name,signal in [('sat-full16','io_equivalent'),('sat-wrap','io_wraps'),('sat-independent','io_independentWrite'),('sat-negative','io_mutationEquivalent')]:
  negative=name=='sat-negative'
  log=run(name,['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {rtl}; prep -top EpochArithmetic -flatten; sat -verify -prove {signal} 1 -timeout 120'],negative)
  text=log.read_text();assert 'timed out' not in text
  assert ('proof did fail' in text) if negative else ('SUCCESS' in text)
 update(status='PASS_SOURCE_BOUND_FULL16BIT_ARITHMETIC_RESET_PRIORITY_WRAP_AND_NEGATIVE_MUTATION_NOT_FULL_DCACHE',ended_utc=now(),child={},generated_rtl_sha256=sha(rtl),remaining='Queued actual512-entry decode, generated-helper8192-cycle boundary, paired storage maps, then complete frozen DCache comparison/map and composed verification remain required.')
 save(O/'result.json',st)
if __name__=='__main__':
 try:main()
 except Exception as e:
  if S.exists():
   j=read(S)
   if j.get('pid')==os.getpid():j.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(S,j)
  raise
