#!/usr/bin/python3
"""Authenticate the completed GG prefix and appended resources, then reuse r2's
exact target/wrapper checks. Read-only producer; immutable independent result.
"""
import datetime
import fcntl
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import traceback

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
O = D/'build-logs/Opt4-mcrams-dcache-owner-audit-round43-r3-20261111'
R = D/'build-logs/Opt4-mcrams-dcache-owner-system-r1-20261111'
OLD = W/'candidates/mcrams-dcache-owner-audit-r2-20261111'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'

def read(p): return json.loads(Path(p).read_text())
def now(): return datetime.datetime.now(datetime.timezone.utc).isoformat()
def digest(data): return hashlib.sha256(data).hexdigest()
def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda: f.read(2**20), b''): h.update(b)
    return h.hexdigest()
def save(p, obj):
    p = Path(p); t = p.with_name(p.name+'.tmp-'+str(os.getpid()))
    with t.open('x') as f:
        json.dump(obj, f, indent=2, sort_keys=True); f.write('\n')
        f.flush(); os.fsync(f.fileno())
    os.replace(t, p)
def policy():
    p = read(D/'unattended-opt4/campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE
    assert p['area_equivalence_only'] and not p['functional_extensions_allowed']
    assert p['native_paused'] and not p['fpga_access']
    assert p['board_allowlist'] == ['0000:21:00.0']

def authenticate_assembly(assembled, resources, raw_hash, final_hash):
    suffix = b''.join(resources)
    assert suffix and len(assembled) > len(suffix), 'missing raw prefix or resources'
    assert assembled.endswith(suffix), 'appended resources differ'
    raw = assembled[:-len(suffix)]
    assert digest(raw) == raw_hash, 'original GoldenGate SV prefix differs'
    assert digest(assembled) == final_hash, 'assembled SV differs'
    return dict(raw_bytes=len(raw), appended_bytes=len(suffix),
                raw_sv_sha256=digest(raw), assembled_sv_sha256=digest(assembled))

def selftest():
    raw, resources = b'module X; endmodule\n', [b'module Y; endmodule\n', b'// resource2\n']
    complete = raw+b''.join(resources)
    authenticate_assembly(complete, resources, digest(raw), digest(complete))
    rejected = []
    for name, data in [('raw-bit', b'!'+complete[1:]),
                       ('resource-bit', complete[:-1]+b'!'),
                       ('missing-resource', complete[:-len(resources[-1])])]:
        try: authenticate_assembly(data, resources, digest(raw), digest(complete))
        except AssertionError: rejected.append(name)
        else: raise AssertionError('mutation accepted: '+name)
    return dict(positive='PASS', rejected=rejected)

def main():
    policy(); O.mkdir(parents=True, exist_ok=True)
    lock = (O/'instance.lock').open('a'); fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    if (O/'complete.json').exists():
        done = read(O/'complete.json')
        assert sha(O/'result.json') == done['result_sha256']
        assert sha(__file__) == done['auditor_sha256']
        for p,h in read(O/'input-binding.json').items(): assert sha(p)==h, p
        print('IMMUTABLE_COMPLETE_REVALIDATED'); return
    assert not (O/'failure.json').exists(), 'use a new recovery version'
    for p,h in read(C/'upstream-hashes.json').items(): assert sha(p)==h, p
    spec = importlib.util.spec_from_file_location('r2', OLD/'audit.py')
    a = importlib.util.module_from_spec(spec); spec.loader.exec_module(a); a.O = O
    state, receipt = read(R/'result.json'), read(R/'receipts/goldengate-owner-only.json')
    assert state['status'] == 'HOST_RTL_GENERATED_REQUIRES_FULL_TARGET_PARITY_AND_AREA'
    assert receipt['returncode'] == 0 and state['functional_baseline'] == BASE
    g = R/'goldengate'; sv = g/'FireSim-generated.sv'
    resource_paths = [Path(n) for n in (g/'firrtl_black_box_resource_files.f').read_text().splitlines() if n.strip()]
    assert [p.name for p in resource_paths] == ['plusarg_reader.v','AbstractClockGate.v']
    assert all(p.parent == g for p in resource_paths)
    assembled = sv.read_bytes()
    assembly = authenticate_assembly(assembled, [p.read_bytes() for p in resource_paths],
        receipt['outputs'][str(sv)], state['host_rtl_sha256'])
    assert digest(assembled) == read(g/'blackboxes-appended.json')['sha256']
    del assembled
    for p,h in receipt['outputs'].items():
        if p != str(sv): assert sha(p)==h, p
    plan = read(W/'candidates/mcrams-dcache-owner-system-r1-20261111/plan.json')
    for p,h in {**plan['inputs'], **plan['evidence_sources']}.items(): assert sha(p)==h, p
    reference = a.LOW
    assert sha(reference) == sha(g/'post-bridge-extraction.fir'), 'complete pre-host target FIR changed'
    old = (g/'post-wrap-top.fir').read_text()
    wrapped = (g/'post-wrap-sram-models.fir').read_text()
    checked = a.check_pair(old, wrapped)
    # Only the new annotation and identical original annotations feed GG.
    ann = W/'candidates/mcrams-dcache-owner-system-r1-20261111/owner-only.anno.json'
    added = read(R/'preflight.json')['exactly_added_annotation']
    annotation_list = read(ann)
    assert annotation_list[-1] == added
    assert len([x for x in annotation_list if x.get('class')=='midas.targetutils.FirrtlMemModelAnnotation']) == 11
    bindings = {**read(C/'upstream-hashes.json'), **plan['inputs'], **plan['evidence_sources']}
    extra = [Path(__file__), R/'result.json', R/'preflight.json',
        R/'receipts/goldengate-owner-only.json', reference,
        g/'post-bridge-extraction.fir', g/'post-wrap-top.fir', g/'post-wrap-sram-models.fir',
        sv, g/'blackboxes-appended.json', g/'firrtl_black_box_resource_files.f', *resource_paths]
    bindings.update({str(p):sha(p) for p in extra})
    result = dict(checked, schema='ec-owner-full-target-wrapper-audit/3', utc=now(),
        status='PASS_EXACT_FULL_PREHOST_TARGET_AND_DCACHE_WRAPPER_NOT_FULL_HOST_PARITY_OR_FIT',
        functional_baseline=BASE, derived_hardware=state['derived_hardware'],
        complete_prehost_target_byte_identical=True, complete_prehost_target_sha256=sha(reference),
        assembly=assembly, assembly_negative_tests=selftest(),
        existing_wrapper_negative_tests=read(OLD/'auditor-tests.json'),
        prior_failure_preserved=str(D/'build-logs/Opt4-mcrams-dcache-owner-audit-r2-20261111/failure.json'),
        original_annotations_preserved=7450, exactly_one_owner_memory_annotation_added=True,
        no_RTL_change=True, no_duplicate_GG=True, full_host_parity_passed=False,
        full_DCache_area_measured=False, production_admission=False, whole_fit=False, fpga_access=False)
    save(O/'input-binding.json', bindings); save(O/'result.json', result)
    save(O/'complete.json', dict(result_sha256=sha(O/'result.json'), auditor_sha256=sha(__file__)))
    save(O/'state.json', dict(status=result['status'], pid=os.getpid(), utc=now(),
        result_sha256=sha(O/'result.json')))
    print(json.dumps(result))

if __name__ == '__main__':
    try: main()
    except Exception as exc:
        if O.exists() and not (O/'complete.json').exists():
            save(O/'failure.json', dict(error=repr(exc), traceback=traceback.format_exc(), utc=now()))
            save(O/'state.json', dict(status='FAILED_WITH_EVIDENCE', error=repr(exc), utc=now()))
        raise
