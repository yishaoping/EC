#!/usr/bin/env python3
"""Offline fixtures and source contracts only; never build/run hardware."""
import copy
import importlib.util
import json
from pathlib import Path
import tempfile
import unittest
from collections import Counter

ROOT = Path(__file__).resolve().parents[3]
OUT = ROOT / 'slowdown/optimization_4_svb'


def module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    return m


a = module('analysis', OUT / 'analysis/analyze_svb.py')
p = module('protocol_fixtures', OUT / 'scripts/offline_protocol_tests.py')
capture = module('capture', OUT / 'scripts/compact_capture.py')


def cache_rows():
    result = []
    for level, sets, ways in ((1, 256, 2), (2, 1024, 16)):
        models = []
        for i, (s, w) in enumerate(((sets, ways), (sets//2, ways*2), (sets*2, ways), (sets, ways*2))):
            models.append(dict(name=f'S{i}', sets=s, ways=w, capacity_bytes=s*w*64,
                               stats=dict(access=100, hit=80+i*4, miss=20-i*4,
                                          replacement=15-i*3, dirty_victim=5)))
        result.append(dict(schema=1, classification='COUNTERFACTUAL_CACHE_TRAFFIC_ESTIMATE',
                           level=level, instance=0, sets=sets, ways=ways, block_bytes=64,
                           stop_seen=True, geometry_decision_eligible=True,
                           actual=dict(access=100, hit=80, miss=20), models=models))
    result[0].update(data_fingerprints=dict(captured=1, issued=1, matched_lower=1, pending=0, mismatches=0),
                     svb_entry_accounting=dict(observed=True, entries=16, allocations=1,
                                               completions=1, coalesced=0, discarded=0,
                                               occupancy=0, conserved=True),
                     shadow_8_capacity=dict(observed=True, would_full_at_8=3, cycles_above_8=5,
                                            occupancy_histogram=[10]*17, depth_histogram=[10]*17))
    return result


class CacheTests(unittest.TestCase):
    def analyze_cache(self, rows, benchmark=True):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory)
            (path/'cache_opportunity.jsonl').write_text('\n'.join(json.dumps(r) for r in rows)+'\n')
            return a.cache_opportunity(path, benchmark)

    def test_four_shapes_and_estimate_only(self):
        out = self.analyze_cache(cache_rows())
        self.assertEqual(out['status'], 'PASS')
        self.assertIsNone(out['predicted_roi'])
        self.assertIsNotNone(out['cache_opt_candidate'])

    def test_checksum_failure_blocks_geometry_decision(self):
        out = self.analyze_cache(cache_rows(), False)
        self.assertIsNone(out['cache_opt_candidate'])
        self.assertTrue(all(r['decision']=='BLOCKED_BY_BENCHMARK_CORRECTNESS' for r in out['models']))

    def test_s0_disagreement_blocks_candidate(self):
        rows=cache_rows()
        for r in rows:r['geometry_decision_eligible']=False
        self.assertIsNone(self.analyze_cache(rows)['cache_opt_candidate'])

    def test_missing_or_duplicate_level(self):
        self.assertEqual(self.analyze_cache(cache_rows()[:1])['status'], 'FAIL')
        rows=cache_rows();rows.append(copy.deepcopy(rows[0]))
        self.assertEqual(self.analyze_cache(rows)['status'], 'FAIL')

    def test_fingerprint_and_conservation_fail_closed(self):
        for field, key, value in [('data_fingerprints','mismatches',1),
                                  ('data_fingerprints','matched_lower',0),
                                  ('svb_entry_accounting','conserved',False),
                                  ('svb_entry_accounting','entries',8)]:
            rows=cache_rows();rows[0][field][key]=value
            self.assertEqual(self.analyze_cache(rows)['status'], 'FAIL')

    def test_shadow_access_conservation(self):
        rows=cache_rows();rows[1]['models'][1]['stats']['access']=101
        self.assertEqual(self.analyze_cache(rows)['status'],'FAIL')

    def test_geometry_shape_and_claimed_sanity_are_checked(self):
        rows=cache_rows();rows[0]['models'][1]['sets']=256
        self.assertEqual(self.analyze_cache(rows)['status'],'FAIL')
        rows=cache_rows()
        for r in rows:r['actual'].update(hit=0,miss=100)
        out=self.analyze_cache(rows)
        self.assertIsNone(out['cache_opt_candidate'])

    def test_16entry_protocol_accepts_slot15_but_not16(self):
        for entry, expected in ((15,'PASS'),(16,'FAIL')):
            rows=p.svb_sequence()+[p.stats()]
            for r in rows[:5]:r['nums'][2]=entry
            cap=p.event(30,40);cap['nums']=[2,16]+[0]*14;rows.append(cap)
            self.assertEqual(p.ProtocolTests().analyze(rows)['protocol']['status'],expected)

    def test_failed_16entry_run_uses_manifest_without_stop_capacity_snapshot(self):
        rows=p.svb_sequence()
        for row in rows:row['nums'][2]=15
        ledger=a.protocol_ledger(rows, configured_entries=16)
        self.assertEqual(ledger['entry_capacity_source'],'run_manifest')
        self.assertEqual(ledger['svb_completions'],1)
        self.assertFalse(any('selection' in error for error in ledger['errors']))
        self.assertNotEqual(ledger['status'],'PASS')  # No final counters/footers.
        legacy=a.protocol_ledger(rows)
        self.assertTrue(any('invalid selection' in error for error in legacy['errors']))

    def test_capacity_manifest_and_snapshot_mismatch_fails(self):
        cap=p.event(30,40);cap['nums']=[2,8]+[0]*14
        ledger=a.protocol_ledger(p.svb_sequence()+[cap],configured_entries=16)
        self.assertEqual(ledger['status'],'FAIL')
        self.assertIn('SVB capacity snapshot disagrees with run manifest',ledger['errors'])

    def test_real_stale_release_counterexample(self):
        first=p.event(20,1458055,owner=0,first=1,n3=0x80011f40,n4=119,n7=67826)
        old=p.event(20,1459713,first=1,n3=0x80011f40,n4=116,n7=65841)
        out=a.data_ordering([first,old])
        self.assertEqual(out['status'],'FAIL')
        self.assertEqual(out['stale_publications'],1)

    def test_equal_generation_repeat_is_not_regression(self):
        self.assertEqual(a.data_ordering([p.event(20,1,first=1),p.event(20,5,first=1)])['status'],'PASS')

    def test_explicit_benchmark_failure_is_fail(self):
        result=p.ProtocolTests().analyze(p.svb_sequence()+[p.stats()],
            '[RUN] benchmark=gapbs_bfs verified=0 parent_checksum=43440224\n[END] hart=0 status=FAIL\n',
            {'roi_cycles':1720057})
        self.assertEqual(result['correctness']['status'],'FAIL')
        self.assertFalse(result['performance_valid'])

    def test_router_keeps_only_final_json(self):
        with tempfile.TemporaryDirectory() as directory:
            path=Path(directory); router=capture.Router(path)
            router.feed(b'CACHE_OPPORTUNITY {"schema":1}\n',1)
            stats=router.close()
            self.assertEqual(json.loads((path/'cache_opportunity.jsonl').read_text()),{'schema':1})
            self.assertEqual(stats['sizes']['cache_opportunity.jsonl'],13)

    def test_observer_has_no_outputs(self):
        text=(ROOT/'chipyard/generators/rocket-chip/src/main/scala/util/CacheOpportunityObservation.scala').read_text()
        self.assertNotIn('Output(',text)
        self.assertNotIn('Flipped(',text)

    def test_l2_observation_mux_projects_full_request_by_fields(self):
        text=(ROOT/'chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala').read_text()
        self.assertIn('val observationIncoming = Wire(new QueuedRequest(params), init = request.bits)',text)
        self.assertIn('Mux(mshr_uses_directory_for_lb, requests.io.data, observationIncoming)',text)
        self.assertNotIn('Mux(mshr_uses_directory_for_lb, requests.io.data, request.bits)',text)

    def test_same_line_gates_precede_arbiter(self):
        text=(ROOT/'chipyard/generators/boom/src/main/scala/lsu/dcache.scala').read_text()
        for q in (0,1,2,3):self.assertIn(f'!svb.io.releaseBlocked({q})',text)
        self.assertIn('!ackPending && !io.req.valid',text)
        self.assertIn('svbCaptureDrained',text)
        self.assertIn('SVB capture changed pre-overwrite identity',text)

    def test_entry_count_and_histogram_chunking(self):
        svb=(ROOT/'chipyard/generators/boom/src/main/scala/lsu/speculative-version-buffer.scala').read_text()
        dc=(ROOT/'chipyard/generators/boom/src/main/scala/lsu/dcache.scala').read_text()
        self.assertIn('case object SVBEntries extends Field[Int](16)',svb)
        self.assertIn('new BoomWritebackUnit(nSVBEntries)',dc)
        self.assertIn('.grouped(15)',dc)
        self.assertIn('SVB entry conservation failed',svb)

    def new_run(self, checksum=43439728, missing_cache=False, missing_histogram_footer=False,
                mismatched_histogram=False, invalid_protocol=False):
        with tempfile.TemporaryDirectory() as directory:
            path=Path(directory)
            rows=p.svb_sequence()+[p.stats()]
            if invalid_protocol:
                for row in rows[:5]:row['nums'][2]=16
            e=p.event(30,40);e['nums']=[2,16]+[0]*14;rows.append(e)
            for kind in (17,18):
                for chunk in (0,1):
                    e=p.event(kind,40);e['hart']=chunk;e['nums']=[chunk]+[10]*15;rows.append(e)
            text=''
            for e in rows:
                text+='\t'.join(map(str,['SC1',e['time'],e['cycle'],e['cycle'],e['episode'],e['kind'],e['hart']]))
                text+='\t'+'\t'.join(f'{n:016x}' for n in e['nums'])+'\n'
            for (kind,hart),count in Counter((e['kind'],e['hart']) for e in rows).items():
                if missing_histogram_footer and kind==17 and hart==1:continue
                text+=f'SC_END\t99\t99\t99\t1\t{kind}\t{hart}\t{count}\n'
            (path/'safe_chain_events.tsv').write_text(text)
            (path/'stdout.log').write_text(f'[RUN] benchmark=gapbs_bfs verified=1 parent_checksum={checksum}\n'
                                          '[COMPUTATION] status=PASS\n[END] hart=0 status=PASS\n')
            (path/'roi.json').write_text(json.dumps({'roi_cycles':2000000}))
            (path/'run_manifest.json').write_text(json.dumps({'source':{'revision_mode':'corrected_svb16_fst_owner_fix_v1'}}))
            if not missing_cache:
                cache=cache_rows()
                if mismatched_histogram:cache[0]['shadow_8_capacity']['occupancy_histogram'][0]=9
                (path/'cache_opportunity.jsonl').write_text('\n'.join(json.dumps(r) for r in cache)+'\n')
            return a.run_summary(path)

    def test_complete_new_run_can_publish_roi_and_histogram17(self):
        out=self.new_run()
        self.assertTrue(out['performance_valid'])
        self.assertEqual(len(out['occupancy_histogram']),17)
        self.assertEqual(out['benchmark_result']['checksum'],43439728)

    def test_new_run_missing_shadow_or_wrong_checksum_never_passes(self):
        self.assertFalse(self.new_run(missing_cache=True)['performance_valid'])
        self.assertEqual(self.new_run(checksum=43440224)['correctness']['status'],'FAIL')

    def test_histogram_coverage_and_host_equality_are_required(self):
        self.assertFalse(self.new_run(missing_histogram_footer=True)['performance_valid'])
        self.assertFalse(self.new_run(mismatched_histogram=True)['performance_valid'])

    def test_protocol_failure_blocks_geometry_even_with_correct_checksum(self):
        result=self.new_run(invalid_protocol=True)
        self.assertEqual(result['correctness']['status'],'FAIL')
        self.assertIsNone(result['cache_opportunity']['cache_opt_candidate'])


if __name__=='__main__':unittest.main()
