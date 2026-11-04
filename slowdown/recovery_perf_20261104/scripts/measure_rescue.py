#!/usr/bin/env python3
"""Validate the rescue controller before a representative fixed Canneal run."""
import argparse
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
    args = parser.parse_args()
    work = OUT / "build" / (args.build_id + "_measurement_" + uuid.uuid4().hex[:6])
    work.mkdir(parents=True, exist_ok=False)
    state = {"state": "WAIT_BUILD", "pid": os.getpid(), "build_id": args.build_id,
             "start_utc": datetime.datetime.now(datetime.timezone.utc).isoformat()}
    def save():
        temporary = work / "status.tmp"
        temporary.write_text(json.dumps(state, indent=2) + "\n")
        temporary.replace(work / "status.json")
    def run(name, command):
        state["state"] = name.upper()
        save()
        log = work / (name + ".log")
        with log.open("xb") as stream:
            rc = subprocess.run([sys.executable] + list(map(str, command)), cwd=ROOT,
                                stdout=stream, stderr=subprocess.STDOUT).returncode
        state[name] = {"exit_status": rc, "log": str(log)}
        save()
        if rc:
            state["state"] = name.upper() + "_FAILED"
            save()
            raise RuntimeError(name + " failed: " + str(log))
        return log
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
    run("rescue_gate", [OUT / "scripts/test_emitted_rescue_gate.py", generated / "gen-collateral/BoomNonBlockingDCache.sv"])
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
    revision = seal(args.build_id)
    state["revision"] = str(revision)
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
    state["state"] = "REPRESENTATIVE_VALIDATED_MEASUREMENT_COMPLETE"
    state["end_utc"] = datetime.datetime.now(datetime.timezone.utc).isoformat()
    save()
    print(json.dumps(state), flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
