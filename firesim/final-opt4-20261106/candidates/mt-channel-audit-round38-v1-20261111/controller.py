#!/usr/bin/python3
"""Read-only, fail-closed audit of the saved MT+MCRams InferModelPorts failure.

This does not change FIRRTL, annotations, target sources, or compiler libraries.
It follows only unconditional reference-to-reference connections. Equal nominal
clock frequencies are deliberately insufficient evidence of clock equivalence.
"""
import collections
import datetime
import hashlib
import json
import os
from pathlib import Path
import re
import traceback

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
BASELINE = '8491167d84b6d9521b151a743673c1516926a1f8'
SAVED = D / 'cycleprecise-frozen-mt-mcrams-r1-20261111/goldengate'
OUT = D / 'build-logs/Opt4-mt-channel-audit-round38-v1-20261111'
STATE = D / 'Opt4-mt-channel-audit-round38-v1-state.json'
LOCAL = Path(__file__).resolve().parent
REF = re.compile(r'\w+(?:\.\w+)?\Z')


def now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for block in iter(lambda: f.read(4 * 1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def atomic(path, value):
    path = Path(path)
    tmp = path.with_name(path.name + '.tmp-' + str(os.getpid()))
    with tmp.open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())
    os.replace(tmp, path)


def parse_fir(path):
    modules = {}
    current = None
    conditional = []
    circuit = None
    with path.open() as f:
        for line_no, line in enumerate(f, 1):
            s = line.strip()
            indent = len(line) - len(line.lstrip())
            cm = re.match(r'circuit (\w+)\s*:', s)
            if cm:
                circuit = cm[1]
            mm = re.match(r'(module|extmodule) (\w+)\s*:', s)
            if mm:
                current = {'ports': {}, 'instances': {},
                           'drivers': collections.defaultdict(list),
                           'external': mm[1] == 'extmodule'}
                modules[mm[2]] = current
                conditional = []
                continue
            if current is None or not s:
                continue
            while conditional and indent <= conditional[-1]:
                conditional.pop()
            if s.startswith(('when ', 'else ')) or s == 'else :':
                conditional.append(indent)
            p = re.match(r'(input|output) (\w+) : (.*?)(?: @\[.*)?$', s)
            if p:
                current['ports'][p[2]] = {'direction': p[1], 'type': p[3]}
                continue
            i = re.match(r'inst (\w+) of (\w+)', s)
            if i:
                current['instances'][i[1]] = i[2]
                continue
            c = re.match(r'([\w.]+) <= (.*?)(?: @\[.*)?$', s)
            n = re.match(r'node (\w+) = (.*?)(?: @\[.*)?$', s)
            if c or n:
                q = c or n
                current['drivers'][q[1]].append({
                    'rhs': q[2], 'line': line_no,
                    'conditional': bool(conditional),
                    'kind': 'connect' if c else 'node'})
    assert circuit and modules
    return circuit, modules


def one_driver(records, label):
    assert records, ('no_driver', label)
    assert not any(r['conditional'] for r in records), ('conditional_driver', label)
    values = {r['rhs'] for r in records}
    assert len(values) == 1, ('distinct_drivers', label, records)
    rhs = next(iter(values))
    assert REF.fullmatch(rhs), ('non_reference_driver', label, rhs)
    return rhs


def resolve(modules, module, ref, context=(), seen=()):
    key = (context, module, ref)
    assert key not in seen and len(seen) < 200, ('clock_cone_cycle', key)
    m = modules[module]
    assert not m['external'], ('external_clock_cone', module, ref)
    step = {'module': module, 'instances': [i for _, i in context], 'reference': ref}
    drivers = m['drivers'].get(ref, [])
    if drivers:
        rhs = one_driver(drivers, (module, ref))
        step['drivers'] = drivers
        endpoint, chain = resolve(modules, module, rhs, context, seen + (key,))
    elif '.' in ref:
        instance, port = ref.split('.', 1)
        child = m['instances'][instance]
        p = modules[child]['ports'][port]
        assert p == {'direction': 'output', 'type': 'Clock'}, ('non_clock_output', module, ref, p)
        endpoint, chain = resolve(modules, child, port, context + ((module, instance),), seen + (key,))
    else:
        p = m['ports'].get(ref)
        assert p == {'direction': 'input', 'type': 'Clock'}, ('undriven_or_non_clock', module, ref, p)
        if not context:
            return {'module': module, 'input': ref}, [step]
        parent, instance = context[-1]
        endpoint, chain = resolve(modules, parent, instance + '.' + ref, context[:-1], seen + (key,))
    return endpoint, [step] + chain


def analyze(circuit, modules, annos):
    top = modules[circuit]
    transforms = {a['target'].split('|')[1] for a in annos
                  if a.get('class', '').endswith('.FAMETransformAnnotation')}
    channels = [a for a in annos if a.get('class', '').endswith('.FAMEChannelConnectionAnnotation')]
    # Match FAMEChannelAnalysis.getTopConnects: top port <-> model port.
    connects = collections.defaultdict(list)
    for lhs, records in top['drivers'].items():
        rhs = one_driver(records, (circuit, lhs))
        if '.' not in lhs and '.' in rhs:
            connects[lhs].append(rhs)
        elif '.' in lhs and '.' not in rhs:
            connects[rhs].append(lhs)
    port_map = {}
    for port, targets in connects.items():
        assert len(set(targets)) == 1, ('ambiguous_top_port', port, targets)
        instance, name = targets[0].split('.')
        module = top['instances'][instance]
        port_map[port] = (module, name)

    def mapped(target):
        assert target.startswith('~' + circuit + '|' + circuit + '>'), target
        return port_map.get(target.split('>', 1)[1])

    grouped = collections.defaultdict(list)
    for c in channels:
        for flow in ('sources', 'sinks'):
            targets = c.get(flow) or []
            if not targets:
                continue
            payloads = [mapped(t) for t in targets]
            if not payloads[0] or payloads[0][0] not in transforms:
                continue  # External bridge or bridge loopback; no model ports.
            module = payloads[0][0]
            assert all(p and p[0] == module for p in payloads), ('mixed_channel', c)
            clock = mapped(c['clock']) if c.get('clock') else None
            clock_port = clock[1] if clock and clock[0] == module else None
            grouped[(module, flow)].append({
                'channel': c['globalName'], 'clock': clock_port,
                'payload': tuple(p[1] for p in payloads)})

    conflicts = []
    for (module, flow), entries in sorted(grouped.items()):
        for i, a in enumerate(entries):
            for b in entries[:i]:
                if set(a['payload']) & set(b['payload']) and (a['clock'], a['payload']) != (b['clock'], b['payload']):
                    conflicts.append({'module': module, 'flow': flow, 'a': a, 'b': b})
    assert conflicts, 'Saved failure not reproduced by independent port audit'
    clocks = sorted({(c['module'], c[k]['clock']) for c in conflicts for k in ('a', 'b')}, key=str)
    clock_proofs = {}
    for module, clock in clocks:
        key = module + '>' + str(clock)
        try:
            assert clock is not None, 'Clock is absent on one side'
            endpoint, chain = resolve(modules, module, clock)
            clock_proofs[key] = {'status': 'WIRE_ALIAS_RESOLVED', 'endpoint': endpoint, 'chain': chain}
        except Exception as error:
            clock_proofs[key] = {'status': 'UNRESOLVED', 'error': repr(error)}
    for c in conflicts:
        pa, pb = [clock_proofs[c['module'] + '>' + str(c[k]['clock'])] for k in ('a', 'b')]
        c['identical_payload'] = c['a']['payload'] == c['b']['payload']
        c['wire_identical_clock'] = (pa['status'] == pb['status'] == 'WIRE_ALIAS_RESOLVED' and pa['endpoint'] == pb['endpoint'])
    return {'circuit': circuit, 'module_count': len(modules),
            'transformed_modules': sorted(transforms), 'channel_count': len(channels),
            'model_flow_group_count': len(grouped), 'conflicts': conflicts,
            'clock_proofs': clock_proofs}


def negative_checks():
    def toy(drivers, **extras):
        return {'M': {'external': False, 'ports': {'c0': {'direction': 'input', 'type': 'Clock'},
                                                  'c1': {'direction': 'input', 'type': 'Clock'}},
                      'instances': {}, 'drivers': drivers, **extras}}
    def dr(rhs, conditional=False):
        return {'rhs': rhs, 'line': 1, 'conditional': conditional, 'kind': 'connect'}
    results = {}
    for label, drivers in {
        'distinct_drivers': {'a': [dr('c0'), dr('c1')]},
        'conditional_connect': {'a': [dr('c0', True)]},
        'computed_clock': {'a': [dr('asClock(UInt<1>(1))')]},
        'alias_loop': {'a': [dr('b')], 'b': [dr('a')]},
        'undriven_clock': {},
    }.items():
        try:
            resolve(toy(drivers), 'M', 'a')
        except Exception:
            results[label] = 'REJECTED'
        else:
            raise AssertionError(('negative_accepted', label))
    e0, _ = resolve(toy({}), 'M', 'c0')
    e1, _ = resolve(toy({}), 'M', 'c1')
    assert e0 != e1
    results['different_roots_even_if_same_frequency'] = 'REJECTED'
    endpoint, _ = resolve(toy({'a': [dr('c0'), dr('c0')]}), 'M', 'a')
    assert endpoint == e0
    results['identical_duplicate_connects'] = 'ACCEPTED'
    return results


def main():
    policy = json.loads((U / 'campaign-policy.json').read_text())
    assert policy['scope_supersedes_previous_recovery_authorization'] is True
    assert policy['latest_postopt_capacity']['functional_baseline'] == BASELINE
    expected = json.loads((LOCAL / 'inputs.json').read_text())
    OUT.mkdir(parents=True, exist_ok=False)
    start = now()
    identity = {'pid': os.getpid(), 'start_ticks': Path('/proc/self/stat').read_text().split()[21],
                'host_boot_id': Path('/proc/sys/kernel/random/boot_id').read_text().strip()}
    state = {'schema': 'ec-opt4-mt-channel-audit/1', 'functional_baseline': BASELINE,
             'status': 'RUNNING_READ_ONLY_AUDIT', 'started_utc': start, **identity,
             'fpga_access': False, 'target_changed': False, 'compiler_changed': False}
    atomic(STATE, state)
    try:
        before = {p: (Path(p).stat().st_size, Path(p).stat().st_mtime_ns) for p in expected}
        actual = {p: sha(p) for p in expected}
        assert actual == expected, 'Input hash mismatch'
        circuit, modules = parse_fir(SAVED / 'post-channel-excision.fir')
        data = analyze(circuit, modules, json.loads((SAVED / 'post-channel-excision.json').read_text()))
        data['negative_checks'] = negative_checks()
        complete = all(c['identical_payload'] and c['wire_identical_clock'] for c in data['conflicts'])
        status = ('PASS_ALL_CONFLICT_CLOCKS_WIRE_IDENTICAL_NO_REPAIR_APPLIED' if complete
                  else 'DIAGNOSTIC_COMPLETE_CLOCK_OR_PAYLOAD_EQUIVALENCE_UNPROVEN_NO_REPAIR')
        after = {p: (Path(p).stat().st_size, Path(p).stat().st_mtime_ns) for p in expected}
        assert before == after, 'Input changed while auditing'
        result = {**state, **data, 'status': status, 'completed_utc': now(), 'inputs': actual,
                  'policy_observed': policy['scope_reminder'], 'scope': 'Saved InferModelPorts channel-clock boundary only',
                  'limitations': ['No compiler repair applied', 'Not full target equivalence or MT sharing proof',
                                 'No whole-system area, timing or FPGA admission',
                                 'Four specialized Rocket modules remain a later MTModels sharing obligation']}
        atomic(OUT / 'result.json', result)
        state.update(status=status, result=str(OUT / 'result.json'), updated_utc=now())
        atomic(STATE, state)
        print(status, 'conflicts=' + str(len(data['conflicts'])), flush=True)
    except BaseException as error:
        atomic(OUT / 'failure.json', {'error': repr(error), 'traceback': traceback.format_exc(), 'utc': now()})
        state.update(status='FAILED_WITH_EVIDENCE', error=repr(error), updated_utc=now())
        atomic(STATE, state)
        raise


if __name__ == '__main__':
    main()
