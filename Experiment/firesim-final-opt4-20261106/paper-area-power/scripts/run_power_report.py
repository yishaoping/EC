#!/usr/bin/env python3
"""Low-priority, bounded report-only Vivado invocation on the private snapshot."""
from pathlib import Path
from datetime import datetime, timezone
import json
import os
import resource
import signal
import subprocess
import time

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / 'generated/placed'
OUT.mkdir(parents=True, exist_ok=True)
receipt = OUT / 'invocation.json'
assert not receipt.exists(), 'Preserve existing invocation; use a new revision for another run.'
memory = dict(line.split(':', 1) for line in Path('/proc/meminfo').read_text().splitlines())
available = int(memory['MemAvailable'].split()[0]) * 1024
load = os.getloadavg()
assert available > 192 * 1024**3 and load[0] < 128, (available, load)
argv = ['/tools/Xilinx/Vivado/2021.1/bin/vivado', '-mode', 'batch', '-nojournal', '-log', str(OUT / 'vivado.log'), '-source', str(ROOT / 'scripts/report_preroute_power.tcl')]
record = {'started_utc': datetime.now(timezone.utc).isoformat(), 'argv': argv, 'cwd': str(OUT), 'checkpoint': str(ROOT / 'checkpoints/design_1_wrapper_placed.dcp'), 'hardware_commit': '6fada307bb77be90b39720d3f95404fece0e431b', 'build': 'Opt4-performance-only-support-r6-20261113', 'purpose': 'read-only reports on private placed checkpoint; no synthesis/place/route', 'available_memory_bytes_before': available, 'load_before': load, 'cpu_affinity': [252, 253], 'nice': 19, 'max_threads': 2, 'address_space_limit_gib': 96, 'timeout_seconds': 1800}
receipt.write_text(json.dumps(record, indent=2) + '\n')
def limits():
    os.nice(19)
    os.sched_setaffinity(0, {252, 253})
    resource.setrlimit(resource.RLIMIT_AS, (96 * 1024**3, 96 * 1024**3))
env = os.environ.copy()
env['TMPDIR'] = str(OUT / 'tmp')
Path(env['TMPDIR']).mkdir(exist_ok=True)
start = time.monotonic()
with (OUT / 'console.log').open('w') as log:
    process = subprocess.Popen(argv, cwd=OUT, env=env, preexec_fn=limits, start_new_session=True, stdout=log, stderr=subprocess.STDOUT)
    try:
        record['returncode'] = process.wait(timeout=1800)
    except subprocess.TimeoutExpired:
        # Only this new private report session, never any existing CAD process.
        os.killpg(process.pid, signal.SIGTERM)
        try:
            process.wait(timeout=10)
        except subprocess.TimeoutExpired:
            os.killpg(process.pid, signal.SIGKILL)
            process.wait()
        record['status'] = 'REPORT_TIMEOUT'
        record['returncode'] = process.returncode
record['ended_utc'] = datetime.now(timezone.utc).isoformat()
record['wall_seconds'] = time.monotonic() - start
record['status'] = record.get('status', 'COMPLETE' if (OUT / 'reporting.complete').exists() and record.get('returncode') == 0 else 'FAILED_WITH_LOG')
receipt.write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps(record, indent=2))
