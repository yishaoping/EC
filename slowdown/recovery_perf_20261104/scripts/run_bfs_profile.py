#!/usr/bin/env python3
"""Pinned BFS regression with complete per-package checker work evidence."""
import argparse
import hashlib
import json
import sys
from pathlib import Path
from seal_candidate import ROOT

sys.path.insert(0, str(ROOT / "slowdown/parsec_evaluation_20261103/scripts"))
import run_bfs_regression as bfs
from profile_stalls import report


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("revision", type=Path)
    args = parser.parse_args()
    base_router = bfs.compact_capture.Router
    class Router(base_router):
        def __init__(self, directory):
            super().__init__(directory, event_limit=64 * 1024 * 1024)
    bfs.compact_capture.Router = Router
    optional = bfs.compact_capture.optional_event
    bfs.compact_capture.optional_event = lambda k, h: k not in (11, 12) and optional(k, h)
    runs = set()
    original_dump = bfs.dump
    def capture_manifest(path, data):
        if path.name == "run_manifest.json":
            runs.add(path.parent)
        original_dump(path, data)
    bfs.dump = capture_manifest
    sys.argv = ["run_bfs_regression.py", "--hardware-revision", str(args.revision.resolve())]
    rc = bfs.main()
    assert len(runs) == 1
    run = runs.pop()
    if rc:
        return rc
    records = bfs.stable.parse_events(run / "safe_chain_events.tsv")
    accepted = {(r["hart"], r["nums"][0] & 0xffffffff) for r in records if r["kind"] == 3 and r["nums"][1] & 2}
    groups = {}
    for r in records:
        if r["kind"] == 11 and 1 <= r["hart"] <= 4 and r["nums"][0]:
            groups.setdefault((r["hart"], r["nums"][0]), []).append(r)
    closed = {}
    for identity, rows in groups.items():
        rows.sort(key=lambda r: r["time"])
        starts = [r for r in rows if r["nums"][2] & 128 and not r["nums"][3]]
        ends = [r for r in rows if r["nums"][2] & 2]
        if not starts or not ends:
            continue
        first, last = starts[0], ends[-1]
        assert first["time"] <= last["time"] and not any(first["nums"][3:])
        assert last["nums"][3] == sum(last["nums"][4:13])
        assert not any(any(b < a for a, b in zip(x["nums"][3:], y["nums"][3:])) for x, y in zip(rows, rows[1:]))
        closed[identity] = last
    result = {"complete": bool(accepted) and set(closed) == accepted,
              "accepted_packages": len(accepted), "closed_counter_intervals": len(closed),
              "checked_instructions": sum(r["nums"][13] for r in closed.values()),
              "scope": "full protected session, not hart0 rdinstret",
              "runner_sha256": hashlib.sha256(Path(__file__).read_bytes()).hexdigest()}
    (run / "full_checker_work.json").write_text(json.dumps(result, indent=2) + "\n")
    (run / "stall_profile.json").write_text(json.dumps(report(run), indent=2) + "\n")
    print("FULL_CHECKER_WORK=" + json.dumps(result), flush=True)
    return int(not result["complete"])


if __name__ == "__main__":
    raise SystemExit(main())
