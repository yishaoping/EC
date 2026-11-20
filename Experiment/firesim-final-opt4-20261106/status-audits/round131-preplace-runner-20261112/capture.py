#!/usr/bin/python3
"""One bounded continuity capture; never controls processes or devices."""
import datetime
import hashlib
import json
from pathlib import Path
import re
import shutil
import subprocess

D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
A = Path(__file__).resolve().parent
PREV = D / 'status-audits/round130-preplace-exception-contract-20261112/continuity.json'
previous = json.loads(PREV.read_text())
boot = Path('/proc/sys/kernel/random/boot_id').read_text().strip()


def sha(data):
    return hashlib.sha256(data).hexdigest()


def save(path, data):
    with path.open('xb') as handle:
        handle.write(data)


record = dict(schema='ec-round131-bounded-continuity/1',
              observed_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
              host_boot_id=boot, states={}, processes={}, logs={}, capacity_outputs={},
              bound_sources={}, CPU_comparison_controls=[], fpga_operations=[],
              new_production_jobs=[], new_requests=[])
paths = [
    'cycleprecise-svb-host40-shell-recovery-r5-20261112/state.json',
    'cycleprecise-original-svb-host40-shell-onboard-r5-20261112/state.json',
    'cycleprecise-original-svb-host40-shell-application-onboard-r5-20261112/state.json',
    'Opt4-mcrams-full-host-capacity-r1-state.json',
    'Opt4-mcrams-full-host-continuation-r2-state.json',
    'Opt4-mcrams-owner-mc-runtime-r2-state.json',
    'mcrams-shell-ipcollateral-r4b-observer-20261112/state.json',
    'fpga-priority-handoff-r1-20261112/state.json',
    'unattended-opt4/jobs/svb-application-fpga-metrics-r1-8491167d/state.json',
]
for index, name in enumerate(paths):
    path = D / name
    if path.exists():
        data = path.read_bytes()
        save(A / ('state-copy-' + str(index) + '.json'), data)
        state = json.loads(data)
        record['states'][name] = dict(source=str(path), sha256=sha(data),
            **{key: state.get(key) for key in ['status', 'pid', 'start_ticks', 'host_boot_id',
                  'source_id', 'continuation_revision', 'updated_utc', 'stage', 'current_stage',
                  'reports', 'full_host_fit']})

for pid, expected in previous['processes'].items():
    proc = Path('/proc') / pid
    try:
        stat = (proc / 'stat').read_text().rsplit(')', 1)[1].split()
        groups = (proc / 'cgroup').read_text().splitlines()
        group = next((row.split(':', 2)[2] for row in groups if ':name=systemd:' in row), '')
        current = dict(pid=int(pid), start_ticks=stat[19], host_boot_id=boot, state=stat[0],
                       cpu_ticks=int(stat[11]) + int(stat[12]), cgroup=group,
                       argv=(proc / 'cmdline').read_bytes().replace(b'\0', b' ').decode())
        current['matches_previous_identity_and_exact_cgroup'] = all(
            str(current[key]) == str(expected[key]) for key in ['pid', 'start_ticks', 'host_boot_id', 'cgroup'])
        current['cpu_ticks_since_round130'] = current['cpu_ticks'] - expected['cpu_ticks']
        record['processes'][pid] = current
    except FileNotFoundError:
        record['processes'][pid] = dict(pid=int(pid), exists=False)

units = sorted({row['cgroup'].rsplit('/', 1)[-1] for row in record['processes'].values() if row.get('cgroup')})
record['services'] = subprocess.check_output(['systemctl', 'show', *units,
    '-p', 'Id', '-p', 'MainPID', '-p', 'ActiveState', '-p', 'SubState', '-p', 'ControlGroup'], text=True)

for name, limit, label in [
        ('cycleprecise-svb-host40-shell-recovery-r5-20261112/E-preroute-shell-replication/vivado.log', 16000, 'r5'),
        ('build-logs/Opt4-mcrams-full-host-capacity-r1-20261112/run.log', 6000, 'capacity')]:
    path = D / name
    with path.open('rb') as handle:
        handle.seek(max(0, path.stat().st_size - limit))
        tail = handle.read(limit)
    save(A / (label + '-bounded-tail.log'), tail)
    record['logs'][label] = dict(source=str(path), bytes=path.stat().st_size,
        mtime_ns=path.stat().st_mtime_ns, tail_sha256=sha(tail))
    if label == 'r5':
        text = tail.decode(errors='replace')
        overlaps = re.findall(r'Number of Nodes with overlaps\s*=\s*(\d+)', text)
        timing = re.findall(r'Intermediate Timing Summary[^\n]*', text)
        record['logs'][label].update(latest_overlap=int(overlaps[-1]) if overlaps else None,
            latest_intermediate_timing=timing[-1] if timing else None,
            intermediate_is_final=False)

for prefix, names in [
        ('build-logs/Opt4-mcrams-full-host-capacity-r1-20261112',
         ['synth-utilization.rpt', 'postopt-utilization.rpt', 'result.json', 'postopt.dcp']),
        ('build-logs/Opt4-mcrams-full-host-continuation-r2-20261112',
         ['early-synth-capacity.json', 'early-postopt-capacity.json'])]:
    for name in names:
        path = D / prefix / name
        detail = dict(exists=path.exists())
        if path.exists():
            detail['bytes'] = path.stat().st_size
            if path.suffix in ['.json', '.rpt']:
                data = path.read_bytes()
                save(A / ('capacity-' + name), data)
                detail['sha256'] = sha(data)
                if path.suffix == '.json':
                    detail['result'] = json.loads(data)
        record['capacity_outputs'][str(path)] = detail

for group, pins in previous['bound_sources'].items():
    record['bound_sources'][group] = {}
    for path, expected in pins.items():
        digest = sha(Path(path).read_bytes())
        assert digest == expected, ('bound source changed', path)
        record['bound_sources'][group][path] = digest

parity = Path(previous['finite_parity_result']['source'])
data = parity.read_bytes()
assert sha(data) == previous['finite_parity_result']['sha256']
save(A / 'owner-MC-result.json', data)
record['finite_parity_result'] = dict(source=str(parity), sha256=sha(data),
    status=json.loads(data)['status'])
mem = next(int(line.split()[1]) for line in Path('/proc/meminfo').read_text().splitlines() if line.startswith('MemAvailable:'))
record['resources'] = dict(available_memory_gib=round(mem / 2**20, 2),
                          free_disk_gib=round(shutil.disk_usage(D).free / 2**30, 2),
                          loadavg=Path('/proc/loadavg').read_text().strip())
save(A / 'continuity.json', (json.dumps(record, indent=2, sort_keys=True) + '\n').encode())
print(json.dumps(dict(observed_utc=record['observed_utc'], r5=record['logs']['r5'],
    capacity_status=record['states']['Opt4-mcrams-full-host-capacity-r1-state.json']['status'],
    capacity_outputs=record['capacity_outputs'],
    all_previous_live_identities_match=all(p.get('matches_previous_identity_and_exact_cgroup') for p in record['processes'].values()),
    bound_sources_unchanged=True, resources=record['resources'])))
