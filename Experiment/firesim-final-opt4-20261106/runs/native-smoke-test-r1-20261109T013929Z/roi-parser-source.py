#!/usr/bin/env python3
"""Read B raw bridge logs only; never certify/commit samples or run a target."""
import argparse
import hashlib
import json
from pathlib import Path

SCHEMA = 'ec-dac-b-raw-roi/1'
FIELDS = ('sequence', 'under_reset', 'state_transition', 'epoch', 'state',
          'source_boom_tick', 'roi_begin_tick', 'roi_end_tick', 'faults')


def inspect_bytes(raw):
    records = raw.splitlines(keepends=True)
    partial = records.pop() if records and not records[-1].endswith(b'\n') else b''
    epochs = {}
    last = None
    issues = []
    parsed = 0
    for number, line in enumerate(records, 1):
        try:
            value = json.loads(line)
            if (value.get('schema') != SCHEMA or value.get('configuration') != 'B' or
                value.get('formal_sample') is not False or value.get('synthetic') is not False or
                value.get('timebase_verified') is not False or value.get('runtime_validated') is not False):
                raise ValueError('not an unverified B raw bridge record')
            if any(type(value.get(n)) is not int or not 0 <= value[n] < 2**64 for n in FIELDS):
                raise ValueError('invalid uint64')
            if value['sequence'] != parsed:
                raise ValueError('missing/duplicate/out-of-order bridge sequence')
            if value['under_reset'] > 1 or value['state_transition'] > 1 or value['state'] > 5:
                raise ValueError('invalid controller enum/boolean')
            epoch, state, tick = value['epoch'], value['state'], value['source_boom_tick']
            if last and not value['under_reset'] and not last['under_reset']:
                if tick < last['source_boom_tick'] or epoch < last['epoch']:
                    raise ValueError('source tick/epoch regressed without reset')
            if epoch:
                item = epochs.setdefault(epoch, {'epoch': epoch, 'states': [], 'faults': 0,
                    'reset_seen': False, 'aborted': False, 'roi_cycles': None,
                    'source_boundaries_complete': False, 'formal_sample_eligible': False})
                item['faults'] |= value['faults']
                item['reset_seen'] |= bool(value['under_reset'])
                if not item['states'] or item['states'][-1] != state:
                    item['states'].append(state)
                if state == 0:
                    item['aborted'] = True
                if state in (2, 3, 4):
                    begin, end = value['roi_begin_tick'], value['roi_end_tick']
                    if begin > tick or (state in (3, 4) and not begin < end <= tick):
                        raise ValueError('invalid source marker timestamps')
                    if 'begin_tick' in item and item['begin_tick'] != begin:
                        raise ValueError('begin timestamp changed within epoch')
                    item['begin_tick'] = begin
                    if state in (3, 4):
                        if 'end_tick' in item and item['end_tick'] != end:
                            raise ValueError('end timestamp changed within epoch')
                        item['end_tick'] = end
                        item['roi_cycles'] = end-begin
                item['source_boundaries_complete'] = (item['states'] == [1, 2, 3, 4] and
                    not item['faults'] and not item['reset_seen'] and not item['aborted'])
            parsed += 1
            last = value
        except (ValueError, KeyError, TypeError, AttributeError) as error:
            issues.append({'line': number, 'error': str(error)})
            break
    return {'schema': SCHEMA, 'parsed_records': parsed, 'file_sha256': hashlib.sha256(raw).hexdigest(),
            'partial_tail_bytes': len(partial), 'protocol_issues': issues,
            'last_sequence': last['sequence'] if last else None,
            'epochs': list(epochs.values()), 'formal_sample_eligible': False,
            'runtime_validation': 'NOT_ESTABLISHED_BY_RAW_LOG',
            'warning': 'Raw ROI boundaries only. Output/job identity, runtime timebase checks and the formal host collector are still required.'}


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('log', type=Path)
    p.add_argument('--out', type=Path, required=True)
    p.add_argument('--allow-partial', action='store_true', help='inspect complete prefix after interruption; partial tail remains explicit')
    a = p.parse_args()
    report = inspect_bytes(a.log.read_bytes())
    report['log'] = str(a.log.resolve())
    a.out.parent.mkdir(parents=True, exist_ok=True)
    with a.out.open('x') as f:
        json.dump(report, f, indent=2); f.write('\n')
    print(a.out)
    return 2 if report['protocol_issues'] or (report['partial_tail_bytes'] and not a.allow_partial) else 0


if __name__ == '__main__':
    raise SystemExit(main())
