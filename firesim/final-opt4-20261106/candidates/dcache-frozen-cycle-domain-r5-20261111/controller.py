#!/usr/bin/python3
from pathlib import Path
import datetime,fcntl,hashlib,json,os,subprocess
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C=Path(__file__).resolve().parent;O=D/'build-logs/Opt4-fit-dcache-frozen-cycle-domain-r5-20261111';S=D/'Opt4-fit-dcache-frozen-cycle-domain-r5-state.json'
MODEL=D/'build-logs/Opt4-fit-dcache-frozen-cycle-r4-20261111/obj'
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
 prior=read(C/'prior-state.json');broker=read(C/'prior-broker.json')
 for j in [prior,broker]:
  assert j['status']=='FAILED_WITH_EVIDENCE' and not live(j) and not live(j.get('child',{}))
 manifest=read(C/'model-binding.json');assert all(sha(p)==h for p,h in manifest.items())
 assert prior['stages']['compile']['returncode']==0 and prior['preparation']['compared_signals']==2534
 assert 'primary write domain must describe its own request' in Path(prior['stages']['comparison']['log']).read_text()
 old=Path('/data1/gzh/EC/firesim/final-opt4-20261106/candidates/dcache-frozen-cycle-r4-20261111/stimulus.cpp').read_text()
 assert (C/'stimulus.cpp').read_text()==old.replace('d.io___05Flsu_req_bits_0_bits_write_domain_valid = 1;','d.io___05Flsu_req_bits_0_bits_write_domain_valid = store;')
 st=dict(schema='ec-opt4-complete-frozen-dcache-cycle-stimulus-recovery/1',**ident(os.getpid()),hardware_commit=prior['hardware_commit'],source_id=prior['source_id'],functional_baseline_commit=prior['functional_baseline_commit'],status='REUSING_AUTHENTICATED_R4_COMPILED_MODEL',started_utc=now(),stages={},preparation=prior['preparation'],fpga_access=False,complete_dcache_cycles_verified=False,whole_admission=False,full_dut_formal=False,rtl_changed=False,assertions_disabled=False)
 def update(**kw):st.update(kw);st['updated_utc']=now();save(S,st)
 update()
 env={**os.environ,'LD_LIBRARY_PATH':'','CCACHE_DISABLE':'1','OMP_NUM_THREADS':'2','TMPDIR':str(O)}
 def run(n,argv):
  policy();log=O/(n+'-attempt-1.log')
  with log.open('xb',buffering=0) as f:
   child=subprocess.Popen(['nice','-n','15',*map(str,argv)],cwd=O,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT);update(status='RUNNING_'+n.upper(),child=ident(child.pid),stage_log=str(log))
   while child.poll() is None:
    try:child.wait(timeout=30)
    except subprocess.TimeoutExpired:pass
    update();os.fsync(f.fileno())
  st['stages'][n]=dict(argv=list(map(str,argv)),returncode=child.returncode,log=str(log),log_sha256=sha(log),ended_utc=now());update(child={});assert child.returncode==0,(n,child.returncode,str(log))
  return log
 clang='/usr/bin/clang++'
 if not Path(clang).exists():clang='clang++'
 run('compile-stimulus',[clang,'-O0','-std=c++17','-faligned-new','-fbracket-depth=4096','-I'+str(MODEL),'-I/usr/local/share/verilator/include','-I/usr/local/share/verilator/include/vltstd','-I'+str(C),'-c',C/'stimulus.cpp','-o',O/'stimulus.o'])
 exe=O/'VDCacheCyclePair'
 run('link',[clang,O/'stimulus.o',MODEL/'verilated.o',MODEL/'verilated_threads.o',MODEL/'VDCacheCyclePair__ALL.a','-pthread','-lpthread','-latomic','-o',exe])
 log=run('comparison',[exe]);assert 'COMPLETE_FROZEN_DCACHE_CYCLE_PASS cycles=8192' in log.read_text()
 update(status='PASS_COMPLETE_FROZEN_DCACHE_8192_CYCLE_OBSERVATION_REGRESSION_NOT_FULL_FORMAL_NOT_WHOLE_ADMITTED',complete_dcache_cycles_verified=True,ended_utc=now(),executable_sha256=sha(exe));save(O/'result.json',st)
if __name__=='__main__':
 try:main()
 except Exception as e:
  if S.exists():
   st=read(S)
   if st.get('pid')==os.getpid():st.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(S,st)
  raise
