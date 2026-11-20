#!/usr/bin/python3
"""Source-bound installedImage proof or paired local map, never whole CAD."""
from pathlib import Path
import datetime, fcntl, hashlib, json, os, re, signal, subprocess, sys, time
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');U=D/'unattended-opt4'
C=W/'candidates/reservation-memory-r1-20261111'
MODE='map'
assert MODE in ('proof','map')
O=D/('build-logs/Opt4-fit-reservation-'+MODE+'-r3-20261111')
S=D/('Opt4-fit-reservation-'+MODE+'-r3-state.json')
REL='chipyard/generators/boom/src/main/scala/lsu/'
def read(p):return json.loads(Path(p).read_text())
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def save(p,j):
 p=Path(p);p.parent.mkdir(parents=True,exist_ok=True);t=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with t.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(t,p)
def policy():
 p=read(U/'campaign-policy.json')
 assert p['area_equivalence_only'] and not p['functional_extensions_allowed'] and not p['fpga_access']
 assert p['functional_baseline_commit']=='8491167d84b6d9521b151a743673c1516926a1f8'
 return p
BOOT=Path('/proc/sys/kernel/random/boot_id').read_text().strip()
def identity(pid):
 try:
  x=Path('/proc',str(pid),'stat').read_text().rsplit(')',1)[1].split()
  return dict(pid=pid,start_ticks=x[19],host_boot_id=BOOT,process_state=x[0])
 except FileNotFoundError:return {}
def guard():
 policy();mem=int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:')))
 disk=os.statvfs(W)
 assert mem>=48*1048576 and disk.f_bavail*disk.f_frsize>=40*2**30
def main():
 policy();O.mkdir(exist_ok=False);lock=(O/'instance.lock').open('x');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 b=read(C/'binding-r2.json');F=Path(b['worktree']);src=F/REL/'dcache.scala'
 assert sha(src)==b['dcache_sha256']
 assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==b['hardware_commit']
 assert src.read_bytes()==subprocess.check_output(['git','show',b['hardware_commit']+':'+REL+'dcache.scala'],cwd=F)
 assert set(subprocess.check_output(['git','diff','--name-only',b['parent_commit'],b['hardware_commit']],cwd=F,text=True).splitlines())=={REL+'dcache.scala','lineage.json'}
 back=src.read_text()
 for old,new in reversed(read(C/'replacements.json')):
  assert back.count(new)==1,new
  back=back.replace(new,old)
 assert back==(C/'parent.scala.txt').read_text()
 assert back.encode()==subprocess.check_output(['git','show',b['parent_commit']+':'+REL+'dcache.scala'],cwd=F)
 # Authenticate the full inherited DCache delta against the frozen source.
 frozen=W/'C4'/REL/'dcache.scala';original=frozen.read_text()
 a0=original.index('  var contiguous = true.B');a1=original.index('  val newSafePacketWatermark',a0)
 z0=back.index('  val safePrefix = Module(new SafePrefixScanner');z1=back.index('  val newSafePacketWatermark',z0)
 assert back[:z0]+original[a0:a1]+back[z1:]==original
 for commit in policy()['forbidden_extension_commits']:
  assert subprocess.run(['git','merge-base','--is-ancestor',commit,b['hardware_commit']],cwd=F).returncode==1
 assert src.read_text().count('assert(')==back.count('assert(')
 assert src.read_text().count('printf(')==back.count('printf(')
 assert src.read_text().count('dontTouch(')==back.count('dontTouch(')
 helper=src.read_text().split('  class ReservationStorage',1)[1].split('  val installedImage =',1)[0]
 assert ('  class ReservationStorage'+helper) in (C/'Emit.scala').read_text()
 geometry=read(C/'frozen-geometry-r2.json')
 assert sha(geometry['frozen_rtl'])==geometry['frozen_rtl_sha256'] and geometry['reservedTag_width']==23
 st={**b,**identity(os.getpid()),'schema':'ec-opt4-reservation-'+MODE+'/1','status':'STARTING','started_utc':now(),'stages':{},'full_dut_formal':False,'exact_source_reversal':True,'inherited_scanner_only_frozen_difference':True,'scope':'512x80 uninitialized five-field reservation storage, five independent async readers. Local screen only; actual field aliases and generated fullmodule mapping remain required. Complete frozen DCache cycle comparison and complete-module area remain required.'}
 def update(**kw):st.update(kw);st['updated_utc']=now();save(S,st)
 update();tmp=O/'tmp';tmp.mkdir()
 env={**os.environ,'TMPDIR':str(tmp),'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':'','CCACHE_DISABLE':'1','OMP_NUM_THREADS':'2'}
 def run(name,argv,outputs=(),negative=False,timeout=1800):
  guard();log=O/(name+'.log');assert not log.exists()
  with log.open('xb',buffering=0) as f:
   p=subprocess.Popen(list(map(str,['nice','-n','10',*argv])),cwd=O,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
   update(status='RUNNING_'+name.upper(),active_stage=name,child=identity(p.pid));start=time.monotonic()
   while p.poll() is None:
    try:p.wait(timeout=30)
    except subprocess.TimeoutExpired:pass
    update(child=identity(p.pid));os.fsync(f.fileno())
    if time.monotonic()-start>timeout:
     os.killpg(p.pid,signal.SIGTERM);p.wait(timeout=60);raise TimeoutError(name)
  good=p.returncode!=0 if negative else p.returncode==0
  st['stages'][name]=dict(returncode=p.returncode,accepted=good,argv=list(map(str,argv)),log=str(log),sha256=sha(log),outputs={str(x):sha(x) for x in outputs if Path(x).is_file()})
  update(child={});assert good and all(Path(x).is_file() for x in outputs),(name,p.returncode,str(log))
  return log
 if MODE=='proof':
  cfg=read(C/'toolchain.json');classes=O/'classes';classes.mkdir()
  cp=':'.join([str(W/'Opt4-fit-update-share-svb-r2-20261111/builds/system-e0c3737f-r3/source-classes'),str(W/'C4/chipyard/generators/firechip/target/scala-2.13/firechip_2.13-1.6.jar'),*cfg['classpath']])
  run('compile',[cfg['java'],'-Xmx16G','-Xss8M','-XX:ActiveProcessorCount=2','-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,'-Xplugin:'+cfg['plugin'],'-d',classes,src,F/REL/'SafePrefixScanner.scala',C/'Emit.scala'],[classes/'boom/lsu/BoomNonBlockingDCacheModule.class',classes/'opt4reservation/Emit.class'])
  rtls={}
  for mode,top in [('proof','ReservationTransition'),('pair','ReservationPair'),('reference','ReservationReference'),('candidate','ReservationCandidate')]:
   sub=O/mode;sub.mkdir();rtl=sub/(top+'.v')
   log=run('emit-'+mode,[cfg['java'],'-Xmx16G','-Xss8M','-XX:ActiveProcessorCount=2','-cp',str(classes)+':'+cp,'opt4reservation.Emit',mode,sub],[rtl])
   assert 'sets=256 ways=2 bits=80 fields=16,32,8,1,23 writers=1 reset=uninitialized' in log.read_text();rtls[mode]=rtl
  proof=rtls['proof']
  log=run('sat-transition',['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {proof}; prep -top ReservationTransition -flatten; sat -verify -prove io_equivalent 1 -timeout 240'],timeout=360)
  assert 'SUCCESS' in log.read_text() and 'timed out' not in log.read_text()
  log=run('sat-write-data-mutation',['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {proof}; prep -top ReservationTransition -flatten; sat -verify -prove io_mutationEquivalent 1 -timeout 60'],negative=True,timeout=180)
  assert 'proof did fail' in log.read_text() and 'timed out' not in log.read_text()
  topology=O/'memory-topology.json'
  run('topology',['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {rtls["candidate"]}; hierarchy -top ReservationCandidate; proc; opt_clean; memory_collect; write_json {topology}'],[topology])
  cells=read(topology)['modules']['ReservationCandidate']['cells'];mems=[v for v in cells.values() if v['type']=='$mem_v2']
  assert mems and sum(int(x['parameters']['WIDTH'],2) for x in mems)==80
  for x in mems:
   q=x['parameters'];assert int(q['SIZE'],2)==512 and int(q['RD_PORTS'],2)==5 and int(q['WR_PORTS'],2)==1
   assert int(q['RD_CLK_ENABLE'],2)==0 and int(q['WR_CLK_ENABLE'],2)==1
   assert set(q['INIT'])=={'x'},'candidate introduced initialized payload'
  assert not any(x['type'] in ('$sdff','$adff','$sdffe','$adffe') for x in cells.values())
  exe=O/'obj/VReservationPair'
  run('compile-boundary',['/usr/local/bin/verilator','--cc','--exe','--build','-j','2','-Wno-fatal','--top-module','ReservationPair','--Mdir',O/'obj','--output-split','10000','--output-split-cfuncs','200','-CFLAGS','-O0','-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',rtls['pair'],C/'boundary.cpp'],[exe])
  log=run('boundary',[exe],timeout=600);assert 'RESERVATION_BOUNDARY_PASS cycles=8192 entries=512 bits=80' in log.read_text()
  update(status='PASS_SOURCE_BOUND_ARBITRARY_STATE_BITWISE_STORAGE_RELATION_ACTUAL_TOPOLOGY_AND_8192_CYCLES_FULL_DCACHE_PENDING',rtls={k:dict(path=str(v),sha256=sha(v)) for k,v in rtls.items()},payload_reset='NONE_PRESERVED',all80_bits_retained=True,mutation_rejected=True,ended_utc=now(),child={})
 else:
  proof_path=D/'build-logs/Opt4-fit-reservation-proof-r3-20261111/result.json';proof=read(proof_path)
  assert proof['status'].startswith('PASS_') and proof['hardware_commit']==b['hardware_commit'] and proof['source_id']==b['source_id']
  maps={}
  for label,top in [('reference','ReservationReference'),('candidate','ReservationCandidate')]:
   rtl=Path(proof['rtls'][label]['path']);assert sha(rtl)==proof['rtls'][label]['sha256']
   sub=O/label;sub.mkdir();report=sub/'utilization.rpt';dcp=sub/'module.dcp';tcl=sub/'map.tcl'
   tcl.write_text(f'set_param general.maxThreads 2\nread_verilog {{{rtl}}}\nsynth_design -mode out_of_context -top {top} -part xcu280-fsvh2892-2L-e\nset bb [get_cells -hier -quiet -filter {{IS_BLACKBOX == 1}}]\nif {{[llength $bb]}} {{error "unresolved storage blackbox"}}\nreport_utilization -file {{{report}}}\nwrite_checkpoint -force {{{dcp}}}\nexit 0\n')
   run('map-'+label,['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',sub/'vivado.log','-source',tcl],[report,dcp])
   counts={}
   for line in report.read_text().splitlines():
    m=re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|Block RAM Tile|DSPs)\s*\|\s*([\d,.]+)\s*\|',line)
    if m:counts.setdefault(m[1].rstrip('*'),float(m[2].replace(',','')))
   assert len(counts)==5 and counts['CLB LUTs']>0
   maps[label]=dict(resources=counts,report=str(report),report_sha256=sha(report),rtl_sha256=sha(rtl),checkpoint=str(dcp));update(maps=maps)
  update(status='COMPLETE_PAIRED_RESERVATION_STORAGE_MAP_NOT_FULL_DCACHE_NOT_ADMITTED',maps=maps,local_luts_saved=maps['reference']['resources']['CLB LUTs']-maps['candidate']['resources']['CLB LUTs'],proof_receipt=str(proof_path),proof_receipt_sha256=sha(proof_path),ended_utc=now(),child={})
 save(O/'result.json',st)
if __name__=='__main__':
 try:main()
 except Exception as e:
  if S.exists():
   s=read(S)
   if s.get('pid')==os.getpid():s.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(S,s)
  raise
