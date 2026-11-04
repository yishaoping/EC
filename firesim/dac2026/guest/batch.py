#!/usr/bin/env python3
"""Run only when manually installed/launched inside the target guest.

One Linux boot, sequential samples, process-group timeout, validate output, drain
between samples. Control backend is REQUIRED; no host-wallclock performance data.
The bridge adapter correlates these control messages with its aggregate metrics.
"""
import argparse
import json
import os
from pathlib import Path
import signal
import subprocess
import sys
import time

def control(executable, operation, job):
    r=subprocess.run([executable,operation,job["sample_id"],str(job["attempt"])],capture_output=True,text=True,timeout=120)
    if r.returncode:
        raise RuntimeError("control backend failed: "+r.stderr[-2000:])
    value=json.loads(r.stdout)
    if value.get("ack") is not True or value.get("sample_id")!=job["sample_id"]:
        raise RuntimeError("invalid control acknowledgement")
    return value

def run(jobs,backend,logdir):
    Path(logdir).mkdir(parents=True,exist_ok=True)
    for job in jobs:
        sid=job["sample_id"]
        control(backend,"drain-before",job)
        control(backend,"arm",job)
        case=job["case"]
        timeout=case["common"]["sample_timeout_seconds"]
        failure=None
        with open(Path(logdir)/(sid+f'.attempt-{job["attempt"]}.log'),"xb") as log:
            # Reserve checker harts through firmware/DT; app cpuset is hart0 only.
            os.sched_setaffinity(0,{0})
            p=None
            try:
                p=subprocess.Popen(case["argv"],cwd=case["cwd"],stdout=log,stderr=subprocess.STDOUT,start_new_session=True)
                rc=p.wait(timeout=timeout)
                if rc:
                    failure="failed"
            except subprocess.TimeoutExpired:
                failure="timeout"
                os.killpg(p.pid,signal.SIGTERM)
                try:p.wait(timeout=5)
                except subprocess.TimeoutExpired:
                    os.killpg(p.pid,signal.SIGKILL);p.wait()
            except OSError as exc:
                failure="failed"
                log.write(("process launch failed: "+str(exc)+"\n").encode())
            log.flush();os.fsync(log.fileno())
        if failure is None:
            try:
                result=subprocess.run(case["verify_argv"],cwd=case["cwd"],capture_output=True,text=True,timeout=120)
                proof=json.loads(result.stdout) if result.returncode==0 else {}
                if proof.get("correct") is not True or len(proof.get("sha256",""))!=64:
                    failure="failed"
            except (OSError,subprocess.TimeoutExpired,ValueError,AttributeError):
                failure="failed"
            # Validator must emit a JSON digest; never accept exit(0) alone.
            if failure is None:
                control(backend,"output-verified:"+proof["sha256"],job)
        # Unsuccessful process termination still requires a sequenced close/drain.
        # If this fails, stop the batch rather than contaminate the next sample.
        control(backend,"seal-and-drain",job)
        control(backend,failure or "sample-complete",job)

if __name__=="__main__":
    p=argparse.ArgumentParser()
    p.add_argument("--jobs",required=True);p.add_argument("--control",required=True)
    p.add_argument("--logdir",default="/var/log/ec-dac")
    a=p.parse_args()
    run(json.loads(Path(a.jobs).read_text())["samples"],a.control,a.logdir)
