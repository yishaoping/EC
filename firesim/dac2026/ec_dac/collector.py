from __future__ import annotations
import json
from pathlib import Path
import time
from . import DEFINITION
from .common import read_json, digest, require, atomic_json
from .ledger import Journal, status

class Collector:
    """Single host writer. Adapter stdout carries aggregate records, never instruction traces."""
    def __init__(self, campaign):
        self.root = Path(campaign)
        self.manifest = read_json(self.root / "manifest.json")
        self.samples = {s["sample_id"]:s for s in self.manifest["samples"]}
        self.journal = Journal(self.root)
        self.active = {}
        self.seen = {}
        for r in self.journal.records:
            if r.get("kind") == "adapter_event":
                e = r["event"]
                self.seen[(e["sample_id"],e["attempt"],e["event_seq"])] = digest(e)
        self.latest, self.last = {}, {}
        self.next_seq = {}
        self.finished = {r["sample"]["sample_id"] for r in status(self.root)[0] if r["state"] == "complete"}
        self.terminal = {}

    def close(self):
        self.journal.close()

    def event(self, event):
        sid = event["sample_id"]
        require(sid in self.samples, "unknown sample identity")
        sample = self.samples[sid]
        require(event.get("identity_digest") == digest(sample), "adapter identity/config/code mismatch")
        require(event.get("definition") == DEFINITION, "adapter statistics definition mismatch")
        require(type(event["event_seq"]) is int and event["event_seq"] > 0, "invalid event sequence")
        require(type(event["attempt"]) is int and event["attempt"] > 0, "invalid attempt number")
        key = sid, event["attempt"], event["event_seq"]
        sha = digest(event)
        if key in self.seen:
            require(self.seen[key] == sha, "conflicting duplicate event")
            return "duplicate"
        kind = event["type"]
        if kind == "start":
            require(sid not in self.finished and not self.active, "completed sample or concurrent sample in one node")
            old_attempts = [k[1] for k in self.seen if k[0] == sid]
            require(event["attempt"] > max(old_attempts, default=0), "stale attempt")
            require(event["event_seq"] == 1, "attempt must start at event sequence 1")
        else:
            require(self.active.get(sid) == event["attempt"], "event outside active attempt")
            require(event["event_seq"] == self.next_seq[sid], "event gap/out-of-order event")
        # Preserve every accepted aggregate event before exposing any completion marker.
        self.journal.append({"kind":"adapter_event","event":event,"identity":sample})
        self.seen[key] = sha
        self.next_seq[sid] = event["event_seq"] + 1
        if kind == "start":
            self.active[sid] = event["attempt"]
            # A retry is a fresh full sample, not a continuation of old counters.
            self.latest.pop(sid, None)
            self.terminal.pop(sid, None)
            self.last[sid] = time.monotonic()
            self.journal.append({"kind":"state","sample_id":sid,"identity":sample,
                                 "attempt":event["attempt"],"state":"running"})
        elif kind in ("snapshot","end"):
            metrics = event["metrics"]
            previous = self.latest.get(sid)
            if previous:
                for field in ("generated","completed","latency_count","latency_sum","queue_full_ticks",
                              "queue_occupancy_tick_sum","boom_protection_blocked_ticks"):
                    require(metrics[field] >= previous[field], "cumulative counter regressed: " + field)
                require(metrics["epoch"] == previous["epoch"], "ROI epoch changed within sample")
            self.latest[sid] = metrics
            self.last[sid] = time.monotonic()
            atomic_json(self.root / "snapshots" / f"{sid}.attempt-{event['attempt']}.json",
                        {"identity":sample,"attempt":event["attempt"],"event_seq":event["event_seq"],"metrics":metrics})
            if kind == "end":
                try:
                    self.journal.commit(sample, event["attempt"], metrics)
                except ValueError as e:
                    self.fail(sid, "failed", str(e))
                    return "invalid"
                self.finished.add(sid)
                self.terminal[sid] = "complete"
                del self.active[sid]
        elif kind in ("failed","timeout","interrupted"):
            self.fail(sid, kind, event.get("reason", kind))
        else:
            raise ValueError("unknown aggregate event type: " + kind)
        return "accepted"

    def fail(self, sid, state, reason):
        self.journal.append({"kind":"state","sample_id":sid,"identity":self.samples[sid],
                             "attempt":self.active.get(sid),"state":state,"reason":reason})
        self.active.pop(sid, None)
        self.terminal[sid] = state

    def heartbeat(self, max_age=60, enforce_fresh=False):
        # A stale heartbeat is not a new measurement; mark it explicitly.
        for sid, attempt in list(self.active.items()):
            age = time.monotonic() - self.last[sid]
            self.journal.append({"kind":"host_heartbeat","sample_id":sid,"identity":self.samples[sid],
                                 "attempt":attempt,"measurement_age_seconds":age,
                                 "stale":age > max_age,"metrics":self.latest.get(sid)})
            if enforce_fresh and age > max_age:
                self.fail(sid, "timeout", "no fresh bridge snapshot within freshness limit")
                raise TimeoutError("bridge statistics stopped arriving; partial sample retained")

    def interrupted(self, reason):
        for sid in list(self.active):
            self.fail(sid, "interrupted", reason)
