#!/usr/bin/env python3
"""Run the fixed main inputs against one sealed candidate, preserving failures."""
import argparse
import concurrent.futures
import datetime
import json
import subprocess
import sys
import uuid
from pathlib import Path
from seal_candidate import ROOT, OUT


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("revision", type=Path)
    parser.add_argument("--reuse-canneal", type=Path,
                        help="reuse the completed representative test from this same sealed simulator")
    args = parser.parse_args()
    revision = args.revision.resolve()
    suite = OUT / "runs" / ("regressions_" + datetime.datetime.now(datetime.timezone.utc).strftime("%Y%m%d_%H%M%S_") + uuid.uuid4().hex[:6])
    suite.mkdir(parents=True, exist_ok=False)
    status = {"revision": str(revision), "state": "RUNNING", "tests": {}}
    def save():
        (suite / "status.json").write_text(json.dumps(status, indent=2) + "\n")
    save()
    print("SUITE_DIRECTORY=" + str(suite), flush=True)
    commands = {
        "streamcluster_project64": [str(OUT / "scripts/run_profile.py"), "streamcluster_project64", str(revision), "--max-cycles", "5500000"],
        "canneal_project400": [str(OUT / "scripts/run_profile.py"), "canneal_project400", str(revision), "--max-cycles", "2500000"],
        "blackscholes_project64": [str(OUT / "scripts/run_profile.py"), "blackscholes_project64", str(revision), "--max-cycles", "8000000"],
        "bfs": [str(OUT / "scripts/run_bfs_profile.py"), str(revision)]}
    if args.reuse_canneal:
        reused = args.reuse_canneal.resolve()
        manifest = json.loads((reused / "run_manifest.json").read_text())
        analysis = json.loads((reused / "analysis.json").read_text())
        sealed = json.loads(revision.read_text())
        assert reused.name.startswith("canneal_project400_correction_"), reused
        assert manifest["simulator_sha256"] == sealed["simulator_sha256"]
        assert analysis["status"] == "PASS" and analysis["full_session_checker_work"]["complete"]
        status["tests"]["canneal_project400"] = {
            "exit_status": 0, "run": str(reused), "reused_representative": True}
        del commands["canneal_project400"]
        save()
    def run(name):
        log = suite / (name + ".log")
        with log.open("xb") as stream:
            process = subprocess.run([sys.executable] + commands[name], cwd=ROOT, stdout=stream, stderr=subprocess.STDOUT)
        paths = [line.split("=", 1)[1] for line in log.read_text().splitlines() if line.startswith("RUN_DIRECTORY=")]
        return name, {"exit_status": process.returncode, "run": paths[-1] if paths else None, "log": str(log)}
    with concurrent.futures.ThreadPoolExecutor(max_workers=3) as pool:
        futures = [pool.submit(run, name) for name in commands]
        for future in concurrent.futures.as_completed(futures):
            name, result = future.result()
            status["tests"][name] = result
            save()
            print(name + "=" + json.dumps(result), flush=True)
    status["state"] = "PASS" if all(r["exit_status"] == 0 for r in status["tests"].values()) else "FAIL"
    save()
    return int(status["state"] != "PASS")


if __name__ == "__main__":
    raise SystemExit(main())
