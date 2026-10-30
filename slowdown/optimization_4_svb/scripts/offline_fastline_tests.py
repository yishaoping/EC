#!/usr/bin/env python3
"""Reduced protocol tests, including replay of the saved FST failure.

These are offline state-machine/ordering tests, not a BOOM simulation. The
independent publication oracle rejects any same-line version regression.
"""
from dataclasses import dataclass
import importlib.util
import itertools
import json
from pathlib import Path
import unittest

ROOT = Path('/data1/gzh/EC')
EVIDENCE = ROOT/'AI/TMP/opt4_svb_fst_rootcause_fix_20261030_114113_773ea77d'


@dataclass(frozen=True)
class Image:
    line: int
    way: int
    epoch: int
    seq: int
    generation: int


class Protocol:
    def __init__(self, fixed=True):
        self.fixed = fixed
        self.lease = None
        self.resident = {}
        self.retained = []
        self.wb = None
        self.published = {}
        self.acquires = self.releases = 0

    def capture(self, old, incoming):
        assert self.lease is None  # single immutable capture descriptor
        assert self.resident[old.way] == old
        self.retained.append(old)
        self.lease = (old, incoming)
        self.acquires += 1

    def tick(self):
        if self.fixed and self.lease and self.resident.get(self.lease[0].way) != self.lease[0]:
            self.lease = None
            self.releases += 1

    def admit_handoff(self, line):
        # Other slot/epoch/nack/capture gates are explicitly assumed satisfied.
        return self.lease is None or (self.fixed and line != self.lease[0].line)

    def bypass(self, image, incoming):
        return bool(self.lease and self.lease == (image, incoming) and
                    self.resident.get(image.way) == image)

    def effect(self, old, incoming, generation):
        assert self.resident[old.way] == old
        self.resident[old.way] = Image(old.line, old.way, old.epoch, incoming, generation)
        if self.lease and self.lease == (old, incoming):
            self.lease = None
            self.releases += 1

    def external_ready(self, line):
        return self.wb is None and not any(i.line == line for i in self.retained)

    def publish(self, image):
        version = (image.seq, image.generation)
        assert version >= self.published.get(image.line, (-1, -1)), 'VERSION_REGRESSION'
        self.published[image.line] = version

    def promote(self, image, safe):
        assert self.wb is None and image in self.retained and image.seq <= safe
        assert not any(i.line == image.line and (i.seq, i.generation) >
                       (image.seq, image.generation) and i.seq <= safe for i in self.retained)
        self.wb = image
        self.publish(image)

    def ack(self, image):
        assert self.wb == image  # immutable full transaction identity, not only line
        self.retained = [i for i in self.retained if not
                         (i.line == image.line and (i.seq, i.generation) <=
                          (image.seq, image.generation))]
        self.wb = None


A = Image(0x800123c0, 1, 0x16, 179, 0x158a8)
B = Image(0x80008040, 0, 0x20, 182, 0x15c2a)


class FastLineTests(unittest.TestCase):
    def owner(self, fixed=True):
        p = Protocol(fixed)
        p.resident[A.way] = A
        p.capture(A, 183)
        return p

    def test_A_unrelated_handoff_while_predecessor_retained(self):
        old, new = self.owner(False), self.owner()
        self.assertFalse(old.admit_handoff(B.line))
        self.assertTrue(new.admit_handoff(B.line))
        self.assertEqual(new.retained, [A])
        self.assertFalse(new.external_ready(A.line))

    def test_B_same_line_WB_never_overtakes_even_after_lease_revoke(self):
        p = self.owner()
        p.resident[1] = Image(0x800563c0, 1, 0x17, 3, 0xb92e)
        p.tick()
        self.assertIsNone(p.lease)
        self.assertFalse(p.external_ready(A.line))
        p.promote(A, 182)
        self.assertFalse(p.external_ready(A.line))
        p.ack(A)
        self.assertTrue(p.external_ready(A.line))
        p.publish(Image(A.line, 0, 17, 183, 0x15ceb))
        with self.assertRaisesRegex(AssertionError, 'VERSION_REGRESSION'):
            p.publish(A)

    def test_C_probe_waits_for_matching_ACK_not_lease_release(self):
        p = self.owner()
        p.effect(A, 183, 0x15ceb)
        self.assertIsNone(p.lease)
        self.assertFalse(p.external_ready(A.line))
        p.promote(A, 179)
        with self.assertRaises(AssertionError):
            p.ack(Image(A.line, A.way, A.epoch, A.seq, A.generation+1))
        self.assertFalse(p.external_ready(A.line))
        p.ack(A)
        self.assertTrue(p.external_ready(A.line))

    def test_D_MSHR_owns_WB_unrelated_handoff_not_fastline_blocked(self):
        p = self.owner()
        p.wb = B
        self.assertTrue(p.admit_handoff(B.line))
        self.assertFalse(p.external_ready(B.line))  # real WB resource remains serialized
        p.wb = None
        self.assertTrue(p.external_ready(B.line))
        self.assertEqual(p.retained, [A])

    def test_E_STQ_order_inversion_old_counterexample_new_progress(self):
        # The older B store must finish before A's held store can execute.
        def run(fixed):
            p = self.owner(fixed)
            queue = [B.line, A.line]
            for _ in range(8):
                if queue and (queue[0] == A.line or p.admit_handoff(queue[0])):
                    line = queue.pop(0)
                    if line == A.line:
                        p.effect(A, 183, 0x15ceb)
                p.tick()
            return queue, p
        self.assertEqual(run(False)[0], [B.line, A.line])
        queue, p = run(True)
        self.assertFalse(queue)
        self.assertEqual(p.acquires, p.releases)
        self.assertEqual(p.retained, [A])

    def test_saved_FST_replay_acquire_replacement_alternate_way_completion(self):
        evidence = json.loads((EVIDENCE/'owner_lifetime.json').read_text())
        changes = {(r['time'], r['signal'].split('.')[-1]): r['value']
                   for r in evidence['transitions']}
        self.assertEqual(changes[3656021, 'svbFastLineValid'], 1)
        self.assertEqual(changes[3656087, 'slotEpoch_143_1'], 0x17)
        self.assertEqual(changes[3656087, 'svbCaptureResidentMatch'], 0)
        self.assertEqual(changes[3673921, 's3_way'], 1)  # one-hot way0
        self.assertEqual(changes[3673925, 'io_dmem_store_done_valid'], 1)
        self.assertEqual(changes[3673925, 'io_dmem_store_done_bits_req_request_token'], 0x1cc33)
        for fixed in (False, True):
            p = self.owner(fixed)
            p.resident[1] = Image(0x800563c0, 1, 0x17, 3, 0xb92e)
            p.tick()  # identity lost: old implementation never revoked the lease
            p.resident[0] = Image(A.line, 0, 0x11, 179, 0x158a8)
            p.effect(p.resident[0], 183, 0x15ceb)
            self.assertEqual(p.lease is None, fixed)
            self.assertEqual(p.admit_handoff(B.line), fixed)
            self.assertEqual(p.retained, [A])

    def test_identity_dimensions_each_revoke_permission(self):
        for replacement in (None, Image(A.line+64,1,A.epoch,A.seq,A.generation),
                            Image(A.line,1,A.epoch+1,A.seq,A.generation),
                            Image(A.line,1,A.epoch,A.seq+1,A.generation),
                            Image(A.line,1,A.epoch,A.seq,A.generation+1)):
            p = self.owner()
            p.resident[1] = replacement
            self.assertFalse(p.bypass(A, 183))
            p.tick()
            self.assertIsNone(p.lease)
            self.assertEqual(p.acquires, p.releases)
            self.assertEqual(p.retained, [A])

    def test_live_lease_matches_only_original_way_epoch_key_and_incoming_package(self):
        p = self.owner()
        self.assertTrue(p.bypass(A, 183))
        self.assertFalse(p.bypass(A, 184))
        self.assertFalse(p.bypass(Image(A.line,0,A.epoch,A.seq,A.generation),183))
        self.assertFalse(p.admit_handoff(A.line))
        with self.assertRaises(AssertionError):
            p.capture(A, 184)

    def test_single_freeze_descriptor_cannot_acquire_capture_and_handoff_together(self):
        for capture_pending, handoff_pending, live_lease, same_line, unsafe, space in \
                itertools.product((False, True), repeat=6):
            if capture_pending and handoff_pending:
                continue  # invalid initial ownership is separately asserted in RTL
            capture = unsafe and space and not (
                capture_pending or handoff_pending or live_lease)
            handoff = not (capture or capture_pending or
                            (live_lease and same_line) or handoff_pending)
            self.assertFalse(capture and handoff)
            self.assertFalse((capture_pending or capture) and (handoff_pending or handoff))

    def test_exhaustive_interleavings_preserve_ordering_and_owner_balance(self):
        # All 24 orders of invalidation, unrelated admission, watermark, and ACK.
        for order in itertools.permutations(('revoke','other','safe','ack')):
            p = self.owner()
            promoted = False
            for action in order:
                if action == 'revoke':
                    p.resident[1] = None
                    p.tick()
                elif action == 'other':
                    self.assertTrue(p.admit_handoff(B.line))
                elif action == 'safe':
                    p.promote(A, 179)
                    promoted = True
                elif promoted:
                    p.ack(A)
                self.assertEqual(p.acquires-p.releases, int(p.lease is not None))
                if A in p.retained:
                    self.assertFalse(p.external_ready(A.line))

    def test_failure_overlay_preserves_all_functional_and_event_gates(self):
        import sys
        sys.path.insert(0, str(Path(__file__).resolve().parent))
        from prepare_failure_diagnostics import overlay
        source = """module Fixture(input clock, reset, valid);
  if ((`PRINTF_COND_) & valid & ~reset)
    $fwrite(32'h80000002, "FASTLINE_RELEASE cycle=%x\\n", cycle);
  if ((`PRINTF_COND_) & valid)
    $fwrite(32'h80000002, "PRESERVATION_WAIT cycle=%x\\n", cycle);
  if ((`PRINTF_COND_) & unrelated)
    $fwrite(32'h80000002, "unrelated cycle=%x\\n", cycle);
  if ((`PRINTF_COND_) & watchdog & ~reset)
    $fwrite(32'h80000002, "DCACHE_WATCHDOG_SNAPSHOT cycle=%x\\n", cycle);
endmodule
"""
        result, counts = overlay(source, 'Fixture')
        self.assertEqual(result.replace("1'b1", '`PRINTF_COND_'), source)
        self.assertEqual(counts, {'FASTLINE_RELEASE':1, 'PRESERVATION_WAIT':1,
                                  'DCACHE_WATCHDOG_SNAPSHOT':1})
        self.assertIn('(`PRINTF_COND_) & unrelated)', result)
        self.assertNotIn('opt4_wave_', result)
        self.assertNotIn('$dump', result)

    def test_RTL_guards_correspond_to_protocol_contract(self):
        text = (ROOT/'chipyard/generators/boom/src/main/scala/lsu/dcache.scala').read_text()
        def block(start, end): return text.split(start,1)[1].split(end,1)[0]
        fallback = block('val crossPackageBlockCondition =', 'val fastLineBlocksOtherLine')
        self.assertIn('!svbFastPreservationConflict', fallback)
        self.assertNotIn('!svbFastLineValid', fallback)
        self.assertIn('!svbFastLineValid', block('val svbEligibleCandidate =', 'val svbEligible ='))
        self.assertIn('!crossPackagePending', block('val svbEligibleCandidate =', 'val svbEligible ='))
        s3 = block('val s3_svbOwnsPredecessor =', 'val s3_preservationAllowed =')
        self.assertIn('svbCaptureResidentMatch', s3)
        self.assertIn('s3_req.slot_epoch === svbFastEpoch', s3)
        self.assertIn('when (svbFastLeaseRevoked)', text)
        for invariant in ('DEADLOCK-1:', 'ORDER-1:', 'OWNER-1:', 'WB-1:'):
            self.assertIn(invariant, text)
        for port in (0,1,3):
            self.assertIn(f'wbArb.io.in({port}).valid :=', text)
        self.assertIn('tl_out.b.ready        := prober.io.req.ready && !lrsc_valid && !svb.io.releaseBlocked(3)', text)


if __name__ == '__main__':
    unittest.main(verbosity=2)
