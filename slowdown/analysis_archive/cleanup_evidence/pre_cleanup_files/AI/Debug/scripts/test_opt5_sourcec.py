#!/usr/bin/env python3
"""CPU-only protocol witnesses, diagnostics rejection tests and one-run guards.

These witnesses exercise the proposed resource/ordering contract, not an RTL
simulation. The sealed Scala typing and later hardware run are separate gates.
"""
import importlib.util
from pathlib import Path
import unittest
import uuid

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('sourcec', HERE / 'launch_opt5_sourcec.py')
sourcec = importlib.util.module_from_spec(spec)
spec.loader.exec_module(sourcec)


class Checkpoint:
    """Small transaction/port contract with independently progressing C packet."""
    def __init__(self, old=False):
        self.state = 'idle'
        self.txn = 0
        self.set = None
        self.a_beats = 0
        self.c_set = None
        self.c_remaining = 0
        self.c_done = []
        self.old = old

    def capture(self, target):
        if self.state != 'idle' or self.c_remaining:
            return False
        self.set = target
        self.txn += 1
        self.state = 'read'
        self.a_beats = 0
        return True

    def send(self):
        self.state = 'send'
        self.a_beats += 1
        if self.a_beats == 8:
            self.state = 'waitAck'

    def release(self, target):
        if self.c_remaining or (self.state != 'idle' and
                (self.old or self.state != 'waitAck' or target == self.set)):
            return False
        self.c_set = target
        self.c_remaining = 8
        return True

    def c_tick(self, ready):
        if ready and self.c_remaining:
            self.c_remaining -= 1
            if not self.c_remaining:
                self.c_done.append(self.c_set)

    def ack(self, source=2, txn=None, size=6, denied=False):
        if self.state != 'waitAck' or source != 2 or size != 6 or txn != self.txn:
            return False
        self.state = 'failed' if denied else 'idle'
        return not denied


class SourceCTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.out = HERE.parents[1] / 'TMP' / ('sourcec_cpu_tests_' + uuid.uuid4().hex)
        cls.out.mkdir()
        cls.contract = dict(run_target='OPT5_SOURCEC_B_ONLY_64K_2WAY',
                            number_of_full_runs_requested=1, automatic_retry=False)

    def path(self):
        p = self.out / uuid.uuid4().hex
        p.mkdir()
        return p

    def waiting(self, old=False):
        c = Checkpoint(old)
        self.assertTrue(c.capture(4))
        for _ in range(8):
            c.send()
        return c

    def test_old_global_waitack_hol_and_new_progress(self):
        old, new = self.waiting(True), self.waiting()
        self.assertFalse(old.release(7))
        self.assertTrue(new.release(7))
        for ready in [True, False] * 8:
            new.c_tick(ready)
        self.assertEqual(new.c_done, [7])
        self.assertEqual(new.state, 'waitAck')
        self.assertFalse(new.release(4))
        self.assertTrue(new.ack(txn=1))

    def test_all_non_waitack_active_phases_remain_reserved(self):
        c = Checkpoint()
        c.capture(4)
        for state in ['read', 'delay1', 'delay2', 'send', 'failed']:
            c.state = state
            self.assertFalse(c.release(7))

    def test_ack_does_not_cut_c_packet_or_allow_next_capture(self):
        c = self.waiting()
        self.assertTrue(c.release(7))
        c.c_tick(True)
        self.assertTrue(c.ack(txn=1))
        self.assertFalse(c.capture(9))
        self.assertFalse(c.release(9))
        for _ in range(7):
            c.c_tick(True)
        self.assertTrue(c.capture(9))
        self.assertEqual(c.c_done, [7])

    def test_stale_wrong_source_size_denied_ack_keep_protection(self):
        c = self.waiting()
        for kwargs in [dict(source=0, txn=1), dict(txn=0), dict(txn=1, size=5)]:
            self.assertFalse(c.ack(**kwargs))
            self.assertEqual(c.state, 'waitAck')
            self.assertFalse(c.release(4))
        self.assertFalse(c.ack(txn=1, denied=True))
        self.assertEqual(c.state, 'failed')
        self.assertFalse(c.release(7))

    def test_partial_a_cannot_release_port_or_complete(self):
        c = Checkpoint()
        c.capture(4)
        for _ in range(7):
            c.send()
            self.assertFalse(c.release(7))
            self.assertFalse(c.ack(txn=1))
        c.send()
        self.assertTrue(c.ack(txn=1))

    def test_valid_B_and_wrong_arm_retry_count_rejected(self):
        sourcec.validate_target(self.contract, 'B')
        for changes, arm in [({}, 'A'), ({'automatic_retry': True}, 'B'),
                             ({'number_of_full_runs_requested': 2}, 'B')]:
            with self.assertRaises(ValueError):
                sourcec.validate_target(dict(self.contract, **changes), arm)

    def test_second_claim_rejected(self):
        p = self.path()
        sourcec.claim_once(p)
        with self.assertRaises(FileExistsError):
            sourcec.claim_once(p)

    def test_existing_run_rejected_without_claim(self):
        p = self.path()
        run = p / 'sealed/arms/B/runs/existing'
        run.mkdir(parents=True)
        (run / 'run_manifest.json').write_text('{}')
        with self.assertRaises(ValueError):
            sourcec.claim_once(p)
        self.assertFalse((p / 'SOURCEC_LAUNCH_CLAIM.json').exists())

    def diagnostic_fixture(self):
        path = self.path() / 'events.tsv'
        path.write_text('SC_END\t1\t1\t1\t1\t48\t0\t1\n')
        rows = [dict(kind=40, hart=0, n=[1, 100]),
                dict(kind=48, hart=0, n=[1, 100, 20, 5, 3, 9, 30, 7, 50, 12] + [0] * 6)]
        capture = dict(producers={'48:0': dict(produced=1, emitted=1, omitted=0)},
                       observers={'48:0': dict(events_seen=1, footers_seen=1, omitted=0)})
        return rows, path, capture

    def test_diagnostics_conservation(self):
        self.assertEqual(sourcec.diagnostics(*self.diagnostic_fixture())['status'], 'PASS')

    def test_diagnostics_reject_phase_counter_or_capture_corruption(self):
        for index in [0, 1, 2, 3, 4, 7, 8, 9, 10]:
            rows, path, capture = self.diagnostic_fixture()
            rows[1]['n'][index] += 101
            self.assertEqual(sourcec.diagnostics(rows, path, capture)['status'], 'FAIL')
        rows, path, capture = self.diagnostic_fixture()
        capture['producers']['48:0']['omitted'] = 1
        self.assertEqual(sourcec.diagnostics(rows, path, capture)['status'], 'FAIL')
        path.write_text('')
        self.assertEqual(sourcec.diagnostics(rows, path, capture)['status'], 'FAIL')
        self.assertEqual(sourcec.diagnostics(rows + [rows[1]], path, capture)['status'], 'FAIL')

    def test_diagnostics_reject_bypass_without_pending_and_unaccounted_block(self):
        for index, value in [(4, 8), (5, 4)]:
            rows, path, capture = self.diagnostic_fixture()
            rows[1]['n'][index] = value
            self.assertEqual(sourcec.diagnostics(rows, path, capture)['status'], 'FAIL')

    def test_performance_thresholds_and_invalid_run(self):
        for roi, expected in [(1502512, 'SUB1P5_SUCCESS'), (1502513, 'STRONG_OPT5'),
                              (1548923, 'STRONG_OPT5'), (1548924, 'MODERATE_KEEP_FOR_COMBINATION'),
                              (1598923, 'MODERATE_KEEP_FOR_COMBINATION'), (1598924, 'STOP_SOURCEC_DIRECTION'),
                              (1700000, 'STOP_SOURCEC_DIRECTION')]:
            self.assertEqual(sourcec.verdict(roi, True)['decision'], expected)
        self.assertFalse(sourcec.verdict(1000000, False)['performance_valid'])

    def test_overlay_preserves_budgets_classification_and_SC48_conservation(self):
        original = sourcec.module('sourcec_original_capture', sourcec.CAPTURE)
        directory = self.path()
        overlay = directory / 'capture.py'
        overlay.write_text(sourcec.capture_overlay_text())
        impl = sourcec.module('sourcec_overlay_capture', overlay)
        self.assertEqual(impl.budget_contract(), original.budget_contract())
        self.assertTrue(all(impl.optional_event(k, h) == original.optional_event(k, h)
                            for k in range(256) for h in range(5)))
        capture = self.path()
        router = impl.Router(capture)
        for h in range(134):
            router.line(('\t'.join(['SC1', '1', '1', '1', '1', '48', str(h)] + ['0' * 16] * 16) + '\n').encode(), 1)
            router.line(f'SC_END\t2\t2\t2\t1\t48\t{h}\t1\n'.encode(), 1)
            router.line(f'SC_LOG_STATS\t48\t{h}\t1\t1\t0\t200000\n'.encode(), 1)
        stats = router.close()
        self.assertTrue(stats['mandatory_evidence_complete'])
        self.assertEqual(len(stats['producers']), 134)

    def test_source_retains_lock_ack_drain_and_C_packet_invariants(self):
        l2 = sourcec.ROOT / sourcec.L2
        p = (l2 / 'L2Preservation.scala').read_text()
        s = (l2 / 'Scheduler.scala').read_text()
        for fragment in ['io.lock.valid := active || capture', 'val active = state =/= idle',
                         'state === idle && need && io.drained', 'when (finalBeat) { state := waitAck }',
                         'io.d.bits.echo(CachePreserveTxn) === serial', 'when (complete) {',
                         '.otherwise { state := failed }', 'io.waitingAck := state === waitAck']:
            self.assertIn(fragment, p)
        for fragment in ['preservation.io.drained := sourceD.io.idle && sourceC.io.idle',
                         'val drainForCheckpoint = runnable.orR && !preservation.io.lock.valid',
                         '!x.valid && !locked(m.io.status.bits.set) && outerSafe',
                         'val sourceCReserved = preservation.io.lock.valid && !preservation.io.waitingAck',
                         'sourceC.io.bs_adr.ready := !sourceCReserved',
                         '(!sourceCReserved && !drainForCheckpoint)',
                         'TLArbiter.lowest(params.outer, io.out.a, preservation.io.a, sourceA.io.a)',
                         'remainingCounters(48,']:
            self.assertIn(fragment, s)
        self.assertEqual(s.count('L2_PREMATURE_OVERWRITE_ERROR'), 4)


if __name__ == '__main__':
    unittest.main()
