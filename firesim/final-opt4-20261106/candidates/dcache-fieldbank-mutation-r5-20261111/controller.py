#!/usr/bin/python3
"""Reuse authenticated 512 positive words; finish four actual-write mutations.

The r4 harness regex did not span multiline emitted write expressions. It did
not produce or run any mutation. Preserve all r4 artifacts and do not repeat SAT.
"""
from pathlib import Path
import datetime
import fcntl
import hashlib
import json
import os
import re
import subprocess

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
P = D / 'build-logs/Opt4-fit-dcache-fieldbank-generated-proof-r4-20261111'
O = D / 'build-logs/Opt4-fit-dcache-fieldbank-mutation-r5-20261111'
S = D / 'Opt4-fit-dcache-fieldbank-mutation-r5-state.json'
COMMIT = 'd9d732622601ed792a2647546006b5aae986ab8e'
SID = '1639f464d8675806abb5d7dd04adc5dfd1fcf0e351e016ef6a20adcbea1b6e4e'


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''):
            h.update(block)
    return h.hexdigest()


def now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()


def ident(pid):
    try:
        fields = Path(f'/proc/{pid}/stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=pid, start_ticks=fields[19], process_state=fields[0],
                    host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    except FileNotFoundError:
        return {}


def live(old):
    current = ident(old.get('pid', 0))
    return bool(current and current['start_ticks'] == str(old.get('start_ticks'))
                and current['host_boot_id'] == old.get('host_boot_id')
                and current['process_state'] not in ['Z', 'X'])


def save(path, value):
    path = Path(path)
    temp = path.with_name(path.name + '.tmp-' + str(os.getpid()))
    with temp.open('w') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n'); f.flush(); os.fsync(f.fileno())
    os.replace(temp, path)


def policy():
    p = read(D / 'unattended-opt4/campaign-policy.json')
    assert p['functional_baseline_commit'] == '8491167d84b6d9521b151a743673c1516926a1f8'
    assert p['area_equivalence_only'] and not p['functional_extensions_allowed']
    assert not p['fpga_access'] and p['native_paused']


def main():
    policy()
    O.mkdir(exist_ok=True)
    lock = (O / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not S.exists(), 'preserve prior recovery; new version required'
    assert all(sha(p) == h for p, h in read(C / 'input-hashes.json').items())
    prior = read(C / 'evidence/prior-proof-state.json')
    assert prior['status'] == 'FAILED_WITH_EVIDENCE' and prior['covered_count'] == 512
    assert not live(prior) and not live(prior.get('child', {})), 'adopt original job'
    contract = read(P / 'extraction-contract.json')
    assert contract['hardware_commit'] == COMMIT and contract['source_id'] == SID
    assert len(contract['all_generation_observations']) == 512
    rtl = (P / 'GeneratedOwnerTransition.v').read_text()
    assert sha(P / 'GeneratedOwnerTransition.v') == contract['miter_sha256']
    covered = set()
    reused = []
    original = 'assign equivalent = &{' + ','.join(
        'word_equal_' + str(i) + ' & tap_equal_' + str(i) for i in range(512)) + '};'
    assert rtl.count(original) == 1
    for first in range(0, 512, 8):
        label = f'slots-{first:03d}-{first+7:03d}'
        receipt = P / (label + '-result.json')
        result = read(receipt)
        assert result['returncode'] == 0 and result['accepted'] and not result['timeout']
        assert result['mutation'] is None and result['slots'] == list(range(first, first+8))
        assert sha(result['log']) == result['log_sha256']
        assert sha(P / (label + '.v')) == result['miter_sha256']
        assert 'SUCCESS' in Path(result['log']).read_text()
        # Authenticate that only the output partition changed from the exact
        # source-bound miter, not assumptions or the positive logic itself.
        expected = rtl.replace(original, 'assign equivalent = &{' + ','.join(
            'word_equal_' + str(i) + ' & tap_equal_' + str(i) for i in result['slots']) + '};')
        assert hashlib.sha256(expected.encode()).hexdigest() == result['miter_sha256']
        covered.update(result['slots'])
        reused.append(dict(path=str(receipt), sha256=sha(receipt), slots=result['slots']))
    assert covered == set(range(512))
    state = dict(schema='ec-opt4-generated-field-mutation-continuation/1', **ident(os.getpid()),
                 hardware_commit=COMMIT, source_id=SID, covered_count=512,
                 inherited_positive_partitions=reused, positive_sat_repeated=False,
                 status='VERIFIED_INHERITED_512WORD_POSITIVE_PARTITIONS', stages={},
                 started_utc=now(), fpga_access=False, whole_dut_formal=False,
                 full_dcache_cycles_verified=False, actual_field_write_mutations_rejected=0)

    def update(**kw):
        state.update(kw); state['updated_utc'] = now(); save(S, state)

    update(extraction_contract_sha256=sha(P / 'extraction-contract.json'))
    for memory, writer in contract['physical_writers'].items():
        policy()
        width = writer['bits']
        declaration = re.search(r'wire \[' + str(width-1) + r':0\] raw_next_0_'
                                + re.escape(memory) + r' = [^;]+;', rtl)
        assert declaration, ('actual raw field transition absent', memory)
        before = declaration.group(0)
        marker = '? (' + writer['data'] + ') : previous_raw[' + str(writer['hi']) + ':' + str(writer['lo']) + ']'
        assert before.count(marker) == 1, ('actual extracted data branch not authenticated', memory)
        after = before.replace(marker, '? ((' + writer['data'] + ') ^ ' + str(width) + "'h1) : previous_raw["
                               + str(writer['hi']) + ':' + str(writer['lo']) + ']')
        mutated = rtl[:declaration.start()] + after + rtl[declaration.end():]
        mutated = mutated.replace(original, 'assign equivalent = word_equal_0 & tap_equal_0;')
        label = 'mutation-' + memory
        v = O / (label + '.v')
        with v.open('x') as f:
            f.write(mutated)
        ys = O / (label + '.ys')
        with ys.open('x') as f:
            f.write(f'read_verilog {v}\nhierarchy -check -top GeneratedOwnerTransition\n'
                    'proc\nopt\nopt_clean -purge\n'
                    'sat -verify -timeout 45 -set legal_interface 1 -prove equivalent 1 -show-inputs\n')
        log = O / (label + '-attempt-1.log')
        argv = ['nice', '-n', '15', '/usr/local/bin/yosys', '-s', str(ys)]
        with log.open('xb', buffering=0) as f:
            child = subprocess.Popen(argv, cwd=O, stdin=subprocess.DEVNULL, stdout=f, stderr=subprocess.STDOUT)
            update(status='RUNNING_' + label.upper(), child=ident(child.pid), stage_log=str(log))
            while child.poll() is None:
                try:
                    child.wait(timeout=30)
                except subprocess.TimeoutExpired:
                    pass
                os.fsync(f.fileno()); update()
        text = log.read_text()
        accepted = child.returncode != 0 and 'proof did fail' in text and 'TIMEOUT' not in text
        row = dict(memory=memory, bits=width, actual_write_data_branch_xor=1,
                   before_sha256=hashlib.sha256(before.encode()).hexdigest(),
                   after_sha256=hashlib.sha256(after.encode()).hexdigest(),
                   miter_sha256=sha(v), log=str(log), log_sha256=sha(log),
                   returncode=child.returncode, mutation_rejected=accepted)
        state['stages'][memory] = row
        save(O / (label + '-result.json'), row)
        update(child={})
        assert accepted, ('negative mutation was not rejected', memory)
        state['actual_field_write_mutations_rejected'] += 1
        update()
    assert state['actual_field_write_mutations_rejected'] == 4
    update(status='PASS_ACTUAL_GENERATED_FOUR_FIELD_WRITERS_512WORD_TRANSITIONS_TAPS_AND_FOUR_DATA_MUTATIONS_NOT_FULL_DCACHE',
           ended_utc=now(), proof_limits=contract['proof_limits'])
    save(O / 'result.json', state)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        state = read(S) if S.exists() else {}
        if state.get('pid') == os.getpid():
            state.update(status='FAILED_WITH_EVIDENCE', error=repr(exc), ended_utc=now())
            save(S, state)
        raise
