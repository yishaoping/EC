#!/usr/bin/python3
"""Isolated 3656aec4 real memory-interface -> Golden Gate MCRams experiment.
No DUT edits, FPGA access, full-DUT implementation or tool source changes.
"""
import argparse, collections, fcntl, hashlib, json, os, pathlib, re, resource, shutil, subprocess, sys, time, datetime
P=pathlib.Path
C=P(__file__).resolve().parent
W=P('/data1/gzh/EC/firesim/final-opt4-20261106')
D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
L=D/'build-logs/Opt4-mcrams-dcache-entry-r4-20261111'
S=D/'Opt4-mcrams-dcache-entry-r4-state.json'
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
HW='3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
ROOT=W/'Opt4-fit-dcache-field-read-prune-r1-20261111'
RAW=ROOT/'builds/system-3656aec4-r4/elaborate/firesim.firesim.FireSim.fir'
LOW=ROOT/'builds/system-3656aec4-r4/goldengate/post-bridge-extraction.fir'
SOURCE=ROOT/'chipyard/generators/boom/src/main/scala/lsu/dcache.scala'
FS=W/'C4/chipyard/sims/firesim/sim'
V='/nix/store/bj3wbpawbk71c082cvrnqkfyix7ipx0g-verilator-5.048/bin/verilator'
CLANG='/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++'
ST={}
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def read(p):return json.loads(P(p).read_text()) if P(p).is_file() else {}
def sha(p):
 h=hashlib.sha256()
 with P(p).open('rb') as f:
  for b in iter(lambda:f.read(2**20),b''):h.update(b)
 return h.hexdigest()
def save(p,x):
 p=P(p);p.parent.mkdir(parents=True,exist_ok=True);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with q.open('w') as f:json.dump(x,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(q,p)
def identity(pid=None):
 pid=pid or os.getpid()
 try:
  a=P(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split();return dict(pid=pid,start_ticks=a[19],host_boot_id=P('/proc/sys/kernel/random/boot_id').read_text().strip())
 except FileNotFoundError:return {}
def update(**kw):ST.update(kw,updated_utc=now());save(S,ST);save(L/'state.json',ST)
def stage(n,args,cwd=C,outputs=(),timeout=3600,env=None,expected=0):
 receipt=L/'receipts'/f'{n}.json';old=read(receipt)
 if old and old['returncode']==expected and all(P(k).is_file() and sha(k)==v for k,v in old['outputs'].items()):return old
 if old:raise RuntimeError('failed receipt preserved, independent recovery version required: '+n)
 log=L/(n+'.log');assert not log.exists(),'partial stage requires evidence review: '+n
 update(status='RUNNING',stage=n);start=time.monotonic()
 with log.open('xb',buffering=0) as f:
  p=subprocess.Popen(args,cwd=cwd,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,env=env);update(child=identity(p.pid),argv=args)
  try:rc=p.wait(timeout=timeout)
  except subprocess.TimeoutExpired:
   # Only this new bounded CPU child, never a pre-existing CAD/FPGA process.
   p.terminate()
   try:p.wait(timeout=20)
   except subprocess.TimeoutExpired:p.kill();p.wait()
   rc='TIMEOUT'
  os.fsync(f.fileno())
 r=dict(stage=n,returncode=rc,host_wall_seconds=time.monotonic()-start,completed_utc=now(),log=str(log),log_sha256=sha(log),outputs={str(x):sha(x) for x in outputs if P(x).is_file()},argv=args)
 save(receipt,r);update(child={},last_receipt=str(receipt))
 assert rc==expected and all(P(x).is_file() for x in outputs),(n,rc,str(log))
 return r

def blocks(text):
 lines=text.splitlines();out={}
 for i,l in enumerate(lines):
  m=re.match(r'    mem (owner(?:Image|Generation|Packet|Tracked)Memory(?:_flattened)?) :',l)
  if m:
   j=i+1
   while j<len(lines) and lines[j].startswith('      '):j+=1
   body='\n'.join(lines[i:j])+'\n'
   one=lambda key:re.search(r'^      '+key+r' => (.+)$',body,re.M).group(1)
   out[m.group(1)]=dict(name=m.group(1),line=i+1,data_type=one('data-type'),depth=int(one('depth')),read_latency=int(one('read-latency')),write_latency=int(one('write-latency')),read_under_write=one('read-under-write'),readers=re.findall(r'^      reader => (.+)$',body,re.M),writers=re.findall(r'^      writer => (.+)$',body,re.M),readwriters=re.findall(r'^      readwriter => (.+)$',body,re.M),text=body)
 return out

def verify_shape(x,width,reads):
 assert x['data_type']==f'UInt<{width}>' and x['depth']==512
 assert (x['read_latency'],x['write_latency'],x['read_under_write'])==(0,1,'undefined')
 assert len(x['readers'])==reads and len(x['writers'])==1 and not x['readwriters']

def inventory():
 data=blocks(LOW.read_text());expect=[('ownerImageMemory_flattened',81,35),('ownerGenerationMemory',32,518),('ownerPacketMemory',32,4),('ownerTrackedMemory',1,4)]
 out={}
 for n,width,reads in expect:
  x=data[n];verify_shape(x,width,reads);q=C/'evidence'/f'{n}.fir';q.parent.mkdir(exist_ok=True)
  if q.exists():assert q.read_text()==x['text']
  else:q.write_text(x['text'])
  out[n]={k:v for k,v in x.items() if k!='text'};out[n]['block_sha256']=sha(q)
 source=SOURCE.read_text()
 assert 'when (ownerWriteEnable && !reset.asBool)' in source
 assert 'ownerWritten = RegInit(VecInit(Seq.fill(nSets * nWays)(false.B)))' in source
 assert 'Mux(ownerWritten(index), ownerImageMemory.read(index), 0.U.asTypeOf(new CacheImageKey))' in source
 # Reject wrong port count and changed timing semantics; admission cannot silently reshape interfaces.
 negatives={}
 for key,value in [('read_latency',1),('readers',data['ownerImageMemory_flattened']['readers'][:-1]),('readwriters',['rw'])]:
  v=dict(data['ownerImageMemory_flattened']);v[key]=value
  try:verify_shape(v,81,35)
  except AssertionError:negatives[key]='REJECTED'
  else:raise AssertionError('shape mutation accepted')
 binding=dict(schema='ec-opt4-mcrams-dcache-entry-binding/1',functional_baseline=BASE,derived_hardware_commit=HW,original_target_changed=False,fpga_access=False,full_dut_equivalence=False,
  scope='Real original memory definitions extracted unchanged; new isolated target re-expresses ownerImageMemory raw 35R1W81 shape plus original written-mask/reset gate and observation-only edge capture. Not a complete DCache or whole-system equivalence claim.',
  inputs={str(p):sha(p) for p in [RAW,LOW,SOURCE]},memories=out,negative_shape_checks=negatives,
  reset_semantics='Raw Mem not reset; ownerWritten mask reset synchronously; write gated by !reset; same original single writer, no write collision arbitration change.',
  ordering='Direct target RTL pre-edge trace and independent scoreboard. GG poke-all, stable-peek-all, step-one. Same-cycle read/write outputs and next capture are explicitly undefined;512 paired write-then-no-write checks and512 address sweep prove committed state.')
 save(C/'entry-inventory.json',binding);save(L/'entry-inventory.json',binding);return binding

def main():
 parser=argparse.ArgumentParser();parser.add_argument('--run',action='store_true');args=parser.parse_args();assert args.run
 os.sched_setaffinity(0,sorted(os.sched_getaffinity(0))[:2]);resource.setrlimit(resource.RLIMIT_AS,(24*2**30,24*2**30))
 L.mkdir(parents=True,exist_ok=True);lock=(L/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 plan=read(C/'plan.json');assert all(sha(k)==v for k,v in plan['inputs'].items())
 ST.update(schema='ec-opt4-real-dcache-mcrams-entry/1',**identity(),started_utc=now(),functional_baseline_commit=BASE,hardware_commit=HW,fpga_access=False,production_admission=False,full_dut_equivalence=False,cpus=list(os.sched_getaffinity(0)),memory_limit_bytes=24*2**30)
 update(status='STARTED',stage='entry-inventory');binding=inventory();ST['entry_inventory']=str(L/'entry-inventory.json')
 cfg=read(W/'candidates/dcache-field-read-system-r1-20261111/config.json');classes=L/'classes';classes.mkdir(exist_ok=True)
 java=[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=2'];cp=str(classes)+':'+':'.join(cfg['classpath'])
 stage('scala-compile',java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',':'.join(cfg['classpath']),'-Xplugin:'+cfg['plugin'],'-d',str(classes),str(C/'Entry.scala')],outputs=[classes/'opt4entry/Entry.class'])
 target=L/'target';target.mkdir(exist_ok=True)
 stage('entry-target',java+['-cp',cp,'freechips.rocketchip.system.Generator','--target-dir',str(target),'--name','Entry','--top-module','opt4entry.Entry','--configs','firesim.midasexamples.NoConfig'],outputs=[target/'Entry.fir',target/'Entry.anno.json'])
 # Emit a direct RTL reference of exactly the isolated EntryDUT, not a
 # host-model-derived golden trace. Both host configs consume this same trace.
 whole=(target/'Entry.fir').read_text()
 module=re.search(r'^  module EntryDUT :\n.*?(?=^  (?:ext)?module |\Z)',whole,re.M|re.S)[0]
 direct=L/'reference';direct.mkdir(exist_ok=True)
 # Preserve EntryDUT bytes. The explicit synchronous UInt1 reset belongs
 # only to the direct test wrapper, matching the original harness reset wire.
 typ=re.search(r'^    output io : (.*)$',module,re.M)[1]
 wrapper='  module EntryDirect :\n    input clock : Clock\n    input reset : UInt<1>\n    output io : '+typ+'\n    inst dut of EntryDUT\n    dut.clock <= clock\n    dut.reset <= reset\n'
 for i in range(35):
  wrapper+='    dut.io.address['+str(i)+'] <= io.address['+str(i)+']\n'
  wrapper+='    io.data['+str(i)+'] <= dut.io.data['+str(i)+']\n'
  wrapper+='    io.captured['+str(i)+'] <= dut.io.captured['+str(i)+']\n'
 for n in ['writeAddress','writeData','writeEnable']:wrapper+='    dut.io.'+n+' <= io.'+n+'\n'
 fir=direct/'EntryDUT.fir';fir.write_text('FIRRTL version 1.1.0\ncircuit EntryDirect :\n'+module+'\n'+wrapper)
 sv=direct/'EntryDUT.v'
 stage('reference-rtl',java+['-cp',cp,'firrtl.stage.FirrtlMain','-i',str(fir),'-o',str(sv),'-X','verilog'],outputs=[sv])
 stage('reference-compile',[V,'--cc','--exe','--build','-j2','--assert','-Wno-fatal','--top-module','EntryDirect','--prefix','VEntryDUT','--Mdir',str(direct/'obj'),str(sv),str(C/'DirectEntry.cc')],outputs=[direct/'obj/VEntryDUT'])
 stage('reference-trace',[str(direct/'obj/VEntryDUT')],cwd=L,outputs=[L/'target-cycles.txt',L/'reference-summary.json'])
 ref=read(L/'reference-summary.json')
 assert ref['read_after_write_pairs']==512 and ref['sweep_addresses']==512 and ref['reset_cycles']>5
 assert ref['scoreboard_pass'] and ref['undefined_values_skipped']>0
 # Preserve source target bytes; both host configurations compile exactly this target.
 target_binding={str(p):sha(p) for p in [target/'Entry.fir',target/'Entry.anno.json']};save(L/'target-binding.json',target_binding)
 hdr=L/'headers';hdr.mkdir(exist_ok=True);shutil.copy2('/usr/include/x86_64-linux-gnu/gmp.h',hdr/'gmp.h')
 libs=L/'libs';libs.mkdir(exist_ok=True)
 if not (libs/'libgmp.so').exists():(libs/'libgmp.so').symlink_to('/usr/lib/x86_64-linux-gnu/libgmp.so')
 env={**os.environ,'PATH':str(P(CLANG).parent)+':'+str(P(V).parent)+':/usr/bin:/bin','CXX':CLANG,'LD_LIBRARY_PATH':'','CXXFLAGS':'-O1 -I'+str(hdr)+' -I'+str(FS/'src/main/cc/midasexamples'),'LDFLAGS':'-L'+str(libs)+' -Wl,-rpath,'+str(libs),'OMP_NUM_THREADS':'2'}
 for config in ['PlainConfig','MCConfig']:
  out=L/config;out.mkdir(exist_ok=True)
  stage('gg-'+config,java+['-cp',cp,'midas.stage.GoldenGateMain','-i',str(target/'Entry.fir'),'-td',str(out),'-faf',str(target/'Entry.anno.json'),'-ggcp','opt4entry','-ggcs',config,'--output-filename-base','FireSim-generated','--no-dedup'],outputs=[out/'FireSim-generated.sv',out/'FireSim-generated.const.h'])
  if config=='PlainConfig':
   emitted=blocks((out/'post-bridge-extraction.fir').read_text());image=next(v for k,v in emitted.items() if k.startswith('ownerImageMemory'));verify_shape(image,81,35)
   save(L/'emitted-entry-shape.json',{k:v for k,v in image.items() if k!='text'})
  if not (out/'blackboxes-appended.json').exists():
   with (out/'FireSim-generated.sv').open('a') as f:
    names=out/'firrtl_black_box_resource_files.f'
    for name in names.read_text().splitlines() if names.exists() else []:
     if name.strip():f.write(P(name).read_text())
   save(out/'blackboxes-appended.json',dict(sha256=sha(out/'FireSim-generated.sv')))
  stage('compile-'+config,['/usr/bin/make','-C',str(FS/'midas/src/main/cc'),'-j2','verilator','PLATFORM=xilinx_alveo','DRIVER_NAME=Entry','GEN_DIR='+str(out),'GEN_FILE_BASENAME=FireSim-generated','DRIVER='+str(FS/'src/main/cc/midasexamples/TestHarness.cc')+' '+str(C/'TestEntry.cc'),'VERILATOR_FLAGS=-Wno-fatal -Wno-MULTIDRIVEN','CXX='+CLANG],outputs=[out/'VEntry'],env=env,timeout=3600)
  stage('run-'+config,[str(out/'VEntry'),'+seed=8491167','+max-cycles=100000'],cwd=out,env=env,timeout=1800)
  log=(L/('run-'+config+'.log')).read_text();assert '[Entry]PASS Test' in log and '[Entry]FAIL' not in log and 'unstable value' not in log
  metric=json.loads(next(x[len('ENTRY_RESULT '):] for x in log.splitlines() if x.startswith('ENTRY_RESULT ')))
  ref=read(L/'reference-summary.json')
  assert metric['target_test_cycles']==ref['target_cycles']
  assert metric['checked_values']==ref['compared_values']
  assert metric['undefined_values_skipped']==ref['undefined_values_skipped']
  stage('negative-'+config,[str(out/'VEntry'),'+seed=8491167','+max-cycles=100000','+negative'],cwd=out,env=env,timeout=900,expected=1)
  neg=(L/('negative-'+config+'.log')).read_text();assert 'ENTRY_TRACE_MISMATCH cycle=10' in neg and '[Entry]FAIL Test' in neg
  ST.setdefault('results',{})[config]=dict(metrics=metric,negative_rejected=True,host_rtl_sha256=sha(out/'FireSim-generated.sv'),binary_sha256=sha(out/'VEntry'),target_sha256=target_binding)
  save(L/(config+'-result.json'),ST['results'][config]);update()
 assert ST['results']['PlainConfig']['metrics']['event_digest']==ST['results']['MCConfig']['metrics']['event_digest']
 assert all(sha(k)==v for k,v in target_binding.items())
 update(status='PASS_REAL_DCACHE_MEMORY_INTERFACE_SAME_TARGET_GG_PLAIN_AND_MCRAMS_NOT_FULL_DCACHE',completed_utc=now(),next='Use this bounded memory-interface evidence to admit independent module area measurement and exact-annotation integration; no whole-DUT/FIT/FPGA claim.')
 save(L/'result.json',ST)
if __name__=='__main__':
 try:main()
 except Exception as e:
  if L.exists():update(status='FAILED_WITH_EVIDENCE',error=repr(e));save(L/'failure.json',ST)
  raise
