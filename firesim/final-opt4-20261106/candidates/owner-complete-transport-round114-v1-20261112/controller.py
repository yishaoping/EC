#!/usr/bin/python3
"""Prepare and run a read-only completion follower for the existing MC retry."""
import argparse
import fcntl
import importlib.util
import json
import os
from pathlib import Path
import resource
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
O = D/'build-logs/Opt4-owner-complete-transport-round114-v1-20261112'
S = D/'Opt4-owner-complete-transport-round114-v1-state.json'
OLD = D/'cycleprecise-owner-pair-runtime-r1-20261111'
MC = D/'cycleprecise-owner-mc-runtime-r2-20261112'
RETRY = W/'candidates/mcrams-owner-mc-runtime-r2-20261112'
UNIT = 'ec-opt4-auto-owner-mc-runtime-r2-3656aec4.service'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
HW = '3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
SOURCE = '79aedd9ada6137e018d7f9c9c175fd4a06f53820d235ddcbe4b4a185e75fd68d'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha
sys.path.insert(0, str(C))
from transport_audit import compare, mutation_checks


def policy():
    p = read(U/'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert p['native_paused'] and not p['fpga_access'] and not p['functional_extensions_allowed']
    assert p['board_allowlist'] == ['0000:21:00.0']


def write_new(p, value):
    with p.open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n'); f.flush(); os.fsync(f.fileno())


def command_line(argv):
    args = [x[7:] if x.startswith('+prog0=') else x for x in argv[1:]]
    return (' '.join(args) + ' \n').encode()


def exclusive_cpu():
    occupied = set()
    for row in read(U/'snapshot.json')['states'].values():
        if not row.get('identity_live'): continue
        for proc in [row, row.get('child', {}), row.get('stage_process', {}), *row.get('worker_processes', [])]:
            if live(proc) and proc['pid'] != os.getpid():
                affinity = os.sched_getaffinity(proc['pid'])
                if len(affinity) <= 16: occupied |= affinity
    return next(cpu for cpu in range(239, 7, -1) if cpu in os.sched_getaffinity(0) and cpu not in occupied)


def release():
    raw = subprocess.check_output(['systemctl', 'show', UNIT, '-p', 'ActiveState',
        '-p', 'SubState', '-p', 'MainPID', '-p', 'ControlGroup', '-p', 'TasksCurrent'], text=True)
    fields = dict(line.split('=', 1) for line in raw.splitlines() if '=' in line)
    roots = {Path('/sys/fs/cgroup/system.slice')/UNIT}
    if fields.get('ControlGroup'):
        roots.add(Path('/sys/fs/cgroup')/fields['ControlGroup'].lstrip('/'))
    pids = set()
    for root in roots:
        if root.exists():
            files = [root/'cgroup.procs', *root.glob('**/cgroup.procs')]
            for path in set(files):
                if path.exists(): pids.update(int(x) for x in path.read_text().split())
    inactive = fields.get('ActiveState') in ('inactive', 'failed')
    tasks = fields.get('TasksCurrent')
    eligible = inactive and fields.get('MainPID') == '0' and tasks in ('0', '[not set]') and not pids
    return dict(eligible=eligible, unit=UNIT, properties=fields, cgroup_pids=sorted(pids))


def prepare():
    policy()
    assert not (C/'plan.json').exists() and not O.exists() and not S.exists()
    rp = read(RETRY/'plan.json')
    plain = read(OLD/'result.json')['results']['Plain']
    rr = read(OLD/'receipts/run-Plain.json')
    assert plain['output_correctness'] and rr['returncode'] == 0 and rr['stop_cause'] is None
    prefix = W/'candidates/owner-stdout-prefix-round113-v4-20261112/transport_audit.py'
    spec = importlib.util.spec_from_file_location('prior_prefix', prefix)
    module = importlib.util.module_from_spec(spec); spec.loader.exec_module(module)
    extra_formats = [b'[ROI] hart=0 start=%lu stop=%lu cycles=%lu',
        b'[OUTPUT] benchmark=canneal checksum=%016lx verified=%d routing_cost=%lu',
        b'[APP] protected=%lu start=%lu end=%lu cycles=%lu instret=%lu session_stop=%lu',
        b'[COMPUTATION] status=%s scope=official_serial_kernel', b'[END] hart=0 status=%s']
    uart = list(module.UART_ROWS) + [(x+'\n').encode() for x in plain['target_rows']]
    assert len(uart) == 11
    elf = next(Path(x[7:]) for x in rp['reference_args'] if x.startswith('+prog0='))
    blob = elf.read_bytes()
    assert all(x in blob for x in list(module.ELF_FORMATS) + extra_formats)
    files = [C/'controller.py', C/'transport_audit.py', C/'README.md', prefix,
        RETRY/'controller.py', RETRY/'plan.json', W/'scripts/opt4_unattended_common.py',
        W/'C4/chipyard/sims/firesim/sim/midas/src/main/cc/core/simulation.cc',
        W/'C4/chipyard/sims/firesim/sim/firesim-lib/src/main/cc/bridges/tsibridge.cc']
    plan = dict(schema='ec-owner-complete-transport-plan/1', functional_baseline=BASE,
        hardware_commit=HW, source_id=SOURCE, inputs={str(p):sha(p) for p in files},
        evidence={str(p):sha(p) for p in [elf, OLD/'result.json', OLD/'receipts/run-Plain.json']},
        uart_rows=[x.decode() for x in uart], target_cycles=rp['expected_reference_target_cycles'],
        plain_log=rr['log'], plain_log_sha256=rr['log_sha256'],
        plain_command_line=command_line(rr['argv']).decode(),
        runtime_unit=UNIT, runtime_result=str(MC/'result.json'), runtime_receipt=str(MC/'receipts/run-MCRams.json'),
        cpu=exclusive_cpu(), no_runtime_launch=True, fpga_access=False, whole_fit=False)
    write_new(C/'plan.json', plan)
    write_new(C/'preflight.json', dict(status='PREPARED_WAIT_EXISTING_RETRY_NO_SIMULATOR',
        mutation_checks=mutation_checks(uart), plan_sha256=sha(C/'plan.json'), utc=now()))
    request = dict(action='cpu_job', spec=dict(name='owner-complete-transport-r114-v1-3656aec4',
        kind='analysis', cwd=str(C), argv=['/usr/bin/python3', str(C/'controller.py'), '--run'],
        inputs={**plan['inputs'], **{str(p):sha(p) for p in [C/'plan.json', C/'preflight.json']}},
        outputs=[str(O/'complete.json')], checkpoints=[str(S)]))
    target = U/'requests/owner-complete-transport-r114-v1-3656aec4.json'
    assert not target.exists()
    pending = U/('pending-owner-complete-transport-r114-v1-' + str(os.getpid()) + '.json')
    write_new(pending, request)
    os.replace(pending, target)
    print(json.dumps(dict(status='PREPARED_AND_SUBMITTED', request=request['spec']['name'],
        cpu=plan['cpu'], mutations=read(C/'preflight.json')['mutation_checks'])))


def run():
    policy(); plan = read(C/'plan.json')
    O.mkdir(exist_ok=True)
    lock = (O/'instance.lock').open('a'); fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not S.exists(), 'adopt existing state; never restart a partial audit'
    for p, digest in {**plan['inputs'], **plan['evidence']}.items(): assert sha(p) == digest, p
    cpu = exclusive_cpu(); os.sched_setaffinity(0, {cpu})
    resource.setrlimit(resource.RLIMIT_AS, (4*2**30, 4*2**30))
    state = dict(schema='ec-owner-complete-transport/1', **identity(), cpu=cpu,
        functional_baseline=BASE, hardware_commit=HW, source_id=SOURCE, started_utc=now(),
        fpga_access=False, whole_fit=False, target_changed=False, no_runtime_launch=True)
    def update(**values):
        state.update(values, updated_utc=now()); save(S, state)
    uart = [x.encode() for x in plan['uart_rows']]
    update(status='VALIDATING_SEALED_PLAIN_COMPLETE_TRANSPORT')
    mutation = mutation_checks(uart); write_new(O/'mutations.json', mutation)
    path = Path(plan['plain_log']); command = plan['plain_command_line'].encode()
    before = (path.stat().st_size, path.stat().st_mtime_ns)
    with path.open('rb') as a, path.open('rb') as b:
        result = compare(a, b, uart, command, command, plan['target_cycles'])
    assert before == (path.stat().st_size, path.stat().st_mtime_ns)
    assert result['passed'] and result['counts']['plain']['raw_sha256'] == plan['plain_log_sha256']
    write_new(O/'plain-complete-preflight.json', result)
    while True:
        policy(); released = release()
        if Path(plan['runtime_result']).is_file() and Path(plan['runtime_receipt']).is_file() and released['eligible']:
            break
        update(status='WAITING_EXACT_MC_RETRY_COMPLETION_NO_SIMULATOR', runtime_release=released,
            plain_preflight_sha256=sha(O/'plain-complete-preflight.json'), mutation_sha256=sha(O/'mutations.json'))
        time.sleep(300)
    final = read(plan['runtime_result']); receipt = read(plan['runtime_receipt'])
    assert final['functional_baseline'] == BASE and final['derived_hardware'] == HW
    if receipt['returncode'] != 0 or receipt['stop_cause'] is not None or not final.get('captured_finite_parity_passed'):
        update(status='RETRY_FAILED_OR_CAPTURED_PARITY_FAILED_NO_FULL_STDOUT_PASS', runtime_release=released,
            retry_result_sha256=sha(plan['runtime_result']), retry_receipt_sha256=sha(plan['runtime_receipt']))
        write_new(O/'result.json', state)
        write_new(O/'complete.json', dict(status=state['status'], result_sha256=sha(O/'result.json')))
        return
    actual = Path(receipt['log']); mc_before = (actual.stat().st_size, actual.stat().st_mtime_ns)
    with actual.open('rb') as a, path.open('rb') as b:
        result = compare(a, b, uart, command_line(receipt['argv']), command, plan['target_cycles'])
    assert mc_before == (actual.stat().st_size, actual.stat().st_mtime_ns)
    assert before == (path.stat().st_size, path.stat().st_mtime_ns)
    assert result['counts']['mc']['raw_sha256'] == receipt['log_sha256']
    assert result['counts']['plain']['raw_sha256'] == plan['plain_log_sha256']
    write_new(O/'complete-transport-comparison.json', result)
    update(status='PASS_COMPLETE_FINITE_OWNER_STDOUT_TRANSPORTS_NOT_FULL_EQUIVALENCE' if result['passed'] else
        'FAIL_COMPLETE_STDOUT_TRANSPORT_COMPARISON_NOT_DUT_ERROR_CLASSIFICATION',
        comparison_sha256=sha(O/'complete-transport-comparison.json'),
        retry_result_sha256=sha(plan['runtime_result']), retry_receipt_sha256=sha(plan['runtime_receipt']),
        runtime_release=released, completed_utc=now())
    write_new(O/'result.json', state)
    write_new(O/'complete.json', dict(status=state['status'], result_sha256=sha(O/'result.json')))


if __name__ == '__main__':
    ap = argparse.ArgumentParser(); ap.add_argument('--prepare', action='store_true'); ap.add_argument('--run', action='store_true')
    args = ap.parse_args(); assert args.prepare != args.run
    if args.prepare: prepare()
    else:
        try: run()
        except Exception as error:
            if not (O/'complete.json').exists():
                save(O/'failure.json', dict(status='FAILED_AUDIT_WITH_EVIDENCE_NOT_DUT_ERROR', error=repr(error), utc=now()))
            raise
