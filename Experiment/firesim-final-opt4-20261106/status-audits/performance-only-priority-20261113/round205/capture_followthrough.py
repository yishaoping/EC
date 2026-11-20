#!/usr/bin/python3
"""Capture emitted physical progress without controlling the existing job."""
import datetime as dt
import hashlib
import json
from pathlib import Path
import re

A = Path(__file__).resolve().parent
D = A.parents[2]
S = D/'build-logs/Opt4-performance-only-support-r6-20261113'


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''):
            h.update(block)
    return h.hexdigest()


def ref(p):
    return dict(path=str(p), sha256=sha(p))


prior_path = A.parent/'round204/followthrough-audit.json'
prior = read(prior_path)
assert all(sha(p) == h for p, h in prior['artifacts'].items())
cad = read(S/'cad-state.json')
assert cad['hardware_commit'] == prior['hardware_commit']
assert cad['source_id'] == prior['source_id']
assert cad['status'] == 'RUNNING_IMPLEMENTATION'
assert not (S/'implementation-result.json').exists()
assert not (S/'timing_bitstream-result.json').exists()
assert not (S/'postopt-result.json').exists()
snapshot = A/'implementation-log-snapshot.log'
with snapshot.open('xb') as f:
    f.write((S/'implementation-attempt-1.log').read_bytes())
text = snapshot.read_text(errors='replace')
lines = text.splitlines()
assert not any(line.startswith('ERROR:') for line in lines)
assert 'Phase 2 SLR Crossing Optimization | Checksum:' in text
assert 'Phase 3 Fanout Optimization' in text
assert 'Optimized 228 nets or cells. Created 212 new cells' in text
assert not re.search(r'^phys_opt_design:.*Errors encountered', text, re.M)
phase = next(line for line in reversed(lines) if line.startswith('Phase '))
estimates = [line for line in lines if 'Estimated Timing Summary' in line]
latest_wns = float(re.search(r'WNS=([-+0-9.]+)', estimates[-1])[1])
row = dict(schema='ec-performance-only-round205-physical-progress/1',
    utc=dt.datetime.now(dt.timezone.utc).isoformat(),
    hardware_commit=prior['hardware_commit'], source_id=prior['source_id'],
    scope='actual_complete_shell_ongoing_phys_opt_not_final_routed_timing',
    stage='phys_opt_design', current_phase=phase,
    SLR_crossing_optimization_completed=True,
    SLR_pass_optimized_nets_or_cells=228, SLR_pass_created_cells=212,
    SLR_pass_moved_existing_cells=18, current_log_errors=[],
    adopted_placed_checkpoint=ref(prior_path), resources=prior['resources'],
    LUT_headroom=prior['LUT_headroom'],
    intermediate_estimated_WNS_ns=latest_wns,
    high_congestion_warning=prior['high_congestion_warning'],
    timing_scope='Intermediate estimate; final route/setup/hold/pulse/skew/coverage/DRC pending',
    artifacts={str(snapshot):sha(snapshot)},
    implementation_receipt_exists=False, timing_bitstream_receipt_exists=False,
    outer_result_exists=False, physical_timing_passed=False,
    no_new_jobs=True, no_live_inputs_modified=True, no_FPGA_IO=True)
with (A/'followthrough-audit.json').open('x') as f:
    json.dump(row, f, indent=2);f.write('\n')
print(json.dumps({k:v for k,v in row.items() if k not in ['artifacts','resources']}))
