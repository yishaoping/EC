#!/usr/bin/env python3
"""Offline Stage 2 trace checks. Does not build or run any hardware."""
import argparse
from collections import Counter
import json
from pathlib import Path
import re


def analyze(lines):
    counts, errors, committed, requests = Counter(), [], Counter(), set()
    preserves = Counter()
    snapshots, acknowledged = {}, Counter()
    receipts = {}
    for lineno, line in enumerate(lines, 1):
        match = re.search(r'STAGE2_TX (\w+) (.*)', line)
        if not match:
            continue
        kind, body = match.groups()
        p = {k: int(v, 16) for k, v in re.findall(r'(\w+)=([0-9a-fA-F]+)', body)}
        counts[kind] += 1
        key = tuple(p.get(k) for k in ('valid', 'writer', 'gen', 'seq'))
        def fail(reason):
            errors.append(dict(line=lineno, event=kind, reason=reason, fields=p))
        if kind == 'IMPORT':
            receipts[p['line']] = (p['epoch'], key)
        elif kind == 'PRESERVE_DONE':
            descriptor = (p['line'], p['epoch'])
            if snapshots.pop(descriptor, None) != key or not acknowledged[key]:
                fail('preserve_done_without_matching_snapshot_and_ack')
            else:
                acknowledged[key] -= 1
                if p['accepted']:
                    receipts[p['line']] = (p['epoch'], key)
        elif kind == 'LOWER_COMMIT':
            committed[key] += 1
        elif kind == 'ACK' and p['matched']:
            if not committed[key]:
                fail('matched_ack_without_lower_commit')
            else:
                committed[key] -= 1
            if preserves[key]:
                preserves[key] -= 1
                acknowledged[key] += 1
                counts['PRESERVE_RECEIPT'] += 1
        elif kind == 'PRESERVE':
            descriptor = (p['line'], p['epoch'])
            if descriptor in snapshots:
                fail('duplicate_pending_snapshot')
            snapshots[descriptor] = key
            preserves[key] += 1
            if preserves[key] > 1:
                fail('duplicate_pending_preserve')
        elif kind == 'MODIFY':
            same = p['old_valid'] and p['new_seq'] != 0 and p['old_seq'] == p['new_seq']
            if p['new_seq'] and not same and (not p['safe'] or not p['lower']):
                fail('speculative_overwrite_without_safe_preserved_predecessor')
            if not same and not p['safe']:
                fail('different_writer_overwrote_unsafe_image')
            old_key = tuple(p[k] for k in ('old_valid', 'old_writer', 'old_gen', 'old_seq'))
            if p['new_seq'] and not same and p['lower'] and receipts.get(p['line']) != (p['epoch'], old_key):
                fail('preservation_flag_without_matching_receipt')
            receipts.pop(p['line'], None)
            if p['req'] in requests:
                fail('duplicate_physical_effect')
            requests.add(p['req'])
            if same:
                counts['SAME_PACKAGE'] += 1
            counts['REPLAY_EFFECT' if p['replay'] else 'NORMAL_EFFECT'] += 1
            if p['cmd'] == 7:
                counts['SC_EFFECT'] += 1
            if p['cmd'] in (4, 8, 9, 10, 11, 12, 13, 14, 15):
                counts['AMO_EFFECT'] += 1
        elif kind == 'BLOCK':
            counts['WAIT_SAFE' if not p['safe'] else 'WAIT_PRESERVATION'] += 1
    for key, count in preserves.items():
        if count:
            errors.append(dict(reason='unclosed_preservation', key=key, count=count))
    for descriptor, key in snapshots.items():
        errors.append(dict(reason='unclosed_snapshot', descriptor=descriptor, key=key))
    # Never call an empty trace or missing scenario a pass. Adversarial cases
    # (e.g. a stale receipt) are mandatory in the directed module, not assumed
    # to occur in BFS. Its coverage is checked separately by its CASE markers.
    required = ('MODIFY', 'IMPORT', 'PRESERVE', 'PRESERVE_RECEIPT', 'SAME_PACKAGE',
                'NORMAL_EFFECT', 'REPLAY_EFFECT', 'WAIT_SAFE', 'WAIT_PRESERVATION')
    missing = [name for name in required if not counts[name]]
    return dict(schema=1, status='FAIL' if errors else 'UNCOVERED' if missing else 'PASS',
                counts=dict(counts), errors=errors, missing_coverage=missing)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('trace', type=Path)
    parser.add_argument('--json', type=Path, required=True)
    args = parser.parse_args()
    with args.trace.open(errors='replace') as stream:
        report = analyze(stream)
    args.json.write_text(json.dumps(report, indent=2) + '\n')
    print('STAGE2_TRACE=' + report['status'])
    print('COUNTS=' + json.dumps(report['counts'], sort_keys=True))
    print('MISSING_COVERAGE=' + ','.join(report['missing_coverage']))
    print('ERROR_COUNT=' + str(len(report['errors'])))
    return 1 if report['errors'] else 3 if report['missing_coverage'] else 0


if __name__ == '__main__':
    raise SystemExit(main())
