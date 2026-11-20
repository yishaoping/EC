#!/usr/bin/python3
"""Adopt the root supervisor only after its detached round exits naturally."""
import fcntl
import importlib.util
import os
from pathlib import Path
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
OUT = D / 'fpga-unattended-r2-20261112'
sys.path.insert(0, str(W / 'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha


def load():
    pins = read(C / 'inputs.json')
    assert all(sha(p) == h for p, h in pins['files'].items())
    spec = importlib.util.spec_from_file_location('ec_bounded_fpga_supervisor', C / 'supervisor.py')
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def main():
    module = load()
    if '--validate-only' in sys.argv:
        snapshot = module.snapshot()
        import json
        assert Path(snapshot['full_evidence_snapshot']).is_file()
        assert len(snapshot['states']) <= 24
        print(json.dumps(dict(status='PASS_BOUNDED_REAL_SNAPSHOT_FULL_EVIDENCE_RETAINED',
            states=len(snapshot['states']), bytes=len(json.dumps(snapshot)),
            full_evidence_snapshot=snapshot['full_evidence_snapshot'], fpga_io=False)))
        return
    assert os.geteuid() == 0
    OUT.mkdir(exist_ok=True)
    lock = (OUT / 'takeover.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    unit = 'ec-opt4-unattended.service'
    while True:
        props = dict(line.split('=', 1) for line in subprocess.check_output(
            ['systemctl', 'show', unit, '-p', 'MainPID', '-p', 'ActiveState', '-p', 'ControlGroup'],
            text=True).splitlines() if '=' in line)
        cg = Path('/sys/fs/cgroup/systemd/system.slice') / unit
        if props['MainPID'] == '0':
            assert props['ActiveState'] in ['inactive', 'failed']
            assert not cg.exists() or not any(p.read_text().strip() for p in cg.rglob('cgroup.procs'))
            break
        active = []
        for path in (U / 'rounds').glob('round-*/worker.json'):
            row = read(path)
            if live(row) or live(row.get('child', {})):
                active.append(str(path))
        tasks = {int(v) for p in cg.rglob('cgroup.procs') for v in p.read_text().split()} if cg.exists() else set()
        old = read(U / 'state.json')
        pid = int(props['MainPID'])
        if active or tasks != {pid} or not live(old) or old.get('pid') != pid:
            save(OUT / 'state.json', dict(status='WAITING_CURRENT_AI_ROUND_NATURAL_EXIT_NO_SIGNALS',
                **identity(), updated_utc=now(), active_rounds=active, supervisor_tasks=sorted(tasks),
                cad_or_model_signalled=False, fpga_io=False))
            time.sleep(15)
            continue
        argv = [v.decode() for v in (Path('/proc') / str(pid) / 'cmdline').read_bytes().split(b'\0') if v]
        assert argv == ['/usr/bin/python3', str(W / 'scripts/opt4_unattended_supervisor.py')]
        save(OUT / 'old-supervisor-before.json', dict(utc=now(), properties=props,
            state=old, tasks=sorted(tasks), argv=argv, process=identity(pid), cad_signalled=False))
        # Recheck immediately: no request-handler or launcher child may have
        # appeared between the evidence read and the transfer.
        assert {int(v) for p in cg.rglob('cgroup.procs') for v in p.read_text().split()} == {pid}
        subprocess.run(['systemctl', '--no-ask-password', 'stop', unit], check=True)
        assert not live(old)
        assert not cg.exists() or not any(p.read_text().strip() for p in cg.rglob('cgroup.procs'))
        subprocess.run(['systemctl', '--no-ask-password', 'disable', unit], check=True)
        save(OUT / 'old-supervisor-handoff.json', dict(utc=now(),
            old_identity=old, cad_or_model_signalled=False, fpga_io=False))
        break
    save(OUT / 'state.json', dict(status='ENTERING_BOUNDED_SUPERVISOR_EXISTING_JOBS_ADOPTED',
        **identity(), updated_utc=now(), cad_or_model_signalled=False, fpga_io=False))
    module.main()


if __name__ == '__main__':
    main()
