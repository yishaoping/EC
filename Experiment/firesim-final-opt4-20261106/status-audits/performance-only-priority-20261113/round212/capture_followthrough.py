#!/usr/bin/python3
"""Capture phase-bounded, emitted physical progress without CAD or device control."""
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


def ref(p):
    return dict(path=str(p), sha256=sha(p))


prior_path = A.parent/'round211/followthrough-audit.json'
prior = read(prior_path)
assert all(sha(p) == h for p, h in prior['artifacts'].items())
cad = read(S/'cad-state.json')
assert cad['hardware_commit'] == prior['hardware_commit']
assert cad['source_id'] == prior['source_id']
assert cad['status'] == 'RUNNING_IMPLEMENTATION'
receipts = {name: (S/name).exists() for name in [
    'implementation-result.json', 'timing_bitstream-result.json', 'postopt-result.json']}
assert not any(receipts.values()), 'adopt actual completed output before ongoing progress'
snapshot = A/'implementation-log-snapshot.log'
with snapshot.open('xb') as f:
    f.write((S/'implementation-attempt-1.log').read_bytes())
text = snapshot.read_text(errors='replace')
errors = re.findall(r'^ERROR:.*$', text, re.M)
assert not errors
assert not re.search(r'^phys_opt_design:.*Errors encountered', text, re.M)
# The last initialization belongs to the standalone post-placement phys_opt_design.
# Partition each phase at the next start so subsequent passes cannot inflate counts.
physical = text[text.rindex('Phase 1 Physical Synthesis Initialization\n'):]
starts = list(re.finditer(r'^Phase (\d+) ([^\n|]+)\n', physical, re.M))
blocks = {}
completed = []
passes = {}
for i, match in enumerate(starts):
    number, name = int(match[1]), match[2].strip()
    block = physical[match.end(): starts[i+1].start() if i+1 < len(starts) else len(physical)]
    blocks[number] = block
    checksum = re.search(r'^Phase '+str(number)+' '+re.escape(name)+r' \| Checksum: (\w+)$', block, re.M)
    if not checksum:
        continue
    counts = re.findall(r'End \d+ Pass\. Optimized (\d+) nets? or cells?\. Created (\d+) new cells?, deleted (\d+) existing cells? and moved (\d+) existing cells?', block)
    if counts:
        optimized, created, deleted, moved = map(int, counts[-1])
        passes[name] = passes.get(name, 0)+1
        completed.append(dict(phase=name, phase_number=number, pass_number=passes[name],
            optimized_nets_or_cells=optimized, created_cells=created, deleted_cells=deleted,
            moved_existing_cells=moved, completion_checksum=checksum[1]))

assert any(x['phase_number'] == 11 and x['optimized_nets_or_cells'] == 20
    and x['created_cells'] == 13 and x['moved_existing_cells'] == 0 for x in completed)
assert starts[-1][1] == '12' and starts[-1][2] == 'Critical Cell Optimization'


def critical(number):
    block = blocks[number]
    identified = re.findall(r'Identified (\d+) candidate nets for critical-cell optimization\.', block)
    assert len(identified) == 1
    replicated = re.findall(r'^INFO: \[Physopt [^\]]+\] Processed net (.+)\. Replicated (\d+) times\.', block, re.M)
    declined = re.findall(r'^INFO: \[Physopt [^\]]+\] Net (.+) was not replicated\.', block, re.M)
    return dict(phase_number=number, identified_candidates=int(identified[0]),
        replicated_nets=[dict(net=net, replications=int(n)) for net, n in replicated],
        declined_nets=declined,
        processed_unique_nets=len({net for net, _ in replicated} | set(declined)),
        replication_outcome_lines=len(replicated), nonreplication_outcome_lines=len(declined),
        phase_completed=bool(re.search(r'^Phase '+str(number)+r' Critical Cell Optimization \| Checksum:', block, re.M)))


estimates = [dict(WNS_ns=float(a), TNS_ns=float(b)) for a, b in re.findall(
    r'Estimated Timing Summary \| WNS=([-+0-9.]+) \| TNS=([-+0-9.]+)', physical)]
row = dict(schema='ec-performance-only-round212-physical-progress/1',
    utc=dt.datetime.now(dt.timezone.utc).isoformat(), hardware_commit=prior['hardware_commit'],
    source_id=prior['source_id'], scope='actual_complete_shell_ongoing_phys_opt_not_final_routed_timing',
    stage='phys_opt_design', current_phase='Phase 12 Critical Cell Optimization',
    completed_physical_optimization_phases=completed,
    critical_cell_progress=critical(7), second_critical_cell_progress=critical(12),
    second_rewire_progress=dict(signal_push_started=True, phase_completed=True,
        optimized_nets=20, created_cells=13, completion_checksum='14eb45519'),
    phase_count_scope='Each phase is bounded by its next start; first and second critical-cell passes are counted separately.',
    current_log_errors=errors, prior_physical_progress=ref(prior_path),
    adopted_placed_checkpoint=prior['adopted_placed_checkpoint'],
    resources=prior['resources'], LUT_headroom=prior['LUT_headroom'],
    intermediate_estimated_WNS_ns=estimates[-1]['WNS_ns'],
    intermediate_estimated_TNS_ns=estimates[-1]['TNS_ns'],
    intermediate_timing_estimates=estimates, high_congestion_warning=prior['high_congestion_warning'],
    timing_scope='Intermediate estimate; final route/setup/hold/pulse/skew/coverage/DRC pending',
    artifacts={str(snapshot):sha(snapshot)}, receipts=receipts, physical_timing_passed=False,
    no_new_jobs=True, no_live_inputs_modified=True, no_FPGA_IO=True)
with (A/'followthrough-audit.json').open('x') as f:
    json.dump(row, f, indent=2); f.write('\n')
print(json.dumps({k:row[k] for k in ['utc','current_phase','second_rewire_progress',
    'second_critical_cell_progress','intermediate_estimated_WNS_ns','intermediate_estimated_TNS_ns']}))
