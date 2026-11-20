#!/usr/bin/python3
"""Seal completed r4 failures and a separate, unlaunched minimal Tcl repair."""
import hashlib
import json
import re
import subprocess
from datetime import datetime, timezone
from pathlib import Path

HERE = Path(__file__).resolve().parent
D = HERE.parent.parent
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
C = W / 'candidates/svb-host40-shell-recovery-r4-20261112'
R = D / 'cycleprecise-svb-host40-shell-recovery-r4-20261112'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
SID = 'b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f'


def read(path):
    return json.loads(Path(path).read_text())


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for chunk in iter(lambda: f.read(4 * 1024 * 1024), b''):
            h.update(chunk)
    return h.hexdigest()


def save(name, value):
    with (HERE / name).open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n')


def unit_evidence(unit):
    props = dict(line.split('=', 1) for line in subprocess.check_output(
        ['systemctl', 'show', unit, '-p', 'MainPID', '-p', 'ActiveState',
         '-p', 'SubState', '-p', 'ControlGroup', '-p', 'ExecMainStatus'],
        text=True).splitlines() if '=' in line)
    expected = '/system.slice/' + unit
    assert props.get('ControlGroup') in ('', expected)
    cg = Path('/sys/fs/cgroup/systemd') / expected.lstrip('/')
    tasks = sorted({int(v) for p in cg.rglob('cgroup.procs')
                    for v in p.read_text().split()}) if cg.exists() else []
    identities = []
    for pid in tasks:
        proc = Path('/proc') / str(pid)
        fields = (proc / 'stat').read_text().rsplit(')', 1)[1].split()
        groups = (proc / 'cgroup').read_text().splitlines()
        assert any(row.split(':', 2)[1] == 'name=systemd' and
                   (row.split(':', 2)[2] == expected or
                    row.split(':', 2)[2].startswith(expected + '/')) for row in groups)
        identities.append(dict(pid=pid, start_ticks=fields[19],
            host_boot_id=BOOT, process_state=fields[0],
            argv=(proc / 'cmdline').read_bytes().replace(b'\0', b' ').decode()))
    return dict(unit=unit, properties=props, recursive_cgroup_pids=tasks,
                identities=identities)


def timing_evidence(directory):
    text = (directory / 'final-timing.rpt').read_text()
    match = re.search(r'^\s*WNS\(ns\).*?\n\s*-+[^\n]*\n([^\n]+)', text, re.M)
    values = match.group(1).split()
    paths = []
    for match in re.finditer(r'^Slack \(VIOLATED\)[^\n]*', text, re.M):
        row = dict(slack_ns=float(re.search(r'([-0-9.]+)ns', match.group()).group(1)))
        block = text[match.start():match.start() + 9500].splitlines()[:32]
        for line in block:
            for key in ('Source', 'Destination', 'Path Group', 'Path Type',
                        'Requirement', 'Data Path Delay', 'Clock Path Skew'):
                if re.match(r'\s*' + key + ':', line):
                    row[key] = line.split(':', 1)[1].strip()
        paths.append(row)
    routes = (directory / 'route-final.rpt').read_text()
    errors = int(re.search(r'nets with routing errors\.+\s*:\s*(\d+)', routes).group(1))
    drc = (directory / 'drc-final.rpt').read_text()
    warnings = sum(int(x) for x in re.findall(r'^\|[^\n]*\| Warning\s*\|[^\n]*\|\s*(\d+)\s*\|', drc, re.M))
    return dict(wns_ns=float(values[0]), tns_ns=float(values[1]),
                setup_failing_endpoints=int(values[2]), whs_ns=float(values[4]),
                hold_failing_endpoints=int(values[6]), route_errors=errors,
                drc_warning_violations=warnings,
                drc_error_summary_present=bool(re.search(r'^\|[^\n]*\| Error\s*\|', drc, re.M)),
                worst_reported_path=min(paths, key=lambda row: row['slack_ns']))


assert not (HERE / 'complete.json').exists(), 'adopt sealed round122 evidence'
BOOT = Path('/proc/sys/kernel/random/boot_id').read_text().strip()
assert BOOT == 'd6c6e410-10ad-4326-86ba-79b657eabd96'
now = datetime.now(timezone.utc).isoformat()
policy = read(D / 'FPGA_SESSION_POLICY.json')
assert policy['functional_baseline_commit'] == BASE
assert policy['board_allowlist'] == ['0000:21:00.0'] and policy['native_fpga_paused']
assert not policy['functional_extensions_allowed']
physical = read(R / 'state.json')
assert physical['status'] == 'BOUNDED_SHELL_STRATEGIES_FAILED_WITH_ALL_CHECKPOINTS_RETAINED'
assert physical['pid'] == 2561977 and physical['start_ticks'] == '26532915'
assert physical['host_boot_id'] == BOOT and not physical['fpga_access']
services = [unit_evidence('ec-opt4-svb-host40-shell-' + role + '-r4.service')
            for role in ('physical', 'follow', 'application-follow')]
for row in services[:2]:
    assert row['properties']['MainPID'] == '0'
    assert row['properties']['ActiveState'] in ('inactive', 'failed')
    assert not row['recursive_cgroup_pids']
assert services[2]['properties']['MainPID'] == '2561979'
assert services[2]['recursive_cgroup_pids'] == [2561979]
assert services[2]['identities'][0]['start_ticks'] == '26532916'
assert not (D / 'cycleprecise-original-svb-host40-shell-onboard-r4-20261112/deployment.json').exists()

expected = {
    'B-shell-FD-replicate': 'dad45676d3d80cc2d1eb43a89d541bb208758da4a138d827e3b92116d575b052',
    'C-postroute-clock-skew': 'c005f7e3edbaf4bf539e6758128f4868e59bb1777bca6ee580b09e863c93afe6',
    'D-shell-critical-shortest-route': 'a2de13a30bd04ad69798b58f38fc77f490bd91f9c902f9368461a209659ba5b1',
}
results = {}
for name, digest in expected.items():
    path = R / name / 'result.json'
    assert sha(path) == digest
    value = read(path)
    assert value['status'] == 'FAILED_WITH_EVIDENCE' and value['returncode'] == 1
    assert value['source_id'] == SID and value['functional_baseline'] == BASE
    assert not value['bitstream'] and not value['complete_opt4'] and not value['fpga_access']
    item = dict(result=str(path), sha256=digest, completed_utc=value['completed_utc'])
    if name.startswith(('C-', 'D-')):
        item['timing'] = timing_evidence(path.parent)
        assert item['timing']['wns_ns'] < 0
        assert item['timing']['route_errors'] == 0
        assert item['timing']['drc_warning_violations'] == 49
        assert not item['timing']['drc_error_summary_present']
    results[name] = item

cp = R / 'C-postroute-clock-skew/final.dcp'
dp = R / 'D-shell-critical-shortest-route'
c_hash = '51b6ac50f4fd672b6bb118df117a26b62fe478fc857244a81e861c28b5a6dc8c'
assert sha(cp) == c_hash and sha(dp / 'sealed-source.dcp') == c_hash
d_hash = 'fcb957143e064c404044ea2b86607fd508d793f1313b5edef804ea5d0a4b1e62'
assert sha(dp / 'final.dcp') == d_hash
for name in ('final-timing.rpt', 'route-final.rpt', 'drc-final.rpt', 'recover.tcl', 'sealed-inputs.json'):
    path = dp / name
    assert sha(path) == read(dp / 'result.json')['outputs'][str(path)]
assert sha(C / 'inputs.json') == '567b43630a6b15c1fcfcbfdb80fe2830f1965f6cbb2b261c93acc165a6a08e37'
admission = D / 'status-audits/fpga-exclusive-takeover-20261112T030000Z/same-small-svb-slot-measured-readmission.json'
assert sha(admission) == '3b4c46ee3c126741d50e12e1f68a58f99c84c0e249304429c1c66961f293f78b'
installation = read(C / 'installation.json')
for name, digest in installation['units'].items():
    assert sha(Path('/etc/systemd/system') / name) == digest

# Preserve the complete r4 certification gate tail byte for byte. Only the
# previously unsupported strategy is changed, in a new, unlaunched artifact.
strategy = '''if {![llength $observed_nets] || [llength $observed_nets]>32} {error "bounded shell Q selection failed"}
# Vivado 2021.1 rejects forced replication in post-route mode. Retain placement,
# remove routing on this private checkpoint, then apply the original strategy.
route_design -unroute
phys_opt_design -force_replication_on_nets $observed_nets
'''
template = (C / 'recover.tcl.in').read_text()
assert template.count('@STRATEGY@') == 1
repaired = template.replace('@STRATEGY@', strategy.rstrip())
assert repaired.split('snapshot physical\n', 1)[1] == template.split('snapshot physical\n', 1)[1]
assert not any(s in repaired for s in ('create_clock', 'set_false_path', '-retime', 'AddRetime', '-preserve'))
with (HERE / 'recover-preroute-replication.tcl.in').open('x') as f:
    f.write(repaired)
mock = '''set observed_nets {shell_a shell_b}
set operations {}
proc route_design {args} {global operations; if {$args ne "-unroute"} {error "unexpected route command"}; lappend operations unroute}
proc phys_opt_design {args} {global operations; if {$operations ne "unroute"} {error "replication precedes unroute"}; if {[lindex $args 0] ne "-force_replication_on_nets"} {error "wrong physical operation"}; lappend operations replicate}
''' + strategy + '''if {$operations ne "unroute replicate"} {error "operation order"}
puts PASS_TCL_CONTROL_FLOW_ONLY_NO_VIVADO_CERTIFICATION
'''
check = subprocess.run(['/usr/bin/tclsh'], input=mock, text=True, capture_output=True, check=True)
assert check.stdout.strip() == 'PASS_TCL_CONTROL_FLOW_ONLY_NO_VIVADO_CERTIFICATION'
save('repair-plan.json', dict(
    schema='ec-svb-host40-preroute-replication-preparation/1',
    status='PREPARED_UNLAUNCHED_REQUIRES_EXISTING_AUTHORIZED_ADMINISTRATOR',
    functional_baseline=BASE, source_id=SID, profile='OriginalSVB32-component-trace-host40',
    checkpoint=str(cp), checkpoint_sha256=c_hash,
    prerequisite_results=results, resource_admission=str(admission), resource_admission_sha256=sha(admission),
    template=str(HERE / 'recover-preroute-replication.tcl.in'),
    template_sha256=sha(HERE / 'recover-preroute-replication.tcl.in'),
    change='Remove routing on a private copy of best C checkpoint before previously unsupported B forced-replication command; full strict gate tail unchanged.',
    prelaunch_requirements=[
        'Existing authorized administrator installs independently versioned physical/certificate/21-only runtime binding; never reinstall r4 or priority handoff.',
        'Reverify exact r4 producer PID/start_ticks/boot_id dead and exact recursive cgroup empty; acquire existing extra-component-slot.lock for the full CAD lifetime.',
        'Reverify 192GiB available/load<128/disk>=150GiB; max3 existing component Vivados; CPUs224,225;64GiB cap; no whole launch.',
        'Independently bind new result and certificate; all clocks/setup/hold/route/DRC/pulse/skew/target/software/hash gates remain required before directed then same-bit application replay on21 only.',
    ],
    validation=dict(tcl_control_flow=check.stdout.strip(), strict_gate_tail_identical=True,
                    actual_vivado_execution=False, command_support_after_unroute_unproven=True),
    installed=False, queued=False, launched=False, fpga_access=False,
    root_operations=[], process_signals=[], target_rtl_changed=False, complete_opt4=False))

save('closure.json', dict(
    schema='ec-round122-r4-failure-closure/1', utc=now, host_boot_id=BOOT,
    status='R4_BCD_EXHAUSTED_NO_CERTIFIED_BITSTREAM', results=results,
    best_checkpoint=dict(path=str(cp), sha256=c_hash, wns_ns=-0.411),
    rejected_D_checkpoint=dict(path=str(dp / 'final.dcp'), sha256=d_hash, wns_ns=-0.503),
    C_to_D_sealed_input_sha256=c_hash, services=services,
    physical_state=physical, r4_input_manifest_sha256=sha(C / 'inputs.json'),
    r4_units_unchanged=True, live_inputs_changed=False, root_operations=[], process_signals=[],
    newly_launched_jobs=[], fpga_samples=0, certified_bitstream=False,
    earlier_this_round_identity_checks=dict(
        capacity=dict(pid=2379656, start_ticks='25825451', exact_cgroup='/system.slice/ec-opt4-auto-mcrams-full-host-capacity-r1-3656aec4.service'),
        owner_mc=dict(pid=2378806, start_ticks='25817526', exact_cgroup='/system.slice/ec-opt4-auto-owner-mc-runtime-r2-3656aec4.service'),
        priority=dict(pid=2551972, start_ticks='26486048', exact_cgroup='/system.slice/ec-opt4-fpga-priority-handoff-r1.service'),
        r51=dict(pid=2323399, start_ticks='25276450'), resumed_r3=dict(pid=2377613, start_ticks='25815969'),
        note='All matched live boot/PID/start_ticks and exact recursive service cgroups earlier this round. Whole CAD checks are not repeated here.'),
    scope='Original SVB component only; no complete EC FPGA/FIT/sample claim. CPU comparison consumers untouched.'))

report = '''r4 B/C/D exhausted; certification remains unavailable.

C: WNS -0.411ns, TNS -292.970ns, 2130 setup failures; WHS +0.001ns.
D: WNS -0.503ns, TNS -343.017ns, 2299 setup failures; WHS +0.001ns.
Both retain final checkpoints, zero routing errors and 49 warning DRC violations.
B failed because Vivado 2021.1 rejects forced replication in post-route mode.

Proven immediate blocker: negative setup slack. Proven worst-path observations:
C XDMA reset-to-reset pin, 96.792% routing delay; D width-converter-to-DDR
enable, 92.066% routing delay. These observations do not prove that the prepared
replication repair will fix timing. C remains the best completed checkpoint.

Prepared a separate Tcl repair: unroute a private checkpoint before the original
B forced-replication command. The entire reporting/strict certification gate tail
is identical to r4. Tcl mock validates command ordering only; actual Vivado support
and timing improvement remain unproven. Preparation is neither queued nor launched.
Root service installation belongs to the existing authorized administrator.

r4 physical and directed follower exited with exact empty cgroups. Its application
waiter remains one matched idle Python. No process was stopped or signalled.
Existing r51/resumed-r3 routes, MCRams full-host capacity, owner-MC parity, and
priority handoff were matched live during this round and remain under their owners.
No LUT/FIT result is inferred for MCRams. Existing continuations automatically
consume their actual completed outputs. Recheck components >=300s, whole CAD >=600s.
'''
with (HERE / 'REPORT.md').open('x') as f:
    f.write(report)
files = {str(p): sha(p) for p in sorted(HERE.iterdir()) if p.is_file()}
save('complete.json', dict(schema='ec-round-evidence-seal/1', utc=datetime.now(timezone.utc).isoformat(),
    files=files, no_fpga_io=True, no_process_signals=True, hardware_success=False))
print(json.dumps(dict(audit=str(HERE), closure_sha256=sha(HERE / 'closure.json'),
    complete_sha256=sha(HERE / 'complete.json'), repair_sha256=sha(HERE / 'repair-plan.json'),
    outcome='RECOVERABLE_FAILURE', launched_jobs=[])))
