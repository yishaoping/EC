#!/usr/bin/env python3
"""Finish the two existing candidates and write results without another session.

Never changes RTL, accepted hardware references, inputs, or validation rules.
The rescue driver gates additional regressions on measured incremental benefit.
"""
import argparse
import csv
import datetime
import hashlib
import io
import json
import math
import os
import subprocess
import sys
import time
import traceback
from pathlib import Path
from seal_candidate import ROOT, OUT

PERF = Path("/data1/gzh/EC-opt4-recovery-perf/slowdown/recovery_perf_20261104")
FIRST = PERF / "build/overlap_checker_icache4k_20261104_021411_630679e4_measurement_714cdc/status.json"
PARENT = Path("/data1/gzh/EC-opt4-recovery-perf/slowdown/parsec_evaluation_20261103/runs/canneal_project400_correction_20261104_034748_9af23859")
BUILD = "overlap_svb_rescue_r2_20261104_042210_dc665532"


def read(path):
    try:
        return json.loads(Path(path).read_text())
    except (FileNotFoundError, json.JSONDecodeError):
        return {}


def atomic(path, content):
    temporary = path.with_name(path.name + ".tmp")
    temporary.write_text(content)
    temporary.replace(path)


def alive(pid):
    try:
        os.kill(int(pid), 0)
        return True
    except (OSError, TypeError, ValueError):
        return False


def terminal(state):
    value = state.get("state", "")
    return ("FAILED" in value or "TIMEOUT" in value or "COMPLETE" in value
            or value.startswith(("REJECTED", "SUPERSEDED")) or not alive(state.get("pid")))


def comparison(state):
    suite = state.get("regressions", {}).get("suite")
    return read(Path(suite) / "comparison.json") if suite else {}


def report(state):
    first, rescue = state["candidate_one"], state["candidate_two"]
    comparisons = {"ICache 4 KiB": comparison(first), "ICache + SVB rescue": comparison(rescue)}
    base = read(OUT / "baseline/consistency.json")
    names = ["blackscholes_project64", "streamcluster_project64", "canneal_project400"]
    rows, candidates = [], {}
    for label, measured in comparisons.items():
        for name in names:
            frozen = base[name]["roi_cycles"]
            row = measured.get("benchmarks", {}).get(name, {})
            cycles = row.get("candidate_correction_cycles")
            # The representative Canneal is valid even if a whole candidate
            # is rejected, but must not imply that its other regressions ran.
            if label == "ICache + SVB rescue" and name == "canneal_project400" and cycles is None:
                cycles = rescue.get("canneal", {}).get("ROI_cycles")
            rows.append({"candidate": label, "benchmark": name,
                         "native_cycles": frozen["native"], "check_cycles": frozen["check"],
                         "frozen_correction_cycles": frozen["correction"], "candidate_cycles": cycles,
                         "frozen_correction_check": frozen["correction"] / frozen["check"],
                         "candidate_correction_check": cycles / frozen["check"] if cycles else None,
                         "ROI_reduction": 1 - cycles / frozen["correction"] if cycles else None})
        if measured.get("status") == "PASS":
            ratios = [r["candidate_cycles"] / r["frozen_correction_cycles"]
                      for r in rows if r["candidate"] == label and r["candidate_cycles"]]
            bfs = measured.get("bfs", {})
            if len(ratios) == 3 and bfs:
                bfs_ratio = 1 - bfs["relative_ROI_reduction"]
                gain = 1 - math.prod(ratios) ** (1/3)
                candidates[label] = {
                    "three_PARSEC_geomean_ROI_reduction": gain,
                    "maximum_PARSEC_regression": max(ratios) - 1,
                    "BFS_ROI_reduction": bfs["relative_ROI_reduction"],
                    "passes_performance_balance_gate": gain > 0 and max(ratios + [bfs_ratio]) <= 1.02,
                    "hardware_commit": measured["revision"]["canonical_hardware_commit"],
                    "scope": "Performance recommendation only; no accepted hardware reference is changed"}
    eligible = {k: v for k, v in candidates.items() if v["passes_performance_balance_gate"]}
    recommendation = max(eligible, key=lambda k: eligible[k]["three_PARSEC_geomean_ROI_reduction"]) if eligible else "Frozen baseline (candidate validation or balance gate pending/failed)"
    state.update(comparison_rows=rows, performance_candidates=candidates,
                 performance_recommendation=recommendation,
                 comparison_artifacts={label: value.get("suite") for label, value in comparisons.items()})
    lines = ["# Recovery performance evaluation", "",
             "Updated UTC: " + datetime.datetime.now(datetime.timezone.utc).isoformat(), "",
             "State: **" + state["state"] + "**. This report is updated by the detached evaluation driver.", "",
             "Frozen hardware: `a6e63c75947739dfbb411b32bfe0eb5ed55c5bb1`, immutable reference `opt4-recovery-perf-baseline-20261104`.",
             "Four checker cores throughout. All performance numbers below are target application ROI cycles.", "",
             "## Fixed inputs", "",
             "| Candidate | Benchmark | Native | Check | Frozen correction | Candidate correction | Frozen Corr/Check | Candidate Corr/Check | ROI reduction |",
             "|---|---|---:|---:|---:|---:|---:|---:|---:|"]
    for row in rows:
        values = [row["candidate"], row["benchmark"], *[f"{row[k]:,}" for k in ("native_cycles", "check_cycles", "frozen_correction_cycles")],
                  f"{row['candidate_cycles']:,}" if row["candidate_cycles"] else "N/A",
                  f"{row['frozen_correction_check']:.6f}",
                  f"{row['candidate_correction_check']:.6f}" if row["candidate_correction_check"] else "N/A",
                  f"{100*row['ROI_reduction']:.3f}%" if row["ROI_reduction"] is not None else "N/A"]
        lines.append("| " + " | ".join(values) + " |")
    lines += ["", "BFS uses its independently pinned native-normalized reference: native 1,001,675; frozen correction 1,128,052 (1.126166×).", ""]
    for label, measured in comparisons.items():
        bfs = measured.get("bfs", {})
        if bfs:
            result = bfs["result"]
            lines.append(f"- {label}: BFS {result['ROI_cycles']:,} cycles; Correction/Native {bfs['candidate_correction_native']:.6f}×; ROI reduction {100*bfs['relative_ROI_reduction']:.3f}%.")
        else:
            lines.append("- " + label + ": BFS N/A (no completed validated comparison yet).")
    lines += ["", "Performance recommendation: **" + recommendation + "**.",
              "Selection requires all fixed-input validations, a positive PARSEC geometric-mean gain, and no individual PARSEC/BFS regression above 2%. This performance filter does not replace recovery validation.", ""]
    for label, value in candidates.items():
        lines.append(f"- {label}: measured hardware `{value['hardware_commit']}`; PARSEC geometric-mean cycle reduction {100*value['three_PARSEC_geomean_ROI_reduction']:.3f}%.")
    lines += ["", "## Controller validation and measured mechanisms", "",
              "The old rescue RTL fails the persistent-cancellation test; r2 passes 10 cases / 353 checks. Its admission cone passes 20,025 vectors, and the emitted epoch cone passes 73 cases / 2,818 ownership checks.",
              "The initially failed epoch wrapper only omitted a private copy of its C++ driver. The corrected wrapper passes; original failure logs remain. No second-candidate system simulation ran before that failure.", "",
              "Canneal's frozen complete trace exposes 97,796 unsafe-wait cycles in 15 full-SVB fallback episodes that later gain space. This is an opportunity bound, not achieved savings. Rescue preserves the frozen identity and uses the existing durable capture/lease path (`dcache.scala:2007`, qualification/cancellation `:2448`).",
              "Set freezing blocks LSU ingress (`dcache.scala:849`, `:876`); safe-watermark/ACK waiting prolongs the freeze. Canneal's refined wait split measures 116,989 not-yet-formed-result cycles, 1,054 formed-result/cleanup/transport cycles, and 17 watermark-propagation cycles. These observed waits overlap other gates and are not an additive slowdown attribution.",
              "The ICache candidate changes checker nWays 1 to 2 (`rocket-chip/src/main/scala/subsystem/Configs.scala:259`), adding 8 KiB data RAM across four checkers plus tags. Area and timing are not signed off.", "",
              "### Complete Streamcluster simdev pilot (separate input)", "",
              "1,452,774 → 1,420,838 ROI cycles (2.1983% reduction); unchanged 1,094,668 retired application instructions and output. All 525/510 timing-dependent packages have complete checker-work evidence and accepted PASS results.", "",
              "| Sampled mechanism | Frozen | ICache candidate | Difference |", "|---|---:|---:|---:|"]
    pilot_before = read(OUT / "baseline/streamcluster_simdev_full_profile.json")
    pilot_after = read(OUT / "candidates/checker_icache4k_full_pilot.json")
    before_groups = pilot_before.get("stall_profile", {}).get("groups", {})
    after_groups = pilot_after.get("stall_profile", {}).get("groups", {})
    metrics = [("52", "no_commit_ic"), ("52", "no_commit_rob_nonempty"), ("52", "no_commit_rob_empty"),
               ("53", "freeze_set_ingress_block"), ("53", "legacy_preservation_pending"),
               ("53", "release_ack_pending"), ("53", "mshr_admission_block"),
               ("54", "refill_beats"), ("54", "svb_full_cycles")]
    for group, key in metrics:
        b = before_groups.get(group, {}).get("counts", {}).get(key)
        a = after_groups.get(group, {}).get("counts", {}).get(key)
        if b is not None and a is not None:
            lines.append(f"| {key} | {b:,} | {a:,} | {a-b:+,} |")
    lines += ["", "SC52 retirement categories are exclusive and conserve sampled cycles. Cache/ACK exposures overlap. Pilot sampled intervals cover 1,451,008 / 1,420,288 cycles, with 1,766 / 550 ROI boundary cycles unmeasured. They are not the fixed project64 input. Check has no matching new SC52/53 counters: N/A.",
              "Full before/after physical miss/refill/eviction counts, SVB occupancy/reclamation, ACK counters, checker-local partitions and available main-core sampled stalls are retained in each suite's `comparison.json`. Their recorded traffic windows may include preparation and differ from the application ROI; no shadow-cache predictions are used.", "",
              "## Main-input mechanism tables", "",
              "N/A means the corresponding observation is unavailable, not zero. SC52 counts are an exclusive sampled retirement partition; SC53 exposures overlap. Physical cache counters and peak SVB occupancy use each run's recorded traffic window. Checker-local starvation covers the captured ROI packages, which may be incomplete for frozen traces."]
    selected = comparisons.get(recommendation) or next((value for value in comparisons.values()
                                                       if value.get("benchmarks")), {})
    if selected:
        lines += ["", "Mechanism data use measured hardware `" + selected["revision"]["canonical_hardware_commit"] + "`; a rejected performance candidate is still reported when the frozen baseline is recommended."]
    for name in names:
        row = selected.get("benchmarks", {}).get(name, {})
        before = row.get("before_counters", {})
        after = row.get("after_counters", {})
        groups = row.get("stall_profile", {}).get("groups", {})
        def observed(kind, key):
            return groups.get(str(kind), {}).get("counts", {}).get(key)
        def physical(counters, level, key):
            values = [m for m in counters.get("physical_cache_traffic", []) if m["level"] == level]
            return values[0].get("actual", {}).get(key) if values else None
        frozen = base[name]["roi_cycles"]
        instructions = base[name]["roi_instructions"]
        cycles = row.get("candidate_correction_cycles")
        observations = [
            ("Application ROI cycles", frozen["check"], frozen["correction"], cycles),
            ("Application retired instructions", instructions, instructions, instructions if cycles else None),
            ("Main-core IPC", instructions/frozen["check"], instructions/frozen["correction"], instructions/cycles if cycles else None),
            ("SC52 no-commit GH/RSU/IC primary gates", None, None,
             sum(observed(52, k) for k in ["no_commit_gh", "no_commit_rsu", "no_commit_ic"])
             if observed(52, "no_commit_ic") is not None else None),
            ("SC53 legacy preservation pending (overlap)", None, None, observed(53, "legacy_preservation_pending")),
            ("SC53 freeze-set ingress (overlap)", None, None, observed(53, "freeze_set_ingress_block")),
            ("SC53 victim nack exposure", None, None, observed(53, "victim_nack")),
            ("SC53 MSHR admission blocked", None, None, observed(53, "mshr_admission_block")),
            ("SC53 release/ACK outstanding (overlap)", None, None, observed(53, "release_ack_pending")),
            ("Physical L1 misses, traffic window", None, physical(before, 1, "miss"), physical(after, 1, "miss")),
            ("Physical L2 misses, traffic window", None, physical(before, 2, "miss"), physical(after, 2, "miss")),
            ("Physical L1 replacements, traffic window", None, physical(before, 1, "replacement"), physical(after, 1, "replacement")),
            ("SC54 refill beats", None, None, observed(54, "refill_beats")),
            ("SVB peak occupied entries, traffic window", None, (before.get("SVB_occupancy") or {}).get("max_occupancy"), (after.get("SVB_occupancy") or {}).get("max_occupancy")),
            ("Captured checker-local instruction starvation", None, (before.get("checker_ROI_local_partition") or {}).get("instruction_starvation"), (after.get("checker_ROI_local_partition") or {}).get("instruction_starvation")),
            ("Result queue stall cycles", None, None, None)]
        def display(value):
            return "N/A" if value is None else f"{value:.6f}" if isinstance(value, float) else f"{value:,}"
        lines += ["", "### " + name, "", "| Mechanism | Check | Frozen correction | Selected candidate | Candidate − frozen |", "|---|---:|---:|---:|---:|"]
        for label, check, previous, current in observations:
            delta = current-previous if current is not None and previous is not None else None
            lines.append("| " + " | ".join([label, *map(display, [check, previous, current, delta])]) + " |")
    lines += ["",
              "## Measurement and correctness boundaries", "",
              "Earlier Blackscholes 1.12142 used test4/100 rounds, 220,637 retired instructions and a STOP-inclusive ROI. The frozen 1.035765 uses project64/100 rounds, 3,562,647 instructions and the application-only ROI, on the corrected epoch/owner hardware. These are incompatible experiments.",
              "The fixed Native/Check/Correction triplets have matching application inputs, output, ROI work and ISA/cache/clocks. Native changes the mode word. Check uses fetch4 and Correction fetch8, so Corr/Check is the net design ratio. Detection's equivalent internal sequenced-coverage evidence is unavailable.",
              "Candidate acceptance checks output, ELF, retired instructions, complete per-package re-execution intervals, PASS/FAIL/CANCELLED, snapshot/integrity ordering and release/ACK ledgers. Complete no-fault execution does not prove architectural fault recovery.",
              "The actual emitted SVB has directed persistent-data, same-line-version, rollback-invalidation, held-promotion, delayed-ACK-across-flush/epoch and wrong-key/entry ACK rejection tests. Its bytes and the WB module must match those already tested before rescue simulation. These unit/cone tests do not prove full architectural register rollback or every SPEC-version flush scenario. No watermark, ACK, retention rule, checker count, application semantics or assertion is weakened.", "",
              "## Job states and artifacts", "",
              "- Candidate 1: `" + first.get("state", "UNKNOWN") + "`; status `" + str(FIRST) + "`.",
              "- Candidate 2: `" + rescue.get("state", "NOT_STARTED") + "`; status `" + str(state.get("rescue_status_path", "N/A")) + "`.",
              "- Detached driver: `" + str(state["driver_directory"]) + "`.",
              "- Source history, frozen measurements and rejected/unfavorable windows: `EXPERIMENTS.md` and `baseline/`.",
              "- This work stays on isolated recovery branches; frozen evaluation, check and FPGA implementations are untouched."]
    if rescue.get("incremental_over_icache_candidate"):
        lines += ["", "Rescue incremental result: `" + json.dumps(rescue["incremental_over_icache_candidate"]) + "`."]
    if state.get("errors"):
        lines += ["", "Failures retained for follow-up:", ""] + ["- " + value for value in state["errors"]]
    atomic(OUT / "RESULTS.md", "\n".join(lines) + "\n")
    output = io.StringIO()
    writer = csv.DictWriter(output, fieldnames=list(rows[0]))
    writer.writeheader()
    writer.writerows(rows)
    atomic(OUT / "FINAL_COMPARISON.csv", output.getvalue())
    atomic(OUT / "FINAL_STATUS.json", json.dumps(state, indent=2) + "\n")


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--report-only", action="store_true")
    args = parser.parse_args()
    directory = OUT / "runs" / ("finish_" + datetime.datetime.now(datetime.timezone.utc).strftime("%Y%m%d_%H%M%S_%f"))
    directory.mkdir(parents=True, exist_ok=False)
    state = {"state": "RUNNING", "pid": os.getpid(), "driver_directory": str(directory),
             "runner_sha256": hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), "errors": []}
    if args.report_only:
        state.update(state="PENDING", candidate_one=read(FIRST), candidate_two={})
        report(state)
        return 0
    log = directory / "rescue_driver.log"
    with log.open("xb") as stream:
        process = subprocess.Popen([sys.executable, "-u", str(OUT / "scripts/measure_rescue.py"), BUILD,
                                    "--parent-canneal", str(PARENT)], cwd=ROOT, stdout=stream, stderr=subprocess.STDOUT)
    state["rescue_pid"] = process.pid
    print("DRIVER_DIRECTORY=" + str(directory), flush=True)
    deadline = time.monotonic() + 10 * 3600
    while True:
        state["candidate_one"] = read(FIRST)
        for path in (OUT / "build").glob(BUILD + "_measurement_*/status.json"):
            value = read(path)
            if value.get("pid") == process.pid:
                state["candidate_two"] = value
                state["rescue_status_path"] = str(path)
                break
        state.setdefault("candidate_two", {})
        rc = process.poll()
        if rc is not None and rc != 0:
            message = "Rescue driver failed (exit " + str(rc) + "); see " + str(log)
            if message not in state["errors"]:
                state["errors"].append(message)
        done = bool(state["candidate_one"]) and terminal(state["candidate_one"]) and rc is not None
        if done:
            first_ok = state["candidate_one"].get("state") == "VALIDATED_MEASUREMENT_COMPLETE"
            state["state"] = "COMPLETE" if first_ok and rc == 0 else "COMPLETE_WITH_FAILURES"
            if not first_ok:
                state["errors"].append("Candidate-1 evaluation did not complete successfully; see " + str(FIRST))
        if time.monotonic() >= deadline and not done:
            state["state"] = "WATCH_TIMEOUT_JOBS_NOT_TERMINATED"
            state["errors"].append("Ten-hour report wait expired; existing build/simulation processes are left intact.")
        report(state)
        atomic(directory / "status.json", json.dumps(state, indent=2) + "\n")
        if done or time.monotonic() >= deadline:
            print(json.dumps({"state": state["state"], "report": str(OUT / "RESULTS.md"), "errors": state["errors"]}), flush=True)
            return int(state["state"] != "COMPLETE")
        time.sleep(60)


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except Exception:
        state = read(OUT / "FINAL_STATUS.json")
        state.update(state="REPORT_DRIVER_FAILED", driver_traceback=traceback.format_exc())
        atomic(OUT / "FINAL_STATUS.json", json.dumps(state, indent=2) + "\n")
        raise
