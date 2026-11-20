#!/usr/bin/python3
"""Independent replay checker coverage proof and full-trace count oracle.

Never starts a simulation, CAD or board operation. Full binary traversal is a
separate broker analysis; --prepare only checks small sources and receipts.
"""
from pathlib import Path
import argparse
import ast
import copy
import datetime
import hashlib
import itertools
import json
import math
import os
import re
import struct

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
O = D/'build-logs/Opt4-svb-replay-coverage-round46-v1-20261111'
U = D/'unattended-opt4'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
TARGET = W/'candidates/full-svb-binary-replay-r1-20261111'
STREAM = W/'candidates/full-svb-gg-stream-replay-r2-20261111'
GG = D/'cycleprecise-original-svb-gg-stream-replay-r3-20261111'
OBS = D/'cycleprecise-frozen-full-gg-external-observer-r5-20261111'
REPLAY = D/'cycleprecise-original-svb-binary-replay-r1-20261111'


def read(path):
    return json.loads(Path(path).read_text())


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for chunk in iter(lambda: stream.read(2**20), b''):
            h.update(chunk)
    return h.hexdigest()


def write_once(path, value):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    temp = path.with_name(path.name + '.preparing-' + str(os.getpid()))
    with temp.open('x') as stream:
        json.dump(value, stream, indent=2, sort_keys=True)
        stream.write('\n')
        stream.flush()
        os.fsync(stream.fileno())
    try:
        os.link(temp, path)
    finally:
        temp.unlink()


def policy():
    p = read(U/'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert not p['functional_extensions_allowed'] and not p['fpga_access']
    assert p['native_paused'] and p['board_allowlist'] == ['0000:21:00.0']


def evaluate(condition, signals):
    expression = condition.replace('d.', '').replace('&&', ' and ').replace('||', ' or ')
    node = ast.parse(expression, mode='eval')
    for item in ast.walk(node):
        assert isinstance(item, (ast.Expression, ast.BoolOp, ast.And, ast.Or,
                                 ast.Name, ast.Load)), ('unknown predicate', condition)
        if isinstance(item, ast.Name):
            assert item.id in signals
    return bool(eval(compile(node, '<restricted predicate>', 'eval'),
                     {'__builtins__': {}}, signals))


def group(name):
    if name.startswith('io_promote_bits_'):
        return 'promote_payload'
    if name.startswith('io_active'):
        return 'active_payload'
    if name.startswith('io_releaseBlocking'):
        return 'release_payload'
    return 'always'


def stream_defined(name, signals):
    defined = signals['known_reset']
    if group(name) == 'promote_payload':
        defined &= signals['io_promote_valid']
    if group(name) == 'active_payload':
        defined &= (signals['io_selected'] or signals['io_promote_valid'] or signals['io_ack_valid'])
    if group(name) == 'release_payload':
        defined &= signals['io_releaseBlocked_3']
    return bool(defined)


def coverage(layout, target, stream):
    fields = [field for field in layout['fields'] if field.get('direction')]
    assert len(fields) == 62 and fields[0]['name'] == 'clock'
    ports = [field for field in fields if field['name'] != 'clock']
    table = re.findall(r'^\{"(\w+)",(\d+),(\d+),(\d+),(true|false)\},$', stream, re.M)
    expected = [(f['name'], str(f['word_offset']), str(f['word_count']),
                 str(f['width']), 'true' if f['direction'] == 'input' else 'false') for f in ports]
    assert table == expected, 'stream port table does not exactly match complete layout'
    covered = [f['word_offset'] + i for f in ports for i in range(f['word_count'])]
    assert sorted(covered) == list(range(7, 101)) and len(covered) == len(set(covered))

    body = target.split('void outputs(VSpeculativeVersionBuffer& d,const Row& row,bool known_reset) {', 1)[1].split('\n }', 1)[0]
    checks = []
    for line in body.strip().splitlines():
        match = re.fullmatch(r'\s*if\((.*)\)check\("(\w+)\[(\d+)\]",row\[(\d+)\],(.*)\);', line)
        assert match, ('unparsed target checker', line)
        condition, name, word, offset, actual = match.groups()
        checks.append(dict(condition=condition, name=name, word=int(word), offset=int(offset)))
        allowed = [f'uint32_t((uint64_t(d.{name})>>{32*int(word)}))', f'uint32_t(d.{name}[{word}])']
        assert actual in allowed, ('actual output getter mismatch', name, word)
    outputs = [f for f in ports if f['direction'] == 'output']
    expected_words = [(f['name'], i, f['word_offset']+i) for f in outputs for i in range(f['word_count'])]
    assert [(c['name'], c['word'], c['offset']) for c in checks] == expected_words
    assert len(checks) == 46 and len(outputs) == 31

    body = target.split('static void drive(VSpeculativeVersionBuffer& d,const Row& row) {', 1)[1].split('\n}', 1)[0]
    driven = []
    for line in body.strip().splitlines():
        if line.strip() == 'd.io_resetStats=0;d.io_countStats=0;':
            continue
        scalar = re.fullmatch(r'\s*d\.(\w+)=get\(row,(\d+),(\d+)\);', line)
        wide = re.fullmatch(r'\s*for\(unsigned j=0;j<(\d+);\+\+j\)d\.(\w+)\[j\]=row\[(\d+)\+j\];', line)
        assert scalar or wide, ('unparsed input driver', line)
        if scalar:
            name, offset, count = scalar.groups()
        else:
            count, name, offset = wide.groups()
        driven.append((name, int(offset), int(count)))
    assert driven == [(f['name'], f['word_offset'], f['word_count']) for f in ports if f['direction'] == 'input']

    # Fail closed if the real GG masking code or edge sequencing changes.
    mask = stream.split('bool defined=known_reset;', 1)[1].split('if(!defined)continue;', 1)[0]
    assert mask.strip().splitlines() == [
        'if(name.starts_with("io_promote_bits_"))defined&=row[42]!=0;',
        '    if(name.starts_with("io_active"))defined&=(row[68]||row[42]||row[93]);',
        '    if(name.starts_with("io_releaseBlocking"))defined&=row[87]!=0;']
    assert 'if(s=="+svb-force-all-inputs")cache_inputs=false;' in stream
    assert 'bool changed=!cache_inputs||rows==0;' in stream
    assert 'previous=row;step(1);stable();if(row[7]){known_reset=true;++resets;}++rows;' in stream
    assert 'c.tick=tick;c.outputs(d,row,known_reset);\n  step(d);if(d.reset){known_reset=true;++reset_edges;}' in target
    assert stream.index('for(const auto&p:ports){if(p.input)continue;') < stream.index('previous=row;step(1);')
    assert 'peek("io_occupancy");stable();' in stream

    # Actual DUT guard controls are compared before the guarded outputs. The
    # ACK valid guard is an input. This establishes mask agreement by induction
    # over the ordered checker, rather than assuming unverified DUT outputs.
    order = {f['name']: i for i, f in enumerate(outputs)}
    dependencies = {'promote_payload': ['io_promote_valid'],
                    'active_payload': ['io_selected', 'io_promote_valid'],
                    'release_payload': ['io_releaseBlocked_3'], 'always': []}
    for f in outputs:
        for dependency in dependencies[group(f['name'])]:
            assert group(dependency) == 'always' and order[dependency] < order[f['name']]
    keys = ['known_reset', 'io_promote_valid', 'io_selected', 'io_ack_valid', 'io_releaseBlocked_3']
    valuations = list(itertools.product([False, True], repeat=len(keys)))
    for values in valuations:
        signals = dict(zip(keys, values))
        for check in checks:
            assert evaluate(check['condition'], signals) == stream_defined(check['name'], signals), ('mask mismatch', check, signals)
    return dict(original_ports_including_clock=62, driven_input_ports=30,
                compared_output_ports=31, driven_input_words_per_edge=48,
                possible_defined_output_words_per_edge=46,
                predicate_control_valuations=len(valuations),
                predicate_word_checks=len(valuations)*len(checks),
                output_words=checks, output_groups={f['name']: group(f['name']) for f in outputs},
                mask_dependency_order_proved=True,
                scope='Checker interface, mapping and defined-mask proof; not RTL equivalence or a new replay result.')


def summary(text):
    match = re.search(r'^REPLAY_SUMMARY (.*)$', text, re.M)
    assert match
    return {k: int(v) for k, v in (item.split('=') for item in match[1].split())}


def prepare():
    policy()
    assert not (C/'plan.json').exists(), 'adopt existing immutable preflight'
    layout = read(TARGET/'binary-layout.json')
    target = (TARGET/'replay.cpp').read_text()
    stream = (STREAM/'StreamingReplay.cc').read_text()
    target_plan, stream_plan = read(TARGET/'plan.json'), read(STREAM/'plan.json')
    assert sha(TARGET/'replay.cpp') == target_plan['replay_source_sha256']
    assert sha(STREAM/'StreamingReplay.cc') == stream_plan['inputs'][str(STREAM/'StreamingReplay.cc')]
    assert sha(TARGET/'binary-layout.json') == target_plan['layout_sha256'] == sha(STREAM/'binary-layout.json')
    proof = coverage(layout, target, stream)
    mutations = {
        'omit_last_128bit_promotion_payload': stream.replace('{"io_promote_bits_data_3",63,4,128,false},', ''),
        'wrong_capture_word_offset': stream.replace('{"io_capture_bits_data_3",30,4,128,true},', '{"io_capture_bits_data_3",29,4,128,true},'),
        'wrong_release_mask': stream.replace('defined&=row[87]!=0;', 'defined&=row[84]!=0;'),
        'disable_force_all_switch': stream.replace('cache_inputs=false;', 'cache_inputs=true;'),
        'omit_target_edge_step': stream.replace('previous=row;step(1);', 'previous=row;')}
    rejected = []
    for name, mutated in mutations.items():
        try:
            coverage(layout, target, mutated)
        except (AssertionError, IndexError, KeyError):
            rejected.append(name)
        else:
            raise AssertionError(('coverage mutation survived', name))
    result = read(REPLAY/'full-result.json')
    observed = read(OBS/'full-result.json')
    assert result['passed'] and result['actual_payload_mutation_rejected'] and not result['fpga_access']
    assert result['original_full_metasim_result_sha256'] == sha(OBS/'full-result.json')
    parsed = {}
    for kind in ['positive', 'negative']:
        record = result[kind]
        assert sha(record['log']) == record['log_sha256']
        parsed[kind] = summary(Path(record['log']).read_text())
    positive, negative = parsed['positive'], parsed['negative']
    assert positive['cycles'] == observed['binary_integrity']['records']
    assert positive['mismatches'] == positive['mutation_applied'] == 0
    assert negative['mismatches'] == negative['mutation_applied'] == 1
    assert all(negative[k] == positive[k] for k in positive if k not in ['mismatches', 'mutation_applied'])
    records = positive['cycles']
    prep = read(GG/'result.json')
    measured = max(prep['reused_real_startup_positive']['host_wall_seconds']/10000,
                   prep['directed']['host_wall_seconds']/prep['directed']['summary']['records'])
    timeout = math.ceil(3*measured*records+600)
    assert 0 < timeout <= 86400
    required = dict(records=records, target_cycles=records, first_source_tick=positive['first_tick'],
                    last_source_tick=positive['last_tick'], reset_edges=positive['reset_edges'],
                    defined_output_word_checks=positive['defined_output_word_checks'],
                    input_word_writes=records*proof['driven_input_words_per_edge'], input_cache_enabled=0,
                    mismatches=0, mutation_applied=0,
                    **{key: observed['binary_integrity']['counts'][count] for key, count in [
                        ('capture_accepted', 'capture_accepted'), ('promote_accepted', 'promote_accepted'), ('acked', 'ack_accepted')]})
    paths = [TARGET/'binary-layout.json', TARGET/'replay.cpp', TARGET/'plan.json',
             STREAM/'StreamingReplay.cc', STREAM/'plan.json', C/'audit.py',
             REPLAY/'full-result.json', OBS/'full-result.json', GG/'result.json']
    paths += [Path(result[k]['log']) for k in ['positive', 'negative']]
    pins = {str(path): sha(path) for path in paths}
    value = dict(schema='ec-original-svb-replay-coverage/1',
                 status='PASS_SOURCE_BOUND_PORT_WORD_MASK_AND_EDGE_CHECKER_COVERAGE',
                 functional_baseline=BASE, proof=proof, mutations_rejected=rejected,
                 standalone_actual_summaries=parsed, expected_gg_summary=required,
                 per_run_timeout_seconds=timeout, trace=observed['binary_integrity']['file'],
                 trace_sha256=observed['binary_integrity']['sha256'], inputs=pins,
                 fpga_access=False, fpga_passed=False, full_trace_oracle_executed=False,
                 complete_opt4_equivalence=False,
                 next_step='Adopt existing GG full replay; independent broker analysis traverses the sealed trace once and checks counts. No additional replay.',
                 created_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
    write_once(C/'plan.json', value)
    print(json.dumps({k: value[k] for k in ['status', 'mutations_rejected', 'expected_gg_summary', 'per_run_timeout_seconds']}))


def run():
    policy()
    plan = read(C/'plan.json')
    for path, expected in plan['inputs'].items():
        assert sha(path) == expected, ('source or receipt changed', path)
    assert not (O/'result.json').exists(), 'adopt immutable oracle output'
    layout = read(TARGET/'binary-layout.json')
    ports = [f for f in layout['fields'] if f.get('direction') and f['name'] != 'clock']
    outputs = [f for f in ports if f['direction'] == 'output']
    counts = dict(always=0, promote_payload=0, active_payload=0, release_payload=0)
    h = hashlib.sha256()
    decode = struct.Struct('<101I')
    known = False
    records = resets = captures = promotes = acks = 0
    first = last = None
    with Path(plan['trace']).open('rb') as trace:
        header = trace.read(16)
        assert header == b'ECSVBFULLBINv1\0\0\0'
        h.update(header)
        while True:
            block = trace.read(404*4096)
            if not block:
                break
            h.update(block)
            assert len(block) % 404 == 0, 'partial binary record'
            for row in decode.iter_unpack(block):
                tick = row[0] | row[1] << 32
                assert last is None or tick == last+1, 'missing target edge'
                first = tick if first is None else first
                last = tick
                assert row[6] == 1
                for f in ports:
                    if f['width'] % 32:
                        assert row[f['word_offset']+f['word_count']-1] >> (f['width'] % 32) == 0
                if known:
                    counts['always'] += 1
                    counts['promote_payload'] += bool(row[42])
                    counts['active_payload'] += bool(row[68] or row[42] or row[93])
                    counts['release_payload'] += bool(row[87])
                    captures += bool(row[9] and row[8])
                    promotes += bool(row[42] and row[41])
                    acks += bool(row[100])
                # A synchronous reset makes the following pre-edge defined.
                if row[7]:
                    known = True
                    resets += 1
                records += 1
    assert h.hexdigest() == plan['trace_sha256'], 'trace bytes changed'
    per_port = {f['name']: counts[group(f['name'])] for f in outputs}
    oracle = dict(records=records, target_cycles=records, first_source_tick=first,
                  last_source_tick=last, reset_edges=resets,
                  defined_output_fields=sum(per_port.values()),
                  defined_output_word_checks=sum(per_port[f['name']]*f['word_count'] for f in outputs),
                  input_word_writes=48*records, input_cache_enabled=0, mismatches=0,
                  mutation_applied=0, capture_accepted=captures, promote_accepted=promotes, acked=acks)
    assert all(oracle[k] == v for k, v in plan['expected_gg_summary'].items())
    result = dict(schema='ec-original-svb-full-binary-count-oracle/1',
                  status='PASS_COMPLETE_BINARY_COVERAGE_COUNTS_NOT_ADDITIONAL_REPLAY_OR_FPGA',
                  functional_baseline=BASE, trace_sha256=h.hexdigest(),
                  plan_sha256=sha(C/'plan.json'), oracle_summary=oracle,
                  per_output_defined_fields=per_port, defined_group_counts=counts,
                  fpga_access=False, full_opt4=False, fpga_passed=False,
                  completed_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
    write_once(O/'result.json', result)
    write_once(O/'complete.json', dict(result_sha256=sha(O/'result.json')))
    print(json.dumps({'status': result['status'], 'oracle_summary': oracle}))


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--prepare', action='store_true')
    parser.add_argument('--run', action='store_true')
    args = parser.parse_args()
    assert args.prepare != args.run
    prepare() if args.prepare else run()
