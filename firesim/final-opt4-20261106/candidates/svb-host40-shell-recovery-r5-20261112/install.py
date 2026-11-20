#!/usr/bin/python3
import os,sys,subprocess
from pathlib import Path
C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import read,save,sha,now,live

def validate():
    for name in ['inputs.json','runtime-inputs.json','application-inputs.json']:
        p=read(C/name)
        assert p['board_allowlist']==['0000:21:00.0']
        for path,h in p['files'].items():assert sha(path)==h,('input changed',path)
    for name in ['runtime.py','application.py']:
        subprocess.run(['/usr/bin/python3',str(C/name),'--offline'],check=True,cwd=W)
    s=read(D/'cycleprecise-svb-host40-shell-recovery-r4-20261112/state.json')
    assert s['status']=='BOUNDED_SHELL_STRATEGIES_FAILED_WITH_ALL_CHECKPOINTS_RETAINED'
    assert not live(s) and not live(s.get('child',{}))
    unit='ec-opt4-svb-host40-shell-physical-r4.service'
    assert subprocess.check_output(['systemctl','show',unit,'-p','MainPID','--value'],text=True).strip()=='0'
    cg=Path('/sys/fs/cgroup/systemd/system.slice')/unit
    assert not cg.exists() or not any(p.read_text().strip() for p in cg.rglob('cgroup.procs'))

def main():
    validate()
    if '--validate-only' in sys.argv:return
    assert os.geteuid()==0 and not (C/'installation.json').exists(),'adopt installed r5'
    units={}
    for role,script,user,memory,cpus,output in [
      ('physical','controller.py','guozh','64G','224 225','cycleprecise-svb-host40-shell-recovery-r5-20261112'),
      ('follow','runtime.py','root','32G','236 237','cycleprecise-original-svb-host40-shell-onboard-r5-20261112'),
      ('application-follow','application.py','root','4G','238 239','cycleprecise-original-svb-host40-shell-application-onboard-r5-20261112')]:
        unit='ec-opt4-svb-host40-shell-'+role+'-r5.service'
        out=D/output;out.mkdir(exist_ok=True)
        assert not (out/'state.json').exists(),'adopt existing state'
        if user=='guozh':os.chown(out,1008,1008)
        text=f"""[Unit]
Description=Original SVB host40 private preroute continuation {role} r5
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User={user}
Group={user}
WorkingDirectory={W}
ExecStart=/usr/bin/python3 {C/script}
Environment=PYTHONPATH={W/'scripts'}
Nice=10
CPUQuota=200%
AllowedCPUs={cpus}
MemoryMax={memory}
TasksMax=512
Restart=no
KillMode=process
StandardOutput=append:{out/'service.log'}
StandardError=append:{out/'service.log'}
[Install]
WantedBy=multi-user.target
"""
        path=Path('/etc/systemd/system')/unit
        assert not path.exists(),'preserve existing unit'
        path.write_text(text);units[unit]=sha(path)
    save(C/'installation.json',dict(status='INDEPENDENT_R5_INSTALLED_FROM_COMPLETED_R4_NO_SIGNALS',utc=now(),units=units,fpga_io=False,cad_signalled=False))
    subprocess.run(['systemctl','daemon-reload'],check=True)
    subprocess.run(['systemctl','enable','--now',*units],check=True)

if __name__=='__main__':main()
