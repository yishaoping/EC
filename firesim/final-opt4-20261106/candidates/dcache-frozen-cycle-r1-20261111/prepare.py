#!/usr/bin/python3
"""Build an isolated complete-DCache cycle miter from authenticated generated RTL.

Only module names and extra read-only observation ports change in these copies.
All dependencies, assertions, existing outputs, storage, and parameters remain.
"""
from pathlib import Path
import hashlib
import json
import re

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
TOP = 'BoomNonBlockingDCache'
FROZEN = '8491167d84b6d9521b151a743673c1516926a1f8'
COMMIT = 'd9d732622601ed792a2647546006b5aae986ab8e'
SID = '1639f464d8675806abb5d7dd04adc5dfd1fcf0e351e016ef6a20adcbea1b6e4e'


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''):
            h.update(block)
    return h.hexdigest()


def policy():
    p = read(D / 'unattended-opt4/campaign-policy.json')
    assert p['functional_baseline_commit'] == FROZEN
    assert p['area_equivalence_only'] and not p['functional_extensions_allowed']
    assert not p['fpga_access'] and p['native_paused']


def save_new(p, value):
    with Path(p).open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n')


def generate(out):
    policy()
    out = Path(out)
    out.mkdir(parents=True, exist_ok=True)
    inputs = read(C / 'input-hashes.json')
    assert all(sha(p) == h for p, h in inputs.items()), 'changed bound input'
    frozen_receipt = read(C / 'evidence/frozen-goldengate.json')
    candidate_receipt = read(C / 'evidence/candidate-rtl.json')
    assert frozen_receipt['frozen_hardware_commit'] == FROZEN
    assert frozen_receipt['config'] == 'DacOpt4C4' and frozen_receipt['returncode'] == 0
    assert candidate_receipt['hardware_commit'] == COMMIT
    assert candidate_receipt['source_id'] == SID
    assert candidate_receipt['configuration_matches_frozen_parameters']
    parameters = read(C / 'evidence/frozen-parameters.json')
    assert parameters['configuration'] == 'firesim.firesim.DacOpt4C4'
    frozen_path = next(Path(p) for p in frozen_receipt['outputs'] if p.endswith('FireSim-generated.sv'))
    candidate_path = Path(candidate_receipt['goldengate_dir']) / 'FireSim-generated.sv'
    ports = {}
    observations = {}
    metadata = {}
    originals = [
        ('frozen', frozen_path, frozen_receipt['outputs'][str(frozen_path)],
         C / 'evidence/frozen-annotations.json', 'Frozen__'),
        ('candidate', candidate_path, candidate_receipt['outputs'][str(candidate_path)],
         C / 'evidence/candidate-annotations.json', 'Candidate__'),
    ]
    for label, path, digest, annotation, prefix in originals:
        policy()
        assert sha(path) == digest
        text = path.read_text()
        matches = list(re.finditer(r'^module ([A-Za-z_][\w$]*)\(', text, re.M))
        modules = {}
        for m in matches:
            end = text.index('\nendmodule', m.end()) + len('\nendmodule')
            modules[m.group(1)] = text[m.start():end] + '\n'
        assert TOP in modules
        header = re.match(r'module ' + TOP + r'\((.*?)\);', modules[TOP], re.S)
        assert header
        ports[label] = [(direction, int(high) + 1 if high else 1, name)
                        for direction, high, name in re.findall(
                            r'(input|output)\s+(?:\[(\d+):0\]\s+)?(\w+)', header.group(1))]
        assert len(ports[label]) == 362, 'actual complete frozen interface required'
        body = modules[TOP][header.end():]
        # One declaration scan avoids hundreds of repeated scans of the large module.
        declared = {}
        for m in re.finditer(r'(?m)^[ \t]*(?:input|output|wire|reg)[ \t]+(?:\[(\d+):0\][ \t]+)?([A-Za-z_][\w$]*)[ \t]*(?=[=;,\n])',
                             modules[TOP]):
            declared[m.group(2)] = int(m.group(1)) + 1 if m.group(1) else 1
        names = [row['target'].split('>', 1)[1] for row in read(annotation)
                 if row.get('class') == 'firrtl.transforms.DontTouchAnnotation'
                 and row.get('target', '').startswith('~FireSim|' + TOP + '>')]
        observed = {}
        unmatched = []
        for raw in sorted(set(names)):
            stem = re.sub(r'[^A-Za-z0-9_$]', '_', raw).rstrip('_')
            pattern = re.compile(re.escape(stem) + r'(?:_\d+)*$')
            selected = [n for n in declared if pattern.fullmatch(n)]
            if not selected:
                unmatched.append(raw)
            for name in selected:
                observed[name] = declared[name]
        assert not unmatched, ('do not drop frozen observations', label, unmatched)
        for i in range(512):
            name = 'debug_line_generation_' + str(i)
            assert declared.get(name) == 32
            observed[name] = 32
        observations[label] = observed
        # Keep each observation separately identifiable, including invalid states.
        additions = ',\n' + ',\n'.join('  output ' + (f'[{bits-1}:0] ' if bits > 1 else '')
                                        + 'cycle_observe_' + name for name, bits in sorted(observed.items()))
        modified = header.group(0)[:-2] + additions + '\n);' + body
        point = modified.rindex('\nendmodule')
        assignments = '\n'.join('  assign cycle_observe_' + name + ' = ' + name + ';'
                                 for name in sorted(observed))
        modules[TOP] = modified[:point] + '\n' + assignments + modified[point:]
        dependencies = {}
        instance = re.compile(r'(?m)^[ \t]+([A-Za-z_][\w$]*)[ \t]+(?:#\([^;]+?\)[ \t]*)?([A-Za-z_][\w$]*)[ \t]*\(')
        todo = [TOP]
        selected = set()
        while todo:
            name = todo.pop()
            if name in selected:
                continue
            selected.add(name)
            deps = {m.group(1) for m in instance.finditer(modules[name]) if m.group(1) in modules}
            dependencies[name] = sorted(deps)
            todo.extend(deps - selected)
        assert len(selected) > 20, 'complete child-module closure required'
        # Rename declarations and instance type tokens only; no logic edits.
        rename = re.compile(r'(?m)^(module[ \t]+|[ \t]+)(' + '|'.join(
            sorted(map(re.escape, selected), key=len, reverse=True)) + r')(?=[ \t(])')
        closure = '\n'.join(rename.sub(lambda m: m.group(1) + prefix + m.group(2), modules[name])
                            for name in sorted(selected))
        target = out / (label + '.sv')
        target.write_text(closure)
        metadata[label] = dict(path=str(path), sha256=digest, closure=str(target),
                               closure_sha256=sha(target), modules=sorted(selected),
                               dependencies=dependencies, assertions_preserved=True,
                               original_output_count=sum(d == 'output' for d, w, n in ports[label]),
                               original_annotation_targets=len(names), observation_count=len(observed),
                               observation_bits=sum(observed.values()),
                               simulation_initialization='Both copies use zero Verilator initialization; arbitrary payload/reset relation is proved separately.')
    assert ports['frozen'] == ports['candidate'], 'complete interfaces differ'
    assert observations['frozen'] == observations['candidate'], 'debug observations differ'
    observed = observations['frozen']
    rows = ports['frozen']
    outputs = [(n, w) for d, w, n in rows if d == 'output']
    comparison = outputs + [('cycle_observe_' + n, w) for n, w in sorted(observed.items())]
    wrapper = ['module DCacheCyclePair(\n' + ',\n'.join(
        '  ' + d + ' ' + (f'[{w-1}:0] ' if w > 1 else '') + n for d, w, n in rows)
        + f',\n  output [{len(comparison)-1}:0] cycle_mismatch\n);']
    for name, bits in comparison:
        if name.startswith('cycle_observe_'):
            wrapper.append('wire ' + (f'[{bits-1}:0] ' if bits > 1 else '') + 'f_' + name + ';')
        wrapper.append('wire ' + (f'[{bits-1}:0] ' if bits > 1 else '') + 'c_' + name + ';')
    for label, prefix, wireprefix in [('frozen', 'Frozen__', 'f_'), ('candidate', 'Candidate__', 'c_')]:
        connections = []
        for direction, bits, name in rows:
            signal = name if direction == 'input' or label == 'frozen' else wireprefix + name
            connections.append('.' + name + '(' + signal + ')')
        connections += ['.cycle_observe_' + name + '(' + wireprefix + 'cycle_observe_' + name + ')'
                        for name in sorted(observed)]
        wrapper.append(prefix + TOP + ' ' + label + '(\n' + ',\n'.join(connections) + '\n);')
    for i, (name, bits) in enumerate(comparison):
        left = 'f_' + name if name.startswith('cycle_observe_') else name
        wrapper.append(f'assign cycle_mismatch[{i}] = ({left} != c_{name});')
    wrapper.append('endmodule\n')
    (out / 'pair.sv').write_text('\n'.join(wrapper))
    # Explicitly initialize every top input on every cycle, then apply the
    # stateful legal protocol driver. No stimulus depends on candidate outputs.
    clear = ['static void clear_inputs(VDCacheCyclePair &d) {']
    for direction, bits, name in rows:
        if direction == 'input':
            clear.append('  ' + (f'for (auto &word : d.{name}) word = 0;' if bits > 64 else f'd.{name} = 0;'))
    clear.append('}\n')
    (out / 'clear-inputs.h').write_text('\n'.join(clear))
    (out / 'mismatch-names.h').write_text('static const char *mismatch_names[] = {\n' + ',\n'.join(
        json.dumps(n) for n, w in comparison) + '\n};\n')
    save_new(out / 'preparation.json', dict(schema='ec-opt4-complete-dcache-cycle-preparation/1',
        hardware_commit=COMMIT, source_id=SID, functional_baseline_commit=FROZEN,
        authenticated_rtl=metadata, compared_signals=len(comparison),
        compared_bits=sum(w for n, w in comparison), all_original_outputs=True,
        all_original_donttouch_observations=True, generation_taps=512,
        full_module_formal=False, whole_admission=False, fpga_access=False,
        pair_sha256=sha(out / 'pair.sv'), inputs=inputs))
    return read(out / 'preparation.json')


if __name__ == '__main__':
    import sys
    print(json.dumps(generate(sys.argv[1]), sort_keys=True))
