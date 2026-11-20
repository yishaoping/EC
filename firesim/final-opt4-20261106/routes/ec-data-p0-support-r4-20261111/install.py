#!/usr/bin/python3
"""Run one bounded incremental replay driver build; no model/CAD/device work."""
import fcntl
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
O = D/'ec-data-p0-support-r4-20261111'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import bound_inputs, live, read, save, sha, now


def main():
    assert os.geteuid() == 0
    available = int(next(a.split()[1] for a in Path('/proc/meminfo').read_text().splitlines() if a.startswith('MemAvailable:')))
    assert available >= 192*2**20 and float(Path('/proc/loadavg').read_text().split()[0]) < 48
    assert shutil.disk_usage(W).free >= 100*2**30
    O.mkdir(exist_ok=True)
    os.chown(O, 1008, 1008)
    lock = (O/'install.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    name = 'full-svb-gg-stream-replay-r2-8491167d'
    q = U/'requests'/(name+'.json')
    withdrawn = U/'withdrawn-requests'/(name+'.direct-bounded.json')
    assert not q.exists() and not withdrawn.exists()
    spec = read(Path(__file__).parent/'spec.json')
    assert spec['name'] == name
    assert spec['argv'] == ['/usr/bin/python3', str(W/'candidates/full-svb-gg-stream-replay-r2-20261111/run.py'), '--prepare']
    hashes = bound_inputs(spec)
    old = read(U/'jobs'/name/'state.json')
    assert not live(old) and not live(old.get('child', {})), 'adopt existing preparation'
    assert not (D/'cycleprecise-original-svb-gg-stream-replay-r2-20261111').exists(), 'preparation already started; adopt evidence'
    specpath = O/'spec.json'
    if specpath.exists():
        assert read(specpath) == spec
    else:
        save(specpath, spec)
    name = 'ec-opt4-real-svb-gg-stream-prepare-r2.service'
    unit = f'''[Unit]
Description=Incremental original SVB stream replay driver preparation without FPGA access
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
StandardOutput=append:{O}/service.log
StandardError=append:{O}/service.log
[Install]
WantedBy=multi-user.target
'''
    p = Path('/etc/systemd/system')/name
    if p.exists():
        assert p.read_text() == unit
    else:
        p.write_text(unit)
    save(O/'installation.json', dict(utc=now(), memory_available_gib=available/2**20,
        disk_free_gib=shutil.disk_usage(W).free/2**30, inputs=hashes,
        spec_sha256=sha(specpath), unit_sha256=sha(p), fpga_access=False,
        whole_cad=False, unique_direct_job_not_broker_queued=True))
    subprocess.run(['systemctl','daemon-reload'], check=True)
    subprocess.run(['systemctl','enable','--now',name], check=True)
    subprocess.run(['systemctl','show',name,'-p','ActiveState','-p','MainPID','-p','AllowedCPUs','-p','MemoryMax'], check=True)


if __name__ == '__main__':
    main()
