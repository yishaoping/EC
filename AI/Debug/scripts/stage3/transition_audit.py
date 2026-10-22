#!/usr/bin/env python3
"""Static source-table expansion for the Stage3 fixture; never elaborates RTL.

NORMAL, FLUSH_COMMIT, EVICT and BYPASS are distinct assertion domains.
This checks table completeness and reviewed fixture path membership, not
reachability, temporal correctness, compilation or dynamic CASE completion.
"""

import argparse
import ast
import hashlib
import json
from pathlib import Path
import re


CONFIG = dict(p=False, c=True, m=True, r=False, f=True, b=False)
SOURCE = Path("chipyard/generators/sifive-cache/design/craft/inclusivecache/src/MSHR.scala")
FIXTURE = Path("AI/Debug/scripts/stage3/stage3_test.cpp")
S = "S_"
# Manually reviewed transaction families; names below must match the CASE inventory.
# Miss coverage is INVALID, independently of a non-INVALID replacement victim.
FAMILIES = {
    "same_line": [("INVALID", "TRUNK_C"), ("TRUNK_C", "TIP_D"),
                  ("TIP_D", "TRUNK_CD"), ("TRUNK_CD", "TIP_D"), ("INVALID", "TIP")],
    "aba": [("INVALID", "TRUNK_C"), ("TRUNK_C", "TIP_D"),
            ("TIP_D", "TRUNK_CD"), ("TRUNK_CD", "TIP_D")],
    "trusted": [("INVALID", "TRUNK_C"), ("TRUNK_C", "TIP_D"), ("TIP_D", "TIP_D"),
                ("TIP_D", "TRUNK_CD"), ("TRUNK_CD", "TIP_D")],
    "dirty_victim": [("INVALID", "TIP"), ("TIP", "TRUNK_C"),
                     ("TRUNK_C", "TIP_D"), ("INVALID", "TRUNK_C"), ("TRUNK_C", "TIP")],
    "clean_victim": [("INVALID", "TIP"), ("INVALID", "TRUNK_C"), ("TRUNK_C", "TIP")],
    "flush": [("INVALID", "TRUNK_C"), ("TRUNK_C", "TIP_D")],
    "probe": [("INVALID", "TRUNK_C"), ("TRUNK_C", "TIP_D"),
              ("TIP_D", "TRUNK_CD"), ("TRUNK_CD", "TIP_CD"), ("TIP_CD", "TIP_D")],
    # Early park has no commit; late park publishes completed Probe downgrades
    # without adding the requester. Replay is a fresh ordinary lookup/plan.
    "client_wait": [("INVALID", "TRUNK_C"), ("TRUNK_C", "TIP_D"),
                    ("TIP_D", "TRUNK_CD"), ("TRUNK_CD", "TIP_D"),
                    ("TRUNK_CD", "TIP_CD"), ("TIP_CD", "TIP_D")],
}
CASES = {
    "same_line_safe_dirty_wait_ack": "same_line",
    "outer_backpressure_exactly_once": "same_line",
    "delayed_ack_freezes_predecessor": "same_line",
    "pending_same_line_request": "same_line",
    "pending_replacement_pressure": "same_line",
    "validation_and_ack_same_cycle": "same_line",
    "duplicate_ack_ignored": "same_line",
    "full_provenance_collision": "aba",
    "stale_ack_ignored": "aba",
    "repeated_speculative_same_line": "aba",
    "same_line_already_outer_preserved": "trusted",
    "speculative_set_victim_blocks_outer": "dirty_victim",
    "same_set_different_line_replacement": "dirty_victim",
    "safe_dirty_set_victim_wait_ack": "dirty_victim",
    "validated_victim_preserve_ack_replace": "dirty_victim",
    "safe_clean_victim_no_write": "clean_victim",
    "flush_clear_normal_writeback_barrier": "flush",
    "validation_and_refill_replacement_same_cycle": "probe",
    "lineage_unaware_peer_waits_validation": "client_wait",
}


def require(condition, message):
    if not condition:
        raise ValueError(message)


def condition_value(expression):
    # Only booleans, cfg names, && and ||; no eval / Scala execution.
    expression = re.sub(r"\btrue\b", "True", expression)
    expression = re.sub(r"\bfalse\b", "False", expression)
    tree = ast.parse(expression.replace("&&", " and ").replace("||", " or "), mode="eval")

    def visit(node):
        if isinstance(node, ast.Expression):
            return visit(node.body)
        if isinstance(node, ast.Constant) and type(node.value) is bool:
            return node.value
        if isinstance(node, ast.Name) and node.id in CONFIG:
            return CONFIG[node.id]
        if isinstance(node, ast.BoolOp) and isinstance(node.op, (ast.And, ast.Or)):
            values = [visit(v) for v in node.values]
            return all(values) if isinstance(node.op, ast.And) else any(values)
        raise ValueError(f"Unsupported table condition: {expression}")

    return visit(tree)


def table(source, name, arity):
    args = r"(S_\w+),\s*(S_\w+),\s*([^\n)]+)" if arity == 3 else r"(S_\w+),\s*([^\n)]+)"
    return re.findall(r"^\s*" + name + r"\(" + args + r"\)", source, re.M)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path(__file__).resolve().parents[4])
    parser.add_argument("--baseline", type=Path, help="Saved same-run MSHR.scala for table equality")
    parser.add_argument("--output", type=Path, required=True, help="JSON artifact; outside immutable runs")
    parser.add_argument("--markdown", type=Path, help="Readable full matrix artifact")
    args = parser.parse_args()
    text = (args.root / SOURCE).read_text()
    harness = (args.root / FIXTURE).read_text()
    states = re.findall(r"^case object (S_\w+)\s+extends CacheState", text, re.M)
    require(len(states) == 9 and len(set(states)) == 9, "Expected all 9 coverage states")
    rows = table(text, "transition", 3)
    pairs = {(a, b): expr.strip() for a, b, expr in rows}
    require(len(rows) == len(pairs) == 72, "Duplicate/missing ordinary table rows")
    require(set(pairs) == {(a, b) for a in states for b in states if a != b}, "Incomplete 9x9 table")
    baseline_equal = None
    if args.baseline:
        old = args.baseline.read_text()
        baseline_equal = rows == table(old, "transition", 3)
        require(baseline_equal, "Ordinary transition capability conditions changed")
        # Also keep the original assertion helper, not just its table calls.
        body = lambda s: s.split("  def transition(", 1)[1].split("\n  }", 1)[0]
        require(body(text) == body(old), "Ordinary assertion helper changed")
    normal_allowed = [(a, b) for (a, b), expr in pairs.items() if condition_value(expr)]
    normal_forbidden = [(a, b) for (a, b), expr in pairs.items() if not condition_value(expr)]
    domain_states = {}
    for name, count in (("eviction", 8), ("bypass", 9), ("flushCommit", 9)):
        entries = table(text, name, 2)
        require(len(entries) == count and len(dict(entries)) == count, f"Incomplete {name} domain")
        domain_states[name] = [s for s, expr in entries if condition_value(expr) and (name != "flushCommit" or CONFIG["f"])]
    require(set(domain_states["eviction"]) == set(domain_states["flushCommit"]), "Evict/flush capability mismatch")
    flush_edges = [(s, "S_INVALID") for s in domain_states["flushCommit"]]
    collisions = [pair for pair in flush_edges if pair in normal_forbidden]
    require(len(collisions) == 6, "Re-evaluate configured flush/ordinary table mismatch")
    for guard in (
        "io.schedule.ready && request.control", "io.schedule.ready && !request.control",
        "releaseIssued && releaseSent && w_releaseack", "request_valid && meta_valid && meta.hit",
        "!final_meta_writeback.clients.orR", "final_meta_writeback.image.asUInt === UInt(0)",
    ):
        require(guard in text, f"Missing reviewed commit guard: {guard}")
    cases = re.findall(r'r\.pass\("([^"]+)"\)', harness)
    require(len(cases) == len(CASES) and set(cases) == set(CASES), "CASE mapping drift/duplicate")
    family_edges = {name: [(S + a, S + b) for a, b in edges] for name, edges in FAMILIES.items()}
    for name, edges in family_edges.items():
        for a, b in edges:
            require(a == b or (a, b) in normal_allowed, f"Reviewed {name} path forbidden: {a}->{b}")
    digest = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
    result = dict(
        kind="STATIC_SOURCE_TABLE_AUDIT_NOT_SIMULATION", config=CONFIG, states=states,
        source_sha256=digest(args.root / SOURCE), fixture_sha256=digest(args.root / FIXTURE),
        ordinary_table_unchanged=baseline_equal, ordinary_allowed=normal_allowed,
        ordinary_forbidden=normal_forbidden, implicit_self_pairs=[(s, s) for s in states],
        self_pair_semantics="No original transition() check, not an independently proven transition",
        event_domains=domain_states, flush_edges=flush_edges, old_flush_domain_collisions=collisions,
        reviewed_family_edges=family_edges, cases=CASES,
        limits="CASE families are manually reviewed overapproximations, not a control-flow proof. Temporal gates and cleanup require source review; no dynamic PASS is implied.",
        CURRENT_CONFIG_TRANSITION_AUDIT="PASS",
    )
    args.output.write_text(json.dumps(result, indent=2) + "\n")
    if args.markdown:
        lines = ["# Stage3 configured assertion matrix", "", "Static source expansion: `(p,c,m,r,f)=(false,true,true,false,true)`, `b=false`.", "",
                 "N = ordinary table allows; F = ordinary table forbids; · = implicit self (not checked by the original table).",
                 "Flush commits use the separate strict terminal proof. Matrix includes unreachable BRANCH states.", "",
                 "| before / after | " + " | ".join(s[2:] for s in states) + " |",
                 "|---|" + "---|" * len(states)]
        for a in states:
            lines.append("| " + a[2:] + " | " + " | ".join("·" if a == b else "N" if (a, b) in normal_allowed else "F" for b in states) + " |")
        lines += ["", f"Ordinary: {len(normal_allowed)} allowed, {len(normal_forbidden)} forbidden, 9 implicit self pairs.", "",
                  "Strict FLUSH_COMMIT allowed edges (each requires issued+sent+matching ACK, cleared metadata/provenance):", ""]
        lines += [f"- `{a} -> {b}`" for a, b in flush_edges]
        lines += ["", "BRANCH/BRANCH_C cannot originate in this configuration. Replacement has a separate EVICT event; a tag miss remains INVALID in the ordinary matrix.", "",
                  "This artifact is not RTL generation, simulation or a proof that all table-allowed paths are reachable."]
        args.markdown.write_text("\n".join(lines) + "\n")
    print(f"CURRENT_CONFIG_TRANSITION_AUDIT=PASS ordinary_allowed={len(normal_allowed)} ordinary_forbidden={len(normal_forbidden)} flush_domains={len(flush_edges)} cases={len(cases)}")


if __name__ == "__main__":
    main()
