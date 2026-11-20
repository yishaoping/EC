#!/usr/bin/python3
"""Recover utilization rows from a completed OOC map without rerunning CAD."""
from pathlib import Path
import hashlib
import json
import os
import re

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
F = W/'Opt4-fit-address-decode-r2-20261111'
C = W/'candidates/address-decode-r2-20261111'
SHARED = W/'candidates/address-decode-r1-20261111/controller.py'
S = D/'Opt4-fit-address-decode-r2-state.json'
REPORT = D/'build-logs/Opt4-fit-address-decode-r2-20261111/map-full-module/utilization.rpt'
OUT = D/'build-logs/Opt4-fit-address-decode-r2-20261111/map-full-module/recovered-utilization.json'
COMMIT = '579904b258213630cf00c13e65fde5ea9512bb03'
SOURCE = '9bbb8feb5244affd7d7288a1a3024a6c53b9cf5248cf4077aad3959e00cf088c'

def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda: f.read(1 << 20), b''):
            h.update(b)
    return h.hexdigest()

def write(p, value):
    p = Path(p); p.parent.mkdir(parents=True, exist_ok=True)
    data = (json.dumps(value, indent=2, sort_keys=True)+'\n').encode()
    if p.exists():
        assert p.read_bytes() == data, 'recovery receipt is immutable'
        return
    q = p.with_name(p.name+'.tmp-'+str(os.getpid()))
    with q.open('wb') as f:
        f.write(data); f.flush(); os.fsync(f.fileno())
    os.replace(q, p)

def main():
    state = json.loads(S.read_text())
    stage = state['stages']['map-full-module']
    mapped = state['full_module_map']
    assert state['hardware_commit'] == COMMIT and state['source_id'] == SOURCE
    assert stage['returncode'] == 0 and stage['accepted_result']
    assert mapped['report'] == str(REPORT) and mapped['report_sha256'] == sha(REPORT)
    assert stage['outputs'][str(REPORT)] == mapped['report_sha256']
    assert 'resource[row[1]]=float(row[2].replace' in SHARED.read_text()
    assert 'CLB LUTs*               | 1326431' in REPORT.read_text()

    resources = {}
    rows = {}
    pattern = re.compile(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|Block RAM Tile|DSPs)\s*\|\s*([\d,]+)\s*\|')
    for line_no, line in enumerate(REPORT.read_text().splitlines(), 1):
        m = pattern.match(line)
        if not m:
            continue
        name = m.group(1).rstrip('*')
        if name not in resources:
            resources[name] = float(m.group(2).replace(',', ''))
            rows[name] = dict(line=line_no, raw=line.strip())
    assert set(resources) == {'CLB LUTs', 'CLB Registers', 'CARRY8', 'Block RAM Tile', 'DSPs'}
    assert resources == {'CLB LUTs': 1326431.0, 'CLB Registers': 390359.0,
                         'CARRY8': 56070.0, 'Block RAM Tile': 216.0, 'DSPs': 0.0}
    assert all(v == 0 for v in mapped['resources'].values()), 'expected parser failure not present'
    result = dict(schema='ec-opt4-recovered-module-map/1', status='RECOVERED_COMPLETED_OOC_REPORT_PARSE',
        hardware_commit=COMMIT, source_id=SOURCE, scope='Complete PackageAddressStats OOC synthesis only; not whole-DUT FIT',
        report=str(REPORT), report_sha256=sha(REPORT), rtl_sha256=mapped['rtl_sha256'],
        tcl_sha256=mapped['tcl_sha256'],
        dcp=dict(path=next(p for p in stage['outputs'] if p.endswith('.dcp')),
                 sha256=stage['outputs'][next(p for p in stage['outputs'] if p.endswith('.dcp'))]),
        map_log=stage['log'], map_returncode=stage['returncode'], resources=resources,
        source_parser=str(C/'controller.py'), shared_parser=str(SHARED),
        root_cause='The parser scans the entire utilization report and overwrites first-section totals with later hierarchy rows of zero; CLB LUTs is also starred in the summary row. The recovered parser keeps the first design-total row per primitive.',
        parser_rows=rows, service_wrapper_error='PermissionError appending CPU_JOB_EXITED to root-owned unattended-opt4/ledger.jsonl after job state COMPLETE and returncode 0',
        cad_rerun=False, full_dut_formal=False, fpga_access=False)
    write(OUT, result)
    print(json.dumps(dict(output=str(OUT), resources=resources, report_sha256=sha(REPORT)), sort_keys=True))

if __name__ == '__main__':
    main()
