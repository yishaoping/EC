#!/usr/bin/env python3
"""Host-only analyzer regressions; these do not simulate the hardware."""
import unittest
from stage2_trace_scoreboard import analyze


class Stage2TraceTests(unittest.TestCase):
    def report(self, *lines):
        return analyze(['STAGE2_TX '+line for line in lines])

    def test_empty_is_uncovered(self):
        self.assertEqual(analyze([])['status'], 'UNCOVERED')

    def test_safe_sent_without_receipt_is_not_accepted(self):
        r = self.report('PRESERVE line=80000000 epoch=1 valid=1 writer=0 gen=4 seq=1')
        self.assertEqual(r['errors'][0]['reason'], 'unclosed_preservation')

    def test_ack_must_follow_commit(self):
        r = self.report('ACK source=1 valid=1 writer=0 gen=4 seq=1 matched=1')
        self.assertEqual(r['errors'][0]['reason'], 'matched_ack_without_lower_commit')

    def test_stale_ack_does_not_close_new_preserve(self):
        r = self.report('PRESERVE line=80000000 epoch=1 valid=1 writer=0 gen=5 seq=1',
                        'LOWER_COMMIT source=1 valid=1 writer=0 gen=4 seq=1',
                        'ACK source=1 valid=1 writer=0 gen=4 seq=1 matched=0')
        self.assertTrue(any(e['reason']=='unclosed_preservation' for e in r['errors']))

    def test_matching_receipt_closes_preserve(self):
        r = self.report('PRESERVE line=80000000 epoch=1 valid=1 writer=0 gen=5 seq=1',
                        'LOWER_COMMIT source=1 valid=1 writer=0 gen=5 seq=1',
                        'ACK source=1 valid=1 writer=0 gen=5 seq=1 matched=1',
                        'PRESERVE_DONE line=80000000 epoch=1 valid=1 writer=0 gen=5 seq=1 accepted=1')
        self.assertEqual(r['errors'], [])
        self.assertEqual(r['counts']['PRESERVE_RECEIPT'], 1)

    def modification(self, **changes):
        fields = dict(line=0x80000000, epoch=1, old_gen=4, old_seq=1, old_writer=0,
                      old_valid=1, lower=0, safe=0, new_gen=5, new_seq=2, writer=0,
                      replay=0, cmd=1, req=7)
        fields.update(changes)
        return 'MODIFY '+' '.join(f'{k}={v:x}' for k,v in fields.items())

    def test_unpreserved_cross_package_is_error(self):
        self.assertTrue(self.report(self.modification(safe=1))['errors'])

    def test_same_package_is_legal_without_new_receipt(self):
        self.assertEqual(self.report(self.modification(new_seq=1))['errors'], [])

    def test_duplicate_effect_is_error(self):
        m = self.modification(safe=1, lower=1)
        self.assertTrue(any(e['reason']=='duplicate_physical_effect' for e in self.report(m,m)['errors']))

    def test_self_reported_lower_flag_is_not_a_receipt(self):
        self.assertTrue(any(e['reason']=='preservation_flag_without_matching_receipt'
                            for e in self.report(self.modification(safe=1, lower=1))['errors']))

    def test_import_proves_exact_key(self):
        r = self.report('IMPORT line=80000000 epoch=1 valid=1 writer=0 gen=4 seq=1',
                        self.modification(safe=1, lower=1))
        self.assertEqual(r['errors'], [])

    def test_old_import_cannot_prove_new_generation(self):
        r = self.report('IMPORT line=80000000 epoch=1 valid=1 writer=0 gen=3 seq=1',
                        self.modification(safe=1, lower=1))
        self.assertTrue(r['errors'])

    def test_old_epoch_receipt_is_not_current_receipt(self):
        r = self.report('IMPORT line=80000000 epoch=1 valid=1 writer=0 gen=4 seq=1',
                        self.modification(epoch=2, safe=1, lower=1))
        self.assertTrue(r['errors'])

    def test_forged_preserve_done_cannot_prove_receipt(self):
        r = self.report('PRESERVE_DONE line=80000000 epoch=1 valid=1 writer=0 gen=4 seq=1 accepted=1',
                        self.modification(safe=1, lower=1))
        self.assertTrue(any(e['reason']=='preserve_done_without_matching_snapshot_and_ack' for e in r['errors']))

    def test_ack_without_done_leaves_snapshot_open(self):
        r = self.report('PRESERVE line=80000000 epoch=1 valid=1 writer=0 gen=5 seq=1',
                        'LOWER_COMMIT source=1 valid=1 writer=0 gen=5 seq=1',
                        'ACK source=1 valid=1 writer=0 gen=5 seq=1 matched=1')
        self.assertTrue(any(e['reason']=='unclosed_snapshot' for e in r['errors']))

    def test_replay_and_normal_use_identical_rule(self):
        self.assertTrue(self.report(self.modification(replay=1))['errors'])

    def test_unsafe_seq0_cannot_erase_ownership(self):
        self.assertTrue(self.report(self.modification(new_seq=0))['errors'])


if __name__ == '__main__':
    unittest.main()
