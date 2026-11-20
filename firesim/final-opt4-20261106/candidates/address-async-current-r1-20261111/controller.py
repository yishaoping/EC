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
O=D/'build-logs/Opt4-fit-address-async-current-r1-20261111'
S=D/'Opt4-fit-address-async-current-r1-state.json'
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
 old=read(S);assert not live(old) and not live(old.get('child',{})),'adopt live identities'
 cfg=read(C/'config.json');b=cfg['binding'];F=Path(cfg['worktree']);inputs=read(C/'input-hashes.json')
 assert all(sha(p)==h for p,h in inputs.items()),'input mismatch'
 assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==b['hardware_commit']
 names=['PackageAddressStats.scala','AddressBucketGrouped.scala','AddressCurrentBucketMemory.scala']
 for n in names:assert (F/REL/n).read_bytes()==subprocess.check_output(['git','show',b['hardware_commit']+':'+REL+n],cwd=F)
 assert subprocess.check_output(['git','diff','--name-only',b['parent_commit'],b['hardware_commit']],cwd=F,text=True).splitlines()==[REL+'AddressCurrentBucketMemory.scala',REL+'PackageAddressStats.scala','lineage.json']
 inherited=read(cfg['parent_local_receipt']);assert inherited['hardware_commit']==b['parent_commit'] and inherited['full_dut_formal'] is False
 assert inherited['full_module_regression']['status']=='PASS_6144_CYCLES_ALL_52_OUTPUTS_NOT_FORMAL'
 source=(F/REL/'PackageAddressStats.scala').read_text()
 for n in ['bucketLoadFirst','bucketStoreFirst','bucketStrictWriteRead']:
  assert f'val {n} = Reg(Vec(packetWindow, Vec(4, UInt(64.W))))' in source
 assert 'currentBucketMemory.io.writeEnable := processCommit && !io.resetStats' in source
 assert 'val safeAdvance = drainingWindow && !processValid' in source
 st=dict(schema='ec-opt4-address-async-current-validation/1',**identity(os.getpid()),hardware_commit=b['hardware_commit'],source_id=b['source_id'],status='STARTING',started_utc=now(),input_sha256=inputs,stages=old.get('stages',{}),inherited_bucket_tag_verification=inherited['local_formal'],inherited_histogram_verification=inherited['inherited_group4'],full_dut_formal=False,full_dut_synthesis=False,production_selected=False,fpga_access=False,proof_limits='One-word inductive valid-payload relation over arbitrary full-width values, delta and reset/retire/event conditions; actual 256x512 memory topology/8192 vectors; frozen complete-module cycle comparison. No full-DUT formal or FIT claim.')
 save(S,st)
 def update(**kw):st.update(kw);st['updated_utc']=now();save(S,st)
 tmp=O/'tmp';tmp.mkdir(exist_ok=True);cache=O/'ccache';cache.mkdir(exist_ok=True)
 env={**os.environ,'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':'','OMP_NUM_THREADS':'8','MAKEFLAGS':'-j8','CCACHE_DISABLE':'1','CCACHE_DIR':str(cache),'CCACHE_TEMPDIR':str(tmp),'TMPDIR':str(tmp)}
 def run(label,args,directory,outputs=(),negative=False):
  directory.mkdir(parents=True,exist_ok=True);rp=directory/(label+'-result.json');r=read(rp)
  if r:
   assert r['hardware_commit']==b['hardware_commit'] and r['source_id']==b['source_id']
   assert r['accepted_result'] and not r['missing_outputs'],'failed checkpoint requires isolated recovery'
   assert all(sha(p)==h for p,h in r['outputs'].items());st['stages'][label]=r;save(S,st);return Path(r['log'])
  while not gate():update(status='WAITING_RESOURCE_GATE',next_stage=label);time.sleep(300)
  log=directory/(label+'-attempt-1.log');assert not log.exists(),'incomplete stage requires audit'
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
 run('compile',[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',':'.join(cfg['classpath']),'-Xplugin:'+cfg['plugin'],'-d',classes,*[F/REL/n for n in names],C/'EmitAsync.scala'],O,[classes/'opt4async/EmitAsync.class'])
 def elaborate(mode,top):
  sub=O/mode;sub.mkdir(exist_ok=True);rtl=sub/(top+'.v')
  run('elaborate-'+mode,[cfg['java'],'-Xmx24G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',cp,'opt4async.EmitAsync',mode,sub],sub,[rtl]);return rtl
 proof=elaborate('proof','AsyncProof')
 for prop in ['equivalent','overflowEquivalent','nextEquivalent']:
  log=run('sat-'+prop,['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {proof}; prep -top AsyncProof -flatten; sat -verify -prove io_{prop} 1 -timeout 180'],O/'proof')
  assert 'SUCCESS' in log.read_text() and 'timed out' not in log.read_text()
 log=run('sat-negative-invalid-mutation',['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {proof}; prep -top AsyncProof -flatten; sat -verify -prove io_mutationEquivalent 1 -timeout 60'],O/'proof',negative=True)
 assert 'proof did fail' in log.read_text() and 'timed out' not in log.read_text()
 update(local_formal='PASS_64BIT_VALID_PAYLOAD_INDUCTION_RESET_RETIRE_ALLOCATION_OVERFLOW',negative_mutation_rejected=True)
 memory=elaborate('memory','AddressCurrentBucketMemory');topo=O/'memory/topology.json'
 run('memory-topology',['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {memory}; hierarchy -top AddressCurrentBucketMemory; proc; memory_collect; write_json {topo}'],O/'memory',[topo])
 cells=read(topo)['modules']['AddressCurrentBucketMemory']['cells'];memories=[]
 def integer(p,k):return int(p[k],2)
 for name,cell in cells.items():
  if cell['type']=='$mem_v2':
   p=cell['parameters'];r={k:integer(p,k) for k in ['WIDTH','SIZE','ABITS','RD_PORTS','WR_PORTS','RD_CLK_ENABLE','WR_CLK_ENABLE']}
   assert r==dict(WIDTH=64,SIZE=256,ABITS=8,RD_PORTS=2,WR_PORTS=1,RD_CLK_ENABLE=0,WR_CLK_ENABLE=1),(name,r)
   memories.append(dict(name=name,**r))
 assert len(memories)==8
 topology=dict(status='PASS_ACTUAL_256X512_TWO_ASYNC_READS_ONE_SYNC_WRITE',memories=memories,total_bits=131072,rtl_sha256=sha(memory),yosys_json_sha256=sha(topo))
 save(O/'memory/topology-receipt.json',topology);update(memory_topology=topology)
 rtl=elaborate('boundary','AsyncMemoryProbe');sub=O/'boundary';exe=sub/'obj/VAsyncMemoryProbe'
 run('boundary-compile',['/usr/local/bin/verilator','--cc','--exe','--build','--top-module','AsyncMemoryProbe','--Mdir',sub/'obj','-j',8,'-Wno-fatal','-CFLAGS','-O0','-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',rtl,C/'boundary.cpp'],sub,[exe])
 log=run('boundary-run',[exe],sub);assert 'ASYNC_ACTUAL_SIZE_PASS' in log.read_text()
 update(actual_size_boundary='PASS_8192_VECTORS_256X512_ASYNC_READS_SAME_ADDRESS_64BIT_OVERFLOW_STALE_INVALID_RESET')
 def mapping(label,rtl,top):
  sub=O/label;sub.mkdir(exist_ok=True);report=sub/'utilization.rpt';dcp=sub/'module.dcp';tcl=sub/'map.tcl'
  exact_text(tcl,'set_param general.maxThreads 4\n'+f'read_verilog {{{rtl}}}\nsynth_design -top {top} -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized\nreport_utilization -file {{{report}}}\nreport_utilization -hierarchical -file {{{sub/"hierarchical.rpt"}}}\nwrite_checkpoint -force {{{dcp}}}\nexit 0\n')
  run(label,['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',sub/'vivado.log','-source',tcl],sub,[report,dcp])
  return dict(resources=resources(report),report=str(report),report_sha256=sha(report),checkpoint=str(dcp),rtl_sha256=sha(rtl),tcl_sha256=sha(tcl),scope='OOC only; not whole-DUT FIT')
 update(memory_only_map=mapping('map-memory',memory,'AddressCurrentBucketMemory'))
 rtl=elaborate('address','PackageAddressStats');sub=O/'compare';sub.mkdir(exist_ok=True)
 for source,target in [('frozen-original.v','original.v'),('frozen-tb.v','tb.v')]:exact_text(sub/target,(C/source).read_text())
 exe=sub/'obj/Vtb'
 run('compare-compile',['/usr/local/bin/verilator','--binary','--timing','--top-module','tb','--Mdir',sub/'obj','-j',8,'--output-split',10000,'--output-split-cfuncs',200,'--x-initial',0,'--x-assign',0,'-Wno-fatal','-DRANDOMIZE_REG_INIT','-DRANDOMIZE_MEM_INIT',"-DRANDOM=32'h0",'-CFLAGS','-O0','-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',sub/'original.v',rtl,sub/'tb.v'],sub,[exe])
 log=run('compare',[exe],sub);assert 'ADDRESS_SEQUENTIAL_COMPARISON_PASS' in log.read_text()
 update(full_module_regression='PASS_6144_CYCLES_ALL_52_OUTPUTS_NOT_FORMAL',independent_global_reset_regression='PASS_GLOBAL_RESET_WITHOUT_RESETSTATS_PHASE_512_513_RESTART_516',rtl_sha256=sha(rtl))
 save(O/'verified-local.json',dict(hardware_commit=b['hardware_commit'],source_id=b['source_id'],rtl_sha256=sha(rtl),local_formal=st['local_formal'],memory_topology=topology,negative_mutation_rejected=True,actual_size_boundary=st['actual_size_boundary'],full_module_regression=st['full_module_regression'],independent_global_reset_regression=st['independent_global_reset_regression'],inherited_bucket_tag_verification=inherited['local_formal'],full_dut_formal=False))
 mapped=mapping('map-full-module',rtl,'PackageAddressStats')
 update(status='VERIFIED_AND_MAPPED_MODULE_ONLY',child={},ended_utc=now(),full_module_map=mapped);save(O/'result.json',st)

if __name__=='__main__':
 try:main()
 except Exception as exc:
  st=read(S)
  if st.get('pid')==os.getpid():st.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=now());save(S,st)
  raise
