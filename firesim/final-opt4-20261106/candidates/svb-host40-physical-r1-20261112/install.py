#!/usr/bin/python3
"""Install immutable waiting CPU/21-only followers; no CAD or device call here."""
import os
from pathlib import Path
import subprocess
import sys

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import read,save,sha,live,now


def main():
    assert os.geteuid()==0
    for manifest in ['inputs.json','runtime-inputs.json','application-inputs.json']:
        pins=read(C/manifest)
        assert pins['board_allowlist']==['0000:21:00.0'] and pins['profile']=='OriginalSVB32-component-trace-host40'
        for path,h in pins['files'].items():assert sha(path)==h,('immutable host40 install input changed',path)
    for script in ['runtime.py','application.py']:
        subprocess.run(['/usr/bin/python3',str(C/script),'--offline'],cwd=W,check=True)
    configs=[('ec-opt4-svb-host40-physical-r1.service','controller.py','guozh','64G','250 251',
              D/'cycleprecise-svb-host40-implementation-r1-20261112'),
             ('ec-opt4-svb-host40-follow-r1.service','runtime.py','root','32G','232 233',
              D/'cycleprecise-original-svb-host40-onboard-r1-20261112'),
             ('ec-opt4-svb-host40-application-follow-r1.service','application.py','root','4G','234 235',
              D/'cycleprecise-original-svb-host40-application-onboard-r1-20261112')]
    units={}
    for name,script,user,memory,cpus,out in configs:
        out.mkdir(exist_ok=True)
        old=read(out/'state.json')
        assert not live(old) and not live(old.get('child',{})),('adopt existing live service',name)
        assert not (out/'deployment.json').exists() and not (out/'run-started.json').exists(),('preserve existing run',name)
        if user=='guozh':os.chown(out,1008,1008)
        text=f'''[Unit]
Description=Independent original SVB host40 conditional {script}
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User={user}
Group={user}
WorkingDirectory={W}
ExecStart=/usr/bin/python3 {C}/{script}
Environment=PYTHONPATH={W}/scripts
Nice=10
CPUQuota=200%
AllowedCPUs={cpus}
MemoryMax={memory}
TasksMax=512
Restart=no
KillMode=process
StandardOutput=append:{out}/service.log
StandardError=append:{out}/service.log
[Install]
WantedBy=multi-user.target
'''
        p=Path('/etc/systemd/system')/name
        if p.exists():assert p.read_text()==text,('service definition differs; independent version required',name)
        else:p.write_text(text)
        units[name]=sha(p)
    subprocess.run(['systemctl','daemon-reload'],check=True)
    subprocess.run(['systemctl','enable','--now',*units],check=True)
    save(C/'installation.json',dict(status='WAITING_CPU_AND_INDEPENDENT_21_ONLY_FOLLOWERS_INSTALLED',units=units,
       manifests={name:sha(C/name) for name in ['inputs.json','runtime-inputs.json','application-inputs.json']},
       fpga_access_at_install=False,immediate_cad_not_required=True,created_utc=now()))
    subprocess.run(['systemctl','show',*units,'-p','ActiveState','-p','MainPID','-p','SubState'],check=True)


if __name__=='__main__':main()
