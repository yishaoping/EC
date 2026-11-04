#!/usr/bin/env python3
"""Finish a private profiling build and retain bounded diagnostic evidence."""
import argparse
import json
import os
import subprocess
import sys
import time
import uuid
from pathlib import Path
from seal_candidate import ROOT, OUT, seal


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("build_id")
    args = parser.parse_args()
    build = ROOT / "slowdown/optimization_6_overlap/runs" / args.build_id / "run_manifest.json"
    work = OUT / "build" / (args.build_id + "_diagnostics_" + uuid.uuid4().hex[:6])
    work.mkdir(parents=True, exist_ok=False)
    status = {"state": "WAIT_BUILD", "pid": os.getpid(), "build_id": args.build_id}
    status_path = work / "status.json"
    def save():
        status_path.write_text(json.dumps(status, indent=2) + "\n")
    save()
    deadline = time.monotonic() + 3 * 3600
    while time.monotonic() < deadline:
        m = json.loads(build.read_text())
        if "error" in m:
            status.update(state="BUILD_FAILED", error=m["error"])
            save()
            return 1
        if m.get("verilator_build") == "PASS":
            break
        time.sleep(30)
    else:
        status["state"] = "BUILD_WAIT_TIMEOUT"
        save()
        return 1
    revision = seal(args.build_id)
    status.update(state="SHORT_DIAGNOSTIC", revision=str(revision))
    save()
    cases = [("streamcluster_simdev", 2200000, "baseline_reproducibility")]
    for workload, cycles, name in cases:
        command = [sys.executable, str(OUT / "scripts/run_profile.py"),
                   workload, str(revision), "--max-cycles", str(cycles)]
        status["state"] = name.upper()
        save()
        log = work / (name + ".log")
        with log.open("xb") as stream:
            process = subprocess.run(command, cwd=ROOT, stdout=stream, stderr=subprocess.STDOUT)
        paths = [line.split("=", 1)[1] for line in log.read_text().splitlines()
                 if line.startswith("RUN_DIRECTORY=")]
        status[name] = {"exit_status": process.returncode, "log": str(log),
                        "run": paths[-1] if paths else None}
        save()
        if name == "short_diagnostic" and paths:
            subprocess.run([sys.executable, str(OUT / "scripts/profile_stalls.py"),
                            paths[-1], "--start", "200000", "--stop", "400000"],
                           cwd=ROOT, stdout=(work / "short_profile.json").open("x"), check=True)
        if name == "baseline_reproducibility" and process.returncode:
            status["state"] = "BASELINE_VALIDATION_FAILED"
            save()
            return 1
    status["state"] = "COMPLETE"
    save()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
