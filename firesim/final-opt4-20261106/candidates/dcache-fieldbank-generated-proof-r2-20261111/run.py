#!/usr/bin/python3
"""Authenticate and prove d9's actual four-memory owner transition cut.

No source, generated RTL, existing controller, CAD, or FPGA modifications.
The frozen full-DCache cycle comparison remains a separate admission gate.
"""
from pathlib import Path
import datetime
import fcntl
import hashlib
import json
import os
import re
import shutil
import subprocess
import time

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
O = D / 'build-logs/Opt4-fit-dcache-fieldbank-generated-proof-r2-20261111'
S = D / 'Opt4-fit-dcache-fieldbank-generated-proof-r2-state.json'
COMMIT = 'd9d732622601ed792a2647546006b5aae986ab8e'
SID = '1639f464d8675806abb5d7dd04adc5dfd1fcf0e351e016ef6a20adcbea1b6e4e'
BASELINE = '8491167d84b6d9521b151a743673c1516926a1f8'


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''):
            h.update(block)
    return h.hexdigest()


def read(p):
    p = Path(p)
    return json.loads(p.read_text()) if p.is_file() else {}


def now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()


def save(p, j):
    p = Path(p)
    p.parent.mkdir(parents=True, exist_ok=True)
    q = p.with_name(p.name + '.tmp-' + str(os.getpid()))
    with q.open('w') as f:
        json.dump(j, f, indent=2, sort_keys=True)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())
    os.replace(q, p)


def ident(pid):
    try:
        s = Path(f'/proc/{pid}/stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=pid, start_ticks=s[19], process_state=s[0],
                    host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    except FileNotFoundError:
        return {}


def live(j):
    i = ident(j.get('pid', 0))
    return bool(i and i['start_ticks'] == str(j.get('start_ticks'))
                and i['host_boot_id'] == j.get('host_boot_id')
                and i['process_state'] not in ['X', 'Z'])


def policy():
    p = read(D / 'unattended-opt4/campaign-policy.json')
    assert p['functional_baseline_commit'] == BASELINE
    assert p['area_equivalence_only'] and not p['functional_extensions_allowed']
    assert not p['fpga_access'] and p['native_paused']
    return p


def resource_gate():
    mem = int(next(s.split()[1] for s in Path('/proc/meminfo').read_text().splitlines()
                   if s.startswith('MemAvailable:'))) / 2**20
    load = float(Path('/proc/loadavg').read_text().split()[0])
    return mem >= 256 and load < 96 and shutil.disk_usage(W).free >= 40 * 2**30


def main():
    policy()
    O.mkdir(exist_ok=True)
    lock = (O / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    prior = read(S)
    assert not live(prior) and not live(prior.get('child', {})), 'adopt existing identity'
    assert not prior, 'failure or partial stage needs a new reviewed controller version'
    evidence = read(C / 'evidence/snapshot-manifest.json')
    assert all(sha(original) == row['sha256'] == sha(row['snapshot']) for original, row in evidence.items())
    manifest = read(C / 'input-hashes.json')
    assert manifest and all(sha(p) == h for p, h in manifest.items())
    st = dict(schema='ec-opt4-generated-fieldbank-proof/1', **ident(os.getpid()),
              status='WAITING_AUTHENTICATED_FIELD_GOLDENGATE', hardware_commit=COMMIT,
              source_id=SID, functional_baseline_commit=BASELINE, started_utc=now(),
              fpga_access=False, full_dut_formal=False, complete_dcache_formal=False,
              production_admission=False, stages={}, covered_slots=[])

    def update(**kw):
        st.update(kw)
        st['updated_utc'] = now()
        save(S, st)

    update()
    while True:
        policy()
        rtl = read(D / 'Opt4-fit-dcache-fieldbank-rtl-state.json')
        producer = read(D / 'Opt4-fit-dcache-fieldbank-system-r1-state.json')
        if rtl.get('status') == 'GOLDENGATE_COMPLETE_NOT_SYNTHESIZED':
            assert rtl['hardware_commit'] == COMMIT and rtl['source_id'] == SID
            break
        if producer.get('status') in ['FAILED_WITH_EVIDENCE', 'DEPENDENCY_FAILED_WITH_EVIDENCE']:
            update(status='DEPENDENCY_FAILED_WITH_EVIDENCE', producer_status=producer['status'])
            save(O / 'result.json', st)
            return
        update(producer_status=producer.get('status'))
        time.sleep(300)
    source = read(D / 'Opt4-fit-dcache-owner-fieldbanks-r1-state.json')
    parent = read(D / 'Opt4-fit-dcache-generated-owner-proof-r3-state.json')
    assert source['source_id'] == SID and source['hardware_commit'] == COMMIT
    assert source['status'].startswith('PASS_SOURCE_BOUND_FIELD_STORAGE_RELATION_')
    assert parent['status'].startswith('PASS_ACTUAL_GENERATED_512WORD_TRANSITION_AND_TAPS_')
    save(O / 'source-validation-receipt.json', source)
    save(O / 'parent-generated-proof-receipt.json', parent)

    def run(label, argv, negative=False):
        policy()
        while not resource_gate():
            update(status='WAITING_LIGHT_AUXILIARY_RESOURCE_GATE', next_stage=label)
            time.sleep(300)
            policy()
        log = O / (label + '.log')
        assert not log.exists(), 'preserve every partial log; use versioned recovery'
        with log.open('xb', buffering=0) as f:
            child = subprocess.Popen(argv, cwd=O, stdin=subprocess.DEVNULL,
                                     stdout=f, stderr=subprocess.STDOUT,
                                     env={**os.environ, 'OMP_NUM_THREADS': '1'})
            update(status='RUNNING_' + label.upper(), active_stage=label, child=ident(child.pid))
            while child.poll() is None:
                try:
                    child.wait(timeout=30)
                except subprocess.TimeoutExpired:
                    pass
                os.fsync(f.fileno())
                update()
        result = dict(returncode=child.returncode, argv=argv, log=str(log),
                      log_sha256=sha(log), ended_utc=now())
        if label == 'extract':
            result['accepted'] = child.returncode == 0
        else:
            text = log.read_text()
            result['timeout'] = 'timed out' in text.lower() or 'TIMEOUT!' in text
            result['accepted'] = (child.returncode != 0 and 'proof did fail' in text
                                  if negative else child.returncode == 0 and 'SUCCESS' in text)
            result['accepted'] &= not result['timeout']
        save(O / (label + '-result.json'), result)
        st['stages'][label] = result
        update(child={})
        return result

    assert run('extract', ['/usr/bin/python3', str(C / 'extract.py')])['accepted']
    contract = read(O / 'extraction-contract.json')
    assert contract['hardware_commit'] == COMMIT and contract['source_id'] == SID
    assert len(contract['all_generation_observations']) == 512
    assert set(contract['physical_writers']) == {
        'ownerImageMemory', 'ownerGenerationMemory', 'ownerPacketMemory', 'ownerTrackedMemory'}
    miter = O / 'GeneratedOwnerTransition.v'
    assert sha(miter) == contract['miter_sha256']
    rtl = miter.read_text()
    original = 'assign equivalent = &{' + ','.join(
        'word_equal_' + str(i) + ' & tap_equal_' + str(i) for i in range(512)) + '};'
    assert rtl.count(original) == 1
    covered = set()
    update(extraction_contract_sha256=sha(O / 'extraction-contract.json'),
           proof_scope=contract['proof_limits'])

    def partition(slots, mutation=None):
        label = ('mutation-' + mutation if mutation else f'slots-{slots[0]:03d}-{slots[-1]:03d}')
        sub = rtl.replace(original, 'assign equivalent = &{' + ','.join(
            'word_equal_' + str(i) + ' & tap_equal_' + str(i) for i in slots) + '};')
        if mutation:
            w = contract['physical_writers'][mutation]
            pattern = (r'(wire \[' + str(w['bits'] - 1) + r':0\] raw_next_0_' + mutation
                       + r' =.*?\? )\(([^;]+)\)( : previous_raw\['
                       + str(w['hi']) + ':' + str(w['lo']) + r'\];)')
            sub, count = re.subn(pattern, lambda m: m[1] + '((' + m[2] + ') ^ '
                                 + str(w['bits']) + "'h1)" + m[3], sub)
            assert count == 1, 'mutation must corrupt the actual generated field write data'
        path = O / (label + '.v')
        assert not path.exists()
        path.write_text(sub)
        script = O / (label + '.ys')
        script.write_text(f'read_verilog {path}\nhierarchy -check -top GeneratedOwnerTransition\n'
                          'proc\nopt\nopt_clean -purge\n'
                          'sat -verify -timeout 45 -set legal_interface 1 -prove equivalent 1 -show-inputs\n')
        result = run(label, ['/usr/local/bin/yosys', '-s', str(script)], bool(mutation))
        result.update(slots=slots, miter_sha256=sha(path), mutation=mutation)
        save(O / (label + '-result.json'), result)
        if result['accepted']:
            if not mutation:
                covered.update(slots)
                update(covered_slots=sorted(covered), covered_count=len(covered))
            return
        if result.get('timeout') and len(slots) > 1 and not mutation:
            middle = len(slots) // 2
            partition(slots[:middle])
            partition(slots[middle:])
            return
        raise RuntimeError('proof did not pass: ' + label)

    for first in range(0, 512, 8):
        partition(list(range(first, first + 8)))
    assert covered == set(range(512))
    for memory in contract['physical_writers']:
        partition([0], mutation=memory)
    update(status='PASS_ACTUAL_GENERATED_FOUR_FIELD_WRITERS_512WORD_TRANSITIONS_TAPS_AND_FOUR_DATA_MUTATIONS_NOT_FULL_DCACHE',
           covered_count=512, actual_field_write_mutations_rejected=4, child={}, ended_utc=now())
    save(O / 'result.json', st)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        st = read(S)
        if st.get('pid') == os.getpid():
            st.update(status='FAILED_WITH_EVIDENCE', error=repr(exc), ended_utc=now())
            save(S, st)
        raise
