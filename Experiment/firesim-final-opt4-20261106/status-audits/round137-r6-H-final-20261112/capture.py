#!/usr/bin/env python3
"""Pin completed H evidence and adopt existing I; never invoke CAD or devices."""
import collections
import datetime
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess

B = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path('/data1/gzh/EC/firesim/final-opt4-20261106/candidates/svb-r5-routed-repair-r6-20261112')
A = Path(__file__).resolve().parent
H = B/'cycleprecise-svb-host40-shell-recovery-r6-20261112/H-postroute-placement-critical-cell'
BOOT = Path('/proc/sys/kernel/random/boot_id').read_text().strip()


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for chunk in iter(lambda: f.read(4*1024*1024), b''):
            h.update(chunk)
    return h.hexdigest()


def read(path):
    return json.loads(Path(path).read_text())


def save(path, data):
    with Path(path).open('x') as f:
        json.dump(data, f, indent=2, sort_keys=True)
        f.write('\n')


def identity(pid, expected_start=None, expected_cgroup=None):
    p = Path('/proc')/str(pid)
    stat = (p/'stat').read_text()
    fields = stat[stat.rfind(')')+2:].split()
    groups = [line.split(':', 2)[2] for line in (p/'cgroup').read_text().splitlines()]
    if expected_start is not None:
        assert fields[19] == expected_start, (pid, 'start_ticks')
    if expected_cgroup is not None:
        assert expected_cgroup in groups, (pid, 'exact cgroup')
    return dict(pid=pid, start_ticks=fields[19], host_boot_id=BOOT,
                process_state=fields[0], cpu_ticks=int(fields[11])+int(fields[12]),
                argv=[v.decode() for v in (p/'cmdline').read_bytes().split(b'\0') if v],
                exact_cgroups=sorted(set(groups)), expected_cgroup=expected_cgroup)


assert not (A/'receipt.json').exists(), 'immutable audit already exists'
r = read(H/'result.json')
assert r['status'] == 'FAILED_WITH_EVIDENCE' and r['returncode'] == 1
assert r['timing'] == dict(wns=-0.02, tns=-0.447, setup_failing=45,
                         whs=0.001, ths=0.0, hold_failing=0)
assert r['bitstream'] is None and r['bitstream_sha256'] is None
assert not (H/'original-svb-host40.bit').exists()
assert not (H/'complete.json').exists()

# Verify only newly completed H outputs. Existing 95-input validation is reused.
files = {}
for name, digest in r['outputs'].items():
    p = Path(name)
    before = p.stat()
    actual = sha(p)
    after = p.stat()
    assert actual == digest and (before.st_size, before.st_mtime_ns) == (after.st_size, after.st_mtime_ns), name
    item = dict(source=str(p), sha256=actual, bytes=after.st_size, source_mtime_ns=after.st_mtime_ns)
    if p.suffix != '.dcp':
        dest = A/('H-'+p.name)
        shutil.copyfile(p, dest)
        assert sha(dest) == actual
        item['copy'] = str(dest)
    files[p.name] = item
shutil.copyfile(H/'result.json', A/'H-result.json')
files['result.json'] = dict(source=str(H/'result.json'), copy=str(A/'H-result.json'), sha256=sha(A/'H-result.json'))

summary = (H/'final-timing.rpt').read_text()
m = re.search(r'WNS\(ns\).*?\n\s*[-\s]+\n\s*([-\d.]+)\s+([-\d.]+)\s+(\d+)\s+\d+\s+([-\d.]+)\s+([-\d.]+)\s+(\d+)', summary)
assert m and [float(m[1]), float(m[2]), int(m[3]), float(m[4]), float(m[5]), int(m[6])] == [-0.02, -0.447, 45, 0.001, 0.0, 0]
negative = (H/'negative-setup-final.rpt').read_text()
paths = {}
for label in ['Source', 'Destination', 'Path Group', 'Path Type', 'Requirement', 'Logic Levels']:
    vals = re.findall(r'^\s*'+re.escape(label)+r'\s*:\s*(.*)$', negative, re.M)
    assert len(vals) == 45, label
    paths[label] = dict(count=len(vals), distribution=dict(collections.Counter(vals)))
assert all(x.startswith('design_1_i/xdma_0/') for label in ['Source', 'Destination'] for x in paths[label]['distribution'])
assert paths['Path Group']['distribution'] == {'GTYE4_CHANNEL_TXOUTCLK[3]_3': 45}
save(A/'H-failing-paths.json', paths)
checks = dict((k, int(v)) for k, v in re.findall(r'checking (\w+) \((\d+)\)', (H/'check-timing.rpt').read_text()))
assert checks['no_clock'] == checks['unconstrained_internal_endpoints'] == 0
route = (H/'route-final.rpt').read_text()
route_counts = {k: int(re.search(re.escape(k)+r'\.+\s*:\s*(\d+)', route)[1]) for k in ['# of routable nets', '# of fully routed nets', '# of nets with routing errors']}
assert route_counts == {'# of routable nets': 255876, '# of fully routed nets': 255876, '# of nets with routing errors': 0}
drc = (H/'drc-final.rpt').read_text()
drc_rows = re.findall(r'^\|\s*(\S+)\s*\|\s*(Warning|Error|Critical Warning)\s*\|.*?\|\s*(\d+)\s*\|', drc, re.M)
assert drc_rows and sum(int(n) for _, _, n in drc_rows) == 49
assert all(severity == 'Warning' for _, severity, _ in drc_rows)
assert 'setup/hold gate failed; candidate retained for next strategy' in (H/'vivado.log').read_text()

previous = read(B/'status-audits/round134-r6-installer-scope-repair-20261112/r6-source-verification.json')
source_changes = [p for p, digest in previous['sources'].items() if sha(p) != digest]
assert not source_changes
save(A/'source-continuity.json', dict(status='UNCHANGED_R6_SOURCE_HASHES',
     prior_validation=str(B/'status-audits/round134-r6-installer-scope-repair-20261112/r6-source-verification.json'),
     prior_validation_sha256=sha(B/'status-audits/round134-r6-installer-scope-repair-20261112/r6-source-verification.json'),
     unchanged_source_count=len(previous['sources']), bound_input_revalidation_repeated=False,
     source_changes=source_changes))

services = []
for unit, rel in [
    ('ec-opt4-svb-host40-shell-physical-r6.service', 'cycleprecise-svb-host40-shell-recovery-r6-20261112/state.json'),
    ('ec-opt4-svb-host40-shell-follow-r6.service', 'cycleprecise-original-svb-host40-shell-onboard-r6-20261112/state.json'),
    ('ec-opt4-svb-host40-shell-application-follow-r6.service', 'cycleprecise-original-svb-host40-shell-application-onboard-r6-20261112/state.json'),
]:
    raw = (B/rel).read_bytes()
    s = json.loads(raw)
    assert s['host_boot_id'] == BOOT
    ident = identity(s['pid'], s['start_ticks'], '/system.slice/'+unit)
    props = subprocess.check_output(['systemctl', 'show', unit, '--property=MainPID,ControlGroup,ActiveState,SubState,MemoryMax,AllowedCPUs,ExecMainStartTimestampMonotonic'], text=True)
    prop = dict(line.split('=', 1) for line in props.splitlines() if '=' in line)
    assert prop['ActiveState'] == 'active' and int(prop['MainPID']) == s['pid']
    assert prop['ControlGroup'] == '/system.slice/'+unit
    (A/(unit+'.state.json')).write_bytes(raw)
    group = Path('/sys/fs/cgroup/systemd')/prop['ControlGroup'].lstrip('/')
    pids = {int(x) for f in group.rglob('cgroup.procs') for x in f.read_text().split()}
    members = [identity(pid, expected_cgroup=prop['ControlGroup']) for pid in sorted(pids)]
    if 'physical-r6' in unit:
        assert s['mode'] == 'I-postroute-clock-skew', 'stage changed; preserve this audit and inspect after cadence'
        vivados = [x for x in members if x['argv'] and x['argv'][0].endswith('/unwrapped/lnx64.o/vivado')]
        assert len(vivados) == 1 and '/I-postroute-clock-skew/' in ' '.join(vivados[0]['argv'])
        current = dict(mode=s['mode'], identity=vivados[0],
                       intermediate_timing=s.get('latest_timing'), intermediate_is_final=False)
    services.append(dict(unit=unit, identity=ident, systemd=prop, members=members,
                         state_sha256=hashlib.sha256(raw).hexdigest(), status=s['status']))
save(A/'r6-live-adoption.json', dict(utc=datetime.datetime.now(datetime.timezone.utc).isoformat(), services=services, current=current))

metrics_unit = 'ec-opt4-auto-svb-application-fpga-metrics-r1-8491167d.service'
metrics = read(B/'svb-application-fpga-metrics-r1-20261112/state.json')
metrics_ident = identity(metrics['pid'], metrics['start_ticks'], '/system.slice/'+metrics_unit)
save(A/'metrics-singleton.json', dict(status='RUNNING_NOT_QUEUED', consumer_status=metrics['status'], identity=metrics_ident,
     request=str(B/'unattended-opt4/requests/svb-application-fpga-metrics-r1-8491167d.json'), request_duplicated=False))

next_action = ('Preserve existing r6 I then conditional J-postroute-targeted-delay-reroute; '
               'require complete timing/route/DRC/pulse/skew and independent certification before existing '
               '21-only directed and same-bit application replay. Preserve original complete MCrams capacity '
               'and r3 continuation/r4b observer, metrics singleton and memory guards; no new whole CAD.')
receipt = dict(schema='ec-opt4-round137-r6-H-final/1', round=137,
    utc=datetime.datetime.now(datetime.timezone.utc).isoformat(), status='H_FINAL_FAILURE_PINNED_EXISTING_I_ADOPTED',
    functional_baseline=r['functional_baseline'], source_id=r['source_id'], profile=r['profile'],
    H_result=files['result.json'], H_completed_utc=r['completed_utc'], H_final_timing=r['timing'],
    H_outputs=files, H_final_checkpoint=files['final.dcp'],
    H_route_counts=route_counts, H_drc_summary=drc_rows, H_check_timing=checks,
    H_failure=dict(symptom='PROVEN_45_FINAL_SETUP_FAILURES', blocking_condition='PROVEN_SETUP_HOLD_GATE_REJECTED',
      location='PROVEN_ALL_45_REPORTED_PATHS_INSIDE_XDMA_PCIE_GROUP_GTYE4_CHANNEL_TXOUTCLK[3]_3',
      upstream_causal_trigger='UNPROVEN_PHYSICAL_PATH_TIMING_REMAINS_NEGATIVE', downstream_amplifier='UNPROVEN'),
    current=current, J_status='CONDITIONAL_IN_EXISTING_CONTROLLER_NOT_SEPARATE_JOB',
    certified_bitstream=False, FPGA_samples=0, FPGA_operations=[], CPU_comparison_controls=[],
    launched_jobs=[], new_requests=[], process_signals=[], bound_source_changes=[],
    existing_metrics='RUNNING_NOT_QUEUED_WAITING_EXACT_R5_RECEIPTS',
    original_MCrams='PRESERVED_ORIGINAL_PID2379656_START25825451_POSTOPT_PENDING_AT_INITIAL_09:36_CHECK',
    next_automatic_action=next_action, normal_CAD_recheck_seconds=300, whole_CAD_recheck_seconds=600)
save(A/'receipt.json', receipt)

# Publish a narrowly scoped durable handoff; leave all source and gate bindings alone.
policy = B/'unattended-opt4/campaign-policy.json'
before = policy.read_bytes()
p = json.loads(before)
shutil.copyfile(policy, A/'campaign-policy.before.json')
update = dict(result=str(A/'receipt.json'), result_sha256=sha(A/'receipt.json'), H_status=r['status'],
              H_final_timing=r['timing'], existing_I_pid=current['identity']['pid'],
              existing_I_start_ticks=current['identity']['start_ticks'], next_automatic_action=next_action)
p['latest_p0_result_update'] = update
p['latest_worker_execution_report'] = str(A/'receipt.json')
p['foreground_request_for_next_worker'] = (
    'Round137 pinned r6 H completed FAILED setup WNS-0.020/WHS+0.001 TNS-0.447/45setup, '
    'all45 inside XDMA PCIe group GTYE4_CHANNEL_TXOUTCLK[3]_3; route255876/255876 errors0, '
    '49DRCwarnings/noError, no_clock0/unconstrained_internal0; no bitstream. '
    'FinalDCP805d75337e5d6c25e4d4730bec9d8f415456127e18bd7a29e3d5eccd54da7c8d. '
    f"Existing r6 I actualVivado PID{current['identity']['pid']}/start{current['identity']['start_ticks']} "
    'matched boot_id/exact physical-r6 cgroup; I intermediate timing is not final. '
    'Preserve I->conditionalJ and all certification/replay gates. Metrics original singleton RUNNING, '
    'not queued; do not duplicate/edit. Original MCrams capacity still awaiting authoritative postopt '
    'at initial09:36 check; preserve it, r3 continuation and r4b observer. '
    'NormalCAD>=300s/whole>=600s. Evidence: '+str(A/'receipt.json'))
assert policy.read_bytes() == before, 'policy changed concurrently; receipt remains valid'
tmp = policy.with_name('campaign-policy.round137.tmp')
tmp.write_text(json.dumps(p, indent=2, sort_keys=True)+'\n')
os.replace(tmp, policy)
shutil.copyfile(policy, A/'campaign-policy.after.json')
save(A/'publication.json', dict(receipt_sha256=sha(A/'receipt.json'),
    policy_before_sha256=hashlib.sha256(before).hexdigest(), policy_after_sha256=sha(policy),
    changed_policy_keys=['latest_p0_result_update', 'latest_worker_execution_report', 'foreground_request_for_next_worker']))
print(json.dumps(dict(receipt=str(A/'receipt.json'), receipt_sha256=sha(A/'receipt.json'),
                     H_final_timing=r['timing'], current_I_pid=current['identity']['pid'],
                     current_I_start_ticks=current['identity']['start_ticks'], H_outputs_verified=len(files)-1)))
