#!/usr/bin/python3
"""Independent original address RegVec->256R/256W memory prototype.
No live/full target edits. Bounded CPU proof/GG/metasim; local area only later.
"""
import argparse,datetime,fcntl,hashlib,importlib.util,json,os,pathlib,random,resource,subprocess,time
P=pathlib.Path;C=P(__file__).resolve().parent
W=P('/data1/gzh/EC/firesim/final-opt4-20261106');D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
L=D/'build-logs/Opt4-mcrams-address-bucket-r2-20261112';S=D/'Opt4-mcrams-address-bucket-r2-state.json'
FS=W/'C4/chipyard/sims/firesim/sim';ST={}
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def sha(p):
 h=hashlib.sha256()
 with P(p).open('rb') as f:
  for b in iter(lambda:f.read(2**20),b''):h.update(b)
 return h.hexdigest()
def read(p):return json.loads(P(p).read_text())
def save(p,j):
 p=P(p);p.parent.mkdir(parents=True,exist_ok=True);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with q.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(q,p)
def ident(pid=None):
 pid=pid or os.getpid()
 try:a=P(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split();return dict(pid=pid,start_ticks=a[19],host_boot_id=P('/proc/sys/kernel/random/boot_id').read_text().strip())
 except FileNotFoundError:return {}
def update(**kw):ST.update(kw,updated_utc=now());save(S,ST)
def stage(name,args,outputs=(),cwd=C,env=None,expected=0):
 q=L/'receipts'/(name+'.json');log=L/(name+'.log')
 if q.exists():
  r=read(q);assert r['returncode']==expected and all(sha(p)==h for p,h in r['outputs'].items());return r
 assert not log.exists(),'preserve partial evidence; use independent recovery'
 start=time.monotonic();update(status='RUNNING',stage=name)
 with log.open('xb',buffering=0) as f:
  p=subprocess.Popen(args,cwd=cwd,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,env=env);update(child=ident(p.pid))
  while p.poll() is None:
   try:p.wait(timeout=60)
   except subprocess.TimeoutExpired:pass
   update(host_wall_seconds=time.monotonic()-start);os.fsync(f.fileno())
 r=dict(returncode=p.returncode,host_wall_seconds=time.monotonic()-start,argv=args,log=str(log),log_sha256=sha(log),outputs={str(p):sha(p) for p in outputs if P(p).is_file()},completed_utc=now())
 save(q,r);update(child={},last_receipt=str(q));assert p.returncode==expected and all(P(p).is_file() for p in outputs),(name,p.returncode)
 return r
def trace():
 # Independent software old-state oracle; exhaustive address sweep, all-word
 # writes, conflicting retirement/process/reset and global resets are present.
 rng=random.Random(8491167);state=[0]*256;rows=[];hits=dict(resetStats=0,retire_process_conflicts=0,global_reset=0,all_word_updates=0)
 for cycle in range(592):
  reset=cycle in [0,1,137,138,511]
  stats=cycle in [0,1,129,257,513]
  process=cycle>1 and cycle%7!=0;retire=cycle%3==0
  ri=(cycle-2)%256;ci=(cycle*73)%256
  enables=[cycle<258 or rng.randrange(4)!=0 for _ in range(256)]
  data=[rng.getrandbits(64) for _ in range(256)]
  observed=state+[state[ci],state[ri]]
  vals=[int(reset),int(process),int(retire),ri,int(stats),ci]+list(map(int,enables))+data+observed
  rows.append(str(cycle)+' '+' '.join(format(x,'x') for x in vals)+'\n')
  if process:
   for i in range(256):
    if enables[i]:state[i]=data[i]
  if retire:state[ri]=0
  if stats:state=[0]*256
  hits['resetStats']+=stats;hits['global_reset']+=reset;hits['retire_process_conflicts']+=retire and process;hits['all_word_updates']+=process and all(enables)
 (L/'target-cycles.txt').write_text(''.join(rows));return dict(target_cycles=len(rows),checked_values=(len(rows)-1)*258,initial_uninitialized_values_skipped=258,coverage=hits)
def main():
 argparse.ArgumentParser().parse_args();L.mkdir(exist_ok=True);lock=(L/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB);assert not S.exists()
 plan=read(C/'plan.json');assert all(sha(p)==h for p,h in plan['inputs'].items())
 os.sched_setaffinity(0,{246,247});resource.setrlimit(resource.RLIMIT_AS,(24*2**30,24*2**30))
 ST.update(schema='ec-address-bucket-regvec-mcrams-prototype/1',**ident(),started_utc=now(),functional_baseline=BASE,fpga_access=False,whole_dut_equivalence=False,production_admission=False,actual_size=[256,64],ports=dict(read=258,write=256),area_scope='One exact storage-update interface; arithmetic and full address module are not replaced')
 stage('step-proof',['/usr/local/bin/yosys','-p',f'read_verilog {C}/step-proof.v; prep -top StepProof; sat -verify -prove equivalent 1 -show-inputs'])
 stage('mutation-negative',['/usr/local/bin/yosys','-p',f'read_verilog {C}/step-proof.v; prep -top StepProof; sat -verify -prove mutantEquivalent 1 -show-inputs'],expected=1)
 assert 'SUCCESS' in (L/'step-proof.log').read_text() and 'proof did fail' in (L/'mutation-negative.log').read_text()
 summary=trace();save(L/'reference-summary.json',summary)
 cfg=read(W/'candidates/dcache-field-read-system-r1-20261111/config.json');classes=L/'classes';classes.mkdir(exist_ok=True)
 java=[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=2'];cp=str(classes)+':'+':'.join(cfg['classpath'])
 stage('scala-compile',java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',':'.join(cfg['classpath']),'-Xplugin:'+cfg['plugin'],'-d',str(classes),str(C/'Bucket.scala')],outputs=[classes/'opt4bucket/RegBucket.class',classes/'opt4bucket/MemBucket.class'])
 clang='/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++';verilator='/nix/store/bj3wbpawbk71c082cvrnqkfyix7ipx0g-verilator-5.048/bin/verilator'
 env={**os.environ,'CCACHE_DISABLE':'1','LD_LIBRARY_PATH':'','PATH':str(P(clang).parent)+':'+str(P(verilator).parent)+':/usr/bin:/bin','CXX':clang,'CXXFLAGS':'-O1 -I'+str(L/'headers')+' -I'+str(FS/'src/main/cc/midasexamples'),'LDFLAGS':'-L'+str(L/'libs')+' -Wl,-rpath,'+str(L/'libs'),'OMP_NUM_THREADS':'2'}
 for label,harness,config in [('Reg','RegHarness','PlainConfig'),('MemMC','MemHarness','MCConfig')]:
  t=L/(label+'-target');t.mkdir(exist_ok=True);out=L/label;out.mkdir(exist_ok=True)
  stage('elaborate-'+label,java+['-cp',cp,'freechips.rocketchip.system.Generator','--target-dir',str(t),'--name','Bucket','--top-module','opt4bucket.'+harness,'--configs','firesim.midasexamples.NoConfig'],outputs=[t/'Bucket.fir',t/'Bucket.anno.json'])
  if label=='MemMC':
   raw=(t/'Bucket.fir').read_text();assert 'cmem bank : UInt<64>[256]' in raw
  stage('gg-'+label,java+['-cp',cp,'midas.stage.GoldenGateMain','-i',str(t/'Bucket.fir'),'-td',str(out),'-faf',str(t/'Bucket.anno.json'),'-ggcp','opt4bucket','-ggcs',config,'--output-filename-base','FireSim-generated','--no-dedup'],outputs=[out/'FireSim-generated.sv',out/'FireSim-generated.const.h'])
  sv=out/'FireSim-generated.sv';mark=out/'blackboxes-appended.json'
  if not mark.exists():
   with sv.open('a') as f:
    b=out/'firrtl_black_box_resource_files.f'
    for name in b.read_text().splitlines() if b.exists() else []:
     if name.strip():f.write(P(name).read_text())
   save(mark,dict(sha256=sha(sv)))
  stage('compile-'+label,['/usr/bin/make','-C',str(FS/'midas/src/main/cc'),'-j2','verilator','PLATFORM=xilinx_alveo','DRIVER_NAME=Bucket','GEN_DIR='+str(out),'GEN_FILE_BASENAME=FireSim-generated','DRIVER='+str(FS/'src/main/cc/midasexamples/TestHarness.cc')+' '+str(C/'TestBucket.cc'),'VERILATOR_FLAGS=-Wno-fatal -Wno-MULTIDRIVEN','CXX='+clang],outputs=[out/'VBucket'],env=env)
  stage('run-'+label,[str(out/'VBucket'),'+seed=8491167','+max-cycles=100000'],cwd=out,env=env)
  text=(L/('run-'+label+'.log')).read_text();assert '[Bucket]PASS Test' in text and 'BUCKET_TRACE_MISMATCH' not in text
  metric=json.loads(next(l[len('BUCKET_RESULT '):] for l in text.splitlines() if l.startswith('BUCKET_RESULT ')))
  assert metric['target_cycles']==summary['target_cycles'] and metric['checked_values']==summary['checked_values']
  stage('negative-'+label,[str(out/'VBucket'),'+seed=8491167','+max-cycles=100000','+negative'],cwd=out,env=env,expected=1)
  assert 'BUCKET_TRACE_MISMATCH cycle=10' in (L/('negative-'+label+'.log')).read_text()
  ST.setdefault('results',{})[label]=dict(metrics=metric,binary_sha256=sha(out/'VBucket'),host_rtl_sha256=sha(sv),negative_rejected=True);update()
 assert ST['results']['Reg']['metrics']['event_digest']==ST['results']['MemMC']['metrics']['event_digest']
 update(status='PASS_WORD_TRANSITION_LEMMA_AND_FINITE_FULL_WIDTH_ALL_WORD_TARGET_PARITY_AREA_PENDING',completed_utc=now(),scope='One original storage update interface, not full AddressStats or whole DUT equivalence',reference_trace_sha256=sha(L/'target-cycles.txt'),full_debug_retained=True)
 save(L/'result.json',ST)
if __name__=='__main__':
 try:main()
 except Exception as e:
  if ST:update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(L/'failure.json',ST)
  raise
