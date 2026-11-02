#!/usr/bin/env python3
"""CPU-only tests: reject lossy/ambiguous protocol joins and invalid gain bounds."""
import copy
import importlib.util
from pathlib import Path
import unittest

spec = importlib.util.spec_from_file_location('transfer_tested',Path(__file__).with_name('analyze_opt5_cache_transfer.py'))
m = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m)


def fixture():
    def event(kind,cycle,d,line):
        return dict(kind=kind,cycle=cycle,d=d+[0]*(16-len(d)),line=line,hart=0,episode=1)
    def release(kind,cycle,first=0,last=0):
        return event(kind,cycle,[1,0,255,0x80000000,7,6,7 if kind==20 else 6,99,0,1,2,first,last,1,1,6],cycle)
    rows = [release(20,10,first=1),release(20,16,last=1)]
    rows += [event(38,20+i,[2,0x80000000,7,99,0,6,100+i,i,1,8],100+i) for i in range(8)]
    rows += [release(21,29)]
    return rows


class TransferTests(unittest.TestCase):
    def test_complete_join(self):
        t,e = m.reconstruct(fixture())
        self.assertEqual(len(t),1); self.assertEqual(e,{})
        self.assertEqual(t[0]['bank_word_offsets'],list(range(8)))
        self.assertEqual(t[0]['raw_rows']['bank'],list(range(100,108)))

    def test_same_edge_final_bank_and_ack(self):
        rows=fixture(); rows[-1]['cycle']=27
        self.assertEqual(m.reconstruct(list(reversed(rows)))[0][0]['ack'],27)

    def test_missing_word_rejected(self):
        rows=fixture(); del rows[5]
        with self.assertRaises(ValueError): m.reconstruct(rows)

    def test_duplicate_word_rejected(self):
        rows=fixture(); rows[4]['d'][7]=1
        with self.assertRaises(ValueError): m.reconstruct(rows)

    def test_wrong_bank_token_rejected(self):
        for index in (1,2,3,4):
            rows=fixture(); rows[2]['d'][index]+=1
            with self.subTest(index=index),self.assertRaises(ValueError): m.reconstruct(rows)

    def test_wrong_ack_identity_rejected(self):
        for index in (1,2,3,4,7,8,9,10,15):
            rows=fixture(); rows[-1]['d'][index]+=1
            with self.subTest(index=index),self.assertRaises(ValueError): m.reconstruct(rows)

    def test_other_client_excluded_even_same_image(self):
        rows=fixture(); other=copy.deepcopy(rows[2]); other['d'][5]=20; rows.append(other)
        self.assertEqual(m.reconstruct(rows)[1],{'20':1})

    def test_wrong_l1_source_rejected(self):
        rows=fixture(); rows[0]['d'][5]=7
        with self.assertRaises(ValueError): m.reconstruct(rows)

    def test_overlapping_source_rejected(self):
        rows=fixture(); extra=copy.deepcopy(rows[0]); extra['cycle']=12; rows.append(extra)
        with self.assertRaises(ValueError): m.reconstruct(rows)

    def test_missing_ack_rejected(self):
        with self.assertRaises(ValueError): m.reconstruct(fixture()[:-1])

    def test_missing_last_c_rejected(self):
        rows=fixture(); del rows[1]
        with self.assertRaises(ValueError): m.reconstruct(rows)

    def test_early_ack_rejected(self):
        rows=fixture(); rows[-1]['cycle']=26
        with self.assertRaises(ValueError): m.reconstruct(rows)

    def test_orphan_bank_rejected(self):
        rows=fixture(); rows[2]['cycle']=9
        with self.assertRaises(ValueError): m.reconstruct(rows)

    def test_reset_join_rejected(self):
        rows=fixture(); rows[-1]['episode']=2
        with self.assertRaises(ValueError): m.reconstruct(rows)

    def test_roi_boundary_censor_and_prefix_overlap(self):
        t,_=m.reconstruct(fixture())
        s=m.summarize(t,[11,28],[11,25],[[13,18]])
        self.assertEqual(s['roi_contained_transactions'],0)
        self.assertEqual(s['boundary_censored_transactions'],1)
        self.assertEqual(s['roi_phase_union_cycles'],17)
        self.assertEqual(s['prefix_phase_union_cycles'],14)
        self.assertEqual(s['scheduler_overlap_prefix_cycles'],5)
        self.assertIsNone(s['independent_critical_upper_bound'])
        self.assertEqual(s['conservative_recoverable_cycles'],0)

    def test_phase_sum_partition(self):
        t,_=m.reconstruct(fixture()); s=m.summarize(t,[0,100],[0,100],[])
        d=s['distributions']['all']
        self.assertEqual(d['first_C_to_ACK']['sum'],d['first_C_to_last_C']['sum']+d['last_C_to_first_bank']['sum']+d['first_bank_to_last_bank']['sum']+d['last_bank_to_ACK']['sum'])

    def test_exact_quantile_nearest_rank(self):
        d=m.exact_distribution(list(range(1,101)))
        self.assertEqual([d[k] for k in ('median','p90','p99','max')],[50,90,99,100])
        self.assertIsNone(m.exact_distribution([])['mean'])

    def test_histogram_bounds_not_exact_latency(self):
        h=[0]*32; h[5]=10
        d=m.histogram_summary(h,10,200)
        self.assertEqual(d['median_bounds'],[16,31]); self.assertIsNone(d['exact_quantiles'])
        with self.assertRaises(ValueError): m.histogram_summary(h,9,200)
        with self.assertRaises(ValueError): m.histogram_summary(h,10,500)

    def test_histogram_saturation_unknown_upper(self):
        h=[0]*32; h[31]=1
        self.assertEqual(m.histogram_summary(h,1,2**40)['max_bounds'],[2**30,None])

    def test_tail_sum_bounds_use_exact_sum(self):
        h=[0]*32; h[1]=2; h[11]=2
        d=m.histogram_summary(h,4,3002)['at_least_1024']
        self.assertEqual(d['samples'],2)
        self.assertEqual(d['elapsed_duration_sum_bounds'],[3000,3000])

    def test_tail_bounds_with_no_tail(self):
        h=[0]*32; h[5]=4
        self.assertEqual(m.histogram_summary(h,4,100)['at_least_1024']['elapsed_duration_sum_bounds'],[0,0])


if __name__ == '__main__':
    unittest.main(verbosity=2)
