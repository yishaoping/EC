#!/usr/bin/env python3
"""Compare fixed workloads and retain physical counters without shadow estimates."""
import argparse
import json
from pathlib import Path
from seal_candidate import ROOT, OUT


def read(path):
    return json.loads(path.read_text())


def counters(analysis):
    cache = analysis.get("cache_opportunity", {})
    physical = []
    for model in cache.get("models", []):
        physical.append({"level": model["level"], "instance": model["instance"],
                         "cycles": model.get("cycles"), "actual": model.get("actual"),
                         "mshr_full_cycles": model.get("mshr_full_cycles"),
                         "writebacks": model.get("writebacks"),
                         "dram_facing_reads": model.get("dram_facing_reads"),
                         "dram_facing_writes": model.get("dram_facing_writes")})
    frontend = {identity: value["counters"] for identity, value in
                analysis.get("terminal_snapshots", {}).get("snapshots", {}).items()
                if identity.startswith("49:")}
    checker = analysis.get("checker_profile", {})
    return {"physical_cache_traffic": physical,
            "SVB_entry_accounting": cache.get("entry_accounting"),
            "SVB_occupancy": cache.get("shadow_8_capacity"),
            "sourcec": analysis.get("sourcec", {}).get("counters"),
            "retained_copy": analysis.get("retained_copy", {}).get("counters"),
            "checker_frontend_traffic_window": frontend,
            "checker_ROI_local_partition": checker.get("local_priority_cycles"),
            "checker_ROI_captured_packages": checker.get("fully_captured_ROI_packages"),
            "checker_ROI_capture_excluded": checker.get("excluded"),
            "full_session_checker_work": analysis.get("full_session_checker_work"),
            "scope": "physical traffic uses its recorded window, not automatically the application ROI; checker cycles are local; overlapping exposures are not additive savings"}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("suite", type=Path)
    args = parser.parse_args()
    suite = args.suite.resolve()
    status = read(suite / "status.json")
    selection = read(OUT / "baseline/primary_selection.json")
    result = {"revision": read(Path(status["revision"])), "suite": str(suite),
              "status": "PASS", "benchmarks": {}, "errors": []}
    lines = ["| Benchmark | Native cycles | Check cycles | Frozen correction | Candidate correction | Frozen Corr/Check | Candidate Corr/Check | ROI reduction |",
             "|---|---:|---:|---:|---:|---:|---:|---:|"]
    for workload, selected in selection.items():
        before_run = ROOT / "slowdown/parsec_evaluation_20261103/runs" / selected["correction"]
        before = read(before_run / "analysis.json")
        before_manifest = read(before_run / "run_manifest.json")
        check = read(ROOT / "slowdown/parsec_evaluation_20261103/runs" / selected["check"] / "analysis.json")
        native = read(ROOT / "slowdown/parsec_evaluation_20261103/runs" / selected["native"] / "analysis.json")
        test = status["tests"].get(workload, {})
        row = {"native_cycles": native["ROI_cycles"], "check_cycles": check["ROI_cycles"],
               "frozen_correction_cycles": before["ROI_cycles"],
               "frozen_correction_check": before["ROI_cycles"] / check["ROI_cycles"],
               "before_counters": counters(before), "test": test}
        result["benchmarks"][workload] = row
        if not test.get("run") or test.get("exit_status") != 0:
            result["errors"].append(workload + ": regression did not pass")
            continue
        run = Path(test["run"])
        after = read(run / "analysis.json")
        manifest = read(run / "run_manifest.json")
        for key in ["elf_sha256", "roi_instret", "output"]:
            if manifest[key] != before_manifest[key]:
                result["errors"].append(workload + ": changed " + key)
        if after["status"] != "PASS" or not after.get("full_session_checker_work", {}).get("complete"):
            result["errors"].append(workload + ": incomplete correctness/checker work")
        row.update(candidate_correction_cycles=after["ROI_cycles"],
                   candidate_correction_check=after["ROI_cycles"] / check["ROI_cycles"],
                   relative_ROI_reduction=1 - after["ROI_cycles"] / before["ROI_cycles"],
                   main_retired_instructions=manifest["roi_instret"],
                   main_IPC={"check": check["main_hart_roi_instret"] / check["ROI_cycles"],
                             "frozen": before_manifest["roi_instret"] / before["ROI_cycles"],
                             "candidate": manifest["roi_instret"] / after["ROI_cycles"]},
                   after_counters=counters(after), stall_profile=read(run / "stall_profile.json"))
        lines.append(f"| {workload} | {row['native_cycles']:,} | {row['check_cycles']:,} | {row['frozen_correction_cycles']:,} | {row['candidate_correction_cycles']:,} | {row['frozen_correction_check']:.6f} | {row['candidate_correction_check']:.6f} | {100*row['relative_ROI_reduction']:.2f}% |")
    test = status["tests"].get("bfs", {})
    if test.get("run") and test.get("exit_status") == 0:
        run = Path(test["run"])
        bfs = read(run / "result.json")
        work = read(run / "full_checker_work.json")
        result["bfs"] = {"test": test, "result": bfs, "full_checker_work": work,
                         "native_cycles": 1001675, "frozen_correction_cycles": 1128052,
                         "candidate_correction_native": bfs["ROI_cycles"] / 1001675,
                         "relative_ROI_reduction": 1 - bfs["ROI_cycles"] / 1128052,
                         "stall_profile": read(run / "stall_profile.json")}
        if bfs["status"] != "PASS" or not work["complete"]:
            result["errors"].append("BFS correctness/checker work failed")
    else:
        result["errors"].append("BFS regression did not pass")
    if result["errors"]:
        result["status"] = "FAIL"
    (suite / "comparison.json").write_text(json.dumps(result, indent=2) + "\n")
    (suite / "comparison.md").write_text("\n".join(lines) + "\n")
    print(json.dumps({"status": result["status"], "errors": result["errors"], "report": str(suite / "comparison.md")}), flush=True)
    return int(result["status"] != "PASS")


if __name__ == "__main__":
    raise SystemExit(main())
