#!/usr/bin/env python3
"""Reuse sealed PARSEC binaries and gates, retaining every checker work interval."""
import argparse
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
    # Preserve the established capture budget while reserving protocol capacity
    # for full-session checker instruction/load/store counters, not examples.
    old_optional = run_pilot.compact_capture.optional_event
    run_pilot.compact_capture.optional_event = lambda k, h: k not in (11, 12) and old_optional(k, h)
    before = set((run_pilot.OUT / "runs").iterdir())
    sys.argv = ["run_pilot.py", args.workload, "correction", "--validation",
                "--hardware-revision", str(args.revision.resolve()),
                "--max-cycles", str(args.max_cycles)]
    rc = run_pilot.main()
    fresh = set((run_pilot.OUT / "runs").iterdir()) - before
    assert len(fresh) == 1
    run = fresh.pop()
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
