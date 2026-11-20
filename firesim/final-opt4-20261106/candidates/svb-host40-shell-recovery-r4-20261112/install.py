#!/usr/bin/python3
"""Replace verified idle physical waiters; preserve every live CAD process."""
import fcntl
import os
from pathlib import Path
import subprocess
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
sys.path.insert(0, str(W / 'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha


def verify():
    for name in ['inputs.json', 'runtime-inputs.json', 'application-inputs.json']:
        pins = read(C / name)
        assert pins['board_allowlist'] == ['0000:21:00.0']
        assert pins['functional_baseline'] == '8491167d84b6d9521b151a743673c1516926a1f8'
        for path, digest in pins['files'].items():
            assert sha(path) == digest, ('immutable input changed', path)
    for name in ['runtime.py', 'application.py']:
        subprocess.run(['/usr/bin/python3', str(C / name), '--offline'], cwd=W, check=True)


def idle(unit, version):
    props = dict(line.split('=', 1) for line in subprocess.check_output(
        ['systemctl', 'show', unit, '-p', 'MainPID', '-p', 'ActiveState', '-p', 'ControlGroup'],
        text=True).splitlines() if '=' in line)
    state = read(D / ('cycleprecise-svb-host40-shell-recovery-' + version + '-20261112/state.json'))
    pid = int(props['MainPID'])
    assert pid and props['ActiveState'] == 'active' and state['pid'] == pid and live(state)
    assert state['status'] in [
        'WAITING_ADMITTED_THIRD_SMALL_COMPONENT_RESOURCE_GUARD',
        'WAITING_R2_ACTUAL_FAILURE_AND_EXACT_CGROUP_EXIT_NO_CAD']
    assert not state.get('child'), 'physical child prevents handoff'
    cg = Path('/sys/fs/cgroup/systemd/system.slice') / unit
    assert props['ControlGroup'] == '/system.slice/' + unit and (cg / 'cgroup.procs').is_file()
    tasks = {int(v) for p in cg.rglob('cgroup.procs') for v in p.read_text().split()}
    assert tasks == {pid}, 'only an exact single Python waiter can transfer'
    argv = [v.decode() for v in (Path('/proc') / str(pid) / 'cmdline').read_bytes().split(b'\0') if v]
    expected = ['/usr/bin/python3', str(W / ('candidates/svb-host40-shell-recovery-' + version + '-20261112/controller.py'))]
    assert argv == expected
    return dict(unit=unit, version=version, properties=props, state=state,
        process=identity(pid), argv=argv, tasks=sorted(tasks))


def main():
    verify()
    if '--validate-only' in sys.argv:
        for version in ['r2', 'r3']:
            row = idle('ec-opt4-svb-host40-shell-physical-' + version + '.service', version)
            print('VERIFIED_IDLE_PHYSICAL_WAITER', row['unit'], row['process']['pid'])
        print('PASS_R4_IMMUTABLE_INPUTS_ORIGINAL_OFFLINE_GATES_EXACT_IDLE_WAITERS_NO_ACTIONS')
        return
    assert os.geteuid() == 0
    lock = (C / 'installation.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not (C / 'installation.json').exists(), 'adopt already installed r4'
    # Build and verify all units before retiring any empty waiter.
    units = {}
    configurations = [
        ('physical', 'controller.py', 'guozh', '64G', '224 225', 'cycleprecise-svb-host40-shell-recovery-r4-20261112'),
        ('follow', 'runtime.py', 'root', '32G', '236 237', 'cycleprecise-original-svb-host40-shell-onboard-r4-20261112'),
        ('application-follow', 'application.py', 'root', '4G', '238 239', 'cycleprecise-original-svb-host40-shell-application-onboard-r4-20261112'),
    ]
    for role, script, user, memory, cpus, output in configurations:
        unit = 'ec-opt4-svb-host40-shell-' + role + '-r4.service'
        out = D / output
        out.mkdir(exist_ok=True)
        assert not (out / 'state.json').exists(), 'adopt existing r4 state'
        if user == 'guozh':
            os.chown(out, 1008, 1008)
        text = f'''[Unit]
Description=Measured same-slot original SVB host40 {role} r4
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User={user}
Group={user}
WorkingDirectory={W}
ExecStart=/usr/bin/python3 {C / script}
Environment=PYTHONPATH={W / 'scripts'}
Nice=10
CPUQuota=200%
AllowedCPUs={cpus}
MemoryMax={memory}
TasksMax=512
Restart=no
KillMode=process
StandardOutput=append:{out / 'service.log'}
StandardError=append:{out / 'service.log'}
[Install]
WantedBy=multi-user.target
'''
        path = Path('/etc/systemd/system') / unit
        if path.exists():
            assert path.read_text() == text
        else:
            path.write_text(text)
        units[unit] = sha(path)
    rows = [idle('ec-opt4-svb-host40-shell-physical-' + v + '.service', v) for v in ['r2', 'r3']]
    save(C / 'idle-handoff-before.json', dict(utc=now(), rows=rows, cad_signalled=False, fpga_io=False))
    for row in rows:
        current = idle(row['unit'], row['version'])
        assert current['process']['start_ticks'] == row['process']['start_ticks']
        subprocess.run(['systemctl', '--no-ask-password', 'stop', row['unit']], check=True)
        assert not live(row['state'])
        cg = Path('/sys/fs/cgroup/systemd/system.slice') / row['unit']
        assert not cg.exists() or not any(p.read_text().strip() for p in cg.rglob('cgroup.procs'))
        subprocess.run(['systemctl', '--no-ask-password', 'disable', row['unit']], check=True)
    save(C / 'installation.json', dict(
        status='EXACT_IDLE_R2_R3_WAITERS_REPLACED_BY_MEASURED_SAME_SLOT_R4',
        utc=now(), units=units, retired_idle_waiters=rows, cad_signalled=False,
        fpga_io=False, resource_admission=read(C / 'inputs.json')['resource_admission']))
    subprocess.run(['systemctl', '--no-ask-password', 'daemon-reload'], check=True)
    subprocess.run(['systemctl', '--no-ask-password', 'enable', '--now', *units], check=True)
    print('INSTALLED_MEASURED_SAME_SLOT_R4_B_C_D_AND_INDEPENDENT21_ONLY_FOLLOWERS')


if __name__ == '__main__':
    main()
