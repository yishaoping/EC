#!/usr/bin/env python3
"""Read one post-opt completion event and compare matching-stage reports.

No CAD invocation, clock/RTL changes, implementation gate or periodic polling.
The owned build's exit also wakes the collector if the stage fails early.
"""
import argparse
import ctypes
import hashlib
import json
import os
from pathlib import Path
import re
import select

HERE = Path(__file__).resolve().parent
NEW = Path('/var/tmp/guozh-ec-checker-fault-20261117/full-r2')
OLD = Path('/var/tmp/guozh-ec-rtl-timing-r2-20261115/full-combined-qualified')
METRICS = ['CLB LUTs', 'CLB Registers', 'Register as Flip Flop', 'F7 Muxes',
           'F8 Muxes', 'F9 Muxes', 'Block RAM Tile', 'URAM', 'LUT as Memory']


def sha(p):
    return hashlib.sha256(p.read_bytes()).hexdigest()


def save(p, row):
    temp = p.with_suffix('.tmp')
    temp.write_text(json.dumps(row, indent=2) + '\n')
    temp.replace(p)


def utilization(path):
    found = {}
    for line in path.read_text().splitlines():
        fields = [v.strip() for v in line.split('|')]
        if len(fields) < 4:
            continue
        label = fields[1].rstrip('*')
        if label in METRICS and label not in found:
            found[label] = float(fields[2].replace(',', ''))
    assert all(k in found for k in METRICS), (path, found)
    return found


def fanout(path):
    rows = []
    for line in path.read_text().splitlines():
        fields = [v.strip() for v in line.split('|')]
        if len(fields) == 5 and fields[2].isdigit():
            rows.append(dict(net=fields[1], fanout=int(fields[2]), driver=fields[3]))
    return rows


def compare():
    receipt = json.loads((NEW/'implementation-result.json').read_text())
    assert receipt['returncode'] == 0
    for path, digest in receipt['outputs'].items():
        # Large checkpoint hash was checked by the owner; compare report hashes
        # here without competing for memory/disk bandwidth with placement.
        p = Path(path)
        if p.suffix == '.rpt':
            assert sha(p) == digest
    before = utilization(OLD/'top-postopt-utilization.rpt')
    after = utilization(NEW/'top-postopt-utilization.rpt')
    assert before['CLB LUTs'] == 824809 and before['CLB Registers'] == 448466
    rows = {k:dict(before=before[k], after=after[k], delta=after[k]-before[k],
            delta_percent=100*(after[k]-before[k])/before[k] if before[k] else None) for k in METRICS}
    evidence = {}
    details = {}
    for label, root in [('before', OLD), ('after', NEW)]:
        for name in ['top-postopt-utilization.rpt', 'top-postopt-hierarchical.rpt',
                     'top-postopt-fanout.rpt', 'top-postopt-slr-utilization.rpt']:
            p = root/name
            if p.exists():
                evidence[str(p)] = sha(p)
        details[label] = dict(top_reported_fanout=fanout(root/'top-postopt-fanout.rpt'),
            csr_rsu_hierarchy_rows=[line.strip() for line in (root/'top-postopt-hierarchical.rpt').read_text().splitlines()
                if re.search(r'\|\s*(csr|rsu_master|\(csr\)|\(rsu_master\))\s*\|', line)])
    result = dict(status='COMPARED_COMPLETE_SHELL_POSTOPT_SAME_CONFIGURATION',
        profile='EC Performance-Only', phase='post-opt, unplaced', metrics=rows,
        evidence=evidence, details=details,
        physical_congestion='Not measurable from unplaced post-opt; use placed congestion and per-SLR reports',
        csr_rsu_fanout_limit='Top 80 nets only; absence of metadata names does not prove their exact fanout',
        cad_access=False, periodic_patrol=False)
    save(HERE/'postopt-comparison.json', result)
    lines = ['# Performance-Only CSR/RSU repair: matching post-opt comparison', '',
             '| Metric | Before | After | Delta |', '|---|---:|---:|---:|']
    for key, row in rows.items():
        lines.append(f'| {key} | {row["before"]:g} | {row["after"]:g} | {row["delta"]:+g} |')
    lines += ['', result['physical_congestion'], '', result['csr_rsu_fanout_limit'], '']
    (HERE/'postopt-comparison.md').write_text('\n'.join(lines))
    return result


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--build-pid', type=int, required=True)
    parser.add_argument('--start-ticks', required=True)
    a = parser.parse_args()
    # Inotify is an event subscription; no repeated status queries or timer.
    lib = ctypes.CDLL(None, use_errno=True)
    fd = lib.inotify_init1(os.O_CLOEXEC | os.O_NONBLOCK)
    assert fd >= 0
    assert lib.inotify_add_watch(fd, os.fsencode(NEW), 0x80) >= 0  # atomic receipt MOVED_TO only
    receipt = NEW/'implementation-result.json'
    if not receipt.exists():
        pidfd = os.pidfd_open(a.build_pid)
        p = Path('/proc', str(a.build_pid))
        assert p.joinpath('stat').read_text().rsplit(') ', 1)[1].split()[19] == a.start_ticks
        assert b'/physical.py\0' in p.joinpath('cmdline').read_bytes()
        poll = select.poll()
        poll.register(fd, select.POLLIN)
        poll.register(pidfd, select.POLLIN)
        save(HERE/'comparison-state.json', dict(status='WAITING_POSTOPT_COMPLETION_EVENT',
            owner_pid=a.build_pid, periodic_patrol=False, cad_access=False))
        while not receipt.exists():
            events = poll.poll()
            if any(key == pidfd for key, _ in events) and not receipt.exists():
                save(HERE/'comparison-state.json', dict(status='BUILD_EXITED_BEFORE_POSTOPT',
                    periodic_patrol=False, cad_access=False))
                return
            if any(key == fd for key, _ in events):
                os.read(fd, 65536)
        os.close(pidfd)
    result = compare()
    save(HERE/'comparison-state.json', dict(status=result['status'], periodic_patrol=False, cad_access=False))


if __name__ == '__main__':
    main()
