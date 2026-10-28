"""Pure offline SC1 analysis. Observation cycles are not lost or avoidable cycles."""
import csv
import json
from collections import Counter, defaultdict
from fractions import Fraction
from pathlib import Path

CATEGORIES = ('RESULT_NOT_AVAILABLE', 'PREFIX_HOLE', 'PREFIX_PROPAGATION_DELAY',
              'POST_SAFE_WAIT', 'MULTI_CAUSE', 'UNRESOLVED')
EXPECTED = {(k, 0) for k in (1, 2, 7, 8, 10)} | {(k, h) for k in (3, 4, 5, 6)
           for h in range(1, 5)} | {(9, h) for h in range(32)}
EXPECTED |= {(k, h) for k in (11, 12, 13) for h in range(1, 5)} | {(14, 0), (15, 0)}
EXPECTED |= {(16, h) for h in range(1, 5)}
MAIN = {1, 2, 3, 5, 7, 8, 9, 10, 14, 15}
LONG = 1000


def bit(value, index):
    return bool(value & (1 << index))


def distribution(values):
    values = sorted(values)
    if not values:
        return dict(n=0, min=None, p50=None, p95=None, max=None)
    return dict(n=len(values), min=values[0], p50=values[(len(values)-1)//2],
                p95=values[((len(values)-1)*95)//100], max=values[-1])


def read_events(path):
    rows, footers, counts, errors, previous = [], {}, Counter(), [], {}
    with path.open() as stream:
        for lineno, raw in enumerate(stream, 1):
            if not raw.endswith('\n'):
                raise ValueError('unterminated compact record at line ' + str(lineno))
            cols = raw.rstrip('\n').split('\t')
            if cols[0] == 'SC1' and len(cols) == 23:
                time, cycle, local, episode, kind, hart = map(int, cols[1:7])
                data = [int(v, 16) for v in cols[7:]]
                if min(time, cycle, local, episode, kind, hart, *data) < 0 or max(data) >= 2**64:
                    raise ValueError('out-of-range SC1 value')
                key = kind, hart
                if key not in EXPECTED:
                    errors.append('unexpected observer ' + str(key))
                if key in footers:
                    errors.append('event after footer ' + str(key))
                if key in previous and (time <= previous[key][0] or local <= previous[key][1]):
                    errors.append('non-monotone observer clock ' + str(key))
                previous[key] = time, local
                rows.append(dict(time=time, cycle=cycle, local=local, episode=episode,
                                 kind=kind, hart=hart, d=data, line=lineno))
                counts[key] += 1
            elif cols[0] == 'SC_END' and len(cols) == 8:
                time, cycle, local, episode, kind, hart, count = map(int, cols[1:])
                if (kind, hart) not in EXPECTED:
                    errors.append('unexpected footer observer '+str((kind, hart)))
                if (kind, hart) in footers:
                    errors.append('duplicate footer ' + str((kind, hart)))
                footers[kind, hart] = dict(time=time, cycle=cycle, local=local, episode=episode, count=count)
            else:
                raise ValueError('malformed compact record at line ' + str(lineno))
    for key in EXPECTED:
        if key not in footers:
            errors.append('missing observer footer ' + str(key))
        elif footers[key]['count'] != counts[key]:
            errors.append('event count mismatch ' + str(key))
        elif key in previous and footers[key]['time'] < previous[key][0]:
            errors.append('footer predates final event ' + str(key))
    episodes = {r['episode'] for r in rows} | {f['episode'] for f in footers.values()}
    if len(episodes) != 1:
        errors.append('multiple/reset episodes; cross-episode association refused')
    return rows, footers, errors


def align_clocks(rows, errors):
    """Fit actual main-clock timestamp/cycle pairs; never reuse FST scaling.

    Async rows become visible at the first main edge at/after their raw time.
    Shared CSR taps are labels only; disagreement invalidates the attribution.
    """
    anchors = sorted({(r['cycle'], r['time']) for r in rows if r['kind'] in MAIN})
    period = offset = None
    if len(anchors) >= 2 and anchors[-1][0] > anchors[0][0]:
        period = Fraction(anchors[-1][1]-anchors[0][1], anchors[-1][0]-anchors[0][0])
        offset = anchors[0][1] - period*anchors[0][0]
        if period <= 0 or any(t != offset+period*c for c, t in anchors):
            errors.append('main-clock timestamp/cycle relation is not affine')
            period = None
    else:
        errors.append('insufficient main-clock anchors')
    for row in rows:
        row['effective_cycle'] = row['cycle']
        if period and row['kind'] not in MAIN:
            coordinate = (row['time']-offset)/period
            edge = -(-coordinate.numerator//coordinate.denominator)
            if abs(edge-row['cycle']) > 1:
                errors.append('asynchronous cycle tap disagrees with main-clock fit')
            row['effective_cycle'] = edge
    return dict(period=str(period), offset=str(offset),
                async_policy='ceil raw timestamp to first main pre-edge sample; equal-time batch unordered')


def pending_class(p, prefix, accepted, produced):
    if p is None:
        return 'UNRESOLVED', dict(reason='missing pending state')
    if prefix is None:
        return 'UNRESOLVED', dict(reason='missing prefix state', entry=p['d'][0],
            target=p['d'][1], unsafe=not bit(p['d'][9], 1))
    d = p['d']; target = d[1]; flags = d[9]
    old, new, hole, tag, hflags = prefix['d'][:5]
    context = dict(target=target, entry=d[0], slot_epoch=d[2], generation=d[6], writer=d[7],
                   set=d[3], tag=d[4], way=d[5], safe_prefix=old, next_prefix=new,
                   earliest_missing_predecessor=hole, hole_slot_tag=tag, hole_flags=hflags,
                   target_distance=target-hole, release_bits=flags, unsafe=not bit(flags, 1))
    if not bit(flags, 0):
        return None, context
    if not bit(flags, 2):
        return 'UNRESOLVED', dict(context, reason='resident identity revoked')
    if bit(flags, 23) or bit(flags, 24) or bit(flags, 18):
        return 'MULTI_CAUSE', dict(context, reason='recovery/kill/revocation concurrent')
    if not d[8] or target == 0:
        return 'POST_SAFE_WAIT', dict(context, reason='untracked/base live key; safety vacuous')
    if bit(flags, 1):
        if old < target:
            return 'UNRESOLVED', dict(context, reason='safe/key/prefix mismatch')
        reasons = [name for b, name in ((5, 'mshr'), (6, 'slot'), (7, 'drain'),
                   (8, 'completion'), (9, 'probe'), (3, 'wb_issued'), (4, 'meta_clear_pending')) if bit(flags, b)]
        return 'POST_SAFE_WAIT', dict(context, conditions=reasons,
                   reason='WB/receipt/meta-clear release predicates; not checker wait')
    if old >= target:
        return 'UNRESOLVED', dict(context, reason='prefix covers target but safe bit low')
    guards = [name for b, name in ((6, 'slot'), (7, 'drain'), (8, 'completion'),
              (9, 'probe')) if bit(flags, b)]
    if guards:
        return 'MULTI_CAUSE', dict(context, reason='unsafe target plus independent WB-admission guards',
                                  conditions=guards)
    status, known = accepted.get(target), produced.get(target)
    # Next table is the exact local source of truth, including this edge.
    target_slot_pass = d[10] == target and (d[11] & 7) == 7
    if target_slot_pass:
        status = 0
    if (status is not None and status != 0) or (known is not None and known['status'] != 0):
        return 'UNRESOLVED', dict(context, reason='target FAIL/CANCELLED/unknown status')
    if new >= target:
        return 'PREFIX_PROPAGATION_DELAY', dict(context, reason='combinational Next covers target; registered safe still old',
                                                 phase='watermark_register_edge')
    if status == 0:
        if hole < target:
            if not bit(hflags, 0) or tag != hole:
                return 'UNRESOLVED', dict(context, reason='hole slot absent/tag mismatch')
            if bit(hflags, 1):
                return 'UNRESOLVED', dict(context, reason='hole completed FAIL/CANCELLED or inconsistent PASS')
            return 'PREFIX_HOLE', context
        return 'UNRESOLVED', dict(context, reason='accepted target without earlier hole or Next coverage')
    if known and known['status'] == 0:
        # Formed PASS is not accepted safety. Cleanup, queue and CDC are still
        # necessary, so this is NOT a prefix-propagation optimization candidate.
        if hole < target:
            return 'MULTI_CAUSE', dict(context, reason='earlier hole plus target cleanup/transport',
                                      phase='pre_accept_transport_or_cleanup')
        return 'RESULT_NOT_AVAILABLE', dict(context, reason='formed PASS not yet accepted at L1 safety endpoint',
                                             phase='pre_accept_transport_or_cleanup')
    return 'RESULT_NOT_AVAILABLE', dict(context, reason='no target PASS formed/accepted', phase='checker_execution_or_tail')


def analyze_events(path, roi, out):
    start, stop = roi['start_cycle'], roi['stop_cycle']
    if stop <= start:
        raise ValueError('invalid ROI')
    if out.exists():
        raise ValueError('output already exists; refuse overwrite')
    rows, footers, errors = read_events(path)
    clock_fit = align_clocks(rows, errors)
    for key, footer in footers.items():
        if footer['cycle'] < stop:
            errors.append('observer ends before software ROI ' + str(key))
    for key in {(1, 0), (8, 0)} | {(k, h) for k in (4, 5, 6) for h in range(1, 5)}:
        initial = [r['effective_cycle'] for r in rows if (r['kind'], r['hart']) == key]
        if not initial or min(initial) > start:
            errors.append('observer lacks state at ROI start ' + str(key))
    grouped = defaultdict(list)
    prefixes = sorted((r for r in rows if r['kind'] == 1), key=lambda r: r['cycle'])
    for i, row in enumerate(prefixes):
        old, new = row['d'][:2]
        if new < old:
            errors.append('prefix moved backwards')
        if new > old and row['cycle'] < stop:
            following = prefixes[i+1] if i+1 < len(prefixes) else None
            if following is None or following['cycle'] != row['cycle']+1 or following['d'][0] != new:
                errors.append('Next-to-registered prefix transition missing at next core edge')
    for row in rows:
        grouped[row['effective_cycle']].append(row)
    accepted, produced, seqs = {}, {}, defaultdict(dict)
    prefix = pending = None
    spans, holes, checkpoint, entry_bounds = [], {}, set(), {}
    last = None

    def interval(a, b):
        a, b = max(a, start), min(b, stop)
        if b <= a or pending is None or not bit(pending['d'][9], 0):
            return
        category, context = pending_class(pending, prefix, accepted, produced)
        if category is None:
            return
        if errors:
            category = 'UNRESOLVED'
        key = (category, context.get('entry'), context.get('target'), context.get('earliest_missing_predecessor'),
               context.get('release_bits'), context.get('phase'))
        if spans and spans[-1]['key'] == key and spans[-1]['end_cycle'] == a:
            spans[-1]['end_cycle'] = b; spans[-1]['cycles'] += b-a
        else:
            spans.append(dict(key=key, category=category, start_cycle=a, end_cycle=b, cycles=b-a, **context))
        if category == 'PREFIX_HOLE':
            hole = context['earliest_missing_predecessor']
            h = holes.setdefault(hole, dict(id=hole, interval_cycles=0, targets=set(), entries=set(),
                      passed_behind_area=0, max_passed_behind=0, first_cycle=a, last_cycle=b))
            h['interval_cycles'] += b-a; h['targets'].add(context['target']); h['entries'].add(context['entry'])
            n = prefix['d'][8]; h['passed_behind_area'] += n*(b-a)
            h['max_passed_behind'] = max(h['max_passed_behind'], n); h['last_cycle'] = b

    for cycle, batch in sorted(grouped.items()):
        if last is not None:
            interval(last, cycle)
        # Checkpoint is registered pre-edge state. Accepts override it even if
        # simulator print order is reversed at the same timestamp.
        for r in sorted(batch, key=lambda r: (r['kind'] != 9, r['time'], r['kind'], r['hart'])):
            d, k, hart = r['d'], r['kind'], r['hart']
            if k == 9:
                chunk, safe, alloc, complete, passed = d[:5]
                if chunk != hart or chunk in checkpoint or cycle > start:
                    errors.append('invalid/duplicate/late tagged checkpoint')
                checkpoint.add(chunk)
                for offset in range(8):
                    if bit(alloc, offset) and bit(complete, offset):
                        seq = d[5+offset]; accepted[seq] = 0 if bit(passed, offset) else -1
                        seqs[seq]['checkpoint_completion'] = True
            elif k == 2:
                seqs[d[0]]['allocated_cycle'] = cycle
                if d[1]:
                    errors.append('allocation collision')
            elif k == 3 and bit(d[1], 0):
                payload = d[0]; seq = payload & 0xffffffff; status = (payload >> 32) & 3
                seqs[seq].setdefault('boom_result_cycle', cycle)
                if bit(d[1], 1):
                    if status > 2:
                        errors.append('illegal accepted status')
                    if status in (1, 2):
                        errors.append('FAIL/CANCELLED accepted; correctness review required')
                    accepted[seq] = status
                    seqs[seq].update(accepted_cycle=cycle, status=status, checker=hart)
            elif k == 4 and bit(d[1], 0):
                seq = d[0] & 0xffffffff; status = (d[0] >> 32) & 3
                produced.setdefault(seq, dict(cycle=cycle, status=status, checker=hart, endpoint='CDC_ENQ'))
                seqs[seq].setdefault('endpoint_valid_cycle', cycle)
                if bit(d[1], 2):
                    seqs[seq].setdefault('cdc_enqueued_cycle', cycle)
            elif k == 5 and bit(d[1], 2):
                seqs[d[0] & 0xffffffff].setdefault('cdc_dequeued_cycle', cycle)
            elif k == 6:
                seq, f = d[0], d[2]
                if bit(f, 20) and d[14]:
                    seqs[d[14]].update(start_edge_seen=True, checker=hart,
                        checker_start_local_cycle=r['local'], checker_start_cycle=cycle)
                if seq:
                    e = seqs[seq]; e.update(checker=hart)
                    if d[9] == seq:
                        e['arf_epoch'] = d[1]
                    e.setdefault('checker_first_observed_cycle', cycle)
                    e['last_tail_count'] = d[4]
                    e.setdefault('tail_timeline', []).append(dict(cycle=cycle, time=r['time'],
                        local_cycle=r['local'], arf_epoch=d[1] if d[9] == seq else None,
                        raw_ecp_epoch=d[1], ecp_seq=d[9], compare_done_seq=d[10],
                        compare_done_epoch=d[11], checked_count=d[4],
                        encoded_count=d[5], flags=f, context_flags=d[3], pc=d[13]))
                    for flag, name in ((2, 'producer_sealed'), (3, 'ingress_drained'), (4, 'lsl_quiescent'),
                        (5, 'arf_complete'), (8, 'exec_done'), (9, 'full_check_complete'), (10, 'cleanup_done')):
                        if bit(f, flag):
                            if name == 'cleanup_done' and not (bit(f, 13) or bit(f, 14) or 'result_formed_cycle' in e):
                                continue
                            e.setdefault(name+'_cycle', cycle)
                            e.setdefault(name+'_local_cycle', r['local'])
                    # First observation may be a package already active at ROI.
                if bit(f, 16) or bit(f, 9) or bit(f, 18):
                    payload = d[7]; qseq = payload & 0xffffffff; status = (payload >> 32) & 3
                    produced.setdefault(qseq, dict(cycle=cycle, status=status, checker=hart, endpoint='RESULT_FORMED'))
                    seqs[qseq].setdefault('result_formed_cycle', cycle)
                    seqs[qseq].setdefault('completion_local_cycle', r['local'])
                    seqs[qseq]['arf_epoch_at_result'] = d[1] if d[9] == qseq else None
                if bit(f, 15):
                    payload = d[6]; qseq = payload & 0xffffffff; status = (payload >> 32) & 3
                    produced.setdefault(qseq, dict(cycle=cycle, status=status, checker=hart, endpoint='RESULT_QUEUE'))
                if bit(f, 17):
                    seqs[d[6] & 0xffffffff].setdefault('result_handoff_cycle', cycle)
            elif k == 7:
                for h, seq in enumerate(d[8:13]):
                    if h and seq:
                        seqs[seq].setdefault('assigned_checker', h)
                        seqs[seq].setdefault('assignment_first_observed_cycle', cycle)
            elif k == 8:
                was = pending
                if was is not None and bit(was['d'][9], 0) and (not bit(d[9], 0) or d[0] != was['d'][0]):
                    entry_bounds.setdefault(was['d'][0], {})['leave'] = cycle
                pending = r
                if bit(d[9], 0):
                    entry_bounds.setdefault(d[0], {}).setdefault('enter', cycle)
        ps = [r for r in batch if r['kind'] == 1]
        if len(ps) > 1:
            errors.append('duplicate main PREFIX at same cycle')
        if ps:
            prefix = ps[0]
        last = cycle
    if last is not None:
        interval(last, stop)
    if checkpoint != set(range(32)):
        errors.append('ROI-entry tagged bitmap checkpoint incomplete')
    # An event may be clipped by ROI or end while still pending; retain censoring.
    by_entry = defaultdict(list)
    for s in spans:
        by_entry[s['entry']].append(s)
    pending_events = []
    for entry, parts in by_entry.items():
        a, b = parts[0]['start_cycle'], parts[-1]['end_cycle']
        bounds = entry_bounds.get(entry, {})
        pending_events.append(dict(entry=entry, start_cycle=a, end_cycle=b, cycles=sum(s['cycles'] for s in parts),
            unsafe_cycles=sum(s['cycles'] for s in parts if s['unsafe']),
            boundary_clipped=bounds.get('enter', start) < start or bounds.get('leave', stop+1) > stop,
            long=sum(s['cycles'] for s in parts) >= LONG))
    if errors:
        for row in spans:
            row['observed_candidate_category'] = row['category']; row['category'] = 'UNRESOLVED'
        holes = {}  # Invalid coverage cannot leave authoritative-looking hole claims.
    totals, events = Counter(), defaultdict(set)
    long_entries = {p['entry'] for p in pending_events if p['long']}
    for s in spans:
        totals[s['category']] += s['cycles']; events[s['category']].add(s['entry'])
    total = sum(totals.values()); unsafe = sum(s['cycles'] for s in spans if s['unsafe'])
    delta = (stop-start)-1001675
    def table_for(parts):
        t, e = Counter(), defaultdict(set)
        denom = sum(s['cycles'] for s in parts)
        for s in parts:
            t[s['category']] += s['cycles']; e[s['category']].add(s['entry'])
        return [dict(category=c, events=len(e[c]), cycles=t[c],
            percent_pending=100*t[c]/denom if denom else None,
            percent_slowdown_delta=100*t[c]/delta if delta > 0 else None) for c in CATEGORIES]
    table = table_for(spans)
    long_table = table_for([s for s in spans if s['entry'] in long_entries])
    for hole, h in holes.items():
        h['targets'] = sorted(h['targets']); h['entries'] = sorted(h['entries'])
        h['later_passed_results_blocked_peak'] = h['max_passed_behind']
        h['predecessor'] = {k: v for k, v in seqs.get(hole, {}).items() if k != 'tail_timeline'}
        h['tail_timeline_reference'] = 'sequence_events.json:' + str(hole)
        h['epoch_semantics'] = 'ARF epoch is distinct from L1 slot epoch; unavailable epoch remains null'
        h['arf_epoch'] = seqs.get(hole, {}).get('arf_epoch')
        h['amplification_units'] = 'PASS-result count and PASS-result*cycle area, NOT main-core lost cycles'
    largest = max(table, key=lambda r: r['cycles']) if total else None
    mapping = {'RESULT_NOT_AVAILABLE': 'OPT2_TARGET_CHECKER_RESULT_LATENCY',
               'PREFIX_HOLE': 'OPT2_TARGET_PREFIX_HOLE_SERIALIZATION',
               'PREFIX_PROPAGATION_DELAY': 'OPT2_TARGET_WATERMARK_PROPAGATION',
               'POST_SAFE_WAIT': 'OPT2_TARGET_POST_SAFE_RELEASE'}
    decision = 'ROOT_CAUSE_STILL_UNRESOLVED'
    if not errors and largest and largest['cycles']/total >= .5:
        decision = mapping.get(largest['category'], decision)
    latency_fields = [('allocated_cycle', 'result_formed_cycle'), ('result_formed_cycle', 'accepted_cycle'),
                      ('cdc_enqueued_cycle', 'cdc_dequeued_cycle'), ('assignment_first_observed_cycle', 'accepted_cycle')]
    latencies = {a+'_to_'+b: distribution([e[b]-e[a] for e in seqs.values() if a in e and b in e and e[b] >= e[a]])
                 for a, b in latency_fields}
    per_checker = {}
    for hart in range(1, 5):
        own = [e for e in seqs.values() if e.get('checker') == hart]
        per_checker[hart] = dict(sequences_observed=len(own), accepted=sum('accepted_cycle' in e for e in own),
            allocation_to_accept_cycles=distribution([e['accepted_cycle']-e['allocated_cycle'] for e in own
                if 'accepted_cycle' in e and 'allocated_cycle' in e]))
        per_checker[hart]['checker_start_to_completion_local_cycles'] = distribution([
            e['completion_local_cycle']-e['checker_start_local_cycle'] for e in own
            if 'completion_local_cycle' in e and 'checker_start_local_cycle' in e
            and e['completion_local_cycle'] >= e['checker_start_local_cycle']])
    accepted_order = sorted((e['accepted_cycle'], seq) for seq, e in seqs.items() if e.get('status') == 0 and 'accepted_cycle' in e)
    high, inversions = 0, []
    for c, seq in accepted_order:
        if seq < high:
            inversions.append(dict(cycle=c, seq=seq, higher_seq_already_passed=high))
        high = max(high, seq)
    summary = dict(schema=3, input=str(path.resolve()), roi=[start, stop], roi_cycles=stop-start,
        coverage='COMPLETE' if not errors else 'INCOMPLETE', errors=sorted(set(errors)),
        pending_events=len(pending_events) if not errors else None,
        pending_cycles=total if not errors else None,
        strict_unsafe_waitsafe_cycles=unsafe if not errors else None,
        observed_partial_pending_cycles=total, population_complete=not bool(errors),
        post_safe_or_other_pending_cycles=total-unsafe, categories=table, long_event_categories=long_table,
        pending_distribution=distribution([p['cycles'] for p in pending_events if not p['boundary_clipped']]),
        long_event_threshold_cycles=LONG, long_event_count=len(long_entries), decision=decision,
        decision_scope='majority >=50% of observed pending; study target only, not critical-path proof or optimization authorization',
        normalization_delta_cycles=delta, clock_alignment=clock_fit, latency_distributions=latencies,
        per_checker=per_checker, out_of_order_accepted_results=inversions,
        load_imbalance='candidate comparison only; asynchronous clocks, unequal package work and censoring preclude a standalone proof',
        time_semantics='main pre-edge samples persist on [c,next); combinational Next includes current-edge accepts; registered watermark stays old until next edge',
        percent_policy='percent of all pending includes POST_SAFE_WAIT; strict unsafe denominator reported separately; delta normalization is NOT attributed slowdown',
        ROB_critical_path_cycles='UNRESOLVED', avoidable_cycles='UNRESOLVED',
        RUN_PROVENANCE='UNRESOLVED', full_cache_package_dram_drain='UNRESOLVED')
    out.mkdir(parents=True, exist_ok=False)
    for name, data in [('summary.json', summary), ('prefix_holes.json', list(holes.values())),
                       ('sequence_events.json', seqs), ('pending_events.json', pending_events)]:
        (out/name).write_text(json.dumps(data, indent=2)+'\n')
    with (out/'waitsafe_intervals.jsonl').open('x') as f:
        for row in spans:
            row.pop('key', None); f.write(json.dumps(row)+'\n')
    for name, data in [('categories.csv', table), ('long_event_categories.csv', long_table)]:
        with (out/name).open('x') as f:
            w = csv.DictWriter(f, fieldnames=list(data[0])); w.writeheader(); w.writerows(data)
    md = ['# Safe-chain observation result', '', decision, '',
          '| Category | Events | Cycles | % pending | % slowdown delta (normalization only) |',
          '|---|---:|---:|---:|---:|']
    md += [f"| {r['category']} | {r['events']} | {r['cycles']} | {r['percent_pending']} | {r['percent_slowdown_delta']} |" for r in table]
    md += ['', summary['decision_scope'], '', 'WaitSafe strictly unsafe cycles: '+str(unsafe)+'. All pending cycles: '+str(total)+'.',
           'UNRESOLVED: ROB critical-path attribution, avoidable loss, historical RUN_PROVENANCE and full cache/package/DRAM drain.',
           'RESULT_NOT_AVAILABLE includes formed PASS awaiting mandatory cleanup/transport/acceptance; see per-interval phase.',
           'This parser reports safe-chain observations. The separate opt3_summary.json describes the fused checker experiment.']
    (out/'README.md').write_text('\n'.join(md)+'\n')
    print(json.dumps(summary, indent=2))
    return summary
