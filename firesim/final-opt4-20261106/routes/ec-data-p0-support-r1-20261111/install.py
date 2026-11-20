#!/usr/bin/python3
"""Install bounded replay preparation and finite area-report polling only."""
from pathlib import Path
import json,os,shutil,subprocess,sys
HERE=Path(__file__).resolve().parent
W=HERE.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U=D/'unattended-opt4'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import bound_inputs,read,save,sha,live,now

def putunit(name,text):
 p=Path('/etc/systemd/system')/name
 if p.exists():assert p.read_text()==text
 else:p.write_text(text)

def main():
 assert os.geteuid()==0
 memory=int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:')))
 assert memory>=192*2**20 and float(Path('/proc/loadavg').read_text().split()[0])<48
 assert shutil.disk_usage(W).free>=100*2**30
 out=D/'ec-data-p0-support-r1-20261111';out.mkdir(exist_ok=True);os.chown(out,1008,1008)
 analyzer=W/'candidates/mcrams-dcache-entry-area-analysis-r1-20261111/analyze.py'
 # A finite 5-minute timer avoids occupying any expensive synthesis slot.
 service=f'''[Unit]
Description=Validate saved MCRams entry module resources from total tables
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=oneshot
User=guozh
Group=guozh
WorkingDirectory={analyzer.parent}
ExecStart=/usr/bin/python3 {analyzer}
TimeoutStartSec=120
CPUQuota=100%
MemoryMax=1G
Nice=15
StandardOutput=append:{out}/area-analysis.log
StandardError=append:{out}/area-analysis.log
'''
 timer='''[Unit]
Description=Check completed MCRams resource reports without rerunning synthesis
[Timer]
OnBootSec=60s
OnUnitInactiveSec=300s
AccuracySec=20s
Persistent=true
Unit=ec-opt4-mcrams-entry-area-analysis-r1.service
[Install]
WantedBy=timers.target
'''
 putunit('ec-opt4-mcrams-entry-area-analysis-r1.service',service)
 putunit('ec-opt4-mcrams-entry-area-analysis-r1.timer',timer)
 # This is one incremental main compile/link plus short replay, not another
 # simulator-model/CAD build. Withdraw the equivalent queued broker request.
 q=U/'requests/full-svb-binary-replay-r1-8491167d.json'
 withdrawn=U/'withdrawn-requests/full-svb-binary-replay-r1-8491167d.direct-bounded.json'
 req=read(q if q.exists() else withdrawn);spec=req['spec'];bound_inputs(spec)
 assert spec['name']=='full-svb-binary-replay-r1-8491167d'
 assert spec['argv']==['/usr/bin/python3',str(W/'candidates/full-svb-binary-replay-r1-20261111/run.py'),'--prepare']
 old=read(U/'jobs'/spec['name']/'state.json')
 assert not live(old) and not live(old.get('child',{})),'adopt existing replay preparation'
 if q.exists():
  withdrawn.parent.mkdir(exist_ok=True);assert not withdrawn.exists();q.rename(withdrawn)
 else:assert withdrawn.exists()
 specpath=out/'replay-prepare-spec.json'
 if specpath.exists():assert read(specpath)==spec
 else:save(specpath,spec)
 unit='ec-opt4-real-svb-binary-replay-prepare-r1.service'
 text=f'''[Unit]
Description=Prepare original frozen SVB replay using saved model objects
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User=guozh
Group=guozh
WorkingDirectory={spec['cwd']}
ExecStart=/usr/bin/python3 {W}/scripts/opt4_unattended_cpu_job.py {specpath}
Environment=PYTHONPATH={W}/scripts
Nice=15
CPUQuota=200%
AllowedCPUs=248-249
MemoryMax=24G
TasksMax=256
Restart=no
KillMode=control-group
StandardOutput=append:{out}/replay-prepare.log
StandardError=append:{out}/replay-prepare.log
[Install]
WantedBy=multi-user.target
'''
 putunit(unit,text)
 save(out/'installation.json',dict(utc=now(),analyzer=str(analyzer),analyzer_sha256=sha(analyzer),
  replay_spec_sha256=sha(specpath),memory_available_gib=memory/2**20,
  fpga_access=False,whole_cad=False,duplicate_request_withdrawn=str(withdrawn)))
 subprocess.run(['systemctl','daemon-reload'],check=True)
 subprocess.run(['systemctl','enable','--now','ec-opt4-mcrams-entry-area-analysis-r1.timer',unit],check=True,capture_output=True)
 subprocess.run(['systemctl','start','ec-opt4-mcrams-entry-area-analysis-r1.service'],check=True)
 subprocess.run(['systemctl','show',unit,'-p','MainPID','-p','ActiveState','-p','MemoryMax','-p','AllowedCPUs'],check=True)

if __name__=='__main__':main()
