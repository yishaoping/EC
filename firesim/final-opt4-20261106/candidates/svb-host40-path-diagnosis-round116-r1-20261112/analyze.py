#!/usr/bin/python3
"""Snapshot and diagnose existing host40 STA reports. Never invokes CAD or FPGA."""
import csv
import datetime
import hashlib
import io
import json
import os
from pathlib import Path
import re

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
OUT = D / 'build-logs/Opt4-svb-host40-path-diagnosis-round116-r1-20261112'
PROBE = D / 'cycleprecise-svb-hostclock-probe-r2-20261112'
PHYSICAL = D / 'cycleprecise-svb-host40-shell-recovery-r2-20261112/A-shell-routing-placement'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
FIELDS = ['WNS(ns)', 'TNS(ns)', 'TNS Failing Endpoints', 'TNS Total Endpoints',
          'WHS(ns)', 'THS(ns)', 'THS Failing Endpoints', 'THS Total Endpoints',
          'WPWS(ns)', 'TPWS(ns)', 'TPWS Failing Endpoints', 'TPWS Total Endpoints']


def digest(data):
    return hashlib.sha256(data).hexdigest()


def atomic(path, data):
    tmp = path.with_name(path.name + '.tmp-' + str(os.getpid()))
    with tmp.open('xb') as f:
        f.write(data)
        f.flush()
        os.fsync(f.fileno())
    os.replace(tmp, path)


def save(path, obj):
    atomic(path, (json.dumps(obj, indent=2, sort_keys=True) + '\n').encode())


def snapshot(path, name, expected=None):
    with path.open('rb') as f:
        before = os.fstat(f.fileno())
        data = f.read()
        after = os.fstat(f.fileno())
    current = path.stat()
    key = lambda s: (s.st_dev, s.st_ino, s.st_size, s.st_mtime_ns)
    assert key(before) == key(after) == key(current), ('report changed during read', str(path))
    sha = digest(data)
    if expected is not None:
        assert sha == expected, ('bound report hash mismatch', str(path))
    atomic(OUT / name, data)
    return data.decode(), dict(path=str(path), snapshot=str(OUT / name), sha256=sha,
                               bytes=len(data), mtime_ns=after.st_mtime_ns,
                               existing_receipt_sha256=expected)


def section(text, title):
    match = re.search(r'^\| ' + re.escape(title) + r'\s*$', text, re.M)
    assert match, ('missing report section', title)
    following = re.search(r'^\| [A-Za-z].*$', text[match.end():], re.M)
    assert following, ('section end missing', title)
    return text[match.end():match.end() + following.start()]


def columns(text, fields):
    lines = text.splitlines()
    headers = [(i, line) for i, line in enumerate(lines) if all(f in line for f in fields)]
    assert len(headers) == 1, ('missing/duplicate header', fields)
    i, header = headers[0]
    # Vivado right-aligns numeric cells. Use the end of each header label,
    # not whitespace splitting, so blank setup/hold columns cannot shift.
    ends = [header.index(f) + len(f) for f in fields]
    rows = []
    for line in lines[i + 1:]:
        if not line.strip() or set(line.strip()) <= {'-', ' '}:
            continue
        if len(line) < ends[0] or not re.search(r'\d', line[ends[0] - len(fields[0]):]):
            continue
        label_end = ends[0] - len(fields[0])
        labels = line[:label_end].rstrip()
        values = {}
        start = label_end
        for field, end in zip(fields, ends):
            value = line[start:end].strip()
            assert not value or re.fullmatch(r'-?\d+(?:\.\d+)?', value), (field, value, line)
            values[field] = None if not value else (int(value) if 'Endpoints' in field else float(value))
            start = end
        assert not line[start:].strip(), ('unexpected trailing columns', line[start:])
        rows.append((labels, values))
    return rows


def parse(text):
    assert '| Design            : design_1_wrapper' in text
    assert '| Tool Version      : Vivado v.2021.1' in text
    summary_rows = columns(section(text, 'Design Timing Summary'), FIELDS)
    assert len(summary_rows) == 1
    global_summary = summary_rows[0][1]
    groups = []
    for title, fields in [('Intra Clock Table', FIELDS), ('Inter Clock Table', FIELDS[:8]),
                          ('Other Path Groups Table', FIELDS)]:
        for labels, values in columns(section(text, title), fields):
            names = re.split(r'\s{2,}', labels.strip())
            assert len(names) == (2 if title == 'Inter Clock Table' else 1), (title, names)
            groups.append(dict(table=title, source_clock=names[0],
                               destination_clock=names[-1], **values))
    finite_setup = [g['WNS(ns)'] for g in groups if g.get('WNS(ns)') is not None]
    finite_hold = [g['WHS(ns)'] for g in groups if g.get('WHS(ns)') is not None]
    assert min(finite_setup) == global_summary['WNS(ns)']
    assert min(finite_hold) == global_summary['WHS(ns)']
    pulse = [g['WPWS(ns)'] for g in groups if g.get('WPWS(ns)') is not None]
    assert min(pulse) == global_summary['WPWS(ns)']
    clock_text = section(text, 'Clock Summary')
    clocks = {}
    for line in clock_text.splitlines():
        m = re.match(r'^\s*(\S+)\s+\{[-\d.]+\s+[-\d.]+\}\s+([\d.]+)\s+([\d.]+)\s*$', line)
        if m:
            assert m[1] not in clocks
            clocks[m[1]] = float(m[2])
    assert len(clocks) == 66, ('clock count', len(clocks))
    paths = []
    matches = list(re.finditer(r'^Slack(?: \((?:MET|VIOLATED)\))?\s*:\s*([-\d.]+|inf)(?:ns)?', text, re.M))
    for i, match in enumerate(matches):
        block = text[match.start():matches[i + 1].start() if i + 1 < len(matches) else len(text)]
        def required(pattern):
            m = re.search(pattern, block, re.M)
            assert m, ('path field missing', pattern)
            return m[1].strip()
        source = required(r'^  Source:\s+(.+)$')
        destination = required(r'^  Destination:\s+(.+)$')
        kind = required(r'^  Path Type:\s+(.+)$')
        group = required(r'^  Path Group:\s+(.+)$')
        data_delay = float(required(r'^  Data Path Delay:\s+([\d.]+)ns'))
        route = re.search(r'^  Data Path Delay:.*route ([\d.]+)ns \(([\d.]+)%\)', block, re.M)
        assert route
        data_segments = re.split(r'^  -+\s+-+\s*$', block, flags=re.M)
        assert len(data_segments) >= 4
        nets = []
        for net in re.finditer(r'net \(fo=(\d+), ([^)]+)\)\s+([-\d.]+)\s+([-\d.]+)\s+(.+)', data_segments[2]):
            nets.append(dict(fanout=int(net[1]), route_status=net[2], delay_ns=float(net[3]), net=net[5].strip()))
        paths.append(dict(slack_ns=None if match[1] == 'inf' else float(match[1]), source=source,
                          destination=destination, path_type=kind, path_group=group,
                          data_delay_ns=data_delay, route_delay_ns=float(route[1]), route_percent=float(route[2]),
                          logic_levels=int(required(r'^  Logic Levels:\s+(\d+)')),
                          data_nets=nets))
    assert paths
    return dict(summary=global_summary, groups=groups, clocks=clocks, paths=paths)


def csv_write(path, fields, rows):
    buf = io.StringIO(newline='')
    writer = csv.DictWriter(buf, fieldnames=fields, extrasaction='ignore')
    writer.writeheader()
    writer.writerows(rows)
    atomic(path, buf.getvalue().encode())


def main():
    policy = json.loads((D / 'unattended-opt4/campaign-policy.json').read_text())
    assert policy['functional_baseline_commit'] == BASE and policy['native_paused']
    assert policy['area_equivalence_only'] and not policy['functional_extensions_allowed']
    assert not OUT.exists(), 'immutable diagnostic already exists; use a new version'
    OUT.mkdir()
    probe = json.loads((PROBE / 'result.json').read_text())
    assert probe['status'] == 'COMPLETE_DIAGNOSTIC_NOT_CERTIFIED'
    assert probe['functional_baseline'] == BASE
    old_path = PROBE / 'after-timing.rpt'
    old_text, old_binding = snapshot(old_path, 'probe-after-timing.rpt', probe['outputs'][str(old_path)])
    current_text, current_binding = snapshot(PHYSICAL / 'physical-timing.rpt', 'A-physical-timing.rpt')
    selected_text, selected_binding = snapshot(PHYSICAL / 'shell-negative-q-before.tsv', 'A-shell-negative-q-before.tsv')
    # A completed snapshot marker binds the named checkpoint/report stage.
    # A live router log is never treated as a sealed result or certificate.
    with (PHYSICAL / 'recovery.log').open('rb') as f:
        prefix = f.read(128 * 1024)
    marker = re.search(rb'^EC_HOST40_SHELL_SNAPSHOT tag=physical WNS=([-\d.]+) WHS=([-\d.]+)$', prefix, re.M)
    assert marker, 'physical snapshot has not finished'
    old, current = parse(old_text), parse(current_text)
    assert current['summary']['WNS(ns)'] == float(marker[1])
    assert current['summary']['WHS(ns)'] == float(marker[2])
    assert old['clocks'] == current['clocks'], 'clock periods differ between snapshots'
    selected = list(csv.DictReader(io.StringIO(selected_text), delimiter='\t'))
    assert selected and set(selected[0]) == {'cell', 'ref', 'net', 'fanout', 'path_slack'}
    assert len({r['net'] for r in selected}) == len(selected)
    selected_cells = {row['cell'] for row in selected}
    negative_paths = []
    for path in current['paths']:
        if path['slack_ns'] is None or path['slack_ns'] >= 0 or not path['path_type'].startswith('Setup'):
            continue
        row = dict(path)
        row['start_cell_in_existing_query'] = path['source'].rsplit('/', 1)[0] in selected_cells
        net = max(path['data_nets'], key=lambda n: n['delay_ns']) if path['data_nets'] else {}
        row.update(dominant_net=net.get('net'), dominant_net_fanout=net.get('fanout'), dominant_net_delay_ns=net.get('delay_ns'))
        negative_paths.append(row)
    negative_paths.sort(key=lambda p: p['slack_ns'])
    negative_groups = [g for g in current['groups'] if g.get('WNS(ns)') is not None and g['WNS(ns)'] < 0]
    target = [g for g in current['groups'] if g['table'] == 'Intra Clock Table' and g['source_clock'] == 'clk_out1_design_1_clk_wiz_0_0']
    assert len(target) == 1
    result = dict(schema='ec-host40-saved-path-diagnosis/1',
        status='COMPLETE_REPORT_BOUND_PHYSICAL_STAGE_DIAGNOSIS_NOT_CERTIFICATION',
        functional_baseline=BASE, created_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
        script_sha256=digest(Path(__file__).read_bytes()), inputs=[old_binding, current_binding, selected_binding],
        before_summary=old['summary'], A_physical_summary=current['summary'],
        delta={k: current['summary'][k] - old['summary'][k] for k in FIELDS},
        unchanged_clock_periods=current['clocks'], target_host_clock=target[0],
        negative_clock_groups=negative_groups, negative_reported_setup_paths=negative_paths,
        all_reported_paths=current['paths'], existing_selected_q_nets=selected,
        path_scope='Only representative paths emitted by report_timing_summary, not a census of all failing endpoints.',
        table_scope='Clock-group endpoint counts/TNS can overlap. They are retained as report rows and are never summed into a whole-design count.',
        causal_findings=dict(symptom='Setup timing still fails in saved A physical stage.',
            immediate_blocker='Negative setup slack; final routed timing/DRC/pulse/skew certificate still absent.',
            upstream_trigger='Reported negative representative setup paths are shell routes; high-fanout net delay is measured per path.',
            amplifier='Route delay dominance and load fanout are measured; physical replication benefit remains unproven.'),
        no_cad=True, no_fpga_io=True, no_live_input_changed=True, physical_certificate=False,
        next_action='Let live A/B and conditional C/D finish. Use exact emitted path names and safe-cell query evidence for any versioned failure recovery; retain all clock/hold/route/DRC/pulse/skew gates.')
    save(OUT / 'result.json', result)
    csv_write(OUT / 'clock-groups.csv', ['table', 'source_clock', 'destination_clock'] + FIELDS, current['groups'])
    csv_write(OUT / 'negative-setup-paths.csv', ['path_group', 'slack_ns', 'source', 'destination', 'data_delay_ns',
        'route_percent', 'logic_levels', 'dominant_net', 'dominant_net_fanout', 'dominant_net_delay_ns', 'start_cell_in_existing_query'], negative_paths)
    save(OUT / 'complete.json', dict(result_sha256=digest((OUT / 'result.json').read_bytes()),
         outputs={str(p): digest(p.read_bytes()) for p in OUT.iterdir() if p.is_file() and p.name != 'complete.json'}))
    print(json.dumps(dict(status=result['status'], before=old['summary'], A_physical=current['summary'],
                         negative_groups=len(negative_groups), representative_negative_paths=len(negative_paths),
                         selected_start_cells=sum(r['start_cell_in_existing_query'] for r in negative_paths),
                         result=str(OUT / 'result.json')), indent=2))


if __name__ == '__main__':
    main()
