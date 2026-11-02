#!/usr/bin/env python3
"""Recover the saved seq67 run's identity accounting, without changing evidence.

This is deliberately scoped to the 133-identity/128-slot capture failure. It
never invents producer statistics, events or footers, and rejects actual loss of
any mandatory record. Use the returned summary only in a separate derived view.
"""
import argparse
from collections import Counter
from copy import deepcopy
import hashlib
import json
from pathlib import Path


RECOVERABLE = {'16:0', '17:0', '18:0', '30:0', '31:0'}
REASONS = {'too_many_observer_identities', 'malformed_producer_statistics',
           'mandatory_producer_footer_mismatch'}


def optional(key):
    kind, hart = map(int, key.split(':'))
    return kind == 1 or (4 <= kind <= 15 and kind != 10) or (kind == 16 and hart != 0)


def digest(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def require(condition, message):
    if not condition:
        raise ValueError(message)


def recover(capture, event_path):
    require(capture.get('schema') == 2 and capture.get('closed') is True and
            capture.get('policy') == 'priority_reserved_v2', 'unsupported capture')
    require(set(capture.get('incomplete_reasons', [])) == REASONS,
            'failure reasons differ from the reviewed identity-cap failure')
    observers, producers = capture['observers'], capture['producers']
    require(len(observers) == 129 and len(producers) == 128 and 'other' in observers,
            'not the reviewed 128-slot overflow')
    require(not capture.get('counts', {}).get('failure_markers_seen'), 'failure marker')
    raw = {}
    lines = {}
    with Path(event_path).open() as stream:
        for number, line in enumerate(stream, 1):
            require(line.endswith('\n'), 'unterminated compact record')
            p = line.rstrip('\n').split('\t')
            require(p[0] in ('SC1', 'SC_END'), 'unrecognized compact record')
            require(len(p) == (23 if p[0] == 'SC1' else 8), 'invalid compact record')
            values = [int(v) for v in p[1:7]]
            require(all(0 <= v < 2**64 for v in values), 'invalid unsigned field')
            kind, hart = values[4:6]
            require(kind < 256 and hart < 65536, 'invalid identity')
            key = f'{kind}:{hart}'
            o = raw.setdefault(key, dict(seen=0, kept=0, omitted=0,
                                        events_seen=0, footers_seen=0))
            o['seen'] += 1
            o['kept'] += 1
            if p[0] == 'SC1':
                require(all(len(v) == 16 and 0 <= int(v, 16) < 2**64 for v in p[7:]),
                        'invalid event data')
                o['events_seen'] += 1
                lines.setdefault(key, []).append(number)
            else:
                count = int(p[7])
                require(0 <= count < 2**64, 'invalid footer count')
                o['footers_seen'] += 1
                o['footer_emitted_count'] = count
    require(len(raw) == 133, 'unexpected raw identity inventory')
    require(set(raw) - set(observers) == RECOVERABLE, 'unexpected merged identities')
    require(set(observers) - set(raw) == {'other'}, 'unexplained observer identity')
    require(set(producers) <= set(raw), 'producer without a raw identity')
    unknown_optional = sorted(set(raw) - set(producers))
    require(len(unknown_optional) == 5 and all(optional(k) for k in unknown_optional),
            'missing mandatory producer statistics')
    merged = dict(seen=0, kept=0, omitted=0, events_seen=0, footers_seen=0)
    for key in RECOVERABLE:
        for field in merged:
            merged[field] += raw[key][field]
    require(all(observers['other'].get(k) == v for k, v in merged.items()),
            'other bucket is not exactly the five preserved STOP identities')
    require(observers['other'].get('footer_emitted_count') == 1,
            'unexpected merged footer value')
    checked = []
    for key, o in raw.items():
        require(o['footers_seen'] == 1, key + ': missing/duplicate footer')
        original = observers.get(key)
        if original:
            require(original.get('kept') == o['kept'] and
                    original.get('seen') == original.get('kept', 0) + original.get('omitted', 0) and
                    original.get('events_seen') == o['events_seen'] + original.get('omitted', 0) and
                    original.get('footers_seen') == 1 and
                    original.get('footer_emitted_count') == o['footer_emitted_count'],
                    key + ': retained/raw accounting mismatch')
        producer = producers.get(key)
        if producer:
            require(producer.get('produced') == producer.get('emitted', 0) + producer.get('omitted', 0)
                    and producer.get('emitted') == o['footer_emitted_count'],
                    key + ': producer/footer mismatch')
        if not optional(key):
            require(producer is not None and producer.get('omitted') == 0 and
                    producer.get('produced') == producer.get('emitted') == o['events_seen'] ==
                    o['footer_emitted_count'] and not producer.get('limit_seen') and
                    (not original or original.get('omitted') == 0),
                    key + ': mandatory loss/limit/mismatch')
            checked.append(key)
    derived = deepcopy(capture)
    derived['observers'].pop('other')
    derived['observers'].update({k: raw[k] for k in RECOVERABLE})
    derived['incomplete_reasons'] = []
    derived['mandatory_evidence_complete'] = True
    derived['optional_evidence_complete'] = False
    derived['offline_recovery'] = dict(
        schema=1, policy='raw_identity_deaggregation_with_complete_mandatory_conservation',
        original_incomplete_reasons=capture['incomplete_reasons'],
        optional_producer_statistics_unavailable=unknown_optional,
        events_added=0, footers_added=0, producer_statistics_added=0)
    audit = dict(status='PASS', raw_identity_count=len(raw), original_identity_cap=128,
                 raw_records=sum(o['kept'] for o in raw.values()),
                 mandatory_identities_checked=sorted(checked),
                 reconstructed_identities={k: dict(raw[k], event_lines=lines[k]) for k in sorted(RECOVERABLE)},
                 unknown_optional_producer_statistics=unknown_optional,
                 note='Missing optional SC_LOG_STATS are not reconstructed. Every mandatory producer, event and footer is conserved independently.')
    return derived, audit


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('run', type=Path)
    ap.add_argument('--output', required=True, type=Path)
    args = ap.parse_args()
    require(not args.output.exists(), 'output must be a new directory')
    source = args.run / 'capture_summary.json'
    derived, audit = recover(json.loads(source.read_text()), args.run / 'safe_chain_events.tsv')
    audit['source_sha256'] = {str(p.resolve()): digest(p) for p in
                              [source, args.run / 'safe_chain_events.tsv']}
    args.output.mkdir(parents=True)
    for name, value in [('capture_summary.json', derived), ('capture_recovery_audit.json', audit)]:
        (args.output / name).write_text(json.dumps(value, indent=2, sort_keys=True) + '\n')
    print(json.dumps({k: audit[k] for k in ['status', 'raw_identity_count', 'raw_records']}))


if __name__ == '__main__':
    main()
