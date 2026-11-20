#!/usr/bin/python3
"""Authenticate and compare the complete field-reader-only generated DCache.

An identity mismatch is inconclusive and never permits production admission.
No RTL, existing job, FPGA or reference synthesis is changed by this check.
"""
from pathlib import Path
import datetime
import fcntl
import hashlib
import json
import os
import re
import time

from canonical import Cone, TOKEN, compare, modules
from diagnostic_metadata import source_locations
from selfcheck import run as selfcheck

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
L = D / 'build-logs/Opt4-fit-dcache-field-read-exact-identity-round31-v2-20261111'
S = D / 'Opt4-fit-dcache-field-read-exact-identity-round31-v2-state.json'
COMMIT = '3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
SID = '79aedd9ada6137e018d7f9c9c175fd4a06f53820d235ddcbe4b4a185e75fd68d'
PARENT = 'd9d732622601ed792a2647546006b5aae986ab8e'
TOP = 'BoomNonBlockingDCache'
PASS = 'PASS_COMPLETE_GENERATED_DCACHE_RESTRICTED_PREDICATE_IDENTITY_ALL_STATE_OUTPUTS_OBSERVATIONS_AND_STATEMENTS_NOT_WHOLE_DUT'


def read(p):
    return json.loads(Path(p).read_text()) if Path(p).is_file() else {}


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for chunk in iter(lambda: f.read(2**20), b''):
            h.update(chunk)
    return h.hexdigest()


def now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()


def save(p, x):
    q = p.with_name(p.name + '.tmp-' + str(os.getpid()))
    with q.open('w') as f:
        json.dump(x, f, indent=2, sort_keys=True)
        f.write('\n'); f.flush(); os.fsync(f.fileno())
    os.replace(q, p)


def main():
    L.mkdir(exist_ok=True)
    lock = (L / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not S.exists(), 'preserve previous evidence; version recovery'
    fields = Path('/proc/self/stat').read_text().rsplit(')', 1)[1].split()
    st = dict(schema='ec-opt4-field-read-generated-identity/1', pid=os.getpid(),
              start_ticks=fields[19], host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
              hardware_commit=COMMIT, source_id=SID, parent_commit=PARENT,
              functional_baseline_commit='8491167d84b6d9521b151a743673c1516926a1f8',
              status='WAITING_AUTHENTICATED_CANDIDATE_GOLDENGATE', started_utc=now(),
              fpga_access=False, production_admission=False, whole_dut_formal=False)

    def update(**kw):
        st.update(kw); st['updated_utc'] = now(); save(S, st)

    update()
    manifest = read(C / 'input-hashes.json')
    assert manifest and all(sha(p) == h for p, h in manifest.items())
    while True:
        policy = read(D / 'unattended-opt4/campaign-policy.json')
        assert policy['functional_baseline_commit'] == st['functional_baseline_commit']
        assert policy['area_equivalence_only'] and not policy['functional_extensions_allowed']
        assert policy['native_paused'] and not policy['fpga_access']
        producer = read(D / 'Opt4-fit-dcache-field-read-system-r1-state.json')
        rtl = read(D / 'Opt4-fit-dcache-field-read-rtl-state.json')
        job = read(D / 'unattended-opt4/jobs/dcache-field-read-system-r1-3656aec4/state.json')
        if producer.get('status') in ['FAILED_WITH_EVIDENCE', 'DEPENDENCY_FAILED_WITH_EVIDENCE']:
            update(status='DEPENDENCY_FAILED_WITH_EVIDENCE', dependency_status=producer['status'])
            save(L / 'result.json', st); return
        if producer.get('status') == 'RTL_READY_REAL_ABI_CHECKED' and job.get('status') == 'COMPLETE':
            result = D / 'build-logs/Opt4-fit-dcache-field-read-system-r1-20261111/result.json'
            assert job['returncode'] == 0 and job['outputs'][str(result)] == sha(result)
            assert read(result) == producer
            break
        update(dependency_status=producer.get('status')); time.sleep(60)
    update(status='CHECKING_COMPLETE_GENERATED_DCACHE_EXACT_PREDICATE_IDENTITY')
    audit = read(C / 'evidence/checker-audit.json')
    assert audit['status'] == 'PASS_CHECKER_REVIEW_WITH_SAT_WIDTH_COUNTEREXAMPLE_AND_RESTRICTED_PREDICATE_VALIDATION_NOT_CANDIDATE_ADMISSION'
    assert audit['restricted_checker_validation']['status'] == 'PASS_EXACT_PREDICATE_FACTORING_SAT_AND_FIVE_SEMANTIC_MUTATIONS_REJECTED'
    audit_result = D / 'build-logs/Opt4-fit-field-read-checker-audit-round30-v1-20261111/result.json'
    audit_job = read(D / 'unattended-opt4/jobs/field-read-checker-audit-r30-v1-3656aec4/state.json')
    assert audit_job == read(C / 'evidence/checker-audit-job.json')
    assert audit_job['status'] == 'COMPLETE' and audit_job['returncode'] == 0
    assert audit_job['outputs'][str(audit_result)] == sha(audit_result)
    assert audit == read(audit_result)
    selfcheck(L)

    assert rtl['hardware_commit'] == COMMIT and rtl['source_id'] == SID
    assert rtl['configuration_matches_frozen_parameters'] and rtl['modified_class_origins_verified']
    source = read(D / 'Opt4-fit-dcache-field-read-prune-r1-state.json')
    assert source['hardware_commit'] == COMMIT and source['source_id'] == SID
    assert source['exact_parent_reversal'] and source['frozen_parameters_match']
    cycle = read(D / 'Opt4-fit-dcache-frozen-cycle-r5-state.json')
    assert cycle['hardware_commit'] == PARENT and cycle['complete_dcache_cycles_verified']
    cycle_result = D / 'build-logs/Opt4-fit-dcache-frozen-cycle-r5-20261111/result.json'
    cycle_job = read(D / 'unattended-opt4/jobs/dcache-frozen-cycle-r5-d9d73262/state.json')
    assert read(cycle_result) == cycle and cycle_job['status'] == 'COMPLETE'
    assert cycle_job['returncode'] == 0 and cycle_job['outputs'][str(cycle_result)] == sha(cycle_result)
    parent = read(D / 'Opt4-fit-dcache-fieldbank-rtl-state.json')
    assert parent['hardware_commit'] == PARENT
    refs = {}
    graphs = {}
    annotations = {}
    for label, receipt in [('parent', parent), ('candidate', rtl)]:
        path = Path(receipt['goldengate_dir']) / 'FireSim-generated.sv'
        assert sha(path) == receipt['outputs'][str(path)]
        refs[label] = dict(path=str(path), sha256=sha(path))
        graphs[label] = modules(path.read_text())
        annotation = Path(receipt['elaboration_dir']) / 'firesim.firesim.FireSim.anno.json'
        if label == 'candidate':
            expected = producer['stages']['elaborate']['outputs'][str(annotation)]
        else:
            snapshot = W / 'candidates/dcache-frozen-cycle-r3-20261111/evidence/candidate-annotations.json'
            expected = cycle['preparation']['inputs'][str(snapshot)]
            assert sha(snapshot) == expected
        assert sha(annotation) == expected
        annotations[label] = [r['target'] for r in read(annotation)
                              if r.get('class') == 'firrtl.transforms.DontTouchAnnotation'
                              and r.get('target', '').startswith('~FireSim|' + TOP + '>')]
        refs[label].update(annotation=str(annotation), annotation_sha256=sha(annotation))
    assert annotations['parent'] == annotations['candidate'], 'original DontTouch annotations changed'
    assert set(graphs['parent']) == set(graphs['candidate']), 'generated module inventory changed'
    changed_others = [n for n in graphs['parent'] if n != TOP
                      and TOKEN.findall(graphs['parent'][n]) != TOKEN.findall(graphs['candidate'][n])]
    assert not changed_others, ('unproven changes outside DCache', changed_others)
    declarations = Cone(graphs['parent'][TOP]).types
    prefix_index = {}
    for name in declarations:
        stem = name
        while True:
            prefix_index.setdefault(stem, set()).add(name)
            shortened = re.sub(r'_\d+$', '', stem)
            if shortened == stem: break
            stem = shortened
    observed = set()
    for raw in annotations['parent']:
        raw = raw.split('>', 1)[1]
        stem = re.sub(r'[^A-Za-z0-9_$]', '_', raw).rstrip('_')
        alternatives = {stem}
        if raw.startswith('io.'):
            alternatives.add('io__' + raw[3:].replace('.', '_'))
        hits = sorted(set().union(*(prefix_index.get(a, set()) for a in alternatives)))
        if raw == 'slowdown_opt1_pending_live_key':
            hits += [stem + '_' + f for f in ['valid', 'writer', 'generation', 'contentSeq']
                     if stem + '_' + f in declarations]
        assert hits, ('unmatched original observation', raw)
        observed.update(hits)
    assert all('debug_line_generation_' + str(i) in observed for i in range(512))
    normalized, diagnostic = source_locations(graphs['candidate'][TOP])
    save(L / 'assertion-source-location-metadata.json', diagnostic)
    comparison = compare(graphs['parent'][TOP], normalized, observed)
    save(L / 'symbolic-comparison.json', comparison)
    if not comparison['identical']:
        update(status='UNPROVEN_GENERATED_IDENTITY_MISMATCH_REQUIRES_REVIEW_NO_ADMISSION',
               comparison=comparison, inputs=refs, ended_utc=now())
        save(L / 'result.json', st); return
    match = re.search(r'(ownerGenerationMemory\[[^\]\n]+\] <= )([A-Za-z_][\w$]*)(;)', normalized)
    assert match, 'actual generated writer required'
    replacement = match[1] + "(32'h1 ^ " + match[2] + ')' + match[3]
    mutated = normalized[:match.start()] + replacement + normalized[match.end():]
    negative = compare(normalized, mutated, observed)
    assert not negative['identical']
    save(L / 'actual-write-mutation-negative.json', dict(original_statement=match[0],
        mutated_statement=replacement, actual_next_state_write_bitflip_rejected=True, comparison=negative))
    assert all(sha(p) == h for p, h in manifest.items())
    update(status=PASS, comparison=comparison, inputs=refs, checker_audit_receipt_sha256=sha(audit_result),
           independent_verification_reason='Prototype r2 has a SAT-confirmed width-context false positive. This version adds only leading ternary selection by unsigned one-bit AND to the restricted equality checker, validated by SAT and semantic mutations. Every state update, observation and functional statement is retained.', actual_memory_write_mutation_rejected=True, diagnostic_metadata_sha256=sha(L / 'assertion-source-location-metadata.json'), parent_frozen_cycle_result_sha256=sha(cycle_result),
           all_other_generated_modules_identical=True, original_observations_preserved=True,
           cycle_semantics='Identical complete generated register/memory updates, combinational cones, assertions and submodule connections relative to parent; parent originalfrozen8192cycle receipt preserved.',
           resources=None, whole_fit_not_inferred=True, ended_utc=now())
    save(L / 'result.json', st)


if __name__ == '__main__':
    try:
        main()
    except Exception as error:
        if S.exists():
            st = read(S)
            if st.get('pid') == os.getpid():
                st.update(status='FAILED_WITH_EVIDENCE', error=repr(error), ended_utc=now())
                save(S, st)
        raise
