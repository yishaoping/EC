"""Offline-only Opt2 metrics; preserves the original safe-chain classification.

No subprocesses, simulation, hardware generation or waveform parsing. The
legacy parser validates coverage first; this layer splits its transport phase
and reports censored/unobserved metrics explicitly instead of inventing them.
"""
import json
from collections import Counter, defaultdict
from pathlib import Path

from compact_causality import align_clocks, bit, distribution, read_events

BASELINE = 1001675
ORIGINAL = 4734881
OPT1 = 4706513
CATEGORIES = ('RESULT_NOT_AVAILABLE', 'RESULT_TRANSFER_DELAY', 'PREFIX_HOLE',
              'WATERMARK_PROPAGATION_DELAY', 'POST_SAFE_RELEASE', 'MULTI_CAUSE',
              'UNRESOLVED')


def load_safe_chain_reference():
    """Read the small versioned reference; original run products stay local."""
    reference = Path(__file__).with_name('reference_safe_chain_summary.json')
    before = json.loads(reference.read_text())
    if (before['schema'] != 1 or before['pending_cycles'] != 3178984 or
            before['latency_distributions']['result_formed_cycle_to_accepted_cycle']['n'] != 332):
        raise ValueError('Pinned safe-chain summary does not match the reviewed run')
    return reference, before


def category(row):
    name = row['category']
    if name == 'RESULT_NOT_AVAILABLE' and row.get('phase') == 'pre_accept_transport_or_cleanup':
        return 'RESULT_TRANSFER_DELAY'
    return {'PREFIX_PROPAGATION_DELAY': 'WATERMARK_PROPAGATION_DELAY',
            'POST_SAFE_WAIT': 'POST_SAFE_RELEASE'}.get(name, name)


def release_stage(flags):
    # Exclusive stage, not a claim that every active bit independently blocks.
    if any(bit(flags, b) for b in (18, 23, 24)):
        return 'revocation_or_recovery'
    guards = [name for b, name in ((6, 'slot'), (7, 'drain'),
              (8, 'completion'), (9, 'probe')) if bit(flags, b)]
    if guards:
        return 'admission:' + '+'.join(guards)
    if bit(flags, 4):
        return 'metadata_clear'
    if bit(flags, 3):
        return 'writeback_receipt'
    if bit(flags, 12):
        return 'writeback_fire_edge'
    if bit(flags, 10) and not bit(flags, 11):
        return 'writeback_ready'
    return 'admission_or_release_edge'


def extend_analysis(events, roi, out):
    out = Path(out)
    legacy = json.loads((out/'summary.json').read_text())
    with (out/'waitsafe_intervals.jsonl').open() as stream:
        spans = [json.loads(line) for line in stream]
    seqs = json.loads((out/'sequence_events.json').read_text())
    rows, footers, errors = read_events(Path(events))
    fit = align_clocks(rows, errors)
    if legacy['coverage'] != 'COMPLETE' or errors:
        raise ValueError('Refuse Opt2 comparison with incomplete event coverage: ' + str(errors))
    counts, entries = Counter(), defaultdict(set)
    production, transfer, release, terminal = Counter(), Counter(), Counter(), Counter()
    sealed_phases = Counter()
    last_by_entry = {}
    for r in spans:
        name, n = category(r), r['cycles']
        counts[name] += n
        entries[name].add(r['entry'])
        last_by_entry[r['entry']] = r
        s = seqs.get(str(r.get('target')), {})
        a, b = r['start_cycle'], r['end_cycle']
        if name == 'RESULT_NOT_AVAILABLE':
            done = s.get('exec_done_cycle')
            if done is None:
                production['execution_milestone_missing'] += n
            else:
                before = max(0, min(b, done)-a)
                production['before_exec_done'] += before
                production['exec_done_to_result'] += n-before
            sealed = s.get('producer_sealed_cycle')
            if sealed is None or done is None:
                sealed_phases['missing_milestone'] += n
            else:
                unsealed = max(0, min(b, sealed)-a)
                executing = max(0, min(b, done)-max(a, sealed))
                sealed_phases['before_producer_seal'] += unsealed
                sealed_phases['sealed_before_exec_done'] += executing
                sealed_phases['after_exec_done'] += n-unsealed-executing
        if name == 'RESULT_TRANSFER_DELAY':
            enq, deq = s.get('cdc_enqueued_cycle'), s.get('cdc_dequeued_cycle')
            if enq is None or deq is None:
                transfer['missing_endpoint'] += n
            else:
                pre = max(0, min(b, enq)-a)
                cdc = max(0, min(b, deq)-max(a, enq))
                transfer['formed_to_enqueue_cleanup'] += pre
                transfer['cdc'] += cdc
                transfer['dequeue_to_accept'] += n-pre-cdc
        if name == 'POST_SAFE_RELEASE':
            release[release_stage(r['release_bits'])] += n
    for r in last_by_entry.values():
        terminal[release_stage(r['release_bits'])] += 1
    total = sum(counts.values())
    if total != legacy['pending_cycles']:
        raise ValueError('Nonexclusive or incomplete pending partition')
    actual = roi['stop_cycle']-roi['start_cycle']
    delta = actual-BASELINE
    table = [dict(category=k, events=len(entries[k]), cycles=counts[k],
                  percent_pending=100*counts[k]/total if total else 0,
                  percent_current_roi=100*counts[k]/actual,
                  percent_slowdown_delta=100*counts[k]/delta if delta else None)
             for k in CATEGORIES]
    pairs = (('allocated_cycle', 'checker_start_cycle'),
             ('checker_start_cycle', 'producer_sealed_cycle'),
             ('checker_start_cycle', 'exec_done_cycle'),
             ('producer_sealed_cycle', 'result_formed_cycle'),
             ('exec_done_cycle', 'result_formed_cycle'),
             ('allocated_cycle', 'result_formed_cycle'),
             ('result_formed_cycle', 'cdc_enqueued_cycle'),
             ('cdc_enqueued_cycle', 'cdc_dequeued_cycle'),
             ('cdc_dequeued_cycle', 'accepted_cycle'))
    latencies = {a+'_to_'+b: distribution([s[b]-s[a] for s in seqs.values()
                 if a in s and b in s and s[b] >= s[a]]) for a, b in pairs}
    # Global frontier episodes: exact tagged earliest *allocated* missing
    # predecessor, including time before any later PASS exists. Kept separate
    # from the shorter period when it actually holds a later PASS behind it.
    prefixes = sorted((r for r in rows if r['kind'] == 1), key=lambda r: r['cycle'])
    holes = {}
    for i, r in enumerate(prefixes):
        a = max(r['cycle'], roi['start_cycle'])
        b = min(prefixes[i+1]['cycle'] if i+1 < len(prefixes) else roi['stop_cycle'], roi['stop_cycle'])
        d = r['d']; hole = d[2]
        if b <= a or d[3] != hole or not bit(d[4], 0) or bit(d[4], 1):
            continue
        h = holes.setdefault(hole, dict(id=hole, first_cycle=a, last_cycle=b,
             frontier_missing_cycles=0, pass_blocking_cycles=0, passed_result_cycle_area=0,
             max_passed_behind=0, max_lead_distance=0, blocked_entries=set(),
             pending_prefix_cycles=0, arf_epoch=seqs.get(str(hole), {}).get('arf_epoch_at_result')))
        h['last_cycle'] = b
        h['frontier_missing_cycles'] += b-a
        if d[8]:
            h['pass_blocking_cycles'] += b-a
            h['passed_result_cycle_area'] += (b-a)*d[8]
            h['max_passed_behind'] = max(h['max_passed_behind'], d[8])
            leads = [int(k)-hole for k, s in seqs.items() if int(k) > hole and
                     s.get('status') == 0 and s.get('accepted_cycle', b) <= a]
            h['max_lead_distance'] = max([h['max_lead_distance'], *leads])
    for r in spans:
        if category(r) == 'PREFIX_HOLE':
            h = holes.get(r['earliest_missing_predecessor'])
            if h:
                h['blocked_entries'].add(r['entry'])
                h['pending_prefix_cycles'] += r['cycles']
    for h in holes.values():
        h['blocked_entries'] = sorted(h['blocked_entries'])
        h['observed_wall_lifetime'] = h['last_cycle']-h['first_cycle']
        h['roi_clipped'] = h['first_cycle'] == roi['start_cycle'] or h['last_cycle'] == roi['stop_cycle']
    amplified = [h for h in holes.values() if h['max_passed_behind']]
    assignments = Counter(s.get('assigned_checker') for s in seqs.values() if 'assigned_checker' in s)
    correctness = Counter()
    for r in rows:
        if r['kind'] == 2:
            correctness['allocation_collisions'] += bool(r['d'][1])
        if r['kind'] == 3:
            for b, label in ((1, 'accepted'), (2, 'stale_level_observations'),
                             (3, 'held_duplicate_observations'), (4, 'failed'), (5, 'cancelled')):
                correctness[label] += bit(r['d'][1], b)
    result = dict(schema=1, event_coverage=legacy['coverage'], clock_alignment=fit,
        performance=dict(baseline_roi=BASELINE, original_current_roi=ORIGINAL, opt1_roi=OPT1,
             measured_roi=actual, gain_from_opt1_reference=OPT1-actual,
             total_gain=ORIGINAL-actual, slowdown_delta=delta,
             caution='Historical phase definitions use Opt1 reference; Opt2b performance is in opt2b_summary.json'),
        pending_cycles=total, strict_unsafe_waitsafe_cycles=legacy['strict_unsafe_waitsafe_cycles'],
        categories=table, production_wait_cycles=dict(production), transfer_wait_cycles=dict(transfer),
        production_seal_phases=dict(sealed_phases),
        latency_distributions=latencies, checker_assignments=dict(sorted(assignments.items())),
        post_safe_exclusive_stage_cycles=dict(release), terminal_observed_stage_entries=dict(terminal),
        hole_summary=dict(global_allocated_frontiers=len(holes), amplified_holes=len(amplified),
            max_observed_frontier_lifetime=max((h['observed_wall_lifetime'] for h in holes.values()), default=0),
            max_pass_blocking_cycles=max((h['pass_blocking_cycles'] for h in amplified), default=0),
            passed_behind_peak=distribution([h['max_passed_behind'] for h in amplified]),
            mean_passed_behind_peak=sum(h['max_passed_behind'] for h in amplified)/len(amplified) if amplified else 0,
            blocked_entries=distribution([len(h['blocked_entries']) for h in amplified]),
            mean_blocked_entries=sum(len(h['blocked_entries']) for h in amplified)/len(amplified) if amplified else 0,
            passed_result_cycle_area=sum(h['passed_result_cycle_area'] for h in amplified),
            pending_prefix_cycles=sum(h['pending_prefix_cycles'] for h in holes.values())),
        correctness=dict(correctness), downstream=dict(
            commit_gate=dict(value=None, status='UNOBSERVED: no ready-head/commit per-cycle predicate in SC1'),
            mshr_lifetime=dict(value=None, status='UNOBSERVED: no allocation/free/state lifetimes in SC1'),
            set_collateral=dict(value=None, status='UNOBSERVED: no continuous collateral-hit opportunities in SC1'),
            replay_nack=dict(value=None, status='UNOBSERVED: no counted replay/nack events in SC1')),
        decision=legacy['decision'], critical_path_attributed_cycles=None, avoidable_cycles=None,
        limitations=['Pending-state cycles are not an additive causal ROI budget.',
          'Ingress/LSL early samples are censored; do not integrate them as continuous blockers.',
          'Terminal observed stage is a protocol stage, not proof of one exclusive ACK/DRAM cause.',
          'Package release is distinct from software completion; full drain and RUN_PROVENANCE unresolved.'])
    for name, value in (('optimization2_metrics.json', result), ('global_prefix_holes.json', list(holes.values()))):
        with (out/name).open('x') as stream:
            json.dump(value, stream, indent=2); stream.write('\n')
    reference, before = load_safe_chain_reference()
    reference_metrics = json.loads(Path(__file__).with_name('reference_safe_chain_metrics.json').read_text())
    comparison = dict(reference=before['source'], reference_snapshot=str(reference),
        reference_source_sha256=before['source_sha256'], before=before['latency_distributions'],
        after=latencies, before_pending_cycles=before['pending_cycles'], after_pending_cycles=total,
        before_prefix_cycles=87361, after_prefix_cycles=counts['PREFIX_HOLE'],
        before_result_unformed_cycles=2993080, after_result_unformed_cycles=counts['RESULT_NOT_AVAILABLE'],
        before_transfer_cycles=3720, after_transfer_cycles=counts['RESULT_TRANSFER_DELAY'],
        before_propagation_cycles=178, after_propagation_cycles=counts['WATERMARK_PROPAGATION_DELAY'],
        before_post_safe_cycles=78275, after_post_safe_cycles=counts['POST_SAFE_RELEASE'],
        before_hole_summary=reference_metrics['hole_summary'], after_hole_summary=result['hole_summary'],
        before_checker_assignments=reference_metrics['checker_assignments'], after_checker_assignments=result['checker_assignments'],
        before_downstream=reference_metrics['downstream'], downstream=result['downstream'],
        performance=result['performance'], correctness=result['correctness'])
    with (out/'optimization2_comparison.json').open('x') as stream:
        json.dump(comparison, stream, indent=2); stream.write('\n')
    return result
