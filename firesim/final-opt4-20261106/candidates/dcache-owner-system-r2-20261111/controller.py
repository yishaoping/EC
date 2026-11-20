#!/usr/bin/python3
"""Verified best-module integration, GoldenGate and seven-file ABI audit only.
No synthesis, FPGA access, driver receipt rewriting or CAD job control.
"""
from pathlib import Path
import datetime as dt,fcntl,hashlib,importlib.util,json,os,shutil,subprocess,sys,time
C=Path(__file__).resolve().parent;W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
L=D/'build-logs/Opt4-fit-dcache-owner-system-r2-20261111';S=D/'Opt4-fit-dcache-owner-system-r2-state.json';RS=D/'Opt4-fit-dcache-owner-rtl-state.json'
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for b in iter(lambda:f.read(2**20),b''):h.update(b)
 return h.hexdigest()
def read(p):return json.loads(Path(p).read_text()) if Path(p).is_file() else {}
def now():return dt.datetime.now(dt.timezone.utc).isoformat()
def save(p,x):
 p=Path(p);p.parent.mkdir(parents=True,exist_ok=True);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with q.open('w') as f:json.dump(x,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(q,p)
def identity(pid):
 try:
  s=Path(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split();return dict(pid=pid,start_ticks=s[19],process_state=s[0],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
 except FileNotFoundError:return {}
def live(x):
 v=identity(x.get('pid',0));return bool(v and v['start_ticks']==str(x.get('start_ticks')) and v['host_boot_id']==x.get('host_boot_id') and v['process_state'] not in ['X','Z'])
def resource_gate():
 memory=int(next(s.split()[1] for s in Path('/proc/meminfo').read_text().splitlines() if s.startswith('MemAvailable:')))
 return memory>=96*2**20 and shutil.disk_usage(W).free>=100*2**30

def main():
 L.mkdir(exist_ok=True);lock=(L/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 old=read(S);assert not live(old) and not live(old.get('child',{})),'adopt live controller/child'
 cfg=read(C/'config.json');b=cfg['binding'];F=Path(cfg['worktree']);commit=b['hardware_commit'];O=F/'builds'/('system-'+commit[:8]+'-r3');O.mkdir(parents=True,exist_ok=True)
 manifest=read(C/'input-hashes.json');assert all(sha(p)==h for p,h in manifest.items()),'input changed'
 assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==commit
 sys.path.insert(0,str(W/'scripts'));spec=importlib.util.spec_from_file_location('system_inventory',W/'scripts/build_hw.py');mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod)
 inventory=mod.inventory(F/'chipyard');assert hashlib.sha256(json.dumps(inventory,sort_keys=True).encode()).hexdigest()==b['source_id']
 # Wait on exact independent validation/map checkpoints. No expensive RTL
 # generation for a failed or low-gain probe. The current CAD is untouched.
 waiting=dict(schema='ec-opt4-owner-system-wait/1',**identity(os.getpid()),hardware_commit=commit,source_id=b['source_id'],status='WAITING_OWNER_PROOF_AND_OBSERVED_AREA',started_utc=now(),fpga_access=False)
 save(S,waiting)
 while True:
  mapped=read(D/'Opt4-fit-dcache-owner-observed-map-r1-state.json')
  source=read(D/'Opt4-fit-dcache-owner-memory-validation-r3-state.json')
  arbiter=read(D/'Opt4-fit-dcache-owner-arbiter-proof-r3-state.json')
  if any(x.get('status') in ['FAILED_WITH_EVIDENCE','DEPENDENCY_FAILED_WITH_EVIDENCE','SKIPPED_LOW_GAIN_SCREEN'] for x in [mapped,source,arbiter]):
   waiting.update(status='DEPENDENCY_FAILED_WITH_EVIDENCE',dependencies=[x.get('status') for x in [mapped,source,arbiter]],updated_utc=now());save(S,waiting);save(L/'result.json',waiting);return
  if mapped.get('status','').startswith('COMPLETE_') and source.get('status','').startswith('PASS_') and arbiter.get('status','').startswith('PASS_'):break
  waiting.update(updated_utc=now(),dependencies=[x.get('status') for x in [mapped,source,arbiter]]);save(S,waiting);time.sleep(300)
 if mapped['lut_saved']<75000:
  waiting.update(status='SKIPPED_INSUFFICIENT_OBSERVED_STORAGE_GAIN',lut_saved=mapped['lut_saved'],updated_utc=now());save(S,waiting);save(L/'result.json',waiting);return
 st=dict(schema='ec-opt4-best-module-system-preparation/1',**identity(os.getpid()),hardware_commit=commit,source_id=b['source_id'],status='STARTING',started_utc=now(),stages=old.get('stages',{}),fpga_access=False,full_dut_synthesis=False,formal_admission=False,proof_limits='Exact e0 source composition plus source-bound full-width owner-memory induction, actual Arbiter2 write exclusion, reset/observation regression and measured observed storage boundary. Not full-DUT formal or integrated FIT inference.')
 save(S,st)
 def update(**kw):st.update(kw);st['updated_utc']=now();save(S,st)
 tmp=L/'tmp';tmp.mkdir(exist_ok=True)
 env={**os.environ,'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':'','OMP_NUM_THREADS':'8','TMPDIR':str(tmp),'CCACHE_DISABLE':'1','CCACHE_DIR':str(L/'ccache')}
 def stage(name,args,out,outputs):
  out.mkdir(parents=True,exist_ok=True);rp=L/(name+'-result.json');r=read(rp)
  if r:
   assert r['hardware_commit']==commit and r['source_id']==b['source_id'] and r['returncode']==0
   assert all(sha(p)==h for p,h in r['outputs'].items());st['stages'][name]=r;save(S,st);return
  while not resource_gate():update(status='WAITING_RESOURCE_GATE',next_stage=name);time.sleep(300)
  log=L/(name+'-attempt-1.log');assert not log.exists(),'failed/incomplete stage requires reviewed recovery'
  with log.open('xb',buffering=0) as f:
   argv=list(map(str,['nice','-n','10',*args]));p=subprocess.Popen(argv,cwd=F/'chipyard',env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT)
   child=identity(p.pid);r=dict(hardware_commit=commit,source_id=b['source_id'],argv=argv,log=str(log),started_utc=now(),**child);update(status='RUNNING_'+name.upper(),child=child,active_stage=name)
   while p.poll() is None:
    try:p.wait(timeout=30)
    except subprocess.TimeoutExpired:pass
    update();os.fsync(f.fileno())
  missing=[str(p) for p in outputs if not p.is_file() or not p.stat().st_size]
  r.update(returncode=p.returncode,ended_utc=now(),outputs={str(p):sha(p) for p in outputs if p.is_file()},missing_outputs=missing);save(rp,r);st['stages'][name]=r;update(child={})
  assert p.returncode==0 and not missing,(name,p.returncode,str(log),missing)
 stage('verify-combination',['/usr/bin/python3',C/'verify_combination.py'],L,[L/'combined-equivalence.json'])
 classes=O/'source-classes';classes.mkdir(exist_ok=True);sources=[]
 for rel in b['changed_files']:
  p=L/'sources'/rel;p.parent.mkdir(parents=True,exist_ok=True);data=subprocess.check_output(['git','show',commit+':'+rel],cwd=F)
  assert data==(F/rel).read_bytes()
  if p.exists():assert p.read_bytes()==data
  else:p.write_bytes(data)
  sources.append(p)
 jav=[cfg['java'],'-Xmx32G','-Xss8M','-XX:ActiveProcessorCount=8','-Dec.dac.firesim=true']
 stage('compile',[cfg['java'],'-Xmx24G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',':'.join(cfg['classpath']),'-Xplugin:'+cfg['plugin'],'-d',classes,*sources],classes,[classes/'boom/lsu/PackageAddressStats.class',classes/'boom/lsu/AddressBucketGrouped$.class',classes/'boom/lsu/SafePrefixScanner.class'])
 class_hashes={str(p.relative_to(classes)):sha(p) for p in sorted(classes.rglob('*.class'))};assert len(class_hashes)>=31
 # Exact re-emission equality for both composed modules is already hash-bound.
 cp=str(classes)+':'+cfg['firechip']+':'+':'.join(cfg['classpath']);parameters=O/'parameters';pp=parameters/'parameters.json'
 stage('parameters',jav+['-cp',cp,'firesim.firesim.DacParameterAudit','firesim.firesim.DacOpt4C4',str(pp)],parameters,[pp])
 assert read(pp)==read(cfg['frozen_parameters']),'frozen core/checker/cache/memory configuration changed'
 update(configuration_matches_frozen_parameters=True)
 elab=O/'elaborate';fir=elab/'firesim.firesim.FireSim.fir';anno=elab/'firesim.firesim.FireSim.anno.json'
 stage('elaborate',jav+['-verbose:class','-cp',cp,'chipyard.Generator','--target-dir',str(elab),'--name','firesim.firesim.FireSim','--top-module','firesim.firesim.FireSim','--legacy-configs','firesim.firesim:DacOpt4C4'],elab,[fir,anno,elab/'firesim.firesim.FireSim.dts',elab/'firesim.firesim.FireSim.dromajo_params.h'])
 text=(L/'elaborate-attempt-1.log').read_text(errors='replace')
 names=['boom.lsu.AddressBucketGrouped$','boom.lsu.PackageAddressStats','boom.lsu.SafePrefixScanner','boom.lsu.BoomNonBlockingDCache','boom.lsu.BoomNonBlockingDCacheModule$OwnerPayload','freechips.rocketchip.guardiancouncil.GHBarrierLatencyStats','sifive.blocks.inclusivecache.InclusiveCache','boom.lsu.NewestSafeEntry$','boom.lsu.SpeculativeVersionBuffer','boom.lsu.AddressBucketUpdate$']
 origins={n:[l for l in text.splitlines() if n in l and str(classes) in l] for n in names};assert all(origins.values()),origins
 save(L/'modified-class-origins.json',origins);update(modified_class_origins_verified=True)
 gg=O/'goldengate';expected=[gg/n for n in ['FireSim-generated.sv','FireSim-generated.const.h','FireSim-generated.const.vh','FireSim-generated.defines.vh','FireSim-generated.synthesis.xdc','FireSim-generated.implementation.xdc']]
 stage('goldengate',jav+['-cp',cp,'midas.stage.GoldenGateMain','-i',str(fir),'-td',str(gg),'-faf',str(anno),'-ggcp','firesim.configs','-ggcs','DacXilinxAlveoConfig','--output-filename-base','FireSim-generated','--no-dedup'],gg,expected)
 marker=L/'blackbox-append.json'
 if not marker.exists():
  listing=gg/'firrtl_black_box_resource_files.f';added={}
  if listing.exists():
   with (gg/'FireSim-generated.sv').open('ab') as f:
    for line in listing.read_text().splitlines():
     if line.strip():
      path=Path(line.strip());assert path.resolve().is_relative_to(W) or path.resolve().is_relative_to(D)
      f.write(path.read_bytes());f.write(b'\n');added[str(path)]=sha(path)
    f.flush();os.fsync(f.fileno())
  save(marker,dict(resources=added,output_sha256=sha(gg/'FireSim-generated.sv')))
 assert all(sha(classes/p)==h for p,h in class_hashes.items());assert all(sha(p)==h for p,h in manifest.items()),'bound inputs changed'
 rtl=dict(schema='ec-opt4-fit-whole-rtl/1',status='GOLDENGATE_COMPLETE_NOT_SYNTHESIZED',hardware_commit=commit,source_id=b['source_id'],goldengate_dir=str(gg),elaboration_dir=str(elab),modified_class_origins_verified=True,configuration_matches_frozen_parameters=True,private_class_hashes=class_hashes,outputs={str(p):sha(p) for p in gg.iterdir() if p.is_file()},full_dut_synthesis=False,fpga_access=False,formal_admission=False)
 save(RS,rtl)
 base=read(cfg['baseline_driver_compatibility']);rows=[]
 assert len(base['generated_abi_and_target_description'])==7
 for row in base['generated_abi_and_target_description']:
  role=row['role'];derived=(gg if role.startswith('FireSim-generated.') else elab)/role
  original_hash=sha(row['original']);derived_hash=sha(derived)
  rows.append(dict(role=role,original=row['original'],derived=str(derived),original_sha256=original_hash,derived_sha256=derived_hash,byte_equal=original_hash==derived_hash))
 equal=all(row['byte_equal'] for row in rows);audit=dict(schema='ec-opt4-real-seven-file-abi-audit/1',hardware_commit=commit,source_id=b['source_id'],status='ALL_7_BYTE_EQUAL_REUSE_ELIGIBLE' if equal else 'ABI_CHANGED_REQUIRES_REAL_DRIVER_REBUILD',rows=rows,recompiled=False,driver_reuse_certified=False,fpga_access=False)
 save(L/'driver-reuse-seven-file-audit.json',audit);update(status='RTL_READY_REAL_ABI_CHECKED' if equal else 'RTL_READY_DRIVER_REBUILD_REQUIRED',abi_status=audit['status'],ended_utc=now());save(L/'result.json',st)
if __name__=='__main__':
 try:main()
 except Exception as e:
  s=read(S)
  if s.get('pid')==os.getpid():s.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(S,s)
  raise
