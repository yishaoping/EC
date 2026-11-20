#!/usr/bin/env python3
"""Pin completed I/J evidence. Read-only toward CAD, services and devices."""
import collections
import datetime
import difflib
import hashlib
import json
import pathlib
import re
import shutil

B = pathlib.Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = pathlib.Path('/data1/gzh/EC/firesim/final-opt4-20261106/candidates')
A = pathlib.Path(__file__).resolve().parent
R6 = B/'cycleprecise-svb-host40-shell-recovery-r6-20261112'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
SID = 'b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f'


def sha(path):
    h = hashlib.sha256()
    with pathlib.Path(path).open('rb') as f:
        for chunk in iter(lambda: f.read(4*1024*1024), b''):
            h.update(chunk)
    return h.hexdigest()


def save(name, data):
    text = json.dumps(data, indent=2, sort_keys=True)+'\n'
    path = A/name
    if path.exists():
        assert path.read_text() == text, 'existing evidence differs: '+name
        return
    with path.open('x') as f:
        f.write(text)


assert not (A/'completed-results.json').exists(), 'immutable evidence already captured'
completed = {}
for letter, mode in [('I', 'I-postroute-clock-skew'), ('J', 'J-postroute-targeted-delay-reroute')]:
    out = R6/mode
    r = json.loads((out/'result.json').read_text())
    assert r['functional_baseline'] == BASE and r['source_id'] == SID
    assert r['status'] == 'FAILED_WITH_EVIDENCE' and r['returncode'] == 1
    assert not r['target_rtl_changed'] and not r['fpga_access'] and not r['complete_opt4']
    assert r['bitstream'] is None and r['bitstream_sha256'] is None
    assert not (out/'complete.json').exists() and not (out/'original-svb-host40.bit').exists()
    files = {}
    for path, expected in r['outputs'].items():
        p = pathlib.Path(path)
        before = p.stat()
        actual = sha(p)
        after = p.stat()
        assert actual == expected, path
        assert (before.st_size, before.st_mtime_ns) == (after.st_size, after.st_mtime_ns), path
        row = dict(source=path, sha256=actual, bytes=after.st_size, mtime_ns=after.st_mtime_ns)
        if p.suffix != '.dcp':
            dest = A/(letter+'-'+p.name)
            shutil.copyfile(p, dest)
            assert sha(dest) == actual
            row['copy'] = str(dest)
        files[p.name] = row
    dest = A/(letter+'-result.json')
    shutil.copyfile(out/'result.json', dest)
    files['result.json'] = dict(source=str(out/'result.json'), copy=str(dest), sha256=sha(dest))
    completed[letter] = dict(result={k: v for k, v in r.items() if k != 'outputs'}, files=files)

i = R6/'I-postroute-clock-skew'
expected_timing = dict(wns=-0.017, tns=-0.387, setup_failing=42, whs=0.001, ths=0.0, hold_failing=0)
assert completed['I']['result']['timing'] == expected_timing
text = (i/'final-timing.rpt').read_text()
m = re.search(r'WNS\(ns\).*?\n\s*[-\s]+\n\s*([-\d.]+)\s+([-\d.]+)\s+(\d+)\s+\d+\s+([-\d.]+)\s+([-\d.]+)\s+(\d+)', text)
assert m and [float(m[1]), float(m[2]), int(m[3]), float(m[4]), float(m[5]), int(m[6])] == [-0.017, -0.387, 42, 0.001, 0.0, 0]
negative = (i/'negative-setup-final.rpt').read_text()
paths = {}
for label in ['Source', 'Destination', 'Path Group', 'Path Type', 'Requirement', 'Logic Levels']:
    vals = re.findall(r'^\s*'+re.escape(label)+r'\s*:\s*(.*)$', negative, re.M)
    assert len(vals) == 42, label
    paths[label] = dict(count=len(vals), distribution=dict(collections.Counter(vals)))
assert paths['Path Group']['distribution'] == {'GTYE4_CHANNEL_TXOUTCLK[3]_3': 42}
assert all(x.startswith('design_1_i/xdma_0/') for k in ['Source', 'Destination'] for x in paths[k]['distribution'])
save('I-failing-paths.json', paths)
route = (i/'route-final.rpt').read_text()
counts = {k: int(re.search(re.escape(k)+r'\.+\s*:\s*(\d+)', route)[1]) for k in ['# of routable nets', '# of fully routed nets', '# of nets with routing errors']}
assert counts == {'# of routable nets': 255876, '# of fully routed nets': 255876, '# of nets with routing errors': 0}
checks = dict((k, int(v)) for k, v in re.findall(r'checking (\w+) \((\d+)\)', (i/'check-timing.rpt').read_text()))
assert checks['no_clock'] == checks['unconstrained_internal_endpoints'] == 0
drc = re.findall(r'^\|\s*(\S+)\s*\|\s*(Warning|Error|Critical Warning)\s*\|.*?\|\s*(\d+)\s*\|', (i/'drc-final.rpt').read_text(), re.M)
assert drc and all(x[1] == 'Warning' for x in drc) and sum(int(x[2]) for x in drc) == 49
assert 'setup/hold gate failed; candidate retained for next strategy' in (i/'vivado.log').read_text()
completed['I'].update(route_counts=counts, check_timing=checks, drc_summary=drc,
    failure=dict(symptom='PROVEN_42_FINAL_SETUP_FAILURES', blocking_condition='PROVEN_SETUP_GATE_REJECTED',
        upstream_causal_trigger='UNPROVEN_PHYSICAL_PATH_TIMING_REMAINS_NEGATIVE', downstream_amplifier='UNPROVEN'))

j = R6/'J-postroute-targeted-delay-reroute'
log = (j/'vivado.log').read_text()
assert "ERROR: [Common 17-54] The object 'timing_path' does not have a property 'POINTS'." in log
assert completed['J']['result']['timing'] is None
assert not re.search(r'^EC_R6_SELECTED_CRITICAL_DATA_NETS count=', log, re.M)
assert not (j/'selected-critical-data-nets.txt').exists()
assert not (j/'physical.dcp').exists() and not (j/'final.dcp').exists()
sealed = json.loads((j/'sealed-inputs.json').read_text())
assert sha(j/'sealed-source.dcp') == completed['I']['files']['routed.dcp']['sha256']
completed['J'].update(failure=dict(symptom='PROVEN_TIMING_PATH_POINTS_PROPERTY_REJECTED',
    blocking_condition='PROVEN_TCL_EXCEPTION_BEFORE_NET_SELECTION_OR_UNROUTE',
    upstream_causal_trigger='PROVEN_UNSUPPORTED_VIVADO_2021_1_PROPERTY_IN_SELECTOR', downstream_amplifier='NONE_OBSERVED'),
    sealed_source_is_I_routed_checkpoint=True, final_timing_available=False)
save('completed-results.json', dict(schema='ec-opt4-round138-completed-r6-results/1', round=138,
    utc=datetime.datetime.now(datetime.timezone.utc).isoformat(), functional_baseline=BASE, source_id=SID,
    completed=completed, certified_bitstream=False, FPGA_samples=0, FPGA_operations=[], process_signals=[]))

# Reuse the previous source validation; do not reread all 100 bound inputs.
prior_path = B/'status-audits/round134-r6-installer-scope-repair-20261112/r6-source-verification.json'
prior = json.loads(prior_path.read_text())
assert all(sha(p) == h for p, h in prior['sources'].items())
r7 = C/'svb-routed-conditional-r7-20261112'
pins = json.loads((r7/'inputs.json').read_text())
local = {p: h for p, h in pins['files'].items() if pathlib.Path(p).parent == r7}
assert local and all(sha(p) == h for p, h in local.items())
save('source-continuity.json', dict(status='UNCHANGED_BOUND_R6_R7_SOURCES',
    prior_r6_validation=str(prior_path), prior_r6_validation_sha256=sha(prior_path),
    r6_source_count=len(prior['sources']), r7_local_sources=local,
    r7_inputs_sha256=sha(r7/'inputs.json'), full_bound_input_revalidation_repeated=False, live_bound_edits=[]))

# Keep a separate, unapplied minimal repair for a future independently versioned
# successor. Actual TIMING_POINTS/PIN enumeration must pass on the saved DCP.
template = (r7/'recover.tcl.in').read_text()
assert template.count('get_property POINTS $path') == 2
repair = template.replace('get_property POINTS $path', 'get_property TIMING_POINTS $path')
assert repair.replace('get_property TIMING_POINTS $path', 'get_property POINTS $path') == template
(A/'recover-timing-points.preview.tcl.in').write_text(repair)
(A/'timing-points-api-repair.unapplied.patch').write_text(''.join(difflib.unified_diff(
    template.splitlines(keepends=True), repair.splitlines(keepends=True),
    fromfile=str(r7/'recover.tcl.in'), tofile='future-independent-successor/recover.tcl.in')))
save('api-repair-plan.json', dict(status='PREPARED_UNAPPLIED_NOT_TOOL_VALIDATED_NOT_ADMITTED',
    observed_failure=str(A/'J-vivado.log'), current_r7_template=str(r7/'recover.tcl.in'),
    current_r7_template_sha256=sha(r7/'recover.tcl.in'), affected_r7_strategy='M-postroute-critical-SRL-output-reroute',
    K_L_affected_by_this_selector=False, live_source_edits=[], process_signals=[], new_jobs=[],
    preview=str(A/'recover-timing-points.preview.tcl.in'), preview_sha256=sha(A/'recover-timing-points.preview.tcl.in'),
    change='Two property tokens POINTS -> TIMING_POINTS only; all selection bounds, physical commands, clocks and gates identical',
    required_before_use=['Confirm TIMING_POINTS and timing_point PIN using actual Vivado 2021.1 on a saved routed DCP',
        'Independently version and pin any successor; preserve live r7 inputs and existing K/L',
        'Wait exhausted predecessor, exact dead identities and empty cgroup; same lock/resources and certificate/replay gates'],
    current_r7_strategy_M_failure='STRONGLY_SUPPORTED_IF_REACHED_SAME_API_CALL_AS_PROVEN_J_FAILURE'))
print(json.dumps(dict(status='PINNED_I_FINAL_FAILURE_J_API_FAILURE', completed_results_sha256=sha(A/'completed-results.json'),
    I_final_timing=expected_timing, I_final_checkpoint_sha256=completed['I']['files']['final.dcp']['sha256'],
    J_failure='POINTS_UNSUPPORTED_BEFORE_UNROUTE', unapplied_repair='NOT_TOOL_VALIDATED', live_source_changes=[])))
