#!/usr/bin/python3
"""Bind finite entry validation to the exact whole-generated RAM boundary.

No RTL changes, simulation, synthesis, or FPGA access. This checks complete
combinational adapters under an explicit port bijection and byte-identical
stateful RamModels. It does not prove the RamModel against all target inputs.
"""
import argparse
import datetime
import fcntl
import hashlib
import json
import os
from pathlib import Path
import re

C = Path(__file__).resolve().parent
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
O = D / 'build-logs/Opt4-mcrams-owner-model-reuse-round44-v1-20261111'
S = D / 'Opt4-mcrams-owner-model-reuse-round44-v1-state.json'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
HW = '3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
ENTRY = D / 'build-logs/Opt4-mcrams-dcache-entry-r5-20261111'
ACTUAL = D / 'build-logs/Opt4-mcrams-dcache-owner-system-r1-20261111/goldengate/FireSim-generated.sv'
NAME = 'mcrams-owner-model-reuse-r44-v1-3656aec4'


def read(path):
    return json.loads(Path(path).read_text())


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for b in iter(lambda: f.read(2**20), b''):
            h.update(b)
    return h.hexdigest()


def digest(text):
    return hashlib.sha256(text.encode()).hexdigest()


def now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()


def save(path, value):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    tmp = path.with_name(path.name + '.tmp-' + str(os.getpid()))
    with tmp.open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())
    os.replace(tmp, path)


def policy():
    p = read(U / 'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE
    assert p['area_equivalence_only'] and not p['functional_extensions_allowed']
    assert not p['fpga_access']


def module(text, name):
    matches = list(re.finditer(r'^module ' + re.escape(name) +
                              r'\b.*?^endmodule\b[^\n]*', text, re.M | re.S))
    assert len(matches) == 1, (name, len(matches))
    return matches[0][0]


def parse_adapter(text):
    """Reject every statement outside the complete combinational grammar."""
    text = re.sub(r'//[^\n]*', '', text)
    header, body = text.split(');', 1)
    ports = re.findall(r'(?m)^\s*(input|output)\s+(?:\[([^\]]+)\]\s+)?(\w+)', header)
    assert len(ports) == 294 and len({p[2] for p in ports}) == 294
    port_rest = re.sub(r'^module\s+\w+\s*\(', '', header)
    port_rest = re.sub(r'\b(?:input|output)\s+(?:\[[^\]]+\]\s+)?\w+\s*,?', '', port_rest)
    assert not port_rest.strip(), port_rest[:100]
    assignments = re.findall(r'\bassign\s+(\w+)\s*=\s*(.*?);', body, re.S)
    assert len(assignments) == 256 and len(dict(assignments)) == 256
    for lhs, rhs in assignments:
        assert re.fullmatch(r'\s*\w+(?:\s*&\s*\w+)*\s*', rhs), (lhs, rhs)
    wires = re.findall(r'\bwire\s+(?:\[([^\]]+)\]\s+)?(\w+)\s*;', body)
    instances = re.findall(r'\bRamModel\s+model\s*\((.*?)\)\s*;', body, re.S)
    assert len(instances) == 1
    bindings = re.findall(r'\.(\w+)\s*\(\s*(\w+)\s*\)', instances[0])
    assert len(bindings) == len(set(p for p, _ in bindings))
    residual = re.sub(r'\bassign\s+\w+\s*=\s*.*?;', '', body, flags=re.S)
    residual = re.sub(r'\bwire\s+(?:\[[^\]]+\]\s+)?\w+\s*;', '', residual)
    residual = re.sub(r'\bRamModel\s+model\s*\(.*?\)\s*;', '', residual, flags=re.S)
    assert residual.strip() == 'endmodule', residual[:100]
    widths = {n: w for _, w, n in ports}
    widths.update({n: w for w, n in wires})
    declared = set(widths)
    for lhs, rhs in assignments:
        assert lhs in declared
        terms = re.findall(r'\w+', rhs)
        assert set(terms) <= declared
        if len(terms) > 1:
            assert widths[lhs] == '' and all(widths[t] == '' for t in terms)
        else:
            assert widths[lhs] == widths[terms[0]], (lhs, rhs)
    assert all(n in declared for _, n in bindings)
    return dict(ports=ports, wires=wires, assignments=dict(assignments), bindings=bindings)


def canonical(adapter):
    """Map external read ports using the actual numbered model channels."""
    bases = []
    for i in range(35):
        rhs = adapter['assignments'][f'model_channels_read_cmds_{i}_bits_addr'].strip()
        assert rhs.endswith('_addr_sink_bits')
        bases.append(rhs[:-len('_addr_sink_bits')])
    assert len(set(bases)) == 35
    rename = {}
    for i, base in enumerate(bases):
        for _, _, n in adapter['ports']:
            if n.startswith(base + '_'):
                assert n not in rename
                rename[n] = f'READ_{i}_' + n[len(base) + 1:]
    assert len(rename) == 280
    def rn(n):
        return rename.get(n, n)
    assignments = {rn(lhs): sorted(rn(t) for t in re.findall(r'\w+', rhs))
                   for lhs, rhs in adapter['assignments'].items()}
    return dict(ports=sorted((d, w, rn(n)) for d, w, n in adapter['ports']),
                wires=sorted((w, rn(n)) for w, n in adapter['wires']),
                assignments=assignments,
                bindings=sorted((p, rn(n)) for p, n in adapter['bindings'])), rename


def compare(actual, entry, actual_ram, entry_ram):
    assert actual_ram == entry_ram, 'stateful model bytes differ'
    a, ar = canonical(parse_adapter(actual))
    b, br = canonical(parse_adapter(entry))
    assert a == b, 'complete adapter differs after explicit read-channel port bijection'
    inverse = {v: k for k, v in br.items()}
    mapping = {k: inverse[v] for k, v in ar.items()}
    assert len(mapping) == 280 and len(set(mapping.values())) == 280
    return a, mapping


def analyze():
    a = (C / 'actual-wrapper.sv').read_text()
    b = (C / 'tested-wrapper.sv').read_text()
    ram_a = (C / 'actual-RamModel.sv').read_text()
    ram_b = (C / 'tested-RamModel.sv').read_text()
    normal, mapping = compare(a, b, ram_a, ram_b)
    # Check three real disconnected/wrong-data/changed-state paths. Mutants
    # exist only in this analysis, never in any target/host/CAD input.
    mutations = {
        'write_data_crosswire': (a.replace('assign model_channels_write_cmds_0_bits_data = MPORT_data_sink_bits;',
            'assign model_channels_write_cmds_0_bits_data = MPORT_addr_sink_bits;', 1), ram_a),
        'read_output_crosswire': (a.replace('= model_channels_read_resps_0_bits;',
            '= model_channels_read_resps_1_bits;', 1), ram_a),
        'stateful_model_byte_change': (a, ram_a.replace('reg [80:0] data [0:511]',
            'reg [80:0] data [0:510]', 1)),
    }
    rejected = {}
    for name, (ma, mr) in mutations.items():
        assert (ma, mr) != (a, ram_a), ('mutation not applied', name)
        try:
            compare(ma, b, mr, ram_b)
        except AssertionError as e:
            rejected[name] = str(e)
        else:
            raise AssertionError(('mutation accepted', name))
    result = dict(schema='ec-owner-boundary-validation-reuse/1', functional_baseline=BASE,
                  derived_hardware=HW, fpga_access=False, production_admission=False,
                  whole_fit=False, full_dut_equivalence=False,
                  status='PASS_IDENTICAL_STATEFUL_MODEL_AND_COMPLETE_ADAPTER_UNDER_EXPLICIT_PORT_BIJECTION',
                  stateful_model_sha256=digest(ram_a), stateful_model_bytes=len(ram_a.encode()),
                  wrapper_ports=294, combinational_assignments=256, read_channels=35,
                  write_channels=1, read_port_bijection=mapping,
                  canonical_adapter_sha256=digest(json.dumps(normal, sort_keys=True)),
                  negative_mutations_rejected=rejected,
                  reused_entry_metrics=read(C / 'entry-result.json')['results']['MCConfig']['metrics'],
                  limitations=[
                      'Reuses finite 2569-cycle/178857-defined-comparison boundary validation, not universal RamModel equivalence.',
                      'Port bijection is explicit; complete DCache embedding and same-target whole runtime parity remain independent gates.',
                      'No area or whole-system saving inferred, no new compile/map/metasim/FPGA run.'])
    return result


def prepare():
    assert not (C / 'plan.json').exists() and not O.exists(), 'preserve existing evidence'
    O.mkdir(parents=True)
    extraction = read(W / 'candidates/mcrams-owner-generated-area-r1-20261111/extraction.json')
    entry = read(ENTRY / 'result.json')
    assert entry['functional_baseline_commit'] == BASE and entry['hardware_commit'] == HW
    assert entry['status'].startswith('PASS_') and entry['results']['MCConfig']['negative_rejected']
    source_hashes = {}
    for label, path, expected, top in [
        ('actual', ACTUAL, extraction['source_sha256'], 'ownerImageMemory_flattened'),
        ('tested', ENTRY / 'MCConfig/FireSim-generated.sv',
         entry['results']['MCConfig']['host_rtl_sha256'], 'ownerImageMemory')]:
        raw = path.read_bytes()
        assert hashlib.sha256(raw).hexdigest() == expected
        source_hashes[str(path)] = expected
        text = raw.decode()
        wrapper, ram = module(text, top), module(text, 'RamModel')
        if label == 'actual':
            assert digest(wrapper) == extraction['modules'][top]
            assert digest(ram) == extraction['modules']['RamModel']
        (C / (label + '-wrapper.sv')).write_text(wrapper)
        (C / (label + '-RamModel.sv')).write_text(ram)
    evidence = [ENTRY / 'result.json', ENTRY / 'entry-inventory.json',
                ENTRY / 'receipts/run-MCConfig.json', ENTRY / 'receipts/negative-MCConfig.json',
                D / 'build-logs/Opt4-mcrams-dcache-owner-audit-round43-r3-20261111/result.json',
                D / 'build-logs/Opt4-mcrams-dcache-owner-audit-round43-r3-20261111/complete.json']
    evidence_hashes = {}
    for i, path in enumerate(evidence):
        raw = path.read_bytes()
        evidence_hashes[str(path)] = hashlib.sha256(raw).hexdigest()
        (C / ('entry-result.json' if i == 0 else f'evidence-{i}-{path.name}')).write_bytes(raw)
    for stage, expected_rc in [('run-MCConfig', 0), ('negative-MCConfig', 1)]:
        r = read(ENTRY / 'receipts' / (stage + '.json'))
        assert r['returncode'] == expected_rc and sha(r['log']) == r['log_sha256']
        evidence_hashes[r['log']] = r['log_sha256']
    result = analyze()
    save(C / 'preflight.json', result)
    files = [f for f in C.iterdir() if f.is_file() and f.name != 'plan.json']
    plan = dict(schema='ec-owner-model-reuse-plan/1', functional_baseline=BASE,
                derived_hardware=HW, created_utc=now(), inputs={str(f): sha(f) for f in files},
                original_sources=source_hashes, evidence=evidence_hashes,
                source_binding='Verified complete source hashes once at immutable capsule creation; execution uses those exact copied modules.',
                cpu_work='Bounded text/connection identity only; no external tool, no CAD, no simulator, no FPGA.',
                fpga_access=False, production_admission=False, whole_fit=False)
    save(C / 'plan.json', plan)
    request = dict(action='cpu_job', spec=dict(name=NAME, kind='analysis', cwd=str(C),
        argv=['/usr/bin/python3', str(C / 'audit.py'), '--run'],
        inputs={str(f): sha(f) for f in files + [C / 'plan.json']},
        outputs=[str(O / 'result.json')], checkpoints=[str(S)]))
    save(C / 'request.json', request)
    dest = U / 'requests' / (NAME + '.json')
    assert not dest.exists()
    policy()
    save(dest, request)
    print(json.dumps(dict(request=str(dest), preflight_status=result['status'],
                          ports=result['wrapper_ports'], assignments=result['combinational_assignments'])))


def run():
    lock = (O / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    plan = read(C / 'plan.json')
    assert all(sha(p) == h for p, h in plan['inputs'].items())
    if (O / 'complete.json').exists():
        done = read(O / 'complete.json')
        assert sha(O / 'result.json') == done['result_sha256']
        print('ADOPTED_IMMUTABLE_COMPLETE')
        return
    assert not (O / 'result.json').exists(), 'partial evidence retained'
    result = analyze()
    assert result == read(C / 'preflight.json')
    result.update(completed_utc=now(), plan_sha256=sha(C / 'plan.json'),
                  inputs_sha256=plan['inputs'], original_sources=plan['original_sources'])
    save(O / 'result.json', result)
    save(O / 'complete.json', dict(result_sha256=sha(O / 'result.json'),
                                 controller_sha256=sha(__file__)))
    stat = Path(f'/proc/{os.getpid()}/stat').read_text().rsplit(')', 1)[1].split()
    save(S, dict(status=result['status'], pid=os.getpid(), start_ticks=stat[19],
                 host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
                 updated_utc=now(), fpga_access=False, result=str(O / 'result.json')))
    print(result['status'])


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--prepare', action='store_true')
    parser.add_argument('--run', action='store_true')
    args = parser.parse_args()
    assert args.prepare != args.run
    policy()
    if args.prepare:
        prepare()
    else:
        run()
