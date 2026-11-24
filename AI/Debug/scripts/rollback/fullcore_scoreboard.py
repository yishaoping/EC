#!/usr/bin/env python3
"""User-run full BOOM log checks. Missing coverage fails; no synthetic PASS.

This checks architectural workload results and the real FAIL/SCP/restore/EVT/
restart sequence. It does not claim a log proves every byte on the DRAM port.
"""
import argparse
from pathlib import Path
import re


def records(path, require_trap_io=False):
    bad = re.compile(r'PALIMPSEST_FATAL|Assertion failed|%Error|WORKLOAD_END status=FAIL|UNCOVERED|'
                     r'\*\*\* FAILED|bad syscall|terminate called')
    oracle = re.compile(r'PALIMPSEST_WORKLOAD_RESULT ok=(\d+) checksum=([0-9a-f]+) expected=([0-9a-f]+) fp=([0-9a-f]+) csr=([0-9a-f]+)')
    result = []
    events = []
    end = False
    exited = False
    trap_io = []
    with Path(path).open(errors='replace') as stream:
        for line in stream:
            assert not bad.search(line), f'{path}: {line.rstrip()}'
            if 'STAGE1_SIM_EXIT' in line:
                assert re.search(r'reason=(serial_success|external_success)\b', line) and \
                    all(f'{kind}_exit=0' in line for kind in ('dtm', 'tsi', 'jtag')), \
                    f'{path}: unsuccessful simulator exit: {line.rstrip()}'
                exited = True
            if 'PALIMPSEST_' not in line:
                continue
            trap_io.extend(re.findall(
                r'PALIMPSEST_TRAP_IO_RESULT ecalls=(\d+) expected=(\d+) mmio_nonzero=(\d+)', line))
            result.extend(oracle.findall(line))
            end |= 'PALIMPSEST_WORKLOAD_END status=PASS' in line
            for match in re.finditer(r'(PALIMPSEST_\w+)([^\n]*)', line):
                fields = dict(re.findall(r'(\w+)=([0-9a-f]+)', match[2]))
                events.append((match[1], {k: int(v, 16) for k, v in fields.items()}))
    assert len(result) == 1 and result[0][0] == '1', f'{path}: missing/failed workload result'
    assert end, f'{path}: no workload end'
    assert exited, f'{path}: no successful simulator exit'
    if require_trap_io:
        assert len(trap_io) == 1 and trap_io[0] == ('128', '128', '1'), \
            f'{path}: missing/incorrect compact trap/MMIO oracle: {trap_io}'
    _, actual, expected, fp, csr = result[0]
    assert actual == expected and int(fp, 16) == 0x3ff8000000000000 and int(csr, 16) == 15
    for name, fields in events:
        if name == 'PALIMPSEST_RESULT':
            assert fields.get('seq', 0) > 0 and \
                tuple(fields.get(k) for k in ('pass', 'fail', 'cancelled')) in \
                {(1, 0, 0), (0, 1, 0), (0, 0, 1)}, f'{path}: malformed result: {fields}'
    return (actual, fp, csr), events


def check(normal, fault, failed_seq, require_trap_io=False):
    signature, good = records(normal, require_trap_io)
    restored, events = records(fault, require_trap_io)
    assert restored == signature, 'fault run architectural result differs from normal run'
    assert any(name == 'PALIMPSEST_RESULT' for name, _ in good), 'UNCOVERED: normal results'
    assert all(f.get('pass') == 1 for name, f in good if name == 'PALIMPSEST_RESULT'), \
        'normal run has a FAIL or CANCELLED result'
    assert not any(name in {'PALIMPSEST_EVT', 'PALIMPSEST_ARCH_RESTORE', 'PALIMPSEST_RESTART',
                            'PALIMPSEST_SEQ_REBASE_TARGET'} for name, _ in good), \
        'normal run unexpectedly rolled back'
    failures = [f['seq'] for name, f in events if name == 'PALIMPSEST_RESULT' and f['fail']]
    assert failures == [failed_seq], f'unexpected fault results: {failures}'
    assert not any(f['cancelled'] for name, f in events if name == 'PALIMPSEST_RESULT'), \
        'fault run has a CANCELLED result'
    for kind in ('PALIMPSEST_EVT', 'PALIMPSEST_ARCH_RESTORE', 'PALIMPSEST_RESTART'):
        assert sum(name == kind for name, _ in events) == 1, f'extra/missing {kind}'
    assert not any(name == 'PALIMPSEST_SEQ_REBASE_TARGET' for name, _ in events), \
        'fault profile unexpectedly rebased'
    def find(name, predicate, start=0):
        for index in range(start, len(events)):
            if events[index][0] == name and predicate(events[index][1]):
                return index, events[index][1]
        raise AssertionError(f'UNCOVERED: {name} after event {start}')
    capture, scp = find('PALIMPSEST_SCP_CAPTURE', lambda f: f.get('seq') == failed_seq)
    failure, _ = find('PALIMPSEST_RESULT', lambda f: f.get('seq') == failed_seq and f.get('fail') == 1, capture)
    invalidate, evt = find('PALIMPSEST_EVT', lambda f: f.get('target') == failed_seq, failure)
    restore, state = find('PALIMPSEST_ARCH_RESTORE', lambda f: f.get('seq') == failed_seq, invalidate)
    restart, resumed = find('PALIMPSEST_RESTART', lambda f: f.get('target') == failed_seq, restore)
    assert state['pc'] == resumed['pc'] == scp['pc'], 'restart did not use the Starting CP PC'
    assert resumed.get('reconciled') == 1 and resumed['epoch'] == evt['next_epoch']
    find('PALIMPSEST_SCP_CAPTURE', lambda f: f.get('seq', 0) > failed_seq and f.get('epoch') == resumed['epoch'], restart)
    find('PALIMPSEST_RESULT', lambda f: f.get('seq', 0) > failed_seq and f.get('pass') == 1, restart)
    print(f'PALIMPSEST_FULLCORE=PASS target={failed_seq} checksum={signature[0]}')
    print('Figure4 A7 selection and DRAM byte safety require the independent hierarchy/baseline tests.')


def check_rebase(log, threshold, require_trap_io=False):
    signature, events = records(log, require_trap_io)
    assert all(f.get('pass') == 1 for name, f in events if name == 'PALIMPSEST_RESULT'), \
        'rebase run has a FAIL or CANCELLED result'
    passes = 0
    target = None
    phase = 'idle'
    restored_pc = None
    for name, fields in events:
        if name == 'PALIMPSEST_SEQ_REBASE_TARGET':
            assert phase == 'idle' and fields['seq'] >= threshold, 'overlapping rebase'
            target = fields['seq']
            phase = 'evt'
        elif name == 'PALIMPSEST_EVT':
            assert phase == 'evt' and fields['target'] == target, 'unexpected EVT'
            phase = 'restore'
        elif name == 'PALIMPSEST_ARCH_RESTORE':
            assert phase == 'restore' and fields['seq'] == target, 'unexpected architectural restore'
            restored_pc = fields['pc']
            phase = 'compact'
        elif name == 'PALIMPSEST_EVT_COMPACT':
            assert phase == 'compact' and fields['tail'] == target, 'unexpected EVT compaction'
            phase = 'reset'
        elif name == 'PALIMPSEST_SEQ_REBASE_RESET':
            assert phase == 'reset' and fields['old_tail'] == target, 'reset without a sealed rebase target'
            phase = 'restart'
        elif name == 'PALIMPSEST_RESTART':
            assert phase == 'restart' and fields['target'] == target, 'restart before matching Seq reset'
            assert fields['epoch'] == 0 and fields['reconciled'] == 1 and fields['pc'] == restored_pc
            phase = 'capture'
        elif name == 'PALIMPSEST_SCP_CAPTURE' and phase in {'evt', 'restore', 'compact', 'reset', 'restart', 'capture'}:
            assert phase == 'capture', 'new package before rebase restart'
            assert fields['seq'] == 1 and fields['epoch'] == 0, 'first new package is not Seq1 / Epoch0'
            phase = 'pass'
        elif name == 'PALIMPSEST_RESULT' and fields.get('seq') == 1 and phase == 'pass':
            assert fields.get('pass') == 1, 'reused Seq1 was not validated'
            passes += 1
            phase = 'idle'
    assert passes and phase == 'idle', f'UNCOVERED: complete Seq32 rebase (last phase {phase})'
    print(f'PALIMPSEST_FULLCORE_SEQ=PASS resets={passes} seq1_passes={passes} checksum={signature[0]}')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--normal')
    parser.add_argument('--fault')
    parser.add_argument('--rebase')
    parser.add_argument('--single', help='check one complete architectural oracle and simulator exit')
    parser.add_argument('--require-trap-io', action='store_true',
                        help='also require 128 completed ecalls and a nonzero MMIO result')
    parser.add_argument('--threshold', type=int, default=16)
    parser.add_argument('--failed-seq', type=int, default=8)
    args = parser.parse_args()
    if args.single and not (args.normal or args.fault or args.rebase):
        signature, _ = records(args.single, args.require_trap_io)
        print(f'PALIMPSEST_WORKLOAD_ORACLE=PASS checksum={signature[0]}')
    elif args.rebase and not (args.normal or args.fault or args.single):
        check_rebase(args.rebase, args.threshold, args.require_trap_io)
    elif args.normal and args.fault and not (args.rebase or args.single):
        check(args.normal, args.fault, args.failed_seq, args.require_trap_io)
    else:
        parser.error('provide --normal and --fault, --rebase, or --single')
