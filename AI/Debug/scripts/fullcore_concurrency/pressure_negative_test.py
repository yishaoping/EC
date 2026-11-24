#!/usr/bin/env python3
"""Require strict rejection of corrupted complete History pressure evidence."""
import argparse
import contextlib
import io
import json
from pathlib import Path
import re
import pressure_scoreboard as score


def main():
    p = argparse.ArgumentParser(description=__doc__)
    for name in ('program', 'pressure', 'run-exit', 'out'):
        p.add_argument('--' + name, type=Path, required=True)
    a = p.parse_args()
    a.out.mkdir()
    paths = [a.program, a.pressure, a.run_exit, Path(__file__).resolve(), Path(score.__file__)]
    hashes = {str(p): score.digest(p) for p in paths}
    score.check(a.program, a.pressure, a.run_exit)
    # Preserve every architectural marker, including complete-program and exit
    # oracles. Only remove noisy instruction text from negative-test copies.
    program = ''.join(line for line in a.program.read_text().splitlines(True)
                      if 'PALIMPSEST_' in line or 'STAGE1_SIM_EXIT' in line)
    pressure = a.pressure.read_text()
    cases = {
        'no_actual_full': ('pressure', re.sub(r'\bfree=0\b', 'free=1', pressure)),
        'missing_producer_end': ('pressure', re.sub(r'\bend_sent=1\b', 'end_sent=0', pressure)),
        'wrong_first_package_count': ('pressure', re.sub(r'\bcount=64\b', 'count=63', pressure)),
        'owners_never_release': ('pressure', re.sub(r'\bfree=(?:4[89]|5\d|6[0-4])\b', 'free=47', pressure)),
        'checksum_corruption': ('program', program.replace('974ea63763416da0', '974ea63763416da1', 1)),
        'missing_program_end': ('program', program.replace('PALIMPSEST_WORKLOAD_END status=PASS', 'REMOVED')),
        'extra_failure': ('program', program + 'PALIMPSEST_RESULT seq=000000ff pass=0 fail=1 cancelled=0\n'),
        'failed_exit': ('run_exit', '1\n'),
    }
    results = {}
    for name, (kind, contents) in cases.items():
        case = a.out / name
        case.mkdir()
        pp, hh, ee = case/'program.log', case/'pressure.log', case/'run.exit'
        pp.write_text(contents if kind == 'program' else program)
        hh.write_text(contents if kind == 'pressure' else pressure)
        ee.write_text(contents if kind == 'run_exit' else '0\n')
        try:
            with contextlib.redirect_stdout(io.StringIO()):
                score.check(pp, hh, ee)
        except AssertionError as error:
            results[name] = {'rejected': True, 'reason': str(error)}
        else:
            raise AssertionError('accepted corrupted pressure evidence: ' + name)
    assert all(score.digest(Path(p)) == h for p, h in hashes.items())
    (a.out/'results.json').write_text(json.dumps({'status': 'PASS', 'inputs': hashes,
        'valid_complete_record_passed': True, 'mutations': results}, indent=2) + '\n')
    print('PALIMPSEST_PRESSURE_NEGATIVE=PASS rejected=' + str(len(results)))


if __name__ == '__main__':
    main()
