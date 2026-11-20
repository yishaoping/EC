#!/usr/bin/python3
"""Continue exact passed storage proof/topology with corrected generated port API."""
from pathlib import Path
import datetime,fcntl,hashlib,json,os,shutil,subprocess
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');C=Path(__file__).resolve().parent
O=D/'build-logs/Opt4-fit-reservation-proof-r2-20261111';S=D/'Opt4-fit-reservation-proof-r2-state.json'
OLD=W/'candidates/reservation-memory-r1-20261111';PRIOR=D/'build-logs/Opt4-fit-reservation-proof-r1-20261111'
def read(p):return json.loads(Path(p).read_text())
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def save(p,j):
 p=Path(p);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with q.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(q,p)
def ident(pid):
 try:
  s=Path(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split();return dict(pid=pid,start_ticks=s[19],process_state=s[0],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
 except FileNotFoundError:return {}
def live(j):
 x=ident(j.get('pid',0));return x and x['start_ticks']==str(j.get('start_ticks')) and x['host_boot_id']==j.get('host_boot_id') and x['process_state'] not in ['X','Z']
def policy():
 p=read(D/'unattended-opt4/campaign-policy.json');assert p['area_equivalence_only'] and not p['functional_extensions_allowed'] and not p['fpga_access']
 assert p['functional_baseline_commit']=='8491167d84b6d9521b151a743673c1516926a1f8'
def main():
 policy();O.mkdir(exist_ok=False);lock=(O/'instance.lock').open('x');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB);assert not S.exists()
 prior=read(C/'prior-state.json');assert prior['status']=='FAILED_WITH_EVIDENCE' and not live(prior) and not live(prior.get('child',{}))
 assert prior['stages']['compile-boundary']['returncode']==2
 passed={}
 for n in ['compile','emit-proof','emit-pair','emit-reference','emit-candidate','sat-transition','sat-write-data-mutation','topology']:
  r=prior['stages'][n];assert r['accepted'] and sha(r['log'])==r['sha256']
  assert all(sha(p)==h for p,h in r['outputs'].items());passed[n]=r
 assert 'SUCCESS' in Path(passed['sat-transition']['log']).read_text()
 assert 'proof did fail' in Path(passed['sat-write-data-mutation']['log']).read_text()
 b=read(C/'binding-r2.json');assert sha(Path(b['worktree'])/'chipyard/generators/boom/src/main/scala/lsu/dcache.scala')==b['dcache_sha256']
 st=dict(**b,**ident(os.getpid()),status='REUSING_AUTHENTICATED_PROOF_AND_GENERATED_MODEL',schema='ec-opt4-reservation-proof-continuation/1',stages={},reused_stages=passed,started_utc=now(),full_dut_formal=False,rtl_changed=False,whole_admission=False)
 def update(**kw):st.update(kw);st['updated_utc']=now();save(S,st)
 update();model=read(C/'model-inputs.json');obj=O/'obj';obj.mkdir()
 for p,h in model.items():
  src=Path(p);assert sha(src)==h;shutil.copy2(src,obj/src.name)
 mk=obj/'VReservationPair.mk';s=mk.read_text();assert str(OLD) in s;mk.write_text(s.replace(str(OLD),str(C)))
 env={**os.environ,'LD_LIBRARY_PATH':'','CCACHE_DISABLE':'1','OMP_NUM_THREADS':'2','TMPDIR':str(O)}
 def run(n,argv):
  policy();log=O/(n+'-attempt-1.log')
  with log.open('xb',buffering=0) as f:
   child=subprocess.Popen(['nice','-n','15',*map(str,argv)],cwd=obj,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT);update(status='RUNNING_'+n.upper(),child=ident(child.pid),stage_log=str(log))
   while child.poll() is None:
    try:child.wait(timeout=30)
    except subprocess.TimeoutExpired:pass
    update();os.fsync(f.fileno())
  st['stages'][n]=dict(returncode=child.returncode,argv=list(map(str,argv)),log=str(log),sha256=sha(log));update(child={});assert child.returncode==0,(n,child.returncode,str(log))
  return log
 run('compile-boundary',['/usr/bin/make','-f','VReservationPair.mk','-j2','OPT_FAST=-O0','OPT_SLOW=-O0'])
 exe=obj/'VReservationPair';log=run('boundary',[exe]);assert 'RESERVATION_BOUNDARY_PASS cycles=8192 entries=512 bits=80 readers=5' in log.read_text()
 rtls={}
 for label,top in [('proof','ReservationTransition'),('pair','ReservationPair'),('reference','ReservationReference'),('candidate','ReservationCandidate')]:
  f=PRIOR/label/(top+'.v');rtls[label]=dict(path=str(f),sha256=sha(f))
 update(status='PASS_SOURCE_BOUND_ARBITRARY_STATE_BITWISE_STORAGE_RELATION_ACTUAL_TOPOLOGY_AND_8192_CYCLES_FULL_DCACHE_PENDING',rtls=rtls,mutation_rejected=True,payload_reset='NONE_PRESERVED',all80_bits_retained=True,scope='Uninitialized512x80 fivefield storage with5arbitrary asyncreaders, exact sourcehelper and source reversal; local screen only, fullDCache generated proof/cycle/map still required.',ended_utc=now());save(O/'result.json',st)
if __name__=='__main__':
 try:main()
 except Exception as e:
  if S.exists():
   st=read(S)
   if st.get('pid')==os.getpid():st.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(S,st)
  raise
