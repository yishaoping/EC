#!/usr/bin/env python3
"""Validate the rescue controller before a representative fixed Canneal run."""
import argparse
import atexit
import datetime
import hashlib
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
    parser.add_argument("--parent-canneal", type=Path,
                        help="compare against the running/completed ICache-only candidate before more regressions")
    parser.add_argument("--resume-status", type=Path,
                        help="reuse a sealed build and successful directed checks from a stopped attempt")
    parser.add_argument("--preflight-only", action="store_true",
                        help="verify the resumed seals and cleanliness without starting any simulation")
    args = parser.parse_args()
    work = OUT / "build" / (args.build_id + "_measurement_" + uuid.uuid4().hex[:6])
    work.mkdir(parents=True, exist_ok=False)
    state = {"state": "WAIT_BUILD", "pid": os.getpid(), "pgid": os.getpgrp(),
             "session_id": os.getsid(0), "build_id": args.build_id,
             "run_id": work.name, "candidate": "ICache 4KiB plus full-SVB rescue r2",
             "benchmark": "canneal_project400", "commands": [],
             "start_utc": datetime.datetime.now(datetime.timezone.utc).isoformat()}
    def save():
        temporary = work / "status.tmp"
        temporary.write_text(json.dumps(state, indent=2) + "\n")
        temporary.replace(work / "status.json")
    def completed():
        value = state["state"]
        terminal = "COMPLETE" in value or "FAILED" in value or "TIMEOUT" in value or value.startswith("REJECTED")
        if not terminal:
            state["interrupted_phase"] = value
            state["state"] = "RUNNER_FAILED"
        state["exit_status"] = int("FAILED" in state["state"] or "TIMEOUT" in state["state"])
        state["end_utc"] = datetime.datetime.now(datetime.timezone.utc).isoformat()
        state["completion_marker"] = "TERMINAL_STATUS_RECORDED"
        save()
    atexit.register(completed)
    def run(name, command):
        state["state"] = name.upper()
        save()
        log = work / (name + ".log")
        argv = [sys.executable] + list(map(str, command))
        record = {"phase": name, "command": argv, "log": str(log),
                  "start_utc": datetime.datetime.now(datetime.timezone.utc).isoformat()}
        state["commands"].append(record)
        with log.open("xb") as stream:
            child = subprocess.Popen(argv, cwd=ROOT, stdout=stream, stderr=subprocess.STDOUT)
            record.update(pid=child.pid, pgid=os.getpgid(child.pid), session_id=os.getsid(child.pid))
            state["active_child"] = record.copy()
            save()
            rc = child.wait()
        record.update(exit_status=rc, end_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
        state.pop("active_child", None)
        state[name] = record.copy()
        save()
        if rc:
            state["state"] = name.upper() + "_FAILED"
            save()
            raise RuntimeError(name + " failed: " + str(log))
        return log
    save()
    print("MEASUREMENT_DIRECTORY=" + str(work), flush=True)
    resumed = json.loads(args.resume_status.read_text()) if args.resume_status else None
    if resumed:
        assert resumed["build_id"] == args.build_id
        assert resumed["state"] == "CANNEAL_FAILED" and resumed["canneal"]["exit_status"] != 0
        # This recovery is specifically for the prelaunch clean-worktree error.
        failed_log = Path(resumed["canneal"]["log"]).read_text()
        assert "Evaluation must start from a clean worktree" in failed_log
        assert "RUN_DIRECTORY=" not in failed_log, "a real simulation started; inspect it before resuming"
        state["resumed_from"] = str(args.resume_status.resolve())
        save()
    manifest = ROOT / "slowdown/optimization_6_overlap/runs" / args.build_id / "run_manifest.json"
    deadline = time.monotonic() + 4 * 3600
    while time.monotonic() < deadline:
        build = json.loads(manifest.read_text())
        if "error" in build:
            state.update(state="BUILD_FAILED", error=build["error"])
            save()
            return 1
        if build.get("hardware_generation") == "PASS":
            break
        time.sleep(15)
    else:
        state["state"] = "BUILD_WAIT_TIMEOUT"
        save()
        return 1
    generated = ROOT / "slowdown/optimization_6_overlap/build" / args.build_id / "generated"
    if resumed:
        emitted_sha = hashlib.sha256((generated / "gen-collateral/BoomNonBlockingDCache.sv").read_bytes()).hexdigest()
        for name in ["rescue_gate", "rescue_pulses", "epoch_cone"]:
            previous = resumed[name]
            assert previous["exit_status"] == 0
            lines = Path(previous["log"]).read_text().splitlines()
            results = [Path(line.removeprefix("RESULT=")) for line in lines
                       if line.startswith("RESULT=") or line.startswith("/") and line.endswith(".json")]
            assert len(results) == 1, (name, results)
            result = json.loads(results[0].read_text())
            assert result["status"] == "PASS"
            assert (result.get("emitted_sha256") or result.get("emitted_source_sha256")) == emitted_sha
            state[name] = dict(previous, reused=True, evidence=str(results[0]))
        save()
    else:
        run("rescue_gate", [OUT / "scripts/test_emitted_rescue_gate.py", generated / "gen-collateral/BoomNonBlockingDCache.sv"])
        run("rescue_pulses", [OUT / "scripts/test_emitted_rescue_pulses.py", generated / "gen-collateral/BoomNonBlockingDCache.sv"])
        run("epoch_cone", [OUT / "scripts/test_epoch_private.py", generated / "gen-collateral/BoomNonBlockingDCache.sv"])
    # The actual retained data/ACK tests were already run against this byte
    # identical SVB module; changed control is checked above and in system.
    old = Path("/data1/gzh/EC-opt4-recovery-perf/slowdown/optimization_6_overlap/build/overlap_checker_icache4k_20261104_021411_630679e4/generated/gen-collateral")
    identity = {}
    for name in ["SpeculativeVersionBuffer.sv", "BoomWritebackUnit.sv"]:
        before, after = old / name, generated / "gen-collateral" / name
        h = [hashlib.sha256(p.read_bytes()).hexdigest() for p in [before, after]]
        assert h[0] == h[1], (name, "retention/WB module changed; rerun its unit tests")
        identity[name] = h[0]
    state["unchanged_retention_WB_sha256"] = identity
    state["state"] = "WAIT_CXX"
    save()
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
    if resumed:
        revision = Path(resumed["revision"])
        sealed = json.loads(revision.read_text())
        assert sealed["build_id"] == args.build_id
        assert hashlib.sha256((ROOT / sealed["simulator"]).read_bytes()).hexdigest() == sealed["simulator_sha256"]
        state["reused_build"] = True
    else:
        revision = seal(args.build_id)
    state["revision"] = str(revision)
    state["hardware_commit"] = json.loads(revision.read_text())["canonical_hardware_commit"]
    if args.preflight_only:
        sys.path.insert(0, str(ROOT / "slowdown/parsec_evaluation_20261103/scripts"))
        import run_pilot
        run_pilot.hardware(revision, validation=True)
        assert not subprocess.check_output(["git", "status", "--porcelain=v1"], cwd=ROOT)
        state.update(state="PREFLIGHT_COMPLETE", simulation="NOT_STARTED")
        save()
        print(json.dumps(state), flush=True)
        return 0
    log = run("canneal", [OUT / "scripts/run_profile.py", "canneal_project400", revision,
                          "--max-cycles", "2500000"])
    paths = [line.split("=", 1)[1] for line in log.read_text().splitlines() if line.startswith("RUN_DIRECTORY=")]
    assert len(paths) == 1
    state["canneal"]["run"] = paths[0]
    actual = Path(paths[0])
    baseline = ROOT / "slowdown/parsec_evaluation_20261103/runs/canneal_project400_correction_20261103_131917_9545510b"
    before = json.loads((baseline / "run_manifest.json").read_text())
    after = json.loads((actual / "run_manifest.json").read_text())
    for key in ["elf_sha256", "roi_instret", "output"]:
        assert before[key] == after[key], key
    profile = json.loads((actual / "stall_profile.json").read_text())
    handoffs = profile["groups"]["55"].get("counts", {}).get("rescue_handoffs", 0)
    state["canneal"].update(ROI_cycles=after["roi_cycles"], frozen_ROI_cycles=before["roi_cycles"],
                            correction_check=after["roi_cycles"] / 419398,
                            relative_ROI_reduction=1 - after["roi_cycles"] / before["roi_cycles"],
                            measured_ROI_rescue_handoffs=handoffs)
    if args.parent_canneal:
        parent = args.parent_canneal.resolve()
        state.update(state="WAIT_PARENT_CANNEAL", parent_canneal=str(parent))
        save()
        parent_deadline = time.monotonic() + 4 * 3600
        while not (parent / "analysis.json").exists():
            if time.monotonic() >= parent_deadline:
                state["state"] = "PARENT_WAIT_TIMEOUT"
                save()
                return 1
            time.sleep(30)
        parent_analysis = json.loads((parent / "analysis.json").read_text())
        parent_manifest = json.loads((parent / "run_manifest.json").read_text())
        assert parent_analysis["status"] == "PASS" and parent_analysis["full_session_checker_work"]["complete"]
        for key in ["elf_sha256", "roi_instret", "output"]:
            assert parent_manifest[key] == after[key], key
        gain = 1 - after["roi_cycles"] / parent_manifest["roi_cycles"]
        state["incremental_over_icache_candidate"] = {
            "parent_ROI_cycles": parent_manifest["roi_cycles"], "ROI_reduction": gain,
            "minimum_gain_for_additional_regressions": 0.005}
        if gain < 0.005 or handoffs == 0:
            state.update(state="REJECTED_AFTER_REPRESENTATIVE",
                         decision="Rescue adds less than 0.5 percent over ICache-only, or has no measured ROI handoff; preserve evidence without spending a full regression suite")
            state["end_utc"] = datetime.datetime.now(datetime.timezone.utc).isoformat()
            save()
            print(json.dumps(state), flush=True)
            return 0
        suite_log = run("regressions", [OUT / "scripts/run_regressions.py", revision,
                                        "--reuse-canneal", actual])
        suites = [line.split("=", 1)[1] for line in suite_log.read_text().splitlines()
                  if line.startswith("SUITE_DIRECTORY=")]
        assert len(suites) == 1
        state["regressions"]["suite"] = suites[0]
        run("comparison", [OUT / "scripts/compare_results.py", suites[0]])
        state["state"] = "VALIDATED_MEASUREMENT_COMPLETE"
    else:
        state["state"] = "REPRESENTATIVE_VALIDATED_MEASUREMENT_COMPLETE"
    state["end_utc"] = datetime.datetime.now(datetime.timezone.utc).isoformat()
    save()
    print(json.dumps(state), flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
