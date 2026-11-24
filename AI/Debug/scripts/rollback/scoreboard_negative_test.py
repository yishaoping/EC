#!/usr/bin/env python3
"""Mutate real passing full-core records to test rejection of hidden failures."""
import argparse
import contextlib
import hashlib
import io
import json
from pathlib import Path

import fullcore_scoreboard as score


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--normal', type=Path, required=True)
    parser.add_argument('--fault', type=Path, required=True)
    parser.add_argument('--rebase', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[4]
    out = args.out.resolve()
    assert out.is_relative_to(root / 'AI/TMP')
    out.mkdir()
    inputs = {}
    for kind in ('normal', 'fault', 'rebase'):
        source = getattr(args, kind)
        h = hashlib.sha256()
        kept = []
        with source.open('rb') as stream:
            for line in stream:
                h.update(line)
                if b'PALIMPSEST_' in line or b'STAGE1_SIM_EXIT' in line:
                    kept.append(line.decode(errors='replace'))
        inputs[kind] = {'source': str(source), 'sha256': h.hexdigest()}
        (out / f'{kind}.log').write_text(''.join(kept))
    normal, fault, rebase = (out / f'{k}.log' for k in ('normal', 'fault', 'rebase'))
    with contextlib.redirect_stdout(io.StringIO()):
        score.check(normal, fault, 8)
        score.check_rebase(rebase, 16)
    cases = [
        ('normal_cancel', 'normal', 'PALIMPSEST_RESULT seq=000000fe pass=0 fail=0 cancelled=1\n'),
        ('fault_cancel', 'fault', 'PALIMPSEST_RESULT seq=000000fe pass=0 fail=0 cancelled=1\n'),
        ('fault_extra_fail', 'fault', 'PALIMPSEST_RESULT seq=000000fe pass=0 fail=1 cancelled=0\n'),
        ('fault_duplicate_fail', 'fault', 'PALIMPSEST_RESULT seq=00000008 pass=0 fail=1 cancelled=0\n'),
        ('fault_extra_restore', 'fault', 'PALIMPSEST_ARCH_RESTORE seq=000000fe epoch=2 pc=80000380\n'),
        ('fault_extra_evt', 'fault', 'PALIMPSEST_EVT target=000000fe tail=000000fe next_epoch=2\n'),
        ('fault_extra_restart', 'fault', 'PALIMPSEST_RESTART target=000000fe epoch=2 pc=80000380 reconciled=1\n'),
        ('malformed_result', 'fault', 'PALIMPSEST_RESULT seq=000000fe pass=1 fail=1 cancelled=0\n'),
        ('rebase_fail', 'rebase', 'PALIMPSEST_RESULT seq=000000fe pass=0 fail=1 cancelled=0\n'),
        ('rebase_cancel', 'rebase', 'PALIMPSEST_RESULT seq=000000fe pass=0 fail=0 cancelled=1\n'),
        ('rebase_extra_restore', 'rebase', 'PALIMPSEST_ARCH_RESTORE seq=000000fe epoch=2 pc=80000380\n'),
    ]
    results = {}
    for name, kind, addition in cases:
        mutated = out / (name + '.log')
        mutated.write_text((out / f'{kind}.log').read_text() + addition)
        try:
            with contextlib.redirect_stdout(io.StringIO()):
                if kind == 'rebase':
                    score.check_rebase(mutated, 16)
                else:
                    score.check(mutated if kind == 'normal' else normal,
                                mutated if kind == 'fault' else fault, 8)
        except AssertionError as error:
            results[name] = {'rejected': True, 'reason': str(error)}
        else:
            raise AssertionError('accepted a hidden failure: ' + name)
    report = {'inputs': inputs, 'valid_records_passed': True, 'mutations': results,
              'scoreboard_sha256': hashlib.sha256(Path(score.__file__).read_bytes()).hexdigest(),
              'test_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest()}
    (out / 'results.json').write_text(json.dumps(report, indent=2) + '\n')
    print(f'PALIMPSEST_SCOREBOARD_NEGATIVE=PASS rejected={len(results)}')


if __name__ == '__main__':
    main()
