#!/usr/bin/python3
from pathlib import Path
import sys,subprocess,json,os,fcntl,time
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import *
C=Path(__file__).resolve().parent;O=D/'build-logs/Opt4-svb-invalidation-validation-r2-20261111';S=D/'Opt4-svb-invalidation-validation-r2-state.json'
def main():
 O.mkdir(exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 old=read(S);assert not live(old) and not live(old.get('child',{}))
 cfg=read(C/'binding.json');assert all(sha(p)==h for p,h in cfg['inputs'].items())
 P=Path(cfg['rtl']);L=Path(cfg['logger']);F=Path(cfg['worktree']);assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==cfg['hardware_commit']
 st=dict(**identity(),status='STARTING',hardware_commit=cfg['hardware_commit'],source_id=cfg['source_id'],rtl=str(P),rtl_sha256=sha(P),fpga_execution=False,architectural_restart_validated=False,started_utc=now(),stages={});save(S,st)
 env={**os.environ,'CCACHE_DISABLE':'1','CCACHE_DIR':str(O/'ccache'),'CCACHE_TEMPDIR':str(O/'tmp'),'TMPDIR':str(O/'tmp')};(O/'tmp').mkdir(exist_ok=True)
 def stage(label,argv,timeout,negative=False):
  log=O/(label+'.log');assert not log.exists()
  with log.open('xb',buffering=0) as f:
   p=subprocess.Popen(argv,stdout=f,stderr=subprocess.STDOUT,env=env,cwd=O,stdin=subprocess.DEVNULL,start_new_session=True);start=time.monotonic();st.update(status='RUNNING_'+label.upper(),child=identity(p.pid));save(S,st)
   while p.poll() is None:
    try:p.wait(timeout=30)
    except subprocess.TimeoutExpired:pass
    st.update(updated_utc=now());save(S,st);os.fsync(f.fileno())
    if p.poll() is None and time.monotonic()-start>timeout:
     os.killpg(p.pid,15)
     try:p.wait(timeout=10)
     except subprocess.TimeoutExpired:os.killpg(p.pid,9);p.wait()
     raise AssertionError((label,'timeout',str(log)))
  result=dict(returncode=p.returncode,log=str(log),sha256=sha(log),ended_utc=now());st['stages'][label]=result;st.update(child={});save(S,st)
  assert (p.returncode!=0 if negative else p.returncode==0),(label,p.returncode,str(log))
  return log
 argv=['/usr/local/bin/verilator','--cc','--exe','--build','--assert','--top-module','SVBModuleHarness','--Mdir',str(O/'obj'),'-j','8','-Wno-fatal','-CFLAGS','-O0','-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',str(P),str(L),str(C/'test.cpp')]
 stage('compile',argv,1200)
 log=stage('valid-invalidation-owner-data',[str(O/'obj/VSVBModuleHarness')],60)
 assert 'SVB_INVALIDATION_OWNER_DATA_LIFETIME_PASS' in log.read_text()
 log=stage('negative-mismatched-ack',[str(O/'obj/VSVBModuleHarness'),'bad-ack'],60,negative=True)
 assert 'SVB completion does not match the outstanding entry/key' in log.read_text()
 assert all(sha(p)==h for p,h in cfg['inputs'].items())
 st.update(status='PASS_REAL_RTL_SVB_INVALIDATION_OWNER_DATA_AND_NEGATIVE_ACK_NOT_ARCHITECTURAL_ROLLBACK',completed_utc=now(),limitations='Real SVB RTL with assertions and all 512-bit payload/owner stability; existing invalidate boundary and mismatch ACK rejection. Does not execute actual checker comparison, CDC FAIL, architectural restore or instruction restart. Not a full-DUT formal proof or FPGA sample.');save(O/'result.json',st);save(S,st)
if __name__=='__main__':
 try:main()
 except Exception as e:
  st=read(S)
  if st.get('pid')==os.getpid():st.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(S,st)
  raise
