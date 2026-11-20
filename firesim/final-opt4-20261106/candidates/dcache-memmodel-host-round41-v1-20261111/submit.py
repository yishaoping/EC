#!/usr/bin/python3
"""One-shot guarded request publication; no timer, child process, or FPGA I/O."""
from pathlib import Path
import ast
import datetime
import fcntl
import hashlib
import json
import os
import shutil

C = Path(__file__).resolve().parent
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
PREP = W / 'candidates/dcache-memmodel-prep-round41-v3-20261111'
RESULT = D / 'build-logs/Opt4-dcache-memmodel-prep-round41-v3-20261111/result.json'
NAME = 'dcache-memmodel-host-r41-v1-3656aec4'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for data in iter(lambda: f.read(2**20), b''):
            h.update(data)
    return h.hexdigest()


def write_new(p, value):
    with Path(p).open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())


def main():
    policy = read(U / 'campaign-policy.json')
    assert policy['functional_baseline_commit'] == BASE and policy['area_equivalence_only']
    assert policy['native_paused'] and not policy['functional_extensions_allowed'] and not policy['fpga_access']
    lock = (C / 'submit.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    request = U / 'requests' / (NAME + '.json')
    if request.exists():
        receipt = U / 'request-results' / (NAME + '.json')
        print(json.dumps(dict(status='ADOPT_EXISTING_UNIQUE_REQUEST', request=str(request),
                              broker=read(receipt) if receipt.exists() else None)))
        return
    if not RESULT.is_file():
        print(json.dumps(dict(status='WAITING_EXACT_TARGET_ANNOTATION_PREPARATION', prerequisite=str(RESULT),
                              request_submitted=False, cpu_waiting_job_created=False)))
        return
    prep = read(RESULT)
    assert prep['status'] == 'PASS_EXACT_TARGET_FOUR_MEMORY_ANNOTATIONS_RESOLVED_NOT_TRANSFORMED_OR_ADMITTED'
    assert prep['functional_baseline'] == BASE and prep['added_annotations'] == 4
    assert prep['negative_cases_rejected'] == 4 and prep['generation_read_ports'] == 518
    before = read(PREP / 'plan.json')
    raw = Path(before['target_fir'])
    assert sha(raw) == prep['target_fir_sha256'] == before['inputs'][str(raw)]
    assert sha(prep['annotated_json']) == prep['annotated_json_sha256']
    # Preserve source provenance and verify every copied dependency before use.
    evidence = C / 'evidence'
    evidence.mkdir(exist_ok=True)
    origins = {
        'preparation.json': RESULT,
        'corrected-area.json': D / 'build-logs/Opt4-mcrams-dcache-entry-area-analysis-r1-20261111/result.json',
        'finite-entry-parity.json': D / 'build-logs/Opt4-mcrams-dcache-entry-r5-20261111/result.json',
        'memory-coverage.json': RESULT.parent / 'memory-coverage.json',
        'annotation-resolution-receipt.json': RESULT.parent / 'receipts/resolve.json'}
    provenance = {}
    for name, original in origins.items():
        target = evidence / name
        if target.exists():
            assert sha(target) == sha(original), 'Existing evidence copy changed; independent version required'
        else:
            shutil.copy2(original, target)
        provenance[str(target)] = dict(original=str(original), sha256=sha(target))
    area = read(evidence / 'corrected-area.json')
    assert area['status'] == 'CORRECTED_AREA_COMPLETE_NOT_FULL_DCACHE_OR_OPT4_FIT'
    assert area['results']['PlainConfig']['resources']['CLB LUTs']['used'] == 405706
    assert area['results']['MCConfig']['resources']['CLB LUTs']['used'] == 24192
    annotation = C / 'four-owner-memories.anno.json'
    if annotation.exists():
        assert sha(annotation) == prep['annotated_json_sha256']
    else:
        shutil.copy2(prep['annotated_json'], annotation)
    cfg = read(before['config'])
    inputs = {str(raw): prep['target_fir_sha256'], before['config']: before['inputs'][before['config']]}
    for path in set(cfg['classpath'] + cfg['compiler']):
        assert sha(path) == before['inputs'][path]
        inputs[path] = before['inputs'][path]
    helper = W / 'routes/cycleprecise-r2-20261111/run.py'
    for p in [C / 'controller.py', C / 'submit.py', C / 'README.md', helper, annotation, *[evidence / name for name in origins]]:
        inputs[str(p)] = sha(p)
    for p in (C / 'controller.py', C / 'submit.py'):
        ast.parse(p.read_text(), filename=str(p))
    provenance_path = evidence / 'provenance.json'
    if provenance_path.exists():
        assert read(provenance_path) == provenance
    else:
        write_new(provenance_path, provenance)
    inputs[str(provenance_path)] = sha(provenance_path)
    host_input_id = hashlib.sha256(json.dumps(inputs, sort_keys=True).encode()).hexdigest()
    plan = dict(schema='ec-opt4-four-owner-mcrams-host-plan/1', functional_baseline=BASE,
                derived_hardware_commit=prep['derived_hardware_commit'], source_id=prep['source_id'],
                host_input_id=host_input_id, target_fir=str(raw), config=before['config'], inputs=inputs,
                external_tool_inputs=before['external_tool_inputs'], fpga_access=False,
                full_dut_equivalence=False, production_admission=False,
                prerequisite_scope='Actual local entry parity and paired area plus unchanged-target annotation resolution only')
    plan_path = C / 'plan.json'
    if plan_path.exists():
        assert read(plan_path) == plan
    else:
        write_new(plan_path, plan)
    job = dict(action='cpu_job', spec=dict(name=NAME, kind='rtl', cwd=str(C),
               argv=['/usr/bin/python3', str(C / 'controller.py')], inputs={**inputs, str(plan_path): sha(plan_path)},
               outputs=[str(D / 'build-logs/Opt4-dcache-memmodel-host-round41-v1-20261111/result.json')],
               checkpoints=[str(D / 'Opt4-dcache-memmodel-host-round41-v1-state.json')]))
    assert all(Path(path).is_relative_to(W) for path in job['spec']['inputs'])
    local = C / 'request.json'
    if local.exists():
        assert read(local) == job
    else:
        write_new(local, job)
    temp = request.with_name('.' + request.name + '.tmp-' + str(os.getpid()))
    write_new(temp, job)
    os.link(temp, request)
    temp.unlink()
    print(json.dumps(dict(status='REQUEST_PUBLISHED_NOT_YET_STARTED', request=str(request),
                          host_input_id=host_input_id, created_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())))


if __name__ == '__main__':
    main()
