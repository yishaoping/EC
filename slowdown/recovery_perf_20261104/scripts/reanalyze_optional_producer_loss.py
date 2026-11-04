#!/usr/bin/env python3
"""Preserve a failed capture; reclassify only the proven optional-footer bug."""
import argparse
import copy
import hashlib
import json
import re
import subprocess
import sys
import uuid
from pathlib import Path
from seal_candidate import ROOT, OUT


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("run", type=Path)
    args = parser.parse_args()
    run = args.run.resolve()
    cap = json.loads((run / "capture_summary.json").read_text())
    manifest = json.loads((run / "run_manifest.json").read_text())
    assert cap["incomplete_reasons"] == ["malformed_producer_statistics"]
    missing = set(cap["observers"]) - set(cap["producers"])
    assert missing == {"4:4", "5:3", "5:4"} and len(cap["producers"]) == 128
    assert len(cap["observers"]) == 131 and not cap["optional_evidence_complete"]
    for identity, producer in cap["producers"].items():
        observer = cap["observers"][identity]
        assert observer["footers_seen"] == 1
        assert producer["emitted"] == observer["events_seen"] == observer["footer_emitted_count"]
        assert producer["produced"] == producer["emitted"] + producer["omitted"]
        assert producer["omitted"] == 0
    # Prove the old parser's capacity bug against the actual sealed tool.
    source = manifest["build_evidence"]["source"]
    relative = "slowdown/optimization_4_svb/scripts/compact_capture.py"
    old = subprocess.check_output(["git", "show", source["git_head"] + ":" + relative], cwd=ROOT)
    assert hashlib.sha256(old).hexdigest() == source["tool_sha256"][relative]
    assert b"len(self.producers) >= 128" in old and b"len(self.observers) >= 144" in old
    # Generated instances of kinds 4/5 use the sealed logger's default limit.
    build = ROOT / "slowdown/optimization_6_overlap/build" / manifest["build_evidence"]["revision"]["build_id"]
    top = build / "generated/gen-collateral/DigitalTop.sv"
    instances = re.findall(r"SafeChainEventLogger #\((.*?)\) ghm_safe_chain_observer_[45](?:_\d+)? \(", top.read_text(), re.S)
    assert len(instances) == 8
    assert all("MAX_EVENTS" not in p and re.search(r"\.KIND\([45]\)", p) for p in instances)
    relative_logger = "chipyard/generators/rocket-chip/src/main/resources/vsrc/SafeChainEventLogger.v"
    logger = ROOT / relative_logger
    sealed_logger = subprocess.check_output(["git", "show", source["git_head"] + ":" + relative_logger], cwd=ROOT)
    assert sha(logger) == hashlib.sha256(sealed_logger).hexdigest()
    assert sha(build / "generated/gen-collateral/SafeChainEventLogger.v") == sha(logger)
    text = logger.read_text()
    assert re.search(r"parameter integer MAX_EVENTS\s*=\s*200000", text)
    assert "emitted >= event_limit" in text and "omitted = omitted + 1" in text
    assert "KIND == 14 || KIND == 15" in text
    # No synthetic producer totals are inserted. These optional statistics
    # remain unavailable. Their independent real footers are retained and
    # are below the limit, so the producer could not have omitted an event.
    footer_counts = {}
    for line in (run / "safe_chain_events.tsv").open():
        words = line.split()
        if words[0] == "SC_END" and len(words) == 8:
            identity = words[5] + ":" + words[6]
            if identity in missing:
                assert identity not in footer_counts
                footer_counts[identity] = int(words[7])
    for identity in missing:
        observer = cap["observers"][identity]
        assert observer["footers_seen"] == 1
        assert 0 < footer_counts[identity] == observer["footer_emitted_count"] == observer["events_seen"] < 200000
    recovered = copy.deepcopy(cap)
    recovered["incomplete_reasons"] = []
    recovered["mandatory_evidence_complete"] = True
    proof = {"original_run": str(run), "original_capture_sha256": sha(run / "capture_summary.json"),
             "original_analysis_sha256": sha(run / "analysis.json"),
             "missing_optional_producer_statistics": sorted(missing), "independent_footer_counts": footer_counts,
             "generated_top_sha256": sha(top), "sealed_logger_sha256": sha(logger),
             "scope": "Only optional final producer metadata was rejected after parser identity 128; all 128 retained producer totals match real footers. Missing optional totals are not invented. Default limit 200000 and emitted below limit prove zero source omissions. All mandatory protocol/integrity/package evidence remains subject to unchanged validators."}
    recovered["optional_producer_statistics_reanalysis"] = proof
    dest = OUT / "build" / (run.name + "_capture_reanalysis_" + uuid.uuid4().hex[:6])
    dest.mkdir(parents=True, exist_ok=False)
    for name in ["stdout.log", "stderr.log", "safe_chain_events.tsv", "cache_opportunity.jsonl", "roi.json"]:
        (dest / name).symlink_to(run / name)
    manifest["capture_reanalysis"] = proof
    manifest["capture"] = recovered
    (dest / "run_manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")
    (dest / "capture_summary.json").write_text(json.dumps(recovered, indent=2) + "\n")
    (dest / "reanalysis_proof.json").write_text(json.dumps(proof, indent=2) + "\n")
    sys.path.insert(0, str(ROOT / "slowdown/parsec_evaluation_20261103/scripts"))
    import analyze_pilot
    from profile_stalls import report
    result = analyze_pilot.analyze(dest)
    (dest / "stall_profile.json").write_text(json.dumps(report(dest), indent=2) + "\n")
    print("REANALYSIS_DIRECTORY=" + str(dest), flush=True)
    print(json.dumps({"status": result["status"], "errors": result["errors"],
                      "full_checker_work": result["full_session_checker_work"]}), flush=True)
    return int(result["status"] != "PASS" or not result["full_session_checker_work"]["complete"])


if __name__ == "__main__":
    raise SystemExit(main())
