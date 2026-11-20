#!/usr/bin/python3
"""Offline, lossless transport audit. Never launches a model or CAD tool."""
import argparse
import fcntl
import json
import os
from pathlib import Path
import resource
import shutil
import sys

C = Path(__file__).resolve().parent
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
OLD = D/'cycleprecise-owner-pair-runtime-r1-20261111'
O = D/'build-logs/Opt4-owner-stdout-prefix-round113-v4-20261112'
S = D/'Opt4-owner-stdout-prefix-round113-v4-state.json'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
HW = '3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
SOURCE = '79aedd9ada6137e018d7f9c9c175fd4a06f53820d235ddcbe4b4a185e75fd68d'
NAME = 'owner-stdout-prefix-r113-v4-3656aec4'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha
from transport_audit import compare, mutation_checks, ELF_FORMATS


def policy():
    p = read(U/'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert p['native_paused'] and not p['fpga_access']
    assert not p['functional_extensions_allowed']
    assert p['board_allowlist'] == ['0000:21:00.0']
    return p


def write_new(path, value):
    with path.open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n'); f.flush(); os.fsync(f.fileno())


def affinity_guard(cpu):
    # Reconcile the periodic snapshot with current broker records, so a newer
    # service cannot be missed simply because it postdates that snapshot.
    rows = list(read(U/'snapshot.json')['states'].values())
    for path in (U/'jobs').glob('*/state.json'):
        row = read(path)
        if row.get('status') != 'RUNNING':
            continue
        rows.append(row)
        rows.extend(read(x) for x in row.get('checkpoints', []))
    seen = set()
    checked = []
    for row in rows:
        for proc in [row, row.get('child', {}), row.get('stage_process', {}),
                     *row.get('worker_processes', [])]:
            pid = proc.get('pid')
            if not pid or pid == os.getpid() or pid in seen or not live(proc):
                continue
            seen.add(pid)
            affinity = os.sched_getaffinity(pid)
            if len(affinity) <= 8:
                assert cpu not in affinity, ('occupied narrow CPU affinity', pid, sorted(affinity))
                checked.append(dict(pid=pid, cpus=sorted(affinity)))
    return checked


def prepare():
    policy()
    assert not (C/'plan.json').exists() and not O.exists()
    reference = read(OLD/'plan.json')
    assert reference['functional_baseline'] == BASE and reference['derived_hardware'] == HW
    assert not live(read(D/'Opt4-mcrams-owner-pair-runtime-r1-state.json'))
    elf = Path(next(a.split('=', 1)[1] for a in reference['reference_args'] if a.startswith('+prog0=')))
    assert sha(elf) == reference['elf_sha256']
    files = [OLD/'plan.json', OLD/'result.json', elf]
    files += [OLD/'receipts'/('run-'+label+'.json') for label in ['Plain', 'MCRams']]
    for version in ['v1', 'v2']:
        files += [D/f'build-logs/Opt4-owner-runtime-timeout-round113-{version}-20261112/prefix-audit.json']
    evidence = {str(path): sha(path) for path in files}
    inputs = {str(path): sha(path) for path in [C/'controller.py', C/'transport_audit.py',
        C/'README.md', W/'scripts/opt4_unattended_common.py']}
    plan = dict(schema='ec-owner-offline-stdout-prefix/1', functional_baseline=BASE,
        hardware_commit=HW, source_id=SOURCE, inputs=inputs, evidence=evidence,
        elf=str(elf), elf_sha256=reference['elf_sha256'], cpu=248,
        narrow_affinities=affinity_guard(248), no_runtime_launch=True,
        target_changed=False, fpga_access=False, whole_fit=False)
    write_new(C/'plan.json', plan)
    request = dict(action='cpu_job', spec=dict(name=NAME, kind='analysis', cwd=str(C),
        argv=['/usr/bin/python3', str(C/'controller.py'), '--run'],
        inputs={**inputs, str(C/'plan.json'): sha(C/'plan.json')},
        outputs=[str(O/'complete.json')], checkpoints=[str(S)]))
    write_new(C/'request.json', request)
    print('PREPARED_OFFLINE_AUDIT_ONLY_NOT_SUBMITTED')


def run():
    policy()
    plan = read(C/'plan.json')
    assert not O.exists(), 'Preserve partial evidence; use a new version'
    assert all(sha(path) == digest for path, digest in {**plan['inputs'], **plan['evidence']}.items())
    checked = affinity_guard(plan['cpu'])
    mem = int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines()
                   if x.startswith('MemAvailable:')))
    assert mem >= 256*2**20 and os.getloadavg()[0] < 96
    assert shutil.disk_usage(D).free >= 40*2**30
    os.sched_setaffinity(0, {plan['cpu']})
    resource.setrlimit(resource.RLIMIT_AS, (2*2**30,)*2)
    O.mkdir()
    lock = (O/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    state = dict(schema='ec-owner-offline-stdout-prefix/1', **identity(), started_utc=now(),
        functional_baseline=BASE, hardware_commit=HW, source_id=SOURCE,
        cpu=plan['cpu'], target_changed=False, fpga_access=False, whole_fit=False,
        no_runtime_launch=True, narrow_affinities=checked)
    def update(status, **extra):
        state.update(status=status, updated_utc=now(), **extra)
        save(S, state)
    try:
        update('AUDITING_SEALED_LOGS_ON_INDEPENDENT_CPU')
        elf = Path(plan['elf']).read_bytes()
        assert all(fmt in elf for fmt in ELF_FORMATS)
        mutations = mutation_checks()
        write_new(O/'transport-mutations.json', mutations)
        with (OLD/'run-MCRams.log').open('rb') as mc, (OLD/'run-Plain.log').open('rb') as plain:
            result = compare(mc, plain)
        for key, label in [('mc', 'MCRams'), ('plain', 'Plain')]:
            assert result['counts'][key]['raw_sha256'] == read(OLD/'receipts'/('run-'+label+'.json'))['log_sha256']
        result.update(state)
        result.update(status='PASS_SEALED_MC_STDOUT_PREFIX_WITH_SIX_ELF_BOUND_UART_ROWS'
            if result['passed'] else 'FAIL_SEALED_STDOUT_PREFIX_PRESERVED', completed_utc=now(),
            plan_sha256=sha(C/'plan.json'), elf_sha256=plan['elf_sha256'],
            mutation_receipt_sha256=sha(O/'transport-mutations.json'),
            immutable_mc_log=str(OLD/'run-MCRams.log'), immutable_plain_log=str(OLD/'run-Plain.log'),
            adopted_runtime_state=str(D/'Opt4-mcrams-owner-mc-runtime-r2-state.json'),
            limitations=['Finite incomplete CPU stdout prefix; no completed ROI or universal equivalence.',
                'All complete bytes retained within each stream; UART host drain interleaving is not target timing.',
                'Existing owner-MC runtime r2 is independent and remains untouched.',
                'No complete Opt4 FIT, FPGA sample, strict checker latency, or new target behavior.'])
        write_new(O/'result.json', result)
        write_new(O/'complete.json', dict(result_sha256=sha(O/'result.json'), completed_utc=now()))
        update(result['status'], result_sha256=sha(O/'result.json'))
        assert result['passed'], result['first_mismatch']
    except Exception as exc:
        update('FAILED_WITH_EVIDENCE', error=repr(exc))
        write_new(O/'failure.json', state)
        raise


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument('--prepare', action='store_true')
    group.add_argument('--run', action='store_true')
    args = parser.parse_args()
    prepare() if args.prepare else run()
