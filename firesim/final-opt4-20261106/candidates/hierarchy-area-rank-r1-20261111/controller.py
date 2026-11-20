#!/usr/bin/python3
"""Rank inclusive and directly owned resources from the preserved post-opt map."""
from pathlib import Path
import datetime as dt
import hashlib
import json
import os

W = Path("/data1/gzh/EC/firesim/final-opt4-20261106")
D = Path("/data1/gzh/EC/Experiment/firesim-final-opt4-20261106")
U = D / "unattended-opt4"
POLICY = U / "campaign-policy.json"
PRIOR_STATE = D / "Opt4-fit-cad-state.json"
REPORT = D / "build-logs/Opt4-fit-cad-8da24a26/top-postopt-hierarchical.rpt"
OUT = D / "build-logs/Opt4-fit-hierarchy-analysis-r1-20261111"
STATE = D / "Opt4-fit-hierarchy-analysis-r1-state.json"
EXPECTED_FROZEN = "8491167d84b6d9521b151a743673c1516926a1f8"
EXPECTED_REPORT_COMMIT = "8da24a269b98a0d6a8f57b030353a310812c4344"


def sha(path):
    h = hashlib.sha256()
    with Path(path).open("rb") as source:
        for block in iter(lambda: source.read(1 << 20), b""):
            h.update(block)
    return h.hexdigest()


def read(path):
    return json.loads(Path(path).read_text())


def save(path, value):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_name(path.name + ".tmp-" + str(os.getpid()))
    with temporary.open("w") as target:
        json.dump(value, target, indent=2, sort_keys=True)
        target.write("\n")
        target.flush()
        os.fsync(target.fileno())
    os.replace(temporary, path)


def parse_report(path):
    names = [
        "total_luts",
        "logic_luts",
        "lutrams",
        "srls",
        "ffs",
        "ramb36",
        "ramb18",
        "uram",
        "dsp",
    ]
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
        rows.append(
            {
                "indent": len(raw_instance) - len(raw_instance.lstrip()),
                "instance": raw_instance.strip(),
                "module": fields[2].strip(),
                **dict(zip(names, resources)),
                "children": [],
            }
        )
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
            if row["parent_path"]
            else row["instance"]
        )
        stack.append(row)

    for row in reversed(rows):
        row["owned"] = {
            name: row[name] - sum(child[name] for child in row["children"])
            for name in names
        }
        assert all(value >= 0 for value in row["owned"].values()), row["path"]
    return rows


def compact(row):
    return {
        "path": row["path"],
        "module": row["module"],
        "inclusive": {name: row[name] for name in row["owned"]},
        "owned": row["owned"],
    }


def main():
    policy = read(POLICY)
    assert policy["functional_baseline_commit"] == EXPECTED_FROZEN
    assert policy["area_equivalence_only"] is True
    assert policy["functional_extensions_allowed"] is False
    assert policy["current_live_whole_commit"] == "9ae9a7fcf231a75259e23973b12a93896a443cbb"
    prior = read(PRIOR_STATE)
    assert prior["hardware_commit"] == EXPECTED_REPORT_COMMIT
    assert prior["status"] == "NOT_FIT_POSTOPT"
    assert prior["top_postopt_resources"]["CLB LUTs"]["used"] == 3215683
    assert REPORT.is_file() and not OUT.exists() and not STATE.exists()

    rows = parse_report(REPORT)
    root_indent = min(row["indent"] for row in rows)
    top = next(row for row in rows if row["indent"] == root_indent)
    assert top["total_luts"] == prior["top_postopt_resources"]["CLB LUTs"]["used"]

    selected_modules = {
        "PackageAddressStats",
        "BoomMSHRFile",
        "BoomMSHR",
        "SpeculativeVersionBuffer",
        "BoomNonBlockingDCache",
        "InclusiveCache",
        "Scheduler",
        "GHBarrierLatencyStats",
    }
    selected = [
        compact(row)
        for row in rows
        if row["module"] in selected_modules
    ]
    owned_rank = sorted(
        (row for row in rows if row["owned"]["total_luts"] >= 10000),
        key=lambda row: row["owned"]["total_luts"],
        reverse=True,
    )
    receipt = {
        "schema": "ec-opt4-inclusive-hierarchy-ranking/1",
        "status": "PASS_NON_OVERLAPPING_POSTOPT_HIERARCHY_RANKING",
        "scope": "Historical 8da24a26 post-opt report only; not the live 9ae build or a FIT claim.",
        "frozen_baseline_commit": EXPECTED_FROZEN,
        "report_commit": EXPECTED_REPORT_COMMIT,
        "live_whole_commit": policy["current_live_whole_commit"],
        "report": str(REPORT),
        "report_sha256": sha(REPORT),
        "prior_state_sha256": sha(PRIOR_STATE),
        "policy_sha256": sha(POLICY),
        "top": compact(top),
        "selected_modules": selected,
        "largest_non_overlapping_owned_nodes": [
            compact(row) for row in owned_rank[:50]
        ],
        "interpretation": [
            "Inclusive parent rows contain their child rows and must not be summed.",
            "Owned resources subtract direct child inclusive resources; the resulting ranking avoids hierarchy double counting.",
            "Address statistics remain the largest owned block in the historical design; MSHR, SVB, writeback, probe, barrier-stat, and L2 descendants are separate optimization targets.",
            "All instrumentation and event behavior remain in scope and must be preserved by any candidate.",
        ],
    }
    OUT.mkdir(parents=True)
    save(OUT / "result.json", receipt)
    state = {
        "schema": "ec-opt4-analysis-state/1",
        "status": receipt["status"],
        "hardware_commit": EXPECTED_REPORT_COMMIT,
        "frozen_baseline_commit": EXPECTED_FROZEN,
        "policy_sha256": receipt["policy_sha256"],
        "report_sha256": receipt["report_sha256"],
        "result": str(OUT / "result.json"),
        "result_sha256": sha(OUT / "result.json"),
        "ended_utc": dt.datetime.now(dt.timezone.utc).isoformat(),
    }
    save(STATE, state)


if __name__ == "__main__":
    main()
