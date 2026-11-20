#!/usr/bin/python3
"""Classify a saved Vivado log by command context, never by echoed Tcl."""
import hashlib
import json
import re
from pathlib import Path


def classify(text):
    commands, snapshots, intermediate = [], [], []
    current = None
    bitstream_marker = False
    phase = None
    for line in text.splitlines():
        if line.startswith('Command: '):
            current = dict(command=line[len('Command: '):], completed=False)
            commands.append(current)
        if line == 'route_design completed successfully':
            if current and current['command'].startswith('route_design '):
                current['completed'] = True
        match = re.fullmatch(r'EC_HOST40_SHELL_SNAPSHOT tag=(\S+) WNS=([-0-9.]+) WHS=([-0-9.]+)', line)
        if match:
            snapshots.append(dict(tag=match[1], WNS_ns=float(match[2]), WHS_ns=float(match[3])))
        if line.startswith('INFO: [Route 35-416] Intermediate Timing Summary'):
            intermediate.append(line)
        if re.match(r'^Phase [0-9]', line):
            phase = line
        if re.fullmatch(r'EC_SVB_HOST40_BITSTREAM_COMPLETE WNS=[-0-9.]+ WHS=[-0-9.]+', line):
            bitstream_marker = True
    unroutes = [c for c in commands if c['command'].startswith('route_design ') and '-unroute' in c['command'].split()]
    routes = [c for c in commands if c['command'].startswith('route_design ') and '-unroute' not in c['command'].split()]
    return dict(schema='ec-saved-r5-command-context/1',
        route_commands=routes, unroute_commands=unroutes,
        completed_unroutes=sum(c['completed'] for c in unroutes),
        completed_routes=sum(c['completed'] for c in routes),
        latest_route_phase=phase,
        snapshots=snapshots,
        latest_intermediate_timing=intermediate[-1] if intermediate else None,
        bitstream_completion_marker=bitstream_marker,
        certification_inferred=False, completed_hashed_result_still_required=True)


def main():
    root = Path(__file__).resolve().parent
    cases = [
        ('unroute_success_only', 'Command: route_design -unroute\nroute_design completed successfully', 0, 1, False),
        ('phase7_and_8_are_not_completion', 'Command: route_design -directive Explore -tns_cleanup\nPhase 7 Route finalize\n  Number of Failed Nets = 0\n Verification completed successfully\nPhase 10.2 Hold Fix Iter', 0, 0, False),
        ('echoed_tcl_is_not_output', '# puts "EC_SVB_HOST40_BITSTREAM_COMPLETE WNS=0.1 WHS=0.1"\n# EC_HOST40_SHELL_SNAPSHOT tag=final WNS=0.1 WHS=0.1', 0, 0, False),
        ('actual_route_completion', 'Command: route_design -directive Explore -tns_cleanup\nroute_design completed successfully', 1, 0, False),
        ('marker_still_needs_result', 'EC_SVB_HOST40_BITSTREAM_COMPLETE WNS=0.1 WHS=0.1', 0, 0, True),
    ]
    validations = []
    for name, text, routes, unroutes, marker in cases:
        actual = classify(text)
        assert actual['completed_routes'] == routes
        assert actual['completed_unroutes'] == unroutes
        assert actual['bitstream_completion_marker'] == marker
        assert not actual['certification_inferred']
        validations.append(dict(case=name, passed=True))
    source = root / 'r5-bounded.log'
    result = classify(source.read_text())
    result.update(source=str(source), source_sha256=hashlib.sha256(source.read_bytes()).hexdigest())
    assert result['completed_unroutes'] == 1 and result['completed_routes'] == 0
    assert not any(s['tag'] in ['routed', 'final'] for s in result['snapshots'])
    assert not result['bitstream_completion_marker']
    for name, value in [('phase-classification.json', result),
                        ('classification-validation.json', dict(cases=validations, all_passed=True, no_CAD_executed=True))]:
        path = root / name
        assert not path.exists()
        path.write_text(json.dumps(value, indent=2) + '\n')
    print(json.dumps(dict(completed_routes=result['completed_routes'],
        completed_unroutes=result['completed_unroutes'], latest_phase=result['latest_route_phase'],
        offline_cases=len(validations), all_passed=True)))


if __name__ == '__main__':
    main()
