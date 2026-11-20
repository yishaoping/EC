#!/usr/bin/python3
"""Verify durable round publication and the independent morning collector."""
import datetime as dt
import hashlib
import json
from pathlib import Path

A = Path(__file__).resolve().parent
D = A.parents[2]
P = D/'performance-only-20261113'


def read(path):
    return json.loads(Path(path).read_text())


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def create(path, row):
    with path.open('x') as f:
        json.dump(row, f, indent=2)
        f.write('\n')


receipt_path = D/'area-sprint-20261112/round-00215.json'
receipt = read(receipt_path)
published = read(A/'publication.json')
owner = read(P/'ACTIVE_OWNER.json')
latest = read(D/'area-sprint-20261112/latest-round.json')
prototype = read(P/'LATEST.json')
policy = read(D/'unattended-opt4/campaign-policy.json')
assert receipt['round'] == latest['round'] == owner['latest_round']['round'] == 215
assert prototype['latest_round'] == latest == owner['latest_round']
assert latest['receipt_sha256'] == sha(receipt_path)
assert receipt['capacity_FIT'] and not receipt['full_PALIMPSEST']
assert receipt['prototype_area_LUT'] == 1023687 and receipt['LUT_headroom'] == 279993
assert receipt['intermediate_estimated_WNS_ns'] == -2.316
assert not receipt['physical_timing_passed'] and not receipt['runtime_certified']
assert not receipt['bitstream_exists'] and receipt['no_FPGA_IO']
assert receipt['launched_jobs'] == []
assert receipt['real_progress']['current_phase'] == 'Phase 18 Critical Cell Optimization'
assert receipt['real_progress']['whole_CAD_observation_seconds'] >= 600
assert owner['third_rewire_progress']['optimized_nets_or_cells'] == 38
assert owner['third_critical_cell_progress']['processed_unique_nets'] == 7
assert owner == policy['performance_only_priority_20261113']['active_owner']
assert policy['round215_performance_only_physical_optimization_progress_20261113'] == latest
for row in receipt['evidence']:
    assert sha(row['path']) == row['sha256'], row['path']
for key in ['fullshell_ledger', 'prototype_ledger']:
    row = receipt[key]
    assert sha(row['path']) == row['sha256']
assert published['ACTIVE_OWNER_sha256'] == sha(P/'ACTIVE_OWNER.json')
assert published['prototype_LATEST_sha256'] == sha(P/'LATEST.json')
assert published['campaign_policy_sha256'] == sha(D/'unattended-opt4/campaign-policy.json')
for key in ['hardware_commit', 'experiment_commit', 'functional_baseline', 'source_binding_sha256']:
    assert receipt[key] == read(D/'area-sprint-20261112/round-00214.json')[key]
if not (A/'publication-verification.json').exists():
    create(A/'publication-verification.json', dict(
        schema='ec-performance-only-round215-publication-verification/1',
        utc=dt.datetime.now(dt.timezone.utc).isoformat(), round=215,
        receipt_sha256=sha(receipt_path), exact_evidence_hashes_verified=True,
        ledgers_unchanged=True, source_identity_unchanged=True, FPGA_IO=False,
        verifier_sha256=sha(__file__)))

morning = read(D/'area-sprint-20261112/latest.json')
assert morning['latest_round_evidence'] == latest, 'independent collector has not published round215 yet'
assert receipt['summary'] in (D/'area-sprint-20261112/LATEST.md').read_text()
create(A/'morning-publication-verification.json', dict(
    schema='ec-performance-only-round215-independent-morning-publication/1',
    utc=dt.datetime.now(dt.timezone.utc).isoformat(),
    collector_updated_utc=morning['updated_utc'], latest_round=215,
    latest_json_sha256=sha(D/'area-sprint-20261112/latest.json'),
    LATEST_md_sha256=sha(D/'area-sprint-20261112/LATEST.md'),
    collector_restarted=False, FPGA_IO=False))
print(json.dumps(dict(round=215, exact_publication_verified=True,
    independent_morning_publication_verified=True, FPGA_IO=False)))
