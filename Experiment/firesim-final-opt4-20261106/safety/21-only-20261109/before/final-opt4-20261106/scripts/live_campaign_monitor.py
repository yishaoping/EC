#!/usr/bin/env python3
"""Publish durable run/CAD state automatically; never inspect devices or processes."""
import fcntl,json,os,subprocess,time
from pathlib import Path
from board_batch import W,D

lock=(D/'locks/live-campaign-monitor.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
manifest=dict(pid=os.getpid(),start_ticks=Path('/proc/self/stat').read_text().split()[21],
              host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
              interval_seconds=300,no_device_or_process_queries=True,log=str(D/'live-campaign-monitor-20261107.log'))
(D/'live-campaign-monitor.json').write_text(json.dumps(manifest,indent=2)+'\n')
previous=None
while True:
    cad=json.loads((D/'C4-runtime-cad-state.json').read_text());results=tuple((str(p),p.stat().st_mtime_ns) for p in sorted((D/'runs').glob('*/result.json')))
    states=tuple((str(p),p.stat().st_mtime_ns) for p in sorted((D/'runs').glob('*/state.json')))
    continuation=json.loads((D/'fpga-continuation-state.json').read_text()) if (D/'fpga-continuation-state.json').exists() else {}
    fingerprint=(cad['status'],continuation.get('status'),continuation.get('stage'),results,states)
    if fingerprint!=previous:
        subprocess.run(['python3',str(W/'scripts/summarize_results.py')],check=True)
        subprocess.run(['python3',str(W/'scripts/publish_live.py')],check=True)
        previous=fingerprint
    time.sleep(300)
