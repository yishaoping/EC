#!/usr/bin/python3
"""One finite dispatch check; a system timer calls it after SSH disconnects."""
from pathlib import Path
import datetime
import fcntl
import hashlib
import json
import os

W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C=Path(__file__).resolve().parent
U=D/'unattended-opt4'
OUT=D/'cycleprecise-frozen-full-gg-external-observer-r5-20261111'
STATUS=D/'Opt4-full-gg-external-observer-r5-dispatch-state.json'
NAME='full-gg-external-observer-r5-full-8491167d'
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
def read(p):return json.loads(Path(p).read_text())
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for b in iter(lambda:f.read(4*2**20),b''):h.update(b)
 return h.hexdigest()
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def save(p,value):
 p=Path(p);tmp=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with tmp.open('x') as f:json.dump(value,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(tmp,p)
 fd=os.open(p.parent,os.O_RDONLY|os.O_DIRECTORY);os.fsync(fd);os.close(fd)
def finish(status,**v):
 save(STATUS,dict(schema='ec-gg-external-observer-r5-dispatch/1',status=status,updated_utc=now(),fpga_access=False,**v))
def main():
 lock=(C/'dispatch.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 policy=read(U/'campaign-policy.json')
 assert policy['functional_baseline_commit']==BASE and policy['area_equivalence_only']
 assert not policy['functional_extensions_allowed'] and policy['native_paused'] and not policy['fpga_access']
 assert policy['board_allowlist']==['0000:21:00.0']
 request_path=U/'requests'/f'{NAME}.json'
 if request_path.exists():
  finish('ALREADY_SUBMITTED_ADOPT_EXISTING',request=str(request_path),request_sha256=sha(request_path));return
 predecessor=D/'cycleprecise-frozen-full-gg-external-observer-r3-20261111/result.json'
 if not predecessor.exists():finish('WAITING_PREDECESSOR_COMPLETION',predecessor=str(predecessor));return
 prior=read(predecessor)
 assert prior.get('valid_finite_observation') and prior['functional_baseline']==BASE,'PREDECESSOR_FAILED_NO_ADMISSION'
 assert prior['original_prints_and_application_and_target_count_match'],'PREDECESSOR_PARITY_MISSING'
 assert prior['observer_summary']['sample_errors']==0,'PREDECESSOR_SAMPLING_NOT_VALID'
 gate=OUT/'probe-result.json'
 if not gate.exists():finish('WAITING_R5_STARTUP_PROBE',probe=str(gate));return
 probe=read(gate);assert probe['passed'],'R5_PROBE_FAILED_NO_ADMISSION'
 assert probe['observer_on']['observer_summary']['sample_errors']==0
 plan=read(C/'plan.json')
 for p,h in plan['external_inputs'].items():assert sha(p)==h,('CHANGED_MODEL_INPUT',p)
 job=read(U/'jobs/full-gg-external-observer-r5-8491167d/spec.json')
 for p,h in job['inputs'].items():assert sha(p)==h,('CHANGED_PREPARE_INPUT',p)
 receipt=read(OUT/'build-receipt.json')
 assert sha(plan['binary'])==receipt['binary_sha256'],'OBSERVED_BINARY_CHANGED'
 assert not (OUT/'canneal-observer-on').exists(),'ADOPT_EXISTING_FULL_RUN_NOT_DUPLICATE'
 # Only use already-existing broker. All executable/new validation files and
 # immutable predecessor/probe receipts are hash bound to this single request.
 bound=dict(job['inputs'])
 for name in ['dispatch.py','validate_binary.py','analyze_acceptance.py','analyze_svb_latency.py','run_full.py','binary-layout.json',Path(plan['binary']).name]:
  p=C/name;bound[str(p)]=sha(p)
 # Evidence snapshots are small immutable copies under the allowed input root.
 capsule=C/'dispatch-evidence';capsule.mkdir(exist_ok=True)
 originals={}
 for source in [predecessor,gate,OUT/'build-receipt.json']:
  digest=sha(source);target=capsule/(digest[:16]+'-'+source.name)
  if not target.exists():
   with target.open('xb') as f:f.write(source.read_bytes());f.flush();os.fsync(f.fileno())
  assert sha(target)==digest
  bound[str(target)]=digest;originals[str(source)]=digest
 req=dict(action='cpu_job',spec=dict(name=NAME,kind='analysis',cwd=str(C),
  argv=['/usr/bin/python3',str(C/'run_full.py')],inputs=bound,
  outputs=[str(OUT/'full-result.json')],checkpoints=[str(D/'Opt4-full-gg-external-observer-r5-state.json')]))
 # Publish a complete file using an exclusive hardlink. The broker can never
 # observe a half-written JSON request, even at the timer scheduling boundary.
 temp=request_path.with_name(request_path.name+'.preparing-'+str(os.getpid()))
 with temp.open('x') as f:json.dump(req,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 try:os.link(temp,request_path)
 finally:temp.unlink()
 finish('SUBMITTED_R5_FULL_AFTER_PREDECESSOR_PASS',request=str(request_path),request_sha256=sha(request_path),
  predecessor_evidence=originals,binary_sha256=receipt['binary_sha256'])
if __name__=='__main__':
 try:main()
 except BaseException as error:
  finish('DISPATCH_REJECTED_WITH_EVIDENCE',error=repr(error));raise
