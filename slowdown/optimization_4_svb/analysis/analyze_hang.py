#!/usr/bin/env python3
"""Build bounded hang progress and wait-for artifacts from a completed run."""
import argparse
import json
import re
from pathlib import Path


BASE_TYPES = (
    'FAST_LINE', 'SVB_ENTRY', 'WB', 'PROBE', 'MSHR', 'PRESERVATION',
    'PROMOTION', 'C_CHANNEL', 'D_ACK', 'WATERMARK',
)
EVENT_PREFIXES = (
    'FASTLINE_', 'SVB_', 'WB_', 'PROBE_', 'MSHR_', 'PRESERVATION_',
    'PRESERVATION', 'C_CHANNEL', 'D_ACK', 'WATERMARK_ADVANCE',
    'CORE_WATCHDOG_SNAPSHOT', 'DCACHE_WATCHDOG_SNAPSHOT',
    'CACHE_HANG_SNAPSHOT', 'LONG_STALL',
)


def number(value):
    if value is None or not re.fullmatch(r'(?:0x)?[0-9a-fA-F]+', value):
        return None
    return int(value, 16) if not value.startswith('0x') else int(value, 16)


def parse_record(line, source):
    line = line.strip()
    if not line:
        return None
    parts = line.split()
    name = parts[0]
    if not name.startswith(EVENT_PREFIXES):
        return None
    fields = {}
    for token in parts[1:]:
        if '=' not in token:
            continue
        key, value = token.split('=', 1)
        fields[key] = number(value) if number(value) is not None else value
    return dict(name=name, fields=fields, raw=line, source=source,
                cycle=fields.get('cycle') if isinstance(fields.get('cycle'), int) else None)


def read_records(run):
    records = []
    ring = run / 'hang_ringbuffer.tsv'
    if ring.is_file():
        for index, line in enumerate(ring.read_text(errors='replace').splitlines(), 1):
            if index == 1 and line == 'stream\tevent':
                continue
            stream, sep, event = line.partition('\t')
            if sep:
                row = parse_record(event, f'hang_ringbuffer.tsv:{index}:{stream}')
                if row:
                    records.append(row)
    for name in ('stdout.log', 'stderr.log'):
        path = run / name
        if not path.is_file():
            continue
        for index, line in enumerate(path.read_text(errors='replace').splitlines(), 1):
            row = parse_record(line, f'{name}:{index}')
            if row:
                records.append(row)
    unique = {}
    for row in records:
        unique[(row['name'], row['raw'])] = row
    return sorted(unique.values(), key=lambda row: (
        row['cycle'] if row['cycle'] is not None else -1, row['source']))


def latest(records, name):
    matches = [row for row in records if row['name'] == name]
    return max(matches, key=lambda row: row['cycle'] or -1) if matches else None


def failure_report(run):
    """Identify native assertion failures even when Chisel printf is disabled.

    An assertion number alone is not a watchdog identity. Resolve its exact
    generated source line in this run's build, or require the explicit message.
    """
    run = Path(run)
    evidence = []
    failures = []
    times = []
    for name in ('stdout.log', 'stderr.log', 'hang_ringbuffer.tsv'):
        path = run / name
        if not path.is_file():
            continue
        for index, line in enumerate(path.read_text(errors='replace').splitlines(), 1):
            source = f'{name}:{index}'
            if re.search(r'(?i)assertion failed|%error|\bfatal\b', line):
                failures.append(source)
            watchdog = 'Pipeline has hung' in line
            match = re.search(r'%Error: ([^\s:]+\.sv):(\d+): Assertion failed', line)
            if match:
                generated = (run.parent.parent / 'build' / run.name / 'generated' /
                             'gen-collateral' / Path(match[1]).name)
                if generated.is_file():
                    lines = generated.read_text(errors='replace').splitlines()
                    number = int(match[2])
                    if 1 <= number <= len(lines):
                        assertion = lines[number - 1]
                        if re.search(r'\bassert\s*\(\s*~\s*ecWatchdogImminent\s*\)', assertion):
                            watchdog = True
                            evidence.append(f'{generated}:{number}')
            if watchdog:
                evidence.append(source)
                time = re.search(r'\[(\d+)\]', line)
                if time:
                    times.append(int(time[1]))
    return dict(watchdog_detected=bool(evidence),
                simulator_time=max(times) if times else None,
                watchdog_evidence=sorted(set(evidence)),
                failure_evidence=sorted(set(failures)))


def progress_report(records, failure=None):
    core = latest(records, 'CORE_WATCHDOG_SNAPSHOT')
    cache = latest(records, 'DCACHE_WATCHDOG_SNAPSHOT')
    watchdog_cycle = core['cycle'] if core else None
    fields = cache['fields'] if cache else {}
    core_fields = core['fields'] if core else {}
    categories = {
        'commit': (core_fields.get('last_commit'), 'CORE_WATCHDOG_SNAPSHOT.last_commit'),
        'watchdog_counter_reset': (core_fields.get('last_progress'), 'CORE_WATCHDOG_SNAPSHOT.last_progress'),
        'lsu': (fields.get('last_lsu'), 'DCACHE_WATCHDOG_SNAPSHOT.last_lsu'),
        'watermark': (fields.get('last_watermark'), 'DCACHE_WATCHDOG_SNAPSHOT.last_watermark'),
        'checker_result': (fields.get('last_checker_result'), 'DCACHE_WATCHDOG_SNAPSHOT.last_checker_result'),
        'writeback_completion': (fields.get('last_wb'), 'DCACHE_WATCHDOG_SNAPSHOT.last_wb'),
        'probe_completion': (fields.get('last_probe'), 'DCACHE_WATCHDOG_SNAPSHOT.last_probe'),
        'mshr_free': (fields.get('last_mshr_free'), 'DCACHE_WATCHDOG_SNAPSHOT.last_mshr_free'),
        'svb_completion': (fields.get('last_svb'), 'DCACHE_WATCHDOG_SNAPSHOT.last_svb'),
    }
    event_sources = {
        'watermark': ('WATERMARK_ADVANCE', 'cycle'),
        'writeback_completion': ('WB_COMPLETE', 'cycle'),
        'probe_completion': ('PROBE_COMPLETE', 'cycle'),
        'mshr_free': ('MSHR_FREE', 'cycle'),
        'svb_completion': ('SVB_COMPLETION', 'cycle'),
    }
    result = {}
    for category, (cycle, source) in categories.items():
        event_spec = event_sources.get(category)
        if event_spec:
            event = latest(records, event_spec[0])
            event_cycle = event['fields'].get(event_spec[1]) if event else None
            if isinstance(event_cycle, int) and (not isinstance(cycle, int) or event_cycle > cycle):
                cycle, source = event_cycle, event['name']
        observed = isinstance(cycle, int) and cycle != 0
        result[category] = dict(cycle=cycle if observed else None,
                                status='OBSERVED' if observed else 'NOT_OBSERVED', source=source)
    failure = failure or {}
    return dict(schema=1, watchdog_detected=core is not None or failure.get('watchdog_detected', False),
                watchdog_cycle=watchdog_cycle, progress_before_watchdog=bool(core),
                watchdog_simulator_time=failure.get('simulator_time'),
                diagnostic_snapshots_complete=core is not None and cache is not None,
                failure_detection=failure,
                last_progress_cycle_by_category=result,
                evidence={
                    'core_watchdog_snapshot': core['source'] if core else None,
                    'dcache_watchdog_snapshot': cache['source'] if cache else None,
                })


def graph_report(records, progress):
    nodes = {kind: dict(id=kind, type=kind, observed=False) for kind in BASE_TYPES}
    edges = []

    def node(kind, identity=None, **attrs):
        key = kind if identity is None else f'{kind}:{identity}'
        item = nodes.setdefault(key, dict(id=key, type=kind, observed=True))
        item.update(attrs)
        return key

    def edge(source, target, reason, record):
        edges.append(dict(from_node=source, to_node=target, relation='waits_for',
                          reason=reason, evidence=record['source'],
                          cycle=record['cycle'], confidence='direct_observation'))

    for row in records:
        f = row['fields']
        if row['name'] in ('C_CHANNEL', 'SVB_C_FIRE'):
            node('C_CHANNEL', hex(f.get('line', 0)), line=f.get('line'),
                 last=bool(f.get('last')), owner=f.get('owner', 'SVB' if row['name'] == 'SVB_C_FIRE' else None),
                 last_cycle=row['cycle'])
        elif row['name'] == 'D_ACK':
            node('D_ACK', hex(f.get('line', 0)), line=f.get('line'),
                 matched=bool(f.get('matched')), owner_svb=bool(f.get('owner_svb')),
                 last_cycle=row['cycle'])
        elif row['name'] in ('WB_START', 'WB_COMPLETE'):
            node('WB', hex(f.get('line', 0)), line=f.get('line'),
                 owner_type=f.get('owner_type', f.get('kind')), last_cycle=row['cycle'])
        elif row['name'] in ('PROBE_START', 'PROBE_COMPLETE', 'PROBE_BLOCKED'):
            node('PROBE', hex(f.get('line', 0)), line=f.get('line'),
                 state=f.get('state', f.get('probe_state')), last_cycle=row['cycle'])
        elif row['name'].startswith('PRESERVATION_'):
            node('PRESERVATION', hex(f.get('line', 0)), line=f.get('line'),
                 pending=bool(f.get('pending')), last_cycle=row['cycle'])
        elif row['name'].startswith('SVB_') and isinstance(f.get('entry'), int):
            node('SVB_ENTRY', str(f['entry']), line=f.get('line'), sequence=f.get('seq'),
                 state=f.get('state'), last_cycle=row['cycle'])

    snapshots = [row for row in records if row['name'] == 'DCACHE_WATCHDOG_SNAPSHOT']
    snapshot = max(snapshots, key=lambda row: row['cycle'] or -1) if snapshots else None
    snap = snapshot['fields'] if snapshot else {}
    watermark = snap.get('safe_watermark')
    fastline_id = None
    if snap.get('fast_valid') == 1:
        fastline_id = node('FAST_LINE', hex(snap.get('fast_line', 0)), line=snap.get('fast_line'),
                           sequence=snap.get('fast_seq'), epoch=snap.get('fast_epoch'),
                           owner='SVB', owner_state=snap.get('fast_state'),
                           acquire_cycle=snap.get('fast_acquire_cycle'),
                           release_cycle=snap.get('fast_release_cycle'))
    elif any(row['name'] == 'FASTLINE_ACQUIRE' for row in records):
        row = latest(records, 'FASTLINE_ACQUIRE')
        f = row['fields']
        fastline_id = node('FAST_LINE', hex(f.get('line', 0)), line=f.get('line'),
                           sequence=f.get('seq'), epoch=f.get('epoch'), owner='SVB',
                           owner_state=f.get('owner_state'), acquire_cycle=f.get('cycle'))

    for row in records:
        f = row['fields']
        if row['name'] == 'FASTLINE_BLOCK_OTHER_LINE':
            sole_gate = all(f.get(key) == 1 for key in (
                'gate_fast_valid', 'gate_other_line', 'gate_slot_free', 'gate_nack_clear',
                'gate_epoch_match', 'gate_no_pending_handoff', 'gate_would_handoff_without_fastline'))
            sole_gate = sole_gate and f.get('gate_capture_pending') == 0 and f.get('gate_fast_match') == 0
            if sole_gate:
                line = f.get('line')
                owner_line = f.get('fast_line')
                preserve_id = node('PRESERVATION', f'{line:#x}:seq{f.get("package_seq")}',
                                   line=line, sequence=f.get('package_seq'),
                                   request_type=f.get('request_type'))
                fastline_id = node('FAST_LINE', f'{owner_line:#x}', line=owner_line,
                                   sequence=f.get('fast_seq'), epoch=f.get('fast_epoch'),
                                   owner='SVB', owner_state=f.get('owner_state'),
                                   acquire_cycle=f.get('acquire_cycle'), generation=f.get('fast_generation'))
                edge(preserve_id, fastline_id,
                     'global svbFastLineValid is the only failed preservation-start gate', row)
        elif row['name'] == 'PROBE_BLOCKED' and f.get('blocked_retained_svb') == 1:
            probe_id = node('PROBE', hex(f.get('line', 0)), line=f.get('line'), state=f.get('probe_state'))
            entry_id = node('SVB_ENTRY', str(f.get('blocking_entry')),
                            line=f.get('blocking_line'), sequence=f.get('blocking_seq'),
                            generation=f.get('blocking_generation'))
            edge(probe_id, entry_id, 'probe ingress blocked by retained SVB entry', row)
        elif row['name'] == 'PRESERVATION_BLOCKED':
            preserve_id = node('PRESERVATION', hex(f.get('line', 0)), line=f.get('line'),
                               sequence=f.get('seq'), waiting_reason=f.get('waiting_reason'))
            reason = f.get('waiting_reason')
            if reason == 2 and f.get('slot_conflict') == 1:
                target = node('MSHR', hex(f.get('line', 0)), line=f.get('line'))
                edge(preserve_id, target, 'preservation slot is owned by an active MSHR', row)
            elif reason == 5 and f.get('probe_same_set') == 1:
                target = node('PROBE', hex(f.get('line', 0)), line=f.get('line'))
                edge(preserve_id, target, 'preservation waits for a probe in the same set', row)
            elif reason == 6 and f.get('safe') == 0:
                target = node('WATERMARK', 'unknown', value=None)
                edge(preserve_id, target, 'preservation image is not safe at the current watermark', row)
            elif reason == 7 and f.get('request_valid') == 1 and f.get('request_ready') == 0:
                target = node('WB', hex(f.get('wb_line', 0)), line=f.get('wb_line'),
                              pending=bool(f.get('wb_pending')),
                              svb_owner=bool(f.get('wb_pending_svb')),
                              source_busy=bool(f.get('wb_source_busy')))
                edge(preserve_id, target, 'preservation request waits for the shared writeback source', row)
        elif row['name'] in ('MSHR_STATE', 'LONG_STALL') and (
                row['name'] == 'MSHR_STATE' or f.get('object') == 'MSHR'):
            line = f.get('line')
            identity = f.get('entry', 'unknown')
            mshr_id = node('MSHR', str(identity), line=line, state=f.get('state'),
                           waiting_resource=f.get('waiting_resource'))
            if f.get('wb_dependency') == 1:
                edge(mshr_id, node('WB', hex(line or 0), line=line), 'MSHR reports WB dependency', row)
            if f.get('probe_dependency') == 1:
                edge(mshr_id, node('PROBE', hex(line or 0), line=line), 'MSHR reports probe dependency', row)
            if f.get('svb_dependency') == 1:
                edge(mshr_id, node('SVB_ENTRY', hex(line or 0), line=line), 'MSHR reports SVB dependency', row)
        elif row['name'] == 'LONG_STALL' and f.get('object') == 'SVB_ENTRY':
            entry_id = node('SVB_ENTRY', str(f.get('entry')), line=f.get('line'),
                            state=f.get('state'), sequence=f.get('seq'))
            if f.get('state') == 2:
                edge(entry_id, node('D_ACK', hex(f.get('line', 0)), line=f.get('line')),
                     'SVB WB_WAIT entry is retained until matching D ACK', row)
            elif f.get('safe') == 0:
                edge(entry_id, node('WATERMARK', str(f.get('watermark')), value=f.get('watermark')),
                     'unsafe SVB entry is waiting for safe watermark', row)
        elif row['name'] == 'SVB_HANG_ENTRY':
            entry_id = node('SVB_ENTRY', str(f.get('entry')), line=f.get('line'),
                            state=f.get('state'), sequence=f.get('seq'), generation=f.get('generation'))
            valid_key = f.get('key_valid') == 1
            if (f.get('state') == 1 and valid_key and isinstance(watermark, int) and
                    isinstance(f.get('seq'), int) and f['seq'] > watermark):
                edge(entry_id, node('WATERMARK', str(watermark), value=watermark),
                     'valid SVB sequence exceeds watchdog safe watermark', row)
            if f.get('state') == 2:
                edge(entry_id, node('D_ACK', hex(f.get('line', 0)), line=f.get('line')),
                     'SVB WB_WAIT entry requires matching D ACK', row)
        elif row['name'] == 'WB_BLOCK' and f.get('owner_type') == 'SVB_PROMOTION':
            promotion_id = node('PROMOTION', str(f.get('entry')), line=f.get('line'), sequence=f.get('seq'))
            wb_id = node('WB', hex(f.get('pending_line', 0)), line=f.get('pending_line'),
                         pending=bool(f.get('wb_pending')), svb_owner=bool(f.get('pending_svb')))
            edge(promotion_id, wb_id, 'promotion waits for shared writeback source', row)
        elif row['name'] == 'WB_BLOCK' and isinstance(f.get('owner_type'), int):
            request_type = {0: 'PROBE', 1: 'MSHR', 2: 'SVB_ENTRY', 3: 'PRESERVATION'}.get(f['owner_type'])
            if request_type:
                request_id = node(request_type, hex(f.get('line', 0)), line=f.get('line'),
                                  waiting_reason=f.get('waiting_reason'))
                wb_id = node('WB', hex(f.get('pending_line', 0)), line=f.get('pending_line'),
                             pending=bool(f.get('wb_pending')), svb_owner=bool(f.get('pending_svb')))
                edge(request_id, wb_id, 'writeback request is backpressured by shared WB unit', row)
        elif row['name'] == 'LONG_STALL' and f.get('object') == 'SVB_PROMOTION':
            promotion_id = node('PROMOTION', str(f.get('entry')), line=f.get('line'), sequence=f.get('seq'))
            if f.get('waiting_reason') == 1:
                edge(promotion_id, node('WB', hex(f.get('line', 0)), line=f.get('line')),
                     'promotion reports an active WB owner', row)
            elif f.get('safe') == 0:
                edge(promotion_id, node('WATERMARK', str(snap.get('safe_watermark')),
                                         value=snap.get('safe_watermark')),
                     'promotion entry is not safe at the current watermark', row)
        elif row['name'] == 'LONG_STALL' and f.get('object') == 'WB':
            wb_id = node('WB', hex(f.get('line', 0)), line=f.get('line'),
                         owner_type=f.get('owner_type'), state=f.get('state'))
            next_channel = 'D_ACK' if f.get('waiting_reason') == 2 else 'C_CHANNEL'
            edge(wb_id, node(next_channel, hex(f.get('line', 0)), line=f.get('line')),
                 'long-stalled writeback reports its next required channel phase', row)

    if snap.get('wb_pending') == 1:
        wb_id = node('WB', hex(snap.get('wb_line', 0)), line=snap.get('wb_line'),
                     owner_type=snap.get('wb_owner_type'), svb_owner=bool(snap.get('wb_pending_svb')),
                     sent=bool(snap.get('wb_sent')))
        target_type = 'D_ACK' if snap.get('wb_sent') == 1 else 'C_CHANNEL'
        target = node(target_type, hex(snap.get('wb_line', 0)), line=snap.get('wb_line'))
        edge(wb_id, target, 'pending WB awaits its next TileLink handshake', snapshot)
        if snap.get('wb_pending_svb') == 1:
            entry_id = node('SVB_ENTRY', str(snap.get('wb_entry')), line=snap.get('wb_line'),
                            sequence=snap.get('svb_seq'), state=2)
            if snap.get('wb_sent') == 1:
                edge(entry_id, target, 'promoted SVB entry awaits ReleaseAck', snapshot)

    # Deduplicate identical dependencies while keeping every source row as evidence.
    compact = {}
    for item in edges:
        key = (item['from_node'], item['to_node'], item['reason'])
        if key not in compact:
            compact[key] = item
        elif item['evidence'] not in compact[key]['evidence']:
            compact[key]['evidence'] += '; ' + item['evidence']
    edges = list(compact.values())
    cycles = find_cycles(edges)
    for kind in BASE_TYPES:
        node(kind)
    watchdog = progress['watchdog_detected']
    status = ('HANG_DIAGNOSTIC_EVIDENCE_INSUFFICIENT'
              if watchdog and not progress['diagnostic_snapshots_complete'] else
              'CONFIRMED_DEADLOCK_CYCLE' if cycles else
              'HANG_ROOT_CAUSE_STILL_UNRESOLVED' if watchdog else 'NO_WATCHDOG_OBSERVED')
    if not watchdog and progress.get('failure_detection', {}).get('failure_evidence'):
        status = 'ABNORMAL_EXIT_WITHOUT_WATCHDOG_EVIDENCE'
    blocked = [row for row in records if row['name'] == 'FASTLINE_BLOCK_OTHER_LINE']
    return dict(schema=1, status=status, watchdog_detected=watchdog,
                nodes=sorted(nodes.values(), key=lambda item: item['id']), edges=edges,
                cycles=cycles, unrelated_lines_blocked_by_fast_line=[
                    dict(cycle=row['cycle'], line=row['fields'].get('line'),
                         owner_line=row['fields'].get('fast_line'),
                         package_seq=row['fields'].get('package_seq'), evidence=row['source'])
                    for row in blocked],
                candidate_fastline_related_waits=sum(
                    1 for row in records if row['name'] == 'PRESERVATION_WAIT' and
                    row['fields'].get('blocked_fastline') == 1),
                evidence_records=len(records),
                cycle_policy='a cycle is confirmed only when every edge is directly backed by a logged wait condition')


def find_cycles(edges):
    graph = {}
    for item in edges:
        graph.setdefault(item['from_node'], []).append(item['to_node'])
    found = set()
    visiting = []
    active = set()
    visited = set()

    def visit(current):
        if current in active:
            start = visiting.index(current)
            cycle = tuple(visiting[start:] + [current])
            rotations = [cycle[i:-1] + cycle[:i] for i in range(len(cycle) - 1)]
            found.add(min(rotations))
            return
        if current in visited:
            return
        active.add(current)
        visiting.append(current)
        for target in graph.get(current, []):
            visit(target)
        visiting.pop()
        active.remove(current)
        visited.add(current)

    for start in graph:
        visit(start)
    return [list(cycle) + [cycle[0]] for cycle in sorted(found)]


def rootcause_markdown(progress, graph, records):
    lines = ['# Opt4 SVB hang diagnostic', '', f"**Status: `{graph['status']}`.**", '']
    if progress['watchdog_detected']:
        core_record = latest(records, 'CORE_WATCHDOG_SNAPSHOT')
        core = core_record['fields'] if core_record else {}
        lines += [f"Watchdog core cycle: `{progress['watchdog_cycle']}`; simulator time: `{progress.get('watchdog_simulator_time')}`; last ROB commit: `{core.get('last_commit')}`; last watchdog reset: `{core.get('last_progress')}`.", '']
        if not progress['diagnostic_snapshots_complete']:
            lines += ['The watchdog is proven by a failure message or its exact generated assertion, but the CORE/DCACHE watchdog state snapshots are missing. Missing ownership state cannot establish a wait-for cycle.', '']
        lines += [f"Watchdog evidence: {progress.get('failure_detection', {}).get('watchdog_evidence', [])}", '']
        cache = latest(records, 'DCACHE_WATCHDOG_SNAPSHOT')
        if cache:
            f = cache['fields']
            lines += [f"Fast line: valid=`{f.get('fast_valid')}`, line=`{f.get('fast_line')}`, sequence=`{f.get('fast_seq')}`, epoch=`{f.get('fast_epoch')}`, owner state=`{f.get('fast_state')}`, acquired=`{f.get('fast_acquire_cycle')}`; safe watermark=`{f.get('safe_watermark') }`.",
                      f"WB: pending=`{f.get('wb_pending')}`, owner type=`{f.get('wb_owner_type')}`, line=`{f.get('wb_line')}`, sent=`{f.get('wb_sent')}`. Probe: valid=`{f.get('probe_valid')}`, line=`{f.get('probe_line')}`, state=`{f.get('probe_state')}`. MSHR active count=`{f.get('mshr_active')}`.",
                      f"Preservation: active=`{f.get('preservation_wait')}`, line=`{f.get('preservation_line')}`, pending=`{f.get('preservation_pending')}`, start condition=`{f.get('preservation_block_condition')}`. Promotion: valid=`{f.get('promotion_valid')}`, entry=`{f.get('promotion_entry')}`, line=`{f.get('promotion_line')}`, sequence=`{f.get('promotion_seq')}`.", '']
    else:
        lines += ['No watchdog snapshot was found in the captured diagnostic records.', '']
        if progress.get('failure_detection', {}).get('failure_evidence'):
            lines += ['A runtime failure was recorded; its assertion is not proven to be the pipeline watchdog.', '']
    blocked = graph['unrelated_lines_blocked_by_fast_line']
    if blocked:
        lines += ['Unrelated preservation requests proven to be gated solely by `svbFastLineValid`:']
        lines.extend(f"- cycle `{item['cycle']}`, line `{item['line']}`, package sequence `{item['package_seq']}`, fast-line owner `{item['owner_line']}` ({item['evidence']})" for item in blocked)
    else:
        lines += ['No unrelated line was proven to be blocked solely by the global fast-line gate.']
    lines += ['', 'Last observed progress cycles:']
    for name, item in progress['last_progress_cycle_by_category'].items():
        lines.append(f"- {name}: `{item['cycle']}` ({item['status']}, {item['source']})")
    lines += ['', 'Wait-for edges:']
    if graph['edges']:
        lines.extend(f"- `{item['from_node']}` waits for `{item['to_node']}`: {item['reason']} ({item['evidence']})" for item in graph['edges'])
    else:
        lines.append('- No complete dependency edge was established from the captured records.')
    if graph['cycles']:
        lines += ['', 'Confirmed cycle(s):']
        lines.extend('- `' + ' -> '.join(cycle) + '`' for cycle in graph['cycles'])
    elif progress['watchdog_detected']:
        lines += ['', 'The observed wait edges do not form a closed cycle. The hang root cause remains unresolved; missing dependencies stay unknown.']
    return '\n'.join(lines) + '\n'


def analyze(run, output_dir=None):
    run = Path(run)
    output_dir = Path(output_dir) if output_dir else run
    output_dir.mkdir(parents=True, exist_ok=True)
    records = read_records(run)
    progress = progress_report(records, failure_report(run))
    graph = graph_report(records, progress)
    (output_dir / 'last_progress.json').write_text(json.dumps(progress, indent=2, sort_keys=True) + '\n')
    (output_dir / 'wait_for_graph.json').write_text(json.dumps(graph, indent=2, sort_keys=True) + '\n')
    (output_dir / 'hang_rootcause.md').write_text(rootcause_markdown(progress, graph, records))
    return dict(status=graph['status'], records=len(records), cycles=graph['cycles'])


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('run', type=Path)
    parser.add_argument('--output-dir', type=Path)
    args = parser.parse_args()
    result = analyze(args.run, args.output_dir)
    print(json.dumps(result, indent=2, sort_keys=True))


if __name__ == '__main__':
    main()
