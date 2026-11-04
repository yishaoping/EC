#!/usr/bin/env python3
"""Report cumulative hardware observations without attributing overlap to savings."""
import argparse
import json
from pathlib import Path

CORE = ["cycles", "commit_cycles", "no_commit_gh", "no_commit_rsu",
        "no_commit_ic", "no_commit_big_hang", "no_commit_dispatch_drain",
        "no_commit_csr", "no_commit_rob_nonempty", "no_commit_rob_empty",
        "raw_gh", "raw_rsu", "raw_ic", "raw_dispatch_drain", "retired"]
CACHE = ["cycles", "lsu_ingress_block", "freeze_set_ingress_block",
         "array_arbitration_ingress_block", "s2_nack", "s2_write_busy",
         "preservation_block", "legacy_preservation_pending", "capture_pending",
         "mshr_admission_block", "victim_nack", "replay_wait", "svb_full_fallback",
         "release_ack_pending", "owner_block", "hit_nack", "data_nack",
         "refill_beats", "legacy_wb_requests", "captures", "promotions",
         "store_effects", "lsu_requests", "mshr_admissions", "mshr_active",
         "install_wait", "a_beats", "c_beats", "d_beats", "svb_full_cycles"]


def report(run, start=None, stop=None):
    if start is None or stop is None:
        roi = json.loads((run / "roi.json").read_text())
        start, stop = roi["start_cycle"], roi["stop_cycle"]
    assert 0 <= start < stop
    samples = {k: [] for k in (52, 53, 54)}
    with (run / "safe_chain_events.tsv").open() as stream:
        for line in stream:
            words = line.split()
            if words[0] != "SC1":
                continue
            kind, hart = int(words[5]), int(words[6])
            cycle = int(words[2])
            if kind in samples and hart == 0 and start <= cycle < stop:
                values = [int(w, 16) for w in words[7:]]
                assert values[0] == 1
                samples[kind].append((cycle, values[1:]))
    result = {"run": str(run.resolve()), "requested_window": [start, stop],
              "scope": "SC52 priority partition is exclusive; cache exposures overlap and are not lost-cycle attribution",
              "groups": {}}
    for kind, names in [(52, CORE), (53, CACHE[:15]), (54, CACHE[15:])]:
        rows = sorted(samples[kind])
        if len(rows) < 2:
            result["groups"][str(kind)] = {"status": "INSUFFICIENT_SAMPLES"}
            continue
        assert all(b[0] - a[0] == 1024 for a, b in zip(rows, rows[1:])), "missing profiling sample"
        first, last = rows[0], rows[-1]
        delta = [b - a for a, b in zip(first[1], last[1])]
        assert min(delta) >= 0
        counts = dict(zip(names, delta))
        if kind == 52:
            assert counts["cycles"] == last[0] - first[0]
            assert sum(delta[1:10]) == delta[0], "core cycle partition does not conserve cycles"
        result["groups"][str(kind)] = {"status": "EXACT_BETWEEN_SAMPLES",
            "sampled_window": [first[0], last[0]],
            "unmeasured_boundary_cycles": first[0] - start + stop - last[0],
            "counts": counts}
    return result


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("run", type=Path)
    parser.add_argument("--start", type=int)
    parser.add_argument("--stop", type=int)
    args = parser.parse_args()
    result = report(args.run, args.start, args.stop)
    (args.run / "stall_profile.json").write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps(result, indent=2))
