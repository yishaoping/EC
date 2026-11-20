#!/usr/bin/python3
"""Compositional source validation of an independent metadata candidate.

This is not full-DUT formal and does not admit any CAD/FPGA build. Accurate
area must retain the complete generation observation and real source aliases.
"""
from pathlib import Path
import datetime,fcntl,hashlib,json,os,subprocess
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C=Path(__file__).resolve().parent;O=D/'build-logs/Opt4-fit-dcache-owner-memory-validation-r2-20261111';S=D/'Opt4-fit-dcache-owner-memory-validation-r2-state.json'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(p,j):
 p=Path(p);p.parent.mkdir(parents=True,exist_ok=True);t=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with t.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(t,p)
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def identity(pid):
 try:
  v=(Path('/proc')/str(pid)/'stat').read_text().rsplit(')',1)[1].split();return dict(pid=pid,start_ticks=v[19],process_state=v[0],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
 except FileNotFoundError:return {}
def main():
 O.mkdir(exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 cfg=json.loads((C/'config.json').read_text());b=cfg['binding'];F=Path(cfg['worktree']);src=F/cfg['source_relative']
 assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==b['hardware_commit']
 assert src.read_bytes()==subprocess.check_output(['git','show',b['hardware_commit']+':'+cfg['source_relative']],cwd=F)
 delta=subprocess.check_output(['git','diff','--name-only',b['parent_commit'],b['hardware_commit']],cwd=F,text=True).splitlines()
 assert set(delta)=={cfg['source_relative'],'lineage.json'}
 text=src.read_text();pairs=json.loads((C/'reverse-substitutions.json').read_text());back=text
 for new,old,count in reversed(pairs):
  assert new and back.count(new)>=count
  back=back.replace(new,old,count)
 parent=subprocess.check_output(['git','show',b['parent_commit']+':'+cfg['source_relative']],cwd=F)
 assert back.encode()==parent==(C/'parent.scala.txt').read_bytes()
 assert parent==(W/'C4'/cfg['source_relative']).read_bytes(),'DCache parent must equal integrated frozen baseline'
 for name in ['dirtyPacketSeq(','dirtyPacketTracked(','lineGeneration(','imageKey(']:assert name not in text
 assert text.count('ownerMemory.write(')==1 and text.count('ownerWriteEnable := true.B')==2
 assert 'ownerWriteEnable && !reset.asBool' in text and 'RegInit(VecInit(Seq.fill(nSets * nWays)(false.B)))' in text
 assert 'val dataWriteArb = Module(new Arbiter(new L1DataWriteReq, 2))' in text
 assert 'readOwner(s.U, w.U).generation' in text and 'dontTouch(debug_line_generation)' in text
 # Composition leaves every non-storage byte intact. The transition cut has
 # arbitrary payload/mask/index and sync-reset dominance; lift to all146 bits.
 prior=D/'build-logs/Opt4-fit-dcache-owner-memory-screen-r2-20261111'
 log=prior/'sat-transition.log';negative=prior/'sat-negative.log';assert 'SUCCESS' in log.read_text() and 'timed out' not in log.read_text()
 assert 'proof did fail' in negative.read_text() and 'timed out' not in negative.read_text()
 screen=json.loads((D/'Opt4-fit-dcache-owner-memory-screen-r2-state.json').read_text())
 assert screen['inductive_transition'].startswith('PASS_512_ENTRIES')
 for n,p in [('sat-transition',log),('sat-negative',negative)]:assert sha(p)==screen['stages'][n]['sha256']
 st=dict(schema='ec-opt4-owner-memory-source-validation/1',**identity(os.getpid()),hardware_commit=b['hardware_commit'],source_id=b['source_id'],parent_commit=b['parent_commit'],functional_baseline_commit=b['frozen_commit'],status='COMPOSITIONAL_SOURCE_RELATION_VERIFIED_TYPECHECK_PENDING',started_utc=now(),source_sha256=sha(src),exact_parent_reversal=True,frozen_dcache_parent_byte_equal=True,full_widths_preserved={'image':81,'generation':32,'packetSeq':32,'tracked':1},unqualified_read_accesses=b['read_accesses'],complete_generation_observation_preserved=True,
   induction_receipt={'reference_relation':'reference146 = written ? raw146 : 0; base synchronous reset establishes all words0; two arbiter write effects combine to exactly one full-word write; before/after edge reads unchanged.', 'scope':'Exact source reversal plus reused arbitrary512word transition induction, bitwise lifting to146. Not a full-DCache generated-RTL formal proof or integrated area measurement.', 'proof':str(log),'sha256':sha(log),'negative_sha256':sha(negative)},stages={},fpga_access=False,whole_dut_admission=False,production_selected=False)
 def update(**kw):st.update(kw);st['updated_utc']=now();save(S,st)
 update();classes=O/'classes';classes.mkdir(exist_ok=True)
 firechip=W/'C4/chipyard/generators/firechip/target/scala-2.13/firechip_2.13-1.6.jar'
 cp=':'.join([str(W/'Opt4-fit-update-share-svb-r2-20261111/builds/system-e0c3737f-r3/source-classes'),str(firechip),*cfg['classpath']])
 argv=[cfg['java'],'-Xmx16G','-Xss8M','-XX:ActiveProcessorCount=2','-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,'-Xplugin:'+cfg['plugin'],'-d',str(classes),str(src),str(F/'chipyard/generators/boom/src/main/scala/lsu/SafePrefixScanner.scala')]
 log=O/'typecheck.log';assert not log.exists()
 with log.open('xb',buffering=0) as f:
  p=subprocess.Popen(['nice','-n','10',*argv],cwd=O,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,env={**os.environ,'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':''})
  update(status='RUNNING_CHANGED_DCACHE_TYPECHECK',child=identity(p.pid))
  while p.poll() is None:
   try:p.wait(timeout=30)
   except subprocess.TimeoutExpired:pass
   update(child=identity(p.pid));os.fsync(f.fileno())
 st['stages']['typecheck']=dict(returncode=p.returncode,log=str(log),sha256=sha(log),argv=argv)
 assert p.returncode==0 and (classes/'boom/lsu/BoomNonBlockingDCacheModule.class').is_file()
 update(status='PASS_SOURCE_BOUND_COMPOSITIONAL_STORAGE_RELATION_AND_DCACHE_TYPECHECK_NOT_AREA_ADMITTED',child={},ended_utc=now(),remaining=['Complete source-derived storage map with original512x32 generation observation and original input alias constraints','Generated complete-DCache boundary equivalence or independently reviewed source-bound compositional admission','Composition with exact selected address candidate before whole synthesis'])
 save(O/'result.json',st)
if __name__=='__main__':
 try:main()
 except Exception as e:
  if S.exists():
   j=json.loads(S.read_text())
   if j.get('pid')==os.getpid():j.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(S,j)
  raise
