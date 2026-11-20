#!/usr/bin/python3
"""Pure retirement decode candidate: proof, exact frozen comparison, full map.

Independent source/output/version. Does not modify the live whole synthesis.
"""
from pathlib import Path
import datetime,fcntl,hashlib,json,os,re,subprocess,time
C=Path(__file__).resolve().parent
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-fit-address-static-retire-r2-20261111'
S=D/'Opt4-fit-address-static-retire-r2-state.json'
REL='chipyard/generators/boom/src/main/scala/lsu/'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def read(p):return json.loads(Path(p).read_text())
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
 cfg=read(C/'config.json');b=cfg['binding'];F=Path(cfg['worktree'])
 assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==b['hardware_commit']
 parent=lambda n:subprocess.check_output(['git','show',b['parent_commit']+':'+REL+n],cwd=F)
 for n in ['AddressBucketGrouped.scala','AddressBucketUpdate.scala']:
  assert (F/REL/n).read_bytes()==parent(n)
 delta=subprocess.check_output(['git','diff','--name-only',b['parent_commit'],b['hardware_commit']],cwd=F,text=True).splitlines()
 assert set(delta)=={REL+'PackageAddressStats.scala','lineage.json'}
 a=parent('PackageAddressStats.scala').decode();s=(F/REL/'PackageAddressStats.scala').read_text()
 a0=a.index('  when (safeAdvance && !safeError) {');a1=a.index('\n  val packageTableFull',a0)
 s0=s.index('  when (safeAdvance && !safeError) {');s1=s.index('\n  val packageTableFull',s0)
 assert a[:a0]==s[:s0] and a[a1:]==s[s1:],'Only retirement block may change'
 for name in ['bucketStore','bucketFirstStore','bucketLoadFirst','bucketStoreFirst','bucketStrictWriteRead']:
  assert f'{name}(retiringIdx)(g) := 0.U' in a[a0:a1]
  assert f'{name}(retiringIdx)(g) := 0.U' not in s
  assert f'{name}(i)(g) := 0.U' in s[s0:s1]
  # All read/subtraction expressions are retained verbatim.
  assert a[a0:a1].count(f'{name}(retiringIdx)(g)')-1==s[s0:s1].count(f'{name}(retiringIdx)(g)')
 st=dict(schema='ec-opt4-static-retire-validation/1',**identity(os.getpid()),status='STARTING',started_utc=now(),hardware_commit=b['hardware_commit'],source_id=b['source_id'],parent_commit=b['parent_commit'],functional_baseline_commit=b['frozen_commit'],fpga_access=False,full_dut_synthesis=False,production_selected=False,stages={})
 def update(**v):st.update(v);st['updated_utc']=now();save(S,st)
 tmp=O/'tmp';tmp.mkdir(exist_ok=True)
 env={**os.environ,'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':'','TMPDIR':str(tmp),'CCACHE_DISABLE':'1','OMP_NUM_THREADS':'4','MAKEFLAGS':'-j4'}
 def run(name,argv,outputs=(),negative=False):
  log=O/(name+'.log');assert not log.exists(),('preserve old attempt; use reviewed recovery',str(log))
  with log.open('xb',buffering=0) as f:
   p=subprocess.Popen(list(map(str,['nice','-n','10',*argv])),cwd=O,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT)
   update(status='RUNNING_'+name.upper(),active_stage=name,child=identity(p.pid))
   while p.poll() is None:
    try:p.wait(timeout=30)
    except subprocess.TimeoutExpired:pass
    update(child=identity(p.pid));os.fsync(f.fileno())
  good=p.returncode!=0 if negative else p.returncode==0
  st['stages'][name]=dict(returncode=p.returncode,accepted=good,log=str(log),log_sha256=sha(log),outputs={str(p):sha(p) for p in outputs if Path(p).is_file()})
  update(child={});assert good and all(Path(p).is_file() for p in outputs),(name,p.returncode,str(log))
  return log
 update();classes=O/'classes';classes.mkdir(exist_ok=True)
 cp=':'.join(cfg['classpath']);names=['PackageAddressStats.scala','AddressBucketGrouped.scala','AddressBucketUpdate.scala']
 run('compile',[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,'-Xplugin:'+cfg['plugin'],'-d',classes,*[F/REL/n for n in names],C/'Emit.scala'],[classes/'opt4retirestatic/Emit.class'])
 cp=str(classes)+':'+cp
 def emit(mode,top):
  sub=O/mode;sub.mkdir(exist_ok=True);rtl=sub/(top+'.v')
  run('emit-'+mode,[cfg['java'],'-Xmx24G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',cp,'opt4retirestatic.Emit',mode,sub],[rtl]);return rtl
 original_emitter=W/'candidates/address-static-retire-r1-20261111/Emit.scala'
 full=original_emitter.read_text();bitwise=(C/'Emit.scala').read_text()
 pattern='val words=Input(Vec(256,Vec(4,UInt(64.W))))'
 assert full.count(pattern)==1 and bitwise==full.replace(pattern,'val words=Input(Vec(256,Vec(4,UInt(1.W))))')
 save(O/'bitwise-lifting.json',dict(status='EXACT_BITWISE_TEMPLATE_WIDTH_ONLY_REDUCTION',full_payload_bits=64,proof_payload_bits=1,slots=256,granules=4,full_template=str(original_emitter),full_sha256=sha(original_emitter),bitwise_template_sha256=sha(C/'Emit.scala'),reason='Reference and candidate only hold or clear each word to0; selector, valid and reset depend on no payload bits. The proved one-bit equality lifts independently to every one of64 bits by identical bit-separable mux/clear template. Complete DUT counters stay64 bits. This is a combinational transition cut, not full-DUT formal.'))
 proof=emit('proof','RetireClearProof')
 log=run('sat-clear',['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {proof}; prep -top RetireClearProof -flatten; sat -verify -prove io_equivalent 1 -timeout 180'])
 assert 'SUCCESS' in log.read_text() and 'timed out' not in log.read_text()
 log=run('sat-negative',['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {proof}; prep -top RetireClearProof -flatten; sat -verify -prove io_mutationEquivalent 1 -timeout 60'],negative=True)
 assert 'proof did fail' in log.read_text() and 'timed out' not in log.read_text()
 update(local_formal='PASS_ALL_256X4_BITWISE_CLEAR_LIFTED_TO64_ARBITRARY_PAYLOAD_VALID_INDEX_RESETSTATS_AND_PRIORITY',negative_mutation_rejected=True)
 rtl=emit('address','PackageAddressStats')
 baseline=W/'candidates/address-update-share-r2-20261111';cmp=O/'compare';cmp.mkdir(exist_ok=True)
 for src,dst in [('frozen-original.v','original.v'),('frozen-tb.v','tb.v')]:
  assert not (cmp/dst).exists();(cmp/dst).write_bytes((baseline/src).read_bytes())
 exe=cmp/'obj/Vtb'
 run('compare-compile',['/usr/local/bin/verilator','--binary','--timing','--top-module','tb','--Mdir',cmp/'obj','-j',4,'--output-split',10000,'--output-split-cfuncs',200,'--x-initial',0,'--x-assign',0,'-Wno-fatal','-DRANDOMIZE_REG_INIT','-DRANDOMIZE_MEM_INIT',"-DRANDOM=32'h0",'-CFLAGS','-O0','-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',cmp/'original.v',rtl,cmp/'tb.v'],[exe])
 log=run('compare',[exe]);assert 'ADDRESS_SEQUENTIAL_COMPARISON_PASS vectors=6144' in log.read_text()
 update(full_module_regression='PASS_6144_CYCLES_ALL_52_OUTPUTS_NOT_FULL_DUT_FORMAL',independent_global_reset='Inherited unchanged globalReset512/513/restart516 frozen testbench; source hash recorded in compile stage')
 # All geometry and widths remain complete. A zero-area report is invalid.
 sub=O/'map-full-module';sub.mkdir(exist_ok=True);tcl=sub/'map.tcl';report=sub/'utilization.rpt';dcp=sub/'module.dcp'
 tcl.write_text(f'set_param general.maxThreads 4\nread_verilog {{{rtl}}}\nsynth_design -mode out_of_context -top PackageAddressStats -part xcu280-fsvh2892-2L-e\nreport_utilization -file {{{report}}}\nreport_utilization -hierarchical -file {{{sub/"hierarchical.rpt"}}}\nwrite_checkpoint -force {{{dcp}}}\nexit 0\n')
 run('map-full-module',['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',sub/'vivado.log','-source',tcl],[report,dcp])
 resources={}
 for line in report.read_text().splitlines():
  m=re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|Block RAM Tile|DSPs)\s*\|\s*([\d,.]+)\s*\|',line)
  if m:resources.setdefault(m[1].rstrip('*'),float(m[2].replace(',','')))
 assert len(resources)==5 and resources['CLB LUTs']>0 and resources['CLB Registers']>0 and resources['Block RAM Tile']>0,'Incomplete/empty complete-module report rejected'
 update(status='VERIFIED_AND_MAPPED_COMPLETE_ADDRESS_MODULE_NOT_WHOLE_DUT',full_module_map=dict(resources=resources,report=str(report),report_sha256=sha(report),checkpoint=str(dcp),rtl_sha256=sha(rtl)),measured_lut_delta_vs00847dc2=872880-resources['CLB LUTs'],ended_utc=now(),child={})
 save(O/'result.json',st);print(st['status'])
if __name__=='__main__':
 try:main()
 except Exception as exc:
  if S.exists():
   j=read(S)
   if j.get('pid')==os.getpid():j.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=now());save(S,j)
  raise
