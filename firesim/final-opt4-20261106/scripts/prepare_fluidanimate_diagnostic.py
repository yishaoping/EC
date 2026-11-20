#!/usr/bin/env python3
"""Reuse the failing app unchanged and capture its full output before rejecting it."""
import datetime as dt
import json
from pathlib import Path
import shutil
import subprocess
from board_batch import W,D,save,sha

def main():
    target=W/'software/fluidanimate-diagnostic-apps-build.json'
    if not target.exists():
        source=W/'software/fluidanimate-apps-build.json'
        s=json.loads(source.read_text())
        out=W/'software'/('apps-fluidanimate-diagnostic-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ'))
        out.mkdir();shutil.copytree(Path(s['output_dir'])/'inputs',out/'inputs')
        s.update(output_dir=str(out),software_profile='fluidanimate-unchanged-app-failed-output-capture',
                 formal_eligible=False,diagnostic_capture_files=['out.fluid'],
                 reused_apps_receipt=str(source),reused_apps_receipt_sha256=sha(source),
                 diagnostic_policy='Unchanged computation, ROI and exact-byte validity gate; failed output captured to host before invalid marker. Never a formal sample.')
        save(target,s);save(out/'manifest.json',s)
    subprocess.run(['python3',W/'scripts/prepare_profile_system.py','fluidanimate-diagnostic'],check=True)

if __name__=='__main__':main()
