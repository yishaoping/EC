#!/usr/bin/env python3
"""Accept a complete 64-entry History pressure program, not a bounded probe."""
import argparse
import json
from pathlib import Path
import re
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent.parent / 'rollback'))
from build_io_observer import digest
import fullcore_scoreboard


def check(program, pressure, run_exit):
    assert Path(run_exit).read_text().strip() == '0', 'program did not exit successfully'
    signature, events = fullcore_scoreboard.records(program)
    assert signature[0] == '974ea63763416da0', 'not the frozen complete pressure workload'
    results = [f for n, f in events if n == 'PALIMPSEST_RESULT']
    assert results and all((f['pass'], f['fail'], f['cancelled']) == (1, 0, 0)
                           for f in results), 'pressure run contains FAIL or cancellation'
    samples, seals = [], []
    for line in Path(pressure).read_text().splitlines():
        assert line.startswith(('HISTORY ', 'CAPACITY_SEAL ')), 'unknown pressure record'
        fields = {k: int(v, 16 if k == 'seal' else 10)
                  for k, v in re.findall(r'(\w+)=([0-9a-f]+)', line)}
        if line.startswith('HISTORY '):
            assert set(fields) == {'tick', 'clock', 'free', 'state', 'capacity', 'stop', 'seq'}
            assert 0 <= fields['free'] <= 64
            assert not samples or fields['tick'] >= samples[-1]['tick']
            samples.append(fields)
        else:
            seals.append(fields)
    assert samples and seals, 'missing actual History or producer observations'
    # This is the original nonempty-ROB/slow-CDC first-bad boundary.
    first_seals = [s for s in seals if s['ghm_seq'] == 1 and s['ghm_end'] and
                   s['end_sent'] and s['count'] == 64 and s['seal']]
    assert first_seals, 'Seq1 never sealed with actual END/count=64'
    assert any(f['seq'] == 1 for f in results), 'Seq1 did not finish checker validation'
    full = next((s for s in samples if s['seq'] and s['free'] == 0), None)
    assert full, 'UNCOVERED: real 64/64 History capacity was not reached'
    released = next((s for s in samples if s['tick'] > full['tick'] and
                     s['free'] >= 48 and s['seq'] > full['seq']), None)
    assert released, 'full History never released capacity and advanced package'
    assert any(f['seq'] > released['seq'] for f in results), 'no later complete Checker PASS'
    assert samples[-1]['free'] == 64, 'History owners remain at program completion'
    return {'status': 'PASS', 'checksum': signature[0], 'actual_history_entries': 64,
            'first_sealed_package': first_seals[0], 'full': full,
            'released': released, 'last_history': samples[-1],
            'checker_passes': len(results), 'no_fail_or_cancel': True}


def main():
    p = argparse.ArgumentParser(description=__doc__)
    for name in ('program', 'pressure', 'run-exit', 'report'):
        p.add_argument('--' + name, type=Path, required=True)
    a = p.parse_args()
    assert not a.report.exists(), 'preserve prior verdict'
    paths = [a.program, a.pressure, a.run_exit, Path(__file__).resolve(),
             Path(fullcore_scoreboard.__file__)]
    hashes = {str(p): digest(p) for p in paths}
    result = check(a.program, a.pressure, a.run_exit)
    assert all(digest(Path(p)) == h for p, h in hashes.items()), 'evidence changed'
    result['inputs'] = hashes
    a.report.write_text(json.dumps(result, indent=2) + '\n')
    print('PALIMPSEST_PRESSURE_FULL_PROGRAM=PASS History=64/64 final_free=64')


if __name__ == '__main__':
    main()
