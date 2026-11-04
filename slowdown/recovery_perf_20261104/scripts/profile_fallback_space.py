#!/usr/bin/env python3
"""Bound the opportunity to revisit a full-SVB fallback, using complete streams."""
import argparse
import collections
import json
from pathlib import Path


def profile(run):
    cap = json.loads((run / "capture_summary.json").read_text())
    roi = json.loads((run / "roi.json").read_text())
    required = {"8:0", "32:0"} | {f"35:{i}" for i in range(16)}
    for identity in required:
        observer, producer = cap["observers"][identity], cap["producers"][identity]
        assert observer["omitted"] == producer["omitted"] == 0, identity
        assert observer["footers_seen"] == 1, identity
        assert producer["emitted"] == observer["events_seen"] == observer["footer_emitted_count"], identity
    batches = collections.defaultdict(list)
    for line in (run / "safe_chain_events.tsv").open():
        w = line.split()
        if w[0] == "SC1" and len(w) == 23 and int(w[5]) in (8, 32, 35):
            batches[int(w[2])].append((int(w[5]), [int(x, 16) for x in w[7:]]))
    live, full_entries, candidates = set(), set(), set()
    pending = previous = None
    cycles = guarded = 0
    def interval(stop):
        nonlocal cycles, guarded
        if previous is None or pending is None:
            return
        n = max(0, min(stop, roi["stop_cycle"]) - max(previous, roi["start_cycle"]))
        flags = pending[9]
        if n and flags & 1 and not flags & 2 and pending[0] in full_entries and len(live) < 16:
            cycles += n
            candidates.add(pending[0])
            # Remaining owner/drain/probe guards further bound usefulness.
            blocked = any(flags & (1 << b) for b in (3, 4, 6, 7, 8, 9, 18, 23, 24))
            if not blocked:
                guarded += n
    for time, batch in sorted(batches.items()):
        interval(time)
        for kind, data in batch:
            if kind == 8:
                if data[9] & 1 and (pending is None or not pending[9] & 1 or data[0] != pending[0]):
                    if len(live) == 16:
                        full_entries.add(data[0])
                pending = data
            elif kind == 32:
                assert data[1] not in live
                live.add(data[1])
            else:
                assert data[1] in live
                live.remove(data[1])
        previous = time
    interval(roi["stop_cycle"])
    assert not live
    return {"run": str(run.resolve()), "ROI": roi, "full_start_episodes": len(full_entries),
            "full_start_with_later_space_episodes": len(candidates),
            "unsafe_wait_with_later_space_cycles": cycles,
            "without_saved_owner_drain_probe_recovery_guards_cycles": guarded,
            "scope": "Complete SC8 plus exact SVB allocation/terminal ownership. Exposure bound, not cycle savings; original fast-path qualification, incoming sequence and epoch eligibility can further reduce usefulness. Same-edge entry/occupancy ordering may differ by one cycle."}


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("run", type=Path)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    result = profile(args.run)
    with args.output.open("x") as stream:
        stream.write(json.dumps(result, indent=2) + "\n")
    print(json.dumps(result))
