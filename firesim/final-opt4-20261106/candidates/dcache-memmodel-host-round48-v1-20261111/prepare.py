#!/usr/bin/python3
"""Seal a four-memory host continuation; never submit or launch a CPU job."""
import ast
import copy
import hashlib
import json
import os
from pathlib import Path

C = Path(__file__).resolve().parent
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
PREP = W/'candidates/dcache-memmodel-prep-round41-v3-20261111'
AREA_SHA = '34fc766d60d2aa577050e88f9fa125ab04096ac3df91494ad8e308f047598e4c'
EXPECTED = {'ownerImageMemory_flattened': (81, 35),
            'ownerGenerationMemory': (32, 518),
            'ownerPacketMemory': (32, 4), 'ownerTrackedMemory': (1, 4)}


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as stream:
        for block in iter(lambda: stream.read(2**20), b''):
            h.update(block)
    return h.hexdigest()


def once(p, data):
    p = Path(p)
    p.parent.mkdir(parents=True, exist_ok=True)
    if p.exists():
        assert p.read_bytes() == data, ('immutable prepared file changed', str(p))
        return
    temp = p.with_name('.' + p.name + '.tmp-' + str(os.getpid()))
    with temp.open('xb') as stream:
        stream.write(data)
        stream.flush()
        os.fsync(stream.fileno())
    try:
        os.link(temp, p)
    finally:
        temp.unlink()


def save(p, value):
    once(p, (json.dumps(value, indent=2, sort_keys=True) + '\n').encode())


def annotation_check(original, added, memories):
    cls = 'midas.targetutils.FirrtlMemModelAnnotation'
    names = ['ownerImageMemory', 'ownerGenerationMemory', 'ownerPacketMemory', 'ownerTrackedMemory']
    assert added == original + [{'class': cls, 'target': '~FireSim|BoomNonBlockingDCache>' + n} for n in names]
    assert sum(a.get('class') == cls for a in original) == 10
    assert sum(a.get('class') == cls for a in added) == 14
    assert sum('EnableModelMultiThreadingAnnotation' in a.get('class', '') for a in added) == 5
    assert set(memories) == set(EXPECTED)
    for name, (width, readers) in EXPECTED.items():
        m = memories[name]
        assert (m['width'], m['depth'], m['read_latency'], m['write_latency'], m['read_under_write']) == (width, 512, 0, 1, 'undefined')
        assert len(m['readers']) == readers and len(m['writers']) == 1 and not m['readwriters']


def main():
    policy = read(U/'campaign-policy.json')
    assert policy['functional_baseline_commit'] == BASE and policy['area_equivalence_only']
    assert policy['native_paused'] and not policy['functional_extensions_allowed'] and not policy['fpga_access']
    old = read(PREP/'plan.json')
    origins = {
        'preparation.json': D/'build-logs/Opt4-dcache-memmodel-prep-round41-v3-20261111/result.json',
        'memory-coverage.json': D/'build-logs/Opt4-dcache-memmodel-prep-round41-v3-20261111/memory-coverage.json',
        'resolution.json': D/'build-logs/Opt4-dcache-memmodel-prep-round41-v3-20261111/receipts/resolve.json',
        'resolution.log': D/'build-logs/Opt4-dcache-memmodel-prep-round41-v3-20261111/resolve.log',
        'corrected-area-r2.json': D/'build-logs/Opt4-mcrams-dcache-entry-area-analysis-r2-20261111/result.json',
        'corrected-area-complete.json': D/'build-logs/Opt4-mcrams-dcache-entry-area-analysis-r2-20261111/complete.json',
        'entry-parity.json': D/'build-logs/Opt4-mcrams-dcache-entry-r5-20261111/result.json',
        'owner-audit-r3.json': D/'build-logs/Opt4-mcrams-dcache-owner-audit-round43-r3-20261111/result.json'}
    provenance = {}
    for name, origin in origins.items():
        dest = C/'evidence'/name
        once(dest, origin.read_bytes())
        provenance[str(dest)] = {'original': str(origin), 'sha256': sha(dest)}
    assert sha(C/'evidence/corrected-area-r2.json') == AREA_SHA
    assert read(C/'evidence/corrected-area-complete.json')['result_sha256'] == AREA_SHA
    prep = read(C/'evidence/preparation.json')
    assert prep['status'] == 'PASS_EXACT_TARGET_FOUR_MEMORY_ANNOTATIONS_RESOLVED_NOT_TRANSFORMED_OR_ADMITTED'
    assert prep['functional_baseline'] == BASE and prep['negative_cases_rejected'] == 4
    assert prep['added_annotations'] == 4 and prep['generation_read_ports'] == 518
    resolution = read(C/'evidence/resolution.json')
    assert resolution['returncode'] == 0 and sha(C/'evidence/resolution.log') == resolution['log_sha256']
    assert 'PASS_UNCHANGED_TARGET_AST_MEMORY_ANNOTATION_RESOLUTION' in (C/'evidence/resolution.log').read_text()
    area = read(C/'evidence/corrected-area-r2.json')
    assert area['status'] == 'CORRECTED_AREA_COMPLETE_NOT_FULL_DCACHE_OR_OPT4_FIT'
    assert [area['results'][n]['resources']['CLB LUTs']['used'] for n in ['PlainConfig', 'MCConfig']] == [405706, 24192]
    parity = read(C/'evidence/entry-parity.json')['results']
    assert parity['PlainConfig']['target_sha256'] == parity['MCConfig']['target_sha256']
    assert all(r['negative_rejected'] and r['metrics']['checked_values'] == 178857 for r in parity.values())
    raw, annotations, low = [Path(old[k]) for k in ['target_fir', 'target_annotations', 'lowered_target']]
    for f in [raw, annotations, low, Path(old['config'])]:
        assert sha(f) == old['inputs'][str(f)], ('prior source changed', str(f))
    assert sha(raw) == prep['target_fir_sha256']
    candidate = Path(prep['annotated_json'])
    assert sha(candidate) == prep['annotated_json_sha256']
    once(C/'four-owner-memories.anno.json', candidate.read_bytes())
    original, added = read(annotations), read(candidate)
    memories = read(C/'evidence/memory-coverage.json')['lowered_memories']
    annotation_check(original, added, memories)
    rejected = []
    mutations = [
        ('dropped_original_observation', original[1:], added, memories),
        ('extra_host_annotation', original, added + [added[-1]], memories),
        ('changed_memory_target', original, added[:-1] + [{'class': added[-1]['class'], 'target': '~FireSim|BoomNonBlockingDCache>other'}], memories)]
    bad = copy.deepcopy(memories)
    bad['ownerGenerationMemory']['readers'].pop()
    mutations.append(('dropped_generation_observation', original, added, bad))
    for label, a, b, m in mutations:
        try:
            annotation_check(a, b, m)
        except AssertionError:
            rejected.append(label)
        else:
            raise AssertionError(('mutation accepted', label))
    save(C/'evidence/provenance.json', provenance)
    cfg = read(old['config'])
    sources = {str(p): old['inputs'][str(p)] for p in [raw, annotations, low, Path(old['config'])]}
    # Prior source-bound compiler hashes remain authenticated again at execution.
    for p in set(cfg['classpath'] + cfg['compiler']):
        assert Path(p).is_relative_to(W)
        sources[p] = old['inputs'][p]
    local = [C/'controller.py', C/'prepare.py', C/'README.md', C/'four-owner-memories.anno.json', *sorted((C/'evidence').iterdir())]
    for p in local:
        if p.suffix == '.py':
            ast.parse(p.read_text(), filename=str(p))
    inputs = {**sources, **{str(p): sha(p) for p in local}}
    assert all(Path(p).is_relative_to(W) for p in inputs)
    save(C/'plan.json', dict(schema='ec-four-owner-host-continuation/1', functional_baseline=BASE,
        hardware_commit=prep['derived_hardware_commit'], source_id=prep['source_id'],
        target_fir=str(raw), target_annotations=str(annotations), lowered_target=str(low), config=old['config'],
        inputs=inputs, external_tool_inputs=old['external_tool_inputs'],
        memory_interfaces=memories, original_annotations=len(original), new_annotations=len(added),
        preflight_negative_rejected=rejected, area_r2_sha256=AREA_SHA,
        original_submitter_preserved=str(W/'candidates/dcache-memmodel-host-round41-v1-20261111/submit.py'),
        required_completed_receipts=[str(D/'cycleprecise-original-svb-gg-stream-replay-r3-20261111/full-result.json'),
            str(D/'cycleprecise-owner-pair-runtime-r1-20261111/result.json')],
        complete_prehost_target_sha256=sha(low), target_function_changed=False, target_cycles_changed=False,
        submitted=False, fpga_access=False, whole_synthesis=False, production_admission=False,
        scope='Prepared host transform only; 35/518/4/4 ports retained. No four-memory host parity or full DCache/Opt4 area evidence.'))
    print(json.dumps(dict(status='PREPARED_EXACT_FOUR_MEMORY_CONTINUATION_NOT_SUBMITTED',
        preserved_annotations=len(original), added_annotations=4, readers=[35, 518, 4, 4],
        negative_cases_rejected=len(rejected), broker_inputs=len(inputs), fpga_access=False)))


if __name__ == '__main__':
    main()
