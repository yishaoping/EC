#!/usr/bin/python3
"""Exact existing broker job installation with bounded local resource evidence.
No generic guard changes, different job name, privilege in the child, or FPGA.
"""
from pathlib import Path
import datetime,fcntl,hashlib,json,os,subprocess,sys
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');U=D/'unattended-opt4'
C=Path(__file__).resolve().parent
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import bound_inputs,read,save,sha,identity,live,UID,GID
def main():
 assert os.geteuid()==0,'ROOT_INSTALLER_ONLY_CHILD_UNPRIVILEGED'
 request=read(C/'request.json');spec=request['spec'];name=spec['name'];assert request['action']=='cpu_job' and spec['kind']=='analysis'
 assert name=='matched-single-boom-gg-r3-8491167d'
 installlock=(C/'local-install.lock').open('a');fcntl.flock(installlock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 assert read(U/'requests'/(name+'.json'))==request,'EXACT_REQUEST_MATCH'
 hashes=bound_inputs(spec);plan=read(C/'plan.json')
 preflight=read(C/'preflight.json')
 assert preflight['status']=='PASS_MAKE_DRYRUN_ORIGINAL_NATIVE_COLLECTOR_ALL_VARIABLES' and preflight['returncode']==0
 assert preflight['plan_sha256']==sha(C/'plan.json') and preflight['dryrun_sha256']==sha(C/'make-dryrun.log')
 assert plan['cpu_affinity']==list(range(208,216)) and plan['max_address_space_gib']==64 and plan['max_cpus']==8
 policy=read(U/'campaign-policy.json');assert policy['native_paused'] and not policy['fpga_access'] and policy['board_allowlist']==['0000:21:00.0']
 oldname='matched-single-boom-gg-r2-8491167d';old=read(U/'jobs'/oldname/'state.json')
 assert old['status']=='FAILED_WITH_EVIDENCE' and old['returncode']==1
 assert not live(old) and not live(old.get('child',{}))
 oldunit='ec-opt4-auto-'+oldname+'.service'
 oldgroup=subprocess.check_output(['systemctl','show',oldunit,'--property=ControlGroup','--value'],text=True).strip()
 oldactive=subprocess.check_output(['systemctl','show',oldunit,'--property=ActiveState','--value'],text=True).strip()
 assert oldactive in ['inactive','failed'],('OLD_SERVICE_STILL_ACTIVE',oldactive)
 # This host uses cgroup v1: systemd's hierarchy is below the systemd
 # controller mount, not /sys/fs/cgroup/<ControlGroup>.
 cgroot=Path('/sys/fs/cgroup/systemd');assert cgroot.is_dir(),'CGROUP_V1_SYSTEMD_ROOT_REQUIRED'
 explicit=cgroot/'system.slice'/oldunit
 oldpaths={explicit}
 if oldgroup:
  assert oldgroup.startswith('/system.slice/'),'UNEXPECTED_OLD_CGROUP_PATH'
  oldpaths.add(cgroot/oldgroup.lstrip('/'))
 cgevidence=[]
 for oldpath in sorted(oldpaths):
  if oldpath.exists():
   procs=list(oldpath.rglob('cgroup.procs'))
   assert oldpath/'cgroup.procs' in procs,('CGROUP_PROCS_MISSING',str(oldpath))
   for f in procs:
    assert f.is_file() and os.access(f,os.R_OK),('CGROUP_PROCS_UNREADABLE',str(f))
    assert not f.read_text().strip(),('OLD_CGROUP_NOT_EMPTY',str(f))
   cgevidence.append(dict(path=str(oldpath),exists=True,readable_empty_procs=[str(f) for f in procs]))
  else:cgevidence.append(dict(path=str(oldpath),exists=False))
 peers=[]
 for p in (U/'jobs').glob('*/state.json'):
  row=read(p)
  if live(row) or live(row.get('child',{})):
   # Test known nested controller children; broad scheduler affinity does
   # not claim exclusive ownership, while pinned active workers do.
   ids=[]
   for x in [row,row.get('child',{})]:
    if live(x):ids.append(x['pid'])
   if row.get('checkpoints'):
    for q in row['checkpoints']:
     cp=read(q)
     for x in [cp,cp.get('child',{})]:
      if live(x):ids.append(x['pid'])
   for pid in set(ids):
    try:aff=sorted(os.sched_getaffinity(pid))
    except ProcessLookupError:continue
    if len(aff)<=32:assert not set(aff).intersection(plan['cpu_affinity']),('KNOWN_PINNED_PEER_OVERLAP',p.parent.name,pid,aff)
    peers.append(dict(job=p.parent.name,pid=pid,cpu_affinity=aff if len(aff)<=32 else 'broad scheduler affinity'))
 mem=int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:')))/2**20
 load=float(Path('/proc/loadavg').read_text().split()[0]);disk=os.statvfs(W);free=disk.f_bavail*disk.f_frsize/2**30
 assert mem>=256 and load<48 and free>=150,('LOCAL_RESOURCE_BUDGET',mem,load,free)
 out=U/'jobs'/name;out.mkdir(exist_ok=True);os.chown(out,UID,GID)
 state=read(out/'state.json');assert not live(state) and not live(state.get('child',{}))
 assert state.get('status')!='COMPLETE' and not (D/'cycleprecise-matched-single-boom-gg-r3-20261112/result.json').exists()
 specpath=out/'spec.json'
 if specpath.exists():assert read(specpath)==spec
 else:save(specpath,spec)
 unit='ec-opt4-auto-'+name+'.service'
 text=f'''[Unit]
Description=Opt4 autonomous CPU job {name}
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User=guozh
Group=guozh
WorkingDirectory={C}
ExecStart=/usr/bin/python3 {W}/scripts/opt4_unattended_cpu_job.py {specpath}
Nice=10
TasksMax=1024
CPUQuota=3200%
Restart=no
KillMode=process
StandardOutput=append:{out}/service.log
StandardError=append:{out}/service.log
[Install]
WantedBy=multi-user.target
'''
 up=Path('/etc/systemd/system')/unit
 if up.exists():assert up.read_text()==text,'EXACT_BROKER_UNIT_REQUIRED'
 else:up.write_text(text)
 request_receipt=U/'request-results'/(name+'.json')
 prior_receipt=read(request_receipt)
 prior_path=C/'prior-broker-receipt.json';assert not prior_path.exists();save(prior_path,prior_receipt)
 assert not prior_receipt or prior_receipt.get('status')=='DEFERRED',('REQUEST_ALREADY_HANDLED',prior_receipt)
 # Persist the claim before enabling the exact broker unit. The supervisor
 # skips every non-DEFERRED receipt, including failed local launches, so it
 # cannot later repeat this immutable version after a natural task failure.
 save(request_receipt,dict(status='CLAIMED_EXACT_LOCAL_CPU_INSTALL_NO_AUTORETRY',unit=unit,
   request_sha256=sha(C/'request.json'),spec_sha256=sha(specpath),installer_sha256=sha(__file__),
   prior_receipt=str(prior_path),utc=datetime.datetime.now(datetime.timezone.utc).isoformat()))
 subprocess.run(['systemctl','daemon-reload'],check=True)
 try:subprocess.run(['systemctl','enable','--now',unit],check=True,capture_output=True)
 except Exception as error:
  save(request_receipt,dict(status='FAILED_LOCAL_INSTALL_WITHOUT_RETRY',unit=unit,error=repr(error),
    request_sha256=sha(C/'request.json'),utc=datetime.datetime.now(datetime.timezone.utc).isoformat()))
  raise
 save(request_receipt,dict(status='STARTED',unit=unit,spec_sha256=sha(specpath),
   request_sha256=sha(C/'request.json'),local_budget_receipt=str(C/'local-launch-receipt.json'),
   prior_receipt=str(prior_path),utc=datetime.datetime.now(datetime.timezone.utc).isoformat()))
 receipt=dict(status='STARTED_EXACT_BROKER_UNIT_WITH_LOCAL_CPU_BUDGET',unit=unit,spec_sha256=sha(specpath),
    request_sha256=sha(C/'request.json'),installer_sha256=sha(__file__),verified_input_count=len(hashes),
    preflight_sha256=sha(C/'preflight.json'),request_result=str(request_receipt),prior_broker_receipt_sha256=sha(prior_path),old_unit=oldunit,old_state=oldactive,old_cgroup_checks=cgevidence,memory_available_gib=mem,load1=load,free_disk_gib=free,
    cpu_affinity=plan['cpu_affinity'],peers_checked=peers,fpga_access=False,utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
 target=C/'local-launch-receipt.json';assert not target.exists();save(target,receipt)
 print(json.dumps({k:v for k,v in receipt.items() if k!='peers_checked'},indent=2))
if __name__=='__main__':main()
