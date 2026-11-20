#!/usr/bin/python3
"""One exact small-module admission; no change to general broker guards."""
import argparse,fcntl,hashlib,json,os,pathlib,shutil,subprocess,sys
C=pathlib.Path(__file__).resolve().parent;W=C.parent.parent
D=pathlib.Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');U=D/'unattended-opt4'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import bound_inputs,live,read,save,sha,now,UID,GID
NAME='address-bucket-mcrams-area-r2-8491167d';UNIT='ec-opt4-auto-'+NAME+'.service'
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--validate-only',action='store_true');a=ap.parse_args()
 req=read(C/'request.json');spec=req['spec'];assert req['action']=='cpu_job' and spec['name']==NAME and spec['kind']=='module'
 assert spec['argv']==['/usr/bin/python3',str(C/'controller.py')];assert spec['cwd']==str(C);bound_inputs(spec)
 assert read(C/'preflight-result.json')['status']=='PASS_ACTUAL_ZERO_NONZERO_REPORT_AND_MUTATION_PREFLIGHT'
 assert set([220,221])<=os.sched_getaffinity(0)
 if a.validate_only:print('PASS_EXACT_SMALL_MODULE_INPUTS_PREFLIGHT_CPU220_221_24G_NO_FPGA');return
 assert os.geteuid()==0
 lock=(D/'locks/address-bucket-area-r2-local-installer.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 mem=int(next(x.split()[1] for x in pathlib.Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:')))
 assert mem>=256*2**20 and shutil.disk_usage(D).free>=40*2**30,'small module resource margin'
 out=U/'jobs'/NAME;out.mkdir(exist_ok=True);os.chown(out,UID,GID);sp=out/'spec.json'
 if sp.exists():assert read(sp)==spec
 state=read(out/'state.json')
 if live(state) or live(state.get('child',{})):print('ADOPT_EXISTING_R2');return
 oldname='address-bucket-mcrams-area-r1-8491167d';oldstate=read(U/'jobs'/oldname/'state.json')
 assert not live(oldstate) and not live(oldstate.get('child',{})),'existing r1 task must be adopted'
 oldunit='ec-opt4-auto-'+oldname+'.service';active=subprocess.run(['systemctl','is-active','--quiet',oldunit]).returncode==0;assert not active
 pending=U/'request-results'/(oldname+'.json');old=read(pending)
 assert old.get('status') in ['DEFERRED','REPLACED_BY_VERSIONED_R2_LOCAL_MODULE_ADMISSION'],old
 if old['status']=='DEFERRED':
  save(C/'r1-deferred-before-supersession.json',old)
  save(pending,dict(status='REPLACED_BY_VERSIONED_R2_LOCAL_MODULE_ADMISSION',replacement=NAME,prior_receipt=str(C/'r1-deferred-before-supersession.json'),original_request_preserved=True,utc=now()))
 save(sp,spec);save(U/'requests'/(NAME+'.json'),req)
 text=f'''[Unit]
Description=Opt4 autonomous CPU job {NAME}
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User=guozh
Group=guozh
WorkingDirectory={C}
ExecStart=/usr/bin/python3 {W}/scripts/opt4_unattended_cpu_job.py {sp}
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
 up=pathlib.Path('/etc/systemd/system')/UNIT
 if up.exists():assert up.read_text()==text
 else:up.write_text(text)
 subprocess.run(['systemctl','daemon-reload'],check=True);subprocess.run(['systemctl','enable','--now',UNIT],check=True)
 receipt=dict(status='STARTED_EXACT_LOCAL_SMALL_MODULE_UNIT_GENERAL_BROKER_UNCHANGED',unit=UNIT,spec_sha256=sha(sp),available_memory_kib=mem,free_disk_bytes=shutil.disk_usage(D).free,cpus=[220,221],memory_limit_gib=24,no_large_CAD=True,fpga_access=False,utc=now())
 save(U/'request-results'/(NAME+'.json'),dict(status='STARTED',request_sha256=sha(U/'requests'/(NAME+'.json')),local_admission=receipt,utc=now()));save(C/'installation-receipt.json',receipt);print(json.dumps(receipt))
if __name__=='__main__':main()
