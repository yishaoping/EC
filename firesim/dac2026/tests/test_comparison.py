"""Offline identity/join fixtures only; no target or benchmark is executed."""
import copy
import csv
from pathlib import Path
import tempfile
import unittest

from ec_dac import DEFINITION
from ec_dac.common import digest
from ec_dac.comparison import ARTIFACTS, SCHEMA, configuration_signature, grouping, validate_sample_comparison
from ec_dac.analysis import summarize
from ec_dac.ledger import Journal
from test_contract import sample, metrics, setup_campaign


def descriptor(label):
    return {"path":"/OFFLINE_FIXTURE_ONLY/" + label, "sha256":digest(label)}


def fixture_samples():
    b, c = sample("B",0), sample("C4",4)
    for s in (b,c):
        s["case"] = {"benchmark":"OFFLINE_FIXTURE_ONLY", "files":{"input":digest("input-v1")},
                     "common":{"memory_model":"fixture_latency_40", "boom_mhz":200}}
        s["comparison_key"] = digest(s["case"])
        s["artifacts"] = {k:descriptor(s["configuration"]["id"]+"-"+k) for k in ARTIFACTS}
    context = {"schema":SCHEMA, "definition":DEFINITION, "reviewed":True,
               "common":copy.deepcopy(b["case"]["common"]),
               "baseline":{"configuration":configuration_signature(b["configuration"]), "artifacts":b["artifacts"]},
               "software_manifest":descriptor("common-software"), "observer_manifest":descriptor("common-observer"),
               "comparability_evidence":descriptor("common-evidence")}
    for s in (b,c):
        bind(s, context)
    return b,c


def bind(s, context):
    admission = {"schema":SCHEMA, "reviewed":True, "context_id":digest(context),
                 "configuration":configuration_signature(s["configuration"]), "source_id":s["source_id"],
                 "artifacts_id":digest(s["artifacts"]), "evidence":[descriptor("config-evidence")]}
    s["comparison"] = {"context":copy.deepcopy(context), "context_id":digest(context),
                       "admission":admission, "admission_id":digest(admission)}
    s.pop("sample_id",None)
    s["sample_id"] = digest(s)[:24]


class ComparisonTests(unittest.TestCase):
    def test_public_baseline_reused_after_unrelated_site_source_and_kit_change(self):
        b,c = fixture_samples()
        c.update(source_id="new-C2-C8-source-inventory",site_id="new-site-with-C2-C8",kit_id="new-unrelated-script")
        bind(c,c["comparison"]["context"])
        self.assertEqual(grouping(b),grouping(c))
        with tempfile.TemporaryDirectory() as t:
            p=Path(t)
            for campaign,s,cycles in ((p/"old-B",b,100),(p/"new-C4",c,150)):
                setup_campaign(campaign,[s]); j=Journal(campaign)
                m=metrics(s["configuration"]["rockets"],cycles);m["synthetic"]=False
                j.commit(s,1,m);j.close()
            summarize([p/"old-B",p/"new-C4"],p/"report",plots=False)
            with open(p/"report/slowdown.csv") as f:
                rows=list(csv.DictReader(f))
            self.assertEqual(float(next(r for r in rows if r["configuration"]=="C4")["slowdown"]),1.5)

    def test_changed_baseline_memory_software_observer_never_reuses_old_B(self):
        b,c=fixture_samples()
        for field in ("baseline", "memory", "software_manifest", "observer_manifest"):
            changed=copy.deepcopy(c);context=changed["comparison"]["context"]
            if field=="baseline":context["baseline"]["artifacts"]["bitstream"]=descriptor("different-B")
            elif field=="memory":
                context["common"]["memory_model"]="fixture_latency_50"
                changed["case"]["common"]=copy.deepcopy(context["common"])
                changed["comparison_key"]=digest(changed["case"])
            else:context[field]=descriptor("changed-"+field)
            bind(changed,context)
            self.assertNotEqual(grouping(b),grouping(changed),field)

    def test_input_change_cannot_join_even_with_same_context(self):
        b,c=fixture_samples();c["case"]["files"]["input"]=digest("input-v2")
        c["comparison_key"]=digest(c["case"]);bind(c,c["comparison"]["context"])
        self.assertNotEqual(grouping(b),grouping(c))

    def test_stale_or_tampered_admission_is_rejected(self):
        _,c=fixture_samples()
        for key,value in (("source_id","changed"),("artifacts",{}),("comparison_key","old-input")):
            changed=copy.deepcopy(c);changed[key]=value
            with self.assertRaises(ValueError,msg=key):validate_sample_comparison(changed)
        changed=copy.deepcopy(c);changed["comparison"]["context"]["definition"]="commit-time-is-wrong"
        with self.assertRaises(ValueError):grouping(changed)

    def test_old_records_retain_exact_identity_matching(self):
        b,c=sample("B",0),sample("C4",4)
        self.assertEqual(grouping(b),grouping(c))
        c["site_id"]="unrelated-new-artifact-without-proof"
        self.assertNotEqual(grouping(b),grouping(c))

    def test_distinct_C4_versions_are_not_silently_averaged(self):
        _,c=fixture_samples();changed=copy.deepcopy(c)
        changed["artifacts"]["bitstream"]=descriptor("different-C4-bitstream")
        bind(changed,changed["comparison"]["context"])
        with tempfile.TemporaryDirectory() as t:
            p=Path(t);setup_campaign(p,[c,changed])
            with self.assertRaisesRegex(ValueError,"multiple hardware/software versions"):
                summarize([p],p/"report",plots=False)


if __name__=="__main__":unittest.main()
