#!/usr/bin/python3
"""Prepare an honest complete-host area boundary; never run CAD or simulation.

GoldenGate excises ownerImageMemory from the target hierarchy. Its host RAM
model is a sibling of FireSim under FAMETop, rather than a DCache child. A
DCache-only OOC map would therefore omit that RAM and its token scheduler.
"""
from pathlib import Path
import datetime
import hashlib
import json
import os
import re

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
PAIR = W/'candidates/mcrams-owner-pair-compile-round43-v1-20261111/plan.json'
AUDIT = D/'build-logs/Opt4-mcrams-dcache-owner-audit-round43-r3-20261111/result.json'
DCACHE = 'BoomNonBlockingDCache'
MEMORY = 'ownerImageMemory_flattened'


def read(path):
    return json.loads(Path(path).read_text())


def digest(data):
    return hashlib.sha256(data).hexdigest()


def save(path, value):
    path = Path(path)
    with path.open('x') as stream:
        json.dump(value, stream, indent=2, sort_keys=True)
        stream.write('\n')
        stream.flush()
        os.fsync(stream.fileno())


def modules(text):
    found = list(re.finditer(r'^module\s+(\w+)\b.*?^endmodule\b[^\n]*',
                             text, re.M | re.S))
    result = {match[1]: match[0] for match in found}
    assert len(found) == len(result), 'duplicate module definitions'
    assert len(result) > 100, 'incomplete generated source'
    return result


def instances(body, known):
    # These emitted modules use unparameterized named-port instances. Match
    # the line-start module/instance pair, then require a known definition.
    return [(match[1], match[2]) for match in re.finditer(
        r'^\s*(\w+)\s+(\w+)\s*\(', body, re.M) if match[1] in known]


def paths_to(graph, root, target):
    paths = []

    def visit(module, path, ancestors):
        assert module not in ancestors, 'recursive module hierarchy'
        if module == target:
            paths.append(path)
            return
        for child, instance in graph[module]:
            visit(child, path + [{'module': child, 'instance': instance}],
                  ancestors | {module})

    visit(root, [{'module': root, 'instance': None}], set())
    return paths


def header_ports(body):
    header = body[:body.index(');') + 2]
    # Remove source-location comments before handling wrapped port lines.
    clean = re.sub(r'//[^\n]*', '', header)
    rows = re.findall(r'\b(input|output)\s+(?:\[([^\]]+)\]\s+)?(\w+)', clean)
    ports = {name: {'direction': direction, 'range': width or None}
             for direction, width, name in rows}
    assert len(ports) == len(rows) and 'clock' in ports and 'reset' in ports
    return ports


def common_ancestor(a, b):
    common = []
    for left, right in zip(a, b):
        if left != right:
            break
        common.append(left)
    assert common
    return common[-1]['module']


def main():
    policy = read(D/'unattended-opt4/campaign-policy.json')
    assert policy['functional_baseline_commit'] == BASE
    assert policy['area_equivalence_only'] and policy['native_paused']
    assert not policy['fpga_access'] and not policy['functional_extensions_allowed']
    assert policy['board_allowlist'] == ['0000:21:00.0']
    assert not (C/'area-boundary.json').exists(), 'adopt immutable prepared result'
    plan, audit = read(PAIR), read(AUDIT)
    assert plan['functional_baseline'] == BASE
    assert audit['complete_prehost_target_byte_identical']
    assert audit['target_DCache_nonwrapper_statements_identical']
    result = {}
    port_sets = {}
    for mode in plan['modes']:
        label, source = mode['label'], Path(mode['source_host_rtl'])
        data = source.read_bytes()
        assert digest(data) == mode['host_rtl_sha256'], ('changed host RTL', label)
        all_modules = modules(data.decode())
        del data
        graph = {name: instances(body, all_modules)
                 for name, body in all_modules.items()}
        dcache_paths = paths_to(graph, 'FAMETop', DCACHE)
        assert len(dcache_paths) == 1, ('ambiguous DCache hierarchy', label)
        ram_paths = paths_to(graph, 'FAMETop', MEMORY)
        if label == 'MC':
            assert len(ram_paths) == 1, 'missing or duplicate excised owner model'
            assert common_ancestor(dcache_paths[0], ram_paths[0]) == 'FAMETop'
            assert not paths_to(graph, DCACHE, MEMORY), 'owner model became a DCache child'
            assert any(child == 'RamModel' for child, _ in graph[MEMORY])
        else:
            assert label == 'Plain' and not ram_paths
        port_sets[label] = header_ports(all_modules[DCACHE])
        evidence_names = {item['module'] for path in dcache_paths + ram_paths for item in path}
        evidence_names |= {'FAMETop', 'FireSim', DCACHE}
        evidence_dir = C/label
        evidence_dir.mkdir()
        for name in sorted(evidence_names):
            # Exact module bodies, without renaming, pruning, or added RTL.
            (evidence_dir/(name+'.sv')).write_text(all_modules[name])
        result[label] = dict(source=str(source), source_sha256=mode['host_rtl_sha256'],
            source_stat={'bytes': source.stat().st_size, 'mtime_ns': source.stat().st_mtime_ns},
            module_count=len(all_modules), dcache_paths=dcache_paths,
            owner_model_paths=ram_paths, dcache_port_count=len(port_sets[label]),
            captured_modules={name: dict(bytes=len(all_modules[name].encode()),
                sha256=digest(all_modules[name].encode()), children=graph[name])
                for name in sorted(evidence_names)})
        del graph, all_modules
    plain, mc = port_sets['Plain'], port_sets['MC']
    assert all(mc.get(name) == spec for name, spec in plain.items()), 'original DCache interface changed'
    added = sorted(set(mc) - set(plain))
    assert added and all(name.startswith(MEMORY + '_') for name in added)
    # A scheduler omission and omitted RAM must never be described as complete
    # host area. Store the enclosing boundary rather than an invalid map TCL.
    value = dict(schema='ec-mcrams-complete-host-area-boundary/1',
        status='PREPARED_EXACT_ENCLOSING_BOUNDARY_NOT_MAPPED_OR_ADMITTED',
        created_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
        functional_baseline=BASE, derived_hardware=plan['hardware_commit'],
        source_id=plan['source_id'], modes=result,
        original_dcache_ports_preserved=len(plain), added_memory_cut_ports=added,
        required_enclosing_host_root='FAMETop',
        dcache_only_map_would_omit_owner_host_RAM=True,
        existing_owner_wrapper_request='owner-generated-area-r1-3656aec4',
        existing_pair_compile_request='mcrams-owner-pair-compile-r43-v2-3656aec4',
        no_duplicate_existing_jobs=True, cpu_job_submitted=False, whole_cad_started=False,
        fpga_access=False, full_DCache_area_measured=False, whole_fit=False,
        production_admission=False,
        next_required=[
            'Adopt the existing owner pair compilation and same-target workload parity receipts.',
            'Keep the existing exact owner-wrapper area result separate from complete-host area.',
            'Any FAMETop synthesis is a full-DUT build: wait for e0 exit, resource guards, '
            'and source/config/annotation/ABI admission; do not submit a third whole.',
            'An independently reconstructed smaller cut would need exact token scheduler, '
            'target-edge, reset, read/write conflict, and all original observation proof first.'],
        evidence={str(PAIR): digest(PAIR.read_bytes()), str(AUDIT): digest(AUDIT.read_bytes())})
    save(C/'area-boundary.json', value)
    print(json.dumps({key: value[key] for key in ['status', 'required_enclosing_host_root',
          'original_dcache_ports_preserved', 'cpu_job_submitted', 'whole_fit']}))


if __name__ == '__main__':
    main()
