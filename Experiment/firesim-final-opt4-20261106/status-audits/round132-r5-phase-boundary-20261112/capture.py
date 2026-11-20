#!/usr/bin/python3
"""One bounded, read-only continuity capture; no job or device control."""
import datetime
import hashlib
import json
import re
import subprocess
from pathlib import Path

A = Path(__file__).resolve().parent
D = A.parent.parent
BOOT = Path('/proc/sys/kernel/random/boot_id').read_text().strip()
EXPECTED_BOOT = 'd6c6e410-10ad-4326-86ba-79b657eabd96'
assert BOOT == EXPECTED_BOOT


def save(name, value):
    path = A / name
    assert not path.exists(), ('immutable capture already exists', path)
    path.write_text(json.dumps(value, indent=2, sort_keys=True) + '\n')


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def identity(pid, start, unit):
    row = dict(pid=pid, expected_start_ticks=start, expected_cgroup='/system.slice/' + unit)
    try:
        p = Path('/proc') / str(pid)
        stat = (p / 'stat').read_text().split(') ', 1)[1].split()
        groups = (p / 'cgroup').read_text().splitlines()
        cg = next(line.split(':', 2)[2] for line in groups if ':name=systemd:' in line)
        row.update(start_ticks=stat[19], process_state=stat[0],
                   cpu_ticks=int(stat[11]) + int(stat[12]), cgroup=cg,
                   argv=(p / 'cmdline').read_bytes().replace(b'\0', b' ').decode(),
                   host_boot_id=BOOT,
                   identity_matches=stat[19] == start and cg == row['expected_cgroup'])
    except FileNotFoundError:
        row.update(process_exited=True, identity_matches=False)
    return row


def bounded_log(relative, copy_name, size):
    path = D / relative
    stat = path.stat()
    with path.open('rb') as stream:
        stream.seek(max(0, stat.st_size - size))
        data = stream.read(size)
    copy = A / copy_name
    assert not copy.exists()
    copy.write_bytes(data)
    return dict(path=str(path), observed_bytes=stat.st_size, mtime_ns=stat.st_mtime_ns,
                retained_bytes=len(data), copy=str(copy), copy_sha256=sha(copy)), data.decode(errors='replace')


def main():
    capture = dict(schema='ec-round132-exact-continuity/1',
                   utc=datetime.datetime.now(datetime.timezone.utc).isoformat(), host_boot_id=BOOT,
                   read_only=True, process_signals=[], new_jobs=[], device_operations=[])
    states = [
        'cycleprecise-svb-host40-shell-recovery-r5-20261112/state.json',
        'cycleprecise-original-svb-host40-shell-onboard-r5-20261112/state.json',
        'cycleprecise-original-svb-host40-shell-application-onboard-r5-20261112/state.json',
        'mcrams-shell-ipcollateral-r4b-observer-20261112/state.json',
        'svb-application-fpga-metrics-r1-20261112/state.json',
    ]
    capture['states'] = {}
    for index, relative in enumerate(states):
        data = (D / relative).read_bytes()
        copy = A / f'state-copy-{index}.json'
        assert not copy.exists()
        copy.write_bytes(data)
        capture['states'][relative] = dict(copy=str(copy), sha256=sha(copy), state=json.loads(data))
    processes = [
        (2692643, '26961211', 'ec-opt4-svb-host40-shell-application-follow-r5.service'),
        (2692644, '26961211', 'ec-opt4-svb-host40-shell-follow-r5.service'),
        (2692645, '26961211', 'ec-opt4-svb-host40-shell-physical-r5.service'),
        (2692703, '26961377', 'ec-opt4-svb-host40-shell-physical-r5.service'),
        (2759828, '27368804', 'ec-opt4-mcrams-host-continuation-r3-clock-3656aec4.service'),
        (2797798, '27514959', 'ec-opt4-auto-mcrams-ipcollateral-recovery-observer-r4b-3656aec4.service'),
        (2813002, '27638842', 'ec-opt4-auto-svb-application-fpga-metrics-r1-8491167d.service'),
        (2551972, '26486048', 'ec-opt4-fpga-priority-handoff-r1.service'),
    ]
    capture['processes'] = [identity(*args) for args in processes]
    units = sorted({args[2] for args in processes})
    result = subprocess.run(['systemctl', 'show', *units,
        '--property=Id,MainPID,ControlGroup,ActiveState,SubState'], capture_output=True, text=True)
    assert result.returncode == 0, result.stderr
    capture['systemd_properties'] = result.stdout
    capture['r5_log'], log = bounded_log(
        'cycleprecise-svb-host40-shell-recovery-r5-20261112/E-preroute-shell-replication/vivado.log',
        'r5-bounded.log', 65536)
    snapshots = [dict(tag=tag, WNS_ns=float(wns), WHS_ns=float(whs)) for tag, wns, whs in
        re.findall(r'^EC_HOST40_SHELL_SNAPSHOT tag=(\S+) WNS=([-0-9.]+) WHS=([-0-9.]+)', log, re.M)]
    capture['r5_phase_evidence'] = dict(
        actual_snapshot_markers=snapshots,
        successful_route_commands=len(re.findall(r'^route_design completed successfully', log, re.M)),
        route_summary_observations=re.findall(r'^\s+Number of (?:Failed Nets|Unrouted Nets|Partially Routed Nets|Node Overlaps)\s+=\s+\d+', log, re.M),
        latest_intermediate_timing=(re.findall(r'^INFO: \[Route 35-416\].*$', log, re.M) or [None])[-1],
        actual_bitstream_completion_marker=bool(re.search(r'^EC_SVB_HOST40_BITSTREAM_COMPLETE WNS=', log, re.M)),
        first_route_is_not_certification=True)
    # Reuse the supplied immutable whole-CAD observation. Do not poll the
    # live producer again inside its 600-second observation interval.
    snapshot = D / 'unattended-opt4/snapshots/full-2026-11-12T07-46-12.901171+00-00.json'
    expected = '4ab1c222c4e0a4040de393741cd992dc40fbb42f26f2e79c240f935df9e2abad'
    assert sha(snapshot) == expected
    capture['whole_cad_evidence'] = dict(path=str(snapshot), sha256=expected,
        utc='2026-11-12T07:46:12.901010+00:00', live_producer_repolled=False,
        most_recent_allowed_direct_observation='Initial round read: rebuilding user hierarchy; no LUT/FIT result established',
        original_router_pid=2379656, original_start_ticks='25825451',
        exact_process_identity_matched_on_initial_round_read=True)
    mc = D / 'cycleprecise-owner-mc-runtime-r2-20261112/result.json'
    capture['owner_mc'] = dict(path=str(mc), sha256=sha(mc),
        status=json.loads(mc.read_text())['status'], strict_or_full_equivalence_claimed=False)
    capture['conditional_physical_request_exists'] = (D /
        'unattended-opt4/requests/mcrams-shell-ipcollateral-r4b-3656aec4.json').exists()
    for name in ['chosen-result.json', 'E-preroute-shell-replication/result.json',
                 'F-preroute-fanout-placement-routing/result.json']:
        path = D / 'cycleprecise-svb-host40-shell-recovery-r5-20261112' / name
        if path.exists():
            capture.setdefault('r5_completed_results', {})[name] = dict(sha256=sha(path), data=json.loads(path.read_text()))
    save('continuity.json', capture)
    print(json.dumps(dict(utc=capture['utc'], matched_live_processes=sum(p['identity_matches'] for p in capture['processes']),
        phase_evidence=capture['r5_phase_evidence'],
        completed_r5_results=list(capture.get('r5_completed_results', {})),
        whole_cad_repolled=False,
        conditional_r4b_request=capture['conditional_physical_request_exists'], continuity_sha256=sha(A / 'continuity.json'))))


if __name__ == '__main__':
    main()
