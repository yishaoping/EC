#!/usr/bin/python3
"""Install exactly one bounded CPU-only P0 physical retry; no FPGA operations."""
import fcntl
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys

HERE = Path(__file__).resolve().parent
W = HERE.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
L = D/'cycleprecise-svb-spread-implementation-r1-20261111'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import bound_inputs, live, read, save, sha, now


def main():
    assert os.geteuid() == 0
    req = read(HERE/'request.json')
    bound_inputs(req['spec'])
    unit = 'ec-opt4-original-svb-spread-impl-r1.service'
    spec = req['spec']
    assert spec['kind'] == 'module' and spec['argv'] == ['/usr/bin/python3',str(HERE/'run.py')]
    # This is a small saved-checkpoint physical job, not another whole-DUT
    # synthesis. Count guards remain unchanged. Admission uses measured host
    # margins plus hard per-service CPU/memory limits and a separate lock.
    memory = int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:')))
    assert memory >= 256*2**20, 'insufficient independent retry margin'
    load = float(Path('/proc/loadavg').read_text().split()[0])
    assert load < 48 and shutil.disk_usage(W).free >= 150*2**30
    peers = U/'jobs'/spec['name']/'state.json'
    r = read(peers)
    assert not live(r) and not live(r.get('child',{})), 'adopt already running broker job'
    L.mkdir(exist_ok=True)
    os.chown(L,1008,1008)
    lock = (L/'install.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not live(read(L/'state.json')), 'adopt existing independent implementation'
    q = U/'requests/foreground-svb-spread-impl-r1-8491167d.json'
    withdrawn = q.with_suffix('.json.withdrawn-p0-direct')
    if q.exists():
        assert sha(q)==sha(HERE/'request.json')
        assert not withdrawn.exists()
        q.rename(withdrawn)
    else:
        assert withdrawn.exists() and sha(withdrawn)==sha(HERE/'request.json')
    cpus = sorted(os.sched_getaffinity(0))[-2:]
    assert len(cpus)==2
    text=f'''[Unit]
Description=Original frozen SVB bounded spread placement and routing
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User=guozh
Group=guozh
WorkingDirectory={HERE}
ExecStart=/usr/bin/python3 {HERE}/run.py
Environment=PYTHONPATH={W}/scripts
Nice=10
CPUQuota=200%
AllowedCPUs={' '.join(map(str,cpus))}
MemoryMax=64G
TasksMax=256
Restart=no
KillMode=control-group
StandardOutput=append:{L}/service.log
StandardError=append:{L}/service.log
[Install]
WantedBy=multi-user.target
'''
    p=Path('/etc/systemd/system')/unit
    if p.exists():assert p.read_text()==text
    else:p.write_text(text)
    save(L/'resource-admission.json',dict(schema='ec-svb-bounded-physical-resource-admission/1',
        utc=now(),memory_available_gib=memory/2**20,load1=load,
        disk_free_gib=shutil.disk_usage(W).free/2**30,CPUQuota='200%',
        allowed_cpus=cpus,memory_max_gib=64,target_changed=False,
        whole_dut_synthesis=False,fpga_access=False,producer_untouched=True,
        withdrawn_duplicate_request=str(withdrawn),inputs=bound_inputs(spec),
        unit=unit,unit_sha256=sha(p)))
    subprocess.run(['systemctl','daemon-reload'],check=True)
    subprocess.run(['systemctl','enable','--now',unit],check=True,capture_output=True)
    subprocess.run(['systemctl','show',unit,'-p','ActiveState','-p','MainPID',
        '-p','CPUQuotaPerSecUSec','-p','MemoryMax','-p','AllowedCPUs'],check=True)


if __name__ == '__main__':
    main()
