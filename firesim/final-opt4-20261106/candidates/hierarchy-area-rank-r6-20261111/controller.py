#!/usr/bin/python3
"""Correct module-name categorization over the preserved r5 hierarchy parse."""
from pathlib import Path
import datetime as dt
import runpy

ROOT = Path("/data1/gzh/EC")
D = ROOT / "Experiment/firesim-final-opt4-20261106"
U = D / "unattended-opt4"
CANDIDATE = ROOT / "firesim/final-opt4-20261106/candidates"
PARSER = CANDIDATE / "hierarchy-area-rank-r5-20261111/controller.py"
PRIOR_PARSER = CANDIDATE / "hierarchy-area-rank-r1-20261111/controller.py"
EVIDENCE = CANDIDATE / "hierarchy-area-rank-r4-20261111/evidence"
REPORT = EVIDENCE / "top-postopt-hierarchical.rpt"
PRIOR_STATE = EVIDENCE / "cad-state.json"
OUT = D / "build-logs/Opt4-fit-hierarchy-analysis-r6-20261111"
STATE = D / "Opt4-fit-hierarchy-analysis-r6-state.json"
PARSER_NS = runpy.run_path(str(PARSER), run_name="ec_opt4_hierarchy_rank_r5")
IO = PARSER_NS["NAMESPACE"]
NAMES = PARSER_NS["NAMES"]


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
    policy = IO["read"](policy_path)
    frozen = "8491167d84b6d9521b151a743673c1516926a1f8"
    report_commit = "8da24a269b98a0d6a8f57b030353a310812c4344"
    assert policy["functional_baseline_commit"] == frozen
    assert policy["area_equivalence_only"] is True
    assert policy["functional_extensions_allowed"] is False
    assert policy["current_live_whole_commit"] == "9ae9a7fcf231a75259e23973b12a93896a443cbb"
    prior = IO["read"](PRIOR_STATE)
    assert prior["hardware_commit"] == report_commit
    assert prior["status"] == "NOT_FIT_POSTOPT"
    assert not OUT.exists() and not STATE.exists()

    rows, root, overlaps = PARSER_NS["parse_report"](REPORT)
    assert root["total_luts"] == prior["top_postopt_resources"]["CLB LUTs"]["used"]
    partition = {
        name: sum(row["owned"][name] for row in rows)
        for name in NAMES
    }
    assert all(abs(partition[name] - root[name]) < 0.001 for name in NAMES)

    wanted = (
        "PackageAddressStats",
        "BoomMSHRFile",
        "BoomMSHR",
        "SpeculativeVersionBuffer",
        "BoomNonBlockingDCache",
        "InclusiveCache",
        "Scheduler",
        "GHBarrierLatencyStats",
    )
    selected = [
        compact(row)
        for row in rows
        if any(row["module"].endswith("_" + suffix) for suffix in wanted)
    ]
    assert selected, "Vivado-prefixed module categorization returned no rows"
    owned_rank = sorted(
        (row for row in rows if row["owned"]["total_luts"] >= 10000),
        key=lambda row: row["owned"]["total_luts"],
        reverse=True,
    )
    input_files = [Path(__file__), PARSER, PRIOR_PARSER, REPORT, PRIOR_STATE]
    inputs = {str(path): IO["sha"](path) for path in input_files}
    receipt = {
        "schema": "ec-opt4-inclusive-hierarchy-ranking/3",
        "status": "PASS_NONOVERLAPPING_POSTOPT_HIERARCHY_RANKING",
        "scope": "Historical 8da24a26 post-opt report only; not the live 9ae build or a FIT claim.",
        "frozen_baseline_commit": frozen,
        "report_commit": report_commit,
        "live_whole_commit": policy["current_live_whole_commit"],
        "report": str(REPORT),
        "input_sha256": inputs,
        "top": compact(root),
        "owned_resource_partition": partition,
        "overlap_reconciliations": overlaps,
        "overlap_reconciliation_count": len(overlaps),
        "categorized_module_rows": selected,
        "largest_nonoverlapping_owned_nodes": [
            compact(row) for row in owned_rank[:50]
        ],
        "interpretation": [
            "Inclusive hierarchy rows overlap when child attribution exceeds a parent.",
            "Top-down resource allocation proportionally scales child allocations at those nodes; owned component totals exactly partition the top report.",
            "Vivado module prefixes are retained and matched by suffix for categorization.",
            "The allocation is accounting reconciliation, not a new synthesis measurement or candidate area estimate.",
            "All instrumentation and event behavior remain in scope and must be preserved by any candidate.",
        ],
        "ended_utc": dt.datetime.now(dt.timezone.utc).isoformat(),
    }
    OUT.mkdir(parents=True)
    IO["save"](OUT / "result.json", receipt)
    IO["save"](STATE, {
        "schema": "ec-opt4-analysis-state/1",
        "status": receipt["status"],
        "hardware_commit": report_commit,
        "frozen_baseline_commit": frozen,
        "input_sha256": inputs,
        "result": str(OUT / "result.json"),
        "result_sha256": IO["sha"](OUT / "result.json"),
        "ended_utc": receipt["ended_utc"],
    })


if __name__ == "__main__":
    main()
