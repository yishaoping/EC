#!/usr/bin/python3
"""Explain failed generated identity without modifying RTL or admission receipts."""
from pathlib import Path
import datetime
import difflib
import fcntl
import hashlib
import importlib.util
import json
import os
import re

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
L = D / 'build-logs/Opt4-fit-dcache-field-read-cone-audit-r2-20261111'
S = D / 'Opt4-fit-dcache-field-read-cone-audit-r2-state.json'
TOP = 'BoomNonBlockingDCache'


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
    assert p['functional_baseline_commit'] == '8491167d84b6d9521b151a743673c1516926a1f8'
    assert p['area_equivalence_only'] and not p['functional_extensions_allowed']
    assert p['native_paused'] and not p['fpga_access']


def save(p, j):
    q = p.with_name(p.name + '.tmp-' + str(os.getpid()))
    with q.open('w') as f:
        json.dump(j, f, indent=2, sort_keys=True)
        f.write('\n'); f.flush(); os.fsync(f.fileno())
    os.replace(q, p)


def now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()


def main():
    policy()
    L.mkdir(exist_ok=True)
    lock = (L / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not S.exists(), 'use versioned recovery'
    manifest = read(C / 'input-hashes.json')
    assert all(sha(p) == h for p, h in manifest.items())
    prior = read(D / 'Opt4-fit-dcache-field-read-generated-r1-state.json')
    assert prior['status'] == 'UNPROVEN_GENERATED_IDENTITY_MISMATCH_REQUIRES_REVIEW_NO_ADMISSION'
    st = dict(schema='ec-opt4-field-read-cone-audit/1', pid=os.getpid(),
              start_ticks=Path('/proc/self/stat').read_text().rsplit(')', 1)[1].split()[19],
              host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
              hardware_commit=prior['hardware_commit'], source_id=prior['source_id'],
              functional_baseline_commit=prior['functional_baseline_commit'],
              status='ANALYZING_FAILED_SYMBOLIC_CONES', started_utc=now(),
              fpga_access=False, production_admission=False, resources=None)
    save(S, st)
    spec = importlib.util.spec_from_file_location('canonical_r1', W / 'candidates/dcache-field-read-generated-r1-20261111/canonical.py')
    canon = importlib.util.module_from_spec(spec); spec.loader.exec_module(canon)
    cones = {}
    for label, row in prior['inputs'].items():
        policy()
        assert sha(row['path']) == row['sha256']
        text = Path(row['path']).read_text()
        start = text.index('\nmodule ' + TOP + '(') + 1
        end = text.index('\nendmodule', start) + len('\nendmodule')
        cones[label] = canon.Cone(canon.strip_comments(text[start:end]))
    left, right = cones['parent'], cones['candidate']

    def unalias(cone, name):
        seen = set()
        while name in cone.defs:
            expr = cone.defs[name]
            if not canon.IDENT.fullmatch(expr) or cone.types.get(expr) != cone.types[name]:
                break
            assert name not in seen; seen.add(name); name = expr
        return name

    visited = set()
    divergent = []

    def trace(a, b, path, depth=0):
        a, b = unalias(left, a), unalias(right, b)
        if left.symbol(a) == right.symbol(b) or (a, b) in visited:
            return
        visited.add((a, b))
        ea, eb = left.defs.get(a, a), right.defs.get(b, b)
        ta, tb = canon.TOKEN.findall(ea), canon.TOKEN.findall(eb)
        sa = ['WIRE' if t in left.types else t for t in ta]
        sb = ['WIRE' if t in right.types else t for t in tb]
        if depth < 100 and sa == sb and left.types.get(a) == right.types.get(b):
            children = [(x, y) for x, y in zip(ta, tb) if x in left.types and y in right.types
                        and left.symbol(x) != right.symbol(y)]
            if children:
                for x, y in children: trace(x, y, path + [a + ' / ' + b], depth + 1)
                return
        divergent.append(dict(parent_name=a, candidate_name=b, parent_type=left.types.get(a),
                              candidate_type=right.types.get(b), parent_expression=ea,
                              candidate_expression=eb, path=path))

    for root in prior['comparison']['mismatched_observations']:
        trace(root, root, [root])
    save(L / 'divergent-cones.json', divergent)
    policy()
    # Hash-expanded lines identify the first changed state/assert/instance text.
    def residual_lines(cone):
        text = canon.ASSIGN.sub('', canon.WIRE.sub('', cone.body))
        text = canon.BARE.sub('', text)
        return [cone.expression(line.strip()) for line in text.splitlines() if line.strip()]
    a, b = residual_lines(left), residual_lines(right)
    differences = []
    for tag, i, j, k, m in difflib.SequenceMatcher(a=a, b=b, autojunk=False).get_opcodes():
        if tag != 'equal':
            differences.append(dict(kind=tag, parent_lines=[i,j], candidate_lines=[k,m],
                                    parent=a[i:j][:12], candidate=b[k:m][:12]))
    save(L / 'residual-differences.json', differences)
    st.update(status='COMPLETE_CONSERVATIVE_MISMATCH_DIAGNOSIS_NO_ADMISSION',
              original_receipt_sha256=sha(D / 'Opt4-fit-dcache-field-read-generated-r1-state.json'),
              divergent_cones=divergent, residual_difference_groups=len(differences),
              inputs=prior['inputs'], ended_utc=now())
    save(S, st); save(L / 'result.json', st)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if S.exists():
            j = read(S)
            if j.get('pid') == os.getpid():
                j.update(status='FAILED_WITH_EVIDENCE', error=repr(exc), ended_utc=now())
                save(S, j)
        raise
