#!/usr/bin/env python3
"""Finalize the three active distinct-workload PARSEC project triplets."""
import datetime
import json
import subprocess
import sys
import time
import uuid
from pathlib import Path

from overnight_parsec_remaining import (
    OUT, ROOT, dump, failure_detail, read_json, run_plan, utc_now,
    validate_triplet,
)

MAX_WAIT_SECONDS = 48 * 60 * 60
BATCHES = {
    "blackscholes_project64": "measurements_124710_1426a31f",
    "streamcluster_project64": "measurements_131425_0ee6393e",
    "canneal_project400": "measurements_131916_46c7c03f",
}


def main():
    token = datetime.datetime.now(datetime.timezone.utc).strftime("%Y%m%dT%H%M%S_") + uuid.uuid4().hex[:8]
    workdir = OUT / "build" / ("finalize_running_" + token)
    workdir.mkdir(parents=True, exist_ok=False)
    report_path = workdir / "report.json"
    report = {"state": "WAITING_FOR_THREE_DISTINCT_WORKLOADS", "started_utc": utc_now(),
              "pid": __import__("os").getpid(), "batch_ids": BATCHES,
              "unsupported_scope": "Only these three benchmarks have equivalent Native/Check/Correction HTIF builds; other PARSEC applications are listed in SUPPORT_MATRIX.md and are not hardware measurements.",
              "failures": [], "primary_triplets": {}}
    dump(report_path, report)

    deadline = time.monotonic() + MAX_WAIT_SECONDS
    results = {}
    expected = {}
    for workload in BATCHES:
        plan = OUT / ("measurement_" + workload + ".json")
        expected[workload] = {case["label"] for case in json.loads(plan.read_text())}
    while time.monotonic() < deadline:
        ready = True
        for workload, batch_id in BATCHES.items():
            snapshot = read_json(OUT / "build" / batch_id / "results.json")
            if not isinstance(snapshot, dict) or not expected[workload].issubset(snapshot):
                ready = False
                break
            results[workload] = snapshot
        if ready:
            break
        report["last_wait_check_utc"] = utc_now()
        dump(report_path, report)
        time.sleep(60)
    else:
        report["state"] = "WAIT_TIMEOUT"
        report["ended_utc"] = utc_now()
        report["failures"].append({"reason": "One or more primary triplets did not finish within 48 hours."})
        final = OUT / "logs" / ("parsec_main_run_" + token + ".json")
        dump(final, report)
        (OUT / "logs" / "parsec_main_run.latest").write_text(str(final.relative_to(ROOT)) + "\n")
        return 2

    for workload, batch in results.items():
        for label, item in batch.items():
            if item.get("exit_status") != 0 or item.get("analysis_exit_status") != 0:
                report["failures"].append(failure_detail(label, item))
        selection, reasons = validate_triplet(workload, batch)
        if selection:
            report["primary_triplets"][workload] = selection
        else:
            report["failures"].append({"workload": workload, "reason": reasons,
                                       "scope": "Excluded from primary comparisons."})
    dump(report_path, report)

    repeat_plan = [{"label": workload + "_correction_repeat", "workload": workload,
                    "design": "correction", "max_cycles": 10000000}
                   for workload in report["primary_triplets"]]
    repeat_results = {}
    if repeat_plan:
        plan_path = workdir / "correction_repeats.json"
        dump(plan_path, repeat_plan)
        repeat_results = run_plan("correction_repeats", plan_path, workdir, report, report_path)
        for label, item in repeat_results.items():
            if item.get("exit_status") != 0 or item.get("analysis_exit_status") != 0:
                report["failures"].append(failure_detail(label, item))

    primary = report["primary_triplets"]
    dump(OUT / "primary_selection.json", primary)
    repeats = {}
    for workload, ids in primary.items():
        item = repeat_results.get(workload + "_correction_repeat")
        if item and item.get("exit_status") == 0 and item.get("analysis_exit_status") == 0:
            repeats[workload] = [ids["correction"], Path(item["run_directory"]).name]
        else:
            report["failures"].append({"workload": workload, "reason": "Correction repeat failed or unavailable."})
    dump(OUT / "repeat_selection.json", repeats)

    if repeats:
        verify = subprocess.run([sys.executable, str(OUT / "scripts/verify_repeats.py")],
                                cwd=ROOT, capture_output=True, text=True)
        report["repeat_verification"] = {"exit_status": verify.returncode,
                                         "stdout": verify.stdout, "stderr": verify.stderr}
        if verify.returncode:
            report["failures"].append({"reason": "Deterministic correction repeat gate failed."})
    summary = subprocess.run([sys.executable, str(OUT / "scripts/summarize.py")],
                             cwd=ROOT, capture_output=True, text=True)
    report["summary"] = {"exit_status": summary.returncode,
                         "stdout": summary.stdout, "stderr": summary.stderr}
    report["ended_utc"] = utc_now()
    report["state"] = "COMPLETE" if not report["failures"] and summary.returncode == 0 else "COMPLETE_WITH_FAILURES"
    dump(report_path, report)
    final = OUT / "logs" / ("parsec_main_run_" + token + ".json")
    dump(final, report)
    (OUT / "logs" / "parsec_main_run.latest").write_text(str(final.relative_to(ROOT)) + "\n")
    print(json.dumps({"state": report["state"], "report": str(final.relative_to(ROOT)),
                      "primary_workloads": sorted(primary), "failures": len(report["failures"])}, indent=2))
    return 0 if summary.returncode == 0 else 1


if __name__ == "__main__":
    raise SystemExit(main())
