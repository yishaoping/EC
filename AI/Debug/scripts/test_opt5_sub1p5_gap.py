#!/usr/bin/env python3
"""CPU-only tests for exposure, cohort, and provenance failure boundaries."""
import importlib.util
from fractions import Fraction
from pathlib import Path
import tempfile
import unittest

SPEC = importlib.util.spec_from_file_location('opt5_gap', Path(__file__).with_name('analyze_opt5_sub1p5_gap.py'))
gap = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(gap)


class GapBoundaries(unittest.TestCase):
    def test_strict_fractional_target_rounding(self):
        t = gap.target_math(1001675,1648923,1707863)
        self.assertEqual(t['max_integer_roi_below_target'],1502512)
        self.assertEqual(t['minimum_integer_saving'],146411)
        self.assertEqual(t['approximate_gap'],146410)
        self.assertEqual(t['total_minimum_integer_saving'],205351)

    def test_strict_integral_target_rounding(self):
        t = gap.target_math(100,180,200)
        self.assertEqual(t['max_integer_roi_below_target'],149)
        self.assertEqual(t['minimum_integer_saving'],31)

    def test_other_rational_threshold(self):
        self.assertEqual(gap.target_math(10,20,30,Fraction(4,3))['max_integer_roi_below_target'],13)

    def test_nested_exposures_never_added(self):
        b = gap.fixed_trace_envelopes(1648923,53845,80832,1001675)
        self.assertEqual(b['combined_upper_bound'],80832)
        self.assertEqual(b['additional_nonmiss_head_pending'],26987)
        self.assertEqual(b['ideal_all_head_load_deletion_roi'],1568091)
        self.assertGreater(b['ideal_all_head_load_deletion_slowdown'],1.5)

    def test_invalid_nesting_fails(self):
        with self.assertRaises(ValueError):
            gap.fixed_trace_envelopes(100,80,60,50)

    def test_marginals_do_not_prove_head_retry_join(self):
        self.assertEqual(gap.overlap_bounds(53845,47162,1648923),[0,47162])

    def test_frechet_forced_overlap(self):
        self.assertEqual(gap.overlap_bounds(80,70,100),[50,70])
        with self.assertRaises(ValueError):
            gap.overlap_bounds(101,10,100)

    def test_traffic_roi_bounds_not_exact_exposure(self):
        self.assertEqual(gap.traffic_roi_bounds(159519,[698208,2358291],[698301,2347224]),[148359,159519])

    def test_bad_roi_containment_fails(self):
        with self.assertRaises(ValueError):
            gap.traffic_roi_bounds(15,[10,30],[9,25])

    def test_carry_in_tokens_widen_attempt_ratio(self):
        a = gap.attempt_amplification(40033,1062,16)
        self.assertEqual(a['affected_miss_token_count_bounds'],[1062,1078])
        self.assertEqual(a['some_token_attempt_count_at_least'],38)
        self.assertAlmostEqual(a['attempts_per_miss_token_bounds'][0],40033/1078)
        self.assertIn('NOT nack retry',a['metric'])

    def test_carry_in_bound_cannot_exceed_attempts(self):
        a = gap.attempt_amplification(3,2,16)
        self.assertEqual(a['affected_miss_token_count_bounds'],[2,3])
        self.assertEqual(a['attempts_per_miss_token_bounds'][0],1)

    def test_absent_unique_retry_history_stays_unknown(self):
        a = gap.retry_factor(47162)
        self.assertIsNone(a['value'])
        self.assertEqual(a['bounds'],[1,47162])

    def test_zero_retry_cohort_ratio_undefined(self):
        self.assertIsNone(gap.retry_factor(0)['bounds'])

    def test_critical_retry_factor_needs_matching_cohort(self):
        self.assertEqual(gap.retry_factor(12,3)['value'],4)
        with self.assertRaises(ValueError):
            gap.retry_factor(12,13)

    def test_sc7_scheduler_decodes_fsm_and_availability(self):
        self.assertTrue(gap.scheduler_unavailable([999,0,0,2<<3]))
        self.assertFalse(gap.scheduler_unavailable([2,0,1<<6,2<<3]))
        self.assertFalse(gap.scheduler_unavailable([2,0,0,5<<3]))

    def test_evidence_digest_change_fails_closed(self):
        # Keep the synthetic fixture too: this workspace forbids TMP cleanup.
        d = tempfile.mkdtemp(prefix='opt5-gap-test-',dir=gap.ROOT/'AI/TMP')
        p=Path(d)/'synthetic_evidence.json';p.write_text('raw evidence')
        expected={str(p):gap.sha(p)}
        self.assertEqual(gap.audit_hashes(expected),1)
        p.write_text('changed evidence')
        with self.assertRaisesRegex(ValueError,'digest mismatch'):
            gap.audit_hashes(expected)

    def test_missing_evidence_fails_closed(self):
        with self.assertRaisesRegex(ValueError,'digest mismatch'):
            gap.audit_hashes({'/nonexistent/opt5-input.json':'0'*64})


if __name__ == '__main__':
    unittest.main()
