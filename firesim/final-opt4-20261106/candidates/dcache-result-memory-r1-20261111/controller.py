#!/usr/bin/python3
"""Detached immutable local proof, actual-size checks, frozen comparison and maps.

No whole-DUT build, live-input mutation or device access. A failed stage is
never retried here. A separate controller must audit and bind its checkpoints.
"""
from pathlib import Path
import datetime as dt, fcntl, hashlib, importlib.util, json, os, re, shutil, subprocess, time

C=Path(__file__).resolve().parent
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-fit-dcache-result-memory-r1-20261111'
S=D/'Opt4-fit-dcache-result-memory-r1-state.json'
REL='chipyard/generators/boom/src/main/scala/lsu/'

def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for block in iter(lambda:f.read(2**20),b''):h.update(block)
 return h.hexdigest()
def read(p):return json.loads(Path(p).read_text()) if Path(p).is_file() else {}
def now():return dt.datetime.now(dt.timezone.utc).isoformat()
def save(p,x):
 p=Path(p);p.parent.mkdir(parents=True,exist_ok=True);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with q.open('w') as f:json.dump(x,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(q,p)
def exact_text(p,s):
 if p.exists():assert p.read_text()==s,str(p)
 else:p.write_text(s)
def identity(pid):
 try:
  v=Path(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split()
  return dict(pid=pid,start_ticks=v[19],process_state=v[0],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
 except FileNotFoundError:return {}
def live(x):
 y=identity(x.get('pid',0));return bool(y and all(str(x.get(k))==str(y[k]) for k in ['start_ticks','host_boot_id']) and y['process_state'] not in ['Z','X'])
def gate():
 mem=int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:')))
 return mem>=48*2**20 and shutil.disk_usage(W).free>=40*2**30
def resources(p):
 r={}
 for line in p.read_text().splitlines():
  m=re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|Block RAM Tile|DSPs)\s*\|\s*([\d,.]+)\s*\|',line)
  if m:r.setdefault(m[1].rstrip('*'),float(m[2].replace(',','')))
 assert len(r)==5 and r['CLB LUTs']>0
 return r

def main():
 O.mkdir(exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 old=read(S);assert not live(old) and not live(old.get('child',{})), 'adopt live controller and child'
 cfg=read(C/'config.json');b=cfg['binding'];F=Path(cfg['worktree']);inputs=read(C/'input-hashes.json')
 assert all(sha(p)==h for p,h in inputs.items()),'immutable input mismatch'
 assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==b['hardware_commit']
 for name in ['dcache.scala','AppliedEffectResultMemory.scala']:
  assert (F/REL/name).read_bytes()==subprocess.check_output(['git','show',b['hardware_commit']+':'+REL+name],cwd=F)
 assert subprocess.check_output(['git','diff','--name-only',b['parent_commit'],b['hardware_commit']],cwd=F,text=True).splitlines()==[REL+'AppliedEffectResultMemory.scala',REL+'dcache.scala','lineage.json']
 parent=(C/'parent-dcache.scala.txt').read_text();source=(F/REL/'dcache.scala').read_text()
 assert parent.count('appliedEffectResult(')==3 and source.count('appliedEffectResult(')==0
 spec=importlib.util.spec_from_file_location('source_contract',C/'source_contract.py');contract=importlib.util.module_from_spec(spec);spec.loader.exec_module(contract)
 save(O/'source-contract.json',contract.verify())
 # All full-array observation declarations and taps remain byte-identical.
 for line in parent.splitlines():
  if 'debug_' in line or 'dontTouch(' in line:assert line in source,line
 st=dict(schema='ec-opt4-dcache-result-memory-validation/1',**identity(os.getpid()),hardware_commit=b['hardware_commit'],source_id=b['source_id'],status='STARTING',started_utc=now(),input_sha256=inputs,stages=old.get('stages',{}),full_dut_formal=False,full_dut_synthesis=False,production_selected=False,fpga_access=False,complete_dcache_comparison='NOT_RUN_NOT_ADMITTED',proof_limits='Generated helper SAT establishes arbitrary-word update/index equivalence under common uninitialized payload relation. Actual 512x64 memory topology and 8192-cycle matched-register regression check both read ports and reset writes. No complete frozen-DCache output regression, whole-DUT equivalence or FIT claim.')
 save(S,st)
 def update(**kw):st.update(kw);st['updated_utc']=now();save(S,st)
 tmp=O/'tmp';tmp.mkdir(exist_ok=True);cache=O/'ccache';cache.mkdir(exist_ok=True)
 env={**os.environ,'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':'','OMP_NUM_THREADS':'8','MAKEFLAGS':'-j8','CCACHE_DISABLE':'1','CCACHE_DIR':str(cache),'CCACHE_TEMPDIR':str(tmp),'TMPDIR':str(tmp)}
 def run(label,args,directory,outputs=(),negative=False):
  directory.mkdir(parents=True,exist_ok=True);rp=directory/(label+'-result.json');r=read(rp)
  if r:
   assert r['hardware_commit']==b['hardware_commit'] and r['source_id']==b['source_id']
   assert r['accepted_result'] and not r['missing_outputs'],'failed checkpoint needs isolated recovery'
   assert all(sha(p)==h for p,h in r['outputs'].items());st['stages'][label]=r;save(S,st);return Path(r['log'])
  while not gate():update(status='WAITING_RESOURCE_GATE',next_stage=label);time.sleep(300)
  log=directory/(label+'-attempt-1.log');assert not log.exists(),'incomplete stage needs separate recovery audit'
  argv=list(map(str,['nice','-n','10',*args]))
  with log.open('xb',buffering=0) as f:
   p=subprocess.Popen(argv,cwd=directory,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT)
   child=identity(p.pid);r=dict(hardware_commit=b['hardware_commit'],source_id=b['source_id'],argv=argv,log=str(log),started_utc=now(),**child)
   st['stages'][label]=r;update(status='RUNNING_'+label.upper(),child=child,active_stage=label)
   while p.poll() is None:
    try:p.wait(timeout=30)
    except subprocess.TimeoutExpired:pass
    update();os.fsync(f.fileno())
  accepted=p.returncode!=0 if negative else p.returncode==0
  r.update(returncode=p.returncode,accepted_result=accepted,negative=negative,ended_utc=now(),outputs={str(p):sha(p) for p in outputs if p.is_file()},missing_outputs=[str(p) for p in outputs if not p.is_file()])
  save(rp,r);st['stages'][label]=r;update(child={});assert accepted and not r['missing_outputs'],(label,p.returncode,str(log))
  return log
 classes=O/'classes';classes.mkdir(exist_ok=True);cp=str(classes)+':'+':'.join(cfg['classpath'])
 compiler=[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',':'.join(cfg['classpath']),'-Xplugin:'+cfg['plugin'],'-d',classes]
 run('compile',compiler+[F/REL/'AppliedEffectResultMemory.scala',C/'Emit.scala'],O,[classes/'opt4dcacheresult/Emit.class'])
 def emit(mode,top):
  sub=O/mode;sub.mkdir(exist_ok=True);rtl=sub/(top+'.v')
  log=run('emit-'+mode,[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',cp,'opt4dcacheresult.Emit',mode,sub],sub,[rtl])
  assert 'ACTUAL_RESULT_MEMORY sets=64 ways=8 bits=64' in log.read_text()
  return rtl
 proof=emit('proof','ResultWordProof')
 for prop in ['indexEquivalent','nextEquivalent']:
  log=run('sat-'+prop,['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {proof}; prep -top ResultWordProof -flatten; sat -verify -prove io_{prop} 1 -timeout 120'],O/'proof')
  assert 'SUCCESS' in log.read_text() and 'timed out' not in log.read_text()
 log=run('sat-negative-mutation',['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {proof}; prep -top ResultWordProof -flatten; sat -verify -prove io_mutantEquivalent 1 -timeout 60'],O/'proof',negative=True)
 assert 'proof did fail' in log.read_text() and 'timed out' not in log.read_text()
 update(local_formal='PASS_ARBITRARY64_WORD_INDEX_UPDATE_NO_RESET_MASKING',negative_mutation_rejected=True)
 memory=emit('candidate','AppliedEffectResultMemory');reference=emit('reference','ReferenceResultMemory');pair=emit('pair','ResultMemoryPair')
 topo=O/'candidate/topology.json'
 run('topology',['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {memory}; hierarchy -top AppliedEffectResultMemory; proc; memory_collect; write_json {topo}'],O/'candidate',[topo])
 cells=read(topo)['modules']['AppliedEffectResultMemory']['cells'];memories=[]
 for name,cell in cells.items():
  if cell['type']=='$mem_v2':
   p=cell['parameters'];v={k:int(p[k],2) for k in ['WIDTH','SIZE','ABITS','RD_PORTS','WR_PORTS','RD_CLK_ENABLE','WR_CLK_ENABLE']}
   assert v==dict(WIDTH=64,SIZE=512,ABITS=9,RD_PORTS=2,WR_PORTS=1,RD_CLK_ENABLE=0,WR_CLK_ENABLE=1),(name,v)
   memories.append(dict(name=name,**v))
 assert len(memories)==1
 topology=dict(status='PASS_512X64_ASYNC2R_SYNC1W',memories=memories,rtl_sha256=sha(memory),json_sha256=sha(topo))
 save(O/'candidate/topology-receipt.json',topology);update(memory_topology=topology)
 sub=O/'boundary';exe=sub/'obj/VResultMemoryPair'
 run('compile-boundary',['/usr/local/bin/verilator','--cc','--exe','--build','--top-module','ResultMemoryPair','--Mdir',sub/'obj','-j',8,'--output-split',10000,'--output-split-cfuncs',200,'-Wno-fatal','-CFLAGS','-O0','-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',pair,C/'boundary.cpp'],sub,[exe])
 log=run('boundary',[exe],sub);assert 'RESULT_MEMORY_ACTUAL_SIZE_PASS' in log.read_text()
 update(actual_size_boundary='PASS_8192_CYCLES_512X64_TWO_ASYNC_READS_FULL_DATA_BOUNDARIES_PRE_POST_EDGE_DISABLED_WRITE_RESET_WRITE',storage_module_comparison='PASS_ALL_STORAGE_OUTPUTS_8192_CYCLES_NOT_COMPLETE_DCACHE')
 # Compile changed DCache only after local storage proof/regression. This is
 # a source/API check, not a DCache elaboration or full-DUT verification.
 checkclasses=O/'dcache-typecheck';checkclasses.mkdir(exist_ok=True)
 typecompiler=[cfg['java'],'-Xmx16G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,'-Xplugin:'+cfg['plugin'],'-d',checkclasses]
 run('typecheck-dcache',typecompiler+[F/REL/'dcache.scala'],O,[checkclasses/'boom/lsu/BoomNonBlockingDCacheModule.class'])
 def mapping(label,rtl,top):
  sub=O/label;sub.mkdir(exist_ok=True);report=sub/'utilization.rpt';dcp=sub/'module.dcp';tcl=sub/'map.tcl'
  exact_text(tcl,'set_param general.maxThreads 4\n'+f'read_verilog {{{rtl}}}\nsynth_design -top {top} -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized\nreport_utilization -file {{{report}}}\nwrite_checkpoint -force {{{dcp}}}\nexit 0\n')
  run(label,['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',sub/'vivado.log','-source',tcl],sub,[report,dcp])
  return dict(resources=resources(report),report=str(report),report_sha256=sha(report),checkpoint=str(dcp),rtl_sha256=sha(rtl),tcl_sha256=sha(tcl),scope='Complete payload-storage module OOC; no DCache/whole-DUT capacity estimate')
 update(reference_storage_map=mapping('map-reference',reference,'ReferenceResultMemory'))
 update(candidate_storage_map=mapping('map-candidate',memory,'AppliedEffectResultMemory'))
 gain=st['reference_storage_map']['resources']['CLB LUTs']-st['candidate_storage_map']['resources']['CLB LUTs']
 update(status='LOCAL_STORAGE_VERIFIED_AND_MAPPED_COMPLETE_DCACHE_PENDING_NOT_ADMITTED',child={},ended_utc=now(),measured_storage_lut_saving=gain,whole_dut_admission=False)
 save(O/'result.json',st)

if __name__=='__main__':
 try:main()
 except Exception as exc:
  st=read(S)
  if st.get('pid')==os.getpid():st.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=now());save(S,st)
  raise

