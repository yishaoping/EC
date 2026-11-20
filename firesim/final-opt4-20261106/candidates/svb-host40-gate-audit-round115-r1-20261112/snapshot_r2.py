#!/usr/bin/python3
"""Seal one read-only adoption snapshot; never scan unrelated /proc entries."""
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
U = D / 'unattended-opt4'
OUT = D / 'status-audits/opt4-round115-host40-gates-r2-20261112T022000Z'


def sha(b):
    return hashlib.sha256(b).hexdigest()


def save(q, j):
    t = q.with_name(q.name + '.tmp-' + str(os.getpid()))
    with t.open('x') as f:
        json.dump(j, f, indent=2, sort_keys=True)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())
    os.replace(t, q)


def main():
    policy_raw = (U / 'campaign-policy.json').read_bytes()
    policy = json.loads(policy_raw)
    assert policy['functional_baseline_commit'] == '8491167d84b6d9521b151a743673c1516926a1f8'
    assert policy['native_paused'] and not policy['fpga_access']
    assert policy['board_allowlist'] == ['0000:21:00.0']
    assert not policy['functional_extensions_allowed']
    assert not OUT.exists()
    OUT.mkdir()
    boot = Path('/proc/sys/kernel/random/boot_id').read_text().strip()

    def ident(pid):
        try:
            parts = Path(f'/proc/{pid}/stat').read_text().rsplit(')', 1)[1].split()
            return dict(pid=int(pid), start_ticks=parts[19], process_state=parts[0],
                        cpu_ticks=int(parts[11]) + int(parts[12]), host_boot_id=boot)
        except FileNotFoundError:
            return None

    paths = [
        'cycleprecise-svb-host40-shell-recovery-r2-20261112/state.json',
        'cycleprecise-original-svb-host40-shell-onboard-r2-20261112/state.json',
        'cycleprecise-original-svb-host40-shell-application-onboard-r2-20261112/state.json',
        'Opt4-svb-physical-resume-r3-state.json',
        'Opt4-svb-physical-resource-recovery-round51-v1-state.json',
        'Opt4-svb-physical-pinreplicate-r4-state.json',
        'Opt4-mcrams-full-host-capacity-r1-state.json',
        'Opt4-mcrams-full-host-continuation-r2-state.json',
        'Opt4-mcrams-owner-mc-runtime-r2-state.json',
        'Opt4-fit-update-share-svb-cad-state.json',
        'Opt4-owner-complete-transport-round114-r2-state.json',
        'Opt4-mcrams-address-bucket-area-r2-state.json',
    ]
    states = {}
    for rel in paths:
        raw = (D / rel).read_bytes()
        j = json.loads(raw)
        actual = ident(j['pid']) if j.get('pid') else None
        live = bool(actual and str(actual['start_ticks']) == str(j.get('start_ticks'))
                    and actual['host_boot_id'] == j.get('host_boot_id') and actual['process_state'] != 'Z')
        states[rel] = dict(snapshot_state=j, snapshot_bytes_sha256=sha(raw),
                           actual_controller=actual, identity_live=live)
    units = [
        'ec-opt4-auto-svb-physical-resource-recovery-r51-v1.service',
        'ec-opt4-auto-svb-physical-resume-r3-v1-8491167d.service',
        'ec-opt4-svb-host40-shell-physical-r2.service',
        'ec-opt4-svb-host40-shell-follow-r2.service',
        'ec-opt4-svb-host40-shell-application-follow-r2.service',
        'ec-opt4-svb-host40-physical-r1.service',
        'ec-opt4-auto-svb-physical-pinreplicate-r4-v1-8491167d.service',
        'ec-opt4-auto-mcrams-full-host-capacity-r1-3656aec4.service',
        'ec-opt4-mcrams-owner-runtime-follow-r1.service',
    ]
    services = {}
    component_workers = []
    for unit in units:
        text = subprocess.check_output(['systemctl', 'show', unit, '-p', 'MainPID', '-p', 'ActiveState',
                                       '-p', 'SubState', '-p', 'ControlGroup', '-p', 'AllowedCPUs', '-p', 'MemoryMax'], text=True)
        props = dict(x.split('=', 1) for x in text.splitlines() if '=' in x)
        q = Path('/sys/fs/cgroup/systemd/system.slice') / unit
        tasks = sorted({int(x) for f in q.rglob('cgroup.procs') for x in f.read_text().split()}) if q.exists() else []
        rows = []
        for pid in tasks:
            actual = ident(pid)
            if not actual:
                continue
            try:
                cmd = Path(f'/proc/{pid}/cmdline').read_bytes().split(b'\0')
            except FileNotFoundError:
                continue
            actual['vivado_worker'] = bool(cmd and cmd[0].endswith(b'/unwrapped/lnx64.o/vivado'))
            if actual['vivado_worker'] and 'svb-' in unit:
                component_workers.append(dict(unit=unit, **actual))
            rows.append(actual)
        unitpath = Path('/etc/systemd/system') / unit
        services[unit] = dict(properties=props, exact_recursive_cgroup_tasks=rows,
                              unit_sha256=sha(unitpath.read_bytes()) if unitpath.exists() else None)
    assert len(component_workers) <= 3
    extra = services['ec-opt4-svb-host40-shell-physical-r2.service']['properties']
    assert extra['AllowedCPUs'] == '224-225' and extra['MemoryMax'] == str(64 * 2**30)
    gate = D / 'build-logs/Opt4-svb-host40-gate-audit-round115-r1-20261112'
    gate_raw = (gate / 'result.json').read_bytes()
    g = json.loads(gate_raw)
    assert json.loads((gate / 'complete.json').read_text())['result_sha256'] == sha(gate_raw)
    assert g['case_count'] == 46 and g['negative_cases'] == 44 and not g['physical_timing_pass'] and not g['fpga_access']
    reportpaths = {rel: [str(x.relative_to(D)) for x in (D / rel).rglob('*utilization.rpt')] for rel in [
        'build-logs/Opt4-mcrams-full-host-capacity-r1-20261112',
        'build-logs/Opt4-mcrams-address-bucket-area-r2-20261112']}
    log = D / 'cycleprecise-svb-host40-shell-recovery-r2-20261112/A-shell-routing-placement/recovery.log'
    with log.open('rb') as f:
        f.seek(max(0, log.stat().st_size - 32000))
        excerpt = f.read()
    (OUT / 'p0-physical-log-excerpt.txt').write_bytes(excerpt)
    wns = re.findall(rb'Improved path group WNS = (-?\d+(?:\.\d+)?)', excerpt)
    assert re.findall(rb'Improved path group WNS = (-?\d+(?:\.\d+)?)', b'Improved path group WNS = -0.417.') == [b'-0.417']
    receipt = U / 'request-results/matched-single-boom-gg-r2-8491167d.json'
    receipt_raw = receipt.read_bytes()
    mem = int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:'))) / 2**20
    prior = D / 'status-audits/opt4-round115-host40-gates-20261112T022000Z/failure.json'
    snap = dict(schema='ec-opt4-round115-adoption-and-gate-audit/2',
                utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
                functional_baseline=policy['functional_baseline_commit'], host_boot_id=boot,
                policy_snapshot_sha256=sha(policy_raw), states=states, services=services,
                actual_component_vivado_count=len(component_workers), component_workers=component_workers,
                memory_available_gib=mem, free_disk_gib=shutil.disk_usage(W).free / 2**30,
                loadavg=Path('/proc/loadavg').read_text().strip(),
                gate_audit=dict(result=str(gate / 'result.json'), result_sha256=sha(gate_raw),
                                positive_cases=2, negative_rejections=44,
                                scope='Mocked gate-control flow only; no physical certification'),
                actual_utilization_reports=reportpaths,
                host40r2_latest_interim_pathgroup_wns_ns=float(wns[-1]) if wns else None,
                host40r2_interim_wns_is_not_completed_timing=True,
                physical_log_excerpt_sha256=sha(excerpt),
                native_owner_r2_request_receipt=dict(path=str(receipt), sha256=sha(receipt_raw), receipt=json.loads(receipt_raw)),
                snapshot_parser_failure_preserved=dict(path=str(prior), sha256=sha(prior.read_bytes())),
                native_fpga_paused=True, fpga_samples_this_round=0, fpga_access=False,
                new_persistent_jobs_launched_this_round=[], adopted_existing_jobs=True,
                normal_cad_or_model_stopped=False, live_inputs_modified=False)
    save(OUT / 'snapshot.json', snap)
    print(json.dumps(dict(snapshot=str(OUT / 'snapshot.json'), actual_component_vivado=len(component_workers),
                         negative_rejections=44, interim_wns=snap['host40r2_latest_interim_pathgroup_wns_ns'],
                         capacity_reports=reportpaths)))


if __name__ == '__main__':
    main()
