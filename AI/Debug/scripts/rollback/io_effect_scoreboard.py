#!/usr/bin/env python3
"""Check a real IOMSHR effect -> rollback -> raw-word replay without a second A.

--focused checks a bounded signal run only. Without it, --normal is required
and the complete architectural oracle and strict fault pair must also pass.
State encodings are the production IOMSHR Enum(idle, access, ack, response).
The 1->2 transition is exclusively caused by mem_access.fire in that module.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re

import fullcore_scoreboard


def check(effects, log, target, require_output=False, require_amo=False):
    samples = []
    footer = None
    decimal = {'tick', 'clock', 'old_state', 'state', 'journal', 'replay', 'mem_access_fire'}
    required = decimal | {'seq', 'pc', 'addr', 'cmd', 'size', 'operand', 'journal_seq',
                          'journal_pc', 'journal_addr', 'journal_cmd', 'journal_size',
                          'journal_operand', 'journal_word', 'grant_word'}
    with Path(effects).open() as stream:
        for line in stream:
            if line.startswith('IO_EFFECT_OBSERVER_END '):
                assert footer is None, 'duplicate observer footer'
                footer = {k: int(v) for k, v in re.findall(r'(\w+)=(\d+)', line)}
                continue
            assert footer is None and line.startswith('IO_EFFECT_OBSERVER '), 'damaged observer stream'
            fields = dict(re.findall(r'(\w+)=([0-9a-f]+)', line))
            assert fields.keys() == required, f'incomplete observer sample: {line}'
            sample = {k: int(v, 10 if k in decimal else 16) for k, v in fields.items()}
            assert sample['state'] in range(4)
            assert sample['mem_access_fire'] == int(sample['old_state'] == 1 and sample['state'] == 2)
            if samples:
                assert sample['old_state'] == samples[-1]['state'], 'missing state transition'
                assert sample['tick'] >= samples[-1]['tick'], 'observer time reversed'
            else:
                assert sample['old_state'] == (1 << 64) - 1 and sample['state'] == 0
            samples.append(sample)
    assert footer and footer['events'] == len(samples), 'observer did not close cleanly'
    assert footer['last_tick'] >= samples[-1]['tick']
    fired = [(i, s) for i, s in enumerate(samples) if s['seq'] == target and s['mem_access_fire']]
    assert len(fired) == 1, 'UNCOVERED/duplicate original device A handshake'
    start, original = fired[0]
    identity = tuple(original[k] for k in ('pc', 'addr', 'cmd', 'size'))

    def find(predicate, after):
        for i in range(after + 1, len(samples)):
            if predicate(samples[i]):
                return i, samples[i]
        raise AssertionError('UNCOVERED: complete journal/replay chain')

    saved_i, saved = find(lambda s: s['journal'] and s['journal_seq'] == target and
                         s['old_state'] == 2 and s['state'] == 3, start)
    assert tuple(saved['journal_' + k] for k in ('pc', 'addr', 'cmd', 'size')) == identity
    # A pure write returns an ACK. grant_word is an old read's register value;
    # IOMSHR deliberately journals zero for this case.
    if original['cmd'] == 1:
        assert saved['journal_word'] == 0, 'write journal contains response data'
    else:
        assert saved['journal_word'] == saved['grant_word'], 'wrong original raw word'
    invalid_i, invalid = find(lambda s: s['journal'] and s['replay'] and
                             s['journal_seq'] == target, saved_i)
    replay_i, replay = find(lambda s: s['old_state'] == 0 and s['state'] == 3 and
                           s['seq'] > target and s['journal_seq'] == s['seq'] and
                           not s['replay'], invalid_i)
    assert tuple(replay[k] for k in ('pc', 'addr', 'cmd', 'size')) == identity
    assert replay['journal'] and replay['grant_word'] == replay['journal_word'] == saved['journal_word']
    if original['cmd'] != 0:  # A write retry must preserve its operand too.
        assert replay['operand'] == saved['journal_operand'] == original['operand']
    done_i, done = find(lambda s: s['seq'] == replay['seq'] and
                       s['old_state'] == 3 and s['state'] == 0, replay_i)
    assert sum(s['mem_access_fire'] for s in samples[start:done_i + 1]
               if tuple(s[k] for k in ('pc', 'addr', 'cmd', 'size')) == identity) == 1, \
        'recovery issued the logical device effect twice'

    names = {'PALIMPSEST_SCP_CAPTURE', 'PALIMPSEST_RESULT', 'PALIMPSEST_EVT',
             'PALIMPSEST_ARCH_RESTORE', 'PALIMPSEST_RESTART', 'PALIMPSEST_IO_REPLAY'}
    events = []
    output_markers = []
    amo_markers = []
    bad = re.compile(r'Assertion failed|PALIMPSEST_FATAL|%Error|UNCOVERED|bad syscall')
    with Path(log).open(errors='replace') as stream:
        for line in stream:
            assert not bad.search(line), line.strip()
            output_markers.extend(re.findall(
                r'PALIMPSEST_MMIO_OUTPUT_RESULT checks=(\d+) last=([0-9a-f]+)', line))
            amo_markers.extend(re.findall(
                r'PALIMPSEST_MMIO_AMO_RESULT checks=(\d+) last=([0-9a-f]+)', line))
            for name, rest in re.findall(r'(PALIMPSEST_\w+)([^\n]*)', line):
                if name in names:
                    events.append((name, {k: int(v, 16) for k, v in re.findall(r'(\w+)=([0-9a-f]+)', rest)}))
    cursor = -1
    chain = []
    for name, key, value in [('PALIMPSEST_SCP_CAPTURE', 'seq', target),
                             ('PALIMPSEST_RESULT', 'seq', target),
                             ('PALIMPSEST_EVT', 'target', target),
                             ('PALIMPSEST_ARCH_RESTORE', 'seq', target),
                             ('PALIMPSEST_RESTART', 'target', target),
                             ('PALIMPSEST_IO_REPLAY', 'seq', replay['seq'])]:
        found = next(((i, f) for i, (n, f) in enumerate(events)
                      if i > cursor and n == name and f.get(key) == value), None)
        assert found, f'UNCOVERED: {name}'
        cursor, fields = found
        if name == 'PALIMPSEST_RESULT':
            assert fields['fail'] == 1 and fields['pass'] == fields['cancelled'] == 0
        if name in {'PALIMPSEST_SCP_CAPTURE', 'PALIMPSEST_ARCH_RESTORE', 'PALIMPSEST_RESTART', 'PALIMPSEST_IO_REPLAY'}:
            assert fields['pc'] == original['pc'], 'recovery/replay PC differs'
        chain.append({'event': name, **fields})
    result = {'target': target, 'replay_seq': replay['seq'], 'identity': identity,
              'device_A_handshakes_through_replay': 1, 'raw_word': saved['journal_word'],
              'samples': [original, saved, invalid, replay, done], 'recovery_events': chain}
    if require_output:
        assert output_markers == [('16', '123400000000100f')], 'missing/incorrect output oracle'
        assert original['addr'] == 0x2004000 and original['cmd'] == 1 and original['size'] == 3
        operations = [(i, s) for i, s in enumerate(samples)
                      if s['mem_access_fire'] and s['addr'] == 0x2004000]
        assert len(operations) == 32, 'missing/duplicate mtimecmp device operation'
        rounds = []
        for round_index in range(16):
            write_index, write = operations[2 * round_index]
            read_index, read = operations[2 * round_index + 1]
            expected = 0x1234000000001000 + round_index
            assert write['cmd'] == 1 and read['cmd'] == 0, 'device write/read order differs'
            assert write['pc'] == original['pc'] and write['size'] == read['size'] == 3
            assert write['operand'] == expected, 'incorrect actual device write operand'
            _, ack = find(lambda s: s['seq'] == read['seq'] and s['old_state'] == 2 and
                          s['state'] == 3, read_index)
            assert ack['journal_word'] == ack['grant_word'] == expected, 'incorrect device readback'
            assert write_index < read_index
            rounds.append({'write': write, 'read': read, 'readback': ack['grant_word']})
        result['output_rounds'] = rounds
    if require_amo:
        assert amo_markers == [('16', '1234000000001010')], 'missing/incorrect AMO oracle'
        assert original['addr'] == 0x2004000 and original['cmd'] == 8 and original['size'] == 3
        # The seq0 initialization is outside the protected workload. All 32
        # protected device effects must be AMOADD/read pairs, including rounds
        # after recovery; a correct first replay alone does not pass this test.
        operations = [(i, s) for i, s in enumerate(samples)
                      if s['mem_access_fire'] and s['addr'] == 0x2004000 and s['seq'] != 0]
        assert len(operations) == 32, 'missing/duplicate protected AMO/read operation'
        rounds = []
        for round_index in range(16):
            amo_index, amo = operations[2 * round_index]
            read_index, read = operations[2 * round_index + 1]
            expected = 0x1234000000001000 + round_index
            assert amo['cmd'] == 8 and read['cmd'] == 0, 'device AMO/read order differs'
            assert amo['pc'] == original['pc'] and amo['size'] == read['size'] == 3
            assert amo['operand'] == 1, 'incorrect actual device AMO operand'
            _, old = find(lambda s: s['seq'] == amo['seq'] and s['old_state'] == 2 and
                          s['state'] == 3, amo_index)
            _, new = find(lambda s: s['seq'] == read['seq'] and s['old_state'] == 2 and
                          s['state'] == 3, read_index)
            assert old['journal_word'] == old['grant_word'] == expected, 'incorrect AMO old value'
            assert new['journal_word'] == new['grant_word'] == expected + 1, 'incorrect AMO readback'
            rounds.append({'amo': amo, 'read': read, 'old': old['grant_word'], 'new': new['grant_word']})
        result['amo_rounds'] = rounds
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--effects', required=True)
    parser.add_argument('--fault', required=True)
    parser.add_argument('--normal')
    parser.add_argument('--failed-seq', type=int, default=40)
    parser.add_argument('--focused', action='store_true')
    profile = parser.add_mutually_exclusive_group()
    profile.add_argument('--require-output', action='store_true',
                        help='Require all 16 compact-mmio-output writes and readbacks')
    profile.add_argument('--require-amo', action='store_true',
                         help='Require all 16 compact-mmio-amo old values and readbacks')
    parser.add_argument('--report', type=Path)
    args = parser.parse_args()
    if args.focused == bool(args.normal):
        parser.error('provide --normal for complete validation, or --focused for signal evidence only')
    result = check(args.effects, args.fault, args.failed_seq, args.require_output, args.require_amo)
    if not args.focused:
        fullcore_scoreboard.check(args.normal, args.fault, args.failed_seq, require_trap_io=True)
        if args.require_output:
            with Path(args.normal).open(errors='replace') as stream:
                markers = [match for line in stream for match in re.findall(
                    r'PALIMPSEST_MMIO_OUTPUT_RESULT checks=(\d+) last=([0-9a-f]+)', line)]
            assert markers == [('16', '123400000000100f')], 'normal output oracle differs'
        if args.require_amo:
            with Path(args.normal).open(errors='replace') as stream:
                markers = [match for line in stream for match in re.findall(
                    r'PALIMPSEST_MMIO_AMO_RESULT checks=(\d+) last=([0-9a-f]+)', line)]
            assert markers == [('16', '1234000000001010')], 'normal AMO oracle differs'
    result['scope'] = 'focused_signal_chain' if args.focused else 'complete_trap_io_pair'
    result['inputs_sha256'] = {}
    for filename in [args.effects, args.fault, args.normal, __file__, fullcore_scoreboard.__file__]:
        if filename:
            p = Path(filename)
            h = hashlib.sha256()
            with p.open('rb') as stream:
                for block in iter(lambda: stream.read(1024 * 1024), b''):
                    h.update(block)
            result['inputs_sha256'][str(p)] = h.hexdigest()
    if args.report:
        with args.report.open('x') as stream:
            json.dump(result, stream, indent=2)
            stream.write('\n')
    marker = 'PALIMPSEST_IO_EFFECT_CHAIN' if args.focused else 'PALIMPSEST_FULLCORE_IO_REPLAY'
    print(f'{marker}=PASS scope={result["scope"]} target={args.failed_seq} device_A=1 raw_word={result["raw_word"]:x}')


if __name__ == '__main__':
    main()
