#!/usr/bin/python3
from pathlib import Path
import datetime,fcntl,hashlib,json,os
C=Path(__file__).resolve().parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U=D/'unattended-opt4';O=D/'cycleprecise-original-svb-gg-stream-replay-r2-20261111'
OBS=D/'cycleprecise-frozen-full-gg-external-observer-r5-20261111'
REPLAY=D/'cycleprecise-original-svb-binary-replay-r1-20261111'
STATUS=D/'Opt4-original-svb-gg-stream-replay-r2-dispatch-state.json'
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
def state(status,**v):save(STATUS,dict(status=status,fpga_access=False,updated_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),**v))
def main():
 lock=(C/'dispatch.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 name='full-svb-gg-stream-replay-r2-full-8491167d';dest=U/'requests'/(name+'.json')
 if dest.exists():state('ALREADY_SUBMITTED_ADOPT_EXISTING',request=str(dest),request_sha256=sha(dest));return
 if not (O/'result.json').exists():state('WAITING_STREAMING_DRIVER_PREPARATION');return
 assert read(O/'result.json')['passed'],'PREPARATION_FAILED_REQUIRES_EVIDENCE_BASED_REPAIR'
 if not (OBS/'full-result.json').exists():state('WAITING_COMPLETE_REAL_APPLICATION_TRACE');return
 observed=read(OBS/'full-result.json')
 assert observed['valid_finite_observation'] and observed['full_original_generated_svb_ports_saved']
 assert observed['binary_integrity']['counts']['capture_accepted']>0 and observed['binary_integrity']['counts']['promote_accepted']>0
 if not (REPLAY/'full-result.json').exists():state('WAITING_ORIGINAL_TARGET_APPLICATION_REPLAY');return
 assert read(REPLAY/'full-result.json')['passed'],'ORIGINAL_TARGET_REPLAY_FAILED_NO_ADMISSION'
 build=read(O/'build-receipt.json');assert sha(C/'plan.json')==build['plan_sha256']
 for f,h in build['binaries'].items():assert sha(f)==h,('BINARY_CHANGED',f)
 bound={str(p):sha(p) for p in [C/'run.py',C/'prepare.py',C/'StreamingReplay.cc',C/'plan.json',C/'binary-layout.json',C/'directed-original-svb.bin',C/'VSVBStreamingReplay',C/'SVBStreamingReplay-xilinx_alveo_u280',C/'dispatch.py']}
 capsule=C/'dispatch-evidence';capsule.mkdir(exist_ok=True)
 for src in [O/'result.json',O/'build-receipt.json',OBS/'full-result.json',REPLAY/'full-result.json']:
  h=sha(src);target=capsule/(h[:16]+'-'+src.parent.name+'-'+src.name)
  if not target.exists():
   with target.open('xb') as f:f.write(src.read_bytes());f.flush();os.fsync(f.fileno())
  assert sha(target)==h;bound[str(target)]=h
 request=dict(action='cpu_job',spec=dict(name=name,kind='analysis',cwd=str(C),argv=['/usr/bin/python3',str(C/'run.py'),'--full'],inputs=bound,outputs=[str(O/'full-result.json'),str(O/'board-admission-ready.json')],checkpoints=[str(D/'Opt4-original-svb-gg-stream-replay-r2-state.json')]))
 temp=dest.with_name(dest.name+'.preparing-'+str(os.getpid()))
 with temp.open('x') as f:json.dump(request,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 try:os.link(temp,dest)
 finally:temp.unlink()
 state('SUBMITTED_ONE_CPU_GG_APPLICATION_REPLAY',request=str(dest),request_sha256=sha(dest))
if __name__=='__main__':
 try:main()
 except BaseException as e:state('DISPATCH_REJECTED_WITH_EVIDENCE',error=repr(e));raise
