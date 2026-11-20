#!/usr/bin/python3
"""Start the verified queued small entry map within explicit spare resources."""
from pathlib import Path
import fcntl,json,os,shutil,subprocess,sys
C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U=D/'unattended-opt4'
L=D/'build-logs/Opt4-mcrams-dcache-entry-area-r2-20261111'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import bound_inputs,read,live,save,sha,now


def main():
 assert os.geteuid()==0
 request=U/'requests/mcrams-dcache-entry-area-r2-8491167d.json'
 withdrawn=U/'withdrawn-requests/mcrams-dcache-entry-area-r2-8491167d.direct-bounded.json'
 r=read(request if request.exists() else withdrawn);spec=r['spec']
 assert spec['argv']==['/usr/bin/python3',str(C/'controller.py'),'--run']
 assert spec['kind']=='module';bound_inputs(spec)
 assert not live(read(D/'Opt4-mcrams-dcache-entry-area-r2-state.json'))
 prior=read(U/'jobs'/spec['name']/'state.json')
 assert not live(prior) and not live(prior.get('child',{}))
 memory=int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:')))
 load=float(Path('/proc/loadavg').read_text().split()[0])
 assert memory>=256*2**20 and load<48 and shutil.disk_usage(W).free>=150*2**30
 assert {250,251}<=os.sched_getaffinity(0)
 L.mkdir(parents=True,exist_ok=True);os.chown(L,1008,1008)
 lock=(L/'installation.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 if request.exists():
  withdrawn.parent.mkdir(exist_ok=True);assert not withdrawn.exists();request.rename(withdrawn)
 else:assert withdrawn.exists()
 unit='ec-opt4-real-dcache-entry-area-r2.service'
 text=f'''[Unit]
Description=Verified DCache MCRams entry same-settings module area
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User=guozh
Group=guozh
WorkingDirectory={C}
ExecStart=/usr/bin/python3 {C}/controller.py --run
Environment=PYTHONPATH={W}/scripts
Nice=15
CPUQuota=200%
AllowedCPUs=250-251
MemoryMax=64G
TasksMax=256
Restart=no
KillMode=control-group
StandardOutput=append:{L}/direct-service.log
StandardError=append:{L}/direct-service.log
[Install]
WantedBy=multi-user.target
'''
 p=Path('/etc/systemd/system')/unit
 if p.exists():assert p.read_text()==text
 else:p.write_text(text)
 save(L/'direct-resource-admission.json',dict(utc=now(),unit=unit,unit_sha256=sha(p),
  input_hashes=bound_inputs(spec),withdrawn_duplicate_request=str(withdrawn),
  memory_available_gib=memory/2**20,load1=load,disk_free_gib=shutil.disk_usage(W).free/2**30,
  cpus=[250,251],memory_max_gib=64,CPUQuota='200%',whole_dut_synthesis=False,
  fpga_access=False,scope='Two small frozen storage-entry host designs, sequential identical OOC settings. Existing P0/CAD services preserved.'))
 subprocess.run(['systemctl','daemon-reload'],check=True)
 subprocess.run(['systemctl','enable','--now',unit],check=True,capture_output=True)
 subprocess.run(['systemctl','show',unit,'-p','MainPID','-p','ActiveState','-p','MemoryMax','-p','AllowedCPUs'],check=True)


if __name__=='__main__':main()
