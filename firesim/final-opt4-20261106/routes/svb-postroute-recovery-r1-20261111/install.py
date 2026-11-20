#!/usr/bin/python3
"""Install conditional CPU workers/timer and certified 21-only board follower.

Installing starts only the read-only dispatcher timer and a waiting follower.
Workers stay idle until a recorded producer failure safely releases a slot.
"""
import os
from pathlib import Path
import subprocess
import sys
C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
R=D/'cycleprecise-svb-postroute-recovery-r1-20261111'
L=D/'cycleprecise-original-svb-recovered-onboard-r1-20261111'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import read,save,sha,live,now


def put(name,text):
    p=Path('/etc/systemd/system')/name
    if p.exists():assert p.read_text()==text,('different preexisting unit',name)
    else:p.write_text(text)
    return p


def main():
    assert os.geteuid()==0
    pins=read(C/'inputs.json')
    assert pins['functional_baseline']=='8491167d84b6d9521b151a743673c1516926a1f8'
    assert pins['board_allowlist']==['0000:21:00.0'] and not pins['target_changed']
    for p,h in pins['files'].items():assert sha(p)==h
    subprocess.run(['/usr/bin/python3',str(C/'runtime.py'),'--offline'],check=True)
    R.mkdir(exist_ok=True);L.mkdir(exist_ok=True)
    assert not live(read(L/'state.json')),'adopt existing runtime follower'
    assert not (L/'deployment.json').exists(),'adopt existing deployment'
    installed={}
    for producer,cpus in [('original','252 253'),('spread','254 255')]:
        for mode in ['postroute','replicate']:
            out=R/(producer+'-'+mode);out.mkdir(exist_ok=True);os.chown(out,1008,1008)
            unit=f'ec-opt4-svb-recovery-{producer}-{mode}-r1.service'
            text=f'''[Unit]
Description=Original SVB bounded conditional {producer} {mode} physical recovery
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User=guozh
Group=guozh
WorkingDirectory={C}
ExecStart=/usr/bin/python3 {C}/run.py --producer {producer} --mode {mode} --run
Environment=PYTHONPATH={W}/scripts
Nice=10
CPUQuota=200%
AllowedCPUs={cpus}
MemoryMax=64G
TasksMax=256
Restart=no
KillMode=control-group
StandardOutput=append:{out}/service.log
StandardError=append:{out}/service.log
'''
            installed[unit]=sha(put(unit,text))
    name='ec-opt4-svb-physical-recovery-r1-dispatch.service'
    text=f'''[Unit]
Description=Read-only failed SVB physical stage dispatcher
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=oneshot
User=root
WorkingDirectory={W}
ExecStart=/usr/bin/python3 {C}/dispatch.py
CPUQuota=100%
MemoryMax=2G
TimeoutStartSec=180
StandardOutput=append:{R}/dispatch.log
StandardError=append:{R}/dispatch.log
'''
    installed[name]=sha(put(name,text))
    timer='ec-opt4-svb-physical-recovery-r1-dispatch.timer'
    installed[timer]=sha(put(timer,'''[Unit]
Description=Check original SVB physical recovery every five minutes
[Timer]
OnBootSec=45
OnUnitActiveSec=300
Persistent=true
Unit=ec-opt4-svb-physical-recovery-r1-dispatch.service
[Install]
WantedBy=timers.target
'''))
    follower='ec-opt4-original-svb-recovered-follow-r1.service'
    installed[follower]=sha(put(follower,f'''[Unit]
Description=Certify recovered original SVB then replay only on card21
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User=root
WorkingDirectory={W}
ExecStart=/usr/bin/python3 {C}/runtime.py
Environment=PYTHONPATH={W}/scripts
Nice=10
CPUQuota=200%
MemoryMax=32G
TasksMax=512
Restart=no
KillMode=process
StandardOutput=append:{L}/service.log
StandardError=append:{L}/service.log
[Install]
WantedBy=multi-user.target
'''))
    save(R/'installation.json',dict(inputs_sha256=sha(C/'inputs.json'),units=installed,
         installed_utc=now(),fpga_access_at_install=False,starts_cpu_cad_at_install=False,
         rule='Only failed inactive empty producer -> unique bounded replacement; no third component route. Independent source/timing/DRC cert then both21 locks. Existing completed component wins; no e2/global operations.'))
    subprocess.run(['systemctl','daemon-reload'],check=True)
    subprocess.run(['systemctl','enable','--now',timer,follower],check=True)
    subprocess.run(['systemctl','show',timer,follower,'-p','MainPID','-p','ActiveState'],check=True)


if __name__=='__main__':main()
