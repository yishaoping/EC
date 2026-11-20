#!/usr/bin/python3
"""Partition recovery of the authenticated generated storage transition miter.

No DUT edits. Every original word is covered, with arbitrary 146-bit state and
reset mask. This remains a transition-cut proof, not whole DCache/DUT formal.
"""
from pathlib import Path
import datetime, fcntl, hashlib, json, os, re, subprocess, time

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
R = D / 'build-logs/Opt4-fit-dcache-generated-owner-proof-r2-20261111'
O = D / 'build-logs/Opt4-fit-dcache-generated-owner-proof-r3-20261111'
S = D / 'Opt4-fit-dcache-generated-owner-proof-r3-state.json'
COMMIT = '2210930f510eccf5518c444dadca4a51bcf6f851'
SID = '548c7b8e1066ba82388ab759127e6d3b5c2a794f2f32ebcdc27b7f653b71d66c'


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def read(p):
    return json.loads(Path(p).read_text())


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
        t = Path(f'/proc/{pid}/stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=pid, start_ticks=t[19], process_state=t[0],
                    host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    except FileNotFoundError:
        return {}


def live(j):
    p = ident(j.get('pid', 0))
    return bool(p and p['start_ticks'] == str(j.get('start_ticks')) and
                p['host_boot_id'] == j.get('host_boot_id') and
                p['process_state'] not in ['Z', 'X'])


def main():
    O.mkdir(exist_ok=True)
    lock = (O / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    old = read(S) if S.exists() else {}
    assert not live(old) and not live(old.get('child', {})), 'adopt existing job'
    st = dict(schema='ec-generated-owner-partition-proof/1', **ident(os.getpid()),
              hardware_commit=COMMIT, source_id=SID, started_utc=now(),
              status='WAITING_ORIGINAL_PROOF_SAFE_EXIT', covered_slots=[],
              fpga_access=False, whole_dut_formal=False, complete_dcache_formal=False)

    def update(**kw):
        st.update(kw)
        st['updated_utc'] = now()
        save(S, st)

    update()
    while True:
        original = read(D / 'Opt4-fit-dcache-generated-owner-proof-r2-state.json')
        if not live(original) and not live(original.get('child', {})):
            break
        update(original_status=original.get('status'))
        time.sleep(30)
    contract = read(R / 'extraction-contract.json')
    assert contract['hardware_commit'] == COMMIT and contract['source_id'] == SID
    assert contract['all_original_words'] == 512 and contract['word_bits'] == 146
    assert contract['closure_rejects_crossword_oldstate']
    assert len(contract['all_generation_observations']) == 512
    for x in contract['inputs'].values():
        assert sha(x['path']) == x['sha256']
    p = R / 'GeneratedOwnerTransition.v'
    assert sha(p) == contract['miter_sha256']
    rtl = p.read_text()
    expected = 'assign equivalent = &{' + ','.join('word_equal_' + str(i) for i in range(512)) + '};'
    assert rtl.count(expected) == 1
    assert sha(D / 'Opt4-fit-dcache-owner-arbiter-proof-r3-state.json') == contract['actual_arbiter_receipt_sha256']
    save(O / 'original-proof-outcome.json', original)
    save(O / 'extraction-contract.json', contract)
    update(status='RUNNING_PARTITIONED_GENERATED_TRANSITION_PROOF',
           contract_sha256=sha(R / 'extraction-contract.json'),
           original_outcome=original['status'], miter_sha256=sha(p),
           proof_scope=contract['proof_limits'])

    def run(slots, negative=False):
        label = ('negative-write-data-bitflip' if negative else f'slots-{slots[0]:03d}-{slots[-1]:03d}')
        out = O / label
        out.mkdir(exist_ok=True)
        result = out / 'result.json'
        sub = rtl.replace(expected, 'assign equivalent = &{' + ','.join('word_equal_' + str(i) for i in slots) + '};')
        if negative:
            # Corrupt a real candidate write-data bit, not the proof predicate.
            sub, count = re.subn(r'(wire \[145:0\] raw_next_0 =.*?\? )\(([^;]+)\)( : previous_raw;)',
                                lambda m: m[1] + '(' + m[2] + " ^ 146'h2)" + m[3], sub)
            assert count == 1, 'negative test must mutate actual candidate write data'
        miter = out / 'miter.v'
        if miter.exists():
            assert miter.read_text() == sub
        else:
            miter.write_text(sub)
        if result.exists():
            r = read(result)
            assert r['miter_sha256'] == sha(miter) and r['slots'] == slots
            assert sha(out / 'proof.log') == r['log_sha256']
            if r['accepted']:
                return True
            if r['timeout']:
                return False
            raise RuntimeError('previous semantic proof failure: ' + str(result))
        ys = out / 'proof.ys'
        ys.write_text(f'read_verilog {miter}\nhierarchy -check -top GeneratedOwnerTransition\nproc\nopt\nopt_clean -purge\nsat -verify -timeout 45 -set legal_interface 1 -prove equivalent 1 -show-inputs\n')
        log = out / 'proof.log'
        assert not log.exists(), 'incomplete proof requires reviewed recovery'
        started = time.monotonic()
        with log.open('xb', buffering=0) as f:
            child = subprocess.Popen(['/usr/local/bin/yosys', '-s', str(ys)], cwd=out,
                                     stdin=subprocess.DEVNULL, stdout=f, stderr=subprocess.STDOUT)
            update(active_partition=label, child=ident(child.pid))
            while child.poll() is None:
                try:
                    child.wait(timeout=30)
                except subprocess.TimeoutExpired:
                    pass
                update()
                os.fsync(f.fileno())
        text = log.read_text()
        timeout = 'timed out' in text.lower() or 'timeout' in text.lower().split('solving problem with')[-1]
        if negative:
            accepted = child.returncode != 0 and 'proof did fail' in text and not timeout
        else:
            accepted = child.returncode == 0 and 'SUCCESS' in text and not timeout
        r = dict(slots=slots, negative_write_data_mutation=negative,
                 returncode=child.returncode, accepted=accepted, timeout=timeout,
                 miter_sha256=sha(miter), log_sha256=sha(log),
                 elapsed_seconds=time.monotonic() - started, ended_utc=now())
        save(result, r)
        update(child={})
        if not accepted and not timeout:
            raise RuntimeError('semantic proof failure: ' + str(result))
        return accepted

    covered = set()

    def prove(slots):
        if run(slots):
            covered.update(slots)
            update(covered_slots=sorted(covered), covered_count=len(covered))
        else:
            assert len(slots) > 1, 'single-word timeout: retain evidence and refine proof'
            middle = len(slots) // 2
            prove(slots[:middle])
            prove(slots[middle:])

    for first in range(0, 512, 8):
        prove(list(range(first, first + 8)))
    assert covered == set(range(512))
    assert run([0], negative=True), 'write-data mutation must be rejected'
    update(status='PASS_ACTUAL_GENERATED_512WORD_TRANSITION_AND_TAPS_WITH_REAL_WRITE_MUTATION_NOT_FULL_DCACHE_FORMAL',
           covered_count=512, actual_write_data_mutation_rejected=True, child={},
           ended_utc=now(), production_admission=False)
    save(O / 'result.json', st)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if S.exists():
            st = read(S)
            if st.get('pid') == os.getpid():
                st.update(status='FAILED_WITH_EVIDENCE', error=repr(exc), ended_utc=now())
                save(S, st)
        raise
