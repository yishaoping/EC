"""Durable append-only JSON text sequences plus atomically committed samples."""
from __future__ import annotations
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
from . import SCHEMA
from .common import canonical, atomic_json, read_json, require, digest
from .measurement import validate_metrics

def read_records(path):
    """RS framing recovers after a torn record without deleting original bytes."""
    if not Path(path).exists():
        return [], []
    raw = Path(path).read_bytes()
    good, bad = [], []
    if raw and not raw.startswith(b"\x1e"):
        bad.append({"frame":0,"reason":"missing initial RS"})
    for index, frame in enumerate(raw.split(b"\x1e")[1:], 1):
        if not frame.endswith(b"\n"):
            bad.append({"frame":index,"reason":"torn/incomplete record","bytes":len(frame)})
            continue
        try:
            good.append(json.loads(frame))
        except (ValueError, UnicodeError) as e:
            bad.append({"frame":index,"reason":str(e)})
    return good, bad

class Journal:
    def __init__(self, campaign):
        self.root = Path(campaign)
        self.root.mkdir(parents=True, exist_ok=True)
        self.lock = open(self.root / ".writer.lock", "a+")
        fcntl.flock(self.lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
        self.path = self.root / "raw.jsonseq"
        self.records, self.torn = read_records(self.path)
        self.sequence = max((r.get("batch_seq", 0) for r in self.records), default=0)
        self.fd = os.open(self.path, os.O_WRONLY | os.O_APPEND | os.O_CREAT, 0o600)

    def close(self):
        os.close(self.fd)
        self.lock.close()

    def append(self, record):
        self.sequence += 1
        value = {**record,"schema":SCHEMA,"batch_seq":self.sequence,
                 "host_time_utc":dt.datetime.now(dt.timezone.utc).isoformat()}
        payload = b"\x1e" + canonical(value).encode() + b"\n"
        offset = 0
        while offset < len(payload):
            n = os.write(self.fd, payload[offset:])
            if n <= 0:
                raise OSError("journal write made no progress")
            offset += n
        os.fsync(self.fd)  # disk errors propagate; runner must stop admission
        self.records.append(value)
        return value

    def commit(self, sample, attempt, metrics, allow_synthetic=False):
        errors = validate_metrics(metrics, sample["configuration"], allow_synthetic)
        require(not errors, "; ".join(errors))
        result = {"schema":SCHEMA,"status":"complete","sample_id":sample["sample_id"],
                  "identity":sample,"attempt":attempt,"metrics":metrics,"metrics_digest":digest(metrics)}
        dest = self.root / "results" / (sample["sample_id"] + ".json")
        atomic_json(dest, result, replace=False)
        self.append({"kind":"state","state":"complete","sample_id":sample["sample_id"],
                     "attempt":attempt,"identity":sample,"metrics_digest":result["metrics_digest"]})
        return dest

def status(campaign, manifest=None, allow_synthetic=False):
    root = Path(campaign)
    manifest = manifest or read_json(root / "manifest.json")
    records, issues = read_records(root / "raw.jsonseq")
    states, last_seq = {}, 0
    for record in records:
        seq = record.get("batch_seq", 0)
        if seq <= last_seq:
            issues.append({"reason":"nonmonotonic journal batch sequence","batch_seq":seq})
        last_seq = max(seq, last_seq)
        if record.get("kind") == "state":
            states[record["sample_id"]] = record.get("state", "failed")
    output = []
    for sample in manifest["samples"]:
        sid = sample["sample_id"]
        p = root / "results" / (sid + ".json")
        state = states.get(sid, "pending")
        errors = []
        if p.exists():
            try:
                r = read_json(p)
                require(r.get("identity") == sample and r.get("sample_id") == sid and
                        r.get("status") == "complete", "result identity/status mismatch")
                require(digest(r["metrics"]) == r.get("metrics_digest"), "metrics checksum mismatch")
                errors = validate_metrics(r["metrics"], sample["configuration"], allow_synthetic)
                state = "complete" if not errors else "failed"
            except (OSError, ValueError, KeyError) as e:
                state, errors = "failed", [str(e)]
        elif state == "complete":
            state, errors = "failed", ["completion journal exists but atomic result is missing"]
        output.append({"sample":sample,"state":state,"errors":errors})
    return output, issues

def recover(campaign, allow_synthetic=False):
    # Call only after the previous run/collector stopped, with the exclusive writer lock.
    j = Journal(campaign)
    try:
        states, issues = status(campaign, allow_synthetic=allow_synthetic)
        for s in states:
            if s["state"] == "running":
                j.append({"kind":"state","sample_id":s["sample"]["sample_id"],
                          "identity":s["sample"],"state":"interrupted","reason":"recovered unfinished sample"})
        return {"states":status(campaign, allow_synthetic=allow_synthetic)[0],"journal_issues":issues}
    finally:
        j.close()
