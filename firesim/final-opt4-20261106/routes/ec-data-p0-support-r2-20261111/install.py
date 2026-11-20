#!/usr/bin/python3
"""Replace only a finite report-analysis timer with immutable evidence reuse."""
import hashlib
import json
import os
from pathlib import Path
import subprocess

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = W/'candidates/mcrams-dcache-entry-area-analysis-r2-20261111'
O = D/'ec-data-p0-support-r2-20261111'
EXPECTED = '553d0da88e26a155119f48c6f665e9909287f5c15da8f37f894fae712247a899'


def main():
    assert os.geteuid() == 0
    assert hashlib.sha256((C/'analyze.py').read_bytes()).hexdigest() == EXPECTED
    result = D/'build-logs/Opt4-mcrams-dcache-entry-area-analysis-r2-20261111/result.json'
    complete = json.loads(result.with_name('complete.json').read_text())
    assert hashlib.sha256(result.read_bytes()).hexdigest() == complete['result_sha256']
    assert complete['parser_source_sha256'] == EXPECTED
    old = 'ec-opt4-mcrams-entry-area-analysis-r1'
    status = subprocess.run(['systemctl','is-active',old+'.service'], text=True, capture_output=True)
    assert status.stdout.strip() == 'inactive'
    O.mkdir(exist_ok=True)
    os.chown(O, 1008, 1008)
    service = f'''[Unit]
Description=Validate and reuse immutable completed MCRams resource evidence
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=oneshot
User=guozh
Group=guozh
WorkingDirectory={C}
ExecStart=/usr/bin/python3 {C}/analyze.py
TimeoutStartSec=120
CPUQuota=100%
MemoryMax=1G
Nice=15
StandardOutput=append:{O}/area-analysis.log
StandardError=append:{O}/area-analysis.log
'''
    timer = '''[Unit]
Description=Recheck immutable MCRams resource evidence without rerunning synthesis
[Timer]
OnBootSec=60s
OnUnitInactiveSec=300s
AccuracySec=20s
Persistent=true
Unit=ec-opt4-mcrams-entry-area-analysis-r2.service
[Install]
WantedBy=timers.target
'''
    for suffix, text in [('service', service), ('timer', timer)]:
        p = Path('/etc/systemd/system/ec-opt4-mcrams-entry-area-analysis-r2.'+suffix)
        if p.exists():
            assert p.read_text() == text
        else:
            p.write_text(text)
    # The old unit has no CAD child and is already idle. Never stop any
    # synthesis, simulation, card owner or deployment follower here.
    subprocess.run(['systemctl','disable','--now',old+'.timer'], check=True)
    subprocess.run(['systemctl','daemon-reload'], check=True)
    subprocess.run(['systemctl','enable','--now','ec-opt4-mcrams-entry-area-analysis-r2.timer'], check=True)
    subprocess.run(['systemctl','start','ec-opt4-mcrams-entry-area-analysis-r2.service'], check=True)
    assert hashlib.sha256(result.read_bytes()).hexdigest() == complete['result_sha256']
    print(json.dumps(dict(status='IMMUTABLE_ANALYSIS_TIMER_INSTALLED',result_sha256=complete['result_sha256'],fpga_access=False,cad_touched=False)))


if __name__ == '__main__':
    main()
