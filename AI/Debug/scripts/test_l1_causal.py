#!/usr/bin/env python3
"""CPU-only causal-counter and source-scope tests."""
import importlib.util
import json
from pathlib import Path
import subprocess
import tempfile
import unittest

ROOT=Path(__file__).resolve().parents[3]
NATIVE=ROOT/'chipyard/generators/rocket-chip/src/main/resources/csrc/cache_opportunity.cc'

class CausalTests(unittest.TestCase):
    def test_native_identity_joins_intersections_histograms_and_exact_roi(self):
        code='#include <cassert>\n#include "'+str(NATIVE)+'"\n'+r'''
using namespace ec_observation;
int main(){
 Causal c;
 for(U t=1;t<=22;++t){
  c.tick(t,t>=5 && t<=14?1:0,false);
  if(t==4)c.event(23,2,0,3,0,0,0);
  if(t==5){c.event(14,5,0x8000,101,7,0,0);c.event(21,16,0,101,0,0,0);}
  if(t==6)c.event(22,0,0,101,0,0,0);
  if(t==7)c.event(15,5,0x8000,101,1,0,0);
  if(t==12)c.event(16,0,0,1,0,0,0);
  c.event(18,(t>=7 && t<=15?1:0)|(t>=8 && t<=12?2:0),0,101,1,0,0);
  if(t==14)c.event(20,0,0,101,0,0,0);
  if(t==15)c.event(17,0,0,101,0,0,0);
  if(t==21)c.event(23,1,0,20,0,0,0);
 }
 assert(c.errors==0);std::fprintf(stdout,"%s\n",c.json().c_str());
 Causal overflow;for(U t=1;t<=66;++t)overflow.tick(t,0,false);
 overflow.event(23,2,0,1,0,0,0);assert(overflow.errors==1);
 Causal repeated;repeated.tick(1,0,false);
 for(unsigned i=0;i<8;++i)repeated.event(23,2,0,1,0,0,0);
 assert(repeated.markerEvents==8);assert(repeated.startMarkers==8);
}
'''
        with tempfile.TemporaryDirectory(dir=ROOT/'AI/TMP') as d:
            d=Path(d);(d/'fixture.cc').write_text(code)
            subprocess.run(['g++','-std=c++11','-Wall','-Wextra',str(d/'fixture.cc'),'-o',str(d/'fixture')],check=True,capture_output=True)
            p=subprocess.run([str(d/'fixture')],check=True,capture_output=True,text=True)
        o=json.loads(p.stdout);self.assertEqual(o['status'],'PASS');c=o['counts']
        self.assertEqual(o['roi_marker_events'],2)
        self.assertEqual(o['roi_snapshot_lookup_errors'],0)
        self.assertEqual(o['roi_marker_observed_cycles'],[4,21])
        self.assertEqual(o['roi_marker_requested_cycles'],[3,20])
        self.assertEqual(o['roi_marker_snapshot_found'],[1,1])
        self.assertEqual(p.stderr.count('[CAUSAL_ROI_MARKER]'),7) # two valid + one stale + four bounded duplicates
        expected={'sample_cycles':17,'mshr_busy_cycles':10,'mshr_full_cycles':0,
                  'load_tag_miss_requests':1,'mshr_primary_allocations':1,'refill_completions':1,
                  'load_rpq_replays':1,'load_nack_retries':1,
                  'ROB_HEAD_WAITING_ON_LOAD_MISS_CYCLES':9,
                  'ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_BUSY_CYCLES':8,
                  'SCHEDULER_UNAVAILABLE_AND_MSHR_BUSY_CYCLES':5,
                  'ROB_HEAD_LOAD_BLOCK_AND_SCHEDULER_UNAVAILABLE_CYCLES':5,
                  'detect_alloc_sum':2,'alloc_refill_sum':5,'detect_data_sum':10,
                  'miss_returns_still_head':1}
        for k,v in expected.items():self.assertEqual(c[k],v,k)
        self.assertEqual(sum(o['mshr_occupancy_histogram']),17)
        self.assertEqual([sum(h) for h in o['latency_histograms']],[1,1,1])

    def test_geometry_is_boom_only_and_single_variable(self):
        s=(ROOT/'chipyard/generators/chipyard/src/main/scala/config/RocketConfigs.scala').read_text()
        block=s.split('// L1_CAUSAL_GEOMETRY_BEGIN')[1].split('// L1_CAUSAL_GEOMETRY_END')[0]
        self.assertIn('case b: boom.common.BoomTileAttachParams',block)
        self.assertIn('_.copy(nSets = sets)',block)
        self.assertIn('WithL1CausalSets(256)',block);self.assertIn('WithL1CausalSets(512)',block)
        self.assertNotIn('nMSHRs =',block);self.assertNotIn('nWays =',block)

    def test_default_launcher_guard_and_explicit_seal_remain(self):
        s=(ROOT/'slowdown/optimization_4_svb/scripts/launch_optimization_4_svb.py').read_text()
        self.assertIn('if CAUSAL_CONTEXT is not None:',s)
        self.assertIn('unreviewed hardware changes:',s)
        self.assertIn('causal sealed input changed:',s)
        self.assertIn('paired_source_fingerprint',s)

if __name__=='__main__':unittest.main()
