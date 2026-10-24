#!/usr/bin/env python3
"""Offline TSV analysis. Sample settled values immediately BEFORE core rising edges.

Does not open FST or invoke build/simulation. Names and values are supplied by
fst_extract. Unknown values remain unknown; cycle counts use actual core edges.
"""
import argparse
from collections import Counter, defaultdict
import json
from pathlib import Path
import re
import statistics


def number(raw):
    raw = raw.lower().removeprefix("b")
    return int(raw, 2) if raw and set(raw) <= {"0", "1"} else None


def batches(path, meta, names):
    tick, changes = None, {}
    with path.open() as stream:
        for line in stream:
            row = line.rstrip("\n").split("\t", 3)
            if row[0] == "META":
                meta.update(start_tick=int(row[1]), end_tick=int(row[2]), timescale_exponent=int(row[3]))
            elif row[0] == "WINDOW":
                meta.update(window_start=int(row[1]), window_end=int(row[2]))
            elif row[0] == "H":
                names[row[3].split()[0]] = (int(row[1]), int(row[2]))
            elif row[0] == "V":
                at, handle, value = int(row[1]), int(row[2]), number(row[3])
                if tick is not None and at < tick:
                    raise ValueError("non-monotonic FST callback ticks")
                if tick is not None and at != tick:
                    yield tick, changes
                    changes = {}
                tick = at
                changes[handle] = value
        if tick is not None:
            yield tick, changes


def scopes(names, token):
    return sorted({n.rsplit(".", 1)[0] for n in names
                   if re.fullmatch(re.escape(token) + r"(?:_\d+)?", n.rsplit(".", 1)[-1])})


class Signals:
    def __init__(self, names, state):
        self.names, self.state = names, state
        self.scope_cache, self.vector_cache = {}, {}

    def scopes(self, token):
        if token not in self.scope_cache:
            self.scope_cache[token] = scopes(self.names, token)
        return self.scope_cache[token]

    def get(self, scope, leaf):
        record = self.names.get(scope + "." + leaf)
        return self.state.get(record[0]) if record else None

    def lane(self, scope, leaf, lane, boolean=False):
        record = self.names.get(scope + "." + leaf + "_" + str(lane))
        if record:
            return self.state.get(record[0])
        record = self.names.get(scope + "." + leaf)
        if record and boolean:
            value = self.state.get(record[0])
            return ((value >> lane) & 1) if value is not None and lane < record[1] else None
        return None  # Never guess the element width of a packed UInt Vec.

    def vec(self, scope, leaf, boolean=True):
        prefix = scope + "." + leaf + "_"
        if prefix not in self.vector_cache:
            self.vector_cache[prefix] = sorted(int(n[len(prefix):]) for n in self.names
                         if n.startswith(prefix) and n[len(prefix):].isdigit())
        lanes = self.vector_cache[prefix]
        if lanes:
            return [self.get(scope, leaf + "_" + str(i)) for i in lanes]
        record = self.names.get(scope + "." + leaf)
        value = self.state.get(record[0]) if record else None
        if value is None:
            return []
        return [(value >> i) & 1 for i in range(record[1])] if boolean else [value]


def any_known(values):
    if any(v is not None and v != 0 for v in values):
        return True
    return False if values and all(v is not None for v in values) else None


def both(a, b):
    if a is False or b is False:
        return False
    return None if a is None or b is None else bool(a and b)


def invert(a):
    return None if a is None else not a


class Ledger:
    def __init__(self):
        self.open, self.counts, self.unknown, self.rows, self.seen = {}, Counter(), Counter(), defaultdict(list), set()

    def add(self, metric, active, index, tick, cycle, identity=None, context=None):
        self.seen.add(metric)
        if active is None:
            self.unknown[metric] += 1
        if active:
            self.counts[metric] += 1
        old = self.open.get(metric)
        if old and (not active or old["identity"] != identity or old["end_sample"] != index):
            self.close(metric, tick, index)
            old = None
        if active:
            if old is None:
                self.open[metric] = {"start_tick": tick, "start_sample": index, "start_csr_cycle": cycle,
                                     "end_sample": index + 1, "cycles": 1, "identity": identity,
                                     "context_at_start": context, "context_at_last_sample": context}
            else:
                old["cycles"] += 1
                old["end_sample"] = index + 1
                old["context_at_last_sample"] = context

    def close(self, metric, tick, index):
        old = self.open.pop(metric)
        old.update(end_tick=tick, end_sample=index, right_boundary_clipped=(tick is None))
        self.rows[metric].append(old)


def distribution(rows):
    values = sorted(r["cycles"] for r in rows)
    return {"events": len(values), "median": statistics.median(values),
            "p95_nearest_rank": values[max(0, (95 * len(values) + 99) // 100 - 1)],
            "max": max(values)} if values else {"events": 0}


def measure(sig, lsu, rob, lanes):
    get = lambda leaf: sig.get(lsu, "slowdown_" + leaf)
    flag = lambda leaf: None if get(leaf) is None else bool(get(leaf))
    pending, freeze, conflict = flag("pending"), flag("freeze"), flag("freeze_conflict")
    valid, ready = flag("lsu_valid"), flag("lsu_ready")
    blocked = both(valid, invert(ready))
    freeze_sufficient = both(blocked, conflict)
    exclusive = both(freeze_sufficient, both(invert(flag("killed_replay")), flag("pipeline_ready")))
    metrics = {"pending_activity": pending, "freeze_activity": freeze, "freeze_conflict": conflict,
               "lsu_valid_not_ready": blocked, "freeze_sufficient_block": freeze_sufficient,
               "freeze_only_admission_condition": exclusive}
    details = {}
    for lane in lanes:
        lv = sig.lane(lsu, "slowdown_lsu_lane_valid", lane, True)
        fields = {k: sig.lane(lsu, "slowdown_lsu_" + k, lane)
                  for k in ("addr", "set", "tag", "cmd", "rob_idx", "pc", "packet_seq",
                            "token", "token_valid", "ldq_idx", "stq_idx")}
        if len(lanes) == 1:
            fields = {k: get("lsu_" + k) if v is None else v for k, v in fields.items()}
        ps, pt = get("pending_set"), get("pending_tag")
        same = None if fields["set"] is None or ps is None else fields["set"] == ps
        diff = None if fields["tag"] is None or pt is None else fields["tag"] != pt
        live = both(blocked, None if lv is None else bool(lv))
        prefix = "lane_" + str(lane) + "_"
        metrics[prefix + "blocked"] = live
        metrics[prefix + "same_set_different_line"] = both(live, both(pending, both(same, diff)))
        metrics[prefix + "freeze_only_different_line"] = both(metrics[prefix + "same_set_different_line"], exclusive)
        metrics[prefix + "same_line"] = both(live, both(pending, both(same, invert(diff))))
        metrics[prefix + "different_set_collateral"] = both(live, both(freeze_sufficient, invert(same)))
        metrics[prefix + "fire"] = both(both(valid, ready), None if lv is None else bool(lv))
        details[prefix] = fields
    gate_value = sig.get(rob, "slowdown_rob_gate")
    gate = None if gate_value is None else bool(gate_value)
    can = any_known(sig.vec(rob, "slowdown_can_commit_noGC"))
    commit = any_known(sig.vec(rob, "slowdown_will_commit"))
    no_gc = any_known(sig.vec(rob, "slowdown_will_commit_noGC"))
    opportunity = both(gate, both(no_gc, invert(commit)))
    different = any_known([v for k, v in metrics.items() if k.endswith("_same_set_different_line")])
    metrics.update(rob_gate=gate, can_commit_noGC=can, actual_commit=commit,
                   rob_gate_with_ready_head=both(gate, can), confirmed_direct_gc_commit_opportunity=opportunity,
                   freeze_and_rob_gate=both(freeze, gate), same_set_different_line_union=different,
                   different_line_and_rob_gate=both(different, gate),
                   different_line_and_commit_opportunity=both(different, opportunity),
                   target_interval_union=any_known([pending, freeze, blocked, gate]))
    for ch in ("a", "c", "d"):
        values = []
        for scope in sig.scopes("slowdown_outer_" + ch + "_valid"):
            v, r = (sig.get(scope, "slowdown_outer_" + ch + "_" + k) for k in ("valid", "ready"))
            values.append(None if v is None or r is None else bool(v and not r))
        metrics["outer_" + ch + "_backpressure"] = any_known(values)
        metrics["different_line_and_outer_" + ch] = both(different, any_known(values))
    for token in ("barrier_active", "preservation_lock", "scheduler_interlock", "validation_block", "mshr_file_active"):
        values = [sig.get(s, "slowdown_" + token) for s in sig.scopes("slowdown_" + token)]
        metrics[token + "_activity"] = any_known(values)
        metrics["different_line_and_" + token] = both(different, any_known(values))
    for token in ("pending_mshr_conflict", "pending_slot_conflict", "pending_resident_match",
                  "pending_issued", "pending_wb_done", "meta_clear_valid", "meta_clear_ready"):
        metrics[token] = flag(token)
        metrics["pending_and_" + token] = both(pending, flag(token))
    for label, valid_leaf, ready_leaf in (
        ("mshr_primary_admission_wait", "slowdown_mshr_pri_valid", "slowdown_mshr_pri_ready"),
        ("mshr_secondary_admission_wait", "slowdown_mshr_sec_valid", "slowdown_mshr_sec_ready"),
        ("scheduler_request_wait", "slowdown_scheduler_request_valid", "slowdown_scheduler_request_ready")):
        statuses = []
        for scope in sig.scopes(valid_leaf):
            v, r = sig.get(scope, valid_leaf), sig.get(scope, ready_leaf)
            statuses.append(None if v is None or r is None else bool(v and not r))
        metrics[label] = any_known(statuses)
        metrics["different_line_and_" + label] = both(different, any_known(statuses))
    for token in ("debug_s2_nack", "debug_s2_nack_miss", "debug_s2_nack_victim", "debug_s2_nack_wb",
                  "debug_cross_package_wb_valid", "debug_cross_package_wb_ready", "debug_cross_package_meta_clear_block"):
        metrics[token] = any_known(sig.vec(lsu, token))
    pid = {k: get("pending_" + k) for k in ("set", "tag", "way", "seq", "epoch", "writer", "generation", "content_seq")}
    return metrics, details, pid


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("trace", type=Path)
    p.add_argument("--roi", type=Path, help="roi.json from this exact run; clip by csr-cycle bounds")
    p.add_argument("--lsu-scope", help="exact FST scope if multiple observed LSUs")
    p.add_argument("--rob-scope", help="exact FST scope if multiple observed ROBs")
    p.add_argument("--out", type=Path, required=True, help="NEW directory under slowdown/analysis/results")
    args = p.parse_args()
    out = args.out.resolve()
    out.relative_to(Path("/data1/gzh/EC/slowdown/analysis/results").resolve())
    if out.exists():
        raise SystemExit("output already exists; refusing overwrite")
    roi = json.loads(args.roi.read_text()) if args.roi else None
    if roi and ("start_cycle" not in roi or "stop_cycle" not in roi):
        raise SystemExit("ROI lacks start_cycle/stop_cycle")
    names, meta, state, ledger = {}, {}, {}, Ledger()
    periods, last_tick, sample, accepted = Counter(), None, 0, 0
    lsu, rob, clock, lanes = None, None, None, None
    fires, identities = [], set()
    sig = Signals(names, state)
    for tick, changes in batches(args.trace, meta, names):
        if lsu is None:
            lsus, robs = scopes(names, "slowdown_csr_cycle"), scopes(names, "slowdown_can_commit_noGC")
            if args.lsu_scope:
                lsus = [s for s in lsus if s == args.lsu_scope]
            if args.rob_scope:
                robs = [s for s in robs if s == args.rob_scope]
            if len(lsus) != 1 or len(robs) != 1:
                raise SystemExit("UNRESOLVED: select one LSU and ROB: " + repr((lsus, robs)))
            lsu, rob = lsus[0], robs[0]
            record = names.get(lsu + ".slowdown_core_clock")
            if not record:
                raise SystemExit("UNRESOLVED: core clock alias absent")
            clock = record[0]
            prefix = lsu + ".slowdown_lsu_lane_valid_"
            lanes = sorted(int(n[len(prefix):]) for n in names if n.startswith(prefix) and n[len(prefix):].isdigit())
            if not lanes and lsu + ".slowdown_lsu_lane_valid" in names:
                lanes = list(range(names[lsu + ".slowdown_lsu_lane_valid"][1]))
            if not lanes:
                raise SystemExit("UNRESOLVED: per-lane valid absent")
        if state.get(clock) == 0 and changes.get(clock) == 1:
            # sig reads state before all changes at this edge.
            cycle = sig.get(lsu, "slowdown_csr_cycle")
            selected = not roi or (cycle is not None and roi["start_cycle"] <= cycle < roi["stop_cycle"])
            if last_tick is not None:
                periods[tick - last_tick] += 1
            last_tick = tick
            if selected:
                metrics, details, pid = measure(sig, lsu, rob, lanes)
                for key, active in metrics.items():
                    identity = pid if key in ("pending_activity", "freeze_activity") else None
                    context = None
                    if key.startswith("lane_"):
                        prefix = "_".join(key.split("_")[:2]) + "_"
                        request = details[prefix]
                        identity = request
                        context = {"pending": pid,
                                    "rob_head_idx": sig.get(rob, "slowdown_rob_head_idx"),
                                    "rob_head_valid": sig.vec(rob, "slowdown_rob_head_valid"),
                                    "rob_head_pc": sig.vec(rob, "slowdown_rob_head_pc", False),
                                    "head_busy": sig.vec(rob, "slowdown_head_busy"),
                                    "can_commit_noGC": sig.vec(rob, "slowdown_can_commit_noGC"),
                                    "will_commit": sig.vec(rob, "slowdown_will_commit")}
                        if key.endswith("same_set_different_line") and active:
                            identities.add(json.dumps(request, sort_keys=True))
                        if key.endswith("_fire") and active:
                            fires.append({"tick": tick, "csr_cycle": cycle, "lane": prefix, "request": request})
                    ledger.add(key, active, sample, tick, cycle, identity, context)
                accepted += 1
            else:
                for key in list(ledger.open):
                    ledger.close(key, tick, sample)
            sample += 1
        state.update(changes)
    for key in list(ledger.open):
        ledger.close(key, None, ledger.open[key]["end_sample"])
    if not sample:
        raise SystemExit("UNRESOLVED: no observed core rising edges")
    out.mkdir(parents=True)
    with (out / "intervals.jsonl").open("x") as stream:
        for metric, rows in sorted(ledger.rows.items()):
            for row in rows:
                stream.write(json.dumps({"metric": metric, **row}, sort_keys=True) + "\n")
    (out / "accepted_requests.jsonl").write_text("".join(json.dumps(r) + "\n" for r in fires))
    summary = {"schema": 1, "trace": str(args.trace.resolve()), "meta": meta, "roi": roi,
               "scope": {"lsu": lsu, "rob": rob, "lanes": lanes},
               "sampled_cycles": accepted, "all_sampled_edges": sample,
               "coverage": "UNRESOLVED_WITHOUT_ROI" if not roi else (
                   "FULL_ROI_EDGE_COUNT" if accepted == roi.get("current_roi_cycles") else "TRACE_INCOMPLETE_ROI_EDGE_COUNT_MISMATCH"),
               "sampling": "settled values immediately before observed core rising edges",
               "interval_semantics": "half-open core sample indices; raw FST ticks retained; capture boundaries may clip waits",
               "observed_ticks_per_core_period": dict(periods),
               "metrics": {k: {"true_cycles": ledger.counts[k], "unknown_cycles": ledger.unknown[k],
                                "wait_distribution_in_cycles": distribution(ledger.rows[k])} for k in sorted(ledger.seen)},
               "unique_different_line_request_keys": len(identities),
               "identity_caveat": "observed keys; token/ROB wrap and cancellation require lifecycle review",
               "causality": {"set_freeze": "direct ready predicate when freeze_only_admission_condition holds",
                             "gc_opportunity": "only direct GC commit gate, not proof of upstream freeze causality",
                             "freeze_to_rob_critical_path": "UNRESOLVED; overlap alone is not causal proof",
                             "mshr_full": "UNRESOLVED; active MSHR is not full",
                             "avoidable_cycles": "UNRESOLVED; no safe narrower implementation or counterfactual"},
               "comparison": "no mechanism-level slowdown estimate"}
    (out / "summary.json").write_text(json.dumps(summary, indent=2) + "\n")
    print(out / "summary.json")


if __name__ == "__main__":
    main()
