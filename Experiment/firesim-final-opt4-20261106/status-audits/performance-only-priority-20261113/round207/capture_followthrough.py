#!/usr/bin/python3
"""Preserve actual emitted physical progress; no CAD or device control."""
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
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


prior_path = A.parent/'round206/followthrough-audit.json'
prior = read(prior_path)
assert all(sha(p) == h for p, h in prior['artifacts'].items())
cad = read(S/'cad-state.json')
assert cad['hardware_commit'] == prior['hardware_commit']
assert cad['source_id'] == prior['source_id']
assert cad['status'] == 'RUNNING_IMPLEMENTATION'
receipts = {name: (S/name).exists() for name in [
    'implementation-result.json', 'timing_bitstream-result.json', 'postopt-result.json']}
assert not any(receipts.values()), 'adopt completed output before publishing ongoing progress'
snapshot = A/'implementation-log-snapshot.log'
with snapshot.open('xb') as f:
    f.write((S/'implementation-attempt-1.log').read_bytes())
text = snapshot.read_text(errors='replace')
lines = text.splitlines()
assert not any(line.startswith('ERROR:') for line in lines)
assert not re.search(r'^phys_opt_design:.*Errors encountered', text, re.M)
completed = []
for name, optimized, created, moved in [
    ('SLR Crossing Optimization', 228, 212, 18),
    ('Fanout Optimization', 6, 0, 0),
    ('Single Cell Placement Optimization', 127, 0, 127),
    ('Multi Cell Placement Optimization', 43, 0, 93),
    ('Rewire', 63, 29, 0),
]:
    assert re.search(r'^Phase \d+ '+re.escape(name)+r' \| Checksum:', text, re.M)
    assert (f'Optimized {optimized} nets or cells. Created {created} new cell' in text)
    completed.append(dict(phase=name, optimized_nets_or_cells=optimized,
                          created_cells=created, moved_existing_cells=moved))
phase = next(line for line in reversed(lines) if line.startswith('Phase '))
assert 'Phase 7 Critical Cell Optimization' in text
assert 'Identified 30 candidate nets for critical-cell optimization.' in text
estimates = [dict(WNS_ns=float(a), TNS_ns=float(b)) for a, b in re.findall(
    r'Estimated Timing Summary \| WNS=([-+0-9.]+) \| TNS=([-+0-9.]+)', text)]
row = dict(schema='ec-performance-only-round207-physical-progress/1',
    utc=dt.datetime.now(dt.timezone.utc).isoformat(),
    hardware_commit=prior['hardware_commit'], source_id=prior['source_id'],
    scope='actual_complete_shell_ongoing_phys_opt_not_final_routed_timing',
    stage='phys_opt_design', current_phase=phase,
    completed_physical_optimization_phases=completed,
    current_log_errors=[],
    prior_physical_progress=dict(path=str(prior_path), sha256=sha(prior_path)),
    adopted_placed_checkpoint=prior['adopted_placed_checkpoint'],
    resources=prior['resources'], LUT_headroom=prior['LUT_headroom'],
    intermediate_estimated_WNS_ns=estimates[-1]['WNS_ns'],
    intermediate_estimated_TNS_ns=estimates[-1]['TNS_ns'],
    intermediate_timing_estimates=estimates,
    high_congestion_warning=prior['high_congestion_warning'],
    timing_scope='Intermediate estimate; final route/setup/hold/pulse/skew/coverage/DRC pending',
    artifacts={str(snapshot):sha(snapshot)}, receipts=receipts,
    physical_timing_passed=False, no_new_jobs=True,
    no_live_inputs_modified=True, no_FPGA_IO=True)
with (A/'followthrough-audit.json').open('x') as f:
    json.dump(row, f, indent=2);f.write('\n')
print(json.dumps({k:v for k,v in row.items() if k not in [
    'artifacts', 'resources', 'intermediate_timing_estimates']}))
