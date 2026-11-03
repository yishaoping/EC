#!/usr/bin/env python3
"""CPU contract witnesses; these do not replace elaboration or RTL simulation."""
from dataclasses import dataclass
import importlib.util
import itertools
from pathlib import Path
import random
import unittest

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('overlap_analysis', HERE / 'analyze_overlap.py')
analysis = importlib.util.module_from_spec(spec)
spec.loader.exec_module(analysis)


@dataclass(frozen=True)
class Op:
    token: int
    slot: int
    kind: str = 'store'
    result: int = 0


class CompletionContract:
    """Two slots and a bounded terminal queue, with separate physical effects."""
    def __init__(self, overlap, flow=False):
        self.overlap = overlap
        self.flow = flow
        self.s3 = None
        self.applied = False
        self.q = []
        self.pending = set()
        self.effects = []
        self.terminals = []
        self.accepted = []
        self.cycles = 0

    def tick(self, incoming=None, array_ready=True, response_ready=True):
        self.cycles += 1
        held = self.s3
        # Combinational admission sees pre-edge ownership, including a terminal
        # consumed on this edge. It never turns over the occupied S3 register.
        admit = (incoming is not None and held is None and
                 incoming.slot not in self.pending and (self.overlap or not self.q))
        deq = bool(self.q) and response_ready
        effect = bool(held) and not self.applied and held.kind == 'store' and array_ready
        enq = bool(held) and len(self.q) < 2 and (
            self.applied or (self.overlap and effect))
        bypass = self.flow and not self.q and enq and response_ready
        if effect:
            assert held.token not in self.effects
            self.effects.append(held.token)
            self.applied = True
        if deq:
            done = self.q.pop(0)
            assert done.slot in self.pending
            self.pending.remove(done.slot)
            assert done.token not in [x.token for x in self.terminals]
            self.terminals.append(done)
        if enq:
            assert held.slot not in self.pending
            assert held.kind != 'store' or held.token in self.effects
            if bypass:
                self.terminals.append(held)
            else:
                self.q.append(held)
                self.pending.add(held.slot)
            self.s3 = None
            self.applied = False
        if admit:
            self.s3 = incoming
            self.applied = incoming.kind in ('failed_sc', 'duplicate', 'cancel')
            self.accepted.append(incoming)
        assert self.pending == {x.slot for x in self.q}
        return admit

    def drain(self):
        for _ in range(20):
            self.tick()
            if self.s3 is None and not self.q:
                break
        assert self.s3 is None and not self.q
        assert self.terminals == self.accepted
        assert self.effects == [x.token for x in self.accepted if x.kind == 'store']


class OverlapTests(unittest.TestCase):
    def test_effect_enqueues_without_consuming_before_physical_edge(self):
        c = CompletionContract(True)
        self.assertTrue(c.tick(Op(1, 0, result=0x12345678)))
        c.tick()
        self.assertEqual(c.effects, [1])
        self.assertEqual(c.terminals, [])
        self.assertEqual(c.q[0].result, 0x12345678)
        c.drain()

    def test_unrelated_grant_proceeds_while_terminal_is_backpressured(self):
        c = CompletionContract(True)
        c.tick(Op(1, 0)); c.tick(response_ready=False)
        self.assertFalse(c.tick(Op(2, 0), response_ready=False))
        self.assertTrue(c.tick(Op(2, 1), response_ready=False))
        c.tick(response_ready=False)
        self.assertEqual(c.effects, [1, 2])
        self.assertEqual(c.pending, {0, 1})
        c.drain()

    def test_all_backpressure_schedules_preserve_effect_and_terminal_order(self):
        for bits in itertools.product((False, True), repeat=10):
            for overlap, flow in ((False, False), (True, False), (True, True)):
                c = CompletionContract(overlap, flow)
                todo = [Op(1, 0), Op(2, 1, 'failed_sc', 1),
                        Op(3, 0, 'duplicate', 0xCAFE), Op(4, 1, 'cancel')]
                for i in range(0, 10, 2):
                    if c.tick(todo[0] if todo else None, bits[i], bits[i+1]):
                        todo.pop(0)
                # Fair suffix: all accepted obligations must eventually drain.
                for _ in range(30):
                    if c.tick(todo[0] if todo else None):
                        todo.pop(0)
                self.assertFalse(todo)
                c.drain()

    def test_random_response_content_and_same_slot_dependencies(self):
        rng = random.Random(20261103)
        for _ in range(300):
            c = CompletionContract(True)
            todo = [Op(i+1, rng.randrange(2), rng.choice(
                ('store', 'store', 'failed_sc', 'duplicate', 'cancel')),
                rng.getrandbits(64)) for i in range(20)]
            for _ in range(200):
                if c.tick(todo[0] if todo else None, rng.random() < .6, rng.random() < .4):
                    todo.pop(0)
            for _ in range(100):
                if c.tick(todo[0] if todo else None):
                    todo.pop(0)
            self.assertFalse(todo)
            c.drain()

    def test_flow_terminal_keeps_exact_payload_and_never_precedes_effect(self):
        c = CompletionContract(True, flow=True)
        op = Op(1, 0, result=0xFFFFFFFF80000001)
        c.tick(op)
        c.tick(array_ready=False)
        self.assertEqual(c.terminals, [])
        c.tick()
        self.assertEqual(c.effects, [1])
        self.assertEqual(c.terminals, [op])
        self.assertFalse(c.pending)
        c.drain()

    def test_full_flow_queue_holds_applied_grant_without_repeating_effect(self):
        c = CompletionContract(True, flow=True)
        # The two-entry contract has two slots. Seed terminal owners as would
        # additional independent cache slots; hold a third applied S3 owner.
        c.accepted = [Op(1, 0), Op(2, 1), Op(3, 2)]
        c.q = c.accepted[:2]
        c.pending = {0, 1}
        c.effects = [1, 2]
        c.s3 = c.accepted[2]
        for _ in range(5):
            c.tick(response_ready=False)
        self.assertEqual(c.effects, [1, 2, 3])
        self.assertEqual(c.s3, c.accepted[2])
        c.drain()

    def test_fixed_trace_reduces_cycles_without_changing_results(self):
        cycles = []
        for overlap in (False, True):
            c = CompletionContract(overlap)
            todo = [Op(i+1, i % 2) for i in range(40)]
            while todo or c.s3 is not None or c.q:
                if c.tick(todo[0] if todo else None):
                    todo.pop(0)
            c.drain()
            cycles.append(c.cycles)
        self.assertLess(cycles[1], cycles[0])

    def diagnostic_fixture(self):
        r = dict(kind=48, hart=0, cycle=100,
                 nums=[1, 100, 20, 5, 3, 9, 30, 7, 50, 12] + [0]*6)
        c = dict(observers={'48:0': dict(events_seen=1, footers_seen=1,
                        footer_emitted_count=1, omitted=0)},
                 producers={'48:0': dict(produced=1, emitted=1, omitted=0)})
        return r, c

    def test_diagnostics_require_window_and_phase_conservation(self):
        r, c = self.diagnostic_fixture()
        self.assertEqual(analysis.sourcec([r], c, 100)['status'], 'PASS')
        for i in range(16):
            bad = dict(r, nums=r['nums'].copy())
            bad['nums'][i] += 101
            self.assertEqual(analysis.sourcec([bad], c, 100)['status'], 'FAIL')

    def test_diagnostics_reject_missing_duplicate_or_lost_evidence(self):
        r, c = self.diagnostic_fixture()
        for rows in ([], [r, r]):
            self.assertEqual(analysis.sourcec(rows, c, 100)['status'], 'FAIL')
        c['producers']['48:0']['omitted'] = 1
        self.assertEqual(analysis.sourcec([r], c, 100)['status'], 'FAIL')

    def test_terminal_snapshots_require_exact_traffic_window_and_ownership(self):
        frontend = dict(kind=49, hart=1, cycle=100, nums=[1, 100, 100, 10, 20, 0,
            5, 65, 80, 60, 70, 2, 0, 2, 0, 1])
        cache = dict(kind=50, hart=0, cycle=100, nums=[1, 100, 10, 8, 8, 8,
            9, 9, 0, 20, 1, 6, 4, 2, 7, 0])
        rows = [dict(frontend, hart=hart) for hart in range(1, 5)] + [cache]
        capture = dict(observers={}, producers={})
        for row in rows:
            key = f"{row['kind']}:{row['hart']}"
            capture['observers'][key] = dict(events_seen=1, footers_seen=1,
                footer_emitted_count=1, omitted=0)
            capture['producers'][key] = dict(produced=1, emitted=1, omitted=0)
        report = analysis.terminal_snapshots(rows, capture, 100, required=True)
        self.assertEqual(report['status'], 'PASS', report['errors'])
        self.assertEqual(report['snapshots']['50:0']['counters']['empty_queue_bypasses'], 8)
        self.assertEqual(analysis.terminal_snapshots([], capture, 100)['status'],
                         'NOT_IN_THIS_REVISION')

    def test_terminal_snapshots_reject_window_loss_and_impossible_forward(self):
        frontend = dict(kind=49, hart=1, cycle=100, nums=[1, 100, 100, 10, 20, 0,
            5, 65, 80, 60, 70, 2, 0, 2, 0, 1])
        cache = dict(kind=50, hart=0, cycle=100, nums=[1, 100, 10, 8, 8, 8,
            9, 9, 0, 20, 1, 6, 4, 2, 7, 0])
        rows = [dict(frontend, hart=hart) for hart in range(1, 5)] + [cache]
        capture = dict(observers={}, producers={})
        for row in rows:
            key = f"{row['kind']}:{row['hart']}"
            capture['observers'][key] = dict(events_seen=1, footers_seen=1,
                footer_emitted_count=1, omitted=0)
            capture['producers'][key] = dict(produced=1, emitted=1, omitted=0)
        cache['nums'][13] = 7
        self.assertEqual(analysis.terminal_snapshots(rows, capture, 100,
            required=True)['status'], 'FAIL')
        cache['nums'][13] = 2
        self.assertEqual(analysis.terminal_snapshots(rows, capture, 99,
            required=True)['status'], 'FAIL')
        capture['observers']['49:1']['omitted'] = 1
        self.assertEqual(analysis.terminal_snapshots(rows, capture, 100,
            required=True)['status'], 'FAIL')


if __name__ == '__main__':
    unittest.main(verbosity=2)
