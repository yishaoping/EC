#!/usr/bin/python3
"""Independent three-writer epoch-register screen; no whole-DUT admission."""
from pathlib import Path
import datetime, fcntl, hashlib, json, os, re, signal, subprocess, time

C=Path(__file__).resolve().parent
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U=D/'unattended-opt4'
O=D/'build-logs/Opt4-fit-slot-epoch-static-r2-20261111'
S=D/'Opt4-fit-slot-epoch-static-r2-state.json'
REL='chipyard/generators/boom/src/main/scala/lsu/'
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
  return dict(pid=pid,start_ticks=a[19],process_state=a[0],host_boot_id=BOOT)
 except FileNotFoundError:return {}
def policy():
 p=read(U/'campaign-policy.json')
 assert p['area_equivalence_only'] and not p['functional_extensions_allowed'] and not p['fpga_access']
 assert p['functional_baseline_commit']=='8491167d84b6d9521b151a743673c1516926a1f8'
 return p
def guard():
 policy();mem={a.split(':')[0]:int(a.split()[1]) for a in Path('/proc/meminfo').read_text().splitlines() if a.startswith('MemAvailable:')}
 fs=os.statvfs(W)
 assert mem['MemAvailable']/1048576>=48 and fs.f_bavail*fs.f_frsize/2**30>=40
def main():
 policy();O.mkdir(exist_ok=False);lock=(O/'instance.lock').open('x');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 b=read(C/'binding.json');cfg=read(C/'toolchain.json');F=Path(b['worktree']);src=F/REL/'dcache.scala';helper=F/REL/'SlotEpochBank.scala'
 assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==b['hardware_commit']
 assert sha(src)==b['dcache_sha256'] and sha(helper)==b['helper_sha256']==sha(C/'SlotEpochBank.scala')
 assert src.read_bytes()==subprocess.check_output(['git','show',b['hardware_commit']+':'+REL+'dcache.scala'],cwd=F)
 delta=subprocess.check_output(['git','diff','--name-only',b['parent_commit'],b['hardware_commit']],cwd=F,text=True).splitlines()
 assert set(delta)=={REL+'dcache.scala',REL+'SlotEpochBank.scala','lineage.json'}
 back=src.read_text()
 for new,old,count in reversed(read(C/'reverse-substitutions.json')):
  assert back.count(new)>=count
  back=back.replace(new,old,count)
 assert back.encode()==subprocess.check_output(['git','show',b['parent_commit']+':'+REL+'dcache.scala'],cwd=F)==(C/'parent.scala.txt').read_bytes()
 # Parent DCache has only the separately proved scanner change from frozen.
 frozen=subprocess.check_output(['git','show',b['frozen_commit']+':'+REL+'dcache.scala'],cwd=F).decode()
 a0=frozen.index('  var contiguous = true.B');a1=frozen.index('  val newSafePacketWatermark',a0)
 b0=back.index('  val safePrefix = Module(new SafePrefixScanner');b1=back.index('  val newSafePacketWatermark',b0)
 assert back[:b0]+frozen[a0:a1]+back[b1:]==frozen
 for forbidden in policy()['forbidden_extension_commits']:
  assert subprocess.run(['git','merge-base','--is-ancestor',forbidden,b['hardware_commit']],cwd=F).returncode==1
 st=dict(schema='ec-opt4-slot-epoch-screen/1',**identity(os.getpid()),**b,status='STARTING',started_utc=now(),stages={},source_reversal_exact=True,inherited_scanner_only_frozen_difference=True,scope='Actual512x16 three-writer storage boundary, complete snapshot and12 arbitrary asynchronous readers. Not complete DCache or whole-DUT equivalence/map.',full_dut_formal=False)
 def update(**kw):st.update(kw);st['updated_utc']=now();save(S,st)
 update();tmp=O/'tmp';tmp.mkdir();env={**os.environ,'TMPDIR':str(tmp),'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':'','CCACHE_DISABLE':'1','OMP_NUM_THREADS':'2'}
 def run(name,argv,outputs=(),negative=False,timeout=7200):
  policy();guard();log=O/(name+'.log');assert not log.exists()
  with log.open('xb',buffering=0) as f:
   p=subprocess.Popen(list(map(str,['nice','-n','10',*argv])),cwd=O,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
   update(status='RUNNING_'+name.upper(),child=identity(p.pid),active_stage=name);start=time.monotonic()
   while p.poll() is None:
    try:p.wait(timeout=30)
    except subprocess.TimeoutExpired:pass
    update(child=identity(p.pid));os.fsync(f.fileno())
    if time.monotonic()-start>timeout:
     os.killpg(p.pid,signal.SIGTERM);p.wait(timeout=60);raise TimeoutError(name)
  good=p.returncode!=0 if negative else p.returncode==0
  st['stages'][name]=dict(returncode=p.returncode,accepted=good,log=str(log),sha256=sha(log),outputs={str(p):sha(p) for p in outputs if Path(p).is_file()})
  update(child={});assert good and all(Path(p).is_file() for p in outputs),(name,p.returncode,str(log))
  return log
 classes=O/'classes';classes.mkdir()
 cp=':'.join([str(W/'Opt4-fit-update-share-svb-r2-20261111/builds/system-e0c3737f-r3/source-classes'),str(W/'C4/chipyard/generators/firechip/target/scala-2.13/firechip_2.13-1.6.jar'),*cfg['classpath']])
 run('compile',[cfg['java'],'-Xmx16G','-Xss8M','-XX:ActiveProcessorCount=2','-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,'-Xplugin:'+cfg['plugin'],'-d',classes,src,helper,F/REL/'SafePrefixScanner.scala',C/'Emit.scala'],[classes/'boom/lsu/BoomNonBlockingDCacheModule.class',classes/'opt4epochstatic/Emit.class'])
 cp=str(classes)+':'+cp;rtl={}
 for mode,top in [('proof','EpochTransition'),('pair','EpochPair'),('reference','EpochReference'),('candidate','EpochCandidate')]:
  sub=O/mode;sub.mkdir();p=sub/(top+'.v')
  run('emit-'+mode,[cfg['java'],'-Xmx16G','-Xss8M','-XX:ActiveProcessorCount=2','-cp',cp,'opt4epochstatic.Emit',mode,sub],[p]);rtl[mode]=p
 proof=rtl['proof']
 log=run('sat-transition',['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {proof}; prep -top EpochTransition -flatten; sat -verify -prove io_equivalent 1 -timeout 240'],timeout=360)
 assert 'SUCCESS' in log.read_text() and 'timed out' not in log.read_text()
 log=run('sat-priority-mutation',['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {proof}; prep -top EpochTransition -flatten; sat -verify -prove io_mutationEquivalent 1 -timeout 60'],negative=True,timeout=180)
 assert 'proof did fail' in log.read_text() and 'timed out' not in log.read_text()
 update(local_transition='PASS_512_ENTRY_ARBITRARY_3WRITER_DATA_PRIORITY_SYNCRESET_READ_DECODE_BITWISE_LIFT_TO16',priority_mutation_rejected=True)
 exe=O/'obj/VEpochPair'
 run('compile-boundary',['/usr/local/bin/verilator','--cc','--exe','--build','-j','2','-Wno-fatal','--top-module','EpochPair','--Mdir',O/'obj','--output-split','10000','--output-split-cfuncs','200','-CFLAGS','-O0','-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',rtl['pair'],C/'boundary.cpp'],[exe],timeout=1800)
 log=run('boundary',[exe],timeout=300);assert 'SLOT_EPOCH_BOUNDARY_PASS cycles=8192' in log.read_text()
 update(boundary='PASS_8192_CYCLES_512X16_3WRITERS_12READERS_COMPLETE_SNAPSHOT_RESET_COLLISION_WRAP')
 maps={}
 for label,top in [('reference','EpochReference'),('candidate','EpochCandidate')]:
  sub=O/label;report=sub/'utilization.rpt';dcp=sub/'module.dcp';tcl=sub/'map.tcl'
  tcl.write_text(f'set_param general.maxThreads 2\nread_verilog {{{rtl[label]}}}\nsynth_design -mode out_of_context -top {top} -part xcu280-fsvh2892-2L-e\nreport_utilization -file {{{report}}}\nwrite_checkpoint -force {{{dcp}}}\nexit 0\n')
  run('map-'+label,['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',sub/'vivado.log','-source',tcl],[report,dcp])
  resources={}
  for line in report.read_text().splitlines():
   m=re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|Block RAM Tile|DSPs)\s*\|\s*([\d,.]+)\s*\|',line)
   if m:resources.setdefault(m[1].rstrip('*'),float(m[2].replace(',','')))
  assert len(resources)==5 and resources['CLB LUTs']>0 and resources['CLB Registers']>=8192
  maps[label]=dict(resources=resources,report=str(report),report_sha256=sha(report),rtl_sha256=sha(rtl[label]),checkpoint=str(dcp));update(maps=maps)
 saving=maps['reference']['resources']['CLB LUTs']-maps['candidate']['resources']['CLB LUTs']
 update(status='COMPLETE_VERIFIED_PAIRED_STORAGE_MAP_FULL_DCACHE_COMPARISON_PENDING_NOT_ADMITTED',maps=maps,storage_boundary_luts_saved=saving,ended_utc=now(),child={},remaining=['Frozen complete DCache cycle/observation comparison','Actual complete DCache paired mapping','Source-bound composition with selected candidates before any whole admission'])
 save(O/'result.json',st)
if __name__=='__main__':
 try:main()
 except Exception as e:
  if S.exists():
   j=read(S)
   if j.get('pid')==os.getpid():j.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(S,j)
  raise
