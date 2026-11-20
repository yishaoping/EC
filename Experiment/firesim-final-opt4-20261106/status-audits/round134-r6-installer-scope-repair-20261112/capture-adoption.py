#!/usr/bin/python3
"""Read and pin the actual foreground r6; never start or signal a service."""
import datetime
import hashlib
import json
from pathlib import Path
import subprocess

ROOT = Path('/data1/gzh/EC')
D = ROOT / 'Experiment/firesim-final-opt4-20261106'
C = ROOT / 'firesim/final-opt4-20261106/candidates/svb-r5-routed-repair-r6-20261112'
A = Path(__file__).resolve().parent
BOOT = Path('/proc/sys/kernel/random/boot_id').read_text().strip()
EXPECTED_BOOT = 'd6c6e410-10ad-4326-86ba-79b657eabd96'


def sha(path):
    digest = hashlib.sha256()
    with Path(path).open('rb') as source:
        for block in iter(lambda: source.read(2**20), b''):
            digest.update(block)
    return digest.hexdigest()


def save(name, data):
    path = A / name
    with path.open('x') as output:
        json.dump(data, output, indent=2, sort_keys=True)
        output.write('\n')
    return path


def identity(pid):
    p = Path('/proc') / str(pid)
    fields = (p / 'stat').read_text().rsplit(') ', 1)[1].split()
    group = next(line.split(':', 2)[2]
                 for line in (p / 'cgroup').read_text().splitlines()
                 if ':name=systemd:' in line)
    return dict(pid=pid, start_ticks=fields[19], host_boot_id=BOOT,
                process_state=fields[0], exact_cgroup=group,
                argv=[s.decode() for s in (p / 'cmdline').read_bytes().split(b'\0') if s])


def main():
    assert BOOT == EXPECTED_BOOT
    bindings = json.loads((C / 'inputs.json').read_text())
    for path, expected in bindings['files'].items():
        assert sha(path) == expected, ('bound input changed', path)
    installation = json.loads((C / 'installation.json').read_text())
    for unit, expected in installation['units'].items():
        assert sha(Path('/etc/systemd/system') / unit) == expected, unit
    rows = []
    specifications = [
        ('cycleprecise-svb-host40-shell-recovery-r6-20261112', 'physical',
         3109899, '28470862', 'controller.py'),
        ('cycleprecise-original-svb-host40-shell-onboard-r6-20261112', 'follow',
         3109930, '28470947', 'runtime.py'),
        ('cycleprecise-original-svb-host40-shell-application-onboard-r6-20261112',
         'application-follow', 3110004, '28471027', 'application.py')]
    for directory, role, pid, ticks, script in specifications:
        path = D / directory / 'state.json'
        raw = path.read_bytes()
        state = json.loads(raw)
        unit = 'ec-opt4-svb-host40-shell-' + role + '-r6.service'
        actual = identity(pid)
        assert state['pid'] == pid and state['start_ticks'] == ticks
        assert state['host_boot_id'] == BOOT
        assert actual['start_ticks'] == ticks
        assert actual['exact_cgroup'] == '/system.slice/' + unit
        assert actual['argv'] == ['/usr/bin/python3', str(C / script)]
        properties = dict(line.split('=', 1) for line in subprocess.check_output(
            ['systemctl', 'show', unit, '-p', 'MainPID', '-p', 'ActiveState',
             '-p', 'ControlGroup'], text=True).splitlines())
        assert properties['MainPID'] == str(pid) and properties['ActiveState'] == 'active'
        assert properties['ControlGroup'] == actual['exact_cgroup']
        copy = A / ('r6-' + role + '-state.json')
        with copy.open('xb') as output:
            output.write(raw)
        rows.append(dict(unit=unit, identity=actual, status=state['status'],
                         state=str(path), state_copy=str(copy), state_copy_sha256=sha(copy)))

    cg = Path('/sys/fs/cgroup/systemd/system.slice/ec-opt4-svb-host40-shell-physical-r6.service')
    processes = [identity(pid) for pid in sorted({int(pid) for p in cg.rglob('cgroup.procs')
                                                for pid in p.read_text().split()})]
    vivados = [p for p in processes if p['argv'] and
               p['argv'][0].endswith('/unwrapped/lnx64.o/vivado')]
    assert len(vivados) == 1, 'adopt one existing physical Vivado'
    out = D / 'cycleprecise-svb-host40-shell-recovery-r6-20261112'
    selected = json.loads((out / 'selected-checkpoint.json').read_text())
    assert sha(selected['checkpoint']) == selected['sha256']
    predecessor = D / 'cycleprecise-svb-host40-shell-recovery-r5-20261112/E-preroute-shell-replication'
    assert selected['checkpoint'] == str(predecessor / 'final.dcp')
    predecessor_result = predecessor / 'result.json'
    assert sha(predecessor_result) == 'f9d97aa4a4c049218586756c75495d90e02bc7bb61cf73ee8e62e85542d8129b'
    assert sha(predecessor / 'final-timing.rpt') == 'a845571ea0f8588d34853851cdcc2a05e80af150b67676129844545d40b1c5ce'
    r6_state = json.loads((A / 'r6-physical-state.json').read_text())
    assert r6_state['input_manifest_sha256'] == sha(C / 'inputs.json')
    sources = {str(p): sha(p) for p in C.iterdir() if p.is_file()}
    save('r6-source-verification.json', dict(
        status='PASS_ALL_95_BOUND_INPUTS_AND_THREE_EXACT_UNIT_HASHES',
        bound_input_count=len(bindings['files']), sources=sources,
        unit_sha256=installation['units']))
    save('adoption.json', dict(
        schema='ec-opt4-round134-r6-adoption/1', round=134,
        utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
        status='ADOPT_EXISTING_FOREGROUND_R6_NO_INSTALL_OR_DUPLICATE',
        candidate=str(C), candidate_inputs_sha256=sha(C / 'inputs.json'),
        installation=str(C / 'installation.json'),
        installation_sha256=sha(C / 'installation.json'),
        services=rows, physical_cgroup_processes=processes,
        selected_checkpoint=selected, predecessor_result=str(predecessor_result),
        predecessor_result_sha256=sha(predecessor_result),
        predecessor_final_wns_ns=-0.029, predecessor_final_whs_ns=0.001,
        r6_final_timing_available=False, r6_certified=False,
        separately_prepared_installer='SUPERSEDED_DO_NOT_INSTALL',
        real_validate_only_result='REFUSED_EXISTING_R6_STATE_BEFORE_ANY_UNIT_WRITE',
        CAD_jobs_launched_by_this_round=[], FPGA_operations=[],
        existing_processes_signalled=[], new_requests=[], CPU_comparison_controls=[],
        original_metrics_request_duplicated=False,
        next_automatic_action='Existing r6 G -> H -> I -> J with all gates; on real certification, existing 21-only directed and same-bit application followers.',
        minimum_normal_CAD_recheck_seconds=300, minimum_whole_CAD_recheck_seconds=600))
    print(json.dumps(dict(status='R6_ADOPTED', services=len(rows),
                          bound_inputs_verified=len(bindings['files']),
                          vivado=vivados[0], selected_checkpoint=selected)))


if __name__ == '__main__':
    main()
