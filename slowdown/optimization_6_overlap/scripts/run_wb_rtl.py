#!/usr/bin/env python3
"""Run the actual emitted writeback unit from a sealed experiment build."""
import argparse
import datetime as dt
import hashlib
import json
from pathlib import Path
import subprocess
import uuid

ROOT = Path(__file__).resolve().parents[3]
OUT = ROOT / 'slowdown/optimization_6_overlap'


def sha(p):
    return hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    ap = argparse.ArgumentParser(); ap.add_argument('generated', type=Path)
    args = ap.parse_args()
    source = args.generated.resolve() / 'gen-collateral/BoomWritebackUnit.sv'
    driver = OUT / 'scripts/wb_driver.cpp'
    run = OUT / 'build' / ('wb_' + dt.datetime.now().strftime('%Y%m%d_%H%M%S_') + uuid.uuid4().hex[:8])
    run.mkdir(parents=True)
    argv = ['verilator', '--cc', '--exe', '--build', '--assert', '-Wno-fatal',
        '--top-module', 'BoomWritebackUnit', '-Mdir', str(run / 'obj'),
        '-CFLAGS', '-O2 -std=c++17', str(source), str(driver), '-o', 'wb_test']
    with (run / 'build.log').open('x') as log:
        subprocess.run(argv, cwd=ROOT, stdout=log, stderr=subprocess.STDOUT, check=True)
    result = subprocess.run([str(run / 'obj/wb_test')], capture_output=True, text=True, check=True)
    report = dict(scope='actual emitted WB RTL with TtoT/TtoN and probe concurrency; not the top-level retained-receipt controller',
        source=str(source), source_sha256=sha(source), driver_sha256=sha(driver),
        runner_sha256=sha(Path(__file__)), status='PASS', output=result.stdout.strip())
    (run / 'result.json').write_text(json.dumps(report, indent=2, sort_keys=True) + '\n')
    print(result.stdout.strip()); print('RESULT=' + str(run / 'result.json'))


if __name__ == '__main__':
    main()
