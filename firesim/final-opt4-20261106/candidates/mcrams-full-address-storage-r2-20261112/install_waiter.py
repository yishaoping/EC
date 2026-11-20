#!/usr/bin/python3
"""Detached exact RTL resource waiter; no FPGA/CAD and no reduced budgets."""
import argparse,datetime,fcntl,hashlib,json,os,pathlib,subprocess,time
P=pathlib.Path;C=P(__file__).resolve().parent;W=C.parent.parent
D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');U=D/'unattended-opt4'
NAME='full-address-mcrams-rtl-r2-8491167d';UNIT='ec-opt4-full-address-rtl-r2-resource-waiter.service'
S=D/'Opt4-mcrams-full-address-rtl-r2-resource-waiter-state.json';LOG=D/'mcrams-full-address-rtl-r2-resource-waiter.log'
PINNED_INSTALLER='ff2f97c908ab9dd837e003ec7cac21570b732b26dabc416b42955b24bafc91be'
PINNED_REQUEST='106762be2089f7c07245afc2de83faea817ea933cb529b8ce0cb04a7116d0f1a'
def sha(p):return hashlib.sha256(P(p).read_bytes()).hexdigest()
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def read(p):return json.loads(P(p).read_text()) if P(p).exists() else {}
def save(p,j):
 p=P(p);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with q.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.chown(q,1008,1008);os.replace(q,p);fd=os.open(p.parent,os.O_RDONLY|os.O_DIRECTORY);os.fsync(fd);os.close(fd)
def ident(pid=None):
 pid=pid or os.getpid()
 try:a=P(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split();return dict(pid=pid,start_ticks=a[19],host_boot_id=P('/proc/sys/kernel/random/boot_id').read_text().strip(),process_state=a[0])
 except FileNotFoundError:return {}
def live(s):
 a=ident(s['pid']) if s.get('pid') else {}
 return bool(a and a['process_state'] not in ['Z','X'] and all(str(a[k])==str(s.get(k)) for k in ['pid','start_ticks','host_boot_id']))
def verify():
 assert sha(C/'install_local_rtl.py')==PINNED_INSTALLER
 assert sha(C/'request.json')==PINNED_REQUEST
 req=read(C/'request.json');assert req['spec']['kind']=='rtl' and req['spec']['name']==NAME
 for p,h in req['spec']['inputs'].items():assert sha(p)==h,p
def unit_text():
 return f'''[Unit]
Description=Wait actual resources for exact2core24GiB complete address RTL preparation
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User=root
WorkingDirectory={C}
ExecStart=/usr/bin/python3 {C/'install_waiter.py'} --follow
Restart=on-failure
RestartSec=300
KillMode=process
StandardOutput=append:{LOG}
StandardError=append:{LOG}
[Install]
WantedBy=multi-user.target
'''
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--follow',action='store_true');ap.add_argument('--validate-only',action='store_true');a=ap.parse_args();verify()
 if a.validate_only:print('PASS_PINNED_FULL_ADDRESS_RESOURCE_WAITER_NO_TASK_START');return
 assert os.geteuid()==0
 if not a.follow:
  p=P('/etc/systemd/system')/UNIT
  if p.exists():assert p.read_text()==unit_text()
  else:p.write_text(unit_text())
  subprocess.run(['systemctl','daemon-reload'],check=True);subprocess.run(['systemctl','enable','--now',UNIT],check=True);return
 lock=(D/'locks/full-address-rtl-r2-resource-waiter.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 st=dict(schema='ec-exact-small-RTL-resource-waiter/1',**ident(),started_utc=now(),installer_sha256=PINNED_INSTALLER,request_sha256=PINNED_REQUEST,fpga_access=False,no_CAD=True,poll_seconds=300)
 while True:
  verify();job=read(U/'jobs'/NAME/'state.json');receipt=read(U/'request-results'/(NAME+'.json'))
  if live(job) or live(job.get('child',{})) or job.get('status')=='COMPLETE':
   st.update(status='ADOPTED_EXISTING_EXACT_JOB_NO_DUPLICATE',job=job,ended_utc=now());save(S,st);return
  if job or receipt.get('status') not in [None,'DEFERRED']:
   st.update(status='EXISTING_EXIT_OR_ADMISSION_EVIDENCE_PRESERVED_NO_BLIND_RESTART',job=job,receipt=receipt,ended_utc=now());save(S,st);return
  mem=int(next(l.split()[1] for l in P('/proc/meminfo').read_text().splitlines() if l.startswith('MemAvailable:')));load=float(P('/proc/loadavg').read_text().split()[0]);disk=os.statvfs(D);free=disk.f_bavail*disk.f_frsize
  st.update(status='WAITING_REAL_256GIB_MEMORY_150GIB_DISK_LOAD48_GATE',memory_kib=mem,disk_bytes=free,load1=load,updated_utc=now());save(S,st)
  if mem>=256*2**20 and free>=150*2**30 and load<48:
   p=subprocess.run(['/usr/bin/python3',str(C/'install_local_rtl.py')],stdin=subprocess.DEVNULL,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
   with LOG.open('a') as f:f.write(now()+' INSTALL_RETURN '+str(p.returncode)+'\n'+p.stdout+'\n');f.flush();os.fsync(f.fileno())
   st.update(last_installer_returncode=p.returncode,last_installer_output=p.stdout[-5000:],updated_utc=now());save(S,st)
   if p.returncode==0:
    st.update(status='EXACT_PINNED_JOB_START_OR_ADOPTION_COMPLETED',ended_utc=now());save(S,st);return
   # Resource/affinity race remains a wait; other failures preserve exact
   # evidence and retry verify without touching existing jobs or live inputs.
  time.sleep(300)
if __name__=='__main__':main()
