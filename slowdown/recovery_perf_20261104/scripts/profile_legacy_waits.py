#!/usr/bin/env python3
"""Classify preservation waits only when every relevant state stream is complete."""
import argparse
import collections
import importlib.util
import json
from pathlib import Path
from seal_candidate import ROOT

spec = importlib.util.spec_from_file_location("causality", ROOT / "slowdown/optimization_3_checker/analysis/compact_causality.py")
causality = importlib.util.module_from_spec(spec)
spec.loader.exec_module(causality)


def profile(run):
    cap = json.loads((run / "capture_summary.json").read_text())
    roi = json.loads((run / "roi.json").read_text())
    required = {(1, 0), (8, 0)} | {(k, h) for k in (3, 4, 6) for h in range(1, 5)}
    missing = []
    for kind, hart in sorted(required):
        identity = f"{kind}:{hart}"
        observer, producer = cap["observers"].get(identity, {}), cap["producers"].get(identity, {})
        if (observer.get("footers_seen") != 1 or observer.get("omitted", 1) or
                producer.get("omitted", 1) or producer.get("emitted") != observer.get("events_seen") or
                producer.get("emitted") != observer.get("footer_emitted_count")):
            missing.append(identity)
    result = {"run": str(run.resolve()), "ROI": roi,
              "scope": "complete state-stream wait exposure in main cycles; overlapping cache/core counters are not additive causal savings; same-edge uncertainty at most one cycle"}
    if missing:
        return dict(result, status="N/A_INCOMPLETE_OPTIONAL_STATE", missing_or_omitted_identities=missing)
    rows, footers = [], {}
    with (run / "safe_chain_events.tsv").open() as stream:
        for line in stream:
            words = line.split()
            if words[0] == "SC_END":
                identity = int(words[5]), int(words[6])
                if identity in required:
                    footers[identity] = int(words[2])
            elif words[0] == "SC1" and len(words) == 23:
                t, cycle, local, episode, kind, hart = map(int, words[1:7])
                if (kind, hart) in required:
                    rows.append(dict(time=t, cycle=cycle, local=local, episode=episode,
                                     kind=kind, hart=hart, d=[int(w, 16) for w in words[7:]]))
    assert set(footers) == required and min(footers.values()) >= roi["stop_cycle"]
    assert len({r["episode"] for r in rows}) == 1
    for kind in (1, 8):
        assert min(r["cycle"] for r in rows if r["kind"] == kind) <= roi["start_cycle"]
    errors = []
    clock_fit = causality.align_clocks(rows, errors)
    assert not errors, errors
    batches = collections.defaultdict(list)
    for row in rows:
        batches[row["effective_cycle"]].append(row)
    prefix = pending = previous = None
    accepted, produced = {}, {}
    counts, phases, intervals = collections.Counter(), collections.Counter(), []
    def interval(stop):
        if previous is None or pending is None:
            return
        start, end = max(previous, roi["start_cycle"]), min(stop, roi["stop_cycle"])
        if start >= end:
            return
        category, context = causality.pending_class(pending, prefix, accepted, produced)
        if category:
            counts[category] += end - start
            phases[category + ":" + context.get("phase", "none")] += end - start
            intervals.append(dict(start=start, cycles=end - start, category=category, context=context))
    for cycle, batch in sorted(batches.items()):
        interval(cycle)
        for row in batch:
            kind, data = row["kind"], row["d"]
            if kind == 1:
                prefix = row
            elif kind == 8:
                pending = row
            elif kind == 3 and data[1] & 2:
                accepted[data[0] & 0xffffffff] = (data[0] >> 32) & 3
            elif kind == 4 and data[1] & 1:
                produced.setdefault(data[0] & 0xffffffff, dict(status=(data[0] >> 32) & 3))
            elif kind == 6:
                for present, payload in [(data[2] & ((1 << 16) | (1 << 9) | (1 << 18)), data[7]),
                                         (data[2] & (1 << 15), data[6])]:
                    if present:
                        produced.setdefault(payload & 0xffffffff, dict(status=(payload >> 32) & 3))
        previous = cycle
    interval(roi["stop_cycle"])
    return dict(result, status="PASS" if not counts["UNRESOLVED"] else "UNRESOLVED",
                clock_fit=clock_fit, counts=dict(counts), phases=dict(phases),
                longest=sorted(intervals, key=lambda r: r["cycles"], reverse=True)[:8])


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("run", type=Path)
    parser.add_argument("--output", required=True, type=Path)
    args = parser.parse_args()
    result = profile(args.run)
    with args.output.open("x") as stream:
        stream.write(json.dumps(result, indent=2) + "\n")
    print(json.dumps({k: result[k] for k in ["status", "counts", "phases"] if k in result}), flush=True)
