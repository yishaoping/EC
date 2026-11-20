#!/usr/bin/python3
"""Compile/elaborate actual complete private address targets, no CAD/FPGA."""
import datetime,fcntl,hashlib,json,os,pathlib,resource,subprocess,time
P=pathlib.Path;C=P(__file__).resolve().parent;W=C.parent.parent
D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');O=D/'build-logs/Opt4-mcrams-full-address-storage-r1-20261112';S=D/'Opt4-mcrams-full-address-storage-r1-state.json';ST={}
def read(p):return json.loads(P(p).read_text())
def sha(p):return hashlib.sha256(P(p).read_bytes()).hexdigest()
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def save(p,j):
 p=P(p);p.parent.mkdir(exist_ok=True,parents=True);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with q.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(q,p);d=os.open(p.parent,os.O_RDONLY|os.O_DIRECTORY);os.fsync(d);os.close(d)
def ident(pid=None):
 pid=pid or os.getpid()
 try:a=P(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split();return dict(pid=pid,start_ticks=a[19],host_boot_id=P('/proc/sys/kernel/random/boot_id').read_text().strip(),process_state=a[0])
 except FileNotFoundError:return {}
def update(**kw):ST.update(kw,updated_utc=now());save(S,ST)
def stage(n,argv,outputs):
 r=O/(n+'-receipt.json')
 if r.exists():
  x=read(r);assert x['returncode']==0 and all(sha(p)==h for p,h in x['outputs'].items());return
 log=O/(n+'.log');assert not log.exists(),'partial stage preserved; new recovery version required';start=time.monotonic()
 with log.open('xb',buffering=0) as f:
  p=subprocess.Popen(argv,cwd=C,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'2'},start_new_session=True);update(status='RUNNING_'+n.upper(),child=ident(p.pid),log=str(log))
  while p.poll() is None:
   try:p.wait(timeout=60)
   except subprocess.TimeoutExpired:pass
   update(host_wall_seconds=time.monotonic()-start);os.fsync(f.fileno())
 x=dict(returncode=p.returncode,host_wall_seconds=time.monotonic()-start,argv=argv,outputs={str(p):sha(p) for p in outputs if P(p).exists()},log_sha256=sha(log));save(r,x);update(child={});assert p.returncode==0 and all(P(p).exists() for p in outputs),(n,p.returncode)
def main():
 O.mkdir(exist_ok=True);lk=(O/'instance.lock').open('a');fcntl.flock(lk,fcntl.LOCK_EX|fcntl.LOCK_NB);assert not S.exists()
 plan=read(C/'plan.json');assert all(sha(p)==h for p,h in plan['inputs'].items());os.sched_setaffinity(0,{216,217});resource.setrlimit(resource.RLIMIT_AS,(24*2**30,24*2**30))
 ST.update(schema='ec-private-full-address-target-preparation/1',**ident(),started_utc=now(),fpga_access=False,no_large_CAD=True,cpus=[216,217],memory_limit_gib=24,functional_baseline=plan['functional_baseline'],target_source_sha256=plan['source_sha256'],validation='Not production admitted; compile/elaboration is not full equivalence')
 cfg=read(W/'candidates/dcache-field-read-system-r1-20261111/config.json');cl=O/'classes';cl.mkdir(exist_ok=True);cp=':'.join(cfg['classpath']);java=[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=2']
 stage('scala-compile',java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,'-Xplugin:'+cfg['plugin'],'-d',str(cl),str(C/'PlainPackageAddressStats.scala'),str(C/'MemPackageAddressStats.scala'),str(C/'EmitAddress.scala')],[cl/'opt4addressplain/PackageAddressStats.class',cl/'opt4addressmcrams/PackageAddressStats.class'])
 for label,harness in [('MemMC','MemHarness'),('Plain','PlainHarness')]:
  out=O/label;out.mkdir(exist_ok=True)
  stage('elaborate-'+label,java+['-cp',str(cl)+':'+cp,'freechips.rocketchip.system.Generator','--target-dir',str(out),'--name','Address','--top-module','opt4fulladdress.'+harness,'--configs','firesim.midasexamples.NoConfig'],[out/'Address.fir',out/'Address.anno.json'])
  text=(out/'Address.fir').read_text();assert 'debugBuckets' in text
  if label=='MemMC':
   import re
   memories=re.findall(r'^    cmem (bucket\w+Memory(?:_\d+)?) : UInt<64>\s*\[256\]',text,re.M);assert len(memories)==20,(len(memories),memories)
   ST['actual_twenty_full_width_memories']=memories
 update(status='COMPILED_ELABORATED_COMPLETE_ADDRESS_TARGET_PAIR_NOT_EQUIVALENCE_ADMITTED',completed_utc=now(),next='Consume measured singlebank area; lower both actualtargets, prove target state transitions and preserve every5120debugword; onlypassedcompleteparity/areaadmitsnextwholehost',models={label:{str(p):sha(p) for p in (O/label).glob('*') if p.is_file()} for label in ['Plain','MemMC']});save(O/'result.json',ST)
if __name__=='__main__':
 try:main()
 except Exception as e:
  if ST:update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(O/'failure.json',ST)
  raise
