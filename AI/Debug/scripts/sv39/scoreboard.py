#!/usr/bin/env python3
"""Check every physical Sv39 load and the surviving architectural operations.

This is the fixed compact-sv39 workload (load PC 0x8000045c, round in x5).
Main's actual commit trace binds each physical request/response/terminal to
its round and returned x12. SCP capture records the committed prefix and x5;
Restore undoes exactly that suffix. No physical access, even discarded work,
is ignored. Normal and fault runs must both end with exactly rounds 0..15.
"""
import argparse
from collections import deque
import hashlib
import json
from pathlib import Path
import re
import sys

ROOT = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(ROOT / 'AI/Debug/scripts/rollback'))
import fullcore_scoreboard


def scan(path, pc=0x8000045c):
    inflight, completed, commits = {}, deque(), deque()
    attempts, logical, discarded = [], [], []
    checkpoints, restores, markers = {}, [], []
    round_register = None
    expected = [(0x8000a000, 0x3742579900000021), (0x8000b000, 0x69d1e20500000043)]

    def pair():
        # Printfs in different production modules can appear in either order
        # on the same edge. Pair the two independent complete event streams;
        # neither event alone is accepted as an architectural operation.
        while completed and commits:
            item, commit = completed.popleft(), commits.popleft()
            round_index, write, text = commit
            address, value = expected[round_index & 1]
            assert item['request']['addr'] == address, 'physical alias address differs from committed round'
            assert item['response']['data'] == value, 'physical alias value differs, including discarded suffix'
            assert write and int(write[1]) == 12 and int(write[2], 16) == value, 'Main committed wrong alias value'
            item.update(round=round_index, commit=text)
            attempts.append(item)
            logical.append(item)
    with Path(path).open(errors='replace') as stream:
        for line in stream:
            markers.extend(re.findall(r'PALIMPSEST_SV39_RESULT checks=(\d+) expected=(\d+)', line))
            event = re.match(r'STAGE1_TX (LOAD_REQ|LOAD_RESP|LOAD_TERMINAL) source=BOOM ', line)
            if event:
                fields = {k: int(v, 16) for k, v in re.findall(r'(\w+)=([0-9a-f]+)', line)}
                if fields['pc'] != pc:
                    continue
                token = fields['token']
                assert fields['cacheable'] == 1
                if event[1] == 'LOAD_REQ':
                    assert token not in inflight, 'duplicate unresolved alias request token'
                    inflight[token] = {'request': fields}
                elif event[1] == 'LOAD_RESP':
                    item = inflight[token]
                    assert 'response' not in item and item['request']['addr'] == fields['addr']
                    item['response'] = fields
                else:
                    item = inflight.pop(token)
                    assert item['response']['addr'] == fields['addr'], 'terminal address changed'
                    item['terminal'] = fields
                    completed.append(item)
                    pair()
                continue
            commit = re.match(r'C:0 \d+ 0x([0-9a-f]+) ', line)
            if commit:
                write = re.search(r' x\s*(\d+) 0x([0-9a-f]+)', line)
                if write and int(write[1]) == 5:
                    round_register = int(write[2], 16)
                if int(commit[1], 16) != pc:
                    continue
                assert round_register is not None and 0 <= round_register < 16, 'missing/invalid committed round'
                commits.append((round_register, write, line.strip()))
                pair()
                continue
            if line.startswith('PALIMPSEST_SCP_CAPTURE '):
                fields = {k: int(v, 16) for k, v in re.findall(r'(\w+)=([0-9a-f]+)', line)}
                assert not commits, 'SCP captured before an older committed alias terminal'
                checkpoints[fields['seq']] = dict(fields, round_register=round_register, prefix=len(logical))
            elif line.startswith('PALIMPSEST_ARCH_RESTORE '):
                fields = {k: int(v, 16) for k, v in re.findall(r'(\w+)=([0-9a-f]+)', line)}
                checkpoint = checkpoints[fields['seq']]
                assert checkpoint['pc'] == fields['pc'], 'restore did not use SCP PC'
                assert not inflight and not completed and not commits, 'unpaired physical alias work at restore boundary'
                assert checkpoint['prefix'] <= len(logical)
                suffix = logical[checkpoint['prefix']:]
                discarded.extend(suffix)
                logical = logical[:checkpoint['prefix']]
                round_register = checkpoint['round_register']
                restores.append({'restore': fields, 'checkpoint': checkpoint,
                                 'discarded_rounds': [x['round'] for x in suffix]})
    assert markers == [('16', '16')], 'missing/incorrect Sv39 software oracle'
    assert not inflight and not completed and not commits, 'unpaired/extra physical alias operation'
    assert [x['round'] for x in logical] == list(range(16)), 'surviving logical alias sequence differs'
    assert len(attempts) == len(logical) + len(discarded), 'physical operation accounting mismatch'
    return {'physical_attempts': attempts, 'surviving': logical, 'discarded': discarded, 'restores': restores}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--normal', type=Path, required=True)
    parser.add_argument('--fault', type=Path, required=True)
    parser.add_argument('--report', type=Path, required=True)
    args = parser.parse_args()
    fullcore_scoreboard.check(args.normal, args.fault, 8)
    result = {kind: scan(path) for kind, path in [('normal', args.normal), ('fault', args.fault)]}
    assert not result['normal']['restores'] and not result['normal']['discarded']
    assert len(result['fault']['restores']) == 1
    assert result['fault']['restores'][0]['restore']['seq'] == 8
    # Derive physical attempt count from the real captured/restored prefix;
    # there is no exemption for incorrect values in discarded operations.
    result['inputs_sha256'] = {}
    for p in [args.normal, args.fault, Path(__file__), Path(fullcore_scoreboard.__file__)]:
        h = hashlib.sha256()
        with p.open('rb') as stream:
            for block in iter(lambda: stream.read(1024 * 1024), b''):
                h.update(block)
        result['inputs_sha256'][str(p)] = h.hexdigest()
    with args.report.open('x') as stream:
        json.dump(result, stream, indent=2)
        stream.write('\n')
    print('PALIMPSEST_SV39_PAIR=PASS surviving=16/16 physical=' +
          '/'.join(str(len(result[k]['physical_attempts'])) for k in ['normal', 'fault']) +
          ' discarded=' + str(len(result['fault']['discarded'])))


if __name__ == '__main__':
    main()
