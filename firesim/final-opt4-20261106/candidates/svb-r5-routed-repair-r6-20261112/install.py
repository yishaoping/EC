#!/usr/bin/python3
"""Install only the new r6 services; leave all existing services untouched."""
import os
from pathlib import Path
import subprocess
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import read, save, sha, now


def main():
    for manifest in ['inputs.json', 'runtime-inputs.json', 'application-inputs.json']:
        pins = read(C/manifest)
        assert pins['board_allowlist'] == ['0000:21:00.0']
        for path, digest in pins['files'].items():
            assert sha(path) == digest, ('bound input changed', path)
    for name in ['runtime.py', 'application.py']:
        subprocess.run(['/usr/bin/python3', str(C/name), '--offline'], cwd=W, check=True)
    if '--validate-only' in sys.argv:
        return
    assert os.geteuid() == 0
    # A confirmed inactive r5 and an empty cgroup are required for slot reuse.
    unit = 'ec-opt4-svb-host40-shell-physical-r5.service'
    props = dict(x.split('=', 1) for x in subprocess.check_output(['systemctl', 'show', unit, '-p', 'MainPID', '-p', 'ActiveState'], text=True).splitlines())
    assert props['MainPID'] == '0' and props['ActiveState'] in ['inactive', 'failed']
    cg = Path('/sys/fs/cgroup/systemd/system.slice')/unit
    assert not cg.exists() or not any(p.read_text().strip() for p in cg.rglob('cgroup.procs'))
    units = {}
    for role, script, user, memory, cpus, root in [
        ('physical', 'controller.py', 'guozh', '64G', '224 225', 'cycleprecise-svb-host40-shell-recovery-r6-20261112'),
        ('follow', 'runtime.py', 'root', '32G', '236 237', 'cycleprecise-original-svb-host40-shell-onboard-r6-20261112'),
        ('application-follow', 'application.py', 'root', '4G', '238 239', 'cycleprecise-original-svb-host40-shell-application-onboard-r6-20261112'),
    ]:
        unit = 'ec-opt4-svb-host40-shell-'+role+'-r6.service'
        out = D/root
        out.mkdir(exist_ok=True)
        if user == 'guozh':
            os.chown(out, 1008, 1008)
        text = f'''[Unit]
Description=Original SVB r5 routed checkpoint repair {role} r6
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User={user}
Group={user}
WorkingDirectory={W}
ExecStart=/usr/bin/python3 {C/script}
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
        target = Path('/etc/systemd/system')/unit
        if target.exists():
            assert target.read_text() == text
        else:
            assert not (out/'state.json').exists(), 'existing r6 state requires adoption'
            target.write_text(text)
        units[unit] = sha(target)
    subprocess.run(['systemctl', 'daemon-reload'], check=True)
    for unit in units:
        subprocess.run(['systemctl', 'enable', '--now', unit], check=True)
    save(C/'installation.json', dict(status='R6_INSTALLED_REUSING_R5_E_ROUTED_CHECKPOINT', units=units,
        existing_services_changed=False, existing_processes_signalled=False, fpga_io_during_install=False,
        board_allowlist=['0000:21:00.0'], utc=now()))
    print('R6 physical, independent certification/21-only directed measurement, and application replay services installed.')


if __name__ == '__main__':
    main()
