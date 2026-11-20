#!/usr/bin/python3
"""Broker-owned component physical repair; unchanged RTL, clocks and r1 CAD.

Resource deferral is monitor state, never a failed CAD attempt. Old services,
failures, inputs and certificate/application followers remain untouched.
"""
import fcntl
import importlib.util
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import time
import traceback

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
ROOT = D/'cycleprecise-svb-postroute-recovery-r1-20261111'
OUT = ROOT/'round51-v1'
STATE = D/'Opt4-svb-physical-resource-recovery-round51-v1-state.json'
R1 = W/'routes/svb-postroute-recovery-r1-20261111'
R2 = W/'routes/svb-postroute-recovery-r2-20261111'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
SID = 'b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f'
VARIANTS = [(p, mode) for p in ['spread', 'original']
            for mode in ['postroute', 'replicate']]
PRODUCERS = ['ec-opt4-original-svb-spread-impl-r1.service',
             'ec-opt4-frozen-svb-fpga-r2.service']
OLD_WORKERS = [f'ec-opt4-svb-recovery-{p}-{mode}-r{r}.service'
               for r in [1, 2] for p, mode in VARIANTS]
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha


def policy():
    p = read(U/'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert p['native_paused'] and not p['fpga_access']
    assert not p['functional_extensions_allowed']
    assert p['board_allowlist'] == ['0000:21:00.0']
    return p


def verify():
    policy()
    for path, expected in read(C/'inputs.json')['files'].items():
        assert sha(path) == expected, ('changed immutable recovery input', path)


def resources(memory_kib=None, disk_bytes=None, load1=None):
    # Exact original r1 thresholds, including strict load<48. No weaker gate.
    if memory_kib is None:
        memory_kib = int(next(s.split()[1] for s in Path('/proc/meminfo').read_text().splitlines()
                              if s.startswith('MemAvailable:')))
    if disk_bytes is None:
        disk_bytes = shutil.disk_usage(W).free
    if load1 is None:
        load1 = float(Path('/proc/loadavg').read_text().split()[0])
    reasons = []
    if memory_kib < 128*2**20:
        reasons.append('available memory below unchanged 128GiB gate')
    if disk_bytes < 96*2**30:
        reasons.append('free disk below unchanged 96GiB gate')
    if not 0 <= load1 < 48:
        reasons.append('load does not satisfy unchanged load<48 gate')
    return dict(eligible=not reasons, reasons=reasons, memory_kib=memory_kib,
                disk_bytes=disk_bytes, load1=load1,
                thresholds=dict(memory_gib=128, disk_gib=96, load_exclusive=48))


def properties(unit):
    raw = subprocess.run(['systemctl', 'show', unit, '-p', 'MainPID',
                          '-p', 'ControlGroup', '-p', 'ActiveState'],
                         check=True, capture_output=True, text=True).stdout
    return dict(row.split('=', 1) for row in raw.splitlines() if '=' in row)


def exact_empty(unit, values=None, hierarchy=Path('/sys/fs/cgroup/systemd')):
    assert unit in PRODUCERS + OLD_WORKERS
    values = properties(unit) if values is None else values
    if values.get('MainPID') != '0' or values.get('ActiveState') not in ['inactive', 'failed']:
        return False
    expected = '/system.slice/'+unit
    if values.get('ControlGroup', '') not in ['', expected]:
        return False
    if not hierarchy.is_dir():
        return False
    target = hierarchy/expected.lstrip('/')
    if not target.exists():
        return True
    if not (target/'cgroup.procs').is_file():
        return False
    return all(not p.read_text().strip() for p in target.rglob('cgroup.procs'))


def old_attempts_unchanged():
    # Four failures were at the pre-CAD load assertion. Never retry a real
    # physical attempt, partial DCP or sealed input under the old identity.
    history = read(C/'prior-failures.json')
    for path, expected in history['files'].items():
        assert sha(path) == expected, ('prior failure changed; adopt and review', path)
    for p, mode in VARIANTS:
        old = ROOT/(p+'-'+mode)
        assert not any(old.glob('*.dcp')), 'old physical attempt now exists'
        assert not (old/'sealed-inputs.json').exists()
        assert not (old/'recovery.log').exists()
        assert not (old/'result.json').exists()


def load_original():
    spec = importlib.util.spec_from_file_location('round51_strict_guard', R2/'guard.py')
    guard = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(guard)
    guard.verify()
    m = guard.module()
    m.unit_empty = exact_empty
    # Only output location changes. r1 capsule, TCL, target/source/clock checks
    # and capsule_inputs_sha256 remain exactly compatible with the live follower.
    m.OUTPUT = OUT
    return m


def status(state, **extra):
    save(STATE, dict(schema='ec-svb-component-resource-recovery/1', **identity(),
                    status=state, updated_utc=now(), fpga_access=False,
                    target_changed=False, complete_opt4=False,
                    functional_baseline=BASE, source_id=SID, **extra))


def guard_race(error):
    # Accept only the two original pre-CAD resource assertion sites as deferral.
    frames = traceback.extract_tb(error.__traceback__)
    return (type(error) is AssertionError and not error.args and frames
            and Path(frames[-1].filename) == R1/'run.py'
            and frames[-1].lineno in [141, 142])


def run_attempt(m, producer, mode, resource_fn=resources):
    gate = resource_fn()
    if not gate['eligible']:
        status('DEFERRED_UNCHANGED_RESOURCE_GUARDS_NO_CAD_ATTEMPT', resources=gate)
        return 'deferred'
    policy()
    current = m.eligibility(producer, mode)
    if not current['eligible']:
        status('WAITING_STRICT_PRODUCER_ELIGIBILITY', eligibility=current)
        return 'deferred'
    if not all(exact_empty(unit) for unit in OLD_WORKERS):
        status('ADOPT_OLD_RECOVERY_TASKS_NO_DUPLICATE')
        return 'deferred'
    out = OUT/(producer+'-'+mode)
    try:
        m.run(producer, mode)
    except Exception as error:
        # A load/memory/disk race before r1 creates state is still no attempt.
        if guard_race(error) and not (out/'state.json').exists():
            status('DEFERRED_PRE_CAD_RESOURCE_RACE', error=repr(error), resources=resource_fn())
            return 'deferred'
        failure = dict(status='FAILED_WITH_EVIDENCE', error=repr(error),
                       traceback=traceback.format_exc(), **identity(), failed_utc=now(),
                       producer=producer, mode=mode, fpga_access=False)
        save(OUT/(producer+'-'+mode+'-failure.json'), failure)
        return 'failed'
    return 'finished'


def publish(result_path):
    policy()
    result_path = result_path.resolve()
    assert result_path.is_relative_to(OUT)
    r = read(result_path)
    assert r['status'] == 'BITSTREAM_WRITTEN_PENDING_INDEPENDENT_CERTIFICATION'
    assert r['functional_baseline'] == BASE and r['source_id'] == SID
    assert not r['target_changed'] and not r['fpga_access'] and not r['complete_opt4']
    assert r['capsule_inputs_sha256'] == sha(R1/'inputs.json')
    assert read(result_path.parent/'complete.json')['result_sha256'] == sha(result_path)
    assert all(sha(p) == h for p, h in r['outputs'].items())
    chosen = ROOT/'chosen-physical-result.json'
    choice = dict(result=str(result_path), result_sha256=sha(result_path), source_id=SID,
                  functional_baseline=BASE, chosen_utc=now(), fpga_access=False)
    old = read(chosen)
    if old:
        assert old['result_sha256'] == choice['result_sha256'], 'existing certified-route candidate wins'
    else:
        save(chosen, choice)
    return choice


def main():
    verify()
    assert read(C/'preflight.json')['status'] == 'PASS_RESOURCE_DEFERRAL_AND_STRICT_CGROUP_NEGATIVES'
    old_attempts_unchanged()
    OUT.mkdir(exist_ok=True)
    lock = (OUT/'controller.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    allowed = set(os.sched_getaffinity(0)) & {254, 255}
    assert allowed == {254, 255}, 'retain reserved component repair CPUs'
    os.sched_setaffinity(0, allowed)
    m = load_original()
    while True:
        policy()
        if (ROOT/'chosen-physical-result.json').exists():
            status('ADOPT_EXISTING_PHYSICAL_CHOICE_NO_DUPLICATE')
            break
        if any((D/n/'complete.json').exists() for n in [
                'cycleprecise-original-svb-onboard-r1-20261111',
                'cycleprecise-original-svb-spread-onboard-r2-20261111']):
            status('EXISTING_COMPONENT_MEASUREMENT_WINS')
            break
        priority = read(D/'Opt4-fit-runtime-priority.json')
        if priority.get('status') in ['ACTIVE', 'REQUESTED_AT_SAFE_BOUNDARY']:
            status('WAITING_FULL_OPT4_PRIORITY')
            time.sleep(300)
            continue
        if not all(exact_empty(unit) for unit in OLD_WORKERS):
            status('ADOPT_OLD_RECOVERY_TASKS_NO_DUPLICATE')
            time.sleep(300)
            continue
        for producer, mode in VARIANTS:
            root = OUT/(producer+'-'+mode)
            if read(root/'result.json').get('status') == 'BITSTREAM_WRITTEN_PENDING_INDEPENDENT_CERTIFICATION':
                choice = publish(root/'result.json')
                status('HANDED_TO_EXISTING_CERTIFICATE_FOLLOWER_NO_FPGA_IO', choice=choice)
                save(OUT/'complete.json', dict(status='HANDED_TO_CERTIFICATION_NOT_FPGA_RESULT',
                     choice=choice, completed_utc=now(), fpga_access=False))
                return
        gate = resources()
        if not gate['eligible']:
            status('DEFERRED_UNCHANGED_RESOURCE_GUARDS_NO_CAD_ATTEMPT', resources=gate)
            time.sleep(300)
            continue
        candidates = [(p, mode) for p, mode in VARIANTS
                      if not (OUT/(p+'-'+mode)/'state.json').exists()
                      and not (OUT/(p+'-'+mode+'-failure.json')).exists()]
        if not candidates:
            status('BOUNDED_VARIANTS_EXHAUSTED_WITH_IMMUTABLE_FAILURES')
            break
        ran = False
        # Share the old global physical lock; never overlap any actual repair.
        with (ROOT/'instance.lock').open('a') as physical_lock:
            try:
                fcntl.flock(physical_lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
            except BlockingIOError:
                status('ADOPT_EXISTING_PHYSICAL_LOCK_OWNER')
            else:
                for producer, mode in candidates:
                    if not m.eligibility(producer, mode)['eligible']:
                        continue
                    status('ADMITTED_COMPONENT_REPAIR_UNCHANGED_GUARDS', producer=producer,
                           mode=mode, resources=gate)
                    outcome = run_attempt(m, producer, mode)
                    ran = outcome != 'deferred'
                    break
        if not ran:
            time.sleep(300)
    save(OUT/'complete.json', dict(status=read(STATE)['status'], completed_utc=now(),
                                 fpga_access=False, no_fpga_result=True))


if __name__ == '__main__':
    main()
