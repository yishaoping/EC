#!/usr/bin/python3
"""Pure retirement decode candidate: proof, exact frozen comparison, full map.

Independent source/output/version. Does not modify the live whole synthesis.
"""
from pathlib import Path
import datetime,fcntl,hashlib,json,os,re,subprocess,time
C=Path(__file__).resolve().parent
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-fit-address-update-sequence-r1-20261111'
S=D/'Opt4-fit-address-update-sequence-r1-state.json'
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
 rel=REL+'PackageAddressStats.scala'
 text=(F/rel).read_text();back=text
 pairs=read(C/'reverse-substitutions.json')
 for new,old in reversed(pairs):
  assert back.count(new)==1;back=back.replace(new,old,1)
 assert back.encode()==subprocess.check_output(['git','show',b['parent_commit']+':'+rel],cwd=F)
 assert set(subprocess.check_output(['git','diff','--name-only',b['parent_commit'],b['hardware_commit']],cwd=F,text=True).splitlines())=={rel,REL+'AddressBucketSequenceMemory.scala','lineage.json'}
 assert (F/REL/'AddressBucketSequenceMemory.scala').read_bytes()==subprocess.check_output(['git','show',b['sequence_candidate']+':'+REL+'AddressBucketSequenceMemory.scala'],cwd=F)
 for n in ['AddressBucketGrouped.scala','AddressBucketUpdate.scala']:
  assert (F/REL/n).read_bytes()==subprocess.check_output(['git','show',b['parent_commit']+':'+REL+n],cwd=F)
 sequence=read(D/'build-logs/Opt4-fit-address-sequence-replicated-r1-20261111/result.json')
 assert sequence['hardware_commit']==b['sequence_candidate'] and sequence['status']=='VERIFIED_AND_MAPPED_MODULE_ONLY'
 assert sequence['local_formal']=='PASS_FULL32_VALID_PAYLOAD_INDUCTION_MATCHES_RESET_RETIRE_SINGLE_WRITER'
 assert sequence['full_module_regression']=='PASS_6144_CYCLES_ALL_52_OUTPUTS_NOT_FORMAL'
 assert sequence['memory_topology']['status']=='PASS_45_EXACT_REPLICAS_90_ASYNC_READS_BROADCAST_FULL32_SINGLE_EDGE_WRITE'
 assert sha(sequence['full_module_map']['report'])==sequence['full_module_map']['report_sha256']
 st=dict(schema='ec-opt4-update-sequence-composition-validation/1',**identity(os.getpid()),status='STARTING',started_utc=now(),hardware_commit=b['hardware_commit'],source_id=b['source_id'],parent_commit=b['parent_commit'],functional_baseline_commit=b['frozen_commit'],fpga_access=False,full_dut_synthesis=False,production_selected=False,stages={})
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
 cp=':'.join(cfg['classpath']);names=['PackageAddressStats.scala','AddressBucketGrouped.scala','AddressBucketUpdate.scala','AddressBucketSequenceMemory.scala']
 run('compile',[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,'-Xplugin:'+cfg['plugin'],'-d',classes,*[F/REL/n for n in names],C/'Emit.scala'],[classes/'opt4retirestatic/Emit.class'])
 cp=str(classes)+':'+cp
 def emit(mode,top):
  sub=O/mode;sub.mkdir(exist_ok=True);rtl=sub/(top+'.v')
  run('emit-'+mode,[cfg['java'],'-Xmx24G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',cp,'opt4retirestatic.Emit',mode,sub],[rtl]);return rtl
 update(local_formal='SOURCE_BOUND_COMPOSITION_OF_VERIFIED_RESET_CORRECT_UPDATE_AND_FULL32_SEQUENCE_STORAGE_INDUCTION',inherited_sequence_proof=sequence['local_formal'],inherited_sequence_topology=sequence['memory_topology']['status'],exact_parent_reversal=True,full_dut_formal=False)
 save(O/'compositional-local-evidence.json',dict(hardware_commit=b['hardware_commit'],source_id=b['source_id'],sequence_receipt_sha256=sha(D/'build-logs/Opt4-fit-address-sequence-replicated-r1-20261111/result.json'),scope='Sequence field reads/write/reset gating changed identically to proven27f7e7d6; full32 helper byte-identical. All counter/update/helper bytes reverse exactly to composed e0. Counter arithmetic sharing independent from valid/tag storage state. Full frozen regression and map still required.'))
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
