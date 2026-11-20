#!/usr/bin/python3
"""Partition historical hierarchy resources despite small Xilinx overlaps."""
from pathlib import Path
import datetime as dt
import runpy
import sys

ROOT = Path("/data1/gzh/EC")
D = ROOT / "Experiment/firesim-final-opt4-20261106"
U = D / "unattended-opt4"
CANDIDATE = ROOT / "firesim/final-opt4-20261106/candidates/hierarchy-area-rank-r4-20261111"
BASE = ROOT / "firesim/final-opt4-20261106/candidates/hierarchy-area-rank-r1-20261111/controller.py"
NAMESPACE = runpy.run_path(str(BASE), run_name="ec_opt4_hierarchy_rank_template")
REPORT = CANDIDATE / "evidence/top-postopt-hierarchical.rpt"
PRIOR_STATE = CANDIDATE / "evidence/cad-state.json"
OUT = D / "build-logs/Opt4-fit-hierarchy-analysis-r5-20261111"
STATE = D / "Opt4-fit-hierarchy-analysis-r5-state.json"
NAMES = [
    "total_luts", "logic_luts", "lutrams", "srls", "ffs",
    "ramb36", "ramb18", "uram", "dsp",
]


def parse_report(path):
    rows = []
    for line in path.read_text().splitlines():
        fields = line.split("|")
        if len(fields) < 12:
            continue
        try:
            resources = [
                int(fields[index].strip().replace(",", ""))
                for index in range(3, 12)
            ]
        except ValueError:
            continue
        raw_instance = fields[1]
        rows.append({
            "indent": len(raw_instance) - len(raw_instance.lstrip()),
            "instance": raw_instance.strip(),
            "module": fields[2].strip(),
            **dict(zip(NAMES, resources)),
            "children": [],
        })
    assert rows, "hierarchical utilization table was not parsed"

    stack = []
    for row in rows:
        while stack and stack[-1]["indent"] >= row["indent"]:
            stack.pop()
        if stack:
            stack[-1]["children"].append(row)
        row["parent_path"] = stack[-1]["path"] if stack else ""
        row["path"] = (
            row["parent_path"] + "." + row["instance"]
            if row["parent_path"] else row["instance"]
        )
        stack.append(row)

    overlaps = []

    def allocate(row, inherited):
        child_sums = {
            name: sum(child[name] for child in row["children"])
            for name in NAMES
        }
        raw_delta = {
            name: row[name] - child_sums[name]
            for name in NAMES
        }
        row["raw_owned_delta"] = raw_delta
        row["owned"] = {
            name: max(0, raw_delta[name]) * inherited[name]
            for name in NAMES
        }
        local_scale = {
            name: min(1.0, row[name] / child_sums[name])
            if child_sums[name] else 1.0
            for name in NAMES
        }
        row["allocation_factor"] = inherited
        row["child_allocation_factor"] = {
            name: inherited[name] * local_scale[name]
            for name in NAMES
        }
        for name in NAMES:
            if raw_delta[name] < 0:
                overlaps.append({
                    "path": row["path"],
                    "module": row["module"],
                    "resource": name,
                    "parent_inclusive": row[name],
                    "children_inclusive_sum": child_sums[name],
                    "overlap": -raw_delta[name],
                    "scale": local_scale[name],
                })
        for child in row["children"]:
            allocate(child, row["child_allocation_factor"])

    minimum_indent = min(row["indent"] for row in rows)
    roots = [row for row in rows if row["indent"] == minimum_indent]
    assert len(roots) == 1, ("root-count", len(roots))
    root = roots[0]
    allocate(root, {name: 1.0 for name in NAMES})
    return rows, root, overlaps


def compact(row):
    return {
        "path": row["path"],
        "module": row["module"],
        "inclusive": {name: row[name] for name in NAMES},
        "owned_nonoverlapping": row["owned"],
        "raw_unadjusted_delta": row["raw_owned_delta"],
        "allocation_factor": row["allocation_factor"],
    }


def main():
    policy_path = U / "campaign-policy.json"
    policy = NAMESPACE["read"](policy_path)
    expected_frozen = "8491167d84b6d9521b151a743673c1516926a1f8"
    expected_report_commit = "8da24a269b98a0d6a8f57b030353a310812c4344"
    assert policy["functional_baseline_commit"] == expected_frozen
    assert policy["area_equivalence_only"] is True
    assert policy["functional_extensions_allowed"] is False
    assert policy["current_live_whole_commit"] == "9ae9a7fcf231a75259e23973b12a93896a443cbb"
    prior = NAMESPACE["read"](PRIOR_STATE)
    assert prior["hardware_commit"] == expected_report_commit
    assert prior["status"] == "NOT_FIT_POSTOPT"
    assert prior["top_postopt_resources"]["CLB LUTs"]["used"] == 3215683
    assert REPORT.is_file() and not OUT.exists() and not STATE.exists()

    rows, root, overlaps = parse_report(REPORT)
    assert root["total_luts"] == prior["top_postopt_resources"]["CLB LUTs"]["used"]
    partition = {
        name: sum(row["owned"][name] for row in rows)
        for name in NAMES
    }
    assert all(abs(partition[name] - root[name]) < 0.001 for name in NAMES), partition

    selected_modules = {
        "PackageAddressStats", "BoomMSHRFile", "BoomMSHR",
        "SpeculativeVersionBuffer", "BoomNonBlockingDCache",
        "InclusiveCache", "Scheduler", "GHBarrierLatencyStats",
    }
    selected = [compact(row) for row in rows if row["module"] in selected_modules]
    owned_rank = sorted(
        (row for row in rows if row["owned"]["total_luts"] >= 10000),
        key=lambda row: row["owned"]["total_luts"],
        reverse=True,
    )
    input_files = [
        Path(__file__),
        BASE,
        REPORT,
        PRIOR_STATE,
    ]
    inputs = {str(path): NAMESPACE["sha"](path) for path in input_files}
    receipt = {
        "schema": "ec-opt4-inclusive-hierarchy-ranking/2",
        "status": "PASS_NONOVERLAPPING_POSTOPT_HIERARCHY_RANKING",
        "scope": "Historical 8da24a26 post-opt report only; not the live 9ae build or a FIT claim.",
        "frozen_baseline_commit": expected_frozen,
        "report_commit": expected_report_commit,
        "live_whole_commit": policy["current_live_whole_commit"],
        "report": str(REPORT),
        "input_sha256": inputs,
        "top": compact(root),
        "owned_resource_partition": partition,
        "overlap_reconciliations": overlaps,
        "overlap_reconciliation_count": len(overlaps),
        "selected_modules": selected,
        "largest_nonoverlapping_owned_nodes": [
            compact(row) for row in owned_rank[:50]
        ],
        "interpretation": [
            "Historical inclusive hierarchy rows overlap when child attribution exceeds a parent.",
            "The top-down resource allocation proportionally scales child allocations at those nodes; owned component totals then exactly partition the top report.",
            "The allocation is accounting reconciliation, not a new synthesis measurement or candidate area estimate.",
            "All instrumentation and event behavior remain in scope and must be preserved by any candidate.",
        ],
        "ended_utc": dt.datetime.now(dt.timezone.utc).isoformat(),
    }
    OUT.mkdir(parents=True)
    NAMESPACE["save"](OUT / "result.json", receipt)
    state = {
        "schema": "ec-opt4-analysis-state/1",
        "status": receipt["status"],
        "hardware_commit": expected_report_commit,
        "frozen_baseline_commit": expected_frozen,
        "input_sha256": inputs,
        "result": str(OUT / "result.json"),
        "result_sha256": NAMESPACE["sha"](OUT / "result.json"),
        "ended_utc": receipt["ended_utc"],
    }
    NAMESPACE["save"](STATE, state)


if __name__ == "__main__":
    main()
