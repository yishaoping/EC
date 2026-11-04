#!/usr/bin/env python3
"""Reuse sealed PARSEC binaries and gates, retaining every checker work interval."""
import argparse
import hashlib
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "slowdown/parsec_evaluation_20261103/scripts"))
import run_pilot
import analyze_pilot
from profile_stalls import report


def main():
    p = argparse.ArgumentParser()
    p.add_argument("workload")
    p.add_argument("revision", type=Path)
    p.add_argument("--max-cycles", type=int, default=10000000)
    args = p.parse_args()
    runner_sha = hashlib.sha256(Path(__file__).read_bytes()).hexdigest()
    capture_sha = hashlib.sha256(Path(run_pilot.compact_capture.__file__).read_bytes()).hexdigest()
    # A bounded 64 MiB event budget (72 MiB including other streams) retains
    # full-session work counters plus the periodic main-core/cache samples.
    base_router = run_pilot.compact_capture.Router
    class ProfileRouter(base_router):
        def __init__(self, directory):
            super().__init__(directory, event_limit=64 * 1024 * 1024)
    run_pilot.compact_capture.Router = ProfileRouter
    old_optional = run_pilot.compact_capture.optional_event
    run_pilot.compact_capture.optional_event = lambda k, h: k not in (11, 12) and old_optional(k, h)
    runs = set()
    original_dump = run_pilot.dump
    def capture_manifest(path, data):
        if path.name == "run_manifest.json" and path.parent.parent == run_pilot.OUT / "runs":
            runs.add(path.parent)
        original_dump(path, data)
    run_pilot.dump = capture_manifest
    sys.argv = ["run_pilot.py", args.workload, "correction", "--validation",
                "--hardware-revision", str(args.revision.resolve()),
                "--max-cycles", str(args.max_cycles)]
    rc = run_pilot.main()
    assert len(runs) == 1
    run = runs.pop()
    manifest_path = run / "run_manifest.json"
    manifest = json.loads(manifest_path.read_text())
    manifest["profiling_capture_policy"] = {
        "runner_sha256": runner_sha, "capture_sha256": capture_sha,
        "event_limit_bytes": 64 * 1024 * 1024,
        "mandatory_checker_work_kinds": [11, 12]}
    manifest_path.write_text(json.dumps(manifest, indent=2) + "\n")
    if rc == 0:
        result = analyze_pilot.analyze(run)
        profile = report(run)
        (run / "stall_profile.json").write_text(json.dumps(profile, indent=2) + "\n")
        full = result.get("full_session_checker_work", {})
        print("PROFILE_VALIDATION=" + json.dumps({"status": result["status"],
            "full_checker_work": full, "errors": result["errors"]}), flush=True)
        return int(result["status"] != "PASS" or not full.get("complete"))
    return rc


if __name__ == "__main__":
    raise SystemExit(main())
