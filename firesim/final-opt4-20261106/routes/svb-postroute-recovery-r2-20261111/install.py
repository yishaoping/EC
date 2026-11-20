#!/usr/bin/python3
"""Replace only the pure waiting r1 timer with stricter r2 CPU admission."""
from pathlib import Path
import os
import subprocess
import sys
from guard import C,R1,verify,read,save,sha,now
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
ROOT=D/'cycleprecise-svb-postroute-recovery-r1-20261111'


def put(name,text):
    p=Path('/etc/systemd/system')/name
    if p.exists():assert p.read_text()==text,('preexisting different unit',name)
    else:p.write_text(text)
    return p


def props(unit):
    raw=subprocess.run(['systemctl','show',unit,'-p','MainPID','-p','ActiveState'],capture_output=True,text=True,check=True).stdout
    return dict(x.split('=',1) for x in raw.splitlines() if '=' in x)


def main():
    assert os.geteuid()==0
    verify()
    # Do not alter or stop the r1 root certificate/board follower. It continues
    # waiting on the exact same output manifests and source profile.
    for p in ['original','spread']:
        for mode in ['postroute','replicate']:
            unit=f'ec-opt4-svb-recovery-{p}-{mode}-r1.service'
            state=props(unit)
            assert state['MainPID']=='0' and state['ActiveState']=='inactive','adopt live r1 recovery worker'
    state=props('ec-opt4-svb-physical-recovery-r1-dispatch.service')
    assert state['MainPID']=='0' and state['ActiveState']=='inactive','allow r1 short dispatch to exit before installation'
    timer='ec-opt4-svb-physical-recovery-r1-dispatch.timer'
    subprocess.run(['systemctl','disable','--now',timer],check=True)
    # Recheck after cancelling only the lightweight timer, so a dispatch race
    # cannot leave an old worker starting during the new scheduler install.
    for p in ['original','spread']:
        for mode in ['postroute','replicate']:
            state=props(f'ec-opt4-svb-recovery-{p}-{mode}-r1.service')
            assert state['MainPID']=='0' and state['ActiveState']=='inactive'
    assert props('ec-opt4-svb-physical-recovery-r1-dispatch.service')['MainPID']=='0'
    units={}
    for p in ['original','spread']:
        for mode in ['postroute','replicate']:
            old=f'ec-opt4-svb-recovery-{p}-{mode}-r1.service'
            new=old.replace('-r1.service','-r2.service')
            text=(Path('/etc/systemd/system')/old).read_text()
            text=text.replace(str(R1/'run.py'),str(C/'run.py')).replace(f'WorkingDirectory={R1}',f'WorkingDirectory={C}')
            text=text.replace('conditional '+p,'strict exact-cgroup conditional '+p)
            units[new]=sha(put(new,text))
    old='ec-opt4-svb-physical-recovery-r1-dispatch.service';new=old.replace('-r1-','-r2-')
    text=(Path('/etc/systemd/system')/old).read_text().replace(str(R1/'dispatch.py'),str(C/'dispatch.py')).replace('failed SVB','strict exact-cgroup failed SVB')
    text=text.replace(str(ROOT/'dispatch.log'),str(ROOT/'dispatch-r2.log'))
    units[new]=sha(put(new,text))
    timer2='ec-opt4-svb-physical-recovery-r2-dispatch.timer'
    text=(Path('/etc/systemd/system')/timer).read_text().replace('-r1-','-r2-')
    units[timer2]=sha(put(timer2,text))
    save(ROOT/'strict-r2-installation.json',dict(installed_utc=now(),inputs_sha256=sha(C/'inputs.json'),
         units=units,disabled_pure_timer=timer,root_follower_preserved=True,
         r1_files_untouched=True,fpga_access=False,starts_cad_at_install=False))
    subprocess.run(['systemctl','daemon-reload'],check=True)
    subprocess.run(['systemctl','enable','--now',timer2],check=True)
    subprocess.run(['systemctl','show',timer2,'-p','ActiveState'],check=True)


if __name__=='__main__':main()
