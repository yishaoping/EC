#!/usr/bin/env python3
"""CPU-only lock-scope, boundary, evidence-absence and attribution tests."""
import importlib.util
from pathlib import Path
import unittest

spec=importlib.util.spec_from_file_location('preserve_tested',Path(__file__).with_name('analyze_opt5_preservation_outer_a.py'))
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)


class AttributionTests(unittest.TestCase):
    def trace(self,ack=70,bank=lambda _:True,ready=lambda _:True):
        return m.packet_contract(bank,ready,ack_cycle=ack,cycles=80)

    def test_first_and_last_A_contract(self):
        self.assertEqual([r['cycle'] for r in self.trace() if r['pres_fire']],list(range(4,33,4)))

    def test_packet_not_locked_before_first_A(self):
        self.assertTrue(all(not r['packet_lock'] for r in self.trace()[:4]))

    def test_normal_A_during_snapshot_bank_read(self):
        self.assertTrue(self.trace()[0]['normal_fire'])

    def test_intrinsic_packet_gaps(self):
        self.assertEqual(sum(r['intrinsic_locked_gap'] for r in self.trace()),21)

    def test_final_beat_releases_packet_before_ACK(self):
        r=self.trace()[32]
        self.assertEqual(r['cycle'],33);self.assertEqual(r['state'],'waitAck')
        self.assertFalse(r['packet_lock']);self.assertTrue(r['target_set_lock']);self.assertTrue(r['normal_fire'])

    def test_ACK_extension_does_not_extend_packet_lock(self):
        a,b=self.trace(40),self.trace(70)
        self.assertEqual(sum(x['packet_lock'] for x in a),28)
        self.assertEqual(sum(x['packet_lock'] for x in a),sum(x['packet_lock'] for x in b))
        self.assertGreater(sum(x['target_set_lock'] for x in b),sum(x['target_set_lock'] for x in a))

    def test_bank_stall_can_extend_lock_beyond_gap_only_bound(self):
        t=self.trace(bank=lambda c:not 5<=c<10)
        self.assertGreater(sum(r['packet_lock'] for r in t),28)
        self.assertGreater(sum(r['intrinsic_locked_gap'] for r in t),21)
        self.assertIn('bank-read waiting',m.intrinsic_gap_bound(1)['excludes'])

    def test_downstream_backpressure_distinct_from_intrinsic_gaps(self):
        t=self.trace(ready=lambda c:c not in (8,9,10))
        self.assertGreater(sum(r['packet_lock'] for r in t),28)
        self.assertEqual(sum(r['intrinsic_locked_gap'] for r in t),21)

    def test_early_ACK_rejected(self):
        with self.assertRaises(ValueError): self.trace(ack=20)

    def test_missing_ACK_keeps_set_but_not_packet(self):
        r=self.trace(ack=None)[-1]
        self.assertTrue(r['target_set_lock']);self.assertFalse(r['packet_lock'])

    def test_gap_ceiling_count_and_carry(self):
        b=m.intrinsic_gap_bound(1623)
        self.assertEqual(b['packet_count_ceiling'],1624);self.assertEqual(b['cycle_upper_bound'],34104)
        self.assertIn('NOT whole',b['scope'])

    def test_no_carry_and_empty_count(self):
        self.assertEqual(m.intrinsic_gap_bound(0,carry_in=0)['cycle_upper_bound'],0)

    def test_invalid_count(self):
        with self.assertRaises(ValueError): m.intrinsic_gap_bound(-1)
        with self.assertRaises(ValueError): m.intrinsic_gap_bound(1,carry_in=2)

    def test_presented_request_amplification_is_not_repeated_valid(self):
        self.assertEqual(m.max_presented_heads_without_dequeue(['req0']*50,range(50)),1)

    def test_no_presented_request_is_zero_denominator_not_retry_factor(self):
        self.assertEqual(m.max_presented_heads_without_dequeue([None]*50,range(50)),0)

    def test_different_head_during_no_dequeue_is_error(self):
        with self.assertRaises(ValueError): m.max_presented_heads_without_dequeue(['req0','req1'],[0,1])

    def test_critical_nested_union_not_addition(self):
        b=m.unknown_bounds(1648923,53845,80832)
        self.assertEqual(b['INDEPENDENT_CACHE_TRANSFER_UB']['deduplicated_direct_head_miss_union_range'],[0,53845])
        self.assertEqual(b['INDEPENDENT_CACHE_TRANSFER_UB']['deduplicated_all_direct_head_pending_union_range'],[0,80832])
        self.assertIsNone(b['INDEPENDENT_CACHE_TRANSFER_UB']['value'])

    def test_missing_pending_and_lock_evidence_stays_unknown(self):
        b=m.unknown_bounds(1648923,53845,80832)
        self.assertIsNone(b['PRESERVATION_PENDING_UB']['value']);self.assertIsNone(b['OUTER_A_CRITICAL_UB']['value'])

    def test_invalid_nested_head_bounds(self):
        with self.assertRaises(ValueError): m.unknown_bounds(100,90,80)


if __name__=='__main__':unittest.main(verbosity=2)
