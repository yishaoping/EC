#!/usr/bin/python3
"""Audit the real FireSim/RAM interconnect, including SimWrapper channels.

This is immutable structural evidence, not universal FIFO/RAM equivalence,
an area measurement, or a new simulation. No generated input is modified.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re

C = Path(__file__).resolve().parent
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-owner-channel-composition-round50-v1-20261111'
OLD = W/'candidates/mcrams-host-area-boundary-round45-v1-20261111'
PRE = 'lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
HW = '3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
IDENT = r'[A-Za-z_][A-Za-z_0-9]*'


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as stream:
        for block in iter(lambda: stream.read(2**20), b''):
            h.update(block)
    return h.hexdigest()


def policy():
    p = read(D/'unattended-opt4/campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert p['native_paused'] and not p['fpga_access'] and not p['functional_extensions_allowed']
    assert p['board_allowlist'] == ['0000:21:00.0']


def once(path, value):
    path.parent.mkdir(parents=True, exist_ok=True)
    raw = (json.dumps(value, indent=2, sort_keys=True)+'\n').encode()
    if path.exists():
        assert path.read_bytes() == raw, ('immutable evidence differs', str(path))
    else:
        with path.open('xb') as stream:
            stream.write(raw)
            stream.flush()
            os.fsync(stream.fileno())


def clean(text):
    return re.sub(r'//[^\n]*', '', text)


def ports(text):
    header = text[:text.index(');')]
    rows = re.findall(r'\b(input|output)\s+(?:\[([^\]]+)\]\s*)?('+IDENT+r')', header)
    result = {name: (direction, width.replace(' ', '')) for direction, width, name in rows}
    assert len(rows) == len(result)
    return result


def instance(text, kind):
    matches = list(re.finditer(r'^\s*'+re.escape(kind)+r'\s+('+IDENT+r')\s*\((.*?)\)\s*;', text, re.M | re.S))
    assert len(matches) == 1, (kind, len(matches))
    return matches[0][1], bindings(matches[0][2])


def bindings(body):
    pattern = r'\.\s*('+IDENT+r')\s*\(\s*([^()]*)\s*\)\s*,?'
    matches = list(re.finditer(pattern, body))
    assert not re.sub(pattern, '', body).strip(), 'unparsed named port'
    result = {m[1]: m[2].strip() for m in matches}
    assert len(result) == len(matches)
    assert all(not v or re.fullmatch(IDENT+r"|\d+'h[0-9a-f]+", v) for v in result.values())
    return result


def resolver(text):
    rows = re.findall(r'\bassign\s+('+IDENT+r')\s*=\s*([^;]+);', text, re.S)
    aliases = {a: b.strip() for a, b in rows}
    assert len(rows) == len(aliases), 'multiple continuous drivers'
    cache = {}

    def root(name):
        if name in cache:
            return cache[name]
        visited = set()
        original = name
        while name in aliases:
            assert name not in visited, ('alias cycle', original)
            visited.add(name)
            name = aliases[name]
            assert re.fullmatch(IDENT+r"|\d+'h[0-9a-f]+", name), ('non-alias on selected channel', original, name)
        for n in visited:
            cache[n] = name
        cache[original] = name
        return name
    return root


def flip(name):
    return name.replace('_source_', '_TEMP_').replace('_sink_', '_source_').replace('_TEMP_', '_sink_')


def audit(texts):
    fame, fire, ram, sim = (clean(texts[n]) for n in ['FAMETop', 'FireSim', 'ownerImageMemory_flattened', 'SimWrapper'])
    pf, pt, pr = ports(fame), ports(fire), ports(ram)
    _, bf = instance(fame, 'FireSim')
    _, br = instance(fame, 'ownerImageMemory_flattened')
    _, target = instance(sim, 'FAMETop')
    assert set(bf) == set(pt) and set(br) == set(pr) and set(target) == set(pf)
    fr, sr = resolver(fame), resolver(sim)
    # Port directions are the same on the enclosing FAMETop and its child.
    exposed = {}
    for name, (direction, width) in pf.items():
        # Only owner ports and shared host clock/reset are relevant here.
        if 'ownerImageMemory_flattened' in name or name in ['hostClock', 'hostReset']:
            key = (direction, width, fr(name))
            assert key not in exposed, ('ambiguous owner boundary', name)
            exposed[key] = name

    def endpoint(port, table, bound):
        direction, width = table[port]
        key = direction, width, fr(bound[port])
        assert key in exposed, ('owner endpoint omitted from FAMETop', port)
        return sr(target[exposed[key]])

    for port, expected in [('hostClock', 'clock'), ('hostReset', 'reset')]:
        assert endpoint(port, pr, br) == endpoint(port, pt, bf) == expected

    pipe_rows = list(re.finditer(r'^\s*(PipeChannel\w*)\s+('+IDENT+r'ownerImageMemory'+IDENT+r')\s*\((.*?)\)\s*;', sim, re.M | re.S))
    assert len(pipe_rows) == 109, len(pipe_rows)
    pipes = {}
    for match in pipe_rows:
        kind, name, binding = match[1], match[2], bindings(match[3])
        pp = ports(clean(texts[kind]))
        assert set(binding) == set(pp), ('pipe interface mismatch', name)
        assert sr(binding['clock']) == 'clock' and sr(binding['reset']) == 'reset'
        pipes[name] = kind, binding, pp

    owner = {p: v for p, v in pt.items() if p.startswith(PRE)}
    commands = sorted(p[:-len('_source_valid')] for p in owner if p.endswith('_source_valid'))
    responses = sorted(p[:-len('_sink_valid')] for p in owner if p.endswith('_sink_valid'))
    assert len(owner) == 301 and len(pr) == 294 and len(commands) == 74 and len(responses) == 35
    checked_fire, checked_ram, used = set(), set(), set()
    channels, discarded_source_bits, unused_response_bits, constant_bits = [], [], [], []
    for stem, command in [(x, True) for x in commands] + [(x, False) for x in responses]:
        fstem = stem
        rstem = stem[len(PRE):]
        fp = fstem + ('_source_' if command else '_sink_')
        rp = rstem + ('_sink_' if command else '_source_')
        producer, consumer = ((pt, bf, fp), (pr, br, rp)) if command else ((pr, br, rp), (pt, bf, fp))
        ptable, pbound, pprefix = producer
        ctable, cbound, cprefix = consumer
        pv = endpoint(pprefix+'valid', ptable, pbound)
        matches = [(n, x) for n, x in pipes.items() if sr(x[1]['io_in_valid']) == pv]
        assert len(matches) == 1, ('missing/ambiguous pipe producer', stem)
        name, (kind, binding, pports) = matches[0]
        assert name not in used, ('duplicate pipe use', stem)
        used.add(name)
        for suffix, pipeport, table, bound, prefix in [
            ('valid', 'io_in_valid', ptable, pbound, pprefix),
            ('ready', 'io_in_ready', ptable, pbound, pprefix),
            ('valid', 'io_out_valid', ctable, cbound, cprefix),
            ('ready', 'io_out_ready', ctable, cbound, cprefix)]:
            port = prefix+suffix
            expected_direction = ('output' if table is ptable and suffix == 'valid' else
                                  'input' if table is ptable else 'input' if suffix == 'valid' else 'output')
            assert table[port] == (expected_direction, '')
            assert endpoint(port, table, bound) == sr(binding[pipeport]), ('crossed token channel', port)
        for table, bound, prefix, pipeport, label in [
            (ptable, pbound, pprefix, 'io_in_bits', 'producer'),
            (ctable, cbound, cprefix, 'io_out_bits', 'consumer')]:
            port = prefix+'bits'
            if port in table and pipeport in binding:
                assert table[port][1] == pports[pipeport][1], ('payload width mismatch', port)
                assert endpoint(port, table, bound) == sr(binding[pipeport]), ('crossed payload channel', port)
            elif port in table:
                assert command and label == 'producer' and port.endswith('_en_source_bits')
                discarded_source_bits.append(port[len(PRE):])
            elif pipeport in binding:
                assert command and label == 'producer' and rstem == 'MPORT_mask'
                assert sr(binding[pipeport]) == "1'h1", 'write mask constant changed'
                constant_bits.append('MPORT_mask=1')
            if table is pt:
                checked_fire |= {prefix+s for s in ['valid', 'ready', 'bits'] if prefix+s in table}
            else:
                checked_ram |= {prefix+s for s in ['valid', 'ready', 'bits'] if prefix+s in table}
        if not command and fp+'bits' not in pt:
            # Compiler-pruned target bits still have all ready/valid tokens.
            assert rp+'bits' in pr and 'io_in_bits' not in binding and 'io_out_bits' not in binding
            unused_response_bits.append(rstem)
        channels.append(dict(stem=rstem, direction='command' if command else 'response',
                             instance=name, module=kind, ports=sorted(binding)))
    assert used == set(pipes)
    assert checked_fire == set(owner)
    assert checked_ram == set(pr)-{'hostClock', 'hostReset'}
    assert len(discarded_source_bits) == 15 and len(unused_response_bits) == 5 and constant_bits == ['MPORT_mask=1']
    # The 109 queues are a real part of the composition, outside FAMETop.
    # Their stateful bodies are bound verbatim, not declared formally proved.
    queue_closure = {n: hashlib.sha256(t.encode()).hexdigest() for n, t in texts.items()
                     if n.startswith(('PipeChannel', 'ShiftQueue'))}
    return dict(owner_fire_ports=301, ram_wrapper_ports=294, channel_instances=109,
                command_channels=74, response_channels=35, channel_records=channels,
                all_owner_token_ports_accounted=True, payload_widths_and_aliases_checked=True,
                host_clock_and_reset_checked=True, constant_write_mask=constant_bits,
                source_enable_payloads_pruned_but_tokens_preserved=discarded_source_bits,
                response_payloads_pruned_but_tokens_preserved=unused_response_bits,
                queue_module_hashes=queue_closure, minimum_existing_enclosing_root_for_connected_channels='SimWrapper',
                fame_root_contains_children_but_exposes_channel_endpoints=True)


def analyze():
    plan = read(C/'plan.json')
    for path, digest in plan['inputs'].items():
        assert sha(path) == digest, ('sealed input changed', path)
    texts = {p.stem: p.read_text() for p in (C/'evidence').glob('*.sv')}
    result = audit(texts)
    mutations = {}
    raw = texts['SimWrapper']
    # Alter actual driver expressions, not unrelated diagnostics or comments.
    for label, suffix, old, new in [
        ('read_address_crosswire', 'MPORT_5_addr_io_in_bits', 'MPORT_5_addr_source_bits', 'MPORT_6_addr_source_bits'),
        ('write_data_crosswire', 'MPORT_data_io_in_bits', 'MPORT_data_source_bits', 'MPORT_addr_source_bits'),
        ('ack_ready_crosswire', 'MPORT_5_data_io_out_ready', 'MPORT_5_data_sink_ready', 'MPORT_6_data_sink_ready')]:
        pattern = r'(\bassign\s+'+IDENT+re.escape(suffix)+r'\s*=\s*)('+IDENT+re.escape(old)+r')(\s*;)'
        mutant, count = re.subn(pattern, lambda m: m[1]+m[2][:-len(old)]+new+m[3], raw)
        assert count == 1, ('ineffective wiring mutation', label, count)
        mutations[label] = mutant
    # Queue clock/reset and the source-side true write-mask are also checked.
    for label, suffix, expected, changed in [
        ('queue_clock_crosswire', 'MPORT_5_addr_clock', 'clock', 'reset'),
        ('queue_reset_crosswire', 'MPORT_5_addr_reset', 'reset', 'clock'),
        ('write_mask_zero', 'MPORT_mask_io_in_bits', "1'h1", "1'h0")]:
        pattern = r'(\bassign\s+'+IDENT+re.escape(suffix)+r'\s*=\s*)'+re.escape(expected)+r'(\s*;)'
        mutant, count = re.subn(pattern, lambda m: m[1]+changed+m[2], raw)
        assert count == 1, ('ineffective control mutation', label, count)
        mutations[label] = mutant
    rejected = {}
    for name, mutant in mutations.items():
        try:
            audit({**texts, 'SimWrapper': mutant})
        except AssertionError as error:
            rejected[name] = str(error)
        else:
            raise AssertionError(('interconnect mutation accepted', name))
    result.update(schema='ec-owner-host-channel-composition/1',
                  status='PASS_EXACT_OWNER_FAME_AND_SIMWRAPPER_CHANNEL_WIRING_NOT_FULL_EQUIVALENCE',
                  functional_baseline=BASE, hardware_commit=HW,
                  plan_sha256=sha(C/'plan.json'), mutations_rejected=rejected,
                  fpga_access=False, simulation_run=False, synthesis_run=False, full_equivalence=False,
                  whole_fit=False, smaller_area_cut_admitted=False,
                  limitations=['Connectivity and widths only; queue/RAM universal transition proof remains separate.',
                               'Existing runtime parity and scalar scheduler audit remain separate receipts.',
                               'No target RTL or annotations changed; no resource gain or hardware sample inferred.'])
    return result


def prepare():
    if (C/'plan.json').exists():
        print('ADOPT_PREPARED_IMMUTABLE_CAPSULE')
        return
    boundary = read(OLD/'area-boundary.json')
    actual = boundary['modes']['MC']
    source = Path(actual['source'])
    assert sha(source) == actual['source_sha256']
    text = source.read_text()
    all_modules = {m[1]: m[0] for m in re.finditer(r'^module\s+(\w+)\b.*?^endmodule\b[^\n]*', text, re.M | re.S)}
    names = {'FAMETop', 'FireSim', 'ownerImageMemory_flattened', 'SimWrapper'}
    sim = clean(all_modules['SimWrapper'])
    names |= {m[1] for m in re.finditer(r'^\s*(PipeChannel\w*)\s+('+IDENT+r'ownerImageMemory'+IDENT+r')\s*\(', sim, re.M)}
    pending = list(names-{'FAMETop', 'FireSim', 'ownerImageMemory_flattened', 'SimWrapper'})
    while pending:
        name = pending.pop()
        for child in re.findall(r'^\s*(ShiftQueue\w*)\s+\w+\s*\(', all_modules[name], re.M):
            if child not in names:
                names.add(child)
                pending.append(child)
    evidence = C/'evidence'
    evidence.mkdir()
    for name in sorted(names):
        raw = all_modules[name].encode()
        if name in actual['captured_modules']:
            assert hashlib.sha256(raw).hexdigest() == actual['captured_modules'][name]['sha256']
        (evidence/(name+'.sv')).write_bytes(raw)
    # Source/receipt provenance stays explicit. The broker sees sealed W files.
    receipts = [OLD/'area-boundary.json',
                W/'candidates/owner-token-audit-round49-v3-20261111/result.json',
                D/'build-logs/Opt4-mcrams-owner-model-reuse-round44-v2-20261111/result.json',
                D/'build-logs/Opt4-owner-generated-area-analysis-round49-r3-20261111/result.json']
    originals = {}
    for i, path in enumerate(receipts):
        originals[str(path)] = sha(path)
        (evidence/(str(i)+'-'+path.parent.name+'-'+path.name)).write_bytes(path.read_bytes())
    files = sorted(evidence.iterdir())
    once(C/'plan.json', dict(schema='ec-owner-channel-composition-plan/1',
                            functional_baseline=BASE, hardware_commit=HW, inputs={str(p):sha(p) for p in files},
                            source=str(source), source_sha256=actual['source_sha256'], original_receipts=originals,
                            existing_runtime_preserved=True, fpga_access=False, no_whole_synthesis=True))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--prepare', action='store_true')
    ap.add_argument('--run', action='store_true')
    args = ap.parse_args()
    assert args.prepare != args.run
    policy()
    if args.prepare:
        prepare()
        result = analyze()
        once(C/'preflight.json', result)
        print(json.dumps({k: v for k, v in result.items() if k not in ['channel_records', 'queue_module_hashes']}))
    else:
        if (O/'complete.json').exists():
            assert sha(O/'result.json') == read(O/'complete.json')['result_sha256']
            print('ADOPT_COMPLETE_IMMUTABLE_CHANNEL_AUDIT')
            return
        result = analyze()
        assert result == read(C/'preflight.json')
        once(O/'result.json', result)
        once(O/'complete.json', dict(result_sha256=sha(O/'result.json')))
        print(result['status'])


if __name__ == '__main__':
    main()
