#!/usr/bin/env python3
"""Read existing simmedium producers; write only this independent receipt."""
import datetime
import hashlib
import json
import os
from pathlib import Path
import subprocess
import time

OUT = Path(__file__).resolve().parent
EC = Path('/data1/gzh/EC')
ROOT = EC / 'Experiment/parsec8-simmedium-ec-r2-20261112'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
BENCH = ['blackscholes', 'fluidanimate', 'bodytrack', 'freqmine',
         'swaptions', 'ferret', 'dedup', 'streamcluster']
UNIT = 'ec-parsec8-simmedium-ec-r2-20261112.service'
CGROUP = '/user.slice/user-1008.slice/user@1008.service/' + UNIT
BOOT = Path('/proc/sys/kernel/random/boot_id').read_text().strip()
bindings = {}


def sha(path):
    digest = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for chunk in iter(lambda: stream.read(2 ** 20), b''):
            digest.update(chunk)
    return digest.hexdigest()


def read(path, immutable=False):
    path = Path(path)
    raw = path.read_bytes()
    if immutable:
        bindings[str(path)] = hashlib.sha256(raw).hexdigest()
    return json.loads(raw)


def process(identity):
    pid = identity['pid']
    p = Path('/proc') / str(pid)
    stat = p.joinpath('stat').read_text().rsplit(')', 1)[1].split()
    assert str(identity['start_ticks']) == stat[19]
    assert identity.get('boot_id', identity.get('host_boot_id')) == BOOT
    groups = p.joinpath('cgroup').read_text().splitlines()
    assert '1:name=systemd:' + CGROUP in groups
    assert stat[0] != 'Z'
    return dict(pid=pid, start_ticks=stat[19], boot_id=BOOT,
                state=stat[0], cpu_ticks=int(stat[11]) + int(stat[12]),
                ppid=int(stat[1]), cgroup=CGROUP,
                affinity=sorted(os.sched_getaffinity(pid)),
                exe=str(p.joinpath('exe').resolve()),
                argv=p.joinpath('cmdline').read_bytes().decode().split('\0')[:-1])


def main():
    assert not (OUT / 'receipt.json').exists(), 'preserve existing receipt'
    inputs = read(ROOT / 'inputs.json', True)
    assert inputs['benchmarks'] == BENCH
    assert inputs['functional_baseline'] == BASE
    assert inputs['input_sizes'] == ['simmedium'] and inputs['repetitions'] == 1
    assert not inputs['native_launch_allowed'] and not inputs['fpga_access']
    assert inputs['cpu_slots'] == [201, 200]
    model = Path(inputs['model'])
    assert inputs['model_sha256'] == 'cc2993bd8c6f56893afd9e73cc358684c07c481a52ef8eb50dc7a136134b2867'
    bindings[str(model)] = sha(model)
    assert bindings[str(model)] == inputs['model_sha256']
    for name in ['campaign.py', 'audit_follow.py']:
        p = ROOT / name
        bindings[str(p)] = sha(p)
        if str(p) in inputs['files']:
            assert bindings[str(p)] == inputs['files'][str(p)]
    frozen = EC / 'Experiment/firesim-final-opt4-20261106/cycleprecise-frozen-full-metasim-r1-20261111/binding.json'
    assert read(frozen, True)['functional_baseline'] == BASE
    assert bindings[str(frozen)] == inputs['files'][str(frozen)]

    native = []
    for ct in inputs['contracts']:
        b = ct['benchmark']
        assert read(ROOT / 'contracts' / (b + '.json'), True) == ct
        assert ct['input'] == 'simmedium' and ct['mode'] == 'ec' and ct['repeat'] == 1
        assert ct['case']['input'] == 'simmedium' and ct['case']['threads'] == 1
        assert ct['preflight'] == 'PASS_SOFTWARE_INPUT_MEMORY_FREQUENCY_CONTRACT'
        assert sorted(n['repeat'] for n in ct['native_archives']) == [1, 2, 3]
        for old in ct['native_archives']:
            p = Path(old['result'])
            n = read(p, True)
            assert bindings[str(p)] == old['result_sha256']
            ni = n['identity']
            checks = dict(
                valid=n['valid'] is True, input=ni['input'] == 'simmedium',
                repetition=ni['repetition'] == old['repeat'],
                elf=ni['elf_sha256'] == ct['app_sha256'],
                rootfs=ni['rootfs_sha256'] == ct['rootfs_sha256'],
                case=ni['case'] == ct['case'], threads=ni['threads'] == 1,
                frequency=ni['target_boom_hz'] == ct['fdt']['target_boom_hz'],
                memory_model=ni['memory_model'] == {k: inputs['memory'][k] for k in ['model', 'settings']},
                linux_memory=ni['linux_memory_cap_bytes'] == ct['fdt']['linux_mem_cap'],
                bootargs=ni['linux_bootargs'] == ct['fdt']['bootargs'],
                roi_cycles=n['roi_cycles'] == old['roi_cycles'] and n['roi_cycles'] > 0)
            assert all(checks.values()), (b, old['repeat'], checks)
            native.append(dict(benchmark=b, repetition=old['repeat'], source=str(p),
                               sha256=bindings[str(p)], checks=checks))

    env = {**os.environ, 'XDG_RUNTIME_DIR': '/run/user/1008',
           'DBUS_SESSION_BUS_ADDRESS': 'unix:path=/run/user/1008/bus'}
    props = subprocess.check_output(
        ['systemctl', '--user', 'show', UNIT, '--property=ActiveState,SubState,MainPID,ControlGroup,ExecStart,FragmentPath'],
        env=env, text=True)
    service = dict(line.split('=', 1) for line in props.splitlines())
    assert service['ActiveState'] == 'active' and service['SubState'] == 'running'
    assert service['ControlGroup'] == CGROUP
    campaign = read(ROOT / 'campaign-state.json')
    controller = process(campaign['controller'])
    assert controller['pid'] == int(service['MainPID'])
    assert controller['argv'] == ['/usr/bin/python3', str(ROOT / 'campaign.py'), 'campaign']
    active = []
    for cpu, work in campaign['active'].items():
        b = work['benchmark']
        state = read(ROOT / 'runs' / b / 'state.json')
        binding = read(ROOT / 'runs' / b / 'binding.json', True)
        assert binding['functional_baseline'] == BASE and binding['input'] == 'simmedium'
        assert binding['mode'] == 'ec' and binding['repeat'] == 1 and not binding['fpga_access']
        assert binding['inputs_sha256'] == bindings[str(ROOT / 'inputs.json')]
        assert binding['model_sha256'] == inputs['model_sha256']
        assert binding['runner_sha256'] == bindings[str(ROOT / 'campaign.py')]
        assert binding['contract'] == next(c for c in inputs['contracts'] if c['benchmark'] == b)
        worker, child = process(work['worker']), process(state['child'])
        assert worker['pid'] == state['controller']['pid']
        assert worker['ppid'] == controller['pid'] and child['ppid'] == worker['pid']
        assert worker['affinity'] == child['affinity'] == [int(cpu)]
        assert child['argv'] == binding['args'] and child['exe'] == str(model.resolve())
        active.append(dict(benchmark=b, producer_state=state, worker=worker, child_first=child,
                           uart_input_bytes=(ROOT / 'runs' / b / 'uart.in').stat().st_size))
    # CPU activity confirms a live process, not guest/target-cycle progress.
    time.sleep(2)
    for row in active:
        row['child_second'] = process(row['producer_state']['child'])
        row['cpu_ticks_delta'] = row['child_second']['cpu_ticks'] - row['child_first']['cpu_ticks']
        assert row['cpu_ticks_delta'] > 0
    coverage = read(ROOT / 'coverage.json')
    paper = read(ROOT / 'paper-state.json')
    assert coverage['scoped_data_excluded'] is True
    assert all(r['slowdown'] is None for r in coverage['rows'])
    assert paper['valid_slowdowns'] == 0 and all(r['slowdown'] is None for r in paper['rows'])
    assert sorted([r['benchmark'] for r in active] + campaign['pending']) == sorted(BENCH)
    assert all(not (ROOT / 'runs' / b / 'binding.json').exists() for b in campaign['pending'])
    assert all(sha(p) == digest for p, digest in bindings.items())
    receipt = dict(
        schema='ec-round148-existing-simmedium-owner-adoption/1',
        status='PASS_EXISTING_OWNER_IDENTITY_AND_SIMMEDIUM_SCOPE',
        observed_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
        functional_baseline=BASE, model_sha256=inputs['model_sha256'],
        service=service, controller=controller, active=active, pending=campaign['pending'],
        valid_full_simmedium_ec=paper['valid_ec_simmedium'], valid_slowdowns=0,
        native_archives_verified=native, immutable_source_sha256=bindings,
        timeouts={k: inputs[k] for k in ['boot_timeout_seconds', 'run_timeout_seconds', 'stalled_progress_timeout_seconds']},
        one_attempt_guard='Existing binding blocks relaunch; existing result skips benchmark; wrapper/model failure records result and continues pending order.',
        runtime_boundary='CPU activity observed; no guest ROI or target progress established by that observation. Archived Native is FPGA; current EC is full GoldenGate CPU simulation. Cross-backend admission remains pending.',
        source_review='campaign.py run_one/campaign and audit_follow.py audit/publish, bound by SHA; no producer edits.',
        launched_jobs=[], producer_files_modified=[], process_signals=[], fpga_operations=[],
        excluded='All previous reduced/phase profiles; SVB component measurements; no Native/reduced/test launch or project64/100 resumption.',
        next_automatic_action='Existing owner waits for EC_GUEST_READY, sends only this benchmark simmedium 1, audits completed output/checker/drain streams, records failure/timeout and advances without replay.')
    target = OUT / 'receipt.json'
    with target.open('x') as stream:
        json.dump(receipt, stream, indent=2, sort_keys=True)
        stream.write('\n')
    with (OUT / 'receipt.sha256').open('x') as stream:
        stream.write(sha(target) + '  receipt.json\n')
    print(json.dumps(dict(status=receipt['status'], receipt_sha256=sha(target),
                         active=[dict(benchmark=r['benchmark'], pid=r['child_first']['pid'],
                                      cpu_ticks_delta=r['cpu_ticks_delta'],
                                      guest_command_sent=r['producer_state']['guest_command_sent']) for r in active],
                         pending=campaign['pending'], native_archives_verified=len(native),
                         valid_full_simmedium_ec=paper['valid_ec_simmedium'], valid_slowdowns=0)))


if __name__ == '__main__':
    main()
