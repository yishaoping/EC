#!/usr/bin/env python3
"""Mutate real complete I/O/rebase evidence and require every corruption to fail."""
import argparse
import contextlib
import io
import json
from pathlib import Path
import re
import sys

import io_rebase_scoreboard as score
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'rollback'))
from build_io_observer import digest


def main():
    p = argparse.ArgumentParser(description=__doc__)
    for key in ('normal', 'fault', 'effects', 'overlap', 'out'):
        p.add_argument('--' + key, type=Path, required=True)
    a = p.parse_args()
    root = Path(__file__).resolve().parents[4]
    out = a.out.resolve()
    assert out.is_relative_to(root / 'AI/TMP')
    out.mkdir()
    inputs = {str(x): digest(x) for x in [a.normal, a.fault, a.effects, a.overlap,
              Path(score.__file__), Path(__file__).resolve()]}
    score.check(a.normal, a.fault, a.effects, a.overlap)
    for key in ('normal', 'fault'):
        with getattr(a, key).open(errors='replace') as stream:
            (out / (key + '.log')).write_text(''.join(line for line in stream
                if 'PALIMPSEST_' in line or 'STAGE1_SIM_EXIT' in line))
    (out / 'effects.log').write_bytes(a.effects.read_bytes())
    (out / 'overlap.log').write_bytes(a.overlap.read_bytes())
    original = {k: (out / (k + '.log')).read_text() for k in ('normal', 'fault', 'effects', 'overlap')}
    reset_at = original['fault'].index('PALIMPSEST_SEQ_REBASE_RESET')
    reset_tail, removed = re.subn(
        r'^PALIMPSEST_RESULT seq=00000001 pass=1 fail=0 cancelled=0\n', '',
        original['fault'][reset_at:], count=1, flags=re.M)
    assert removed == 1, 'did not mutate a real Seq1 PASS after physical reset'
    mutations = {
        'hidden_late_fail': ('fault', original['fault'] +
            'PALIMPSEST_RESULT seq=00000028 pass=0 fail=1 cancelled=0\n'),
        'hidden_cancel': ('fault', original['fault'] +
            'PALIMPSEST_RESULT seq=00000029 pass=0 fail=0 cancelled=1\n'),
        'missing_program_oracle': ('fault', re.sub(r'^.*PALIMPSEST_WORKLOAD_RESULT.*\n', '', original['fault'], flags=re.M)),
        'damaged_final_checksum': ('fault', original['fault'].replace('checksum=75f3f507c3419640', 'checksum=75f3f507c3419641')),
        'missing_new_seq1_pass': ('fault', original['fault'][:reset_at] + reset_tail),
        'missing_effect_footer': ('effects', re.sub(r'^IO_EFFECT_OBSERVER_END.*\n', '', original['effects'], flags=re.M)),
    }
    # A valid later physical namespace still must contain exactly 48 device A
    # handshakes. Corrupt its address without disrupting the initial replay.
    lines = original['effects'].splitlines(True)
    last = next(i for i in range(len(lines)-1, -1, -1)
                if 'mem_access_fire=1' in lines[i] and 'addr=200bffc ' in lines[i])
    altered = lines.copy()
    altered[last] = altered[last].replace('addr=200bffc ', 'addr=200bff0 ')
    mutations['lost_later_namespace_device_read'] = ('effects', ''.join(altered))
    rows = original['overlap'].splitlines(True)
    changed = rows.copy()
    reset = next(i for i, line in enumerate(rows) if line.split()[-1] == '1')
    fields = changed[reset].split()
    fields[5] = '1'
    changed[reset] = ' '.join(fields) + '\n'
    mutations['reset_over_pending_journal'] = ('overlap', ''.join(changed))
    changed = rows.copy()
    allocated = next(i for i, line in enumerate(rows)
                     if line.split()[2:4] == ['1', '41'])
    fields = changed[allocated].split()
    fields[4] = '1'
    changed[allocated] = ' '.join(fields) + '\n'
    mutations['premature_reservation'] = ('overlap', ''.join(changed))
    results = {}
    for name, (kind, text) in mutations.items():
        path = out / (name + '.log')
        path.write_text(text)
        args = {k: (path if k == kind else out / (k + '.log'))
                for k in ('normal', 'fault', 'effects', 'overlap')}
        try:
            with contextlib.redirect_stdout(io.StringIO()):
                score.check(**args)
        except (AssertionError, KeyError, ValueError, StopIteration) as error:
            results[name] = {'rejected': True, 'reason': repr(error)}
        else:
            raise AssertionError('accepted corruption: ' + name)
    (out / 'results.json').write_text(json.dumps({'valid_records_passed': True,
        'inputs': inputs, 'mutations': results}, indent=2) + '\n')
    print('PALIMPSEST_IO_REBASE_NEGATIVE=PASS rejected=' + str(len(results)))


if __name__ == '__main__':
    main()
