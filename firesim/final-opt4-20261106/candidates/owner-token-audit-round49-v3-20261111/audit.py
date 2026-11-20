#!/usr/bin/python3
"""Read-only audit of emitted owner-memory token and clock control.

This proves scalar scheduler identities, not the RAM datapath, a smaller
composed area boundary, full target equivalence, or FPGA admission.
"""
import argparse
import hashlib
import itertools
import json
from pathlib import Path
import re
import shutil

C = Path(__file__).resolve().parent
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
PREFIX = 'lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
TOKEN = re.compile(r"1'h[01]|[A-Za-z_][A-Za-z_0-9]*|[~&|^?:()]")


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def policy():
    p = json.loads((D/'unattended-opt4/campaign-policy.json').read_text())
    assert p['functional_baseline_commit'] == BASE
    assert p['area_equivalence_only'] and not p['fpga_access']
    return p


def write_once(p, value):
    raw = (json.dumps(value, sort_keys=True, indent=2) + '\n').encode()
    if p.exists():
        assert p.read_bytes() == raw, ('immutable result changed', str(p))
    else:
        with p.open('xb') as f:
            f.write(raw)


def parse(expr):
    ts = TOKEN.findall(expr)
    assert ''.join(ts) == re.sub(r'\s+', '', expr), ('unsupported scalar expression', expr)
    pos = 0

    def atom():
        nonlocal pos
        t = ts[pos]
        pos += 1
        if t == '~':
            return ('~', atom())
        if t == '(':
            n = mux()
            assert ts[pos] == ')'
            pos += 1
            return n
        assert re.fullmatch(r"1'h[01]|[A-Za-z_][A-Za-z_0-9]*", t)
        return ('c', int(t[-1])) if t.startswith("1'h") else ('v', t)

    def binary(level):
        nonlocal pos
        ops = ['|', '^', '&']
        if level == 3:
            return atom()
        n = binary(level+1)
        while pos < len(ts) and ts[pos] == ops[level]:
            op = ts[pos]
            pos += 1
            n = (op, n, binary(level+1))
        return n

    def mux():
        nonlocal pos
        n = binary(0)
        if pos < len(ts) and ts[pos] == '?':
            pos += 1
            yes = mux()
            assert ts[pos] == ':'
            pos += 1
            n = ('?', n, yes, mux())
        return n

    result = mux()
    assert pos == len(ts), expr
    return result


def variables(n):
    if n[0] == 'v':
        return {n[1]}
    if n[0] == 'c':
        return set()
    return set().union(*(variables(x) for x in n[1:]))


def value(n, env):
    op = n[0]
    if op == 'v':
        return env[n[1]]
    if op == 'c':
        return n[1]
    if op == '~':
        return 1 ^ value(n[1], env)
    if op == '?':
        return value(n[2] if value(n[1], env) else n[3], env)
    a, b = value(n[1], env), value(n[2], env)
    return {'&': a & b, '|': a | b, '^': a ^ b}[op]


def exact_boolean(a, b):
    names = sorted(variables(a) | variables(b))
    assert len(names) <= 8, names
    for bits in itertools.product([0, 1], repeat=len(names)):
        env = dict(zip(names, bits))
        assert value(a, env) == value(b, env), ('scalar counterexample', env)
    return 2**len(names)


def canonical(n):
    if n[0] in ['&', '|', '^']:
        children = []

        def gather(x):
            if x[0] == n[0]:
                gather(x[1])
                gather(x[2])
            else:
                children.append(canonical(x))

        gather(n)
        return (n[0], *sorted(children, key=repr))
    if n[0] in ['v', 'c']:
        return n
    return (n[0], *(canonical(x) for x in n[1:]))


def audit(raw):
    s = re.sub(r'//[^\n]*', '', raw)
    header = s[:s.index(');')]
    ports = dict((m[3], (m[1], m[2] or '')) for m in
        re.finditer(r'\b(input|output)\s*(\[[^\]]+\])?\s*(\w+)\s*(?=,|$)', header))
    owner = {k: v for k, v in ports.items() if k.startswith(PREFIX)}
    assert len(owner) == 301, len(owner)
    responses = sorted(k[:-len('_sink_valid')] for k in owner if k.endswith('_data_sink_valid'))
    commands = sorted(k[:-len('_source_valid')] for k in owner if k.endswith('_source_valid'))
    assert len(responses) == 35 and len(commands) == 74
    definitions = {}
    for m in re.finditer(r'\b(?:wire|assign)\s+(\w+)\s*=([^;]+);', s):
        assert m[1] not in definitions, m[1]
        definitions[m[1]] = m[2]

    def conjunction(n):
        pending = [(n, frozenset())]
        result = []
        while pending:
            node, ancestors = pending.pop()
            if node[0] == '&':
                pending.extend([(node[2], ancestors), (node[1], ancestors)])
            elif node[0] == 'v' and node[1] in definitions:
                assert node[1] not in ancestors, ('cyclic expression', node[1])
                pending.append((parse(definitions[node[1]]), ancestors | {node[1]}))
            else:
                result.append(node)
        return result

    finish_factors = conjunction(parse(definitions['targetCycleFinishing']))
    factors = set(canonical(x) for x in finish_factors)
    checks = 0
    for stem in responses:
        assert owner[stem+'_sink_valid'] == ('input', '')
        assert canonical(parse(stem+'_sink_valid')) in factors, ('finish missing response', stem)
        checks += exact_boolean(parse(definitions[stem+'_sink_ready']),
            parse('targetCycleFinishing & ~'+stem+'_fired_0'))
        # The incoming data token is consumed at the finishing edge. Its exact
        # emitted next-state expression uses the next clock token, including
        # the host-reset value. Capture the real SSA expression, never infer it.
        reg = stem+'_fired_0'
        updates = re.findall(r'\b'+reg+r'\s*<=([^;]+);', s)
        assert len(updates) == 1, (reg, len(updates))

        def inline_gen(n):
            if n[0] == 'v' and n[1].startswith('_GEN_'):
                return inline_gen(parse(definitions[n[1]]))
            if n[0] in ['v', 'c']:
                return n
            return (n[0], *(inline_gen(x) for x in n[1:]))

        expected = 'hostReset | (targetCycleFinishing ? ~clockBridge_clocks_sink_bits__0 : '+reg+' | '+stem+'_sink_ready & '+stem+'_sink_valid)'
        checks += exact_boolean(inline_gen(parse(updates[0])), parse(expected))

    out_recurrences = []
    for stem in commands:
        flag = stem+'_fired_0'
        assert owner[stem+'_source_valid'] == ('output', '')
        needed = parse(flag+' | '+stem+'_source_ready & '+stem+'_source_valid')
        assert canonical(needed) in factors, ('finish missing command completion', stem)
        valid = parse(definitions[stem+'_source_valid'])
        # Prove once-per-target-cycle exclusion for arbitrary input readiness.
        # Other response dependencies remain symbolic; no target assumptions.
        assert canonical(parse('~'+flag)) in set(map(canonical, conjunction(valid)))
        updates = re.findall(r'\b'+flag+r'\s*<=([^;]+);', s)
        assert len(updates) == 3, (flag, len(updates))
        checks += exact_boolean(parse(updates[0]), parse("1'h0"))
        checks += exact_boolean(parse(updates[1]), parse('~clockBridge_clocks_0_enabled'))
        checks += exact_boolean(parse(updates[2]), parse(flag+' | '+stem+'_source_ready & '+stem+'_source_valid'))
        # Check branch priority and completeness around these three statements.
        patt = (r'if\s*\(hostReset\)\s*begin\s*'+flag+r'\s*<=([^;]+);\s*end\s*else\s*if\s*'
            r'\(targetCycleFinishing\)\s*begin\s*'+flag+r'\s*<=([^;]+);\s*end\s*else\s*begin\s*'+flag+r'\s*<=([^;]+);\s*end')
        assert len(list(re.finditer(patt, s))) == 1, ('unverified sequential control', flag)
        out_recurrences.append(stem[len(PREFIX):])

    for domain in [0, 1]:
        ce = f'clockBridge_clocks_{domain}_buffer_CE'
        checks += exact_boolean(parse(definitions[ce]),
            parse(f'clockBridge_clocks_{domain}_enabled & targetCycleFinishing & ~hostReset'))
        assert parse(definitions[f'clockBridge_clocks_{domain}_buffer_I']) == parse('hostClock')
    return dict(owner_interface_ports=len(owner), read_responses=len(responses), output_command_channels=len(commands),
        finishing_conjuncts=len(finish_factors), exhaustive_scalar_valuations=checks,
        response_names=[x[len(PREFIX):] for x in responses], command_names=out_recurrences,
        finishing_factors_sha256=hashlib.sha256(repr(sorted(factors, key=repr)).encode()).hexdigest(),
        clock_domains_checked=2, host_reset_blocks_target_clock=True,
        incoming_response_state_uses_next_clock_token=True, outgoing_state_uses_current_enabled_clock=True)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--prepare', action='store_true')
    args = ap.parse_args()
    policy()
    if args.prepare:
        source = W/'candidates/mcrams-host-area-boundary-round45-v1-20261111/MC/FireSim.sv'
        boundary = W/'candidates/mcrams-host-area-boundary-round45-v1-20261111/area-boundary.json'
        evidence = C/'evidence'
        evidence.mkdir(exist_ok=True)
        for original in [source, boundary]:
            dest = evidence/original.name
            if not dest.exists():
                shutil.copyfile(original, dest)
            assert sha(dest) == sha(original)
        write_once(C/'inputs.json', dict(functional_baseline=BASE,
            hardware_commit='3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c',
            sources={str(x): sha(x) for x in [source, boundary]},
            sealed={str(x): sha(x) for x in evidence.iterdir()}))
    manifest = json.loads((C/'inputs.json').read_text())
    for path, digest in manifest['sealed'].items():
        assert sha(path) == digest
    raw = (C/'evidence/FireSim.sv').read_text()
    result = audit(raw)
    mutations = {
        'clock_advance_without_all_tokens': raw.replace(
            'clockBridge_clocks_0_enabled & targetCycleFinishing & ~hostReset',
            'clockBridge_clocks_0_enabled & ~hostReset', 1),
        'clock_advance_during_host_reset': raw.replace(
            'clockBridge_clocks_0_enabled & targetCycleFinishing & ~hostReset',
            'clockBridge_clocks_0_enabled & targetCycleFinishing', 1),
        'source_duplicate_token': re.sub(r'~\s*'+PREFIX+'MPORT_addr_fired_0', "1'h1", raw, count=1),
        'consume_response_before_target_edge': re.sub(
            r'(assign\s+'+PREFIX+r'MPORT_18_data_sink_ready\s*=)\s*targetCycleFinishing\s*&', r'\1', raw, count=1),
        'discard_response_on_disabled_next_clock': raw.replace(
            'targetCycleFinishing ? ~clockBridge_clocks_sink_bits__0 :',
            "targetCycleFinishing ? 1'h0 :", 1),
    }
    rejected = []
    for name, mutant in mutations.items():
        assert mutant != raw, ('ineffective mutation', name)
        try:
            audit(mutant)
        except AssertionError:
            rejected.append(name)
        else:
            raise AssertionError(('mutation survived', name))
    result.update(schema='ec-emitted-owner-token-controls/1', functional_baseline=BASE,
        hardware_commit=manifest['hardware_commit'], inputs_sha256=sha(C/'inputs.json'),
        source_sha256=sha(C/'evidence/FireSim.sv'), mutations_rejected=rejected,
        status='PASS_EXACT_EMITTED_OWNER_TOKEN_AND_CLOCK_CONTROL_IDENTITIES',
        fpga_access=False, simulation_run=False, rtl_generated=False, whole_cad=False,
        smaller_composed_area_boundary_admitted=False, complete_dcache_equivalence=False,
        limitations=['Does not prove RAM data/state semantics or universal target equivalence',
            'Does not reconstruct a smaller DCache/RAM/token-scheduler measurement boundary',
            'No area result, full Opt4 FIT, timing, DRC, bitstream or FPGA result'])
    write_once(C/'result.json', result)
    write_once(C/'complete.json', {'result_sha256': sha(C/'result.json')})
    print(json.dumps({k: v for k, v in result.items() if k not in ['response_names', 'command_names']}, sort_keys=True))


if __name__ == '__main__':
    main()
