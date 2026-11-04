from __future__ import annotations
import fcntl
import json
import os
from pathlib import Path
import selectors
import signal
import subprocess
import time
from .common import KIT, read_json, atomic_json, require
from .collector import Collector
from .ledger import status, read_records
from .planning import select_pending
from .safety import gate

def launch(campaign, config_id, execute=False, benches=None, repeats=None, interrupt_after=None):
    root = Path(campaign)
    manifest = read_json(root / "manifest.json")
    pending, issues = select_pending(root, [config_id], benches, repeats)
    require(pending, "no matching pending/failed/interrupted samples")
    if interrupt_after is not None:
        require(interrupt_after >= 1, "interrupt-after must be >=1")
    phase=manifest["stage"]
    check = gate(config_id, "run", manifest,phase)
    if not execute:
        return {"dry_run":True,"samples":len(pending),"safety":check,"journal_issues":issues}
    require(check["allowed"], "; ".join(check["reasons"]))
    # Cooperative lock covers deployment + launch across all campaigns in this kit.
    lock = open(KIT / ".fpga-operation.lock", "a+")
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    check = gate(config_id, "run", manifest,phase)  # recheck after acquiring lease/lock
    require(check["allowed"], "; ".join(check["reasons"]))
    journal, _ = read_records(root / "raw.jsonseq")
    jobs = []
    for sample in pending:
        sid = sample["sample_id"]
        prior = [r["event"]["attempt"] for r in journal if r.get("kind") == "adapter_event" and r["event"]["sample_id"] == sid]
        jobs.append({**sample,"attempt":max(prior, default=0)+1})
    request = root / "jobs" / (config_id + ".pending-" + str(time.time_ns()) + ".json")
    snapshot_seconds=jobs[0]["case"]["common"]["snapshot_seconds"]
    atomic_json(request, {"samples":jobs,"snapshot_seconds":snapshot_seconds,"boot_once":True,
                          "memory_runtime":check["memory_runtime"]})
    collector = Collector(root)
    argv = check["argv"] + ["--config",config_id,"--jobs",str(request),"--campaign",str(root),
                            "--memory-runtime",check["memory_runtime"]]
    atomic_json(root / "launches" / (str(time.time_ns()) + ".json"), {"argv":argv,"safety":check})
    p = None
    try:
        # One adapter launch / Linux boot per configuration. It must never run infrasetup.
        p = subprocess.Popen(argv, stdout=subprocess.PIPE, stderr=subprocess.PIPE, start_new_session=True)
        sel = selectors.DefaultSelector()
        sel.register(p.stdout, selectors.EVENT_READ, "events")
        sel.register(p.stderr, selectors.EVENT_READ, "log")
        buf = bytearray()
        next_save = time.monotonic()+snapshot_seconds
        logpath = root / "logs" / (config_id + ".adapter.log")
        logpath.parent.mkdir(parents=True, exist_ok=True)
        with open(logpath, "ab", buffering=0) as log:
            while sel.get_map():
                for key, _ in sel.select(timeout=1):
                    block = os.read(key.fileobj.fileno(), 65536)
                    if not block:
                        sel.unregister(key.fileobj)
                        continue
                    if key.data == "log":
                        log.write(block)
                        os.fsync(log.fileno())
                        continue
                    buf.extend(block)
                    require(len(buf) <= 8*1024*1024, "adapter record exceeds 8 MiB; per-event traces are forbidden")
                    while b"\n" in buf:
                        line, _, remainder = buf.partition(b"\n")
                        buf[:] = remainder
                        if line:
                            event=json.loads(line)
                            collector.event(event)
                            if (interrupt_after is not None and event["type"]=="start" and
                                sum(v=="complete" for v in collector.terminal.values())>=interrupt_after):
                                raise KeyboardInterrupt("manual interruption/recovery verification point")
                now = time.monotonic()
                if now >= next_save:
                    collector.heartbeat(max_age=3*snapshot_seconds, enforce_fresh=True)
                    os.fsync(log.fileno())
                    next_save = now+snapshot_seconds
                for sid in list(collector.active):
                    sample = collector.samples[sid]
                    # Adapter must emit timeout and drain before moving to the next sample.
                    duration = sample["case"]["common"]["sample_timeout_seconds"]
                    starts = [r["host_time_utc"] for r in collector.journal.records
                              if r.get("kind") == "state" and r.get("state") == "running" and r.get("sample_id") == sid]
                    import datetime as dt
                    started = dt.datetime.fromisoformat(starts[-1]).timestamp()
                    if time.time()-started > duration+60:
                        collector.fail(sid,"timeout","adapter failed to stop/drain within sample timeout + 60 s")
                        raise TimeoutError("unresponsive adapter; remaining samples will not be admitted")
        if buf:
            # Preserve a partial final wire record rather than parsing it as completed data.
            collector.journal.append({"kind":"partial_adapter_tail","bytes_hex":buf.hex()})
        rc = p.wait(timeout=10)
        collector.interrupted("adapter EOF before sample completion")
        return {"returncode":rc,"states":status(root)[0]}
    except BaseException:
        collector.interrupted("host runner interrupted/error; resume restarts this full sample")
        if p and p.poll() is None:
            # Only the process group created by this invocation, never existing FPGA tasks.
            os.killpg(p.pid, signal.SIGTERM)
        raise
    finally:
        collector.close()
        lock.close()

def deploy(config_id, execute=False, phase="main"):
    check = gate(config_id, "deploy",phase=phase)
    if not execute:
        return {"dry_run":True,"safety":check}
    require(check["allowed"], "; ".join(check["reasons"]))
    with open(KIT / ".fpga-operation.lock", "a+") as lock:
        fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
        check = gate(config_id, "deploy",phase=phase)
        require(check["allowed"], "; ".join(check["reasons"]))
        # The only programming path is a source-hashed, independently reviewed per-card adapter.
        p = subprocess.run(check["argv"] + ["--config",config_id,"--bdf",check["target_bdf"]])
        require(p.returncode==0,"deployment adapter failed; no simulation will be started")
        return {"returncode":p.returncode,"safety":check}
