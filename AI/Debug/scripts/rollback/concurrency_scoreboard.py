#!/usr/bin/env python3
"""Strict complete-Core checks for repeated faults and fault/device/rebase overlap."""
import argparse
import json
from pathlib import Path

import fullcore_scoreboard as full
import io_effect_scoreboard as effects


def control_chain(events, target, cursor, epoch):
    def take(name, predicate, after):
        for i in range(after + 1, len(events)):
            n, f = events[i]
            if n == 'PALIMPSEST_' + name and predicate(f):
                return i, f
        raise AssertionError(f'UNCOVERED: {name} target={target}')
    # The target SCP is captured before the failure; it must belong to the
    # execution epoch resumed by the preceding recovery.
    capture, scp = take('SCP_CAPTURE', lambda f: f['seq'] == target and f['epoch'] == epoch, cursor)
    fail, _ = take('RESULT', lambda f: f['seq'] == target and f['fail'], capture)
    invalid, evt = take('EVT', lambda f: f['target'] == target, fail)
    restore, state = take('ARCH_RESTORE', lambda f: f['seq'] == target, invalid)
    restart, resumed = take('RESTART', lambda f: f['target'] == target, restore)
    assert evt['tail'] >= target and evt['next_epoch'] == epoch + 1
    assert state['epoch'] == resumed['epoch'] == evt['next_epoch']
    assert scp['pc'] == state['pc'] == resumed['pc'] and resumed['reconciled'] == 1
    fresh, new = take('SCP_CAPTURE', lambda f: f['seq'] > evt['tail'] and
                      f['epoch'] == resumed['epoch'], restart)
    passed, result = take('RESULT', lambda f: f['seq'] >= new['seq'] and f['pass'], fresh)
    return passed, restart, resumed['epoch'], dict(target=target, scp=scp, evt=evt,
        restore=state, restart=resumed, resumed_capture=new, resumed_pass=result)


def normal_signature(path):
    signature, events = full.records(path, True)
    assert any(n == 'PALIMPSEST_RESULT' for n, _ in events)
    assert all(f['pass'] for n, f in events if n == 'PALIMPSEST_RESULT')
    assert not any(n in {'PALIMPSEST_EVT', 'PALIMPSEST_ARCH_RESTORE',
                        'PALIMPSEST_RESTART', 'PALIMPSEST_SEQ_REBASE_TARGET'} for n, _ in events)
    return signature


def check_two_faults(normal, fault):
    signature = normal_signature(normal)
    actual, events = full.records(fault, True)
    assert actual == signature, 'architectural result differs from normal'
    assert [f['seq'] for n, f in events if n == 'PALIMPSEST_RESULT' and f['fail']] == [8, 24]
    assert not any(f['cancelled'] for n, f in events if n == 'PALIMPSEST_RESULT')
    assert not any(n == 'PALIMPSEST_SEQ_REBASE_TARGET' for n, _ in events)
    for kind in ('EVT', 'ARCH_RESTORE', 'RESTART'):
        assert sum(n == 'PALIMPSEST_' + kind for n, _ in events) == 2
    chains = []
    cursor, epoch = -1, 0
    for target in (8, 24):
        passed, restart, epoch, chain = control_chain(events, target, cursor, epoch)
        # The next failure must follow both a fresh SCP and successful replay.
        cursor = passed
        chains.append(chain)
    return dict(scope='complete_program_two_independent_comparator_failures',
                checksum=signature[0], recoveries=chains)


def check_overlap(normal, fault, ledger, overlap):
    signature = normal_signature(normal)
    actual, events = full.records(fault, True)
    assert actual == signature, 'architectural result differs from normal'
    effect_chain = effects.check(ledger, fault, 40)
    assert [f['seq'] for n, f in events if n == 'PALIMPSEST_RESULT' and f['fail']] == [40]
    assert not any(f['cancelled'] for n, f in events if n == 'PALIMPSEST_RESULT')
    _, first_restart, epoch, fault_chain = control_chain(events, 40, -1, 0)
    # Apply the existing strict rebase FSM to all later events. Passing only
    # the first reset is insufficient: every planned rebase must end in Seq1 PASS.
    later = events[first_restart + 1:]
    phase, target, pc, resets = 'idle', None, None, 0
    for name, f in later:
        if name == 'PALIMPSEST_SEQ_REBASE_TARGET':
            assert phase == 'idle' and f['seq'] >= 41
            phase, target = 'evt', f['seq']
        elif name == 'PALIMPSEST_EVT':
            assert phase == 'evt' and f['target'] == target
            phase = 'restore'
        elif name == 'PALIMPSEST_ARCH_RESTORE':
            assert phase == 'restore' and f['seq'] == target
            phase, pc = 'compact', f['pc']
        elif name == 'PALIMPSEST_EVT_COMPACT':
            assert phase == 'compact' and f['tail'] == target
            phase = 'reset'
        elif name == 'PALIMPSEST_SEQ_REBASE_RESET':
            assert phase == 'reset' and f['old_tail'] == target
            phase = 'restart'
        elif name == 'PALIMPSEST_RESTART':
            assert phase == 'restart' and f['target'] == target and f['pc'] == pc
            assert f['epoch'] == 0 and f['reconciled'] == 1
            phase = 'capture'
        elif name == 'PALIMPSEST_SCP_CAPTURE' and phase not in {'idle', 'pass'}:
            assert phase == 'capture' and f['seq'] == 1 and f['epoch'] == 0 and f['pc'] == pc
            phase = 'pass'
        elif name == 'PALIMPSEST_RESULT' and phase == 'pass' and f['seq'] == 1:
            assert f['pass'] == 1
            resets += 1
            phase = 'idle'
    assert resets and phase == 'idle', 'UNCOVERED: complete fault + planned rebasing program'
    rows = [tuple(map(int, line.split())) for line in Path(overlap).read_text().splitlines()]
    assert rows and all(len(row) == 7 for row in rows)
    assert all(a[0] <= b[0] for a, b in zip(rows, rows[1:]))
    original, saved, invalid, replay, completed = effect_chain['samples']
    allocation = next(row for row in rows if row[2] and row[3] == 41)
    assert saved['tick'] <= allocation[0] <= invalid['tick']
    assert allocation[4:] == (0, 1, 0), 'Seq41 reserved/reset over unresolved effect'
    release = next(row for row in rows if row[0] >= completed['tick'] and not row[5])
    assert all(not p and not reset for tick, _, _, _, p, _, reset in rows
               if allocation[0] <= tick < release[0])
    reserve = next(row for row in rows if row[0] >= release[0] and row[4])
    reset = next(row for row in rows if row[6])
    assert release[0] <= reserve[0] < reset[0] and reserve[5] == reset[5] == 0
    return dict(scope='complete_program_effect_fault_replay_and_all_planned_rebases',
                checksum=signature[0], resets=resets, fault=fault_chain,
                effect=effect_chain, allocation=allocation, release=release,
                reservation=reserve, first_reset=reset)


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--normal', type=Path, required=True)
    p.add_argument('--fault', type=Path, required=True)
    p.add_argument('--kind', choices=['two-faults', 'io-rebase'], required=True)
    p.add_argument('--effects', type=Path)
    p.add_argument('--overlap', type=Path)
    p.add_argument('--report', type=Path, required=True)
    args = p.parse_args()
    if args.kind == 'two-faults':
        report = check_two_faults(args.normal, args.fault)
    else:
        assert args.effects and args.overlap
        report = check_overlap(args.normal, args.fault, args.effects, args.overlap)
    with args.report.open('x') as stream:
        json.dump(report, stream, indent=2)
        stream.write('\n')
    print('PALIMPSEST_CONCURRENCY=PASS kind=' + args.kind)


if __name__ == '__main__':
    main()
