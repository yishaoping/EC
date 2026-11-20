#!/usr/bin/env python3
"""One-time 21-only bootstrap and boundary reload, preserving the live e2 guest."""
from pathlib import Path
import datetime,fcntl,json,os,select,subprocess,sys
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');sys.path.insert(0,str(W/'scripts'))
from board_batch import D,save,sha
from job_service import proc
O=D/'safety/21-only-20261109';BOOT=Path('/proc/sys/kernel/random/boot_id').read_text().strip()
lock=(O/'transition.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
S={'schema':'ec-target21-transition/1','pid':os.getpid(),'start_ticks':proc(os.getpid())['start_ticks'],
   'host_boot_id':BOOT,'started_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),
   'protected_e2_untouched':True,'hardware_target':'0000:21:00.0','commands':[]}
def checkpoint(stage,**kw):
 S.update(stage=stage,updated_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),**kw);save(O/'transition-state.json',S);print(json.dumps({'stage':stage,**kw}),flush=True)
def read(p):return json.loads(p.read_text()) if p.exists() else {}
def run(label,argv):
 checkpoint(label)
 with (O/(label+'.log')).open('ab',buffering=0) as stream:
  stream.write((json.dumps({'argv':list(map(str,argv))})+'\n').encode())
  child=subprocess.Popen(list(map(str,argv)),cwd=W,stdin=subprocess.DEVNULL,stdout=stream,stderr=subprocess.STDOUT,start_new_session=True)
  checkpoint(label,child_pid=child.pid,child_start_ticks=proc(child.pid)['start_ticks'])
  rc=child.wait()
 S.pop('child_pid',None);S.pop('child_start_ticks',None);S['commands'].append({'label':label,'returncode':rc,'log':str(O/(label+'.log'))})
 checkpoint(label+'-ended',returncode=rc)
 if rc:raise RuntimeError(label+' failed; inspect persistent log')
def group_processes(name):
 unit='ec-parsec-'+name+'.service'
 cg=subprocess.check_output(['systemctl','show',unit,'-p','ControlGroup','--value'],text=True).strip()
 for base in ['/sys/fs/cgroup/systemd','/sys/fs/cgroup']:
  p=Path(base)/cg.lstrip('/')/'cgroup.procs'
  if p.exists():return [r for pid in p.read_text().split() if (r:=proc(int(pid)))]
 raise RuntimeError('cannot inspect service cgroup: '+name)
def restart_without_guests(name):
 rows=group_processes(name)
 if any('FireSim-' in r['cmdline'] or 'run_isolated_sample.py' in r['cmdline'] or 'board_batch.py' in r['cmdline'] or 'vivado' in r['cmdline'] or 'hw_server' in r['cmdline'] for r in rows):
  raise RuntimeError('service still has a live guest/deployment/server: '+name)
 save(O/('restart-'+name+'-precheck.json'),{'boot_id':BOOT,'processes':rows})
 subprocess.run(['systemctl','restart','ec-parsec-'+name+'.service'],check=True)
def protected():
 p=Path('/sys/bus/pci/devices/0000:e2:00.0')
 nodes={str(x):{'inode':x.stat().st_ino,'rdev':x.stat().st_rdev} for x in Path('/dev').glob('xdma1_*')}
 return {'endpoint':str(p.resolve()),'driver':str((p/'driver').resolve()),
         'endpoint_inode':p.stat().st_ino,'resource0_inode':(p/'resource0').stat().st_ino,
         'xdma_module_inode':Path('/sys/module/xdma').stat().st_ino,'device_nodes':nodes}
try:
 checkpoint('AUDITED_START')
 # The C4 waiters own no guest or CAD worker; reload only those idle services.
 for name in ['c4-first','c4-suite']:restart_without_guests(name)
 before=protected();save(O/'protected-e2-before.json',before)
 existing=read(D/'latest-deployment.json')
 cards=[c for c in existing.get('completed_cards',[]) if c.get('bdf')=='0000:21:00.0' and c.get('configuration')=='Native']
 if existing.get('host_boot_id')!=BOOT or not cards:
  run('native21-deploy',['python3',W/'scripts/infrasetup.py','Native'])
 after=protected();save(O/'protected-e2-after-deploy.json',after)
 if before!=after:raise RuntimeError('protected e2 PCI/device/module identity changed; stop 21 progression and inspect')
 import coverage_first as coverage
 valid=coverage.results()
 native_row=next(r for r in coverage.catalog() if r['configuration']=='Native' and r['status']=='READY')
 if not coverage.smoke_valid(native_row,valid):
  run('native21-smoke',['python3',W/'scripts/run_isolated_sample.py','Native','smoke','test','--bdf','0000:21:00.0',
      '--driver-receipt',W/'runtime/Native-efficiency-driver.json','--firmware-receipt',W/'software/Native/reboot-firmware-build.json',
      '--apps-receipt',W/'software/formal-apps-build.json','--rootfs-receipt',W/'software/formal-rootfs-build.json','--timeout','600'])
 # Preserve the original e2 sample, including its runner's result commit.
 saved=read(O/'root-preflight.json')['protected_processes']
 fds=[]
 for key in ['13544','13546']:
  expected=saved[key];p=proc(int(key))
  if p and p['start_ticks']==expected['start_ticks'] and p['process_state'] not in ['Z','X']:
   fds.append(os.pidfd_open(int(key)))
 checkpoint('NATIVE21_SMOKE_PASSED_WAITING_PROTECTED_E2_SAMPLE_BOUNDARY',waiting_pidfds=len(fds))
 while fds:
  ready,_,_=select.select(fds,[],[],300)
  for fd in ready:os.close(fd);fds.remove(fd)
  checkpoint('NATIVE21_SMOKE_PASSED_WAITING_PROTECTED_E2_SAMPLE_BOUNDARY',waiting_pidfds=len(fds))
 # All future launches have already been restricted by the current runner CLI.
 # Only restart the old coordinator after its e2 runner and driver have exited.
 restart_without_guests('coverage-first')
 checkpoint('COMPLETE_EXISTING_COVERAGE_SERVICE_RELOADED_FOR21',status='COMPLETE')
except Exception as exc:
 checkpoint('FAILED_WITH_EVIDENCE',status='FAILED_WITH_EVIDENCE',error=repr(exc));raise
