#!/usr/bin/env python3
"""Synthetic fail-closed tests; fixtures are never hardware evidence."""
import copy
import importlib.util
import json
from pathlib import Path
import re
import unittest
import uuid

ROOT = Path(__file__).resolve().parents[3]
spec = importlib.util.spec_from_file_location('pair', Path(__file__).with_name('analyze_l1_causal_pair.py'))
pair = importlib.util.module_from_spec(spec)
spec.loader.exec_module(pair)


class PairAnalysisTests(unittest.TestCase):
    def fixture(self, gain=90000, head_drop=60000):
        parent = Path((ROOT/'AI/TMP/.l1_causal_active').read_text().strip())
        root = parent/'synthetic_analyzer_tests'/uuid.uuid4().hex[:12]
        revision = root/'revision'
        revision.mkdir(parents=True)
        (root/'SYNTHETIC_ONLY.txt').write_text('Artificial unit-test data. NOT a simulation or performance result.\n')
        pair.dump(root/'simulation_execution_provenance.json',dict(status='PASS',
            argv_A=['/synthetic/simulator-chipyard-L1Causal32Config','-s','1'],
            argv_B=['/synthetic/simulator-chipyard-L1Causal64Config','-s','1']))
        pair.dump(root/'generated_configuration_audit.json',dict(status='PASS'))
        pair.dump(root/'native_resource_copy_validation.json',dict(status='PASS'))
        source_text = (ROOT/'chipyard/generators/rocket-chip/src/main/resources/csrc/cache_opportunity.cc').read_text()
        names = re.findall(r'"([A-Za-z_]+)"', source_text.split('static const char *names[]')[1].split('bool valid=')[0])
        seal = dict(paired_source_fingerprint='synthetic', hardware_sha256={'hw':'hash'},
                    tool_sha256={'tool':'hash'}, software={'elf_sha256':'elf','loadmem_sha256':'mem'},
                    seed=1,max_cycles=500000000,verilator_threads=1)
        pair.dump(revision/'source_seal.json',seal)
        for name in ['A','B']:
            b=name=='B'; n=1700000-(gain if b else 0)
            h=200000-(head_drop if b else 0); busy=300000-(80000 if b else 0)
            counts={key:0 for key in names}
            counts.update(sample_cycles=n, mshr_busy_cycles=busy, mshr_full_cycles=100,
                ROB_HEAD_WAITING_ON_LOAD_MISS_CYCLES=h,
                ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_BUSY_CYCLES=h,
                ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_FULL_CYCLES=50,
                scheduler_unavailable_cycles=200000,
                SCHEDULER_UNAVAILABLE_AND_MSHR_BUSY_CYCLES=10000,
                SCHEDULER_UNAVAILABLE_AND_MSHR_FULL_CYCLES=20,
                ROB_HEAD_LOAD_BLOCK_AND_SCHEDULER_UNAVAILABLE_CYCLES=10000,
                load_tag_miss_requests=1000 if b else 3000,
                mshr_primary_allocations=1000 if b else 3000)
            causal=dict(status='PASS',roi_start=100,roi_stop=n+100,counts=counts,
                roi_marker_events=2,roi_snapshot_lookup_errors=0,roi_marker_requested_cycles=[100,n+100],
                roi_marker_snapshot_found=[1,1],roi_marker_observed_cycles=[101,n+101],
                mshr_occupancy_histogram=[n-busy,busy,0,0,0,0,0],latency_histograms=[[0]*32 for _ in range(3)])
            l1=dict(level=1,sets=512 if b else 256,ways=2,block_bytes=64,mshrs=6,
                geometry_decision_eligible=True,actual={'miss':1300 if b else 3200},
                models=[{'stats':{'miss':1300 if b else 3200}}],causal=causal)
            l2=dict(level=2,sets=512,ways=8,block_bytes=64,mshrs=16,geometry_decision_eligible=True,
                s0_replay_complete=True,snapshot_errors=0,lookup_key_errors=0)
            source=dict(paired_source_fingerprint='synthetic',hardware_sha256={'hw':'hash'},tool_sha256={'tool':'hash'},
                config='L1Causal64Config' if b else 'L1Causal32Config',l1_ways=2,l1_block_bytes=64,l1_mshrs=6,n_svb_entries=16)
            manifest=dict(hardware_generation='PASS',verilator_build='PASS',simulation='COMPLETED',exit_status=0,
                source=source,software=copy.deepcopy(seal['software']))
            summary={k:{'status':'PASS'} for k in ['correctness','integrity','protocol','data_ordering','capture_evidence','remaining_observation']}
            summary.update(performance_valid=True,benchmark_result={'verified':1,'checksum':43439728},opt4_roi_cycles=n)
            run=revision/'arms'/name/'runs'/'synthetic';(run/'analysis').mkdir(parents=True)
            pair.dump(run/'run_manifest.json',manifest);pair.dump(run/'analysis/summary.json',summary)
            pair.dump(run/'roi.json',dict(start_cycle=100,stop_cycle=n+100,safe_chain_roi_cycles=n))
            (run/'cache_opportunity.jsonl').write_text('\n'.join(json.dumps(x) for x in [l2,l1])+'\n')
        return root,revision

    def change_cache(self, revision, mutate):
        p=revision/'arms/B/runs/synthetic/cache_opportunity.jsonl'
        rows=[json.loads(x) for x in p.read_text().splitlines()]
        mutate(rows[1]);p.write_text('\n'.join(json.dumps(x) for x in rows)+'\n')

    def test_valid_pair_and_partition(self):
        root,r=self.fixture();result=pair.analyze(root,r)
        self.assertEqual(result['status'],'OPT5_DIRECTION_JUSTIFIED')
        self.assertEqual(result['causality_answer'],'YES')
        self.assertEqual(sum(result['roi_partition_delta'].values()),90000)
        self.assertEqual(result['next_optimization'],'NONE_JUSTIFIED')

    def test_missing_marker_rejects_interpretation(self):
        root,r=self.fixture();self.change_cache(r,lambda c:c['causal'].update(status='FAIL'))
        self.assertEqual(pair.analyze(root,r)['decision'],'INCONCLUSIVE_DUE_TO_CORRECTNESS_OR_MEASUREMENT')
        self.assertFalse((root/'comparison.json').exists())

    def test_inconsistent_overlap_rejected(self):
        root,r=self.fixture();self.change_cache(r,lambda c:c['causal']['counts'].update(ROB_HEAD_LOAD_BLOCK_AND_SCHEDULER_UNAVAILABLE_CYCLES=2000000))
        self.assertFalse(pair.analyze(root,r)['failed']['B']['partition'])

    def test_same_but_unsealed_tool_hash_rejected(self):
        root,r=self.fixture()
        for n in ['A','B']:
            p=r/'arms'/n/'runs/synthetic/run_manifest.json';m=pair.read(p);m['source']['tool_sha256']={'tool':'unsealed'};pair.dump(p,m)
        self.assertFalse(pair.analyze(root,r)['failed']['pair']['same_tools'])

    def test_weak_gain_not_production_opt5(self):
        root,r=self.fixture(gain=9000,head_drop=5000);result=pair.analyze(root,r)
        self.assertEqual(result['status'],'WEAK_L1_CAPACITY_SIGNAL')
        self.assertFalse(result['formal_opt5_implemented'])

    def test_large_gain_without_quantitative_head_support_not_direction(self):
        root,r=self.fixture(gain=90000,head_drop=1000);result=pair.analyze(root,r)
        self.assertEqual(result['status'],'L1_CAPACITY_OPT5_CANDIDATE')

    def test_different_actual_execution_args_rejected(self):
        root,r=self.fixture();p=root/'simulation_execution_provenance.json';obj=pair.read(p)
        obj['argv_B'][-1]='2';pair.dump(p,obj)
        self.assertFalse(pair.analyze(root,r)['failed']['pair']['same_actual_execution_arguments'])

    def test_marker_lag_outside_bounded_ring_rejected(self):
        root,r=self.fixture();self.change_cache(r,lambda c:c['causal'].update(roi_marker_observed_cycles=[165,c['causal']['roi_stop']+1]))
        self.assertFalse(pair.analyze(root,r)['failed']['B']['roi_marker_records'])

    def test_misses_without_critical_reduction_rejected(self):
        root,r=self.fixture(gain=0,head_drop=0);result=pair.analyze(root,r)
        self.assertEqual(result['status'],'REJECT_L1_CAPACITY_AS_OPT5')
        self.assertEqual(result['causality_answer'],'NO')

    def test_aborted_simulation_without_final_summaries_is_reported(self):
        root,r=self.fixture();run=r/'arms/B/runs/synthetic'
        manifest=pair.read(run/'run_manifest.json');manifest['exit_status']=1;pair.dump(run/'run_manifest.json',manifest)
        (run/'roi.json').rename(run/'incomplete_roi_fixture.json')
        (run/'cache_opportunity.jsonl').write_text('')
        result=pair.analyze(root,r)
        self.assertEqual(result['decision'],'INCONCLUSIVE_DUE_TO_CORRECTNESS_OR_MEASUREMENT')
        b=pair.read(root/'l1_64k_2way_result.json')
        self.assertIsNone(b['roi_cycles']);self.assertIsNone(b['actual_l1'])
        self.assertFalse(b['gates']['completed_software_roi'])
        self.assertEqual(len(b['missing_evidence']),4)
        self.assertTrue((root/'answers_20.md').exists())

    def test_missing_roi_with_present_counters_fails_closed(self):
        root,r=self.fixture();run=r/'arms/B/runs/synthetic'
        (run/'roi.json').rename(run/'incomplete_roi_fixture.json')
        result=pair.analyze(root,r)
        self.assertFalse(result['failed']['B']['roi_marker_records'])


if __name__=='__main__':
    unittest.main()
