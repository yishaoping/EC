import copy
import importlib.util
import json
import os
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

from ec_dac import DEFINITION
from ec_dac.common import atomic_json, digest, filehash
from ec_dac.measurement import ReferenceObserver, bucket_bounds, quantile_interval, validate_metrics
from ec_dac.ledger import Journal, read_records, recover, status
from ec_dac.collector import Collector
from ec_dac.analysis import summarize
from ec_dac.fpga import parse_utilization
from ec_dac.cli import main as cli_main
from ec_dac.planning import make_manifest

def metrics(rockets=2, cycles=100, latency=25):
    o=ReferenceObserver(rockets,17)
    o.roi_begin(100,0,True)
    if rockets:
        o.allocate(1,100)
        o.boom_done(1,110)
        o.verify_done(1,110+latency)
    o.pressure(cycles,0,8,False,[],[False]*rockets)
    o.roi_end(100+cycles,True)
    o.drained(100+cycles+max(latency,10),True,True)
    m=o.snapshot(True)
    m.update(output_correct=True,output_digest="a"*64)
    return m

def sample(cid="C2",n=2,repeat=1):
    s={"schema":"ec-dac/1","definition":DEFINITION,"experiment_id":"TEST_FIXTURE_ONLY",
       "configuration":{"id":cid,"rockets":n,"mode":"unprotected" if n==0 else
                        ("detect" if cid.startswith("D") else "diagnostic" if "barrier" in cid else "correct"),"ready":True},
       "case":{"benchmark":"TEST_FIXTURE","common":{}},"comparison_key":"common-test-case",
       "source_id":"test-source","site_id":"test-site","repetition":repeat,"artifacts":{}}
    s["sample_id"]=digest(s)[:24]
    return s

def setup_campaign(path,samples):
    atomic_json(path/"manifest.json",{"samples":samples,"blockers":[],"schema":"ec-dac/1"})

class MeasurementTests(unittest.TestCase):
    def test_fpga_resources_are_separate_and_require_complete_totals(self):
        fixture="\n".join(["| CLB LUTs* | 1,234 | 0 |", "| CLB Registers | 2,345 | 0 |",
                           "| Block RAM Tile | 12.5 | 0 |", "| DSPs | 3 | 0 |"])
        self.assertEqual(parse_utilization(fixture),{"LUT":1234,"FF":2345,"BRAM_tiles":12.5,"DSP":3})
        with self.assertRaises(ValueError):parse_utilization("| CLB LUTs | 1234 |")

    def test_execution_may_precede_membership_observation(self):
        o=ReferenceObserver(2,1);o.roi_begin(0,0,True)
        o.allocate(1,40);o.boom_done(1,20);o.verify_done(1,80)
        self.assertEqual(o.total,60)

    def test_original_exec_timestamp_not_notification_time(self):
        o=ReferenceObserver(2,1);o.roi_begin(0,0,True);o.allocate(1,1)
        o.verify_done(1,80)  # CDC can deliver notification in another host order
        o.boom_done(1,20)
        self.assertEqual(o.total,60)
        self.assertEqual(o.count,1)

    def test_dirty_roi_and_incomplete_tail_rejected(self):
        o=ReferenceObserver(2,1)
        with self.assertRaises(ValueError):o.roi_begin(0,1,True)
        o.roi_begin(0,0,True);o.allocate(1,1);o.boom_done(1,5);o.roi_end(10,True)
        with self.assertRaises(ValueError):o.drained(20,True,True)
        with self.assertRaises(ValueError):o.snapshot(True)
        o.verify_done(1,500);o.drained(501,True,True)
        self.assertEqual(o.snapshot(True)["latency_max"],495)

    def test_zeros_wrap_duplicates_and_cancel_rejected(self):
        o=ReferenceObserver(2,1);o.roi_begin(0,0,True)
        for seq in (0,1<<32):
            with self.assertRaises(ValueError):o.allocate(seq,1)
        o.allocate(1,1)
        with self.assertRaises(ValueError):o.allocate(1,2)
        with self.assertRaises(ValueError):o.verify_done(1,5,"CANCELLED")

    def test_histogram_and_quantiles(self):
        self.assertEqual(bucket_bounds(255),(255,255))
        self.assertEqual(bucket_bounds(256),(256,271))
        self.assertEqual(bucket_bounds((1<<64)-1)[1],(1<<64)-1)
        h=[{"lo":1,"hi":1,"count":1},{"lo":256,"hi":271,"count":99}]
        self.assertEqual(quantile_interval(h,.99),[256,271])

    def test_formal_validation_excludes_synthetic_and_tail(self):
        m=metrics();c=sample()["configuration"]
        self.assertIn("synthetic/unlabelled data excluded",validate_metrics(m,c))
        self.assertEqual(validate_metrics(m,c,True),[])
        m["outstanding"]=1
        self.assertTrue(validate_metrics(m,c,True))

    def test_overflow_and_counters_checked(self):
        m=metrics();c=sample()["configuration"]
        for field,value in [("overflow",True),("roi_cycles",1<<64),("busy_roi_ticks",[101,0]),
                            ("latency_count",2),("queue_full_ticks",101)]:
            bad=copy.deepcopy(m);bad[field]=value
            self.assertTrue(validate_metrics(bad,c,True),field)

class DurableTests(unittest.TestCase):
    def test_retry_resets_cumulative_snapshot(self):
        with tempfile.TemporaryDirectory() as t:
            p=Path(t);s=sample();setup_campaign(p,[s]);c=Collector(p)
            base={"sample_id":s["sample_id"],"identity_digest":digest(s),"definition":DEFINITION}
            c.event({**base,"attempt":1,"event_seq":1,"type":"start"})
            c.event({**base,"attempt":1,"event_seq":2,"type":"snapshot","metrics":metrics(latency=40)})
            c.interrupted("fixture interruption")
            c.event({**base,"attempt":2,"event_seq":1,"type":"start"})
            self.assertNotIn(s["sample_id"],c.latest)
            self.assertEqual(c.event({**base,"attempt":2,"event_seq":2,"type":"snapshot","metrics":metrics(latency=10)}),"accepted")
            c.interrupted("fixture cleanup");c.close()

    def test_stale_bridge_snapshot_stops_online_collection(self):
        with tempfile.TemporaryDirectory() as t:
            p=Path(t);s=sample();setup_campaign(p,[s]);c=Collector(p)
            c.event({"sample_id":s["sample_id"],"identity_digest":digest(s),"definition":DEFINITION,
                     "attempt":1,"event_seq":1,"type":"start"})
            c.last[s["sample_id"]]-=61
            with self.assertRaises(TimeoutError):c.heartbeat(max_age=60,enforce_fresh=True)
            self.assertFalse(c.active)
            self.assertEqual(status(p)[0][0]["state"],"timeout")
            c.close()

    def test_torn_record_preserved_append_recovers(self):
        with tempfile.TemporaryDirectory() as t:
            p=Path(t);s=sample();setup_campaign(p,[s])
            j=Journal(p);j.append({"kind":"state","sample_id":s["sample_id"],"state":"running"});j.close()
            with open(p/"raw.jsonseq","ab") as f:f.write(b'\x1e{"torn":')
            before=(p/"raw.jsonseq").read_bytes()
            r=recover(p,True)
            self.assertEqual(r["states"][0]["state"],"interrupted")
            self.assertTrue((p/"raw.jsonseq").read_bytes().startswith(before))
            good,bad=read_records(p/"raw.jsonseq")
            self.assertTrue(bad);self.assertEqual(good[-1]["state"],"interrupted")

    def test_completed_result_kept_and_identity_changes_fail(self):
        with tempfile.TemporaryDirectory() as t:
            p=Path(t);s=sample();s2=sample(repeat=2);setup_campaign(p,[s,s2])
            j=Journal(p);result=j.commit(s,1,metrics(),True)
            j.append({"kind":"state","sample_id":s2["sample_id"],"state":"running"});j.close()
            before=filehash(result)
            recover(p,True)
            states,_=status(p,allow_synthetic=True)
            self.assertEqual([r["state"] for r in states],["complete","interrupted"])
            self.assertEqual(filehash(result),before)
            changed=copy.deepcopy(s);changed["source_id"]="different"
            self.assertEqual(status(p,{"samples":[changed]},True)[0][0]["state"],"failed")

    def test_disk_fsync_failure_is_fatal(self):
        with tempfile.TemporaryDirectory() as t:
            j=Journal(t)
            with patch("ec_dac.ledger.os.fsync",side_effect=OSError("disk full")):
                with self.assertRaises(OSError):j.append({"kind":"test"})
            j.close()

    def test_duplicate_and_conflicting_adapter_records(self):
        with tempfile.TemporaryDirectory() as t:
            p=Path(t);s=sample();setup_campaign(p,[s]);c=Collector(p)
            e={"sample_id":s["sample_id"],"identity_digest":digest(s),"definition":DEFINITION,
               "attempt":1,"event_seq":1,"type":"start"}
            self.assertEqual(c.event(e),"accepted")
            self.assertEqual(c.event(e),"duplicate")
            with self.assertRaises(ValueError):c.event({**e,"unexpected":"conflicting payload"})
            with self.assertRaises(ValueError):c.event({**e,"type":"snapshot","event_seq":3,"metrics":metrics()})
            c.interrupted("unit test");c.close()

    def test_atomic_no_clobber(self):
        with tempfile.TemporaryDirectory() as t:
            p=Path(t)/"x.json";atomic_json(p,{"a":1},False)
            with self.assertRaises(FileExistsError):atomic_json(p,{"a":2},False)
            self.assertEqual(json.loads(p.read_text()),{"a":1})

class PlanningTests(unittest.TestCase):
    def test_empty_campaign_cannot_claim_a_stage_ran(self):
        with tempfile.TemporaryDirectory() as t:
            p=Path(t);setup_campaign(p,[])
            with patch("ec_dac.cli.campaign_path",return_value=p),patch("ec_dac.runner.deploy") as deploy:
                with self.assertRaisesRegex(ValueError,"no admitted samples"):
                    cli_main(["stage","--campaign","FIXTURE_ONLY","--stage","main","--execute"])
                deploy.assert_not_called()

    def test_link_bootstrap_requires_structural_not_completed_runtime_tests(self):
        with tempfile.TemporaryDirectory() as t:
            p=Path(t);kit=p/"kit";(kit/"config").mkdir(parents=True)
            for n in ("binary","input","validator"):(p/n).write_text("OFFLINE_FIXTURE")
            config={"experiment_id":"FIXTURE_ONLY","common":{"app_threads":1,"input":"simsmall"},
                    "configurations":[{"id":"C4","rockets":4,"ready":False,"structural_ready":True}],
                    "stages":{"link":["C4"],"main":["C4"]}}
            bench={"name":"fixture","threads":1,"input_name":"simsmall","roi_hooks_verified":True,
                   "binary":str(p/"binary"),"inputs":[str(p/"input")],"validator":str(p/"validator"),
                   "guest_argv":["/unused/fixture"],"guest_cwd":"/unused","guest_verify_argv":["/unused/verifier"]}
            atomic_json(kit/"config/experiment.json",config)
            atomic_json(kit/"config/benchmarks.json",{"benchmarks":[bench]})
            atomic_json(kit/"config/site.json",{"per_config_artifacts":{}})
            with patch("ec_dac.planning.KIT",kit),patch("ec_dac.planning.DATA",p/"data"),\
                 patch("ec_dac.planning.source_identity",return_value={"id":"fixture-source"}),\
                 patch("ec_dac.planning.kit_identity",return_value={"id":"fixture-kit"}):
                self.assertEqual(make_manifest("link-fixture","link")["blockers"],[])
                self.assertTrue(make_manifest("main-fixture","main")["blockers"])
                with self.assertRaisesRegex(ValueError,"outside this stage"):
                    make_manifest("invalid-fixture","link",config_filter=["B"])

class AnalysisTests(unittest.TestCase):
    @unittest.skipUnless(importlib.util.find_spec("matplotlib"),"plot dependency unavailable")
    def test_complete_matrix_plots_share_one_baseline(self):
        # Temporary offline fixture only; never persisted as real experiment data.
        with tempfile.TemporaryDirectory() as t:
            p=Path(t)
            specs=[("B",0,100),("C2",2,160),("C4",4,150),("C8",8,140)]
            samples=[sample(cid,n) for cid,n,_ in specs]
            setup_campaign(p,samples);j=Journal(p)
            for s,(_,n,cycles) in zip(samples,specs):
                m=metrics(n,cycles);m["synthetic"]=False
                j.commit(s,1,m)
            j.close()
            out=p/"report";r=summarize([p],out,plots=True)
            self.assertEqual(r["valid_complete_samples"],4)
            c4=next(x for x in r["geometric_means"] if x["comparison"]=="default" and x["configuration"]=="C4")
            self.assertAlmostEqual(c4["geomean_slowdown"],1.5)
            self.assertGreaterEqual(len(list(out.glob("*.png"))),4)

    def test_incomplete_group_not_in_geomean(self):
        with tempfile.TemporaryDirectory() as t:
            p=Path(t);s=[sample("B",0),sample("C4",4)]
            setup_campaign(p,s);j=Journal(p)
            for item in s[:1]:
                m=metrics(item["configuration"]["rockets"]);m["synthetic"]=False
                j.commit(item,1,m)
            j.close()
            out=p/"report";r=summarize([p],out,plots=False)
            default=[x for x in r["geometric_means"] if x["comparison"]=="default"]
            self.assertTrue(all(x["geomean_slowdown"] is None for x in default))
            self.assertEqual(r["valid_complete_samples"],1)
            self.assertIn("pending",(out/"missing-failed.csv").read_text())

    def test_mismatched_workload_not_compared(self):
        with tempfile.TemporaryDirectory() as t:
            p=Path(t);a=sample("B",0);b=sample("C4",4);b["comparison_key"]="different-input"
            setup_campaign(p,[a,b]);j=Journal(p)
            for s in (a,b):
                m=metrics(s["configuration"]["rockets"]);m["synthetic"]=False;j.commit(s,1,m)
            j.close();out=p/"report";summarize([p],out,plots=False)
            rows=(out/"slowdown.csv").read_text()
            self.assertNotIn(",C4,",rows)

if __name__=="__main__":unittest.main()
