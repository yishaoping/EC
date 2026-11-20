#!/usr/bin/python3
"""Source-bound structural screen, not admission to whole hardware.

Exact synchronous reset and arbitrary state relation are proved. No active CAD
input changes. Eight read ports are a representative cost screen, not the
actual complete DCache boundary. Integrated gain must be measured separately.
"""
from pathlib import Path
import datetime,fcntl,hashlib,json,os,re,signal,subprocess,time
C=Path(__file__).resolve().parent
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-fit-dcache-owner-memory-screen-r2-20261111'
S=D/'Opt4-fit-dcache-owner-memory-screen-r2-state.json'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def save(p,j):
 p=Path(p);p.parent.mkdir(parents=True,exist_ok=True);t=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with t.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(t,p)
def identity(pid):
 try:
  s=(Path('/proc')/str(pid)/'stat').read_text().rsplit(')',1)[1].split()
  return dict(pid=pid,start_ticks=s[19],process_state=s[0],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
 except FileNotFoundError:return {}
def main():
 O.mkdir(exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 cfg=json.loads((C/'config.json').read_text());F=Path(cfg['worktree'])
 assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==cfg['binding']['hardware_commit']
 p=F/'chipyard/generators/boom/src/main/scala/lsu/dcache.scala';s=p.read_text()
 assert 'val dataWriteArb = Module(new Arbiter(new L1DataWriteReq, 2))' in s
 assert 'when (dataWriteArb.io.in(1).fire && refillLastBeat && refillOwnerMatch)' in s
 assert 'when (dataWriteArb.io.in(0).fire)' in s
 fields=['imageKey','lineGeneration','dirtyPacketSeq','dirtyPacketTracked']
 # All payload writes are covered by the two mutually exclusive physical-write
 # arbiter inputs. No claim of full DCache proof is made by this screen.
 matches={n:[i+1 for i,l in enumerate(s.splitlines()) if n+'(' in l and ':=' in l] for n in fields}
 save(O/'source-contract.json',dict(hardware_commit=cfg['binding']['hardware_commit'],source_sha256=sha(p),geometry={'sets':256,'ways':2,'bits':146,'screen_read_ports':8},write_lines=matches,
   relation='effective reference word = written ? raw memory payload : zero; sync reset clears written; write at edge is suppressed by reset. Read is asynchronous before/after edge.',
   limitation='Not complete DCache integration or full-DUT equivalence. Actual read fanout and mapped module must be measured after source-bound integration.'))
 st=dict(schema='ec-opt4-owner-memory-screen/1',**identity(os.getpid()),hardware_commit=cfg['binding']['hardware_commit'],functional_baseline_commit=cfg['binding']['functional_baseline_commit'],status='STARTING',started_utc=now(),stages={},fpga_access=False,full_dut_synthesis=False,production_selected=False)
 def update(**v):st.update(v);st['updated_utc']=now();save(S,st)
 tmp=O/'tmp';tmp.mkdir(exist_ok=True);env={**os.environ,'TMPDIR':str(tmp),'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':'','CCACHE_DISABLE':'1','OMP_NUM_THREADS':'2'}
 def run(name,argv,negative=False,timeout=7200):
  log=O/(name+'.log');assert not log.exists(),'immutable attempt; recover in new version'
  with log.open('xb',buffering=0) as f:
   p=subprocess.Popen(list(map(str,['nice','-n','10',*argv])),cwd=O,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
   update(status='RUNNING_'+name.upper(),active_stage=name,child=identity(p.pid));start=time.monotonic()
   while p.poll() is None:
    try:p.wait(timeout=30)
    except subprocess.TimeoutExpired:pass
    update(child=identity(p.pid));os.fsync(f.fileno())
    if time.monotonic()-start>timeout:
     os.killpg(p.pid,signal.SIGTERM);p.wait(timeout=60);raise TimeoutError('owned local screen '+name)
  good=p.returncode!=0 if negative else p.returncode==0
  st['stages'][name]=dict(returncode=p.returncode,accepted=good,log=str(log),sha256=sha(log));update(child={})
  assert good,(name,p.returncode,str(log));return log
 update();classes=O/'classes';classes.mkdir(exist_ok=True);cp=':'.join(cfg['classpath'])
 run('compile',[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=2','-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,'-Xplugin:'+cfg['plugin'],'-d',classes,C/'Storage.scala'])
 rtl={}
 for mode,top in [('proof','StorageInduction'),('pair','StoragePair'),('reference','RegisterReference'),('candidate','AsyncCandidate')]:
  sub=O/mode;sub.mkdir(exist_ok=True)
  run('emit-'+mode,[cfg['java'],'-Xmx24G','-Xss8M','-XX:ActiveProcessorCount=2','-cp',str(classes)+':'+cp,'opt4ownerstorage.Emit',mode,sub])
  rtl[mode]=sub/(top+'.v');assert rtl[mode].is_file()
 log=run('sat-transition',['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {rtl["proof"]}; prep -top StorageInduction -flatten; sat -verify -prove io_equivalent 1 -timeout 180'],timeout=300)
 assert 'SUCCESS' in log.read_text() and 'timed out' not in log.read_text()
 log=run('sat-negative',['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {rtl["proof"]}; prep -top StorageInduction -flatten; sat -verify -prove io_mutationEquivalent 1 -timeout 60'],negative=True,timeout=180)
 assert 'proof did fail' in log.read_text() and 'timed out' not in log.read_text()
 update(inductive_transition='PASS_512_ENTRIES_ARBITRARY_PAYLOAD_WRITTEN_MASK_AND_SYNC_RESET_READ_RELATION_BITWISE_LIFT_TO146',negative_mutation_rejected=True)
 obj=O/'obj'
 run('compile-boundary',['/usr/bin/verilator','--cc','--exe','--build','-j','2','-Wno-fatal','--top-module','StoragePair','--Mdir',obj,rtl['pair'],C/'boundary.cpp'],timeout=1800)
 log=run('boundary',[obj/'VStoragePair'],timeout=300)
 assert 'PASS_8192' in log.read_text();update(boundary='PASS_8192_CYCLES_512_ENTRIES_146_BITS_8_READERS_PRE_POST_EDGE_RESET_COLLISIONS')
 maps={}
 for label,top in [('reference','RegisterReference'),('candidate','AsyncCandidate')]:
  sub=O/label;report=sub/'utilization.rpt';dcp=sub/'module.dcp';tcl=sub/'map.tcl'
  tcl.write_text(f'set_param general.maxThreads 2\nread_verilog {{{rtl[label]}}}\nsynth_design -mode out_of_context -top {top} -part xcu280-fsvh2892-2L-e\nreport_utilization -file {{{report}}}\nwrite_checkpoint -force {{{dcp}}}\nexit 0\n')
  run('map-'+label,['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',sub/'vivado.log','-source',tcl],timeout=7200)
  counts={}
  for l in report.read_text().splitlines():
   m=re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|Block RAM Tile|DSPs)\s*\|\s*([\d,.]+)\s*\|',l)
   if m:counts.setdefault(m[1].rstrip('*'),float(m[2].replace(',','')))
  assert len(counts)==5 and counts['CLB LUTs']>0 and counts['CLB Registers']>0
  maps[label]=dict(resources=counts,report=str(report),report_sha256=sha(report),dcp=str(dcp));update(maps=maps)
 saving=maps['reference']['resources']['CLB LUTs']-maps['candidate']['resources']['CLB LUTs']
 update(status='COMPLETE_SOURCE_BOUND_INDUCTIVE_STORAGE_SCREEN_NOT_FULL_DCACHE_OR_WHOLE_ADMITTED',maps=maps,lut_saved=saving,
   next_action='If significant positive gain: integrate in separate commit, prove exact source-derived write guards, full reader set, combined state mapping and run matched module map before whole admission.',ended_utc=now(),child={})
 save(O/'result.json',st)
if __name__=='__main__':
 try:main()
 except Exception as e:
  if S.exists():
   j=json.loads(S.read_text())
   if j.get('pid')==os.getpid():j.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(S,j)
  raise
