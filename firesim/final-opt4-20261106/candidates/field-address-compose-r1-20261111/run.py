#!/usr/bin/python3
"""Prevalidate8d50489a exact source composition before long module maps finish.
No whole synthesis/FPGA admission, no existing outputs modified.
"""
from pathlib import Path
import datetime,fcntl,hashlib,importlib.util,json,os,re,subprocess,time
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');C=Path(__file__).resolve().parent;L=D/'build-logs/Opt4-fit-field-address-precheck-r1-20261111';S=D/'Opt4-fit-field-address-precheck-r1-state.json'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def read(p):return json.loads(Path(p).read_text())
def save(p,j):
 p=Path(p);p.parent.mkdir(exist_ok=True,parents=True);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with q.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(q,p)
def ident(pid):
 try:
  s=Path(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split();return dict(pid=pid,start_ticks=s[19],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),process_state=s[0])
 except FileNotFoundError:return {}
def main():
 assert not S.exists(),'preserve prior results; versioned recovery required'
 L.mkdir(exist_ok=True);lock=(L/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 manifest=read(C/'input-hashes.json');assert manifest and all(sha(p)==h for p,h in manifest.items())
 cfg=read(W/'candidates/field-address-compose-r1-20261111/config.json');b=cfg['binding'];F=Path(cfg['worktree']);owner,sequence=b['component_commits'];base=b['common_equivalent_parent'];rel='chipyard/generators/boom/src/main/scala/lsu/'
 assert b['hardware_commit']=='8d50489af3af9e4c766509284ba3d9d7c99cfec9' and subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==b['hardware_commit']
 get=lambda co,p:subprocess.check_output(['git','show',co+':'+p],cwd=F)
 assert (F/rel/'dcache.scala').read_bytes()==get(owner,rel+'dcache.scala')
 for n in ['PackageAddressStats.scala','AddressBucketSequenceMemory.scala']:assert (F/rel/n).read_bytes()==get(sequence,rel+n)
 allowed={rel+'dcache.scala',rel+'PackageAddressStats.scala',rel+'AddressBucketSequenceMemory.scala','lineage.json'}
 assert set(subprocess.check_output(['git','diff','--name-only',base,b['hardware_commit']],cwd=F,text=True).splitlines())==allowed
 for p in b['changed_files']:
  if p not in allowed:assert (F/p).read_bytes()==get(base,p)
 spec=importlib.util.spec_from_file_location('precheck_inventory',W/'scripts/build_hw.py');m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);inv=m.inventory(F/'chipyard');assert hashlib.sha256(json.dumps(inv,sort_keys=True).encode()).hexdigest()==b['source_id']
 addr=read(D/'Opt4-fit-address-update-sequence-r1-state.json');assert addr['hardware_commit']==sequence and addr['exact_parent_reversal'] and addr['full_module_regression'].startswith('PASS_6144')
 old=read(C/'evidence/field-source.json');assert old['hardware_commit']==owner and old['exact_parent_reversal'] and old['frozen_parameters_match'] and old['actual_field_write_mutation_rejected'];assert old['status']=='PASS_SOURCE_BOUND_FIELD_STORAGE_RELATION_TYPECHECK_FROZEN_PARAMETERS_NOT_GENERATED_OR_AREA_ADMITTED'
 parent=read(C/'evidence/owner-parent-composition.json');assert parent['hardware_commit']==old['parent_commit'] and parent['exact_source_reversal'] and parent['status'].startswith('PASS_')
 st=dict(schema='ec-opt4-pre-area-source-composition/1',**ident(os.getpid()),hardware_commit=b['hardware_commit'],source_id=b['source_id'],functional_baseline_commit=b['frozen_commit'],status='SOURCE_COMPOSITION_VERIFIED_COMPILING',started_utc=now(),fpga_access=False,area_admitted=False,production_selected=False,whole_dut_formal=False,stages={})
 def update(**kw):st.update(kw);st['updated_utc']=now();save(S,st)
 update();classes=L/'classes';classes.mkdir();cp=':'.join(cfg['classpath']);env={**os.environ,'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':'','CCACHE_DISABLE':'1'}
 def run(name,argv):
  log=L/(name+'.log');assert not log.exists()
  with log.open('xb',buffering=0) as f:
   p=subprocess.Popen(list(map(str,['nice','-n','10',*argv])),cwd=F/'chipyard',stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,env=env);update(status='RUNNING_'+name.upper(),active_stage=name,child=ident(p.pid))
   while p.poll() is None:
    try:p.wait(timeout=30)
    except subprocess.TimeoutExpired:pass
    update();os.fsync(f.fileno())
  st['stages'][name]=dict(returncode=p.returncode,log=str(log),sha256=sha(log));update(child={});assert p.returncode==0,(name,p.returncode,str(log))
 sources=[F/p for p in b['changed_files']];emit=W/'candidates/address-update-sequence-r1-20261111/Emit.scala'
 run('compile',[cfg['java'],'-Xmx24G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,'-Xplugin:'+cfg['plugin'],'-d',classes,*sources,emit])
 assert (classes/'boom/lsu/BoomNonBlockingDCacheModule.class').is_file() and (classes/'boom/lsu/AddressBucketSequenceReplica.class').is_file()
 cp=str(classes)+':'+cfg['firechip']+':'+cp
 out=L/'parameters.json';run('parameters',[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=2','-Dec.dac.firesim=true','-cp',cp,'firesim.firesim.DacParameterAudit','firesim.firesim.DacOpt4C4',out]);assert read(out)==read(cfg['frozen_parameters'])
 sub=L/'address';sub.mkdir();run('emit-address',[cfg['java'],'-Xmx24G','-Xss8M','-XX:ActiveProcessorCount=4','-Dec.dac.firesim=true','-cp',cp,'opt4retirestatic.Emit','address',sub])
 actual=sub/'PackageAddressStats.v';original=D/'build-logs/Opt4-fit-address-update-sequence-r1-20261111/address/PackageAddressStats.v'
 def normalized(p):return re.sub(r'\s+',' ',re.sub(r'//[^\n]*','',Path(p).read_text())).strip()
 assert normalized(actual)==normalized(original),'combined classpath changed actual addressRTL'
 update(status='PASS_EXACT_DISJOINT_COMPOSITION_FULL_CHANGED_SOURCE_TYPECHECK_FROZEN_PARAMETERS_AND_EMITTED_ADDRESS_RTL_NOT_AREA_ADMITTED',ended_utc=now(),address_rtl_sha256=sha(actual),component_address_rtl_sha256=sha(original),normalized_component_rtl_equal=True,changed_source_sha256={str(p):sha(p) for p in sources},class_sha256={str(p.relative_to(classes)):sha(p) for p in sorted(classes.rglob('*.class'))},component_proofs=[dict(path=str(p),sha256=sha(p)) for p in sorted((C/'evidence').glob('*.json'))],proof_limits='Exact disjoint component source composition and actual combinedsource compile/parameter/emittedaddress identity. Inherited source-bound packed-to-field storage relation, parent owner-transition proof and6144cycle frozenaddress comparison. Actual generated field proof and complete DCache cycle comparison are separate gates. Not monolithic fullDCache or fullDUTformal. Requires actual fullmodule area, finalGG7ABI and wholecapacity gates before admission.');save(L/'result.json',st)
if __name__=='__main__':
 try:main()
 except Exception as exc:
  if S.exists():
   s=read(S)
   if s.get('pid')==os.getpid():s.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=now());save(S,s)
  raise
