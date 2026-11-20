#!/usr/bin/python3
"""Install a persistent alternate-artifact certification/21-only follower."""
from pathlib import Path
import json
import os
import subprocess
import sys

HERE=Path(__file__).resolve().parent
W=HERE.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
L=D/'cycleprecise-original-svb-spread-onboard-r2-20261111'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import save,sha,now


def main():
    assert os.geteuid()==0
    p=HERE/'inputs.json';plan=json.loads(p.read_text())
    assert plan['functional_baseline']=='8491167d84b6d9521b151a743673c1516926a1f8'
    assert plan['board_allowlist']==['0000:21:00.0'] and not plan['target_changed']
    for name,h in plan['files'].items():assert sha(name)==h,(name,'changed')
    L.mkdir(exist_ok=True)
    unit='ec-opt4-original-svb-spread-follow-r2.service'
    text=f'''[Unit]
Description=Original SVB alternate physical result certification and safe 21-only replay
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User=root
WorkingDirectory={W}
ExecStart=/usr/bin/python3 {HERE}/runtime.py
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
'''
    f=Path('/etc/systemd/system')/unit
    if f.exists():assert f.read_text()==text
    else:f.write_text(text)
    save(L/'installation.json',dict(unit=unit,unit_sha256=sha(f),inputs_sha256=sha(p),
        installed_utc=now(),fpga_operation_at_install=False,
        constraints='Original deployed sample wins; alternate only after routed timing/DRC/clock+source/driver/trace identity certification. Share both21 locks. Stop only idle predecessor deployment waiter after valid alternate cert. Never stop CAD or live sample.'))
    # Only replace our newly created idle follower, with verified identity and no FPGA action.
    oldstate=json.loads((D/'cycleprecise-original-svb-spread-onboard-r1-20261111/state.json').read_text())
    assert oldstate['status']=='WAITING_COMPONENT_CAD' and not oldstate.get('child') and not oldstate.get('fpga_access')
    assert not (D/'cycleprecise-original-svb-spread-onboard-r1-20261111/deployment.json').exists()
    pid=subprocess.check_output(['systemctl','show','ec-opt4-original-svb-spread-follow-r1.service','-p','MainPID','--value'],text=True).strip()
    assert int(pid)==oldstate['pid']
    current=Path('/proc',pid,'stat').read_text().rsplit(')',1)[1].split()[19]
    assert current==oldstate['start_ticks']
    save(L/'replaced-idle-follower-r1.json',dict(prior_state=oldstate,reason='guard original idle waiter handoff with shared21 locks',fpga_access=False,cad_signalled=False))
    subprocess.run(['systemctl','disable','--now','ec-opt4-original-svb-spread-follow-r1.service'],check=True,capture_output=True)
    subprocess.run(['systemctl','daemon-reload'],check=True)
    subprocess.run(['systemctl','enable','--now',unit],check=True,capture_output=True)
    subprocess.run(['systemctl','show',unit,'-p','ActiveState','-p','MainPID'],check=True)


if __name__=='__main__':main()
