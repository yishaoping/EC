#!/usr/bin/python3
"""Finite check for one independent CPU replay after full trace completion."""
from pathlib import Path
import fcntl,hashlib,json,os,datetime
C=Path(__file__).resolve().parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U=D/'unattended-opt4';O=D/'cycleprecise-original-svb-binary-replay-r1-20261111'
OBS=D/'cycleprecise-frozen-full-gg-external-observer-r5-20261111'
STATUS=D/'Opt4-original-svb-binary-replay-r1-dispatch-state.json'
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for b in iter(lambda:f.read(4*2**20),b''):h.update(b)
 return h.hexdigest()
def read(p):return json.loads(Path(p).read_text())
def save(p,v):
 tmp=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with tmp.open('x') as f:json.dump(v,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(tmp,p)
def state(status,**v):save(STATUS,dict(status=status,updated_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),fpga_access=False,**v))
def main():
 lock=(C/'dispatch.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 name='full-svb-binary-replay-r1-full-8491167d';dest=U/'requests'/f'{name}.json'
 if dest.exists():state('ALREADY_SUBMITTED_ADOPT_EXISTING',request=str(dest),request_sha256=sha(dest));return
 policy=read(U/'campaign-policy.json')
 assert policy['functional_baseline_commit']=='8491167d84b6d9521b151a743673c1516926a1f8'
 assert policy['area_equivalence_only'] and policy['native_paused'] and not policy['fpga_access']
 if not (O/'result.json').exists():state('WAITING_REPLAY_STARTUP_PREPARATION');return
 assert read(O/'result.json')['passed'],'STARTUP_REPLAY_FAILED_NO_ADMISSION'
 if not (OBS/'full-result.json').exists():state('WAITING_COMPLETE_ORIGINAL_SVB_PORT_TRACE');return
 full=read(OBS/'full-result.json')
 assert full['valid_finite_observation'] and full['full_original_generated_svb_ports_saved'],'FULL_OBSERVER_NOT_VALIDATED'
 assert full['binary_integrity']['counts']['capture_accepted']>0,'NO_REAL_APPLICATION_SVB_CAPTURE'
 assert full['binary_integrity']['counts']['promote_accepted']>0,'NO_REAL_APPLICATION_SVB_PROMOTION'
 # Preparation was admitted by the direct persistent service, not a broker job.
 # Bind its successful immutable receipt and exact local executable sources.
 plan=read(C/'plan.json');build=read(O/'build-receipt.json')
 assert sha(C/'replay')==build['binary_sha256'],'CHANGED_PREPARED_REPLAY_BINARY'
 assert sha(C/'replay.cpp')==plan['replay_source_sha256'],'CHANGED_REPLAY_SOURCE'
 assert sha(C/'binary-layout.json')==plan['layout_sha256'],'CHANGED_REPLAY_LAYOUT'
 bound={str(p):sha(p) for p in [C/'run.py',C/'prepare.py',C/'plan.json',C/'binary-layout.json',C/'dispatch.py',C/'replay.cpp',C/'replay',C.with_name('full-gg-external-observer-r5-20261111')/'validate_binary.py',C.with_name('full-gg-external-observer-r5-20261111')/'controller.py']}
 capsule=C/'dispatch-evidence';capsule.mkdir(exist_ok=True)
 for src in [O/'result.json',O/'build-receipt.json',OBS/'full-result.json',OBS/'binary-integrity.json']:
  h=sha(src);target=capsule/(h[:16]+'-'+src.name)
  if not target.exists():
   with target.open('xb') as f:f.write(src.read_bytes());f.flush();os.fsync(f.fileno())
  assert sha(target)==h;bound[str(target)]=h
 request=dict(action='cpu_job',spec=dict(name=name,kind='analysis',cwd=str(C),
  argv=['/usr/bin/python3',str(C/'run.py'),'--full'],inputs=bound,
  outputs=[str(O/'full-result.json')],checkpoints=[str(D/'Opt4-original-svb-binary-replay-r1-state.json')]))
 temp=dest.with_name(dest.name+'.preparing-'+str(os.getpid()))
 with temp.open('x') as f:json.dump(request,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 try:os.link(temp,dest)
 finally:temp.unlink()
 state('SUBMITTED_ONE_FULL_ORIGINAL_TARGET_SVB_REPLAY',request=str(dest),request_sha256=sha(dest))
if __name__=='__main__':
 try:main()
 except BaseException as e:state('DISPATCH_REJECTED_WITH_EVIDENCE',error=repr(e));raise
