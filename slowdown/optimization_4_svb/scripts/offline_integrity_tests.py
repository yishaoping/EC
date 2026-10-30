#!/usr/bin/env python3
"""Adversarial evidence fixtures plus native host observer tests; no RTL simulation."""
from collections import Counter
import copy
import importlib.util
import json
from pathlib import Path
import subprocess
import tempfile
import unittest

ROOT=Path('/data1/gzh/EC')
spec=importlib.util.spec_from_file_location('integrity',ROOT/'slowdown/optimization_4_svb/analysis/integrity_ledger.py')
l=importlib.util.module_from_spec(spec);spec.loader.exec_module(l)

def event(kind,cycle,nums,hart=0):
    return dict(kind=kind,cycle=cycle,time=cycle+103,episode=1,hart=hart,nums=nums+[0]*(16-len(nums)))


def lifecycle(serial=1,entry=0,line=0x80008040,pkg=179,gen=123,base=0):
    words=[0x1122334455667788+i for i in range(8)]
    h=0
    for i,x in enumerate(words):h^=l.rotate(x,i*7)
    rows=[event(32,base+1,[2,serial,entry,line,pkg,gen,0,7,1,h,8]),
          event(33,base+2,[2,serial,entry,h]),event(36,base+2,[2,serial,entry,pkg],entry),
          event(34,base+3,[2,serial,entry,h,h])]
    for i in range(4):
        rh=words[2*i]^l.rotate(words[2*i+1],7)
        rows.append(event(37,base+4+i,[2,serial,entry,line,pkg,gen,0,7,rh,2*i,2,8]))
    for i in range(8):rows.append(event(38,base+8+i,[2,line,pkg,gen,0,6,words[i],i,1,8]))
    def protocol(k,c):
        n=[1,1,entry,line,pkg,6,6,gen,0,1,7,0,0,1,1,6]
        return event(k,base+c,n)
    rows += [protocol(21,16),protocol(22,17),event(35,base+17,[2,serial,entry,1,0],entry)]
    return rows


class IntegrityTests(unittest.TestCase):
    def test_single_lifecycle_and_last_beat(self):
        out=l.build(lifecycle());self.assertEqual(out['status'],'PASS',out['errors'])
        self.assertEqual(out['completions'],1)

    def test_slot_reuse_identical_version_is_distinct(self):
        out=l.build(lifecycle()+lifecycle(serial=2,base=20))
        self.assertEqual(out['status'],'PASS',out['errors']);self.assertEqual(out['allocations'],2)

    def test_same_line_different_package(self):
        self.assertEqual(l.build(lifecycle()+lifecycle(serial=2,pkg=180,base=20))['status'],'PASS')

    def test_same_package_different_generation(self):
        self.assertEqual(l.build(lifecycle()+lifecycle(serial=2,gen=124,base=20))['status'],'PASS')

    def test_normal_lower_writes_before_and_after_do_not_contaminate(self):
        rs=lifecycle();normal=event(38,0,[2,0x80008040,179,123,0,6,0,0,1,8])
        normal2=copy.deepcopy(normal);normal2.update(cycle=30,time=133)
        self.assertEqual(l.build([normal]+rs+[normal2])['status'],'PASS')

    def test_corruption_at_each_checkpoint_fails(self):
        for kind,index in ((33,3),(34,4),(37,8),(38,6)):
            rs=lifecycle();r=next(x for x in rs if x['kind']==kind);r['nums'][index]^=1
            self.assertEqual(l.build(rs)['status'],'FAIL',kind)

    def test_missing_and_duplicate_final_beat_fail(self):
        rs=lifecycle();last=max((r for r in rs if r['kind']==38),key=lambda r:r['cycle'])
        self.assertEqual(l.build([r for r in rs if r is not last])['status'],'FAIL')
        self.assertEqual(l.build(rs+[copy.deepcopy(last)])['status'],'FAIL')

    def test_reordered_beats_and_early_ack_fail(self):
        rs=lifecycle();beats=[x for x in rs if x['kind']==38];beats[0]['nums'][7],beats[1]['nums'][7]=1,0
        self.assertEqual(l.build(rs)['status'],'FAIL')
        rs=lifecycle();r=next(x for x in rs if x['kind']==21);r.update(cycle=10,time=113)
        self.assertEqual(l.build(rs)['status'],'FAIL')

    def test_occupied_slot_and_serial_reuse_fail(self):
        self.assertEqual(l.build(lifecycle()+lifecycle(serial=2,entry=0,base=2))['status'],'FAIL')
        self.assertEqual(l.build(lifecycle()+lifecycle(base=20))['status'],'FAIL')

    def test_missing_capture_or_stored_checkpoint_fails(self):
        for kind in (32,33):self.assertEqual(l.build([x for x in lifecycle() if x['kind']!=kind])['status'],'FAIL')
        self.assertEqual(l.build([])['status'],'UNOBSERVED')

    def test_coalescing_is_explicit_and_requires_newer_safe_successor(self):
        rs=lifecycle(serial=2,entry=1,gen=124,base=10)
        old=[event(32,1,[2,1,0,0x80008040,179,123,0,7,1,0,8]),event(33,2,[2,1,0,0]),
             event(36,3,[2,1,0,179]),event(35,12,[2,1,0,2,2])]
        self.assertEqual(l.build(old+rs)['status'],'PASS')
        bad=copy.deepcopy(old);bad[-1]['nums'][4]=99
        self.assertEqual(l.build(bad+rs)['status'],'FAIL')

    def test_simultaneous_free_allocate_other_slot_and_export(self):
        rs=lifecycle()+lifecycle(serial=2,entry=1,base=16)
        out=l.build(rs);self.assertEqual(out['status'],'PASS',out['errors'])
        with tempfile.TemporaryDirectory() as d:
            l.export(out,d);self.assertTrue((Path(d)/'svb_lifecycle_ledger.csv').is_file())

    def test_allocation_without_terminal_and_double_free_fail(self):
        rs=lifecycle();self.assertEqual(l.build(rs[:-1])['status'],'FAIL')
        self.assertEqual(l.build(rs+[copy.deepcopy(rs[-1])])['status'],'FAIL')

    def test_native_observer_deferred_fill_shadow_and_histograms(self):
        src=ROOT/'chipyard/generators/rocket-chip/src/main/resources/csrc/cache_opportunity.cc'
        code='#include <cassert>\n#include "'+str(src)+'"\n'+r'''
int main() {
 using namespace ec_observation;
 Cache c(1,0,256,2,64,6); c.enabled=true;
 // A miss must not create a resident line until metadata/fill commits.
 c.event(1,9,0x80008040,1,0,1,0,0);
 c.event(1,9,0x80008040,2,0,1,0,0);
 assert(c.models[0].c.miss==2 && c.models[1].c.miss==2);
 c.event(5,3,0x80008040,0,0,1,0,0);
 c.event(1,5,0x80008040,3,0,1,0,1);
 assert(c.models[0].c.hit==1 && c.models[1].c.hit==1);
 // Replay of the same functional token is counted only once.
 c.event(1,5,0x80008040,3,0,1,0,1); assert(c.actual.access==3);
 c.event(32,16,0,0,0,0,7,1); c.event(32,16,0,0,0,0,8,2);
 c.event(32,16,0,0,0,0,9,3); c.event(32,16,0,0,0,0,16,4);
 c.enabled=false; c.event(32,16,0,0,0,0,0,0); // STOP excluded
 assert(c.svb_occupancy_hist[7]==1 && c.svb_occupancy_hist[8]==1 && c.svb_occupancy_hist[9]==1);
 assert(c.svb_occupancy_hist[16]==1 && c.svb_occupancy_hist[0]==0 && c.svb_depth_hist[4]==1);
 c.enabled=true; c.event(3,0,0x80008040,0,0,0,0,0);
 c.event(1,9,0x80008040,4,0,1,0,0); assert(c.models[1].c.miss==3);
 Cache l2(2,0,1024,16,64,4); l2.enabled=true;
 l2.event(12,0,0x80008040,0,0,0,0,0); // C-only install
 l2.event(1,5,0x80008040,0,0,1,0,1); assert(l2.models[1].c.hit==1);
}
'''
        with tempfile.TemporaryDirectory() as d:
            d=Path(d);(d/'test.cc').write_text(code)
            subprocess.run(['g++','-std=c++11','-O0',str(d/'test.cc'),'-o',str(d/'test')],check=True,capture_output=True)
            subprocess.run([str(d/'test')],check=True,capture_output=True)

    def test_occupancy_depth_simultaneous_state_oracle(self):
        slots={};occ=[0]*17;depth=[0]*17
        # Samples are pre-edge, followed by one atomic delete/allocate update.
        actions=[([],[(i,0 if i<4 else i) for i in range(16)]),([0],[(0,99)]),([],[]),([1,2,3],[])]
        for deleted,allocated in actions:
            occ[len(slots)]+=1
            counts={line:list(slots.values()).count(line) for line in slots.values()}
            depth[max(counts.values(),default=0)]+=1
            next_slots={k:v for k,v in slots.items() if k not in deleted};next_slots.update(allocated)
            self.assertEqual(len(next_slots),len(slots)-len(deleted)+len(allocated))
            slots=next_slots
        self.assertEqual(occ[16],3);self.assertEqual(depth[4],1);self.assertEqual(depth[3],2)
        self.assertEqual(sum(occ),sum(depth))


    def test_depth_one_to_four_multiple_lines_and_coalescing(self):
        slots={}; observed=[]
        for i in range(4):
            slots[i]=100; observed.append(max(list(slots.values()).count(line) for line in slots.values()))
        self.assertEqual(observed,[1,2,3,4])
        slots.update({4:200,5:200}); self.assertEqual(max(Counter(slots.values()).values()),4)
        # Coalescing retires three older images of the first line atomically.
        slots={k:v for k,v in slots.items() if k not in (0,1,2)}
        self.assertEqual(max(Counter(slots.values()).values()),2)

    def final_summary(self, corruption=False, missing_checkpoint=False):
        def load(name,file):
            spec=importlib.util.spec_from_file_location(name,file);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
        a=load('svb_final_analysis',ROOT/'slowdown/optimization_4_svb/analysis/analyze_svb.py')
        fixtures=load('cache_fixture_v2',ROOT/'slowdown/optimization_4_svb/scripts/offline_capacity_cache_tests.py')
        rs=lifecycle()
        n=[1,1,0,0x80008040,179,6,7,123,0,1,7,0,0,1,0,6]
        rs += [event(19,2,n),event(20,4,n[:11]+[1,0,1,0,6]),event(20,7,n[:11]+[0,1,1,1,6])]
        stats=[1]+[0]*15
        for i in (6,7,13,14):stats[i]=1
        rs += [event(25,40,stats),event(30,40,[2,16,0,0,0,1,1,0,0,0]),
               event(10,0,[0,1,0])]
        bins=[40]+[0]*16
        for kind in (17,18):
            for chunk in (0,1):rs.append(event(kind,40,[chunk]+bins[chunk*15:(chunk+1)*15],chunk))
        if missing_checkpoint:rs=[r for r in rs if r['kind']!=33]
        if corruption:next(r for r in rs if r['kind']==38)['nums'][6]^=1
        with tempfile.TemporaryDirectory() as d:
            d=Path(d);text=''
            for r in rs:
                text+='\t'.join(map(str,['SC1',r['time'],r['cycle'],r['cycle'],r['episode'],r['kind'],r['hart']]))+'\t'+'\t'.join(f'{n:016x}' for n in r['nums'])+'\n'
            for (kind,hart),count in Counter((r['kind'],r['hart']) for r in rs).items():
                text+=f'SC_END\t99\t99\t99\t1\t{kind}\t{hart}\t{count}\n'
            (d/'safe_chain_events.tsv').write_text(text)
            (d/'run_manifest.json').write_text(json.dumps({'source':{'revision_mode':'corrected_svb16_integrity_v2'}}))
            (d/'stdout.log').write_text('[RUN] benchmark=gapbs_bfs verified=1 parent_checksum=43439728\n[COMPUTATION] status=PASS\n[END] hart=0 status=PASS\n')
            (d/'roi.json').write_text(json.dumps({'roi_cycles':40}))
            rows=fixtures.cache_rows();rows[0]['data_fingerprints']={'schema':2}
            for row in rows:row['cycles']=40
            rows[0]['shadow_8_capacity'].update(occupancy_histogram=bins,depth_histogram=bins)
            (d/'cache_opportunity.jsonl').write_text('\n'.join(json.dumps(r) for r in rows))
            return a.run_summary(d)

    def test_final_analyzer_accepts_complete_evidence(self):
        out=self.final_summary()
        self.assertEqual(out['correctness']['status'],'PASS',out)
        self.assertTrue(out['performance_valid'])

    def test_final_analyzer_rejects_corruption_and_missing_checkpoint(self):
        for kwargs in ({'corruption':True},{'missing_checkpoint':True}):
            out=self.final_summary(**kwargs)
            self.assertEqual(out['correctness']['status'],'FAIL')
            self.assertFalse(out['performance_valid'])


if __name__=='__main__':unittest.main()
