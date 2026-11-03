#!/usr/bin/env python3
"""Wait for the active Blackscholes triplet, then run remaining supported cases."""
import datetime
import json
import os
import re
import subprocess
import sys
import time
import uuid
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
OUT = ROOT / "slowdown/parsec_evaluation_20261103"
RUN_BATCH = OUT / "scripts/run_measurement_batch.py"
MAX_WAIT_SECONDS = 48 * 60 * 60


def utc_now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()


def dump(path, value):
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_suffix(path.suffix + ".tmp")
    temporary.write_text(json.dumps(value, indent=2) + "\n")
    temporary.replace(path)


def read_json(path):
    try:
        return json.loads(path.read_text())
    except (OSError, json.JSONDecodeError):
        return None


def wait_for_initial_batch(results_path, labels, report, report_path):
    deadline = time.monotonic() + MAX_WAIT_SECONDS
    report["state"] = "WAITING_FOR_ACTIVE_BLACKSCHOLES_BATCH"
    report["active_batch_results"] = str(results_path.relative_to(ROOT))
    report["expected_active_labels"] = labels
    dump(report_path, report)
    while time.monotonic() < deadline:
        results = read_json(results_path)
        if isinstance(results, dict) and set(labels).issubset(results):
            report["active_batch_results_snapshot"] = results
            return results
        report["last_wait_check_utc"] = utc_now()
        dump(report_path, report)
        print("Waiting for active Blackscholes triplet to finish", flush=True)
        time.sleep(60)
    report["state"] = "STOPPED_WAIT_TIMEOUT"
    report["failure"] = "Active Blackscholes batch did not finish within 48 hours."
    dump(report_path, report)
    return None


def run_plan(name, plan_path, workdir, report, report_path):
    log = workdir / (name + ".log")
    command = [sys.executable, str(RUN_BATCH), str(plan_path)]
    item = {"plan": str(plan_path.relative_to(ROOT)), "command": command,
            "log": str(log.relative_to(ROOT)), "state": "RUNNING"}
    report.setdefault("batches", {})[name] = item
    dump(report_path, report)
    with log.open("xb") as output:
        process = subprocess.Popen(command, cwd=ROOT, stdout=output,
                                   stderr=subprocess.STDOUT, start_new_session=True)
        while process.poll() is None:
            time.sleep(60)
            item["last_update_utc"] = utc_now()
            dump(report_path, report)
    item["exit_status"] = process.returncode
    log_text = log.read_text(errors="replace")
    batch_dirs = re.findall(r"^BATCH_DIRECTORY=(.*)$", log_text, re.M)
    batch_dir = Path(batch_dirs[-1]) if batch_dirs else None
    results_path = batch_dir / "results.json" if batch_dir else None
    item["results_file"] = str(results_path.relative_to(ROOT)) if results_path else None
    item["results"] = read_json(results_path) or {} if results_path else {}
    item["state"] = "COMPLETED" if process.returncode == 0 else "COMPLETED_WITH_FAILURES"
    item["end_utc"] = utc_now()
    dump(report_path, report)
    return item["results"]


def run_details(result):
    directory = result.get("run_directory")
    if not directory:
        return None, None, None
    run = Path(directory)
    manifest = read_json(run / "run_manifest.json")
    analysis = read_json(run / "analysis.json")
    return run, manifest, analysis


def failure_detail(label, result):
    run, manifest, analysis = run_details(result)
    detail = {"label": label, "batch_result": result}
    if run is None:
        detail["reason"] = "No run directory was recorded."
        return detail
    detail["run_directory"] = str(run.relative_to(ROOT))
    detail["manifest"] = {key: manifest.get(key) for key in
                          ("state", "exit_status", "validation", "roi_cycles",
                           "roi_instret", "output", "software_correct")} if manifest else None
    detail["analysis_status"] = analysis.get("status") if analysis else None
    markers = []
    for filename in ("stdout.log", "stderr.log"):
        path = run / filename
        if not path.exists():
            continue
        for line in path.read_text(errors="replace").splitlines():
            if re.search(r"Assertion|%Error|FAILED|status=FAIL|PASSED|verified=", line, re.I):
                markers.append(line[-500:])
    detail["diagnostic_markers"] = markers[-30:]
    detail["reason"] = "Run or analysis gate failed; raw run files are retained for review."
    return detail


def validate_triplet(workload, batch_results):
    loaded = {}
    reasons = []
    for design in ("native", "check", "correction"):
        label = workload + "_" + design
        result = batch_results.get(label)
        if not result or result.get("exit_status") != 0 or result.get("analysis_exit_status") != 0:
            reasons.append(label + " run/analysis did not pass")
            continue
        run, manifest, analysis = run_details(result)
        if not manifest or not analysis:
            reasons.append(label + " is missing manifest or analysis")
            continue
        loaded[design] = (run, manifest, analysis)
        if analysis.get("status") != "PASS":
            reasons.append(label + " analysis status is not PASS")
        if manifest.get("evaluation_git_status") != "":
            reasons.append(label + " did not start from a clean worktree")
    if len(loaded) != 3:
        return None, reasons
    native, check, correction = (loaded[key][1] for key in
                                 ("native", "check", "correction"))
    for key in ("roi_instret", "output"):
        if len({json.dumps(m.get(key), sort_keys=True) for m in
                (native, check, correction)}) != 1:
            reasons.append("Triplet differs in " + key)
    if len({json.dumps(native["software"], sort_keys=True),
            json.dumps(check["software"], sort_keys=True),
            json.dumps(correction["software"], sort_keys=True)}) != 1:
        reasons.append("Triplet software/input manifests differ")
    if native.get("native_model") != "detection" or native.get("simulator_sha256") != check.get("simulator_sha256"):
        reasons.append("Native is not the matched detection baseline")
    if check.get("elf_sha256") != correction.get("elf_sha256"):
        reasons.append("Check and Correction protected ELF differ")
    revision = read_json(OUT / "hardware_revision.json") or {}
    if correction.get("canonical_hardware_commit") != revision.get("canonical_hardware_commit"):
        reasons.append("Correction hardware commit is not the accepted revision")
    if correction.get("simulator_sha256") != revision.get("simulator_sha256"):
        reasons.append("Correction simulator is not the accepted simulator")
    packages = loaded["correction"][2].get("packages", {})
    if packages.get("FAIL") != 0 or packages.get("CANCELLED") != 0 or packages.get("PASS", 0) <= 0:
        reasons.append("Correction package accounting failed")
    if reasons:
        return None, reasons
    return {design: batch_results[workload + "_" + design]["run_directory"].split("/")[-1]
            for design in ("native", "check", "correction")}, []


def main():
    token = datetime.datetime.now(datetime.timezone.utc).strftime("%Y%m%dT%H%M%S_") + uuid.uuid4().hex[:8]
    workdir = OUT / "build" / ("overnight_" + token)
    workdir.mkdir(parents=True, exist_ok=False)
    report_path = workdir / "report.json"
    report = {"schema": 1, "state": "STARTING", "started_utc": utc_now(),
              "pid": os.getpid(), "canonical_hardware_commit":
              (read_json(OUT / "hardware_revision.json") or {}).get("canonical_hardware_commit"),
              "scope": ["blackscholes_project64 current batch", "streamcluster_project64",
                        "canneal_project400", "one correction repeat per valid workload"],
              "unsupported_workloads": "Other PARSEC applications are not adapted to this HTIF runtime; see SUPPORT_MATRIX.md.",
              "failures": [], "primary_triplets": {}, "repeat_cases": {}}
    dump(report_path, report)

    active_plan = OUT / "measurement_blackscholes_project64.json"
    active_batch_id = "measurements_124710_1426a31f"
    expected_active = [case["label"] for case in json.loads(active_plan.read_text())]
    active_path = OUT / "build" / active_batch_id / "results.json"
    active = wait_for_initial_batch(active_path, expected_active, report, report_path)
    if active is None:
        report["ended_utc"] = utc_now()
        final_report = OUT / "logs" / ("overnight_" + token + ".json")
        dump(final_report, report)
        (OUT / "logs" / "overnight.latest").write_text(str(final_report.relative_to(ROOT)) + "\n")
        return 2
    report["blackscholes_project64_current_results"] = active
    for label, result in active.items():
        if result.get("exit_status") != 0 or result.get("analysis_exit_status") != 0:
            report["failures"].append(failure_detail(label, result))
    dump(report_path, report)

    all_results = {"blackscholes_project64": active}
    remaining = [("streamcluster_project64", "measurement_streamcluster_project64.json"),
                 ("canneal_project400", "measurement_canneal_project400.json")]
    for workload, plan_name in remaining:
        report["state"] = "RUNNING_" + workload.upper()
        results = run_plan(workload, OUT / plan_name, workdir, report, report_path)
        all_results[workload] = results
        for label, result in results.items():
            if result.get("exit_status") != 0 or result.get("analysis_exit_status") != 0:
                report["failures"].append(failure_detail(label, result))
        dump(report_path, report)

    primary = {}
    for workload, results in all_results.items():
        selection, reasons = validate_triplet(workload, results)
        if selection:
            primary[workload] = selection
        else:
            report["failures"].append({"workload": workload, "reason": reasons,
                                       "scope": "Triplet excluded from primary comparisons."})
    report["primary_triplets"] = primary

    repeat_plan = []
    for workload in primary:
        repeat_plan.append({"label": workload + "_correction_repeat", "workload": workload,
                            "design": "correction", "max_cycles": 10000000})
    repeat_results = {}
    if repeat_plan:
        plan_path = workdir / "repeat_plan.json"
        dump(plan_path, repeat_plan)
        report["state"] = "RUNNING_CORRECTION_REPEATS"
        repeat_results = run_plan("correction_repeats", plan_path, workdir, report, report_path)
        for label, result in repeat_results.items():
            if result.get("exit_status") != 0 or result.get("analysis_exit_status") != 0:
                report["failures"].append(failure_detail(label, result))

    primary_selection = {key: value for key, value in primary.items()}
    dump(OUT / "primary_selection.json", primary_selection)
    repeat_selection = {}
    for workload, ids in primary.items():
        label = workload + "_correction_repeat"
        result = repeat_results.get(label)
        if result and result.get("exit_status") == 0 and result.get("analysis_exit_status") == 0:
            run_dir = result.get("run_directory")
            repeat_selection[workload] = [ids["correction"], Path(run_dir).name]
        else:
            report["failures"].append({"workload": workload,
                                       "reason": "Correction repeat unavailable or failed."})
    dump(OUT / "repeat_selection.json", repeat_selection)

    report["state"] = "FINALIZING"
    report["repeat_cases"] = repeat_selection
    dump(report_path, report)
    if repeat_selection:
        verify = subprocess.run([sys.executable, str(OUT / "scripts/verify_repeats.py")],
                                cwd=ROOT, capture_output=True, text=True)
        report["repeat_verification"] = {"exit_status": verify.returncode,
                                         "stdout": verify.stdout, "stderr": verify.stderr}
        if verify.returncode != 0:
            report["failures"].append({"reason": "Deterministic correction repeat gate failed."})
    summary = subprocess.run([sys.executable, str(OUT / "scripts/summarize.py")],
                             cwd=ROOT, capture_output=True, text=True)
    report["summary"] = {"exit_status": summary.returncode,
                         "stdout": summary.stdout, "stderr": summary.stderr}
    report["ended_utc"] = utc_now()
    report["state"] = "COMPLETE" if not report["failures"] and summary.returncode == 0 else "COMPLETE_WITH_FAILURES"
    dump(report_path, report)
    final_report = OUT / "logs" / ("overnight_" + token + ".json")
    dump(final_report, report)
    (OUT / "logs" / "overnight.latest").write_text(str(final_report.relative_to(ROOT)) + "\n")
    print(json.dumps({"state": report["state"], "report": str(final_report.relative_to(ROOT)),
                      "primary_workloads": sorted(primary),
                      "failures": len(report["failures"])}, indent=2), flush=True)
    return 0 if summary.returncode == 0 else 1


if __name__ == "__main__":
    raise SystemExit(main())
