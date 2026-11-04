"""Executable reference for the passive bridge's statistics contract.

This is an offline contract validator, not a simulator or an event-printing path.
Real FireSim integration must aggregate in the bridge and emit snapshots only.
"""
from __future__ import annotations
import math
from . import DEFINITION
from .common import require

U64 = (1 << 64) - 1

def bucket_bounds(value):
    require(type(value) is int and 0 <= value <= U64, "latency outside uint64")
    if value < 256:
        return value, value
    power = value.bit_length() - 1
    width = 1 << (power - 4)   # 16 equal-width buckets per octave, <=6.25% span
    lo = (value // width) * width
    return lo, min(U64, lo + width - 1)

def quantile_interval(histogram, q):
    n = sum(b["count"] for b in histogram)
    if not n:
        return None
    rank, cumulative = math.ceil(q * n), 0
    for b in sorted(histogram, key=lambda x:x["lo"]):
        cumulative += b["count"]
        if cumulative >= rank:
            return [b["lo"], b["hi"]]
    raise ValueError("histogram missing samples")

class ReferenceObserver:
    """Join by (ROI epoch, package seq), preserving original event timestamps.

    boom_exec_done is max execution-completion time of surviving instructions in
    a sealed package. Retirement establishes membership only; it is NOT its time.
    A result received later over CDC carries its source timestamp on a proven
    common timebase; arrival time is separately named release/transport time.
    """
    def __init__(self, rockets, epoch):
        self.rockets, self.epoch = rockets, epoch
        self.tasks, self.completed = {}, set()
        self.hist, self.errors = {}, []
        self.begin = self.end = self.drain = None
        self.count = self.total = self.maximum = 0
        self.busy_roi = [0] * rockets
        self.busy_drain = [0] * rockets
        self.queue_sum = self.queue_max = self.queue_full = self.blocked = 0
        self.reasons = {}
        self.exception_count = 0

    def roi_begin(self, tick, outstanding_before, package_boundary_clean):
        require(self.begin is None and outstanding_before == 0 and package_boundary_clean,
                "ROI must start at a drained package boundary")
        self.begin = tick

    def allocate(self, seq, tick):
        require(self.begin is not None and self.end is None, "allocation outside ROI")
        require(0 < seq < (1 << 32) and seq not in self.tasks and seq not in self.completed,
                "duplicate or wrapped package sequence; create a fresh epoch before wrap")
        self.tasks[seq] = {"alloc":tick,"exec":None,"verify":None}

    def boom_done(self, seq, execution_tick):
        require(seq in self.tasks and self.tasks[seq]["exec"] is None, "unknown/duplicate BOOM completion")
        self.tasks[seq]["exec"] = execution_tick
        self._join(seq)

    def verify_done(self, seq, source_tick, final_status="PASS"):
        require(seq in self.tasks and self.tasks[seq]["verify"] is None, "unknown/duplicate final compare")
        require(final_status == "PASS", "FAIL/CANCELLED cannot be used as successful latency")
        self.tasks[seq]["verify"] = source_tick
        self._join(seq)

    def _join(self, seq):
        t = self.tasks[seq]
        if t["exec"] is None or t["verify"] is None:
            return
        # Package membership/allocation can be observed at retirement after the
        # instruction executed. Never force its original time to allocation time.
        require(t["exec"] <= t["verify"], "invalid event time/order or CDC conversion")
        latency = t["verify"] - t["exec"]
        lo, hi = bucket_bounds(latency)
        self.hist[(lo, hi)] = self.hist.get((lo, hi), 0) + 1
        self.count += 1
        self.total += latency
        self.maximum = max(self.maximum, latency)
        require(self.total <= U64 and self.count <= U64, "statistics overflow")
        del self.tasks[seq]
        self.completed.add(seq)

    def pressure(self, ticks, occupancy, capacity, blocked, reasons, busy):
        require(self.begin is not None and self.drain is None, "pressure outside sample")
        require(type(ticks) is int and ticks > 0 and 0 <= occupancy <= capacity and capacity > 0,
                "bad queue interval")
        require(len(busy) == self.rockets and all(type(v) is bool for v in busy), "bad busy vector")
        if self.end is None:
            self.queue_sum += occupancy * ticks
            self.queue_max = max(self.queue_max, occupancy)
            self.queue_full += ticks * (occupancy == capacity)
            self.blocked += ticks * blocked
            for reason in set(reasons):
                self.reasons[reason] = self.reasons.get(reason, 0) + ticks
        dest = self.busy_roi if self.end is None else self.busy_drain
        for i, flag in enumerate(busy):
            dest[i] += ticks * flag

    def roi_end(self, tick, producer_sealed):
        require(self.begin is not None and self.end is None and producer_sealed, "unsealed ROI tail")
        require(tick > self.begin, "empty ROI")
        self.end = tick

    def drained(self, tick, all_transports_empty, all_released):
        require(self.end is not None and tick >= self.end and not self.tasks and
                all_transports_empty and all_released, "unfinished validation at drain")
        self.drain = tick

    def snapshot(self, final=False):
        require(not final or self.drain is not None, "final snapshot before drain")
        return {"definition":DEFINITION,"epoch":self.epoch,"final":final,
                "roi_cycles":None if self.end is None else self.end - self.begin,
                "drain_cycles":None if self.drain is None else self.drain - self.end,
                "generated":len(self.tasks)+len(self.completed),"completed":self.count,
                "exceptions":self.exception_count,"outstanding":len(self.tasks),
                "latency_count":self.count,"latency_sum":self.total,"latency_max":self.maximum,
                "histogram":[{"lo":lo,"hi":hi,"count":n} for (lo,hi),n in sorted(self.hist.items())],
                "busy_roi_ticks":self.busy_roi,"busy_drain_ticks":self.busy_drain,
                "queue_occupancy_tick_sum":self.queue_sum,"queue_max":self.queue_max,
                "queue_full_ticks":self.queue_full,"boom_protection_blocked_ticks":self.blocked,
                "blocking_reasons":self.reasons,"blocking_reasons_exclusive":False,
                "overflow":False,"dropped_events":0,"protocol_errors":self.errors,
                "roi_start_drained":True,"roi_end_sealed":self.end is not None,
                "all_released":self.drain is not None,"timebase_verified":True,
                "execution_timestamp_verified":True if self.rockets else None,
                "final_compare_verified":True if self.rockets else None,
                "output_correct":False,"output_digest":None,"synthetic":True}

def validate_metrics(m, config, allow_synthetic=False):
    errors = []
    def check(ok, why):
        if not ok:
            errors.append(why)
    check(m.get("definition") == DEFINITION, "measurement definition mismatch")
    check(m.get("final") is True, "not a final snapshot")
    check(allow_synthetic or m.get("synthetic") is False, "synthetic/unlabelled data excluded")
    ints = ["epoch","roi_cycles","drain_cycles","generated","completed","exceptions","outstanding",
            "latency_count","latency_sum","latency_max","dropped_events","queue_occupancy_tick_sum",
            "queue_max","queue_full_ticks","boom_protection_blocked_ticks"]
    for k in ints:
        check(type(m.get(k)) is int and 0 <= m[k] <= U64, "missing/bad uint64 " + k)
    if errors:
        return errors
    check(m["roi_cycles"] > 0, "zero ROI duration")
    check(m["generated"] == m["completed"] == m["latency_count"], "unmatched validation tasks")
    if config["rockets"]:
        check(m["generated"] > 0, "no measured validation tasks")
    else:
        check(m["generated"] == 0, "B contains checker tasks")
    proof_fields = ["roi_start_drained","roi_end_sealed","all_released","timebase_verified","output_correct"]
    if config["rockets"]:
        proof_fields += ["execution_timestamp_verified","final_compare_verified"]
    else:
        check(m.get("execution_timestamp_verified") is None and m.get("final_compare_verified") is None,
              "B checker latency proofs must be null (not applicable)")
        check(m["latency_sum"] == m["latency_max"] == 0, "B has checker latency")
    for k in proof_fields:
        check(m.get(k) is True, "missing proof: " + k)
    output_digest = m.get("output_digest")
    check(isinstance(output_digest, str) and len(output_digest) == 64 and
          all(c in "0123456789abcdef" for c in output_digest), "missing output digest")
    check(m["exceptions"] == m["outstanding"] == m["dropped_events"] == 0, "exceptions/drops/outstanding")
    check(m.get("overflow") is False and m.get("protocol_errors") == [], "overflow/protocol errors")
    hist = m.get("histogram", [])
    check(isinstance(hist, list), "histogram missing")
    last, count, lower_sum, upper_sum = -1, 0, 0, 0
    for b in hist if isinstance(hist, list) else []:
        if not isinstance(b, dict) or not all(type(b.get(k)) is int for k in ("lo","hi","count")):
            errors.append("malformed histogram bucket")
            continue
        lo, hi, n = b["lo"], b["hi"], b["count"]
        check(0 <= lo <= hi <= U64 and lo > last and n > 0, "histogram overlap/range/count")
        check(0 <= lo <= U64 and bucket_bounds(lo) == (lo, hi), "unknown histogram layout")
        last = hi
        count += n
        lower_sum += lo*n
        upper_sum += hi*n
    check(count == m["latency_count"], "histogram sample count mismatch")
    check(lower_sum <= m["latency_sum"] <= upper_sum, "histogram/sum mismatch")
    if count:
        check(hist[-1]["lo"] <= m["latency_max"] <= hist[-1]["hi"], "maximum/histogram mismatch")
        check(m["latency_max"] <= m["latency_sum"] <= count*m["latency_max"], "invalid latency sum")
    else:
        check(m["latency_sum"] == m["latency_max"] == 0, "nonzero latency statistics without samples")
    for k, duration in [("busy_roi_ticks",m["roi_cycles"]),("busy_drain_ticks",m["drain_cycles"])]:
        v = m.get(k)
        check(isinstance(v, list) and len(v) == config["rockets"] and
              all(type(x) is int and 0 <= x <= duration for x in v), "bad " + k)
    check(m["queue_full_ticks"] <= m["roi_cycles"] and
          m["boom_protection_blocked_ticks"] <= m["roi_cycles"], "cycle counts exceed ROI")
    check(m["queue_occupancy_tick_sum"] <= m["queue_max"]*m["roi_cycles"], "queue occupancy inconsistent")
    reasons = m.get("blocking_reasons")
    check(isinstance(reasons, dict) and all(type(x) is int and 0 <= x <= m["roi_cycles"] for x in reasons.values()),
          "invalid blocking reasons")
    if m.get("blocking_reasons_exclusive") is True and isinstance(reasons, dict):
        check(sum(reasons.values()) == m["boom_protection_blocked_ticks"], "exclusive blocking count does not tie")
    return errors
