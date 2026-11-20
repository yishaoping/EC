#!/usr/bin/python3
"""Install new conditional services only; never stop/restart an existing task."""
import importlib.util
import os
from pathlib import Path
import pwd
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
    spec = importlib.util.spec_from_file_location('conditional_r8', C/'controller.py')
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    m.verify()
    for name in ['runtime.py', 'application.py']:
        subprocess.run(['/usr/bin/python3', str(C/name), '--offline'], check=True)
    if '--validate-only' in sys.argv:
        return
    assert os.geteuid() == 0
    account = pwd.getpwnam('guozh')
    units = {}
    for role, script, user, memory, cpus, root in [
        ('physical', 'controller.py', 'guozh', '64G', '224 225', 'cycleprecise-svb-host40-shell-recovery-r8-20261112'),
        ('follow', 'runtime.py', 'root', '32G', '236 237', 'cycleprecise-original-svb-host40-shell-onboard-r8-20261112'),
        ('application-follow', 'application.py', 'root', '4G', '238 239', 'cycleprecise-original-svb-host40-shell-application-onboard-r8-20261112'),
    ]:
        unit = 'ec-opt4-svb-host40-shell-'+role+'-r8.service'
        out = D/root
        out.mkdir(exist_ok=True)
        if user == 'guozh':
            os.chown(out, account.pw_uid, account.pw_gid)
        content = f'''[Unit]
Description=Conditional SVB routed checkpoint successor {role} r8
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
            assert target.read_text() == content
        else:
            assert not (out/'state.json').exists(), 'existing state requires adoption'
            target.write_text(content)
        units[unit] = sha(target)
    subprocess.run(['systemctl', 'daemon-reload'], check=True)
    for unit in units:
        subprocess.run(['systemctl', 'enable', '--now', unit], check=True)
    save(C/'installation.json', dict(status='CONDITIONAL_R8_INSTALLED_NO_DUPLICATE_CAD', utc=now(), units=units,
        predecessor_must_exhaust_and_exit=True, existing_processes_signalled=False,
        existing_services_changed=False, board_allowlist=['0000:21:00.0'], fpga_access=False))
    print('Conditional r8 and independent 21-only followers installed; existing services unchanged.')


if __name__ == '__main__':
    main()
