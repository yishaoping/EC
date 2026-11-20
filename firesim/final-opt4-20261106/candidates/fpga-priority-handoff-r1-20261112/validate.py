#!/usr/bin/python3
"""Offline behavioral checks against the real immutable software suite."""
import copy
import json
from pathlib import Path
import sys

C = Path(__file__).resolve().parent
sys.path.insert(0, str(C))
from controller import load_original
from follower import idle_runtime_rows
from schedule import PRIORITY, adapt, ordered_suite


def main():
    module = load_original()
    suite = module.read(module.SUITE)
    before = copy.deepcopy(suite)
    ordered = ordered_suite(suite)
    assert tuple(row['program'] for row in ordered['programs'][:8]) == PRIORITY
    assert suite == before
    for row in ordered['programs']:
        assert row == next(r for r in suite['programs'] if r['program'] == row['program'])
    select = adapt(module.next_task)
    completed = set()
    calls = []

    def committed(row, records, size, rep, program=None, bitsha=None):
        assert bitsha == 'offline-only'
        return (program or row['program'], size, rep) in completed

    module.committed = committed
    first = select(suite, [], {}, 'offline-only')
    assert first[1:4] == ('smoke', 'test', 1)
    # A hardware smoke failure blocks workloads.
    assert select(suite, [], {first[4]: {'fixture': True}}, 'offline-only') is None
    completed.add(('smoke', 'test', 1))
    while True:
        task = select(suite, [], {}, 'offline-only')
        if task is None:
            break
        row, program, size, rep, key = task
        calls.append((program, size, rep))
        completed.add((program, size, rep))
    formal = [(name, rep) for name, size, rep in calls if size == 'simmedium']
    assert len(formal) == 39 and len(set(formal)) == 39
    assert [rep for _, rep in formal] == [1] * 13 + [2] * 13 + [3] * 13
    assert [name for name, rep in formal if rep == 1][:8] == list(PRIORITY)
    # Failed application test skips just that profile, leaving the next ready
    # program runnable. The original failure key and stage policy are reused.
    completed = {('smoke', 'test', 1)}
    task = select(suite, [], {}, 'offline-only')
    assert task[1:4] == ('blackscholes', 'test', 1)
    next_ready = select(suite, [], {task[4]: {'fixture': True}}, 'offline-only')
    assert next_ready[1:4] == ('fluidanimate', 'test', 1)
    # An unknown identity, child-bearing waiter, or real runtime is never
    # authorized for retirement by a zero/stale PID.
    assert not idle_runtime_rows([], {})
    assert not idle_runtime_rows([{}, {}], {'pid': 99999999})
    print(json.dumps(dict(status='PASS_OFFLINE_BEHAVIOR_NO_FPGA_IO',
        mandatory_hardware_smoke=True, formal_samples=39,
        first_round_priority=list(PRIORITY),
        first_round_before_repeats=True, application_failure_skips=True,
        canonical_software_suite_unchanged=suite == before,
        rejects_unknown_idle_identity=True)))


if __name__ == '__main__':
    main()
