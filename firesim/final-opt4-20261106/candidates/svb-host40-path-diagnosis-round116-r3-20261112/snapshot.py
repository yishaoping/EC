#!/usr/bin/python3
"""Seal exact known-service identities and a report-bound round116 handoff."""
from pathlib import Path
import datetime
import hashlib
import json
import os
import re
import shutil
import subprocess

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
OUT = D / 'status-audits/opt4-round116-host40-paths-20261112'
ANALYSIS = D / 'build-logs/Opt4-svb-host40-path-diagnosis-round116-r3-20261112'


def sha(data):
    return hashlib.sha256(data).hexdigest()


def save(path, value):
    tmp = path.with_name(path.name + '.tmp-' + str(os.getpid()))
    with tmp.open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())
    os.replace(tmp, path)


def main():
    policy_raw = (D / 'unattended-opt4/campaign-policy.json').read_bytes()
    policy = json.loads(policy_raw)
    assert policy['functional_baseline_commit'] == '8491167d84b6d9521b151a743673c1516926a1f8'
    assert policy['native_paused'] and not policy['fpga_access'] and not policy['functional_extensions_allowed']
    assert policy['board_allowlist'] == ['0000:21:00.0']
    assert not OUT.exists(), 'preserve completed or partial snapshots'
    OUT.mkdir()
    boot = Path('/proc/sys/kernel/random/boot_id').read_text().strip()

    def identity(pid):
        try:
            p = Path('/proc') / str(pid)
            stat = (p / 'stat').read_text().rsplit(')', 1)[1].split()
            return dict(pid=int(pid), start_ticks=stat[19], host_boot_id=boot, process_state=stat[0],
                        cpu_ticks=int(stat[11]) + int(stat[12]),
                        comm=(p / 'comm').read_text().strip(), affinity=sorted(os.sched_getaffinity(int(pid))))
        except (FileNotFoundError, ProcessLookupError):
            return None

    paths = ['Opt4-svb-physical-resume-r3-state.json',
             'Opt4-svb-physical-resource-recovery-round51-v1-state.json',
             'Opt4-svb-physical-pinreplicate-r4-state.json', 'Opt4-svb-host40-physical-r1-state.json',
             'Opt4-mcrams-full-host-capacity-r1-state.json', 'Opt4-mcrams-full-host-continuation-r2-state.json',
             'Opt4-mcrams-owner-mc-runtime-r2-state.json', 'Opt4-mcrams-address-bucket-area-r2-state.json',
             'Opt4-fit-update-share-svb-cad-state.json', 'Opt4-matched-single-boom-gg-r3-state.json',
             'Opt4-owner-complete-transport-round114-r2-state.json']
    for version in (2, 3):
        paths.extend([f'cycleprecise-svb-host40-shell-recovery-r{version}-20261112/state.json',
                      f'cycleprecise-original-svb-host40-shell-onboard-r{version}-20261112/state.json',
                      f'cycleprecise-original-svb-host40-shell-application-onboard-r{version}-20261112/state.json'])
    states = {}
    for rel in paths:
        raw = (D / rel).read_bytes()
        state = json.loads(raw)
        actual = identity(state['pid']) if state.get('pid') else None
        live = bool(actual and actual['process_state'] not in ('Z', 'X') and
                    str(actual['start_ticks']) == str(state.get('start_ticks')) and
                    actual['host_boot_id'] == state.get('host_boot_id'))
        states[rel] = dict(state=state, state_sha256=sha(raw), actual_controller=actual, identity_live=live)

    units = ['ec-opt4-auto-svb-physical-resource-recovery-r51-v1.service',
             'ec-opt4-auto-svb-physical-resume-r3-v1-8491167d.service',
             'ec-opt4-auto-svb-physical-pinreplicate-r4-v1-8491167d.service',
             'ec-opt4-svb-host40-physical-r1.service',
             'ec-opt4-auto-mcrams-full-host-capacity-r1-3656aec4.service',
             'ec-opt4-mcrams-owner-runtime-follow-r1.service',
             'ec-opt4-auto-address-bucket-mcrams-area-r2-8491167d.service',
             'ec-opt4-auto-mcrams-host-continuation-r2-3656aec4.service']
    for version in (2, 3):
        units.extend([f'ec-opt4-svb-host40-shell-physical-r{version}.service',
                      f'ec-opt4-svb-host40-shell-follow-r{version}.service',
                      f'ec-opt4-svb-host40-shell-application-follow-r{version}.service'])
    services, components = {}, []
    for unit in units:
        text = subprocess.check_output(['systemctl', 'show', unit, '-p', 'MainPID', '-p', 'ActiveState',
            '-p', 'SubState', '-p', 'ControlGroup', '-p', 'AllowedCPUs', '-p', 'MemoryMax'], text=True)
        props = dict(line.split('=', 1) for line in text.splitlines() if '=' in line)
        group = Path('/sys/fs/cgroup/systemd/system.slice') / unit
        tasks = sorted({int(pid) for p in group.rglob('cgroup.procs') for pid in p.read_text().split()}) if group.exists() else []
        workers = []
        for pid in tasks:
            actual = identity(pid)
            if not actual:
                continue
            try:
                command = (Path('/proc') / str(pid) / 'cmdline').read_bytes().split(b'\0')
            except FileNotFoundError:
                continue
            actual['vivado_worker'] = bool(command and command[0].endswith(b'/unwrapped/lnx64.o/vivado'))
            if actual['vivado_worker'] and 'svb-' in unit:
                components.append(dict(unit=unit, **actual))
            workers.append(actual)
        services[unit] = dict(properties=props, exact_recursive_cgroup_tasks=workers)
    assert len(components) <= 3
    guard = services['ec-opt4-svb-host40-shell-physical-r2.service']['properties']
    assert guard['AllowedCPUs'] == '224-225' and guard['MemoryMax'] == str(64 * 2**30)
    physical = D / 'cycleprecise-svb-host40-shell-recovery-r2-20261112/A-shell-routing-placement/recovery.log'
    with physical.open('rb') as f:
        f.seek(max(0, physical.stat().st_size - 12000))
        excerpt = f.read()
    (OUT / 'physical-incremental-tail.txt').write_bytes(excerpt)
    with physical.open('rb') as f:
        prefix = f.read(128 * 1024)
    marker = re.search(rb'^EC_HOST40_SHELL_SNAPSHOT tag=physical WNS=[^\n]+', prefix, re.M)
    assert marker
    (OUT / 'physical-completed-snapshot-marker.txt').write_bytes(marker[0] + b'\n')
    report_roots = ['build-logs/Opt4-mcrams-full-host-capacity-r1-20261112',
                    'build-logs/Opt4-mcrams-address-bucket-area-r2-20261112']
    reports = {rel: sorted(str(p.relative_to(D)) for p in (D / rel).rglob('*utilization.rpt')) for rel in report_roots}
    analysis_raw = (ANALYSIS / 'result.json').read_bytes()
    analysis = json.loads(analysis_raw)
    complete = json.loads((ANALYSIS / 'complete.json').read_text())
    assert complete['result_sha256'] == sha(analysis_raw)
    for path, expected in complete['outputs'].items():
        assert sha(Path(path).read_bytes()) == expected
    delay_checks = []
    for path in analysis['all_reported_paths']:
        error = abs(sum(n['delay_ns'] for n in path['data_nets']) - path['route_delay_ns'])
        assert error <= 0.005
        delay_checks.append(error)
    validation = dict(status='PASS_ACTUAL_SAVED_REPORT_CROSSCHECKS', actual_paths=len(delay_checks),
        maximum_net_delay_sum_error_ns=max(delay_checks), tolerance_ns=0.005,
        all_snapshot_output_hashes_match=True, unchanged_clock_period_count=66,
        clock_table_rows=95, negative_representative_setup_paths=5,
        not_final_routed_certificate=True, no_cad_or_fpga_execution=True)
    save(OUT / 'validation.json', validation)
    mem = int(next(line.split()[1] for line in Path('/proc/meminfo').read_text().splitlines() if line.startswith('MemAvailable:'))) / 2**20
    load = float(Path('/proc/loadavg').read_text().split()[0])
    disk = shutil.disk_usage(W).free / 2**30
    snap = dict(schema='ec-opt4-round116-path-diagnosis-adoption/1', utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
        functional_baseline=policy['functional_baseline_commit'], host_boot_id=boot, policy_sha256=sha(policy_raw),
        states=states, services=services, actual_component_vivado_count=len(components), component_workers=components,
        available_memory_gib=mem, free_disk_gib=disk, load1=load,
        new_small_component_resource_admission_satisfied=mem >= 256 and disk >= 150 and load < 48,
        actual_mcrams_utilization_reports=reports, analysis_result=str(ANALYSIS / 'result.json'), analysis_sha256=sha(analysis_raw),
        no_new_persistent_job=True, no_active_input_changed=True, no_process_signalled=True, no_fpga_io=True, new_fpga_samples=0)
    save(OUT / 'snapshot.json', snap)
    report = f"""# Round116: saved host40 paths and active continuation

At {snap['utc']}, {len(components)} component Vivado workers remain within the max3 limit.
Existing P0/P1 CAD, CPU models and root followers were adopted by PID/start_ticks/boot_id;
their exact cgroups are in snapshot.json. No persistent job or FPGA experiment was launched.

Completed A physical-stage STA is WNS -0.417ns / WHS +0.001ns, compared with
the sealed probe -0.424ns / +0.001ns. TNS changes from -941.211 to -746.069ns;
setup failing endpoints change from 5840 to 4955. This is not final routed timing.
The target host clock has WNS +2.987ns; all 66 clock periods agree exactly between reports.
Five negative clock groups involve the XDMA/PCIe and DDR shell. The DDR representative
path has a 688-load net with 3.343ns route delay; the worst XDMA path has a 118-load
net with 3.566ns route delay after a logic stage. A PCIe hard-macro CORECLK startpoint
is outside the existing safe FD-Q replication selector. The live B query will be
recomputed on its sealed input; matching the pre-A query is not an eligibility proof.

The independent analyzer parsed 95 table rows and 267 representative paths. All 267
data-net delay sums reconcile to their reported route delays within 0.005ns; all
saved output hashes match. clock-groups.csv and negative-setup-paths.csv are under
{ANALYSIS}. Endpoint counts/TNS from separate clock groups are not added together.
Parser failures r1/r2 were preserved; only independent r3 produced the completed result.

Resource snapshot: MemAvailable {mem:.2f}GiB, disk {disk:.2f}GiB, load1 {load:.2f}.
Admission for a new small component attempt: {snap['new_small_component_resource_admission_satisfied']}.
Existing jobs are preserved regardless of current admission margin. The exact capacity
producer PID2379656 is adopted, with no Tcl injection, interruption or restart.
Actual MCRams report paths (empty means pending): {json.dumps(reports)}.

No timing certificate, bitstream or FPGA sample is inferred from this analysis.
Native FPGA remains paused; matched Native CPU and owner MC retry remain separate
ongoing executions. Existing 21-only followers still require actual timing/hold/
route/DRC/pulse/skew certification. Strict checker latency still requires matching
BOOM executionDone and validated checker completion in the same timebase.

Next: allow live A/B and conditional C/D to complete under unchanged guards. On real
failure, use the exact path CSV and a versioned sealed checkpoint recovery. Consume
the existing MCRams whole-host utilization/parity receipts as soon as they complete;
never substitute local area gains for full shell capacity or physical FIT.
"""
    (OUT / 'REPORT.md').write_text(report)
    save(OUT / 'complete.json', dict(outputs={str(p): sha(p.read_bytes()) for p in OUT.iterdir() if p.is_file()}))
    print(json.dumps(dict(snapshot=str(OUT / 'snapshot.json'), actual_component_vivado=len(components),
        memory_available_gib=mem, load1=load, capacity_reports=reports,
        p0_status=states['cycleprecise-svb-host40-shell-recovery-r2-20261112/state.json']['state']['status'],
        matched_native_cpu_status=states['Opt4-matched-single-boom-gg-r3-state.json']['state']['status']), indent=2))


if __name__ == '__main__':
    main()
