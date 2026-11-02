#!/usr/bin/env python3
"""Offline fixtures: CPU-only parsers/observer model, never hardware simulation."""
import importlib.util
import json
from pathlib import Path
import subprocess
import tempfile
import unittest

ROOT=Path(__file__).resolve().parents[3]

def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path)
    m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m

remaining=module('remaining',Path(__file__).with_name('analyze_opt4_remaining.py'))
a=module('svb_analysis',ROOT/'slowdown/optimization_4_svb/analysis/analyze_svb.py')
f=module('cache_fixtures',ROOT/'slowdown/optimization_4_svb/scripts/offline_capacity_cache_tests.py')

class RemainingTests(unittest.TestCase):
    def test_union_and_overlap_never_add_activity(self):
        self.assertEqual(remaining.duration([[1,8],[3,10]]),9)
        self.assertEqual(remaining.intersect([[1,8],[3,10]],[[5,12]]),[[5,10]])
        self.assertEqual(remaining.merge([[0,4],[4,7],[9,9]]),[[0,7]])

    def test_level_local_sanity_keeps_l1_hypothesis_and_rejects_l2(self):
        rows=f.cache_rows();rows[1]['geometry_decision_eligible']=False
        rows[1]['models'][0]['stats'].update(hit=0,miss=100)
        with tempfile.TemporaryDirectory() as d:
            d=Path(d);(d/'cache_opportunity.jsonl').write_text('\n'.join(json.dumps(r) for r in rows))
            out=a.cache_opportunity(d,True)
        self.assertEqual(out['status'],'PASS')
        self.assertEqual(out['cache_opt_candidate']['level'],1)
        self.assertEqual(out['models'][1]['decision'],'S0_SANITY_OR_COVERAGE_FAILED_NO_GEOMETRY_DECISION')
        self.assertTrue(all(m['miss_reduction_vs_s0'] is None and
                            m['replacement_reduction_vs_s0'] is None
                            for m in out['models'][1]['models']))

    def test_snapshot_audit_is_required_even_if_s0_miss_count_matches(self):
        for bad in ('s0_replay_complete','read_consistent_snapshots','snapshot_errors','lookup_key_errors'):
            rows=f.cache_rows();r=rows[1]
            r.update(s0_replay_schema=2,s0_replay_complete=True,read_consistent_snapshots=100,snapshot_errors=0,lookup_key_errors=0)
            r[bad]=False if bad=='s0_replay_complete' else 1
            with tempfile.TemporaryDirectory() as d:
                d=Path(d);(d/'cache_opportunity.jsonl').write_text('\n'.join(json.dumps(x) for x in rows))
                out=a.cache_opportunity(d,True)
            self.assertFalse(out['models'][1]['geometry_decision_eligible'])
            self.assertEqual(out['models'][1]['analyzer_read_consistency_audit'],'FAIL')

    def test_legacy_missing_exact_counters_are_unknown(self):
        self.assertEqual(a.remaining_observation([],Path('does-not-exist'))['status'],'UNOBSERVED')

    def test_counter_partition_and_rob_overlap_checks(self):
        records=[dict(kind=10,hart=0,cycle=10,nums=[0,1]+[0]*14),dict(kind=30,hart=0,cycle=20,nums=[0]*16)]
        for k in range(40,46):records.append(dict(kind=k,hart=0,cycle=20,nums=[1,10]+[0]*14))
        records[-1]['nums'][2]=10
        with tempfile.TemporaryDirectory() as d:
            p=Path(d)/'events';p.write_text(''.join(f'SC_END\t1\t1\t1\t1\t{k}\t0\t1\n' for k in range(40,46)))
            self.assertEqual(a.remaining_observation(records,p)['status'],'PASS')
            records[3]['nums'][2]=1 # overlap > zero activity
            self.assertEqual(a.remaining_observation(records,p)['status'],'FAIL')
            records[3]['nums'][2]=0;records[4]['nums'][2]=1 # unmatched partition total
            self.assertEqual(a.remaining_observation(records,p)['status'],'FAIL')

    def test_observer_is_native_input_only_and_rows_precede_demand(self):
        p=ROOT/'chipyard/generators/sifive-cache/design/craft/inclusivecache/src'
        s=(p/'Scheduler.scala').read_text();d=(p/'Directory.scala').read_text()
        self.assertIn('val observationEvents = observationReadRows ++ Seq(',s)
        self.assertIn('directory.io.observationTag, directory.io.observationSet',s)
        self.assertIn('Mux(setQuash && bypass.way === UInt(i), bypass.data, w)',d)
        self.assertIn('params.restoreAddress(params.expandAddress',s)
        self.assertIn('value = io.in.a.bits.opcode',s)
        host=(ROOT/'chipyard/generators/rocket-chip/src/main/resources/csrc/cache_opportunity.cc').read_text()
        self.assertIn('s0_hit=complete && read_hit;',host)
        self.assertNotIn('s0_hit=(flags&4)',host)

    def test_native_directory_timeline_and_missing_snapshot_fixtures(self):
        src=ROOT/'chipyard/generators/rocket-chip/src/main/resources/csrc/cache_opportunity.cc'
        code='#include <cassert>\n#include "'+str(src)+'"\n'+r'''
using namespace ec_observation;
static void snapshot(Cache &c,U line,unsigned set=1,bool missing=false) {
 for(unsigned w=0;w<c.ways-(missing?1:0);++w) c.event(13,w==0?1:0,line+64*w,0,0,set,w,0);
}
int main() {
 const U A=0x80008040ULL,B=0x80018040ULL;
 Cache c(2,0,1024,16,64,4);c.enabled=true;
 c.event(5,1,A,0,0,1,0,0);
 // Accepted input write B is ahead of older lookup A's RAM/bypass view.
 c.event(5,1,B,0,0,1,0,0);snapshot(c,A);
 c.event(1,5,A,0,A,1,0,1);
 assert(c.models[0].c.hit==1 && c.temporal_mirror_disagreements==1);
 assert(c.lookup_snapshots==1 && !c.lookup_snapshot_errors && !c.lookup_key_errors);
 // S0 must compare tags itself, never copy actual.hit from flags.
 snapshot(c,B);c.event(1,5,A,0,A,1,0,1);
 assert(c.models[0].c.miss==1 && c.actual.hit==2);
 // Do not use stale rows from the preceding demand to fill missing ways.
 snapshot(c,A,1,true);c.event(1,5,A,0,A,1,0,1);
 assert(c.lookup_snapshot_errors==1);
 snapshot(c,A);c.event(1,5,A,0,B,1,0,1);assert(c.lookup_key_errors==1);
 c.event(6,1,A,7,6,0,0,0);c.event(6,2,A,7,7,0,0,0);
 assert(c.request_a==1 && c.request_c==1 && c.a_opcodes[6]==1 && c.c_opcodes[7]==1);
 Cache warm(2,0,1024,16,64,4);warm.enabled=false;warm.event(5,1,A,0,0,1,0,0);
 warm.clear_stats();warm.enabled=true;snapshot(warm,A);warm.event(1,5,A,0,A,1,0,1);
 assert(warm.models[0].c.hit==1 && warm.temporal_mirror_disagreements==0);
 Cache duplicate(2,0,1024,16,64,4);duplicate.enabled=true;
 snapshot(duplicate,A);snapshot(duplicate,A);duplicate.event(1,5,A,0,A,1,0,1);
 assert(duplicate.lookup_snapshot_errors==1);
 Cache orphan(2,0,1024,16,64,4);orphan.enabled=true;orphan.stop_seen=true;
 snapshot(orphan,A);orphan.event(1,5,A,0,A,1,0,1);snapshot(orphan,A);
 finish(orphan); // an orphan final snapshot must fail closed
}
'''
        with tempfile.TemporaryDirectory(dir=ROOT/'AI/TMP') as d:
            d=Path(d);(d/'fixture.cc').write_text(code)
            subprocess.run(['g++','-std=c++11','-Wall','-Wextra',str(d/'fixture.cc'),'-o',str(d/'fixture')],check=True,capture_output=True)
            result=subprocess.run([str(d/'fixture')],check=True,capture_output=True,text=True)
            summary=json.loads(result.stderr.strip().removeprefix('CACHE_OPPORTUNITY '))
            self.assertFalse(summary['s0_replay_complete'])
            self.assertFalse(summary['geometry_decision_eligible'])

if __name__=='__main__':unittest.main()
