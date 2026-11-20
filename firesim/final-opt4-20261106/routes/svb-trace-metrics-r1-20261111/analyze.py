#!/usr/bin/python3
"""Measure real pre-edge component events; FPGA attribution requires replay PASS.

Never infers checker-completion latency or architectural rollback from SVB ACK.
The reference trace remains RTL data until the exact trace, driver, all compared
outputs, board and certificate have a successful bound hardware receipt.
"""
import argparse
from collections import Counter
import csv
import hashlib
import json
import math
from pathlib import Path
import statistics
import sys

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
sys.path.insert(0, str(W / 'scripts'))
from board_batch import save

BASE = '8491167d84b6d9521b151a743673c1516926a1f8'


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def read(p):
    return json.loads(Path(p).read_text())


def distribution(values):
    a = sorted(values)
    if not a:
        return {'count': 0, 'sum': 0, 'mean': None, 'median': None,
                'p95': None, 'p99': None, 'max': None, 'histogram': {}}
    return dict(count=len(a), sum=sum(a), mean=statistics.mean(a),
                median=statistics.median(a), p95=a[math.ceil(.95*len(a))-1],
                p99=a[math.ceil(.99*len(a))-1], max=a[-1],
                histogram=dict(sorted(Counter(a).items())))


def analyze(trace, binding):
    assert binding['functional_baseline'] == BASE
    assert sha(trace) == binding['trace_sha256'], 'trace binding mismatch'
    inp = binding['input_ports']; out = binding['output_ports']
    fields = inp + out
    assert len({n for n, _ in fields}) == len(fields)
    start = binding['compare_from_cycle']
    rows = trace.read_text().splitlines()
    assert len(rows) == binding['target_cycles']
    live = {}; segment = 0; samples = []; events = []; counters = Counter()
    outstanding = []

    def key(r, prefix):
        return tuple(r[prefix+n] for n in ['valid', 'writer', 'generation', 'contentSeq'])

    for c, line in enumerate(rows):
        a = line.split()
        assert int(a[0]) == c and len(a) == 1 + len(fields), ('trace record shape', c)
        r = {}
        for (n, width), text in zip(fields, a[1:]):
            v = int(text, 16)
            assert 0 <= v < 2**width, ('trace field width', c, n)
            r[n] = v
        if c < start:
            continue
        counters['compared_cycles'] += 1
        if r['reset']:
            if live:
                outstanding.extend(dict(x, censored_cycle=c, censor_reason='reset')
                                   for x in live.values() if 'ack_cycle' not in x)
            live.clear(); segment += 1
            counters['reset_cycles'] += 1
            continue
        counters['nonreset_cycles'] += 1
        counters['capture_backpressure_cycles'] += bool(r['io_capture_valid'] and not r['io_capture_ready'])
        counters['promotion_backpressure_cycles'] += bool(r['io_promote_valid'] and not r['io_promote_ready'])
        assert r['io_allocation'] == int(bool(r['io_capture_valid'] and r['io_capture_ready'])), ('allocation/fire', c)
        assert r['io_promotion'] == int(bool(r['io_promote_valid'] and r['io_promote_ready'])), ('promotion/fire', c)
        counters['invalidations'] += r['io_invalidate_valid']
        counters['coalesced_entries'] += r['io_coalesced']
        counters['discarded_entries'] += r['io_discarded']
        counters['flush_cycles'] += r['io_flush']
        counters['max_occupancy'] = max(counters['max_occupancy'], r['io_occupancy'])

        # All values are sampled before the same target rising edge. Allocation,
        # promote.fire and matched ACK become effective at that edge; deltas
        # use the difference between these edge indices, with no host time.
        if r['io_allocation']:
            entry = r['io_allocatedEntry']
            identity = (segment, entry, key(r, 'io_capture_bits_key_'))
            assert identity not in live, ('duplicate live allocation identity', c, identity)
            x = dict(segment=segment, entry=entry,
                     key=list(identity[-1]), capture_cycle=c,
                     line=r['io_capture_bits_line'], epoch=r['io_capture_bits_epoch'])
            live[identity] = x
            events.append(dict(event='CAPTURE_FIRE', cycle=c, **x))
            counters['captures'] += 1
        if r['io_promote_valid']:
            identity = (segment, r['io_promote_bits_entry'], key(r, 'io_promote_bits_key_'))
            assert identity in live, ('promoted identity was not allocated', c, identity)
            x = live[identity]
            assert r['io_promote_bits_line'] == x['line'] and r['io_promote_bits_epoch'] == x['epoch']
            if 'first_promote_valid_cycle' not in x:
                x['first_promote_valid_cycle'] = c
                events.append(dict(event='FIRST_PROMOTE_VALID', cycle=c, segment=segment,
                                   entry=x['entry'], key=x['key']))
            if r['io_promotion']:
                assert 'promotion_cycle' not in x, ('duplicate promotion', c, identity)
                x['promotion_cycle'] = c
                counters['promotions'] += 1
                events.append(dict(event='PROMOTE_FIRE', cycle=c, segment=segment,
                                   entry=x['entry'], key=x['key']))
        if r['io_acked']:
            assert r['io_ack_valid'], ('ACK output without input', c)
            identity = (segment, r['io_ack_bits_entry'], key(r, 'io_ack_bits_key_'))
            assert identity in live, ('ACK identity was not allocated', c, identity)
            x = live[identity]
            assert 'promotion_cycle' in x and 'ack_cycle' not in x, ('ACK ordering/duplicate', c)
            x['ack_cycle'] = c
            x['capture_to_first_valid_cycles'] = x['first_promote_valid_cycle']-x['capture_cycle']
            x['capture_to_promote_fire_cycles'] = x['promotion_cycle']-x['capture_cycle']
            x['promote_fire_to_ack_cycles'] = c-x['promotion_cycle']
            x['capture_to_ack_cycles'] = c-x['capture_cycle']
            samples.append(dict(x)); del live[identity]
            counters['acks'] += 1
            events.append(dict(event='MATCHED_ACK', cycle=c, segment=segment,
                               entry=x['entry'], key=x['key']))
    outstanding.extend(dict(x, censored_cycle=len(rows), censor_reason='trace_end')
                       for x in live.values())
    counters['unmatched_capture_records'] = len(outstanding)
    metrics = {n: distribution([s[n] for s in samples]) for n in [
        'capture_to_first_valid_cycles', 'capture_to_promote_fire_cycles',
        'promote_fire_to_ack_cycles', 'capture_to_ack_cycles']}
    return dict(counters=dict(counters), matched_samples=samples,
                unmatched_capture_records=outstanding, events=events,
                distributions=metrics,
                observed_ack_per_nonreset_target_cycle=counters['acks']/counters['nonreset_cycles'],
                quantile_definition='nearest-rank P95/P99; exact 1 target-cycle histogram buckets',
                caveats=[
                    'Synthetic directed trace; includes intentional watermark/ready/ACK delays, not an application latency distribution or peak throughput.',
                    'Only matched capture/promote/ACK identities enter latency distributions; all other captures remain explicitly listed as censored. Coalesced/discarded count is reported without guessing per-entry retirement.',
                    'ACK means original SVB completion; it does not prove checker completion or architectural rollback/restart.',
                    'First 39 initialization cycles excluded because their payload values were not covered by the validated all-output replay.',
                    'Edge-index differences preserve target-cycle time; host wall time is reported separately.'])


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--reference', type=Path, default=D/'cycleprecise-frozen-svb-trace-r4-20261111')
    ap.add_argument('--hardware-run', type=Path)
    ap.add_argument('--out', type=Path, required=True)
    args = ap.parse_args()
    binding = read(args.reference/'binding.json')
    metrics = analyze(args.reference/'target-cycles.txt', binding)
    result = dict(schema='ec-original-svb-event-metrics/1',
        kind='TARGET_RTL_DIRECTED_TRACE_METRICS_NOT_FPGA',
        functional_baseline=BASE, trace_sha256=binding['trace_sha256'],
        binding_path=str(args.reference/'binding.json'),
        binding_sha256=sha(args.reference/'binding.json'), **metrics)
    if args.hardware_run:
        run = args.hardware_run
        r = read(run/'result.json'); c = read(run/'complete.json')
        cert = read(run/'certified-component.json')
        assert c['result_sha256'] == sha(run/'result.json')
        assert r['status'] == 'VALID_COMPONENT_FPGA_TRACE'
        assert r['functional_baseline'] == BASE
        assert r['board_bdf'] == '0000:21:00.0' and r['board_serial'] == '21770433G02LA'
        assert r['returncode'] == 0 and r['compared_output_values'] == 42291
        assert r['certificate_sha256'] == sha(run/'certified-component.json')
        assert cert['driver']['trace_sha256'] == binding['trace_sha256']
        assert r['source_id'] == cert['source_id']
        assert sha(cert['driver']['binary']) == cert['driver']['binary_sha256']
        assert sha(cert['bitstream']) == cert['bitstream_sha256']
        assert sha(r['raw_log']) == r['raw_log_sha256']
        log = Path(r['raw_log']).read_text(errors='replace')
        assert 'PASS_SVB_TRACE target_cycles=372 compared_fields=42291' in log
        assert '[SVBProbe]PASS Test' in log
        assert not any(s in log for s in ['TARGET_HOST_MISMATCH','unstable value','*** FAILED','Assertion failed'])
        result.update(kind='FPGA_VALIDATED_ORIGINAL_SVB_DIRECTED_TRACE_EVENT_METRICS',
                      hardware_result=str(run/'result.json'), hardware_result_sha256=sha(run/'result.json'),
                      host_wall_seconds=r['host_wall_seconds'], board_bdf=r['board_bdf'],
                      board_serial=r['board_serial'], application_trace=False,
                      formal_parsec_sample=False)
    args.out.mkdir(parents=True, exist_ok=True)
    assert not (args.out/'complete.json').exists(), 'completed output immutable'
    for name, rows in [('events', result.pop('events')),
                       ('matched_samples', result.pop('matched_samples')),
                       ('unmatched_capture_records', result.pop('unmatched_capture_records'))]:
        target = args.out/(name+'.json')
        assert not target.exists(), 'preserve partial outputs; use new recovery directory'
        save(target, rows)
        result[name+'_path'] = str(target)
        result[name+'_sha256'] = sha(target)
    save(args.out/'result.json', result)
    save(args.out/'complete.json', {'result_sha256':sha(args.out/'result.json')})
    print(json.dumps({k:result[k] for k in ['kind','counters','distributions']}, sort_keys=True))


if __name__ == '__main__':
    main()
