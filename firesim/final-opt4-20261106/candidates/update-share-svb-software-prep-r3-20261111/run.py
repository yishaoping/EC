#!/usr/bin/python3
"""Prepare all 13 exact paired software profiles before bitstream; no FPGA IO."""
from pathlib import Path
import sys,fcntl,subprocess,os,time
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import *
import prepare_opt4_candidate_runtime as prep
O=D/'build-logs/Opt4-fit-update-share-svb-software-prep-r3-20261111';S=D/'Opt4-fit-update-share-svb-software-prep-r3-state.json'
def main():
 O.mkdir(exist_ok=True);lk=(O/'instance.lock').open('a');fcntl.flock(lk,fcntl.LOCK_EX|fcntl.LOCK_NB);old=read(S);assert not live(old) and not live(old.get('child',{}))
 desc=W/'runtime-candidates/e0c3737f.json';x=prep.descriptor(desc);assert x['commit']=='e0c3737f989c563f99a00f3fd26c1cbd27421775'
 st=dict(**identity(),status='PREPARING_EXACT_DRIVER_AND_13_SOFTWARE_PROFILES',hardware_commit=x['commit'],source_id=x['source_id'],started_utc=now(),fpga_access=False,formal_admission=False);save(S,st)
 out,bundle=prep.generate(x)
 while True:
  r=read(x['rtl_state']);system=read(D/'Opt4-fit-update-share-svb-system-r3-state.json')
  assert system.get('hardware_commit') in [None,x['commit']]
  if system.get('status')=='FAILED_WITH_EVIDENCE':raise RuntimeError(('candidate RTL preparation failed',system.get('error')))
  if r.get('status')=='GOLDENGATE_COMPLETE_NOT_SYNTHESIZED':break
  st.update(status='WAITING_BOUND_GOLDENGATE_FOR_EXACT_ABI',updated_utc=now());save(S,st);time.sleep(60)
 prep.compatibility(x,out)
 log=O/'prepare.log';assert not log.exists()
 with log.open('xb',buffering=0) as f:
  p=subprocess.Popen(['/usr/bin/python3',str(bundle/'prepare_opt4_fit_runtime.py')],cwd=out,stdout=f,stderr=subprocess.STDOUT,stdin=subprocess.DEVNULL);st.update(child=identity(p.pid));save(S,st)
  while p.poll() is None:
   try:p.wait(timeout=30)
   except subprocess.TimeoutExpired:pass
   st.update(updated_utc=now());save(S,st);os.fsync(f.fileno())
 assert p.returncode==0,(p.returncode,str(log))
 suite=read(out/'software-suite.json');assert suite['hardware_commit']==x['commit'] and suite['source_id']==x['source_id'] and len(suite['programs'])==13
 assert all(len(row['native_references'])==3 and row['threads']==1 and row['formal_input']=='simmedium' for row in suite['programs'])
 st.update(status='13_ORDINARY_PROGRAMS_EXACT_PAIRED_SOFTWARE_READY_NOT_FPGA_ADMITTED',child={},ended_utc=now(),programs=[r['program'] for r in suite['programs']],software_suite=str(out/'software-suite.json'),software_suite_sha256=sha(out/'software-suite.json'),program_count=13,bitstream_certified=False,fpga_execution=False);save(O/'result.json',st);save(S,st)
if __name__=='__main__':
 try:main()
 except Exception as e:
  st=read(S)
  if st.get('pid')==os.getpid():st.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(S,st)
  raise
