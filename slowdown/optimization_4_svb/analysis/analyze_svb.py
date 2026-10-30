#!/usr/bin/env python3
"""Analyze hart-qualified SVB counters and the full-run v1 C/D protocol ledger."""
import argparse
from collections import Counter
import json
import importlib.util
import re
from pathlib import Path

_ledger_spec = importlib.util.spec_from_file_location('opt4_integrity_ledger', Path(__file__).with_name('integrity_ledger.py'))
integrity_ledger = importlib.util.module_from_spec(_ledger_spec)
_ledger_spec.loader.exec_module(integrity_ledger)

BASELINE = 1001675
OPT3 = 2928347


def parse_events(path):
    records = []
    for line in Path(path).read_text().splitlines():
        parts = line.split('\t')
        if parts[0] != 'SC1' or len(parts) != 23:
            continue
        try:
            records.append(dict(time=int(parts[1]), cycle=int(parts[2]),
                                episode=int(parts[4]), kind=int(parts[5]), hart=int(parts[6]),
                                nums=[int(x, 16) for x in parts[7:]]))
        except ValueError:
            continue
    return records


def protocol_ledger(records, path=None, configured_entries=None):
    capacities = [r['nums'][1] for r in records
                  if r['hart'] == 0 and r['kind'] == 30 and r['nums'][0] == 2]
    entries = capacities[-1] if capacities else configured_entries if configured_entries is not None else 8
    rows = [r for r in records if r['hart'] == 0 and 19 <= r['kind'] <= 25]
    stats = [r['nums'] for r in rows if r['kind'] == 25]
    errors = []
    if not isinstance(entries, int) or isinstance(entries, bool) or not 1 <= entries <= 256:
        errors.append('invalid SVB entry capacity')
        entries = 8
    if capacities and configured_entries is not None and capacities[-1] != configured_entries:
        errors.append('SVB capacity snapshot disagrees with run manifest')
    issued = matched = svb_issued = svb_matched = completed = conflicts = invalid = 0
    pending = selected = completing = None
    # Blackbox output order within an edge is not a protocol order.
    rows.sort(key=lambda r: (r['episode'], r['time'], r['kind']))
    episode = None
    edge = None
    before_edge = None

    def identity(n):
        return tuple(n[i] for i in (1, 2, 3, 4, 5, 7, 8, 9, 10, 15))

    for row in rows:
        kind, n = row['kind'], row['nums']
        label = f"time={row['time']} kind={kind}"
        if episode is not None and row['episode'] != episode:
            if pending or selected or completing:
                errors.append(label + ': reset with retained ownership')
            pending = selected = completing = None
        episode = row['episode']
        this_edge = (row['episode'], row['time'])
        if this_edge != edge:
            before_edge = (issued, matched, svb_issued, svb_matched, int(pending is not None))
            edge = this_edge
        if n[0] != 1:
            errors.append(label + ': unsupported schema')
            continue
        if kind == 25:
            if n[4] or n[5]:
                errors.append(label + ': nonzero hardware conflict/invalid-ACK counters')
            # Hardware STOP counters are sampled before this edge's handshakes.
            observed = tuple(n[i] for i in (6, 7, 13, 14, 8))
            if observed != before_edge:
                errors.append(label + ': STOP hardware counters disagree with full-run event ledger')
            continue
        if kind == 24:
            conflicts += bool(n[11])
            errors.append(label + ': SOURCE_CONFLICT_ERROR')
            continue
        if kind == 23:
            continue
        if kind == 19:
            if selected or completing or n[1] != 1 or n[2] >= entries:
                errors.append(label + ': duplicate/invalid selection')
            selected = identity(n)
        elif kind == 20:
            if n[6] not in (6, 7) or not (n[11] or n[12]) or not n[13]:
                errors.append(label + ': invalid C Release handshake')
            if n[11]:
                issued += 1
                svb_issued += n[1] == 1
                if pending:
                    conflicts += 1
                    errors.append(label + ': source reused before ReleaseAck')
                if n[1] and selected != identity(n):
                    errors.append(label + ': C identity differs from selected SVB entry')
                pending = dict(identity=identity(n), last=False, owner=n[1])
            if not pending or pending['identity'] != identity(n):
                errors.append(label + ': unmatched C last beat/changed identity')
            elif n[12]:
                if pending['last']:
                    errors.append(label + ': duplicate C last beat')
                pending['last'] = True
        elif kind == 21:
            if (n[6] != 6 or not n[13] or not pending or not pending['last'] or
                    pending['identity'] != identity(n)):
                invalid += 1
                errors.append(label + ': invalid/unmatched ReleaseAck')
            else:
                matched += 1
                svb_matched += pending['owner'] == 1
                if pending['owner']:
                    completing = pending['identity']
                pending = None
        elif kind == 22:
            if n[6] != 6 or not completing or completing != identity(n) or selected != completing:
                errors.append(label + ': completion without matching SVB ACK')
            else:
                completed += 1
                selected = completing = None
    counts = Counter(r['kind'] for r in rows)
    coverage = 'UNOBSERVED'
    if path and Path(path).is_file():
        footers = {}
        for line in Path(path).read_text().splitlines():
            p = line.split('\t')
            if len(p) == 8 and p[0] == 'SC_END':
                try:
                    if int(p[6]) == 0:
                        footers[int(p[5])] = int(p[7])
                except ValueError:
                    pass
        if rows:
            coverage = 'COMPLETE' if all(footers.get(k) == v for k, v in counts.items()) else 'INCOMPLETE'
            if coverage != 'COMPLETE':
                errors.append('protocol observer footer count mismatch/missing footer')
    outstanding = int(pending is not None)
    retained = selected is not None or completing is not None
    status = ('FAIL' if errors else 'UNOBSERVED' if not stats or coverage != 'COMPLETE' else
              'PENDING_RETAINED' if outstanding or retained else 'PASS')
    if not rows:
        issued = matched = svb_issued = svb_matched = completed = conflicts = invalid = None
        outstanding = retained = None
    return dict(status=status, coverage=coverage, entry_capacity=entries,
                entry_capacity_source=('capacity_snapshot' if capacities else
                                       'run_manifest' if configured_entries is not None else 'legacy_v1_default'),
                releases_issued=issued,
                release_acks_matched=matched, svb_promotions_issued=svb_issued,
                svb_release_acks_matched=svb_matched, svb_completions=completed,
                outstanding_at_end=outstanding, svb_entry_retained_at_end=retained,
                source_conflicts=conflicts, invalid_ack=invalid, errors=errors,
                stop_snapshot=stats[-1] if stats else None,
                end_policy='STOP may retain WB_WAIT; exit with retained entries is not proof of full durable drain')


def data_ordering(records):
    latest = {}
    regressions = []
    for r in sorted(records, key=lambda x: (x['episode'], x['time'], x['kind'])):
        n = r['nums']
        if r['hart'] != 0 or r['kind'] != 20 or not n[11] or n[6] != 7 or not n[9]:
            continue
        key = (r['episode'], n[3], n[8])
        previous = latest.get(key)
        current = dict(cycle=r['cycle'], line=hex(n[3]), writer=n[8], generation=n[7],
                       package=n[4], svb=bool(n[1]))
        if previous and n[7] < previous['generation']:
            regressions.append(dict(previous=previous, current=current))
        latest[key] = current
    return dict(status='FAIL' if regressions else 'PASS', stale_publications=len(regressions),
                examples=regressions[:16], scope='full_run_C_ReleaseData_same_line_writer_generation')


def capture_evidence(run, required=False, require_boundaries=False):
    path = run / 'capture_summary.json'
    if not path.is_file():
        return dict(status='FAIL' if required else 'UNOBSERVED',
                    errors=['missing capture summary'] if required else [], required=required)
    try:
        summary = json.loads(path.read_text())
        errors = []
        if summary.get('schema') != 2 or summary.get('policy') != 'priority_reserved_v2' or not summary.get('closed'):
            errors.append('invalid/unclosed bounded capture')
        if not summary.get('mandatory_evidence_complete') or summary.get('incomplete_reasons'):
            errors.append('mandatory observation evidence incomplete')
        if summary.get('counts', {}).get('failure_markers_seen'):
            errors.append('runtime failure marker observed by capture')
        ring = summary.get('diagnostic_ringbuffer')
        if ring is not None:
            if (not isinstance(ring, dict) or
                    ring.get('retained_bytes', 0) > ring.get('limit_bytes', 0) or
                    ring.get('retained_lines', 0) > ring.get('limit_lines', 0)):
                errors.append('invalid diagnostic ring buffer accounting')
        observers, producers = summary.get('observers', {}), summary.get('producers', {})
        if required and not producers:
            errors.append('missing producer accounting; budgeted logger not observed')
        for key in observers.keys() | producers.keys():
            if key == 'other':
                errors.append('unresolved observer identity'); continue
            kind, hart = map(int, key.split(':'))
            observer, producer = observers.get(key, {}), producers.get(key, {})
            if not 0 <= kind < 256 or not 0 <= hart < 65536:
                errors.append(key + ': invalid observer identity')
            optional = kind == 1 or (4 <= kind <= 15 and (kind != 10 or not require_boundaries)) or (kind == 16 and hart != 0)
            if not optional:
                if observer.get('omitted') or producer.get('omitted'):
                    errors.append(key + ': mandatory record loss')
                if required and (producer.get('produced') is None or
                        producer.get('produced') != producer.get('emitted') or
                        producer.get('omitted') != 0):
                    errors.append(key + ': invalid mandatory producer accounting')
                if required and (observer.get('footers_seen') != 1 or
                        producer.get('emitted') != observer.get('events_seen') or
                        producer.get('emitted') != observer.get('footer_emitted_count')):
                    errors.append(key + ': missing/inconsistent producer/footer conservation')
        return dict(status='FAIL' if errors else 'PASS', errors=errors, required=required, summary=summary)
    except (OSError, ValueError, TypeError, AttributeError) as exc:
        return dict(status='FAIL', errors=['invalid capture summary: '+str(exc)], required=required)


def cache_opportunity(run, benchmark, integrity=None):
    path = run / 'cache_opportunity.jsonl'
    if not path.is_file():
        return dict(status='UNOBSERVED', models=[], cache_opt_candidate=None)
    try:
        rows = [json.loads(line) for line in path.read_text().splitlines() if line.strip()]
    except (ValueError, OSError) as exc:
        return dict(status='FAIL', errors=[str(exc)], models=[], cache_opt_candidate=None)
    errors, candidates = [], []
    seen = set()
    for row in rows:
        key = (row.get('level'), row.get('instance'))
        if key in seen:
            errors.append('duplicate cache summary')
        seen.add(key)
        if row.get('schema') != 1 or not row.get('stop_seen'):
            errors.append(f'{key}: missing schema/STOP coverage')
        if row.get('classification') != 'COUNTERFACTUAL_CACHE_TRAFFIC_ESTIMATE':
            errors.append(f'{key}: invalid estimate classification')
        models = row.get('models', [])
        if len(models) != 4:
            errors.append(f'{key}: four candidate geometries required')
            continue
        actual, base = row.get('actual', {}), models[0]['stats']
        sets, ways, block = row.get('sets', 0), row.get('ways', 0), row.get('block_bytes', 0)
        shapes = [(sets, ways), (sets // 2, ways * 2), (sets * 2, ways), (sets, ways * 2)]
        for i, (model, shape) in enumerate(zip(models, shapes)):
            if (model.get('name'), model.get('sets'), model.get('ways'), model.get('capacity_bytes')) != \
                    (f'S{i}', shape[0], shape[1], shape[0] * shape[1] * block):
                errors.append(f'{key}: invalid S{i} geometry')
        if actual.get('access') != actual.get('hit', 0) + actual.get('miss', 0):
            errors.append(f'{key}: actual hit/miss conservation')
        if actual.get('access') != base.get('access'):
            errors.append(f'{key}: actual/shadow stream access mismatch')
        gap = abs(base['miss'] - actual.get('miss', 0)) / max(actual.get('miss', 0), 1)
        sane = bool(row.get('geometry_decision_eligible') and actual.get('access') and gap <= 0.10)
        row['analyzer_s0_miss_relative_error'] = gap
        for m in models:
            st = m['stats']
            if st['access'] != st['hit'] + st['miss'] or st['access'] != base['access']:
                errors.append(f'{key}: shadow access conservation')
            m['miss_reduction_vs_s0'] = base['miss'] - st['miss']
            m['replacement_reduction_vs_s0'] = base['replacement'] - st['replacement']
            m['miss_reduction_vs_actual'] = actual.get('miss', 0) - st['miss']
            m['replacement_reduction_vs_actual'] = actual.get('replacement', 0) - st['replacement']
            m['miss_reduction_percent'] = (100 * (base['miss'] - st['miss']) / base['miss']
                                           if base['miss'] else None)
            m['replacement_reduction_percent'] = (100 * (base['replacement'] - st['replacement']) /
                                                   base['replacement'] if base['replacement'] else None)
            m['conflict_candidate_reduction_vs_s0'] = (base.get('set_full_miss', 0) -
                                                        st.get('set_full_miss', 0))
            m['dram_read_opportunity_reduction'] = m['miss_reduction_vs_s0'] if row['level'] == 2 else None
            # A dirty-victim delta is an opportunity proxy, not predicted actual DRAM traffic.
            m['dirty_victim_opportunity_reduction'] = base['dirty_victim'] - st['dirty_victim']
            if m['name'] != 'S0' and sane and benchmark and \
                    base['miss'] >= 10 and m['miss_reduction_percent'] >= 10:
                candidates.append(dict(level=row['level'], instance=row['instance'], name=m['name'],
                                       sets=m['sets'], ways=m['ways'],
                                       estimated_misses_avoided=m['miss_reduction_vs_s0']))
        if not benchmark:
            row['decision'] = 'BLOCKED_BY_BENCHMARK_CORRECTNESS'
        elif not sane:
            row['decision'] = 'S0_SANITY_OR_COVERAGE_FAILED_NO_GEOMETRY_DECISION'
        else:
            associativity = models[1]['miss_reduction_percent'] or 0
            capacity = models[2]['miss_reduction_percent'] or 0
            row['decision'] = ('associativity-sensitive' if associativity >= 10 else
                               'capacity-sensitive' if capacity >= 10 else 'insensitive')
    if not any(k[0] == 1 for k in seen) or not any(k[0] == 2 for k in seen):
        errors.append('missing L1 or L2 summary')
    l1 = next((r for r in rows if r.get('level') == 1), {})
    fingerprints = l1.get('data_fingerprints', {})
    if fingerprints.get('schema') == 2:
        if not integrity or integrity['status'] != 'PASS':
            errors.append('missing/failed allocation-scoped integrity ledger')
        fingerprints = dict(schema=2, captured=(integrity or {}).get('allocations',0),
            issued=sum(x['promotion_cycle'] is not None for x in (integrity or {}).get('lifecycles',[])),
            matched_lower=(integrity or {}).get('completions',0), pending=0,
            mismatches=len((integrity or {}).get('errors',[])))
    accounting = l1.get('svb_entry_accounting', {})
    capacity = l1.get('shadow_8_capacity', {})
    if fingerprints.get('mismatches') or fingerprints.get('pending'):
        errors.append('SVB data fingerprint mismatch or incomplete issued transfer')
    if not accounting.get('observed') or not accounting.get('conserved') or accounting.get('entries') != 16 or \
            accounting.get('allocations') != sum(accounting.get(k, 0) for k in
                ('completions', 'coalesced', 'discarded', 'occupancy')):
        errors.append('missing/invalid 16-entry final conservation')
    if not capacity.get('observed'):
        errors.append('missing shadow-8 counters')
    if not {'captured', 'issued', 'matched_lower', 'pending', 'mismatches'} <= fingerprints.keys() or \
            fingerprints.get('issued') != fingerprints.get('matched_lower') or \
            fingerprints.get('captured') != accounting.get('allocations'):
        errors.append('missing/inconsistent data fingerprint ledger')
    for name in ('occupancy_histogram', 'depth_histogram'):
        if len(capacity.get(name, [])) != 17:
            errors.append('missing/incomplete final ' + name)
    return dict(status='FAIL' if errors else 'PASS', errors=errors, models=rows,
                data_fingerprints=fingerprints, entry_accounting=accounting, shadow_8_capacity=capacity,
                cache_opt_candidate=(max(candidates, key=lambda x: x['estimated_misses_avoided'])
                                     if candidates and not errors else None),
                classification='COUNTERFACTUAL_CACHE_TRAFFIC_ESTIMATE',
                predicted_roi=None, candidate_policy='one hypothesis only; hardware cost and real validation required')


def run_summary(run):
    run = Path(run)
    manifest_path = run / 'run_manifest.json'
    manifest = json.loads(manifest_path.read_text()) if manifest_path.is_file() else {}
    roi = {}
    for candidate in (run / 'roi.json', run / 'analysis/roi.json'):
        if candidate.is_file():
            roi = json.loads(candidate.read_text())
            break
    events = run / 'safe_chain_events.tsv'
    records = parse_events(events) if events.is_file() else []
    ledger = protocol_ledger(records, events, manifest.get('source', {}).get('n_svb_entries'))
    opt4 = roi.get('safe_chain_roi_cycles', roi.get('roi_cycles'))
    svb = [r['nums'] for r in records if r['hart'] == 0 and r['kind'] == 16]
    occupancy = [r['nums'] for r in records if r['hart'] == 0 and r['kind'] == 17]
    depth = [r['nums'] for r in records if r['hart'] == 0 and r['kind'] == 18]
    waitsafe_cycles = {r['cycle'] for r in records
                       if r['hart'] == 0 and r['kind'] == 15 and r['nums'][0]}
    failed = sum(bool(r['nums'][1] & (1 << 4)) for r in records if r['kind'] == 3)
    cancelled = sum(bool(r['nums'][1] & (1 << 5)) for r in records if r['kind'] == 3)
    diagnostics = '\n'.join((run / name).read_text(errors='replace')
                            for name in ('stdout.log', 'stderr.log') if (run / name).is_file())
    assertions = len(re.findall(r'(?im)\b(assert|assertion|fatal|sc_overflow|%Error)\b', diagnostics))
    benchmark = bool(re.search(r'\[RUN\] benchmark=gapbs_bfs .*\bverified=1\b', diagnostics) and
                     '[COMPUTATION] status=PASS' in diagnostics and '[END] hart=0 status=PASS' in diagnostics)
    benchmark_fail = bool(re.search(r'\bverified=0\b|\[COMPUTATION\] status=FAIL|\[END\] hart=0 status=FAIL|\*\*\* FAILED', diagnostics))
    require_cache = manifest.get('source', {}).get('revision_mode') in {
        'corrected_svb16_cache_opportunity_v1', 'corrected_svb16_fst_owner_fix_v1', 'corrected_svb16_integrity_v2'}
    bounded = manifest.get('source', {}).get('observation_policy') == 'priority_reserved_v2'
    evidence = capture_evidence(run, bounded, manifest.get('source', {}).get('revision_mode') == 'corrected_svb16_integrity_v2')
    if bounded and (manifest.get('simulation') != 'COMPLETED' or manifest.get('exit_status') != 0):
        evidence['status'] = 'FAIL'
        evidence['errors'].append('workload did not complete with exit status zero')
    checksum_match = re.search(r'parent_checksum=(\d+)', diagnostics)
    checksum = int(checksum_match[1]) if checksum_match else None
    if require_cache and benchmark and checksum != 43439728:
        benchmark, benchmark_fail = False, True
    ordering = data_ordering(records)
    integrity = integrity_ledger.build(records)
    require_integrity = manifest.get('source', {}).get('revision_mode') == 'corrected_svb16_integrity_v2'
    if require_integrity:
        if integrity['status'] != 'PASS':
            integrity['errors'].append('full allocation-scoped integrity coverage required')
            integrity['status'] = 'FAIL'
        if integrity['completions'] != ledger['svb_completions']:
            integrity['errors'].append('integrity/protocol completion count mismatch')
            integrity['status'] = 'FAIL'
    cache = cache_opportunity(run, benchmark, integrity)
    if require_integrity and (not cache.get('models') or
            any(not model.get('geometry_decision_eligible') or model.get('analyzer_s0_miss_relative_error',1)>0.10
                for model in cache['models'])):
        cache.setdefault('errors',[]).append('final cache shadow S0 sanity failed')
        cache['status']='FAIL'
    if require_integrity and integrity['status'] != 'PASS':
        cache.setdefault('errors',[]).append('integrity lifecycle ledger failed')
        cache['status'] = 'FAIL'
    if require_integrity:
        accounting=cache.get('entry_accounting',{})
        terminals=integrity['terminal_counts']
        if accounting.get('coalesced') != terminals.get('COALESCED',0) or \
           accounting.get('discarded') != terminals.get('FLUSH_DISCARDED',0)+terminals.get('INVALIDATED',0) or \
           accounting.get('completions') != terminals.get('PROMOTED_COMPLETED',0):
            cache.setdefault('errors',[]).append('terminal lifecycle/final counter mismatch')
            cache['status']='FAIL'
    if require_integrity and cache.get('entry_accounting',{}).get('allocations') != integrity['allocations']:
        cache.setdefault('errors',[]).append('allocation event/final counter mismatch')
        cache['status'] = 'FAIL'
    if require_cache and cache['status'] == 'PASS' and \
            cache['data_fingerprints']['issued'] != ledger['svb_promotions_issued']:
        cache['status'] = 'FAIL'
        cache['errors'].append('fingerprint count differs from full-run SVB C ledger')
    capacity_rows = [r for r in records if r['hart'] == 0 and r['kind'] == 30]
    pressure_rows = [r for r in records if r['hart'] == 0 and r['kind'] == 31]
    new_histogram = bool(capacity_rows)
    def histogram(kind, legacy):
        if not new_histogram:
            return legacy[-1][:9] if legacy else None
        chunks = {r['nums'][0]: r['nums'][1:] for r in records if r['kind'] == kind}
        size = capacity_rows[-1]['nums'][1] + 1
        if sorted(chunks) != list(range((size + 14) // 15)):
            return None
        return [v for i in sorted(chunks) for v in chunks[i]][:size]
    if require_cache:
        capacity_errors = []
        if len(capacity_rows) != 1 or capacity_rows[0]['nums'][:2] != [2, 16]:
            capacity_errors.append('missing/invalid SC capacity schema')
        footers = {}
        if events.is_file():
            for line in events.read_text().splitlines():
                parts = line.split('\t')
                if len(parts) == 8 and parts[0] == 'SC_END':
                    footers[(int(parts[5]), int(parts[6]))] = int(parts[7])
        for kind in (17, 18, 30):
            observed = Counter((r['kind'], r['hart']) for r in records if r['kind'] == kind)
            expected = {(kind, 0), (kind, 1)} if kind in (17, 18) else {(kind, 0)}
            if set(observed) != expected or any(footers.get(k) != v or v != 1 for k, v in observed.items()):
                capacity_errors.append(f'incomplete SC capacity/histogram coverage: kind{kind}')
        if bounded and (len(pressure_rows) != 1 or pressure_rows[0]['nums'][0] != 1 or
                        pressure_rows[0]['nums'][4] != 4096 or footers.get((31, 0)) != 1):
            capacity_errors.append('missing/invalid exact pressure counter snapshot')
        # Only this reviewed legacy artifact used pre-STOP SC snapshots but
        # counted the STOP edge in the DPI histogram. Correct in memory while
        # preserving the original run files and raw host arrays as provenance.
        source=manifest.get('source',{})
        if source.get('revision_mode')=='corrected_svb16_fst_owner_fix_v1' and \
           source.get('patch_sha256')=='c74a132789a70cb021314c9b708f628b0fc33210f855d04c31afc53420d1ee3c':
            host=cache.get('shadow_8_capacity',{})
            pairs=[('occupancy_histogram',histogram(17,occupancy)),('depth_histogram',histogram(18,depth))]
            if all(values is not None and len(values)==17 and host.get(name)==[values[0]+1]+values[1:]
                   for name,values in pairs) and len(capacity_rows)==1 and capacity_rows[0]['nums'][9]==0:
                cache['legacy_boundary_correction']=dict(reason='STOP edge sampled once by old DPI sink',
                    source_patch_sha256=source['patch_sha256'],raw_host_histograms={name:host[name] for name,_ in pairs})
                for name,values in pairs:host[name]=values
        for kind, legacy, name in ((17, occupancy, 'occupancy_histogram'), (18, depth, 'depth_histogram')):
            if histogram(kind, legacy) != cache.get('shadow_8_capacity', {}).get(name):
                capacity_errors.append('SC/host ' + name + ' mismatch')
        if require_integrity:
            boundaries=[r for r in records if r['kind']==10 and r['hart']==0]
            starts=[r['cycle'] for r in boundaries if r['nums'][1]]
            stops=[r['cycle'] for r in capacity_rows]
            expected=stops[0]-starts[0] if len(starts)==len(stops)==1 else None
            for kind,legacy,name in ((17,occupancy,'occupancy'),(18,depth,'depth')):
                values=histogram(kind,legacy)
                if expected is None or values is None or sum(values)!=expected:
                    capacity_errors.append(name+' histogram window conservation failed')
            if cache.get('models'):
                for model in cache['models']:
                    if model.get('level')==1 and model.get('cycles')!=expected:
                        capacity_errors.append('host tick/histogram sampling window mismatch')
            cache['histogram_window']=dict(semantics='pre-edge; START inclusive, STOP exclusive',cycles=expected)
        if capacity_errors:
            cache.setdefault('errors', []).extend(capacity_errors)
            cache['status'] = 'FAIL'
            cache['cache_opt_candidate'] = None
    capture_ok = not re.search(r'(?i)SC_OVERFLOW|truncat|budget exceeded', diagnostics)
    correctness = ('FAIL' if benchmark_fail or failed or cancelled or assertions or ledger['status'] == 'FAIL' or
                   evidence['status'] == 'FAIL' or
                   ordering['status'] == 'FAIL' or (require_cache and cache['status'] == 'FAIL') else
                   'PASS' if benchmark and opt4 is not None and ledger['status'] == 'PASS' and capture_ok and
                   (not require_cache or (cache['status'] == 'PASS' and
                    not cache['entry_accounting'].get('occupancy') and
                    histogram(17, occupancy) is not None and histogram(18, depth) is not None)) else
                   'UNOBSERVED_OR_PENDING')
    if correctness != 'PASS':
        cache['cache_opt_candidate'] = None
        if benchmark:
            for model in cache.get('models', []):
                model['decision'] = 'BLOCKED_BY_OVERALL_CORRECTNESS'
    fields = ['eligible', 'allocations', 'full_fallback', 'unsupported_fallback', 'bypass',
              'promotions', 'acks', 'recovery_from_svb', 'occupancy', 'max_occupancy',
              'max_depth', 'fast_line', 'capture_pending', 'capture_issued']
    counters = dict(zip(fields, svb[-1])) if svb else dict.fromkeys(fields)
    stop_fields = ['version', 'source_busy_cycles', 'queued_cycles', 'max_safe_awaiting',
                   'source_conflicts', 'invalid_ack', 'all_releases_issued', 'all_acks_matched',
                   'outstanding', 'pending_svb', 'pending_entry', 'pending_line', 'coalesced',
                   'svb_releases_issued', 'svb_acks_matched', 'occupancy']
    return dict(baseline_roi_cycles=BASELINE, opt3_roi_cycles=OPT3, opt4_roi_cycles=opt4,
                performance_valid=correctness == 'PASS',
                opt4_incremental_gain_cycles=OPT3 - opt4 if correctness == 'PASS' else None,
                opt4_total_gain_from_baseline_cycles=BASELINE - opt4 if correctness == 'PASS' else None,
                opt4_ratio_to_baseline=opt4 / BASELINE if correctness == 'PASS' else None,
                opt3_strict_unsafe_waitsafe_cycles=1547483,
                opt4_observed_waitsafe_block_records=len(waitsafe_cycles),
                opt4_waitsafe_measurement_status=('SAMPLED_EXAMPLES_PLUS_EXACT_TRAFFIC_WINDOW_COUNTERS' if bounded
                    else 'COMPACT_BLOCK_RECORDS_NOT_TOTAL_WAIT_CYCLES'),
                traffic_pressure_counters=(dict(semantic_writes=pressure_rows[-1]['nums'][1],
                    blocked_cycles=pressure_rows[-1]['nums'][2], blocked_episodes=pressure_rows[-1]['nums'][3],
                    diagnostic_sampling_interval=pressure_rows[-1]['nums'][4],
                    scope='traffic_enable_window_sampled_before_STOP_edge') if pressure_rows else None),
                correctness=dict(status=correctness, benchmark_pass=benchmark, failed_results=failed,
                                 cancelled_results=cancelled, assertion_failures=assertions),
                integrity={k:v for k,v in integrity.items() if k != 'lifecycles'},
                protocol=ledger, svb=counters, data_ordering=ordering, cache_opportunity=cache,
                capture_evidence=evidence,
                benchmark_result=dict(verified=(1 if benchmark else 0 if benchmark_fail else None),
                    checksum=checksum),
                source_stats=dict(zip(stop_fields, ledger['stop_snapshot'])) if ledger['stop_snapshot'] else None,
                occupancy_histogram=(cache.get('shadow_8_capacity', {}).get('occupancy_histogram')
                                     if require_cache else histogram(17, occupancy)),
                depth_histogram=(cache.get('shadow_8_capacity', {}).get('depth_histogram')
                                 if require_cache else histogram(18, depth)),
                observer_status='OBSERVED' if svb else 'UNKNOWN_FROM_MISSING_SVB_EVENT',
                event_records=len(records))


def main():
    p = argparse.ArgumentParser()
    p.add_argument('run', type=Path)
    p.add_argument('--output', type=Path)
    args = p.parse_args()
    out = run_summary(args.run)
    if args.output:
        integrity_ledger.export(integrity_ledger.build(parse_events(args.run/'safe_chain_events.tsv')), args.output.parent)
    text = json.dumps(out, indent=2, sort_keys=True) + '\n'
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(text)
    print(text, end='')


if __name__ == '__main__':
    main()
