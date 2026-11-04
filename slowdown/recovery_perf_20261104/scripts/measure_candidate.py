#!/usr/bin/env python3
"""Seal a finished build, validate the pilot, then run all fixed regressions."""
import argparse
import datetime
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
    parser.add_argument("baseline_run", type=Path)
    args = parser.parse_args()
    work = OUT / "build" / (args.build_id + "_measurement_" + uuid.uuid4().hex[:6])
    work.mkdir(parents=True, exist_ok=False)
    state = {"state": "WAIT_BUILD", "pid": os.getpid(), "build_id": args.build_id,
             "baseline_run": str(args.baseline_run.resolve()),
             "start_utc": datetime.datetime.now(datetime.timezone.utc).isoformat()}
    def save():
        temp = work / "status.tmp"
        temp.write_text(json.dumps(state, indent=2) + "\n")
        temp.replace(work / "status.json")
    def execute(name, argv):
        state["state"] = name.upper()
        save()
        log = work / (name + ".log")
        with log.open("xb") as stream:
            rc = subprocess.run([sys.executable] + list(map(str, argv)), cwd=ROOT,
                                stdout=stream, stderr=subprocess.STDOUT).returncode
        state[name] = {"exit_status": rc, "log": str(log)}
        save()
        return rc, log
    save()
    manifest = ROOT / "slowdown/optimization_6_overlap/runs" / args.build_id / "run_manifest.json"
    deadline = time.monotonic() + 3 * 3600
    while time.monotonic() < deadline:
        build = json.loads(manifest.read_text())
        if "error" in build:
            state.update(state="BUILD_FAILED", error=build["error"])
            save()
            return 1
        if build.get("verilator_build") == "PASS":
            break
        time.sleep(15)
    else:
        state["state"] = "BUILD_WAIT_TIMEOUT"
        save()
        return 1
    revision = seal(args.build_id)
    state["revision"] = str(revision)
    rc, log = execute("pilot", [OUT / "scripts/run_profile.py", "streamcluster_simdev", revision,
                                "--max-cycles", "2200000"])
    paths = [line.split("=", 1)[1] for line in log.read_text().splitlines() if line.startswith("RUN_DIRECTORY=")]
    state["pilot"]["run"] = paths[-1] if paths else None
    if rc or not paths:
        state["state"] = "PILOT_FAILED"
        save()
        return 1
    # The original observation-only run must also reproduce the accepted
    # target cycles/instructions. Do not promote a pilot with changed work.
    baseline = args.baseline_run.resolve()
    baseline_analysis = json.loads((baseline / "analysis.json").read_text())
    baseline_manifest = json.loads((baseline / "run_manifest.json").read_text())
    pilot = Path(paths[-1])
    pilot_analysis = json.loads((pilot / "analysis.json").read_text())
    pilot_manifest = json.loads((pilot / "run_manifest.json").read_text())
    checks = {"baseline_status": baseline_analysis["status"] == "PASS",
              "baseline_complete_work": baseline_analysis["full_session_checker_work"]["complete"],
              "baseline_cycles_reproduced": baseline_manifest["roi_cycles"] == 1452774,
              "baseline_instructions_reproduced": baseline_manifest["roi_instret"] == 1094668,
              "output_checksum": "5e0eed7ac7af71fb" in " ".join(baseline_manifest["output"]),
              "pilot_status": pilot_analysis["status"] == "PASS",
              "pilot_complete_work": pilot_analysis["full_session_checker_work"]["complete"]}
    for key in ["elf_sha256", "roi_instret", "output"]:
        checks["pilot_matches_" + key] = baseline_manifest[key] == pilot_manifest[key]
    state["pilot_validation"] = checks
    state["pilot_cycle_change"] = pilot_manifest["roi_cycles"] - baseline_manifest["roi_cycles"]
    if not all(checks.values()):
        state["state"] = "REPRODUCIBILITY_OR_PILOT_VALIDATION_FAILED"
        save()
        return 1
    # Canneal's independently measured frontend pressure justifies testing
    # all main inputs even if Streamcluster's pilot benefit is small.
    rc, log = execute("regressions", [OUT / "scripts/run_regressions.py", revision])
    paths = [line.split("=", 1)[1] for line in log.read_text().splitlines() if line.startswith("SUITE_DIRECTORY=")]
    state["regressions"]["suite"] = paths[-1] if paths else None
    if paths:
        compare_rc, _ = execute("comparison", [OUT / "scripts/compare_results.py", paths[-1]])
        rc = rc or compare_rc
    state["state"] = "VALIDATED_MEASUREMENT_COMPLETE" if rc == 0 and paths else "REGRESSION_FAILED"
    state["end_utc"] = datetime.datetime.now(datetime.timezone.utc).isoformat()
    save()
    print(json.dumps(state), flush=True)
    return int(rc != 0 or not paths)


if __name__ == "__main__":
    raise SystemExit(main())
